// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x710000-0x71ffff

// ==== FUN_00710390 @ 0x00710390 ====

undefined4 FUN_00710390(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0xf020004) {
    if (uVar1 == 0xf020003) {
      FUN_0070d860(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 < 0x5280019) {
      if (uVar1 == 0x5280018) {
        FUN_0070e710(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 < 0x5280012) {
        if (uVar1 == 0x5280011) {
          FUN_0070f890(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar1 < 0x5280010) {
          if (uVar1 == 0x528000f) {
            FUN_0070f300(*(undefined4 *)(param_1 + 0xc));
            return 1;
          }
          if (uVar1 == 0x5270005) {
            FUN_0070cd20(*(undefined4 *)(param_1 + 0xc));
            return 1;
          }
          if (uVar1 == 0x5280004) {
            FUN_0070dcc0(*(undefined4 *)(param_1 + 0xc));
            return 1;
          }
        }
        else if (uVar1 == 0x5280010) {
          FUN_0070f4a0(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
      }
      else {
        if (uVar1 == 0x5280013) {
          FUN_0070ccc0(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar1 == 0x5280014) {
          FUN_0070d480(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar1 == 0x5280016) {
          FUN_0070cd00(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
      }
    }
    else if (uVar1 < 0x5280021) {
      if (uVar1 == 0x5280020) {
        return 1;
      }
      if (uVar1 == 0x5280019) {
        FUN_0070fb90(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x528001a) {
        FUN_0070d280(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x528001b) {
        FUN_0070cc90(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
    else {
      if (uVar1 == 0xf000004) {
        FUN_0070cea0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0xf000005) {
        FUN_0070cef0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0xf020001) {
        FUN_0070ebc0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
  }
  else if (uVar1 < 0x12020001) {
    if (uVar1 == 0x12020000) {
      FUN_0070e400(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 < 0x12000001) {
      if (uVar1 == 0x12000000) {
        FUN_0070cd70(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0xf020005) {
        FUN_0070e130(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0xf020013) {
        FUN_0070d690(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0xf030008) {
        FUN_0070d080(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
    else {
      if (uVar1 == 0x12000001) {
        FUN_0070cdf0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x12000002) {
        FUN_0070ce30(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x12000003) {
        FUN_0070cf60(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
  }
  else {
    switch(uVar1 + 0xedfdffff) {
    case 0:
      FUN_0070e4d0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 1:
      FUN_0070cfd0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 2:
      FUN_0070f150(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 3:
      FUN_0070e630(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 4:
      FUN_0070fce0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 5:
      FUN_0070ff70(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 6:
      FUN_0070d140(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007106f0 @ 0x007106f0 ====

undefined4 FUN_007106f0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00710390(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00710720 @ 0x00710720 ====

undefined4 FUN_00710720(int param_1)

{
  char *in_ECX;
  uint uVar1;
  
  uVar1 = 0;
  param_1 = param_1 - (int)in_ECX;
  while( true ) {
    if (*in_ECX != in_ECX[param_1]) {
      return 1;
    }
    if (*in_ECX == '\0') break;
    uVar1 = uVar1 + 1;
    in_ECX = in_ECX + 1;
    if (0x20 < uVar1) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00710760 @ 0x00710760 ====

void FUN_00710760(byte param_1)

{
  void *in_ECX;
  
  FUN_0070cfb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00710780 @ 0x00710780 ====

void FUN_00710780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eb664;
  return;
}


// ==== FUN_00710790 @ 0x00710790 ====

void FUN_00710790(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eb664;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007107b0 @ 0x007107b0 ====

void FUN_007107b0(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x14) = param_1 * 1000;
  *(int *)(in_ECX + 0xc) = param_1 * 1000;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  return;
}


// ==== FUN_00710860 @ 0x00710860 ====

void FUN_00710860(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  puVar3 = operator_new(0x1c);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009eb844;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  puVar3[1] = *(undefined4 *)(param_1 + 0x1c);
  puVar3[2] = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  puVar3[3] = *(undefined4 *)(param_1 + 0x24);
  puVar3[4] = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x28);
  puVar3[5] = *(undefined4 *)(param_1 + 0x2c);
  puVar3[6] = uVar1;
  FUN_00797a20(puVar3);
  uVar2 = *(uint *)(in_ECX + 4);
  if ((uVar2 == 0) || ((uVar2 & 0x20) == 0)) {
    *(uint *)(in_ECX + 4) = uVar2 | 0x20;
  }
  return;
}


// ==== FUN_007108d0 @ 0x007108d0 ====

void FUN_007108d0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 4) != 0) && ((*(uint *)(in_ECX + 4) & 0x20) != 0)) {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009eb858;
    }
    FUN_00797a20(puVar2);
    uVar1 = *(uint *)(in_ECX + 4);
    if ((uVar1 != 0) && ((uVar1 & 0x20) != 0)) {
      *(uint *)(in_ECX + 4) = uVar1 & 0xffffffdf;
    }
  }
  return;
}


// ==== FUN_00710920 @ 0x00710920 ====

void FUN_00710920(void)

{
  undefined4 *puVar1;
  int *piVar2;
  uint *puVar3;
  int in_ECX;
  uint uVar4;
  short sVar5;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009eb704;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  if (piVar2 != (int *)0x0) {
    puVar3 = (uint *)(**(code **)(*piVar2 + 0x18))();
    uVar4 = *puVar3;
    sVar5 = (short)(uVar4 / 100000000);
    *(short *)(puVar1 + 1) = sVar5;
    if (sVar5 != 0) {
      uVar4 = uVar4 % 100000000;
    }
    sVar5 = (short)(uVar4 / 1000000);
    *(short *)((int)puVar1 + 6) = sVar5;
    if (sVar5 != 0) {
      uVar4 = uVar4 % 1000000;
    }
    *(short *)(puVar1 + 2) = (short)(uVar4 / 10000);
    FUN_00797a20(puVar1);
    uVar4 = *(uint *)(in_ECX + 4);
    if ((uVar4 == 0) || ((uVar4 & 1) == 0)) {
      *(uint *)(in_ECX + 4) = uVar4 | 1;
    }
  }
  return;
}


// ==== FUN_007109c0 @ 0x007109c0 ====

void FUN_007109c0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  if ((in_ECX[1] != 0) && ((in_ECX[1] & 1U) != 0)) {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009eb72c;
    }
    FUN_00797a20(puVar2);
    (**(code **)(*in_ECX + 0x84))();
    uVar1 = in_ECX[1];
    if ((uVar1 != 0) && ((uVar1 & 1) != 0)) {
      in_ECX[1] = uVar1 & 0xfffffffe;
    }
  }
  return;
}


// ==== FUN_00710a10 @ 0x00710a10 ====

void FUN_00710a10(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009eb740;
  }
  FUN_00797a20(puVar2);
  uVar1 = *(uint *)(in_ECX + 4);
  if ((uVar1 == 0) || ((uVar1 & 2) == 0)) {
    *(uint *)(in_ECX + 4) = uVar1 | 2;
  }
  return;
}


// ==== FUN_00710a50 @ 0x00710a50 ====

void FUN_00710a50(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 4) != 0) && ((*(uint *)(in_ECX + 4) & 2) != 0)) {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009eb754;
    }
    FUN_00797a20(puVar2);
    uVar1 = *(uint *)(in_ECX + 4);
    if ((uVar1 != 0) && ((uVar1 & 2) != 0)) {
      *(uint *)(in_ECX + 4) = uVar1 & 0xfffffffd;
    }
  }
  return;
}


// ==== FUN_00710aa0 @ 0x00710aa0 ====

void FUN_00710aa0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = operator_new(0xc);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009eb718;
  }
  *(undefined2 *)(puVar2 + 1) = 0x7d6;
  *(undefined2 *)((int)puVar2 + 6) = 5;
  *(undefined2 *)(puVar2 + 2) = 0x1f;
  *(undefined2 *)((int)puVar2 + 10) = 0xc;
  FUN_00797a20(puVar2);
  uVar1 = *(uint *)(in_ECX + 4);
  if ((uVar1 == 0) || ((uVar1 & 4) == 0)) {
    *(uint *)(in_ECX + 4) = uVar1 | 4;
  }
  return;
}


// ==== FUN_00710af0 @ 0x00710af0 ====

void FUN_00710af0(undefined4 param_1,undefined1 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = operator_new(0xc);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009eb7f4;
  }
  puVar2[1] = param_1;
  *(undefined1 *)(puVar2 + 2) = param_2;
  FUN_00797a20(puVar2);
  uVar1 = *(uint *)(in_ECX + 4);
  if ((uVar1 == 0) || ((uVar1 & 8) == 0)) {
    *(uint *)(in_ECX + 4) = uVar1 | 8;
  }
  return;
}


// ==== FUN_00710b40 @ 0x00710b40 ====

void FUN_00710b40(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 4) != 0) && ((*(uint *)(in_ECX + 4) & 8) != 0)) {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009eb808;
    }
    FUN_00797a20(puVar2);
    uVar1 = *(uint *)(in_ECX + 4);
    if ((uVar1 != 0) && ((uVar1 & 8) != 0)) {
      *(uint *)(in_ECX + 4) = uVar1 & 0xfffffff7;
    }
  }
  return;
}


// ==== FUN_00710b90 @ 0x00710b90 ====

void FUN_00710b90(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 4) != 0) && ((*(uint *)(in_ECX + 4) & 0x10) != 0)) {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009eb830;
    }
    FUN_00797a20(puVar2);
    uVar1 = *(uint *)(in_ECX + 4);
    if ((uVar1 != 0) && ((uVar1 & 0x10) != 0)) {
      *(uint *)(in_ECX + 4) = uVar1 & 0xffffffef;
    }
  }
  return;
}


// ==== FUN_00710be0 @ 0x00710be0 ====

void FUN_00710be0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 4) == 0) || ((*(uint *)(in_ECX + 4) & 0x40) == 0)) {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009eb894;
    }
    FUN_00797a20(puVar2);
    uVar1 = *(uint *)(in_ECX + 4);
    if ((uVar1 == 0) || ((uVar1 & 0x40) == 0)) {
      *(uint *)(in_ECX + 4) = uVar1 | 0x40;
    }
  }
  return;
}


// ==== FUN_00710c30 @ 0x00710c30 ====

void FUN_00710c30(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 4) != 0) && ((*(uint *)(in_ECX + 4) & 0x40) != 0)) {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009eb8a8;
    }
    FUN_00797a20(puVar2);
    uVar1 = *(uint *)(in_ECX + 4);
    if ((uVar1 != 0) && ((uVar1 & 0x40) != 0)) {
      *(uint *)(in_ECX + 4) = uVar1 & 0xffffffbf;
    }
  }
  return;
}


// ==== FUN_00710c80 @ 0x00710c80 ====

void FUN_00710c80(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) != 0) && ((char)*(int *)(in_ECX + 4) < '\0')) {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009eb7e0;
      FUN_00797a20(puVar1);
      return;
    }
    FUN_00797a20(0);
  }
  return;
}


// ==== FUN_00710cc0 @ 0x00710cc0 ====

void FUN_00710cc0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009eb7a4;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00710cf0 @ 0x00710cf0 ====

void FUN_00710cf0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 4) != 0) && ((*(uint *)(in_ECX + 4) & 0x100) != 0)) {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009eb790;
      FUN_00797a20(puVar1);
      return;
    }
    FUN_00797a20(0);
  }
  return;
}


// ==== FUN_00710d30 @ 0x00710d30 ====

void FUN_00710d30(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) == 0) || (-1 < (char)*(int *)(in_ECX + 4))) {
    iVar3 = (**(code **)(*DAT_00b5ac98 + 8))();
    if ((iVar3 != 1) && (cVar2 = (**(code **)(*DAT_00b5ae58 + 8))(), cVar2 == '\0')) {
      return;
    }
    puVar4 = operator_new(4);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_009eb7b8;
    }
    FUN_00797a20(puVar4);
    uVar1 = *(uint *)(in_ECX + 4);
    if ((uVar1 == 0) || (-1 < (char)uVar1)) {
      *(uint *)(in_ECX + 4) = uVar1 | 0x80;
    }
  }
  return;
}


// ==== FUN_00710d90 @ 0x00710d90 ====

void FUN_00710d90(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) != 0) && ((char)*(int *)(in_ECX + 4) < '\0')) {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009eb7cc;
    }
    FUN_00797a20(puVar2);
    uVar1 = *(uint *)(in_ECX + 4);
    if ((uVar1 != 0) && ((char)uVar1 < '\0')) {
      *(uint *)(in_ECX + 4) = uVar1 & 0xffffff7f;
    }
  }
  return;
}


// ==== FUN_00710de0 @ 0x00710de0 ====

void FUN_00710de0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 4) == 0) || ((*(uint *)(in_ECX + 4) & 0x100) == 0)) {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009eb768;
    }
    FUN_00797a20(puVar2);
    uVar1 = *(uint *)(in_ECX + 4);
    if ((uVar1 == 0) || ((uVar1 & 0x100) == 0)) {
      *(uint *)(in_ECX + 4) = uVar1 | 0x100;
    }
  }
  return;
}


// ==== FUN_00710e30 @ 0x00710e30 ====

void FUN_00710e30(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 4) != 0) && ((*(uint *)(in_ECX + 4) & 0x100) != 0)) {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009eb77c;
    }
    FUN_00797a20(puVar2);
    uVar1 = *(uint *)(in_ECX + 4);
    if ((uVar1 != 0) && ((uVar1 & 0x100) != 0)) {
      *(uint *)(in_ECX + 4) = uVar1 & 0xfffffeff;
    }
  }
  return;
}


// ==== FUN_00710e80 @ 0x00710e80 ====

void FUN_00710e80(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\x01') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009eb86c;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 8) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_00710ec0 @ 0x00710ec0 ====

void FUN_00710ec0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009eb880;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 8) = 0;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_00710f00 @ 0x00710f00 ====

void FUN_00710f00(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined2 unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5280003;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined2 *)(iVar4 + 0x10) = unaff_retaddr;
    FUN_004d8570(iVar4);
                    /* WARNING: Could not recover jumptable at 0x00710f69. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5af2c + 4))();
    return;
  }
  return;
}


// ==== FUN_00710f70 @ 0x00710f70 ====

void FUN_00710f70(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0xf020000;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
  }
  return;
}


// ==== FUN_00710fd0 @ 0x00710fd0 ====

void FUN_00710fd0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0xf020002;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
  }
  return;
}


// ==== FUN_00711030 @ 0x00711030 ====

void FUN_00711030(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x528000a;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
  }
  return;
}


// ==== FUN_00711090 @ 0x00711090 ====

void FUN_00711090(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0xf020012;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
  }
  return;
}


// ==== FUN_007110f0 @ 0x007110f0 ====

void FUN_007110f0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0xf020010;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
  }
  return;
}


// ==== FUN_00711150 @ 0x00711150 ====

void FUN_00711150(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined1 unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0xf020004;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined1 *)(iVar4 + 0x10) = unaff_retaddr;
    FUN_004d8570(iVar4);
                    /* WARNING: Could not recover jumptable at 0x007111b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5af2c + 4))();
    return;
  }
  return;
}


// ==== FUN_007111c0 @ 0x007111c0 ====

void FUN_007111c0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0xf020007;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
  }
  return;
}


// ==== FUN_00711220 @ 0x00711220 ====

void FUN_00711220(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0xf02000a;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
  }
  return;
}


// ==== FUN_00711280 @ 0x00711280 ====

void FUN_00711280(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(5);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0xf02000d;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
  }
  return;
}


// ==== FUN_007112e0 @ 0x007112e0 ====

void FUN_007112e0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5280015;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_00711320 @ 0x00711320 ====

void FUN_00711320(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5280017;
  *(undefined2 *)((int)pvVar2 + 6) = 0x18;
  iVar3 = FUN_004244d0();
  *(undefined4 *)(iVar3 + 0x10) = param_1;
  *(undefined4 *)(iVar3 + 0x14) = param_2;
  FUN_004d8570(iVar3);
  return;
}


// ==== FUN_00711370 @ 0x00711370 ====

undefined4 FUN_00711370(int param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  
  iVar3 = param_1 + 8;
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_siege_showrespawn_009eb580,0x11);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0x14))();
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_siege_hiderespawn_009eb594,0x11);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0x40))();
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_siege_showgate_009eb5a8,0xe);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0x10))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_siege_hidegate_009eb5b8);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x38))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_siege_showzeolite_009eb5c8);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x18))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_siege_hidezeolite_009eb5dc);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x44))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_siege_showplaytimewnd_009eb5f0);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 4))();
    return 1;
  }
  cVar1 = FUN_004036a0(iVar3,s_siege_hideplaytimewnd_009eb608);
  if (cVar1 == '\0') {
    return 0;
  }
  (**(code **)(*in_ECX + 0x2c))();
  return 1;
}


// ==== FUN_007114a0 @ 0x007114a0 ====

void FUN_007114a0(void)

{
  undefined4 *in_ECX;
  uint unaff_EBX;
  void *unaff_EBP;
  uint unaff_ESI;
  void *unaff_EDI;
  undefined1 *_Memory;
  undefined1 auStack_5a [2];
  uint uVar1;
  uint uVar2;
  undefined4 uStack_40;
  undefined1 auStack_2a [2];
  uint local_28;
  uint local_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098f858;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009eb8bc;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ac94 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ac94 = in_ECX;
  }
  uStack_40 = 0x11;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = local_24 & 0xffffff00;
  FUN_00401740();
  uStack_40 = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
  if (0xf < uStack_18) {
    _free(in_ECX);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  FUN_00401740();
  uVar2 = 0;
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  local_14 = local_14 & 0xffffff00;
  if (0xf < uStack_20) {
    _free(unaff_EBP);
    return;
  }
  uStack_20 = 0xf;
  local_24 = 0;
  FUN_00401740();
  uVar1 = 0;
  local_14 = CONCAT31(local_14._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  uStack_1c = uStack_1c & 0xffffff00;
  if (0xf < local_28) {
    _free(unaff_EDI);
    return;
  }
  local_28 = 0xf;
  FUN_00401740();
  uStack_1c = CONCAT31(uStack_1c._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  local_24 = local_24 & 0xffffff00;
  if (0xf < unaff_EBX) {
    _free(&local_28);
    return;
  }
  FUN_00401740(s_siege_showzeolite_009eb488);
  _Memory = auStack_5a + 0x12;
  local_24 = CONCAT31(local_24._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < unaff_ESI) {
    _free(auStack_2a + -6);
    return;
  }
  FUN_00401740(s_siege_hidezeolite_009eb49c,0x11);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(auStack_5a + 10,0);
  if (0xf < uStack_40) {
    _free(auStack_2a + -0xe);
    return;
  }
  uStack_40 = 0xf;
  FUN_00401740(s_siege_showplaytimewnd_009eb4b0,0x15);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(auStack_5a + 2,0);
  if (0xf < uVar2) {
    _free(&uStack_40);
    return;
  }
  FUN_00401740(s_siege_hideplaytimewnd_009eb4c8,0x15);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(auStack_5a + -6,0);
  if (uVar1 < 0x10) {
    ExceptionList = (void *)0x0;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00711760 @ 0x00711760 ====

/* WARNING: Removing unreachable block (ram,0x007119c8) */
/* WARNING: Removing unreachable block (ram,0x00711984) */

void FUN_00711760(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined4 uStack_40;
  undefined1 auStack_2a [2];
  void *local_28;
  uint local_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098f8aa;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009eb8bc;
  uStack_40 = (void **)0x11;
  local_4 = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = local_24 & 0xffffff00;
  FUN_00401740();
  uStack_40 = &local_28;
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_siege_hiderespawn_009eb4f4);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
  if (0xf < uStack_18) {
    _free(in_ECX);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  FUN_00401740(s_siege_showgate_009eb508,0xe);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -6);
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(unaff_EBX);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  FUN_00401740(s_siege_hidegate_009eb518,0xe);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -10);
  local_14 = local_14 & 0xffffff00;
  if (0xf < uStack_20) {
    _free(unaff_EBP);
    return;
  }
  uStack_20 = 0xf;
  local_24 = 0;
  FUN_00401740(s_siege_showzeolite_009eb528,0x11);
  local_14 = CONCAT31(local_14._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -0xe);
  uStack_18 = uStack_18 & 0xffffff00;
  if (0xf < local_24) {
    _free(unaff_ESI);
    return;
  }
  local_24 = 0xf;
  local_28 = (void *)0x0;
  FUN_00401740(s_siege_hidezeolite_009eb53c,0x11);
  uStack_18 = CONCAT31(uStack_18._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -0x12);
  uStack_1c = uStack_1c & 0xffffff00;
  if (local_28 < (void *)0x10) {
    local_28 = (void *)0xf;
    FUN_00401740(s_siege_showplaytimewnd_009eb550,0x15);
    uStack_1c = CONCAT31(uStack_1c._1_3_,7);
    (**(code **)(*DAT_00b5a6c8 + 0x10))(&uStack_40);
    uStack_20 = uStack_20 & 0xffffff00;
    uStack_40 = (void **)((uint)uStack_40 & 0xffffff00);
    FUN_00401740(s_siege_hideplaytimewnd_009eb568,0x15);
    uStack_20 = CONCAT31(uStack_20._1_3_,8);
    (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -0x1a);
    DAT_00b5ac94 = 0;
    *in_ECX = &PTR_FUN_009eb664;
    ExceptionList = (void *)0xf;
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_00711a00 @ 0x00711a00 ====

void FUN_00711a00(undefined4 param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int unaff_EBX;
  uint unaff_ESI;
  undefined4 unaff_retaddr;
  undefined1 auStack_8c [4];
  undefined1 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  int *piStack_7c;
  undefined4 uStack_78;
  int iStack_74;
  char *pcStack_70;
  undefined1 auStack_4e [22];
  undefined1 auStack_38 [4];
  undefined4 uStack_34;
  void *pvStack_2c;
  void *pvStack_24;
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f8f4;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar3 == 0) {
    uStack_10 = 0xf;
    pvStack_14 = (void *)0x0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740();
    uStack_4 = 0;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  iVar4 = (**(code **)(*DAT_00b5ac98 + 4))();
  if (iVar4 == 0) {
    uStack_10 = 0xf;
    pvStack_14 = (void *)0x0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740();
    uStack_4 = 1;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  (**(code **)(*DAT_00b5ac98 + 0x20))();
  piStack_7c = (int *)(**(code **)(*DAT_00b5abc8 + 8))();
  if (piStack_7c == (int *)0x0) {
    pcStack_70 = s_pFlyweight_009eb634;
    uStack_18 = 0xf;
    uStack_1c = 0;
    pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
    iStack_74 = 0x711b28;
    FUN_00401740();
    pvStack_c = (void *)0x2;
    pcStack_70 = (char *)0x711b3a;
    FUN_00406880();
    pvStack_c = (void *)0xffffffff;
    if (uStack_18 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    pcStack_70 = (char *)0x711b56;
    _free(pvStack_2c);
    return;
  }
  uStack_78 = param_1;
  uStack_84 = 0x711b75;
  iStack_74 = iVar3;
  uVar5 = FUN_00827c40();
  switch(uVar5) {
  case 0:
    pcStack_70 = (char *)0x711b8f;
    puVar6 = operator_new(0xc);
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      *puVar6 = &PTR_FUN_009eb81c;
    }
    puVar6[2] = param_1;
    puVar6[1] = unaff_retaddr;
    pcStack_70 = (char *)0x711bb0;
    FUN_00797a20();
    uVar1 = *(uint *)(unaff_EBX + 4);
    if ((uVar1 == 0) || ((uVar1 & 0x10) == 0)) {
      *(uint *)(unaff_EBX + 4) = uVar1 | 0x10;
      ExceptionList = pvStack_14;
      return;
    }
    ExceptionList = pvStack_14;
    return;
  case 1:
    pcStack_70 = (char *)0x8;
    iStack_74 = 0x711bf2;
    iStack_74 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_78 = 0x711bfc;
    FUN_00765c50();
    pvStack_14 = (void *)0x3;
    break;
  case 2:
    pcStack_70 = (char *)0x8;
    iStack_74 = 0x711cbe;
    iStack_74 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_78 = 0x711cc8;
    FUN_00765c50();
    puStack_8 = auStack_8c;
    pvStack_14 = (void *)0x6;
    FUN_00765c50(auStack_38);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    uStack_34 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 3:
    pcStack_70 = (char *)0x8;
    iStack_74 = 0x711c18;
    iStack_74 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_78 = 0x711c22;
    FUN_00765c50();
    puStack_8 = auStack_8c;
    pvStack_14 = (void *)0x4;
    FUN_00765c50(auStack_38);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    goto LAB_00711c96;
  case 4:
    pcStack_70 = (char *)0x8;
    iStack_74 = 0x711c61;
    iStack_74 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_78 = 0x711c6b;
    FUN_00765c50();
    pvStack_14 = (void *)0x5;
    break;
  default:
    pcStack_70 = (void *)0x8;
    iStack_74 = 0x711d16;
    piStack_7c = (int *)(**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_74 = 0xffffffff;
    uStack_78 = 0;
    uStack_80 = 0x711d34;
    FUN_00401660();
    puStack_8 = auStack_8c;
    iStack_74 = 0xf;
    uStack_78 = 0;
    pvStack_14 = (void *)0x7;
    uStack_88 = 0;
    FUN_00401660(auStack_4e + -6,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(8);
    uStack_34 = 0xffffffff;
    if (unaff_ESI < 0x10) {
      pcStack_70 = (char *)((uint)pcStack_70 & 0xffffff00);
      (**(code **)(*piStack_7c + 0x94))();
      ExceptionList = pvStack_14;
      return;
    }
    _free(pcStack_70);
    return;
  }
  puStack_8 = auStack_8c;
  FUN_00765c50(auStack_38);
  (**(code **)(*DAT_00b5ad0c + 0x28))(8);
LAB_00711c96:
  uStack_34 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00711dd0 @ 0x00711dd0 ====

int FUN_00711dd0(int param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_94 [16];
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined1 auStack_4c [64];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098f91e;
  pvStack_c = ExceptionList;
  uStack_70 = 0x711df8;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*DAT_00b5ac98 + 0x5c))();
  if ((((char)iVar1 != '\0') && (*(int *)(in_ECX + 0x14) != 0)) &&
     (uVar3 = *(uint *)(in_ECX + 0xc), *(uint *)(in_ECX + 0x10) < uVar3)) {
    *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + *(int *)(param_1 + 4);
    if (uVar3 < *(uint *)(in_ECX + 0x10)) {
      *(uint *)(in_ECX + 0x10) = uVar3;
    }
    uVar3 = uVar3 - *(int *)(in_ECX + 0x10);
    iVar1 = uVar3 * 0x10624dd3;
    uVar4 = uVar3 / 1000;
    *(uint *)(in_ECX + 0x14) = uVar3;
    if ((uVar4 != 0x3c) && (uVar4 != 0x1e)) {
      *(undefined1 *)(in_ECX + 9) = 0;
      ExceptionList = pvStack_c;
      return iVar1;
    }
    if (*(char *)(in_ECX + 9) == '\0') {
      uStack_70 = 0x2bc0081;
      uStack_74 = 8;
      uStack_78 = 0x711e78;
      uStack_78 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_7c = 0x711e82;
      FUN_00765c50();
      pvStack_c = (void *)0x0;
      uStack_78 = 0x711e95;
      piVar2 = (int *)(**(code **)(*DAT_00b5ab00 + 4))();
      uStack_78 = 0x711e9c;
      iVar1 = (**(code **)(*piVar2 + 4))();
      uStack_78 = iVar1 + 0xc;
      uStack_7c = 0x711ea9;
      FUN_00401830();
      puStack_4 = auStack_94;
      pvStack_c._0_1_ = 1;
      uStack_78 = uVar4;
      FUN_00765c50(auStack_4c + -0x1c);
      uStack_80 = FUN_00404230(auStack_4c);
      uStack_78 = 0xffffffff;
      uStack_7c = 0;
      pvStack_c._0_1_ = 2;
      uStack_84 = 0x711ee9;
      FUN_00401660();
      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
                    /* WARNING: Subroutine does not return */
      uStack_78 = 0x711ef6;
      FUN_00446f10();
    }
  }
  ExceptionList = pvStack_c;
  return iVar1;
}


// ==== FUN_00711f80 @ 0x00711f80 ====

uint FUN_00711f80(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00711dd0(param_1);
  }
  else if (uVar1 == 0x70004) {
    uVar1 = FUN_00711370(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00711fc0 @ 0x00711fc0 ====

undefined4 FUN_00711fc0(void)

{
  return 0x70910000;
}


// ==== FUN_00711fd0 @ 0x00711fd0 ====

undefined4 FUN_00711fd0(void)

{
  return 0x70910002;
}


// ==== FUN_00711fe0 @ 0x00711fe0 ====

undefined4 FUN_00711fe0(void)

{
  return 0x70910001;
}


// ==== FUN_00711ff0 @ 0x00711ff0 ====

undefined4 FUN_00711ff0(void)

{
  return 0x70910003;
}


// ==== FUN_00712000 @ 0x00712000 ====

undefined4 FUN_00712000(void)

{
  return 0x70910004;
}


// ==== FUN_00712010 @ 0x00712010 ====

undefined4 FUN_00712010(void)

{
  return 0x70910020;
}


// ==== FUN_00712020 @ 0x00712020 ====

undefined4 FUN_00712020(void)

{
  return 0x70910021;
}


// ==== FUN_00712030 @ 0x00712030 ====

undefined4 FUN_00712030(void)

{
  return 0x70910022;
}


// ==== FUN_00712040 @ 0x00712040 ====

undefined4 FUN_00712040(void)

{
  return 0x70910026;
}


// ==== FUN_00712050 @ 0x00712050 ====

undefined4 FUN_00712050(void)

{
  return 0x70910023;
}


// ==== FUN_00712060 @ 0x00712060 ====

undefined4 FUN_00712060(void)

{
  return 0x70910024;
}


// ==== FUN_00712070 @ 0x00712070 ====

undefined4 FUN_00712070(void)

{
  return 0x70910025;
}


// ==== FUN_00712080 @ 0x00712080 ====

undefined4 FUN_00712080(void)

{
  return 0x70910005;
}


// ==== FUN_00712090 @ 0x00712090 ====

undefined4 FUN_00712090(void)

{
  return 0x70910006;
}


// ==== FUN_007120a0 @ 0x007120a0 ====

undefined4 FUN_007120a0(void)

{
  return 0x70910007;
}


// ==== FUN_007120b0 @ 0x007120b0 ====

undefined4 FUN_007120b0(void)

{
  return 0x70910008;
}


// ==== FUN_007120c0 @ 0x007120c0 ====

undefined4 FUN_007120c0(void)

{
  return 0x70910011;
}


// ==== FUN_007120d0 @ 0x007120d0 ====

undefined4 FUN_007120d0(void)

{
  return 0x70910012;
}


// ==== FUN_007120e0 @ 0x007120e0 ====

undefined4 FUN_007120e0(void)

{
  return 0x70910009;
}


// ==== FUN_007120f0 @ 0x007120f0 ====

undefined4 FUN_007120f0(void)

{
  return 0x70910010;
}


// ==== FUN_00712100 @ 0x00712100 ====

undefined4 FUN_00712100(void)

{
  return 0x70910013;
}


// ==== FUN_00712110 @ 0x00712110 ====

undefined4 FUN_00712110(void)

{
  return 0x70910014;
}


// ==== FUN_00712120 @ 0x00712120 ====

void FUN_00712120(byte param_1)

{
  void *in_ECX;
  
  FUN_00711760();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00712140 @ 0x00712140 ====

void FUN_00712140(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eba3c;
  return;
}


// ==== FUN_00712150 @ 0x00712150 ====

void FUN_00712150(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009eba3c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00712170 @ 0x00712170 ====

undefined4 FUN_00712170(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x48);
}


// ==== FUN_00712180 @ 0x00712180 ====

void FUN_00712180(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00712190 @ 0x00712190 ====

undefined4 FUN_00712190(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_007121d0 @ 0x007121d0 ====

undefined4 FUN_007121d0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098f93b;
  local_c = ExceptionList;
  if (*(int *)(in_ECX + 0x48) != 0) {
    return 0;
  }
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x4c);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x48) = 0;
    ExceptionList = local_c;
    return 1;
  }
  uVar2 = FUN_0089f070();
  *(undefined4 *)(in_ECX + 0x48) = uVar2;
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00712250 @ 0x00712250 ====

void FUN_00712250(void)

{
  char cVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x48) != (int *)0x0) {
    cVar1 = (**(code **)(**(int **)(in_ECX + 0x48) + 0x14))();
    if (cVar1 == '\x01') {
      (**(code **)(**(int **)(in_ECX + 0x48) + 8))();
    }
    if (*(undefined4 **)(in_ECX + 0x48) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x48))(1);
    }
    *(undefined4 *)(in_ECX + 0x48) = 0;
  }
  return;
}


// ==== FUN_00712290 @ 0x00712290 ====

void FUN_00712290(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x48) == (int *)0x0) {
    return;
  }
  *(undefined1 *)(in_ECX + 5) = 1;
  (**(code **)(**(int **)(in_ECX + 0x48) + 0x20))(0);
  iVar1 = *DAT_00b5add0;
  uVar3 = (**(code **)(*DAT_00b5ae14 + 0x18))();
  cVar2 = (**(code **)(iVar1 + 0x3c))(uVar3);
  if (cVar2 != '\0') {
    (**(code **)(*DAT_00b5ac94 + 0x10))();
    (**(code **)(*DAT_00b5ac94 + 0x18))();
    (**(code **)(*DAT_00b5add0 + 0x50))();
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5ab00 + 4))();
                    /* WARNING: Could not recover jumptable at 0x007122f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar4 + 0x10))();
  return;
}


// ==== FUN_00712300 @ 0x00712300 ====

void FUN_00712300(void)

{
  int *piVar1;
  int *in_ECX;
  
  *(undefined1 *)((int)in_ECX + 5) = 0;
  piVar1 = (int *)(**(code **)(*DAT_00b5ab00 + 4))();
  (**(code **)(*piVar1 + 0x14))();
  (**(code **)(*DAT_00b5add0 + 0x50))();
  (**(code **)(*DAT_00b5ac94 + 0x38))();
  (**(code **)(*DAT_00b5ac94 + 0x44))();
  *(undefined1 *)((int)in_ECX + 6) = 0;
  (**(code **)(*in_ECX + 0x30))(0);
  return;
}


// ==== FUN_00712350 @ 0x00712350 ====

void FUN_00712350(void)

{
  int *in_ECX;
  
  (**(code **)(*DAT_00b5b180 + 0x14))();
  (**(code **)(*DAT_00b5add0 + 0x50))();
  (**(code **)(*in_ECX + 0x30))(0);
  return;
}


// ==== FUN_00712380 @ 0x00712380 ====

void FUN_00712380(void)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ab00 + 4))();
                    /* WARNING: Could not recover jumptable at 0x0071238f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x18))();
  return;
}


// ==== FUN_007123a0 @ 0x007123a0 ====

void FUN_007123a0(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 6) != '\0') {
    piVar1 = (int *)(**(code **)(*DAT_00b5ab00 + 4))();
    (**(code **)(*piVar1 + 0x20))();
    *(undefined1 *)(in_ECX + 6) = 0;
  }
  return;
}


// ==== FUN_007123d0 @ 0x007123d0 ====

void FUN_007123d0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == param_1) {
    (**(code **)(*DAT_00b5ac6c + 0x14))(param_1,*(undefined4 *)(in_ECX + 0x10));
  }
  uVar1 = FUN_004dd240(0x12,10,param_2,0,param_1);
  *(int *)(in_ECX + 0xc) = param_1;
  *(undefined4 *)(in_ECX + 0x10) = uVar1;
  return;
}


// ==== FUN_00712410 @ 0x00712410 ====

bool FUN_00712410(undefined4 param_1,char param_2)

{
  char cVar1;
  
  if (param_2 == '\x01') {
    cVar1 = (**(code **)(*DAT_00b5acac + 0x38))();
    return cVar1 == '\0';
  }
  cVar1 = (**(code **)(*DAT_00b5acac + 0x40))(param_1);
  return cVar1 == '\0';
}


// ==== FUN_00712440 @ 0x00712440 ====

undefined4 FUN_00712440(ushort param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *in_ECX;
  uint uVar4;
  
  iVar1 = (**(code **)(*in_ECX + 8))();
  uVar4 = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5ab04 + 8))();
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  do {
    puVar3 = (undefined4 *)(**(code **)(*piVar2 + 4))();
    if (puVar3[2] == iVar1) {
      if (param_1 == uVar4) {
        return *puVar3;
      }
      uVar4 = uVar4 + 1;
    }
    piVar2 = (int *)(**(code **)(*DAT_00b5ab04 + 0xc))();
  } while (piVar2 != (int *)0x0);
  return 0;
}


// ==== FUN_007124c0 @ 0x007124c0 ====

undefined4 FUN_007124c0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)(*piVar1 + 0x34))(param_1);
  return CONCAT31((int3)((uint)*(undefined4 *)(iVar2 + 8) >> 8),(char)*(undefined4 *)(iVar2 + 4));
}


// ==== FUN_00712500 @ 0x00712500 ====

undefined4 FUN_00712500(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)(*piVar1 + 0x34))(param_1);
  return *(undefined4 *)(iVar2 + 8);
}


// ==== FUN_00712540 @ 0x00712540 ====

void FUN_00712540(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ebad0;
  }
  FUN_00797a20(puVar1);
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ebae4;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00712590 @ 0x00712590 ====

uint FUN_00712590(void)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) == 0) {
    return in_EAX & 0xffff0000;
  }
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x48) + 0x18))();
  if (uVar1 / 1000 < *(uint *)(iVar2 + 4)) {
    return (*(uint *)(iVar2 + 4) - uVar1 / 1000) / 0x15180;
  }
  return 0;
}


// ==== FUN_007125f0 @ 0x007125f0 ====

uint FUN_007125f0(void)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) == 0) {
    return in_EAX & 0xffff0000;
  }
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x48) + 0x18))();
  if (uVar1 / 1000 < *(uint *)(iVar2 + 4)) {
    return (*(uint *)(iVar2 + 4) - uVar1 / 1000) / 0xe10;
  }
  return 0;
}


// ==== FUN_00712650 @ 0x00712650 ====

uint FUN_00712650(void)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) == 0) {
    return in_EAX & 0xffff0000;
  }
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x48) + 0x18))();
  if (uVar1 / 1000 < *(uint *)(iVar2 + 4)) {
    return (*(uint *)(iVar2 + 4) - uVar1 / 1000) / 0x3c;
  }
  return 0;
}


// ==== FUN_007126b0 @ 0x007126b0 ====

void FUN_007126b0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 local_3a [25];
  undefined1 local_21 [33];
  
  if (*(char *)(in_ECX + 6) != '\x01') {
    if (*(uint *)(param_2 + 0x18) < 0x10) {
      param_2 = param_2 + 4;
    }
    else {
      param_2 = *(int *)(param_2 + 4);
    }
    FUN_0047aa30(local_3a,&DAT_009eba20,param_2);
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      param_1 = param_1 + 4;
    }
    else {
      param_1 = *(int *)(param_1 + 4);
    }
    FUN_0050cd30(local_21,&DAT_009eba1c,param_1);
    piVar2 = DAT_00b5a6ac;
    piVar3 = (int *)(**(code **)(*DAT_00b5ab00 + 4))();
    iVar1 = *piVar3;
    uVar4 = (**(code **)(*piVar2 + 0x20))();
    (**(code **)(iVar1 + 0x1c))(local_21,0,local_3a,param_3,uVar4);
    *(undefined1 *)(in_ECX + 6) = 1;
  }
  return;
}


// ==== FUN_00712760 @ 0x00712760 ====

bool FUN_00712760(int param_1)

{
  int iVar1;
  undefined1 local_21 [33];
  
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    param_1 = param_1 + 4;
  }
  else {
    param_1 = *(int *)(param_1 + 4);
  }
  FUN_0050cd30(local_21,&DAT_009eba1c,param_1);
  iVar1 = (**(code **)(*DAT_00b5abec + 0xc))(local_21);
  return iVar1 != 0;
}


// ==== FUN_007127f0 @ 0x007127f0 ====

undefined2 FUN_007127f0(undefined4 param_1)

{
  int in_ECX;
  int local_4;
  
  if (*(int *)(in_ECX + 0x44) == 0) {
    return 0xffff;
  }
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x40)) {
    return 0xffff;
  }
  return *(undefined2 *)(local_4 + 0x10);
}


// ==== FUN_00712840 @ 0x00712840 ====

void FUN_00712840(undefined1 param_1,undefined1 param_2)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_005babb0(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0x30)) {
    *(undefined1 *)(local_4 + 0x18) = param_2;
  }
  return;
}


// ==== FUN_00712870 @ 0x00712870 ====

void FUN_00712870(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x44) != 0) {
    FUN_00713790(*(undefined4 *)(*(int *)(in_ECX + 0x40) + 4));
    *(int *)(*(int *)(in_ECX + 0x40) + 4) = *(int *)(in_ECX + 0x40);
    *(undefined4 *)(in_ECX + 0x44) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(in_ECX + 0x40);
    *(int *)(*(int *)(in_ECX + 0x40) + 8) = *(int *)(in_ECX + 0x40);
  }
  FUN_007143b0(in_ECX + 0x3c);
  return;
}


// ==== FUN_007128c0 @ 0x007128c0 ====

void FUN_007128c0(undefined1 param_1)

{
  code *pcVar1;
  char cVar2;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098f94d;
  pvStack_c = ExceptionList;
  if (*(int *)(in_ECX + 0x48) != 0) {
    ExceptionList = &pvStack_c;
    cVar2 = (**(code **)(**(int **)(in_ECX + 0x48) + 0x14))();
    if (cVar2 == '\0') {
      (**(code **)(**(int **)(in_ECX + 0x48) + 4))(&param_1);
    }
    ExceptionList = pvStack_c;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_m_pLogicSiege____NULL_009eb994,0x15);
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


// ==== FUN_00712970 @ 0x00712970 ====

void FUN_00712970(void)

{
  code *pcVar1;
  char cVar2;
  int *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098f95f;
  pvStack_c = ExceptionList;
  if (in_ECX[0x12] != 0) {
    ExceptionList = &pvStack_c;
    cVar2 = (**(code **)(*(int *)in_ECX[0x12] + 0x14))();
    if (cVar2 == '\x01') {
      (**(code **)(*(int *)in_ECX[0x12] + 8))();
    }
    *(undefined1 *)((int)in_ECX + 6) = 0;
    (**(code **)(*DAT_00b5add0 + 0x50))();
    (**(code **)(*in_ECX + 0x30))(0);
    ExceptionList = local_10;
    return;
  }
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_m_pLogicSiege____NULL_009eb9ac,0x15);
  local_4 = 0;
  FUN_00406880(local_28);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = (void *)0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00712a30 @ 0x00712a30 ====

undefined4 FUN_00712a30(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 extraout_EAX_00;
  int iVar4;
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
  puStack_8 = &LAB_0098f979;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
  if (piVar2 == (int *)0x0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pLogicGuild____NULL_009eb9c4,0x13);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_24);
    return extraout_EAX;
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
  if (piVar2 == (int *)0x0) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(s_pGuildSiege____NULL_009eb9d8,0x13);
    uStack_4 = 1;
    FUN_00406880(auStack_44);
    uStack_4 = 0xffffffff;
    if (uStack_2c < 0x10) {
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_40);
    return extraout_EAX_00;
  }
  iVar4 = (**(code **)(*piVar2 + 0x10))();
  if (iVar4 == 1) {
    ExceptionList = pvStack_c;
    return 1;
  }
  if (iVar4 == 3) {
    ExceptionList = pvStack_c;
    return 3;
  }
  ExceptionList = pvStack_c;
  return 6;
}


// ==== FUN_00712b70 @ 0x00712b70 ====

void FUN_00712b70(void)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f98b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x48) + 0x40))();
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))();
    ExceptionList = pvStack_c;
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pInform____NULL_009eb9ec,0xf);
  uStack_4 = 0;
  FUN_00406880(auStack_28);
  uStack_4 = 0xffffffff;
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_00712c10 @ 0x00712c10 ====

void FUN_00712c10(undefined1 param_1)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  undefined1 uStack00000020;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098f9a5;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x48) + 0x40))();
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(&param_1);
    puStack_8 = (undefined1 *)0xffffffff;
    _eh_vector_destructor_iterator_(&uStack00000020,0xb4,5,FUN_006ef6d0);
    ExceptionList = pvStack_10;
    return;
  }
  pvStack_10 = (void *)0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pInform____NULL_009eb9fc,0xf);
  local_4._0_1_ = 1;
  FUN_00406880(auStack_28);
  local_4 = (uint)local_4._1_3_ << 8;
  if (pvStack_10 < 0x10) {
    pvStack_10 = (void *)0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_00712ce0 @ 0x00712ce0 ====

/* WARNING: Removing unreachable block (ram,0x00712d53) */
/* WARNING: Removing unreachable block (ram,0x00712dc9) */

