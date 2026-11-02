// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x4a0000-0x4affff

// ==== FUN_004a0000 @ 0x004a0000 ====

void FUN_004a0000(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  int *_Memory;
  int local_4;
  
  iVar1 = param_1;
  local_4 = in_ECX;
  param_1 = FUN_004a08b0(param_1);
  if ((param_1 == *(int *)(in_ECX + 0x14)) ||
     (cVar2 = FUN_004a0860(iVar1,param_1 + 0xc), cVar2 != '\0')) {
    local_4 = *(int *)(in_ECX + 0x14);
    piVar3 = &local_4;
  }
  else {
    piVar3 = &param_1;
  }
  if (*piVar3 != *(int *)(in_ECX + 0x14)) {
    FUN_004a0be0(&param_1,*piVar3);
    piVar3 = *(int **)(in_ECX + 8);
    _Memory = (int *)*piVar3;
    if (_Memory != piVar3) {
      do {
        if (_Memory[9] == *(int *)(iVar1 + 0x1c)) {
          if (*(uint *)(iVar1 + 0x18) < 0x10) {
            iVar4 = iVar1 + 4;
          }
          else {
            iVar4 = *(int *)(iVar1 + 4);
          }
          iVar4 = FUN_00403620(0,_Memory[7],iVar4,*(undefined4 *)(iVar1 + 0x14));
          if (iVar4 == 0) {
            if (_Memory == *(int **)(in_ECX + 8)) {
              return;
            }
            *(int *)_Memory[1] = *_Memory;
            *(int *)(*_Memory + 4) = _Memory[1];
            FUN_006c1c60();
            _free(_Memory);
            return;
          }
        }
        _Memory = (int *)*_Memory;
        if (_Memory == piVar3) {
          return;
        }
      } while( true );
    }
  }
  return;
}


// ==== FUN_004a00d0 @ 0x004a00d0 ====

bool FUN_004a00d0(uint param_1)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  uint *puVar4;
  int iVar5;
  uint in_ECX;
  uint local_4;
  
  uVar2 = param_1;
  local_4 = in_ECX;
  param_1 = FUN_004a08b0(param_1);
  if (param_1 != *(uint *)(in_ECX + 0x14)) {
    cVar3 = FUN_004a0860(uVar2,param_1 + 0xc);
    if (cVar3 == '\0') {
      puVar4 = &param_1;
      goto LAB_004a010f;
    }
  }
  local_4 = *(uint *)(in_ECX + 0x14);
  puVar4 = &local_4;
LAB_004a010f:
  if (*puVar4 != *(uint *)(in_ECX + 0x14)) {
    piVar1 = *(int **)(*puVar4 + 0x2c);
    FUN_004a0000(uVar2);
    iVar5 = FUN_004a8060(uVar2);
    if (iVar5 != 0) {
      cVar3 = (**(code **)(*piVar1 + 0x10))(iVar5);
      return cVar3 != '\0';
    }
  }
  return false;
}


// ==== FUN_004a0150 @ 0x004a0150 ====

void FUN_004a0150(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int local_3c;
  int local_38 [2];
  undefined1 local_30 [4];
  void *local_2c;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar2 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ea68;
  local_c = ExceptionList;
  iVar1 = *(int *)(in_ECX + 0x14);
  local_38[0] = in_ECX + 0x10;
  ExceptionList = &local_c;
  param_1 = FUN_004a08b0(param_1);
  if (param_1 != *(int *)(in_ECX + 0x14)) {
    cVar3 = FUN_004a0860(iVar2,param_1 + 0xc);
    if (cVar3 == '\0') {
      piVar4 = &param_1;
      goto LAB_004a01ae;
    }
  }
  local_3c = *(int *)(in_ECX + 0x14);
  piVar4 = &local_3c;
LAB_004a01ae:
  if (*piVar4 == iVar1) {
    iVar1 = *(int *)(in_ECX + 8);
    iVar5 = FUN_004a0a70(iVar1,*(undefined4 *)(iVar1 + 4),iVar2);
    FUN_004a09d0(1);
    *(int *)(iVar1 + 4) = iVar5;
    **(int **)(iVar5 + 4) = iVar5;
    local_18 = 0xf;
    local_1c = 0;
    local_2c = (void *)((uint)local_2c & 0xffffff00);
    FUN_00401660(iVar2,0,0xffffffff);
    local_14 = *(undefined4 *)(iVar2 + 0x1c);
    local_10 = *(undefined4 *)(iVar2 + 0x20);
    local_4 = 0;
    FUN_004a1090(local_38,local_30);
    if (0xf < local_18) {
      _free(local_2c);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004a0250 @ 0x004a0250 ====

void FUN_004a0250(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int local_3c;
  int local_38 [2];
  undefined1 local_30 [4];
  void *local_2c;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar2 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ea7a;
  local_c = ExceptionList;
  iVar1 = *(int *)(in_ECX + 0x14);
  local_38[0] = in_ECX + 0x10;
  ExceptionList = &local_c;
  param_1 = FUN_004a08b0(param_1);
  if (param_1 != *(int *)(in_ECX + 0x14)) {
    cVar3 = FUN_004a0860(iVar2,param_1 + 0xc);
    if (cVar3 == '\0') {
      piVar4 = &param_1;
      goto LAB_004a02ae;
    }
  }
  local_3c = *(int *)(in_ECX + 0x14);
  piVar4 = &local_3c;
LAB_004a02ae:
  if (*piVar4 == iVar1) {
    iVar1 = **(int **)(in_ECX + 8);
    iVar5 = FUN_004a0a70(iVar1,*(undefined4 *)(iVar1 + 4),iVar2);
    FUN_004a09d0(1);
    *(int *)(iVar1 + 4) = iVar5;
    **(int **)(iVar5 + 4) = iVar5;
    local_18 = 0xf;
    local_1c = 0;
    local_2c = (void *)((uint)local_2c & 0xffffff00);
    FUN_00401660(iVar2,0,0xffffffff);
    local_14 = *(undefined4 *)(iVar2 + 0x1c);
    local_10 = *(undefined4 *)(iVar2 + 0x20);
    local_4 = 0;
    FUN_004a1090(local_38,local_30);
    if (0xf < local_18) {
      _free(local_2c);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004a0350 @ 0x004a0350 ====

void FUN_004a0350(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ea97;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009af0a8;
  DAT_00b5ac0c = 0;
  local_4 = 1;
  FUN_004a1190(local_10,*(undefined4 *)in_ECX[5],(undefined4 *)in_ECX[5]);
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_004a03e0 @ 0x004a03e0 ====

int FUN_004a03e0(int param_1)

{
  int iVar1;
  int *_Memory;
  int extraout_EAX;
  int extraout_EAX_00;
  undefined4 uVar2;
  undefined4 uVar3;
  int extraout_EAX_01;
  int in_ECX;
  undefined4 local_34;
  undefined1 local_30 [4];
  void *local_2c;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097eaa9;
  local_c = ExceptionList;
  local_34 = 0;
  iVar1 = **(int **)(in_ECX + 8);
  local_18 = 0xf;
  local_1c = 0;
  local_2c = (void *)((uint)local_2c & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401660(iVar1 + 8,0,0xffffffff);
  local_14 = *(undefined4 *)(iVar1 + 0x24);
  local_10 = *(undefined4 *)(iVar1 + 0x28);
  _Memory = (int *)**(int **)(in_ECX + 8);
  local_4 = 0;
  if (_Memory == *(int **)(in_ECX + 8)) {
    uVar2 = FUN_004a0910(local_30);
    uVar3 = FUN_004a08b0(local_30);
    FUN_004a1190(&local_34,uVar3,uVar2);
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(local_30,0,0xffffffff);
    *(undefined4 *)(param_1 + 0x1c) = local_14;
    *(undefined4 *)(param_1 + 0x20) = local_10;
    if (local_18 < 0x10) {
      ExceptionList = local_c;
      return param_1;
    }
    _free(local_2c);
    return extraout_EAX_01;
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  if ((uint)_Memory[8] < 0x10) {
    _Memory[8] = 0xf;
    _Memory[7] = 0;
    *(undefined1 *)(_Memory + 3) = 0;
    _free(_Memory);
    return extraout_EAX_00;
  }
  _free((void *)_Memory[3]);
  return extraout_EAX;
}


// ==== FUN_004a0510 @ 0x004a0510 ====

void FUN_004a0510(void)

{
  int iVar1;
  int *_Memory;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  void *local_2c;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097eabb;
  local_c = ExceptionList;
  iVar1 = **(int **)(in_ECX + 8);
  local_18 = 0xf;
  local_1c = 0;
  local_2c = (void *)((uint)local_2c & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401660(iVar1 + 8,0,0xffffffff);
  local_14 = *(undefined4 *)(iVar1 + 0x24);
  local_10 = *(undefined4 *)(iVar1 + 0x28);
  _Memory = (int *)**(int **)(in_ECX + 8);
  local_4 = 0;
  if (_Memory == *(int **)(in_ECX + 8)) {
    uVar2 = FUN_004a0910(local_30);
    uVar3 = FUN_004a08b0(local_30);
    FUN_004a1190(local_34,uVar3,uVar2);
    if (local_18 < 0x10) {
      ExceptionList = local_c;
      return;
    }
    _free(local_2c);
    return;
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  if ((uint)_Memory[8] < 0x10) {
    _Memory[8] = 0xf;
    _Memory[7] = 0;
    *(undefined1 *)(_Memory + 3) = 0;
    _free(_Memory);
    return;
  }
  _free((void *)_Memory[3]);
  return;
}


// ==== FUN_004a0600 @ 0x004a0600 ====

void FUN_004a0600(void)

{
  int *_Memory;
  char cVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint local_38;
  undefined1 local_30 [4];
  void *local_2c;
  undefined4 local_1c;
  uint local_18;
  int *local_14;
  int *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097eacd;
  local_c = ExceptionList;
  local_38 = 0;
  ExceptionList = &local_c;
  while( true ) {
    local_4 = 0xffffffff;
    if (*(int *)(in_ECX + 0xc) == 0) {
      ExceptionList = local_c;
      return;
    }
    iVar2 = **(int **)(in_ECX + 8);
    local_18 = 0xf;
    local_1c = 0;
    local_2c = (void *)((uint)local_2c & 0xffffff00);
    FUN_00401660(iVar2 + 8,0,0xffffffff);
    local_14 = *(int **)(iVar2 + 0x24);
    local_10 = *(int **)(iVar2 + 0x28);
    local_4 = 0;
    iVar2 = FUN_004a8060(local_30);
    if (iVar2 == 0) {
      FUN_004a0000(local_30);
    }
    else {
      (**(code **)(*local_10 + 0x10))(iVar2);
      cVar1 = (**(code **)(*local_14 + 0x2c))();
      if (cVar1 == '\0') {
        _Memory = (int *)**(int **)(in_ECX + 8);
        if (_Memory != *(int **)(in_ECX + 8)) {
          *(int *)_Memory[1] = *_Memory;
          *(int *)(*_Memory + 4) = _Memory[1];
          if ((uint)_Memory[8] < 0x10) {
            _Memory[8] = 0xf;
            _Memory[7] = 0;
            *(undefined1 *)(_Memory + 3) = 0;
            _free(_Memory);
            return;
          }
          _free((void *)_Memory[3]);
          return;
        }
        iVar2 = *(int *)(in_ECX + 8);
        iVar3 = FUN_004a0a70(iVar2,*(undefined4 *)(iVar2 + 4),local_30);
        FUN_004a09d0(1);
        *(int *)(iVar2 + 4) = iVar3;
        **(int **)(iVar3 + 4) = iVar3;
      }
      else {
        FUN_004a0510();
      }
    }
    if (0xf < local_18) break;
    local_38 = local_38 + 1;
    local_2c = (void *)((uint)local_2c & 0xffffff00);
    if (2 < local_38) {
      ExceptionList = local_c;
      return;
    }
  }
  local_4 = 0xffffffff;
  _free(local_2c);
  return;
}


// ==== FUN_004a0790 @ 0x004a0790 ====

void FUN_004a0790(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097eaea;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009af0a8;
  uVar1 = FUN_004a0840();
  in_ECX[2] = uVar1;
  in_ECX[3] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  iVar2 = FUN_00821b80();
  in_ECX[5] = iVar2;
  *(undefined1 *)(iVar2 + 0x31) = 1;
  *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
  *(undefined4 *)in_ECX[5] = in_ECX[5];
  *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  in_ECX[6] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac0c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ac0c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004a0840 @ 0x004a0840 ====

void FUN_004a0840(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x2c);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  return;
}


// ==== FUN_004a0860 @ 0x004a0860 ====

bool FUN_004a0860(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1c) < *(int *)(param_2 + 0x1c)) {
    return true;
  }
  if (*(int *)(param_2 + 0x1c) < *(int *)(param_1 + 0x1c)) {
    return false;
  }
  if (*(uint *)(param_2 + 0x18) < 0x10) {
    iVar1 = param_2 + 4;
  }
  else {
    iVar1 = *(int *)(param_2 + 4);
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),iVar1,*(undefined4 *)(param_2 + 0x14));
  return iVar1 < 0;
}


// ==== FUN_004a08b0 @ 0x004a08b0 ====

undefined4 * FUN_004a08b0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar1 = *(char *)((int)puVar4 + 0x31);
  puVar2 = *(undefined4 **)(in_ECX + 4);
  do {
    if (cVar1 != '\0') {
      return puVar2;
    }
    if ((int)puVar4[10] < *(int *)(param_1 + 0x1c)) {
LAB_004a08f6:
      puVar5 = (undefined4 *)puVar4[2];
      puVar4 = puVar2;
    }
    else {
      if ((int)puVar4[10] <= *(int *)(param_1 + 0x1c)) {
        if (*(uint *)(param_1 + 0x18) < 0x10) {
          iVar3 = param_1 + 4;
        }
        else {
          iVar3 = *(int *)(param_1 + 4);
        }
        iVar3 = FUN_00403620(0,puVar4[8],iVar3,*(undefined4 *)(param_1 + 0x14));
        if (iVar3 < 0) goto LAB_004a08f6;
      }
      puVar5 = (undefined4 *)*puVar4;
    }
    cVar1 = *(char *)((int)puVar5 + 0x31);
    puVar2 = puVar4;
    puVar4 = puVar5;
  } while( true );
}


// ==== FUN_004a0910 @ 0x004a0910 ====

undefined4 * FUN_004a0910(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(in_ECX + 4);
  cVar1 = *(char *)((int)puVar5[1] + 0x31);
  puVar2 = (undefined4 *)puVar5[1];
  do {
    if (cVar1 != '\0') {
      return puVar5;
    }
    if (*(int *)(param_1 + 0x1c) < (int)puVar2[10]) {
LAB_004a0955:
      puVar3 = (undefined4 *)*puVar2;
      puVar5 = puVar2;
    }
    else {
      if (*(int *)(param_1 + 0x1c) <= (int)puVar2[10]) {
        if ((uint)puVar2[9] < 0x10) {
          puVar3 = puVar2 + 4;
        }
        else {
          puVar3 = (undefined4 *)puVar2[4];
        }
        iVar4 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),puVar3,puVar2[8]);
        if (iVar4 < 0) goto LAB_004a0955;
      }
      puVar3 = (undefined4 *)puVar2[2];
    }
    cVar1 = *(char *)((int)puVar3 + 0x31);
    puVar2 = puVar3;
  } while( true );
}


// ==== FUN_004a0970 @ 0x004a0970 ====

void FUN_004a0970(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = FUN_004a08b0(param_2);
  if (iVar2 != *(int *)(in_ECX + 4)) {
    cVar1 = FUN_004a0860(param_2,iVar2 + 0xc);
    if (cVar1 == '\0') {
      *param_1 = iVar2;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_004a09d0 @ 0x004a09d0 ====

void FUN_004a09d0(uint param_1)

{
  int in_ECX;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ea48;
  local_c = ExceptionList;
  if (0x71c71c7U - *(int *)(in_ECX + 8) < param_1) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &local_c;
    FUN_00401740(s_list<T>_too_long_0099d1d0,0x10);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c48c);
  }
  *(uint *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return;
}


// ==== FUN_004a0a70 @ 0x004a0a70 ====

undefined4 * FUN_004a0a70(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097ea11;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x2c);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[8] = 0xf;
    puVar1[7] = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
    FUN_00401660(param_3,0,0xffffffff);
    puVar1[9] = *(undefined4 *)(param_3 + 0x1c);
    puVar1[10] = *(undefined4 *)(param_3 + 0x20);
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@004a0afa @ 0x004a0afa ====

void Catch_004a0afa(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004a0b10 @ 0x004a0b10 ====

void * FUN_004a0b10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097ea31;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x34);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_00447060(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004a0b82 @ 0x004a0b82 ====

void Catch_004a0b82(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004a0ba0 @ 0x004a0ba0 ====

void FUN_004a0ba0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x31) == '\0') {
    FUN_004a0ba0(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004a0be0 @ 0x004a0be0 ====

/* WARNING: Removing unreachable block (ram,0x004a0cf0) */
/* WARNING: Removing unreachable block (ram,0x004a0d01) */
/* WARNING: Removing unreachable block (ram,0x004a0d0a) */
/* WARNING: Removing unreachable block (ram,0x004a0d0d) */
/* WARNING: Removing unreachable block (ram,0x004a0cfd) */
/* WARNING: Removing unreachable block (ram,0x004a0d1b) */
/* WARNING: Removing unreachable block (ram,0x004a0d28) */
/* WARNING: Removing unreachable block (ram,0x004a0d33) */
/* WARNING: Removing unreachable block (ram,0x004a0d2f) */
/* WARNING: Removing unreachable block (ram,0x004a0d23) */
/* WARNING: Removing unreachable block (ram,0x004a0d36) */

void FUN_004a0be0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097ea48;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x31) != '\0') {
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
  FUN_00884fb0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x31) == '\0') {
    if (*(char *)(param_2[2] + 0x31) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x31) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x31) == '\0') {
      piVar3 = (int *)FUN_00446e00(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x31) == '\0') {
      uVar4 = FUN_0049ff70(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xc] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xc] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xc] == '\0') {
            *(undefined1 *)(piVar5 + 0xc) = 1;
            *(undefined1 *)(piVar3 + 0xc) = 0;
            FUN_00821aa0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x31) == '\0') {
            if ((*(char *)(*piVar5 + 0x30) == '\x01') && (*(char *)(piVar5[2] + 0x30) == '\x01'))
            goto LAB_004a0e07;
            if (*(char *)(piVar5[2] + 0x30) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x30) = 1;
              *(undefined1 *)(piVar5 + 0xc) = 0;
              FUN_0049ff90(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xc) = (char)piVar3[0xc];
            *(undefined1 *)(piVar3 + 0xc) = 1;
            *(undefined1 *)(piVar5[2] + 0x30) = 1;
            FUN_00821aa0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xc] == '\0') {
            *(undefined1 *)(piVar5 + 0xc) = 1;
            *(undefined1 *)(piVar3 + 0xc) = 0;
            FUN_0049ff90(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x31) == '\0') {
            if ((*(char *)(piVar5[2] + 0x30) != '\x01') || (*(char *)(*piVar5 + 0x30) != '\x01')) {
              if (*(char *)(*piVar5 + 0x30) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x30) = 1;
                *(undefined1 *)(piVar5 + 0xc) = 0;
                FUN_00821aa0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xc) = (char)piVar3[0xc];
              *(undefined1 *)(piVar3 + 0xc) = 1;
              *(undefined1 *)(*piVar5 + 0x30) = 1;
              FUN_0049ff90(piVar3);
              break;
            }
LAB_004a0e07:
            *(undefined1 *)(piVar5 + 0xc) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xc) = 1;
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


// ==== FUN_004a0eb0 @ 0x004a0eb0 ====

void FUN_004a0eb0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097ea48;
  local_c = ExceptionList;
  if (0x71c71c5 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004a0b10(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x30);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x30) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xc] == '\0') {
LAB_004a0fa9:
        *(undefined1 *)(*piVar5 + 0x30) = 1;
        *(undefined1 *)(piVar6 + 0xc) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x30) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_00821aa0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x30) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x30) = 0;
        FUN_0049ff90(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0xc] == '\0') goto LAB_004a0fa9;
      if (piVar7 == (int *)*piVar2) {
        FUN_0049ff90(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x30) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x30) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x31) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x30);
  } while( true );
}


// ==== FUN_004a1090 @ 0x004a1090 ====

void FUN_004a1090(undefined4 *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_ECX;
  undefined4 *puVar7;
  undefined4 local_4;
  
  iVar2 = (int)param_2;
  puVar4 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar3 = *(char *)((int)puVar4 + 0x31);
  bVar1 = true;
  local_4 = 1;
  puVar5 = *(undefined4 **)(in_ECX + 4);
  do {
    if (cVar3 != '\0') {
      param_2 = puVar5;
      if (bVar1) {
        if (puVar5 == (undefined4 *)**(int **)(in_ECX + 4)) {
          puVar4 = (undefined4 *)FUN_004a0eb0(&param_2,1,puVar5,iVar2);
          *param_1 = *puVar4;
          *(undefined1 *)(param_1 + 1) = 1;
          return;
        }
        FUN_008840e0();
      }
      puVar4 = param_2;
      cVar3 = FUN_004a0860(param_2 + 3,iVar2);
      if (cVar3 == '\0') {
        *param_1 = puVar4;
        *(undefined1 *)(param_1 + 1) = 0;
        return;
      }
      puVar4 = (undefined4 *)FUN_004a0eb0(&param_2,local_4,puVar5,iVar2);
      *param_1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    if (*(int *)(iVar2 + 0x1c) < (int)puVar4[10]) {
LAB_004a1126:
      puVar7 = (undefined4 *)*puVar4;
      bVar1 = true;
      local_4 = 1;
    }
    else {
      if (*(int *)(iVar2 + 0x1c) <= (int)puVar4[10]) {
        if ((uint)puVar4[9] < 0x10) {
          puVar5 = puVar4 + 4;
        }
        else {
          puVar5 = (undefined4 *)puVar4[4];
        }
        iVar6 = FUN_00403620(0,*(undefined4 *)(iVar2 + 0x14),puVar5,puVar4[8]);
        if (iVar6 < 0) goto LAB_004a1126;
      }
      puVar7 = (undefined4 *)puVar4[2];
      bVar1 = false;
      local_4 = 0;
    }
    cVar3 = *(char *)((int)puVar7 + 0x31);
    puVar5 = puVar4;
    puVar4 = puVar7;
  } while( true );
}


// ==== FUN_004a1190 @ 0x004a1190 ====

void FUN_004a1190(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004a0ba0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x31) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x31) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x31);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x31);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x31);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x31);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004a0be0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004a1250 @ 0x004a1250 ====

