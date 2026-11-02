// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x860000-0x86ffff

// ==== FUN_00860010 @ 0x00860010 ====

void FUN_00860010(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *_Memory;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar3 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar5 = puVar3;
          if (puVar5 == puVar2) {
            _Memory = *(void **)(*(int *)(param_1 + 4) + 4);
            if (*(char *)((int)_Memory + 0x15) == '\0') {
              FUN_008601e0(*(undefined4 *)((int)_Memory + 8));
              _free(_Memory);
              return;
            }
            *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
            *(undefined4 *)(param_1 + 8) = 0;
            *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
            *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
            return;
          }
          FUN_0085feb0(puVar5[4]);
          puVar3 = puVar5;
        } while (*(char *)((int)puVar5 + 0x15) != '\0');
        puVar3 = (undefined4 *)puVar5[2];
        if (*(char *)((int)puVar3 + 0x15) != '\0') break;
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar5 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      puVar3 = (undefined4 *)puVar5[1];
    } while (*(char *)((int)puVar3 + 0x15) != '\0');
    do {
      puVar4 = puVar3;
      puVar3 = puVar4;
      if (puVar5 != (undefined4 *)puVar4[2]) break;
      puVar3 = (undefined4 *)puVar4[1];
      puVar5 = puVar4;
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  } while( true );
}


// ==== FUN_008600c0 @ 0x008600c0 ====

void FUN_008600c0(void)

{
  int in_ECX;
  
  FUN_00860010(in_ECX + 0x1c);
  FUN_00860010(in_ECX + 0x28);
  FUN_00860010(in_ECX + 4);
  FUN_00860010(in_ECX + 0x10);
  return;
}


// ==== FUN_008600f0 @ 0x008600f0 ====

void FUN_008600f0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a130b4;
  FUN_00860010(in_ECX + 7);
  FUN_00860010(in_ECX + 10);
  FUN_00860010(in_ECX + 1);
  FUN_00860010(in_ECX + 4);
  _Memory = DAT_00b5d9a4;
  if (DAT_00b5d9a4 == (void *)0x0) {
    FUN_00860530(local_4,*(undefined4 *)in_ECX[0xb],(undefined4 *)in_ECX[0xb]);
    _free((void *)in_ECX[0xb]);
    return;
  }
  FUN_0085e500(DAT_00b5d9a4);
  DAT_00b5d9a4 = (void *)0x0;
  if (*(void **)((int)_Memory + 4) == (void *)0x0) {
    *(undefined4 *)((int)_Memory + 4) = 0;
    *(undefined4 *)((int)_Memory + 8) = 0;
    *(undefined4 *)((int)_Memory + 0xc) = 0;
    _free(_Memory);
    return;
  }
  _free(*(void **)((int)_Memory + 4));
  return;
}


// ==== FUN_008601e0 @ 0x008601e0 ====

void FUN_008601e0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_008601e0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00860220 @ 0x00860220 ====

void * FUN_00860220(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a210;
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


// ==== Catch@00860295 @ 0x00860295 ====

void Catch_00860295(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008602b0 @ 0x008602b0 ====

void FUN_008602b0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a220;
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


// ==== Catch@0086033a @ 0x0086033a ====

void Catch_0086033a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00860350 @ 0x00860350 ====

void FUN_00860350(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00860220(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00860455:
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
      if ((char)piVar6[5] == '\0') goto LAB_00860455;
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


// ==== FUN_00860530 @ 0x00860530 ====

void FUN_00860530(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_008601e0(piVar6[1]);
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


// ==== FUN_008605f0 @ 0x008605f0 ====

void FUN_008605f0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00860350(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00860350(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_008606b0 @ 0x008606b0 ====

void FUN_008606b0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a230;
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


// ==== Catch@00860811 @ 0x00860811 ====

void Catch_00860811(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00860900 @ 0x00860900 ====

uint FUN_00860900(undefined4 *param_1,undefined4 *param_2,byte param_3)

{
  void *_Memory;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  
  while( true ) {
    if (param_1 == param_2) {
      return (uint)param_3;
    }
    _Memory = (void *)*param_1;
    if (_Memory != (void *)0x0) break;
    param_1 = param_1 + 1;
  }
  if (*(void **)((int)_Memory + 0x14) != (void *)0x0) {
    _free(*(void **)((int)_Memory + 0x14));
    return extraout_EAX;
  }
  *(undefined4 *)((int)_Memory + 0x14) = 0;
  *(undefined4 *)((int)_Memory + 0x18) = 0;
  *(undefined4 *)((int)_Memory + 0x1c) = 0;
  if (*(void **)((int)_Memory + 4) == (void *)0x0) {
    *(undefined4 *)((int)_Memory + 4) = 0;
    *(undefined4 *)((int)_Memory + 8) = 0;
    *(undefined4 *)((int)_Memory + 0xc) = 0;
    _free(_Memory);
    return extraout_EAX_01;
  }
  _free(*(void **)((int)_Memory + 4));
  return extraout_EAX_00;
}


// ==== FUN_00860970 @ 0x00860970 ====

void FUN_00860970(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_008606b0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_008609c0 @ 0x008609c0 ====

void FUN_008609c0(byte param_1)

{
  void *in_ECX;
  
  FUN_008600f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008609e0 @ 0x008609e0 ====

void FUN_008609e0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar2 = DAT_0099d0dc;
  uVar1 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x5c) = DAT_0099d0dc;
  *(undefined4 *)(in_ECX + 0x60) = uVar1;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = uVar1;
  *(undefined4 *)(in_ECX + 0x78) = uVar2;
  *(undefined4 *)(in_ECX + 0x7c) = uVar2;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x84) = uVar1;
  *(undefined4 *)(in_ECX + 0x94) = uVar1;
  *(undefined4 *)(in_ECX + 0x98) = uVar1;
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  *(undefined4 *)(in_ECX + 0xa0) = uVar1;
  *(undefined4 *)(in_ECX + 0xb0) = uVar1;
  *(undefined4 *)(in_ECX + 0xb4) = uVar2;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  *(undefined4 *)(in_ECX + 0xbc) = uVar1;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined4 *)(in_ECX + 0x74) = uVar1;
  *(undefined4 *)(in_ECX + 0x6c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined4 *)(in_ECX + 0x88) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xa8) = uVar1;
  *(undefined4 *)(in_ECX + 0xac) = uVar1;
  *(undefined4 *)(in_ECX + 0xa4) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xc4) = uVar1;
  *(undefined4 *)(in_ECX + 200) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = 0xffffffff;
  return;
}


// ==== FUN_00860b30 @ 0x00860b30 ====

void FUN_00860b30(void)

{
  return;
}


// ==== FUN_00860b40 @ 0x00860b40 ====

void FUN_00860b40(float param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,float param_7)

{
  float fVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  fVar1 = DAT_0099d080;
  *(float *)(in_ECX + 0x5c) = param_1 - param_3;
  *(float *)(in_ECX + 0x60) = param_2 + param_3;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(float *)(in_ECX + 0x68) = fVar1;
  *(float *)(in_ECX + 0x78) = param_1 - param_3;
  *(float *)(in_ECX + 0x7c) = param_2 - param_3;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(float *)(in_ECX + 0x84) = fVar1;
  *(float *)(in_ECX + 0x94) = param_1 + param_3;
  *(float *)(in_ECX + 0x98) = param_2 + param_3;
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  *(float *)(in_ECX + 0xa0) = fVar1;
  *(float *)(in_ECX + 0xb0) = param_1 + param_3;
  *(float *)(in_ECX + 0xb4) = param_2 - param_3;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  *(float *)(in_ECX + 0xbc) = fVar1;
  if (param_4 < fVar1) {
    if (0.0 < param_4) {
      uVar5 = (uint)ROUND(param_4 * DAT_0099d0b8 + DAT_0099d0b4);
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0xff;
  }
  if (param_5 < fVar1) {
    if (0.0 < param_5) {
      uVar4 = (uint)ROUND(param_5 * DAT_0099d0b8 + DAT_0099d0b4);
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xff;
  }
  if (param_6 < fVar1) {
    if (0.0 < param_6) {
      uVar3 = (uint)ROUND(param_6 * DAT_0099d0b8 + DAT_0099d0b4);
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xff;
  }
  if (param_7 < fVar1) {
    if (0.0 < param_7) {
      iVar2 = (int)ROUND(param_7 * DAT_0099d0b8 + DAT_0099d0b4);
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0xff;
  }
  uVar3 = ((iVar2 << 8 | uVar5) << 8 | uVar4) << 8 | uVar3;
  *(uint *)(in_ECX + 0xc0) = uVar3;
  *(uint *)(in_ECX + 0xa4) = uVar3;
  *(uint *)(in_ECX + 0x88) = uVar3;
  *(uint *)(in_ECX + 0x6c) = uVar3;
  return;
}


// ==== FUN_00860dd0 @ 0x00860dd0 ====

void FUN_00860dd0(float param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float fVar5;
  float fVar6;
  float unaff_retaddr;
  float fStack_f0;
  float fStack_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float fStack_dc;
  float afStack_d8 [6];
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  float fStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  float fStack_9c;
  float afStack_98 [6];
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float afStack_64 [7];
  undefined4 auStack_48 [11];
  float *pfStack_1c;
  
  iVar2 = *(int *)(DAT_00b5ac04 + 0x74);
  local_e8 = *(float *)(iVar2 + 0x1c);
  local_e4 = *(float *)(iVar2 + 0x20);
  local_e0 = *(float *)(iVar2 + 0x24);
  thunk_FUN_0079e1ba(&local_e8,&local_e8);
  afStack_64[0] = DAT_0099d0b4;
  afStack_64[2] = DAT_0099d080;
  iVar2 = *(int *)(*(int *)(DAT_00b5ac04 + 0x78) + 4);
  local_e4 = *(float *)(iVar2 + 0xc);
  local_e0 = *(float *)(iVar2 + 0x10);
  fStack_dc = *(float *)(iVar2 + 0x14);
  fVar6 = local_e8 * DAT_00a13118;
  fVar5 = fStack_ec * DAT_00a13118;
  *(float *)(in_ECX + 0x10) = local_e4 + fStack_f0 * DAT_00a13118;
  *(float *)(in_ECX + 0x14) = local_e0 + fVar5;
  uVar1 = DAT_0099de84;
  *(float *)(in_ECX + 0x18) = fStack_dc + fVar6;
  *(undefined4 *)(in_ECX + 0x14) = uVar1;
  puVar3 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
  puVar4 = auStack_48;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  afStack_98[0] = unaff_retaddr * afStack_64[0];
  afStack_98[5] = param_1 * DAT_009b0318;
  afStack_64[1] = 0.0;
  fStack_6c = 0.0;
  uStack_74 = 0;
  uStack_78 = 0;
  uStack_7c = 0;
  uStack_80 = 0;
  afStack_98[4] = 0.0;
  afStack_98[3] = 0.0;
  afStack_98[2] = 0.0;
  afStack_98[1] = 0.0;
  fStack_70 = afStack_64[2];
  afStack_64[0] = param_1 * afStack_64[0];
  uStack_a0 = 0;
  uStack_a4 = 0;
  uStack_a8 = 0;
  uStack_ac = 0;
  uStack_b4 = 0;
  uStack_b8 = 0;
  uStack_bc = 0;
  uStack_c0 = 0;
  afStack_d8[4] = 0.0;
  afStack_d8[3] = 0.0;
  afStack_d8[2] = 0.0;
  afStack_d8[1] = 0.0;
  fStack_9c = afStack_64[2];
  fStack_b0 = afStack_64[2];
  afStack_d8[5] = afStack_64[2];
  afStack_d8[0] = afStack_64[2];
  fStack_68 = afStack_98[0];
  thunk_FUN_0079ee7b(afStack_d8,auStack_48,afStack_98);
  thunk_FUN_0079e43e(afStack_64,(float *)(in_ECX + 0x10),&local_e4);
  fVar5 = DAT_0099d080 / afStack_64[0];
  *pfStack_1c = fVar5 * fStack_70;
  pfStack_1c[1] = fVar5 * fStack_6c;
  pfStack_1c[2] = afStack_64[0];
  return;
}


// ==== FUN_00861070 @ 0x00861070 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00861070(void)

{
  float fVar1;
  float *pfVar2;
  int in_ECX;
  float10 fVar3;
  float fVar4;
  float fVar5;
  undefined1 local_c [12];
  
  fVar4 = (float)*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0);
  if (*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0) < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  *(float *)(in_ECX + 0x50) = fVar4;
  fVar4 = (float)*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c);
  if (*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c) < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  *(float *)(in_ECX + 0x54) = fVar4;
  if (*(char *)(in_ECX + 0x58) != '\0') {
    if (*(char *)(DAT_00b5ac04 + 0xcc) == '\0') {
      fVar3 = (float10)(**(code **)(*DAT_00b5af70 + 0x24))(6);
    }
    else {
      fVar3 = (float10)(**(code **)(*DAT_00b5af70 + 0x24))(7);
    }
    *(float *)(in_ECX + 0x50) = (float)fVar3;
    *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(in_ECX + 0x50);
  }
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(in_ECX + 0x50);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 0x54);
  pfVar2 = (float *)FUN_00860dd0(local_c,*(undefined4 *)(in_ECX + 0x50),
                                 *(undefined4 *)(in_ECX + 0x54));
  fVar4 = 0.0;
  *(float *)(in_ECX + 0x1c) = *pfVar2;
  *(float *)(in_ECX + 0x20) = pfVar2[1];
  *(float *)(in_ECX + 0x24) = pfVar2[2];
  if (0.0 < *(float *)(in_ECX + 0x24) || *(float *)(in_ECX + 0x24) == 0.0) {
    if (*(char *)(in_ECX + 0x58) != '\0') {
      *(undefined4 *)(in_ECX + 8) = DAT_009b9f98;
      return;
    }
    fVar5 = *(float *)(in_ECX + 0x1c);
    fVar1 = *(float *)(in_ECX + 0x20);
    if (0.0 <= fVar5) {
      if (fVar5 < *(float *)(in_ECX + 0x50) || fVar5 == *(float *)(in_ECX + 0x50)) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = fVar5 - *(float *)(in_ECX + 0x50);
      }
    }
    else {
      fVar5 = 0.0 - fVar5;
    }
    if (0.0 <= fVar1) {
      if (*(float *)(in_ECX + 0x54) <= fVar1 && fVar1 != *(float *)(in_ECX + 0x54)) {
        fVar4 = fVar1 - *(float *)(in_ECX + 0x54);
      }
    }
    else {
      fVar4 = 0.0 - fVar1;
    }
    if (fVar4 < fVar5) {
      fVar4 = fVar5;
    }
    if (*(float *)(in_ECX + 0xc) <= fVar4 && fVar4 != *(float *)(in_ECX + 0xc)) {
      fVar4 = *(float *)(in_ECX + 0xc);
    }
    *(float *)(in_ECX + 8) = (DAT_009b2dbc - fVar4 / *(float *)(in_ECX + 0xc)) * DAT_009b2dbc;
  }
  return;
}


// ==== FUN_008611e0 @ 0x008611e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_008611e0(int param_1,int param_2)

{
  float fVar1;
  char cVar2;
  int in_ECX;
  float local_44;
  float local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  int iStack_24;
  float fStack_20;
  float fStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  fVar1 = (float)param_1;
  if (param_1 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar1 = fVar1 / *(float *)(in_ECX + 0x50);
  local_44 = (fVar1 + fVar1) - DAT_0099d080;
  fVar1 = (float)param_2;
  if (param_2 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar1 = fVar1 / *(float *)(in_ECX + 0x54);
  local_40 = DAT_0099d080 - (fVar1 + fVar1);
  (**(code **)(*DAT_00b5a988 + 0x1c))(&local_3c,&local_44);
  fStack_1c = local_40;
  uStack_18 = local_3c;
  fStack_20 = local_44;
  uStack_10 = uStack_34;
  uStack_c = uStack_30;
  uStack_2c = 4;
  iStack_28 = param_1;
  iStack_24 = param_2;
  uStack_14 = uStack_38;
  cVar2 = (**(code **)(*DAT_00b5a6b4 + 0x20))(&uStack_2c);
  return cVar2 != '\0';
}


// ==== FUN_008612a0 @ 0x008612a0 ====

void FUN_008612a0(void)

{
  int in_ECX;
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x34);
  if (puVar1 != *(undefined4 **)(in_ECX + 0x38)) {
    do {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
        return;
      }
      puVar1 = puVar1 + 1;
    } while (puVar1 != *(undefined4 **)(in_ECX + 0x38));
  }
  if (*(void **)(in_ECX + 0x34) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x34));
  return;
}


// ==== FUN_008612f0 @ 0x008612f0 ====

void FUN_008612f0(void)

{
  int in_ECX;
  int *piVar1;
  
  piVar1 = *(int **)(in_ECX + 0x44);
  if (piVar1 != *(int **)(in_ECX + 0x48)) {
    do {
      if (*piVar1 != 0) {
        (**(code **)(*DAT_00b5a7cc + 0x14))(*piVar1);
      }
      piVar1 = piVar1 + 1;
    } while (piVar1 != *(int **)(in_ECX + 0x48));
  }
  if (*(void **)(in_ECX + 0x44) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x44) = 0;
    *(undefined4 *)(in_ECX + 0x48) = 0;
    *(undefined4 *)(in_ECX + 0x4c) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x44));
  return;
}


// ==== FUN_00861350 @ 0x00861350 ====

void FUN_00861350(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    FUN_008612f0();
    FUN_008612a0();
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00861370 @ 0x00861370 ====

void FUN_00861370(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13120;
  if (*(char *)(in_ECX + 1) != '\0') {
    FUN_008612f0();
    FUN_008612a0();
    *(undefined1 *)(in_ECX + 1) = 0;
  }
  if ((void *)in_ECX[0x11] != (void *)0x0) {
    _free((void *)in_ECX[0x11]);
    return;
  }
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  if ((void *)in_ECX[0xd] == (void *)0x0) {
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    *in_ECX = &PTR_FUN_00a10a18;
    return;
  }
  _free((void *)in_ECX[0xd]);
  return;
}


// ==== FUN_00861410 @ 0x00861410 ====

undefined4 FUN_00861410(uint param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  int extraout_EDX;
  
  piVar2 = (int *)FUN_0049b670();
  iVar5 = *(int *)(in_ECX + 0x44);
  if ((iVar5 == 0) || ((uint)(*(int *)(in_ECX + 0x48) - iVar5 >> 2) <= param_1)) {
    iVar5 = 0;
  }
  else {
    if ((iVar5 == 0) || ((uint)(*(int *)(in_ECX + 0x48) - iVar5 >> 2) <= param_1)) {
      FUN_004b4d10();
      iVar5 = extraout_EDX;
    }
    iVar5 = *(int *)(iVar5 + param_1 * 4);
  }
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar3 = 0;
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_004af750();
    iVar3 = (**(code **)(*piVar4 + 4))();
  }
  if (*(int *)(iVar1 + 0x134) != iVar3) {
    *(int *)(iVar1 + 0x134) = iVar3;
    (**(code **)(**(int **)(iVar1 + 0x90) + 0x104))(*(int **)(iVar1 + 0x90),0,iVar3);
  }
  (**(code **)(*piVar2 + 0x164))(piVar2,0x144);
  piVar4 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar4 + 0x14c))(piVar4,5,2,in_ECX + 0x5c,0x1c);
  (**(code **)(*piVar2 + 0x164))(piVar2,0);
  return 1;
}


// ==== FUN_008614e0 @ 0x008614e0 ====

void FUN_008614e0(char param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int in_ECX;
  int iVar6;
  undefined4 *puVar7;
  float *pfVar8;
  float *pfVar9;
  bool bVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float local_3c;
  float local_38;
  float local_34;
  float local_24;
  float local_20 [4];
  undefined4 local_10;
  undefined4 local_8;
  char local_4;
  
  if (((*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x75) != '\0') &&
      (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x7d) != '\0')) && (*(char *)(in_ECX + 4) != '\0'))
  {
    iVar6 = *(int *)(DAT_00b5ac04 + 0x74);
    fVar2 = *(float *)(iVar6 + 0x1c);
    fVar3 = *(float *)(iVar6 + 0x20);
    fVar4 = *(float *)(iVar6 + 0x24);
    FUN_00862a50(&local_3c);
    if (0.0 <= fVar4 * local_34 + fVar3 * local_38 + fVar2 * local_3c) {
      FUN_00861070();
      if ((param_1 == '\0') &&
         (cVar5 = FUN_008611e0((int)ROUND(*(float *)(in_ECX + 0x1c)),
                               (int)ROUND(*(float *)(in_ECX + 0x20))), cVar5 == '\x01')) {
        return;
      }
      FUN_00858d10();
      fVar2 = *(float *)(in_ECX + 0x28);
      puVar7 = *(undefined4 **)(in_ECX + 0x34);
      fVar3 = *(float *)(in_ECX + 8);
      fVar12 = fVar2 * DAT_0099d0b4;
      fVar13 = *(float *)(in_ECX + 0x2c) * DAT_0099d0b4;
      fVar4 = *(float *)(in_ECX + 0x1c);
      fVar1 = *(float *)(in_ECX + 0x20);
      if (puVar7 != *(undefined4 **)(in_ECX + 0x38)) {
        do {
          pfVar8 = (float *)*puVar7;
          pfVar9 = local_20;
          for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
            *pfVar9 = *pfVar8;
            pfVar8 = pfVar8 + 1;
            pfVar9 = pfVar9 + 1;
          }
          if (param_1 == '\x01') {
            bVar10 = local_4 == '\0';
LAB_00861668:
            if (!bVar10) goto LAB_0086166e;
          }
          else {
            if (param_1 == '\0') {
              bVar10 = local_4 == '\x01';
              goto LAB_00861668;
            }
LAB_0086166e:
            fVar11 = DAT_0099d080;
            if ((DAT_0099d080 < fVar3) || (fVar11 = 0.0, local_24 = fVar3, fVar3 < 0.0)) {
              local_24 = fVar11;
            }
            FUN_00860b40(fVar12 - local_20[1] * (fVar12 - fVar4),
                         fVar13 - local_20[1] * (fVar13 - fVar1),local_20[0] * DAT_0099d0b4 * fVar2,
                         local_20[2],local_20[3],local_10,local_24);
            FUN_00861410(local_8);
          }
          puVar7 = puVar7 + 1;
        } while (puVar7 != *(undefined4 **)(in_ECX + 0x38));
      }
      FUN_00858e60();
    }
  }
  return;
}


// ==== FUN_00861760 @ 0x00861760 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00861760(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined4 extraout_ECX;
  
  uVar2 = DAT_0099d080;
  *in_ECX = &PTR_FUN_00a13120;
  in_ECX[2] = uVar2;
  uVar2 = DAT_009b0e84;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  in_ECX[3] = uVar2;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  *(undefined1 *)(in_ECX + 0x16) = 0;
  fVar1 = (float)*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0);
  if (*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[0x14] = fVar1;
  fVar1 = (float)*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c);
  if (*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[0x15] = fVar1;
  FUN_008609e0();
  return extraout_ECX;
}


// ==== FUN_008617f0 @ 0x008617f0 ====

void FUN_008617f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 *param_8)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_20 [4];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  
  local_8 = param_1;
  local_20[2] = param_4;
  local_20[3] = param_5;
  local_20[0] = param_2;
  local_20[1] = param_3;
  local_10 = param_6;
  local_c = param_7;
  local_4 = param_8._0_1_;
  param_8 = operator_new(0x20);
  if (param_8 == (undefined4 *)0x0) {
    param_8 = (undefined4 *)0x0;
  }
  else {
    puVar2 = local_20;
    puVar3 = param_8;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  iVar1 = *(int *)(in_ECX + 0x34);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x3c) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x38) - iVar1 >> 2)))
  {
    FUN_00861ad0(*(undefined4 *)(in_ECX + 0x38),1,&param_8);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x38);
  *puVar2 = param_8;
  *(undefined4 **)(in_ECX + 0x38) = puVar2 + 1;
  return;
}


// ==== FUN_008618f0 @ 0x008618f0 ====

void FUN_008618f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int unaff_EBX;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  void **ppvVar7;
  int local_28;
  void *apvStack_24 [4];
  undefined4 uStack_14;
  int iStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  if ((((*(char *)(in_ECX + 4) != '\x01') && (DAT_00b5acec != (int *)0x0)) &&
      (local_28 = in_ECX, iVar3 = (**(code **)(*DAT_00b5acec + 0x14))(*(undefined1 *)(in_ECX + 5)),
      iVar3 != 0)) && (iVar3 != -4)) {
    iVar5 = *(int *)(iVar3 + 0x1c);
    iVar1 = *(int *)(iVar3 + 0x20);
    while (iVar5 != iVar1) {
      uStack_c = 0xf;
      iStack_10 = 0;
      apvStack_24[1] = (void *)((uint)apvStack_24[1] & 0xffffff00);
      FUN_00401660(iVar5,0,0xffffffff);
      if (iStack_10 != 0) {
        local_28 = FUN_004b4e70(apvStack_24);
        FUN_004b9b20(&local_28);
      }
      iVar5 = iVar5 + 0x1c;
      if (0xf < uStack_c) {
        _free(apvStack_24[1]);
        return;
      }
      uStack_c = 0xf;
      iStack_10 = 0;
      apvStack_24[1] = (void *)((uint)apvStack_24[1] & 0xffffff00);
    }
    puVar2 = *(undefined4 **)(iVar3 + 0x10);
    for (puVar4 = *(undefined4 **)(iVar3 + 0xc); puVar4 != puVar2; puVar4 = puVar4 + 8) {
      puVar6 = puVar4;
      ppvVar7 = apvStack_24;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *ppvVar7 = (void *)*puVar6;
        puVar6 = puVar6 + 1;
        ppvVar7 = ppvVar7 + 1;
      }
      FUN_008617f0(uStack_8,apvStack_24[0],apvStack_24[1],apvStack_24[2],apvStack_24[3],uStack_14,
                   iStack_10,uStack_c);
    }
    *(undefined1 *)(unaff_EBX + 4) = 1;
  }
  return;
}


// ==== FUN_00861a30 @ 0x00861a30 ====

void FUN_00861a30(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    FUN_008612f0();
    FUN_008612a0();
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  FUN_008618f0();
  return;
}


// ==== FUN_00861a60 @ 0x00861a60 ====

void FUN_00861a60(int *param_1,undefined1 param_2)

{
  int iVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x58) = param_2;
  iVar1 = (**(code **)(*param_1 + 0x4c))();
  if (*(char *)(in_ECX + 5) != *(char *)(iVar1 + 1)) {
    *(char *)(in_ECX + 5) = *(char *)(iVar1 + 1);
    if (*(char *)(in_ECX + 4) != '\0') {
      FUN_008612f0();
      FUN_008612a0();
      *(undefined1 *)(in_ECX + 4) = 0;
    }
    FUN_008618f0();
  }
  return;
}


// ==== FUN_00861ab0 @ 0x00861ab0 ====

void FUN_00861ab0(byte param_1)

{
  void *in_ECX;
  
  FUN_00861370();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00861ad0 @ 0x00861ad0 ====

void FUN_00861ad0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a240;
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


// ==== Catch@00861c31 @ 0x00861c31 ====

void Catch_00861c31(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00861d20 @ 0x00861d20 ====

void FUN_00861d20(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00861d2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  return;
}


// ==== FUN_00861d30 @ 0x00861d30 ====

void FUN_00861d30(undefined1 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
    *(undefined1 *)(iVar1 + 0x14) = *param_1;
    puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x20))();
    *puVar2 = *(undefined4 *)(param_1 + 4);
    iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
    *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1 + 8);
    iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0xc);
  }
  return;
}


// ==== FUN_00861db0 @ 0x00861db0 ====

void FUN_00861db0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x18) = 0;
  }
  return;
}


// ==== FUN_00861dd0 @ 0x00861dd0 ====

void FUN_00861dd0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 4) != (int *)0x0) {
    *(undefined4 *)(in_ECX + 0xc) = param_1;
    *(undefined4 *)(in_ECX + 0x10) = param_2;
    iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
    *(undefined4 *)(iVar1 + 0xc) = param_3;
  }
  return;
}


// ==== FUN_00861e10 @ 0x00861e10 ====

void FUN_00861e10(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  piVar1 = (int *)in_ECX[6];
  *in_ECX = &PTR_FUN_00a1318c;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[6] = 0;
  }
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a10a18;
  return;
}


// ==== FUN_00861e50 @ 0x00861e50 ====

void FUN_00861e50(void)

{
  byte bVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xea) == '\0') {
    bVar1 = -(*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe9) != '\0') & 2;
  }
  else {
    bVar1 = 1;
  }
  if (bVar1 == 1) {
    pvVar2 = operator_new(0x174);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00888da0(in_ECX);
      *(undefined4 *)(in_ECX + 4) = uVar3;
      return;
    }
  }
  else {
    if (bVar1 != 2) {
      return;
    }
    pvVar2 = operator_new(0x15c);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_0088a250(in_ECX);
      *(undefined4 *)(in_ECX + 4) = uVar3;
      return;
    }
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_00861ed0 @ 0x00861ed0 ====

void FUN_00861ed0(void)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  
  if (*(int **)(in_ECX + 4) != (int *)0x0) {
    if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xea) == '\0') {
      uVar2 = -(uint)(*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe9) != '\0') & 2;
    }
    else {
      uVar2 = 1;
    }
    uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
    if (uVar1 == uVar2) {
      return;
    }
    if (*(undefined4 **)(in_ECX + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 4))(1);
    }
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  FUN_00861e50();
  if (*(int **)(in_ECX + 4) == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00861f31. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  return;
}


// ==== FUN_00861f40 @ 0x00861f40 ====

void FUN_00861f40(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 4) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x18))();
    piVar1 = *(int **)(in_ECX + 0x18);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(in_ECX + 0x18) = 0;
    }
  }
  return;
}


// ==== FUN_00861f70 @ 0x00861f70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00861f70(void)