undefined4 FUN_00712ce0(void *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  void *unaff_ESI;
  undefined4 uStack_30;
  int iStack_20;
  uint uStack_1c;
  void *pvStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098f9b7;
  pvStack_c = ExceptionList;
  uStack_30 = (void *)0x712d04;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5acac + 0x48))();
  uStack_30 = (void *)0xd;
  FUN_00401740(s_invalide_name_009eba0c);
  uStack_4 = 0;
  uStack_30 = param_1;
  if (iVar2 == 1) {
    cVar1 = (**(code **)(*DAT_00b5acac + 0x38))();
    if (cVar1 == '\x01') {
      ExceptionList = (void *)0xf;
      return 4;
    }
    cVar1 = (**(code **)(*DAT_00b5acac + 0x50))(param_1,(int)register0x00000010 + -0x2c);
    if ((cVar1 == '\x01') && (iStack_20 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  else {
    cVar1 = (**(code **)(*DAT_00b5acac + 0x38))();
    if (cVar1 == '\x01') {
      ExceptionList = (void *)0xf;
      return 0;
    }
    cVar1 = (**(code **)(*DAT_00b5acac + 0x40))(param_1);
    if (cVar1 == '\x01') {
      if (pvStack_18 < (void *)0x10) {
        ExceptionList = (void *)0x0;
        return 1;
      }
      _free(unaff_ESI);
      return extraout_EAX;
    }
    cVar1 = (**(code **)(*DAT_00b5acac + 0x50))(param_1,&uStack_30);
    if ((cVar1 == '\x01') && (iStack_20 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  if (uStack_1c < 0x10) {
    ExceptionList = pvStack_18;
    return 5;
  }
  _free(uStack_30);
  return extraout_EAX_00;
}


// ==== FUN_00712e90 @ 0x00712e90 ====

undefined4 FUN_00712e90(undefined4 param_1,undefined1 param_2)

{
  undefined4 extraout_EAX;
  int in_ECX;
  int local_3c [3];
  undefined1 local_30;
  undefined1 local_2f;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098f9c9;
  local_c = ExceptionList;
  local_3c[0] = 0;
  ExceptionList = &local_c;
  FUN_005babb0(local_3c,&param_2);
  if (local_3c[0] != *(int *)(in_ECX + 0x30)) {
    FUN_005386a0(local_3c[0] + 0x10);
    ExceptionList = local_c;
    return param_1;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_3c[1] = 0xffffffff;
  local_3c[2] = 0;
  local_2f = 1;
  local_30 = 0;
  local_2e = 0;
  local_2a = 0;
  local_2c = 0;
  local_4 = 0;
  FUN_005386a0(local_3c + 1);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00712f70 @ 0x00712f70 ====

undefined4 FUN_00712f70(int param_1)

{
  int in_ECX;
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)**(int **)(in_ECX + 0x30);
  *(int **)(in_ECX + 0x38) = piVar1;
  if (piVar1 != *(int **)(in_ECX + 0x30)) {
    FUN_00401660(piVar1 + 8,0,0xffffffff);
    return *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x10);
  }
  piVar1 = (int *)(param_1 + 4);
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    piVar2 = piVar1;
  }
  else {
    piVar2 = (int *)*piVar1;
  }
  if (0xf < *(uint *)(param_1 + 0x18)) {
    piVar1 = (int *)*piVar1;
  }
  FUN_004bdb30(&param_1,piVar1,*(int *)(param_1 + 0x14) + (int)piVar2);
  return 0;
}


// ==== FUN_00712fd0 @ 0x00712fd0 ====

undefined4 FUN_00712fd0(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int *piVar3;
  
  FUN_007136c0();
  iVar1 = *(int *)(in_ECX + 0x38);
  if (iVar1 != *(int *)(in_ECX + 0x30)) {
    FUN_00401660(iVar1 + 0x20,0,0xffffffff);
    return *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x10);
  }
  piVar2 = (int *)(param_1 + 4);
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    piVar3 = piVar2;
  }
  else {
    piVar3 = (int *)*piVar2;
  }
  if (0xf < *(uint *)(param_1 + 0x18)) {
    piVar2 = (int *)*piVar2;
  }
  FUN_004bdb30(&param_1,piVar2,*(int *)(param_1 + 0x14) + (int)piVar3);
  return 0;
}


// ==== FUN_00713030 @ 0x00713030 ====

void FUN_00713030(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined1 auStack_8 [8];
  
  FUN_0079bba0(&local_10,&param_1);
  if (local_10 != *(int *)(in_ECX + 0x18)) {
    (**(code **)(*DAT_00b5ac6c + 0x14))
              (*(undefined4 *)(local_10 + 0xc),*(undefined4 *)(local_10 + 0x10));
    FUN_00458a70(auStack_8 + -0x10,local_10);
  }
  local_10 = param_1;
  uStack_c = FUN_004dd240(0x23,1,param_2,0,param_1);
  FUN_00458d90(auStack_8,&local_10);
  return;
}


// ==== FUN_007130b0 @ 0x007130b0 ====

void FUN_007130b0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined1 auStack_8 [8];
  
  FUN_0079bba0(&local_10,&param_1);
  if (local_10 != *(int *)(in_ECX + 0x24)) {
    (**(code **)(*DAT_00b5ac6c + 0x14))
              (*(undefined4 *)(local_10 + 0xc),*(undefined4 *)(local_10 + 0x10));
    FUN_00458a70(auStack_8 + -0x10,local_10);
  }
  local_10 = param_1;
  uStack_c = FUN_004dd240(0x23,2,param_2,0,param_1);
  FUN_00458d90(auStack_8,&local_10);
  return;
}


// ==== FUN_00713130 @ 0x00713130 ====

void FUN_00713130(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_005babb0(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0x30)) {
    FUN_00713bd0(&param_1,local_4);
  }
  FUN_00712540();
  return;
}


// ==== FUN_00713170 @ 0x00713170 ====

void FUN_00713170(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\x01') {
    FUN_007121d0();
    FUN_00712870();
    FUN_00458850(*(undefined4 *)(*(int *)(in_ECX + 0x18) + 4));
    *(int *)(*(int *)(in_ECX + 0x18) + 4) = *(int *)(in_ECX + 0x18);
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x18);
    *(int *)(*(int *)(in_ECX + 0x18) + 8) = *(int *)(in_ECX + 0x18);
    FUN_00458850(*(undefined4 *)(*(int *)(in_ECX + 0x24) + 4));
    *(int *)(*(int *)(in_ECX + 0x24) + 4) = *(int *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(in_ECX + 0x24);
    *(int *)(*(int *)(in_ECX + 0x24) + 8) = *(int *)(in_ECX + 0x24);
    FUN_00713ea0(*(undefined4 *)(*(int *)(in_ECX + 0x30) + 4));
    *(int *)(*(int *)(in_ECX + 0x30) + 4) = *(int *)(in_ECX + 0x30);
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(in_ECX + 0x30);
    *(int *)(*(int *)(in_ECX + 0x30) + 8) = *(int *)(in_ECX + 0x30);
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_00713210 @ 0x00713210 ====

void FUN_00713210(void)

{
  char cVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    if (*(int **)(in_ECX + 0x48) != (int *)0x0) {
      cVar1 = (**(code **)(**(int **)(in_ECX + 0x48) + 0x14))();
      if (cVar1 == '\x01') {
        (**(code **)(**(int **)(in_ECX + 0x48) + 8))();
      }
      if (*(undefined4 **)(in_ECX + 0x48) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 0x48))(1);
      }
      *(undefined4 *)(in_ECX + 0x48) = 0;
    }
    if (*(int *)(in_ECX + 0x44) != 0) {
      FUN_00713790(*(undefined4 *)(*(int *)(in_ECX + 0x40) + 4));
      *(int *)(*(int *)(in_ECX + 0x40) + 4) = *(int *)(in_ECX + 0x40);
      *(undefined4 *)(in_ECX + 0x44) = 0;
      *(undefined4 *)*(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(in_ECX + 0x40);
      *(int *)(*(int *)(in_ECX + 0x40) + 8) = *(int *)(in_ECX + 0x40);
    }
    FUN_00458850(*(undefined4 *)(*(int *)(in_ECX + 0x18) + 4));
    *(int *)(*(int *)(in_ECX + 0x18) + 4) = *(int *)(in_ECX + 0x18);
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x18);
    *(int *)(*(int *)(in_ECX + 0x18) + 8) = *(int *)(in_ECX + 0x18);
    FUN_00458850(*(undefined4 *)(*(int *)(in_ECX + 0x24) + 4));
    *(int *)(*(int *)(in_ECX + 0x24) + 4) = *(int *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(in_ECX + 0x24);
    *(int *)(*(int *)(in_ECX + 0x24) + 8) = *(int *)(in_ECX + 0x24);
    FUN_00713ea0(*(undefined4 *)(*(int *)(in_ECX + 0x30) + 4));
    *(int *)(*(int *)(in_ECX + 0x30) + 4) = *(int *)(in_ECX + 0x30);
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(in_ECX + 0x30);
    *(int *)(*(int *)(in_ECX + 0x30) + 8) = *(int *)(in_ECX + 0x30);
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_007132f0 @ 0x007132f0 ====

void FUN_007132f0(undefined4 param_1)

{
  undefined4 *puVar1;
  void *in_stack_00000018;
  uint in_stack_0000002c;
  undefined1 local_44 [8];
  undefined4 local_3c [6];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098f9e3;
  local_c = ExceptionList;
  local_4 = 0;
  local_3c[0] = param_1;
  ExceptionList = &local_c;
  FUN_005386a0(&param_1);
  local_4._0_1_ = 1;
  FUN_00714220(local_44,local_3c);
  local_4 = (uint)local_4._1_3_ << 8;
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ebad0;
  }
  FUN_00797a20(puVar1);
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ebae4;
  }
  FUN_00797a20(puVar1);
  if (in_stack_0000002c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000018);
  return;
}


// ==== FUN_007133d0 @ 0x007133d0 ====

void FUN_007133d0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098fa2c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ebafc;
  local_4 = 5;
  FUN_00713210();
  DAT_00b5ac98 = 0;
  local_4._0_1_ = 4;
  _eh_vector_destructor_iterator_(in_ECX + 0x1b,0xb4,5,FUN_006ef6d0);
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_00713b10(local_10,*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10]);
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_00713500 @ 0x00713500 ====

void FUN_00713500(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098fa75;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ebafc;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  in_ECX[2] = 0;
  in_ECX[4] = 0;
  iVar1 = FUN_0058d7c0();
  in_ECX[6] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[6] + 4) = in_ECX[6];
  *(undefined4 *)in_ECX[6] = in_ECX[6];
  *(undefined4 *)(in_ECX[6] + 8) = in_ECX[6];
  in_ECX[7] = 0;
  local_4._0_1_ = 1;
  iVar1 = FUN_0058d7c0();
  in_ECX[9] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[9] + 4) = in_ECX[9];
  *(undefined4 *)in_ECX[9] = in_ECX[9];
  *(undefined4 *)(in_ECX[9] + 8) = in_ECX[9];
  in_ECX[10] = 0;
  local_4._0_1_ = 2;
  iVar1 = FUN_004be3a0();
  in_ECX[0xc] = iVar1;
  *(undefined1 *)(iVar1 + 0x3d) = 1;
  *(undefined4 *)(in_ECX[0xc] + 4) = in_ECX[0xc];
  *(undefined4 *)in_ECX[0xc] = in_ECX[0xc];
  *(undefined4 *)(in_ECX[0xc] + 8) = in_ECX[0xc];
  in_ECX[0xd] = 0;
  local_4._0_1_ = 3;
  in_ECX[0xe] = 0;
  iVar1 = FUN_0058d7c0();
  in_ECX[0x10] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0x10] + 4) = in_ECX[0x10];
  *(undefined4 *)in_ECX[0x10] = in_ECX[0x10];
  *(undefined4 *)(in_ECX[0x10] + 8) = in_ECX[0x10];
  in_ECX[0x11] = 0;
  local_4._0_1_ = 4;
  in_ECX[0x12] = 0;
  _eh_vector_constructor_iterator_
            (in_ECX + 0x1b,0xb4,5,(_func_void_void_ptr *)&LAB_007137d0,FUN_006ef6d0);
  local_4 = CONCAT31(local_4._1_3_,5);
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ac98 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ac98 = in_ECX;
  }
  FUN_00713170();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00713640 @ 0x00713640 ====

void FUN_00713640(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x3d);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x3d);
  }
  return;
}


// ==== FUN_00713660 @ 0x00713660 ====

void FUN_00713660(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x3d) == '\0') {
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


// ==== FUN_007136c0 @ 0x007136c0 ====

void FUN_007136c0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x3d) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x3d) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x3d);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x3d);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x3d);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x3d);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_00713710 @ 0x00713710 ====

void FUN_00713710(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x3d) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x3d) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x3d);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x3d);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x3d) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x3d) == '\0');
    if (*(char *)((int)piVar4 + 0x3d) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_00713770 @ 0x00713770 ====

undefined4 FUN_00713770(void)

{
  return 0x70210012;
}


// ==== FUN_00713780 @ 0x00713780 ====

undefined4 FUN_00713780(void)

{
  return 0x70210013;
}


// ==== FUN_00713790 @ 0x00713790 ====

void FUN_00713790(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00713790(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00713800 @ 0x00713800 ====

void FUN_00713800(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x2c) < 0x10) {
    *(undefined4 *)(in_ECX + 0x2c) = 0xf;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined1 *)(in_ECX + 0x18) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_00713830 @ 0x00713830 ====

void FUN_00713830(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x38) < 0x10) {
    *(undefined4 *)(in_ECX + 0x38) = 0xf;
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined1 *)(in_ECX + 0x24) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x24));
  return;
}


// ==== FUN_00713860 @ 0x00713860 ====

/* WARNING: Removing unreachable block (ram,0x00713973) */
/* WARNING: Removing unreachable block (ram,0x00713983) */
/* WARNING: Removing unreachable block (ram,0x0071398c) */
/* WARNING: Removing unreachable block (ram,0x0071398f) */
/* WARNING: Removing unreachable block (ram,0x0071397f) */
/* WARNING: Removing unreachable block (ram,0x0071399d) */
/* WARNING: Removing unreachable block (ram,0x007139aa) */
/* WARNING: Removing unreachable block (ram,0x007139b5) */
/* WARNING: Removing unreachable block (ram,0x007139b1) */
/* WARNING: Removing unreachable block (ram,0x007139a5) */
/* WARNING: Removing unreachable block (ram,0x007139b8) */

void FUN_00713860(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0098faa8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x15) != '\0') {
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
  FUN_00458720();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x15) == '\0') {
    if (*(char *)(param_2[2] + 0x15) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x15) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x15) == '\0') {
      piVar3 = (int *)FUN_004cf3b0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x15) == '\0') {
      uVar4 = FUN_004489e0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[5] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[5] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[5] == '\0') {
            *(undefined1 *)(piVar5 + 5) = 1;
            *(undefined1 *)(piVar3 + 5) = 0;
            FUN_00448a00(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            if ((*(char *)(*piVar5 + 0x14) == '\x01') && (*(char *)(piVar5[2] + 0x14) == '\x01'))
            goto LAB_00713a85;
            if (*(char *)(piVar5[2] + 0x14) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x14) = 1;
              *(undefined1 *)(piVar5 + 5) = 0;
              FUN_00519c40(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 5) = (char)piVar3[5];
            *(undefined1 *)(piVar3 + 5) = 1;
            *(undefined1 *)(piVar5[2] + 0x14) = 1;
            FUN_00448a00(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[5] == '\0') {
            *(undefined1 *)(piVar5 + 5) = 1;
            *(undefined1 *)(piVar3 + 5) = 0;
            FUN_00519c40(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            if ((*(char *)(piVar5[2] + 0x14) != '\x01') || (*(char *)(*piVar5 + 0x14) != '\x01')) {
              if (*(char *)(*piVar5 + 0x14) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x14) = 1;
                *(undefined1 *)(piVar5 + 5) = 0;
                FUN_00448a00(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 5) = (char)piVar3[5];
              *(undefined1 *)(piVar3 + 5) = 1;
              *(undefined1 *)(*piVar5 + 0x14) = 1;
              FUN_00519c40(piVar3);
              break;
            }
LAB_00713a85:
            *(undefined1 *)(piVar5 + 5) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 5) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_00713b10 @ 0x00713b10 ====

void FUN_00713b10(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00713790(piVar6[1]);
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
    FUN_00713860(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00713bd0 @ 0x00713bd0 ====

/* WARNING: Removing unreachable block (ram,0x00713ce0) */
/* WARNING: Removing unreachable block (ram,0x00713cf1) */
/* WARNING: Removing unreachable block (ram,0x00713cfa) */
/* WARNING: Removing unreachable block (ram,0x00713cfd) */
/* WARNING: Removing unreachable block (ram,0x00713ced) */
/* WARNING: Removing unreachable block (ram,0x00713d0b) */
/* WARNING: Removing unreachable block (ram,0x00713d18) */
/* WARNING: Removing unreachable block (ram,0x00713d23) */
/* WARNING: Removing unreachable block (ram,0x00713d1f) */
/* WARNING: Removing unreachable block (ram,0x00713d13) */
/* WARNING: Removing unreachable block (ram,0x00713d26) */

void FUN_00713bd0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0098faa8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x3d) != '\0') {
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
  FUN_007136c0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x3d) == '\0') {
    if (*(char *)(param_2[2] + 0x3d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x3d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x3d) == '\0') {
      piVar3 = (int *)FUN_00713640(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x3d) == '\0') {
      uVar4 = FUN_004bdeb0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xf] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xf] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xf] == '\0') {
            *(undefined1 *)(piVar5 + 0xf) = 1;
            *(undefined1 *)(piVar3 + 0xf) = 0;
            FUN_004be0c0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x3d) == '\0') {
            if ((*(char *)(*piVar5 + 0x3c) == '\x01') && (*(char *)(piVar5[2] + 0x3c) == '\x01'))
            goto LAB_00713df7;
            if (*(char *)(piVar5[2] + 0x3c) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x3c) = 1;
              *(undefined1 *)(piVar5 + 0xf) = 0;
              FUN_00713660(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xf) = (char)piVar3[0xf];
            *(undefined1 *)(piVar3 + 0xf) = 1;
            *(undefined1 *)(piVar5[2] + 0x3c) = 1;
            FUN_004be0c0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xf] == '\0') {
            *(undefined1 *)(piVar5 + 0xf) = 1;
            *(undefined1 *)(piVar3 + 0xf) = 0;
            FUN_00713660(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x3d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x3c) != '\x01') || (*(char *)(*piVar5 + 0x3c) != '\x01')) {
              if (*(char *)(*piVar5 + 0x3c) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x3c) = 1;
                *(undefined1 *)(piVar5 + 0xf) = 0;
                FUN_004be0c0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xf) = (char)piVar3[0xf];
              *(undefined1 *)(piVar3 + 0xf) = 1;
              *(undefined1 *)(*piVar5 + 0x3c) = 1;
              FUN_00713660(piVar3);
              break;
            }
LAB_00713df7:
            *(undefined1 *)(piVar5 + 0xf) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xf) = 1;
  }
  if ((uint)param_2[0xe] < 0x10) {
    param_2[0xe] = 0xf;
    param_2[0xd] = 0;
    *(undefined1 *)(param_2 + 9) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[9]);
  return;
}


// ==== FUN_00713ea0 @ 0x00713ea0 ====

void FUN_00713ea0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x3d) == '\0') {
    FUN_00713ea0(*(undefined4 *)((int)param_1 + 8));
    FUN_00713830();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00713ee0 @ 0x00713ee0 ====

undefined4 *
FUN_00713ee0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0098fa91;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x40);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    FUN_005386a0(param_4 + 1);
    *(undefined1 *)(puVar1 + 0xf) = param_5;
    *(undefined1 *)((int)puVar1 + 0x3d) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@00713f66 @ 0x00713f66 ====

void Catch_00713f66(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00713f80 @ 0x00713f80 ====

void FUN_00713f80(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0098faa8;
  local_c = ExceptionList;
  if (0x5555553 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00713ee0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x3c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x3c) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xf] == '\0') {
LAB_00714079:
        *(undefined1 *)(*piVar5 + 0x3c) = 1;
        *(undefined1 *)(piVar6 + 0xf) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x3c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004be0c0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x3c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x3c) = 0;
        FUN_00713660(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0xf] == '\0') goto LAB_00714079;
      if (piVar7 == (int *)*piVar2) {
        FUN_00713660(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x3c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x3c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x3d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x3c);
  } while( true );
}


// ==== FUN_00714160 @ 0x00714160 ====

void FUN_00714160(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00713ea0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x3d) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x3d) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x3d);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x3d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x3d);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x3d);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00713bd0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00714220 @ 0x00714220 ====