void FUN_004a1250(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004a1190(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004a1280 @ 0x004a1280 ====

void FUN_004a1280(byte param_1)

{
  void *in_ECX;
  
  FUN_004a0350();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004a12b0 @ 0x004a12b0 ====

uint FUN_004a12b0(int param_1)

{
  int *piVar1;
  int *_Memory;
  char cVar2;
  int iVar3;
  uint extraout_EAX;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 8);
  _Memory = (int *)*piVar1;
  do {
    if (_Memory == piVar1) {
      return 0;
    }
    if (_Memory[9] == *(int *)(param_1 + 0x1c)) {
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        iVar3 = param_1 + 4;
      }
      else {
        iVar3 = *(int *)(param_1 + 4);
      }
      iVar3 = FUN_00403620(0,_Memory[7],iVar3,*(undefined4 *)(param_1 + 0x14));
      if (iVar3 == 0) {
        piVar1 = (int *)_Memory[10];
        if (_Memory != *(int **)(in_ECX + 8)) {
          *(int *)_Memory[1] = *_Memory;
          *(int *)(*_Memory + 4) = _Memory[1];
          FUN_006c1c60();
          _free(_Memory);
          return extraout_EAX;
        }
        iVar3 = FUN_004a8060(param_1);
        if (iVar3 == 0) {
          return 0;
        }
        cVar2 = (**(code **)(*piVar1 + 0x10))(iVar3);
        return (uint)(cVar2 != '\0');
      }
    }
    _Memory = (int *)*_Memory;
  } while( true );
}


// ==== FUN_004a1360 @ 0x004a1360 ====

void FUN_004a1360(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined1 uStack00000000;
  
  (**(code **)(*DAT_00b5a740 + 0x1c))(*(undefined4 *)(param_1 + 0x24));
  *(undefined4 *)(param_1 + 0x24) = 0;
  iVar2 = FUN_004a08b0(param_1);
  if (iVar2 != *(int *)(in_ECX + 0x24)) {
    cVar1 = FUN_004a0860(param_1,iVar2 + 0xc);
    if (cVar1 == '\0') {
      piVar3 = (int *)register0x00000010;
      goto LAB_004a13b5;
    }
  }
  piVar3 = (int *)((int)register0x00000010 + -8);
LAB_004a13b5:
  iVar2 = *piVar3;
  if (iVar2 != *(int *)(in_ECX + 0x24)) {
    (**(code **)(**(int **)(iVar2 + 0x2c) + 0x20))();
    FUN_004a0be0(&uStack00000000,iVar2);
  }
  return;
}


// ==== FUN_004a13e0 @ 0x004a13e0 ====

void FUN_004a13e0(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int local_3c;
  int local_38 [2];
  undefined1 local_30 [4];
  void *local_2c;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar2 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097eb68;
  local_c = ExceptionList;
  iVar1 = *(int *)(in_ECX + 0x24);
  local_38[0] = in_ECX + 0x20;
  ExceptionList = &local_c;
  param_1 = FUN_004a08b0(param_1);
  if (param_1 != *(int *)(in_ECX + 0x24)) {
    cVar3 = FUN_004a0860(iVar2,param_1 + 0xc);
    if (cVar3 == '\0') {
      piVar4 = &param_1;
      goto LAB_004a143e;
    }
  }
  local_3c = *(int *)(in_ECX + 0x24);
  piVar4 = &local_3c;
LAB_004a143e:
  if (*piVar4 == iVar1) {
    iVar1 = *(int *)(in_ECX + 8);
    iVar5 = FUN_004a0a70(iVar1,*(undefined4 *)(iVar1 + 4),iVar2);
    FUN_004a09d0(1);
    *(int *)(iVar1 + 4) = iVar5;
    **(int **)(iVar5 + 4) = iVar5;
    local_18 = 0xf;
    local_1c = 0;
    local_2c = (void *)((uint)local_2c & 0xffffff00);
    FUN_00401660(iVar2,0,0xffffffff);
    local_14 = *(undefined4 *)(iVar2 + 0x1c);
    local_10 = *(undefined4 *)(iVar2 + 0x20);
    local_4 = 0;
    FUN_004a1090(local_38,local_30);
    local_4 = 0xffffffff;
    if (0xf < local_18) {
      _free(local_2c);
      return;
    }
    local_18 = 0xf;
    local_1c = 0;
    local_2c = (void *)((uint)local_2c & 0xffffff00);
    (**(code **)(**(int **)(iVar2 + 0x20) + 0x1c))();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004a1500 @ 0x004a1500 ====

void FUN_004a1500(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int local_3c;
  int local_38 [2];
  undefined1 local_30 [4];
  void *local_2c;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar2 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097eb7a;
  local_c = ExceptionList;
  iVar1 = *(int *)(in_ECX + 0x24);
  local_38[0] = in_ECX + 0x20;
  ExceptionList = &local_c;
  param_1 = FUN_004a08b0(param_1);
  if (param_1 != *(int *)(in_ECX + 0x24)) {
    cVar3 = FUN_004a0860(iVar2,param_1 + 0xc);
    if (cVar3 == '\0') {
      piVar4 = &param_1;
      goto LAB_004a155e;
    }
  }
  local_3c = *(int *)(in_ECX + 0x24);
  piVar4 = &local_3c;
LAB_004a155e:
  if (*piVar4 == iVar1) {
    iVar1 = **(int **)(in_ECX + 8);
    iVar5 = FUN_004a0a70(iVar1,*(undefined4 *)(iVar1 + 4),iVar2);
    FUN_004a09d0(1);
    *(int *)(iVar1 + 4) = iVar5;
    **(int **)(iVar5 + 4) = iVar5;
    local_18 = 0xf;
    local_1c = 0;
    local_2c = (void *)((uint)local_2c & 0xffffff00);
    FUN_00401660(iVar2,0,0xffffffff);
    local_14 = *(undefined4 *)(iVar2 + 0x1c);
    local_10 = *(undefined4 *)(iVar2 + 0x20);
    local_4 = 0;
    FUN_004a1090(local_38,local_30);
    local_4 = 0xffffffff;
    if (0xf < local_18) {
      _free(local_2c);
      return;
    }
    local_18 = 0xf;
    local_1c = 0;
    local_2c = (void *)((uint)local_2c & 0xffffff00);
    (**(code **)(**(int **)(iVar2 + 0x20) + 0x1c))();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004a1620 @ 0x004a1620 ====

/* WARNING: Removing unreachable block (ram,0x004a16e6) */
/* WARNING: Removing unreachable block (ram,0x004a1807) */
/* WARNING: Removing unreachable block (ram,0x004a1850) */

undefined4 FUN_004a1620(int param_1)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined4 extraout_EAX;
  undefined4 uVar8;
  int in_ECX;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  bool bVar13;
  bool bVar14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097eb8c;
  iVar7 = *(int *)(in_ECX + 0x34);
  local_c = ExceptionList;
  ExceptionList = &local_c;
  for (iVar10 = *(int *)(in_ECX + 0x30); iVar10 != iVar7; iVar10 = iVar10 + 0x28) {
    if (*(int *)(param_1 + 0x1c) == *(int *)(iVar10 + 0x1c)) {
      if (*(uint *)(iVar10 + 0x18) < 0x10) {
        iVar6 = iVar10 + 4;
      }
      else {
        iVar6 = *(int *)(iVar10 + 4);
      }
      iVar6 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),iVar6,*(undefined4 *)(iVar10 + 0x14));
      if (iVar6 == 0) {
        (**(code **)(**(int **)(iVar10 + 0x20) + 0x30))();
        ExceptionList = local_c;
        return 1;
      }
    }
  }
  iVar10 = *(int *)(in_ECX + 0x14);
  if (iVar10 != *(int *)(in_ECX + 0x18)) {
    do {
      if (*(int *)(param_1 + 0x1c) == *(int *)(iVar10 + 0x1c)) {
        uVar1 = *(uint *)(iVar10 + 0x14);
        if (*(uint *)(iVar10 + 0x18) < 0x10) {
          pbVar12 = (byte *)(iVar10 + 4);
        }
        else {
          pbVar12 = *(byte **)(iVar10 + 4);
        }
        uVar2 = *(uint *)(param_1 + 0x14);
        if (uVar2 != 0) {
          uVar9 = uVar2;
          if (uVar1 <= uVar2) {
            uVar9 = uVar1;
          }
          if (*(uint *)(param_1 + 0x18) < 0x10) {
            pbVar11 = (byte *)(param_1 + 4);
          }
          else {
            pbVar11 = *(byte **)(param_1 + 4);
          }
          bVar13 = false;
          iVar7 = 0;
          bVar14 = true;
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            bVar13 = *pbVar11 < *pbVar12;
            bVar14 = *pbVar11 == *pbVar12;
            pbVar11 = pbVar11 + 1;
            pbVar12 = pbVar12 + 1;
          } while (bVar14);
          if (!bVar14) {
            iVar7 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
          }
          if (iVar7 != 0) goto LAB_004a1725;
        }
        if ((uVar1 <= uVar2) && (uVar2 == uVar1)) {
          piVar3 = *(int **)(iVar10 + 0x24);
          FUN_00401660(iVar10,0,0xffffffff);
          piVar4 = *(int **)(iVar10 + 0x20);
          local_4 = 0;
          FUN_004a2020(iVar10 + 0x28,*(undefined4 *)(in_ECX + 0x18),iVar10,param_1);
          iVar7 = *(int *)(in_ECX + 0x18);
          for (iVar10 = iVar7 + -0x28; iVar10 != iVar7; iVar10 = iVar10 + 0x28) {
            if (0xf < *(uint *)(iVar10 + 0x18)) {
              _free(*(void **)(iVar10 + 4));
              return extraout_EAX;
            }
            *(undefined4 *)(iVar10 + 0x18) = 0xf;
            *(undefined4 *)(iVar10 + 0x14) = 0;
            *(undefined1 *)(iVar10 + 4) = 0;
          }
          *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + -0x28;
          cVar5 = (**(code **)(*DAT_00b5a740 + 0x18))(piVar3);
          if (cVar5 == '\0') {
            (**(code **)(*DAT_00b5a740 + 0x1c))(piVar3);
            ExceptionList = local_c;
            return 0;
          }
          uVar8 = FUN_004a74a0(0xf);
          iVar10 = (**(code **)(*piVar3 + 0x10))(uVar8);
          (**(code **)(*DAT_00b5a740 + 0x1c))(piVar3);
          if (iVar10 == 0) {
            ExceptionList = local_c;
            return 0;
          }
          (**(code **)(*piVar4 + 0x10))(iVar10);
          ExceptionList = piVar4;
          return 1;
        }
      }
LAB_004a1725:
      iVar10 = iVar10 + 0x28;
    } while (iVar10 != *(int *)(in_ECX + 0x18));
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_004a1880 @ 0x004a1880 ====

void FUN_004a1880(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ebb4;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009af14c;
  local_4 = 2;
  DAT_00b5ac0c = 0;
  FUN_004a22d0();
  FUN_004a1190(local_10,*(undefined4 *)in_ECX[9],(undefined4 *)in_ECX[9]);
  _free((void *)in_ECX[9]);
  return;
}


// ==== FUN_004a1920 @ 0x004a1920 ====

uint FUN_004a1920(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  uint uVar5;
  int in_ECX;
  int local_4;
  
  iVar2 = param_1;
  local_4 = in_ECX;
  param_1 = FUN_004a08b0(param_1);
  if (param_1 != *(int *)(in_ECX + 0x24)) {
    cVar3 = FUN_004a0860(iVar2,param_1 + 0xc);
    if (cVar3 == '\0') {
      piVar4 = &param_1;
      goto LAB_004a1960;
    }
  }
  local_4 = *(int *)(in_ECX + 0x24);
  piVar4 = &local_4;
LAB_004a1960:
  iVar1 = *piVar4;
  if (iVar1 == *(int *)(in_ECX + 0x24)) {
    return (uint)piVar4 & 0xffffff00;
  }
  (**(code **)(**(int **)(iVar1 + 0x2c) + 0x20))();
  FUN_004a0be0(&param_1,iVar1);
  uVar5 = FUN_004a1620(iVar2);
  if ((char)uVar5 == '\x01') {
    return uVar5;
  }
  uVar5 = FUN_004a12b0(iVar2);
  return uVar5;
}


// ==== FUN_004a19b0 @ 0x004a19b0 ====

void FUN_004a19b0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ebe7;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009af14c;
  uVar1 = FUN_004a0840();
  in_ECX[2] = uVar1;
  in_ECX[3] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  iVar2 = FUN_00821b80();
  in_ECX[9] = iVar2;
  *(undefined1 *)(iVar2 + 0x31) = 1;
  *(undefined4 *)(in_ECX[9] + 4) = in_ECX[9];
  *(undefined4 *)in_ECX[9] = in_ECX[9];
  *(undefined4 *)(in_ECX[9] + 8) = in_ECX[9];
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac0c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ac0c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004a1a70 @ 0x004a1a70 ====

void FUN_004a1a70(void)

{
  int iVar1;
  int *_Memory;
  int in_ECX;
  undefined1 local_34 [4];
  void *local_30;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ebf9;
  local_c = ExceptionList;
  local_1c = 0xf;
  local_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  local_18 = 0xffff;
  local_4 = 0;
  ExceptionList = &local_c;
  if (*(int *)(in_ECX + 0xc) != 0) {
    do {
      if ((*(int *)(in_ECX + 0x14) != 0) &&
         (9 < (uint)((*(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14)) / 0x28))) break;
      iVar1 = **(int **)(in_ECX + 8);
      FUN_00401660(iVar1 + 8,0,0xffffffff);
      local_18 = *(undefined4 *)(iVar1 + 0x24);
      local_14 = *(undefined4 *)(iVar1 + 0x28);
      local_10 = FUN_004a8540(iVar1 + 8);
      if (local_10 != 0) {
        FUN_004a2750(local_34);
      }
      _Memory = (int *)**(int **)(in_ECX + 8);
      if (_Memory != *(int **)(in_ECX + 8)) {
        *(int *)_Memory[1] = *_Memory;
        *(int *)(*_Memory + 4) = _Memory[1];
        if ((uint)_Memory[8] < 0x10) {
          _Memory[8] = 0xf;
          _Memory[7] = 0;
          *(undefined1 *)(_Memory + 3) = 0;
          _free(_Memory);
          return;
        }
        _free((void *)_Memory[3]);
        return;
      }
    } while (*(int *)(in_ECX + 0xc) != 0);
    if (0xf < local_1c) {
      _free(local_30);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004a1ba0 @ 0x004a1ba0 ====

void FUN_004a1ba0(void)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 ****in_ECX;
  undefined4 *****pppppuVar4;
  int iVar5;
  undefined4 *****pppppuStack_88;
  uint *puStack_84;
  undefined4 *****pppppuStack_80;
  undefined4 *****local_68;
  undefined4 ****ppppuStack_64;
  void *pvStack_48;
  undefined4 ***local_44;
  uint local_40;
  void *pvStack_3c;
  undefined4 uStack_38;
  void *pvStack_34;
  undefined4 local_30;
  void *local_2c;
  uint local_28;
  void *pvStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ec33;
  pvStack_c = ExceptionList;
  ppppuStack_64 = (undefined4 ****)0x11;
  local_68 = (undefined4 *****)s__REQUEST__Loading_009af0fc;
  local_2c = (void *)0xf;
  local_30 = 0;
  local_40 = local_40 & 0xffffff00;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  if (*(int *)((int)in_ECX + 0x14) == 0) {
    ppppuStack_64 = (undefined4 ****)0x0;
  }
  else {
    ppppuStack_64 =
         (undefined4 ****)((*(int *)((int)in_ECX + 0x18) - *(int *)((int)in_ECX + 0x14)) / 0x28);
  }
  puStack_84 = (uint *)0x2;
  local_68 = (undefined4 *****)0xf;
  pppppuStack_88 = (undefined4 *****)&DAT_009af0f8;
  FUN_00401740();
  puStack_84 = &local_28;
  pppppuStack_88 = (undefined4 *****)0x4a1c33;
  ppppuStack_64 = (undefined4 ****)FUN_00404230();
  local_68 = (undefined4 *****)&local_44;
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a688 + 8))();
  if (0xf < uStack_18) {
    _free(local_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  local_2c = (void *)((uint)local_2c & 0xffffff00);
  pvStack_c = (void *)0xffffffff;
  if (0xf < pvStack_34) {
    _free(pvStack_48);
    return;
  }
  pvStack_34 = (void *)0xf;
  uStack_38 = 0;
  FUN_00401740();
  pvStack_c = (void *)0x2;
  puStack_84 = (uint *)((uint)puStack_84 & 0xffffff00);
  FUN_00401740();
  FUN_00404230();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  (**(code **)(*DAT_00b5a688 + 8))();
  if (0xf < uStack_20) {
    _free(pvStack_34);
    return;
  }
  uStack_20 = 0xf;
  pvStack_24 = (void *)0x0;
  pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
  uStack_14 = 0xffffffff;
  if (0xf < pvStack_3c) {
    _free(&pppppuStack_80);
    return;
  }
  pvStack_3c = (void *)0xf;
  local_40 = 0;
  FUN_00401740();
  uStack_14 = 4;
  FUN_00401740(&DAT_009af12c,2);
  FUN_00404230(&uStack_38);
  uStack_14 = CONCAT31(uStack_14._1_3_,5);
  (**(code **)(*DAT_00b5a688 + 8))();
  if (0xf < local_28) {
    pppppuStack_80 = (undefined4 *****)0x4a1dc8;
    _free(pvStack_3c);
    return;
  }
  local_28 = 0xf;
  local_2c = (void *)0x0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  uStack_1c = 0xffffffff;
  if ((undefined4 **)0xf < local_44) {
    pppppuStack_80 = (undefined4 *****)0x4a1def;
    _free(&pppppuStack_88);
    return;
  }
  local_68 = *(undefined4 ******)((int)in_ECX + 0x30);
  if (local_68 != *(undefined4 ******)((int)in_ECX + 0x34)) {
    do {
      pppppuVar4 = local_68;
      cVar2 = (*(code *)(*local_68[8])[0xb])();
      if (cVar2 == '\0') {
        local_68 = pppppuVar4 + 10;
      }
      else {
        pppppuStack_80 = (undefined4 *****)0x4a1e14;
        FUN_004a1360();
        puStack_84 = *(uint **)((int)in_ECX + 0x34);
        pppppuStack_88 = pppppuVar4 + 10;
        pppppuStack_80 = pppppuVar4;
        FUN_004a2020();
        iVar1 = *(int *)((int)in_ECX + 0x34);
        for (iVar5 = iVar1 + -0x28; iVar5 != iVar1; iVar5 = iVar5 + 0x28) {
          if (0xf < *(uint *)(iVar5 + 0x18)) {
            pppppuStack_80 = (undefined4 *****)0x4a1e43;
            _free(*(void **)(iVar5 + 4));
            return;
          }
          *(undefined4 *)(iVar5 + 0x18) = 0xf;
          *(undefined4 *)(iVar5 + 0x14) = 0;
          *(undefined1 *)(iVar5 + 4) = 0;
        }
        *(int *)((int)in_ECX + 0x34) = *(int *)((int)in_ECX + 0x34) + -0x28;
      }
    } while (local_68 != *(undefined4 ******)((int)in_ECX + 0x34));
  }
  pppppuVar4 = *(undefined4 ******)((int)in_ECX + 0x14);
  if (pppppuVar4 != *(undefined4 ******)((int)in_ECX + 0x18)) {
    do {
      cVar2 = (*(code *)(*pppppuVar4[9])[2])();
      if (cVar2 == '\0') {
        pppppuVar4 = pppppuVar4 + 10;
      }
      else {
        pppppuStack_80 = (undefined4 *****)0x4a1e9d;
        FUN_004a74a0();
        pppppuStack_80 = (undefined4 *****)0x4a1ea9;
        iVar5 = (*(code *)(*pppppuVar4[9])[4])();
        if (iVar5 == 0) {
          pppppuStack_80 = (undefined4 *****)0x4a1eb5;
          FUN_004a1360();
          puStack_84 = *(uint **)((int)in_ECX + 0x18);
          pppppuStack_88 = pppppuVar4 + 10;
          pppppuStack_80 = pppppuVar4;
          FUN_004a2020();
          iVar1 = *(int *)((int)in_ECX + 0x18);
          for (iVar5 = iVar1 + -0x28; iVar5 != iVar1; iVar5 = iVar5 + 0x28) {
            if (0xf < *(uint *)(iVar5 + 0x18)) {
              pppppuStack_80 = (undefined4 *****)0x4a1ee7;
              _free(*(void **)(iVar5 + 4));
              return;
            }
            *(undefined4 *)(iVar5 + 0x18) = 0xf;
            *(undefined4 *)(iVar5 + 0x14) = 0;
            *(undefined1 *)(iVar5 + 4) = 0;
          }
          *(int *)((int)ppppuStack_64 + 0x18) = *(int *)((int)ppppuStack_64 + 0x18) + -0x28;
          in_ECX = ppppuStack_64;
        }
        else {
          pppppuStack_80 = (undefined4 *****)0x4a1f18;
          (*(code *)(*pppppuVar4[8])[10])();
          pppppuStack_80 = (undefined4 *****)0x4a1f20;
          iVar5 = (*(code *)(*pppppuVar4[8])[1])();
          if (*(int *)(iVar5 + 0x30) == 2) {
            pppppuStack_80 = (undefined4 *****)0x4a1f2e;
            FUN_004a1360();
            pppppuStack_80 = &local_68;
          }
          else {
            iVar5 = (*(code *)(*pppppuVar4[8])[1])();
            if (*(int *)(iVar5 + 0x30) != 1) goto LAB_004a1f5d;
            pppppuStack_80 = (undefined4 *****)0x4a1f4d;
            FUN_004a2750();
            pppppuStack_80 = (undefined4 *****)((int)register0x00000010 + -0x60);
          }
          puStack_84 = (uint *)0x4a1f5b;
          puVar3 = (undefined4 *)FUN_004a2330();
          pppppuVar4 = (undefined4 *****)*puVar3;
        }
      }
LAB_004a1f5d:
    } while (pppppuVar4 != *(undefined4 ******)((int)in_ECX + 0x18));
  }
  FUN_004a1a70();
  ExceptionList = pvStack_24;
  return;
}


// ==== FUN_004a1f80 @ 0x004a1f80 ====

bool FUN_004a1f80(int param_1,int param_2)

{
  int iVar1;
  
  if (*(uint *)(param_2 + 0x18) < 0x10) {
    iVar1 = param_2 + 4;
  }
  else {
    iVar1 = *(int *)(param_2 + 4);
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),iVar1,*(undefined4 *)(param_2 + 0x14));
  return iVar1 != 0;
}


// ==== FUN_004a1fb0 @ 0x004a1fb0 ====

void FUN_004a1fb0(void)

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
  puStack_8 = &LAB_0097eb08;
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


// ==== FUN_004a2020 @ 0x004a2020 ====

int FUN_004a2020(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_00401660(param_1,0,0xffffffff);
    *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_3 + 0x20) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_3 + 0x24) = *(undefined4 *)(param_1 + 0x24);
    param_1 = param_1 + 0x28;
    param_3 = param_3 + 0x28;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_004a2070 @ 0x004a2070 ====

int FUN_004a2070(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x28;
    iVar2 = param_3 + -0x28;
    FUN_00401660(iVar1,0,0xffffffff);
    *(undefined4 *)(param_3 + -0xc) = *(undefined4 *)(param_2 + -0xc);
    *(undefined4 *)(param_3 + -8) = *(undefined4 *)(param_2 + -8);
    *(undefined4 *)(param_3 + -4) = *(undefined4 *)(param_2 + -4);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_004a20c0 @ 0x004a20c0 ====

int FUN_004a20c0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097eb31;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x28) {
    local_8 = 1;
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x18) = 0xf;
      *(undefined4 *)(param_3 + 0x14) = 0;
      *(undefined1 *)(param_3 + 4) = 0;
      FUN_00401660(param_1,0,0xffffffff);
      *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(param_3 + 0x20) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_3 + 0x24) = *(undefined4 *)(param_1 + 0x24);
    }
    param_3 = param_3 + 0x28;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@004a2138 @ 0x004a2138 ====

void Catch_004a2138(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  iVar1 = *(int *)(unaff_EBP + 0x10);
  while( true ) {
    if (iVar2 == iVar1) {
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(0,0);
    }
    if (0xf < *(uint *)(iVar2 + 0x18)) break;
    *(undefined4 *)(iVar2 + 0x18) = 0xf;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined1 *)(iVar2 + 4) = 0;
    iVar2 = iVar2 + 0x28;
  }
  _free(*(void **)(iVar2 + 4));
  return;
}


// ==== FUN_004a2190 @ 0x004a2190 ====

void FUN_004a2190(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x28) {
    FUN_00401660(param_3,0,0xffffffff);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_3 + 0x20);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_3 + 0x24);
  }
  return;
}


// ==== FUN_004a21d0 @ 0x004a21d0 ====

void FUN_004a21d0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097eb51;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401660(param_3,0,0xffffffff);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_3 + 0x20);
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_3 + 0x24);
    }
    param_1 = param_1 + 0x28;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004a2249 @ 0x004a2249 ====

void Catch_004a2249(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  iVar1 = *(int *)(unaff_EBP + 8);
  while( true ) {
    if (iVar2 == iVar1) {
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(0,0);
    }
    if (0xf < *(uint *)(iVar2 + 0x18)) break;
    *(undefined4 *)(iVar2 + 0x18) = 0xf;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined1 *)(iVar2 + 4) = 0;
    iVar2 = iVar2 + 0x28;
  }
  _free(*(void **)(iVar2 + 4));
  return;
}


// ==== FUN_004a22a0 @ 0x004a22a0 ====

void FUN_004a22a0(int param_1,int param_2)

{
  if (param_1 != param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return;
}


// ==== FUN_004a22d0 @ 0x004a22d0 ====

void FUN_004a22d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004a2320 @ 0x004a2320 ====

void FUN_004a2320(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004a2330 @ 0x004a2330 ====

void FUN_004a2330(int *param_1,int param_2)

{
  int in_ECX;
  
  FUN_004a2020(param_2 + 0x28,*(undefined4 *)(in_ECX + 8),param_2,param_2);
  if (*(int *)(in_ECX + 8) + -0x28 != *(int *)(in_ECX + 8)) {
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x28;
  *param_1 = param_2;
  return;
}


// ==== FUN_004a2380 @ 0x004a2380 ====

int FUN_004a2380(int param_1,int param_2,undefined4 param_3)

{
  FUN_004a21d0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x28;
}


// ==== FUN_004a23b0 @ 0x004a23b0 ====

void FUN_004a23b0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  undefined1 local_44 [2];
  undefined1 auStack_42 [2];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097ec48;
  local_10 = ExceptionList;
  local_14 = local_44 + -0xc;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_28 = *(undefined4 *)(param_3 + 0x1c);
  local_24 = *(undefined4 *)(param_3 + 0x20);
  local_20 = *(undefined4 *)(param_3 + 0x24);
  iVar2 = *(int *)(in_ECX + 4);
  local_8 = 0;
  if (iVar2 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x28;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
    }
    if (0x6666666U - iVar1 < param_2) {
      FUN_004a1fb0();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x6666666 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_00436560();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x28);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      iVar2 = FUN_004a20c0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_004a21d0(iVar2,param_2,local_44);
      FUN_004a20c0(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x28);
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x28;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_004a22a0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x28 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 0x28);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      if ((uint)((iVar2 - param_1) / 0x28) < param_2) {
        FUN_004a20c0(param_1,iVar2,param_2 * 0x28 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004a2380(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x28,local_44
                    );
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x28;
        local_8 = 0;
        FUN_004a2190(param_1,*(int *)(in_ECX + 8) + param_2 * -0x28,local_44);
      }
      else {
        iVar1 = iVar2 + param_2 * -0x28;
        uVar4 = FUN_004a20c0(iVar1,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_004a2070(param_1,iVar1,iVar2,iVar1);
        FUN_004a2190(param_1,param_2 * 0x28 + param_1,local_44);
      }
    }
  }
  if (local_2c < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_40);
  return;
}


// ==== Catch@004a2595 @ 0x004a2595 ====

void Catch_004a2595(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_004a22a0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@004a2648 @ 0x004a2648 ====

void Catch_004a2648(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x28;
  FUN_004a22a0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004a26e0 @ 0x004a26e0 ====

void FUN_004a26e0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x28 != 0) {
      iVar1 = (param_2 - iVar1) / 0x28;
      goto LAB_004a2725;
    }
  }
  iVar1 = 0;
LAB_004a2725:
  FUN_004a23b0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x28;
  return;
}


// ==== FUN_004a2750 @ 0x004a2750 ====

void FUN_004a2750(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x28) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x28))) {
    FUN_004a26e0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004a21d0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x28;
  return;
}


// ==== FUN_004a27e0 @ 0x004a27e0 ====

void FUN_004a27e0(byte param_1)

{
  void *in_ECX;
  
  FUN_004a1880();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004a2800 @ 0x004a2800 ====

void FUN_004a2800(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af25c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004a2820 @ 0x004a2820 ====

void FUN_004a2820(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x20))();
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x2c))(param_1);
  }
  return;
}


// ==== FUN_004a2840 @ 0x004a2840 ====

void FUN_004a2840(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af2a4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a7cc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a7cc = in_ECX;
  return;
}


// ==== FUN_004a2870 @ 0x004a2870 ====

bool FUN_004a2870(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a7d0 + 4))(param_1);
  return iVar1 != 0;
}


// ==== FUN_004a2890 @ 0x004a2890 ====

void FUN_004a2890(void)

{
                    /* WARNING: Could not recover jumptable at 0x004a2898. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a7d0 + 0x14))();
  return;
}


// ==== FUN_004a28a0 @ 0x004a28a0 ====

void FUN_004a28a0(void)

{
                    /* WARNING: Could not recover jumptable at 0x004a28a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a7d0 + 0xc))();
  return;
}


// ==== FUN_004a28b0 @ 0x004a28b0 ====

void FUN_004a28b0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a7cc = 0;
  *in_ECX = &PTR_FUN_009af25c;
  return;
}


// ==== FUN_004a28d0 @ 0x004a28d0 ====

undefined4 FUN_004a28d0(int *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int *in_ECX;
  void *pvStack_2c;
  undefined1 uStack_28;
  uint uStack_18;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097ec68;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = (void *)(**(code **)(*param_1 + 0xc))();
  uVar2 = (**(code **)(*param_1 + 4))();
  uStack_14 = 0xf;
  uStack_18 = 0;
  uStack_28 = 0;
  FUN_00401660(uVar2,0,0xffffffff);
  uStack_4 = 0;
  pvStack_10 = pvVar1;
  uVar2 = (**(code **)(*in_ECX + 0x18))(&pvStack_2c);
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_10;
    return uVar2;
  }
  _free(pvStack_2c);
  return extraout_EAX;
}


// ==== FUN_004a2970 @ 0x004a2970 ====

void FUN_004a2970(int *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int *in_ECX;
  void *pvStack_2c;
  undefined1 uStack_28;
  uint uStack_18;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097ec7a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = (void *)(**(code **)(*param_1 + 0xc))();
  uVar2 = (**(code **)(*param_1 + 4))();
  uStack_14 = 0xf;
  uStack_18 = 0;
  uStack_28 = 0;
  FUN_00401660(uVar2,0,0xffffffff);
  uStack_4 = 0;
  pvStack_10 = pvVar1;
  (**(code **)(*in_ECX + 0x28))(&pvStack_2c);
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(pvStack_2c);
  return;
}


// ==== FUN_004a2a10 @ 0x004a2a10 ====

int * FUN_004a2a10(int param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *extraout_EAX;
  int *extraout_EAX_00;
  int *extraout_EAX_01;
  void *unaff_EBX;
  undefined1 local_6c [16];
  uint auStack_5c [2];
  void *pvStack_54;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 local_3c;
  undefined4 local_38;
  void *local_34;
  undefined1 uStack_30;
  undefined4 uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int *piStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ec9c;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x14) == 0) {
    return (int *)0x0;
  }
  if (*(int *)(param_1 + 0x1c) == 0xffff) {
    return (int *)0x0;
  }
  ExceptionList = &local_c;
  FUN_004a7bb0(local_6c,param_1);
  pvVar1 = *(void **)(param_1 + 0x1c);
  local_4 = 0;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  FUN_00401660(local_6c,0,0xffffffff);
  local_4 = CONCAT31(local_4._1_3_,1);
  local_34 = pvVar1;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7d0 + 4))(local_50);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)FUN_004a7580(&pvStack_54);
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    uStack_18 = 0xffff;
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
    piStack_14 = piVar3;
    FUN_00401660(&pvStack_54,0,0xffffffff);
    uStack_18 = local_38;
    (**(code **)(*DAT_00b5ac0c + 8))(&local_34);
    iVar2 = *piVar3;
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    (**(code **)(iVar2 + 0x18))(uVar4);
    (**(code **)(*piVar3 + 0x1c))();
    (**(code **)(*DAT_00b5a7d0 + 8))(auStack_5c,piVar3);
    if (0xf < uStack_20) {
      _free(local_34);
      return extraout_EAX;
    }
    uStack_20 = 0xf;
    uStack_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
  }
  else {
    iVar2 = *piVar3;
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    (**(code **)(iVar2 + 0x18))(uVar4);
    (**(code **)(*piVar3 + 0x1c))();
  }
  if (0xf < uStack_40) {
    _free(pvStack_54);
    return extraout_EAX_00;
  }
  uStack_40 = 0xf;
  uStack_44 = 0;
  pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
  if (auStack_5c[0] < 0x10) {
    ExceptionList = piStack_14;
    return piVar3;
  }
  _free(unaff_EBX);
  return extraout_EAX_01;
}


// ==== FUN_004a2be0 @ 0x004a2be0 ====

int * FUN_004a2be0(int param_1)

{
  char cVar1;
  int *extraout_EAX;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *extraout_EAX_00;
  uint *apuStack_9c [4];
  undefined4 uStack_8c;
  undefined1 *puStack_88;
  int *piStack_84;
  void *local_60;
  undefined4 local_50;
  uint local_4c [5];
  undefined1 auStack_38 [8];
  void *pvStack_30;
  undefined1 local_28;
  uint uStack_1c;
  undefined4 local_18;
  void *local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0097ecde;
  local_c = ExceptionList;
  if ((*(int *)(param_1 + 0x14) == 0) || (*(int *)(param_1 + 0x1c) == 0xffff)) {
    return (int *)0x0;
  }
  ExceptionList = &local_c;
  FUN_004a7bb0();
  uVar4 = *(undefined4 *)(param_1 + 0x1c);
  local_4 = (undefined1 *)0x0;
  local_14 = (void *)0xf;
  local_18 = 0;
  local_28 = 0;
  piStack_84 = (int *)0x4a2c4b;
  FUN_00401660();
  local_4 = (undefined1 *)CONCAT31(local_4._1_3_,2);
  local_10 = uVar4;
  if (0xf < local_4c[0]) {
    _free(local_60);
    return extraout_EAX;
  }
  local_4c[0] = 0xf;
  local_50 = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5a7d0 + 4))();
  if (piVar2 == (int *)0x0) {
    iVar3 = FUN_004a8060();
    if (iVar3 == 0) {
      apuStack_9c[0] = (uint *)s_<<_cannot_open_file_>>__s_009af19c;
      FUN_00401830();
      apuStack_9c[0] = local_4c;
      uVar4 = FUN_00404230();
      puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
      FUN_00796d50(uVar4);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    piVar2 = (int *)FUN_004a7580();
    cVar1 = (**(code **)(*piVar2 + 0x10))();
    if (cVar1 != '\0') {
      iVar3 = *piVar2;
      (**(code **)(*DAT_00b5a6ac + 0x18))();
      piStack_84 = (int *)0x4a2d78;
      (**(code **)(iVar3 + 0x18))();
      piStack_84 = (int *)0x4a2d7f;
      (**(code **)(*piVar2 + 0x1c))();
      puStack_88 = auStack_38;
      uStack_8c = 0x4a2d90;
      piStack_84 = piVar2;
      (**(code **)(*DAT_00b5a7d0 + 8))();
                    /* WARNING: Subroutine does not return */
      uStack_8c = 0x4a2d99;
      FUN_00446f10();
    }
    local_4 = (undefined1 *)apuStack_9c;
    FUN_00401830(s_<<_invalid_file_format_>>__s_009af1bc);
    uVar4 = FUN_00404230(&local_50);
    local_c._0_1_ = 4;