{
  float fVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1318c;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  FUN_00861e50();
  fVar1 = (float)*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0);
  if (*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[3] = fVar1;
  fVar1 = (float)*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c);
  if (*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[4] = fVar1;
  return;
}


// ==== FUN_00861fe0 @ 0x00861fe0 ====

void FUN_00861fe0(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  
  if ((((*(int *)(in_ECX + 4) != 0) &&
       (piVar3 = (int *)FUN_0049b670(), *(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x7c) != '\0')) &&
      ((iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x20))(), *(char *)(iVar4 + 0x14) != '\0' ||
       (*(char *)(in_ECX + 8) != '\0')))) &&
     (iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x20))(), *(int *)(iVar4 + 0x20) != 0)) {
    (**(code **)(*piVar3 + 0xa8))(piVar3);
    piVar1 = (int *)(in_ECX + 0x18);
    (**(code **)(*piVar3 + 0x98))(piVar3,0,piVar1);
    FUN_008588e0();
    (**(code **)(**(int **)(in_ECX + 4) + 8))();
    FUN_00858a00();
    (**(code **)(*piVar3 + 0x94))(piVar3,0,*piVar1);
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *piVar1 = 0;
    }
    (**(code **)(*piVar3 + 0xa4))(piVar3);
    FUN_00858a60();
    (**(code **)(**(int **)(in_ECX + 4) + 4))();
    FUN_00858b90();
    iVar4 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (*(char *)(iVar4 + 7) != '\0') {
      FUN_00858a60();
      iVar4 = **(int **)(in_ECX + 4);
      iVar5 = (**(code **)(*DAT_00b5ac00 + 8))();
      (**(code **)(iVar4 + 0xc))(*(char *)(iVar5 + 7) + -1);
      FUN_00858b90();
      return;
    }
  }
  return;
}


// ==== FUN_00862120 @ 0x00862120 ====

void FUN_00862120(byte param_1)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  piVar1 = (int *)in_ECX[6];
  *in_ECX = &PTR_FUN_00a1318c;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[6] = 0;
  }
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a10a18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00862170 @ 0x00862170 ====

void FUN_00862170(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined1 local_c0 [40];
  undefined4 local_98;
  undefined1 local_80 [52];
  undefined4 auStack_4c [3];
  undefined1 local_40 [56];
  undefined4 *puStack_8;
  
  local_c4 = DAT_0099d080;
  local_cc = 0;
  local_c8 = 0;
  local_d8 = 0;
  local_d4 = 0;
  local_d0 = 0;
  local_e4 = 0;
  local_e0 = DAT_00a132d8;
  local_dc = 0;
  FUN_007a053b(local_c0,&local_e4,&local_d8,&local_cc);
  local_98 = DAT_0099d080;
  FUN_007a0729(local_80,param_2,param_2,0x3f800000,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x2c));
  thunk_FUN_0079ee7b(local_40,local_c0,local_80);
  puVar2 = auStack_4c;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puStack_8 = *puVar2;
    puVar2 = puVar2 + 1;
    puStack_8 = puStack_8 + 1;
  }
  return;
}


// ==== FUN_00862250 @ 0x00862250 ====

void FUN_00862250(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x288) = *param_1;
  *(undefined4 *)(in_ECX + 0x28c) = param_1[1];
  *(undefined4 *)(in_ECX + 0x290) = param_1[2];
  *(undefined4 *)(in_ECX + 0x294) = param_1[3];
  return;
}


// ==== FUN_00862280 @ 0x00862280 ====

void FUN_00862280(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float local_40 [6];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar3 = DAT_0099d080 / (*param_3 - *param_2);
  local_40[0] = fVar3 * DAT_0099d0f8;
  local_10 = 0.0 - (*param_2 + *param_3) * fVar3;
  fVar3 = DAT_0099d080 / (param_3[1] - param_2[1]);
  local_40[5] = fVar3 * DAT_0099d0f8;
  local_c = 0.0 - (param_2[1] + param_3[1]) * fVar3;
  fVar3 = DAT_0099d080 / (param_3[2] - param_2[2]);
  local_18 = fVar3 * DAT_0099d0f8;
  local_40[4] = 0.0;
  local_20 = 0;
  local_40[1] = 0.0;
  local_1c = 0;
  local_40[2] = 0.0;
  local_28 = 0;
  local_8 = 0.0 - (param_2[2] + param_3[2]) * fVar3;
  local_40[3] = 0.0;
  local_24 = 0;
  local_14 = 0;
  local_4 = DAT_0099d080;
  pfVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_008623e0 @ 0x008623e0 ====

void FUN_008623e0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *in_ECX;
  
  in_ECX[0xbe] = DAT_0099d0f4;
  *in_ECX = &PTR_FUN_00a132e0;
  in_ECX[0xbf] = 0;
  puVar3 = operator_new(0x34);
  uVar1 = DAT_0099d080;
  if (puVar3 == (undefined4 *)0x0) {
    in_ECX[1] = 0;
    return;
  }
  puVar3[1] = DAT_0099d080;
  puVar3[2] = uVar1;
  *puVar3 = 0;
  puVar3[4] = uVar1;
  puVar3[3] = 0;
  puVar3[5] = 0;
  puVar3[7] = uVar1;
  puVar3[6] = 0;
  puVar3[8] = 0;
  uVar2 = DAT_009bf3cc;
  puVar3[10] = uVar1;
  puVar3[0xb] = DAT_009b012c;
  uVar1 = DAT_00a132d4;
  puVar3[9] = uVar2;
  puVar3[0xc] = uVar1;
  in_ECX[1] = puVar3;
  return;
}


// ==== FUN_00862490 @ 0x00862490 ====

void FUN_00862490(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a132e0;
  _free((void *)in_ECX[1]);
  return;
}


// ==== FUN_008624b0 @ 0x008624b0 ====

void FUN_008624b0(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_40 [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 *local_8;
  
  puVar3 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  local_8 = (undefined4 *)0x0;
  local_c = 0;
  local_10 = 0;
  thunk_FUN_0079ee7b(in_ECX + 0x108,local_40,in_ECX + 0x48);
  puVar3 = (undefined4 *)(in_ECX + 8);
  puVar2 = local_8;
  puVar4 = puVar3;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_0079ee7b(in_ECX + 200,puVar3,in_ECX + 0x48);
  thunk_FUN_0079f3a1(in_ECX + 0x88,0,puVar3);
  return;
}


// ==== FUN_00862530 @ 0x00862530 ====

void FUN_00862530(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puStack_150;
  undefined1 *puStack_14c;
  undefined1 *puStack_148;
  float fStack_144;
  float fStack_140;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  undefined1 *puStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  float fStack_10c;
  undefined1 *puStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined1 *puStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  float fStack_e8;
  float fStack_e4;
  undefined1 auStack_e0 [12];
  undefined1 auStack_d4 [8];
  undefined1 auStack_cc [64];
  undefined1 auStack_8c [12];
  undefined1 local_80 [20];
  undefined4 auStack_6c [3];
  undefined1 auStack_60 [80];
  float *pfStack_10;
  
  fStack_140 = (float)(in_ECX + 200);
  fStack_144 = 0.0;
  puStack_148 = local_80;
  puStack_14c = (undefined1 *)0x862554;
  thunk_FUN_0079f3a1();
  puStack_14c = auStack_8c;
  puStack_150 = auStack_cc;
  thunk_FUN_0079f0cc();
  fStack_124 = *pfStack_10;
  fStack_120 = pfStack_10[1];
  fStack_11c = pfStack_10[2];
  puStack_118 = (undefined1 *)pfStack_10[3];
  thunk_FUN_0079ebf5(&fStack_144,&fStack_124,auStack_d4);
  if (fStack_144 != 0.0) {
    if (0.0 < fStack_144) {
      fStack_140 = 0.0 - *pfStack_10;
      thunk_FUN_0079ebf5(&puStack_150,&fStack_140,auStack_e0);
    }
    uStack_ec = 0;
    uStack_f0 = 0;
    uStack_f4 = 0;
    uStack_fc = 0;
    uStack_100 = 0;
    uStack_104 = 0;
    uStack_110 = 0;
    uStack_114 = 0;
    fStack_11c = 0.0;
    fStack_e4 = DAT_0099d080;
    fStack_10c = DAT_0099d080;
    fStack_120 = DAT_0099d080;
    puStack_118 = puStack_150;
    puVar1 = (undefined4 *)(in_ECX + 0x48);
    puStack_108 = puStack_14c;
    puStack_f8 = puStack_148;
    fStack_e8 = fStack_144;
    thunk_FUN_0079ee7b(auStack_60,puVar1,&fStack_120);
    puVar3 = auStack_6c;
    puVar4 = puVar1;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    thunk_FUN_0079ee7b(unaff_EBX,in_ECX + 8,puVar1);
  }
  return;
}


// ==== FUN_008626e0 @ 0x008626e0 ====

void FUN_008626e0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uStack_ac;
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
  undefined4 uStack_50;
  undefined1 auStack_4c [12];
  undefined1 local_40 [64];
  
  thunk_FUN_0079f3a1(local_40,0,param_1);
  uStack_ac = DAT_0099d0dc;
  uStack_a8 = DAT_0099d0dc;
  uStack_a4 = 0;
  uStack_a0 = DAT_0099d080;
  uStack_9c = DAT_0099d0dc;
  uStack_98 = 0;
  uStack_94 = DAT_0099d0dc;
  uStack_90 = DAT_0099d080;
  uStack_8c = 0;
  uStack_88 = DAT_0099d080;
  uStack_84 = DAT_0099d080;
  uStack_80 = 0;
  uStack_7c = DAT_0099d0dc;
  uStack_78 = DAT_0099d0dc;
  uStack_74 = DAT_0099d080;
  uStack_70 = DAT_0099d080;
  uStack_6c = DAT_0099d0dc;
  uStack_68 = DAT_0099d080;
  uStack_64 = DAT_0099d0dc;
  uStack_60 = DAT_0099d080;
  uStack_5c = DAT_0099d080;
  uStack_58 = DAT_0099d080;
  uStack_54 = DAT_0099d080;
  uStack_50 = DAT_0099d080;
  puVar3 = &uStack_ac;
  iVar2 = 8;
  puVar4 = (undefined4 *)(in_ECX + 0x228);
  do {
    thunk_FUN_0079e5a0(puVar3,puVar3,auStack_4c);
    *puVar4 = *puVar3;
    uVar1 = puVar3[2];
    puVar4[1] = puVar3[1];
    puVar3 = puVar3 + 3;
    iVar2 = iVar2 + -1;
    puVar4[2] = uVar1;
    puVar4 = puVar4 + 3;
  } while (iVar2 != 0);
  return;
}


// ==== FUN_00862a50 @ 0x00862a50 ====

void FUN_00862a50(void)

{
  float *pfVar1;
  int in_ECX;
  float local_18;
  float local_14;
  float local_10;
  float local_c [2];
  float *pfStack_4;
  
  pfVar1 = *(float **)(in_ECX + 4);
  local_10 = pfVar1[2] - pfVar1[5];
  local_14 = pfVar1[1] - pfVar1[4];
  local_18 = *pfVar1 - pfVar1[3];
  thunk_FUN_0079e1ba(local_c,&local_18);
  *pfStack_4 = local_14;
  pfStack_4[1] = local_10;
  pfStack_4[2] = local_c[0];
  return;
}


// ==== FUN_00862ac0 @ 0x00862ac0 ====

void FUN_00862ac0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined1 auStack_c [4];
  undefined4 *puStack_8;
  
  iVar2 = (**(code **)(**(int **)(DAT_00b5ac04 + 0xd0) + 0x3c))();
  puVar1 = *(undefined4 **)(in_ECX + 4);
  uStack_10 = puVar1[2];
  uStack_18 = *puVar1;
  fStack_14 = *(float *)(iVar2 + 0x18) + (float)puVar1[1] + DAT_009b0ec8;
  thunk_FUN_0079e5a0(auStack_c,&uStack_18,param_2);
  *puStack_8 = uStack_18;
  puStack_8[1] = fStack_14;
  puStack_8[2] = uStack_10;
  return;
}


// ==== FUN_00862b50 @ 0x00862b50 ====

void FUN_00862b50(undefined4 *param_1)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  float fVar5;
  
  iVar4 = (**(code **)(**(int **)(DAT_00b5ac04 + 0xd0) + 0x3c))();
  puVar3 = *(undefined4 **)(in_ECX + 4);
  uVar1 = puVar3[2];
  fVar2 = *(float *)(iVar4 + 0x18);
  fVar5 = (float)puVar3[1] + DAT_009b0ec8;
  *param_1 = *puVar3;
  param_1[1] = fVar2 + fVar5;
  param_1[2] = uVar1;
  return;
}


// ==== FUN_00862bc0 @ 0x00862bc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00862bc0(float param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int in_ECX;
  int *unaff_retaddr;
  float local_10 [3];
  int *piStack_4;
  
  thunk_FUN_0079e43e(local_10);
  local_10[0] = DAT_0099d080 / local_10[0];
  iVar1 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x9c);
  iVar2 = *(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xa0);
  fVar3 = (float)iVar2;
  if (iVar2 < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  *piStack_4 = (int)ROUND(fVar3 * (local_10[0] * param_1 + DAT_0099d080) * DAT_0099d0b4);
  fVar3 = (float)iVar1;
  if (iVar1 < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  *unaff_retaddr =
       (int)ROUND(fVar3 * (DAT_0099d080 - local_10[0] * (float)(in_ECX + 200)) * DAT_0099d0b4);
  return;
}


// ==== FUN_00862cc0 @ 0x00862cc0 ====

void FUN_00862cc0(uint *param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  float fVar9;
  float local_8;
  
  pfVar1 = *(float **)(in_ECX + 4);
  fVar2 = SQRT((*pfVar1 - pfVar1[3]) * (*pfVar1 - pfVar1[3]) +
               (pfVar1[1] - pfVar1[4]) * (pfVar1[1] - pfVar1[4]) +
               (pfVar1[2] - pfVar1[5]) * (pfVar1[2] - pfVar1[5]));
  fVar9 = DAT_0099d100;
  if (DAT_0099d100 <= fVar2) {
    fVar9 = fVar2;
  }
  pfVar1 = *(float **)(in_ECX + 4);
  local_8 = 0.0;
  if (0.0 <= pfVar1[2] - fVar9) {
    local_8 = pfVar1[2] - fVar9;
  }
  fVar2 = ROUND(local_8);
  local_8 = 0.0;
  if (0.0 <= fVar9 + pfVar1[2]) {
    local_8 = fVar9 + pfVar1[2];
  }
  fVar3 = ROUND(local_8);
  local_8 = 0.0;
  if (0.0 <= *pfVar1 - fVar9) {
    local_8 = *pfVar1 - fVar9;
  }
  fVar4 = ROUND(local_8);
  local_8 = 0.0;
  if (0.0 <= *pfVar1 + fVar9) {
    local_8 = *pfVar1 + fVar9;
  }
  uVar8 = (int)fVar2;
  if ((uint)(int)fVar2 < *(uint *)(in_ECX + 0x28c)) {
    uVar8 = *(uint *)(in_ECX + 0x28c);
  }
  uVar6 = (int)fVar3;
  if (*(uint *)(in_ECX + 0x294) < (uint)(int)fVar3) {
    uVar6 = *(uint *)(in_ECX + 0x294);
  }
  uVar7 = (int)fVar4;
  if ((uint)(int)fVar4 < *(uint *)(in_ECX + 0x288)) {
    uVar7 = *(uint *)(in_ECX + 0x288);
  }
  uVar5 = (int)ROUND(local_8);
  if (*(uint *)(in_ECX + 0x290) < (uint)(int)ROUND(local_8)) {
    uVar5 = *(uint *)(in_ECX + 0x290);
  }
  *param_1 = uVar7;
  param_1[1] = uVar8;
  param_1[2] = uVar5;
  param_1[3] = uVar6;
  return;
}


// ==== FUN_00862e50 @ 0x00862e50 ====

void FUN_00862e50(float *param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,float param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = param_4 * param_6 - param_3 * param_7;
  fVar1 = param_3 * param_5 - param_2 * param_6;
  fVar3 = param_7 * param_2 - param_5 * param_4;
  *param_1 = fVar3 * param_7 - fVar1 * param_6;
  param_1[1] = fVar1 * param_5 - param_7 * fVar2;
  param_1[2] = fVar2 * param_6 - fVar3 * param_5;
  thunk_FUN_0079e1ba(param_1,param_1);
  return;
}


// ==== FUN_00862f50 @ 0x00862f50 ====

void FUN_00862f50(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int in_ECX;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  iVar5 = (**(code **)(**(int **)(DAT_00b5ac04 + 0xd0) + 0x68))();
  fVar8 = *(float *)(iVar5 + 0x40);
  fVar7 = *(float *)(iVar5 + 0x44);
  fVar1 = *(float *)(iVar5 + 0x48);
  iVar5 = (**(code **)(**(int **)(DAT_00b5ac04 + 0xd0) + 0x68))();
  fVar2 = *(float *)(iVar5 + 0x4c);
  fVar3 = *(float *)(iVar5 + 0x50);
  fVar4 = *(float *)(iVar5 + 0x54);
  fVar6 = *(float *)(in_ECX + 0xf0) * fVar1 + fVar8 * *(float *)(in_ECX + 0xd0) +
          fVar7 * *(float *)(in_ECX + 0xe0) + *(float *)(in_ECX + 0x100);
  fVar9 = 0.0;
  if (0.0 <= fVar6) {
    fVar9 = fVar6;
  }
  fVar6 = fVar1 * *(float *)(in_ECX + 0xf0) + fVar2 * *(float *)(in_ECX + 0xd0) +
          fVar7 * *(float *)(in_ECX + 0xe0) + *(float *)(in_ECX + 0x100);
  if (fVar9 <= fVar6) {
    fVar9 = fVar6;
  }
  fVar6 = fVar4 * *(float *)(in_ECX + 0xf0) + fVar8 * *(float *)(in_ECX + 0xd0) +
          fVar7 * *(float *)(in_ECX + 0xe0) + *(float *)(in_ECX + 0x100);
  if (fVar9 <= fVar6) {
    fVar9 = fVar6;
  }
  fVar7 = fVar4 * *(float *)(in_ECX + 0xf0) + fVar2 * *(float *)(in_ECX + 0xd0) +
          fVar7 * *(float *)(in_ECX + 0xe0) + *(float *)(in_ECX + 0x100);
  if (fVar9 <= fVar7) {
    fVar9 = fVar7;
  }
  fVar7 = fVar1 * *(float *)(in_ECX + 0xf0) + fVar8 * *(float *)(in_ECX + 0xd0) +
          fVar3 * *(float *)(in_ECX + 0xe0) + *(float *)(in_ECX + 0x100);
  if (fVar9 <= fVar7) {
    fVar9 = fVar7;
  }
  fVar7 = fVar1 * *(float *)(in_ECX + 0xf0) + fVar2 * *(float *)(in_ECX + 0xd0) +
          fVar3 * *(float *)(in_ECX + 0xe0) + *(float *)(in_ECX + 0x100);
  if (fVar9 <= fVar7) {
    fVar9 = fVar7;
  }
  fVar8 = fVar4 * *(float *)(in_ECX + 0xf0) + fVar8 * *(float *)(in_ECX + 0xd0) +
          fVar3 * *(float *)(in_ECX + 0xe0) + *(float *)(in_ECX + 0x100);
  if (fVar9 <= fVar8) {
    fVar9 = fVar8;
  }
  fVar8 = fVar4 * *(float *)(in_ECX + 0xf0) + fVar2 * *(float *)(in_ECX + 0xd0) +
          fVar3 * *(float *)(in_ECX + 0xe0) + *(float *)(in_ECX + 0x100);
  if (fVar9 <= fVar8) {
    fVar9 = fVar8;
  }
  *(float *)(in_ECX + 0x300) =
       *(float *)(in_ECX + 0xf0) * fVar4 + fVar3 * *(float *)(in_ECX + 0xe0) +
       fVar2 * *(float *)(in_ECX + 0xd0) + *(float *)(in_ECX + 0x100);
  *(float *)(in_ECX + 0x2fc) = *(float *)(*(int *)(in_ECX + 4) + 0x28) + fVar9;
  return;
}


// ==== FUN_00863390 @ 0x00863390 ====

void FUN_00863390(undefined4 param_1)

{
  float *pfVar1;
  int in_ECX;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iStack_13c;
  float fStack_138;
  float fStack_134;
  undefined4 uStack_130;
  float fStack_12c;
  float fStack_128;
  undefined4 uStack_124;
  float fStack_120;
  float fStack_11c;
  undefined4 uStack_118;
  float fStack_114;
  float fStack_110;
  undefined4 uStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  undefined1 local_c0 [40];
  undefined1 auStack_98 [12];
  undefined1 auStack_8c [64];
  undefined1 auStack_4c [12];
  undefined1 local_40 [48];
  float fStack_10;
  
  FUN_007a0693(local_c0,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x24),0x3f800000,
               *(undefined4 *)(*(int *)(in_ECX + 4) + 0x28),*(undefined4 *)(in_ECX + 0x2fc));
  thunk_FUN_0079ee7b(local_40,param_1,local_c0);
  thunk_FUN_0079f3a1(auStack_8c,0,auStack_4c);
  fStack_138 = DAT_0099d0dc;
  fStack_134 = DAT_0099d0dc;
  uStack_130 = 0;
  fStack_12c = DAT_0099d080;
  fStack_128 = DAT_0099d0dc;
  uStack_124 = 0;
  fStack_120 = DAT_0099d0dc;
  fStack_11c = DAT_0099d080;
  uStack_118 = 0;
  fStack_114 = DAT_0099d080;
  fStack_110 = DAT_0099d080;
  uStack_10c = 0;
  fStack_108 = DAT_0099d0dc;
  fStack_104 = DAT_0099d0dc;
  fStack_100 = DAT_0099d080;
  fStack_fc = DAT_0099d080;
  fStack_f8 = DAT_0099d0dc;
  fStack_f4 = DAT_0099d080;
  fStack_f0 = DAT_0099d0dc;
  fStack_ec = DAT_0099d080;
  fStack_e8 = DAT_0099d080;
  pfVar1 = (float *)(in_ECX + 0x298);
  fStack_e4 = DAT_0099d080;
  fStack_e0 = DAT_0099d080;
  fStack_dc = DAT_0099d080;
  pfVar3 = &fStack_138;
  iStack_13c = 8;
  pfVar2 = pfVar1;
  do {
    thunk_FUN_0079e5a0(pfVar3,pfVar3,auStack_98);
    *pfVar2 = *pfVar3;
    fVar4 = pfVar3[2];
    pfVar2[1] = pfVar3[1];
    pfVar3 = pfVar3 + 3;
    iStack_13c = iStack_13c + -1;
    pfVar2[2] = fVar4;
    pfVar2 = pfVar2 + 3;
  } while (iStack_13c != 0);
  if (fStack_10 != DAT_0099d080) {
    fVar8 = (*(float *)(in_ECX + 0x2ec) +
            *(float *)(in_ECX + 0x2e0) + *(float *)(in_ECX + 0x2d4) + *(float *)(in_ECX + 0x2c8)) *
            DAT_009fc7a0;
    fVar7 = (*(float *)(in_ECX + 0x2c4) +
            *(float *)(in_ECX + 0x2b8) + *(float *)(in_ECX + 0x2ac) + *(float *)(in_ECX + 0x2a0)) *
            DAT_009fc7a0;
    fVar10 = (*(float *)(in_ECX + 0x2f4) +
             *(float *)(in_ECX + 0x2e8) + *(float *)(in_ECX + 0x2dc) + *(float *)(in_ECX + 0x2d0)) *
             DAT_009fc7a0;
    fVar4 = (*pfVar1 + *(float *)(in_ECX + 0x2a4) + *(float *)(in_ECX + 0x2b0) +
            *(float *)(in_ECX + 700)) * DAT_009fc7a0;
    fVar5 = (*(float *)(in_ECX + 0x2c0) +
            *(float *)(in_ECX + 0x2b4) + *(float *)(in_ECX + 0x2a8) + *(float *)(in_ECX + 0x29c)) *
            DAT_009fc7a0;
    fStack_10 = fStack_10 - DAT_0099d080;
    fVar9 = (*(float *)(in_ECX + 0x2f0) +
            *(float *)(in_ECX + 0x2e4) + *(float *)(in_ECX + 0x2d8) + *(float *)(in_ECX + 0x2cc)) *
            DAT_009fc7a0;
    fVar6 = fStack_10 + DAT_0099d080;
    *(float *)(in_ECX + 0x29c) =
         (*(float *)(in_ECX + 0x29c) - fVar5) * fVar6 + *(float *)(in_ECX + 0x29c);
    *pfVar1 = *pfVar1 + (*pfVar1 - fVar4) * fVar6;
    *(float *)(in_ECX + 0x2a0) =
         (*(float *)(in_ECX + 0x2a0) - fVar7) * fVar6 + *(float *)(in_ECX + 0x2a0);
    *(float *)(in_ECX + 0x2c8) =
         *(float *)(in_ECX + 0x2c8) + (*(float *)(in_ECX + 0x2c8) - fVar8) * fStack_10;
    *(float *)(in_ECX + 0x2cc) =
         *(float *)(in_ECX + 0x2cc) + (*(float *)(in_ECX + 0x2cc) - fVar9) * fStack_10;
    *(float *)(in_ECX + 0x2d0) =
         *(float *)(in_ECX + 0x2d0) + (*(float *)(in_ECX + 0x2d0) - fVar10) * fStack_10;
    *(float *)(in_ECX + 0x2a4) =
         *(float *)(in_ECX + 0x2a4) + (*(float *)(in_ECX + 0x2a4) - fVar4) * fVar6;
    *(float *)(in_ECX + 0x2a8) =
         (*(float *)(in_ECX + 0x2a8) - fVar5) * fVar6 + *(float *)(in_ECX + 0x2a8);
    *(float *)(in_ECX + 0x2ac) =
         (*(float *)(in_ECX + 0x2ac) - fVar7) * fVar6 + *(float *)(in_ECX + 0x2ac);
    *(float *)(in_ECX + 0x2d4) =
         *(float *)(in_ECX + 0x2d4) + (*(float *)(in_ECX + 0x2d4) - fVar8) * fStack_10;
    *(float *)(in_ECX + 0x2d8) =
         *(float *)(in_ECX + 0x2d8) + (*(float *)(in_ECX + 0x2d8) - fVar9) * fStack_10;
    *(float *)(in_ECX + 0x2dc) =
         *(float *)(in_ECX + 0x2dc) + (*(float *)(in_ECX + 0x2dc) - fVar10) * fStack_10;
    *(float *)(in_ECX + 0x2b0) =
         *(float *)(in_ECX + 0x2b0) + (*(float *)(in_ECX + 0x2b0) - fVar4) * fVar6;
    *(float *)(in_ECX + 0x2b4) =
         (*(float *)(in_ECX + 0x2b4) - fVar5) * fVar6 + *(float *)(in_ECX + 0x2b4);
    *(float *)(in_ECX + 0x2b8) =
         (*(float *)(in_ECX + 0x2b8) - fVar7) * fVar6 + *(float *)(in_ECX + 0x2b8);
    *(float *)(in_ECX + 0x2e0) =
         *(float *)(in_ECX + 0x2e0) + (*(float *)(in_ECX + 0x2e0) - fVar8) * fStack_10;
    *(float *)(in_ECX + 0x2e4) =
         *(float *)(in_ECX + 0x2e4) + (*(float *)(in_ECX + 0x2e4) - fVar9) * fStack_10;
    *(float *)(in_ECX + 0x2e8) =
         *(float *)(in_ECX + 0x2e8) + (*(float *)(in_ECX + 0x2e8) - fVar10) * fStack_10;
    *(float *)(in_ECX + 700) = *(float *)(in_ECX + 700) + (*(float *)(in_ECX + 700) - fVar4) * fVar6
    ;
    *(float *)(in_ECX + 0x2c0) =
         (*(float *)(in_ECX + 0x2c0) - fVar5) * fVar6 + *(float *)(in_ECX + 0x2c0);
    *(float *)(in_ECX + 0x2c4) =
         (*(float *)(in_ECX + 0x2c4) - fVar7) * fVar6 + *(float *)(in_ECX + 0x2c4);
    *(float *)(in_ECX + 0x2ec) =
         *(float *)(in_ECX + 0x2ec) + (*(float *)(in_ECX + 0x2ec) - fVar8) * fStack_10;
    *(float *)(in_ECX + 0x2f0) =
         *(float *)(in_ECX + 0x2f0) + (*(float *)(in_ECX + 0x2f0) - fVar9) * fStack_10;
    *(float *)(in_ECX + 0x2f4) =
         *(float *)(in_ECX + 0x2f4) + (*(float *)(in_ECX + 0x2f4) - fVar10) * fStack_10;
  }
  return;
}


// ==== FUN_00863a80 @ 0x00863a80 ====

void FUN_00863a80(float *param_1,float *param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  float fVar3;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = DAT_009c3560;
  fVar3 = DAT_009b0e8c;
  *param_1 = DAT_009b0e8c;
  param_1[1] = fVar3;
  param_1[2] = fVar3;
  local_8 = local_c;
  *param_2 = local_c;
  param_2[1] = local_c;
  local_4 = local_c;
  param_2[2] = local_c;
  iVar1 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (DAT_0099cdc8 < *(float *)(iVar1 + 0x1c)) {
    *(undefined4 *)(in_ECX + 0x2f0) = *(undefined4 *)(in_ECX + 0x300);
  }
  iVar1 = in_ECX + 0x298;
  iVar2 = 8;
  do {
    thunk_FUN_0079e5a0(&local_c,iVar1,param_3);
    if (local_c < *param_1 || local_c == *param_1) {
      fVar3 = local_c;
    }
    else {
      fVar3 = *param_1;
    }
    *param_1 = fVar3;
    if (local_8 < param_1[1] || local_8 == param_1[1]) {
      fVar3 = local_8;
    }
    else {
      fVar3 = param_1[1];
    }
    param_1[1] = fVar3;
    if (local_4 < param_1[2] || local_4 == param_1[2]) {
      fVar3 = local_4;
    }
    else {
      fVar3 = param_1[2];
    }
    param_1[2] = fVar3;
    fVar3 = local_c;
    if (local_c < *param_2 || local_c == *param_2) {
      fVar3 = *param_2;
    }
    *param_2 = fVar3;
    fVar3 = local_8;
    if (local_8 < param_2[1] || local_8 == param_2[1]) {
      fVar3 = param_2[1];
    }
    param_2[1] = fVar3;
    fVar3 = local_4;
    if (local_4 < param_2[2] || local_4 == param_2[2]) {
      fVar3 = param_2[2];
    }
    iVar1 = iVar1 + 0xc;
    iVar2 = iVar2 + -1;
    param_2[2] = fVar3;
  } while (iVar2 != 0);
  return;
}