void FUN_00714220(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x3d) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x3d) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00713f80(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_00713710();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00713f80(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_007142e0 @ 0x007142e0 ====

void FUN_007142e0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00713b10(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00714310 @ 0x00714310 ====

void FUN_00714310(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00714160(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00714340 @ 0x00714340 ====

void FUN_00714340(byte param_1)

{
  void *in_ECX;
  
  FUN_007133d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00714360 @ 0x00714360 ====

void FUN_00714360(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ebc34;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b1a4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b1a4 = in_ECX;
  return;
}


// ==== FUN_007143b0 @ 0x007143b0 ====

undefined4 FUN_007143b0(void)

{
  code *pcVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 *puVar5;
  undefined4 extraout_EAX_00;
  uint uVar6;
  int *piVar7;
  undefined4 extraout_EAX_01;
  char *pcVar8;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 *unaff_EBX;
  uint uVar9;
  undefined4 local_260;
  void *local_25c;
  void *local_258;
  uint uStack_24c;
  uint local_248;
  void *local_244;
  undefined1 local_240 [4];
  undefined1 local_23c;
  uint uStack_230;
  undefined4 local_22c;
  undefined4 local_228 [5];
  char local_214 [256];
  undefined4 *local_114;
  undefined1 local_110;
  undefined1 local_10f;
  undefined1 local_10e;
  char local_10c [248];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098fb25;
  pvStack_c = ExceptionList;
  local_228[0] = 0xf;
  local_22c = 0;
  local_23c = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Map_23_Siege__009ebbc8,0xd);
  local_4 = 0;
  FUN_004020e0(s_BRICK_23_Siege_csv_009ebbd8,0x12);
  uVar4 = FUN_00402220(&local_25c,local_240,s_Loading____009ebbec);
  local_4._0_1_ = 1;
  FUN_00796d50(uVar4);
  local_4 = (uint)local_4._1_3_ << 8;
  if ((void *)0xf < local_244) {
    _free(local_258);
    return extraout_EAX;
  }
  local_260 = operator_new(0x10);
  local_4._0_1_ = 2;
  if (local_260 == (void *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5 = (undefined4 *)FUN_0081d3a0(local_240);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  local_260 = puVar5;
  if (puVar5 == (undefined4 *)0x0) {
    local_244 = (void *)0xf;
    local_248 = 0;
    local_258 = (void *)((uint)local_258 & 0xffffff00);
    FUN_00401740(s_pReader____NULL_009ebbf8,0xf);
    local_4._0_1_ = 3;
    FUN_00406880(&local_25c);
    local_4 = (uint)local_4._1_3_ << 8;
    if (local_244 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    _free(local_258);
    return extraout_EAX_00;
  }
  local_214[0] = '\0';
  FUN_0044a580(local_10c,&DAT_009ebc28,s_BrickLocate_009ebc08);
  uVar6 = 0;
  do {
    local_214[uVar6] = local_10c[uVar6];
    if (local_10c[uVar6] == '\0') goto LAB_0071450f;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x100);
  local_214[0] = '\0';
LAB_0071450f:
  local_110 = 10;
  local_10f = 0x2c;
  local_10e = 1;
  local_114 = puVar5;
  piVar7 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_214);
  if (piVar7 == (int *)0x0) {
    local_248 = 0xf;
    uStack_24c = 0;
    local_25c = (void *)((uint)local_25c & 0xffffff00);
    FUN_00401740(s_pTable_009ebc14,6);
    puStack_8._0_1_ = 4;
    FUN_00406880(&local_260);
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    if (local_248 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    _free(local_25c);
    return extraout_EAX_01;
  }
  uVar9 = 1;
  uVar6 = (**(code **)(*piVar7 + 8))();
  if (1 < uVar6) {
    do {
      pcVar8 = (char *)(**(code **)(*piVar7 + 0x10))(uVar9,1);
      FUN_0044a580(local_214 + 0xfc,&DAT_009ebc28,&DAT_0099cf70);
      uVar6 = 0;
      iVar2 = 0xfc - (int)pcVar8;
      do {
        if (*pcVar8 != pcVar8[(int)(local_214 + iVar2)]) {
          uVar6 = FUN_004756e0(uVar9,0);
          uVar3 = FUN_00475a90(uVar9,1);
          local_22c = CONCAT22(local_22c._2_2_,uVar3);
          uStack_230 = uVar6;
          FUN_007148f0(local_228,&uStack_230);
          break;
        }
        if (*pcVar8 == '\0') break;
        uVar6 = uVar6 + 1;
        pcVar8 = pcVar8 + 1;
      } while (uVar6 < 0x100);
      uVar9 = uVar9 + 1;
      uVar6 = (**(code **)(*piVar7 + 8))();
    } while (uVar9 < uVar6);
    puVar5 = unaff_EBX;
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar7);
  if (puVar5 != (undefined4 *)0x0) {
    (**(code **)*puVar5)(1);
  }
  uVar4 = FUN_00402220(local_240 + -0x24,&local_248,s_Loading_OK_009ebc1c);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);
  FUN_00796d50(uVar4);
  if (0xf < uStack_24c) {
    _free(local_260);
    return extraout_EAX_02;
  }
  if (uStack_230 < 0x10) {
    ExceptionList = pvStack_14;
    return 1;
  }
  _free(local_244);
  return extraout_EAX_03;
}


// ==== FUN_007146e0 @ 0x007146e0 ====

void FUN_007146e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ebc34;
  DAT_00b5b1a4 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00714710 @ 0x00714710 ====

void FUN_00714710(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0098fac8;
  local_c = ExceptionList;
  if (0x1ffffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00448a90(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[5] == '\0') {
LAB_00714809:
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
      if ((char)piVar6[5] == '\0') goto LAB_00714809;
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


// ==== FUN_007148f0 @ 0x007148f0 ====

void FUN_007148f0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00714710(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00714710(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_007149b0 @ 0x007149b0 ====

void FUN_007149b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ebc7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007149e0 @ 0x007149e0 ====

void FUN_007149e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ebc88;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b17c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b17c = in_ECX;
  return;
}


// ==== FUN_00714a10 @ 0x00714a10 ====

void FUN_00714a10(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = (**(code **)(*DAT_00b5b180 + 8))(*(undefined4 *)(param_1 + 0x10));
  piVar2 = DAT_00b5b180;
  piVar1 = DAT_00b5ac98;
  if (iVar3 != 0) {
    uVar4 = (**(code **)(*DAT_00b5ac1c + 0x3c))(param_1 + 0x18);
    uVar4 = (**(code **)(*piVar1 + 4))(*(undefined4 *)(param_1 + 0x10),uVar4);
    uVar4 = (**(code **)(*piVar2 + 8))(*(undefined4 *)(param_1 + 0x10),uVar4);
    FUN_00827d10(uVar4);
    (**(code **)(*DAT_00b5add0 + 0x50))();
    (**(code **)(*DAT_00b5add0 + 0x54))();
    (**(code **)(*DAT_00b5adc8 + 0x10))();
  }
  return;
}


// ==== FUN_00714ab0 @ 0x00714ab0 ====

void FUN_00714ab0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b17c = 0;
  *in_ECX = &PTR_FUN_009ebc7c;
  return;
}


// ==== FUN_00714ad0 @ 0x00714ad0 ====

void FUN_00714ad0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_58 [4];
  undefined1 uStack_54;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int *piStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_26 [2];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098fb38;
  pvStack_c = ExceptionList;
  iVar2 = 0;
  ExceptionList = &pvStack_c;
  switch(*(undefined1 *)(param_1 + 0x38)) {
  case 0:
    uStack_3c = 1;
    iStack_40 = 0x714b15;
    ExceptionList = &pvStack_c;
    piVar1 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
    iStack_40 = param_1 + 0x10;
    piStack_44 = (int *)0x714b22;
    (**(code **)(*piVar1 + 8))();
    uStack_48 = 0x714b2e;
    piStack_44 = piVar1;
    uStack_48 = (**(code **)(*DAT_00b5a980 + 8))();
    uStack_4c = 0x714b34;
    FUN_00827e80();
    piStack_44 = (int *)0x714b42;
    (**(code **)(*DAT_00b5a78c + 0x6c))();
    piStack_44 = *(int **)(param_1 + 0x34);
    uStack_48 = 0x714b51;
    uStack_3c = (**(code **)(*DAT_00b5ac98 + 4))();
    iStack_40 = 0x714b57;
    FUN_00827dd0();
    iVar2 = 0x2bc0059;
    break;
  case 1:
    iVar2 = 0x2bc0050;
    ExceptionList = &pvStack_c;
    break;
  case 2:
    iVar2 = 0x2bc0051;
    ExceptionList = &pvStack_c;
    break;
  case 3:
    iVar2 = 0x2bc0058;
    ExceptionList = &pvStack_c;
    break;
  case 4:
    iVar2 = 0x2bc0057;
    ExceptionList = &pvStack_c;
    break;
  case 5:
    iVar2 = 0x2bc0053;
    ExceptionList = &pvStack_c;
    break;
  case 6:
    iVar2 = 0x2bc0056;
    ExceptionList = &pvStack_c;
    break;
  case 7:
    iVar2 = 0x2bc0055;
    ExceptionList = &pvStack_c;
    break;
  case 8:
    iVar2 = 0x2bc0052;
    ExceptionList = &pvStack_c;
    break;
  case 9:
    iVar2 = 0x2bc0054;
    ExceptionList = &pvStack_c;
  }
  (**(code **)(*DAT_00b5add0 + 0x50))();
  (**(code **)(*DAT_00b5add0 + 0x54))();
  if (iVar2 != 0) {
    uStack_3c = 8;
    iStack_40 = 0x714bc6;
    uStack_48 = (**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_40 = 0xffffffff;
    piStack_44 = (int *)0x0;
    uStack_4c = 0x714be4;
    FUN_00401660();
    puStack_4 = auStack_58;
    iStack_40 = 0xf;
    piStack_44 = (int *)0x0;
    pvStack_c = (void *)0x0;
    uStack_54 = 0;
    FUN_00401660(auStack_26 + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_10) {
      uStack_3c = 0x714c25;
      _free(pvStack_24);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00714c70 @ 0x00714c70 ====

undefined4 FUN_00714c70(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x528000c) {
    FUN_00714a10(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x528000e) {
    FUN_00714ad0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x5280012) {
    (**(code **)(*DAT_00b5b180 + 0x10))
              (*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10),*(int *)(param_1 + 0xc) + 0x14);
    return 1;
  }
  return 0;
}


// ==== FUN_00714ce0 @ 0x00714ce0 ====

undefined4 FUN_00714ce0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00714c70(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00714d10 @ 0x00714d10 ====

void FUN_00714d10(byte param_1)

{
  void *in_ECX;
  
  FUN_00714ab0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00714d30 @ 0x00714d30 ====

void FUN_00714d30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ebdb4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00714d50 @ 0x00714d50 ====

void FUN_00714d50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ebdd0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b180 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b180 = in_ECX;
  return;
}


// ==== FUN_00714d80 @ 0x00714d80 ====

void FUN_00714d80(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return;
  }
  piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
  uVar2 = (**(code **)(*piVar1 + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::ISentry::RTTI_Type_Descriptor,0);
  FUN_00803725(uVar2);
  return;
}


// ==== FUN_00714dc0 @ 0x00714dc0 ====

void FUN_00714dc0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b180 = 0;
  *in_ECX = &PTR_FUN_009ebdb4;
  return;
}


// ==== FUN_00714de0 @ 0x00714de0 ====

void FUN_00714de0(undefined4 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x528000d;
  *(undefined2 *)((int)pvVar2 + 6) = 0x14;
  iVar3 = FUN_004244d0();
  *(undefined4 *)(iVar3 + 0x10) = param_1;
  FUN_004d8570();
  return;
}


// ==== FUN_00714e30 @ 0x00714e30 ====

int FUN_00714e30(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  int unaff_retaddr;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5abc0 + 8))(param_2);
  if (piVar2 == (int *)0x0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(&DAT_009ebcca,0);
    return unaff_retaddr;
  }
  iVar3 = (**(code **)(*piVar2 + 4))();
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  pcVar4 = (char *)(iVar3 + 2);
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar3 + 2),(int)pcVar4 - (iVar3 + 3));
  return unaff_retaddr;
}


// ==== FUN_00714ec0 @ 0x00714ec0 ====

void FUN_00714ec0(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098fb58;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x3c))();
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    while (iVar3 != 0) {
      (**(code **)(*DAT_00b5abf8 + 8))(iVar3);
      iVar3 = (**(code **)(*piVar2 + 0x10))();
    }
    (**(code **)(*piVar2 + 0x18))();
    ExceptionList = pvStack_c;
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pSentryTree____NULL_009ebd88,0x13);
  uStack_4 = 0;
  FUN_00406880(auStack_28);
  uStack_4 = 0xffffffff;
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_00714f90 @ 0x00714f90 ====

void FUN_00714f90(uint param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined2 uStack_3a;
  uint uStack_34;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098fb6a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar4 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x3c))();
  uVar6 = 0;
  if (piVar4 == (int *)0x0) {
    pvStack_10 = (void *)0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pSentryTree____NULL_009ebccc,0x13);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (pvStack_10 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  FUN_00714ec0();
  if (param_1 != 0) {
    do {
      uVar2 = *param_2;
      uVar1 = *(undefined2 *)(param_2 + 1);
      uStack_30 = (undefined2)uVar2;
      uStack_34 = uVar6;
      uStack_2e = (**(code **)(*DAT_00b5ae14 + 0x18))();
      uStack_3a = (undefined2)((uint)uVar2 >> 0x10);
      uStack_2c = uStack_3a;
      uStack_2a = uVar1;
      iVar5 = (**(code **)(*DAT_00b5abf8 + 4))(&uStack_34);
      if (iVar5 == 0) {
        ExceptionList = pvStack_10;
        return;
      }
      (**(code **)(*piVar4 + 4))(iVar5);
      uVar6 = uVar6 + 1;
      param_2 = (undefined4 *)((int)param_2 + 6);
    } while (uVar6 < param_1);
  }
  (**(code **)(*DAT_00b5add0 + 0x50))();
  (**(code **)(*DAT_00b5add0 + 0x54))();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_007150c0 @ 0x007150c0 ====

void FUN_007150c0(void)

{
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098fb8c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00714ec0();
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401740(s__________________________________009ebce0,0x36);
  local_4 = 0;
  FUN_00403e50(local_44);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401740(s____________________Sentry_Tree_D_009ebd18,0x36);
  local_4 = 1;
  FUN_00403e50(local_44);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s__________________________________009ebd50,0x36);
  local_4 = 2;
  FUN_00403e50(local_28);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_007151e0 @ 0x007151e0 ====

void FUN_007151e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00714dc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00715200 @ 0x00715200 ====

void FUN_00715200(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ebfd4;
  return;
}


// ==== FUN_00715210 @ 0x00715210 ====

void FUN_00715210(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ebfd4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00715230 @ 0x00715230 ====

void FUN_00715230(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x0071523d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x18))();
  return;
}


// ==== FUN_00715240 @ 0x00715240 ====

void FUN_00715240(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\x01') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009ec008;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 4) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_00715280 @ 0x00715280 ====

void FUN_00715280(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009ec01c;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 4) = 0;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_007152c0 @ 0x007152c0 ====

void FUN_007152c0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 5) != '\x01') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009ec030;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 5) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 5) = 1;
  }
  return;
}


// ==== FUN_00715300 @ 0x00715300 ====

void FUN_00715300(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 5) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009ec044;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 5) = 0;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 5) = 0;
  }
  return;
}


// ==== FUN_00715340 @ 0x00715340 ====

void FUN_00715340(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  if ((char)in_ECX[1] == '\x01') {
    (**(code **)(*in_ECX + 0x10))();
  }
  if (*(char *)((int)in_ECX + 5) == '\0') {
    (**(code **)(*in_ECX + 0x14))();
  }
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ec06c;
  }
  FUN_00797a20(puVar1);
  FUN_004dd240(0x16,0xb,0,0,0);
  return;
}


// ==== FUN_00715390 @ 0x00715390 ====

void FUN_00715390(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    puVar1 = operator_new(8);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009ec058;
      puVar1[1] = param_1;
      FUN_00797a20(puVar1);
      return;
    }
    FUN_00797a20(0);
  }
  return;
}


// ==== FUN_00715400 @ 0x00715400 ====

void FUN_00715400(void)

{
  int iVar1;
  int *piVar2;
  short *psVar3;
  undefined4 *puVar4;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x14))();
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x48) + 0x28))();
    psVar3 = (short *)(**(code **)(*piVar2 + 8))();
    if (*psVar3 == 1) {
      puVar4 = operator_new(4);
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = &PTR_FUN_009ec06c;
        FUN_00797a20(puVar4);
        return;
      }
      FUN_00797a20(0);
    }
  }
  return;
}


// ==== FUN_00715460 @ 0x00715460 ====

void FUN_00715460(void)

{
  undefined4 *in_ECX;
  uint unaff_EBX;
  void *unaff_EBP;
  uint unaff_ESI;
  void *unaff_EDI;
  undefined1 auStackY_100 [112];
  void *_Memory;
  undefined1 auStack_66 [2];
  undefined1 *puStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_46 [2];
  uint local_44;
  void *local_40;
  uint uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 local_30;
  uint local_2c;
  undefined1 uStack_24;
  undefined1 uStack_1c;
  undefined1 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098fbe0;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ec080;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ae6c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ae6c = in_ECX;
  }
  uStack_5c = 0x10;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401740();
  uStack_5c = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
  if (0xf < uStack_34) {
    _free(in_ECX);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  FUN_00401740();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  uStack_14 = 0;
  if (0xf < uStack_3c) {
    _free(unaff_EBP);
    return;
  }
  uStack_3c = 0xf;
  local_40 = (void *)0x0;
  FUN_00401740(s_qnotice_showalarm_009ebe4c);
  uStack_14 = 3;
  (**(code **)(*DAT_00b5a6c8 + 0xc))(auStack_46 + -0xe);
  uStack_1c = 0;
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  FUN_00401740(s_qnotice_hidealarm_009ebe60,0x11);
  _Memory = (void *)0x0;
  uStack_1c = 4;
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&uStack_5c);
  uStack_24 = 0;
  if (0xf < unaff_EBX) {
    _free(&local_44);
    return;
  }
  puStack_60 = auStackY_100;
  FUN_00401740(s_qnotice_refreshall_009ebe74,0x12);
  uStack_24 = 5;
  (**(code **)(*DAT_00b5a6c8 + 0xc))(auStack_66 + 2,0);
  local_2c = local_2c & 0xffffff00;
  if (0xf < unaff_ESI) {
    _free(auStack_46 + -6);
    return;
  }
  uStack_38 = 0xf;
  uStack_3c = 0;
  FUN_00401740(s__QUESTID___DWORD___RESULT___DWOR_009ebe88,0x22);
  local_2c._0_1_ = 6;
  FUN_00401740(s_qnotice_refreshresult_009ebeac,0x15);
  local_2c = CONCAT31(local_2c._1_3_,7);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_66 + -6,2,auStack_46 + -10);
  if ((undefined1 *)0xf < puStack_60) {
    _free(_Memory);
    return;
  }
  if (local_44 < 0x10) {
    ExceptionList = local_40;
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_007156c0 @ 0x007156c0 ====

void FUN_007156c0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined4 local_2c;
  void *local_28;
  void *local_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098fc22;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ec080;
  local_4 = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_2c = in_ECX;
  FUN_00401740(s_qnotice_showinfo_009ebec4,0x10);
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
  FUN_00401740(s_qnotice_hideinfo_009ebed8,0x10);
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
  FUN_00401740(s_qnotice_showalarm_009ebeec,0x11);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x30);
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(unaff_EBX);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  FUN_00401740(s_qnotice_hidealarm_009ebf00,0x11);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x34);
  local_14 = local_14 & 0xffffff00;
  if (0xf < uStack_20) {
    _free(unaff_EBP);
    return;
  }
  uStack_20 = 0xf;
  local_24 = (void *)0x0;
  FUN_00401740(s_qnotice_refreshall_009ebf14,0x12);
  local_14 = CONCAT31(local_14._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x38);
  uStack_18 = uStack_18 & 0xffffff00;
  if (0xf < local_24) {
    _free(unaff_ESI);
    return;
  }
  local_24 = (void *)0xf;
  local_28 = (void *)0x0;
  FUN_00401740(s_qnotice_refreshresult_009ebf28,0x15);
  uStack_18 = CONCAT31(uStack_18._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x3c);
  if (local_28 < (void *)0x10) {
    DAT_00b5ae6c = 0;
    *in_ECX = &PTR_FUN_009ebfd4;
    ExceptionList = local_24;
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_007158d0 @ 0x007158d0 ====

undefined4 FUN_007158d0(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098fc34;
  local_c = ExceptionList;
  iVar1 = param_1 + 8;
  ExceptionList = &local_c;
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_qnotice_showinfo_009ebf40,0x10);
  if (iVar3 == 0) {
    (**(code **)(*in_ECX + 0xc))();
    ExceptionList = local_c;
    return 1;
  }
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_qnotice_hideinfo_009ebf54,0x10);
  if (iVar3 == 0) {
    (**(code **)(*in_ECX + 0x10))();
    ExceptionList = local_c;
    return 1;
  }
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_qnotice_showalarm_009ebf68,0x11);
  if (iVar3 == 0) {
    (**(code **)(*in_ECX + 0x14))();
    ExceptionList = local_c;
    return 1;
  }
  cVar2 = FUN_004036a0(iVar1,s_qnotice_hidealarm_009ebf7c);
  if (cVar2 != '\0') {
    (**(code **)(*in_ECX + 0x18))();
    ExceptionList = local_c;
    return 1;
  }
  cVar2 = FUN_004036a0(iVar1,s_qnotice_refreshall_009ebf90);
  if (cVar2 != '\0') {
    (**(code **)(*in_ECX + 0x1c))();
    ExceptionList = local_c;
    return 1;
  }
  cVar2 = FUN_004036a0(iVar1,s_qnotice_refreshresult_009ebfa4);
  if (cVar2 != '\0') {
    uVar4 = FUN_00459160(local_28,0);
    local_4 = 0;
    thunk_FUN_00796fb0(uVar4);
    local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_00715a70 @ 0x00715a70 ====

undefined4 FUN_00715a70(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_007158d0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00715aa0 @ 0x00715aa0 ====

undefined4 FUN_00715aa0(void)

{
  return 0x70440000;
}


// ==== FUN_00715ab0 @ 0x00715ab0 ====

undefined4 FUN_00715ab0(void)

{
  return 0x70440001;
}


// ==== FUN_00715ac0 @ 0x00715ac0 ====

undefined4 FUN_00715ac0(void)

{
  return 0x70440002;
}


// ==== FUN_00715ad0 @ 0x00715ad0 ====

undefined4 FUN_00715ad0(void)

{
  return 0x70440003;
}


// ==== FUN_00715ae0 @ 0x00715ae0 ====

undefined4 FUN_00715ae0(void)

{
  return 0x70440004;
}


// ==== FUN_00715af0 @ 0x00715af0 ====

undefined4 FUN_00715af0(void)

{
  return 0x70440005;
}


// ==== FUN_00715b00 @ 0x00715b00 ====

void FUN_00715b00(byte param_1)

{
  void *in_ECX;
  
  FUN_007156c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00715b20 @ 0x00715b20 ====

void FUN_00715b20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec138;
  return;
}


// ==== FUN_00715b30 @ 0x00715b30 ====

void FUN_00715b30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec138;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00715b50 @ 0x00715b50 ====

void FUN_00715b50(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    piVar1 = *(int **)(in_ECX + 0x1c);
    for (piVar2 = *(int **)(in_ECX + 0x18); piVar2 != piVar1; piVar2 = piVar2 + 1) {
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
    }
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00715b80 @ 0x00715b80 ====

int * FUN_00715b80(undefined4 param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x1c);
  puVar4 = *(undefined4 **)(in_ECX + 0x18);
  while( true ) {
    if (puVar4 == puVar1) {
      return (int *)0x0;
    }
    piVar2 = (int *)*puVar4;
    cVar3 = (**(code **)(*piVar2 + 0x18))(param_1);
    if (cVar3 == '\x01') break;
    puVar4 = puVar4 + 1;
  }
  return piVar2;
}


// ==== FUN_00715bc0 @ 0x00715bc0 ====

void FUN_00715bc0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvStack_c = ExceptionList;
  puStack_8 = &LAB_0098fc53;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ec154;
  local_4 = 1;
  if (*(char *)(in_ECX + 1) != '\0') {
    piVar1 = (int *)in_ECX[7];
    for (piVar2 = (int *)in_ECX[6]; piVar2 != piVar1; piVar2 = piVar2 + 1) {
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
    }
    *(undefined1 *)(in_ECX + 1) = 0;
  }
  DAT_00b5ae70 = 0;
  if ((void *)in_ECX[6] == (void *)0x0) {
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    *in_ECX = &PTR_FUN_009ec138;
    ExceptionList = pvStack_c;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00715c50 @ 0x00715c50 ====

void FUN_00715c50(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098fc68;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar3 = operator_new(0x58);
  local_4 = 0;
  if (pvVar3 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_00788650(param_1);
  }
  iVar1 = *(int *)(in_ECX + 0x18);
  local_4 = 0xffffffff;
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x20) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x1c) - iVar1 >> 2)))
  {
    FUN_00716720(*(undefined4 *)(in_ECX + 0x1c),1,&param_1);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x1c);
    *puVar2 = param_1;
    *(undefined4 **)(in_ECX + 0x1c) = puVar2 + 1;
  }
  if (*(int *)(in_ECX + 0x18) == 0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    ExceptionList = local_c;
    return;
  }
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18) >> 2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00715d30 @ 0x00715d30 ====

void FUN_00715d30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec154;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ae70 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae70 = in_ECX;
  return;
}


// ==== FUN_00715d90 @ 0x00715d90 ====

/* WARNING: Removing unreachable block (ram,0x00716351) */
/* WARNING: Removing unreachable block (ram,0x007163cf) */
/* WARNING: Removing unreachable block (ram,0x00716451) */
/* WARNING: Removing unreachable block (ram,0x00715f86) */
/* WARNING: Removing unreachable block (ram,0x00716297) */
/* WARNING: Removing unreachable block (ram,0x0071622b) */
/* WARNING: Removing unreachable block (ram,0x007161bf) */
/* WARNING: Removing unreachable block (ram,0x00716150) */
/* WARNING: Removing unreachable block (ram,0x007160fb) */
/* WARNING: Removing unreachable block (ram,0x00716059) */
/* WARNING: Removing unreachable block (ram,0x0071655e) */
/* WARNING: Removing unreachable block (ram,0x00716563) */
/* WARNING: Removing unreachable block (ram,0x00716017) */
/* WARNING: Removing unreachable block (ram,0x00715e51) */
/* WARNING: Removing unreachable block (ram,0x00715f90) */
/* WARNING: Removing unreachable block (ram,0x0071658b) */
/* WARNING: Removing unreachable block (ram,0x007160b9) */
/* WARNING: Removing unreachable block (ram,0x007160ca) */
/* WARNING: Removing unreachable block (ram,0x00716033) */
/* WARNING: Removing unreachable block (ram,0x00716069) */
/* WARNING: Removing unreachable block (ram,0x00716467) */
/* WARNING: Removing unreachable block (ram,0x007164d0) */
/* WARNING: Removing unreachable block (ram,0x007164e0) */
/* WARNING: Removing unreachable block (ram,0x007164fe) */
/* WARNING: Removing unreachable block (ram,0x0071650e) */
/* WARNING: Removing unreachable block (ram,0x00716072) */
/* WARNING: Removing unreachable block (ram,0x0071659d) */
/* WARNING: Removing unreachable block (ram,0x0071607a) */
/* WARNING: Removing unreachable block (ram,0x00716097) */
/* WARNING: Removing unreachable block (ram,0x007165a6) */
/* WARNING: Removing unreachable block (ram,0x00716051) */
/* WARNING: Removing unreachable block (ram,0x00716594) */
/* WARNING: Removing unreachable block (ram,0x007160d9) */
/* WARNING: Removing unreachable block (ram,0x007165af) */
/* WARNING: Removing unreachable block (ram,0x0071612e) */
/* WARNING: Removing unreachable block (ram,0x007165b8) */
/* WARNING: Removing unreachable block (ram,0x0071619d) */
/* WARNING: Removing unreachable block (ram,0x007165c1) */
/* WARNING: Removing unreachable block (ram,0x00716209) */
/* WARNING: Removing unreachable block (ram,0x007165ca) */
/* WARNING: Removing unreachable block (ram,0x00716250) */
/* WARNING: Removing unreachable block (ram,0x00716271) */
/* WARNING: Removing unreachable block (ram,0x007162cc) */
/* WARNING: Removing unreachable block (ram,0x007162ae) */
/* WARNING: Removing unreachable block (ram,0x00716244) */
/* WARNING: Removing unreachable block (ram,0x007162f2) */
/* WARNING: Removing unreachable block (ram,0x0071633a) */
/* WARNING: Removing unreachable block (ram,0x0071637c) */
/* WARNING: Removing unreachable block (ram,0x007163bb) */
/* WARNING: Removing unreachable block (ram,0x007163f1) */
/* WARNING: Removing unreachable block (ram,0x00716433) */
/* WARNING: Removing unreachable block (ram,0x0071645e) */
/* WARNING: Removing unreachable block (ram,0x00715f43) */
/* WARNING: Removing unreachable block (ram,0x00716411) */
/* WARNING: Removing unreachable block (ram,0x00716399) */
/* WARNING: Removing unreachable block (ram,0x00716318) */

undefined4 FUN_00715d90(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int local_158;
  void *local_78;
  uint local_64;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098fd12;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00410500();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    local_158 = *(int *)(iVar1 + 0x40);
    iVar1 = *(int *)(iVar1 + 0x44);
    if (local_158 != iVar1) {
      do {
        FUN_00401660();
        local_4 = 1;
        FUN_00404fb0();
        FUN_00401740(s_Invalid_Line_____d__009ec0f4,0x14);
        FUN_00404230(local_28);
        local_4._0_1_ = 2;
        FUN_00405bd0();
        local_4 = CONCAT31(local_4._1_3_,3);
        FUN_00796d50();
        if (0xf < local_64) {
          _free(local_78);
          return extraout_EAX;
        }
        local_78 = (void *)((uint)local_78 & 0xffffff00);
        if (0xf < local_10) {
          _free(local_24);
          return extraout_EAX_00;
        }
        local_24 = (void *)((uint)local_24 & 0xffffff00);
        local_10 = 0xf;
        local_14 = 0;
        local_64 = 0xf;
        local_158 = local_158 + 0x1c;
        local_4 = 0xffffffff;
      } while (local_158 != iVar1);
    }
    (**(code **)(*DAT_00b5a7cc + 0x14))();
    uVar2 = 1;
  }
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_00716600 @ 0x00716600 ====

void FUN_00716600(undefined4 param_1)

{
  code *pcVar1;
  char cVar2;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098fd24;
  local_c = ExceptionList;
  if (*(char *)(in_ECX + 4) != '\x01') {
    ExceptionList = &local_c;
    cVar2 = FUN_00715d90(param_1);
    if (cVar2 == '\0') {
      FUN_00401830(s_FALSE_009ec0ec);
      local_4 = 0;
      FUN_00406880(local_28);
      if (local_10 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(local_24);
      return;
    }
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00716690 @ 0x00716690 ====

void FUN_00716690(void)

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
  puStack_8 = &LAB_0098fd38;
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


// ==== FUN_00716700 @ 0x00716700 ====

void FUN_00716700(byte param_1)

{
  void *in_ECX;
  
  FUN_00715bc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00716720 @ 0x00716720 ====

void FUN_00716720(void *param_1,uint param_2,undefined4 *param_3)

{
  size_t _Size;
  int iVar1;
  uint uVar2;
  void *_Dst;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  
  iVar5 = *(int *)(in_ECX + 4);
  param_3 = (undefined4 *)*param_3;
  if (iVar5 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar5 >> 2;
  }
  uVar7 = CONCAT44(iVar5,iVar1);
  if (param_2 != 0) {
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 2;
    }
    if (0x3fffffffU - iVar5 < param_2) {
      uVar7 = FUN_00716690();
    }
    iVar5 = (int)((ulonglong)uVar7 >> 0x20);
    uVar2 = (uint)uVar7;
    if (iVar5 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 2;
    }
    if (uVar2 < iVar1 + param_2) {
      if (0x3fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar5 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 2;
      }
      if (uVar2 < iVar1 + param_2) {
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 2;
        }
        uVar2 = iVar5 + param_2;
      }
      _Dst = operator_new(uVar2 * 4);
      _Size = ((int)param_1 - (int)*(void **)(in_ECX + 4) >> 2) * 4;
      pvVar3 = _memmove(_Dst,*(void **)(in_ECX + 4),_Size);
      pvVar3 = (void *)FUN_00845740((void *)((int)pvVar3 + _Size),param_2,&param_3);
      _memmove(pvVar3,param_1,(*(int *)(in_ECX + 8) - (int)param_1 >> 2) * 4);
      pvVar3 = *(void **)(in_ECX + 4);
      if (pvVar3 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - (int)pvVar3 >> 2;
      }
      if (pvVar3 == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)_Dst);
        *(void **)(in_ECX + 8) = (void *)((int)_Dst + (param_2 + iVar5) * 4);
        *(void **)(in_ECX + 4) = _Dst;
        return;
      }
      _free(pvVar3);
      return;
    }
    iVar1 = *(int *)(in_ECX + 8);
    iVar5 = param_2 * 4;
    if ((uint)(iVar1 - (int)param_1 >> 2) < param_2) {
      FUN_005a6d90(param_1,iVar1,(void *)(iVar5 + (int)param_1));
      FUN_00845740(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - (int)param_1 >> 2),
                   &param_3);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar5;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + param_2 * -4,&param_3);
      return;
    }
    iVar6 = iVar1 + param_2 * -4;
    uVar4 = FUN_005a6d90(iVar6,iVar1,iVar1);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00822d20(param_1,iVar6,iVar1);
    FUN_008335f0(param_1,(void *)(iVar5 + (int)param_1),&param_3);
  }
  return;
}


// ==== FUN_00716900 @ 0x00716900 ====