LAB_004a2e84:
    FUN_00796d50(uVar4);
    local_c = (void *)CONCAT31(local_c._1_3_,2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar1 = (**(code **)(*piVar2 + 0x2c))();
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*DAT_00b5ac0c + 0x10))();
    if (cVar1 == '\0') {
      piStack_84 = (int *)0x4a2dcf;
      iVar3 = FUN_004a8060();
      if (iVar3 == 0) {
        local_4 = (undefined1 *)apuStack_9c;
        FUN_00401830(s_<<_cannot_open_file_>>__s_009af1e0);
        uVar4 = FUN_00404230(&local_50);
        local_c = (void *)CONCAT31(local_c._1_3_,5);
        FUN_00796d50(uVar4);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      piStack_84 = (int *)0x4a2e49;
      cVar1 = (**(code **)(*piVar2 + 0x10))();
      if (cVar1 == '\0') {
        local_4 = (undefined1 *)apuStack_9c;
        FUN_00401830(s_<<_invalid_file_format_>>__s_009af200);
        uVar4 = FUN_00404230(&local_50);
        local_c._0_1_ = 6;
        goto LAB_004a2e84;
      }
    }
    cVar1 = (**(code **)(*piVar2 + 0x2c))();
    if (cVar1 == '\0') {
      FUN_00401830();
      puStack_8._0_1_ = 7;
      FUN_00406880();
      puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  iVar3 = *piVar2;
  (**(code **)(*DAT_00b5a6ac + 0x18))();
  (**(code **)(iVar3 + 0x18))();
  (**(code **)(*piVar2 + 0x1c))();
  if (uStack_1c < 0x10) {
    ExceptionList = local_14;
    return piVar2;
  }
  piStack_84 = (int *)0x4a2f27;
  _free(pvStack_30);
  return extraout_EAX_00;
}


// ==== FUN_004a2f50 @ 0x004a2f50 ====

/* WARNING: Removing unreachable block (ram,0x004a2fc2) */

void FUN_004a2f50(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  undefined1 auStack_26 [22];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097ecf0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a7d0 + 4))(param_1);
  if (piVar2 == (int *)0x0) {
    FUN_00401740(s_pResource____NULL_009af23c,0x11);
    puStack_8 = (undefined1 *)0x0;
    FUN_00406880(auStack_26 + -6);
    puStack_8 = (undefined1 *)0xffffffff;
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  (**(code **)(*piVar2 + 0x20))();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_004a3000 @ 0x004a3000 ====

void FUN_004a3000(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  void *unaff_EBX;
  undefined1 local_48 [16];
  uint uStack_38;
  void *pvStack_30;
  undefined1 local_2c [4];
  undefined1 local_28;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ed15;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_004a7bb0(local_48,param_1);
  local_4 = 0;
  pvVar1 = operator_new(0xe4);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_004aa110(local_48);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004a88a0(param_2,param_3,param_4);
  local_14 = (void *)0xf;
  local_18 = 0;
  local_28 = 0;
  local_10 = 0xffff;
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 1;
  iVar3 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(iVar3 + 0x28) = 1;
  (**(code **)(*DAT_00b5a7d0 + 8))(local_2c,piVar2);
  iVar3 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(iVar3 + 0x28) = 0;
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  uStack_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  uStack_1c = 0xf;
  if (uStack_38 < 0x10) {
    ExceptionList = local_14;
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_004a3130 @ 0x004a3130 ====

void FUN_004a3130(undefined4 param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  void *unaff_EBX;
  undefined1 local_48 [16];
  uint uStack_38;
  void *pvStack_30;
  undefined1 local_2c [4];
  undefined1 local_28;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ed3a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_004a7bb0(local_48,param_1);
  local_4 = 0;
  pvVar1 = operator_new(0x48);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_004adad0(local_48);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004ad750();
  local_14 = (void *)0xf;
  local_18 = 0;
  local_28 = 0;
  local_10 = 0xffff;
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 4;
  iVar3 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(iVar3 + 0x28) = 1;
  (**(code **)(*DAT_00b5a7d0 + 8))(local_2c,piVar2);
  iVar3 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(iVar3 + 0x28) = 0;
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  uStack_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  uStack_1c = 0xf;
  if (uStack_38 < 0x10) {
    ExceptionList = local_14;
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_004a3240 @ 0x004a3240 ====

void FUN_004a3240(undefined4 param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  void *unaff_EBX;
  undefined1 local_48 [16];
  uint uStack_38;
  void *pvStack_30;
  undefined1 local_2c [4];
  undefined1 local_28;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ed5f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_004a7bb0(local_48,param_1);
  local_4 = 0;
  pvVar1 = operator_new(0x48);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_004ae890(local_48);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004ae510();
  local_14 = (void *)0xf;
  local_18 = 0;
  local_28 = 0;
  local_10 = 0xffff;
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 2;
  iVar3 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(iVar3 + 0x28) = 1;
  (**(code **)(*DAT_00b5a7d0 + 8))(local_2c,piVar2);
  iVar3 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(iVar3 + 0x28) = 0;
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  uStack_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  uStack_1c = 0xf;
  if (uStack_38 < 0x10) {
    ExceptionList = local_14;
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_004a3350 @ 0x004a3350 ====

void FUN_004a3350(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  void *unaff_EBX;
  undefined1 local_48 [16];
  uint uStack_38;
  void *pvStack_30;
  undefined1 local_2c [4];
  undefined1 local_28;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ed84;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_004a7bb0(local_48,param_1);
  local_4 = 0;
  pvVar1 = operator_new(0x58);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_004af3f0(local_48);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004af4e0(param_2,param_3);
  local_14 = (void *)0xf;
  local_18 = 0;
  local_28 = 0;
  local_10 = 0xffff;
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 3;
  iVar3 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(iVar3 + 0x28) = 1;
  (**(code **)(*DAT_00b5a7d0 + 8))(local_2c,piVar2);
  iVar3 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(iVar3 + 0x28) = 0;
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  uStack_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  uStack_1c = 0xf;
  if (uStack_38 < 0x10) {
    ExceptionList = local_14;
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_004a3470 @ 0x004a3470 ====

void FUN_004a3470(int param_1)

{
  undefined4 uVar1;
  undefined1 local_48 [4];
  void *local_44;
  uint local_30;
  void *local_2c;
  undefined1 local_28;
  uint local_18;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097ed9e;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  local_10 = (void *)0xffff;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  uVar1 = FUN_004a7bb0(local_48,param_1);
  local_4._0_1_ = 1;
  FUN_00401660(uVar1,0,0xffffffff);
  local_4 = (uint)local_4._1_3_ << 8;
  if (0xf < local_30) {
    _free(local_44);
    return;
  }
  local_10 = *(void **)(param_1 + 0x1c);
  (**(code **)(*DAT_00b5a7d0 + 0x10))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_004a3530 @ 0x004a3530 ====

int * FUN_004a3530(int param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *extraout_EAX;
  int *extraout_EAX_00;
  int *extraout_EAX_01;
  void *unaff_EBX;
  undefined1 local_6c [16];
  uint auStack_5c [2];
  void *pvStack_54;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 local_3c;
  undefined4 local_38;
  void *local_34;
  undefined1 uStack_30;
  undefined4 uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int *piStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097edc0;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x14) == 0) {
    return (int *)0x0;
  }
  if (*(int *)(param_1 + 0x1c) == 0xffff) {
    return (int *)0x0;
  }
  ExceptionList = &local_c;
  FUN_004a7bb0(local_6c,param_1);
  pvVar1 = *(void **)(param_1 + 0x1c);
  local_4 = 0;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  FUN_00401660(local_6c,0,0xffffffff);
  local_4 = CONCAT31(local_4._1_3_,1);
  local_34 = pvVar1;
  piVar3 = (int *)(**(code **)(*DAT_00b5a7d0 + 4))(local_50);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)FUN_004a7580(&pvStack_54);
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    uStack_18 = 0xffff;
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
    piStack_14 = piVar3;
    FUN_00401660(&pvStack_54,0,0xffffffff);
    uStack_18 = local_38;
    (**(code **)(*DAT_00b5ac0c + 4))(&local_34);
    iVar2 = *piVar3;
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    (**(code **)(iVar2 + 0x18))(uVar4);
    (**(code **)(*piVar3 + 0x1c))();
    (**(code **)(*DAT_00b5a7d0 + 8))(auStack_5c,piVar3);
    if (0xf < uStack_20) {
      _free(local_34);
      return extraout_EAX;
    }
    uStack_20 = 0xf;
    uStack_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
  }
  else {
    iVar2 = *piVar3;
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    (**(code **)(iVar2 + 0x18))(uVar4);
    (**(code **)(*piVar3 + 0x1c))();
  }
  if (0xf < uStack_40) {
    _free(pvStack_54);
    return extraout_EAX_00;
  }
  uStack_40 = 0xf;
  uStack_44 = 0;
  pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
  if (auStack_5c[0] < 0x10) {
    ExceptionList = piStack_14;
    return piVar3;
  }
  _free(unaff_EBX);
  return extraout_EAX_01;
}


// ==== FUN_004a3700 @ 0x004a3700 ====

void FUN_004a3700(byte param_1)

{
  void *in_ECX;
  
  FUN_004a28b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004a3720 @ 0x004a3720 ====

void FUN_004a3720(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af4d8;
  return;
}


// ==== FUN_004a3730 @ 0x004a3730 ====

void FUN_004a3730(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af4d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004a3750 @ 0x004a3750 ====

int FUN_004a3750(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0xc;
}


// ==== FUN_004a3770 @ 0x004a3770 ====

undefined4 * FUN_004a3770(undefined4 param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar2 = *(char *)((int)puVar3 + 0x2d);
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
    cVar2 = *(char *)((int)puVar4 + 0x2d);
  }
  return puVar1;
}


// ==== FUN_004a37b0 @ 0x004a37b0 ====

void FUN_004a37b0(void)

{
  undefined4 *puVar1;
  
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
  return;
}


// ==== FUN_004a37f0 @ 0x004a37f0 ====

void FUN_004a37f0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x24) = **(undefined4 **)(*(int *)(in_ECX + 0x18) + 4);
  return;
}


// ==== FUN_004a3810 @ 0x004a3810 ====

void FUN_004a3810(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x28) = param_1;
  *(undefined4 *)(in_ECX + 0x24) = **(undefined4 **)(*(int *)(in_ECX + 0x18) + param_1 * 0xc + 4);
  return;
}


// ==== FUN_004a3830 @ 0x004a3830 ====

undefined4 FUN_004a3830(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  if (*(int *)(in_ECX + 0x24) == *(int *)(iVar1 + 4 + *(int *)(in_ECX + 0x28) * 0xc)) {
    uVar4 = *(int *)(in_ECX + 0x28) + 1;
    *(uint *)(in_ECX + 0x28) = uVar4;
    if (0x1b < uVar4) {
      return 0;
    }
    iVar2 = *(int *)(iVar1 + 8 + uVar4 * 0xc);
    while (iVar2 == 0) {
      uVar4 = uVar4 + 1;
      *(uint *)(in_ECX + 0x28) = uVar4;
      iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + 8 + uVar4 * 0xc);
    }
    *(int *)(in_ECX + 0x24) = **(int **)(iVar1 + uVar4 * 0xc + 4);
  }
  uVar3 = *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x28);
  FUN_00699bf0();
  return uVar3;
}


// ==== FUN_004a38b0 @ 0x004a38b0 ====

undefined4 FUN_004a38b0(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int in_ECX;
  int local_4;
  
  iVar2 = param_1;
  iVar1 = *(int *)(in_ECX + 0x18);
  if ((iVar1 == 0) || ((uint)((*(int *)(in_ECX + 0x1c) - iVar1) / 0xc) <= *(uint *)(param_1 + 0x1c))
     ) {
                    /* WARNING: Subroutine does not return */
    FUN_004a5260();
  }
  iVar1 = iVar1 + *(uint *)(param_1 + 0x1c) * 0xc;
  param_1 = FUN_004a3770(param_1);
  if (param_1 != *(int *)(iVar1 + 4)) {
    cVar3 = FUN_00415da0(iVar2,param_1 + 0xc);
    if (cVar3 == '\0') {
      piVar4 = &param_1;
      goto LAB_004a391b;
    }
  }
  local_4 = *(int *)(iVar1 + 4);
  piVar4 = &local_4;
LAB_004a391b:
  if (*piVar4 == *(int *)(iVar1 + 4)) {
    return 0;
  }
  return *(undefined4 *)(*piVar4 + 0x28);
}


// ==== FUN_004a3940 @ 0x004a3940 ====

void FUN_004a3940(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_80 [16];
  undefined4 uStack_70;
  undefined4 local_48;
  undefined4 uStack_40;
  uint uStack_3c;
  void *pvStack_34;
  undefined1 auStack_30 [12];
  undefined4 uStack_24;
  uint uStack_20;
  undefined4 uStack_14;
  undefined4 *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097ee10;
  local_c = ExceptionList;
  iVar3 = *(int *)(in_ECX + 0x18);
  if ((iVar3 == 0) ||
     ((uint)((*(int *)(in_ECX + 0x1c) - iVar3) / 0xc) <= *(uint *)((int)param_1 + 0x1c))) {
    ExceptionList = &local_c;
                    /* WARNING: Subroutine does not return */
    FUN_004a5260();
  }
  iVar3 = iVar3 + *(uint *)((int)param_1 + 0x1c) * 0xc;
  ExceptionList = &local_c;
  param_1 = (int *)FUN_004a3770();
  if ((param_1 == (int *)*(int *)(iVar3 + 4)) || (cVar1 = FUN_00415da0(), cVar1 != '\0')) {
    local_48 = *(int *)(iVar3 + 4);
    piVar2 = &local_48;
  }
  else {
    piVar2 = (int *)&param_1;
  }
  if (*piVar2 != *(int *)(iVar3 + 4)) {
    param_1 = *(int **)(*piVar2 + 0x28);
    iVar3 = (**(code **)(*param_1 + 4))();
    if ((*(int *)(iVar3 + 0x28) == 0) && (cVar1 = (**(code **)(*param_1 + 0x2c))(), cVar1 != '\0'))
    {
      FUN_004a5380();
      FUN_00401830(&DAT_009af430);
      FUN_00797530(auStack_30);
      local_c = (undefined4 *)0x0;
      FUN_00401830(s__RES__s__009af434);
      FUN_00797530(auStack_30 + -0x1c);
      local_c = (undefined4 *)CONCAT31(local_c._1_3_,1);
      (**(code **)(*DAT_00b5a688 + 8))();
      if (0xf < uStack_3c) {
        uStack_70 = 0x4a3a97;
        _free(auStack_80);
        return;
      }
      uStack_3c = 0xf;
      uStack_40 = 0;
      uStack_14 = 0xffffffff;
      if (0xf < uStack_20) {
        uStack_70 = 0x4a3ac4;
        _free(pvStack_34);
        return;
      }
      uStack_20 = 0xf;
      uStack_24 = 0;
      pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
      uStack_70 = 0x4a3ade;
      (**(code **)*local_c)();
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004a3b00 @ 0x004a3b00 ====

/* WARNING: Removing unreachable block (ram,0x004a3bee) */

void FUN_004a3b00(uint param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  code *pcVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  undefined4 *puVar8;
  int in_ECX;
  int *piVar9;
  uint uStack_90;
  uint uStack_8c;
  uint uStack_84;
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
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
  puStack_8 = &LAB_0097ee3a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uStack_84 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  if (uStack_84 < param_1) {
    uStack_84 = 0;
  }
  else {
    uStack_84 = uStack_84 - param_1;
  }
  uStack_8c = 0;
  uStack_90 = 0;
  while( true ) {
    iVar1 = *(int *)(in_ECX + 0x18);
    if ((iVar1 == 0) || ((uint)((*(int *)(in_ECX + 0x1c) - iVar1) / 0xc) <= uStack_8c)) {
                    /* WARNING: Subroutine does not return */
      FUN_004a5260();
    }
    piVar2 = *(int **)(iVar1 + 4 + uStack_90);
    piVar9 = (int *)*piVar2;
    if (piVar9 != piVar2) {
      do {
        piVar2 = (int *)piVar9[10];
        if (piVar2 == (int *)0x0) {
          FUN_00401740();
          uStack_4 = 0;
          FUN_00406880();
          uStack_4 = 0xffffffff;
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        iVar7 = (**(code **)(*piVar2 + 4))();
        uVar3 = *(uint *)(iVar7 + 0x20);
        cVar6 = (**(code **)(*piVar2 + 0x2c))();
        if (((cVar6 == '\0') || (iVar7 = (**(code **)(*piVar2 + 4))(), *(int *)(iVar7 + 0x28) != 0))
           || (uStack_84 <= uVar3)) {
          if (*(char *)((int)piVar9 + 0x2d) == '\0') {
            piVar2 = (int *)piVar9[2];
            if (*(char *)((int)piVar2 + 0x2d) == '\0') {
              cVar6 = *(char *)(*piVar2 + 0x2d);
              piVar9 = piVar2;
              piVar2 = (int *)*piVar2;
              while (cVar6 == '\0') {
                cVar6 = *(char *)(*piVar2 + 0x2d);
                piVar9 = piVar2;
                piVar2 = (int *)*piVar2;
              }
            }
            else {
              cVar6 = *(char *)(piVar9[1] + 0x2d);
              piVar5 = (int *)piVar9[1];
              piVar2 = piVar9;
              while ((piVar9 = piVar5, cVar6 == '\0' && (piVar2 == (int *)piVar9[2]))) {
                cVar6 = *(char *)(piVar9[1] + 0x2d);
                piVar5 = (int *)piVar9[1];
                piVar2 = piVar9;
              }
            }
          }
        }
        else {
          (**(code **)(*piVar2 + 4))();
          FUN_004022a0();
          uStack_4 = 1;
          FUN_00796d50();
          uStack_4 = 0xffffffff;
          if (0xf < uStack_2c) {
            _free(pvStack_40);
            return;
          }
          uStack_2c = 0xf;
          uStack_30 = 0;
          pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
          (**(code **)*piVar2)();
          puVar8 = (undefined4 *)FUN_004a5380();
          piVar9 = (int *)*puVar8;
        }
      } while (piVar9 != *(int **)(iVar1 + uStack_90 + 4));
    }
    FUN_00401740(&DAT_009af464,2);
    FUN_00797530(auStack_28);
    uStack_4 = 2;
    FUN_00401740(s__RES__s__009af468,8);
    FUN_00797530(auStack_60);
    uStack_4 = CONCAT31(uStack_4._1_3_,3);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_48) break;
    uStack_48 = 0xf;
    uStack_4c = 0;
    pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
    uStack_4 = 0xffffffff;
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uStack_8c = uStack_8c + 1;
    uStack_90 = uStack_90 + 0xc;
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    if (0x14f < uStack_90) {
      ExceptionList = pvStack_c;
      return;
    }
  }
  _free(pvStack_5c);
  return;
}


// ==== FUN_004a3e40 @ 0x004a3e40 ====

void FUN_004a3e40(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  void *_Memory;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int in_ECX;
  uint uVar10;
  uint local_90;
  uint uStack_8c;
  undefined1 auStack_7c [4];
  void *pvStack_78;
  undefined4 uStack_68;
  uint uStack_64;
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
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
  puStack_8 = &LAB_0097ee64;
  pvStack_c = ExceptionList;
  local_90 = 0;
  uVar10 = 0;
  ExceptionList = &pvStack_c;
  do {
    iVar9 = *(int *)(in_ECX + 0x18);
    if ((iVar9 == 0) || ((uint)((*(int *)(in_ECX + 0x1c) - iVar9) / 0xc) <= local_90))
    goto LAB_004a4346;
    puVar2 = *(undefined4 **)(iVar9 + 4 + uVar10);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      (**(code **)(*(int *)puVar3[10] + 0x24))();
      if (*(char *)((int)puVar3 + 0x2d) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x2d) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x2d);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x2d);
            puVar6 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    local_90 = local_90 + 1;
    uVar10 = uVar10 + 0xc;
  } while (uVar10 < 0x150);
  local_90 = 0;
  uStack_8c = 0;
  do {
    iVar9 = *(int *)(in_ECX + 0x18);
    if ((iVar9 == 0) || ((uint)((*(int *)(in_ECX + 0x1c) - iVar9) / 0xc) <= local_90))
    goto LAB_004a4346;
    puVar2 = *(undefined4 **)(uStack_8c + 4 + iVar9);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      piVar5 = (int *)puVar3[10];
      iVar7 = (**(code **)(*piVar5 + 4))();
      if (*(int *)(iVar7 + 0x28) != 0) {
        (**(code **)(*piVar5 + 4))();
        FUN_00401740(s_Locked_Resource___s_009af474,0x13);
        uVar8 = FUN_00404230(auStack_44);
        uStack_4 = 0;
        FUN_00796d50(uVar8);
        uStack_4 = 0xffffffff;
        if (0xf < uStack_2c) {
          _free(pvStack_40);
          return;
        }
        uStack_2c = 0xf;
        uStack_30 = 0;
        pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      }
      if (*(char *)((int)puVar3 + 0x2d) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x2d) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x2d);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x2d);
            puVar6 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    puVar2 = *(undefined4 **)(uStack_8c + 4 + iVar9);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      piVar5 = (int *)puVar3[10];
      iVar9 = (**(code **)(*piVar5 + 4))();
      if (*(int *)(iVar9 + 0x28) == 0) {
        (**(code **)(*piVar5 + 4))();
        FUN_00401740(s_Unlocked_Resource___s_009af488,0x15);
        uVar8 = FUN_00404230(auStack_7c);
        uStack_4 = 1;
        FUN_00796d50(uVar8);
        uStack_4 = 0xffffffff;
        if (0xf < uStack_64) {
          _free(pvStack_78);
          return;
        }
        uStack_64 = 0xf;
        uStack_68 = 0;
        pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
      }
      if (*(char *)((int)puVar3 + 0x2d) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x2d) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x2d);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x2d);
            puVar6 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    local_90 = local_90 + 1;
    uStack_8c = uStack_8c + 0xc;
  } while (uStack_8c < 0x150);
  uStack_8c = 0;
  local_90 = 0;
  while ((iVar9 = *(int *)(in_ECX + 0x18), iVar9 != 0 &&
         (uStack_8c < (uint)((*(int *)(in_ECX + 0x1c) - iVar9) / 0xc)))) {
    iVar7 = local_90 + iVar9;
    if (*(int *)(local_90 + 8 + iVar9) != 0) {
      FUN_0082c4f0();
      _Memory = *(void **)(*(int *)(iVar7 + 4) + 4);
      if (*(char *)((int)_Memory + 0x2d) == '\0') {
        FUN_004a5340();
        if (*(uint *)((int)_Memory + 0x24) < 0x10) {
          *(undefined4 *)((int)_Memory + 0x24) = 0xf;
          *(undefined4 *)((int)_Memory + 0x20) = 0;
          *(undefined1 *)((int)_Memory + 0x10) = 0;
          _free(_Memory);
          return;
        }
        _free(*(void **)((int)_Memory + 0x10));
        return;
      }
      *(int *)(*(int *)(iVar7 + 4) + 4) = *(int *)(iVar7 + 4);
      *(undefined4 *)(iVar7 + 8) = 0;
      *(undefined4 *)*(undefined4 *)(iVar7 + 4) = *(undefined4 *)(iVar7 + 4);
      *(int *)(*(int *)(iVar7 + 4) + 8) = *(int *)(iVar7 + 4);
    }
    FUN_00401740(&DAT_009af4a0,2);
    FUN_00797530(auStack_28);
    uStack_4 = 2;
    FUN_00401740(s__RES__s__009af4a4,8);
    FUN_00797530(auStack_60);
    uStack_4 = CONCAT31(uStack_4._1_3_,3);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_48) {
      _free(pvStack_5c);
      return;
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
    uStack_4 = 0xffffffff;
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uStack_8c = uStack_8c + 1;
    local_90 = local_90 + 0xc;
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    if (0x14f < local_90) {
      ExceptionList = pvStack_c;
      return;
    }
  }
LAB_004a4346:
                    /* WARNING: Subroutine does not return */
  FUN_004a5260();
}


// ==== FUN_004a4350 @ 0x004a4350 ====

/* WARNING: Removing unreachable block (ram,0x004a441d) */

void FUN_004a4350(undefined1 *param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int in_ECX;
  uint uVar9;
  int *piVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  undefined1 auStack_a8 [4];
  undefined1 local_a4;
  undefined4 uStack_98;
  undefined4 local_94;
  undefined4 *local_90;
  uint local_78;
  uint local_74;
  undefined1 local_60 [4];
  void *pvStack_5c;
  uint uStack_48;
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
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ee96;
  pvStack_c = ExceptionList;
  local_90 = (undefined4 *)local_60;
  local_94 = 0x4a437f;
  ExceptionList = &pvStack_c;
  FUN_004a7bb0();
  local_4 = 0;
  local_78 = 0;
  local_74 = 0;
  do {
    iVar8 = *(int *)(in_ECX + 0x18);
    if ((iVar8 == 0) || ((uint)((*(int *)(in_ECX + 0x1c) - iVar8) / 0xc) <= local_78)) {
                    /* WARNING: Subroutine does not return */
      FUN_004a5260();
    }
    piVar1 = *(int **)(local_74 + 4 + iVar8);
    piVar10 = (int *)*piVar1;
    if (piVar10 != piVar1) {
      do {
        piVar1 = (int *)piVar10[10];
        iVar6 = (**(code **)(*piVar1 + 4))();
        uVar2 = *(uint *)(iVar6 + 0x14);
        if (*(uint *)(iVar6 + 0x18) < 0x10) {
          pbVar7 = (byte *)(iVar6 + 4);
        }
        else {
          pbVar7 = *(byte **)(iVar6 + 4);
        }
        uVar3 = *(uint *)(param_1 + 0x14);
        if (uVar3 == 0) {
LAB_004a445a:
          if ((uVar2 <= uVar3) && (uVar3 == uVar2)) {
            iVar8 = (**(code **)(*piVar1 + 4))();
            if ((*(int *)(iVar8 + 0x28) == 0) &&
               (cVar5 = (**(code **)(*piVar1 + 0x2c))(), cVar5 != '\0')) {
              local_90 = &param_1;
              local_94 = 0x4a4602;
              FUN_004a5380();
              local_94 = 1;
              uStack_98 = 0x4a460a;
              (**(code **)*piVar1)();
              goto LAB_004a470d;
            }
            param_1 = auStack_a8;
            local_90 = (undefined4 *)0xf;
            local_94 = 0;
            local_a4 = 0;
            FUN_00401740(&DAT_009af4b0,2);
            FUN_00797530(auStack_44);
            local_4._0_1_ = 1;
            param_1 = auStack_a8;
            local_90 = (undefined4 *)0xf;
            local_94 = 0;
            local_a4 = 0;
            FUN_00401740(s__RES__s__009af4b4,8);
            local_90 = (undefined4 *)FUN_00797530(auStack_28);
            local_4 = CONCAT31(local_4._1_3_,2);
            local_94 = 0x4a46c9;
            (**(code **)(*DAT_00b5a688 + 8))();
            if (0xf < uStack_10) {
              local_90 = (undefined4 *)0x4a46d9;
              _free(pvStack_24);
              return;
            }
            uStack_10 = 0xf;
            uStack_14 = 0;
            pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
            if (0xf < uStack_2c) {
              local_90 = (undefined4 *)0x4a46f9;
              _free(pvStack_40);
              return;
            }
            if (uStack_48 < 0x10) {
              ExceptionList = pvStack_c;
              return;
            }
            goto LAB_004a4714;
          }
        }
        else {
          uVar9 = uVar3;
          if (uVar2 <= uVar3) {
            uVar9 = uVar2;
          }
          if (*(uint *)(param_1 + 0x18) < 0x10) {
            pbVar11 = param_1 + 4;
          }
          else {
            pbVar11 = *(byte **)(param_1 + 4);
          }
          bVar12 = false;
          iVar6 = 0;
          bVar13 = true;
          do {
            if (uVar9 == 0) break;
            uVar9 = uVar9 - 1;
            bVar12 = *pbVar11 < *pbVar7;
            bVar13 = *pbVar11 == *pbVar7;
            pbVar11 = pbVar11 + 1;
            pbVar7 = pbVar7 + 1;
          } while (bVar13);
          if (!bVar13) {
            iVar6 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          }
          if (iVar6 == 0) goto LAB_004a445a;
        }
        if (*(char *)((int)piVar10 + 0x2d) == '\0') {
          piVar1 = (int *)piVar10[2];
          if (*(char *)((int)piVar1 + 0x2d) == '\0') {
            cVar5 = *(char *)(*piVar1 + 0x2d);
            piVar10 = piVar1;
            piVar1 = (int *)*piVar1;
            while (cVar5 == '\0') {
              cVar5 = *(char *)(*piVar1 + 0x2d);
              piVar10 = piVar1;
              piVar1 = (int *)*piVar1;
            }
          }
          else {
            cVar5 = *(char *)(piVar10[1] + 0x2d);
            piVar4 = (int *)piVar10[1];
            piVar1 = piVar10;
            while ((piVar10 = piVar4, cVar5 == '\0' && (piVar1 == (int *)piVar10[2]))) {
              cVar5 = *(char *)(piVar10[1] + 0x2d);
              piVar4 = (int *)piVar10[1];
              piVar1 = piVar10;
            }
          }
        }
      } while (piVar10 != *(int **)(local_74 + iVar8 + 4));
    }
    local_90 = (undefined4 *)0xf;
    local_94 = 0;
    local_a4 = 0;
    FUN_00401740(&DAT_009af4c0,2);
    FUN_00797530(auStack_28);
    local_4._0_1_ = 3;
    local_90 = (undefined4 *)0xf;
    local_94 = 0;
    local_a4 = 0;
    FUN_00401740(s__RES__s__009af4c4,8);
    local_90 = (undefined4 *)FUN_00797530(auStack_44);
    local_4._0_1_ = 4;
    local_94 = 0x4a455d;
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_2c) {
      local_90 = (undefined4 *)0x4a4572;
      _free(pvStack_40);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    local_4 = (uint)local_4._1_3_ << 8;
    if (0xf < uStack_10) {
      local_90 = (undefined4 *)0x4a459a;
      _free(pvStack_24);
      return;
    }
    local_78 = local_78 + 1;
    local_74 = local_74 + 0xc;
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  } while (local_74 < 0x150);
LAB_004a470d:
  if (uStack_48 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
LAB_004a4714:
  local_90 = (undefined4 *)0x4a4719;
  _free(pvStack_5c);
  return;
}


// ==== FUN_004a4740 @ 0x004a4740 ====

undefined4 FUN_004a4740(int param_1)

{
  int iVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int *in_ECX;
  void *pvStack_6c;
  undefined1 auStack_68 [12];
  undefined4 uStack_5c;
  uint uStack_58;
  void *pvStack_50;
  undefined1 auStack_4c [16];
  uint uStack_3c;
  void *pvStack_2c;
  undefined4 uStack_1c;
  void *pvStack_18;
  int iStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097eeb8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*in_ECX + 4))();
  if (iVar1 != 0) {
    ExceptionList = pvStack_10;
    return 0;
  }
  if ((in_ECX[6] == 0) || ((uint)((in_ECX[7] - in_ECX[6]) / 0xc) <= *(uint *)(param_1 + 0x1c))) {
                    /* WARNING: Subroutine does not return */
    FUN_004a5260();
  }
  pvStack_18 = (void *)0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  FUN_00401660();
  iStack_14 = param_1;
  puStack_8 = (undefined1 *)0x0;
  FUN_004a5ab0();
  puStack_8 = (undefined1 *)0xffffffff;
  if ((void *)0xf < pvStack_18) {
    _free(pvStack_2c);
    return extraout_EAX;
  }
  FUN_00401740(&DAT_009af420,2);
  FUN_00797530(auStack_4c);
  puStack_8 = (undefined1 *)0x1;
  FUN_00401740(s__RES__s__009af424,8);
  FUN_00797530(auStack_68);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a688 + 8))();
  if (0xf < uStack_58) {
    _free(pvStack_6c);
    return extraout_EAX_00;
  }
  uStack_58 = 0xf;
  uStack_5c = 0;
  if (uStack_3c < 0x10) {
    ExceptionList = pvStack_18;
    return 1;
  }
  _free(pvStack_50);
  return extraout_EAX_01;
}


// ==== FUN_004a4920 @ 0x004a4920 ====

void FUN_004a4920(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097eee0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009af500;
  local_4 = 2;
  FUN_004a3e40();
  DAT_00b5a7d0 = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_004a5ee0();
  if (in_ECX[2] == 0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009af4d8;
    ExceptionList = local_c;
    return;
  }
  FUN_00405de0(in_ECX[2],in_ECX[3],in_ECX + 1,in_ECX);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004a49b0 @ 0x004a49b0 ====

/* WARNING: Removing unreachable block (ram,0x004a518f) */
/* WARNING: Removing unreachable block (ram,0x004a5105) */
/* WARNING: Removing unreachable block (ram,0x004a507b) */
/* WARNING: Removing unreachable block (ram,0x004a4ff1) */
/* WARNING: Removing unreachable block (ram,0x004a4f67) */
/* WARNING: Removing unreachable block (ram,0x004a4edd) */
/* WARNING: Removing unreachable block (ram,0x004a4e53) */
/* WARNING: Removing unreachable block (ram,0x004a4dc9) */
/* WARNING: Removing unreachable block (ram,0x004a4d3f) */
/* WARNING: Removing unreachable block (ram,0x004a4cb5) */
/* WARNING: Removing unreachable block (ram,0x004a4c2b) */
/* WARNING: Removing unreachable block (ram,0x004a4ba1) */
/* WARNING: Removing unreachable block (ram,0x004a4b17) */
/* WARNING: Removing unreachable block (ram,0x004a4ad2) */
/* WARNING: Removing unreachable block (ram,0x004a4b5c) */
/* WARNING: Removing unreachable block (ram,0x004a4be6) */
/* WARNING: Removing unreachable block (ram,0x004a4c70) */
/* WARNING: Removing unreachable block (ram,0x004a4cfa) */
/* WARNING: Removing unreachable block (ram,0x004a4d84) */
/* WARNING: Removing unreachable block (ram,0x004a4e0e) */
/* WARNING: Removing unreachable block (ram,0x004a4e98) */
/* WARNING: Removing unreachable block (ram,0x004a4f22) */
/* WARNING: Removing unreachable block (ram,0x004a4fac) */
/* WARNING: Removing unreachable block (ram,0x004a5036) */
/* WARNING: Removing unreachable block (ram,0x004a50c0) */
/* WARNING: Removing unreachable block (ram,0x004a514a) */
/* WARNING: Removing unreachable block (ram,0x004a51cf) */
/* WARNING: Removing unreachable block (ram,0x004a4a8d) */

int FUN_004a49b0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  int unaff_EDI;
  undefined1 auStack_2e [18];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097efe8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009af500;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  local_4 = 2;
  in_ECX[9] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a7d0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a7d0 = in_ECX;
  }
  iVar1 = FUN_004a37b0();
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(int *)(iVar1 + 4) = iVar1;
  *(int *)iVar1 = iVar1;
  *(int *)(iVar1 + 8) = iVar1;
  FUN_004a62b0(0x1c);
  *(undefined4 *)(unaff_EDI + 0x28) = 0;
  FUN_00401740(s_TEXTURE_009af320,7);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(&DAT_009af328,3);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_MAPOBJECT_009af32c,9);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_MAPATTR_009af338,7);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_MAPEFFECT_009af340,9);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_MAPPACK_009af34c,7);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_MAPLIGHT_009af354,8);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(&DAT_009af360,4);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(&DAT_009af368,4);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_BONEANIM_009af370,8);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_SHADER_009af37c,6);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_BINARY_009af384,6);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_OBJECTPACK_009af38c,10);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_EFFECT_009af398,6);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_WATER_009af3a0,5);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_PROPERTY_009af3a8,8);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_TEXTUREPACK_009af3b4,0xb);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_MOUSE_009af3c0,5);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_SCRIPT_009af3c8,6);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(&DAT_009af3d0,3);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_GAMEUIINFO_009af3d4,10);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_PRELOAD_009af3e0,7);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_EFFECTDATA_009af3e8,10);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_EFFECTSCENE_009af3f4,0xb);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_EFFECTMODEL_009af400,0xb);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_STRING_009af40c,6);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(s_SOUND_009af414,5);
  FUN_00406720(auStack_2e + -10);
  FUN_00401740(&DAT_009af41c,3);
  FUN_00406720(auStack_2e + -10);
  ExceptionList = pvStack_1c;
  return unaff_EDI;
}


// ==== FUN_004a5200 @ 0x004a5200 ====

undefined4 FUN_004a5200(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097effd;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x2c);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_004a49b0(pvVar1);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_004a5260 @ 0x004a5260 ====

void FUN_004a5260(void)

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
  puStack_8 = &LAB_0097f018;
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


// ==== FUN_004a52d0 @ 0x004a52d0 ====

void FUN_004a52d0(void)

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
  puStack_8 = &LAB_0097f018;
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


// ==== FUN_004a5340 @ 0x004a5340 ====