// ==== FUN_00863ed0 @ 0x00863ed0 ====

void FUN_00863ed0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_40 [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = *(int *)(in_ECX + 4);
  FUN_007a0693(in_ECX + 0x48,*(undefined4 *)(iVar2 + 0x24),*(undefined4 *)(iVar2 + 0x30),
               *(undefined4 *)(iVar2 + 0x28),*(undefined4 *)(iVar2 + 0x2c));
  iVar2 = *(int *)(in_ECX + 4);
  puVar1 = (undefined4 *)(in_ECX + 8);
  FUN_007a053b(puVar1,iVar2 + 0xc,iVar2,iVar2 + 0x18);
  puVar3 = puVar1;
  puVar4 = local_40;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  thunk_FUN_0079ee7b(in_ECX + 0x108,local_40,in_ECX + 0x48);
  thunk_FUN_0079ee7b(in_ECX + 200,puVar1,in_ECX + 0x48);
  thunk_FUN_0079f3a1(in_ECX + 0x88,0,puVar1);
  FUN_008626e0(in_ECX + 200);
  return;
}


// ==== FUN_00863f70 @ 0x00863f70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00863f70(float *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int in_ECX;
  
  if (param_2 == DAT_0099cdc8) {
    iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
    param_2 = (float)*(int *)(iVar2 + 0xa0);
    if (*(int *)(iVar2 + 0xa0) < 0) {
      param_2 = param_2 + _DAT_0099d104;
    }
    fVar1 = (float)*(int *)(iVar2 + 0x9c);
    if (*(int *)(iVar2 + 0x9c) < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    param_2 = param_2 / fVar1;
  }
  pfVar3 = *(float **)(in_ECX + 4);
  if (((((param_1[3] != *pfVar3) || (param_1[4] != pfVar3[1])) || (param_1[5] != pfVar3[2])) ||
      (((*param_1 != pfVar3[3] || (param_1[1] != pfVar3[4])) ||
       ((param_1[2] != pfVar3[5] || ((param_1[6] != pfVar3[6] || (param_1[7] != pfVar3[7])))))))) ||
     ((param_1[8] != pfVar3[8] ||
      ((((param_1[10] != pfVar3[10] || (param_1[9] != pfVar3[9])) || (param_1[0xb] != pfVar3[0xb]))
       || (param_2 != pfVar3[0xc])))))) {
    *pfVar3 = param_1[3];
    pfVar3[1] = param_1[4];
    pfVar3[2] = param_1[5];
    iVar2 = *(int *)(in_ECX + 4);
    *(float *)(iVar2 + 0xc) = *param_1;
    *(float *)(iVar2 + 0x10) = param_1[1];
    *(float *)(iVar2 + 0x14) = param_1[2];
    iVar2 = *(int *)(in_ECX + 4);
    *(float *)(iVar2 + 0x18) = param_1[6];
    *(float *)(iVar2 + 0x1c) = param_1[7];
    *(float *)(iVar2 + 0x20) = param_1[8];
    *(float *)(*(int *)(in_ECX + 4) + 0x28) = param_1[10];
    *(float *)(*(int *)(in_ECX + 4) + 0x24) = param_1[9];
    *(float *)(*(int *)(in_ECX + 4) + 0x2c) = param_1[0xb];
    *(float *)(*(int *)(in_ECX + 4) + 0x30) = param_2;
    FUN_00863ed0();
  }
  if (*(float *)(in_ECX + 0x2f8) != param_1[0xc]) {
    fVar1 = param_1[0xc];
    *(float *)(in_ECX + 0x2f8) = fVar1;
    (**(code **)(*DAT_00b5af70 + 0x14))(fVar1);
  }
  return;
}


// ==== FUN_00864290 @ 0x00864290 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00864290(float param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,float param_7,float param_8,float param_9)

{
  float fVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float fVar6;
  float fVar7;
  float fStack_1e8;
  float fStack_1e4;
  float local_1e0;
  float local_1dc;
  float local_1d8;
  float fStack_1d4;
  float local_1d0;
  float local_1cc;
  float local_1c8;
  float fStack_1c4;
  float fStack_1c0;
  float fStack_1bc;
  float fStack_1b8;
  float fStack_1b4;
  float local_1b0;
  float fStack_1ac;
  float fStack_1a8;
  float fStack_1a4;
  undefined1 auStack_1a0 [4];
  float fStack_19c;
  undefined1 auStack_194 [4];
  float fStack_190;
  float afStack_188 [6];
  undefined4 uStack_170;
  float fStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  float afStack_160 [4];
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  float fStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  void *pvStack_130;
  uint uStack_12c;
  uint uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  uint uStack_11c;
  float fStack_118;
  void *pvStack_114;
  undefined1 auStack_110 [16];
  uint uStack_100;
  undefined4 auStack_e8 [6];
  undefined1 auStack_d0 [28];
  undefined4 auStack_b4 [3];
  undefined1 auStack_a8 [12];
  undefined1 auStack_9c [52];
  undefined4 auStack_68 [25];
  
  local_1d0 = param_4 - param_1;
  local_1e0 = 0.0;
  local_1dc = DAT_0099d080;
  local_1cc = param_5 - param_2;
  local_1d8 = 0.0;
  local_1c8 = param_6 - param_3;
  thunk_FUN_0079e1ba(&local_1b0,&local_1d0);
  local_1c8 = param_7 * fStack_1b8 + param_8 * fStack_1b4 + param_9 * local_1b0;
  FUN_00862e50(&fStack_1e8,fStack_1b8,fStack_1b4,local_1b0,param_7,param_8,param_9);
  fStack_1bc = param_3 - param_9;
  fStack_1c0 = param_2 - param_8;
  fStack_1c4 = param_1 - param_7;
  iVar3 = in_ECX + 0x148;
  FUN_007a053b(iVar3,&param_1,&fStack_1c4,&fStack_1e8);
  FUN_00863a80(auStack_194,auStack_1a0,iVar3);
  fVar5 = (float10)FUN_00801d60();
  fVar5 = (float10)fsin(ABS(fVar5));
  local_1cc = (float)fVar5;
  fVar6 = DAT_0099d080 / local_1cc;
  local_1dc = ABS(fStack_19c - fStack_190);
  fVar6 = (SQRT((local_1dc * local_1cc + fVar6) * fVar6) + fVar6) * fVar6;
  fVar1 = fVar6 + local_1dc;
  fVar7 = fVar6 - DAT_0099d080;
  fStack_1a4 = param_3 - fVar7 * local_1e0;
  fStack_1a8 = param_2 - fVar7 * fStack_1e4;
  fStack_1ac = param_1 - fVar7 * fStack_1e8;
  local_1d8 = fStack_1ac - param_7;
  fStack_1d4 = fStack_1a8 - param_8;
  local_1d0 = fStack_1a4 - param_9;
  fStack_1c4 = local_1d8;
  fStack_1c0 = fStack_1d4;
  fStack_1bc = local_1d0;
  FUN_007a053b(iVar3,&fStack_1ac,&fStack_1c4,&fStack_1e8);
  uStack_150 = 0;
  afStack_160[2] = 0.0;
  afStack_160[1] = 0.0;
  uStack_164 = 0;
  uStack_168 = 0;
  uStack_170 = 0;
  afStack_188[4] = 0.0;
  afStack_188[3] = 0.0;
  afStack_188[2] = 0.0;
  afStack_188[1] = 0.0;
  afStack_160[0] = DAT_0099d080;
  afStack_188[0] = DAT_0099d080;
  afStack_188[5] = (fVar1 + fVar6) * (DAT_0099d080 / local_1dc);
  afStack_160[3] = fVar1 * fVar6 * _DAT_009fc7bc * (DAT_0099d080 / local_1dc);
  fStack_16c = DAT_0099d080;
  uStack_14c = 0;
  thunk_FUN_0079ee7b(auStack_d0,iVar3,afStack_188);
  puVar2 = auStack_e8 + 3;
  puVar4 = (undefined4 *)(in_ECX + 0x188);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_00863a80(auStack_1a0,&fStack_1ac,(undefined4 *)(in_ECX + 0x188));
  uStack_120 = 0;
  uStack_124 = 0;
  uStack_128 = 0;
  pvStack_130 = (void *)0x0;
  uStack_134 = 0;
  uStack_138 = 0;
  uStack_13c = 0;
  uStack_144 = 0;
  uStack_148 = 0;
  uStack_14c = 0;
  uStack_150 = 0;
  fStack_118 = DAT_0099d080;
  fStack_140 = DAT_0099d080;
  afStack_160[3] = DAT_0099d080;
  uStack_11c = DAT_0099d0b4;
  uStack_12c = DAT_0099d0b4;
  puVar2 = (undefined4 *)FUN_00862280(auStack_9c,auStack_1a0,&fStack_1ac);
  puVar4 = (undefined4 *)(in_ECX + 0x188);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_0079ee7b(auStack_e8 + 3,(undefined4 *)(in_ECX + 0x188),auStack_194);
  puVar2 = auStack_e8;
  puVar4 = auStack_68;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_0079ee7b(auStack_a8,auStack_68,afStack_160);
  puVar2 = auStack_b4;
  puVar4 = (undefined4 *)(in_ECX + 0x188);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_00401740(s_Near___2f_Far___2f_fDot___2f_a____00a13288,0x2c);
  FUN_00404230(auStack_110);
  pvStack_114 = (void *)0xf;
  fStack_118 = 0.0;
  uStack_128 = uStack_128 & 0xffffff00;
  FUN_00401740(s_shadow_00a132b8,6);
  (**(code **)(*DAT_00b5a688 + 8))(&uStack_12c,auStack_110);
  if (0xf < uStack_11c) {
    _free(pvStack_130);
    return;
  }
  if (uStack_100 < 0x10) {
    return;
  }
  _free(pvStack_114);
  return;
}


// ==== FUN_008647e0 @ 0x008647e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008647e0(float *param_1,float param_2,float param_3,float param_4,char param_5)

{
  float *pfVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  float10 fVar4;
  float fVar5;
  float fVar6;
  undefined8 in_stack_fffffec8;
  ulonglong in_stack_fffffed0;
  float fStack_d4;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  void *local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float fStack_a0;
  float fStack_9c;
  void *local_98;
  float local_94;
  float local_90;
  void *pvStack_88;
  uint uStack_84;
  undefined4 uStack_80;
  void *pvStack_7c;
  undefined1 auStack_78 [4];
  uint uStack_74;
  void *pvStack_6c;
  uint uStack_68;
  undefined4 uStack_5c;
  uint uStack_58;
  float local_54 [20];
  
  uVar2 = (undefined4)((ulonglong)in_stack_fffffec8 >> 0x20);
  local_54[1] = DAT_0099d080;
  local_54[0] = 0.0;
  local_54[2] = 0.0;
  pfVar1 = *(float **)(in_ECX + 4);
  fVar6 = (pfVar1[3] - *pfVar1) * (pfVar1[3] - *pfVar1) +
          (pfVar1[4] - pfVar1[1]) * (pfVar1[4] - pfVar1[1]) +
          (pfVar1[5] - pfVar1[2]) * (pfVar1[5] - pfVar1[2]);
  local_a4 = SQRT(fVar6);
  if (param_5 == '\0') {
    FUN_00862f50();
    pfVar1 = *(float **)(in_ECX + 4);
    local_c0 = *pfVar1;
    local_bc = pfVar1[1];
    local_b8 = pfVar1[2];
    local_ac = pfVar1[5];
    local_b4 = (void *)pfVar1[3];
    local_cc = (float)local_b4 - local_c0;
    local_c4 = local_ac - local_b8;
    local_c8 = 0.0;
    local_b0 = local_bc;
    thunk_FUN_0079e1ba(&local_cc,&local_cc);
    local_a4 = 0.0;
    local_a8 = 0.0;
    if (DAT_0099d100 <= local_ac) {
      local_c4 = local_c4 + DAT_009b0ec8;
      local_b8 = local_c4;
    }
    else {
      fVar4 = (float10)FUN_0040d4d0();
      *(float *)(in_ECX + 0x2fc) =
           *(float *)(in_ECX + 0x2fc) - (*(float *)(in_ECX + 0x2fc) - DAT_0099d0f8) * (float)fVar4;
      local_a4 = SQRT(local_cc * local_cc + fVar6 * fVar6 + fStack_d4 * fStack_d4);
      pfVar1 = (float *)FUN_00862a50();
      local_a8 = ABS((pfVar1[2] + *pfVar1) * DAT_0099cdc8 - pfVar1[1] * DAT_0099d080);
      fVar5 = local_a8 * DAT_0099d0f8 + (float)fVar4 + local_a4;
      local_b8 = fVar5 * fVar6 + local_c4;
      local_bc = fVar5 * fStack_d4 + local_c8;
      local_b4 = (void *)(local_c0 + fVar5 * local_cc);
      fStack_a0 = local_bc;
      fStack_9c = local_b8;
      local_98 = local_b4;
    }
    FUN_007a053b(in_ECX + 0x148,&local_bc,&local_c8,&uStack_5c);
    FUN_00863390(in_ECX + 0x148,0x3f8ccccd);
    FUN_00864290();
    pvStack_7c = (void *)0xf;
    uStack_80 = 0;
    local_90 = (float)((uint)local_90 & 0xffffff00);
    FUN_00401740(s__Cam__00a13224,5);
    in_stack_fffffed0 = in_stack_fffffed0 & 0xffffffffffffff00;
    FUN_00401740(s_Cam_____2f_Far____2f_Height____2_00a131e4,0x3c);
    uVar2 = FUN_00404230(auStack_78,uVar2,in_stack_fffffed0);
    (**(code **)(*DAT_00b5a688 + 8))(&local_94,uVar2);
    if (0xf < uStack_68) {
      _free(pvStack_7c);
      return;
    }
    uStack_68 = 0xf;
    pvStack_6c = (void *)0x0;
    pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
    if (0xf < uStack_84) {
      _free(local_98);
      return;
    }
    uStack_84 = 0xf;
    pvStack_88 = (void *)0x0;
    local_98 = (void *)((uint)local_98 & 0xffffff00);
    FUN_00401740(s__Cam2__00a13280,6);
    FUN_00401740(s_Dir_____2f____2f____2f___From_____00a13230,0x4c);
    uVar2 = FUN_00404230(&uStack_80);
    (**(code **)(*DAT_00b5a688 + 8))(&fStack_9c,uVar2);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    if (0xf < uStack_74) {
      _free(pvStack_88);
      return;
    }
  }
  else {
    local_90 = pfVar1[2] + param_4 * local_a4;
    local_94 = pfVar1[1] + param_3 * local_a4;
    local_98 = (void *)(*pfVar1 + param_2 * local_a4);
    FUN_007a053b(in_ECX + 0x148,&local_98,pfVar1,local_54);
    FUN_00862cc0(&local_b4);
    *(float *)(in_ECX + 0x170) = DAT_0099d080;
    FUN_007a0729();
  }
  thunk_FUN_0079ee7b();
  pfVar1 = local_54;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pfVar1;
    pfVar1 = pfVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_00864d70 @ 0x00864d70 ====

void FUN_00864d70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a132e0;
  _free((void *)in_ECX[1]);
  return;
}


// ==== FUN_00864db0 @ 0x00864db0 ====

void FUN_00864db0(void)

{
  return;
}


// ==== FUN_00864dc0 @ 0x00864dc0 ====

void FUN_00864dc0(void)

{
  return;
}


// ==== FUN_00864dd0 @ 0x00864dd0 ====

void FUN_00864dd0(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_00a13488;
  uVar2 = DAT_00a1347c;
  if (param_1 == 1) {
    *param_3 = DAT_00a134b0;
    *param_4 = DAT_00a134ac;
    param_3[1] = DAT_00a134a8;
    param_4[1] = DAT_00a134a4;
    return;
  }
  if (param_1 == 4) {
    *param_3 = DAT_00a134b0;
    *param_4 = DAT_00a134a0;
    param_3[1] = DAT_00a1349c;
    param_4[1] = DAT_00a13498;
    return;
  }
  if (param_1 == 0) {
    *param_3 = DAT_00a134b0;
    *param_4 = DAT_00a13494;
    param_3[1] = DAT_00a13490;
    param_4[1] = DAT_00a1348c;
    return;
  }
  if (param_1 == 3) {
    param_3[1] = DAT_00a134a8;
    uVar2 = DAT_00a13484;
  }
  else if (param_1 == 9) {
    param_3[1] = DAT_00a13480;
    uVar2 = DAT_00a1348c;
  }
  else if (param_1 == 8) {
    param_3[1] = DAT_00a13488;
  }
  else if (param_1 == 2) {
    param_3[1] = DAT_00a13478;
    uVar2 = DAT_00a13474;
  }
  else if (param_1 == 7) {
    param_3[1] = DAT_00a13470;
    uVar2 = DAT_00a1346c;
  }
  else if (param_1 == 6) {
    param_3[1] = DAT_00a13468;
    uVar2 = DAT_00a13464;
  }
  else {
    param_3[1] = DAT_00a13460;
    uVar2 = DAT_00a1345c;
  }
  param_4[1] = uVar2;
  switch(param_2) {
  case 0:
    *param_3 = DAT_00a13458;
    *param_4 = DAT_00a13454;
    return;
  case 1:
    *param_3 = DAT_00a13450;
    *param_4 = DAT_00a1344c;
    return;
  case 2:
    *param_3 = DAT_00a13448;
    *param_4 = DAT_00a13444;
    return;
  case 3:
    *param_3 = uVar1;
    *param_4 = DAT_00a13440;
    return;
  case 4:
    *param_3 = DAT_00a1343c;
    *param_4 = DAT_00a13438;
    return;
  case 5:
    *param_3 = DAT_00a13434;
    *param_4 = DAT_00a13430;
    return;
  case 6:
    *param_3 = DAT_00a1342c;
    *param_4 = DAT_00a13428;
    return;
  case 7:
    *param_3 = DAT_00a13424;
    *param_4 = DAT_00a13420;
    return;
  case 8:
    *param_3 = DAT_00a1341c;
    *param_4 = DAT_00a13418;
    return;
  case 9:
    *param_3 = DAT_00a13414;
    *param_4 = DAT_00a13410;
    return;
  default:
    *param_4 = 0;
    param_4[1] = 0;
    *param_3 = 0;
    param_3[1] = 0;
    return;
  }
}


// ==== FUN_00865120 @ 0x00865120 ====

undefined4 FUN_00865120(undefined4 param_1,undefined4 *param_2)

{
  float unaff_EBX;
  float unaff_ESI;
  float unaff_EDI;
  float local_48 [2];
  undefined1 local_40 [8];
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined1 local_10 [8];
  float *pfStack_8;
  
  FUN_00864dd0(*param_2,0,local_48,local_40);
  local_2c = (float)param_2[4] * DAT_0099d0b4;
  local_28 = (float)param_2[5] * DAT_0099d0b4;
  local_38 = (float)param_2[1];
  local_34 = (float)param_2[2];
  local_30 = (float)param_2[3];
  local_14 = DAT_0099d080;
  local_20 = local_38;
  local_1c = local_34;
  local_18 = local_30;
  thunk_FUN_0079ebf5(local_10,&local_20,*(int *)(DAT_00b5ac04 + 0x78) + 8);
  pfStack_8[5] = (float)param_2[6];
  pfStack_8[3] = unaff_EDI;
  pfStack_8[4] = local_48[0];
  *pfStack_8 = local_1c - local_38;
  pfStack_8[1] = local_18 - local_34;
  pfStack_8[2] = local_14;
  pfStack_8[0xb] = (float)param_2[6];
  pfStack_8[9] = unaff_EDI;
  pfStack_8[10] = unaff_ESI;
  pfStack_8[6] = local_1c - local_38;
  pfStack_8[7] = local_34 + local_18;
  pfStack_8[8] = local_14;
  pfStack_8[0x11] = (float)param_2[6];
  pfStack_8[0xf] = unaff_EBX;
  pfStack_8[0x10] = unaff_ESI;
  pfStack_8[0xc] = local_38 + local_1c;
  pfStack_8[0xd] = local_34 + local_18;
  pfStack_8[0xe] = local_14;
  pfStack_8[0x12] = *pfStack_8;
  pfStack_8[0x13] = pfStack_8[1];
  pfStack_8[0x14] = pfStack_8[2];
  pfStack_8[0x15] = pfStack_8[3];
  pfStack_8[0x16] = pfStack_8[4];
  pfStack_8[0x17] = pfStack_8[5];
  pfStack_8[0x18] = pfStack_8[0xc];
  pfStack_8[0x19] = pfStack_8[0xd];
  pfStack_8[0x1a] = pfStack_8[0xe];
  pfStack_8[0x1b] = pfStack_8[0xf];
  pfStack_8[0x1c] = pfStack_8[0x10];
  pfStack_8[0x1d] = pfStack_8[0x11];
  pfStack_8[0x23] = (float)param_2[6];
  pfStack_8[0x21] = unaff_EBX;
  pfStack_8[0x22] = local_48[0];
  pfStack_8[0x1e] = local_38 + local_1c;
  pfStack_8[0x1f] = local_18 - local_34;
  pfStack_8[0x20] = local_14;
  return 6;
}


// ==== FUN_00865520 @ 0x00865520 ====

void FUN_00865520(void)

{
  int in_ECX;
  
  FUN_00865fe0(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
  *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  return;
}


// ==== FUN_00865550 @ 0x00865550 ====

void FUN_00865550(int *param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  int unaff_EBX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [12];
  float fStack_58;
  undefined1 auStack_54 [4];
  undefined4 auStack_50 [19];
  
  iVar2 = (**(code **)(*param_1 + 0xf8))();
  if (iVar2 != 0) {
    pfVar1 = *(float **)(*(int *)(DAT_00b5ac04 + 0x78) + 4);
    fStack_7c = pfVar1[2] - pfVar1[5];
    fStack_80 = pfVar1[1] - pfVar1[4];
    fStack_84 = *pfVar1 - pfVar1[3];
    thunk_FUN_0079e1ba(&fStack_84,&fStack_84);
    puVar4 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 8);
    puVar5 = auStack_50;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    iVar2 = 0;
    if (0 < unaff_EBX) {
      do {
        fVar3 = (float)(**(code **)(*param_1 + 0xfc))(iVar2);
        uStack_74 = *(undefined4 *)((int)fVar3 + 0xc);
        fStack_7c = *(float *)((int)fVar3 + 4);
        fStack_78 = *(float *)((int)fVar3 + 8) + DAT_009b6df8;
        uStack_70 = DAT_0099d080;
        thunk_FUN_0079ebf5(auStack_64,&fStack_7c,auStack_54);
        fStack_80 = fStack_58;
        fStack_7c = fVar3;
        FUN_008663f0(auStack_68,&fStack_80);
        iVar2 = iVar2 + 1;
      } while (iVar2 < unaff_EBX);
    }
  }
  return;
}


// ==== FUN_00865690 @ 0x00865690 ====

void FUN_00865690(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_40 [16];
  
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 0x48);
  puVar3 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x1f)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x98))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x78),local_40);
  return;
}


// ==== FUN_008656f0 @ 0x008656f0 ====

int FUN_008656f0(undefined4 param_1,undefined4 *param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  int iVar13;
  int iStack_90;
  undefined4 local_80;
  float local_7c;
  float local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  float fStack_68;
  float fStack_64;
  undefined4 uStack_60;
  float fStack_5c;
  float fStack_58;
  undefined4 uStack_54;
  float fStack_4c;
  float fStack_48;
  undefined4 local_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  undefined4 uStack_30;
  undefined4 local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  undefined1 local_10 [8];
  int iStack_8;
  
  local_80 = param_2[1];
  local_7c = (float)param_2[2];
  local_78 = (float)param_2[3];
  local_14 = DAT_0099d080;
  local_20 = local_80;
  local_1c = local_7c;
  local_18 = local_78;
  thunk_FUN_0079ebf5(local_10,&local_20,*(int *)(DAT_00b5ac04 + 0x78) + 8);
  fVar8 = 0.0;
  fVar6 = (float)param_2[4] * DAT_0099d0b4;
  fVar10 = (float)param_2[5] * DAT_0099d0b4;
  if (param_2[0xc] == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (int)(param_2[0xd] - param_2[0xc]) >> 2;
  }
  iVar13 = 0;
  if (uVar4 != 0) {
    iStack_90 = uVar4 * 4;
    puVar5 = (undefined4 *)(iStack_8 + 0xc);
    uVar9 = local_14;
    uVar12 = uVar4;
    while( true ) {
      iStack_90 = iStack_90 + -4;
      uVar12 = uVar12 - 1;
      iVar2 = param_2[0xc];
      if ((iVar2 == 0) || ((uint)(param_2[0xd] - iVar2 >> 2) <= uVar12)) {
                    /* WARNING: Subroutine does not return */
        FUN_0042f370();
      }
      fVar7 = fVar6;
      fVar11 = local_18;
      FUN_00864dd0(*param_2,*(undefined4 *)(iVar2 + iStack_90),&local_80,&local_78);
      iVar2 = param_2[8];
      if ((iVar2 == 0) || ((uint)(param_2[9] - iVar2 >> 2) <= uVar12)) {
                    /* WARNING: Subroutine does not return */
        FUN_0042f370();
      }
      fVar1 = *(float *)(iVar2 + iStack_90);
      puVar5[2] = param_2[6];
      uStack_70 = local_80;
      *puVar5 = local_80;
      uStack_6c = uStack_74;
      puVar5[1] = uStack_74;
      fStack_68 = (local_1c - fVar7) + fVar8;
      puVar5[-3] = fStack_68;
      fStack_48 = fVar11 - fVar10;
      puVar5[-2] = fStack_48;
      puVar5[-1] = uVar9;
      uVar3 = param_2[6];
      puVar5[6] = local_80;
      puVar5[8] = uVar3;
      puVar5[7] = local_7c;
      puVar5[3] = fStack_68;
      fStack_64 = fVar10 + fVar11;
      puVar5[4] = fStack_64;
      puVar5[5] = uVar9;
      puVar5[0xe] = param_2[6];
      fStack_40 = local_78;
      fStack_3c = local_7c;
      puVar5[0xd] = local_7c;
      puVar5[0xc] = local_78;
      fStack_5c = (local_1c - fVar7) + fVar1 + fVar8;
      puVar5[9] = fStack_5c;
      puVar5[10] = fStack_64;
      puVar5[0xb] = uVar9;
      puVar5[0xf] = puVar5[-3];
      puVar5[0x10] = puVar5[-2];
      puVar5[0x11] = puVar5[-1];
      puVar5[0x12] = *puVar5;
      puVar5[0x13] = puVar5[1];
      puVar5[0x14] = puVar5[2];
      iVar13 = iVar13 + 6;
      puVar5[0x15] = puVar5[9];
      puVar5[0x16] = puVar5[10];
      puVar5[0x17] = puVar5[0xb];
      puVar5[0x18] = puVar5[0xc];
      puVar5[0x19] = puVar5[0xd];
      puVar5[0x1a] = puVar5[0xe];
      puVar5[0x20] = param_2[6];
      puVar5[0x1e] = local_78;
      puVar5[0x1f] = uStack_74;
      puVar5[0x1b] = fStack_5c;
      uVar4 = uVar4 - 1;
      puVar5[0x1c] = fStack_48;
      fVar8 = fVar1 + fVar8;
      puVar5[0x1d] = uVar9;
      if (uVar4 == 0) break;
      puVar5 = puVar5 + 0x24;
      uStack_60 = uVar9;
      fStack_58 = fStack_64;
      uStack_54 = uVar9;
      fStack_4c = fStack_5c;
      local_44 = uVar9;
      fStack_38 = fStack_68;
      fStack_34 = fStack_48;
      uStack_30 = uVar9;
    }
  }
  return iVar13;
}


// ==== FUN_00865a50 @ 0x00865a50 ====