void FUN_00716900(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x48) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x48));
    return;
  }
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  if (*(int *)(in_ECX + 0x38) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x38),*(undefined4 *)(in_ECX + 0x3c),in_ECX + 0x34);
    _free(*(void **)(in_ECX + 0x38));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  if (*(int *)(in_ECX + 0x28) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x28),*(undefined4 *)(in_ECX + 0x2c),in_ECX + 0x24);
    _free(*(void **)(in_ECX + 0x28));
    return;
  }
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  if (*(uint *)(in_ECX + 0x20) < 0x10) {
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0xf;
    *(undefined1 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_007169b0 @ 0x007169b0 ====

void FUN_007169b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec1d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007169d0 @ 0x007169d0 ====

void FUN_007169d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec1e4;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b184 = (undefined4 *)0x0;
    DAT_00000000 = 0;
    *(undefined2 *)((int)in_ECX + 6) = 0;
    *(undefined2 *)(in_ECX + 2) = 0;
    in_ECX[3] = 0;
    return;
  }
  DAT_00b5b184 = in_ECX;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined2 *)((int)in_ECX + 6) = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_00716a10 @ 0x00716a10 ====

void FUN_00716a10(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b184 = 0;
  *in_ECX = &PTR_FUN_009ec1d4;
  return;
}


// ==== FUN_00716a30 @ 0x00716a30 ====

void FUN_00716a30(void)

{
  int iVar1;
  int *in_ECX;
  
  if ((DAT_00b5ae14 != 0) && (DAT_00b5a980 != (int *)0x0)) {
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      if (300 < (uint)(iVar1 - in_ECX[3])) {
        (**(code **)(*in_ECX + 8))();
        iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        in_ECX[3] = iVar1;
      }
    }
  }
  return;
}


// ==== FUN_00716a80 @ 0x00716a80 ====

uint FUN_00716a80(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00716a30(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00716ab0 @ 0x00716ab0 ====

undefined4 FUN_00716ab0(void)

{
  float fVar1;
  int iVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  float *pfVar9;
  int in_ECX;
  int iStack_50;
  undefined1 auStack_44 [24];
  undefined1 auStack_2c [20];
  void *pvStack_18;
  void *pvStack_14;
  void *local_c;
  undefined1 *puStack_8;
  int *piStack_4;
  
  piStack_4 = (int *)0xffffffff;
  puStack_8 = &LAB_0098fd60;
  local_c = ExceptionList;
  if ((*(short *)(in_ECX + 6) == 0) || (DAT_00b5a980 == (int *)0x0)) {
    return 0;
  }
  ExceptionList = &local_c;
  iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar5 == 0) {
    ExceptionList = local_c;
    return 0;
  }
  piVar8 = *(int **)(iVar5 + 0x78);
  if (piVar8 == (int *)0x0) {
    FUN_00401830(s_pCoolTimeManager____NULL_009ec170);
    piStack_4 = piVar8;
    FUN_00406880(auStack_44);
    piStack_4 = (int *)0xffffffff;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  piVar6 = (int *)(**(code **)(*piVar8 + 0x20))(0);
  if (piVar6 == (int *)0x0) {
    FUN_00401830(s_pCoolTime____NULL_009ec18c);
    puStack_8 = (undefined1 *)0x1;
    FUN_00406880(auStack_2c);
    puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  iVar2 = *piVar8;
  uVar7 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar2 + 0x18))(uVar7);
  cVar3 = (**(code **)(*piVar6 + 0xc))();
  if ((cVar3 == '\x01') && (*(int **)(iVar5 + 0x50) != (int *)0x0)) {
    iVar5 = **(int **)(iVar5 + 0x50);
    uVar7 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar8 = (int *)(**(code **)(iVar5 + 0x14))(uVar7);
    if (piVar8 != (int *)0x0) {
      pfVar9 = (float *)(**(code **)(*piVar8 + 0x18))();
      fVar1 = *pfVar9;
      iVar5 = (**(code **)(*piVar8 + 0x18))();
      if ((fVar1 != *(float *)(iVar5 + 0xc)) && (0.0 < fVar1)) {
        uVar4 = 0;
        if (0.0 < fVar1) {
          uVar4 = FUN_00802534();
        }
        if (uVar4 <= *(ushort *)(iStack_50 + 6)) {
          uVar4 = 0xf;
          do {
            iVar5 = (**(code **)(*DAT_00b5ad54 + 4))(uVar4);
            if (iVar5 != 0) {
              iVar5 = (**(code **)(*DAT_00b5ad20 + 0x18))(iVar5);
              if (iVar5 == 0x11) {
                (**(code **)(*DAT_00b5ad54 + 0x10))(uVar4);
                ExceptionList = pvStack_18;
                return 1;
              }
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < 0x12);
        }
      }
    }
  }
  ExceptionList = pvStack_14;
  return 0;
}


// ==== FUN_00716ca0 @ 0x00716ca0 ====

undefined4 FUN_00716ca0(void)

{
  float fVar1;
  int iVar2;
  code *pcVar3;
  char cVar4;
  ushort uVar5;
  int iVar6;
  undefined4 extraout_EAX;
  undefined4 uVar7;
  int *piVar8;
  undefined4 extraout_EAX_00;
  int *piVar9;
  int iStack_50;
  undefined1 local_48 [4];
  void *pvStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  void *pvStack_18;
  void *pvStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098fd7a;
  local_c = ExceptionList;
  if (DAT_00b5a980 == (int *)0x0) {
    return 0;
  }
  ExceptionList = &local_c;
  iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar6 == 0) {
    ExceptionList = local_c;
    return 0;
  }
  piVar9 = *(int **)(iVar6 + 0x78);
  if (piVar9 == (int *)0x0) {
    FUN_00401830(s_pCoolTimeManager____NULL_009ec1a0);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar3 = (code *)swi(3);
      uVar7 = (*pcVar3)();
      return uVar7;
    }
    _free(pvStack_24);
    return extraout_EAX;
  }
  piVar8 = (int *)(**(code **)(*piVar9 + 0x20))(0);
  if (piVar8 != (int *)0x0) {
    iVar2 = *piVar9;
    uVar7 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    (**(code **)(iVar2 + 0x18))(uVar7);
    cVar4 = (**(code **)(*piVar8 + 0xc))();
    if ((cVar4 == '\x01') && (*(int **)(iVar6 + 0x50) != (int *)0x0)) {
      iVar6 = **(int **)(iVar6 + 0x50);
      uVar7 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      piVar9 = (int *)(**(code **)(iVar6 + 0x14))(uVar7);
      if (piVar9 != (int *)0x0) {
        iVar6 = (**(code **)(*piVar9 + 0x18))();
        fVar1 = *(float *)(iVar6 + 4);
        iVar6 = (**(code **)(*piVar9 + 0x18))();
        if (fVar1 != *(float *)(iVar6 + 0x10)) {
          if (fVar1 <= DAT_0099cdc8) {
            uVar5 = 0;
          }
          else {
            uVar5 = FUN_00802534();
          }
          if (uVar5 <= *(ushort *)(iStack_50 + 8)) {
            uVar5 = 0xf;
            do {
              iVar6 = (**(code **)(*DAT_00b5ad54 + 4))(uVar5);
              if (iVar6 != 0) {
                iVar6 = (**(code **)(*DAT_00b5ad20 + 0x18))(iVar6);
                if (iVar6 == 0x12) {
                  (**(code **)(*DAT_00b5ad54 + 0x10))(uVar5);
                  ExceptionList = pvStack_18;
                  return 1;
                }
              }
              uVar5 = uVar5 + 1;
            } while (uVar5 < 0x12);
          }
        }
      }
    }
    ExceptionList = pvStack_14;
    return 0;
  }
  FUN_00401830(s_pCoolTime____NULL_009ec1bc);
  puStack_8 = (undefined1 *)0x1;
  FUN_00406880(local_48);
  puStack_8 = (undefined1 *)0xffffffff;
  if (uStack_30 < 0x10) {
    uStack_30 = 0xf;
    uStack_34 = 0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    pcVar3 = (code *)swi(3);
    uVar7 = (*pcVar3)();
    return uVar7;
  }
  _free(pvStack_44);
  return extraout_EAX_00;
}


// ==== FUN_00716ec0 @ 0x00716ec0 ====

void FUN_00716ec0(void)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = (**(code **)(*DAT_00b5a6e4 + 8))();
  *(undefined1 *)(in_ECX + 4) = *(undefined1 *)(iVar3 + 0x10);
  (**(code **)(*DAT_00b5a6e4 + 8))();
  uVar2 = FUN_00802534();
  *(undefined2 *)(in_ECX + 6) = uVar2;
  (**(code **)(*DAT_00b5a6e4 + 8))();
  uVar2 = FUN_00802534();
  *(undefined2 *)(in_ECX + 8) = uVar2;
  if (*(char *)(in_ECX + 4) != '\0') {
    cVar1 = FUN_00716ab0();
    if (cVar1 == '\0') {
      FUN_00716ca0();
      return;
    }
  }
  return;
}


// ==== FUN_00716f20 @ 0x00716f20 ====

void FUN_00716f20(byte param_1)

{
  void *in_ECX;
  
  FUN_00716a10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00716f40 @ 0x00716f40 ====

void FUN_00716f40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec4b8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00716f70 @ 0x00716f70 ====

void FUN_00716f70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec4c4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a9e8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a9e8 = in_ECX;
  return;
}


// ==== FUN_00716fb0 @ 0x00716fb0 ====

void FUN_00716fb0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a9e8 = 0;
  *in_ECX = &PTR_FUN_009ec4b8;
  return;
}


// ==== FUN_00716fd0 @ 0x00716fd0 ====

void FUN_00716fd0(int param_1)

{
  undefined1 auStack_70 [4];
  undefined1 uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_1c;
  void *pvStack_18;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0098fda0;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x10) == '\0') {
    uStack_54 = 5;
    uStack_58 = 0x7170a5;
    ExceptionList = &pvStack_c;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    pvStack_18 = (void *)0xf;
    uStack_1c = 0;
    uStack_2c = uStack_2c & 0xffffff00;
    uStack_64 = 0x7170c3;
    FUN_00401660();
    puStack_4 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_c = (void *)0x0;
    uStack_6c = 0;
    FUN_00401660(&uStack_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    puStack_4 = (undefined1 *)0xffffffff;
    if (0xf < uStack_10) {
      uStack_54 = 0x71710c;
      _free(pvStack_24);
      return;
    }
  }
  else {
    ExceptionList = &pvStack_c;
    if (*(char *)(param_1 + 0x10) == '\x01') {
      uStack_54 = 5;
      uStack_58 = 0x717017;
      ExceptionList = &pvStack_c;
      uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_58 = 0xffffffff;
      uStack_5c = 0;
      uStack_64 = 0x717035;
      FUN_00401660();
      puStack_4 = auStack_70;
      uStack_58 = 0xf;
      uStack_5c = 0;
      pvStack_c = (void *)0x1;
      uStack_6c = 0;
      FUN_00401660(auStack_70 + 0x24,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      puStack_4 = (undefined1 *)0xffffffff;
      if (0xf < uStack_2c) {
        uStack_54 = 0x717082;
        _free(pvStack_40);
        return;
      }
      uStack_2c = 0xf;
      uStack_30 = 0;
    }
  }
  puStack_4 = (undefined1 *)0xffffffff;
  uStack_54 = 0x71711e;
  (**(code **)(*DAT_00b5ad1c + 0x80))();
  uStack_54 = 0;
  uStack_58 = 0x71712d;
  (**(code **)(*DAT_00b5ad1c + 0x84))();
  uStack_58 = 0;
  uStack_5c = 0x717139;
  (**(code **)(*DAT_00b5a9e4 + 0x18))();
  uStack_5c = 0x717144;
  (**(code **)(*DAT_00b5a9e4 + 0x20))();
  ExceptionList = pvStack_18;
  return;
}


// ==== FUN_00717160 @ 0x00717160 ====

void FUN_00717160(void)

{
  char cVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  int unaff_retaddr;
  undefined1 auStack_92 [26];
  void *pvStack_60;
  uint uStack_4c;
  void *pvStack_48;
  void *pvStack_44;
  uint uStack_34;
  void *pvStack_30;
  undefined4 uStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098fdc2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  cVar1 = *(char *)(unaff_retaddr + 0x14);
  if (cVar1 == '\0') {
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar4 == 0) {
      FUN_00401830();
      puStack_8 = (undefined1 *)0x0;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
      if (uStack_4c < 0x10) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      _free(pvStack_60);
      return;
    }
    piVar2 = *(int **)(iVar4 + 0x20);
    if (piVar2 == (int *)0x0) {
      FUN_00401830();
      puStack_8 = (undefined1 *)0x1;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
      if (pvStack_30 < (void *)0x10) {
        pvStack_30 = (void *)0xf;
        uStack_34 = 0;
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      _free(pvStack_44);
      return;
    }
    piVar5 = (int *)(**(code **)(*piVar2 + 0x28))();
    (**(code **)(*piVar5 + 0x1c))();
    FUN_004dd240();
    (**(code **)(*piVar2 + 0x20))();
    (**(code **)(*DAT_00b5a730 + 0x10))();
    (**(code **)(*DAT_00b5ad1c + 0x5c))();
    (**(code **)(*DAT_00b5a78c + 0x6c))();
  }
  else if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_1c = 0xf;
    uStack_20 = 0;
    pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
    FUN_00401660();
    puStack_8 = auStack_92 + -6;
    uStack_10 = 2;
    FUN_00401660(&uStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uStack_28 = 0xffffffff;
    if (0xf < uStack_34) {
      _free(pvStack_48);
      return;
    }
  }
  else if (cVar1 == '\x02') {
    (**(code **)(*DAT_00b5a9e4 + 0x28))();
  }
  else {
    FUN_00401740();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
  }
  (**(code **)(*DAT_00b5a790 + 4))();
  ExceptionList = pvStack_30;
  return;
}


// ==== FUN_007173a0 @ 0x007173a0 ====

void FUN_007173a0(void)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int unaff_retaddr;
  char *pcStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  uint uStack_8c;
  uint uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  int iStack_7c;
  char *pcStack_78;
  undefined4 uStack_74;
  undefined1 auStack_5e [22];
  undefined1 auStack_48 [20];
  undefined1 auStack_34 [4];
  undefined4 uStack_30;
  void *pvStack_20;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098fdfc;
  pvStack_c = ExceptionList;
  uStack_74 = 6;
  pcStack_78 = (char *)0x7173c9;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x18)) {
  case 0:
    pcStack_78 = (char *)0x7173ec;
    uVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    if (uVar2 == 0) {
      pcStack_78 = s_pPC____NULL_009ec278;
      iStack_7c = 0x717403;
      FUN_00401830();
      pcStack_78 = auStack_5e + -6;
      iStack_7c = 0x717411;
      puStack_8 = (undefined1 *)uVar2;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      pcStack_78 = (char *)0x717421;
      FUN_00446f10();
    }
    piVar1 = *(int **)(uVar2 + 0x20);
    if (piVar1 == (int *)0x0) {
      pcStack_78 = s_pBag____NULL_009ec284;
      iStack_7c = 0x717437;
      FUN_00401830();
      pcStack_78 = auStack_48;
      puStack_8 = (undefined1 *)0x1;
      iStack_7c = 0x717449;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      pcStack_78 = (char *)0x717459;
      FUN_00446f10();
    }
    iStack_7c = 0x717465;
    pcStack_78 = (char *)(unaff_retaddr + 0x10);
    piVar3 = (int *)(**(code **)(*piVar1 + 0x28))();
    iStack_7c = 0;
    uStack_80 = 0;
    uStack_84 = 0;
    uStack_88 = 0x717472;
    uStack_88 = (**(code **)(*piVar3 + 0x1c))();
    uStack_88 = uStack_88 & 0xffff;
    uStack_8c = 0xd;
    uStack_90 = 0x71747d;
    FUN_004dd240();
    uStack_80 = 0x717488;
    iStack_7c = unaff_retaddr + 0x10;
    uStack_80 = (**(code **)(*piVar1 + 0x20))();
    uStack_84 = 1;
    uStack_88 = 0x717496;
    (**(code **)(*DAT_00b5a730 + 0x10))();
    uStack_88 = *(undefined4 *)(unaff_retaddr + 0x14);
    uStack_90 = 0x7174a0;
    uStack_8c = uVar2;
    FUN_00827ef0();
    uStack_88 = 0x7174ae;
    (**(code **)(*DAT_00b5a78c + 0x6c))();
    goto LAB_007175dc;
  case 1:
    pcStack_78 = "";
    iStack_7c = 5;
    uStack_80 = 0x7174c5;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x7174cf;
    FUN_00765c50();
    uStack_10 = 2;
    break;
  case 2:
    pcStack_78 = (char *)0x650016;
    iStack_7c = 5;
    uStack_80 = 0x717511;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x71751b;
    FUN_00765c50();
    uStack_10 = 3;
    goto LAB_0071756f;
  case 3:
    pcStack_78 = (char *)0x65001e;
    iStack_7c = 5;
    uStack_80 = 0x717537;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x717541;
    FUN_00765c50();
    uStack_10 = 4;
    break;
  case 4:
    pcStack_78 = (char *)0x65001f;
    iStack_7c = 5;
    uStack_80 = 0x71755d;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x717567;
    FUN_00765c50();
    uStack_10 = 5;
LAB_0071756f:
    puStack_8 = (undefined1 *)&pcStack_98;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_00717592;
  default:
    uStack_94 = 0x27;
    pcStack_78 = (char *)0xf;
    iStack_7c = 0;
    pcStack_98 = s_SA_InitPartStat_IN_CASH___ERROR_d_009ec294;
    uStack_8c = uStack_8c & 0xffffff00;
    FUN_00401740();
    uStack_94 = 2;
    pcStack_98 = (char *)0x7175dc;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
LAB_007175dc:
    uStack_88 = 0x7175e7;
    (**(code **)(*DAT_00b5a790 + 4))();
    ExceptionList = pvStack_20;
    return;
  }
  puStack_8 = (undefined1 *)&pcStack_98;
  FUN_00765c50(auStack_34);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_00717592:
  uStack_30 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00717610 @ 0x00717610 ====

void FUN_00717610(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int unaff_retaddr;
  undefined1 auStack_8e [26];
  void *pvStack_60;
  uint uStack_4c;
  void *pvStack_48;
  void *pvStack_44;
  uint uStack_34;
  void *pvStack_30;
  undefined4 uStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098fe1e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  if (*(char *)(unaff_retaddr + 0x13) == '\0') {
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar3 == 0) {
      FUN_00401830();
      puStack_8 = (undefined1 *)0x0;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
      if (uStack_4c < 0x10) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(pvStack_60);
      return;
    }
    piVar1 = *(int **)(iVar3 + 0x20);
    if (piVar1 == (int *)0x0) {
      FUN_00401830();
      puStack_8 = (undefined1 *)0x1;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
      if (pvStack_30 < (void *)0x10) {
        pvStack_30 = (void *)0xf;
        uStack_34 = 0;
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(pvStack_44);
      return;
    }
    piVar4 = (int *)(**(code **)(*piVar1 + 0x28))();
    (**(code **)(*piVar4 + 0x1c))();
    FUN_004dd240();
    (**(code **)(*piVar1 + 0x20))();
    (**(code **)(*DAT_00b5a730 + 0x10))();
    (**(code **)(*DAT_00b5a78c + 0x6c))();
  }
  else if (*(char *)(unaff_retaddr + 0x13) == '\x01') {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_1c = 0xf;
    uStack_20 = 0;
    pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
    FUN_00401660();
    puStack_8 = auStack_8e + -6;
    uStack_10 = 2;
    FUN_00401660(&uStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uStack_28 = 0xffffffff;
    if (0xf < uStack_34) {
      _free(pvStack_48);
      return;
    }
  }
  else {
    FUN_00401740();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
  }
  (**(code **)(*DAT_00b5a790 + 4))();
  ExceptionList = pvStack_30;
  return;
}


// ==== FUN_00717830 @ 0x00717830 ====

void FUN_00717830(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  void *unaff_ESI;
  undefined1 auStack_88 [4];
  undefined1 uStack_84;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  void *pvStack_38;
  uint uStack_24;
  undefined1 *puStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098fe38;
  pvStack_c = ExceptionList;
  uStack_6c = 0x717863;
  ExceptionList = &pvStack_c;
  FUN_004dd750();
  pcVar2 = (char *)(param_1 + 0x12);
  local_4 = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740();
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401ff0();
  iVar3 = (**(code **)(*DAT_00b5ad20 + 0xc))();
  if (iVar3 != 0) {
    uStack_70 = (**(code **)(*DAT_00b5ad20 + 0x40))();
    uStack_6c = 0;
    uStack_74 = 0x7178f8;
    FUN_00401ff0();
    if (0xf < uStack_24) {
      uStack_6c = 0x717911;
      _free(pvStack_38);
      return;
    }
    uStack_6c = 5;
    uStack_70 = 0x717926;
    uStack_78 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_70 = 0xffffffff;
    uStack_74 = 0;
    uStack_7c = 0x717933;
    FUN_00401ff0();
    puStack_18 = auStack_88;
    uStack_70 = 0xf;
    uStack_74 = 0;
    uStack_84 = 0;
    FUN_00401660(auStack_88 + 0x28,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  if (pvStack_38 < (void *)0x10) {
    ExceptionList = puStack_18;
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_00717990 @ 0x00717990 ====

void FUN_00717990(void)

{
  int iVar1;
  int *piVar2;
  undefined1 extraout_var;
  int unaff_retaddr;
  char *pcStack_98;
  uint uStack_94;
  undefined4 uStack_90;
  uint uStack_8c;
  uint uStack_88;
  int iStack_84;
  undefined4 uStack_80;
  undefined1 auStack_34 [4];
  undefined1 uStack_30;
  void *pvStack_2c;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098fe6a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x13)) {
  case 0:
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar1 == 0) {
      FUN_00401830();
      puStack_8 = (undefined1 *)0x0;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if (*(int **)(iVar1 + 0x20) == (int *)0x0) {
      FUN_00401830();
      puStack_8 = (undefined1 *)0x1;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x20) + 0x28))();
    uStack_80 = 0;
    iStack_84 = 0;
    uStack_88 = 0x717a66;
    uStack_88 = (**(code **)(*piVar2 + 0x1c))();
    uStack_88 = uStack_88 & 0xffff;
    uStack_8c = 0xd;
    uStack_90 = 0x717a71;
    FUN_004dd240();
    uStack_80 = CONCAT13(extraout_var,*(undefined3 *)(unaff_retaddr + 0x10));
    uStack_88 = 0x717a8b;
    iStack_84 = iVar1;
    FUN_00827440();
    (**(code **)(*DAT_00b5a78c + 0x6c))();
    break;
  case 1:
    uStack_80 = 0x717ab0;
    uStack_88 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0xffffffff;
    iStack_84 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    uStack_8c = 0x717ad0;
    FUN_00401660();
    puStack_8 = (undefined1 *)&pcStack_98;
    uStack_80 = 0xf;
    iStack_84 = 0;
    uStack_10 = 2;
    uStack_94 = uStack_94 & 0xffffff00;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    pvStack_c = (void *)0xffffffff;
    if (0xf < uStack_18) {
      uStack_80 = 0x717b27;
      _free(pvStack_2c);
      return;
    }
    break;
  case 2:
    uStack_80 = 0x717b41;
    uStack_88 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0xffffffff;
    iStack_84 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    uStack_8c = 0x717b61;
    FUN_00401660();
    puStack_8 = (undefined1 *)&pcStack_98;
    uStack_80 = 0xf;
    iStack_84 = 0;
    uStack_10 = 3;
    uStack_94 = uStack_94 & 0xffffff00;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    pvStack_c = (void *)0xffffffff;
    if (0xf < uStack_18) {
      uStack_80 = 0x717bb8;
      _free(pvStack_2c);
      return;
    }
    break;
  case 3:
    uStack_80 = 0x717bd2;
    uStack_88 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0xffffffff;
    iStack_84 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    uStack_8c = 0x717bf2;
    FUN_00401660();
    puStack_8 = (undefined1 *)&pcStack_98;
    uStack_80 = 0xf;
    iStack_84 = 0;
    uStack_10 = 4;
    uStack_94 = uStack_94 & 0xffffff00;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    pvStack_c = (void *)0xffffffff;
    if (0xf < uStack_18) {
      uStack_80 = 0x717c45;
      _free(pvStack_2c);
      return;
    }
    break;
  default:
    uStack_94 = 0x27;
    pcStack_98 = s_SA_EventAnother_IN_CASH___ERROR_d_009ec318;
    uStack_8c = uStack_8c & 0xffffff00;
    FUN_00401740();
    uStack_94 = 2;
    pcStack_98 = (char *)0x717c7e;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
  }
  (**(code **)(*DAT_00b5a790 + 4))();
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00717cb0 @ 0x00717cb0 ====

void FUN_00717cb0(int param_1)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  undefined2 extraout_var;
  void *unaff_EBP;
  undefined1 auStack_a8 [4];
  undefined1 uStack_a4;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  uint uStack_90;
  uint *puStack_8c;
  undefined4 uStack_7c;
  char *pcStack_78;
  int iStack_74;
  uint uStack_54;
  undefined1 uStack_50;
  void *local_4c;
  undefined4 local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  void *pvStack_38;
  uint uStack_24;
  undefined1 *puStack_18;
  undefined1 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098fe8c;
  pvStack_c = ExceptionList;
  local_48 = 0xf;
  local_4c = (void *)0x0;
  pcStack_78 = (char *)(param_1 + 0x12);
  local_4 = 0;
  pcVar2 = pcStack_78;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iStack_74 = (int)pcVar2 - (param_1 + 0x13);
  uStack_7c = 0x717d06;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  iStack_74 = 0x650029;
  pcStack_78 = (char *)0x5;
  uStack_7c = 0x717d18;
  (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_7c = 0xffffffff;
  FUN_00401ff0();
  uStack_7c = *(undefined4 *)(param_1 + 0x2c);
  piVar3 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))();
  if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0xc))(), iVar4 == 0)) {
    piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
    piVar3 = (int *)(**(code **)(*piVar3 + 0x24))();
    iVar4 = *piVar3;
    (**(code **)(*DAT_00b5a6ac + 0x20))();
    pcVar2 = (char *)(**(code **)(iVar4 + 0x1c))();
    uStack_3c = 0xf;
    uStack_40 = 0;
    uStack_50 = 0;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    puStack_8c = (uint *)0x717db6;
    FUN_00401740();
    puStack_8c = &uStack_54;
    uStack_14 = 1;
    uStack_90 = 0x717dcc;
    FUN_00401ff0();
    puStack_8c = (uint *)0x717dde;
    uStack_94 = (**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_8c = (uint *)0xffffffff;
    uStack_90 = 0;
    uStack_98 = 0x717deb;
    FUN_00401ff0();
    puStack_8c = (uint *)CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x30));
    uStack_90 = 0x717dfb;
    iVar4 = (**(code **)(*DAT_00b5ad20 + 0xc))();
    if (iVar4 == 0) {
      if ((void *)0xf < pvStack_38) {
        _free(local_4c);
        return;
      }
      pvStack_38 = (void *)0xf;
      uStack_3c = 0;
      local_4c = (void *)((uint)local_4c & 0xffffff00);
    }
    else {
      uStack_90 = (**(code **)(*DAT_00b5ad20 + 0x40))();
      puStack_8c = (uint *)0x0;
      puStack_18._0_1_ = 2;
      uStack_94 = 0x717e5e;
      FUN_00401ff0();
      puStack_18 = (undefined1 *)CONCAT31(puStack_18._1_3_,1);
      if (0xf < uStack_24) {
        puStack_8c = (uint *)0x717e78;
        _free(pvStack_38);
        return;
      }
      puStack_8c = (uint *)0x5;
      uStack_90 = 0x717e8d;
      uStack_98 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_90 = 0xffffffff;
      uStack_94 = 0;
      uStack_9c = 0x717e9a;
      FUN_00401ff0();
      puStack_18 = auStack_a8;
      uStack_90 = 0xf;
      uStack_94 = 0;
      uStack_a4 = 0;
      FUN_00401660(&uStack_7c,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      uStack_90 = (uint)*(ushort *)(param_1 + 0x10);
      puStack_8c = (uint *)0x0;
      uStack_94 = 0x1e;
      uStack_98 = 0x717ee3;
      FUN_004dd750();
      if ((void *)0xf < pvStack_38) {
        _free(local_4c);
        return;
      }
      pvStack_38 = (void *)0xf;
      uStack_3c = 0;
      local_4c = (void *)((uint)local_4c & 0xffffff00);
    }
  }
  if (uStack_54 < 0x10) {
    ExceptionList = puStack_18;
    return;
  }
  _free(unaff_EBP);
  return;
}


// ==== FUN_00717f30 @ 0x00717f30 ====

void FUN_00717f30(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_retaddr;
  char *pcStack_98;
  uint uStack_94;
  undefined4 uStack_90;
  uint uStack_8c;
  void *pvStack_38;
  undefined1 auStack_34 [4];
  undefined1 uStack_30;
  uint uStack_24;
  void *pvStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098febe;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x13)) {
  case 0:
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar2 == 0) {
      FUN_00401830();
      puStack_8 = (undefined1 *)0x0;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    piVar1 = *(int **)(iVar2 + 0x20);
    if (piVar1 == (int *)0x0) {
      FUN_00401830();
      puStack_8 = (undefined1 *)0x1;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    piVar3 = (int *)(**(code **)(*piVar1 + 0x28))();
    (**(code **)(*piVar3 + 0x1c))();
    uStack_8c = 0xd;
    uStack_90 = 0x718010;
    FUN_004dd240();
    (**(code **)(*piVar1 + 0x20))();
    (**(code **)(*DAT_00b5a730 + 0x10))();
    uStack_8c = 0x71802f;
    FUN_00828150();
    (**(code **)(*DAT_00b5a78c + 0x6c))();
    break;
  case 1:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_1c = 0xf;
    pvStack_20 = (void *)0x0;
    uStack_30 = 0;
    uStack_8c = 0x718076;
    FUN_00401660();
    uStack_10 = 2;
    goto LAB_0071815a;
  case 2:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_1c = 0xf;
    pvStack_20 = (void *)0x0;
    uStack_30 = 0;
    uStack_8c = 0x7180b7;
    FUN_00401660();
    puStack_8 = (undefined1 *)&pcStack_98;
    uStack_10 = 3;
    uStack_94 = uStack_94 & 0xffffff00;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    (**(code **)(*DAT_00b5a9e4 + 0x28))(1);
    uStack_18 = 0xffffffff;
    if (0xf < uStack_24) {
      uStack_8c = 0x718116;
      _free(pvStack_38);
      return;
    }
    break;
  case 3:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_1c = 0xf;
    pvStack_20 = (void *)0x0;
    uStack_30 = 0;
    uStack_8c = 0x718152;
    FUN_00401660();
    uStack_10 = 4;
LAB_0071815a:
    puStack_8 = (undefined1 *)&pcStack_98;
    uStack_94 = uStack_94 & 0xffffff00;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uStack_18 = 0xffffffff;
    if (0xf < uStack_24) {
      uStack_8c = 0x71819d;
      _free(pvStack_38);
      return;
    }
    break;
  default:
    uStack_94 = 0x20;
    pcStack_98 = s_SA_Event_IN_CASH___ERROR_default_009ec35c;
    uStack_8c = uStack_8c & 0xffffff00;
    FUN_00401740();
    uStack_94 = 2;
    pcStack_98 = (char *)0x7181d6;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
  }
  (**(code **)(*DAT_00b5a790 + 4))();
  ExceptionList = pvStack_20;
  return;
}


// ==== FUN_00718210 @ 0x00718210 ====

void FUN_00718210(void)

{
  int iVar1;
  int *piVar2;
  undefined1 extraout_var;
  int unaff_retaddr;
  char *pcStack_94;
  char *pcStack_90;
  undefined4 uStack_8c;
  uint uStack_88;
  uint uStack_84;
  int iStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  char *pcStack_74;
  undefined4 uStack_70;
  undefined1 auStack_5e [22];
  undefined1 auStack_48 [20];
  undefined1 auStack_34 [4];
  undefined4 uStack_30;
  void *pvStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098ff00;
  pvStack_c = ExceptionList;
  uStack_70 = 6;
  pcStack_74 = (char *)0x718238;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x13)) {
  case 0:
    pcStack_74 = (char *)0x71825b;
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar1 == 0) {
      pcStack_74 = s_pPC____NULL_009ec380;
      uStack_78 = 0x71826f;
      FUN_00401830();
      pcStack_74 = auStack_5e + -6;
      uStack_78 = 0x71827d;
      puStack_8 = (undefined1 *)iVar1;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      pcStack_74 = (char *)0x718291;
      FUN_00446f10();
    }
    if (*(int **)(iVar1 + 0x20) == (int *)0x0) {
      pcStack_74 = s_pBag____NULL_009ec38c;
      uStack_78 = 0x7182a7;
      FUN_00401830();
      pcStack_74 = auStack_48;
      puStack_8 = (undefined1 *)0x1;
      uStack_78 = 0x7182b9;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      pcStack_74 = (char *)0x7182cd;
      FUN_00446f10();
    }
    uStack_78 = 0x7182d9;
    pcStack_74 = (char *)(unaff_retaddr + 0x10);
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x20) + 0x28))();
    if (piVar2 == (int *)0x0) {
      ExceptionList = pvStack_14;
      return;
    }
    uStack_78 = 0;
    uStack_7c = 0;
    iStack_80 = 0;
    uStack_84 = 0x7182ee;
    uStack_84 = (**(code **)(*piVar2 + 0x1c))();
    uStack_84 = uStack_84 & 0xffff;
    uStack_88 = 0xd;
    uStack_8c = 0x7182f9;
    FUN_004dd240();
    uStack_78 = 1;
    uStack_7c = CONCAT13(extraout_var,*(undefined3 *)(unaff_retaddr + 0x10));
    uStack_84 = 0x718313;
    iStack_80 = iVar1;
    FUN_00827440();
    uStack_78 = 0x718321;
    (**(code **)(*DAT_00b5a78c + 0x6c))();
    uStack_78 = 1;
    uStack_7c = 0x71832e;
    (**(code **)(*DAT_00b5a9e4 + 0x18))();
    uStack_7c = 0x718339;
    (**(code **)(*DAT_00b5a9e4 + 0x1c))();
    goto LAB_007184b5;
  case 1:
    pcStack_74 = "";
    uStack_78 = 5;
    uStack_7c = 0x718350;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_80 = 0x71835a;
    FUN_00765c50();
    uStack_10 = 2;
    break;
  case 2:
    pcStack_90 = s_PORTALPACKETS__SA_Create_INVALID_009ec39c;
    pcStack_94 = (char *)0x71846f;
    FUN_00401830();
    pcStack_90 = (char *)0x2;
    pcStack_94 = (char *)0x71847c;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_007184b5;
  case 3:
    pcStack_74 = (char *)0x650030;
    uStack_78 = 5;
    uStack_7c = 0x718379;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_80 = 0x718383;
    FUN_00765c50();
    uStack_10 = 3;
    goto LAB_0071838b;
  case 4:
    pcStack_74 = (char *)0x65003e;
    uStack_78 = 5;
    uStack_7c = 0x7183c5;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_80 = 0x7183cf;
    FUN_00765c50();
    uStack_10 = 4;
    break;
  case 5:
    pcStack_74 = (char *)0x6e0105;
    uStack_78 = 0;
    uStack_7c = 0x718411;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_80 = 0x71841b;
    FUN_00765c50();
    uStack_10 = 6;
    break;
  case 6:
    pcStack_74 = "\x05";
    uStack_78 = 5;
    uStack_7c = 0x7183eb;
    uStack_7c = (**(code **)(*DAT_00b5a794 + 0xc))();
    iStack_80 = 0x7183f5;
    FUN_00765c50();
    uStack_10 = 5;