void FUN_004a5340(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_004a5340(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004a5380 @ 0x004a5380 ====

/* WARNING: Removing unreachable block (ram,0x004a5490) */
/* WARNING: Removing unreachable block (ram,0x004a54a1) */
/* WARNING: Removing unreachable block (ram,0x004a54aa) */
/* WARNING: Removing unreachable block (ram,0x004a54ad) */
/* WARNING: Removing unreachable block (ram,0x004a549d) */
/* WARNING: Removing unreachable block (ram,0x004a54bb) */
/* WARNING: Removing unreachable block (ram,0x004a54c8) */
/* WARNING: Removing unreachable block (ram,0x004a54d3) */
/* WARNING: Removing unreachable block (ram,0x004a54cf) */
/* WARNING: Removing unreachable block (ram,0x004a54c3) */
/* WARNING: Removing unreachable block (ram,0x004a54d6) */

void FUN_004a5380(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097f018;
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
            goto LAB_004a55a7;
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
LAB_004a55a7:
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


// ==== FUN_004a5650 @ 0x004a5650 ====

void * FUN_004a5650(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097ede1;
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


// ==== Catch@004a56c2 @ 0x004a56c2 ====

void Catch_004a56c2(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004a56e0 @ 0x004a56e0 ====

undefined4 * FUN_004a56e0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097edf0;
  local_10 = ExceptionList;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    ExceptionList = &local_10;
    puVar1 = (undefined4 *)
             FUN_004a5650(local_18,param_2,local_18,param_1 + 3,*(undefined1 *)(param_1 + 0xb));
    if (*(char *)((int)local_18 + 0x2d) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_004a56e0(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_004a56e0(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}


// ==== Catch@004a5771 @ 0x004a5771 ====

void Catch_004a5771(void)

{
  int unaff_EBP;
  
  FUN_004a5340(*(undefined4 *)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004a5790 @ 0x004a5790 ====

void FUN_004a5790(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097f018;
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
  piVar4 = (int *)FUN_004a5650(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004a5889:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_004a5889;
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


// ==== FUN_004a5970 @ 0x004a5970 ====

void FUN_004a5970(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004a5340(piVar6[1]);
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
    FUN_004a5380(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004a5a30 @ 0x004a5a30 ====

void FUN_004a5a30(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  uVar7 = FUN_004a56e0(*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar2);
  *(undefined4 *)(iVar2 + 4) = uVar7;
  piVar3 = *(int **)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0x2d) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0x2d);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0x2d);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)(in_ECX + 4) + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0x2d);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x2d);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)(in_ECX + 4) + 8) = iVar2;
  return;
}


// ==== FUN_004a5ab0 @ 0x004a5ab0 ====

void FUN_004a5ab0(undefined4 *param_1,undefined4 *param_2)

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
  cVar4 = *(char *)((int)puVar5 + 0x2d);
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
    cVar4 = *(char *)((int)puVar6 + 0x2d);
  }
  param_2 = puVar1;
  if (cVar3 != '\0') {
    if (puVar1 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar5 = (undefined4 *)FUN_004a5790(&param_2,1,puVar1,uVar2);
      *param_1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_0079c420();
  }
  puVar5 = param_2;
  cVar4 = FUN_00415da0(param_2 + 3,uVar2);
  if (cVar4 == '\0') {
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
  puVar5 = (undefined4 *)FUN_004a5790(&param_2,cVar3,puVar1,uVar2);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_004a5b80 @ 0x004a5b80 ====

void FUN_004a5b80(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f030;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_004a37b0();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  local_8 = 0;
  FUN_004a5a30(param_1);
  ExceptionList = local_10;
  return;
}


// ==== Catch@004a5bf1 @ 0x004a5bf1 ====

void Catch_004a5bf1(void)

{
  FUN_004a5cf0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004a5c10 @ 0x004a5c10 ====

int FUN_004a5c10(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_1 == param_2) {
    return param_3;
  }
  iVar1 = param_3;
  do {
    if (iVar1 != param_1) {
      FUN_004a5970(&param_3,**(undefined4 **)(iVar1 + 4),*(undefined4 **)(iVar1 + 4));
      FUN_004a5a30(param_1);
    }
    param_1 = param_1 + 0xc;
    iVar1 = iVar1 + 0xc;
  } while (param_1 != param_2);
  return iVar1;
}


// ==== FUN_004a5c60 @ 0x004a5c60 ====

int FUN_004a5c60(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  iVar1 = param_3;
  do {
    param_2 = param_2 + -0xc;
    iVar2 = iVar1 + -0xc;
    if (iVar2 != param_2) {
      FUN_004a5970(&param_3,**(undefined4 **)(iVar1 + -8),*(undefined4 **)(iVar1 + -8));
      FUN_004a5a30(param_2);
    }
    iVar1 = iVar2;
  } while (param_2 != param_1);
  return iVar2;
}


// ==== FUN_004a5cb0 @ 0x004a5cb0 ====

void FUN_004a5cb0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_3;
  iVar1 = param_2;
  for (iVar3 = param_1; iVar3 != iVar1; iVar3 = iVar3 + 0xc) {
    if (iVar3 != iVar2) {
      FUN_004a5970(&param_1,**(undefined4 **)(iVar3 + 4),*(undefined4 **)(iVar3 + 4));
      FUN_004a5a30(iVar2);
    }
  }
  return;
}


// ==== FUN_004a5cf0 @ 0x004a5cf0 ====

void FUN_004a5cf0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004a5970(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004a5d20 @ 0x004a5d20 ====

int FUN_004a5d20(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097f051;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0xc) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_004a5b80(param_1);
    }
    param_3 = param_3 + 0xc;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@004a5d76 @ 0x004a5d76 ====

void Catch_004a5d76(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
  if (iVar1 == *(int *)(unaff_EBP + 0x10)) {
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(0,0);
  }
  FUN_004a5970(unaff_EBP + 0x10,**(undefined4 **)(iVar1 + 4),*(undefined4 **)(iVar1 + 4));
  _free(*(void **)(iVar1 + 4));
  return;
}


// ==== FUN_004a5dd0 @ 0x004a5dd0 ====

void FUN_004a5dd0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097f071;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_004a5b80(param_3);
    }
    param_1 = param_1 + 0xc;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004a5e28 @ 0x004a5e28 ====

void Catch_004a5e28(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
  if (iVar1 == *(int *)(unaff_EBP + 8)) {
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(0,0);
  }
  FUN_004a5970(unaff_EBP + 8,**(undefined4 **)(iVar1 + 4),*(undefined4 **)(iVar1 + 4));
  _free(*(void **)(iVar1 + 4));
  return;
}


// ==== FUN_004a5e80 @ 0x004a5e80 ====

void FUN_004a5e80(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0xc) {
    FUN_004a5cf0();
  }
  return;
}


// ==== FUN_004a5eb0 @ 0x004a5eb0 ====

int FUN_004a5eb0(int param_1,int param_2,undefined4 param_3)

{
  FUN_004a5dd0(param_1,param_2,param_3);
  return param_1 + param_2 * 0xc;
}


// ==== FUN_004a5ee0 @ 0x004a5ee0 ====

void FUN_004a5ee0(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0xc) {
    FUN_004a5cf0();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004a5f30 @ 0x004a5f30 ====

void FUN_004a5f30(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  if (param_2 != param_3) {
    iVar2 = FUN_004a5c10(param_3,*(undefined4 *)(in_ECX + 8),param_2,param_2);
    iVar1 = *(int *)(in_ECX + 8);
    for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0xc) {
      FUN_004a5cf0();
    }
    *(int *)(in_ECX + 8) = iVar2;
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_004a5f90 @ 0x004a5f90 ====

void FUN_004a5f90(int param_1,void *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  int in_ECX;
  uint uVar7;
  uint extraout_ECX;
  undefined1 local_28 [2];
  undefined1 auStack_26 [2];
  undefined4 *local_24;
  void *local_1c;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f088;
  pvStack_10 = ExceptionList;
  local_14 = local_28 + -0xc;
  ExceptionList = &pvStack_10;
  FUN_004a5b80(param_3);
  uVar1 = (uint)param_2;
  iVar4 = *(int *)(in_ECX + 4);
  uVar7 = 0;
  local_8 = 0;
  if (iVar4 != 0) {
    uVar7 = (*(int *)(in_ECX + 0xc) - iVar4) / 0xc;
  }
  if (param_2 != (void *)0x0) {
    if (iVar4 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar4) / 0xc;
    }
    if (0x15555555U - iVar2 < param_2) {
      FUN_004a52d0();
      uVar7 = extraout_ECX;
    }
    iVar2 = param_1;
    if (iVar4 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(int *)(in_ECX + 8) - iVar4) / 0xc;
    }
    if (uVar7 < iVar3 + uVar1) {
      if (0x15555555 - (uVar7 >> 1) < uVar7) {
        uVar7 = 0;
      }
      else {
        uVar7 = uVar7 + (uVar7 >> 1);
      }
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (*(int *)(in_ECX + 8) - iVar4) / 0xc;
      }
      if (uVar7 < iVar4 + uVar1) {
        iVar4 = FUN_004a3750();
        uVar7 = iVar4 + uVar1;
      }
      param_3 = uVar7 * 0xc;
      pvVar5 = operator_new(param_3);
      local_8 = CONCAT31(local_8._1_3_,1);
      param_2 = pvVar5;
      local_1c = pvVar5;
      param_2 = (void *)FUN_004a5d20(*(undefined4 *)(in_ECX + 4),param_1,pvVar5);
      FUN_004a5dd0(param_2,uVar1,local_28);
      param_2 = (void *)((int)param_2 + uVar1 * 0xc);
      FUN_004a5d20(param_1,*(undefined4 *)(in_ECX + 8),param_2);
      local_8 = 0;
      iVar4 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar4 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0xc;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_004a5e80(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = param_3 + (int)pvVar5;
      *(void **)(in_ECX + 8) = (void *)((int)pvVar5 + (uVar1 + iVar4) * 0xc);
      *(void **)(in_ECX + 4) = pvVar5;
    }
    else {
      param_3 = *(uint *)(in_ECX + 8);
      if ((uint)((int)(param_3 - param_1) / 0xc) < uVar1) {
        uVar7 = param_3;
        param_3 = uVar1 * 0xc;
        FUN_004a5d20(param_1,uVar7,uVar1 * 0xc + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004a5eb0(*(int *)(in_ECX + 8),uVar1 - (*(int *)(in_ECX + 8) - iVar2) / 0xc,local_28);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_3;
        local_8 = 0;
        FUN_004a5cb0(iVar2,*(int *)(in_ECX + 8) - param_3,local_28);
      }
      else {
        param_1 = param_3 + uVar1 * -0xc;
        uVar6 = FUN_004a5d20(param_1,param_3,param_3);
        *(undefined4 *)(in_ECX + 8) = uVar6;
        FUN_004a5c60(iVar2,param_1,param_3,param_1);
        FUN_004a5cb0(iVar2,uVar1 * 0xc + iVar2,local_28);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_004a5970(&param_1,*local_24,local_24);
  _free(local_24);
  return;
}


// ==== Catch@004a614e @ 0x004a614e ====

void Catch_004a614e(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_004a5e80(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@004a61fd @ 0x004a61fd ====

void Catch_004a61fd(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0xc;
  FUN_004a5e80(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004a62b0 @ 0x004a62b0 ====

void FUN_004a62b0(uint param_1,undefined1 param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f0a8;
  pvStack_c = ExceptionList;
  iVar2 = *(int *)(in_ECX + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0xc;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0xc;
    }
    ExceptionList = &pvStack_c;
    FUN_004a5f90(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
  }
  else {
    ExceptionList = &pvStack_c;
    if (iVar2 != 0) {
      ExceptionList = &pvStack_c;
      if (param_1 < (uint)((*(int *)(in_ECX + 8) - iVar2) / 0xc)) {
        ExceptionList = &pvStack_c;
        FUN_004a5f30(&param_1,iVar2 + param_1 * 0xc,*(int *)(in_ECX + 8));
      }
    }
  }
  local_4 = 0xffffffff;
  FUN_004a5970(&param_1,*param_3,param_3);
  _free(param_3);
  return;
}


// ==== FUN_004a63a0 @ 0x004a63a0 ====

void FUN_004a63a0(byte param_1)

{
  void *in_ECX;
  
  FUN_004a4920();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004a63c0 @ 0x004a63c0 ====

void FUN_004a63c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af5ec;
  return;
}


// ==== FUN_004a63d0 @ 0x004a63d0 ====

void FUN_004a63d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af5ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004a6410 @ 0x004a6410 ====

void FUN_004a6410(void)

{
  int *piVar1;
  int iVar2;
  
  (**(code **)(*DAT_00b5a7d0 + 0x18))(0);
  piVar1 = (int *)(**(code **)(*DAT_00b5a7d0 + 0x20))();
  while ((piVar1 != (int *)0x0 && (iVar2 = (**(code **)(*piVar1 + 0xc))(), iVar2 == 0))) {
    FUN_004af630();
    piVar1 = (int *)(**(code **)(*DAT_00b5a7d0 + 0x20))();
  }
  return;
}


// ==== FUN_004a6460 @ 0x004a6460 ====

void FUN_004a6460(void)

{
  undefined4 *in_ECX;
  void *unaff_ESI;
  undefined1 auStack_46 [2];
  undefined4 local_44;
  uint local_40;
  void *pvStack_38;
  uint uStack_34;
  undefined4 local_30;
  uint local_2c;
  uint uStack_24;
  void *pvStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f0e0;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009af5fc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a7c8 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a7c8 = in_ECX;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = local_40 & 0xffffff00;
  FUN_00401740(s_res_releaseall_009af560,0xe);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&local_44,0);
  pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
  if (0xf < uStack_34) {
    _free(in_ECX);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  local_2c = local_2c & 0xffffff00;
  FUN_00401740(s_res_export__filename__009af570,0x15);
  pvStack_c._0_1_ = 2;
  uStack_34 = 0xf;
  pvStack_38 = (void *)0x0;
  FUN_00401740(s_res_export_009af588,10);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -6,1,&local_30);
  if (0xf < local_40) {
    _free(unaff_ESI);
    return;
  }
  local_40 = 0xf;
  local_44 = 0;
  if (uStack_24 < 0x10) {
    ExceptionList = pvStack_20;
    return;
  }
  _free(pvStack_38);
  return;
}


// ==== FUN_004a65a0 @ 0x004a65a0 ====

void FUN_004a65a0(void)

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
  
  puStack_8 = &LAB_0097f102;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009af5fc;
  local_4 = 0;
  DAT_00b5a7c8 = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_res_releaseall_009af594,0xe);
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
  FUN_00401740(s_res_export_009af5a4,10);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  if (uStack_18 < 0x10) {
    *in_ECX = &PTR_FUN_009af5ec;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_004a6680 @ 0x004a6680 ====

undefined4 FUN_004a6680(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined1 auStack_98 [4];
  void *pvStack_94;
  undefined4 uStack_84;
  uint uStack_80;
  undefined **local_7c [4];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f13f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_res_releaseall_009af5b0,0xe);
  if (iVar1 == 0) {
    (**(code **)(*DAT_00b5a7d0 + 0x14))(0);
    uVar3 = 1;
  }
  else {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_res_export_009af5c0,10);
    if (iVar1 == 0) {
      local_7c[0] = &PTR_FUN_0099d55c;
      local_6c = 0;
      local_68 = 0;
      local_64 = 0;
      local_4 = 1;
      (**(code **)(*DAT_00b5a7d0 + 0x1c))();
      piVar2 = (int *)(**(code **)(*DAT_00b5a7d0 + 0x20))();
      while (piVar2 != (int *)0x0) {
        uVar3 = (**(code **)(*piVar2 + 4))();
        FUN_00411630(uVar3);
        piVar2 = (int *)(**(code **)(*DAT_00b5a7d0 + 0x20))();
      }
      uVar3 = FUN_00404890(auStack_44);
      local_4._0_1_ = 2;
      FUN_004045b0(auStack_60,uVar3);
      local_4._0_1_ = 4;
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return extraout_EAX;
      }
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      uVar3 = FUN_004046f0(auStack_28,auStack_60);
      local_4._0_1_ = 5;
      FUN_00402220(auStack_98,uVar3,&DAT_009af5cc);
      local_4 = CONCAT31(local_4._1_3_,7);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return extraout_EAX_00;
      }
      uStack_10 = 0xf;
      uStack_14 = 0;
      pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      FUN_004020e0(s_resource_txt_009af5d4,0xc);
      (**(code **)(*DAT_00b5a740 + 0xc))(auStack_98,local_7c);
      if (0xf < uStack_80) {
        _free(pvStack_94);
        return extraout_EAX_01;
      }
      uStack_80 = 0xf;
      uStack_84 = 0;
      pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
      if (0xf < uStack_48) {
        _free(pvStack_5c);
        return extraout_EAX_02;
      }
      uStack_48 = 0xf;
      uStack_4c = 0;
      pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
      FUN_004137c0();
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  ExceptionList = local_c;
  return uVar3;
}


// ==== FUN_004a6890 @ 0x004a6890 ====

undefined4 FUN_004a6890(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    (**(code **)(*DAT_00b5ac0c + 0xc))();
  }
  else if (iVar2 == 0x70004) {
    cVar1 = FUN_004a6680(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004a68e0 @ 0x004a68e0 ====

void FUN_004a68e0(byte param_1)

{
  void *in_ECX;
  
  FUN_004a65a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004a6900 @ 0x004a6900 ====

void FUN_004a6900(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af60c;
  return;
}


// ==== FUN_004a6910 @ 0x004a6910 ====

void FUN_004a6910(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af60c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004a6930 @ 0x004a6930 ====

void * FUN_004a6930(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f161;
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


// ==== Catch@004a69a2 @ 0x004a69a2 ====

void Catch_004a69a2(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004a69c0 @ 0x004a69c0 ====

/* WARNING: Removing unreachable block (ram,0x004a6ad0) */
/* WARNING: Removing unreachable block (ram,0x004a6ae1) */
/* WARNING: Removing unreachable block (ram,0x004a6aea) */
/* WARNING: Removing unreachable block (ram,0x004a6aed) */
/* WARNING: Removing unreachable block (ram,0x004a6add) */
/* WARNING: Removing unreachable block (ram,0x004a6afb) */
/* WARNING: Removing unreachable block (ram,0x004a6b08) */
/* WARNING: Removing unreachable block (ram,0x004a6b13) */
/* WARNING: Removing unreachable block (ram,0x004a6b0f) */
/* WARNING: Removing unreachable block (ram,0x004a6b03) */
/* WARNING: Removing unreachable block (ram,0x004a6b16) */

void FUN_004a69c0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097f178;
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
            goto LAB_004a6be7;
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
LAB_004a6be7:
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


// ==== FUN_004a6c90 @ 0x004a6c90 ====

void FUN_004a6c90(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_004a6c90(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004a6cd0 @ 0x004a6cd0 ====

void FUN_004a6cd0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097f178;
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
  piVar4 = (int *)FUN_004a6930(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004a6dc9:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_004a6dc9;
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


// ==== FUN_004a6eb0 @ 0x004a6eb0 ====

/* WARNING: Removing unreachable block (ram,0x004a6f0f) */

void FUN_004a6eb0(undefined4 *param_1,undefined4 *param_2)

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
LAB_004a6f40:
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
        if (uVar5 == 0) goto LAB_004a6f40;
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
      puVar6 = (undefined4 *)FUN_004a6cd0(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_004a6cd0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_004a7020 @ 0x004a7020 ====

void FUN_004a7020(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004a6c90(piVar6[1]);
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
    FUN_004a69c0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004a70e0 @ 0x004a70e0 ====

int FUN_004a70e0(int param_1)

{
  int iVar1;
  int extraout_EAX;
  int in_ECX;
  int iVar2;
  undefined1 local_34 [8];
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_18;
  uint local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f198;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0069a470(&param_1,param_1);
  if (param_1 != *(int *)(in_ECX + 8)) {
    ExceptionList = local_c;
    return *(int *)(param_1 + 0x28);
  }
  iVar2 = *(int *)(in_ECX + 0xc) + 1;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(iVar1,0,0xffffffff);
  local_4 = 0;
  local_10 = iVar2;
  FUN_004a6eb0(local_34,local_2c);
  if (local_14 < 0x10) {
    ExceptionList = local_c;
    return iVar2;
  }
  _free(local_28);
  return extraout_EAX;
}


// ==== FUN_004a71b0 @ 0x004a71b0 ====

void FUN_004a71b0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f1aa;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009af624;
  DAT_00b5a7e4 = 0;
  local_4 = 0;
  FUN_004a7020(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004a7230 @ 0x004a7230 ====

void FUN_004a7230(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f1bc;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009af624;
  iVar1 = FUN_004a37b0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a7e4 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a7e4 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004a72c0 @ 0x004a72c0 ====

void FUN_004a72c0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004a7020(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004a72f0 @ 0x004a72f0 ====

uint FUN_004a72f0(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if (uVar1 == 0) {
    return 0;
  }
  if ((param_2 != 0) && (param_2 < uVar1)) {
    uVar1 = param_2;
  }
  uVar4 = 0;
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      if (*(uint *)(param_1 + 0x14) <= uVar5) {
        FUN_0079dba3();
      }
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        puVar2 = (undefined4 *)(param_1 + 4);
      }
      else {
        puVar2 = *(undefined4 **)(param_1 + 4);
      }
      uVar4 = uVar4 * 0x10 + (int)*(char *)((int)puVar2 + uVar5);
      uVar3 = 0;
      if ((uVar4 & 0xf0000000) != 0) {
        uVar4 = uVar4 ^ (uVar4 & 0xf0000000) >> 0x18;
        uVar3 = uVar4 & 0xf0000000;
      }
      uVar5 = uVar5 + 1;
      uVar4 = uVar4 & ~uVar3;
    } while (uVar5 < uVar1);
  }
  return uVar4;
}


// ==== FUN_004a7380 @ 0x004a7380 ====

uint FUN_004a7380(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if (uVar1 != *(uint *)(param_2 + 0x14)) {
    return uVar1 & 0xffffff00;
  }
  uVar2 = uVar1 - 5;
  while( true ) {
    if ((int)uVar2 < 0) {
      return CONCAT31((int3)(uVar1 >> 8),1);
    }
    if (*(uint *)(param_1 + 0x14) <= uVar2) {
      FUN_0079dba3();
    }
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      iVar3 = param_1 + 4;
    }
    else {
      iVar3 = *(int *)(param_1 + 4);
    }
    if (*(uint *)(param_2 + 0x14) <= uVar2) {
      FUN_0079dba3();
    }
    if (*(uint *)(param_2 + 0x18) < 0x10) {
      uVar1 = param_2 + 4;
    }
    else {
      uVar1 = *(uint *)(param_2 + 4);
    }
    if (*(char *)(iVar3 + uVar2) != *(char *)(uVar1 + uVar2)) break;
    uVar2 = uVar2 - 1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_004a7400 @ 0x004a7400 ====

uint FUN_004a7400(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  uVar1 = uVar2;
  if (uVar2 != *(uint *)(param_2 + 0x14)) {
    return uVar2 & 0xffffff00;
  }
  do {
    uVar1 = uVar1 - 1;
    if ((int)uVar1 < 0) {
      return CONCAT31((int3)(uVar2 >> 8),1);
    }
    if (*(uint *)(param_1 + 0x14) <= uVar1) {
      FUN_0079dba3();
    }
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      iVar3 = param_1 + 4;
    }
    else {
      iVar3 = *(int *)(param_1 + 4);
    }
    if (*(uint *)(param_2 + 0x14) <= uVar1) {
      FUN_0079dba3();
    }
    if (*(uint *)(param_2 + 0x18) < 0x10) {
      uVar2 = param_2 + 4;
    }
    else {
      uVar2 = *(uint *)(param_2 + 4);
    }
  } while (*(char *)(iVar3 + uVar1) == *(char *)(uVar2 + uVar1));
  return uVar2 & 0xffffff00;
}


// ==== FUN_004a7480 @ 0x004a7480 ====

void FUN_004a7480(byte param_1)

{
  void *in_ECX;
  
  FUN_004a71b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004a74a0 @ 0x004a74a0 ====

undefined4 FUN_004a74a0(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return 4;
  case 1:
    return 7;
  case 2:
    return 8;
  case 3:
    return 0xf;
  case 4:
    return 0xc;
  case 5:
    return 0xb;
  case 6:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x11:
  case 0x12:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1b:
    return 9;
  case 7:
    return 2;
  case 8:
    return 1;
  case 9:
    return 3;
  case 10:
    return 0x10;
  case 0xb:
  case 0x13:
    return 6;
  case 0xc:
    return 10;
  case 0x10:
    return 5;
  default:
    return 0;
  case 0x1a:
    return 0xe;
  }
}


// ==== FUN_004a7580 @ 0x004a7580 ====

undefined4 FUN_004a7580(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f2ee;
  local_c = ExceptionList;
  switch(*(undefined4 *)(param_1 + 0x1c)) {
  case 0:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x50);
    local_4 = 0xe;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004af770(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 1:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xe4);
    local_4 = 7;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004aa110(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 2:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x48);
    local_4 = 10;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004ae890(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 3:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x58);
    local_4 = 9;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004af3f0(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 4:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x48);
    local_4 = 8;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004adad0(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 5:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x4c);
    local_4 = 0xb;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004bd8e0(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 6:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x4c);
    local_4 = 0x11;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004b7110(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 7:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x4c);
    local_4 = 1;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004cb8c0(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 8:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x90);
    local_4 = 0xc;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004baa60(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 9:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x74);
    local_4 = 2;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004c8ee0(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 10:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x40);
    local_4 = 0x14;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004b5470(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xb:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x4c);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004cccf0(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xc:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x5c);
    local_4 = 0x10;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004b80e0(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xe:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xb4);
    local_4 = 0xf;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004b8920(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xf:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x58);
    local_4 = 0xd;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0049e390(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x10:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x8c);
    local_4 = 0x16;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004b43b0(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x11:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x4c);
    local_4 = 0x17;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004b2eb0(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x12:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x50);
    local_4 = 0x13;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0049d890(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x13:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x58);
    local_4 = 6;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004bde00(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x15:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x84);
    local_4 = 0x12;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004b5800(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x16:
    ExceptionList = &local_c;
    pvVar1 = operator_new(100);
    local_4 = 3;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004c7480(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x17:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x48);
    local_4 = 5;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004c0900(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x18:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x48);
    local_4 = 4;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004c4430(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x19:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x48);
    local_4 = 0x19;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004b12d0(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x1a:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x50);
    local_4 = 0x15;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004b51d0(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x1b:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x48);
    local_4 = 0x18;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004b1ee0(param_1);
      ExceptionList = local_c;
      return uVar2;
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_004a7bb0 @ 0x004a7bb0 ====

int FUN_004a7bb0(int param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int extraout_EAX;
  undefined4 ***pppuVar4;
  int iVar5;
  undefined1 local_28 [4];
  undefined4 ***local_24 [4];
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f300;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24[0] = (undefined4 ***)((uint)local_24[0] & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401660(param_2,0,0xffffffff);
  iVar1 = *(int *)(param_2 + 0x14);
  iVar5 = 0;
  local_4 = 0;
  if (0 < iVar1) {
    do {
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        iVar3 = param_2 + 4;
      }
      else {
        iVar3 = *(int *)(param_2 + 4);
      }
      if (*(char *)(iVar3 + iVar5) == '\\') {
        uVar2 = 0x2f;
      }
      else {
        iVar3 = _tolower((int)*(char *)(iVar3 + iVar5));
        uVar2 = (undefined1)iVar3;
      }
      pppuVar4 = local_24[0];
      if (local_10 < 0x10) {
        pppuVar4 = local_24;
      }
      *(undefined1 *)((int)pppuVar4 + iVar5) = uVar2;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_28,0,0xffffffff);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_24[0]);
  return extraout_EAX;
}


// ==== FUN_004a7c90 @ 0x004a7c90 ====

int FUN_004a7c90(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  switch(param_2) {
  case 0:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x28);
    return param_1;
  case 1:
  case 6:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x44);
    return param_1;
  case 2:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x60);
    return param_1;
  case 3:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x7c);
    return param_1;
  case 4:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x98);
    return param_1;
  case 5:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0xb4);
    return param_1;
  case 7:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x108);
    return param_1;
  case 8:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x124);
    return param_1;
  case 9:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x140);
    return param_1;
  case 10:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x15c);
    return param_1;
  default:
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_009af672,0);
    return param_1;
  case 0xc:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x178);
    return param_1;
  case 0xd:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x1b0);
    return param_1;
  case 0xe:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x1cc);
    return param_1;
  case 0xf:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x1e8);
    return param_1;
  case 0x10:
  case 0x11:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x204);
    return param_1;
  case 0x12:
  case 0x19:
  case 0x1b:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x23c);
    return param_1;
  case 0x13:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 600);
    return param_1;
  case 0x15:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x274);
    return param_1;
  case 0x16:
  case 0x17:
  case 0x18:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x220);
    return param_1;
  case 0x1a:
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    FUN_00765c50(iVar2 + 0x290);
    return param_1;
  }
}


// ==== FUN_004a8060 @ 0x004a8060 ====

int FUN_004a8060(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  int extraout_EAX;
  undefined4 uVar6;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int extraout_EAX_04;
  int extraout_EAX_05;
  int extraout_EAX_06;
  int extraout_EAX_07;
  void *unaff_EBP;
  void *unaff_EDI;
  undefined4 local_b8;
  uint local_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  void *pvStack_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 auStack_90 [4];
  void *pvStack_8c;
  undefined1 auStack_88 [12];
  undefined4 uStack_7c;
  uint uStack_78;
  void *pvStack_70;
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [8];
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 auStack_58 [4];
  void *pvStack_54;
  undefined1 auStack_50 [16];
  uint uStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined1 auStack_34 [12];
  undefined1 auStack_28 [4];
  uint uStack_24;
  void *pvStack_20;
  undefined1 uStack_18;
  void *pvStack_14;
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f35e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar2 = FUN_004a74a0();
  local_9c = uVar2;
  cVar1 = FUN_00404150(param_1);
  if (cVar1 != '\0') {
    iVar3 = (**(code **)(*DAT_00b5a740 + 4))(param_1);
    ExceptionList = pvStack_14;
    return iVar3;
  }
  local_a0 = 0xf;
  local_a4 = 0;
  local_b4 = local_b4 & 0xffffff00;
  pcVar4 = PTR_s_DataPath_00ae7198;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_DataPath_00ae7198,(int)pcVar4 - (int)(PTR_s_DataPath_00ae7198 + 1));
  local_4 = 0;
  piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  (**(code **)(*piVar5 + 8))(auStack_28,&local_b8);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
  if (0xf < pvStack_a8) {
    _free(unaff_EBP);
    return extraout_EAX;
  }
  pvStack_a8 = (void *)0xf;
  uStack_ac = 0;
  (**(code **)(*DAT_00b5a6b0 + 0xc))(auStack_68);
  uStack_10 = 3;
  FUN_004a7c90(auStack_88,*(undefined4 *)(param_1 + 0x1c));
  uStack_10 = 4;
  uVar6 = FUN_00405bd0(auStack_50,auStack_34,auStack_6c);
  uStack_10 = 5;
  uVar6 = FUN_00405bd0(&local_a4,uVar6,auStack_88);
  uStack_10 = 6;
  uVar6 = FUN_00405bd0(auStack_90 + -0x34,uVar6,param_1);
  uStack_10 = 7;
  iVar3 = (**(code **)(*DAT_00b5a740 + 8))(uVar6,uVar2);
  if (0xf < local_b4) {
    _free(unaff_EDI);
    return extraout_EAX_00;
  }
  local_b4 = 0xf;
  local_b8 = 0;
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return extraout_EAX_01;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  uStack_18 = 4;
  if (0xf < uStack_40) {
    _free(pvStack_54);
    return extraout_EAX_02;
  }
  if (iVar3 == 0) {
    uVar2 = FUN_00405bd0(auStack_58,auStack_3c,auStack_90);
    uStack_18 = 8;
    uVar2 = FUN_00405bd0(&uStack_ac,uVar2,param_1);
    uStack_18 = 9;
    iVar3 = (**(code **)(*DAT_00b5a740 + 4))(uVar2,uStack_b0);
    if (0xf < uStack_94) {
      _free(pvStack_a8);
      return extraout_EAX_03;
    }
    uStack_94 = 0xf;
    uStack_98 = 0;
    pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
    if (0xf < uStack_40) {
      _free(pvStack_54);
      return extraout_EAX_04;
    }
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return extraout_EAX_05;
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  if (0xf < uStack_5c) {
    _free(pvStack_70);
    return extraout_EAX_06;
  }
  uStack_60 = 0;
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  uStack_5c = 0xf;
  if (uStack_24 < 0x10) {
    ExceptionList = pvStack_20;
    return iVar3;
  }
  _free(pvStack_38);
  return extraout_EAX_07;
}


// ==== FUN_004a8360 @ 0x004a8360 ====

undefined4 FUN_004a8360(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 unaff_retaddr;
  void *pvStack_9c;
  undefined1 local_98 [4];
  undefined1 local_94;
  undefined4 uStack_8c;
  void *pvStack_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 uStack_78;
  uint uStack_74;
  void *pvStack_6c;
  undefined1 auStack_68 [12];
  undefined4 uStack_5c;
  uint uStack_58;
  void *pvStack_50;
  undefined1 auStack_4c [8];
  undefined1 auStack_44 [8];
  uint uStack_3c;
  void *pvStack_34;
  undefined1 auStack_30 [16];
  uint uStack_20;
  void *pvStack_1c;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f393;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = FUN_00404150(param_1);
  if (cVar1 != '\0') {
    uVar2 = (**(code **)(*DAT_00b5a740 + 0xc))(param_1,param_2);
    ExceptionList = pvStack_14;
    return uVar2;
  }
  local_80 = 0xf;
  local_84 = 0;
  local_94 = 0;
  pcVar3 = PTR_s_DataPath_00ae7198;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_DataPath_00ae7198,(int)pcVar3 - (int)(PTR_s_DataPath_00ae7198 + 1));
  local_4 = 0;
  piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  (**(code **)(*piVar4 + 8))(auStack_44,local_98);
  pvStack_c._0_1_ = 2;
  if (0xf < pvStack_88) {
    _free(pvStack_9c);
    return extraout_EAX;
  }
  pvStack_88 = (void *)0xf;
  uStack_8c = 0;
  FUN_004a7c90(&local_84,*(undefined4 *)(param_1 + 0x1c));
  pvStack_c._0_1_ = 3;
  uVar2 = FUN_00405bd0(auStack_30,auStack_4c,&local_84);
  pvStack_c._0_1_ = 4;
  uVar2 = FUN_00405bd0(auStack_68,uVar2,param_1);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);
  uVar2 = (**(code **)(*DAT_00b5a740 + 0xc))(uVar2,unaff_retaddr);
  if (0xf < uStack_58) {
    _free(pvStack_6c);
    return extraout_EAX_00;
  }
  uStack_58 = 0xf;
  uStack_5c = 0;
  pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
  if (0xf < uStack_20) {
    _free(pvStack_34);
    return extraout_EAX_01;
  }
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return extraout_EAX_02;
  }
  uStack_74 = 0xf;
  uStack_78 = 0;
  pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
  if (uStack_3c < 0x10) {
    ExceptionList = pvStack_1c;
    return uVar2;
  }
  _free(pvStack_50);
  return extraout_EAX_03;
}


// ==== FUN_004a8540 @ 0x004a8540 ====

undefined4 FUN_004a8540(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 extraout_EAX;
  undefined4 uVar5;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  void *unaff_EBP;
  undefined1 local_98 [4];
  undefined1 local_94;
  undefined4 uStack_8c;
  void *pvStack_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 uStack_78;
  uint uStack_74;
  void *pvStack_6c;
  undefined1 auStack_68 [12];
  undefined4 uStack_5c;
  uint uStack_58;
  void *pvStack_50;
  undefined1 auStack_4c [12];
  undefined4 uStack_40;
  uint uStack_3c;
  void *pvStack_34;
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [8];
  uint uStack_20;
  void *pvStack_1c;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f3c8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar2 = FUN_004a74a0(*(undefined4 *)(param_1 + 0x1c));
  cVar1 = FUN_00404150(param_1);
  if (cVar1 != '\0') {
    uVar2 = (**(code **)(*DAT_00b5a740 + 0x14))(param_1,uVar2);
    ExceptionList = pvStack_14;
    return uVar2;
  }
  local_80 = 0xf;
  local_84 = 0;
  local_94 = 0;
  pcVar3 = PTR_s_DataPath_00ae7198;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_s_DataPath_00ae7198,(int)pcVar3 - (int)(PTR_s_DataPath_00ae7198 + 1));
  local_4 = 0;
  piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  (**(code **)(*piVar4 + 8))(auStack_28,local_98);
  pvStack_c._0_1_ = 2;
  if (0xf < pvStack_88) {
    _free(unaff_EBP);
    return extraout_EAX;
  }
  pvStack_88 = (void *)0xf;
  uStack_8c = 0;
  FUN_004a7c90(&local_84,*(undefined4 *)(param_1 + 0x1c));
  pvStack_c._0_1_ = 3;
  uVar5 = FUN_00405bd0(auStack_4c,auStack_30,&local_84);
  pvStack_c._0_1_ = 4;
  uVar5 = FUN_00405bd0(auStack_68,uVar5,param_1);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);
  uVar2 = (**(code **)(*DAT_00b5a740 + 0x14))(uVar5,uVar2);
  if (0xf < uStack_58) {
    _free(pvStack_6c);
    return extraout_EAX_00;
  }
  uStack_58 = 0xf;
  uStack_5c = 0;
  pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
  if (0xf < uStack_3c) {
    _free(pvStack_50);
    return extraout_EAX_01;
  }
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  if (0xf < uStack_74) {
    _free(pvStack_88);
    return extraout_EAX_02;
  }
  uStack_78 = 0;
  pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
  uStack_74 = 0xf;
  if (uStack_20 < 0x10) {
    ExceptionList = pvStack_1c;
    return uVar2;
  }
  _free(pvStack_34);
  return extraout_EAX_03;
}


// ==== FUN_004a8720 @ 0x004a8720 ====

void FUN_004a8720(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_0099d0e8;
  param_2[3] = DAT_0099d0e8;
  param_2[4] = uVar1;
  uVar2 = DAT_0099d0f0;
  param_2[5] = uVar1;
  *param_2 = uVar2;
  param_2[1] = uVar2;
  param_2[2] = uVar2;
  FUN_004ce660();
  return;
}


// ==== FUN_004a87a0 @ 0x004a87a0 ====

undefined4 FUN_004a87a0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  char cVar3;
  float fVar4;
  float local_10 [4];
  
  local_10[0] = DAT_0099d0f0;
  cVar3 = FUN_004cd280(param_1,param_2,local_10);
  if (cVar3 == '\0') {
    *param_2 = 0.0;
    param_2[1] = 0.0;
    param_2[2] = 0.0;
    return 0;
  }
  fVar1 = param_1[4];
  fVar2 = param_1[1];
  fVar4 = param_1[2] + param_1[5] * local_10[0];
  *param_2 = *param_1 + local_10[0] * param_1[3];
  param_2[1] = fVar2 + fVar1 * local_10[0];
  param_2[2] = fVar4;
  return CONCAT31((int3)((uint)fVar4 >> 8),1);
}


// ==== FUN_004a8890 @ 0x004a8890 ====

void FUN_004a8890(void)

{
  FUN_004cdb30();
  return;
}


// ==== FUN_004a88a0 @ 0x004a88a0 ====

undefined4 FUN_004a88a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  puVar2 = (undefined4 *)FUN_00445ef0(param_1,param_2,param_3);
  if (puVar2 != (undefined4 *)0x0) {
    cVar1 = (**(code **)(*in_ECX + 0x10))(puVar2);
    if (cVar1 != '\0') {
      return 1;
    }
    (**(code **)*puVar2)(1);
  }
  return 0;
}


// ==== FUN_004a88f0 @ 0x004a88f0 ====

int FUN_004a88f0(undefined4 param_1)

{
  int *in_ECX;
  
  *(undefined1 *)(in_ECX + 0xf) = 1;
  (**(code **)(*in_ECX + 0x10))(param_1);
  *(undefined1 *)(in_ECX + 0xf) = 0;
  if (in_ECX[0x23] == 0) {
    return 0;
  }
  return (in_ECX[0x24] - in_ECX[0x23]) / 0x1c;
}


// ==== FUN_004a8940 @ 0x004a8940 ====

void FUN_004a8940(int param_1,int param_2)

{
  float *pfVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  float fVar2;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  param_2 = param_2 * 0xc;
  pfVar1 = (float *)(*(int *)(param_1 + 0x5c) + param_2);
  local_c = *pfVar1;
  local_8 = pfVar1[1];
  local_4 = pfVar1[2];
  local_18 = *(float *)(*(int *)(in_ECX + 0x9c) + param_2);
  param_2 = *(int *)(in_ECX + 0x9c) + param_2;
  local_14 = *(float *)(param_2 + 4);
  local_10 = *(float *)(param_2 + 8);
  fVar2 = local_10 * local_4 + local_14 * local_8 + local_18 * local_c;
  local_18 = local_18 - local_c * fVar2;
  local_14 = local_14 - local_8 * fVar2;
  local_10 = local_10 - local_4 * fVar2;
  thunk_FUN_0079e1ba(&local_18);
  *(float **)(param_1 + 0x18) = &local_18;
  *(undefined4 *)(param_1 + 0x1c) = unaff_ESI;
  *(float *)(param_1 + 0x20) = local_18;
  return;
}