void FUN_00865a50(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a134b8;
  if (in_ECX[4] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[4]);
    in_ECX[4] = 0;
  }
  FUN_00866330(local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00865ab0 @ 0x00865ab0 ====

/* WARNING: Removing unreachable block (ram,0x00865c3b) */
/* WARNING: Removing unreachable block (ram,0x00865bbf) */
/* WARNING: Removing unreachable block (ram,0x00865c6a) */
/* WARNING: Removing unreachable block (ram,0x00865af4) */

undefined1 FUN_00865ab0(undefined4 param_1,uint *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  char cVar7;
  int iVar8;
  int in_ECX;
  int *unaff_EBX;
  int unaff_EBP;
  uint uVar9;
  int *piVar10;
  int iVar11;
  
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  FUN_00401740(s_FillVertexBuffer_Step_1_00a13398,0x17);
  puVar2 = (undefined4 *)**(undefined4 **)(in_ECX + 8);
  uVar9 = 0;
  while (puVar2 != *(undefined4 **)(in_ECX + 8)) {
    piVar10 = (int *)puVar2[4];
    if ((*piVar10 == 1) || (*piVar10 == 0)) {
      uVar9 = uVar9 + 6;
    }
    else if (piVar10[0xc] != 0) {
      uVar9 = uVar9 + (piVar10[0xd] - piVar10[0xc] >> 2) * 6;
    }
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        cVar7 = *(char *)((int)*puVar3 + 0x15);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar7 == '\0') {
          cVar7 = *(char *)((int)*puVar3 + 0x15);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar7 = *(char *)((int)puVar2[1] + 0x15);
        puVar6 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar6, cVar7 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar7 = *(char *)((int)puVar2[1] + 0x15);
          puVar6 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  *param_2 = uVar9 / 3;
  FUN_00401740(s_FillVertexBuffer_Step_2_00a133b0,0x17);
  iVar11 = uVar9 * 0x18;
  cVar7 = FUN_00881000(0x18,iVar11);
  if (cVar7 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  cVar7 = FUN_00881000(0x18,iVar11);
  if (cVar7 == '\0') {
    return 0;
  }
  uRam0000000f = (**(code **)(*piVar1 + 0x1c))(0x18,iVar11);
  FUN_00401740(s_FillVertexBuffer_Step_3_00a133c8,0x17);
  FUN_00401740(s_FillVertexBuffer_Step_3_2_00a133e0,0x19);
  piVar1 = *(int **)(unaff_EBP + 8);
  piVar10 = (int *)*piVar1;
  if (piVar10 != piVar1) {
    iVar11 = unaff_EBP + 0x14;
    do {
      puVar2 = (undefined4 *)piVar10[4];
      iVar8 = 0;
      switch(*puVar2) {
      case 0:
      case 1:
      case 4:
        iVar8 = FUN_00865120(iVar11,puVar2);
        break;
      case 2:
      case 3:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
        iVar8 = FUN_008656f0(iVar11,puVar2);
      }
      (**(code **)(*unaff_EBX + 0x14))(iVar8 * 0x18,iVar11);
      if (*(char *)((int)piVar10 + 0x15) == '\0') {
        piVar4 = (int *)piVar10[2];
        if (*(char *)((int)piVar4 + 0x15) == '\0') {
          cVar7 = *(char *)(*piVar4 + 0x15);
          piVar10 = piVar4;
          piVar4 = (int *)*piVar4;
          while (cVar7 == '\0') {
            cVar7 = *(char *)(*piVar4 + 0x15);
            piVar10 = piVar4;
            piVar4 = (int *)*piVar4;
          }
        }
        else {
          cVar7 = *(char *)(piVar10[1] + 0x15);
          piVar5 = (int *)piVar10[1];
          piVar4 = piVar10;
          while ((piVar10 = piVar5, cVar7 == '\0' && (piVar4 == (int *)piVar10[2]))) {
            cVar7 = *(char *)(piVar10[1] + 0x15);
            piVar5 = (int *)piVar10[1];
            piVar4 = piVar10;
          }
        }
      }
    } while (piVar10 != piVar1);
  }
  FUN_00881060();
  return 1;
}


// ==== FUN_00865d50 @ 0x00865d50 ====

void FUN_00865d50(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_00a134b8;
  iVar1 = FUN_008660b0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ui_default_damage_dds_00a13324,0x15);
  uVar2 = FUN_004b4e70(local_1c);
  in_ECX[4] = uVar2;
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00865de0 @ 0x00865de0 ====

void FUN_00865de0(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uStack_58;
  int *piStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  int *piStack_48;
  char *pcStack_44;
  int *piStack_40;
  undefined1 local_20 [8];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piStack_40 = (int *)local_20;
    pcStack_44 = (char *)0x865e07;
    cVar2 = FUN_00865ab0();
    if (cVar2 != '\0') {
      piStack_40 = (int *)s_CTextureNumberRenderer_Setup_00a1333c;
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      pcStack_44 = (char *)0x865e2f;
      FUN_00401740();
      if (0xf < local_4) {
        piStack_40 = (int *)0x865e40;
        _free(local_18);
        return;
      }
      FUN_00858740();
      piStack_40 = (int *)0x865e60;
      iVar3 = FUN_0085e3a0();
      piStack_40 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      pcStack_44 = (char *)0x865e7e;
      (**(code **)(*piStack_40 + 0x15c))();
      piStack_48 = *(int **)(iVar3 + 0x1c);
      pcStack_44 = s_Billboard_00a1335c;
      iStack_4c = 0x865e8f;
      (**(code **)(*piStack_48 + 0xf0))();
      uStack_50 = 0x865e97;
      iStack_4c = iVar3;
      FUN_00865690();
      iVar1 = *(int *)(in_ECX + 0x10);
      iStack_4c = 7;
      uStack_50 = 0x865eaa;
      iVar4 = FUN_0085e3a0();
      uVar5 = 0;
      if (iVar1 != 0) {
        iStack_4c = 0x865eb9;
        piVar6 = (int *)FUN_004af750();
        iStack_4c = 0x865ec0;
        uVar5 = (**(code **)(*piVar6 + 4))();
      }
      iVar1 = *(int *)(iVar4 + 0x28);
      if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x21)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      uStack_50 = *(undefined4 *)(iVar1 + 0x80);
      piStack_54 = *(int **)(iVar4 + 0x1c);
      uStack_58 = 0x865ef0;
      iStack_4c = uVar5;
      (**(code **)(*piStack_54 + 0xd0))();
      uVar5 = *(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4);
      piVar6 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      uStack_58 = 0x18;
      uVar9 = 0;
      uVar8 = 0;
      (**(code **)(*piVar6 + 400))(piVar6,0,uVar5,0);
      (**(code **)(**(int **)(iVar3 + 0x1c) + 0x104))(*(int **)(iVar3 + 0x1c),&uStack_58,0);
      FUN_00401740(s_CTextureNumberRenderer_DrawPrimi_00a13368,0x2e);
      FUN_00797530(&uStack_58);
      if ((int *)0xf < piStack_40) {
        _free(piStack_54);
        return;
      }
      uVar7 = 0;
      if (uVar8 != 0) {
        do {
          (**(code **)(**(int **)(iVar3 + 0x1c) + 0x108))(*(int **)(iVar3 + 0x1c),uVar7);
          piVar6 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
          (**(code **)(*piVar6 + 0x144))(piVar6,4,uVar9,uVar5);
          (**(code **)(**(int **)(iVar3 + 0x1c) + 0x110))(*(int **)(iVar3 + 0x1c));
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar8);
      }
      (**(code **)(**(int **)(iVar3 + 0x1c) + 0x114))(*(int **)(iVar3 + 0x1c));
      FUN_00858870();
    }
  }
  return;
}


// ==== FUN_00865fe0 @ 0x00865fe0 ====

void FUN_00865fe0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00865fe0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00866020 @ 0x00866020 ====

void * FUN_00866020(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a250;
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


// ==== Catch@00866095 @ 0x00866095 ====

void Catch_00866095(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008660b0 @ 0x008660b0 ====

void FUN_008660b0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a260;
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


// ==== Catch@0086613a @ 0x0086613a ====

void Catch_0086613a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00866150 @ 0x00866150 ====

void FUN_00866150(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00866020(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00866255:
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
      if ((char)piVar6[5] == '\0') goto LAB_00866255;
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


// ==== FUN_00866330 @ 0x00866330 ====

void FUN_00866330(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00865fe0(piVar6[1]);
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


// ==== FUN_008663f0 @ 0x008663f0 ====

void FUN_008663f0(undefined4 *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  char cVar3;
  undefined4 uVar4;
  bool bVar5;
  bool bVar6;
  undefined4 *puVar7;
  float *pfVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int in_ECX;
  bool bVar11;
  
  pfVar8 = param_2;
  puVar10 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  bVar5 = true;
  bVar11 = true;
  cVar3 = *(char *)((int)puVar10 + 0x15);
  puVar7 = *(undefined4 **)(in_ECX + 4);
  while (cVar3 == '\0') {
    fVar2 = *param_2;
    pfVar1 = (float *)(puVar10 + 3);
    bVar5 = fVar2 == *pfVar1;
    bVar6 = fVar2 < *pfVar1;
    if (bVar6 || bVar5) {
      puVar9 = (undefined4 *)puVar10[2];
    }
    else {
      puVar9 = (undefined4 *)*puVar10;
    }
    bVar11 = !bVar6 && !bVar5;
    bVar5 = (!NAN(fVar2) && !NAN(*pfVar1)) && (!bVar6 && !bVar5);
    puVar7 = puVar10;
    puVar10 = puVar9;
    cVar3 = *(char *)((int)puVar9 + 0x15);
  }
  param_2 = (float *)puVar7;
  if (bVar5) {
    if (puVar7 == (undefined4 *)**(int **)(in_ECX + 4)) {
      bVar11 = true;
      goto LAB_00866470;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *pfVar8 || param_2[3] == *pfVar8) {
    *(undefined1 *)(param_1 + 1) = 0;
    *param_1 = param_2;
    return;
  }
LAB_00866470:
  puVar10 = (undefined4 *)FUN_00866150(&param_2,bVar11,puVar7,pfVar8);
  uVar4 = *puVar10;
  *(undefined1 *)(param_1 + 1) = 1;
  *param_1 = uVar4;
  return;
}


// ==== FUN_008664a0 @ 0x008664a0 ====

void FUN_008664a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00865a50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008664c0 @ 0x008664c0 ====

void FUN_008664c0(void)

{
  return;
}


// ==== FUN_008664d0 @ 0x008664d0 ====

void FUN_008664d0(void)

{
  return;
}


// ==== FUN_00866500 @ 0x00866500 ====

void FUN_00866500(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (param_1 == 0) {
    if (((*(int *)(iVar1 + 0x114) == 2) && (*(int *)(iVar1 + 0x118) == 5)) &&
       (*(int *)(iVar1 + 0x11c) == 2)) {
      return;
    }
    if (*(int *)(iVar1 + 100) != 0) {
      return;
    }
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,2);
    *(undefined4 *)(iVar1 + 0x11c) = 2;
  }
  else {
    if (((*(int *)(iVar1 + 0x114) == 2) && (*(int *)(iVar1 + 0x118) == 5)) &&
       (*(int *)(iVar1 + 0x11c) == 6)) {
      return;
    }
    if (*(int *)(iVar1 + 100) != 0) {
      return;
    }
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
    *(undefined4 *)(iVar1 + 0x11c) = 6;
  }
  *(undefined4 *)(iVar1 + 0x114) = 2;
  *(undefined4 *)(iVar1 + 0x118) = 5;
  return;
}


// ==== FUN_00866680 @ 0x00866680 ====

undefined4 FUN_00866680(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar3 = (*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14)) / 0x24;
  }
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  iVar3 = iVar3 * 0x24;
  cVar2 = FUN_00881000(0x24,iVar3);
  if (cVar2 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  cVar2 = FUN_00881000(0x24,iVar3);
  if (cVar2 == '\0') {
    return 0;
  }
  uVar4 = (**(code **)(*piVar1 + 0x1c))(0x24,iVar3);
  (**(code **)(*piVar1 + 0x14))(iVar3,*(undefined4 *)(param_1 + 0x14));
  FUN_00881060();
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x24)
  ;
  return uVar4;
}


// ==== FUN_00866730 @ 0x00866730 ====

undefined4 FUN_00866730(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 1;
  }
  iVar2 = iVar2 * 2;
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar2)) {
    (**(code **)(*piVar1 + 0x10))();
  }
  if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar2)) {
    return 0;
  }
  uVar3 = (**(code **)(*piVar1 + 0x20))(iVar2);
  iVar2 = *(int *)(param_1 + 0x24);
  if (iVar2 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x28) - iVar2 >> 1;
  }
  (**(code **)(*piVar1 + 0x18))(iVar4,iVar2);
  FUN_00881080();
  return uVar3;
}


// ==== FUN_008667f0 @ 0x008667f0 ====

void FUN_008667f0(undefined4 param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int unaff_EBP;
  int iVar3;
  uint unaff_EDI;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = FUN_00866680(param_2);
  local_c = FUN_00866730(param_2);
  if ((*(int *)(param_2 + 0x24) != 0) &&
     (2 < (uint)(*(int *)(param_2 + 0x28) - *(int *)(param_2 + 0x24) >> 1))) {
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0);
    FUN_0084b7f0(*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 0x18));
    uVar6 = 0;
    puVar5 = &local_c;
    (**(code **)(**(int **)(unaff_EBP + 0x1c) + 0x104))(*(int **)(unaff_EBP + 0x1c),puVar5,0);
    if (unaff_EDI != 0) {
      uVar4 = 0;
      do {
        (**(code **)(*piRam00000040 + 0x108))(piRam00000040);
        if (*(int *)(param_2 + 0x24) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = *(int *)(param_2 + 0x28) - *(int *)(param_2 + 0x24) >> 1;
        }
        if (*(int *)(param_2 + 0x14) == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = (*(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14)) / 0x24;
        }
        piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
        (**(code **)(*piVar1 + 0x148))(piVar1,4,uVar6,0,iVar3,puVar5,uVar2 / 3);
        (**(code **)(**(int **)(uVar4 + 0x1c) + 0x110))(*(int **)(uVar4 + 0x1c));
        uVar4 = uVar4 + 1;
      } while (uVar4 < unaff_EDI);
    }
    (**(code **)(*piRam00000040 + 0x114))(piRam00000040);
  }
  return;
}


// ==== FUN_00866950 @ 0x00866950 ====

void FUN_00866950(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined4 uStack_18;
  int iStack_10;
  uint uStack_c;
  undefined1 local_8 [4];
  int iStack_4;
  
  piVar3 = (int *)FUN_00850950();
  puVar10 = local_8;
  (**(code **)(*piVar3 + 8))(puVar10,param_2);
  piVar3 = *(int **)(param_2 + 100);
  iVar5 = 0;
  if ((piVar3 == (int *)0x0) || (*(int *)(param_2 + 0x68) - (int)piVar3 >> 2 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_004bb6a0();
  }
  puVar6 = (undefined1 *)*piVar3;
  iVar1 = *(int *)(puVar6 + 0x68);
  iVar8 = 0;
  (**(code **)(**(int **)(iStack_4 + 0x1c) + 0x104))(*(int **)(iStack_4 + 0x1c),local_8 + -0x18,0);
  uStack_c = 0;
  if (unaff_EBP != 0) {
    do {
      (**(code **)(**(int **)(iStack_10 + 0x1c) + 0x108))(*(int **)(iStack_10 + 0x1c),uStack_c);
      uVar9 = *(uint *)(puVar6 + 0x30);
      uVar7 = *(uint *)(puVar6 + 0x2c);
      if (uVar7 != uVar9) {
        piVar3 = (int *)(uVar7 + 0x18);
        puVar6 = puVar10;
        do {
          piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
          (**(code **)(*piVar2 + 0x148))
                    (piVar2,piVar3[-5],iVar1 + iStack_10,piVar3[-4],piVar3[-3],iVar8 + iVar5,
                     piVar3[-2]);
          if (*piVar3 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = piVar3[1] - *piVar3 >> 1;
          }
          uVar7 = uVar7 + 0x24;
          iVar5 = iVar5 + iVar4;
          piVar3 = piVar3 + 9;
        } while (uVar7 != uVar9);
        puVar10 = puVar6;
      }
      (**(code **)(**(int **)(uStack_18 + 0x1c) + 0x110))(*(int **)(uStack_18 + 0x1c));
      uStack_c = uStack_c + 1;
    } while (uStack_c < uVar9);
  }
  (**(code **)(**(int **)(iStack_10 + 0x1c) + 0x114))(*(int **)(iStack_10 + 0x1c));
  return;
}


// ==== FUN_00866aa0 @ 0x00866aa0 ====

void FUN_00866aa0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uStack_68;
  int *piStack_64;
  undefined4 uStack_60;
  undefined4 *puStack_5c;
  undefined4 local_40 [16];
  
  puVar3 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
  puVar4 = local_40;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar2 = *(int *)(param_1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar2 >> 2) < 0x5d)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_60 = *(undefined4 *)(iVar2 + 0x170);
  piStack_64 = *(int **)(param_1 + 0x1c);
  puStack_5c = local_40;
  uStack_68 = 0x866af9;
  (**(code **)(*piStack_64 + 0x98))();
  iVar2 = *(int *)(param_1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar2 >> 2) < 0x5f)) {
                    /* WARNING: Subroutine does not return */
    uStack_68 = 0x866b2d;
    FUN_0085b340();
  }
  uStack_68 = 2;
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar2 + 0x178),local_40 + -6);
  uVar1 = FUN_00862b50(&uStack_68);
  iVar2 = *(int *)(param_1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar2 >> 2) < 0x60)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar2 + 0x17c),uVar1,3);
  return;
}


// ==== FUN_00866d10 @ 0x00866d10 ====

void FUN_00866d10(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  undefined4 *apuStack_60 [2];
  undefined4 local_4c;
  undefined4 local_48;
  
  local_4c = *(undefined4 *)(DAT_00b5ac04 + 0x9c);
  iVar1 = *(int *)(param_1 + 0x28);
  local_48 = *(undefined4 *)(DAT_00b5ac04 + 0xa0);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x69)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  apuStack_60[1] = (undefined4 *)0x2;
  apuStack_60[0] = &local_4c;
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x1a0));
  uVar2 = FUN_00862b50(apuStack_60 + 1);
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x6a)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x1a4),uVar2,3);
  iVar1 = *(int *)(param_1 + 0x28);
  puVar4 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
  ppuVar5 = apuStack_60;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar5 = (undefined4 *)*puVar4;
    puVar4 = puVar4 + 1;
    ppuVar5 = ppuVar5 + 1;
  }
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x65)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x98))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 400),apuStack_60);
  return;
}


// ==== FUN_00866e10 @ 0x00866e10 ====

void FUN_00866e10(void)

{
  char cVar1;
  int *piVar2;
  float *pfVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  float *pfVar9;
  int in_ECX;
  int iVar10;
  undefined4 *puVar11;
  float *pfVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  float *pfVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  undefined1 uStack_1b8;
  undefined4 uStack_1ac;
  undefined1 auStack_1a0 [12];
  undefined4 uStack_194;
  float afStack_190 [15];
  undefined1 auStack_154 [12];
  undefined1 auStack_148 [52];
  undefined1 auStack_114 [12];
  undefined4 auStack_108 [16];
  undefined4 auStack_c8 [12];
  undefined4 auStack_98 [16];
  undefined1 auStack_58 [16];
  undefined1 auStack_48 [68];
  
  if ((*(int *)(in_ECX + 0x18) != 0) || (*(int *)(in_ECX + 0xc) != 0)) {
    if (*(int *)(in_ECX + 0xc) != 0) {
      FUN_00859300();
      iVar5 = FUN_0085e3a0(9);
      piVar8 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar8 + 0x15c))(piVar8,*(undefined4 *)(iVar5 + 0x20));
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0xf0))(*(int **)(iVar5 + 0x1c),s_Tracer_00a1352c);
      FUN_00866aa0(iVar5);
      piVar8 = *(int **)(in_ECX + 8);
      piVar2 = (int *)*piVar8;
      while (piVar2 != piVar8) {
        iVar10 = piVar2[3];
        iVar6 = FUN_0085e3a0(9);
        uStack_1ac = 0;
        if (iVar10 != 0) {
          piVar7 = (int *)FUN_004af750();
          uStack_1ac = (**(code **)(*piVar7 + 4))();
        }
        iVar10 = *(int *)(iVar6 + 0x28);
        if ((iVar10 == 0) || ((uint)(*(int *)(iVar6 + 0x2c) - iVar10 >> 2) < 0x5e))
        goto LAB_00867289;
        (**(code **)(**(int **)(iVar6 + 0x1c) + 0xd0))
                  (*(int **)(iVar6 + 0x1c),*(undefined4 *)(iVar10 + 0x174),uStack_1ac);
        FUN_00866500(piVar2[0x10]);
        FUN_008667f0(iVar5,piVar2 + 4);
        FUN_00503890();
      }
      FUN_00859430();
    }
    if (*(int *)(in_ECX + 0x18) != 0) {
      FUN_00859300();
      piVar8 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
      iVar5 = (**(code **)(*piVar8 + 0x1c))();
      if (*(int *)(iVar5 + 8) == 0) {
        uVar17 = 0x15;
      }
      else {
        uVar17 = 0xc;
      }
      uVar17 = FUN_0085e3a0(uVar17);
      *(undefined4 *)(in_ECX + 0x24) = uVar17;
      piVar8 = (int *)FUN_00850950();
      (**(code **)(*piVar8 + 4))();
      piVar8 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar8 + 0x15c))(piVar8,*(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x20));
      piVar8 = *(int **)(*(int *)(in_ECX + 0x24) + 0x1c);
      (**(code **)(*piVar8 + 0xf0))(piVar8,s_TracerMesh_00a13534);
      FUN_00866d10(*(undefined4 *)(in_ECX + 0x24));
      puVar11 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 8);
      puVar14 = auStack_98;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar14 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar14 = puVar14 + 1;
      }
      thunk_FUN_0079f3a1(auStack_58,0,auStack_98);
      FUN_0087aa50(auStack_48);
      puVar11 = *(undefined4 **)(in_ECX + 0x14);
      puVar14 = (undefined4 *)*puVar11;
      while (puVar14 != puVar11) {
        iVar5 = *(int *)(in_ECX + 0x24);
        uVar17 = 0;
        if (puVar14[3] != 0) {
          piVar8 = (int *)FUN_004af750();
          uVar17 = (**(code **)(*piVar8 + 4))();
        }
        iVar10 = *(int *)(iVar5 + 0x28);
        if ((iVar10 == 0) || ((uint)(*(int *)(iVar5 + 0x2c) - iVar10 >> 2) < 0x66)) {
LAB_00867289:
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        (**(code **)(**(int **)(iVar5 + 0x1c) + 0xd0))
                  (*(int **)(iVar5 + 0x1c),*(undefined4 *)(iVar10 + 0x194),uVar17);
        iVar5 = *(int *)(DAT_00b5ac04 + 0x28);
        if (*(char *)(puVar14 + 7) == '\0') {
          if (*(char *)(iVar5 + 0x7e) == '\0') {
            uVar17 = 2;
            goto LAB_008670e0;
          }
          (**(code **)(**(int **)(iVar5 + 0x90) + 0xe4))(*(int **)(iVar5 + 0x90),0x16,3);
        }
        else {
          uVar17 = 1;
LAB_008670e0:
          (**(code **)(**(int **)(iVar5 + 0x90) + 0xe4))(*(int **)(iVar5 + 0x90),0x16,uVar17);
        }
        *(undefined1 *)(iVar5 + 0x74) = uStack_1b8;
        pfVar3 = (float *)puVar14[0xb];
        for (pfVar9 = (float *)puVar14[10]; pfVar9 != pfVar3; pfVar9 = pfVar9 + 0x12) {
          pfVar12 = pfVar9;
          pfVar15 = afStack_190;
          for (iVar5 = 0x12; iVar5 != 0; iVar5 = iVar5 + -1) {
            *pfVar15 = *pfVar12;
            pfVar12 = pfVar12 + 1;
            pfVar15 = pfVar15 + 1;
          }
          fVar4 = afStack_190[0] * (float)puVar14[6];
          thunk_FUN_0079f761(auStack_148,fVar4,fVar4,fVar4);
          FUN_0040ec60(auStack_1a0,puVar14[8]);
          iVar5 = *(int *)(in_ECX + 0x24);
          uStack_194 = afStack_190[1];
          iVar10 = *(int *)(iVar5 + 0x28);
          if ((iVar10 == 0) || ((uint)(*(int *)(iVar5 + 0x2c) - iVar10 >> 2) < 0x68))
          goto LAB_00867289;
          (**(code **)(**(int **)(iVar5 + 0x1c) + 0x88))
                    (*(int **)(iVar5 + 0x1c),*(undefined4 *)(iVar10 + 0x19c),auStack_1a0);
          thunk_FUN_0079ee7b(auStack_114,auStack_154,&uStack_194);
          iVar5 = *(int *)(in_ECX + 0x24);
          puVar13 = auStack_108;
          puVar16 = auStack_c8;
          for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar16 = *puVar13;
            puVar13 = puVar13 + 1;
            puVar16 = puVar16 + 1;
          }
          iVar10 = *(int *)(iVar5 + 0x28);
          if ((iVar10 == 0) || ((uint)(*(int *)(iVar5 + 0x2c) - iVar10 >> 2) < 0x67))
          goto LAB_00867289;
          (**(code **)(**(int **)(iVar5 + 0x1c) + 0x98))
                    (*(int **)(iVar5 + 0x1c),*(undefined4 *)(iVar10 + 0x198),auStack_c8);
          FUN_00866950(*(undefined4 *)(in_ECX + 0x24),puVar14[5]);
        }
        if (*(char *)((int)puVar14 + 0x35) == '\0') {
          puVar13 = (undefined4 *)puVar14[2];
          if (*(char *)((int)puVar13 + 0x35) == '\0') {
            cVar1 = *(char *)((int)*puVar13 + 0x35);
            puVar14 = puVar13;
            puVar13 = (undefined4 *)*puVar13;
            while (cVar1 == '\0') {
              cVar1 = *(char *)((int)*puVar13 + 0x35);
              puVar14 = puVar13;
              puVar13 = (undefined4 *)*puVar13;
            }
          }
          else {
            cVar1 = *(char *)((int)puVar14[1] + 0x35);
            puVar16 = (undefined4 *)puVar14[1];
            puVar13 = puVar14;
            while ((puVar14 = puVar16, cVar1 == '\0' && (puVar13 == (undefined4 *)puVar14[2]))) {
              cVar1 = *(char *)((int)puVar14[1] + 0x35);
              puVar16 = (undefined4 *)puVar14[1];
              puVar13 = puVar14;
            }
          }
        }
      }
      FUN_00859430();
    }
  }
  return;
}


// ==== FUN_00867290 @ 0x00867290 ====

void FUN_00867290(undefined4 *param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,float param_7,float param_8,float param_9,float param_10,
                 float param_11,undefined4 param_12,undefined4 param_13)