LAB_0071838b:
    puStack_8 = (undefined1 *)&pcStack_94;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_00718446;
  default:
    pcStack_90 = (char *)0x20;
    pcStack_74 = (char *)0xf;
    uStack_78 = 0;
    pcStack_94 = s_SA_Event_IN_CASH___ERROR_default_009ec3c4;
    uStack_88 = uStack_88 & 0xffffff00;
    FUN_00401740();
    pcStack_90 = (char *)0x2;
    pcStack_94 = (char *)0x7184b5;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
LAB_007184b5:
    uStack_7c = 0x7184c0;
    (**(code **)(*DAT_00b5a790 + 4))();
    ExceptionList = pvStack_14;
    return;
  }
  puStack_8 = (undefined1 *)&pcStack_94;
  FUN_00765c50(auStack_34);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_00718446:
  uStack_30 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_007184f0 @ 0x007184f0 ====

void FUN_007184f0(void)

{
  int iVar1;
  int unaff_retaddr;
  char *pcStack_54;
  char *pcStack_50;
  undefined1 uStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  void *pvStack_30;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098ff4a;
  pvStack_c = ExceptionList;
  pvStack_30 = (void *)0x6;
  iStack_34 = 0x718516;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x16)) {
  case 0:
    iStack_34 = 0x718539;
    iVar1 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar1 == 0) {
      iStack_34 = 0;
    }
    else {
      iStack_34 = 0x718544;
      iStack_34 = FUN_00511760();
    }
    *(undefined4 *)(iStack_34 + 4) = *(undefined4 *)(unaff_retaddr + 0x10);
    *(undefined2 *)(iStack_34 + 8) = *(undefined2 *)(unaff_retaddr + 0x14);
    *(undefined1 *)(iStack_34 + 10) = 1;
    uStack_38 = 0x718564;
    FUN_00797a20();
    ExceptionList = pvStack_10;
    return;
  case 1:
    iStack_34 = 0x650039;
    uStack_38 = 5;
    uStack_3c = 0x71858b;
    uStack_3c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_40 = 0x718595;
    FUN_00765c50();
    break;
  case 2:
    pcStack_50 = s_PORTALPACKETS__SA_Create_INVALID_009ec3e8;
    pcStack_54 = (char *)0x7185b5;
    FUN_00401830();
    goto LAB_007187a2;
  case 3:
    iStack_34 = 0x65003a;
    uStack_38 = 5;
    uStack_3c = 0x7185cc;
    uStack_3c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_40 = 0x7185d6;
    FUN_00765c50();
    break;
  default:
    pcStack_50 = (char *)0x20;
    iStack_34 = 0xf;
    uStack_38 = 0;
    pcStack_54 = s_SA_Event_IN_CASH___ERROR_default_009ec410;
    uStack_48 = 0;
    FUN_00401740();
LAB_007187a2:
    pcStack_50 = (char *)0x2;
    pcStack_54 = (char *)0x7187af;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    ExceptionList = pvStack_30;
    return;
  case 5:
    iStack_34 = 0x650030;
    uStack_38 = 5;
    uStack_3c = 0x7185f5;
    uStack_3c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_40 = 0x7185ff;
    FUN_00765c50();
    goto LAB_00718607;
  case 6:
    iStack_34 = 0x65003c;
    uStack_38 = 5;
    uStack_3c = 0x718654;
    uStack_3c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_40 = 0x71865e;
    FUN_00765c50();
    break;
  case 7:
    iStack_34 = 0x65003d;
    uStack_38 = 5;
    uStack_3c = 0x71867d;
    uStack_3c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_40 = 0x718687;
    FUN_00765c50();
LAB_00718607:
    puStack_8 = (undefined1 *)&pcStack_54;
    FUN_00765c50(&iStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 8:
    iStack_34 = 0x65003e;
    uStack_38 = 5;
    uStack_3c = 0x7186a6;
    uStack_3c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_40 = 0x7186b0;
    FUN_00765c50();
    break;
  case 9:
    iStack_34 = 0x7d50014;
    uStack_38 = 0;
    uStack_3c = 0x7186cf;
    uStack_3c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_40 = 0x7186d9;
    FUN_00765c50();
    puStack_8 = (undefined1 *)&pcStack_54;
    FUN_00765c50(&iStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 10:
    iStack_34 = 0x650042;
    uStack_38 = 5;
    uStack_3c = 0x71872e;
    uStack_3c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_40 = 0x718738;
    FUN_00765c50();
  }
  puStack_8 = (undefined1 *)&pcStack_54;
  FUN_00765c50(&iStack_34);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== caseD_4 @ 0x0071877b ====

void switchD_00718527::caseD_4(void)

{
  void *unaff_retaddr;
  undefined1 *puStack00000030;
  undefined1 auStack_1c [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  puStack00000030 = auStack_1c;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_SA_Event_IN_CASH___ERROR_default_009ec410,0x20);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  ExceptionList = unaff_retaddr;
  return;
}


// ==== FUN_007187f0 @ 0x007187f0 ====

void FUN_007187f0(int param_1)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStack_be [6];
  undefined4 uStack_b8;
  char *pcStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  void *pvStack_40;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098ff67;
  pvStack_c = ExceptionList;
  uVar5 = *(undefined4 *)(param_1 + 0x10);
  ExceptionList = &pvStack_c;
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(uVar5);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 == 0xe) {
      piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
      piVar1 = (int *)(**(code **)(*piVar1 + 0x24))();
      (**(code **)(*piVar1 + 0x20))();
      (**(code **)(*piVar1 + 0x20))();
      FUN_005229b0(&uStack_b8,auStack_be + -6);
      FUN_00718f10();
      puStack_8 = (undefined1 *)0x0;
      piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
      uVar4 = 0x3d6;
      pcVar3 = s___CashItem_NetHandler_cpp_009ec434;
      uStack_24 = (**(code **)(*piVar1 + 4))(2,s___CashItem_NetHandler_cpp_009ec434,0x3d6);
      FUN_0081d760();
      uStack_b8 = uStack_24;
      uStack_80 = 0;
      uStack_74 = 0xffffffff;
      uStack_98 = 0;
      uStack_94 = 0x640c36;
      uStack_90 = 3;
      uStack_8c = 2000;
      uStack_88 = 0;
      uStack_7c = 0;
      uStack_78 = 0;
      uStack_14 = 1;
      pcStack_b4 = pcVar3;
      uStack_b0 = uVar5;
      uStack_ac = uVar4;
      (**(code **)(*DAT_00b5afe0 + 4))(&uStack_b8);
      (**(code **)(*DAT_00b5a9e4 + 4))(uStack_28);
      puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
      FUN_0081d670();
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return;
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_007189f0 @ 0x007189f0 ====

void FUN_007189f0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_retaddr;
  char *pcStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  uint uStack_84;
  uint uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  int iStack_74;
  char *pcStack_70;
  undefined4 uStack_6c;
  undefined1 auStack_5e [22];
  undefined1 auStack_48 [20];
  undefined1 auStack_34 [20];
  void *pvStack_20;
  void *pvStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098ffb9;
  pvStack_c = ExceptionList;
  uStack_6c = 6;
  pcStack_70 = (char *)0x718a17;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x10)) {
  case 0:
    pcStack_70 = (char *)0x718a39;
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar2 == 0) {
      pcStack_70 = s_pPC____NULL_009ec450;
      iStack_74 = 0x718a4d;
      FUN_00401830();
      pcStack_70 = auStack_5e + -6;
      iStack_74 = 0x718a5b;
      puStack_8 = (undefined1 *)iVar2;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      pcStack_70 = (char *)0x718a6f;
      FUN_00446f10();
    }
    piVar1 = *(int **)(iVar2 + 0x20);
    if (piVar1 == (int *)0x0) {
      pcStack_70 = s_pBag____NULL_009ec45c;
      iStack_74 = 0x718a85;
      FUN_00401830();
      pcStack_70 = auStack_48;
      puStack_8 = (undefined1 *)0x1;
      iStack_74 = 0x718a97;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      pcStack_70 = (char *)0x718aab;
      FUN_00446f10();
    }
    iStack_74 = 0x718ab7;
    pcStack_70 = (char *)(unaff_retaddr + 0x14);
    piVar3 = (int *)(**(code **)(*piVar1 + 0x28))();
    if (piVar3 == (int *)0x0) {
      ExceptionList = pvStack_14;
      return;
    }
    iStack_74 = 0;
    uStack_78 = 0;
    uStack_7c = 0;
    uStack_80 = 0x718acc;
    uStack_80 = (**(code **)(*piVar3 + 0x1c))();
    uStack_80 = uStack_80 & 0xffff;
    uStack_84 = 0xd;
    uStack_88 = 0x718ad7;
    FUN_004dd240();
    uStack_78 = 0x718ae2;
    iStack_74 = unaff_retaddr + 0x14;
    uStack_78 = (**(code **)(*piVar1 + 0x20))();
    uStack_7c = 1;
    uStack_80 = 0x718af0;
    (**(code **)(*DAT_00b5a730 + 0x10))();
    uStack_80 = 0x718afb;
    (**(code **)(*DAT_00b5a78c + 0x6c))();
    ExceptionList = pvStack_20;
    return;
  case 1:
    pcStack_70 = (char *)0x650031;
    iStack_74 = 5;
    uStack_78 = 0x718b20;
    uStack_78 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_7c = 0x718b2a;
    FUN_00765c50();
    uStack_10 = 2;
    break;
  case 2:
    pcStack_70 = (char *)0x650032;
    iStack_74 = 5;
    uStack_78 = 0x718b49;
    uStack_78 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_7c = 0x718b53;
    FUN_00765c50();
    uStack_10 = 3;
    goto LAB_00718b5b;
  case 3:
    pcStack_70 = (char *)0x650033;
    iStack_74 = 5;
    uStack_78 = 0x718bac;
    uStack_78 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_7c = 0x718bb6;
    FUN_00765c50();
    uStack_10 = 4;
    break;
  case 4:
    pcStack_70 = (char *)0x65003f;
    iStack_74 = 5;
    uStack_78 = 0x718c8d;
    uStack_78 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_7c = 0x718c97;
    FUN_00765c50();
    uStack_10 = 8;
    break;
  default:
    uStack_8c = 0x33;
    pcStack_70 = (char *)0xf;
    iStack_74 = 0;
    pcStack_90 = s_GUILDFACTORYPACKETS__SA_GuildEff_009ec46c;
    uStack_84 = uStack_84 & 0xffffff00;
    FUN_00401740();
    uStack_8c = 2;
    pcStack_90 = (char *)0x718d15;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    ExceptionList = pvStack_14;
    return;
  case 10:
    pcStack_70 = (char *)0x650034;
    iStack_74 = 5;
    uStack_78 = 0x718bd5;
    uStack_78 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_7c = 0x718bdf;
    FUN_00765c50();
    uStack_10 = 5;
LAB_00718b5b:
    puStack_8 = (undefined1 *)&pcStack_90;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xb:
    pcStack_70 = (char *)0x650035;
    iStack_74 = 5;
    uStack_78 = 0x718bfe;
    uStack_78 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_7c = 0x718c08;
    FUN_00765c50();
    uStack_10 = 6;
    break;
  case 0xc:
    pcStack_70 = (char *)0x650036;
    iStack_74 = 5;
    uStack_78 = 0x718c27;
    uStack_78 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_7c = 0x718c31;
    FUN_00765c50();
    puStack_8 = (undefined1 *)&pcStack_90;
    uStack_10 = 7;
    FUN_00765c50(auStack_34);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  puStack_8 = (undefined1 *)&pcStack_90;
  FUN_00765c50(auStack_34);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== caseD_5 @ 0x00718cde ====

void switchD_00718a27::caseD_5(void)

{
  void *in_stack_0000003c;
  undefined1 *puStack0000006c;
  undefined1 auStack_1c [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  puStack0000006c = auStack_1c;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_GUILDFACTORYPACKETS__SA_GuildEff_009ec46c,0x33);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  ExceptionList = in_stack_0000003c;
  return;
}


// ==== FUN_00718d60 @ 0x00718d60 ====