// ==== FUN_004a8a30 @ 0x004a8a30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a8a30(float *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  int iVar7;
  
  iVar5 = *(int *)(in_ECX + 0x40) + 1;
  iVar6 = param_3 + 1;
  iVar1 = iVar6 * iVar5 + param_2;
  iVar7 = iVar5 * param_3 + param_2;
  param_1[0xb] = *(float *)(*(int *)(param_4 + 0x3c) + iVar7 * 4);
  param_1[0x17] = *(float *)(*(int *)(param_4 + 0x3c) + iVar1 * 4);
  param_1[0x23] = *(float *)(*(int *)(param_4 + 0x3c) + iVar1 * 4 + 4);
  iVar5 = iVar7 * 4 + 4;
  param_1[0x2f] = *(float *)(*(int *)(param_4 + 0x3c) + iVar5);
  fVar3 = (float)param_2;
  if (param_2 < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  *param_1 = fVar3;
  param_1[0xc] = fVar3;
  fVar3 = (float)(param_2 + 1);
  if (param_2 + 1 < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  param_1[0x18] = fVar3;
  param_1[0x24] = fVar3;
  fVar3 = (float)param_3;
  if (param_3 < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  param_1[2] = fVar3;
  fVar4 = (float)iVar6;
  if (iVar6 < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  param_1[0xe] = fVar4;
  param_1[0x1a] = fVar4;
  param_1[0x26] = fVar3;
  param_1[1] = *(float *)(*(int *)(param_4 + 0x2c) + iVar7 * 4);
  param_1[0xd] = *(float *)(*(int *)(param_4 + 0x2c) + iVar1 * 4);
  param_1[0x19] = *(float *)(*(int *)(param_4 + 0x2c) + iVar1 * 4 + 4);
  param_1[0x25] = *(float *)(*(int *)(param_4 + 0x2c) + iVar5);
  iVar5 = *(int *)(param_4 + 0x5c) + iVar7 * 0xc;
  param_1[3] = *(float *)(*(int *)(param_4 + 0x5c) + iVar7 * 0xc);
  param_1[4] = *(float *)(iVar5 + 4);
  param_1[5] = *(float *)(iVar5 + 8);
  iVar5 = *(int *)(param_4 + 0x5c) + iVar1 * 0xc;
  param_1[0xf] = *(float *)(*(int *)(param_4 + 0x5c) + iVar1 * 0xc);
  param_1[0x10] = *(float *)(iVar5 + 4);
  param_1[0x11] = *(float *)(iVar5 + 8);
  iVar5 = iVar1 * 3 + 3;
  iVar1 = *(int *)(param_4 + 0x5c) + iVar5 * 4;
  param_1[0x1b] = *(float *)(*(int *)(param_4 + 0x5c) + iVar5 * 4);
  param_1[0x1c] = *(float *)(iVar1 + 4);
  param_1[0x1d] = *(float *)(iVar1 + 8);
  pfVar2 = (float *)(*(int *)(param_4 + 0x5c) + (iVar7 * 3 + 3) * 4);
  param_1[0x27] = *pfVar2;
  param_1[0x28] = pfVar2[1];
  param_1[0x29] = pfVar2[2];
  return;
}


// ==== FUN_004a8bd0 @ 0x004a8bd0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a8bd0(float *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  int iVar7;
  
  iVar5 = *(int *)(in_ECX + 0x40) + 1;
  iVar6 = param_3 + 1;
  iVar1 = iVar6 * iVar5 + param_2;
  iVar7 = iVar5 * param_3 + param_2;
  param_1[8] = *(float *)(*(int *)(param_4 + 0x3c) + iVar7 * 4);
  param_1[0x11] = *(float *)(*(int *)(param_4 + 0x3c) + iVar1 * 4);
  param_1[0x1a] = *(float *)(*(int *)(param_4 + 0x3c) + iVar1 * 4 + 4);
  iVar5 = iVar7 * 4 + 4;
  param_1[0x23] = *(float *)(*(int *)(param_4 + 0x3c) + iVar5);
  fVar3 = (float)param_2;
  if (param_2 < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  *param_1 = fVar3;
  param_1[9] = fVar3;
  fVar3 = (float)(param_2 + 1);
  if (param_2 + 1 < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  param_1[0x12] = fVar3;
  param_1[0x1b] = fVar3;
  fVar3 = (float)param_3;
  if (param_3 < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  param_1[2] = fVar3;
  fVar4 = (float)iVar6;
  if (iVar6 < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  param_1[0xb] = fVar4;
  param_1[0x14] = fVar4;
  param_1[0x1d] = fVar3;
  param_1[1] = *(float *)(*(int *)(param_4 + 0x2c) + iVar7 * 4);
  param_1[10] = *(float *)(*(int *)(param_4 + 0x2c) + iVar1 * 4);
  param_1[0x13] = *(float *)(*(int *)(param_4 + 0x2c) + iVar1 * 4 + 4);
  param_1[0x1c] = *(float *)(*(int *)(param_4 + 0x2c) + iVar5);
  iVar5 = *(int *)(param_4 + 0x5c) + iVar7 * 0xc;
  param_1[3] = *(float *)(*(int *)(param_4 + 0x5c) + iVar7 * 0xc);
  param_1[4] = *(float *)(iVar5 + 4);
  param_1[5] = *(float *)(iVar5 + 8);
  iVar5 = *(int *)(param_4 + 0x5c) + iVar1 * 0xc;
  param_1[0xc] = *(float *)(*(int *)(param_4 + 0x5c) + iVar1 * 0xc);
  param_1[0xd] = *(float *)(iVar5 + 4);
  param_1[0xe] = *(float *)(iVar5 + 8);
  iVar5 = iVar1 * 3 + 3;
  iVar1 = *(int *)(param_4 + 0x5c) + iVar5 * 4;
  param_1[0x15] = *(float *)(*(int *)(param_4 + 0x5c) + iVar5 * 4);
  param_1[0x16] = *(float *)(iVar1 + 4);
  param_1[0x17] = *(float *)(iVar1 + 8);
  pfVar2 = (float *)(*(int *)(param_4 + 0x5c) + (iVar7 * 3 + 3) * 4);
  param_1[0x1e] = *pfVar2;
  param_1[0x1f] = pfVar2[1];
  param_1[0x20] = pfVar2[2];
  return;
}


// ==== FUN_004a8d60 @ 0x004a8d60 ====

undefined4 FUN_004a8d60(float *param_1,float *param_2,int param_3,float *param_4)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  int *piVar6;
  float fVar7;
  float fVar8;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  piVar6 = *(int **)(param_3 + 4);
  piVar2 = *(int **)(param_3 + 8);
  local_1c = DAT_0099d0f0;
  do {
    if (piVar6 == piVar2) {
      fVar7 = 0.0;
      *param_2 = 0.0;
      local_8 = 0.0;
      uVar5 = 0;
LAB_004a8e78:
      param_2[1] = local_8;
      param_2[2] = fVar7;
      return uVar5;
    }
    iVar3 = *piVar6;
    local_c = *(float *)(iVar3 + 0xb8);
    local_8 = *(float *)(iVar3 + 0xbc);
    local_4 = *(float *)(iVar3 + 0xc0);
    local_18 = *param_4 - local_c;
    local_10 = param_4[2] - local_4;
    local_14 = param_4[1] - local_8;
    if (((param_1[5] * local_10 + param_1[4] * local_14 + param_1[3] * local_18 <= DAT_0099cdc8) ||
        (SQRT(local_18 * local_18 + local_14 * local_14 + local_10 * local_10) <=
         *(float *)(iVar3 + 0x54))) &&
       (cVar4 = FUN_004cd280(param_1,param_2,&local_1c), cVar4 != '\0')) {
      fVar1 = param_1[5];
      fVar8 = *param_1 + param_1[3] * local_1c;
      local_8 = param_1[1] + param_1[4] * local_1c;
      fVar7 = param_1[2];
      *param_2 = fVar8;
      fVar7 = fVar7 + fVar1 * local_1c;
      uVar5 = CONCAT31((int3)((uint)fVar8 >> 8),1);
      goto LAB_004a8e78;
    }
    piVar6 = piVar6 + 1;
  } while( true );
}


// ==== FUN_004a8ef0 @ 0x004a8ef0 ====

uint FUN_004a8ef0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  uint extraout_EAX;
  uint extraout_EAX_00;
  undefined1 local_34 [4];
  ushort local_30;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f3e8;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_4 = 0;
  ExceptionList = &local_c;
  cVar1 = FUN_0042b7a0(param_1,param_2,local_34,local_28);
  if (cVar1 == '\0') {
    if (local_10 < 0x10) {
      ExceptionList = local_c;
      return 0;
    }
    _free(local_24);
    return extraout_EAX_00;
  }
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return (uint)local_30;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_004a8fa0 @ 0x004a8fa0 ====

void FUN_004a8fa0(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x24))();
  *(undefined1 *)(in_ECX + 0xe) = 0;
  if ((undefined4 *)in_ECX[0x2e] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2e])(1);
  }
  in_ECX[0x2e] = 0;
  if ((void *)in_ECX[0x14] != (void *)0x0) {
    _free((void *)in_ECX[0x14]);
    return;
  }
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  if ((void *)in_ECX[0x1b] == (void *)0x0) {
    in_ECX[0x1b] = 0;
    in_ECX[0x1c] = 0;
    in_ECX[0x1d] = 0;
    in_ECX[0x30] = 0;
    (**(code **)(*in_ECX + 0x10))(in_ECX[8]);
    return;
  }
  _free((void *)in_ECX[0x1b]);
  return;
}


// ==== FUN_004a9040 @ 0x004a9040 ====

undefined4 FUN_004a9040(int param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar2 = FUN_004ac1b0(param_2);
  iVar1 = *(int *)(param_1 + 0xc4);
  if (*(char *)(iVar1 + 0x44) == '\0') {
    FUN_004cdce0(0,iVar2,&param_3);
  }
  else {
    if ((*(float *)(iVar1 + 0x48) == param_3) && (*(int *)(iVar1 + 0x7c) == iVar2)) {
      if (iVar2 != 0) {
        (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
      }
      return 0;
    }
    if (*(char *)(iVar1 + 0x80) == '\0') {
      FUN_004cdce0(1,iVar2,&param_3);
      return 1;
    }
    if ((*(float *)(iVar1 + 0x84) != param_3) || (uVar3 = 1, *(int *)(iVar1 + 0xb8) != iVar2)) {
      uVar3 = 0xff;
    }
    if (iVar2 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
      return uVar3;
    }
  }
  return uVar3;
}


// ==== FUN_004a9110 @ 0x004a9110 ====

void FUN_004a9110(void *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = param_1;
  FUN_004ce140(param_1);
  FUN_004ac870(*(int *)((int)pvVar1 + 4),*(int *)((int)pvVar1 + 8),
               *(int *)((int)pvVar1 + 8) - *(int *)((int)pvVar1 + 4) >> 2);
  FUN_004ab950(&param_1,*(undefined4 *)((int)pvVar1 + 4),*(undefined4 *)((int)pvVar1 + 8));
  if (param_1 != *(void **)((int)pvVar1 + 8)) {
    pvVar2 = _memmove(param_1,*(void **)((int)pvVar1 + 8),0);
    *(void **)((int)pvVar1 + 8) = pvVar2;
  }
  return;
}


// ==== FUN_004a9180 @ 0x004a9180 ====

float10 FUN_004a9180(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  uVar2 = *(int *)(in_ECX + 0x40) * param_2 + param_1;
  iVar1 = *(int *)(in_ECX + 0x50);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x54) - iVar1 >> 2) <= uVar2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0042f370();
  }
  return (float10)*(float *)(iVar1 + uVar2 * 4);
}


// ==== FUN_004a91b0 @ 0x004a91b0 ====

void FUN_004a91b0(uint param_1,int param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int in_ECX;
  uint uVar9;
  int local_50;
  undefined1 local_34 [4];
  void *local_30;
  undefined4 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0097f3fa;
  local_14 = ExceptionList;
  iVar2 = *(int *)(param_2 + 0xc4);
  if (*(void **)(iVar2 + 0x70) != (void *)0x0) {
    ExceptionList = &local_14;
    _free(*(void **)(iVar2 + 0x70));
    return;
  }
  ExceptionList = &local_14;
  *(undefined4 *)(iVar2 + 0x70) = 0;
  *(undefined4 *)(iVar2 + 0x74) = 0;
  *(undefined4 *)(iVar2 + 0x78) = 0;
  if (*(void **)(iVar2 + 0x60) != (void *)0x0) {
    _free(*(void **)(iVar2 + 0x60));
    return;
  }
  *(undefined4 *)(iVar2 + 0x60) = 0;
  *(undefined4 *)(iVar2 + 100) = 0;
  *(undefined4 *)(iVar2 + 0x68) = 0;
  iVar2 = *(int *)(param_2 + 0xc4);
  if (*(void **)(iVar2 + 0xac) != (void *)0x0) {
    _free(*(void **)(iVar2 + 0xac));
    return;
  }
  *(undefined4 *)(iVar2 + 0xac) = 0;
  *(undefined4 *)(iVar2 + 0xb0) = 0;
  *(undefined4 *)(iVar2 + 0xb4) = 0;
  if (*(void **)(iVar2 + 0x9c) != (void *)0x0) {
    _free(*(void **)(iVar2 + 0x9c));
    return;
  }
  *(undefined4 *)(iVar2 + 0x9c) = 0;
  *(undefined4 *)(iVar2 + 0xa0) = 0;
  *(undefined4 *)(iVar2 + 0xa4) = 0;
  local_50 = 0;
  if (param_1 == 0) {
    local_50 = 1;
  }
  else if (1 < param_1) {
    param_1 = 1;
    goto LAB_004a929e;
  }
  FUN_004ac1b0();
  FUN_004cdce0();
LAB_004a929e:
  uVar3 = *(uint *)(param_2 + 0x40);
  uVar8 = *(uint *)(param_2 + 0x44);
  uVar4 = *(uint *)(param_2 + 0x48);
  uVar5 = *(uint *)(param_2 + 0x4c);
  do {
    if (uVar5 <= uVar8) {
      ExceptionList = local_14;
      return;
    }
    uVar9 = uVar3;
    if (uVar3 < uVar4) {
      do {
        iVar2 = *(int *)(in_ECX + 0x50);
        uVar6 = *(int *)(in_ECX + 0x40) * uVar8 + uVar9;
        if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x54) - iVar2 >> 2) <= uVar6)) {
LAB_004a9451:
                    /* WARNING: Subroutine does not return */
          FUN_0042f370();
        }
        if (DAT_0099d0e8 < *(float *)(uVar6 * 4 + iVar2)) {
          if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x54) - iVar2 >> 2) <= uVar6))
          goto LAB_004a9451;
          fVar1 = *(float *)(uVar6 * 4 + iVar2);
          if (fVar1 == *(float *)(*(int *)(param_2 + 0xc4) + 0x48 + param_1 * 0x3c)) {
            FUN_004cdd90();
          }
          else if (fVar1 == *(float *)(*(int *)(param_2 + 0xc4) + 0x48 + local_50 * 0x3c)) {
            FUN_004cdd90();
          }
          else {
            FUN_00401740(s__d____f_009af7c0,7);
            uVar7 = FUN_00404230(local_34);
            local_c = 0;
            FUN_00796d50(uVar7);
            local_c = 0xffffffff;
            if (0xf < local_1c) {
              _free(local_30);
              return;
            }
            local_1c = 0xf;
            local_20 = 0;
            local_30 = (void *)((uint)local_30 & 0xffffff00);
          }
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar4);
    }
    uVar8 = uVar8 + 1;
  } while( true );
}


// ==== FUN_004a9460 @ 0x004a9460 ====

void FUN_004a9460(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  ushort uVar7;
  uint uVar8;
  undefined4 *puVar9;
  ushort uVar10;
  int in_ECX;
  ushort uVar11;
  undefined4 *puVar12;
  int *piVar13;
  
  FUN_00469950(*(int *)(in_ECX + 0x44) * *(int *)(in_ECX + 0x40),0xff);
  puVar3 = *(undefined4 **)(param_1 + 0xa4);
  puVar4 = (undefined4 *)*puVar3;
  puVar6 = puVar4;
  do {
    do {
      while( true ) {
        do {
          puVar12 = puVar4;
          if (puVar12 == puVar3) {
            return;
          }
          piVar5 = (int *)puVar12[6];
          uVar1 = *(undefined1 *)(puVar12 + 8);
          for (piVar13 = (int *)puVar12[5]; piVar13 != piVar5; piVar13 = piVar13 + 3) {
            uVar7 = *(ushort *)(piVar13 + 1);
            uVar11 = 0;
            if (uVar7 != 0) {
              do {
                uVar10 = 0;
                if (uVar7 != 0) {
                  do {
                    uVar8 = (uint)uVar10;
                    uVar10 = uVar10 + 1;
                    *(undefined1 *)
                     (uVar8 * *(int *)(in_ECX + 0x40) + *piVar13 + (uint)uVar11 +
                     *(int *)(in_ECX + 0x6c)) = uVar1;
                  } while (uVar10 < *(ushort *)(piVar13 + 1));
                  puVar12 = puVar6;
                }
                uVar7 = *(ushort *)(piVar13 + 1);
                uVar11 = uVar11 + 1;
              } while (uVar11 < uVar7);
            }
          }
          puVar4 = puVar12;
        } while (*(char *)((int)puVar12 + 0x25) != '\0');
        puVar6 = (undefined4 *)puVar12[2];
        if (*(char *)((int)puVar6 + 0x25) != '\0') break;
        cVar2 = *(char *)((int)*puVar6 + 0x25);
        puVar12 = (undefined4 *)*puVar6;
        while (puVar4 = puVar6, cVar2 == '\0') {
          cVar2 = *(char *)((int)*puVar12 + 0x25);
          puVar6 = puVar12;
          puVar12 = (undefined4 *)*puVar12;
        }
      }
      puVar4 = (undefined4 *)puVar12[1];
      puVar6 = puVar4;
    } while (*(char *)((int)puVar4 + 0x25) != '\0');
    while( true ) {
      puVar9 = puVar4;
      puVar4 = puVar9;
      puVar6 = puVar9;
      if (puVar12 != (undefined4 *)puVar9[2]) break;
      puVar6 = (undefined4 *)puVar9[1];
      puVar4 = puVar6;
      if (*(char *)((int)puVar6 + 0x25) != '\0') break;
      puVar12 = puVar9;
    }
  } while( true );
}


// ==== FUN_004a9570 @ 0x004a9570 ====

void FUN_004a9570(undefined4 param_1,uint *param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar2 = param_2;
  uVar6 = param_2[1];
  iVar5 = *(int *)(param_3 + 0xc) + 1;
  if (uVar6 < param_2[3]) {
    uVar4 = param_2[2];
    local_30 = uVar6 * iVar5;
    param_2 = (uint *)uVar6;
    do {
      uVar6 = *puVar2;
      if (uVar6 < uVar4) {
        iVar8 = (local_30 + uVar6) * 4;
        iVar7 = (local_30 + uVar6 + iVar5) * 4;
        do {
          iVar1 = *(int *)(param_3 + 0x4c);
          local_10 = *(undefined4 *)(iVar8 + iVar1);
          local_c = *(undefined4 *)(iVar7 + iVar1);
          local_8 = *(undefined4 *)(iVar7 + 4 + iVar1);
          local_4 = *(undefined4 *)(iVar8 + 4 + iVar1);
          puVar3 = (undefined4 *)FUN_004d2e40(local_1c,&local_10);
          local_28 = *puVar3;
          local_24 = puVar3[1];
          local_20 = puVar3[2];
          FUN_004acfa0(&local_28);
          uVar4 = puVar2[2];
          uVar6 = uVar6 + 1;
          iVar7 = iVar7 + 4;
          iVar8 = iVar8 + 4;
        } while (uVar6 < uVar4);
      }
      param_2 = (uint *)((int)param_2 + 1);
      local_30 = local_30 + iVar5;
    } while (param_2 < puVar2[3]);
  }
  return;
}


// ==== FUN_004a9700 @ 0x004a9700 ====

void FUN_004a9700(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x60);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if (puVar3[10] != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x1c))(puVar3[10]);
    }
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x2d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  FUN_004ad020(*(undefined4 *)(*(int *)(in_ECX + 0x60) + 4));
  *(int *)(*(int *)(in_ECX + 0x60) + 4) = *(int *)(in_ECX + 0x60);
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(in_ECX + 0x60);
  *(int *)(*(int *)(in_ECX + 0x60) + 8) = *(int *)(in_ECX + 0x60);
  return;
}


// ==== FUN_004a97a0 @ 0x004a97a0 ====

void FUN_004a97a0(void)

{
  int in_ECX;
  
  FUN_004a9700();
  *(undefined1 *)(in_ECX + 0x38) = 1;
  return;
}


// ==== FUN_004a97b0 @ 0x004a97b0 ====

/* WARNING: Removing unreachable block (ram,0x004a9908) */
/* WARNING: Removing unreachable block (ram,0x004a991c) */
/* WARNING: Removing unreachable block (ram,0x004a9a14) */
/* WARNING: Removing unreachable block (ram,0x004a9a28) */
/* WARNING: Removing unreachable block (ram,0x004a9a78) */
/* WARNING: Removing unreachable block (ram,0x004a9a7f) */
/* WARNING: Removing unreachable block (ram,0x004a9a85) */
/* WARNING: Removing unreachable block (ram,0x004a9a89) */
/* WARNING: Removing unreachable block (ram,0x004a9a8e) */
/* WARNING: Removing unreachable block (ram,0x004a9a90) */
/* WARNING: Removing unreachable block (ram,0x004a9a96) */
/* WARNING: Removing unreachable block (ram,0x004a9a9b) */
/* WARNING: Removing unreachable block (ram,0x004a9aa2) */
/* WARNING: Removing unreachable block (ram,0x004a9aa9) */
/* WARNING: Removing unreachable block (ram,0x004a9abb) */
/* WARNING: Removing unreachable block (ram,0x004a9b20) */
/* WARNING: Removing unreachable block (ram,0x004a9b2d) */
/* WARNING: Removing unreachable block (ram,0x004a9b39) */
/* WARNING: Removing unreachable block (ram,0x004a9b40) */
/* WARNING: Removing unreachable block (ram,0x004a9ba3) */
/* WARNING: Removing unreachable block (ram,0x004a9bb0) */
/* WARNING: Removing unreachable block (ram,0x004a9bdd) */
/* WARNING: Removing unreachable block (ram,0x004a9be3) */
/* WARNING: Removing unreachable block (ram,0x004a9bf0) */
/* WARNING: Removing unreachable block (ram,0x004a9a1d) */
/* WARNING: Removing unreachable block (ram,0x004a9c0a) */

void FUN_004a97b0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int in_ECX;
  undefined4 *puVar9;
  uint *puVar10;
  undefined4 *puStack_64;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f43b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_004465c0();
  local_4._0_1_ = 0;
  local_4._1_3_ = 0;
  puStack_64 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puStack_64 == (undefined4 *)0x0) {
    puStack_64 = (undefined4 *)0x0;
  }
  else {
    *puStack_64 = &PTR_FUN_009af7f0;
    puStack_64[2] = 0;
    puStack_64[3] = 0;
    puStack_64[4] = 0;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x88);
  puVar3 = (undefined4 *)*puVar2;
  local_4._0_1_ = 0;
  puVar6 = puVar3;
  do {
    if (puVar3 == puVar2) {
      FUN_00797a20();
      ExceptionList = pvStack_c;
      return;
    }
    puVar4 = (uint *)puVar3[0xc];
    puVar10 = (uint *)puVar3[0xb];
    puVar9 = puVar3;
    if (puVar10 != puVar4) {
      do {
        FUN_004cd1f0();
        iVar7 = FUN_004a9040();
        if (iVar7 == 0xff) {
          iVar7 = puStack_64[2];
          if ((iVar7 == 0) ||
             ((uint)(puStack_64[4] - iVar7 >> 2) <= (uint)(puStack_64[3] - iVar7 >> 2))) {
            FUN_0042f3e0();
          }
          else {
            puVar5 = (uint *)puStack_64[3];
            *puVar5 = *puVar10;
            puStack_64[3] = puVar5 + 1;
          }
          FUN_0042f3e0();
        }
        else {
          FUN_004cdd90();
          iVar7 = *(int *)(in_ECX + 0x50);
          if ((iVar7 == 0) || ((uint)(*(int *)(in_ECX + 0x54) - iVar7 >> 2) <= *puVar10)) {
                    /* WARNING: Subroutine does not return */
            FUN_0042f370();
          }
          *(uint *)(iVar7 + *puVar10 * 4) = puVar10[1];
        }
        puVar10 = puVar10 + 2;
      } while (puVar10 != puVar4);
      puVar9 = puVar6;
    }
    puVar3 = puVar9;
    if (*(char *)((int)puVar9 + 0x39) == '\0') {
      puVar3 = (undefined4 *)puVar9[2];
      if (*(char *)((int)puVar3 + 0x39) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x39);
        puVar9 = (undefined4 *)*puVar3;
        while (puVar6 = puVar3, cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar9 + 0x39);
          puVar3 = puVar9;
          puVar9 = (undefined4 *)*puVar9;
        }
      }
      else {
        puVar3 = (undefined4 *)puVar9[1];
        puVar6 = puVar3;
        if (*(char *)((int)puVar3 + 0x39) == '\0') {
          while ((puVar8 = puVar3, puVar3 = puVar8, puVar6 = puVar8,
                 puVar9 == (undefined4 *)puVar8[2] &&
                 (puVar3 = (undefined4 *)puVar8[1], puVar6 = puVar3,
                 *(char *)((int)puVar3 + 0x39) == '\0'))) {
            puVar9 = puVar8;
          }
        }
      }
    }
  } while( true );
}


// ==== FUN_004a9c30 @ 0x004a9c30 ====

void FUN_004a9c30(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 *puVar10;
  int in_ECX;
  uint uVar11;
  undefined4 *puVar12;
  uint *puVar13;
  int *piVar14;
  undefined4 *puVar15;
  int *local_1c;
  
  if (*(int *)(param_1 + 0x8c) != 0) {
    FUN_004a97b0(param_1);
    return;
  }
  FUN_004465c0(*(int *)(in_ECX + 0x44) * *(int *)(in_ECX + 0x40),0xc61c4000);
  puVar2 = *(undefined4 **)(param_1 + 0x7c);
  puVar15 = (undefined4 *)*puVar2;
  puVar6 = puVar15;
  do {
    do {
      while( true ) {
        do {
          if (puVar15 == puVar2) {
            return;
          }
          piVar3 = (int *)puVar15[0xb];
          piVar14 = (int *)*piVar3;
          puVar12 = puVar15;
          local_1c = piVar14;
          if (piVar14 != piVar3) {
            do {
              uVar11 = *(int *)(in_ECX + 0x40) + 1;
              uVar7 = FUN_004cd1f0((uint)piVar14[3] % uVar11,(uint)piVar14[3] / uVar11);
              puVar15 = (undefined4 *)piVar14[5];
              puVar12 = (undefined4 *)piVar14[6];
              if (puVar15 != puVar12) {
                do {
                  uVar8 = FUN_004a9040(uVar7,puVar6 + 3,*puVar15);
                  puVar4 = (uint *)puVar15[3];
                  for (puVar13 = (uint *)puVar15[2]; puVar13 != puVar4; puVar13 = puVar13 + 1) {
                    FUN_004cdd90(uVar8,*puVar13 % *(uint *)(in_ECX + 0x40),
                                 *puVar13 / *(uint *)(in_ECX + 0x40));
                    iVar5 = *(int *)(in_ECX + 0x50);
                    if ((iVar5 == 0) || ((uint)(*(int *)(in_ECX + 0x54) - iVar5 >> 2) <= *puVar13))
                    {
                    /* WARNING: Subroutine does not return */
                      FUN_0042f370();
                    }
                    *(undefined4 *)(iVar5 + *puVar13 * 4) = *puVar15;
                  }
                  puVar15 = puVar15 + 5;
                } while (puVar15 != puVar12);
                piVar14 = local_1c;
              }
              if (*(char *)((int)piVar14 + 0x21) == '\0') {
                local_1c = (int *)piVar14[2];
                if (*(char *)((int)local_1c + 0x21) == '\0') {
                  cVar1 = *(char *)(*local_1c + 0x21);
                  piVar14 = (int *)*local_1c;
                  while (cVar1 == '\0') {
                    cVar1 = *(char *)(*piVar14 + 0x21);
                    local_1c = piVar14;
                    piVar14 = (int *)*piVar14;
                  }
                }
                else {
                  local_1c = (int *)piVar14[1];
                  if (*(char *)((int)local_1c + 0x21) == '\0') {
                    while( true ) {
                      piVar9 = local_1c;
                      local_1c = piVar9;
                      if ((piVar14 != (int *)piVar9[2]) ||
                         (local_1c = (int *)piVar9[1], *(char *)((int)local_1c + 0x21) != '\0'))
                      break;
                      piVar14 = piVar9;
                    }
                  }
                }
                piVar14 = local_1c;
              }
            } while (piVar14 != piVar3);
            puVar12 = puVar6;
          }
          puVar15 = puVar12;
        } while (*(char *)((int)puVar12 + 0x35) != '\0');
        puVar15 = (undefined4 *)puVar12[2];
        if (*(char *)((int)puVar15 + 0x35) != '\0') break;
        cVar1 = *(char *)((int)*puVar15 + 0x35);
        puVar12 = (undefined4 *)*puVar15;
        while (puVar6 = puVar15, cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar12 + 0x35);
          puVar15 = puVar12;
          puVar12 = (undefined4 *)*puVar12;
        }
      }
      puVar15 = (undefined4 *)puVar12[1];
      puVar6 = puVar15;
    } while (*(char *)((int)puVar15 + 0x35) != '\0');
    while( true ) {
      puVar10 = puVar15;
      puVar15 = puVar10;
      puVar6 = puVar10;
      if (puVar12 != (undefined4 *)puVar10[2]) break;
      puVar15 = (undefined4 *)puVar10[1];
      puVar6 = puVar15;
      if (*(char *)((int)puVar15 + 0x35) != '\0') break;
      puVar12 = puVar10;
    }
  } while( true );
}


// ==== FUN_004a9e20 @ 0x004a9e20 ====

void FUN_004a9e20(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097f458;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009af804;
  local_4 = 1;
  if (*(char *)(in_ECX + 0xe) == '\0') {
    FUN_004a9700();
    *(undefined1 *)(in_ECX + 0xe) = 1;
  }
  if ((undefined4 *)in_ECX[0x2e] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2e])(1);
  }
  in_ECX[0x2e] = 0;
  if ((void *)in_ECX[0x14] != (void *)0x0) {
    _free((void *)in_ECX[0x14]);
    return;
  }
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  if ((void *)in_ECX[0x1b] != (void *)0x0) {
    _free((void *)in_ECX[0x1b]);
    return;
  }
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  if ((undefined4 *)in_ECX[0x2f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2f])(1);
  }
  in_ECX[0x2f] = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_004ad2b0();
  local_4 = 0xffffffff;
  FUN_0049da30();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_004a9ef0 @ 0x004a9ef0 ====

void FUN_004a9ef0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f46a;
  local_c = ExceptionList;
  if (*(int *)(in_ECX + 0x7c) != 0) {
    ExceptionList = &local_c;
    FUN_00405de0(*(int *)(in_ECX + 0x7c),*(undefined4 *)(in_ECX + 0x80),in_ECX + 0x78,param_1);
    _free(*(void **)(in_ECX + 0x7c));
    return;
  }
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  iVar3 = *(int *)(param_1 + 0x94);
  iVar1 = *(int *)(param_1 + 0x98);
  if (iVar3 != iVar1) {
    do {
      local_4 = 0xffffffff;
      uVar2 = FUN_00405bd0(local_28,param_1 + 0xac,iVar3);
      local_4 = 0;
      FUN_00406720(uVar2);
      local_4 = 0xffffffff;
      if (0xf < local_10) {
        _free(local_24);
        return;
      }
      iVar3 = iVar3 + 0x1c;
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
    } while (iVar3 != iVar1);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004a9fd0 @ 0x004a9fd0 ====

uint FUN_004a9fd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  int in_ECX;
  undefined1 local_7c [4];
  void *local_78;
  undefined4 local_68;
  uint local_64;
  undefined1 local_60 [4];
  void *local_5c;
  uint local_48;
  undefined1 local_44 [4];
  void *local_40;
  uint local_2c;
  undefined1 local_28 [4];
  uint local_24;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f48c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar3 = FUN_004d3e10(local_60);
  local_4 = 0;
  uVar3 = FUN_00405bd0(local_7c,uVar3,param_4);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0084a3c0(uVar3,local_28);
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  local_4 = 0xffffffff;
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_00;
  }
  iVar1 = *(int *)(in_ECX + 0xc0);
  cVar2 = FUN_0042d250(param_1,param_2,param_3,param_4,local_24 >> 6,0,0);
  if (cVar2 != '\0') {
    uVar3 = FUN_00405bd0(local_44,iVar1 + 0xac,param_4);
    local_4 = 2;
    FUN_00406720(uVar3);
    if (0xf < local_2c) {
      _free(local_40);
      return extraout_EAX_01;
    }
  }
  ExceptionList = local_c;
  return local_24 >> 6 & 0xffff;
}


// ==== FUN_004aa110 @ 0x004aa110 ====