{
  int iVar1;
  undefined2 *puVar2;
  int in_ECX;
  int iVar3;
  undefined2 *puVar4;
  undefined2 local_30 [6];
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  local_8 = *(float *)(in_ECX + 0x20);
  local_18 = *param_1;
  local_14 = param_1[1];
  local_10 = param_1[2];
  local_c = param_1[3];
  local_30[2] = 2;
  local_30[3] = 2;
  local_20 = param_3;
  local_1c = param_4;
  local_24 = param_2;
  local_4 = 0;
  local_30[0] = 0;
  local_30[1] = 1;
  local_30[4] = 1;
  local_30[5] = 3;
  FUN_00869310(&local_24);
  local_8 = *(float *)(in_ECX + 0x20);
  local_20 = param_6;
  local_1c = param_7;
  local_24 = param_5;
  local_4 = DAT_0099d080;
  FUN_00869310(&local_24);
  local_20 = param_9;
  local_1c = param_10;
  local_24 = param_8;
  local_4 = 0;
  local_8 = SQRT((param_8 - param_2) * (param_8 - param_2) +
                 (param_9 - param_3) * (param_9 - param_3) +
                 (param_10 - param_4) * (param_10 - param_4)) /
            SQRT((param_5 - param_2) * (param_5 - param_2) +
                 (param_6 - param_3) * (param_6 - param_3) +
                 (param_7 - param_4) * (param_7 - param_4)) + *(float *)(in_ECX + 0x20);
  *(float *)(in_ECX + 0x20) = local_8;
  FUN_00869310(&local_24);
  local_8 = *(float *)(in_ECX + 0x20);
  local_20 = (float)param_12;
  local_1c = (float)param_13;
  local_24 = param_11;
  local_4 = DAT_0099d080;
  FUN_00869310(&local_24);
  puVar4 = local_30;
  iVar3 = 6;
  do {
    iVar1 = param_1[9];
    if ((iVar1 == 0) || ((uint)(param_1[0xb] - iVar1 >> 1) <= (uint)(param_1[10] - iVar1 >> 1))) {
      FUN_00427290(param_1[10],1,puVar4);
    }
    else {
      puVar2 = (undefined2 *)param_1[10];
      *puVar2 = *puVar4;
      param_1[10] = puVar2 + 1;
    }
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


// ==== FUN_00867510 @ 0x00867510 ====

void FUN_00867510(undefined4 *param_1,undefined4 param_2,float *param_3,int param_4,
                 undefined4 param_5,float param_6,float param_7)

{
  int iVar1;
  undefined2 *puVar2;
  short *psVar3;
  uint uVar4;
  uint in_ECX;
  uint uVar5;
  float *pfVar6;
  uint uVar7;
  short sVar8;
  undefined2 uVar9;
  float fVar10;
  float local_74;
  float local_6c;
  float local_68;
  float fStack_64;
  undefined4 uStack_60;
  float fStack_5c;
  undefined4 uStack_58;
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
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float fStack_8;
  undefined4 uStack_4;
  
  local_18 = *param_1;
  local_14 = param_1[1];
  local_10 = param_1[2];
  local_c = param_1[3];
  if ((param_3 == (float *)0x0) || (uVar4 = (param_4 - (int)param_3) / 0xc, uVar4 < 2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0042f370();
  }
  if (uVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0042f370();
  }
  local_74 = 0.0;
  uVar5 = 0;
  pfVar6 = param_3 + -4;
  local_68 = SQRT((param_3[4] - param_3[1]) * (param_3[4] - param_3[1]) +
                  (param_3[5] - param_3[2]) * (param_3[5] - param_3[2]) +
                  (param_3[3] - *param_3) * (param_3[3] - *param_3));
  while( true ) {
    if (uVar4 <= uVar5) {
      uVar7 = 0;
      local_68 = (float)((uVar4 >> 1) - 1);
      *(undefined4 *)(in_ECX + 0x1c) = 0;
      while (uVar7 < (uint)local_68) {
        local_6c = (float)CONCAT22((short)(uVar5 >> 0x10),*(undefined2 *)(in_ECX + 0x1c));
        iVar1 = param_1[9];
        if ((iVar1 == 0) || ((uint)(param_1[0xb] - iVar1 >> 1) <= (uint)(param_1[10] - iVar1 >> 1)))
        {
          FUN_00427290(param_1[10],1,&local_6c);
        }
        else {
          puVar2 = (undefined2 *)param_1[10];
          *puVar2 = *(undefined2 *)(in_ECX + 0x1c);
          param_1[10] = puVar2 + 1;
        }
        uVar9 = (undefined2)(in_ECX >> 0x10);
        iVar1 = param_1[9];
        sVar8 = *(short *)(in_ECX + 0x1c) + 2;
        local_6c = (float)CONCAT22(uVar9,sVar8);
        if ((iVar1 == 0) || ((uint)(param_1[0xb] - iVar1 >> 1) <= (uint)(param_1[10] - iVar1 >> 1)))
        {
          FUN_00427290(param_1[10],1,&local_6c);
        }
        else {
          psVar3 = (short *)param_1[10];
          *psVar3 = sVar8;
          param_1[10] = psVar3 + 1;
        }
        iVar1 = param_1[9];
        sVar8 = *(short *)(in_ECX + 0x1c) + 1;
        local_6c = (float)CONCAT22(uVar9,sVar8);
        if ((iVar1 == 0) || ((uint)(param_1[0xb] - iVar1 >> 1) <= (uint)(param_1[10] - iVar1 >> 1)))
        {
          FUN_00427290(param_1[10],1,&local_6c);
        }
        else {
          psVar3 = (short *)param_1[10];
          *psVar3 = sVar8;
          param_1[10] = psVar3 + 1;
        }
        iVar1 = param_1[9];
        sVar8 = *(short *)(in_ECX + 0x1c) + 1;
        local_6c = (float)CONCAT22(uVar9,sVar8);
        if ((iVar1 == 0) || ((uint)(param_1[0xb] - iVar1 >> 1) <= (uint)(param_1[10] - iVar1 >> 1)))
        {
          FUN_00427290(param_1[10],1,&local_6c);
        }
        else {
          psVar3 = (short *)param_1[10];
          *psVar3 = sVar8;
          param_1[10] = psVar3 + 1;
        }
        iVar1 = param_1[9];
        sVar8 = *(short *)(in_ECX + 0x1c) + 2;
        local_6c = (float)CONCAT22(uVar9,sVar8);
        if ((iVar1 == 0) || ((uint)(param_1[0xb] - iVar1 >> 1) <= (uint)(param_1[10] - iVar1 >> 1)))
        {
          FUN_00427290(param_1[10],1,&local_6c);
        }
        else {
          psVar3 = (short *)param_1[10];
          *psVar3 = sVar8;
          param_1[10] = psVar3 + 1;
        }
        iVar1 = param_1[9];
        sVar8 = *(short *)(in_ECX + 0x1c) + 3;
        local_6c = (float)CONCAT22(uVar9,sVar8);
        uVar5 = in_ECX;
        if ((iVar1 == 0) || ((uint)(param_1[0xb] - iVar1 >> 1) <= (uint)(param_1[10] - iVar1 >> 1)))
        {
          FUN_00427290(param_1[10],1,&local_6c);
          *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 2;
          uVar7 = uVar7 + 1;
        }
        else {
          psVar3 = (short *)param_1[10];
          *psVar3 = sVar8;
          param_1[10] = psVar3 + 1;
          *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 2;
          uVar7 = uVar7 + 1;
        }
      }
      _free(param_3);
      return;
    }
    local_54 = pfVar6[4];
    local_50 = pfVar6[5];
    local_4c = pfVar6[6];
    if (uVar4 <= uVar5 + 1) break;
    local_48 = pfVar6[7];
    local_44 = pfVar6[8];
    local_40 = pfVar6[9];
    if (uVar5 != 0) {
      if (uVar4 <= uVar5 - 2) {
                    /* WARNING: Subroutine does not return */
        FUN_0042f370();
      }
      local_6c = SQRT((local_50 - pfVar6[-1]) * (local_50 - pfVar6[-1]) +
                      (local_4c - *pfVar6) * (local_4c - *pfVar6) +
                      (local_54 - pfVar6[-2]) * (local_54 - pfVar6[-2])) / local_68;
      fVar10 = local_6c;
      if (DAT_0099d0f8 <= local_6c) {
        fVar10 = DAT_0099d0f8;
      }
      local_74 = fVar10 + local_74;
    }
    local_3c = local_54 - local_48;
    local_38 = local_50 - local_44;
    local_34 = local_4c - local_40;
    thunk_FUN_0079e1ba(&local_30,&local_3c);
    fVar10 = local_68 * param_7 + param_6 + DAT_0099d0b4;
    local_54 = local_30 * fVar10 + local_54;
    local_50 = fStack_2c * fVar10 + local_50;
    local_4c = fStack_28 * fVar10 + local_4c;
    fVar10 = param_6 - DAT_009c16c0;
    local_48 = local_30 * fVar10 + local_48;
    local_44 = fStack_2c * fVar10 + local_44;
    local_40 = fStack_28 * fVar10 + local_40;
    fStack_64 = local_74;
    uStack_60 = 0;
    fStack_8 = local_74;
    uStack_4 = 0;
    fStack_24 = local_54;
    fStack_20 = local_50;
    fStack_1c = local_4c;
    FUN_00869310(&fStack_24);
    fStack_5c = local_74;
    fStack_24 = local_48;
    fStack_20 = local_44;
    fStack_1c = local_40;
    uStack_58 = DAT_0099d080;
    fStack_8 = local_74;
    uStack_4 = DAT_0099d080;
    FUN_00869310(&fStack_24);
    uVar5 = uVar5 + 2;
    pfVar6 = pfVar6 + 6;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0042f370();
}


// ==== FUN_00867a70 @ 0x00867a70 ====

void FUN_00867a70(void)

{
  int in_ECX;
  
  FUN_00869ab0(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
  *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  FUN_00869b20(*(undefined4 *)(*(int *)(in_ECX + 0x14) + 4));
  *(int *)(*(int *)(in_ECX + 0x14) + 4) = *(int *)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x14);
  *(int *)(*(int *)(in_ECX + 0x14) + 8) = *(int *)(in_ECX + 0x14);
  return;
}


// ==== FUN_00867ad0 @ 0x00867ad0 ====

void FUN_00867ad0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a13558;
  FUN_00867a70();
  FUN_00869d60(local_4,*(undefined4 *)in_ECX[5],(undefined4 *)in_ECX[5]);
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_00867b40 @ 0x00867b40 ====

void FUN_00867b40(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  short sVar6;
  int extraout_EDX;
  int iVar7;
  int extraout_EDX_00;
  int extraout_EDX_01;
  uint uVar8;
  void *pvVar9;
  ushort local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  undefined4 local_70;
  int local_6c;
  int local_68;
  int local_64;
  undefined4 local_60;
  void *local_58;
  int local_54;
  undefined4 local_50;
  void *local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  void *local_20;
  void *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_3c = param_1[0xe];
  local_78 = DAT_0099d080;
  local_68 = DAT_0099d080;
  local_7c = DAT_0099d080;
  local_6c = DAT_0099d080;
  local_74 = DAT_0099d080;
  local_70 = param_1[0xd];
  local_64 = DAT_0099d080;
  local_58 = (void *)0x0;
  local_54 = 0;
  local_50 = 0;
  local_48 = (void *)0x0;
  local_44 = 0;
  local_40 = 0;
  local_60 = local_70;
  FUN_00867290(&local_6c,*param_1,param_1[1],param_1[2],param_1[3],param_1[4],param_1[5],param_1[6],
               param_1[7],param_1[8],param_1[9],param_1[10],param_1[0xb],param_2);
  FUN_00557be0(&local_80,param_1 + 0xc);
  iVar1 = local_54;
  if (local_80 == *(int *)(in_ECX + 8)) {
    uVar4 = FUN_00869a50(param_1 + 0xc,&local_6c);
    FUN_0086a270(&local_7c,uVar4);
    if (local_10 != (void *)0x0) {
      _free(local_10);
      return;
    }
    local_10 = (void *)0x0;
    local_c = 0;
    local_8 = 0;
    if (local_20 != (void *)0x0) {
      _free(local_20);
      return;
    }
LAB_00867cab:
    if (local_48 != (void *)0x0) {
      _free(local_48);
      return;
    }
  }
  else {
    if (*(int *)(local_80 + 0x24) == 0) {
      local_84 = 0;
      iVar7 = extraout_EDX;
    }
    else {
      iVar5 = *(int *)(local_80 + 0x28) - *(int *)(local_80 + 0x24);
      iVar7 = iVar5 / 0x24 + (iVar5 >> 0x1f);
      local_84 = (short)iVar7 - (short)(iVar5 >> 0x1f);
      if (40000 < local_84) {
        FUN_00868a70();
        return;
      }
    }
    pvVar9 = local_58;
    for (uVar8 = 0;
        (iVar5 = local_44, local_58 != (void *)0x0 &&
        (iVar3 = iVar1 - (int)local_58 >> 0x1f, iVar7 = (iVar1 - (int)local_58) / 0x24 + iVar3,
        uVar8 < (uint)(iVar7 - iVar3))); uVar8 = uVar8 + 1) {
      FUN_00869310(pvVar9);
      pvVar9 = (void *)((int)pvVar9 + 0x24);
      iVar7 = extraout_EDX_00;
    }
    uVar8 = 0;
    while (local_48 != (void *)0x0) {
      if ((uint)(iVar5 - (int)local_48 >> 1) <= uVar8) goto LAB_00867cab;
      sVar6 = *(short *)((int)local_48 + uVar8 * 2) + local_84;
      iVar7 = CONCAT22((short)((uint)iVar7 >> 0x10),sVar6);
      iVar1 = *(int *)(local_80 + 0x34);
      local_7c = iVar7;
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(local_80 + 0x3c) - iVar1 >> 1) <=
          (uint)(*(int *)(local_80 + 0x38) - iVar1 >> 1))) {
        FUN_00427290(*(undefined4 *)(local_80 + 0x38),1,&local_7c);
        uVar8 = uVar8 + 1;
        iVar7 = extraout_EDX_01;
      }
      else {
        psVar2 = *(short **)(local_80 + 0x38);
        *psVar2 = sVar6;
        *(short **)(local_80 + 0x38) = psVar2 + 1;
        uVar8 = uVar8 + 1;
      }
    }
  }
  if (local_58 == (void *)0x0) {
    return;
  }
  _free(local_58);
  return;
}


// ==== FUN_00867df0 @ 0x00867df0 ====

/* WARNING: Removing unreachable block (ram,0x00867f63) */

void FUN_00867df0(int param_1,undefined4 param_2)

{
  short *psVar1;
  void *_Memory;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  short sVar5;
  int extraout_EDX;
  int iVar6;
  int extraout_EDX_00;
  uint uVar7;
  ushort uStack_a4;
  int iStack_a0;
  int iStack_9c;
  undefined4 uStack_98;
  undefined1 auStack_82 [22];
  void *local_6c;
  void *local_68;
  void *local_64;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_48;
  undefined4 local_44;
  void *local_40;
  undefined4 local_3c;
  void *pvStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  _Memory = DAT_0099d080;
  local_3c = *(undefined4 *)(param_1 + 0x20);
  local_60 = *(undefined4 *)(param_1 + 0x1c);
  local_6c = DAT_0099d080;
  local_68 = DAT_0099d080;
  iStack_a0 = *(int *)(param_1 + 0x14);
  local_64 = DAT_0099d080;
  iStack_9c = *(int *)(param_1 + 0x18);
  uStack_98 = param_2;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = (void *)0x0;
  FUN_00430d30(param_1);
  FUN_00867510(&local_6c);
  FUN_00557be0(&iStack_a0,param_1 + 0x10);
  pvVar2 = local_64;
  if (iStack_a0 == *(int *)(in_ECX + 8)) {
    uVar3 = FUN_00869a50(param_1 + 0x10,auStack_82 + -10);
    FUN_0086a270(&iStack_9c,uVar3);
    if (pvStack_30 != (void *)0x0) {
      _free(pvStack_30);
      return;
    }
    pvStack_30 = (void *)0x0;
    uStack_2c = 0;
    uStack_28 = 0;
    if (local_40 != (void *)0x0) {
      _free(local_40);
      return;
    }
LAB_00867f14:
    if (local_68 != (void *)0x0) {
      _free(local_68);
      return;
    }
  }
  else {
    if (*(int *)(iStack_a0 + 0x24) == 0) {
      uStack_a4 = 0;
      iVar6 = extraout_EDX;
    }
    else {
      iVar4 = *(int *)(iStack_a0 + 0x28) - *(int *)(iStack_a0 + 0x24);
      iVar6 = iVar4 / 0x24 + (iVar4 >> 0x1f);
      uStack_a4 = (short)iVar6 - (short)(iVar4 >> 0x1f);
      if (40000 < uStack_a4) {
        FUN_00868a70();
        return;
      }
    }
    if (_Memory != (void *)0x0) {
      iVar6 = 0;
    }
    uVar7 = 0;
    while (local_68 != (void *)0x0) {
      if ((uint)((int)pvVar2 - (int)local_68 >> 1) <= uVar7) goto LAB_00867f14;
      sVar5 = *(short *)((int)local_68 + uVar7 * 2) + uStack_a4;
      iVar6 = CONCAT22((short)((uint)iVar6 >> 0x10),sVar5);
      iVar4 = *(int *)(iStack_a0 + 0x34);
      iStack_9c = iVar6;
      if ((iVar4 == 0) ||
         ((uint)(*(int *)(iStack_a0 + 0x3c) - iVar4 >> 1) <=
          (uint)(*(int *)(iStack_a0 + 0x38) - iVar4 >> 1))) {
        FUN_00427290(*(undefined4 *)(iStack_a0 + 0x38),1,&iStack_9c);
        uVar7 = uVar7 + 1;
        iVar6 = extraout_EDX_00;
      }
      else {
        psVar1 = *(short **)(iStack_a0 + 0x38);
        *psVar1 = sVar5;
        *(short **)(iStack_a0 + 0x38) = psVar1 + 1;
        uVar7 = uVar7 + 1;
      }
    }
  }
  if (_Memory == (void *)0x0) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00868050 @ 0x00868050 ====

void FUN_00868050(uint *param_1)

{
  char cVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  uint *puVar6;
  uint **ppuVar7;
  uint *puVar8;
  uint uVar9;
  void *_Memory;
  uint *local_c8;
  uint *local_c4 [2];
  uint local_bc;
  void *local_b8;
  undefined1 local_b4;
  uint local_b0;
  undefined1 local_ac [4];
  void *local_a8;
  uint local_a4;
  undefined4 local_a0;
  int local_9c;
  uint local_98 [3];
  void *local_8c;
  undefined1 local_88;
  uint local_84;
  void *local_7c;
  uint local_50;
  uint local_4c;
  uint local_48 [17];
  
  local_b4 = (undefined1)param_1[2];
  local_bc = *param_1;
  local_b8 = (void *)param_1[4];
  local_b0 = param_1[3];
  local_a8 = (void *)0x0;
  local_a4 = 0;
  local_a0 = 0;
  local_c8 = (uint *)param_1[6];
  local_c4[0] = (uint *)param_1[7];
  local_9c = in_ECX;
  if ((uint *)param_1[6] != (uint *)param_1[7]) {
    do {
      puVar8 = local_c8;
      puVar6 = local_98;
      for (iVar5 = 0x12; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar6 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar6 = puVar6 + 1;
      }
      local_4c = local_98[1];
      local_50 = local_98[0];
      puVar8 = local_98 + 2;
      puVar6 = local_48;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar6 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar6 = puVar6 + 1;
      }
      FUN_008693a0(&local_50);
      local_c8 = local_c8 + 0x12;
    } while (local_c8 != local_c4[0]);
  }
  _Memory = local_a8;
  pvVar2 = (void *)FUN_004b3b40();
  if (pvVar2 == (void *)0x0) {
    local_a4 = 0xf;
    local_b8 = (void *)((uint)local_b8 & 0xffffff00);
    local_a8 = pvVar2;
    FUN_00401740(&DAT_00a1350c,0x1e);
    FUN_00796d50(&local_bc);
    if (0xf < local_a4) {
      _free(local_b8);
      return;
    }
LAB_00868273:
    if (_Memory != (void *)0x0) {
      _free(_Memory);
      return;
    }
  }
  else {
    uVar3 = FUN_004b3b40();
    uVar9 = 0;
    if (uVar3 != 0) {
LAB_00868177:
      uVar4 = FUN_004b3ff0(uVar9);
      _Memory = local_a8;
      if (uVar4 == 0) goto code_r0x00868184;
      puVar8 = (uint *)(*(uint **)(local_9c + 0x14))[1];
      uVar3 = *param_1;
      cVar1 = *(char *)((int)puVar8 + 0x35);
      local_c4[0] = *(uint **)(local_9c + 0x14);
      while (cVar1 == '\0') {
        if ((puVar8[3] < uVar4) || ((puVar8[3] <= uVar4 && (puVar8[4] < uVar3)))) {
          puVar6 = (uint *)puVar8[2];
          puVar8 = local_c4[0];
        }
        else {
          puVar6 = (uint *)*puVar8;
        }
        local_c4[0] = puVar8;
        puVar8 = puVar6;
        cVar1 = *(char *)((int)puVar6 + 0x35);
      }
      if (((local_c4[0] == *(uint **)(local_9c + 0x14)) || (uVar4 < local_c4[0][3])) ||
         ((uVar4 <= local_c4[0][3] && (uVar3 < local_c4[0][4])))) {
        local_c8 = *(uint **)(local_9c + 0x14);
        ppuVar7 = &local_c8;
      }
      else {
        ppuVar7 = local_c4;
      }
      local_c4[0] = *ppuVar7;
      if (local_c4[0] == *(uint **)(local_9c + 0x14)) {
        local_98[2] = local_bc;
        local_88 = local_b4;
        local_8c = local_b8;
        local_84 = local_b0;
        local_98[0] = uVar4;
        local_98[1] = uVar3;
        FUN_008691f0(local_ac);
        FUN_0086a330(local_c4,local_98);
        if (local_7c != (void *)0x0) {
          _free(local_7c);
          return;
        }
        _Memory = local_a8;
      }
      else {
        uVar3 = 0;
        pvVar2 = local_a8;
        while( true ) {
          if (_Memory == (void *)0x0) {
            return;
          }
          if ((uint)((int)(local_a4 - (int)_Memory) / 0x48) <= uVar3) break;
          FUN_008693a0(pvVar2);
          uVar3 = uVar3 + 1;
          pvVar2 = (void *)((int)pvVar2 + 0x48);
        }
      }
      goto LAB_00868273;
    }
LAB_0086818b:
    if (local_a8 != (void *)0x0) {
      _free(local_a8);
      return;
    }
  }
  return;
code_r0x00868184:
  uVar9 = uVar9 + 1;
  if (uVar3 <= uVar9) goto LAB_0086818b;
  goto LAB_00868177;
}


// ==== FUN_008682d0 @ 0x008682d0 ====

void FUN_008682d0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13558;
  iVar1 = FUN_008687b0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x45) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  iVar1 = FUN_00868850();
  in_ECX[5] = iVar1;
  *(undefined1 *)(iVar1 + 0x35) = 1;
  *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
  *(undefined4 *)in_ECX[5] = in_ECX[5];
  *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  in_ECX[6] = 0;
  in_ECX[9] = 0;
  return;
}


// ==== FUN_00868340 @ 0x00868340 ====

void FUN_00868340(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = (**(code **)(*param_1 + 0xec))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0xec))();
    iVar3 = 0;
    if (0 < iVar1) {
      iVar4 = 0;
      do {
        uVar2 = (**(code **)(*param_1 + 0xf0))(iVar3);
        FUN_00868050(uVar2,iVar4);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar3 < iVar1);
    }
  }
  iVar1 = (**(code **)(*param_1 + 0xd4))();
  if (iVar1 != 0) {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    iVar1 = (**(code **)(*param_1 + 0xd4))();
    if (0 < iVar1) {
      iVar3 = 0;
      do {
        uVar2 = (**(code **)(*param_1 + 0xd8))(iVar3);
        FUN_00867b40(uVar2,(iVar1 - iVar4) + -1);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar3 < iVar1);
    }
  }
  iVar1 = (**(code **)(*param_1 + 0xe0))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0xe0))();
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        uVar2 = (**(code **)(*param_1 + 0xe4))(iVar4);
        FUN_00867df0(uVar2,iVar4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  return;
}


// ==== FUN_00868440 @ 0x00868440 ====

int FUN_00868440(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x48;
}


// ==== FUN_00868460 @ 0x00868460 ====

void FUN_00868460(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x45) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x45) == '\0');
  }
  return;
}


// ==== FUN_00868480 @ 0x00868480 ====

void FUN_00868480(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x35) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x35) == '\0');
  }
  return;
}


// ==== FUN_008684a0 @ 0x008684a0 ====

void FUN_008684a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 9;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 9; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_008684d0 @ 0x008684d0 ====

void FUN_008684d0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 0x12;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 0x12; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_00868500 @ 0x00868500 ====

void FUN_00868500(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x45) == '\0') {
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


// ==== FUN_00868550 @ 0x00868550 ====

void FUN_00868550(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x45) == '\0') {
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


// ==== FUN_008685b0 @ 0x008685b0 ====

void FUN_008685b0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x35) == '\0') {
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


// ==== FUN_00868600 @ 0x00868600 ====

void FUN_00868600(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x35) == '\0') {
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


// ==== FUN_00868660 @ 0x00868660 ====

void FUN_00868660(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -0x12;
    param_3 = param_3 + -0x12;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_00868690 @ 0x00868690 ====

void FUN_00868690(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_008686b0 @ 0x008686b0 ====

void FUN_008686b0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_008686d0 @ 0x008686d0 ====

int FUN_008686d0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a2c0;
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


// ==== Catch@00868736 @ 0x00868736 ====

void Catch_00868736(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00868740 @ 0x00868740 ====

int FUN_00868740(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a270;
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


// ==== Catch@008687a6 @ 0x008687a6 ====

void Catch_008687a6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008687b0 @ 0x008687b0 ====

void FUN_008687b0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a280;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x48);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x11) = 1;
  *(undefined1 *)((int)puVar1 + 0x45) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0086883a @ 0x0086883a ====

void Catch_0086883a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00868850 @ 0x00868850 ====

void FUN_00868850(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a290;
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


// ==== Catch@008688da @ 0x008688da ====

void Catch_008688da(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_008688f0 @ 0x008688f0 ====

void FUN_008688f0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a2a0;
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


// ==== Catch@00868956 @ 0x00868956 ====

void Catch_00868956(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00868960 @ 0x00868960 ====

void FUN_00868960(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a2b0;
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


// ==== Catch@008689c6 @ 0x008689c6 ====

void Catch_008689c6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008689d0 @ 0x008689d0 ====

void FUN_008689d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00868740(param_1,param_2,param_3);
  return;
}


// ==== FUN_008689f0 @ 0x008689f0 ====

int FUN_008689f0(int param_1,int param_2,undefined4 param_3)

{
  FUN_008688f0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_00868a20 @ 0x00868a20 ====

int FUN_00868a20(int param_1,int param_2,undefined4 param_3)

{
  FUN_00868960(param_1,param_2,param_3);
  return param_1 + param_2 * 0x48;
}


// ==== FUN_00868a50 @ 0x00868a50 ====

void FUN_00868a50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_008686d0(param_1,param_2,param_3);
  return;
}


// ==== FUN_00868a70 @ 0x00868a70 ====

void FUN_00868a70(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x24) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  if (*(void **)(in_ECX + 0x14) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_00868ab0 @ 0x00868ab0 ====

undefined4 FUN_00868ab0(uint param_1)

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
    param_1 = FUN_0085b3b0();
  }
  pvVar1 = operator_new(param_1 * 0x48);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x48 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00868b00 @ 0x00868b00 ====

void FUN_00868b00(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a2d0;
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
      local_1c = FUN_00868a50(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_008689f0(local_1c,param_2,&local_58);
      FUN_00868a50(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
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
      FUN_008686d0(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_008689f0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,&local_58)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_008684a0(param_1,*(int *)(in_ECX + 8) - local_24,&local_58);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x24;
    uVar2 = FUN_008686d0(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    FUN_004ab860(param_1,local_2c,local_28);
    FUN_008684a0(param_1,param_2 * 0x24 + param_1,&local_58);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00868ca6 @ 0x00868ca6 ====

void Catch_00868ca6(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00868db0 @ 0x00868db0 ====

void FUN_00868db0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a2e0;
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
      local_1c = FUN_008689d0(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_00868a20(local_1c,param_2,&local_7c);
      FUN_008689d0(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
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
      FUN_00868740(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_00868a20(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x48,&local_7c)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_008684d0(param_1,*(int *)(in_ECX + 8) - local_24,&local_7c);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x48;
    uVar2 = FUN_00868740(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    FUN_00868660(param_1,local_2c,local_28);
    FUN_008684d0(param_1,param_2 * 0x48 + param_1,&local_7c);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00868f58 @ 0x00868f58 ====

void Catch_00868f58(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00869060 @ 0x00869060 ====

void FUN_00869060(uint param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x2c) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0x88))
            (*(int **)(in_ECX + 0x1c),*(undefined4 *)(iVar1 + param_1 * 4),param_2);
  return;
}


// ==== FUN_008690a0 @ 0x008690a0 ====

void FUN_008690a0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a2f0;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x24;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x71c71c7 < uVar1) {
      uVar1 = FUN_0085b3b0();
    }
    pvVar2 = operator_new(uVar1 * 0x24);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x24 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_00868a50(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00869167 @ 0x00869167 ====

void Catch_00869167(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00869180 @ 0x00869180 ====

void FUN_00869180(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x24 != 0) {
      iVar1 = (param_2 - iVar1) / 0x24;
      goto LAB_008691c5;
    }
  }
  iVar1 = 0;
LAB_008691c5:
  FUN_00868b00(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x24;
  return;
}


// ==== FUN_008691f0 @ 0x008691f0 ====

void FUN_008691f0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a300;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x48;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_00868ab0(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_008689d0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00869287 @ 0x00869287 ====

void Catch_00869287(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008692a0 @ 0x008692a0 ====

void FUN_008692a0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x48 != 0) {
      iVar1 = (param_2 - iVar1) / 0x48;
      goto LAB_008692e5;
    }
  }
  iVar1 = 0;
LAB_008692e5:
  FUN_00868db0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x48;
  return;
}


// ==== FUN_00869310 @ 0x00869310 ====

void FUN_00869310(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x24) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x24))) {
    FUN_00869180(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_008688f0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x24;
  return;
}


// ==== FUN_008693a0 @ 0x008693a0 ====

void FUN_008693a0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x48) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x48))) {
    FUN_008692a0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00868960(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x48;
  return;
}


// ==== FUN_00869430 @ 0x00869430 ====

/* WARNING: Removing unreachable block (ram,0x00869547) */
/* WARNING: Removing unreachable block (ram,0x00869558) */
/* WARNING: Removing unreachable block (ram,0x00869561) */
/* WARNING: Removing unreachable block (ram,0x00869564) */
/* WARNING: Removing unreachable block (ram,0x00869554) */
/* WARNING: Removing unreachable block (ram,0x00869572) */
/* WARNING: Removing unreachable block (ram,0x0086957f) */
/* WARNING: Removing unreachable block (ram,0x0086958a) */
/* WARNING: Removing unreachable block (ram,0x00869586) */
/* WARNING: Removing unreachable block (ram,0x0086957a) */
/* WARNING: Removing unreachable block (ram,0x0086958d) */

void FUN_00869430(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x45) != '\0') {
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
  FUN_00503890();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x45) == '\0') {
    if (*(char *)(param_2[2] + 0x45) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x45) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x45) == '\0') {
      piVar3 = (int *)FUN_00503810(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x45) == '\0') {
      uVar4 = FUN_00868460(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x11] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x11] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x11] == '\0') {
            *(undefined1 *)(piVar5 + 0x11) = 1;
            *(undefined1 *)(piVar3 + 0x11) = 0;
            FUN_00868500(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x45) == '\0') {
            if ((*(char *)(*piVar5 + 0x44) == '\x01') && (*(char *)(piVar5[2] + 0x44) == '\x01'))
            goto LAB_00869664;
            if (*(char *)(piVar5[2] + 0x44) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x44) = 1;
              *(undefined1 *)(piVar5 + 0x11) = 0;
              FUN_00868550(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x11) = (char)piVar3[0x11];
            *(undefined1 *)(piVar3 + 0x11) = 1;
            *(undefined1 *)(piVar5[2] + 0x44) = 1;
            FUN_00868500(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x11] == '\0') {
            *(undefined1 *)(piVar5 + 0x11) = 1;
            *(undefined1 *)(piVar3 + 0x11) = 0;
            FUN_00868550(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x45) == '\0') {
            if ((*(char *)(piVar5[2] + 0x44) != '\x01') || (*(char *)(*piVar5 + 0x44) != '\x01')) {
              if (*(char *)(*piVar5 + 0x44) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x44) = 1;
                *(undefined1 *)(piVar5 + 0x11) = 0;
                FUN_00868500(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x11) = (char)piVar3[0x11];
              *(undefined1 *)(piVar3 + 0x11) = 1;
              *(undefined1 *)(*piVar5 + 0x44) = 1;
              FUN_00868550(piVar3);
              break;
            }
LAB_00869664:
            *(undefined1 *)(piVar5 + 0x11) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x11) = 1;
  }
  if ((void *)param_2[0xd] != (void *)0x0) {
    _free((void *)param_2[0xd]);
    return;
  }
  param_2[0xd] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  if ((void *)param_2[9] == (void *)0x0) {
    param_2[9] = 0;
    param_2[10] = 0;
    param_2[0xb] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[9]);
  return;
}


// ==== FUN_00869720 @ 0x00869720 ====