undefined4 FUN_00718d60(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x5060015) {
    if (uVar1 == 0x5060014) {
      FUN_007173a0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 < 0x502000d) {
      if (uVar1 == 0x502000c) {
        FUN_00717610(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x281000d) {
        FUN_00717830(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x2810010) {
        FUN_00717cb0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x5000009) {
        FUN_00717f30(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
    else {
      if (uVar1 == 0x502000f) {
        FUN_00717990(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x5060010) {
        FUN_00717160(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
  }
  else if (uVar1 < 0x5230007) {
    if (uVar1 == 0x5230006) {
      FUN_007184f0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x5230002) {
      FUN_00718210(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x5230004) {
      FUN_00716fd0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else {
    if (uVar1 == 0x5230007) {
      FUN_007187f0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x900000e) {
      FUN_007189f0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00718ec0 @ 0x00718ec0 ====

undefined4 FUN_00718ec0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00718d60(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00718ef0 @ 0x00718ef0 ====

void FUN_00718ef0(byte param_1)

{
  void *in_ECX;
  
  FUN_00716fb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00718f10 @ 0x00718f10 ====

void FUN_00718f10(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ffdb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  local_4 = 0;
  in_ECX[3] = 0xffffffff;
  *(undefined2 *)(in_ECX + 4) = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  FUN_00401740(&DAT_0099cf70,0);
  *(undefined1 *)(in_ECX + 0xf) = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00718fc0 @ 0x00718fc0 ====

void FUN_00718fc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec624;
  return;
}


// ==== FUN_00718fd0 @ 0x00718fd0 ====

void FUN_00718fd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec624;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00718ff0 @ 0x00718ff0 ====

void FUN_00718ff0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00719000 @ 0x00719000 ====

undefined4 FUN_00719000(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00719010 @ 0x00719010 ====

void FUN_00719010(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_00719030 @ 0x00719030 ====

void FUN_00719030(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ec6a4;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00719060 @ 0x00719060 ====

void FUN_00719060(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ec6b8;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00719090 @ 0x00719090 ====

void FUN_00719090(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ec67c;
    *(undefined1 *)(puVar1 + 2) = 0;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)((int)puVar1 + 10) = 0;
  }
  *(undefined2 *)(puVar1 + 2) = (undefined2)param_2;
  puVar1[1] = param_1;
  *(undefined1 *)((int)puVar1 + 10) = param_2._2_1_;
  FUN_00797a20(puVar1);
  *(undefined2 *)(in_ECX + 4) = (undefined2)param_2;
  *(undefined1 *)(in_ECX + 6) = param_2._2_1_;
  return;
}


// ==== FUN_007190f0 @ 0x007190f0 ====

void FUN_007190f0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    uRam00000004 = param_1;
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ec690;
  puVar1[1] = param_1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00719130 @ 0x00719130 ====

void FUN_00719130(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    uRam00000004 = param_1;
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009e8a98;
  puVar1[1] = param_1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00719170 @ 0x00719170 ====

void FUN_00719170(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(6);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x506000f;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined2 *)(iVar4 + 0x10) = *(undefined2 *)(in_ECX + 4);
    *(undefined1 *)(iVar4 + 0x12) = *(undefined1 *)(in_ECX + 6);
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5af2c + 4))(6);
  }
  return;
}


// ==== FUN_007191f0 @ 0x007191f0 ====

void FUN_007191f0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int in_ECX;
  undefined4 unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(6);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5060013;
    *(undefined2 *)((int)pvVar3 + 6) = 0x18;
    iVar4 = FUN_004244d0();
    *(undefined4 *)(iVar4 + 0x10) = unaff_retaddr;
    *(undefined2 *)(iVar4 + 0x14) = *(undefined2 *)(in_ECX + 4);
    *(undefined1 *)(iVar4 + 0x16) = *(undefined1 *)(in_ECX + 6);
    FUN_004d8570(iVar4);
                    /* WARNING: Could not recover jumptable at 0x0071926d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5af2c + 4))();
    return;
  }
  return;
}


// ==== FUN_00719280 @ 0x00719280 ====

void FUN_00719280(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(6);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x502000b;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined2 *)(iVar4 + 0x10) = *(undefined2 *)(in_ECX + 4);
    *(undefined1 *)(iVar4 + 0x12) = *(undefined1 *)(in_ECX + 6);
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5af2c + 4))(6);
  }
  return;
}


// ==== FUN_00719300 @ 0x00719300 ====

void FUN_00719300(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(6);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5000008;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined2 *)(iVar4 + 0x10) = *(undefined2 *)(in_ECX + 4);
    *(undefined1 *)(iVar4 + 0x12) = *(undefined1 *)(in_ECX + 6);
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5af2c + 4))(6);
  }
  return;
}


// ==== FUN_00719380 @ 0x00719380 ====

void FUN_00719380(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(6);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x900000d;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined2 *)(iVar4 + 0x10) = *(undefined2 *)(in_ECX + 4);
    *(undefined1 *)(iVar4 + 0x12) = *(undefined1 *)(in_ECX + 6);
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5af2c + 4))(6);
  }
  return;
}


// ==== FUN_00719400 @ 0x00719400 ====

undefined4 FUN_00719400(int param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_event_009ec5b4,10);
  if (iVar2 != 0) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_guildmarkeffect_009ec5c0,0x14);
    if (iVar2 != 0) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_portaltime_009ec5d8,0xf);
      if (iVar2 == 0) {
        (**(code **)(*in_ECX + 0x1c))();
        return 1;
      }
      cVar1 = FUN_004036a0(param_1 + 8,s_hide_portaltime_009ec5e8);
      if (cVar1 == '\0') {
        return 0;
      }
      (**(code **)(*in_ECX + 0x20))();
      return 1;
    }
  }
  FUN_004dd750(0x1e,1,0,1,3,0);
  return 1;
}


// ==== FUN_007194b0 @ 0x007194b0 ====

void FUN_007194b0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  
  piVar6 = *(int **)(in_ECX + 0x18);
  if (((piVar6 != (int *)0x0) && (*(int *)(in_ECX + 0x1c) - (int)piVar6 >> 3 != 0)) &&
     (piVar5 = *(int **)(in_ECX + 0x1c), piVar6 != piVar5)) {
    while( true ) {
      iVar1 = *piVar6;
      iVar2 = piVar6[1];
      iVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      if (2000 < (uint)(iVar4 - iVar2)) break;
      piVar6 = piVar6 + 2;
      if (piVar6 == piVar5) {
        return;
      }
    }
    if (iVar1 != 0) {
      (**(code **)(*DAT_00b5afe0 + 8))(iVar1);
      piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
      (**(code **)(*piVar5 + 8))(s___CashItem_UIHandler_cpp_009ec598,0xc3,2,iVar1);
    }
    piVar3 = *(int **)(in_ECX + 0x1c);
    piVar5 = piVar6 + 2;
    if (piVar5 != piVar3) {
      do {
        *piVar6 = *piVar5;
        piVar6[1] = piVar5[1];
        piVar5 = piVar5 + 2;
        piVar6 = piVar6 + 2;
      } while (piVar5 != piVar3);
    }
    *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + -8;
  }
  return;
}


// ==== FUN_00719580 @ 0x00719580 ====

void FUN_00719580(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int in_ECX;
  undefined1 auStack_3c [4];
  void *pvStack_28;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098fff8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*DAT_00b5adb8 + 0x14))();
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      pvStack_10 = (void *)0x0;
      FUN_00401660(auStack_3c + 8,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if (0xf < uStack_14) {
        _free(pvStack_28);
        return;
      }
    }
    else {
      uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar3 = operator_new(0x400);
      *(undefined4 *)((int)pvVar3 + 8) = uVar2;
      *(undefined4 *)((int)pvVar3 + 0xc) = 0x502000e;
      *(undefined2 *)((int)pvVar3 + 6) = 0x18;
      iVar4 = FUN_004244d0();
      *(undefined2 *)(iVar4 + 0x10) = *(undefined2 *)(in_ECX + 4);
      *(undefined1 *)(iVar4 + 0x12) = *(undefined1 *)(in_ECX + 6);
      uVar2 = (**(code **)(*DAT_00b5adb8 + 0x20))();
      *(undefined4 *)(iVar4 + 0x14) = uVar2;
      FUN_004d8570();
      (**(code **)(*DAT_00b5af2c + 4))();
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_007196d0 @ 0x007196d0 ====

void FUN_007196d0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined1 auStack_58 [4];
  void *pvStack_44;
  undefined1 auStack_34 [4];
  uint uStack_30;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990012;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    iVar2 = *DAT_00b5ad00;
    (**(code **)(*DAT_00b5a97c + 0xc))();
    iVar2 = (**(code **)(iVar2 + 4))();
    if (iVar2 != 0) {
      if (*(short *)(iVar2 + 0x14) == 0) {
        piVar3 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
        piVar3 = (int *)(**(code **)(*piVar3 + 0x2c))();
        iVar2 = (**(code **)(*piVar3 + 0x10))();
        if (*(char *)(iVar2 + 0x961) == '\0') {
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          pvStack_10 = (void *)0x1;
          FUN_00765c50(auStack_34);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        (**(code **)(*DAT_00b5a6ac + 0x20))();
        iVar2 = FUN_00719eb0();
        *(undefined2 *)(iVar2 + 0x10) = *(undefined2 *)(in_ECX + 4);
        *(undefined1 *)(iVar2 + 0x12) = *(undefined1 *)(in_ECX + 6);
        FUN_004d8570();
        (**(code **)(*DAT_00b5af2c + 4))();
      }
      else {
        (**(code **)(*DAT_00b5a794 + 0xc))();
        FUN_00401660();
        pvStack_10 = (void *)0x0;
        FUN_00401660(auStack_58 + 8,0,0xffffffff);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
        if (0xf < uStack_30) {
          _free(pvStack_44);
          return;
        }
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00719890 @ 0x00719890 ====

void FUN_00719890(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_3c [4];
  void *pvStack_28;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990024;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    iVar2 = *DAT_00b5ad00;
    (**(code **)(*DAT_00b5a97c + 0xc))();
    iVar2 = (**(code **)(iVar2 + 4))();
    if (iVar2 != 0) {
      if (*(short *)(iVar2 + 0x14) == 0) {
        (**(code **)(*DAT_00b5a6ac + 0x20))();
        iVar2 = FUN_00719ee0();
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(in_ECX + 0xc);
        FUN_004d8570();
        (**(code **)(*DAT_00b5af2c + 4))();
      }
      else {
        (**(code **)(*DAT_00b5a794 + 0xc))();
        FUN_00401660();
        pvStack_10 = (void *)0x0;
        FUN_00401660(auStack_3c + 8,0,0xffffffff);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
        if (0xf < uStack_14) {
          _free(pvStack_28);
          return;
        }
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_007199c0 @ 0x007199c0 ====

void FUN_007199c0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  undefined4 local_2c;
  void *local_28;
  undefined1 local_24;
  uint uStack_20;
  void *pvStack_1c;
  uint uStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990061;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ec6cc;
  local_4 = 1;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_event_009ec554,10);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8._0_1_ = 1;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_show_portaltime_009ec560,0xf);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  pvStack_c._0_1_ = 1;
  if (0xf < uStack_18) {
    _free(local_2c);
    return;
  }
  uStack_18 = 0xf;
  pvStack_1c = (void *)0x0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffffff00);
  FUN_00401740(s_hide_portaltime_009ec570,0xf);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x30);
  local_10._0_1_ = 1;
  if (0xf < pvStack_1c) {
    _free(unaff_EBX);
    return;
  }
  pvStack_1c = (void *)0xf;
  uStack_20 = 0;
  FUN_00401740(s_show_guildmarkeffect_009ec580,0x14);
  local_10 = CONCAT31(local_10._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x34);
  if (0xf < uStack_20) {
    _free(unaff_EBP);
    return;
  }
  DAT_00b5a9e4 = 0;
  if ((void *)in_ECX[6] == (void *)0x0) {
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    *in_ECX = &PTR_FUN_009ec624;
    ExceptionList = pvStack_1c;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00719b60 @ 0x00719b60 ====

undefined4 FUN_00719b60(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    FUN_007194b0(param_1);
  }
  else if (iVar2 == 0x70004) {
    cVar1 = FUN_00719400(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00719ba0 @ 0x00719ba0 ====

void FUN_00719ba0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *unaff_EDI;
  undefined1 *_Memory;
  undefined1 auStack_62 [6];
  uint *puStack_5c;
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
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009900be;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ec6cc;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  puStack_5c = (uint *)0x0;
  local_4 = 1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740();
  puStack_5c = (uint *)0xa;
  local_4._0_1_ = 2;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = local_40 & 0xffffff00;
  FUN_00401740();
  puStack_5c = &local_28;
  local_4 = CONCAT31(local_4._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 8))();
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
  FUN_00401740(&DAT_009ec513);
  local_10._0_1_ = 4;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_show_portaltime_009ec514);
  _Memory = auStack_46 + -10;
  local_10 = CONCAT31(local_10._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 8))(_Memory,0);
  if (0xf < local_44) {
    _free(unaff_EDI);
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
  FUN_00401740(&DAT_009ec524,0);
  uStack_1c._0_1_ = 6;
  local_44 = 0xf;
  FUN_00401740(s_hide_portaltime_009ec528,0xf);
  uStack_1c = CONCAT31(uStack_1c._1_3_,7);
  (**(code **)(*DAT_00b5a6c8 + 8))(&puStack_5c,0,&local_40);
  if (0xf < unaff_EBP) {
    _free(&local_44);
    return;
  }
  local_28._0_1_ = 1;
  if (0xf < uStack_34) {
    _free((void *)0x0);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  FUN_00401740(&DAT_009ec538,0);
  local_28._0_1_ = 8;
  FUN_00401740(s_show_guildmarkeffect_009ec53c,0x14);
  local_28 = CONCAT31(local_28._1_3_,9);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_62 + -6,0,auStack_46 + -6);
  if ((uint *)0xf < puStack_5c) {
    _free(_Memory);
    return;
  }
  puStack_5c = (uint *)0xf;
  if (0xf < local_40) {
    _free((void *)0x0);
    return;
  }
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a9e4 = (undefined4 *)0x0;
    ExceptionList = pvStack_3c;
    return;
  }
  DAT_00b5a9e4 = in_ECX;
  ExceptionList = pvStack_3c;
  return;
}


// ==== FUN_00719e70 @ 0x00719e70 ====

void FUN_00719e70(undefined4 param_1)

{
  undefined4 local_8;
  undefined4 uStack_4;
  
  local_8 = param_1;
  uStack_4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  FUN_0071a250(&local_8);
  return;
}


// ==== FUN_00719eb0 @ 0x00719eb0 ====

void FUN_00719eb0(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5230001;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  FUN_004244d0();
  return;
}


// ==== FUN_00719ee0 @ 0x00719ee0 ====

void FUN_00719ee0(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5230005;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  FUN_004244d0();
  return;
}


// ==== FUN_00719f10 @ 0x00719f10 ====

undefined4 FUN_00719f10(void)

{
  return 0x70420000;
}


// ==== FUN_00719f20 @ 0x00719f20 ====

undefined4 FUN_00719f20(void)

{
  return 0x70420001;
}


// ==== FUN_00719f30 @ 0x00719f30 ====

undefined4 FUN_00719f30(void)

{
  return 0x70420005;
}


// ==== FUN_00719f40 @ 0x00719f40 ====

undefined4 FUN_00719f40(void)

{
  return 0x70420006;
}


// ==== FUN_00719f50 @ 0x00719f50 ====

void FUN_00719f50(void)

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
  puStack_8 = &LAB_009900d8;
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


// ==== FUN_00719fc0 @ 0x00719fc0 ====

undefined1 FUN_00719fc0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_00719fd0 @ 0x00719fd0 ====

void FUN_00719fd0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00719fe0 @ 0x00719fe0 ====

void FUN_00719fe0(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  int extraout_ECX;
  int iVar6;
  int iVar7;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009900f0;
  local_10 = ExceptionList;
  local_1c = param_3[1];
  local_20 = *param_3;
  iVar3 = *(int *)(in_ECX + 4);
  local_14 = (undefined1 *)((int)register0x00000010 + -0x2c);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0xc) - iVar3 >> 3;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x2c);
    if (0x1fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar2 = FUN_00719f50();
      iVar3 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
    }
    if (uVar2 < iVar6 + param_2) {
      if (0x1fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
      }
      if (uVar2 < iVar6 + param_2) {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - iVar3 >> 3;
        }
        uVar2 = iVar3 + param_2;
      }
      pvVar4 = operator_new(uVar2 * 8);
      local_8 = 0;
      local_18 = pvVar4;
      iVar3 = FUN_00751a10(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_00429bc0(iVar3,param_2,&local_20);
      FUN_00751a10(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 8);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 8 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 8);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar6 = *(int *)(in_ECX + 8);
    iVar3 = param_2 * 8;
    if ((uint)(iVar6 - param_1 >> 3) < param_2) {
      FUN_00751a10(param_1,iVar6,iVar3 + param_1);
      local_8 = 2;
      FUN_004b9150(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 3),&local_20);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar3;
      FUN_00686630(param_1,*(int *)(in_ECX + 8) + param_2 * -8,&local_20);
      ExceptionList = local_10;
      return;
    }
    iVar7 = iVar6 + param_2 * -8;
    uVar5 = FUN_00751a10(iVar7,iVar6,iVar6);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00576790(param_1,iVar7,iVar6);
    FUN_00686630(param_1,iVar3 + param_1,&local_20);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0071a151 @ 0x0071a151 ====

void Catch_0071a151(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0071a230 @ 0x0071a230 ====

void FUN_0071a230(byte param_1)

{
  void *in_ECX;
  
  FUN_007199c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071a250 @ 0x0071a250 ====

void FUN_0071a250(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 3) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 3))) {
    FUN_00719fe0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00429bc0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 8;
  return;
}


// ==== FUN_0071a2c0 @ 0x0071a2c0 ====

void FUN_0071a2c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec7d0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071a2e0 @ 0x0071a2e0 ====

void FUN_0071a2e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec7dc;
  return;
}


// ==== FUN_0071a300 @ 0x0071a300 ====

void FUN_0071a300(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec7e4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b0e0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b0e0 = in_ECX;
  return;
}


// ==== FUN_0071a340 @ 0x0071a340 ====

void FUN_0071a340(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b0e0 = 0;
  *in_ECX = &PTR_FUN_009ec7d0;
  return;
}


// ==== FUN_0071a360 @ 0x0071a360 ====

void FUN_0071a360(void)

{
  int *piVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  int unaff_retaddr;
  undefined4 uStack_84;
  uint uStack_70;
  void *pvStack_34;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990140;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x26)) {
  case 0:
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar4 == 0) {
      FUN_00401830();
      puStack_8 = (undefined1 *)0x0;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    piVar1 = *(int **)(iVar4 + 0x20);
    if (piVar1 == (int *)0x0) {
      FUN_00401830();
      puStack_8 = (undefined1 *)0x1;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    piVar5 = (int *)(**(code **)(*piVar1 + 0x28))();
    (**(code **)(*piVar5 + 0x1c))();
    FUN_004dd240();
    (**(code **)(*piVar1 + 0x20))();
    (**(code **)(*DAT_00b5a730 + 0x10))();
    piVar5 = (int *)(**(code **)(*piVar1 + 0x28))();
    (**(code **)(*piVar5 + 0x1c))();
    FUN_004dd240(0xd);
    (**(code **)(*piVar1 + 0x20))();
    (**(code **)(*DAT_00b5a730 + 0x10))();
    uVar2 = *(uint *)(unaff_retaddr + 0x1c);
    uVar7 = 0;
    if (uVar2 != 0) {
      do {
        iVar4 = (**(code **)(*DAT_00b5ad20 + 0xc))();
        if (iVar4 == 0) {
          FUN_00401830(s_pItemArticle____NULL_009ec778);
          FUN_00406880((int)register0x00000010 + -0x88);
          if (uStack_70 < 0x10) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          _free(uStack_84);
          return;
        }
        uVar6 = (**(code **)(*DAT_00b5a980 + 8))(iVar4);
        FUN_00827140(uVar6);
        uVar7 = uVar7 + 1;
      } while ((uVar7 & 0xffff) < uVar2);
    }
    (**(code **)(*DAT_00b5b0e8 + 8))();
    (**(code **)(*DAT_00b5b0e4 + 8))();
    (**(code **)(*DAT_00b5a78c + 0x6c))();
    goto LAB_0071a6dc;
  case 1:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    break;
  case 2:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    goto LAB_0071a675;
  case 3:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    break;
  case 4:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
LAB_0071a675:
    FUN_00765c50((int)register0x00000010 + -0x88);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto LAB_0071a695;
  default:
    FUN_00401740();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
LAB_0071a6dc:
    (**(code **)(*DAT_00b5a790 + 4))();
    ExceptionList = pvStack_34;
    return;
  }
  FUN_00765c50((int)register0x00000010 + -0x88);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_0071a695:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0071a750 @ 0x0071a750 ====

undefined4 FUN_0071a750(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x502001a) {
      FUN_0071a360(param_1[3]);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0071a790 @ 0x0071a790 ====

void FUN_0071a790(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec7dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071a7b0 @ 0x0071a7b0 ====

void FUN_0071a7b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0071a340();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071a7d0 @ 0x0071a7d0 ====

void FUN_0071a7d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec8a4;
  return;
}


// ==== FUN_0071a7e0 @ 0x0071a7e0 ====

void FUN_0071a7e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec8a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071a800 @ 0x0071a800 ====

undefined1 FUN_0071a800(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_0071a810 @ 0x0071a810 ====

void FUN_0071a810(void)

{
  return;
}


// ==== FUN_0071a830 @ 0x0071a830 ====

void FUN_0071a830(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ec910;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0071a860 @ 0x0071a860 ====

void FUN_0071a860(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 unaff_ESI;
  
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009ec8e8;
  }
  FUN_00797a20(puVar2);
  *(undefined1 *)(in_ECX + 4) = 1;
  cVar1 = (**(code **)(*DAT_00b5a78c + 0x5c))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5a78c + 0x24))();
  }
  (**(code **)(*DAT_00b5a78c + 0x60))(7);
  (**(code **)(*DAT_00b5acd4 + 4))(8);
  *(short *)(in_ECX + 0xc) = (short)unaff_ESI;
  *(char *)(in_ECX + 0xe) = (char)((uint)unaff_ESI >> 0x10);
  return;
}


// ==== FUN_0071a8e0 @ 0x0071a8e0 ====

void FUN_0071a8e0(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x20))();
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ec8fc;
  }
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 1) = 0;
  (**(code **)(*DAT_00b5a78c + 0x60))(0);
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  return;
}


// ==== FUN_0071a930 @ 0x0071a930 ====

void FUN_0071a930(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x0071a949. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5b0e8 + 0xc))();
    return;
  }
  return;
}


// ==== FUN_0071a950 @ 0x0071a950 ====

bool FUN_0071a950(void)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*in_ECX + 0x2c))();
    return iVar2 != 0;
  }
  return false;
}


// ==== FUN_0071a980 @ 0x0071a980 ====

undefined4 FUN_0071a980(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x2c))();
  return 0;
}


// ==== FUN_0071a990 @ 0x0071a990 ====

void FUN_0071a990(void)

{
                    /* WARNING: Could not recover jumptable at 0x0071a998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b0e8 + 4))();
  return;
}


// ==== FUN_0071a9a0 @ 0x0071a9a0 ====

void FUN_0071a9a0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int *in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(6);
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*in_ECX + 0x2c))();
    if (iVar2 != 0) {
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = uVar3;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x5020009;
      *(undefined2 *)((int)pvVar4 + 6) = 0x18;
      iVar2 = FUN_004244d0();
      iVar5 = (**(code **)(*in_ECX + 0x2c))();
      *(undefined2 *)(iVar2 + 0x10) = *(undefined2 *)(iVar5 + 4);
      *(undefined1 *)(iVar2 + 0x12) = *(undefined1 *)(iVar5 + 6);
      *(short *)(iVar2 + 0x13) = (short)in_ECX[3];
      *(undefined1 *)(iVar2 + 0x15) = *(undefined1 *)((int)in_ECX + 0xe);
      FUN_004d8570(iVar2);
      (**(code **)(*DAT_00b5af2c + 4))(6);
    }
  }
  return;
}


// ==== FUN_0071aa40 @ 0x0071aa40 ====

undefined4 FUN_0071aa40(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_Degradewnd_009ec86c,0xf);
  if (iVar1 != 0) {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_Degradewnd_009ec87c,0xf);
    if (iVar1 != 0) {
      return 0;
    }
    (**(code **)(*in_ECX + 0x10))();
  }
  return 1;
}


// ==== FUN_0071aa90 @ 0x0071aa90 ====

undefined4 FUN_0071aa90(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_0071aa40(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0071aac0 @ 0x0071aac0 ====

void FUN_0071aac0(void)

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
  
  puStack_8 = &LAB_00990178;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ec924;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *(undefined1 *)((int)in_ECX + 0xd) = 0;
  *(undefined1 *)((int)in_ECX + 0xe) = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b0e4 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5b0e4 = in_ECX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_009ec826,0);
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = 0;
  FUN_00401740(s_show_Degradewnd_009ec828,0xf);
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
  FUN_00401740(&DAT_009ec838,0);
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_Degradewnd_009ec83c,0xf);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,auStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  if (local_28 < 0x10) {
    *(undefined1 *)(in_ECX + 1) = 0;
    in_ECX[2] = 0;
    *(undefined1 *)((int)in_ECX + 6) = 0;
    *(undefined1 *)((int)in_ECX + 5) = 0;
    ExceptionList = local_24;
    return;
  }
  _free(pvStack_3c);
  return;
}


// ==== FUN_0071ac50 @ 0x0071ac50 ====

void FUN_0071ac50(void)

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
  
  puStack_8 = &LAB_0099019a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ec924;
  local_4 = 0;
  DAT_00b5b0e4 = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_Degradewnd_009ec84c,0xf);
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
  FUN_00401740(s_hide_Degradewnd_009ec85c,0xf);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  if (uStack_18 < 0x10) {
    *in_ECX = &PTR_FUN_009ec8a4;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_0071ad30 @ 0x0071ad30 ====

undefined4 FUN_0071ad30(void)

{
  return 0x70400000;
}


// ==== FUN_0071ad40 @ 0x0071ad40 ====

undefined4 FUN_0071ad40(void)

{
  return 0x70400001;
}


// ==== FUN_0071ad50 @ 0x0071ad50 ====

undefined4 FUN_0071ad50(void)

{
  return 0x70400002;
}


// ==== FUN_0071ad60 @ 0x0071ad60 ====

void FUN_0071ad60(byte param_1)

{
  void *in_ECX;
  
  FUN_0071ac50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071ad80 @ 0x0071ad80 ====

void FUN_0071ad80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec9a8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071ada0 @ 0x0071ada0 ====

undefined4 FUN_0071ada0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0071adb0 @ 0x0071adb0 ====

void FUN_0071adb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec9bc;
  in_ECX[1] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b0e8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b0e8 = in_ECX;
  return;
}


// ==== FUN_0071ade0 @ 0x0071ade0 ====

void FUN_0071ade0(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0071ae00 @ 0x0071ae00 ====

void FUN_0071ae00(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0071ae60 @ 0x0071ae60 ====

void FUN_0071ae60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ec9bc;
  DAT_00b5b0e8 = 0;
  _free((void *)in_ECX[1]);
  return;
}


// ==== FUN_0071ae90 @ 0x0071ae90 ====

void FUN_0071ae90(byte param_1)

{
  void *in_ECX;
  
  FUN_0071ae60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071aeb0 @ 0x0071aeb0 ====

void FUN_0071aeb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ecc10;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071aee0 @ 0x0071aee0 ====

void FUN_0071aee0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ecc1c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b0dc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b0dc = in_ECX;
  return;
}


// ==== FUN_0071af20 @ 0x0071af20 ====

void FUN_0071af20(void)

{
  (**(code **)(*DAT_00b5af2c + 8))(6);
  (**(code **)(*DAT_00b5b0d4 + 0xc))();
  return;
}


// ==== FUN_0071af40 @ 0x0071af40 ====

void FUN_0071af40(void)

{
  (**(code **)(*DAT_00b5af2c + 8))(6);
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  (**(code **)(*DAT_00b5b0d4 + 0xc))();
  return;
}


// ==== FUN_0071af70 @ 0x0071af70 ====

void FUN_0071af70(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b0dc = 0;
  *in_ECX = &PTR_FUN_009ecc10;
  return;
}


// ==== FUN_0071af90 @ 0x0071af90 ====

void FUN_0071af90(void)

{
  int unaff_retaddr;
  
  (**(code **)(*DAT_00b5af2c + 8))();
  if (*(int *)(unaff_retaddr + 0x10) == 0) {
    (**(code **)(*DAT_00b5b0d4 + 0x48))();
    (**(code **)(*DAT_00b5b0d4 + 0x5c))();
  }
  else if (*(int *)(unaff_retaddr + 0x10) == 1) {
    FUN_00401740(s_SA_CashMoney_IN_CASH___ERROR_009eca08,0x1c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  return;
}


// ==== FUN_0071b010 @ 0x0071b010 ====

void FUN_0071b010(void)

{
  char cVar1;
  int unaff_retaddr;
  char *pcStack_54;
  uint uStack_50;
  uint uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *pvStack_28;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009901b8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  cVar1 = *(char *)(unaff_retaddr + 0x10);
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5b0d4 + 8))();
    uStack_38 = 0x71b13b;
    (**(code **)(*DAT_00b5acd4 + 4))();
  }
  else {
    if (cVar1 == '\x01') {
      uStack_50 = 0x17;
      uStack_38 = 0;
      pcStack_54 = s_SA_Open_IN_CASH___ERROR_009eca28;
      uStack_48 = uStack_48 & 0xffffff00;
      FUN_00401740();
      uStack_50 = 2;
      pcStack_54 = (char *)0x71b111;
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      ExceptionList = (void *)0x6;
      return;
    }
    if (cVar1 == '\x02') {
      uStack_38 = 0;
      uStack_3c = 0x71b06b;
      uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_3c = 0xffffffff;
      uStack_40 = 0;
      uStack_48 = 0x71b088;
      FUN_00401660();
      puStack_8 = (undefined1 *)&pcStack_54;
      uStack_3c = 0xf;
      uStack_40 = 0;
      pvStack_10 = (void *)0x0;
      uStack_50 = uStack_50 & 0xffffff00;
      FUN_00401660((int)register0x00000010 + -0x34,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if (0xf < uStack_14) {
        uStack_38 = 0x71b0cd;
        _free(pvStack_28);
        return;
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0071b0e2 @ 0x0071b0e2 ====

void FUN_0071b0e2(void)

{
  void *unaff_retaddr;
  undefined1 *puStack00000030;
  undefined1 auStack_1c [20];
  
  puStack00000030 = auStack_1c;
  FUN_00401740(s_SA_Open_IN_CASH___ERROR_009eca28,0x17);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  ExceptionList = unaff_retaddr;
  return;
}


// ==== FUN_0071b150 @ 0x0071b150 ====

/* WARNING: Removing unreachable block (ram,0x0071b640) */

void FUN_0071b150(void)

{
  undefined2 extraout_var;
  int unaff_retaddr;
  undefined *puStack_c0;
  undefined1 auStack_bc [8];
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined1 *puStack_98;
  undefined1 auStack_94 [4];
  undefined1 uStack_90;
  void *pvStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 auStack_50 [4];
  undefined1 uStack_4c;
  undefined4 *****apppppuStack_48 [3];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  void *pvStack_30;
  undefined1 *puStack_28;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00990212;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x10)) {
  case 0:
    (**(code **)(*DAT_00b5b0d4 + 0x48))();
    (**(code **)(*DAT_00b5b0d4 + 0x10))();
    FUN_00401830();
    uStack_80 = CONCAT22(extraout_var,*(undefined2 *)(unaff_retaddr + 0x14));
    pvStack_c = (void *)0x0;
    if (puStack_34 < (undefined1 *)0x10) {
      apppppuStack_48[0] = apppppuStack_48;
    }
    puStack_4 = auStack_bc;
    puStack_c0 = &DAT_009eca40;
    uStack_a0 = apppppuStack_48[0];
    FUN_00401830();
    puStack_c0 = auStack_94 + -8;
    FUN_00404230();
    uStack_a0 = (undefined4 *****)0x1;
    uStack_a4 = 0x71b21d;
    (**(code **)(*DAT_00b5b0d4 + 0x18))();
                    /* WARNING: Subroutine does not return */
    uStack_a4 = 0x71b226;
    FUN_00446f10();
  case 10:
    uStack_a8 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_ac = 0x71b3fb;
    FUN_00765c50();
    uStack_3c = 4;
    break;
  case 0xb:
    uStack_a0 = (undefined4 *****)0x71b423;
    FUN_00401830();
    uStack_a0 = (undefined4 *****)0x71b430;
    (**(code **)(*DAT_00b5b0d4 + 0x18))();
    uStack_a0 = (undefined4 *****)0x650005;
    uStack_a4 = 5;
    uStack_a8 = 0x71b442;
    uStack_a8 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_ac = 0x71b44c;
    FUN_00765c50();
    uStack_3c = 5;
    break;
  case 0xe:
    uStack_a0 = (undefined4 *****)0x71b471;
    FUN_00401830();
    uStack_a0 = (undefined4 *****)0x71b47e;
    (**(code **)(*DAT_00b5b0d4 + 0x18))();
    uStack_a0 = (undefined4 *****)0x650026;
    uStack_a4 = 5;
    uStack_a8 = 0x71b490;
    uStack_a8 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_ac = 0x71b49a;
    FUN_00765c50();
    uStack_3c = 6;
    break;
  case 0xffffffcb:
  case 0xfffffff8:
    uStack_84 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = 0;
    pvStack_88 = (void *)0x71b4ef;
    FUN_00401660();
    puStack_8 = auStack_94;
    puStack_98 = (undefined1 *)0xffffffff;
    uStack_a0 = (undefined4 *****)auStack_50;
    uStack_80 = 0;
    uStack_10 = 7;
    uStack_90 = 0;
    uStack_a4 = 0x71b51c;
    FUN_00401660();
    puStack_98 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_a0 = (undefined4 *****)0x0;
    uStack_a4 = 0;
    puStack_28 = (undefined1 *)&puStack_c0;
    FUN_00401830(s_NoUserName_009eca74);
    (**(code **)(*DAT_00b5b0d4 + 0x18))(2);
    goto LAB_0071b2cc;
  default:
    uStack_84 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0;
    pvStack_88 = (void *)0x71b586;
    FUN_00401660();
    puStack_8 = (undefined1 *)&puStack_98;
    uStack_80 = 0xf;
    uStack_84 = 0;
    uStack_a0 = (undefined4 *****)&DAT_009eca80;
    uStack_10 = 8;
    auStack_94[0] = 0;
    uStack_a4 = 0x71b5b6;
    FUN_00401740();
    uStack_a0 = (undefined4 *****)0x71b5c0;
    uStack_84 = FUN_00404230();
    uStack_80 = 0;
    uStack_10._0_1_ = 9;
    pvStack_88 = (void *)0x71b5d5;
    FUN_00401ff0();
    uStack_10 = CONCAT31(uStack_10._1_3_,8);
    if (uStack_1c < 0x10) {
      puStack_8 = auStack_94;
      puStack_98 = (undefined1 *)0xffffffff;
      uStack_1c = 0xf;
      uStack_20 = 0;
      pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
      uStack_a0 = (undefined4 *****)(auStack_50 + -0x1c);
      uStack_80 = 0;
      uStack_90 = 0;
      uStack_a4 = 0x71b620;
      FUN_00401660();
      puStack_98 = (undefined1 *)0x2;
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      uStack_a0 = (undefined4 *****)0x71b63d;
      _free(pvStack_88);
      return;
    }
    uStack_80 = 0x71b5ef;
    _free(pvStack_30);
    return;
  case 0xfffffff4:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x71b36c;
    FUN_00765c50();
    puStack_8 = auStack_94;
    puStack_98 = auStack_50;
    uStack_10 = 3;
    FUN_00765c50();
    puStack_98 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_a0 = (undefined4 *****)0x0;
    uStack_a4 = 0;
    puStack_28 = (undefined1 *)&puStack_c0;
    FUN_00401830(s_NoUserName_009eca50);
    (**(code **)(*DAT_00b5b0d4 + 0x18))(4);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xfffffff5:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_80 = 0x71b305;
    FUN_00765c50();
    puStack_8 = auStack_94;
    puStack_98 = auStack_50;
    uStack_10 = 2;
    FUN_00765c50();
    puStack_98 = (undefined1 *)0x2;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xfffffff6:
  case 0xfffffffc:
    uStack_a0 = (undefined4 *****)0x71b255;
    FUN_00401830();
    uStack_a0 = (undefined4 *****)0x71b262;
    (**(code **)(*DAT_00b5b0d4 + 0x18))();
    uStack_a0 = (undefined4 *****)0x650003;
    uStack_a4 = 5;
    uStack_a8 = 0x71b274;
    uStack_b0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a8 = 0xffffffff;
    uStack_ac = 0;
    uStack_b4 = 0x71b292;
    FUN_00401660();
    puStack_34 = (undefined1 *)&puStack_c0;
    uStack_a8 = 0xf;
    uStack_ac = 0;
    uStack_3c = 1;
    auStack_bc[0] = 0;
    FUN_00401660(auStack_94 + 0x18,0,0xffffffff);
    goto LAB_0071b2bf;
  }
  puStack_34 = (undefined1 *)&puStack_c0;
  FUN_00765c50(auStack_94 + 0x18);
LAB_0071b2bf:
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
LAB_0071b2cc:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0071b6c0 @ 0x0071b6c0 ====

/* WARNING: Removing unreachable block (ram,0x0071bb3c) */

void FUN_0071b6c0(void)

{
  char cVar1;
  int *piVar2;
  int unaff_retaddr;
  undefined1 auStack_a8 [12];
  uint uStack_8c;
  void *pvStack_50;
  void *pvStack_4c;
  uint uStack_38;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990264;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined4 *)(unaff_retaddr + 0x10)) {
  case 0:
    (**(code **)(*DAT_00b5b0d4 + 0x48))();
    piVar2 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
    cVar1 = (**(code **)(*piVar2 + 8))();
    if (cVar1 == '\0') {
      FUN_00401830();
      FUN_00796d50();
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    (**(code **)(*piVar2 + 0x78))();
    (**(code **)(*DAT_00b5a980 + 8))();
    FUN_00827140();
    (**(code **)(*DAT_00b5a78c + 0x6c))();
    (**(code **)(*DAT_00b5b0d4 + 0x10))();
    FUN_00401830();
    (**(code **)(*DAT_00b5b0d4 + 0x18))();
    break;
  case 10:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    goto LAB_0071b98a;
  case 0xb:
    FUN_00401830();
    (**(code **)(*DAT_00b5b0d4 + 0x18))();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    goto LAB_0071b98a;
  case 0xe:
    FUN_00401830();
    (**(code **)(*DAT_00b5b0d4 + 0x18))();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
LAB_0071b98a:
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xfffffff4:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    FUN_00401830(s_NoUserName_009ecac8);
    (**(code **)(*DAT_00b5b0d4 + 0x18))(3);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xfffffff5:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    FUN_00765c50();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 0xfffffff6:
  case 0xfffffffc:
    FUN_00401830();
    (**(code **)(*DAT_00b5b0d4 + 0x18))();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    FUN_00401660(auStack_a8 + 0x10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_8c) {
      _free((void *)0x6);
      return;
    }
    break;
  default:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    FUN_00401740();
    FUN_00404230();
    FUN_00401ff0();
    if (0xf < uStack_38) {
      _free(pvStack_4c);
      return;
    }
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
  }
  ExceptionList = pvStack_50;
  return;
}


// ==== FUN_0071bba0 @ 0x0071bba0 ====

/* WARNING: Removing unreachable block (ram,0x0071bc65) */
/* WARNING: Removing unreachable block (ram,0x0071bc10) */

void FUN_0071bba0(void)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char *pcVar6;
  void *unaff_EBX;
  undefined1 auStack_80 [4];
  undefined1 uStack_7c;
  undefined4 uStack_74;
  undefined4 uStack_70;
  char *pcStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  uint uStack_34;
  void *pvStack_1c;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990286;
  puStack_c = ExceptionList;
  ExceptionList = &puStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    FUN_00401740();
    uStack_4 = 0;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar5 = *(int **)(iVar3 + 0x20);
  if (piVar5 == (int *)0x0) {
    FUN_00401740();
    uStack_4 = 1;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar4 = (int *)(**(code **)(*piVar5 + 0x28))();
  uStack_64 = 0;
  uStack_68 = 0x71bc8c;
  uStack_68 = (**(code **)(*piVar4 + 0x1c))();
  uStack_68 = uStack_68 & 0xffff;
  pcStack_6c = (char *)0xd;
  uStack_70 = 0x71bc97;
  FUN_004dd240();
  piVar5 = (int *)(**(code **)(*piVar5 + 0x20))();
  if (piVar5 != (int *)0x0) {
    uStack_64 = 5;
    uStack_68 = 0x71bcbe;
    uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_68 = 0xffffffff;
    pcStack_6c = (char *)0x0;
    uStack_74 = 0x71bcd7;
    FUN_00401660();
    uStack_68 = 0x71bce6;
    iVar3 = (**(code **)(*piVar5 + 0x2c))();
    pcStack_6c = (char *)(iVar3 + 0x32);
    pcVar6 = pcStack_6c;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uStack_68 = (int)pcVar6 - (iVar3 + 0x33);
    uStack_70 = 0x71bd06;
    FUN_004020e0();
    uStack_68 = 1;
    pcStack_6c = &DAT_009ecb0c;
    uStack_70 = 0x71bd16;
    FUN_004020e0();
    puStack_c = auStack_80;
    uStack_68 = 0xf;
    pcStack_6c = (char *)0x0;
    uStack_7c = 0;
    FUN_00401660(auStack_80 + 0x2c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    puStack_c = (undefined1 *)0xffffffff;
    if (0xf < uStack_34) {
      uStack_64 = 0x71bd5b;
      _free(unaff_EBX);
      return;
    }
  }
  uStack_64 = 1;
  uStack_68 = 0x71bd78;
  (**(code **)(*DAT_00b5a730 + 0x10))();
  uStack_68 = 0x71bd83;
  (**(code **)(*DAT_00b5a790 + 4))();
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_0071bda0 @ 0x0071bda0 ====

/* WARNING: Removing unreachable block (ram,0x0071be65) */
/* WARNING: Removing unreachable block (ram,0x0071be10) */

void FUN_0071bda0(void)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char *pcVar6;
  void *unaff_EBX;
  undefined1 auStack_80 [4];
  undefined1 uStack_7c;
  undefined4 uStack_74;
  undefined4 uStack_70;
  char *pcStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  uint uStack_34;
  void *pvStack_1c;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009902a8;
  puStack_c = ExceptionList;
  ExceptionList = &puStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    FUN_00401740();
    uStack_4 = 0;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar5 = *(int **)(iVar3 + 0x34);
  if (piVar5 == (int *)0x0) {
    FUN_00401740();
    uStack_4 = 1;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar4 = (int *)(**(code **)(*piVar5 + 0x20))();
  uStack_64 = 0;
  uStack_68 = 0x71be8c;
  uStack_68 = (**(code **)(*piVar4 + 0x1c))();
  uStack_68 = uStack_68 & 0xffff;
  pcStack_6c = (char *)0xd;
  uStack_70 = 0x71be97;
  FUN_004dd240();
  piVar5 = (int *)(**(code **)(*piVar5 + 0x24))();
  if (piVar5 != (int *)0x0) {
    uStack_64 = 5;
    uStack_68 = 0x71bebe;
    uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_68 = 0xffffffff;
    pcStack_6c = (char *)0x0;
    uStack_74 = 0x71bed7;
    FUN_00401660();
    uStack_68 = 0x71bee6;
    iVar3 = (**(code **)(*piVar5 + 0x2c))();
    pcStack_6c = (char *)(iVar3 + 0x32);
    pcVar6 = pcStack_6c;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uStack_68 = (int)pcVar6 - (iVar3 + 0x33);
    uStack_70 = 0x71bf06;
    FUN_004020e0();
    uStack_68 = 1;
    pcStack_6c = &DAT_009ecb2c;
    uStack_70 = 0x71bf16;
    FUN_004020e0();
    puStack_c = auStack_80;
    uStack_68 = 0xf;
    pcStack_6c = (char *)0x0;
    uStack_7c = 0;
    FUN_00401660(auStack_80 + 0x2c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    puStack_c = (undefined1 *)0xffffffff;
    if (0xf < uStack_34) {
      uStack_64 = 0x71bf5b;
      _free(unaff_EBX);
      return;
    }
  }
  uStack_64 = 1;
  uStack_68 = 0x71bf78;
  (**(code **)(*DAT_00b5a730 + 0x10))();
  uStack_68 = 0x71bf83;
  (**(code **)(*DAT_00b5adc4 + 0x4c))();
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_0071bfa0 @ 0x0071bfa0 ====

/* WARNING: Removing unreachable block (ram,0x0071c065) */
/* WARNING: Removing unreachable block (ram,0x0071c010) */

void FUN_0071bfa0(void)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char *pcVar6;
  void *unaff_EBX;
  undefined1 auStack_80 [4];
  undefined1 uStack_7c;
  undefined4 uStack_74;
  undefined4 uStack_70;
  char *pcStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  uint uStack_34;
  void *pvStack_1c;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009902ca;
  puStack_c = ExceptionList;
  ExceptionList = &puStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    FUN_00401740();
    uStack_4 = 0;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar5 = *(int **)(iVar3 + 0x2c);
  if (piVar5 == (int *)0x0) {
    FUN_00401740();
    uStack_4 = 1;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar4 = (int *)(**(code **)(*piVar5 + 0x24))();
  uStack_64 = 0;
  uStack_68 = 0x71c08c;
  uStack_68 = (**(code **)(*piVar4 + 0x1c))();
  uStack_68 = uStack_68 & 0xffff;
  pcStack_6c = (char *)0xd;
  uStack_70 = 0x71c097;
  FUN_004dd240();
  piVar5 = (int *)(**(code **)(*piVar5 + 0x28))();
  if (piVar5 != (int *)0x0) {
    uStack_64 = 5;
    uStack_68 = 0x71c0be;
    uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_68 = 0xffffffff;
    pcStack_6c = (char *)0x0;
    uStack_74 = 0x71c0d7;
    FUN_00401660();
    uStack_68 = 0x71c0e6;
    iVar3 = (**(code **)(*piVar5 + 0x2c))();
    pcStack_6c = (char *)(iVar3 + 0x32);
    pcVar6 = pcStack_6c;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uStack_68 = (int)pcVar6 - (iVar3 + 0x33);
    uStack_70 = 0x71c106;
    FUN_004020e0();
    uStack_68 = 1;
    pcStack_6c = &DAT_009ecb50;
    uStack_70 = 0x71c116;
    FUN_004020e0();
    puStack_c = auStack_80;
    uStack_68 = 0xf;
    pcStack_6c = (char *)0x0;
    uStack_7c = 0;
    FUN_00401660(auStack_80 + 0x2c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    puStack_c = (undefined1 *)0xffffffff;
    if (0xf < uStack_34) {
      uStack_64 = 0x71c15b;
      _free(unaff_EBX);
      return;
    }
  }
  uStack_64 = 1;
  uStack_68 = 0x71c178;
  (**(code **)(*DAT_00b5a730 + 0x10))();
  uStack_68 = 0x71c183;
  (**(code **)(*DAT_00b5b118 + 4))();
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_0071c1a0 @ 0x0071c1a0 ====

/* WARNING: Removing unreachable block (ram,0x0071c265) */
/* WARNING: Removing unreachable block (ram,0x0071c210) */

void FUN_0071c1a0(void)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  undefined1 auStack_46 [2];
  void *pvStack_44;
  uint uStack_30;
  void *pvStack_1c;
  void *pvStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009902ec;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    FUN_00401740();
    uStack_4 = 0;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(int **)(iVar3 + 0x24) == (int *)0x0) {
    FUN_00401740();
    uStack_4 = 1;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x24) + 0x20))();
  if (piVar4 != (int *)0x0) {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    iVar3 = (**(code **)(*piVar4 + 0x2c))();
    pcVar5 = (char *)(iVar3 + 0x32);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_004020e0();
    FUN_004020e0();
    FUN_00401660(auStack_46 + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    puStack_8 = (undefined1 *)0xffffffff;
    if (0xf < uStack_30) {
      _free(pvStack_44);
      return;
    }
  }
  (**(code **)(*DAT_00b5a730 + 0x10))();
  (**(code **)(*DAT_00b5a790 + 4))();
  iVar3 = *(int *)(puStack_8 + 0x10);
  if (iVar3 == 6) {
    (**(code **)(*DAT_00b5a9e4 + 0x2c))();
    ExceptionList = pvStack_1c;
    return;
  }
  if (iVar3 != 7) {
    if (iVar3 == 0x13) {
      (**(code **)(*DAT_00b5a9e4 + 0x2c))();
      ExceptionList = pvStack_1c;
      return;
    }
    if (iVar3 != 0x14) {
      ExceptionList = pvStack_18;
      return;
    }
  }
  (**(code **)(*DAT_00b5a9e4 + 0x2c))();
  ExceptionList = pvStack_18;
  return;
}


// ==== FUN_0071c3f0 @ 0x0071c3f0 ====

/* WARNING: Removing unreachable block (ram,0x0071c4b4) */
/* WARNING: Removing unreachable block (ram,0x0071c460) */

void FUN_0071c3f0(void)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  undefined1 auStack_46 [6];
  void *pvStack_40;
  uint uStack_2c;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099030e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    FUN_00401740();
    uStack_4 = 0;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(int **)(iVar3 + 0x1c) == (int *)0x0) {
    FUN_00401740();
    uStack_4 = 1;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x1c) + 0x18))();
  if (piVar4 != (int *)0x0) {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0x2;
    iVar3 = (**(code **)(*piVar4 + 0x2c))();
    pcVar5 = (char *)(iVar3 + 0x32);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_004020e0();
    FUN_004020e0();
    FUN_00401660(auStack_46 + -6,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uStack_4 = 0xffffffff;
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
  }
  (**(code **)(*DAT_00b5a730 + 0x10))();
  (**(code **)(*DAT_00b5a790 + 8))();
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_0071c5c0 @ 0x0071c5c0 ====

void FUN_0071c5c0(void)

{
  int *piVar1;
  int unaff_retaddr;
  undefined1 auStack_8c [4];
  void *pvStack_7c;
  undefined4 uStack_6c;
  uint uStack_68;
  void *pvStack_60;
  undefined4 uStack_58;
  undefined4 uStack_54;
  uint uStack_4c;
  undefined4 uStack_34;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990340;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x10)) {
  case 0:
    piVar1 = (int *)(**(code **)(*DAT_00b5ad20 + 4))();
    if (piVar1 == (int *)0x0) {
      FUN_00401830();
      puStack_8 = (undefined1 *)0x1;
      FUN_004022a0();
      puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
      FUN_00796d50();
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_10 = (void *)0x0;
    (**(code **)(*piVar1 + 0x2c))();
    FUN_004021f0();
    FUN_004021f0();
    FUN_00765c50(&uStack_6c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    (**(code **)(*DAT_00b5ad20 + 0x10))(piVar1);
    uStack_34 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0xf;
    uStack_58 = 0;
    uStack_68 = uStack_68 & 0xffffff00;
    FUN_00401660();
    pvStack_10 = (void *)0x3;
    FUN_00401660(&uStack_6c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    puStack_8 = (undefined1 *)0xffffffff;
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
    break;
  case 2:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_10 = (void *)0x4;
    FUN_00401660(auStack_8c + 4,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    puStack_8 = (undefined1 *)0xffffffff;
    if (0xf < uStack_68) {
      _free(pvStack_7c);
      return;
    }
    uStack_68 = 0xf;
    uStack_6c = 0;
    break;
  case 3:
    FUN_00401830();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
  }
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5a790 + 8))();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0071c890 @ 0x0071c890 ====

undefined4 FUN_0071c890(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0xd000008) {
    if (uVar1 == 0xd000007) {
      FUN_0071b150(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 < 0xd000002) {
      if (uVar1 == 0xd000001) {
        FUN_0071af90(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x5020008) {
        FUN_0071c5c0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x5200001) {
        FUN_0071b010(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x5200003) {
        FUN_0071af40(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
    else {
      if (uVar1 == 0xd000003) {
        FUN_0071b6c0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0xd000005) {
        FUN_0071af20(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
  }
  else {
    switch(uVar1 + 0xf2fffff8) {
    case 0:
      FUN_0071c1a0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 1:
      FUN_0071bba0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 2:
      FUN_0071c3f0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 3:
      FUN_0071bda0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 4:
      FUN_0071bfa0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0071c9f0 @ 0x0071c9f0 ====

undefined4 FUN_0071c9f0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0071c890(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0071ca20 @ 0x0071ca20 ====

void FUN_0071ca20(byte param_1)

{
  void *in_ECX;
  
  FUN_0071af70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071ca40 @ 0x0071ca40 ====

void FUN_0071ca40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ecc8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071ca60 @ 0x0071ca60 ====

undefined1 FUN_0071ca60(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_0071ca70 @ 0x0071ca70 ====

void FUN_0071ca70(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0071ca80 @ 0x0071ca80 ====

undefined4 FUN_0071ca80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0071ca90 @ 0x0071ca90 ====

void FUN_0071ca90(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 5) = param_1;
  return;
}


// ==== FUN_0071caa0 @ 0x0071caa0 ====

void FUN_0071caa0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 6) = param_1;
  return;
}


// ==== FUN_0071cab0 @ 0x0071cab0 ====

undefined1 FUN_0071cab0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 5);
}


// ==== FUN_0071cac0 @ 0x0071cac0 ====

undefined1 FUN_0071cac0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 6);
}


// ==== FUN_0071cae0 @ 0x0071cae0 ====

void FUN_0071cae0(char param_1,undefined4 param_2,int param_3)

{
  int *in_ECX;
  
  in_ECX[4] = param_3;
  if (param_1 == '\0') {
    (**(code **)(*in_ECX + 0x1c))();
    return;
  }
  (**(code **)(*in_ECX + 0x74))(param_2);
  return;
}


// ==== FUN_0071cb20 @ 0x0071cb20 ====

void FUN_0071cb20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ecd04;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  in_ECX[2] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b0d4 = (undefined4 *)0x0;
    *(undefined1 *)(in_ECX + 3) = 0;
    return;
  }
  DAT_00b5b0d4 = in_ECX;
  *(undefined1 *)(in_ECX + 3) = 0;
  return;
}


// ==== FUN_0071cb70 @ 0x0071cb70 ====

void FUN_0071cb70(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009e945c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0071cba0 @ 0x0071cba0 ====

void FUN_0071cba0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\x01') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009e940c;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 4) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_0071cbe0 @ 0x0071cbe0 ====

undefined4 FUN_0071cbe0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 0;
    return 1;
  }
  *puVar1 = &PTR_FUN_009e9420;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 4) = 0;
  return 1;
}


// ==== FUN_0071cc20 @ 0x0071cc20 ====

void FUN_0071cc20(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009e9470;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0071cc50 @ 0x0071cc50 ====

void FUN_0071cc50(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != 1) {
    puVar1 = operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_00797a20(0);
      return;
    }
    *puVar1 = &PTR_FUN_009e9498;
    FUN_00797a20(puVar1);
    return;
  }
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009e9484;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0071ccb0 @ 0x0071ccb0 ====

void FUN_0071ccb0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0071ccb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b0d8 + 8))();
  return;
}


// ==== FUN_0071ccc0 @ 0x0071ccc0 ====

void FUN_0071ccc0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0071ccc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b0d8 + 0xc))();
  return;
}


// ==== FUN_0071ccd0 @ 0x0071ccd0 ====

void FUN_0071ccd0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0071ccd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b0d8 + 0x14))();
  return;
}


// ==== FUN_0071cce0 @ 0x0071cce0 ====

void FUN_0071cce0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0071cce8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b0d8 + 0x1c))();
  return;
}


// ==== FUN_0071ccf0 @ 0x0071ccf0 ====

uint FUN_0071ccf0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_0071cd00 @ 0x0071cd00 ====

void FUN_0071cd00(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(6);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5200000;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(6);
  }
  return;
}


// ==== FUN_0071cd60 @ 0x0071cd60 ====

void FUN_0071cd60(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(6);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5200002;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(6);
  }
  return;
}


// ==== FUN_0071cdc0 @ 0x0071cdc0 ====

void FUN_0071cdc0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(6);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5020007;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(6);
  }
  return;
}


// ==== FUN_0071ce20 @ 0x0071ce20 ====

void FUN_0071ce20(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b0d4 = 0;
  *in_ECX = &PTR_FUN_009ecc8c;
  return;
}


// ==== FUN_0071ce40 @ 0x0071ce40 ====

undefined4 FUN_0071ce40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(*DAT_00b5b0d8 + 0x10))(param_1,param_2,param_3,param_4);
  return param_1;
}


// ==== FUN_0071ce70 @ 0x0071ce70 ====

void FUN_0071ce70(void)

{
  char cVar1;
  int iVar2;
  undefined4 uStack_34;
  void *pvStack_28;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990358;
  pvStack_c = ExceptionList;
  uStack_34 = 6;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*DAT_00b5ac1c + 0x28))();
    if (cVar1 != '\0') {
      iVar2 = (**(code **)(*DAT_00b5a78c + 100))();
      if (iVar2 == 0) {
        (**(code **)(*DAT_00b5a6ac + 0x20))();
        FUN_006fda40();
        FUN_004d8570();
        (**(code **)(*DAT_00b5af2c + 4))();
      }
      else {
        (**(code **)(*DAT_00b5a794 + 0xc))();
        FUN_00401660();
        pvStack_10 = (void *)0x0;
        FUN_00401660(&uStack_34,0,0xffffffff);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
        if (0xf < uStack_14) {
          _free(pvStack_28);
          return;
        }
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0071cf90 @ 0x0071cf90 ====

void FUN_0071cf90(undefined4 param_1,void *param_2)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined2 unaff_retaddr;
  uint in_stack_0000001c;
  undefined1 auStack_94 [4];
  undefined1 uStack_90;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 *puStack_7c;
  undefined *puStack_78;
  undefined4 uStack_68;
  int iStack_44;
  undefined1 *puStack_40;
  void *pvStack_30;
  void *pvStack_28;
  uint uStack_1c;
  uint uStack_14;
  undefined1 *puStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099037a;
  pvStack_c = ExceptionList;
  uStack_68 = 6;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5b0d8 + 0x18))();
    if (iStack_44 == 0) {
      puStack_78 = (undefined *)0x5;
      puStack_7c = (undefined1 *)0x71d00a;
      uStack_84 = (**(code **)(*DAT_00b5a794 + 0xc))();
      puStack_7c = (undefined1 *)0xffffffff;
      uStack_80 = 0;
      uStack_88 = 0x71d028;
      FUN_00401660();
      puStack_10 = auStack_94;
      puStack_7c = (undefined1 *)0xf;
      uStack_80 = 0;
      uStack_90 = 0;
      FUN_00401660(&uStack_68,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if ((undefined1 *)0xf < puStack_40) {
        _free((void *)0x0);
        return;
      }
      if (0xf < uStack_14) {
        _free(pvStack_28);
        return;
      }
    }
    else {
      puStack_8 = puStack_40;
      puStack_10 = (undefined1 *)((uint)puStack_10 & 0xffffff00);
      if (0xf < uStack_1c) {
        puStack_78 = (undefined *)0x71d0da;
        _free(pvStack_30);
        return;
      }
      uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      puStack_78 = (undefined *)0x71d0f4;
      pvVar3 = operator_new(0x400);
      *(undefined4 *)((int)pvVar3 + 8) = uVar2;
      *(undefined4 *)((int)pvVar3 + 0xc) = 0xd000002;
      *(undefined2 *)((int)pvVar3 + 6) = 0x2c;
      iVar4 = FUN_004244d0();
      *(undefined2 *)(iVar4 + 0x10) = unaff_retaddr;
      puStack_7c = auStack_94 + 0x34;
      puStack_78 = &DAT_009ecc74;
      uStack_80 = 0x71d135;
      FUN_006fdb20();
      puStack_78 = (undefined *)0x71d145;
      FUN_006fdaf0();
      *(undefined1 **)(iVar4 + 0x28) = puStack_8;
      puStack_78 = (undefined *)0x71d158;
      FUN_004d8570();
      puStack_78 = (undefined *)0x71d165;
      (**(code **)(*DAT_00b5af2c + 4))();
    }
  }
  if (in_stack_0000001c < 0x10) {
    ExceptionList = puStack_10;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_0071d190 @ 0x0071d190 ====

void FUN_0071d190(undefined4 param_1,undefined1 param_2,void *param_3)

{
  undefined4 *puVar1;
  uint in_stack_00000020;
  undefined2 in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined4 in_stack_0000002c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099038c;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  puVar1 = operator_new(0x30);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009e94ac;
    puVar1[8] = 0xf;
    puVar1[7] = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
  }
  puVar1[1] = param_1;
  FUN_00401660(&param_2,0,0xffffffff);
  *(undefined2 *)(puVar1 + 9) = in_stack_00000024;
  puVar1[10] = in_stack_00000028;
  puVar1[0xb] = in_stack_0000002c;
  FUN_00797a20(puVar1);
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_3);
  return;
}