void FUN_004aa110(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f4b4;
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
  local_4 = 0;
  *in_ECX = &PTR_FUN_009af804;
  FUN_004ad5a0();
  local_4._0_1_ = 1;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  FUN_00401660(param_1,0,0xffffffff);
  pvVar1 = operator_new(8);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    in_ECX[0x2f] = 0;
  }
  else {
    uVar2 = FUN_004d3910(in_ECX);
    in_ECX[0x2f] = uVar2;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004aa1d0 @ 0x004aa1d0 ====

undefined4 FUN_004aa1d0(int *param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097f4c9;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 != 7) {
    ExceptionList = pvStack_c;
    return 0;
  }
  *(int **)(in_ECX + 0xc0) = param_1;
  FUN_004ac940();
  iVar2 = *(int *)(*(int *)(in_ECX + 0xc0) + 0xc);
  *(int *)(in_ECX + 0x40) = iVar2;
  iVar1 = *(int *)(*(int *)(in_ECX + 0xc0) + 0x10);
  *(int *)(in_ECX + 0x44) = iVar1;
  iVar2 = (iVar2 + 1) * (iVar1 + 1);
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  FUN_00446310(*(undefined4 *)(in_ECX + 0x9c),iVar2,&uStack_18);
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  FUN_00446310(*(undefined4 *)(in_ECX + 0xac),iVar2,&uStack_18);
  FUN_004a9ef0(*(undefined4 *)(in_ECX + 0xc0));
  pvVar3 = operator_new(0xcc);
  uVar4 = 0;
  uStack_4 = 0;
  if (pvVar3 != (void *)0x0) {
    uVar4 = FUN_004ce210(in_ECX,*(undefined4 *)(in_ECX + 0x40),*(undefined4 *)(in_ECX + 0x44));
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xb8) = uVar4;
  if (*(char *)(in_ECX + 0x3c) == '\0') {
    FUN_004cf2d0(*(undefined4 *)(in_ECX + 0xc0));
  }
  else {
    FUN_004cf2f0(*(undefined4 *)(in_ECX + 0xc0),in_ECX + 0x88);
  }
  if (*(char *)(in_ECX + 0x3c) == '\0') {
    FUN_004a9c30(*(undefined4 *)(in_ECX + 0xc0));
  }
  FUN_004a9460(*(undefined4 *)(in_ECX + 0xc0));
  *(undefined4 *)(in_ECX + 0x34) = 2;
  uVar4 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar4;
  *(int **)(in_ECX + 0x20) = param_1;
  ExceptionList = pvStack_c;
  return 1;
}


// ==== FUN_004aa360 @ 0x004aa360 ====