/* WARNING: Removing unreachable block (ram,0x00869839) */
/* WARNING: Removing unreachable block (ram,0x0086984a) */
/* WARNING: Removing unreachable block (ram,0x00869853) */
/* WARNING: Removing unreachable block (ram,0x00869856) */
/* WARNING: Removing unreachable block (ram,0x00869846) */
/* WARNING: Removing unreachable block (ram,0x00869864) */
/* WARNING: Removing unreachable block (ram,0x00869871) */
/* WARNING: Removing unreachable block (ram,0x0086987c) */
/* WARNING: Removing unreachable block (ram,0x00869878) */
/* WARNING: Removing unreachable block (ram,0x0086986c) */
/* WARNING: Removing unreachable block (ram,0x0086987f) */

void FUN_00869720(undefined4 param_1,int *param_2)

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
            goto LAB_00869954;
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
LAB_00869954:
            *(undefined1 *)(piVar5 + 0xd) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xd) = 1;
  }
  if ((void *)param_2[10] == (void *)0x0) {
    param_2[10] = 0;
    param_2[0xb] = 0;
    param_2[0xc] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[10]);
  return;
}


// ==== FUN_008699f0 @ 0x008699f0 ====

void FUN_008699f0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  FUN_008690a0(param_1 + 5);
  FUN_00427460(param_1 + 9);
  in_ECX[0xd] = param_1[0xd];
  return;
}


// ==== FUN_00869a50 @ 0x00869a50 ====

void FUN_00869a50(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = *param_2;
  in_ECX[2] = param_2[1];
  in_ECX[3] = param_2[2];
  in_ECX[4] = param_2[3];
  FUN_008690a0(param_2 + 4);
  FUN_00427460(param_2 + 8);
  in_ECX[0xd] = param_2[0xc];
  return;
}


// ==== FUN_00869ab0 @ 0x00869ab0 ====

void FUN_00869ab0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x45) != '\0') {
    return;
  }
  FUN_00869ab0(*(undefined4 *)((int)param_1 + 8));
  if (*(void **)((int)param_1 + 0x34) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 0x34));
    return;
  }
  *(undefined4 *)((int)param_1 + 0x34) = 0;
  *(undefined4 *)((int)param_1 + 0x38) = 0;
  *(undefined4 *)((int)param_1 + 0x3c) = 0;
  if (*(void **)((int)param_1 + 0x24) == (void *)0x0) {
    *(undefined4 *)((int)param_1 + 0x24) = 0;
    *(undefined4 *)((int)param_1 + 0x28) = 0;
    *(undefined4 *)((int)param_1 + 0x2c) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x24));
  return;
}


// ==== FUN_00869b20 @ 0x00869b20 ====

void FUN_00869b20(void *param_1)

{
  if (*(char *)((int)param_1 + 0x35) != '\0') {
    return;
  }
  FUN_00869b20(*(undefined4 *)((int)param_1 + 8));
  if (*(void **)((int)param_1 + 0x28) == (void *)0x0) {
    *(undefined4 *)((int)param_1 + 0x28) = 0;
    *(undefined4 *)((int)param_1 + 0x2c) = 0;
    *(undefined4 *)((int)param_1 + 0x30) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x28));
  return;
}


// ==== FUN_00869b70 @ 0x00869b70 ====

void FUN_00869b70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  FUN_008699f0(param_4);
  *(undefined1 *)(in_ECX + 0x11) = param_5;
  *(undefined1 *)((int)in_ECX + 0x45) = 0;
  return;
}


// ==== FUN_00869bb0 @ 0x00869bb0 ====

void FUN_00869bb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
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
  *(undefined1 *)(in_ECX + 7) = *(undefined1 *)(param_4 + 4);
  in_ECX[8] = param_4[5];
  FUN_008691f0(param_4 + 6);
  *(undefined1 *)(in_ECX + 0xd) = param_5;
  *(undefined1 *)((int)in_ECX + 0x35) = 0;
  return;
}


// ==== FUN_00869cd0 @ 0x00869cd0 ====

void * FUN_00869cd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a310;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x48);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00869b70(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00869d45 @ 0x00869d45 ====

void Catch_00869d45(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00869d60 @ 0x00869d60 ====

void FUN_00869d60(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00869b20(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x35) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x35) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x35);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x35);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x35);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x35);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00869720(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00869e20 @ 0x00869e20 ====

void * FUN_00869e20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a320;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x38);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00869bb0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00869e95 @ 0x00869e95 ====

void Catch_00869e95(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00869eb0 @ 0x00869eb0 ====

void FUN_00869eb0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x4924922 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00869cd0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x44);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x44) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x11] == '\0') {
LAB_00869fb5:
        *(undefined1 *)(*piVar5 + 0x44) = 1;
        *(undefined1 *)(piVar6 + 0x11) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x44) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_00868500(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x44) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x44) = 0;
        FUN_00868550(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x11] == '\0') goto LAB_00869fb5;
      if (piVar7 == (int *)*piVar2) {
        FUN_00868550(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x44) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x44) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x45) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x44);
  } while( true );
}


// ==== FUN_0086a090 @ 0x0086a090 ====

void FUN_0086a090(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00869e20(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_0086a195:
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
      if ((char)piVar6[0xd] == '\0') goto LAB_0086a195;
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


// ==== FUN_0086a270 @ 0x0086a270 ====

void FUN_0086a270(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x45) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x45) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00869eb0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_00503830();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00869eb0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0086a330 @ 0x0086a330 ====

void FUN_0086a330(undefined4 *param_1,uint *param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int in_ECX;
  
  puVar1 = param_2;
  puVar3 = *(undefined4 **)(in_ECX + 4);
  cVar4 = '\x01';
  if (*(char *)((int)puVar3[1] + 0x35) == '\0') {
    puVar2 = (undefined4 *)puVar3[1];
    do {
      puVar3 = puVar2;
      if (*param_2 < (uint)puVar3[3]) {
        cVar4 = '\x01';
      }
      else if (((uint)puVar3[3] < *param_2) || ((uint)puVar3[4] <= param_2[1])) {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      if (cVar4 == '\0') {
        puVar2 = (undefined4 *)puVar3[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar3;
      }
    } while (*(char *)((int)puVar2 + 0x35) == '\0');
  }
  param_2 = puVar3;
  if (cVar4 != '\0') {
    if (puVar3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      cVar4 = '\x01';
      goto LAB_0086a39f;
    }
    FUN_00885cd0();
  }
  if ((*puVar1 <= param_2[3]) && ((*puVar1 < param_2[3] || (puVar1[1] <= param_2[4])))) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_0086a39f:
  puVar3 = (undefined4 *)FUN_0086a090(&param_2,cVar4,puVar3,puVar1);
  *param_1 = *puVar3;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_0086a400 @ 0x0086a400 ====

void FUN_0086a400(byte param_1)

{
  void *in_ECX;
  
  FUN_00867ad0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0086a420 @ 0x0086a420 ====

int FUN_0086a420(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x70;
}


// ==== FUN_0086a450 @ 0x0086a450 ====

int FUN_0086a450(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a350;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x18) {
    FUN_0057e010(param_3,param_1);
    param_3 = param_3 + 0x18;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0086a4b6 @ 0x0086a4b6 ====

void Catch_0086a4b6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0086a4c0 @ 0x0086a4c0 ====

void FUN_0086a4c0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a330;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0057e010(param_1,param_3);
    param_1 = param_1 + 0x18;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0086a526 @ 0x0086a526 ====

void Catch_0086a526(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0086a530 @ 0x0086a530 ====

int FUN_0086a530(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a340;
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


// ==== Catch@0086a596 @ 0x0086a596 ====

void Catch_0086a596(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0086a5a0 @ 0x0086a5a0 ====

undefined4 FUN_0086a5a0(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x18;
  }
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  iVar3 = iVar3 * 0x18;
  cVar2 = FUN_00881000(0x18,iVar3);
  if (cVar2 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  cVar2 = FUN_00881000(0x18,iVar3);
  if (cVar2 == '\0') {
    return 0;
  }
  uVar4 = (**(code **)(*piVar1 + 0x1c))(0x18,iVar3);
  (**(code **)(*piVar1 + 0x14))(iVar3,*(undefined4 *)(param_1 + 4));
  FUN_00881060();
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x18)
  ;
  return uVar4;
}


// ==== FUN_0086a660 @ 0x0086a660 ====

undefined4 FUN_0086a660(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 1;
  }
  iVar2 = iVar2 * 2;
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar2)) {
    (**(code **)(*piVar1 + 0x10))();
  }
  if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar2)) {
    return 0;
  }
  uVar3 = (**(code **)(*piVar1 + 0x20))(iVar2);
  iVar2 = *(int *)(param_1 + 0x14);
  if (iVar2 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x18) - iVar2 >> 1;
  }
  (**(code **)(*piVar1 + 0x18))(iVar4,iVar2);
  FUN_00881080();
  return uVar3;
}


// ==== FUN_0086a720 @ 0x0086a720 ====

void FUN_0086a720(undefined4 param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int unaff_EBP;
  int iVar3;
  uint unaff_EDI;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = FUN_0086a5a0(param_2);
  local_c = FUN_0086a660(param_2);
  if ((*(int *)(param_2 + 0x14) != 0) &&
     (2 < (uint)(*(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 1))) {
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0);
    FUN_0084b7f0(*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 0x18));
    uVar6 = 0;
    puVar5 = &local_c;
    (**(code **)(**(int **)(unaff_EBP + 0x1c) + 0x104))(*(int **)(unaff_EBP + 0x1c),puVar5,0);
    if (unaff_EDI != 0) {
      uVar4 = 0;
      do {
        (**(code **)(*piRam00000034 + 0x108))(piRam00000034);
        if (*(int *)(param_2 + 0x14) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = *(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 1;
        }
        if (*(int *)(param_2 + 4) == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x18;
        }
        piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
        (**(code **)(*piVar1 + 0x148))(piVar1,2,uVar6,0,iVar3,puVar5,uVar2 / 3);
        (**(code **)(**(int **)(uVar4 + 0x1c) + 0x110))(*(int **)(uVar4 + 0x1c));
        uVar4 = uVar4 + 1;
      } while (uVar4 < unaff_EDI);
    }
    (**(code **)(*piRam00000034 + 0x114))(piRam00000034);
  }
  return;
}


// ==== FUN_0086a880 @ 0x0086a880 ====

void FUN_0086a880(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_c0 [4];
  undefined4 auStack_bc [15];
  undefined4 local_80 [10];
  undefined1 auStack_58 [12];
  undefined4 auStack_4c [17];
  int iStack_8;
  
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
  puVar3 = local_80;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  thunk_FUN_0079ee7b(local_c0,param_2 + 0x20,local_80);
  puVar2 = (undefined4 *)(local_c0 + -0xc);
  puVar3 = auStack_4c;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = *(int *)(iStack_8 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iStack_8 + 0x2c) - iVar1 >> 2) < 0x78)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iStack_8 + 0x1c) + 0x88))
            (*(int **)(iStack_8 + 0x1c),*(undefined4 *)(iVar1 + 0x1dc),param_2 + 0x60);
  iVar1 = *(int *)(iStack_8 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iStack_8 + 0x2c) - iVar1 >> 2) < 0x77)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iStack_8 + 0x1c) + 0x98))
            (*(int **)(iStack_8 + 0x1c),*(undefined4 *)(iVar1 + 0x1d8),auStack_58);
  return;
}


// ==== FUN_0086a950 @ 0x0086a950 ====

int FUN_0086a950(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar4 + 0x7b) != '\0') {
    iVar4 = 0;
    if ((*(int *)(in_ECX + 8) != 0) &&
       (iVar3 = *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8), iVar4 = iVar3 * -0x6db6db6d,
       iVar3 / 0x70 != 0)) {
      FUN_00859670();
      iVar2 = FUN_0085e3a0(0xd);
      piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar1 + 0x15c))(piVar1,*(undefined4 *)(iVar2 + 0x20));
      (**(code **)(**(int **)(iVar2 + 0x1c) + 0xf0))(*(int **)(iVar2 + 0x1c),s_ObbRender_00a135ac);
      iVar3 = *(int *)(in_ECX + 0xc);
      for (iVar4 = *(int *)(in_ECX + 8); iVar4 != iVar3; iVar4 = iVar4 + 0x70) {
        FUN_0086a880(iVar2,iVar4);
        FUN_0086a720(iVar2,iVar4);
      }
      iVar4 = FUN_00859770();
      return iVar4;
    }
  }
  return iVar4;
}


// ==== FUN_0086aa20 @ 0x0086aa20 ====

void FUN_0086aa20(undefined4 *param_1)