// ==== FUN_0071d240 @ 0x0071d240 ====

void FUN_0071d240(ushort param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = operator_new(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009e94c0;
    puVar1[7] = 0xf;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
  }
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,param_1 | 0x3980000);
  FUN_00401660(uVar2,0,0xffffffff);
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0071d2b0 @ 0x0071d2b0 ====

/* WARNING: Removing unreachable block (ram,0x0071d4ae) */
/* WARNING: Removing unreachable block (ram,0x0071d5bd) */
/* WARNING: Removing unreachable block (ram,0x0071d7d6) */
/* WARNING: Removing unreachable block (ram,0x0071d5df) */
/* WARNING: Removing unreachable block (ram,0x0071d7f8) */
/* WARNING: Removing unreachable block (ram,0x0071d59e) */

void FUN_0071d2b0(void *param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  void *unaff_EDI;
  uint in_stack_00000018;
  void *in_stack_00000024;
  uint in_stack_00000038;
  undefined4 uStack_2d8;
  void *pvStack_2ac;
  uint uStack_2a8;
  uint uStack_298;
  uint uStack_25c;
  undefined4 uStack_258;
  void *pvStack_248;
  uint uStack_234;
  void *pvStack_228;
  uint uStack_214;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009903f3;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    piVar2 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
    pcVar3 = (char *)(**(code **)(*piVar2 + 0x70))();
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740();
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_2d8 = 0x71d3c5;
    FUN_00401660();
    pvStack_10 = (void *)CONCAT31(pvStack_10._1_3_,4);
    uStack_2d8 = 0x71d3de;
    FUN_00401660();
    uStack_2d8 = 0x71d3ef;
    FUN_00401ff0();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_2d8 = 0;
    FUN_00401660();
    uStack_2d8 = 0;
    FUN_00401ff0();
    if (0xf < uStack_2a8) {
      uStack_2d8 = 0x71d434;
      _free(unaff_EDI);
      return;
    }
    uStack_2d8 = 0;
    FUN_00401660();
    uStack_2d8 = 5;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    FUN_00401ff0();
    (**(code **)(*DAT_00b5b0d8 + 0x18))();
    if (uStack_25c == 0) {
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      FUN_00401660(&uStack_2d8,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if (0xf < uStack_298) {
        _free(pvStack_2ac);
        return;
      }
      if (0xf < uStack_214) {
        _free(pvStack_228);
        return;
      }
      if (0xf < in_stack_00000018) {
        _free(param_1);
        return;
      }
    }
    else {
      if (0xf < uStack_234) {
        _free(pvStack_248);
        return;
      }
      uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar5 = operator_new(0x400);
      *(undefined4 *)((int)pvVar5 + 8) = uVar4;
      *(undefined4 *)((int)pvVar5 + 0xc) = 0xd000006;
      *(undefined2 *)((int)pvVar5 + 6) = 0x278;
      iVar6 = FUN_004244d0();
      *(undefined2 *)(iVar6 + 0x10) = (undefined2)local_4;
      FUN_006fdb20();
      FUN_006fdaf0();
      FUN_0047aa30();
      FUN_0047aa00();
      FUN_00495d40();
      FUN_00495ce0();
      FUN_00495d70();
      FUN_00495d10();
      *(undefined1 *)(iVar6 + 0x24f) = 2;
      *(undefined4 *)(iVar6 + 0x274) = uStack_258;
      FUN_004d8570();
      (**(code **)(*DAT_00b5af2c + 4))();
      if (0xf < uStack_25c) {
        _free((void *)0x0);
        return;
      }
      if (0xf < in_stack_00000018) {
        _free(param_1);
        return;
      }
    }
  }
  else if (0xf < in_stack_00000018) {
    _free(param_1);
    return;
  }
  if (in_stack_00000038 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(in_stack_00000024);
  return;
}


// ==== FUN_0071d880 @ 0x0071d880 ====

void FUN_0071d880(byte param_1)

{
  void *in_ECX;
  
  FUN_0071ce20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071d8a0 @ 0x0071d8a0 ====

void FUN_0071d8a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ecdc0;
  return;
}


// ==== FUN_0071d8b0 @ 0x0071d8b0 ====

void FUN_0071d8b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ecdc0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071d8d0 @ 0x0071d8d0 ====

void FUN_0071d8d0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099040b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(4);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00788780();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  FUN_007889a0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0071d930 @ 0x0071d930 ====

int FUN_0071d930(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    FUN_0071d8d0();
  }
  if (*(int *)(in_ECX + 8) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8)) / 0x2c;
}


// ==== FUN_0071d960 @ 0x0071d960 ====

undefined4 * FUN_0071d960(undefined4 *param_1,char param_2,char param_3,char param_4)

{
  undefined4 *puVar1;
  void **ppvVar2;
  undefined4 *extraout_EAX;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 local_38;
  undefined4 local_34;
  char local_30;
  char local_2f;
  char local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099041d;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  puVar3 = *(undefined4 **)(in_ECX + 8);
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  local_4 = 0;
  ppvVar2 = &local_c;
  local_c = ExceptionList;
  do {
    ExceptionList = ppvVar2;
    if (puVar3 == puVar1) {
      *(char *)(param_1 + 2) = local_30;
      param_1[1] = local_34;
      *(char *)((int)param_1 + 9) = local_2f;
      *(char *)((int)param_1 + 10) = local_2e;
      *(undefined1 *)((int)param_1 + 0xb) = local_2d;
      *param_1 = 0;
      *(undefined1 *)(param_1 + 3) = local_2c;
      local_38 = 0;
      param_1[10] = 0xf;
      param_1[9] = 0;
      *(undefined1 *)(param_1 + 5) = 0;
      FUN_00401660(local_28,0,0xffffffff);
LAB_0071da63:
      if (local_10 < 0x10) {
        ExceptionList = local_c;
        return param_1;
      }
      _free(local_24);
      return extraout_EAX;
    }
    local_38 = *puVar3;
    local_34 = puVar3[1];
    local_30 = *(char *)(puVar3 + 2);
    local_2f = *(char *)((int)puVar3 + 9);
    local_2e = *(char *)((int)puVar3 + 10);
    local_2d = *(undefined1 *)((int)puVar3 + 0xb);
    local_2c = *(undefined1 *)(puVar3 + 3);
    FUN_00401660(puVar3 + 4,0,0xffffffff);
    if (((local_30 == param_2) && (local_2f == param_3)) && (local_2e == param_4)) {
      FUN_0071dfb0(&local_38);
      goto LAB_0071da63;
    }
    puVar3 = puVar3 + 0xb;
    ppvVar2 = ExceptionList;
  } while( true );
}


// ==== FUN_0071daa0 @ 0x0071daa0 ====

undefined4 * FUN_0071daa0(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *extraout_EAX;
  int in_ECX;
  undefined4 *puVar3;
  int *local_38;
  undefined4 local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099042f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(int *)(in_ECX + 0x14) == 0) {
    ExceptionList = &pvStack_c;
    FUN_0071d8d0();
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  puVar3 = *(undefined4 **)(in_ECX + 8);
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  local_4 = 0;
  do {
    if (puVar3 == puVar1) {
      *(undefined1 *)(param_1 + 2) = local_30;
      param_1[1] = local_34;
      *(undefined1 *)((int)param_1 + 9) = local_2f;
      *(undefined1 *)((int)param_1 + 10) = local_2e;
      *(undefined1 *)((int)param_1 + 0xb) = local_2d;
      *param_1 = 0;
      *(undefined1 *)(param_1 + 3) = local_2c;
      local_38 = (int *)0x0;
      param_1[10] = 0xf;
      param_1[9] = 0;
      *(undefined1 *)(param_1 + 5) = 0;
      FUN_00401660(local_28,0,0xffffffff);
joined_r0x0071dbe8:
      if (local_10 < 0x10) {
        ExceptionList = pvStack_c;
        return param_1;
      }
      _free(local_24);
      return extraout_EAX;
    }
    local_38 = (int *)*puVar3;
    local_34 = puVar3[1];
    local_30 = *(undefined1 *)(puVar3 + 2);
    local_2f = *(undefined1 *)((int)puVar3 + 9);
    local_2e = *(undefined1 *)((int)puVar3 + 10);
    local_2d = *(undefined1 *)((int)puVar3 + 0xb);
    local_2c = *(undefined1 *)(puVar3 + 3);
    FUN_00401660(puVar3 + 4,0,0xffffffff);
    if ((local_38 != (int *)0x0) &&
       (uVar2 = (**(code **)(*local_38 + 0x1c))(), (uVar2 & 0xffff) == param_2)) {
      FUN_0071dfb0(&local_38);
      goto joined_r0x0071dbe8;
    }
    puVar3 = puVar3 + 0xb;
  } while( true );
}


// ==== FUN_0071dc00 @ 0x0071dc00 ====

/* WARNING: Removing unreachable block (ram,0x0071dcac) */
/* WARNING: Removing unreachable block (ram,0x0071dcd6) */

undefined4 FUN_0071dc00(char param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00990441;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(in_ECX + 0x14) == 0) {
    ExceptionList = &local_c;
    FUN_0071d8d0();
  }
  iVar3 = *(int *)(in_ECX + 8);
  iVar2 = *(int *)(in_ECX + 0xc);
  local_4 = 0;
  while( true ) {
    if (iVar3 == iVar2) {
      ExceptionList = local_c;
      return 0;
    }
    cVar1 = *(char *)(iVar3 + 8);
    FUN_00401660(iVar3 + 0x10,0,0xffffffff);
    if (cVar1 == param_1) break;
    iVar3 = iVar3 + 0x2c;
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_0071dd00 @ 0x0071dd00 ====

/* WARNING: Removing unreachable block (ram,0x0071ddad) */

int FUN_0071dd00(char param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00990453;
  local_c = ExceptionList;
  iVar3 = 0;
  ExceptionList = &local_c;
  if (*(int *)(in_ECX + 0x14) == 0) {
    ExceptionList = &local_c;
    FUN_0071d8d0();
  }
  iVar4 = *(int *)(in_ECX + 8);
  iVar2 = *(int *)(in_ECX + 0xc);
  local_4 = 0;
  for (; iVar4 != iVar2; iVar4 = iVar4 + 0x2c) {
    cVar1 = *(char *)(iVar4 + 8);
    FUN_00401660(iVar4 + 0x10,0,0xffffffff);
    if (cVar1 == param_1) {
      iVar3 = iVar3 + 1;
    }
  }
  ExceptionList = local_c;
  return iVar3;
}


// ==== FUN_0071ddd0 @ 0x0071ddd0 ====

int FUN_0071ddd0(uint param_1)

{
  int iVar1;
  int in_ECX;
  uint extraout_EDX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x2c)) goto LAB_0071ddfe;
  }
  FUN_0071e010();
  param_1 = extraout_EDX;
LAB_0071ddfe:
  return iVar1 + param_1 * 0x2c;
}


// ==== FUN_0071de10 @ 0x0071de10 ====

void FUN_0071de10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ecde4;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b0d8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b0d8 = in_ECX;
  return;
}


// ==== FUN_0071de70 @ 0x0071de70 ====

void FUN_0071de70(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_ECX;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvStack_c = ExceptionList;
  puStack_8 = &LAB_00990482;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ecde4;
  piVar3 = (int *)in_ECX[2];
  piVar1 = (int *)in_ECX[3];
  local_4 = 1;
  for (; piVar3 != piVar1; piVar3 = piVar3 + 0xb) {
    if (*piVar3 != 0) {
      (**(code **)(*DAT_00b5a730 + 0x10))(1,*piVar3);
    }
  }
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  DAT_00b5b0d8 = 0;
  iVar5 = in_ECX[2];
  if (iVar5 == 0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009ecdc0;
    ExceptionList = pvStack_c;
    return;
  }
  iVar2 = in_ECX[3];
  if (iVar5 != iVar2) {
    puVar4 = (uint *)(iVar5 + 0x28);
    do {
      if (0xf < *puVar4) {
        _free((void *)puVar4[-5]);
        return;
      }
      *puVar4 = 0xf;
      puVar4[-1] = 0;
      *(undefined1 *)(puVar4 + -5) = 0;
      iVar5 = iVar5 + 0x2c;
      puVar4 = puVar4 + 0xb;
    } while (iVar5 != iVar2);
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0071df60 @ 0x0071df60 ====

void FUN_0071df60(undefined1 param_1)

{
  void *in_stack_00000018;
  uint in_stack_0000002c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990494;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_0071e7e0(&param_1);
  if (in_stack_0000002c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000018);
  return;
}


// ==== FUN_0071dfb0 @ 0x0071dfb0 ====

void FUN_0071dfb0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  *(undefined1 *)(in_ECX + 2) = *(undefined1 *)(param_1 + 2);
  *(undefined1 *)((int)in_ECX + 9) = *(undefined1 *)((int)param_1 + 9);
  *(undefined1 *)((int)in_ECX + 10) = *(undefined1 *)((int)param_1 + 10);
  *(undefined1 *)((int)in_ECX + 0xb) = *(undefined1 *)((int)param_1 + 0xb);
  *(undefined1 *)(in_ECX + 3) = *(undefined1 *)(param_1 + 3);
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  FUN_00401660(param_1 + 4,0,0xffffffff);
  return;
}


// ==== FUN_0071e010 @ 0x0071e010 ====

void FUN_0071e010(void)

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
  puStack_8 = &LAB_009904a8;
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


// ==== FUN_0071e080 @ 0x0071e080 ====

void FUN_0071e080(void)

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
  puStack_8 = &LAB_009904a8;
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


// ==== FUN_0071e0f0 @ 0x0071e0f0 ====

void FUN_0071e0f0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_3 + 2);
      *(undefined1 *)((int)param_1 + 9) = *(undefined1 *)((int)param_3 + 9);
      *(undefined1 *)((int)param_1 + 10) = *(undefined1 *)((int)param_3 + 10);
      *(undefined1 *)((int)param_1 + 0xb) = *(undefined1 *)((int)param_3 + 0xb);
      *(undefined1 *)(param_1 + 3) = *(undefined1 *)(param_3 + 3);
      FUN_00401660(param_3 + 4,0,0xffffffff);
      param_1 = param_1 + 0xb;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0071e150 @ 0x0071e150 ====

undefined4 * FUN_0071e150(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x2c;
    puVar2 = param_3 + -0xb;
    *puVar2 = *(undefined4 *)(param_2 + -0x2c);
    param_3[-10] = *(undefined4 *)(param_2 + -0x28);
    *(undefined1 *)(param_3 + -9) = *(undefined1 *)(param_2 + -0x24);
    *(undefined1 *)((int)param_3 + -0x23) = *(undefined1 *)(param_2 + -0x23);
    *(undefined1 *)((int)param_3 + -0x22) = *(undefined1 *)(param_2 + -0x22);
    *(undefined1 *)((int)param_3 + -0x21) = *(undefined1 *)(param_2 + -0x21);
    *(undefined1 *)(param_3 + -8) = *(undefined1 *)(param_2 + -0x20);
    FUN_00401660(param_2 + -0x1c,0,0xffffffff);
    param_2 = iVar1;
    param_3 = puVar2;
  } while (iVar1 != param_1);
  return puVar2;
}


// ==== FUN_0071e1c0 @ 0x0071e1c0 ====

undefined4 * FUN_0071e1c0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009904d1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0xb) {
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      *(undefined1 *)(param_3 + 2) = *(undefined1 *)(param_1 + 2);
      *(undefined1 *)((int)param_3 + 9) = *(undefined1 *)((int)param_1 + 9);
      *(undefined1 *)((int)param_3 + 10) = *(undefined1 *)((int)param_1 + 10);
      *(undefined1 *)((int)param_3 + 0xb) = *(undefined1 *)((int)param_1 + 0xb);
      *(undefined1 *)(param_3 + 3) = *(undefined1 *)(param_1 + 3);
      param_3[10] = 0xf;
      param_3[9] = 0;
      *(undefined1 *)(param_3 + 5) = 0;
      FUN_00401660(param_1 + 4,0,0xffffffff);
    }
    param_3 = param_3 + 0xb;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0071e25a @ 0x0071e25a ====

void Catch_0071e25a(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 0x10)) {
    puVar1 = (uint *)(iVar2 + 0x28);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x2c;
      puVar1 = puVar1 + 0xb;
    } while (iVar2 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0071e2b0 @ 0x0071e2b0 ====

void FUN_0071e2b0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009904f1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_3 + 2);
      *(undefined1 *)((int)param_1 + 9) = *(undefined1 *)((int)param_3 + 9);
      *(undefined1 *)((int)param_1 + 10) = *(undefined1 *)((int)param_3 + 10);
      *(undefined1 *)((int)param_1 + 0xb) = *(undefined1 *)((int)param_3 + 0xb);
      *(undefined1 *)(param_1 + 3) = *(undefined1 *)(param_3 + 3);
      param_1[10] = 0xf;
      param_1[9] = 0;
      *(undefined1 *)(param_1 + 5) = 0;
      FUN_00401660(param_3 + 4,0,0xffffffff);
    }
    param_1 = param_1 + 0xb;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0071e34b @ 0x0071e34b ====

void Catch_0071e34b(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 8)) {
    puVar1 = (uint *)(iVar2 + 0x28);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x2c;
      puVar1 = puVar1 + 0xb;
    } while (iVar2 != *(int *)(unaff_EBP + 8));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0071e3a0 @ 0x0071e3a0 ====

void FUN_0071e3a0(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x2c) {
    FUN_00792590();
  }
  return;
}


// ==== FUN_0071e3d0 @ 0x0071e3d0 ====

void FUN_0071e3d0(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x2c) {
    FUN_00792590();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0071e420 @ 0x0071e420 ====

int FUN_0071e420(int param_1,int param_2,undefined4 param_3)

{
  FUN_0071e2b0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x2c;
}


// ==== FUN_0071e450 @ 0x0071e450 ====

void FUN_0071e450(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined1 local_44 [2];
  undefined1 auStack_42 [18];
  void *local_30;
  uint local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00990508;
  local_10 = ExceptionList;
  local_14 = local_44 + -0xc;
  ExceptionList = &local_10;
  FUN_0071dfb0(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x2c;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x2c;
    }
    if (0x5d1745dU - iVar1 < param_2) {
      FUN_0071e080();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x2c;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x5d1745d - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x2c;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_0066e800();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x2c);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = FUN_0071e1c0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0071e2b0(iVar2,param_2,local_44);
      FUN_0071e1c0(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x2c);
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x2c;
      }
      if (iVar2 != 0) {
        FUN_0071e3a0(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x2c + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar1) * 0x2c);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      iVar1 = param_2 * 0x2c;
      if ((uint)((iVar2 - param_1) / 0x2c) < param_2) {
        FUN_0071e1c0(param_1,iVar2,iVar1 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0071e420(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x2c,local_44
                    );
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
        local_8 = 0;
        FUN_0071e0f0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x2c,local_44);
      }
      else {
        iVar6 = iVar2 + param_2 * -0x2c;
        uVar4 = FUN_0071e1c0(iVar6,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_0071e150(param_1,iVar6,iVar2,param_1);
        FUN_0071e0f0(param_1,iVar1 + param_1,local_44);
      }
    }
  }
  if (local_1c < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_30);
  return;
}


// ==== Catch@0071e61a @ 0x0071e61a ====

void Catch_0071e61a(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_0071e3a0(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0071e6d4 @ 0x0071e6d4 ====

void Catch_0071e6d4(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x2c;
  FUN_0071e3a0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0071e770 @ 0x0071e770 ====

void FUN_0071e770(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x2c != 0) {
      iVar1 = (param_2 - iVar1) / 0x2c;
      goto LAB_0071e7b5;
    }
  }
  iVar1 = 0;
LAB_0071e7b5:
  FUN_0071e450(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x2c;
  return;
}


// ==== FUN_0071e7e0 @ 0x0071e7e0 ====

void FUN_0071e7e0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x2c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x2c))) {
    FUN_0071e770(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0071e2b0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x2c;
  return;
}


// ==== FUN_0071e870 @ 0x0071e870 ====

void FUN_0071e870(byte param_1)

{
  void *in_ECX;
  
  FUN_0071de70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071e890 @ 0x0071e890 ====

void FUN_0071e890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ece50;
  return;
}


// ==== FUN_0071e8a0 @ 0x0071e8a0 ====

void FUN_0071e8a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ece50;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071e8c0 @ 0x0071e8c0 ====

void FUN_0071e8c0(void)

{
  int *_Dst;
  undefined4 *puVar1;
  int in_ECX;
  
  _Dst = *(int **)(in_ECX + 0xc);
  if (_Dst == *(int **)(in_ECX + 0x10)) {
    *(int **)(in_ECX + 4) = *(int **)(in_ECX + 0x10);
    return;
  }
  do {
    do {
      puVar1 = (undefined4 *)*_Dst;
      _memmove(_Dst,_Dst + 1,(*(int *)(in_ECX + 0x10) - (int)(_Dst + 1) >> 2) * 4);
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + -4;
    } while (puVar1 == (undefined4 *)0x0);
    (**(code **)*puVar1)(1);
  } while( true );
}


// ==== FUN_0071e910 @ 0x0071e910 ====

/* WARNING: Removing unreachable block (ram,0x0071e979) */

void FUN_0071e910(undefined4 param_1,byte *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  byte *pbVar7;
  undefined4 *_Dst;
  bool bVar8;
  bool bVar9;
  uint in_stack_00000018;
  uint in_stack_0000001c;
  undefined1 local_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  pvStack_c = ExceptionList;
  puStack_8 = &LAB_00990530;
  ExceptionList = &pvStack_c;
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  _Dst = *(undefined4 **)(in_ECX + 0xc);
  uStack_3 = 0;
  *(undefined4 **)(in_ECX + 4) = puVar1;
  do {
    if (_Dst == puVar1) {
      local_4 = 0;
joined_r0x0071ea12:
      if (in_stack_0000001c < 0x10) {
        ExceptionList = pvStack_c;
        return;
      }
      _free(param_2);
      return;
    }
    local_4 = 0;
    piVar2 = (int *)*_Dst;
    iVar3 = (**(code **)(*piVar2 + 0x14))(local_28);
    pbVar7 = param_2;
    if (in_stack_0000001c < 0x10) {
      pbVar7 = (byte *)&param_2;
    }
    uVar5 = *(uint *)(iVar3 + 0x14);
    if (uVar5 == 0) {
LAB_0071e9b3:
      if (uVar5 < in_stack_00000018) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = (uint)(uVar5 != in_stack_00000018);
      }
      bVar8 = uVar5 == 0;
    }
    else {
      uVar6 = in_stack_00000018;
      if (uVar5 < in_stack_00000018) {
        uVar6 = uVar5;
      }
      if (*(uint *)(iVar3 + 0x18) < 0x10) {
        pbVar4 = (byte *)(iVar3 + 4);
      }
      else {
        pbVar4 = *(byte **)(iVar3 + 4);
      }
      bVar8 = false;
      iVar3 = 0;
      bVar9 = true;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar8 = *pbVar4 < *pbVar7;
        bVar9 = *pbVar4 == *pbVar7;
        pbVar4 = pbVar4 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (!bVar9) {
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      }
      bVar8 = false;
      if (iVar3 == 0) goto LAB_0071e9b3;
    }
    local_4 = 0;
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    if (bVar8) {
      _memmove(_Dst,_Dst + 1,(*(int *)(in_ECX + 0x10) - (int)(_Dst + 1) >> 2) * 4);
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + -4;
      (**(code **)*piVar2)(1);
      goto joined_r0x0071ea12;
    }
    _Dst = _Dst + 1;
  } while( true );
}


// ==== FUN_0071ea70 @ 0x0071ea70 ====

/* WARNING: Removing unreachable block (ram,0x0071eadd) */

int * FUN_0071ea70(undefined4 param_1,byte *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int *extraout_EAX;
  int *extraout_EAX_00;
  int *extraout_EAX_01;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  uint in_stack_00000018;
  uint in_stack_0000001c;
  undefined1 local_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  pvStack_c = ExceptionList;
  puStack_8 = &LAB_0099054a;
  ExceptionList = &pvStack_c;
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  puVar7 = *(undefined4 **)(in_ECX + 0xc);
  uStack_3 = 0;
  *(undefined4 **)(in_ECX + 4) = puVar1;
  do {
    if (puVar7 == puVar1) {
      local_4 = 0;
      if (in_stack_0000001c < 0x10) {
        ExceptionList = pvStack_c;
        return (int *)0x0;
      }
      _free(param_2);
      return extraout_EAX_00;
    }
    local_4 = 0;
    piVar2 = (int *)*puVar7;
    iVar3 = (**(code **)(*piVar2 + 0x14))(local_28);
    pbVar8 = param_2;
    if (in_stack_0000001c < 0x10) {
      pbVar8 = (byte *)&param_2;
    }
    uVar5 = *(uint *)(iVar3 + 0x14);
    if (uVar5 == 0) {
LAB_0071eb0f:
      if (uVar5 < in_stack_00000018) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = (uint)(uVar5 != in_stack_00000018);
      }
      bVar9 = uVar5 == 0;
    }
    else {
      uVar6 = uVar5;
      if (in_stack_00000018 <= uVar5) {
        uVar6 = in_stack_00000018;
      }
      if (*(uint *)(iVar3 + 0x18) < 0x10) {
        pbVar4 = (byte *)(iVar3 + 4);
      }
      else {
        pbVar4 = *(byte **)(iVar3 + 4);
      }
      bVar9 = false;
      iVar3 = 0;
      bVar10 = true;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar9 = *pbVar4 < *pbVar8;
        bVar10 = *pbVar4 == *pbVar8;
        pbVar4 = pbVar4 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar10);
      if (!bVar10) {
        iVar3 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      }
      bVar9 = false;
      if (iVar3 == 0) goto LAB_0071eb0f;
    }
    local_4 = 0;
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return extraout_EAX;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    if (bVar9) {
      if (in_stack_0000001c < 0x10) {
        ExceptionList = pvStack_c;
        return piVar2;
      }
      _free(param_2);
      return extraout_EAX_01;
    }
    puVar7 = puVar7 + 1;
  } while( true );
}


