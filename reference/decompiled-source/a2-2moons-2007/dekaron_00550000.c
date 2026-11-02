// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x550000-0x55ffff

// ==== FUN_00550010 @ 0x00550010 ====

void FUN_00550010(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00981f43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb5d4;
  local_4 = 1;
  if (in_ECX[2] != in_ECX[1]) {
    FUN_0054fdf0(in_ECX[2]);
    in_ECX[2] = in_ECX[1];
  }
  FUN_0054e140();
  local_4 = local_4 & 0xffffff00;
  FUN_0054f480();
  *in_ECX = &PTR_FUN_009bb414;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00550080 @ 0x00550080 ====

void FUN_00550080(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb66c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005500a0 @ 0x005500a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005500a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb674;
  FUN_0055a400();
  FUN_0055a390();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5af7c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5af7c = in_ECX;
  return;
}


// ==== FUN_005500e0 @ 0x005500e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005500e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb674;
  _DAT_00b5af7c = 0;
  FUN_0055a3d0();
  FUN_0055a480();
  *in_ECX = &PTR_FUN_009bb66c;
  return;
}


// ==== FUN_00550110 @ 0x00550110 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00550110(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb674;
  _DAT_00b5af7c = 0;
  FUN_0055a3d0();
  FUN_0055a480();
  *in_ECX = &PTR_FUN_009bb66c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00550150 @ 0x00550150 ====

int FUN_00550150(void)

{
  int in_ECX;
  
  return in_ECX + 0x110;
}


// ==== FUN_00550160 @ 0x00550160 ====

undefined4 FUN_00550160(void)

{
  return 2;
}


// ==== FUN_00550190 @ 0x00550190 ====

uint FUN_00550190(void)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5a994 + 0x10))();
  if (((char)uVar1 != '\x01') &&
     (uVar1 = (**(code **)(*DAT_00b5a994 + 0x10))(0x12), (char)uVar1 != '\x01')) {
    uVar1 = 0;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch((undefined *)0x5501d3) {
    case (undefined *)0x8:
    case (undefined *)0x9:
    case (undefined *)0xd:
    case (undefined *)0x20:
    case (undefined *)0x23:
    case (undefined *)0x24:
    case (undefined *)0x25:
    case (undefined *)0x27:
    case (undefined *)0x30:
    case (undefined *)0x31:
    case (undefined *)0x32:
    case (undefined *)0x33:
    case (undefined *)0x34:
    case (undefined *)0x35:
    case (undefined *)0x36:
    case (undefined *)0x37:
    case (undefined *)0x38:
    case (undefined *)0x39:
    case (undefined *)0x41:
    case (undefined *)0x42:
    case (undefined *)0x43:
    case (undefined *)0x44:
    case (undefined *)0x45:
    case (undefined *)0x46:
    case (undefined *)0x47:
    case (undefined *)0x48:
    case (undefined *)0x49:
    case (undefined *)0x4a:
    case (undefined *)0x4b:
    case (undefined *)0x4c:
    case (undefined *)0x4d:
    case (undefined *)0x4e:
    case (undefined *)0x4f:
    case (undefined *)0x50:
    case (undefined *)0x51:
    case (undefined *)0x52:
    case (undefined *)0x53:
    case (undefined *)0x54:
    case (undefined *)0x55:
    case (undefined *)0x56:
    case (undefined *)0x57:
    case (undefined *)0x58:
    case (undefined *)0x59:
    case (undefined *)0x5a:
    case (undefined *)0x60:
    case (undefined *)0x61:
    case (undefined *)0x62:
    case (undefined *)0x63:
    case (undefined *)0x64:
    case (undefined *)0x65:
    case (undefined *)0x66:
    case (undefined *)0x67:
    case (undefined *)0x68:
    case (undefined *)0x69:
    case (undefined *)0xba:
    case (undefined *)0xbb:
    case (undefined *)0xbc:
    case (undefined *)0xbd:
    case (undefined *)0xbe:
    case (undefined *)0xbf:
    case (undefined *)0xc0:
    case (undefined *)0xdb:
    case (undefined *)0xdc:
    case (undefined *)0xdd:
    case (undefined *)0xde:
                    /* WARNING: This code block may not be properly labeled as switch case */
      return 1;
    }
  }
                    /* WARNING: This code block may not be properly labeled as switch case */
  return uVar1 & 0xffffff00;
}


// ==== FUN_00550300 @ 0x00550300 ====

void FUN_00550300(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0xcc);
    local_8 = *(undefined4 *)(in_ECX + 0xd0);
    local_4 = *(undefined4 *)(in_ECX + 0xd4);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_005503d0 @ 0x005503d0 ====

uint FUN_005503d0(int param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int *in_ECX;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  pcVar3 = (char *)0x0;
  if (piVar2 != (int *)0x0) {
    pcVar3 = (char *)(**(code **)(*piVar2 + 0x14))();
    if (*pcVar3 != '\0') {
      piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
      pcVar3 = (char *)0x0;
      if (piVar2 != (int *)0x0) {
        pcVar3 = (char *)(**(code **)(*piVar2 + 100))();
        if ((char)pcVar3 != '\0') {
          iVar1 = *(int *)(param_1 + 4);
          if (iVar1 == 0x25) {
            *(undefined1 *)((int)in_ECX + 0x13d) = 0;
            return 1;
          }
          if (iVar1 == 0x27) {
            *(undefined1 *)((int)in_ECX + 0x13e) = 0;
            return 1;
          }
          pcVar3 = (char *)(iVar1 + -0x2e);
          if (pcVar3 == (char *)0x0) {
            *(undefined1 *)(in_ECX + 0x4f) = 0;
            return 1;
          }
        }
      }
    }
  }
  return (uint)pcVar3 & 0xffffff00;
}


// ==== FUN_00550450 @ 0x00550450 ====

bool FUN_00550450(uint param_1,int param_2)

{
  char cVar1;
  
  if (*(uint *)(param_2 + 0x14) <= param_1) {
    return false;
  }
  if (*(uint *)(param_2 + 0x18) < 0x10) {
    param_2 = param_2 + 4;
  }
  else {
    param_2 = *(int *)(param_2 + 4);
  }
  cVar1 = FUN_00403d70((int)*(char *)(param_2 + param_1));
  return cVar1 == '\x01';
}


// ==== FUN_00550490 @ 0x00550490 ====

uint FUN_00550490(uint param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  
  uVar3 = *(uint *)(param_2 + 0x14);
  if (uVar3 <= param_1) {
    return uVar3 & 0xffffff00;
  }
  uVar6 = 0;
  uVar4 = 0;
  if (uVar3 != 0) {
    do {
      sVar5 = 1;
      if ((uVar6 & 0xffff) < uVar3) {
        if (*(uint *)(param_2 + 0x18) < 0x10) {
          iVar2 = param_2 + 4;
        }
        else {
          iVar2 = *(int *)(param_2 + 4);
        }
        cVar1 = FUN_00403d70((int)*(char *)(iVar2 + (uVar6 & 0xffff)));
        if (cVar1 == '\x01') {
          uVar6 = uVar6 + 1;
          sVar5 = 2;
        }
      }
      uVar3 = uVar6 & 0xffff;
      if (param_1 <= uVar3) break;
      uVar3 = *(uint *)(param_2 + 0x14);
      uVar6 = uVar6 + 1;
    } while ((uVar6 & 0xffff) < uVar3);
    uVar4 = uVar3;
    if (sVar5 == 2) {
      return CONCAT31((int3)(uVar3 >> 8),1);
    }
  }
  return uVar4 & 0xffffff00;
}


// ==== FUN_00550510 @ 0x00550510 ====

void FUN_00550510(void)

{
  char cVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 300) != 0) {
    cVar1 = FUN_00550490(*(int *)(in_ECX + 300) + -1,in_ECX + 0xd8);
    if (cVar1 == '\x01') {
      *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + -2;
      return;
    }
    *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + -1;
  }
  return;
}


// ==== FUN_00550550 @ 0x00550550 ====

void FUN_00550550(void)

{
  uint uVar1;
  char cVar2;
  int in_ECX;
  int iVar3;
  
  uVar1 = *(uint *)(in_ECX + 300);
  if (uVar1 < *(uint *)(in_ECX + 0xec)) {
    if (uVar1 < *(uint *)(in_ECX + 0xec)) {
      if (*(uint *)(in_ECX + 0xf0) < 0x10) {
        iVar3 = in_ECX + 0xdc;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0xdc);
      }
      cVar2 = FUN_00403d70((int)*(char *)(iVar3 + uVar1));
      if (cVar2 == '\x01') {
        *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + 2;
        return;
      }
    }
    *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + 1;
  }
  return;
}


// ==== FUN_005505b0 @ 0x005505b0 ====

void FUN_005505b0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined1 local_4 [4];
  
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bb784;
  in_ECX[0x23] = 0xf;
  in_ECX[0x22] = 0;
  *(undefined1 *)(in_ECX + 0x1e) = 0;
  in_ECX[0x1c] = 0xff000000;
  *(undefined2 *)(in_ECX + 0x24) = 0xfa;
  *(undefined1 *)((int)in_ECX + 0x96) = 0;
  *(undefined1 *)((int)in_ECX + 0x95) = 0;
  *(undefined1 *)((int)in_ECX + 0x92) = 3;
  *(undefined1 *)((int)in_ECX + 0x93) = 0;
  *(undefined1 *)(in_ECX + 0x25) = 0;
  *(undefined1 *)((int)in_ECX + 0x97) = 1;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x2e] = 0xf;
  in_ECX[0x2d] = 0;
  *(undefined1 *)(in_ECX + 0x29) = 0;
  in_ECX[0x2f] = 1;
  in_ECX[0x31] = 1;
  in_ECX[0x30] = 0;
  *(undefined1 *)(in_ECX + 0x32) = 0;
  *(undefined1 *)((int)in_ECX + 0xc9) = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x3c] = 0xf;
  in_ECX[0x3b] = 0;
  *(undefined1 *)(in_ECX + 0x37) = 0;
  in_ECX[0x43] = 0xf;
  in_ECX[0x42] = 0;
  *(undefined1 *)(in_ECX + 0x3e) = 0;
  in_ECX[0x4a] = 0xf;
  in_ECX[0x49] = 0;
  *(undefined1 *)(in_ECX + 0x45) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)(in_ECX + 0x54) = 0;
  if ((uint)in_ECX[0x2e] < 0x10) {
    puVar2 = in_ECX + 0x29;
  }
  else {
    puVar2 = (undefined4 *)in_ECX[0x29];
  }
  if ((uint)in_ECX[0x2e] < 0x10) {
    puVar1 = in_ECX + 0x29;
  }
  else {
    puVar1 = (undefined4 *)in_ECX[0x29];
  }
  FUN_004bdb30(local_4,puVar1,in_ECX[0x2d] + (int)puVar2);
  in_ECX[0x4b] = 0;
  in_ECX[0x4c] = 0;
  in_ECX[0x56] = 3;
  *(undefined2 *)(in_ECX + 0x4e) = 0;
  *(undefined2 *)((int)in_ECX + 0x13a) = 0;
  *(undefined1 *)(in_ECX + 0x58) = 0;
  if ((uint)in_ECX[0x3c] < 0x10) {
    puVar2 = in_ECX + 0x37;
  }
  else {
    puVar2 = (undefined4 *)in_ECX[0x37];
  }
  if ((uint)in_ECX[0x3c] < 0x10) {
    puVar1 = in_ECX + 0x37;
  }
  else {
    puVar1 = (undefined4 *)in_ECX[0x37];
  }
  FUN_004bdb30(local_4,puVar1,in_ECX[0x3b] + (int)puVar2);
  piVar3 = in_ECX + 0x3e;
  if ((uint)in_ECX[0x43] < 0x10) {
    piVar4 = piVar3;
  }
  else {
    piVar4 = (int *)*piVar3;
  }
  if (0xf < (uint)in_ECX[0x43]) {
    piVar3 = (int *)*piVar3;
  }
  FUN_004bdb30(local_4,piVar3,in_ECX[0x42] + (int)piVar4);
  piVar3 = in_ECX + 0x45;
  if ((uint)in_ECX[0x4a] < 0x10) {
    piVar4 = piVar3;
  }
  else {
    piVar4 = (int *)*piVar3;
  }
  if (0xf < (uint)in_ECX[0x4a]) {
    piVar3 = (int *)*piVar3;
  }
  FUN_004bdb30(local_4,piVar3,in_ECX[0x49] + (int)piVar4);
  in_ECX[0x4d] = 0;
  *(undefined1 *)(in_ECX + 0x4f) = 0;
  *(undefined1 *)((int)in_ECX + 0x13d) = 0;
  *(undefined1 *)((int)in_ECX + 0x13e) = 0;
  in_ECX[0x50] = 0;
  return;
}


// ==== FUN_005507e0 @ 0x005507e0 ====

undefined4 FUN_005507e0(void)

{
  int in_ECX;
  int *piVar1;
  int *piVar2;
  undefined1 local_4 [4];
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  piVar1 = (int *)(in_ECX + 0xdc);
  if (*(uint *)(in_ECX + 0xf0) < 0x10) {
    piVar2 = piVar1;
  }
  else {
    piVar2 = (int *)*piVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0xf0)) {
    piVar1 = (int *)*piVar1;
  }
  FUN_004bdb30(local_4,piVar1,*(int *)(in_ECX + 0xec) + (int)piVar2);
  piVar1 = (int *)(in_ECX + 0xf8);
  if (*(uint *)(in_ECX + 0x10c) < 0x10) {
    piVar2 = piVar1;
  }
  else {
    piVar2 = (int *)*piVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0x10c)) {
    piVar1 = (int *)*piVar1;
  }
  FUN_004bdb30(local_4,piVar1,*(int *)(in_ECX + 0x108) + (int)piVar2);
  *(undefined1 *)(in_ECX + 0x44) = 0;
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_00550880 @ 0x00550880 ====

void FUN_00550880(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb784;
  FUN_005507e0();
  if (0xf < (uint)in_ECX[0x4a]) {
    _free((void *)in_ECX[0x45]);
    return;
  }
  in_ECX[0x4a] = 0xf;
  in_ECX[0x49] = 0;
  *(undefined1 *)(in_ECX + 0x45) = 0;
  if (0xf < (uint)in_ECX[0x43]) {
    _free((void *)in_ECX[0x3e]);
    return;
  }
  in_ECX[0x43] = 0xf;
  in_ECX[0x42] = 0;
  *(undefined1 *)(in_ECX + 0x3e) = 0;
  if (0xf < (uint)in_ECX[0x3c]) {
    _free((void *)in_ECX[0x37]);
    return;
  }
  in_ECX[0x3c] = 0xf;
  in_ECX[0x3b] = 0;
  *(undefined1 *)(in_ECX + 0x37) = 0;
  if (0xf < (uint)in_ECX[0x2e]) {
    _free((void *)in_ECX[0x29]);
    return;
  }
  in_ECX[0x2e] = 0xf;
  in_ECX[0x2d] = 0;
  *(undefined1 *)(in_ECX + 0x29) = 0;
  if ((uint)in_ECX[0x23] < 0x10) {
    in_ECX[0x23] = 0xf;
    in_ECX[0x22] = 0;
    *(undefined1 *)(in_ECX + 0x1e) = 0;
    FUN_00552170();
    return;
  }
  _free((void *)in_ECX[0x1e]);
  return;
}


// ==== FUN_00550970 @ 0x00550970 ====

void FUN_00550970(void)

{
  int in_ECX;
  
  FUN_00401660(in_ECX + 0x110,0,0xffffffff);
  return;
}


// ==== FUN_00550990 @ 0x00550990 ====

undefined4 FUN_00550990(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  void *unaff_EBP;
  int unaff_EDI;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uStack_74;
  undefined4 uStack_70;
  uint uStack_6c;
  uint uStack_68;
  undefined4 local_64;
  void *pvStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint uStack_4c;
  undefined1 auStack_44 [4];
  undefined1 uStack_40;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 auStack_28 [10];
  
  iVar6 = *(int *)(in_ECX + 0x158);
  *(undefined2 *)(in_ECX + 0x138) = *(undefined2 *)(param_1 + 4);
  local_64 = *(undefined4 *)(in_ECX + 0x15c);
  *(undefined2 *)(in_ECX + 0x13a) = *(undefined2 *)(param_1 + 6);
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  puVar5 = auStack_28;
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)(in_ECX + 0x164) = auStack_28[2];
  *(undefined4 *)(in_ECX + 0x168) = auStack_28[3];
  *(int *)(in_ECX + 0x164) = *(int *)(in_ECX + 0x164) + iVar6;
  if ((*(ushort *)(in_ECX + 0x138) < *(ushort *)(in_ECX + 0x13a)) &&
     ((uint)*(ushort *)(in_ECX + 0x13a) <= *(uint *)(in_ECX + 0x108))) {
    uStack_74 = 0;
    uStack_70 = 0;
    uStack_2c = 0xf;
    uStack_30 = 0;
    uStack_40 = 0;
    FUN_00401660(in_ECX + 0x110,*(int *)(in_ECX + 0x130),
                 (*(int *)(in_ECX + 300) - *(int *)(in_ECX + 0x130)) +
                 (uint)*(ushort *)(in_ECX + 0x138));
    uVar7 = *(undefined4 *)(in_ECX + 0xbc);
    (**(code **)(*DAT_00b5a688 + 0x34))(uVar7,auStack_44,&uStack_74,&uStack_70);
    iVar6 = *(int *)(in_ECX + 0x98) + *(int *)(in_ECX + 0x158) + unaff_EDI;
    if (*(int *)(in_ECX + 0x58) - *(int *)(in_ECX + 0x50) <= iVar6) {
      iVar6 = *(int *)(in_ECX + 0x58) - *(int *)(in_ECX + 0x50);
    }
    iVar4 = *(int *)(in_ECX + 0x9c);
    uStack_58 = 0xf;
    uStack_5c = 0;
    uStack_6c = uStack_6c & 0xffffff00;
    FUN_00401660(in_ECX + 0xf4,(uint)*(ushort *)(in_ECX + 0x138),
                 (uint)*(ushort *)(in_ECX + 0x13a) - (uint)*(ushort *)(in_ECX + 0x138));
    (**(code **)(*DAT_00b5a688 + 0x34))
              (*(undefined4 *)(in_ECX + 0xbc),&uStack_70,auStack_44 + -0x40,auStack_44 + -0x3c);
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      uVar3 = *(undefined4 *)(in_ECX + 0xc0);
      uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      puVar1[1] = uVar2;
      *puVar1 = &PTR_FUN_009bb6f8;
      *(undefined1 *)(puVar1 + 2) = 1;
      puVar1[4] = uVar3;
      puVar1[5] = iVar6;
      puVar1[6] = iVar4;
      puVar1[7] = uVar7;
      puVar1[8] = unaff_EDI;
    }
    FUN_00797a20(puVar1);
    *(int *)(in_ECX + 0x164) = *(int *)(in_ECX + 0x164) + iVar6;
    *(int *)(in_ECX + 0x168) = *(int *)(in_ECX + 0x168) + iVar4;
    if (0xf < uStack_68) {
      _free(unaff_EBP);
      return extraout_EAX;
    }
    uStack_68 = 0xf;
    uStack_6c = 0;
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return extraout_EAX_00;
    }
  }
  else {
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      uVar7 = *(undefined4 *)(in_ECX + 0xc0);
      uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      puVar1[1] = uVar3;
      puVar1[6] = 0;
      *puVar1 = &PTR_FUN_009bb6f8;
      *(undefined1 *)(puVar1 + 2) = 0;
      puVar1[4] = uVar7;
      puVar1[5] = iVar6;
      puVar1[7] = 1;
      puVar1[8] = local_64;
    }
    FUN_00797a20(puVar1);
  }
  return 1;
}


// ==== FUN_00550c10 @ 0x00550c10 ====

int FUN_00550c10(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  int extraout_EAX;
  int in_ECX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar6 = param_3;
  *(undefined1 *)(in_ECX + 0x150) = 0;
  if ((*(int *)(param_3 + 0x14) == 0) || (param_2 <= *(int *)(in_ECX + 0x154) - 0xfU)) {
    *(undefined4 *)(in_ECX + 0x130) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_3,0,0xffffffff);
    return param_1;
  }
  uVar5 = *(uint *)(in_ECX + 0x130);
  if ((uVar5 < *(uint *)(in_ECX + 300)) &&
     (*(uint *)(in_ECX + 300) < *(int *)(in_ECX + 0x134) + uVar5)) {
    iVar6 = *(int *)(in_ECX + 0x134);
  }
  else {
    *(undefined1 *)(in_ECX + 0x150) = 1;
    param_2 = 0;
    local_20 = 0;
    (**(code **)(*DAT_00b5a688 + 0x34))(*(undefined4 *)(in_ECX + 0xbc),param_3,&param_2,&local_20);
    if (*(int *)(in_ECX + 0x154) - 0xfU < param_2) {
      uVar4 = *(int *)(in_ECX + 300) + *(int *)(in_ECX + 0x108);
      param_3 = 0;
      param_2 = 0;
      if (*(ushort *)(in_ECX + 0x138) < *(ushort *)(in_ECX + 0x13a)) {
        uVar4 = uVar4 + ((uint)*(ushort *)(in_ECX + 0x138) - *(int *)(in_ECX + 0x108));
      }
      do {
        if (param_3 + uVar4 < *(uint *)(iVar6 + 0x14)) {
          if (*(uint *)(iVar6 + 0x18) < 0x10) {
            iVar3 = iVar6 + 4;
          }
          else {
            iVar3 = *(int *)(iVar6 + 4);
          }
          cVar2 = FUN_00403d70((int)*(char *)(iVar3 + param_3 + uVar4));
          uVar5 = uVar4;
          if (cVar2 != '\x01') goto LAB_00550d43;
          param_3 = param_3 + 2;
        }
        else {
          uVar5 = uVar4 - 1;
          cVar2 = FUN_00550490(uVar5,iVar6);
          if (cVar2 == '\x01') {
            uVar5 = uVar4 - 2;
            param_3 = param_3 + 2;
          }
          else {
LAB_00550d43:
            param_3 = param_3 + 1;
          }
        }
        piVar1 = DAT_00b5a688;
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        FUN_00401660(iVar6,uVar5,param_3);
        (**(code **)(*piVar1 + 0x34))(*(undefined4 *)(in_ECX + 0xbc),auStack_1c,&param_2,&local_20);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return extraout_EAX;
        }
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        uVar4 = uVar5;
      } while (param_2 <= *(int *)(in_ECX + 0x154) - 0xfU);
      *(uint *)(in_ECX + 0x130) = uVar5;
      *(int *)(in_ECX + 0x134) = param_3;
      iVar6 = param_3;
    }
    else {
      *(undefined4 *)(in_ECX + 0x130) = 0;
      iVar6 = *(int *)(iVar6 + 0x14);
      *(int *)(in_ECX + 0x134) = iVar6;
      uVar5 = 0;
    }
  }
  FUN_00405b90(param_1,uVar5,iVar6);
  return param_1;
}


// ==== FUN_00550e20 @ 0x00550e20 ====

void FUN_00550e20(char param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  int *in_ECX;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  void *pvVar16;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  void *pvStack_28;
  int iStack_20;
  undefined1 auStack_1c [4];
  undefined1 uStack_18;
  uint uStack_14;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if (piVar4 == (int *)0x0) {
    return;
  }
  cVar3 = (**(code **)(*piVar4 + 100))();
  if (cVar3 == '\0') {
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      iVar9 = in_ECX[0x30];
      uVar6 = (**(code **)(*(int *)in_ECX[1] + 4))();
      puVar5[1] = uVar6;
      puVar5[4] = iVar9;
      *puVar5 = &PTR_FUN_009bb6e0;
      *(undefined1 *)(puVar5 + 2) = 0;
      puVar5[5] = 0;
      puVar5[6] = 0;
      puVar5[7] = 0;
      puVar5[8] = 0;
    }
    FUN_00797a20(puVar5);
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 != (undefined4 *)0x0) {
      iVar9 = in_ECX[0x30];
      uVar6 = (**(code **)(*(int *)in_ECX[1] + 4))();
      puVar5[1] = uVar6;
      puVar5[4] = iVar9;
      *puVar5 = &PTR_FUN_009bb6f8;
      *(undefined1 *)(puVar5 + 2) = 0;
      puVar5[5] = 0;
      puVar5[6] = 0;
      puVar5[7] = 0;
      puVar5[8] = 0;
      FUN_00797a20(puVar5);
      return;
    }
  }
  else {
    if (*(ushort *)((int)in_ECX + 0x13a) <= *(ushort *)(in_ECX + 0x4e)) {
      iStack_2c = (**(code **)(*DAT_00b5a6a8 + 4))();
      if (iStack_2c == 0) {
        uVar6 = 0;
      }
      else {
        iVar9 = in_ECX[0x30];
        uVar15 = 0;
        uVar14 = 0;
        uVar13 = 0;
        uVar12 = 0;
        uVar11 = 0;
        uVar6 = (**(code **)(*(int *)in_ECX[1] + 4))(0,0,0,0,0,iVar9);
        uVar6 = FUN_005520c0(uVar6,uVar11,uVar12,uVar13,uVar14,uVar15,iVar9);
      }
      FUN_00797a20(uVar6);
    }
    pvVar16 = (void *)in_ECX[0x57];
    iVar9 = in_ECX[0x56];
    pvStack_28 = pvVar16;
    piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uVar10 = 0;
    if ((((piVar4 == (int *)0x0) || (cVar3 = (**(code **)(*piVar4 + 100))(), cVar3 == '\0')) ||
        (piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))(), piVar4 == (int *)0x0)) ||
       (pcVar7 = (char *)(**(code **)(*piVar4 + 0x14))(), *pcVar7 == '\0')) {
      iVar8 = (**(code **)(*DAT_00b5a6a8 + 4))();
      if (iVar8 == 0) {
        FUN_00797a20(0);
        return;
      }
      iVar8 = in_ECX[0x30];
      uVar13 = 2;
      uVar12 = 0;
      uVar11 = 1;
      uVar6 = (**(code **)(*(int *)in_ECX[1] + 4))(1,iVar9,0,2,pvVar16,iVar8);
      uVar6 = FUN_00552070(uVar6,uVar11,iVar9,uVar12,uVar13,pvVar16,iVar8);
      FUN_00797a20(uVar6);
      return;
    }
    uStack_34 = 0;
    uStack_30 = 0;
    if (in_ECX[0x3b] != 0) {
      uVar1 = in_ECX[0x4c];
      uVar2 = in_ECX[0x4b];
      if (uVar1 < uVar2) {
        if (param_1 == '\0') {
          FUN_00405b90(auStack_1c,uVar1,uVar2 - uVar1);
        }
        else {
          uStack_4 = 0xf;
          uStack_8 = 0;
          uStack_18 = 0;
          if (uVar2 != uVar1) {
            do {
              FUN_004021f0(&DAT_009bb6bc);
              uVar10 = uVar10 + 1;
            } while (uVar10 < (uint)(in_ECX[0x4b] - in_ECX[0x4c]));
          }
        }
        (**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x2f],auStack_1c,&uStack_34,&uStack_30);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    iVar9 = in_ECX[0x26] + in_ECX[0x56];
    if (in_ECX[0x16] - in_ECX[0x14] <= iVar9) {
      iVar9 = in_ECX[0x16] - in_ECX[0x14];
    }
    iStack_20 = in_ECX[0x27];
    if (param_1 == '\0') {
      (**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x2f],in_ECX + 0x3d,&uStack_34,&uStack_30);
    }
    else {
      uVar10 = 0;
      uStack_4 = 0xf;
      uStack_8 = 0;
      uStack_18 = 0;
      if (in_ECX[0x42] != 0) {
        do {
          FUN_004020e0(&DAT_009bb6c0,1);
          uVar10 = uVar10 + 1;
        } while (uVar10 < (uint)in_ECX[0x42]);
      }
      (**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x2f],auStack_1c,&uStack_34,&uStack_30);
      if (0xf < uStack_14) {
        _free(pvStack_28);
        return;
      }
    }
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 != (undefined4 *)0x0) {
      iVar8 = in_ECX[0x30];
      uVar6 = (**(code **)(*(int *)in_ECX[1] + 4))();
      puVar5[1] = uVar6;
      *puVar5 = &PTR_FUN_009bb6e0;
      *(undefined1 *)(puVar5 + 2) = 1;
      puVar5[4] = iVar8;
      puVar5[5] = iVar9;
      puVar5[6] = iStack_20;
      puVar5[7] = iStack_2c;
      puVar5[8] = pvStack_28;
      FUN_00797a20(puVar5);
      return;
    }
  }
  FUN_00797a20(0);
  return;
}


// ==== FUN_005511f0 @ 0x005511f0 ====

void FUN_005511f0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  undefined1 uVar5;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if (piVar2 == (int *)0x0) {
    return;
  }
  iVar3 = (**(code **)(*piVar2 + 4))();
  if (iVar3 != param_1) {
    return;
  }
  cVar1 = (**(code **)(*piVar2 + 100))();
  uVar5 = 1;
  if (cVar1 == '\x01') {
    if ((*(char *)((int)in_ECX + 0x97) == '\0') || (*(char *)((int)in_ECX + 0x95) == '\x01')) {
      uVar5 = 0;
    }
    puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = &PTR_FUN_009bb6cc;
      *(undefined1 *)(puVar4 + 1) = uVar5;
      goto LAB_00551264;
    }
  }
  else {
    puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = &PTR_FUN_009bb6cc;
      *(undefined1 *)(puVar4 + 1) = 0;
      goto LAB_00551264;
    }
  }
  puVar4 = (undefined4 *)0x0;
LAB_00551264:
  FUN_00797a20(puVar4);
  FUN_00550e20(0);
  return;
}


// ==== FUN_00551280 @ 0x00551280 ====

void FUN_00551280(void)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int local_28;
  undefined4 local_24;
  undefined1 local_20 [4];
  undefined1 local_1c [28];
  
  FUN_00401660(in_ECX + 0xd8,0,0xffffffff);
  if (*(int *)(in_ECX + 0x108) != 0) {
    FUN_00552210(*(undefined4 *)(in_ECX + 300),in_ECX + 0xf4,0,0xffffffff);
  }
  puVar1 = (uint *)(in_ECX + 0x98);
  *puVar1 = 0;
  if (*(char *)(in_ECX + 0x95) != '\0') {
    piVar4 = (int *)(in_ECX + 0xa4);
    if (*(uint *)(in_ECX + 0xb8) < 0x10) {
      piVar5 = piVar4;
    }
    else {
      piVar5 = (int *)*piVar4;
    }
    if (0xf < *(uint *)(in_ECX + 0xb8)) {
      piVar4 = (int *)*piVar4;
    }
    FUN_004bdb30(local_20,piVar4,*(int *)(in_ECX + 0xb4) + (int)piVar5);
    uVar6 = 0;
    if (*(int *)(in_ECX + 0x124) != 0) {
      do {
        FUN_004020e0(&DAT_009bb6b8,1);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(in_ECX + 0x124));
    }
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(puVar1,1);
    FUN_00550e20(1);
    return;
  }
  FUN_00401660(in_ECX + 0x110,0,0xffffffff);
  if (*(int *)(in_ECX + 0xb4) == 0) {
    local_24 = *(undefined4 *)(in_ECX + 0x15c);
    local_28 = 0;
  }
  else {
    (**(code **)(*DAT_00b5a688 + 0x34))
              (*(undefined4 *)(in_ECX + 0xbc),in_ECX + 0xa0,&local_28,&local_24);
  }
  cVar2 = *(char *)(in_ECX + 0x94);
  if (cVar2 == '\x01') {
    *puVar1 = (uint)(*(int *)(in_ECX + 0x154) - local_28) >> 1;
  }
  else if (cVar2 == '\x02') {
    *puVar1 = *(int *)(in_ECX + 0x154) - local_28;
  }
  else if (cVar2 == '\x03') {
    uVar3 = FUN_00550c10(local_1c,local_28,in_ECX + 0x110);
    FUN_00401660(uVar3,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  *puVar1 = 0;
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(puVar1,1);
  FUN_00550e20(0);
  return;
}


// ==== FUN_00551410 @ 0x00551410 ====

void FUN_00551410(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 300) = *(undefined4 *)(in_ECX + 0xec);
  *(undefined1 *)(in_ECX + 0x150) = 0;
  *(undefined4 *)(in_ECX + 0x130) = 0;
  FUN_00551280();
  return;
}


// ==== FUN_00551450 @ 0x00551450 ====

void FUN_00551450(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0xec);
  if ((ushort)(*(short *)(param_1 + 0x14) + (short)uVar1) <= *(ushort *)(in_ECX + 0x90)) {
    *(undefined1 *)(in_ECX + 0x150) = 0;
    if (uVar1 < *(uint *)(in_ECX + 300)) {
      *(uint *)(in_ECX + 300) = uVar1;
    }
    FUN_00552210(*(undefined4 *)(in_ECX + 300),param_1,0,0xffffffff);
    *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + *(int *)(param_1 + 0x14);
    FUN_00551280();
  }
  return;
}


// ==== FUN_005514b0 @ 0x005514b0 ====

void FUN_005514b0(void)

{
  int in_ECX;
  int *piVar1;
  int *piVar2;
  undefined1 local_4 [4];
  
  piVar1 = (int *)(in_ECX + 0x114);
  if (*(uint *)(in_ECX + 0x128) < 0x10) {
    piVar2 = piVar1;
  }
  else {
    piVar2 = (int *)*piVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0x128)) {
    piVar1 = (int *)*piVar1;
  }
  FUN_004bdb30(local_4,piVar1,*(int *)(in_ECX + 0x124) + (int)piVar2);
  piVar1 = (int *)(in_ECX + 0xf8);
  if (*(uint *)(in_ECX + 0x10c) < 0x10) {
    piVar2 = piVar1;
  }
  else {
    piVar2 = (int *)*piVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0x10c)) {
    piVar1 = (int *)*piVar1;
  }
  FUN_004bdb30(local_4,piVar1,*(int *)(in_ECX + 0x108) + (int)piVar2);
  piVar1 = (int *)(in_ECX + 0xdc);
  if (*(uint *)(in_ECX + 0xf0) < 0x10) {
    piVar2 = piVar1;
  }
  else {
    piVar2 = (int *)*piVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0xf0)) {
    piVar1 = (int *)*piVar1;
  }
  FUN_004bdb30(local_4,piVar1,*(int *)(in_ECX + 0xec) + (int)piVar2);
  *(undefined4 *)(in_ECX + 300) = 0;
  *(undefined1 *)(in_ECX + 0x150) = 0;
  *(undefined4 *)(in_ECX + 0x130) = 0;
  FUN_00551280();
  return;
}


// ==== FUN_00551570 @ 0x00551570 ====

void FUN_00551570(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    FUN_005523f0(param_1);
    FUN_00401660(in_ECX + 0xa0,0,0xffffffff);
    *(undefined4 *)(in_ECX + 300) = 0;
    FUN_00551280();
  }
  return;
}


// ==== FUN_005515c0 @ 0x005515c0 ====

undefined4 FUN_005515c0(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  *(int **)(in_ECX + 0x40) = piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = **(int **)(in_ECX + 0x40);
      uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x44) = 1;
        uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
        FUN_00552120(uVar4);
        FUN_005514b0();
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  return 0;
}


// ==== FUN_00551660 @ 0x00551660 ====

void FUN_00551660(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  void *unaff_EBP;
  int unaff_EDI;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_14;
  int iStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = param_1;
  *(undefined1 *)(in_ECX + 0x54) = 0;
  FUN_00552440(param_1 + 4);
  in_ECX[0x33] = *piVar1;
  in_ECX[0x34] = piVar1[1];
  in_ECX[0x35] = piVar1[2];
  in_ECX[0x2f] = (uint)*(byte *)((int)in_ECX + 0x92);
  in_ECX[0x30] = in_ECX[0x1c];
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(&DAT_009bb6b4,1);
  (**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x2f],local_1c,local_20,&param_1);
  if (uStack_14 < 0x10) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    iVar2 = (**(code **)(*piVar1 + 0x14))();
    in_ECX[0x55] = *(int *)(iVar2 + 0x10) - *(int *)(iVar2 + 8);
    in_ECX[0x56] = -(unaff_EDI / 2);
    in_ECX[0x57] = iStack_c;
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    iVar2 = (**(code **)(*piVar1 + 0x14))();
    in_ECX[0x27] = (((*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc)) - iStack_c) + -1) / 2;
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
    FUN_00401660(in_ECX + 0x1d,0,0xffffffff);
    *(undefined1 *)(in_ECX + 0x54) = 0;
    in_ECX[0x4c] = 0;
    in_ECX[0x4b] = in_ECX[0x3b];
    FUN_00551280();
    return;
  }
  _free(unaff_EBP);
  return;
}


// ==== FUN_005517b0 @ 0x005517b0 ====

bool FUN_005517b0(int param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int *in_ECX;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if ((((piVar2 == (int *)0x0) ||
       (pcVar3 = (char *)(**(code **)(*piVar2 + 0x14))(), *pcVar3 == '\0')) ||
      (piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))(), piVar2 == (int *)0x0)) ||
     (cVar1 = (**(code **)(*piVar2 + 100))(), cVar1 == '\0')) {
    return false;
  }
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0xd:
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))();
    if (*pcVar3 != '\0') {
      piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar2 + 0x80))(4,0);
      return true;
    }
    break;
  case 0x20:
  case 0x2d:
    return true;
  case 0x23:
    in_ECX[0x4b] = in_ECX[0x3b];
    FUN_00551280();
    return true;
  case 0x24:
    in_ECX[0x4b] = 0;
    in_ECX[0x4c] = 0;
    FUN_00551280();
    return true;
  case 0x25:
    *(undefined1 *)((int)in_ECX + 0x13d) = 1;
    return true;
  case 0x27:
    *(undefined1 *)((int)in_ECX + 0x13e) = 1;
    return true;
  case 0x2e:
    *(undefined1 *)(in_ECX + 0x4f) = 1;
    return true;
  }
  cVar1 = FUN_00550190(*(undefined4 *)(param_1 + 4));
  return cVar1 == '\x01';
}


// ==== FUN_00551900 @ 0x00551900 ====

undefined4 FUN_00551900(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if ((iVar2 == iVar1) && (param_1[2] == 1)) {
    FUN_00551280();
    return 1;
  }
  return 0;
}


// ==== FUN_00551940 @ 0x00551940 ====

undefined4 FUN_00551940(int param_1)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(char *)(in_ECX + 0x93) == '\0') {
    uVar1 = *(undefined4 *)(in_ECX + 0xec);
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401660(param_1 + 4,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
    if (((ushort)((short)local_8 + (short)uVar1) <= *(ushort *)(in_ECX + 0x90)) &&
       ((*(char *)(in_ECX + 0x94) == '\x03' || (*(char *)(in_ECX + 0x150) == '\0')))) {
      if (*(uint *)(in_ECX + 0xec) < *(uint *)(in_ECX + 300)) {
        *(uint *)(in_ECX + 300) = *(uint *)(in_ECX + 0xec);
      }
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401660(param_1 + 4,0,0xffffffff);
      FUN_00401660(local_1c,0,0xffffffff);
      if (0xf < local_4) {
        _free(local_18);
        return extraout_EAX_00;
      }
      *(undefined4 *)(in_ECX + 0x134) = 0;
      FUN_00551280();
    }
  }
  return 1;
}


// ==== FUN_00551a40 @ 0x00551a40 ====

undefined4 FUN_00551a40(int param_1)

{
  undefined4 extraout_EAX;
  int in_ECX;
  int *piVar1;
  int *piVar2;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *(undefined2 *)(in_ECX + 0x138) = 0;
  *(undefined2 *)(in_ECX + 0x13a) = 0;
  piVar1 = (int *)(in_ECX + 0xf8);
  if (*(uint *)(in_ECX + 0x10c) < 0x10) {
    piVar2 = piVar1;
  }
  else {
    piVar2 = (int *)*piVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0x10c)) {
    piVar1 = (int *)*piVar1;
  }
  FUN_004bdb30(local_20,piVar1,*(int *)(in_ECX + 0x108) + (int)piVar2);
  if (*(char *)(in_ECX + 0x93) == '\0') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401660(param_1 + 4,0,0xffffffff);
    FUN_00551450(local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_00551ae0 @ 0x00551ae0 ====

void FUN_00551ae0(void)

{
  char cVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((*(uint *)(in_ECX + 0xec) < *(uint *)(in_ECX + 300)) || (*(uint *)(in_ECX + 0xec) == 0)) {
    return;
  }
  cVar1 = FUN_00550450(*(uint *)(in_ECX + 300),in_ECX + 0xd8);
  if (cVar1 == '\x01') {
    uVar2 = *(undefined4 *)(in_ECX + 300);
    uVar3 = 2;
  }
  else {
    uVar2 = *(undefined4 *)(in_ECX + 300);
    uVar3 = 1;
  }
  FUN_00401390(uVar2,uVar3);
  *(undefined4 *)(in_ECX + 0x134) = 0;
  FUN_00551280();
  return;
}


// ==== FUN_00551b40 @ 0x00551b40 ====

void FUN_00551b40(int param_1)

{
  uint uVar1;
  char cVar2;
  int in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  if ((*(char *)(in_ECX + 0x13c) != '\0') && (*(int *)(in_ECX + 0x140) + 0x96U < uVar1)) {
    *(uint *)(in_ECX + 0x140) = uVar1;
    FUN_00551ae0();
  }
  if ((*(char *)(in_ECX + 0x13d) != '\0') && (*(int *)(in_ECX + 0x140) + 0x96U < uVar1)) {
    *(uint *)(in_ECX + 0x140) = uVar1;
    if (*(int *)(in_ECX + 300) != 0) {
      cVar2 = FUN_00550490(*(int *)(in_ECX + 300) + -1,in_ECX + 0xd8);
      if (cVar2 == '\x01') {
        *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + -2;
      }
      else {
        *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + -1;
      }
    }
    FUN_00551280();
  }
  if ((*(char *)(in_ECX + 0x13e) != '\0') && (*(int *)(in_ECX + 0x140) + 0x96U < uVar1)) {
    *(uint *)(in_ECX + 0x140) = uVar1;
    FUN_00550550();
    FUN_00551280();
  }
  return;
}


// ==== FUN_00551c00 @ 0x00551c00 ====

undefined4 FUN_00551c00(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  undefined4 in_stack_ffffffb8;
  undefined4 in_stack_ffffffbc;
  void *in_stack_ffffffc0;
  undefined4 uVar7;
  undefined4 uVar8;
  uint local_24;
  uint local_1c;
  undefined4 local_18;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  void *local_c;
  int local_8;
  
  bVar6 = *(int *)(param_1 + 4) != 0;
  local_18 = *(undefined4 *)(param_1 + 8);
  FUN_00406600(param_1 + 0xc);
  if (bVar6) {
    if (*(char *)(in_ECX + 0x160) == '\x01') {
      puVar1 = operator_new(4);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        *puVar1 = &PTR_FUN_009bb710;
      }
      FUN_00797a20(puVar1);
    }
    uVar4 = 0;
    local_24 = 0;
    while( true ) {
      if (local_c == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (local_8 - (int)local_c) / 0x1c;
      }
      uVar5 = local_24 & 0xffff;
      if (uVar2 <= uVar5) break;
      if ((local_c == (void *)0x0) || ((uint)((local_8 - (int)local_c) / 0x1c) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      in_stack_ffffffc0 = (void *)((int)local_c + uVar5 * 0x1c);
      in_stack_ffffffbc = *(undefined4 *)(in_ECX + 0xbc);
      in_stack_ffffffb8 = 0x551ce9;
      (**(code **)(*DAT_00b5a688 + 0x34))(in_stack_ffffffbc,in_stack_ffffffc0,&local_1c,local_14);
      if (uVar4 < local_1c) {
        uVar4 = local_1c;
      }
      local_24 = local_24 + 1;
    }
    uVar7 = 0x551d0c;
    pvVar3 = operator_new(0x24);
    if (pvVar3 == (void *)0x0) {
      FUN_00797a20(0);
    }
    else {
      uVar8 = local_18;
      FUN_00406600(local_10);
      uVar7 = FUN_005524a0(*(undefined4 *)(in_ECX + 0x164),*(undefined4 *)(in_ECX + 0x168),uVar4,
                           in_stack_ffffffb8,in_stack_ffffffbc,in_stack_ffffffc0,uVar7,uVar8);
      FUN_00797a20(uVar7);
    }
  }
  else {
    puVar1 = operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009bb710;
    }
    FUN_00797a20(puVar1);
  }
  *(bool *)(in_ECX + 0x160) = bVar6;
  if (local_c == (void *)0x0) {
    return 1;
  }
  FUN_00405de0(local_c,local_8,local_10,bVar6);
  _free(local_c);
  return extraout_EAX;
}


// ==== FUN_00551dc0 @ 0x00551dc0 ====

void FUN_00551dc0(void)

{
  char cVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 300) == 0) || (*(int *)(in_ECX + 0xec) == 0)) {
    return;
  }
  cVar1 = FUN_00550490(*(int *)(in_ECX + 300) + -1,in_ECX + 0xd8);
  if (cVar1 == '\x01') {
    *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + -2;
    FUN_00551ae0();
    return;
  }
  *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + -1;
  FUN_00551ae0();
  return;
}


// ==== FUN_00551e10 @ 0x00551e10 ====

undefined1 FUN_00551e10(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  char *pcVar4;
  int *in_ECX;
  undefined1 auStack_1c [4];
  undefined1 uStack_18;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  cVar2 = (**(code **)(*piVar3 + 100))();
  if (cVar2 == '\0') {
    return 0;
  }
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  pcVar4 = (char *)(**(code **)(*piVar3 + 0x14))();
  if (*pcVar4 == '\0') {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 8) {
    FUN_00551dc0();
    return 1;
  }
  if (iVar1 == 0x22) {
    piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
    cVar2 = (**(code **)(*piVar3 + 0x80))(0xc,0);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  cVar2 = FUN_00403d90(iVar1);
  if ((cVar2 == '\0') && (iVar1 != 0x20)) {
    return 0;
  }
  if ((*(char *)((int)in_ECX + 0x93) == '\x01') && (cVar2 = FUN_00403d10(iVar1), cVar2 == '\0')) {
    return 1;
  }
  if (((*(char *)((int)in_ECX + 0x93) == '\x02') && (cVar2 = FUN_00403d30(iVar1), cVar2 == '\0')) &&
     (iVar1 != 0x2e)) {
    return 1;
  }
  if (((*(char *)((int)in_ECX + 0x93) != '\x03') || (cVar2 = FUN_00403d50(iVar1), cVar2 != '\0')) ||
     (iVar1 == 0x2e)) {
    uStack_4 = 0xf;
    uStack_8 = 0;
    uStack_18 = 0;
    FUN_00405ac0(1,iVar1);
    FUN_00551450(auStack_1c);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return 1;
}


// ==== FUN_00551f30 @ 0x00551f30 ====

undefined4 FUN_00551f30(int *param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x40) != 0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0x10))(param_1), cVar1 == '\x01')) {
    return 1;
  }
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 < 0x20006) {
    if (uVar2 == 0x20005) {
      cVar1 = FUN_00551940(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if (uVar2 < 0x20003) {
      if (uVar2 == 0x20002) {
        cVar1 = FUN_005503d0(param_1);
        if (cVar1 != '\0') {
          return 1;
        }
      }
      else if (uVar2 == 0x10001) {
        cVar1 = FUN_00551900(param_1);
        if (cVar1 != '\0') {
          return 1;
        }
      }
      else if ((uVar2 == 0x20001) && (cVar1 = FUN_005517b0(param_1), cVar1 != '\0')) {
        return 1;
      }
    }
    else if ((uVar2 == 0x20003) && (cVar1 = FUN_00551e10(param_1), cVar1 != '\0')) {
      return 1;
    }
  }
  else if (uVar2 < 0x20012) {
    if (uVar2 == 0x20011) {
      cVar1 = FUN_00551c00(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if (uVar2 == 0x20006) {
      cVar1 = FUN_00551a40(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if ((uVar2 == 0x20010) && (cVar1 = FUN_00550990(param_1), cVar1 != '\0')) {
      return 1;
    }
  }
  else if (uVar2 == 0x40001) {
    FUN_00551b40(param_1);
  }
  return 0;
}


// ==== FUN_00552060 @ 0x00552060 ====

undefined4 FUN_00552060(void)

{
  return 0x20007;
}


// ==== FUN_00552070 @ 0x00552070 ====

void FUN_00552070(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *(undefined1 *)(in_ECX + 2) = param_2;
  in_ECX[4] = param_7;
  in_ECX[5] = param_3;
  in_ECX[6] = param_4;
  *in_ECX = &PTR_FUN_009bb6e0;
  in_ECX[7] = param_5;
  in_ECX[8] = param_6;
  return;
}


// ==== FUN_005520b0 @ 0x005520b0 ====

undefined4 FUN_005520b0(void)

{
  return 0x60000010;
}


// ==== FUN_005520c0 @ 0x005520c0 ====

void FUN_005520c0(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *(undefined1 *)(in_ECX + 2) = param_2;
  in_ECX[4] = param_7;
  in_ECX[5] = param_3;
  in_ECX[6] = param_4;
  *in_ECX = &PTR_FUN_009bb6f8;
  in_ECX[7] = param_5;
  in_ECX[8] = param_6;
  return;
}


// ==== FUN_00552100 @ 0x00552100 ====

undefined4 FUN_00552100(void)

{
  return 0x60000011;
}


// ==== FUN_00552110 @ 0x00552110 ====

undefined4 FUN_00552110(void)

{
  return 0x70750002;
}


// ==== FUN_00552120 @ 0x00552120 ====

void FUN_00552120(undefined1 *param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  return;
}


// ==== FUN_00552170 @ 0x00552170 ====

void FUN_00552170(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb724;
  if (0xf < (uint)in_ECX[0xf]) {
    _free((void *)in_ECX[10]);
    return;
  }
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[7] = 0;
    in_ECX[8] = 0xf;
    *(undefined1 *)(in_ECX + 3) = 0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_005521c0 @ 0x005521c0 ====

void FUN_005521c0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x45) = param_1;
  return;
}


// ==== FUN_005521d0 @ 0x005521d0 ====

void FUN_005521d0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x46) = param_1;
  return;
}


// ==== FUN_005521e0 @ 0x005521e0 ====

undefined1 FUN_005521e0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x46);
}


// ==== FUN_005521f0 @ 0x005521f0 ====

void FUN_005521f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00552170();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00552210 @ 0x00552210 ====

void FUN_00552210(uint param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if ((*(uint *)(in_ECX + 0x14) < param_1) || (*(uint *)(param_2 + 0x14) < param_3)) {
    FUN_0079dba3();
  }
  uVar1 = *(int *)(param_2 + 0x14) - param_3;
  if (uVar1 < param_4) {
    param_4 = uVar1;
  }
  if (-*(int *)(in_ECX + 0x14) - 1U <= param_4) {
    FUN_0079dbe3();
  }
  if (param_4 == 0) {
    return;
  }
  uVar1 = *(int *)(in_ECX + 0x14) + param_4;
  if (uVar1 == 0xffffffff) {
    FUN_0079dbe3();
  }
  if (*(uint *)(in_ECX + 0x18) < uVar1) {
    FUN_00401410(uVar1,*(undefined4 *)(in_ECX + 0x14));
  }
  else if (uVar1 == 0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      *(undefined1 *)(in_ECX + 4) = 0;
      return;
    }
    **(undefined1 **)(in_ECX + 4) = 0;
    return;
  }
  if (uVar1 == 0) {
    return;
  }
  piVar5 = (int *)(in_ECX + 4);
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    piVar2 = piVar5;
    piVar3 = piVar5;
  }
  else {
    piVar2 = (int *)*piVar5;
    piVar3 = (int *)*piVar5;
  }
  _memmove((void *)((int)piVar2 + param_4 + param_1),(void *)((int)piVar3 + param_1),
           *(int *)(in_ECX + 0x14) - param_1);
  if (in_ECX == param_2) {
    uVar4 = param_3 + param_4;
    if (param_3 <= param_1) {
      uVar4 = param_3;
    }
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      _memmove((void *)((int)piVar5 + param_1),(void *)((int)piVar5 + uVar4),param_4);
    }
    else {
      _memmove((void *)(*piVar5 + param_1),(void *)(*piVar5 + uVar4),param_4);
    }
  }
  else {
    if (*(uint *)(param_2 + 0x18) < 0x10) {
      param_2 = param_2 + 4;
    }
    else {
      param_2 = *(int *)(param_2 + 4);
    }
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      piVar3 = piVar5;
    }
    else {
      piVar3 = (int *)*piVar5;
    }
    puVar6 = (undefined4 *)(param_3 + param_2);
    puVar7 = (undefined4 *)(param_1 + (int)piVar3);
    for (uVar4 = param_4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    for (param_4 = param_4 & 3; param_4 != 0; param_4 = param_4 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
  }
  *(uint *)(in_ECX + 0x14) = uVar1;
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    piVar5 = (int *)*piVar5;
  }
  *(undefined1 *)(uVar1 + (int)piVar5) = 0;
  return;
}


// ==== FUN_005523a0 @ 0x005523a0 ====

int FUN_005523a0(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 4,0,0xffffffff);
  return param_1;
}


// ==== FUN_005523d0 @ 0x005523d0 ====

void FUN_005523d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00550880();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005523f0 @ 0x005523f0 ====

void FUN_005523f0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  FUN_00401660(param_1 + 2,0,0xffffffff);
  in_ECX[9] = param_1[9];
  in_ECX[10] = param_1[10];
  in_ECX[0xb] = param_1[0xb];
  *(undefined1 *)(in_ECX + 0xc) = *(undefined1 *)(param_1 + 0xc);
  *(undefined1 *)((int)in_ECX + 0x31) = *(undefined1 *)((int)param_1 + 0x31);
  return;
}


// ==== FUN_00552440 @ 0x00552440 ====

void FUN_00552440(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  FUN_00401660(param_1 + 1,0,0xffffffff);
  *(undefined2 *)(in_ECX + 8) = *(undefined2 *)(param_1 + 8);
  *(undefined1 *)((int)in_ECX + 0x22) = *(undefined1 *)((int)param_1 + 0x22);
  *(undefined1 *)((int)in_ECX + 0x23) = *(undefined1 *)((int)param_1 + 0x23);
  *(undefined1 *)(in_ECX + 9) = *(undefined1 *)(param_1 + 9);
  *(undefined1 *)((int)in_ECX + 0x25) = *(undefined1 *)((int)param_1 + 0x25);
  *(undefined1 *)((int)in_ECX + 0x26) = *(undefined1 *)((int)param_1 + 0x26);
  *(undefined1 *)((int)in_ECX + 0x27) = *(undefined1 *)((int)param_1 + 0x27);
  return;
}


// ==== FUN_005524a0 @ 0x005524a0 ====

void FUN_005524a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
                 void *param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  in_ECX[2] = param_2;
  *in_ECX = &PTR_FUN_009bb7e0;
  in_ECX[1] = param_1;
  FUN_00406600(&param_4);
  _Memory = param_5;
  in_ECX[7] = param_8;
  in_ECX[8] = param_3;
  if (param_5 == (void *)0x0) {
    return;
  }
  FUN_00405de0(param_5,param_6,&param_4,param_8);
  _free(_Memory);
  return;
}


// ==== FUN_00552500 @ 0x00552500 ====

undefined4 FUN_00552500(void)

{
  return 0x70750001;
}


// ==== FUN_00552510 @ 0x00552510 ====

void FUN_00552510(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb7e0;
  FUN_00406250();
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00552540 @ 0x00552540 ====

void FUN_00552540(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x40) = 0;
  *(undefined1 *)(in_ECX + 0x41) = 0;
  *(undefined1 *)(in_ECX + 0x43) = 0;
  *(undefined1 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0xc;
  *(undefined4 *)(in_ECX + 0x4c) = 500;
  *(undefined1 *)(in_ECX + 0x42) = 0;
  return;
}


// ==== FUN_00552560 @ 0x00552560 ====

void FUN_00552560(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar2 = (**(code **)(*piVar1 + 0x14))();
  in_ECX[0x41] = ((*(int *)(iVar2 + 0x14) + in_ECX[0x31] * -2) - *(int *)(iVar2 + 0xc)) /
                 in_ECX[0x26];
  return;
}


// ==== FUN_005525c0 @ 0x005525c0 ====

void FUN_005525c0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,*(undefined1 *)(in_ECX + 0xa6));
  }
  return;
}


// ==== FUN_005525e0 @ 0x005525e0 ====

undefined4 FUN_005525e0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x44) = 0;
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_00552610 @ 0x00552610 ====

void FUN_00552610(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x70) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x70) + 0x30))(param_1);
    FUN_0055ab10(param_1);
  }
  return;
}


// ==== FUN_00552630 @ 0x00552630 ====

void FUN_00552630(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0xf4);
    local_8 = *(undefined4 *)(in_ECX + 0xf8);
    local_4 = *(undefined4 *)(in_ECX + 0xfc);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_00552720 @ 0x00552720 ====

int FUN_00552720(uint param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar2 = param_2;
  param_2 = *(uint *)(param_2 + 0x14);
  if (param_1 <= param_2) {
    param_2 = param_1;
  }
  uVar6 = 0;
  iVar5 = 0;
  bVar1 = false;
  if (param_2 != 0) {
    do {
      if (bVar1) {
        bVar1 = false;
        iVar5 = uVar6 + 1;
      }
      else {
        if (*(uint *)(iVar2 + 0x14) <= uVar6) {
          FUN_0079dba3();
        }
        if (*(uint *)(iVar2 + 0x18) < 0x10) {
          iVar4 = iVar2 + 4;
        }
        else {
          iVar4 = *(int *)(iVar2 + 4);
        }
        cVar3 = FUN_00403d70((int)*(char *)(iVar4 + uVar6));
        if (cVar3 == '\0') {
          iVar5 = uVar6 + 1;
        }
        else {
          bVar1 = true;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < param_2);
  }
  return iVar5;
}


// ==== FUN_005527a0 @ 0x005527a0 ====

void FUN_005527a0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    uVar1 = *(undefined4 *)(in_ECX + 0xe8);
    uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
    puVar2[1] = uVar3;
    puVar2[4] = uVar1;
    puVar2[8] = 0;
    *puVar2 = &PTR_FUN_009bb6e0;
    *(undefined1 *)(puVar2 + 2) = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
  }
  (**(code **)(*DAT_00b5ad24 + 4))(puVar2);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  return;
}


// ==== FUN_00552860 @ 0x00552860 ====

void FUN_00552860(int *param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 0x11c);
  for (iVar1 = 0; (iVar2 != *(int *)(in_ECX + 0x120) && (iVar1 != param_2)); iVar1 = iVar1 + 1) {
    iVar2 = iVar2 + 0x1c;
  }
  *param_1 = iVar2;
  return;
}


// ==== FUN_00552890 @ 0x00552890 ====

undefined4 FUN_00552890(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  *(int **)(in_ECX + 0x40) = piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = **(int **)(in_ECX + 0x40);
      uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x44) = 1;
        uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
        FUN_00552120(uVar4);
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  return 0;
}


// ==== FUN_00552960 @ 0x00552960 ====

undefined4 FUN_00552960(undefined4 *param_1,undefined4 param_2,undefined4 param_3,ushort *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = FUN_00403620(*param_4,5,s_<font_009bb86c,5);
  if (iVar1 == 0) {
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    local_4 = 0xf;
    FUN_00401660(param_3,*param_4 + 6,1);
    uVar2 = thunk_FUN_00796fb0(local_1c);
    *param_1 = uVar2;
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  else {
    iVar1 = FUN_00403620((uint)*param_4,7,s_<_font>_009bb874,7);
    if (iVar1 != 0) {
      iVar1 = FUN_00403620(*param_4,6,s_<color_009bb87c,6);
      if (iVar1 != 0) {
        iVar1 = FUN_00403620(*param_4,8,s_<_color>_009bb884,8);
        if (iVar1 != 0) {
          return 0;
        }
      }
      *param_4 = *param_4 + 0xd;
      return 1;
    }
  }
  *param_4 = *param_4 + 7;
  return 1;
}


// ==== FUN_00552a40 @ 0x00552a40 ====

void FUN_00552a40(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 ***pppuVar5;
  int *_Dst;
  int *local_24;
  undefined1 auStack_1c [4];
  undefined4 ***apppuStack_18 [4];
  undefined4 uStack_8;
  uint uStack_4;
  
  if ((*(int *)(in_ECX + 0x16c) != 0) &&
     (*(int *)(in_ECX + 0x170) - *(int *)(in_ECX + 0x16c) >> 2 != 0)) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x58))();
    _Dst = *(int **)(iVar2 + 4);
    if (_Dst != *(int **)(iVar2 + 8)) {
      local_24 = _Dst + 1;
      do {
        piVar1 = (int *)*_Dst;
        if (piVar1 != (int *)0x0) {
          uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__scroll_009bb85c);
          FUN_00402220(auStack_1c,uVar3);
          iVar4 = (**(code **)(*piVar1 + 0x50))();
          pppuVar5 = apppuStack_18[0];
          if (uStack_4 < 0x10) {
            pppuVar5 = apppuStack_18;
          }
          iVar4 = FUN_00403620(0,*(undefined4 *)(iVar4 + 0x14),pppuVar5,uStack_8);
          if (0xf < uStack_4) {
            _free(apppuStack_18[0]);
            return;
          }
          uStack_4 = 0xf;
          uStack_8 = 0;
          apppuStack_18[0] = (undefined4 ***)((uint)apppuStack_18[0] & 0xffffff00);
          if (iVar4 == 0) {
            _Dst = _Dst + 1;
            local_24 = local_24 + 1;
          }
          else {
            (**(code **)*piVar1)(1);
            _memmove(_Dst,local_24,(*(int *)(iVar2 + 8) - (int)local_24 >> 2) * 4);
            *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -4;
          }
        }
      } while (_Dst != *(int **)(iVar2 + 8));
    }
    (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
    if (*(void **)(in_ECX + 0x16c) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x16c));
      return;
    }
    *(undefined4 *)(in_ECX + 0x16c) = 0;
    *(undefined4 *)(in_ECX + 0x170) = 0;
    *(undefined4 *)(in_ECX + 0x174) = 0;
  }
  return;
}


// ==== FUN_00552b90 @ 0x00552b90 ====

undefined4 FUN_00552b90(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  int *in_ECX;
  void *apvStack_1c [4];
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar1 = param_1;
  iVar4 = *(int *)(param_1 + 0xc);
  iVar3 = (**(code **)(*piVar2 + 4))();
  if (iVar4 != iVar3) {
    param_1 = iVar4;
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    iVar4 = (**(code **)(*piVar2 + 0x48))(&param_1);
    if (iVar4 == 0) {
      return 0;
    }
  }
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if (piVar2 != (int *)0x0) {
    uVar5 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bb85c);
    FUN_00402220(apvStack_1c,uVar5);
    piVar2 = (int *)(**(code **)(*piVar2 + 0x4c))(apvStack_1c);
    if (0xf < uStack_8) {
      _free(apvStack_1c[0]);
      return extraout_EAX;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
    if (piVar2 != (int *)0x0) {
      uVar5 = (**(code **)(*piVar2 + 0x30))();
      iVar4 = FUN_00803725(uVar5,0,&Framework::UI::IControl::RTTI_Type_Descriptor,
                           &Framework::UI::Control::VScroll::RTTI_Type_Descriptor,0);
      if (iVar4 != 0) {
        if (0 < *(short *)(iVar1 + 4)) {
          FUN_0055aa00();
          return 1;
        }
        if (*(short *)(iVar1 + 4) < 0) {
          FUN_0055aa60();
        }
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00552c90 @ 0x00552c90 ====

void FUN_00552c90(void)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 ****ppppuVar7;
  uint *in_ECX;
  undefined4 ****ppppuVar8;
  uint unaff_EBP;
  int *piVar9;
  int iVar10;
  uint uStack_88;
  int *piStack_84;
  uint *puStack_80;
  undefined1 *puStack_7c;
  undefined1 auStack_66 [2];
  void *apvStack_64 [2];
  undefined1 local_5c [4];
  undefined1 auStack_58 [4];
  undefined4 ****ppppuStack_54;
  uint uStack_50;
  undefined1 auStack_4c [8];
  int iStack_44;
  uint local_40 [2];
  void *pvStack_38;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  uint *puStack_24;
  int *piStack_20;
  int local_1c;
  int *local_18;
  uint uStack_14;
  undefined4 local_8;
  undefined4 local_4;
  
  puStack_7c = (undefined1 *)0x1;
  puStack_80 = (uint *)&DAT_009bb924;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (int *)((uint)local_18 & 0xffffff00);
  piStack_84 = (int *)0x552cc0;
  FUN_00401740();
  puStack_7c = local_5c;
  puStack_80 = local_40;
  piStack_84 = &local_1c;
  uStack_88 = in_ECX[0x39];
  (**(code **)(*DAT_00b5a688 + 0x34))();
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  uStack_14 = 0xf;
  local_18 = (int *)0x0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401740(&DAT_009bb928,2);
  (**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x39],auStack_2c,auStack_4c,auStack_66 + -6);
  iVar5 = local_1c;
  if ((uint *)0xf < puStack_24) {
    _free(pvStack_38);
    return;
  }
  piVar1 = *(int **)(local_1c + 0x14);
  uStack_88 = 0;
  local_40[0] = 0xf;
  iStack_44 = 0;
  ppppuStack_54 = (undefined4 ****)((uint)ppppuStack_54 & 0xffffff00);
  FUN_00401740(&DAT_009bb92b,0);
  piVar9 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    piStack_84 = (int *)0x1;
    while (piVar9 < local_18) {
      if (*(int **)(iVar5 + 0x14) <= piVar9) {
        FUN_0079dba3();
      }
      if (*(uint *)(iVar5 + 0x18) < 0x10) {
        iVar10 = iVar5 + 4;
      }
      else {
        iVar10 = *(int *)(iVar5 + 4);
      }
      puVar6 = (undefined4 *)(iVar5 + 4);
      cVar3 = FUN_00403d70((int)*(char *)(iVar10 + (int)piVar9));
      if (cVar3 == '\0') {
        uVar2 = in_ECX[0x65];
      }
      else {
        uVar2 = in_ECX[0x66];
      }
      uStack_88 = uStack_88 + uVar2;
      if ((in_ECX[0x44] < uStack_88) &&
         ((**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x39],auStack_58,auStack_66 + -10,&puStack_7c),
         in_ECX[0x44] < unaff_EBP)) {
        ppppuVar7 = ppppuStack_54;
        if (local_40[0] < 0x10) {
          ppppuVar7 = &ppppuStack_54;
        }
        ppppuVar8 = ppppuStack_54;
        if (local_40[0] < 0x10) {
          ppppuVar8 = &ppppuStack_54;
        }
        FUN_004bdb30(&uStack_88,ppppuVar8,(int)ppppuVar7 + iStack_44);
        if (cVar3 == '\0') {
          uStack_88 = puStack_80[0x65];
        }
        else {
          uStack_88 = puStack_80[0x66];
        }
      }
      iVar5 = local_1c;
      if (*(int **)(local_1c + 0x14) <= piVar9) {
        FUN_0079dba3();
      }
      if (*(uint *)(iVar5 + 0x18) < 0x10) {
        puVar4 = puVar6;
      }
      else {
        puVar4 = (undefined4 *)*puVar6;
      }
      ppppuVar7 = ppppuStack_54;
      if (local_40[0] < 0x10) {
        ppppuVar7 = &ppppuStack_54;
      }
      iVar5 = (int)ppppuVar7 + iStack_44;
      ppppuVar7 = ppppuStack_54;
      if (local_40[0] < 0x10) {
        ppppuVar7 = &ppppuStack_54;
      }
      if (iVar5 != 0) {
        iVar5 = iVar5 - (int)ppppuVar7;
      }
      FUN_00557c50(iVar5,1,*(undefined1 *)((int)puVar4 + (int)piVar9));
      iVar5 = local_1c;
      if ((cVar3 != '\0') && (piStack_84 < piVar1)) {
        piStack_84 = (int *)((int)piStack_84 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
        if (*(int **)(local_1c + 0x14) <= piVar9) {
          FUN_0079dba3();
        }
        if (0xf < *(uint *)(iVar5 + 0x18)) {
          puVar6 = (undefined4 *)*puVar6;
        }
        ppppuVar7 = ppppuStack_54;
        if (local_40[0] < 0x10) {
          ppppuVar7 = &ppppuStack_54;
        }
        iVar5 = (int)ppppuVar7 + iStack_44;
        ppppuVar7 = ppppuStack_54;
        if (local_40[0] < 0x10) {
          ppppuVar7 = &ppppuStack_54;
        }
        if (iVar5 != 0) {
          iVar5 = iVar5 - (int)ppppuVar7;
        }
        FUN_00557c50(iVar5,1,*(undefined1 *)((int)puVar6 + (int)piVar9));
      }
      piStack_84 = (int *)((int)piStack_84 + 1);
      piVar9 = (int *)((int)piVar9 + 1);
      in_ECX = puStack_80;
      if (piVar1 <= piVar9) break;
      iVar5 = local_1c;
    }
  }
  (**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x39],auStack_58,apvStack_64,&puStack_7c);
  *puStack_24 = (uint)piVar1;
  *piStack_20 = *piStack_20 + uStack_88;
  if (uStack_50 < 0x10) {
    return;
  }
  _free(apvStack_64[0]);
  return;
}


// ==== FUN_00552fc0 @ 0x00552fc0 ====

int FUN_00552fc0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int extraout_EAX;
  int iVar2;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = *(int *)(param_2 + 4);
  iVar2 = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  do {
    if (iVar1 == *(int *)(param_2 + 8)) {
LAB_0055300d:
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401660(local_1c,0,0xffffffff);
      if (local_4 < 0x10) {
        return param_1;
      }
      _free(local_18);
      return extraout_EAX;
    }
    if (iVar2 == param_3) {
      FUN_00401660(iVar1,0,0xffffffff);
      goto LAB_0055300d;
    }
    iVar1 = iVar1 + 0x1c;
    iVar2 = iVar2 + 1;
  } while( true );
}


// ==== FUN_00553050 @ 0x00553050 ====

void FUN_00553050(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  void *apvStack_1c [5];
  uint uStack_8;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__scroll_009bb85c);
  FUN_00402220(apvStack_1c,uVar2);
  iVar3 = (**(code **)(*piVar1 + 0x4c))(apvStack_1c);
  in_ECX[0x1c] = iVar3;
  if (uStack_8 < 0x10) {
    return;
  }
  _free(apvStack_1c[0]);
  return;
}


// ==== FUN_005530b0 @ 0x005530b0 ====

void FUN_005530b0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  undefined3 *puVar6;
  int *in_ECX;
  char *pcVar7;
  uint uVar8;
  undefined1 local_74 [4];
  void *local_70;
  undefined4 local_60;
  uint local_5c;
  undefined1 local_58 [4];
  void *local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if ((char)in_ECX[0x5e] != '\0') {
    uStack_3c._0_3_ = CONCAT12(1,(undefined2)uStack_3c);
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    local_5c = 0xf;
    local_60 = 0;
    local_70 = (void *)((uint)local_70 & 0xffffff00);
    uVar8 = 0;
    while( true ) {
      iVar3 = in_ECX[0x4f];
      if ((iVar3 == 0) || ((uint)(in_ECX[0x50] - iVar3 >> 2) <= uVar8)) break;
      if ((iVar3 == 0) || ((uint)(in_ECX[0x50] - iVar3 >> 2) <= uVar8)) {
                    /* WARNING: Subroutine does not return */
        FUN_0042f370();
      }
      FUN_00401740(s__d_select_009bb850,9);
      iVar3 = FUN_00404230(local_58);
      if (*(uint *)(iVar3 + 0x18) < 0x10) {
        pcVar7 = (char *)(iVar3 + 4);
      }
      else {
        pcVar7 = *(char **)(iVar3 + 4);
      }
      pcVar4 = pcVar7;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(pcVar7,(int)pcVar4 - (int)(pcVar7 + 1));
      if (0xf < local_40) {
        _free(local_54);
        return;
      }
      local_40 = 0xf;
      local_44 = 0;
      local_54 = (void *)((uint)local_54 & 0xffffff00);
      piVar5 = (int *)(**(code **)(*in_ECX + 0x3c))();
      piVar5 = (int *)(**(code **)(*piVar5 + 0x4c))(local_74);
      puVar6 = (undefined3 *)(**(code **)(*piVar5 + 0x10))();
      local_40 = CONCAT13(local_40._3_1_,*puVar6);
      uStack_3c = *(undefined4 *)(puVar6 + 1);
      local_38 = *(undefined4 *)(puVar6 + 2);
      local_34 = *(int *)(puVar6 + 3);
      local_30 = *(undefined4 *)(puVar6 + 4);
      local_2c = *(int *)(puVar6 + 5);
      local_28 = *(undefined4 *)(puVar6 + 6);
      local_24 = *(undefined4 *)(puVar6 + 7);
      FUN_00401660(puVar6 + 8,0,0xffffffff);
      uVar2 = in_ECX[0x40];
      if (uVar2 < (uint)in_ECX[0x41]) {
        local_34 = in_ECX[0x26] * uVar2 + in_ECX[0x25];
        local_2c = in_ECX[0x26] + -2 + local_34;
        local_40 = CONCAT31(local_40._1_3_,1);
        in_ECX[0x40] = uVar2 + 1;
      }
      else {
        local_40 = (uint)local_40._1_3_ << 8;
      }
      (**(code **)(*piVar5 + 0xc))(&local_40);
      uVar8 = uVar8 + 1;
    }
    if (0xf < local_5c) {
      _free(local_70);
      return;
    }
    local_5c = 0xf;
    local_60 = 0;
    local_70 = (void *)((uint)local_70 & 0xffffff00);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  return;
}


// ==== FUN_005532e0 @ 0x005532e0 ====

int FUN_005532e0(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(in_ECX + 0x11c) != 0) {
    uVar1 = *param_1;
    if ((uVar1 < (uint)((*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c)) &&
       (uVar3 = 0, uVar1 != 0)) {
      iVar2 = *(int *)(in_ECX + 0x14c);
      do {
        if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 0x150) - iVar2 >> 2) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
          FUN_0042f370();
        }
        iVar4 = iVar4 + *(int *)(iVar2 + uVar3 * 4);
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar1);
    }
  }
  return iVar4;
}


// ==== FUN_00553350 @ 0x00553350 ====

uint FUN_00553350(uint *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  uVar3 = 0;
  if (*(int *)(in_ECX + 0x11c) != 0) {
    iVar5 = *(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c);
    iVar2 = iVar5 >> 0x1f;
    iVar5 = iVar5 / 0x1c + iVar2;
    if (iVar5 != iVar2) {
      iVar1 = *(int *)(in_ECX + 0x14c);
      do {
        if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x150) - iVar1 >> 2) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_0042f370();
        }
        uVar3 = uVar3 + *(int *)(iVar1 + uVar4 * 4);
      } while ((uVar3 <= *param_1) && (uVar4 = uVar4 + 1, uVar4 < (uint)(iVar5 - iVar2)));
    }
  }
  return uVar4;
}


// ==== FUN_005533c0 @ 0x005533c0 ====

void FUN_005533c0(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  uVar2 = FUN_005532e0(in_ECX + 0x180);
  *(undefined4 *)(in_ECX + 0x17c) = 0;
  while( true ) {
    if (param_1 <= uVar2) {
      *(int *)(in_ECX + 0x17c) = *(int *)(in_ECX + 0x17c) + param_2;
      return;
    }
    iVar1 = *(int *)(in_ECX + 0x15c);
    if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x160) - iVar1 >> 2) <= uVar2)) break;
    *(int *)(in_ECX + 0x17c) = *(int *)(in_ECX + 0x17c) + *(int *)(iVar1 + uVar2 * 4);
    uVar2 = uVar2 + 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0042f370();
}


// ==== FUN_00553430 @ 0x00553430 ====

void FUN_00553430(void)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *in_ECX;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint uStack_38;
  int local_34;
  int iStack_30;
  int iStack_2c;
  void *local_28;
  int local_24;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_14;
  undefined4 uStack_8;
  uint uStack_4;
  
  uVar7 = 0;
  local_34 = 0;
  local_28 = (void *)0x0;
  local_24 = 0;
  piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if ((piVar2 != (int *)0x0) && (cVar1 = (**(code **)(*piVar2 + 100))(), cVar1 != '\0')) {
    uVar3 = FUN_005532e0(in_ECX + 0x60);
    uStack_38 = uVar3;
    if ((in_ECX[0x47] == 0) || (iStack_30 = (in_ECX[0x48] - in_ECX[0x47]) / 0x1c, iStack_30 == 0)) {
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      FUN_00401740(&DAT_009bb930,1);
      (**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x39],auStack_1c,&local_34,&local_28);
      if (uStack_14 < 0x10) {
        return;
      }
      _free(local_28);
      return;
    }
    iVar4 = FUN_00405d30(in_ECX[0x60]);
    if (*(int *)(iVar4 + 0x14) == 0) {
      FUN_00401830(&DAT_009bb934);
      (**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x39],auStack_1c,&local_34,&local_28);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
      local_34 = 0;
      iStack_30 = 0;
    }
    else {
      iVar4 = in_ECX[0x5f];
      puVar9 = &uStack_38;
      piVar2 = &local_34;
      iVar8 = 0;
      uVar6 = FUN_00405d30(in_ECX[0x60]);
      FUN_00552c90(uVar6,iVar4,piVar2,puVar9);
      if (uVar3 < uStack_38) {
        iVar4 = in_ECX[0x57];
        do {
          if ((iVar4 == 0) || ((uint)(in_ECX[0x58] - iVar4 >> 2) <= uVar3)) goto LAB_00553609;
          iVar8 = iVar8 + *(int *)(iVar4 + uVar3 * 4);
          uVar3 = uVar3 + 1;
        } while (uVar3 < uStack_38);
      }
      iStack_30 = in_ECX[0x5f] - iVar8;
      if ((char)in_ECX[99] == '\x01') {
        iVar4 = in_ECX[0x57];
        if ((iVar4 != 0) && (uVar3 < (uint)(in_ECX[0x58] - iVar4 >> 2))) {
          if ((iVar4 == 0) || ((uint)(in_ECX[0x58] - iVar4 >> 2) <= uVar3)) {
LAB_00553609:
                    /* WARNING: Subroutine does not return */
            FUN_0042f370();
          }
          if (iStack_30 == *(int *)(iVar4 + uVar3 * 4)) {
            iStack_30 = 0;
          }
        }
        iVar8 = FUN_00405d30(in_ECX[0x60]);
        iVar4 = local_34;
        uVar7 = in_ECX[0x5f];
        if (uVar7 < *(uint *)(iVar8 + 0x14)) {
          iVar8 = FUN_00405d30(in_ECX[0x60]);
          if (*(uint *)(iVar8 + 0x18) < 0x10) {
            iVar8 = iVar8 + 4;
          }
          else {
            iVar8 = *(int *)(iVar8 + 4);
          }
          cVar1 = FUN_00403d70((int)*(char *)(iVar8 + uVar7));
          if (cVar1 == '\0') {
            iVar8 = in_ECX[0x65];
          }
          else {
            iVar8 = in_ECX[0x66];
          }
          if ((uint)in_ECX[0x44] < (uint)(iVar4 + iVar8)) {
            uStack_38 = uStack_38 + 1;
            local_34 = 0;
          }
        }
      }
      uVar3 = uStack_38;
    }
    local_24 = in_ECX[0x24] + -1 + local_34;
    uVar7 = (uVar3 - in_ECX[0x43]) * in_ECX[0x26] + in_ECX[0x25];
    in_ECX[0x62] = uVar3;
    in_ECX[0x61] = iStack_30;
  }
  if (((int)uVar7 < in_ECX[0x25]) || ((uint)(in_ECX[0x41] * in_ECX[0x26] + in_ECX[0x25]) <= uVar7))
  {
    FUN_005527a0();
  }
  else {
    iStack_2c = in_ECX[0x45];
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      iVar4 = in_ECX[0x3a];
      uVar6 = (**(code **)(*(int *)in_ECX[1] + 4))();
      puVar5[1] = uVar6;
      *puVar5 = &PTR_FUN_009bb6e0;
      *(undefined1 *)(puVar5 + 2) = 1;
      puVar5[4] = iVar4;
      puVar5[5] = local_24;
      puVar5[6] = uVar7;
      puVar5[7] = 2;
      puVar5[8] = iStack_2c;
    }
    (**(code **)(*DAT_00b5ad24 + 4))(puVar5);
    if (puVar5 != (undefined4 *)0x0) {
      (**(code **)*puVar5)(1);
      return;
    }
  }
  return;
}


// ==== FUN_00553770 @ 0x00553770 ====

void FUN_00553770(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (param_1 < 0) {
    uVar2 = *(uint *)(in_ECX + 0x17c);
    if (uVar2 < 2) {
      if ((uVar2 != 1) && (*(int *)(in_ECX + 0x180) != 0)) {
        iVar3 = *(int *)(in_ECX + 0x180) + -1;
        *(int *)(in_ECX + 0x180) = iVar3;
        iVar3 = FUN_00405d30(iVar3);
        uVar5 = *(undefined4 *)(iVar3 + 0x14);
      }
    }
    else {
      *(uint *)(in_ECX + 0x17c) = uVar2 - 1;
      if (*(int *)(in_ECX + 0x11c) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c;
      }
      if (*(uint *)(in_ECX + 0x180) < uVar2) {
        uVar5 = FUN_00405d30(*(uint *)(in_ECX + 0x180));
        uVar5 = FUN_00552720(*(undefined4 *)(in_ECX + 0x17c),uVar5);
        *(undefined4 *)(in_ECX + 0x17c) = uVar5;
        FUN_00553430();
        return;
      }
    }
    *(undefined4 *)(in_ECX + 0x17c) = uVar5;
    FUN_00553430();
    return;
  }
  iVar3 = *(int *)(in_ECX + 0x11c);
  if ((iVar3 == 0) ||
     ((uint)((*(int *)(in_ECX + 0x120) - iVar3) / 0x1c) <= *(uint *)(in_ECX + 0x180))) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  uVar4 = FUN_00552720(*(undefined4 *)(in_ECX + 0x17c),iVar3 + *(uint *)(in_ECX + 0x180) * 0x1c);
  uVar2 = *(uint *)(in_ECX + 0x180);
  *(uint *)(in_ECX + 0x17c) = uVar4;
  iVar3 = *(int *)(in_ECX + 0x11c);
  if ((iVar3 == 0) || ((uint)((*(int *)(in_ECX + 0x120) - iVar3) / 0x1c) <= uVar2)) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  if (uVar4 < *(uint *)(iVar3 + 0x14 + uVar2 * 0x1c)) {
    iVar3 = FUN_00405d30(uVar2);
    if (*(uint *)(iVar3 + 0x18) < 0x10) {
      iVar3 = iVar3 + 4;
    }
    else {
      iVar3 = *(int *)(iVar3 + 4);
    }
    cVar1 = FUN_00403d70((int)*(char *)(iVar3 + uVar4));
    if (cVar1 != '\0') {
      *(int *)(in_ECX + 0x17c) = *(int *)(in_ECX + 0x17c) + 2;
      FUN_00553430();
      return;
    }
    *(int *)(in_ECX + 0x17c) = *(int *)(in_ECX + 0x17c) + 1;
  }
  else if (*(int *)(in_ECX + 0x11c) != 0) {
    if ((*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c != 0) {
      iVar3 = 0;
      if (*(int *)(in_ECX + 0x11c) != 0) {
        iVar3 = (*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c;
      }
      if (uVar2 < iVar3 - 1U) {
        *(uint *)(in_ECX + 0x180) = uVar2 + 1;
        *(undefined4 *)(in_ECX + 0x17c) = 0;
        FUN_00553430();
        return;
      }
    }
  }
  FUN_00553430();
  return;
}


// ==== FUN_005539a0 @ 0x005539a0 ====

void FUN_005539a0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  
  if (((*(char *)((int)in_ECX + 0xa6) != '\0') &&
      (piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))(), piVar2 != (int *)0x0)) &&
     (iVar3 = (**(code **)(*piVar2 + 4))(), iVar3 == param_1)) {
    cVar1 = (**(code **)(*piVar2 + 100))();
    if (cVar1 == '\x01') {
      puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = &PTR_FUN_009bb6cc;
        *(undefined1 *)(puVar4 + 1) = 1;
      }
      FUN_00797a20(puVar4);
      FUN_00553430();
      return;
    }
    puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_009bb6cc;
      *(undefined1 *)(puVar4 + 1) = 0;
    }
    FUN_00797a20(puVar4);
    FUN_005527a0();
    in_ECX[100] = 0;
  }
  return;
}


// ==== FUN_00553a40 @ 0x00553a40 ====

void FUN_00553a40(int param_1)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 ****ppppuVar5;
  int iVar6;
  int iVar7;
  int *in_ECX;
  uint uVar8;
  uint uVar9;
  uint uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  uint uStack_24;
  undefined1 auStack_1c [4];
  undefined4 ****appppuStack_18 [4];
  int iStack_8;
  uint uStack_4;
  
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar4 = (**(code **)(*piVar3 + 0x14))();
  uStack_24 = *(int *)(param_1 + 0x10) - (*(int *)(iVar4 + 8) + in_ECX[0x24]);
  uVar8 = (*(int *)(param_1 + 0x14) - (*(int *)(iVar4 + 0xc) + in_ECX[0x25])) / in_ECX[0x26] +
          in_ECX[0x43];
  uStack_2c = uVar8;
  if ((in_ECX[0x4b] == 0) || ((uint)((in_ECX[0x4c] - in_ECX[0x4b]) / 0x1c) <= uVar8)) {
    if ((in_ECX[0x47] == 0) || ((in_ECX[0x48] - in_ECX[0x47]) / 0x1c == 0)) {
      in_ECX[0x60] = 0;
      in_ECX[0x5f] = 0;
      FUN_00553430();
      return;
    }
    if (in_ECX[0x47] == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (in_ECX[0x48] - in_ECX[0x47]) / 0x1c;
    }
    in_ECX[0x60] = iVar4 + -1;
    iVar4 = FUN_00405d30(iVar4 + -1);
    in_ECX[0x5f] = *(int *)(iVar4 + 0x14);
    FUN_00553430();
    return;
  }
  if ((in_ECX[0x4b] != 0) && (uVar8 < (uint)((in_ECX[0x4c] - in_ECX[0x4b]) / 0x1c))) {
    iVar4 = FUN_00405d30(uVar8);
    uVar9 = 0;
    uVar1 = *(uint *)(iVar4 + 0x14);
    uStack_4 = 0xf;
    iStack_8 = 0;
    appppuStack_18[0] = (undefined4 ****)((uint)appppuStack_18[0] & 0xffffff00);
    FUN_00401740(&DAT_009bb8ab,0);
    if ((int)uStack_24 < 1) {
      *(undefined1 *)(in_ECX + 99) = 1;
    }
    else if (uVar1 != 0) {
      do {
        if (*(uint *)(iVar4 + 0x14) <= uVar9) {
          FUN_0079dba3();
        }
        if (*(uint *)(iVar4 + 0x18) < 0x10) {
          iVar7 = iVar4 + 4;
        }
        else {
          iVar7 = *(int *)(iVar4 + 4);
        }
        ppppuVar5 = appppuStack_18[0];
        if (uStack_4 < 0x10) {
          ppppuVar5 = appppuStack_18;
        }
        iVar6 = (int)ppppuVar5 + iStack_8;
        ppppuVar5 = appppuStack_18[0];
        if (uStack_4 < 0x10) {
          ppppuVar5 = appppuStack_18;
        }
        if (iVar6 != 0) {
          iVar6 = iVar6 - (int)ppppuVar5;
        }
        FUN_00557c50(iVar6,1,*(undefined1 *)(iVar7 + uVar9));
        if (*(uint *)(iVar4 + 0x14) <= uVar9) {
          FUN_0079dba3();
        }
        if (*(uint *)(iVar4 + 0x18) < 0x10) {
          iVar7 = iVar4 + 4;
        }
        else {
          iVar7 = *(int *)(iVar4 + 4);
        }
        cVar2 = FUN_00403d70((int)*(char *)(iVar7 + uVar9));
        if (cVar2 != '\0') {
          uVar9 = uVar9 + 1;
          if (*(uint *)(iVar4 + 0x14) <= uVar9) {
            FUN_0079dba3();
          }
          if (*(uint *)(iVar4 + 0x18) < 0x10) {
            iVar7 = iVar4 + 4;
          }
          else {
            iVar7 = *(int *)(iVar4 + 4);
          }
          FUN_00557d70(CONCAT31((int3)((uint)iVar7 >> 8),*(undefined1 *)(iVar7 + uVar9)));
        }
        (**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x39],auStack_1c,&uStack_30,auStack_28);
        uVar9 = uVar9 + 1;
      } while ((uStack_30 < uStack_24) && (uVar9 < uVar1));
    }
    iVar4 = FUN_00553350(&uStack_2c);
    in_ECX[0x60] = iVar4;
    FUN_005533c0(uVar8,uVar9);
    if (0xf < uStack_4) {
      _free(appppuStack_18[0]);
      return;
    }
    FUN_00553430();
  }
  return;
}


// ==== FUN_00553d00 @ 0x00553d00 ====

undefined4 FUN_00553d00(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if ((iVar2 == iVar1) && (*(char *)((int)in_ECX + 0xa6) != '\0')) {
    iVar1 = param_1[2];
    if (iVar1 == 1) {
      FUN_00553a40(param_1 + 3);
      return 1;
    }
    if (iVar1 == 7) {
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(4,0);
      return 1;
    }
    if (iVar1 == 8) {
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(5,0);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00553d90 @ 0x00553d90 ====

void FUN_00553d90(void)

{
  SHORT SVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bb944;
  in_ECX[0x1c] = 0;
  in_ECX[0x23] = 0xf;
  in_ECX[0x22] = 0;
  *(undefined1 *)(in_ECX + 0x1e) = 0;
  iVar2 = FUN_00503ac0();
  in_ECX[0x2e] = iVar2;
  *(undefined1 *)(iVar2 + 0x45) = 1;
  *(undefined4 *)(in_ECX[0x2e] + 4) = in_ECX[0x2e];
  *(undefined4 *)in_ECX[0x2e] = in_ECX[0x2e];
  *(undefined4 *)(in_ECX[0x2e] + 8) = in_ECX[0x2e];
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x38] = 0xf;
  in_ECX[0x37] = 0;
  *(undefined1 *)(in_ECX + 0x33) = 0;
  in_ECX[0x39] = 1;
  in_ECX[0x3a] = 0;
  in_ECX[0x3b] = 1;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  *(undefined1 *)((int)in_ECX + 0xf1) = 0;
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x43] = 0;
  in_ECX[0x47] = 0;
  in_ECX[0x48] = 0;
  in_ECX[0x49] = 0;
  in_ECX[0x4b] = 0;
  in_ECX[0x4c] = 0;
  in_ECX[0x4d] = 0;
  in_ECX[0x4f] = 0;
  in_ECX[0x50] = 0;
  in_ECX[0x51] = 0;
  in_ECX[0x53] = 0;
  in_ECX[0x54] = 0;
  in_ECX[0x55] = 0;
  in_ECX[0x57] = 0;
  in_ECX[0x58] = 0;
  in_ECX[0x59] = 0;
  in_ECX[0x5b] = 0;
  in_ECX[0x5c] = 0;
  in_ECX[0x5d] = 0;
  *(undefined1 *)((int)in_ECX + 0x179) = 0;
  in_ECX[0x5f] = 0;
  in_ECX[0x60] = 0;
  in_ECX[0x61] = 0;
  in_ECX[0x62] = 0;
  *(undefined1 *)(in_ECX + 99) = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  *(undefined1 *)(in_ECX + 0x5e) = 0;
  SVar1 = GetKeyState(0x2d);
  *(SHORT *)((int)in_ECX + 0x18e) = SVar1;
  in_ECX[100] = 0;
  *(undefined1 *)(in_ECX + 0x67) = 0;
  return;
}


// ==== FUN_00553f20 @ 0x00553f20 ====

void FUN_00553f20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb944;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  if ((void *)in_ECX[0x5b] != (void *)0x0) {
    _free((void *)in_ECX[0x5b]);
    return;
  }
  in_ECX[0x5b] = 0;
  in_ECX[0x5c] = 0;
  in_ECX[0x5d] = 0;
  if ((void *)in_ECX[0x57] != (void *)0x0) {
    _free((void *)in_ECX[0x57]);
    return;
  }
  in_ECX[0x57] = 0;
  in_ECX[0x58] = 0;
  in_ECX[0x59] = 0;
  if ((void *)in_ECX[0x53] != (void *)0x0) {
    _free((void *)in_ECX[0x53]);
    return;
  }
  in_ECX[0x53] = 0;
  in_ECX[0x54] = 0;
  in_ECX[0x55] = 0;
  if ((void *)in_ECX[0x4f] != (void *)0x0) {
    _free((void *)in_ECX[0x4f]);
    return;
  }
  in_ECX[0x4f] = 0;
  in_ECX[0x50] = 0;
  in_ECX[0x51] = 0;
  if (in_ECX[0x4b] != 0) {
    FUN_00405de0(in_ECX[0x4b],in_ECX[0x4c],in_ECX + 0x4a,in_ECX);
    _free((void *)in_ECX[0x4b]);
    return;
  }
  in_ECX[0x4b] = 0;
  in_ECX[0x4c] = 0;
  in_ECX[0x4d] = 0;
  if (in_ECX[0x47] != 0) {
    FUN_00405de0(in_ECX[0x47],in_ECX[0x48],in_ECX + 0x46,in_ECX);
    _free((void *)in_ECX[0x47]);
    return;
  }
  in_ECX[0x47] = 0;
  in_ECX[0x48] = 0;
  in_ECX[0x49] = 0;
  if ((uint)in_ECX[0x38] < 0x10) {
    in_ECX[0x38] = 0xf;
    in_ECX[0x37] = 0;
    *(undefined1 *)(in_ECX + 0x33) = 0;
    FUN_00505a00();
    FUN_00552170();
    return;
  }
  _free((void *)in_ECX[0x33]);
  return;
}


// ==== FUN_00554090 @ 0x00554090 ====

void FUN_00554090(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  void *unaff_EBP;
  int unaff_EDI;
  undefined1 auStack_3c [2];
  undefined1 auStack_3a [2];
  undefined1 local_38 [4];
  void *local_34;
  uint uStack_30;
  void *pvStack_2c;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  uint local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740(&DAT_009bb8a2,0);
  FUN_00406720(local_1c);
  piVar1 = param_1 + 0x1e;
  FUN_00558060(piVar1);
  in_ECX[0x3a] = param_1[0x2c];
  in_ECX[0x39] = param_1[0x28];
  in_ECX[0x30] = param_1[0x25];
  in_ECX[0x31] = param_1[0x26];
  in_ECX[0x3b] = param_1[0x27];
  *(undefined1 *)(in_ECX + 0x3c) = 1;
  in_ECX[0x3d] = *param_1;
  in_ECX[0x3e] = param_1[1];
  in_ECX[0x3f] = param_1[2];
  if ((uint)*(ushort *)(param_1 + 0x2a) < (uint)param_1[0x23]) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401660(piVar1,0,(uint)*(ushort *)(param_1 + 0x2a));
    FUN_00401660(local_38,0,0xffffffff);
    if (0xf < local_20) {
      _free(local_34);
      return;
    }
  }
  else {
    FUN_00401660(piVar1,0,0xffffffff);
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar2 = (**(code **)(*piVar1 + 0x14))();
  in_ECX[0x41] = ((in_ECX[0x31] * -2 - *(int *)(iVar2 + 0xc)) + *(int *)(iVar2 + 0x14)) /
                 in_ECX[0x26];
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar2 = (**(code **)(*piVar1 + 0x14))();
  in_ECX[0x44] = ((*(int *)(iVar2 + 0x10) - (uint)*(ushort *)((int)in_ECX + 0xb2)) - in_ECX[0x24]) -
                 *(int *)(iVar2 + 8);
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(&DAT_009bb8a4,1);
  (**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x39],local_38,in_ECX + 0x65,auStack_3c);
  if (0xf < uStack_30) {
    _free(unaff_EBP);
    return;
  }
  if ((*(char *)((int)in_ECX + 0xa6) != '\0') || (*(char *)((int)in_ECX + 0xa7) != '\0')) {
    uStack_30 = 0xf;
    local_34 = (void *)0x0;
    FUN_00401740(&DAT_009bb8a8,2);
    (**(code **)(*DAT_00b5a688 + 0x34))
              (in_ECX[0x39],auStack_3c + -0xc,in_ECX + 0x66,auStack_3c + -0x10);
    if (0xf < uStack_30) {
      _free((void *)((uint)unaff_EBP & 0xffffff00));
      return;
    }
  }
  in_ECX[0x45] = unaff_EDI;
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  if (local_18 < 0x10) {
    return;
  }
  _free(pvStack_2c);
  return;
}


// ==== FUN_005542f0 @ 0x005542f0 ====

void FUN_005542f0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  uVar3 = 0;
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      uVar2 = *(uint *)(param_1 + 0x18);
      if (uVar2 < 0x10) {
        iVar4 = param_1 + 4;
      }
      else {
        iVar4 = *(int *)(param_1 + 4);
      }
      if (*(char *)(iVar4 + uVar5) == '<') {
LAB_00554341:
        if (uVar2 < 0x10) {
          iVar4 = param_1 + 4;
        }
        else {
          iVar4 = *(int *)(param_1 + 4);
        }
        if (*(char *)(iVar4 + uVar5) == '<') {
          local_20 = 0xf;
          local_24 = 0;
          local_34 = (void *)((uint)local_34 & 0xffffff00);
          FUN_00401660(param_1,uVar3,uVar5 - uVar3);
          FUN_00406720(local_38);
          if (0xf < local_20) {
            _free(local_34);
            return;
          }
          local_20 = 0xf;
          local_24 = 0;
          local_34 = (void *)((uint)local_34 & 0xffffff00);
          uVar3 = uVar5;
        }
        else {
          local_4 = 0xf;
          local_8 = 0;
          local_18 = (void *)((uint)local_18 & 0xffffff00);
          FUN_00401660(param_1,uVar3,(uVar5 + 1) - uVar3);
          FUN_00406720(local_1c);
          if (0xf < local_4) {
            _free(local_18);
            return;
          }
          local_4 = 0xf;
          local_8 = 0;
          local_18 = (void *)((uint)local_18 & 0xffffff00);
          uVar3 = uVar5 + 1;
        }
        uVar5 = uVar3;
      }
      else {
        if (uVar2 < 0x10) {
          iVar4 = param_1 + 4;
        }
        else {
          iVar4 = *(int *)(param_1 + 4);
        }
        if (*(char *)(iVar4 + uVar5) == '>') goto LAB_00554341;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
    if (uVar3 < uVar1) {
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401660(param_1,uVar3,uVar1 - uVar3);
      FUN_00406720(local_1c);
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00554460 @ 0x00554460 ====

void FUN_00554460(int param_1,uint param_2,undefined1 param_3,void *param_4)

{
  int iVar1;
  uint uVar2;
  uint in_stack_00000024;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 0) {
LAB_005544ae:
    uVar2 = 0;
  }
  else {
    if (param_2 < (uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c)) {
      FUN_00401660(&param_3,0,0xffffffff);
      goto LAB_005544d8;
    }
    if (iVar1 == 0) goto LAB_005544ae;
    uVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
  }
  if (uVar2 == param_2) {
    FUN_00406720(&param_3);
  }
LAB_005544d8:
  if (in_stack_00000024 < 0x10) {
    return;
  }
  _free(param_4);
  return;
}


// ==== FUN_00554500 @ 0x00554500 ====

/* WARNING: Removing unreachable block (ram,0x005546ae) */

undefined4 FUN_00554500(undefined4 param_1)

{
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  int iVar3;
  byte ****ppppbVar4;
  void *_Memory;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  void *local_80;
  uint local_7c;
  undefined4 local_6c;
  undefined1 local_68 [4];
  void *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58 [4];
  void *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48 [4];
  void *local_44;
  int local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  byte ****local_34 [4];
  int local_24;
  uint local_20;
  undefined1 local_1c [28];
  
  local_44 = (void *)0x0;
  local_40 = 0;
  local_3c = 0;
  local_54 = (void *)0x0;
  local_50 = 0;
  local_4c = 0;
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (byte ****)((uint)local_34[0] & 0xffffff00);
  FUN_00401740(s___GT___009bb8b0,6);
  FUN_00406720(local_38);
  if (0xf < local_20) {
    _free(local_34[0]);
    return extraout_EAX;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (byte ****)((uint)local_34[0] & 0xffffff00);
  FUN_00401740(s___LT___009bb8b8,6);
  FUN_00406720(local_38);
  if (0xf < local_20) {
    _free(local_34[0]);
    return extraout_EAX_00;
  }
  local_64 = (void *)0x0;
  local_60 = 0;
  local_5c = 0;
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (byte ****)((uint)local_34[0] & 0xffffff00);
  FUN_00401740(&DAT_009bb8c0,1);
  FUN_00406720(local_38);
  if (0xf < local_20) {
    _free(local_34[0]);
    return extraout_EAX_01;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (byte ****)((uint)local_34[0] & 0xffffff00);
  FUN_00401740(&DAT_009bb8c4,1);
  FUN_00406720(local_38);
  if (0xf < local_20) {
    _free(local_34[0]);
    return extraout_EAX_02;
  }
  FUN_005542f0(param_1,local_48);
  local_7c = 0;
  local_80 = local_44;
  _Memory = local_44;
  do {
    if ((_Memory == (void *)0x0) || ((uint)((local_40 - (int)_Memory) / 0x1c) <= local_7c)) {
      if (local_64 != (void *)0x0) {
        FUN_00405de0(local_64,local_60,local_68,local_6c);
        _free(local_64);
        return extraout_EAX_04;
      }
      local_64 = (void *)0x0;
      local_60 = 0;
      local_5c = 0;
      if (local_54 != (void *)0x0) {
        FUN_00405de0(local_54,local_50,local_58,local_6c);
        _free(local_54);
        return extraout_EAX_05;
      }
      local_54 = (void *)0x0;
      local_50 = 0;
      local_4c = 0;
      if (_Memory == (void *)0x0) {
        return 0;
      }
      FUN_00405de0(_Memory,local_40,local_48,local_6c);
      _free(_Memory);
      return extraout_EAX_06;
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (byte ****)((uint)local_34[0] & 0xffffff00);
    FUN_00401660(local_80,0,0xffffffff);
    if (local_24 == 0) {
LAB_005546e3:
      if (local_24 != 0) goto LAB_005546f2;
    }
    else {
      ppppbVar4 = local_34[0];
      if (local_20 < 0x10) {
        ppppbVar4 = (byte ****)local_34;
      }
      iVar3 = 0;
      bVar6 = false;
      iVar1 = 0;
      bVar7 = true;
      pbVar5 = &DAT_009bb8c6;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *(byte *)ppppbVar4 < *pbVar5;
        bVar7 = *(byte *)ppppbVar4 == *pbVar5;
        ppppbVar4 = (byte ****)((int)ppppbVar4 + 1);
        pbVar5 = pbVar5 + 1;
      } while (bVar7);
      if (!bVar7) {
        iVar1 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      }
      _Memory = local_44;
      if (iVar1 == 0) goto LAB_005546e3;
LAB_005546f2:
      iVar1 = FUN_00403620(0,local_24,s_<_font>_009bb8c8,7);
      if (iVar1 != 0) {
        iVar1 = FUN_00403620(0,local_24,s_<_color>_009bb8d0,8);
        if (iVar1 != 0) {
          iVar1 = FUN_00403620(0,5,s_<font_009bb8dc,5);
          if (iVar1 != 0) {
            iVar1 = FUN_00403620(0,6,s_<color_009bb8e4,6);
            if (iVar1 != 0) {
              iVar1 = FUN_00403620(0,6,s_<space_009bb8ec,6);
              if ((((iVar1 != 0) && (iVar1 = FUN_00557ba0(0,4,&DAT_009bb8f4), iVar1 != 0)) &&
                  (iVar1 = FUN_00557ba0(0,7,s_<center_009bb8fc), iVar1 != 0)) &&
                 (((iVar1 = FUN_004233d0(&DAT_009bb904,0), iVar1 == -1 &&
                   (iVar1 = FUN_004233d0(s_<overlab_009bb90c,0), iVar1 == -1)) &&
                  (iVar1 = FUN_004233d0(s_<_overlab>_009bb918,0), iVar1 == -1)))) {
                uVar2 = FUN_00404a40(local_1c,local_38,local_58,local_68);
                FUN_00401660(uVar2,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
            }
          }
        }
      }
    }
    if (0xf < local_20) {
      _free(local_34[0]);
      return extraout_EAX_03;
    }
    local_7c = local_7c + 1;
    local_80 = (void *)((int)local_80 + 0x1c);
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (byte ****)((uint)local_34[0] & 0xffffff00);
  } while( true );
}


// ==== FUN_00554930 @ 0x00554930 ====

void FUN_00554930(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int aiStack_f8 [2];
  undefined4 uStack_f0;
  undefined1 local_ec [4];
  int local_e8;
  int local_e4;
  undefined4 local_e0;
  int iStack_dc;
  undefined4 uStack_d8;
  int iStack_d4;
  undefined1 uStack_cc;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined1 local_a8 [4];
  void *local_a4;
  undefined4 local_94;
  uint local_90;
  undefined1 auStack_34 [52];
  
  local_e8 = 0;
  local_e4 = 0;
  local_e0 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    local_90 = 0xf;
    local_94 = 0;
    local_a4 = (void *)((uint)local_a4 & 0xffffff00);
    FUN_00401740(&DAT_009bb894,1);
    FUN_00405300(param_1,local_a8,local_ec);
    if (0xf < local_90) {
      _free(local_a4);
      return;
    }
    if ((local_e8 != 0) &&
       (iVar2 = local_e4 - local_e8 >> 0x1f, (local_e4 - local_e8) / 0x1c + iVar2 != iVar2)) {
      uVar1 = FUN_00405d30(1);
      uStack_d8 = thunk_FUN_00796fb0(uVar1);
      FUN_00430ce0(&uStack_d8);
      iStack_dc = (**(code **)(*DAT_00b5a7ac + 4))();
      if (iStack_dc != 0) {
        iVar2 = (**(code **)(*DAT_00b5a7ac + 8))(1);
        if (iVar2 != 0) {
          FUN_004fec10();
          uStack_b8 = 0xf;
          uStack_bc = 0;
          uStack_cc = 0;
          uStack_b4 = 0;
          uStack_b0 = 0;
          uStack_ac = 0;
          pvVar3 = operator_new(0x468);
          if (pvVar3 != (void *)0x0) {
            iStack_d4 = FUN_00505f10();
            if (iStack_d4 != 0) {
              FUN_00552540();
              FUN_00503fe0();
              uStack_f0 = 0;
              FUN_00557be0(aiStack_f8,&uStack_f0);
              FUN_005523f0(aiStack_f8[0] + 0x10);
              uVar1 = FUN_00405d30(0);
              FUN_00401660(uVar1,0,0xffffffff);
              aiStack_f8[0] = 0;
              uVar1 = FUN_00504640(aiStack_f8,auStack_34);
              FUN_00505600(aiStack_f8,uVar1);
              FUN_00446f40();
              uStack_f0 = 1;
              piVar4 = (int *)FUN_00557be0(aiStack_f8,&uStack_f0);
              aiStack_f8[0] = 1;
              uVar1 = FUN_00504640(aiStack_f8,*piVar4 + 0x10);
              FUN_00505600(aiStack_f8,uVar1);
              FUN_00446f40();
              uStack_f0 = 2;
              piVar4 = (int *)FUN_00557be0(aiStack_f8,&uStack_f0);
              aiStack_f8[0] = 2;
              uVar1 = FUN_00504640(aiStack_f8,*piVar4 + 0x10);
              FUN_00505600(aiStack_f8,uVar1);
              FUN_00446f40();
              FUN_00401830(s__d_select_009bb898);
              iVar2 = FUN_00404230(local_a8);
              if (*(uint *)(iVar2 + 0x18) < 0x10) {
                iVar2 = iVar2 + 4;
              }
              else {
                iVar2 = *(int *)(iVar2 + 4);
              }
              FUN_00403810(iVar2);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
          }
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
    }
    FUN_00406250();
  }
  return;
}


// ==== FUN_00554d00 @ 0x00554d00 ====

uint FUN_00554d00(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint extraout_EAX;
  int in_ECX;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint local_3c;
  int iStack_38;
  uint local_34 [2];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int local_24;
  uint uStack_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar2 = param_2;
  local_34[0] = 0;
  local_34[1] = 0;
  local_24 = in_ECX;
  if (*(char *)(in_ECX + 0xa6) == '\x01') {
    uVar4 = (**(code **)(*DAT_00b5a688 + 0x34))
                      (*(undefined4 *)(in_ECX + 0xe4),param_1,local_34,local_34 + 1);
  }
  else {
    uVar4 = FUN_00554500(param_1);
  }
  if (local_34[0] <= *(uint *)(in_ECX + 0x110)) {
    return uVar4 & 0xffffff00;
  }
  local_3c = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_009bb8ac,0);
  FUN_00406720(local_1c);
  uStack_20 = *(uint *)(param_1 + 0x14);
  param_2 = 0;
  uVar4 = 0;
  if (uStack_20 != 0) {
    iStack_38 = 0;
    do {
      if (*(uint *)(param_1 + 0x14) <= param_2) {
        FUN_0079dba3();
      }
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        iVar5 = param_1 + 4;
      }
      else {
        iVar5 = *(int *)(param_1 + 4);
      }
      puVar7 = (undefined4 *)(param_1 + 4);
      iVar1 = *(int *)(iVar2 + 4);
      if ((iVar1 == 0) || ((uint)((*(int *)(iVar2 + 8) - iVar1) / 0x1c) <= local_3c)) {
LAB_00554f8f:
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar4 = *(uint *)(iStack_38 + 0x18 + iVar1);
      uStack_2c = CONCAT31(uStack_2c._1_3_,*(undefined1 *)(iVar5 + param_2));
      puVar6 = (undefined4 *)(iStack_38 + iVar1 + 4);
      if (uVar4 < 0x10) {
        puVar8 = puVar6;
      }
      else {
        puVar8 = (undefined4 *)*puVar6;
      }
      iVar5 = *(int *)(iStack_38 + iVar1 + 0x14) + (int)puVar8;
      if (0xf < uVar4) {
        puVar6 = (undefined4 *)*puVar6;
      }
      if (iVar5 != 0) {
        iVar5 = iVar5 - (int)puVar6;
      }
      FUN_00557c50(iVar5,1,uStack_2c);
      if (*(uint *)(param_1 + 0x14) <= param_2) {
        FUN_0079dba3();
      }
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        puVar6 = puVar7;
      }
      else {
        puVar6 = (undefined4 *)*puVar7;
      }
      cVar3 = FUN_00403d70((int)*(char *)((int)puVar6 + param_2));
      if (cVar3 != '\0') {
        param_2 = param_2 + 1;
        if (*(uint *)(param_1 + 0x14) <= param_2) {
          FUN_0079dba3();
        }
        if (0xf < *(uint *)(param_1 + 0x18)) {
          puVar7 = (undefined4 *)*puVar7;
        }
        iVar5 = *(int *)(iVar2 + 4);
        if ((iVar5 == 0) || ((uint)((*(int *)(iVar2 + 8) - iVar5) / 0x1c) <= local_3c))
        goto LAB_00554f8f;
        uVar4 = *(uint *)(iStack_38 + 0x18 + iVar5);
        uStack_28 = CONCAT31(uStack_28._1_3_,*(undefined1 *)((int)puVar7 + param_2));
        puVar7 = (undefined4 *)(iStack_38 + iVar5 + 4);
        if (uVar4 < 0x10) {
          puVar6 = puVar7;
        }
        else {
          puVar6 = (undefined4 *)*puVar7;
        }
        iVar5 = *(int *)(iStack_38 + iVar5 + 0x14) + (int)puVar6;
        if (0xf < uVar4) {
          puVar7 = (undefined4 *)*puVar7;
        }
        if (iVar5 != 0) {
          iVar5 = iVar5 - (int)puVar7;
        }
        FUN_00557c50(iVar5,1,uStack_28);
      }
      iVar1 = local_24;
      iVar5 = *(int *)(iVar2 + 4);
      if ((iVar5 == 0) || ((uint)((*(int *)(iVar2 + 8) - iVar5) / 0x1c) <= local_3c))
      goto LAB_00554f8f;
      (**(code **)(*DAT_00b5a688 + 0x34))
                (*(undefined4 *)(local_24 + 0xe4),iStack_38 + iVar5,local_34,local_34 + 1);
      if (*(uint *)(iVar1 + 0x110) < local_34[0]) {
        FUN_00406720(local_1c);
        local_3c = local_3c + 1;
        iStack_38 = iStack_38 + 0x1c;
      }
      uVar4 = param_2 + 1;
      param_2 = uVar4;
    } while (uVar4 < uStack_20);
  }
  if (local_4 < 0x10) {
    return CONCAT31((int3)(uVar4 >> 8),1);
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_00554fd0 @ 0x00554fd0 ====

void FUN_00554fd0(void)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  undefined4 *puVar4;
  void *_Memory;
  char cVar5;
  undefined4 uVar6;
  uint uVar7;
  int *in_ECX;
  void *pvVar8;
  int iVar9;
  uint uVar10;
  uint local_6c;
  int local_68;
  int local_64;
  undefined1 local_60 [4];
  void *local_5c;
  int local_58;
  undefined4 local_54;
  undefined1 local_50 [4];
  void *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_3c;
  uint local_38;
  undefined1 local_34 [8];
  void *local_2c;
  uint uStack_18;
  
  FUN_00504250(in_ECX + 0x30);
  FUN_00401740(&DAT_009bb840,0);
  in_ECX[0x40] = 0;
  if ((in_ECX[0x1c] == 0) && (*(char *)((int)in_ECX + 0xa7) == '\0')) {
    iVar1 = in_ECX[0x48];
    for (iVar9 = in_ECX[0x47]; iVar9 != iVar1; iVar9 = iVar9 + 0x1c) {
      uVar6 = FUN_00402220(local_50,iVar9,&DAT_009bb844);
      FUN_00401ff0(uVar6,0,0xffffffff);
      if (0xf < local_38) {
        _free(local_4c);
        return;
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = (void *)((uint)local_4c & 0xffffff00);
    }
    (**(code **)(*in_ECX + 8))(local_34);
  }
  else {
    if ((*(char *)((int)in_ECX + 0xa6) == '\x01') || (*(char *)((int)in_ECX + 0xa7) == '\x01')) {
      if ((in_ECX[0x4b] == 0) || (local_64 = (in_ECX[0x4c] - in_ECX[0x4b]) / 0x1c, local_64 == 0)) {
        local_4c = (void *)0x0;
        local_48 = 0;
        local_44 = 0;
        if ((void *)in_ECX[0x53] != (void *)0x0) {
          _free((void *)in_ECX[0x53]);
          return;
        }
        in_ECX[0x53] = 0;
        in_ECX[0x54] = 0;
        in_ECX[0x55] = 0;
        if ((void *)in_ECX[0x57] != (void *)0x0) {
          _free((void *)in_ECX[0x57]);
          return;
        }
        in_ECX[0x57] = 0;
        in_ECX[0x58] = 0;
        in_ECX[0x59] = 0;
        FUN_00401740(&DAT_009bb846,0);
        iVar9 = in_ECX[0x47];
        local_5c = (void *)0x0;
        local_58 = 0;
        local_54 = 0;
        local_68 = iVar9;
        if (iVar9 != in_ECX[0x48]) {
          do {
            if (local_5c != (void *)0x0) {
              FUN_00405de0(local_5c,local_58,local_60,local_64);
              _free(local_5c);
              return;
            }
            local_5c = (void *)0x0;
            local_58 = 0;
            local_54 = 0;
            cVar5 = FUN_00554d00(iVar9,local_60);
            if (cVar5 == '\0') {
              FUN_00406720(iVar9);
              iVar1 = in_ECX[0x57];
              local_64 = *(int *)(iVar9 + 0x14);
              if ((iVar1 == 0) ||
                 ((uint)(in_ECX[0x59] - iVar1 >> 2) <= (uint)(in_ECX[0x58] - iVar1 >> 2))) {
                FUN_0042f3e0(in_ECX[0x58],1,&local_64);
              }
              else {
                piVar2 = (int *)in_ECX[0x58];
                *piVar2 = local_64;
                in_ECX[0x58] = (int)(piVar2 + 1);
              }
              iVar1 = in_ECX[0x53];
              local_64 = 1;
              if ((iVar1 == 0) ||
                 ((uint)(in_ECX[0x55] - iVar1 >> 2) <= (uint)(in_ECX[0x54] - iVar1 >> 2))) {
                FUN_0042f3e0(in_ECX[0x54],1,&local_64);
              }
              else {
                puVar4 = (undefined4 *)in_ECX[0x54];
                *puVar4 = 1;
                in_ECX[0x54] = (int)(puVar4 + 1);
              }
            }
            else {
              if (local_5c == (void *)0x0) {
                local_6c = 0;
              }
              else {
                local_6c = (local_58 - (int)local_5c) / 0x1c;
              }
              uVar10 = 0;
              if (local_6c != 0) {
                pvVar8 = local_5c;
                do {
                  if ((local_5c == (void *)0x0) ||
                     (uVar7 = (local_58 - (int)local_5c) / 0x1c, uVar7 <= uVar10)) {
                    /* WARNING: Subroutine does not return */
                    FUN_00405ca0();
                  }
                  FUN_00406720(pvVar8);
                  if (uVar7 <= uVar10) {
                    /* WARNING: Subroutine does not return */
                    FUN_00405ca0();
                  }
                  iVar9 = in_ECX[0x57];
                  local_64 = *(int *)((int)pvVar8 + 0x14);
                  if ((iVar9 == 0) ||
                     ((uint)(in_ECX[0x59] - iVar9 >> 2) <= (uint)(in_ECX[0x58] - iVar9 >> 2))) {
                    FUN_0042f3e0(in_ECX[0x58],1,&local_64);
                  }
                  else {
                    piVar2 = (int *)in_ECX[0x58];
                    *piVar2 = local_64;
                    in_ECX[0x58] = (int)(piVar2 + 1);
                  }
                  uVar10 = uVar10 + 1;
                  pvVar8 = (void *)((int)pvVar8 + 0x1c);
                } while (uVar10 < local_6c);
              }
              iVar9 = in_ECX[0x53];
              if ((iVar9 == 0) ||
                 ((uint)(in_ECX[0x55] - iVar9 >> 2) <= (uint)(in_ECX[0x54] - iVar9 >> 2))) {
                FUN_0042f3e0(in_ECX[0x54],1,&local_6c);
                iVar9 = local_68;
              }
              else {
                puVar3 = (uint *)in_ECX[0x54];
                *puVar3 = local_6c;
                in_ECX[0x54] = (int)(puVar3 + 1);
                iVar9 = local_68;
              }
            }
            FUN_00401ff0(iVar9,0,0xffffffff);
            iVar9 = iVar9 + 0x1c;
            local_68 = iVar9;
            if (iVar9 != in_ECX[0x48]) {
              FUN_004020e0(&DAT_009bb848,1);
            }
            if (*(ushort *)(in_ECX + 0x2c) != 0) {
              if (in_ECX[0x53] == 0) {
                uVar10 = 0;
              }
              else {
                uVar10 = in_ECX[0x54] - in_ECX[0x53] >> 2;
              }
              if (*(ushort *)(in_ECX + 0x2c) <= uVar10) break;
            }
          } while (iVar9 != in_ECX[0x48]);
        }
        FUN_0043b3d0(local_50);
        _Memory = local_4c;
        pvVar8 = local_5c;
        if (local_5c != (void *)0x0) {
          FUN_00405de0(local_5c,local_58,local_60,local_64);
          _free(pvVar8);
          return;
        }
        if (local_4c != (void *)0x0) {
          FUN_00405de0(local_4c,local_48,local_50,local_64);
          _free(_Memory);
          return;
        }
      }
    }
    else {
      FUN_0043b3d0(in_ECX + 0x46);
    }
    if (in_ECX[0x4b] == 0) {
      uVar10 = 0;
    }
    else {
      uVar10 = (in_ECX[0x4c] - in_ECX[0x4b]) / 0x1c;
    }
    in_ECX[0x42] = 0;
    uVar7 = uVar10;
    if ((char)in_ECX[0x5e] == '\x01') {
      if (in_ECX[0x4f] == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = in_ECX[0x50] - in_ECX[0x4f] >> 2;
      }
      uVar7 = iVar9 + uVar10;
    }
    if ((uint)in_ECX[0x41] < uVar7) {
      in_ECX[0x42] = uVar7 - in_ECX[0x41];
    }
    if ((int *)in_ECX[0x1c] == (int *)0x0) {
      in_ECX[0x43] = 0;
    }
    else {
      iVar9 = in_ECX[0x42];
      (**(code **)(*(int *)in_ECX[0x1c] + 0x30))(iVar9);
      FUN_0055aac0(iVar9);
      if (*(char *)((int)in_ECX + 0x179) == '\0') {
        iVar9 = (**(code **)(*(int *)in_ECX[0x1c] + 0x30))();
        in_ECX[0x43] = *(int *)(iVar9 + 0x88);
      }
      else {
        iVar9 = in_ECX[0x42];
        in_ECX[0x43] = iVar9;
        (**(code **)(*(int *)in_ECX[0x1c] + 0x30))(iVar9);
        FUN_0055ab10(iVar9);
      }
    }
    uVar7 = in_ECX[0x43];
    if (uVar7 + in_ECX[0x41] <= uVar10) {
      uVar10 = uVar7 + in_ECX[0x41];
    }
    if (uVar7 < uVar10) {
      iVar9 = uVar7 * 0x1c;
      do {
        iVar1 = in_ECX[0x4b];
        if ((iVar1 == 0) || ((uint)((in_ECX[0x4c] - iVar1) / 0x1c) <= uVar7)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uVar6 = FUN_00402220(local_50,iVar1 + iVar9,&DAT_009bb84c);
        FUN_00401ff0(uVar6,0,0xffffffff);
        if (0xf < local_38) {
          _free(local_4c);
          return;
        }
        in_ECX[0x40] = in_ECX[0x40] + 1;
        uVar7 = uVar7 + 1;
        iVar9 = iVar9 + 0x1c;
        local_38 = 0xf;
        local_3c = 0;
        local_4c = (void *)((uint)local_4c & 0xffffff00);
      } while (uVar7 < uVar10);
    }
    (**(code **)(*in_ECX + 8))(local_34);
    if (*(char *)((int)in_ECX + 0xa6) == '\x01') {
      FUN_00553430();
    }
    FUN_005530b0();
  }
  if (uStack_18 < 0x10) {
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_00555670 @ 0x00555670 ====

void FUN_00555670(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x11c) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x11c),*(undefined4 *)(in_ECX + 0x120),in_ECX + 0x118);
    _free(*(void **)(in_ECX + 0x11c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  *(undefined4 *)(in_ECX + 0x120) = 0;
  *(undefined4 *)(in_ECX + 0x124) = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_009bb890,1);
  FUN_00405300(in_ECX + 200,local_1c,in_ECX + 0x118);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if ((*(int *)(in_ECX + 0x11c) == 0) ||
     ((uint)((*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c) < 2)) {
    return;
  }
  if (*(void **)(in_ECX + 0x13c) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x13c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x13c) = 0;
  *(undefined4 *)(in_ECX + 0x140) = 0;
  *(undefined4 *)(in_ECX + 0x144) = 0;
  iVar2 = *(int *)(in_ECX + 0x11c);
  if ((iVar2 != 0) && ((*(int *)(in_ECX + 0x120) - iVar2) / 0x1c != 0)) {
    FUN_00401660(iVar2,0,0xffffffff);
    uVar3 = 1;
    iVar2 = 0x1c;
    while( true ) {
      if (*(int *)(in_ECX + 0x11c) == 0) {
        return;
      }
      if ((uint)((*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c) <= uVar3) {
        return;
      }
      iVar1 = *(int *)(in_ECX + 0x11c);
      if ((iVar1 == 0) || ((uint)((*(int *)(in_ECX + 0x120) - iVar1) / 0x1c) <= uVar3)) break;
      FUN_00554930(iVar2 + iVar1);
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x1c;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00405ca0();
}


// ==== FUN_00555800 @ 0x00555800 ====

undefined4 FUN_00555800(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 ****ppppuVar3;
  int iVar4;
  undefined4 extraout_EAX;
  int in_ECX;
  bool bVar5;
  undefined1 auStack_1c [4];
  undefined4 ****local_18 [4];
  undefined4 uStack_8;
  uint local_4;
  
  bVar5 = false;
  if (param_1 == 4) {
    bVar5 = true;
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(s__scroll_009bb85c);
    FUN_00402220(auStack_1c,uVar2);
    ppppuVar3 = local_18[0];
    if (local_4 < 0x10) {
      ppppuVar3 = local_18;
    }
    iVar4 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),ppppuVar3,uStack_8);
    if ((iVar4 == 0) && (bVar1 = true, param_3 == 6)) goto LAB_0055586d;
  }
  bVar1 = false;
LAB_0055586d:
  if ((bVar5) && (0xf < local_4)) {
    _free(local_18[0]);
    return extraout_EAX;
  }
  if (bVar1) {
    *(undefined1 *)(in_ECX + 0x179) = 0;
    FUN_00554fd0();
    return 1;
  }
  return 0;
}


// ==== FUN_005558b0 @ 0x005558b0 ====

void FUN_005558b0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 local_58;
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  undefined1 local_38 [4];
  void *local_34;
  uint local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  FUN_00552fc0(local_38,in_ECX + 0x118,*(undefined4 *)(in_ECX + 0x180));
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(&DAT_009bb92c,0);
  if (*(ushort *)(in_ECX + 0xb0) != 0) {
    if (*(int *)(in_ECX + 300) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (*(int *)(in_ECX + 0x130) - *(int *)(in_ECX + 300)) / 0x1c;
    }
    if (*(ushort *)(in_ECX + 0xb0) <= uVar1) {
      if (0xf < local_3c) {
        _free(local_50);
        return;
      }
      local_3c = 0xf;
      local_40 = 0;
      local_50 = (void *)((uint)local_50 & 0xffffff00);
      if (local_20 < 0x10) {
        return;
      }
      _free(local_34);
      return;
    }
  }
  if (*(int *)(in_ECX + 0x11c) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c;
  }
  if (iVar2 == *(int *)(in_ECX + 0x180)) {
    FUN_00406720(local_54);
  }
  uVar1 = *(uint *)(in_ECX + 0x17c);
  if (uVar1 < local_24) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401660(local_38,uVar1,local_24 - uVar1);
    FUN_00401660(local_1c,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    FUN_00401390(*(undefined4 *)(in_ECX + 0x17c),local_24 - uVar1);
  }
  iVar2 = *(int *)(in_ECX + 0x180);
  *(int *)(in_ECX + 0x180) = iVar2 + 1;
  *(undefined4 *)(in_ECX + 0x17c) = 0;
  FUN_00401660(local_38,0,0xffffffff);
  FUN_00554460(in_ECX + 0x118,iVar2);
  iVar2 = *(int *)(in_ECX + 0x11c);
  for (iVar3 = 0; (iVar2 != *(int *)(in_ECX + 0x120) && (iVar3 != *(int *)(in_ECX + 0x180)));
      iVar3 = iVar3 + 1) {
    iVar2 = iVar2 + 0x1c;
  }
  FUN_004066a0(&local_58,iVar2,local_54);
  if ((*(uint *)(in_ECX + 0x104) <= (*(int *)(in_ECX + 0x188) - *(int *)(in_ECX + 0x10c)) + 1U) &&
     (*(int **)(in_ECX + 0x70) != (int *)0x0)) {
    iVar2 = *(int *)(in_ECX + 0x10c) + 1;
    *(int *)(in_ECX + 0x10c) = iVar2;
    (**(code **)(**(int **)(in_ECX + 0x70) + 0x30))(iVar2);
    FUN_0055ab10(iVar2);
  }
  FUN_00553430();
  if (*(int *)(in_ECX + 300) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 300),*(undefined4 *)(in_ECX + 0x130),in_ECX + 0x128,local_58);
    _free(*(void **)(in_ECX + 300));
    return;
  }
  *(undefined4 *)(in_ECX + 300) = 0;
  *(undefined4 *)(in_ECX + 0x130) = 0;
  *(undefined4 *)(in_ECX + 0x134) = 0;
  FUN_00554fd0();
  if (0xf < local_3c) {
    _free(local_50);
    return;
  }
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  if (local_20 < 0x10) {
    return;
  }
  _free(local_34);
  return;
}


// ==== FUN_00555b50 @ 0x00555b50 ====

undefined4 FUN_00555b50(int param_1)

{
  undefined4 extraout_EAX;
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  int local_24;
  uint local_20;
  undefined1 local_1c [20];
  int local_8;
  
  if (*(char *)(in_ECX + 0xa9) == '\0') {
    if (*(ushort *)(in_ECX + 0xb0) != 0) {
      uVar1 = 0;
      if (*(int *)(in_ECX + 300) != 0) {
        uVar1 = (*(int *)(in_ECX + 0x130) - *(int *)(in_ECX + 300)) / 0x1c;
      }
      if (*(ushort *)(in_ECX + 0xb0) < uVar1) {
        return 1;
      }
    }
    if ((int)(uint)*(ushort *)(in_ECX + 0xdc) < (int)(*(ushort *)(in_ECX + 0xa4) - 2)) {
      uVar1 = 0;
      if (*(int *)(in_ECX + 0x11c) != 0) {
        uVar1 = (*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c;
      }
      if (*(uint *)(in_ECX + 0x180) <= uVar1) {
        FUN_00552fc0(local_1c,in_ECX + 0x118,*(uint *)(in_ECX + 0x180));
        if (*(int *)(in_ECX + 400) != 0) {
          if (local_8 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          FUN_00401390(*(undefined4 *)(in_ECX + 0x17c),*(int *)(in_ECX + 400));
        }
        uVar2 = FUN_005523a0(local_38);
        FUN_00552210(*(undefined4 *)(in_ECX + 0x17c),uVar2,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else {
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      FUN_00401660(param_1 + 4,0,0xffffffff);
      if (0xf < local_20) {
        _free(local_34);
        return extraout_EAX;
      }
      if (local_24 == 0) {
        FUN_00554fd0();
        return 1;
      }
    }
  }
  return 1;
}


// ==== FUN_00555d20 @ 0x00555d20 ====

undefined4 FUN_00555d20(void)

{
  uint uVar1;
  char *pcVar2;
  int in_ECX;
  undefined1 local_38 [20];
  uint local_24;
  undefined1 local_1c [28];
  
  if ((*(char *)(in_ECX + 0xa9) != '\0') ||
     ((int)(*(ushort *)(in_ECX + 0xa4) - 2) < (int)(uint)*(ushort *)(in_ECX + 0xdc))) {
    return 1;
  }
  if (*(ushort *)(in_ECX + 0xb0) != 0) {
    uVar1 = 0;
    if (*(int *)(in_ECX + 300) != 0) {
      uVar1 = (*(int *)(in_ECX + 0x130) - *(int *)(in_ECX + 300)) / 0x1c;
    }
    if (*(ushort *)(in_ECX + 0xb0) < uVar1) {
      return 1;
    }
  }
  FUN_00552fc0(local_1c,in_ECX + 0x118,*(undefined4 *)(in_ECX + 0x180));
  uVar1 = 0;
  if (*(int *)(in_ECX + 0x11c) != 0) {
    uVar1 = (*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c;
  }
  if (uVar1 < *(uint *)(in_ECX + 0x180)) {
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  if (*(int *)(in_ECX + 400) != 0) {
    FUN_00401390(*(undefined4 *)(in_ECX + 0x17c),*(int *)(in_ECX + 400));
  }
  FUN_005523a0(local_38);
  if (1 < local_24) {
    uVar1 = local_24 - 1;
    pcVar2 = (char *)FUN_004d9a40(uVar1);
    if (*pcVar2 == '\\') {
      FUN_00401390(uVar1,1);
      local_24 = uVar1;
    }
  }
  FUN_00552210(*(undefined4 *)(in_ECX + 0x17c),local_38,0,0xffffffff);
  *(undefined4 *)(in_ECX + 400) = 0;
  FUN_00401660(local_1c,0,0xffffffff);
  FUN_00554460(in_ECX + 0x118,*(undefined4 *)(in_ECX + 0x180));
  *(int *)(in_ECX + 0x17c) = *(int *)(in_ECX + 0x17c) + local_24;
  FUN_00406250();
  FUN_00554fd0();
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00555eb0 @ 0x00555eb0 ====

void FUN_00555eb0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_ECX;
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x11c) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c;
  }
  if (*(uint *)(in_ECX + 0x180) < uVar2) {
    iVar3 = FUN_00552fc0(local_1c,in_ECX + 0x118,*(uint *)(in_ECX + 0x180));
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    if (*(int *)(in_ECX + 0x17c) == *(int *)(iVar3 + 0x14)) {
      if (*(int *)(in_ECX + 0x11c) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c;
      }
      if (*(uint *)(in_ECX + 0x180) < iVar3 - 1U) {
        uVar4 = FUN_00405d30(*(uint *)(in_ECX + 0x180) + 1);
        FUN_00405d30(*(undefined4 *)(in_ECX + 0x180));
        FUN_00401ff0(uVar4,0,0xffffffff);
        puVar5 = (undefined4 *)FUN_00552860(local_24,*(int *)(in_ECX + 0x180) + 1);
        FUN_004d5730(&local_20,*puVar5);
      }
    }
    else {
      iVar3 = FUN_00405d30(*(undefined4 *)(in_ECX + 0x180));
      iVar6 = FUN_00552720(*(undefined4 *)(in_ECX + 0x17c),iVar3);
      if (*(uint *)(iVar3 + 0x18) < 0x10) {
        iVar3 = iVar3 + 4;
      }
      else {
        iVar3 = *(int *)(iVar3 + 4);
      }
      cVar1 = FUN_00403d70((int)*(char *)(iVar3 + iVar6));
      iVar3 = (cVar1 != '\0') + 1;
      FUN_00405d30(*(undefined4 *)(in_ECX + 0x180));
      FUN_00401390(iVar6,iVar3);
    }
    if (*(int *)(in_ECX + 300) != 0) {
      FUN_00405de0(*(int *)(in_ECX + 300),*(undefined4 *)(in_ECX + 0x130),in_ECX + 0x128,local_20);
      _free(*(void **)(in_ECX + 300));
      return;
    }
    *(undefined4 *)(in_ECX + 300) = 0;
    *(undefined4 *)(in_ECX + 0x130) = 0;
    *(undefined4 *)(in_ECX + 0x134) = 0;
    FUN_00554fd0();
  }
  return;
}


// ==== FUN_00556050 @ 0x00556050 ====

void FUN_00556050(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_ECX;
  undefined4 uVar7;
  undefined4 uVar8;
  int local_8;
  undefined4 local_4;
  
  if (*(int *)(in_ECX + 0x17c) == 0) {
    if (*(int *)(in_ECX + 0x180) == 0) {
      return;
    }
    if ((*(int *)(in_ECX + 0x10c) == *(int *)(in_ECX + 0x188)) &&
       (*(int **)(in_ECX + 0x70) != (int *)0x0)) {
      iVar3 = *(int *)(in_ECX + 0x10c) + -1;
      *(int *)(in_ECX + 0x10c) = iVar3;
      (**(code **)(**(int **)(in_ECX + 0x70) + 0x30))(iVar3);
      FUN_0055ab10(iVar3);
    }
    *(int *)(in_ECX + 0x180) = *(int *)(in_ECX + 0x180) + -1;
    iVar3 = FUN_00405d30(*(undefined4 *)(in_ECX + 0x180));
    *(undefined4 *)(in_ECX + 0x17c) = *(undefined4 *)(iVar3 + 0x14);
    uVar4 = FUN_00405d30(*(int *)(in_ECX + 0x180) + 1);
    FUN_00405d30(*(undefined4 *)(in_ECX + 0x180));
    FUN_00401ff0(uVar4,0,0xffffffff);
    puVar5 = (undefined4 *)FUN_00552860(&local_8,*(int *)(in_ECX + 0x180) + 1);
    FUN_004d5730(&local_4,*puVar5);
  }
  else {
    iVar3 = *(int *)(in_ECX + 0x11c);
    if ((iVar3 == 0) ||
       ((uint)((*(int *)(in_ECX + 0x120) - iVar3) / 0x1c) <= *(uint *)(in_ECX + 0x180))) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    local_8 = FUN_00552720(*(int *)(in_ECX + 0x17c) + -1,iVar3 + *(uint *)(in_ECX + 0x180) * 0x1c);
    uVar1 = *(uint *)(in_ECX + 0x180);
    *(int *)(in_ECX + 0x17c) = local_8;
    iVar3 = *(int *)(in_ECX + 0x11c);
    if ((iVar3 == 0) || ((uint)((*(int *)(in_ECX + 0x120) - iVar3) / 0x1c) <= uVar1)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    iVar6 = iVar3 + uVar1 * 0x1c;
    if (*(uint *)(iVar3 + 0x18 + uVar1 * 0x1c) < 0x10) {
      iVar6 = iVar6 + 4;
    }
    else {
      iVar6 = *(int *)(iVar6 + 4);
    }
    cVar2 = FUN_00403d70((int)*(char *)(iVar6 + local_8));
    if (cVar2 == '\0') {
      uVar4 = *(undefined4 *)(in_ECX + 0x17c);
      uVar7 = *(undefined4 *)(in_ECX + 0x180);
      uVar8 = 1;
    }
    else {
      uVar4 = *(undefined4 *)(in_ECX + 0x17c);
      uVar7 = *(undefined4 *)(in_ECX + 0x180);
      uVar8 = 2;
    }
    FUN_00405d30(uVar7);
    FUN_00401390(uVar4,uVar8);
  }
  if (*(int *)(in_ECX + 300) == 0) {
    *(undefined4 *)(in_ECX + 300) = 0;
    *(undefined4 *)(in_ECX + 0x130) = 0;
    *(undefined4 *)(in_ECX + 0x134) = 0;
    FUN_00554fd0();
    return;
  }
  FUN_00405de0(*(int *)(in_ECX + 300),*(undefined4 *)(in_ECX + 0x130),in_ECX + 0x128,local_4);
  _free(*(void **)(in_ECX + 300));
  return;
}


// ==== FUN_00556260 @ 0x00556260 ====

void FUN_00556260(void)

{
  uint *puVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  int unaff_ESI;
  uint uVar9;
  bool bVar10;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  puVar1 = (uint *)(in_ECX + 0x180);
  if ((*(int *)(in_ECX + 0x11c) == 0) ||
     ((uint)((*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c) <=
      *(uint *)(in_ECX + 0x180))) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  iVar4 = *(int *)(in_ECX + 0x11c) + *(uint *)(in_ECX + 0x180) * 0x1c;
  (**(code **)(*DAT_00b5a688 + 0x34))(*(undefined4 *)(in_ECX + 0xe4),iVar4,local_4,local_8);
  uVar7 = *(uint *)(in_ECX + 0x188);
  if (iVar4 < 0) {
    uVar8 = *puVar1;
    if (uVar8 == 0) {
      puVar1 = *(uint **)(in_ECX + 0x14c);
      if ((puVar1 == (uint *)0x0) || (*(int *)(in_ECX + 0x150) - (int)puVar1 >> 2 == 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_0042f370();
      }
      if (*puVar1 < 2) {
        return;
      }
      if (uVar7 == 0) {
        return;
      }
      *(int *)(in_ECX + 0x17c) = *(int *)(in_ECX + 0x17c) - *(int *)(in_ECX + 0x184);
      iVar4 = FUN_00405d30(uVar7 - 1);
      uVar8 = *(uint *)(iVar4 + 0x14);
      uVar9 = *(uint *)(in_ECX + 0x184);
      if (uVar8 < *(uint *)(in_ECX + 0x184)) {
        *(undefined1 *)(in_ECX + 0x18c) = 0;
        uVar9 = uVar8;
      }
      *(int *)(in_ECX + 0x17c) = *(int *)(in_ECX + 0x17c) + (uVar9 - uVar8);
      uVar8 = 0;
      bVar10 = false;
      if (uVar9 != 0) {
        do {
          if (*(uint *)(iVar4 + 0x14) <= uVar8) {
            FUN_0079dba3();
          }
          if (*(uint *)(iVar4 + 0x18) < 0x10) {
            iVar5 = iVar4 + 4;
          }
          else {
            iVar5 = *(int *)(iVar4 + 4);
          }
          cVar3 = FUN_00403d70((int)*(char *)(iVar5 + uVar8));
          if (cVar3 != '\0') {
            bVar10 = (bool)(bVar10 ^ 1);
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < uVar9);
      }
      bVar10 = !bVar10;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x14c);
      if ((iVar4 == 0) || ((uint)(*(int *)(in_ECX + 0x150) - iVar4 >> 2) <= uVar8)) {
                    /* WARNING: Subroutine does not return */
        FUN_0042f370();
      }
      if (*(uint *)(iVar4 + uVar8 * 4) < 2) {
        uVar8 = uVar8 - 1;
        *puVar1 = uVar8;
        iVar4 = *(int *)(in_ECX + 0x14c);
        if ((iVar4 == 0) || ((uint)(*(int *)(in_ECX + 0x150) - iVar4 >> 2) <= uVar8)) {
                    /* WARNING: Subroutine does not return */
          FUN_0042f370();
        }
        if (*(uint *)(iVar4 + uVar8 * 4) < 2) {
          iVar4 = FUN_00405d30(uVar8);
          if (*(uint *)(iVar4 + 0x14) <= *(uint *)(in_ECX + 0x184)) goto LAB_0055654f;
          *(uint *)(in_ECX + 0x17c) = *(uint *)(in_ECX + 0x184);
          iVar4 = FUN_00405d30(*(int *)(in_ECX + 0x188) + -1);
          uVar8 = 0;
          bVar10 = false;
          if (*(int *)(in_ECX + 0x184) != 0) {
            do {
              if (*(uint *)(iVar4 + 0x14) <= uVar8) {
                FUN_0079dba3();
              }
              if (*(uint *)(iVar4 + 0x18) < 0x10) {
                iVar5 = iVar4 + 4;
              }
              else {
                iVar5 = *(int *)(iVar4 + 4);
              }
              cVar3 = FUN_00403d70((int)*(char *)(iVar5 + uVar8));
              if (cVar3 != '\0') {
                bVar10 = (bool)(bVar10 ^ 1);
              }
              uVar8 = uVar8 + 1;
            } while (uVar8 < *(uint *)(in_ECX + 0x184));
          }
        }
        else {
          iVar4 = FUN_00405d30(uVar7 - 1);
          uVar8 = *(uint *)(iVar4 + 0x14);
          if (uVar8 <= *(uint *)(in_ECX + 0x184)) {
LAB_0055654f:
            iVar4 = FUN_00405d30(*puVar1);
            uVar7 = uVar7 - 1;
            *(undefined4 *)(in_ECX + 0x17c) = *(undefined4 *)(iVar4 + 0x14);
            goto LAB_0055698f;
          }
          iVar5 = FUN_00405d30(*puVar1);
          bVar10 = false;
          uVar9 = 0;
          *(uint *)(in_ECX + 0x17c) = (*(int *)(iVar5 + 0x14) - uVar8) + *(int *)(in_ECX + 0x184);
          if (*(int *)(in_ECX + 0x184) != 0) {
            do {
              if (*(uint *)(iVar4 + 0x14) <= uVar9) {
                FUN_0079dba3();
              }
              if (*(uint *)(iVar4 + 0x18) < 0x10) {
                iVar5 = iVar4 + 4;
              }
              else {
                iVar5 = *(int *)(iVar4 + 4);
              }
              cVar3 = FUN_00403d70((int)*(char *)(iVar5 + uVar9));
              if (cVar3 != '\0') {
                bVar10 = (bool)(bVar10 ^ 1);
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < *(uint *)(in_ECX + 0x184));
          }
        }
LAB_00556659:
        bVar10 = !bVar10;
      }
      else {
        iVar5 = FUN_005532e0(puVar1);
        iVar4 = *(int *)(in_ECX + 0x188);
        if (iVar4 == iVar5) {
          *puVar1 = *puVar1 - 1;
          iVar4 = FUN_00405d30(iVar4 + -1);
          uVar8 = *(uint *)(iVar4 + 0x14);
          if (uVar8 <= *(uint *)(in_ECX + 0x184)) goto LAB_0055654f;
          iVar5 = FUN_00405d30(*puVar1);
          bVar10 = false;
          *(uint *)(in_ECX + 0x17c) = (*(int *)(iVar5 + 0x14) - uVar8) + *(int *)(in_ECX + 0x184);
          if (*(int *)(in_ECX + 0x184) != 0) {
            uVar8 = 0;
            do {
              if (*(uint *)(iVar4 + 0x14) <= uVar8) {
                FUN_0079dba3();
              }
              if (*(uint *)(iVar4 + 0x18) < 0x10) {
                iVar5 = iVar4 + 4;
              }
              else {
                iVar5 = *(int *)(iVar4 + 4);
              }
              cVar3 = FUN_00403d70((int)*(char *)(iVar5 + uVar8));
              if (cVar3 != '\0') {
                bVar10 = (bool)(bVar10 ^ 1);
              }
              uVar8 = uVar8 + 1;
            } while (uVar8 < *(uint *)(in_ECX + 0x184));
          }
          goto LAB_00556659;
        }
        *(int *)(in_ECX + 0x17c) = *(int *)(in_ECX + 0x17c) - *(int *)(in_ECX + 0x184);
        iVar4 = FUN_00405d30(iVar4 + -1);
        uVar8 = *(uint *)(iVar4 + 0x14);
        uVar9 = *(uint *)(in_ECX + 0x184);
        if (uVar8 < *(uint *)(in_ECX + 0x184)) {
          *(undefined1 *)(in_ECX + 0x18c) = 0;
          uVar9 = uVar8;
        }
        *(int *)(in_ECX + 0x17c) = *(int *)(in_ECX + 0x17c) + (uVar9 - uVar8);
        uVar8 = 0;
        bVar10 = false;
        if (uVar9 != 0) {
          do {
            if (*(uint *)(iVar4 + 0x14) <= uVar8) {
              FUN_0079dba3();
            }
            if (*(uint *)(iVar4 + 0x18) < 0x10) {
              iVar5 = iVar4 + 4;
            }
            else {
              iVar5 = *(int *)(iVar4 + 4);
            }
            cVar3 = FUN_00403d70((int)*(char *)(iVar5 + uVar8));
            if (cVar3 != '\0') {
              bVar10 = (bool)(bVar10 ^ 1);
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar9);
        }
        bVar10 = !bVar10;
      }
    }
    if (!bVar10) {
      *(int *)(in_ECX + 0x17c) = *(int *)(in_ECX + 0x17c) + 1;
    }
    uVar7 = uVar7 - 1;
  }
  else {
    iVar4 = 0;
    if (*(int *)(in_ECX + 0x11c) != 0) {
      iVar4 = (*(int *)(in_ECX + 0x120) - *(int *)(in_ECX + 0x11c)) / 0x1c;
    }
    if (*puVar1 == iVar4 - 1U) {
      iVar4 = 0;
      if (*(int *)(in_ECX + 300) != 0) {
        iVar4 = (*(int *)(in_ECX + 0x130) - *(int *)(in_ECX + 300)) / 0x1c;
      }
      if (uVar7 == iVar4 - 1U) {
        return;
      }
      iVar4 = *(int *)(in_ECX + 0x15c);
      if ((iVar4 == 0) || ((uint)(*(int *)(in_ECX + 0x160) - iVar4 >> 2) <= uVar7)) {
                    /* WARNING: Subroutine does not return */
        FUN_0042f370();
      }
      uVar8 = *(uint *)(in_ECX + 0x184);
      iVar5 = *(int *)(in_ECX + 0x15c);
      iVar4 = *(int *)(iVar4 + uVar7 * 4) - uVar8;
      uVar7 = uVar7 + 1;
      if ((iVar5 == 0) || ((uint)(*(int *)(in_ECX + 0x160) - iVar5 >> 2) <= uVar7)) {
                    /* WARNING: Subroutine does not return */
        FUN_0042f370();
      }
      uVar9 = *(uint *)(iVar5 + uVar7 * 4);
      if (uVar9 < uVar8) {
        uVar8 = uVar9;
      }
      uVar8 = iVar4 + *(int *)(in_ECX + 0x17c) + uVar8;
      if (uVar8 < *(uint *)(unaff_ESI + 0x14)) {
        bVar10 = false;
        for (uVar9 = *(uint *)(in_ECX + 0x17c); uVar9 < uVar8; uVar9 = uVar9 + 1) {
          if (*(uint *)(unaff_ESI + 0x14) <= uVar9) {
            FUN_0079dba3();
          }
          if (*(uint *)(unaff_ESI + 0x18) < 0x10) {
            iVar4 = unaff_ESI + 4;
          }
          else {
            iVar4 = *(int *)(unaff_ESI + 4);
          }
          cVar3 = FUN_00403d70((int)*(char *)(iVar4 + uVar9));
          if (cVar3 != '\0') {
            bVar10 = (bool)(bVar10 ^ 1);
          }
        }
        if (bVar10) {
          uVar8 = uVar8 + 1;
        }
        *(uint *)(in_ECX + 0x17c) = uVar8;
      }
      else {
        *(uint *)(in_ECX + 0x17c) = *(uint *)(unaff_ESI + 0x14);
      }
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x14c);
      iVar5 = 0;
      uVar8 = 0;
      do {
        if ((iVar4 == 0) || ((uint)(*(int *)(in_ECX + 0x150) - iVar4 >> 2) <= uVar8)) {
                    /* WARNING: Subroutine does not return */
          FUN_0042f370();
        }
        iVar5 = iVar5 + *(int *)(iVar4 + uVar8 * 4);
        uVar8 = uVar8 + 1;
      } while (uVar8 <= *puVar1);
      if (iVar5 == 0) {
        return;
      }
      if (uVar7 == iVar5 - 1U) {
        *puVar1 = *puVar1 + 1;
        iVar4 = FUN_00405d30(uVar7 + 1);
        uVar9 = *(uint *)(iVar4 + 0x14);
        if (uVar9 < *(uint *)(in_ECX + 0x184)) {
          *(uint *)(in_ECX + 0x17c) = uVar9;
        }
        else {
          *(uint *)(in_ECX + 0x17c) = *(uint *)(in_ECX + 0x184);
        }
        if ((*(char *)(in_ECX + 0x18c) == '\0') && (*(int *)(in_ECX + 0x17c) == 0)) {
          *(uint *)(in_ECX + 0x17c) = uVar9;
        }
        if (uVar9 <= *(uint *)(in_ECX + 0x17c)) goto LAB_0055691c;
        uVar8 = 0;
        bVar10 = false;
        if (*(uint *)(in_ECX + 0x17c) != 0) {
          do {
            if (*(uint *)(iVar4 + 0x14) <= uVar8) {
              FUN_0079dba3();
            }
            if (*(uint *)(iVar4 + 0x18) < 0x10) {
              puVar6 = (undefined4 *)(iVar4 + 4);
            }
            else {
              puVar6 = *(undefined4 **)(iVar4 + 4);
            }
            cVar3 = FUN_00403d70((int)*(char *)((int)puVar6 + uVar8));
            if (cVar3 != '\0') {
              bVar10 = (bool)(bVar10 ^ 1);
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < *(uint *)(in_ECX + 0x17c));
        }
        if (bVar10) {
          *(int *)(in_ECX + 0x17c) = *(int *)(in_ECX + 0x17c) + 1;
        }
      }
      else {
        iVar4 = *(int *)(in_ECX + 0x15c);
        if ((iVar4 == 0) || ((uint)(*(int *)(in_ECX + 0x160) - iVar4 >> 2) <= uVar7)) {
                    /* WARNING: Subroutine does not return */
          FUN_0042f370();
        }
        uVar8 = *(uint *)(in_ECX + 0x184);
        iVar5 = *(int *)(in_ECX + 0x15c);
        iVar4 = *(int *)(iVar4 + uVar7 * 4) - uVar8;
        if ((iVar5 == 0) || ((uint)(*(int *)(in_ECX + 0x160) - iVar5 >> 2) <= uVar7 + 1)) {
                    /* WARNING: Subroutine does not return */
          FUN_0042f370();
        }
        uVar9 = *(uint *)(iVar5 + (uVar7 + 1) * 4);
        if (uVar9 < uVar8) {
          uVar8 = uVar9;
        }
        uVar8 = iVar4 + *(int *)(in_ECX + 0x17c) + uVar8;
        uVar9 = *(uint *)(unaff_ESI + 0x14);
        if (uVar8 < uVar9) {
          bVar2 = 0;
          for (uVar9 = *(uint *)(in_ECX + 0x17c); uVar9 < uVar8; uVar9 = uVar9 + 1) {
            if (*(uint *)(unaff_ESI + 0x14) <= uVar9) {
              FUN_0079dba3();
            }
            if (*(uint *)(unaff_ESI + 0x18) < 0x10) {
              iVar4 = unaff_ESI + 4;
            }
            else {
              iVar4 = *(int *)(unaff_ESI + 4);
            }
            cVar3 = FUN_00403d70((int)*(char *)(iVar4 + uVar9));
            if (cVar3 != '\0') {
              bVar2 = bVar2 + 1;
            }
          }
          *(uint *)(in_ECX + 0x17c) = uVar8;
          if ((bool)(bVar2 & 1)) {
            *(uint *)(in_ECX + 0x17c) = uVar8 + 1;
          }
        }
        else {
LAB_0055691c:
          *(uint *)(in_ECX + 0x17c) = uVar9;
        }
      }
      uVar7 = uVar7 + 1;
    }
  }
LAB_0055698f:
  uVar8 = *(uint *)(in_ECX + 0x10c);
  if ((uVar7 < *(int *)(in_ECX + 0x104) + uVar8) || (*(int **)(in_ECX + 0x70) == (int *)0x0)) {
    if ((uVar8 <= uVar7) || (*(int **)(in_ECX + 0x70) == (int *)0x0)) goto LAB_005569da;
    iVar4 = uVar8 - 1;
    *(int *)(in_ECX + 0x10c) = iVar4;
    (**(code **)(**(int **)(in_ECX + 0x70) + 0x30))(iVar4);
  }
  else {
    iVar4 = uVar8 + 1;
    *(int *)(in_ECX + 0x10c) = iVar4;
    (**(code **)(**(int **)(in_ECX + 0x70) + 0x30))(iVar4);
  }
  FUN_0055ab10(iVar4);
LAB_005569da:
  FUN_00554fd0();
  return;
}


// ==== FUN_005569f0 @ 0x005569f0 ====

void FUN_005569f0(int param_1,undefined1 param_2)

{
  uint *puVar1;
  uint *_Memory;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *****pppppuVar6;
  undefined4 uVar7;
  int iVar8;
  int *in_ECX;
  undefined4 *****pppppuVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint uStack_118;
  int local_114;
  uint uStack_110;
  uint uStack_10c;
  int iStack_108;
  undefined1 auStack_104 [4];
  undefined4 *****apppppuStack_100 [4];
  uint uStack_f0;
  uint uStack_ec;
  undefined1 local_e8 [4];
  void *local_e4;
  undefined4 local_d4;
  uint local_d0;
  uint *puStack_c8;
  uint *puStack_c4;
  undefined4 uStack_c0;
  uint local_bc;
  uint uStack_b8;
  undefined1 auStack_b4 [4];
  undefined4 *****apppppuStack_b0 [4];
  int iStack_a0;
  uint uStack_9c;
  uint uStack_98;
  int iStack_94;
  undefined1 auStack_90 [4];
  undefined4 *****apppppuStack_8c [4];
  int iStack_7c;
  uint uStack_78;
  undefined1 auStack_74 [4];
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  FUN_00552a40();
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x5e) = param_2;
  if ((uint)*(ushort *)(in_ECX + 0x29) < *(uint *)(param_1 + 0x14)) {
    local_d0 = 0xf;
    local_d4 = 0;
    local_e4 = (void *)((uint)local_e4 & 0xffffff00);
    FUN_00401660(param_1,0,(uint)*(ushort *)(in_ECX + 0x29));
    FUN_00401660(local_e8,0,0xffffffff);
    if (0xf < local_d0) {
      _free(local_e4);
      return;
    }
  }
  else {
    FUN_00401660(param_1,0,0xffffffff);
  }
  if ((char)in_ECX[0x5e] != '\0') {
    FUN_00555670();
  }
  if (in_ECX[0x47] != 0) {
    FUN_00405de0(in_ECX[0x47],in_ECX[0x48],in_ECX + 0x46,local_bc);
    _free((void *)in_ECX[0x47]);
    return;
  }
  in_ECX[0x47] = 0;
  in_ECX[0x48] = 0;
  in_ECX[0x49] = 0;
  local_d0 = 0xf;
  local_d4 = 0;
  local_e4 = (void *)((uint)local_e4 & 0xffffff00);
  FUN_00401740(&DAT_009bb864,1);
  FUN_00405300(in_ECX + 0x32,local_e8,in_ECX + 0x46);
  if (0xf < local_d0) {
    _free(local_e4);
    return;
  }
  if ((*(char *)((int)in_ECX + 0xa6) != '\0') || (*(char *)((int)in_ECX + 0xa7) == '\0')) {
LAB_00557339:
    if (*(char *)((int)in_ECX + 0xa6) == '\x01') {
      if ((in_ECX[0x47] == 0) || (local_114 = (in_ECX[0x48] - in_ECX[0x47]) / 0x1c, local_114 == 0))
      {
        in_ECX[0x60] = 0;
        in_ECX[0x5f] = 0;
        local_d0 = 0xf;
        local_d4 = 0;
        local_e4 = (void *)((uint)local_e4 & 0xffffff00);
        FUN_00401740(&DAT_009bb86a,0);
        FUN_00406720(local_e8);
        if (0xf < local_d0) {
          _free(local_e4);
          return;
        }
      }
      else {
        if (in_ECX[0x47] == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = (in_ECX[0x48] - in_ECX[0x47]) / 0x1c;
        }
        uVar12 = iVar4 - 1;
        in_ECX[0x60] = uVar12;
        iVar4 = in_ECX[0x47];
        if ((iVar4 == 0) || ((uint)((in_ECX[0x48] - iVar4) / 0x1c) <= uVar12)) {
LAB_005573c8:
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        in_ECX[0x5f] = *(int *)(iVar4 + 0x14 + uVar12 * 0x1c);
      }
    }
    if (in_ECX[0x4b] == 0) {
      in_ECX[0x4b] = 0;
      in_ECX[0x4c] = 0;
      in_ECX[0x4d] = 0;
      FUN_00554fd0();
      return;
    }
    FUN_00405de0(in_ECX[0x4b],in_ECX[0x4c],in_ECX + 0x4a,local_114);
    _free((void *)in_ECX[0x4b]);
    return;
  }
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  iVar4 = (**(code **)(*piVar3 + 0x14))();
  uStack_10c = 0;
  uStack_98 = ((*(int *)(iVar4 + 0x10) - (uint)*(ushort *)((int)in_ECX + 0xb2)) - in_ECX[0x24]) -
              *(int *)(iVar4 + 8);
  do {
    uVar12 = 0;
    if (in_ECX[0x47] != 0) {
      uVar12 = (in_ECX[0x48] - in_ECX[0x47]) / 0x1c;
    }
    uVar10 = uStack_10c & 0xffff;
    local_bc = uVar10;
    if (uVar12 <= uVar10) goto LAB_00557339;
    iVar4 = in_ECX[0x47];
    if ((iVar4 == 0) || ((uint)((in_ECX[0x48] - iVar4) / 0x1c) <= uVar10)) goto LAB_005573c8;
    (**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x39],iVar4 + uVar10 * 0x1c,&uStack_b8,auStack_74);
    if (uStack_98 <= uStack_b8) {
      iVar4 = in_ECX[0x47];
      puStack_c8 = (uint *)0x0;
      puStack_c4 = (uint *)0x0;
      uStack_c0 = 0;
      if ((iVar4 == 0) || ((uint)((in_ECX[0x48] - iVar4) / 0x1c) <= uVar10)) goto LAB_005573c8;
      uStack_ec = 0xf;
      uStack_f0 = 0;
      apppppuStack_100[0] = (undefined4 *****)((uint)apppppuStack_100[0] & 0xffffff00);
      FUN_00401660(iVar4 + uVar10 * 0x1c,0,0xffffffff);
      iStack_94 = in_ECX[0x39];
      uStack_118 = 0;
      iStack_108 = 1;
      uStack_78 = 0xf;
      iStack_7c = 0;
      apppppuStack_8c[0] = (undefined4 *****)((uint)apppppuStack_8c[0] & 0xffffff00);
      uStack_9c = 0xf;
      iStack_a0 = 0;
      apppppuStack_b0[0] = (undefined4 *****)((uint)apppppuStack_b0[0] & 0xffffff00);
      uStack_110 = 0;
      if (uStack_f0 != 0) {
        do {
          uVar12 = uStack_110;
          uVar10 = uStack_110 & 0xffff;
          if (uStack_f0 <= uVar10) {
            FUN_0079dba3();
          }
          pppppuVar6 = apppppuStack_100[0];
          if (uStack_ec < 0x10) {
            pppppuVar6 = apppppuStack_100;
          }
          if (*(char *)((int)pppppuVar6 + uVar10) == '<') {
            cVar2 = FUN_00552960(&iStack_94,&local_bc,auStack_104,&uStack_110);
            if (cVar2 != '\x01') {
              uVar12 = uStack_110;
              goto LAB_00556d24;
            }
          }
          else {
LAB_00556d24:
            uVar12 = uVar12 & 0xffff;
            if (uVar12 < uStack_f0) {
              pppppuVar6 = apppppuStack_100[0];
              if (uStack_ec < 0x10) {
                pppppuVar6 = apppppuStack_100;
              }
              cVar2 = FUN_00403d70((int)*(char *)((int)pppppuVar6 + uVar12));
              iStack_108 = 2;
              if (cVar2 != '\x01') goto LAB_00556d54;
            }
            else {
LAB_00556d54:
              iStack_108 = 1;
            }
            iVar4 = iStack_108;
            uStack_20 = 0xf;
            uStack_24 = 0;
            pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
            FUN_00401660(auStack_104,uVar12,iStack_108);
            FUN_00401ff0(auStack_38,0,0xffffffff);
            if (0xf < uStack_20) {
              _free(pvStack_34);
              return;
            }
            uStack_20 = 0xf;
            uStack_24 = 0;
            pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
            (**(code **)(*DAT_00b5a688 + 0x34))(iStack_94,auStack_90,&uStack_b8,auStack_74);
            if (uStack_98 <= uStack_b8) {
              iVar5 = (**(code **)(*DAT_00b5a6b0 + 8))();
              if (iVar5 == 3) {
                uVar10 = uVar12 + iVar4;
                if (uVar10 < uStack_f0) {
                  if (uStack_f0 <= uVar12) {
                    FUN_0079dba3();
                  }
                  pppppuVar6 = apppppuStack_100[0];
                  if (uStack_ec < 0x10) {
                    pppppuVar6 = apppppuStack_100;
                  }
                  cVar2 = *(char *)((int)pppppuVar6 + uVar12);
                  if (uStack_f0 <= uVar10) {
                    FUN_0079dba3();
                  }
                  pppppuVar6 = apppppuStack_100[0];
                  if (uStack_ec < 0x10) {
                    pppppuVar6 = apppppuStack_100;
                  }
                  if ((((cVar2 != '\t') && (cVar2 != ' ')) &&
                      (*(char *)((int)pppppuVar6 + uVar10) != '\t')) &&
                     (*(char *)((int)pppppuVar6 + uVar10) != ' ')) {
                    FUN_00403810(&DAT_009bb868);
                    goto LAB_00556f08;
                  }
                  pppppuVar6 = apppppuStack_b0[0];
                  if (uStack_9c < 0x10) {
                    pppppuVar6 = apppppuStack_b0;
                  }
                  iVar5 = (int)pppppuVar6 + iStack_a0;
                  pppppuVar6 = apppppuStack_b0[0];
                  if (uStack_9c < 0x10) {
                    pppppuVar6 = apppppuStack_b0;
                  }
                }
                else {
                  pppppuVar6 = apppppuStack_b0[0];
                  if (uStack_9c < 0x10) {
                    pppppuVar6 = apppppuStack_b0;
                  }
                  iVar5 = (int)pppppuVar6 + iStack_a0;
                  pppppuVar6 = apppppuStack_b0[0];
                  if (uStack_9c < 0x10) {
                    pppppuVar6 = apppppuStack_b0;
                  }
                }
                FUN_004bdb30(&local_114,pppppuVar6,iVar5);
              }
LAB_00556f08:
              iVar4 = uVar12 + iVar4;
              uStack_3c = 0xf;
              uStack_40 = 0;
              pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
              FUN_00401660(auStack_104,uStack_118,iVar4 - uStack_118);
              uVar7 = FUN_00405bd0(auStack_1c,auStack_54,auStack_b4);
              FUN_004066a0(&local_114,puStack_c8,uVar7);
              if (0xf < uStack_4) {
                _free(pvStack_18);
                return;
              }
              uStack_4 = 0xf;
              uStack_8 = 0;
              pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
              pppppuVar6 = apppppuStack_8c[0];
              if (uStack_78 < 0x10) {
                pppppuVar6 = apppppuStack_8c;
              }
              pppppuVar9 = apppppuStack_8c[0];
              if (uStack_78 < 0x10) {
                pppppuVar9 = apppppuStack_8c;
              }
              FUN_004bdb30(&local_114,pppppuVar9,(int)pppppuVar6 + iStack_7c);
              if (0xf < uStack_3c) {
                _free(pvStack_50);
                return;
              }
              uStack_3c = 0xf;
              uStack_40 = 0;
              pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
              uStack_118 = iVar4;
            }
          }
          uStack_110 = uStack_110 + iStack_108;
        } while ((uStack_110 & 0xffff) < uStack_f0);
      }
      local_d0 = 0xf;
      local_d4 = 0;
      local_e4 = (void *)((uint)local_e4 & 0xffffff00);
      FUN_00401660(auStack_104,uStack_118,(uStack_110 & 0xffff) - uStack_118);
      FUN_004066a0(&local_114,puStack_c8,local_e8);
      iVar4 = in_ECX[0x48];
      iVar5 = local_bc * 0x1c;
      iVar8 = in_ECX[0x47] + iVar5;
      while (iVar8 = iVar8 + 0x1c, iVar8 != iVar4) {
        FUN_00401660(iVar8,0,0xffffffff);
      }
      FUN_00405de0(in_ECX[0x48] + -0x1c,in_ECX[0x48],in_ECX + 0x46,local_114);
      _Memory = puStack_c8;
      in_ECX[0x48] = in_ECX[0x48] + -0x1c;
      uStack_118 = 0;
      while( true ) {
        if (_Memory == (uint *)0x0) {
          uVar12 = 0;
        }
        else {
          uVar12 = ((int)puStack_c4 - (int)_Memory) / 0x1c;
        }
        uVar10 = uStack_118 & 0xffff;
        if (uVar12 <= uVar10) break;
        if ((_Memory == (uint *)0x0) || ((uint)(((int)puStack_c4 - (int)_Memory) / 0x1c) <= uVar10))
        {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        uStack_58 = 0xf;
        uStack_5c = 0;
        pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
        FUN_00401660(_Memory + uVar10 * 7,0,0xffffffff);
        FUN_004062c0(in_ECX[0x47] + iVar5,1,auStack_70);
        if (0xf < uStack_58) {
          _free(pvStack_6c);
          return;
        }
        uStack_118 = uStack_118 + 1;
        uStack_58 = 0xf;
        uStack_5c = 0;
        pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
      }
      if (_Memory == (uint *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = ((int)puStack_c4 - (int)_Memory) / 0x1c;
      }
      uStack_10c = (uStack_10c - 1) + iVar4;
      if (0xf < local_d0) {
        _free(local_e4);
        return;
      }
      local_d0 = 0xf;
      local_d4 = 0;
      local_e4 = (void *)((uint)local_e4 & 0xffffff00);
      if (0xf < uStack_9c) {
        _free(apppppuStack_b0[0]);
        return;
      }
      uStack_9c = 0xf;
      iStack_a0 = 0;
      apppppuStack_b0[0] = (undefined4 *****)((uint)apppppuStack_b0[0] & 0xffffff00);
      if (0xf < uStack_78) {
        _free(apppppuStack_8c[0]);
        return;
      }
      uStack_78 = 0xf;
      iStack_7c = 0;
      apppppuStack_8c[0] = (undefined4 *****)((uint)apppppuStack_8c[0] & 0xffffff00);
      if (0xf < uStack_ec) {
        _free(apppppuStack_100[0]);
        return;
      }
      uStack_ec = 0xf;
      uStack_f0 = 0;
      apppppuStack_100[0] = (undefined4 *****)((uint)apppppuStack_100[0] & 0xffffff00);
      if (_Memory != (uint *)0x0) {
        if (_Memory != puStack_c4) {
          puVar11 = _Memory + 6;
          do {
            if (0xf < *puVar11) {
              _free((void *)puVar11[-5]);
              return;
            }
            *puVar11 = 0xf;
            puVar11[-1] = 0;
            *(undefined1 *)(puVar11 + -5) = 0;
            puVar1 = puVar11 + 1;
            puVar11 = puVar11 + 7;
          } while (puVar1 != puStack_c4);
        }
        _free(_Memory);
        return;
      }
      puStack_c8 = (uint *)0x0;
      puStack_c4 = (uint *)0x0;
      uStack_c0 = 0;
    }
    uStack_10c = uStack_10c + 1;
  } while( true );
}


// ==== FUN_00557490 @ 0x00557490 ====

bool FUN_00557490(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int *in_ECX;
  
  piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if ((piVar3 == (int *)0x0) || (cVar2 = (**(code **)(*piVar3 + 100))(), cVar2 == '\0')) {
    return false;
  }
  iVar1 = in_ECX[99];
  *(undefined1 *)(in_ECX + 99) = 0;
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0xd:
    piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
    pcVar4 = (char *)(**(code **)(*piVar3 + 0x10))();
    if (*pcVar4 != '\0') {
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(4,0);
      return true;
    }
    break;
  case 0x20:
  case 0xbf:
  case 0xdc:
    return true;
  case 0x23:
    puVar5 = (undefined4 *)FUN_00430610(in_ECX[0x62]);
    FUN_005533c0(in_ECX[0x62],*puVar5);
    FUN_00553430();
    return true;
  case 0x24:
    FUN_005533c0(in_ECX[0x62],0);
    *(undefined1 *)(in_ECX + 99) = 1;
    FUN_00553430();
    FUN_004ab730();
    FUN_00554fd0();
    return true;
  case 0x25:
    *(undefined1 *)(in_ECX + 99) = 1;
    FUN_00553770(0xffffffff);
    return true;
  case 0x26:
    *(char *)(in_ECX + 99) = (char)iVar1;
    FUN_00556260(0xffffffff);
    return true;
  case 0x27:
    *(undefined1 *)(in_ECX + 99) = 1;
    FUN_00553770(1);
    return true;
  case 0x28:
    *(char *)(in_ECX + 99) = (char)iVar1;
    FUN_00556260(1);
    return true;
  case 0x2d:
    *(ushort *)((int)in_ECX + 0x18e) = (ushort)(*(short *)((int)in_ECX + 0x18e) == 0);
    return true;
  case 0x2e:
    FUN_00555eb0();
    return true;
  }
  cVar2 = FUN_00403d90(*(undefined4 *)(param_1 + 4));
  return cVar2 == '\x01';
}


// ==== FUN_00557710 @ 0x00557710 ====

undefined1 FUN_00557710(int param_1)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  char *pcVar8;
  uint *puVar9;
  uint uVar10;
  int *in_ECX;
  undefined1 auStack_48 [4];
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [20];
  int iStack_24;
  undefined1 uStack_18;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
  if ((piVar4 == (int *)0x0) || (cVar3 = (**(code **)(*piVar4 + 100))(), cVar3 == '\0')) {
    return 0;
  }
  iVar2 = *(int *)(param_1 + 4);
  in_ECX[100] = 0;
  if (iVar2 != 0x5c) {
    if (iVar2 == 8) {
      FUN_00556050();
      return 1;
    }
    if (iVar2 == 0xd) {
      if ((uint)in_ECX[0x37] < (uint)*(ushort *)(in_ECX + 0x29)) {
        FUN_005558b0();
        return 1;
      }
    }
    else {
      if ((char)in_ECX[0x67] != '\0') {
        *(undefined1 *)(in_ECX + 0x67) = 0;
        return 1;
      }
      cVar3 = FUN_00403d70(iVar2);
      if (cVar3 == '\x01') {
        *(undefined1 *)(in_ECX + 0x67) = 1;
        return 1;
      }
      if ((iVar2 == 0x22) && (iVar5 = FUN_00405d30(in_ECX[0x60]), *(int *)(iVar5 + 0x14) == 0)) {
        piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
        cVar3 = (**(code **)(*piVar4 + 0x80))(0xc,0);
        if (cVar3 != '\0') {
          return 1;
        }
      }
      cVar3 = FUN_00403d90(iVar2);
      if ((cVar3 == '\0') && (iVar2 != 0x20)) {
        return 0;
      }
      if (((((*(char *)((int)in_ECX + 0xa9) != '\x01') ||
            (cVar3 = FUN_00403d10(iVar2), cVar3 != '\0')) &&
           ((*(char *)((int)in_ECX + 0xa9) != '\x02' ||
            ((cVar3 = FUN_00403d30(iVar2), cVar3 != '\0' || (iVar2 == 0x2e)))))) &&
          ((*(char *)((int)in_ECX + 0xa9) != '\x03' ||
           ((cVar3 = FUN_00403d50(iVar2), cVar3 != '\0' || (iVar2 == 0x2e)))))) &&
         (((uint)in_ECX[0x37] < (uint)*(ushort *)(in_ECX + 0x29) &&
          ((uVar1 = *(ushort *)(in_ECX + 0x2c), uVar1 == 0 ||
           (uVar6 = FUN_00405820(), uVar6 <= uVar1)))))) {
        uVar7 = FUN_00405d30(in_ECX[0x60]);
        FUN_00765c50(uVar7);
        if ((iStack_24 == 0) || (iVar5 = in_ECX[0x5f], iVar5 == iStack_24)) {
          FUN_00557d70(iVar2);
          uVar6 = 0;
          cVar3 = FUN_004ab730();
          if (cVar3 == '\0') {
            puVar9 = (uint *)FUN_00430610(in_ECX[0x60]);
            uVar6 = *puVar9;
          }
          uStack_44 = 0;
          uStack_40 = 0;
          uStack_3c = 0;
          FUN_00554d00(auStack_38,auStack_48);
          uVar10 = FUN_00405820();
          if (((uVar6 < uVar10) && ((int *)in_ECX[0x1c] != (int *)0x0)) &&
             ((uint)in_ECX[0x41] <= (in_ECX[0x62] - in_ECX[0x43]) + 1U)) {
            iVar5 = in_ECX[0x43] + 1;
            in_ECX[0x43] = iVar5;
            (**(code **)(*(int *)in_ECX[0x1c] + 0x30))(iVar5);
            FUN_0055ab10(iVar5);
          }
          FUN_00406250();
        }
        else if ((*(short *)((int)in_ECX + 0x18e) == 0) || (iVar2 == 0x20)) {
          FUN_00557c50(iVar5,1,iVar2);
        }
        else {
          pcVar8 = (char *)FUN_0043fec0(iVar5);
          cVar3 = FUN_00403d70((int)*pcVar8);
          FUN_00401390(in_ECX[0x5f],(cVar3 != '\0') + '\x01');
          FUN_00557c50(in_ECX[0x5f],1,iVar2);
        }
        uStack_4 = 0xf;
        uStack_8 = 0;
        uStack_18 = 0;
        FUN_00557d70(iVar2);
        FUN_00405d30(in_ECX[0x60]);
        FUN_00401660(auStack_38,0,0xffffffff);
        in_ECX[0x5f] = in_ECX[0x5f] + 1;
        FUN_00406250();
        FUN_00554fd0();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  return 1;
}


// ==== FUN_00557a50 @ 0x00557a50 ====

undefined4 FUN_00557a50(int *param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x40) != 0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0x10))(param_1), cVar1 != '\0')) {
    return 1;
  }
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 < 0x20004) {
    if (uVar2 == 0x20003) {
      if ((*(char *)(in_ECX + 0xa6) != '\0') && (cVar1 = FUN_00557710(param_1), cVar1 != '\0')) {
        return 1;
      }
    }
    else if (uVar2 == 0x10001) {
      cVar1 = FUN_00553d00(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if (uVar2 == 0x10010) {
      cVar1 = FUN_00552b90(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if (((uVar2 == 0x20001) && (*(char *)(in_ECX + 0xa6) != '\0')) &&
            (cVar1 = FUN_00557490(param_1), cVar1 != '\0')) {
      return 1;
    }
  }
  else if (uVar2 == 0x20005) {
    if ((*(char *)(in_ECX + 0xa6) != '\0') && (cVar1 = FUN_00555b50(param_1), cVar1 != '\0')) {
      return 1;
    }
  }
  else if (((uVar2 == 0x20006) && (*(char *)(in_ECX + 0xa6) != '\0')) &&
          (cVar1 = FUN_00555d20(param_1), cVar1 != '\0')) {
    return 1;
  }
  return 0;
}


// ==== FUN_00557b50 @ 0x00557b50 ====

undefined4 FUN_00557b50(int *param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_1 != (int *)0x0) {
    cVar1 = (**(code **)(*in_ECX + 0x74))(param_1);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*param_1 + 0x78))();
      if (cVar1 != '\0') {
        iVar2 = (**(code **)(*param_1 + 0x38))();
        in_ECX[1] = iVar2;
        return 1;
      }
      (**(code **)(*in_ECX + 0x74))(0);
    }
  }
  return 0;
}


// ==== FUN_00557ba0 @ 0x00557ba0 ====

void FUN_00557ba0(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_3;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00403620(param_1,param_2,param_3,(int)pcVar2 - (int)(param_3 + 1));
  return;
}


// ==== FUN_00557be0 @ 0x00557be0 ====

void FUN_00557be0(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x45) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x45) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_00557c50 @ 0x00557c50 ====

void FUN_00557c50(uint param_1,uint param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  int in_ECX;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  if (*(uint *)(in_ECX + 0x14) < param_1) {
    FUN_0079dba3();
  }
  if (-*(int *)(in_ECX + 0x14) - 1U <= param_2) {
    FUN_0079dbe3();
  }
  if (param_2 != 0) {
    uVar5 = *(int *)(in_ECX + 0x14) + param_2;
    if (uVar5 == 0xffffffff) {
      FUN_0079dbe3();
    }
    if (*(uint *)(in_ECX + 0x18) < uVar5) {
      FUN_00401410(uVar5,*(undefined4 *)(in_ECX + 0x14));
    }
    else if (uVar5 == 0) {
      *(undefined4 *)(in_ECX + 0x14) = 0;
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        *(undefined1 *)(in_ECX + 4) = 0;
        return;
      }
      **(undefined1 **)(in_ECX + 4) = 0;
      return;
    }
    if (uVar5 != 0) {
      puVar4 = (undefined4 *)(in_ECX + 4);
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        puVar1 = puVar4;
        puVar3 = puVar4;
      }
      else {
        puVar1 = (undefined4 *)*puVar4;
        puVar3 = (undefined4 *)*puVar4;
      }
      _memmove((void *)((int)puVar1 + param_2 + param_1),(void *)((int)puVar3 + param_1),
               *(int *)(in_ECX + 0x14) - param_1);
      if (*(uint *)(in_ECX + 0x18) < 0x10) {
        puVar3 = puVar4;
      }
      else {
        puVar3 = (undefined4 *)*puVar4;
      }
      puVar3 = (undefined4 *)((int)puVar3 + param_1);
      for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar3 = CONCAT22(CONCAT11(param_3,param_3),CONCAT11(param_3,param_3));
        puVar3 = puVar3 + 1;
      }
      for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
        *(undefined1 *)puVar3 = param_3;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
      *(uint *)(in_ECX + 0x14) = uVar5;
      if (0xf < *(uint *)(in_ECX + 0x18)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      *(undefined1 *)(uVar5 + (int)puVar4) = 0;
    }
  }
  return;
}


// ==== FUN_00557d70 @ 0x00557d70 ====

void FUN_00557d70(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)(in_ECX + 4);
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    puVar3 = puVar2;
  }
  else {
    puVar3 = (undefined4 *)*puVar2;
  }
  iVar1 = *(int *)(in_ECX + 0x14) + (int)puVar3;
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    puVar2 = (undefined4 *)*puVar2;
  }
  if (iVar1 == 0) {
    FUN_00557c50(0,1,param_1);
    return;
  }
  FUN_00557c50(iVar1 - (int)puVar2,1,param_1);
  return;
}


// ==== FUN_00557dc0 @ 0x00557dc0 ====

void FUN_00557dc0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981f50;
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


// ==== Catch@00557f21 @ 0x00557f21 ====

void Catch_00557f21(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00558010 @ 0x00558010 ====

void FUN_00558010(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_00557dc0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_00558060 @ 0x00558060 ====

void FUN_00558060(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(iVar1 + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(iVar1 + 0x24);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(iVar1 + 0x28);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(iVar1 + 0x2c);
  *(undefined2 *)(in_ECX + 0x30) = *(undefined2 *)(iVar1 + 0x30);
  *(undefined1 *)(in_ECX + 0x32) = *(undefined1 *)(iVar1 + 0x32);
  *(undefined1 *)(in_ECX + 0x33) = *(undefined1 *)(iVar1 + 0x33);
  *(undefined1 *)(in_ECX + 0x34) = *(undefined1 *)(iVar1 + 0x34);
  *(undefined1 *)(in_ECX + 0x35) = *(undefined1 *)(iVar1 + 0x35);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(iVar1 + 0x38);
  *(undefined2 *)(in_ECX + 0x3c) = *(undefined2 *)(iVar1 + 0x3c);
  *(undefined2 *)(in_ECX + 0x3e) = *(undefined2 *)(iVar1 + 0x3e);
  if (in_ECX + 0x40 != iVar1 + 0x40) {
    FUN_005054c0(&param_1,**(undefined4 **)(in_ECX + 0x44),*(undefined4 **)(in_ECX + 0x44));
    FUN_00505580(iVar1 + 0x40);
  }
  return;
}


// ==== FUN_00558100 @ 0x00558100 ====

void FUN_00558100(byte param_1)

{
  void *in_ECX;
  
  FUN_00553f20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00558120 @ 0x00558120 ====

int FUN_00558120(void)

{
  int in_ECX;
  
  return in_ECX + 0x94;
}


// ==== FUN_00558130 @ 0x00558130 ====

void FUN_00558130(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10b) = param_1;
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  *(undefined1 *)(in_ECX + 0x73) = 0;
  return;
}


// ==== FUN_00558150 @ 0x00558150 ====

uint FUN_00558150(int param_1)

{
  int *piVar1;
  uint uVar2;
  int *in_ECX;
  
  uVar2 = *(uint *)(param_1 + 8);
  if (((char)in_ECX[0x42] == '\x01') && ((char)in_ECX[0x1c] != '\0')) {
    if (200 < uVar2 - in_ECX[0x46]) {
      in_ECX[0x46] = uVar2;
      piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
      uVar2 = (**(code **)(*piVar1 + 0x80))(0,0);
      return uVar2 & 0xffffff00;
    }
  }
  else {
    in_ECX[0x46] = uVar2;
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_005581c0 @ 0x005581c0 ====

void FUN_005581c0(int *param_1)

{
  int *in_ECX;
  
  in_ECX[0x1e] = *param_1;
  in_ECX[0x1f] = param_1[1];
  in_ECX[0x20] = param_1[2];
                    /* WARNING: Could not recover jumptable at 0x005581e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_005581f0 @ 0x005581f0 ====

undefined4 FUN_005581f0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x44) = 0;
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_00558220 @ 0x00558220 ====

void FUN_00558220(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0x78);
    local_8 = *(undefined4 *)(in_ECX + 0x7c);
    local_4 = *(undefined4 *)(in_ECX + 0x80);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_005582f0 @ 0x005582f0 ====

void FUN_005582f0(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  int *local_4;
  
  piVar2 = param_1;
  if (in_ECX[0x1d] != *param_1) {
    local_4 = in_ECX;
    FUN_00558e00(&local_4,param_1);
    if (local_4 != (int *)in_ECX[0x36]) {
      in_ECX[0x1e] = local_4[4];
      in_ECX[0x1f] = local_4[5];
      in_ECX[0x20] = local_4[6];
      (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
    }
    FUN_00558e70(&local_4,piVar2);
    if (local_4 != (int *)in_ECX[0x39]) {
      in_ECX[0x21] = local_4[4];
      in_ECX[0x22] = local_4[5];
      in_ECX[0x23] = local_4[6];
      in_ECX[0x24] = local_4[7];
      puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
        uVar3 = (**(code **)(*piVar2 + 4))();
        *puVar1 = &PTR_FUN_009bba08;
        puVar1[1] = uVar3;
        puVar1[3] = 1;
        puVar1[5] = 0;
        *(undefined1 *)(puVar1 + 6) = 0;
      }
      *(undefined1 *)((int)puVar1 + 0x19) = 1;
      puVar1[2] = in_ECX[0x21];
      puVar1[3] = in_ECX[0x22];
      puVar1[4] = in_ECX[0x23];
      *(char *)(puVar1 + 6) = (char)in_ECX[0x24];
      FUN_00797a20(puVar1);
      piVar2 = param_1;
    }
    FUN_00557be0(&param_1,piVar2);
    if (param_1 != (int *)in_ECX[0x33]) {
      in_ECX[0x2f] = param_1[0xe];
      in_ECX[0x2e] = param_1[0xd];
      *(undefined1 *)(in_ECX + 0x31) = *(undefined1 *)((int)in_ECX + 0x109);
      in_ECX[0x25] = param_1[4];
      in_ECX[0x26] = param_1[5];
      (**(code **)(*in_ECX + 8))(in_ECX + 0x25);
    }
    in_ECX[0x1d] = *piVar2;
  }
  return;
}


// ==== FUN_00558460 @ 0x00558460 ====

void FUN_00558460(uint param_1)

{
  int in_ECX;
  bool bVar1;
  
  if (*(char *)(in_ECX + 0x10b) != '\0') {
    if ((((*(char *)(in_ECX + 0x70) == '\x01') || (*(char *)(in_ECX + 0x72) == '\x01')) ||
        (*(char *)(in_ECX + 0x71) == '\x01')) ||
       ((*(char *)(in_ECX + 0x45) == '\0' || (*(char *)(in_ECX + 0x48) == '\0')))) {
      *(undefined4 *)(in_ECX + 0x11c) = 0;
    }
    else {
      *(int *)(in_ECX + 0x11c) = *(int *)(in_ECX + 0x11c) + *(int *)(param_1 + 4);
      if (*(uint *)(in_ECX + 0x114) < *(uint *)(in_ECX + 0x11c)) {
        bVar1 = *(char *)(in_ECX + 0x73) == '\0';
        *(undefined4 *)(in_ECX + 0x11c) = 0;
        *(bool *)(in_ECX + 0x73) = bVar1;
        param_1 = -(uint)bVar1 & 5;
        FUN_005582f0(&param_1);
        return;
      }
    }
  }
  return;
}


// ==== FUN_005584d0 @ 0x005584d0 ====

void FUN_005584d0(int *param_1)

{
  uint uVar1;
  int *piVar2;
  int *in_ECX;
  int iVar3;
  int *piVar4;
  int aiStack_28 [4];
  int iStack_18;
  int iStack_14;
  
  if (*(char *)((int)in_ECX + 0x45) != '\0') {
    piVar2 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
    piVar4 = aiStack_28;
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar4 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar4 = piVar4 + 1;
    }
    *(undefined1 *)(in_ECX + 0x1c) = 0;
    iVar3 = *param_1;
    uVar1 = param_1[1];
    if ((((aiStack_28[2] <= iVar3) && (aiStack_28[3] <= (int)uVar1)) && (iVar3 < iStack_18)) &&
       ((int)uVar1 < iStack_14)) {
      *(undefined1 *)((int)in_ECX + 0x71) = 1;
      param_1 = (int *)0x1;
      FUN_005582f0(&param_1);
      piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar2 + 0x80))(1,iVar3 << 0x10 | uVar1);
      return;
    }
    *(undefined1 *)((int)in_ECX + 0x71) = 0;
    param_1 = (int *)0x0;
    FUN_005582f0(&param_1);
  }
  return;
}


// ==== FUN_00558580 @ 0x00558580 ====

void FUN_00558580(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *in_ECX;
  undefined4 local_4;
  
  if (((*(char *)((int)in_ECX + 0x45) != '\0') && (*(char *)((int)in_ECX + 0x72) == '\0')) &&
     ((char)in_ECX[0x42] != '\x02')) {
    *(undefined1 *)(in_ECX + 0x1c) = 1;
    *(undefined1 *)((int)in_ECX + 0x71) = 1;
    local_4 = 2;
    FUN_005582f0(&local_4);
    iVar1 = *(int *)(param_1 + 0x10);
    uVar2 = *(uint *)(param_1 + 0x14);
    piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar3 + 0x80))(2,iVar1 << 0x10 | uVar2);
  }
  return;
}


// ==== FUN_005585e0 @ 0x005585e0 ====

void FUN_005585e0(void)

{
  int *piVar1;
  int *in_ECX;
  undefined4 uStack_c;
  
  if ((*(char *)((int)in_ECX + 0x72) == '\0') && ((char)in_ECX[0x42] != '\x02')) {
    *(undefined1 *)(in_ECX + 0x1c) = 1;
    *(undefined1 *)((int)in_ECX + 0x71) = 1;
    uStack_c = 0x55860a;
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    uStack_c = 0;
    (**(code **)(*piVar1 + 0x80))(0);
    FUN_004dd240(0xf,0,(char)in_ECX[0x44],0,0);
    FUN_005582f0(&uStack_c);
  }
  return;
}


// ==== FUN_00558640 @ 0x00558640 ====

void FUN_00558640(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *in_ECX;
  undefined4 local_4;
  
  if (((*(char *)((int)in_ECX + 0x72) == '\0') && (*(char *)((int)in_ECX + 0x45) != '\0')) &&
     ((char)in_ECX[0x42] != '\x02')) {
    *(undefined1 *)((int)in_ECX + 0x71) = 1;
    local_4 = 1;
    *(undefined1 *)(in_ECX + 0x1c) = 0;
    FUN_005582f0(&local_4);
    iVar1 = *(int *)(param_1 + 0x10);
    uVar2 = *(uint *)(param_1 + 0x14);
    piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar3 + 0x80))(4,iVar1 << 0x10 | uVar2);
  }
  return;
}


// ==== FUN_005586a0 @ 0x005586a0 ====

void FUN_005586a0(void)

{
  int *piVar1;
  int *in_ECX;
  undefined4 local_4;
  
  if ((*(char *)((int)in_ECX + 0x72) == '\0') && ((char)in_ECX[0x42] != '\x02')) {
    *(undefined1 *)(in_ECX + 0x1c) = 0;
    *(undefined1 *)((int)in_ECX + 0x71) = 0;
    local_4 = 0;
    FUN_005582f0(&local_4);
    piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar1 + 0x80))(5,0);
  }
  return;
}


// ==== FUN_005586f0 @ 0x005586f0 ====

void FUN_005586f0(char param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x45) != param_1) {
    *(char *)(in_ECX + 0x45) = param_1;
    if (param_1 != '\0') {
      _param_1 = 0;
      FUN_005582f0(&param_1);
      return;
    }
    _param_1 = 3;
    FUN_005582f0(&param_1);
  }
  return;
}


// ==== FUN_00558730 @ 0x00558730 ====

void FUN_00558730(char param_1)

{
  int in_ECX;
  
  *(char *)(in_ECX + 0x72) = param_1;
  if (param_1 == '\0') {
    _param_1 = 0;
    FUN_005582f0(&param_1);
    return;
  }
  _param_1 = 4;
  FUN_005582f0(&param_1);
  return;
}


// ==== FUN_00558770 @ 0x00558770 ====

undefined4 FUN_00558770(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 == iVar1) {
    switch(param_1[2] + -1) {
    case 0:
      FUN_005585e0();
      return 1;
    case 2:
      FUN_00558580(param_1 + 3);
      return 1;
    case 6:
      FUN_00558640(param_1 + 3);
      return 1;
    case 7:
      FUN_005586a0();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00558810 @ 0x00558810 ====

undefined4 FUN_00558810(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 != iVar1) {
    return 0;
  }
  if ((param_1[2] == 1) && (param_1[6] == 1)) {
    FUN_005584d0(param_1 + 0xe);
  }
  if ((param_1[2] == 0) && (param_1[6] == 1)) {
    piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar3 + 0x80))(0,0);
  }
  return 1;
}


// ==== FUN_00558880 @ 0x00558880 ====

undefined4 FUN_00558880(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  *(int **)(in_ECX + 0x40) = piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = **(int **)(in_ECX + 0x40);
      uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x44) = 1;
        *(undefined4 *)(in_ECX + 0x74) = 0xffffffff;
        uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
        FUN_00552120(uVar4);
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  return 0;
}


// ==== FUN_00558920 @ 0x00558920 ====

undefined4 FUN_00558920(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) == 0) || (*(char *)(in_ECX + 0x45) == '\0')) {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    cVar1 = FUN_00558770(param_1);
  }
  else {
    if (iVar2 != 0x10003) {
      if (iVar2 == 0x40001) {
        FUN_00558150(param_1);
        FUN_00558460(param_1);
        return 0;
      }
      return 0;
    }
    cVar1 = FUN_00558810(param_1);
  }
  if (cVar1 == '\0') {
    return 0;
  }
  return 1;
}


// ==== FUN_005589b0 @ 0x005589b0 ====

void FUN_005589b0(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  undefined1 local_4 [4];
  
  piVar1 = param_1;
  if ((*(int *)(in_ECX + 0x40) != 0) &&
     (iVar2 = FUN_00403620(0,param_1[7],s_Button_Close_Fail_009bb9d8 + 0x13,0), iVar2 != 0)) {
    FUN_005523f0(piVar1);
    if (*(int *)(in_ECX + 0xb0) == 0) {
      param_1 = (int *)0x0;
    }
    else {
      (**(code **)(*DAT_00b5a688 + 0x34))
                (*(undefined4 *)(in_ECX + 0xb8),in_ECX + 0x9c,&param_1,local_4);
    }
    uVar3 = 0;
    if (*(char *)((int)piVar1 + 0x31) == '\x01') {
      uVar3 = (uint)((*(int *)(in_ECX + 0x58) - *(int *)(in_ECX + 0x50)) - (int)param_1) >> 1;
    }
    else if (*(char *)((int)piVar1 + 0x31) == '\x02') {
      uVar3 = (*(int *)(in_ECX + 0x58) - *(int *)(in_ECX + 0x50)) - (int)param_1;
    }
    if (*(int *)(in_ECX + 0x58) - *(int *)(in_ECX + 0x50) <= (int)param_1) {
      uVar3 = 0;
    }
    *(uint *)(in_ECX + 0x94) = *piVar1 + uVar3;
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(piVar1,0);
  }
  return;
}


// ==== FUN_00558a80 @ 0x00558a80 ====

void FUN_00558a80(int param_1)

{
  int *in_ECX;
  
  FUN_00504d50(*(undefined4 *)(in_ECX[0x33] + 4));
  *(int *)(in_ECX[0x33] + 4) = in_ECX[0x33];
  in_ECX[0x34] = 0;
  *(int *)in_ECX[0x33] = in_ECX[0x33];
  *(int *)(in_ECX[0x33] + 8) = in_ECX[0x33];
  FUN_00558ee0(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
  FUN_00557be0(&param_1,in_ECX + 0x1d);
  if (param_1 != in_ECX[0x33]) {
    FUN_005523f0(param_1 + 0x10);
    (**(code **)(*in_ECX + 8))(in_ECX + 0x25);
  }
  return;
}


// ==== FUN_00558b00 @ 0x00558b00 ====

void FUN_00558b00(void)

{
  undefined4 *in_ECX;
  
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bba24;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)((int)in_ECX + 0x71) = 0;
  *(undefined1 *)((int)in_ECX + 0x72) = 0;
  in_ECX[0x1d] = 0xffffffff;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x2d] = 0xf;
  in_ECX[0x2c] = 0;
  *(undefined1 *)(in_ECX + 0x28) = 0;
  in_ECX[0x2e] = 1;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 1;
  *(undefined1 *)(in_ECX + 0x31) = 0;
  *(undefined1 *)((int)in_ECX + 0xc5) = 0;
  FUN_00505a60();
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x73) = 0;
  in_ECX[0x47] = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  return;
}


// ==== FUN_00558bc0 @ 0x00558bc0 ====

void FUN_00558bc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bba24;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00505af0();
  if ((uint)in_ECX[0x2d] < 0x10) {
    in_ECX[0x2c] = 0;
    in_ECX[0x2d] = 0xf;
    *(undefined1 *)(in_ECX + 0x28) = 0;
    FUN_00552170();
    return;
  }
  _free((void *)in_ECX[0x28]);
  return;
}


// ==== FUN_00558c30 @ 0x00558c30 ====

void FUN_00558c30(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  int *local_4;
  
  local_4 = in_ECX;
  FUN_00505cc0(param_1 + 0xc4);
  param_1 = 0;
  FUN_00558e00(&local_4,&param_1);
  if (local_4 == (int *)in_ECX[0x36]) {
    in_ECX[0x1e] = 0;
  }
  else {
    in_ECX[0x1e] = local_4[4];
    in_ECX[0x1f] = local_4[5];
    in_ECX[0x20] = local_4[6];
  }
  FUN_00558e70(&local_4,&param_1);
  if (local_4 == (int *)in_ECX[0x39]) {
    in_ECX[0x21] = 0;
  }
  else {
    in_ECX[0x21] = local_4[4];
    in_ECX[0x22] = local_4[5];
    in_ECX[0x23] = local_4[6];
    in_ECX[0x24] = local_4[7];
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
      uVar3 = (**(code **)(*piVar2 + 4))();
      *puVar1 = &PTR_FUN_009bba08;
      puVar1[1] = uVar3;
      puVar1[3] = 1;
      puVar1[5] = 0;
      *(undefined1 *)(puVar1 + 6) = 0;
    }
    *(undefined1 *)((int)puVar1 + 0x19) = 1;
    puVar1[2] = in_ECX[0x21];
    puVar1[3] = in_ECX[0x22];
    puVar1[4] = in_ECX[0x23];
    *(char *)(puVar1 + 6) = (char)in_ECX[0x24];
    (**(code **)(*DAT_00b5ad24 + 4))(puVar1);
    (**(code **)*puVar1)(1);
  }
  FUN_00557be0(&local_4,&param_1);
  if (local_4 != (int *)in_ECX[0x33]) {
    FUN_005523f0(local_4 + 4);
    (**(code **)(*in_ECX + 8))(in_ECX + 0x25);
  }
  in_ECX[0x1d] = 0;
  FUN_00401660(in_ECX + 0x3b,0,0xffffffff);
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return;
}


// ==== FUN_00558dc0 @ 0x00558dc0 ====

void FUN_00558dc0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009bba08;
  in_ECX[3] = 1;
  in_ECX[5] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  return;
}


// ==== FUN_00558df0 @ 0x00558df0 ====

undefined4 FUN_00558df0(void)

{
  return 0x60000050;
}


// ==== FUN_00558e00 @ 0x00558e00 ====

void FUN_00558e00(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x1d) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x1d) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_00558e70 @ 0x00558e70 ====

void FUN_00558e70(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_00558ee0 @ 0x00558ee0 ====

void FUN_00558ee0(int *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined1 local_8 [8];
  
  while (param_1 != param_2) {
    FUN_00505600(local_8,param_1 + 3);
    if (*(char *)((int)param_1 + 0x45) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x45) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x45);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x45);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x45);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x45);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  return;
}


// ==== FUN_00558f60 @ 0x00558f60 ====

void FUN_00558f60(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00558f65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x24))();
  return;
}


// ==== FUN_00558f70 @ 0x00558f70 ====

void FUN_00558f70(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00558f75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x28))();
  return;
}


// ==== FUN_00558f80 @ 0x00558f80 ====

void FUN_00558f80(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00558f85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x30))();
  return;
}


// ==== FUN_00558f90 @ 0x00558f90 ====

undefined4 FUN_00558f90(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x2c))(param_1);
  return param_1;
}


// ==== FUN_00558fb0 @ 0x00558fb0 ====

void FUN_00558fb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00558bc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00558fd0 @ 0x00558fd0 ====

void FUN_00558fd0(undefined1 param_1)

{
  int *in_ECX;
  
  *(undefined1 *)(in_ECX + 0x12) = param_1;
                    /* WARNING: Could not recover jumptable at 0x00558fdf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_00558ff0 @ 0x00558ff0 ====

void FUN_00558ff0(int param_1)

{
  int *in_ECX;
  
  in_ECX[0x23] = param_1;
                    /* WARNING: Could not recover jumptable at 0x00559003. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_00559010 @ 0x00559010 ====

undefined4 FUN_00559010(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 4))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 == iVar1) {
    switch(param_1[2] + -1) {
    case 0:
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(1,0);
      return 1;
    case 1:
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(3,0);
      return 1;
    case 2:
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(2,0);
      return 1;
    case 6:
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(4,0);
      return 1;
    case 7:
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(5,0);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00559110 @ 0x00559110 ====

void FUN_00559110(int *param_1)

{
  int *in_ECX;
  
  in_ECX[0x23] = *param_1;
  in_ECX[0x24] = param_1[1];
  in_ECX[0x25] = param_1[2];
  in_ECX[0x1f] = param_1[0x65];
  in_ECX[0x20] = param_1[0x66];
  in_ECX[0x21] = param_1[0x67];
  in_ECX[0x22] = param_1[0x68];
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  (**(code **)(*in_ECX + 8))(in_ECX + 0x26);
  return;
}


// ==== FUN_00559170 @ 0x00559170 ====

void FUN_00559170(int param_1)

{
  int *in_ECX;
  
  if ((int *)in_ECX[0x10] != (int *)0x0) {
    in_ECX[0x30] = param_1;
    (**(code **)(*(int *)in_ECX[0x10] + 0x14))(in_ECX + 0x26,0);
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  }
  return;
}


// ==== FUN_005591b0 @ 0x005591b0 ====

undefined4 FUN_005591b0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined1 *)(in_ECX + 0x44) = 0;
  return 1;
}


// ==== FUN_005591e0 @ 0x005591e0 ====

undefined4 FUN_005591e0(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x40) != 0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0x10))(param_1), cVar1 != '\0')) {
    return 1;
  }
  if (((*(int *)(in_ECX + 4) == 0) || (iVar2 = (**(code **)(*param_1 + 4))(), iVar2 != 0x10001)) ||
     (cVar1 = FUN_00559010(param_1), cVar1 == '\0')) {
    return 0;
  }
  return 1;
}


// ==== FUN_00559230 @ 0x00559230 ====

void FUN_00559230(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  iVar1 = param_2[1];
  iVar3 = *(int *)(iVar3 + 0xc);
  iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  iVar2 = *param_2;
  iVar4 = *(int *)(iVar4 + 8);
  param_1[1] = iVar1 - iVar3;
  *param_1 = iVar2 - iVar4;
  return;
}


// ==== FUN_00559270 @ 0x00559270 ====

void FUN_00559270(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0x8c);
    local_8 = *(undefined4 *)(in_ECX + 0x90);
    local_4 = *(undefined4 *)(in_ECX + 0x94);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_00559380 @ 0x00559380 ====

void FUN_00559380(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbb04;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
    *(undefined1 *)(in_ECX + 0x11) = 0;
  }
  if ((uint)in_ECX[0x2e] < 0x10) {
    in_ECX[0x2d] = 0;
    in_ECX[0x2e] = 0xf;
    *(undefined1 *)(in_ECX + 0x29) = 0;
    FUN_00552170();
    return;
  }
  _free((void *)in_ECX[0x29]);
  return;
}


// ==== FUN_005593e0 @ 0x005593e0 ====

void FUN_005593e0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bbb04;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x2e] = 0xf;
  in_ECX[0x2d] = 0;
  *(undefined1 *)(in_ECX + 0x29) = 0;
  in_ECX[0x30] = 0;
  *(undefined1 *)(in_ECX + 0x32) = 0;
  *(undefined1 *)((int)in_ECX + 0xc9) = 0;
  in_ECX[0x2f] = 1;
  in_ECX[0x31] = 1;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  in_ECX[0x20] = 5;
  in_ECX[0x21] = 5;
  *(undefined1 *)(in_ECX + 0x1f) = 0;
  *(undefined1 *)((int)in_ECX + 0x7d) = 0;
  *(undefined1 *)((int)in_ECX + 0x7e) = 0;
  in_ECX[0x22] = 0xc;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  return;
}


// ==== FUN_005594a0 @ 0x005594a0 ====

undefined4 FUN_005594a0(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  *(int **)(in_ECX + 0x40) = piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = **(int **)(in_ECX + 0x40);
      uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x44) = 1;
        uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
        FUN_00552120(uVar4);
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  return 0;
}


// ==== FUN_00559540 @ 0x00559540 ====

void FUN_00559540(undefined4 param_1)

{
  int iVar1;
  undefined1 local_54 [4];
  void *local_50;
  int local_40;
  uint local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00401740(&DAT_009bbad2,0);
  do {
    if (local_40 == 0) {
LAB_00559670:
      if (local_3c < 0x10) {
        return;
      }
      _free(local_50);
      return;
    }
    iVar1 = FUN_00405850(&DAT_009bbad4,0,1);
    if (iVar1 == -1) {
      FUN_00401ff0(local_54,0,0xffffffff);
      goto LAB_00559670;
    }
    if (iVar1 != 0) {
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      FUN_00401660(local_54,0,iVar1);
      FUN_00401ff0(local_38,0,0xffffffff);
      if (0xf < local_20) {
        _free(local_34);
        return;
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
    }
    iVar1 = FUN_00405850(&DAT_009bbad8,0,1);
    if (iVar1 == -1) goto LAB_00559670;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401660(local_54,iVar1 + 1,0xffffffff);
    FUN_00401660(local_1c,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
  } while( true );
}


// ==== FUN_00559690 @ 0x00559690 ====

void FUN_00559690(undefined4 *param_1,undefined4 param_2,undefined4 param_3,ushort *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = FUN_00403620(*param_4,5,s_<font_009bbaec,5);
  if (iVar1 == 0) {
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    local_4 = 0xf;
    FUN_00401660(param_3,*param_4 + 6,1);
    uVar2 = thunk_FUN_00796fb0(local_1c);
    *param_1 = uVar2;
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    *param_4 = *param_4 + 7;
  }
  return;
}


// ==== FUN_00559710 @ 0x00559710 ====

void FUN_00559710(void)

{
  uint *puVar1;
  uint *_Memory;
  void *pvVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 ****ppppuVar8;
  undefined4 uVar9;
  int *in_ECX;
  uint uVar10;
  undefined4 ****ppppuVar11;
  uint uVar12;
  int *piVar13;
  void *pvVar14;
  uint *puVar15;
  uint uStack_14c;
  uint local_148;
  undefined4 uStack_144;
  uint uStack_140;
  uint uStack_13c;
  undefined1 auStack_138 [4];
  uint *local_134;
  uint *local_130;
  undefined4 local_12c;
  undefined1 local_128 [4];
  void *local_124;
  void *local_120;
  undefined4 local_11c;
  uint uStack_118;
  undefined4 local_114;
  undefined1 auStack_110 [4];
  undefined4 ****appppuStack_10c [4];
  uint uStack_fc;
  uint uStack_f8;
  int *local_f4;
  undefined1 local_f0 [4];
  void *local_ec;
  undefined4 local_dc;
  uint local_d8;
  undefined1 auStack_d4 [4];
  undefined4 ****appppuStack_d0 [4];
  int iStack_c0;
  uint uStack_bc;
  int iStack_b8;
  uint uStack_b4;
  int iStack_b0;
  uint uStack_ac;
  undefined1 auStack_a8 [4];
  undefined4 ****appppuStack_a4 [4];
  int iStack_94;
  uint uStack_90;
  undefined1 local_8c [4];
  void *local_88;
  undefined4 local_78;
  uint local_74;
  undefined1 auStack_70 [4];
  void *pvStack_6c;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (in_ECX[0x2d] != 0) {
    local_148 = 0;
    local_114 = 0;
    local_74 = 0xf;
    local_78 = 0;
    local_88 = (void *)((uint)local_88 & 0xffffff00);
    local_f4 = in_ECX;
    FUN_00401660(in_ECX + 0x28,0,0xffffffff);
    FUN_00559540(local_8c);
    if (*(char *)((int)in_ECX + 0x7d) != '\0') {
      *(undefined1 *)(in_ECX + 0x1f) = 1;
      local_124 = (void *)0x0;
      local_120 = (void *)0x0;
      local_11c = 0;
      local_d8 = 0xf;
      local_dc = 0;
      local_ec = (void *)((uint)local_ec & 0xffffff00);
      FUN_00401740(&DAT_009bbadc,1);
      FUN_00405300(in_ECX + 0x28,local_f0,local_128);
      if (0xf < local_d8) {
        _free(local_ec);
        return;
      }
      piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
      iVar5 = (**(code **)(*piVar4 + 0x14))();
      uStack_118 = 0;
      uVar12 = ((*(int *)(iVar5 + 0x10) - in_ECX[0x20]) - *(int *)(iVar5 + 8)) - 0xc;
      uStack_b4 = uVar12;
      while( true ) {
        pvVar14 = local_124;
        if (local_124 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = ((int)local_120 - (int)local_124) / 0x1c;
        }
        uVar10 = uStack_118 & 0xffff;
        if (uVar6 <= uVar10) break;
        if ((local_124 == (void *)0x0) ||
           ((uint)(((int)local_120 - (int)local_124) / 0x1c) <= uVar10)) {
                    /* WARNING: Subroutine does not return */
          FUN_00405ca0();
        }
        (**(code **)(*DAT_00b5a688 + 0x34))
                  (in_ECX[0x2f],(void *)((int)local_124 + uVar10 * 0x1c),&local_148,&local_114);
        if (uVar12 <= local_148) {
          local_134 = (uint *)0x0;
          local_130 = (uint *)0x0;
          local_12c = 0;
          if ((local_124 == (void *)0x0) ||
             ((uint)(((int)local_120 - (int)local_124) / 0x1c) <= uVar10)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          uStack_f8 = 0xf;
          uStack_fc = 0;
          appppuStack_10c[0] = (undefined4 ****)((uint)appppuStack_10c[0] & 0xffffff00);
          FUN_00401660((void *)((int)local_124 + uVar10 * 0x1c),0,0xffffffff);
          iStack_b8 = in_ECX[0x2f];
          uStack_140 = 0;
          uStack_90 = 0xf;
          iStack_94 = 0;
          appppuStack_a4[0] = (undefined4 ****)((uint)appppuStack_a4[0] & 0xffffff00);
          uStack_bc = 0xf;
          iStack_c0 = 0;
          appppuStack_d0[0] = (undefined4 ****)((uint)appppuStack_d0[0] & 0xffffff00);
          uStack_ac = uStack_fc;
          uStack_13c = 0;
          if ((short)uStack_fc != 0) {
            do {
              uVar12 = uStack_13c;
              uVar6 = uStack_13c & 0xffff;
              if (uStack_fc <= uVar6) {
                FUN_0079dba3();
              }
              ppppuVar8 = appppuStack_10c[0];
              if (uStack_f8 < 0x10) {
                ppppuVar8 = appppuStack_10c;
              }
              if (*(char *)((int)ppppuVar8 + uVar6) == '<') {
                FUN_00559690(&iStack_b8,&local_f4,auStack_110,&uStack_13c);
                uVar12 = uStack_13c;
              }
              uVar6 = uVar12 & 0xffff;
              if (uVar6 < uStack_fc) {
                ppppuVar8 = appppuStack_10c[0];
                if (uStack_f8 < 0x10) {
                  ppppuVar8 = appppuStack_10c;
                }
                cVar3 = FUN_00403d70((int)*(char *)((int)ppppuVar8 + uVar6));
                iVar5 = 2;
                if (cVar3 != '\x01') goto LAB_005599df;
              }
              else {
LAB_005599df:
                iVar5 = 1;
              }
              uStack_20 = 0xf;
              uStack_24 = 0;
              pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
              iStack_b0 = iVar5;
              FUN_00401660(auStack_110,uVar6,iVar5);
              FUN_00401ff0(auStack_38,0,0xffffffff);
              if (0xf < uStack_20) {
                _free(pvStack_34);
                return;
              }
              uStack_20 = 0xf;
              uStack_24 = 0;
              pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
              (**(code **)(*DAT_00b5a688 + 0x34))(iStack_b8,auStack_a8,&local_148,&local_114);
              if (uStack_b4 <= local_148) {
                iVar7 = (**(code **)(*DAT_00b5a6b0 + 8))();
                if (iVar7 == 3) {
                  uVar12 = iVar5 + uVar6;
                  if (uVar12 < (uStack_ac & 0xffff)) {
                    if (uStack_fc <= uVar6) {
                      FUN_0079dba3();
                    }
                    ppppuVar8 = appppuStack_10c[0];
                    if (uStack_f8 < 0x10) {
                      ppppuVar8 = appppuStack_10c;
                    }
                    cVar3 = *(char *)((int)ppppuVar8 + uVar6);
                    if (uStack_fc <= uVar12) {
                      FUN_0079dba3();
                    }
                    ppppuVar8 = appppuStack_10c[0];
                    if (uStack_f8 < 0x10) {
                      ppppuVar8 = appppuStack_10c;
                    }
                    if ((((cVar3 != '\t') && (cVar3 != ' ')) &&
                        (*(char *)((int)ppppuVar8 + uVar12) != '\t')) &&
                       (*(char *)((int)ppppuVar8 + uVar12) != ' ')) {
                      FUN_00403810(&DAT_009bbae0);
                      goto LAB_00559bb8;
                    }
                    ppppuVar8 = appppuStack_d0[0];
                    if (uStack_bc < 0x10) {
                      ppppuVar8 = appppuStack_d0;
                    }
                    iVar7 = (int)ppppuVar8 + iStack_c0;
                    ppppuVar8 = appppuStack_d0[0];
                    if (uStack_bc < 0x10) {
                      ppppuVar8 = appppuStack_d0;
                    }
                  }
                  else {
                    ppppuVar8 = appppuStack_d0[0];
                    if (uStack_bc < 0x10) {
                      ppppuVar8 = appppuStack_d0;
                    }
                    iVar7 = (int)ppppuVar8 + iStack_c0;
                    ppppuVar8 = appppuStack_d0[0];
                    if (uStack_bc < 0x10) {
                      ppppuVar8 = appppuStack_d0;
                    }
                  }
                  FUN_004bdb30(&uStack_144,ppppuVar8,iVar7);
                }
LAB_00559bb8:
                uVar6 = iVar5 + uVar6;
                uStack_3c = 0xf;
                uStack_40 = 0;
                pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
                FUN_00401660(auStack_110,uStack_140,uVar6 - uStack_140);
                uVar9 = FUN_00405bd0(auStack_1c,auStack_54,auStack_d4);
                FUN_004066a0(&uStack_144,local_134,uVar9);
                if (0xf < uStack_4) {
                  _free(pvStack_18);
                  return;
                }
                uStack_4 = 0xf;
                uStack_8 = 0;
                pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
                ppppuVar8 = appppuStack_a4[0];
                if (uStack_90 < 0x10) {
                  ppppuVar8 = appppuStack_a4;
                }
                ppppuVar11 = appppuStack_a4[0];
                if (uStack_90 < 0x10) {
                  ppppuVar11 = appppuStack_a4;
                }
                if ((int)ppppuVar8 + iStack_94 == 0) {
                  iVar5 = 0;
                }
                else {
                  iVar5 = ((int)ppppuVar8 + iStack_94) - (int)ppppuVar11;
                }
                FUN_00401390(0,iVar5);
                uStack_140 = uVar6;
                if (0xf < uStack_3c) {
                  _free(pvStack_50);
                  return;
                }
                uStack_3c = 0xf;
                uStack_40 = 0;
                pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
                uVar12 = uStack_13c;
                iVar5 = iStack_b0;
              }
              uStack_13c = uVar12 + iVar5;
            } while ((ushort)uStack_13c < (ushort)uStack_ac);
          }
          local_d8 = 0xf;
          local_dc = 0;
          local_ec = (void *)((uint)local_ec & 0xffffff00);
          FUN_00401660(auStack_110,uStack_140,(uStack_13c & 0xffff) - uStack_140);
          FUN_004066a0(&uStack_144,local_134,local_f0);
          pvVar2 = local_120;
          for (pvVar14 = (void *)((int)local_124 + uVar10 * 0x1c + 0x1c); pvVar14 != pvVar2;
              pvVar14 = (void *)((int)pvVar14 + 0x1c)) {
            FUN_00401660(pvVar14,0,0xffffffff);
          }
          FUN_00405de0((int)local_120 + -0x1c,local_120,local_128,uStack_144);
          _Memory = local_134;
          local_120 = (void *)((int)local_120 + -0x1c);
          uStack_14c = 0;
          while( true ) {
            if (_Memory == (uint *)0x0) {
              uVar12 = 0;
            }
            else {
              uVar12 = ((int)local_130 - (int)_Memory) / 0x1c;
            }
            uVar6 = uStack_14c & 0xffff;
            if (uVar12 <= uVar6) break;
            if ((_Memory == (uint *)0x0) ||
               ((uint)(((int)local_130 - (int)_Memory) / 0x1c) <= uVar6)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            uStack_58 = 0xf;
            uStack_5c = 0;
            pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
            FUN_00401660(_Memory + uVar6 * 7,0,0xffffffff);
            FUN_004062c0((void *)((int)local_124 + uVar10 * 0x1c),1,auStack_70);
            if (0xf < uStack_58) {
              _free(pvStack_6c);
              return;
            }
            uStack_14c = uStack_14c + 1;
            uStack_58 = 0xf;
            uStack_5c = 0;
            pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
          }
          if (_Memory == (uint *)0x0) {
            iVar5 = 0;
          }
          else {
            iVar5 = ((int)local_130 - (int)_Memory) / 0x1c;
          }
          uStack_118 = (uStack_118 - 1) + iVar5;
          if (0xf < local_d8) {
            _free(local_ec);
            return;
          }
          local_d8 = 0xf;
          local_dc = 0;
          local_ec = (void *)((uint)local_ec & 0xffffff00);
          if (0xf < uStack_bc) {
            _free(appppuStack_d0[0]);
            return;
          }
          uStack_bc = 0xf;
          iStack_c0 = 0;
          appppuStack_d0[0] = (undefined4 ****)((uint)appppuStack_d0[0] & 0xffffff00);
          if (0xf < uStack_90) {
            _free(appppuStack_a4[0]);
            return;
          }
          uStack_90 = 0xf;
          iStack_94 = 0;
          appppuStack_a4[0] = (undefined4 ****)((uint)appppuStack_a4[0] & 0xffffff00);
          if (0xf < uStack_f8) {
            _free(appppuStack_10c[0]);
            return;
          }
          uStack_f8 = 0xf;
          uStack_fc = 0;
          appppuStack_10c[0] = (undefined4 ****)((uint)appppuStack_10c[0] & 0xffffff00);
          if (_Memory != (uint *)0x0) {
            if (_Memory != local_130) {
              puVar15 = _Memory + 6;
              do {
                if (0xf < *puVar15) {
                  _free((void *)puVar15[-5]);
                  return;
                }
                *puVar15 = 0xf;
                puVar15[-1] = 0;
                *(undefined1 *)(puVar15 + -5) = 0;
                puVar1 = puVar15 + 1;
                puVar15 = puVar15 + 7;
              } while (puVar1 != local_130);
            }
            _free(_Memory);
            return;
          }
          local_134 = (void *)0x0;
          local_130 = (uint *)0x0;
          local_12c = 0;
          in_ECX = local_f4;
          uVar12 = uStack_b4;
        }
        uStack_118 = uStack_118 + 1;
      }
      piVar4 = in_ECX + 0x29;
      if ((uint)in_ECX[0x2e] < 0x10) {
        piVar13 = piVar4;
      }
      else {
        piVar13 = (int *)*piVar4;
      }
      if (0xf < (uint)in_ECX[0x2e]) {
        piVar4 = (int *)*piVar4;
      }
      FUN_004bdb30(&uStack_144,piVar4,in_ECX[0x2d] + (int)piVar13);
      if (pvVar14 != local_120) {
        do {
          FUN_00401ff0(pvVar14,0,0xffffffff);
          if (pvVar14 != local_120) {
            FUN_004020e0(&DAT_009bbae4,1);
          }
          pvVar14 = (void *)((int)pvVar14 + 0x1c);
        } while (pvVar14 != local_120);
      }
      if (local_124 != (void *)0x0) {
        FUN_00405de0(local_124,local_120,local_128,uStack_144);
        _free(local_124);
        return;
      }
    }
    if ((char)in_ECX[0x1f] == '\0') {
      *(undefined1 *)(in_ECX + 0x32) = 0;
      (**(code **)(*DAT_00b5a688 + 0x34))(in_ECX[0x2f],local_8c,&local_148,&local_114);
    }
    else {
      uVar12 = 0;
      *(undefined1 *)(in_ECX + 0x32) = 1;
      local_134 = (void *)0x0;
      local_130 = (uint *)0x0;
      local_12c = 0;
      local_d8 = 0xf;
      local_dc = 0;
      local_ec = (void *)((uint)local_ec & 0xffffff00);
      FUN_00401740(&DAT_009bbae8,1);
      FUN_00405300(local_8c,local_f0,auStack_138);
      if (0xf < local_d8) {
        _free(local_ec);
        return;
      }
      uStack_140 = 0;
      uStack_14c = 0;
      for (; (local_134 != (void *)0x0 &&
             (uVar12 < (uint)(((int)local_130 - (int)local_134) / 0x1c))); uVar12 = uVar12 + 1) {
        (**(code **)(*DAT_00b5a688 + 0x34))
                  (in_ECX[0x2f],(int)local_134 + uStack_14c,&local_148,&local_114);
        if (uStack_140 < local_148) {
          uStack_140 = local_148;
        }
        uStack_14c = uStack_14c + 0x1c;
      }
      local_148 = uStack_140;
      if (local_134 != (void *)0x0) {
        FUN_00405de0(local_134,local_130,auStack_138,uStack_144);
        _free(local_134);
        return;
      }
    }
    if ((int)(local_148 + 5) < in_ECX[0x16] - in_ECX[0x14]) {
      if (*(char *)((int)in_ECX + 0x7e) == '\x01') {
        in_ECX[0x26] = ((in_ECX[0x16] - in_ECX[0x14]) - local_148) - 5 >> 1;
      }
      else if (*(char *)((int)in_ECX + 0x7e) == '\x02') {
        in_ECX[0x26] = ((in_ECX[0x16] - in_ECX[0x14]) - local_148) + -5;
      }
      else {
        in_ECX[0x26] = 3;
      }
    }
    else {
      in_ECX[0x26] = 1;
    }
    if (0xf < local_74) {
      _free(local_88);
      return;
    }
  }
  return;
}


// ==== FUN_0055a260 @ 0x0055a260 ====

void FUN_0055a260(undefined4 param_1)

{
  int *in_ECX;
  
  if (in_ECX[0x10] != 0) {
    FUN_00401660(param_1,0,0xffffffff);
    FUN_00559710();
    (**(code **)(*(int *)in_ECX[0x10] + 0x14))(in_ECX + 0x26,0);
    (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  }
  return;
}


// ==== FUN_0055a2b0 @ 0x0055a2b0 ====

void FUN_0055a2b0(int param_1)

{
  code *pcVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(param_1 + 4) != 0xd) {
    if (*(int *)(in_ECX + 0x40) != 0) {
      FUN_005523f0(param_1);
      FUN_00559710();
      *(undefined4 *)(in_ECX + 0xc4) = *(undefined4 *)(in_ECX + 0x88);
      (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(in_ECX + 0x98,0);
    }
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_FALSE_009bbacc,5);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0055a370 @ 0x0055a370 ====

void FUN_0055a370(byte param_1)

{
  void *in_ECX;
  
  FUN_00559380();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0055a390 @ 0x0055a390 ====

void FUN_0055a390(void)

{
  void *pvVar1;
  
  if (DAT_00b5a7ac == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_0055b770();
    }
  }
  if (DAT_00b5a7a8 == 0) {
    pvVar1 = operator_new(0x14);
    if (pvVar1 != (void *)0x0) {
      FUN_0055b390();
      return;
    }
  }
  return;
}


// ==== FUN_0055a3d0 @ 0x0055a3d0 ====

void FUN_0055a3d0(void)

{
  if (DAT_00b5a7a8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a7a8)(1);
  }
  if (DAT_00b5a7ac != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a7ac)(1);
  }
  return;
}


// ==== FUN_0055a400 @ 0x0055a400 ====

void FUN_0055a400(void)

{
  void *pvVar1;
  
  if (DAT_00b5a7a4 == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_0056b150();
    }
  }
  if (DAT_00b5a798 == 0) {
    pvVar1 = operator_new(0xc);
    if (pvVar1 != (void *)0x0) {
      FUN_0055ca80();
    }
  }
  if (DAT_00b5a7a0 == 0) {
    pvVar1 = operator_new(0x28);
    if (pvVar1 != (void *)0x0) {
      FUN_0055c6b0();
    }
  }
  if (DAT_00b5a79c == 0) {
    pvVar1 = operator_new(0x14);
    if (pvVar1 != (void *)0x0) {
      FUN_0055bf20();
      return;
    }
  }
  return;
}


// ==== FUN_0055a480 @ 0x0055a480 ====

void FUN_0055a480(void)

{
  if (DAT_00b5a7a4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a7a4)(1);
  }
  if (DAT_00b5a798 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a798)(1);
  }
  if (DAT_00b5a7a0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a7a0)(1);
  }
  if (DAT_00b5a79c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a79c)(1);
  }
  return;
}


// ==== FUN_0055a560 @ 0x0055a560 ====

void FUN_0055a560(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x14))(param_1,0);
  }
  return;
}


// ==== FUN_0055a580 @ 0x0055a580 ====

undefined4 FUN_0055a580(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) == '\0') {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x44) = 0;
  if (*(undefined4 **)(in_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x40))(1);
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return 1;
}


// ==== FUN_0055a5b0 @ 0x0055a5b0 ====

undefined4 FUN_0055a5b0(int *param_1)

{
  char cVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    cVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0x10))(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  (**(code **)(*param_1 + 4))();
  return 0;
}


// ==== FUN_0055a5e0 @ 0x0055a5e0 ====

void FUN_0055a5e0(undefined1 *param_1)

{
  int in_ECX;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x48) = *param_1;
  *(undefined1 *)(in_ECX + 0x49) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x24);
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 4) != 0)) {
    local_34[0] = *(undefined1 *)(in_ECX + 0x48);
    local_c = *(undefined4 *)(in_ECX + 0x98);
    local_8 = *(undefined4 *)(in_ECX + 0x9c);
    local_4 = *(undefined4 *)(in_ECX + 0xa0);
    local_30 = *(undefined4 *)(in_ECX + 0x4c);
    local_28 = *(undefined4 *)(in_ECX + 0x54);
    local_2c = *(undefined4 *)(in_ECX + 0x50);
    local_20 = *(undefined4 *)(in_ECX + 0x5c);
    local_24 = *(undefined4 *)(in_ECX + 0x58);
    local_18 = *(undefined4 *)(in_ECX + 100);
    local_1c = *(undefined4 *)(in_ECX + 0x60);
    local_10 = *(undefined4 *)(in_ECX + 0x6c);
    local_14 = *(undefined4 *)(in_ECX + 0x68);
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1c))(local_34);
  }
  return;
}


// ==== FUN_0055a6b0 @ 0x0055a6b0 ====

void FUN_0055a6b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbc54;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00552170();
  return;
}


// ==== FUN_0055a6e0 @ 0x0055a6e0 ====

void FUN_0055a6e0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[7] = 0;
  in_ECX[8] = 0xf;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *in_ECX = &PTR_FUN_009bbc54;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 1;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0xffffffff;
  in_ECX[0x25] = 0xf;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[1] = 0;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 1;
  in_ECX[0x29] = 0;
  return;
}


// ==== FUN_0055a760 @ 0x0055a760 ====

uint FUN_0055a760(void)

{
  int iVar1;
  undefined4 uVar2;
  uint extraout_EAX;
  int in_ECX;
  undefined1 auStack_3c [12];
  int iStack_30;
  int iStack_28;
  void *pvStack_1c;
  uint uStack_8;
  
  if (*(uint *)(in_ECX + 0x8c) == *(uint *)(in_ECX + 0x88)) {
    return *(uint *)(in_ECX + 0x8c) & 0xffffff00;
  }
  uVar2 = (**(code **)(**(int **)(in_ECX + 0x78) + 0x10))();
  FUN_005041e0(uVar2);
  iVar1 = *(int *)(in_ECX + 0x88);
  if (iVar1 == 0) {
    iStack_30 = *(int *)(in_ECX + 0x84);
  }
  else {
    if (iVar1 == *(int *)(in_ECX + 0x7c)) {
      iStack_30 = *(int *)(in_ECX + 0x90) - *(int *)(in_ECX + 0x94);
    }
    else {
      iStack_30 = (int)((float)iVar1 * *(float *)(in_ECX + 0xa8));
    }
    iStack_30 = iStack_30 + *(int *)(in_ECX + 0x84);
  }
  iStack_28 = *(int *)(in_ECX + 0x94) + iStack_30;
  auStack_3c[0] = *(int *)(in_ECX + 0x7c) != 0;
  (**(code **)(**(int **)(in_ECX + 0x78) + 0xc))(auStack_3c);
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(in_ECX + 0x88);
  if (uStack_8 < 0x10) {
    return CONCAT31((int3)((uint)*(undefined4 *)(in_ECX + 0x88) >> 8),1);
  }
  _free(pvStack_1c);
  return extraout_EAX;
}


// ==== FUN_0055a820 @ 0x0055a820 ====

void FUN_0055a820(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  bool bVar3;
  float fVar4;
  bool abStack_78 [28];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 auStack_40 [4];
  bool bStack_3c;
  void *pvStack_20;
  uint uStack_c;
  
  uVar2 = (**(code **)(**(int **)(in_ECX + 0x74) + 0x10))();
  FUN_005041e0(uVar2);
  uVar2 = (**(code **)(**(int **)(in_ECX + 0x70) + 0x10))();
  FUN_005041e0(uVar2);
  abStack_78[0] = *(int *)(in_ECX + 0x7c) < 1;
  if (abStack_78[0]) {
    fVar4 = 0.0;
  }
  else {
    fVar4 = (float)(*(int *)(in_ECX + 0x90) - *(int *)(in_ECX + 0x94)) /
            (float)*(int *)(in_ECX + 0x7c);
  }
  bStack_3c = !abStack_78[0];
  abStack_78[0] = !abStack_78[0];
  *(float *)(in_ECX + 0xa8) = fVar4;
  (**(code **)(**(int **)(in_ECX + 0x70) + 0xc))(abStack_78);
  (**(code **)(**(int **)(in_ECX + 0x74) + 0xc))(auStack_40);
  iVar1 = *(int *)(in_ECX + 0x7c);
  bVar3 = false;
  if (iVar1 == 0) {
    if (*(char *)(in_ECX + 0x45) != '\0') {
      (**(code **)(**(int **)(in_ECX + 4) + 0x44))(0);
      *(undefined1 *)(in_ECX + 0x45) = 0;
    }
    iVar1 = *(int *)(in_ECX + 0x7c);
    bVar3 = iVar1 == 0;
  }
  if ((!bVar3 && -1 < iVar1) && (*(char *)(in_ECX + 0x45) == '\0')) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x44))(1);
    *(undefined1 *)(in_ECX + 0x45) = 1;
  }
  if (0xf < uStack_48) {
    _free(pvStack_5c);
    return;
  }
  uStack_4c = 0;
  pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
  uStack_48 = 0xf;
  if (uStack_c < 0x10) {
    return;
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_0055a920 @ 0x0055a920 ====

void FUN_0055a920(void)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  
  in_ECX[0x22] = in_ECX[0x1f];
  cVar1 = FUN_0055a760();
  if (cVar1 != '\0') {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar2 + 0x80))(6,in_ECX[0x22]);
  }
  return;
}


// ==== FUN_0055a960 @ 0x0055a960 ====

undefined4 FUN_0055a960(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x44) != '\0') {
    return 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  piVar3 = (int *)(**(code **)(*DAT_00b5a7bc + 4))();
  *(int **)(in_ECX + 0x40) = piVar3;
  if (piVar3 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar3 + 4))(param_1 + 0x1c);
    if (cVar2 != '\0') {
      iVar1 = **(int **)(in_ECX + 0x40);
      uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
      cVar2 = (**(code **)(iVar1 + 0x18))(uVar4);
      if (cVar2 != '\0') {
        *(undefined1 *)(in_ECX + 0x44) = 1;
        uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
        FUN_00552120(uVar4);
        return 1;
      }
    }
    (**(code **)(*DAT_00b5a7bc + 8))(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  return 0;
}


// ==== FUN_0055aa00 @ 0x0055aa00 ====

void FUN_0055aa00(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = in_ECX[0x22];
  if (0 < iVar1) {
    if (iVar1 < in_ECX[0x20]) {
      in_ECX[0x22] = 0;
    }
    else {
      in_ECX[0x22] = iVar1 - in_ECX[0x20];
    }
    cVar2 = FUN_0055a760();
    if (cVar2 != '\0') {
      piVar3 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar3 + 0x80))(6,in_ECX[0x22]);
    }
  }
  return;
}


// ==== FUN_0055aa60 @ 0x0055aa60 ====

void FUN_0055aa60(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar1 = in_ECX[0x22];
  iVar2 = in_ECX[0x1f];
  if (iVar1 < iVar2) {
    if (in_ECX[0x20] + iVar2 < iVar1) {
      in_ECX[0x22] = iVar2;
    }
    else {
      in_ECX[0x22] = in_ECX[0x20] + iVar1;
    }
    cVar3 = FUN_0055a760();
    if (cVar3 != '\0') {
      piVar4 = (int *)(**(code **)(*in_ECX + 0x3c))();
      (**(code **)(*piVar4 + 0x80))(6,in_ECX[0x22]);
    }
  }
  return;
}


// ==== FUN_0055aac0 @ 0x0055aac0 ====

void FUN_0055aac0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x7c) != param_1) {
    *(undefined4 *)(in_ECX + 0x8c) = 0xffffffff;
    *(int *)(in_ECX + 0x7c) = param_1;
    FUN_0055a820();
    if (param_1 == 0) {
      *(undefined4 *)(in_ECX + 0x88) = 0;
      FUN_0055a760();
      return;
    }
    if (param_1 < *(int *)(in_ECX + 0x88)) {
      *(int *)(in_ECX + 0x88) = param_1;
    }
    FUN_0055a760();
  }
  return;
}


// ==== FUN_0055ab10 @ 0x0055ab10 ====

void FUN_0055ab10(int param_1)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  
  in_ECX[0x22] = param_1;
  cVar1 = FUN_0055a760();
  if (cVar1 != '\0') {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x3c))();
    (**(code **)(*piVar2 + 0x80))(6,in_ECX[0x22]);
  }
  return;
}


// ==== FUN_0055ab50 @ 0x0055ab50 ====

void FUN_0055ab50(int *param_1)

{
  int *in_ECX;
  
  in_ECX[0x23] = -1;
  in_ECX[0x1f] = param_1[0xe];
  in_ECX[0x20] = param_1[0xf];
  in_ECX[0x26] = *param_1;
  in_ECX[0x27] = param_1[1];
  in_ECX[0x28] = param_1[2];
  in_ECX[0x22] = 0;
  FUN_0055a820();
  FUN_0055a760();
  (**(code **)(*in_ECX + 0xc))(in_ECX + 0x12);
  return;
}


// ==== FUN_0055ac40 @ 0x0055ac40 ====

void FUN_0055ac40(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  void *unaff_EBX;
  void *unaff_ESI;
  undefined4 uStack_10c;
  uint uStack_100;
  uint uStack_fc;
  uint uStack_f8;
  int iStack_f0;
  int iStack_e8;
  void *pvStack_dc;
  undefined4 uStack_cc;
  uint uStack_c8;
  int iStack_b4;
  int iStack_ac;
  void *pvStack_a0;
  undefined4 uStack_90;
  uint uStack_8c;
  int iStack_78;
  int iStack_70;
  void *pvStack_64;
  undefined4 uStack_54;
  uint uStack_50;
  int iStack_3c;
  int iStack_34;
  void *pvStack_28;
  uint uStack_14;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__upbtn_009bbc2c);
  FUN_00402220(&uStack_10c,uVar2);
  iVar3 = (**(code **)(*piVar1 + 0x4c))(&uStack_10c);
  in_ECX[0x1c] = iVar3;
  if (0xf < uStack_f8) {
    _free(uStack_10c);
    return;
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__downbtn_009bbc34);
  FUN_00402220((int)register0x00000010 + -0x110,uVar2);
  iVar3 = (**(code **)(*piVar1 + 0x4c))((int)register0x00000010 + -0x110);
  in_ECX[0x1d] = iVar3;
  if (0xf < uStack_fc) {
    _free(unaff_EBX);
    return;
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*(int *)in_ECX[1] + 0x50))(&DAT_009bbc40);
  FUN_00402220((int)register0x00000010 + -0x114,uVar2);
  iVar3 = (**(code **)(*piVar1 + 0x4c))((int)register0x00000010 + -0x114);
  in_ECX[0x1e] = iVar3;
  if (0xf < uStack_100) {
    _free(unaff_ESI);
    return;
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0x3c))();
  uVar2 = (**(code **)(*piVar1 + 0x10))();
  FUN_005041e0(uVar2);
  uVar2 = (**(code **)(*(int *)in_ECX[0x1c] + 0x10))();
  FUN_005041e0(uVar2);
  uVar2 = (**(code **)(*(int *)in_ECX[0x1d] + 0x10))();
  FUN_005041e0(uVar2);
  uVar2 = (**(code **)(*(int *)in_ECX[0x1e] + 0x10))();
  FUN_005041e0(uVar2);
  in_ECX[0x21] = iStack_70 - iStack_78;
  in_ECX[0x25] = iStack_e8 - iStack_f0;
  in_ECX[0x24] = (((iStack_34 - iStack_3c) - iStack_ac) - iStack_70) + iStack_b4 + iStack_78;
  uStack_fc = uStack_fc & 0xffffff00;
  (**(code **)(*(int *)in_ECX[0x1e] + 0xc))(&uStack_fc);
  if (0xf < uStack_c8) {
    _free(pvStack_dc);
    return;
  }
  uStack_c8 = 0xf;
  uStack_cc = 0;
  pvStack_dc = (void *)((uint)pvStack_dc & 0xffffff00);
  if (0xf < uStack_8c) {
    _free(pvStack_a0);
    return;
  }
  uStack_8c = 0xf;
  uStack_90 = 0;
  pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
  if (0xf < uStack_50) {
    _free(pvStack_64);
    return;
  }
  uStack_50 = 0xf;
  uStack_54 = 0;
  pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
  if (uStack_14 < 0x10) {
    return;
  }
  _free(pvStack_28);
  return;
}


// ==== FUN_0055ae70 @ 0x0055ae70 ====

undefined4 FUN_0055ae70(int param_1,int param_2,int param_3,ushort param_4)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 extraout_EAX;
  int *piVar7;
  undefined4 *******pppppppuVar8;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 *puVar9;
  uint uVar10;
  int *in_ECX;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *******apppppppuStack_28 [3];
  int iStack_1c;
  undefined4 uStack_14;
  uint local_10;
  
  bVar2 = false;
  if (param_1 == 1) {
    bVar2 = true;
    uVar5 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__upbtn_009bbc2c);
    FUN_00402220(apppppppuStack_28,uVar5);
    pppppppuVar8 = apppppppuStack_28[1];
    if (local_10 < 0x10) {
      pppppppuVar8 = apppppppuStack_28 + 1;
    }
    iVar6 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),pppppppuVar8,uStack_14);
    if ((iVar6 != 0) || (bVar3 = true, param_3 != 1)) goto LAB_0055aede;
  }
  else {
LAB_0055aede:
    bVar3 = false;
  }
  if ((bVar2) && (0xf < local_10)) {
    _free(apppppppuStack_28[1]);
    return extraout_EAX;
  }
  bVar2 = false;
  if (bVar3) {
    iVar6 = in_ECX[0x22];
    if (0 < iVar6) {
      if (iVar6 < in_ECX[0x20]) {
        in_ECX[0x22] = 0;
      }
      else {
        in_ECX[0x22] = iVar6 - in_ECX[0x20];
      }
    }
  }
  else {
    if (param_1 == 1) {
      bVar2 = true;
      uVar5 = (**(code **)(*(int *)in_ECX[1] + 0x50))(s__downbtn_009bbc34);
      FUN_00402220(apppppppuStack_28,uVar5);
      pppppppuVar8 = apppppppuStack_28[1];
      if (local_10 < 0x10) {
        pppppppuVar8 = apppppppuStack_28 + 1;
      }
      iVar6 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),pppppppuVar8,uStack_14);
      if ((iVar6 != 0) || (bVar3 = true, param_3 != 1)) goto LAB_0055afb9;
    }
    else {
LAB_0055afb9:
      bVar3 = false;
    }
    if ((bVar2) && (0xf < local_10)) {
      _free(apppppppuStack_28[1]);
      return extraout_EAX_00;
    }
    bVar2 = false;
    if (!bVar3) {
      if (param_1 == 0) {
        bVar2 = true;
        uVar5 = (**(code **)(*(int *)in_ECX[1] + 0x50))(&DAT_009bbc40);
        FUN_00402220(apppppppuStack_28,uVar5);
        cVar4 = FUN_00423420(param_2,apppppppuStack_28);
        if ((cVar4 == '\0') || (bVar3 = true, param_3 != 7)) goto LAB_0055b054;
      }
      else {
LAB_0055b054:
        bVar3 = false;
      }
      if ((bVar2) && (0xf < local_10)) {
        _free(apppppppuStack_28[1]);
        return extraout_EAX_01;
      }
      if (!bVar3) {
        return 0;
      }
      puVar9 = (undefined4 *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
      iVar6 = in_ECX[0x24];
      iVar1 = in_ECX[0x25];
      pppppppuVar8 = apppppppuStack_28;
      for (iVar11 = 10; iVar11 != 0; iVar11 = iVar11 + -1) {
        *pppppppuVar8 = (undefined4 ******)*puVar9;
        puVar9 = puVar9 + 1;
        pppppppuVar8 = pppppppuVar8 + 1;
      }
      uVar12 = in_ECX[0x21] + iStack_1c;
      uVar10 = (iVar6 - iVar1) + uVar12;
      uVar13 = (uint)param_4;
      if ((int)(uint)param_4 <= (int)uVar12) {
        uVar13 = uVar12;
      }
      if ((int)uVar10 < (int)uVar13) {
        uVar13 = uVar10;
      }
      in_ECX[0x22] = (int)(((float)(int)(uVar13 - uVar12) / (float)(int)(uVar10 - uVar12)) *
                          (float)in_ECX[0x1f]);
      cVar4 = FUN_0055a760();
      goto joined_r0x0055b0e5;
    }
    iVar6 = in_ECX[0x22];
    iVar1 = in_ECX[0x1f];
    if (iVar6 < iVar1) {
      if (iVar1 + in_ECX[0x20] < iVar6) {
        in_ECX[0x22] = iVar1;
      }
      else {
        in_ECX[0x22] = in_ECX[0x20] + iVar6;
      }
    }
  }
  cVar4 = FUN_0055a760();
joined_r0x0055b0e5:
  if (cVar4 == '\0') {
    return 1;
  }
  piVar7 = (int *)(**(code **)(*in_ECX + 0x3c))();
  (**(code **)(*piVar7 + 0x80))(6,in_ECX[0x22]);
  return 0;
}


// ==== FUN_0055b100 @ 0x0055b100 ====

void FUN_0055b100(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbc54;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    *(undefined1 *)(in_ECX + 0x11) = 0;
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  FUN_00552170();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0055b150 @ 0x0055b150 ====

void FUN_0055b150(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbd18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0055b170 @ 0x0055b170 ====

void FUN_0055b170(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  char *pcVar5;
  int in_ECX;
  int *piVar6;
  
  piVar1 = *(int **)(in_ECX + 0xc);
  for (piVar6 = *(int **)(in_ECX + 8); piVar6 != piVar1; piVar6 = piVar6 + 1) {
    piVar2 = (int *)*piVar6;
    if ((((piVar2 != (int *)0x0) && (cVar3 = (**(code **)(*piVar2 + 0x30))(), cVar3 != '\0')) &&
        (piVar4 = (int *)(**(code **)(*piVar2 + 0x3c))(), piVar4 != (int *)0x0)) &&
       (pcVar5 = (char *)(**(code **)(*piVar4 + 0x10))(), *pcVar5 != '\0')) {
      (**(code **)(*piVar2 + 0x44))(param_1);
    }
  }
  return;
}


// ==== FUN_0055b1c0 @ 0x0055b1c0 ====

void FUN_0055b1c0(int param_1)

{
  int *_Dst;
  int in_ECX;
  
  _Dst = *(int **)(in_ECX + 8);
  if (_Dst != *(int **)(in_ECX + 0xc)) {
    while (*_Dst != param_1) {
      _Dst = _Dst + 1;
      if (_Dst == *(int **)(in_ECX + 0xc)) {
        return;
      }
    }
    _memmove(_Dst,_Dst + 1,(*(int *)(in_ECX + 0xc) - (int)(_Dst + 1) >> 2) * 4);
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -4;
  }
  return;
}


// ==== FUN_0055b210 @ 0x0055b210 ====

undefined4 FUN_0055b210(void)

{
  int *piVar1;
  code *pcVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 extraout_EAX_00;
  int in_ECX;
  int *piVar4;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  piVar1 = *(int **)(in_ECX + 0xc);
  for (piVar4 = *(int **)(in_ECX + 8); piVar4 != piVar1; piVar4 = piVar4 + 1) {
    if ((undefined4 *)*piVar4 == (undefined4 *)0x0) {
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401740(s_pControl____NULL_009bbce8,0x10);
      FUN_00406880(local_1c);
      if (local_4 < 0x10) {
        local_4 = 0xf;
        local_8 = 0;
        local_18 = (void *)((uint)local_18 & 0xffffff00);
        pcVar2 = (code *)swi(3);
        uVar3 = (*pcVar2)();
        return uVar3;
      }
      _free(local_18);
      return extraout_EAX;
    }
    (*(code *)**(undefined4 **)*piVar4)(1);
  }
  if (*(void **)(in_ECX + 8) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    return 0;
  }
  _free(*(void **)(in_ECX + 8));
  return extraout_EAX_00;
}


// ==== FUN_0055b2b0 @ 0x0055b2b0 ====

int * FUN_0055b2b0(int param_1)

{
  int *piVar1;
  code *pcVar2;
  int *extraout_EAX;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  piVar3 = *(int **)(in_ECX + 0xc);
  piVar6 = *(int **)(in_ECX + 8);
  while( true ) {
    if (piVar6 == piVar3) {
      return (int *)0x0;
    }
    piVar1 = (int *)*piVar6;
    if (piVar1 == (int *)0x0) break;
    piVar4 = (int *)(**(code **)(*piVar1 + 0x3c))();
    iVar5 = (**(code **)(*piVar4 + 4))();
    if (iVar5 == param_1) {
      return piVar1;
    }
    piVar6 = piVar6 + 1;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pControl____NULL_009bbcfc,0x10);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    pcVar2 = (code *)swi(3);
    piVar3 = (int *)(*pcVar2)();
    return piVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0055b350 @ 0x0055b350 ====

void FUN_0055b350(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbd34;
  FUN_0055b210();
  DAT_00b5a7a8 = 0;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009bbd18;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0055b390 @ 0x0055b390 ====

void FUN_0055b390(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbd34;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a7a8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a7a8 = in_ECX;
  return;
}


// ==== FUN_0055b3c0 @ 0x0055b3c0 ====

void FUN_0055b3c0(int *param_1)

{
  int iVar1;
  undefined1 uStack00000000;
  
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x18))();
    if (iVar1 != 2) {
      iVar1 = (**(code **)(*param_1 + 0x18))();
      if (iVar1 != 0x15) {
        iVar1 = (**(code **)(*param_1 + 0x18))();
        if (iVar1 != 6) {
          (**(code **)(*param_1 + 0x2c))(0);
          FUN_0055b6d0(&uStack00000000);
          return;
        }
      }
    }
    (**(code **)(*param_1 + 0x2c))(1);
    FUN_0055b6d0(&uStack00000000);
  }
  return;
}


// ==== FUN_0055b430 @ 0x0055b430 ====

void FUN_0055b430(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981f60;
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


// ==== Catch@0055b591 @ 0x0055b591 ====

void Catch_0055b591(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0055b680 @ 0x0055b680 ====

void FUN_0055b680(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbd34;
  FUN_0055b210();
  DAT_00b5a7a8 = 0;
  if ((void *)in_ECX[2] != (void *)0x0) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_009bbd18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0055b6d0 @ 0x0055b6d0 ====

void FUN_0055b6d0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_0055b430(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_0055b720 @ 0x0055b720 ====

void FUN_0055b720(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbd98;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0055b740 @ 0x0055b740 ====

undefined4 FUN_0055b740(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  pvVar1 = operator_new(0xc4);
  if (pvVar1 == (void *)0x0) {
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
    return 0;
  }
  uVar2 = FUN_0056bb00(*(undefined4 *)(in_ECX + 4));
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  return uVar2;
}


// ==== FUN_0055b770 @ 0x0055b770 ====

void FUN_0055b770(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbdb0;
  in_ECX[1] = 0x600000;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a7ac = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a7ac = in_ECX;
  return;
}


// ==== FUN_0055b7a0 @ 0x0055b7a0 ====

undefined4 FUN_0055b7a0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(1);
  }
  return 1;
}


// ==== FUN_0055b7c0 @ 0x0055b7c0 ====

undefined4 FUN_0055b7c0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)(*DAT_00b5a7a8 + 8))(param_1);
    (**(code **)*param_1)(1);
  }
  return 1;
}


// ==== FUN_0055b810 @ 0x0055b810 ====

undefined4 FUN_0055b810(undefined4 param_1)

{
  code *pcVar1;
  void *pvVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  switch(param_1) {
  case 0:
    pvVar2 = operator_new(0xcc);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00588410();
      goto LAB_0055bbd8;
    }
    break;
  case 1:
    pvVar2 = operator_new(0x120);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00558b00();
      goto LAB_0055bbd8;
    }
    break;
  case 2:
    pvVar2 = operator_new(0x16c);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_005505b0();
      goto LAB_0055bbd8;
    }
    break;
  case 3:
    pvVar2 = operator_new(0x8c);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00587c20();
      goto LAB_0055bbd8;
    }
    break;
  case 4:
    pvVar2 = operator_new(0xac);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_0055a6e0();
      goto LAB_0055bbd8;
    }
    break;
  case 5:
    pvVar2 = operator_new(0xd8);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00586b50();
      goto LAB_0055bbd8;
    }
    break;
  case 6:
    pvVar2 = operator_new(0x1a0);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00553d90();
      goto LAB_0055bbd8;
    }
    break;
  case 7:
    pvVar2 = operator_new(0xf8);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00584bd0();
      goto LAB_0055bbd8;
    }
    break;
  case 8:
    pvVar2 = operator_new(0xcc);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_005593e0();
      goto LAB_0055bbd8;
    }
    break;
  case 9:
    pvVar2 = operator_new(0x90);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00583070();
      goto LAB_0055bbd8;
    }
    break;
  case 10:
    pvVar2 = operator_new(0xd8);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00581310();
      goto LAB_0055bbd8;
    }
    break;
  case 0xb:
    pvVar2 = operator_new(0xc4);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00582240();
      goto LAB_0055bbd8;
    }
    break;
  case 0xc:
    pvVar2 = operator_new(0xa0);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_0057db50();
      goto LAB_0055bbd8;
    }
    break;
  case 0xd:
    pvVar2 = operator_new(0x90);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_0057bbe0();
      goto LAB_0055bbd8;
    }
    break;
  case 0xe:
    pvVar2 = operator_new(200);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00574200();
      goto LAB_0055bbd8;
    }
    break;
  case 0xf:
    pvVar2 = operator_new(0xf4);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_0057f750();
      goto LAB_0055bbd8;
    }
    break;
  default:
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_false_009bbd88,5);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(local_18);
    return extraout_EAX;
  case 0x12:
    pvVar2 = operator_new(0xe0);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_0057b400();
      goto LAB_0055bbd8;
    }
    break;
  case 0x13:
    pvVar2 = operator_new(0x110);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_0057a570();
      goto LAB_0055bbd8;
    }
    break;
  case 0x14:
    pvVar2 = operator_new(0x94);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00579830();
      goto LAB_0055bbd8;
    }
    break;
  case 0x15:
    pvVar2 = operator_new(0xf4);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00578120();
      goto LAB_0055bbd8;
    }
    break;
  case 0x16:
    pvVar2 = operator_new(0xf0);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_005761d0();
      goto LAB_0055bbd8;
    }
    break;
  case 0x17:
    pvVar2 = operator_new(0xf8);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_005720b0();
      goto LAB_0055bbd8;
    }
    break;
  case 0x18:
    pvVar2 = operator_new(0xbc);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00570620();
      goto LAB_0055bbd8;
    }
    break;
  case 0x19:
    pvVar2 = operator_new(0xe0);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_0056f7d0();
      goto LAB_0055bbd8;
    }
    break;
  case 0x1a:
    pvVar2 = operator_new(0x160);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_0056d880();
      goto LAB_0055bbd8;
    }
  }
  uVar3 = 0;
LAB_0055bbd8:
  (**(code **)(*DAT_00b5a7a8 + 4))(uVar3);
  return uVar3;
}


// ==== FUN_0055bc60 @ 0x0055bc60 ====

void FUN_0055bc60(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5a7ac = 0;
  *in_ECX = &PTR_FUN_009bbd98;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0055bc90 @ 0x0055bc90 ====

void FUN_0055bc90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbe08;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0055bcb0 @ 0x0055bcb0 ====

void FUN_0055bcb0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  
  piVar2 = param_1;
  iVar1 = param_1[2];
  if (((iVar1 == 1) || (iVar1 == 5)) || (iVar1 == 3)) {
    piVar3 = (int *)(**(code **)(*DAT_00b5a7a0 + 0x28))();
    param_1 = (int *)(**(code **)(*piVar2 + 0x10))();
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)(**(code **)(*DAT_00b5a7a0 + 0x2c))(&param_1);
    }
    else {
      piVar3 = (int *)(**(code **)(*piVar3 + 0x30))(&param_1);
    }
    if (piVar3 != (int *)0x0) {
      piVar4 = (int *)(**(code **)(*DAT_00b5a7a0 + 0x2c))((undefined4 *)(in_ECX + 4));
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x60))();
      }
      uVar5 = (**(code **)(*piVar2 + 0x10))();
      *(undefined4 *)(in_ECX + 4) = uVar5;
      (**(code **)(*piVar3 + 0x5c))();
    }
  }
  return;
}


// ==== FUN_0055bd40 @ 0x0055bd40 ====

void FUN_0055bd40(void)

{
  int *piVar1;
  int in_ECX;
  undefined1 uStack00000000;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a7a0 + 0x2c))((undefined4 *)(in_ECX + 4));
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x60))();
  }
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(_uStack00000000 + 4);
  piVar1 = (int *)(**(code **)(*DAT_00b5a7a0 + 0x2c))(&uStack00000000);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x5c))();
  }
  return;
}


// ==== FUN_0055bd90 @ 0x0055bd90 ====

void FUN_0055bd90(int param_1)

{
  int *_Memory;
  int in_ECX;
  
  for (_Memory = (int *)**(int **)(in_ECX + 0xc);
      (_Memory != *(int **)(in_ECX + 0xc) && (_Memory[2] != param_1)); _Memory = (int *)*_Memory) {
  }
  if (_Memory == *(int **)(in_ECX + 0xc)) {
    return;
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  _free(_Memory);
  return;
}


// ==== FUN_0055bdd0 @ 0x0055bdd0 ====

undefined4 FUN_0055bdd0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  undefined4 unaff_retaddr;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5a7a0 + 0x2c))(in_ECX + 4);
  if ((piVar4 == (int *)0x0) ||
     ((((piVar5 = (int *)(**(code **)(*piVar4 + 0x38))(), piVar5 == (int *)0x0 ||
        (piVar5 = (int *)(**(code **)(*piVar5 + 0x4c))(), piVar5 == (int *)0x0)) ||
       (cVar3 = (**(code **)(*piVar5 + 4))(unaff_retaddr), cVar3 != '\x01')) &&
      (cVar3 = (**(code **)(*piVar4 + 0x1c))(unaff_retaddr), cVar3 != '\x01')))) {
    puVar1 = *(undefined4 **)(in_ECX + 0xc);
    puVar2 = (undefined4 *)*puVar1;
    while( true ) {
      if (puVar2 == puVar1) {
        return 0;
      }
      cVar3 = (**(code **)(*(int *)puVar2[2] + 4))(unaff_retaddr);
      if (cVar3 != '\0') break;
      puVar2 = (undefined4 *)*puVar2;
    }
  }
  return 1;
}


// ==== FUN_0055be50 @ 0x0055be50 ====

void FUN_0055be50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbe20;
  DAT_00b5a79c = 0;
  FUN_008984a0();
  *in_ECX = &PTR_FUN_009bbe08;
  return;
}


// ==== FUN_0055be80 @ 0x0055be80 ====

undefined4 FUN_0055be80(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  
  cVar3 = (**(code **)(*param_1 + 0xc))();
  if (cVar3 != '\0') {
    uVar4 = FUN_0055bdd0(param_1);
    return uVar4;
  }
  iVar5 = (**(code **)(*param_1 + 4))();
  if (iVar5 == 0x10001) {
    FUN_0055bcb0(param_1);
  }
  else if (iVar5 == -0x70000000) {
    FUN_0055bd40(param_1);
    return 1;
  }
  if ((DAT_00b5a7a0 != (int *)0x0) &&
     (cVar3 = (**(code **)(*DAT_00b5a7a0 + 0xc))(param_1), cVar3 != '\0')) {
    return 1;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      return 0;
    }
    cVar3 = (**(code **)(*(int *)puVar2[2] + 4))(param_1);
    if (cVar3 != '\0') break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return 1;
}


// ==== FUN_0055bf20 @ 0x0055bf20 ====

void FUN_0055bf20(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbe20;
  uVar1 = FUN_0055bff0();
  in_ECX[3] = uVar1;
  in_ECX[4] = 0;
  in_ECX[1] = 0xffffffff;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a79c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a79c = in_ECX;
  return;
}


// ==== FUN_0055bf70 @ 0x0055bf70 ====

void FUN_0055bf70(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = FUN_0055c080(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}


// ==== FUN_0055bfb0 @ 0x0055bfb0 ====

void FUN_0055bfb0(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = **(int **)(in_ECX + 0xc);
  iVar2 = FUN_0055c080(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}


// ==== FUN_0055bff0 @ 0x0055bff0 ====

void FUN_0055bff0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981f70;
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


// ==== Catch@0055c05f @ 0x0055c05f ====

void Catch_0055c05f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0055c080 @ 0x0055c080 ====

void FUN_0055c080(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981f80;
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


// ==== Catch@0055c0e9 @ 0x0055c0e9 ====

void Catch_0055c0e9(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0055c100 @ 0x0055c100 ====

void FUN_0055c100(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbe20;
  DAT_00b5a79c = 0;
  FUN_008984a0();
  *in_ECX = &PTR_FUN_009bbe08;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0055c140 @ 0x0055c140 ====

void FUN_0055c140(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbeac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0055c160 @ 0x0055c160 ====

void FUN_0055c160(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined1 auStack_22 [2];
  undefined4 auStack_20 [7];
  int *piStack_4;
  
  if ((uint)in_ECX[6] < (uint)in_ECX[8]) {
    (**(code **)(*in_ECX + 0x14))(param_1);
    in_ECX[9] = *param_1;
    return;
  }
  piVar2 = (int *)(**(code **)(*in_ECX + 0x24))(param_1);
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x14))();
  iVar1 = in_ECX[8];
  puVar5 = (undefined4 *)(auStack_22 + -6);
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  in_ECX[8] = iVar1 + 0x10000;
  (**(code **)(*piVar2 + 0x18))(auStack_22 + -6);
  in_ECX[9] = *piStack_4;
  return;
}


// ==== FUN_0055c1e0 @ 0x0055c1e0 ====

undefined4 FUN_0055c1e0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 0xc);
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  while( true ) {
    if (puVar3 == puVar1) {
      return 0;
    }
    iVar2 = (**(code **)(*(int *)*puVar3 + 4))();
    if (iVar2 == *param_1) break;
    puVar3 = puVar3 + 1;
  }
  return *puVar3;
}


// ==== FUN_0055c220 @ 0x0055c220 ====

int * FUN_0055c220(void)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int in_ECX;
  int *piVar4;
  
  piVar1 = *(int **)(in_ECX + 0x10);
  piVar4 = *(int **)(in_ECX + 0xc);
  while( true ) {
    if (piVar4 == piVar1) {
      return (int *)0x0;
    }
    piVar2 = (int *)*piVar4;
    if ((piVar2 != (int *)0x0) && (cVar3 = (**(code **)(*piVar2 + 0x50))(), cVar3 != '\0')) break;
    piVar4 = piVar4 + 1;
  }
  return piVar2;
}


// ==== FUN_0055c260 @ 0x0055c260 ====

int FUN_0055c260(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  puVar3 = *(undefined4 **)(in_ECX + 0xc);
  while( true ) {
    if (puVar3 == puVar1) {
      return 0;
    }
    iVar2 = (**(code **)(*(int *)*puVar3 + 0x30))(param_1);
    if (iVar2 != 0) break;
    puVar3 = puVar3 + 1;
  }
  return iVar2;
}


// ==== FUN_0055c290 @ 0x0055c290 ====

undefined4 FUN_0055c290(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xc) == 0) || (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc) >> 2 == 0))
  {
    return 0;
  }
  *(undefined4 **)(in_ECX + 4) = *(undefined4 **)(in_ECX + 0xc);
  return **(undefined4 **)(in_ECX + 0xc);
}


// ==== FUN_0055c2c0 @ 0x0055c2c0 ====

undefined4 FUN_0055c2c0(void)

{
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0xc) != 0) && (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc) >> 2 != 0)
      ) && (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 0x10))) {
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 4;
    if (*(undefined4 **)(in_ECX + 4) != *(undefined4 **)(in_ECX + 0x10)) {
      return **(undefined4 **)(in_ECX + 4);
    }
  }
  return 0;
}


// ==== FUN_0055c300 @ 0x0055c300 ====

void FUN_0055c300(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbee8;
  DAT_00b5a7a0 = 0;
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009bbeac;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_0055c340 @ 0x0055c340 ====

undefined4 FUN_0055c340(void)

{
  int *_Dst;
  int *piVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  _Dst = *(int **)(in_ECX + 0xc);
  piVar1 = *(int **)(in_ECX + 0x10);
  if (_Dst == piVar1) {
    *(int **)(in_ECX + 4) = piVar1;
    return CONCAT31((int3)((uint)piVar1 >> 8),1);
  }
  do {
    do {
      puVar2 = (undefined4 *)*_Dst;
      _memmove(_Dst,_Dst + 1,(*(int *)(in_ECX + 0x10) - (int)(_Dst + 1) >> 2) * 4);
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + -4;
    } while (puVar2 == (undefined4 *)0x0);
    (**(code **)*puVar2)(1);
  } while( true );
}


// ==== FUN_0055c390 @ 0x0055c390 ====

undefined4 FUN_0055c390(int param_1)

{
  int *_Dst;
  int in_ECX;
  
  _Dst = *(int **)(in_ECX + 0xc);
  *(int **)(in_ECX + 4) = *(int **)(in_ECX + 0x10);
  while( true ) {
    if (_Dst == *(int **)(in_ECX + 0x10)) {
      return 0;
    }
    if (*_Dst == param_1) break;
    _Dst = _Dst + 1;
  }
  _memmove(_Dst,_Dst + 1,(*(int *)(in_ECX + 0x10) - (int)(_Dst + 1) >> 2) * 4);
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + -4;
  return 1;
}


// ==== FUN_0055c3e0 @ 0x0055c3e0 ====

undefined4 FUN_0055c3e0(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int *piVar6;
  int *in_ECX;
  undefined4 *puVar7;
  undefined4 *puStack_48;
  undefined4 uStack_44;
  undefined4 *puStack_40;
  int *local_3c;
  undefined1 auStack_38 [4];
  undefined1 uStack_34;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  void *pvStack_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  local_3c = in_ECX;
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 == 0x10001) {
    puStack_48 = (undefined4 *)in_ECX[3];
    puStack_40 = (undefined4 *)in_ECX[4];
    if (puStack_48 != puStack_40) {
      do {
        piVar6 = (int *)*puStack_48;
        uStack_44 = (**(code **)(*param_1 + 0x10))();
        piVar4 = (int *)(**(code **)(*piVar6 + 0x30))(&uStack_44);
        if (piVar4 != (int *)0x0) {
          uStack_20 = 0xf;
          uStack_24 = 0;
          uStack_34 = 0;
          FUN_00401740(s_window_under_cursor_009bbe70,0x13);
          uVar5 = (**(code **)(*piVar6 + 0x10))();
          (**(code **)(*DAT_00b5a688 + 8))(auStack_38,uVar5);
          if (0xf < uStack_28) {
            _free(local_3c);
            return extraout_EAX;
          }
          uStack_28 = 0xf;
          uStack_2c = 0;
          local_3c = (int *)((uint)local_3c & 0xffffff00);
          uStack_c = 0xf;
          uStack_10 = 0;
          uStack_20 = uStack_20 & 0xffffff00;
          FUN_00401740(s_control_under_cursor_009bbe84,0x14);
          uVar5 = (**(code **)(*piVar4 + 0x50))();
          (**(code **)(*DAT_00b5a688 + 8))(&uStack_24,uVar5);
          if (0xf < uStack_4) {
            _free(pvStack_18);
            return extraout_EAX_00;
          }
          uStack_4 = 0xf;
          uStack_8 = 0;
          pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        }
        puStack_48 = puStack_48 + 1;
      } while (puStack_48 != puStack_40);
      in_ECX = local_3c;
    }
  }
  piVar6 = (int *)(**(code **)(*in_ECX + 0x28))();
  if (piVar6 == (int *)0x0) {
    puVar1 = (undefined4 *)in_ECX[4];
    for (puVar7 = (undefined4 *)in_ECX[3]; puVar7 != puVar1; puVar7 = puVar7 + 1) {
      piVar6 = (int *)*puVar7;
      piVar4 = (int *)(**(code **)(*piVar6 + 0x2c))();
      cVar2 = (**(code **)(*piVar4 + 0x28))();
      if ((cVar2 != '\0') && (cVar2 = (**(code **)(*piVar6 + 0x1c))(param_1), cVar2 == '\x01')) {
        return 1;
      }
    }
  }
  else {
    cVar2 = (**(code **)(*piVar6 + 0x1c))(param_1);
    if (cVar2 == '\x01') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0055c580 @ 0x0055c580 ====

void FUN_0055c580(int *param_1)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint *puVar7;
  int *in_ECX;
  undefined4 *puVar8;
  uint *puVar9;
  undefined1 local_64 [4];
  void *local_60;
  undefined4 local_50;
  uint local_4c [4];
  int iStack_3c;
  undefined4 auStack_24 [4];
  int iStack_14;
  
  piVar6 = (int *)in_ECX[3];
  in_ECX[8] = in_ECX[7];
  piVar1 = (int *)in_ECX[4];
  while( true ) {
    if (piVar6 == piVar1) {
      piVar6 = (int *)(**(code **)(*in_ECX + 0x24))(param_1);
      puVar7 = (uint *)(**(code **)(*piVar6 + 0x14))();
      iStack_3c = in_ECX[8];
      puVar9 = local_4c;
      for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      in_ECX[8] = iStack_3c + 0x10000;
      (**(code **)(*piVar6 + 0x18))(local_4c);
      return;
    }
    piVar2 = (int *)*piVar6;
    if (piVar2 == (int *)0x0) break;
    iVar4 = (**(code **)(*piVar2 + 4))();
    if (iVar4 != *param_1) {
      puVar5 = (undefined4 *)(**(code **)(*piVar2 + 0x14))();
      iStack_14 = in_ECX[8];
      puVar8 = auStack_24;
      for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar8 = puVar8 + 1;
      }
      in_ECX[8] = iStack_14 + 0x10000;
      (**(code **)(*piVar2 + 0x18))(auStack_24);
    }
    piVar6 = piVar6 + 1;
  }
  local_4c[0] = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  FUN_00401740(s_pWindow_009bbe9c,7);
  FUN_00406880(local_64);
  if (local_4c[0] < 0x10) {
    local_4c[0] = 0xf;
    local_50 = 0;
    local_60 = (void *)((uint)local_60 & 0xffffff00);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  _free(local_60);
  return;
}


// ==== FUN_0055c6b0 @ 0x0055c6b0 ====

void FUN_0055c6b0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbee8;
  puVar1 = in_ECX + 1;
  *puVar1 = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a7a0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a7a0 = in_ECX;
  }
  in_ECX[9] = 0;
  in_ECX[7] = 0x10010000;
  in_ECX[8] = 0x10010000;
  in_ECX[6] = 0x1f000000;
  *puVar1 = in_ECX[4];
  return;
}


// ==== FUN_0055c700 @ 0x0055c700 ====

undefined4 FUN_0055c700(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x10) - iVar1 >> 2)))
  {
    FUN_0055c7d0(*(undefined4 *)(in_ECX + 0x10),1,&param_1);
    *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0x10);
    return CONCAT31((int3)((uint)*(undefined4 *)(in_ECX + 0x10) >> 8),1);
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x10);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x10) = puVar2 + 1;
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0x10);
  return CONCAT31((int3)((uint)*(undefined4 *)(in_ECX + 0x10) >> 8),1);
}


// ==== FUN_0055c770 @ 0x0055c770 ====

undefined4 FUN_0055c770(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 0x10000;
  return *(undefined4 *)(in_ECX + 0x20);
}


// ==== FUN_0055c780 @ 0x0055c780 ====

void FUN_0055c780(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bbee8;
  DAT_00b5a7a0 = 0;
  if ((void *)in_ECX[3] != (void *)0x0) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  *in_ECX = &PTR_FUN_009bbeac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0055c7d0 @ 0x0055c7d0 ====

void FUN_0055c7d0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981f90;
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


// ==== Catch@0055c931 @ 0x0055c931 ====

void Catch_0055c931(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0055ca20 @ 0x0055ca20 ====

void FUN_0055ca20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bcd5c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0055ca40 @ 0x0055ca40 ====

void FUN_0055ca40(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = *param_2;
  in_ECX[2] = param_2[1];
  in_ECX[3] = param_2[2];
  in_ECX[4] = param_2[3];
  return;
}


// ==== FUN_0055ca70 @ 0x0055ca70 ====

undefined4 FUN_0055ca70(void)

{
  return 0x60000030;
}


// ==== FUN_0055ca80 @ 0x0055ca80 ====

void FUN_0055ca80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bcd80;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a798 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a798 = in_ECX;
  return;
}


// ==== FUN_0055cad0 @ 0x0055cad0 ====

undefined1 FUN_0055cad0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_<panel>_009bc038,7);
  if (iVar2 != 0) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_<button>_009bc040,8);
    if (iVar2 != 0) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_<edit>_009bc04c,6);
      if (iVar2 != 0) {
        cVar1 = FUN_004036a0(param_1,s_<processbar>_009bc054);
        if (cVar1 == '\0') {
          cVar1 = FUN_004036a0(param_1,s_<vscroll>_009bc064);
          if (cVar1 == '\0') {
            cVar1 = FUN_004036a0(param_1,s_<treectrl>_009bc070);
            if (cVar1 == '\0') {
              cVar1 = FUN_004036a0(param_1,s_<textbox>_009bc07c);
              if (cVar1 == '\0') {
                cVar1 = FUN_004036a0(param_1,s_<label>_009bc088);
                if (cVar1 == '\0') {
                  cVar1 = FUN_004036a0(param_1,s_<slotctrl>_009bc090);
                  if (cVar1 == '\0') {
                    cVar1 = FUN_004036a0(param_1,s_<partystate>_009bc09c);
                    if (cVar1 == '\0') {
                      cVar1 = FUN_004036a0(param_1,s_<tab>_009bc0ac);
                      if (cVar1 == '\0') {
                        cVar1 = FUN_004036a0(param_1,s_<skilltree>_009bc0b4);
                        if (cVar1 == '\0') {
                          cVar1 = FUN_004036a0(param_1,s_<item>_009bc0c0);
                          if (cVar1 == '\0') {
                            cVar1 = FUN_004036a0(param_1,s_<itemslot>_009bc0c8);
                            if (cVar1 == '\0') {
                              cVar1 = FUN_004036a0(param_1,s_<quickslot>_009bc0d4);
                              if (cVar1 == '\0') {
                                cVar1 = FUN_004036a0(param_1,s_<emoti>_009bc0e0);
                                if (cVar1 == '\0') {
                                  cVar1 = FUN_004036a0(param_1,s_<slidebar>_009bc0e8);
                                  if (cVar1 == '\0') {
                                    cVar1 = FUN_004036a0(param_1,s_<combobox>_009bc0f4);
                                    if (cVar1 == '\0') {
                                      cVar1 = FUN_004036a0(param_1,s_<messengertree>_009bc100);
                                      if (cVar1 == '\0') {
                                        cVar1 = FUN_004036a0(param_1,s_<listbox>_009bc110);
                                        if (cVar1 == '\0') {
                                          cVar1 = FUN_004036a0(param_1,s_<casebox>_009bc11c);
                                          if (cVar1 == '\0') {
                                            cVar1 = FUN_004036a0(param_1,s_<maillist>_009bc128);
                                            if (cVar1 == '\0') {
                                              cVar1 = FUN_004036a0(param_1,s_<noticectrl>_009bc134);
                                              if (cVar1 == '\0') {
                                                cVar1 = FUN_004036a0(param_1,s_<expanel>_009bc144);
                                                if (cVar1 == '\0') {
                                                  cVar1 = FUN_004036a0(param_1,
                                                  s_<buttonlist>_009bc150);
                                                  if (cVar1 == '\0') {
                                                    return 0;
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}


// ==== FUN_0055cd00 @ 0x0055cd00 ====

int FUN_0055cd00(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_center_009bc2c0,6);
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_right_009bc2c8,5);
  if (iVar1 == 0) {
    return 2;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_inverse_009bc2d0,7);
  return (-(uint)(iVar1 != 0) & 0xfffffffd) + 3;
}


// ==== FUN_0055cde0 @ 0x0055cde0 ====

void FUN_0055cde0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  uVar1 = FUN_00588600(local_1c);
  uVar1 = thunk_FUN_00796e60(uVar1);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uVar2 = FUN_00588600(local_1c);
  uVar2 = thunk_FUN_00796e60(uVar2);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uVar3 = FUN_00588600(local_1c);
  uVar3 = thunk_FUN_00796e60(uVar3);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uVar4 = FUN_00588600(local_1c);
  uVar4 = thunk_FUN_00796e60(uVar4);
  if (uStack_4 < 0x10) {
    *param_1 = uVar1;
    param_1[1] = uVar2;
    param_1[2] = uVar3;
    param_1[3] = uVar4;
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_0055cec0 @ 0x0055cec0 ====

void FUN_0055cec0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 local_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  uVar1 = FUN_00588600(local_1c);
  uVar1 = thunk_FUN_00796e60(uVar1);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
  uVar2 = FUN_00588600(local_1c);
  uVar2 = thunk_FUN_00796e60(uVar2);
  if (uStack_4 < 0x10) {
    *param_1 = uVar1;
    param_1[1] = uVar2;
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_0055cf30 @ 0x0055cf30 ====

void FUN_0055cf30(undefined1 *param_1,int param_2,undefined1 param_3,void *param_4)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 in_stack_00000020;
  uint in_stack_00000024;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  iVar3 = FUN_00403620(0,in_stack_00000020,&DAT_009bc27c,2);
  if (iVar3 == 0) {
    uVar4 = FUN_00588600(local_1c);
    FUN_00401660(uVar4,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  else {
    iVar3 = FUN_00403620(0,in_stack_00000020,s_enable_009bc280,6);
    if (iVar3 == 0) {
      uVar4 = FUN_00588600(local_1c);
      uVar1 = thunk_FUN_00796fe0(uVar4);
      param_1[1] = uVar1;
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
    }
    else {
      iVar3 = FUN_00403620(0,in_stack_00000020,s_visible_009bc288,7);
      if (iVar3 == 0) {
        uVar4 = FUN_00588600(local_1c);
        uVar1 = thunk_FUN_00796fe0(uVar4);
        *param_1 = uVar1;
        if (0xf < local_4) {
          _free(local_18);
          return;
        }
      }
      else {
        cVar2 = FUN_004036a0(&param_3,s_layer_009bc290);
        if (cVar2 != '\0') {
          uVar4 = FUN_00588600(local_1c);
          uVar4 = thunk_FUN_00796fb0(uVar4);
          *(undefined4 *)(param_1 + 4) = uVar4;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar2 = FUN_004036a0(&param_3,s_intersect_009bc298);
        if (cVar2 != '\0') {
          uVar4 = FUN_00588600(local_1c);
          uVar1 = thunk_FUN_00796fe0(uVar4);
          *(undefined1 *)(param_2 + 0xc) = uVar1;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar2 = FUN_004036a0(&param_3,&DAT_009bc2a4);
        if (cVar2 == '\0') {
          cVar2 = FUN_004036a0(&param_3,s_border_009bc2ac);
          if (cVar2 != '\0') {
            uVar4 = FUN_00588600(local_1c);
            uVar1 = thunk_FUN_00796fe0(uVar4);
            param_1[2] = uVar1;
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          cVar2 = FUN_004036a0(&param_3,s_position_009bc2b4);
          if (cVar2 != '\0') {
            uVar4 = FUN_00588600(local_1c);
            uVar4 = FUN_0055cd00(uVar4);
            *(undefined4 *)(param_1 + 0x18) = uVar4;
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
        }
        else {
          uVar4 = FUN_0055cde0(local_1c);
          FUN_004e9a10(uVar4);
          if (*(int *)(param_1 + 0x18) != 3) {
            *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + *(int *)(param_1 + 8);
          }
          if (*(int *)(param_1 + 0x1c) != 3) {
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x14);
          }
        }
      }
    }
  }
  if (in_stack_00000024 < 0x10) {
    return;
  }
  _free(param_4);
  return;
}


// ==== FUN_0055d1f0 @ 0x0055d1f0 ====

uint FUN_0055d1f0(undefined4 *param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint extraout_EAX;
  int iVar3;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  uint uVar4;
  byte ****ppppbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  uint local_b0;
  undefined1 local_a8 [4];
  byte ****local_a4 [4];
  uint local_94;
  uint local_90;
  undefined1 local_8c [4];
  void *local_88;
  undefined4 local_78;
  uint local_74;
  undefined1 local_70 [4];
  void *local_6c;
  undefined4 local_5c;
  uint local_58;
  undefined1 local_54 [4];
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  *param_1 = 0;
  local_90 = 0xf;
  local_94 = 0;
  local_a4[0] = (byte ****)((uint)local_a4[0] & 0xffffff00);
  local_b0 = 0;
  cVar1 = FUN_005885f0();
  uVar4 = 0;
  if (cVar1 != '\0') {
    do {
      uVar2 = FUN_00588600(local_8c);
      FUN_00401660(uVar2,0,0xffffffff);
      if (0xf < local_74) {
        _free(local_88);
        return extraout_EAX;
      }
      local_74 = 0xf;
      local_78 = 0;
      local_88 = (void *)((uint)local_88 & 0xffffff00);
      if (local_94 == 0) {
LAB_0055d4dd:
        if (local_94 != 0) {
          uVar4 = local_94;
          if (4 < local_94) {
            uVar4 = 5;
          }
          ppppbVar5 = local_a4[0];
          if (local_90 < 0x10) {
            ppppbVar5 = (byte ****)local_a4;
          }
          bVar7 = false;
          iVar3 = 0;
          bVar8 = true;
          pbVar6 = (byte *)s_color_009bcca0;
          do {
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            bVar7 = *(byte *)ppppbVar5 < *pbVar6;
            bVar8 = *(byte *)ppppbVar5 == *pbVar6;
            ppppbVar5 = (byte ****)((int)ppppbVar5 + 1);
            pbVar6 = pbVar6 + 1;
          } while (bVar8);
          if (!bVar8) {
            iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          }
          if (((iVar3 == 0) && (4 < local_94)) && (local_94 == 5)) {
            uVar2 = FUN_00588600(local_70);
            uVar2 = thunk_FUN_00796e90(uVar2);
            *param_1 = uVar2;
            if (0xf < local_58) {
              _free(local_6c);
              return extraout_EAX_01;
            }
            local_58 = 0xf;
            local_5c = 0;
            local_6c = (void *)((uint)local_6c & 0xffffff00);
            goto LAB_0055d691;
          }
        }
        iVar3 = FUN_00403620(0,local_94,s_screen_009bcca8,6);
        if (iVar3 == 0) {
          iVar3 = *DAT_00b5a7c0;
          uVar2 = FUN_00588600(local_54);
          uVar2 = (**(code **)(iVar3 + 8))(uVar2);
          param_1[1] = uVar2;
          if (0xf < uStack_3c) {
            _free(pvStack_50);
            return extraout_EAX_02;
          }
          uStack_3c = 0xf;
          uStack_40 = 0;
          pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
        }
        else {
          iVar3 = FUN_00403620(0,local_94,s_index_009bccb0,5);
          if (iVar3 == 0) {
            uVar2 = FUN_00588600(local_1c);
            uVar2 = thunk_FUN_00796fb0(uVar2);
            param_1[2] = uVar2;
            if (0xf < uStack_4) {
              _free(pvStack_18);
              return extraout_EAX_03;
            }
            uStack_4 = 0xf;
            uStack_8 = 0;
            pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
          }
          else {
            iVar3 = FUN_00403620(0,local_94,s_<_image>_009bccb8,8);
            if ((iVar3 == 0) ||
               (iVar3 = FUN_00403620(0,local_94,s_<_iconimage>_009bccc4,0xc), iVar3 == 0)) break;
          }
        }
      }
      else {
        uVar4 = local_94;
        if (2 < local_94) {
          uVar4 = 3;
        }
        ppppbVar5 = local_a4[0];
        if (local_90 < 0x10) {
          ppppbVar5 = (byte ****)local_a4;
        }
        bVar7 = false;
        iVar3 = 0;
        bVar8 = true;
        pbVar6 = &DAT_009bcc4c;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          bVar7 = *(byte *)ppppbVar5 < *pbVar6;
          bVar8 = *(byte *)ppppbVar5 == *pbVar6;
          ppppbVar5 = (byte ****)((int)ppppbVar5 + 1);
          pbVar6 = pbVar6 + 1;
        } while (bVar8);
        if (!bVar8) {
          iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        }
        if (((iVar3 != 0) || (local_94 < 3)) || (local_94 != 3)) goto LAB_0055d4dd;
        uVar2 = FUN_00588600(local_38);
        FUN_00401660(uVar2,0,0xffffffff);
        if (0xf < local_20) {
          _free(local_34);
          return extraout_EAX_00;
        }
        local_20 = 0xf;
        local_24 = 0;
        local_34 = (void *)((uint)local_34 & 0xffffff00);
        if (local_94 == 0) {
LAB_0055d381:
          iVar3 = FUN_00403620(0,local_94,&DAT_009bcc58,4);
          if (iVar3 == 0) {
            local_b0 = 2;
          }
          else {
            iVar3 = FUN_00403620(0,local_94,s_disable_009bcc60,7);
            if (iVar3 == 0) {
              local_b0 = 3;
            }
            else {
              iVar3 = FUN_00403620(0,local_94,s_check_009bcc68,5);
              if (iVar3 == 0) {
                local_b0 = 4;
              }
              else {
                iVar3 = FUN_00403620(0,local_94,s_blink_009bcc70,5);
                if (iVar3 == 0) {
                  local_b0 = 5;
                }
                else {
                  cVar1 = FUN_004036a0(local_a8,&DAT_009bcc78);
                  if (cVar1 == '\0') {
                    cVar1 = FUN_004036a0(local_a8,&DAT_009bcc80);
                    if (cVar1 == '\0') {
                      cVar1 = FUN_004036a0(local_a8,s_minus_009bcc88);
                      if (cVar1 == '\0') {
                        cVar1 = FUN_004036a0(local_a8,&DAT_009bcc90);
                        if (cVar1 == '\0') {
                          cVar1 = FUN_004036a0(local_a8,&DAT_009bcc98);
                          if (cVar1 == '\0') {
                            local_b0 = thunk_FUN_00796f50(local_a8);
                            local_b0 = local_b0 & 0xff;
                          }
                          else {
                            local_b0 = 10;
                          }
                        }
                        else {
                          local_b0 = 9;
                        }
                      }
                      else {
                        local_b0 = 8;
                      }
                    }
                    else {
                      local_b0 = 7;
                    }
                  }
                  else {
                    local_b0 = 0;
                  }
                }
              }
            }
          }
        }
        else {
          uVar4 = local_94;
          if (3 < local_94) {
            uVar4 = 4;
          }
          ppppbVar5 = local_a4[0];
          if (local_90 < 0x10) {
            ppppbVar5 = (byte ****)local_a4;
          }
          bVar7 = false;
          iVar3 = 0;
          bVar8 = true;
          pbVar6 = &DAT_009bcc50;
          do {
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            bVar7 = *(byte *)ppppbVar5 < *pbVar6;
            bVar8 = *(byte *)ppppbVar5 == *pbVar6;
            ppppbVar5 = (byte ****)((int)ppppbVar5 + 1);
            pbVar6 = pbVar6 + 1;
          } while (bVar8);
          if (!bVar8) {
            iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          }
          if (((iVar3 != 0) || (local_94 < 4)) || (local_94 != 4)) goto LAB_0055d381;
          local_b0 = 1;
        }
      }
LAB_0055d691:
      cVar1 = FUN_005885f0();
    } while (cVar1 != '\0');
    uVar4 = local_b0;
  }
  if (local_90 < 0x10) {
    return uVar4;
  }
  _free(local_a4[0]);
  return extraout_EAX_04;
}


// ==== FUN_0055d6d0 @ 0x0055d6d0 ====

uint FUN_0055d6d0(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  uint extraout_EAX;
  int iVar3;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  uint extraout_EAX_05;
  uint extraout_EAX_06;
  uint extraout_EAX_07;
  uint extraout_EAX_08;
  uint uVar4;
  byte *****pppppbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  uint local_120;
  undefined1 local_118 [4];
  byte *****local_114 [4];
  uint local_104;
  uint local_100;
  undefined1 local_fc [4];
  void *local_f8;
  undefined4 local_e8;
  uint local_e4;
  undefined1 local_e0 [4];
  void *pvStack_dc;
  undefined4 uStack_cc;
  uint uStack_c8;
  undefined1 local_c4 [4];
  void *pvStack_c0;
  undefined4 uStack_b0;
  uint uStack_ac;
  undefined1 local_a8 [4];
  void *local_a4;
  undefined4 local_94;
  uint local_90;
  undefined1 auStack_8c [4];
  void *pvStack_88;
  undefined4 uStack_78;
  uint uStack_74;
  undefined1 local_70 [4];
  void *local_6c;
  undefined4 local_5c;
  uint local_58;
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined1 local_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  *param_1 = 0;
  local_100 = 0xf;
  local_104 = 0;
  local_114[0] = (byte *****)((uint)local_114[0] & 0xffffff00);
  local_120 = 0;
  cVar1 = FUN_005885f0();
  while (cVar1 != '\0') {
    uVar2 = FUN_00588600(local_a8);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < local_90) {
      _free(local_a4);
      return extraout_EAX;
    }
    local_90 = 0xf;
    local_94 = 0;
    local_a4 = (void *)((uint)local_a4 & 0xffffff00);
    if (local_104 == 0) {
LAB_0055d9d9:
      if (local_104 != 0) {
        uVar4 = local_104;
        if (4 < local_104) {
          uVar4 = 5;
        }
        pppppbVar5 = local_114[0];
        if (local_100 < 0x10) {
          pppppbVar5 = (byte *****)local_114;
        }
        bVar7 = false;
        iVar3 = 0;
        bVar8 = true;
        pbVar6 = (byte *)s_color_009bcd28;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          bVar7 = *(byte *)pppppbVar5 < *pbVar6;
          bVar8 = *(byte *)pppppbVar5 == *pbVar6;
          pppppbVar5 = (byte *****)((int)pppppbVar5 + 1);
          pbVar6 = pbVar6 + 1;
        } while (bVar8);
        if (!bVar8) {
          iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        }
        if (((iVar3 == 0) && (4 < local_104)) && (local_104 == 5)) {
          uVar2 = FUN_00588600(local_fc);
          uVar2 = thunk_FUN_00796e90(uVar2);
          *param_1 = uVar2;
          if (0xf < local_e4) {
            _free(local_f8);
            return extraout_EAX_01;
          }
          local_e4 = 0xf;
          local_e8 = 0;
          local_f8 = (void *)((uint)local_f8 & 0xffffff00);
          goto LAB_0055dcd0;
        }
      }
      iVar3 = FUN_00403620(0,local_104,s_screen_009bcd30,6);
      if (iVar3 == 0) {
        iVar3 = *DAT_00b5a7c0;
        uVar2 = FUN_00588600(local_38);
        uVar2 = (**(code **)(iVar3 + 8))(uVar2);
        param_1[1] = uVar2;
        if (0xf < uStack_20) {
          _free(pvStack_34);
          return extraout_EAX_02;
        }
        uStack_20 = 0xf;
        uStack_24 = 0;
        pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
      }
      else {
        iVar3 = FUN_00403620(0,local_104,s_index_009bcd38,5);
        if (iVar3 == 0) {
          uVar2 = FUN_00588600(local_e0);
          uVar2 = thunk_FUN_00796fb0(uVar2);
          param_1[2] = uVar2;
          if (0xf < uStack_c8) {
            _free(pvStack_dc);
            return extraout_EAX_03;
          }
          uStack_c8 = 0xf;
          uStack_cc = 0;
          pvStack_dc = (void *)((uint)pvStack_dc & 0xffffff00);
        }
        else {
          iVar3 = FUN_00403620(0,local_104,s_effect_009bcd40,6);
          if (iVar3 == 0) {
            uVar2 = FUN_00588600(local_c4);
            uVar2 = thunk_FUN_00796e60(uVar2);
            *param_2 = uVar2;
            if (0xf < uStack_ac) {
              _free(pvStack_c0);
              return extraout_EAX_04;
            }
            uStack_ac = 0xf;
            uStack_b0 = 0;
            pvStack_c0 = (void *)((uint)pvStack_c0 & 0xffffff00);
            uVar2 = FUN_00588600(auStack_8c);
            uVar2 = thunk_FUN_00796e60(uVar2);
            param_2[1] = uVar2;
            if (0xf < uStack_74) {
              _free(pvStack_88);
              return extraout_EAX_05;
            }
            uStack_74 = 0xf;
            uStack_78 = 0;
            pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
            uVar2 = FUN_00588600(auStack_54);
            uVar2 = thunk_FUN_00796e60(uVar2);
            param_2[2] = uVar2;
            if (0xf < uStack_3c) {
              _free(pvStack_50);
              return extraout_EAX_06;
            }
            uStack_3c = 0xf;
            uStack_40 = 0;
            pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
            uVar2 = FUN_00588600(auStack_1c);
            uVar2 = thunk_FUN_00796e60(uVar2);
            param_2[3] = uVar2;
            if (0xf < uStack_4) {
              _free(pvStack_18);
              return extraout_EAX_07;
            }
            uStack_4 = 0xf;
            uStack_8 = 0;
            pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
          }
          else {
            iVar3 = FUN_00403620(0,local_104,s_<_image>_009bcd48,8);
            if (iVar3 == 0) break;
          }
        }
      }
    }
    else {
      uVar4 = local_104;
      if (2 < local_104) {
        uVar4 = 3;
      }
      pppppbVar5 = local_114[0];
      if (local_100 < 0x10) {
        pppppbVar5 = (byte *****)local_114;
      }
      bVar7 = false;
      iVar3 = 0;
      bVar8 = true;
      pbVar6 = &DAT_009bccd4;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        bVar7 = *(byte *)pppppbVar5 < *pbVar6;
        bVar8 = *(byte *)pppppbVar5 == *pbVar6;
        pppppbVar5 = (byte *****)((int)pppppbVar5 + 1);
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if (!bVar8) {
        iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (((iVar3 != 0) || (local_104 < 3)) || (local_104 != 3)) goto LAB_0055d9d9;
      uVar2 = FUN_00588600(local_70);
      FUN_00401660(uVar2,0,0xffffffff);
      if (0xf < local_58) {
        _free(local_6c);
        return extraout_EAX_00;
      }
      local_58 = 0xf;
      local_5c = 0;
      local_6c = (void *)((uint)local_6c & 0xffffff00);
      if (local_104 == 0) {
LAB_0055d875:
        iVar3 = FUN_00403620(0,local_104,&DAT_009bcce0,4);
        if (iVar3 == 0) {
          local_120 = 2;
        }
        else {
          iVar3 = FUN_00403620(0,local_104,s_disable_009bcce8,7);
          if (iVar3 == 0) {
            local_120 = 3;
          }
          else {
            iVar3 = FUN_00403620(0,local_104,s_check_009bccf0,5);
            if (iVar3 == 0) {
              local_120 = 4;
            }
            else {
              iVar3 = FUN_00403620(0,local_104,s_blink_009bccf8,5);
              if (iVar3 == 0) {
                local_120 = 5;
              }
              else {
                cVar1 = FUN_004036a0(local_118,&DAT_009bcd00);
                if (cVar1 == '\0') {
                  cVar1 = FUN_004036a0(local_118,&DAT_009bcd08);
                  if (cVar1 == '\0') {
                    cVar1 = FUN_004036a0(local_118,s_minus_009bcd10);
                    if (cVar1 == '\0') {
                      cVar1 = FUN_004036a0(local_118,&DAT_009bcd18);
                      if (cVar1 == '\0') {
                        cVar1 = FUN_004036a0(local_118,&DAT_009bcd20);
                        if (cVar1 == '\0') {
                          local_120 = thunk_FUN_00796f50(local_118);
                          local_120 = local_120 & 0xff;
                        }
                        else {
                          local_120 = 10;
                        }
                      }
                      else {
                        local_120 = 9;
                      }
                    }
                    else {
                      local_120 = 8;
                    }
                  }
                  else {
                    local_120 = 7;
                  }
                }
                else {
                  local_120 = 0;
                }
              }
            }
          }
        }
      }
      else {
        uVar4 = local_104;
        if (3 < local_104) {
          uVar4 = 4;
        }
        pppppbVar5 = local_114[0];
        if (local_100 < 0x10) {
          pppppbVar5 = (byte *****)local_114;
        }
        bVar7 = false;
        iVar3 = 0;
        bVar8 = true;
        pbVar6 = &DAT_009bccd8;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          bVar7 = *(byte *)pppppbVar5 < *pbVar6;
          bVar8 = *(byte *)pppppbVar5 == *pbVar6;
          pppppbVar5 = (byte *****)((int)pppppbVar5 + 1);
          pbVar6 = pbVar6 + 1;
        } while (bVar8);
        if (!bVar8) {
          iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        }
        if (((iVar3 != 0) || (local_104 < 4)) || (local_104 != 4)) goto LAB_0055d875;
        local_120 = 1;
      }
    }
LAB_0055dcd0:
    cVar1 = FUN_005885f0();
  }
  if (local_100 < 0x10) {
    return local_120;
  }
  _free(local_114[0]);
  return extraout_EAX_08;
}


// ==== FUN_0055dd10 @ 0x0055dd10 ====

void FUN_0055dd10(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar2 = FUN_00410500(param_1);
  pvVar3 = operator_new(0xc);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00588850(iVar2 + 0x3c);
  }
  *(undefined4 *)(in_ECX + 8) = uVar4;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  cVar1 = FUN_005885f0();
  while (cVar1 != '\0') {
    uVar4 = FUN_00588600(local_1c);
    FUN_00401660(uVar4,0,0xffffffff);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00588740(local_38);
    cVar1 = FUN_005885f0();
  }
  if (local_20 < 0x10) {
    return;
  }
  _free(local_34);
  return;
}


// ==== FUN_0055dde0 @ 0x0055dde0 ====

uint FUN_0055dde0(undefined4 *param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint extraout_EAX;
  int iVar3;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  undefined4 *puVar4;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  uint extraout_EAX_05;
  uint extraout_EAX_06;
  uint uVar5;
  byte ******ppppppbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  uint local_128;
  undefined1 local_120 [4];
  byte ******local_11c [4];
  uint local_10c;
  uint local_108;
  undefined1 local_104 [4];
  void *local_100;
  undefined4 local_f0;
  uint local_ec;
  undefined1 local_e8 [4];
  void *local_e4;
  undefined4 local_d4;
  uint local_d0;
  undefined1 local_cc [4];
  void *local_c8;
  undefined4 local_b8;
  uint local_b4;
  undefined1 local_b0 [4];
  void *local_ac;
  undefined4 local_9c;
  uint local_98;
  undefined1 local_94 [4];
  void *local_90;
  undefined4 local_80;
  uint local_7c;
  undefined1 local_78 [4];
  void *pvStack_74;
  undefined4 uStack_64;
  uint uStack_60;
  undefined1 local_5c [4];
  void *local_58;
  undefined4 local_48;
  uint local_44;
  undefined1 local_40 [8];
  undefined1 local_38 [56];
  
  local_10c = 0;
  local_11c[0] = (byte ******)((uint)local_11c[0] & 0xffffff00);
  local_128 = 0;
  *param_1 = 1;
  param_1[1] = 1;
  *(undefined1 *)(param_1 + 0xc) = 0;
  local_108 = 0xf;
  cVar1 = FUN_005885f0();
  while (cVar1 != '\0') {
    uVar2 = FUN_00588600(local_cc);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < local_b4) {
      _free(local_c8);
      return extraout_EAX;
    }
    local_b4 = 0xf;
    local_b8 = 0;
    local_c8 = (void *)((uint)local_c8 & 0xffffff00);
    if (local_10c == 0) {
LAB_0055e136:
      if (local_10c != 0) {
        uVar5 = local_10c;
        if (4 < local_10c) {
          uVar5 = 5;
        }
        ppppppbVar6 = local_11c[0];
        if (local_108 < 0x10) {
          ppppppbVar6 = (byte ******)local_11c;
        }
        bVar8 = false;
        iVar3 = 0;
        bVar9 = true;
        pbVar7 = (byte *)s_color_009bcb0c;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          bVar8 = *(byte *)ppppppbVar6 < *pbVar7;
          bVar9 = *(byte *)ppppppbVar6 == *pbVar7;
          ppppppbVar6 = (byte ******)((int)ppppppbVar6 + 1);
          pbVar7 = pbVar7 + 1;
        } while (bVar9);
        if (!bVar9) {
          iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        }
        if (((iVar3 == 0) && (4 < local_10c)) && (local_10c == 5)) {
          uVar2 = FUN_00588600(local_104);
          uVar2 = thunk_FUN_00796e90(uVar2);
          param_1[10] = uVar2;
          if (0xf < local_ec) {
            _free(local_100);
            return extraout_EAX_01;
          }
          local_ec = 0xf;
          local_f0 = 0;
          local_100 = (void *)((uint)local_100 & 0xffffff00);
          goto LAB_0055e483;
        }
      }
      iVar3 = FUN_00403620(0,local_10c,s_fontIndex_009bcb14,9);
      if ((iVar3 == 0) || (iVar3 = FUN_00403620(0,local_10c,s_fontindex_009bcb20,9), iVar3 == 0)) {
        uVar2 = FUN_00588600(local_78);
        uVar2 = thunk_FUN_00796fb0(uVar2);
        param_1[9] = uVar2;
        if (0xf < uStack_60) {
          _free(pvStack_74);
          return extraout_EAX_05;
        }
        uStack_60 = 0xf;
        uStack_64 = 0;
        pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
      }
      else {
        iVar3 = FUN_00403620(0,local_10c,s_position_009bcb2c,8);
        if (iVar3 == 0) {
          puVar4 = (undefined4 *)FUN_0055cec0(local_40);
          *param_1 = *puVar4;
          param_1[1] = puVar4[1];
          FUN_00401740(s__d__d_009bcb38,5);
          uVar2 = FUN_00404230(local_e8);
          uVar2 = FUN_004022a0(local_5c,s_Title_Pos___009bcb40,uVar2);
          FUN_00796d50(uVar2);
          if (0xf < local_44) {
            _free(local_58);
            return extraout_EAX_02;
          }
          local_44 = 0xf;
          local_48 = 0;
          local_58 = (void *)((uint)local_58 & 0xffffff00);
          if (0xf < local_d0) {
            _free(local_e4);
            return extraout_EAX_03;
          }
          local_d0 = 0xf;
          local_d4 = 0;
          local_e4 = (void *)((uint)local_e4 & 0xffffff00);
        }
        else {
          iVar3 = FUN_00403620(0,local_10c,&DAT_009bcb58,4);
          if (iVar3 == 0) {
            uVar2 = FUN_00588600(local_b0);
            FUN_00401660(uVar2,0,0xffffffff);
            if (0xf < local_98) {
              _free(local_ac);
              return extraout_EAX_04;
            }
            local_98 = 0xf;
            local_9c = 0;
            local_ac = (void *)((uint)local_ac & 0xffffff00);
          }
          else {
            cVar1 = FUN_004036a0(local_120,s_text2_009bcb60);
            if (cVar1 != '\0') {
              uVar2 = FUN_00588600(local_38);
              thunk_FUN_00796e60(uVar2);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            cVar1 = FUN_004036a0(local_120,s_<_title>_009bcb68);
            if ((cVar1 != '\0') ||
               (cVar1 = FUN_004036a0(local_120,s_<_icontext>_009bcb74), cVar1 != '\0')) break;
          }
        }
      }
    }
    else {
      uVar5 = local_10c;
      if (4 < local_10c) {
        uVar5 = 5;
      }
      ppppppbVar6 = local_11c[0];
      if (local_108 < 0x10) {
        ppppppbVar6 = (byte ******)local_11c;
      }
      bVar8 = false;
      iVar3 = 0;
      bVar9 = true;
      pbVar7 = (byte *)s_state_009bcaa4;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        bVar8 = *(byte *)ppppppbVar6 < *pbVar7;
        bVar9 = *(byte *)ppppppbVar6 == *pbVar7;
        ppppppbVar6 = (byte ******)((int)ppppppbVar6 + 1);
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (!bVar9) {
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      }
      if (((iVar3 != 0) || (local_10c < 5)) || (local_10c != 5)) goto LAB_0055e136;
      uVar2 = FUN_00588600(local_94);
      FUN_00401660(uVar2,0,0xffffffff);
      if (0xf < local_7c) {
        _free(local_90);
        return extraout_EAX_00;
      }
      local_7c = 0xf;
      local_80 = 0;
      local_90 = (void *)((uint)local_90 & 0xffffff00);
      if (local_10c == 0) {
LAB_0055df8c:
        iVar3 = FUN_00403620(0,local_10c,&DAT_009bcab4,4);
        if (iVar3 == 0) {
          local_128 = 2;
        }
        else {
          iVar3 = FUN_00403620(0,local_10c,s_disable_009bcabc,7);
          if (iVar3 == 0) {
            local_128 = 3;
          }
          else {
            iVar3 = FUN_00403620(0,local_10c,s_check_009bcac4,5);
            if (iVar3 == 0) {
              local_128 = 4;
            }
            else {
              iVar3 = FUN_00403620(0,local_10c,s_blink_009bcacc,5);
              if (iVar3 == 0) {
                local_128 = 5;
              }
              else {
                cVar1 = FUN_004036a0(local_120,&DAT_009bcad4);
                if (cVar1 == '\0') {
                  cVar1 = FUN_004036a0(local_120,&DAT_009bcadc);
                  if (cVar1 == '\0') {
                    cVar1 = FUN_004036a0(local_120,s_unknown_009bcae4);
                    if (cVar1 == '\0') {
                      cVar1 = FUN_004036a0(local_120,s_finish_009bcaec);
                      if (cVar1 == '\0') {
                        cVar1 = FUN_004036a0(local_120,s_complete_009bcaf4);
                        if (cVar1 == '\0') {
                          cVar1 = FUN_004036a0(local_120,&DAT_009bcb00);
                          if (cVar1 == '\0') {
                            cVar1 = FUN_004036a0(local_120,s_title_009bcb04);
                            if (cVar1 == '\0') {
                              local_128 = thunk_FUN_00796f50(local_120);
                              local_128 = local_128 & 0xff;
                            }
                            else {
                              local_128 = 6;
                            }
                          }
                          else {
                            local_128 = 9;
                          }
                        }
                        else {
                          local_128 = 0xc;
                        }
                      }
                      else {
                        local_128 = 0xb;
                      }
                    }
                    else {
                      local_128 = 10;
                    }
                  }
                  else {
                    local_128 = 8;
                  }
                }
                else {
                  local_128 = 0;
                }
              }
            }
          }
        }
      }
      else {
        uVar5 = local_10c;
        if (3 < local_10c) {
          uVar5 = 4;
        }
        ppppppbVar6 = local_11c[0];
        if (local_108 < 0x10) {
          ppppppbVar6 = (byte ******)local_11c;
        }
        bVar8 = false;
        iVar3 = 0;
        bVar9 = true;
        pbVar7 = &DAT_009bcaac;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          bVar8 = *(byte *)ppppppbVar6 < *pbVar7;
          bVar9 = *(byte *)ppppppbVar6 == *pbVar7;
          ppppppbVar6 = (byte ******)((int)ppppppbVar6 + 1);
          pbVar7 = pbVar7 + 1;
        } while (bVar9);
        if (!bVar9) {
          iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        }
        if (((iVar3 != 0) || (local_10c < 4)) || (local_10c != 4)) goto LAB_0055df8c;
        local_128 = 1;
      }
    }
LAB_0055e483:
    cVar1 = FUN_005885f0();
  }
  if (local_108 < 0x10) {
    return local_128;
  }
  _free(local_11c[0]);
  return extraout_EAX_06;
}


// ==== FUN_0055e4c0 @ 0x0055e4c0 ====

uint FUN_0055e4c0(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  uint extraout_EAX;
  int iVar3;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  undefined4 *puVar4;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  uint extraout_EAX_05;
  uint extraout_EAX_06;
  uint extraout_EAX_07;
  uint extraout_EAX_08;
  uint uVar5;
  byte ****ppppbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  uint local_198;
  undefined1 local_190 [4];
  byte ****local_18c [4];
  uint local_17c;
  uint local_178;
  undefined1 local_174 [4];
  void *local_170;
  undefined4 local_160;
  uint local_15c;
  undefined1 local_158 [4];
  void *local_154;
  undefined4 local_144;
  uint local_140;
  undefined1 local_13c [4];
  void *local_138;
  undefined4 local_128;
  uint local_124;
  undefined1 local_120 [4];
  void *pvStack_11c;
  undefined4 uStack_10c;
  uint uStack_108;
  undefined1 local_104 [4];
  void *local_100;
  undefined4 local_f0;
  uint local_ec;
  undefined1 auStack_e8 [4];
  void *pvStack_e4;
  undefined4 uStack_d4;
  uint uStack_d0;
  undefined1 local_cc [4];
  void *local_c8;
  undefined4 local_b8;
  uint local_b4;
  undefined1 local_b0 [4];
  void *local_ac;
  undefined4 local_9c;
  uint local_98;
  undefined1 local_94 [4];
  void *pvStack_90;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined1 local_78 [64];
  undefined1 local_38 [56];
  
  local_178 = 0xf;
  local_17c = 0;
  local_18c[0] = (byte ****)((uint)local_18c[0] & 0xffffff00);
  local_198 = 0;
  cVar1 = FUN_005885f0();
  while (cVar1 != '\0') {
    uVar2 = FUN_00588600(local_13c);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < local_124) {
      _free(local_138);
      return extraout_EAX;
    }
    local_124 = 0xf;
    local_128 = 0;
    local_138 = (void *)((uint)local_138 & 0xffffff00);
    if (local_17c == 0) {
LAB_0055e7fa:
      if (local_17c != 0) {
        uVar5 = local_17c;
        if (4 < local_17c) {
          uVar5 = 5;
        }
        ppppbVar6 = local_18c[0];
        if (local_178 < 0x10) {
          ppppbVar6 = (byte ****)local_18c;
        }
        bVar8 = false;
        iVar3 = 0;
        bVar9 = true;
        pbVar7 = (byte *)s_color_009bcbe8;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          bVar8 = *(byte *)ppppbVar6 < *pbVar7;
          bVar9 = *(byte *)ppppbVar6 == *pbVar7;
          ppppbVar6 = (byte ****)((int)ppppbVar6 + 1);
          pbVar7 = pbVar7 + 1;
        } while (bVar9);
        if (!bVar9) {
          iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        }
        if (((iVar3 == 0) && (4 < local_17c)) && (local_17c == 5)) {
          uVar2 = FUN_00588600(local_104);
          uVar2 = thunk_FUN_00796e90(uVar2);
          param_1[10] = uVar2;
          if (0xf < local_ec) {
            _free(local_100);
            return extraout_EAX_01;
          }
          local_ec = 0xf;
          local_f0 = 0;
          local_100 = (void *)((uint)local_100 & 0xffffff00);
          goto LAB_0055ec2a;
        }
      }
      iVar3 = FUN_00403620(0,local_17c,s_fontIndex_009bcbf0,9);
      if (iVar3 == 0) {
        uVar2 = FUN_00588600(local_94);
        uVar2 = thunk_FUN_00796fb0(uVar2);
        param_1[9] = uVar2;
        if (0xf < uStack_7c) {
          _free(pvStack_90);
          return extraout_EAX_02;
        }
        uStack_7c = 0xf;
        uStack_80 = 0;
        pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
      }
      else {
        iVar3 = FUN_00403620(0,local_17c,s_position_009bcbfc,8);
        if (iVar3 == 0) {
          puVar4 = (undefined4 *)FUN_0055cec0(local_78);
          *param_1 = *puVar4;
          param_1[1] = puVar4[1];
          FUN_00401740(s__d__d_009bcc08,5);
          uVar2 = FUN_00404230(local_b0);
          uVar2 = FUN_004022a0(local_174,s_Title_Pos___009bcc10,uVar2);
          FUN_00796d50(uVar2);
          if (0xf < local_15c) {
            _free(local_170);
            return extraout_EAX_03;
          }
          local_15c = 0xf;
          local_160 = 0;
          local_170 = (void *)((uint)local_170 & 0xffffff00);
          if (0xf < local_98) {
            _free(local_ac);
            return extraout_EAX_04;
          }
          local_98 = 0xf;
          local_9c = 0;
          local_ac = (void *)((uint)local_ac & 0xffffff00);
        }
        else {
          iVar3 = FUN_00403620(0,local_17c,&DAT_009bcc28,4);
          if (iVar3 == 0) {
            uVar2 = FUN_00588600(local_158);
            FUN_00401660(uVar2,0,0xffffffff);
            if (0xf < local_140) {
              _free(local_154);
              return extraout_EAX_05;
            }
            local_140 = 0xf;
            local_144 = 0;
            local_154 = (void *)((uint)local_154 & 0xffffff00);
          }
          else {
            iVar3 = FUN_00403620(0,local_17c,s_text2_009bcc30,5);
            if (iVar3 == 0) {
              uVar2 = FUN_00588600(local_120);
              iVar3 = thunk_FUN_00796e60(uVar2);
              if (0xf < uStack_108) {
                _free(pvStack_11c);
                return extraout_EAX_06;
              }
              uStack_108 = 0xf;
              uStack_10c = 0;
              pvStack_11c = (void *)((uint)pvStack_11c & 0xffffff00);
              uVar2 = FUN_00588600(auStack_e8);
              uVar5 = thunk_FUN_00796e60(uVar2);
              if (0xf < uStack_d0) {
                _free(pvStack_e4);
                return extraout_EAX_07;
              }
              uStack_d0 = 0xf;
              uStack_d4 = 0;
              pvStack_e4 = (void *)((uint)pvStack_e4 & 0xffffff00);
              uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,iVar3 << 0x10 | uVar5);
              FUN_00401660(uVar2,0,0xffffffff);
            }
            else {
              cVar1 = FUN_004036a0(local_190,s_effect_009bcc38);
              if (cVar1 != '\0') {
                uVar2 = FUN_00588600(local_38);
                uVar2 = thunk_FUN_00796e60(uVar2);
                *param_2 = uVar2;
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar1 = FUN_004036a0(local_190,s_<_title>_009bcc40);
              if (cVar1 != '\0') break;
            }
          }
        }
      }
    }
    else {
      uVar5 = local_17c;
      if (4 < local_17c) {
        uVar5 = 5;
      }
      ppppbVar6 = local_18c[0];
      if (local_178 < 0x10) {
        ppppbVar6 = (byte ****)local_18c;
      }
      bVar8 = false;
      iVar3 = 0;
      bVar9 = true;
      pbVar7 = (byte *)s_state_009bcb80;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        bVar8 = *(byte *)ppppbVar6 < *pbVar7;
        bVar9 = *(byte *)ppppbVar6 == *pbVar7;
        ppppbVar6 = (byte ****)((int)ppppbVar6 + 1);
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (!bVar9) {
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      }
      if (((iVar3 != 0) || (local_17c < 5)) || (local_17c != 5)) goto LAB_0055e7fa;
      uVar2 = FUN_00588600(local_cc);
      FUN_00401660(uVar2,0,0xffffffff);
      if (0xf < local_b4) {
        _free(local_c8);
        return extraout_EAX_00;
      }
      local_b4 = 0xf;
      local_b8 = 0;
      local_c8 = (void *)((uint)local_c8 & 0xffffff00);
      if (local_17c == 0) {
LAB_0055e650:
        iVar3 = FUN_00403620(0,local_17c,&DAT_009bcb90,4);
        if (iVar3 == 0) {
          local_198 = 2;
        }
        else {
          iVar3 = FUN_00403620(0,local_17c,s_disable_009bcb98,7);
          if (iVar3 == 0) {
            local_198 = 3;
          }
          else {
            iVar3 = FUN_00403620(0,local_17c,s_check_009bcba0,5);
            if (iVar3 == 0) {
              local_198 = 4;
            }
            else {
              iVar3 = FUN_00403620(0,local_17c,s_blink_009bcba8,5);
              if (iVar3 == 0) {
                local_198 = 5;
              }
              else {
                cVar1 = FUN_004036a0(local_190,&DAT_009bcbb0);
                if (cVar1 == '\0') {
                  cVar1 = FUN_004036a0(local_190,&DAT_009bcbb8);
                  if (cVar1 == '\0') {
                    cVar1 = FUN_004036a0(local_190,s_unknown_009bcbc0);
                    if (cVar1 == '\0') {
                      cVar1 = FUN_004036a0(local_190,s_finish_009bcbc8);
                      if (cVar1 == '\0') {
                        cVar1 = FUN_004036a0(local_190,s_complete_009bcbd0);
                        if (cVar1 == '\0') {
                          cVar1 = FUN_004036a0(local_190,&DAT_009bcbdc);
                          if (cVar1 == '\0') {
                            cVar1 = FUN_004036a0(local_190,s_title_009bcbe0);
                            if (cVar1 == '\0') {
                              local_198 = thunk_FUN_00796f50(local_190);
                              local_198 = local_198 & 0xff;
                            }
                            else {
                              local_198 = 6;
                            }
                          }
                          else {
                            local_198 = 9;
                          }
                        }
                        else {
                          local_198 = 0xc;
                        }
                      }
                      else {
                        local_198 = 0xb;
                      }
                    }
                    else {
                      local_198 = 10;
                    }
                  }
                  else {
                    local_198 = 8;
                  }
                }
                else {
                  local_198 = 0;
                }
              }
            }
          }
        }
      }
      else {
        uVar5 = local_17c;
        if (3 < local_17c) {
          uVar5 = 4;
        }
        ppppbVar6 = local_18c[0];
        if (local_178 < 0x10) {
          ppppbVar6 = (byte ****)local_18c;
        }
        bVar8 = false;
        iVar3 = 0;
        bVar9 = true;
        pbVar7 = &DAT_009bcb88;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          bVar8 = *(byte *)ppppbVar6 < *pbVar7;
          bVar9 = *(byte *)ppppbVar6 == *pbVar7;
          ppppbVar6 = (byte ****)((int)ppppbVar6 + 1);
          pbVar7 = pbVar7 + 1;
        } while (bVar9);
        if (!bVar9) {
          iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        }
        if (((iVar3 != 0) || (local_17c < 4)) || (local_17c != 4)) goto LAB_0055e650;
        local_198 = 1;
      }
    }
LAB_0055ec2a:
    cVar1 = FUN_005885f0();
  }
  if (local_178 < 0x10) {
    return local_198;
  }
  _free(local_18c[0]);
  return extraout_EAX_08;
}


// ==== FUN_0055ec70 @ 0x0055ec70 ====

/* WARNING: Removing unreachable block (ram,0x0055ee2b) */
/* WARNING: Removing unreachable block (ram,0x0055ee91) */

void FUN_0055ec70(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 ******ppppppuVar8;
  int iVar9;
  byte ******ppppppbVar10;
  void *unaff_EDI;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  undefined4 in_stack_ffffff00;
  uint in_stack_ffffff04;
  undefined4 in_stack_ffffff08;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int local_d0;
  int *piStack_cc;
  int *piStack_c8;
  byte ******appppppbStack_c4 [3];
  undefined1 auStack_b8 [4];
  uint uStack_b4;
  int *piStack_b0;
  undefined4 uStack_ac;
  undefined4 ******appppppuStack_a4 [4];
  undefined4 uStack_94;
  uint uStack_90;
  undefined1 uStack_88;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_64 [6];
  undefined1 uStack_5e;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 auStack_44 [2];
  undefined1 uStack_3c;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined1 auStack_c [8];
  int *piStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_5e = 1;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  auStack_44[0] = 0;
  uStack_28 = 0xf;
  uStack_2c = 0;
  uStack_3c = 0;
  piStack_c8 = piVar3;
  uStack_ac = (**(code **)(*DAT_00b5a7ac + 8))(10);
  uStack_74 = 0xf;
  uStack_78 = 0;
  uStack_88 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  piStack_b0 = (int *)0xf;
  uStack_b4 = 0;
  appppppbStack_c4[0] = (byte ******)((uint)appppppbStack_c4[0] & 0xffffff00);
  uStack_90 = 0xf;
  uStack_94 = 0;
  appppppuStack_a4[0] = (undefined4 ******)((uint)appppppuStack_a4[0] & 0xffffff00);
  FUN_00401740(s_<_itemslot>_009bc324,0xb);
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    local_d0 = 0;
  }
  else {
    local_d0 = FUN_00505f10();
  }
  *(undefined4 *)(local_d0 + 0x1a8) = 0x20;
  *(undefined4 *)(local_d0 + 0x1ac) = 0x20;
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_0055ef5e:
      FUN_00401660(auStack_44,0,0xffffffff);
      (**(code **)(*piVar3 + 8))(auStack_64);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*piVar3 + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar3);
        if (cVar2 == '\0') {
          (**(code **)(*piVar3 + 0x74))(0);
        }
        else {
          iVar9 = (**(code **)(*piStack_4 + 0x38))();
          piVar3[1] = iVar9;
        }
      }
      piVar1 = piStack_b0;
      (**(code **)(*piStack_b0 + 0x38))(piVar3);
      (**(code **)(*piVar1 + 0x1c))(&uStack_94);
      (**(code **)(*piVar3 + 0x2c))(piVar1);
      FUN_00569460(auStack_b8,piVar3);
      (**(code **)(*piVar1 + 0x24))(unaff_EDI);
      FUN_00505d80();
      _free(unaff_EDI);
      return;
    }
    uVar5 = FUN_00588600(&uStack_28);
    uVar14 = 0x55edad;
    FUN_00401660(uVar5,0,0xffffffff);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    cVar2 = FUN_0055cad0(&piStack_c8);
    if (cVar2 != '\0') {
      FUN_00588700(&piStack_c8);
      goto LAB_0055ef5e;
    }
    uVar16 = 0xf;
    uVar15 = 0;
    in_stack_ffffff04 = in_stack_ffffff04 & 0xffffff00;
    FUN_00401660(&piStack_c8,0,0xffffffff);
    FUN_0055cf30(auStack_64,local_d0,in_stack_ffffff00,in_stack_ffffff04,in_stack_ffffff08,uVar14,
                 uVar5,uVar15,uVar16);
    piVar3 = piStack_cc;
    if (uStack_b4 == 0) {
code_r0x0055ee94:
      if (uStack_b4 != 0) {
        uVar7 = uStack_b4;
        if (7 < uStack_b4) {
          uVar7 = 8;
        }
        ppppppbVar10 = appppppbStack_c4[0];
        if (piStack_b0 < (int *)0x10) {
          ppppppbVar10 = (byte ******)appppppbStack_c4;
        }
        bVar12 = false;
        iVar9 = 0;
        bVar13 = true;
        pbVar11 = (byte *)s_cellsize_009bc338;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
          bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
          ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
          pbVar11 = pbVar11 + 1;
        } while (bVar13);
        if (!bVar13) {
          iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        }
        if (((iVar9 == 0) && (7 < uStack_b4)) && (uStack_b4 == 8)) {
          puVar6 = (undefined4 *)FUN_0055cec0(auStack_c);
          *(undefined4 *)(local_d0 + 0x1a8) = *puVar6;
          *(undefined4 *)(local_d0 + 0x1ac) = puVar6[1];
          goto LAB_0055ef2c;
        }
      }
      ppppppuVar8 = appppppuStack_a4[0];
      if (uStack_90 < 0x10) {
        ppppppuVar8 = appppppuStack_a4;
      }
      in_stack_ffffff08 = 0x55ef28;
      iVar9 = FUN_00403620(0,uStack_b4,ppppppuVar8,uStack_94);
      if (iVar9 == 0) {
        FUN_00588700(&piStack_c8);
        goto LAB_0055ef5e;
      }
    }
    else {
      uVar7 = uStack_b4;
      if (6 < uStack_b4) {
        uVar7 = 7;
      }
      ppppppbVar10 = appppppbStack_c4[0];
      if (piStack_b0 < (int *)0x10) {
        ppppppbVar10 = (byte ******)appppppbStack_c4;
      }
      bVar12 = false;
      iVar9 = 0;
      bVar13 = true;
      pbVar11 = (byte *)s_<image>_009bc330;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
        bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
        ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
        pbVar11 = pbVar11 + 1;
      } while (bVar13);
      if (!bVar13) {
        iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      }
      if (((iVar9 != 0) || (uStack_b4 < 7)) || (uStack_b4 != 7)) goto code_r0x0055ee94;
      FUN_0055d1f0(local_d0);
    }
LAB_0055ef2c:
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_0055f0a0 @ 0x0055f0a0 ====

/* WARNING: Removing unreachable block (ram,0x0055f362) */
/* WARNING: Removing unreachable block (ram,0x0055f36d) */
/* WARNING: Removing unreachable block (ram,0x0055f37a) */
/* WARNING: Removing unreachable block (ram,0x0055f391) */
/* WARNING: Removing unreachable block (ram,0x0055f39e) */
/* WARNING: Removing unreachable block (ram,0x0055f3b0) */
/* WARNING: Removing unreachable block (ram,0x0055f3bd) */
/* WARNING: Removing unreachable block (ram,0x0055f3d2) */
/* WARNING: Removing unreachable block (ram,0x0055f3e2) */

void FUN_0055f0a0(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte ******ppppppbVar7;
  int iVar8;
  uint uVar9;
  byte ******ppppppbVar10;
  bool bVar11;
  bool bVar12;
  undefined4 in_stack_ffffff0c;
  uint in_stack_ffffff10;
  undefined4 in_stack_ffffff14;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int *piStack_c4;
  int *piStack_c0;
  byte ******appppppbStack_bc [2];
  undefined1 auStack_b4 [8];
  uint uStack_ac;
  uint uStack_a8;
  byte ******appppppbStack_a0 [4];
  uint uStack_90;
  int *piStack_8c;
  undefined4 uStack_88;
  uint uStack_80;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 auStack_5c [6];
  undefined1 uStack_56;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 auStack_3c [2];
  undefined1 uStack_34;
  undefined4 uStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  int *piStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_56 = 1;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  auStack_3c[0] = 0;
  uStack_20 = 0xf;
  uStack_24 = 0;
  uStack_34 = 0;
  piStack_c0 = piVar3;
  uStack_88 = (**(code **)(*DAT_00b5a7ac + 8))();
  uStack_6c = 0xf;
  uStack_70 = 0;
  uStack_80 = uStack_80 & 0xffffff00;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_a8 = 0xf;
  uStack_ac = 0;
  appppppbStack_bc[0] = (byte ******)((uint)appppppbStack_bc[0] & 0xffffff00);
  piStack_8c = (int *)0xf;
  uStack_90 = 0;
  appppppbStack_a0[0] = (byte ******)((uint)appppppbStack_a0[0] & 0xffffff00);
  FUN_00401740(s_<_quickslot>_009bc344,0xc);
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_00505f10();
  }
  FUN_0056a6d0();
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_0055f2be:
      FUN_00401660(auStack_3c,0,0xffffffff);
      (**(code **)(*piVar3 + 8))(auStack_5c);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*piVar3 + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(piVar3);
        if (cVar2 == '\0') {
          (**(code **)(*piVar3 + 0x74))(0);
        }
        else {
          iVar8 = (**(code **)(*piStack_4 + 0x38))();
          piVar3[1] = iVar8;
        }
      }
      piVar1 = piStack_8c;
      (**(code **)(*piStack_8c + 0x38))(piVar3);
      (**(code **)(*piVar1 + 0x1c))(&piStack_8c);
      (**(code **)(*piVar3 + 0x2c))(piVar1);
      FUN_00569460(auStack_b4,piVar3);
      (**(code **)(*piVar1 + 0x24))(0x12);
      FUN_00505d80();
      _free((void *)0x12);
      return;
    }
    uVar6 = FUN_00588600(&uStack_20);
    uVar13 = 0x55f1cd;
    FUN_00401660(uVar6,0,0xffffffff);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    cVar2 = FUN_0055cad0(&piStack_c0);
    if (cVar2 != '\0') {
LAB_0055f2b6:
      FUN_00588700(&piStack_c0);
      goto LAB_0055f2be;
    }
    uVar15 = 0xf;
    uVar14 = 0;
    in_stack_ffffff10 = in_stack_ffffff10 & 0xffffff00;
    FUN_00401660(&piStack_c0,0,0xffffffff);
    FUN_0055cf30(auStack_5c,uVar5,in_stack_ffffff0c,in_stack_ffffff10,in_stack_ffffff14,uVar13,uVar6
                 ,uVar14,uVar15);
    ppppppbVar7 = appppppbStack_a0[0];
    if (piStack_8c < (int *)0x10) {
      ppppppbVar7 = (byte ******)appppppbStack_a0;
    }
    if (uStack_ac == 0) {
LAB_0055f289:
      if ((uStack_90 <= uStack_ac) && (uStack_ac == uStack_90)) goto LAB_0055f2b6;
    }
    else {
      uVar9 = uStack_90;
      if (uStack_ac < uStack_90) {
        uVar9 = uStack_ac;
      }
      ppppppbVar10 = appppppbStack_bc[0];
      if (uStack_a8 < 0x10) {
        ppppppbVar10 = (byte ******)appppppbStack_bc;
      }
      bVar11 = false;
      iVar8 = 0;
      bVar12 = true;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        bVar11 = *(byte *)ppppppbVar10 < *(byte *)ppppppbVar7;
        bVar12 = *(byte *)ppppppbVar10 == *(byte *)ppppppbVar7;
        ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
        ppppppbVar7 = (byte ******)((int)ppppppbVar7 + 1);
      } while (bVar12);
      if (!bVar12) {
        iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      }
      piVar3 = piStack_c4;
      if (iVar8 == 0) goto LAB_0055f289;
    }
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_0055f3f0 @ 0x0055f3f0 ====

/* WARNING: Removing unreachable block (ram,0x0055f63c) */

void FUN_0055f3f0(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 ******ppppppuVar7;
  uint uVar8;
  int iVar9;
  int *unaff_EBX;
  int *unaff_EBP;
  int *unaff_ESI;
  byte ******ppppppbVar10;
  int *unaff_EDI;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  undefined4 in_stack_fffffeb0;
  uint in_stack_fffffeb4;
  undefined4 in_stack_fffffeb8;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 local_11c;
  byte ******appppppbStack_118 [2];
  void *apvStack_110 [2];
  uint uStack_108;
  uint uStack_104;
  undefined4 uStack_100;
  undefined4 ******appppppuStack_fc [3];
  void *pvStack_f0;
  undefined4 uStack_ec;
  int *piStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  uint uStack_dc;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined1 auStack_b8 [6];
  undefined1 uStack_b2;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  void *pvStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 uStack_90;
  undefined4 uStack_80;
  undefined4 uStack_7c;
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
  undefined1 auStack_c [8];
  int *piStack_4;
  
  (**(code **)(*DAT_00b5a7ac + 4))();
  uStack_b2 = 1;
  uStack_b0 = 0;
  uStack_ac = 0;
  pvStack_a8 = (void *)0x0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  uStack_7c = 0xf;
  uStack_80 = 0;
  uStack_90 = 0;
  uVar17 = 0xf;
  uStack_e4 = (**(code **)(*DAT_00b5a7ac + 8))(0xf);
  uStack_c8 = 0xf;
  uStack_cc = 0;
  uStack_dc = uStack_dc & 0xffffff00;
  uStack_c4 = 0;
  uStack_c0 = 0;
  uStack_bc = 0;
  uStack_104 = 0xf;
  uStack_108 = 0;
  appppppbStack_118[0] = (byte ******)((uint)appppppbStack_118[0] & 0xffffff00);
  piStack_e8 = (int *)0xf;
  uStack_ec = 0;
  appppppuStack_fc[0] = (undefined4 ******)((uint)appppppuStack_fc[0] & 0xffffff00);
  FUN_00401740(s_<_item>_009bc354,7);
  pvVar4 = operator_new(0x468);
  if (pvVar4 == (void *)0x0) {
    pvVar4 = (void *)0x0;
  }
  else {
    pvVar4 = (void *)FUN_00505f10();
  }
  *(undefined4 *)((int)pvVar4 + 0x1c4) = 0x20;
  *(undefined4 *)((int)pvVar4 + 0x1c8) = 0x20;
  *(undefined4 *)((int)pvVar4 + 0x1c0) = 0;
  *(undefined4 *)((int)pvVar4 + 0x1cc) = 1;
  *(undefined4 *)((int)pvVar4 + 0x1d0) = 1;
  *(undefined1 *)((int)pvVar4 + 0x1d4) = 0;
  *(undefined1 *)((int)pvVar4 + 0x1d5) = 0;
  *(undefined1 *)((int)pvVar4 + 0x1d6) = 0;
  *(undefined4 *)((int)pvVar4 + 0x1d8) = 0;
  cVar2 = FUN_005885f0();
  do {
    if (cVar2 == '\0') {
LAB_0055f8ac:
      FUN_00401660(&uStack_98,0,0xffffffff);
      (**(code **)(*unaff_EBX + 8))(auStack_b8);
      if ((piStack_4 != (int *)0x0) &&
         (cVar2 = (**(code **)(*unaff_EBP + 0x74))(piStack_4), cVar2 != '\0')) {
        cVar2 = (**(code **)(*piStack_4 + 0x78))(unaff_EBP);
        if (cVar2 == '\0') {
          (**(code **)(*unaff_ESI + 0x74))(0);
        }
        else {
          iVar9 = (**(code **)(*piStack_4 + 0x38))();
          unaff_EBP[1] = iVar9;
        }
      }
      piVar1 = piStack_e8;
      (**(code **)(*piStack_e8 + 0x38))(unaff_EBP);
      (**(code **)(*piVar1 + 0x1c))(&piStack_e8);
      (**(code **)(*unaff_EDI + 0x2c))(piVar1);
      FUN_00569460(apvStack_110,uVar17);
      (**(code **)(*piVar1 + 0x24))(pvVar4);
      if (pvVar4 != (void *)0x0) {
        FUN_00505d80();
        _free(pvVar4);
        return;
      }
      if ((undefined4 ******)0xf < appppppuStack_fc[0]) {
        _free(apvStack_110[0]);
        return;
      }
      appppppuStack_fc[0] = (undefined4 ******)0xf;
      uStack_100 = 0;
      apvStack_110[0] = (void *)((uint)apvStack_110[0] & 0xffffff00);
      if ((byte ******)0xf < appppppbStack_118[0]) {
        _free(unaff_ESI);
        return;
      }
      appppppbStack_118[0] = (byte ******)0xf;
      local_11c = 0;
      if (0xf < uStack_dc) {
        _free(pvStack_f0);
        return;
      }
      uStack_dc = 0xf;
      uStack_e0 = 0;
      pvStack_f0 = (void *)((uint)pvStack_f0 & 0xffffff00);
      if (uStack_94 < 0x10) {
        return;
      }
      _free(pvStack_a8);
      return;
    }
    uVar5 = FUN_00588600(auStack_44);
    uVar14 = 0x55f54d;
    FUN_00401660(uVar5,0,0xffffffff);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    cVar2 = FUN_0055cad0(&local_11c);
    if (cVar2 != '\0') {
LAB_0055f8a4:
      FUN_00588700(&local_11c);
      goto LAB_0055f8ac;
    }
    uVar16 = 0xf;
    uVar15 = 0;
    in_stack_fffffeb4 = in_stack_fffffeb4 & 0xffffff00;
    FUN_00401660(&local_11c,0,0xffffffff);
    FUN_0055cf30(auStack_b8,pvVar4,in_stack_fffffeb0,in_stack_fffffeb4,in_stack_fffffeb8,uVar14,
                 uVar5,uVar15,uVar16);
    if (uStack_108 == 0) {
code_r0x0055f63f:
      if (uStack_108 != 0) {
        uVar8 = uStack_108;
        if (4 < uStack_108) {
          uVar8 = 5;
        }
        ppppppbVar10 = appppppbStack_118[0];
        if (uStack_104 < 0x10) {
          ppppppbVar10 = (byte ******)appppppbStack_118;
        }
        bVar12 = false;
        iVar9 = 0;
        bVar13 = true;
        pbVar11 = (byte *)s_align_009bc368;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
          bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
          ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
          pbVar11 = pbVar11 + 1;
        } while (bVar13);
        if (!bVar13) {
          iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        }
        if (((iVar9 == 0) && (4 < uStack_108)) && (uStack_108 == 5)) {
          uVar5 = FUN_00588600(&uStack_7c);
          FUN_00401660(uVar5,0,0xffffffff);
          if (0xf < uStack_64) {
            _free(pvStack_78);
            return;
          }
          uStack_64 = 0xf;
          uStack_68 = 0;
          pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
          in_stack_fffffeb8 = 0x55f6fd;
          iVar9 = FUN_00403620(0,uStack_108,s_center_009bc370,6);
          if (iVar9 == 0) {
            *(undefined1 *)((int)pvVar4 + 0x1d6) = 1;
          }
          else {
            in_stack_fffffeb8 = 0x55f727;
            iVar9 = FUN_00403620(0,uStack_108,s_right_009bc378,5);
            *(byte *)((int)pvVar4 + 0x1d6) = (-(iVar9 != 0) & 0xfeU) + 2;
          }
          goto LAB_0055f88a;
        }
      }
      in_stack_fffffeb8 = 0x55f754;
      iVar9 = FUN_00403620(0,uStack_108,s_moveable_009bc380,8);
      if (iVar9 == 0) {
        uVar5 = FUN_00588600(auStack_28);
        uVar3 = thunk_FUN_00796fe0(uVar5);
        *(undefined1 *)((int)pvVar4 + 0x1d5) = uVar3;
        if (0xf < uStack_10) {
          _free(pvStack_24);
          return;
        }
        uStack_10 = 0xf;
        uStack_14 = 0;
        pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      }
      else {
        iVar9 = FUN_00403620(0,uStack_108,&DAT_009bc38c,4);
        if (iVar9 == 0) {
          uVar5 = FUN_00588600(auStack_60);
          FUN_00401660(uVar5,0,0xffffffff);
          if (0xf < uStack_48) {
            _free(pvStack_5c);
            return;
          }
          uStack_48 = 0xf;
          uStack_4c = 0;
          pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
          in_stack_fffffeb8 = 0x55f82f;
          iVar9 = FUN_00403620(0,uStack_108,&DAT_009bc394,4);
          *(uint *)((int)pvVar4 + 0x1c0) = (uint)(iVar9 == 0);
        }
        else {
          in_stack_fffffeb8 = 0x55f854;
          iVar9 = FUN_00403620(0,uStack_108,s_<image>_009bc39c,7);
          if (iVar9 == 0) {
            FUN_0055d1f0(pvVar4);
          }
          else {
            ppppppuVar7 = appppppuStack_fc[0];
            if (piStack_e8 < (int *)0x10) {
              ppppppuVar7 = appppppuStack_fc;
            }
            in_stack_fffffeb8 = 0x55f886;
            iVar9 = FUN_00403620(0,uStack_108,ppppppuVar7,uStack_ec);
            if (iVar9 == 0) goto LAB_0055f8a4;
          }
        }
      }
    }
    else {
      uVar8 = uStack_108;
      if (7 < uStack_108) {
        uVar8 = 8;
      }
      ppppppbVar10 = appppppbStack_118[0];
      if (uStack_104 < 0x10) {
        ppppppbVar10 = (byte ******)appppppbStack_118;
      }
      bVar12 = false;
      iVar9 = 0;
      bVar13 = true;
      pbVar11 = (byte *)s_cellsize_009bc35c;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        bVar12 = *(byte *)ppppppbVar10 < *pbVar11;
        bVar13 = *(byte *)ppppppbVar10 == *pbVar11;
        ppppppbVar10 = (byte ******)((int)ppppppbVar10 + 1);
        pbVar11 = pbVar11 + 1;
      } while (bVar13);
      if (!bVar13) {
        iVar9 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      }
      if (((iVar9 != 0) || (uStack_108 < 8)) || (uStack_108 != 8)) goto code_r0x0055f63f;
      puVar6 = (undefined4 *)FUN_0055cec0(auStack_c);
      *(undefined4 *)((int)pvVar4 + 0x1c4) = *puVar6;
      *(undefined4 *)((int)pvVar4 + 0x1c8) = puVar6[1];
    }
LAB_0055f88a:
    cVar2 = FUN_005885f0();
  } while( true );
}


// ==== FUN_0055fa00 @ 0x0055fa00 ====

/* WARNING: Removing unreachable block (ram,0x0055fc5b) */
/* WARNING: Removing unreachable block (ram,0x0055fd19) */

void FUN_0055fa00(void)

{
  char cVar1;
  undefined1 uVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *pvVar7;
  undefined4 *****pppppuVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  uint3 unaff_EBX;
  undefined4 unaff_EBP;
  int *unaff_ESI;
  byte *****pppppbVar12;
  byte *pbVar13;
  bool bVar14;
  bool bVar15;
  int *unaff_retaddr;
  undefined4 in_stack_fffffe60;
  uint in_stack_fffffe64;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int *piVar19;
  int *piStack_170;
  undefined1 auStack_164 [4];
  byte *****apppppbStack_160 [2];
  undefined1 auStack_158 [8];
  uint uStack_150;
  uint uStack_14c;
  int *piStack_148;
  int *piStack_144;
  undefined4 *****apppppuStack_140 [4];
  undefined4 uStack_130;
  uint uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined1 uStack_11c;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined1 uStack_f8;
  undefined1 uStack_f7;
  undefined1 uStack_f0;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined1 auStack_cc [4];
  void *pvStack_c8;
  undefined4 uStack_b8;
  uint uStack_b4;
  undefined1 auStack_b0 [6];
  undefined1 uStack_aa;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 auStack_90 [2];
  undefined1 uStack_88;
  undefined4 uStack_78;
  undefined4 uStack_74;
  void *pvStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
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
  int *piStack_c;
  int *piStack_8;
  undefined4 uStack_4;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
  uStack_aa = 1;
  uStack_a8 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  uStack_94 = 0;
  auStack_90[0] = 0;
  uStack_74 = 0xf;
  uStack_78 = 0;
  uStack_88 = 0;
  piStack_144 = piVar4;
  (**(code **)(*DAT_00b5a7ac + 8))(8);
  uStack_dc = 0xf;
  uStack_e0 = 0;
  uStack_f0 = 0;
  uStack_d8 = 0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  uStack_14c = 0xf;
  uStack_150 = 0;
  apppppbStack_160[0] = (byte *****)((uint)apppppbStack_160[0] & 0xffffff00);
  uStack_12c = 0xf;
  uStack_130 = 0;
  apppppuStack_140[0] = (undefined4 *****)((uint)apppppuStack_140[0] & 0xffffff00);
  FUN_00401740(s_<_label>_009bc3a4,8);
  uStack_104 = 1;
  uStack_fc = 1;
  piVar19 = (int *)(uint)unaff_EBX;
  uStack_128 = 0;
  uStack_124 = 0;
  uStack_108 = 0xf;
  uStack_10c = 0;
  uStack_11c = 0;
  uStack_100 = 0;
  uStack_f8 = 0;
  uStack_f7 = 0;
  uVar5 = (**(code **)(*unaff_retaddr + 0x50))();
  uVar6 = FUN_004022a0(auStack_cc,s_Make_Label___009bc3b0,uVar5);
  uVar5 = 0x55fb3e;
  FUN_00796d50(uVar6);
  if (0xf < uStack_b4) {
    _free(pvStack_c8);
    return;
  }
  pvVar7 = operator_new(0x468);
  if (pvVar7 == (void *)0x0) {
    piStack_170 = (int *)0x0;
  }
  else {
    piStack_170 = (int *)FUN_00505f10();
  }
  piStack_170[0x66] = 5;
  piStack_170[0x67] = 5;
  *(undefined1 *)(piStack_170 + 0x65) = 0;
  *(undefined1 *)((int)piStack_170 + 0x195) = 0;
  *(undefined1 *)((int)piStack_170 + 0x196) = 0;
  piStack_170[0x68] = 0xc;
  cVar1 = FUN_005885f0();
  do {
    if (cVar1 == '\0') {
LAB_0055ffa9:
      FUN_00401660(auStack_90,0,0xffffffff);
      (**(code **)(*piVar4 + 8))(auStack_b0);
      cVar1 = uStack_4._3_1_;
      cVar3 = (**(code **)(*piVar4 + 0x74))();
      if (cVar3 != '\0') {
        cVar3 = (**(code **)(*piStack_8 + 0x78))(piVar4);
        if (cVar3 == '\0') {
          (**(code **)(*piVar4 + 0x74))(0);
        }
        else {
          iVar11 = (**(code **)(*piStack_c + 0x38))();
          piVar4[1] = iVar11;
        }
      }
      (**(code **)(*piStack_170 + 0x38))(piVar4);
      (**(code **)(*piVar19 + 0x1c))(&uStack_100);
      (**(code **)(*piVar4 + 0x2c))(unaff_EBP);
      FUN_00569460(auStack_158,piVar4);
      (**(code **)(*unaff_ESI + 0x24))(piStack_170);
      if (cVar1 != '\0') {
        (**(code **)(*unaff_ESI + 8))(apppppuStack_140);
      }
      if ((char)piStack_170[3] == '\0') {
        puVar9 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        if (puVar9 == (undefined4 *)0x0) {
          puVar9 = (undefined4 *)0x0;
        }
        else {
          uVar5 = (**(code **)(*piVar4 + 4))();
          *puVar9 = &PTR_FUN_009bcd68;
          puVar9[1] = uVar5;
        }
        *(undefined1 *)(puVar9 + 2) = 0;
        (**(code **)(*DAT_00b5ad24 + 4))(puVar9);
        (**(code **)*puVar9)(1);
      }
      FUN_00505d80();
      _free(piStack_170);
      return;
    }
    uVar6 = FUN_00588600(&uStack_74);
    uVar16 = 0x55fbdd;
    FUN_00401660(uVar6,0,0xffffffff);
    if (0xf < uStack_5c) {
      _free(pvStack_70);
      return;
    }
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
    cVar1 = FUN_0055cad0(auStack_164);
    if (cVar1 != '\0') {
      FUN_00588700(auStack_164);
      goto LAB_0055ffa9;
    }
    uVar18 = 0xf;
    uVar17 = 0;
    in_stack_fffffe64 = in_stack_fffffe64 & 0xffffff00;
    FUN_00401660(auStack_164,0,0xffffffff);
    FUN_0055cf30(auStack_b0,piStack_170,in_stack_fffffe60,in_stack_fffffe64,uVar5,uVar16,uVar6,
                 uVar17,uVar18);
    if (uStack_150 == 0) {
code_r0x0055fd1c:
      if (uStack_150 != 0) {
        uVar10 = uStack_150;
        if (9 < uStack_150) {
          uVar10 = 10;
        }
        pppppbVar12 = apppppbStack_160[0];
        if (uStack_14c < 0x10) {
          pppppbVar12 = (byte *****)apppppbStack_160;
        }
        bVar14 = false;
        iVar11 = 0;
        bVar15 = true;
        pbVar13 = (byte *)s_lineheight_009bc3cc;
        do {
          if (uVar10 == 0) break;
          uVar10 = uVar10 - 1;
          bVar14 = *(byte *)pppppbVar12 < *pbVar13;
          bVar15 = *(byte *)pppppbVar12 == *pbVar13;
          pppppbVar12 = (byte *****)((int)pppppbVar12 + 1);
          pbVar13 = pbVar13 + 1;
        } while (bVar15);
        if (!bVar15) {
          iVar11 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
        }
        if (((iVar11 == 0) && (9 < uStack_150)) && (uStack_150 == 10)) {
          uVar6 = FUN_00588600(auStack_3c);
          iVar11 = thunk_FUN_00796e60(uVar6);
          piStack_170[0x68] = iVar11;
          if (0xf < uStack_24) {
            _free(pvStack_38);
            return;
          }
          uStack_24 = 0xf;
          uStack_28 = 0;
          pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
          goto LAB_0055ff73;
        }
      }
      iVar11 = FUN_00403620(0,uStack_150,s_align_009bc3d8,5);
      if (iVar11 == 0) {
        uVar5 = FUN_00588600(auStack_58);
        FUN_00401660(uVar5,0,0xffffffff);
        if (0xf < uStack_40) {
          _free(pvStack_54);
          return;
        }
        uStack_40 = 0xf;
        uStack_44 = 0;
        pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
        uVar5 = 0x55fe53;
        iVar11 = FUN_00403620(0,uStack_150,s_center_009bc3e0,6);
        if (iVar11 == 0) {
          *(undefined1 *)((int)piStack_170 + 0x196) = 1;
        }
        else {
          uVar5 = 0x55fe79;
          iVar11 = FUN_00403620(0,uStack_150,s_right_009bc3e8,5);
          *(byte *)((int)piStack_170 + 0x196) = (-(iVar11 != 0) & 0xfeU) + 2;
        }
      }
      else {
        uVar5 = 0x55fea2;
        iVar11 = FUN_00403620(0,uStack_150,s_autoline_009bc3f0,8);
        if (iVar11 == 0) {
          uVar6 = FUN_00588600(auStack_cc);
          uVar2 = thunk_FUN_00796fe0(uVar6);
          *(undefined1 *)((int)piStack_170 + 0x195) = uVar2;
          if (0xf < uStack_b4) {
            _free(pvStack_c8);
            return;
          }
          uStack_b4 = 0xf;
          uStack_b8 = 0;
          pvStack_c8 = (void *)((uint)pvStack_c8 & 0xffffff00);
        }
        else {
          uVar5 = 0x55ff10;
          iVar11 = FUN_00403620(0,uStack_150,s_<image>_009bc3fc,7);
          if (iVar11 == 0) {
            FUN_0055d1f0(piStack_170);
          }
          else {
            uVar5 = 0x55ff34;
            iVar11 = FUN_00403620(0,uStack_150,s_<title>_009bc404,7);
            if (iVar11 == 0) {
              FUN_0055dde0(&uStack_128);
              piVar19 = (int *)CONCAT13(1,(int3)piVar19);
            }
            else {
              pppppuVar8 = apppppuStack_140[0];
              if (uStack_12c < 0x10) {
                pppppuVar8 = apppppuStack_140;
              }
              uVar5 = 0x55ff6f;
              iVar11 = FUN_00403620(0,uStack_150,pppppuVar8,uStack_130);
              if (iVar11 == 0) {
                FUN_00588700(auStack_164);
                piVar4 = piStack_148;
                goto LAB_0055ffa9;
              }
            }
          }
        }
      }
    }
    else {
      uVar10 = uStack_150;
      if (8 < uStack_150) {
        uVar10 = 9;
      }
      pppppbVar12 = apppppbStack_160[0];
      if (uStack_14c < 0x10) {
        pppppbVar12 = (byte *****)apppppbStack_160;
      }
      bVar14 = false;
      iVar11 = 0;
      bVar15 = true;
      pbVar13 = (byte *)s_multiline_009bc3c0;
      do {
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        bVar14 = *(byte *)pppppbVar12 < *pbVar13;
        bVar15 = *(byte *)pppppbVar12 == *pbVar13;
        pppppbVar12 = (byte *****)((int)pppppbVar12 + 1);
        pbVar13 = pbVar13 + 1;
      } while (bVar15);
      if (!bVar15) {
        iVar11 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
      }
      if (((iVar11 != 0) || (uStack_150 < 9)) || (uStack_150 != 9)) goto code_r0x0055fd1c;
      uVar6 = FUN_00588600(auStack_20);
      uVar2 = thunk_FUN_00796fe0(uVar6);
      *(undefined1 *)(piStack_170 + 0x65) = uVar2;
      if ((int *)0xf < piStack_8) {
        _free(pvStack_1c);
        return;
      }
      piStack_8 = (int *)0xf;
      piStack_c = (int *)0x0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    }
LAB_0055ff73:
    cVar1 = FUN_005885f0();
    piVar4 = piStack_148;
  } while( true );
}