{
  int iVar1;
  short *psVar2;
  undefined4 *puVar3;
  int iVar4;
  short sVar5;
  float *pfVar6;
  float *pfVar7;
  short sVar8;
  float *pfVar9;
  float fVar10;
  short sStack_10e;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float local_fc [4];
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float *pfStack_94;
  float *pfStack_90;
  undefined4 *local_88;
  undefined4 *local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [60];
  int iStack_4;
  
  local_80 = param_1[3];
  local_70 = param_1[4];
  local_fc[0] = (float)param_1[0xc];
  local_fc[1] = (float)param_1[0xd];
  local_fc[2] = (float)param_1[0xe];
  local_6c = param_1[7];
  local_84 = param_1 + 3;
  local_7c = param_1[6];
  local_68 = param_1[10];
  local_88 = param_1 + 6;
  local_78 = param_1[9];
  local_60 = param_1[5];
  pfVar6 = (float *)(param_1 + 9);
  local_5c = param_1[8];
  local_74 = 0;
  local_64 = 0;
  local_58 = param_1[0xb];
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = DAT_0099d080;
  thunk_FUN_0079f7f5(local_40,*param_1,param_1[1],param_1[2]);
  thunk_FUN_0079ee7b(local_fc + 3,local_40,&local_80);
  pfVar7 = local_fc;
  pfVar9 = (float *)(iStack_4 + 0x20);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar9 = *pfVar7;
    pfVar7 = pfVar7 + 1;
    pfVar9 = pfVar9 + 1;
  }
  puVar3 = (undefined4 *)FUN_0040e8c0(local_fc + -8,param_1[0xf]);
  *(undefined4 *)(iStack_4 + 0x60) = *puVar3;
  *(undefined4 *)(iStack_4 + 100) = puVar3[1];
  *(undefined4 *)(iStack_4 + 0x68) = puVar3[2];
  *(undefined4 *)(iStack_4 + 0x6c) = puVar3[3];
  local_fc[3] = 0.0 - *pfVar6;
  fStack_ec = 0.0 - (float)param_1[10];
  fStack_e8 = 0.0 - (float)param_1[0xb];
  local_fc[1] = 0.0 - fStack_104;
  local_fc[2] = 0.0 - fStack_100;
  fVar10 = 0.0 - fStack_108;
  pfVar7 = local_fc;
  iVar4 = 4;
  fStack_e4 = fVar10;
  fStack_e0 = local_fc[1];
  fStack_dc = local_fc[2];
  fStack_d8 = local_fc[3];
  fStack_d4 = fStack_ec;
  fStack_d0 = fStack_e8;
  fStack_cc = fVar10;
  fStack_c4 = local_fc[2];
  fStack_c0 = local_fc[3];
  fStack_bc = fStack_ec;
  fStack_b8 = fStack_e8;
  fStack_ac = local_fc[2];
  fStack_a8 = local_fc[3];
  fStack_a4 = fStack_ec;
  fStack_a0 = fStack_e8;
  fStack_9c = local_fc[1];
  fStack_98 = local_fc[2];
  do {
    FUN_0086c900(pfVar7);
    pfVar7 = pfVar7 + 6;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  fStack_a8 = *pfVar6;
  fStack_a4 = (float)param_1[10];
  fStack_a0 = (float)param_1[0xb];
  fStack_c0 = *pfVar6;
  fStack_bc = (float)param_1[10];
  fStack_b8 = (float)param_1[0xb];
  fStack_d8 = *pfVar6;
  fStack_d4 = (float)param_1[10];
  fStack_d0 = (float)param_1[0xb];
  local_fc[3] = *pfVar6;
  fStack_ec = (float)param_1[10];
  fStack_e8 = (float)param_1[0xb];
  local_fc[1] = fStack_9c;
  fStack_e0 = fStack_9c;
  pfVar6 = local_fc;
  iVar4 = 4;
  fStack_e4 = fVar10;
  fStack_cc = fVar10;
  do {
    FUN_0086c900(pfVar6);
    pfVar6 = pfVar6 + 6;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  fStack_a8 = *pfStack_90;
  fStack_a4 = pfStack_90[1];
  fStack_a0 = pfStack_90[2];
  fStack_c0 = *pfStack_90;
  fStack_bc = pfStack_90[1];
  fStack_b8 = pfStack_90[2];
  fStack_d8 = *pfStack_90;
  fStack_d4 = pfStack_90[1];
  fStack_d0 = pfStack_90[2];
  local_fc[3] = *pfStack_90;
  fStack_ec = pfStack_90[1];
  fStack_e8 = pfStack_90[2];
  local_fc[1] = fStack_9c;
  fStack_e0 = fStack_9c;
  fStack_dc = fStack_98;
  fStack_c4 = fStack_98;
  pfVar6 = local_fc;
  iVar4 = 4;
  do {
    FUN_0086c900(pfVar6);
    pfVar6 = pfVar6 + 6;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  local_fc[3] = 0.0 - *pfStack_90;
  fStack_ec = 0.0 - pfStack_90[1];
  fStack_e8 = 0.0 - pfStack_90[2];
  local_fc[1] = fStack_9c;
  fStack_e0 = fStack_9c;
  fStack_dc = fStack_98;
  fStack_c4 = fStack_98;
  pfVar6 = local_fc;
  iVar4 = 4;
  local_fc[0] = fVar10;
  fStack_e4 = fVar10;
  fStack_d8 = local_fc[3];
  fStack_d4 = fStack_ec;
  fStack_d0 = fStack_e8;
  fStack_cc = fVar10;
  fStack_c0 = local_fc[3];
  fStack_bc = fStack_ec;
  fStack_b8 = fStack_e8;
  fStack_b4 = fVar10;
  fStack_a8 = local_fc[3];
  fStack_a4 = fStack_ec;
  fStack_a0 = fStack_e8;
  do {
    FUN_0086c900(pfVar6);
    pfVar6 = pfVar6 + 6;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  fStack_a8 = *pfStack_94;
  fStack_a4 = pfStack_94[1];
  fStack_a0 = pfStack_94[2];
  fStack_c0 = *pfStack_94;
  fStack_bc = pfStack_94[1];
  fStack_b8 = pfStack_94[2];
  fStack_d8 = *pfStack_94;
  fStack_d4 = pfStack_94[1];
  fStack_d0 = pfStack_94[2];
  local_fc[3] = *pfStack_94;
  fStack_ec = pfStack_94[1];
  fStack_e8 = pfStack_94[2];
  local_fc[2] = fStack_98;
  fStack_dc = fStack_98;
  pfVar6 = local_fc;
  iVar4 = 4;
  fStack_e4 = fVar10;
  fStack_cc = fVar10;
  do {
    FUN_0086c900(pfVar6);
    pfVar6 = pfVar6 + 6;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  local_fc[3] = 0.0 - *pfStack_94;
  fStack_ec = 0.0 - pfStack_94[1];
  fStack_e8 = 0.0 - pfStack_94[2];
  local_fc[1] = fStack_9c;
  local_fc[2] = fStack_98;
  fStack_e0 = fStack_9c;
  fStack_dc = fStack_98;
  fStack_c8 = fStack_9c;
  fStack_b0 = fStack_9c;
  pfVar6 = local_fc;
  iVar4 = 4;
  fStack_e4 = fVar10;
  fStack_d8 = local_fc[3];
  fStack_d4 = fStack_ec;
  fStack_d0 = fStack_e8;
  fStack_cc = fVar10;
  fStack_c0 = local_fc[3];
  fStack_bc = fStack_ec;
  fStack_b8 = fStack_e8;
  fStack_a8 = local_fc[3];
  fStack_a4 = fStack_ec;
  fStack_a0 = fStack_e8;
  do {
    FUN_0086c900(pfVar6);
    pfVar6 = pfVar6 + 6;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  sVar5 = 0;
  fStack_10c = 8.40779e-45;
  do {
    iVar4 = 0;
    do {
      iVar1 = *(int *)(iStack_4 + 0x14);
      sVar8 = *(short *)((int)local_fc + iVar4 * 2 + -0x20) + sVar5;
      pfVar6 = (float *)CONCAT22((short)((uint)pfVar6 >> 0x10),sVar8);
      pfStack_94 = pfVar6;
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(iStack_4 + 0x1c) - iVar1 >> 1) <=
          (uint)(*(int *)(iStack_4 + 0x18) - iVar1 >> 1))) {
        FUN_00427290(*(undefined4 *)(iStack_4 + 0x18),1,&pfStack_94);
      }
      else {
        psVar2 = *(short **)(iStack_4 + 0x18);
        *psVar2 = sVar8;
        *(short **)(iStack_4 + 0x18) = psVar2 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
    sVar5 = sVar5 + 4;
    fStack_10c = (float)((int)fStack_10c + -1);
  } while (fStack_10c != 0.0);
  return;
}


// ==== FUN_0086b470 @ 0x0086b470 ====

void FUN_0086b470(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    return;
  }
  FUN_0084bbf0(*(int *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),in_ECX + 4);
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_0086b4b0 @ 0x0086b4b0 ====

void FUN_0086b4b0(int *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iStack_174;
  undefined1 auStack_170 [4];
  void *pvStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  void *pvStack_15c;
  undefined2 *puStack_158;
  int iStack_154;
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
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  uint uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  void *pvStack_e4;
  int iStack_e0;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 auStack_c0 [24];
  undefined4 auStack_60 [24];
  
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x7b) != '\0') {
    iStack_174 = (**(code **)(*param_1 + 0xa0))();
    iVar4 = 0;
    if (0 < iStack_174) {
      do {
        uVar1 = (**(code **)(*param_1 + 0xa4))(iVar4);
        pvStack_16c = (void *)0x0;
        uStack_168 = 0;
        uStack_164 = 0;
        pvStack_15c = (void *)0x0;
        puStack_158 = (undefined2 *)0x0;
        iStack_154 = 0;
        FUN_0086aa20(uVar1,auStack_170);
        FUN_0086cfa0(auStack_170);
        if (pvStack_15c != (void *)0x0) {
          _free(pvStack_15c);
          return;
        }
        pvStack_15c = (void *)0x0;
        puStack_158 = (undefined2 *)0x0;
        iStack_154 = 0;
        if (pvStack_16c != (void *)0x0) {
          _free(pvStack_16c);
          return;
        }
        iVar4 = iVar4 + 1;
        pvStack_16c = (void *)0x0;
        uStack_168 = 0;
        uStack_164 = 0;
      } while (iVar4 < iStack_174);
    }
    uVar1 = (**(code **)(*param_1 + 0x9c))();
    FUN_0086c6e0(uVar1);
    if (pvStack_e4 == (void *)0x0) {
      iStack_174 = 0;
    }
    else {
      iStack_174 = iStack_e0 - (int)pvStack_e4 >> 2;
    }
    uStack_fc = 0;
    if (0 < iStack_174) {
      do {
        if ((pvStack_e4 == (void *)0x0) || ((uint)(iStack_e0 - (int)pvStack_e4 >> 2) <= uStack_fc))
        {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        iVar4 = *(int *)((int)pvStack_e4 + uStack_fc * 4);
        iVar3 = *(int *)(iVar4 + 0x58);
        for (iVar4 = *(int *)(iVar4 + 0x54); iVar4 != iVar3; iVar4 = iVar4 + 0x40) {
          pvStack_16c = (void *)0x0;
          uStack_168 = 0;
          uStack_164 = 0;
          pvStack_15c = (void *)0x0;
          puStack_158 = (undefined2 *)0x0;
          iStack_154 = 0;
          FUN_0086aa20(iVar4,auStack_170);
          FUN_0086cfa0(auStack_170);
          if (pvStack_15c != (void *)0x0) {
            _free(pvStack_15c);
            return;
          }
          pvStack_15c = (void *)0x0;
          puStack_158 = (undefined2 *)0x0;
          iStack_154 = 0;
          if (pvStack_16c != (void *)0x0) {
            _free(pvStack_16c);
            return;
          }
          pvStack_16c = (void *)0x0;
          uStack_168 = 0;
          uStack_164 = 0;
        }
        uStack_fc = uStack_fc + 1;
      } while ((int)uStack_fc < iStack_174);
    }
    pvStack_16c = (void *)0x0;
    uStack_168 = 0;
    uStack_164 = 0;
    pvStack_15c = (void *)0x0;
    puStack_158 = (undefined2 *)0x0;
    iStack_154 = 0;
    puVar2 = (undefined4 *)FUN_0040ec60(&uStack_f8,0xff0000ff);
    uStack_110 = *puVar2;
    uStack_10c = puVar2[1];
    uStack_108 = puVar2[2];
    uStack_104 = puVar2[3];
    uStack_118 = 0;
    uStack_11c = 0;
    uStack_120 = 0;
    uStack_124 = 0;
    uStack_12c = 0;
    uStack_130 = 0;
    uStack_134 = 0;
    uStack_138 = 0;
    uStack_140 = 0;
    uStack_144 = 0;
    uStack_148 = 0;
    uStack_14c = 0;
    uStack_114 = DAT_0099d080;
    uStack_128 = DAT_0099d080;
    uStack_13c = DAT_0099d080;
    uStack_150 = DAT_0099d080;
    iVar4 = (**(code **)(*param_1 + 0xc))();
    uStack_f8 = DAT_0099d080;
    puVar2 = (undefined4 *)(iVar4 + 0x34);
    puVar5 = auStack_c0;
    for (iVar3 = 0x30; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar5 = puVar5 + 1;
    }
    uStack_f4 = 0;
    uStack_f0 = 0;
    uStack_cc = DAT_0099d080;
    uStack_c8 = 0;
    uStack_c4 = 0;
    puVar2 = auStack_60;
    iVar4 = 8;
    do {
      uStack_d8 = *puVar2;
      uStack_d4 = puVar2[1];
      uStack_d0 = puVar2[2];
      FUN_0086c900(&uStack_d8);
      puVar2 = puVar2 + 3;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iStack_174 = 0;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 0;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 1;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 1;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 1;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 1;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 3;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 3;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 3;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 3;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 2;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 2;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 2;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 2;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 0;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 0;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 4;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 4;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 5;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 5;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 5;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 5;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 7;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 7;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 7;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 7;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 6;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 6;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 6;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 6;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 4;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 4;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 2;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 2;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 6;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 6;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 6;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 6;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 7;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 7;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 7;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 7;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 3;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 3;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 3;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 3;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 2;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 2;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 0;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 0;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 1;
    if ((pvStack_15c == (void *)0x0) ||
       ((uint)(iStack_154 - (int)pvStack_15c >> 1) <=
        (uint)((int)puStack_158 - (int)pvStack_15c >> 1))) {
      FUN_00427290(puStack_158,1,&iStack_174);
    }
    else {
      *puStack_158 = 1;
      puStack_158 = puStack_158 + 1;
    }
    iStack_174 = 1;
    FUN_004275a0(&iStack_174);
    iStack_174 = 5;
    FUN_004275a0(&iStack_174);
    iStack_174 = 5;
    FUN_004275a0(&iStack_174);
    iStack_174 = 4;
    FUN_004275a0(&iStack_174);
    iStack_174 = 4;
    FUN_004275a0(&iStack_174);
    iStack_174 = 0;
    FUN_004275a0(&iStack_174);
    iStack_174 = 1;
    FUN_004275a0(&iStack_174);
    iStack_174 = 3;
    FUN_004275a0(&iStack_174);
    iStack_174 = 3;
    FUN_004275a0(&iStack_174);
    iStack_174 = 7;
    FUN_004275a0(&iStack_174);
    iStack_174 = 7;
    FUN_004275a0(&iStack_174);
    iStack_174 = 5;
    FUN_004275a0(&iStack_174);
    iStack_174 = 5;
    FUN_004275a0(&iStack_174);
    iStack_174 = 1;
    FUN_004275a0(&iStack_174);
    iStack_174 = 2;
    FUN_004275a0(&iStack_174);
    iStack_174 = 6;
    FUN_004275a0(&iStack_174);
    iStack_174 = 6;
    FUN_004275a0(&iStack_174);
    iStack_174 = 4;
    FUN_004275a0(&iStack_174);
    iStack_174 = 4;
    FUN_004275a0(&iStack_174);
    iStack_174 = 0;
    FUN_004275a0(&iStack_174);
    iStack_174 = 0;
    FUN_004275a0(&iStack_174);
    iStack_174 = 2;
    FUN_004275a0(&iStack_174);
    FUN_0086cfa0(auStack_170);
    if (pvStack_15c != (void *)0x0) {
      _free(pvStack_15c);
      return;
    }
    if (pvStack_16c != (void *)0x0) {
      _free(pvStack_16c);
      return;
    }
    if (pvStack_e4 != (void *)0x0) {
      _free(pvStack_e4);
      return;
    }
  }
  return;
}


// ==== FUN_0086c120 @ 0x0086c120 ====

void FUN_0086c120(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0086a450(param_1,param_2,param_3);
  return;
}


// ==== FUN_0086c140 @ 0x0086c140 ====

int FUN_0086c140(int param_1,int param_2,undefined4 param_3)

{
  FUN_0086a4c0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x18;
}


// ==== FUN_0086c170 @ 0x0086c170 ====

void FUN_0086c170(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0086a530(param_1,param_2,param_3);
  return;
}


// ==== FUN_0086c190 @ 0x0086c190 ====

undefined4 FUN_0086c190(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0xaaaaaaa < param_1) {
    param_1 = FUN_0085b3b0();
  }
  pvVar1 = operator_new(param_1 * 0x18);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x18 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_0086c1e0 @ 0x0086c1e0 ====

void FUN_0086c1e0(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint extraout_ECX;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
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
  puStack_c = &LAB_0099a360;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x5c);
  local_50 = *param_3;
  local_4c = param_3[1];
  local_48 = param_3[2];
  local_44 = param_3[3];
  local_40 = param_3[4];
  local_3c = param_3[5];
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x18;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x5c);
    if (0xaaaaaaaU - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_20 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
    }
    if (local_20 < iVar2 + param_2) {
      if (0xaaaaaaa - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_0057dfd0();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0x18;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_0086c120(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_0086c140(local_1c,param_2,&local_50);
      FUN_0086c120(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x18;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0x18);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0x18) < param_2) {
      local_24 = param_2 * 0x18;
      FUN_0086a450(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_0086c140(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x18,&local_50)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_004dcf10(param_1,*(int *)(in_ECX + 8) - local_24,&local_50);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x18;
    uVar4 = FUN_0086a450(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_0085d5a0(param_1,local_2c,local_28,local_38);
    FUN_004dcf10(param_1,param_2 * 0x18 + param_1,&local_50);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0086c3a1 @ 0x0086c3a1 ====

void Catch_0086c3a1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0086c4b0 @ 0x0086c4b0 ====

void FUN_0086c4b0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a370;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x18;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_0086c190(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_0086c120(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0086c547 @ 0x0086c547 ====

void Catch_0086c547(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0086c560 @ 0x0086c560 ====

void FUN_0086c560(int param_1)

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
    iVar6 = iVar6 / 0x18 + iVar4;
    uVar7 = iVar6 - iVar4;
    if (iVar6 != iVar4) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x18;
      }
      if (uVar7 <= uVar3) {
        FUN_0085d550(iVar1,*(undefined4 *)(param_1 + 8),_Memory,param_1);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x18) * 0x18;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 0xc) - (int)_Memory) / 0x18;
      }
      if (uVar7 <= uVar3) {
        iVar4 = FUN_0057dfd0();
        iVar1 = iVar1 + iVar4 * 0x18;
        FUN_0085d550(*(undefined4 *)(param_1 + 4),iVar1,_Memory,param_1);
        uVar5 = FUN_0086a450(iVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar5;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      uVar5 = FUN_0057dfd0();
      cVar2 = FUN_0086c190(uVar5);
      if (cVar2 == '\0') {
        return;
      }
      uVar5 = FUN_0086c120(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
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


// ==== FUN_0086c6e0 @ 0x0086c6e0 ====

void FUN_0086c6e0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a380;
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
    uVar3 = FUN_0086c170(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0086c799 @ 0x0086c799 ====

void Catch_0086c799(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0086c7b0 @ 0x0086c7b0 ====

void FUN_0086c7b0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x18 != 0) {
      iVar1 = (param_2 - iVar1) / 0x18;
      goto LAB_0086c7f5;
    }
  }
  iVar1 = 0;
LAB_0086c7f5:
  FUN_0086c1e0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x18;
  return;
}


// ==== FUN_0086c820 @ 0x0086c820 ====

void FUN_0086c820(int param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  FUN_0086c4b0(param_1);
  FUN_00427460(param_1 + 0x10);
  puVar2 = (undefined4 *)(param_1 + 0x20);
  puVar3 = (undefined4 *)(in_ECX + 0x20);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  return;
}


// ==== FUN_0086c870 @ 0x0086c870 ====

int FUN_0086c870(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_1 != param_2) {
    puVar2 = (undefined4 *)(param_2 + 0x20);
    puVar3 = (undefined4 *)(param_3 + 0x20);
    while( true ) {
      param_2 = param_2 + -0x70;
      param_3 = param_3 + -0x70;
      FUN_0086c560(param_2);
      FUN_004394e0(puVar2 + -0x20);
      puVar4 = puVar2 + -0x1c;
      puVar5 = puVar3 + -0x1c;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar3[-0xc] = puVar2[-0xc];
      puVar3[-0xb] = puVar2[-0xb];
      puVar3[-10] = puVar2[-10];
      puVar3[-9] = puVar2[-9];
      if (param_2 == param_1) break;
      puVar2 = puVar2 + -0x1c;
      puVar3 = puVar3 + -0x1c;
    }
  }
  return param_3;
}


// ==== FUN_0086c900 @ 0x0086c900 ====

void FUN_0086c900(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x18) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x18))) {
    FUN_0086c7b0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0086a4c0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x18;
  return;
}


// ==== FUN_0086c990 @ 0x0086c990 ====

void FUN_0086c990(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_1 != param_2) {
    puVar2 = (undefined4 *)(param_1 + 0x20);
    do {
      FUN_0086c560(param_3);
      FUN_004394e0(param_3 + 0x10);
      puVar3 = (undefined4 *)(param_3 + 0x20);
      puVar4 = puVar2;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar2[0x10] = *(undefined4 *)(param_3 + 0x60);
      puVar2[0x11] = *(undefined4 *)(param_3 + 100);
      puVar2[0x12] = *(undefined4 *)(param_3 + 0x68);
      param_1 = param_1 + 0x70;
      puVar2[0x13] = *(undefined4 *)(param_3 + 0x6c);
      puVar2 = puVar2 + 0x1c;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0086ca00 @ 0x0086ca00 ====

void FUN_0086ca00(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    FUN_0086c820(param_2);
  }
  return;
}


// ==== FUN_0086ca20 @ 0x0086ca20 ====

int FUN_0086ca20(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a390;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x70) {
    FUN_0086ca00(param_3,param_1);
    param_3 = param_3 + 0x70;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0086ca8a @ 0x0086ca8a ====

void Catch_0086ca8a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x70) {
    FUN_0084bb90(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0086cab0 @ 0x0086cab0 ====

void FUN_0086cab0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a3a0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0086ca00(param_1,param_3);
    param_1 = param_1 + 0x70;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0086cb1a @ 0x0086cb1a ====

void Catch_0086cb1a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x70) {
    FUN_0084bb90(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0086cb40 @ 0x0086cb40 ====

void FUN_0086cb40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0086ca20(param_1,param_2,param_3);
  return;
}


// ==== FUN_0086cb60 @ 0x0086cb60 ====

int FUN_0086cb60(int param_1,int param_2,undefined4 param_3)

{
  FUN_0086cab0(param_1,param_2,param_3);
  return param_2 * 0x70 + param_1;
}


// ==== FUN_0086cba0 @ 0x0086cba0 ====

void FUN_0086cba0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  uint extraout_ECX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 local_b0 [2];
  undefined1 auStack_ae [2];
  void *local_ac;
  void *local_9c;
  undefined4 local_90 [16];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_3c;
  int local_30;
  uint local_2c;
  int local_28;
  void *local_20;
  void *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a3b0;
  local_10 = ExceptionList;
  local_14 = local_b0 + -0xc;
  ExceptionList = &local_10;
  FUN_0086c4b0(param_3);
  FUN_00427460(param_3 + 0x10);
  puVar5 = (undefined4 *)(param_3 + 0x20);
  puVar6 = local_90;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  local_50 = *(undefined4 *)(param_3 + 0x60);
  local_4c = *(undefined4 *)(param_3 + 100);
  local_48 = *(undefined4 *)(param_3 + 0x68);
  local_44 = *(undefined4 *)(param_3 + 0x6c);
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x70;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x70;
    }
    if (0x2492492U - iVar3 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x70;
    }
    if (uVar4 < iVar3 + param_2) {
      if (0x2492492 - (uVar4 >> 1) < uVar4) {
        local_2c = 0;
      }
      else {
        local_2c = uVar4 + (uVar4 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x70;
      }
      if (local_2c < iVar3 + param_2) {
        iVar3 = FUN_0086a420();
        local_2c = iVar3 + param_2;
      }
      local_2c = local_2c * 0x70;
      local_20 = operator_new(local_2c);
      local_8 = 0;
      local_1c = local_20;
      local_1c = (void *)FUN_0086cb40(*(undefined4 *)(in_ECX + 4),param_1,local_20);
      local_1c = (void *)FUN_0086cb60(local_1c,param_2,local_b0);
      FUN_0086cb40(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      iVar3 = *(int *)(in_ECX + 4);
      if (iVar3 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x70;
      }
      if (iVar3 != 0) {
        FUN_0084bbf0(iVar3,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_2c + (int)local_20;
      *(void **)(in_ECX + 8) = (void *)((param_2 + iVar1) * 0x70 + (int)local_20);
      *(void **)(in_ECX + 4) = local_20;
    }
    else {
      local_30 = *(int *)(in_ECX + 8);
      local_28 = local_30 - param_1;
      if ((uint)(local_28 / 0x70) < param_2) {
        local_18 = param_2 * 0x70;
        FUN_0086ca20(param_1,local_30,local_18 + param_1);
        local_8 = 2;
        FUN_0086cb60(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x70,
                     local_b0);
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
        FUN_0086c990(param_1,*(int *)(in_ECX + 8) - local_18,local_b0);
      }
      else {
        local_18 = param_2 * 0x70;
        iVar3 = local_30 + param_2 * -0x70;
        uVar2 = FUN_0086ca20(iVar3,local_30,local_30);
        *(undefined4 *)(in_ECX + 8) = uVar2;
        FUN_0086c870(param_1,iVar3,local_30,local_3c);
        FUN_0086c990(param_1,local_18 + param_1,local_b0);
      }
    }
  }
  if (local_9c != (void *)0x0) {
    _free(local_9c);
    return;
  }
  if (local_ac == (void *)0x0) {
    ExceptionList = local_10;
    return;
  }
  _free(local_ac);
  return;
}


// ==== Catch@0086cdb2 @ 0x0086cdb2 ====

void Catch_0086cdb2(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x1c);
  FUN_0084bc50(_Memory,*(undefined4 *)(unaff_EBP + -0x18));
  _free(_Memory);
  return;
}


// ==== Catch@0086ce7a @ 0x0086ce7a ====

void Catch_0086ce7a(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x70;
  FUN_0084bc50(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x20) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0086cf20 @ 0x0086cf20 ====

void FUN_0086cf20(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x70 != 0) {
      iVar1 = (param_2 - iVar1) / 0x70;
      goto LAB_0086cf69;
    }
  }
  iVar1 = 0;
LAB_0086cf69:
  FUN_0086cba0(param_2,1,param_3);
  *param_1 = iVar1 * 0x70 + *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_0086cfa0 @ 0x0086cfa0 ====

void FUN_0086cfa0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x70) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x70))) {
    FUN_0086cf20(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0086cab0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x70;
  return;
}


// ==== FUN_0086d0f0 @ 0x0086d0f0 ====

void FUN_0086d0f0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_0084be00(param_1);
  if (cVar1 == '\0') {
    iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
    if (((*(int *)(iVar2 + 0x114) == 2) && (*(int *)(iVar2 + 0x118) == 5)) &&
       (*(int *)(iVar2 + 0x11c) == 6)) {
      return;
    }
    if (*(int *)(iVar2 + 100) != 0) {
      return;
    }
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x14,6);
    *(undefined4 *)(iVar2 + 0x11c) = 6;
  }
  else {
    iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
    if (((*(int *)(iVar2 + 0x114) == 2) && (*(int *)(iVar2 + 0x118) == 5)) &&
       (*(int *)(iVar2 + 0x11c) == 2)) {
      return;
    }
    if (*(int *)(iVar2 + 100) != 0) {
      return;
    }
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x14,2);
    *(undefined4 *)(iVar2 + 0x11c) = 2;
  }
  *(undefined4 *)(iVar2 + 0x114) = 2;
  *(undefined4 *)(iVar2 + 0x118) = 5;
  return;
}


// ==== FUN_0086d2d0 @ 0x0086d2d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0086d2d0(int *param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  int local_228;
  int local_224;
  short sStack_220;
  ushort uStack_21e;
  short sStack_21c;
  short sStack_21a;
  float fStack_218;
  float fStack_214;
  float fStack_210;
  float fStack_20c;
  float fStack_208;
  int iStack_204;
  int aiStack_200 [4];
  int aiStack_1f0 [4];
  int aiStack_1e0 [4];
  int aiStack_1d0 [4];
  undefined1 auStack_1c0 [20];
  float afStack_1ac [107];
  
  iVar6 = param_1[10];
  if (iVar6 == 1) {
    iVar6 = param_1[0xb];
  }
  else {
    if (iVar6 == 2) {
      iVar3 = param_1[0xb];
      iVar6 = 0;
      goto LAB_0086d309;
    }
    if (iVar6 == 3) {
      iVar6 = param_1[0xb];
      iVar3 = iVar6;
      goto LAB_0086d309;
    }
    iVar6 = 0;
  }
  iVar3 = 0;
LAB_0086d309:
  local_228 = param_1[8];
  local_224 = param_1[9];
  if ((local_228 != 0) || (local_224 != 0)) {
    FUN_0086d0f0(param_1[3]);
    piVar2 = (int *)FUN_004af750();
    if (param_1[8] < 0) {
      local_228 = (**(code **)(*piVar2 + 8))();
    }
    if (param_1[9] < 0) {
      local_224 = (**(code **)(*piVar2 + 0xc))();
    }
    aiStack_1f0[0] = *param_1;
    aiStack_1f0[1] = aiStack_1f0[0] + iVar6;
    aiStack_1f0[3] = aiStack_1f0[0] + local_228;
    aiStack_1d0[0] = param_1[1];
    aiStack_1d0[1] = param_1[1] + iVar3;
    aiStack_1f0[2] = (aiStack_1f0[0] - iVar6) + local_228;
    aiStack_1d0[3] = param_1[1] + local_224;
    aiStack_1e0[0] = param_1[4];
    aiStack_1e0[1] = param_1[4] + iVar6;
    aiStack_1e0[3] = param_1[6];
    aiStack_200[0] = param_1[5];
    aiStack_200[1] = param_1[5] + iVar3;
    aiStack_1d0[2] = (param_1[1] - iVar3) + local_224;
    aiStack_200[3] = param_1[7];
    fStack_210 = 0.0;
    aiStack_1e0[2] = param_1[6] - iVar6;
    aiStack_200[2] = param_1[7] - iVar3;
    fStack_20c = DAT_0099d080;
    pfVar7 = afStack_1ac;
    local_228 = 0;
    do {
      fStack_214 = (float)*(int *)((int)aiStack_1d0 + local_228) - DAT_0099d0b4;
      fStack_208 = (float)*(int *)((int)aiStack_200 + local_228);
      iVar6 = 0;
      pfVar8 = pfVar7;
      do {
        iVar3 = *(int *)((int)aiStack_1e0 + iVar6);
        fStack_218 = (float)*(int *)((int)aiStack_1f0 + iVar6) - DAT_0099d0b4;
        pfVar8[-5] = fStack_218;
        pfVar8[-4] = fStack_214;
        pfVar8[-3] = fStack_210;
        pfVar8[-2] = fStack_20c;
        iStack_204 = (**(code **)(*piVar2 + 8))();
        fVar1 = (float)iStack_204;
        if (iStack_204 < 0) {
          fVar1 = fVar1 + _DAT_0099d104;
        }
        *pfVar8 = (float)iVar3 / fVar1;
        iStack_204 = (**(code **)(*piVar2 + 0xc))();
        fVar1 = (float)iStack_204;
        if (iStack_204 < 0) {
          fVar1 = fVar1 + _DAT_0099d104;
        }
        pfVar8[-1] = (float)param_1[0xd];
        iVar6 = iVar6 + 4;
        pfVar7 = pfVar8 + 7;
        pfVar8[1] = fStack_208 / fVar1;
        pfVar8 = pfVar7;
      } while (iVar6 < 0x10);
      local_228 = local_228 + 4;
    } while (local_228 < 0x10);
    iVar6 = *(int *)(DAT_00b5ac04 + 0x28);
    iVar3 = 0;
    if (param_1[3] != 0) {
      piVar2 = (int *)FUN_004af750();
      iVar3 = (**(code **)(*piVar2 + 4))();
    }
    if (*(int *)(iVar6 + 0x134) != iVar3) {
      *(int *)(iVar6 + 0x134) = iVar3;
      (**(code **)(**(int **)(iVar6 + 0x90) + 0x104))(*(int **)(iVar6 + 0x90),0,iVar3);
    }
    uVar4 = 1;
    do {
      iVar6 = 3;
      uVar5 = uVar4;
      do {
        sStack_220 = uVar5 - 1;
        sStack_21c = uVar5 + 3;
        sStack_21a = uVar5 + 4;
        piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
        uStack_21e = uVar5;
        (**(code **)(*piVar2 + 0x150))(piVar2,5,0,0x10,2,&sStack_220,0x65,auStack_1c0,0x1c);
        uVar5 = uVar5 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0xd);
  }
  return;
}


// ==== FUN_0086d590 @ 0x0086d590 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0086d590(void)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
      (*(int *)(iVar1 + 0x11c) != 6)) && (*(int *)(iVar1 + 100) == 0)) {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
    *(undefined4 *)(iVar1 + 0x114) = 2;
    *(undefined4 *)(iVar1 + 0x118) = 5;
    *(undefined4 *)(iVar1 + 0x11c) = 6;
  }
  local_6c = DAT_009b0318;
  local_68 = 0;
  local_70 = DAT_009b0318;
  local_54 = _DAT_00a13628;
  uStack_50 = DAT_009b0318;
  uStack_4c = 0;
  uStack_48 = DAT_0099d080;
  uStack_38 = DAT_009b0318;
  uStack_34 = _DAT_00a13628;
  uStack_30 = 0;
  uStack_2c = DAT_0099d080;
  uStack_64 = DAT_0099d080;
  uStack_1c = _DAT_00a13628;
  uStack_18 = _DAT_00a13628;
  uStack_60 = 0xffffffff;
  uStack_44 = 0xffffffff;
  uStack_28 = 0xffffffff;
  uStack_c = 0xffffffff;
  local_78 = 0;
  uStack_74 = DAT_0099d080;
  uStack_14 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_40 = DAT_0099d080;
  uStack_3c = 0;
  uStack_24 = 0;
  uStack_20 = DAT_0099d080;
  uStack_10 = DAT_0099d080;
  uStack_8 = DAT_0099d080;
  uStack_4 = DAT_0099d080;
  piVar2 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  cVar3 = FUN_00881000(0x1c,0x70);
  if (cVar3 == '\0') {
    (**(code **)(*piVar2 + 0xc))();
  }
  uVar4 = (**(code **)(*piVar2 + 0x1c))(0x1c,0x70);
  (**(code **)(*piVar2 + 0x14))(0x70,&local_78);
  FUN_00881060();
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 400))(piVar2,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x1c)
  ;
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0x144))(piVar2,5,uVar4,2);
  return;
}


// ==== FUN_0086d880 @ 0x0086d880 ====

void FUN_0086d880(int param_1)

{
  int iVar1;
  int *piVar2;
  float local_70;
  float fStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  float fStack_38;
  float fStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(int *)(iVar1 + 0x134) != 0) {
    *(undefined4 *)(iVar1 + 0x134) = 0;
    (**(code **)(**(int **)(iVar1 + 0x90) + 0x104))(*(int **)(iVar1 + 0x90),0,0);
  }
  local_70 = (float)(*(int *)(param_1 + 8) + -4);
  local_68 = 0;
  fStack_54 = (float)(*(int *)(param_1 + 0x10) + 4);
  fStack_6c = (float)(*(int *)(param_1 + 0xc) + -2);
  uStack_4c = 0;
  uStack_48 = DAT_0099d080;
  fStack_34 = (float)(*(int *)(param_1 + 0x14) + 2);
  uStack_30 = 0;
  uStack_2c = DAT_0099d080;
  uStack_64 = DAT_0099d080;
  uStack_60 = 0x7f000000;
  uStack_44 = 0x7f000000;
  uStack_28 = 0x7f000000;
  uStack_c = 0x7f000000;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_14 = 0;
  uStack_10 = DAT_0099d080;
  uStack_8 = 0;
  uStack_4 = 0;
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  fStack_50 = fStack_6c;
  fStack_38 = local_70;
  fStack_1c = fStack_54;
  fStack_18 = fStack_34;
  (**(code **)(*piVar2 + 0x14c))(piVar2,5,2,&local_70,0x1c);
  return;
}


// ==== FUN_0086da40 @ 0x0086da40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0086da40(int *param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  if ((_DAT_00b5da18 & 1) == 0) {
    _DAT_00b5da18 = _DAT_00b5da18 | 1;
  }
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar4 = param_1[8];
  iVar5 = param_1[9];
  if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
      (*(int *)(iVar1 + 0x11c) != 6)) && (*(int *)(iVar1 + 100) == 0)) {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
    *(undefined4 *)(iVar1 + 0x114) = 2;
    *(undefined4 *)(iVar1 + 0x118) = 5;
    *(undefined4 *)(iVar1 + 0x11c) = 6;
  }
  if (param_1[3] != 0) {
    piVar3 = (int *)FUN_004af750();
    if (param_1[8] < 0) {
      iVar4 = (**(code **)(*piVar3 + 8))();
    }
    if (param_1[9] < 0) {
      iVar5 = (**(code **)(*piVar3 + 0xc))();
    }
  }
  _DAT_00b5d9a8 = (float)*param_1 - DAT_0099d0b4;
  _DAT_00b5d9ac = (float)param_1[1] - DAT_0099d0b4;
  _DAT_00b5d9b0 = 0;
  _DAT_00b5d9b4 = DAT_0099d080;
  _DAT_00b5d9b8 = param_1[0xd];
  _DAT_00b5d9bc = 0;
  _DAT_00b5d9c0 = 0;
  _DAT_00b5d9c4 = (float)(*param_1 + iVar4);
  if (*param_1 + iVar4 < 0) {
    _DAT_00b5d9c4 = _DAT_00b5d9c4 + _DAT_0099d104;
  }
  _DAT_00b5d9c4 = _DAT_00b5d9c4 - DAT_0099d0b4;
  _DAT_00b5d9c8 = (float)param_1[1] - DAT_0099d0b4;
  _DAT_00b5d9cc = 0;
  _DAT_00b5d9d0 = DAT_0099d080;
  _DAT_00b5d9d4 = param_1[0xd];
  _DAT_00b5d9dc = 0;
  _DAT_00b5d9d8 = 0;
  _DAT_00b5d9e4 = (float)(param_1[1] + iVar5);
  _DAT_00b5d9e0 = (float)*param_1 - DAT_0099d0b4;
  if (param_1[1] + iVar5 < 0) {
    _DAT_00b5d9e4 = _DAT_00b5d9e4 + _DAT_0099d104;
  }
  _DAT_00b5d9e4 = _DAT_00b5d9e4 - DAT_0099d0b4;
  _DAT_00b5d9e8 = 0;
  _DAT_00b5d9ec = DAT_0099d080;
  _DAT_00b5d9f0 = param_1[0xd];
  _DAT_00b5d9f4 = 0;
  _DAT_00b5d9f8 = 0;
  _DAT_00b5d9fc = (float)(*param_1 + iVar4);
  if (*param_1 + iVar4 < 0) {
    _DAT_00b5d9fc = _DAT_00b5d9fc + _DAT_0099d104;
  }
  _DAT_00b5d9fc = _DAT_00b5d9fc - DAT_0099d0b4;
  _DAT_00b5da00 = (float)(param_1[1] + iVar5);
  if (param_1[1] + iVar5 < 0) {
    _DAT_00b5da00 = _DAT_00b5da00 + _DAT_0099d104;
  }
  _DAT_00b5da00 = _DAT_00b5da00 - DAT_0099d0b4;
  _DAT_00b5da04 = 0;
  _DAT_00b5da08 = DAT_0099d080;
  _DAT_00b5da0c = param_1[0xd];
  _DAT_00b5da10 = 0;
  _DAT_00b5da14 = 0;
  piVar3 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  cVar2 = FUN_00881000(0x1c,0x70);
  if (cVar2 == '\0') {
    (**(code **)(*piVar3 + 0xc))();
  }
  uVar6 = (**(code **)(*piVar3 + 0x1c))(0x1c,0x70);
  (**(code **)(*piVar3 + 0x14))(0x70,&DAT_00b5d9a8);
  FUN_00881060();
  piVar3 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar3 + 400))(piVar3,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x1c)
  ;
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(int *)(iVar1 + 0x134) != 0) {
    *(undefined4 *)(iVar1 + 0x134) = 0;
    (**(code **)(**(int **)(iVar1 + 0x90) + 0x104))(*(int **)(iVar1 + 0x90),0,0);
  }
  piVar3 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar3 + 0x144))(piVar3,5,uVar6,2);
  return;
}


// ==== FUN_0086de30 @ 0x0086de30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0086de30(int *param_1)