void FUN_004aa360(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint local_58;
  uint local_54;
  short local_50;
  short local_4e;
  short local_4c;
  short local_4a;
  short local_48;
  short local_46;
  uint local_44 [2];
  undefined1 local_3c [4];
  void *local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  undefined4 local_20;
  void *local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = param_2;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f4e3;
  local_c = ExceptionList;
  uVar5 = param_3 * 4;
  local_50 = (short)uVar5;
  local_4e = local_50 + 1;
  local_46 = local_50 + 3;
  local_4c = local_50 + 2;
  ExceptionList = &local_c;
  local_4a = local_50;
  local_48 = local_4c;
  uVar2 = FUN_004d49b0(param_2);
  uVar3 = FUN_004d49b0(iVar1 + 0x1c);
  local_58 = uVar2;
  local_54 = uVar3;
  param_3 = FUN_004ab7c0(&local_58);
  if (((param_3 == *(int *)(param_1 + 0x30)) || (uVar2 < *(uint *)(param_3 + 0xc))) ||
     ((uVar2 <= *(uint *)(param_3 + 0xc) && (uVar3 < *(uint *)(param_3 + 0x10))))) {
    param_2 = *(int *)(param_1 + 0x30);
    piVar4 = &param_2;
  }
  else {
    piVar4 = &param_3;
  }
  iVar1 = *piVar4;
  if (iVar1 == *(int *)(param_1 + 0x30)) {
    local_38 = (void *)0x0;
    local_34 = 0;
    local_30 = 0;
    local_4 = 0;
    FUN_00426fe0(0,&local_50,local_44,param_1);
    local_44[0] = uVar5 & 0xffff;
    local_2c = local_58;
    local_44[1] = 4;
    local_20 = 4;
    local_28 = local_54;
    local_24 = local_44[0];
    FUN_00427460(local_3c);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_004ad670(&local_58,&local_2c);
    if (local_18 != (void *)0x0) {
      _free(local_18);
      return;
    }
    if (local_38 != (void *)0x0) {
      _free(local_38);
      return;
    }
  }
  else {
    FUN_00426fe0(*(undefined4 *)(iVar1 + 0x24),&local_50,local_44,param_1);
    uVar5 = uVar5 & 0xffff;
    if (uVar5 < *(uint *)(iVar1 + 0x14)) {
      *(uint *)(iVar1 + 0x14) = uVar5;
    }
    uVar5 = (uVar5 - *(int *)(iVar1 + 0x14)) + 4;
    if (*(uint *)(iVar1 + 0x18) < uVar5) {
      *(uint *)(iVar1 + 0x18) = uVar5;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004aa520 @ 0x004aa520 ====

void FUN_004aa520(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  uint *puVar7;
  int local_5c;
  uint *local_58;
  int *local_54;
  undefined1 local_50 [8];
  uint local_48;
  uint local_44;
  int local_40;
  int local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24 [2];
  void *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f4fd;
  local_c = ExceptionList;
  piVar5 = *(int **)(param_2 + 0xa4);
  piVar6 = (int *)*piVar5;
  ExceptionList = &local_c;
  local_54 = piVar5;
  if (piVar6 != piVar5) {
    do {
      local_58 = (uint *)piVar6[6];
      puVar7 = (uint *)piVar6[5];
      param_2 = piVar6[3];
      if (puVar7 != local_58) {
        do {
          local_44 = *puVar7 / *(uint *)(in_ECX + 0x40);
          local_48 = *puVar7 % *(uint *)(in_ECX + 0x40);
          local_3c = ((ushort)puVar7[1] - 1) + local_44;
          local_40 = ((ushort)puVar7[1] - 1) + local_48;
          cVar4 = FUN_0040ef40(param_1,&local_48);
          iVar2 = param_3;
          if (cVar4 != '\0') {
            FUN_0042eb40(&local_5c,&param_2);
            if (local_5c == *(int *)(iVar2 + 4)) {
              local_34 = (void *)0x0;
              local_30 = 0;
              local_2c = 0;
              local_4 = 0;
              FUN_00430ed0(puVar7);
              local_24[0] = param_2;
              FUN_00430e00(local_38);
              local_10 = local_28;
              local_4 = CONCAT31(local_4._1_3_,1);
              FUN_00432120(local_50,local_24);
              if (local_1c != (void *)0x0) {
                _free(local_1c);
                return;
              }
              local_1c = (void *)0x0;
              local_18 = 0;
              local_14 = 0;
              local_4 = 0xffffffff;
              if (local_34 != (void *)0x0) {
                _free(local_34);
                return;
              }
              local_34 = (void *)0x0;
              local_30 = 0;
              local_2c = 0;
            }
            else {
              FUN_00430ed0(puVar7);
            }
          }
          puVar7 = puVar7 + 3;
        } while (puVar7 != local_58);
        piVar5 = local_54;
      }
      if (*(char *)((int)piVar6 + 0x25) == '\0') {
        piVar1 = (int *)piVar6[2];
        if (*(char *)((int)piVar1 + 0x25) == '\0') {
          cVar4 = *(char *)(*piVar1 + 0x25);
          piVar6 = piVar1;
          piVar1 = (int *)*piVar1;
          while (cVar4 == '\0') {
            cVar4 = *(char *)(*piVar1 + 0x25);
            piVar6 = piVar1;
            piVar1 = (int *)*piVar1;
          }
        }
        else {
          cVar4 = *(char *)(piVar6[1] + 0x25);
          piVar3 = (int *)piVar6[1];
          piVar1 = piVar6;
          while ((piVar6 = piVar3, cVar4 == '\0' && (piVar1 == (int *)piVar6[2]))) {
            cVar4 = *(char *)(piVar6[1] + 0x25);
            piVar3 = (int *)piVar6[1];
            piVar1 = piVar6;
          }
        }
      }
    } while (piVar6 != piVar5);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_004aa6f0 @ 0x004aa6f0 ====

void FUN_004aa6f0(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  void *pvVar8;
  int in_ECX;
  void *pvVar9;
  uint uVar10;
  uint uStack_1fc;
  void *pvStack_1f8;
  void *pvStack_1f4;
  void *pvStack_1f0;
  void *pvStack_1ec;
  uint uStack_1e8;
  void *pvStack_1e4;
  void *pvStack_1e0;
  void *pvStack_1dc;
  void *pvStack_1d8;
  void *pvStack_1d4;
  uint uStack_1d0;
  int iStack_1cc;
  int iStack_1c8;
  undefined1 auStack_1c4 [4];
  undefined4 *puStack_1c0;
  undefined4 uStack_1bc;
  int iStack_1b8;
  void *pvStack_1b4;
  undefined1 auStack_1b0 [12];
  int iStack_1a4;
  undefined1 auStack_1a0 [4];
  void *pvStack_19c;
  int iStack_18c;
  uint uStack_188;
  void *pvStack_180;
  undefined4 uStack_170;
  uint uStack_16c;
  undefined1 auStack_168 [4];
  void *pvStack_164;
  undefined4 uStack_154;
  uint uStack_150;
  undefined1 auStack_14c [4];
  void *pvStack_148;
  undefined4 uStack_138;
  uint uStack_134;
  undefined1 auStack_130 [4];
  void *pvStack_12c;
  void *pvStack_128;
  undefined4 uStack_124;
  undefined1 auStack_120 [4];
  void *pvStack_11c;
  undefined4 uStack_10c;
  uint uStack_108;
  undefined1 auStack_104 [4];
  void *pvStack_100;
  undefined4 uStack_f0;
  uint uStack_ec;
  undefined1 auStack_e8 [4];
  void *pvStack_e4;
  undefined4 uStack_d4;
  uint uStack_d0;
  undefined1 auStack_cc [144];
  undefined1 auStack_3c [48];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097f58b;
  pvStack_c = ExceptionList;
  if (param_2 == 0) {
    return;
  }
  pvStack_1e4 = *(void **)(param_2 + 0x40);
  pvStack_1e0 = *(void **)(param_2 + 0x44);
  pvStack_1dc = *(void **)(param_2 + 0x48);
  pvStack_1d8 = *(void **)(param_2 + 0x4c);
  iVar5 = ((int)pvStack_1d8 - (int)pvStack_1e0) * ((int)pvStack_1dc - (int)pvStack_1e4);
  uStack_1fc = iVar5 * 4;
  ExceptionList = &pvStack_c;
  puStack_1c0 = (undefined4 *)FUN_00412d20();
  *(undefined1 *)((int)puStack_1c0 + 0x25) = 1;
  puStack_1c0[1] = puStack_1c0;
  *puStack_1c0 = puStack_1c0;
  puStack_1c0[2] = puStack_1c0;
  uStack_1bc = 0;
  uStack_4 = 0;
  FUN_004aa520(&pvStack_1e4,param_1,auStack_1c4);
  pvStack_12c = (void *)0x0;
  pvStack_128 = (void *)0x0;
  uStack_124 = 0;
  uStack_4._0_1_ = 1;
  FUN_004acb70(iVar5);
  FUN_004a9570(auStack_130,&pvStack_1e4,param_1);
  FUN_004cf060();
  iStack_1b8 = *(int *)(param_2 + 0xc4);
  *(uint *)(iStack_1b8 + 8) = ((uint)pvStack_1e4 & 0xfffffff0) << 0xc | (uint)pvStack_1e0 >> 4;
  pvStack_1d4 = *(void **)(param_1 + 0xc);
  iStack_1a4 = (int)pvStack_1d4 + 1;
  pvStack_1f0 = pvStack_12c;
  piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar5 = (**(code **)(*piVar6 + 0x1c))();
  if (*(int *)(iVar5 + 8) == 0) {
    FUN_004aca80(uStack_1fc);
    FUN_0040d030(auStack_cc,0x24,4,FUN_00419fa0);
    pvStack_1f8 = pvStack_1e0;
    if (pvStack_1e0 < pvStack_1d8) {
      iStack_1c8 = (int)pvStack_1d4 * (int)pvStack_1e0;
      pvVar8 = pvStack_1dc;
      pvVar9 = pvStack_1e4;
      do {
        pvStack_1f4 = pvVar9;
        if (pvVar9 < pvVar8) {
          do {
            if (pvStack_1f0 == pvStack_128) {
              uStack_150 = 0xf;
              uStack_154 = 0;
              pvStack_164 = (void *)((uint)pvStack_164 & 0xffffff00);
              FUN_00401740(s_itCellProperty____vecCellPropert_009af720,0x27);
              uStack_4 = CONCAT31(uStack_4._1_3_,8);
              FUN_00406880(auStack_168);
              if (uStack_150 < 0x10) {
                uStack_150 = 0xf;
                uStack_154 = 0;
                pvStack_164 = (void *)((uint)pvStack_164 & 0xffffff00);
                pcVar3 = (code *)swi(3);
                (*pcVar3)();
                return;
              }
              _free(pvStack_164);
              return;
            }
            pvStack_1b4 = pvStack_1f0;
            pvStack_1f0 = (void *)((int)pvStack_1f0 + 0xc);
            iVar5 = (((int)pvStack_1f8 - (int)pvStack_1e0) * ((int)pvVar8 - (int)pvVar9) -
                    (int)pvVar9) + (int)pvStack_1f4;
            uStack_188 = 0xf;
            iStack_18c = 0;
            pvStack_19c = (void *)((uint)pvStack_19c & 0xffffff00);
            uStack_16c = 0xf;
            uStack_170 = 0;
            pvStack_180 = (void *)((uint)pvStack_180 & 0xffffff00);
            uStack_4._0_1_ = 9;
            FUN_00401740(&DAT_009af748,0);
            FUN_004a8bd0(auStack_cc,pvStack_1f4,pvStack_1f8,param_1);
            cVar4 = FUN_004d39a0(param_1,auStack_1c4,pvStack_1f4,pvStack_1f8,&uStack_1e8,auStack_1b0
                                );
            if (cVar4 == '\0') {
              uStack_1fc = iStack_1c8 + (int)pvStack_1f4;
              iVar2 = *(int *)(param_1 + 0x6c);
              if ((iVar2 == 0) || ((uint)(*(int *)(param_1 + 0x70) - iVar2 >> 1) <= uStack_1fc))
              goto LAB_004ab2d5;
              uVar1 = *(ushort *)(iVar2 + uStack_1fc * 2);
              iStack_1cc = CONCAT22((short)((uint)iVar2 >> 0x10),uVar1);
              if (3 < uVar1) {
                uStack_134 = 0xf;
                uStack_138 = 0;
                pvStack_148 = (void *)((uint)pvStack_148 & 0xffffff00);
                FUN_00401740(s_curTexPattern_<_MAPDATA::_dwNumP_009af74c,0x26);
                uStack_4._0_1_ = 10;
                FUN_00406880(auStack_14c);
                uStack_4 = CONCAT31(uStack_4._1_3_,9);
                if (uStack_134 < 0x10) {
                  uStack_134 = 0xf;
                  uStack_138 = 0;
                  pvStack_148 = (void *)((uint)pvStack_148 & 0xffffff00);
                  pcVar3 = (code *)swi(3);
                  (*pcVar3)();
                  return;
                }
                _free(pvStack_148);
                return;
              }
              uStack_1fc = FUN_004d2150(pvStack_1b4,iStack_1cc);
              uStack_1d0 = param_1 + 0x18;
              pvStack_1ec = *(void **)(param_1 + 0x1c);
              if ((pvStack_1ec == (void *)0x0) ||
                 ((uint)((*(int *)(param_1 + 0x20) - (int)pvStack_1ec) / 0x1c) <= uStack_1fc)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              uVar7 = FUN_00405bd0(auStack_120,param_1 + 0xac,
                                   (void *)((int)pvStack_1ec + uStack_1fc * 0x1c));
              uStack_4._0_1_ = 0xb;
              FUN_00401660(uVar7,0,0xffffffff);
              uStack_4._0_1_ = 9;
              if (0xf < uStack_108) {
                _free(pvStack_11c);
                return;
              }
              uStack_108 = 0xf;
              uStack_10c = 0;
              pvStack_11c = (void *)((uint)pvStack_11c & 0xffffff00);
              FUN_004d33d0(auStack_cc,pvStack_1b4,iStack_1cc);
            }
            else {
              uStack_1fc = *(uint *)(in_ECX + 0x7c);
              pvStack_1ec = (void *)(in_ECX + 0x78);
              if ((uStack_1fc == 0) ||
                 ((uint)((int)(*(int *)(in_ECX + 0x80) - uStack_1fc) / 0x1c) <= uStack_1e8)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              FUN_00401660(uStack_1fc + uStack_1e8 * 0x1c,0,0xffffffff);
              FUN_004d25a0(auStack_cc,pvStack_1f4,pvStack_1f8,*(undefined4 *)(in_ECX + 0x40),
                           auStack_1b0);
            }
            FUN_004ac4f0(*(undefined4 *)(iStack_1b8 + 0x24),auStack_cc,auStack_3c,uStack_1fc);
            FUN_004aa360(iStack_1b8,auStack_1a0,iVar5);
            uStack_4._0_1_ = 1;
            if (0xf < uStack_16c) {
              _free(pvStack_180);
              return;
            }
            uStack_16c = 0xf;
            uStack_170 = 0;
            pvStack_180 = (void *)((uint)pvStack_180 & 0xffffff00);
            if (0xf < uStack_188) {
              _free(pvStack_19c);
              return;
            }
            pvStack_1f4 = (void *)((int)pvStack_1f4 + 1);
            uStack_188 = 0xf;
            iStack_18c = 0;
            pvStack_19c = (void *)((uint)pvStack_19c & 0xffffff00);
            pvVar8 = pvStack_1dc;
            pvVar9 = pvStack_1e4;
          } while (pvStack_1f4 < pvStack_1dc);
        }
        iStack_1c8 = iStack_1c8 + (int)pvStack_1d4;
        pvStack_1f8 = (void *)((int)pvStack_1f8 + 1);
      } while (pvStack_1f8 < pvStack_1d8);
    }
  }
  else {
    FUN_004ac990(uStack_1fc);
    FUN_0040d030(auStack_cc,0x30,4,FUN_00419fa0);
    pvStack_1f4 = pvStack_1e0;
    if (pvStack_1e0 < pvStack_1d8) {
      iStack_1c8 = (int)pvStack_1d4 * (int)pvStack_1e0;
      pvVar8 = pvStack_1dc;
      pvVar9 = pvStack_1e4;
      do {
        pvStack_1f8 = pvVar9;
        if (pvVar9 < pvVar8) {
          do {
            if (pvStack_1f0 == pvStack_128) {
              uStack_134 = 0xf;
              uStack_138 = 0;
              pvStack_148 = (void *)((uint)pvStack_148 & 0xffffff00);
              FUN_00401740(s_itCellProperty____vecCellPropert_009af6c4,0x27);
              uStack_4 = CONCAT31(uStack_4._1_3_,2);
              FUN_00406880(auStack_14c);
              if (uStack_134 < 0x10) {
                uStack_134 = 0xf;
                uStack_138 = 0;
                pvStack_148 = (void *)((uint)pvStack_148 & 0xffffff00);
                pcVar3 = (code *)swi(3);
                (*pcVar3)();
                return;
              }
              _free(pvStack_148);
              return;
            }
            pvStack_1ec = pvStack_1f0;
            pvStack_1f0 = (void *)((int)pvStack_1f0 + 0xc);
            iVar5 = (((int)pvStack_1f4 - (int)pvStack_1e0) * ((int)pvVar8 - (int)pvVar9) -
                    (int)pvVar9) + (int)pvStack_1f8;
            uStack_188 = 0xf;
            iStack_18c = 0;
            pvStack_19c = (void *)((uint)pvStack_19c & 0xffffff00);
            uStack_16c = 0xf;
            uStack_170 = 0;
            pvStack_180 = (void *)((uint)pvStack_180 & 0xffffff00);
            uStack_4._0_1_ = 3;
            FUN_00401740(&DAT_009af6ec,0);
            FUN_004a8a30(auStack_cc,pvStack_1f8,pvStack_1f4,param_1);
            cVar4 = FUN_004d39a0(param_1,auStack_1c4,pvStack_1f8,pvStack_1f4,&uStack_1e8,auStack_1b0
                                );
            if (cVar4 == '\0') {
              uStack_1d0 = iStack_1c8 + (int)pvStack_1f8;
              iVar2 = *(int *)(param_1 + 0x6c);
              if ((iVar2 == 0) || ((uint)(*(int *)(param_1 + 0x70) - iVar2 >> 1) <= uStack_1d0)) {
LAB_004ab2d5:
                    /* WARNING: Subroutine does not return */
                FUN_00426d40();
              }
              uVar1 = *(ushort *)(iVar2 + uStack_1d0 * 2);
              iStack_1cc = CONCAT22((short)((uint)iVar2 >> 0x10),uVar1);
              if (3 < uVar1) {
                uStack_150 = 0xf;
                uStack_154 = 0;
                pvStack_164 = (void *)((uint)pvStack_164 & 0xffffff00);
                FUN_00401740(s_curTexPattern_<_MAPDATA::_dwNumP_009af6f0,0x26);
                uStack_4._0_1_ = 4;
                FUN_00406880(auStack_168);
                uStack_4 = CONCAT31(uStack_4._1_3_,3);
                if (uStack_150 < 0x10) {
                  uStack_150 = 0xf;
                  uStack_154 = 0;
                  pvStack_164 = (void *)((uint)pvStack_164 & 0xffffff00);
                  pcVar3 = (code *)swi(3);
                  (*pcVar3)();
                  return;
                }
                _free(pvStack_164);
                return;
              }
              uStack_1d0 = FUN_004d2150(pvStack_1ec,iStack_1cc);
              uStack_1fc = param_1 + 0x18;
              pvStack_1b4 = *(void **)(param_1 + 0x1c);
              if ((pvStack_1b4 == (void *)0x0) ||
                 ((uint)((*(int *)(param_1 + 0x20) - (int)pvStack_1b4) / 0x1c) <= uStack_1d0)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              uVar7 = FUN_00405bd0(auStack_e8,param_1 + 0xac,
                                   (void *)((int)pvStack_1b4 + uStack_1d0 * 0x1c));
              uStack_4._0_1_ = 5;
              FUN_00401660(uVar7,0,0xffffffff);
              uStack_4._0_1_ = 3;
              if (0xf < uStack_d0) {
                _free(pvStack_e4);
                return;
              }
              uStack_d0 = 0xf;
              uStack_d4 = 0;
              pvStack_e4 = (void *)((uint)pvStack_e4 & 0xffffff00);
              FUN_004d2e90(auStack_cc,pvStack_1ec,iStack_1cc);
            }
            else {
              uStack_1fc = *(uint *)(in_ECX + 0x7c);
              pvStack_1ec = (void *)(in_ECX + 0x78);
              if ((uStack_1fc == 0) ||
                 ((uint)((int)(*(int *)(in_ECX + 0x80) - uStack_1fc) / 0x1c) <= uStack_1e8)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              FUN_00401660(uStack_1fc + uStack_1e8 * 0x1c,0,0xffffffff);
              FUN_004d21b0(auStack_cc,pvStack_1f8,pvStack_1f4,*(undefined4 *)(in_ECX + 0x40),
                           auStack_1b0);
            }
            FUN_004d3ab0(auStack_cc,pvStack_1f8,pvStack_1f4,iStack_1a4,in_ECX + 0x98,in_ECX + 0xa8);
            FUN_00405b90(auStack_104,0,iStack_18c + -4);
            uStack_4._0_1_ = 6;
            uVar7 = FUN_00402220(auStack_120,auStack_104,s___dds_009af718);
            uStack_4._0_1_ = 7;
            FUN_00401660(uVar7,0,0xffffffff);
            uStack_4._0_1_ = 6;
            if (0xf < uStack_108) {
              _free(pvStack_11c);
              return;
            }
            uStack_108 = 0xf;
            uStack_10c = 0;
            pvStack_11c = (void *)((uint)pvStack_11c & 0xffffff00);
            FUN_004ac240(*(undefined4 *)(iStack_1b8 + 0x14),auStack_cc,&pvStack_c,uStack_1fc);
            FUN_004aa360(iStack_1b8,auStack_1a0,iVar5);
            if (0xf < uStack_ec) {
              _free(pvStack_100);
              return;
            }
            uStack_ec = 0xf;
            uStack_f0 = 0;
            pvStack_100 = (void *)((uint)pvStack_100 & 0xffffff00);
            uStack_4._0_1_ = 1;
            if (0xf < uStack_16c) {
              _free(pvStack_180);
              return;
            }
            uStack_16c = 0xf;
            uStack_170 = 0;
            pvStack_180 = (void *)((uint)pvStack_180 & 0xffffff00);
            if (0xf < uStack_188) {
              _free(pvStack_19c);
              return;
            }
            pvStack_1f8 = (void *)((int)pvStack_1f8 + 1);
            uStack_188 = 0xf;
            iStack_18c = 0;
            pvStack_19c = (void *)((uint)pvStack_19c & 0xffffff00);
            pvVar8 = pvStack_1dc;
            pvVar9 = pvStack_1e4;
          } while (pvStack_1f8 < pvStack_1dc);
        }
        iStack_1c8 = iStack_1c8 + (int)pvStack_1d4;
        pvStack_1f4 = (void *)((int)pvStack_1f4 + 1);
      } while (pvStack_1f4 < pvStack_1d8);
    }
  }
  FUN_004cd4e0();
  piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar5 = (**(code **)(*piVar6 + 0x1c))();
  if (*(int *)(iVar5 + 8) == 0) {
    if (pvStack_12c != (void *)0x0) {
      _free(pvStack_12c);
      return;
    }
    uStack_4 = 0xffffffff;
    FUN_004141c0(&uStack_1fc,*puStack_1c0,puStack_1c0);
  }
  else {
    uStack_1fc = *(uint *)(iStack_1b8 + 0x14);
    uVar10 = *(uint *)(iStack_1b8 + 0x10);
    pvStack_1d4 = pvStack_1e0;
    if (pvStack_1e0 < pvStack_1d8) {
      pvVar8 = pvStack_1dc;
      do {
        pvStack_1f0 = pvStack_1e4;
        if (pvStack_1e4 < pvVar8) {
          do {
            if (uVar10 == uStack_1fc) break;
            iStack_1cc = (int)pvStack_1d4 * iStack_1a4;
            FUN_004a8940(param_1,(void *)((int)pvStack_1f0 + iStack_1cc),uVar10);
            pvStack_1ec = (void *)(((int)pvStack_1d4 + 1U) * iStack_1a4);
            FUN_004a8940(param_1,(void *)((int)pvStack_1f0 + (int)pvStack_1ec),uVar10 + 0x30);
            FUN_004a8940(param_1,(int)pvStack_1f0 + 1U + (int)pvStack_1ec,uVar10 + 0x60);
            FUN_004a8940(param_1,(int)pvStack_1f0 + iStack_1cc + 1,uVar10 + 0x90);
            pvStack_1f0 = (void *)((int)pvStack_1f0 + 1);
            uVar10 = uVar10 + 0xc0;
            pvVar8 = pvStack_1dc;
          } while (pvStack_1f0 < pvStack_1dc);
        }
        pvStack_1d4 = (void *)((int)pvStack_1d4 + 1);
      } while (pvStack_1d4 < pvStack_1d8);
    }
    if (pvStack_12c != (void *)0x0) {
      _free(pvStack_12c);
      return;
    }
    uStack_4 = 0xffffffff;
    FUN_004141c0(&uStack_1fc,*puStack_1c0,puStack_1c0);
  }
  _free(puStack_1c0);
  return;
}


// ==== FUN_004aa714 @ 0x004aa714 ====

/* WARNING: Removing unreachable block (ram,0x004ab3d4) */
/* WARNING: Removing unreachable block (ram,0x004aad31) */
/* WARNING: Removing unreachable block (ram,0x004aa8ec) */
/* WARNING: Removing unreachable block (ram,0x004ab23c) */
/* WARNING: Removing unreachable block (ram,0x004ab270) */
/* WARNING: Removing unreachable block (ram,0x004aaadd) */
/* WARNING: Removing unreachable block (ram,0x004aad60) */
/* WARNING: Removing unreachable block (ram,0x004aade9) */
/* WARNING: Removing unreachable block (ram,0x004ab0e1) */
/* WARNING: Removing unreachable block (ram,0x004aaef0) */

void FUN_004aa714(undefined1 param_1,uint param_2,uint param_3,uint param_4,uint param_5,
                 uint param_6,undefined1 param_7)

{
  ushort uVar1;
  code *pcVar2;
  uint uVar3;
  char cVar4;
  int in_EAX;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int in_ECX;
  uint uVar9;
  undefined1 uVar10;
  uint unaff_EBX;
  uint uVar11;
  bool in_ZF;
  uint uStack00000020;
  uint uStack00000024;
  uint uStack00000028;
  uint in_stack_0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  int in_stack_00000038;
  undefined1 uStack0000003c;
  undefined4 *in_stack_00000040;
  undefined1 uStack00000050;
  int in_stack_0000005c;
  undefined1 uStack00000060;
  undefined4 in_stack_00000064;
  undefined1 uStack00000098;
  undefined1 uStack0000009c;
  undefined3 uStack0000009d;
  undefined1 uStack000000b4;
  undefined1 uStack000000b8;
  undefined3 uStack000000b9;
  undefined1 uStack000000d0;
  undefined1 uStack000000e0;
  void *in_stack_000000e4;
  uint in_stack_000000f8;
  undefined1 uStack000000fc;
  void *in_stack_00000100;
  uint in_stack_00000114;
  undefined1 uStack00000118;
  void *in_stack_0000011c;
  uint in_stack_00000130;
  undefined1 uStack00000134;
  undefined1 uStack000001c4;
  undefined4 uStack000001f4;
  int in_stack_00000204;
  int in_stack_00000208;
  
  if (in_ZF) {
    ExceptionList = uStack000001f4;
    return;
  }
  _param_7 = *(uint *)(in_EAX + 0x40);
  uStack00000020 = *(uint *)(in_EAX + 0x44);
  uStack00000024 = *(uint *)(in_EAX + 0x48);
  uStack00000028 = *(uint *)(in_EAX + 0x4c);
  iVar5 = (uStack00000028 - uStack00000020) * (uStack00000024 - _param_7);
  _param_1 = iVar5 * 4;
  in_stack_00000040 = (undefined4 *)FUN_00412d20();
  *(undefined1 *)((int)in_stack_00000040 + 0x25) = 1;
  in_stack_00000040[1] = in_stack_00000040;
  *in_stack_00000040 = in_stack_00000040;
  in_stack_00000040[2] = in_stack_00000040;
  FUN_004aa520(&param_7,in_stack_00000204,&uStack0000003c);
  FUN_004acb70(iVar5);
  FUN_004a9570(&uStack000000d0,&param_7,in_stack_00000204);
  FUN_004cf060();
  iVar5 = *(int *)(in_stack_00000208 + 0xc4);
  *(uint *)(iVar5 + 8) = (_param_7 & 0xfffffff0) << 0xc | uStack00000020 >> 4;
  in_stack_0000002c = *(uint *)(in_stack_00000204 + 0xc);
  in_stack_0000005c = in_stack_0000002c + 1;
  param_4 = unaff_EBX;
  piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar7 = (**(code **)(*piVar6 + 0x1c))();
  uVar10 = (undefined1)unaff_EBX;
  uStack000000b8 = uVar10;
  uStack0000009c = uVar10;
  if (*(uint *)(iVar7 + 8) == unaff_EBX) {
    FUN_004aca80(_param_1);
    FUN_0040d030(&uStack00000134,0x24,4,FUN_00419fa0);
    param_2 = uStack00000020;
    if (uStack00000020 < uStack00000028) {
      in_stack_00000038 = in_stack_0000002c * uStack00000020;
      uVar11 = uStack00000024;
      uVar9 = _param_7;
      do {
        param_3 = uVar9;
        if (uVar9 < uVar11) {
          do {
            uVar3 = param_4;
            if (param_4 == unaff_EBX) {
              FUN_00401740(s_itCellProperty____vecCellPropert_009af720,0x27);
              FUN_00406880(&uStack00000098);
              _uStack0000009c = CONCAT31(uStack0000009d,uVar10);
              pcVar2 = (code *)swi(3);
              (*pcVar2)();
              return;
            }
            param_4 = param_4 + 0xc;
            iVar7 = ((param_2 - uStack00000020) * (uVar11 - uVar9) - uVar9) + param_3;
            in_stack_00000064 = CONCAT31(in_stack_00000064._1_3_,uVar10);
            FUN_00401740(&DAT_009af748,unaff_EBX);
            FUN_004a8bd0(&uStack00000134,param_3,param_2,in_stack_00000204);
            cVar4 = FUN_004d39a0(in_stack_00000204,&uStack0000003c,param_3,param_2,&param_6,
                                 &uStack00000050);
            if (cVar4 == '\0') {
              _param_1 = in_stack_00000038 + param_3;
              uVar11 = *(uint *)(in_stack_00000204 + 0x6c);
              if ((uVar11 == unaff_EBX) ||
                 ((uint)((int)(*(int *)(in_stack_00000204 + 0x70) - uVar11) >> 1) <= _param_1))
              goto LAB_004ab2d5;
              uVar1 = *(ushort *)(uVar11 + _param_1 * 2);
              in_stack_00000034 = CONCAT22((short)(uVar11 >> 0x10),uVar1);
              if (3 < uVar1) {
                FUN_00401740(s_curTexPattern_<_MAPDATA::_dwNumP_009af74c,0x26);
                FUN_00406880(&uStack000000b4);
                _uStack000000b8 = CONCAT31(uStack000000b9,uVar10);
                pcVar2 = (code *)swi(3);
                (*pcVar2)();
                return;
              }
              _param_1 = FUN_004d2150(uVar3,in_stack_00000034);
              in_stack_00000030 = in_stack_00000204 + 0x18;
              param_5 = *(uint *)(in_stack_00000204 + 0x1c);
              if ((param_5 == unaff_EBX) ||
                 ((uint)((int)(*(int *)(in_stack_00000204 + 0x20) - param_5) / 0x1c) <= _param_1)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              uVar8 = FUN_00405bd0(&uStack000000e0,in_stack_00000204 + 0xac,
                                   param_5 + _param_1 * 0x1c);
              FUN_00401660(uVar8,unaff_EBX,0xffffffff);
              if (0xf < in_stack_000000f8) {
                _free(in_stack_000000e4);
                return;
              }
              in_stack_000000f8 = 0xf;
              in_stack_000000e4 = (void *)CONCAT31(in_stack_000000e4._1_3_,uVar10);
              FUN_004d33d0(&uStack00000134,uVar3,in_stack_00000034);
            }
            else {
              _param_1 = *(uint *)(in_ECX + 0x7c);
              param_5 = in_ECX + 0x78;
              if ((_param_1 == unaff_EBX) ||
                 ((uint)((int)(*(int *)(in_ECX + 0x80) - _param_1) / 0x1c) <= param_6)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              FUN_00401660(_param_1 + param_6 * 0x1c,unaff_EBX,0xffffffff);
              FUN_004d25a0(&uStack00000134,param_3,param_2,*(undefined4 *)(in_ECX + 0x40),
                           &uStack00000050);
            }
            FUN_004ac4f0(*(undefined4 *)(iVar5 + 0x24),&uStack00000134,&uStack000001c4,_param_1);
            FUN_004aa360(iVar5,&uStack00000060,iVar7);
            param_3 = param_3 + 1;
            in_stack_00000064 = CONCAT31(in_stack_00000064._1_3_,uVar10);
            uVar11 = uStack00000024;
            uVar9 = _param_7;
          } while (param_3 < uStack00000024);
        }
        in_stack_00000038 = in_stack_00000038 + in_stack_0000002c;
        param_2 = param_2 + 1;
      } while (param_2 < uStack00000028);
    }
  }
  else {
    FUN_004ac990(_param_1);
    FUN_0040d030(&uStack00000134,0x30,4,FUN_00419fa0);
    param_3 = uStack00000020;
    if (uStack00000020 < uStack00000028) {
      in_stack_00000038 = in_stack_0000002c * uStack00000020;
      uVar11 = uStack00000024;
      uVar9 = _param_7;
      do {
        param_2 = uVar9;
        if (uVar9 < uVar11) {
          do {
            if (param_4 == unaff_EBX) {
              FUN_00401740(s_itCellProperty____vecCellPropert_009af6c4,0x27);
              FUN_00406880(&uStack000000b4);
              _uStack000000b8 = CONCAT31(uStack000000b9,uVar10);
              pcVar2 = (code *)swi(3);
              (*pcVar2)();
              return;
            }
            param_5 = param_4;
            param_4 = param_4 + 0xc;
            iVar7 = ((param_3 - uStack00000020) * (uVar11 - uVar9) - uVar9) + param_2;
            in_stack_00000064 = CONCAT31(in_stack_00000064._1_3_,uVar10);
            FUN_00401740(&DAT_009af6ec,unaff_EBX);
            FUN_004a8a30(&uStack00000134,param_2,param_3,in_stack_00000204);
            cVar4 = FUN_004d39a0(in_stack_00000204,&uStack0000003c,param_2,param_3,&param_6,
                                 &uStack00000050);
            if (cVar4 == '\0') {
              in_stack_00000030 = in_stack_00000038 + param_2;
              uVar11 = *(uint *)(in_stack_00000204 + 0x6c);
              if ((uVar11 == unaff_EBX) ||
                 ((uint)((int)(*(int *)(in_stack_00000204 + 0x70) - uVar11) >> 1) <=
                  in_stack_00000030)) {
LAB_004ab2d5:
                    /* WARNING: Subroutine does not return */
                FUN_00426d40();
              }
              uVar1 = *(ushort *)(uVar11 + in_stack_00000030 * 2);
              in_stack_00000034 = CONCAT22((short)(uVar11 >> 0x10),uVar1);
              if (3 < uVar1) {
                FUN_00401740(s_curTexPattern_<_MAPDATA::_dwNumP_009af6f0,0x26);
                FUN_00406880(&uStack00000098);
                _uStack0000009c = CONCAT31(uStack0000009d,uVar10);
                pcVar2 = (code *)swi(3);
                (*pcVar2)();
                return;
              }
              in_stack_00000030 = FUN_004d2150(param_5,in_stack_00000034);
              _param_1 = in_stack_00000204 + 0x18;
              uVar11 = *(uint *)(in_stack_00000204 + 0x1c);
              if ((uVar11 == unaff_EBX) ||
                 ((uint)((int)(*(int *)(in_stack_00000204 + 0x20) - uVar11) / 0x1c) <=
                  in_stack_00000030)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              uVar8 = FUN_00405bd0(&uStack00000118,in_stack_00000204 + 0xac,
                                   uVar11 + in_stack_00000030 * 0x1c);
              FUN_00401660(uVar8,unaff_EBX,0xffffffff);
              if (0xf < in_stack_00000130) {
                _free(in_stack_0000011c);
                return;
              }
              in_stack_00000130 = 0xf;
              in_stack_0000011c = (void *)CONCAT31(in_stack_0000011c._1_3_,uVar10);
              FUN_004d2e90(&uStack00000134,param_5,in_stack_00000034);
            }
            else {
              _param_1 = *(uint *)(in_ECX + 0x7c);
              param_5 = in_ECX + 0x78;
              if ((_param_1 == unaff_EBX) ||
                 ((uint)((int)(*(int *)(in_ECX + 0x80) - _param_1) / 0x1c) <= param_6)) {
                    /* WARNING: Subroutine does not return */
                FUN_00405ca0();
              }
              FUN_00401660(_param_1 + param_6 * 0x1c,unaff_EBX,0xffffffff);
              FUN_004d21b0(&uStack00000134,param_2,param_3,*(undefined4 *)(in_ECX + 0x40),
                           &uStack00000050);
            }
            FUN_004d3ab0(&uStack00000134,param_2,param_3,in_stack_0000005c,in_ECX + 0x98,
                         in_ECX + 0xa8);
            FUN_00405b90(&uStack000000fc,unaff_EBX,unaff_EBX - 4);
            uVar8 = FUN_00402220(&uStack000000e0,&uStack000000fc,s___dds_009af718);
            FUN_00401660(uVar8,unaff_EBX,0xffffffff);
            if (0xf < in_stack_000000f8) {
              _free(in_stack_000000e4);
              return;
            }
            in_stack_000000f8 = 0xf;
            in_stack_000000e4 = (void *)CONCAT31(in_stack_000000e4._1_3_,uVar10);
            FUN_004ac240(*(undefined4 *)(iVar5 + 0x14),&uStack00000134,&uStack000001f4,_param_1);
            FUN_004aa360(iVar5,&uStack00000060,iVar7);
            if (0xf < in_stack_00000114) {
              _free(in_stack_00000100);
              return;
            }
            in_stack_00000114 = 0xf;
            in_stack_00000100 = (void *)CONCAT31(in_stack_00000100._1_3_,uVar10);
            param_2 = param_2 + 1;
            in_stack_00000064 = CONCAT31(in_stack_00000064._1_3_,uVar10);
            uVar11 = uStack00000024;
            uVar9 = _param_7;
          } while (param_2 < uStack00000024);
        }
        in_stack_00000038 = in_stack_00000038 + in_stack_0000002c;
        param_3 = param_3 + 1;
      } while (param_3 < uStack00000028);
    }
  }
  FUN_004cd4e0();
  piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar7 = (**(code **)(*piVar6 + 0x1c))();
  if (*(uint *)(iVar7 + 8) == unaff_EBX) {
    FUN_004141c0(&param_1,*in_stack_00000040,in_stack_00000040);
  }
  else {
    _param_1 = *(uint *)(iVar5 + 0x14);
    uVar11 = *(uint *)(iVar5 + 0x10);
    in_stack_0000002c = uStack00000020;
    if (uStack00000020 < uStack00000028) {
      uVar9 = uStack00000024;
      do {
        param_4 = _param_7;
        if (_param_7 < uVar9) {
          do {
            if (uVar11 == _param_1) break;
            in_stack_00000034 = in_stack_0000002c * in_stack_0000005c;
            FUN_004a8940(in_stack_00000204,param_4 + in_stack_00000034,uVar11);
            param_5 = (in_stack_0000002c + 1) * in_stack_0000005c;
            FUN_004a8940(in_stack_00000204,param_4 + param_5,uVar11 + 0x30);
            FUN_004a8940(in_stack_00000204,param_4 + 1 + param_5,uVar11 + 0x60);
            FUN_004a8940(in_stack_00000204,param_4 + 1 + in_stack_00000034,uVar11 + 0x90);
            param_4 = param_4 + 1;
            uVar11 = uVar11 + 0xc0;
            uVar9 = uStack00000024;
          } while (param_4 < uStack00000024);
        }
        in_stack_0000002c = in_stack_0000002c + 1;
      } while (in_stack_0000002c < uStack00000028);
    }
    FUN_004141c0(&param_1,*in_stack_00000040,in_stack_00000040);
  }
  _free(in_stack_00000040);
  return;
}


// ==== FUN_004ab430 @ 0x004ab430 ====

void FUN_004ab430(void *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *pvVar3;
  void *pvVar4;
  int in_ECX;
  undefined4 *puVar5;
  
  pvVar3 = param_1;
  FUN_004ac870(*(int *)((int)param_1 + 4),*(int *)((int)param_1 + 8),
               *(int *)((int)param_1 + 8) - *(int *)((int)param_1 + 4) >> 2);
  FUN_004ab950(&param_1,*(undefined4 *)((int)pvVar3 + 4),*(undefined4 *)((int)pvVar3 + 8));
  if (param_1 != *(void **)((int)pvVar3 + 8)) {
    pvVar4 = _memmove(param_1,*(void **)((int)pvVar3 + 8),0);
    *(void **)((int)pvVar3 + 8) = pvVar4;
  }
  puVar1 = *(undefined4 **)((int)pvVar3 + 8);
  uVar2 = *(undefined4 *)(in_ECX + 0xc0);
  for (puVar5 = *(undefined4 **)((int)pvVar3 + 4); puVar5 != puVar1; puVar5 = puVar5 + 1) {
    FUN_004aa6f0(uVar2,*puVar5);
  }
  return;
}


// ==== FUN_004ab4c0 @ 0x004ab4c0 ====

int FUN_004ab4c0(void)

{
  longlong lVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  
  uVar2 = 0;
  if (*(int *)(in_ECX + 0x8c) != 0) {
    uVar2 = 0;
    if ((*(int *)(in_ECX + 0x90) - *(int *)(in_ECX + 0x8c)) / 0x1c != 0) {
      uVar2 = FUN_004d5000();
      uVar2 = FUN_004d5040(uVar2);
      FUN_004aa6f0(uVar2);
      FUN_004abdf0();
      uVar2 = 0;
      if (*(int *)(in_ECX + 0x8c) != 0) {
        iVar3 = *(int *)(in_ECX + 0x90) - *(int *)(in_ECX + 0x8c);
        lVar1 = (longlong)iVar3 * -0x6db6db6d;
        uVar2 = (undefined4)lVar1;
        if (iVar3 / 0x1c != 0) {
          return (uint)(uint3)((ulonglong)lVar1 >> 8) << 8;
        }
      }
    }
  }
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}


// ==== FUN_004ab6e0 @ 0x004ab6e0 ====

void FUN_004ab6e0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc0);
  FUN_00414a70(*(undefined4 *)(*(int *)(iVar1 + 0x7c) + 4));
  *(int *)(*(int *)(iVar1 + 0x7c) + 4) = *(int *)(iVar1 + 0x7c);
  *(undefined4 *)(iVar1 + 0x80) = 0;
  *(undefined4 *)*(undefined4 *)(iVar1 + 0x7c) = *(undefined4 *)(iVar1 + 0x7c);
  *(int *)(*(int *)(iVar1 + 0x7c) + 8) = *(int *)(iVar1 + 0x7c);
  FUN_004cec00(*(undefined4 *)(in_ECX + 0xc0));
  return;
}


// ==== FUN_004ab730 @ 0x004ab730 ====

undefined4 FUN_004ab730(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 1;
  }
  iVar1 = *(int *)(in_ECX + 8) - *(int *)(in_ECX + 4);
  return CONCAT31((int3)(iVar1 >> 10),iVar1 >> 2 == 0);
}


// ==== FUN_004ab760 @ 0x004ab760 ====

int FUN_004ab760(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x30;
}


// ==== FUN_004ab780 @ 0x004ab780 ====

void FUN_004ab780(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  while (param_1 != param_2) {
    param_3[-3] = param_2[-3];
    param_3[-2] = param_2[-2];
    param_3[-1] = param_2[-1];
    param_2 = param_2 + -3;
    param_3 = param_3 + -3;
  }
  return;
}


// ==== FUN_004ab7c0 @ 0x004ab7c0 ====

undefined4 * FUN_004ab7c0(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar2[1] + 0x2d) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if (((uint)puVar2[3] < *param_1) ||
         (((uint)puVar2[3] <= *param_1 && ((uint)puVar2[4] < param_1[1])))) {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x2d) == '\0');
  }
  return puVar2;
}


// ==== FUN_004ab800 @ 0x004ab800 ====

void FUN_004ab800(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  while (param_1 != param_2) {
    puVar3 = param_1 + 0xc;
    puVar1 = param_3 + 0xc;
    puVar4 = param_1;
    puVar5 = param_3;
    for (iVar2 = 0xc; param_1 = puVar3, param_3 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}


// ==== FUN_004ab830 @ 0x004ab830 ====

void FUN_004ab830(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  while (param_1 != param_2) {
    puVar3 = param_1 + 9;
    puVar1 = param_3 + 9;
    puVar4 = param_1;
    puVar5 = param_3;
    for (iVar2 = 9; param_1 = puVar3, param_3 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}


// ==== FUN_004ab860 @ 0x004ab860 ====

void FUN_004ab860(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -9;
    param_3 = param_3 + -9;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_004ab890 @ 0x004ab890 ====

void FUN_004ab890(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 **ppuVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *local_8;
  undefined4 *local_4;
  
  puVar4 = param_3;
  iVar9 = (int)param_3 - param_1 >> 2;
  iVar11 = param_2 - param_1 >> 2;
  iVar7 = iVar11;
  param_2 = iVar9;
  while (iVar2 = iVar7, iVar2 != 0) {
    iVar7 = param_2 % iVar2;
    param_2 = iVar2;
  }
  if ((param_2 < iVar9) && (0 < param_2)) {
    puVar10 = (undefined4 *)(param_1 + param_2 * 4);
    do {
      uVar1 = *puVar10;
      if (puVar10 + iVar11 == puVar4) {
        puVar6 = &param_1;
      }
      else {
        param_3 = puVar10 + iVar11;
        puVar6 = &param_3;
      }
      puVar5 = (undefined4 *)*puVar6;
      puVar6 = puVar10;
      while (puVar3 = puVar5, puVar3 != puVar10) {
        *puVar6 = *puVar3;
        iVar7 = (int)puVar4 - (int)puVar3 >> 2;
        if (iVar11 < iVar7) {
          local_8 = puVar3 + iVar11;
          ppuVar8 = &local_8;
        }
        else {
          local_4 = (undefined4 *)(param_1 + (iVar7 * 0x3fffffff + iVar11) * 4);
          ppuVar8 = &local_4;
        }
        puVar6 = puVar3;
        puVar5 = *ppuVar8;
      }
      puVar10 = puVar10 + -1;
      param_2 = param_2 + -1;
      *puVar6 = uVar1;
    } while (param_2 != 0);
  }
  return;
}


// ==== FUN_004ab950 @ 0x004ab950 ====

void FUN_004ab950(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  
  if (param_2 != param_3) {
    while (piVar1 = param_2 + 1, piVar1 != param_3) {
      if (*param_2 == *piVar1) {
        for (piVar1 = param_2 + 2; piVar1 != param_3; piVar1 = piVar1 + 1) {
          if (*param_2 != *piVar1) {
            param_2 = param_2 + 1;
            *param_2 = *piVar1;
          }
        }
        *param_1 = param_2 + 1;
        return;
      }
      param_2 = piVar1;
    }
  }
  *param_1 = param_3;
  return;
}


// ==== FUN_004ab9a0 @ 0x004ab9a0 ====

void FUN_004ab9a0(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  iVar2 = (int)param_3 - (int)param_1 >> 2;
  if (iVar2 < 0x29) {
    uVar1 = *param_2;
    if (uVar1 < *param_1) {
      *param_2 = *param_1;
      *param_1 = uVar1;
    }
    uVar1 = *param_3;
    if (uVar1 < *param_2) {
      *param_3 = *param_2;
      *param_2 = uVar1;
    }
    uVar1 = *param_2;
    if (uVar1 < *param_1) {
      *param_2 = *param_1;
      *param_1 = uVar1;
      return;
    }
  }
  else {
    iVar2 = iVar2 + 1;
    iVar2 = (int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3;
    uVar1 = param_1[iVar2];
    if (uVar1 < *param_1) {
      param_1[iVar2] = *param_1;
      *param_1 = uVar1;
    }
    uVar1 = param_1[iVar2 * 2];
    if (uVar1 < param_1[iVar2]) {
      param_1[iVar2 * 2] = param_1[iVar2];
      param_1[iVar2] = uVar1;
    }
    uVar1 = param_1[iVar2];
    if (uVar1 < *param_1) {
      param_1[iVar2] = *param_1;
      *param_1 = uVar1;
    }
    uVar1 = *param_2;
    puVar3 = param_2 + -iVar2;
    if (uVar1 < *puVar3) {
      *param_2 = *puVar3;
      *puVar3 = uVar1;
    }
    uVar1 = param_2[iVar2];
    if (uVar1 < *param_2) {
      param_2[iVar2] = *param_2;
      *param_2 = uVar1;
    }
    uVar1 = *param_2;
    if (uVar1 < *puVar3) {
      *param_2 = *puVar3;
      *puVar3 = uVar1;
    }
    puVar3 = param_3 + -iVar2;
    puVar4 = param_3 + iVar2 * -2;
    uVar1 = *puVar3;
    if (uVar1 < *puVar4) {
      *puVar3 = *puVar4;
      *puVar4 = uVar1;
    }
    uVar1 = *param_3;
    if (uVar1 < *puVar3) {
      *param_3 = *puVar3;
      *puVar3 = uVar1;
    }
    uVar1 = *puVar3;
    if (uVar1 < *puVar4) {
      *puVar3 = *puVar4;
      *puVar4 = uVar1;
    }
    uVar1 = *param_2;
    if (uVar1 < param_1[iVar2]) {
      *param_2 = param_1[iVar2];
      param_1[iVar2] = uVar1;
    }
    uVar1 = *puVar3;
    if (uVar1 < *param_2) {
      *puVar3 = *param_2;
      *param_2 = uVar1;
    }
    uVar1 = *param_2;
    if (uVar1 < param_1[iVar2]) {
      *param_2 = param_1[iVar2];
      param_1[iVar2] = uVar1;
    }
  }
  return;
}


// ==== FUN_004abae0 @ 0x004abae0 ====

void FUN_004abae0(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2;
  while( true ) {
    iVar2 = iVar1 * 2 + 2;
    if (param_3 <= iVar2) break;
    if (*(uint *)(param_1 + iVar2 * 4) < *(uint *)(param_1 + -4 + iVar2 * 4)) {
      iVar2 = iVar1 * 2 + 1;
    }
    *(undefined4 *)(param_1 + iVar1 * 4) = *(undefined4 *)(param_1 + iVar2 * 4);
    iVar1 = iVar2;
  }
  if (iVar2 == param_3) {
    *(undefined4 *)(param_1 + iVar1 * 4) = *(undefined4 *)(param_1 + -4 + param_3 * 4);
    iVar1 = param_3 + -1;
  }
  while ((param_2 < iVar1 && (iVar2 = (iVar1 + -1) / 2, *(uint *)(param_1 + iVar2 * 4) < param_4)))
  {
    *(undefined4 *)(param_1 + iVar1 * 4) = *(undefined4 *)(param_1 + iVar2 * 4);
    iVar1 = iVar2;
  }
  *(uint *)(param_1 + iVar1 * 4) = param_4;
  return;
}


// ==== FUN_004abb60 @ 0x004abb60 ====

void FUN_004abb60(undefined4 *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar4 = param_2 + (((int)param_3 - (int)param_2 >> 2) - ((int)param_3 - (int)param_2 >> 0x1f) >>
                     1);
  FUN_004ab9a0(param_2,puVar4,param_3 + -1);
  puVar5 = puVar4 + 1;
  for (; ((param_2 < puVar4 && (*puVar4 <= puVar4[-1])) && (puVar4[-1] <= *puVar4));
      puVar4 = puVar4 + -1) {
  }
  puVar6 = puVar5;
  puVar2 = puVar4;
  if (puVar5 < param_3) {
    do {
      puVar6 = puVar5;
      if ((*puVar5 < *puVar4) || (*puVar4 < *puVar5)) break;
      puVar5 = puVar5 + 1;
      puVar6 = puVar5;
    } while (puVar5 < param_3);
  }
joined_r0x004abbc5:
  do {
    puVar3 = puVar4;
    if (param_3 <= puVar5) {
joined_r0x004abbed:
      for (; param_2 < puVar4; puVar4 = puVar4 + -1) {
        puVar3 = puVar3 + -1;
        if (*puVar2 <= *puVar3) {
          if (*puVar2 < *puVar3) break;
          uVar1 = puVar2[-1];
          puVar2 = puVar2 + -1;
          *puVar2 = *puVar3;
          *puVar3 = uVar1;
        }
      }
      if (puVar4 == param_2) {
        if (puVar5 == param_3) {
          param_1[1] = puVar6;
          *param_1 = puVar2;
          return;
        }
        if (puVar6 != puVar5) {
          uVar1 = *puVar2;
          *puVar2 = *puVar6;
          *puVar6 = uVar1;
        }
        uVar1 = *puVar2;
        *puVar2 = *puVar5;
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
        puVar2 = puVar2 + 1;
      }
      else {
        puVar4 = puVar4 + -1;
        if (puVar5 == param_3) {
          puVar2 = puVar2 + -1;
          if (puVar4 != puVar2) {
            uVar1 = *puVar4;
            *puVar4 = *puVar2;
            *puVar2 = uVar1;
          }
          uVar1 = *puVar2;
          *puVar2 = puVar6[-1];
          puVar6[-1] = uVar1;
          puVar6 = puVar6 + -1;
        }
        else {
          uVar1 = *puVar5;
          *puVar5 = *puVar4;
          puVar5 = puVar5 + 1;
          *puVar4 = uVar1;
        }
      }
      goto joined_r0x004abbc5;
    }
    if (*puVar5 <= *puVar2) {
      if (*puVar5 < *puVar2) goto joined_r0x004abbed;
      uVar1 = *puVar6;
      *puVar6 = *puVar5;
      puVar6 = puVar6 + 1;
      *puVar5 = uVar1;
    }
    puVar5 = puVar5 + 1;
  } while( true );
}


// ==== FUN_004abcb0 @ 0x004abcb0 ====

void FUN_004abcb0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_2 - param_1 >> 2;
  iVar2 = iVar3 - (param_2 - param_1 >> 0x1f) >> 1;
  while (0 < iVar2) {
    iVar1 = iVar2 * 4;
    iVar2 = iVar2 + -1;
    FUN_004abae0(param_1,iVar2,iVar3,*(undefined4 *)(param_1 + -4 + iVar1));
  }
  return;
}


// ==== FUN_004abcf0 @ 0x004abcf0 ====

void FUN_004abcf0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    (**(code **)*param_1)(0);
  }
  return;
}


// ==== FUN_004abd20 @ 0x004abd20 ====

void FUN_004abd20(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (puVar2 == (undefined4 *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 8);
  for (; puVar2 != puVar1; puVar2 = puVar2 + 7) {
    (**(code **)*puVar2)(0);
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004abd70 @ 0x004abd70 ====

void FUN_004abd70(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  
  puVar4 = param_1;
  if (param_1 != param_2) {
joined_r0x004abd84:
    while( true ) {
      puVar2 = puVar4;
      puVar4 = puVar2 + 1;
      if (puVar4 == param_2) break;
      uVar1 = *puVar4;
      if (*param_1 <= uVar1) goto LAB_004abda0;
      if ((param_1 != puVar4) && (puVar4 != puVar2 + 2)) {
        puVar5 = param_1;
        goto LAB_004abdc3;
      }
    }
  }
  return;
LAB_004abda0:
  puVar3 = puVar2;
  if (uVar1 < *puVar2) {
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + -1;
    } while (uVar1 < puVar5[-1]);
    if ((puVar5 != puVar4) && (puVar4 != puVar2 + 2)) {
LAB_004abdc3:
      FUN_004ab890(puVar5,puVar4,puVar2 + 2,0,0);
    }
  }
  goto joined_r0x004abd84;
}


// ==== FUN_004abde0 @ 0x004abde0 ====

void FUN_004abde0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (puVar2 == (undefined4 *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 8);
  for (; puVar2 != puVar1; puVar2 = puVar2 + 7) {
    (**(code **)*puVar2)(0);
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004abdf0 @ 0x004abdf0 ====

void FUN_004abdf0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  if ((*(int *)(in_ECX + 4) != 0) &&
     (puVar1 = *(undefined4 **)(in_ECX + 8), ((int)puVar1 - *(int *)(in_ECX + 4)) / 0x1c != 0)) {
    for (puVar2 = puVar1 + -7; puVar2 != puVar1; puVar2 = puVar2 + 7) {
      (**(code **)*puVar2)(0);
    }
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x1c;
  }
  return;
}


// ==== FUN_004abe40 @ 0x004abe40 ====

void FUN_004abe40(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  for (param_2 = param_2 - (int)param_1; 1 < param_2 >> 2; param_2 = param_2 + -4) {
    uVar1 = *(undefined4 *)((int)param_1 + param_2 + -4);
    *(undefined4 *)((int)param_1 + param_2 + -4) = *param_1;
    FUN_004abae0(param_1,0,param_2 + -4 >> 2,uVar1);
  }
  return;
}


// ==== FUN_004abe90 @ 0x004abe90 ====

void FUN_004abe90(void)

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
  puStack_8 = &LAB_0097f6a8;
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


// ==== FUN_004abf00 @ 0x004abf00 ====

void FUN_004abf00(int param_1,uint param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  uint extraout_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f5c0;
  local_10 = ExceptionList;
  local_20 = *param_3;
  local_1c = param_3[1];
  iVar3 = *(int *)(in_ECX + 4);
  local_18 = param_3[2];
  local_14 = (undefined1 *)((int)register0x00000010 + -0x2c);
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0xc;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x2c);
    if (0x15555555U - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_004abe90();
      uVar6 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    if (uVar6 < iVar2 + param_2) {
      if (0x15555555 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
      }
      if (uVar6 < iVar3 + param_2) {
        iVar3 = FUN_004a3750();
        uVar6 = iVar3 + param_2;
      }
      pvVar4 = operator_new(uVar6 * 0xc);
      local_8 = 0;
      iVar3 = FUN_0042eab0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_0042ea70(iVar3,param_2,&local_20);
      FUN_0042eab0(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 0xc);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0xc;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0xc + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 0xc);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0xc) < param_2) {
      FUN_0042eab0(param_1,iVar3,param_2 * 0xc + param_1);
      local_8 = 2;
      FUN_0042edf0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0xc,&local_20);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0xc;
      FUN_006d89e0(param_1,*(int *)(in_ECX + 8) + param_2 * -0xc,&local_20);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + param_2 * -0xc;
    uVar5 = FUN_0042eab0(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_004ab780(param_1,iVar2,iVar3,iVar2);
    FUN_006d89e0(param_1,param_2 * 0xc + param_1,&local_20);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004ac0b2 @ 0x004ac0b2 ====

void Catch_004ac0b2(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_004ac1b0 @ 0x004ac1b0 ====

undefined4 FUN_004ac1b0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  void *local_2c;
  undefined1 local_28;
  uint local_18;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f5d8;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0xe;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 8))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_004ac240 @ 0x004ac240 ====

void FUN_004ac240(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  uint extraout_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f5f0;
  local_10 = ExceptionList;
  iVar3 = *(int *)(in_ECX + 4);
  uVar1 = (param_3 - param_2) / 0x30;
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x30;
  }
  if (uVar1 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x30;
    }
    ExceptionList = &local_10;
    if (0x5555555U - iVar2 < uVar1) {
      ExceptionList = &local_10;
      FUN_004abe90();
      uVar6 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x30;
    }
    if (uVar6 < iVar2 + uVar1) {
      if (0x5555555 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x30;
      }
      if (uVar6 < iVar3 + uVar1) {
        iVar3 = FUN_004ab760();
        uVar6 = iVar3 + uVar1;
      }
      pvVar4 = operator_new(uVar6 * 0x30);
      local_8 = 0;
      uVar5 = FUN_004623b0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_004623b0(param_2,param_3,uVar5);
      FUN_004623b0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x30;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0x30 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((uVar1 + iVar3) * 0x30 + (int)pvVar4);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x30) < uVar1) {
      FUN_004623b0(param_1,iVar3,uVar1 * 0x30 + param_1);
      iVar3 = ((*(int *)(in_ECX + 8) - param_1) / 0x30) * 0x30 + param_2;
      local_8 = 2;
      FUN_004623b0(iVar3,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar1 * 0x30;
      FUN_004ab800(param_2,iVar3,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + uVar1 * -0x30;
    uVar5 = FUN_004623b0(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00462380(param_1,iVar2,iVar3);
    FUN_004ab800(param_2,param_3,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004ac3ef @ 0x004ac3ef ====

void Catch_004ac3ef(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004ac4f0 @ 0x004ac4f0 ====

void FUN_004ac4f0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  uint extraout_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f600;
  local_10 = ExceptionList;
  iVar3 = *(int *)(in_ECX + 4);
  uVar1 = (param_3 - param_2) / 0x24;
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x24;
  }
  if (uVar1 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
    }
    ExceptionList = &local_10;
    if (0x71c71c7U - iVar2 < uVar1) {
      ExceptionList = &local_10;
      FUN_004abe90();
      uVar6 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
    }
    if (uVar6 < iVar2 + uVar1) {
      if (0x71c71c7 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
      }
      if (uVar6 < iVar3 + uVar1) {
        iVar3 = FUN_0066e7e0();
        uVar6 = iVar3 + uVar1;
      }
      pvVar4 = operator_new(uVar6 * 0x24);
      local_8 = 0;
      uVar5 = FUN_004cf5b0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_004cf5b0(param_2,param_3,uVar5);
      FUN_004cf5b0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x24;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0x24 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (uVar1 + iVar3) * 0x24);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0x24) < uVar1) {
      FUN_004cf5b0(param_1,iVar3,uVar1 * 0x24 + param_1);
      iVar3 = param_2 + ((*(int *)(in_ECX + 8) - param_1) / 0x24) * 0x24;
      local_8 = 2;
      FUN_004cf5b0(iVar3,param_3,*(int *)(in_ECX + 8));
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar1 * 0x24;
      FUN_004ab830(param_2,iVar3,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + uVar1 * -0x24;
    uVar5 = FUN_004cf5b0(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_004ab860(param_1,iVar2,iVar3);
    FUN_004ab830(param_2,param_3,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004ac69e @ 0x004ac69e ====

void Catch_004ac69e(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004ac7a0 @ 0x004ac7a0 ====

void FUN_004ac7a0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int local_8;
  int local_4;
  
  iVar1 = param_2 - param_1 >> 2;
  if (0x20 < iVar1) {
    do {
      if (param_3 < 1) {
        if (0x20 < iVar1) {
          if (4 < (int)(param_2 - param_1 & 0xfffffffcU)) {
            FUN_004abcb0(param_1,param_2,0,0);
          }
          FUN_004abe40(param_1,param_2);
          return;
        }
        break;
      }
      FUN_004abb60(&local_8,param_1,param_2);
      iVar1 = local_4;
      param_3 = param_3 / 2 + (param_3 / 2) / 2;
      if ((int)(local_8 - param_1 & 0xfffffffcU) < (int)(param_2 - local_4 & 0xfffffffcU)) {
        FUN_004ac7a0(param_1,local_8,param_3);
        param_1 = iVar1;
      }
      else {
        FUN_004ac7a0(local_4,param_2,param_3);
        param_2 = local_8;
      }
      iVar1 = param_2 - param_1 >> 2;
    } while (0x20 < iVar1);
  }
  if (1 < iVar1) {
    FUN_004abd70(param_1,param_2);
  }
  return;
}


// ==== FUN_004ac870 @ 0x004ac870 ====

void FUN_004ac870(int param_1,int param_2,int param_3)

{
  int iVar1;
  int local_8;
  int local_4;
  
  iVar1 = param_2 - param_1 >> 2;
  if (0x20 < iVar1) {
    do {
      if (param_3 < 1) {
        if (0x20 < iVar1) {
          if (4 < (int)(param_2 - param_1 & 0xfffffffcU)) {
            FUN_004abcb0(param_1,param_2,0,0);
          }
          FUN_004abe40(param_1,param_2);
          return;
        }
        break;
      }
      FUN_004abb60(&local_8,param_1,param_2);
      iVar1 = local_4;
      param_3 = param_3 / 2 + (param_3 / 2) / 2;
      if ((int)(local_8 - param_1 & 0xfffffffcU) < (int)(param_2 - local_4 & 0xfffffffcU)) {
        FUN_004ac870(param_1,local_8,param_3);
        param_1 = iVar1;
      }
      else {
        FUN_004ac870(local_4,param_2,param_3);
        param_2 = local_8;
      }
      iVar1 = param_2 - param_1 >> 2;
    } while (0x20 < iVar1);
  }
  if (1 < iVar1) {
    FUN_004abd70(param_1,param_2);
  }
  return;
}


// ==== FUN_004ac940 @ 0x004ac940 ====

void FUN_004ac940(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (*(void **)(in_ECX + 0x60) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x60));
    return;
  }
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  if (*(void **)(in_ECX + 0x70) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x70) = 0;
    *(undefined4 *)(in_ECX + 0x74) = 0;
    *(undefined4 *)(in_ECX + 0x78) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x70));
  return;
}


// ==== FUN_004ac990 @ 0x004ac990 ====

void FUN_004ac990(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f610;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x5555555 < param_1) {
    ExceptionList = &local_10;
    FUN_004abe90();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0x30;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0x30);
    local_8 = 0;
    FUN_004623b0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x30 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004aca65 @ 0x004aca65 ====

void Catch_004aca65(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_004aca80 @ 0x004aca80 ====

void FUN_004aca80(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f620;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x71c71c7 < param_1) {
    ExceptionList = &local_10;
    FUN_004abe90();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0x24;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0x24);
    local_8 = 0;
    FUN_004cf5b0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x24 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004acb54 @ 0x004acb54 ====

void Catch_004acb54(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_004acb70 @ 0x004acb70 ====

void FUN_004acb70(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f630;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x15555555 < param_1) {
    ExceptionList = &local_10;
    FUN_004abe90();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0xc;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0xc);
    local_8 = 0;
    FUN_0042eab0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0xc + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004acc42 @ 0x004acc42 ====

void Catch_004acc42(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 8));
  return;
}


// ==== FUN_004acc60 @ 0x004acc60 ====

void FUN_004acc60(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0xc != 0) {
      iVar1 = (param_2 - iVar1) / 0xc;
      goto LAB_004acca3;
    }
  }
  iVar1 = 0;
LAB_004acca3:
  FUN_004abf00(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0xc;
  return;
}


// ==== FUN_004accd0 @ 0x004accd0 ====

/* WARNING: Removing unreachable block (ram,0x004acde0) */
/* WARNING: Removing unreachable block (ram,0x004acdf1) */
/* WARNING: Removing unreachable block (ram,0x004acdfa) */
/* WARNING: Removing unreachable block (ram,0x004acdfd) */
/* WARNING: Removing unreachable block (ram,0x004acded) */
/* WARNING: Removing unreachable block (ram,0x004ace0b) */
/* WARNING: Removing unreachable block (ram,0x004ace18) */
/* WARNING: Removing unreachable block (ram,0x004ace23) */
/* WARNING: Removing unreachable block (ram,0x004ace1f) */
/* WARNING: Removing unreachable block (ram,0x004ace13) */
/* WARNING: Removing unreachable block (ram,0x004ace26) */

void FUN_004accd0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097f6a8;
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
            goto LAB_004acef7;
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
LAB_004acef7:
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


// ==== FUN_004acfa0 @ 0x004acfa0 ====

void FUN_004acfa0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc) <= (uint)((*(int *)(in_ECX + 8) - iVar1) / 0xc)
     )) {
    FUN_004acc60(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0042ea70(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0xc;
  return;
}


// ==== FUN_004ad020 @ 0x004ad020 ====

void FUN_004ad020(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_004ad020(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004ad060 @ 0x004ad060 ====

undefined4 FUN_004ad060(void)

{
  return 0x10040012;
}


// ==== FUN_004ad070 @ 0x004ad070 ====

void FUN_004ad070(byte param_1)

{
  FUN_004ad0a0();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_004ad0a0 @ 0x004ad0a0 ====

void FUN_004ad0a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af7f0;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004ad0e0 @ 0x004ad0e0 ====

void FUN_004ad0e0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004ad020(piVar6[1]);
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
    FUN_004accd0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004ad1a0 @ 0x004ad1a0 ====

void FUN_004ad1a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
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
  FUN_00427460(param_4 + 4);
  *(undefined1 *)(in_ECX + 0xb) = param_5;
  *(undefined1 *)((int)in_ECX + 0x2d) = 0;
  return;
}


// ==== FUN_004ad1f0 @ 0x004ad1f0 ====

void * FUN_004ad1f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f651;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x30);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_004ad1a0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004ad262 @ 0x004ad262 ====

void Catch_004ad262(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004ad280 @ 0x004ad280 ====

void FUN_004ad280(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004ad0e0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004ad2b0 @ 0x004ad2b0 ====

void FUN_004ad2b0(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097f68c;
  pvStack_c = ExceptionList;
  local_4 = 3;
  if (*(void **)(in_ECX + 0x70) != (void *)0x0) {
    ExceptionList = &pvStack_c;
    _free(*(void **)(in_ECX + 0x70));
    return;
  }
  ExceptionList = &pvStack_c;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x78) = 0;
  if (*(void **)(in_ECX + 0x60) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x60));
    return;
  }
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  FUN_004abd20();
  if (*(int *)(in_ECX + 0x40) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x40),*(undefined4 *)(in_ECX + 0x44),in_ECX + 0x3c,in_ECX);
    _free(*(void **)(in_ECX + 0x40));
    return;
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  if (*(void **)(in_ECX + 0x30) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x30) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    local_4 = local_4 & 0xffffff00;
    FUN_004ad0e0(local_10,**(undefined4 **)(in_ECX + 0x24),*(undefined4 **)(in_ECX + 0x24));
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  _free(*(void **)(in_ECX + 0x30));
  return;
}


// ==== FUN_004ad3c0 @ 0x004ad3c0 ====

void FUN_004ad3c0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097f6a8;
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
  piVar4 = (int *)FUN_004ad1f0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004ad4b9:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_004ad4b9;
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


// ==== FUN_004ad5a0 @ 0x004ad5a0 ====

void FUN_004ad5a0(void)

{
  int iVar1;
  undefined1 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f702;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  local_4 = 0;
  iVar1 = FUN_004a37b0();
  *(int *)(in_ECX + 0x24) = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(int *)(*(int *)(in_ECX + 0x24) + 4) = *(int *)(in_ECX + 0x24);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(in_ECX + 0x24);
  *(int *)(*(int *)(in_ECX + 0x24) + 8) = *(int *)(in_ECX + 0x24);
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x78) = 0;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004ad650 @ 0x004ad650 ====

void FUN_004ad650(byte param_1)

{
  void *in_ECX;
  
  FUN_004a9e20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004ad670 @ 0x004ad670 ====

void FUN_004ad670(undefined4 *param_1,uint *param_2)

{
  bool bVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 local_4;
  
  puVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar1 = true;
  local_4 = 1;
  if (*(char *)((int)puVar4[1] + 0x2d) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if ((*param_2 < (uint)puVar4[3]) ||
         ((*param_2 <= (uint)puVar4[3] && (param_2[1] < (uint)puVar4[4])))) {
        puVar3 = (undefined4 *)*puVar4;
        bVar1 = true;
        local_4 = 1;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
        bVar1 = false;
        local_4 = 0;
      }
    } while (*(char *)((int)puVar3 + 0x2d) == '\0');
  }
  param_2 = puVar4;
  if (bVar1) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      local_4 = 1;
      goto LAB_004ad6c5;
    }
    FUN_0079c420();
  }
  if ((*puVar2 <= param_2[3]) && ((*puVar2 < param_2[3] || (puVar2[1] <= param_2[4])))) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_004ad6c5:
  puVar4 = (undefined4 *)FUN_004ad3c0(&param_2,local_4,puVar4,puVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_004ad750 @ 0x004ad750 ====

undefined4 FUN_004ad750(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  puVar2 = (undefined4 *)FUN_004adcc0();
  if (puVar2 != (undefined4 *)0x0) {
    FUN_00427850();
    cVar1 = (**(code **)(*in_ECX + 0x10))(puVar2);
    if (cVar1 != '\0') {
      return 1;
    }
    (**(code **)*puVar2)(1);
  }
  return 0;
}


// ==== FUN_004ad790 @ 0x004ad790 ====

void FUN_004ad790(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  int local_44 [2];
  uint local_3c;
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  void *local_24;
  void *local_1c;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f7a8;
  local_c = ExceptionList;
  uVar2 = *param_1 << 0x10 | param_1[1];
  ExceptionList = &local_c;
  param_1 = (int *)uVar2;
  FUN_0058b9b0(local_44,&param_1);
  if (local_44[0] == *(int *)(in_ECX + 0x40)) {
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_4 = 0;
    local_3c = uVar2;
    local_28 = uVar2;
    local_24 = (void *)uVar2;
    FUN_004adc20(local_38);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_004ae310(local_44,&local_28);
    if (local_1c != (void *)0x0) {
      _free(local_1c);
      return;
    }
    local_4 = 0xffffffff;
  }
  piVar3 = (int *)FUN_0058b9b0(local_44,&param_1);
  if (*piVar3 != *(int *)(in_ECX + 0x40)) {
    FUN_00428520(param_2);
    ExceptionList = local_c;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_find_it____m_mapZoneList_end___009af874,0x1e);
  local_4 = 2;
  FUN_00406880(&local_28);
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


// ==== FUN_004ad8e0 @ 0x004ad8e0 ====

void FUN_004ad8e0(undefined4 param_1)

{
  undefined1 auStack_6 [6];
  
  FUN_00427920(param_1);
  FUN_004ad790(auStack_6 + -6,param_1);
  return;
}


// ==== FUN_004ad950 @ 0x004ad950 ====

undefined4 FUN_004ad950(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint uStack_8;
  uint uStack_4;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 != 0xc) {
    return 0;
  }
  uVar4 = 0;
  if (param_1[3] != 0) {
    iVar2 = 0;
    do {
      iVar1 = param_1[5];
      if ((iVar1 == 0) || ((uint)((param_1[6] - iVar1) / 0x3c) <= uVar4)) {
        FUN_004adb80();
        break;
      }
      uStack_8 = (uint)(*(float *)(iVar1 + iVar2) * DAT_009af898);
      uStack_8 = ((int)uStack_8 < 0) - 1 & uStack_8;
      uStack_4 = (uint)(*(float *)(iVar1 + iVar2 + 4) * DAT_009af898);
      uStack_4 = uStack_4 & ((int)uStack_4 < 0) - 1;
      FUN_004ad790(&uStack_8,iVar1 + iVar2);
      uVar4 = uVar4 + 1;
      iVar2 = iVar2 + 0x3c;
    } while (uVar4 < (uint)param_1[3]);
  }
  uVar3 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  *(int **)(in_ECX + 0x20) = param_1;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  return 1;
}


// ==== FUN_004ada50 @ 0x004ada50 ====

void FUN_004ada50(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f7ba;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009af8a0;
  local_4 = 0;
  FUN_004ae3d0(local_10,*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10]);
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_004adad0 @ 0x004adad0 ====

void FUN_004adad0(undefined4 param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f7d7;
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
  local_4 = 0;
  *in_ECX = &PTR_FUN_009af8a0;
  iVar1 = FUN_00412d20();
  in_ECX[0x10] = iVar1;
  *(undefined1 *)(iVar1 + 0x25) = 1;
  *(undefined4 *)(in_ECX[0x10] + 4) = in_ECX[0x10];
  *(undefined4 *)in_ECX[0x10] = in_ECX[0x10];
  *(undefined4 *)(in_ECX[0x10] + 8) = in_ECX[0x10];
  in_ECX[0x11] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004adb80 @ 0x004adb80 ====

void FUN_004adb80(void)

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
  puStack_8 = &LAB_0097f778;
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


// ==== FUN_004adbf0 @ 0x004adbf0 ====

void FUN_004adbf0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0xc) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_004adc20 @ 0x004adc20 ====

void FUN_004adc20(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f710;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x3c;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_00413160(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_00427bf0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004adcac @ 0x004adcac ====

void Catch_004adcac(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004adcc0 @ 0x004adcc0 ====

undefined4 * FUN_004adcc0(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 *extraout_EAX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f73b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar2 = operator_new(0x20);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_0099d4fc;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
  }
  local_4 = 0xffffffff;
  if (puVar2 != (undefined4 *)0x0) {
    ExceptionList = local_c;
    return puVar2;
  }
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_10 = 0xf;
  FUN_00401740(&DAT_0099e358,2);
  local_4 = 2;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    puVar2 = (undefined4 *)(*pcVar1)();
    return puVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_004add70 @ 0x004add70 ====

undefined4 *
FUN_004add70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f761;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x28);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    puVar1[4] = param_4[1];
    FUN_004adc20(param_4 + 2);
    *(undefined1 *)(puVar1 + 9) = param_5;
    *(undefined1 *)((int)puVar1 + 0x25) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@004addfc @ 0x004addfc ====

void Catch_004addfc(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004ade20 @ 0x004ade20 ====

/* WARNING: Removing unreachable block (ram,0x004adf30) */
/* WARNING: Removing unreachable block (ram,0x004adf41) */
/* WARNING: Removing unreachable block (ram,0x004adf4a) */
/* WARNING: Removing unreachable block (ram,0x004adf4d) */
/* WARNING: Removing unreachable block (ram,0x004adf3d) */
/* WARNING: Removing unreachable block (ram,0x004adf5b) */
/* WARNING: Removing unreachable block (ram,0x004adf68) */
/* WARNING: Removing unreachable block (ram,0x004adf73) */
/* WARNING: Removing unreachable block (ram,0x004adf6f) */
/* WARNING: Removing unreachable block (ram,0x004adf63) */
/* WARNING: Removing unreachable block (ram,0x004adf76) */

void FUN_004ade20(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097f778;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x25) != '\0') {
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
  FUN_0051b6b0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x25) == '\0') {
    if (*(char *)(param_2[2] + 0x25) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x25) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x25) == '\0') {
      piVar3 = (int *)FUN_00412870(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x25) == '\0') {
      uVar4 = FUN_004ae4e0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[9] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[9] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[9] == '\0') {
            *(undefined1 *)(piVar5 + 9) = 1;
            *(undefined1 *)(piVar3 + 9) = 0;
            FUN_0058b7f0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x25) == '\0') {
            if ((*(char *)(*piVar5 + 0x24) == '\x01') && (*(char *)(piVar5[2] + 0x24) == '\x01'))
            goto LAB_004ae047;
            if (*(char *)(piVar5[2] + 0x24) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x24) = 1;
              *(undefined1 *)(piVar5 + 9) = 0;
              FUN_00412890(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 9) = (char)piVar3[9];
            *(undefined1 *)(piVar3 + 9) = 1;
            *(undefined1 *)(piVar5[2] + 0x24) = 1;
            FUN_0058b7f0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[9] == '\0') {
            *(undefined1 *)(piVar5 + 9) = 1;
            *(undefined1 *)(piVar3 + 9) = 0;
            FUN_00412890(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x25) == '\0') {
            if ((*(char *)(piVar5[2] + 0x24) != '\x01') || (*(char *)(*piVar5 + 0x24) != '\x01')) {
              if (*(char *)(*piVar5 + 0x24) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x24) = 1;
                *(undefined1 *)(piVar5 + 9) = 0;
                FUN_0058b7f0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 9) = (char)piVar3[9];
              *(undefined1 *)(piVar3 + 9) = 1;
              *(undefined1 *)(*piVar5 + 0x24) = 1;
              FUN_00412890(piVar3);
              break;
            }
LAB_004ae047:
            *(undefined1 *)(piVar5 + 9) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 9) = 1;
  }
  if ((void *)param_2[6] == (void *)0x0) {
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[6]);
  return;
}


// ==== FUN_004ae0f0 @ 0x004ae0f0 ====

void FUN_004ae0f0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x25) == '\0') {
    FUN_004ae0f0(*(undefined4 *)((int)param_1 + 8));
    FUN_00705010();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004ae130 @ 0x004ae130 ====

void FUN_004ae130(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097f778;
  local_c = ExceptionList;
  if (0xaaaaaa8 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004add70(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x24);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x24) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[9] == '\0') {
LAB_004ae229:
        *(undefined1 *)(*piVar5 + 0x24) = 1;
        *(undefined1 *)(piVar6 + 9) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x24) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0058b7f0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x24) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x24) = 0;
        FUN_00412890(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[9] == '\0') goto LAB_004ae229;
      if (piVar7 == (int *)*piVar2) {
        FUN_00412890(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x24) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x24) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x25) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x24);
  } while( true );
}


