// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x7f0000-0x7fffff

// ==== FUN_007f0000 @ 0x007f0000 ====

int FUN_007f0000(int param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if (iVar2 < 0) {
    iVar2 = FUN_007d1690(param_1 + 0x58,&local_8);
    if (iVar2 != 0) {
      *(byte *)(param_1 + 10) = *(byte *)(param_1 + 10) | 0x10;
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x30);
    lVar3 = __alldiv(local_8,local_4,iVar1,iVar1 >> 0x1f);
    iVar2 = (int)lVar3;
    if ((*(char *)(param_1 + 0x10) == '\0') && (lVar3 == (int)(0x40000000 / (longlong)iVar1))) {
      iVar2 = iVar2 + 1;
    }
    if (*(char *)(param_1 + 9) != '\0') {
      *(int *)(param_1 + 0x14) = iVar2;
    }
  }
  return iVar2;
}


// ==== FUN_007f0080 @ 0x007f0080 ====

void FUN_007f0080(void)

{
  int in_EAX;
  int unaff_EDI;
  
  if (*(int *)(in_EAX + 4) != 0) {
    if (*(int *)(in_EAX + 8) != 0) {
      *(undefined4 *)(*(int *)(in_EAX + 8) + 0xc) = *(undefined4 *)(in_EAX + 0xc);
    }
    if (*(int *)(in_EAX + 0xc) != 0) {
      *(undefined4 *)(*(int *)(in_EAX + 0xc) + 8) = *(undefined4 *)(in_EAX + 8);
      *(undefined4 *)(in_EAX + 4) = 0;
      *(undefined4 *)(in_EAX + 0xc) = 0;
      *(undefined4 *)(in_EAX + 8) = 0;
      return;
    }
    *(undefined4 *)(unaff_EDI + 0xc4 + (*(uint *)(in_EAX + 4) & 0x7ff) * 4) =
         *(undefined4 *)(in_EAX + 8);
    *(undefined4 *)(in_EAX + 4) = 0;
    *(undefined4 *)(in_EAX + 0xc) = 0;
    *(undefined4 *)(in_EAX + 8) = 0;
  }
  return;
}


// ==== FUN_007f00d0 @ 0x007f00d0 ====

void FUN_007f00d0(void)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  if (in_EAX == *(int **)(iVar1 + 0x7c)) {
    for (iVar2 = in_EAX[4]; (iVar2 != 0 && (*(char *)(iVar2 + 0x27) != '\0'));
        iVar2 = *(int *)(iVar2 + 0x10)) {
    }
    *(int *)(iVar1 + 0x7c) = iVar2;
  }
  if (in_EAX[5] == 0) {
    *(int *)(iVar1 + 0x74) = in_EAX[4];
  }
  else {
    *(int *)(in_EAX[5] + 0x10) = in_EAX[4];
  }
  if (in_EAX[4] == 0) {
    *(int *)(iVar1 + 0x78) = in_EAX[5];
  }
  else {
    *(int *)(in_EAX[4] + 0x14) = in_EAX[5];
  }
  in_EAX[5] = 0;
  in_EAX[4] = 0;
  if (in_EAX[1] != 0) {
    if (in_EAX[2] != 0) {
      *(int *)(in_EAX[2] + 0xc) = in_EAX[3];
    }
    if (in_EAX[3] != 0) {
      *(int *)(in_EAX[3] + 8) = in_EAX[2];
      in_EAX[1] = 0;
      in_EAX[3] = 0;
      in_EAX[2] = 0;
      return;
    }
    *(int *)(iVar1 + 0xc4 + (in_EAX[1] & 0x7ffU) * 4) = in_EAX[2];
    in_EAX[1] = 0;
    in_EAX[3] = 0;
    in_EAX[2] = 0;
  }
  return;
}


// ==== FUN_007f0170 @ 0x007f0170 ====

void FUN_007f0170(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int unaff_EBX;
  undefined4 *puVar5;
  int *piVar6;
  
  uVar1 = *(uint *)(unaff_EBX + 0x14);
  piVar6 = (int *)(unaff_EBX + 0x80);
  iVar2 = *(int *)(unaff_EBX + 0x80);
  while (iVar2 != 0) {
    if (uVar1 < *(uint *)(iVar2 + 4)) {
      if (*(short *)(iVar2 + 0x2a) < 1) {
        *piVar6 = *(int *)(iVar2 + 0x18);
        FUN_007f00d0();
        FUN_007d05b0(iVar2);
        *(int *)(unaff_EBX + 0x34) = *(int *)(unaff_EBX + 0x34) + -1;
      }
      else {
        uVar4 = *(uint *)(unaff_EBX + 0x30);
        puVar5 = (undefined4 *)(iVar2 + 0x30);
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar5 = 0;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
        piVar6 = (int *)(iVar2 + 0x18);
      }
    }
    else {
      piVar6 = (int *)(iVar2 + 0x18);
    }
    iVar2 = *piVar6;
  }
  return;
}


// ==== FUN_007f01e0 @ 0x007f01e0 ====

int FUN_007f01e0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 <= (int)(uint)*(byte *)(param_1 + 9)) {
    return 0;
  }
  iVar3 = 1;
  do {
    iVar2 = FUN_007d1850(param_1 + 0x58,param_2);
    if (iVar2 != 5) {
      if (iVar2 == 0) {
        *(undefined1 *)(param_1 + 9) = (undefined1)param_2;
      }
      return iVar2;
    }
    puVar1 = *(undefined4 **)(param_1 + 0x70);
    if (puVar1 == (undefined4 *)0x0) {
      return 5;
    }
    if ((code *)*puVar1 == (code *)0x0) {
      return 5;
    }
    iVar2 = (*(code *)*puVar1)(puVar1[1],iVar3);
    iVar3 = iVar3 + 1;
  } while (iVar2 != 0);
  return 5;
}


// ==== FUN_007f0250 @ 0x007f0250 ====

void FUN_007f0250(void)

{
  int iVar1;
  int *in_EAX;
  
  if (*(short *)((int)in_EAX + 0x2a) == 0) {
    if (in_EAX == *(int **)(*in_EAX + 0x7c)) {
      for (iVar1 = in_EAX[4]; (iVar1 != 0 && (*(char *)(iVar1 + 0x27) != '\0'));
          iVar1 = *(int *)(iVar1 + 0x10)) {
      }
      *(int *)(*in_EAX + 0x7c) = iVar1;
    }
    if (in_EAX[5] == 0) {
      *(int *)(*in_EAX + 0x74) = in_EAX[4];
    }
    else {
      *(int *)(in_EAX[5] + 0x10) = in_EAX[4];
    }
    if (in_EAX[4] != 0) {
      *(int *)(in_EAX[4] + 0x14) = in_EAX[5];
      *(int *)(*in_EAX + 0x3c) = *(int *)(*in_EAX + 0x3c) + 1;
      *(short *)((int)in_EAX + 0x2a) = *(short *)((int)in_EAX + 0x2a) + 1;
      return;
    }
    *(int *)(*in_EAX + 0x78) = in_EAX[5];
    *(int *)(*in_EAX + 0x3c) = *(int *)(*in_EAX + 0x3c) + 1;
  }
  *(short *)((int)in_EAX + 0x2a) = *(short *)((int)in_EAX + 0x2a) + 1;
  return;
}


// ==== FUN_007f02c0 @ 0x007f02c0 ====

undefined4 FUN_007f02c0(int param_1)

{
  if (*(short *)(param_1 + -6) == 0) {
    FUN_007f0250();
    return 0;
  }
  *(short *)(param_1 + -6) = *(short *)(param_1 + -6) + 1;
  return 0;
}


// ==== FUN_007f02e0 @ 0x007f02e0 ====

int FUN_007f02e0(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  if (*(char *)(unaff_ESI + 0xd) != '\0') {
    if (*(char *)(unaff_ESI + 0xb) == '\0') {
      if ((*(char *)(unaff_ESI + 8) != '\0') && (iVar1 = FUN_007d1630(unaff_ESI + 0x60), iVar1 != 0)
         ) {
        return iVar1;
      }
      iVar1 = unaff_ESI + 0x60;
      FUN_007d1600(iVar1,*(uint *)(unaff_ESI + 0x90) + 8,
                   *(int *)(unaff_ESI + 0x94) + (uint)(0xfffffff7 < *(uint *)(unaff_ESI + 0x90)));
      iVar2 = FUN_007eec70(iVar1);
      if (iVar2 != 0) {
        return iVar2;
      }
      FUN_007d1600(iVar1,*(undefined4 *)(unaff_ESI + 0x88),*(undefined4 *)(unaff_ESI + 0x8c));
      iVar1 = FUN_007d1630(iVar1);
      if (iVar1 != 0) {
        return iVar1;
      }
      *(undefined1 *)(unaff_ESI + 1) = 1;
    }
    iVar1 = *(int *)(unaff_ESI + 0x80);
    *(undefined1 *)(unaff_ESI + 0xd) = 0;
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
      *(undefined1 *)(iVar1 + 0x27) = 0;
    }
    *(undefined4 *)(unaff_ESI + 0x7c) = *(undefined4 *)(unaff_ESI + 0x74);
  }
  return 0;
}


// ==== FUN_007f0390 @ 0x007f0390 ====

int FUN_007f0390(void)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  undefined8 uVar3;
  
  if (in_EAX == (int *)0x0) {
    return 0;
  }
  iVar1 = *in_EAX;
  iVar2 = FUN_007f01e0(iVar1,4);
  if (iVar2 == 0) {
    do {
      uVar3 = __allmul(in_EAX[1] + -1,0,*(int *)(iVar1 + 0x30),*(int *)(iVar1 + 0x30) >> 0x1f);
      FUN_007d1600(iVar1 + 0x58,uVar3);
      if (((uint)in_EAX[1] <= *(uint *)(iVar1 + 0x14)) &&
         (iVar2 = FUN_007d15a0(iVar1 + 0x58,in_EAX + 0xc,*(undefined4 *)(iVar1 + 0x30)), iVar2 != 0)
         ) {
        return iVar2;
      }
      *(undefined1 *)((int)in_EAX + 0x26) = 0;
      in_EAX = (int *)in_EAX[0xb];
    } while (in_EAX != (int *)0x0);
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_007f0400 @ 0x007f0400 ====

void FUN_007f0400(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = 0;
  for (iVar1 = *(int *)(in_ECX + 0x80); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
    if (*(char *)(iVar1 + 0x26) != '\0') {
      *(int *)(iVar1 + 0x2c) = iVar2;
      iVar2 = iVar1;
    }
  }
  return;
}


// ==== FUN_007f0430 @ 0x007f0430 ====

undefined4 FUN_007f0430(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (*(char *)(unaff_ESI + 2) != '\0') {
    iVar1 = FUN_007d12b0(*(undefined4 *)(unaff_ESI + 0x50));
    if (iVar1 != 0) {
      iVar1 = FUN_007d1980(unaff_ESI + 0x58);
      if (iVar1 == 0) {
        iVar1 = FUN_007f0000();
        if (iVar1 != 0) {
          return 1;
        }
        FUN_007d12a0(*(undefined4 *)(unaff_ESI + 0x50));
      }
    }
  }
  return 0;
}


// ==== FUN_007f0480 @ 0x007f0480 ====

int FUN_007f0480(int param_1,uint param_2)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 10) & 0xfe) == 0) {
    iVar1 = *(int *)(param_1 + 0xc4 + (param_2 & 0x7ff) * 4);
    if (iVar1 != 0) {
      while (*(uint *)(iVar1 + 4) != param_2) {
        iVar1 = *(int *)(iVar1 + 8);
        if (iVar1 == 0) {
          return 0;
        }
      }
      if (iVar1 != 0) {
        if (*(short *)(iVar1 + 0x2a) == 0) {
          iVar1 = FUN_007f0250();
          return iVar1 + 0x30;
        }
        *(short *)(iVar1 + 0x2a) = *(short *)(iVar1 + 0x2a) + 1;
        return iVar1 + 0x30;
      }
    }
  }
  return 0;
}


// ==== FUN_007f04d0 @ 0x007f04d0 ====

void FUN_007f04d0(int param_1,uint param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    for (iVar1 = *(int *)(param_1 + 0xc4 + (param_2 & 0x7ff) * 4);
        (iVar1 != 0 && (*(uint *)(iVar1 + 4) != param_2)); iVar1 = *(int *)(iVar1 + 8)) {
    }
    *(undefined1 *)(iVar1 + 0x28) = 1;
    if ((*(char *)(iVar1 + 0x26) != '\0') &&
       ((*(int *)(param_1 + 0x14) != *(int *)(iVar1 + 4) ||
        (*(int *)(param_1 + 0x14) <= *(int *)(param_1 + 0x18))))) {
      *(undefined1 *)(iVar1 + 0x26) = 0;
    }
  }
  return;
}


// ==== FUN_007f0520 @ 0x007f0520 ====

void FUN_007f0520(int param_1)

{
  char *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  
  puVar3 = (undefined4 *)(param_1 + -0x30);
  pcVar1 = (char *)*puVar3;
  if ((((pcVar1[9] == '\x04') && (*pcVar1 != '\0')) && (*(char *)(param_1 + -8) == '\0')) &&
     ((pcVar1[0xf] == '\0' && (pcVar1[0x10] == '\0')))) {
    if ((*(char *)(param_1 + -0xc) == '\0') &&
       (uVar2 = *(uint *)(param_1 + -0x2c), (int)uVar2 <= *(int *)(pcVar1 + 0x18))) {
      pbVar4 = (byte *)(*(int *)(pcVar1 + 0x44) + (uVar2 >> 3));
      *pbVar4 = *pbVar4 | '\x01' << ((byte)uVar2 & 7);
      *(undefined1 *)(param_1 + -0xc) = 1;
      if (pcVar1[5] != '\0') {
        pbVar4 = (byte *)(*(int *)(pcVar1 + 0x48) + (*(uint *)(param_1 + -0x2c) >> 3));
        *pbVar4 = *pbVar4 | '\x01' << ((byte)*(uint *)(param_1 + -0x2c) & 7);
        puVar3 = (undefined4 *)FUN_007ef330();
      }
    }
    if (((pcVar1[5] != '\0') && (*(char *)((int)puVar3 + 0x25) == '\0')) &&
       (uVar2 = puVar3[1], (int)uVar2 <= *(int *)(pcVar1 + 0x1c))) {
      pbVar4 = (byte *)(*(int *)(pcVar1 + 0x48) + (uVar2 >> 3));
      *pbVar4 = *pbVar4 | '\x01' << ((byte)uVar2 & 7);
      FUN_007ef330();
      return;
    }
  }
  return;
}


// ==== FUN_007f05e0 @ 0x007f05e0 ====

undefined1 FUN_007f05e0(int param_1)

{
  return *(undefined1 *)(param_1 + 0xc);
}


// ==== FUN_007f05f0 @ 0x007f05f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007f05f0(int param_1)

{
  _DAT_00b5c5ec = *(undefined4 *)(param_1 + 0x3c);
  _DAT_00b5c5f0 = *(undefined4 *)(param_1 + 0x34);
  _DAT_00b5c5f4 = *(undefined4 *)(param_1 + 0x40);
  _DAT_00b5c5f8 = *(undefined4 *)(param_1 + 0x14);
  _DAT_00b5c5fc = (uint)*(byte *)(param_1 + 9);
  _DAT_00b5c600 = (uint)*(byte *)(param_1 + 10);
  return &DAT_00b5c5ec;
}


// ==== FUN_007f0640 @ 0x007f0640 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007f0640(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1[0x10] != '\0') {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x14);
    param_1[5] = '\x01';
    return 0;
  }
  if (*param_1 == '\0') {
    param_1[6] = '\x01';
    return 0;
  }
  iVar3 = FUN_007d0550(((int)(*(int *)(param_1 + 0x14) + (*(int *)(param_1 + 0x14) >> 0x1f & 7U)) >>
                       3) + 1);
  *(int *)(param_1 + 0x48) = iVar3;
  if (iVar3 == 0) {
    FUN_007d1850(param_1 + 0x58,1);
    return 7;
  }
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x14);
  cVar1 = param_1[4];
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x88);
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0x8c);
  param_1[0x98] = '\0';
  param_1[0x99] = '\0';
  param_1[0x9a] = '\0';
  param_1[0x9b] = '\0';
  param_1[0x9c] = '\0';
  param_1[0x9d] = '\0';
  param_1[0x9e] = '\0';
  param_1[0x9f] = '\0';
  *(undefined4 *)(param_1 + 0xa0) = uVar2;
  param_1[0xa4] = '\0';
  param_1[0xa5] = '\0';
  param_1[0xa6] = '\0';
  param_1[0xa7] = '\0';
  if (cVar1 == '\0') {
    iVar3 = FUN_007efbd0();
    if (iVar3 != 0) {
      if (*(int *)(param_1 + 0x48) != 0) {
        FUN_007d05b0(*(int *)(param_1 + 0x48));
        param_1[0x48] = '\0';
        param_1[0x49] = '\0';
        param_1[0x4a] = '\0';
        param_1[0x4b] = '\0';
      }
      return iVar3;
    }
    param_1[4] = '\x01';
    param_1[0x28] = '\0';
    param_1[0x29] = '\0';
    param_1[0x2a] = '\0';
    param_1[0x2b] = '\0';
  }
  param_1[5] = '\x01';
  return 0;
}


// ==== FUN_007f0790 @ 0x007f0790 ====

undefined4 FUN_007f0790(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 5) != '\0') {
    if (*(char *)(param_1 + 0x10) == '\0') {
      FUN_007d1600(param_1 + 0x68,0,0);
      FUN_007d05b0(*(undefined4 *)(param_1 + 0x48));
      *(undefined4 *)(param_1 + 0x48) = 0;
    }
    iVar2 = *(int *)(param_1 + 0x84);
    while (iVar1 = iVar2, iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x1c);
      *(undefined1 *)(iVar1 + 0x25) = 0;
      *(undefined4 *)(iVar1 + 0x1c) = 0;
      *(undefined4 *)(iVar1 + 0x20) = 0;
      if (*(char *)(param_1 + 0x10) != '\0') {
        iVar1 = *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x2c) + 0x30 + iVar1;
        FUN_007d05b0(*(undefined4 *)(iVar1 + 4));
        *(undefined4 *)(iVar1 + 4) = 0;
      }
    }
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined1 *)(param_1 + 5) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  *(undefined1 *)(param_1 + 6) = 0;
  return 0;
}


// ==== FUN_007f0820 @ 0x007f0820 ====

undefined4 FUN_007f0820(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (*(char *)(param_1 + 5) == '\0') {
    *(undefined1 *)(param_1 + 6) = 0;
    return 0;
  }
  if (*(char *)(param_1 + 0x10) == '\0') {
    uVar2 = FUN_007ef920();
    FUN_007f0790(param_1);
    *(undefined1 *)(param_1 + 6) = 0;
    return uVar2;
  }
  for (iVar1 = *(int *)(param_1 + 0x84); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
    uVar4 = *(uint *)(param_1 + 0x30);
    iVar5 = *(int *)(param_1 + 0x2c) + uVar4;
    puVar6 = *(undefined4 **)(iVar5 + 0x34 + iVar1);
    iVar5 = iVar5 + 0x30 + iVar1;
    if (puVar6 != (undefined4 *)0x0) {
      puVar7 = (undefined4 *)(iVar1 + 0x30);
      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      FUN_007d05b0(*(undefined4 *)(iVar5 + 4));
      *(undefined4 *)(iVar5 + 4) = 0;
    }
  }
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x1c);
  FUN_007f0170();
  FUN_007f0790(param_1);
  *(undefined1 *)(param_1 + 6) = 0;
  return 0;
}


// ==== FUN_007f08e0 @ 0x007f08e0 ====

undefined4 FUN_007f08e0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x4c);
}


// ==== FUN_007f08f0 @ 0x007f08f0 ====

undefined4 FUN_007f08f0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x54);
}


// ==== FUN_007f0900 @ 0x007f0900 ====

undefined4 FUN_007f0900(int param_1)

{
  return *(undefined4 *)(param_1 + 0x50);
}


// ==== FUN_007f0910 @ 0x007f0910 ====

undefined4 FUN_007f0910(void)

{
  int iVar1;
  undefined4 uVar2;
  char *unaff_ESI;
  
  if ((byte)unaff_ESI[9] < 2) {
    return 0;
  }
  FUN_007f0790();
  if (unaff_ESI[4] != '\0') {
    FUN_007d1530(unaff_ESI + 0x68);
    unaff_ESI[4] = '\0';
  }
  if (*unaff_ESI != '\0') {
    FUN_007d1530(unaff_ESI + 0x60);
    *unaff_ESI = '\0';
    FUN_007d12a0(*(undefined4 *)(unaff_ESI + 0x50));
    FUN_007d05b0(*(undefined4 *)(unaff_ESI + 0x44));
    iVar1 = *(int *)(unaff_ESI + 0x80);
    unaff_ESI[0x44] = '\0';
    unaff_ESI[0x45] = '\0';
    unaff_ESI[0x46] = '\0';
    unaff_ESI[0x47] = '\0';
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
      *(undefined1 *)(iVar1 + 0x24) = 0;
      *(undefined1 *)(iVar1 + 0x26) = 0;
      *(undefined1 *)(iVar1 + 0x27) = 0;
    }
    unaff_ESI[0xe] = '\0';
    unaff_ESI[0x20] = '\0';
    unaff_ESI[0x21] = '\0';
    unaff_ESI[0x22] = '\0';
    unaff_ESI[0x23] = '\0';
  }
  uVar2 = FUN_007d19d0(unaff_ESI + 0x58,1);
  unaff_ESI[0x18] = '\0';
  unaff_ESI[0x19] = '\0';
  unaff_ESI[0x1a] = '\0';
  unaff_ESI[0x1b] = '\0';
  unaff_ESI[0x11] = '\0';
  unaff_ESI[9] = '\x01';
  return uVar2;
}


// ==== FUN_007f09a0 @ 0x007f09a0 ====

/* WARNING: Removing unreachable block (ram,0x007f09eb) */
/* WARNING: Removing unreachable block (ram,0x007f0b5d) */
/* WARNING: Removing unreachable block (ram,0x007f0b61) */
/* WARNING: Removing unreachable block (ram,0x007f0b6c) */

int FUN_007f09a0(void)

{
  uint uVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  uint uVar4;
  int local_10;
  uint local_c;
  uint local_8;
  int local_4;
  
  local_10 = 0;
  iVar3 = FUN_007d1690();
  if (iVar3 != 0) {
    *(undefined4 *)(in_EAX + 0xb0) = 0x200;
    return iVar3;
  }
  iVar3 = FUN_007eed20();
  if (iVar3 == 0) {
    FUN_007d1600(in_EAX + 0x60,0,0);
    *(undefined4 *)(in_EAX + 0x88) = 0;
    *(undefined4 *)(in_EAX + 0x8c) = 0;
    iVar3 = FUN_007ef0d0(local_8,local_4,&local_c,&local_10);
    while (iVar3 == 0) {
      if (local_c == 0xffffffff) {
        uVar1 = *(uint *)(in_EAX + 0xb0);
        iVar3 = *(int *)(in_EAX + 0x30) + 8;
        local_c = __alldiv(local_8 - uVar1,
                           (local_4 - ((int)uVar1 >> 0x1f)) - (uint)(local_8 < uVar1),iVar3,
                           iVar3 >> 0x1f);
      }
      uVar1 = local_c;
      iVar2 = local_10;
      if (((3 < *(byte *)(in_EAX + 9)) && (*(int *)(in_EAX + 0x88) == *(int *)(in_EAX + 0xb0))) &&
         (*(int *)(in_EAX + 0x8c) == *(int *)(in_EAX + 0xb0) >> 0x1f)) {
        iVar3 = FUN_007d1650(in_EAX + 0x58,(longlong)*(int *)(in_EAX + 0x30) * (longlong)local_10);
        if (iVar3 != 0) goto LAB_007f0b55;
        *(int *)(in_EAX + 0x14) = iVar2;
      }
      uVar4 = 0;
      if (uVar1 != 0) {
        do {
          iVar3 = FUN_007ef400();
          if (iVar3 != 0) {
            if (iVar3 != 0x65) goto LAB_007f0b46;
            *(uint *)(in_EAX + 0x88) = local_8;
            *(int *)(in_EAX + 0x8c) = local_4;
            break;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
      }
      iVar3 = FUN_007ef0d0(local_8,local_4);
    }
  }
  else {
    FUN_007d05b0();
  }
  if (iVar3 != 0x65) {
LAB_007f0b46:
    if (iVar3 != 0) goto LAB_007f0b55;
  }
  iVar3 = FUN_007f0910();
LAB_007f0b55:
  *(undefined4 *)(in_EAX + 0xb0) = 0x200;
  return iVar3;
}


// ==== FUN_007f0ba0 @ 0x007f0ba0 ====

int FUN_007f0ba0(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  
  FUN_007f0000(param_1);
  bVar1 = *(byte *)(param_1 + 10);
  if (bVar1 == 0) {
    if (*(uint *)(param_1 + 0x14) <= param_2) {
      return 0;
    }
    if (*(char *)(param_1 + 0x10) != '\0') {
      *(uint *)(param_1 + 0x14) = param_2;
      FUN_007f0170();
      return 0;
    }
    iVar2 = FUN_007f02e0();
    if (((iVar2 == 0) && (iVar2 = FUN_007f01e0(param_1,4), iVar2 == 0)) &&
       (iVar2 = FUN_007ef900(param_2), iVar2 == 0)) {
      *(uint *)(param_1 + 0x14) = param_2;
    }
  }
  else {
    iVar2 = 0;
    if ((bVar1 & 4) != 0) {
      iVar2 = 0xf;
    }
    if ((bVar1 & 0x10) != 0) {
      iVar2 = 10;
    }
    if ((bVar1 & 1) != 0) {
      iVar2 = 0xd;
    }
    if ((bVar1 & 2) != 0) {
      iVar2 = 7;
    }
    if ((bVar1 & 8) != 0) {
      return 0xb;
    }
  }
  return iVar2;
}


// ==== FUN_007f0c50 @ 0x007f0c50 ====

int FUN_007f0c50(void)

{
  undefined1 *in_EAX;
  int iVar1;
  
  FUN_007f0000();
  iVar1 = FUN_007d0550(((int)(*(int *)(in_EAX + 0x14) + (*(int *)(in_EAX + 0x14) >> 0x1f & 7U)) >> 3
                       ) + 1);
  *(int *)(in_EAX + 0x44) = iVar1;
  if (iVar1 == 0) {
    iVar1 = 7;
LAB_007f0ce4:
    FUN_007d05b0(*(undefined4 *)(in_EAX + 0x44));
    *(undefined4 *)(in_EAX + 0x44) = 0;
    FUN_007d19d0(in_EAX + 0x58,0);
    in_EAX[9] = 0;
    return iVar1;
  }
  iVar1 = FUN_007d1350(*(undefined4 *)(in_EAX + 0x50),in_EAX + 0x60,in_EAX[0xb]);
  *(undefined4 *)(in_EAX + 0x88) = 0;
  *(undefined4 *)(in_EAX + 0x8c) = 0;
  in_EAX[0x11] = 0;
  *(undefined4 *)(in_EAX + 0x90) = 0;
  *(undefined4 *)(in_EAX + 0x94) = 0;
  if (iVar1 != 0) goto LAB_007f0ce4;
  FUN_004d8fb0(*(undefined4 *)(in_EAX + 0x54),in_EAX + 0x60);
  *in_EAX = 1;
  in_EAX[1] = 0;
  in_EAX[0xd] = 0;
  in_EAX[0xf] = 0;
  *(undefined4 *)(in_EAX + 0x20) = 0;
  if (in_EAX[10] != '\0') {
    iVar1 = FUN_007eece0();
    goto LAB_007f0ce4;
  }
  *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x14);
  iVar1 = FUN_007eef30();
  if (in_EAX[6] != '\0') {
    if (iVar1 != 0) goto LAB_007f0d28;
    iVar1 = FUN_007f0640();
  }
  if (iVar1 == 0) {
    return 0;
  }
LAB_007f0d28:
  iVar1 = FUN_007f0910();
  if (iVar1 == 0) {
    iVar1 = 0xd;
  }
  return iVar1;
}


// ==== FUN_007f0d40 @ 0x007f0d40 ====

int FUN_007f0d40(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + -0x30);
  iVar1 = 0;
  if (*(char *)(iVar2 + 9) == '\x01') {
    if (*(char *)(iVar2 + 0x10) == '\0') {
      iVar1 = FUN_007d1850(iVar2 + 0x58,2);
      if (iVar1 == 0) {
        *(undefined1 *)(iVar2 + 9) = 2;
        if (param_2 != 0) {
          iVar1 = FUN_007f01e0(iVar2,4);
        }
        if (((iVar1 == 0) && (*(undefined1 *)(iVar2 + 0xe) = 0, *(char *)(iVar2 + 2) != '\0')) &&
           (*(char *)(iVar2 + 0xb) == '\0')) {
          iVar2 = FUN_007f0c50();
          return iVar2;
        }
      }
    }
    else {
      *(undefined1 *)(iVar2 + 9) = 4;
      *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar2 + 0x14);
    }
  }
  return iVar1;
}


// ==== FUN_007f0db0 @ 0x007f0db0 ====

undefined4 FUN_007f0db0(char *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (param_1[0x10] != '\0') {
    for (iVar4 = *(int *)(param_1 + 0x80); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x18)) {
      if (*(char *)(iVar4 + 0x26) != '\0') {
        uVar6 = *(uint *)(param_1 + 0x30);
        puVar7 = *(undefined4 **)(*(int *)(param_1 + 0x2c) + uVar6 + 0x30 + iVar4);
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0x2c) + uVar6 + 0x30 + iVar4);
        if (puVar7 != (undefined4 *)0x0) {
          puVar8 = (undefined4 *)(iVar4 + 0x30);
          for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          }
        }
        FUN_007d05b0(*puVar1);
        FUN_007d05b0(puVar1[1]);
        *puVar1 = 0;
        puVar1[1] = 0;
        *(undefined1 *)(iVar4 + 0x26) = 0;
        *(undefined1 *)(iVar4 + 0x24) = 0;
        *(undefined1 *)(iVar4 + 0x25) = 0;
        *(undefined4 *)(iVar4 + 0x1c) = 0;
        *(undefined4 *)(iVar4 + 0x20) = 0;
        if (*(code **)(param_1 + 0xb8) != (code *)0x0) {
          (**(code **)(param_1 + 0xb8))(iVar4 + 0x30,*(undefined4 *)(param_1 + 0x30));
        }
      }
    }
    uVar2 = *(undefined4 *)(param_1 + 0x18);
    param_1[0x84] = '\0';
    param_1[0x85] = '\0';
    param_1[0x86] = '\0';
    param_1[0x87] = '\0';
    *(undefined4 *)(param_1 + 0x14) = uVar2;
    FUN_007f0170();
    param_1[5] = '\0';
    param_1[9] = '\x01';
    return 0;
  }
  if ((param_1[0xe] == '\0') || (*param_1 == '\0')) {
    uVar2 = FUN_007f0910();
  }
  else {
    if ((param_1[10] != '\0') && (param_1[10] != '\x01')) {
      if (3 < (byte)param_1[9]) {
        FUN_007f09a0();
      }
      uVar2 = FUN_007eece0();
      return uVar2;
    }
    if (param_1[9] == '\x02') {
      iVar3 = FUN_007ef7c0();
      iVar4 = FUN_007f0910();
      if (iVar3 != 0) goto LAB_007f0ec5;
    }
    else {
      iVar4 = FUN_007f09a0();
    }
    uVar2 = 0;
    if (iVar4 != 0) {
LAB_007f0ec5:
      param_1[10] = param_1[10] | 8;
      param_1[0x14] = -1;
      param_1[0x15] = -1;
      param_1[0x16] = -1;
      param_1[0x17] = -1;
      return 0xb;
    }
  }
  param_1[0x14] = -1;
  param_1[0x15] = -1;
  param_1[0x16] = -1;
  param_1[0x17] = -1;
  return uVar2;
}


// ==== FUN_007f0ef0 @ 0x007f0ef0 ====

void FUN_007f0ef0(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 *puVar3;
  
  if (*(char *)(unaff_ESI + 10) == '\0') {
    iVar2 = *(int *)(unaff_ESI + 0x80);
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x18);
      FUN_007d05b0(iVar2);
      iVar2 = iVar1;
    }
    *(undefined4 *)(unaff_ESI + 0x74) = 0;
    *(undefined4 *)(unaff_ESI + 0x7c) = 0;
    *(undefined4 *)(unaff_ESI + 0x78) = 0;
    *(undefined4 *)(unaff_ESI + 0x80) = 0;
    puVar3 = (undefined4 *)(unaff_ESI + 0xc4);
    for (iVar2 = 0x800; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *(undefined4 *)(unaff_ESI + 0x34) = 0;
    if (1 < *(byte *)(unaff_ESI + 9)) {
      FUN_007f0db0();
    }
    FUN_007d19d0(unaff_ESI + 0x58,0);
    *(undefined1 *)(unaff_ESI + 9) = 0;
    *(undefined4 *)(unaff_ESI + 0x14) = 0xffffffff;
    *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  }
  return;
}


// ==== FUN_007f0f70 @ 0x007f0f70 ====

undefined4 FUN_007f0f70(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  switch(param_1[9]) {
  case '\x01':
    cVar1 = param_1[0x10];
    break;
  case '\x02':
  case '\x04':
  case '\x05':
    FUN_007f0db0(param_1);
    cVar1 = param_1[0x10];
    break;
  default:
    goto switchD_007f0f7f_caseD_3;
  }
  if (cVar1 == '\0') {
    FUN_007d19d0(param_1 + 0x58,0);
  }
switchD_007f0f7f_caseD_3:
  iVar3 = *(int *)(param_1 + 0x80);
  while (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + 0x18);
    FUN_007d05b0(iVar3);
    iVar3 = iVar2;
  }
  if (*param_1 != '\0') {
    FUN_007d1530(param_1 + 0x60);
  }
  FUN_007d05b0(*(undefined4 *)(param_1 + 0x44));
  if (param_1[4] != '\0') {
    FUN_007d1530(param_1 + 0x68);
  }
  FUN_007d1530(param_1 + 0x58);
  FUN_007d05b0(param_1);
  return 0;
}


// ==== FUN_007f1030 @ 0x007f1030 ====

undefined4 FUN_007f1030(int param_1)

{
  short *psVar1;
  int *piVar2;
  int iVar3;
  
  psVar1 = (short *)(param_1 + -6);
  *psVar1 = *psVar1 + -1;
  piVar2 = (int *)(param_1 + -0x30);
  if (*psVar1 != 0) {
    return 0;
  }
  iVar3 = *piVar2;
  *(undefined4 *)(param_1 + -0x20) = 0;
  *(undefined4 *)(param_1 + -0x1c) = *(undefined4 *)(iVar3 + 0x78);
  *(int **)(iVar3 + 0x78) = piVar2;
  if (*(int *)(param_1 + -0x1c) == 0) {
    *(int **)(iVar3 + 0x74) = piVar2;
  }
  else {
    *(int **)(*(int *)(param_1 + -0x1c) + 0x10) = piVar2;
  }
  if ((*(char *)(param_1 + -9) == '\0') && (*(int *)(iVar3 + 0x7c) == 0)) {
    *(int **)(iVar3 + 0x7c) = piVar2;
  }
  if (*(code **)(iVar3 + 0xb4) != (code *)0x0) {
    (**(code **)(iVar3 + 0xb4))(param_1,*(undefined4 *)(iVar3 + 0x30));
  }
  piVar2 = (int *)(iVar3 + 0x3c);
  *piVar2 = *piVar2 + -1;
  if ((*piVar2 == 0) && (*(char *)(iVar3 + 0x10) == '\0')) {
    FUN_007f0ef0();
  }
  return 0;
}


// ==== FUN_007f10a0 @ 0x007f10a0 ====

int FUN_007f10a0(undefined4 *param_1)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int local_8;
  
  pcVar3 = (char *)param_1[-0xc];
  bVar2 = pcVar3[10];
  local_8 = 0;
  if (bVar2 == 0) {
    if (pcVar3[0xc] != '\0') {
      return 3;
    }
    *(undefined1 *)((int)param_1 + -10) = 1;
    if ((*(char *)(param_1 + -3) == '\0') ||
       ((*(char *)((int)param_1 + -0xb) == '\0' && (pcVar3[5] != '\0')))) {
      iVar7 = FUN_007f0d40(param_1,0);
      if (iVar7 != 0) {
        return iVar7;
      }
      local_8 = 0;
      if (((*pcVar3 == '\0') && (pcVar3[2] != '\0')) && (local_8 = FUN_007f0c50(), local_8 != 0)) {
        return local_8;
      }
      pcVar3[0xe] = '\x01';
      if ((*(char *)(param_1 + -3) == '\0') && ((pcVar3[2] != '\0' || (pcVar3[0x10] != '\0')))) {
        if (*(int *)(pcVar3 + 0x18) < (int)param_1[-0xb]) {
          if ((pcVar3[1] == '\0') && (pcVar3[7] == '\0')) {
            *(undefined1 *)((int)param_1 + -9) = 1;
          }
          else {
            *(undefined1 *)((int)param_1 + -9) = 0;
          }
        }
        else if (pcVar3[0x10] == '\0') {
          uVar5 = *(undefined4 *)((int)param_1 + *(int *)(pcVar3 + 0x30));
          FUN_007ef3d0();
          FUN_007eecb0();
          uVar6 = param_1[-0xb];
          uVar10 = *(int *)(pcVar3 + 0x30) + 8;
          *(char *)(param_1 + -1) = (char)((uint)uVar6 >> 0x18);
          *(char *)((int)param_1 + -3) = (char)((uint)uVar6 >> 0x10);
          *(char *)((int)param_1 + -2) = (char)((uint)uVar6 >> 8);
          *(char *)((int)param_1 + -1) = (char)uVar6;
          iVar7 = FUN_007d15a0(pcVar3 + 0x60,param_1 + -1,uVar10);
          *(uint *)(pcVar3 + 0x8c) =
               *(int *)(pcVar3 + 0x8c) + ((int)uVar10 >> 0x1f) +
               (uint)CARRY4(*(uint *)(pcVar3 + 0x88),uVar10);
          *(uint *)(pcVar3 + 0x88) = *(uint *)(pcVar3 + 0x88) + uVar10;
          *(undefined4 *)((int)param_1 + *(int *)(pcVar3 + 0x30)) = uVar5;
          if (iVar7 != 0) {
            FUN_007f0db0(pcVar3);
            pcVar3[10] = pcVar3[10] | 1;
            return iVar7;
          }
          *(int *)(pcVar3 + 0x20) = *(int *)(pcVar3 + 0x20) + 1;
          pbVar1 = (byte *)(((uint)param_1[-0xb] >> 3) + *(int *)(pcVar3 + 0x44));
          *pbVar1 = *pbVar1 | '\x01' << ((byte)param_1[-0xb] & 7);
          *(bool *)((int)param_1 + -9) = pcVar3[7] == '\0';
          local_8 = 0;
          if (pcVar3[5] != '\0') {
            pbVar1 = (byte *)(((uint)param_1[-0xb] >> 3) + *(int *)(pcVar3 + 0x48));
            *pbVar1 = *pbVar1 | '\x01' << ((byte)param_1[-0xb] & 7);
            FUN_007ef330();
          }
        }
        else {
          iVar7 = *(int *)(pcVar3 + 0x30);
          iVar4 = *(int *)(pcVar3 + 0x2c);
          puVar8 = (undefined4 *)FUN_007d0590(iVar7);
          *(undefined4 **)((int)param_1 + iVar4 + iVar7) = puVar8;
          if (puVar8 != (undefined4 *)0x0) {
            uVar10 = *(uint *)(pcVar3 + 0x30);
            puVar11 = param_1;
            for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *puVar8 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar8 = puVar8 + 1;
            }
            for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
              *(undefined1 *)puVar8 = *(undefined1 *)puVar11;
              puVar11 = (undefined4 *)((int)puVar11 + 1);
              puVar8 = (undefined4 *)((int)puVar8 + 1);
            }
          }
        }
        if (*(char *)((int)param_1 + -9) != '\0') {
          pcVar3[0xd] = '\x01';
        }
        *(undefined1 *)(param_1 + -3) = 1;
      }
      if (((pcVar3[5] != '\0') && (*(char *)((int)param_1 + -0xb) == '\0')) &&
         (iVar7 = param_1[-0xb], iVar7 <= *(int *)(pcVar3 + 0x1c))) {
        if (pcVar3[0x10] == '\0') {
          *(char *)(param_1 + -1) = (char)((uint)iVar7 >> 0x18);
          *(char *)((int)param_1 + -3) = (char)((uint)iVar7 >> 0x10);
          *(char *)((int)param_1 + -1) = (char)iVar7;
          *(char *)((int)param_1 + -2) = (char)((uint)iVar7 >> 8);
          iVar7 = FUN_007d15a0(pcVar3 + 0x68,param_1 + -1,*(int *)(pcVar3 + 0x30) + 4);
          if (iVar7 != 0) {
            FUN_007f0db0(pcVar3);
            pcVar3[10] = pcVar3[10] | 1;
            return iVar7;
          }
          *(int *)(pcVar3 + 0x28) = *(int *)(pcVar3 + 0x28) + 1;
          pbVar1 = (byte *)(((uint)param_1[-0xb] >> 3) + *(int *)(pcVar3 + 0x48));
          *pbVar1 = *pbVar1 | '\x01' << ((byte)param_1[-0xb] & 7);
          local_8 = 0;
        }
        else {
          iVar7 = *(int *)(pcVar3 + 0x30);
          iVar4 = *(int *)(pcVar3 + 0x2c);
          puVar8 = (undefined4 *)FUN_007d0590(iVar7);
          *(undefined4 **)((int)param_1 + iVar4 + iVar7 + 4) = puVar8;
          if (puVar8 != (undefined4 *)0x0) {
            uVar10 = *(uint *)(pcVar3 + 0x30);
            puVar11 = param_1;
            for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *puVar8 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar8 = puVar8 + 1;
            }
            for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
              *(undefined1 *)puVar8 = *(undefined1 *)puVar11;
              puVar11 = (undefined4 *)((int)puVar11 + 1);
              puVar8 = (undefined4 *)((int)puVar8 + 1);
            }
          }
        }
        FUN_007ef330();
      }
    }
    else {
      pcVar3[0xe] = '\x01';
    }
    iVar7 = param_1[-0xb];
    if (((*(int *)(pcVar3 + 0x14) < iVar7) &&
        (*(int *)(pcVar3 + 0x14) = iVar7, pcVar3[0x10] == '\0')) &&
       (iVar7 == (int)(0x40000000 / (longlong)*(int *)(pcVar3 + 0x30)))) {
      *(int *)(pcVar3 + 0x14) = iVar7 + 1;
    }
  }
  else {
    local_8 = 0;
    if ((bVar2 & 4) != 0) {
      local_8 = 0xf;
    }
    if ((bVar2 & 0x10) != 0) {
      local_8 = 10;
    }
    if ((bVar2 & 1) != 0) {
      local_8 = 0xd;
    }
    if ((bVar2 & 2) != 0) {
      local_8 = 7;
    }
    if ((bVar2 & 8) != 0) {
      return 0xb;
    }
  }
  return local_8;
}


// ==== FUN_007f1420 @ 0x007f1420 ====

int FUN_007f1420(undefined1 *param_1,uint param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  uint local_8;
  int local_4;
  
  if ((0x7fffffff < param_2) || (param_2 == 0)) {
    return 0xb;
  }
  *param_3 = 0;
  if ((param_1[10] & 0xfe) != 0) {
    iVar2 = FUN_007eece0();
    return iVar2;
  }
  if ((*(int *)(param_1 + 0x3c) == 0) && (param_1[0x10] == '\0')) {
    if ((param_1[3] == '\0') && (iVar2 = FUN_007f01e0(param_1,1), iVar2 != 0)) {
      return iVar2;
    }
    iVar2 = FUN_007f0430();
    if (iVar2 != 0) {
      puVar1 = param_1 + 0x58;
      iVar2 = FUN_007d1850(puVar1,4);
      if (iVar2 != 0) {
        FUN_007d19d0(puVar1,0);
        param_1[9] = 0;
        return iVar2;
      }
      param_1[9] = 4;
      iVar2 = FUN_007d13a0(*(undefined4 *)(param_1 + 0x50),param_1 + 0x60);
      if (iVar2 != 0) {
        FUN_007d19d0(puVar1,0);
        param_1[9] = 0;
        return 5;
      }
      *param_1 = 1;
      param_1[1] = 0;
      *(undefined4 *)(param_1 + 0x88) = 0;
      *(undefined4 *)(param_1 + 0x8c) = 0;
      param_1[0x11] = 0;
      *(undefined4 *)(param_1 + 0x90) = 0;
      *(undefined4 *)(param_1 + 0x94) = 0;
      iVar2 = FUN_007f09a0();
      if (iVar2 != 0) {
        return iVar2;
      }
    }
  }
  else {
    puVar3 = (undefined4 *)FUN_007ef3b0();
    if ((param_1[0x10] != '\0') && (param_1[9] == '\0')) {
      param_1[9] = 1;
    }
    if (puVar3 != (undefined4 *)0x0) {
      if (*(short *)((int)puVar3 + 0x2a) == 0) {
        FUN_007f0250();
        *param_3 = puVar3 + 0xc;
        return 0;
      }
      *(short *)((int)puVar3 + 0x2a) = *(short *)((int)puVar3 + 0x2a) + 1;
      goto LAB_007f182e;
    }
  }
  if (((*(int *)(param_1 + 0x34) < *(int *)(param_1 + 0x40)) || (*(int *)(param_1 + 0x74) == 0)) ||
     (param_1[0x10] != '\0')) {
    puVar3 = (undefined4 *)
             FUN_007d0590(*(int *)(param_1 + 0x30) + (uint)(byte)param_1[0x10] * 8 + 0x34 +
                          *(int *)(param_1 + 0x2c));
    if (puVar3 == (undefined4 *)0x0) {
      param_1[10] = param_1[10] | 2;
      return 7;
    }
    puVar7 = puVar3;
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    if (param_1[0x10] != '\0') {
      puVar7 = (undefined4 *)
               (*(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x2c) + 0x30 + (int)puVar3);
      *puVar7 = 0;
      puVar7[1] = 0;
    }
    *puVar3 = param_1;
    puVar3[6] = *(undefined4 *)(param_1 + 0x80);
    iVar2 = *(int *)(param_1 + 0x34);
    *(undefined4 **)(param_1 + 0x80) = puVar3;
    *(int *)(param_1 + 0x34) = iVar2 + 1;
    if (*(int *)(param_1 + 0x38) < iVar2 + 1) {
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
    }
  }
  else {
    puVar3 = *(undefined4 **)(param_1 + 0x7c);
    if (puVar3 == (undefined4 *)0x0) {
      iVar2 = FUN_007f02e0();
      if (iVar2 != 0) goto LAB_007f15aa;
      if (param_1[8] != '\0') {
        *(undefined4 *)(param_1 + 0x20) = 0;
        iVar2 = FUN_007eef30();
        if (iVar2 != 0) goto LAB_007f15aa;
      }
      puVar3 = *(undefined4 **)(param_1 + 0x74);
    }
    if (*(char *)((int)puVar3 + 0x26) != '\0') {
      puVar3[0xb] = 0;
      iVar2 = FUN_007f0390();
      if (iVar2 != 0) {
LAB_007f15aa:
        FUN_007f0db0(param_1);
        return 10;
      }
    }
    if (*(char *)(puVar3 + 10) != '\0') {
      param_1[0xf] = 1;
    }
    FUN_007f00d0();
  }
  puVar3[1] = param_2;
  if ((*(int *)(param_1 + 0x44) == 0) || (*(int *)(param_1 + 0x18) < (int)param_2)) {
    *(undefined1 *)(puVar3 + 9) = 0;
  }
  else {
    *(bool *)(puVar3 + 9) =
         (*(byte *)((param_2 >> 3) + *(int *)(param_1 + 0x44)) & (byte)(1 << ((byte)param_2 & 7)))
         != 0;
  }
  *(undefined1 *)((int)puVar3 + 0x27) = 0;
  if (((*(int *)(param_1 + 0x48) == 0) || (*(int *)(param_1 + 0x1c) < (int)param_2)) ||
     ((*(byte *)((param_2 >> 3) + *(int *)(param_1 + 0x48)) & (byte)(1 << ((byte)param_2 & 7))) == 0
     )) {
    FUN_007ef370();
  }
  else {
    FUN_007ef330();
  }
  *(undefined1 *)((int)puVar3 + 0x26) = 0;
  *(undefined2 *)((int)puVar3 + 0x2a) = 1;
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  puVar3[2] = *(undefined4 *)(param_1 + (param_2 & 0x7ff) * 4 + 0xc4);
  *(undefined4 **)(param_1 + (param_2 & 0x7ff) * 4 + 0xc4) = puVar3;
  if (puVar3[2] != 0) {
    *(undefined4 **)(puVar3[2] + 0xc) = puVar3;
  }
  uVar6 = *(uint *)(param_1 + 0x2c);
  if (0 < (int)uVar6) {
    puVar7 = (undefined4 *)(*(int *)(param_1 + 0x30) + 0x30 + (int)puVar3);
    for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar7 = 0;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
  }
  if (param_1[10] != '\0') {
    FUN_007f1030(puVar3 + 0xc);
    iVar2 = FUN_007eece0();
    return iVar2;
  }
  iVar2 = FUN_007f0000(param_1);
  if (iVar2 < (int)param_2) {
    uVar6 = *(uint *)(param_1 + 0x30);
    puVar7 = puVar3 + 0xc;
    for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar7 = 0;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    *param_3 = puVar3 + 0xc;
    return 0;
  }
  puVar1 = param_1 + 0x58;
  uVar8 = __allmul(param_2 - 1,0,*(int *)(param_1 + 0x30),*(int *)(param_1 + 0x30) >> 0x1f);
  FUN_007d1600(puVar1,uVar8);
  puVar7 = puVar3 + 0xc;
  iVar2 = FUN_007d1550(puVar1,puVar7,*(undefined4 *)(param_1 + 0x30));
  if (iVar2 != 0) {
    iVar4 = FUN_007d1690(puVar1,&local_8);
    if (iVar4 == 0) {
      uVar6 = *(uint *)(param_1 + 0x30);
      if ((local_4 < 1) && ((local_4 < 0 || (local_8 < uVar6 * param_2)))) {
        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar7 = 0;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        *param_3 = puVar3 + 0xc;
        return 0;
      }
    }
    FUN_007f1030(puVar7);
    return iVar2;
  }
LAB_007f182e:
  *param_3 = puVar3 + 0xc;
  return 0;
}


// ==== FUN_007f1850 @ 0x007f1850 ====

int FUN_007f1850(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *local_4;
  
  iVar1 = FUN_007f1420(param_1,param_2,&local_4);
  if (iVar1 == 0) {
    iVar1 = FUN_007f10a0(local_4);
    if (iVar1 == 0) {
      uVar3 = *(uint *)(param_1 + 0x30);
      puVar4 = local_4;
      for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = *param_3;
        param_3 = param_3 + 1;
        puVar4 = puVar4 + 1;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar4 = *(undefined1 *)param_3;
        param_3 = (undefined4 *)((int)param_3 + 1);
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
    }
    FUN_007f1030(local_4);
  }
  return iVar1;
}


// ==== FUN_007f18b0 @ 0x007f18b0 ====

int FUN_007f18b0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_007f1420();
  if ((iVar1 == 0) && (iVar1 = FUN_007f10a0(in_ECX), iVar1 == 0)) {
    iVar1 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(in_ECX + 0x18),*(undefined1 *)(in_ECX + 0x19)
                                      ),*(undefined1 *)(in_ECX + 0x1a)),
                     *(undefined1 *)(in_ECX + 0x1b)) + 1;
    *(char *)(in_ECX + 0x18) = (char)((uint)iVar1 >> 0x18);
    *(char *)(in_ECX + 0x19) = (char)((uint)iVar1 >> 0x10);
    *(char *)(in_ECX + 0x1a) = (char)((uint)iVar1 >> 8);
    *(char *)(in_ECX + 0x1b) = (char)iVar1;
    FUN_007f1030(in_ECX);
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_007f1920 @ 0x007f1920 ====

int FUN_007f1920(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = param_1;
  if (*(char *)(param_1 + 9) == '\x05') {
    return 0;
  }
  if (*(char *)(param_1 + 0x10) != '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0xe) == '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x11) == '\0') {
    iVar2 = FUN_007f18b0();
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((param_3 != 0) && (uVar4 = param_3 + 1, uVar4 <= *(uint *)(iVar1 + 0x18))) {
      do {
        if ((*(byte *)((uVar4 >> 3) + *(int *)(iVar1 + 0x44)) & (byte)(1 << ((byte)uVar4 & 7))) == 0
           ) {
          iVar3 = FUN_007f1420(iVar1,uVar4,&param_1);
          iVar2 = param_1;
          if (iVar3 != 0) {
            return iVar3;
          }
          iVar3 = FUN_007f10a0(param_1);
          FUN_007f1030(iVar2);
          if (iVar3 != 0) {
            return iVar3;
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 <= *(uint *)(iVar1 + 0x18));
    }
    iVar2 = FUN_007ef1f0(param_2);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = FUN_007f02e0();
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  if ((param_3 == 0) || (iVar2 = FUN_007f0ba0(iVar1,param_3), iVar2 == 0)) {
    FUN_007f0400();
    iVar2 = FUN_007f0390();
    if (iVar2 == 0) {
      if (*(char *)(iVar1 + 7) == '\0') {
        iVar2 = FUN_007d1630(iVar1 + 0x58);
      }
      *(undefined1 *)(iVar1 + 9) = 5;
    }
  }
  return iVar2;
}


// ==== FUN_007f1a40 @ 0x007f1a40 ====

int FUN_007f1a40(int param_1,int param_2,uint param_3)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = param_3;
  iVar4 = param_2;
  pcVar1 = (char *)(param_2 + -9);
  iVar6 = param_2 + -0x30;
  param_2 = 0;
  if (*pcVar1 != '\0') {
    param_2 = *(int *)(iVar4 + -0x2c);
  }
  if (*(int *)(iVar4 + -0x2c) != 0) {
    if (*(int *)(iVar4 + -0x28) != 0) {
      *(undefined4 *)(*(int *)(iVar4 + -0x28) + 0xc) = *(undefined4 *)(iVar4 + -0x24);
    }
    if (*(int *)(iVar4 + -0x24) == 0) {
      *(undefined4 *)(param_1 + 0xc4 + (*(uint *)(iVar4 + -0x2c) & 0x7ff) * 4) =
           *(undefined4 *)(iVar4 + -0x28);
    }
    else {
      *(undefined4 *)(*(int *)(iVar4 + -0x24) + 8) = *(undefined4 *)(iVar4 + -0x28);
    }
    *(undefined4 *)(iVar4 + -0x2c) = 0;
    *(undefined4 *)(iVar4 + -0x24) = 0;
    *(undefined4 *)(iVar4 + -0x28) = 0;
  }
  uVar5 = param_3 & 0x7ff;
  iVar3 = *(int *)(param_1 + 0xc4 + uVar5 * 4);
  do {
    if (iVar3 == 0) {
LAB_007f1adf:
      *(uint *)(iVar4 + -0x2c) = uVar2;
      iVar3 = *(int *)(param_1 + 0xc4 + uVar5 * 4);
      if (iVar3 != 0) {
        *(int *)(iVar3 + 0xc) = iVar6;
      }
      *(undefined4 *)(iVar4 + -0x28) = *(undefined4 *)(param_1 + 0xc4 + uVar5 * 4);
      *(int *)(param_1 + 0xc4 + uVar5 * 4) = iVar6;
      *(undefined4 *)(iVar4 + -0x24) = 0;
      *(undefined1 *)(iVar4 + -10) = 1;
      *(undefined1 *)(param_1 + 0xe) = 1;
      if (param_2 != 0) {
        iVar4 = FUN_007f1420(param_1,param_2,&param_2);
        if (iVar4 != 0) {
          return iVar4;
        }
        *(undefined1 *)(param_1 + 0xd) = 1;
        *(undefined1 *)(param_2 + -9) = 1;
        *(undefined1 *)(param_2 + -0xc) = 1;
        *(undefined1 *)(param_2 + -10) = 1;
        FUN_007f1030(param_2);
      }
      return 0;
    }
    if (*(uint *)(iVar3 + 4) == param_3) {
      if (iVar3 != 0) {
        iVar3 = FUN_007f0080();
        *(undefined1 *)(iVar3 + 0x26) = 0;
        if (*(char *)(iVar3 + 0x27) != '\0') {
          *(undefined1 *)(iVar4 + -0xc) = 1;
          *(undefined1 *)(iVar4 + -9) = 1;
        }
      }
      goto LAB_007f1adf;
    }
    iVar3 = *(int *)(iVar3 + 8);
  } while( true );
}


// ==== FUN_007f1b50 @ 0x007f1b50 ====

int FUN_007f1b50(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 10) == '\x01') {
    iVar2 = FUN_007f0db0(param_1);
    if (iVar2 == 0) {
      return 0xd;
    }
  }
  else {
    if (*(char *)(param_1 + 10) != '\0') {
      iVar2 = FUN_007eece0();
      return iVar2;
    }
    if (*(byte *)(param_1 + 9) < 2) {
      return 1;
    }
    if (*(char *)(param_1 + 0x10) != '\0') {
      for (iVar2 = FUN_007f0400(); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x2c)) {
        iVar3 = *(int *)(param_1 + 0x30) + iVar2;
        puVar1 = (undefined4 *)(iVar3 + 0x30 + *(int *)(param_1 + 0x2c));
        FUN_007d05b0(*(undefined4 *)(iVar3 + 0x30 + *(int *)(param_1 + 0x2c)));
        FUN_007d05b0(puVar1[1]);
        *puVar1 = 0;
        puVar1[1] = 0;
        *(undefined1 *)(iVar2 + 0x26) = 0;
        *(undefined1 *)(iVar2 + 0x24) = 0;
        *(undefined1 *)(iVar2 + 0x25) = 0;
        *(undefined4 *)(iVar2 + 0x1c) = 0;
        *(undefined4 *)(iVar2 + 0x20) = 0;
      }
      *(undefined4 *)(param_1 + 0x84) = 0;
      *(undefined1 *)(param_1 + 9) = 1;
      return 0;
    }
    if ((*(char *)(param_1 + 0xe) != '\0') && (iVar2 = FUN_007f1920(param_1,0,0), iVar2 != 0)) {
      FUN_007f0db0(param_1);
      return iVar2;
    }
    iVar2 = FUN_007f0910();
    *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
  }
  return iVar2;
}


// ==== FUN_007f1c30 @ 0x007f1c30 ====

int FUN_007f1c30(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  int iVar10;
  int local_14;
  
  local_14 = 0;
  puVar9 = &param_1;
  while( true ) {
    iVar7 = puVar9[1];
    iVar2 = puVar9[2];
    iVar3 = puVar9[3];
    piVar4 = (int *)puVar9[5];
    iVar5 = puVar9[4];
    puVar9 = puVar9 + 5;
    iVar10 = 0;
    pbVar8 = param_1;
    if (iVar7 != 0) {
      do {
        iVar7 = iVar7 + -1;
        iVar6 = _isdigit((uint)*pbVar8);
        if (iVar6 == 0) {
          return local_14;
        }
        bVar1 = *pbVar8;
        pbVar8 = pbVar8 + 1;
        iVar10 = (char)bVar1 + -0x30 + iVar10 * 10;
      } while (iVar7 != 0);
    }
    if (iVar10 < iVar2) {
      return local_14;
    }
    if (iVar3 < iVar10) {
      return local_14;
    }
    if ((iVar5 != 0) && (iVar5 != (char)*pbVar8)) break;
    *piVar4 = iVar10;
    param_1 = pbVar8 + 1;
    local_14 = local_14 + 1;
    if (iVar5 == 0) {
      return local_14;
    }
  }
  return local_14;
}


// ==== FUN_007f1cf0 @ 0x007f1cf0 ====

bool FUN_007f1cf0(void)

{
  byte *pbVar1;
  byte bVar2;
  byte *in_EAX;
  int iVar3;
  int iVar4;
  int unaff_EBX;
  byte *pbVar5;
  int local_8;
  int local_4;
  
  iVar3 = _isspace((uint)*in_EAX);
  while (iVar3 != 0) {
    pbVar5 = in_EAX + 1;
    in_EAX = in_EAX + 1;
    iVar3 = _isspace((uint)*pbVar5);
  }
  *(undefined4 *)(unaff_EBX + 0x1c) = 0;
  bVar2 = *in_EAX;
  if (bVar2 == 0x2d) {
    iVar3 = -1;
  }
  else {
    if (bVar2 != 0x2b) {
      return bVar2 != 0;
    }
    iVar3 = 1;
  }
  iVar4 = FUN_007f1c30(in_EAX + 1,2,0,0xe,0x3a,&local_8,2,0,0x3b,0,&local_4);
  if (iVar4 != 2) {
    return true;
  }
  pbVar5 = in_EAX + 6;
  *(int *)(unaff_EBX + 0x1c) = (local_8 * 0x3c + local_4) * iVar3;
  iVar3 = _isspace((uint)*pbVar5);
  while (iVar3 != 0) {
    pbVar1 = pbVar5 + 1;
    pbVar5 = pbVar5 + 1;
    iVar3 = _isspace((uint)*pbVar1);
  }
  return *pbVar5 != 0;
}


// ==== FUN_007f1dd0 @ 0x007f1dd0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007f1dd0(void)

{
  byte *pbVar1;
  char cVar2;
  double dVar3;
  int in_EAX;
  int iVar4;
  char *pcVar5;
  int unaff_EDI;
  int local_24;
  double local_20;
  undefined4 local_18;
  undefined4 local_14;
  double local_10;
  
  local_20 = _DAT_0099d098;
  iVar4 = FUN_007f1c30();
  if (iVar4 != 2) {
    return 1;
  }
  if (*(char *)(in_EAX + 5) == ':') {
    iVar4 = FUN_007f1c30(in_EAX + 6,2,0,0x3b,0,&local_24);
    if (iVar4 != 1) {
      return 1;
    }
    if ((*(char *)(in_EAX + 8) == '.') &&
       (iVar4 = _isdigit((uint)*(byte *)(in_EAX + 9)), iVar4 != 0)) {
      pcVar5 = (char *)(in_EAX + 9);
      local_10 = _DAT_0099d0a0;
      iVar4 = _isdigit((uint)*(byte *)(in_EAX + 9));
      while (iVar4 != 0) {
        cVar2 = *pcVar5;
        pbVar1 = (byte *)(pcVar5 + 1);
        pcVar5 = pcVar5 + 1;
        local_20 = ((double)(int)cVar2 + local_20 * _DAT_009fdca8) - _DAT_00a02990;
        local_10 = local_10 * _DAT_009fdca8;
        iVar4 = _isdigit((uint)*pbVar1);
      }
      dVar3 = local_20 / local_10;
      goto LAB_007f1ed3;
    }
  }
  else {
    local_24 = 0;
  }
  dVar3 = local_20;
LAB_007f1ed3:
  *(undefined1 *)(unaff_EDI + 0x2a) = 0;
  *(undefined1 *)(unaff_EDI + 0x29) = 1;
  *(double *)(unaff_EDI + 0x20) = (double)local_24 + dVar3;
  *(undefined4 *)(unaff_EDI + 0x14) = local_18;
  *(undefined4 *)(unaff_EDI + 0x18) = local_14;
  iVar4 = FUN_007f1cf0();
  if (iVar4 == 0) {
    *(bool *)(unaff_EDI + 0x2b) = *(int *)(unaff_EDI + 0x1c) != 0;
    return 0;
  }
  return 1;
}


// ==== FUN_007f1f20 @ 0x007f1f20 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007f1f20(void)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double *unaff_ESI;
  
  if (*(char *)((int)unaff_ESI + 0x2a) != '\0') {
    return;
  }
  if (*(char *)(unaff_ESI + 5) == '\0') {
    iVar5 = 2000;
    iVar4 = 1;
  }
  else {
    iVar5 = *(int *)(unaff_ESI + 1);
    iVar4 = *(int *)(unaff_ESI + 2);
    if (2 < *(int *)((int)unaff_ESI + 0xc)) goto LAB_007f1f4c;
  }
  iVar5 = iVar5 + -1;
LAB_007f1f4c:
  iVar5 = iVar5 / 100;
  iVar2 = FUN_00802534();
  iVar3 = FUN_00802534();
  *(undefined1 *)((int)unaff_ESI + 0x2a) = 1;
  *(undefined1 *)(unaff_ESI + 5) = 0;
  dVar1 = (double)((((iVar3 - iVar2) + ((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2)) - iVar5) + 2 +
                  iVar4) - _DAT_00a029b0;
  *unaff_ESI = dVar1;
  if (*(char *)((int)unaff_ESI + 0x29) != '\0') {
    dVar1 = ((double)*(int *)((int)unaff_ESI + 0x14) * _DAT_00a029a0 +
             (double)*(int *)(unaff_ESI + 3) * _DAT_00a029a8 + unaff_ESI[4]) * _DAT_00a02998 + dVar1
    ;
    *unaff_ESI = dVar1;
    if (*(char *)((int)unaff_ESI + 0x2b) != '\0') {
      *(undefined1 *)((int)unaff_ESI + 0x29) = 0;
      *(undefined1 *)((int)unaff_ESI + 0x2b) = 0;
      *unaff_ESI = (double)(*(int *)((int)unaff_ESI + 0x1c) * 0x3c) * _DAT_00a02998 + dVar1;
    }
  }
  return;
}


// ==== FUN_007f2030 @ 0x007f2030 ====

undefined4 FUN_007f2030(char *param_1)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  undefined4 local_8;
  undefined4 local_4;
  
  cVar1 = *param_1;
  pcVar3 = param_1;
  if (cVar1 == '-') {
    pcVar3 = param_1 + 1;
  }
  iVar2 = FUN_007f1c30(pcVar3,4,0,9999,0x2d,&param_1,2,1,0xc,0x2d,&local_8,2,1,0x1f,0,&local_4);
  if (iVar2 != 3) {
    return 1;
  }
  for (pbVar4 = (byte *)(pcVar3 + 10);
      (iVar2 = _isspace((uint)*pbVar4), iVar2 != 0 || (*pbVar4 == 0x54)); pbVar4 = pbVar4 + 1) {
  }
  iVar2 = FUN_007f1dd0();
  if (iVar2 != 0) {
    if (*pbVar4 != 0) {
      return 1;
    }
    *(undefined1 *)(in_EAX + 0x29) = 0;
  }
  *(undefined1 *)(in_EAX + 0x2a) = 0;
  *(undefined1 *)(in_EAX + 0x28) = 1;
  pcVar3 = param_1;
  if (cVar1 == '-') {
    pcVar3 = (char *)-(int)param_1;
  }
  *(char **)(in_EAX + 8) = pcVar3;
  *(undefined4 *)(in_EAX + 0xc) = local_8;
  *(undefined4 *)(in_EAX + 0x10) = local_4;
  if (*(char *)(in_EAX + 0x2b) != '\0') {
    FUN_007f1f20();
  }
  return 0;
}


// ==== FUN_007f2110 @ 0x007f2110 ====

undefined4 FUN_007f2110(void)

{
  int iVar1;
  double *unaff_ESI;
  double *pdVar2;
  float10 fVar3;
  double local_8;
  
  pdVar2 = unaff_ESI;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pdVar2 = 0;
    pdVar2 = (double *)((int)pdVar2 + 4);
  }
  iVar1 = FUN_007f2030();
  if (iVar1 != 0) {
    iVar1 = FUN_007f1dd0();
    if (iVar1 != 0) {
      iVar1 = FUN_007d08e0();
      if (iVar1 == 0) {
        FUN_007d1b00(&local_8);
        *unaff_ESI = local_8;
        *(undefined1 *)((int)unaff_ESI + 0x2a) = 1;
        return 0;
      }
      iVar1 = FUN_007d0990();
      if (iVar1 == 0) {
        return 1;
      }
      fVar3 = (float10)FUN_007d0ac0();
      *unaff_ESI = (double)fVar3;
      *(undefined1 *)((int)unaff_ESI + 0x2a) = 1;
    }
  }
  return 0;
}


// ==== FUN_007f21a0 @ 0x007f21a0 ====

void FUN_007f21a0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_EDI;
  
  if (*(char *)(unaff_EDI + 0x28) == '\0') {
    if (*(char *)(unaff_EDI + 0x2a) == '\0') {
      *(undefined4 *)(unaff_EDI + 8) = 2000;
      *(undefined4 *)(unaff_EDI + 0xc) = 1;
      *(undefined4 *)(unaff_EDI + 0x10) = 1;
      *(undefined1 *)(unaff_EDI + 0x28) = 1;
      return;
    }
    iVar1 = FUN_00802534();
    iVar2 = FUN_00802534();
    iVar3 = FUN_00802534();
    iVar4 = FUN_00802534();
    iVar5 = FUN_00802534();
    iVar6 = FUN_00802534();
    *(int *)(unaff_EDI + 0x10) =
         (((iVar2 - ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2)) + 0x5f5 + iVar1) - iVar6) - iVar4;
    iVar1 = iVar5 + -1;
    if (0xd < iVar5) {
      iVar1 = iVar5 + -0xd;
    }
    *(int *)(unaff_EDI + 0xc) = iVar1;
    if (2 < iVar1) {
      *(int *)(unaff_EDI + 8) = iVar3 + -0x126c;
      *(undefined1 *)(unaff_EDI + 0x28) = 1;
      return;
    }
    *(int *)(unaff_EDI + 8) = iVar3 + -0x126b;
    *(undefined1 *)(unaff_EDI + 0x28) = 1;
  }
  return;
}


// ==== FUN_007f22b0 @ 0x007f22b0 ====

void FUN_007f22b0(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  float10 extraout_ST0;
  
  if (*(char *)(unaff_ESI + 0x29) == '\0') {
    uVar1 = FUN_00802534();
    uVar1 = FUN_00802534(uVar1);
    iVar2 = FUN_00802534(uVar1);
    *(int *)(unaff_ESI + 0x14) = iVar2 / 0xe10;
    *(double *)(unaff_ESI + 0x20) = (double)(extraout_ST0 - (float10)iVar2);
    *(int *)(unaff_ESI + 0x18) = (iVar2 % 0xe10) / 0x3c;
    *(undefined1 *)(unaff_ESI + 0x29) = 1;
    *(double *)(unaff_ESI + 0x20) = (double)((iVar2 % 0xe10) % 0x3c) + *(double *)(unaff_ESI + 0x20)
    ;
  }
  return;
}


// ==== FUN_007f2360 @ 0x007f2360 ====

void FUN_007f2360(void)

{
  FUN_007f21a0();
  FUN_007f22b0();
  return;
}


// ==== FUN_007f2380 @ 0x007f2380 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_007f2380(void)

{
  undefined4 *in_EAX;
  tm *ptVar1;
  int iVar2;
  double *pdVar3;
  int local_64;
  double local_60;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  double local_40;
  undefined1 local_36;
  double local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  double local_10;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  
  pdVar3 = &local_60;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pdVar3 = *in_EAX;
    in_EAX = in_EAX + 1;
    pdVar3 = (double *)((int)pdVar3 + 4);
  }
  FUN_007f21a0();
  FUN_007f22b0();
  if ((local_58 < 0x7b3) || (0x7f5 < local_58)) {
    local_58 = 2000;
    local_54 = 1;
    local_50 = 1;
    local_4c = 0;
    local_48 = 0;
    local_40 = _DAT_0099d098;
  }
  else {
    local_64 = FUN_00802534();
    local_40 = (double)local_64;
  }
  local_44 = 0;
  local_36 = 0;
  FUN_007f1f20();
  local_64 = FUN_00802534();
  FUN_007d1ae0();
  ptVar1 = _localtime((time_t *)&local_64);
  local_10 = (double)ptVar1->tm_sec;
  local_28 = ptVar1->tm_year + 0x76c;
  local_20 = ptVar1->tm_mday;
  local_24 = ptVar1->tm_mon + 1;
  local_1c = ptVar1->tm_hour;
  local_18 = ptVar1->tm_min;
  FUN_007d1af0();
  local_8 = 1;
  local_7 = 1;
  local_6 = 0;
  local_5 = 0;
  FUN_007f1f20();
  return (float10)local_30 - (float10)local_60;
}


// ==== FUN_007f24a0 @ 0x007f24a0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007f24a0(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 uVar6;
  char *in_ECX;
  double *unaff_EBX;
  uint uVar7;
  double *pdVar8;
  bool bVar9;
  float10 extraout_ST0;
  float10 fVar10;
  float10 extraout_ST0_00;
  byte *local_74;
  undefined4 local_70;
  int local_6c;
  double local_68;
  double local_60 [6];
  byte local_2c [32];
  undefined4 local_c;
  
  local_c = DAT_00b49670;
  uVar7 = 0;
  local_74 = local_2c + -(int)in_ECX;
  local_70 = 1;
  do {
    if (*in_ECX == '\0') break;
    iVar2 = _tolower((int)*in_ECX);
    uVar7 = uVar7 + 1;
    in_ECX[(int)local_74] = (char)iVar2;
    in_ECX = in_ECX + 1;
  } while (uVar7 < 0x1d);
  local_2c[uVar7] = 0;
  switch(local_2c[0]) {
  case 0x2b:
  case 0x2d:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    fVar10 = (float10)FUN_007d0ac0(local_2c,&local_6c);
    local_68 = (double)fVar10;
    if (local_6c - (int)local_2c < 1) {
      return local_70;
    }
    pbVar3 = local_2c + (local_6c - (int)local_2c);
    if (*pbVar3 != 0x3a) {
      local_74 = pbVar3;
      iVar2 = _isspace((uint)*pbVar3);
      if (iVar2 != 0) {
        do {
          pbVar4 = pbVar3 + 1;
          pbVar3 = pbVar3 + 1;
          iVar2 = _isspace((uint)*pbVar4);
        } while (iVar2 != 0);
        local_74 = pbVar3;
      }
      pbVar4 = pbVar3;
      do {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + 1;
      } while (bVar1 != 0);
      iVar2 = (int)pbVar4 - (int)(pbVar3 + 1);
      if (10 < iVar2) {
        return local_70;
      }
      if (iVar2 < 3) {
        return local_70;
      }
      if (pbVar3[iVar2 + -1] == 0x73) {
        pbVar3[iVar2 + -1] = 0;
        iVar2 = iVar2 + -1;
      }
      FUN_007f1f20();
      local_70 = 0;
      if (iVar2 == 3) {
        iVar2 = 4;
        bVar9 = true;
        pbVar3 = &DAT_009fd938;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar9 = *local_74 == *pbVar3;
          local_74 = local_74 + 1;
          pbVar3 = pbVar3 + 1;
        } while (bVar9);
        if (bVar9) {
          *(undefined1 *)(unaff_EBX + 5) = 0;
          *(undefined1 *)((int)unaff_EBX + 0x29) = 0;
          *(undefined1 *)((int)unaff_EBX + 0x2b) = 0;
          *unaff_EBX = local_68 + *unaff_EBX;
          return 0;
        }
      }
      else if (iVar2 == 4) {
        iVar2 = 5;
        bVar9 = true;
        pbVar3 = local_74;
        pbVar4 = &DAT_009fd93c;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar9 = *pbVar3 == *pbVar4;
          pbVar3 = pbVar3 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar9);
        if (bVar9) {
          local_68 = local_68 * _DAT_00a02a38;
          *(undefined1 *)(unaff_EBX + 5) = 0;
          *(undefined1 *)((int)unaff_EBX + 0x29) = 0;
          *(undefined1 *)((int)unaff_EBX + 0x2b) = 0;
          *unaff_EBX = local_68 + *unaff_EBX;
          return 0;
        }
        iVar2 = 5;
        bVar9 = true;
        pbVar3 = local_74;
        pbVar4 = &DAT_009fd928;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar9 = *pbVar3 == *pbVar4;
          pbVar3 = pbVar3 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar9);
        if (bVar9) {
          FUN_007f2360();
          uVar6 = FUN_00802534();
          *(undefined4 *)(unaff_EBX + 1) = uVar6;
          *(undefined1 *)((int)unaff_EBX + 0x2a) = 0;
          FUN_007f1f20();
          goto LAB_007f2a3e;
        }
      }
      else if (iVar2 == 6) {
        iVar2 = 7;
        bVar9 = true;
        pbVar3 = local_74;
        pbVar4 = (byte *)(s_F_minute_00a02a2e + 2);
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar9 = *pbVar3 == *pbVar4;
          pbVar3 = pbVar3 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar9);
        if (bVar9) {
          local_68 = local_68 * _DAT_00a02a28;
          *(undefined1 *)(unaff_EBX + 5) = 0;
          *(undefined1 *)((int)unaff_EBX + 0x29) = 0;
          *(undefined1 *)((int)unaff_EBX + 0x2b) = 0;
          *unaff_EBX = local_68 + *unaff_EBX;
          return 0;
        }
        iVar2 = 7;
        bVar9 = true;
        pbVar3 = (byte *)(s_>_second_00a02a1e + 2);
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar9 = *local_74 == *pbVar3;
          local_74 = local_74 + 1;
          pbVar3 = pbVar3 + 1;
        } while (bVar9);
        if (bVar9) {
          *(undefined1 *)(unaff_EBX + 5) = 0;
          local_68 = local_68 * _DAT_00a02998;
          *(undefined1 *)((int)unaff_EBX + 0x29) = 0;
          *(undefined1 *)((int)unaff_EBX + 0x2b) = 0;
          *unaff_EBX = local_68 + *unaff_EBX;
          return 0;
        }
      }
      else if (iVar2 == 5) {
        iVar2 = 6;
        bVar9 = true;
        pbVar3 = local_74;
        pbVar4 = (byte *)s_month_009fd930;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar9 = *pbVar3 == *pbVar4;
          pbVar3 = pbVar3 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar9);
        if (bVar9) {
          FUN_007f2360();
          iVar5 = FUN_00802534();
          *(int *)((int)unaff_EBX + 0xc) = iVar5;
          iVar2 = iVar5 + -1;
          if (iVar5 < 1) {
            iVar2 = iVar5 + -0xc;
          }
          *(int *)(unaff_EBX + 1) = *(int *)(unaff_EBX + 1) + iVar2 / 0xc;
          *(int *)((int)unaff_EBX + 0xc) = iVar5 + (iVar2 / 0xc) * -0xc;
          *(undefined1 *)((int)unaff_EBX + 0x2a) = 0;
          FUN_007f1f20();
          iVar2 = FUN_00802534();
          if ((double)iVar2 != local_68) {
            *unaff_EBX = (local_68 - (double)iVar2) * _DAT_00a02a18 + *unaff_EBX;
          }
          goto LAB_007f2a3e;
        }
      }
      local_70 = 1;
LAB_007f2a3e:
      *(undefined1 *)(unaff_EBX + 5) = 0;
      *(undefined1 *)((int)unaff_EBX + 0x29) = 0;
      *(undefined1 *)((int)unaff_EBX + 0x2b) = 0;
      return local_70;
    }
    _isdigit((uint)local_2c[0]);
    pdVar8 = local_60;
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined4 *)pdVar8 = 0;
      pdVar8 = (double *)((int)pdVar8 + 4);
    }
    iVar2 = FUN_007f1dd0();
    if (iVar2 != 0) {
      return local_70;
    }
    FUN_007f1f20();
    local_6c = FUN_00802534();
    local_60[0] = (double)(extraout_ST0_00 - (float10)local_6c);
    if (local_2c[0] == 0x2d) {
      local_60[0] = -local_60[0];
    }
    FUN_007f1f20();
    fVar10 = (float10)local_60[0] + (float10)*unaff_EBX;
    break;
  default:
    return local_70;
  case 0x6c:
    iVar2 = 10;
    bVar9 = true;
    pbVar3 = local_2c;
    pbVar4 = (byte *)s_localtime_00a02a74;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar9 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar9);
    if (!bVar9) {
      return local_70;
    }
    FUN_007f1f20();
    fVar10 = (float10)FUN_007f2380();
    fVar10 = fVar10 + (float10)*unaff_EBX;
    break;
  case 0x73:
    iVar2 = _strncmp((char *)local_2c,s__start_of_00a02a3f + 1,9);
    if (iVar2 != 0) {
      return local_70;
    }
    FUN_007f21a0();
    unaff_EBX[4] = _DAT_0099d098;
    *(undefined4 *)(unaff_EBX + 3) = 0;
    *(undefined4 *)((int)unaff_EBX + 0x14) = 0;
    *(undefined1 *)((int)unaff_EBX + 0x2b) = 0;
    *(undefined1 *)((int)unaff_EBX + 0x2a) = 0;
    iVar2 = 6;
    bVar9 = true;
    *(undefined1 *)((int)unaff_EBX + 0x29) = 1;
    pbVar3 = local_2c + 9;
    pbVar4 = (byte *)s_month_009fd930;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar9 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar9);
    if (bVar9) {
      *(undefined4 *)(unaff_EBX + 2) = 1;
      return 0;
    }
    iVar2 = 5;
    bVar9 = true;
    pbVar3 = local_2c + 9;
    pbVar4 = &DAT_009fd928;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar9 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar9);
    if (bVar9) {
      FUN_007f21a0();
      *(undefined4 *)((int)unaff_EBX + 0xc) = 1;
      *(undefined4 *)(unaff_EBX + 2) = 1;
      return 0;
    }
    iVar2 = 4;
    bVar9 = true;
    pbVar3 = local_2c + 9;
    pbVar4 = &DAT_009fd938;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar9 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar9);
    if (bVar9) {
      return 0;
    }
    return local_70;
  case 0x75:
    iVar2 = 10;
    bVar9 = true;
    pbVar3 = local_2c;
    pbVar4 = (byte *)s_unixepoch_00a02a68;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar9 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar9);
    if ((!bVar9) || (*(char *)((int)unaff_EBX + 0x2a) == '\0')) {
      iVar2 = 4;
      bVar9 = true;
      pbVar3 = local_2c;
      pbVar4 = &DAT_00a02a64;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar9 = *pbVar3 == *pbVar4;
        pbVar3 = pbVar3 + 1;
        pbVar4 = pbVar4 + 1;
      } while (bVar9);
      if (!bVar9) {
        return local_70;
      }
      FUN_007f1f20();
      fVar10 = (float10)FUN_007f2380();
      local_68 = (double)fVar10;
      *(undefined1 *)(unaff_EBX + 5) = 0;
      *(undefined1 *)((int)unaff_EBX + 0x29) = 0;
      *(undefined1 *)((int)unaff_EBX + 0x2b) = 0;
      *unaff_EBX = (double)((float10)*unaff_EBX - fVar10);
      fVar10 = (float10)FUN_007f2380();
      fVar10 = ((float10)local_68 - fVar10) + (float10)*unaff_EBX;
      goto LAB_007f2573;
    }
    fVar10 = (float10)*unaff_EBX * (float10)_DAT_00a02998 + (float10)_DAT_00a02a10;
    break;
  case 0x77:
    iVar2 = _strncmp((char *)local_2c,s_weekday_00a02a58,8);
    if (iVar2 != 0) {
      return local_70;
    }
    FUN_007d0ac0(local_2c + 8,&local_74);
    if ((int)local_74 - (int)(local_2c + 8) < 1) {
      return local_70;
    }
    pbVar3 = (byte *)FUN_00802534();
    if (extraout_ST0 != (float10)(int)pbVar3) {
      return local_70;
    }
    if ((int)pbVar3 < 0) {
      return local_70;
    }
    if ((float10)_DAT_009fffb8 <= extraout_ST0) {
      return local_70;
    }
    local_74 = pbVar3;
    FUN_007f2360();
    *(undefined1 *)((int)unaff_EBX + 0x2b) = 0;
    *(undefined1 *)((int)unaff_EBX + 0x2a) = 0;
    FUN_007f1f20();
    iVar2 = FUN_00802534();
    iVar2 = iVar2 % 7;
    if ((int)pbVar3 < iVar2) {
      iVar2 = iVar2 + -7;
    }
    fVar10 = (float10)((int)pbVar3 - iVar2) + (float10)*unaff_EBX;
  }
  *(undefined1 *)(unaff_EBX + 5) = 0;
  *(undefined1 *)((int)unaff_EBX + 0x29) = 0;
  *(undefined1 *)((int)unaff_EBX + 0x2b) = 0;
LAB_007f2573:
  *unaff_EBX = (double)fVar10;
  return 0;
}


// ==== FUN_007f2b20 @ 0x007f2b20 ====

undefined4 FUN_007f2b20(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar1 = FUN_007cdf80(*param_2);
  if (iVar1 != 5) {
    FUN_007cdf50(*param_2);
    iVar1 = FUN_007f2110();
    if (iVar1 == 0) {
      iVar1 = 1;
      if (1 < param_1) {
        do {
          iVar2 = FUN_007cdf80(param_2[iVar1]);
          if (iVar2 == 5) {
            return 1;
          }
          FUN_007cdf50(param_2[iVar1]);
          iVar2 = FUN_007f24a0();
          if (iVar2 != 0) {
            return 1;
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < param_1);
      }
      return 0;
    }
  }
  return 1;
}


// ==== FUN_007f2bc0 @ 0x007f2bc0 ====

void FUN_007f2bc0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 local_30 [6];
  
  iVar1 = FUN_007f2b20(param_2,param_3,local_30);
  if (iVar1 == 0) {
    FUN_007f1f20();
    FUN_007cdf90(param_1,local_30[0]);
  }
  return;
}


// ==== FUN_007f2c10 @ 0x007f2c10 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f2c10(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_98 [8];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  char local_68 [100];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar1 = FUN_007f2b20(param_2,param_3,local_98);
  if (iVar1 == 0) {
    FUN_007f21a0();
    FUN_007f22b0();
    uVar2 = FUN_00802534();
    _sprintf(local_68,s__04d__02d__02d__02d__02d__02d_00a02a80,local_90,local_8c,local_88,local_84,
             local_80,uVar2);
    FUN_007ce030(param_1,local_68,0xffffffff,0xffffffff);
  }
  return;
}


// ==== FUN_007f2cc0 @ 0x007f2cc0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f2cc0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_98 [20];
  undefined4 local_84;
  undefined4 local_80;
  char local_68 [100];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar1 = FUN_007f2b20(param_2,param_3,local_98);
  if (iVar1 == 0) {
    FUN_007f22b0();
    uVar2 = FUN_00802534();
    _sprintf(local_68,s__02d__02d__02d_00a02aa0,local_84,local_80,uVar2);
    FUN_007ce030(param_1,local_68,0xffffffff,0xffffffff);
  }
  return;
}


// ==== FUN_007f2d50 @ 0x007f2d50 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f2d50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_98 [8];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  char local_68 [100];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar1 = FUN_007f2b20(param_2,param_3,local_98);
  if (iVar1 == 0) {
    FUN_007f21a0();
    _sprintf(local_68,s__04d__02d__02d_00a02ab0,local_90,local_8c,local_88);
    FUN_007ce030(param_1,local_68,0xffffffff,0xffffffff);
  }
  return;
}


// ==== FUN_007f2de0 @ 0x007f2de0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f2de0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  char *pcVar8;
  uint uVar9;
  char *pcVar10;
  undefined8 *puVar11;
  undefined4 *puVar12;
  undefined8 local_c8 [6];
  undefined4 local_98 [10];
  undefined1 local_6e;
  undefined1 local_68 [100];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  pcVar4 = (char *)FUN_007cdf50(*param_3);
  if (pcVar4 == (char *)0x0) {
    return;
  }
  iVar5 = FUN_007f2b20();
  if (iVar5 != 0) {
    return;
  }
  uVar9 = 1;
  iVar5 = 0;
  if (*pcVar4 != '\0') {
    do {
      if (pcVar4[iVar5] == '%') {
        switch(pcVar4[iVar5 + 1]) {
        case '%':
        case 'w':
          break;
        default:
          goto switchD_007f2e5f_caseD_26;
        case 'H':
        case 'M':
        case 'S':
        case 'W':
        case 'd':
        case 'm':
          uVar9 = uVar9 + 1;
          break;
        case 'J':
        case 's':
          uVar9 = uVar9 + 0x32;
          break;
        case 'Y':
        case 'f':
          uVar9 = uVar9 + 8;
          break;
        case 'j':
          uVar9 = uVar9 + 3;
        }
        iVar5 = iVar5 + 1;
      }
      iVar2 = iVar5 + 1;
      iVar5 = iVar5 + 1;
      uVar9 = uVar9 + 1;
    } while (pcVar4[iVar2] != '\0');
    if (99 < uVar9) {
      puVar6 = (undefined1 *)FUN_007d0550(uVar9);
      if (puVar6 == (undefined1 *)0x0) {
        return;
      }
      goto LAB_007f2e9f;
    }
  }
  puVar6 = local_68;
LAB_007f2e9f:
  FUN_007f1f20();
  FUN_007f21a0();
  FUN_007f22b0();
  pcVar10 = (char *)0x0;
  if (*pcVar4 != '\0') {
    do {
      if (*pcVar4 != '%') {
        puVar6[(int)pcVar10] = *pcVar4;
        goto LAB_007f3124;
      }
      pcVar1 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
      switch(*pcVar1) {
      case '%':
        puVar6[(int)pcVar10] = 0x25;
        goto LAB_007f3124;
      case 'H':
        goto LAB_007f30c2;
      case 'J':
        pcVar8 = puVar6 + (int)pcVar10;
        _sprintf(pcVar8,s___16g_00a02ac8,local_c8[0]);
        pcVar1 = pcVar8 + 1;
        do {
          cVar3 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar3 != '\0');
        pcVar10 = pcVar8 + ((int)pcVar10 - (int)pcVar1);
        break;
      case 'M':
        _sprintf(puVar6 + (int)pcVar10,&DAT_00a02af0);
        pcVar10 = pcVar10 + 2;
        break;
      case 'S':
        FUN_00802534();
        goto LAB_007f30c2;
      case 'W':
      case 'j':
        puVar11 = local_c8;
        puVar12 = local_98;
        for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar12 = *(undefined4 *)puVar11;
          puVar11 = (undefined8 *)((int)puVar11 + 4);
          puVar12 = puVar12 + 1;
        }
        local_6e = 0;
        local_98[3] = 1;
        local_98[4] = 1;
        FUN_007f1f20();
        FUN_00802534();
        if (*pcVar4 == 'W') {
          FUN_00802534();
          _sprintf(puVar6 + (int)pcVar10,&DAT_00a02af0);
          pcVar10 = pcVar10 + 2;
        }
        else {
          _sprintf(puVar6 + (int)pcVar10,&DAT_00a02ad0);
          pcVar10 = pcVar10 + 3;
        }
        break;
      case 'Y':
        pcVar8 = puVar6 + (int)pcVar10;
        _sprintf(pcVar8,&DAT_00a02ac0);
        pcVar1 = pcVar8 + 1;
        do {
          cVar3 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar3 != '\0');
        pcVar10 = pcVar8 + ((int)pcVar10 - (int)pcVar1);
        break;
      case 'd':
        _sprintf(puVar6 + (int)pcVar10,&DAT_00a02af0);
        pcVar10 = pcVar10 + 2;
        break;
      case 'f':
        uVar7 = FUN_00802534();
        pcVar8 = puVar6 + (int)pcVar10;
        FUN_00802534();
        _sprintf(pcVar8,s__02d__03d_00a02ad8,uVar7);
        pcVar1 = pcVar8 + 1;
        do {
          cVar3 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar3 != '\0');
        pcVar10 = pcVar8 + ((int)pcVar10 - (int)pcVar1);
        break;
      case 'm':
LAB_007f30c2:
        _sprintf(puVar6 + (int)pcVar10,&DAT_00a02af0);
        pcVar10 = pcVar10 + 2;
        break;
      case 's':
        pcVar8 = puVar6 + (int)pcVar10;
        FUN_00802534();
        _sprintf(pcVar8,&DAT_009fff54);
        pcVar1 = pcVar8 + 1;
        do {
          cVar3 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar3 != '\0');
        pcVar10 = pcVar8 + ((int)pcVar10 - (int)pcVar1);
        break;
      case 'w':
        iVar5 = FUN_00802534();
        puVar6[(int)pcVar10] = (char)(iVar5 % 7) + '0';
LAB_007f3124:
        pcVar10 = pcVar10 + 1;
      }
      pcVar1 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
    } while (*pcVar1 != '\0');
  }
  puVar6[(int)pcVar10] = 0;
  FUN_007ce030(param_1,puVar6,0xffffffffffffffff);
  if (puVar6 != local_68) {
    FUN_007d05b0(puVar6);
  }
switchD_007f2e5f_caseD_26:
  return;
}


// ==== FUN_007f3270 @ 0x007f3270 ====

void FUN_007f3270(undefined4 param_1)

{
  int iVar1;
  int local_4;
  
  iVar1 = FUN_007cfdf0();
  if (iVar1 != 0) {
    local_4 = iVar1;
    FUN_007cfe10(iVar1,0xffffffff,&PTR_LAB_00776f6b_3_00a029c8,1,0);
    FUN_007f2cc0(param_1,1,&local_4);
    FUN_007cfe40(iVar1);
  }
  return;
}


// ==== FUN_007f32b0 @ 0x007f32b0 ====

void FUN_007f32b0(undefined4 param_1)

{
  int iVar1;
  int local_4;
  
  iVar1 = FUN_007cfdf0();
  if (iVar1 != 0) {
    local_4 = iVar1;
    FUN_007cfe10(iVar1,0xffffffff,&PTR_LAB_00776f6b_3_00a029c8,1,0);
    FUN_007f2d50(param_1,1,&local_4);
    FUN_007cfe40(iVar1);
  }
  return;
}


// ==== FUN_007f32f0 @ 0x007f32f0 ====

void FUN_007f32f0(undefined4 param_1)

{
  int iVar1;
  int local_4;
  
  iVar1 = FUN_007cfdf0();
  if (iVar1 != 0) {
    local_4 = iVar1;
    FUN_007cfe10(iVar1,0xffffffff,&PTR_LAB_00776f6b_3_00a029c8,1,0);
    FUN_007f2c10(param_1,1,&local_4);
    FUN_007cfe40(iVar1);
  }
  return;
}


// ==== FUN_007f3330 @ 0x007f3330 ====

void FUN_007f3330(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    FUN_007cd550(param_1,*(undefined4 *)((int)&PTR_s_julianday_00a028d8 + uVar1),
                 *(undefined4 *)((int)&DAT_00a028dc + uVar1),1,0,
                 *(undefined4 *)((int)&PTR_FUN_00a028e0 + uVar1),0,0);
    uVar1 = uVar1 + 0xc;
  } while (uVar1 < 0x60);
  return;
}


// ==== FUN_007f3380 @ 0x007f3380 ====

void FUN_007f3380(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar9;
  int iVar8;
  
  puVar1 = param_3;
  iVar4 = FUN_007cdf50(*param_3);
  uVar5 = FUN_007cdf50(puVar1[1]);
  uVar6 = 0;
  iVar8 = iVar4;
  iVar2 = iVar4;
  uVar3 = uVar6;
  if (iVar4 != 0) {
    do {
      do {
        uVar7 = uVar3;
        iVar9 = iVar2;
        iVar8 = iVar8 + uVar6;
        uVar6 = FUN_007e5090(iVar8,&param_3);
        iVar2 = iVar9;
        uVar3 = uVar7;
      } while (param_3 == (undefined4 *)0x3);
      iVar2 = iVar8;
      uVar3 = uVar6;
    } while (param_3 != (undefined4 *)0x17);
    uVar5 = FUN_007e4830(s____s_Q_s_00a02b3c,iVar9 - iVar4,iVar4,uVar5,(uVar7 & 0x7fffffff) + iVar9)
    ;
    FUN_007ce030(param_1,uVar5,0xffffffff,FUN_007d05b0);
  }
  return;
}


// ==== FUN_007f3420 @ 0x007f3420 ====

void FUN_007f3420(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar8;
  int iVar7;
  int local_c;
  undefined4 local_8;
  
  iVar3 = FUN_007cdf50(*param_3);
  local_8 = FUN_007cdf50(param_3[1]);
  uVar4 = 0;
  param_3 = (undefined4 *)0x3;
  iVar7 = iVar3;
  iVar1 = iVar3;
  uVar2 = uVar4;
  if (iVar3 != 0) {
    do {
      while( true ) {
        do {
          uVar5 = uVar2;
          iVar8 = iVar1;
          iVar7 = iVar7 + uVar4;
          uVar4 = FUN_007e5090(iVar7,&local_c);
          iVar1 = iVar8;
          uVar2 = uVar5;
        } while (local_c == 3);
        param_3 = (undefined4 *)((int)param_3 + 1);
        if ((local_c != 0x73) && (local_c != 0x65)) break;
        param_3 = (undefined4 *)0x0;
        iVar1 = iVar7;
        uVar2 = uVar4;
      }
      iVar1 = iVar7;
      uVar2 = uVar4;
    } while ((param_3 != (undefined4 *)0x2) ||
            (((local_c != 0x86 && (local_c != 0x28)) && (local_c != 0xc))));
    uVar6 = FUN_007e4830(s____s_Q_s_00a02b3c,iVar8 - iVar3,iVar3,local_8,
                         (uVar5 & 0x7fffffff) + iVar8);
    FUN_007ce030(param_1,uVar6,0xffffffff,FUN_007d05b0);
  }
  return;
}


// ==== FUN_007f3500 @ 0x007f3500 ====

void FUN_007f3500(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    FUN_007cd550(param_1,*(undefined4 *)((int)&PTR_s_sqlite_rename_table_00a02af8 + uVar1),
                 (int)(char)(&DAT_00a02afc)[uVar1],1,0,
                 *(undefined4 *)((int)&PTR_FUN_00a02b00 + uVar1),0,0);
    uVar1 = uVar1 + 0xc;
  } while (uVar1 < 0x18);
  return;
}


// ==== FUN_007f3550 @ 0x007f3550 ====

int FUN_007f3550(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  if (*(char *)(in_EAX + 0x1d) == '\x01') {
    return 0;
  }
  puVar3 = *(undefined4 **)(in_EAX + 0x28);
  if (puVar3 == (undefined4 *)0x0) {
    return 0;
  }
  do {
    iVar1 = iVar2;
    if (*(char *)(puVar3 + 2) == '\x01') {
      if (iVar2 == 0) {
        iVar1 = FUN_007e4830(s_name__Q_00a02b58,*puVar3);
      }
      else {
        iVar1 = FUN_007e4830(s__s_OR_name__Q_00a02b48,iVar2,*puVar3);
        FUN_007d05b0(iVar2);
      }
    }
    puVar3 = (undefined4 *)puVar3[9];
    iVar2 = iVar1;
  } while (puVar3 != (undefined4 *)0x0);
  return iVar1;
}


// ==== FUN_007f35c0 @ 0x007f35c0 ====

void FUN_007f35c0(undefined4 param_1)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_EBX;
  
  iVar3 = FUN_007e8190();
  if (iVar3 != 0) {
    uVar1 = *(undefined1 *)((int)unaff_EBX + 0x1d);
    for (puVar2 = (undefined4 *)unaff_EBX[10]; puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)puVar2[9]) {
      FUN_007dda80(iVar3,0x3b,*(undefined1 *)(puVar2 + 2),0,*puVar2,0);
    }
    FUN_007dda80(iVar3,0x58,uVar1,0,*unaff_EBX,0);
    iVar4 = FUN_007e4830(s_tbl_name__Q_00a02b60,param_1);
    if (iVar4 != 0) {
      FUN_007dda80(iVar3,0x1c,uVar1,0,iVar4,0xffffffff);
      iVar4 = FUN_007f3550();
      if (iVar4 != 0) {
        FUN_007dda80(iVar3,0x1c,1,0,iVar4,0xffffffff);
      }
    }
  }
  return;
}


// ==== FUN_007f3660 @ 0x007f3660 ====

void FUN_007f3660(int *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  
  iVar6 = *param_1;
  iVar9 = 0;
  piVar3 = (int *)FUN_007d2330(param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4));
  if (piVar3 != (int *)0x0) {
    uVar8 = (uint)*(byte *)((int)piVar3 + 0x1d);
    uVar2 = *(undefined4 *)(uVar8 * 0x70 + *(int *)(iVar6 + 4));
    iVar9 = FUN_007d2730(param_3);
    if (iVar9 != 0) {
      iVar4 = FUN_007d22b0(iVar6,iVar9,uVar2);
      if ((iVar4 == 0) && (iVar4 = FUN_007d23d0(iVar6,iVar9,uVar2), iVar4 == 0)) {
        pcVar10 = (char *)*piVar3;
        pcVar5 = pcVar10;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        if (((uint)((int)pcVar5 - (int)(pcVar10 + 1)) < 7) ||
           (iVar4 = FUN_007d0930(pcVar10,s_sqlite__00a001a8,7), iVar4 != 0)) {
          iVar4 = FUN_007d28b0(param_1,iVar9);
          if ((iVar4 == 0) &&
             ((iVar4 = FUN_007ed5e0(param_1,0x1a,uVar2,*piVar3,0), iVar4 == 0 &&
              (iVar4 = FUN_007e8190(param_1), iVar4 != 0)))) {
            FUN_007d3d30(param_1,0,uVar8);
            FUN_007d2ce0(iVar6,iVar4,uVar8);
            pcVar10 = (char *)*piVar3;
            pcVar5 = pcVar10;
            do {
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            pcVar7 = s_sqlite_temp_master_009fff68;
            if (uVar8 != 1) {
              pcVar7 = s_sqlite_master_009fff58;
            }
            FUN_007d2210(param_1,s_UPDATE__Q__s_SET_sql___CASE_WHEN_00a02c40,uVar2,pcVar7,iVar9,
                         iVar9,iVar9,iVar9,iVar9,(int)pcVar5 - (int)(pcVar10 + 1),pcVar10);
            iVar6 = FUN_007d22b0(iVar6,s_sqlite_sequence_00a00510,uVar2);
            if (iVar6 != 0) {
              FUN_007d2210(param_1,s_UPDATE__Q_sqlite_sequence_set_na_00a02c04,uVar2,iVar9,*piVar3);
            }
            iVar6 = FUN_007f3550();
            if (iVar6 != 0) {
              FUN_007d2210(param_1,s_UPDATE_sqlite_temp_master_SET_sq_00a02ba8,iVar9,iVar9,iVar6);
              FUN_007d05b0(iVar6);
            }
            FUN_007f35c0(iVar9);
          }
          goto LAB_007f383f;
        }
        pcVar10 = s_table__s_may_not_be_altered_00a02db8;
        iVar6 = *piVar3;
      }
      else {
        pcVar10 = s_there_is_already_another_table_o_00a02b6c;
        iVar6 = iVar9;
      }
      FUN_007d0820(param_1,pcVar10,iVar6);
    }
  }
LAB_007f383f:
  FUN_007d3a10(param_2);
  FUN_007d05b0(iVar9);
  return;
}


// ==== FUN_007f3860 @ 0x007f3860 ====

void FUN_007f3860(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  byte *pbVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  char cVar7;
  char *pcVar8;
  byte *pbVar9;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 *local_4;
  
  if (param_1[6] != 0) {
    return;
  }
  puVar1 = (undefined4 *)param_1[0x26];
  uVar6 = (uint)*(byte *)((int)puVar1 + 0x1d);
  local_c = *puVar1;
  local_8 = *(undefined4 *)(uVar6 * 0x70 + *(int *)(*param_1 + 4));
  pcVar8 = *(char **)(puVar1[2] + -0x10 + puVar1[1] * 0x14);
  iVar2 = puVar1[2] + -0x14 + puVar1[1] * 0x14;
  local_4 = (undefined4 *)FUN_007d22b0(*param_1,local_c,local_8);
  if ((pcVar8 != (char *)0x0) && (*pcVar8 == '^')) {
    pcVar8 = (char *)0x0;
  }
  if (*(char *)(iVar2 + 0x11) != '\0') {
    FUN_007d0820(param_1,s_Cannot_add_a_PRIMARY_KEY_column_00a02ed4);
    return;
  }
  if (puVar1[4] != 0) {
    FUN_007d0820(param_1,s_Cannot_add_a_UNIQUE_column_00a02eb8);
    return;
  }
  if (*(char *)(iVar2 + 0x10) == '\0') {
    if (pcVar8 == (char *)0x0) goto LAB_007f3975;
  }
  else if (pcVar8 == (char *)0x0) {
    FUN_007d0820(param_1,s_Cannot_add_a_NOT_NULL_column_wit_00a02e80);
    return;
  }
  iVar2 = FUN_007d0150(pcVar8,1,0x6f,&local_10);
  if (iVar2 != 0) {
    return;
  }
  if (local_10 == 0) {
    FUN_007d0820(param_1,s_Cannot_add_a_column_with_non_con_00a02e50);
    return;
  }
  FUN_007cfe40(local_10);
LAB_007f3975:
  pbVar3 = (byte *)FUN_007d06a0(*param_2,(uint)param_2[1] >> 1);
  if (pbVar3 != (byte *)0x0) {
    pbVar9 = pbVar3 + (((uint)param_2[1] >> 1) - 1);
    while (((pbVar3 < pbVar9 && (*pbVar9 == 0x3b)) || (iVar2 = _isspace((uint)*pbVar9), iVar2 != 0))
          ) {
      *pbVar9 = 0;
      pbVar9 = pbVar9 + -1;
    }
    pcVar4 = s_sqlite_temp_master_009fff68;
    if (uVar6 != 1) {
      pcVar4 = s_sqlite_master_009fff58;
    }
    FUN_007d2210(param_1,s_UPDATE__Q__s_SET_sql___substr_sq_00a02dd8,local_8,pcVar4,puVar1[0xd],
                 pbVar3,puVar1[0xd] + 1,local_c);
    FUN_007d05b0(pbVar3);
  }
  iVar2 = FUN_007e8190(param_1);
  if (iVar2 != 0) {
    cVar7 = (pcVar8 != (char *)0x0) + '\x02';
    FUN_007dc140(iVar2,0x73,uVar6,1);
    FUN_007dc140(iVar2,0x32,cVar7,0);
    iVar5 = FUN_007dc320(iVar2);
    FUN_007dc140(iVar2,0x4b,0,iVar5 + 3);
    FUN_007dc140(iVar2,0x32,cVar7,0);
    FUN_007dc140(iVar2,3,uVar6,1);
  }
  FUN_007f35c0(*local_4);
  return;
}


// ==== FUN_007f3a80 @ 0x007f3a80 ====

void FUN_007f3a80(undefined4 *param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_8;
  
  puVar2 = (undefined4 *)
           FUN_007d2330(param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4));
  if (puVar2 != (undefined4 *)0x0) {
    if (puVar2[6] != 0) {
      FUN_007d0820(param_1,s_Cannot_add_a_column_to_a_view_00a02ef4);
      FUN_007d3a10(param_2);
      return;
    }
    uVar1 = *(undefined1 *)((int)puVar2 + 0x1d);
    piVar3 = (int *)FUN_007d0550(0x38);
    if (piVar3 != (int *)0x0) {
      param_1[0x26] = piVar3;
      iVar4 = puVar2[1];
      piVar3[1] = iVar4;
      iVar4 = iVar4 + -1;
      iVar4 = FUN_007d0550((((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) * 8 + 8) * 0x14);
      piVar3[2] = iVar4;
      iVar4 = FUN_007d0640(*puVar2);
      *piVar3 = iVar4;
      if (((undefined4 *)piVar3[2] != (undefined4 *)0x0) && (iVar4 != 0)) {
        puVar7 = (undefined4 *)puVar2[2];
        puVar8 = (undefined4 *)piVar3[2];
        for (uVar6 = (uint)(piVar3[1] * 0x14) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        iVar4 = 0;
        if (0 < piVar3[1]) {
          local_8 = 0;
          do {
            puVar7 = (undefined4 *)(piVar3[2] + local_8);
            uVar5 = FUN_007d0640(*(undefined4 *)(piVar3[2] + local_8));
            *puVar7 = uVar5;
            puVar7[2] = 0;
            puVar7[1] = 0;
            iVar4 = iVar4 + 1;
            local_8 = local_8 + 0x14;
          } while (iVar4 < piVar3[1]);
        }
        *(undefined1 *)((int)piVar3 + 0x1d) = uVar1;
        piVar3[0xd] = puVar2[0xd];
        piVar3[9] = 1;
        FUN_007d3d30(param_1,0,uVar1);
        iVar4 = FUN_007e8190(param_1);
        if (iVar4 != 0) {
          FUN_007d2ce0(*param_1,iVar4,uVar1);
        }
      }
    }
  }
  FUN_007d3a10(param_2);
  return;
}


// ==== FUN_007f3bf0 @ 0x007f3bf0 ====

void FUN_007f3bf0(void)

{
  int in_EAX;
  byte *pbVar1;
  int iVar2;
  
  FUN_007e6500(0x14);
  iVar2 = 4;
  pbVar1 = (byte *)(in_EAX + 1);
  do {
    pbVar1[-1] = s_abcdefghijklmnopqrstuvwxyz012345_00a02f14[(uint)pbVar1[-1] % 0x24];
    *pbVar1 = s_abcdefghijklmnopqrstuvwxyz012345_00a02f14[(uint)*pbVar1 % 0x24];
    pbVar1[1] = s_abcdefghijklmnopqrstuvwxyz012345_00a02f14[(uint)pbVar1[1] % 0x24];
    pbVar1[2] = s_abcdefghijklmnopqrstuvwxyz012345_00a02f14[(uint)pbVar1[2] % 0x24];
    iVar2 = iVar2 + -1;
    pbVar1[3] = s_abcdefghijklmnopqrstuvwxyz012345_00a02f14[(uint)pbVar1[3] % 0x24];
    pbVar1 = pbVar1 + 5;
  } while (iVar2 != 0);
  return;
}


// ==== FUN_007f3c80 @ 0x007f3c80 ====

void FUN_007f3c80(void)

{
  int iVar1;
  undefined4 in_ECX;
  
  iVar1 = FUN_007ceac0();
  if (iVar1 != 0) {
    FUN_007cd780();
    return;
  }
  do {
    iVar1 = FUN_007ce0a0(in_ECX);
  } while (iVar1 == 100);
  FUN_007cd7b0(in_ECX);
  return;
}


// ==== FUN_007f3cd0 @ 0x007f3cd0 ====

int FUN_007f3cd0(void)

{
  int iVar1;
  undefined4 local_8;
  undefined4 uStack_4;
  
  iVar1 = FUN_007ceac0();
  if (iVar1 == 0) {
    iVar1 = FUN_007ce0a0(local_8);
    while (iVar1 == 100) {
      FUN_007ce2e0(local_8,0);
      iVar1 = FUN_007ceac0();
      if (iVar1 == 0) {
        do {
          iVar1 = FUN_007ce0a0(uStack_4);
        } while (iVar1 == 100);
        iVar1 = FUN_007cd7b0(uStack_4);
      }
      else {
        iVar1 = FUN_007cd780();
      }
      if (iVar1 != 0) {
        FUN_007cd7b0(local_8);
        return iVar1;
      }
      iVar1 = FUN_007ce0a0(local_8);
    }
    iVar1 = FUN_007cd7b0(local_8);
  }
  return iVar1;
}


// ==== FUN_007f3d90 @ 0x007f3d90 ====

void FUN_007f3d90(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_007e8190(param_1);
  if (iVar1 != 0) {
    FUN_007dc140(iVar1,0x42,0,0);
  }
  return;
}


// ==== FUN_007f3dc0 @ 0x007f3dc0 ====

int FUN_007f3dc0(undefined4 param_1,int *param_2)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int local_c;
  int local_8;
  uint local_4;
  
  local_4 = param_2[2];
  param_2[2] = local_4 | 0x800;
  local_4 = local_4 & 0x800;
  local_c = 0;
  if (*(char *)((int)param_2 + 0x11) == '\0') {
    FUN_007d0700(param_1,s_cannot_VACUUM_from_within_a_tran_00a0339c,0);
    iVar9 = 1;
  }
  else {
    local_8 = *(int *)(param_2[1] + 4);
    pcVar4 = (char *)FUN_007db070(local_8);
    if (*pcVar4 == '\0') {
      return 0;
    }
    pcVar1 = pcVar4 + 1;
    pcVar5 = pcVar4;
    do {
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    local_c = FUN_007d0550(pcVar5 + (100 - (int)pcVar1));
    if (local_c == 0) {
      iVar9 = 7;
    }
    else {
      iVar8 = local_c - (int)pcVar4;
      do {
        cVar2 = *pcVar4;
        pcVar4[iVar8] = cVar2;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      do {
        pcVar5[local_c - (int)pcVar1] = '-';
        FUN_007f3bf0();
        iVar8 = FUN_007d12b0(local_c);
      } while (iVar8 != 0);
      iVar8 = FUN_007e4830(s_ATTACH___q__AS_vacuum_db__00a03380,local_c);
      if (iVar8 == 0) {
        iVar9 = 7;
      }
      else {
        iVar9 = FUN_007f3c80();
        FUN_007d05b0(iVar8);
        iVar8 = local_8;
        if (iVar9 == 0) {
          uVar3 = *(undefined4 *)(*param_2 * 0x70 + -0x6c + param_2[1]);
          uVar6 = FUN_007d66f0(local_8);
          uVar6 = FUN_007d66e0(iVar8,uVar6);
          FUN_007d6680(uVar3,uVar6);
          FUN_007f3c80();
          uVar6 = FUN_007d6720(iVar8);
          FUN_007d6700(uVar3,uVar6);
          iVar9 = FUN_007f3c80();
          if ((((((iVar9 == 0) && (iVar9 = FUN_007f3cd0(), iVar9 == 0)) &&
                (iVar9 = FUN_007f3cd0(), iVar9 == 0)) &&
               ((iVar9 = FUN_007f3cd0(), iVar9 == 0 && (iVar9 = FUN_007f3cd0(), iVar9 == 0)))) &&
              ((iVar9 = FUN_007f3cd0(), iVar9 == 0 &&
               ((iVar9 = FUN_007f3cd0(), iVar9 == 0 && (iVar9 = FUN_007f3cd0(), iVar9 == 0)))))) &&
             ((iVar9 = FUN_007f3cd0(), iVar9 == 0 &&
              ((iVar7 = FUN_007db270(uVar3), iVar7 != 0 &&
               (iVar9 = FUN_007d69e0(iVar8,1), iVar9 == 0)))))) {
            uVar10 = 0;
            do {
              iVar9 = FUN_007da670(iVar8,(&DAT_00a02f3c)[uVar10],&local_8);
              if (iVar9 != 0) goto LAB_007f4058;
              FUN_007da6d0(uVar3,(&DAT_00a02f3c)[uVar10],
                           (uint)(byte)(&DAT_00a02f3d)[uVar10] + local_8);
              uVar10 = uVar10 + 2;
            } while (uVar10 < 8);
            iVar9 = FUN_007db0a0(iVar8,uVar3);
            if (iVar9 == 0) {
              iVar9 = FUN_007d6f20(iVar8);
            }
          }
        }
      }
    }
  }
LAB_007f4058:
  param_2[2] = param_2[2] & 0xfffff7ffU | local_4;
  *(undefined1 *)((int)param_2 + 0x11) = 1;
  if (iVar9 == 0) {
    iVar9 = FUN_007f3c80();
  }
  else {
    FUN_007f3c80();
  }
  if (local_c != 0) {
    FUN_007d12a0(local_c);
    FUN_007d05b0(local_c);
  }
  FUN_007d3fc0(param_2,0);
  return iVar9;
}


// ==== FUN_007f40c0 @ 0x007f40c0 ====

void FUN_007f40c0(code *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*param_1)(0x7dc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0xffffffff;
  }
  return;
}


// ==== FUN_007f40e0 @ 0x007f40e0 ====

void FUN_007f40e0(void)

{
  undefined1 in_AL;
  undefined4 *unaff_ESI;
  
  switch(in_AL) {
  case 0x9d:
  case 0xbd:
  case 0xce:
    FUN_007e6af0(*unaff_ESI);
    return;
  case 0xaa:
  case 0xae:
  case 0xc2:
  case 0xc4:
  case 0xcc:
  case 0xd2:
  case 0xe0:
    FUN_007eabc0(*unaff_ESI);
    return;
  case 0xaf:
  case 0xb7:
  case 0xc0:
  case 0xc3:
  case 0xc5:
  case 199:
  case 0xd1:
  case 0xd4:
  case 0xd5:
  case 0xd8:
  case 0xde:
    FUN_007ea740(*unaff_ESI);
    return;
  case 0xbc:
  case 0xc1:
  case 0xc9:
  case 0xca:
    FUN_007d3a10(*unaff_ESI);
    return;
  case 0xc6:
    FUN_007eabc0(*unaff_ESI);
    FUN_007eabc0(unaff_ESI[1]);
    return;
  case 0xcd:
  case 0xd0:
  case 0xd7:
    FUN_007d3980(*unaff_ESI);
    return;
  case 0xe6:
  case 0xeb:
    FUN_007ed6b0(*unaff_ESI);
    return;
  case 0xe8:
    FUN_007d3980(unaff_ESI[1]);
  }
  return;
}


// ==== FUN_007f41e0 @ 0x007f41e0 ====

void FUN_007f41e0(int *param_1,code *param_2)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    while (-1 < iVar1) {
      if (-1 < *param_1) {
        FUN_007f40e0();
        *param_1 = *param_1 + -1;
      }
      iVar1 = *param_1;
    }
    (*param_2)(param_1);
  }
  return;
}


// ==== FUN_007f4220 @ 0x007f4220 ====

undefined2 FUN_007f4220(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint in_ECX;
  int *in_EDX;
  
  iVar2 = in_EDX[*in_EDX * 5 + 3];
  sVar1 = *(short *)(&DAT_00a04418 + iVar2 * 2);
  while (sVar1 != -0x46) {
    if (in_ECX == 0xf1) {
      return 0x368;
    }
    uVar3 = (int)sVar1 + in_ECX;
    if (((-1 < (int)uVar3) && (uVar3 < 0x56f)) && ((byte)(&DAT_00a03ea8)[uVar3] == in_ECX)) {
      return *(undefined2 *)(&DAT_00a033c8 + uVar3 * 2);
    }
    if ((0x8c < in_ECX) || (in_ECX = (uint)(byte)(&DAT_00a05168)[in_ECX], in_ECX == 0)) break;
    sVar1 = *(short *)(&DAT_00a04418 + iVar2 * 2);
  }
  return *(undefined2 *)(&DAT_00a04cf8 + iVar2 * 2);
}


// ==== FUN_007f4290 @ 0x007f4290 ====

void FUN_007f4290(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  int *unaff_EDI;
  
  iVar2 = *unaff_EDI;
  iVar3 = iVar2 + 1;
  *unaff_EDI = iVar3;
  if (iVar3 < 100) {
    piVar1 = unaff_EDI + iVar3 * 5 + 3;
    *piVar1 = param_1;
    piVar1[1] = param_2;
    piVar1[2] = *in_ECX;
    piVar1[3] = in_ECX[1];
    piVar1[4] = in_ECX[2];
    return;
  }
  iVar3 = unaff_EDI[2];
  *unaff_EDI = iVar2;
  while (-1 < iVar2) {
    if (-1 < *unaff_EDI) {
      FUN_007f40e0();
      *unaff_EDI = *unaff_EDI + -1;
    }
    iVar2 = *unaff_EDI;
  }
  unaff_EDI[2] = iVar3;
  return;
}


// ==== FUN_007f4300 @ 0x007f4300 ====

void FUN_007f4300(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EDI;
  
  iVar2 = unaff_EDI[2];
  iVar1 = *unaff_EDI;
  while (-1 < iVar1) {
    if (-1 < *unaff_EDI) {
      FUN_007f40e0();
      *unaff_EDI = *unaff_EDI + -1;
    }
    iVar1 = *unaff_EDI;
  }
  unaff_EDI[2] = iVar2;
  return;
}


// ==== FUN_007f4340 @ 0x007f4340 ====

void FUN_007f4340(int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  undefined4 uVar14;
  int local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  int local_4;
  
  iVar2 = *param_1;
  iVar6 = param_1[2];
  if (299 < param_2 - 3U) goto switchD_007f4372_caseD_a0;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(*(undefined1 *)((int)&PTR_caseD_a0_007f5b70 + param_2 + 1)) {
  case 0:
    FUN_007d2080(iVar6);
  case 0xa0:
switchD_007f4372_caseD_a0:
    piVar11 = local_c;
    break;
  case 1:
    FUN_007d2060(iVar6,0);
    goto switchD_007f4372_caseD_a0;
  case 2:
    FUN_007d2060(iVar6,1);
    goto switchD_007f4372_caseD_a0;
  case 3:
    FUN_007d3ad0(iVar6,param_1[iVar2 * 5]);
    goto switchD_007f4372_caseD_a0;
  case 4:
    piVar11 = (int *)0xe;
    local_c = (int *)0xe;
    break;
  case 5:
    piVar11 = (int *)param_1[iVar2 * 5 + 4];
    local_c = piVar11;
    break;
  case 6:
    FUN_007d3b70(iVar6);
    goto switchD_007f4372_caseD_a0;
  case 7:
    FUN_007d3bd0(iVar6);
    goto switchD_007f4372_caseD_a0;
  case 8:
    FUN_007d4240(iVar6,param_1 + iVar2 * 5 + -0xf,param_1 + iVar2 * 5,param_1 + iVar2 * 5 + 5,
                 param_1[iVar2 * 5 + -10],0);
    goto switchD_007f4372_caseD_a0;
  case 9:
    piVar11 = (int *)0x1;
    local_c = (int *)0x1;
    break;
  case 10:
    goto switchD_007f4372_caseD_a;
  case 0xb:
    FUN_007d2fe0(iVar6,param_1 + iVar2 * 5,param_1 + iVar2 * 5 + 5,0);
    goto switchD_007f4372_caseD_a0;
  case 0xc:
    FUN_007d2fe0(iVar6,0,0,param_1[iVar2 * 5 + 5]);
    FUN_007e6af0(param_1[iVar2 * 5 + 5]);
    goto switchD_007f4372_caseD_a0;
  case 0xd:
    piVar11 = (int *)param_1[iVar2 * 5 + -5];
    local_8 = (*(uint *)(iVar6 + 0x8c) & 0xfffffffe) + (*(int *)(iVar6 + 0x88) - (int)piVar11) * 2 ^
              local_8 & 1;
    local_c = piVar11;
    break;
  case 0xe:
    FUN_007d2910(iVar6,param_1 + iVar2 * 5 + 5);
    piVar11 = (int *)param_1[iVar2 * 5 + 5];
    local_8 = param_1[iVar2 * 5 + 6];
    local_c = piVar11;
    break;
  case 0xf:
    piVar11 = (int *)param_1[iVar2 * 5 + 5];
    local_8 = param_1[iVar2 * 5 + 6];
    local_c = piVar11;
    break;
  case 0x10:
    FUN_007d2ad0(iVar6,param_1 + iVar2 * 5 + 5,param_1 + iVar2 * 5 + 5);
    goto switchD_007f4372_caseD_a0;
  case 0x11:
    FUN_007d2ad0(iVar6,param_1 + iVar2 * 5 + -10,param_1 + iVar2 * 5 + 5);
    goto switchD_007f4372_caseD_a0;
  case 0x12:
    FUN_007d2ad0(iVar6,param_1 + iVar2 * 5 + -0x14,param_1 + iVar2 * 5 + 5);
    goto switchD_007f4372_caseD_a0;
  case 0x13:
    piVar11 = (int *)param_1[iVar2 * 5 + 5];
    local_8 = param_1[iVar2 * 5 + 6];
    local_c = piVar11;
    break;
  case 0x14:
    piVar11 = (int *)param_1[iVar2 * 5];
    local_8 = (param_1[iVar2 * 5 + 6] & 0xfffffffeU) + (param_1[iVar2 * 5 + 5] - (int)piVar11) * 2 ^
              local_8 & 1;
    local_c = piVar11;
    break;
  case 0x15:
    piVar11 = (int *)_atol((char *)param_1[iVar2 * 5 + 5]);
    local_c = piVar11;
    break;
  case 0x16:
    lVar3 = _atol((char *)param_1[iVar2 * 5 + 5]);
    piVar11 = (int *)-lVar3;
    local_c = piVar11;
    break;
  case 0x17:
    FUN_007d2b90(iVar6,param_1[iVar2 * 5 + 5]);
    goto switchD_007f4372_caseD_a0;
  case 0x18:
    uVar14 = FUN_007eb130(0x57,param_1[iVar2 * 5 + 5],0,0);
    FUN_007d2b90(iVar6,uVar14);
    goto switchD_007f4372_caseD_a0;
  case 0x19:
    uVar14 = FUN_007eb130(0x5a,0,0,param_1 + iVar2 * 5 + 5);
    FUN_007d2b90(iVar6,uVar14);
    goto switchD_007f4372_caseD_a0;
  case 0x1a:
    FUN_007d2a30(iVar6,param_1[iVar2 * 5 + 5]);
    goto switchD_007f4372_caseD_a0;
  case 0x1b:
    FUN_007d5440(iVar6,0,param_1[iVar2 * 5],param_1[iVar2 * 5 + 5]);
    goto switchD_007f4372_caseD_a0;
  case 0x1c:
    FUN_007d4900(iVar6,0,0,0,0,param_1[iVar2 * 5 + 5],0,0);
    goto switchD_007f4372_caseD_a0;
  case 0x1d:
    FUN_007eabc0(param_1[iVar2 * 5 + -5]);
    goto switchD_007f4372_caseD_a0;
  case 0x1e:
    FUN_007d3460(iVar6,0,param_1 + iVar2 * 5 + -5,param_1[iVar2 * 5],param_1[iVar2 * 5 + 5]);
    goto switchD_007f4372_caseD_a0;
  case 0x1f:
    FUN_007d3750(iVar6,param_1[iVar2 * 5 + 5]);
    goto switchD_007f4372_caseD_a0;
  case 0x20:
    FUN_007d4590(iVar6,param_1[iVar2 * 5 + 5],(uint)param_1[iVar2 * 5 + 6] >> 1);
    goto switchD_007f4372_caseD_a0;
  case 0x21:
    piVar11 = (int *)0x60606;
    local_c = (int *)0x60606;
    break;
  case 0x22:
    piVar11 = (int *)(param_1[iVar2 * 5] & param_1[iVar2 * 5 + 6] | param_1[iVar2 * 5 + 5]);
    local_c = piVar11;
    break;
  case 0x23:
    piVar11 = (int *)0x0;
    local_c = (int *)0x0;
    local_8 = 0;
    break;
  case 0x24:
    piVar11 = (int *)param_1[iVar2 * 5 + 5];
    local_8 = 0xff;
    local_c = piVar11;
    break;
  case 0x25:
    piVar11 = (int *)(param_1[iVar2 * 5 + 5] << 8);
    local_8 = 0xff00;
    local_c = piVar11;
    break;
  case 0x26:
    piVar11 = (int *)(param_1[iVar2 * 5 + 5] << 0x10);
    local_8 = 0xff0000;
    local_c = piVar11;
    break;
  case 0x27:
    piVar11 = (int *)0x7;
    local_c = (int *)0x7;
    break;
  case 0x28:
    piVar11 = (int *)0x8;
    local_c = (int *)0x8;
    break;
  case 0x29:
    piVar11 = (int *)0x9;
    local_c = (int *)0x9;
    break;
  case 0x2a:
    piVar11 = (int *)0x6;
    local_c = (int *)0x6;
    break;
  case 0x2b:
    goto switchD_007f4372_caseD_2b;
  case 0x2c:
    local_8 = local_8 & 1;
    goto switchD_007f4372_caseD_a;
  case 0x2d:
    piVar11 = (int *)param_1[iVar2 * 5];
    local_8 = param_1[iVar2 * 5 + 1];
    local_c = piVar11;
    break;
  case 0x2e:
    FUN_007d5440(iVar6,param_1[iVar2 * 5 + -10],param_1[iVar2 * 5 + 5],param_1[iVar2 * 5 + -5]);
    goto switchD_007f4372_caseD_a0;
  case 0x2f:
    FUN_007d4900(iVar6,0,0,0,param_1[iVar2 * 5 + -5],param_1[iVar2 * 5 + 5],0,0);
    goto switchD_007f4372_caseD_a0;
  case 0x30:
    FUN_007d3460(iVar6,param_1[iVar2 * 5 + -0x19],param_1 + iVar2 * 5 + -10,param_1[iVar2 * 5 + -5],
                 param_1[iVar2 * 5]);
    FUN_007d3750(iVar6,param_1[iVar2 * 5 + 5]);
    goto switchD_007f4372_caseD_a0;
  case 0x31:
    piVar11 = (int *)0x63;
    local_c = (int *)0x63;
    break;
  case 0x32:
    piVar11 = (int *)0x4;
    local_c = (int *)0x4;
    break;
  case 0x33:
    piVar11 = (int *)0x5;
    local_c = (int *)0x5;
    break;
  case 0x34:
    FUN_007d46c0(iVar6,param_1[iVar2 * 5 + 5],0);
    goto switchD_007f4372_caseD_a0;
  case 0x35:
    FUN_007d55c0(iVar6,param_1 + iVar2 * 5 + -0x19,param_1 + iVar2 * 5 + -10,
                 param_1 + iVar2 * 5 + -5,param_1[iVar2 * 5 + 5],param_1[iVar2 * 5 + -0x14]);
    goto switchD_007f4372_caseD_a0;
  case 0x36:
    FUN_007d46c0(iVar6,param_1[iVar2 * 5 + 5],1);
    goto switchD_007f4372_caseD_a0;
  case 0x37:
    FUN_007e9760(iVar6,param_1[iVar2 * 5 + 5],1,0,0,0,0,0);
    FUN_007e6af0(param_1[iVar2 * 5 + 5]);
    goto switchD_007f4372_caseD_a0;
  case 0x38:
    if (param_1[iVar2 * 5 + 5] != 0) {
      *(char *)(param_1[iVar2 * 5 + 5] + 4) = (char)param_1[iVar2 * 5];
      *(int *)(param_1[iVar2 * 5 + 5] + 0x1c) = param_1[iVar2 * 5 + -5];
    }
    goto switchD_007f4372_caseD_2b;
  case 0x39:
    piVar11 = (int *)0x6e;
    local_c = (int *)0x6e;
    break;
  case 0x3a:
    piVar11 = (int *)FUN_007e6530(param_1[iVar2 * 5 + -0x19],param_1[iVar2 * 5 + -0x14],
                                  param_1[iVar2 * 5 + -0xf],param_1[iVar2 * 5 + -10],
                                  param_1[iVar2 * 5 + -5],param_1[iVar2 * 5],
                                  param_1[iVar2 * 5 + -0x1e],param_1[iVar2 * 5 + 5],
                                  param_1[iVar2 * 5 + 6]);
    local_c = piVar11;
    break;
  case 0x3b:
    piVar11 = (int *)param_1[iVar2 * 5];
    local_c = piVar11;
    break;
  case 0x3c:
    if ((param_1[iVar2 * 5 + 6] & 0xfffffffeU) == 0) {
      iVar6 = param_1[iVar2 * 5];
      piVar11 = (int *)0x0;
    }
    else {
      iVar6 = param_1[iVar2 * 5];
      piVar11 = param_1 + iVar2 * 5 + 5;
    }
    goto LAB_007f4c80;
  case 0x3d:
    uVar14 = FUN_007eb130(0x6e,0,0,0,0);
    piVar11 = (int *)FUN_007eadd0(param_1[iVar2 * 5],uVar14);
    local_c = piVar11;
    break;
  case 0x3e:
    uVar14 = FUN_007eb130(0x6e,0,0,0);
    uVar4 = FUN_007eb130(0x1b,0,0,param_1 + iVar2 * 5 + -5);
    uVar14 = FUN_007eb130(0x73,uVar4,uVar14,0,0);
    piVar11 = (int *)FUN_007eadd0(param_1[iVar2 * 5 + -10],uVar14);
    local_c = piVar11;
    break;
  case 0x3f:
    local_8 = local_8 & 1;
    goto switchD_007f4372_caseD_a0;
  case 0x40:
    piVar11 = (int *)FUN_007d0550(0x2c);
    local_c = piVar11;
    break;
  case 0x41:
    goto switchD_007f4372_caseD_41;
  case 0x42:
    piVar11 = (int *)param_1[iVar2 * 5];
    local_c = piVar11;
    if ((piVar11 != (int *)0x0) && (0 < (short)*piVar11)) {
      piVar11[(short)*piVar11 * 10 + -4] = param_1[iVar2 * 5 + 5];
    }
    break;
  case 0x43:
    piVar11 = (int *)FUN_007d5320(param_1[iVar2 * 5 + -0x14],param_1 + iVar2 * 5 + -0xf,
                                  param_1 + iVar2 * 5 + -10);
    local_c = piVar11;
    if ((param_1[iVar2 * 5 + -4] & 0xfffffffeU) != 0) {
      FUN_007d3930(piVar11,param_1 + iVar2 * 5 + -5);
    }
    iVar6 = param_1[iVar2 * 5];
    if (iVar6 != 0) {
      if ((piVar11 == (int *)0x0) || ((short)*piVar11 < 2)) {
        FUN_007eabc0(iVar6);
      }
      else {
        piVar11[(short)*piVar11 * 10 + -0xc] = iVar6;
      }
    }
    iVar6 = param_1[iVar2 * 5 + 5];
    if (iVar6 != 0) {
      if (piVar11 != (int *)0x0) goto LAB_007f4a21;
LAB_007f49a9:
      FUN_007d3980(iVar6);
    }
    break;
  case 0x44:
    piVar11 = (int *)FUN_007d5320(param_1[iVar2 * 5 + -0x19],0,0);
    piVar11[(short)*piVar11 * 10 + -5] = param_1[iVar2 * 5 + -0xf];
    local_c = piVar11;
    if ((param_1[iVar2 * 5 + -4] & 0xfffffffeU) != 0) {
      FUN_007d3930(piVar11,param_1 + iVar2 * 5 + -5);
    }
    iVar6 = param_1[iVar2 * 5];
    if (iVar6 != 0) {
      if ((short)*piVar11 < 2) {
        FUN_007eabc0(iVar6);
      }
      else {
        piVar11[(short)*piVar11 * 10 + -0xc] = iVar6;
      }
    }
    iVar6 = param_1[iVar2 * 5 + 5];
    if (iVar6 != 0) {
LAB_007f4a21:
      if ((short)*piVar11 < 2) goto LAB_007f49a9;
      piVar11[(short)*piVar11 * 10 + -0xb] = iVar6;
    }
    break;
  case 0x45:
    piVar11 = (int *)FUN_007e6530(0,param_1[iVar2 * 5 + 5],0,0,0,0,0,0,0);
    local_c = piVar11;
    break;
  case 0x46:
    piVar11 = (int *)0x0;
    local_8 = local_8 & 1;
    local_c = (int *)0x0;
    break;
  case 0x47:
    piVar11 = (int *)FUN_007d5320(0,param_1 + iVar2 * 5,param_1 + iVar2 * 5 + 5);
    local_c = piVar11;
    break;
  case 0x48:
    piVar11 = (int *)FUN_007e6600(iVar6,param_1 + iVar2 * 5,0,0);
    local_c = piVar11;
    break;
  case 0x49:
    piVar11 = (int *)FUN_007e6600(iVar6,param_1 + iVar2 * 5 + -5,param_1 + iVar2 * 5,0);
    local_c = piVar11;
    break;
  case 0x4a:
    piVar11 = (int *)FUN_007e6600(iVar6,param_1 + iVar2 * 5 + -10,param_1 + iVar2 * 5 + -5,
                                  param_1 + iVar2 * 5);
    local_c = piVar11;
    break;
  case 0x4b:
    piVar11 = (int *)param_1[iVar2 * 5];
    local_c = piVar11;
    break;
  case 0x4c:
    if ((param_1[iVar2 * 5 + 1] & 0xfffffffeU) == 0) {
      piVar11 = (int *)0x0;
    }
    else {
      piVar11 = param_1 + iVar2 * 5;
    }
    piVar11 = (int *)FUN_007eadd0(param_1[iVar2 * 5 + -0xf],param_1[iVar2 * 5 + -5],piVar11);
    local_c = piVar11;
    if (piVar11 != (int *)0x0) {
      *(char *)(piVar11[2] + -4 + *piVar11 * 0xc) = (char)param_1[iVar2 * 5 + 5];
    }
    break;
  case 0x4d:
    if ((param_1[iVar2 * 5 + 1] & 0xfffffffeU) == 0) {
      piVar11 = (int *)0x0;
    }
    else {
      piVar11 = param_1 + iVar2 * 5;
    }
    piVar11 = (int *)FUN_007eadd0(0,param_1[iVar2 * 5 + -5],piVar11);
    local_c = piVar11;
    if ((piVar11 != (int *)0x0) && (piVar11[2] != 0)) {
      *(char *)(piVar11[2] + 8) = (char)param_1[iVar2 * 5 + 5];
    }
    break;
  case 0x4e:
    piVar11 = (int *)param_1[iVar2 * 5 + 5];
    local_8 = 0;
    local_c = piVar11;
    break;
  case 0x4f:
    piVar11 = (int *)param_1[iVar2 * 5 + -5];
    local_8 = param_1[iVar2 * 5 + 5];
    local_c = piVar11;
    break;
  case 0x50:
    local_8 = param_1[iVar2 * 5 + -5];
    goto switchD_007f4372_caseD_41;
  case 0x51:
    FUN_007ecea0(iVar6,param_1[iVar2 * 5],param_1[iVar2 * 5 + 5]);
    goto switchD_007f4372_caseD_a0;
  case 0x52:
    FUN_007f8c40(iVar6,param_1[iVar2 * 5 + -10],param_1[iVar2 * 5],param_1[iVar2 * 5 + 5],
                 param_1[iVar2 * 5 + -0xf]);
    goto switchD_007f4372_caseD_a0;
  case 0x53:
    piVar11 = (int *)FUN_007eadd0(param_1[iVar2 * 5 + -0xf],param_1[iVar2 * 5 + 5],
                                  param_1 + iVar2 * 5 + -5);
    local_c = piVar11;
    break;
  case 0x54:
    piVar11 = (int *)FUN_007eadd0(0,param_1[iVar2 * 5 + 5],param_1 + iVar2 * 5 + -5);
    local_c = piVar11;
    break;
  case 0x55:
    FUN_007fa1b0(iVar6,param_1[iVar2 * 5 + -0x14],param_1[iVar2 * 5],0,param_1[iVar2 * 5 + -0xf],
                 param_1[iVar2 * 5 + -0x1e]);
    goto switchD_007f4372_caseD_a0;
  case 0x56:
    FUN_007fa1b0(iVar6,param_1[iVar2 * 5 + -5],0,param_1[iVar2 * 5 + 5],param_1[iVar2 * 5],
                 param_1[iVar2 * 5 + -0xf]);
    goto switchD_007f4372_caseD_a0;
  case 0x57:
    iVar6 = param_1[iVar2 * 5 + 5];
    piVar11 = (int *)0x0;
LAB_007f4c80:
    piVar11 = (int *)FUN_007eadd0(param_1[iVar2 * 5 + -5],iVar6,piVar11);
    local_c = piVar11;
    break;
  case 0x58:
    piVar11 = (int *)FUN_007eadd0(0,param_1[iVar2 * 5 + 5],0);
    local_c = piVar11;
    break;
  case 0x59:
    piVar11 = (int *)FUN_007d5280(param_1[iVar2 * 5 + -5],param_1 + iVar2 * 5 + 5);
    local_c = piVar11;
    break;
  case 0x5a:
    piVar11 = (int *)FUN_007d5280(0,param_1 + iVar2 * 5 + 5);
    local_c = piVar11;
    break;
  case 0x5b:
    piVar11 = (int *)param_1[iVar2 * 5];
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1 + iVar2 * 5 + -5,param_1 + iVar2 * 5 + 5);
    break;
  case 0x5c:
    piVar11 = (int *)FUN_007eb130(param_1[iVar2 * 5 + 4],0,0,param_1 + iVar2 * 5 + 5);
    local_c = piVar11;
    break;
  case 0x5d:
    piVar11 = (int *)FUN_007eb130(0x1b,0,0,param_1 + iVar2 * 5 + 5);
    local_c = piVar11;
    break;
  case 0x5e:
    uVar14 = FUN_007eb130(0x1b,0,0,param_1 + iVar2 * 5 + -5);
    uVar4 = FUN_007eb130(0x1b,0,0,param_1 + iVar2 * 5 + 5);
    piVar11 = (int *)FUN_007eb130(0x73,uVar14,uVar4,0);
    local_c = piVar11;
    break;
  case 0x5f:
    uVar14 = FUN_007eb130(0x1b,0,0,param_1 + iVar2 * 5 + -0xf);
    uVar4 = FUN_007eb130(0x1b,0,0,param_1 + iVar2 * 5 + -5);
    uVar5 = FUN_007eb130(0x1b,0,0,param_1 + iVar2 * 5 + 5);
    uVar4 = FUN_007eb130(0x73,uVar4,uVar5,0);
    piVar11 = (int *)FUN_007eb130(0x73,uVar14,uVar4,0);
    local_c = piVar11;
    break;
  case 0x60:
    piVar11 = (int *)FUN_007eb1c0(iVar6,param_1 + iVar2 * 5 + 5);
    local_c = piVar11;
    break;
  case 0x61:
    piVar11 = (int *)FUN_007eb130(0x83,0,0,param_1 + iVar2 * 5 + 5);
    local_c = piVar11;
    FUN_007ea420(iVar6,piVar11);
    break;
  case 0x62:
    piVar11 = (int *)FUN_007eab60(param_1[iVar2 * 5],param_1 + iVar2 * 5 + -10);
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1 + iVar2 * 5 + -10,param_1 + iVar2 * 5 + 5);
    break;
  case 99:
    piVar11 = (int *)FUN_007eab60(0,param_1 + iVar2 * 5 + -10);
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1 + iVar2 * 5 + -10,param_1 + iVar2 * 5 + 5);
    break;
  case 100:
    piVar11 = (int *)FUN_007eab60(0,param_1 + iVar2 * 5 + 5);
    local_c = piVar11;
    if (piVar11 != (int *)0x0) {
      *(undefined1 *)piVar11 = 9;
    }
    break;
  case 0x65:
    piVar11 = (int *)FUN_007eb130(param_1[iVar2 * 5 + -1],param_1[iVar2 * 5 + -5],
                                  param_1[iVar2 * 5 + 5],0);
    local_c = piVar11;
    break;
  case 0x66:
    piVar11 = (int *)param_1[iVar2 * 5 + 5];
    local_8 = param_1[iVar2 * 5 + 6];
    local_4 = 0;
    local_c = piVar11;
    break;
  case 0x67:
    piVar11 = (int *)param_1[iVar2 * 5 + 5];
    local_8 = param_1[iVar2 * 5 + 6];
    local_4 = 1;
    local_c = piVar11;
    break;
  case 0x68:
    uVar14 = FUN_007eadd0(0,param_1[iVar2 * 5],0);
    uVar14 = FUN_007eadd0(uVar14,param_1[iVar2 * 5 + -10],0);
    if (param_1[iVar2 * 5 + 5] != 0) {
      uVar14 = FUN_007eadd0(uVar14,param_1[iVar2 * 5 + 5],0);
    }
    local_c = (int *)FUN_007eab60(uVar14,param_1 + iVar2 * 5 + -5);
    if (param_1[iVar2 * 5 + -3] != 0) {
      local_c = (int *)FUN_007eb130(0x40,local_c,0,0);
    }
    piVar11 = local_c;
    FUN_007ea3c0(local_c,param_1[iVar2 * 5 + -10] + 0x1c,param_1[iVar2 * 5] + 0x1c);
    break;
  case 0x69:
    piVar11 = (int *)FUN_007eb130(0x44,param_1[iVar2 * 5],0,0);
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1[iVar2 * 5] + 0x1c,param_1 + iVar2 * 5 + 5);
    break;
  case 0x6a:
    piVar11 = (int *)FUN_007eb130(0x44,param_1[iVar2 * 5 + -5],0,0);
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1[iVar2 * 5 + -5] + 0x1c,param_1 + iVar2 * 5 + 5);
    break;
  case 0x6b:
    piVar11 = (int *)FUN_007eb130(0x45,param_1[iVar2 * 5],0,0);
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1[iVar2 * 5] + 0x1c,param_1 + iVar2 * 5 + 5);
    break;
  case 0x6c:
    piVar11 = (int *)FUN_007eb130(0x45,param_1[iVar2 * 5 + -5],0,0);
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1[iVar2 * 5 + -5] + 0x1c,param_1 + iVar2 * 5 + 5);
    break;
  case 0x6d:
    piVar11 = (int *)FUN_007eb130(0x45,param_1[iVar2 * 5 + -10],0,0);
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1[iVar2 * 5 + -10] + 0x1c,param_1 + iVar2 * 5 + 5);
    break;
  case 0x6e:
    piVar11 = (int *)FUN_007eb130(param_1[iVar2 * 5 + -1],param_1[iVar2 * 5 + 5],0,0);
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1 + iVar2 * 5,param_1[iVar2 * 5 + 5] + 0x1c);
    break;
  case 0x6f:
    piVar11 = (int *)FUN_007eb130(0x57,param_1[iVar2 * 5 + 5],0,0);
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1 + iVar2 * 5,param_1[iVar2 * 5 + 5] + 0x1c);
    break;
  case 0x70:
    piVar11 = (int *)FUN_007eb130(0x58,param_1[iVar2 * 5 + 5],0,0);
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1 + iVar2 * 5,param_1[iVar2 * 5 + 5] + 0x1c);
    break;
  case 0x71:
    uVar14 = FUN_007eadd0(0,param_1[iVar2 * 5 + -5],0);
    iVar6 = FUN_007eadd0(uVar14,param_1[iVar2 * 5 + 5],0);
    local_c = (int *)FUN_007eb130(0x42,param_1[iVar2 * 5 + -0xf],0,0);
    if (local_c != (int *)0x0) {
      local_c[4] = iVar6;
    }
    if (param_1[iVar2 * 5 + -10] != 0) {
      local_c = (int *)FUN_007eb130(0x40,local_c,0,0);
    }
    piVar11 = local_c;
    FUN_007ea3c0(local_c,param_1[iVar2 * 5 + -0xf] + 0x1c,param_1[iVar2 * 5 + 5] + 0x1c);
    break;
  case 0x72:
    piVar11 = (int *)FUN_007eb130(0x43,param_1[iVar2 * 5 + -0xf],0,0);
    local_c = piVar11;
    if (piVar11 == (int *)0x0) {
      FUN_007ea740(param_1[iVar2 * 5]);
    }
    else {
      piVar11[4] = param_1[iVar2 * 5];
    }
    if (param_1[iVar2 * 5 + -10] != 0) {
      piVar11 = (int *)FUN_007eb130(0x40,piVar11,0,0);
      local_c = piVar11;
    }
    FUN_007ea3c0(piVar11,param_1[iVar2 * 5 + -0xf] + 0x1c,param_1 + iVar2 * 5 + 5);
    break;
  case 0x73:
    piVar11 = (int *)FUN_007eb130(0x71,0,0,0);
    local_c = piVar11;
    if (piVar11 == (int *)0x0) {
      FUN_007e6af0(param_1[iVar2 * 5]);
    }
    else {
      piVar11[0xd] = param_1[iVar2 * 5];
    }
    FUN_007ea3c0(piVar11,param_1 + iVar2 * 5 + -5,param_1 + iVar2 * 5 + 5);
    break;
  case 0x74:
    piVar11 = (int *)FUN_007eb130(0x43,param_1[iVar2 * 5 + -0xf],0,0);
    local_c = piVar11;
    if (piVar11 == (int *)0x0) {
      FUN_007e6af0(param_1[iVar2 * 5]);
    }
    else {
      piVar11[0xd] = param_1[iVar2 * 5];
    }
    if (param_1[iVar2 * 5 + -10] != 0) {
      piVar11 = (int *)FUN_007eb130(0x40,piVar11,0,0);
      local_c = piVar11;
    }
    FUN_007ea3c0(piVar11,param_1[iVar2 * 5 + -0xf] + 0x1c,param_1 + iVar2 * 5 + 5);
    break;
  case 0x75:
    piVar12 = param_1 + iVar2 * 5 + 5;
    local_14 = FUN_007d5320(0,param_1 + iVar2 * 5,piVar12);
    piVar11 = (int *)FUN_007eb130(0x43,param_1[iVar2 * 5 + -10],0,0);
    local_c = piVar11;
    if (piVar11 != (int *)0x0) {
      iVar6 = FUN_007e6530(0,local_14,0,0,0,0,0,0,0);
      piVar11[0xd] = iVar6;
    }
    if (param_1[iVar2 * 5 + -5] != 0) {
      piVar11 = (int *)FUN_007eb130(0x40,piVar11,0,0);
      local_c = piVar11;
    }
    piVar13 = param_1 + iVar2 * 5;
    if (*piVar12 != 0) {
      piVar13 = piVar12;
    }
    FUN_007ea3c0(piVar11,param_1[iVar2 * 5 + -10] + 0x1c,piVar13);
    break;
  case 0x76:
    piVar11 = (int *)FUN_007eb130(0x84,0,0,0);
    local_c = piVar11;
    if (piVar11 == (int *)0x0) {
      FUN_007e6af0(param_1[iVar2 * 5]);
    }
    else {
      piVar11[0xd] = param_1[iVar2 * 5];
      FUN_007ea3c0(piVar11,param_1 + iVar2 * 5 + -10,param_1 + iVar2 * 5 + 5);
    }
    break;
  case 0x77:
    piVar11 = (int *)FUN_007eb130(0x85,param_1[iVar2 * 5 + -10],param_1[iVar2 * 5],0);
    if (piVar11 != (int *)0x0) {
      piVar11[4] = param_1[iVar2 * 5 + -5];
    }
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1 + iVar2 * 5 + -0xf,param_1 + iVar2 * 5 + 5);
    break;
  case 0x78:
    uVar14 = FUN_007eadd0(param_1[iVar2 * 5 + -0xf],param_1[iVar2 * 5 + -5],0);
    piVar11 = (int *)FUN_007eadd0(uVar14,param_1[iVar2 * 5 + 5],0);
    local_c = piVar11;
    break;
  case 0x79:
    uVar14 = FUN_007eadd0(0,param_1[iVar2 * 5 + -5],0);
    piVar11 = (int *)FUN_007eadd0(uVar14,param_1[iVar2 * 5 + 5],0);
    local_c = piVar11;
    break;
  case 0x7a:
    if (param_1[iVar2 * 5 + -0x28] != 0) {
      param_1[iVar2 * 5 + -0x28] = param_1[iVar2 * 5 + 5];
    }
    if (param_1[iVar2 * 5 + -0x28] == 99) {
      param_1[iVar2 * 5 + -0x28] = 2;
    }
    uVar14 = FUN_007d5320(0,param_1 + iVar2 * 5 + -0xf,0,param_1[iVar2 * 5 + -5],
                          param_1[iVar2 * 5 + -0x28],param_1 + iVar2 * 5 + -0x2d,param_1 + iVar2 * 5
                         );
    FUN_007d4900(iVar6,param_1 + iVar2 * 5 + -0x1e,param_1 + iVar2 * 5 + -0x19,uVar14);
    goto switchD_007f4372_caseD_a0;
  case 0x7b:
    piVar11 = (int *)0x2;
    local_c = (int *)0x2;
    break;
  case 0x7c:
    iVar10 = 0;
    if (((param_1[iVar2 * 5 + 1] & 0xfffffffeU) != 0) &&
       (iVar10 = FUN_007eb130(7,0,0,0), iVar10 != 0)) {
      uVar14 = FUN_007d2c50(iVar6,param_1[iVar2 * 5],(uint)param_1[iVar2 * 5 + 1] >> 1);
      *(undefined4 *)(iVar10 + 4) = uVar14;
    }
    piVar11 = (int *)FUN_007eadd0(param_1[iVar2 * 5 + -0xf],iVar10,param_1 + iVar2 * 5 + -5);
    local_c = piVar11;
    break;
  case 0x7d:
    iVar10 = 0;
    if (((param_1[iVar2 * 5 + 1] & 0xfffffffeU) != 0) &&
       (iVar10 = FUN_007eb130(7,0,0,0), iVar10 != 0)) {
      uVar14 = FUN_007d2c50(iVar6,param_1[iVar2 * 5],(uint)param_1[iVar2 * 5 + 1] >> 1);
      *(undefined4 *)(iVar10 + 4) = uVar14;
    }
    piVar11 = (int *)FUN_007eadd0(0,iVar10,param_1 + iVar2 * 5 + -5);
    local_c = piVar11;
    break;
  case 0x7e:
    FUN_007d50f0(iVar6,param_1[iVar2 * 5 + 5]);
    goto switchD_007f4372_caseD_a0;
  case 0x7f:
    FUN_007f3d90(iVar6,0);
    goto switchD_007f4372_caseD_a0;
  case 0x80:
    uVar14 = 0;
    goto LAB_007f54d2;
  case 0x81:
    uVar14 = 1;
LAB_007f54d2:
    FUN_007fb140(iVar6,param_1 + iVar2 * 5 + -10,param_1 + iVar2 * 5 + -5,param_1 + iVar2 * 5 + 5,
                 uVar14);
    goto switchD_007f4372_caseD_a0;
  case 0x82:
    FUN_007fb140(iVar6,param_1 + iVar2 * 5 + -0xf,param_1 + iVar2 * 5 + -10,param_1 + iVar2 * 5,0);
    goto switchD_007f4372_caseD_a0;
  case 0x83:
    FUN_007fb140(iVar6,param_1 + iVar2 * 5,param_1 + iVar2 * 5 + 5,0,0);
    goto switchD_007f4372_caseD_a0;
  case 0x84:
    local_14 = param_1[iVar2 * 5 + -10];
    local_10 = (param_1[iVar2 * 5 + 6] & 0xfffffffeU) + (param_1[iVar2 * 5 + 5] - local_14) * 2 ^
               local_10 & 1;
    FUN_007ee300(iVar6,param_1[iVar2 * 5],&local_14);
    goto switchD_007f4372_caseD_a0;
  case 0x85:
    FUN_007edfa0(iVar6,param_1 + iVar2 * 5 + -0x1e,param_1 + iVar2 * 5 + -0x19,
                 param_1[iVar2 * 5 + -0x14],param_1[iVar2 * 5 + -0xf],param_1[iVar2 * 5 + -0xe],
                 param_1[iVar2 * 5 + -5],param_1[iVar2 * 5],param_1[iVar2 * 5 + 5],
                 param_1[iVar2 * 5 + -0x28]);
    if ((param_1[iVar2 * 5 + -0x18] & 0xfffffffeU) == 0) {
      piVar11 = (int *)param_1[iVar2 * 5 + -0x1e];
      local_8 = param_1[iVar2 * 5 + -0x1d];
      local_c = piVar11;
    }
    else {
      local_8 = param_1[iVar2 * 5 + -0x18];
      piVar11 = (int *)param_1[iVar2 * 5 + -0x19];
      local_c = piVar11;
    }
    break;
  case 0x86:
    piVar11 = (int *)0x20;
    local_c = (int *)0x20;
    break;
  case 0x87:
    piVar11 = (int *)0x1d;
    local_c = (int *)0x1d;
    break;
  case 0x88:
    piVar11 = (int *)0x2b;
    local_c = (int *)0x2b;
    break;
  case 0x89:
    piVar11 = (int *)param_1[iVar2 * 5 + 4];
    local_8 = 0;
    local_c = piVar11;
    break;
  case 0x8a:
    local_8 = param_1[iVar2 * 5 + 5];
    piVar11 = (int *)0x67;
    local_c = (int *)0x67;
    break;
  case 0x8b:
    piVar11 = (int *)&DAT_00000035;
    local_c = (int *)&DAT_00000035;
    break;
  case 0x8c:
    piVar11 = (int *)0x36;
    local_c = (int *)0x36;
    break;
  case 0x8d:
    *(int *)(param_1[iVar2 * 5 + -5] + 0x24) = param_1[iVar2 * 5 + 5];
    piVar11 = (int *)param_1[iVar2 * 5 + -5];
    local_c = piVar11;
    break;
  case 0x8e:
    piVar11 = (int *)FUN_007ed850(param_1 + iVar2 * 5 + -10,param_1[iVar2 * 5],
                                  param_1[iVar2 * 5 + 5],param_1[iVar2 * 5 + -0xf]);
    local_c = piVar11;
    break;
  case 0x8f:
    piVar11 = (int *)FUN_007ed7e0(param_1 + iVar2 * 5 + -0x14,param_1[iVar2 * 5 + -0xf],
                                  param_1[iVar2 * 5],0,param_1[iVar2 * 5 + -0x1e]);
    local_c = piVar11;
    break;
  case 0x90:
    piVar11 = (int *)FUN_007ed7e0(param_1 + iVar2 * 5 + -5,param_1[iVar2 * 5],0,
                                  param_1[iVar2 * 5 + 5],param_1[iVar2 * 5 + -0xf]);
    local_c = piVar11;
    break;
  case 0x91:
    piVar11 = (int *)FUN_007ed8a0(param_1 + iVar2 * 5,param_1[iVar2 * 5 + 5]);
    local_c = piVar11;
    break;
  case 0x92:
    piVar11 = (int *)FUN_007ed7b0(param_1[iVar2 * 5 + 5]);
    local_c = piVar11;
    break;
  case 0x93:
    piVar11 = (int *)FUN_007eb130(0x32,0,0,0);
    piVar11[10] = 4;
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1 + iVar2 * 5 + -10,param_1 + iVar2 * 5 + 5);
    break;
  case 0x94:
    piVar11 = (int *)FUN_007eb130(0x32,0,0,param_1 + iVar2 * 5);
    piVar11[10] = param_1[iVar2 * 5 + -10];
    local_c = piVar11;
    FUN_007ea3c0(piVar11,param_1 + iVar2 * 5 + -0x14,param_1 + iVar2 * 5 + 5);
    break;
  case 0x95:
    piVar11 = (int *)0x3;
    local_c = (int *)0x3;
    break;
  case 0x96:
    FUN_007ee4d0(iVar6,param_1[iVar2 * 5 + 5]);
    goto switchD_007f4372_caseD_a0;
  case 0x97:
    FUN_007ee5e0(iVar6,param_1 + iVar2 * 5 + -10,param_1 + iVar2 * 5,param_1[iVar2 * 5 + 5],
                 param_1 + iVar2 * 5 + 6);
    goto switchD_007f4372_caseD_a0;
  case 0x98:
    local_8 = param_1[iVar2 * 5 + 5];
    local_4 = param_1[iVar2 * 5 + 6];
    piVar11 = (int *)0x1;
    local_c = (int *)0x1;
    break;
  case 0x99:
    local_8 = param_1[iVar2 * 5 + 5];
    local_4 = param_1[iVar2 * 5 + 6];
    piVar11 = (int *)0x2;
    local_c = (int *)0x2;
    break;
  case 0x9a:
    FUN_007ee870(iVar6,param_1 + iVar2 * 5 + 5);
    goto switchD_007f4372_caseD_a0;
  case 0x9b:
    FUN_007d3e70(iVar6,0,0);
    goto switchD_007f4372_caseD_a0;
  case 0x9c:
    FUN_007d3e70(iVar6,param_1 + iVar2 * 5,param_1 + iVar2 * 5 + 5);
    goto switchD_007f4372_caseD_a0;
  case 0x9d:
    FUN_007f3660(iVar6,param_1[iVar2 * 5 + -10],param_1 + iVar2 * 5 + 5);
    goto switchD_007f4372_caseD_a0;
  case 0x9e:
    FUN_007f3860(iVar6,param_1 + iVar2 * 5 + 5);
    goto switchD_007f4372_caseD_a0;
  case 0x9f:
    FUN_007f3a80(iVar6,param_1[iVar2 * 5 + 5]);
    goto switchD_007f4372_caseD_a0;
  }
LAB_007f5824:
  uVar9 = (uint)(byte)(&DAT_00a051f8)[param_2 * 2];
  uVar7 = (uint)(byte)(&DAT_00a051f9)[param_2 * 2];
  piVar12 = param_1 + iVar2 * 5 + uVar7 * -5 + 3;
  *param_1 = *param_1 - uVar7;
  if (*(short *)(&DAT_00a04888 + *piVar12 * 2) != -0x47) {
    if (uVar9 == 0xf1) {
      return;
    }
    uVar8 = (int)*(short *)(&DAT_00a04888 + *piVar12 * 2) + uVar9;
    if (((-1 < (int)uVar8) && (uVar8 < 0x56f)) && ((byte)(&DAT_00a03ea8)[uVar8] == uVar9)) {
      uVar1 = *(ushort *)(&DAT_00a033c8 + uVar8 * 2);
      goto LAB_007f588a;
    }
  }
  uVar1 = *(ushort *)(&DAT_00a04cf8 + *piVar12 * 2);
LAB_007f588a:
  uVar8 = (uint)uVar1;
  if (0x234 < uVar8) {
    if (uVar8 == 0x367) {
      FUN_007f4300();
    }
    return;
  }
  if (uVar7 == 0) {
    FUN_007f4290(uVar8,uVar9);
    return;
  }
  *param_1 = *param_1 + 1;
  piVar12[6] = uVar9;
  piVar12[5] = uVar8;
  piVar12[7] = (int)piVar11;
  piVar12[8] = local_8;
  piVar12[9] = local_4;
  return;
switchD_007f4372_caseD_41:
  piVar11 = (int *)param_1[iVar2 * 5 + 5];
  local_c = piVar11;
  goto LAB_007f5824;
switchD_007f4372_caseD_2b:
  piVar11 = (int *)param_1[iVar2 * 5 + 5];
  local_c = piVar11;
  goto LAB_007f5824;
switchD_007f4372_caseD_a:
  piVar11 = (int *)0x0;
  local_c = (int *)0x0;
  goto LAB_007f5824;
}


// ==== FUN_007f5ca0 @ 0x007f5ca0 ====

void FUN_007f5ca0(int *param_1,int param_2,char *param_3,undefined4 param_4,int param_5)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  char *local_18;
  undefined4 local_14;
  undefined4 local_c;
  
  bVar2 = false;
  if (*param_1 < 0) {
    *param_1 = 0;
    param_1[1] = -1;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  bVar7 = param_2 != 0;
  param_1[2] = param_5;
  iVar4 = param_2;
  do {
    iVar6 = 0;
    iVar3 = FUN_007f4220();
    if (iVar3 < 0x235) {
      FUN_007f4290(iVar3,iVar4);
      param_1[1] = param_1[1] + -1;
      if (bVar7) {
        return;
      }
      if (*param_1 < 0) {
        return;
      }
      param_2 = 0;
    }
    else {
      if (iVar3 < 0x366) {
        FUN_007f4340(param_1,iVar3 + -0x235);
        iVar6 = iVar4;
      }
      else {
        if (iVar3 != 0x366) {
          FUN_007f4300();
          return;
        }
        if (param_1[1] < 0) {
          iVar4 = param_1[2];
          local_18 = param_3;
          local_14 = param_4;
          if (*(int *)(iVar4 + 8) == 0) {
            if (*param_3 == '\0') {
              FUN_007d0820(iVar4,s_incomplete_SQL_statement_00a0545c);
            }
            else {
              FUN_007d0820(iVar4,s_near___T___syntax_error_00a01cc8,&local_18);
            }
          }
          param_1[2] = iVar4;
        }
        if ((param_1[*param_1 * 5 + 4] == 0x8d) || (bVar2)) {
          FUN_007f40e0();
LAB_007f5e7a:
          param_2 = 0xf1;
        }
        else {
          if (*param_1 < 0) {
LAB_007f5e5d:
            FUN_007f40e0();
            FUN_007f4300();
            goto LAB_007f5e7a;
          }
          do {
            iVar4 = (int)*(short *)(&DAT_00a04418 + param_1[*param_1 * 5 + 3] * 2);
            if ((((iVar4 == -0x46) || (uVar5 = iVar4 + 0x8d, (int)uVar5 < 0)) || (0x56e < uVar5)) ||
               ((&DAT_00a03f35)[iVar4] != -0x73)) {
              uVar1 = *(ushort *)(&DAT_00a04cf8 + param_1[*param_1 * 5 + 3] * 2);
            }
            else {
              uVar1 = *(ushort *)(&DAT_00a033c8 + uVar5 * 2);
            }
            if (uVar1 < 0x235) break;
            if (-1 < *param_1) {
              FUN_007f40e0();
              *param_1 = *param_1 + -1;
            }
          } while (-1 < *param_1);
          if ((*param_1 < 0) || (param_2 == 0)) goto LAB_007f5e5d;
          local_c = 0;
          FUN_007f4290(uVar1,0x8d);
        }
        param_1[1] = 3;
        bVar2 = true;
        iVar6 = param_2;
      }
      if (iVar6 == 0xf1) {
        return;
      }
    }
    iVar4 = iVar6;
    if (*param_1 < 0) {
      return;
    }
  } while( true );
}


// ==== FUN_007f5ec0 @ 0x007f5ec0 ====

void FUN_007f5ec0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (0 < iVar1) {
    do {
      if (*(int *)(param_1[3] + -4 + *param_1 * 4) != 0) break;
      iVar1 = *param_1 + -1;
      *param_1 = iVar1;
    } while (0 < iVar1);
    iVar1 = *param_1;
  }
  if (iVar1 == 0) {
    param_1[2] = 0;
  }
  return;
}


// ==== FUN_007f5ef0 @ 0x007f5ef0 ====

int FUN_007f5ef0(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  if ((param_1 == param_3) || (iVar1 = FUN_007fc260(param_1,param_3), iVar1 == 0)) {
    iVar1 = param_2 / 0x1c + 1 + *param_3;
    if (((iVar1 <= param_3[1]) || (iVar1 = FUN_007f6030(param_3,iVar1), iVar1 == 0)) &&
       ((param_2 < 0x1c || (iVar1 = FUN_007fc1e0(param_3,param_2 / 0x1c), iVar1 == 0)))) {
      if (param_2 % 0x1c != 0) {
        bVar2 = (byte)(param_2 % 0x1c);
        param_1 = (int *)0x0;
        uVar4 = 0;
        puVar5 = (uint *)param_3[3];
        if (0 < *param_3) {
          do {
            uVar3 = *puVar5 >> (0x1c - bVar2 & 0x1f) & (1 << (bVar2 & 0x1f)) - 1U;
            *puVar5 = (*puVar5 << (bVar2 & 0x1f) | uVar4) & 0xfffffff;
            param_1 = (int *)((int)param_1 + 1);
            uVar4 = uVar3;
            puVar5 = puVar5 + 1;
          } while ((int)param_1 < *param_3);
          if (uVar3 != 0) {
            *(uint *)(param_3[3] + *param_3 * 4) = uVar3;
            *param_3 = *param_3 + 1;
          }
        }
      }
      FUN_007f5ec0(param_3);
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== FUN_007f5ff0 @ 0x007f5ff0 ====

void FUN_007f5ff0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)param_1[3];
  iVar2 = 0;
  param_1[2] = 0;
  *param_1 = 0;
  if (0 < (int)param_1[1]) {
    do {
      *puVar1 = 0;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < (int)param_1[1]);
  }
  return;
}


// ==== FUN_007f6030 @ 0x007f6030 ====

undefined4 FUN_007f6030(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 4) < (int)param_2) {
    uVar1 = param_2 & 0x8000001f;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xffffffe0) + 1;
    }
    iVar3 = param_2 + (0x40 - uVar1);
    iVar2 = FUN_00806326(*(undefined4 *)(param_1 + 0xc),iVar3 * 4);
    if (iVar2 == 0) {
      return 0xfffffffe;
    }
    *(int *)(param_1 + 0xc) = iVar2;
    iVar2 = *(int *)(param_1 + 4);
    *(int *)(param_1 + 4) = iVar3;
    if (iVar2 < iVar3) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar2 * 4) = 0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 4));
    }
  }
  return 0;
}


// ==== FUN_007f60a0 @ 0x007f60a0 ====

void FUN_007f60a0(int *param_1)

{
  int iVar1;
  
  if (param_1[3] == 0) {
    return;
  }
  iVar1 = 0;
  if (0 < *param_1) {
    do {
      *(undefined4 *)(param_1[3] + iVar1 * 4) = 0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *param_1);
  }
  _free((void *)param_1[3]);
  return;
}


// ==== FUN_007f60f0 @ 0x007f60f0 ====

void FUN_007f60f0(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  param_2 = param_2 + -1;
  iVar2 = 0;
  if (0 < param_2) {
    do {
      uVar1 = *(undefined1 *)(iVar2 + param_1);
      *(undefined1 *)(iVar2 + param_1) = *(undefined1 *)(param_2 + param_1);
      *(undefined1 *)(param_2 + param_1) = uVar1;
      iVar2 = iVar2 + 1;
      param_2 = param_2 + -1;
    } while (iVar2 < param_2);
  }
  return;
}


// ==== FUN_007f6120 @ 0x007f6120 ====

int FUN_007f6120(undefined4 param_1,int param_2,int *param_3,int param_4)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined1 local_10 [16];
  
  if (param_2 < 1) {
    iVar2 = FUN_007fc260(param_1,param_3);
    if (param_4 != 0) {
      FUN_007f5ff0(param_4);
    }
    return iVar2;
  }
  iVar2 = FUN_007f6f20(local_10);
  if (iVar2 == 0) {
    if ((param_4 != 0) && (iVar2 = FUN_007fc380(param_1,param_2,local_10), iVar2 != 0)) {
      FUN_007f60a0(local_10);
      return iVar2;
    }
    iVar2 = FUN_007fc260(param_1,param_3);
    if (iVar2 != 0) {
      FUN_007f60a0(local_10);
      return iVar2;
    }
    if (0x1b < param_2) {
      FUN_007fc310(param_3,param_2 / 0x1c);
    }
    if (param_2 % 0x1c != 0) {
      iVar2 = *param_3;
      bVar3 = (byte)(param_2 % 0x1c);
      uVar4 = 0;
      puVar1 = (uint *)(param_3[3] + -4 + iVar2 * 4);
      while (iVar2 = iVar2 + -1, -1 < iVar2) {
        uVar5 = uVar4 << (0x1c - bVar3 & 0x1f);
        uVar4 = *puVar1 & (1 << (bVar3 & 0x1f)) - 1U;
        *puVar1 = *puVar1 >> (bVar3 & 0x1f) | uVar5;
        puVar1 = puVar1 + -1;
      }
    }
    FUN_007f5ec0(param_3);
    if (param_4 != 0) {
      FUN_007fc2d0(local_10,param_4);
    }
    FUN_007f60a0(local_10);
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_007f62a0 @ 0x007f62a0 ====

void FUN_007f62a0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_007f6f20(param_1);
  if (iVar1 == 0) {
    FUN_007fc260(param_2,param_1);
  }
  return;
}


// ==== FUN_007f62d0 @ 0x007f62d0 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_007f62d0(undefined4 param_1,int *param_2,int *param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  code *local_1034;
  undefined4 local_1030;
  int local_102c;
  uint local_1028;
  uint local_1024;
  int local_1020;
  undefined1 local_101c [16];
  int local_100c;
  uint local_1008;
  int local_1004;
  undefined1 auStack_1000 [16];
  undefined1 local_ff0 [4076];
  undefined4 uStack_4;
  
  uStack_4 = 0x7f62da;
  iVar2 = FUN_007fcda0(param_2);
  if (iVar2 < 8) {
    local_102c = 2;
  }
  else if (iVar2 < 0x25) {
    local_102c = 3;
  }
  else if (iVar2 < 0x8d) {
    local_102c = 4;
  }
  else if (iVar2 < 0x1c3) {
    local_102c = 5;
  }
  else if (iVar2 < 0x518) {
    local_102c = 6;
  }
  else {
    local_102c = (0xdc9 < iVar2) + 7;
  }
  iVar2 = FUN_007f6f20(local_ff0);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = 1 << ((byte)local_102c - 1 & 0x1f);
  local_1024 = 1 << ((byte)local_102c & 0x1f);
  local_1020 = iVar2;
  if (iVar2 < (int)local_1024) {
    puVar5 = auStack_1000 + iVar2 * 0x10;
    do {
      iVar3 = FUN_007f6f20(puVar5);
      if (iVar3 != 0) {
        if (local_1020 < iVar2) {
          puVar5 = auStack_1000 + local_1020 * 0x10;
          iVar2 = iVar2 - local_1020;
          do {
            FUN_007f60a0(puVar5);
            puVar5 = puVar5 + 0x10;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        FUN_007f60a0(local_ff0);
        return iVar3;
      }
      iVar2 = iVar2 + 1;
      puVar5 = puVar5 + 0x10;
    } while (iVar2 < (int)local_1024);
  }
  iVar2 = local_1020;
  if (param_5 == 0) {
    iVar3 = FUN_007fcd40(param_3,&local_1030);
    if (iVar3 != 0) goto LAB_007f681b;
    if ((*param_3 * 2 + 1 < 0x200) && (*param_3 < 0x100)) {
      local_1034 = FUN_007fcb50;
    }
    else {
      local_1034 = FUN_007fca00;
    }
  }
  else if (param_5 == 1) {
    FUN_007fc9e0(param_3,&local_1030);
    local_1034 = FUN_007fc8f0;
  }
  else {
    iVar3 = FUN_007fc860(param_3,&local_1030);
    if (iVar3 != 0) goto LAB_007f681b;
    local_1034 = (code *)&LAB_007fc7a0;
  }
  iVar3 = FUN_007f6f20(local_101c);
  if (iVar3 != 0) goto LAB_007f681b;
  if (param_5 == 0) {
    iVar3 = FUN_007fc700(local_101c,param_3);
    if (iVar3 != 0) goto LAB_007f680e;
    iVar3 = FUN_007fc690(param_1,local_101c,param_3,local_ff0);
  }
  else {
    FUN_007fc660(local_101c,1);
    iVar3 = FUN_007fc5d0(param_1,param_3,local_ff0);
  }
  if (iVar3 == 0) {
    puVar5 = auStack_1000 + iVar2 * 0x10;
    iVar3 = FUN_007fc260(local_ff0,puVar5);
    if (iVar3 == 0) {
      iVar2 = 0;
      if (0 < local_102c + -1) {
        do {
          iVar3 = FUN_007fc540(puVar5,puVar5);
          if ((iVar3 != 0) || (iVar3 = (*local_1034)(puVar5,param_3,local_1030), iVar3 != 0))
          goto LAB_007f680a;
          iVar2 = iVar2 + 1;
        } while (iVar2 < local_102c + -1);
      }
      iVar2 = local_1020 + 1;
      if (iVar2 < (int)local_1024) {
        puVar5 = auStack_1000 + iVar2 * 0x10;
        do {
          iVar3 = FUN_007fc470(puVar5 + -0x10,local_ff0,puVar5);
          if ((iVar3 != 0) || (iVar3 = (*local_1034)(puVar5,param_3,local_1030), iVar3 != 0))
          goto LAB_007f680a;
          iVar2 = iVar2 + 1;
          puVar5 = puVar5 + 0x10;
        } while (iVar2 < (int)local_1024);
      }
      iVar2 = 0;
      local_100c = *param_2 + -1;
      local_1004 = 1;
      local_1008 = 0;
      do {
        iVar6 = 0;
        local_1028 = 0;
        iVar3 = local_100c;
LAB_007f65e5:
        do {
          iVar1 = local_102c;
          local_1004 = local_1004 + -1;
          if (local_1004 == 0) {
            if (iVar3 == -1) {
              if (((iVar2 != 2) || (iVar6 < 1)) || (iVar2 = 0, iVar6 < 1)) goto LAB_007f67d1;
              goto LAB_007f6751;
            }
            local_1008 = *(uint *)(param_2[3] + iVar3 * 4);
            iVar3 = iVar3 + -1;
            local_1004 = 0x1c;
            local_100c = iVar3;
          }
          uVar4 = local_1008 >> 0x1b;
          local_1008 = local_1008 * 2;
          uVar4 = uVar4 & 1;
          if (iVar2 == 0) {
            if (uVar4 == 0) goto LAB_007f65e5;
          }
          else if ((iVar2 == 1) && (uVar4 == 0)) {
            iVar3 = FUN_007fc540(local_101c,local_101c);
            if ((iVar3 != 0) || (iVar3 = (*local_1034)(local_101c,param_3,local_1030), iVar3 != 0))
            goto LAB_007f680a;
            iVar3 = local_100c;
            goto LAB_007f65e5;
          }
          iVar6 = iVar6 + 1;
          iVar2 = 2;
          local_1028 = local_1028 | uVar4 << ((char)local_102c - (char)iVar6 & 0x1fU);
        } while (iVar6 != local_102c);
        iVar2 = 0;
        if (0 < local_102c) {
          do {
            iVar3 = FUN_007fc540(local_101c,local_101c);
            if ((iVar3 != 0) || (iVar3 = (*local_1034)(local_101c,param_3,local_1030), iVar3 != 0))
            goto LAB_007f680a;
            iVar2 = iVar2 + 1;
          } while (iVar2 < iVar1);
        }
        iVar3 = FUN_007fc470(local_101c,auStack_1000 + local_1028 * 0x10,local_101c);
        if ((iVar3 != 0) || (iVar3 = (*local_1034)(local_101c,param_3,local_1030), iVar3 != 0))
        goto LAB_007f680a;
        iVar2 = 1;
      } while( true );
    }
  }
  goto LAB_007f680e;
  while (iVar2 = iVar2 + 1, iVar2 < iVar6) {
LAB_007f6751:
    iVar3 = FUN_007fc540(local_101c,local_101c);
    if (((iVar3 != 0) || (iVar3 = (*local_1034)(local_101c,param_3,local_1030), iVar3 != 0)) ||
       ((local_1028 = local_1028 * 2, (local_1024 & local_1028) != 0 &&
        ((iVar3 = FUN_007fc470(local_101c,local_ff0,local_101c), iVar3 != 0 ||
         (iVar3 = (*local_1034)(local_101c,param_3,local_1030), iVar3 != 0)))))) goto LAB_007f680a;
  }
LAB_007f67d1:
  if ((param_5 != 0) || (iVar3 = (*local_1034)(local_101c,param_3,local_1030), iVar3 == 0)) {
    FUN_007fc2d0(local_101c,param_4);
    iVar3 = 0;
  }
LAB_007f680a:
  iVar2 = local_1020;
LAB_007f680e:
  FUN_007f60a0(local_101c);
LAB_007f681b:
  FUN_007f60a0(local_ff0);
  if (iVar2 < (int)local_1024) {
    iVar6 = local_1024 - iVar2;
    puVar5 = auStack_1000 + iVar2 * 0x10;
    do {
      FUN_007f60a0(puVar5);
      puVar5 = puVar5 + 0x10;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  return iVar3;
}


// ==== FUN_007f6860 @ 0x007f6860 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_007f6860(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  int local_1040;
  code *local_103c;
  uint local_1030;
  undefined1 local_102c [16];
  int local_101c;
  uint local_1018;
  int local_1014;
  undefined1 local_1010 [16];
  undefined1 auStack_1000 [16];
  undefined1 local_ff0 [4076];
  undefined4 uStack_4;
  
  uStack_4 = 0x7f686a;
  iVar1 = FUN_007fcda0(param_2);
  if (iVar1 < 8) {
    local_1040 = 2;
  }
  else if (iVar1 < 0x25) {
    local_1040 = 3;
  }
  else if (iVar1 < 0x8d) {
    local_1040 = 4;
  }
  else if (iVar1 < 0x1c3) {
    local_1040 = 5;
  }
  else if (iVar1 < 0x518) {
    local_1040 = 6;
  }
  else {
    local_1040 = (0xdc9 < iVar1) + 7;
  }
  iVar1 = FUN_007f6f20(local_ff0);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = local_1040 + -1;
  iVar5 = 1 << ((byte)iVar1 & 0x1f);
  uVar2 = 1 << (sbyte)local_1040;
  if (iVar5 < (int)uVar2) {
    puVar8 = auStack_1000 + iVar5 * 0x10;
    iVar7 = iVar5;
    do {
      iVar3 = FUN_007f6f20(puVar8);
      if (iVar3 != 0) {
        if (iVar5 < iVar7) {
          puVar8 = auStack_1000 + iVar5 * 0x10;
          iVar7 = iVar7 - iVar5;
          do {
            FUN_007f60a0(puVar8);
            puVar8 = puVar8 + 0x10;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        FUN_007f60a0(local_ff0);
        return iVar3;
      }
      iVar7 = iVar7 + 1;
      puVar8 = puVar8 + 0x10;
    } while (iVar7 < (int)uVar2);
  }
  iVar7 = FUN_007f6f20(local_1010);
  if (iVar7 != 0) goto LAB_007f6d69;
  if (param_5 == 0) {
    iVar7 = FUN_007fd050(local_1010,param_3);
    if (iVar7 == 0) {
      local_103c = FUN_007fcef0;
      goto LAB_007f69eb;
    }
  }
  else {
    iVar7 = FUN_007fce90(param_3,local_1010);
    if (iVar7 == 0) {
      local_103c = (code *)&LAB_007fcdd0;
LAB_007f69eb:
      iVar7 = FUN_007fc5d0(param_1,param_3,local_ff0);
      if (iVar7 == 0) {
        puVar8 = auStack_1000 + iVar5 * 0x10;
        iVar7 = FUN_007fc260(local_ff0,puVar8);
        if (iVar7 == 0) {
          iVar3 = 0;
          if (0 < iVar1) {
            do {
              iVar7 = FUN_007fc540(puVar8,puVar8);
              if ((iVar7 != 0) || (iVar7 = (*local_103c)(puVar8,param_3,local_1010), iVar7 != 0))
              goto LAB_007f6d5c;
              iVar3 = iVar3 + 1;
            } while (iVar3 < iVar1);
          }
          iVar1 = iVar5 + 1;
          if (iVar1 < (int)uVar2) {
            puVar8 = auStack_1000 + iVar1 * 0x10;
            do {
              iVar7 = FUN_007fc470(puVar8 + -0x10,local_ff0,puVar8);
              if ((iVar7 != 0) || (iVar7 = (*local_103c)(puVar8,param_3,local_1010), iVar7 != 0))
              goto LAB_007f6d5c;
              iVar1 = iVar1 + 1;
              puVar8 = puVar8 + 0x10;
            } while (iVar1 < (int)uVar2);
          }
          iVar7 = FUN_007f6f20(local_102c);
          uVar6 = 0;
          if (iVar7 == 0) {
            FUN_007fc660(local_102c,1);
            local_1014 = *param_2 + -1;
            iVar3 = 0;
            local_101c = 1;
            local_1018 = 0;
            iVar9 = 0;
            local_1030 = 0;
            iVar1 = local_1014;
LAB_007f6b23:
            while( true ) {
              local_101c = local_101c + -1;
              if (local_101c == 0) {
                if (iVar1 == -1) {
                  if (((iVar3 != 2) || (iVar9 < 1)) || (iVar1 = 0, iVar9 < 1)) goto LAB_007f6d34;
                  goto LAB_007f6ca6;
                }
                local_1018 = *(uint *)(param_2[3] + iVar1 * 4);
                iVar1 = iVar1 + -1;
                local_101c = 0x1c;
                local_1014 = iVar1;
              }
              uVar4 = local_1018 >> 0x1b;
              local_1018 = local_1018 * 2;
              uVar4 = uVar4 & 1;
              if (iVar3 == 0) goto code_r0x007f6b6d;
              if ((iVar3 != 1) || (uVar4 != 0)) goto LAB_007f6b71;
              iVar7 = FUN_007fc540(local_102c,local_102c);
              if ((iVar7 != 0) || (iVar7 = (*local_103c)(local_102c,param_3,local_1010), iVar7 != 0)
                 ) break;
              iVar1 = local_1014;
            }
            goto LAB_007f6d4b;
          }
        }
      }
    }
  }
LAB_007f6d5c:
  FUN_007f60a0(local_1010);
LAB_007f6d69:
  FUN_007f60a0(local_ff0);
  if (iVar5 < (int)uVar2) {
    iVar1 = uVar2 - iVar5;
    puVar8 = auStack_1000 + iVar5 * 0x10;
    do {
      FUN_007f60a0(puVar8);
      puVar8 = puVar8 + 0x10;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return iVar7;
  while (iVar1 = iVar1 + 1, iVar1 < iVar9) {
LAB_007f6ca6:
    iVar7 = FUN_007fc540(local_102c,local_102c);
    if (((iVar7 != 0) || (iVar7 = (*local_103c)(local_102c,param_3,local_1010), iVar7 != 0)) ||
       ((local_1030 = local_1030 * 2, (uVar2 & local_1030) != 0 &&
        ((iVar7 = FUN_007fc470(local_102c,local_ff0,local_102c), iVar7 != 0 ||
         (iVar7 = (*local_103c)(local_102c,param_3,local_1010), iVar7 != 0)))))) goto LAB_007f6d4b;
  }
LAB_007f6d34:
  FUN_007fc2d0(local_102c,param_4);
  iVar7 = 0;
LAB_007f6d4b:
  FUN_007f60a0(local_102c);
  goto LAB_007f6d5c;
code_r0x007f6b6d:
  if (uVar4 != 0) {
LAB_007f6b71:
    iVar9 = iVar9 + 1;
    iVar3 = 2;
    uVar6 = uVar6 | uVar4 << ((sbyte)local_1040 - (char)iVar9 & 0x1fU);
    local_1030 = uVar6;
    if (iVar9 == local_1040) {
      iVar1 = 0;
      if (local_1040 != 0) {
        do {
          iVar7 = FUN_007fc540(local_102c,local_102c);
          if ((iVar7 != 0) || (iVar7 = (*local_103c)(local_102c,param_3,local_1010), iVar7 != 0))
          goto LAB_007f6d4b;
          iVar1 = iVar1 + 1;
        } while (iVar1 < local_1040);
      }
      iVar7 = FUN_007fc470(local_102c,auStack_1000 + uVar6 * 0x10,local_102c);
      iVar9 = 0;
      if ((iVar7 != 0) || (iVar7 = (*local_103c)(local_102c,param_3,local_1010), iVar7 != 0))
      goto LAB_007f6d4b;
      local_1030 = 0;
      iVar3 = 1;
      uVar6 = 0;
      iVar1 = local_1014;
    }
  }
  goto LAB_007f6b23;
}


// ==== FUN_007f6db0 @ 0x007f6db0 ====

int FUN_007f6db0(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return iVar1;
  }
  if (iVar1 == 1) {
    return iVar1;
  }
  if (1 < iVar1) {
    iVar1 = FUN_007fcda0(param_1);
    iVar4 = 0x1c;
    uVar2 = 1;
    if (0x1c < iVar1) {
      puVar3 = (uint *)(param_1[3] + 4);
      do {
        if ((*puVar3 & uVar2) == 0) {
          return 0;
        }
        uVar2 = uVar2 * 2;
        if (0xfffffff < uVar2) {
          puVar3 = puVar3 + 1;
          uVar2 = 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  return 1;
}


// ==== FUN_007f6e20 @ 0x007f6e20 ====

undefined4 FUN_007f6e20(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (iVar1 < 2) {
    return 0;
  }
  if (1 < iVar1) {
    piVar2 = (int *)param_1[3];
    iVar3 = 1;
    do {
      piVar2 = piVar2 + 1;
      if (*piVar2 != 0xfffffff) {
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return 1;
}


// ==== FUN_007f6e60 @ 0x007f6e60 ====

bool FUN_007f6e60(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      return true;
    }
    if (1 < iVar1) {
      iVar4 = 0;
      if (0 < iVar1) {
        piVar2 = (int *)param_1[3];
        iVar3 = iVar1;
        do {
          if (*piVar2 == 0xfffffff) {
            iVar4 = iVar4 + 1;
          }
          piVar2 = piVar2 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      return iVar1 / 2 <= iVar4;
    }
  }
  return false;
}


// ==== FUN_007f6eb0 @ 0x007f6eb0 ====

int FUN_007f6eb0(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 == param_2) || (iVar1 = FUN_007fc260(param_1,param_2), iVar1 == 0)) {
    *(undefined4 *)(param_2 + 8) = 0;
    return 0;
  }
  return iVar1;
}


// ==== FUN_007f6ee0 @ 0x007f6ee0 ====

undefined4 FUN_007f6ee0(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_2[2] == 1) || (*param_2 == 0)) {
    return 0xfffffffd;
  }
  if ((*param_2 < 1) || ((*(byte *)param_2[3] & 1) == 0)) {
    uVar1 = FUN_007fd090();
    return uVar1;
  }
  uVar1 = FUN_007fd520();
  return uVar1;
}


// ==== FUN_007f6f20 @ 0x007f6f20 ====

undefined4 FUN_007f6f20(undefined4 *param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = _malloc(0x80);
  param_1[3] = pvVar1;
  if (pvVar1 == (void *)0x0) {
    return 0xfffffffe;
  }
  iVar2 = 0;
  do {
    *(undefined4 *)(iVar2 + param_1[3]) = 0;
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x80);
  *param_1 = 0;
  param_1[1] = 0x20;
  param_1[2] = 0;
  return 0;
}


// ==== FUN_007f6f70 @ 0x007f6f70 ====

undefined4 FUN_007f6f70(int *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *param_1;
  if (*param_2 < iVar1) {
    return 1;
  }
  if (iVar1 < *param_2) {
    return 0xffffffff;
  }
  iVar5 = 0;
  puVar3 = (uint *)(param_1[3] + -4 + iVar1 * 4);
  if (0 < iVar1) {
    iVar4 = (param_2[3] + -4 + iVar1 * 4) - (int)puVar3;
    do {
      uVar2 = *(uint *)(iVar4 + (int)puVar3);
      if (uVar2 < *puVar3) {
        return 1;
      }
      if (*puVar3 < uVar2) {
        return 0xffffffff;
      }
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + -1;
    } while (iVar5 < iVar1);
  }
  return 0;
}


// ==== FUN_007f6fe0 @ 0x007f6fe0 ====

int FUN_007f6fe0(int param_1,undefined4 *param_2,char *param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 != (char *)0x0) {
    if (0 < param_1) {
      if ((param_1 == 1) || (*param_3 != '?')) {
        *param_2 = param_3;
        return 1;
      }
      pcVar1 = *(char **)(param_3 + 8);
      if (*pcVar1 == '?') {
        iVar2 = FUN_007f6fe0(param_1,param_2,pcVar1);
        iVar3 = FUN_007f6fe0(param_1 - iVar2,param_2 + iVar2 * 6,*(undefined4 *)(param_3 + 0xc));
        return iVar2 + iVar3;
      }
      *param_2 = pcVar1;
      iVar2 = FUN_007f6fe0(param_1 + -1,param_2 + 6,*(undefined4 *)(param_3 + 0xc));
      return iVar2 + 1;
    }
  }
  return 0;
}


// ==== FUN_007f7070 @ 0x007f7070 ====

uint FUN_007f7070(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *unaff_ESI;
  int iVar4;
  
  uVar3 = 0;
  if (unaff_ESI == (int *)0x0) {
    return 0;
  }
  iVar4 = 0;
  if (*unaff_ESI < 1) {
    return 0;
  }
  iVar2 = 0;
  do {
    uVar1 = FUN_007f7410(param_1,*(undefined4 *)(unaff_ESI[2] + iVar2));
    uVar3 = uVar3 | uVar1;
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 0xc;
  } while (iVar4 < *unaff_ESI);
  return uVar3;
}


// ==== FUN_007f70c0 @ 0x007f70c0 ====

undefined4 FUN_007f70c0(int *param_1,int param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int *in_EAX;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_10;
  int *local_c;
  uint local_8;
  
  iVar1 = *param_1;
  puVar5 = (undefined4 *)in_EAX[2];
  iVar2 = *in_EAX;
  iVar6 = 0;
  local_10 = 0;
  if (0 < iVar2) {
    local_c = (int *)(param_2 + 0x2c);
    do {
      if (*(int *)(param_2 + 4) <= iVar6) {
        if ((local_10 < iVar2) &&
           ((iVar6 < *(int *)(param_2 + 4) || (*(char *)(param_2 + 0x14) == '\0')))) {
          return 0;
        }
        break;
      }
      pcVar3 = (char *)*puVar5;
      if (*pcVar3 != '\a') {
        return 0;
      }
      if (*(int *)(pcVar3 + 0x24) != param_3) {
        return 0;
      }
      iVar4 = FUN_007ea170(param_1,pcVar3);
      if (iVar4 == 0) {
        iVar4 = *(int *)(iVar1 + 0x18);
      }
      if ((*(int *)(pcVar3 + 0x28) == *(int *)(*(int *)(param_2 + 8) + iVar6 * 4)) &&
         (iVar4 == *local_c)) {
        if (param_4 < iVar6) {
          if (*(byte *)(puVar5 + 2) != local_8) {
            return 0;
          }
          local_10 = local_10 + 1;
          puVar5 = puVar5 + 3;
        }
        else {
          local_8 = (uint)*(byte *)(puVar5 + 2);
          local_10 = local_10 + 1;
          puVar5 = puVar5 + 3;
        }
      }
      else if (param_4 <= iVar6) {
        return 0;
      }
      local_c = local_c + 1;
      iVar6 = iVar6 + 1;
    } while (local_10 < iVar2);
  }
  *param_5 = (uint)(local_8 == 1);
  return 1;
}


// ==== FUN_007f71d0 @ 0x007f71d0 ====

void FUN_007f71d0(int *param_1)

{
  char cVar1;
  short *psVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  short *psVar9;
  int *piVar10;
  int local_10;
  int local_c;
  short *local_8;
  
  psVar2 = (short *)param_1[1];
  uVar3 = *(undefined4 *)(*param_1 + 0xc);
  iVar4 = (int)*psVar2;
  iVar5 = iVar4 + -1;
  if (-1 < iVar5) {
    psVar9 = psVar2 + iVar5 * 0x14 + 0xe;
    piVar10 = param_1 + iVar5 * 0x10 + 0xf;
    do {
      FUN_007dc1e0(uVar3,piVar10[-3]);
      if (piVar10[-2] != 0x17) {
        FUN_007dc140(uVar3,piVar10[-2],piVar10[-1],*piVar10);
      }
      FUN_007dc1e0(uVar3,piVar10[-4]);
      if (piVar10[3] != 0x17) {
        FUN_007dc140(uVar3,piVar10[3],piVar10[4],piVar10[5]);
      }
      if (piVar10[1] != 0) {
        iVar5 = FUN_007dc140(uVar3,1,piVar10[1],0);
        FUN_007dc140(uVar3,0x45,1,(-1 < piVar10[-6]) + 4 + iVar5);
        FUN_007dc140(uVar3,0x7c,*(undefined4 *)psVar9,0);
        if (-1 < piVar10[-6]) {
          FUN_007dc140(uVar3,0x7c,piVar10[-6],0);
        }
        FUN_007dc140(uVar3,0x61,0,piVar10[2]);
      }
      piVar10 = piVar10 + -0x10;
      psVar9 = psVar9 + -0x14;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  FUN_007dc1e0(uVar3,param_1[4]);
  local_c = 0;
  if (0 < *psVar2) {
    local_8 = psVar2 + 0xe;
    piVar10 = param_1 + 7;
    do {
      if ((*(char *)(*(int *)(local_8 + -6) + 0x1e) == '\0') &&
         (*(int *)(*(int *)(local_8 + -6) + 0x18) == 0)) {
        if ((*(byte *)(piVar10 + 3) & 1) == 0) {
          FUN_007dc140(uVar3,0x1e,*(undefined4 *)local_8,0);
        }
        if (*piVar10 != 0) {
          FUN_007dc140(uVar3,0x1e,piVar10[2],0);
        }
        if ((*(byte *)(piVar10 + 3) & 1) != 0) {
          iVar4 = *piVar10;
          pcVar6 = (char *)FUN_007dc5b0(uVar3,param_1[2]);
          local_10 = FUN_007dc320(uVar3);
          if (param_1[2] < local_10) {
            local_10 = local_10 - param_1[2];
            do {
              if (*(int *)(pcVar6 + 4) == piVar10[1]) {
                cVar1 = *pcVar6;
                if (cVar1 == '\x02') {
                  *(int *)(pcVar6 + 4) = piVar10[2];
                  iVar5 = *(int *)(iVar4 + 4);
                  iVar7 = 0;
                  if (0 < iVar5) {
                    piVar8 = *(int **)(iVar4 + 8);
                    do {
                      if (*(int *)(pcVar6 + 8) == *piVar8) {
                        *(int *)(pcVar6 + 8) = iVar7;
                        break;
                      }
                      iVar7 = iVar7 + 1;
                      piVar8 = piVar8 + 1;
                    } while (iVar7 < iVar5);
                  }
                }
                else if (cVar1 == '&') {
                  *(int *)(pcVar6 + 4) = piVar10[2];
                  *pcVar6 = '7';
                }
                else if (cVar1 == '|') {
                  *pcVar6 = '\x17';
                }
              }
              pcVar6 = pcVar6 + 0x14;
              local_10 = local_10 + -1;
            } while (local_10 != 0);
          }
        }
      }
      local_c = local_c + 1;
      local_8 = local_8 + 0x14;
      piVar10 = piVar10 + 0x10;
    } while (local_c < *psVar2);
  }
  FUN_007d05b0();
  return;
}


// ==== FUN_007f7410 @ 0x007f7410 ====

uint FUN_007f7410(int *param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  if (*param_2 != '\a') {
    uVar2 = FUN_007f7410(param_1,*(undefined4 *)(param_2 + 0xc));
    uVar3 = FUN_007f7410(param_1,*(undefined4 *)(param_2 + 8));
    uVar4 = FUN_007f7070(param_1);
    iVar1 = *(int *)(param_2 + 0x34);
    uVar4 = uVar2 | uVar3 | uVar4;
    if (iVar1 != 0) {
      uVar2 = FUN_007f7070(param_1);
      uVar3 = FUN_007f7070(param_1);
      uVar5 = FUN_007f7070(param_1);
      uVar6 = FUN_007f7410(param_1,*(undefined4 *)(iVar1 + 0xc));
      uVar7 = FUN_007f7410(param_1,*(undefined4 *)(iVar1 + 0x14));
      uVar4 = uVar4 | uVar2 | uVar3 | uVar5 | uVar6 | uVar7;
    }
    return uVar4;
  }
  iVar1 = *param_1;
  iVar8 = 0;
  if (0 < iVar1) {
    do {
      param_1 = param_1 + 1;
      if (*param_1 == *(int *)(param_2 + 0x24)) {
        return 1 << ((byte)iVar8 & 0x1f);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar1);
  }
  return 0;
}


// ==== FUN_007f74d0 @ 0x007f74d0 ====

void FUN_007f74d0(short *param_1)

{
  byte bVar1;
  undefined2 uVar2;
  byte *pbVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined4 *unaff_ESI;
  
  pbVar3 = (byte *)*unaff_ESI;
  uVar5 = FUN_007f7410();
  unaff_ESI[3] = uVar5;
  uVar5 = FUN_007f7410();
  unaff_ESI[4] = uVar5;
  uVar5 = FUN_007f7410();
  iVar9 = -1;
  unaff_ESI[5] = uVar5;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  *(undefined2 *)((int)unaff_ESI + 6) = 0xffff;
  *(undefined2 *)(unaff_ESI + 2) = 0xffff;
  bVar1 = *pbVar3;
  if (((bVar1 == 0x43) || ((0x46 < bVar1 && (bVar1 < 0x4c)))) &&
     ((unaff_ESI[3] & unaff_ESI[4]) == 0)) {
    pcVar4 = *(char **)(pbVar3 + 0xc);
    if ((pcVar4 != (char *)0x0) && (*pcVar4 == '\a')) {
      *(undefined2 *)(unaff_ESI + 2) = *(undefined2 *)(pcVar4 + 0x24);
      *(undefined1 *)(unaff_ESI + 1) = 1;
    }
    if (**(char **)(pbVar3 + 8) == '\a') {
      *(undefined2 *)((int)unaff_ESI + 6) = *(undefined2 *)(*(char **)(pbVar3 + 8) + 0x24);
      *(undefined1 *)(unaff_ESI + 1) = 1;
    }
  }
  if (*(char *)(unaff_ESI + 1) != '\0') {
    iVar7 = (int)*param_1;
    iVar6 = 0;
    if (0 < iVar7) {
      piVar8 = (int *)(param_1 + 0xe);
      do {
        if (*piVar8 == (int)*(short *)((int)unaff_ESI + 6)) {
          iVar9 = iVar6;
          break;
        }
        iVar6 = iVar6 + 1;
        piVar8 = piVar8 + 10;
      } while (iVar6 < iVar7);
    }
    iVar6 = 0;
    if (0 < iVar7) {
      piVar8 = (int *)(param_1 + 0xe);
      do {
        if (*piVar8 == (int)*(short *)(unaff_ESI + 2)) goto LAB_007f75a2;
        iVar6 = iVar6 + 1;
        piVar8 = piVar8 + 10;
      } while (iVar6 < iVar7);
    }
    iVar6 = -1;
LAB_007f75a2:
    if (iVar9 < iVar6) {
      uVar5 = *(undefined4 *)(*(int *)(pbVar3 + 0xc) + 4);
      *(undefined4 *)(*(int *)(pbVar3 + 0xc) + 4) = *(undefined4 *)(*(int *)(pbVar3 + 8) + 4);
      *(undefined4 *)(*(int *)(pbVar3 + 8) + 4) = uVar5;
      uVar5 = *(undefined4 *)(pbVar3 + 8);
      *(undefined4 *)(pbVar3 + 8) = *(undefined4 *)(pbVar3 + 0xc);
      *(undefined4 *)(pbVar3 + 0xc) = uVar5;
      if (0x47 < *pbVar3) {
        *pbVar3 = (*pbVar3 + 0xb8 ^ 2) + 0x48;
      }
      uVar5 = unaff_ESI[4];
      unaff_ESI[4] = unaff_ESI[3];
      uVar2 = *(undefined2 *)((int)unaff_ESI + 6);
      unaff_ESI[3] = uVar5;
      *(undefined2 *)((int)unaff_ESI + 6) = *(undefined2 *)(unaff_ESI + 2);
      *(undefined2 *)(unaff_ESI + 2) = uVar2;
    }
  }
  return;
}


// ==== FUN_007f7600 @ 0x007f7600 ====

undefined4 * FUN_007f7600(int *param_1,uint *param_2,char *param_3,int *param_4)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  byte bVar16;
  char cVar17;
  int iVar18;
  uint *puVar19;
  int iVar20;
  uint uVar21;
  int *piVar22;
  char **ppcVar23;
  int iVar24;
  bool bVar25;
  bool bVar26;
  uint uVar27;
  char **local_bf0;
  uint local_bec;
  uint *local_be8;
  uint *local_be4;
  int local_bdc;
  uint local_bd8;
  int local_bd4;
  int local_bd0;
  int local_bcc;
  uint local_bc8;
  uint local_bc0;
  uint *local_bbc;
  uint local_bb8;
  uint local_bb4;
  uint local_bb0;
  uint local_bac;
  uint *local_ba8;
  int local_ba4;
  int local_ba0;
  uint local_b98;
  int local_b94;
  undefined4 *local_b90;
  int local_b8c;
  uint local_b88 [34];
  int local_b00 [32];
  int local_a80 [32];
  int local_a00 [32];
  char *local_980 [4];
  uint local_970 [2];
  undefined1 local_968 [2404];
  
  local_b94 = param_1[3];
  local_bb0 = 0;
  if (0x20 < (ushort)*param_2) {
    FUN_007d0820(param_1,s_at_most__d_tables_in_a_join_00a054b8,0x20);
    return (undefined4 *)0x0;
  }
  puVar19 = local_b88;
  for (iVar18 = 0x21; iVar18 != 0; iVar18 = iVar18 + -1) {
    *puVar19 = 0;
    puVar19 = puVar19 + 1;
  }
  ppcVar23 = local_980;
  for (iVar18 = 0x25e; iVar18 != 0; iVar18 = iVar18 + -1) {
    *ppcVar23 = (char *)0x0;
    ppcVar23 = ppcVar23 + 1;
  }
  if (param_3 == (char *)0x0) {
    local_bdc = 0;
  }
  else if (*param_3 == '?') {
    pcVar3 = *(char **)(param_3 + 8);
    if (*pcVar3 == '?') {
      local_bdc = FUN_007f6fe0(0x65,local_980,pcVar3);
      iVar18 = FUN_007f6fe0(0x65 - local_bdc,local_980 + local_bdc * 6,
                            *(undefined4 *)(param_3 + 0xc));
      local_bdc = local_bdc + iVar18;
    }
    else {
      local_980[0] = pcVar3;
      local_bdc = FUN_007f6fe0(100,local_968,*(undefined4 *)(param_3 + 0xc));
      local_bdc = local_bdc + 1;
    }
    if (local_bdc == 0x65) {
      FUN_007d0820(param_1,s_WHERE_clause_too_complex___no_mo_00a0547c,100);
      return (undefined4 *)0x0;
    }
  }
  else {
    local_980[0] = param_3;
    local_bdc = 1;
  }
  puVar5 = (undefined4 *)FUN_007d0550((short)(ushort)*param_2 * 0x40 + 0x58);
  local_b90 = puVar5;
  if (DAT_00b5c4c4 != 0) {
    FUN_007d05b0(puVar5);
    return (undefined4 *)0x0;
  }
  *puVar5 = param_1;
  puVar5[1] = param_2;
  uVar6 = FUN_007dc190(local_b94);
  puVar5[4] = uVar6;
  if ((param_3 != (char *)0x0) &&
     (((ushort)*param_2 == 0 || (iVar18 = FUN_007eaee0(param_3), iVar18 != 0)))) {
    FUN_007eca30(param_1,param_3,puVar5[4],1);
  }
  iVar18 = (int)(short)(ushort)*param_2;
  uVar21 = local_b88[0];
  if (0 < iVar18) {
    puVar19 = param_2 + 7;
    do {
      if (uVar21 < 0x20) {
        local_b88[uVar21 + 1] = *puVar19;
        uVar21 = local_b88[0] + 1;
        local_b88[0] = uVar21;
      }
      puVar19 = puVar19 + 10;
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
  }
  iVar18 = local_bdc;
  if (0 < local_bdc) {
    do {
      FUN_007f74d0(param_2);
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
    uVar21 = local_b88[0];
  }
  puVar5 = local_b90;
  puVar19 = local_b90 + 6;
  local_ba8 = param_2 + 1;
  local_bc8 = 0;
  local_bd8 = 0;
  if (0 < (short)(ushort)*param_2) {
    local_bf0 = (char **)(local_b90 + 7);
    puVar8 = param_2;
    while (local_be8 = puVar8 + 10, local_bd8 < 0x1f) {
      uVar9 = puVar8[7];
      iVar18 = 0;
      iVar20 = 0;
      if (0 < (int)uVar21) {
        do {
          if (local_b88[iVar20 + 1] == uVar9) {
            uVar21 = 1 << ((byte)iVar20 & 0x1f);
            goto LAB_007f783d;
          }
          iVar20 = iVar20 + 1;
        } while (iVar20 < (int)uVar21);
      }
      uVar21 = 0;
LAB_007f783d:
      local_b98 = puVar8[4];
      local_ba0 = 0;
      local_bd4 = 0;
      local_bb4 = 0;
      local_bf0[2] = (char *)0xffffffff;
      local_a00[local_bd8] = -1;
      local_b00[local_bd8] = -1;
      local_a80[local_bd8] = -1;
      if (0 < local_bdc) {
        local_be4 = local_970;
        do {
          if ((((int)*(short *)((int)local_be4 + -10) == uVar9) &&
              (*(int *)(*(int *)((undefined1 *)local_be4[-4] + 8) + 0x28) < 0)) &&
             ((*local_be4 & local_bc8) == *local_be4)) {
            switch(*(undefined1 *)local_be4[-4]) {
            case 0x43:
            case 0x47:
              local_a00[local_bd8] = iVar18;
              break;
            case 0x48:
            case 0x4b:
              local_a80[local_bd8] = iVar18;
              break;
            case 0x49:
            case 0x4a:
              local_b00[local_bd8] = iVar18;
            }
          }
          iVar18 = iVar18 + 1;
          local_be4 = local_be4 + 6;
        } while (iVar18 < local_bdc);
      }
      if (local_a00[local_bd8] < 0) {
        for (iVar18 = *(int *)(local_b98 + 0x10); iVar18 != 0; iVar18 = *(int *)(iVar18 + 0x1c)) {
          local_bac = 0;
          local_bc0 = 0;
          local_bb8 = 0;
          bVar25 = false;
          local_b98 = 0;
          if (*(uint *)(iVar18 + 4) < 0x21) {
            if (0 < local_bdc) {
              local_bbc = local_970;
              local_ba4 = local_bdc;
              do {
                puVar1 = (undefined1 *)local_bbc[-4];
                iVar20 = FUN_007ea170(param_1,*(undefined4 *)(puVar1 + 8));
                if ((iVar20 == 0) &&
                   ((*(int *)(puVar1 + 0xc) == 0 ||
                    (iVar20 = FUN_007ea170(param_1,*(int *)(puVar1 + 0xc)), iVar20 == 0)))) {
                  iVar20 = *(int *)(*param_1 + 0x18);
                }
                if (((int)*(short *)((int)local_bbc + -10) == uVar9) &&
                   ((*local_bbc & local_bc8) == *local_bbc)) {
                  iVar12 = *(int *)(*(int *)(puVar1 + 8) + 0x28);
                  if (iVar12 < 0) {
                    local_b8c = (uint)local_b8c._1_3_ << 8;
                  }
                  else {
                    local_b8c = CONCAT31(local_b8c._1_3_,
                                         *(undefined1 *)
                                          (*(int *)(*(int *)(iVar18 + 0xc) + 8) + 0x12 +
                                          iVar12 * 0x14));
                  }
                  iVar24 = 0;
                  if (0 < *(int *)(iVar18 + 4)) {
                    piVar22 = (int *)(iVar18 + 0x2c);
                    do {
                      if (((iVar20 == *piVar22) &&
                          (iVar7 = FUN_007ea2a0(puVar1,local_b8c), iVar7 != 0)) &&
                         (*(int *)(*(int *)(iVar18 + 8) + iVar24 * 4) == iVar12)) {
                        bVar16 = (byte)iVar24;
                        switch(*puVar1) {
                        case 0x43:
                          if (iVar24 == 0) {
                            bVar25 = true;
                          }
                          break;
                        case 0x47:
                          local_bac = local_bac | 1 << (bVar16 & 0x1f);
                          break;
                        case 0x48:
                        case 0x4b:
                          local_bb8 = local_bb8 | 1 << (bVar16 & 0x1f);
                          break;
                        case 0x49:
                        case 0x4a:
                          local_bc0 = local_bc0 | 1 << (bVar16 & 0x1f);
                        }
                        break;
                      }
                      iVar24 = iVar24 + 1;
                      piVar22 = piVar22 + 1;
                    } while (iVar24 < *(int *)(iVar18 + 4));
                  }
                }
                local_bbc = local_bbc + 6;
                local_ba4 = local_ba4 + -1;
              } while (local_ba4 != 0);
            }
            iVar20 = 0;
            if (0 < *(int *)(iVar18 + 4)) {
              do {
                iVar12 = iVar20 + 1;
                uVar14 = (1 << ((byte)iVar12 & 0x1f)) - 1;
                if ((uVar14 & local_bac) != uVar14) break;
                iVar20 = iVar12;
              } while (iVar12 < *(int *)(iVar18 + 4));
            }
            uVar14 = 1 << ((byte)iVar20 & 0x1f);
            iVar12 = iVar20 * 0x20;
            if ((local_bc0 & uVar14) != 0) {
              iVar12 = iVar12 + 4;
            }
            if ((local_bb8 & uVar14) != 0) {
              iVar12 = iVar12 + 8;
            }
            if ((iVar12 == 0) && (bVar25)) {
              iVar12 = 0x10;
            }
            if (((local_bd8 == 0) && (iVar12 != 0x10)) &&
               ((param_4 != (int *)0x0 &&
                ((*param_4 != 0 &&
                 (iVar20 = FUN_007f70c0(param_1,iVar18,param_2[7],iVar20,&local_b98), iVar20 != 0)))
                ))) {
              iVar12 = iVar12 + 2;
            }
            if ((iVar12 != 0) && (*local_be8 < 0x40000000)) {
              local_ba4 = *(int *)(iVar18 + 4);
              uVar14 = 0;
              if (0 < local_ba4) {
                puVar8 = *(uint **)(iVar18 + 8);
                do {
                  if (*puVar8 < 0x1e) {
                    uVar14 = uVar14 | 1 << ((byte)*puVar8 & 0x1f);
                  }
                  puVar8 = puVar8 + 1;
                  local_ba4 = local_ba4 + -1;
                } while (local_ba4 != 0);
              }
              if ((*local_be8 & uVar14) == *local_be8) {
                iVar12 = iVar12 + 1;
              }
            }
            if (local_bd4 < iVar12) {
              local_bb4 = local_b98;
              local_bd4 = iVar12;
              local_ba0 = iVar18;
            }
          }
        }
        local_bf0[3] = (char *)local_bd4;
        local_bf0[0xe] = (char *)local_bb4;
        *local_bf0 = (char *)local_ba0;
        if (local_ba0 != 0) {
          local_bf0[2] = (char *)param_1[7];
          param_1[7] = param_1[7] + 1;
        }
      }
      else {
        *local_bf0 = (char *)0x0;
      }
      local_bc8 = local_bc8 | uVar21;
      local_bf0 = local_bf0 + 0x10;
      local_bd8 = local_bd8 + 1;
      if ((int)(short)(ushort)*param_2 <= (int)local_bd8) break;
      uVar21 = local_b88[0];
      puVar8 = local_be8;
    }
  }
  if (((param_4 != (int *)0x0) && (*param_4 != 0)) && (0 < (short)(ushort)*param_2)) {
    if (puVar5[7] == 0) {
      puVar2 = *(undefined4 **)(*param_4 + 8);
      pcVar3 = (char *)*puVar2;
      if (((*pcVar3 == '\a') && (*(uint *)(pcVar3 + 0x24) == param_2[7])) &&
         (*(int *)(pcVar3 + 0x28) == -1)) {
        bVar16 = *(byte *)(puVar2 + 2);
        *param_4 = 0;
        puVar5[0x15] = (uint)bVar16;
        goto LAB_007f7cd7;
      }
    }
    if (((puVar5[10] != 0x10) && (local_a00[0] < 0)) &&
       ((local_b00[0] < 0 && ((local_a80[0] < 0 && ((puVar5[10] & 2) != 0)))))) {
      *param_4 = 0;
    }
  }
LAB_007f7cd7:
  FUN_007d3cc0(param_1,0xffffffff);
  iVar18 = local_b94;
  local_bd8 = 0;
  if (0 < (short)(ushort)*param_2) {
    puVar8 = puVar5 + 8;
    local_be4 = param_2 + 7;
    do {
      uVar21 = puVar8[1];
      uVar9 = local_be4[-3];
      if ((*(char *)(uVar9 + 0x1e) == '\0') && (*(int *)(uVar9 + 0x18) == 0)) {
        if ((puVar8[2] & 1) == 0) {
          FUN_007ecd00(iVar18,*local_be4,uVar9);
        }
        uVar14 = puVar8[-1];
        *puVar8 = *local_be4;
        if (uVar14 != 0) {
          FUN_007dc140(iVar18,0x32,*(undefined1 *)(uVar14 + 0x16),0);
          FUN_007dda80(iVar18,0xe,uVar21,*(undefined4 *)(uVar14 + 0x10),uVar14 + 0x20,0xfffffffa);
        }
        if ((puVar8[2] & 1) != 0) {
          FUN_007dc140(iVar18,0x67,uVar21,*(int *)(uVar14 + 4) + 1);
        }
        FUN_007d3cc0(param_1,*(undefined1 *)(uVar9 + 0x1d));
      }
      local_bd8 = local_bd8 + 1;
      local_be4 = local_be4 + 10;
      puVar8 = puVar8 + 0x10;
    } while ((int)local_bd8 < (int)(short)(ushort)*param_2);
  }
  uVar6 = FUN_007dc320(iVar18);
  local_b90[2] = uVar6;
  local_bc8 = 0;
  local_bd8 = 0;
  if (0 < (short)(ushort)*param_2) {
    do {
      uVar21 = local_ba8[6];
      uVar9 = puVar19[3];
      uVar14 = puVar19[4];
      uVar10 = puVar19[1];
      puVar19[0xc] = 0x17;
      if ((0 < (int)local_bd8) && ((param_2[local_bd8 * 10 + -4] & 4) != 0)) {
        if (param_1[8] == 0) {
          param_1[8] = 1;
        }
        puVar19[10] = param_1[8];
        param_1[8] = param_1[8] + 1;
        FUN_007dc140(iVar18,0x76,0,0);
        FUN_007dc140(iVar18,0x78,puVar19[10],1);
      }
      if ((local_bd8 < 0x1f) && (-1 < local_a00[local_bd8])) {
        ppcVar23 = local_980 + local_a00[local_bd8] * 6;
        uVar9 = FUN_007dc190(iVar18);
        puVar19[5] = uVar9;
        pcVar3 = *ppcVar23;
        if (*pcVar3 == 'C') {
          iVar20 = param_1[3];
          FUN_007ebcc0(param_1,pcVar3);
          uVar14 = *(uint *)(pcVar3 + 0x24);
          FUN_007dc140(iVar20,0x79,uVar14,uVar9);
          uVar10 = FUN_007dc140(iVar20,2,uVar14,0);
          puVar19[0xd] = uVar14;
          puVar19[0xe] = uVar10;
          puVar19[0xc] = 0x6c;
        }
        else {
          FUN_007ec010(param_1,*(undefined4 *)(pcVar3 + 0xc));
        }
        if ((puVar19[10] == 0) || (((*ppcVar23)[3] & 1U) != 0)) {
          *ppcVar23 = (char *)0x0;
        }
        local_bb0 = FUN_007dc190(iVar18);
        puVar19[6] = local_bb0;
        FUN_007dc140(iVar18,0x24,1,uVar9);
        FUN_007dc140(iVar18,0x2d,uVar21,uVar9);
        puVar19[7] = 0x17;
      }
      else {
        if (((uVar10 == 0) || (uVar11 = puVar19[4], (int)uVar11 < 4)) || ((uVar11 & 0xc) != 0)) {
          if ((local_bd8 < 0x1f) && ((-1 < local_b00[local_bd8] || (-1 < local_a80[local_bd8])))) {
            uVar9 = puVar19[0xf];
            cVar17 = '\x17';
            uVar14 = FUN_007dc190(iVar18);
            puVar19[5] = uVar14;
            local_bb0 = FUN_007dc190(iVar18);
            puVar19[6] = local_bb0;
            if (uVar9 != 0) {
              iVar20 = local_a80[local_bd8];
              local_a80[local_bd8] = local_b00[local_bd8];
              local_b00[local_bd8] = iVar20;
            }
            if (local_a80[local_bd8] < 0) {
              FUN_007dc140(iVar18,(-(uint)(uVar9 != 0) & 0xffffffbd) + 0x79,uVar21,uVar14);
            }
            else {
              ppcVar23 = local_980 + local_a80[local_bd8] * 6;
              pcVar3 = *ppcVar23;
              FUN_007ec010(param_1,*(undefined4 *)(pcVar3 + 0xc));
              cVar4 = *pcVar3;
              if ((cVar4 == 'I') || (cVar4 == 'H')) {
                uVar6 = 1;
              }
              else {
                uVar6 = 0;
              }
              FUN_007dc140(iVar18,0x74,uVar6,uVar14);
              FUN_007dc140(iVar18,(-(uint)(uVar9 != 0) & 0xffffffea) + 0x7a,uVar21,uVar14);
              if ((puVar19[10] == 0) || (((*ppcVar23)[3] & 1U) != 0)) {
                *ppcVar23 = (char *)0x0;
              }
            }
            if (-1 < local_b00[local_bd8]) {
              ppcVar23 = local_980 + local_b00[local_bd8] * 6;
              pcVar3 = *ppcVar23;
              FUN_007ec010(param_1,*(undefined4 *)(pcVar3 + 0xc));
              *puVar19 = param_1[8];
              param_1[8] = param_1[8] + 1;
              FUN_007dc140(iVar18,0x78,*puVar19,1);
              cVar17 = *pcVar3;
              if ((cVar17 == 'J') || (cVar17 == 'H')) {
                cVar17 = (uVar9 == 0) * '\x02' + 'I';
              }
              else {
                cVar17 = (uVar9 != 0) * '\x02' + 'H';
              }
              if ((puVar19[10] == 0) || (((*ppcVar23)[3] & 1U) != 0)) {
                *ppcVar23 = (char *)0x0;
              }
            }
            uVar10 = FUN_007dc320(iVar18);
            puVar19[9] = uVar10;
            puVar19[7] = (-(uint)(uVar9 != 0) & 0xffffffc8) + 0x6c;
            puVar19[8] = uVar21;
            if (cVar17 != '\x17') {
              FUN_007dc140(iVar18,0x26,uVar21,0);
              FUN_007dc140(iVar18,1,*puVar19,0);
              FUN_007dc140(iVar18,cVar17,0x6e,uVar14);
            }
            goto LAB_007f8a4d;
          }
          if (uVar10 == 0) {
            uVar9 = FUN_007dc190(iVar18);
            puVar19[5] = uVar9;
            local_bb0 = FUN_007dc190(iVar18);
            puVar19[6] = local_bb0;
            if (puVar19[0xf] == 0) {
              uVar6 = 0x79;
              puVar19[7] = 0x6c;
            }
            else {
              uVar6 = 0x36;
              puVar19[7] = 0x34;
            }
            FUN_007dc140(iVar18,uVar6,uVar21,uVar9);
            uVar9 = FUN_007dc320(iVar18);
            puVar19[9] = uVar9;
            uVar9 = uVar21;
            goto LAB_007f8a4a;
          }
          uVar11 = puVar19[4];
          iVar20 = (int)(uVar11 + ((int)uVar11 >> 0x1f & 0x1fU)) >> 5;
          bVar25 = false;
          bVar26 = false;
          local_bd0 = 0;
          if (0 < iVar20) {
            do {
              ppcVar23 = local_980;
              local_bcc = 0;
              if (0 < local_bdc) {
                do {
                  pcVar3 = *ppcVar23;
                  if ((((pcVar3 != (char *)0x0) && ((int)*(short *)((int)ppcVar23 + 6) == uVar21))
                      && (*pcVar3 == 'G')) &&
                     (((char *)((uint)ppcVar23[4] & local_bc8) == ppcVar23[4] &&
                      (*(int *)(*(int *)(pcVar3 + 8) + 0x28) ==
                       *(int *)(*(int *)(uVar10 + 8) + local_bd0 * 4))))) {
                    FUN_007ec010(param_1,*(undefined4 *)(pcVar3 + 0xc));
                    if ((puVar19[10] == 0) || (((*ppcVar23)[3] & 1U) != 0)) {
                      *ppcVar23 = (char *)0x0;
                    }
                    break;
                  }
                  local_bcc = local_bcc + 1;
                  ppcVar23 = ppcVar23 + 6;
                } while (local_bcc < local_bdc);
              }
              local_bd0 = local_bd0 + 1;
            } while (local_bd0 < iVar20);
          }
          local_bd0 = 0;
          if (0 < iVar20) {
            iVar12 = iVar20;
            do {
              FUN_007dc140(iVar18,0x60,iVar20 + -1,0);
              iVar12 = iVar12 + -1;
              local_bd0 = iVar20;
            } while (iVar12 != 0);
          }
          local_bb0 = FUN_007dc190(iVar18);
          puVar19[6] = local_bb0;
          uVar15 = FUN_007dc190(iVar18);
          puVar19[5] = uVar15;
          uVar27 = uVar9;
          uVar13 = uVar15;
          if ((uVar11 & 4) == 0) {
            bVar25 = true;
            cVar17 = ((iVar20 < 1) - 1U & 0x26) + 0x17;
            if (cVar17 != '\x17') goto LAB_007f8711;
            if (puVar19[0xf] != 0) {
              iVar12 = 0x36;
              goto LAB_007f87b7;
            }
          }
          else {
            local_bf0 = local_980;
            local_bcc = 0;
            if (local_bdc < 1) {
LAB_007f86e0:
              cVar17 = '=';
            }
            else {
              do {
                pcVar3 = *local_bf0;
                if ((((pcVar3 != (char *)0x0) && ((int)*(short *)((int)local_bf0 + 6) == uVar21)) &&
                    ((*pcVar3 == 'J' || (*pcVar3 == 'I')))) &&
                   (((char *)((uint)local_bf0[4] & local_bc8) == local_bf0[4] &&
                    (*(int *)(*(int *)(pcVar3 + 8) + 0x28) ==
                     *(int *)(*(int *)(uVar10 + 8) + local_bd0 * 4))))) {
                  FUN_007ec010(param_1,*(undefined4 *)(pcVar3 + 0xc));
                  bVar25 = *pcVar3 == 'I';
                  if ((puVar19[10] == 0) || (((*local_bf0)[3] & 1U) != 0)) {
                    *local_bf0 = (char *)0x0;
                  }
                  goto LAB_007f86e0;
                }
                local_bcc = local_bcc + 1;
                local_bf0 = local_bf0 + 6;
              } while (local_bcc < local_bdc);
              cVar17 = '=';
            }
LAB_007f8711:
            *puVar19 = param_1[8];
            iVar24 = (uVar11 >> 2 & 1) + iVar20;
            param_1[8] = param_1[8] + 1;
            iVar12 = FUN_007dc320(iVar18);
            FUN_007dc140(iVar18,0x45,-iVar24,iVar12 + 3);
            FUN_007dc140(iVar18,0xb,iVar24,0);
            FUN_007dc140(iVar18,0x61,0,uVar15);
            FUN_007dc140(iVar18,0x5b,iVar24,0);
            FUN_007f97c0(iVar18,uVar10);
            if (puVar19[0xf] == 0) {
              iVar12 = 0x78;
              uVar27 = *puVar19;
              uVar13 = 1;
            }
            else {
              iVar12 = (-(uint)bVar25 & 0xffffffdf) + 100;
            }
LAB_007f87b7:
            FUN_007dc140(iVar18,iVar12,uVar27,uVar13);
          }
          if ((uVar11 & 8) == 0) {
            bVar26 = true;
          }
          else {
            local_bf0 = local_980;
            local_bcc = 0;
            if (0 < local_bdc) {
              do {
                pcVar3 = *local_bf0;
                if ((((pcVar3 != (char *)0x0) && ((int)*(short *)((int)local_bf0 + 6) == uVar21)) &&
                    ((*pcVar3 == 'H' || (*pcVar3 == 'K')))) &&
                   (((char *)((uint)local_bf0[4] & local_bc8) == local_bf0[4] &&
                    (*(int *)(*(int *)(pcVar3 + 8) + 0x28) ==
                     *(int *)(*(int *)(uVar10 + 8) + local_bd0 * 4))))) {
                  FUN_007ec010(param_1,*(undefined4 *)(pcVar3 + 0xc));
                  bVar26 = *pcVar3 == 'K';
                  if ((puVar19[10] == 0) || (((*local_bf0)[3] & 1U) != 0)) {
                    *local_bf0 = (char *)0x0;
                  }
                  break;
                }
                local_bcc = local_bcc + 1;
                local_bf0 = local_bf0 + 6;
              } while (local_bcc < local_bdc);
            }
          }
          if ((iVar20 < 1) && ((uVar11 & 8) == 0)) {
            if (puVar19[0xf] == 0) {
              cVar4 = 'y';
              goto LAB_007f8968;
            }
            cVar17 = '\x17';
          }
          else {
            iVar24 = (uVar11 >> 3 & 1) + iVar20;
            iVar12 = FUN_007dc320(iVar18);
            FUN_007dc140(iVar18,0x45,-iVar24,iVar12 + 3);
            FUN_007dc140(iVar18,0xb,iVar24,0);
            FUN_007dc140(iVar18,0x61,0,uVar15);
            FUN_007dc140(iVar18,0x5b,iVar24,0);
            FUN_007f97c0(iVar18,uVar10);
            if (puVar19[0xf] == 0) {
              cVar4 = (-bVar26 & 0x75U) + 5;
LAB_007f8968:
              FUN_007dc140(iVar18,cVar4,uVar9,uVar15);
            }
            else {
              *puVar19 = param_1[8];
              param_1[8] = param_1[8] + 1;
              FUN_007dc140(iVar18,0x78,*puVar19,1);
              cVar17 = '\'';
            }
          }
          uVar10 = FUN_007dc320(iVar18);
          if (cVar17 != '\x17') {
            FUN_007dc140(iVar18,1,*puVar19,0);
            FUN_007dc140(iVar18,cVar17,uVar9,uVar15);
            if (((bVar25) && (puVar19[0xf] == 0)) || ((!bVar26 && (puVar19[0xf] != 0)))) {
              FUN_007dc430(iVar18,0xffffffff,&DAT_00a05478,0xfffffffe);
            }
          }
          FUN_007dc140(iVar18,7,uVar9,0);
          FUN_007dc140(iVar18,0x22,(uVar11 >> 2 & 1) + iVar20,local_bb0);
          if ((uVar14 & 1) == 0) {
            FUN_007dc140(iVar18,0x37,uVar9,0);
            FUN_007dc140(iVar18,0x7a,uVar21,0);
          }
          puVar19[7] = (-(uint)(puVar19[0xf] != 0) & 0xffffffc8) + 0x6c;
          puVar19[9] = uVar10;
        }
        else {
          iVar20 = (int)(uVar11 + 0x10 + ((int)(uVar11 + 0x10) >> 0x1f & 0x1fU)) >> 5;
          uVar11 = FUN_007dc190(iVar18);
          puVar19[5] = uVar11;
          local_bd0 = 0;
          if (0 < iVar20) {
            do {
              local_bf0 = local_980;
              local_bcc = 0;
              if (0 < local_bdc) {
                do {
                  pcVar3 = *local_bf0;
                  if (((((pcVar3 != (char *)0x0) && ((int)*(short *)((int)local_bf0 + 6) == uVar21))
                       && ((char *)((uint)local_bf0[4] & local_bc8) == local_bf0[4])) &&
                      ((*(int *)(*(int *)(pcVar3 + 8) + 0x28) ==
                        *(int *)(*(int *)(uVar10 + 8) + local_bd0 * 4) &&
                       ((*pcVar3 == 'G' || (*pcVar3 == 'C')))))) &&
                     (iVar12 = FUN_007ea2a0(pcVar3,*(undefined1 *)
                                                    (*(int *)(*(int *)(uVar10 + 0xc) + 8) + 0x12 +
                                                    *(int *)(*(int *)(pcVar3 + 8) + 0x28) * 0x14)),
                     iVar12 != 0)) {
                    pcVar3 = *local_bf0;
                    if (*pcVar3 == 'C') {
                      iVar18 = param_1[3];
                      FUN_007ebcc0(param_1,pcVar3);
                      uVar27 = *(uint *)(pcVar3 + 0x24);
                      FUN_007dc140(iVar18,0x79,uVar27,uVar11);
                      uVar13 = FUN_007dc140(iVar18,2,uVar27,0);
                      puVar19[0xe] = uVar13;
                      puVar19[0xc] = 0x6c;
                      puVar19[0xd] = uVar27;
                      iVar18 = local_b94;
                    }
                    else {
                      FUN_007ec010(param_1,*(undefined4 *)(pcVar3 + 0xc));
                    }
                    if ((puVar19[10] == 0) || (((*local_bf0)[3] & 1U) != 0)) {
                      *local_bf0 = (char *)0x0;
                    }
                    break;
                  }
                  local_bcc = local_bcc + 1;
                  local_bf0 = local_bf0 + 6;
                } while (local_bcc < local_bdc);
              }
              local_bd0 = local_bd0 + 1;
            } while (local_bd0 < iVar20);
          }
          *puVar19 = param_1[8];
          param_1[8] = param_1[8] + 1;
          local_bb0 = FUN_007dc190(iVar18);
          puVar19[6] = local_bb0;
          iVar12 = FUN_007dc320(iVar18);
          FUN_007dc140(iVar18,0x45,-iVar20,iVar12 + 3);
          FUN_007dc140(iVar18,0xb,iVar20,0);
          FUN_007dc140(iVar18,0x61,0,uVar11);
          FUN_007dc140(iVar18,0x5b,iVar20,0);
          FUN_007f97c0(iVar18,uVar10);
          FUN_007dc140(iVar18,0x78,*puVar19,0);
          if (puVar19[0xf] == 0) {
            FUN_007dc140(iVar18,0x7a,uVar9,uVar11);
            local_bec = FUN_007dc140(iVar18,1,*puVar19,0);
            FUN_007dda80(iVar18,0x3d,uVar9,uVar11,&DAT_00a05478,0xfffffffe);
            puVar19[7] = 0x6c;
          }
          else {
            FUN_007dc140(iVar18,0x43,uVar9,uVar11);
            local_bec = FUN_007dc140(iVar18,1,*puVar19,0);
            FUN_007dc140(iVar18,0x27,uVar9,uVar11);
            puVar19[7] = 0x34;
          }
          FUN_007dc140(iVar18,7,uVar9,0);
          FUN_007dc140(iVar18,0x22,iVar20,local_bb0);
          if ((uVar14 & 1) == 0) {
            FUN_007dc140(iVar18,0x37,uVar9,0);
            FUN_007dc140(iVar18,0x7a,uVar21,0);
          }
          puVar19[9] = local_bec;
        }
LAB_007f8a4a:
        puVar19[8] = uVar9;
      }
LAB_007f8a4d:
      iVar20 = 0;
      if (0 < (int)local_b88[0]) {
        do {
          if (local_b88[iVar20 + 1] == uVar21) {
            uVar21 = 1 << ((byte)iVar20 & 0x1f);
            goto LAB_007f8a75;
          }
          iVar20 = iVar20 + 1;
        } while (iVar20 < (int)local_b88[0]);
      }
      uVar21 = 0;
LAB_007f8a75:
      local_bc8 = local_bc8 | uVar21;
      ppcVar23 = local_980;
      if (0 < local_bdc) {
        local_bec = local_bdc;
        do {
          pcVar3 = *ppcVar23;
          if (((pcVar3 != (char *)0x0) && ((char *)((uint)ppcVar23[5] & local_bc8) == ppcVar23[5]))
             && ((puVar19[10] == 0 || ((pcVar3[3] & 1U) != 0)))) {
            FUN_007eca30(param_1,pcVar3,local_bb0,1);
            *ppcVar23 = (char *)0x0;
          }
          ppcVar23 = ppcVar23 + 6;
          local_bec = local_bec + -1;
        } while (local_bec != 0);
      }
      if (puVar19[10] != 0) {
        uVar21 = FUN_007dc320(iVar18);
        puVar19[0xb] = uVar21;
        FUN_007dc140(iVar18,0x32,1,0);
        FUN_007dc140(iVar18,0x78,puVar19[10],1);
        ppcVar23 = local_980;
        if (0 < local_bdc) {
          local_bec = local_bdc;
          do {
            if ((*ppcVar23 != (char *)0x0) &&
               ((char *)((uint)ppcVar23[5] & local_bc8) == ppcVar23[5])) {
              FUN_007eca30(param_1,*ppcVar23,local_bb0,1);
              *ppcVar23 = (char *)0x0;
            }
            ppcVar23 = ppcVar23 + 6;
            local_bec = local_bec + -1;
          } while (local_bec != 0);
        }
      }
      local_bd8 = local_bd8 + 1;
      local_ba8 = local_ba8 + 10;
      puVar19 = puVar19 + 0x10;
    } while ((int)local_bd8 < (int)(short)(ushort)*param_2);
  }
  local_b90[3] = local_bb0;
  return local_b90;
}


// ==== FUN_007f8be0 @ 0x007f8be0 ====

void FUN_007f8be0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_4;
  
  if ((param_2 != 0) && (*(int *)(param_2 + 0x18) == 0)) {
    iVar2 = FUN_007dda70(param_1);
    iVar1 = *(int *)(param_2 + 8) + param_3 * 0x14;
    FUN_007d0150(*(undefined4 *)(iVar1 + 4),*(undefined1 *)(iVar2 + 0x10),
                 *(undefined1 *)(iVar1 + 0x12),&local_4);
    FUN_007dc430(param_1,0xffffffff,local_4,0xfffffff8);
  }
  return;
}


// ==== FUN_007f8c40 @ 0x007f8c40 ====

void FUN_007f8c40(int *param_1,int param_2,int *param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  bool bVar12;
  int local_60;
  int local_5c;
  undefined4 local_58;
  int *local_4c;
  int local_48;
  int local_40;
  int *local_38;
  undefined4 local_34;
  int *local_30;
  int *local_2c;
  undefined1 local_28 [4];
  undefined4 local_24;
  int *local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar11 = 0;
  local_40 = -1;
  local_48 = -1;
  local_58 = 0;
  local_2c = (int *)0x0;
  local_4c = (int *)0x0;
  local_5c = 0;
  local_34 = 0;
  bVar2 = false;
  local_24 = 0;
  if ((param_1[6] == 0) && (DAT_00b5c4c4 == 0)) {
    iVar1 = *param_1;
    puVar3 = (undefined4 *)FUN_007ecc30(param_1,param_2);
    if (puVar3 != (undefined4 *)0x0) {
      iVar4 = FUN_007edb60(param_1,puVar3,0x67,param_3);
      bVar12 = puVar3[6] != 0;
      iVar5 = FUN_007ecc90(param_1,puVar3,iVar4);
      if ((iVar5 == 0) &&
         (((!bVar12 || (iVar5 = FUN_007d45e0(param_1,puVar3), iVar5 == 0)) &&
          (local_5c = FUN_007d0590(puVar3[1] << 2), local_5c != 0)))) {
        iVar5 = 0;
        if (0 < (int)puVar3[1]) {
          do {
            *(undefined4 *)(local_5c + iVar5 * 4) = 0xffffffff;
            iVar5 = iVar5 + 1;
          } while (iVar5 < (int)puVar3[1]);
        }
        if (iVar4 != 0) {
          local_40 = param_1[7];
          local_48 = local_40 + 1;
          param_1[7] = local_40 + 2;
        }
        iVar5 = param_1[7];
        *(int *)(param_2 + 0x1c) = iVar5;
        iVar6 = param_1[7] + 1;
        param_1[7] = iVar6;
        for (iVar7 = puVar3[4]; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x1c)) {
          iVar6 = iVar6 + 1;
          param_1[7] = iVar6;
        }
        local_18 = 0;
        local_14 = 0;
        local_10 = 0;
        local_c = 0;
        local_8 = 0;
        local_4 = 0;
        local_20 = param_1;
        local_1c = param_2;
        local_60 = 0;
        local_38 = (int *)0x0;
        if (0 < *param_3) {
          do {
            iVar7 = FUN_007ebc80(&local_20,*(undefined4 *)(iVar11 + param_3[2]));
            if (iVar7 != 0) goto LAB_007f976b;
            iVar7 = 0;
            if (0 < (int)puVar3[1]) {
              iVar6 = 0;
              do {
                iVar8 = FUN_007d08e0(*(undefined4 *)(puVar3[2] + iVar6),
                                     *(undefined4 *)(iVar11 + 4 + param_3[2]));
                if (iVar8 == 0) {
                  if (iVar7 == puVar3[3]) {
                    local_34 = *(undefined4 *)(iVar11 + param_3[2]);
                    local_60 = 1;
                  }
                  *(int **)(local_5c + iVar7 * 4) = local_38;
                  break;
                }
                iVar7 = iVar7 + 1;
                iVar6 = iVar6 + 0x14;
              } while (iVar7 < (int)puVar3[1]);
            }
            if ((int)puVar3[1] <= iVar7) {
              iVar6 = FUN_007ea8f0(*(undefined4 *)(iVar11 + 4 + param_3[2]));
              if (iVar6 == 0) {
                FUN_007d0820(param_1,s_no_such_column___s_00a01cfc,
                             *(undefined4 *)(param_3[2] + 4 + (int)local_38 * 0xc));
                goto LAB_007f976b;
              }
              local_34 = *(undefined4 *)(iVar11 + param_3[2]);
              local_60 = 1;
            }
            iVar6 = FUN_007ed5e0(param_1,0x17,*puVar3,*(undefined4 *)(puVar3[2] + iVar7 * 0x14),
                                 *(undefined4 *)
                                  ((uint)*(byte *)((int)puVar3 + 0x1d) * 0x70 + *(int *)(iVar1 + 4))
                                );
            if (iVar6 == 1) goto LAB_007f976b;
            if (iVar6 == 2) {
              *(undefined4 *)(local_5c + iVar7 * 4) = 0xffffffff;
            }
            local_38 = (int *)((int)local_38 + 1);
            iVar11 = iVar11 + 0xc;
          } while ((int)local_38 < *param_3);
        }
        iVar11 = puVar3[4];
        local_38 = (int *)0x0;
        local_30 = (int *)0x0;
        if (iVar11 != 0) {
          do {
            if (local_60 == 0) {
              iVar7 = 0;
              if (0 < *(int *)(iVar11 + 4)) {
                piVar10 = *(int **)(iVar11 + 8);
                do {
                  if (-1 < *(int *)(local_5c + *piVar10 * 4)) break;
                  iVar7 = iVar7 + 1;
                  piVar10 = piVar10 + 1;
                } while (iVar7 < *(int *)(iVar11 + 4));
              }
            }
            else {
              iVar7 = 0;
            }
            if (iVar7 < *(int *)(iVar11 + 4)) {
              local_30 = (int *)((int)local_30 + 1);
            }
            piVar10 = local_30;
            iVar11 = *(int *)(iVar11 + 0x1c);
            local_38 = (int *)((int)local_38 + 1);
          } while (iVar11 != 0);
          if (0 < (int)local_38) {
            local_2c = (int *)FUN_007d0590(local_38 + (int)local_30);
            if (local_2c == (int *)0x0) goto LAB_007f976b;
            local_4c = local_2c + (int)piVar10;
          }
        }
        iVar11 = puVar3[4];
        if (iVar11 != 0) {
          local_38 = local_4c;
          local_30 = local_2c;
          do {
            if (local_60 == 0) {
              iVar7 = 0;
              if (0 < *(int *)(iVar11 + 4)) {
                piVar10 = *(int **)(iVar11 + 8);
                do {
                  if (-1 < *(int *)(local_5c + *piVar10 * 4)) break;
                  iVar7 = iVar7 + 1;
                  piVar10 = piVar10 + 1;
                } while (iVar7 < *(int *)(iVar11 + 4));
              }
            }
            else {
              iVar7 = 0;
            }
            if (iVar7 < *(int *)(iVar11 + 4)) {
              iVar7 = FUN_007d2c00(param_1,iVar11);
              if (iVar7 != 0) goto LAB_007f976b;
              *local_30 = iVar11;
              local_30 = local_30 + 1;
              *(undefined1 *)local_38 = 1;
            }
            else {
              *(undefined1 *)local_38 = 0;
            }
            iVar11 = *(int *)(iVar11 + 0x1c);
            local_38 = (int *)((int)local_38 + 1);
          } while (iVar11 != 0);
        }
        iVar11 = FUN_007ebc80(&local_20,param_4);
        if (iVar11 == 0) {
          if (bVar12) {
            FUN_007ed660(param_1,local_28,*puVar3);
          }
          iVar11 = FUN_007e8190(param_1);
          if (iVar11 != 0) {
            if (*(char *)((int)param_1 + 0x13) == '\0') {
              FUN_007dda40(iVar11);
            }
            FUN_007d3d30(param_1,1,*(undefined1 *)((int)puVar3 + 0x1d));
            if (bVar12) {
              uVar9 = FUN_007ead10(puVar3[6]);
              FUN_007e9760(param_1,uVar9,8,iVar5,0,0,0,0);
              FUN_007e6af0(uVar9);
            }
            iVar7 = FUN_007f7600(param_1,param_2,param_4,0);
            if (iVar7 != 0) {
              FUN_007dc140(iVar11,0x26,iVar5,0);
              FUN_007dc140(iVar11,0x1f,0,0);
              FUN_007f71d0(iVar7);
              if ((*(char *)(iVar1 + 8) < '\0') && (param_1[0x28] == 0)) {
                FUN_007dc140(iVar11,0x32,0,0);
              }
              if (iVar4 != 0) {
                FUN_007dc140(iVar11,0x75,local_48,0);
                FUN_007dc140(iVar11,0x67,local_48,puVar3[1]);
                FUN_007dc140(iVar11,0x75,local_40,0);
                FUN_007dc140(iVar11,0x67,local_40,puVar3[1]);
                FUN_007dc140(iVar11,0x13,0,0);
                local_58 = FUN_007dc140(iVar11,0x5e,0,0);
                if (!bVar12) {
                  FUN_007dc140(iVar11,0x60,0,0);
                  FUN_007dc140(iVar11,0x60,0,0);
                  FUN_007ecd00(iVar11,iVar5,puVar3);
                }
                FUN_007dc140(iVar11,0x7a,iVar5,0);
                FUN_007dc140(iVar11,0x26,iVar5,0);
                FUN_007dc140(iVar11,0x2a,iVar5,0);
                FUN_007dc140(iVar11,0x71,local_48,0);
                if (local_60 == 0) {
                  FUN_007dc140(iVar11,0x26,iVar5,0);
                }
                else {
                  FUN_007ec7c0(param_1,local_34);
                }
                iVar7 = 0;
                if (0 < (int)puVar3[1]) {
                  iVar6 = 0;
                  do {
                    if (iVar7 == puVar3[3]) {
                      FUN_007dc140(iVar11,0x76,0,0);
                    }
                    else {
                      iVar8 = *(int *)(local_5c + iVar7 * 4);
                      if (iVar8 < 0) {
                        FUN_007dc140(iVar11,2,iVar5,iVar7);
                        if (puVar3[6] == 0) {
                          iVar8 = FUN_007dda70(iVar11);
                          local_30 = (int *)CONCAT31(local_30._1_3_,*(undefined1 *)(iVar8 + 0x10));
                          FUN_007d0150(*(undefined4 *)(puVar3[2] + iVar6 + 4),local_30,
                                       *(undefined1 *)(puVar3[2] + iVar6 + 0x12),&local_38);
                          FUN_007dc430(iVar11,0xffffffff,local_38,0xfffffff8);
                        }
                      }
                      else {
                        FUN_007ec7c0(param_1,*(undefined4 *)(param_3[2] + iVar8 * 0xc));
                      }
                    }
                    iVar7 = iVar7 + 1;
                    iVar6 = iVar6 + 0x14;
                  } while (iVar7 < (int)puVar3[1]);
                }
                FUN_007dc140(iVar11,0x5b,puVar3[1],0);
                if (!bVar12) {
                  FUN_007f9840(iVar11,puVar3);
                }
                if (param_1[6] != 0) goto LAB_007f976b;
                FUN_007dc140(iVar11,0x71,local_40,0);
                if (!bVar12) {
                  FUN_007dc140(iVar11,0x1e,iVar5,0);
                }
                iVar7 = FUN_007ede00(param_1,0x67,param_3,1,puVar3,local_40,local_48,param_5,
                                     local_58);
                if (iVar7 != 0) goto LAB_007f976b;
              }
              if (!bVar12) {
                FUN_007dc140(iVar11,0x32,*(undefined1 *)((int)puVar3 + 0x1d),0);
                FUN_007dc140(iVar11,9,iVar5,puVar3[5]);
                FUN_007dc140(iVar11,0x67,iVar5,puVar3[1]);
                if (param_5 == 5) {
LAB_007f93cf:
                  bVar2 = true;
                }
                else {
                  bVar2 = false;
                  for (iVar7 = puVar3[4]; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x1c)) {
                    if (*(char *)(iVar7 + 0x14) == '\x05') goto LAB_007f93cf;
                  }
                }
                iVar6 = 0;
                for (iVar7 = puVar3[4]; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x1c)) {
                  if ((bVar2) || (*(char *)(iVar6 + (int)local_4c) != '\0')) {
                    FUN_007dc140(iVar11,0x32,*(undefined1 *)(iVar7 + 0x16),0);
                    FUN_007dda80(iVar11,9,iVar5 + 1 + iVar6,*(undefined4 *)(iVar7 + 0x10),
                                 iVar7 + 0x20,0xfffffffa);
                  }
                  iVar6 = iVar6 + 1;
                }
                if (iVar4 == 0) {
                  FUN_007dc140(iVar11,0x13,0,0);
                  local_58 = FUN_007dc140(iVar11,0x5e,0,0);
                  FUN_007dc140(iVar11,0x60,0,0);
                }
                FUN_007dc140(iVar11,0x2d,iVar5,local_58);
                if (local_60 != 0) {
                  FUN_007ec010(param_1,local_34);
                  FUN_007dc140(iVar11,0x24,0,0);
                }
                iVar7 = 0;
                if (0 < (int)puVar3[1]) {
                  local_30 = (int *)0x0;
                  do {
                    if (iVar7 == puVar3[3]) {
                      FUN_007dc140(iVar11,0x76,0,0);
                    }
                    else {
                      iVar6 = *(int *)(local_5c + iVar7 * 4);
                      if (iVar6 < 0) {
                        FUN_007dc140(iVar11,2,iVar5,iVar7);
                        if (puVar3[6] == 0) {
                          iVar6 = FUN_007dda70(iVar11);
                          local_34 = CONCAT31(local_34._1_3_,*(undefined1 *)(iVar6 + 0x10));
                          FUN_007d0150(*(undefined4 *)((int)local_30 + puVar3[2] + 4),local_34,
                                       *(undefined1 *)((int)local_30 + puVar3[2] + 0x12),&local_38);
                          FUN_007dc430(iVar11,0xffffffff,local_38,0xfffffff8);
                        }
                      }
                      else {
                        FUN_007ec010(param_1,*(undefined4 *)(param_3[2] + iVar6 * 0xc));
                      }
                    }
                    iVar7 = iVar7 + 1;
                    local_30 = local_30 + 5;
                  } while (iVar7 < (int)puVar3[1]);
                }
                FUN_007f9920(param_1,puVar3,iVar5,local_4c,local_60,1,param_5,local_58);
                FUN_007ecde0(iVar1,iVar11,puVar3,iVar5,local_4c);
                if (local_60 != 0) {
                  FUN_007dc140(iVar11,0x5c,iVar5,0);
                }
                FUN_007fa020(param_1,puVar3,iVar5,local_4c,local_60,1,0xffffffff);
              }
              if ((*(char *)(iVar1 + 8) < '\0') && (param_1[0x28] == 0)) {
                FUN_007dc140(iVar11,0x28,1,0);
              }
              if (iVar4 != 0) {
                if (!bVar12) {
                  iVar6 = 0;
                  for (iVar7 = puVar3[4]; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x1c)) {
                    if ((bVar2) || (*(char *)((int)local_4c + iVar6) != '\0')) {
                      FUN_007dc140(iVar11,0x1e,iVar5 + 1 + iVar6,0);
                    }
                    iVar6 = iVar6 + 1;
                  }
                  FUN_007dc140(iVar11,0x1e,iVar5,0);
                }
                iVar7 = FUN_007ede00(param_1,0x67,param_3,2,puVar3,local_40,local_48,param_5,
                                     local_58);
                if (iVar7 != 0) goto LAB_007f976b;
              }
              FUN_007dc140(iVar11,0x61,0,local_58);
              uVar9 = FUN_007dc320(iVar11);
              FUN_007dc400(iVar11,local_58,uVar9);
              FUN_007dc140(iVar11,0x5f,0,0);
              if (iVar4 == 0) {
                iVar7 = 0;
                for (iVar4 = puVar3[4]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x1c)) {
                  if ((bVar2) || (*(char *)((int)local_4c + iVar7) != '\0')) {
                    FUN_007dc140(iVar11,0x1e,iVar5 + 1 + iVar7,0);
                  }
                  iVar7 = iVar7 + 1;
                }
                FUN_007dc140(iVar11,0x1e,iVar5,0);
              }
              else {
                FUN_007dc140(iVar11,0x1e,local_40,0);
                FUN_007dc140(iVar11,0x1e,local_48,0);
              }
              if (((*(char *)(iVar1 + 8) < '\0') && (param_1[0x28] == 0)) &&
                 (*(char *)((int)param_1 + 0x13) == '\0')) {
                FUN_007dc140(iVar11,0x39,1,0);
                FUN_007dccf0(iVar11,1);
                FUN_007dcd30(iVar11,0,s_rows_updated_00a054d4,0xfffffffe);
              }
            }
          }
        }
      }
    }
  }
LAB_007f976b:
  FUN_007ed690(local_28);
  FUN_007d05b0(local_2c);
  FUN_007d05b0(local_5c);
  FUN_007d3a10(param_2);
  FUN_007ea740(param_3);
  FUN_007eabc0(param_4);
  return;
}


// ==== FUN_007f97c0 @ 0x007f97c0 ====

void FUN_007f97c0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 0x18) == 0) {
    iVar1 = *(int *)(param_2 + 0xc);
    iVar2 = FUN_007d0550(*(int *)(param_2 + 4) + 1);
    *(int *)(param_2 + 0x18) = iVar2;
    if (iVar2 == 0) {
      return;
    }
    iVar2 = 0;
    if (0 < *(int *)(param_2 + 4)) {
      do {
        *(undefined1 *)(iVar2 + *(int *)(param_2 + 0x18)) =
             *(undefined1 *)
              (*(int *)(iVar1 + 8) + 0x12 + *(int *)(*(int *)(param_2 + 8) + iVar2 * 4) * 0x14);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_2 + 4));
    }
    *(undefined1 *)(*(int *)(param_2 + 4) + *(int *)(param_2 + 0x18)) = 0;
  }
  FUN_007dc430(param_1,0xffffffff,*(undefined4 *)(param_2 + 0x18),0);
  return;
}


// ==== FUN_007f9840 @ 0x007f9840 ====

void FUN_007f9840(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_2 + 0x30) == 0) {
    iVar1 = FUN_007d0550(*(int *)(param_2 + 4) + 1);
    if (iVar1 == 0) {
      return;
    }
    iVar2 = 0;
    if (0 < *(int *)(param_2 + 4)) {
      iVar3 = 0;
      do {
        *(undefined1 *)(iVar2 + iVar1) = *(undefined1 *)(*(int *)(param_2 + 8) + 0x12 + iVar3);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x14;
      } while (iVar2 < *(int *)(param_2 + 4));
    }
    *(undefined1 *)(iVar1 + *(int *)(param_2 + 4)) = 0;
    *(int *)(param_2 + 0x30) = iVar1;
  }
  FUN_007dc430(param_1,0xffffffff,*(undefined4 *)(param_2 + 0x30),0);
  return;
}


// ==== FUN_007f98b0 @ 0x007f98b0 ====

undefined4 FUN_007f98b0(int param_1,uint param_2,int param_3)

{
  short *psVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  psVar1 = *(short **)(param_1 + 8);
  if (psVar1 == (short *)0x0) {
    return 0;
  }
  iVar4 = 0;
  if (0 < *psVar1) {
    piVar3 = (int *)(psVar1 + 8);
    do {
      if (piVar3[1] == 0) {
        if ((*(byte *)(*piVar3 + 0x1d) == param_2) && (*(int *)(*piVar3 + 0x14) == param_3)) {
          return 1;
        }
      }
      else {
        iVar2 = FUN_007f98b0(piVar3[1],param_2,param_3);
        if (iVar2 != 0) {
          return 1;
        }
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 10;
    } while (iVar4 < **(short **)(param_1 + 8));
  }
  return 0;
}


// ==== FUN_007f98bc @ 0x007f98bc ====

undefined4 FUN_007f98bc(int param_1,uint param_2,int param_3)

{
  short *in_EAX;
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *in_EAX) {
    piVar2 = (int *)(in_EAX + 8);
    do {
      if (piVar2[1] == 0) {
        if ((*(byte *)(*piVar2 + 0x1d) == param_2) && (*(int *)(*piVar2 + 0x14) == param_3)) {
          return 1;
        }
      }
      else {
        iVar1 = FUN_007f98b0(piVar2[1],param_2,param_3);
        if (iVar1 != 0) {
          return 1;
        }
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 10;
    } while (iVar3 < **(short **)(param_1 + 8));
  }
  return 0;
}


// ==== FUN_007f9920 @ 0x007f9920 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f9920(undefined4 *param_1,undefined4 *param_2,int param_3,int param_4,int param_5,
                 int param_6,uint param_7,undefined4 param_8)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int local_f4;
  uint local_f0;
  int local_ec;
  int local_e8;
  undefined4 local_e4;
  int local_e0;
  undefined4 local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  char local_cc [200];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  local_d4 = 0;
  local_dc = 0;
  if ((param_6 == 0) || (local_e0 = 1, param_5 == 0)) {
    local_e0 = 0;
  }
  uVar2 = FUN_007e8190(param_1);
  iVar10 = param_2[1];
  local_e8 = 0;
  local_d0 = iVar10;
  if (0 < iVar10) {
    local_f4 = 0;
    local_f0 = iVar10;
    do {
      if (local_e8 != param_2[3]) {
        uVar12 = (uint)*(byte *)(local_f4 + 0x10 + param_2[2]);
        if (uVar12 != 0) {
          if (param_7 == 99) {
            if (uVar12 != 99) goto LAB_007f99cb;
LAB_007f99d7:
            uVar12 = 2;
          }
          else {
            uVar12 = param_7;
LAB_007f99cb:
            if ((uVar12 == 5) && (*(int *)(local_f4 + param_2[2] + 4) == 0)) goto LAB_007f99d7;
          }
          FUN_007dc140(uVar2,0x60,local_f0 + -1,1);
          uVar3 = FUN_007dc140(uVar2,0x45,1,0);
          switch(uVar12) {
          case 1:
          case 2:
          case 3:
            local_e4 = 0;
            FUN_007dc140(uVar2,0x25,0x13,uVar12);
            FUN_007d0700(&local_e4,*param_2,&DAT_00a0119c,*(undefined4 *)(local_f4 + param_2[2]),
                         s_may_not_be_NULL_00a05538,0);
            FUN_007dc430(uVar2,0xffffffff,local_e4,0xffffffff);
            break;
          case 4:
            FUN_007dc140(uVar2,0xb,iVar10 + 1 + local_e0,0);
            FUN_007dc140(uVar2,0x61,0,param_8);
            break;
          case 5:
            FUN_007ec010(param_1,*(undefined4 *)(local_f4 + 4 + param_2[2]));
            FUN_007dc140(uVar2,0x2c,local_f0,0);
          }
          uVar4 = FUN_007dc320(uVar2);
          FUN_007dc400(uVar2,uVar3,uVar4);
        }
      }
      local_e8 = local_e8 + 1;
      local_f4 = local_f4 + 0x14;
      local_f0 = local_f0 + -1;
    } while (local_e8 < iVar10);
  }
  if (param_5 != 0) {
    uVar12 = (uint)*(byte *)(param_2 + 8);
    if (param_7 == 99) {
      if (uVar12 == 99) {
        uVar12 = 2;
      }
    }
    else {
      uVar12 = param_7;
    }
    if (param_6 != 0) {
      FUN_007dc140(uVar2,0x60,iVar10 + 1,1);
      FUN_007dc140(uVar2,0x60,iVar10 + 1,1);
      local_dc = FUN_007dc140(uVar2,0x47,0,0);
    }
    FUN_007dc140(uVar2,0x60,iVar10,1);
    local_e4 = FUN_007dc140(uVar2,0x2d,param_3,0);
    switch(uVar12) {
    case 4:
      FUN_007dc140(uVar2,0xb,iVar10 + 1 + local_e0,0);
      FUN_007dc140(uVar2,0x61,0,param_8);
      break;
    case 5:
      FUN_007ecde0(*param_1,uVar2,param_2,param_3,0);
      if (param_6 != 0) {
        FUN_007dc140(uVar2,0x60,iVar10 + local_e0,1);
        FUN_007dc140(uVar2,0x7a,param_3,0);
      }
      local_d4 = 1;
      break;
    default:
      uVar12 = 2;
    case 1:
    case 2:
    case 3:
      FUN_007dda80(uVar2,0x25,0x13,uVar12,s_PRIMARY_KEY_must_be_unique_00a0551c,0xfffffffe);
    }
    uVar3 = FUN_007dc320(uVar2);
    FUN_007dc400(uVar2,local_e4,uVar3);
    if (param_6 != 0) {
      FUN_007dc400(uVar2,local_dc,uVar3);
      FUN_007dc140(uVar2,0x60,iVar10 + 1,1);
      FUN_007dc140(uVar2,0x7a,param_3,0);
    }
  }
  local_d8 = param_2[4];
  local_f4 = -1;
  local_ec = 0;
  if (local_d8 == 0) {
    return;
  }
  do {
    iVar11 = local_d8;
    if ((param_4 == 0) || (*(char *)(local_ec + param_4) != '\0')) {
      local_f4 = local_f4 + 1;
      FUN_007dc140(uVar2,0x60,local_f4 + iVar10,1);
      iVar13 = 0;
      if (0 < *(int *)(iVar11 + 4)) {
        do {
          iVar6 = *(int *)(*(int *)(iVar11 + 8) + iVar13 * 4);
          if (iVar6 == param_2[3]) {
            iVar6 = local_f4 + iVar10 + 1 + iVar13;
          }
          else {
            iVar6 = (local_f4 - iVar6) + iVar13 + iVar10;
          }
          FUN_007dc140(uVar2,0x60,iVar6,1);
          iVar13 = iVar13 + 1;
        } while (iVar13 < *(int *)(iVar11 + 4));
      }
      local_dc = FUN_007dc140(uVar2,0x5b,*(undefined4 *)(iVar11 + 4),0x1000000);
      FUN_007f97c0(uVar2,iVar11);
      local_f0 = (uint)*(byte *)(iVar11 + 0x14);
      if (local_f0 != 0) {
        if (param_7 == 99) {
          if (local_f0 == 99) {
            local_f0 = 2;
          }
        }
        else {
          local_f0 = param_7;
        }
        if (local_d4 != 0) {
          if (local_f0 == 4) {
            local_f0 = 5;
          }
          else if (local_f0 == 3) {
            local_f0 = 2;
          }
        }
        iVar10 = local_d0 + local_e0;
        iVar11 = iVar10 + 1 + local_f4;
        FUN_007dc140(uVar2,0x60,iVar11,1);
        local_e4 = FUN_007dc140(uVar2,0x21,local_ec + 1 + param_3,0);
        switch(local_f0) {
        case 1:
        case 2:
        case 3:
          iVar10 = *(int *)(local_d8 + 4);
          pcVar7 = s_columns_00a05510;
          if (iVar10 < 2) {
            pcVar7 = s_column_00a05508;
          }
          pcVar9 = local_cc;
          do {
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
            *pcVar9 = cVar1;
            pcVar9 = pcVar9 + 1;
          } while (cVar1 != '\0');
          pcVar7 = local_cc;
          do {
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          pcVar7 = pcVar7 + -(int)(local_cc + 1);
          iVar11 = 0;
          if (0 < iVar10) {
            do {
              if ((char *)0xa9 < pcVar7) break;
              pcVar9 = *(char **)(param_2[2] + *(int *)(*(int *)(local_d8 + 8) + iVar11 * 4) * 0x14)
              ;
              pcVar5 = pcVar9;
              do {
                cVar1 = *pcVar5;
                pcVar5 = pcVar5 + 1;
              } while (cVar1 != '\0');
              pcVar8 = pcVar7;
              if (0 < iVar11) {
                *(undefined2 *)(local_cc + (int)pcVar7) = DAT_00a05504;
                local_cc[(int)(pcVar7 + 2)] = DAT_00a05506;
                pcVar8 = pcVar7 + 2;
              }
              pcVar7 = pcVar5 + ((int)pcVar8 - (int)(pcVar9 + 1));
              if ((char *)0xaa < pcVar7) {
                builtin_strncpy(local_cc + (int)pcVar8,"...",4);
                pcVar7 = pcVar8 + 3;
                break;
              }
              iVar13 = (int)pcVar8 - (int)pcVar9;
              do {
                cVar1 = *pcVar9;
                (local_cc + iVar13)[(int)pcVar9] = cVar1;
                pcVar9 = pcVar9 + 1;
              } while (cVar1 != '\0');
              iVar11 = iVar11 + 1;
            } while (iVar11 < iVar10);
          }
          pcVar9 = s_are_not_unique_00a054f4;
          if (iVar10 < 2) {
            pcVar9 = s_is_not_unique_00a054e4;
          }
          pcVar7 = local_cc + (int)pcVar7;
          do {
            cVar1 = *pcVar9;
            pcVar9 = pcVar9 + 1;
            *pcVar7 = cVar1;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_007dda80(uVar2,0x25,0x13,local_f0,local_cc,0);
          break;
        case 4:
          FUN_007dc140(uVar2,0xb,iVar10 + 3 + local_f4,0);
          FUN_007dc140(uVar2,0x61,0,param_8);
          break;
        case 5:
          FUN_007ece40(*param_1,uVar2,param_2,param_3,0);
          if (param_6 != 0) {
            FUN_007dc140(uVar2,0x60,iVar11,1);
            FUN_007dc140(uVar2,0x7a,param_3,0);
          }
          local_d4 = 1;
        }
        uVar12 = FUN_007dc320(uVar2);
        FUN_007dc400(uVar2,local_dc,uVar12 | 0x1000000);
        FUN_007dc400(uVar2,local_e4,uVar12);
        iVar11 = local_d8;
      }
    }
    local_d8 = *(int *)(iVar11 + 0x1c);
    local_ec = local_ec + 1;
    if (local_d8 == 0) {
      return;
    }
    iVar10 = local_d0;
  } while( true );
}


// ==== FUN_007fa020 @ 0x007fa020 ====

void FUN_007fa020(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = FUN_007e8190(param_1);
  iVar4 = 0;
  for (iVar1 = *(int *)(param_2 + 0x10); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
    iVar4 = iVar4 + 1;
  }
  while (iVar1 = iVar4, iVar4 = iVar1 + -1, -1 < iVar4) {
    if ((param_4 == 0) || (*(char *)(iVar4 + param_4) != '\0')) {
      FUN_007dc140(uVar3,0x6e,iVar1 + param_3,0);
    }
  }
  FUN_007dc140(uVar3,0x5b,*(undefined4 *)(param_2 + 4),0);
  FUN_007f9840(uVar3,param_2);
  if (-1 < param_7) {
    FUN_007dc140(uVar3,0x60,1,0);
    FUN_007dc140(uVar3,0x60,1,0);
    FUN_007dc140(uVar3,0x71,param_7,0);
  }
  if (*(char *)(param_1 + 0x13) == '\0') {
    bVar2 = (param_6 != 0) - 1U & 2 | 1;
  }
  else {
    bVar2 = 0;
  }
  FUN_007dc140(uVar3,0x71,param_3,bVar2);
  if ((param_6 != 0) && (param_5 != 0)) {
    FUN_007dc140(uVar3,0xb,1,0);
  }
  return;
}


// ==== FUN_007fa110 @ 0x007fa110 ====

void FUN_007fa110(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = FUN_007e8190(param_1);
  FUN_007dc140(uVar2,0x32,*(undefined1 *)(param_2 + 0x1d),0);
  FUN_007dc140(uVar2,param_4,param_3,*(undefined4 *)(param_2 + 0x14));
  FUN_007dc140(uVar2,0x67,param_3,*(undefined4 *)(param_2 + 4));
  iVar3 = 1;
  for (iVar1 = *(int *)(param_2 + 0x10); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
    FUN_007dc140(uVar2,0x32,*(undefined1 *)(iVar1 + 0x16),0);
    FUN_007dda80(uVar2,param_4,iVar3 + param_3,*(undefined4 *)(iVar1 + 0x10),iVar1 + 0x20,0xfffffffa
                );
    iVar3 = iVar3 + 1;
  }
  if (*(int *)(param_1 + 0x1c) <= iVar3 + param_3) {
    *(int *)(param_1 + 0x1c) = iVar3 + param_3;
  }
  return;
}


// ==== FUN_007fa1b0 @ 0x007fa1b0 ====

void FUN_007fa1b0(int *param_1,int param_2,int *param_3,undefined4 *param_4,int *param_5,
                 undefined4 param_6)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int *piVar12;
  bool bVar13;
  int local_6c;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_24;
  int *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_5c = -1;
  local_58 = -1;
  local_6c = 0;
  local_30 = 0;
  local_2c = 0;
  bVar2 = false;
  local_64 = 0;
  local_48 = 0;
  local_40 = 0;
  local_44 = 0;
  local_38 = 0;
  local_54 = 0;
  if ((((param_1[6] != 0) || (DAT_00b5c4c4 != 0)) || (iVar1 = *param_1, *(int *)(param_2 + 8) == 0))
     || (puVar3 = (undefined4 *)FUN_007ecc30(param_1,param_2), puVar3 == (undefined4 *)0x0))
  goto LAB_007faee0;
  puVar4 = (undefined4 *)((uint)*(byte *)((int)puVar3 + 0x1d) * 0x70 + *(int *)(iVar1 + 4));
  iVar5 = FUN_007ed5e0(param_1,0x12,*puVar3,0,*puVar4);
  if (iVar5 != 0) goto LAB_007faee0;
  uVar6 = FUN_007edb60(param_1,puVar3,0x68,0);
  bVar13 = puVar3[6] != 0;
  iVar5 = FUN_007ecc90(param_1,puVar3,uVar6);
  if ((iVar5 != 0) || ((bVar13 && (iVar5 = FUN_007d45e0(param_1,puVar3), iVar5 != 0))))
  goto LAB_007faee0;
  for (iVar5 = puVar3[4]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x1c)) {
    iVar7 = FUN_007d2c00(param_1,iVar5);
    if (iVar7 != 0) goto LAB_007faee0;
  }
  iVar5 = FUN_007e8190(param_1);
  if (iVar5 == 0) goto LAB_007faee0;
  if (*(char *)((int)param_1 + 0x13) == '\0') {
    FUN_007dda40(iVar5);
  }
  if ((param_4 == (undefined4 *)0x0) && (uVar6 == 0)) {
    uVar8 = 0;
  }
  else {
    uVar8 = 1;
  }
  FUN_007d3d30(param_1,uVar8,*(undefined1 *)((int)puVar3 + 0x1d));
  if (uVar6 != 0) {
    local_58 = param_1[7];
    param_1[7] = local_58 + 1;
  }
  if (*(char *)((int)puVar3 + 0x21) != '\0') {
    iVar7 = param_1[7];
    iVar9 = FUN_007dc320(iVar5);
    local_24 = param_1[8];
    local_54 = local_24 + 1;
    param_1[8] = local_24 + 2;
    FUN_007dc140(iVar5,0x32,*(undefined1 *)((int)puVar3 + 0x1d),0);
    FUN_007dc140(iVar5,0xe,iVar7,*(undefined4 *)(puVar4[0x19] + 0x14));
    FUN_007dc140(iVar5,0x67,iVar7,2);
    FUN_007dc140(iVar5,0x79,iVar7,iVar9 + 0xd);
    FUN_007dc140(iVar5,2,iVar7,0);
    FUN_007dda80(iVar5,0x5a,0,0,*puVar3,0);
    FUN_007dc140(iVar5,0x46,0x6f01,iVar9 + 0xc);
    FUN_007dc140(iVar5,0x26,iVar7,0);
    FUN_007dc140(iVar5,0x78,local_24,1);
    FUN_007dc140(iVar5,2,iVar7,1);
    FUN_007dc140(iVar5,0x78,local_54,1);
    FUN_007dc140(iVar5,0x61,0,iVar9 + 0xd);
    FUN_007dc140(iVar5,0x6c,iVar7,iVar9 + 4);
    FUN_007dc140(iVar5,0x1e,iVar7,0);
  }
  if (param_4 == (undefined4 *)0x0) {
    local_60 = *param_3;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    local_20 = param_1;
    local_64 = -1;
    bVar2 = false;
    local_34 = 0;
    if (0 < local_60) {
      local_4c = 0;
      do {
        iVar7 = FUN_007ebc80(&local_20,*(undefined4 *)(local_4c + param_3[2]));
        if (iVar7 != 0) goto LAB_007faee0;
        local_34 = local_34 + 1;
        local_4c = local_4c + 0xc;
      } while (local_34 < local_60);
    }
  }
  else {
    uVar8 = FUN_007dc140(iVar5,0x61,0,0);
    local_48 = FUN_007dc320(iVar5);
    local_44 = FUN_007dc190(iVar5);
    iVar7 = FUN_007e9760(param_1,param_4,0xb,local_44,0,0,0,0);
    if (((iVar7 != 0) || (param_1[6] != 0)) || (DAT_00b5c4c4 != 0)) goto LAB_007faee0;
    local_40 = FUN_007dc190(iVar5);
    FUN_007dc140(iVar5,0x61,0,local_40);
    local_60 = *(int *)*param_4;
    if ((uVar6 == 0) &&
       (iVar7 = FUN_007f98b0(param_4,*(undefined1 *)((int)puVar3 + 0x1d),puVar3[5]), iVar7 == 0)) {
      uVar10 = FUN_007dc320(iVar5);
      FUN_007dc400(iVar5,uVar8,uVar10);
    }
    else {
      local_64 = param_1[7];
      bVar2 = true;
      param_1[7] = local_64 + 1;
      FUN_007dc1e0(iVar5,local_44);
      FUN_007dc140(iVar5,0x5b,local_60,0);
      FUN_007f9840(iVar5,puVar3);
      FUN_007dc140(iVar5,0x19,local_64,0);
      FUN_007dc140(iVar5,0x66,1,0);
      FUN_007dc140(iVar5,0x71,local_64,0);
      FUN_007dc140(iVar5,0x18,0,0);
      uVar10 = FUN_007dc320(iVar5);
      FUN_007dc400(iVar5,uVar8,uVar10);
      FUN_007dc140(iVar5,0x2e,local_64,0);
      FUN_007dc140(iVar5,0x67,local_64,local_60);
      FUN_007dc140(iVar5,0x61,0,local_48);
      FUN_007dc1e0(iVar5,local_40);
    }
  }
  if (param_5 == (int *)0x0) {
    if (local_60 != puVar3[1]) {
      FUN_007d0820(param_1,s_table__S_has__d_columns_but__d_v_00a05598,param_2,0,puVar3[1],local_60)
      ;
      goto LAB_007faee0;
    }
    local_5c = puVar3[3];
  }
  else {
    iVar7 = *param_5;
    if (local_60 != iVar7) {
      FUN_007d0820(param_1,s__d_values_for__d_columns_00a0557c,local_60,iVar7);
      goto LAB_007faee0;
    }
    iVar9 = 0;
    if (0 < iVar7) {
      do {
        *(undefined4 *)(param_5[2] + 4 + iVar9 * 8) = 0xffffffff;
        iVar9 = iVar9 + 1;
      } while (iVar9 < *param_5);
    }
    iVar7 = 0;
    if (0 < *param_5) {
      do {
        iVar9 = 0;
        if (0 < (int)puVar3[1]) {
          local_4c = 0;
          iVar9 = 0;
          do {
            iVar11 = FUN_007d08e0(*(undefined4 *)(param_5[2] + iVar7 * 8),
                                  *(undefined4 *)(puVar3[2] + local_4c));
            if (iVar11 == 0) {
              *(int *)(param_5[2] + 4 + iVar7 * 8) = iVar9;
              if (iVar9 == puVar3[3]) {
                local_5c = iVar7;
              }
              break;
            }
            iVar9 = iVar9 + 1;
            local_4c = local_4c + 0x14;
          } while (iVar9 < (int)puVar3[1]);
        }
        if ((int)puVar3[1] <= iVar9) {
          iVar9 = FUN_007ea8f0(*(undefined4 *)(param_5[2] + iVar7 * 8));
          if (iVar9 == 0) {
            FUN_007d0820(param_1,s_table__S_has_no_column_named__s_00a0555c,param_2,0,
                         *(undefined4 *)(param_5[2] + iVar7 * 8));
            param_1[6] = param_1[6] + 1;
            goto LAB_007faee0;
          }
          local_5c = iVar7;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < *param_5);
    }
  }
  if (uVar6 != 0) {
    FUN_007dc140(iVar5,0x75,local_58,0);
    FUN_007dc140(iVar5,0x67,local_58,puVar3[1]);
  }
  if (*(char *)(iVar1 + 8) < '\0') {
    local_38 = param_1[8];
    param_1[8] = local_38 + 1;
    FUN_007dc140(iVar5,0x32,0,0);
    FUN_007dc140(iVar5,0x78,local_38,1);
  }
  if (uVar6 == 0) {
    local_6c = param_1[7];
    FUN_007fa110(param_1,puVar3,local_6c,9);
  }
  if (bVar2) {
    local_2c = FUN_007dc190(iVar5);
    FUN_007dc140(iVar5,0x79,local_64,local_2c);
    local_30 = FUN_007dc320(iVar5);
  }
  else if (param_4 != (undefined4 *)0x0) {
    FUN_007dc140(iVar5,0x61,0,local_48);
    FUN_007dc1e0(iVar5,local_44);
  }
  uVar8 = FUN_007dc190(iVar5);
  if ((uVar6 & 1) != 0) {
    if (local_5c < 0) {
      FUN_007dc140(iVar5,0x32,0xffffffff,0);
    }
    else if (bVar2) {
      FUN_007dc140(iVar5,2,local_64,local_5c);
    }
    else {
      FUN_007ec010(param_1,*(undefined4 *)(param_3[2] + local_5c * 0xc));
      iVar7 = FUN_007dc320(iVar5);
      FUN_007dc140(iVar5,0x45,0xffffffff,iVar7 + 3);
      FUN_007dc140(iVar5,0xb,1,0);
      FUN_007dc140(iVar5,0x32,0xffffffff,0);
      FUN_007dc140(iVar5,0x24,0,0);
    }
    iVar7 = 0;
    if (0 < (int)puVar3[1]) {
      local_44 = 0;
      do {
        if (param_5 == (int *)0x0) {
          iVar11 = iVar7;
LAB_007fa93d:
          if (bVar2) {
            FUN_007dc140(iVar5,2,local_64,iVar11);
          }
          else {
            FUN_007ec7c0(param_1,*(undefined4 *)(param_3[2] + iVar11 * 0xc));
          }
        }
        else {
          iVar9 = *param_5;
          iVar11 = 0;
          if (0 < iVar9) {
            piVar12 = (int *)(param_5[2] + 4);
            do {
              if (*piVar12 == iVar7) break;
              iVar11 = iVar11 + 1;
              piVar12 = piVar12 + 2;
            } while (iVar11 < iVar9);
          }
          if (iVar11 < iVar9) goto LAB_007fa93d;
          FUN_007ec010(param_1,*(undefined4 *)(puVar3[2] + 4 + local_44));
        }
        iVar7 = iVar7 + 1;
        local_44 = local_44 + 0x14;
      } while (iVar7 < (int)puVar3[1]);
    }
    FUN_007dc140(iVar5,0x5b,puVar3[1],0);
    if (!bVar13) {
      FUN_007f9840(iVar5,puVar3);
    }
    FUN_007dc140(iVar5,0x71,local_58,0);
    iVar7 = FUN_007ede00(param_1,0x68,0,1,puVar3,local_58,0xffffffff,param_6,uVar8);
    if (iVar7 != 0) goto LAB_007faee0;
  }
  if (uVar6 == 0) {
    if (!bVar13) goto LAB_007faa5f;
  }
  else if (!bVar13) {
    local_6c = param_1[7];
    FUN_007fa110(param_1,puVar3,local_6c,9);
LAB_007faa5f:
    if (local_5c < 0) {
      FUN_007dc140(iVar5,0x19,local_6c,local_54);
    }
    else {
      if (bVar2) {
        FUN_007dc140(iVar5,2,local_64,local_5c);
      }
      else if (param_4 == (undefined4 *)0x0) {
        FUN_007ec010(param_1,*(undefined4 *)(param_3[2] + local_5c * 0xc));
      }
      else {
        FUN_007dc140(iVar5,0x60,(local_60 - local_5c) + -1,1);
      }
      iVar7 = FUN_007dc320(iVar5);
      FUN_007dc140(iVar5,0x45,0xffffffff,iVar7 + 3);
      FUN_007dc140(iVar5,0xb,1,0);
      FUN_007dc140(iVar5,0x19,local_6c,local_54);
      FUN_007dc140(iVar5,0x24,0,0);
    }
    if (*(char *)((int)puVar3 + 0x21) != '\0') {
      FUN_007dc140(iVar5,0x2b,local_54,0);
    }
    iVar7 = 0;
    if (0 < (int)puVar3[1]) {
      local_44 = 0;
      do {
        if (iVar7 == puVar3[3]) {
          FUN_007dc140(iVar5,0x76,0,0);
        }
        else if (param_5 == (int *)0x0) {
          iVar11 = iVar7;
LAB_007fab66:
          if (bVar2) {
            FUN_007dc140(iVar5,2,local_64,iVar11);
          }
          else {
            if (param_4 == (undefined4 *)0x0) {
              uVar10 = *(undefined4 *)(param_3[2] + iVar11 * 0xc);
              goto LAB_007fabf6;
            }
            FUN_007dc140(iVar5,0x60,(iVar7 - iVar11) + local_60,1);
          }
        }
        else {
          iVar9 = *param_5;
          iVar11 = 0;
          if (0 < iVar9) {
            piVar12 = (int *)(param_5[2] + 4);
            do {
              if (*piVar12 == iVar7) break;
              iVar11 = iVar11 + 1;
              piVar12 = piVar12 + 2;
            } while (iVar11 < iVar9);
          }
          if (iVar11 < iVar9) goto LAB_007fab66;
          uVar10 = *(undefined4 *)(puVar3[2] + 4 + local_44);
LAB_007fabf6:
          FUN_007ec010(param_1,uVar10);
        }
        iVar7 = iVar7 + 1;
        local_44 = local_44 + 0x14;
      } while (iVar7 < (int)puVar3[1]);
    }
    FUN_007f9920(param_1,puVar3,local_6c,0,-1 < local_5c,0,param_6,uVar8);
    if ((uVar6 & 2) == 0) {
      iVar7 = -1;
    }
    else {
      iVar7 = local_58;
    }
    FUN_007fa020(param_1,puVar3,local_6c,0,0,0,iVar7);
  }
  if (*(char *)(iVar1 + 8) < '\0') {
    FUN_007dc140(iVar5,0x2f,local_38,0);
  }
  if (uVar6 != 0) {
    if (!bVar13) {
      FUN_007dc140(iVar5,0x1e,local_6c,0);
      iVar7 = puVar3[4];
      if (iVar7 != 0) {
        iVar9 = local_6c;
        do {
          iVar9 = iVar9 + 1;
          FUN_007dc140(iVar5,0x1e,iVar9,0);
          iVar7 = *(int *)(iVar7 + 0x1c);
        } while (iVar7 != 0);
      }
    }
    iVar7 = FUN_007ede00(param_1,0x68,0,2,puVar3,local_58,0xffffffff,param_6,uVar8);
    if (iVar7 != 0) goto LAB_007faee0;
  }
  FUN_007dc1e0(iVar5,uVar8);
  if (bVar2) {
    FUN_007dc140(iVar5,0x6c,local_64,local_30);
    FUN_007dc1e0(iVar5,local_2c);
    FUN_007dc140(iVar5,0x1e,local_64,0);
  }
  else if (param_4 != (undefined4 *)0x0) {
    FUN_007dc140(iVar5,0xb,local_60,0);
    FUN_007dc140(iVar5,0x18,0,0);
    FUN_007dc1e0(iVar5,local_40);
  }
  if (uVar6 == 0) {
    FUN_007dc140(iVar5,0x1e,local_6c,0);
    iVar7 = puVar3[4];
    if (iVar7 != 0) {
      do {
        local_6c = local_6c + 1;
        FUN_007dc140(iVar5,0x1e,local_6c,0);
        iVar7 = *(int *)(iVar7 + 0x1c);
      } while (iVar7 != 0);
    }
  }
  if (*(char *)((int)puVar3 + 0x21) != '\0') {
    iVar7 = param_1[7];
    iVar9 = FUN_007dc320(iVar5);
    FUN_007dc140(iVar5,0x32,*(undefined1 *)((int)puVar3 + 0x1d),0);
    FUN_007dc140(iVar5,9,iVar7,*(undefined4 *)(puVar4[0x19] + 0x14));
    FUN_007dc140(iVar5,0x67,iVar7,2);
    FUN_007dc140(iVar5,1,local_24,0);
    FUN_007dc140(iVar5,0x45,0xffffffff,iVar9 + 7);
    FUN_007dc140(iVar5,0xb,1,0);
    FUN_007dc140(iVar5,0x19,iVar7,0);
    FUN_007dda80(iVar5,0x5a,0,0,*puVar3,0);
    FUN_007dc140(iVar5,1,local_54,0);
    FUN_007dc140(iVar5,0x5b,2,0);
    FUN_007dc140(iVar5,0x71,iVar7,0);
    FUN_007dc140(iVar5,0x1e,iVar7,0);
  }
  if (((*(char *)(iVar1 + 8) < '\0') && (*(char *)((int)param_1 + 0x13) == '\0')) &&
     (param_1[0x28] == 0)) {
    FUN_007dc140(iVar5,1,local_38,0);
    FUN_007dc140(iVar5,0x39,1,0);
    FUN_007dccf0(iVar5,1);
    FUN_007dcd30(iVar5,0,s_rows_inserted_00a0554c,0xfffffffe);
  }
LAB_007faee0:
  FUN_007d3a10(param_2);
  FUN_007ea740(param_3);
  FUN_007e6af0(param_4);
  FUN_007d3980(param_5);
  return;
}


// ==== FUN_007faf20 @ 0x007faf20 ====

uint FUN_007faf20(void)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte *unaff_EBX;
  
  iVar3 = _isdigit((uint)*unaff_EBX);
  if (iVar3 != 0) {
    uVar4 = _atol((char *)unaff_EBX);
    return uVar4;
  }
  pbVar1 = unaff_EBX + 1;
  do {
    bVar2 = *unaff_EBX;
    unaff_EBX = unaff_EBX + 1;
  } while (bVar2 != 0);
  uVar4 = 0;
  do {
    if ((uint)(byte)(&DAT_00a055f0)[uVar4] == (int)unaff_EBX - (int)pbVar1) {
      iVar3 = FUN_007d0930(s_onoffalseyestruefull_00a055d0 + (byte)(&DAT_00a055e8)[uVar4]);
      if (iVar3 == 0) {
        return (uint)*(byte *)(uVar4 + 0xa055f8);
      }
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 7);
  return 1;
}


// ==== FUN_007faf90 @ 0x007faf90 ====

undefined4 FUN_007faf90(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  iVar2 = *(int *)(*(int *)(iVar1 + 4) + 0x74);
  if (iVar2 != 0) {
    if ((*(byte *)(iVar1 + 8) & 8) != 0) {
      FUN_007d0820();
      return 1;
    }
    FUN_007db2b0(iVar2);
    *(undefined4 *)(*(int *)(iVar1 + 4) + 0x74) = 0;
    FUN_007d3fc0(iVar1,0);
  }
  return 0;
}


// ==== FUN_007fafe0 @ 0x007fafe0 ====

undefined4 FUN_007fafe0(void)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *unaff_EDI;
  
  cVar1 = *in_EAX;
  if ((cVar1 < '0') || ('2' < cVar1)) {
    iVar2 = FUN_007d08e0();
    if (iVar2 == 0) {
      uVar4 = 1;
    }
    else {
      iVar2 = FUN_007d08e0();
      uVar4 = (-(uint)(iVar2 != 0) & 0xfffffffe) + 2;
    }
  }
  else {
    uVar4 = (int)cVar1 - 0x30;
  }
  iVar2 = *unaff_EDI;
  if (*(byte *)(iVar2 + 0x13) != uVar4) {
    iVar3 = FUN_007faf90();
    if (iVar3 != 0) {
      return 1;
    }
    *(char *)(iVar2 + 0x13) = (char)uVar4;
  }
  return 0;
}


// ==== FUN_007fb050 @ 0x007fb050 ====

void FUN_007fb050(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EDI;
  
  uVar1 = FUN_007e8190();
  FUN_007dc140(uVar1,0x32,param_2,0);
  if (*(char *)(unaff_EDI + 0x74) == '\0') {
    FUN_007dccf0(uVar1,1);
    FUN_007dcd30(uVar1,0,param_1,0xfffffffe);
  }
  FUN_007dc140(uVar1,0x39,1,0);
  return;
}


// ==== FUN_007fb0a0 @ 0x007fb0a0 ====

undefined4 FUN_007fb0a0(int param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  undefined **ppuVar4;
  
  uVar3 = 0;
  ppuVar4 = &PTR_s_vdbe_trace_00a05600;
  do {
    iVar1 = FUN_007d08e0();
    if (iVar1 == 0) {
      iVar1 = *in_ECX;
      iVar2 = FUN_007e8190();
      if (iVar2 != 0) {
        if (param_1 == 0) {
          FUN_007fb050(*ppuVar4,(*(uint *)(iVar1 + 8) & (uint)ppuVar4[1]) != 0);
        }
        else {
          uVar3 = FUN_007faf20();
          if ((uVar3 & 1) == 0) {
            *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & ~(uint)ppuVar4[1];
          }
          else {
            *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | (uint)ppuVar4[1];
          }
        }
        FUN_007dc140(iVar2,0xf,0,0);
      }
      return 1;
    }
    uVar3 = uVar3 + 1;
    ppuVar4 = ppuVar4 + 2;
  } while (uVar3 < 9);
  return 0;
}


// ==== FUN_007fb140 @ 0x007fb140 ====

void FUN_007fb140(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined **ppuVar1;
  int *piVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  long lVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined **ppuVar14;
  undefined4 *puVar15;
  int iVar16;
  int iVar17;
  char *local_20;
  int *local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_8;
  int local_4;
  
  piVar2 = (int *)*param_1;
  iVar5 = FUN_007e8190(param_1);
  if (iVar5 == 0) {
    return;
  }
  iVar6 = FUN_007d2850(param_1,param_2,param_3,&local_8);
  if (iVar6 < 0) {
    return;
  }
  puVar15 = (undefined4 *)(iVar6 * 0x70 + piVar2[1]);
  pcVar7 = (char *)FUN_007d2730(local_8);
  if (pcVar7 == (char *)0x0) {
    return;
  }
  if (param_5 == 0) {
    pcVar8 = (char *)FUN_007d2730(param_4);
  }
  else {
    pcVar8 = (char *)FUN_007e4830(&PTR___break_00a05aac,param_4);
  }
  if (iVar6 < 1) {
    local_1c = (int *)0x0;
  }
  else {
    local_1c = (int *)*puVar15;
  }
  iVar9 = FUN_007ed5e0(param_1,0x13,pcVar7,pcVar8,local_1c);
  local_20 = pcVar8;
  if (iVar9 == 0) {
    iVar9 = FUN_007d08e0(pcVar7,s_default_cache_size_00a05a98);
    if (iVar9 == 0) {
      iVar9 = FUN_007ce9f0(param_1);
      if (iVar9 != 0) goto LAB_007fc1b8;
      if (pcVar8 == (char *)0x0) {
        FUN_007dccf0(iVar5,1);
        FUN_007dcd30(iVar5,0,s_cache_size_00a05a8c,0xfffffffe);
        iVar9 = FUN_007dc330(iVar5,7,&DAT_00a05648);
        FUN_007dc3d0(iVar5,iVar9,iVar6);
        FUN_007dc3d0(iVar5,iVar9 + 5,2000);
      }
      else {
        lVar10 = _atol(pcVar8);
        if (lVar10 < 0) {
          lVar10 = -lVar10;
        }
        FUN_007d3d30(param_1,0,iVar6);
        FUN_007dc140(iVar5,0x32,lVar10,0);
        FUN_007dc140(iVar5,0x73,iVar6,2);
        iVar9 = FUN_007dc140(iVar5,0x32,0,0);
        FUN_007dc140(iVar5,0x4b,0,iVar9 + 3);
        FUN_007dc140(iVar5,0x57,0,0);
        FUN_007dc140(iVar5,3,iVar6,2);
        puVar15[0x18] = lVar10;
        FUN_007d6640(puVar15[1],lVar10);
      }
    }
    else {
      iVar9 = FUN_007d08e0(pcVar7,s_page_size_00a05a80);
      if (iVar9 == 0) {
        iVar6 = puVar15[1];
        if (pcVar8 == (char *)0x0) {
          if (iVar6 == 0) {
            uVar11 = 0;
          }
          else {
            uVar11 = FUN_007d66e0(iVar6);
          }
          FUN_007fb050(s_page_size_00a05a80,uVar11);
        }
        else {
          uVar11 = 0xffffffff;
          lVar10 = _atol(pcVar8);
          FUN_007d6680(iVar6,lVar10,uVar11);
        }
      }
      else {
        iVar9 = FUN_007d08e0(pcVar7,s_auto_vacuum_00a05a74);
        if (iVar9 == 0) {
          iVar6 = puVar15[1];
          if (pcVar8 == (char *)0x0) {
            if (iVar6 == 0) {
              uVar11 = 0;
            }
            else {
              uVar11 = FUN_007d6720(iVar6);
            }
            FUN_007fb050(s_auto_vacuum_00a05a74,uVar11);
          }
          else {
            uVar12 = FUN_007faf20();
            FUN_007d6700(iVar6,uVar12 & 1);
          }
        }
        else {
          iVar9 = FUN_007d08e0(pcVar7,s_cache_size_00a05a8c);
          if (iVar9 == 0) {
            iVar6 = FUN_007ce9f0(param_1);
            if (iVar6 != 0) goto LAB_007fc1b8;
            if (pcVar8 == (char *)0x0) {
              FUN_007fb050(s_cache_size_00a05a8c,puVar15[0x18]);
            }
            else {
              lVar10 = _atol(pcVar8);
              if (lVar10 < 0) {
                lVar10 = -lVar10;
              }
              puVar15[0x18] = lVar10;
              FUN_007d6640(puVar15[1],lVar10);
            }
          }
          else {
            iVar9 = FUN_007d08e0(pcVar7,s_temp_store_00a05a68);
            if (iVar9 == 0) {
              if (pcVar8 == (char *)0x0) {
                FUN_007fb050(s_temp_store_00a05a68,*(undefined1 *)((int)piVar2 + 0x13));
              }
              else {
                FUN_007fafe0();
              }
            }
            else {
              iVar9 = FUN_007d08e0(pcVar7,s_temp_store_directory_00a05a50);
              if (iVar9 == 0) {
                if (pcVar8 == (char *)0x0) {
                  if (DAT_00b5c4cc != (char *)0x0) {
                    FUN_007dccf0(iVar5,1);
                    FUN_007dcd30(iVar5,0,s_temp_store_directory_00a05a50,0xfffffffe);
                    FUN_007dda80(iVar5,0x5a,0,0,DAT_00b5c4cc,0);
                    FUN_007dc140(iVar5,0x39,1,0);
                  }
                }
                else {
                  if ((*pcVar8 != '\0') && (iVar6 = FUN_007d1800(pcVar8), iVar6 == 0)) {
                    FUN_007d0820(param_1,s_not_a_writable_directory_00a05a34);
                    goto LAB_007fc1b8;
                  }
                  if (*(byte *)((int)piVar2 + 0x13) < 2) {
                    FUN_007faf90();
                  }
                  FUN_007d05b0(DAT_00b5c4cc);
                  if (*pcVar8 == '\0') {
                    DAT_00b5c4cc = (char *)0x0;
                  }
                  else {
                    local_20 = (char *)0x0;
                    DAT_00b5c4cc = pcVar8;
                  }
                }
              }
              else {
                iVar9 = FUN_007d08e0(pcVar7,s_synchronous_00a05a28);
                if (iVar9 == 0) {
                  iVar6 = FUN_007ce9f0(param_1);
                  if (iVar6 != 0) goto LAB_007fc1b8;
                  if (pcVar8 == (char *)0x0) {
                    FUN_007fb050(s_synchronous_00a05a28,*(byte *)((int)puVar15 + 0x5f) - 1);
                  }
                  else if (*(char *)((int)piVar2 + 0x11) == '\0') {
                    FUN_007d0820(param_1,s_Safety_level_may_not_be_changed_i_00a059f0);
                  }
                  else {
                    cVar4 = FUN_007faf20();
                    *(char *)((int)puVar15 + 0x5f) = cVar4 + '\x01';
                    FUN_007d6660(puVar15[1],cVar4 + '\x01');
                  }
                }
                else {
                  iVar9 = FUN_007fb0a0(pcVar8);
                  if (iVar9 == 0) {
                    iVar9 = FUN_007d08e0(pcVar7,s_table_info_00a059e4);
                    if ((iVar9 == 0) && (pcVar8 != (char *)0x0)) {
                      iVar6 = FUN_007ce9f0(param_1);
                      if (iVar6 != 0) goto LAB_007fc1b8;
                      iVar6 = FUN_007d22b0(piVar2,pcVar8,local_1c);
                      if (iVar6 != 0) {
                        FUN_007dccf0(iVar5,6);
                        FUN_007dcd30(iVar5,0,&PTR_LAB_00a059e0,0xfffffffe);
                        FUN_007dcd30(iVar5,1,&DAT_009fcfb0,0xfffffffe);
                        FUN_007dcd30(iVar5,2,&DAT_009fd734,0xfffffffe);
                        FUN_007dcd30(iVar5,3,s_notnull_00a059d8,0xfffffffe);
                        FUN_007dcd30(iVar5,4,s_dflt_value_00a059cc,0xfffffffe);
                        FUN_007dcd30(iVar5,5,&DAT_00a059c8,0xfffffffe);
                        FUN_007d45e0(param_1,iVar6);
                        iVar9 = 0;
                        if (0 < *(int *)(iVar6 + 4)) {
                          iVar16 = 0;
                          do {
                            FUN_007dc140(iVar5,0x32,iVar9,0);
                            FUN_007dda80(iVar5,0x5a,0,0,
                                         *(undefined4 *)(*(int *)(iVar6 + 8) + iVar16),0);
                            pcVar8 = *(char **)(*(int *)(iVar6 + 8) + 8 + iVar16);
                            if (pcVar8 == (char *)0x0) {
                              pcVar8 = s_numeric_009fd6e8;
                            }
                            FUN_007dda80(iVar5,0x5a,0,0,pcVar8,0);
                            FUN_007dc140(iVar5,0x32,
                                         *(undefined1 *)(*(int *)(iVar6 + 8) + 0x10 + iVar16),0);
                            FUN_007ec010(param_1,*(undefined4 *)(*(int *)(iVar6 + 8) + 4 + iVar16));
                            FUN_007dc140(iVar5,0x32,
                                         *(undefined1 *)(*(int *)(iVar6 + 8) + 0x11 + iVar16),0);
                            FUN_007dc140(iVar5,0x39,6,0);
                            iVar9 = iVar9 + 1;
                            iVar16 = iVar16 + 0x14;
                          } while (iVar9 < *(int *)(iVar6 + 4));
                        }
                      }
                    }
                    else {
                      iVar9 = FUN_007d08e0(pcVar7,s_index_info_00a059bc);
                      if ((iVar9 == 0) && (pcVar8 != (char *)0x0)) {
                        iVar6 = FUN_007ce9f0(param_1);
                        if (iVar6 != 0) goto LAB_007fc1b8;
                        iVar6 = FUN_007d23d0(piVar2,pcVar8,local_1c);
                        if (iVar6 != 0) {
                          iVar9 = *(int *)(iVar6 + 0xc);
                          FUN_007dccf0(iVar5,3);
                          FUN_007dcd30(iVar5,0,s_seqno_00a059b4,0xfffffffe);
                          FUN_007dcd30(iVar5,1,&PTR_LAB_00a059e0,0xfffffffe);
                          FUN_007dcd30(iVar5,2,&DAT_009fcfb0,0xfffffffe);
                          iVar16 = 0;
                          if (0 < *(int *)(iVar6 + 4)) {
                            do {
                              iVar17 = *(int *)(*(int *)(iVar6 + 8) + iVar16 * 4);
                              FUN_007dc140(iVar5,0x32,iVar16,0);
                              FUN_007dc140(iVar5,0x32,iVar17,0);
                              FUN_007dda80(iVar5,0x5a,0,0,
                                           *(undefined4 *)(*(int *)(iVar9 + 8) + iVar17 * 0x14),0);
                              FUN_007dc140(iVar5,0x39,3,0);
                              iVar16 = iVar16 + 1;
                            } while (iVar16 < *(int *)(iVar6 + 4));
                          }
                        }
                      }
                      else {
                        iVar9 = FUN_007d08e0(pcVar7,s_index_list_00a059a8);
                        if ((iVar9 == 0) && (pcVar8 != (char *)0x0)) {
                          iVar6 = FUN_007ce9f0(param_1);
                          if (iVar6 != 0) goto LAB_007fc1b8;
                          iVar6 = FUN_007d22b0(piVar2,pcVar8,local_1c);
                          if (iVar6 != 0) {
                            iVar5 = FUN_007e8190(param_1);
                            puVar15 = *(undefined4 **)(iVar6 + 0x10);
                            if (puVar15 != (undefined4 *)0x0) {
                              iVar6 = 0;
                              FUN_007dccf0(iVar5,3);
                              FUN_007dcd30(iVar5,0,&DAT_00a059a4,0xfffffffe);
                              FUN_007dcd30(iVar5,1,&DAT_009fcfb0,0xfffffffe);
                              FUN_007dcd30(iVar5,2,s_unique_00a0599c,0xfffffffe);
                              do {
                                FUN_007dc140(iVar5,0x32,iVar6,0);
                                FUN_007dda80(iVar5,0x5a,0,0,*puVar15,0);
                                FUN_007dc140(iVar5,0x32,*(char *)(puVar15 + 5) != '\0',0);
                                FUN_007dc140(iVar5,0x39,3,0);
                                puVar15 = (undefined4 *)puVar15[7];
                                iVar6 = iVar6 + 1;
                              } while (puVar15 != (undefined4 *)0x0);
                            }
                          }
                        }
                        else {
                          iVar9 = FUN_007d08e0(pcVar7,s_database_list_00a0598c);
                          if (iVar9 == 0) {
                            iVar6 = FUN_007ce9f0(param_1);
                            if (iVar6 != 0) goto LAB_007fc1b8;
                            FUN_007dccf0(iVar5,3);
                            FUN_007dcd30(iVar5,0,&DAT_00a059a4,0xfffffffe);
                            FUN_007dcd30(iVar5,1,&DAT_009fcfb0,0xfffffffe);
                            FUN_007dcd30(iVar5,2,&DAT_009fd7a4,0xfffffffe);
                            iVar6 = 0;
                            if (0 < *piVar2) {
                              iVar9 = 0;
                              do {
                                if (*(int *)(iVar9 + 4 + piVar2[1]) != 0) {
                                  FUN_007dc140(iVar5,0x32,iVar6,0);
                                  FUN_007dda80(iVar5,0x5a,0,0,*(undefined4 *)(iVar9 + piVar2[1]),0);
                                  uVar11 = FUN_007db070(*(undefined4 *)(iVar9 + 4 + piVar2[1]),0);
                                  FUN_007dda80(iVar5,0x5a,0,0,uVar11);
                                  FUN_007dc140(iVar5,0x39,3,0);
                                }
                                iVar6 = iVar6 + 1;
                                iVar9 = iVar9 + 0x70;
                              } while (iVar6 < *piVar2);
                            }
                          }
                          else {
                            iVar9 = FUN_007d08e0(pcVar7,s_collation_list_00a0597c);
                            if (iVar9 == 0) {
                              iVar6 = 0;
                              FUN_007dccf0(iVar5,2);
                              FUN_007dcd30(iVar5,0,&DAT_00a059a4,0xfffffffe);
                              FUN_007dcd30(iVar5,1,&DAT_009fcfb0,0xfffffffe);
                              for (puVar15 = (undefined4 *)piVar2[0x2c];
                                  puVar15 != (undefined4 *)0x0; puVar15 = (undefined4 *)*puVar15) {
                                puVar3 = (undefined4 *)puVar15[2];
                                FUN_007dc140(iVar5,0x32,iVar6,0);
                                iVar6 = iVar6 + 1;
                                FUN_007dda80(iVar5,0x5a,0,0,*puVar3,0);
                                FUN_007dc140(iVar5,0x39,2,0);
                              }
                            }
                            else {
                              iVar9 = FUN_007d08e0(pcVar7,s_foreign_key_list_00a05968);
                              if ((iVar9 == 0) && (pcVar8 != (char *)0x0)) {
                                iVar6 = FUN_007ce9f0(param_1);
                                if (iVar6 != 0) goto LAB_007fc1b8;
                                iVar6 = FUN_007d22b0(piVar2,pcVar8,local_1c);
                                if (iVar6 != 0) {
                                  iVar5 = FUN_007e8190(param_1);
                                  iVar9 = *(int *)(iVar6 + 0x2c);
                                  if (iVar9 != 0) {
                                    iVar16 = 0;
                                    FUN_007dccf0(iVar5,5);
                                    FUN_007dcd30(iVar5,0,&DAT_00a05964,0xfffffffe);
                                    FUN_007dcd30(iVar5,1,&DAT_00a059a4,0xfffffffe);
                                    FUN_007dcd30(iVar5,2,s_table_009fda44,0xfffffffe);
                                    FUN_007dcd30(iVar5,3,&DAT_00a0595c,0xfffffffe);
                                    FUN_007dcd30(iVar5,4,&DAT_00a05958,0xfffffffe);
                                    do {
                                      iVar17 = 0;
                                      if (0 < *(int *)(iVar9 + 0x10)) {
                                        do {
                                          FUN_007dc140(iVar5,0x32,iVar16,0);
                                          FUN_007dc140(iVar5,0x32,iVar17,0);
                                          FUN_007dda80(iVar5,0x5a,0,0,*(undefined4 *)(iVar9 + 8),0);
                                          FUN_007dda80(iVar5,0x5a,0,0,
                                                       *(undefined4 *)
                                                        (*(int *)(iVar6 + 8) +
                                                        *(int *)(*(int *)(iVar9 + 0x14) + iVar17 * 8
                                                                ) * 0x14),0);
                                          FUN_007dda80(iVar5,0x5a,0,0,
                                                       *(undefined4 *)
                                                        (*(int *)(iVar9 + 0x14) + 4 + iVar17 * 8),0)
                                          ;
                                          FUN_007dc140(iVar5,0x39,5,0);
                                          iVar17 = iVar17 + 1;
                                        } while (iVar17 < *(int *)(iVar9 + 0x10));
                                      }
                                      iVar9 = *(int *)(iVar9 + 4);
                                      iVar16 = iVar16 + 1;
                                    } while (iVar9 != 0);
                                  }
                                }
                              }
                              else {
                                iVar9 = FUN_007d08e0(pcVar7,s_integrity_check_00a05948);
                                if (iVar9 == 0) {
                                  iVar6 = FUN_007ce9f0(param_1);
                                  if (iVar6 != 0) goto LAB_007fc1b8;
                                  FUN_007dccf0(iVar5,1);
                                  FUN_007dcd30(iVar5,0,s_integrity_check_00a05948,0xfffffffe);
                                  FUN_007dc330(iVar5,2,&DAT_00a05680);
                                  local_18 = 0;
                                  if (0 < *piVar2) {
                                    local_10 = 0;
                                    do {
                                      iVar6 = 0;
                                      FUN_007d3cc0(param_1,local_18);
                                      local_1c = *(int **)(local_10 + 0x14 + piVar2[1]);
                                      if (local_1c != (int *)0x0) {
                                        do {
                                          iVar9 = local_1c[2];
                                          FUN_007dc140(iVar5,0x32,*(undefined4 *)(iVar9 + 0x14),0);
                                          for (iVar9 = *(int *)(iVar9 + 0x10); iVar6 = iVar6 + 1,
                                              iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x1c)) {
                                            iVar16 = FUN_007d2c00(param_1,iVar9);
                                            if (iVar16 != 0) goto LAB_007fc1b8;
                                            FUN_007dc140(iVar5,0x32,*(undefined4 *)(iVar9 + 0x10),0)
                                            ;
                                          }
                                          local_1c = (int *)*local_1c;
                                        } while (local_1c != (int *)0x0);
                                      }
                                      FUN_007dc140(iVar5,0x14,iVar6,local_18);
                                      FUN_007dc140(iVar5,0x60,0,1);
                                      iVar6 = FUN_007dda80(iVar5,0x5a,0,0,&DAT_00a00f60,0xfffffffe);
                                      FUN_007dc140(iVar5,0x47,0,iVar6 + 6);
                                      uVar11 = FUN_007e4830(s_____in_database__s_____00a05930,
                                                            *(undefined4 *)(local_10 + piVar2[1]),
                                                            0xffffffff);
                                      FUN_007dda80(iVar5,0x5a,0,0,uVar11);
                                      FUN_007dc140(iVar5,0x66,1,0);
                                      FUN_007dc140(iVar5,0x56,0,1);
                                      FUN_007dc140(iVar5,0x39,1,0);
                                      FUN_007d3cc0(param_1,local_18);
                                      local_1c = *(int **)(local_10 + 0x14 + piVar2[1]);
                                      if (local_1c != (int *)0x0) {
                                        do {
                                          iVar6 = local_1c[2];
                                          local_4 = iVar6;
                                          if (*(int *)(iVar6 + 0x10) != 0) {
                                            FUN_007fa110(param_1,iVar6,1,0xe);
                                            FUN_007dc140(iVar5,0x32,0,0);
                                            FUN_007dc140(iVar5,0x78,1,1);
                                            iVar9 = FUN_007dc140(iVar5,0x79,1,0);
                                            FUN_007dc140(iVar5,0x2f,1,0);
                                            puVar15 = *(undefined4 **)(iVar6 + 0x10);
                                            if (puVar15 != (undefined4 *)0x0) {
                                              iVar6 = 2;
                                              do {
                                                FUN_007ecd40(iVar5,puVar15,1);
                                                uVar11 = FUN_007dc140(iVar5,0x7b,iVar6,0);
                                                iVar16 = FUN_007dc330(iVar5,7,&DAT_00a056b8);
                                                FUN_007dc430(iVar5,iVar16 + 4,*puVar15,0xfffffffe);
                                                uVar13 = FUN_007dc320(iVar5);
                                                FUN_007dc400(iVar5,uVar11,uVar13);
                                                puVar15 = (undefined4 *)puVar15[7];
                                                iVar6 = iVar6 + 1;
                                              } while (puVar15 != (undefined4 *)0x0);
                                            }
                                            FUN_007dc140(iVar5,0x6c,1,iVar9 + 1);
                                            uVar11 = FUN_007dc320(iVar5);
                                            FUN_007dc400(iVar5,iVar9,uVar11);
                                            puVar15 = *(undefined4 **)(local_4 + 0x10);
                                            if (puVar15 != (undefined4 *)0x0) {
                                              local_14 = 2;
                                              do {
                                                if (puVar15[4] != 0) {
                                                  iVar6 = FUN_007dc330(iVar5,0xd,&DAT_00a056f0);
                                                  FUN_007dc3d0(iVar5,iVar6 + 2,local_14);
                                                  FUN_007dc400(iVar5,iVar6 + 2,iVar6 + 5);
                                                  FUN_007dc3d0(iVar5,iVar6 + 4,local_14);
                                                  FUN_007dc400(iVar5,iVar6 + 4,iVar6 + 3);
                                                  FUN_007dc400(iVar5,iVar6 + 7,iVar6 + 0xd);
                                                  FUN_007dc430(iVar5,iVar6 + 10,*puVar15,0xfffffffe)
                                                  ;
                                                }
                                                puVar15 = (undefined4 *)puVar15[7];
                                                local_14 = local_14 + 1;
                                              } while (puVar15 != (undefined4 *)0x0);
                                            }
                                          }
                                          local_1c = (int *)*local_1c;
                                        } while (local_1c != (int *)0x0);
                                      }
                                      local_18 = local_18 + 1;
                                      local_10 = local_10 + 0x70;
                                    } while (local_18 < *piVar2);
                                  }
                                  iVar6 = FUN_007dc330(iVar5,5,&DAT_00a05690);
                                  FUN_007dc400(iVar5,iVar6 + 2,iVar6 + 5);
                                }
                                else {
                                  iVar9 = FUN_007d08e0(pcVar7,s_encoding_00a05924);
                                  if (iVar9 == 0) {
                                    DAT_00b492dc = (DAT_009ff8b0 == '\0') + '\x02';
                                    DAT_00b492e4 = DAT_00b492dc;
                                    if (pcVar8 == (char *)0x0) {
                                      iVar6 = FUN_007ce9f0(param_1);
                                      if (iVar6 != 0) goto LAB_007fc1b8;
                                      FUN_007dccf0(iVar5,1);
                                      FUN_007dcd30(iVar5,0,s_encoding_00a05924,0xfffffffe);
                                      FUN_007dc140(iVar5,0x5a,0,0);
                                      ppuVar14 = &PTR_s_UTF_8_00b492a8;
                                      if (PTR_s_UTF_8_00b492a8 == (undefined *)0x0) {
LAB_007fc065:
                                        FUN_007dc140(iVar5,0x39,1,0);
                                      }
                                      else {
                                        do {
                                          if (*(char *)(ppuVar14 + 1) == *(char *)(*param_1 + 0x10))
                                          {
                                            FUN_007dc430(iVar5,0xffffffff,*ppuVar14,0xfffffffe);
                                            goto LAB_007fc065;
                                          }
                                          ppuVar1 = ppuVar14 + 2;
                                          ppuVar14 = ppuVar14 + 2;
                                        } while (*ppuVar1 != (undefined *)0x0);
                                        FUN_007dc140(iVar5,0x39,1,0);
                                      }
                                    }
                                    else if ((*(byte *)(*param_1 + 8) & 2) == 0) {
                                      ppuVar14 = &PTR_s_UTF_8_00b492a8;
                                      if (PTR_s_UTF_8_00b492a8 == (undefined *)0x0) {
LAB_007fc0d8:
                                        FUN_007d0820(param_1,s_unsupported_encoding___s_00a05908,
                                                     pcVar8);
                                      }
                                      else {
                                        do {
                                          iVar6 = FUN_007d08e0(pcVar8,*ppuVar14);
                                          if (iVar6 == 0) {
                                            *(undefined1 *)(*param_1 + 0x10) =
                                                 *(undefined1 *)(ppuVar14 + 1);
                                            if (*ppuVar14 != (undefined *)0x0) goto LAB_007fc1a5;
                                            goto LAB_007fc0d8;
                                          }
                                          ppuVar1 = ppuVar14 + 2;
                                          ppuVar14 = ppuVar14 + 2;
                                        } while (*ppuVar1 != (undefined *)0x0);
                                        FUN_007d0820(param_1,s_unsupported_encoding___s_00a05908,
                                                     pcVar8);
                                      }
                                    }
                                  }
                                  else {
                                    iVar9 = FUN_007d08e0(pcVar7,s_schema_version_00a058f8);
                                    if ((iVar9 == 0) ||
                                       (iVar9 = FUN_007d08e0(pcVar7,s_user_version_00a058e8),
                                       iVar9 == 0)) {
                                      if ((*pcVar7 == 's') || (param_1 = (int *)0x5, *pcVar7 == 'S')
                                         ) {
                                        param_1 = (int *)0x0;
                                      }
                                      if (pcVar8 == (char *)0x0) {
                                        uVar11 = FUN_007dc330(iVar5,2,&DAT_00a05770);
                                        FUN_007dc3d0(iVar5,uVar11,iVar6);
                                        FUN_007dc400(iVar5,uVar11,param_1);
                                        FUN_007dccf0(iVar5,1);
                                      }
                                      else {
                                        iVar9 = FUN_007dc330(iVar5,3,&DAT_00a05758);
                                        FUN_007dc3d0(iVar5,iVar9,iVar6);
                                        lVar10 = _atol(pcVar8);
                                        FUN_007dc3d0(iVar5,iVar9 + 1,lVar10);
                                        FUN_007dc3d0(iVar5,iVar9 + 2,iVar6);
                                        FUN_007dc400(iVar5,iVar9 + 2,param_1);
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
LAB_007fc1a5:
    if (iVar5 != 0) {
      FUN_007dc140(iVar5,0xf,1,0);
    }
  }
LAB_007fc1b8:
  FUN_007d05b0(pcVar7);
  FUN_007d05b0(local_20);
  return;
}


// ==== FUN_007fc1e0 @ 0x007fc1e0 ====

int FUN_007fc1e0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 < 1) {
    return 0;
  }
  if ((param_1[1] < *param_1 + param_2) &&
     (iVar1 = FUN_007f6030(param_1,*param_1 + param_2), iVar1 != 0)) {
    return iVar1;
  }
  *param_1 = *param_1 + param_2;
  iVar1 = *param_1;
  puVar2 = (undefined4 *)(param_1[3] + -4 + iVar1 * 4);
  puVar3 = (undefined4 *)(param_1[3] + -4 + (iVar1 - param_2) * 4);
  if (param_2 <= iVar1 + -1) {
    iVar1 = ((iVar1 + -1) - param_2) + 1;
    do {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + -1;
      puVar3 = puVar3 + -1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  if (0 < param_2) {
    puVar2 = (undefined4 *)param_1[3];
    for (; param_2 != 0; param_2 = param_2 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
  }
  return 0;
}


// ==== FUN_007fc260 @ 0x007fc260 ====

int FUN_007fc260(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 != param_2) {
    if ((param_2[1] < *param_1) && (iVar1 = FUN_007f6030(param_2,*param_1), iVar1 != 0)) {
      return iVar1;
    }
    puVar3 = (undefined4 *)param_1[3];
    puVar2 = (undefined4 *)param_2[3];
    iVar1 = 0;
    if (0 < *param_1) {
      do {
        *puVar2 = *puVar3;
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar1 < *param_1);
    }
    if (iVar1 < *param_2) {
      do {
        *puVar2 = 0;
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar1 < *param_2);
    }
    *param_2 = *param_1;
    param_2[2] = param_1[2];
  }
  return 0;
}


// ==== FUN_007fc2d0 @ 0x007fc2d0 ====

void FUN_007fc2d0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = *param_1;
  uVar2 = param_1[3];
  uVar3 = param_1[1];
  uVar4 = param_1[2];
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  *param_2 = uVar1;
  param_2[1] = uVar3;
  param_2[2] = uVar4;
  param_2[3] = uVar2;
  return;
}


// ==== FUN_007fc310 @ 0x007fc310 ====

void FUN_007fc310(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (0 < param_2) {
    if (*param_1 <= param_2) {
      FUN_007f5ff0(param_1);
      return;
    }
    puVar1 = (undefined4 *)param_1[3];
    iVar2 = 0;
    puVar3 = puVar1 + param_2;
    if (0 < *param_1 - param_2) {
      do {
        *puVar1 = *puVar3;
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar2 < *param_1 - param_2);
    }
    if (iVar2 < *param_1) {
      do {
        *puVar1 = 0;
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 1;
      } while (iVar2 < *param_1);
    }
    *param_1 = *param_1 - param_2;
  }
  return;
}


// ==== FUN_007fc380 @ 0x007fc380 ====

int FUN_007fc380(int *param_1,uint param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  
  if ((int)param_2 < 1) {
    FUN_007f5ff0(param_3);
    return 0;
  }
  if (*param_1 * 0x1c <= (int)param_2) {
    iVar2 = FUN_007fc260(param_1,param_3);
    return iVar2;
  }
  iVar2 = FUN_007fc260(param_1,param_3);
  if (iVar2 == 0) {
    iVar2 = (uint)((int)param_2 % 0x1c != 0) + (int)param_2 / 0x1c;
    if (iVar2 < *param_3) {
      do {
        *(undefined4 *)(param_3[3] + iVar2 * 4) = 0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < *param_3);
    }
    puVar1 = (uint *)(param_3[3] + ((int)param_2 / 0x1c) * 4);
    *puVar1 = *puVar1 & (1 << ((char)param_2 + (char)(param_2 / 0x1c) * -0x1c & 0x1fU)) - 1U;
    FUN_007f5ec0(param_3);
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_007fc470 @ 0x007fc470 ====

void FUN_007fc470(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = *param_2;
  iVar2 = *param_1;
  uVar3 = (uint)(param_1[2] != param_2[2]);
  iVar4 = iVar2;
  if (iVar1 <= iVar2) {
    iVar4 = iVar1;
  }
  if (DAT_00b492f8 <= iVar4) {
    FUN_007fddb0(param_1,param_2,param_3);
    param_3[2] = (*param_3 < 1) - 1 & uVar3;
    return;
  }
  iVar4 = iVar2;
  if (iVar1 <= iVar2) {
    iVar4 = iVar1;
  }
  if (DAT_00b492f0 <= iVar4) {
    FUN_007fda80(param_1,param_2,param_3);
    param_3[2] = (*param_3 < 1) - 1 & uVar3;
    return;
  }
  iVar4 = iVar1 + 1 + iVar2;
  if (iVar4 < 0x200) {
    if (iVar1 <= iVar2) {
      iVar2 = iVar1;
    }
    if (iVar2 < 0x101) {
      FUN_007fd940(param_1,param_2,param_3,iVar4);
      goto LAB_007fc523;
    }
  }
  FUN_007fd7f0(param_1,param_2,param_3,iVar4);
LAB_007fc523:
  param_3[2] = (*param_3 < 1) - 1 & uVar3;
  return;
}


// ==== FUN_007fc540 @ 0x007fc540 ====

void FUN_007fc540(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (DAT_00b492fc <= iVar1) {
    FUN_007feb90(param_1,param_2);
    *(undefined4 *)(param_2 + 8) = 0;
    return;
  }
  if (DAT_00b492f4 <= iVar1) {
    FUN_007fe930(param_1,param_2);
    *(undefined4 *)(param_2 + 8) = 0;
    return;
  }
  if ((iVar1 * 2 + 1 < 0x200) && (iVar1 < 0x80)) {
    FUN_007fe7a0(param_1,param_2);
    *(undefined4 *)(param_2 + 8) = 0;
    return;
  }
  FUN_007fe610(param_1,param_2);
  *(undefined4 *)(param_2 + 8) = 0;
  return;
}


// ==== FUN_007fc5d0 @ 0x007fc5d0 ====

int FUN_007fc5d0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_10 [8];
  int local_8;
  
  iVar1 = FUN_007f6f20(local_10);
  if (iVar1 == 0) {
    iVar1 = FUN_007ff210(param_1,param_2,0,local_10);
    if (iVar1 == 0) {
      if (local_8 != *(int *)(param_2 + 8)) {
        iVar1 = FUN_007ff1a0(param_2,local_10,param_3);
        FUN_007f60a0(local_10);
        return iVar1;
      }
      iVar1 = 0;
      FUN_007fc2d0(local_10,param_3);
    }
    FUN_007f60a0(local_10);
  }
  return iVar1;
}


// ==== FUN_007fc660 @ 0x007fc660 ====

void FUN_007fc660(uint *param_1,uint param_2)

{
  FUN_007f5ff0(param_1);
  *(uint *)param_1[3] = param_2 & 0xfffffff;
  *param_1 = (uint)(*(int *)param_1[3] != 0);
  return;
}


// ==== FUN_007fc690 @ 0x007fc690 ====

int FUN_007fc690(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 local_10 [16];
  
  iVar1 = FUN_007f6f20(local_10);
  if (iVar1 == 0) {
    iVar1 = FUN_007fc470(param_1,param_2,local_10);
    if (iVar1 != 0) {
      FUN_007f60a0(local_10);
      return iVar1;
    }
    iVar1 = FUN_007fc5d0(local_10,param_3,param_4);
    FUN_007f60a0(local_10);
  }
  return iVar1;
}


// ==== FUN_007fc700 @ 0x007fc700 ====

int FUN_007fc700(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_007fcda0(param_2);
  iVar1 = iVar1 % 0x1c;
  if (*param_2 < 2) {
    FUN_007fc660(param_1,1);
    iVar1 = 1;
  }
  else {
    iVar2 = FUN_007ff8b0(param_1,iVar1 + -0x1d + *param_2 * 0x1c);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  iVar1 = iVar1 + -1;
  while( true ) {
    if (0x1b < iVar1) {
      return 0;
    }
    iVar2 = FUN_007ff810(param_1,param_1);
    if (iVar2 != 0) break;
    iVar2 = FUN_007f6f70(param_1,param_2);
    if ((iVar2 != -1) && (iVar2 = FUN_007ff740(param_1,param_2,param_1), iVar2 != 0)) {
      return iVar2;
    }
    iVar1 = iVar1 + 1;
  }
  return iVar2;
}


// ==== FUN_007fc860 @ 0x007fc860 ====

int FUN_007fc860(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_10 [12];
  undefined4 *local_4;
  
  iVar1 = FUN_007f6f20(local_10);
  if (iVar1 != 0) {
    return iVar1;
  }
  uVar2 = FUN_007fcda0(param_1);
  iVar1 = FUN_007ff8b0(local_10,uVar2);
  if ((iVar1 == 0) && (iVar1 = FUN_007ff740(local_10,param_1,local_10), iVar1 == 0)) {
    *param_2 = *local_4;
    FUN_007f60a0(local_10);
    return 0;
  }
  FUN_007f60a0(local_10);
  return iVar1;
}


// ==== FUN_007fc8f0 @ 0x007fc8f0 ====

int FUN_007fc8f0(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  undefined8 uVar8;
  int local_4;
  
  iVar1 = *param_2;
  if ((iVar1 * 2 <= param_1[1]) || (iVar2 = FUN_007f6030(param_1,iVar1 * 2), iVar2 == 0)) {
    while( true ) {
      puVar6 = (uint *)param_1[3];
      puVar5 = puVar6 + iVar1;
      uVar7 = 0;
      if (0 < iVar1) {
        local_4 = iVar1;
        do {
          uVar8 = __allmul(*puVar5,0,param_3,0);
          uVar3 = (uint)uVar8 + *puVar6;
          uVar4 = uVar3 + uVar7;
          uVar7 = uVar4 >> 0x1c |
                  ((int)((ulonglong)uVar8 >> 0x20) + (uint)CARRY4((uint)uVar8,*puVar6) +
                  (uint)CARRY4(uVar3,uVar7)) * 0x10;
          *puVar6 = uVar4 & 0xfffffff;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
          local_4 = local_4 + -1;
        } while (local_4 != 0);
      }
      *puVar6 = uVar7;
      iVar2 = iVar1 + 1;
      if (iVar2 < *param_1) {
        do {
          puVar6 = puVar6 + 1;
          *puVar6 = 0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *param_1);
      }
      FUN_007f5ec0(param_1);
      iVar2 = FUN_007f6f70(param_1,param_2);
      if (iVar2 == -1) break;
      FUN_007ff740(param_1,param_2,param_1);
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_007fc9e0 @ 0x007fc9e0 ====

void FUN_007fc9e0(int param_1,int *param_2)

{
  *param_2 = 0x10000000 - **(int **)(param_1 + 0xc);
  return;
}


// ==== FUN_007fca00 @ 0x007fca00 ====

int FUN_007fca00(int *param_1,int *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined4 *local_c;
  int local_8;
  int local_4;
  
  iVar2 = *param_2 * 2 + 1;
  if ((iVar2 < 0x200) && (*param_2 < 0x100)) {
    iVar2 = FUN_007fcb50(param_1,param_2,param_3);
    return iVar2;
  }
  if ((iVar2 <= param_1[1]) || (iVar3 = FUN_007f6030(param_1,iVar2), iVar3 == 0)) {
    *param_1 = iVar2;
    iVar2 = *param_2;
    local_4 = 0;
    if (0 < iVar2) {
      do {
        iVar3 = *(int *)(param_1[3] + local_4 * 4);
        puVar6 = (uint *)(param_1[3] + local_4 * 4);
        local_c = (undefined4 *)param_2[3];
        uVar7 = 0;
        local_8 = 0;
        if (0 < iVar2) {
          do {
            uVar8 = __allmul(*local_c,0,iVar3 * param_3 & 0xfffffff,0);
            uVar1 = *puVar6;
            uVar4 = (uint)uVar8 + uVar1;
            uVar5 = uVar4 + uVar7;
            local_c = local_c + 1;
            *puVar6 = uVar5 & 0xfffffff;
            uVar7 = uVar5 >> 0x1c |
                    ((int)((ulonglong)uVar8 >> 0x20) + (uint)CARRY4((uint)uVar8,uVar1) +
                    (uint)CARRY4(uVar4,uVar7)) * 0x10;
            local_8 = local_8 + 1;
            puVar6 = puVar6 + 1;
          } while (local_8 < *param_2);
          for (; uVar7 != 0; uVar7 = uVar7 >> 0x1c) {
            *puVar6 = *puVar6 + uVar7;
            uVar7 = *puVar6;
            *puVar6 = *puVar6 & 0xfffffff;
            puVar6 = puVar6 + 1;
          }
        }
        iVar2 = *param_2;
        local_4 = local_4 + 1;
      } while (local_4 < iVar2);
    }
    FUN_007f5ec0(param_1);
    FUN_007fc310(param_1,*param_2);
    iVar2 = FUN_007f6f70(param_1,param_2);
    if (iVar2 != -1) {
      iVar2 = FUN_007ff740(param_1,param_2,param_1);
      return iVar2;
    }
    iVar3 = 0;
  }
  return iVar3;
}


// ==== FUN_007fcb50 @ 0x007fcb50 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_007fcb50(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined8 uVar12;
  int local_101c;
  int local_1018;
  uint local_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0x7fcb5a;
  iVar9 = *param_1;
  if ((*param_2 + 1 <= param_1[1]) || (iVar3 = FUN_007f6030(param_1,*param_2 + 1), iVar3 == 0)) {
    puVar5 = (uint *)param_1[3];
    iVar3 = 0;
    puVar8 = local_1000;
    if (0 < *param_1) {
      iVar3 = *param_1;
      iVar6 = iVar3;
      do {
        *puVar8 = *puVar5;
        puVar8[1] = 0;
        puVar8 = puVar8 + 2;
        puVar5 = puVar5 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    iVar1 = *param_2;
    iVar6 = iVar1 * 2 + 1;
    if (iVar3 < iVar6) {
      *puVar8 = 0;
      puVar8[1] = 0;
      puVar5 = puVar8 + 2;
      for (uVar7 = (iVar6 - iVar3) * 8 - 5U >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar5 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    iVar3 = 0;
    if (0 < iVar1) {
      puVar2 = (undefined4 *)param_2[3];
      puVar8 = local_1000;
      local_1018 = iVar1;
      do {
        uVar7 = *puVar8;
        if (0 < iVar1) {
          puVar10 = puVar2;
          puVar5 = puVar8;
          local_101c = iVar1;
          do {
            uVar12 = __allmul(*puVar10,0,uVar7 * param_3 & 0xfffffff,0);
            uVar4 = *puVar5;
            *puVar5 = *puVar5 + (uint)uVar12;
            puVar5[1] = puVar5[1] + (int)((ulonglong)uVar12 >> 0x20) +
                        (uint)CARRY4(uVar4,(uint)uVar12);
            puVar10 = puVar10 + 1;
            puVar5 = puVar5 + 2;
            local_101c = local_101c + -1;
          } while (local_101c != 0);
        }
        uVar4 = *puVar8 >> 0x1c | puVar8[1] << 4;
        puVar5 = puVar8 + 2;
        uVar7 = *puVar5;
        *puVar5 = *puVar5 + uVar4;
        puVar8[3] = puVar8[3] + (puVar8[1] >> 0x1c) + (uint)CARRY4(uVar7,uVar4);
        puVar8 = puVar8 + 2;
        local_1018 = local_1018 + -1;
      } while (local_1018 != 0);
      iVar3 = iVar1;
    }
    puVar8 = local_1000 + iVar3 * 2;
    iVar3 = iVar3 + 1;
    puVar5 = local_1000 + iVar3 * 2;
    if (iVar3 <= iVar6) {
      iVar3 = (iVar6 - iVar3) + 1;
      do {
        uVar4 = puVar8[1];
        uVar11 = *puVar8 >> 0x1c | uVar4 << 4;
        uVar7 = *puVar5;
        *puVar5 = *puVar5 + uVar11;
        puVar5[1] = puVar5[1] + (uVar4 >> 0x1c) + (uint)CARRY4(uVar7,uVar11);
        puVar8 = puVar8 + 2;
        puVar5 = puVar5 + 2;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    puVar5 = (uint *)param_1[3];
    puVar8 = local_1000 + iVar1 * 2;
    iVar3 = 0;
    if (0 < iVar1 + 1) {
      do {
        *puVar5 = *puVar8 & 0xfffffff;
        iVar3 = iVar3 + 1;
        puVar5 = puVar5 + 1;
        puVar8 = puVar8 + 2;
      } while (iVar3 < *param_2 + 1);
    }
    if (iVar3 < iVar9) {
      for (iVar9 = iVar9 - iVar3; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
    }
    *param_1 = *param_2 + 1;
    FUN_007f5ec0(param_1);
    iVar9 = FUN_007f6f70(param_1,param_2);
    if (iVar9 != -1) {
      iVar9 = FUN_007ff740(param_1,param_2,param_1);
      return iVar9;
    }
    iVar3 = 0;
  }
  return iVar3;
}


// ==== FUN_007fcd40 @ 0x007fcd40 ====

undefined4 FUN_007fcd40(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = **(uint **)(param_1 + 0xc);
  if ((uVar1 & 1) == 0) {
    return 0xfffffffd;
  }
  iVar2 = (uVar1 * 2 + 4 & 8) + uVar1;
  iVar2 = (2 - iVar2 * uVar1) * iVar2;
  iVar2 = (2 - iVar2 * uVar1) * iVar2;
  *param_2 = -((2 - iVar2 * uVar1) * iVar2) & 0xfffffff;
  return 0;
}


// ==== FUN_007fcda0 @ 0x007fcda0 ====

int FUN_007fcda0(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = iVar1 * 0x1c + -0x1c;
  for (uVar3 = *(uint *)(param_1[3] + -4 + iVar1 * 4); uVar3 != 0; uVar3 = uVar3 >> 1) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


// ==== FUN_007fce90 @ 0x007fce90 ====

int FUN_007fce90(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_10 [16];
  
  iVar1 = FUN_007f6f20(local_10);
  if (iVar1 == 0) {
    uVar2 = FUN_007fcda0(param_1);
    iVar1 = FUN_007ff8b0(local_10,uVar2);
    if (iVar1 == 0) {
      iVar1 = FUN_007ff740(local_10,param_1,param_2);
    }
    FUN_007f60a0(local_10);
  }
  return iVar1;
}


// ==== FUN_007fcef0 @ 0x007fcef0 ====

int FUN_007fcef0(undefined4 param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_10 [16];
  
  uVar1 = *param_2;
  iVar2 = FUN_007f62a0(local_10,param_1);
  if (iVar2 != 0) {
    return iVar2;
  }
  FUN_007fc310(local_10,uVar1 - 1);
  if (uVar1 < 0x8000001) {
    iVar2 = FUN_007ffb70(local_10,param_3,local_10,uVar1);
  }
  else {
    iVar2 = FUN_007fc470(local_10,param_3,local_10);
  }
  if (iVar2 == 0) {
    iVar4 = uVar1 + 1;
    FUN_007fc310(local_10,iVar4);
    iVar2 = FUN_007fc380(param_1,(uVar1 + 1) * 0x1c,param_1);
    if (((iVar2 == 0) && (iVar2 = FUN_007fd7f0(local_10,param_2,local_10,iVar4), iVar2 == 0)) &&
       (iVar2 = FUN_007ffb00(param_1,local_10,param_1), iVar2 == 0)) {
      iVar3 = FUN_007ffad0(param_1,0);
      if (iVar3 == -1) {
        FUN_007fc660(local_10,1);
        iVar2 = FUN_007fc1e0(local_10,iVar4);
        if ((iVar2 != 0) || (iVar2 = FUN_007ff1a0(param_1,local_10,param_1), iVar2 != 0))
        goto LAB_007fd039;
      }
      iVar4 = FUN_007e6310(param_1,param_2);
      while ((iVar4 != -1 && (iVar2 = FUN_007ff740(param_1,param_2,param_1), iVar2 == 0))) {
        iVar4 = FUN_007e6310(param_1,param_2);
      }
    }
  }
LAB_007fd039:
  FUN_007f60a0(local_10);
  return iVar2;
}


// ==== FUN_007fd050 @ 0x007fd050 ====

void FUN_007fd050(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_007ff8b0(param_1,*param_2 * 0x38);
  if (iVar1 == 0) {
    FUN_007ff210(param_1,param_2,param_1,0);
  }
  return;
}


// ==== FUN_007fd090 @ 0x007fd090 ====

int FUN_007fd090(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  int local_80 [3];
  byte *local_74;
  int local_70 [3];
  byte *local_64;
  int local_60 [3];
  byte *local_54;
  int local_50 [3];
  byte *local_44;
  int local_40 [3];
  byte *local_34;
  int local_30 [3];
  byte *local_24;
  int local_20 [3];
  byte *local_14;
  int local_10 [3];
  byte *local_4;
  
  if ((param_2[2] == 1) || (*param_2 == 0)) {
    iVar1 = -3;
  }
  else {
    iVar1 = FUN_007ffd80(local_10,local_20,local_40,local_50,local_60,local_30,local_80,local_70,0);
    if (iVar1 == 0) {
      iVar1 = FUN_007fc5d0(param_1,param_2,local_10);
      if ((iVar1 == 0) && (iVar1 = FUN_007fc260(param_2,local_20), iVar1 == 0)) {
        if ((local_10[0] < 1) ||
           ((((*local_4 & 1) != 0 || (local_20[0] < 1)) || ((*local_14 & 1) != 0)))) {
          iVar1 = FUN_007fc260(local_10,local_40);
          if ((iVar1 == 0) && (iVar1 = FUN_007fc260(local_20,local_50), iVar1 == 0)) {
            FUN_007fc660(local_60,1);
            FUN_007fc660(local_70,1);
            do {
              bVar4 = local_40[0] == 0;
              while ((bVar4 || local_40[0] < 0 || ((*local_34 & 1) != 0))) {
                while ((0 < local_50[0] && ((*local_44 & 1) == 0))) {
                  iVar1 = FUN_007ffce0(local_50,local_50);
                  if (((iVar1 != 0) ||
                      ((((0 < local_80[0] && ((*local_74 & 1) != 0)) ||
                        ((0 < local_70[0] && ((*local_64 & 1) != 0)))) &&
                       ((iVar1 = FUN_007ff1a0(local_80,local_20,local_80), iVar1 != 0 ||
                        (iVar1 = FUN_007ffb00(local_70,local_10,local_70), iVar1 != 0)))))) ||
                     ((iVar1 = FUN_007ffce0(local_80,local_80), iVar1 != 0 ||
                      (iVar1 = FUN_007ffce0(local_70,local_70), iVar1 != 0)))) goto LAB_007fd4c1;
                }
                iVar1 = FUN_007e6310(local_40,local_50);
                if (iVar1 == -1) {
                  iVar1 = FUN_007ffb00(local_50,local_40,local_50);
                  if ((iVar1 != 0) || (iVar1 = FUN_007ffb00(local_80,local_60,local_80), iVar1 != 0)
                     ) goto LAB_007fd4c1;
                  piVar3 = local_70;
                  piVar2 = local_30;
                }
                else {
                  iVar1 = FUN_007ffb00(local_40,local_50,local_40);
                  if ((iVar1 != 0) || (iVar1 = FUN_007ffb00(local_60,local_80,local_60), iVar1 != 0)
                     ) goto LAB_007fd4c1;
                  piVar3 = local_30;
                  piVar2 = local_70;
                }
                iVar1 = FUN_007ffb00(piVar3,piVar2,piVar3);
                if (iVar1 != 0) goto LAB_007fd4c1;
                bVar4 = false;
                if (local_40[0] == 0) {
                  iVar1 = FUN_007ffad0(local_50,1);
                  if (iVar1 != 0) goto LAB_007fd14b;
                  iVar1 = FUN_007ffad0(local_80,0);
                  if (iVar1 != -1) goto LAB_007fd46a;
                  goto LAB_007fd440;
                }
              }
              iVar1 = FUN_007ffce0(local_40,local_40);
            } while ((iVar1 == 0) &&
                    (((((local_60[0] < 1 || ((*local_54 & 1) == 0)) &&
                       ((local_30[0] < 1 || ((*local_24 & 1) == 0)))) ||
                      ((iVar1 = FUN_007ff1a0(local_60,local_20,local_60), iVar1 == 0 &&
                       (iVar1 = FUN_007ffb00(local_30,local_10,local_30), iVar1 == 0)))) &&
                     ((iVar1 = FUN_007ffce0(local_60,local_60), iVar1 == 0 &&
                      (iVar1 = FUN_007ffce0(local_30,local_30), iVar1 == 0))))));
          }
        }
        else {
LAB_007fd14b:
          iVar1 = -3;
        }
      }
      goto LAB_007fd4c1;
    }
  }
  return iVar1;
  while (iVar1 = FUN_007ffad0(local_80,0), iVar1 == -1) {
LAB_007fd440:
    iVar1 = FUN_007ff1a0(local_80,param_2,local_80);
    if (iVar1 != 0) goto LAB_007fd4c1;
  }
LAB_007fd46a:
  iVar1 = FUN_007f6f70(local_80,param_2);
  while (iVar1 != -1) {
    iVar1 = FUN_007ffb00(local_80,param_2,local_80);
    if (iVar1 != 0) goto LAB_007fd4c1;
    iVar1 = FUN_007f6f70(local_80,param_2);
  }
  FUN_007fc2d0(local_80,param_3);
  iVar1 = 0;
LAB_007fd4c1:
  FUN_007e6040(local_10,local_20,local_40,local_50,local_60,local_30,local_80,local_70,0);
  return iVar1;
}


// ==== FUN_007fd520 @ 0x007fd520 ====

int FUN_007fd520(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  int local_60 [2];
  int local_58;
  byte *local_54;
  int local_50 [3];
  byte *local_44;
  int local_40 [3];
  byte *local_34;
  int local_30 [3];
  byte *local_24;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  if ((0 < *param_2) && ((*(byte *)param_2[3] & 1) == 0)) {
    return -3;
  }
  iVar2 = FUN_007ffd80(local_20,local_10,local_40,local_50,local_30,local_60,0);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = FUN_007fc260(param_2,local_20);
  if ((((iVar2 == 0) && (iVar2 = FUN_007fc5d0(param_1,param_2,local_10), iVar2 == 0)) &&
      (iVar2 = FUN_007fc260(local_20,local_40), iVar2 == 0)) &&
     (iVar2 = FUN_007fc260(local_10,local_50), iVar2 == 0)) {
    FUN_007fc660(local_60,1);
    do {
      bVar5 = local_40[0] == 0;
      while ((bVar5 || local_40[0] < 0 || ((*local_34 & 1) != 0))) {
        while ((0 < local_50[0] && ((*local_44 & 1) == 0))) {
          iVar2 = FUN_007ffce0(local_50,local_50);
          if (((iVar2 != 0) ||
              (((0 < local_60[0] && ((*local_54 & 1) != 0)) &&
               (iVar2 = FUN_007ffb00(local_60,local_20,local_60), iVar2 != 0)))) ||
             (iVar2 = FUN_007ffce0(local_60,local_60), iVar2 != 0)) goto LAB_007fd7b6;
        }
        iVar2 = FUN_007e6310(local_40,local_50);
        if (iVar2 == -1) {
          iVar2 = FUN_007ffb00(local_50,local_40,local_50);
          if (iVar2 != 0) goto LAB_007fd7b6;
          piVar3 = local_60;
          piVar4 = local_30;
        }
        else {
          iVar2 = FUN_007ffb00(local_40,local_50,local_40);
          if (iVar2 != 0) goto LAB_007fd7b6;
          piVar3 = local_30;
          piVar4 = local_60;
        }
        iVar2 = FUN_007ffb00(piVar3,piVar4,piVar3);
        if (iVar2 != 0) goto LAB_007fd7b6;
        bVar5 = false;
        if (local_40[0] == 0) {
          iVar2 = FUN_007ffad0(local_50,1);
          if (iVar2 == 0) {
            uVar1 = *(undefined4 *)(param_1 + 8);
            goto joined_r0x007fd77e;
          }
          iVar2 = -3;
          goto LAB_007fd7b6;
        }
      }
      iVar2 = FUN_007ffce0(local_40,local_40);
    } while (((iVar2 == 0) &&
             (((local_30[0] < 1 || ((*local_24 & 1) == 0)) ||
              (iVar2 = FUN_007ffb00(local_30,local_20,local_30), iVar2 == 0)))) &&
            (iVar2 = FUN_007ffce0(local_30,local_30), iVar2 == 0));
  }
  goto LAB_007fd7b6;
  while (iVar2 = FUN_007ff1a0(local_60,param_2,local_60), iVar2 == 0) {
joined_r0x007fd77e:
    if (local_58 != 1) {
      FUN_007fc2d0(local_60,param_3);
      *(undefined4 *)(param_3 + 8) = uVar1;
      iVar2 = 0;
      break;
    }
  }
LAB_007fd7b6:
  FUN_007e6040(local_20,local_10,local_40,local_50,local_30,local_60,0);
  return iVar2;
}


// ==== FUN_007fd7f0 @ 0x007fd7f0 ====

int FUN_007fd7f0(int *param_1,int *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  int local_28;
  int local_24;
  int local_20;
  int local_10 [3];
  int local_4;
  
  if (param_4 < 0x200) {
    iVar2 = *param_1;
    if (*param_2 <= *param_1) {
      iVar2 = *param_2;
    }
    if (iVar2 < 0x100) {
      iVar2 = FUN_007fd940(param_1,param_2,param_3,param_4);
      return iVar2;
    }
  }
  iVar2 = FUN_007e5fc0(local_10,param_4);
  if (iVar2 == 0) {
    iVar2 = *param_1;
    local_10[0] = param_4;
    if (0 < iVar2) {
      local_28 = param_4;
      local_20 = 0;
      do {
        uVar7 = 0;
        iVar5 = *param_2;
        if (local_28 <= *param_2) {
          iVar5 = local_28;
        }
        uVar1 = *(undefined4 *)(param_1[3] + local_20 * 4);
        puVar9 = (undefined4 *)param_2[3];
        puVar8 = (uint *)(local_4 + local_20 * 4);
        iVar6 = 0;
        if (0 < iVar5) {
          local_24 = iVar5;
          do {
            uVar10 = __allmul(*puVar9,0,uVar1,0);
            uVar3 = (uint)uVar10 + *puVar8;
            uVar4 = uVar3 + uVar7;
            uVar7 = uVar4 >> 0x1c |
                    ((int)((ulonglong)uVar10 >> 0x20) + (uint)CARRY4((uint)uVar10,*puVar8) +
                    (uint)CARRY4(uVar3,uVar7)) * 0x10;
            *puVar8 = uVar4 & 0xfffffff;
            puVar9 = puVar9 + 1;
            puVar8 = puVar8 + 1;
            local_24 = local_24 + -1;
          } while (local_24 != 0);
          iVar6 = iVar5;
        }
        if (iVar6 + local_20 < param_4) {
          *puVar8 = uVar7;
        }
        local_28 = local_28 + -1;
        local_20 = local_20 + 1;
      } while (local_20 < iVar2);
    }
    FUN_007f5ec0(local_10);
    FUN_007fc2d0(local_10,param_3);
    FUN_007f60a0(local_10);
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_007fd940 @ 0x007fd940 ====

int FUN_007fd940(int *param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint local_800 [512];
  
  if ((param_4 <= param_3[1]) || (iVar4 = FUN_007f6030(param_3,param_4), iVar4 == 0)) {
    iVar6 = *param_1;
    iVar4 = *param_2 + iVar6;
    if (param_4 < iVar4) {
      iVar4 = param_4;
    }
    iVar11 = 0;
    uVar3 = 0;
    if (0 < iVar4) {
      iVar1 = param_1[3];
      iVar2 = param_2[3];
      iVar7 = *param_2 + -1;
      do {
        iVar8 = iVar7;
        if (iVar11 <= iVar7) {
          iVar8 = iVar11;
        }
        puVar9 = (uint *)(iVar1 + (iVar11 - iVar8) * 4);
        iVar12 = iVar6 - (iVar11 - iVar8);
        puVar5 = (uint *)(iVar2 + iVar8 * 4);
        if (iVar8 + 1 <= iVar12) {
          iVar12 = iVar8 + 1;
        }
        if (0 < iVar12) {
          do {
            uVar3 = (ulonglong)*puVar5 * (ulonglong)*puVar9 + uVar3;
            puVar5 = puVar5 + -1;
            puVar9 = puVar9 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        uVar10 = (uint)uVar3;
        uVar3 = uVar3 >> 0x1c;
        local_800[iVar11] = uVar10 & 0xfffffff;
        iVar11 = iVar11 + 1;
      } while (iVar11 < iVar4);
    }
    iVar6 = *param_3;
    puVar9 = (uint *)param_3[3];
    *param_3 = iVar4;
    iVar4 = iVar4 + 1;
    iVar11 = 0;
    if (0 < iVar4) {
      puVar5 = local_800;
      puVar13 = puVar9;
      for (iVar11 = iVar4; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar13 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar13 = puVar13 + 1;
      }
      puVar9 = puVar9 + iVar4;
      iVar11 = iVar4;
    }
    if (iVar11 < iVar6) {
      for (iVar6 = iVar6 - iVar11; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
    }
    FUN_007f5ec0(param_3);
    iVar4 = 0;
  }
  return iVar4;
}


// ==== FUN_007fda80 @ 0x007fda80 ====

undefined4 FUN_007fda80(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int local_7c;
  undefined4 local_78;
  undefined1 local_70 [16];
  int local_60 [3];
  undefined4 *local_54;
  int local_50 [3];
  undefined4 *local_44;
  undefined1 local_40 [16];
  int local_30 [3];
  undefined4 *local_24;
  int local_20 [3];
  undefined4 *local_14;
  undefined1 local_10 [16];
  
  uVar6 = 0xfffffffe;
  local_78 = 0xfffffffe;
  iVar5 = *param_2;
  if (*param_1 < *param_2) {
    iVar5 = *param_1;
  }
  iVar5 = iVar5 >> 1;
  iVar1 = FUN_007e5fc0(local_60,iVar5);
  if (iVar1 == 0) {
    iVar1 = FUN_007e5fc0(local_20,*param_1 - iVar5);
    if (iVar1 == 0) {
      iVar1 = FUN_007e5fc0(local_50,iVar5);
      if (iVar1 == 0) {
        iVar1 = FUN_007e5fc0(local_30,*param_2 - iVar5);
        if (iVar1 == 0) {
          iVar1 = iVar5 * 2;
          iVar2 = FUN_007e5fc0(local_70,iVar1);
          if (iVar2 == 0) {
            iVar2 = FUN_007e5fc0(local_10,iVar1);
            if (iVar2 == 0) {
              iVar2 = FUN_007e5fc0(local_40,iVar1);
              if (iVar2 == 0) {
                local_20[0] = *param_1 - iVar5;
                local_30[0] = *param_2 - iVar5;
                puVar3 = (undefined4 *)param_1[3];
                puVar4 = (undefined4 *)param_2[3];
                if (0 < iVar5) {
                  local_7c = iVar5;
                  do {
                    *local_54 = *puVar3;
                    *local_44 = *puVar4;
                    local_54 = local_54 + 1;
                    puVar3 = puVar3 + 1;
                    local_44 = local_44 + 1;
                    puVar4 = puVar4 + 1;
                    local_7c = local_7c + -1;
                  } while (local_7c != 0);
                }
                local_7c = iVar5;
                if (iVar5 < *param_1) {
                  do {
                    *local_14 = *puVar3;
                    local_7c = local_7c + 1;
                    local_14 = local_14 + 1;
                    puVar3 = puVar3 + 1;
                  } while (local_7c < *param_1);
                }
                iVar2 = iVar5;
                if (iVar5 < *param_2) {
                  do {
                    *local_24 = *puVar4;
                    iVar2 = iVar2 + 1;
                    local_24 = local_24 + 1;
                    puVar4 = puVar4 + 1;
                  } while (iVar2 < *param_2);
                }
                local_60[0] = iVar5;
                local_50[0] = iVar5;
                FUN_007f5ec0(local_60);
                FUN_007f5ec0(local_50);
                iVar2 = FUN_007fc470(local_60,local_50,local_10);
                if ((((((iVar2 == 0) &&
                       (iVar2 = FUN_007fc470(local_20,local_30,local_40), iVar2 == 0)) &&
                      (iVar2 = FUN_007ff910(local_20,local_60,local_70), iVar2 == 0)) &&
                     ((iVar2 = FUN_007ff910(local_30,local_50,local_60), iVar2 == 0 &&
                      (iVar2 = FUN_007fc470(local_70,local_60,local_70), iVar2 == 0)))) &&
                    ((iVar2 = FUN_007ff1a0(local_10,local_40,local_60), iVar2 == 0 &&
                     ((iVar2 = FUN_007ff740(local_70,local_60,local_70), iVar2 == 0 &&
                      (iVar5 = FUN_007fc1e0(local_70,iVar5), iVar5 == 0)))))) &&
                   ((iVar5 = FUN_007fc1e0(local_40,iVar1), iVar5 == 0 &&
                    ((iVar5 = FUN_007ff1a0(local_10,local_70,local_70), iVar5 == 0 &&
                     (iVar5 = FUN_007ff1a0(local_70,local_40,param_3), iVar5 == 0)))))) {
                  local_78 = 0;
                }
                FUN_007f60a0(local_40);
              }
              FUN_007f60a0(local_10);
            }
            FUN_007f60a0(local_70);
          }
          FUN_007f60a0(local_30);
          uVar6 = local_78;
        }
        FUN_007f60a0(local_50);
      }
      FUN_007f60a0(local_20);
    }
    FUN_007f60a0(local_60);
  }
  return uVar6;
}


// ==== FUN_007fddb0 @ 0x007fddb0 ====

int FUN_007fddb0(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_d0 [16];
  undefined1 local_c0 [16];
  undefined1 local_b0 [16];
  undefined1 local_a0 [16];
  undefined1 local_90 [16];
  undefined1 local_80 [16];
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  iVar2 = FUN_007ffd80(local_10,local_90,local_b0,local_a0,local_60,local_20,local_80,local_50,
                       local_30,local_70,local_40,local_d0,local_c0,0);
  if (iVar2 == 0) {
    iVar3 = *param_2;
    if (*param_1 < *param_2) {
      iVar3 = *param_1;
    }
    iVar3 = iVar3 / 3;
    iVar1 = iVar3 * 0x1c;
    iVar2 = FUN_007fc380(param_1,iVar1,local_20);
    if (iVar2 == 0) {
      iVar2 = FUN_007fc260(param_1,local_80);
      if (iVar2 == 0) {
        FUN_007fc310(local_80,iVar3);
        FUN_007fc380(local_80,iVar1,local_80);
        iVar2 = FUN_007fc260(param_1,local_50);
        if (iVar2 == 0) {
          FUN_007fc310(local_50,iVar3 * 2);
          iVar2 = FUN_007fc380(param_2,iVar1,local_30);
          if (iVar2 == 0) {
            iVar2 = FUN_007fc260(param_2,local_70);
            if (iVar2 == 0) {
              FUN_007fc310(local_70,iVar3);
              FUN_007fc380(local_70,iVar1,local_70);
              iVar2 = FUN_007fc260(param_2,local_40);
              if (iVar2 == 0) {
                FUN_007fc310(local_40,iVar3 * 2);
                iVar2 = FUN_007fc470(local_20,local_30,local_10);
                if (iVar2 == 0) {
                  iVar2 = FUN_007fc470(local_50,local_40,local_60);
                  if (iVar2 == 0) {
                    iVar2 = FUN_007ff810(local_20,local_d0);
                    if (iVar2 == 0) {
                      iVar2 = FUN_007ff1a0(local_d0,local_80,local_d0);
                      if (iVar2 == 0) {
                        iVar2 = FUN_007ff810(local_d0,local_d0);
                        if (iVar2 == 0) {
                          iVar2 = FUN_007ff1a0(local_d0,local_50,local_d0);
                          if (iVar2 == 0) {
                            iVar2 = FUN_007ff810(local_30,local_c0);
                            if (iVar2 == 0) {
                              iVar2 = FUN_007ff1a0(local_c0,local_70,local_c0);
                              if (iVar2 == 0) {
                                iVar2 = FUN_007ff810(local_c0,local_c0);
                                if (iVar2 == 0) {
                                  iVar2 = FUN_007ff1a0(local_c0,local_40,local_c0);
                                  if (iVar2 == 0) {
                                    iVar2 = FUN_007fc470(local_d0,local_c0,local_90);
                                    if (iVar2 == 0) {
                                      iVar2 = FUN_007ff810(local_50,local_d0);
                                      if (iVar2 == 0) {
                                        iVar2 = FUN_007ff1a0(local_d0,local_80,local_d0);
                                        if (iVar2 == 0) {
                                          iVar2 = FUN_007ff810(local_d0,local_d0);
                                          if (iVar2 == 0) {
                                            iVar2 = FUN_007ff1a0(local_d0,local_20,local_d0);
                                            if (iVar2 == 0) {
                                              iVar2 = FUN_007ff810(local_40,local_c0);
                                              if (iVar2 == 0) {
                                                iVar2 = FUN_007ff1a0(local_c0,local_70,local_c0);
                                                if (iVar2 == 0) {
                                                  iVar2 = FUN_007ff810(local_c0,local_c0);
                                                  if (iVar2 == 0) {
                                                    iVar2 = FUN_007ff1a0(local_c0,local_30,local_c0)
                                                    ;
                                                    if (iVar2 == 0) {
                                                      iVar2 = FUN_007fc470(local_d0,local_c0,
                                                                           local_a0);
                                                      if (iVar2 == 0) {
                                                        iVar2 = FUN_007ff1a0(local_50,local_80,
                                                                             local_d0);
                                                        if (iVar2 == 0) {
                                                          iVar2 = FUN_007ff1a0(local_d0,local_20,
                                                                               local_d0);
                                                          if (iVar2 == 0) {
                                                            iVar2 = FUN_007ff1a0(local_40,local_70,
                                                                                 local_c0);
                                                            if (iVar2 == 0) {
                                                              iVar2 = FUN_007ff1a0(local_c0,local_30
                                                                                   ,local_c0);
                                                              if (iVar2 == 0) {
                                                                iVar2 = FUN_007fc470(local_d0,
                                                  local_c0,local_b0);
                                                  if (iVar2 == 0) {
                                                    iVar2 = FUN_007ffb00(local_90,local_60,local_90)
                                                    ;
                                                    if (iVar2 == 0) {
                                                      iVar2 = FUN_007ffb00(local_a0,local_10,
                                                                           local_a0);
                                                      if (iVar2 == 0) {
                                                        iVar2 = FUN_007ffce0(local_90,local_90);
                                                        if (iVar2 == 0) {
                                                          iVar2 = FUN_007ffce0(local_a0,local_a0);
                                                          if (iVar2 == 0) {
                                                            iVar2 = FUN_007ffb00(local_b0,local_10,
                                                                                 local_b0);
                                                            if (iVar2 == 0) {
                                                              iVar2 = FUN_007ffb00(local_b0,local_60
                                                                                   ,local_b0);
                                                              if (iVar2 == 0) {
                                                                iVar2 = FUN_007ffb00(local_90,
                                                  local_b0,local_90);
                                                  if (iVar2 == 0) {
                                                    iVar2 = FUN_007ffb00(local_a0,local_b0,local_a0)
                                                    ;
                                                    if (iVar2 == 0) {
                                                      iVar2 = FUN_007f5ef0(local_10,3,local_d0);
                                                      if (iVar2 == 0) {
                                                        iVar2 = FUN_007ffb00(local_90,local_d0,
                                                                             local_90);
                                                        if (iVar2 == 0) {
                                                          iVar2 = FUN_007f5ef0(local_60,3,local_d0);
                                                          if (iVar2 == 0) {
                                                            iVar2 = FUN_007ffb00(local_a0,local_d0,
                                                                                 local_a0);
                                                            if (iVar2 == 0) {
                                                              iVar2 = FUN_007ffa10(local_b0,3,
                                                                                   local_b0);
                                                              if (iVar2 == 0) {
                                                                iVar2 = FUN_007ffb00(local_b0,
                                                  local_90,local_b0);
                                                  if (iVar2 == 0) {
                                                    iVar2 = FUN_007ffb00(local_b0,local_a0,local_b0)
                                                    ;
                                                    if (iVar2 == 0) {
                                                      iVar2 = FUN_007ffb00(local_90,local_b0,
                                                                           local_90);
                                                      if (iVar2 == 0) {
                                                        iVar2 = FUN_007ffb00(local_a0,local_b0,
                                                                             local_a0);
                                                        if (iVar2 == 0) {
                                                          iVar2 = FUN_007ffdf0(local_90,local_90,0);
                                                          if (iVar2 == 0) {
                                                            iVar2 = FUN_007ffdf0(local_a0,local_a0,0
                                                                                );
                                                            if (iVar2 == 0) {
                                                              iVar2 = FUN_007fc1e0(local_90,iVar3);
                                                              if (iVar2 == 0) {
                                                                iVar2 = FUN_007fc1e0(local_b0,iVar3 
                                                  * 2);
                                                  if (iVar2 == 0) {
                                                    iVar2 = FUN_007fc1e0(local_a0,iVar3 * 3);
                                                    if (iVar2 == 0) {
                                                      iVar2 = FUN_007fc1e0(local_60,iVar3 * 4);
                                                      if (iVar2 == 0) {
                                                        iVar2 = FUN_007ff1a0(local_10,local_90,
                                                                             param_3);
                                                        if (iVar2 == 0) {
                                                          iVar2 = FUN_007ff1a0(local_b0,local_a0,
                                                                               local_d0);
                                                          if (iVar2 == 0) {
                                                            iVar2 = FUN_007ff1a0(local_60,local_d0,
                                                                                 local_d0);
                                                            if (iVar2 == 0) {
                                                              iVar2 = FUN_007ff1a0(local_d0,param_3,
                                                                                   param_3);
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
                }
              }
            }
          }
        }
      }
    }
    FUN_007e6040(local_10,local_90,local_b0,local_a0,local_60,local_20,local_80,local_50,local_30,
                 local_70,local_40,local_d0,local_c0,0);
  }
  return iVar2;
}


// ==== FUN_007fe610 @ 0x007fe610 ====

int FUN_007fe610(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  longlong lVar9;
  undefined8 uVar10;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_10 [3];
  int local_4;
  
  iVar1 = *param_1;
  iVar7 = iVar1 * 2 + 1;
  iVar3 = FUN_007e5fc0(local_10,iVar7);
  if (iVar3 == 0) {
    local_10[0] = iVar7;
    if (0 < iVar1) {
      local_1c = 1;
      local_20 = 0;
      local_28 = 0;
      local_18 = iVar1;
      do {
        lVar9 = __allmul(*(undefined4 *)(param_1[3] + local_28),0,
                         *(undefined4 *)(param_1[3] + local_28),0);
        lVar9 = lVar9 + (ulonglong)*(uint *)(local_4 + local_20);
        uVar4 = (uint)lVar9;
        uVar5 = uVar4 >> 0x1c | (int)((ulonglong)lVar9 >> 0x20) * 0x10;
        *(uint *)(local_4 + local_20) = uVar4 & 0xfffffff;
        uVar2 = *(undefined4 *)(local_28 + param_1[3]);
        puVar8 = (uint *)(local_4 + 4 + local_20);
        if (local_1c < iVar1) {
          iVar7 = local_1c;
          do {
            uVar10 = __allmul(*(undefined4 *)(param_1[3] + iVar7 * 4),0,uVar2,0);
            uVar10 = __allmul(uVar10,2,0);
            uVar4 = (uint)uVar10 + *puVar8;
            uVar6 = uVar4 + uVar5;
            uVar5 = uVar6 >> 0x1c |
                    ((int)((ulonglong)uVar10 >> 0x20) + (uint)CARRY4((uint)uVar10,*puVar8) +
                    (uint)CARRY4(uVar4,uVar5)) * 0x10;
            *puVar8 = uVar6 & 0xfffffff;
            iVar7 = iVar7 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar7 < iVar1);
        }
        if (uVar5 != 0) {
          do {
            uVar4 = *puVar8 + uVar5;
            uVar5 = uVar4 >> 0x1c | (uint)CARRY4(*puVar8,uVar5) << 4;
            *puVar8 = uVar4 & 0xfffffff;
            puVar8 = puVar8 + 1;
          } while (uVar5 != 0);
        }
        local_28 = local_28 + 4;
        local_20 = local_20 + 8;
        local_1c = local_1c + 1;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
    FUN_007f5ec0(local_10);
    FUN_007fc2d0(local_10,param_2);
    FUN_007f60a0(local_10);
    iVar3 = 0;
  }
  return iVar3;
}


// ==== FUN_007fe7a0 @ 0x007fe7a0 ====

int FUN_007fe7a0(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  longlong lVar12;
  int local_820;
  uint auStack_800 [512];
  
  iVar2 = *param_1 * 2;
  if ((param_2[1] < iVar2) && (iVar5 = FUN_007f6030(param_2,iVar2), iVar5 != 0)) {
    return iVar5;
  }
  uVar9 = 0;
  uVar4 = 0;
  if (0 < iVar2) {
    iVar5 = *param_1;
    iVar7 = param_1[3];
    do {
      uVar6 = iVar5 - 1;
      if ((int)uVar9 <= (int)uVar6) {
        uVar6 = uVar9;
      }
      iVar8 = uVar9 - uVar6;
      local_820 = iVar5 - iVar8;
      puVar11 = (uint *)(iVar7 + iVar8 * 4);
      puVar10 = (uint *)(iVar7 + uVar6 * 4);
      if ((int)(uVar6 + 1) <= local_820) {
        local_820 = uVar6 + 1;
      }
      iVar8 = (int)((uVar6 - iVar8) + 1) >> 1;
      if (iVar8 <= local_820) {
        local_820 = iVar8;
      }
      lVar12 = 0;
      if (0 < local_820) {
        lVar12 = 0;
        do {
          lVar12 = (ulonglong)*puVar10 * (ulonglong)*puVar11 + lVar12;
          puVar10 = puVar10 + -1;
          puVar11 = puVar11 + 1;
          local_820 = local_820 + -1;
        } while (local_820 != 0);
      }
      lVar12 = __allmul(lVar12,2,0);
      uVar3 = lVar12 + uVar4;
      if ((uVar9 & 1) == 0) {
        uVar1 = *(undefined4 *)(param_1[3] + ((int)uVar9 >> 1) * 4);
        lVar12 = __allmul(uVar1,0,uVar1,0);
        uVar3 = lVar12 + uVar3;
      }
      uVar4 = uVar3 >> 0x1c;
      auStack_800[uVar9] = (uint)uVar3 & 0xfffffff;
      uVar9 = uVar9 + 1;
    } while ((int)uVar9 < iVar2);
  }
  iVar5 = *param_2;
  *param_2 = *param_1 * 2;
  puVar11 = (uint *)param_2[3];
  iVar7 = 0;
  if (0 < iVar2) {
    do {
      *puVar11 = auStack_800[iVar7] & 0xfffffff;
      iVar7 = iVar7 + 1;
      puVar11 = puVar11 + 1;
    } while (iVar7 < iVar2);
  }
  if (iVar7 < iVar5) {
    for (iVar5 = iVar5 - iVar7; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
  }
  FUN_007f5ec0(param_2);
  return 0;
}


// ==== FUN_007fe930 @ 0x007fe930 ====

undefined4 FUN_007fe930(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_60 [16];
  int local_50 [3];
  undefined4 *local_44;
  undefined1 local_40 [16];
  int local_30 [3];
  undefined4 *local_24;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  iVar4 = *param_1 >> 1;
  uVar3 = 0xfffffffe;
  iVar1 = FUN_007e5fc0(local_50,iVar4);
  if (iVar1 == 0) {
    iVar1 = FUN_007e5fc0(local_30,*param_1 - iVar4);
    if (iVar1 == 0) {
      iVar1 = FUN_007e5fc0(local_60,*param_1 * 2);
      if (iVar1 == 0) {
        iVar1 = FUN_007e5fc0(local_10,*param_1 * 2);
        if (iVar1 == 0) {
          iVar1 = FUN_007e5fc0(local_20,iVar4 * 2);
          if (iVar1 == 0) {
            iVar1 = FUN_007e5fc0(local_40,(*param_1 - iVar4) * 2);
            if (iVar1 == 0) {
              puVar2 = (undefined4 *)param_1[3];
              if (0 < iVar4) {
                iVar1 = iVar4;
                do {
                  *local_44 = *puVar2;
                  local_44 = local_44 + 1;
                  puVar2 = puVar2 + 1;
                  iVar1 = iVar1 + -1;
                } while (iVar1 != 0);
              }
              if (iVar4 < *param_1) {
                iVar1 = iVar4;
                do {
                  *local_24 = *puVar2;
                  iVar1 = iVar1 + 1;
                  local_24 = local_24 + 1;
                  puVar2 = puVar2 + 1;
                } while (iVar1 < *param_1);
              }
              uVar3 = 0xfffffffe;
              local_30[0] = *param_1 - iVar4;
              local_50[0] = iVar4;
              FUN_007f5ec0(local_50);
              iVar1 = FUN_007fc540(local_50,local_20);
              if ((((((iVar1 == 0) && (iVar1 = FUN_007fc540(local_30,local_40), iVar1 == 0)) &&
                    (iVar1 = FUN_007ff910(local_30,local_50,local_60), iVar1 == 0)) &&
                   ((iVar1 = FUN_007fc540(local_60,local_60), iVar1 == 0 &&
                    (iVar1 = FUN_007ff910(local_20,local_40,local_10), iVar1 == 0)))) &&
                  ((iVar1 = FUN_007ff740(local_60,local_10,local_60), iVar1 == 0 &&
                   ((iVar1 = FUN_007fc1e0(local_60,iVar4), iVar1 == 0 &&
                    (iVar1 = FUN_007fc1e0(local_40,iVar4 * 2), iVar1 == 0)))))) &&
                 ((iVar1 = FUN_007ff1a0(local_20,local_60,local_60), iVar1 == 0 &&
                  (iVar1 = FUN_007ff1a0(local_60,local_40,param_2), iVar1 == 0)))) {
                uVar3 = 0;
              }
              FUN_007f60a0(local_40);
            }
            FUN_007f60a0(local_20);
          }
          FUN_007f60a0(local_10);
        }
        FUN_007f60a0(local_60);
      }
      FUN_007f60a0(local_30);
    }
    FUN_007f60a0(local_50);
  }
  return uVar3;
}


// ==== FUN_007feb90 @ 0x007feb90 ====

int FUN_007feb90(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_90 [16];
  undefined1 local_80 [16];
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  iVar2 = FUN_007ffd80(local_10,local_60,local_80,local_70,local_40,local_20,local_50,local_30,
                       local_90,0);
  if (iVar2 == 0) {
    iVar1 = *param_1 / 3;
    iVar2 = FUN_007fc380(param_1,iVar1 * 0x1c,local_20);
    if (iVar2 == 0) {
      iVar2 = FUN_007fc260(param_1,local_50);
      if (iVar2 == 0) {
        FUN_007fc310(local_50,iVar1);
        FUN_007fc380(local_50,iVar1 * 0x1c,local_50);
        iVar2 = FUN_007fc260(param_1,local_30);
        if (iVar2 == 0) {
          FUN_007fc310(local_30,iVar1 * 2);
          iVar2 = FUN_007fc540(local_20,local_10);
          if (iVar2 == 0) {
            iVar2 = FUN_007fc540(local_30,local_40);
            if (iVar2 == 0) {
              iVar2 = FUN_007ff810(local_20,local_90);
              if (iVar2 == 0) {
                iVar2 = FUN_007ff1a0(local_90,local_50,local_90);
                if (iVar2 == 0) {
                  iVar2 = FUN_007ff810(local_90,local_90);
                  if (iVar2 == 0) {
                    iVar2 = FUN_007ff1a0(local_90,local_30,local_90);
                    if (iVar2 == 0) {
                      iVar2 = FUN_007fc540(local_90,local_60);
                      if (iVar2 == 0) {
                        iVar2 = FUN_007ff810(local_30,local_90);
                        if (iVar2 == 0) {
                          iVar2 = FUN_007ff1a0(local_90,local_50,local_90);
                          if (iVar2 == 0) {
                            iVar2 = FUN_007ff810(local_90,local_90);
                            if (iVar2 == 0) {
                              iVar2 = FUN_007ff1a0(local_90,local_20,local_90);
                              if (iVar2 == 0) {
                                iVar2 = FUN_007fc540(local_90,local_70);
                                if (iVar2 == 0) {
                                  iVar2 = FUN_007ff1a0(local_30,local_50,local_90);
                                  if (iVar2 == 0) {
                                    iVar2 = FUN_007ff1a0(local_90,local_20,local_90);
                                    if (iVar2 == 0) {
                                      iVar2 = FUN_007fc540(local_90,local_80);
                                      if (iVar2 == 0) {
                                        iVar2 = FUN_007ffb00(local_60,local_40,local_60);
                                        if (iVar2 == 0) {
                                          iVar2 = FUN_007ffb00(local_70,local_10,local_70);
                                          if (iVar2 == 0) {
                                            iVar2 = FUN_007ffce0(local_60,local_60);
                                            if (iVar2 == 0) {
                                              iVar2 = FUN_007ffce0(local_70,local_70);
                                              if (iVar2 == 0) {
                                                iVar2 = FUN_007ffb00(local_80,local_10,local_80);
                                                if (iVar2 == 0) {
                                                  iVar2 = FUN_007ffb00(local_80,local_40,local_80);
                                                  if (iVar2 == 0) {
                                                    iVar2 = FUN_007ffb00(local_60,local_80,local_60)
                                                    ;
                                                    if (iVar2 == 0) {
                                                      iVar2 = FUN_007ffb00(local_70,local_80,
                                                                           local_70);
                                                      if (iVar2 == 0) {
                                                        iVar2 = FUN_007f5ef0(local_10,3,local_90);
                                                        if (iVar2 == 0) {
                                                          iVar2 = FUN_007ffb00(local_60,local_90,
                                                                               local_60);
                                                          if (iVar2 == 0) {
                                                            iVar2 = FUN_007f5ef0(local_40,3,local_90
                                                                                );
                                                            if (iVar2 == 0) {
                                                              iVar2 = FUN_007ffb00(local_70,local_90
                                                                                   ,local_70);
                                                              if (iVar2 == 0) {
                                                                iVar2 = FUN_007ffa10(local_80,3,
                                                                                     local_80);
                                                                if (iVar2 == 0) {
                                                                  iVar2 = FUN_007ffb00(local_80,
                                                  local_60,local_80);
                                                  if (iVar2 == 0) {
                                                    iVar2 = FUN_007ffb00(local_80,local_70,local_80)
                                                    ;
                                                    if (iVar2 == 0) {
                                                      iVar2 = FUN_007ffb00(local_60,local_80,
                                                                           local_60);
                                                      if (iVar2 == 0) {
                                                        iVar2 = FUN_007ffb00(local_70,local_80,
                                                                             local_70);
                                                        if (iVar2 == 0) {
                                                          iVar2 = FUN_007ffdf0(local_60,local_60,0);
                                                          if (iVar2 == 0) {
                                                            iVar2 = FUN_007ffdf0(local_70,local_70,0
                                                                                );
                                                            if (iVar2 == 0) {
                                                              iVar2 = FUN_007fc1e0(local_60,iVar1);
                                                              if (iVar2 == 0) {
                                                                iVar2 = FUN_007fc1e0(local_80,iVar1 
                                                  * 2);
                                                  if (iVar2 == 0) {
                                                    iVar2 = FUN_007fc1e0(local_70,iVar1 * 3);
                                                    if (iVar2 == 0) {
                                                      iVar2 = FUN_007fc1e0(local_40,iVar1 * 4);
                                                      if (iVar2 == 0) {
                                                        iVar2 = FUN_007ff1a0(local_10,local_60,
                                                                             param_2);
                                                        if (iVar2 == 0) {
                                                          iVar2 = FUN_007ff1a0(local_80,local_70,
                                                                               local_90);
                                                          if (iVar2 == 0) {
                                                            iVar2 = FUN_007ff1a0(local_40,local_90,
                                                                                 local_90);
                                                            if (iVar2 == 0) {
                                                              iVar2 = FUN_007ff1a0(local_90,param_2,
                                                                                   param_2);
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
    FUN_007e6040(local_10,local_60,local_80,local_70,local_40,local_20,local_50,local_30,local_90,0)
    ;
  }
  return iVar2;
}


// ==== FUN_007ff1a0 @ 0x007ff1a0 ====

void FUN_007ff1a0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_2 + 8);
  if (iVar1 == iVar2) {
    *(int *)(param_3 + 8) = iVar1;
    FUN_007ff910(param_1,param_2,param_3);
    return;
  }
  iVar3 = FUN_007f6f70(param_1,param_2);
  if (iVar3 == -1) {
    *(int *)(param_3 + 8) = iVar2;
    FUN_007ff740(param_2,param_1,param_3);
    return;
  }
  *(int *)(param_3 + 8) = iVar1;
  FUN_007ff740(param_1,param_2,param_3);
  return;
}


// ==== FUN_007ff210 @ 0x007ff210 ====

int FUN_007ff210(int *param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  int local_60;
  int local_50 [2];
  int local_48;
  int local_44;
  int local_40 [2];
  undefined4 local_38;
  int local_34;
  undefined4 local_30 [3];
  undefined4 *local_24;
  int local_20 [3];
  int local_14;
  undefined4 local_10 [3];
  undefined4 *local_4;
  
  if (*param_2 == 0) {
    return -3;
  }
  iVar5 = FUN_007f6f70(param_1,param_2);
  if (iVar5 == -1) {
    if (param_4 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_007fc260(param_1,param_4);
    }
    if (param_3 == 0) {
      return iVar5;
    }
    FUN_007f5ff0(param_3);
    return iVar5;
  }
  iVar5 = FUN_007e5fc0(local_20,*param_1 + 2);
  if (iVar5 != 0) {
    return iVar5;
  }
  local_20[0] = *param_1 + 2;
  iVar5 = FUN_007f6f20(local_30);
  if (iVar5 != 0) goto LAB_007ff722;
  iVar5 = FUN_007f6f20(local_10);
  if (iVar5 == 0) {
    iVar5 = FUN_007f62a0(local_50,param_1);
    if (iVar5 == 0) {
      iVar5 = FUN_007f62a0(local_40,param_2);
      if (iVar5 == 0) {
        iVar3 = param_1[2];
        iVar2 = param_2[2];
        local_38 = 0;
        local_48 = 0;
        iVar5 = FUN_007fcda0(local_40);
        if (iVar5 % 0x1c < 0x1b) {
          local_60 = 0x1b - iVar5 % 0x1c;
          iVar5 = FUN_007f5ef0(local_50,local_60,local_50);
          if ((iVar5 == 0) && (iVar5 = FUN_007f5ef0(local_40,local_60,local_40), iVar5 == 0))
          goto LAB_007ff376;
        }
        else {
          local_60 = 0;
LAB_007ff376:
          iVar8 = local_50[0] + -1;
          iVar9 = local_40[0] + -1;
          iVar10 = iVar8 - iVar9;
          iVar5 = FUN_007fc1e0(local_40,iVar10);
          if (iVar5 == 0) {
            iVar5 = FUN_007e6310(local_50,local_40);
            while (iVar5 != -1) {
              piVar1 = (int *)(local_14 + iVar10 * 4);
              *piVar1 = *piVar1 + 1;
              iVar5 = FUN_007ffb00(local_50,local_40,local_50);
              if (iVar5 != 0) goto LAB_007ff6ee;
              iVar5 = FUN_007e6310(local_50,local_40);
            }
            FUN_007fc310(local_40,iVar10);
            for (; local_40[0] <= iVar8; iVar8 = iVar8 + -1) {
              if (iVar8 <= local_50[0]) {
                uVar6 = *(uint *)(local_44 + iVar8 * 4);
                uVar4 = *(uint *)(local_34 + iVar9 * 4);
                if (uVar6 == uVar4) {
                  param_2 = (int *)(iVar8 - iVar9);
                  iVar10 = (int)param_2 * 4;
                  *(undefined4 *)(iVar10 + -4 + local_14) = 0xfffffff;
                }
                else {
                  uVar11 = __aulldiv(uVar6 << 0x1c | *(uint *)(local_44 + -4 + iVar8 * 4),uVar6 >> 4
                                     ,uVar4,0);
                  uVar6 = (uint)uVar11;
                  if (((int)((ulonglong)uVar11 >> 0x20) != 0) || (0xfffffff < uVar6)) {
                    uVar6 = 0xfffffff;
                  }
                  param_2 = (int *)(iVar8 - iVar9);
                  iVar10 = (int)param_2 * 4;
                  *(uint *)(iVar10 + -4 + local_14) = uVar6 & 0xfffffff;
                }
                *(uint *)(iVar10 + -4 + local_14) =
                     *(int *)(iVar10 + -4 + local_14) + 1U & 0xfffffff;
                do {
                  *(uint *)(iVar10 + -4 + local_14) =
                       *(int *)(iVar10 + -4 + local_14) - 1U & 0xfffffff;
                  FUN_007f5ff0(local_30);
                  if (local_40[0] + -2 < 0) {
                    uVar7 = 0;
                  }
                  else {
                    uVar7 = *(undefined4 *)(local_34 + -4 + iVar9 * 4);
                  }
                  *local_24 = uVar7;
                  local_24[1] = *(undefined4 *)(local_34 + iVar9 * 4);
                  local_30[0] = 2;
                  iVar5 = FUN_007ffa10(local_30,*(undefined4 *)(iVar10 + -4 + local_14),local_30);
                  if (iVar5 != 0) goto LAB_007ff6ee;
                  if (iVar8 + -2 < 0) {
                    uVar7 = 0;
                  }
                  else {
                    uVar7 = *(undefined4 *)(local_44 + (iVar8 + -2) * 4);
                  }
                  *local_4 = uVar7;
                  if (iVar8 + -1 < 0) {
                    uVar7 = 0;
                  }
                  else {
                    uVar7 = *(undefined4 *)(local_44 + -4 + iVar8 * 4);
                  }
                  local_4[1] = uVar7;
                  local_4[2] = *(undefined4 *)(local_44 + iVar8 * 4);
                  local_10[0] = 3;
                  iVar5 = FUN_007f6f70(local_30,local_10);
                } while (iVar5 == 1);
                iVar5 = FUN_007ffa10(local_40,*(undefined4 *)(iVar10 + -4 + local_14),local_30);
                if (iVar5 != 0) goto LAB_007ff6ee;
                iVar5 = FUN_007fc1e0(local_30,(int)param_2 + -1);
                if ((iVar5 != 0) || (iVar5 = FUN_007ffb00(local_50,local_30,local_50), iVar5 != 0))
                goto LAB_007ff6ee;
                if (local_48 == 1) {
                  iVar5 = FUN_007fc260(local_40,local_30);
                  if (((iVar5 != 0) ||
                      (iVar5 = FUN_007fc1e0(local_30,(int)param_2 + -1), iVar5 != 0)) ||
                     (iVar5 = FUN_007ff1a0(local_50,local_30,local_50), iVar5 != 0))
                  goto LAB_007ff6ee;
                  *(uint *)(iVar10 + -4 + local_14) =
                       *(int *)(iVar10 + -4 + local_14) - 1U & 0xfffffff;
                }
              }
            }
            if (local_50[0] == 0) {
              local_48 = 0;
            }
            else {
              local_48 = param_1[2];
            }
            if (param_3 != 0) {
              FUN_007f5ec0(local_20);
              FUN_007fc2d0(local_20,param_3);
              *(uint *)(param_3 + 8) = (uint)(iVar3 != iVar2);
            }
            if (param_4 != 0) {
              FUN_007f6120(local_50,local_60,local_50,0);
              FUN_007fc2d0(local_50,param_4);
            }
            iVar5 = 0;
          }
        }
LAB_007ff6ee:
        FUN_007f60a0(local_40);
      }
      FUN_007f60a0(local_50);
    }
    FUN_007f60a0(local_10);
  }
  FUN_007f60a0(local_30);
LAB_007ff722:
  FUN_007f60a0(local_20);
  return iVar5;
}


// ==== FUN_007ff740 @ 0x007ff740 ====

int FUN_007ff740(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  
  iVar8 = *param_1;
  iVar1 = *param_2;
  if ((param_3[1] < iVar8) && (iVar3 = FUN_007f6030(param_3,iVar8), iVar3 != 0)) {
    return iVar3;
  }
  iVar3 = *param_3;
  *param_3 = iVar8;
  piVar6 = (int *)param_1[3];
  piVar7 = (int *)param_2[3];
  puVar10 = (uint *)param_3[3];
  uVar9 = 0;
  iVar4 = 0;
  if (0 < iVar1) {
    iVar4 = iVar1;
    do {
      iVar2 = *piVar7;
      piVar7 = piVar7 + 1;
      uVar9 = (*piVar6 - iVar2) - uVar9;
      *puVar10 = uVar9 & 0xfffffff;
      piVar6 = piVar6 + 1;
      uVar9 = uVar9 >> 0x1f;
      puVar10 = puVar10 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar4 = iVar1;
  }
  if (iVar4 < iVar8) {
    iVar8 = iVar8 - iVar4;
    do {
      uVar5 = *piVar6 - uVar9;
      uVar9 = uVar5 >> 0x1f;
      *puVar10 = uVar5 & 0xfffffff;
      piVar6 = piVar6 + 1;
      puVar10 = puVar10 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  if (*param_3 < iVar3) {
    for (iVar3 = iVar3 - *param_3; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
  }
  FUN_007f5ec0(param_3);
  return 0;
}


// ==== FUN_007ff810 @ 0x007ff810 ====

int FUN_007ff810(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  
  if ((*param_1 + 1 <= param_2[1]) || (iVar2 = FUN_007f6030(param_2,*param_1 + 1), iVar2 == 0)) {
    iVar2 = *param_2;
    *param_2 = *param_1;
    puVar5 = (uint *)param_2[3];
    iVar3 = 0;
    uVar4 = 0;
    puVar6 = (uint *)param_1[3];
    if (0 < *param_1) {
      do {
        uVar1 = *puVar6;
        *puVar5 = uVar1 * 2 & 0xfffffff | uVar4;
        uVar4 = uVar1 >> 0x1b;
        iVar3 = iVar3 + 1;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar3 < *param_1);
      if (uVar4 != 0) {
        *puVar5 = 1;
        *param_2 = *param_2 + 1;
      }
    }
    iVar3 = *param_2;
    if (iVar3 < iVar2) {
      puVar7 = (undefined4 *)(param_2[3] + iVar3 * 4);
      for (iVar2 = iVar2 - iVar3; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
    }
    param_2[2] = param_1[2];
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_007ff8b0 @ 0x007ff8b0 ====

int FUN_007ff8b0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_007f5ff0(param_1);
  iVar1 = param_2 / 0x1c;
  iVar2 = FUN_007f6030(param_1,iVar1 + 1);
  if (iVar2 == 0) {
    *param_1 = iVar1 + 1;
    *(int *)(param_1[3] + iVar1 * 4) = 1 << ((char)param_2 + (char)iVar1 * -0x1c & 0x1fU);
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_007ff910 @ 0x007ff910 ====

int FUN_007ff910(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint *puVar7;
  int *local_8;
  
  piVar1 = param_3;
  piVar5 = param_2;
  piVar4 = param_1;
  iVar6 = *param_2;
  iVar2 = *param_1;
  if (iVar6 < iVar2) {
    local_8 = param_1;
    param_1 = (int *)iVar6;
    param_2 = (int *)iVar2;
  }
  else {
    local_8 = param_2;
    param_1 = (int *)iVar2;
    param_2 = (int *)iVar6;
  }
  iVar6 = (int)param_2 + 1;
  if ((iVar6 <= param_3[1]) || (iVar2 = FUN_007f6030(param_3,iVar6), iVar2 == 0)) {
    iVar2 = *param_3;
    *param_3 = iVar6;
    piVar4 = (int *)piVar4[3];
    piVar5 = (int *)piVar5[3];
    puVar7 = (uint *)param_3[3];
    uVar3 = 0;
    iVar6 = 0;
    if (0 < (int)param_1) {
      param_3 = param_1;
      do {
        iVar6 = *piVar5;
        piVar5 = piVar5 + 1;
        uVar3 = iVar6 + *piVar4 + uVar3;
        *puVar7 = uVar3 & 0xfffffff;
        piVar4 = piVar4 + 1;
        uVar3 = uVar3 >> 0x1c;
        puVar7 = puVar7 + 1;
        param_3 = (int *)((int)param_3 + -1);
      } while (param_3 != (int *)0x0);
      iVar6 = (int)param_1;
    }
    if (param_1 != param_2) {
      for (; iVar6 < (int)param_2; iVar6 = iVar6 + 1) {
        uVar3 = uVar3 + *(int *)(local_8[3] + iVar6 * 4);
        *puVar7 = uVar3;
        *puVar7 = *puVar7 & 0xfffffff;
        uVar3 = uVar3 >> 0x1c;
        puVar7 = puVar7 + 1;
      }
    }
    *puVar7 = uVar3;
    iVar6 = *piVar1;
    if (iVar6 < iVar2) {
      for (iVar2 = iVar2 - iVar6; puVar7 = puVar7 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = 0;
      }
    }
    FUN_007f5ec0(piVar1);
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_007ffa10 @ 0x007ffa10 ====

int FUN_007ffa10(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint *puVar6;
  longlong lVar7;
  
  if ((param_3[1] < *param_1 + 1) && (iVar1 = FUN_007f6030(param_3,*param_1 + 1), iVar1 != 0)) {
    return iVar1;
  }
  iVar1 = *param_3;
  param_3[2] = param_1[2];
  puVar4 = (undefined4 *)param_1[3];
  puVar6 = (uint *)param_3[3];
  uVar3 = 0;
  iVar5 = 0;
  if (0 < *param_1) {
    do {
      lVar7 = __allmul(*puVar4,0,param_2,0);
      uVar2 = (uint)(lVar7 + (ulonglong)uVar3);
      uVar3 = uVar2 >> 0x1c | (int)(lVar7 + (ulonglong)uVar3 >> 0x20) * 0x10;
      *puVar6 = uVar2 & 0xfffffff;
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar5 < *param_1);
  }
  *puVar6 = uVar3;
  if (iVar5 + 1 < iVar1) {
    for (iVar1 = iVar1 - (iVar5 + 1); puVar6 = puVar6 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar6 = 0;
    }
  }
  *param_3 = *param_1 + 1;
  FUN_007f5ec0(param_3);
  return 0;
}


// ==== FUN_007ffad0 @ 0x007ffad0 ====

int FUN_007ffad0(int *param_1,uint param_2)

{
  if (param_1[2] == 1) {
    return -1;
  }
  if ((*param_1 < 2) && (*(uint *)param_1[3] <= param_2)) {
    return -(uint)(*(uint *)param_1[3] < param_2);
  }
  return 1;
}


// ==== FUN_007ffb00 @ 0x007ffb00 ====

void FUN_007ffb00(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != *(int *)(param_2 + 8)) {
    *(int *)(param_3 + 8) = iVar1;
    FUN_007ff910(param_1,param_2,param_3);
    return;
  }
  iVar2 = FUN_007f6f70(param_1,param_2);
  if (iVar2 == -1) {
    *(uint *)(param_3 + 8) = (uint)(iVar1 == 0);
    FUN_007ff740(param_2,param_1,param_3);
    return;
  }
  *(int *)(param_3 + 8) = iVar1;
  FUN_007ff740(param_1,param_2,param_3);
  return;
}


// ==== FUN_007ffb70 @ 0x007ffb70 ====

int FUN_007ffb70(int *param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  int local_30;
  int local_2c;
  int local_28;
  int local_10 [3];
  int local_4;
  
  iVar1 = *param_2;
  iVar3 = *param_1;
  iVar4 = iVar1 + 1 + iVar3;
  if (iVar4 < 0x200) {
    if (iVar1 <= iVar3) {
      iVar3 = iVar1;
    }
    if (iVar3 < 0x100) {
      iVar4 = FUN_007fff10(param_1,param_2,param_3,param_4);
      return iVar4;
    }
  }
  iVar4 = FUN_007e5fc0(local_10,iVar4);
  if (iVar4 == 0) {
    iVar4 = *param_1;
    iVar1 = *param_2;
    local_10[0] = iVar1 + 1 + iVar4;
    local_28 = 0;
    if (0 < iVar4) {
      iVar3 = param_4 * 4;
      local_30 = iVar3;
      do {
        uVar2 = *(undefined4 *)(param_1[3] + local_28 * 4);
        puVar8 = (uint *)(iVar3 + local_4);
        puVar9 = (undefined4 *)(param_2[3] + local_30);
        uVar7 = 0;
        if (param_4 < iVar1) {
          local_2c = iVar1 - param_4;
          do {
            uVar10 = __allmul(*puVar9,0,uVar2,0);
            uVar5 = (uint)uVar10 + *puVar8;
            uVar6 = uVar5 + uVar7;
            uVar7 = uVar6 >> 0x1c |
                    ((int)((ulonglong)uVar10 >> 0x20) + (uint)CARRY4((uint)uVar10,*puVar8) +
                    (uint)CARRY4(uVar5,uVar7)) * 0x10;
            *puVar8 = uVar6 & 0xfffffff;
            puVar9 = puVar9 + 1;
            puVar8 = puVar8 + 1;
            local_2c = local_2c + -1;
          } while (local_2c != 0);
        }
        local_30 = local_30 + -4;
        local_28 = local_28 + 1;
        param_4 = param_4 + -1;
        *puVar8 = uVar7;
      } while (local_28 < iVar4);
    }
    FUN_007f5ec0(local_10);
    FUN_007fc2d0(local_10,param_3);
    FUN_007f60a0(local_10);
    iVar4 = 0;
  }
  return iVar4;
}


// ==== FUN_007ffce0 @ 0x007ffce0 ====

int FUN_007ffce0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  
  if ((*param_1 <= param_2[1]) || (iVar1 = FUN_007f6030(param_2,*param_1), iVar1 == 0)) {
    iVar1 = *param_1;
    iVar2 = *param_2;
    *param_2 = iVar1;
    puVar6 = (uint *)(param_1[3] + -4 + iVar1 * 4);
    puVar5 = (uint *)(param_2[3] + -4 + iVar1 * 4);
    uVar3 = 0;
    while (iVar1 = iVar1 + -1, -1 < iVar1) {
      uVar4 = uVar3 << 0x1b;
      uVar3 = *puVar6 & 1;
      *puVar5 = *puVar6 >> 1 | uVar4;
      puVar5 = puVar5 + -1;
      puVar6 = puVar6 + -1;
    }
    iVar1 = *param_2;
    if (iVar1 < iVar2) {
      puVar7 = (undefined4 *)(param_2[3] + iVar1 * 4);
      for (iVar2 = iVar2 - iVar1; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
    }
    param_2[2] = param_1[2];
    FUN_007f5ec0(param_2);
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_007ffd80 @ 0x007ffd80 ====

undefined4 FUN_007ffd80(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 == 0) {
    return 0;
  }
  iVar2 = param_1;
  puVar1 = (undefined1 *)register0x00000010;
  do {
    iVar2 = FUN_007f6f20(iVar2);
    if (iVar2 != 0) {
      if (iVar3 != 0) {
        puVar1 = (undefined1 *)register0x00000010;
        do {
          iVar3 = iVar3 + -1;
          FUN_007f60a0(param_1);
          param_1 = *(int *)(puVar1 + 8);
          puVar1 = puVar1 + 4;
        } while (iVar3 != 0);
      }
      return 0xfffffffe;
    }
    iVar2 = *(int *)(puVar1 + 8);
    iVar3 = iVar3 + 1;
    puVar1 = puVar1 + 4;
  } while (iVar2 != 0);
  return 0;
}


// ==== FUN_007ffdf0 @ 0x007ffdf0 ====

int FUN_007ffdf0(int *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  int local_10 [2];
  int local_8;
  int local_4;
  
  iVar2 = FUN_007e5fc0(local_10,*param_1);
  if (iVar2 == 0) {
    local_10[0] = *param_1;
    local_8 = param_1[2];
    uVar3 = 0;
    iVar2 = local_10[0];
    while (iVar2 = iVar2 + -1, -1 < iVar2) {
      uVar1 = uVar3 >> 4;
      uVar3 = *(uint *)(param_1[3] + iVar2 * 4) | uVar3 << 0x1c;
      if ((uVar1 == 0) && (uVar3 < 3)) {
        iVar4 = 0;
      }
      else {
        uVar5 = __allmul(uVar3,uVar1,0x5555555,0);
        iVar4 = (int)(uVar5 >> 0x1c);
        lVar6 = __allmul(uVar5 >> 0x1c,0xfffffffd,0xffffffff);
        for (lVar6 = lVar6 + CONCAT44(uVar1,uVar3);
            (uVar3 = (uint)lVar6, (int)((ulonglong)lVar6 >> 0x20) != 0 || (2 < uVar3));
            lVar6 = lVar6 + -3) {
          iVar4 = iVar4 + 1;
        }
      }
      *(int *)(local_4 + iVar2 * 4) = iVar4;
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = uVar3;
    }
    if (param_2 != 0) {
      FUN_007f5ec0(local_10);
      FUN_007fc2d0(local_10,param_2);
    }
    FUN_007f60a0(local_10);
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_007fff10 @ 0x007fff10 ====

int FUN_007fff10(int *param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint auStack_800 [512];
  
  if ((*param_1 + *param_2 <= param_3[1]) ||
     (iVar4 = FUN_007f6030(param_3,*param_1 + *param_2), iVar4 == 0)) {
    iVar7 = *param_1;
    iVar4 = *param_2 + iVar7;
    uVar3 = 0;
    if (param_4 < iVar4) {
      iVar5 = *param_2 + -1;
      iVar1 = param_1[3];
      iVar2 = param_2[3];
      iVar11 = param_4;
      do {
        iVar8 = iVar5;
        if (iVar11 <= iVar5) {
          iVar8 = iVar11;
        }
        puVar9 = (uint *)(iVar1 + (iVar11 - iVar8) * 4);
        puVar6 = (uint *)(iVar2 + iVar8 * 4);
        iVar12 = iVar7 - (iVar11 - iVar8);
        if (iVar8 + 1 <= iVar12) {
          iVar12 = iVar8 + 1;
        }
        if (0 < iVar12) {
          do {
            uVar3 = (ulonglong)*puVar6 * (ulonglong)*puVar9 + uVar3;
            puVar6 = puVar6 + -1;
            puVar9 = puVar9 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        uVar10 = (uint)uVar3;
        uVar3 = uVar3 >> 0x1c;
        auStack_800[iVar11] = uVar10 & 0xfffffff;
        iVar11 = iVar11 + 1;
      } while (iVar11 < iVar4);
    }
    iVar7 = *param_3;
    puVar9 = (uint *)(param_3[3] + param_4 * 4);
    *param_3 = iVar4;
    if (param_4 <= iVar4) {
      iVar5 = (iVar4 - param_4) + 1;
      puVar6 = auStack_800 + param_4;
      puVar13 = puVar9;
      for (iVar4 = iVar5; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar13 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar13 = puVar13 + 1;
      }
      param_4 = iVar5 + param_4;
      puVar9 = puVar9 + iVar5;
    }
    if (param_4 < iVar7) {
      for (iVar7 = iVar7 - param_4; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
    }
    FUN_007f5ec0(param_3);
    iVar4 = 0;
  }
  return iVar4;
}