{
  int iVar1;
  float fVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  float10 fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  if ((_DAT_00b5da90 & 1) == 0) {
    _DAT_00b5da90 = _DAT_00b5da90 | 1;
  }
  iVar5 = param_1[8];
  iVar6 = param_1[9];
  piVar4 = (int *)FUN_004af750();
  FUN_0086d0f0(param_1[3]);
  if (param_1[8] < 0) {
    iVar5 = (**(code **)(*piVar4 + 8))();
  }
  if (param_1[9] < 0) {
    iVar6 = (**(code **)(*piVar4 + 0xc))();
  }
  iVar1 = param_1[4];
  if ((param_1[6] < iVar1) && (param_1[7] < param_1[5])) {
    fVar11 = 0.0;
    fVar10 = 0.0;
    _DAT_00b5da70 = DAT_0099d080;
    fVar13 = DAT_0099d080;
  }
  else {
    iVar7 = (**(code **)(*piVar4 + 8))();
    fVar11 = (float)iVar7;
    if (iVar7 < 0) {
      fVar11 = fVar11 + _DAT_0099d104;
    }
    fVar11 = (float)iVar1 / fVar11;
    iVar1 = param_1[5];
    iVar7 = (**(code **)(*piVar4 + 0xc))();
    fVar10 = (float)iVar7;
    if (iVar7 < 0) {
      fVar10 = fVar10 + _DAT_0099d104;
    }
    fVar10 = (float)iVar1 / fVar10;
    iVar1 = param_1[6];
    iVar7 = (**(code **)(*piVar4 + 8))();
    fVar13 = (float)iVar7;
    if (iVar7 < 0) {
      fVar13 = fVar13 + _DAT_0099d104;
    }
    fVar13 = (float)iVar1 / fVar13;
    iVar1 = param_1[7];
    iVar7 = (**(code **)(*piVar4 + 0xc))();
    _DAT_00b5da70 = (float)iVar7;
    if (iVar7 < 0) {
      _DAT_00b5da70 = _DAT_00b5da70 + _DAT_0099d104;
    }
    _DAT_00b5da70 = (float)iVar1 / _DAT_00b5da70;
  }
  _DAT_00b5da30 = param_1[0xd];
  _DAT_00b5da4c = param_1[0xd];
  _DAT_00b5da68 = param_1[0xd];
  _DAT_00b5da84 = param_1[0xd];
  DAT_00b5da20 = (float)*param_1 - DAT_0099d0b4;
  DAT_00b5da24 = (float)param_1[1] - DAT_0099d0b4;
  DAT_00b5da28 = 0;
  fVar2 = (float)(*param_1 + iVar5);
  if (*param_1 + iVar5 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  DAT_00b5da3c = fVar2 - DAT_0099d0b4;
  DAT_00b5da40 = (float)param_1[1] - DAT_0099d0b4;
  DAT_00b5da44 = 0;
  fVar2 = (float)(param_1[1] + iVar6);
  DAT_00b5da58 = (float)*param_1 - DAT_0099d0b4;
  if (param_1[1] + iVar6 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  DAT_00b5da5c = fVar2 - DAT_0099d0b4;
  DAT_00b5da60 = 0;
  fVar2 = (float)(*param_1 + iVar5);
  if (*param_1 + iVar5 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  DAT_00b5da74 = fVar2 - DAT_0099d0b4;
  fVar2 = (float)(param_1[1] + iVar6);
  if (param_1[1] + iVar6 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  DAT_00b5da78 = fVar2 - DAT_0099d0b4;
  DAT_00b5da7c = 0;
  DAT_00b5da2c = DAT_0099d080;
  _DAT_00b5da34 = fVar11;
  _DAT_00b5da38 = fVar10;
  DAT_00b5da48 = DAT_0099d080;
  _DAT_00b5da50 = fVar13;
  _DAT_00b5da54 = fVar10;
  DAT_00b5da64 = DAT_0099d080;
  _DAT_00b5da6c = fVar11;
  DAT_00b5da80 = DAT_0099d080;
  _DAT_00b5da88 = fVar13;
  _DAT_00b5da8c = _DAT_00b5da70;
  if ((char)param_1[0xe] != '\0') {
    fVar9 = (float10)FUN_0040d4c0(param_1[0xf]);
    fVar11 = (float)fVar9;
    fVar9 = (float10)FUN_0040d4d0(param_1[0xf]);
    fVar10 = (float)fVar9;
    fVar13 = (float)iVar5;
    if (iVar5 < 0) {
      fVar13 = fVar13 + _DAT_0099d104;
    }
    fVar13 = fVar13 * DAT_0099d0b4 + (float)*param_1;
    fVar2 = (float)iVar6;
    if (iVar6 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar2 = fVar2 * DAT_0099d0b4 + (float)param_1[1];
    fVar14 = DAT_00b5da20 - fVar13;
    DAT_00b5da20 = fVar14 * fVar10 + (DAT_00b5da24 - fVar2) * fVar11 + fVar13;
    fVar12 = 0.0 - fVar11;
    DAT_00b5da24 = (DAT_00b5da24 - fVar2) * fVar10 + fVar12 * fVar14 + fVar2;
    fVar14 = DAT_00b5da3c - fVar13;
    DAT_00b5da3c = fVar14 * fVar10 + (DAT_00b5da40 - fVar2) * fVar11 + fVar13;
    DAT_00b5da40 = (DAT_00b5da40 - fVar2) * fVar10 + fVar12 * fVar14 + fVar2;
    fVar14 = DAT_00b5da58 - fVar13;
    DAT_00b5da58 = fVar14 * fVar10 + (DAT_00b5da5c - fVar2) * fVar11 + fVar13;
    DAT_00b5da5c = (DAT_00b5da5c - fVar2) * fVar10 + fVar12 * fVar14 + fVar2;
    fVar14 = DAT_00b5da78 - fVar2;
    DAT_00b5da78 = fVar14 * fVar10 + fVar12 * (DAT_00b5da74 - fVar13) + fVar2;
    DAT_00b5da74 = (DAT_00b5da74 - fVar13) * fVar10 + fVar14 * fVar11 + fVar13;
  }
  piVar4 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar4 + 400))(piVar4,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x1c)
  ;
  piVar4 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  cVar3 = FUN_00881000(0x1c,0x70);
  if (cVar3 == '\0') {
    (**(code **)(*piVar4 + 0xc))();
  }
  uVar8 = (**(code **)(*piVar4 + 0x1c))(0x1c,0x70);
  (**(code **)(*piVar4 + 0x14))(0x70,&DAT_00b5da20);
  FUN_00881060();
  iVar5 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar6 = 0;
  if (param_1[3] != 0) {
    piVar4 = (int *)FUN_004af750();
    iVar6 = (**(code **)(*piVar4 + 4))();
  }
  if (*(int *)(iVar5 + 0x134) != iVar6) {
    *(int *)(iVar5 + 0x134) = iVar6;
    (**(code **)(**(int **)(iVar5 + 0x90) + 0x104))(*(int **)(iVar5 + 0x90),0,iVar6);
  }
  piVar4 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar4 + 0x144))(piVar4,5,uVar8,2);
  return;
}


// ==== FUN_0086e590 @ 0x0086e590 ====

/* WARNING: Type propagation algorithm not settling */

void FUN_0086e590(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  undefined4 *puVar7;
  HDC hdc;
  BOOL BVar8;
  undefined4 *puVar9;
  int in_ECX;
  LPCSTR ******lpString;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  uint uVar13;
  undefined4 *puVar14;
  int iStack_74;
  undefined4 *puStack_70;
  tagSIZE tStack_58;
  undefined4 uStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  LPCSTR ******local_3c [4];
  int local_2c;
  uint local_28;
  undefined1 local_24 [4];
  void *local_20;
  undefined4 local_10;
  uint local_c;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x24c);
  puVar11 = (undefined4 *)*puVar2;
  puVar7 = puVar11;
  do {
    if (puVar11 == puVar2) {
      return;
    }
    puVar9 = (undefined4 *)puVar11[6];
    puVar14 = (undefined4 *)puVar11[5];
    puVar10 = puVar11;
    if (puVar14 != puVar9) {
      do {
        FUN_0086d880(puVar14);
        if (0xd < (uint)puVar14[1]) {
          local_c = 0xf;
          local_10 = 0;
          local_20 = (void *)((uint)local_20 & 0xffffff00);
          FUN_00401740(s_CdwIndex_<_NUM_FONT_00a1362b + 1,0x12);
          FUN_00406880(local_24);
          if (local_c < 0x10) {
            local_c = 0xf;
            local_10 = 0;
            local_20 = (void *)((uint)local_20 & 0xffffff00);
            pcVar6 = (code *)swi(3);
            (*pcVar6)();
            return;
          }
          _free(local_20);
          return;
        }
        piVar3 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x168 + puVar14[1] * 4);
        local_28 = 0xf;
        local_2c = 0;
        local_3c[0] = (LPCSTR ******)((uint)local_3c[0] & 0xffffff00);
        FUN_00401740(&DAT_00a13608,1);
        piVar4 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x168 + puVar14[1] * 4);
        hdc = (HDC)(**(code **)(*piVar4 + 0x20))(piVar4);
        lpString = local_3c[0];
        if (local_28 < 0x10) {
          lpString = (LPCSTR ******)local_3c;
        }
        BVar8 = GetTextExtentPoint32A(hdc,(LPCSTR)lpString,local_2c,&tStack_58);
        uVar13 = -(uint)(BVar8 != 0) & tStack_58.cy;
        if (0xf < local_28) {
          _free(local_3c[0]);
          return;
        }
        iVar5 = puVar14[7];
        iVar12 = puVar14[8];
        local_28 = 0xf;
        local_2c = 0;
        local_3c[0] = (LPCSTR ******)((uint)local_3c[0] & 0xffffff00);
        if (iVar12 != iVar5) {
          iStack_74 = 0;
          puVar11 = (undefined4 *)(iVar12 + -0x18);
          do {
            uStack_50 = puVar14[2];
            uStack_48 = puVar14[4];
            iStack_44 = puVar14[5] - iStack_74;
            iStack_4c = iStack_44 - uVar13;
            if ((uint)puVar11[5] < 0x10) {
              puStack_70 = puVar11;
            }
            else {
              puStack_70 = (undefined4 *)*puVar11;
            }
            (**(code **)(*piVar3 + 0x38))(piVar3,0,puStack_70,0xffffffff,&uStack_50,0,*puVar14);
            iStack_74 = iStack_74 + uVar13;
            iVar12 = iVar12 + -0x1c;
            puVar11 = puVar11 + -7;
          } while (iVar12 != iVar5);
        }
        puVar14 = puVar14 + 10;
      } while (puVar14 != puVar9);
      puVar10 = puVar7;
    }
    puVar11 = puVar10;
    if (*(char *)((int)puVar10 + 0x21) == '\0') {
      puVar11 = (undefined4 *)puVar10[2];
      if (*(char *)((int)puVar11 + 0x21) == '\0') {
        cVar1 = *(char *)((int)*puVar11 + 0x21);
        puVar9 = (undefined4 *)*puVar11;
        while (puVar7 = puVar11, cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar9 + 0x21);
          puVar11 = puVar9;
          puVar9 = (undefined4 *)*puVar9;
        }
      }
      else {
        puVar11 = (undefined4 *)puVar10[1];
        puVar7 = puVar11;
        if (*(char *)((int)puVar11 + 0x21) == '\0') {
          while ((puVar9 = puVar11, puVar11 = puVar9, puVar7 = puVar9,
                 puVar10 == (undefined4 *)puVar9[2] &&
                 (puVar11 = (undefined4 *)puVar9[1], puVar7 = puVar11,
                 *(char *)((int)puVar11 + 0x21) == '\0'))) {
            puVar10 = puVar9;
          }
        }
      }
    }
  } while( true );
}


// ==== FUN_0086e7e0 @ 0x0086e7e0 ====

void FUN_0086e7e0(int param_1)

{
  undefined4 local_10;
  int local_c;
  undefined1 local_8 [8];
  
  local_10 = *(undefined4 *)(param_1 + 8);
  local_c = param_1;
  FUN_0086fc00(local_8,&local_10);
  return;
}


// ==== FUN_0086e810 @ 0x0086e810 ====

/* WARNING: Removing unreachable block (ram,0x0086e849) */
/* WARNING: Removing unreachable block (ram,0x0086e850) */
/* WARNING: Removing unreachable block (ram,0x0086e85e) */

void FUN_0086e810(void)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
  int local_8;
  int local_4;
  
  piVar2 = (int *)(in_ECX + 0x18);
  iVar1 = 0xe;
  local_4 = in_ECX;
  do {
    FUN_0059c2f0();
    local_8 = piVar2[-4];
    if (piVar2[-1] != *piVar2) {
      *piVar2 = piVar2[-1];
    }
    FUN_0086fd30(piVar2[-1],9,&local_8);
    piVar2[2] = 1;
    piVar2[3] = 1;
    piVar2 = piVar2 + 10;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(local_4 + 0x230) = 0;
  return;
}


// ==== FUN_0086e8a0 @ 0x0086e8a0 ====

void FUN_0086e8a0(void)

{
  int in_ECX;
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_9;
  undefined4 local_8;
  int local_4;
  
  puVar1 = (undefined4 *)(in_ECX + 0xc);
  iVar2 = 0xe;
  local_4 = in_ECX;
  do {
    *(undefined1 *)(puVar1 + -3) = local_9;
    local_8 = FUN_0086f7f0();
    puVar1[-1] = local_8;
    *puVar1 = 0;
    FUN_00870010(9,&local_8);
    puVar1[5] = 1;
    puVar1[6] = 1;
    puVar1 = puVar1 + 10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(local_4 + 0x230) = 0;
  return;
}


// ==== FUN_0086e910 @ 0x0086e910 ====

void FUN_0086e910(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined1 local_2c [8];
  undefined1 local_24 [4];
  void *local_20;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar5 = param_2;
  iVar4 = param_1;
  iVar1 = param_1 * 0x28;
  FUN_0041ec50(&param_1,param_2);
  if (param_1 != *(int *)(in_ECX + iVar1 + 8)) {
    *param_3 = *(undefined4 *)(param_1 + 0x24);
    *param_4 = *(undefined4 *)(param_1 + 0x28);
    return;
  }
  if (300 < *(uint *)(in_ECX + 0x230)) {
    FUN_0086e810();
  }
  puVar6 = param_4;
  FUN_0086f570(iVar4,uVar5,param_3,param_4);
  uVar2 = *param_3;
  uVar3 = *puVar6;
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401660(uVar5,0,0xffffffff);
  local_8 = uVar2;
  local_4 = uVar3;
  FUN_00870130(local_2c,local_24);
  if (local_c < 0x10) {
    *(int *)(in_ECX + 0x230) = *(int *)(in_ECX + 0x230) + 1;
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_0086ea00 @ 0x0086ea00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0086ea00(undefined4 *param_1,float *param_2,undefined4 *param_3)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  char cVar5;
  undefined4 uVar6;
  undefined4 extraout_EAX;
  undefined4 *puVar7;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  HDC hdc;
  BOOL BVar8;
  int iVar9;
  LPCSTR lpString;
  int unaff_EBX;
  uint unaff_EBP;
  float fVar10;
  undefined4 *puVar11;
  int iVar12;
  float fVar13;
  uint uVar14;
  tagSIZE tStack_84;
  float afStack_78 [4];
  undefined1 local_68 [4];
  void *local_64;
  undefined4 uStack_54;
  uint local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  undefined4 auStack_40 [16];
  
  param_3[1] = 3;
  *param_3 = *param_1;
  if (param_1[9] != 0) {
    FUN_00401740(&DAT_00a1360c,4);
    uVar6 = FUN_00404230(local_68);
    FUN_00406720(uVar6);
    if (0xf < local_50) {
      _free(local_64);
      return extraout_EAX;
    }
  }
  fVar1 = (float)param_1[0x10];
  if (fVar1 != 0.0) {
    fVar10 = 0.0;
    if ((uint)fVar1 < 0x1f) {
      FUN_00406720(param_1 + 0xb);
    }
    else {
      do {
        if ((uint)param_1[0x10] <= (uint)fVar10) {
          FUN_0079dba3();
        }
        if ((uint)param_1[0x11] < 0x10) {
          puVar7 = param_1 + 0xc;
        }
        else {
          puVar7 = (undefined4 *)param_1[0xc];
        }
        cVar5 = FUN_00403d70((int)*(char *)((int)puVar7 + (int)fVar10));
        if (cVar5 == '\0') {
          fVar10 = (float)((int)fVar10 + 1);
        }
        else {
          if (fVar10 == 4.06377e-44) {
            fVar10 = 4.34403e-44;
            break;
          }
          if (fVar10 == 4.2039e-44) break;
          fVar10 = (float)((int)fVar10 + 2);
        }
      } while ((int)fVar10 < 0x1f);
      local_50 = 0xf;
      uStack_54 = 0;
      local_64 = (void *)((uint)local_64 & 0xffffff00);
      FUN_00401660(param_1 + 0xb,0,fVar10);
      FUN_00406720(local_68);
      if (0xf < local_50) {
        _free(local_64);
        return extraout_EAX_00;
      }
      if ((uint)fVar10 < (uint)fVar1) {
        local_50 = 0xf;
        uStack_54 = 0;
        local_64 = (void *)((uint)local_64 & 0xffffff00);
        FUN_00401660(param_1 + 0xb,fVar10,fVar1);
        FUN_00406720(local_68);
        if (0xf < local_50) {
          _free(local_64);
          return extraout_EAX_01;
        }
      }
    }
  }
  if ((param_3[7] == 0) || ((int)(param_3[8] - param_3[7]) / 0x1c == 0)) {
    return 0;
  }
  fStack_4c = (float)param_1[1] + *param_2;
  fStack_48 = (float)param_1[2] + param_2[1];
  fStack_44 = (float)param_1[3] + param_2[2];
  puVar7 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
  puVar11 = auStack_40;
  for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar11 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar11 = puVar11 + 1;
  }
  thunk_FUN_0079e43e(afStack_78,&fStack_4c,auStack_40);
  fVar13 = DAT_0099d080 / afStack_78[0];
  afStack_78[0] = fVar13 * afStack_78[0];
  iVar9 = *(int *)(DAT_00b5ac04 + 0x28);
  fVar10 = (float)*(int *)(iVar9 + 0xa0);
  if (*(int *)(iVar9 + 0xa0) < 0) {
    fVar10 = fVar10 + _DAT_0099d104;
  }
  fVar10 = (fVar13 * (float)tStack_84.cx + DAT_0099d080) * fVar10 * DAT_0099d0b4;
  fVar4 = (float)*(int *)(iVar9 + 0x9c);
  if (*(int *)(iVar9 + 0x9c) < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  iVar2 = param_3[8];
  iVar12 = 0;
  uVar14 = 0;
  fVar1 = (DAT_0099d080 - fVar13 * fVar1) * fVar4 * DAT_0099d0b4 - DAT_0099d100;
  for (iVar9 = param_3[7]; iVar9 != iVar2; iVar9 = iVar9 + 0x1c) {
    piVar3 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x168 + param_3[1] * 4);
    hdc = (HDC)(**(code **)(*piVar3 + 0x20))(piVar3);
    if (*(uint *)(iVar9 + 0x18) < 0x10) {
      lpString = (LPCSTR)(iVar9 + 4);
    }
    else {
      lpString = *(LPCSTR *)(iVar9 + 4);
    }
    BVar8 = GetTextExtentPoint32A(hdc,lpString,*(int *)(iVar9 + 0x14),(LPSIZE)(afStack_78 + -7));
    if (BVar8 == 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = unaff_EBX;
      if (uVar14 < unaff_EBP) {
        uVar14 = unaff_EBP;
      }
    }
  }
  fVar13 = (float)(int)uVar14;
  if ((int)uVar14 < 0) {
    fVar13 = fVar13 + _DAT_0099d104;
  }
  fVar13 = fVar13 * DAT_0099d0b4;
  param_3[2] = (int)ROUND(fVar10 - fVar13);
  param_3[4] = (int)ROUND(fVar10 + fVar13);
  iVar9 = 0;
  if (param_3[7] != 0) {
    iVar9 = (int)(param_3[8] - param_3[7]) / 0x1c;
  }
  fVar10 = (float)(iVar9 * iVar12);
  if (iVar9 * iVar12 < 0) {
    fVar10 = fVar10 + _DAT_0099d104;
  }
  iVar9 = (int)fVar1;
  param_3[5] = iVar9;
  param_3[3] = (int)ROUND(fVar1 - fVar10);
  return CONCAT31((int3)((uint)iVar9 >> 8),1);
}


// ==== FUN_0086ee10 @ 0x0086ee10 ====

void FUN_0086ee10(int *param_1)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  undefined4 uVar6;
  int *piVar7;
  int unaff_EBP;
  undefined4 uVar8;
  int iVar9;
  uint local_58;
  uint local_54;
  uint local_50;
  int local_4c;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  float local_10;
  float local_c;
  float local_8;
  
  if ((param_1[0x11] != 0) && ((param_1[0x12] - param_1[0x11]) / 0x2c != 0)) {
    local_44 = param_1[0x12];
    local_48 = param_1[9];
    local_50 = param_1[8];
    iVar9 = param_1[0x11];
    if (iVar9 != local_44) {
      local_4c = in_ECX + 0x14;
      do {
        uVar1 = local_50;
        piVar3 = (int *)FUN_0086fb20(*(undefined4 *)(iVar9 + 0x24));
        FUN_0086e910(*(undefined4 *)(iVar9 + 0x24),iVar9,&local_58,&local_54);
        if (uVar1 < local_58) {
          local_58 = uVar1;
        }
        if (local_48 < local_54) {
          local_54 = local_48;
        }
        local_40 = *(int *)(iVar9 + 0x1c) + *param_1;
        local_3c = *(int *)(iVar9 + 0x20) + param_1[1];
        local_38 = local_40 + local_58;
        local_34 = local_3c + local_54;
        cVar2 = FUN_0086fb90(*(undefined4 *)(iVar9 + 0x24));
        if (cVar2 != '\0') {
          FUN_0040e8c0(&local_10,*(undefined4 *)(iVar9 + 0x28));
          if (((DAT_0099d0b4 <= local_10) || (DAT_0099d0b4 <= local_c)) || (DAT_0099d0b4 <= local_8)
             ) {
            uVar6 = 0xff404040;
            uVar8 = 0xffc0c0c0;
          }
          else {
            uVar6 = 0xffc0c0c0;
            uVar8 = 0xff909090;
          }
          local_30 = local_40 + 2;
          local_2c = local_3c + 1;
          local_28 = local_38 + 2;
          local_24 = local_34 + 1;
          piVar7 = (int *)(iVar9 + 4);
          if (*(uint *)(iVar9 + 0x18) < 0x10) {
            piVar4 = piVar7;
          }
          else {
            piVar4 = (int *)*piVar7;
          }
          (**(code **)(*piVar3 + 0x38))(piVar3,0,piVar4,0xffffffff,&local_30,0,uVar6);
          local_3c = unaff_EBP + 1;
          local_34 = local_54 + 1;
          local_38 = local_58;
          local_30 = local_50;
          if (0xf < *(uint *)(iVar9 + 0x18)) {
            piVar7 = (int *)*piVar7;
          }
          (**(code **)(*piVar3 + 0x38))(piVar3,0,piVar7,0xffffffff,&local_3c,0,uVar8);
        }
        if (*(uint *)(iVar9 + 0x18) < 0x10) {
          iVar5 = iVar9 + 4;
        }
        else {
          iVar5 = *(int *)(iVar9 + 4);
        }
        (**(code **)(*piVar3 + 0x38))
                  (piVar3,0,iVar5,0xffffffff,&local_40,0,*(undefined4 *)(iVar9 + 0x28));
        iVar9 = iVar9 + 0x2c;
      } while (iVar9 != local_44);
    }
  }
  return;
}


// ==== FUN_0086f020 @ 0x0086f020 ====

void FUN_0086f020(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int in_ECX;
  int *unaff_EBP;
  int unaff_ESI;
  
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x79) == '\0') {
    return;
  }
  piVar9 = (int *)FUN_0049b670();
  FUN_00858a60();
  (**(code **)(*piVar9 + 0x164))(piVar9,0x144);
  puVar3 = *(undefined4 **)(in_ECX + 8);
  puVar4 = (undefined4 *)*puVar3;
  while (puVar4 != puVar3) {
    iVar5 = puVar4[4];
    if (*(char *)(iVar5 + 0x30) != '\0') {
      FUN_0086da40(iVar5);
    }
    if (*(int *)(iVar5 + 0xc) != 0) {
      if (*(int *)(iVar5 + 0x28) == 0) {
        FUN_0086de30(iVar5);
      }
      else {
        FUN_0086d2d0(iVar5);
      }
    }
    FUN_0086ee10(iVar5);
    if (*(char *)((int)puVar4 + 0x15) == '\0') {
      puVar6 = (undefined4 *)puVar4[2];
      if (*(char *)((int)puVar6 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar6 + 0x15);
        puVar4 = puVar6;
        puVar6 = (undefined4 *)*puVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x15);
          puVar4 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar4[1] + 0x15);
        puVar8 = (undefined4 *)puVar4[1];
        puVar6 = puVar4;
        while ((puVar4 = puVar8, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar4[2]))) {
          cVar1 = *(char *)((int)puVar4[1] + 0x15);
          puVar8 = (undefined4 *)puVar4[1];
          puVar6 = puVar4;
        }
      }
    }
  }
  FUN_0086e590();
  piVar7 = DAT_00b5af70;
  bVar2 = *(byte *)(in_ECX + 0x10);
  if (bVar2 != 0) {
    uVar10 = FUN_0049b670();
    uVar11 = (**(code **)(*piVar7 + 4))(bVar2 - 1);
    (**(code **)(unaff_ESI + 0x104))(uVar10,0,uVar11);
    FUN_0086d590();
    piVar9 = unaff_EBP;
  }
  (**(code **)(*piVar9 + 0x164))(piVar9,0);
  FUN_00858b90();
  return;
}


// ==== FUN_0086f170 @ 0x0086f170 ====

void FUN_0086f170(void)

{
  int in_ECX;
  
  FUN_0086f5e0(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
  *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  FUN_008714f0(*(undefined4 *)(*(int *)(in_ECX + 0x24c) + 4));
  *(int *)(*(int *)(in_ECX + 0x24c) + 4) = *(int *)(in_ECX + 0x24c);
  *(undefined4 *)(in_ECX + 0x250) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x24c) = *(undefined4 *)(in_ECX + 0x24c);
  *(int *)(*(int *)(in_ECX + 0x24c) + 8) = *(int *)(in_ECX + 0x24c);
  return;
}


// ==== FUN_0086f1d0 @ 0x0086f1d0 ====

void FUN_0086f1d0(int *param_1)

{
  int iVar1;
  void *_Memory;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  void *_Memory_00;
  undefined4 *puVar7;
  float fVar8;
  undefined1 *puVar9;
  int iStack_a0;
  float afStack_9c [2];
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  void *pvStack_80;
  int iStack_7c;
  undefined1 auStack_74 [24];
  undefined1 auStack_5c [4];
  void *pvStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 auStack_40 [16];
  
  uVar3 = (**(code **)(*param_1 + 0x9c))();
  FUN_0086c6e0(uVar3);
  if (pvStack_80 == (void *)0x0) {
    iStack_a0 = 0;
  }
  else {
    iStack_a0 = iStack_7c - (int)pvStack_80 >> 2;
  }
  uVar5 = 0;
  _Memory_00 = pvStack_80;
  if (0 < iStack_a0) {
    do {
      if ((_Memory_00 == (void *)0x0) || ((uint)(iStack_7c - (int)_Memory_00 >> 2) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      puVar6 = *(undefined4 **)((int)_Memory_00 + uVar5 * 4);
      iVar1 = puVar6[0x13];
      uStack_4c = *puVar6;
      uStack_48 = puVar6[1];
      uStack_44 = puVar6[2];
      pvStack_58 = (void *)0x0;
      uStack_54 = 0;
      uStack_50 = 0;
      if (iVar1 != 0) {
        cVar2 = FUN_0086ea00(iVar1,&uStack_4c,auStack_74);
        if (cVar2 != '\0') {
          puVar6 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
          puVar7 = auStack_40;
          for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          thunk_FUN_0079e43e(&fStack_94,iVar1 + 4,auStack_40);
          fVar8 = DAT_0099d080 / fStack_88;
          fStack_94 = fStack_94 * fVar8;
          fStack_90 = fStack_90 * fVar8;
          puVar9 = auStack_74;
          afStack_9c[0] = fVar8 * fStack_8c;
          fStack_88 = fVar8 * fStack_88;
          fStack_8c = afStack_9c[0];
          FUN_00871560(afStack_9c);
          FUN_00870c90(puVar9);
          _Memory_00 = pvStack_80;
        }
        _Memory = pvStack_58;
        if (pvStack_58 != (void *)0x0) {
          FUN_00405de0(pvStack_58,uStack_54,auStack_5c,afStack_9c[0]);
          _free(_Memory);
          return;
        }
      }
      uVar5 = uVar5 + 1;
      pvStack_58 = (void *)0x0;
      uStack_54 = 0;
      uStack_50 = 0;
    } while ((int)uVar5 < iStack_a0);
  }
  if (_Memory_00 == (void *)0x0) {
    return;
  }
  _free(_Memory_00);
  return;
}


// ==== FUN_0086f390 @ 0x0086f390 ====

void FUN_0086f390(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_18;
  int iStack_14;
  undefined1 auStack_10 [12];
  
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x79) != '\0') {
    iVar1 = (**(code **)(*param_1 + 0xac))();
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        iStack_14 = (**(code **)(*param_1 + 0xb0))(iVar2);
        uStack_18 = *(undefined4 *)(iStack_14 + 8);
        FUN_0086fc00(auStack_10,&uStack_18);
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    FUN_0086f1d0(param_1);
  }
  return;
}


// ==== FUN_0086f410 @ 0x0086f410 ====

void FUN_0086f410(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a13644;
  FUN_00871630(local_4,*(undefined4 *)in_ECX[0x93],(undefined4 *)in_ECX[0x93]);
  _free((void *)in_ECX[0x93]);
  return;
}


// ==== FUN_0086f490 @ 0x0086f490 ====

void FUN_0086f490(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13644;
  iVar1 = FUN_0086f6c0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_0086e8a0();
  iVar1 = FUN_0086f620();
  in_ECX[0x93] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(undefined4 *)(in_ECX[0x93] + 4) = in_ECX[0x93];
  *(undefined4 *)in_ECX[0x93] = in_ECX[0x93];
  *(undefined4 *)(in_ECX[0x93] + 8) = in_ECX[0x93];
  in_ECX[0x94] = 0;
  return;
}


// ==== FUN_0086f500 @ 0x0086f500 ====

int FUN_0086f500(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a3c0;
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


// ==== Catch@0086f566 @ 0x0086f566 ====

void Catch_0086f566(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0086f570 @ 0x0086f570 ====

void FUN_0086f570(int param_1,undefined4 *param_2,LONG *param_3)

{
  HDC hdc;
  BOOL BVar1;
  int in_ECX;
  LPCSTR lpString;
  tagSIZE tStack_c;
  
  tStack_c.cx = *(undefined4 *)(in_ECX + 0x168 + param_1 * 4);
  hdc = (HDC)(**(code **)(*(int *)tStack_c.cx + 0x20))();
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    lpString = (LPCSTR)(param_1 + 4);
  }
  else {
    lpString = *(LPCSTR *)(param_1 + 4);
  }
  BVar1 = GetTextExtentPoint32A(hdc,lpString,*(int *)(param_1 + 0x14),&tStack_c);
  if (BVar1 == 0) {
    *param_2 = 0;
    *param_3 = 0;
    return;
  }
  *param_2 = tStack_c.cx;
  *param_3 = tStack_c.cy;
  return;
}


// ==== FUN_0086f5e0 @ 0x0086f5e0 ====

void FUN_0086f5e0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0086f5e0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0086f620 @ 0x0086f620 ====

void FUN_0086f620(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a3d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 8) = 1;
  *(undefined1 *)((int)puVar1 + 0x21) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0086f6aa @ 0x0086f6aa ====

void Catch_0086f6aa(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0086f6c0 @ 0x0086f6c0 ====

void FUN_0086f6c0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a3e0;
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


// ==== Catch@0086f74a @ 0x0086f74a ====

void Catch_0086f74a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0086f760 @ 0x0086f760 ====

void * FUN_0086f760(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a3f0;
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


// ==== Catch@0086f7d5 @ 0x0086f7d5 ====

void Catch_0086f7d5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0086f7f0 @ 0x0086f7f0 ====

void FUN_0086f7f0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a400;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x2c);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0086f85f @ 0x0086f85f ====

void Catch_0086f85f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0086f880 @ 0x0086f880 ====

void FUN_0086f880(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a410;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00897070(param_1,param_3);
    param_1 = param_1 + 4;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0086f8e6 @ 0x0086f8e6 ====

void Catch_0086f8e6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0086f8f0 @ 0x0086f8f0 ====

void FUN_0086f8f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0086f500(param_1,param_2,param_3);
  return;
}


// ==== FUN_0086f910 @ 0x0086f910 ====

int FUN_0086f910(int param_1,int param_2,undefined4 param_3)

{
  FUN_0086f880(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_0086f940 @ 0x0086f940 ====

void FUN_0086f940(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_0086f760(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_0086fa45:
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
      if ((char)piVar6[5] == '\0') goto LAB_0086fa45;
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


// ==== FUN_0086fb20 @ 0x0086fb20 ====

undefined4 FUN_0086fb20(uint param_1)

{
  code *pcVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (param_1 < 0xe) {
    return *(undefined4 *)(in_ECX + 0x168 + param_1 * 4);
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_CdwIndex_<_NUM_FONT_00a1362b + 1,0x12);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0086fb90 @ 0x0086fb90 ====

uint FUN_0086fb90(uint param_1)

{
  code *pcVar1;
  uint extraout_EAX;
  uint uVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (param_1 < 0xe) {
    return (uint)*(byte *)(param_1 + 0x520 + in_ECX);
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_CdwIndex_<_NUM_FONT_00a1362b + 1,0x12);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0086fc00 @ 0x0086fc00 ====

void FUN_0086fc00(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  bVar1 = true;
  if (*(char *)((int)puVar3[1] + 0x15) == '\0') {
    puVar2 = (undefined4 *)puVar3[1];
    do {
      puVar3 = puVar2;
      bVar1 = *param_2 < (int)puVar3[3];
      if (bVar1) {
        puVar2 = (undefined4 *)*puVar3;
      }
      else {
        puVar2 = (undefined4 *)puVar3[2];
      }
    } while (*(char *)((int)puVar2 + 0x15) == '\0');
  }
  puVar3 = (undefined4 *)FUN_0086f940(&param_2,bVar1,puVar3,param_2);
  *param_1 = *puVar3;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_0086fd30 @ 0x0086fd30 ====

void FUN_0086fd30(int param_1,uint param_2,undefined4 *param_3)

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
  undefined1 auStack_32 [26];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a420;
  local_10 = ExceptionList;
  local_14 = auStack_32 + -0xe;
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
    puVar1 = auStack_32 + -0xe;
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
      uVar5 = FUN_0086f8f0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_0086f910(uVar5,param_2,&local_18);
      FUN_0086f8f0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_0086f500(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_0086f910(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_0086f500(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0086fe91 @ 0x0086fe91 ====

void Catch_0086fe91(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0086ff80 @ 0x0086ff80 ====

void * FUN_0086ff80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a430;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x2c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_008736f0(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0086ffed @ 0x0086ffed ====

void Catch_0086ffed(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