// ==== FUN_004ae310 @ 0x004ae310 ====

void FUN_004ae310(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x25) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x25) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_004ae130(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058aca0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004ae130(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004ae3d0 @ 0x004ae3d0 ====

void FUN_004ae3d0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004ae0f0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x25) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x25) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x25);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x25);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x25);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x25);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004ade20(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004ae490 @ 0x004ae490 ====

void FUN_004ae490(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004ae3d0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004ae4c0 @ 0x004ae4c0 ====

void FUN_004ae4c0(byte param_1)

{
  void *in_ECX;
  
  FUN_004ada50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004ae4e0 @ 0x004ae4e0 ====

void FUN_004ae4e0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x25) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x25) == '\0');
  }
  return;
}


// ==== FUN_004ae510 @ 0x004ae510 ====

undefined4 FUN_004ae510(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  puVar2 = (undefined4 *)FUN_004aea70();
  if (puVar2 != (undefined4 *)0x0) {
    FUN_00428870();
    cVar1 = (**(code **)(*in_ECX + 0x10))(puVar2);
    if (cVar1 != '\0') {
      return 1;
    }
    (**(code **)*puVar2)(1);
  }
  return 0;
}


// ==== FUN_004ae550 @ 0x004ae550 ====

void FUN_004ae550(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  int local_44 [2];
  uint local_3c;
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f888;
  local_c = ExceptionList;
  uVar2 = *param_1 << 0x10 | param_1[1];
  ExceptionList = &local_c;
  param_1 = (int *)uVar2;
  FUN_0058b9b0(local_44,&param_1);
  if (local_44[0] == *(int *)(in_ECX + 0x40)) {
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_4 = 0;
    local_3c = uVar2;
    local_28 = uVar2;
    local_24 = (void *)uVar2;
    FUN_004ae9b0(local_38);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_004aedc0(local_44,&local_28);
    FUN_00413810();
    local_4 = 0xffffffff;
    FUN_00413810();
  }
  piVar3 = (int *)FUN_0058b9b0(local_44,&param_1);
  if (*piVar3 != *(int *)(in_ECX + 0x40)) {
    FUN_00429750(param_2);
    ExceptionList = local_c;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_find_it____m_mapZoneList_end___009af910,0x1e);
  local_4 = 2;
  FUN_00406880(&local_28);
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


// ==== FUN_004ae6a0 @ 0x004ae6a0 ====

void FUN_004ae6a0(undefined4 param_1)

{
  undefined1 auStack_6 [6];
  
  FUN_004288b0(param_1);
  FUN_004ae550(auStack_6 + -6,param_1);
  return;
}


// ==== FUN_004ae710 @ 0x004ae710 ====

undefined4 FUN_004ae710(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint uStack_8;
  uint uStack_4;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 != 8) {
    return 0;
  }
  uVar4 = 0;
  if (param_1[3] != 0) {
    iVar2 = 0;
    do {
      iVar1 = param_1[5];
      if ((iVar1 == 0) || ((uint)((param_1[6] - iVar1) / 0x3c) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_004ae940();
      }
      uStack_8 = (uint)(*(float *)(iVar1 + iVar2) * DAT_009af898);
      uStack_8 = ((int)uStack_8 < 0) - 1 & uStack_8;
      uStack_4 = (uint)(*(float *)(iVar1 + iVar2 + 4) * DAT_009af898);
      uStack_4 = uStack_4 & ((int)uStack_4 < 0) - 1;
      FUN_004ae550(&uStack_8,iVar1 + iVar2);
      uVar4 = uVar4 + 1;
      iVar2 = iVar2 + 0x3c;
    } while (uVar4 < (uint)param_1[3]);
  }
  uVar3 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  *(int **)(in_ECX + 0x20) = param_1;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  return 1;
}


// ==== FUN_004ae810 @ 0x004ae810 ====

void FUN_004ae810(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f89a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009af938;
  local_4 = 0;
  FUN_004af1c0(local_10,*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10]);
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_004ae890 @ 0x004ae890 ====

void FUN_004ae890(undefined4 param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f8b7;
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
  local_4 = 0;
  *in_ECX = &PTR_FUN_009af938;
  iVar1 = FUN_00412d20();
  in_ECX[0x10] = iVar1;
  *(undefined1 *)(iVar1 + 0x25) = 1;
  *(undefined4 *)(in_ECX[0x10] + 4) = in_ECX[0x10];
  *(undefined4 *)in_ECX[0x10] = in_ECX[0x10];
  *(undefined4 *)(in_ECX[0x10] + 8) = in_ECX[0x10];
  in_ECX[0x11] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004ae940 @ 0x004ae940 ====

void FUN_004ae940(void)

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
  puStack_8 = &LAB_0097f858;
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


// ==== FUN_004ae9b0 @ 0x004ae9b0 ====

void FUN_004ae9b0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f7f0;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x3c;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_00413160(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_00428cd0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004aea3c @ 0x004aea3c ====

void Catch_004aea3c(void)

{
  FUN_00413810();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004aea50 @ 0x004aea50 ====

void FUN_004aea50(void)

{
  FUN_00413810();
  return;
}


// ==== FUN_004aea60 @ 0x004aea60 ====

void FUN_004aea60(void)

{
  FUN_00413810();
  return;
}


// ==== FUN_004aea70 @ 0x004aea70 ====

undefined4 * FUN_004aea70(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 *extraout_EAX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f81b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar2 = operator_new(0x20);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_0099d57c;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
  }
  local_4 = 0xffffffff;
  if (puVar2 != (undefined4 *)0x0) {
    ExceptionList = local_c;
    return puVar2;
  }
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_10 = 0xf;
  FUN_00401740(&DAT_0099e358,2);
  local_4 = 2;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    puVar2 = (undefined4 *)(*pcVar1)();
    return puVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_004aeb20 @ 0x004aeb20 ====

void FUN_004aeb20(void)

{
  FUN_00413810();
  return;
}


// ==== FUN_004aeb30 @ 0x004aeb30 ====

undefined4 *
FUN_004aeb30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f841;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x28);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    puVar1[4] = param_4[1];
    FUN_004ae9b0(param_4 + 2);
    *(undefined1 *)(puVar1 + 9) = param_5;
    *(undefined1 *)((int)puVar1 + 0x25) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@004aebbc @ 0x004aebbc ====

void Catch_004aebbc(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004aebe0 @ 0x004aebe0 ====

void FUN_004aebe0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097f858;
  local_c = ExceptionList;
  if (0xaaaaaa8 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004aeb30(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x24);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x24) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[9] == '\0') {
LAB_004aecd9:
        *(undefined1 *)(*piVar5 + 0x24) = 1;
        *(undefined1 *)(piVar6 + 9) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x24) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0058b7f0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x24) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x24) = 0;
        FUN_00412890(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[9] == '\0') goto LAB_004aecd9;
      if (piVar7 == (int *)*piVar2) {
        FUN_00412890(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x24) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x24) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x25) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x24);
  } while( true );
}


// ==== FUN_004aedc0 @ 0x004aedc0 ====

void FUN_004aedc0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x25) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x25) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_004aebe0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058aca0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004aebe0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004aee80 @ 0x004aee80 ====

/* WARNING: Removing unreachable block (ram,0x004aef97) */
/* WARNING: Removing unreachable block (ram,0x004aefa8) */
/* WARNING: Removing unreachable block (ram,0x004aefb1) */
/* WARNING: Removing unreachable block (ram,0x004aefb4) */
/* WARNING: Removing unreachable block (ram,0x004aefa4) */
/* WARNING: Removing unreachable block (ram,0x004aefc2) */
/* WARNING: Removing unreachable block (ram,0x004aefd3) */
/* WARNING: Removing unreachable block (ram,0x004aefde) */
/* WARNING: Removing unreachable block (ram,0x004aefda) */
/* WARNING: Removing unreachable block (ram,0x004aefce) */
/* WARNING: Removing unreachable block (ram,0x004aefe1) */

void FUN_004aee80(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f858;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x25) != '\0') {
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
  FUN_0051b6b0();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x25) == '\0') {
    if (*(char *)(param_2[2] + 0x25) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x25) == '\0') {
    piVar7[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar7;
  }
  else if ((int *)*piVar5 == param_2) {
    *piVar5 = (int)piVar7;
  }
  else {
    piVar5[2] = (int)piVar7;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar7 + 0x25) == '\0') {
      piVar3 = (int *)FUN_00412870(piVar7);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar6 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar6 + 8) == param_2) {
    if (*(char *)((int)piVar7 + 0x25) == '\0') {
      uVar4 = FUN_004ae4e0(piVar7);
      *(undefined4 *)(iVar6 + 8) = uVar4;
    }
    else {
      *(int **)(iVar6 + 8) = piVar5;
    }
  }
  if ((char)param_2[9] == '\x01') {
    if (piVar7 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar7[9] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar7 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[9] == '\0') {
            *(undefined1 *)(piVar5 + 9) = 1;
            *(undefined1 *)(piVar3 + 9) = 0;
            FUN_0058b7f0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x25) == '\0') {
            if ((*(char *)(*piVar5 + 0x24) == '\x01') && (*(char *)(piVar5[2] + 0x24) == '\x01'))
            goto LAB_004af0b5;
            if (*(char *)(piVar5[2] + 0x24) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x24) = 1;
              *(undefined1 *)(piVar5 + 9) = 0;
              FUN_00412890(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 9) = (char)piVar3[9];
            *(undefined1 *)(piVar3 + 9) = 1;
            *(undefined1 *)(piVar5[2] + 0x24) = 1;
            FUN_0058b7f0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[9] == '\0') {
            *(undefined1 *)(piVar5 + 9) = 1;
            *(undefined1 *)(piVar3 + 9) = 0;
            FUN_00412890(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x25) == '\0') {
            if ((*(char *)(piVar5[2] + 0x24) != '\x01') || (*(char *)(*piVar5 + 0x24) != '\x01')) {
              if (*(char *)(*piVar5 + 0x24) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x24) = 1;
                *(undefined1 *)(piVar5 + 9) = 0;
                FUN_0058b7f0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 9) = (char)piVar3[9];
              *(undefined1 *)(piVar3 + 9) = 1;
              *(undefined1 *)(*piVar5 + 0x24) = 1;
              FUN_00412890(piVar3);
              break;
            }
LAB_004af0b5:
            *(undefined1 *)(piVar5 + 9) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar7 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar7 + 9) = 1;
  }
  iVar6 = param_2[6];
  if (iVar6 == 0) {
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
    _free(param_2);
    return;
  }
  iVar2 = param_2[7];
  for (; iVar6 != iVar2; iVar6 = iVar6 + 0x3c) {
    FUN_00401330(1,0);
  }
  _free((void *)param_2[6]);
  return;
}


// ==== FUN_004af180 @ 0x004af180 ====

void FUN_004af180(void *param_1)

{
  if (*(char *)((int)param_1 + 0x25) == '\0') {
    FUN_004af180(*(undefined4 *)((int)param_1 + 8));
    FUN_004aeb20();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004af1c0 @ 0x004af1c0 ====

void FUN_004af1c0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004af180(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x25) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x25) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x25);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x25);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x25);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x25);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004aee80(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004af280 @ 0x004af280 ====

void FUN_004af280(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004af1c0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004af2b0 @ 0x004af2b0 ====

void FUN_004af2b0(byte param_1)

{
  void *in_ECX;
  
  FUN_004ae810();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004af310 @ 0x004af310 ====

void FUN_004af310(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af9b0;
  if ((void *)in_ECX[0x12] == (void *)0x0) {
    in_ECX[0x12] = 0;
    in_ECX[0x13] = 0;
    in_ECX[0x14] = 0;
    FUN_0049da30();
    return;
  }
  _free((void *)in_ECX[0x12]);
  return;
}


// ==== FUN_004af350 @ 0x004af350 ====

undefined4 FUN_004af350(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  uVar2 = *(int *)(in_ECX + 0x3c) * param_2 + param_1;
  iVar1 = *(int *)(in_ECX + 0x48);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x4c) - iVar1 >> 1) <= uVar2)) {
                    /* WARNING: Subroutine does not return */
    FUN_00426d40();
  }
  return CONCAT22((short)(uVar2 >> 0x10),*(undefined2 *)(iVar1 + uVar2 * 2));
}


// ==== FUN_004af3f0 @ 0x004af3f0 ====

void FUN_004af3f0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f8e3;
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
  *in_ECX = &PTR_FUN_009af9b0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  local_4 = 1;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004af480 @ 0x004af480 ====

undefined4 FUN_004af480(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0xf) {
    *(int *)(in_ECX + 0x3c) = param_1[3];
    *(int *)(in_ECX + 0x40) = param_1[4];
    FUN_004394e0(param_1 + 5);
    uVar2 = (**(code **)(*param_1 + 0x10))();
    *(undefined4 *)(in_ECX + 0x28) = uVar2;
    *(int **)(in_ECX + 0x20) = param_1;
    *(int **)(in_ECX + 0x54) = param_1;
    *(undefined4 *)(in_ECX + 0x34) = 2;
    return 1;
  }
  return 0;
}


// ==== FUN_004af4e0 @ 0x004af4e0 ====

undefined4 FUN_004af4e0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  puVar2 = (undefined4 *)FUN_004af550();
  FUN_00426be0(param_1,param_2);
  cVar1 = (**(code **)(*in_ECX + 0x10))(puVar2);
  if (cVar1 != '\0') {
    return 1;
  }
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  return 0;
}


// ==== FUN_004af530 @ 0x004af530 ====

void FUN_004af530(byte param_1)

{
  void *in_ECX;
  
  FUN_004af310();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004af550 @ 0x004af550 ====

undefined4 * FUN_004af550(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 *extraout_EAX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f90b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar2 = operator_new(0x24);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_0099d4dc;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[8] = 0;
  }
  local_4 = 0xffffffff;
  if (puVar2 != (undefined4 *)0x0) {
    ExceptionList = local_c;
    return puVar2;
  }
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_10 = 0xf;
  FUN_00401740(&DAT_0099e358,2);
  local_4 = 2;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    puVar2 = (undefined4 *)(*pcVar1)();
    return puVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_004af600 @ 0x004af600 ====

void FUN_004af600(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x48) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x48))(1);
    *(undefined4 *)(in_ECX + 0x48) = 0;
  }
  uVar1 = FUN_0084c400();
  *(undefined4 *)(in_ECX + 0x48) = uVar1;
  return;
}


// ==== FUN_004af630 @ 0x004af630 ====

void FUN_004af630(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x48) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x48))(1);
  }
  *(undefined4 *)(in_ECX + 0x48) = 0;
  return;
}


// ==== FUN_004af650 @ 0x004af650 ====

undefined4 FUN_004af650(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 != 4) {
    return 0;
  }
  uVar3 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  *(int **)(in_ECX + 0x20) = param_1;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  uVar1 = (**(code **)(*param_1 + 0x14))();
  *(undefined1 *)(in_ECX + 0x4c) = uVar1;
  if (*(undefined4 **)(in_ECX + 0x48) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x48))(1);
    *(undefined4 *)(in_ECX + 0x48) = 0;
  }
  uVar3 = FUN_0084c400();
  *(undefined4 *)(in_ECX + 0x48) = uVar3;
  if (*(undefined4 **)(in_ECX + 0x20) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x20))(1);
  }
  *(undefined4 *)(in_ECX + 0x20) = 0;
  return 1;
}


// ==== FUN_004af6c0 @ 0x004af6c0 ====

undefined4 FUN_004af6c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x20) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x10);
}


// ==== FUN_004af6d0 @ 0x004af6d0 ====

void FUN_004af6d0(void)

{
  undefined4 uVar1;
  int *in_ECX;
  void *local_2c;
  undefined1 local_28;
  uint local_18;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097f928;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(in_ECX + 1,0,0xffffffff);
  local_10 = (void *)0x0;
  local_4 = 0;
  uVar1 = FUN_004a8060(&local_2c);
  (**(code **)(*in_ECX + 0x10))(uVar1);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_004af750 @ 0x004af750 ====

int FUN_004af750(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x48);
  if (iVar1 == 0) {
    FUN_004af6d0();
    iVar1 = *(int *)(in_ECX + 0x48);
  }
  return iVar1;
}


// ==== FUN_004af770 @ 0x004af770 ====

void FUN_004af770(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f942;
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
  local_4 = 0;
  *in_ECX = &PTR_FUN_009afa68;
  in_ECX[0x12] = 0;
  FUN_00401660(param_1,0,0xffffffff);
  iVar1 = FUN_00405850(&DAT_009afa20,0,3);
  *(bool *)((int)in_ECX + 0x4d) = iVar1 == 0;
  uVar2 = FUN_004022a0(local_28,s__Resource__Texture_Created_009afa24,in_ECX + 1);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00403e50(uVar2);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_004af840 @ 0x004af840 ====

void FUN_004af840(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097f95c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009afa68;
  local_4 = 0;
  if ((undefined4 *)in_ECX[0x12] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x12])(1);
  }
  in_ECX[0x12] = 0;
  uVar1 = FUN_004022a0(local_28,s__Resource__Texture_Removed__009afa40,in_ECX + 1);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00403e50(uVar1);
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    local_4 = 0xffffffff;
    FUN_0049da30();
    ExceptionList = pvStack_c;
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_004af8f0 @ 0x004af8f0 ====

void FUN_004af8f0(byte param_1)

{
  void *in_ECX;
  
  FUN_004af840();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004af910 @ 0x004af910 ====

void FUN_004af910(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x1d);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x1d);
  }
  return;
}


// ==== FUN_004af930 @ 0x004af930 ====

void FUN_004af930(void)

{
  undefined4 *puVar1;
  
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
  return;
}


// ==== FUN_004af9b0 @ 0x004af9b0 ====

/* WARNING: Removing unreachable block (ram,0x004afac0) */
/* WARNING: Removing unreachable block (ram,0x004afad1) */
/* WARNING: Removing unreachable block (ram,0x004afada) */
/* WARNING: Removing unreachable block (ram,0x004afadd) */
/* WARNING: Removing unreachable block (ram,0x004afacd) */
/* WARNING: Removing unreachable block (ram,0x004afaeb) */
/* WARNING: Removing unreachable block (ram,0x004afaf8) */
/* WARNING: Removing unreachable block (ram,0x004afb03) */
/* WARNING: Removing unreachable block (ram,0x004afaff) */
/* WARNING: Removing unreachable block (ram,0x004afaf3) */
/* WARNING: Removing unreachable block (ram,0x004afb06) */

void FUN_004af9b0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097f9d8;
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
            goto LAB_004afbd7;
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
LAB_004afbd7:
            *(undefined1 *)(piVar5 + 0xb) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xb) = 1;
  }
  if ((uint)param_2[10] < 0x10) {
    param_2[10] = 0xf;
    param_2[9] = 0;
    *(undefined1 *)(param_2 + 5) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_004afc80 @ 0x004afc80 ====

void FUN_004afc80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  *(undefined2 *)(in_ECX + 3) = *param_4;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  FUN_00401660(param_4 + 2,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0xb) = param_5;
  *(undefined1 *)((int)in_ECX + 0x2d) = 0;
  return;
}


// ==== FUN_004afce0 @ 0x004afce0 ====

void FUN_004afce0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_004afce0(*(undefined4 *)((int)param_1 + 8));
    FUN_00792590();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004afd20 @ 0x004afd20 ====

void * FUN_004afd20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f981;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x30);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_004afc80(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004afd92 @ 0x004afd92 ====

void Catch_004afd92(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004afdb0 @ 0x004afdb0 ====

undefined4 * FUN_004afdb0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097f990;
  local_10 = ExceptionList;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    ExceptionList = &local_10;
    puVar1 = (undefined4 *)
             FUN_004afd20(local_18,param_2,local_18,param_1 + 3,*(undefined1 *)(param_1 + 0xb));
    if (*(char *)((int)local_18 + 0x2d) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_004afdb0(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_004afdb0(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}


// ==== Catch@004afe41 @ 0x004afe41 ====

void Catch_004afe41(void)

{
  int unaff_EBP;
  
  FUN_004afce0(*(undefined4 *)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