// ==== FUN_0071ebc0 @ 0x0071ebc0 ====

undefined4 FUN_0071ebc0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  int in_ECX;
  undefined4 *puVar5;
  undefined1 auStack_42 [2];
  void *pvStack_40;
  undefined1 auStack_38 [8];
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined1 uStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990564;
  local_c = ExceptionList;
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  puVar5 = *(undefined4 **)(in_ECX + 0xc);
  if (puVar5 != puVar1) {
    ExceptionList = &local_c;
    do {
      piVar2 = (int *)*puVar5;
      iVar4 = (**(code **)(*piVar2 + 0x10))();
      if (iVar4 == param_1) {
        (**(code **)(*DAT_00b5ac50 + 4))(auStack_28,param_2);
        local_c = (void *)0x0;
        (**(code **)(*DAT_00b5ac50 + 8))(auStack_42 + -10,param_2);
        uStack_14 = 1;
        cVar3 = (**(code **)(*piVar2 + 0x18))(auStack_38,uStack_4,auStack_42 + -0x12,param_1);
        if (cVar3 == '\x01') {
          if (0xf < uStack_2c) {
            _free(pvStack_40);
            return extraout_EAX;
          }
          uStack_2c = 0xf;
          uStack_30 = 0;
          if (uStack_10 < 0x10) {
            ExceptionList = local_c;
            return 1;
          }
          _free(pvStack_24);
          return extraout_EAX_00;
        }
        if (0xf < uStack_2c) {
          _free(pvStack_40);
          return extraout_EAX_01;
        }
        uStack_2c = 0xf;
        uStack_30 = 0;
        if (uStack_10 < 0x10) {
          ExceptionList = local_c;
          return 0;
        }
        _free(pvStack_24);
        return extraout_EAX_02;
      }
      puVar5 = puVar5 + 1;
    } while (puVar5 != puVar1);
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_0071ed00 @ 0x0071ed00 ====

undefined4 FUN_0071ed00(undefined4 param_1)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  undefined4 extraout_EAX_07;
  undefined4 extraout_EAX_08;
  undefined4 extraout_EAX_09;
  undefined4 extraout_EAX_10;
  int in_ECX;
  undefined4 *puVar3;
  undefined1 local_b8 [4];
  void *local_b4;
  undefined4 local_a4;
  uint local_a0;
  undefined1 local_9c [4];
  void *local_98;
  undefined4 local_88;
  uint local_84;
  undefined1 local_80 [4];
  void *local_7c;
  undefined4 local_6c;
  uint local_68;
  undefined1 local_64 [4];
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined1 local_48 [4];
  void *local_44;
  undefined4 local_34;
  uint local_30;
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_18;
  uint local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009905a4;
  local_c = ExceptionList;
  if ((*(int *)(in_ECX + 0xc) != 0) &&
     (local_10 = *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc) >> 2, local_10 != 0)) {
    local_14 = 0xf;
    local_18 = 0;
    local_28 = (void *)((uint)local_28 & 0xffffff00);
    local_4c = 0xf;
    local_50 = 0;
    local_60 = (void *)((uint)local_60 & 0xffffff00);
    local_30 = 0xf;
    local_34 = 0;
    local_44 = (void *)((uint)local_44 & 0xffffff00);
    local_a0 = 0xf;
    local_a4 = 0;
    local_b4 = (void *)((uint)local_b4 & 0xffffff00);
    local_68 = 0xf;
    local_6c = 0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    local_84 = 0xf;
    local_88 = 0;
    local_98 = (void *)((uint)local_98 & 0xffffff00);
    local_4 = 5;
    ExceptionList = &local_c;
    (**(code **)(*DAT_00b5ac50 + 0xc))
              (param_1,local_2c,local_64,local_48,local_b8,local_80,local_9c);
    puVar1 = *(undefined4 **)(in_ECX + 0x10);
    for (puVar3 = *(undefined4 **)(in_ECX + 0xc); puVar3 != puVar1; puVar3 = puVar3 + 1) {
      cVar2 = (**(code **)(*(int *)*puVar3 + 0x1c))
                        (local_2c,local_64,local_48,local_b8,local_80,local_9c);
      if (cVar2 == '\x01') {
        if (0xf < local_84) {
          _free(local_98);
          return extraout_EAX_05;
        }
        local_84 = 0xf;
        local_88 = 0;
        local_98 = (void *)((uint)local_98 & 0xffffff00);
        if (0xf < local_68) {
          _free(local_7c);
          return extraout_EAX_06;
        }
        local_68 = 0xf;
        local_6c = 0;
        local_7c = (void *)((uint)local_7c & 0xffffff00);
        if (0xf < local_a0) {
          _free(local_b4);
          return extraout_EAX_07;
        }
        local_a0 = 0xf;
        local_a4 = 0;
        local_b4 = (void *)((uint)local_b4 & 0xffffff00);
        if (0xf < local_30) {
          _free(local_44);
          return extraout_EAX_08;
        }
        local_30 = 0xf;
        local_34 = 0;
        local_44 = (void *)((uint)local_44 & 0xffffff00);
        if (0xf < local_4c) {
          _free(local_60);
          return extraout_EAX_09;
        }
        local_4c = 0xf;
        local_50 = 0;
        local_60 = (void *)((uint)local_60 & 0xffffff00);
        if (local_14 < 0x10) {
          ExceptionList = local_c;
          return 1;
        }
        _free(local_28);
        return extraout_EAX_10;
      }
    }
    if (0xf < local_84) {
      _free(local_98);
      return extraout_EAX;
    }
    local_84 = 0xf;
    local_88 = 0;
    local_98 = (void *)((uint)local_98 & 0xffffff00);
    if (0xf < local_68) {
      _free(local_7c);
      return extraout_EAX_00;
    }
    local_68 = 0xf;
    local_6c = 0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    if (0xf < local_a0) {
      _free(local_b4);
      return extraout_EAX_01;
    }
    local_a0 = 0xf;
    local_a4 = 0;
    local_b4 = (void *)((uint)local_b4 & 0xffffff00);
    if (0xf < local_30) {
      _free(local_44);
      return extraout_EAX_02;
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = (void *)((uint)local_44 & 0xffffff00);
    if (0xf < local_4c) {
      _free(local_60);
      return extraout_EAX_03;
    }
    local_4c = 0xf;
    local_50 = 0;
    local_60 = (void *)((uint)local_60 & 0xffffff00);
    if (0xf < local_14) {
      _free(local_28);
      return extraout_EAX_04;
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_0071efe0 @ 0x0071efe0 ====

void FUN_0071efe0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009905c1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ece6c;
  local_4 = 1;
  FUN_0071e8c0();
  DAT_00b5ac4c = 0;
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009ece50;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0071f050 @ 0x0071f050 ====

void FUN_0071f050(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ece6c;
  puVar1 = in_ECX + 1;
  *puVar1 = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  *puVar1 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ac4c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac4c = in_ECX;
  return;
}


// ==== FUN_0071f0c0 @ 0x0071f0c0 ====

/* WARNING: Removing unreachable block (ram,0x0071f142) */

void FUN_0071f0c0(int *param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  int *in_ECX;
  undefined1 auStack_58 [16];
  undefined1 auStack_48 [4];
  uint uStack_44;
  undefined1 auStack_1c [16];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009905e5;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_1 + 0x14))(auStack_58);
  iVar3 = (**(code **)(*in_ECX + 0xc))();
  if (iVar3 != 0) {
    uStack_44 = uStack_44 & 0xffffff00;
    FUN_00401740(s_FindUIWindow__i_pWindow_>GetWind_009ece08,0x32);
    FUN_00406880(auStack_48);
    uStack_44 = uStack_44 & 0xffffff00;
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar3 = in_ECX[3];
  if ((iVar3 == 0) || ((uint)(in_ECX[5] - iVar3 >> 2) <= (uint)(in_ECX[4] - iVar3 >> 2))) {
    FUN_0071f270(in_ECX[4],1,auStack_1c);
    in_ECX[1] = in_ECX[4];
    ExceptionList = auStack_58;
    return;
  }
  puVar1 = (undefined4 *)in_ECX[4];
  *puVar1 = param_1;
  in_ECX[4] = (int)(puVar1 + 1);
  in_ECX[1] = in_ECX[4];
  ExceptionList = auStack_58;
  return;
}


// ==== FUN_0071f1e0 @ 0x0071f1e0 ====

void FUN_0071f1e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0071efe0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071f200 @ 0x0071f200 ====

void FUN_0071f200(void)

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
  puStack_8 = &LAB_009905f8;
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


// ==== FUN_0071f270 @ 0x0071f270 ====

void FUN_0071f270(void *param_1,uint param_2,undefined4 *param_3)

{
  size_t _Size;
  int iVar1;
  uint uVar2;
  void *_Dst;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  
  iVar5 = *(int *)(in_ECX + 4);
  param_3 = (undefined4 *)*param_3;
  if (iVar5 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar5 >> 2;
  }
  uVar7 = CONCAT44(iVar5,iVar1);
  if (param_2 != 0) {
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 2;
    }
    if (0x3fffffffU - iVar5 < param_2) {
      uVar7 = FUN_0071f200();
    }
    iVar5 = (int)((ulonglong)uVar7 >> 0x20);
    uVar2 = (uint)uVar7;
    if (iVar5 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 2;
    }
    if (uVar2 < iVar1 + param_2) {
      if (0x3fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar5 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 2;
      }
      if (uVar2 < iVar1 + param_2) {
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 2;
        }
        uVar2 = iVar5 + param_2;
      }
      _Dst = operator_new(uVar2 * 4);
      _Size = ((int)param_1 - (int)*(void **)(in_ECX + 4) >> 2) * 4;
      pvVar3 = _memmove(_Dst,*(void **)(in_ECX + 4),_Size);
      pvVar3 = (void *)FUN_00845740((void *)((int)pvVar3 + _Size),param_2,&param_3);
      _memmove(pvVar3,param_1,(*(int *)(in_ECX + 8) - (int)param_1 >> 2) * 4);
      pvVar3 = *(void **)(in_ECX + 4);
      if (pvVar3 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - (int)pvVar3 >> 2;
      }
      if (pvVar3 == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)_Dst);
        *(void **)(in_ECX + 8) = (void *)((int)_Dst + (param_2 + iVar5) * 4);
        *(void **)(in_ECX + 4) = _Dst;
        return;
      }
      _free(pvVar3);
      return;
    }
    iVar1 = *(int *)(in_ECX + 8);
    iVar5 = param_2 * 4;
    if ((uint)(iVar1 - (int)param_1 >> 2) < param_2) {
      FUN_005a6d90(param_1,iVar1,(void *)(iVar5 + (int)param_1));
      FUN_00845740(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - (int)param_1 >> 2),
                   &param_3);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar5;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + param_2 * -4,&param_3);
      return;
    }
    iVar6 = iVar1 + param_2 * -4;
    uVar4 = FUN_005a6d90(iVar6,iVar1,iVar1);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00822d20(param_1,iVar6,iVar1);
    FUN_008335f0(param_1,(void *)(iVar5 + (int)param_1),&param_3);
  }
  return;
}


// ==== FUN_0071f450 @ 0x0071f450 ====

void FUN_0071f450(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed04c;
  return;
}


// ==== FUN_0071f460 @ 0x0071f460 ====

void FUN_0071f460(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ed04c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0071f480 @ 0x0071f480 ====

void FUN_0071f480(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_0071f490 @ 0x0071f490 ====

undefined4 FUN_0071f490(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0071f4a0 @ 0x0071f4a0 ====

void FUN_0071f4a0(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0071f4b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_0071f4c0 @ 0x0071f4c0 ====

bool FUN_0071f4c0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  cVar1 = (**(code **)(*piVar2 + 100))();
  return cVar1 != '\0';
}


// ==== FUN_0071f4e0 @ 0x0071f4e0 ====

void FUN_0071f4e0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0071f4e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ac4c + 0x10))();
  return;
}


// ==== FUN_0071f4f0 @ 0x0071f4f0 ====

void FUN_0071f4f0(undefined4 param_1)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x44))(param_1);
  }
  return;
}


// ==== FUN_0071f520 @ 0x0071f520 ====

void FUN_0071f520(undefined4 param_1)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(param_1);
  }
  return;
}


// ==== FUN_0071f550 @ 0x0071f550 ====

void FUN_0071f550(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  undefined1 uStack00000000;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_005582f0(&uStack00000000);
    }
  }
  return;
}


// ==== FUN_0071f590 @ 0x0071f590 ====

void FUN_0071f590(undefined4 param_1)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_0055a260(param_1);
  }
  return;
}


// ==== FUN_0071f5c0 @ 0x0071f5c0 ====

void FUN_0071f5c0(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x34))(param_1);
  puVar2 = operator_new(8);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009b1798;
  }
  uVar3 = (**(code **)(*piVar1 + 4))();
  puVar2[1] = uVar3;
  FUN_00797a20(puVar2);
  return;
}


// ==== FUN_0071f610 @ 0x0071f610 ====

void FUN_0071f610(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_005514b0();
    }
  }
  return;
}


// ==== FUN_0071f640 @ 0x0071f640 ====

void FUN_0071f640(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ac48 = 0;
  *in_ECX = &PTR_FUN_009ed04c;
  return;
}


// ==== FUN_0071f660 @ 0x0071f660 ====

void FUN_0071f660(undefined1 param_1)

{
  int in_ECX;
  void *unaff_EBX;
  uint unaff_retaddr;
  void *pvStack_28;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00990618;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(&param_1,0,0xffffffff);
  (**(code **)(*DAT_00b5ac4c + 8))();
  *(undefined4 *)(in_ECX + 4) = 0;
  if (unaff_retaddr < 0x10) {
    ExceptionList = pvStack_28;
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_0071f6e0 @ 0x0071f6e0 ====

void FUN_0071f6e0(void)

{
  undefined1 auStack_1cc [4];
  undefined1 uStack_1c8;
  undefined4 uStack_1b8;
  char *pcStack_1b4;
  undefined1 *puStack_1b0;
  undefined1 auStack_1ac [4];
  undefined1 uStack_1a8;
  undefined1 *puStack_1a4;
  undefined4 uStack_198;
  char *pcStack_194;
  code *pcStack_190;
  undefined1 auStack_18c [4];
  undefined1 uStack_188;
  undefined1 *puStack_184;
  undefined4 uStack_178;
  char *pcStack_174;
  code *pcStack_170;
  undefined1 auStack_16c [4];
  undefined1 uStack_168;
  undefined1 *puStack_164;
  undefined4 uStack_158;
  char *pcStack_154;
  code *pcStack_150;
  undefined1 auStack_14c [4];
  undefined1 uStack_148;
  undefined1 *puStack_144;
  undefined4 uStack_138;
  char *pcStack_134;
  code *pcStack_130;
  undefined1 auStack_12c [4];
  undefined1 uStack_128;
  undefined1 *puStack_124;
  undefined4 uStack_118;
  char *pcStack_114;
  code *pcStack_110;
  undefined1 auStack_10c [4];
  undefined1 uStack_108;
  undefined1 *puStack_104;
  undefined4 uStack_f8;
  char *pcStack_f4;
  code *pcStack_f0;
  undefined1 auStack_ec [4];
  undefined1 uStack_e8;
  undefined1 *puStack_e4;
  undefined4 uStack_d8;
  char *pcStack_d4;
  code *pcStack_d0;
  undefined1 auStack_cc [4];
  undefined1 uStack_c8;
  undefined1 *puStack_c4;
  undefined4 uStack_b8;
  char *pcStack_b4;
  code *pcStack_b0;
  undefined1 auStack_ac [4];
  undefined1 uStack_a8;
  undefined1 *puStack_a4;
  undefined4 uStack_98;
  char *pcStack_94;
  code *pcStack_90;
  undefined1 auStack_8c [4];
  undefined1 uStack_88;
  undefined1 *puStack_84;
  undefined4 uStack_78;
  char *pcStack_74;
  code *pcStack_70;
  undefined1 auStack_6c [4];
  undefined1 uStack_68;
  undefined1 *puStack_64;
  undefined4 uStack_58;
  char *pcStack_54;
  code *pcStack_50;
  undefined1 auStack_4c [4];
  undefined1 uStack_48;
  undefined1 *puStack_44;
  undefined4 uStack_38;
  char *pcStack_34;
  code *pcStack_30;
  undefined1 local_28;
  undefined1 *puStack_24;
  undefined4 local_18;
  undefined4 local_14;
  code *pcStack_10;
  
  pcStack_10 = FUN_00789010;
  pcStack_30 = (code *)0xe;
  local_14 = 0xf;
  local_18 = 0;
  pcStack_34 = s_WrapInitWindow_009ecec0;
  local_28 = 0;
  uStack_38 = 0x71f70d;
  FUN_00401740();
  pcStack_30 = (code *)0x71f718;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  pcStack_30 = FUN_00788be0;
  puStack_24 = auStack_4c;
  pcStack_50 = (code *)0x14;
  pcStack_34 = (char *)0xf;
  uStack_38 = 0;
  pcStack_54 = s_WrapCompositeVisible_009eced0;
  uStack_48 = 0;
  uStack_58 = 0x71f73b;
  FUN_00401740();
  pcStack_50 = (code *)0x71f746;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  pcStack_50 = FUN_00788c60;
  puStack_44 = auStack_6c;
  pcStack_70 = (code *)0xe;
  pcStack_54 = (char *)0xf;
  uStack_58 = 0;
  pcStack_74 = s_WrapInitButton_009ecee8;
  uStack_68 = 0;
  uStack_78 = 0x71f769;
  FUN_00401740();
  pcStack_70 = (code *)0x71f774;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  pcStack_70 = FUN_00788cd0;
  puStack_64 = auStack_8c;
  pcStack_90 = (code *)0x12;
  pcStack_74 = (char *)0xf;
  uStack_78 = 0;
  pcStack_94 = s_WrapSetButtonTitle_009ecef8;
  uStack_88 = 0;
  uStack_98 = 0x71f797;
  FUN_00401740();
  pcStack_90 = (code *)0x71f7a2;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  pcStack_90 = FUN_00788d80;
  puStack_84 = auStack_ac;
  pcStack_b0 = (code *)0x12;
  pcStack_94 = (char *)0xf;
  uStack_98 = 0;
  pcStack_b4 = s_WrapSetButtonCheck_009ecf0c;
  uStack_a8 = 0;
  uStack_b8 = 0x71f7c5;
  FUN_00401740();
  pcStack_b0 = (code *)0x71f7d0;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  pcStack_b0 = FUN_00788e00;
  puStack_a4 = auStack_cc;
  pcStack_d0 = (code *)0xc;
  pcStack_b4 = (char *)0xf;
  uStack_b8 = 0;
  pcStack_d4 = s_WrapSetLabel_009ecf20;
  uStack_c8 = 0;
  uStack_d8 = 0x71f7f3;
  FUN_00401740();
  pcStack_d0 = (code *)0x71f7fe;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  pcStack_d0 = FUN_00789100;
  puStack_c4 = auStack_ec;
  pcStack_f0 = (code *)0x11;
  pcStack_d4 = (char *)0xf;
  uStack_d8 = 0;
  pcStack_f4 = s_WrapGetEditString_009ecf30;
  uStack_e8 = 0;
  uStack_f8 = 0x71f821;
  FUN_00401740();
  pcStack_f0 = (code *)0x71f82c;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  pcStack_f0 = FUN_00788eb0;
  puStack_e4 = auStack_10c;
  pcStack_110 = (code *)0xd;
  pcStack_f4 = (char *)0xf;
  uStack_f8 = 0;
  pcStack_114 = s_WrapClearEdit_009ecf44;
  uStack_108 = 0;
  uStack_118 = 0x71f84f;
  FUN_00401740();
  pcStack_110 = (code *)0x71f85a;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  pcStack_110 = FUN_00788f20;
  puStack_104 = auStack_12c;
  pcStack_130 = (code *)0xc;
  pcStack_114 = (char *)0xf;
  uStack_118 = 0;
  pcStack_134 = s_WrapSetFocus_009ecf54;
  uStack_128 = 0;
  uStack_138 = 0x71f87d;
  FUN_00401740();
  pcStack_130 = (code *)0x71f888;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  pcStack_130 = FUN_00788f90;
  puStack_124 = auStack_14c;
  pcStack_150 = (code *)0xc;
  pcStack_134 = (char *)0xf;
  uStack_138 = 0;
  pcStack_154 = s_WrapGetFocus_009ecf64;
  uStack_148 = 0;
  uStack_158 = 0x71f8ab;
  FUN_00401740();
  pcStack_150 = (code *)0x71f8b6;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  pcStack_150 = FUN_007891d0;
  puStack_144 = auStack_16c;
  pcStack_170 = (code *)0x13;
  pcStack_154 = (char *)0xf;
  uStack_158 = 0;
  pcStack_174 = s_WrapGetScriptString_009ecf74;
  uStack_168 = 0;
  uStack_178 = 0x71f8d9;
  FUN_00401740();
  pcStack_170 = (code *)0x71f8e4;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  pcStack_170 = FUN_007892a0;
  puStack_164 = auStack_18c;
  pcStack_190 = (code *)0x18;
  pcStack_174 = (char *)0xf;
  uStack_178 = 0;
  pcStack_194 = s_WrapGetServerAddressName_009ecf88;
  uStack_188 = 0;
  uStack_198 = 0x71f907;
  FUN_00401740();
  pcStack_190 = (code *)0x71f912;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  pcStack_190 = FUN_007893c0;
  puStack_184 = auStack_1ac;
  puStack_1b0 = (undefined1 *)0xc;
  pcStack_194 = (char *)0xf;
  uStack_198 = 0;
  pcStack_1b4 = s_WrapTryLogin_009ecfa4;
  uStack_1a8 = 0;
  uStack_1b8 = 0x71f935;
  FUN_00401740();
  puStack_1b0 = (undefined1 *)0x71f940;
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  puStack_1b0 = &LAB_00788bd0;
  puStack_1a4 = auStack_1cc;
  pcStack_1b4 = (char *)0xf;
  uStack_1b8 = 0;
  uStack_1c8 = 0;
  FUN_00401740(s_WrapQuitGame_009ecfb4,0xc);
  (**(code **)(*DAT_00b5ac54 + 0x20))();
  return;
}


// ==== FUN_0071f980 @ 0x0071f980 ====

/* WARNING: Removing unreachable block (ram,0x0071fa6c) */

void FUN_0071f980(void)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int in_ECX;
  undefined1 auStack_e8 [4];
  undefined1 uStack_e4;
  undefined4 uStack_d8;
  char *pcStack_d4;
  undefined4 uStack_d0;
  undefined1 uStack_c8;
  void *pvStack_bc;
  char *pcStack_b8;
  undefined4 uStack_b4;
  int iStack_b0;
  void *pvStack_ac;
  char *pcStack_a8;
  void *pvStack_a4;
  undefined1 auStack_9c [16];
  undefined4 uStack_8c;
  char *pcStack_88;
  int iStack_84;
  undefined1 uStack_7c;
  undefined1 *puStack_70;
  char *pcStack_6c;
  void *pvStack_c;
  char *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = &LAB_00990645;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar2 = operator_new(0x28);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00789630();
  }
  *(undefined4 *)(in_ECX + 8) = uVar3;
  local_4 = 0xffffffff;
  pvVar2 = (void *)(**(code **)(*DAT_00b5ac54 + 4))();
  (**(code **)(**(int **)(in_ECX + 8) + 4))();
  (**(code **)(*DAT_00b5ac4c + 4))();
  (**(code **)(*DAT_00b5ac54 + 0x4c))();
  pcVar6 = pcStack_8;
  if (*(uint *)(pcStack_8 + 0x18) < 0x10) {
    pcStack_6c = pcStack_8 + 4;
  }
  else {
    pcStack_6c = *(char **)(pcStack_8 + 4);
  }
  pcStack_8 = pcStack_8 + 4;
  pcVar4 = pcStack_6c;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  puStack_70 = (undefined1 *)0x71fa46;
  FUN_00401740();
  pcStack_6c = (char *)0x71fa58;
  iVar5 = FUN_0059a1e0();
  if (0xf < *(uint *)(pcVar6 + 0x18)) {
    pcStack_8 = *(char **)pcStack_8;
  }
  pcStack_6c = (char *)0x0;
  uStack_7c = 0;
  pcVar6 = pcStack_8;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iStack_84 = (int)pcVar6 - (int)(pcStack_8 + 1);
  uStack_8c = 0x71fad6;
  pcStack_88 = pcStack_8;
  pcStack_8 = pcStack_8 + 1;
  FUN_00401740();
  iStack_84 = *(undefined4 *)(iVar5 + 0x50);
  if (*(uint *)(iVar5 + 0x54) < 0x10) {
    pcStack_a8 = (char *)(iVar5 + 0x40);
  }
  else {
    pcStack_a8 = *(char **)(iVar5 + 0x40);
  }
  pcStack_8 = pcStack_a8 + 1;
  pcStack_88 = (char *)0xf;
  uStack_8c = 0;
  auStack_9c[0] = 0;
  pcVar6 = pcStack_a8;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  pvStack_a4 = (void *)((int)pcVar6 - (int)pcStack_8);
  pvStack_ac = (void *)0x71fb2c;
  FUN_00401740();
  pcStack_a8 = (char *)0x71fb43;
  pvStack_a4 = pvVar2;
  (**(code **)(*DAT_00b5ac54 + 0x18))();
  pcStack_a8 = (char *)0x0;
  iStack_b0 = 0x71fb50;
  pvStack_ac = pvVar2;
  (**(code **)(*DAT_00b5ac54 + 8))();
  uStack_b4 = 0x71fb5c;
  iStack_b0 = iVar5;
  (**(code **)(*DAT_00b5a7cc + 0x14))();
  uStack_b4 = 0x71fb67;
  iVar5 = (**(code **)(*DAT_00b5a6b0 + 8))();
  uStack_b4 = 5;
  pcStack_b8 = s_KOREA_009ecfc4;
  pcStack_6c = (char *)0x0;
  uStack_7c = 0;
  pvStack_bc = (void *)0x71fb8a;
  FUN_00401740();
  if (iVar5 == 1) {
LAB_0071fba7:
    uStack_b4 = 7;
    pcStack_b8 = s_CHINESE_009ecfcc;
  }
  else {
    if (iVar5 != 2) {
      if (iVar5 != 4) goto LAB_0071fbb7;
      goto LAB_0071fba7;
    }
    uStack_b4 = 8;
    pcStack_b8 = s_JAPANESE_009ecfd4;
  }
  pvStack_bc = (void *)0x71fbb7;
  FUN_00401740();
LAB_0071fbb7:
  uStack_d0 = 10;
  uStack_b4 = 0xf;
  pcStack_b8 = (char *)0x0;
  pcStack_d4 = s_InitWindow_009ecfe0;
  uStack_c8 = 0;
  uStack_d8 = 0x71fbd5;
  FUN_00401740();
  uStack_d0 = 0x71fbe0;
  (**(code **)(*DAT_00b5ac54 + 0x30))();
  puStack_70 = auStack_e8;
  uStack_d0 = 0xf;
  pcStack_d4 = (char *)0x0;
  uStack_e4 = 0;
  FUN_00401660(auStack_9c,0,0xffffffff);
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  (**(code **)(*DAT_00b5ac54 + 8))(pvVar2,1);
  if (pcStack_a8 < 0x10) {
    ExceptionList = pvStack_a4;
    return;
  }
  _free(pvStack_bc);
  return;
}


// ==== FUN_0071fc50 @ 0x0071fc50 ====

/* WARNING: Removing unreachable block (ram,0x0071fcd5) */

undefined4
FUN_0071fc50(undefined4 param_1,char *param_2,undefined4 param_3,uint param_4,undefined4 param_5,
            undefined1 param_6,uint param_7)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  undefined1 auStack_60 [4];
  undefined1 uStack_5c;
  undefined4 uStack_4c;
  int iStack_48;
  char *pcStack_44;
  void *pvStack_20;
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00990667;
  pvStack_c = ExceptionList;
  local_4 = (void *)0x1;
  pcStack_44 = param_2;
  if (param_7 < 0x10) {
    pcStack_44 = (char *)&param_2;
  }
  pcVar2 = pcStack_44;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iStack_48 = 0x71fcb6;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4._0_1_ = 2;
  pcStack_44 = (char *)0x71fcc5;
  iVar3 = FUN_00410500();
  local_4 = (void *)CONCAT31(local_4._1_3_,1);
  pcStack_44 = (char *)(iVar3 + 0x3c);
  iStack_48 = 0x71fcf2;
  uVar4 = (**(code **)(*DAT_00b5a798 + 4))();
  *(undefined4 *)(in_ECX + 4) = uVar4;
  if (iVar3 != 0) {
    uStack_4c = 0x71fd05;
    iStack_48 = iVar3;
    (**(code **)(*DAT_00b5a7cc + 0x14))();
  }
  iStack_48 = 0xf;
  uStack_4c = 0;
  uStack_5c = 0;
  FUN_00401660(&param_6,0,0xffffffff);
  (**(code **)(**(int **)(in_ECX + 8) + 0xc))(*(undefined4 *)(in_ECX + 4));
  if ((void *)0xf < pvStack_c) {
    _free(pvStack_20);
    return extraout_EAX;
  }
  pvStack_c = (void *)0xf;
  if (param_4 < 0x10) {
    ExceptionList = auStack_60;
    return 0;
  }
  _free(local_4);
  return extraout_EAX_00;
}


// ==== FUN_0071fd90 @ 0x0071fd90 ====

/* WARNING: Removing unreachable block (ram,0x0071fe3c) */

void FUN_0071fd90(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined1 auStack_3e [46];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00990679;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x34))(param_1);
  if ((piVar1 != (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(*piVar1 + 0x30))(), piVar1 != (int *)0x0)) {
    puStack_8 = (undefined1 *)0x0;
    uVar2 = FUN_00558120();
    FUN_005523f0(uVar2);
    FUN_00401660(param_1,0,0xffffffff);
    (**(code **)(*piVar1 + 8))(auStack_3e + -6);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0071fe60 @ 0x0071fe60 ====

/* WARNING: Removing unreachable block (ram,0x0071fede) */

void FUN_0071fe60(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  undefined1 auStack_26 [22];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099068b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*in_ECX + 0x14))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x34))(param_1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x30))();
    if (iVar3 == 0) {
      FUN_00401740(s_pControl____NULL_009ecfec,0x10);
      puStack_8 = (undefined1 *)0x0;
      FUN_00406880(auStack_26 + -6);
      puStack_8 = (undefined1 *)0xffffffff;
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_00558730(param_1);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0071ff20 @ 0x0071ff20 ====

int FUN_0071ff20(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int extraout_EAX;
  int in_ECX;
  int unaff_retaddr;
  undefined4 local_2c;
  void *pvStack_28;
  undefined1 local_24;
  int iStack_18;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099069d;
  pvStack_c = ExceptionList;
  local_2c = 0;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_2);
  iVar2 = (**(code **)(*piVar1 + 0x30))();
  if (iVar2 != 0) {
    FUN_00550970(&local_2c);
  }
  if (iStack_18 == 0) {
    FUN_00401740(s_EMPTY_009ed000,5);
  }
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  FUN_00401660(&local_2c,0,0xffffffff);
  if (local_14 < 0x10) {
    ExceptionList = local_10;
    return unaff_retaddr;
  }
  _free(pvStack_28);
  return extraout_EAX;
}


// ==== FUN_0071ffe0 @ 0x0071ffe0 ====

/* WARNING: Removing unreachable block (ram,0x00720071) */

void FUN_0071ffe0(void)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  void *pvStack_58;
  undefined4 uStack_20;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009906af;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401660();
  piVar3 = (int *)(**(code **)(*DAT_00b5ac4c + 0xc))();
  if (piVar3 == (int *)0x0) {
    FUN_00401740();
    FUN_00406880();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar1 = *in_ECX;
  (**(code **)(*piVar3 + 0x10))();
  (**(code **)(iVar1 + 0x10))();
  iVar1 = *DAT_00b5ac54;
  (**(code **)(*piVar3 + 8))();
  (**(code **)(iVar1 + 8))();
  FUN_00401660(uStack_20,0,0xffffffff);
  (**(code **)(*DAT_00b5ac54 + 0x30))();
  iVar1 = *DAT_00b5ac54;
  uVar4 = (**(code **)(*piVar3 + 8))(0);
  (**(code **)(iVar1 + 8))(uVar4);
  (**(code **)(*DAT_00b5ac54 + 0x38))();
  ExceptionList = pvStack_58;
  return;
}


