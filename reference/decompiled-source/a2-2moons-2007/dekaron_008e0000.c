// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x8e0000-0x8effff

// ==== FUN_008e0403 @ 0x008e0403 ====

int FUN_008e0403(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  uint *puVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  bool bVar8;
  
  if (param_3 != (undefined4 *)0x0) {
    iVar4 = FUN_008d6973(param_2,0);
    if (iVar4 != 0) {
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      piVar5 = (int *)(*(int *)(iVar4 + 0x28) + *(int *)(param_1 + 0x20));
      if (*piVar5 == 0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = piVar5 + 1;
      }
      *param_3 = piVar5;
      param_3[1] = *(undefined4 *)(iVar4 + 0x2c);
      puVar1 = param_3 + 2;
      puVar6 = param_3 + 3;
      *puVar1 = 0;
      *puVar6 = 0;
      sVar3 = *(short *)(iVar4 + 0x14);
      if ((sVar3 == *(short *)(param_1 + 0x42)) &&
         (*(short *)(iVar4 + 0x18) == *(short *)(param_1 + 0x44))) {
        param_3 = (undefined4 *)0x1;
      }
      else {
        param_3 = (undefined4 *)0x0;
      }
      bVar8 = sVar3 == *(short *)(param_1 + 0x40);
      iVar7 = FUN_008de725(*(undefined2 *)(iVar4 + 0x34),param_3,bVar8,puVar1);
      if (-1 < iVar7) {
        iVar7 = FUN_008de96d(*(undefined2 *)(iVar4 + 0x34),param_3,bVar8,puVar6);
      }
      goto LAB_008e04b9;
    }
  }
  iVar7 = -0x7789f794;
LAB_008e04b9:
  puVar2 = (uint *)(param_1 + 0x118);
  if ((*(byte *)puVar2 & 1) != 0) {
    __controlfp(*(uint *)(param_1 + 0x114),0x30000);
    *puVar2 = *puVar2 & 0xfffffffe;
  }
  return iVar7;
}


// ==== FUN_008e04e5 @ 0x008e04e5 ====

undefined4 FUN_008e04e5(int param_1)

{
  if ((*(int *)(param_1 + 0x3c) == 4) || (*(int *)(param_1 + 0x3c) == 3)) {
    return 0x8876086c;
  }
  *(undefined4 *)(param_1 + 0x3c) = 3;
  if (*(int *)(param_1 + 0xf8) != 0) {
    FUN_008df5d1(1);
    *(int *)(param_1 + 0xf8) = 0;
  }
  *(int *)(param_1 + 0xfc) = param_1 + 0xe0;
  return 0;
}


// ==== FUN_008e0536 @ 0x008e0536 ====

undefined4 FUN_008e0536(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  
  uVar3 = 0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0x8007000e;
  }
  else {
    puVar2[1] = param_1;
    puVar2[3] = param_2;
    *puVar2 = 1;
    *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
    *(int *)(in_ECX + 0xfc) = (int)puVar2;
  }
  return uVar3;
}


// ==== FUN_008e058a @ 0x008e058a ====

undefined4 FUN_008e058a(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  
  uVar3 = 0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0x8007000e;
  }
  else {
    puVar2[1] = param_1;
    puVar2[3] = param_2;
    *puVar2 = 5;
    *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
    *(int *)(in_ECX + 0xfc) = (int)puVar2;
  }
  return uVar3;
}


// ==== FUN_008e05de @ 0x008e05de ====

undefined4 FUN_008e05de(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  
  uVar3 = 0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0x8007000e;
  }
  else {
    puVar2[1] = param_1;
    puVar2[3] = param_2;
    *puVar2 = 3;
    *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
    *(int *)(in_ECX + 0xfc) = (int)puVar2;
  }
  return uVar3;
}


// ==== FUN_008e0632 @ 0x008e0632 ====

undefined4 FUN_008e0632(undefined4 param_1,undefined4 *param_2,int param_3)

{
  void *pvVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_c;
  undefined4 *local_8;
  
  local_c = 0;
  local_8 = (undefined4 *)0x0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  if ((param_3 == 0) || (local_8 = operator_new(param_3 << 2), local_8 != (undefined4 *)0x0)) {
    puVar4 = local_8;
    for (iVar3 = param_3; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar2[1] = param_1;
    puVar2[2] = param_3;
    puVar2[3] = local_8;
    *puVar2 = 2;
    *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
    *(int *)(in_ECX + 0xfc) = (int)puVar2;
    puVar2 = (undefined4 *)0x0;
  }
  else {
    local_c = 0x8007000e;
  }
  if (puVar2 != (undefined4 *)0x0) {
    FUN_008df5d1(1);
  }
  return local_c;
}


// ==== FUN_008e06db @ 0x008e06db ====

undefined4 FUN_008e06db(undefined4 param_1,undefined4 *param_2,int param_3)

{
  void *pvVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_c;
  undefined4 *local_8;
  
  local_c = 0;
  local_8 = (undefined4 *)0x0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  if ((param_3 == 0) || (local_8 = operator_new(param_3 << 2), local_8 != (undefined4 *)0x0)) {
    puVar4 = local_8;
    for (iVar3 = param_3; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar2[1] = param_1;
    puVar2[2] = param_3;
    puVar2[3] = local_8;
    *puVar2 = 4;
    *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
    *(int *)(in_ECX + 0xfc) = (int)puVar2;
    puVar2 = (undefined4 *)0x0;
  }
  else {
    local_c = 0x8007000e;
  }
  if (puVar2 != (undefined4 *)0x0) {
    FUN_008df5d1(1);
  }
  return local_c;
}


// ==== FUN_008e0784 @ 0x008e0784 ====

undefined4 FUN_008e0784(undefined4 param_1,undefined4 *param_2,int param_3)

{
  void *pvVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_c;
  undefined4 *local_8;
  
  local_c = 0;
  local_8 = (undefined4 *)0x0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  if ((param_3 == 0) || (local_8 = operator_new(param_3 << 2), local_8 != (undefined4 *)0x0)) {
    puVar4 = local_8;
    for (iVar3 = param_3; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar2[1] = param_1;
    puVar2[2] = param_3;
    puVar2[3] = local_8;
    *puVar2 = 6;
    *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
    *(int *)(in_ECX + 0xfc) = (int)puVar2;
    puVar2 = (undefined4 *)0x0;
  }
  else {
    local_c = 0x8007000e;
  }
  if (puVar2 != (undefined4 *)0x0) {
    FUN_008df5d1(1);
  }
  return local_c;
}


// ==== FUN_008e082d @ 0x008e082d ====

undefined4 FUN_008e082d(undefined4 param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    puVar3 = operator_new(0x10);
    if (puVar3 == (undefined4 *)0x0) {
      local_8 = 0x8007000e;
    }
    else {
      *puVar3 = *param_2;
      puVar3[1] = param_2[1];
      puVar3[2] = param_2[2];
      puVar3[3] = param_2[3];
      puVar2[3] = puVar3;
      *puVar2 = 7;
      puVar2[1] = param_1;
      *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
      *(int *)(in_ECX + 0xfc) = (int)puVar2;
      puVar2 = (undefined4 *)0x0;
    }
    if (puVar2 != (undefined4 *)0x0) {
      FUN_008df5d1(1);
    }
  }
  return local_8;
}


// ==== FUN_008e08b9 @ 0x008e08b9 ====

undefined4 FUN_008e08b9(undefined4 param_1,undefined4 *param_2,uint param_3)

{
  void *pvVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_c;
  undefined4 *local_8;
  
  local_c = 0;
  local_8 = (undefined4 *)0x0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  if ((param_3 == 0) || (local_8 = operator_new(param_3 << 4), local_8 != (undefined4 *)0x0)) {
    puVar4 = local_8;
    for (iVar3 = (param_3 & 0xfffffff) << 2; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    puVar2[1] = param_1;
    puVar2[2] = param_3;
    puVar2[3] = local_8;
    *puVar2 = 8;
    *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
    *(int *)(in_ECX + 0xfc) = (int)puVar2;
    puVar2 = (undefined4 *)0x0;
  }
  else {
    local_c = 0x8007000e;
  }
  if (puVar2 != (undefined4 *)0x0) {
    FUN_008df5d1(1);
  }
  return local_c;
}


// ==== FUN_008e0971 @ 0x008e0971 ====

undefined4 FUN_008e0971(undefined4 param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  local_8 = 0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    puVar3 = operator_new(0x40);
    if (puVar3 == (undefined4 *)0x0) {
      local_8 = 0x8007000e;
    }
    else {
      puVar5 = puVar3;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = *param_2;
        param_2 = param_2 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar2[3] = puVar3;
      *puVar2 = 9;
      puVar2[1] = param_1;
      *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
      *(int *)(in_ECX + 0xfc) = (int)puVar2;
      puVar2 = (undefined4 *)0x0;
    }
    if (puVar2 != (undefined4 *)0x0) {
      FUN_008df5d1(1);
    }
  }
  return local_8;
}


// ==== FUN_008e09fe @ 0x008e09fe ====

undefined4 FUN_008e09fe(undefined4 param_1,undefined4 *param_2,uint param_3)

{
  void *pvVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_c;
  undefined4 *local_8;
  
  local_c = 0;
  local_8 = (undefined4 *)0x0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  if ((param_3 == 0) || (local_8 = operator_new(param_3 << 6), local_8 != (undefined4 *)0x0)) {
    puVar4 = local_8;
    for (iVar3 = (param_3 & 0x3ffffff) << 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    puVar2[1] = param_1;
    puVar2[2] = param_3;
    puVar2[3] = local_8;
    *puVar2 = 10;
    *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
    *(int *)(in_ECX + 0xfc) = (int)puVar2;
    puVar2 = (undefined4 *)0x0;
  }
  else {
    local_c = 0x8007000e;
  }
  if (puVar2 != (undefined4 *)0x0) {
    FUN_008df5d1(1);
  }
  return local_c;
}


// ==== FUN_008e0ab6 @ 0x008e0ab6 ====

undefined4 FUN_008e0ab6(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 local_c;
  undefined4 *local_8;
  
  local_c = 0;
  local_8 = (undefined4 *)0x0;
  pvVar2 = operator_new(0x1c);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar3 == (undefined4 *)0x0) {
    local_c = 0x8007000e;
  }
  else {
    if ((param_3 == 0) || (local_8 = operator_new(param_3 << 6), local_8 != (undefined4 *)0x0)) {
      uVar4 = 0;
      if (param_3 != 0) {
        puVar6 = local_8;
        do {
          iVar1 = uVar4 * 4;
          uVar4 = uVar4 + 1;
          puVar7 = *(undefined4 **)(param_2 + iVar1);
          puVar8 = puVar6;
          for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          puVar6 = puVar6 + 0x10;
        } while (uVar4 < param_3);
      }
      puVar3[1] = param_1;
      puVar3[2] = param_3;
      puVar3[3] = local_8;
      *puVar3 = 10;
      *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar3;
      *(int *)(in_ECX + 0xfc) = (int)puVar3;
      puVar3 = (undefined4 *)0x0;
    }
    else {
      local_c = 0x8007000e;
    }
    if (puVar3 != (undefined4 *)0x0) {
      FUN_008df5d1(1);
    }
  }
  return local_c;
}


// ==== FUN_008e0b75 @ 0x008e0b75 ====

undefined4 FUN_008e0b75(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    pvVar1 = operator_new(0x40);
    if (pvVar1 == (void *)0x0) {
      local_8 = 0x8007000e;
    }
    else {
      thunk_FUN_0079f0cc(pvVar1,param_2);
      puVar2[1] = param_1;
      *puVar2 = 9;
      puVar2[3] = pvVar1;
      *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
      *(int *)(in_ECX + 0xfc) = (int)puVar2;
      puVar2 = (undefined4 *)0x0;
    }
    if (puVar2 != (undefined4 *)0x0) {
      FUN_008df5d1(1);
    }
  }
  return local_8;
}


// ==== FUN_008e0bff @ 0x008e0bff ====

undefined4 FUN_008e0bff(undefined4 param_1,int param_2,void *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 local_c;
  void *local_8;
  
  iVar1 = (int)param_3;
  local_c = 0;
  local_8 = (void *)0x0;
  pvVar2 = operator_new(0x1c);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar3 == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  if (param_3 != (void *)0x0) {
    local_8 = operator_new((int)param_3 << 6);
    if (local_8 == (void *)0x0) {
      local_c = 0x8007000e;
      goto LAB_008e0cb0;
    }
    if (param_3 != (void *)0x0) {
      iVar4 = param_2 - (int)local_8;
      param_2 = (int)param_3;
      param_3 = local_8;
      do {
        thunk_FUN_0079f0cc(param_3,iVar4 + (int)param_3);
        param_3 = (void *)((int)param_3 + 0x40);
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  puVar3[1] = param_1;
  puVar3[3] = local_8;
  *puVar3 = 10;
  puVar3[2] = iVar1;
  *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar3;
  *(int *)(in_ECX + 0xfc) = (int)puVar3;
  puVar3 = (undefined4 *)0x0;
LAB_008e0cb0:
  if (puVar3 != (undefined4 *)0x0) {
    FUN_008df5d1(1);
  }
  return local_c;
}


// ==== FUN_008e0cc6 @ 0x008e0cc6 ====

undefined4 FUN_008e0cc6(undefined4 param_1,int param_2,void *param_3)

{
  uint uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int in_ECX;
  uint uVar4;
  undefined4 local_c;
  void *local_8;
  
  uVar1 = (uint)param_3;
  uVar4 = 0;
  local_c = 0;
  local_8 = (void *)0x0;
  pvVar2 = operator_new(0x1c);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar3 == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  if ((param_3 == (void *)0x0) ||
     (local_8 = operator_new((int)param_3 << 6), local_8 != (void *)0x0)) {
    if (param_3 != (void *)0x0) {
      param_3 = local_8;
      do {
        thunk_FUN_0079f0cc(param_3,*(undefined4 *)(param_2 + uVar4 * 4));
        param_3 = (void *)((int)param_3 + 0x40);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
    puVar3[1] = param_1;
    puVar3[3] = local_8;
    *puVar3 = 10;
    puVar3[2] = uVar1;
    *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar3;
    *(int *)(in_ECX + 0xfc) = (int)puVar3;
    puVar3 = (undefined4 *)0x0;
  }
  else {
    local_c = 0x8007000e;
  }
  if (puVar3 != (undefined4 *)0x0) {
    FUN_008df5d1(1);
  }
  return local_c;
}


// ==== FUN_008e0d83 @ 0x008e0d83 ====

int FUN_008e0d83(undefined4 param_1,char *param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int in_ECX;
  uint uVar8;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = (int *)0x0;
  pvVar2 = operator_new(0x1c);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar3 == (undefined4 *)0x0) {
LAB_008e0db6:
    local_c = -0x7ff8fff2;
LAB_008e0e74:
    if (local_8 == (int *)0x0) goto LAB_008e0e84;
    (**(code **)(*local_8 + 8))(local_8);
  }
  else {
    if (param_2 == (char *)0x0) {
LAB_008e0e0e:
      puVar6 = operator_new(0xc);
      if (puVar6 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        puVar7 = puVar6 + 1;
        *puVar6 = 1;
        FUN_0040d030(puVar7,8,1,&LAB_008d91c3);
      }
      if (puVar7 == (undefined4 *)0x0) goto LAB_008e0db6;
      *puVar7 = 4;
      puVar7[1] = local_8;
      local_8 = (int *)0x0;
      puVar3[5] = puVar7;
      *puVar3 = 0xb;
      puVar3[1] = param_1;
      puVar3[4] = 1;
      *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar3;
      *(int *)(in_ECX + 0xfc) = (int)puVar3;
      puVar3 = (undefined4 *)0x0;
      goto LAB_008e0e74;
    }
    pcVar4 = param_2;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = pcVar4 + (1 - (int)(param_2 + 1));
    local_c = FUN_008eb3df(pcVar4,&local_8);
    if (-1 < local_c) {
      pcVar5 = (char *)(**(code **)(*local_8 + 0xc))(local_8);
      for (uVar8 = (uint)pcVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)param_2;
        param_2 = param_2 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar8 = (uint)pcVar4 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar5 = *param_2;
        param_2 = param_2 + 1;
        pcVar5 = pcVar5 + 1;
      }
      goto LAB_008e0e0e;
    }
  }
  local_8 = (int *)0x0;
LAB_008e0e84:
  if (puVar3 != (undefined4 *)0x0) {
    FUN_008df5d1(1);
  }
  return local_c;
}


// ==== FUN_008e0e9b @ 0x008e0e9b ====

undefined4 FUN_008e0e9b(undefined4 param_1,int *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 local_8;
  
  puVar4 = (undefined4 *)0x0;
  local_8 = 0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    puVar3 = operator_new(0xc);
    if (puVar3 != (undefined4 *)0x0) {
      puVar4 = puVar3 + 1;
      *puVar3 = 1;
      FUN_0040d030(puVar4,8,1,&LAB_008d91c3);
    }
    if (puVar4 == (undefined4 *)0x0) {
      local_8 = 0x8007000e;
      FUN_008df5d1(1);
    }
    else {
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 4))(param_2);
      }
      puVar4[1] = param_2;
      *puVar4 = 5;
      puVar2[1] = param_1;
      *puVar2 = 0xc;
      puVar2[4] = 1;
      puVar2[5] = puVar4;
      *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
      *(int *)(in_ECX + 0xfc) = (int)puVar2;
    }
  }
  return local_8;
}


// ==== FUN_008e0f4e @ 0x008e0f4e ====

undefined4 FUN_008e0f4e(undefined4 param_1,int *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 local_8;
  
  puVar4 = (undefined4 *)0x0;
  local_8 = 0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    puVar3 = operator_new(0xc);
    if (puVar3 != (undefined4 *)0x0) {
      puVar4 = puVar3 + 1;
      *puVar3 = 1;
      FUN_0040d030(puVar4,8,1,&LAB_008d91c3);
    }
    if (puVar4 == (undefined4 *)0x0) {
      local_8 = 0x8007000e;
      FUN_008df5d1(1);
    }
    else {
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 4))(param_2);
      }
      puVar4[1] = param_2;
      *puVar4 = 0xf;
      puVar2[1] = param_1;
      *puVar2 = 0xd;
      puVar2[4] = 1;
      puVar2[5] = puVar4;
      *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
      *(int *)(in_ECX + 0xfc) = (int)puVar2;
    }
  }
  return local_8;
}


// ==== FUN_008e1001 @ 0x008e1001 ====

undefined4 FUN_008e1001(undefined4 param_1,int *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 local_8;
  
  puVar4 = (undefined4 *)0x0;
  local_8 = 0;
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar2 == (undefined4 *)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    puVar3 = operator_new(0xc);
    if (puVar3 != (undefined4 *)0x0) {
      puVar4 = puVar3 + 1;
      *puVar3 = 1;
      FUN_0040d030(puVar4,8,1,&LAB_008d91c3);
    }
    if (puVar4 == (undefined4 *)0x0) {
      local_8 = 0x8007000e;
      FUN_008df5d1(1);
    }
    else {
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 4))(param_2);
      }
      puVar4[1] = param_2;
      *puVar4 = 0x10;
      puVar2[1] = param_1;
      *puVar2 = 0xe;
      puVar2[4] = 1;
      puVar2[5] = puVar4;
      *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar2;
      *(int *)(in_ECX + 0xfc) = (int)puVar2;
    }
  }
  return local_8;
}


// ==== FUN_008e10b4 @ 0x008e10b4 ====

int FUN_008e10b4(uint param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int *piVar5;
  int extraout_EAX;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  int local_10;
  undefined4 *local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  local_c = (undefined4 *)0x0;
  pvVar3 = operator_new(0x1c);
  if (pvVar3 == (void *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_008d8f08();
  }
  if (puVar4 == (undefined4 *)0x0) {
    return -0x7ff8fff2;
  }
  if (param_3 == 0) {
LAB_008e112c:
    uVar6 = ~param_1;
    uVar1 = *(undefined4 *)(uVar6 + 4);
    local_10 = 0;
    param_2 = (undefined4 *)FUN_008d91a3(uVar1,local_c,0,&local_10,*(int *)(uVar6 + 8) != -1);
    iVar2 = local_10;
    if ((int)param_2 < 0) goto LAB_008e11f7;
    piVar5 = operator_new(local_10 * 8 + 4);
    if (piVar5 == (int *)0x0) {
      local_8 = (int *)0x0;
    }
    else {
      *piVar5 = iVar2;
      FUN_0040d030(piVar5 + 1,8,iVar2,&LAB_008d91c3);
      local_8 = piVar5 + 1;
    }
    puVar7 = local_c;
    if (local_8 != (int *)0x0) {
      param_2 = (undefined4 *)FUN_008d91a3(uVar1,local_c,local_8,0,*(int *)(uVar6 + 8) != -1);
      if (-1 < (int)param_2) {
        puVar4[1] = param_1;
        puVar4[2] = param_3;
        *puVar4 = 0;
        puVar4[3] = puVar7;
        puVar4[4] = local_10;
        puVar4[5] = local_8;
        *(undefined4 **)(*(int *)(in_ECX + 0xfc) + 0x18) = puVar4;
        *(int *)(in_ECX + 0xfc) = (int)puVar4;
        local_c = (undefined4 *)0x0;
        local_8 = (int *)0x0;
        puVar4 = (undefined4 *)0x0;
      }
      goto LAB_008e11f7;
    }
  }
  else {
    local_c = operator_new(param_3);
    if (local_c != (undefined4 *)0x0) {
      puVar7 = local_c;
      for (uVar6 = param_3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar7 = *param_2;
        param_2 = param_2 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar6 = param_3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      goto LAB_008e112c;
    }
  }
  param_2 = (undefined4 *)0x8007000e;
LAB_008e11f7:
  if (local_c != (undefined4 *)0x0) {
    _free(local_c);
    return extraout_EAX;
  }
  if (local_8 != (int *)0x0) {
    FUN_008dc793(3);
  }
  if (puVar4 != (undefined4 *)0x0) {
    FUN_008df5d1(1);
  }
  return (int)param_2;
}


// ==== FUN_008e122a @ 0x008e122a ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008e122a(uint param_1)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  short *psVar11;
  undefined4 *puVar12;
  char cVar13;
  int in_ECX;
  uint *puVar14;
  uint *puVar15;
  int *piVar16;
  uint uVar17;
  uint uVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  undefined8 uVar21;
  int *piVar22;
  ushort *puVar23;
  undefined4 uVar24;
  uint **ppuVar25;
  undefined1 local_8c [4];
  undefined4 *local_88;
  undefined4 *local_84;
  undefined4 *local_80;
  undefined4 uStack_7c;
  uint local_78 [2];
  void *local_70;
  uint *local_6c;
  int *local_68;
  undefined4 *local_64;
  int *local_60;
  uint *local_5c;
  int *local_58;
  int local_54;
  uint *local_50;
  int local_4c;
  uint *local_48;
  int *local_44;
  int *local_40;
  uint *local_3c;
  ushort local_38 [4];
  short local_30 [2];
  uint *local_2c;
  undefined1 local_28 [4];
  int *local_24;
  int local_20;
  uint *local_1c;
  undefined1 local_18 [4];
  uint *local_14;
  ushort local_10 [4];
  undefined4 local_8;
  
  piVar16 = (int *)(param_1 * 100 + *(int *)(in_ECX + 0x2c));
  iVar7 = piVar16[1];
  local_8 = DAT_00b49670;
  iVar4 = *(int *)(iVar7 + 0x1c) * 4;
  local_4c = 0;
  local_70 = (void *)0x0;
  if (*(int *)(*(int *)(iVar4 + *(int *)(in_ECX + 0xb0)) + 0x40) == 0) {
    iVar5 = *(int *)(in_ECX + 0x20);
  }
  else {
    iVar5 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
  }
  *(int *)(iVar7 + 8) =
       *(int *)(*(int *)(iVar4 + *(int *)(in_ECX + 0xb0)) + 0x30) + *(int *)(iVar7 + 0x24) + iVar5;
  iVar7 = piVar16[1];
  iVar4 = *(int *)(iVar7 + 0x1c) * 4;
  if (*(int *)(*(int *)(iVar4 + *(int *)(in_ECX + 0xb0)) + 0x40) == 0) {
    local_40 = *(int **)(in_ECX + 0x20);
  }
  else {
    local_40 = *(int **)(*(int *)(in_ECX + 0x38) + 0x10);
  }
  *(int *)(iVar7 + 0xc) =
       *(int *)(*(int *)(iVar4 + *(int *)(in_ECX + 0xb0)) + 0x2c) + *(int *)(iVar7 + 0x20) +
       (int)local_40;
  iVar7 = piVar16[1];
  iVar5 = *(int *)(iVar7 + 0x1c) * 4;
  iVar4 = *(int *)(iVar5 + *(int *)(in_ECX + 0xb0));
  if (*(int *)(*(int *)(iVar5 + *(int *)(in_ECX + 0xb0)) + 0x40) == 0) {
    if (*(int *)(iVar4 + 0x40) == 0) {
      iVar5 = *(int *)(in_ECX + 0x20);
    }
    else {
      iVar5 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
    }
    iVar7 = *(int *)(*(int *)(iVar4 + 0x30) + *(int *)(iVar7 + 0x24) + iVar5);
  }
  else {
    if (*(int *)(iVar4 + 0x40) == 0) {
      local_40 = *(int **)(in_ECX + 0x20);
    }
    else {
      local_40 = *(int **)(*(int *)(in_ECX + 0x38) + 0x10);
    }
    iVar4 = *(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(iVar7 + 0x1c) * 4);
    iVar7 = *(int *)(*(int *)(*(int *)(iVar4 + 0x40) + 8) +
                    *(int *)(*(int *)(iVar7 + 0x24) + *(int *)(iVar4 + 0x30) + (int)local_40) * 4);
  }
  iVar7 = *(int *)(in_ECX + 0x18) + iVar7 * 0x18;
  if ((*(uint *)(iVar7 + 0x14) & 1) == 0) {
    if ((((*(byte *)(piVar16 + 2) & 8) != 0) && (*(int *)(in_ECX + 0xb4) != 0)) &&
       ((*(byte *)(in_ECX + 0x119) & 8) == 0)) {
      local_6c = (uint *)(*(int *)(in_ECX + 0xac) * *(int *)(in_ECX + 0xa0));
      local_50 = (uint *)0x0;
      if (local_6c != (uint *)0x0) {
        do {
          puVar15 = *(uint **)((int)local_50 * 4 + *(int *)(in_ECX + 0xc0));
          if (puVar15 != (uint *)0x0) {
            local_1c = *(uint **)((int)local_50 * 4 + *(int *)(in_ECX + 0xb4));
            uVar17 = *puVar15;
            puVar14 = (uint *)0x0;
            local_3c = puVar15;
            if (uVar17 != 0) {
              do {
                if (*(ushort *)(uVar17 + 0x14) == param_1) {
                  if ((puVar14 == (uint *)0x0) && (puVar14 = local_1c, *local_1c != 0)) {
                    do {
                      local_1c = local_1c + 1;
                    } while (*local_1c != 0);
                    puVar14 = local_1c;
                  }
                  *puVar14 = uVar17;
                  puVar14 = puVar14 + 1;
                  *puVar14 = 0;
                }
                local_3c = local_3c + 1;
                uVar17 = *local_3c;
              } while (uVar17 != 0);
            }
          }
          local_50 = (uint *)((int)local_50 + 1);
        } while (local_50 < local_6c);
      }
      piVar16[2] = piVar16[2] & 0xfffffff7;
    }
    local_4c = 0;
    goto LAB_008e2182;
  }
  if (*(int *)(iVar7 + 4) == 0) {
    *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) | 2;
    *(undefined4 *)(iVar7 + 0xc) = 0;
  }
  else {
    local_4c = FUN_008db628(iVar7);
    if (local_4c < 0) goto LAB_008e2182;
  }
  *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) & 0xfffffffe;
  local_44 = (int *)0x1;
  if (1 < *(ushort *)((int)piVar16 + 0x36)) {
    local_3c = (uint *)0x64;
    do {
      local_54 = piVar16[1] + (int)local_3c;
      if ((*(short *)(local_54 + 0x52) == 0xb4) || (*(short *)(local_54 + 0x52) == 0xb5)) {
        piVar10 = *(int **)(local_54 + 0x38);
        if (piVar10 != (int *)0x0) {
          (**(code **)(*piVar10 + 8))(piVar10);
          *(undefined4 *)(local_54 + 0x38) = 0;
        }
        local_48 = (uint *)0x0;
        if (*(short *)(local_54 + 0x4e) != 0) {
          do {
            local_4c = FUN_008db5a9(param_1,local_44,local_48);
            if (local_4c < 0) goto LAB_008e2182;
            local_48 = (uint *)((int)local_48 + 1);
          } while (local_48 < (uint *)(uint)*(ushort *)(local_54 + 0x4e));
        }
      }
      else if ((*(short *)(local_54 + 0x4e) != 0) &&
              (local_4c = FUN_008db5a9(param_1,local_44,0), local_4c < 0)) goto LAB_008e2182;
      local_44 = (int *)((int)local_44 + 1);
      local_3c = local_3c + 0x19;
      *(undefined2 *)(local_54 + 0x4e) = 0;
    } while (local_44 < (int *)(uint)*(ushort *)((int)piVar16 + 0x36));
  }
  puVar15 = (uint *)0x0;
  local_88 = (undefined4 *)0x0;
  local_84 = (undefined4 *)0x0;
  local_80 = (undefined4 *)0x0;
  uStack_7c = 0;
  *(undefined2 *)((int)piVar16 + 0x36) = 1;
  *(undefined2 *)(piVar16 + 0xd) = 0;
  *(undefined2 *)(piVar16 + 6) = 0;
  piVar16[7] = 0;
  piVar16[8] = 0;
  if ((*(byte *)(iVar7 + 0x14) & 2) == 0) goto LAB_008e2182;
  local_5c = (uint *)0x0;
  local_68 = (int *)0x0;
  local_40 = (int *)0x1;
  local_3c = (uint *)0x1;
  if (*(int *)(iVar7 + 4) == 0) {
    piVar10 = (int *)(iVar7 + 0xc);
    *piVar10 = 0;
    uVar17 = 0;
    local_10[0] = 0;
    local_10[1] = 0;
    piVar9 = piVar16 + 7;
    local_10[2] = 0;
    do {
      *(undefined1 *)(uVar17 + 0x2c + (int)piVar16) = 0;
      *(undefined2 *)piVar9 = 0;
      uVar17 = uVar17 + 1;
      piVar9 = (int *)((int)piVar9 + 2);
    } while (uVar17 < 4);
    local_3c = (uint *)0x0;
    local_44 = piVar10;
  }
  else {
    piVar9 = &local_20;
    psVar11 = local_30;
    puVar23 = local_38;
    piVar10 = (int *)(iVar7 + 0xc);
    piVar22 = piVar10;
    local_44 = piVar10;
    uVar6 = (**(code **)(**(int **)(iVar7 + 8) + 0xc))
                      (*(int **)(iVar7 + 8),piVar10,puVar23,psVar11,piVar9);
    local_4c = FUN_008d578c(uVar6,piVar22,puVar23,psVar11,piVar9);
    if (local_4c < 0) goto LAB_008e2182;
    piVar16[7] = local_20;
    piVar16[8] = (int)local_1c;
    puVar15 = local_78;
    ppuVar25 = &local_5c;
    uVar24 = 0x53455250;
    uVar6 = (**(code **)(**(int **)(iVar7 + 8) + 0xc))
                      (*(int **)(iVar7 + 8),0x53455250,ppuVar25,puVar15);
    local_4c = FUN_008f2d0f(uVar6,uVar24,ppuVar25,puVar15);
    if (local_4c < 0) {
      return;
    }
    if (local_4c == 0) {
      local_40 = (int *)0x2;
      iVar7 = FUN_008f2d0f(local_5c,0x49535250,&local_68,local_8c);
      if (iVar7 < 0) {
        return;
      }
      local_4c = FUN_008d578c(local_5c,&local_6c,local_28,local_18,local_10);
      if (local_4c < 0) {
        return;
      }
      uVar17 = 0;
      do {
        uVar8 = uVar17 + 1;
        local_10[uVar17] = (short)local_68[uVar17 + 3] + (short)local_68[uVar17];
        uVar17 = uVar8;
      } while (uVar8 < 3);
    }
    else {
      local_10[0] = 0;
      local_10[1] = 0;
      local_10[2] = 0;
      piVar10 = local_44;
    }
    piVar9 = piVar16 + 0xb;
    uVar17 = 0;
    puVar15 = local_3c;
    do {
      if ((*(short *)((int)local_30 + uVar17) == 0) &&
         (*(short *)(local_28 + uVar17 + 8) == *(short *)((int)local_38 + uVar17))) {
        cVar13 = '\x01';
      }
      else {
        cVar13 = '\0';
      }
      sVar1 = *(short *)((int)local_38 + uVar17);
      *(char *)piVar9 = cVar13;
      if ((sVar1 != 0) && (cVar13 == '\0')) {
        puVar15 = (uint *)0x0;
      }
      piVar9 = (int *)((int)piVar9 + 1);
      uVar17 = uVar17 + 2;
    } while (uVar17 < 8);
  }
  local_10[3] = 0;
  local_54 = *piVar10;
  *(undefined2 *)((int)piVar16 + 0x4e) = 1;
  *(undefined2 *)(piVar16 + 0x15) = 1;
  *(undefined2 *)((int)piVar16 + 0x5a) = 1;
  *(undefined2 *)(piVar16 + 0x18) = 1;
  *(undefined2 *)(piVar16 + 0x13) = 1;
  *(undefined2 *)((int)piVar16 + 0x52) = 1;
  *(undefined2 *)(piVar16 + 0x16) = 1;
  *(undefined2 *)((int)piVar16 + 0x5e) = 1;
  *(short *)(piVar16 + 0x14) = (short)piVar16[7];
  uVar17 = piVar16[2] & 0xfffffffaU | (uint)puVar15 & 1;
  *(short *)((int)piVar16 + 0x56) = (short)piVar16[8];
  piVar16[2] = uVar17 | 2;
  *(undefined2 *)(piVar16 + 0x17) = *(undefined2 *)((int)piVar16 + 0x1e);
  if (*piVar10 == 0) goto LAB_008e2182;
  piVar16[2] = uVar17 | 10;
  uVar17 = *(int *)(local_54 + 0xc) + (int)local_40;
  if (*(ushort *)(piVar16 + 0xe) < uVar17) {
    puVar15 = operator_new(uVar17 * 100 + 4);
    if (puVar15 == (uint *)0x0) {
      local_48 = (uint *)0x0;
    }
    else {
      *puVar15 = uVar17;
      FUN_0040d030(puVar15 + 1,100,uVar17,&LAB_008de2cc);
      local_48 = puVar15 + 1;
    }
    if (local_48 != (uint *)0x0) {
      uVar3 = *(ushort *)(piVar16[1] + 0x52);
      *(ushort *)((int)local_48 + 0x52) = uVar3;
      uVar17 = *(uint *)(&DAT_00a218ec + (uint)uVar3 * 0x1c);
      *(undefined2 *)(local_48 + 0x15) = 0xffff;
      local_48[0x16] = uVar17;
      *(undefined2 *)((int)local_48 + 0x56) = 1;
      puVar15 = (uint *)(piVar16[1] + 8);
      puVar14 = local_48 + 2;
      for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar14 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar14 = puVar14 + 1;
      }
      *local_48 = *(uint *)piVar16[1];
      local_48[0xc] =
           local_48[0xc] ^ ((*(int *)(piVar16[1] + 0x30) << 0x1f) >> 0x1f ^ local_48[0xc]) & 1;
      local_48[0xc] =
           ((*(int *)(piVar16[1] + 0x30) << 0x1e) >> 0x1e ^ local_48[0xc]) & 2 ^ local_48[0xc];
      local_48[0xf] = *(uint *)(piVar16[1] + 0x3c);
      local_48[0xd] = *(uint *)(piVar16[1] + 0x34);
      *(undefined2 *)((int)local_48 + 0x4e) = *(undefined2 *)(piVar16[1] + 0x4e);
      *(undefined2 *)(local_48 + 0x14) = *(undefined2 *)(piVar16[1] + 0x50);
      local_48[0xe] = *(uint *)(piVar16[1] + 0x38);
      *(undefined4 *)(piVar16[1] + 0x34) = 0;
      *(undefined2 *)(piVar16[1] + 0x4e) = 0;
      *(undefined2 *)(piVar16[1] + 0x50) = 0;
      *(undefined4 *)(piVar16[1] + 0x38) = 0;
      if (piVar16[1] != 0) {
        FUN_008df396(3);
        piVar16[1] = 0;
      }
      piVar16[1] = (int)local_48;
      *(short *)(piVar16 + 0xe) = *(short *)(*local_44 + 0xc) + 1;
      goto LAB_008e173d;
    }
  }
  else {
LAB_008e173d:
    uVar17 = (uint)*(ushort *)(piVar16 + 7);
    piVar16[3] = 0;
    piVar16[0x10] = 0;
    if (*(ushort *)(piVar16 + 7) <= local_10[0]) {
      uVar17 = CONCAT22(local_10[1],local_10[0]);
    }
    local_1c = (uint *)((uVar17 & 0xffff) * 0x10);
    uVar17 = (uint)*(ushort *)((int)piVar16 + 0x1e);
    piVar16[3] = (int)local_1c;
    piVar16[0x12] = (int)local_1c;
    if (*(ushort *)((int)piVar16 + 0x1e) <= local_10[1]) {
      uVar17 = CONCAT22(local_10[2],local_10[1]);
    }
    local_2c = local_1c + (uVar17 & 0xffff);
    uVar17 = (uint)*(ushort *)(piVar16 + 8);
    piVar16[3] = (int)local_2c;
    piVar16[0x11] = (int)local_2c;
    if (*(ushort *)(piVar16 + 8) <= local_10[2]) {
      uVar17 = CONCAT22(local_10[3],local_10[2]);
    }
    local_6c = local_2c + (uVar17 & 0xffff) * 4;
    piVar16[3] = (int)(local_6c + *(ushort *)((int)piVar16 + 0x22));
    *(ushort *)(piVar16 + 0xd) = *(ushort *)((int)piVar16 + 0x22);
    if (local_5c != (uint *)0x0) {
      local_3c = (uint *)((uint)*(ushort *)((int)piVar16 + 0x36) * 100 + piVar16[1]);
      *(ushort *)((int)piVar16 + 0x36) = *(ushort *)((int)piVar16 + 0x36) + 1;
      *local_3c = 1;
      local_3c[0xc] = local_3c[0xc] & 0xfffffff5 | 1;
      piVar16[2] = piVar16[2] | 4;
      puVar15 = local_3c + 0xe;
      local_4c = FUN_008eb3df(local_78[0] + 0x68,puVar15);
      if (local_4c < 0) goto LAB_008e2182;
      piVar10 = (int *)*puVar15;
      local_48 = (uint *)(**(code **)(*piVar10 + 0xc))(piVar10);
      local_14 = (uint *)(local_68 + 4);
      local_40 = local_68 + 3;
      local_50 = (uint *)(local_68 + 1);
      local_24 = local_68;
      local_58 = local_68 + 5;
      local_60 = local_68 + 2;
      uVar17 = (*local_40 + *local_68) * 4 | (*local_40 + *local_68 & 0x3fffffffU) << 1;
      uVar17 = uVar17 | uVar17 >> 2;
      uVar17 = uVar17 | uVar17 >> 4;
      uVar17 = uVar17 | uVar17 >> 8;
      uVar17 = uVar17 | uVar17 >> 0x10;
      uVar8 = (*local_14 + *local_50) * 4 | (*local_14 + *local_50 & 0x3fffffff) << 1;
      uVar8 = uVar8 | uVar8 >> 2;
      uVar8 = uVar8 | uVar8 >> 4;
      uVar8 = uVar8 | uVar8 >> 8;
      uVar8 = uVar8 | uVar8 >> 0x10;
      uVar18 = (*local_60 + *local_58) * 4 | (*local_60 + *local_58 & 0x3fffffffU) << 1;
      local_48[6] = 0;
      uVar18 = uVar18 | uVar18 >> 2;
      uVar18 = uVar18 | uVar18 >> 4;
      uVar18 = uVar18 | uVar18 >> 8;
      local_64 = (undefined4 *)(uVar18 | uVar18 >> 0x10);
      local_48[2] = (uint)local_64;
      *local_48 = uVar17;
      local_48[1] = uVar8;
      uVar18 = (*local_68 + *local_40) * 4;
      local_48[3] = uVar18;
      if (uVar18 != 0) {
        local_48[3] = uVar18 - 1;
      }
      uVar18 = (*local_14 + *local_50) * 4;
      local_48[4] = uVar18;
      if (uVar18 != 0) {
        local_48[4] = uVar18 - 1;
      }
      uVar18 = (*local_58 + *local_60) * 4;
      local_48[5] = uVar18;
      if (uVar18 != 0) {
        local_48[5] = uVar18 - 1;
      }
      uVar18 = local_48[3] >> 1 | local_48[3];
      uVar18 = uVar18 >> 2 | uVar18;
      uVar18 = uVar18 >> 4 | uVar18;
      uVar18 = uVar18 >> 8 | uVar18;
      local_48[3] = uVar18 >> 0x10 | uVar18;
      uVar18 = local_48[4] >> 1 | local_48[4];
      uVar18 = uVar18 >> 2 | uVar18;
      uVar18 = uVar18 >> 4 | uVar18;
      uVar18 = uVar18 >> 8 | uVar18;
      local_48[4] = uVar18 >> 0x10 | uVar18;
      uVar18 = local_48[5] >> 1 | local_48[5];
      uVar18 = uVar18 >> 2 | uVar18;
      uVar18 = uVar18 >> 4 | uVar18;
      uVar18 = uVar18 >> 8 | uVar18;
      local_48[5] = uVar18 >> 0x10 | uVar18;
      uVar18 = (piVar16[3] & 7U) + (piVar16[3] & 0xfffffff8U);
      piVar16[3] = uVar18;
      local_48[7] = uVar18;
      uVar17 = piVar16[3] + uVar17 * 8;
      uVar17 = (uVar17 & 7) + (uVar17 & 0xfffffff8);
      piVar16[3] = uVar17;
      local_48[8] = uVar17;
      uVar17 = piVar16[3] + uVar8 * 8;
      uVar17 = (uVar17 & 7) + (uVar17 & 0xfffffff8);
      piVar16[3] = uVar17;
      local_48[9] = uVar17;
      piVar16[3] = piVar16[3] + (int)local_64 * 8;
      uVar17 = 0;
      local_48[10] = 0;
      local_48[0xb] = (uint)local_1c;
      local_48[0xc] = (uint)local_2c;
      *(undefined2 *)((int)local_3c + 0x56) = 0;
      *(undefined2 *)(local_3c + 0x15) = 0;
      puVar15 = local_48 + 0x10;
      do {
        puVar15[3] = local_40[uVar17];
        *puVar15 = local_68[uVar17];
        uVar17 = uVar17 + 1;
        puVar15 = puVar15 + 1;
      } while (uVar17 < 3);
      local_48[0x17] = (int)local_68 + (0x80 - (int)local_5c);
      uVar17 = (int)local_68 + local_68[6] * 8 + (0x84 - (int)local_5c);
      local_48[0x18] = uVar17;
      local_48[0x19] = uVar17 + 4 + *(int *)((uVar17 - 0x68) + (int)local_5c) * 8;
      puVar15 = local_5c;
      puVar14 = local_48 + 0x1a;
      for (uVar17 = local_78[0] >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
        *puVar14 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar14 = puVar14 + 1;
      }
      for (uVar17 = local_78[0] & 3; uVar17 != 0; uVar17 = uVar17 - 1) {
        *(char *)puVar14 = (char)*puVar15;
        puVar15 = (uint *)((int)puVar15 + 1);
        puVar14 = (uint *)((int)puVar14 + 1);
      }
      local_4c = FUN_008b5afa(local_48 + 0x1a,local_3c + 0x10,local_3c + 0x11);
      if ((local_4c < 0) ||
         (local_4c = FUN_008db391(param_1,*(ushort *)((int)piVar16 + 0x36) - 1,local_48),
         local_4c < 0)) goto LAB_008e2182;
      *(undefined2 *)((int)local_3c + 0x52) = 0xb4;
      local_3c[0x16] = 0x10000000;
      piVar16[2] = piVar16[2] | 1;
      local_50 = (uint *)(piVar16 + 7);
      local_3c = local_48 + 0x17;
      uVar17 = 0;
      do {
        uVar3 = *(ushort *)((int)local_10 + uVar17);
        if (uVar3 != 0) {
          piVar10 = (int *)(*local_3c + (int)local_48);
          iVar4 = 0;
          for (iVar7 = *piVar10; iVar7 != 0; iVar7 = iVar7 + -1) {
            piVar10 = piVar10 + 2;
            iVar4 = iVar4 + *piVar10;
          }
          uVar2 = (ushort)*local_50;
          if ((ushort)*local_50 <= uVar3) {
            uVar2 = uVar3;
          }
          if ((uint)*(ushort *)((int)local_38 + uVar17) + iVar4 != (uint)uVar2) {
            piVar16[2] = piVar16[2] & 0xfffffffe;
            break;
          }
          if ((iVar4 != 0) && (*(ushort *)((int)local_38 + uVar17) == 0)) {
            piVar16[2] = piVar16[2] | 0x10;
          }
        }
        local_3c = local_3c + 1;
        local_50 = (uint *)((int)local_50 + 2);
        uVar17 = uVar17 + 2;
      } while (uVar17 < 6);
      if ((*(byte *)(piVar16 + 2) & 1) != 0) {
        uVar3 = *(ushort *)(piVar16 + 7);
        if (*(ushort *)(piVar16 + 7) <= local_10[0]) {
          uVar3 = local_10[0];
        }
        *(ushort *)(piVar16 + 0x14) = uVar3;
        uVar3 = *(ushort *)(piVar16 + 8);
        if (*(ushort *)(piVar16 + 8) <= local_10[2]) {
          uVar3 = local_10[2];
        }
        *(ushort *)((int)piVar16 + 0x56) = uVar3;
        uVar3 = *(ushort *)((int)piVar16 + 0x1e);
        if (*(ushort *)((int)piVar16 + 0x1e) <= local_10[1]) {
          uVar3 = local_10[1];
        }
        *(ushort *)(piVar16 + 0x17) = uVar3;
      }
    }
    local_4c = FUN_008d5ac8();
    iVar7 = local_54;
    if (local_4c < 0) goto LAB_008e2182;
    *(undefined2 *)(piVar16 + 0xd) = 0;
    local_70 = operator_new(*(int *)(local_54 + 0xc) << 2);
    if (local_70 != (void *)0x0) {
      uVar17 = 0;
      iVar4 = *(int *)(iVar7 + 0x10) + iVar7;
      if (*(int *)(iVar7 + 0xc) != 0) {
        do {
          *(int *)((int)local_70 + uVar17 * 4) = iVar4;
          uVar17 = uVar17 + 1;
          iVar4 = iVar4 + 0x14;
        } while (uVar17 < *(uint *)(iVar7 + 0xc));
      }
      _qsort(local_70,*(size_t *)(iVar7 + 0xc),4,FUN_008d59e0);
      iVar4 = 0;
      iVar5 = 0;
      local_58 = (int *)0x0;
      if (*(int **)(iVar7 + 0xc) != (int *)0x0) {
        psVar11 = (short *)(*(int *)(iVar7 + 0x10) + iVar7 + 4);
        local_40 = *(int **)(iVar7 + 0xc);
        do {
          sVar1 = *psVar11;
          if (sVar1 == 0) {
            iVar5 = iVar5 + 1;
          }
          else if (sVar1 == 1) {
            local_58 = (int *)((int)local_58 + 1);
          }
          else if (sVar1 == 2) {
            iVar4 = iVar4 + 1;
          }
          psVar11 = psVar11 + 10;
          local_40 = (int *)((int)local_40 + -1);
        } while (local_40 != (int *)0x0);
      }
      local_60 = (int *)0x0;
      uVar3 = *(ushort *)((int)piVar16 + 0x36);
      local_3c = (uint *)(uint)uVar3;
      local_50 = (uint *)(iVar4 + (int)local_3c);
      local_58 = (int *)((int)local_58 + (int)local_50);
      local_48 = (uint *)(iVar5 + (int)local_58);
      *(ushort *)((int)piVar16 + 0x36) = *(short *)(iVar7 + 0xc) + uVar3;
      *(ushort *)(piVar16 + 0x13) = uVar3;
      *(short *)((int)piVar16 + 0x52) = (short)local_50;
      *(short *)(piVar16 + 0x16) = (short)local_58;
      *(undefined2 *)((int)piVar16 + 0x5e) = local_48._0_2_;
      if (*(int *)(iVar7 + 0xc) != 0) {
        do {
          piVar10 = *(int **)((int)local_70 + (int)local_60 * 4);
          sVar1 = (short)piVar10[1];
          local_44 = (int *)0x0;
          if (sVar1 == 0) {
            local_44 = (int *)((uint)local_58 & 0xffff);
            local_58 = (int *)((int)local_58 + 1);
          }
          else if (sVar1 == 1) {
            local_44 = (int *)((uint)local_50 & 0xffff);
            local_50 = (uint *)((int)local_50 + 1);
          }
          else if (sVar1 == 2) {
            local_44 = (int *)((uint)local_3c & 0xffff);
            local_3c = (uint *)((int)local_3c + 1);
          }
          else if (sVar1 == 3) {
            local_44 = (int *)((uint)local_48 & 0xffff);
            local_48 = (uint *)((int)local_48 + 1);
          }
          puVar19 = (undefined4 *)((int)local_44 * 100 + piVar16[1]);
          *(undefined2 *)(puVar19 + 0x15) = *(undefined2 *)((int)piVar10 + 6);
          iVar7 = piVar10[2];
          puVar19[0xc] = puVar19[0xc] | 9;
          *(short *)((int)puVar19 + 0x56) = (short)iVar7;
          local_64 = puVar19;
          local_24 = piVar10;
          iVar7 = FUN_008d61a2(*piVar10 + local_54,10);
          local_10[2] = (ushort)iVar7;
          local_10[3] = (ushort)((uint)iVar7 >> 0x10);
          if (iVar7 == 0) {
            *puVar19 = 0;
            puVar19 = (undefined4 *)0x0;
          }
          else {
            if (*(short *)(puVar19 + 0x14) == 0) {
              puVar12 = operator_new(0x24);
              if (puVar12 == (undefined4 *)0x0) {
                puVar15 = (uint *)0x0;
              }
              else {
                *puVar12 = 1;
                local_14 = puVar12 + 1;
                FUN_0040d030(local_14,0x20,1,&LAB_008d5a15);
                puVar15 = local_14;
              }
              puVar19[0xd] = puVar15;
              if (puVar15 == (uint *)0x0) goto LAB_008e20cb;
              *(undefined2 *)(puVar19 + 0x14) = 1;
            }
            local_4c = FUN_008d60b3(param_1,local_44,0,CONCAT22(local_10[3],local_10[2]),piVar10);
            if (local_4c < 0) goto LAB_008e2182;
            puVar19 = (undefined4 *)CONCAT22(local_10[3],local_10[2]);
            *(undefined2 *)((int)local_64 + 0x4e) = 1;
            puVar12 = puVar19;
            puVar20 = local_64 + 2;
            for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar20 = *puVar12;
              puVar12 = puVar12 + 1;
              puVar20 = puVar20 + 1;
            }
            local_64[10] = 0;
            local_64[0xb] = 0;
            local_64[0xc] = local_64[0xc] & 0xfffffffd;
            *local_64 = 1;
          }
          piVar10 = local_24;
          local_64[0xf] = local_54;
          sVar1 = (short)local_24[1];
          if (sVar1 == 0) {
            *(undefined2 *)((int)local_64 + 0x52) = 0x95;
            local_64[0x16] = 0xc010000;
            local_14 = local_1c + *(ushort *)((int)local_24 + 6);
            local_64[0x12] = local_14;
            uVar17 = (uint)*(ushort *)(local_24 + 2);
            if (local_24[4] == 0) {
              puVar19 = (undefined4 *)(*piVar16 + (int)local_14);
              for (; uVar17 != 0; uVar17 = uVar17 - 1) {
                *puVar19 = 0;
                puVar19 = puVar19 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(undefined1 *)puVar19 = 0;
                puVar19 = (undefined4 *)((int)puVar19 + 1);
              }
            }
            else {
              puVar19 = (undefined4 *)(local_54 + local_24[4]);
              puVar12 = (undefined4 *)(*piVar16 + (int)local_14);
              for (; uVar17 != 0; uVar17 = uVar17 - 1) {
                *puVar12 = *puVar19;
                puVar19 = puVar19 + 1;
                puVar12 = puVar12 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(undefined1 *)puVar12 = *(undefined1 *)puVar19;
                puVar19 = (undefined4 *)((int)puVar19 + 1);
                puVar12 = (undefined4 *)((int)puVar12 + 1);
              }
            }
            if (*(char *)((int)piVar16 + 0x2d) != '\0') {
              if (local_84 != (undefined4 *)0x0) {
                local_84[0xc] = local_84[0xc] & 0xfffffffe;
              }
              local_84 = local_64;
            }
          }
          else if (sVar1 == 1) {
            local_40 = (int *)0x0;
            *(undefined2 *)((int)local_64 + 0x52) = 0x96;
            local_64[0x16] = 0xc020000;
            local_64[0x12] = local_2c + (uint)*(ushort *)((int)local_24 + 6) * 4;
            if ((short)local_24[2] != 0) {
              iVar7 = 0;
              do {
                *(undefined4 *)(*piVar16 + local_64[0x12] + iVar7) = 0;
                iVar7 = iVar7 + 0x10;
                *(undefined4 *)(*piVar16 + local_64[0x12] + -0xc + iVar7) = 0;
                *(undefined4 *)(*piVar16 + local_64[0x12] + -8 + iVar7) = 1;
                *(undefined4 *)(*piVar16 + local_64[0x12] + -4 + iVar7) = 0;
                local_40 = (int *)((int)local_40 + 1);
              } while (local_40 < (int *)(uint)*(ushort *)(local_24 + 2));
            }
            if (local_24[4] != 0) {
              puVar19 = (undefined4 *)(local_54 + local_24[4]);
              puVar12 = (undefined4 *)(*piVar16 + local_64[0x12]);
              for (iVar7 = (uint)*(ushort *)(local_24 + 2) << 2; iVar7 != 0; iVar7 = iVar7 + -1) {
                *puVar12 = *puVar19;
                puVar19 = puVar19 + 1;
                puVar12 = puVar12 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(undefined1 *)puVar12 = *(undefined1 *)puVar19;
                puVar19 = (undefined4 *)((int)puVar19 + 1);
                puVar12 = (undefined4 *)((int)puVar12 + 1);
              }
            }
            if (*(char *)((int)piVar16 + 0x2e) != '\0') {
              if (local_80 != (undefined4 *)0x0) {
                local_80[0xc] = local_80[0xc] & 0xfffffffe;
              }
              local_80 = local_64;
            }
          }
          else if (sVar1 == 2) {
            puVar12 = local_64;
            if (puVar19 != (undefined4 *)0x0) {
              iVar7 = *(int *)puVar19[1];
              if (((int *)puVar19[1])[4] == 0) {
                local_44 = (int *)0x1;
              }
              else {
                local_44 = *(int **)(puVar19[1] + 0x10);
              }
              local_40 = *(int **)(puVar19[1] + 0x18);
              iVar4 = *(int *)(puVar19[1] + 4);
              if (-1 < iVar4) {
                if (iVar4 < 2) {
                  if (iVar7 == 3) {
                    local_64[0xc] = local_64[0xc] | 0x10;
                    local_64[0x17] = *puVar19;
                    piVar9 = (int *)(uint)*(ushort *)(local_24 + 2);
                    if (local_44 < (int *)(uint)*(ushort *)(local_24 + 2)) {
                      piVar9 = local_44;
                    }
                    goto LAB_008e1f1b;
                  }
                }
                else if (iVar4 == 2) {
                  if ((iVar7 == 3) && (*(short *)(local_24[3] + local_54) == 3)) {
                    if (local_44 == (int *)0x1) {
                      local_64[0xc] = local_64[0xc] | 0x10;
                      local_64[0x17] = *puVar19;
                      piVar9 = (int *)(uint)*(ushort *)(local_24 + 2);
                      if (local_40 < (int *)(uint)*(ushort *)(local_24 + 2)) {
                        piVar9 = local_40;
                      }
                    }
                    else {
                      if (local_40 != (int *)0x4) goto LAB_008e1f21;
                      local_64[0xc] = local_64[0xc] | 0x10;
                      local_64[0x17] = *puVar19;
                      piVar9 = (int *)((int)local_44 << 2);
                      if ((int *)(uint)*(ushort *)(local_24 + 2) <= (int *)((int)local_44 << 2)) {
                        piVar9 = (int *)(uint)*(ushort *)(local_24 + 2);
                      }
                    }
LAB_008e1f1b:
                    local_64[0x18] = (int)piVar9 << 4;
                  }
                }
                else if (iVar4 == 5) {
                  puVar15 = (uint *)puVar19[1];
                  local_14 = puVar15;
                  uVar21 = FUN_008d542d(&local_14);
                  puVar12 = (undefined4 *)((ulonglong)uVar21 >> 0x20);
                  if ((int)uVar21 != 0) {
                    local_14 = puVar15;
                    uVar8 = FUN_008d53ae(&local_14,4);
                    local_64[0xc] = local_64[0xc] | 0x10;
                    local_64[0x17] = *(undefined4 *)CONCAT22(local_10[3],local_10[2]);
                    uVar17 = (uint)*(ushort *)(local_24 + 2);
                    if (uVar8 < *(ushort *)(local_24 + 2)) {
                      uVar17 = uVar8;
                    }
                    local_64[0x18] = uVar17 << 4;
                    puVar12 = local_64;
                    piVar10 = local_24;
                  }
                }
              }
            }
LAB_008e1f21:
            *(undefined2 *)((int)puVar12 + 0x52) = 0x94;
            puVar12[0x16] = 0xc000000;
            local_14 = (uint *)((uint)*(ushort *)((int)piVar10 + 6) * 0x10);
            puVar12[0x12] = local_14;
            if (piVar10[4] == 0) {
              puVar19 = (undefined4 *)(*piVar16 + (int)local_14);
              for (iVar7 = (uint)*(ushort *)(piVar10 + 2) << 2; iVar7 != 0; iVar7 = iVar7 + -1) {
                *puVar19 = 0;
                puVar19 = puVar19 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(undefined1 *)puVar19 = 0;
                puVar19 = (undefined4 *)((int)puVar19 + 1);
              }
            }
            else {
              puVar19 = (undefined4 *)(local_54 + piVar10[4]);
              puVar20 = (undefined4 *)(*piVar16 + (int)local_14);
              for (iVar7 = (uint)*(ushort *)(piVar10 + 2) << 2; iVar7 != 0; iVar7 = iVar7 + -1) {
                *puVar20 = *puVar19;
                puVar19 = puVar19 + 1;
                puVar20 = puVar20 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(undefined1 *)puVar20 = *(undefined1 *)puVar19;
                puVar19 = (undefined4 *)((int)puVar19 + 1);
                puVar20 = (undefined4 *)((int)puVar20 + 1);
              }
            }
            if ((char)piVar16[0xb] != '\0') {
              if (local_88 != (undefined4 *)0x0) {
                local_88[0xc] = local_88[0xc] & 0xfffffffe;
              }
              local_88 = puVar12;
            }
          }
          else if (sVar1 == 3) {
            *(undefined2 *)((int)local_64 + 0x52) = 0xb2;
            local_64[0x16] = 0xf000000;
            uVar3 = *(ushort *)((int)local_24 + 6);
            *(short *)(local_64 + 0x15) = *(short *)(local_64 + 0x15) + 0x101;
            local_64[0xc] = local_64[0xc] & 0xfffffffd;
            local_64[0x12] = local_6c + uVar3;
            *local_64 = 0;
            if (puVar19 == (undefined4 *)0x0) {
              *(undefined2 *)(*piVar16 + local_64[0x12]) = 0;
              *(undefined2 *)(*piVar16 + 2 + local_64[0x12]) = 0;
            }
            else {
              *(short *)(*piVar16 + local_64[0x12]) = *(short *)(puVar19 + 0x11) + 1;
              *(undefined2 *)(*piVar16 + 2 + local_64[0x12]) = 0;
              uVar3 = *(ushort *)((int)puVar19 + 0x46);
              if (*(ushort *)((int)local_64 + 0x56) < *(ushort *)((int)puVar19 + 0x46)) {
                uVar3 = *(ushort *)((int)local_64 + 0x56);
              }
              *(ushort *)((int)local_64 + 0x56) = uVar3;
            }
            *(undefined2 *)(piVar16[5] + (uint)*(ushort *)(piVar16 + 0xd) * 2 + *piVar16) =
                 local_44._0_2_;
            *(short *)(piVar16 + 0xd) = (short)piVar16[0xd] + 1;
          }
          local_60 = (int *)((int)local_60 + 1);
        } while (local_60 < *(int **)(local_54 + 0xc));
        uVar3 = (ushort)local_3c;
      }
      *(ushort *)((int)piVar16 + 0x4e) = uVar3;
      *(short *)(piVar16 + 0x15) = (short)local_50;
      *(short *)((int)piVar16 + 0x5a) = (short)local_58;
      *(undefined2 *)(piVar16 + 0x18) = local_48._0_2_;
      goto LAB_008e2182;
    }
  }
LAB_008e20cb:
  local_4c = -0x7ff8fff2;
LAB_008e2182:
  _free(local_70);
  return;
}


// ==== FUN_008e219d @ 0x008e219d ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008e219d(uint param_1)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  short *psVar10;
  undefined4 *puVar11;
  uint *puVar12;
  char cVar13;
  int in_ECX;
  uint *puVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  undefined8 uVar20;
  ushort *puVar21;
  undefined4 uVar22;
  uint **ppuVar23;
  undefined1 local_8c [4];
  undefined4 *local_88;
  undefined4 *local_84;
  undefined4 *local_80;
  undefined4 uStack_7c;
  uint local_78 [2];
  void *local_70;
  uint *local_6c;
  uint *local_68;
  uint *local_64;
  undefined4 *local_60;
  uint *local_5c;
  uint *local_58;
  uint local_54;
  uint *local_50;
  int local_4c;
  uint *local_48;
  uint *local_44;
  uint *local_40;
  uint *local_3c;
  ushort local_38 [4];
  short local_30 [2];
  uint *local_2c;
  undefined1 local_28 [4];
  uint *local_24;
  int local_20;
  uint *local_1c;
  undefined1 local_18 [4];
  uint *local_14;
  ushort local_10 [4];
  undefined4 local_8;
  
  piVar15 = (int *)(param_1 * 100 + *(int *)(in_ECX + 0x2c));
  iVar7 = piVar15[1];
  local_8 = DAT_00b49670;
  iVar4 = *(int *)(iVar7 + 0x1c) * 4;
  local_4c = 0;
  local_70 = (void *)0x0;
  if (*(int *)(*(int *)(iVar4 + *(int *)(in_ECX + 0xb0)) + 0x40) == 0) {
    iVar5 = *(int *)(in_ECX + 0x20);
  }
  else {
    iVar5 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
  }
  *(int *)(iVar7 + 8) =
       *(int *)(*(int *)(iVar4 + *(int *)(in_ECX + 0xb0)) + 0x30) + *(int *)(iVar7 + 0x24) + iVar5;
  iVar7 = piVar15[1];
  iVar4 = *(int *)(iVar7 + 0x1c) * 4;
  if (*(int *)(*(int *)(iVar4 + *(int *)(in_ECX + 0xb0)) + 0x40) == 0) {
    local_44 = *(uint **)(in_ECX + 0x20);
  }
  else {
    local_44 = *(uint **)(*(int *)(in_ECX + 0x38) + 0x10);
  }
  *(int *)(iVar7 + 0xc) =
       *(int *)(*(int *)(iVar4 + *(int *)(in_ECX + 0xb0)) + 0x2c) + *(int *)(iVar7 + 0x20) +
       (int)local_44;
  iVar7 = piVar15[1];
  iVar5 = *(int *)(iVar7 + 0x1c) * 4;
  iVar4 = *(int *)(iVar5 + *(int *)(in_ECX + 0xb0));
  if (*(int *)(*(int *)(iVar5 + *(int *)(in_ECX + 0xb0)) + 0x40) == 0) {
    if (*(int *)(iVar4 + 0x40) == 0) {
      iVar5 = *(int *)(in_ECX + 0x20);
    }
    else {
      iVar5 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
    }
    iVar7 = *(int *)(*(int *)(iVar4 + 0x30) + *(int *)(iVar7 + 0x24) + iVar5);
  }
  else {
    if (*(int *)(iVar4 + 0x40) == 0) {
      local_44 = *(uint **)(in_ECX + 0x20);
    }
    else {
      local_44 = *(uint **)(*(int *)(in_ECX + 0x38) + 0x10);
    }
    iVar4 = *(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(iVar7 + 0x1c) * 4);
    iVar7 = *(int *)(*(int *)(*(int *)(iVar4 + 0x40) + 8) +
                    *(int *)(*(int *)(iVar7 + 0x24) + *(int *)(iVar4 + 0x30) + (int)local_44) * 4);
  }
  iVar7 = *(int *)(in_ECX + 0x18) + iVar7 * 0x18;
  if ((*(uint *)(iVar7 + 0x14) & 1) == 0) {
    if ((((*(byte *)(piVar15 + 2) & 8) != 0) && (*(int *)(in_ECX + 0xb4) != 0)) &&
       ((*(byte *)(in_ECX + 0x119) & 8) == 0)) {
      local_6c = (uint *)(*(int *)(in_ECX + 0xac) * *(int *)(in_ECX + 0xa0));
      local_50 = (uint *)0x0;
      if (local_6c != (uint *)0x0) {
        do {
          puVar14 = *(uint **)((int)local_50 * 4 + *(int *)(in_ECX + 0xc0));
          if (puVar14 != (uint *)0x0) {
            local_1c = *(uint **)((int)local_50 * 4 + *(int *)(in_ECX + 0xb4));
            uVar16 = *puVar14;
            puVar12 = (uint *)0x0;
            local_40 = puVar14;
            if (uVar16 != 0) {
              do {
                if (*(ushort *)(uVar16 + 0x14) == param_1) {
                  if ((puVar12 == (uint *)0x0) && (puVar12 = local_1c, *local_1c != 0)) {
                    do {
                      local_1c = local_1c + 1;
                    } while (*local_1c != 0);
                    puVar12 = local_1c;
                  }
                  *puVar12 = uVar16;
                  puVar12 = puVar12 + 1;
                  *puVar12 = 0;
                }
                local_40 = local_40 + 1;
                uVar16 = *local_40;
              } while (uVar16 != 0);
            }
          }
          local_50 = (uint *)((int)local_50 + 1);
        } while (local_50 < local_6c);
      }
      piVar15[2] = piVar15[2] & 0xfffffff7;
    }
    local_4c = 0;
    goto LAB_008e310a;
  }
  if (*(int *)(iVar7 + 4) == 0) {
    *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) | 2;
    *(undefined4 *)(iVar7 + 0xc) = 0;
  }
  else {
    local_4c = FUN_008db71a(iVar7);
    if (local_4c < 0) goto LAB_008e310a;
  }
  *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) & 0xfffffffe;
  local_54 = 1;
  if (1 < *(ushort *)((int)piVar15 + 0x36)) {
    local_40 = (uint *)0x64;
    do {
      local_3c = (uint *)(piVar15[1] + (int)local_40);
      if ((*(short *)((int)local_3c + 0x52) == 0xb4) || (*(short *)((int)local_3c + 0x52) == 0xb5))
      {
        piVar9 = (int *)local_3c[0xe];
        if (piVar9 != (int *)0x0) {
          (**(code **)(*piVar9 + 8))(piVar9);
          local_3c[0xe] = 0;
        }
        local_48 = (uint *)0x0;
        if (*(short *)((int)local_3c + 0x4e) != 0) {
          do {
            local_4c = FUN_008db5a9(param_1,local_54,local_48);
            if (local_4c < 0) goto LAB_008e310a;
            local_48 = (uint *)((int)local_48 + 1);
          } while (local_48 < (uint *)(uint)*(ushort *)((int)local_3c + 0x4e));
        }
      }
      else if ((*(short *)((int)local_3c + 0x4e) != 0) &&
              (local_4c = FUN_008db5a9(param_1,local_54,0), local_4c < 0)) goto LAB_008e310a;
      local_54 = local_54 + 1;
      local_40 = local_40 + 0x19;
      *(undefined2 *)((int)local_3c + 0x4e) = 0;
    } while (local_54 < *(ushort *)((int)piVar15 + 0x36));
  }
  puVar14 = (uint *)0x0;
  local_88 = (undefined4 *)0x0;
  local_84 = (undefined4 *)0x0;
  local_80 = (undefined4 *)0x0;
  uStack_7c = 0;
  *(undefined2 *)((int)piVar15 + 0x36) = 1;
  *(undefined2 *)(piVar15 + 0xd) = 0;
  *(undefined2 *)((int)piVar15 + 0x1a) = 0;
  piVar15[9] = 0;
  piVar15[10] = 0;
  if ((*(byte *)(iVar7 + 0x14) & 2) == 0) goto LAB_008e310a;
  local_5c = (uint *)0x0;
  local_68 = (uint *)0x0;
  local_44 = (uint *)0x1;
  local_40 = (uint *)0x1;
  if (*(int *)(iVar7 + 4) == 0) {
    puVar12 = (uint *)(iVar7 + 0xc);
    *puVar12 = 0;
    uVar16 = 0;
    local_10[0] = 0;
    local_10[1] = 0;
    piVar9 = piVar15 + 9;
    local_10[2] = 0;
    do {
      *(undefined1 *)(uVar16 + 0x30 + (int)piVar15) = 0;
      *(undefined2 *)piVar9 = 0;
      uVar16 = uVar16 + 1;
      piVar9 = (int *)((int)piVar9 + 2);
    } while (uVar16 < 4);
    local_40 = (uint *)0x0;
    local_3c = puVar12;
  }
  else {
    piVar9 = &local_20;
    psVar10 = local_30;
    puVar21 = local_38;
    puVar12 = (uint *)(iVar7 + 0xc);
    puVar14 = puVar12;
    local_3c = puVar12;
    uVar6 = (**(code **)(**(int **)(iVar7 + 8) + 0xc))
                      (*(int **)(iVar7 + 8),puVar12,puVar21,psVar10,piVar9);
    local_4c = FUN_008d578c(uVar6,puVar14,puVar21,psVar10,piVar9);
    if (local_4c < 0) goto LAB_008e310a;
    piVar15[9] = local_20;
    piVar15[10] = (int)local_1c;
    puVar14 = local_78;
    ppuVar23 = &local_5c;
    uVar22 = 0x53455250;
    uVar6 = (**(code **)(**(int **)(iVar7 + 8) + 0xc))
                      (*(int **)(iVar7 + 8),0x53455250,ppuVar23,puVar14);
    local_4c = FUN_008f2d0f(uVar6,uVar22,ppuVar23,puVar14);
    if (local_4c < 0) {
      return;
    }
    if (local_4c == 0) {
      local_44 = (uint *)0x2;
      iVar7 = FUN_008f2d0f(local_5c,0x49535250,&local_68,local_8c);
      if (iVar7 < 0) {
        return;
      }
      local_4c = FUN_008d578c(local_5c,&local_6c,local_28,local_18,local_10);
      if (local_4c < 0) {
        return;
      }
      uVar16 = 0;
      do {
        uVar8 = uVar16 + 1;
        local_10[uVar16] = (short)local_68[uVar16 + 3] + (short)local_68[uVar16];
        uVar16 = uVar8;
      } while (uVar8 < 3);
    }
    else {
      local_10[0] = 0;
      local_10[1] = 0;
      local_10[2] = 0;
      puVar12 = local_3c;
    }
    piVar9 = piVar15 + 0xc;
    uVar16 = 0;
    puVar14 = local_40;
    do {
      if ((*(short *)((int)local_30 + uVar16) == 0) &&
         (*(short *)(local_28 + uVar16 + 8) == *(short *)((int)local_38 + uVar16))) {
        cVar13 = '\x01';
      }
      else {
        cVar13 = '\0';
      }
      sVar1 = *(short *)((int)local_38 + uVar16);
      *(char *)piVar9 = cVar13;
      if ((sVar1 != 0) && (cVar13 == '\0')) {
        puVar14 = (uint *)0x0;
      }
      piVar9 = (int *)((int)piVar9 + 1);
      uVar16 = uVar16 + 2;
    } while (uVar16 < 8);
  }
  local_10[3] = 0;
  local_54 = *puVar12;
  *(undefined2 *)((int)piVar15 + 0x4e) = 1;
  *(undefined2 *)(piVar15 + 0x15) = 1;
  *(undefined2 *)((int)piVar15 + 0x5a) = 1;
  *(undefined2 *)(piVar15 + 0x18) = 1;
  *(undefined2 *)(piVar15 + 0x13) = 1;
  *(undefined2 *)((int)piVar15 + 0x52) = 1;
  *(undefined2 *)(piVar15 + 0x16) = 1;
  *(undefined2 *)((int)piVar15 + 0x5e) = 1;
  *(short *)(piVar15 + 0x14) = (short)piVar15[9];
  *(short *)((int)piVar15 + 0x56) = (short)piVar15[10];
  uVar16 = piVar15[2] & 0xfffffffaU | (uint)puVar14 & 1;
  piVar15[2] = uVar16;
  *(undefined2 *)(piVar15 + 0x17) = *(undefined2 *)((int)piVar15 + 0x26);
  if (*puVar12 == 0) goto LAB_008e310a;
  piVar15[2] = uVar16 | 8;
  uVar16 = *(int *)(local_54 + 0xc) + (int)local_44;
  if (*(ushort *)(piVar15 + 0xe) < uVar16) {
    puVar14 = operator_new(uVar16 * 100 + 4);
    if (puVar14 == (uint *)0x0) {
      local_48 = (uint *)0x0;
    }
    else {
      *puVar14 = uVar16;
      FUN_0040d030(puVar14 + 1,100,uVar16,&LAB_008de2cc);
      local_48 = puVar14 + 1;
    }
    if (local_48 != (uint *)0x0) {
      uVar3 = *(ushort *)(piVar15[1] + 0x52);
      *(ushort *)((int)local_48 + 0x52) = uVar3;
      uVar16 = *(uint *)(&DAT_00a218ec + (uint)uVar3 * 0x1c);
      *(undefined2 *)(local_48 + 0x15) = 0xffff;
      local_48[0x16] = uVar16;
      *(undefined2 *)((int)local_48 + 0x56) = 1;
      puVar14 = (uint *)(piVar15[1] + 8);
      puVar12 = local_48 + 2;
      for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar12 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar12 = puVar12 + 1;
      }
      *local_48 = *(uint *)piVar15[1];
      local_48[0xc] =
           local_48[0xc] ^ ((*(int *)(piVar15[1] + 0x30) << 0x1f) >> 0x1f ^ local_48[0xc]) & 1;
      local_48[0xc] =
           ((*(int *)(piVar15[1] + 0x30) << 0x1e) >> 0x1e ^ local_48[0xc]) & 2 ^ local_48[0xc];
      local_48[0xf] = *(uint *)(piVar15[1] + 0x3c);
      local_48[0xd] = *(uint *)(piVar15[1] + 0x34);
      *(undefined2 *)((int)local_48 + 0x4e) = *(undefined2 *)(piVar15[1] + 0x4e);
      *(undefined2 *)(local_48 + 0x14) = *(undefined2 *)(piVar15[1] + 0x50);
      local_48[0xe] = *(uint *)(piVar15[1] + 0x38);
      *(undefined4 *)(piVar15[1] + 0x34) = 0;
      *(undefined2 *)(piVar15[1] + 0x4e) = 0;
      *(undefined2 *)(piVar15[1] + 0x50) = 0;
      *(undefined4 *)(piVar15[1] + 0x38) = 0;
      if (piVar15[1] != 0) {
        FUN_008df396(3);
        piVar15[1] = 0;
      }
      piVar15[1] = (int)local_48;
      *(short *)(piVar15 + 0xe) = *(short *)(*local_3c + 0xc) + 1;
      goto LAB_008e26ad;
    }
  }
  else {
LAB_008e26ad:
    uVar16 = (uint)*(ushort *)(piVar15 + 9);
    piVar15[3] = 0;
    piVar15[0x10] = 0;
    if (*(ushort *)(piVar15 + 9) <= local_10[0]) {
      uVar16 = CONCAT22(local_10[1],local_10[0]);
    }
    local_1c = (uint *)((uVar16 & 0xffff) * 0x10);
    uVar16 = (uint)*(ushort *)((int)piVar15 + 0x26);
    piVar15[3] = (int)local_1c;
    piVar15[0x12] = (int)local_1c;
    if (*(ushort *)((int)piVar15 + 0x26) <= local_10[1]) {
      uVar16 = CONCAT22(local_10[2],local_10[1]);
    }
    local_2c = local_1c + (uVar16 & 0xffff);
    uVar16 = (uint)*(ushort *)(piVar15 + 10);
    piVar15[3] = (int)local_2c;
    piVar15[0x11] = (int)local_2c;
    if (*(ushort *)(piVar15 + 10) <= local_10[2]) {
      uVar16 = CONCAT22(local_10[3],local_10[2]);
    }
    local_6c = local_2c + (uVar16 & 0xffff) * 4;
    piVar15[3] = (int)(local_6c + *(ushort *)((int)piVar15 + 0x2a));
    *(ushort *)(piVar15 + 0xd) = *(ushort *)((int)piVar15 + 0x2a);
    if (local_5c != (uint *)0x0) {
      local_40 = (uint *)((uint)*(ushort *)((int)piVar15 + 0x36) * 100 + piVar15[1]);
      *(ushort *)((int)piVar15 + 0x36) = *(ushort *)((int)piVar15 + 0x36) + 1;
      *local_40 = 1;
      local_40[0xc] = local_40[0xc] & 0xfffffff5 | 1;
      piVar15[2] = piVar15[2] | 4;
      puVar14 = local_40 + 0xe;
      local_4c = FUN_008eb3df(local_78[0] + 0x68,puVar14);
      if (local_4c < 0) goto LAB_008e310a;
      piVar9 = (int *)*puVar14;
      local_48 = (uint *)(**(code **)(*piVar9 + 0xc))(piVar9);
      local_24 = local_68 + 3;
      local_58 = local_68 + 4;
      local_14 = local_68 + 1;
      local_50 = local_68;
      local_64 = local_68 + 5;
      local_44 = local_68 + 2;
      uVar16 = (*local_68 + *local_24) * 4 | (*local_68 + *local_24 & 0x3fffffff) << 1;
      uVar16 = uVar16 | uVar16 >> 2;
      uVar16 = uVar16 | uVar16 >> 4;
      uVar16 = uVar16 | uVar16 >> 8;
      uVar16 = uVar16 | uVar16 >> 0x10;
      uVar8 = (*local_14 + *local_58) * 4 | (*local_14 + *local_58 & 0x3fffffff) << 1;
      uVar8 = uVar8 | uVar8 >> 2;
      uVar8 = uVar8 | uVar8 >> 4;
      uVar8 = uVar8 | uVar8 >> 8;
      uVar8 = uVar8 | uVar8 >> 0x10;
      uVar17 = (*local_64 + *local_44) * 4 | (*local_64 + *local_44 & 0x3fffffff) << 1;
      local_48[6] = 0;
      uVar17 = uVar17 | uVar17 >> 2;
      uVar17 = uVar17 | uVar17 >> 4;
      uVar17 = uVar17 | uVar17 >> 8;
      local_60 = (undefined4 *)(uVar17 | uVar17 >> 0x10);
      local_48[2] = (uint)local_60;
      *local_48 = uVar16;
      local_48[1] = uVar8;
      uVar17 = (*local_24 + *local_68) * 4;
      local_48[3] = uVar17;
      if (uVar17 != 0) {
        local_48[3] = uVar17 - 1;
      }
      uVar17 = (*local_14 + *local_58) * 4;
      local_48[4] = uVar17;
      if (uVar17 != 0) {
        local_48[4] = uVar17 - 1;
      }
      uVar17 = (*local_44 + *local_64) * 4;
      local_48[5] = uVar17;
      if (uVar17 != 0) {
        local_48[5] = uVar17 - 1;
      }
      uVar17 = local_48[3] >> 1 | local_48[3];
      uVar17 = uVar17 >> 2 | uVar17;
      uVar17 = uVar17 >> 4 | uVar17;
      uVar17 = uVar17 >> 8 | uVar17;
      local_48[3] = uVar17 >> 0x10 | uVar17;
      uVar17 = local_48[4] >> 1 | local_48[4];
      uVar17 = uVar17 >> 2 | uVar17;
      uVar17 = uVar17 >> 4 | uVar17;
      uVar17 = uVar17 >> 8 | uVar17;
      local_48[4] = uVar17 >> 0x10 | uVar17;
      uVar17 = local_48[5] >> 1 | local_48[5];
      uVar17 = uVar17 >> 2 | uVar17;
      uVar17 = uVar17 >> 4 | uVar17;
      uVar17 = uVar17 >> 8 | uVar17;
      local_48[5] = uVar17 >> 0x10 | uVar17;
      uVar17 = (piVar15[3] & 7U) + (piVar15[3] & 0xfffffff8U);
      piVar15[3] = uVar17;
      local_48[7] = uVar17;
      uVar16 = piVar15[3] + uVar16 * 8;
      uVar16 = (uVar16 & 7) + (uVar16 & 0xfffffff8);
      piVar15[3] = uVar16;
      local_48[8] = uVar16;
      uVar16 = piVar15[3] + uVar8 * 8;
      uVar16 = (uVar16 & 7) + (uVar16 & 0xfffffff8);
      piVar15[3] = uVar16;
      local_48[9] = uVar16;
      piVar15[3] = piVar15[3] + (int)local_60 * 8;
      uVar16 = 0;
      local_48[10] = 0;
      local_48[0xb] = (uint)local_1c;
      local_48[0xc] = (uint)local_2c;
      *(undefined2 *)((int)local_40 + 0x56) = 0;
      *(undefined2 *)(local_40 + 0x15) = 0;
      puVar14 = local_48 + 0x10;
      do {
        puVar14[3] = local_24[uVar16];
        *puVar14 = local_68[uVar16];
        uVar16 = uVar16 + 1;
        puVar14 = puVar14 + 1;
      } while (uVar16 < 3);
      local_48[0x17] = (int)local_68 + (0x80 - (int)local_5c);
      uVar16 = (int)local_68 + local_68[6] * 8 + (0x84 - (int)local_5c);
      local_48[0x18] = uVar16;
      local_48[0x19] = uVar16 + 4 + *(int *)((uVar16 - 0x68) + (int)local_5c) * 8;
      puVar14 = local_5c;
      puVar12 = local_48 + 0x1a;
      for (uVar16 = local_78[0] >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
        *puVar12 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar12 = puVar12 + 1;
      }
      for (uVar16 = local_78[0] & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
        *(char *)puVar12 = (char)*puVar14;
        puVar14 = (uint *)((int)puVar14 + 1);
        puVar12 = (uint *)((int)puVar12 + 1);
      }
      local_4c = FUN_008b5afa(local_48 + 0x1a,local_40 + 0x10,local_40 + 0x11);
      if ((local_4c < 0) ||
         (local_4c = FUN_008db391(param_1,*(ushort *)((int)piVar15 + 0x36) - 1,local_48),
         local_4c < 0)) goto LAB_008e310a;
      *(undefined2 *)((int)local_40 + 0x52) = 0xb5;
      local_40[0x16] = 0x11000000;
      piVar15[2] = piVar15[2] | 1;
      local_50 = (uint *)(piVar15 + 9);
      local_40 = local_48 + 0x17;
      uVar16 = 0;
      do {
        uVar3 = *(ushort *)((int)local_10 + uVar16);
        if (uVar3 != 0) {
          piVar9 = (int *)(*local_40 + (int)local_48);
          iVar4 = 0;
          for (iVar7 = *piVar9; iVar7 != 0; iVar7 = iVar7 + -1) {
            piVar9 = piVar9 + 2;
            iVar4 = iVar4 + *piVar9;
          }
          uVar2 = (ushort)*local_50;
          if ((ushort)*local_50 <= uVar3) {
            uVar2 = uVar3;
          }
          if ((uint)*(ushort *)((int)local_38 + uVar16) + iVar4 != (uint)uVar2) {
            piVar15[2] = piVar15[2] & 0xfffffffe;
            break;
          }
          if ((iVar4 != 0) && (*(ushort *)((int)local_38 + uVar16) == 0)) {
            piVar15[2] = piVar15[2] | 0x10;
          }
        }
        local_40 = local_40 + 1;
        local_50 = (uint *)((int)local_50 + 2);
        uVar16 = uVar16 + 2;
      } while (uVar16 < 6);
      if ((*(byte *)(piVar15 + 2) & 1) != 0) {
        uVar3 = *(ushort *)(piVar15 + 9);
        if (*(ushort *)(piVar15 + 9) <= local_10[0]) {
          uVar3 = local_10[0];
        }
        *(ushort *)(piVar15 + 0x14) = uVar3;
        uVar3 = *(ushort *)(piVar15 + 10);
        if (*(ushort *)(piVar15 + 10) <= local_10[2]) {
          uVar3 = local_10[2];
        }
        *(ushort *)((int)piVar15 + 0x56) = uVar3;
        uVar3 = *(ushort *)((int)piVar15 + 0x26);
        if (*(ushort *)((int)piVar15 + 0x26) <= local_10[1]) {
          uVar3 = local_10[1];
        }
        *(ushort *)(piVar15 + 0x17) = uVar3;
      }
    }
    local_4c = FUN_008d5ac8();
    uVar16 = local_54;
    if (local_4c < 0) goto LAB_008e310a;
    *(undefined2 *)(piVar15 + 0xd) = 0;
    local_70 = operator_new(*(int *)(local_54 + 0xc) << 2);
    if (local_70 != (void *)0x0) {
      uVar8 = 0;
      iVar7 = *(int *)(uVar16 + 0x10) + uVar16;
      if (*(int *)(uVar16 + 0xc) != 0) {
        do {
          *(int *)((int)local_70 + uVar8 * 4) = iVar7;
          uVar8 = uVar8 + 1;
          iVar7 = iVar7 + 0x14;
        } while (uVar8 < *(uint *)(uVar16 + 0xc));
      }
      _qsort(local_70,*(size_t *)(uVar16 + 0xc),4,FUN_008d59e0);
      iVar7 = 0;
      iVar4 = 0;
      local_58 = (uint *)0x0;
      if (*(uint **)(uVar16 + 0xc) != (uint *)0x0) {
        psVar10 = (short *)(*(int *)(uVar16 + 0x10) + uVar16 + 4);
        local_44 = *(uint **)(uVar16 + 0xc);
        do {
          sVar1 = *psVar10;
          if (sVar1 == 0) {
            iVar4 = iVar4 + 1;
          }
          else if (sVar1 == 1) {
            local_58 = (uint *)((int)local_58 + 1);
          }
          else if (sVar1 == 2) {
            iVar7 = iVar7 + 1;
          }
          psVar10 = psVar10 + 10;
          local_44 = (uint *)((int)local_44 + -1);
        } while (local_44 != (uint *)0x0);
      }
      local_64 = (uint *)0x0;
      uVar3 = *(ushort *)((int)piVar15 + 0x36);
      local_40 = (uint *)(uint)uVar3;
      local_50 = (uint *)(iVar7 + (int)local_40);
      local_58 = (uint *)((int)local_58 + (int)local_50);
      local_48 = (uint *)(iVar4 + (int)local_58);
      *(ushort *)((int)piVar15 + 0x36) = *(short *)(uVar16 + 0xc) + uVar3;
      *(ushort *)(piVar15 + 0x13) = uVar3;
      *(short *)((int)piVar15 + 0x52) = (short)local_50;
      *(short *)(piVar15 + 0x16) = (short)local_58;
      *(undefined2 *)((int)piVar15 + 0x5e) = local_48._0_2_;
      if (*(int *)(uVar16 + 0xc) != 0) {
        do {
          puVar14 = *(uint **)((int)local_70 + (int)local_64 * 4);
          sVar1 = (short)puVar14[1];
          local_3c = (uint *)0x0;
          if (sVar1 == 0) {
            local_3c = (uint *)((uint)local_58 & 0xffff);
            local_58 = (uint *)((int)local_58 + 1);
          }
          else if (sVar1 == 1) {
            local_3c = (uint *)((uint)local_50 & 0xffff);
            local_50 = (uint *)((int)local_50 + 1);
          }
          else if (sVar1 == 2) {
            local_3c = (uint *)((uint)local_40 & 0xffff);
            local_40 = (uint *)((int)local_40 + 1);
          }
          else if (sVar1 == 3) {
            local_3c = (uint *)((uint)local_48 & 0xffff);
            local_48 = (uint *)((int)local_48 + 1);
          }
          puVar18 = (undefined4 *)((int)local_3c * 100 + piVar15[1]);
          *(undefined2 *)(puVar18 + 0x15) = *(undefined2 *)((int)puVar14 + 6);
          uVar16 = puVar14[2];
          puVar18[0xc] = puVar18[0xc] | 9;
          *(short *)((int)puVar18 + 0x56) = (short)uVar16;
          local_60 = puVar18;
          local_24 = puVar14;
          iVar7 = FUN_008d61a2(*puVar14 + local_54,10);
          local_10[2] = (ushort)iVar7;
          local_10[3] = (ushort)((uint)iVar7 >> 0x10);
          if (iVar7 == 0) {
            *puVar18 = 0;
            puVar18 = (undefined4 *)0x0;
          }
          else {
            if (*(short *)(puVar18 + 0x14) == 0) {
              puVar11 = operator_new(0x24);
              if (puVar11 == (undefined4 *)0x0) {
                puVar12 = (uint *)0x0;
              }
              else {
                *puVar11 = 1;
                local_14 = puVar11 + 1;
                FUN_0040d030(local_14,0x20,1,&LAB_008d5a15);
                puVar12 = local_14;
              }
              puVar18[0xd] = puVar12;
              if (puVar12 == (uint *)0x0) goto LAB_008e3053;
              *(undefined2 *)(puVar18 + 0x14) = 1;
            }
            local_4c = FUN_008d60b3(param_1,local_3c,0,CONCAT22(local_10[3],local_10[2]),puVar14);
            if (local_4c < 0) goto LAB_008e310a;
            puVar18 = (undefined4 *)CONCAT22(local_10[3],local_10[2]);
            *(undefined2 *)((int)local_60 + 0x4e) = 1;
            puVar11 = puVar18;
            puVar19 = local_60 + 2;
            for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar19 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar19 = puVar19 + 1;
            }
            local_60[0xc] = local_60[0xc] & 0xfffffffd;
            local_60[10] = 0;
            local_60[0xb] = 0;
            *local_60 = 1;
          }
          puVar14 = local_24;
          local_60[0xf] = local_54;
          sVar1 = (short)local_24[1];
          if (sVar1 == 0) {
            *(undefined2 *)((int)local_60 + 0x52) = 0x9d;
            local_60[0x16] = 0xd010000;
            local_14 = local_1c + *(ushort *)((int)local_24 + 6);
            local_60[0x12] = local_14;
            uVar16 = (uint)(ushort)local_24[2];
            if (local_24[4] == 0) {
              puVar18 = (undefined4 *)(*piVar15 + (int)local_14);
              for (; uVar16 != 0; uVar16 = uVar16 - 1) {
                *puVar18 = 0;
                puVar18 = puVar18 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(undefined1 *)puVar18 = 0;
                puVar18 = (undefined4 *)((int)puVar18 + 1);
              }
            }
            else {
              puVar18 = (undefined4 *)(local_24[4] + local_54);
              puVar11 = (undefined4 *)(*piVar15 + (int)local_14);
              for (; uVar16 != 0; uVar16 = uVar16 - 1) {
                *puVar11 = *puVar18;
                puVar18 = puVar18 + 1;
                puVar11 = puVar11 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(undefined1 *)puVar11 = *(undefined1 *)puVar18;
                puVar18 = (undefined4 *)((int)puVar18 + 1);
                puVar11 = (undefined4 *)((int)puVar11 + 1);
              }
            }
            if (*(char *)((int)piVar15 + 0x31) != '\0') {
              if (local_84 != (undefined4 *)0x0) {
                local_84[0xc] = local_84[0xc] & 0xfffffffe;
              }
              local_84 = local_60;
            }
          }
          else if (sVar1 == 1) {
            *(undefined2 *)((int)local_60 + 0x52) = 0x9e;
            local_60[0x16] = 0xd020000;
            local_44 = (uint *)0x0;
            local_60[0x12] = local_2c + (uint)*(ushort *)((int)local_24 + 6) * 4;
            if ((short)local_24[2] != 0) {
              local_3c = (uint *)0x0;
              do {
                *(undefined4 *)((int)local_3c + local_60[0x12] + *piVar15) = 0;
                *(undefined4 *)((int)local_3c + local_60[0x12] + *piVar15 + 4) = 0;
                *(undefined4 *)((int)local_3c + local_60[0x12] + *piVar15 + 8) = 1;
                local_44 = (uint *)((int)local_44 + 1);
                puVar14 = local_3c + 4;
                *(undefined4 *)((int)local_3c + local_60[0x12] + *piVar15 + 0xc) = 0;
                local_3c = puVar14;
              } while (local_44 < (uint *)(uint)(ushort)local_24[2]);
            }
            if (local_24[4] != 0) {
              puVar18 = (undefined4 *)(local_54 + local_24[4]);
              puVar11 = (undefined4 *)(*piVar15 + local_60[0x12]);
              for (iVar7 = (uint)(ushort)local_24[2] << 2; iVar7 != 0; iVar7 = iVar7 + -1) {
                *puVar11 = *puVar18;
                puVar18 = puVar18 + 1;
                puVar11 = puVar11 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(undefined1 *)puVar11 = *(undefined1 *)puVar18;
                puVar18 = (undefined4 *)((int)puVar18 + 1);
                puVar11 = (undefined4 *)((int)puVar11 + 1);
              }
            }
            if (*(char *)((int)piVar15 + 0x32) != '\0') {
              if (local_80 != (undefined4 *)0x0) {
                local_80[0xc] = local_80[0xc] & 0xfffffffe;
              }
              local_80 = local_60;
            }
          }
          else if (sVar1 == 2) {
            puVar11 = local_60;
            if (puVar18 != (undefined4 *)0x0) {
              iVar7 = *(int *)puVar18[1];
              if (((int *)puVar18[1])[4] == 0) {
                local_3c = (uint *)0x1;
              }
              else {
                local_3c = *(uint **)(puVar18[1] + 0x10);
              }
              local_44 = *(uint **)(puVar18[1] + 0x18);
              iVar4 = *(int *)(puVar18[1] + 4);
              if (-1 < iVar4) {
                if (iVar4 < 2) {
                  if (iVar7 == 3) {
                    local_60[0xc] = local_60[0xc] | 0x10;
                    local_60[0x17] = *puVar18;
                    puVar12 = (uint *)(uint)(ushort)local_24[2];
                    if (local_3c < (uint *)(uint)(ushort)local_24[2]) {
                      puVar12 = local_3c;
                    }
                    goto LAB_008e2e87;
                  }
                }
                else if (iVar4 == 2) {
                  if ((iVar7 == 3) && (*(short *)(local_24[3] + local_54) == 3)) {
                    if (local_3c == (uint *)0x1) {
                      local_60[0xc] = local_60[0xc] | 0x10;
                      local_60[0x17] = *puVar18;
                      puVar12 = (uint *)(uint)(ushort)local_24[2];
                      if (local_44 < (uint *)(uint)(ushort)local_24[2]) {
                        puVar12 = local_44;
                      }
                    }
                    else {
                      if (local_44 != (uint *)0x4) goto LAB_008e2e8d;
                      local_60[0xc] = local_60[0xc] | 0x10;
                      local_60[0x17] = *puVar18;
                      puVar12 = (uint *)((int)local_3c << 2);
                      if ((uint *)(uint)(ushort)local_24[2] <= (uint *)((int)local_3c << 2)) {
                        puVar12 = (uint *)(uint)(ushort)local_24[2];
                      }
                    }
LAB_008e2e87:
                    local_60[0x18] = (int)puVar12 << 4;
                  }
                }
                else if (iVar4 == 5) {
                  puVar12 = (uint *)puVar18[1];
                  local_14 = puVar12;
                  uVar20 = FUN_008d542d(&local_14);
                  puVar11 = (undefined4 *)((ulonglong)uVar20 >> 0x20);
                  if ((int)uVar20 != 0) {
                    local_14 = puVar12;
                    uVar8 = FUN_008d53ae(&local_14,4);
                    local_60[0xc] = local_60[0xc] | 0x10;
                    local_60[0x17] = *(undefined4 *)CONCAT22(local_10[3],local_10[2]);
                    uVar16 = (uint)(ushort)local_24[2];
                    if (uVar8 < (ushort)local_24[2]) {
                      uVar16 = uVar8;
                    }
                    local_60[0x18] = uVar16 << 4;
                    puVar11 = local_60;
                    puVar14 = local_24;
                  }
                }
              }
            }
LAB_008e2e8d:
            *(undefined2 *)((int)puVar11 + 0x52) = 0x9c;
            puVar11[0x16] = 0xd000000;
            local_14 = (uint *)((uint)*(ushort *)((int)puVar14 + 6) * 0x10);
            puVar11[0x12] = local_14;
            if (puVar14[4] == 0) {
              puVar18 = (undefined4 *)(*piVar15 + (int)local_14);
              for (iVar7 = (uint)(ushort)puVar14[2] << 2; iVar7 != 0; iVar7 = iVar7 + -1) {
                *puVar18 = 0;
                puVar18 = puVar18 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(undefined1 *)puVar18 = 0;
                puVar18 = (undefined4 *)((int)puVar18 + 1);
              }
            }
            else {
              puVar18 = (undefined4 *)(local_54 + puVar14[4]);
              puVar19 = (undefined4 *)(*piVar15 + (int)local_14);
              for (iVar7 = (uint)(ushort)puVar14[2] << 2; iVar7 != 0; iVar7 = iVar7 + -1) {
                *puVar19 = *puVar18;
                puVar18 = puVar18 + 1;
                puVar19 = puVar19 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(undefined1 *)puVar19 = *(undefined1 *)puVar18;
                puVar18 = (undefined4 *)((int)puVar18 + 1);
                puVar19 = (undefined4 *)((int)puVar19 + 1);
              }
            }
            if ((char)piVar15[0xc] != '\0') {
              if (local_88 != (undefined4 *)0x0) {
                local_88[0xc] = local_88[0xc] & 0xfffffffe;
              }
              local_88 = puVar11;
            }
          }
          else if (sVar1 == 3) {
            *(undefined2 *)((int)local_60 + 0x52) = 0xb2;
            local_60[0x16] = 0xf000000;
            uVar3 = *(ushort *)((int)local_24 + 6);
            local_60[0xc] = local_60[0xc] & 0xfffffffd;
            local_60[0x12] = local_6c + uVar3;
            *local_60 = 0;
            if (puVar18 == (undefined4 *)0x0) {
              *(undefined2 *)(*piVar15 + local_60[0x12]) = 0;
              *(undefined2 *)(*piVar15 + 2 + local_60[0x12]) = 0;
            }
            else {
              *(short *)(*piVar15 + local_60[0x12]) = *(short *)(puVar18 + 0x11) + 1;
              *(undefined2 *)(*piVar15 + 2 + local_60[0x12]) = 0;
              uVar3 = *(ushort *)((int)puVar18 + 0x46);
              if (*(ushort *)((int)local_60 + 0x56) < *(ushort *)((int)puVar18 + 0x46)) {
                uVar3 = *(ushort *)((int)local_60 + 0x56);
              }
              *(ushort *)((int)local_60 + 0x56) = uVar3;
            }
            *(undefined2 *)(piVar15[5] + (uint)*(ushort *)(piVar15 + 0xd) * 2 + *piVar15) =
                 local_3c._0_2_;
            *(short *)(piVar15 + 0xd) = (short)piVar15[0xd] + 1;
          }
          local_64 = (uint *)((int)local_64 + 1);
        } while (local_64 < *(uint **)(local_54 + 0xc));
        uVar3 = (ushort)local_40;
      }
      *(ushort *)((int)piVar15 + 0x4e) = uVar3;
      *(short *)(piVar15 + 0x15) = (short)local_50;
      *(short *)((int)piVar15 + 0x5a) = (short)local_58;
      *(undefined2 *)(piVar15 + 0x18) = local_48._0_2_;
      goto LAB_008e310a;
    }
  }
LAB_008e3053:
  local_4c = -0x7ff8fff2;
LAB_008e310a:
  _free(local_70);
  return;
}


// ==== FUN_008e3125 @ 0x008e3125 ====

int FUN_008e3125(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  int in_ECX;
  ushort *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int local_14;
  uint local_c;
  uint local_8;
  
  do {
    if (param_3 <= param_2) {
      return 0;
    }
    puVar2 = (ushort *)(*(int *)(param_2 + 0x48) + *param_1);
    local_c = (uint)*(ushort *)(param_2 + 0x54);
    piVar5 = (int *)(((uint)puVar2[1] + (uint)*puVar2) * 100 + -100 + *(int *)(in_ECX + 0x2c));
    piVar3 = piVar5 + (uint)*(ushort *)(param_2 + 0x56) * 0x19;
    for (; piVar5 < piVar3; piVar5 = piVar5 + 0x19) {
      local_8 = 0;
      piVar4 = (int *)piVar5[1];
      if (*(short *)((int)piVar5 + 0x36) != 0) {
        do {
          if (*(char *)((int)piVar4 + 0x5b) == '\x03') {
            if (*piVar4 != 0) {
              iVar1 = FUN_008dee52(((int)piVar5 - *(int *)(in_ECX + 0x2c)) / 100 & 0xffff,local_8);
              if (iVar1 < 0) {
                return iVar1;
              }
              *piVar4 = piVar4[1];
            }
            local_14 = (**(code **)(**(int **)(in_ECX + 8) + 0x114))
                                 (*(int **)(in_ECX + 8),local_c,piVar4[0x16] & 0xffffff,
                                  *(undefined4 *)(piVar4[0x12] + *piVar5));
          }
          else if (*(char *)((int)piVar4 + 0x5b) == '\t') {
            iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + piVar4[7] * 4) + 0x40);
            if (iVar1 == 0) {
              iVar1 = *(int *)piVar4[2];
            }
            else {
              iVar1 = *(int *)(*(int *)(iVar1 + 8) + *(int *)piVar4[2] * 4);
            }
            local_14 = (**(code **)(**(int **)(in_ECX + 8) + 0x104))
                                 (*(undefined4 *)(in_ECX + 8),local_c,
                                  *(undefined4 *)(*(int *)(in_ECX + 0x18) + 4 + iVar1 * 0x18));
          }
          if (local_14 < 0) {
            return local_14;
          }
          local_8 = local_8 + 1;
          piVar4 = piVar4 + 0x19;
        } while (local_8 < *(ushort *)((int)piVar5 + 0x36));
      }
      local_c = local_c + 1;
    }
    param_2 = param_2 + 100;
  } while( true );
}


// ==== FUN_008e3262 @ 0x008e3262 ====

int FUN_008e3262(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  int local_10;
  int *local_c;
  int *local_8;
  
  piVar7 = (int *)param_1[1];
  iVar1 = param_1[2] << 0x1e;
  if (*piVar7 == 0) {
    iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + piVar7[7] * 4) + 0x40);
    local_10 = in_ECX;
    if (iVar1 < 0) {
      if (iVar2 == 0) {
        iVar2 = *(int *)piVar7[2];
      }
      else {
        iVar2 = *(int *)(*(int *)(iVar2 + 8) + *(int *)piVar7[2] * 4);
      }
      iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x170))
                        (*(undefined4 *)(in_ECX + 8),
                         *(undefined4 *)(*(int *)(in_ECX + 0x18) + 4 + iVar2 * 0x18));
    }
    else {
      if (iVar2 == 0) {
        iVar2 = *(int *)piVar7[2];
      }
      else {
        iVar2 = *(int *)(*(int *)(iVar2 + 8) + *(int *)piVar7[2] * 4);
      }
      iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x1ac))
                        (*(undefined4 *)(in_ECX + 8),
                         *(undefined4 *)(*(int *)(in_ECX + 0x18) + 4 + iVar2 * 0x18));
    }
    if (-1 < iVar2) {
      local_c = piVar7 + 0x19;
      if ((*(byte *)(param_1 + 2) & 4) != 0) {
        iVar2 = FUN_008ddfb8(((int)param_1 - *(int *)(in_ECX + 0x2c)) / 100 & 0xffff,1);
        if (iVar2 < 0) {
          return iVar2;
        }
        if ((*(byte *)(param_1 + 2) & 0x10) != 0) {
          if (((short)param_1[0x14] != 0) &&
             ((short)param_1[0x13] == *(short *)((int)param_1 + 0x4e))) {
            if (iVar1 < 0) {
              (**(code **)(**(int **)(in_ECX + 8) + 0x178))();
            }
            else {
              (**(code **)(**(int **)(in_ECX + 8) + 0x1b4))
                        (*(undefined4 *)(in_ECX + 8),0,param_1[0x10] + *param_1,(short)param_1[0x14]
                        );
            }
          }
          if ((*(short *)((int)param_1 + 0x56) != 0) &&
             (*(short *)((int)param_1 + 0x52) == (short)param_1[0x15])) {
            if (iVar1 < 0) {
              (**(code **)(**(int **)(in_ECX + 8) + 0x180))();
            }
            else {
              (**(code **)(**(int **)(in_ECX + 8) + 0x1bc))
                        (*(undefined4 *)(in_ECX + 8),0,param_1[0x11] + *param_1,
                         *(short *)((int)param_1 + 0x56));
            }
          }
          if (((short)param_1[0x17] != 0) &&
             ((short)param_1[0x16] == *(short *)((int)param_1 + 0x5a))) {
            if (iVar1 < 0) {
              (**(code **)(**(int **)(in_ECX + 8) + 0x188))();
            }
            else {
              (**(code **)(**(int **)(in_ECX + 8) + 0x1c4))
                        (*(undefined4 *)(in_ECX + 8),0,param_1[0x12] + *param_1,(short)param_1[0x17]
                        );
            }
          }
        }
        local_c = piVar7 + 0x32;
      }
      piVar5 = (int *)((uint)*(ushort *)((int)param_1 + 0x4e) * 100 + param_1[1]);
      piVar7 = local_c;
      local_8 = piVar5;
      if (local_c < piVar5) {
        do {
          piVar7 = local_c;
          if (*local_c != 0) {
            *local_c = local_c[1];
            if ((*(byte *)(local_c + 0xc) & 0x10) == 0) {
              FUN_008dc7e1(local_c + 2,(undefined4 *)(local_c[0x12] + *param_1),
                           *(undefined2 *)((int)local_c + 0x56),local_c[0xf],
                           *(undefined4 *)(local_c[0xd] + 0x10),&local_c,
                           *(undefined4 *)
                            (*(int *)(*(int *)(in_ECX + 0xb0) + local_c[7] * 4) + 0x4c));
              piVar5 = local_8;
            }
            else {
              uVar4 = local_c[0x18];
              puVar6 = (undefined4 *)local_c[0x17];
              puVar8 = (undefined4 *)(local_c[0x12] + *param_1);
              for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar8 = *puVar6;
                puVar6 = puVar6 + 1;
                puVar8 = puVar8 + 1;
              }
              for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
                puVar6 = (undefined4 *)((int)puVar6 + 1);
                puVar8 = (undefined4 *)((int)puVar8 + 1);
              }
              in_ECX = local_10;
            }
          }
          piVar7 = piVar7 + 0x19;
          local_c = piVar7;
        } while (piVar7 < piVar5);
        if (iVar1 < 0) {
          iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x178))();
        }
        else {
          iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x1b4))
                            (*(undefined4 *)(in_ECX + 8),0,param_1[0x10] + *param_1,
                             (short)param_1[0x14]);
        }
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      if (*(short *)((int)param_1 + 0x4e) != *(short *)((int)param_1 + 0x36)) {
        piVar5 = (int *)((uint)*(ushort *)(param_1 + 0x15) * 100 + param_1[1]);
        local_8 = piVar5;
        if (piVar7 < piVar5) {
          do {
            if (*piVar7 != 0) {
              *piVar7 = piVar7[1];
              FUN_008dcb9c(piVar7 + 2,piVar7[0x12] + *param_1,*(undefined2 *)((int)piVar7 + 0x56),
                           piVar7[0xf],*(undefined4 *)(piVar7[0xd] + 0x10),&local_10,
                           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0xb0) + piVar7[7] * 4) + 0x4c)
                          );
              piVar5 = local_8;
            }
            piVar7 = piVar7 + 0x19;
          } while (piVar7 < piVar5);
          if (iVar1 < 0) {
            iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x180))();
          }
          else {
            iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x1bc))
                              (*(undefined4 *)(in_ECX + 8),0,param_1[0x11] + *param_1,
                               *(undefined2 *)((int)param_1 + 0x56));
          }
          if (iVar2 < 0) {
            return iVar2;
          }
        }
        piVar5 = (int *)((uint)*(ushort *)((int)param_1 + 0x5a) * 100 + param_1[1]);
        local_8 = piVar5;
        if (piVar7 < piVar5) {
          do {
            if (*piVar7 != 0) {
              *piVar7 = piVar7[1];
              FUN_008dcfa2(piVar7 + 2,piVar7[0x12] + *param_1,*(undefined2 *)((int)piVar7 + 0x56),
                           piVar7[0xf],*(undefined4 *)(piVar7[0xd] + 0x10),&local_10,
                           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0xb0) + piVar7[7] * 4) + 0x4c)
                          );
              piVar5 = local_8;
            }
            piVar7 = piVar7 + 0x19;
          } while (piVar7 < piVar5);
          if (iVar1 < 0) {
            iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x188))();
          }
          else {
            iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x1c4))
                              (*(undefined4 *)(in_ECX + 8),0,param_1[0x12] + *param_1,
                               (short)param_1[0x17]);
          }
          if (iVar1 < 0) {
            return iVar1;
          }
        }
        piVar5 = (int *)((uint)*(ushort *)(param_1 + 0x18) * 100 + param_1[1]);
        if (piVar7 < piVar5) {
          iVar1 = FUN_008e3125(param_1,piVar7,piVar5);
          return iVar1;
        }
      }
      iVar2 = 0;
    }
  }
  else {
    iVar2 = FUN_008e36eb(((int)param_1 - *(int *)(in_ECX + 0x2c)) / 100,0,0xffff);
  }
  return iVar2;
}


// ==== FUN_008e3606 @ 0x008e3606 ====

int FUN_008e3606(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1 & 0xffff;
  iVar4 = uVar3 * 100 + *(int *)(in_ECX + 0x2c);
  if (((*(byte *)(in_ECX + 0x118) & 8) == 0) ||
     ((iVar1 = FUN_008de443(*(short *)(iVar4 + 0x18) != -1,iVar4 + 0x1c), -1 < iVar1 &&
      (iVar1 = FUN_008de5b4(*(short *)(iVar4 + 0x1a) != -1,iVar4 + 0x24), -1 < iVar1)))) {
    if ((*(byte *)(iVar4 + 8) & 8) != 0) {
      if (*(short *)(iVar4 + 0x18) == -1) {
        iVar1 = FUN_008e219d(uVar3);
      }
      else {
        iVar1 = FUN_008e122a(uVar3);
      }
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    if (*(int *)(in_ECX + 0x3c) == 4) {
      if ((*(byte *)(iVar4 + 8) & 1) != 0) {
        iVar4 = FUN_008e3262(iVar4);
        return iVar4;
      }
      iVar1 = 0;
      if (*(short *)(iVar4 + 0x36) != 0) {
        do {
          iVar2 = FUN_008e36eb(param_1,iVar1,param_2);
          if (iVar2 < 0) {
            return iVar2;
          }
          iVar1 = iVar1 + 1;
        } while ((ushort)iVar1 < *(ushort *)(iVar4 + 0x36));
      }
    }
    else {
      iVar1 = 0;
      if (*(short *)(iVar4 + 0x36) != 0) {
        do {
          iVar2 = FUN_008e36eb(param_1,iVar1,param_2);
          if ((iVar2 < 0) && (*(int *)(in_ECX + 0x3c) != 1)) {
            return iVar2;
          }
          iVar1 = iVar1 + 1;
        } while ((ushort)iVar1 < *(ushort *)(iVar4 + 0x36));
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_008e36eb @ 0x008e36eb ====

int FUN_008e36eb(uint param_1,int *param_2,uint param_3)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  ushort *puVar11;
  int *piVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined1 local_19c [61];
  byte local_15f;
  undefined1 local_6c [64];
  int local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  int *local_c;
  int local_8;
  
  local_8 = 0;
  local_10 = param_1 & 0xffff;
  piVar12 = (int *)(local_10 * 100 + *(int *)(in_ECX + 0x2c));
  local_c = (int *)(((uint)param_2 & 0xffff) * 100 + piVar12[1]);
  if ((short)param_3 == -1) {
    param_3 = CONCAT22(param_3._2_2_,(short)local_c[0x15]);
  }
  puVar11 = (ushort *)(local_c[0x12] + *piVar12);
  local_24 = local_c[0x16];
  if (*local_c != 0) {
    uVar7 = local_24 >> 0x18;
    *local_c = local_c[1];
    if (0xd < uVar7) {
      if (uVar7 < 0xe) {
LAB_008e3ca9:
        local_8 = FUN_008dee52(local_10,(uint)param_2 & 0xffff);
      }
      else {
        if (uVar7 < 0x10) {
          if (local_c[0xe] != 0) {
            local_8 = FUN_008dde39(local_10,(uint)param_2 & 0xffff);
            if (local_8 < 0) {
              return local_8;
            }
            (**(code **)(*(int *)local_c[0xe] + 0xc))((int *)local_c[0xe]);
            param_2 = (int *)__ftol();
            if (puVar11[1] != (ushort)param_2) {
              uVar7 = (uint)param_2 & 0xffff;
              if (*(uint *)(local_c[3] + 0x10) <= uVar7) {
                return -0x7fffbffb;
              }
              if (*(short *)(in_ECX + 0x42) == *(short *)(in_ECX + 0x40)) {
                iVar4 = -(uint)*(ushort *)((int)local_c + 0x56);
              }
              else {
                iVar4 = 0;
              }
              local_8 = FUN_008d51ba((puVar11[1] - 1) + (uint)*puVar11,
                                     CONCAT22(*(short *)((int)local_c + 0x56) >> 0xf,
                                              -*(short *)((int)local_c + 0x56)),iVar4);
              if (local_8 < 0) {
                return local_8;
              }
              puVar11[1] = (ushort)param_2;
              if (*(short *)(in_ECX + 0x42) == *(short *)(in_ECX + 0x40)) {
                uVar1 = *(undefined2 *)((int)local_c + 0x56);
              }
              else {
                uVar1 = 0;
              }
              local_8 = FUN_008d51ba((*puVar11 - 1) + uVar7,(int)*(short *)((int)local_c + 0x56),
                                     uVar1);
              goto LAB_008e3cb8;
            }
            if ((*(byte *)(in_ECX + 0x118) & 4) != 0) {
              return local_8;
            }
          }
          goto LAB_008e3cc3;
        }
        if ((uVar7 != 0x10) && (uVar7 != 0x11)) goto LAB_008e3ca9;
        local_8 = FUN_008ddfb8(local_10,(uint)param_2 & 0xffff);
      }
LAB_008e3cb8:
      if (local_8 < 0) {
        return local_8;
      }
      goto LAB_008e3cc3;
    }
    if (0xb < uVar7) {
      param_1 = 0xffffffff;
      local_2c = 0;
      local_28 = 0;
      if (local_c[0xe] == 0) {
        if (local_c[0xf] != 0) {
          local_28 = *(undefined4 *)(local_c[0xd] + 0x10);
          param_1 = *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0xb0) + local_c[7] * 4) + 0x4c);
          local_2c = local_c[0xf];
        }
      }
      else {
        local_8 = FUN_008dde39(local_10,(uint)param_2 & 0xffff);
        if (local_8 < 0) {
          return local_8;
        }
        local_8 = FUN_008dae25(local_10,(uint)param_2 & 0xffff);
        if (local_8 < 0) {
          return local_8;
        }
      }
      if (local_24 == 0xc000000) {
LAB_008e3b65:
        FUN_008dc7e1(local_c + 2,puVar11,*(undefined2 *)((int)local_c + 0x56),local_2c,local_28,
                     &param_2,param_1);
      }
      else if (local_24 == 0xc010000) {
LAB_008e3b42:
        FUN_008dcfa2(local_c + 2,puVar11,*(undefined2 *)((int)local_c + 0x56),local_2c,local_28,
                     &param_2,param_1);
      }
      else {
        if (local_24 != 0xc020000) {
          if (local_24 == 0xd000000) goto LAB_008e3b65;
          if (local_24 == 0xd010000) goto LAB_008e3b42;
          if (local_24 != 0xd020000) goto LAB_008e3cc3;
        }
        FUN_008dcb9c(local_c + 2,puVar11,*(undefined2 *)((int)local_c + 0x56),local_2c,local_28,
                     &param_2,param_1);
      }
      goto LAB_008e3cc3;
    }
    if (uVar7 == 3) {
      local_8 = FUN_008dee52(local_10,(uint)param_2 & 0xffff);
      if (local_8 < 0) {
        return local_8;
      }
      if ((*(int *)(in_ECX + 0x3c) == 4) && ((short)param_3 == -1)) {
        iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) +
                                 (uint)*(ushort *)((int)piVar12 + 0x3e) * 4) + 0x34);
        if (iVar4 == 0) {
          return local_8;
        }
        iVar4 = *(int *)(iVar4 + 0x18);
        do {
          iVar4 = *(int *)(iVar4 + 0x1c);
          piVar2 = (int *)((uint)*(ushort *)(iVar4 + 0x14) * 100 + *(int *)(in_ECX + 0x2c));
          iVar8 = (uint)*(ushort *)(iVar4 + 0x16) * 100 + piVar2[1];
          puVar9 = (ushort *)(*(int *)(iVar8 + 0x48) + *piVar2);
          if ((short)piVar2[0xf] != 0) {
            param_3 = (uint)puVar9[1];
            param_2 = (int *)(uint)*puVar9;
            if ((((int)(((int)param_2 - 1U) + param_3) <= (int)local_10) &&
                ((int)local_10 <
                 (int)((uint)*(ushort *)(iVar8 + 0x56) + (int)param_2 + -1 + param_3))) &&
               (local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x114))
                                    (*(undefined4 *)(in_ECX + 8),
                                     (((uint)*(ushort *)(iVar8 + 0x54) - (int)param_2) - param_3) +
                                     1 + local_10,local_24 & 0xffffff,*(undefined4 *)puVar11),
               local_8 < 0)) {
              return local_8;
            }
          }
          if (*(int *)(iVar4 + 0x1c) ==
              *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + (uint)*(ushort *)((int)piVar12 + 0x3e) * 4
                               ) + 0x34)) {
            return local_8;
          }
        } while( true );
      }
      goto LAB_008e3cc3;
    }
    if (uVar7 == 9) {
      if ((*(int *)(in_ECX + 0x3c) == 4) && ((short)param_3 == -1)) {
        iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) +
                                 (uint)*(ushort *)((int)piVar12 + 0x3e) * 4) + 0x34);
        if (iVar4 == 0) {
          return 0;
        }
        iVar4 = *(int *)(iVar4 + 0x18);
        do {
          iVar4 = *(int *)(iVar4 + 0x1c);
          piVar2 = (int *)((uint)*(ushort *)(iVar4 + 0x14) * 100 + *(int *)(in_ECX + 0x2c));
          iVar8 = (uint)*(ushort *)(iVar4 + 0x16) * 100 + piVar2[1];
          puVar11 = (ushort *)(*(int *)(iVar8 + 0x48) + *piVar2);
          if ((short)piVar2[0xf] != 0) {
            param_3 = (uint)puVar11[1];
            param_2 = (int *)(uint)*puVar11;
            if (((int)(((int)param_2 - 1U) + param_3) <= (int)local_10) &&
               ((int)local_10 < (int)((uint)*(ushort *)(iVar8 + 0x56) + (int)param_2 + -1 + param_3)
               )) {
              iVar10 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + local_c[7] * 4) + 0x40);
              iVar3 = *(int *)local_c[2];
              if (iVar10 != 0) {
                iVar3 = *(int *)(*(int *)(iVar10 + 8) + iVar3 * 4);
              }
              local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x104))
                                  (*(undefined4 *)(in_ECX + 8),
                                   (((uint)*(ushort *)(iVar8 + 0x54) - (int)param_2) - param_3) + 1
                                   + local_10,
                                   *(undefined4 *)(*(int *)(in_ECX + 0x18) + 4 + iVar3 * 0x18));
              if (local_8 < 0) {
                return local_8;
              }
            }
          }
          if (*(int *)(iVar4 + 0x1c) ==
              *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + (uint)*(ushort *)((int)piVar12 + 0x3e) * 4
                               ) + 0x34)) {
            return local_8;
          }
        } while( true );
      }
      goto LAB_008e3cc3;
    }
    if (uVar7 != 10) {
      if (uVar7 != 0xb) goto LAB_008e3ca9;
      iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + local_c[7] * 4) + 0x40);
      iVar8 = *(int *)local_c[2];
      if (iVar4 != 0) {
        iVar8 = *(int *)(*(int *)(iVar4 + 8) + iVar8 * 4);
      }
      if (*(int *)(*(int *)(in_ECX + 0x18) + 4 + iVar8 * 0x18) != 0) {
        local_8 = FUN_008d51ba(local_10,0xffffffff,
                               (*(short *)(in_ECX + 0x42) != *(short *)(in_ECX + 0x40)) - 1);
        if (local_8 < 0) {
          return local_8;
        }
        local_8 = FUN_008e219d(local_10);
        goto LAB_008e37d6;
      }
      goto LAB_008e3cc3;
    }
    iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + local_c[7] * 4) + 0x40);
    iVar8 = *(int *)local_c[2];
    if (iVar4 != 0) {
      iVar8 = *(int *)(*(int *)(iVar4 + 8) + iVar8 * 4);
    }
    if (*(int *)(*(int *)(in_ECX + 0x18) + 4 + iVar8 * 0x18) == 0) goto LAB_008e3cc3;
    local_8 = FUN_008d51ba(local_10,0xffffffff,
                           (*(short *)(in_ECX + 0x42) != *(short *)(in_ECX + 0x40)) - 1);
    if (local_8 < 0) {
      return local_8;
    }
    local_8 = FUN_008e122a(local_10);
LAB_008e37d6:
    if (local_8 < 0) {
      return local_8;
    }
    local_8 = FUN_008d51ba(local_10,1,*(short *)(in_ECX + 0x42) == *(short *)(in_ECX + 0x40));
    if (local_8 < 0) {
      return local_8;
    }
    uVar7 = 0xffff;
LAB_008e380f:
    local_8 = FUN_008e3606(param_1,uVar7);
    goto switchD_008e3cd5_default;
  }
LAB_008e3cc3:
  switch(local_24 >> 0x18) {
  case 1:
    local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0xe4))
                        (*(int **)(in_ECX + 8),local_24 & 0xffffff,*(undefined4 *)puVar11);
    break;
  case 2:
    local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x10c))
                        (*(int **)(in_ECX + 8),param_3 & 0xffff,local_24 & 0xffffff,
                         *(undefined4 *)puVar11);
    break;
  case 3:
    if (*(int *)(in_ECX + 0x3c) == 1) {
      return local_8;
    }
    local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x114))
                        (*(int **)(in_ECX + 8),param_3 & 0xffff,local_24 & 0xffffff,
                         *(undefined4 *)puVar11);
    break;
  case 4:
    local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x13c))
                        (*(int **)(in_ECX + 8),*(undefined4 *)puVar11);
    break;
  case 5:
    if (*(int *)(in_ECX + 0x3c) == 1) {
      uVar6 = 2;
    }
    else {
      uVar6 = *(undefined4 *)puVar11;
    }
    local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x164))(*(int **)(in_ECX + 8),uVar6);
    break;
  case 6:
    thunk_FUN_0079f0cc(local_6c,puVar11);
    if (local_24 == 0x6000000) {
      iVar4 = 3;
    }
    else if (local_24 == 0x6000001) {
      iVar4 = 2;
    }
    else if (local_24 == 0x6000002) {
      iVar4 = (param_3 & 0xffff) + 0x100;
    }
    else {
      if (local_24 != 0x6000003) {
        return local_8;
      }
      iVar4 = (param_3 & 0xffff) + 0x10;
    }
    local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0xb0))(*(int **)(in_ECX + 8),iVar4,local_6c);
    break;
  case 7:
    puVar5 = (undefined4 *)
             ((uint)*(ushort *)(in_ECX + 0x42) * 0xb4 + 0x44 + *(int *)(in_ECX + 0xa4));
    if (local_24 == 0x7000000) {
      puVar13 = puVar5;
LAB_008e3e18:
      local_20 = *(undefined4 *)puVar11;
      local_1c = *(undefined4 *)(puVar11 + 2);
      local_18 = *(undefined4 *)(puVar11 + 4);
      local_14 = *(undefined4 *)(puVar11 + 6);
      *puVar13 = local_20;
      puVar13[1] = local_1c;
      puVar13[2] = local_18;
      puVar13[3] = local_14;
    }
    else {
      if (local_24 == 0x7000001) {
        puVar13 = puVar5 + 4;
        goto LAB_008e3e18;
      }
      if (local_24 == 0x7000002) {
        puVar13 = puVar5 + 8;
        goto LAB_008e3e18;
      }
      if (local_24 == 0x7000003) {
        puVar13 = puVar5 + 0xc;
        goto LAB_008e3e18;
      }
      if (local_24 == 0x7000004) {
        puVar5[0x10] = *(undefined4 *)puVar11;
      }
    }
    if (((*(byte *)(local_c + 0xc) & 1) == 0) && ((*(byte *)(in_ECX + 0x118) & 4) == 0)) {
      return local_8;
    }
    local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0xc4))(*(int **)(in_ECX + 8),puVar5);
    break;
  case 8:
    if (local_24 == 0x800000d) {
      local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0xd4))
                          (*(int **)(in_ECX + 8),param_3 & 0xffff,*(undefined4 *)puVar11);
      break;
    }
    puVar5 = (undefined4 *)
             ((uint)*(ushort *)(local_c + 0x13) * 0x68 +
             *(int *)((uint)*(ushort *)(in_ECX + 0x42) * 0xb4 + 0x40 + *(int *)(in_ECX + 0xa4)));
    switch(local_24) {
    case 0x8000000:
      *puVar5 = *(undefined4 *)puVar11;
      break;
    case 0x8000001:
      puVar14 = puVar5 + 1;
      goto LAB_008e3ea7;
    case 0x8000002:
      puVar14 = puVar5 + 5;
      goto LAB_008e3ea7;
    case 0x8000003:
      puVar14 = puVar5 + 9;
LAB_008e3ea7:
      local_20 = *(undefined4 *)puVar11;
      local_1c = *(undefined4 *)(puVar11 + 2);
      local_18 = *(undefined4 *)(puVar11 + 4);
      local_14 = *(undefined4 *)(puVar11 + 6);
      puVar13 = puVar14 + 1;
      *puVar14 = local_20;
LAB_008e3eea:
      *puVar13 = local_1c;
      puVar13[1] = local_18;
      puVar13[2] = local_14;
      break;
    case 0x8000004:
      puVar13 = puVar5 + 0xd;
      goto LAB_008e3ed6;
    case 0x8000005:
      puVar13 = puVar5 + 0x10;
LAB_008e3ed6:
      local_1c = *(undefined4 *)puVar11;
      local_18 = *(undefined4 *)(puVar11 + 2);
      local_14 = *(undefined4 *)(puVar11 + 4);
      goto LAB_008e3eea;
    case 0x8000006:
      puVar5[0x13] = *(undefined4 *)puVar11;
      break;
    case 0x8000007:
      puVar5[0x14] = *(undefined4 *)puVar11;
      break;
    case 0x8000008:
      puVar5[0x15] = *(undefined4 *)puVar11;
      break;
    case 0x8000009:
      puVar5[0x16] = *(undefined4 *)puVar11;
      break;
    case 0x800000a:
      puVar5[0x17] = *(undefined4 *)puVar11;
      break;
    case 0x800000b:
      puVar5[0x18] = *(undefined4 *)puVar11;
      break;
    case 0x800000c:
      puVar5[0x19] = *(undefined4 *)puVar11;
    }
    if (((*(byte *)(local_c + 0xc) & 1) == 0) && ((*(byte *)(in_ECX + 0x118) & 4) == 0)) {
      return local_8;
    }
    if (*(int *)(in_ECX + 0x3c) == 1) {
      local_1c = 0;
      *puVar5 = 3;
      local_18 = 0;
      local_14 = 0x3f800000;
      puVar5[0x10] = 0;
      puVar5[0x11] = 0;
      puVar5[0x12] = 0x3f800000;
    }
    local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0xcc))
                        (*(int **)(in_ECX + 8),param_3 & 0xffff,puVar5);
    break;
  case 9:
    if (*(int *)(in_ECX + 0x3c) == 2) {
      local_8 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))(*(int **)(in_ECX + 0xc),local_19c);
      if (local_8 < 0) {
        return local_8;
      }
      if (*(int *)local_c[3] == 8) {
        local_15f = local_15f & 0x20;
      }
      else {
        if (*(int *)local_c[3] != 9) goto LAB_008e3fd2;
        local_15f = local_15f & 8;
      }
      if (local_15f == 0) {
        return -0x7fffbffb;
      }
    }
LAB_008e3fd2:
    iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + local_c[7] * 4) + 0x40);
    iVar8 = *(int *)local_c[2];
    if (iVar4 != 0) {
      iVar8 = *(int *)(*(int *)(iVar4 + 8) + iVar8 * 4);
    }
    local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x104))
                        (*(int **)(in_ECX + 8),param_3 & 0xffff,
                         *(undefined4 *)(*(int *)(in_ECX + 0x18) + 4 + iVar8 * 0x18));
    break;
  case 10:
    if (*(int *)(in_ECX + 0x3c) == 1) {
      return local_8;
    }
    if (*(int *)(in_ECX + 0x3c) == 2) {
      iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + local_c[7] * 4) + 0x40);
      iVar8 = *(int *)local_c[2];
      if (iVar4 == 0) {
        iVar10 = iVar8;
      }
      else {
        iVar10 = *(int *)(*(int *)(iVar4 + 8) + iVar8 * 4);
      }
      iVar3 = *(int *)(in_ECX + 0x18);
      if ((*(byte *)(iVar3 + 0x14 + iVar10 * 0x18) & 2) == 0) {
        return -0x7fffbffb;
      }
      if (iVar4 == 0) {
        iVar10 = iVar8;
      }
      else {
        iVar10 = *(int *)(*(int *)(iVar4 + 8) + iVar8 * 4);
      }
      if (*(int *)(iVar3 + 4 + iVar10 * 0x18) == 0) {
LAB_008e40a7:
        uVar6 = 0;
      }
      else {
        if (iVar4 == 0) {
          iVar10 = iVar8;
        }
        else {
          iVar10 = *(int *)(*(int *)(iVar4 + 8) + iVar8 * 4);
        }
        if (*(int *)(iVar3 + 8 + iVar10 * 0x18) == 0) goto LAB_008e40a7;
        if (iVar4 != 0) {
          iVar8 = *(int *)(*(int *)(iVar4 + 8) + iVar8 * 4);
        }
        piVar12 = *(int **)(*(int *)(in_ECX + 0x18) + 8 + iVar8 * 0x18);
        uVar6 = (**(code **)(*piVar12 + 0xc))(piVar12);
      }
      local_8 = FUN_008d52a6(uVar6);
      if (local_8 < 0) {
        return local_8;
      }
    }
    iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + local_c[7] * 4) + 0x40);
    if (iVar4 == 0) {
      iVar4 = *(int *)local_c[2];
    }
    else {
      iVar4 = *(int *)(*(int *)(iVar4 + 8) + *(int *)local_c[2] * 4);
    }
    local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x170))
                        (*(int **)(in_ECX + 8),
                         *(undefined4 *)(*(int *)(in_ECX + 0x18) + 4 + iVar4 * 0x18));
    break;
  case 0xb:
    if (*(int *)(in_ECX + 0x3c) == 1) {
      return local_8;
    }
    if (*(int *)(in_ECX + 0x3c) == 2) {
      iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + local_c[7] * 4) + 0x40);
      if (iVar4 == 0) {
        iVar4 = *(int *)local_c[2];
      }
      else {
        iVar4 = *(int *)(*(int *)(iVar4 + 8) + *(int *)local_c[2] * 4);
      }
      if ((*(byte *)(*(int *)(in_ECX + 0x18) + 0x14 + iVar4 * 0x18) & 2) == 0) {
        return -0x7fffbffb;
      }
    }
    iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + local_c[7] * 4) + 0x40);
    iVar8 = *(int *)local_c[2];
    if (iVar4 != 0) {
      iVar8 = *(int *)(*(int *)(iVar4 + 8) + iVar8 * 4);
    }
    local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x1ac))
                        (*(int **)(in_ECX + 8),
                         *(undefined4 *)(*(int *)(in_ECX + 0x18) + 4 + iVar8 * 0x18));
    break;
  case 0xc:
    if (*(int *)(in_ECX + 0x3c) == 1) {
      return local_8;
    }
    iVar4 = *(int *)(in_ECX + 0x118) << 0x1d;
    if ((-1 < iVar4) && ((*(byte *)(local_c + 0xc) & 1) == 0)) {
      return local_8;
    }
    if (local_24 == 0xc000000) {
      if ((((char)piVar12[0xb] == '\0') || (iVar4 < 0)) || ((*(byte *)(local_c + 0xc) & 1) == 0)) {
        uVar1 = *(undefined2 *)((int)local_c + 0x56);
        uVar7 = param_3 & 0xffff;
      }
      else {
        uVar1 = (undefined2)piVar12[7];
        puVar11 = puVar11 + (uint)*(ushort *)(local_c + 0x15) * -8;
        uVar7 = 0;
      }
      local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x178))
                          (*(int **)(in_ECX + 8),uVar7,puVar11,uVar1);
    }
    else if (local_24 == 0xc010000) {
      if (((*(char *)((int)piVar12 + 0x2d) == '\0') || (iVar4 < 0)) ||
         ((*(byte *)(local_c + 0xc) & 1) == 0)) {
        uVar1 = *(undefined2 *)((int)local_c + 0x56);
        uVar7 = param_3 & 0xffff;
      }
      else {
        uVar1 = *(undefined2 *)((int)piVar12 + 0x1e);
        puVar11 = puVar11 + (uint)*(ushort *)(local_c + 0x15) * -2;
        uVar7 = 0;
      }
      local_8 = FUN_008d4df2(*(undefined4 *)(in_ECX + 8),uVar7,puVar11,uVar1);
    }
    else {
      if (local_24 != 0xc020000) {
        return local_8;
      }
      if (((*(char *)((int)piVar12 + 0x2e) == '\0') || (iVar4 < 0)) ||
         ((*(byte *)(local_c + 0xc) & 1) == 0)) {
        uVar1 = *(undefined2 *)((int)local_c + 0x56);
        uVar7 = param_3 & 0xffff;
      }
      else {
        uVar1 = (undefined2)piVar12[8];
        puVar11 = puVar11 + (uint)*(ushort *)(local_c + 0x15) * -8;
        uVar7 = 0;
      }
      local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x180))
                          (*(int **)(in_ECX + 8),uVar7,puVar11,uVar1);
    }
    break;
  case 0xd:
    if (*(int *)(in_ECX + 0x3c) == 1) {
      return local_8;
    }
    iVar4 = *(int *)(in_ECX + 0x118) << 0x1d;
    if ((-1 < iVar4) && ((*(byte *)(local_c + 0xc) & 1) == 0)) {
      return local_8;
    }
    if (local_24 == 0xd000000) {
      if ((((char)piVar12[0xc] == '\0') || (iVar4 < 0)) || ((*(byte *)(local_c + 0xc) & 1) == 0)) {
        uVar1 = *(undefined2 *)((int)local_c + 0x56);
        uVar7 = param_3 & 0xffff;
      }
      else {
        uVar1 = (undefined2)piVar12[9];
        puVar11 = puVar11 + (uint)*(ushort *)(local_c + 0x15) * -8;
        uVar7 = 0;
      }
      local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x1b4))
                          (*(int **)(in_ECX + 8),uVar7,puVar11,uVar1);
    }
    else if (local_24 == 0xd010000) {
      if (((*(char *)((int)piVar12 + 0x31) == '\0') || (iVar4 < 0)) ||
         ((*(byte *)(local_c + 0xc) & 1) == 0)) {
        uVar1 = *(undefined2 *)((int)local_c + 0x56);
        uVar7 = param_3 & 0xffff;
      }
      else {
        uVar1 = *(undefined2 *)((int)piVar12 + 0x26);
        puVar11 = puVar11 + (uint)*(ushort *)(local_c + 0x15) * -2;
        uVar7 = 0;
      }
      local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x1c4))
                          (*(int **)(in_ECX + 8),uVar7,puVar11,uVar1);
    }
    else {
      if (local_24 != 0xd020000) {
        return local_8;
      }
      if (((*(char *)((int)piVar12 + 0x32) == '\0') || (iVar4 < 0)) ||
         ((*(byte *)(local_c + 0xc) & 1) == 0)) {
        uVar1 = *(undefined2 *)((int)local_c + 0x56);
        uVar7 = param_3 & 0xffff;
      }
      else {
        uVar1 = (undefined2)piVar12[10];
        puVar11 = puVar11 + (uint)*(ushort *)(local_c + 0x15) * -8;
        uVar7 = 0;
      }
      local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x1bc))
                          (*(int **)(in_ECX + 8),uVar7,puVar11,uVar1);
    }
    break;
  case 0xe:
    if (*puVar11 == 0) {
      return local_8;
    }
    if (*(int *)(in_ECX + 0x3c) != 4) {
      iVar4 = FUN_008e3606((ushort)(puVar11[1] + *puVar11) - 1,0xffff);
      return iVar4;
    }
    iVar4 = (puVar11[1] - 1) + (uint)*puVar11;
    iVar8 = iVar4 * 100 + *(int *)(in_ECX + 0x2c);
    if ((*(byte *)(iVar8 + 8) & 1) == 0) {
      FUN_008e3606(iVar4,0xffff);
      return local_8;
    }
    FUN_008e3262(iVar8);
    return local_8;
  case 0xf:
    if (*puVar11 == 0) {
      return local_8;
    }
    if (*(int *)(in_ECX + 0x3c) == 4) {
      local_8 = FUN_008e3125(piVar12,local_c,local_c + 0x19);
      break;
    }
    param_1 = (ushort)(puVar11[1] + *puVar11) - 1;
    uVar7 = param_3;
    goto LAB_008e380f;
  case 0x10:
    iVar4 = (**(code **)(*(int *)local_c[0xe] + 0xc))((int *)local_c[0xe]);
    if (*(int *)(iVar4 + 0x4c) != 0) {
      iVar8 = *(int *)(iVar4 + 0x28);
      iVar10 = *piVar12;
      param_2 = (int *)(*(int *)(iVar4 + 0x5c) + iVar4);
      param_3 = *param_2;
      param_2 = param_2 + 1;
      if (param_3 != 0) {
        do {
          local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x178))
                              (*(undefined4 *)(in_ECX + 8),*param_2,*param_2 * 0x10 + iVar8 + iVar10
                               ,param_2[1]);
          param_2 = param_2 + 2;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
    if (*(int *)(iVar4 + 0x50) != 0) {
      iVar8 = *(int *)(iVar4 + 0x2c);
      iVar10 = *piVar12;
      param_2 = (int *)(*(int *)(iVar4 + 0x60) + iVar4);
      param_3 = *param_2;
      param_2 = param_2 + 1;
      if (param_3 != 0) {
        do {
          local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x188))
                              (*(undefined4 *)(in_ECX + 8),*param_2,iVar8 + iVar10 + *param_2 * 4,
                               param_2[1]);
          param_2 = param_2 + 2;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
    if (*(int *)(iVar4 + 0x54) == 0) {
      return local_8;
    }
    param_3 = *(int *)(iVar4 + 0x30) + *piVar12;
    piVar12 = (int *)(*(int *)(iVar4 + 100) + iVar4);
    param_2 = (int *)*piVar12;
    piVar12 = piVar12 + 1;
    if (param_2 == (int *)0x0) {
      return local_8;
    }
    do {
      local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x1bc))
                          (*(int **)(in_ECX + 8),*piVar12,*piVar12 * 0x10 + param_3,piVar12[1]);
      piVar12 = piVar12 + 2;
      param_2 = (int *)((int)param_2 + -1);
    } while (param_2 != (int *)0x0);
    return local_8;
  case 0x11:
    iVar4 = (**(code **)(*(int *)local_c[0xe] + 0xc))((int *)local_c[0xe]);
    if (*(int *)(iVar4 + 0x4c) != 0) {
      iVar8 = *(int *)(iVar4 + 0x28);
      iVar10 = *piVar12;
      param_2 = (int *)(*(int *)(iVar4 + 0x5c) + iVar4);
      param_3 = *param_2;
      param_2 = param_2 + 1;
      if (param_3 != 0) {
        do {
          local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x1b4))
                              (*(undefined4 *)(in_ECX + 8),*param_2,*param_2 * 0x10 + iVar8 + iVar10
                               ,param_2[1]);
          param_2 = param_2 + 2;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
    if (*(int *)(iVar4 + 0x50) != 0) {
      iVar8 = *(int *)(iVar4 + 0x2c);
      iVar10 = *piVar12;
      param_2 = (int *)(*(int *)(iVar4 + 0x60) + iVar4);
      param_3 = *param_2;
      param_2 = param_2 + 1;
      if (param_3 != 0) {
        do {
          local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x1c4))
                              (*(undefined4 *)(in_ECX + 8),*param_2,iVar8 + iVar10 + *param_2 * 4,
                               param_2[1]);
          param_2 = param_2 + 2;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
    if (*(int *)(iVar4 + 0x54) != 0) {
      param_3 = *(int *)(iVar4 + 0x30) + *piVar12;
      piVar12 = (int *)(*(int *)(iVar4 + 100) + iVar4);
      param_2 = (int *)*piVar12;
      piVar12 = piVar12 + 1;
      if (param_2 != (int *)0x0) {
        do {
          local_8 = (**(code **)(**(int **)(in_ECX + 8) + 0x1bc))
                              (*(int **)(in_ECX + 8),*piVar12,*piVar12 * 0x10 + param_3,piVar12[1]);
          piVar12 = piVar12 + 2;
          param_2 = (int *)((int)param_2 + -1);
        } while (param_2 != (int *)0x0);
      }
    }
  }
switchD_008e3cd5_default:
  return local_8;
}


// ==== FUN_008e46dd @ 0x008e46dd ====

undefined4 FUN_008e46dd(int *param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int in_ECX;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  puVar5 = param_2;
  bVar4 = false;
  uVar9 = param_2[0x16];
  puVar6 = (undefined4 *)(param_2[0x12] + *param_1);
  *param_2 = param_2[1];
  uVar8 = uVar9 >> 0x18;
  if (uVar8 == 0xc) {
    bVar4 = true;
  }
  else if (uVar8 != 0xd) {
    if (uVar8 == 0xf) {
      puVar10 = param_2 + 0x19;
      param_2 = puVar6;
      uVar7 = FUN_008e3125(param_1,puVar5,puVar10);
      return uVar7;
    }
    return 0x80004005;
  }
  param_1 = *(int **)(param_2[0xd] + 0x10);
  uVar7 = *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0xb0) + param_2[7] * 4) + 0x4c);
  if (uVar9 == 0xc000000) {
LAB_008e481a:
    if ((*(byte *)(param_2 + 0xc) & 0x10) == 0) {
      puVar1 = (undefined2 *)((int)param_2 + 0x56);
      puVar10 = param_2 + 0xf;
      puVar11 = param_2 + 2;
      param_2 = puVar6;
      FUN_008dc7e1(puVar11,puVar6,*puVar1,*puVar10,param_1,&param_1,uVar7);
      uVar9 = (uint)param_1;
    }
    else {
      uVar9 = param_2[0x18];
      puVar10 = (undefined4 *)param_2[0x17];
      puVar11 = puVar6;
      for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      uVar9 = (uint)*(ushort *)((int)param_2 + 0x56);
      param_2 = puVar6;
    }
    piVar3 = *(int **)(in_ECX + 8);
    if (bVar4) {
      uVar7 = (**(code **)(*piVar3 + 0x178))(piVar3,*(undefined2 *)(puVar5 + 0x15),param_2,uVar9);
    }
    else {
      uVar7 = (**(code **)(*piVar3 + 0x1b4))
                        (piVar3,*(undefined2 *)(puVar5 + 0x15),param_2,
                         *(undefined2 *)((int)puVar5 + 0x56));
    }
  }
  else {
    if (uVar9 == 0xc010000) {
LAB_008e47d5:
      puVar1 = (undefined2 *)((int)param_2 + 0x56);
      puVar10 = param_2 + 0xf;
      puVar11 = param_2 + 2;
      param_2 = puVar6;
      FUN_008dcfa2(puVar11,puVar6,*puVar1,*puVar10,param_1,&param_1,uVar7);
      iVar2 = **(int **)(in_ECX + 8);
      if (bVar4) {
        uVar7 = (**(code **)(iVar2 + 0x188))();
        return uVar7;
      }
      uVar7 = (**(code **)(iVar2 + 0x1c4))
                        (*(int **)(in_ECX + 8),*(undefined2 *)(puVar5 + 0x15),param_2,
                         *(undefined2 *)((int)puVar5 + 0x56));
      return uVar7;
    }
    if (uVar9 != 0xc020000) {
      if (uVar9 == 0xd000000) goto LAB_008e481a;
      if (uVar9 == 0xd010000) goto LAB_008e47d5;
      if (uVar9 != 0xd020000) {
        return 0x80004005;
      }
    }
    puVar1 = (undefined2 *)((int)param_2 + 0x56);
    puVar10 = param_2 + 0xf;
    puVar11 = param_2 + 2;
    param_2 = puVar6;
    FUN_008dcb9c(puVar11,puVar6,*puVar1,*puVar10,param_1,&param_1,uVar7);
    iVar2 = **(int **)(in_ECX + 8);
    if (bVar4) {
      uVar7 = (**(code **)(iVar2 + 0x180))();
    }
    else {
      uVar7 = (**(code **)(iVar2 + 0x1bc))
                        (*(int **)(in_ECX + 8),*(undefined2 *)(puVar5 + 0x15),param_2,
                         *(undefined2 *)((int)puVar5 + 0x56));
    }
  }
  return uVar7;
}


// ==== FUN_008e4897 @ 0x008e4897 ====

void FUN_008e4897(void)

{
  undefined4 *in_ECX;
  
  if ((void *)*in_ECX != (void *)0x0) {
    _free((void *)*in_ECX);
    return;
  }
  if (in_ECX[1] != 0) {
    FUN_008df396(3);
    in_ECX[1] = 0;
  }
  return;
}


// ==== FUN_008e48c0 @ 0x008e48c0 ====

void FUN_008e48c0(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  int local_8;
  
  if (*(int *)(in_ECX + 0x30) != 0) {
    FUN_008df375(1);
    *(undefined4 *)(in_ECX + 0x30) = 0;
  }
  if (*(int *)(in_ECX + 0x38) != 0) {
    FUN_008df483(3);
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  if (*(void **)(in_ECX + 0x40) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x40));
    return;
  }
  piVar2 = *(int **)(in_ECX + 0x88);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(int *)(in_ECX + 0x88) = 0;
  }
  piVar2 = (int *)(in_ECX + 0x8c);
  local_8 = 2;
  do {
    piVar1 = (int *)piVar2[2];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      piVar2[2] = 0;
    }
    piVar1 = (int *)*piVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  FUN_008de297();
  return;
}


// ==== FUN_008e4953 @ 0x008e4953 ====

void FUN_008e4953(byte param_1)

{
  void *in_ECX;
  
  if ((param_1 & 2) == 0) {
    FUN_008e4897();
    if ((param_1 & 1) != 0) {
      _free(in_ECX);
      return;
    }
  }
  else {
    FUN_0049b480(in_ECX,100,*(undefined4 *)((int)in_ECX + -4),FUN_008e4897);
    if ((param_1 & 1) != 0) {
      _free((undefined4 *)((int)in_ECX + -4));
      return;
    }
  }
  return;
}


// ==== FUN_008e49a1 @ 0x008e49a1 ====

void FUN_008e49a1(byte param_1)

{
  void *in_ECX;
  
  if ((param_1 & 2) == 0) {
    FUN_008e48c0();
    if ((param_1 & 1) != 0) {
      _free(in_ECX);
      return;
    }
  }
  else {
    FUN_0049b480(in_ECX,0xb4,*(undefined4 *)((int)in_ECX + -4),FUN_008e48c0);
    if ((param_1 & 1) != 0) {
      _free((undefined4 *)((int)in_ECX + -4));
      return;
    }
  }
  return;
}


// ==== FUN_008e49f2 @ 0x008e49f2 ====

int FUN_008e49f2(int param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  int local_c;
  int local_8;
  
  puVar2 = param_3;
  iVar5 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 4;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if ((param_2 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *puVar2 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(iVar4 + *puVar2 * 4);
  }
  *puVar2 = *puVar2 + 1;
  if ((param_2 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *puVar2 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(iVar5 + 0x30) = *(undefined4 *)(iVar4 + *puVar2 * 4);
  }
  *puVar2 = *puVar2 + 1;
  if ((param_2 == (int *)0x0) || (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), uVar3 < *puVar2))
  {
    return -0x7fffbffb;
  }
  param_2 = (int *)0x0;
  *(int *)(in_ECX + 0xa8) = *(int *)(in_ECX + 0xa8) + 1;
  param_1 = *(int *)(in_ECX + 0x20);
  local_c = *(int *)(iVar5 + 0x2c);
  if ((uint)(*(int *)(in_ECX + 0x1c) + param_1) < (uint)(param_1 + 0x14 + local_c)) {
    return 0;
  }
  uVar3 = *(uint *)(param_1 + 4 + local_c);
  uVar1 = *(uint *)(param_1 + 0x10 + local_c);
  if (uVar3 < 2) {
    uVar3 = 1;
    if (1 < uVar1) {
      uVar3 = uVar1;
    }
    *(int *)(in_ECX + 0x128) = *(int *)(in_ECX + 0x128) + uVar3 * 0x10;
    return 0;
  }
  if (uVar3 < 4) {
    uVar3 = 1;
    if (1 < uVar1) {
      uVar3 = uVar1;
    }
    *(int *)(in_ECX + 0x124) = *(int *)(in_ECX + 0x124) + uVar3 * 0x40;
    return 0;
  }
  if (uVar3 != 5) {
    return 0;
  }
  local_8 = *(int *)(iVar5 + 0x30);
  param_3 = (uint *)(local_c + param_1);
  param_1 = param_1 + local_8;
  param_2 = (int *)FUN_008df8be(&param_3,&param_1,0);
  if ((int)param_2 < 0) {
    return (int)param_2;
  }
  iVar5 = FUN_008d62ad(*(undefined4 *)(in_ECX + 0x20),&local_c,&local_8);
  *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + iVar5;
  return (int)param_2;
}


// ==== FUN_008e4b2d @ 0x008e4b2d ====

int FUN_008e4b2d(uint param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  int local_10;
  int local_8;
  
  puVar2 = param_3;
  uVar1 = param_1;
  if ((param_2 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(iVar4 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(iVar4 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
    param_1 = *(uint *)(iVar4 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 == (int *)0x0) || (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), uVar3 < *param_3)
     ) {
    return -0x7fffbffb;
  }
  iVar4 = FUN_008d5ff3(*(undefined4 *)(uVar1 + 0x28));
  if (iVar4 < 0) {
    return iVar4;
  }
  local_10 = 0;
  param_3 = (uint *)0x0;
  if (*(int *)(uVar1 + 0x2c) != 0) {
    do {
      pvVar5 = operator_new(0x50);
      if (pvVar5 == (void *)0x0) {
        local_8 = 0;
      }
      else {
        local_8 = FUN_008df302();
      }
      if (local_8 == 0) {
        return -0x7ff8fff2;
      }
      iVar4 = FUN_008e49f2(local_8,param_2,puVar2);
      if (iVar4 < 0) goto LAB_008e4c99;
      if (local_10 == 0) {
        *(int *)(uVar1 + 0x30) = local_8;
      }
      else {
        *(int *)(local_10 + 0x3c) = local_8;
      }
      param_3 = (uint *)((int)param_3 + 1);
      local_10 = local_8;
    } while (param_3 < *(uint *)(uVar1 + 0x2c));
  }
  local_8 = 0;
  iVar4 = FUN_008df3e4(param_1);
  if (iVar4 < 0) {
    return iVar4;
  }
  param_3 = (uint *)0x0;
  if (param_1 == 0) {
    return iVar4;
  }
  do {
    iVar4 = FUN_008dba54(*(undefined2 *)(uVar1 + 0x34),param_3,param_2,puVar2);
    if (iVar4 < 0) {
      return iVar4;
    }
    param_3 = (uint *)((int)param_3 + 1);
  } while (((uint)param_3 & 0xffff) < param_1);
LAB_008e4c99:
  param_2 = (int *)iVar4;
  if (local_8 == 0) {
    return (int)param_2;
  }
  FUN_008df375(1);
  return (int)param_2;
}


// ==== FUN_008e4cba @ 0x008e4cba ====

uint FUN_008e4cba(uint param_1,char *param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int in_ECX;
  int iVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  
LAB_008e4e38:
  if (param_1 == 0) {
    if ((param_2 == (char *)0x0) || (uVar5 = FUN_008e606c(param_2,param_3 + 1,0), uVar5 == 0)) {
LAB_008e4de1:
      uVar5 = 0;
    }
    else {
LAB_008e4e59:
      uVar5 = ~uVar5;
    }
    return uVar5;
  }
  uVar10 = 0;
  uVar5 = FUN_008e606c(param_1,param_3 + 1,0);
  if (uVar5 != 0) {
    if (param_2 != (char *)0x0) {
      iVar3 = *(int *)(uVar5 + 4);
      if (((*(int *)(iVar3 + 4) == 5) &&
          ((*(int *)(uVar5 + 8) != -1 || (*(int *)(iVar3 + 0x10) == 0)))) &&
         ((uVar4 = *(uint *)(iVar3 + 0x14), *(int *)(uVar5 + 0x20) != 0 ||
          (iVar3 = FUN_008dc045(uVar5,uVar4), -1 < iVar3)))) {
        param_1 = 0;
        do {
          if (uVar4 <= uVar10) break;
          iVar3 = *(int *)(*(int *)(uVar5 + 0x20) + 4 + param_1);
          iVar8 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(uVar5 + 0x14) * 4) + 0x40);
          if (iVar8 == 0) {
            iVar6 = *(int *)(in_ECX + 0x20);
          }
          else {
            iVar6 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
          }
          iVar1 = *(int *)(iVar3 + 8);
          if (*(int *)(iVar1 + iVar6) == 0) {
            pcVar7 = (char *)0x0;
          }
          else {
            if (iVar8 == 0) {
              iVar8 = *(int *)(in_ECX + 0x20);
            }
            else {
              iVar8 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
            }
            pcVar7 = (char *)(iVar1 + 4 + iVar8);
          }
          cVar2 = *param_2;
          pcVar9 = param_2;
          while ((cVar2 == *pcVar7 && (cVar2 != '\0'))) {
            pcVar9 = pcVar9 + 1;
            pcVar7 = pcVar7 + 1;
            cVar2 = *pcVar9;
          }
          cVar2 = *pcVar9;
          if (cVar2 == *pcVar7) {
            uVar5 = *(int *)(uVar5 + 0x20) + uVar10 * 0x28;
            goto LAB_008e4e59;
          }
          if (*pcVar7 == '\0') {
            if (cVar2 == '.') {
              param_1 = ~(*(int *)(uVar5 + 0x20) + uVar10 * 0x28);
              goto LAB_008e4e31;
            }
            if (cVar2 == '@') {
              uVar5 = FUN_008dfe48(~(*(int *)(uVar5 + 0x20) + uVar10 * 0x28),pcVar9 + 1,param_3);
              return uVar5;
            }
            if (cVar2 == '[') goto LAB_008e4dc7;
          }
          uVar10 = uVar10 + 1;
          param_1 = param_1 + 0x28;
        } while( true );
      }
      goto LAB_008e4de1;
    }
    goto LAB_008e4e59;
  }
  goto LAB_008e4de1;
LAB_008e4dc7:
  pcVar9 = pcVar9 + 1;
  if (((*pcVar9 < '0') || ('9' < *pcVar9)) ||
     (uVar4 = _atol(pcVar9), *(uint *)(iVar3 + 0x10) <= uVar4)) goto LAB_008e4de1;
  for (; ('/' < *pcVar9 && (*pcVar9 < ':')); pcVar9 = pcVar9 + 1) {
  }
  if (*pcVar9 != ']') goto LAB_008e4de1;
  pcVar9 = pcVar9 + 1;
  param_1 = FUN_008d64b8(~(*(int *)(uVar5 + 0x20) + uVar10 * 0x28),uVar4,param_3);
  if (param_1 == 0) goto LAB_008e4de1;
  if (*pcVar9 == '\0') {
    return param_1;
  }
  if (*pcVar9 != '.') goto LAB_008e4de1;
LAB_008e4e31:
  param_2 = pcVar9 + 1;
  goto LAB_008e4e38;
}


// ==== FUN_008e4e8a @ 0x008e4e8a ====

undefined4 FUN_008e4e8a(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_008dfe48(param_2,param_3,0);
  }
  return uVar1;
}


// ==== FUN_008e4ead @ 0x008e4ead ====

int FUN_008e4ead(int param_1,int param_2)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int *piVar6;
  uint uVar7;
  int in_ECX;
  ushort *puVar8;
  int *piVar9;
  uint uVar10;
  uint local_c;
  int local_8;
  
  local_8 = 0;
  piVar9 = (int *)(param_1 * 100 + *(int *)(in_ECX + 0x2c));
  if (((((*(ushort *)(piVar9 + 6) == 0xffff) ||
        (piVar6 = (int *)((uint)*(ushort *)(piVar9 + 6) * 100 + piVar9[1]), *piVar6 == 0)) ||
       (piVar6[0x16] != 0xa000000)) ||
      (((local_8 = FUN_008d51ba(param_1,-(uint)(param_2 != 0),0xffffffff), -1 < local_8 &&
        (local_8 = FUN_008e122a(param_1), -1 < local_8)) &&
       (local_8 = FUN_008d51ba(param_1,param_2 != 0,1), -1 < local_8)))) &&
     (((*(ushort *)((int)piVar9 + 0x1a) == 0xffff ||
       (piVar6 = (int *)((uint)*(ushort *)((int)piVar9 + 0x1a) * 100 + piVar9[1]), *piVar6 == 0)) ||
      ((piVar6[0x16] != 0xb000000 ||
       (((local_8 = FUN_008d51ba(param_1,-(uint)(param_2 != 0),0xffffffff), -1 < local_8 &&
         (local_8 = FUN_008e219d(param_1), -1 < local_8)) &&
        (local_8 = FUN_008d51ba(param_1,param_2 != 0,1), -1 < local_8)))))))) {
    iVar3 = piVar9[5];
    iVar4 = *piVar9;
    uVar2 = 0;
    if ((short)piVar9[0xd] != 0) {
      do {
        puVar1 = (ushort *)(iVar3 + iVar4 + (uint)uVar2 * 2);
        piVar6 = (int *)((uint)*puVar1 * 100 + piVar9[1]);
        puVar8 = (ushort *)(piVar6[0x12] + *piVar9);
        if (*puVar8 != 0) {
          local_c = *(uint *)(piVar6[3] + 0x10);
          if (local_c == 0) {
            local_c = 1;
          }
          if (*piVar6 != 0) {
            *piVar6 = piVar6[1];
            local_8 = FUN_008dde39(param_1,*puVar1);
            if (local_8 < 0) {
              return local_8;
            }
            (**(code **)(*(int *)piVar6[0xe] + 0xc))((int *)piVar6[0xe]);
            uVar5 = __ftol();
            if (puVar8[1] != uVar5) {
              if (local_c <= uVar5) {
                return -0x7fffbffb;
              }
              puVar8[1] = uVar5;
            }
          }
          uVar7 = 0;
          uVar10 = 0;
          if (local_c != 0) {
            do {
              local_8 = FUN_008e4ead((*puVar8 - 1) + uVar7,param_2);
              if (local_8 < 0) {
                return local_8;
              }
              uVar10 = uVar10 + 1;
              uVar7 = uVar10 & 0xffff;
            } while (uVar7 < local_c);
          }
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(ushort *)(piVar9 + 0xd));
    }
  }
  return local_8;
}


// ==== FUN_008e5095 @ 0x008e5095 ====

undefined4 FUN_008e5095(int param_1)

{
  ushort *puVar1;
  undefined2 *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  *(uint *)(param_1 + 0x118) = *(uint *)(param_1 + 0x118) | 4;
  uVar5 = 0;
  if (*(int *)(param_1 + 0x10c) != 0) {
    do {
      puVar1 = (ushort *)(*(int *)(param_1 + 0x108) + uVar5 * 4);
      iVar4 = (uint)*puVar1 * 100 + *(int *)(param_1 + 0x2c);
      piVar3 = (int *)((uint)puVar1[1] * 100 + *(int *)(iVar4 + 4));
      piVar3[0xc] = piVar3[0xc] & 0xfffffffd;
      if ((*(short *)(iVar4 + 0x3c) != 0) && (*piVar3 != 0)) {
        if ((piVar3[0xc] & 8U) == 0) {
          puVar2 = (undefined2 *)(*(int *)(param_1 + 0x108) + uVar5 * 4);
          FUN_008e36eb(*puVar2,puVar2[1],0xffff);
        }
        else {
          FUN_008e46dd(iVar4,piVar3);
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0x10c));
  }
  if ((*(byte *)(param_1 + 0x118) & 1) != 0) {
    __controlfp(*(uint *)(param_1 + 0x114),0x30000);
    *(uint *)(param_1 + 0x118) = *(uint *)(param_1 + 0x118) & 0xfffffffe;
  }
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(uint *)(param_1 + 0x118) = *(uint *)(param_1 + 0x118) & 0xfffffffb;
  return 0;
}


// ==== FUN_008e5150 @ 0x008e5150 ====

int FUN_008e5150(int param_1,uint param_2)

{
  uint *puVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_1;
  if (*(int *)(param_1 + 0x3c) == 0) {
    param_1 = -0x7789f794;
    iVar4 = param_1;
    goto LAB_008e5241;
  }
  iVar5 = (uint)*(ushort *)(param_1 + 0x42) * 0xb4 + *(int *)(param_1 + 0xa4);
  if (param_2 < *(uint *)(iVar5 + 0x34)) {
    uVar2 = *(ushort *)(param_1 + 0x44);
    if ((ushort)param_2 != uVar2) {
      if ((uVar2 != 0xffff) &&
         (iVar4 = FUN_008d51ba(*(undefined2 *)((uint)uVar2 * 0x38 + 0x34 + *(int *)(iVar5 + 0x38)),
                               0xffffffff,
                               (*(ushort *)(param_1 + 0x40) != *(ushort *)(param_1 + 0x42)) - 1),
         iVar4 < 0)) goto LAB_008e5241;
      *(ushort *)(param_1 + 0x44) = (ushort)param_2;
      iVar4 = FUN_008d51ba(*(undefined2 *)
                            ((param_2 & 0xffff) * 0x38 + 0x34 + *(int *)(iVar5 + 0x38)),1,
                           *(short *)(param_1 + 0x40) == *(short *)(param_1 + 0x42));
      if (iVar4 < 0) goto LAB_008e5241;
    }
    iVar4 = *(int *)(iVar5 + 0x38);
    *(byte *)(param_1 + 0x118) = *(byte *)(param_1 + 0x118) & 0x7f;
    if ((*(uint *)(param_1 + 0x118) & 0x100) == 0) {
      iVar4 = FUN_008e3606(*(undefined2 *)(param_2 * 0x38 + iVar4 + 0x34),0xffff);
      if (-1 < iVar4) {
        *(uint *)(param_1 + 0x118) = *(uint *)(param_1 + 0x118) | 0x100;
      }
      goto LAB_008e5241;
    }
  }
  param_1 = -0x7789f794;
  iVar4 = param_1;
LAB_008e5241:
  param_1 = iVar4;
  puVar1 = (uint *)(iVar3 + 0x118);
  if ((*(byte *)puVar1 & 1) != 0) {
    __controlfp(*(uint *)(iVar3 + 0x114),0x30000);
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  return param_1;
}


// ==== FUN_008e526a @ 0x008e526a ====

void FUN_008e526a(void)

{
  undefined4 *in_ECX;
  uint uVar1;
  
  *in_ECX = &PTR_FUN_00a23090;
  if (in_ECX[0x37] != 0) {
    FUN_008d5a3d(1);
    in_ECX[0x37] = 0;
  }
  if ((in_ECX[0x36] != 0) && (uVar1 = 0, in_ECX[0x34] != 0)) {
    do {
      if (*(int *)(in_ECX[0x36] + uVar1 * 4) != 0) {
        FUN_008df5d1(1);
        *(undefined4 *)(in_ECX[0x36] + uVar1 * 4) = 0;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)in_ECX[0x34]);
  }
  FUN_008d5b85();
  _free((void *)in_ECX[0x2f]);
  return;
}


// ==== FUN_008e5443 @ 0x008e5443 ====

void FUN_008e5443(byte param_1)

{
  void *in_ECX;
  
  FUN_008e526a();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008e5464 @ 0x008e5464 ====

/* WARNING: Removing unreachable block (ram,0x008e56ac) */
/* WARNING: Removing unreachable block (ram,0x008e5656) */
/* WARNING: Removing unreachable block (ram,0x008e573f) */
/* WARNING: Removing unreachable block (ram,0x008e575c) */
/* WARNING: Removing unreachable block (ram,0x008e5768) */
/* WARNING: Removing unreachable block (ram,0x008e576a) */
/* WARNING: Removing unreachable block (ram,0x008e576f) */
/* WARNING: Removing unreachable block (ram,0x008e5771) */
/* WARNING: Removing unreachable block (ram,0x008e56d6) */
/* WARNING: Removing unreachable block (ram,0x008e56fe) */
/* WARNING: Removing unreachable block (ram,0x008e5702) */
/* WARNING: Removing unreachable block (ram,0x008e5709) */
/* WARNING: Removing unreachable block (ram,0x008e570b) */
/* WARNING: Removing unreachable block (ram,0x008e5711) */
/* WARNING: Removing unreachable block (ram,0x008e5730) */
/* WARNING: Removing unreachable block (ram,0x008e5732) */
/* WARNING: Removing unreachable block (ram,0x008e573b) */
/* WARNING: Removing unreachable block (ram,0x008e573d) */
/* WARNING: Removing unreachable block (ram,0x008e5637) */
/* WARNING: Removing unreachable block (ram,0x008e563c) */
/* WARNING: Removing unreachable block (ram,0x008e563e) */
/* WARNING: Removing unreachable block (ram,0x008e568b) */
/* WARNING: Removing unreachable block (ram,0x008e5692) */
/* WARNING: Removing unreachable block (ram,0x008e5694) */

void FUN_008e5464(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_1c;
  uint local_18;
  
  *(byte *)(in_ECX + 0x119) = *(byte *)(in_ECX + 0x119) | 8;
  pvVar1 = operator_new(*(int *)(in_ECX + 0xa0) * *(int *)(in_ECX + 0xac) * 4);
  *(void **)(in_ECX + 0xb4) = pvVar1;
  pvVar1 = operator_new(*(int *)(in_ECX + 0xa0) * *(int *)(in_ECX + 0xac) * 4);
  *(void **)(in_ECX + 0xc0) = pvVar1;
  puVar2 = operator_new(*(uint *)(in_ECX + 0xac));
  *(undefined4 **)(in_ECX + 0xbc) = puVar2;
  if (((*(int *)(in_ECX + 0xb4) != 0) && (*(int *)(in_ECX + 0xc0) != 0)) &&
     (puVar2 != (undefined4 *)0x0)) {
    uVar5 = *(uint *)(in_ECX + 0xac);
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar2 = 0;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
    *(undefined2 *)(in_ECX + 0x40) = 0;
    if (*(int *)(in_ECX + 0xa0) != 0) {
      do {
        iVar3 = *(int *)(in_ECX + 0xac) * (uint)*(ushort *)(in_ECX + 0x40) * 4;
        *(int *)(in_ECX + 0xb8) = *(int *)(in_ECX + 0xb4) + iVar3;
        iVar7 = *(int *)(in_ECX + 0xc0);
        local_18 = 0;
        if (*(int *)((uint)*(ushort *)(in_ECX + 0x40) * 0xb4 + 0x34 + *(int *)(in_ECX + 0xa4)) != 0)
        {
          local_1c = 0;
          do {
            iVar8 = *(int *)((uint)*(ushort *)(in_ECX + 0x40) * 0xb4 + 0x38 +
                            *(int *)(in_ECX + 0xa4)) + local_1c;
            FUN_008d51ba(*(undefined2 *)(iVar8 + 0x34),0,1);
            FUN_008e4ead(*(undefined2 *)(iVar8 + 0x34),0);
            local_18 = local_18 + 1;
            local_1c = local_1c + 0x38;
          } while (local_18 <
                   *(uint *)((uint)*(ushort *)(in_ECX + 0x40) * 0xb4 + 0x34 +
                            *(int *)(in_ECX + 0xa4)));
        }
        local_18 = 0;
        if (*(int *)(in_ECX + 0xac) != 0) {
          do {
            iVar8 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + local_18 * 4) + 0x34);
            if (iVar8 != 0) {
              iVar8 = *(int *)(iVar8 + 0x18);
              do {
                iVar8 = *(int *)(iVar8 + 0x1c);
                iVar6 = (uint)*(ushort *)(iVar8 + 0x14) * 100 + *(int *)(in_ECX + 0x2c);
                if (*(short *)(iVar6 + 0x3a) != 0) {
                  if ((*(byte *)(iVar6 + 8) & 8) == 0) {
                    pvVar1 = operator_new(4);
                    if (pvVar1 != (void *)0x0) {
                      _free((void *)0x0);
                      return;
                    }
                  }
                  else {
                    pvVar1 = operator_new(4);
                    if (pvVar1 != (void *)0x0) {
                      _free((void *)0x0);
                      return;
                    }
                  }
                  iVar7 = 0;
                  uVar5 = 0;
                  if (*(int *)((uint)*(ushort *)(in_ECX + 0x40) * 0xb4 + 0x34 +
                              *(int *)(in_ECX + 0xa4)) != 0) {
                    do {
                      FUN_008d51ba(*(undefined2 *)
                                    (*(int *)((uint)*(ushort *)(in_ECX + 0x40) * 0xb4 + 0x38 +
                                             *(int *)(in_ECX + 0xa4)) + 0x34 + iVar7),0,0xffffffff);
                      uVar5 = uVar5 + 1;
                      iVar7 = iVar7 + 0x38;
                    } while (uVar5 < *(uint *)((uint)*(ushort *)(in_ECX + 0x40) * 0xb4 + 0x34 +
                                              *(int *)(in_ECX + 0xa4)));
                  }
                  goto LAB_008e586e;
                }
              } while (*(int *)(iVar8 + 0x1c) !=
                       *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + local_18 * 4) + 0x34));
            }
            *(undefined4 *)(*(int *)(in_ECX + 0xb8) + local_18 * 4) = 0;
            *(undefined4 *)(iVar7 + iVar3 + local_18 * 4) = 0;
            local_18 = local_18 + 1;
          } while (local_18 < *(uint *)(in_ECX + 0xac));
        }
        iVar7 = 0;
        uVar5 = 0;
        if (*(int *)((uint)*(ushort *)(in_ECX + 0x40) * 0xb4 + 0x34 + *(int *)(in_ECX + 0xa4)) != 0)
        {
          do {
            FUN_008d51ba(*(undefined2 *)
                          (*(int *)((uint)*(ushort *)(in_ECX + 0x40) * 0xb4 + 0x38 +
                                   *(int *)(in_ECX + 0xa4)) + 0x34 + iVar7),0,0xffffffff);
            uVar5 = uVar5 + 1;
            iVar7 = iVar7 + 0x38;
          } while (uVar5 < *(uint *)((uint)*(ushort *)(in_ECX + 0x40) * 0xb4 + 0x34 +
                                    *(int *)(in_ECX + 0xa4)));
        }
        *(short *)(in_ECX + 0x40) = *(short *)(in_ECX + 0x40) + 1;
      } while ((uint)*(ushort *)(in_ECX + 0x40) < *(uint *)(in_ECX + 0xa0));
    }
LAB_008e586e:
    *(undefined2 *)(in_ECX + 0x40) = 0xffff;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_008e589e @ 0x008e589e ====

int FUN_008e589e(int param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  void *pvVar9;
  int iVar10;
  int local_c;
  int local_8;
  
  puVar5 = param_3;
  piVar2 = param_2;
  iVar10 = param_1;
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  if ((param_2 != (int *)0x0) &&
     (uVar7 = (**(code **)(*param_2 + 0x10))(param_2), *puVar5 + 1 <= uVar7)) {
    iVar8 = (**(code **)(*piVar2 + 0xc))(piVar2);
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(iVar8 + *puVar5 * 4);
  }
  *puVar5 = *puVar5 + 1;
  if ((piVar2 != (int *)0x0) &&
     (uVar7 = (**(code **)(*piVar2 + 0x10))(piVar2), *puVar5 + 1 <= uVar7)) {
    iVar8 = (**(code **)(*piVar2 + 0xc))(piVar2);
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar8 + *puVar5 * 4);
  }
  *puVar5 = *puVar5 + 1;
  if ((piVar2 != (int *)0x0) &&
     (uVar7 = (**(code **)(*piVar2 + 0x10))(piVar2), *puVar5 + 1 <= uVar7)) {
    iVar8 = (**(code **)(*piVar2 + 0xc))(piVar2);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(iVar8 + *puVar5 * 4);
  }
  *puVar5 = *puVar5 + 1;
  if ((piVar2 != (int *)0x0) &&
     (uVar7 = (**(code **)(*piVar2 + 0x10))(piVar2), *puVar5 + 1 <= uVar7)) {
    iVar8 = (**(code **)(*piVar2 + 0xc))(piVar2);
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(iVar8 + *puVar5 * 4);
  }
  *puVar5 = *puVar5 + 1;
  if ((piVar2 == (int *)0x0) || (uVar7 = (**(code **)(*piVar2 + 0x10))(piVar2), uVar7 < *puVar5)) {
    return -0x7fffbffb;
  }
  piVar1 = (int *)(param_1 + 0x38);
  param_1 = 0;
  param_3 = (uint *)iVar10;
  param_2 = (int *)0x0;
  if (*piVar1 != 0) {
    do {
      pvVar9 = operator_new(0x50);
      if (pvVar9 == (void *)0x0) {
        local_8 = 0;
      }
      else {
        local_8 = FUN_008df302();
      }
      if (local_8 == 0) {
        return -0x7ff8fff2;
      }
      param_1 = FUN_008e49f2(local_8,piVar2,puVar5);
      iVar8 = local_8;
      if (param_1 < 0) goto LAB_008e5a73;
      local_8 = 0;
      param_2 = (int *)((int)param_2 + 1);
      *(int *)((int)param_3 + 0x3c) = iVar8;
      param_3 = (uint *)iVar8;
    } while (param_2 < *(uint *)(iVar10 + 0x38));
  }
  iVar6 = local_c;
  *(int *)(local_c + 0xa8) = *(int *)(local_c + 0xa8) + 1;
  iVar8 = *(int *)(local_c + 0x20);
  iVar3 = *(int *)(iVar10 + 0x2c);
  if ((uint)(*(int *)(local_c + 0x1c) + iVar8) < (uint)(iVar8 + 0x14 + iVar3)) {
    return param_1;
  }
  uVar7 = *(uint *)(iVar8 + 4 + iVar3);
  uVar4 = *(uint *)(iVar8 + 0x10 + iVar3);
  if (1 < uVar7) {
    if (uVar7 < 4) {
      uVar7 = 1;
      if (1 < uVar4) {
        uVar7 = uVar4;
      }
      *(int *)(local_c + 0x124) = *(int *)(local_c + 0x124) + uVar7 * 0x40;
      return param_1;
    }
    if (uVar7 != 5) {
      return param_1;
    }
    local_c = *(int *)(iVar10 + 0x30);
    param_3 = (uint *)(iVar3 + iVar8);
    param_2 = (int *)(iVar8 + local_c);
    local_8 = iVar3;
    iVar10 = FUN_008df8be(&param_3,&param_2,0);
    if (iVar10 < 0) {
      return iVar10;
    }
    iVar8 = FUN_008d62ad(*(undefined4 *)(iVar6 + 0x20),&local_8,&local_c);
    piVar2 = (int *)(iVar6 + 300);
    *piVar2 = *piVar2 + iVar8;
    return iVar10;
  }
  uVar7 = 1;
  if (1 < uVar4) {
    uVar7 = uVar4;
  }
  *(int *)(local_c + 0x128) = *(int *)(local_c + 0x128) + uVar7 * 0x10;
LAB_008e5a73:
  if (local_8 == 0) {
    return param_1;
  }
  FUN_008df375(1);
  return param_1;
}


// ==== FUN_008e5a8b @ 0x008e5a8b ====

int FUN_008e5a8b(int param_1,int *param_2,uint *param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  int *piVar8;
  int iVar9;
  int extraout_EAX;
  int extraout_EAX_00;
  ushort uVar10;
  int in_ECX;
  ushort *puVar11;
  uint uVar12;
  undefined4 *puVar13;
  uint local_18;
  uint local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  
  puVar4 = param_3;
  iVar3 = param_1;
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  if ((param_2 != (int *)0x0) &&
     (uVar5 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar5)) {
    iVar6 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(iVar6 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 != (int *)0x0) &&
     (uVar5 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar5)) {
    iVar6 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(iVar6 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 != (int *)0x0) &&
     (uVar5 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar5)) {
    iVar6 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(iVar6 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 == (int *)0x0) || (uVar5 = (**(code **)(*param_2 + 0x10))(param_2), uVar5 < *param_3)
     ) {
    return -0x7fffbffb;
  }
  iVar6 = FUN_008d5ff3(*(undefined4 *)(param_1 + 0x28));
  if (iVar6 < 0) {
    return iVar6;
  }
  local_14 = 0;
  param_3 = (uint *)0x0;
  if (*(int *)(param_1 + 0x2c) != 0) {
    do {
      pvVar7 = operator_new(0x50);
      if (pvVar7 == (void *)0x0) {
        local_8 = 0;
      }
      else {
        local_8 = FUN_008df302();
      }
      if (local_8 == 0) {
        return -0x7ff8fff2;
      }
      iVar6 = FUN_008e49f2(local_8,param_2,puVar4);
      if (iVar6 < 0) goto LAB_008e6036;
      if (local_14 == 0) {
        *(int *)(param_1 + 0x30) = local_8;
      }
      else {
        *(int *)(local_14 + 0x3c) = local_8;
      }
      param_3 = (uint *)((int)param_3 + 1);
      local_14 = local_8;
    } while (param_3 < *(uint *)(param_1 + 0x2c));
  }
  param_1 = iVar6;
  local_8 = 0;
  iVar6 = *(int *)(iVar3 + 0x34);
  if (iVar6 != 0) {
    piVar8 = operator_new(iVar6 * 0x38 + 4);
    if (piVar8 == (int *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      *piVar8 = iVar6;
      piVar8 = piVar8 + 1;
      FUN_0040d030(piVar8,0x38,iVar6,&LAB_008de355);
    }
    *(int **)(iVar3 + 0x38) = piVar8;
    if (piVar8 == (int *)0x0) {
      return -0x7ff8fff2;
    }
  }
  uVar10 = 0;
  if (*(int *)(iVar3 + 0x34) != 0) {
    do {
      if (*(uint *)(in_ECX + 0x34) <= (uint)*(ushort *)(in_ECX + 0x30)) {
        return -0x7fffbffb;
      }
      iVar6 = (uint)uVar10 * 0x38;
      *(ushort *)(iVar6 + 0x34 + *(int *)(iVar3 + 0x38)) = *(ushort *)(in_ECX + 0x30);
      *(short *)(in_ECX + 0x30) = *(short *)(in_ECX + 0x30) + 1;
      *(undefined2 *)(iVar6 + 0x14 + *(int *)(iVar3 + 0x38)) = *(undefined2 *)(iVar3 + 0x14);
      *(ushort *)(iVar6 + 0x18 + *(int *)(iVar3 + 0x38)) = uVar10;
      param_1 = FUN_008e4b2d(*(int *)(iVar3 + 0x38) + iVar6,param_2,puVar4);
      if (param_1 < 0) {
        return param_1;
      }
      uVar10 = uVar10 + 1;
    } while ((uint)uVar10 < *(uint *)(iVar3 + 0x34));
  }
  uVar5 = 0;
  param_2 = (int *)0x0;
  param_3 = (uint *)0x0;
  if (*(int *)(iVar3 + 0x34) != 0) {
    do {
      iVar6 = (uint)*(ushort *)(uVar5 * 0x38 + *(int *)(iVar3 + 0x38) + 0x34) * 100;
      if (*(short *)(*(int *)(in_ECX + 0x2c) + 0x36 + iVar6) != 0) {
        local_14 = (uint)*(ushort *)(iVar6 + 0x36 + *(int *)(in_ECX + 0x2c));
        puVar11 = (ushort *)(*(int *)(*(int *)(in_ECX + 0x2c) + 4 + iVar6) + 0x54);
        do {
          if (((*(uint *)(&DAT_00a218ec + (uint)puVar11[-1] * 0x1c) & 0xff000000) == 0x8000000) &&
             (param_2 < (uint)*puVar11)) {
            param_2 = (int *)(uint)*puVar11;
          }
          puVar11 = puVar11 + 0x32;
          local_14 = local_14 - 1;
        } while (local_14 != 0);
      }
      param_3 = (uint *)((int)param_3 + 1);
      uVar5 = (uint)param_3 & 0xffff;
    } while (uVar5 < *(uint *)(iVar3 + 0x34));
  }
  uVar5 = (int)param_2 * 2 + 2;
  local_c = operator_new(uVar5);
  if (local_c == (undefined4 *)0x0) {
LAB_008e5df1:
    param_1 = -0x7ff8fff2;
  }
  else {
    puVar13 = local_c;
    for (uVar12 = uVar5 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
      *puVar13 = 0;
      puVar13 = puVar13 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar13 = 0;
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    *(undefined2 *)(iVar3 + 0x3c) = 0;
    param_3 = (uint *)0x0;
    if (*(int *)(iVar3 + 0x34) != 0) {
      uVar5 = 0;
      do {
        iVar6 = uVar5 * 0x38 + *(int *)(iVar3 + 0x38);
        iVar9 = (uint)*(ushort *)(iVar6 + 0x34) * 100;
        local_14 = 0;
        if (*(short *)(iVar9 + 0x36 + *(int *)(in_ECX + 0x2c)) != 0) {
          param_2 = (int *)0x0;
          do {
            iVar9 = *(int *)(iVar9 + 4 + *(int *)(in_ECX + 0x2c)) + (int)param_2;
            if (((*(uint *)(&DAT_00a218ec + (uint)*(ushort *)(iVar9 + 0x52) * 0x1c) & 0xff000000) ==
                 0x8000000) && (*(short *)((int)local_c + (uint)*(ushort *)(iVar9 + 0x54) * 2) == 0)
               ) {
              *(short *)(iVar3 + 0x3c) = *(short *)(iVar3 + 0x3c) + 1;
              *(undefined2 *)((int)local_c + (uint)*(ushort *)(iVar9 + 0x54) * 2) =
                   *(undefined2 *)(iVar3 + 0x3c);
            }
            iVar9 = (uint)*(ushort *)(iVar6 + 0x34) * 100;
            local_14 = local_14 + 1;
            param_2 = (int *)((int)param_2 + 100);
          } while (local_14 < *(ushort *)(iVar9 + 0x36 + *(int *)(in_ECX + 0x2c)));
        }
        param_3 = (uint *)((int)param_3 + 1);
        uVar5 = (uint)param_3 & 0xffff;
      } while (uVar5 < *(uint *)(iVar3 + 0x34));
    }
    if (*(ushort *)(iVar3 + 0x3c) != 0) {
      pvVar7 = operator_new((uint)*(ushort *)(iVar3 + 0x3c) * 0x68);
      *(void **)(iVar3 + 0x40) = pvVar7;
      local_10 = operator_new((uint)*(ushort *)(iVar3 + 0x3c) << 2);
      if ((*(int *)(iVar3 + 0x40) == 0) || (local_10 == (undefined4 *)0x0)) goto LAB_008e5df1;
    }
    param_3 = (uint *)0x0;
    *(undefined4 *)(iVar3 + 0xa4) = 0;
    *(undefined4 *)(iVar3 + 0xa8) = 0;
    *(undefined4 *)(iVar3 + 0xac) = 0;
    *(undefined4 *)(iVar3 + 0xb0) = 0;
    if (*(int *)(iVar3 + 0x34) != 0) {
      uVar5 = 0;
      do {
        iVar6 = (uint)*(ushort *)(uVar5 * 0x38 + 0x34 + *(int *)(iVar3 + 0x38)) * 100 +
                *(int *)(in_ECX + 0x2c);
        bVar1 = false;
        puVar13 = local_10;
        for (uVar5 = (uint)*(ushort *)(iVar3 + 0x3c); uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar13 = 0;
          puVar13 = puVar13 + 1;
        }
        for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined1 *)puVar13 = 0;
          puVar13 = (undefined4 *)((int)puVar13 + 1);
        }
        uVar10 = *(ushort *)(iVar6 + 0x36);
        if (uVar10 != 0) {
          local_18 = (uint)uVar10;
          param_2 = (int *)(local_18 * 100);
          do {
            param_2 = (int *)((int)param_2 + -100);
            iVar9 = *(int *)(iVar6 + 4) + (int)param_2;
            uVar5 = *(uint *)(&DAT_00a218ec + (uint)*(ushort *)(iVar9 + 0x52) * 0x1c);
            uVar12 = uVar5 >> 0x18;
            if (uVar12 == 3) goto LAB_008e5ebf;
            if (uVar12 == 7) {
              bVar2 = !bVar1;
              bVar1 = true;
              *(uint *)(iVar9 + 0x30) =
                   *(uint *)(iVar9 + 0x30) ^ ((uint)bVar2 ^ *(uint *)(iVar9 + 0x30)) & 1;
            }
            else if (uVar12 == 8) {
              uVar10 = *(short *)((int)local_c + (uint)*(ushort *)(iVar9 + 0x54) * 2) - 1;
              *(ushort *)(iVar9 + 0x4c) = uVar10;
              if (*(int *)(iVar9 + 0x58) == 0x800000d) {
                *(uint *)(iVar9 + 0x30) = *(uint *)(iVar9 + 0x30) | 1;
              }
              else {
                *(uint *)(iVar9 + 0x30) =
                     *(uint *)(iVar9 + 0x30) ^
                     ((uint)(local_10[uVar10] == 0) ^ *(uint *)(iVar9 + 0x30)) & 1;
                local_10[*(ushort *)(iVar9 + 0x4c)] = 1;
              }
            }
            else {
              if (uVar12 == 9) {
LAB_008e5ebf:
                uVar10 = *(ushort *)(iVar9 + 0x54);
                if (uVar10 < 0x100) {
                  uVar5 = (uint)uVar10 + (uint)*(ushort *)(iVar9 + 0x56);
                  puVar11 = (ushort *)(iVar3 + 0xb2);
                }
                else {
                  if (uVar10 < 0x101) goto LAB_008e601d;
                  uVar5 = (*(ushort *)(iVar9 + 0x56) - 0x101) + (uint)uVar10;
                  puVar11 = (ushort *)(iVar3 + 0xaa);
                }
              }
              else if (uVar12 == 0xc) {
                if (uVar5 == 0xc000000) {
                  uVar5 = (uint)*(ushort *)(iVar9 + 0x56) + (uint)*(ushort *)(iVar9 + 0x54);
                  puVar11 = (ushort *)(iVar3 + 0xa4);
                }
                else if (uVar5 == 0xc010000) {
                  uVar5 = (uint)*(ushort *)(iVar9 + 0x56) + (uint)*(ushort *)(iVar9 + 0x54);
                  puVar11 = (ushort *)(iVar3 + 0xa6);
                }
                else {
                  if (uVar5 != 0xc020000) goto LAB_008e601d;
                  uVar5 = (uint)*(ushort *)(iVar9 + 0x56) + (uint)*(ushort *)(iVar9 + 0x54);
                  puVar11 = (ushort *)(iVar3 + 0xa8);
                }
              }
              else {
                if (uVar12 != 0xd) {
                  if (uVar12 != 0xf) goto LAB_008e601d;
                  goto LAB_008e5ebf;
                }
                if (uVar5 == 0xd000000) {
                  uVar5 = (uint)*(ushort *)(iVar9 + 0x56) + (uint)*(ushort *)(iVar9 + 0x54);
                  puVar11 = (ushort *)(iVar3 + 0xac);
                }
                else if (uVar5 == 0xd010000) {
                  uVar5 = (uint)*(ushort *)(iVar9 + 0x56) + (uint)*(ushort *)(iVar9 + 0x54);
                  puVar11 = (ushort *)(iVar3 + 0xae);
                }
                else {
                  if (uVar5 != 0xd020000) goto LAB_008e601d;
                  uVar5 = (uint)*(ushort *)(iVar9 + 0x56) + (uint)*(ushort *)(iVar9 + 0x54);
                  puVar11 = (ushort *)(iVar3 + 0xb0);
                }
              }
              if ((int)uVar5 < (int)(uint)*puVar11) {
                uVar5 = (uint)*puVar11;
              }
              *puVar11 = (ushort)uVar5;
            }
LAB_008e601d:
            local_18 = local_18 - 1;
          } while (local_18 != 0);
        }
        param_3 = (uint *)((int)param_3 + 1);
        uVar5 = (uint)param_3 & 0xffff;
        iVar6 = param_1;
      } while (uVar5 < *(uint *)(iVar3 + 0x34));
LAB_008e6036:
      param_1 = iVar6;
      if (local_8 != 0) {
        FUN_008df375(1);
      }
    }
  }
  if (local_c != (undefined4 *)0x0) {
    _free(local_c);
    return extraout_EAX;
  }
  if (local_10 == (undefined4 *)0x0) {
    return param_1;
  }
  _free(local_10);
  return extraout_EAX_00;
}


// ==== FUN_008e606c @ 0x008e606c ====

uint FUN_008e606c(char *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  char cVar6;
  int in_ECX;
  int iVar7;
  int iVar8;
  char *pcVar9;
  uint local_c;
  
  if ((char *)((uint)param_1 & 0xffff) != param_1) {
    if (0 < (int)param_1) {
      local_c = 0;
      if (*(int *)(in_ECX + 0x98) == 0) {
        return 0;
      }
      uVar3 = *(uint *)(in_ECX + 0x9c);
      do {
        iVar8 = *(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(uVar3 + 0x14) * 4) + 0x40);
        iVar1 = *(int *)(uVar3 + 4);
        if (iVar8 == 0) {
          iVar7 = *(int *)(in_ECX + 0x20);
        }
        else {
          iVar7 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
        }
        iVar2 = *(int *)(iVar1 + 8);
        if (*(int *)(iVar2 + iVar7) == 0) {
          pcVar4 = (char *)0x0;
        }
        else {
          if (iVar8 == 0) {
            iVar8 = *(int *)(in_ECX + 0x20);
          }
          else {
            iVar8 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
          }
          pcVar4 = (char *)(iVar2 + 4 + iVar8);
        }
        pcVar9 = param_1;
        cVar6 = *param_1;
        while ((cVar6 == *pcVar4 && (cVar6 != '\0'))) {
          pcVar9 = pcVar9 + 1;
          pcVar4 = pcVar4 + 1;
          cVar6 = *pcVar9;
        }
        cVar6 = *pcVar9;
        if (cVar6 == *pcVar4) {
          return uVar3;
        }
        if (*pcVar4 == '\0') {
          if (cVar6 == '.') {
            pcVar9 = pcVar9 + 1;
            uVar3 = ~uVar3;
            goto LAB_008e61e7;
          }
          if (cVar6 == '@') {
            *(uint *)(in_ECX + 0x118) =
                 *(uint *)(in_ECX + 0x118) ^ (param_3 * 2 ^ *(uint *)(in_ECX + 0x118)) & 2;
            uVar3 = FUN_008dfe48(~uVar3,pcVar9 + 1,param_2);
            *(uint *)(in_ECX + 0x118) = *(uint *)(in_ECX + 0x118) & 0xfffffffd;
            goto LAB_008e61ee;
          }
          if (cVar6 == '[') {
            pcVar9 = pcVar9 + 1;
            if (*pcVar9 < '0') {
              return 0;
            }
            if ('9' < *pcVar9) {
              return 0;
            }
            uVar5 = _atol(pcVar9);
            if (*(uint *)(iVar1 + 0x10) <= uVar5) {
              return 0;
            }
            for (; ('/' < *pcVar9 && (*pcVar9 < ':')); pcVar9 = pcVar9 + 1) {
            }
            if (*pcVar9 == ']') {
              uVar3 = FUN_008d64b8(~uVar3,uVar5,param_2);
              if (uVar3 != 0) {
                if (pcVar9[1] == '\0') {
LAB_008e61f6:
                  return ~uVar3;
                }
                if (pcVar9[1] == '.') {
                  pcVar9 = pcVar9 + 2;
LAB_008e61e7:
                  uVar3 = FUN_008e4cba(uVar3,pcVar9,param_2);
LAB_008e61ee:
                  if (uVar3 != 0) goto LAB_008e61f6;
                }
              }
            }
            return 0;
          }
        }
        local_c = local_c + 1;
        uVar3 = uVar3 + 0x50;
        if (*(uint *)(in_ECX + 0x98) <= local_c) {
          return 0;
        }
      } while( true );
    }
    uVar3 = ~(uint)param_1;
    if ((*(int *)(uVar3 + 0x10) == 3) && (*(uint *)(uVar3 + 0x14) < *(uint *)(in_ECX + 0xa8))) {
      return uVar3;
    }
  }
  return 0;
}


// ==== FUN_008e61fd @ 0x008e61fd ====

uint FUN_008e61fd(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    if (param_3 < *(uint *)(param_1 + 0x98)) {
      uVar1 = ~(*(int *)(param_1 + 0x9c) + param_3 * 0x50);
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    iVar2 = FUN_008e606c(param_2,1,0);
    if (((iVar2 == 0) || (iVar3 = *(int *)(iVar2 + 4), *(int *)(iVar3 + 4) != 5)) ||
       ((*(int *)(iVar2 + 8) == -1 && (*(int *)(iVar3 + 0x10) != 0)))) {
      uVar1 = 0;
    }
    else if ((param_3 < *(uint *)(iVar3 + 0x14)) &&
            ((*(int *)(iVar2 + 0x20) != 0 ||
             (iVar3 = FUN_008dc045(iVar2,*(uint *)(iVar3 + 0x14)), -1 < iVar3)))) {
      uVar1 = ~(*(int *)(iVar2 + 0x20) + param_3 * 0x28);
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ==== FUN_008e628c @ 0x008e628c ====

void FUN_008e628c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_008e4cba(param_2,param_3,0);
  return;
}


// ==== FUN_008e62a5 @ 0x008e62a5 ====

uint FUN_008e62a5(int param_1,uint param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = 0;
  if (param_2 == 0) {
    param_2 = 0;
    uVar4 = 0;
    if (*(int *)(param_1 + 0x98) != 0) {
      do {
        iVar2 = *(int *)(param_1 + 0x9c) + iVar8;
        if (*(int *)(*(int *)(*(int *)(param_1 + 0xb0) + *(int *)(iVar2 + 0x14) * 4) + 0x40) == 0) {
          iVar5 = *(int *)(param_1 + 0x20);
        }
        else {
          iVar5 = *(int *)(*(int *)(param_1 + 0x38) + 0x10);
        }
        iVar2 = *(int *)(*(int *)(iVar2 + 4) + 0xc);
        if (*(int *)(iVar2 + iVar5) == 0) {
LAB_008e6337:
          pcVar3 = param_3;
LAB_008e633a:
          if (pcVar3 == (char *)0x0) break;
        }
        else {
          if (*(int *)(*(int *)(*(int *)(param_1 + 0xb0) +
                               *(int *)(iVar8 + 0x14 + *(int *)(param_1 + 0x9c)) * 4) + 0x40) == 0)
          {
            iVar5 = *(int *)(param_1 + 0x20);
          }
          else {
            iVar5 = *(int *)(*(int *)(param_1 + 0x38) + 0x10);
          }
          pcVar3 = (char *)(iVar2 + 4 + iVar5);
          if (pcVar3 == (char *)0x0) goto LAB_008e6337;
          if (param_3 != (char *)0x0) {
            pcVar3 = (char *)__stricmp(pcVar3,param_3);
            goto LAB_008e633a;
          }
        }
        param_2 = param_2 + 1;
        iVar8 = iVar8 + 0x50;
      } while (param_2 < *(uint *)(param_1 + 0x98));
      uVar4 = param_2;
    }
    if (uVar4 != *(uint *)(param_1 + 0x98)) {
      uVar4 = *(int *)(param_1 + 0x9c) + uVar4 * 0x50;
LAB_008e6452:
      return ~uVar4;
    }
  }
  else {
    iVar2 = FUN_008e606c(param_2,2,0);
    if ((((iVar2 != 0) && (iVar5 = *(int *)(iVar2 + 4), *(int *)(iVar5 + 4) == 5)) &&
        ((*(int *)(iVar2 + 8) != -1 || (*(int *)(iVar5 + 0x10) == 0)))) &&
       ((uVar4 = *(uint *)(iVar5 + 0x14), *(int *)(iVar2 + 0x20) != 0 ||
        (iVar5 = FUN_008dc045(iVar2,uVar4), -1 < iVar5)))) {
      param_2 = 0;
      uVar6 = 0;
      if (uVar4 != 0) {
        do {
          iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 0xb0) + *(int *)(iVar2 + 0x14) * 4) + 0x40);
          if (iVar5 == 0) {
            iVar7 = *(int *)(param_1 + 0x20);
          }
          else {
            iVar7 = *(int *)(*(int *)(param_1 + 0x38) + 0x10);
          }
          iVar1 = *(int *)(*(int *)(iVar8 + 4 + *(int *)(iVar2 + 0x20)) + 0xc);
          if (*(int *)(iVar1 + iVar7) == 0) {
LAB_008e6429:
            pcVar3 = param_3;
LAB_008e642d:
            if (pcVar3 == (char *)0x0) break;
          }
          else {
            if (iVar5 == 0) {
              iVar5 = *(int *)(param_1 + 0x20);
            }
            else {
              iVar5 = *(int *)(*(int *)(param_1 + 0x38) + 0x10);
            }
            pcVar3 = (char *)(iVar1 + 4 + iVar5);
            if (pcVar3 == (char *)0x0) goto LAB_008e6429;
            if (param_3 != (char *)0x0) {
              pcVar3 = (char *)__stricmp(pcVar3,param_3);
              goto LAB_008e642d;
            }
          }
          param_2 = param_2 + 1;
          iVar8 = iVar8 + 0x28;
        } while (param_2 < uVar4);
        uVar6 = param_2;
      }
      if (uVar6 != uVar4) {
        uVar4 = *(int *)(iVar2 + 0x20) + uVar6 * 0x28;
        goto LAB_008e6452;
      }
    }
  }
  return 0;
}


// ==== FUN_008e645b @ 0x008e645b ====

undefined4 FUN_008e645b(int param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  uVar1 = *(ushort *)(param_1 + 0x42);
  uVar6 = 0;
  if (param_3 != 0) {
    iVar3 = FUN_008d69b4(param_3,1);
    if (iVar3 == 0) {
      return 0;
    }
    uVar1 = *(ushort *)(iVar3 + 0x14);
  }
  iVar3 = FUN_008d61a2(param_2,10);
  if (iVar3 != 0) {
    uVar2 = *(ushort *)(param_1 + 0x40);
    if (uVar1 != uVar2) {
      if ((uVar2 != 0xffff) && (*(int *)((uint)uVar2 * 0xb4 + 0x34 + *(int *)(param_1 + 0xa4)) != 0)
         ) {
        param_3 = 0;
        do {
          if ((*(ushort *)(param_1 + 0x42) == *(ushort *)(param_1 + 0x40)) &&
             (*(ushort *)(param_1 + 0x44) == uVar6)) {
            uVar4 = 0xffffffff;
          }
          else {
            uVar4 = 0;
          }
          FUN_008d51ba(*(undefined2 *)
                        (*(int *)((uint)*(ushort *)(param_1 + 0x40) * 0xb4 + 0x38 +
                                 *(int *)(param_1 + 0xa4)) + param_3 + 0x34),uVar4,0xffffffff);
          param_3 = param_3 + 0x38;
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint *)((uint)*(ushort *)(param_1 + 0x40) * 0xb4 + 0x34 +
                                  *(int *)(param_1 + 0xa4)));
      }
      *(ushort *)(param_1 + 0x40) = uVar1;
      iVar5 = 0;
      uVar6 = 0;
      if (*(int *)((uint)uVar1 * 0xb4 + 0x34 + *(int *)(param_1 + 0xa4)) != 0) {
        do {
          if ((*(ushort *)(param_1 + 0x42) == *(ushort *)(param_1 + 0x40)) &&
             (*(ushort *)(param_1 + 0x44) == uVar6)) {
            uVar4 = 1;
          }
          else {
            uVar4 = 0;
          }
          FUN_008d51ba(*(undefined2 *)
                        (*(int *)((uint)*(ushort *)(param_1 + 0x40) * 0xb4 + 0x38 +
                                 *(int *)(param_1 + 0xa4)) + iVar5 + 0x34),uVar4,1);
          uVar6 = uVar6 + 1;
          iVar5 = iVar5 + 0x38;
        } while (uVar6 < *(uint *)((uint)*(ushort *)(param_1 + 0x40) * 0xb4 + 0x34 +
                                  *(int *)(param_1 + 0xa4)));
      }
      *(uint *)(param_1 + 0x118) = *(uint *)(param_1 + 0x118) | 0x40;
    }
    if ((*(uint *)(param_1 + 0x118) & 0x40) != 0) {
      *(uint *)(param_1 + 0x118) = *(uint *)(param_1 + 0x118) | 0x800;
      iVar5 = 0;
      uVar6 = 0;
      if (*(int *)((uint)*(ushort *)(param_1 + 0x40) * 0xb4 + 0x34 + *(int *)(param_1 + 0xa4)) != 0)
      {
        do {
          if ((*(ushort *)(param_1 + 0x42) == *(ushort *)(param_1 + 0x40)) &&
             (*(ushort *)(param_1 + 0x44) == uVar6)) {
            uVar4 = 1;
          }
          else {
            uVar4 = 0;
          }
          FUN_008e4ead(*(undefined2 *)
                        (*(int *)((uint)*(ushort *)(param_1 + 0x40) * 0xb4 + 0x38 +
                                 *(int *)(param_1 + 0xa4)) + iVar5 + 0x34),uVar4);
          uVar6 = uVar6 + 1;
          iVar5 = iVar5 + 0x38;
        } while (uVar6 < *(uint *)((uint)*(ushort *)(param_1 + 0x40) * 0xb4 + 0x34 +
                                  *(int *)(param_1 + 0xa4)));
      }
      *(ushort *)(param_1 + 0x118) = *(ushort *)(param_1 + 0x118) & 0xf7bf;
    }
    if ((*(byte *)(param_1 + 0x118) & 1) != 0) {
      __controlfp(*(uint *)(param_1 + 0x114),0x30000);
      *(uint *)(param_1 + 0x118) = *(uint *)(param_1 + 0x118) & 0xfffffffe;
    }
    iVar3 = *(int *)(iVar3 + 0x34);
    if (iVar3 != 0) {
      iVar5 = *(int *)(iVar3 + 0x18);
      do {
        iVar5 = *(int *)(iVar5 + 0x1c);
        if (*(short *)((uint)*(ushort *)(iVar5 + 0x14) * 100 + 0x3a + *(int *)(param_1 + 0x2c)) != 0
           ) {
          return 1;
        }
      } while (*(int *)(iVar5 + 0x1c) != iVar3);
    }
  }
  return 0;
}


// ==== FUN_008e6689 @ 0x008e6689 ====

undefined4 FUN_008e6689(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x8876086c;
  }
  if ((int)param_2 < 0) {
    param_2 = ~param_2;
  }
  else {
    param_2 = FUN_008e606c(param_2,1,0);
    if (param_2 == 0) {
      return 0x8876086c;
    }
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0xb0) + *(int *)(param_2 + 0x14) * 4);
  puVar2 = *(undefined4 **)(param_2 + 4);
  puVar7 = param_3;
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  uVar3 = *(uint *)(param_2 + 0x14);
  iVar4 = *(int *)(*(int *)(param_1 + 0xb0) + uVar3 * 4);
  if (((*(uint *)(iVar4 + 0x28) & 1) == 0) && (*(uint *)(param_1 + 0xac) <= uVar3)) {
    iVar4 = *(int *)(*(int *)(param_1 + 0x11c) + (uVar3 - *(uint *)(param_1 + 0xac)) * 4);
  }
  else if (*(int *)(iVar4 + 0x40) == 0) {
    iVar4 = *(int *)(param_1 + 0x20);
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0x38) + 0x10);
  }
  param_3[2] = puVar2[1];
  param_3[3] = *puVar2;
  if (*(int *)(param_2 + 8) == -1) {
    uVar5 = puVar2[4];
  }
  else {
    uVar5 = 0;
  }
  param_3[6] = uVar5;
  if (*(int *)(puVar2[2] + iVar4) == 0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(puVar2[2] + iVar4) + 1;
  }
  *param_3 = piVar6;
  if (*(int *)(iVar4 + puVar2[3]) == 0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(iVar4 + puVar2[3]) + 1;
  }
  param_3[1] = piVar6;
  param_3[10] = *(undefined4 *)(param_2 + 0xc);
  param_3[9] = *(undefined4 *)(iVar1 + 0x28);
  if (((*(int *)(param_2 + 0x18) == 0) && (*(int *)(param_2 + 0x1c) == 0)) &&
     (*(int *)(param_2 + 8) == -1)) {
    param_3[7] = *(undefined4 *)(iVar1 + 0x38);
  }
  else {
    param_3[7] = 0;
  }
  iVar1 = param_3[2];
  if (iVar1 == 1) {
    param_3[8] = 0;
    param_3[4] = puVar2[6];
    uVar5 = puVar2[5];
LAB_008e67d2:
    param_3[5] = uVar5;
  }
  else {
    if (iVar1 == 4) {
      param_3[8] = 0;
    }
    else {
      if (iVar1 != 5) {
        param_3[8] = 0;
        param_3[4] = puVar2[5];
        uVar5 = puVar2[6];
        goto LAB_008e67d2;
      }
      param_3[8] = puVar2[5];
    }
    param_3[4] = 0;
    param_3[5] = 0;
  }
  return 0;
}


// ==== FUN_008e67df @ 0x008e67df ====

undefined4 FUN_008e67df(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 0x24);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  if (*piVar1 == 0) {
    FUN_008e5443(1);
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_008e67fc @ 0x008e67fc ====

int FUN_008e67fc(int param_1,int param_2,int *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *_Memory;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int extraout_EAX;
  int in_ECX;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint local_8;
  
  iVar1 = param_1 * 100 + *(int *)(in_ECX + 0x2c);
  puVar7 = (undefined4 *)(param_2 * 100 + *(int *)(iVar1 + 4));
  iVar3 = *(int *)(&DAT_00a218dc + (uint)*(ushort *)((int)puVar7 + 0x52) * 0x1c);
  if ((((iVar3 != 0x10) && (iVar3 != 0xf)) && (iVar3 != 5)) && (iVar3 != 10)) {
    return -0x7fffbffb;
  }
  if ((param_3 != (int *)0x0) &&
     (uVar2 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 + 1 <= uVar2)) {
    iVar3 = (**(code **)(*param_3 + 0xc))(param_3);
    local_8 = *(uint *)(iVar3 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if (((param_3 == (int *)0x0) ||
      (uVar2 = (**(code **)(*param_3 + 0x10))(param_3), uVar2 < *param_4)) || (local_8 < 2)) {
    return -0x7fffbffb;
  }
  _Memory = operator_new(local_8);
  if (_Memory != (undefined4 *)0x0) {
    if (local_8 != 0) {
      iVar3 = (uint)((local_8 & 3) != 0) + (local_8 >> 2);
      uVar2 = (**(code **)(*param_3 + 0x10))(param_3);
      if (*param_4 + iVar3 <= uVar2) {
        iVar4 = (**(code **)(*param_3 + 0xc))(param_3);
        puVar5 = (undefined4 *)(iVar4 + *param_4 * 4);
        puVar6 = _Memory;
        for (uVar2 = local_8 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar2 = local_8 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
      }
      *param_4 = *param_4 + iVar3;
    }
    uVar2 = (**(code **)(*param_3 + 0x10))(param_3);
    if (((uVar2 < *param_4) ||
        (param_4 = (uint *)0x0, *(char *)((local_8 - 1) + (int)_Memory) != '\0')) ||
       (puVar5 = (undefined4 *)FUN_008e606c(_Memory,2,0), puVar5 == (undefined4 *)0x0)) {
LAB_008e6999:
      param_4 = (uint *)0x80004005;
      goto LAB_008e6aaa;
    }
    iVar3 = *(int *)(*(int *)(in_ECX + 0xb0) + puVar5[5] * 4);
    if (*(int *)(iVar3 + 0x40) == 0) {
      iVar4 = *(int *)(in_ECX + 0x20);
    }
    else {
      iVar4 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
    }
    iVar3 = *(int *)(*(int *)(iVar3 + 0x2c) + puVar5[6] + iVar4);
    puVar7[0xc] = puVar7[0xc] & 0xfffffffd;
    iVar4 = *(int *)(&DAT_00a218dc + (uint)*(ushort *)((int)puVar7 + 0x52) * 0x1c);
    if (iVar4 == 5) {
      if (((iVar3 != 5) && (iVar3 != 6)) && ((iVar3 != 7 && ((iVar3 != 8 && (iVar3 != 9)))))) {
        param_4 = (uint *)0x80004005;
      }
      *puVar7 = 1;
LAB_008e6a40:
      if ((int)param_4 < 0) goto LAB_008e6aaa;
    }
    else {
      if (iVar4 == 10) {
        if ((((iVar3 != 10) && (iVar3 != 0xb)) && (iVar3 != 0xc)) &&
           ((iVar3 != 0xd && (iVar3 != 0xe)))) {
          param_4 = (uint *)0x80004005;
        }
        *puVar7 = 0;
        goto LAB_008e6a40;
      }
      if ((0xe < iVar4) && (iVar4 < 0x11)) {
        if (iVar4 == iVar3) {
          puVar6 = puVar7 + 2;
          for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar6 = puVar6 + 1;
          }
          *(undefined2 *)(puVar7 + 0x15) = 0xffff;
          puVar7[10] = 0;
          puVar7[0xb] = 0;
          *puVar7 = 0;
          *(undefined2 *)((int)puVar7 + 0x52) = 0xb3;
          puVar7[0x16] = 0xe000000;
          *(undefined2 *)((int)puVar7 + 0x56) = 1;
          *(short *)(iVar1 + 0x34) = *(short *)(iVar1 + 0x34) + 1;
          iVar3 = (*(uint *)(iVar1 + 0xc) & 3) + (*(uint *)(iVar1 + 0xc) & 0xfffffffc);
          *(int *)(iVar1 + 0xc) = iVar3;
          puVar7[0x12] = iVar3;
          *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 4;
          goto LAB_008e6aaa;
        }
        goto LAB_008e6999;
      }
    }
    puVar6 = puVar5;
    puVar8 = puVar7 + 2;
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    puVar7[10] = 0;
    puVar7[0xb] = 0;
    puVar6 = operator_new(0x24);
    if (puVar6 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      puVar8 = puVar6 + 1;
      *puVar6 = 1;
      FUN_0040d030(puVar8,0x20,1,&LAB_008d5a15);
    }
    puVar7[0xd] = puVar8;
    if (puVar8 != (undefined4 *)0x0) {
      *(undefined2 *)(puVar7 + 0x14) = 1;
      *(undefined2 *)((int)puVar7 + 0x4e) = 1;
      param_4 = (uint *)FUN_008d60b3(param_1,param_2,0,puVar5,0);
      goto LAB_008e6aaa;
    }
  }
  param_4 = (uint *)0x8007000e;
LAB_008e6aaa:
  if (_Memory == (undefined4 *)0x0) {
    return (int)param_4;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_008e6ac3 @ 0x008e6ac3 ====

int FUN_008e6ac3(int param_1,int param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *_Memory;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int extraout_EAX;
  int in_ECX;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_c;
  uint local_8;
  
  iVar2 = param_1 * 100 + *(int *)(in_ECX + 0x2c);
  puVar8 = (undefined4 *)(param_2 * 100 + *(int *)(iVar2 + 4));
  if ((param_3 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_3 + 0xc))(param_3);
    local_c = *(int *)(iVar4 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if ((param_3 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_3 + 0xc))(param_3);
    local_8 = *(uint *)(iVar4 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if (((param_3 == (int *)0x0) ||
      (uVar3 = (**(code **)(*param_3 + 0x10))(param_3), uVar3 < *param_4)) || (local_8 < 2)) {
    return -0x7fffbffb;
  }
  _Memory = operator_new(local_8);
  if (_Memory == (undefined4 *)0x0) {
    local_8 = -0x7ff8fff2;
    goto LAB_008e6d5a;
  }
  if (local_8 != 0) {
    iVar4 = (uint)((local_8 & 3) != 0) + (local_8 >> 2);
    uVar3 = (**(code **)(*param_3 + 0x10))(param_3);
    if (*param_4 + iVar4 <= uVar3) {
      iVar5 = (**(code **)(*param_3 + 0xc))(param_3);
      puVar6 = (undefined4 *)(iVar5 + *param_4 * 4);
      puVar9 = _Memory;
      for (uVar3 = local_8 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar9 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar3 = local_8 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
    }
    *param_4 = *param_4 + iVar4;
  }
  uVar3 = (**(code **)(*param_3 + 0x10))(param_3);
  if (((*param_4 <= uVar3) && (*(char *)((local_8 - 1) + (int)_Memory) == '\0')) &&
     (puVar6 = (undefined4 *)FUN_008e606c(_Memory,2,0), puVar6 != (undefined4 *)0x0)) {
    puVar9 = puVar8 + 2;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar8[10] = 0;
    puVar8[0xb] = 0;
    *(undefined2 *)(puVar8 + 0x15) = 0xffff;
    puVar8[0xc] = puVar8[0xc] & 0xfffffffd;
    *(undefined2 *)((int)puVar8 + 0x56) = 1;
    *puVar8 = 1;
    uVar3 = local_c + (-4 - local_8);
    *(undefined2 *)((int)puVar8 + 0x52) = 0xb3;
    puVar8[0x16] = 0xe000000;
    *(short *)(iVar2 + 0x34) = *(short *)(iVar2 + 0x34) + 1;
    local_8 = FUN_008eb3df(uVar3 + 0x20,puVar8 + 0xe);
    if ((int)local_8 < 0) goto LAB_008e6d5a;
    piVar1 = (int *)puVar8[0xe];
    puVar6 = (undefined4 *)(**(code **)(*piVar1 + 0xc))(piVar1);
    puVar6[2] = 0;
    *puVar6 = 1;
    puVar6[1] = 3;
    iVar4 = (*(uint *)(iVar2 + 0xc) & 7) + (*(uint *)(iVar2 + 0xc) & 0xfffffff8);
    *(int *)(iVar2 + 0xc) = iVar4;
    puVar6[3] = iVar4;
    uVar7 = *(int *)(iVar2 + 0xc) + 0x20;
    iVar4 = (uVar7 & 3) + (uVar7 & 0xfffffffc);
    *(int *)(iVar2 + 0xc) = iVar4;
    puVar8[0x12] = iVar4;
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 4;
    if (uVar3 == 0) goto LAB_008e6d5a;
    iVar2 = (uint)((uVar3 & 3) != 0) + (uVar3 >> 2);
    uVar7 = (**(code **)(*param_3 + 0x10))(param_3);
    if (*param_4 + iVar2 <= uVar7) {
      iVar4 = (**(code **)(*param_3 + 0xc))(param_3);
      puVar9 = (undefined4 *)(iVar4 + *param_4 * 4);
      puVar10 = puVar6 + 8;
      for (uVar7 = uVar3 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
    }
    *param_4 = *param_4 + iVar2;
    local_8 = FUN_008b5afa(puVar6 + 8,puVar8 + 0x10,puVar8 + 0x11);
    if ((int)local_8 < 0) goto LAB_008e6d5a;
    uVar3 = (**(code **)(*param_3 + 0x10))(param_3);
    if (*param_4 <= uVar3) {
      local_8 = FUN_008b5afa(puVar6 + 8,puVar8 + 0x10,puVar8 + 0x11);
      if (-1 < (int)local_8) {
        local_8 = FUN_008db131(param_1,param_2,puVar6);
      }
      goto LAB_008e6d5a;
    }
  }
  local_8 = -0x7fffbffb;
LAB_008e6d5a:
  if (_Memory == (undefined4 *)0x0) {
    return local_8;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_008e6d73 @ 0x008e6d73 ====

int FUN_008e6d73(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  if ((int)param_2 < 0) {
    param_2 = ~param_2;
  }
  else {
    param_2 = FUN_008e606c(param_2,1,0);
    if (param_2 == 0) {
      return -0x7789f794;
    }
  }
  if ((param_4 != 0xffffffff) && (param_4 < *(uint *)(param_2 + 0xc))) {
    return -0x7789f794;
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    iVar1 = FUN_008e10b4(~param_2,param_3,param_4);
    return iVar1;
  }
  iVar1 = FUN_008dc3cd(param_2,param_3);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_008da8ec(param_2);
  return iVar1;
}


// ==== FUN_008e6ddf @ 0x008e6ddf ====

undefined4 FUN_008e6ddf(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_008e606c(param_2,1,0);
  if ((puVar1 == (undefined4 *)0x0) || ((param_4 != 0xffffffff && (param_4 < (uint)puVar1[3])))) {
    uVar2 = 0x8876086c;
  }
  else {
    uVar2 = FUN_008dc738(puVar1[1],*puVar1,param_3,
                         *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + puVar1[5] * 4) + 0x40),
                         puVar1[2] != -1);
  }
  return uVar2;
}


// ==== FUN_008e6e3b @ 0x008e6e3b ====

undefined4 FUN_008e6e3b(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((int)param_2 < 0) {
    param_2 = ~param_2;
  }
  else {
    param_2 = FUN_008e606c(param_2,1,1);
    if (param_2 == 0) {
      return 0x8876086c;
    }
  }
  uVar1 = *(uint *)(*(int *)(param_2 + 4) + 0x10);
  if ((uVar1 < param_4) || (uVar1 < param_3)) {
    uVar2 = 0x8876086c;
  }
  else {
    *(uint *)(*(int *)(*(int *)(param_1 + 0xb0) + *(int *)(param_2 + 0x14) * 4) + 0x48) = param_3;
    *(uint *)(*(int *)(*(int *)(param_1 + 0xb0) + *(int *)(param_2 + 0x14) * 4) + 0x4c) = param_4;
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_008e6ea6 @ 0x008e6ea6 ====

undefined4 FUN_008e6ea6(int param_1,uint param_2,uint *param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint local_10;
  uint local_c;
  undefined4 *local_8;
  
  if ((int)param_2 < 0) {
    local_8 = (undefined4 *)~param_2;
  }
  else {
    piVar1 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar1 + 4) = 1;
    *(undefined4 *)*piVar1 = 3;
    *(uint *)(*piVar1 + 0x10) = param_4;
    *(undefined4 *)(*piVar1 + 0x14) = 4;
    *(undefined4 *)(*piVar1 + 0x18) = 1;
    local_8 = (undefined4 *)FUN_008e606c(param_2,1,1);
    if (local_8 == (undefined4 *)0x0) {
      return 0x8876086c;
    }
  }
  piVar1 = (int *)local_8[1];
  if (((piVar1[4] != 0) && (local_8[2] == -1)) && (param_4 <= (uint)piVar1[4])) {
    if (*(int *)(param_1 + 0x3c) == 3) {
      uVar3 = FUN_008e08b9(~(uint)local_8,param_3,param_4);
      return uVar3;
    }
    if (piVar1[1] == 1) {
      iVar5 = *piVar1;
      uVar2 = piVar1[5];
      puVar7 = (uint *)*local_8;
      param_2 = 4;
      if (uVar2 < 5) {
        param_2 = uVar2;
      }
      if (iVar5 == 1) {
        if (param_4 != 0) {
          local_10 = param_4;
          do {
            if (param_2 != 0) {
              puVar4 = puVar7;
              uVar6 = param_2;
              do {
                *puVar4 = (uint)(DAT_0099cdc8 !=
                                *(float *)((int)puVar4 + ((int)param_3 - (int)puVar7)));
                puVar4 = puVar4 + 1;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            puVar7 = puVar7 + uVar2;
            param_3 = param_3 + 4;
            local_10 = local_10 - 1;
          } while (local_10 != 0);
        }
      }
      else if (iVar5 == 2) {
        if (param_4 != 0) {
          local_10 = param_4;
          do {
            if (param_2 != 0) {
              local_c = param_2;
              puVar4 = puVar7;
              do {
                uVar6 = __ftol();
                *puVar4 = uVar6;
                puVar4 = puVar4 + 1;
                local_c = local_c - 1;
              } while (local_c != 0);
            }
            puVar7 = puVar7 + uVar2;
            local_10 = local_10 - 1;
          } while (local_10 != 0);
        }
      }
      else {
        if (iVar5 != 3) {
          return 0x8876086c;
        }
        if (uVar2 == 4) {
          for (iVar5 = (param_4 & 0xfffffff) << 2; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar7 = *param_3;
            param_3 = param_3 + 1;
            puVar7 = puVar7 + 1;
          }
          for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(char *)puVar7 = (char)*param_3;
            param_3 = (uint *)((int)param_3 + 1);
            puVar7 = (uint *)((int)puVar7 + 1);
          }
        }
        else {
          for (; param_4 != 0; param_4 = param_4 - 1) {
            if (param_2 != 0) {
              puVar4 = puVar7;
              uVar6 = param_2;
              do {
                *puVar4 = *(uint *)(((int)param_3 - (int)puVar7) + (int)puVar4);
                puVar4 = puVar4 + 1;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + 4;
            puVar7 = puVar7 + uVar2;
          }
        }
      }
      uVar3 = FUN_008da8ec(local_8);
      return uVar3;
    }
  }
  return 0x8876086c;
}


// ==== FUN_008e7069 @ 0x008e7069 ====

undefined4 FUN_008e7069(undefined4 param_1,int param_2,float *param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  float *pfVar5;
  int iVar6;
  uint uVar7;
  
  if (param_4 == 0) {
    return 0;
  }
  if ((param_3 != (float *)0x0) && (piVar4 = (int *)FUN_008e606c(param_2,1,0), piVar4 != (int *)0x0)
     ) {
    piVar1 = (int *)piVar4[1];
    if ((piVar1[4] != 0) &&
       (((piVar4[2] == -1 && (param_4 <= (uint)piVar1[4])) && (piVar1[1] == 1)))) {
      param_2 = *piVar4;
      uVar2 = piVar1[5];
      iVar3 = *piVar1;
      param_1 = 4;
      if (uVar2 < 5) {
        param_1 = uVar2;
      }
      pfVar5 = param_3;
      for (iVar6 = (param_4 & 0xfffffff) << 2; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pfVar5 = 0.0;
        pfVar5 = pfVar5 + 1;
      }
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined1 *)pfVar5 = 0;
        pfVar5 = (float *)((int)pfVar5 + 1);
      }
      if (iVar3 == 1) {
        do {
          if (param_1 != 0) {
            pfVar5 = param_3;
            uVar7 = param_1;
            do {
              *pfVar5 = (float)(*(int *)((int)pfVar5 + (param_2 - (int)param_3)) != 0);
              pfVar5 = pfVar5 + 1;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          param_2 = param_2 + uVar2 * 4;
          param_3 = param_3 + 4;
          param_4 = param_4 - 1;
        } while (param_4 != 0);
        return 0;
      }
      if (iVar3 == 2) {
        do {
          if (param_1 != 0) {
            pfVar5 = param_3;
            uVar7 = param_1;
            do {
              *pfVar5 = (float)*(int *)((int)pfVar5 + (param_2 - (int)param_3));
              pfVar5 = pfVar5 + 1;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          param_2 = param_2 + uVar2 * 4;
          param_3 = param_3 + 4;
          param_4 = param_4 - 1;
        } while (param_4 != 0);
        return 0;
      }
      if (iVar3 == 3) {
        do {
          if (param_1 != 0) {
            pfVar5 = param_3;
            uVar7 = param_1;
            do {
              *pfVar5 = *(float *)((param_2 - (int)param_3) + (int)pfVar5);
              pfVar5 = pfVar5 + 1;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          param_2 = param_2 + uVar2 * 4;
          param_3 = param_3 + 4;
          param_4 = param_4 - 1;
        } while (param_4 != 0);
        return 0;
      }
    }
  }
  return 0x8876086c;
}


// ==== FUN_008e71ac @ 0x008e71ac ====

int FUN_008e71ac(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((int)param_2 < 0) {
    puVar3 = (undefined4 *)~param_2;
  }
  else {
    piVar1 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar1 + 4) = 2;
    *(undefined4 *)*piVar1 = 3;
    *(uint *)(*piVar1 + 0x10) = param_4;
    *(undefined4 *)(*piVar1 + 0x14) = 4;
    *(undefined4 *)(*piVar1 + 0x18) = 4;
    puVar3 = (undefined4 *)FUN_008e606c(param_2,1,1);
    if (puVar3 == (undefined4 *)0x0) {
      return -0x7789f794;
    }
  }
  iVar2 = puVar3[1];
  if (((*(int *)(iVar2 + 4) != 2) || (*(uint *)(iVar2 + 0x10) < param_4)) || (puVar3[2] != -1)) {
    return -0x7789f794;
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    iVar2 = FUN_008e09fe(~(uint)puVar3,param_3,param_4);
    return iVar2;
  }
  iVar2 = FUN_008d739d(iVar2,*puVar3,param_3,param_4);
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = FUN_008da8ec(puVar3);
  return iVar2;
}


// ==== FUN_008e724c @ 0x008e724c ====

undefined4 FUN_008e724c(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_4 == 0) {
    uVar2 = 0;
  }
  else {
    if ((param_3 != 0) &&
       (puVar3 = (undefined4 *)FUN_008e606c(param_2,1,0), puVar3 != (undefined4 *)0x0)) {
      iVar1 = puVar3[1];
      if ((*(uint *)(iVar1 + 0x10) != 0) &&
         (((puVar3[2] == -1 && (param_4 <= *(uint *)(iVar1 + 0x10))) && (*(int *)(iVar1 + 4) == 2)))
         ) {
        uVar2 = FUN_008d7631(iVar1,*puVar3,param_3,param_4);
        return uVar2;
      }
    }
    uVar2 = 0x8876086c;
  }
  return uVar2;
}


// ==== FUN_008e72ab @ 0x008e72ab ====

int FUN_008e72ab(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((int)param_2 < 0) {
    puVar3 = (undefined4 *)~param_2;
  }
  else {
    piVar1 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar1 + 4) = 2;
    *(undefined4 *)*piVar1 = 3;
    *(uint *)(*piVar1 + 0x10) = param_4;
    *(undefined4 *)(*piVar1 + 0x14) = 4;
    *(undefined4 *)(*piVar1 + 0x18) = 4;
    puVar3 = (undefined4 *)FUN_008e606c(param_2,1,1);
    if (puVar3 == (undefined4 *)0x0) {
      return -0x7789f794;
    }
  }
  iVar2 = puVar3[1];
  if (((*(int *)(iVar2 + 4) != 2) || (*(uint *)(iVar2 + 0x10) < param_4)) || (puVar3[2] != -1)) {
    return -0x7789f794;
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    iVar2 = FUN_008e0ab6(~(uint)puVar3,param_3,param_4);
    return iVar2;
  }
  iVar2 = FUN_008d78c4(iVar2,*puVar3,param_3,param_4);
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = FUN_008da8ec(puVar3);
  return iVar2;
}


// ==== FUN_008e734b @ 0x008e734b ====

undefined4 FUN_008e734b(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_4 == 0) {
    uVar2 = 0;
  }
  else {
    if ((param_3 != 0) &&
       (puVar3 = (undefined4 *)FUN_008e606c(param_2,1,0), puVar3 != (undefined4 *)0x0)) {
      iVar1 = puVar3[1];
      if ((*(uint *)(iVar1 + 0x10) != 0) &&
         (((puVar3[2] == -1 && (param_4 <= *(uint *)(iVar1 + 0x10))) && (*(int *)(iVar1 + 4) == 2)))
         ) {
        uVar2 = FUN_008d7b51(iVar1,*puVar3,param_3,param_4);
        return uVar2;
      }
    }
    uVar2 = 0x8876086c;
  }
  return uVar2;
}


// ==== FUN_008e73aa @ 0x008e73aa ====

int FUN_008e73aa(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((int)param_2 < 0) {
    puVar3 = (undefined4 *)~param_2;
  }
  else {
    piVar1 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar1 + 4) = 2;
    *(undefined4 *)*piVar1 = 3;
    *(uint *)(*piVar1 + 0x10) = param_4;
    *(undefined4 *)(*piVar1 + 0x14) = 4;
    *(undefined4 *)(*piVar1 + 0x18) = 4;
    puVar3 = (undefined4 *)FUN_008e606c(param_2,1,1);
    if (puVar3 == (undefined4 *)0x0) {
      return -0x7789f794;
    }
  }
  iVar2 = puVar3[1];
  if (((*(int *)(iVar2 + 4) != 2) || (*(uint *)(iVar2 + 0x10) < param_4)) || (puVar3[2] != -1)) {
    return -0x7789f794;
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    iVar2 = FUN_008e0bff(~(uint)puVar3,param_3,param_4);
    return iVar2;
  }
  iVar2 = FUN_008d7242(iVar2,*puVar3,param_3,param_4);
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = FUN_008da8ec(puVar3);
  return iVar2;
}


// ==== FUN_008e744a @ 0x008e744a ====

undefined4 FUN_008e744a(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_4 == 0) {
    uVar2 = 0;
  }
  else {
    if ((param_3 != 0) &&
       (puVar3 = (undefined4 *)FUN_008e606c(param_2,1,0), puVar3 != (undefined4 *)0x0)) {
      iVar1 = puVar3[1];
      if ((*(uint *)(iVar1 + 0x10) != 0) &&
         (((puVar3[2] == -1 && (param_4 <= *(uint *)(iVar1 + 0x10))) && (*(int *)(iVar1 + 4) == 2)))
         ) {
        uVar2 = FUN_008d74b2(iVar1,*puVar3,param_3,param_4);
        return uVar2;
      }
    }
    uVar2 = 0x8876086c;
  }
  return uVar2;
}


// ==== FUN_008e74a9 @ 0x008e74a9 ====

int FUN_008e74a9(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((int)param_2 < 0) {
    puVar3 = (undefined4 *)~param_2;
  }
  else {
    piVar1 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar1 + 4) = 2;
    *(undefined4 *)*piVar1 = 3;
    *(uint *)(*piVar1 + 0x10) = param_4;
    *(undefined4 *)(*piVar1 + 0x14) = 4;
    *(undefined4 *)(*piVar1 + 0x18) = 4;
    puVar3 = (undefined4 *)FUN_008e606c(param_2,1,1);
    if (puVar3 == (undefined4 *)0x0) {
      return -0x7789f794;
    }
  }
  iVar2 = puVar3[1];
  if (((*(int *)(iVar2 + 4) != 2) || (*(uint *)(iVar2 + 0x10) < param_4)) || (puVar3[2] != -1)) {
    return -0x7789f794;
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    iVar2 = FUN_008e0cc6(~(uint)puVar3,param_3,param_4);
    return iVar2;
  }
  iVar2 = FUN_008d77c4(iVar2,*puVar3,param_3,param_4);
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = FUN_008da8ec(puVar3);
  return iVar2;
}


// ==== FUN_008e7549 @ 0x008e7549 ====

undefined4 FUN_008e7549(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_4 == 0) {
    uVar2 = 0;
  }
  else {
    if ((param_3 != 0) &&
       (puVar3 = (undefined4 *)FUN_008e606c(param_2,1,0), puVar3 != (undefined4 *)0x0)) {
      iVar1 = puVar3[1];
      if ((*(uint *)(iVar1 + 0x10) != 0) &&
         (((puVar3[2] == -1 && (param_4 <= *(uint *)(iVar1 + 0x10))) && (*(int *)(iVar1 + 4) == 2)))
         ) {
        uVar2 = FUN_008d79f3(iVar1,*puVar3,param_3,param_4);
        return uVar2;
      }
    }
    uVar2 = 0x8876086c;
  }
  return uVar2;
}


// ==== FUN_008e75a8 @ 0x008e75a8 ====

undefined4 FUN_008e75a8(int param_1,uint param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if ((int)param_2 < 0) {
    puVar4 = (undefined4 *)~param_2;
  }
  else {
    piVar1 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar1 + 4) = 2;
    *(undefined4 *)*piVar1 = 3;
    *(undefined4 *)(*piVar1 + 0x10) = 0;
    *(undefined4 *)(*piVar1 + 0x14) = 4;
    *(undefined4 *)(*piVar1 + 0x18) = 4;
    puVar4 = (undefined4 *)FUN_008e606c(param_2,1,1);
    if (puVar4 == (undefined4 *)0x0) {
      return 0x8876086c;
    }
  }
  iVar2 = puVar4[1];
  if ((*(int *)(iVar2 + 4) != 2) || ((*(int *)(iVar2 + 0x10) != 0 && (puVar4[2] == -1)))) {
    return 0x8876086c;
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    uVar3 = FUN_008e0971(~(uint)puVar4,param_3);
    return uVar3;
  }
  FUN_008d72db(iVar2,*puVar4,param_3);
  uVar3 = FUN_008da8ec(puVar4);
  return uVar3;
}


// ==== FUN_008e7640 @ 0x008e7640 ====

undefined4 FUN_008e7640(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = (undefined4 *)FUN_008e606c(param_2,1,0);
  if ((puVar2 == (undefined4 *)0x0) ||
     (((iVar1 = puVar2[1], *(int *)(iVar1 + 0x10) != 0 && (puVar2[2] == -1)) ||
      (*(int *)(iVar1 + 4) != 2)))) {
    uVar3 = 0x8876086c;
  }
  else {
    uVar3 = FUN_008d7631(iVar1,*puVar2,param_3,1);
  }
  return uVar3;
}


// ==== FUN_008e7688 @ 0x008e7688 ====

int FUN_008e7688(int param_1,uint param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((int)param_2 < 0) {
    puVar3 = (undefined4 *)~param_2;
  }
  else {
    piVar1 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar1 + 4) = 2;
    *(undefined4 *)*piVar1 = 3;
    *(undefined4 *)(*piVar1 + 0x10) = 0;
    *(undefined4 *)(*piVar1 + 0x14) = 4;
    *(undefined4 *)(*piVar1 + 0x18) = 4;
    puVar3 = (undefined4 *)FUN_008e606c(param_2,1,1);
    if (puVar3 == (undefined4 *)0x0) {
      return -0x7789f794;
    }
  }
  iVar2 = puVar3[1];
  if ((*(int *)(iVar2 + 4) != 2) || ((*(int *)(iVar2 + 0x10) != 0 && (puVar3[2] == -1)))) {
    return -0x7789f794;
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    iVar2 = FUN_008e0b75(~(uint)puVar3,param_3);
    return iVar2;
  }
  iVar2 = FUN_008d7242(iVar2,*puVar3,param_3,1);
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = FUN_008da8ec(puVar3);
  return iVar2;
}


// ==== FUN_008e7729 @ 0x008e7729 ====

undefined4 FUN_008e7729(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (((param_3 == 0) ||
      (puVar1 = (undefined4 *)FUN_008e606c(param_2,1,0), puVar1 == (undefined4 *)0x0)) ||
     ((*(int *)(puVar1[1] + 0x10) != 0 && (puVar1[2] == -1)))) {
    return 0x8876086c;
  }
  uVar2 = FUN_008d74b2(puVar1[1],*puVar1,param_3,1);
  return uVar2;
}


// ==== FUN_008e7771 @ 0x008e7771 ====

undefined4 FUN_008e7771(int param_1,uint param_2,float *param_3)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  float *pfVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar13;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  
  if ((int)param_2 < 0) {
    piVar8 = (int *)~param_2;
  }
  else {
    piVar8 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar8 + 4) = 1;
    *(undefined4 *)*piVar8 = 3;
    *(undefined4 *)(*piVar8 + 0x10) = 0;
    *(undefined4 *)(*piVar8 + 0x14) = 4;
    *(undefined4 *)(*piVar8 + 0x18) = 1;
    piVar8 = (int *)FUN_008e606c(param_2,1,1);
    if (piVar8 == (int *)0x0) {
      return 0x8876086c;
    }
  }
  piVar1 = (int *)piVar8[1];
  uVar7 = 0;
  if (((piVar1[4] != 0) && (piVar8[2] == -1)) || ((piVar1[1] != 1 && (piVar1[1] != 0)))) {
    return 0x8876086c;
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    uVar4 = FUN_008e082d(~(uint)piVar8,param_3);
    return uVar4;
  }
  uVar6 = piVar1[5];
  iVar5 = *piVar1;
  if (iVar5 == 3) {
    pfVar9 = (float *)*piVar8;
    for (; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pfVar9 = *param_3;
      param_3 = param_3 + 1;
      pfVar9 = pfVar9 + 1;
    }
  }
  else if (iVar5 == 2) {
    if (uVar6 == 1) {
      fVar10 = (float10)param_3[3];
      fVar11 = (float10)DAT_0099d080;
      fVar2 = param_3[1];
      fVar3 = param_3[2];
      fVar12 = (float10)DAT_0099cdc8;
      if ((float10)*param_3 < fVar11) {
        fVar13 = (float10)*param_3;
        if ((NAN(fVar13) || NAN(fVar12)) || fVar13 < fVar12 == (fVar13 == fVar12)) {
          fVar10 = fVar11;
          param_3 = (float *)__ftol();
          fVar12 = extraout_ST0;
          fVar11 = extraout_ST1;
        }
        else {
          param_3 = (float *)0x0;
        }
      }
      else {
        param_3 = (float *)0xff;
      }
      if ((float10)fVar2 < fVar11) {
        fVar13 = (float10)fVar2;
        if ((NAN(fVar13) || NAN(fVar12)) || fVar13 < fVar12 == (fVar13 == fVar12)) {
          fVar10 = fVar11;
          param_2 = __ftol();
          fVar12 = extraout_ST0_00;
          fVar11 = extraout_ST1_00;
        }
        else {
          param_2 = 0;
        }
      }
      else {
        param_2 = 0xff;
      }
      if ((float10)fVar3 < fVar11) {
        fVar13 = (float10)fVar3;
        if ((NAN(fVar13) || NAN(fVar12)) || fVar13 < fVar12 == (fVar13 == fVar12)) {
          uVar7 = __ftol();
          fVar11 = extraout_ST0_01;
          fVar10 = extraout_ST1_01;
        }
        else {
          uVar7 = 0;
        }
      }
      else {
        uVar7 = 0xff;
      }
      if (fVar10 < fVar11) {
        fVar11 = (float10)DAT_0099cdc8;
        if ((NAN(fVar10) || NAN(fVar11)) || fVar10 < fVar11 == (fVar10 == fVar11)) {
          iVar5 = __ftol();
        }
        else {
          iVar5 = 0;
        }
      }
      else {
        iVar5 = 0xff;
      }
      *(uint *)*piVar8 = ((iVar5 << 8 | (uint)param_3) << 8 | param_2) << 8 | uVar7;
    }
    else if (uVar6 != 0) {
      do {
        *(int *)(*piVar8 + uVar7 * 4) = (int)ROUND(param_3[uVar7]);
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar6);
    }
  }
  else {
    if (iVar5 != 1) {
      return 0x8876086c;
    }
    param_2 = 0;
    if (uVar6 != 0) {
      do {
        iVar5 = param_2 * 4;
        pfVar9 = param_3 + param_2;
        param_2 = param_2 + 1;
        *(uint *)(iVar5 + *piVar8) = (uint)(DAT_0099cdc8 != *pfVar9);
      } while (param_2 < uVar6);
    }
  }
  uVar4 = FUN_008da8ec(piVar8);
  return uVar4;
}


// ==== FUN_008e79d1 @ 0x008e79d1 ====

undefined4 FUN_008e79d1(undefined4 param_1,undefined4 param_2,float *param_3)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  
  if ((((param_3 != (float *)0x0) &&
       (piVar6 = (int *)FUN_008e606c(param_2,1,0), piVar6 != (int *)0x0)) &&
      ((piVar1 = (int *)piVar6[1], piVar1[4] == 0 || (piVar6[2] != -1)))) &&
     ((-1 < piVar1[1] && (piVar1[1] < 2)))) {
    uVar8 = piVar1[5];
    iVar2 = *piVar1;
    if (piVar1[6] == 1) {
      if (4 < uVar8) {
        uVar8 = 4;
      }
      *param_3 = 0.0;
      param_3[1] = 0.0;
      param_3[2] = 0.0;
      param_3[3] = 0.0;
      if (iVar2 == 1) {
        uVar7 = 0;
        if (uVar8 == 0) {
          return 0;
        }
        do {
          param_3[uVar7] = (float)(*(int *)(*piVar6 + uVar7 * 4) != 0);
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar8);
        return 0;
      }
      if (iVar2 == 2) {
        if (uVar8 == 1) {
          uVar8 = *(uint *)*piVar6;
          fVar3 = (float)(uVar8 >> 8 & 0xff) * DAT_0099d0b0;
          fVar4 = (float)(uVar8 & 0xff) * DAT_0099d0b0;
          fVar5 = (float)(uVar8 >> 0x18) * DAT_0099d0b0;
          *param_3 = (float)(uVar8 >> 0x10 & 0xff) * DAT_0099d0b0;
          param_3[1] = fVar3;
          param_3[2] = fVar4;
          param_3[3] = fVar5;
          return 0;
        }
        uVar7 = 0;
        if (uVar8 == 0) {
          return 0;
        }
        do {
          param_3[uVar7] = (float)*(int *)(*piVar6 + uVar7 * 4);
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar8);
        return 0;
      }
      if (iVar2 == 3) {
        uVar7 = 0;
        if (uVar8 == 0) {
          return 0;
        }
        do {
          param_3[uVar7] = *(float *)(*piVar6 + uVar7 * 4);
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar8);
        return 0;
      }
    }
  }
  return 0x8876086c;
}


// ==== FUN_008e7b24 @ 0x008e7b24 ====

int FUN_008e7b24(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  piVar1 = (int *)(param_1 + 0xc4);
  *(undefined4 *)(*piVar1 + 4) = 4;
  *(undefined4 *)*piVar1 = 4;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  puVar2 = (undefined4 *)FUN_008e606c(param_2,1,1);
  if (((puVar2 == (undefined4 *)0x0) ||
      (((piVar1 = (int *)puVar2[1], piVar1[4] != 0 && (puVar2[2] == -1)) || (piVar1[1] != 4)))) ||
     (*piVar1 != 4)) {
    iVar3 = -0x7789f794;
  }
  else if (*(int *)(param_1 + 0x3c) == 3) {
    iVar3 = FUN_008e0d83(~(uint)puVar2,param_3);
  }
  else {
    iVar3 = FUN_008d7113(param_3,*(undefined4 *)*puVar2,
                         *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + puVar2[5] * 4) + 0x40))
    ;
    if (-1 < iVar3) {
      iVar3 = FUN_008da8ec(puVar2);
    }
  }
  return iVar3;
}


// ==== FUN_008e7bbf @ 0x008e7bbf ====

undefined4 FUN_008e7bbf(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_3 == (undefined4 *)0x0) {
    local_8 = 0x8876086c;
  }
  else {
    puVar3 = (undefined4 *)FUN_008e606c(param_2,1,0);
    if (((puVar3 == (undefined4 *)0x0) ||
        (((piVar1 = (int *)puVar3[1], piVar1[4] != 0 && (puVar3[2] == -1)) || (piVar1[1] != 4)))) ||
       (*piVar1 != 4)) {
      local_8 = 0x8876086c;
    }
    else {
      iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0xb0) + puVar3[5] * 4) + 0x40);
      iVar4 = *(int *)*puVar3;
      if (iVar2 != 0) {
        iVar4 = *(int *)(*(int *)(iVar2 + 8) + iVar4 * 4);
      }
      iVar2 = *(int *)(param_1 + 0x18) + iVar4 * 0x18;
      if (*(int *)(iVar2 + 4) == 0) {
        *param_3 = 0;
      }
      else {
        piVar1 = *(int **)(iVar2 + 4);
        uVar5 = (**(code **)(*piVar1 + 0xc))(piVar1);
        *param_3 = uVar5;
      }
    }
  }
  return local_8;
}


// ==== FUN_008e7c57 @ 0x008e7c57 ====

int FUN_008e7c57(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if ((int)param_2 < 0) {
    puVar5 = (undefined4 *)~param_2;
  }
  else {
    piVar1 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar1 + 4) = 4;
    *(undefined4 *)*piVar1 = 5;
    *(undefined4 *)(*piVar1 + 0x10) = 0;
    puVar5 = (undefined4 *)FUN_008e606c(param_2,1,1);
    if (puVar5 == (undefined4 *)0x0) {
      return -0x7789f794;
    }
  }
  if ((((((int *)puVar5[1])[4] != 0) && (puVar5[2] == -1)) || (iVar3 = *(int *)puVar5[1], iVar3 < 5)
      ) || (9 < iVar3)) {
    return -0x7789f794;
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    iVar3 = FUN_008e0e9b(~(uint)puVar5,param_3);
    return iVar3;
  }
  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0xb0) + puVar5[5] * 4) + 0x40);
  iVar2 = *(int *)*puVar5;
  if (iVar3 == 0) {
    iVar4 = iVar2;
  }
  else {
    iVar4 = *(int *)(*(int *)(iVar3 + 8) + iVar2 * 4);
  }
  if (param_3 == *(int *)(*(int *)(param_1 + 0x18) + 4 + iVar4 * 0x18)) {
    return 0;
  }
  iVar3 = FUN_008d706f(param_3,iVar2,iVar3);
  if (iVar3 < 0) {
    return iVar3;
  }
  iVar3 = FUN_008da8ec(puVar5);
  return iVar3;
}


// ==== FUN_008e7d2b @ 0x008e7d2b ====

undefined4 FUN_008e7d2b(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (param_3 == (int *)0x0) {
    uVar5 = 0x8876086c;
  }
  else {
    puVar3 = (undefined4 *)FUN_008e606c(param_2,1,0);
    if (((puVar3 == (undefined4 *)0x0) ||
        (((piVar1 = (int *)puVar3[1], piVar1[4] != 0 && (puVar3[2] == -1)) ||
         (iVar2 = *piVar1, piVar1[1] != 4)))) ||
       ((((iVar2 != 5 && (iVar2 != 6)) && (iVar2 != 7)) && ((iVar2 != 8 && (iVar2 != 9)))))) {
      uVar5 = 0x8876086c;
    }
    else {
      iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0xb0) + puVar3[5] * 4) + 0x40);
      iVar4 = *(int *)*puVar3;
      if (iVar2 != 0) {
        iVar4 = *(int *)(*(int *)(iVar2 + 8) + iVar4 * 4);
      }
      piVar1 = *(int **)(*(int *)(param_1 + 0x18) + 4 + iVar4 * 0x18);
      *param_3 = (int)piVar1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
    }
  }
  return uVar5;
}


// ==== FUN_008e7dcd @ 0x008e7dcd ====

int FUN_008e7dcd(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = (int *)(param_1 + 0xc4);
  *(undefined4 *)(*piVar1 + 4) = 4;
  *(undefined4 *)*piVar1 = 0xf;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  puVar3 = (undefined4 *)FUN_008e606c(param_2,1,1);
  if (((puVar3 == (undefined4 *)0x0) ||
      (((piVar1 = (int *)puVar3[1], piVar1[4] != 0 && (puVar3[2] == -1)) || (piVar1[1] != 4)))) ||
     (*piVar1 != 0xf)) {
    iVar4 = -0x7789f794;
  }
  else if (*(int *)(param_1 + 0x3c) == 3) {
    iVar4 = FUN_008e0f4e(~(uint)puVar3,param_3);
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0xb0) + puVar3[5] * 4);
    iVar2 = *(int *)(iVar4 + 0x40);
    if (iVar2 == 0) {
      iVar6 = puVar3[7];
      iVar5 = *(int *)(*(int *)(iVar4 + 0x30) + iVar6 + *(int *)(param_1 + 0x20));
    }
    else {
      iVar5 = *(int *)(*(int *)(param_1 + 0xb0) + puVar3[5] * 4);
      iVar6 = puVar3[7];
      iVar5 = *(int *)(*(int *)(*(int *)(iVar5 + 0x40) + 8) +
                      *(int *)(*(int *)(iVar5 + 0x30) + iVar6 +
                              *(int *)(*(int *)(param_1 + 0x38) + 0x10)) * 4);
    }
    if (param_3 == *(int *)(*(int *)(param_1 + 0x18) + 4 + iVar5 * 0x18)) {
      if (iVar2 == 0) {
        iVar4 = *(int *)(*(int *)(iVar4 + 0x30) + iVar6 + *(int *)(param_1 + 0x20));
      }
      else {
        iVar4 = *(int *)(*(int *)(param_1 + 0xb0) + puVar3[5] * 4);
        iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 0x40) + 8) +
                        *(int *)(*(int *)(iVar4 + 0x30) + iVar6 +
                                *(int *)(*(int *)(param_1 + 0x38) + 0x10)) * 4);
      }
      if ((*(byte *)(*(int *)(param_1 + 0x18) + 0x14 + iVar4 * 0x18) & 2) != 0) {
        return 0;
      }
    }
    iVar4 = FUN_008d6fb7(param_3,*(undefined4 *)*puVar3,iVar2);
    if (-1 < iVar4) {
      iVar4 = FUN_008da8ec(puVar3);
    }
  }
  return iVar4;
}


// ==== FUN_008e7f22 @ 0x008e7f22 ====

undefined4 FUN_008e7f22(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_3 == (int *)0x0) {
    local_8 = 0x8876086c;
  }
  else {
    iVar3 = FUN_008e606c(param_2,1,0);
    if (((iVar3 == 0) ||
        (((piVar1 = *(int **)(iVar3 + 4), piVar1[4] != 0 && (*(int *)(iVar3 + 8) == -1)) ||
         (piVar1[1] != 4)))) || (*piVar1 != 0xf)) {
      local_8 = 0x8876086c;
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0xb0) + *(int *)(iVar3 + 0x14) * 4);
      if (*(int *)(iVar2 + 0x40) == 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 0x30) + *(int *)(iVar3 + 0x1c) + *(int *)(param_1 + 0x20))
        ;
      }
      else {
        iVar2 = *(int *)(*(int *)(param_1 + 0xb0) + *(int *)(iVar3 + 0x14) * 4);
        iVar3 = *(int *)(*(int *)(*(int *)(iVar2 + 0x40) + 8) +
                        *(int *)(*(int *)(iVar2 + 0x30) + *(int *)(iVar3 + 0x1c) +
                                *(int *)(*(int *)(param_1 + 0x38) + 0x10)) * 4);
      }
      piVar1 = *(int **)(*(int *)(param_1 + 0x18) + 4 + iVar3 * 0x18);
      *param_3 = (int)piVar1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
    }
  }
  return local_8;
}


// ==== FUN_008e7fdd @ 0x008e7fdd ====

int FUN_008e7fdd(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = (int *)(param_1 + 0xc4);
  *(undefined4 *)(*piVar1 + 4) = 4;
  *(undefined4 *)*piVar1 = 0x10;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  puVar3 = (undefined4 *)FUN_008e606c(param_2,1,1);
  if (((puVar3 == (undefined4 *)0x0) ||
      (((piVar1 = (int *)puVar3[1], piVar1[4] != 0 && (puVar3[2] == -1)) || (piVar1[1] != 4)))) ||
     (*piVar1 != 0x10)) {
    iVar4 = -0x7789f794;
  }
  else if (*(int *)(param_1 + 0x3c) == 3) {
    iVar4 = FUN_008e1001(~(uint)puVar3,param_3);
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0xb0) + puVar3[5] * 4);
    iVar2 = *(int *)(iVar4 + 0x40);
    if (iVar2 == 0) {
      iVar6 = puVar3[7];
      iVar5 = *(int *)(*(int *)(iVar4 + 0x30) + iVar6 + *(int *)(param_1 + 0x20));
    }
    else {
      iVar5 = *(int *)(*(int *)(param_1 + 0xb0) + puVar3[5] * 4);
      iVar6 = puVar3[7];
      iVar5 = *(int *)(*(int *)(*(int *)(iVar5 + 0x40) + 8) +
                      *(int *)(*(int *)(iVar5 + 0x30) + iVar6 +
                              *(int *)(*(int *)(param_1 + 0x38) + 0x10)) * 4);
    }
    if (param_3 == *(int *)(*(int *)(param_1 + 0x18) + 4 + iVar5 * 0x18)) {
      if (iVar2 == 0) {
        iVar4 = *(int *)(*(int *)(iVar4 + 0x30) + iVar6 + *(int *)(param_1 + 0x20));
      }
      else {
        iVar4 = *(int *)(*(int *)(param_1 + 0xb0) + puVar3[5] * 4);
        iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 0x40) + 8) +
                        *(int *)(*(int *)(iVar4 + 0x30) + iVar6 +
                                *(int *)(*(int *)(param_1 + 0x38) + 0x10)) * 4);
      }
      if ((*(byte *)(*(int *)(param_1 + 0x18) + 0x14 + iVar4 * 0x18) & 2) != 0) {
        return 0;
      }
    }
    iVar4 = FUN_008d6fb7(param_3,*(undefined4 *)*puVar3,iVar2);
    if (-1 < iVar4) {
      iVar4 = FUN_008da8ec(puVar3);
    }
  }
  return iVar4;
}


// ==== FUN_008e8132 @ 0x008e8132 ====

undefined4 FUN_008e8132(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_3 == (int *)0x0) {
    local_8 = 0x8876086c;
  }
  else {
    iVar3 = FUN_008e606c(param_2,1,0);
    if (((iVar3 == 0) ||
        (((piVar1 = *(int **)(iVar3 + 4), piVar1[4] != 0 && (*(int *)(iVar3 + 8) == -1)) ||
         (piVar1[1] != 4)))) || (*piVar1 != 0x10)) {
      local_8 = 0x8876086c;
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0xb0) + *(int *)(iVar3 + 0x14) * 4);
      if (*(int *)(iVar2 + 0x40) == 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 0x30) + *(int *)(iVar3 + 0x1c) + *(int *)(param_1 + 0x20))
        ;
      }
      else {
        iVar2 = *(int *)(*(int *)(param_1 + 0xb0) + *(int *)(iVar3 + 0x14) * 4);
        iVar3 = *(int *)(*(int *)(*(int *)(iVar2 + 0x40) + 8) +
                        *(int *)(*(int *)(iVar2 + 0x30) + *(int *)(iVar3 + 0x1c) +
                                *(int *)(*(int *)(param_1 + 0x38) + 0x10)) * 4);
      }
      piVar1 = *(int **)(*(int *)(param_1 + 0x18) + 4 + iVar3 * 0x18);
      *param_3 = (int)piVar1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
    }
  }
  return local_8;
}


// ==== FUN_008e81ed @ 0x008e81ed ====

undefined4 FUN_008e81ed(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  float local_18 [4];
  undefined4 local_8;
  
  local_8 = 0;
  if ((int)param_2 < 0) {
    piVar6 = (int *)~param_2;
  }
  else {
    piVar6 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar6 + 4) = 0;
    *(undefined4 *)*piVar6 = 2;
    *(undefined4 *)(*piVar6 + 0x10) = 0;
    *(undefined4 *)(*piVar6 + 0x14) = 1;
    *(undefined4 *)(*piVar6 + 0x18) = 1;
    piVar6 = (int *)FUN_008e606c(param_2,1,1);
    if (piVar6 == (int *)0x0) {
      return 0x8876086c;
    }
  }
  piVar1 = (int *)piVar6[1];
  if ((piVar1[4] != 0) && (piVar6[2] == -1)) {
    return 0x8876086c;
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    uVar4 = FUN_008e05de(~(uint)piVar6,param_3);
  }
  else {
    if (piVar1[1] < 0) {
      return 0x8876086c;
    }
    if (3 < piVar1[1]) {
      return 0x8876086c;
    }
    uVar2 = piVar1[5];
    iVar3 = *piVar1;
    if (((iVar3 == 3) && (piVar1[6] == 1)) && ((uVar2 == 3 || (uVar2 == 4)))) {
      local_18[0] = (float)(param_3 >> 0x10 & 0xff) * DAT_0099d0b0;
      local_18[1] = (float)(param_3 >> 8 & 0xff) * DAT_0099d0b0;
      uVar5 = 0;
      local_18[2] = (float)(param_3 & 0xff) * DAT_0099d0b0;
      local_18[3] = (float)(param_3 >> 0x18) * DAT_0099d0b0;
      if (uVar2 != 0) {
        do {
          *(float *)(*piVar6 + uVar5 * 4) = local_18[uVar5];
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar2);
      }
    }
    else {
      if (uVar2 != 1) {
        return 0x8876086c;
      }
      if (piVar1[6] != 1) {
        return 0x8876086c;
      }
      if (iVar3 == 1) {
        if ((*(uint *)*piVar6 == 0) == (param_3 == 0)) {
          return local_8;
        }
        *(uint *)*piVar6 = (uint)(param_3 != 0);
      }
      else if (iVar3 == 2) {
        if (*(uint *)*piVar6 == param_3) {
          return local_8;
        }
        *(uint *)*piVar6 = param_3;
      }
      else {
        if (iVar3 != 3) {
          return 0x8876086c;
        }
        if (*(float *)*piVar6 == (float)(int)param_3) {
          return local_8;
        }
        *(float *)*piVar6 = (float)(int)param_3;
      }
    }
    uVar4 = FUN_008da8ec(piVar6);
  }
  return uVar4;
}


// ==== FUN_008e837a @ 0x008e837a ====

undefined4 FUN_008e837a(undefined4 param_1,uint param_2,uint *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  float *pfVar5;
  uint uVar6;
  float *pfVar7;
  uint uVar8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar11;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float local_18 [5];
  
  local_18[4] = 0.0;
  if (param_3 == (uint *)0x0) {
    return 0x8876086c;
  }
  puVar3 = (undefined4 *)FUN_008e606c(param_2,1,0);
  if (((puVar3 == (undefined4 *)0x0) ||
      (((piVar1 = (int *)puVar3[1], piVar1[4] != 0 && (puVar3[2] == -1)) || (piVar1[1] < 0)))) ||
     (3 < piVar1[1])) {
    return 0x8876086c;
  }
  iVar4 = piVar1[5];
  iVar2 = *piVar1;
  if (((iVar2 != 3) || (piVar1[6] != 1)) || ((iVar4 != 3 && (iVar4 != 4)))) {
    if (iVar4 != 1) {
      return 0x8876086c;
    }
    if (piVar1[6] != 1) {
      return 0x8876086c;
    }
    if (iVar2 == 1) {
      *param_3 = (uint)(*(int *)*puVar3 != 0);
      return local_18[4];
    }
    if (iVar2 == 2) {
      uVar8 = *(uint *)*puVar3;
    }
    else {
      if (iVar2 != 3) {
        return 0x8876086c;
      }
      uVar8 = __ftol();
    }
    *param_3 = uVar8;
    return local_18[4];
  }
  local_18[0] = 0.0;
  local_18[1] = 0.0;
  local_18[2] = 0.0;
  local_18[3] = 0.0;
  fVar9 = (float10)DAT_0099d080;
  fVar10 = (float10)DAT_0099cdc8;
  if (iVar4 != 0) {
    pfVar5 = (float *)*puVar3;
    pfVar7 = local_18;
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pfVar7 = *pfVar5;
      pfVar5 = pfVar5 + 1;
      pfVar7 = pfVar7 + 1;
    }
    if (fVar9 <= (float10)local_18[0]) {
      param_2 = 0xff;
      goto LAB_008e846d;
    }
    fVar11 = (float10)local_18[0];
    if ((NAN(fVar11) || NAN(fVar10)) || fVar11 < fVar10 == (fVar11 == fVar10)) {
      param_2 = __ftol();
      fVar10 = extraout_ST0;
      fVar9 = extraout_ST1;
      goto LAB_008e846d;
    }
  }
  param_2 = 0;
LAB_008e846d:
  if ((float10)local_18[1] < fVar9) {
    fVar11 = (float10)local_18[1];
    if ((NAN(fVar11) || NAN(fVar10)) || fVar11 < fVar10 == (fVar11 == fVar10)) {
      uVar8 = __ftol();
      fVar10 = extraout_ST0_00;
      fVar9 = extraout_ST1_00;
    }
    else {
      uVar8 = 0;
    }
  }
  else {
    uVar8 = 0xff;
  }
  if ((float10)local_18[2] < fVar9) {
    fVar11 = (float10)local_18[2];
    if ((NAN(fVar11) || NAN(fVar10)) || fVar11 < fVar10 == (fVar11 == fVar10)) {
      uVar6 = __ftol();
      fVar9 = extraout_ST0_01;
    }
    else {
      uVar6 = 0;
    }
  }
  else {
    uVar6 = 0xff;
  }
  if ((float10)local_18[3] < fVar9) {
    if ((NAN(local_18[3]) || NAN(DAT_0099cdc8)) ||
        local_18[3] < DAT_0099cdc8 == (local_18[3] == DAT_0099cdc8)) {
      iVar4 = __ftol();
    }
    else {
      iVar4 = 0;
    }
  }
  else {
    iVar4 = 0xff;
  }
  *param_3 = ((iVar4 << 8 | param_2) << 8 | uVar8) << 8 | uVar6;
  return local_18[4];
}


// ==== FUN_008e856c @ 0x008e856c ====

undefined4 FUN_008e856c(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  if ((int)param_2 < 0) {
    puVar4 = (undefined4 *)~param_2;
  }
  else {
    piVar1 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar1 + 4) = 0;
    *(undefined4 *)*piVar1 = 1;
    *(undefined4 *)(*piVar1 + 0x10) = 0;
    *(undefined4 *)(*piVar1 + 0x14) = 1;
    *(undefined4 *)(*piVar1 + 0x18) = 1;
    puVar4 = (undefined4 *)FUN_008e606c(param_2,1,1);
    if (puVar4 == (undefined4 *)0x0) {
      return 0x8876086c;
    }
  }
  piVar1 = (int *)puVar4[1];
  if ((piVar1[4] == 0) || (puVar4[2] != -1)) {
    if (*(int *)(param_1 + 0x3c) == 3) {
      uVar3 = FUN_008e0536(~(uint)puVar4,param_3);
      return uVar3;
    }
    uVar5 = (uint)(param_3 != 0);
    if ((((-1 < piVar1[1]) && (piVar1[1] < 4)) && (piVar1[5] == 1)) && (piVar1[6] == 1)) {
      iVar2 = *piVar1;
      if (iVar2 == 1) {
        if ((*(uint *)*puVar4 == 0) == (uVar5 == 0)) {
          return 0;
        }
        *(uint *)*puVar4 = uVar5;
      }
      else if (iVar2 == 2) {
        if (*(uint *)*puVar4 == uVar5) {
          return 0;
        }
        *(uint *)*puVar4 = uVar5;
      }
      else {
        if (iVar2 != 3) {
          return 0x8876086c;
        }
        if (*(float *)*puVar4 == (float)uVar5) {
          return 0;
        }
        *(float *)*puVar4 = (float)uVar5;
      }
      uVar3 = FUN_008da8ec(puVar4);
      return uVar3;
    }
  }
  return 0x8876086c;
}


// ==== FUN_008e8666 @ 0x008e8666 ====

undefined4 FUN_008e8666(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((((param_3 != (uint *)0x0) &&
       (puVar3 = (undefined4 *)FUN_008e606c(param_2,1,0), puVar3 != (undefined4 *)0x0)) &&
      ((piVar1 = (int *)puVar3[1], piVar1[4] == 0 || (puVar3[2] != -1)))) &&
     ((((-1 < piVar1[1] && (piVar1[1] < 4)) && (piVar1[5] == 1)) && (piVar1[6] == 1)))) {
    iVar2 = *piVar1;
    if ((iVar2 == 1) || (iVar2 == 2)) {
      *param_3 = (uint)(*(int *)*puVar3 != 0);
      return 0;
    }
    if (iVar2 == 3) {
      *param_3 = (uint)(DAT_0099cdc8 != *(float *)*puVar3);
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== FUN_008e86f8 @ 0x008e86f8 ====

undefined4 FUN_008e86f8(int param_1,uint param_2,float *param_3,int param_4)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  uint uVar10;
  uint local_14;
  int *local_10;
  uint local_8;
  
  if ((int)param_2 < 0) {
    local_10 = (int *)~param_2;
  }
  else {
    piVar2 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar2 + 4) = 0;
    *(undefined4 *)*piVar2 = 1;
    *(int *)(*piVar2 + 0x10) = param_4;
    *(undefined4 *)(*piVar2 + 0x14) = 1;
    *(undefined4 *)(*piVar2 + 0x18) = 1;
    local_10 = (int *)FUN_008e606c(param_2,1,1);
    if (local_10 == (int *)0x0) {
      return 0x8876086c;
    }
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    uVar5 = FUN_008e0632(~(uint)local_10,param_3,param_4);
    return uVar5;
  }
  piVar2 = (int *)local_10[1];
  iVar3 = piVar2[1];
  if (iVar3 < 0) {
    return 0x8876086c;
  }
  if (1 < iVar3) {
    if (iVar3 == 2) {
      param_2 = piVar2[4];
      uVar4 = piVar2[5];
      uVar10 = piVar2[6];
      if ((param_2 == 0) || (local_10[2] != -1)) {
        param_2 = 1;
      }
      iVar3 = *piVar2;
      iVar9 = *local_10;
      if (iVar3 == 1) {
        local_14 = 0;
        if (param_2 != 0) {
          pfVar8 = param_3;
          do {
            if (param_4 == 0) break;
            param_3 = (float *)0x0;
            if (uVar10 != 0) {
              do {
                local_8 = 0;
                if (uVar4 != 0) {
                  pfVar7 = pfVar8 + (int)param_3;
                  do {
                    if (param_4 == 0) break;
                    param_4 = param_4 + -1;
                    uVar6 = local_8 + 1;
                    *(float *)(iVar9 + (local_8 + (int)param_3 * 4) * 4) = *pfVar7;
                    pfVar7 = pfVar7 + uVar10;
                    local_8 = uVar6;
                  } while (uVar6 < uVar4);
                }
                param_3 = (float *)((int)param_3 + 1);
              } while (param_3 < uVar10);
            }
            iVar9 = iVar9 + 0x40;
            local_14 = local_14 + 1;
            pfVar8 = pfVar8 + uVar10 * uVar4;
          } while (local_14 < param_2);
        }
      }
      else if (iVar3 == 2) {
        local_14 = 0;
        if (param_2 != 0) {
          pfVar8 = param_3;
          do {
            if (param_4 == 0) break;
            param_3 = (float *)0x0;
            if (uVar10 != 0) {
              do {
                local_8 = 0;
                if (uVar4 != 0) {
                  pfVar7 = pfVar8 + (int)param_3;
                  do {
                    if (param_4 == 0) break;
                    param_4 = param_4 + -1;
                    uVar6 = local_8 + 1;
                    *(float *)(iVar9 + (local_8 + (int)param_3 * 4) * 4) = *pfVar7;
                    pfVar7 = pfVar7 + uVar10;
                    local_8 = uVar6;
                  } while (uVar6 < uVar4);
                }
                param_3 = (float *)((int)param_3 + 1);
              } while (param_3 < uVar10);
            }
            iVar9 = iVar9 + 0x40;
            local_14 = local_14 + 1;
            pfVar8 = pfVar8 + uVar10 * uVar4;
          } while (local_14 < param_2);
        }
      }
      else {
        if (iVar3 != 3) {
          return 0x80004005;
        }
        local_8 = 0;
        if (param_2 != 0) {
          pfVar8 = param_3;
          do {
            if (param_4 == 0) break;
            param_3 = (float *)0x0;
            if (uVar10 != 0) {
              do {
                uVar6 = 0;
                if (uVar4 != 0) {
                  pfVar7 = pfVar8 + (int)param_3;
                  do {
                    if (param_4 == 0) break;
                    param_4 = param_4 + -1;
                    *(float *)(iVar9 + (uVar6 + (int)param_3 * 4) * 4) = (float)(int)*pfVar7;
                    pfVar7 = pfVar7 + uVar10;
                    uVar6 = uVar6 + 1;
                  } while (uVar6 < uVar4);
                }
                param_3 = (float *)((int)param_3 + 1);
              } while (param_3 < uVar10);
            }
            iVar9 = iVar9 + 0x40;
            local_8 = local_8 + 1;
            pfVar8 = pfVar8 + uVar10 * uVar4;
          } while (local_8 < param_2);
        }
      }
      goto LAB_008e8a28;
    }
    if (iVar3 != 3) {
      return 0x8876086c;
    }
  }
  param_2 = piVar2[4];
  if ((param_2 == 0) || (local_10[2] != -1)) {
    param_2 = 1;
  }
  uVar4 = piVar2[5];
  iVar3 = *piVar2;
  pfVar8 = (float *)*local_10;
  if (iVar3 == 1) {
    uVar10 = 0;
    if (param_2 != 0) {
      do {
        uVar6 = 0;
        if (param_4 == 0) break;
        if (uVar4 != 0) {
          do {
            if (param_4 == 0) break;
            fVar1 = *param_3;
            param_3 = param_3 + 1;
            param_4 = param_4 + -1;
            *pfVar8 = fVar1;
            pfVar8 = pfVar8 + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar4);
        }
        uVar10 = uVar10 + 1;
        pfVar8 = pfVar8 + (4 - uVar4);
      } while (uVar10 < param_2);
    }
  }
  else if (iVar3 == 2) {
    uVar10 = 0;
    if (param_2 != 0) {
      do {
        uVar6 = 0;
        if (param_4 == 0) break;
        if (uVar4 != 0) {
          do {
            if (param_4 == 0) break;
            fVar1 = *param_3;
            param_3 = param_3 + 1;
            param_4 = param_4 + -1;
            *pfVar8 = fVar1;
            pfVar8 = pfVar8 + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar4);
        }
        uVar10 = uVar10 + 1;
        pfVar8 = pfVar8 + (4 - uVar4);
      } while (uVar10 < param_2);
    }
  }
  else {
    if (iVar3 != 3) {
      return 0x8876086c;
    }
    uVar10 = 0;
    if (param_2 != 0) {
      do {
        uVar6 = 0;
        if (param_4 == 0) break;
        if (uVar4 != 0) {
          do {
            if (param_4 == 0) break;
            fVar1 = *param_3;
            param_3 = param_3 + 1;
            param_4 = param_4 + -1;
            *pfVar8 = (float)(int)fVar1;
            pfVar8 = pfVar8 + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar4);
        }
        uVar10 = uVar10 + 1;
        pfVar8 = pfVar8 + (4 - uVar4);
      } while (uVar10 < param_2);
    }
  }
LAB_008e8a28:
  uVar5 = FUN_008da8ec(local_10);
  return uVar5;
}


// ==== FUN_008e8a38 @ 0x008e8a38 ====

undefined4 FUN_008e8a38(undefined4 param_1,float *param_2,uint *param_3,float *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  undefined4 *puVar5;
  float *pfVar6;
  uint *puVar7;
  int iVar8;
  int local_18;
  int local_14;
  int local_10;
  uint *local_c;
  
  if (param_4 == (float *)0x0) {
    return 0;
  }
  if (param_3 == (uint *)0x0) {
    return 0x8876086c;
  }
  puVar5 = (undefined4 *)FUN_008e606c(param_2,1,0);
  if (puVar5 == (undefined4 *)0x0) {
    return 0x8876086c;
  }
  piVar1 = (int *)puVar5[1];
  iVar8 = piVar1[1];
  if (-1 < iVar8) {
    if (1 < iVar8) {
      if (iVar8 == 2) {
        local_18 = piVar1[4];
        if ((local_18 == 0) || (puVar5[2] != -1)) {
          local_18 = 1;
        }
        iVar8 = piVar1[5];
        iVar2 = piVar1[6];
        iVar3 = *piVar1;
        param_4 = (float *)*puVar5;
        local_10 = local_18;
        if (iVar3 == 1) {
          if (local_18 == 0) {
            return 0;
          }
          do {
            if (iVar2 != 0) {
              param_1 = (float *)param_3;
              param_2 = param_4;
              local_14 = iVar2;
              do {
                if (iVar8 != 0) {
                  pfVar6 = param_2;
                  puVar7 = (uint *)param_1;
                  local_18 = iVar8;
                  do {
                    fVar4 = *pfVar6;
                    pfVar6 = pfVar6 + 1;
                    *puVar7 = (uint)(fVar4 != 0.0);
                    puVar7 = puVar7 + iVar2;
                    local_18 = local_18 + -1;
                  } while (local_18 != 0);
                }
                param_2 = param_2 + 4;
                param_1 = param_1 + 1;
                local_14 = local_14 + -1;
              } while (local_14 != 0);
            }
            param_4 = param_4 + 0x10;
            param_3 = param_3 + iVar2 * iVar8;
            local_10 = local_10 + -1;
          } while (local_10 != 0);
          return 0;
        }
        if (iVar3 == 2) {
          if (local_18 == 0) {
            return 0;
          }
          do {
            if (iVar2 != 0) {
              param_1 = (float *)param_3;
              param_2 = param_4;
              local_14 = iVar2;
              do {
                if (iVar8 != 0) {
                  pfVar6 = param_2;
                  puVar7 = (uint *)param_1;
                  local_18 = iVar8;
                  do {
                    fVar4 = *pfVar6;
                    pfVar6 = pfVar6 + 1;
                    *puVar7 = (uint)(fVar4 != 0.0);
                    puVar7 = puVar7 + iVar2;
                    local_18 = local_18 + -1;
                  } while (local_18 != 0);
                }
                param_2 = param_2 + 4;
                param_1 = param_1 + 1;
                local_14 = local_14 + -1;
              } while (local_14 != 0);
            }
            param_4 = param_4 + 0x10;
            param_3 = param_3 + iVar2 * iVar8;
            local_10 = local_10 + -1;
          } while (local_10 != 0);
          return 0;
        }
        if (iVar3 != 3) {
          return 0x80004005;
        }
        if (local_18 == 0) {
          return 0;
        }
        do {
          if (iVar2 != 0) {
            local_c = param_3;
            param_1 = param_4;
            local_14 = iVar2;
            do {
              if (iVar8 != 0) {
                param_2 = param_1;
                puVar7 = local_c;
                local_10 = iVar8;
                do {
                  fVar4 = *param_2;
                  param_2 = param_2 + 1;
                  *puVar7 = (uint)(DAT_0099cdc8 != fVar4);
                  puVar7 = puVar7 + iVar2;
                  local_10 = local_10 + -1;
                } while (local_10 != 0);
              }
              param_1 = param_1 + 4;
              local_c = local_c + 1;
              local_14 = local_14 + -1;
            } while (local_14 != 0);
          }
          param_4 = param_4 + 0x10;
          param_3 = param_3 + iVar2 * iVar8;
          local_18 = local_18 + -1;
        } while (local_18 != 0);
        return 0;
      }
      if (iVar8 != 3) {
        return 0x8876086c;
      }
    }
    iVar8 = piVar1[4];
    if ((iVar8 == 0) || (puVar5[2] != -1)) {
      iVar8 = 1;
    }
    iVar2 = piVar1[5];
    iVar3 = *piVar1;
    pfVar6 = (float *)*puVar5;
    if (iVar3 == 1) {
      if (iVar8 == 0) {
        return 0;
      }
      puVar7 = param_3;
      param_3 = (uint *)iVar8;
      do {
        if (iVar2 != 0) {
          iVar8 = iVar2;
          do {
            fVar4 = *pfVar6;
            pfVar6 = pfVar6 + 1;
            *puVar7 = (uint)(fVar4 != 0.0);
            puVar7 = puVar7 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
        pfVar6 = pfVar6 + (4 - iVar2);
        param_3 = (uint *)((int)param_3 + -1);
      } while (param_3 != (uint *)0x0);
      return 0;
    }
    if (iVar3 == 2) {
      if (iVar8 == 0) {
        return 0;
      }
      puVar7 = param_3;
      param_3 = (uint *)iVar8;
      do {
        if (iVar2 != 0) {
          iVar8 = iVar2;
          do {
            fVar4 = *pfVar6;
            pfVar6 = pfVar6 + 1;
            *puVar7 = (uint)(fVar4 != 0.0);
            puVar7 = puVar7 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
        pfVar6 = pfVar6 + (4 - iVar2);
        param_3 = (uint *)((int)param_3 + -1);
      } while (param_3 != (uint *)0x0);
      return 0;
    }
    if (iVar3 == 3) {
      if (iVar8 == 0) {
        return 0;
      }
      puVar7 = param_3;
      param_3 = (uint *)iVar8;
      do {
        if (iVar2 != 0) {
          iVar8 = iVar2;
          do {
            *puVar7 = (uint)(DAT_0099cdc8 != *pfVar6);
            puVar7 = puVar7 + 1;
            pfVar6 = pfVar6 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
        pfVar6 = pfVar6 + (4 - iVar2);
        param_3 = (uint *)((int)param_3 + -1);
      } while (param_3 != (uint *)0x0);
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== FUN_008e8d17 @ 0x008e8d17 ====

undefined4 FUN_008e8d17(int param_1,uint param_2,float *param_3,int param_4)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  float *pfVar7;
  float *pfVar8;
  uint uVar9;
  int local_18;
  uint local_14;
  int *local_10;
  uint local_8;
  
  if ((int)param_2 < 0) {
    local_10 = (int *)~param_2;
  }
  else {
    piVar4 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar4 + 4) = 0;
    *(undefined4 *)*piVar4 = 2;
    *(int *)(*piVar4 + 0x10) = param_4;
    *(undefined4 *)(*piVar4 + 0x14) = 1;
    *(undefined4 *)(*piVar4 + 0x18) = 1;
    local_10 = (int *)FUN_008e606c(param_2,1,1);
    if (local_10 == (int *)0x0) {
      return 0x8876086c;
    }
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    uVar5 = FUN_008e06db(~(uint)local_10,param_3,param_4);
    return uVar5;
  }
  piVar4 = (int *)local_10[1];
  iVar2 = piVar4[1];
  if (iVar2 < 0) {
    return 0x8876086c;
  }
  if (1 < iVar2) {
    if (iVar2 == 2) {
      param_2 = piVar4[4];
      uVar3 = piVar4[5];
      uVar6 = piVar4[6];
      if ((param_2 == 0) || (local_10[2] != -1)) {
        param_2 = 1;
      }
      iVar2 = *piVar4;
      local_18 = *local_10;
      if (iVar2 == 1) {
        local_14 = 0;
        if (param_2 != 0) {
          pfVar8 = param_3;
          do {
            if (param_4 == 0) break;
            param_3 = (float *)0x0;
            if (uVar6 != 0) {
              do {
                local_8 = 0;
                if (uVar3 != 0) {
                  pfVar7 = pfVar8 + (int)param_3;
                  do {
                    if (param_4 == 0) break;
                    iVar2 = local_8 + (int)param_3 * 4;
                    param_4 = param_4 + -1;
                    local_8 = local_8 + 1;
                    *(uint *)(local_18 + iVar2 * 4) = (uint)(*pfVar7 != 0.0);
                    pfVar7 = pfVar7 + uVar6;
                  } while (local_8 < uVar3);
                }
                param_3 = (float *)((int)param_3 + 1);
              } while (param_3 < uVar6);
            }
            local_18 = local_18 + 0x40;
            local_14 = local_14 + 1;
            pfVar8 = pfVar8 + uVar6 * uVar3;
          } while (local_14 < param_2);
        }
      }
      else if (iVar2 == 2) {
        local_14 = 0;
        if (param_2 != 0) {
          pfVar8 = param_3;
          do {
            if (param_4 == 0) break;
            param_3 = (float *)0x0;
            if (uVar6 != 0) {
              do {
                local_8 = 0;
                if (uVar3 != 0) {
                  pfVar7 = pfVar8 + (int)param_3;
                  do {
                    if (param_4 == 0) break;
                    param_4 = param_4 + -1;
                    uVar9 = local_8 + 1;
                    *(float *)(local_18 + (local_8 + (int)param_3 * 4) * 4) = *pfVar7;
                    pfVar7 = pfVar7 + uVar6;
                    local_8 = uVar9;
                  } while (uVar9 < uVar3);
                }
                param_3 = (float *)((int)param_3 + 1);
              } while (param_3 < uVar6);
            }
            local_18 = local_18 + 0x40;
            local_14 = local_14 + 1;
            pfVar8 = pfVar8 + uVar6 * uVar3;
          } while (local_14 < param_2);
        }
      }
      else {
        if (iVar2 != 3) {
          return 0x80004005;
        }
        local_8 = 0;
        if (param_2 != 0) {
          pfVar8 = param_3;
          do {
            if (param_4 == 0) break;
            param_3 = (float *)0x0;
            if (uVar6 != 0) {
              do {
                uVar9 = 0;
                if (uVar3 != 0) {
                  pfVar7 = pfVar8 + (int)param_3;
                  do {
                    if (param_4 == 0) break;
                    param_4 = param_4 + -1;
                    *(float *)(local_18 + (uVar9 + (int)param_3 * 4) * 4) = (float)(int)*pfVar7;
                    pfVar7 = pfVar7 + uVar6;
                    uVar9 = uVar9 + 1;
                  } while (uVar9 < uVar3);
                }
                param_3 = (float *)((int)param_3 + 1);
              } while (param_3 < uVar6);
            }
            local_18 = local_18 + 0x40;
            local_8 = local_8 + 1;
            pfVar8 = pfVar8 + uVar6 * uVar3;
          } while (local_8 < param_2);
        }
      }
      goto LAB_008e905c;
    }
    if (iVar2 != 3) {
      return 0x8876086c;
    }
  }
  param_2 = piVar4[4];
  if ((param_2 == 0) || (local_10[2] != -1)) {
    param_2 = 1;
  }
  uVar3 = piVar4[5];
  iVar2 = *piVar4;
  pfVar8 = (float *)*local_10;
  if (iVar2 == 1) {
    uVar6 = 0;
    if (param_2 != 0) {
      do {
        uVar9 = 0;
        if (param_4 == 0) break;
        if (uVar3 != 0) {
          do {
            if (param_4 == 0) break;
            fVar1 = *param_3;
            param_3 = param_3 + 1;
            param_4 = param_4 + -1;
            *pfVar8 = (float)(uint)(fVar1 != 0.0);
            pfVar8 = pfVar8 + 1;
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar3);
        }
        uVar6 = uVar6 + 1;
        pfVar8 = pfVar8 + (4 - uVar3);
      } while (uVar6 < param_2);
    }
  }
  else if (iVar2 == 2) {
    uVar6 = 0;
    if (param_2 != 0) {
      do {
        uVar9 = 0;
        if (param_4 == 0) break;
        if (uVar3 != 0) {
          do {
            if (param_4 == 0) break;
            fVar1 = *param_3;
            param_3 = param_3 + 1;
            param_4 = param_4 + -1;
            *pfVar8 = fVar1;
            pfVar8 = pfVar8 + 1;
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar3);
        }
        uVar6 = uVar6 + 1;
        pfVar8 = pfVar8 + (4 - uVar3);
      } while (uVar6 < param_2);
    }
  }
  else {
    if (iVar2 != 3) {
      return 0x8876086c;
    }
    uVar6 = 0;
    if (param_2 != 0) {
      do {
        uVar9 = 0;
        if (param_4 == 0) break;
        if (uVar3 != 0) {
          do {
            if (param_4 == 0) break;
            fVar1 = *param_3;
            param_3 = param_3 + 1;
            param_4 = param_4 + -1;
            *pfVar8 = (float)(int)fVar1;
            pfVar8 = pfVar8 + 1;
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar3);
        }
        uVar6 = uVar6 + 1;
        pfVar8 = pfVar8 + (4 - uVar3);
      } while (uVar6 < param_2);
    }
  }
LAB_008e905c:
  uVar5 = FUN_008da8ec(local_10);
  return uVar5;
}


// ==== FUN_008e906c @ 0x008e906c ====

undefined4 FUN_008e906c(undefined4 param_1,int param_2,uint *param_3,uint *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  int local_20;
  int local_1c;
  int local_18;
  uint *local_14;
  uint *local_c;
  
  if (param_4 == (uint *)0x0) {
    return 0;
  }
  if (param_3 == (uint *)0x0) {
    return 0x8876086c;
  }
  puVar4 = (undefined4 *)FUN_008e606c(param_2,1,0);
  if (puVar4 == (undefined4 *)0x0) {
    return 0x8876086c;
  }
  piVar1 = (int *)puVar4[1];
  iVar2 = piVar1[1];
  if (-1 < iVar2) {
    if (1 < iVar2) {
      if (iVar2 == 2) {
        local_20 = piVar1[4];
        if ((local_20 == 0) || (puVar4[2] != -1)) {
          local_20 = 1;
        }
        iVar2 = piVar1[5];
        iVar8 = piVar1[6];
        iVar3 = *piVar1;
        param_4 = (uint *)*puVar4;
        local_18 = local_20;
        if (iVar3 == 1) {
          if (local_20 == 0) {
            return 0;
          }
          do {
            if (iVar8 != 0) {
              local_14 = param_3;
              param_1 = param_4;
              local_1c = iVar8;
              do {
                if (iVar2 != 0) {
                  puVar6 = param_1;
                  puVar7 = local_14;
                  local_20 = iVar2;
                  do {
                    uVar5 = *puVar6;
                    puVar6 = puVar6 + 1;
                    *puVar7 = (uint)(uVar5 != 0);
                    puVar7 = puVar7 + iVar8;
                    local_20 = local_20 + -1;
                  } while (local_20 != 0);
                }
                param_1 = param_1 + 4;
                local_14 = local_14 + 1;
                local_1c = local_1c + -1;
              } while (local_1c != 0);
            }
            param_4 = param_4 + 0x10;
            param_3 = param_3 + iVar8 * iVar2;
            local_18 = local_18 + -1;
          } while (local_18 != 0);
          return 0;
        }
        if (iVar3 == 2) {
          if (local_20 == 0) {
            return 0;
          }
          do {
            if (iVar8 != 0) {
              local_14 = param_3;
              param_1 = param_4;
              local_1c = iVar8;
              do {
                if (iVar2 != 0) {
                  puVar6 = param_1;
                  puVar7 = local_14;
                  local_20 = iVar2;
                  do {
                    *puVar7 = *puVar6;
                    puVar6 = puVar6 + 1;
                    puVar7 = puVar7 + iVar8;
                    local_20 = local_20 + -1;
                  } while (local_20 != 0);
                }
                param_1 = param_1 + 4;
                local_14 = local_14 + 1;
                local_1c = local_1c + -1;
              } while (local_1c != 0);
            }
            param_4 = param_4 + 0x10;
            param_3 = param_3 + iVar8 * iVar2;
            local_18 = local_18 + -1;
          } while (local_18 != 0);
          return 0;
        }
        if (iVar3 != 3) {
          return 0x80004005;
        }
        if (local_20 == 0) {
          return 0;
        }
        do {
          if (iVar8 != 0) {
            local_14 = param_3;
            local_1c = iVar8;
            do {
              if (iVar2 != 0) {
                local_c = local_14;
                local_18 = iVar2;
                do {
                  uVar5 = __ftol();
                  local_18 = local_18 + -1;
                  *local_c = uVar5;
                  local_c = local_c + iVar8;
                } while (local_18 != 0);
              }
              local_14 = local_14 + 1;
              local_1c = local_1c + -1;
            } while (local_1c != 0);
          }
          param_3 = param_3 + iVar8 * iVar2;
          local_20 = local_20 + -1;
        } while (local_20 != 0);
        return 0;
      }
      if (iVar2 != 3) {
        return 0x8876086c;
      }
    }
    param_2 = piVar1[4];
    if ((param_2 == 0) || (puVar4[2] != -1)) {
      param_2 = 1;
    }
    iVar2 = piVar1[5];
    iVar8 = *piVar1;
    puVar6 = (uint *)*puVar4;
    param_4 = (uint *)param_2;
    if (iVar8 == 1) {
      if (param_2 == 0) {
        return 0;
      }
      do {
        if (iVar2 != 0) {
          iVar8 = iVar2;
          do {
            uVar5 = *puVar6;
            puVar7 = param_3 + 1;
            puVar6 = puVar6 + 1;
            iVar8 = iVar8 + -1;
            *param_3 = (uint)(uVar5 != 0);
            param_3 = puVar7;
          } while (iVar8 != 0);
        }
        puVar6 = puVar6 + (4 - iVar2);
        param_4 = (uint *)((int)param_4 + -1);
      } while (param_4 != (uint *)0x0);
      return 0;
    }
    if (iVar8 == 2) {
      if (param_2 == 0) {
        return 0;
      }
      do {
        if (iVar2 != 0) {
          iVar8 = iVar2;
          do {
            *param_3 = *puVar6;
            param_3 = param_3 + 1;
            puVar6 = puVar6 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
        puVar6 = puVar6 + (4 - iVar2);
        param_4 = (uint *)((int)param_4 + -1);
      } while (param_4 != (uint *)0x0);
      return 0;
    }
    if (iVar8 == 3) {
      if (param_2 == 0) {
        return 0;
      }
      do {
        if (iVar2 != 0) {
          param_4 = (uint *)iVar2;
          do {
            uVar5 = __ftol();
            puVar6 = param_3 + 1;
            param_4 = (uint *)((int)param_4 + -1);
            *param_3 = uVar5;
            param_3 = puVar6;
          } while (param_4 != (uint *)0x0);
        }
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== FUN_008e9336 @ 0x008e9336 ====

undefined4 FUN_008e9336(int param_1,uint param_2,float *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  float *pfVar5;
  uint uVar6;
  float fVar7;
  float *pfVar8;
  uint uVar9;
  int *local_18;
  float *local_14;
  uint local_10;
  uint local_c;
  
  if ((int)param_2 < 0) {
    local_18 = (int *)~param_2;
  }
  else {
    piVar1 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar1 + 4) = 0;
    *(undefined4 *)*piVar1 = 3;
    *(int *)(*piVar1 + 0x10) = param_4;
    *(undefined4 *)(*piVar1 + 0x14) = 1;
    *(undefined4 *)(*piVar1 + 0x18) = 1;
    local_18 = (int *)FUN_008e606c(param_2,1,1);
    if (local_18 == (int *)0x0) {
      return 0x8876086c;
    }
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    uVar4 = FUN_008e0784(~(uint)local_18,param_3,param_4);
    return uVar4;
  }
  piVar1 = (int *)local_18[1];
  iVar2 = piVar1[1];
  if (iVar2 < 0) {
    return 0x8876086c;
  }
  if (1 < iVar2) {
    if (iVar2 == 2) {
      uVar3 = piVar1[5];
      local_10 = piVar1[4];
      uVar9 = piVar1[6];
      if ((local_10 == 0) || (local_18[2] != -1)) {
        local_10 = 1;
      }
      iVar2 = *piVar1;
      param_2 = *local_18;
      if (iVar2 == 1) {
        local_c = 0;
        if (local_10 != 0) {
          pfVar8 = param_3;
          do {
            if (param_4 == 0) break;
            param_3 = (float *)0x0;
            if (uVar9 != 0) {
              do {
                uVar6 = 0;
                if (uVar3 != 0) {
                  local_14 = pfVar8 + (int)param_3;
                  do {
                    if (param_4 == 0) break;
                    param_4 = param_4 + -1;
                    *(uint *)(param_2 + (uVar6 + (int)param_3 * 4) * 4) =
                         (uint)(DAT_0099cdc8 != *local_14);
                    local_14 = local_14 + uVar9;
                    uVar6 = uVar6 + 1;
                  } while (uVar6 < uVar3);
                }
                param_3 = (float *)((int)param_3 + 1);
              } while (param_3 < uVar9);
            }
            param_2 = param_2 + 0x40;
            local_c = local_c + 1;
            pfVar8 = pfVar8 + uVar9 * uVar3;
          } while (local_c < local_10);
        }
      }
      else if (iVar2 == 2) {
        local_14 = (float *)0x0;
        if (local_10 != 0) {
          do {
            if (param_4 == 0) break;
            param_3 = (float *)0x0;
            if (uVar9 != 0) {
              do {
                local_c = 0;
                if (uVar3 != 0) {
                  do {
                    if (param_4 == 0) break;
                    uVar4 = __ftol();
                    param_4 = param_4 + -1;
                    uVar6 = local_c + 1;
                    *(undefined4 *)(param_2 + (local_c + (int)param_3 * 4) * 4) = uVar4;
                    local_c = uVar6;
                  } while (uVar6 < uVar3);
                }
                param_3 = (float *)((int)param_3 + 1);
              } while (param_3 < uVar9);
            }
            param_2 = param_2 + 0x40;
            local_14 = (float *)((int)local_14 + 1);
          } while (local_14 < local_10);
        }
      }
      else {
        if (iVar2 != 3) {
          return 0x80004005;
        }
        local_c = 0;
        if (local_10 != 0) {
          pfVar8 = param_3;
          do {
            if (param_4 == 0) break;
            param_3 = (float *)0x0;
            if (uVar9 != 0) {
              do {
                uVar6 = 0;
                if (uVar3 != 0) {
                  pfVar5 = pfVar8 + (int)param_3;
                  do {
                    if (param_4 == 0) break;
                    param_4 = param_4 + -1;
                    *(float *)(param_2 + (uVar6 + (int)param_3 * 4) * 4) = *pfVar5;
                    uVar6 = uVar6 + 1;
                    pfVar5 = pfVar5 + uVar9;
                  } while (uVar6 < uVar3);
                }
                param_3 = (float *)((int)param_3 + 1);
              } while (param_3 < uVar9);
            }
            param_2 = param_2 + 0x40;
            local_c = local_c + 1;
            pfVar8 = pfVar8 + uVar9 * uVar3;
          } while (local_c < local_10);
        }
      }
      goto LAB_008e96bc;
    }
    if (iVar2 != 3) {
      return 0x8876086c;
    }
  }
  param_2 = piVar1[4];
  if ((param_2 == 0) || (local_18[2] != -1)) {
    param_2 = 1;
  }
  uVar3 = piVar1[5];
  iVar2 = *piVar1;
  pfVar8 = (float *)*local_18;
  if (iVar2 == 1) {
    uVar9 = 0;
    if (param_2 != 0) {
      do {
        uVar6 = 0;
        if (param_4 == 0) break;
        if (uVar3 != 0) {
          do {
            if (param_4 == 0) break;
            fVar7 = *param_3;
            param_3 = param_3 + 1;
            param_4 = param_4 + -1;
            *pfVar8 = (float)(uint)(DAT_0099cdc8 != fVar7);
            pfVar8 = pfVar8 + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar3);
        }
        uVar9 = uVar9 + 1;
        pfVar8 = pfVar8 + (4 - uVar3);
      } while (uVar9 < param_2);
    }
  }
  else if (iVar2 == 2) {
    local_14 = (float *)0x0;
    if (param_2 != 0) {
      do {
        uVar9 = 0;
        if (param_4 == 0) break;
        if (uVar3 != 0) {
          do {
            if (param_4 == 0) break;
            fVar7 = (float)__ftol();
            param_4 = param_4 + -1;
            *pfVar8 = fVar7;
            pfVar8 = pfVar8 + 1;
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar3);
        }
        local_14 = (float *)((int)local_14 + 1);
        pfVar8 = pfVar8 + (4 - uVar3);
      } while (local_14 < param_2);
    }
  }
  else {
    if (iVar2 != 3) {
      return 0x8876086c;
    }
    uVar9 = 0;
    if (param_2 != 0) {
      do {
        uVar6 = 0;
        if (param_4 == 0) break;
        if (uVar3 != 0) {
          do {
            if (param_4 == 0) break;
            fVar7 = *param_3;
            param_3 = param_3 + 1;
            param_4 = param_4 + -1;
            *pfVar8 = fVar7;
            pfVar8 = pfVar8 + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar3);
        }
        uVar9 = uVar9 + 1;
        pfVar8 = pfVar8 + (4 - uVar3);
      } while (uVar9 < param_2);
    }
  }
LAB_008e96bc:
  uVar4 = FUN_008da8ec(local_18);
  return uVar4;
}


// ==== FUN_008e96cc @ 0x008e96cc ====

undefined4 FUN_008e96cc(undefined4 param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  int local_18;
  int local_14;
  int local_10;
  
  if (param_4 == (float *)0x0) {
    return 0;
  }
  if (param_3 == (float *)0x0) {
    return 0x8876086c;
  }
  puVar4 = (undefined4 *)FUN_008e606c(param_2,1,0);
  if (puVar4 == (undefined4 *)0x0) {
    return 0x8876086c;
  }
  piVar2 = (int *)puVar4[1];
  iVar3 = piVar2[1];
  if (-1 < iVar3) {
    if (1 < iVar3) {
      if (iVar3 == 2) {
        local_18 = piVar2[4];
        if ((local_18 == 0) || (puVar4[2] != -1)) {
          local_18 = 1;
        }
        iVar3 = piVar2[5];
        iVar7 = piVar2[6];
        iVar6 = *piVar2;
        param_4 = (float *)*puVar4;
        if (iVar6 == 1) {
          if (local_18 == 0) {
            return 0;
          }
          local_10 = local_18;
          do {
            if (iVar7 != 0) {
              param_1 = param_3;
              param_2 = param_4;
              local_14 = iVar7;
              do {
                if (iVar3 != 0) {
                  pfVar5 = param_2;
                  pfVar8 = param_1;
                  local_18 = iVar3;
                  do {
                    fVar1 = *pfVar5;
                    pfVar5 = pfVar5 + 1;
                    *pfVar8 = (float)(fVar1 != 0.0);
                    pfVar8 = pfVar8 + iVar7;
                    local_18 = local_18 + -1;
                  } while (local_18 != 0);
                }
                param_2 = param_2 + 4;
                param_1 = param_1 + 1;
                local_14 = local_14 + -1;
              } while (local_14 != 0);
            }
            param_4 = param_4 + 0x10;
            param_3 = param_3 + iVar7 * iVar3;
            local_10 = local_10 + -1;
          } while (local_10 != 0);
          return 0;
        }
        if (iVar6 == 2) {
          if (local_18 == 0) {
            return 0;
          }
          local_14 = local_18;
          do {
            if (iVar7 != 0) {
              param_1 = param_3;
              param_2 = param_4;
              local_18 = iVar7;
              do {
                if (iVar3 != 0) {
                  iVar6 = iVar3;
                  pfVar5 = param_2;
                  pfVar8 = param_1;
                  do {
                    fVar1 = *pfVar5;
                    pfVar5 = pfVar5 + 1;
                    *pfVar8 = (float)(int)fVar1;
                    pfVar8 = pfVar8 + iVar7;
                    iVar6 = iVar6 + -1;
                  } while (iVar6 != 0);
                }
                param_2 = param_2 + 4;
                param_1 = param_1 + 1;
                local_18 = local_18 + -1;
              } while (local_18 != 0);
            }
            param_4 = param_4 + 0x10;
            param_3 = param_3 + iVar7 * iVar3;
            local_14 = local_14 + -1;
          } while (local_14 != 0);
          return 0;
        }
        if (iVar6 != 3) {
          return 0x80004005;
        }
        if (local_18 == 0) {
          return 0;
        }
        do {
          if (iVar7 != 0) {
            param_1 = param_3;
            param_2 = param_4;
            local_14 = iVar7;
            do {
              if (iVar3 != 0) {
                pfVar5 = param_2;
                pfVar8 = param_1;
                local_10 = iVar3;
                do {
                  *pfVar8 = *pfVar5;
                  pfVar5 = pfVar5 + 1;
                  pfVar8 = pfVar8 + iVar7;
                  local_10 = local_10 + -1;
                } while (local_10 != 0);
              }
              param_2 = param_2 + 4;
              param_1 = param_1 + 1;
              local_14 = local_14 + -1;
            } while (local_14 != 0);
          }
          param_4 = param_4 + 0x10;
          param_3 = param_3 + iVar7 * iVar3;
          local_18 = local_18 + -1;
        } while (local_18 != 0);
        return 0;
      }
      if (iVar3 != 3) {
        return 0x8876086c;
      }
    }
    param_4 = (float *)piVar2[4];
    if ((param_4 == (float *)0x0) || (puVar4[2] != -1)) {
      param_4 = (float *)0x1;
    }
    iVar3 = piVar2[5];
    iVar7 = *piVar2;
    pfVar5 = (float *)*puVar4;
    if (iVar7 == 1) {
      if (param_4 == (float *)0x0) {
        return 0;
      }
      do {
        if (iVar3 != 0) {
          iVar7 = iVar3;
          do {
            fVar1 = *pfVar5;
            pfVar5 = pfVar5 + 1;
            pfVar8 = param_3 + 1;
            iVar7 = iVar7 + -1;
            *param_3 = (float)(fVar1 != 0.0);
            param_3 = pfVar8;
          } while (iVar7 != 0);
        }
        pfVar5 = pfVar5 + (4 - iVar3);
        param_4 = (float *)((int)param_4 + -1);
      } while (param_4 != (float *)0x0);
      return 0;
    }
    if (iVar7 == 2) {
      if (param_4 == (float *)0x0) {
        return 0;
      }
      do {
        if (iVar3 != 0) {
          iVar7 = iVar3;
          do {
            fVar1 = *pfVar5;
            pfVar5 = pfVar5 + 1;
            *param_3 = (float)(int)fVar1;
            param_3 = param_3 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        pfVar5 = pfVar5 + (4 - iVar3);
        param_4 = (float *)((int)param_4 + -1);
      } while (param_4 != (float *)0x0);
      return 0;
    }
    if (iVar7 == 3) {
      if (param_4 == (float *)0x0) {
        return 0;
      }
      do {
        if (iVar3 != 0) {
          iVar7 = iVar3;
          do {
            *param_3 = *pfVar5;
            param_3 = param_3 + 1;
            pfVar5 = pfVar5 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        pfVar5 = pfVar5 + (4 - iVar3);
        param_4 = (float *)((int)param_4 + -1);
      } while (param_4 != (float *)0x0);
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== FUN_008e996f @ 0x008e996f ====

undefined4 FUN_008e996f(int param_1,uint param_2,float param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((int)param_2 < 0) {
    puVar4 = (undefined4 *)~param_2;
  }
  else {
    piVar1 = (int *)(param_1 + 0xc4);
    *(undefined4 *)(*piVar1 + 4) = 0;
    *(undefined4 *)*piVar1 = 3;
    *(undefined4 *)(*piVar1 + 0x10) = 0;
    *(undefined4 *)(*piVar1 + 0x14) = 1;
    *(undefined4 *)(*piVar1 + 0x18) = 1;
    puVar4 = (undefined4 *)FUN_008e606c(param_2,1,1);
    if (puVar4 == (undefined4 *)0x0) {
      return 0x8876086c;
    }
  }
  piVar1 = (int *)puVar4[1];
  if ((piVar1[4] != 0) && (puVar4[2] == -1)) {
    return 0x8876086c;
  }
  if (*(int *)(param_1 + 0x3c) == 3) {
    uVar2 = FUN_008e058a(~(uint)puVar4,param_3);
  }
  else {
    if (piVar1[1] < 0) {
      return 0x8876086c;
    }
    if (3 < piVar1[1]) {
      return 0x8876086c;
    }
    if (piVar1[5] != 1) {
      return 0x8876086c;
    }
    if (piVar1[6] != 1) {
      return 0x8876086c;
    }
    iVar3 = *piVar1;
    if (iVar3 == 1) {
      if (*(uint *)*puVar4 == (uint)(DAT_0099cdc8 != param_3)) {
        return 0;
      }
      *(uint *)*puVar4 = (uint)(DAT_0099cdc8 != param_3);
    }
    else if (iVar3 == 2) {
      piVar1 = (int *)*puVar4;
      iVar3 = __ftol();
      if (*piVar1 == iVar3) {
        return 0;
      }
      *piVar1 = iVar3;
    }
    else {
      if (iVar3 != 3) {
        return 0x8876086c;
      }
      if (*(float *)*puVar4 == param_3) {
        return 0;
      }
      *(float *)*puVar4 = param_3;
    }
    uVar2 = FUN_008da8ec(puVar4);
  }
  return uVar2;
}


// ==== FUN_008e9a99 @ 0x008e9a99 ====

undefined4 FUN_008e9a99(undefined4 param_1,undefined4 param_2,float *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  if (((((param_3 == (float *)0x0) ||
        (puVar3 = (undefined4 *)FUN_008e606c(param_2,1,0), puVar3 == (undefined4 *)0x0)) ||
       ((piVar1 = (int *)puVar3[1], piVar1[4] != 0 && (puVar3[2] == -1)))) ||
      (((piVar1[1] < 0 || (3 < piVar1[1])) || (piVar1[5] != 1)))) || (piVar1[6] != 1)) {
    return 0x8876086c;
  }
  iVar2 = *piVar1;
  if (iVar2 == 1) {
    uVar4 = (uint)(*(int *)*puVar3 != 0);
  }
  else {
    if (iVar2 != 2) {
      if (iVar2 == 3) {
        *param_3 = *(float *)*puVar3;
        return 0;
      }
      return 0x8876086c;
    }
    uVar4 = *(uint *)*puVar3;
  }
  *param_3 = (float)(int)uVar4;
  return 0;
}


// ==== FUN_008e9b1a @ 0x008e9b1a ====

int FUN_008e9b1a(uint param_1,uint *param_2,int *param_3,uint *param_4)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  ushort uVar4;
  uint *puVar5;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  int extraout_EAX;
  uint uVar9;
  int *piVar10;
  undefined4 *puVar11;
  int extraout_EAX_00;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int in_ECX;
  uint uVar15;
  int iVar16;
  int iVar17;
  short *psVar18;
  int iVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  int iVar22;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar5 = param_4;
  if ((param_1 == 0) || (param_3 == (int *)0x0)) {
    iVar7 = -0x7789f794;
    goto LAB_008eaab6;
  }
  pvVar6 = operator_new(0x1c);
  *(void **)(in_ECX + 0xc4) = pvVar6;
  if (pvVar6 == (void *)0x0) goto LAB_008e9b4e;
  iVar7 = FUN_008d5cc2();
  if (iVar7 < 0) goto LAB_008eaab6;
  puVar11 = *(undefined4 **)(in_ECX + 0xc4);
  for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  }
  *(uint **)(in_ECX + 0x38) = param_2;
  if (param_2 != (uint *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  FUN_008d8921(param_1);
  *(int **)(in_ECX + 0x28) = param_3;
  (**(code **)(*param_3 + 4))(param_3);
  param_1 = *param_4;
  uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
  if (param_1 + 1 <= uVar8) {
    param_1 = *param_4;
    iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
    param_2 = *(uint **)(iVar7 + param_1 * 4);
  }
  *param_4 = param_1 + 1;
  uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
  if (*param_4 + 1 <= uVar8) {
    iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
    *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(iVar7 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if ((param_2 == (uint *)0xfeff0901) &&
     (uVar8 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 <= uVar8)) {
    if (*(void **)(in_ECX + 0x20) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x20));
      return extraout_EAX;
    }
    pvVar6 = operator_new(*(uint *)(in_ECX + 0x1c));
    *(void **)(in_ECX + 0x20) = pvVar6;
    if (pvVar6 == (void *)0x0) goto LAB_008e9b4e;
    if (*(int *)(in_ECX + 0x1c) != 0) {
      uVar8 = *(uint *)(in_ECX + 0x1c);
      uVar9 = (**(code **)(*param_3 + 0x10))(param_3);
      if ((uint)((uVar8 & 3) != 0) + (uVar8 >> 2) + *param_4 <= uVar9) {
        iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
        puVar11 = (undefined4 *)(iVar7 + *param_4 * 4);
        puVar20 = *(undefined4 **)(in_ECX + 0x20);
        for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *puVar20 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar20 = puVar20 + 1;
        }
        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined1 *)puVar20 = *(undefined1 *)puVar11;
          puVar11 = (undefined4 *)((int)puVar11 + 1);
          puVar20 = (undefined4 *)((int)puVar20 + 1);
        }
      }
      *param_4 = *param_4 +
                 (uint)((*(uint *)(in_ECX + 0x1c) & 3) != 0) + (*(uint *)(in_ECX + 0x1c) >> 2);
    }
    uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
    if (*param_4 + 1 <= uVar8) {
      iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
      *(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(iVar7 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;
    uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
    if (*param_4 + 1 <= uVar8) {
      iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
      *(undefined4 *)(in_ECX + 0xa0) = *(undefined4 *)(iVar7 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;
    uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
    if (*param_4 + 1 <= uVar8) {
      iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
      *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(iVar7 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;
    uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
    if (*param_4 + 1 <= uVar8) {
      iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
      *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(iVar7 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;
    uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
    if (((*param_4 <= uVar8) && (3 < *(uint *)(in_ECX + 0x1c))) && (**(int **)(in_ECX + 0x20) == 0))
    {
      iVar7 = *(int *)(in_ECX + 0x34);
      if (iVar7 != 0) {
        piVar10 = operator_new(iVar7 * 100 + 4);
        if (piVar10 == (int *)0x0) {
          piVar10 = (int *)0x0;
        }
        else {
          *piVar10 = iVar7;
          piVar10 = piVar10 + 1;
          FUN_0040d030(piVar10,100,iVar7,FUN_008d5a5e);
        }
        *(int **)(in_ECX + 0x2c) = piVar10;
        if (piVar10 == (int *)0x0) goto LAB_008e9b4e;
      }
      iVar7 = *(int *)(in_ECX + 0x98);
      *(undefined2 *)(in_ECX + 0x30) = 0;
      if (iVar7 != 0) {
        piVar10 = operator_new(iVar7 * 0x50 + 4);
        if (piVar10 == (int *)0x0) {
          piVar10 = (int *)0x0;
        }
        else {
          *piVar10 = iVar7;
          piVar10 = piVar10 + 1;
          FUN_0040d030(piVar10,0x50,iVar7,FUN_008df302);
        }
        *(int **)(in_ECX + 0x9c) = piVar10;
        if (piVar10 == (int *)0x0) goto LAB_008e9b4e;
      }
      iVar7 = *(int *)(in_ECX + 0xa0);
      if (iVar7 != 0) {
        piVar10 = operator_new(iVar7 * 0xb4 + 4);
        if (piVar10 == (int *)0x0) {
          piVar10 = (int *)0x0;
        }
        else {
          *piVar10 = iVar7;
          piVar10 = piVar10 + 1;
          FUN_0040d030(piVar10,0xb4,iVar7,FUN_008de373);
        }
        *(int **)(in_ECX + 0xa4) = piVar10;
        if (piVar10 != (int *)0x0) {
          iVar7 = *(int *)(in_ECX + 0x14);
          if (iVar7 != 0) {
            piVar10 = operator_new(iVar7 * 0x18 + 4);
            if (piVar10 == (int *)0x0) {
              piVar10 = (int *)0x0;
            }
            else {
              *piVar10 = iVar7;
              piVar10 = piVar10 + 1;
              FUN_0040d030(piVar10,0x18,iVar7,&LAB_008d5b22);
            }
            *(int **)(in_ECX + 0x18) = piVar10;
            if (piVar10 == (int *)0x0) goto LAB_008e9b4e;
          }
          uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
          if (uVar8 < *param_4) goto LAB_008ea85e;
          uVar8 = 0;
          *(undefined4 *)(in_ECX + 0xa8) = 1;
          param_2 = (uint *)0x0;
          if (*(int *)(in_ECX + 0x98) != 0) {
            do {
              iVar7 = FUN_008e589e(uVar8 * 0x50 + *(int *)(in_ECX + 0x9c),param_3,param_4);
              if (iVar7 < 0) goto LAB_008eaab6;
              param_2 = (uint *)((int)param_2 + 1);
              uVar8 = (uint)param_2 & 0xffff;
            } while (uVar8 < *(uint *)(in_ECX + 0x98));
          }
          uVar8 = 0;
          uVar1 = 0;
          if (*(int *)(in_ECX + 0xa0) != 0) {
            do {
              *(ushort *)(*(int *)(in_ECX + 0xa4) + 0x14 + uVar8 * 0xb4) = uVar1;
              iVar7 = FUN_008e5a8b(*(int *)(in_ECX + 0xa4) + uVar8 * 0xb4,param_3,param_4);
              if (iVar7 < 0) goto LAB_008eaab6;
              uVar1 = uVar1 + 1;
              uVar8 = (uint)uVar1;
            } while (uVar8 < *(uint *)(in_ECX + 0xa0));
          }
          uVar8 = *(int *)(in_ECX + 300) + *(int *)(in_ECX + 0x1c) + *(int *)(in_ECX + 0x128) + 0x20
                  + *(int *)(in_ECX + 0x124);
          puVar11 = operator_new(uVar8);
          if (puVar11 != (undefined4 *)0x0) {
            uVar9 = *(uint *)(in_ECX + 0x1c);
            puVar20 = *(undefined4 **)(in_ECX + 0x20);
            puVar21 = puVar11;
            for (uVar15 = uVar9 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
              *puVar21 = *puVar20;
              puVar20 = puVar20 + 1;
              puVar21 = puVar21 + 1;
            }
            for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined1 *)puVar21 = *(undefined1 *)puVar20;
              puVar20 = (undefined4 *)((int)puVar20 + 1);
              puVar21 = (undefined4 *)((int)puVar21 + 1);
            }
            uVar8 = uVar8 - *(int *)(in_ECX + 0x1c);
            puVar20 = (undefined4 *)(*(int *)(in_ECX + 0x1c) + (int)puVar11);
            for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *puVar20 = 0;
              puVar20 = puVar20 + 1;
            }
            for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
              *(undefined1 *)puVar20 = 0;
              puVar20 = (undefined4 *)((int)puVar20 + 1);
            }
            local_10 = (((uint)(*(int *)(in_ECX + 0x1c) + (int)puVar11) & 0xffffffe0) - (int)puVar11
                       ) + 0x20;
            local_14 = *(int *)(in_ECX + 0x124) + local_10;
            local_c = *(int *)(in_ECX + 0x128) + local_14;
            if (*(void **)(in_ECX + 0x20) != (void *)0x0) {
              _free(*(void **)(in_ECX + 0x20));
              return extraout_EAX_00;
            }
            *(undefined4 **)(in_ECX + 0x20) = puVar11;
            piVar10 = operator_new(*(int *)(in_ECX + 0xa8) << 2);
            *(int **)(in_ECX + 0xb0) = piVar10;
            if (piVar10 != (int *)0x0) {
              param_2 = (uint *)0x0;
              *piVar10 = in_ECX + 0x48;
              param_1 = 1;
              if (*(int *)(in_ECX + 0x98) != 0) {
                do {
                  uVar8 = param_1 & 0xffff;
                  if (*(uint *)(in_ECX + 0xa8) <= uVar8) break;
                  local_30 = ((uint)param_2 & 0xffff) * 0x50;
                  piVar10 = (int *)(*(int *)(in_ECX + 0x9c) + local_30);
                  *(int **)(*(int *)(in_ECX + 0xb0) + uVar8 * 4) = piVar10;
                  piVar10[5] = uVar8;
                  iVar7 = *(int *)(*(int *)(in_ECX + 0xb0) + uVar8 * 4);
                  if (*(int *)(iVar7 + 0x40) == 0) {
                    iVar16 = *(int *)(in_ECX + 0x20);
                  }
                  else {
                    iVar16 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                  }
                  local_8 = *(int *)(iVar7 + 0x2c) + iVar16 + piVar10[6];
                  iVar7 = *(int *)(*(int *)(in_ECX + 0xb0) + piVar10[5] * 4);
                  if (*(int *)(iVar7 + 0x40) == 0) {
                    local_18 = *(int *)(in_ECX + 0x20);
                  }
                  else {
                    local_18 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                  }
                  local_18 = piVar10[7] + *(int *)(iVar7 + 0x30) + local_18;
                  local_20 = piVar10[0xb];
                  local_1c = piVar10[0xc];
                  *(undefined2 *)(piVar10 + 0x11) = *(undefined2 *)(in_ECX + 0x30);
                  *(undefined2 *)((int)piVar10 + 0x46) = 0;
                  iVar7 = FUN_008df8be(&local_8,&local_18,uVar8);
                  if (iVar7 < 0) goto LAB_008eaab6;
                  if (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + piVar10[5] * 4) + 0x40) == 0) {
                    uVar12 = *(undefined4 *)(in_ECX + 0x20);
                  }
                  else {
                    uVar12 = *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x10);
                  }
                  iVar7 = FUN_008d63c8(uVar12,&local_20,&local_1c);
                  piVar10[3] = iVar7;
                  piVar10[0x12] = 0;
                  iVar7 = *(int *)(*(int *)(in_ECX + 0xb0) + piVar10[5] * 4);
                  if (*(int *)(iVar7 + 0x40) == 0) {
                    iVar16 = *(int *)(in_ECX + 0x20);
                  }
                  else {
                    iVar16 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                  }
                  local_8 = *(int *)(iVar7 + 0x2c) + iVar16 + piVar10[6];
                  iVar7 = *(int *)(local_8 + 0x10);
                  piVar10[0x13] = iVar7;
                  if (iVar7 == 0) {
                    piVar10[0x13] = 1;
                  }
                  iVar7 = FUN_008db8a8(piVar10,&local_14,&local_10,&local_c);
                  if (iVar7 < 0) goto LAB_008eaab6;
                  *piVar10 = *(int *)(in_ECX + 0x20) + piVar10[0xc];
                  piVar10[1] = piVar10[0xb] + *(int *)(in_ECX + 0x20);
                  piVar10 = *(int **)(*(int *)(in_ECX + 0x9c) + 0x3c + local_30);
                  while ((param_1 = param_1 + 1, piVar10 != (int *)0x0 &&
                         (uVar8 = param_1 & 0xffff, uVar8 < *(uint *)(in_ECX + 0xa8)))) {
                    *(int **)(*(int *)(in_ECX + 0xb0) + uVar8 * 4) = piVar10;
                    piVar10[5] = uVar8;
                    iVar7 = *(int *)(*(int *)(in_ECX + 0xb0) + uVar8 * 4);
                    if (*(int *)(iVar7 + 0x40) == 0) {
                      local_2c = *(uint *)(in_ECX + 0x20);
                    }
                    else {
                      local_2c = *(uint *)(*(int *)(in_ECX + 0x38) + 0x10);
                    }
                    local_8 = piVar10[6] + *(int *)(iVar7 + 0x2c) + local_2c;
                    iVar7 = *(int *)(*(int *)(in_ECX + 0xb0) + piVar10[5] * 4);
                    if (*(int *)(iVar7 + 0x40) == 0) {
                      local_18 = *(int *)(in_ECX + 0x20);
                    }
                    else {
                      local_18 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                    }
                    local_18 = piVar10[7] + *(int *)(iVar7 + 0x30) + local_18;
                    local_20 = piVar10[0xb];
                    local_1c = piVar10[0xc];
                    iVar7 = FUN_008db8a8(piVar10,&local_14,&local_10,&local_c);
                    if (iVar7 < 0) goto LAB_008eaab6;
                    *piVar10 = *(int *)(in_ECX + 0x20) + piVar10[0xc];
                    piVar10[1] = piVar10[0xb] + *(int *)(in_ECX + 0x20);
                    uVar2 = *(undefined2 *)(in_ECX + 0x30);
                    *(undefined2 *)((int)piVar10 + 0x46) = 0;
                    *(undefined2 *)(piVar10 + 0x11) = uVar2;
                    iVar7 = FUN_008df8be(&local_8,&local_18,uVar8);
                    if (iVar7 < 0) goto LAB_008eaab6;
                    if (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + piVar10[5] * 4) + 0x40) == 0) {
                      uVar12 = *(undefined4 *)(in_ECX + 0x20);
                    }
                    else {
                      uVar12 = *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x10);
                    }
                    iVar7 = FUN_008d63c8(uVar12,&local_20,&local_1c);
                    piVar10[3] = iVar7;
                    piVar10 = (int *)piVar10[0xf];
                  }
                  param_2 = (uint *)((int)param_2 + 1);
                } while (((uint)param_2 & 0xffff) < *(uint *)(in_ECX + 0x98));
              }
              uVar8 = 0;
              param_2 = (uint *)0x0;
              if (*(int *)(in_ECX + 0xa0) != 0) {
                do {
                  local_28 = uVar8 * 0xb4 + *(int *)(in_ECX + 0xa4);
                  piVar10 = *(int **)(local_28 + 0x30);
                  while ((piVar10 != (int *)0x0 &&
                         (uVar8 = param_1 & 0xffff, uVar8 < *(uint *)(in_ECX + 0xa8)))) {
                    *(int **)(*(int *)(in_ECX + 0xb0) + uVar8 * 4) = piVar10;
                    piVar10[5] = uVar8;
                    iVar7 = *(int *)(*(int *)(in_ECX + 0xb0) + uVar8 * 4);
                    if (*(int *)(iVar7 + 0x40) == 0) {
                      local_1c = *(int *)(in_ECX + 0x20);
                    }
                    else {
                      local_1c = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                    }
                    local_1c = piVar10[6] + *(int *)(iVar7 + 0x2c) + local_1c;
                    iVar7 = *(int *)(*(int *)(in_ECX + 0xb0) + piVar10[5] * 4);
                    if (*(int *)(iVar7 + 0x40) == 0) {
                      iVar16 = *(int *)(in_ECX + 0x20);
                    }
                    else {
                      iVar16 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                    }
                    local_20 = piVar10[7] + *(int *)(iVar7 + 0x30) + iVar16;
                    local_8 = piVar10[0xb];
                    local_18 = piVar10[0xc];
                    iVar7 = FUN_008db8a8(piVar10,&local_14,&local_10,&local_c);
                    if (iVar7 < 0) goto LAB_008eaab6;
                    *piVar10 = piVar10[0xc] + *(int *)(in_ECX + 0x20);
                    piVar10[1] = *(int *)(in_ECX + 0x20) + piVar10[0xb];
                    uVar2 = *(undefined2 *)(in_ECX + 0x30);
                    *(undefined2 *)((int)piVar10 + 0x46) = 0;
                    *(undefined2 *)(piVar10 + 0x11) = uVar2;
                    iVar7 = FUN_008df8be(&local_1c,&local_20,uVar8);
                    if (iVar7 < 0) goto LAB_008eaab6;
                    if (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + piVar10[5] * 4) + 0x40) == 0) {
                      uVar12 = *(undefined4 *)(in_ECX + 0x20);
                    }
                    else {
                      uVar12 = *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x10);
                    }
                    iVar7 = FUN_008d63c8(uVar12,&local_8,&local_18);
                    param_1 = param_1 + 1;
                    piVar10[3] = iVar7;
                    piVar10 = (int *)piVar10[0xf];
                  }
                  local_2c = 0;
                  if (*(int *)(local_28 + 0x34) != 0) {
                    local_24 = 0;
                    do {
                      piVar10 = *(int **)(local_24 + 0x30 + *(int *)(local_28 + 0x38));
                      while ((piVar10 != (int *)0x0 &&
                             (uVar8 = param_1 & 0xffff, uVar8 < *(uint *)(in_ECX + 0xa8)))) {
                        *(int **)(*(int *)(in_ECX + 0xb0) + uVar8 * 4) = piVar10;
                        piVar10[5] = uVar8;
                        iVar7 = *(int *)(*(int *)(in_ECX + 0xb0) + uVar8 * 4);
                        if (*(int *)(iVar7 + 0x40) == 0) {
                          local_30 = *(uint *)(in_ECX + 0x20);
                        }
                        else {
                          local_30 = *(uint *)(*(int *)(in_ECX + 0x38) + 0x10);
                        }
                        local_1c = piVar10[6] + *(int *)(iVar7 + 0x2c) + local_30;
                        iVar7 = *(int *)(*(int *)(in_ECX + 0xb0) + piVar10[5] * 4);
                        if (*(int *)(iVar7 + 0x40) == 0) {
                          iVar16 = *(int *)(in_ECX + 0x20);
                        }
                        else {
                          iVar16 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                        }
                        local_20 = *(int *)(iVar7 + 0x30) + piVar10[7] + iVar16;
                        local_8 = piVar10[0xb];
                        local_18 = piVar10[0xc];
                        iVar7 = FUN_008db8a8(piVar10,&local_14,&local_10,&local_c);
                        if (iVar7 < 0) goto LAB_008eaab6;
                        *piVar10 = piVar10[0xc] + *(int *)(in_ECX + 0x20);
                        piVar10[1] = *(int *)(in_ECX + 0x20) + piVar10[0xb];
                        uVar2 = *(undefined2 *)(in_ECX + 0x30);
                        *(undefined2 *)((int)piVar10 + 0x46) = 0;
                        *(undefined2 *)(piVar10 + 0x11) = uVar2;
                        iVar7 = FUN_008df8be(&local_1c,&local_20,uVar8);
                        if (iVar7 < 0) goto LAB_008eaab6;
                        if (*(int *)(*(int *)(*(int *)(in_ECX + 0xb0) + piVar10[5] * 4) + 0x40) == 0
                           ) {
                          uVar12 = *(undefined4 *)(in_ECX + 0x20);
                        }
                        else {
                          uVar12 = *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x10);
                        }
                        iVar7 = FUN_008d63c8(uVar12,&local_8,&local_18);
                        param_1 = param_1 + 1;
                        piVar10[3] = iVar7;
                        piVar10 = (int *)piVar10[0xf];
                      }
                      local_2c = local_2c + 1;
                      local_24 = local_24 + 0x38;
                    } while (local_2c < *(uint *)(local_28 + 0x34));
                  }
                  param_2 = (uint *)((int)param_2 + 1);
                  uVar8 = (uint)param_2 & 0xffff;
                } while (uVar8 < *(uint *)(in_ECX + 0xa0));
              }
              if ((param_1 & 0xffff) == *(uint *)(in_ECX + 0xa8)) {
                param_1 = *param_4;
                uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
                if (param_1 + 1 <= uVar8) {
                  param_1 = *param_4;
                  iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
                  param_4 = *(uint **)(iVar7 + param_1 * 4);
                }
                *puVar5 = param_1 + 1;
                uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
                uVar9 = param_1 + 2;
                param_1 = param_1 + 1;
                if (uVar9 <= uVar8) {
                  param_1 = *puVar5;
                  iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
                  local_24 = *(uint *)(iVar7 + param_1 * 4);
                }
                *puVar5 = param_1 + 1;
                uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
                if (*puVar5 <= uVar8) {
                  iVar7 = 0;
                  param_2 = (uint *)0x0;
                  if (param_4 != (uint *)0x0) {
                    do {
                      iVar7 = FUN_008d5dc1(param_3,puVar5);
                      if (iVar7 < 0) goto LAB_008eaab6;
                      param_2 = (uint *)((int)param_2 + 1);
                    } while (param_2 < param_4);
                  }
                  param_2 = (uint *)0x0;
                  if (local_24 != 0) {
                    do {
                      param_1 = *puVar5;
                      uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
                      if (param_1 + 1 <= uVar8) {
                        param_1 = *puVar5;
                        iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
                        local_20 = *(uint *)(iVar7 + param_1 * 4);
                      }
                      *puVar5 = param_1 + 1;
                      uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
                      uVar9 = param_1 + 2;
                      param_1 = param_1 + 1;
                      if (uVar9 <= uVar8) {
                        param_1 = *puVar5;
                        iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
                        local_30 = *(uint *)(iVar7 + param_1 * 4);
                      }
                      *puVar5 = param_1 + 1;
                      uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
                      uVar9 = param_1 + 2;
                      param_1 = param_1 + 1;
                      if (uVar9 <= uVar8) {
                        param_1 = *puVar5;
                        iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
                        local_28 = *(uint *)(iVar7 + param_1 * 4);
                      }
                      *puVar5 = param_1 + 1;
                      uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
                      uVar9 = param_1 + 2;
                      param_1 = param_1 + 1;
                      if (uVar9 <= uVar8) {
                        param_1 = *puVar5;
                        iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
                        param_4 = *(uint **)(iVar7 + param_1 * 4);
                      }
                      *puVar5 = param_1 + 1;
                      uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
                      uVar9 = param_1 + 2;
                      param_1 = param_1 + 1;
                      if (uVar9 <= uVar8) {
                        param_1 = *puVar5;
                        iVar7 = (**(code **)(*param_3 + 0xc))(param_3);
                        local_2c = *(uint *)(iVar7 + param_1 * 4);
                      }
                      *puVar5 = param_1 + 1;
                      uVar8 = (**(code **)(*param_3 + 0x10))(param_3);
                      if (uVar8 < *puVar5) goto LAB_008ea85e;
                      if (local_20 == 0xffffffff) {
                        if ((*(uint *)(in_ECX + 0x98) <= local_30) ||
                           (iVar7 = local_30 * 0x50 + *(int *)(in_ECX + 0x9c),
                           *(ushort *)(iVar7 + 0x46) <= local_28)) goto LAB_008ea85e;
                        uVar8 = local_28 + *(ushort *)(iVar7 + 0x44);
                      }
                      else {
                        if (((*(uint *)(in_ECX + 0xa0) <= local_20) ||
                            (iVar7 = local_20 * 0xb4 + *(int *)(in_ECX + 0xa4),
                            *(uint *)(iVar7 + 0x34) <= local_30)) || (local_28 != 0xffffffff))
                        goto LAB_008ea85e;
                        uVar8 = (uint)*(ushort *)(*(int *)(iVar7 + 0x38) + 0x34 + local_30 * 0x38);
                      }
                      if ((uint *)(uint)*(ushort *)(uVar8 * 100 + 0x36 + *(int *)(in_ECX + 0x2c)) <=
                          param_4) goto LAB_008ea85e;
                      iVar7 = *(int *)(&DAT_00a218dc +
                                      (uint)*(ushort *)
                                             (*(int *)(uVar8 * 100 + 4 + *(int *)(in_ECX + 0x2c)) +
                                              0x52 + (int)param_4 * 100) * 0x1c);
                      if ((iVar7 == 5) || (iVar7 == 10)) {
                        if (local_2c == 1) {
LAB_008ea741:
                          iVar7 = FUN_008e67fc(uVar8,param_4,param_3,puVar5);
                        }
                        else {
                          iVar7 = -0x7fffbffb;
                        }
                      }
                      else if ((iVar7 < 0xf) || (0x10 < iVar7)) {
                        iVar7 = FUN_008dbe47(uVar8,param_4,param_3,puVar5);
                      }
                      else if (local_2c == 0) {
                        iVar7 = FUN_008df640(uVar8,param_4,param_3,puVar5);
                      }
                      else {
                        if (local_2c == 1) goto LAB_008ea741;
                        iVar7 = FUN_008e6ac3(uVar8,param_4,param_3,puVar5);
                      }
                      if (iVar7 < 0) goto LAB_008eaab6;
                      param_2 = (uint *)((int)param_2 + 1);
                    } while (param_2 < local_24);
                  }
                  uVar8 = 0;
                  if ((*(int *)(in_ECX + 0x38) != 0) && (uVar9 = 0, *(int *)(in_ECX + 0x98) != 0)) {
                    do {
                      iVar16 = uVar8 * 0x50 + *(int *)(in_ECX + 0x9c);
                      if (((*(uint *)(*(int *)(*(int *)(in_ECX + 0xb0) + *(int *)(iVar16 + 0x14) * 4
                                              ) + 0x28) & 1) != 0) &&
                         (iVar7 = FUN_008bc881(in_ECX,iVar16), iVar7 < 0)) goto LAB_008eaab6;
                      uVar9 = uVar9 + 1;
                      uVar8 = uVar9 & 0xffff;
                    } while (uVar8 < *(uint *)(in_ECX + 0x98));
                  }
                  uVar1 = 0;
                  if (*(short *)(in_ECX + 0x30) != 0) {
                    do {
                      piVar10 = (int *)((uint)uVar1 * 100 + *(int *)(in_ECX + 0x2c));
                      iVar7 = FUN_008d5ac8();
                      if (iVar7 < 0) goto LAB_008eaab6;
                      uVar8 = piVar10[3];
                      puVar11 = (undefined4 *)*piVar10;
                      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                        *puVar11 = 0;
                        puVar11 = puVar11 + 1;
                      }
                      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                        *(undefined1 *)puVar11 = 0;
                        puVar11 = (undefined4 *)((int)puVar11 + 1);
                      }
                      iVar16 = piVar10[5];
                      iVar19 = *piVar10;
                      param_1 = 0;
                      uVar4 = 0;
                      if (*(short *)((int)piVar10 + 0x36) != 0) {
                        do {
                          iVar13 = (uint)uVar4 * 100 + piVar10[1];
                          iVar17 = *(int *)(iVar13 + 0x1c) * 4;
                          iVar14 = *(int *)(iVar17 + *(int *)(in_ECX + 0xb0));
                          if (*(int *)(iVar14 + 0x40) == 0) {
                            iVar22 = *(int *)(in_ECX + 0x20);
                          }
                          else {
                            iVar22 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                          }
                          *(int *)(iVar13 + 8) =
                               *(int *)(iVar14 + 0x30) + *(int *)(iVar13 + 0x24) + iVar22;
                          iVar14 = *(int *)(iVar17 + *(int *)(in_ECX + 0xb0));
                          if (*(int *)(iVar14 + 0x40) == 0) {
                            iVar17 = *(int *)(in_ECX + 0x20);
                          }
                          else {
                            iVar17 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                          }
                          *(int *)(iVar13 + 0xc) =
                               *(int *)(iVar14 + 0x2c) + *(int *)(iVar13 + 0x20) + iVar17;
                          if ((*(int *)(&DAT_00a218ec + (uint)*(ushort *)(iVar13 + 0x52) * 0x1c) ==
                               0xe000000) ||
                             (*(int *)(&DAT_00a218ec + (uint)*(ushort *)(iVar13 + 0x52) * 0x1c) ==
                              0xf000000)) {
                            uVar8 = param_1 & 0xffff;
                            param_1 = param_1 + 1;
                            *(ushort *)(iVar16 + iVar19 + uVar8 * 2) = uVar4;
                            psVar18 = (short *)(*(int *)(iVar13 + 0x48) + *piVar10);
                            if (*(int *)(iVar13 + 0x1c) == 0) {
                              iVar14 = **(int **)(in_ECX + 0xb0);
                              if (*(int *)(iVar14 + 0x40) == 0) {
                                iVar14 = *(int *)(*(int *)(iVar14 + 0x30) + *(int *)(iVar13 + 0x24)
                                                 + *(int *)(in_ECX + 0x20));
                              }
                              else {
                                iVar14 = **(int **)(in_ECX + 0xb0);
                                iVar14 = *(int *)(*(int *)(*(int *)(iVar14 + 0x40) + 8) +
                                                 *(int *)(*(int *)(iVar14 + 0x30) +
                                                          *(int *)(iVar13 + 0x24) +
                                                         *(int *)(*(int *)(in_ECX + 0x38) + 0x10)) *
                                                 4);
                              }
                              sVar3 = *(short *)(*(int *)(in_ECX + 0x18) + 0x10 + iVar14 * 0x18);
                              psVar18[1] = 0;
                              *psVar18 = sVar3 + 1;
                            }
                            else {
                              *psVar18 = *(short *)(*(int *)(*(int *)(in_ECX + 0xb0) +
                                                            *(int *)(iVar13 + 0x1c) * 4) + 0x44) + 1
                              ;
                              psVar18[1] = (short)(*(uint *)(iVar13 + 0x24) >> 2);
                            }
                          }
                          uVar4 = uVar4 + 1;
                        } while (uVar4 < *(ushort *)((int)piVar10 + 0x36));
                      }
                      uVar1 = uVar1 + 1;
                    } while (uVar1 < *(ushort *)(in_ECX + 0x30));
                  }
                  *(undefined2 *)(in_ECX + 0x44) = 0xffff;
                  *(undefined2 *)(in_ECX + 0x40) = 0xffff;
                  *(uint *)(in_ECX + 0x118) = *(uint *)(in_ECX + 0x118) | 0x40;
                  uVar8 = 0;
                  *(undefined4 *)(in_ECX + 0x3c) = 0;
                  *(undefined2 *)(in_ECX + 0x42) = 0;
                  if (*(int *)(in_ECX + 0x98) != 0) {
                    uVar9 = 0;
                    do {
                      iVar19 = uVar9 * 0x50 + *(int *)(in_ECX + 0x9c);
                      iVar16 = **(int **)(iVar19 + 4);
                      if (((iVar16 < 10) || (0xe < iVar16)) &&
                         (iVar7 = FUN_008d4ea9(iVar19), iVar7 < 0)) goto LAB_008eaab6;
                      uVar8 = uVar8 + 1;
                      uVar9 = uVar8 & 0xffff;
                    } while (uVar9 < *(uint *)(in_ECX + 0x98));
                  }
                  uVar1 = 0;
                  if (*(int *)(in_ECX + 0xa8) != 0) {
                    uVar8 = 0;
                    do {
                      piVar10 = *(int **)(*(int *)(in_ECX + 0xb0) + uVar8 * 4);
                      iVar16 = *(int *)(piVar10[5] * 4 + *(int *)(in_ECX + 0xb0));
                      if (*(int *)(iVar16 + 0x40) == 0) {
                        iVar19 = *(int *)(in_ECX + 0x20);
                      }
                      else {
                        iVar19 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                      }
                      *piVar10 = piVar10[7] + *(int *)(iVar16 + 0x30) + iVar19;
                      iVar16 = *(int *)(piVar10[5] * 4 + *(int *)(in_ECX + 0xb0));
                      if (*(int *)(iVar16 + 0x40) == 0) {
                        iVar19 = *(int *)(in_ECX + 0x20);
                      }
                      else {
                        iVar19 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                      }
                      iVar19 = piVar10[6] + *(int *)(iVar16 + 0x2c) + iVar19;
                      while( true ) {
                        piVar10[1] = iVar19;
                        piVar10 = (int *)piVar10[9];
                        if (piVar10 == (int *)0x0) break;
                        iVar16 = *(int *)(piVar10[5] * 4 + *(int *)(in_ECX + 0xb0));
                        if (*(int *)(iVar16 + 0x40) == 0) {
                          iVar19 = *(int *)(in_ECX + 0x20);
                        }
                        else {
                          iVar19 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                        }
                        *piVar10 = piVar10[7] + *(int *)(iVar16 + 0x30) + iVar19;
                        iVar16 = *(int *)(piVar10[5] * 4 + *(int *)(in_ECX + 0xb0));
                        if (*(int *)(iVar16 + 0x40) == 0) {
                          iVar19 = *(int *)(in_ECX + 0x20);
                        }
                        else {
                          iVar19 = *(int *)(*(int *)(in_ECX + 0x38) + 0x10);
                        }
                        iVar19 = piVar10[6] + *(int *)(iVar16 + 0x2c) + iVar19;
                      }
                      uVar1 = uVar1 + 1;
                      uVar8 = (uint)uVar1;
                    } while (uVar8 < *(uint *)(in_ECX + 0xa8));
                  }
                  goto LAB_008eaab6;
                }
              }
              goto LAB_008ea85e;
            }
          }
        }
LAB_008e9b4e:
        iVar7 = -0x7ff8fff2;
        goto LAB_008eaab6;
      }
    }
  }
LAB_008ea85e:
  iVar7 = -0x7fffbffb;
LAB_008eaab6:
  *(undefined4 *)(in_ECX + 0xac) = *(undefined4 *)(in_ECX + 0xa8);
  return iVar7;
}


// ==== FUN_008eaac9 @ 0x008eaac9 ====

int FUN_008eaac9(uint param_1,int param_2,undefined4 *param_3)

{
  uint *puVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  int *local_1c;
  uint local_18;
  int *local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  iVar2 = param_1;
  if (param_3 == (undefined4 *)0x0) {
    return -0x7789f794;
  }
  pvVar3 = operator_new(0x130);
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_008df4d1();
  }
  if (piVar4 == (int *)0x0) {
    return -0x7ff8fff2;
  }
  local_18 = 0;
  if (param_2 == *(int *)(param_1 + 0xc)) {
    *(byte *)((int)piVar4 + 0x119) = *(byte *)((int)piVar4 + 0x119) | 2;
    param_2 = FUN_008e9b1a(param_2,*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x28),
                           &local_18);
    if (param_2 < 0) goto LAB_008eb20c;
    *(byte *)((int)piVar4 + 0x119) = *(byte *)((int)piVar4 + 0x119) & 0xfd;
    param_2 = FUN_008d5cc2();
    if (param_2 < 0) goto LAB_008eb20c;
    *param_3 = 0;
    local_c = 0;
    if (*(int *)(param_1 + 0xa0) != 0) {
      param_1 = 0;
      uVar10 = local_18;
      do {
        local_18 = uVar10;
        if (*(int *)(*(int *)(iVar2 + 0xa4) + 0x88 + param_1) != 0) {
          *(undefined4 *)(piVar4[0x29] + 0x88 + param_1) =
               *(undefined4 *)(*(int *)(iVar2 + 0xa4) + 0x88 + param_1);
          piVar5 = *(int **)(*(int *)(iVar2 + 0xa4) + 0x88 + param_1);
          (**(code **)(*piVar5 + 4))(piVar5);
        }
        iVar9 = param_1 + 0x8c;
        local_18 = 2;
        do {
          if (*(int *)(iVar9 + *(int *)(iVar2 + 0xa4)) != 0) {
            *(undefined4 *)(iVar9 + piVar4[0x29]) = *(undefined4 *)(iVar9 + *(int *)(iVar2 + 0xa4));
            piVar5 = *(int **)(iVar9 + *(int *)(iVar2 + 0xa4));
            (**(code **)(*piVar5 + 4))(piVar5);
          }
          iVar9 = iVar9 + 4;
          local_18 = local_18 - 1;
        } while (local_18 != 0);
        iVar9 = param_1 + 0x94;
        local_18 = 2;
        do {
          if (*(int *)(iVar9 + *(int *)(iVar2 + 0xa4)) != 0) {
            *(undefined4 *)(iVar9 + piVar4[0x29]) = *(undefined4 *)(iVar9 + *(int *)(iVar2 + 0xa4));
            piVar5 = *(int **)(iVar9 + *(int *)(iVar2 + 0xa4));
            (**(code **)(*piVar5 + 4))(piVar5);
          }
          iVar9 = iVar9 + 4;
          local_18 = local_18 - 1;
        } while (local_18 != 0);
        local_c = local_c + 1;
        param_1 = param_1 + 0xb4;
        local_18 = 0;
        uVar10 = 0;
      } while (local_c < *(uint *)(iVar2 + 0xa0));
    }
    param_1 = 0;
    if (*(int *)(iVar2 + 0x14) != 0) {
      iVar9 = 0;
      do {
        piVar5 = (int *)(*(int *)(iVar2 + 0x18) + iVar9);
        if (*piVar5 == 0xf) {
          if (piVar5[1] != 0) {
            piVar5 = *(int **)(iVar9 + 4 + *(int *)(iVar2 + 0x18));
            (**(code **)(*piVar5 + 4))(piVar5);
          }
          piVar5 = (int *)(piVar4[6] + 4 + iVar9);
          if (*piVar5 != 0) {
            piVar5 = (int *)*piVar5;
            (**(code **)(*piVar5 + 8))(piVar5);
            *(undefined4 *)(piVar4[6] + 4 + iVar9) = 0;
          }
          *(undefined4 *)(piVar4[6] + 4 + iVar9) =
               *(undefined4 *)(iVar9 + 4 + *(int *)(iVar2 + 0x18));
          puVar1 = (uint *)(piVar4[6] + 0x14 + iVar9);
          *puVar1 = *puVar1 ^ ((*(int *)(iVar9 + 0x14 + *(int *)(iVar2 + 0x18)) << 0x1e) >> 0x1e ^
                              *puVar1) & 2;
          puVar1 = (uint *)(piVar4[6] + 0x14 + iVar9);
          *puVar1 = *puVar1 | 1;
        }
        piVar5 = (int *)(*(int *)(iVar2 + 0x18) + iVar9);
        if (*piVar5 == 0x10) {
          if (piVar5[1] != 0) {
            piVar5 = *(int **)(iVar9 + 4 + *(int *)(iVar2 + 0x18));
            (**(code **)(*piVar5 + 4))(piVar5);
          }
          piVar5 = (int *)(piVar4[6] + 4 + iVar9);
          if (*piVar5 != 0) {
            piVar5 = (int *)*piVar5;
            (**(code **)(*piVar5 + 8))(piVar5);
            *(undefined4 *)(piVar4[6] + 4 + iVar9) = 0;
          }
          *(undefined4 *)(piVar4[6] + 4 + iVar9) =
               *(undefined4 *)(iVar9 + 4 + *(int *)(iVar2 + 0x18));
          puVar1 = (uint *)(piVar4[6] + 0x14 + iVar9);
          *puVar1 = *puVar1 ^ ((*(int *)(iVar9 + 0x14 + *(int *)(iVar2 + 0x18)) << 0x1e) >> 0x1e ^
                              *puVar1) & 2;
          puVar1 = (uint *)(piVar4[6] + 0x14 + iVar9);
          *puVar1 = *puVar1 | 1;
        }
        param_1 = param_1 + 1;
        iVar9 = iVar9 + 0x18;
      } while (param_1 < *(uint *)(iVar2 + 0x14));
    }
    piVar5 = (int *)(iVar2 + 0x104);
    piVar4[0x41] = *piVar5;
    if (*piVar5 != 0) {
      (**(code **)(*(int *)*piVar5 + 4))((int *)*piVar5);
    }
    FUN_008e5464();
    iVar9 = 0;
    uVar10 = 0;
    if (*(int *)(iVar2 + 0x14) != 0) {
      do {
        piVar5 = (int *)(iVar9 + *(int *)(iVar2 + 0x18));
        if (*piVar5 == 0xf) {
          puVar1 = (uint *)(piVar4[6] + 0x14 + iVar9);
          *puVar1 = *puVar1 ^ ((piVar5[5] << 0x1e) >> 0x1e ^ *puVar1) & 2;
        }
        piVar5 = (int *)(iVar9 + *(int *)(iVar2 + 0x18));
        if (*piVar5 == 0x10) {
          puVar1 = (uint *)(piVar4[6] + 0x14 + iVar9);
          *puVar1 = *puVar1 ^ ((piVar5[5] << 0x1e) >> 0x1e ^ *puVar1) & 2;
        }
        uVar10 = uVar10 + 1;
        iVar9 = iVar9 + 0x18;
      } while (uVar10 < *(uint *)(iVar2 + 0x14));
    }
  }
  else {
    param_2 = FUN_008e9b1a(param_2,*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x28),
                           &local_18);
    if ((param_2 < 0) || (param_2 = FUN_008d5cc2(), param_2 < 0)) goto LAB_008eb20c;
    FUN_008e5464();
  }
  local_c = 0;
  if (*(int *)(iVar2 + 0x98) != 0) {
    local_8 = 0;
    do {
      puVar11 = (undefined4 *)(*(int *)(iVar2 + 0x9c) + local_8);
      param_1 = piVar4[0x27] + local_8;
      local_18 = *(uint *)(*(int *)(iVar2 + 0xb0) + puVar11[5] * 4);
      if (*(int *)(local_18 + 0x40) == 0) {
        iVar9 = *(int *)(iVar2 + 0x20);
      }
      else {
        iVar9 = *(int *)(*(int *)(iVar2 + 0x38) + 0x10);
      }
      if (*(int *)(*(int *)(puVar11[1] + 8) + iVar9) == 0) {
        local_14 = (int *)0x0;
      }
      else {
        if (*(int *)(local_18 + 0x40) == 0) {
          iVar9 = *(int *)(iVar2 + 0x20);
        }
        else {
          iVar9 = *(int *)(*(int *)(iVar2 + 0x38) + 0x10);
        }
        local_14 = (int *)(*(int *)(puVar11[1] + 8) + 4 + iVar9);
      }
      if ((*(uint *)(local_18 + 0x28) & 2) != 0) goto LAB_008eaf0d;
      iVar9 = *(int *)(piVar4[0x2c] + *(int *)(param_1 + 0x14) * 4);
      if (*(int *)(iVar9 + 0x40) == 0) {
        iVar6 = piVar4[8];
      }
      else {
        iVar6 = *(int *)(piVar4[0xe] + 0x10);
      }
      param_2 = FUN_008dc3aa(puVar11[1],*(int *)(iVar9 + 0x30) + *(int *)(param_1 + 0x1c) + iVar6,
                             *puVar11,*(undefined4 *)(param_1 + 0x40),puVar11[0x10],iVar2);
      if (param_2 < 0) goto LAB_008eb20c;
      param_2 = FUN_008da8ec(param_1);
      while( true ) {
        if (param_2 < 0) goto LAB_008eb20c;
LAB_008eaf0d:
        puVar11 = (undefined4 *)puVar11[0xf];
        iVar9 = *(int *)(param_1 + 0x3c);
        if (iVar9 == 0) break;
        iVar6 = *(int *)(piVar4[0x2c] + *(int *)(iVar9 + 0x14) * 4);
        if (*(int *)(iVar6 + 0x40) == 0) {
          iVar8 = piVar4[8];
        }
        else {
          iVar8 = *(int *)(piVar4[0xe] + 0x10);
        }
        param_2 = FUN_008dc3aa(puVar11[1],*(int *)(iVar6 + 0x30) + *(int *)(iVar9 + 0x1c) + iVar8,
                               *puVar11,*(undefined4 *)(iVar9 + 0x40),puVar11[0x10],iVar2);
        param_1 = iVar9;
      }
      for (; puVar11 != (undefined4 *)0x0; puVar11 = (undefined4 *)puVar11[0xf]) {
        param_2 = FUN_008d66a7(local_14,puVar11,piVar4);
        if (param_2 < 0) goto LAB_008eb20c;
        param_1 = *(int *)(param_1 + 0x3c);
        iVar9 = *(int *)(piVar4[0x2c] + *(int *)(param_1 + 0x14) * 4);
        if (*(int *)(iVar9 + 0x40) == 0) {
          iVar6 = piVar4[8];
        }
        else {
          iVar6 = *(int *)(piVar4[0xe] + 0x10);
        }
        param_2 = FUN_008dc3aa(puVar11[1],*(int *)(iVar9 + 0x30) + *(int *)(param_1 + 0x1c) + iVar6,
                               *puVar11,*(undefined4 *)(param_1 + 0x40),puVar11[0x10],iVar2);
        if (param_2 < 0) goto LAB_008eb20c;
      }
      local_c = local_c + 1;
      local_8 = local_8 + 0x50;
    } while (local_c < *(uint *)(iVar2 + 0x98));
  }
  local_18 = 0;
  if (*(int *)(iVar2 + 0xa0) != 0) {
    local_c = 0;
    do {
      iVar9 = *(int *)(iVar2 + 0xa4) + local_c;
      local_10 = piVar4[0x29] + local_c;
      local_14 = (int *)(*(int *)(iVar9 + 0x28) + *(int *)(iVar2 + 0x20));
      if (*local_14 == 0) {
        local_14 = (int *)0x0;
      }
      else {
        local_14 = local_14 + 1;
      }
      piVar5 = (int *)(iVar9 + 0x30);
      puVar11 = (undefined4 *)*piVar5;
      iVar6 = *(int *)(local_10 + 0x30);
      while (iVar6 != 0) {
        iVar8 = *(int *)(piVar4[0x2c] + *(int *)(iVar6 + 0x14) * 4);
        if (*(int *)(iVar8 + 0x40) == 0) {
          iVar7 = piVar4[8];
        }
        else {
          iVar7 = *(int *)(piVar4[0xe] + 0x10);
        }
        param_2 = FUN_008dc3aa(puVar11[1],*(int *)(iVar8 + 0x30) + *(int *)(iVar6 + 0x1c) + iVar7,
                               *puVar11,*(undefined4 *)(iVar6 + 0x40),puVar11[0x10],iVar2);
        if (param_2 < 0) goto LAB_008eb20c;
        puVar11 = (undefined4 *)puVar11[0xf];
        piVar5 = (int *)(iVar6 + 0x3c);
        iVar6 = *piVar5;
      }
      param_1 = *piVar5;
      for (; puVar11 != (undefined4 *)0x0; puVar11 = (undefined4 *)puVar11[0xf]) {
        param_2 = FUN_008d66a7(local_14,puVar11,piVar4);
        if (param_2 < 0) goto LAB_008eb20c;
        param_1 = *(int *)(param_1 + 0x3c);
        iVar6 = *(int *)(piVar4[0x2c] + *(int *)(param_1 + 0x14) * 4);
        if (*(int *)(iVar6 + 0x40) == 0) {
          iVar8 = piVar4[8];
        }
        else {
          iVar8 = *(int *)(piVar4[0xe] + 0x10);
        }
        param_2 = FUN_008dc3aa(puVar11[1],*(int *)(iVar6 + 0x30) + *(int *)(param_1 + 0x1c) + iVar8,
                               *puVar11,*(undefined4 *)(param_1 + 0x40),puVar11[0x10],iVar2);
        if (param_2 < 0) goto LAB_008eb20c;
      }
      local_14 = (int *)0x0;
      if (*(int *)(local_10 + 0x34) != 0) {
        local_8 = 0;
        do {
          iVar6 = *(int *)(iVar9 + 0x38) + local_8;
          local_1c = (int *)(*(int *)(iVar6 + 0x28) + *(int *)(iVar2 + 0x20));
          if (*local_1c == 0) {
            local_1c = (int *)0x0;
          }
          else {
            local_1c = local_1c + 1;
          }
          piVar5 = (int *)(iVar6 + 0x30);
          puVar11 = (undefined4 *)*piVar5;
          iVar6 = *(int *)(*(int *)(local_10 + 0x38) + local_8 + 0x30);
          while (iVar6 != 0) {
            iVar8 = *(int *)(piVar4[0x2c] + *(int *)(iVar6 + 0x14) * 4);
            if (*(int *)(iVar8 + 0x40) == 0) {
              iVar7 = piVar4[8];
            }
            else {
              iVar7 = *(int *)(piVar4[0xe] + 0x10);
            }
            param_2 = FUN_008dc3aa(puVar11[1],
                                   *(int *)(iVar8 + 0x30) + *(int *)(iVar6 + 0x1c) + iVar7,*puVar11,
                                   *(undefined4 *)(iVar6 + 0x40),puVar11[0x10],iVar2);
            if (param_2 < 0) goto LAB_008eb20c;
            puVar11 = (undefined4 *)puVar11[0xf];
            piVar5 = (int *)(iVar6 + 0x3c);
            iVar6 = *piVar5;
          }
          param_1 = *piVar5;
          for (; puVar11 != (undefined4 *)0x0; puVar11 = (undefined4 *)puVar11[0xf]) {
            param_2 = FUN_008d66a7(local_1c,puVar11,piVar4);
            if (param_2 < 0) goto LAB_008eb20c;
            param_1 = *(int *)(param_1 + 0x3c);
            iVar6 = *(int *)(piVar4[0x2c] + *(int *)(param_1 + 0x14) * 4);
            if (*(int *)(iVar6 + 0x40) == 0) {
              iVar8 = piVar4[8];
            }
            else {
              iVar8 = *(int *)(piVar4[0xe] + 0x10);
            }
            param_2 = FUN_008dc3aa(puVar11[1],
                                   *(int *)(iVar6 + 0x30) + *(int *)(param_1 + 0x1c) + iVar8,
                                   *puVar11,*(undefined4 *)(param_1 + 0x40),puVar11[0x10],iVar2);
            if (param_2 < 0) goto LAB_008eb20c;
          }
          local_14 = (int *)((int)local_14 + 1);
          local_8 = local_8 + 0x38;
        } while (local_14 < *(int **)(local_10 + 0x34));
      }
      local_18 = local_18 + 1;
      local_c = local_c + 0xb4;
    } while (local_18 < *(uint *)(iVar2 + 0xa0));
  }
  *param_3 = piVar4;
  piVar4 = (int *)0x0;
LAB_008eb20c:
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  return param_2;
}


// ==== FUN_008eb220 @ 0x008eb220 ====

void FUN_008eb220(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a231cc;
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_008eb230 @ 0x008eb230 ====

undefined4 FUN_008eb230(uint param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  pvVar1 = operator_new(param_1);
  *(void **)(in_ECX + 0xc) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    *(uint *)(in_ECX + 8) = param_1;
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_008eb25c @ 0x008eb25c ====

int FUN_008eb25c(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  iVar1 = iVar2 + -1;
  param_1[1] = iVar1;
  if (iVar2 == 1) {
    (**(code **)(*param_1 + 0x14))(1);
  }
  return iVar1;
}


// ==== FUN_008eb281 @ 0x008eb281 ====

undefined4 FUN_008eb281(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}


// ==== FUN_008eb290 @ 0x008eb290 ====

undefined4 FUN_008eb290(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


// ==== FUN_008eb29f @ 0x008eb29f ====

undefined4 FUN_008eb29f(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  if (*(uint *)(in_ECX + 8) < param_1) {
    puVar1 = operator_new(param_1);
    if (puVar1 != (undefined4 *)0x0) {
      uVar4 = *(uint *)(in_ECX + 8);
      puVar5 = *(undefined4 **)(in_ECX + 0xc);
      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar1 = puVar1 + 1;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar1 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar1 = (undefined4 *)((int)puVar1 + 1);
      }
      _free(*(void **)(in_ECX + 0xc));
      return extraout_EAX;
    }
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== FUN_008eb2fb @ 0x008eb2fb ====

void FUN_008eb2fb(byte param_1)

{
  void *in_ECX;
  
  FUN_008eb220();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008eb31c @ 0x008eb31c ====

undefined4 FUN_008eb31c(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  
  *param_3 = 0;
  iVar1 = 4;
  bVar4 = true;
  piVar2 = param_2;
  piVar3 = &DAT_00a52010;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *piVar2 == *piVar3;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    iVar1 = 4;
    bVar4 = true;
    piVar2 = &DAT_00a24fbc;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *param_2 == *piVar2;
      param_2 = param_2 + 1;
      piVar2 = piVar2 + 1;
    } while (bVar4);
    if (!bVar4) {
      return 0x80004002;
    }
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}


// ==== FUN_008eb365 @ 0x008eb365 ====

void FUN_008eb365(void)

{
  undefined4 *in_ECX;
  
  in_ECX[3] = 0;
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_00a231cc;
  in_ECX[1] = 1;
  return;
}


// ==== FUN_008eb37d @ 0x008eb37d ====

int FUN_008eb37d(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    iVar1 = -0x7789f794;
  }
  else {
    pvVar2 = operator_new(0x10);
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_008eb365();
    }
    if (piVar3 == (int *)0x0) {
      iVar1 = -0x7ff8fff2;
    }
    else {
      iVar1 = (**(code **)(*piVar3 + 0x18))(param_1);
      if (iVar1 < 0) {
        (**(code **)(*piVar3 + 0x14))(1);
      }
      else {
        *param_2 = piVar3;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ==== FUN_008eb3df @ 0x008eb3df ====

void FUN_008eb3df(void)

{
  FUN_008eb37d();
  return;
}


// ==== FUN_008eb3f0 @ 0x008eb3f0 ====

undefined4 FUN_008eb3f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *unaff_ESI;
  
  if (unaff_ESI[5] != 0xcc) {
    (**(code **)unaff_ESI[0x6a])();
    unaff_ESI[0x23] = 0;
    unaff_ESI[5] = 0xcc;
  }
  iVar1 = *(int *)(unaff_ESI[0x6a] + 8);
  while (iVar1 != 0) {
    puVar2 = (undefined4 *)*unaff_ESI;
    puVar2[5] = 0x30;
    (*(code *)*puVar2)();
    iVar1 = *(int *)(unaff_ESI[0x6a] + 8);
  }
  unaff_ESI[5] = (unaff_ESI[0x11] != 0) + 0xcd;
  return 1;
}


// ==== FUN_008eb460 @ 0x008eb460 ====

int FUN_008eb460(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  
  piVar4 = param_1;
  iVar1 = param_1[5];
  if (iVar1 != 0xcd) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0x14;
    puVar2[6] = iVar1;
    (*(code *)*puVar2)(param_1);
  }
  uVar3 = piVar4[0x1d];
  if (uVar3 <= (uint)piVar4[0x23]) {
    iVar1 = *piVar4;
    *(undefined4 *)(iVar1 + 0x14) = 0x7b;
    (**(code **)(iVar1 + 4))(piVar4,0xffffffff);
    return 0;
  }
  puVar2 = (undefined4 *)piVar4[2];
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = piVar4[0x23];
    puVar2[2] = uVar3;
    (*(code *)*puVar2)(piVar4);
  }
  param_1 = (int *)0x0;
  (**(code **)(piVar4[0x6b] + 4))(piVar4,param_2,&param_1,param_3);
  piVar4[0x23] = piVar4[0x23] + (int)param_1;
  return (int)param_1;
}


// ==== FUN_008eb4f0 @ 0x008eb4f0 ====

undefined4 FUN_008eb4f0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1[5] == 0xca) {
    FUN_0090a460(param_1);
    if (param_1[0x10] != 0) {
      param_1[5] = 0xcf;
      return 1;
    }
    param_1[5] = 0xcb;
  }
  iVar3 = param_1[5];
  if (iVar3 != 0xcb) {
    if (iVar3 != 0xcc) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 0x14;
      puVar2[6] = iVar3;
      (*(code *)*puVar2)(param_1);
    }
    uVar4 = FUN_008eb3f0();
    return uVar4;
  }
  if (*(int *)(param_1[0x6e] + 0x10) != 0) {
    while( true ) {
      if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
        (**(code **)param_1[2])(param_1);
      }
      iVar3 = (**(code **)param_1[0x6e])(param_1);
      if (iVar3 == 0) {
        return 0;
      }
      if (iVar3 == 2) break;
      iVar1 = param_1[2];
      if ((iVar1 != 0) &&
         (((iVar3 == 3 || (iVar3 == 1)) &&
          (iVar3 = *(int *)(iVar1 + 4) + 1, *(int *)(iVar1 + 4) = iVar3,
          *(int *)(iVar1 + 8) <= iVar3)))) {
        *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + param_1[0x51];
      }
    }
  }
  param_1[0x27] = param_1[0x25];
  uVar4 = FUN_008eb3f0();
  return uVar4;
}


// ==== FUN_008eb5d0 @ 0x008eb5d0 ====

void FUN_008eb5d0(int *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  param_1[1] = 0;
  if (param_2 != 0x3e) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0xc;
    puVar1[6] = 0x3e;
    puVar1[7] = param_2;
    (*(code *)*puVar1)(param_1);
  }
  if (param_3 != 0x1d8) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x15;
    puVar1[6] = 0x1d8;
    puVar1[7] = param_3;
    (*(code *)*puVar1)(param_1);
  }
  iVar2 = param_1[3];
  iVar3 = *param_1;
  piVar5 = param_1;
  for (iVar4 = 0x76; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  *param_1 = iVar3;
  param_1[3] = iVar2;
  param_1[4] = 1;
  FUN_0090b560(param_1);
  param_1[2] = 0;
  param_1[6] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x32] = 0;
  param_1[0x2f] = 0;
  param_1[0x33] = 0;
  param_1[0x30] = 0;
  param_1[0x34] = 0;
  param_1[0x31] = 0;
  param_1[0x35] = 0;
  param_1[0x4d] = 0;
  FUN_008ed250(param_1);
  FUN_0090aa30(param_1);
  param_1[5] = 200;
  return;
}


// ==== FUN_008eb6c0 @ 0x008eb6c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008eb6c0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *unaff_ESI;
  
  iVar1 = unaff_ESI[9];
  if (iVar1 == 1) {
    unaff_ESI[10] = 1;
    unaff_ESI[0xb] = 1;
    goto LAB_008eb7e3;
  }
  if (iVar1 != 3) {
    if (iVar1 == 4) {
      if ((unaff_ESI[0x4a] == 0) || (uVar6 = (uint)*(byte *)(unaff_ESI + 0x4b), uVar6 == 0)) {
        unaff_ESI[10] = 4;
        unaff_ESI[0xb] = 4;
      }
      else {
        if (uVar6 != 2) {
          iVar1 = *unaff_ESI;
          *(undefined4 *)(iVar1 + 0x14) = 0x72;
          *(uint *)(iVar1 + 0x18) = uVar6;
          (**(code **)(iVar1 + 4))();
        }
        unaff_ESI[10] = 5;
        unaff_ESI[0xb] = 4;
      }
    }
    else {
      unaff_ESI[10] = 0;
      unaff_ESI[0xb] = 0;
    }
    goto LAB_008eb7e3;
  }
  if (unaff_ESI[0x47] == 0) {
    if (unaff_ESI[0x4a] == 0) {
      piVar2 = (int *)unaff_ESI[0x37];
      iVar1 = *piVar2;
      iVar3 = piVar2[0x15];
      iVar4 = piVar2[0x2a];
      if (iVar1 == 1) {
        if ((iVar3 == 2) && (iVar4 == 3)) {
          unaff_ESI[10] = 3;
          unaff_ESI[0xb] = 2;
          goto LAB_008eb7e3;
        }
      }
      else if (((iVar1 == 0x52) && (iVar3 == 0x47)) && (iVar4 == 0x42)) goto LAB_008eb767;
      iVar5 = *unaff_ESI;
      *(int *)(iVar5 + 0x18) = iVar1;
      *(int *)(iVar5 + 0x1c) = iVar3;
      *(int *)(iVar5 + 0x20) = iVar4;
      *(undefined4 *)(iVar5 + 0x14) = 0x6f;
    }
    else {
      uVar6 = (uint)*(byte *)(unaff_ESI + 0x4b);
      if (uVar6 == 0) {
LAB_008eb767:
        unaff_ESI[10] = 2;
        unaff_ESI[0xb] = 2;
        goto LAB_008eb7e3;
      }
      if (uVar6 == 1) goto LAB_008eb7c6;
      iVar5 = *unaff_ESI;
      *(undefined4 *)(iVar5 + 0x14) = 0x72;
      *(uint *)(iVar5 + 0x18) = uVar6;
    }
    (**(code **)(iVar5 + 4))();
  }
LAB_008eb7c6:
  unaff_ESI[10] = 3;
  unaff_ESI[0xb] = 2;
LAB_008eb7e3:
  *(undefined8 *)(unaff_ESI + 0xe) = _DAT_0099d0a0;
  unaff_ESI[0xc] = 1;
  unaff_ESI[0xd] = 1;
  unaff_ESI[0x10] = 0;
  unaff_ESI[0x11] = 0;
  unaff_ESI[0x12] = 0;
  unaff_ESI[0x13] = 1;
  unaff_ESI[0x14] = 1;
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x16] = 2;
  unaff_ESI[0x17] = 0;
  unaff_ESI[0x18] = 0x100;
  unaff_ESI[0x22] = 0;
  unaff_ESI[0x19] = 0;
  unaff_ESI[0x1a] = 0;
  unaff_ESI[0x1b] = 0;
  return;
}


// ==== FUN_008eb830 @ 0x008eb830 ====

int FUN_008eb830(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[5];
  iVar3 = 0;
  switch(iVar2) {
  case 200:
    (**(code **)(param_1[0x6e] + 4))(param_1);
    (**(code **)(param_1[6] + 8))(param_1);
    param_1[5] = 0xc9;
  case 0xc9:
    iVar3 = (**(code **)param_1[0x6e])(param_1);
    if (iVar3 == 1) {
      FUN_008eb6c0();
      param_1[5] = 0xca;
      return 1;
    }
    break;
  case 0xca:
    return 1;
  case 0xcb:
  case 0xcc:
  case 0xcd:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd2:
    iVar2 = (**(code **)param_1[0x6e])(param_1);
    return iVar2;
  default:
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x14;
    puVar1[6] = iVar2;
    (*(code *)*puVar1)(param_1);
  }
  return iVar3;
}


// ==== FUN_008eb8f0 @ 0x008eb8f0 ====

undefined4 FUN_008eb8f0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_1[5];
  if (((iVar2 == 0xcd) || (iVar2 == 0xce)) && (param_1[0x10] == 0)) {
    if ((uint)param_1[0x23] < (uint)param_1[0x1d]) {
      puVar1 = (undefined4 *)*param_1;
      puVar1[5] = 0x43;
      (*(code *)*puVar1)(param_1);
    }
    (**(code **)(param_1[0x6a] + 4))(param_1);
    param_1[5] = 0xd2;
  }
  else if (iVar2 == 0xcf) {
    param_1[5] = 0xd2;
  }
  else if (iVar2 != 0xd2) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x14;
    puVar1[6] = iVar2;
    (*(code *)*puVar1)(param_1);
  }
  iVar2 = *(int *)(param_1[0x6e] + 0x14);
  while( true ) {
    if (iVar2 != 0) {
      (**(code **)(param_1[6] + 0x18))(param_1);
      FUN_0090b620(param_1);
      return 1;
    }
    iVar2 = (**(code **)param_1[0x6e])(param_1);
    if (iVar2 == 0) break;
    iVar2 = *(int *)(param_1[0x6e] + 0x14);
  }
  return 0;
}


// ==== FUN_008eb9b0 @ 0x008eb9b0 ====

int FUN_008eb9b0(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_1[5];
  if ((iVar2 != 200) && (iVar2 != 0xc9)) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x14;
    puVar1[6] = iVar2;
    (*(code *)*puVar1)(param_1);
  }
  iVar2 = FUN_008eb830(param_1);
  if (iVar2 == 1) {
    iVar2 = 1;
  }
  else if (iVar2 == 2) {
    if (param_2 != 0) {
      puVar1 = (undefined4 *)*param_1;
      puVar1[5] = 0x33;
      (*(code *)*puVar1)(param_1);
    }
    FUN_0090b620(param_1);
    return 2;
  }
  return iVar2;
}


// ==== FUN_008eba20 @ 0x008eba20 ====

undefined4 FUN_008eba20(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *unaff_ESI;
  
  iVar3 = *unaff_ESI;
  *(undefined4 *)(iVar3 + 0x14) = 0x66;
  (**(code **)(iVar3 + 4))();
  if (*(int *)(unaff_ESI[0x6f] + 0xc) != 0) {
    puVar1 = (undefined4 *)*unaff_ESI;
    puVar1[5] = 0x3d;
    (*(code *)*puVar1)();
  }
  piVar2 = unaff_ESI + 0x3e;
  iVar3 = 0x10;
  do {
    *(undefined1 *)(piVar2 + -4) = 0;
    *(undefined1 *)piVar2 = 1;
    *(undefined1 *)(piVar2 + 4) = 5;
    piVar2 = (int *)((int)piVar2 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  unaff_ESI[0x46] = 0;
  unaff_ESI[10] = 0;
  unaff_ESI[0x4c] = 0;
  unaff_ESI[0x47] = 0;
  *(undefined1 *)((int)unaff_ESI + 0x122) = 0;
  unaff_ESI[0x4a] = 0;
  *(undefined1 *)(unaff_ESI + 0x4b) = 0;
  *(undefined1 *)(unaff_ESI + 0x48) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x121) = 1;
  *(undefined2 *)(unaff_ESI + 0x49) = 1;
  *(undefined2 *)((int)unaff_ESI + 0x126) = 1;
  *(undefined4 *)(unaff_ESI[0x6f] + 0xc) = 1;
  return 1;
}


// ==== FUN_008ebad0 @ 0x008ebad0 ====

undefined4 FUN_008ebad0(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int in_ECX;
  int in_EDX;
  int *unaff_ESI;
  undefined1 *puVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint local_10;
  uint *local_c;
  
  puVar4 = (undefined4 *)unaff_ESI[6];
  iVar8 = puVar4[1];
  puVar10 = (undefined1 *)*puVar4;
  unaff_ESI[0x38] = in_ECX;
  unaff_ESI[0x39] = in_EDX;
  if (iVar8 == 0) {
    iVar8 = (*(code *)puVar4[3])();
    if (iVar8 == 0) {
      return 0;
    }
    puVar10 = (undefined1 *)*puVar4;
    iVar8 = puVar4[1];
  }
  uVar1 = *puVar10;
  iVar8 = iVar8 + -1;
  puVar10 = puVar10 + 1;
  if (iVar8 == 0) {
    iVar8 = (*(code *)puVar4[3])();
    if (iVar8 == 0) {
      return 0;
    }
    puVar10 = (undefined1 *)*puVar4;
    iVar8 = puVar4[1];
  }
  uVar2 = *puVar10;
  iVar8 = iVar8 + -1;
  pbVar11 = puVar10 + 1;
  if (iVar8 == 0) {
    iVar8 = (*(code *)puVar4[3])();
    if (iVar8 == 0) {
      return 0;
    }
    pbVar11 = (byte *)*puVar4;
    iVar8 = puVar4[1];
  }
  iVar8 = iVar8 + -1;
  pbVar12 = pbVar11 + 1;
  unaff_ESI[0x36] = (uint)*pbVar11;
  if (iVar8 == 0) {
    iVar8 = (*(code *)puVar4[3])();
    if (iVar8 == 0) {
      return 0;
    }
    pbVar12 = (byte *)*puVar4;
    iVar8 = puVar4[1];
  }
  iVar8 = iVar8 + -1;
  pbVar11 = pbVar12 + 1;
  unaff_ESI[8] = (uint)*pbVar12 << 8;
  if (iVar8 == 0) {
    iVar8 = (*(code *)puVar4[3])();
    if (iVar8 == 0) {
      return 0;
    }
    pbVar11 = (byte *)*puVar4;
    iVar8 = puVar4[1];
  }
  iVar8 = iVar8 + -1;
  pbVar12 = pbVar11 + 1;
  unaff_ESI[8] = unaff_ESI[8] + (uint)*pbVar11;
  if (iVar8 == 0) {
    iVar8 = (*(code *)puVar4[3])();
    if (iVar8 == 0) {
      return 0;
    }
    pbVar12 = (byte *)*puVar4;
    iVar8 = puVar4[1];
  }
  iVar8 = iVar8 + -1;
  pbVar11 = pbVar12 + 1;
  unaff_ESI[7] = (uint)*pbVar12 << 8;
  if (iVar8 == 0) {
    iVar8 = (*(code *)puVar4[3])();
    if (iVar8 == 0) {
      return 0;
    }
    pbVar11 = (byte *)*puVar4;
    iVar8 = puVar4[1];
  }
  iVar8 = iVar8 + -1;
  pbVar12 = pbVar11 + 1;
  unaff_ESI[7] = unaff_ESI[7] + (uint)*pbVar11;
  if (iVar8 == 0) {
    iVar8 = (*(code *)puVar4[3])();
    if (iVar8 == 0) {
      return 0;
    }
    pbVar12 = (byte *)*puVar4;
    iVar8 = puVar4[1];
  }
  iVar9 = *unaff_ESI;
  unaff_ESI[9] = (uint)*pbVar12;
  iVar5 = unaff_ESI[7];
  *(int *)(iVar9 + 0x18) = unaff_ESI[0x69];
  iVar6 = unaff_ESI[8];
  *(int *)(iVar9 + 0x1c) = iVar5;
  iVar5 = unaff_ESI[9];
  *(int *)(iVar9 + 0x20) = iVar6;
  *(int *)(iVar9 + 0x24) = iVar5;
  iVar8 = iVar8 + -1;
  pbVar12 = pbVar12 + 1;
  *(undefined4 *)(iVar9 + 0x14) = 100;
  (**(code **)(iVar9 + 4))();
  if (*(int *)(unaff_ESI[0x6f] + 0x10) != 0) {
    puVar7 = (undefined4 *)*unaff_ESI;
    puVar7[5] = 0x3a;
    (*(code *)*puVar7)();
  }
  if (((unaff_ESI[8] == 0) || (unaff_ESI[7] == 0)) || (unaff_ESI[9] < 1)) {
    puVar7 = (undefined4 *)*unaff_ESI;
    puVar7[5] = 0x20;
    (*(code *)*puVar7)();
  }
  if (CONCAT11(uVar1,uVar2) - 8 != unaff_ESI[9] * 3) {
    puVar7 = (undefined4 *)*unaff_ESI;
    puVar7[5] = 0xb;
    (*(code *)*puVar7)();
  }
  if (unaff_ESI[0x37] == 0) {
    iVar9 = (**(code **)unaff_ESI[1])();
    unaff_ESI[0x37] = iVar9;
  }
  local_c = (uint *)unaff_ESI[0x37];
  local_10 = 0;
  if (0 < unaff_ESI[9]) {
    do {
      local_c[1] = local_10;
      if (iVar8 == 0) {
        iVar8 = (*(code *)puVar4[3])();
        if (iVar8 == 0) {
          return 0;
        }
        pbVar12 = (byte *)*puVar4;
        iVar8 = puVar4[1];
      }
      iVar8 = iVar8 + -1;
      pbVar11 = pbVar12 + 1;
      *local_c = (uint)*pbVar12;
      if (iVar8 == 0) {
        iVar8 = (*(code *)puVar4[3])();
        if (iVar8 == 0) {
          return 0;
        }
        pbVar11 = (byte *)*puVar4;
        iVar8 = puVar4[1];
      }
      bVar3 = *pbVar11;
      iVar8 = iVar8 + -1;
      pbVar11 = pbVar11 + 1;
      local_c[2] = (int)(uint)bVar3 >> 4;
      local_c[3] = bVar3 & 0xf;
      if (iVar8 == 0) {
        iVar8 = (*(code *)puVar4[3])();
        if (iVar8 == 0) {
          return 0;
        }
        pbVar11 = (byte *)*puVar4;
        iVar8 = puVar4[1];
      }
      local_c[4] = (uint)*pbVar11;
      iVar9 = *unaff_ESI;
      *(uint *)(iVar9 + 0x18) = *local_c;
      *(uint *)(iVar9 + 0x1c) = local_c[2];
      *(uint *)(iVar9 + 0x20) = local_c[3];
      *(uint *)(iVar9 + 0x24) = local_c[4];
      iVar8 = iVar8 + -1;
      pbVar12 = pbVar11 + 1;
      *(undefined4 *)(iVar9 + 0x14) = 0x65;
      (**(code **)(iVar9 + 4))();
      local_10 = local_10 + 1;
      local_c = local_c + 0x15;
    } while ((int)local_10 < unaff_ESI[9]);
  }
  *(undefined4 *)(unaff_ESI[0x6f] + 0x10) = 1;
  *puVar4 = pbVar12;
  puVar4[1] = iVar8;
  return 1;
}


// ==== FUN_008ebdb0 @ 0x008ebdb0 ====

undefined4 FUN_008ebdb0(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined1 *puVar11;
  byte *pbVar12;
  byte *pbVar13;
  int *unaff_ESI;
  uint *puVar14;
  int local_18;
  int *local_10;
  int local_8;
  
  puVar4 = (undefined4 *)unaff_ESI[6];
  local_8 = puVar4[1];
  puVar11 = (undefined1 *)*puVar4;
  if (*(int *)(unaff_ESI[0x6f] + 0x10) == 0) {
    puVar5 = (undefined4 *)*unaff_ESI;
    puVar5[5] = 0x3e;
    (*(code *)*puVar5)();
  }
  if (local_8 == 0) {
    iVar7 = (*(code *)puVar4[3])();
    if (iVar7 == 0) {
      return 0;
    }
    local_8 = puVar4[1];
    puVar11 = (undefined1 *)*puVar4;
  }
  uVar1 = *puVar11;
  local_8 = local_8 + -1;
  puVar11 = puVar11 + 1;
  if (local_8 == 0) {
    iVar7 = (*(code *)puVar4[3])();
    if (iVar7 == 0) {
      return 0;
    }
    local_8 = puVar4[1];
    puVar11 = (undefined1 *)*puVar4;
  }
  uVar2 = *puVar11;
  local_8 = local_8 + -1;
  pbVar12 = puVar11 + 1;
  if (local_8 == 0) {
    iVar7 = (*(code *)puVar4[3])();
    if (iVar7 == 0) {
      return 0;
    }
    local_8 = puVar4[1];
    pbVar12 = (byte *)*puVar4;
  }
  uVar8 = (uint)*pbVar12;
  local_8 = local_8 + -1;
  iVar7 = *unaff_ESI;
  *(undefined4 *)(iVar7 + 0x14) = 0x67;
  pbVar12 = pbVar12 + 1;
  *(uint *)(iVar7 + 0x18) = uVar8;
  (**(code **)(iVar7 + 4))();
  if ((((uint)CONCAT11(uVar1,uVar2) != uVar8 * 2 + 6) || (uVar8 == 0)) || (4 < uVar8)) {
    puVar5 = (undefined4 *)*unaff_ESI;
    puVar5[5] = 0xb;
    (*(code *)*puVar5)();
  }
  unaff_ESI[0x53] = uVar8;
  local_18 = 0;
  if (uVar8 != 0) {
    local_10 = unaff_ESI + 0x54;
    do {
      if (local_8 == 0) {
        iVar7 = (*(code *)puVar4[3])();
        if (iVar7 == 0) {
          return 0;
        }
        local_8 = puVar4[1];
        pbVar12 = (byte *)*puVar4;
      }
      uVar9 = (uint)*pbVar12;
      local_8 = local_8 + -1;
      pbVar12 = pbVar12 + 1;
      if (local_8 == 0) {
        iVar7 = (*(code *)puVar4[3])();
        if (iVar7 == 0) {
          return 0;
        }
        local_8 = puVar4[1];
        pbVar12 = (byte *)*puVar4;
      }
      puVar14 = (uint *)unaff_ESI[0x37];
      local_8 = local_8 + -1;
      bVar3 = *pbVar12;
      pbVar12 = pbVar12 + 1;
      iVar7 = 0;
      if (0 < unaff_ESI[9]) {
        do {
          if (uVar9 == *puVar14) goto LAB_008ebf37;
          iVar7 = iVar7 + 1;
          puVar14 = puVar14 + 0x15;
        } while (iVar7 < unaff_ESI[9]);
      }
      puVar5 = (undefined4 *)*unaff_ESI;
      puVar5[5] = 5;
      puVar5[6] = uVar9;
      (*(code *)*puVar5)();
LAB_008ebf37:
      puVar14[6] = bVar3 & 0xf;
      *local_10 = (int)puVar14;
      iVar7 = *unaff_ESI;
      puVar14[5] = (int)(uint)bVar3 >> 4;
      *(uint *)(iVar7 + 0x18) = uVar9;
      *(uint *)(iVar7 + 0x1c) = puVar14[5];
      *(uint *)(iVar7 + 0x20) = puVar14[6];
      *(undefined4 *)(iVar7 + 0x14) = 0x68;
      (**(code **)(iVar7 + 4))();
      local_18 = local_18 + 1;
      local_10 = local_10 + 1;
    } while (local_18 < (int)uVar8);
  }
  if (local_8 == 0) {
    iVar7 = (*(code *)puVar4[3])();
    if (iVar7 == 0) {
      return 0;
    }
    local_8 = puVar4[1];
    pbVar12 = (byte *)*puVar4;
  }
  local_8 = local_8 + -1;
  pbVar13 = pbVar12 + 1;
  unaff_ESI[0x65] = (uint)*pbVar12;
  if (local_8 == 0) {
    iVar7 = (*(code *)puVar4[3])();
    if (iVar7 == 0) {
      return 0;
    }
    local_8 = puVar4[1];
    pbVar13 = (byte *)*puVar4;
  }
  local_8 = local_8 + -1;
  pbVar12 = pbVar13 + 1;
  unaff_ESI[0x66] = (uint)*pbVar13;
  if (local_8 == 0) {
    iVar7 = (*(code *)puVar4[3])();
    if (iVar7 == 0) {
      return 0;
    }
    local_8 = puVar4[1];
    pbVar12 = (byte *)*puVar4;
  }
  uVar8 = *pbVar12 & 0xf;
  iVar10 = (int)(uint)*pbVar12 >> 4;
  unaff_ESI[0x68] = uVar8;
  iVar7 = *unaff_ESI;
  *(int *)(iVar7 + 0x18) = unaff_ESI[0x65];
  iVar6 = unaff_ESI[0x66];
  *(int *)(iVar7 + 0x20) = iVar10;
  unaff_ESI[0x67] = iVar10;
  *(int *)(iVar7 + 0x1c) = iVar6;
  *(uint *)(iVar7 + 0x24) = uVar8;
  *(undefined4 *)(iVar7 + 0x14) = 0x69;
  (**(code **)(iVar7 + 4))();
  unaff_ESI[0x25] = unaff_ESI[0x25] + 1;
  *(undefined4 *)(unaff_ESI[0x6f] + 0x14) = 0;
  *puVar4 = pbVar12 + 1;
  puVar4[1] = local_8 + -1;
  return 1;
}


// ==== FUN_008ec070 @ 0x008ec070 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008ec070(void)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  undefined4 *puVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int *unaff_EBX;
  undefined1 *puVar8;
  int *piVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  int local_134;
  int local_130;
  int local_12c;
  byte *local_124;
  int local_120;
  byte local_11c [256];
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  byte local_c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  puVar4 = (undefined4 *)unaff_EBX[6];
  puVar8 = (undefined1 *)*puVar4;
  local_120 = puVar4[1];
  if (local_120 == 0) {
    iVar6 = (*(code *)puVar4[3])();
    if (iVar6 == 0) {
      return 0;
    }
    puVar8 = (undefined1 *)*puVar4;
    local_120 = puVar4[1];
  }
  uVar1 = *puVar8;
  local_120 = local_120 + -1;
  puVar8 = puVar8 + 1;
  if (local_120 == 0) {
    iVar6 = (*(code *)puVar4[3])();
    if (iVar6 == 0) {
      return 0;
    }
    puVar8 = (undefined1 *)*puVar4;
    local_120 = puVar4[1];
  }
  local_120 = local_120 + -1;
  local_12c = CONCAT11(uVar1,*puVar8) - 2;
  local_124 = puVar8 + 1;
  if (0x10 < local_12c) {
    do {
      if (local_120 == 0) {
        iVar6 = (*(code *)puVar4[3])();
        if (iVar6 == 0) {
          return 0;
        }
        local_124 = (byte *)*puVar4;
        local_120 = puVar4[1];
      }
      bVar2 = *local_124;
      uVar7 = (uint)bVar2;
      iVar6 = *unaff_EBX;
      local_120 = local_120 + -1;
      *(undefined4 *)(iVar6 + 0x14) = 0x50;
      local_124 = local_124 + 1;
      *(uint *)(iVar6 + 0x18) = uVar7;
      (**(code **)(iVar6 + 4))();
      local_1c = local_1c & 0xffffff00;
      local_130 = 0;
      local_134 = 1;
      do {
        if (local_120 == 0) {
          iVar6 = (*(code *)puVar4[3])();
          if (iVar6 == 0) {
            return 0;
          }
          local_124 = (byte *)*puVar4;
          local_120 = puVar4[1];
        }
        bVar3 = *local_124;
        local_11c[local_134 + 0x100] = bVar3;
        local_120 = local_120 + -1;
        local_124 = local_124 + 1;
        local_130 = local_130 + (uint)bVar3;
        local_134 = local_134 + 1;
      } while (local_134 < 0x11);
      iVar6 = *unaff_EBX;
      *(uint *)(iVar6 + 0x18) = local_1c >> 8 & 0xff;
      *(uint *)(iVar6 + 0x1c) = local_1c >> 0x10 & 0xff;
      *(uint *)(iVar6 + 0x20) = local_1c >> 0x18;
      *(uint *)(iVar6 + 0x24) = local_18 & 0xff;
      *(uint *)(iVar6 + 0x28) = local_18 >> 8 & 0xff;
      *(uint *)(iVar6 + 0x2c) = local_18 >> 0x10 & 0xff;
      *(uint *)(iVar6 + 0x30) = local_18 >> 0x18;
      *(uint *)(iVar6 + 0x34) = local_14 & 0xff;
      *(undefined4 *)(iVar6 + 0x14) = 0x56;
      (**(code **)(iVar6 + 4))();
      iVar6 = *unaff_EBX;
      *(uint *)(iVar6 + 0x18) = local_14 >> 8 & 0xff;
      *(uint *)(iVar6 + 0x1c) = local_14 >> 0x10 & 0xff;
      *(uint *)(iVar6 + 0x20) = local_14 >> 0x18;
      *(uint *)(iVar6 + 0x24) = local_10 & 0xff;
      *(uint *)(iVar6 + 0x28) = local_10 >> 8 & 0xff;
      *(uint *)(iVar6 + 0x2c) = local_10 >> 0x10 & 0xff;
      *(uint *)(iVar6 + 0x30) = local_10 >> 0x18;
      *(uint *)(iVar6 + 0x34) = (uint)local_c;
      *(undefined4 *)(iVar6 + 0x14) = 0x56;
      (**(code **)(iVar6 + 4))();
      if ((0x100 < local_130) || (local_12c + -0x11 < local_130)) {
        puVar11 = (undefined4 *)*unaff_EBX;
        puVar11[5] = 8;
        (*(code *)*puVar11)();
      }
      local_134 = 0;
      if (0 < local_130) {
        do {
          if (local_120 == 0) {
            iVar6 = (*(code *)puVar4[3])();
            if (iVar6 == 0) {
              return 0;
            }
            local_120 = puVar4[1];
            local_124 = (byte *)*puVar4;
          }
          bVar3 = *local_124;
          local_120 = local_120 + -1;
          local_124 = local_124 + 1;
          local_11c[local_134] = bVar3;
          local_134 = local_134 + 1;
        } while (local_134 < local_130);
      }
      local_12c = (local_12c + -0x11) - local_130;
      if ((bVar2 & 0x10) == 0) {
        iVar6 = uVar7 + 0x2e;
      }
      else {
        iVar6 = uVar7 + 0x22;
        uVar7 = uVar7 - 0x10;
      }
      piVar9 = unaff_EBX + iVar6;
      if (((int)uVar7 < 0) || (3 < (int)uVar7)) {
        puVar11 = (undefined4 *)*unaff_EBX;
        puVar11[5] = 0x1e;
        puVar11[6] = uVar7;
        (*(code *)*puVar11)();
      }
      if (*piVar9 == 0) {
        iVar6 = FUN_0090b6c0(unaff_EBX);
        *piVar9 = iVar6;
      }
      puVar5 = (uint *)*piVar9;
      *puVar5 = local_1c;
      puVar5[1] = local_18;
      puVar5[2] = local_14;
      puVar5[3] = local_10;
      *(byte *)(puVar5 + 4) = local_c;
      pbVar10 = local_11c;
      puVar11 = (undefined4 *)((int)puVar5 + 0x11);
      for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar11 = *(undefined4 *)pbVar10;
        pbVar10 = pbVar10 + 4;
        puVar11 = puVar11 + 1;
      }
    } while (0x10 < local_12c);
  }
  if (local_12c != 0) {
    puVar11 = (undefined4 *)*unaff_EBX;
    puVar11[5] = 0xb;
    (*(code *)*puVar11)();
  }
  puVar4[1] = local_120;
  *puVar4 = local_124;
  return 1;
}


// ==== FUN_008ec3f0 @ 0x008ec3f0 ====

undefined4 FUN_008ec3f0(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  ushort *puVar10;
  undefined1 *puVar11;
  byte *pbVar12;
  int *local_14;
  int local_8;
  
  puVar3 = (undefined4 *)param_1[6];
  iVar5 = puVar3[1];
  puVar11 = (undefined1 *)*puVar3;
  if (iVar5 == 0) {
    iVar5 = (*(code *)puVar3[3])(param_1);
    if (iVar5 == 0) {
      return 0;
    }
    puVar11 = (undefined1 *)*puVar3;
    iVar5 = puVar3[1];
  }
  uVar1 = *puVar11;
  iVar5 = iVar5 + -1;
  puVar11 = puVar11 + 1;
  if (iVar5 == 0) {
    iVar5 = (*(code *)puVar3[3])(param_1);
    if (iVar5 == 0) {
      return 0;
    }
    puVar11 = (undefined1 *)*puVar3;
    iVar5 = puVar3[1];
  }
  iVar5 = iVar5 + -1;
  local_8 = CONCAT11(uVar1,*puVar11) - 2;
  pbVar12 = puVar11 + 1;
  if (0 < local_8) {
    do {
      if (iVar5 == 0) {
        iVar5 = (*(code *)puVar3[3])(param_1);
        if (iVar5 == 0) {
          return 0;
        }
        pbVar12 = (byte *)*puVar3;
        iVar5 = puVar3[1];
      }
      bVar2 = *pbVar12;
      iVar6 = *param_1;
      iVar7 = (int)(uint)bVar2 >> 4;
      *(undefined4 *)(iVar6 + 0x14) = 0x51;
      uVar9 = bVar2 & 0xf;
      *(uint *)(iVar6 + 0x18) = uVar9;
      iVar5 = iVar5 + -1;
      pbVar12 = pbVar12 + 1;
      *(int *)(iVar6 + 0x1c) = iVar7;
      (**(code **)(iVar6 + 4))(param_1,1);
      if (3 < uVar9) {
        puVar4 = (undefined4 *)*param_1;
        puVar4[5] = 0x1f;
        puVar4[6] = uVar9;
        (*(code *)*puVar4)(param_1);
      }
      if (param_1[uVar9 + 0x2a] == 0) {
        iVar6 = FUN_0090b690(param_1);
        param_1[uVar9 + 0x2a] = iVar6;
      }
      iVar6 = param_1[uVar9 + 0x2a];
      local_14 = &DAT_00a28750;
      do {
        if (iVar7 == 0) {
          if (iVar5 == 0) {
            iVar5 = (*(code *)puVar3[3])(param_1);
            if (iVar5 == 0) {
              return 0;
            }
            pbVar12 = (byte *)*puVar3;
            iVar5 = puVar3[1];
          }
          uVar8 = (ushort)*pbVar12;
        }
        else {
          if (iVar5 == 0) {
            iVar5 = (*(code *)puVar3[3])(param_1);
            if (iVar5 == 0) {
              return 0;
            }
            pbVar12 = (byte *)*puVar3;
            iVar5 = puVar3[1];
          }
          bVar2 = *pbVar12;
          iVar5 = iVar5 + -1;
          pbVar12 = pbVar12 + 1;
          if (iVar5 == 0) {
            iVar5 = (*(code *)puVar3[3])(param_1);
            if (iVar5 == 0) {
              return 0;
            }
            pbVar12 = (byte *)*puVar3;
            iVar5 = puVar3[1];
          }
          uVar8 = CONCAT11(bVar2,*pbVar12);
        }
        *(ushort *)(iVar6 + *local_14 * 2) = uVar8;
        iVar5 = iVar5 + -1;
        local_14 = local_14 + 1;
        pbVar12 = pbVar12 + 1;
      } while ((int)local_14 < 0xa28850);
      if (1 < *(int *)(*param_1 + 0x68)) {
        puVar10 = (ushort *)(iVar6 + 4);
        local_14 = (int *)0x8;
        do {
          iVar6 = *param_1;
          *(uint *)(iVar6 + 0x18) = (uint)puVar10[-2];
          *(uint *)(iVar6 + 0x1c) = (uint)puVar10[-1];
          *(uint *)(iVar6 + 0x20) = (uint)*puVar10;
          *(uint *)(iVar6 + 0x24) = (uint)puVar10[1];
          *(uint *)(iVar6 + 0x28) = (uint)puVar10[2];
          *(uint *)(iVar6 + 0x2c) = (uint)puVar10[3];
          *(uint *)(iVar6 + 0x30) = (uint)puVar10[4];
          *(uint *)(iVar6 + 0x34) = (uint)puVar10[5];
          *(undefined4 *)(iVar6 + 0x14) = 0x5d;
          (**(code **)(iVar6 + 4))(param_1,2);
          puVar10 = puVar10 + 8;
          local_14 = (int *)((int)local_14 + -1);
        } while (local_14 != (int *)0x0);
      }
      iVar6 = local_8 + -0x41;
      if (iVar7 != 0) {
        iVar6 = local_8 + -0x81;
      }
      local_8 = iVar6;
    } while (0 < local_8);
  }
  if (local_8 != 0) {
    puVar4 = (undefined4 *)*param_1;
    puVar4[5] = 0xb;
    (*(code *)*puVar4)(param_1);
  }
  *puVar3 = pbVar12;
  puVar3[1] = iVar5;
  return 1;
}


// ==== FUN_008ec640 @ 0x008ec640 ====

undefined4 FUN_008ec640(int *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  
  puVar3 = (undefined4 *)param_1[6];
  iVar6 = puVar3[1];
  puVar7 = (undefined1 *)*puVar3;
  if (iVar6 == 0) {
    iVar6 = (*(code *)puVar3[3])(param_1);
    if (iVar6 == 0) {
      return 0;
    }
    puVar7 = (undefined1 *)*puVar3;
    iVar6 = puVar3[1];
  }
  uVar1 = *puVar7;
  iVar6 = iVar6 + -1;
  puVar7 = puVar7 + 1;
  if (iVar6 == 0) {
    iVar6 = (*(code *)puVar3[3])(param_1);
    if (iVar6 == 0) {
      return 0;
    }
    puVar7 = (undefined1 *)*puVar3;
    iVar6 = puVar3[1];
  }
  iVar6 = iVar6 + -1;
  puVar8 = puVar7 + 1;
  if (CONCAT11(uVar1,*puVar7) != 4) {
    puVar4 = (undefined4 *)*param_1;
    puVar4[5] = 0xb;
    (*(code *)*puVar4)(param_1);
  }
  if (iVar6 == 0) {
    iVar6 = (*(code *)puVar3[3])(param_1);
    if (iVar6 == 0) {
      return 0;
    }
    puVar8 = (undefined1 *)*puVar3;
    iVar6 = puVar3[1];
  }
  uVar1 = *puVar8;
  iVar6 = iVar6 + -1;
  puVar8 = puVar8 + 1;
  if (iVar6 == 0) {
    iVar6 = (*(code *)puVar3[3])(param_1);
    if (iVar6 == 0) {
      return 0;
    }
    puVar8 = (undefined1 *)*puVar3;
    iVar6 = puVar3[1];
  }
  uVar2 = *puVar8;
  iVar5 = *param_1;
  *(undefined4 *)(iVar5 + 0x14) = 0x52;
  *(uint *)(iVar5 + 0x18) = (uint)CONCAT11(uVar1,uVar2);
  (**(code **)(iVar5 + 4))(param_1,1);
  *puVar3 = puVar8 + 1;
  puVar3[1] = iVar6 + -1;
  param_1[0x46] = (uint)CONCAT11(uVar1,uVar2);
  return 1;
}


// ==== FUN_008ec720 @ 0x008ec720 ====

void FUN_008ec720(void)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  ushort uVar7;
  ushort uVar8;
  int iVar9;
  uint in_EAX;
  int in_ECX;
  uint uVar10;
  int *unaff_ESI;
  char *unaff_EDI;
  
  iVar1 = in_EAX + in_ECX;
  if ((((in_EAX < 0xe) || (*unaff_EDI != 'J')) || (unaff_EDI[1] != 'F')) ||
     (((unaff_EDI[2] != 'I' || (unaff_EDI[3] != 'F')) || (unaff_EDI[4] != '\0')))) {
    if (((5 < in_EAX) && (*unaff_EDI == 'J')) &&
       ((unaff_EDI[1] == 'F' &&
        (((unaff_EDI[2] == 'X' && (unaff_EDI[3] == 'X')) && (unaff_EDI[4] == '\0')))))) {
      uVar10 = (uint)(byte)unaff_EDI[5];
      if (uVar10 == 0x10) {
        iVar9 = *unaff_ESI;
        *(undefined4 *)(iVar9 + 0x14) = 0x6c;
        *(int *)(iVar9 + 0x18) = iVar1;
        (**(code **)(iVar9 + 4))();
        return;
      }
      if (uVar10 == 0x11) {
        iVar9 = *unaff_ESI;
        *(undefined4 *)(iVar9 + 0x14) = 0x6d;
        *(int *)(iVar9 + 0x18) = iVar1;
        (**(code **)(iVar9 + 4))();
        return;
      }
      iVar9 = *unaff_ESI;
      if (uVar10 == 0x13) {
        *(undefined4 *)(iVar9 + 0x14) = 0x6e;
        *(int *)(iVar9 + 0x18) = iVar1;
        (**(code **)(iVar9 + 4))();
        return;
      }
      *(undefined4 *)(iVar9 + 0x14) = 0x59;
      *(uint *)(iVar9 + 0x18) = uVar10;
      *(int *)(iVar9 + 0x1c) = iVar1;
      (**(code **)(iVar9 + 4))();
      return;
    }
    iVar9 = *unaff_ESI;
    *(undefined4 *)(iVar9 + 0x14) = 0x4d;
    *(int *)(iVar9 + 0x18) = iVar1;
    (**(code **)(iVar9 + 4))();
  }
  else {
    cVar2 = unaff_EDI[7];
    bVar3 = unaff_EDI[5];
    *(char *)((int)unaff_ESI + 0x121) = unaff_EDI[6];
    cVar4 = unaff_EDI[8];
    *(char *)((int)unaff_ESI + 0x122) = cVar2;
    cVar2 = unaff_EDI[9];
    unaff_ESI[0x47] = 1;
    *(byte *)(unaff_ESI + 0x48) = bVar3;
    cVar5 = unaff_EDI[0xb];
    *(ushort *)(unaff_ESI + 0x49) = CONCAT11(cVar4,cVar2);
    *(ushort *)((int)unaff_ESI + 0x126) = CONCAT11(unaff_EDI[10],cVar5);
    if (bVar3 != 1) {
      iVar9 = *unaff_ESI;
      bVar6 = unaff_EDI[6];
      *(undefined4 *)(iVar9 + 0x14) = 0x77;
      *(uint *)(iVar9 + 0x18) = (uint)bVar3;
      *(uint *)(iVar9 + 0x1c) = (uint)bVar6;
      (**(code **)(iVar9 + 4))();
    }
    iVar9 = *unaff_ESI;
    bVar3 = *(byte *)((int)unaff_ESI + 0x121);
    *(uint *)(iVar9 + 0x18) = (uint)*(byte *)(unaff_ESI + 0x48);
    uVar7 = *(ushort *)(unaff_ESI + 0x49);
    *(uint *)(iVar9 + 0x1c) = (uint)bVar3;
    uVar8 = *(ushort *)((int)unaff_ESI + 0x126);
    *(uint *)(iVar9 + 0x20) = (uint)uVar7;
    bVar3 = *(byte *)((int)unaff_ESI + 0x122);
    *(uint *)(iVar9 + 0x24) = (uint)uVar8;
    *(uint *)(iVar9 + 0x28) = (uint)bVar3;
    *(undefined4 *)(iVar9 + 0x14) = 0x57;
    (**(code **)(iVar9 + 4))();
    bVar3 = unaff_EDI[0xc];
    bVar6 = unaff_EDI[0xd];
    if (bVar3 != 0 || bVar6 != 0) {
      iVar9 = *unaff_ESI;
      *(undefined4 *)(iVar9 + 0x14) = 0x5a;
      *(uint *)(iVar9 + 0x18) = (uint)bVar3;
      *(uint *)(iVar9 + 0x1c) = (uint)bVar6;
      (**(code **)(iVar9 + 4))();
    }
    if (iVar1 + -0xe != (uint)(byte)unaff_EDI[0xc] * (uint)(byte)unaff_EDI[0xd] * 3) {
      iVar9 = *unaff_ESI;
      *(undefined4 *)(iVar9 + 0x14) = 0x58;
      *(int *)(iVar9 + 0x18) = iVar1 + -0xe;
      (**(code **)(iVar9 + 4))();
      return;
    }
  }
  return;
}


// ==== FUN_008ec900 @ 0x008ec900 ====

void FUN_008ec900(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char *in_EAX;
  uint in_ECX;
  int *unaff_ESI;
  
  if ((((in_ECX < 0xc) || (*in_EAX != 'A')) || (in_EAX[1] != 'd')) ||
     (((in_EAX[2] != 'o' || (in_EAX[3] != 'b')) || (in_EAX[4] != 'e')))) {
    iVar3 = *unaff_ESI;
    *(undefined4 *)(iVar3 + 0x14) = 0x4e;
    *(uint *)(iVar3 + 0x18) = in_ECX + param_1;
    (**(code **)(iVar3 + 4))();
    return;
  }
  iVar3 = *unaff_ESI;
  bVar1 = in_EAX[0xb];
  cVar2 = in_EAX[8];
  *(uint *)(iVar3 + 0x18) = (uint)CONCAT11(in_EAX[5],in_EAX[6]);
  *(uint *)(iVar3 + 0x1c) = (uint)CONCAT11(in_EAX[7],cVar2);
  *(uint *)(iVar3 + 0x20) = (uint)CONCAT11(in_EAX[9],in_EAX[10]);
  *(uint *)(iVar3 + 0x24) = (uint)bVar1;
  *(undefined4 *)(iVar3 + 0x14) = 0x4c;
  (**(code **)(iVar3 + 4))();
  *(byte *)(unaff_ESI + 0x4b) = bVar1;
  unaff_ESI[0x4a] = 1;
  return;
}


// ==== FUN_008ec9a0 @ 0x008ec9a0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008ec9a0(int *param_1)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint local_2c;
  uint local_20;
  int local_1c;
  undefined1 local_18 [16];
  undefined4 local_8;
  
  puVar2 = (undefined4 *)param_1[6];
  local_1c = puVar2[1];
  puVar7 = (undefined1 *)*puVar2;
  local_8 = DAT_00b49670;
  if (local_1c == 0) {
    iVar5 = (*(code *)puVar2[3])(param_1);
    if (iVar5 == 0) {
      return 0;
    }
    local_1c = puVar2[1];
    puVar7 = (undefined1 *)*puVar2;
  }
  uVar1 = *puVar7;
  local_1c = local_1c + -1;
  puVar7 = puVar7 + 1;
  if (local_1c == 0) {
    iVar5 = (*(code *)puVar2[3])(param_1);
    if (iVar5 == 0) {
      return 0;
    }
    local_1c = puVar2[1];
    puVar7 = (undefined1 *)*puVar2;
  }
  local_1c = local_1c + -1;
  uVar6 = CONCAT11(uVar1,*puVar7) - 2;
  puVar7 = puVar7 + 1;
  if ((int)uVar6 < 0xe) {
    local_20 = ((int)uVar6 < 1) - 1 & uVar6;
  }
  else {
    local_20 = 0xe;
  }
  local_2c = 0;
  if (local_20 != 0) {
    do {
      if (local_1c == 0) {
        iVar5 = (*(code *)puVar2[3])(param_1);
        if (iVar5 == 0) {
          return 0;
        }
        local_1c = puVar2[1];
        puVar7 = (undefined1 *)*puVar2;
      }
      local_1c = local_1c + -1;
      local_18[local_2c] = *puVar7;
      puVar7 = puVar7 + 1;
      local_2c = local_2c + 1;
    } while (local_2c < local_20);
  }
  iVar5 = uVar6 - local_20;
  if (param_1[0x69] == 0xe0) {
    FUN_008ec720();
  }
  else if (param_1[0x69] == 0xee) {
    FUN_008ec900(iVar5);
  }
  else {
    puVar3 = (undefined4 *)*param_1;
    iVar4 = param_1[0x69];
    puVar3[5] = 0x44;
    puVar3[6] = iVar4;
    (*(code *)*puVar3)(param_1);
  }
  *puVar2 = puVar7;
  puVar2[1] = local_1c;
  if (0 < iVar5) {
    (**(code **)(param_1[6] + 0x10))(param_1,iVar5);
  }
  return 1;
}


// ==== FUN_008ecb10 @ 0x008ecb10 ====

undefined4 FUN_008ecb10(int *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  
  piVar5 = param_1;
  puVar2 = (undefined4 *)param_1[6];
  iVar6 = puVar2[1];
  pbVar7 = (byte *)*puVar2;
  if (iVar6 == 0) {
    iVar6 = (*(code *)puVar2[3])(param_1);
    if (iVar6 == 0) {
      return 0;
    }
    iVar6 = puVar2[1];
    pbVar7 = (byte *)*puVar2;
  }
  bVar1 = *pbVar7;
  pbVar7 = pbVar7 + 1;
  iVar3 = iVar6 + -1;
  if (iVar6 + -1 == 0) {
    iVar6 = (*(code *)puVar2[3])(param_1);
    if (iVar6 == 0) {
      return 0;
    }
    pbVar7 = (byte *)*puVar2;
    iVar3 = puVar2[1];
  }
  param_1 = (int *)iVar3;
  iVar3 = piVar5[0x69];
  iVar6 = (uint)bVar1 * 0x100 + -2 + (uint)*pbVar7;
  iVar4 = *piVar5;
  *(undefined4 *)(iVar4 + 0x14) = 0x5b;
  *(int *)(iVar4 + 0x18) = iVar3;
  *(int *)(iVar4 + 0x1c) = iVar6;
  (**(code **)(iVar4 + 4))(piVar5,1);
  puVar2[1] = (int)param_1 + -1;
  *puVar2 = pbVar7 + 1;
  if (0 < iVar6) {
    (**(code **)(piVar5[6] + 0x10))(piVar5,iVar6);
  }
  return 1;
}


// ==== FUN_008ecbc0 @ 0x008ecbc0 ====

undefined4 FUN_008ecbc0(int *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  
  puVar2 = (undefined4 *)param_1[6];
  iVar5 = puVar2[1];
  pbVar7 = (byte *)*puVar2;
  while( true ) {
    if (iVar5 == 0) {
      iVar5 = (*(code *)puVar2[3])(param_1);
      if (iVar5 == 0) {
        return 0;
      }
      pbVar7 = (byte *)*puVar2;
      iVar5 = puVar2[1];
    }
    bVar1 = *pbVar7;
    while( true ) {
      pbVar7 = pbVar7 + 1;
      iVar5 = iVar5 + -1;
      if (bVar1 == 0xff) break;
      *(int *)(param_1[0x6f] + 0x18) = *(int *)(param_1[0x6f] + 0x18) + 1;
      *puVar2 = pbVar7;
      puVar2[1] = iVar5;
      if (iVar5 == 0) {
        iVar5 = (*(code *)puVar2[3])(param_1);
        if (iVar5 == 0) {
          return 0;
        }
        pbVar7 = (byte *)*puVar2;
        iVar5 = puVar2[1];
      }
      bVar1 = *pbVar7;
    }
    do {
      if (iVar5 == 0) {
        iVar5 = (*(code *)puVar2[3])(param_1);
        if (iVar5 == 0) {
          return 0;
        }
        pbVar7 = (byte *)*puVar2;
        iVar5 = puVar2[1];
      }
      uVar6 = (uint)*pbVar7;
      iVar5 = iVar5 + -1;
      pbVar7 = pbVar7 + 1;
    } while (uVar6 == 0xff);
    if (uVar6 != 0) break;
    *(int *)(param_1[0x6f] + 0x18) = *(int *)(param_1[0x6f] + 0x18) + 2;
    *puVar2 = pbVar7;
    puVar2[1] = iVar5;
  }
  iVar3 = *(int *)(param_1[0x6f] + 0x18);
  if (iVar3 != 0) {
    iVar4 = *param_1;
    *(undefined4 *)(iVar4 + 0x14) = 0x74;
    *(int *)(iVar4 + 0x18) = iVar3;
    *(uint *)(iVar4 + 0x1c) = uVar6;
    (**(code **)(iVar4 + 4))(param_1,0xffffffff);
    *(undefined4 *)(param_1[0x6f] + 0x18) = 0;
  }
  *puVar2 = pbVar7;
  puVar2[1] = iVar5;
  param_1[0x69] = uVar6;
  return 1;
}


// ==== FUN_008eccd0 @ 0x008eccd0 ====

undefined4 FUN_008eccd0(int *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  
  puVar2 = (undefined4 *)param_1[6];
  pbVar6 = (byte *)*puVar2;
  iVar4 = puVar2[1];
  if (iVar4 == 0) {
    iVar4 = (*(code *)puVar2[3])(param_1);
    if (iVar4 == 0) {
      return 0;
    }
    pbVar6 = (byte *)*puVar2;
    iVar4 = puVar2[1];
  }
  bVar1 = *pbVar6;
  iVar4 = iVar4 + -1;
  pbVar6 = pbVar6 + 1;
  if (iVar4 == 0) {
    iVar4 = (*(code *)puVar2[3])(param_1);
    if (iVar4 == 0) {
      return 0;
    }
    pbVar6 = (byte *)*puVar2;
    iVar4 = puVar2[1];
  }
  uVar5 = (uint)*pbVar6;
  if ((bVar1 != 0xff) || (uVar5 != 0xd8)) {
    puVar3 = (undefined4 *)*param_1;
    puVar3[5] = 0x35;
    puVar3[6] = (uint)bVar1;
    puVar3[7] = uVar5;
    (*(code *)*puVar3)(param_1);
  }
  puVar2[1] = iVar4 + -1;
  *puVar2 = pbVar6 + 1;
  param_1[0x69] = uVar5;
  return 1;
}


// ==== FUN_008ecd70 @ 0x008ecd70 ====

undefined4 FUN_008ecd70(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
LAB_008ecd80:
  if (param_1[0x69] == 0) {
    if (*(int *)(param_1[0x6f] + 0xc) == 0) {
      iVar3 = FUN_008eccd0(param_1);
    }
    else {
      iVar3 = FUN_008ecbc0(param_1);
    }
    if (iVar3 == 0) {
      return 0;
    }
  }
  iVar3 = param_1[0x69];
  switch(iVar3) {
  case 1:
  case 0xd0:
  case 0xd1:
  case 0xd2:
  case 0xd3:
  case 0xd4:
  case 0xd5:
  case 0xd6:
  case 0xd7:
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x14) = 0x5c;
    *(int *)(iVar1 + 0x18) = iVar3;
    (**(code **)(iVar1 + 4))(param_1,1);
    param_1[0x69] = 0;
    goto LAB_008ecd80;
  default:
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0x44;
    puVar2[6] = iVar3;
    (*(code *)*puVar2)(param_1);
    goto LAB_008ecef0;
  case 0xc0:
  case 0xc1:
    break;
  case 0xc2:
    break;
  case 0xc3:
  case 0xc5:
  case 0xc6:
  case 199:
  case 200:
  case 0xcb:
  case 0xcd:
  case 0xce:
  case 0xcf:
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0x3c;
    puVar2[6] = iVar3;
    (*(code *)*puVar2)(param_1);
    param_1[0x69] = 0;
    goto LAB_008ecd80;
  case 0xc4:
    iVar3 = FUN_008ec070();
    if (iVar3 == 0) {
      return 0;
    }
    param_1[0x69] = 0;
    goto LAB_008ecd80;
  case 0xc9:
    iVar3 = FUN_008ebad0();
    if (iVar3 == 0) {
      return 0;
    }
LAB_008ecef0:
    param_1[0x69] = 0;
    goto LAB_008ecd80;
  case 0xca:
    break;
  case 0xcc:
  case 0xdc:
    iVar3 = FUN_008ecb10(param_1);
    if (iVar3 == 0) {
      return 0;
    }
    param_1[0x69] = 0;
    goto LAB_008ecd80;
  case 0xd8:
    iVar3 = FUN_008eba20();
    goto LAB_008ece04;
  case 0xd9:
    iVar3 = *param_1;
    *(undefined4 *)(iVar3 + 0x14) = 0x55;
    (**(code **)(iVar3 + 4))(param_1,1);
    param_1[0x69] = 0;
    return 2;
  case 0xda:
    iVar3 = FUN_008ebdb0();
    if (iVar3 == 0) {
      return 0;
    }
    param_1[0x69] = 0;
    return 1;
  case 0xdb:
    iVar3 = FUN_008ec3f0(param_1);
    if (iVar3 == 0) {
      return 0;
    }
    param_1[0x69] = 0;
    goto LAB_008ecd80;
  case 0xdd:
    iVar3 = FUN_008ec640(param_1);
    if (iVar3 == 0) {
      return 0;
    }
    param_1[0x69] = 0;
    goto LAB_008ecd80;
  case 0xe0:
  case 0xe1:
  case 0xe2:
  case 0xe3:
  case 0xe4:
  case 0xe5:
  case 0xe6:
  case 0xe7:
  case 0xe8:
  case 0xe9:
  case 0xea:
  case 0xeb:
  case 0xec:
  case 0xed:
  case 0xee:
  case 0xef:
    iVar3 = (**(code **)(param_1[0x6f] + -0x360 + iVar3 * 4))(param_1);
    if (iVar3 == 0) {
      return 0;
    }
    param_1[0x69] = 0;
    goto LAB_008ecd80;
  case 0xfe:
    goto switchD_008ecdc0_caseD_fe;
  }
  iVar3 = FUN_008ebad0();
LAB_008ece04:
  if (iVar3 == 0) {
    return 0;
  }
  param_1[0x69] = 0;
  goto LAB_008ecd80;
switchD_008ecdc0_caseD_fe:
  iVar3 = (**(code **)(param_1[0x6f] + 0x1c))(param_1);
  if (iVar3 == 0) {
    return 0;
  }
  param_1[0x69] = 0;
  goto LAB_008ecd80;
}


// ==== FUN_008ed080 @ 0x008ed080 ====

undefined4 FUN_008ed080(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1[0x69] == 0) && (iVar2 = FUN_008ecbc0(param_1), iVar2 == 0)) {
    return 0;
  }
  iVar2 = param_1[0x6f];
  iVar1 = *(int *)(iVar2 + 0x14);
  if (param_1[0x69] == iVar1 + 0xd0) {
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x14) = 0x62;
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar2 + 0x14);
    (**(code **)(iVar1 + 4))(param_1,3);
    param_1[0x69] = 0;
  }
  else {
    iVar2 = (**(code **)(param_1[6] + 0x14))(param_1,iVar1);
    if (iVar2 == 0) {
      return 0;
    }
  }
  *(uint *)(param_1[0x6f] + 0x14) = *(int *)(param_1[0x6f] + 0x14) + 1U & 7;
  return 1;
}


// ==== FUN_008ed110 @ 0x008ed110 ====

undefined4 FUN_008ed110(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar2 = param_1[0x69];
  *(undefined4 *)(iVar3 + 0x14) = 0x79;
  *(int *)(iVar3 + 0x18) = iVar2;
  *(int *)(iVar3 + 0x1c) = param_2;
  (**(code **)(iVar3 + 4))(param_1,0xffffffff);
  do {
    if (iVar2 < 0xc0) {
LAB_008ed148:
      iVar3 = 2;
    }
    else if ((((iVar2 < 0xd0) || (0xd7 < iVar2)) || (iVar2 == (param_2 + 1U & 7) + 0xd0)) ||
            (iVar2 == (param_2 + 2U & 7) + 0xd0)) {
      iVar3 = 3;
    }
    else {
      if ((iVar2 == (param_2 - 1U & 7) + 0xd0) || (iVar2 == (param_2 - 2U & 7) + 0xd0))
      goto LAB_008ed148;
      iVar3 = 1;
    }
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x14) = 0x61;
    *(int *)(iVar1 + 0x18) = iVar2;
    *(int *)(iVar1 + 0x1c) = iVar3;
    (**(code **)(iVar1 + 4))(param_1,4);
    if (iVar3 == 1) {
      param_1[0x69] = 0;
      return 1;
    }
    if (iVar3 == 2) {
      iVar3 = FUN_008ecbc0(param_1);
      if (iVar3 == 0) {
        return 0;
      }
      iVar2 = param_1[0x69];
    }
    else if (iVar3 == 3) {
      return 1;
    }
  } while( true );
}


// ==== FUN_008ed210 @ 0x008ed210 ====

void FUN_008ed210(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1bc);
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0xa4) = 0;
  return;
}


// ==== FUN_008ed250 @ 0x008ed250 ====

void FUN_008ed250(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0xac);
  *(undefined4 **)(param_1 + 0x1bc) = puVar1;
  *puVar1 = FUN_008ed210;
  puVar1[1] = FUN_008ecd70;
  puVar1[2] = FUN_008ed080;
  puVar1[7] = FUN_008ecb10;
  puVar1[0x18] = 0;
  puVar2 = puVar1 + 0x19;
  iVar3 = 0x10;
  do {
    puVar2[-0x11] = FUN_008ecb10;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar1[8] = FUN_008ec9a0;
  puVar1[0x16] = FUN_008ec9a0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[6] = 0;
  puVar1[0x29] = 0;
  return;
}


// ==== FUN_008ed2e0 @ 0x008ed2e0 ====

void FUN_008ed2e0(int *param_1)

{
  (**(code **)(*param_1 + 8))(param_1);
  FUN_0090b660(param_1);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


// ==== FUN_008ed300 @ 0x008ed300 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008ed300(int *param_1)

{
  undefined1 local_d0 [200];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  (**(code **)(*param_1 + 0xc))(param_1,local_d0);
  return;
}


// ==== FUN_008ed340 @ 0x008ed340 ====

void FUN_008ed340(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (-1 < param_2) {
    if (param_2 <= *(int *)(iVar1 + 0x68)) {
      (**(code **)(iVar1 + 8))(param_1);
    }
    return;
  }
  if ((*(int *)(iVar1 + 0x6c) == 0) || (2 < *(int *)(iVar1 + 0x68))) {
    (**(code **)(iVar1 + 8))(param_1);
  }
  *(int *)(iVar1 + 0x6c) = *(int *)(iVar1 + 0x6c) + 1;
  return;
}


// ==== FUN_008ed380 @ 0x008ed380 ====

void FUN_008ed380(int *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *_Format;
  char *pcVar4;
  
  iVar2 = *param_1;
  iVar3 = *(int *)(iVar2 + 0x14);
  if ((iVar3 < 1) || (*(int *)(iVar2 + 0x74) < iVar3)) {
    if ((*(int *)(iVar2 + 0x78) != 0) &&
       ((*(int *)(iVar2 + 0x7c) <= iVar3 && (iVar3 <= *(int *)(iVar2 + 0x80))))) {
      _Format = *(char **)(*(int *)(iVar2 + 0x78) + (iVar3 - *(int *)(iVar2 + 0x7c)) * 4);
      goto LAB_008ed3bd;
    }
  }
  else {
    _Format = *(char **)(*(int *)(iVar2 + 0x70) + iVar3 * 4);
LAB_008ed3bd:
    if (_Format != (char *)0x0) goto LAB_008ed3c9;
  }
  *(int *)(iVar2 + 0x18) = iVar3;
  _Format = (char *)**(undefined4 **)(iVar2 + 0x70);
LAB_008ed3c9:
  cVar1 = *_Format;
  pcVar4 = _Format;
  do {
    if (cVar1 == '\0') {
LAB_008ed3dd:
      _sprintf(param_2,_Format,*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c),
               *(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x24),
               *(undefined4 *)(iVar2 + 0x28),*(undefined4 *)(iVar2 + 0x2c),
               *(undefined4 *)(iVar2 + 0x30),*(undefined4 *)(iVar2 + 0x34));
      return;
    }
    pcVar4 = pcVar4 + 1;
    if (cVar1 == '%') {
      if (*pcVar4 == 's') {
        _sprintf(param_2,_Format,iVar2 + 0x18);
        return;
      }
      goto LAB_008ed3dd;
    }
    cVar1 = *pcVar4;
  } while( true );
}


// ==== FUN_008ed430 @ 0x008ed430 ====

void FUN_008ed430(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x6c) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  return;
}


// ==== FUN_008ed450 @ 0x008ed450 ====

void FUN_008ed450(undefined4 *param_1)

{
  *param_1 = FUN_008ed2e0;
  param_1[1] = FUN_008ed340;
  param_1[2] = FUN_008ed300;
  param_1[3] = FUN_008ed380;
  param_1[4] = FUN_008ed430;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[5] = 0;
  param_1[0x1c] = &PTR_s_Bogus_message_code__d_00a231e8;
  param_1[0x1d] = 0x7b;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  return;
}


// ==== FUN_008ed4b0 @ 0x008ed4b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008ed4b0(int *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar5;
  int *piVar6;
  
  param_1[1] = 0;
  if (param_2 != 0x3e) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0xc;
    puVar1[6] = 0x3e;
    puVar1[7] = param_2;
    (*(code *)*puVar1)(param_1);
  }
  if (param_3 != 0x180) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x15;
    puVar1[6] = 0x180;
    puVar1[7] = param_3;
    (*(code *)*puVar1)(param_1);
  }
  iVar2 = param_1[3];
  iVar3 = *param_1;
  piVar6 = param_1;
  for (iVar5 = 0x60; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  *param_1 = iVar3;
  param_1[3] = iVar2;
  param_1[4] = 0;
  FUN_0090b560(param_1);
  param_1[2] = 0;
  uVar4 = _DAT_0099d0a0;
  param_1[6] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x1a] = 0;
  param_1[0x17] = 0;
  param_1[0x1b] = 0;
  param_1[0x18] = 0;
  param_1[0x1c] = 0;
  param_1[0x19] = 0;
  param_1[0x1d] = 0;
  *(undefined8 *)(param_1 + 0xc) = uVar4;
  param_1[0x5e] = 0;
  param_1[5] = 100;
  return;
}


// ==== FUN_008ed570 @ 0x008ed570 ====

void FUN_008ed570(void)

{
  FUN_0090b660();
  return;
}


// ==== FUN_008ed580 @ 0x008ed580 ====

void FUN_008ed580(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x48) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x80) = param_2;
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x80) = param_2;
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x80) = param_2;
  }
  if (*(int *)(param_1 + 0x54) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x80) = param_2;
  }
  piVar1 = (int *)(param_1 + 0x68);
  iVar2 = 4;
  do {
    if (piVar1[-4] != 0) {
      *(undefined4 *)(piVar1[-4] + 0x114) = param_2;
    }
    if (*piVar1 != 0) {
      *(undefined4 *)(*piVar1 + 0x114) = param_2;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== FUN_008ed5f0 @ 0x008ed5f0 ====

void FUN_008ed5f0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = param_1[5];
  if ((iVar2 == 0x65) || (iVar2 == 0x66)) {
    if ((uint)param_1[0x3a] < (uint)param_1[8]) {
      puVar1 = (undefined4 *)*param_1;
      puVar1[5] = 0x43;
      (*(code *)*puVar1)(param_1);
    }
    (**(code **)(param_1[0x55] + 8))(param_1);
  }
  else if (iVar2 != 0x67) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x14;
    puVar1[6] = iVar2;
    (*(code *)*puVar1)(param_1);
  }
  puVar1 = (undefined4 *)param_1[0x55];
  iVar2 = puVar1[4];
  while (iVar2 == 0) {
    (*(code *)*puVar1)(param_1);
    uVar3 = param_1[0x3e];
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        puVar1 = (undefined4 *)param_1[2];
        if (puVar1 != (undefined4 *)0x0) {
          puVar1[1] = uVar4;
          puVar1[2] = uVar3;
          (*(code *)*puVar1)(param_1);
        }
        iVar2 = (**(code **)(param_1[0x58] + 4))(param_1,0);
        if (iVar2 == 0) {
          puVar1 = (undefined4 *)*param_1;
          puVar1[5] = 0x18;
          (*(code *)*puVar1)(param_1);
        }
        uVar3 = param_1[0x3e];
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
    }
    (**(code **)(param_1[0x55] + 8))(param_1);
    puVar1 = (undefined4 *)param_1[0x55];
    iVar2 = puVar1[4];
  }
  (**(code **)(param_1[0x59] + 0xc))(param_1);
  (**(code **)(param_1[6] + 0x10))(param_1);
  FUN_0090b620(param_1);
  return;
}


// ==== FUN_008ed6d0 @ 0x008ed6d0 ====

void FUN_008ed6d0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = param_1[5];
  if (iVar1 != 100) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0x14;
    puVar2[6] = iVar1;
    (*(code *)*puVar2)(param_1);
  }
  if (param_2 != 0) {
    FUN_008ed580(param_1,0);
  }
  (**(code **)(*param_1 + 0x10))(param_1);
  (**(code **)(param_1[6] + 8))(param_1);
  FUN_0090c8a0(param_1);
  (**(code **)param_1[0x55])(param_1);
  param_1[0x3a] = 0;
  param_1[5] = (param_1[0x2c] != 0) + 0x65;
  return;
}


// ==== FUN_008ed740 @ 0x008ed740 ====

void FUN_008ed740(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  
  piVar3 = param_1;
  iVar1 = param_1[5];
  if (iVar1 != 0x65) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0x14;
    puVar2[6] = iVar1;
    (*(code *)*puVar2)(param_1);
  }
  if ((uint)piVar3[8] <= (uint)piVar3[0x3a]) {
    iVar1 = *piVar3;
    *(undefined4 *)(iVar1 + 0x14) = 0x7b;
    (**(code **)(iVar1 + 4))(piVar3,0xffffffff);
  }
  puVar2 = (undefined4 *)piVar3[2];
  if (puVar2 != (undefined4 *)0x0) {
    iVar1 = piVar3[8];
    puVar2[1] = piVar3[0x3a];
    puVar2[2] = iVar1;
    (*(code *)*puVar2)(piVar3);
  }
  if (*(int *)(piVar3[0x55] + 0xc) != 0) {
    (**(code **)(piVar3[0x55] + 4))(piVar3);
  }
  uVar4 = param_3;
  if ((uint)(piVar3[8] - piVar3[0x3a]) < param_3) {
    uVar4 = piVar3[8] - piVar3[0x3a];
  }
  param_1 = (int *)0x0;
  (**(code **)(piVar3[0x56] + 4))(piVar3,param_2,&param_1,uVar4);
  piVar3[0x3a] = piVar3[0x3a] + (int)param_1;
  return;
}


// ==== FUN_008ed7f0 @ 0x008ed7f0 ====

void FUN_008ed7f0(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined2 *puVar6;
  
  iVar3 = param_1[5];
  if (iVar3 != 100) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x14;
    puVar1[6] = iVar3;
    (*(code *)*puVar1)(param_1);
  }
  if ((param_2 < 0) || (3 < param_2)) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x1f;
    puVar1[6] = param_2;
    (*(code *)*puVar1)(param_1);
  }
  if (param_1[param_2 + 0x12] == 0) {
    iVar3 = FUN_0090b690(param_1);
    param_1[param_2 + 0x12] = iVar3;
  }
  iVar3 = param_1[param_2 + 0x12];
  puVar6 = (undefined2 *)(iVar3 + 4);
  piVar5 = (int *)(param_3 + 8);
  param_1 = (int *)0x10;
  do {
    iVar4 = (piVar5[-2] * param_4 + 0x32) / 100;
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    else if (0x7fff < iVar4) {
      iVar4 = 0x7fff;
    }
    if ((param_5 != 0) && (0xff < iVar4)) {
      iVar4 = 0xff;
    }
    iVar2 = piVar5[-1];
    puVar6[-2] = (short)iVar4;
    iVar4 = (iVar2 * param_4 + 0x32) / 100;
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    else if (0x7fff < iVar4) {
      iVar4 = 0x7fff;
    }
    if ((param_5 != 0) && (0xff < iVar4)) {
      iVar4 = 0xff;
    }
    iVar2 = *piVar5;
    puVar6[-1] = (short)iVar4;
    iVar4 = (iVar2 * param_4 + 0x32) / 100;
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    else if (0x7fff < iVar4) {
      iVar4 = 0x7fff;
    }
    if ((param_5 != 0) && (0xff < iVar4)) {
      iVar4 = 0xff;
    }
    iVar2 = piVar5[1];
    *puVar6 = (short)iVar4;
    iVar4 = (iVar2 * param_4 + 0x32) / 100;
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    else if (0x7fff < iVar4) {
      iVar4 = 0x7fff;
    }
    if ((param_5 != 0) && (0xff < iVar4)) {
      iVar4 = 0xff;
    }
    puVar6[1] = (short)iVar4;
    piVar5 = piVar5 + 4;
    puVar6 = puVar6 + 4;
    param_1 = (int *)((int)param_1 + -1);
  } while (param_1 != (int *)0x0);
  *(undefined4 *)(iVar3 + 0x80) = 0;
  return;
}


// ==== FUN_008ed9b0 @ 0x008ed9b0 ====

void FUN_008ed9b0(int *param_1,undefined4 *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined4 *in_EAX;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  int *unaff_EBX;
  uint uVar9;
  undefined4 *puVar10;
  
  if (*unaff_EBX == 0) {
    iVar6 = FUN_0090b6c0(param_1);
    *unaff_EBX = iVar6;
  }
  puVar10 = (undefined4 *)*unaff_EBX;
  *puVar10 = *in_EAX;
  puVar10[1] = in_EAX[1];
  puVar10[2] = in_EAX[2];
  uVar4 = *(undefined1 *)(in_EAX + 4);
  puVar10[3] = in_EAX[3];
  *(undefined1 *)(puVar10 + 4) = uVar4;
  uVar9 = 0;
  pbVar7 = (byte *)((int)in_EAX + 3);
  iVar6 = 4;
  do {
    pbVar1 = pbVar7 + -1;
    pbVar2 = pbVar7 + -2;
    pbVar3 = pbVar7 + 1;
    bVar5 = *pbVar7;
    pbVar7 = pbVar7 + 4;
    iVar6 = iVar6 + -1;
    uVar9 = bVar5 + uVar9 + (uint)*pbVar2 + (uint)*pbVar1 + (uint)*pbVar3;
  } while (iVar6 != 0);
  if (((int)uVar9 < 1) || (0x100 < (int)uVar9)) {
    puVar10 = (undefined4 *)*param_1;
    puVar10[5] = 8;
    (*(code *)*puVar10)(param_1);
  }
  iVar6 = *unaff_EBX;
  puVar10 = (undefined4 *)(iVar6 + 0x11);
  for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar10 = *param_2;
    param_2 = param_2 + 1;
    puVar10 = puVar10 + 1;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined1 *)puVar10 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar10 = (undefined4 *)((int)puVar10 + 1);
  }
  *(undefined4 *)(iVar6 + 0x114) = 0;
  return;
}


// ==== FUN_008eda60 @ 0x008eda60 ====

void FUN_008eda60(void)

{
  undefined4 unaff_ESI;
  
  FUN_008ed9b0(unaff_ESI,&DAT_00a24a10);
  FUN_008ed9b0(unaff_ESI,&DAT_00a24958);
  FUN_008ed9b0(unaff_ESI,&DAT_00a24a10);
  FUN_008ed9b0(unaff_ESI,&DAT_00a24888);
  return;
}


// ==== FUN_008edac0 @ 0x008edac0 ====

void FUN_008edac0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = param_1[5];
  if (iVar1 != 100) {
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 0x14;
    puVar2[6] = iVar1;
    (*(code *)*puVar2)(param_1);
  }
  param_1[0x10] = param_2;
  param_1[0x34] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 1;
  param_1[0x39] = 1;
  switch(param_2) {
  case 0:
    iVar1 = param_1[9];
    param_1[0xf] = iVar1;
    if ((iVar1 < 1) || (10 < iVar1)) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 0x1a;
      puVar2[6] = iVar1;
      puVar2[7] = 10;
      (*(code *)*puVar2)(param_1);
    }
    iVar1 = param_1[0xf];
    iVar3 = 0;
    if (0 < iVar1) {
      piVar4 = (int *)param_1[0x11];
      do {
        *piVar4 = iVar3;
        piVar4[2] = 1;
        piVar4[3] = 1;
        piVar4[4] = 0;
        piVar4[5] = 0;
        piVar4[6] = 0;
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 0x15;
      } while (iVar3 < iVar1);
      return;
    }
    break;
  case 1:
    param_1[0x34] = 1;
    param_1[0xf] = 1;
    puVar2 = (undefined4 *)param_1[0x11];
    *puVar2 = 1;
    puVar2[2] = 1;
    puVar2[3] = 1;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    return;
  case 2:
    param_1[0x37] = 1;
    param_1[0xf] = 3;
    puVar2 = (undefined4 *)param_1[0x11];
    puVar2[2] = 1;
    puVar2[3] = 1;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    *puVar2 = 0x52;
    puVar2[0x17] = 1;
    puVar2[0x18] = 1;
    puVar2[0x19] = 0;
    puVar2[0x1a] = 0;
    puVar2[0x1b] = 0;
    puVar2[0x15] = 0x47;
    puVar2[0x2c] = 1;
    puVar2[0x2d] = 1;
    puVar2[0x2e] = 0;
    puVar2[0x2f] = 0;
    puVar2[0x30] = 0;
    puVar2[0x2a] = 0x42;
    return;
  case 3:
    param_1[0x34] = 1;
    param_1[0xf] = 3;
    puVar2 = (undefined4 *)param_1[0x11];
    *puVar2 = 1;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[2] = 2;
    puVar2[3] = 2;
    puVar2[0x17] = 1;
    puVar2[0x18] = 1;
    puVar2[0x19] = 1;
    puVar2[0x1a] = 1;
    puVar2[0x1b] = 1;
    puVar2[0x15] = 2;
    puVar2[0x2c] = 1;
    puVar2[0x2d] = 1;
    puVar2[0x2e] = 1;
    puVar2[0x2f] = 1;
    puVar2[0x30] = 1;
    puVar2[0x2a] = 3;
    return;
  case 4:
    param_1[0x37] = 1;
    param_1[0xf] = 4;
    puVar2 = (undefined4 *)param_1[0x11];
    puVar2[2] = 1;
    puVar2[3] = 1;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    *puVar2 = 0x43;
    puVar2[0x17] = 1;
    puVar2[0x18] = 1;
    puVar2[0x19] = 0;
    puVar2[0x1a] = 0;
    puVar2[0x1b] = 0;
    puVar2[0x15] = 0x4d;
    puVar2[0x2c] = 1;
    puVar2[0x2d] = 1;
    puVar2[0x2e] = 0;
    puVar2[0x2f] = 0;
    puVar2[0x30] = 0;
    puVar2[0x2a] = 0x59;
    puVar2[0x41] = 1;
    puVar2[0x42] = 1;
    puVar2[0x43] = 0;
    puVar2[0x44] = 0;
    puVar2[0x45] = 0;
    puVar2[0x3f] = 0x4b;
    return;
  case 5:
    puVar2 = (undefined4 *)param_1[0x11];
    *puVar2 = 1;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[2] = 2;
    puVar2[3] = 2;
    puVar2[0x17] = 1;
    puVar2[0x18] = 1;
    puVar2[0x19] = 1;
    puVar2[0x1a] = 1;
    puVar2[0x1b] = 1;
    puVar2[0x15] = 2;
    puVar2[0x2c] = 1;
    puVar2[0x2d] = 1;
    puVar2[0x2e] = 1;
    puVar2[0x2f] = 1;
    puVar2[0x30] = 1;
    puVar2[0x2a] = 3;
    param_1[0x37] = 1;
    param_1[0xf] = 4;
    puVar2[0x43] = 0;
    puVar2[0x44] = 0;
    puVar2[0x45] = 0;
    puVar2[0x3f] = 4;
    puVar2[0x41] = 2;
    puVar2[0x42] = 2;
    return;
  default:
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 10;
    (*(code *)*puVar2)(param_1);
  }
  return;
}


// ==== FUN_008eddb0 @ 0x008eddb0 ====

void FUN_008eddb0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  switch(param_1[10]) {
  case 0:
    FUN_008edac0(param_1,0);
    return;
  case 1:
  case 8:
    iVar1 = param_1[5];
    if (iVar1 != 100) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 0x14;
      puVar2[6] = iVar1;
      (*(code *)*puVar2)(param_1);
    }
    break;
  case 2:
  case 3:
  case 6:
  case 7:
    FUN_008edac0(param_1,3);
    return;
  case 4:
    FUN_008edac0(param_1,4);
    return;
  case 5:
    iVar1 = param_1[5];
    if (iVar1 != 100) {
      puVar2 = (undefined4 *)*param_1;
      puVar2[5] = 0x14;
      puVar2[6] = iVar1;
      (*(code *)*puVar2)(param_1);
    }
    puVar2 = (undefined4 *)param_1[0x11];
    *puVar2 = 1;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    param_1[0x10] = 5;
    param_1[0x34] = 0;
    param_1[0x38] = 1;
    param_1[0x39] = 1;
    param_1[0x37] = 1;
    param_1[0xf] = 4;
    puVar2[2] = 2;
    puVar2[3] = 2;
    puVar2[0x15] = 2;
    puVar2[0x17] = 1;
    puVar2[0x18] = 1;
    puVar2[0x19] = 1;
    puVar2[0x1a] = 1;
    puVar2[0x1b] = 1;
    puVar2[0x2a] = 3;
    puVar2[0x2c] = 1;
    puVar2[0x2d] = 1;
    puVar2[0x2e] = 1;
    puVar2[0x2f] = 1;
    puVar2[0x30] = 1;
    puVar2[0x41] = 2;
    puVar2[0x42] = 2;
    puVar2[0x3f] = 4;
    puVar2[0x43] = 0;
    puVar2[0x44] = 0;
    puVar2[0x45] = 0;
    return;
  default:
    puVar2 = (undefined4 *)*param_1;
    puVar2[5] = 9;
    (*(code *)*puVar2)(param_1);
    return;
  }
  param_1[0x10] = 1;
  param_1[0x37] = 0;
  param_1[0x38] = 1;
  param_1[0x39] = 1;
  param_1[0x34] = 1;
  param_1[0xf] = 1;
  puVar2 = (undefined4 *)param_1[0x11];
  *puVar2 = 1;
  puVar2[2] = 1;
  puVar2[3] = 1;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  return;
}


// ==== FUN_008edf50 @ 0x008edf50 ====

void FUN_008edf50(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = param_1[5];
  if (iVar2 != 100) {
    puVar1 = (undefined4 *)*param_1;
    puVar1[5] = 0x14;
    puVar1[6] = iVar2;
    (*(code *)*puVar1)(param_1);
  }
  if (param_1[0x11] == 0) {
    iVar2 = (**(code **)param_1[1])(param_1,0,0x348);
    param_1[0x11] = iVar2;
  }
  param_1[0xe] = 8;
  FUN_008ed7f0(param_1,0,&DAT_00a24770,0x32,1);
  FUN_008ed7f0(param_1,1,&DAT_00a24670,0x32,1);
  FUN_008eda60();
  piVar3 = param_1 + 0x22;
  iVar2 = 0x10;
  do {
    *(undefined1 *)(piVar3 + -4) = 0;
    *(undefined1 *)piVar3 = 1;
    *(undefined1 *)(piVar3 + 4) = 5;
    piVar3 = (int *)((int)piVar3 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0x2b] = 0;
  param_1[0x2a] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  if (8 < param_1[0xe]) {
    param_1[0x2e] = 1;
  }
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  *(undefined1 *)(param_1 + 0x35) = 1;
  *(undefined1 *)((int)param_1 + 0xd5) = 1;
  *(undefined1 *)((int)param_1 + 0xd6) = 0;
  *(undefined2 *)(param_1 + 0x36) = 1;
  *(undefined2 *)((int)param_1 + 0xda) = 1;
  FUN_008eddb0(param_1);
  return;
}


// ==== FUN_008ee04b @ 0x008ee04b ====

void FUN_008ee04b(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar3 = 0;
  iVar6 = 0;
  do {
    bVar2 = *(byte *)(param_1 + 0x10c + iVar6);
    uVar5 = (uint)bVar2;
    iVar6 = iVar6 + 1;
    if (((uVar5 < 0x29) || (0x7a < uVar5)) || ((0x5a < uVar5 && (uVar5 < 0x61)))) {
      *(undefined1 *)(iVar3 + in_ECX) = 0x5b;
      *(undefined *)(iVar3 + 1 + in_ECX) = (&DAT_00a24a1c)[(int)uVar5 >> 4];
      *(undefined *)(iVar3 + 2 + in_ECX) = (&DAT_00a24a1c)[uVar5 & 0xf];
      iVar4 = iVar3 + 3;
      *(undefined1 *)(iVar4 + in_ECX) = 0x5d;
    }
    else {
      *(byte *)(iVar3 + in_ECX) = bVar2;
      iVar4 = iVar3;
    }
    iVar3 = iVar4 + 1;
  } while (iVar6 < 4);
  if (param_2 == (undefined4 *)0x0) {
    *(undefined1 *)(iVar3 + in_ECX) = 0;
  }
  else {
    *(undefined1 *)(iVar3 + in_ECX) = 0x3a;
    *(undefined1 *)(iVar4 + 2 + in_ECX) = 0x20;
    puVar1 = (undefined4 *)(iVar4 + 3 + in_ECX);
    puVar7 = puVar1;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *param_2;
      param_2 = param_2 + 1;
      puVar7 = puVar7 + 1;
    }
    *(undefined1 *)((int)puVar1 + 0x3f) = 0;
  }
  return;
}


// ==== FUN_008ee0d7 @ 0x008ee0d7 ====

void FUN_008ee0d7(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x48) = param_2;
  *(undefined4 *)(param_1 + 0x40) = param_3;
  *(undefined4 *)(param_1 + 0x44) = param_4;
  return;
}


// ==== FUN_008ee0f5 @ 0x008ee0f5 ====

void FUN_008ee0f5(int *param_1,undefined4 param_2)

{
  if ((code *)param_1[0x10] != (code *)0x0) {
    (*(code *)param_1[0x10])(param_1,param_2);
  }
                    /* WARNING: Subroutine does not return */
  _longjmp(param_1,1);
}


// ==== FUN_008ee116 @ 0x008ee116 ====

void FUN_008ee116(int param_1,undefined4 param_2)

{
  if (*(code **)(param_1 + 0x44) != (code *)0x0) {
    (**(code **)(param_1 + 0x44))(param_1,param_2);
  }
  return;
}


// ==== FUN_008ee131 @ 0x008ee131 ====

void FUN_008ee131(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined1 local_58 [80];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  FUN_008ee04b(param_1,param_2);
  FUN_008ee0f5(param_1,local_58);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_008ee15d @ 0x008ee15d ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008ee15d(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_58 [80];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  FUN_008ee04b(param_1,param_2);
  FUN_008ee116(param_1,local_58);
  return;
}


// ==== FUN_008ee195 @ 0x008ee195 ====

int FUN_008ee195(int param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  bool bVar3;
  bool bVar4;
  
  if (param_3 < 9) {
    if (param_3 == 0) {
      return 0;
    }
  }
  else {
    param_3 = 8;
  }
  if (7 < param_2) {
    return 0;
  }
  if (8 < param_2 + param_3) {
    param_3 = 8 - param_2;
  }
  bVar3 = false;
  bVar4 = true;
  pbVar1 = (byte *)(param_1 + param_2);
  pbVar2 = &DAT_00a24a2c + param_2;
  do {
    if (param_3 == 0) break;
    param_3 = param_3 - 1;
    bVar3 = *pbVar1 < *pbVar2;
    bVar4 = *pbVar1 == *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  } while (bVar4);
  if (bVar4) {
    return 0;
  }
  return (1 - (uint)bVar3) - (uint)(bVar3 != 0);
}


// ==== FUN_008ee1e3 @ 0x008ee1e3 ====

undefined4 * FUN_008ee1e3(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_2 * param_3;
  puVar1 = (undefined4 *)FUN_0090c9a9(param_1,uVar5);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    if (uVar5 < 0x8001) {
      puVar2 = puVar1;
    }
    else {
      puVar2 = puVar1;
      for (iVar3 = 0x2000; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      uVar5 = uVar5 - 0x8000;
      puVar2 = puVar1 + 0x2000;
    }
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar2 = 0;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
    puVar2 = puVar1;
  }
  return puVar2;
}


// ==== FUN_008ee239 @ 0x008ee239 ====

void FUN_008ee239(void)

{
  FUN_0090c9e2();
  return;
}


// ==== FUN_008ee244 @ 0x008ee244 ====

void FUN_008ee244(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0090ca5e(0,0,0);
  *(undefined4 *)(param_1 + 0x100) = uVar1;
  return;
}


// ==== FUN_008ee260 @ 0x008ee260 ====

void FUN_008ee260(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 0x10c) & 0x20) == 0) {
    if ((*(byte *)(param_1 + 0x5d) & 8) != 0) {
      return;
    }
  }
  else if ((*(uint *)(param_1 + 0x5c) & 0x300) == 0x300) {
    return;
  }
  uVar1 = FUN_0090ca5e(*(undefined4 *)(param_1 + 0x100),param_2,param_3);
  *(undefined4 *)(param_1 + 0x100) = uVar1;
  return;
}


// ==== FUN_008ee2a2 @ 0x008ee2a2 ====

void FUN_008ee2a2(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = 0;
    param_2 = param_2 + 1;
  }
  return;
}


// ==== FUN_008ee2b7 @ 0x008ee2b7 ====

undefined4 FUN_008ee2b7(int param_1)

{
  return *(undefined4 *)(param_1 + 0x54);
}


// ==== FUN_008ee2c6 @ 0x008ee2c6 ====

undefined4 * FUN_008ee2c6(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)FUN_0090c949(2);
    if (puVar1 != (undefined4 *)0x0) {
      puVar3 = puVar1;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
    }
  }
  return puVar1;
}


// ==== FUN_008ee2f3 @ 0x008ee2f3 ====

void FUN_008ee2f3(undefined4 param_1,undefined4 *param_2)

{
  FUN_0090cc13(param_1);
  FUN_0090d074(param_1,*param_2,param_2[1],*(undefined1 *)(param_2 + 6),
               *(undefined1 *)((int)param_2 + 0x19),*(undefined1 *)((int)param_2 + 0x1a),
               *(undefined1 *)((int)param_2 + 0x1b),*(undefined1 *)(param_2 + 7));
  if ((*(byte *)(param_2 + 2) & 8) == 0) {
    if (*(char *)((int)param_2 + 0x19) == '\x03') {
      FUN_008ee0f5(param_1,s_Valid_palette_required_for_palet_00a24a40);
    }
  }
  else {
    FUN_0090cc39(param_1,param_2[4],*(undefined2 *)(param_2 + 5));
  }
  return;
}


// ==== FUN_008ee357 @ 0x008ee357 ====

void FUN_008ee357(int param_1)

{
  if ((*(byte *)(param_1 + 0x58) & 4) == 0) {
    FUN_008ee0f5(param_1,s_No_IDATs_written_into_file_00a24a6c);
  }
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 8;
  FUN_0090d340(param_1);
  return;
}


// ==== FUN_008ee380 @ 0x008ee380 ====

void FUN_008ee380(int param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  bool bVar5;
  
  if ((*(int *)(param_1 + 0xd4) == 0) && (*(char *)(param_1 + 0x114) == '\0')) {
    if ((*(byte *)(param_1 + 0x61) & 0x80) != 0) {
      FUN_008ee116(param_1,s_PNG_WRITE_FILLER_SUPPORTED_is_no_00a24b34);
    }
    if ((*(byte *)(param_1 + 0x60) & 4) != 0) {
      FUN_008ee116(param_1,s_PNG_WRITE_PACK_SUPPORTED_is_not_d_00a24b08);
    }
    if ((*(byte *)(param_1 + 0x60) & 8) != 0) {
      FUN_008ee116(param_1,s_PNG_WRITE_SHIFT_SUPPORTED_is_not_00a24adc);
    }
    if ((*(byte *)(param_1 + 0x60) & 1) != 0) {
      FUN_008ee116(param_1,s_PNG_WRITE_BGR_SUPPORTED_is_not_d_00a24ab4);
    }
    if ((*(byte *)(param_1 + 0x60) & 0x10) != 0) {
      FUN_008ee116(param_1,s_PNG_WRITE_SWAP_SUPPORTED_is_not_d_00a24a88);
    }
    FUN_0090cccb(param_1);
  }
  if ((*(char *)(param_1 + 0x113) == '\0') || ((*(byte *)(param_1 + 0x60) & 2) == 0)) {
LAB_008ee498:
    *(undefined1 *)(param_1 + 0xf8) = *(undefined1 *)(param_1 + 0x116);
    *(char *)(param_1 + 0xf9) = *(char *)(param_1 + 0x118);
    bVar3 = *(char *)(param_1 + 0x118) * *(char *)(param_1 + 0x11b);
    *(byte *)(param_1 + 0xfb) = bVar3;
    uVar4 = (uint)bVar3 * *(int *)(param_1 + 0xc4) + 7 >> 3;
    *(uint *)(param_1 + 0xf4) = uVar4;
    piVar1 = (int *)(param_1 + 0xf0);
    *piVar1 = *(int *)(param_1 + 0xc4);
    *(char *)(param_1 + 0xfa) = *(char *)(param_1 + 0x11b);
    FUN_0090ca00(param_1,*(int *)(param_1 + 0xdc) + 1,param_2,uVar4);
    if ((((*(char *)(param_1 + 0x113) == '\0') || (5 < *(byte *)(param_1 + 0x114))) ||
        ((*(byte *)(param_1 + 0x60) & 2) == 0)) ||
       (FUN_0090ce0d(piVar1,*(int *)(param_1 + 0xdc) + 1,*(byte *)(param_1 + 0x114)), *piVar1 != 0))
    {
      if (*(int *)(param_1 + 0x60) != 0) {
        FUN_008a2f12(param_1);
      }
      FUN_0090d590(param_1,piVar1);
      if (*(code **)(param_1 + 0x170) != (code *)0x0) {
        (**(code **)(param_1 + 0x170))
                  (param_1,*(undefined4 *)(param_1 + 0xd4),*(undefined1 *)(param_1 + 0x114));
      }
    }
    else {
      FUN_0090d361(param_1);
    }
  }
  else {
    cVar2 = *(char *)(param_1 + 0x114);
    if (cVar2 == '\0') {
      bVar5 = (*(byte *)(param_1 + 0xd4) & 7) == 0;
LAB_008ee496:
      if (bVar5) goto LAB_008ee498;
    }
    else if (cVar2 == '\x01') {
      if ((*(byte *)(param_1 + 0xd4) & 7) == 0) {
        bVar5 = *(uint *)(param_1 + 0xb8) < 5;
LAB_008ee48b:
        if (!bVar5) goto LAB_008ee498;
      }
    }
    else {
      if (cVar2 == '\x02') {
        bVar5 = ((byte)*(undefined4 *)(param_1 + 0xd4) & 7) == 4;
        goto LAB_008ee496;
      }
      if (cVar2 == '\x03') {
        if ((*(byte *)(param_1 + 0xd4) & 3) == 0) {
          bVar5 = *(uint *)(param_1 + 0xb8) < 3;
          goto LAB_008ee48b;
        }
      }
      else {
        if (cVar2 == '\x04') {
          bVar5 = ((byte)*(undefined4 *)(param_1 + 0xd4) & 3) == 2;
          goto LAB_008ee496;
        }
        if (cVar2 == '\x05') {
          if ((*(byte *)(param_1 + 0xd4) & 1) == 0) {
            bVar5 = *(uint *)(param_1 + 0xb8) < 2;
            goto LAB_008ee48b;
          }
        }
        else if ((cVar2 != '\x06') || ((*(byte *)(param_1 + 0xd4) & 1) != 0)) goto LAB_008ee498;
      }
    }
    FUN_0090d361(param_1);
  }
  return;
}


// ==== FUN_008ee566 @ 0x008ee566 ====

void FUN_008ee566(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  if (*(uint *)(param_1 + 0xd4) < *(uint *)(param_1 + 0xc0)) {
    while( true ) {
      iVar1 = FUN_0090e08b(param_1 + 100,2);
      if (iVar1 != 0) {
        pcVar2 = *(char **)(param_1 + 0x7c);
        if (pcVar2 == (char *)0x0) {
          pcVar2 = s_zlib_error_00a24b60;
        }
        FUN_008ee0f5(param_1,pcVar2);
      }
      if (*(int *)(param_1 + 0x74) != 0) break;
      FUN_0090d31d(param_1,*(undefined4 *)(param_1 + 0x9c),*(undefined4 *)(param_1 + 0xa0));
      *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x9c);
      *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0xa0);
    }
    if (*(int *)(param_1 + 0xa0) != *(int *)(param_1 + 0x74)) {
      FUN_0090d31d(param_1,*(undefined4 *)(param_1 + 0x9c),
                   *(int *)(param_1 + 0xa0) - *(int *)(param_1 + 0x74));
      *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x9c);
      *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0xa0);
    }
    *(undefined4 *)(param_1 + 0x128) = 0;
    FUN_008eea31(param_1);
  }
  return;
}


// ==== FUN_008ee60f @ 0x008ee60f ====

void FUN_008ee60f(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 local_44 [16];
  
  FUN_0090e2ca(param_1 + 0x19);
  FUN_0090c9e2(param_1,param_1[0x27]);
  FUN_0090c9e2(param_1,param_1[0x37]);
  FUN_0090c9e2(param_1,param_1[0x36]);
  FUN_0090c9e2(param_1,param_1[0x38]);
  FUN_0090c9e2(param_1,param_1[0x39]);
  FUN_0090c9e2(param_1,param_1[0x3a]);
  FUN_0090c9e2(param_1,param_1[0x3b]);
  FUN_0090c9e2(param_1,param_1[0x61]);
  FUN_0090c9e2(param_1,param_1[0x62]);
  FUN_0090c9e2(param_1,param_1[99]);
  FUN_0090c9e2(param_1,param_1[100]);
  FUN_0090c9e2(param_1,param_1[0x65]);
  uVar1 = param_1[0x12];
  uVar2 = param_1[0x10];
  iVar7 = 0x67;
  puVar5 = param_1;
  puVar6 = local_44;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  uVar3 = param_1[0x11];
  puVar5 = param_1;
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  param_1[0x11] = uVar3;
  puVar5 = local_44;
  puVar6 = param_1;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  param_1[0x10] = uVar2;
  param_1[0x12] = uVar1;
  return;
}


// ==== FUN_008ee6f2 @ 0x008ee6f2 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008ee6f2(int param_1,int param_2,int param_3,int param_4,double *param_5)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  double *pdVar5;
  
  if (param_2 < 3) {
    if (param_2 == 0) {
      param_2 = 1;
    }
    if (((param_3 < 0) || (param_4 == 0)) || (param_2 == 1)) {
      param_3 = 0;
    }
    *(char *)(param_1 + 0x181) = (char)param_3;
    *(char *)(param_1 + 0x180) = (char)param_2;
    if (0 < param_3) {
      if (*(int *)(param_1 + 0x184) == 0) {
        uVar2 = FUN_0090c9a9(param_1,param_3);
        *(undefined4 *)(param_1 + 0x184) = uVar2;
        iVar3 = 0;
        if (0 < param_3) {
          do {
            *(undefined1 *)(iVar3 + *(int *)(param_1 + 0x184)) = 0xff;
            iVar3 = iVar3 + 1;
          } while (iVar3 < param_3);
        }
      }
      if (*(int *)(param_1 + 0x188) == 0) {
        uVar2 = FUN_0090c9a9(param_1,param_3 * 2);
        *(undefined4 *)(param_1 + 0x188) = uVar2;
        uVar2 = FUN_0090c9a9(param_1,param_3 * 2);
        *(undefined4 *)(param_1 + 0x18c) = uVar2;
        iVar3 = 0;
        if (0 < param_3) {
          do {
            *(undefined2 *)(*(int *)(param_1 + 0x188) + iVar3 * 2) = 0x100;
            *(undefined2 *)(*(int *)(param_1 + 0x18c) + iVar3 * 2) = 0x100;
            iVar3 = iVar3 + 1;
          } while (iVar3 < param_3);
        }
      }
      iVar3 = 0;
      if (0 < param_3) {
        do {
          if (_DAT_0099d098 <= *(double *)(param_4 + iVar3 * 8)) {
            uVar1 = __ftol();
            *(undefined2 *)(*(int *)(param_1 + 0x18c) + iVar3 * 2) = uVar1;
            uVar1 = __ftol();
            *(undefined2 *)(*(int *)(param_1 + 0x188) + iVar3 * 2) = uVar1;
          }
          else {
            *(undefined2 *)(*(int *)(param_1 + 0x188) + iVar3 * 2) = 0x100;
            *(undefined2 *)(*(int *)(param_1 + 0x18c) + iVar3 * 2) = 0x100;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_3);
      }
    }
    iVar3 = 0;
    if (*(int *)(param_1 + 400) == 0) {
      uVar2 = FUN_0090c9a9(param_1,10);
      *(undefined4 *)(param_1 + 400) = uVar2;
      uVar2 = FUN_0090c9a9(param_1,10);
      *(undefined4 *)(param_1 + 0x194) = uVar2;
      iVar4 = 0;
      do {
        *(undefined2 *)(iVar4 + *(int *)(param_1 + 400)) = 8;
        *(undefined2 *)(iVar4 + *(int *)(param_1 + 0x194)) = 8;
        iVar4 = iVar4 + 2;
      } while (iVar4 < 10);
    }
    pdVar5 = param_5;
    do {
      if ((param_5 == (double *)0x0) || (*pdVar5 < _DAT_0099d098)) {
        *(undefined2 *)(iVar3 + *(int *)(param_1 + 400)) = 8;
        *(undefined2 *)(iVar3 + *(int *)(param_1 + 0x194)) = 8;
      }
      else if (_DAT_0099d0a0 <= *pdVar5) {
        uVar1 = __ftol();
        *(undefined2 *)(iVar3 + *(int *)(param_1 + 0x194)) = uVar1;
        uVar1 = __ftol();
        *(undefined2 *)(iVar3 + *(int *)(param_1 + 400)) = uVar1;
      }
      pdVar5 = pdVar5 + 1;
      iVar3 = iVar3 + 2;
    } while (iVar3 < 10);
  }
  else {
    FUN_008ee116(param_1,s_p_Unknown_filter_heuristic_metho_00a24b7e + 2);
  }
  return;
}


// ==== FUN_008ee903 @ 0x008ee903 ====

int FUN_008ee903(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_0090c949(1);
  if (iVar1 != 0) {
    iVar2 = __setjmp3(iVar1,0);
    if (iVar2 == 0) {
      FUN_008ee0d7(iVar1,param_2,param_3,param_4);
      if ((param_1 == (char *)0x0) || (*param_1 != '1')) {
        FUN_008ee0f5(iVar1,s_Incompatible_libpng_version_in_a_00a24ba0);
      }
      *(undefined4 *)(iVar1 + 0xa0) = 0x2000;
      uVar3 = FUN_0090c9a9(iVar1,0x2000);
      *(undefined4 *)(iVar1 + 0x9c) = uVar3;
      FUN_008eea4b(iVar1,0,0,0);
      FUN_008ee6f2(iVar1,0,1,0,0);
      return iVar1;
    }
    FUN_0090c9e2(iVar1,*(undefined4 *)(iVar1 + 0x9c));
    FUN_0090c991(iVar1);
  }
  return 0;
}


// ==== FUN_008ee99b @ 0x008ee99b ====

void FUN_008ee99b(undefined4 param_1,undefined4 *param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    FUN_008ee380(param_1,*param_2);
    param_2 = param_2 + 1;
  }
  return;
}


// ==== FUN_008ee9c2 @ 0x008ee9c2 ====

void FUN_008ee9c2(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if ((param_2 != (int *)0x0) && (*param_2 != 0)) {
    FUN_0090c991(*param_2);
    *param_2 = 0;
  }
  if (iVar1 != 0) {
    FUN_008ee60f(iVar1);
    FUN_0090c991(iVar1);
    *param_1 = 0;
  }
  return;
}


// ==== FUN_008eea05 @ 0x008eea05 ====

void FUN_008eea05(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(code **)(param_1 + 0x4c) == (code *)0x0) {
    FUN_008ee0f5(param_1,s_Call_to_NULL_write_function_00a24bd8);
  }
  else {
    (**(code **)(param_1 + 0x4c))(param_1,param_2,param_3);
  }
  return;
}


// ==== FUN_008eea31 @ 0x008eea31 ====

void FUN_008eea31(int param_1)

{
  if (*(code **)(param_1 + 0x120) != (code *)0x0) {
    (**(code **)(param_1 + 0x120))(param_1);
  }
  return;
}


// ==== FUN_008eea4b @ 0x008eea4b ====

void FUN_008eea4b(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x54) = param_2;
  *(undefined4 *)(param_1 + 0x4c) = param_3;
  *(undefined4 *)(param_1 + 0x120) = param_4;
  if (*(int *)(param_1 + 0x50) != 0) {
    *(undefined4 *)(param_1 + 0x50) = 0;
    FUN_008ee116(param_1,s_Attempted_to_set_both_read_data__00a24c2c);
    FUN_008ee116(param_1,s_the_same_structure__Resetting_re_00a24bf4);
  }
  return;
}


// ==== FUN_008eea8e @ 0x008eea8e ====

void FUN_008eea8e(int param_1,int param_2,double param_3)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 1;
    *(float *)(param_2 + 0x28) = (float)param_3;
  }
  return;
}


// ==== FUN_008eeaae @ 0x008eeaae ====

void FUN_008eeaae(int param_1,uint *param_2,uint param_3,uint param_4,char param_5,byte param_6,
                 undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  byte bVar1;
  
  if ((param_1 != 0) && (param_2 != (uint *)0x0)) {
    *(undefined1 *)((int)param_2 + 0x1a) = param_8;
    param_2[1] = param_4;
    *(undefined1 *)((int)param_2 + 0x1b) = param_9;
    *param_2 = param_3;
    *(char *)(param_2 + 6) = param_5;
    *(byte *)((int)param_2 + 0x19) = param_6;
    *(undefined1 *)(param_2 + 7) = param_7;
    if ((param_6 == 3) || ((param_6 & 2) == 0)) {
      *(undefined1 *)((int)param_2 + 0x1d) = 1;
    }
    else {
      *(undefined1 *)((int)param_2 + 0x1d) = 3;
    }
    if ((param_6 & 4) != 0) {
      *(char *)((int)param_2 + 0x1d) = *(char *)((int)param_2 + 0x1d) + '\x01';
    }
    bVar1 = *(char *)((int)param_2 + 0x1d) * param_5;
    *(byte *)((int)param_2 + 0x1e) = bVar1;
    if ((uint)(0x7fffffff / (ulonglong)(uint)((int)(bVar1 + 7) >> 3)) < param_3) {
      FUN_008ee116(param_1,s_Width_too_large_to_process_image_00a24c64);
      param_2[3] = 0;
    }
    else {
      param_2[3] = bVar1 * param_3 + 7 >> 3;
    }
  }
  return;
}


// ==== FUN_008eeb51 @ 0x008eeb51 ====

void FUN_008eeb51(int param_1,int param_2,undefined4 param_3,undefined2 param_4)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 8;
    *(undefined4 *)(param_2 + 0x10) = param_3;
    *(undefined2 *)(param_2 + 0x14) = param_4;
  }
  return;
}


// ==== FUN_008eeb79 @ 0x008eeb79 ====

void FUN_008eeb79(int param_1,int param_2,undefined1 param_3)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) | 8;
    *(undefined1 *)(param_2 + 0x2c) = param_3;
  }
  return;
}


// ==== FUN_008eeb99 @ 0x008eeb99 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008eeb99(int param_1,int param_2,undefined4 param_3)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    FUN_008eeb79(param_1,param_2,param_3);
    FUN_008eea8e(param_1,param_2,_DAT_00a24ca8);
  }
  return;
}


// ==== FUN_008eebd2 @ 0x008eebd2 ====

void FUN_008eebd2(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    if (param_3 != 0) {
      *(int *)(param_2 + 0x30) = param_3;
    }
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(param_2 + 0x34) = *param_5;
      *(undefined4 *)(param_2 + 0x38) = param_5[1];
      *(undefined2 *)(param_2 + 0x3c) = *(undefined2 *)(param_5 + 2);
      if (param_4 == 0) {
        param_4 = 1;
      }
    }
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x10;
    *(undefined2 *)(param_2 + 0x16) = (undefined2)param_4;
  }
  return;
}


// ==== FUN_008eec1d @ 0x008eec1d ====

int FUN_008eec1d(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  iVar1 = FUN_0090c949(1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = __setjmp3(iVar1,0);
  if (iVar2 != 0) {
    FUN_0090c9e2(iVar1,*(undefined4 *)(iVar1 + 0x9c));
    FUN_0090c991(iVar1);
    return 0;
  }
  FUN_008ee0d7(iVar1,param_2,param_3,param_4);
  if ((param_1 == (char *)0x0) || (*param_1 != '1')) {
    FUN_008ee0f5(iVar1,s_Incompatible_libpng_version_in_a_00a24ba0);
  }
  *(undefined4 *)(iVar1 + 0xa0) = 0x2000;
  uVar3 = FUN_0090c9a9(iVar1,0x2000);
  *(undefined4 *)(iVar1 + 0x9c) = uVar3;
  *(code **)(iVar1 + 0x84) = FUN_008ee1e3;
  *(code **)(iVar1 + 0x88) = FUN_008ee239;
  *(int *)(iVar1 + 0x8c) = iVar1;
  iVar2 = FUN_0090f198(iVar1 + 100,s_1_1_4_00a24d68,0x38);
  if (iVar2 == -6) {
    pcVar4 = s_zlib_version_error_00a24d2c;
  }
  else if ((iVar2 == -4) || (iVar2 == -2)) {
    pcVar4 = s_zlib_memory_error_00a24d40;
  }
  else {
    if (iVar2 == 0) goto LAB_008eecf0;
    pcVar4 = s_Unknown_zlib_error_00a24d54;
  }
  FUN_008ee0f5(iVar1,pcVar4);
LAB_008eecf0:
  *(undefined4 *)(iVar1 + 0x70) = *(undefined4 *)(iVar1 + 0x9c);
  *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(iVar1 + 0xa0);
  FUN_008f0de5(iVar1,0,0);
  return iVar1;
}


// ==== FUN_008eed13 @ 0x008eed13 ====

void FUN_008eed13(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  
  iVar2 = param_1;
  if (*(byte *)(param_1 + 0x11c) < 8) {
    uVar4 = (uint)*(byte *)(param_1 + 0x11c);
    iVar5 = -uVar4 + 8;
    FUN_008f0db9(param_1,uVar4 + 0x20 + param_2,iVar5);
    *(undefined1 *)(iVar2 + 0x11c) = 8;
    iVar5 = FUN_008ee195(param_2 + 0x20,uVar4,iVar5);
    if (iVar5 != 0) {
      if (uVar4 < 4) {
        iVar5 = FUN_008ee195(param_2 + 0x20,uVar4,-uVar4 + 4);
        if (iVar5 == 0) goto LAB_008eed79;
        pcVar6 = s_Not_a_PNG_file_00a24dd0;
      }
      else {
LAB_008eed79:
        pcVar6 = s_PNG_file_corrupted_by_ASCII_conv_00a24da8;
      }
      FUN_008ee0f5(iVar2,pcVar6);
    }
  }
  piVar1 = (int *)(iVar2 + 0x10c);
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          FUN_008f0db9(iVar2,&param_1,4);
          uVar3 = FUN_0090f524(&param_1);
          FUN_008ee244(iVar2);
          FUN_0090f568(iVar2,piVar1,4);
          if (*piVar1 != DAT_00a24cf4) break;
          FUN_0090fed5(iVar2,param_2,uVar3);
        }
        if (*piVar1 != DAT_00a24d0c) break;
        FUN_009100cd(iVar2,param_2,uVar3);
      }
      if (*piVar1 != DAT_00a24d04) break;
      FUN_009101e8(iVar2,param_2,uVar3);
    }
    if (*piVar1 == DAT_00a24cfc) break;
    if (*piVar1 == DAT_00a24d14) {
      FUN_00910230(iVar2,param_2,uVar3);
    }
    else if (*piVar1 == DAT_00a24d1c) {
      FUN_00910333(iVar2,param_2,uVar3);
    }
    else if (*piVar1 == DAT_00a24d24) {
      FUN_00910417(iVar2,param_2,uVar3);
    }
    else {
      FUN_009105bc(iVar2,param_2,uVar3);
    }
  }
  if ((*(uint *)(iVar2 + 0x58) & 1) == 0) {
    pcVar6 = s_Missing_IHDR_before_IDAT_00a24d8c;
  }
  else {
    if ((*(char *)(iVar2 + 0x116) != '\x03') || ((*(uint *)(iVar2 + 0x58) & 2) != 0))
    goto LAB_008eee72;
    pcVar6 = s_Missing_PLTE_before_IDAT_00a24d70;
  }
  FUN_008ee0f5(iVar2,pcVar6);
LAB_008eee72:
  *(uint *)(iVar2 + 0x58) = *(uint *)(iVar2 + 0x58) | 4;
  *(undefined4 *)(iVar2 + 0xfc) = uVar3;
  return;
}


// ==== FUN_008eee83 @ 0x008eee83 ====

void FUN_008eee83(int param_1,undefined4 param_2)

{
  if ((*(byte *)(param_1 + 0x5c) & 0x40) == 0) {
    FUN_0090fcad(param_1);
  }
  FUN_008ef83b(param_1,param_2);
  return;
}


// ==== FUN_008eeea6 @ 0x008eeea6 ====

void FUN_008eeea6(int param_1,int param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  bool bVar7;
  
  iVar3 = param_1;
  if ((*(byte *)(param_1 + 0x5c) & 0x40) == 0) {
    FUN_0090fcad(param_1);
  }
  if ((*(char *)(iVar3 + 0x113) != '\0') && ((*(byte *)(iVar3 + 0x60) & 2) != 0)) {
    cVar2 = *(char *)(iVar3 + 0x114);
    if (cVar2 == '\0') {
      if ((*(byte *)(iVar3 + 0xd4) & 7) != 0) {
        bVar7 = param_3 == 0;
LAB_008eefb8:
        if (bVar7) goto LAB_008eef0f;
        uVar4 = 0xff;
LAB_008eefc3:
        FUN_0090f645(iVar3,param_3,uVar4);
LAB_008eef0f:
        FUN_00910605(iVar3);
        return;
      }
    }
    else if (cVar2 == '\x01') {
      if (((*(byte *)(iVar3 + 0xd4) & 7) != 0) || (*(uint *)(iVar3 + 0xb8) < 5)) {
        if (param_3 == 0) goto LAB_008eef0f;
        uVar4 = 0xf;
        goto LAB_008eefc3;
      }
    }
    else if (cVar2 == '\x02') {
      if (((byte)*(uint *)(iVar3 + 0xd4) & 7) != 4) {
        if (param_3 == 0) goto LAB_008eef0f;
        bVar7 = (*(uint *)(iVar3 + 0xd4) & 4) == 0;
        goto LAB_008eefb8;
      }
    }
    else if (cVar2 == '\x03') {
      if (((*(byte *)(iVar3 + 0xd4) & 3) != 0) || (*(uint *)(iVar3 + 0xb8) < 3)) {
        if (param_3 == 0) goto LAB_008eef0f;
        uVar4 = 0x33;
        goto LAB_008eefc3;
      }
    }
    else if (cVar2 == '\x04') {
      if (((byte)*(uint *)(iVar3 + 0xd4) & 3) != 2) {
        if (param_3 == 0) goto LAB_008eef0f;
        bVar7 = (*(uint *)(iVar3 + 0xd4) & 2) == 0;
        goto LAB_008eefb8;
      }
    }
    else if (cVar2 == '\x05') {
      if (((*(byte *)(iVar3 + 0xd4) & 1) != 0) || (*(uint *)(iVar3 + 0xb8) < 2)) {
        if (param_3 == 0) goto LAB_008eef0f;
        uVar4 = 0x55;
        goto LAB_008eefc3;
      }
    }
    else if ((cVar2 == '\x06') && ((*(byte *)(iVar3 + 0xd4) & 1) == 0)) goto LAB_008eef0f;
  }
  if ((*(byte *)(iVar3 + 0x58) & 4) == 0) {
    FUN_008ee0f5(iVar3,s_Invalid_attempt_to_read_row_data_00a24e24);
  }
  *(undefined4 *)(iVar3 + 0x70) = *(undefined4 *)(iVar3 + 0xdc);
  *(undefined4 *)(iVar3 + 0x74) = *(undefined4 *)(iVar3 + 0xcc);
  do {
    if (*(int *)(iVar3 + 0x68) == 0) {
      if (*(int *)(iVar3 + 0xfc) == 0) {
        do {
          FUN_0090fe4c(iVar3,0);
          FUN_008f0db9(iVar3,&param_1,4);
          uVar4 = FUN_0090f524(&param_1);
          *(undefined4 *)(iVar3 + 0xfc) = uVar4;
          FUN_008ee244(iVar3);
          FUN_0090f568(iVar3,(int *)(iVar3 + 0x10c),4);
          if (*(int *)(iVar3 + 0x10c) != DAT_00a24cfc) {
            FUN_008ee0f5(iVar3,s_Not_enough_image_data_00a24e0c);
          }
        } while (*(int *)(iVar3 + 0xfc) == 0);
      }
      *(uint *)(iVar3 + 0x68) = *(uint *)(iVar3 + 0xa0);
      *(undefined4 *)(iVar3 + 100) = *(undefined4 *)(iVar3 + 0x9c);
      if (*(uint *)(iVar3 + 0xfc) < *(uint *)(iVar3 + 0xa0)) {
        *(uint *)(iVar3 + 0x68) = *(uint *)(iVar3 + 0xfc);
      }
      FUN_0090f568(iVar3,*(undefined4 *)(iVar3 + 0x9c),*(undefined4 *)(iVar3 + 0x68));
      *(int *)(iVar3 + 0xfc) = *(int *)(iVar3 + 0xfc) - *(int *)(iVar3 + 0x68);
    }
    iVar5 = FUN_0090f1b1((undefined4 *)(iVar3 + 100),1);
    if (iVar5 == 1) {
      if (((*(int *)(iVar3 + 0x74) != 0) || (*(int *)(iVar3 + 0x68) != 0)) ||
         (*(int *)(iVar3 + 0xfc) != 0)) {
        FUN_008ee0f5(iVar3,s_Extra_compressed_data_00a24de0);
      }
      *(uint *)(iVar3 + 0x58) = *(uint *)(iVar3 + 0x58) | 8;
      *(uint *)(iVar3 + 0x5c) = *(uint *)(iVar3 + 0x5c) | 0x20;
      break;
    }
    if (iVar5 != 0) {
      pcVar6 = *(char **)(iVar3 + 0x7c);
      if (pcVar6 == (char *)0x0) {
        pcVar6 = s_Decompression_error_00a24df8;
      }
      FUN_008ee0f5(iVar3,pcVar6);
    }
  } while (*(int *)(iVar3 + 0x74) != 0);
  *(undefined1 *)(iVar3 + 0xfa) = *(undefined1 *)(iVar3 + 0x11a);
  *(undefined1 *)(iVar3 + 0xf9) = *(undefined1 *)(iVar3 + 0x117);
  *(byte *)(iVar3 + 0xfb) = *(byte *)(iVar3 + 0x119);
  *(undefined1 *)(iVar3 + 0xf8) = *(undefined1 *)(iVar3 + 0x116);
  piVar1 = (int *)(iVar3 + 0xf0);
  *piVar1 = *(int *)(iVar3 + 0xd0);
  *(uint *)(iVar3 + 0xf4) = (uint)*(byte *)(iVar3 + 0x119) * *(int *)(iVar3 + 0xd0) + 7 >> 3;
  FUN_0090fb34(iVar3,piVar1,*(undefined1 **)(iVar3 + 0xdc) + 1,*(int *)(iVar3 + 0xd8) + 1,
               **(undefined1 **)(iVar3 + 0xdc));
  FUN_0090ca00(iVar3,*(undefined4 *)(iVar3 + 0xd8),*(undefined4 *)(iVar3 + 0xdc),
               *(int *)(iVar3 + 200) + 1);
  if (*(int *)(iVar3 + 0x60) != 0) {
    FUN_008f0c18(iVar3);
  }
  if ((*(char *)(iVar3 + 0x113) == '\0') || ((*(uint *)(iVar3 + 0x60) & 2) == 0)) {
    if (param_2 != 0) {
      FUN_0090f645(iVar3,param_2,0xff);
    }
    if (param_3 == 0) goto LAB_008ef200;
    uVar4 = 0xff;
    iVar5 = param_3;
  }
  else {
    if (*(byte *)(iVar3 + 0x114) < 6) {
      FUN_0090f85d(piVar1,*(int *)(iVar3 + 0xdc) + 1,*(byte *)(iVar3 + 0x114),
                   *(uint *)(iVar3 + 0x60));
    }
    if (param_3 != 0) {
      FUN_0090f645(iVar3,param_3,*(undefined4 *)(&DAT_00a24cd8 + (uint)*(byte *)(iVar3 + 0x114) * 4)
                  );
    }
    if (param_2 == 0) goto LAB_008ef200;
    uVar4 = *(undefined4 *)(&DAT_00a24cbc + (uint)*(byte *)(iVar3 + 0x114) * 4);
    iVar5 = param_2;
  }
  FUN_0090f645(iVar3,iVar5,uVar4);
LAB_008ef200:
  FUN_00910605(iVar3);
  if (*(code **)(iVar3 + 0x16c) != (code *)0x0) {
    (**(code **)(iVar3 + 0x16c))(iVar3,*(undefined4 *)(iVar3 + 0xd4),*(undefined1 *)(iVar3 + 0x114))
    ;
  }
  return;
}


// ==== FUN_008ef22b @ 0x008ef22b ====

void FUN_008ef22b(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_8;
  
  iVar2 = param_1;
  local_8 = FUN_008ef687(param_1);
  iVar1 = *(int *)(param_1 + 0xbc);
  *(int *)(param_1 + 0xc0) = iVar1;
  if (0 < local_8) {
    do {
      if (iVar1 != 0) {
        puVar3 = param_2;
        param_1 = iVar1;
        do {
          FUN_008eeea6(iVar2,*puVar3,0);
          puVar3 = puVar3 + 1;
          param_1 = param_1 + -1;
        } while (param_1 != 0);
      }
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return;
}


// ==== FUN_008ef278 @ 0x008ef278 ====

void FUN_008ef278(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_44 [16];
  
  iVar6 = 0;
  if (param_2 != 0) {
    FUN_008ee2a2(param_1,param_2);
  }
  if (param_3 != 0) {
    FUN_008ee2a2(param_1,param_3);
  }
  FUN_0090c9e2(param_1,param_1[0x27]);
  FUN_0090c9e2(param_1,param_1[0x37]);
  FUN_0090c9e2(param_1,param_1[0x36]);
  FUN_0090c9e2(param_1,param_1[0x5d]);
  FUN_0090c9e2(param_1,param_1[0x5e]);
  FUN_0090c9e2(param_1,param_1[0x4e]);
  if ((*(byte *)((int)param_1 + 0x5d) & 0x10) != 0) {
    FUN_008ee239(param_1,param_1[0x41]);
  }
  if ((*(byte *)((int)param_1 + 0x5d) & 0x20) != 0) {
    FUN_0090c9e2(param_1,param_1[0x57]);
  }
  if (param_1[0x51] != 0) {
    iVar4 = 1 << (8U - (char)param_1[0x4b] & 0x1f);
    if (0 < iVar4) {
      do {
        FUN_0090c9e2(param_1,*(undefined4 *)(param_1[0x51] + iVar6 * 4));
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar4);
    }
    FUN_0090c9e2(param_1,param_1[0x51]);
  }
  FUN_0090f076(param_1 + 0x19);
  uVar1 = param_1[0x12];
  uVar2 = param_1[0x10];
  iVar4 = 0x67;
  puVar5 = param_1;
  puVar7 = local_44;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  uVar3 = param_1[0x11];
  puVar5 = param_1;
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  param_1[0x11] = uVar3;
  puVar5 = local_44;
  puVar7 = param_1;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  param_1[0x10] = uVar2;
  param_1[0x12] = uVar1;
  return;
}


// ==== FUN_008ef38f @ 0x008ef38f ====

void FUN_008ef38f(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int local_c;
  int local_8;
  
  iVar1 = 0;
  local_8 = 0;
  local_c = 0;
  if (param_1 != (int *)0x0) {
    local_8 = *param_1;
  }
  if (param_2 != (int *)0x0) {
    iVar1 = *param_2;
  }
  if (param_3 != (int *)0x0) {
    local_c = *param_3;
  }
  if (local_8 != 0) {
    FUN_008ef278(local_8,iVar1,local_c);
  }
  if (iVar1 != 0) {
    FUN_0090c991(iVar1);
    *param_2 = 0;
  }
  if (local_c != 0) {
    FUN_0090c991(local_c);
    *param_3 = 0;
  }
  if (local_8 != 0) {
    FUN_0090c991(local_8);
    *param_1 = 0;
  }
  return;
}


// ==== FUN_008ef40e @ 0x008ef40e ====

uint FUN_008ef40e(int param_1,int param_2,uint param_3)

{
  if ((param_1 == 0) || (param_2 == 0)) {
    param_3 = 0;
  }
  else {
    param_3 = *(uint *)(param_2 + 8) & param_3;
  }
  return param_3;
}


// ==== FUN_008ef42e @ 0x008ef42e ====

undefined4 FUN_008ef42e(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 0xc);
  }
  return uVar1;
}


// ==== FUN_008ef44b @ 0x008ef44b ====

undefined1 FUN_008ef44b(int param_1,int param_2)

{
  undefined1 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined1 *)(param_2 + 0x1d);
  }
  return uVar1;
}


// ==== FUN_008ef468 @ 0x008ef468 ====

undefined4 FUN_008ef468(int param_1,int param_2,double *param_3)

{
  undefined4 uVar1;
  
  if ((((param_1 == 0) || (param_2 == 0)) || ((*(byte *)(param_2 + 8) & 1) == 0)) ||
     (param_3 == (double *)0x0)) {
    uVar1 = 0;
  }
  else {
    *param_3 = (double)*(float *)(param_2 + 0x28);
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_008ef497 @ 0x008ef497 ====

undefined4 FUN_008ef497(int param_1,int param_2,uint *param_3)

{
  undefined4 uVar1;
  
  if ((((param_1 == 0) || (param_2 == 0)) || (uVar1 = 0x800, (*(uint *)(param_2 + 8) & 0x800) == 0))
     || (param_3 == (uint *)0x0)) {
    uVar1 = 0;
  }
  else {
    *param_3 = (uint)*(byte *)(param_2 + 0x2c);
  }
  return uVar1;
}


// ==== FUN_008ef4c8 @ 0x008ef4c8 ====

undefined4
FUN_008ef4c8(int param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5,uint *param_6,
            uint *param_7,uint *param_8,uint *param_9)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((((param_1 == 0) || (param_2 == (uint *)0x0)) || (param_3 == (uint *)0x0)) ||
     (((param_4 == (uint *)0x0 || (param_5 == (uint *)0x0)) || (param_6 == (uint *)0x0)))) {
    uVar3 = 0;
  }
  else {
    *param_3 = *param_2;
    *param_4 = param_2[1];
    *param_5 = (uint)(byte)param_2[6];
    *param_6 = (uint)*(byte *)((int)param_2 + 0x19);
    if (param_8 != (uint *)0x0) {
      *param_8 = (uint)*(byte *)((int)param_2 + 0x1a);
    }
    if (param_9 != (uint *)0x0) {
      *param_9 = (uint)*(byte *)((int)param_2 + 0x1b);
    }
    if (param_7 != (uint *)0x0) {
      *param_7 = (uint)(byte)param_2[7];
    }
    uVar1 = *param_6;
    if (uVar1 == 3) {
      uVar2 = 1;
    }
    else {
      uVar2 = (int)(char)uVar1 & 2U | 1;
    }
    if ((uVar1 & 4) != 0) {
      uVar2 = uVar2 + 1;
    }
    if ((uint)(0x7fffffff / (ulonglong)(uint)((int)(*param_5 * uVar2 + 7) >> 3)) < *param_3) {
      FUN_008ee116(param_1,s_Width_too_large_for_libpng_to_pr_00a24e48);
    }
    uVar3 = 1;
  }
  return uVar3;
}


// ==== FUN_008ef59b @ 0x008ef59b ====

undefined4 FUN_008ef59b(int param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  undefined4 uVar1;
  
  if ((((param_1 == 0) || (param_2 == 0)) || ((*(byte *)(param_2 + 8) & 8) == 0)) ||
     (param_3 == (undefined4 *)0x0)) {
    uVar1 = 0;
  }
  else {
    *param_3 = *(undefined4 *)(param_2 + 0x10);
    *param_4 = (uint)*(ushort *)(param_2 + 0x14);
    uVar1 = 8;
  }
  return uVar1;
}


// ==== FUN_008ef5d3 @ 0x008ef5d3 ====

undefined4 FUN_008ef5d3(int param_1,int param_2,undefined4 *param_3,uint *param_4,int *param_5)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((param_1 != 0) && (param_2 != 0)) && ((*(byte *)(param_2 + 8) & 0x10) != 0)) {
    if (*(char *)(param_2 + 0x19) == '\x03') {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(param_2 + 0x30);
        uVar1 = 0x10;
      }
      if (param_5 != (int *)0x0) {
        *param_5 = param_2 + 0x34;
      }
    }
    else {
      if (param_5 != (int *)0x0) {
        *param_5 = param_2 + 0x34;
        uVar1 = 0x10;
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = 0;
      }
    }
    if (param_4 != (uint *)0x0) {
      *param_4 = (uint)*(ushort *)(param_2 + 0x16);
      uVar1 = 0x10;
    }
  }
  return uVar1;
}


// ==== FUN_008ef63e @ 0x008ef63e ====

void FUN_008ef63e(int param_1)

{
  *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | 1;
  return;
}


// ==== FUN_008ef64e @ 0x008ef64e ====

void FUN_008ef64e(int param_1)

{
  if (*(char *)(param_1 + 0x117) == '\x10') {
    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | 0x10;
  }
  return;
}


// ==== FUN_008ef667 @ 0x008ef667 ====

void FUN_008ef667(int param_1)

{
  if (*(byte *)(param_1 + 0x117) < 8) {
    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | 4;
    *(undefined1 *)(param_1 + 0x118) = 8;
  }
  return;
}


// ==== FUN_008ef687 @ 0x008ef687 ====

undefined4 FUN_008ef687(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x113) == '\0') {
    uVar1 = 1;
  }
  else {
    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | 2;
    uVar1 = 7;
  }
  return uVar1;
}


// ==== FUN_008ef6a8 @ 0x008ef6a8 ====

void FUN_008ef6a8(int param_1,byte param_2,int param_3)

{
  *(byte *)(param_1 + 0x61) = *(byte *)(param_1 + 0x61) | 0x80;
  *(ushort *)(param_1 + 0x11e) = (ushort)param_2;
  if (param_3 == 1) {
    *(byte *)(param_1 + 0x5c) = *(byte *)(param_1 + 0x5c) | 0x80;
  }
  else {
    *(byte *)(param_1 + 0x5c) = *(byte *)(param_1 + 0x5c) & 0x7f;
  }
  if (*(char *)(param_1 + 0x116) == '\x02') {
    *(undefined1 *)(param_1 + 0x11b) = 4;
  }
  if ((*(char *)(param_1 + 0x116) == '\0') && (7 < *(byte *)(param_1 + 0x117))) {
    *(undefined1 *)(param_1 + 0x11b) = 2;
  }
  return;
}


// ==== FUN_008ef6fa @ 0x008ef6fa ====

void FUN_008ef6fa(int *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  if ((*(char *)((int)param_1 + 9) == '\x10') &&
     (iVar2 = (uint)*(byte *)((int)param_1 + 10) * *param_1, iVar2 != 0)) {
    do {
      uVar1 = *param_2;
      *param_2 = param_2[1];
      param_2[1] = uVar1;
      param_2 = param_2 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


// ==== FUN_008ef72d @ 0x008ef72d ====

void FUN_008ef72d(int *param_1,undefined1 *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 2);
  if ((bVar1 & 2) != 0) {
    iVar3 = *param_1;
    if (*(char *)((int)param_1 + 9) == '\b') {
      if (bVar1 == 2) {
        if (iVar3 != 0) {
          do {
            uVar2 = *param_2;
            *param_2 = param_2[2];
            param_2[2] = uVar2;
            param_2 = param_2 + 3;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
      else if ((bVar1 == 6) && (iVar3 != 0)) {
        do {
          uVar2 = *param_2;
          *param_2 = param_2[2];
          param_2[2] = uVar2;
          param_2 = param_2 + 4;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    else if (*(char *)((int)param_1 + 9) == '\x10') {
      if (bVar1 == 2) {
        if (iVar3 != 0) {
          param_2 = param_2 + 1;
          do {
            uVar2 = param_2[-1];
            param_2[-1] = param_2[3];
            param_2[3] = uVar2;
            uVar2 = *param_2;
            *param_2 = param_2[4];
            param_2[4] = uVar2;
            param_2 = param_2 + 6;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
      else if ((bVar1 == 6) && (iVar3 != 0)) {
        param_2 = param_2 + 1;
        do {
          uVar2 = param_2[-1];
          param_2[-1] = param_2[3];
          param_2[3] = uVar2;
          uVar2 = *param_2;
          *param_2 = param_2[4];
          param_2[4] = uVar2;
          param_2 = param_2 + 8;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
  }
  return;
}


// ==== FUN_008ef7f0 @ 0x008ef7f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008ef7f0(int param_1,double param_2,double param_3)

{
  if (_DAT_00a24e80 < ABS(param_2 * param_3 - _DAT_0099d0a0)) {
    *(byte *)(param_1 + 0x61) = *(byte *)(param_1 + 0x61) | 0x20;
  }
  *(float *)(param_1 + 0x130) = (float)param_3;
  *(float *)(param_1 + 0x134) = (float)param_2;
  return;
}


// ==== FUN_008ef82b @ 0x008ef82b ====

void FUN_008ef82b(int param_1)

{
  *(byte *)(param_1 + 0x61) = *(byte *)(param_1 + 0x61) | 0x10;
  return;
}


// ==== FUN_008ef83b @ 0x008ef83b ====

void FUN_008ef83b(int param_1,int *param_2)

{
  byte bVar1;
  
  if ((*(byte *)(param_1 + 0x61) & 0x10) == 0) goto LAB_008ef888;
  if (*(byte *)((int)param_2 + 0x19) == 3) {
    *(char *)((int)param_2 + 0x19) = (*(short *)(param_1 + 0x10a) != 0) * '\x04' + '\x02';
LAB_008ef880:
    *(undefined1 *)(param_2 + 6) = 8;
  }
  else {
    if (*(short *)(param_1 + 0x10a) != 0) {
      *(byte *)((int)param_2 + 0x19) = *(byte *)((int)param_2 + 0x19) | 4;
    }
    if (*(byte *)(param_2 + 6) < 8) goto LAB_008ef880;
  }
  *(undefined2 *)((int)param_2 + 0x16) = 0;
LAB_008ef888:
  if ((*(byte *)(param_1 + 0x61) & 0x20) != 0) {
    param_2[10] = *(int *)(param_1 + 0x130);
  }
  if (((*(byte *)(param_1 + 0x61) & 4) != 0) && ((char)param_2[6] == '\x10')) {
    *(undefined1 *)(param_2 + 6) = 8;
  }
  if (((*(byte *)(param_1 + 0x60) & 0x40) != 0) &&
     ((((*(char *)((int)param_2 + 0x19) == '\x02' || (*(char *)((int)param_2 + 0x19) == '\x06')) &&
       (*(int *)(param_1 + 0x174) != 0)) && ((char)param_2[6] == '\b')))) {
    *(undefined1 *)((int)param_2 + 0x19) = 3;
  }
  if (((*(byte *)(param_1 + 0x60) & 4) != 0) && (*(byte *)(param_2 + 6) < 8)) {
    *(undefined1 *)(param_2 + 6) = 8;
  }
  bVar1 = *(byte *)((int)param_2 + 0x19);
  if ((bVar1 == 3) || ((bVar1 & 2) == 0)) {
    *(undefined1 *)((int)param_2 + 0x1d) = 1;
  }
  else {
    *(undefined1 *)((int)param_2 + 0x1d) = 3;
  }
  if ((bVar1 & 4) != 0) {
    *(char *)((int)param_2 + 0x1d) = *(char *)((int)param_2 + 0x1d) + '\x01';
  }
  if (((*(byte *)(param_1 + 0x61) & 0x80) != 0) && ((bVar1 == 2 || (bVar1 == 0)))) {
    *(char *)((int)param_2 + 0x1d) = *(char *)((int)param_2 + 0x1d) + '\x01';
  }
  bVar1 = (char)param_2[6] * *(char *)((int)param_2 + 0x1d);
  *(byte *)((int)param_2 + 0x1e) = bVar1;
  param_2[3] = (uint)bVar1 * *param_2 + 7 >> 3;
  return;
}


// ==== FUN_008ef924 @ 0x008ef924 ====

void FUN_008ef924(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  bVar1 = *(byte *)((int)param_1 + 9);
  if (bVar1 < 8) {
    iVar2 = *param_1;
    if (bVar1 == 1) {
      pbVar4 = (byte *)((iVar2 - 1U >> 3) + param_2);
      pbVar5 = (byte *)(iVar2 + -1 + param_2);
      iVar3 = 7 - (iVar2 - 1U & 7);
      if (iVar2 != 0) {
        param_2 = iVar2;
        do {
          *pbVar5 = *pbVar4 >> ((byte)iVar3 & 0x1f) & 1;
          if (iVar3 == 7) {
            iVar3 = 0;
            pbVar4 = pbVar4 + -1;
          }
          else {
            iVar3 = iVar3 + 1;
          }
          pbVar5 = pbVar5 + -1;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
    }
    else if (bVar1 == 2) {
      pbVar4 = (byte *)((iVar2 - 1U >> 2) + param_2);
      pbVar5 = (byte *)(iVar2 + -1 + param_2);
      iVar3 = (3 - (iVar2 - 1U & 3)) * 2;
      if (iVar2 != 0) {
        param_2 = iVar2;
        do {
          *pbVar5 = *pbVar4 >> ((byte)iVar3 & 0x1f) & 3;
          if (iVar3 == 6) {
            iVar3 = 0;
            pbVar4 = pbVar4 + -1;
          }
          else {
            iVar3 = iVar3 + 2;
          }
          pbVar5 = pbVar5 + -1;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
    }
    else if (bVar1 == 4) {
      pbVar4 = (byte *)((iVar2 - 1U >> 1) + param_2);
      pbVar5 = (byte *)(iVar2 + -1 + param_2);
      iVar3 = (1 - (iVar2 - 1U & 1)) * 4;
      if (iVar2 != 0) {
        param_2 = iVar2;
        do {
          *pbVar5 = *pbVar4 >> ((byte)iVar3 & 0x1f) & 0xf;
          if (iVar3 == 4) {
            iVar3 = 0;
            pbVar4 = pbVar4 + -1;
          }
          else {
            iVar3 = 4;
          }
          pbVar5 = pbVar5 + -1;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
    }
    *(undefined1 *)((int)param_1 + 9) = 8;
    *(byte *)((int)param_1 + 0xb) = *(byte *)((int)param_1 + 10) << 3;
    param_1[1] = (uint)*(byte *)((int)param_1 + 10) * iVar2;
  }
  return;
}


// ==== FUN_008efa37 @ 0x008efa37 ====

int * FUN_008efa37(int *param_1,byte *param_2,byte *param_3)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  byte bVar4;
  ushort uVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int local_18 [4];
  int local_8;
  
  pbVar9 = param_2;
  if (*(byte *)(param_1 + 2) != 3) {
    bVar3 = false;
    iVar12 = *param_1;
    local_8 = iVar12;
    if ((*(byte *)(param_1 + 2) & 2) == 0) {
      local_18[0] = (uint)*(byte *)((int)param_1 + 9) - (uint)param_3[3];
      uVar7 = 1;
    }
    else {
      uVar7 = (uint)*(byte *)((int)param_1 + 9);
      local_18[0] = uVar7 - *param_3;
      local_18[1] = uVar7 - param_3[1];
      local_18[2] = uVar7 - param_3[2];
      uVar7 = 3;
    }
    iVar8 = local_18[0];
    if ((*(byte *)(param_1 + 2) & 4) != 0) {
      local_18[uVar7] = (uint)*(byte *)((int)param_1 + 9) - (uint)param_3[4];
      uVar7 = uVar7 + 1;
      iVar8 = local_18[0];
    }
    iVar10 = 0;
    if (uVar7 != 0) {
      do {
        if (local_18[iVar10] < 1) {
          local_18[iVar10] = 0;
          iVar8 = local_18[0];
        }
        else {
          bVar3 = true;
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)uVar7);
      uVar11 = 0;
      if (bVar3) {
        cVar2 = *(char *)((int)param_1 + 9);
        if (cVar2 == '\x02') {
          for (iVar12 = param_1[1]; param_1 = (int *)0x0, iVar12 != 0; iVar12 = iVar12 + -1) {
            *param_2 = *param_2 >> 1 & 0x55;
            param_2 = param_2 + 1;
          }
        }
        else if (cVar2 == '\x04') {
          piVar1 = param_1 + 1;
          bVar6 = (byte)iVar8;
          uVar7 = 0xf0 >> (bVar6 & 0x1f) & 0xfffffff0;
          bVar4 = (byte)uVar7 | (byte)(0xf >> (bVar6 & 0x1f));
          param_1 = (int *)CONCAT31((int3)(uVar7 >> 8),bVar4);
          for (iVar12 = *piVar1; iVar12 != 0; iVar12 = iVar12 + -1) {
            *param_2 = *param_2 >> (bVar6 & 0x1f) & bVar4;
            param_2 = param_2 + 1;
          }
        }
        else if (cVar2 == '\b') {
          if (iVar12 * uVar7 != 0) {
            do {
              param_1 = (int *)(uVar11 / uVar7);
              *param_2 = *param_2 >> (*(byte *)(local_18 + uVar11 % uVar7) & 0x1f);
              param_2 = param_2 + 1;
              uVar11 = uVar11 + 1;
            } while (uVar11 < iVar12 * uVar7);
          }
        }
        else if (cVar2 == '\x10') {
          param_2 = (byte *)0x0;
          if ((int *)(iVar12 * uVar7) != (int *)0x0) {
            do {
              uVar5 = CONCAT11(*pbVar9,pbVar9[1]) >> ((byte)local_18[(uint)param_2 % uVar7] & 0x1f);
              *pbVar9 = (byte)(uVar5 >> 8);
              pbVar9[1] = (byte)uVar5;
              pbVar9 = pbVar9 + 2;
              param_1 = (int *)((int)param_2 + 1);
              param_2 = (byte *)param_1;
            } while (param_1 < (int *)(iVar12 * uVar7));
          }
        }
      }
    }
  }
  return param_1;
}


// ==== FUN_008efbb5 @ 0x008efbb5 ====

void FUN_008efbb5(int *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if (*(char *)((int)param_1 + 9) == '\x10') {
    iVar2 = (uint)*(byte *)((int)param_1 + 10) * *param_1;
    if (iVar2 != 0) {
      puVar3 = param_2;
      do {
        uVar1 = *param_2;
        param_2 = param_2 + 2;
        *puVar3 = uVar1;
        puVar3 = puVar3 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    *(undefined1 *)((int)param_1 + 9) = 8;
    *(byte *)((int)param_1 + 0xb) = *(byte *)((int)param_1 + 10) << 3;
    param_1[1] = (uint)*(byte *)((int)param_1 + 10) * *param_1;
  }
  return;
}


// ==== FUN_008efbff @ 0x008efbff ====

void FUN_008efbff(uint *param_1,undefined1 *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  byte bVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  
  uVar1 = *param_1;
  bVar4 = (byte)(param_3 >> 8);
  uVar3 = (undefined1)param_3;
  if ((char)param_1[2] == '\0') {
    if (*(char *)((int)param_1 + 9) == '\b') {
      puVar2 = (undefined1 *)((int)param_2 + uVar1);
      puVar6 = puVar2 + uVar1;
      if ((param_4 & 0x80) == 0) {
        if (uVar1 != 0) {
          param_2 = (undefined1 *)uVar1;
          do {
            puVar2 = puVar2 + -1;
            puVar6[-1] = *puVar2;
            puVar6 = puVar6 + -2;
            param_2 = (undefined1 *)((int)param_2 - 1);
            *puVar6 = uVar3;
          } while (param_2 != (undefined1 *)0x0);
        }
      }
      else {
        if (1 < uVar1) {
          param_2 = (undefined1 *)(uVar1 - 1);
          do {
            puVar2 = puVar2 + -1;
            puVar6[-1] = uVar3;
            puVar6 = puVar6 + -2;
            param_2 = (undefined1 *)((int)param_2 + -1);
            *puVar6 = *puVar2;
          } while (param_2 != (undefined1 *)0x0);
        }
        puVar6[-1] = uVar3;
      }
      *(undefined1 *)((int)param_1 + 10) = 2;
      *(undefined1 *)((int)param_1 + 0xb) = 0x10;
      uVar1 = uVar1 * 2;
    }
    else {
      if (*(char *)((int)param_1 + 9) != '\x10') {
        return;
      }
      if ((param_4 & 0x80) == 0) {
        param_2 = (undefined1 *)(uVar1 + (int)param_2);
        puVar6 = param_2 + uVar1;
        if (uVar1 != 0) {
          param_4 = uVar1;
          do {
            puVar2 = param_2 + -1;
            param_2 = param_2 + -2;
            puVar6[-1] = *puVar2;
            puVar6[-2] = *param_2;
            puVar6[-3] = bVar4;
            puVar6 = puVar6 + -4;
            param_4 = param_4 - 1;
            *puVar6 = uVar3;
          } while (param_4 != 0);
        }
      }
      else {
        puVar6 = (undefined1 *)((int)param_2 + uVar1);
        puVar2 = puVar6 + uVar1;
        if (1 < uVar1) {
          param_2 = (undefined1 *)(uVar1 - 1);
          uVar5 = param_3 >> 8;
          do {
            puVar2[-1] = (char)uVar5;
            puVar2[-2] = uVar3;
            puVar2[-3] = puVar6[-1];
            puVar6 = puVar6 + -2;
            puVar2 = puVar2 + -4;
            param_2 = (undefined1 *)((int)param_2 + -1);
            *puVar2 = *puVar6;
            uVar5 = (uint)bVar4;
          } while (param_2 != (undefined1 *)0x0);
        }
        puVar2[-1] = bVar4;
        puVar2[-2] = uVar3;
      }
      *(undefined1 *)((int)param_1 + 10) = 2;
      *(undefined1 *)((int)param_1 + 0xb) = 0x20;
      uVar1 = uVar1 << 2;
    }
  }
  else {
    if ((char)param_1[2] != '\x02') {
      return;
    }
    if (*(char *)((int)param_1 + 9) == '\b') {
      puVar6 = (undefined1 *)((int)param_2 + uVar1 * 3);
      puVar2 = puVar6 + uVar1;
      if ((param_4 & 0x80) == 0) {
        if (uVar1 != 0) {
          param_2 = (undefined1 *)uVar1;
          do {
            puVar2[-1] = puVar6[-1];
            puVar2[-2] = puVar6[-2];
            puVar6 = puVar6 + -3;
            puVar2[-3] = *puVar6;
            puVar2 = puVar2 + -4;
            param_2 = (undefined1 *)((int)param_2 - 1);
            *puVar2 = uVar3;
          } while (param_2 != (undefined1 *)0x0);
        }
      }
      else {
        if (1 < uVar1) {
          param_2 = (undefined1 *)(uVar1 - 1);
          do {
            puVar2[-1] = uVar3;
            puVar2[-2] = puVar6[-1];
            puVar7 = puVar6 + -2;
            puVar6 = puVar6 + -3;
            puVar2[-3] = *puVar7;
            puVar2 = puVar2 + -4;
            param_2 = (undefined1 *)((int)param_2 + -1);
            *puVar2 = *puVar6;
          } while (param_2 != (undefined1 *)0x0);
        }
        puVar2[-1] = uVar3;
      }
      *(undefined1 *)((int)param_1 + 0xb) = 0x20;
      uVar1 = uVar1 << 2;
    }
    else {
      if (*(char *)((int)param_1 + 9) != '\x10') {
        return;
      }
      if ((param_4 & 0x80) == 0) {
        puVar6 = (undefined1 *)((int)param_2 + uVar1 * 3);
        puVar2 = puVar6 + uVar1;
        if (uVar1 != 0) {
          param_2 = (undefined1 *)uVar1;
          do {
            puVar2[-1] = puVar6[-1];
            puVar2[-2] = puVar6[-2];
            puVar2[-3] = puVar6[-3];
            puVar2[-4] = puVar6[-4];
            puVar2[-5] = puVar6[-5];
            puVar6 = puVar6 + -6;
            puVar2[-6] = *puVar6;
            puVar2[-7] = bVar4;
            puVar2 = puVar2 + -8;
            param_2 = (undefined1 *)((int)param_2 - 1);
            *puVar2 = uVar3;
          } while (param_2 != (undefined1 *)0x0);
        }
      }
      else {
        puVar6 = (undefined1 *)((int)param_2 + uVar1 * 3);
        puVar2 = puVar6 + uVar1;
        if (1 < uVar1) {
          param_2 = (undefined1 *)(uVar1 - 1);
          do {
            puVar2[-1] = bVar4;
            puVar2[-2] = uVar3;
            puVar2[-3] = puVar6[-1];
            puVar2[-4] = puVar6[-2];
            puVar2[-5] = puVar6[-3];
            puVar2[-6] = puVar6[-4];
            puVar7 = puVar6 + -5;
            puVar6 = puVar6 + -6;
            puVar2[-7] = *puVar7;
            puVar2 = puVar2 + -8;
            param_2 = (undefined1 *)((int)param_2 + -1);
            *puVar2 = *puVar6;
          } while (param_2 != (undefined1 *)0x0);
        }
        puVar2[-1] = bVar4;
        puVar2[-2] = uVar3;
      }
      *(undefined1 *)((int)param_1 + 0xb) = 0x40;
      uVar1 = uVar1 << 3;
    }
    *(undefined1 *)((int)param_1 + 10) = 4;
  }
  param_1[1] = uVar1;
  return;
}


// ==== FUN_008efe34 @ 0x008efe34 ====

void FUN_008efe34(int *param_1,byte *param_2,int param_3,byte *param_4,byte param_5)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  iVar5 = (int)param_4;
  iVar4 = param_3;
  bVar1 = *(byte *)((int)param_1 + 9);
  iVar11 = *param_1;
  if (((bVar1 < 9) && (param_3 != 0)) || ((bVar1 == 0x10 && (param_4 != (byte *)0x0)))) {
    cVar2 = (char)param_1[2];
    if (cVar2 == '\0') {
      if ((bVar1 == 2) && (param_4 = param_2, iVar11 != 0)) {
        param_3 = (iVar11 - 1U >> 2) + 1;
        do {
          uVar7 = (uint)*param_4;
          uVar9 = uVar7 & 0xc0;
          uVar8 = uVar7 & 3;
          uVar10 = uVar7 & 0xc;
          uVar7 = uVar7 & 0x30;
          param_3 = param_3 + -1;
          *param_4 = (byte)((byte)(*(byte *)(((uVar10 << 2 | uVar10) << 2 | (int)uVar10 >> 2 |
                                             uVar10) + iVar4) & 0xcf |
                                  *(byte *)((((uVar8 << 2 | uVar8) << 2 | uVar8) << 2 | uVar8) +
                                           iVar4) >> 2) >> 2 |
                           *(byte *)(((int)((int)uVar7 >> 2 | uVar7) >> 2 | uVar7 << 2 | uVar7) +
                                    iVar4) & 0xc3) >> 2 |
                     *(byte *)(((int)((int)((int)uVar9 >> 2 | uVar9) >> 2 | uVar9) >> 2 | uVar9) +
                              iVar4) & 0xc0;
          param_4 = param_4 + 1;
        } while (param_3 != 0);
      }
      cVar2 = *(char *)((int)param_1 + 9);
      if (cVar2 == '\x04') {
        if (iVar11 != 0) {
          iVar11 = (iVar11 - 1U >> 1) + 1;
          do {
            uVar8 = *param_2 & 0xf0;
            uVar7 = *param_2 & 0xf;
            *param_2 = *(byte *)(((int)uVar8 >> 4 | uVar8) + iVar4) & 0xf0 |
                       *(byte *)((uVar7 << 4 | uVar7) + iVar4) >> 4;
            param_2 = param_2 + 1;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
      }
      else if (cVar2 == '\b') {
        if (iVar11 != 0) {
          do {
            *param_2 = *(byte *)((uint)*param_2 + iVar4);
            param_2 = param_2 + 1;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
      }
      else if (cVar2 == '\x10') {
        for (; iVar11 != 0; iVar11 = iVar11 + -1) {
          uVar3 = *(undefined2 *)
                   (*(int *)(iVar5 + (uint)(param_2[1] >> (param_5 & 0x1f)) * 4) +
                   (uint)*param_2 * 2);
          *param_2 = (byte)((ushort)uVar3 >> 8);
          param_2[1] = (byte)uVar3;
          param_2 = param_2 + 2;
        }
      }
    }
    else if (cVar2 == '\x02') {
      if (bVar1 == 8) {
        if (iVar11 != 0) {
          do {
            *param_2 = *(byte *)((uint)*param_2 + param_3);
            param_2[1] = *(byte *)((uint)param_2[1] + param_3);
            param_2[2] = *(byte *)((uint)param_2[2] + param_3);
            param_2 = param_2 + 3;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
      }
      else if (iVar11 != 0) {
        pbVar6 = param_2;
        param_2 = (byte *)iVar11;
        do {
          uVar3 = *(undefined2 *)
                   (*(int *)((int)param_4 + (uint)(pbVar6[1] >> (param_5 & 0x1f)) * 4) +
                   (uint)*pbVar6 * 2);
          pbVar6[1] = (byte)uVar3;
          *pbVar6 = (byte)((ushort)uVar3 >> 8);
          uVar3 = *(undefined2 *)
                   (*(int *)((int)param_4 + (uint)(pbVar6[3] >> (param_5 & 0x1f)) * 4) +
                   (uint)pbVar6[2] * 2);
          pbVar6[3] = (byte)uVar3;
          pbVar6[2] = (byte)((ushort)uVar3 >> 8);
          uVar3 = *(undefined2 *)
                   (*(int *)((int)param_4 + (uint)(pbVar6[5] >> (param_5 & 0x1f)) * 4) +
                   (uint)pbVar6[4] * 2);
          pbVar6[4] = (byte)((ushort)uVar3 >> 8);
          pbVar6[5] = (byte)uVar3;
          pbVar6 = pbVar6 + 6;
          param_2 = (byte *)((int)param_2 + -1);
        } while (param_2 != (byte *)0x0);
      }
    }
    else if (cVar2 == '\x04') {
      if (bVar1 == 8) {
        if (iVar11 != 0) {
          do {
            *param_2 = *(byte *)((uint)*param_2 + param_3);
            param_2 = param_2 + 2;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
      }
      else {
        for (; iVar11 != 0; iVar11 = iVar11 + -1) {
          uVar3 = *(undefined2 *)
                   (*(int *)((int)param_4 + (uint)(param_2[1] >> (param_5 & 0x1f)) * 4) +
                   (uint)*param_2 * 2);
          *param_2 = (byte)((ushort)uVar3 >> 8);
          param_2[1] = (byte)uVar3;
          param_2 = param_2 + 4;
        }
      }
    }
    else if (cVar2 == '\x06') {
      if (bVar1 == 8) {
        if (iVar11 != 0) {
          do {
            *param_2 = *(byte *)((uint)*param_2 + param_3);
            param_2[1] = *(byte *)((uint)param_2[1] + param_3);
            param_2[2] = *(byte *)((uint)param_2[2] + param_3);
            param_2 = param_2 + 4;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
      }
      else if (iVar11 != 0) {
        pbVar6 = param_2;
        param_2 = (byte *)iVar11;
        do {
          uVar3 = *(undefined2 *)
                   (*(int *)((int)param_4 + (uint)(pbVar6[1] >> (param_5 & 0x1f)) * 4) +
                   (uint)*pbVar6 * 2);
          pbVar6[1] = (byte)uVar3;
          *pbVar6 = (byte)((ushort)uVar3 >> 8);
          uVar3 = *(undefined2 *)
                   (*(int *)((int)param_4 + (uint)(pbVar6[3] >> (param_5 & 0x1f)) * 4) +
                   (uint)pbVar6[2] * 2);
          pbVar6[3] = (byte)uVar3;
          pbVar6[2] = (byte)((ushort)uVar3 >> 8);
          uVar3 = *(undefined2 *)
                   (*(int *)((int)param_4 + (uint)(pbVar6[5] >> (param_5 & 0x1f)) * 4) +
                   (uint)pbVar6[4] * 2);
          pbVar6[4] = (byte)((ushort)uVar3 >> 8);
          pbVar6[5] = (byte)uVar3;
          pbVar6 = pbVar6 + 8;
          param_2 = (byte *)((int)param_2 + -1);
        } while (param_2 != (byte *)0x0);
      }
    }
  }
  return;
}


