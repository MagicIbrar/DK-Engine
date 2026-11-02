// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x7d0000-0x7dffff

// ==== FUN_007d0000 @ 0x007d0000 ====

undefined4 FUN_007d0000(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_007cff80(param_1);
  *param_1 = uVar1;
  if ((*(byte *)((int)param_1 + 0xc) & 0x40) != 0) {
    if (*(code **)((int)param_1 + 0x1c) == (code *)0x0) {
      FUN_007d05b0(*(undefined4 *)(param_1 + 3));
    }
    else {
      (**(code **)((int)param_1 + 0x1c))(*(undefined4 *)(param_1 + 3));
    }
    *(undefined4 *)(param_1 + 3) = 0;
    *(undefined4 *)((int)param_1 + 0x1c) = 0;
  }
  *(undefined2 *)((int)param_1 + 0xc) = 4;
  return 0;
}


// ==== FUN_007d0050 @ 0x007d0050 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_007d0050(longlong *param_1)

{
  ushort uVar1;
  int iVar2;
  float10 fVar3;
  
  uVar1 = *(ushort *)((int)param_1 + 0xc);
  if ((uVar1 & 8) != 0) {
    return (float10)(double)param_1[2];
  }
  if ((uVar1 & 4) != 0) {
    return (float10)*param_1;
  }
  if ((uVar1 & 0x12) == 0) {
    return (float10)_DAT_0099d098;
  }
  iVar2 = FUN_007cfe90(param_1,1);
  if (iVar2 == 0) {
    iVar2 = FUN_007cf920(param_1);
    if (iVar2 == 0) {
      fVar3 = (float10)FUN_007d0ac0((int)param_1[3],0);
      return fVar3;
    }
  }
  return (float10)_DAT_009fffb8;
}


// ==== FUN_007d00b0 @ 0x007d00b0 ====

undefined4 FUN_007d00b0(int param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_007d0050(param_1);
  *(double *)(param_1 + 0x10) = (double)fVar1;
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
  return 0;
}


// ==== FUN_007d0100 @ 0x007d0100 ====

undefined4 FUN_007d0100(int param_1,undefined1 param_2)

{
  ushort uVar1;
  
  if ((param_1 == 0) || (uVar1 = *(ushort *)(param_1 + 0xc), (uVar1 & 1) != 0)) {
    return 0;
  }
  if ((uVar1 & 2) != 0) {
    FUN_007cfe90(param_1,param_2);
    return *(undefined4 *)(param_1 + 0x18);
  }
  if ((uVar1 & 0x10) == 0) {
    FUN_007cfee0(param_1,param_2);
  }
  return *(undefined4 *)(param_1 + 0x18);
}


// ==== FUN_007d0150 @ 0x007d0150 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007d0150(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *local_4;
  
  local_4 = (int *)0x0;
  if (param_1 == (char *)0x0) {
    *param_4 = 0;
    return 0;
  }
  cVar1 = *param_1;
  if (((cVar1 == 'Z') || (cVar1 == -0x80)) || (cVar1 == '\x7f')) {
    pcVar3 = (char *)FUN_007d06a0(*(undefined4 *)(param_1 + 0x14),*(uint *)(param_1 + 0x18) >> 1);
    local_4 = (int *)FUN_007d0550(0x40);
    if (local_4 != (int *)0x0) {
      *(undefined2 *)(local_4 + 3) = 1;
      *(undefined1 *)((int)local_4 + 0xe) = 5;
    }
    if ((pcVar3 == (char *)0x0) || (local_4 == (int *)0x0)) {
LAB_007d031b:
      FUN_007d05b0(pcVar3);
      FUN_007cfe40(local_4);
      *param_4 = 0;
      return 7;
    }
    FUN_007d0860(pcVar3);
    if (local_4 != (int *)0x0) {
      FUN_007cfbe0(local_4,pcVar3,0xffffffff,1,FUN_007d05b0);
    }
    if (((cVar1 == '\x7f') || (cVar1 == -0x80)) && ((char)param_3 == 'o')) {
      param_3 = 0x6e;
    }
    FUN_007df850(local_4,param_3,param_2);
  }
  else if (cVar1 == 'W') {
    iVar2 = FUN_007d0150(*(undefined4 *)(param_1 + 8),param_2,param_3,&local_4);
    if (iVar2 == 0) {
      iVar2 = *local_4;
      *local_4 = -iVar2;
      local_4[1] = -(local_4[1] + (uint)(iVar2 != 0));
      *(double *)(local_4 + 4) = *(double *)(local_4 + 4) * _DAT_009fd350;
      *param_4 = local_4;
      return 0;
    }
  }
  else if (cVar1 == -0x7f) {
    local_4 = (int *)FUN_007cfdf0();
    pcVar3 = (char *)FUN_007d06a0(*(int *)(param_1 + 0x14) + 1,(*(uint *)(param_1 + 0x18) >> 1) - 1)
    ;
    if ((pcVar3 != (char *)0x0) && (local_4 != (int *)0x0)) {
      FUN_007d0860(pcVar3);
      pcVar4 = pcVar3;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      uVar5 = FUN_007d11c0(pcVar3,(uint)((int)pcVar4 - (int)(pcVar3 + 1)) >> 1,0,FUN_007d05b0);
      FUN_007cfbe0(local_4,uVar5);
      FUN_007d05b0(pcVar3);
      *param_4 = local_4;
      return 0;
    }
    goto LAB_007d031b;
  }
  *param_4 = local_4;
  return 0;
}


// ==== FUN_007d0350 @ 0x007d0350 ====

undefined4 FUN_007d0350(int param_1,undefined1 param_2)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0xc);
  if ((uVar1 & 0x10) != 0) {
LAB_007d038d:
    return *(undefined4 *)(param_1 + 8);
  }
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 2) == 0) {
      FUN_007cfee0(param_1,param_2);
    }
    else {
      FUN_007cfe90(param_1,param_2);
    }
    if (*(int *)(param_1 + 0x18) != 0) goto LAB_007d038d;
  }
  return 0;
}


// ==== FUN_007d03a0 @ 0x007d03a0 ====

int FUN_007d03a0(uint *param_1,uint *param_2,int param_3)

{
  double dVar1;
  double dVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  bool bVar14;
  bool bVar15;
  
  uVar4 = (ushort)param_2[3];
  uVar5 = (ushort)param_1[3];
  uVar8 = uVar4 | uVar5;
  if ((uVar8 & 1) != 0) {
    return (uVar4 & 1) - (uVar5 & 1);
  }
  if ((uVar8 & 0xc) != 0) {
    if ((uVar5 & 0xc) != 0) {
      if ((uVar4 & 0xc) == 0) {
        return -1;
      }
      if ((uVar4 & uVar5 & 4) == 0) {
        if ((uVar5 & 8) == 0) {
          dVar1 = (double)*(longlong *)param_1;
        }
        else {
          dVar1 = *(double *)(param_1 + 4);
        }
        if ((uVar4 & 8) == 0) {
          dVar2 = (double)*(longlong *)param_2;
        }
        else {
          dVar2 = *(double *)(param_2 + 4);
        }
        if (dVar1 < dVar2) {
          return -1;
        }
        if (dVar1 <= dVar2) {
          return 0;
        }
      }
      else {
        uVar6 = param_1[1];
        uVar7 = param_2[1];
        if ((int)uVar6 <= (int)uVar7) {
          if ((int)uVar6 < (int)uVar7) {
            return -1;
          }
          if (*param_1 < *param_2) {
            return -1;
          }
          if ((int)uVar6 < (int)uVar7) {
            return 0;
          }
          if (((int)uVar6 <= (int)uVar7) && (*param_1 <= *param_2)) {
            return 0;
          }
        }
      }
    }
    return 1;
  }
  if ((uVar8 & 2) != 0) {
    if ((uVar5 & 2) == 0) {
      return 1;
    }
    if ((uVar4 & 2) == 0) {
      return -1;
    }
    if (param_3 != 0) {
      cVar3 = *(char *)((int)param_1 + 0xf);
      if (cVar3 == *(char *)(param_3 + 4)) {
        iVar9 = (**(code **)(param_3 + 0xc))
                          (*(undefined4 *)(param_3 + 8),param_1[2],param_1[6],param_2[2],param_2[6])
        ;
        return iVar9;
      }
      uVar10 = FUN_007d0100(param_2,CONCAT11((char)(uVar8 >> 8),*(char *)(param_3 + 4)));
      uVar10 = FUN_007d0350(param_2,*(undefined1 *)(param_3 + 4),uVar10);
      uVar10 = FUN_007d0100(param_1,*(undefined1 *)(param_3 + 4),uVar10);
      uVar10 = FUN_007d0350(param_1,*(undefined1 *)(param_3 + 4),uVar10);
      iVar9 = (**(code **)(param_3 + 0xc))(*(undefined4 *)(param_3 + 8),uVar10);
      FUN_007d0350(param_1,cVar3);
      FUN_007d0100(param_1,cVar3);
      FUN_007d0350(param_2,cVar3);
      FUN_007d0100(param_2,cVar3);
      return iVar9;
    }
  }
  uVar6 = param_2[2];
  uVar7 = param_1[2];
  uVar11 = uVar6;
  if ((int)uVar7 <= (int)uVar6) {
    uVar11 = uVar7;
  }
  bVar14 = false;
  iVar9 = 0;
  bVar15 = true;
  pbVar12 = (byte *)param_1[6];
  pbVar13 = (byte *)param_2[6];
  do {
    if (uVar11 == 0) break;
    uVar11 = uVar11 - 1;
    bVar14 = *pbVar12 < *pbVar13;
    bVar15 = *pbVar12 == *pbVar13;
    pbVar12 = pbVar12 + 1;
    pbVar13 = pbVar13 + 1;
  } while (bVar15);
  if (!bVar15) {
    iVar9 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
  }
  if (iVar9 == 0) {
    iVar9 = uVar7 - uVar6;
  }
  return iVar9;
}


// ==== FUN_007d0550 @ 0x007d0550 ====

undefined4 * FUN_007d0550(uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = _malloc(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    if (0 < (int)param_1) {
      DAT_00b5c4c4 = DAT_00b5c4c4 + 1;
      return (undefined4 *)0x0;
    }
  }
  else {
    puVar3 = puVar1;
    for (uVar2 = param_1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    for (param_1 = param_1 & 3; param_1 != 0; param_1 = param_1 - 1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  return puVar1;
}


// ==== FUN_007d0590 @ 0x007d0590 ====

void FUN_007d0590(size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = _malloc(param_1);
  if ((pvVar1 == (void *)0x0) && (0 < (int)param_1)) {
    DAT_00b5c4c4 = DAT_00b5c4c4 + 1;
  }
  return;
}


// ==== FUN_007d05b0 @ 0x007d05b0 ====

void FUN_007d05b0(void *param_1)

{
  if (param_1 == (void *)0x0) {
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_007d05d0 @ 0x007d05d0 ====

undefined4 * FUN_007d05d0(void *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *extraout_EAX;
  uint uVar2;
  undefined4 *puVar3;
  
  if (param_1 != (void *)0x0) {
    if (param_2 == 0) {
      _free(param_1);
      return extraout_EAX;
    }
    puVar1 = (undefined4 *)FUN_00806326(param_1,param_2);
    if ((puVar1 == (undefined4 *)0x0) && (0 < (int)param_2)) {
      DAT_00b5c4c4 = DAT_00b5c4c4 + 1;
    }
    return puVar1;
  }
  puVar1 = _malloc(param_2);
  if (puVar1 == (undefined4 *)0x0) {
    if (0 < (int)param_2) {
      DAT_00b5c4c4 = DAT_00b5c4c4 + 1;
      return (undefined4 *)0x0;
    }
  }
  else {
    puVar3 = puVar1;
    for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  return puVar1;
}


// ==== FUN_007d0640 @ 0x007d0640 ====

void * FUN_007d0640(char *param_1)

{
  char cVar1;
  char *pcVar2;
  void *pvVar3;
  int iVar4;
  
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pvVar3 = _malloc((size_t)(pcVar2 + (1 - (int)(param_1 + 1))));
  if (pvVar3 == (void *)0x0) {
    if (0 < (int)(pcVar2 + (1 - (int)(param_1 + 1)))) {
      DAT_00b5c4c4 = DAT_00b5c4c4 + 1;
      return (void *)0x0;
    }
  }
  else {
    iVar4 = (int)pvVar3 - (int)param_1;
    do {
      cVar1 = *param_1;
      param_1[iVar4] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
  }
  return pvVar3;
}


// ==== FUN_007d06a0 @ 0x007d06a0 ====

undefined4 * FUN_007d06a0(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar1 = _malloc(param_2 + 1);
  if (puVar1 == (undefined4 *)0x0) {
    if (0 < (int)(param_2 + 1)) {
      DAT_00b5c4c4 = DAT_00b5c4c4 + 1;
      return (undefined4 *)0x0;
    }
  }
  else {
    puVar3 = puVar1;
    for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    *(undefined1 *)((int)puVar1 + param_2) = 0;
  }
  return puVar1;
}


// ==== FUN_007d0700 @ 0x007d0700 ====

void FUN_007d0700(undefined4 *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  char *_Size;
  
  pcVar4 = param_2;
  if (param_1 != (undefined4 *)0x0) {
    _Size = (char *)0x1;
    if (param_2 != (char *)0x0) {
      puVar5 = &param_2;
      pcVar3 = param_2;
      do {
        pcVar1 = pcVar3 + 1;
        do {
          cVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar2 != '\0');
        puVar5 = puVar5 + 1;
        _Size = pcVar3 + ((int)_Size - (int)pcVar1);
        pcVar3 = (char *)*puVar5;
      } while (pcVar3 != (char *)0x0);
    }
    if ((void *)*param_1 != (void *)0x0) {
      _free((void *)*param_1);
      return;
    }
    pcVar3 = _malloc((size_t)_Size);
    if ((pcVar3 == (char *)0x0) && (0 < (int)_Size)) {
      DAT_00b5c4c4 = DAT_00b5c4c4 + 1;
    }
    *param_1 = pcVar3;
    if ((pcVar3 != (char *)0x0) && (*pcVar3 = '\0', pcVar4 != (char *)0x0)) {
      puVar5 = &param_2;
      do {
        iVar6 = (int)pcVar3 - (int)pcVar4;
        do {
          cVar2 = *pcVar4;
          pcVar4[iVar6] = cVar2;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        pcVar4 = pcVar3;
        do {
          pcVar3 = pcVar4;
          pcVar4 = pcVar3 + 1;
        } while (*pcVar3 != '\0');
        puVar5 = puVar5 + 1;
        pcVar4 = (char *)*puVar5;
      } while (pcVar4 != (char *)0x0);
    }
  }
  return;
}


// ==== FUN_007d07b0 @ 0x007d07b0 ====

void FUN_007d07b0(int param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x70) == 0) {
      iVar1 = FUN_007cfdf0();
      *(int *)(param_1 + 0x70) = iVar1;
      if (iVar1 == 0) {
        return;
      }
    }
    *(undefined4 *)(param_1 + 0xc) = param_2;
    if (param_3 != 0) {
      uVar2 = FUN_007e47e0(param_3,&param_4);
      FUN_007cfe10(*(undefined4 *)(param_1 + 0x70),0xffffffff,uVar2,1,FUN_007d05b0);
      return;
    }
    FUN_007cfe10(*(undefined4 *)(param_1 + 0x70),0,0,1,0);
  }
  return;
}


// ==== FUN_007d0820 @ 0x007d0820 ====

void FUN_007d0820(int param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  if (*(void **)(param_1 + 8) == (void *)0x0) {
    uVar1 = FUN_007e47e0(param_2,&param_3);
    *(undefined4 *)(param_1 + 8) = uVar1;
    return;
  }
  _free(*(void **)(param_1 + 8));
  return;
}


// ==== FUN_007d0860 @ 0x007d0860 ====

void FUN_007d0860(char *param_1)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  char *pcVar5;
  
  if (param_1 != (char *)0x0) {
    cVar4 = *param_1;
    if ((cVar4 != '\"') && (cVar4 != '\'')) {
      if (cVar4 != '[') {
        return;
      }
      cVar4 = ']';
    }
    iVar2 = 0;
    if (param_1[1] != '\0') {
      pcVar5 = param_1 + 2;
      pcVar1 = param_1;
      do {
        pcVar3 = pcVar1 + 1;
        if (*pcVar3 == cVar4) {
          if (*pcVar5 != cVar4) {
            param_1[iVar2] = '\0';
            return;
          }
          param_1[iVar2] = cVar4;
          pcVar5 = pcVar5 + 1;
          pcVar3 = pcVar1 + 2;
        }
        else {
          param_1[iVar2] = *pcVar3;
        }
        iVar2 = iVar2 + 1;
        pcVar5 = pcVar5 + 1;
        pcVar1 = pcVar3;
      } while (pcVar3[1] != '\0');
      return;
    }
  }
  return;
}


// ==== FUN_007d08e0 @ 0x007d08e0 ====

int FUN_007d08e0(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  
  bVar2 = *param_1;
  while ((bVar2 != 0 && ((&DAT_009fffc0)[bVar2] == (&DAT_009fffc0)[*param_2]))) {
    pbVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    bVar2 = *pbVar1;
  }
  return (uint)(byte)(&DAT_009fffc0)[*param_1] - (uint)(byte)(&DAT_009fffc0)[*param_2];
}


// ==== FUN_007d0930 @ 0x007d0930 ====

int FUN_007d0930(byte *param_1,byte *param_2,int param_3)

{
  while (0 < param_3) {
    if ((*param_1 == 0) || ((&DAT_009fffc0)[*param_1] != (&DAT_009fffc0)[*param_2])) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    param_3 = param_3 + -1;
  }
  if (param_3 + -1 < 0) {
    return 0;
  }
  return (uint)(byte)(&DAT_009fffc0)[*param_1] - (uint)(byte)(&DAT_009fffc0)[*param_2];
}


// ==== FUN_007d0990 @ 0x007d0990 ====

bool FUN_007d0990(byte *param_1,undefined4 *param_2,char param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (param_3 != '\x01') + 1;
  if (param_3 == '\x03') {
    param_1 = param_1 + 1;
  }
  if ((*param_1 == 0x2d) || (*param_1 == 0x2b)) {
    param_1 = param_1 + iVar3;
  }
  iVar2 = _isdigit((uint)*param_1);
  if (iVar2 == 0) {
    return false;
  }
  param_1 = param_1 + iVar3;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  iVar2 = _isdigit((uint)*param_1);
  while (iVar2 != 0) {
    pbVar1 = param_1 + iVar3;
    param_1 = param_1 + iVar3;
    iVar2 = _isdigit((uint)*pbVar1);
  }
  if (*param_1 == 0x2e) {
    pbVar1 = param_1 + iVar3;
    param_1 = param_1 + iVar3;
    iVar2 = _isdigit((uint)*pbVar1);
    if (iVar2 == 0) {
      return false;
    }
    iVar2 = _isdigit((uint)*param_1);
    while (iVar2 != 0) {
      pbVar1 = param_1 + iVar3;
      param_1 = param_1 + iVar3;
      iVar2 = _isdigit((uint)*pbVar1);
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 1;
    }
  }
  if ((*param_1 == 0x65) || (*param_1 == 0x45)) {
    pbVar1 = param_1 + iVar3;
    param_1 = param_1 + iVar3;
    if ((*pbVar1 == 0x2b) || (*pbVar1 == 0x2d)) {
      param_1 = param_1 + iVar3;
    }
    iVar2 = _isdigit((uint)*param_1);
    if (iVar2 == 0) {
      return false;
    }
    iVar2 = _isdigit((uint)*param_1);
    while (iVar2 != 0) {
      pbVar1 = param_1 + iVar3;
      param_1 = param_1 + iVar3;
      iVar2 = _isdigit((uint)*pbVar1);
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 1;
    }
  }
  return *param_1 == 0;
}


// ==== FUN_007d0ac0 @ 0x007d0ac0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_007d0ac0(byte *param_1,undefined4 *param_2)

{
  byte bVar1;
  double dVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  float10 fVar8;
  int local_20;
  double local_18;
  
  local_18 = _DAT_0099d098;
  iVar5 = 1;
  local_20 = 1;
  if (*param_1 == 0x2d) {
    local_20 = -1;
LAB_007d0af6:
    param_1 = param_1 + 1;
  }
  else if (*param_1 == 0x2b) goto LAB_007d0af6;
  iVar3 = _isdigit((uint)*param_1);
  dVar2 = _DAT_0099d0a0;
  while (_DAT_0099d0a0 = dVar2, iVar3 != 0) {
    bVar1 = *param_1;
    pbVar6 = param_1 + 1;
    param_1 = param_1 + 1;
    local_18 = local_18 * _DAT_009fdca8 + (double)((char)bVar1 + -0x30);
    iVar3 = _isdigit((uint)*pbVar6);
    dVar2 = _DAT_0099d0a0;
  }
  if (*param_1 == 0x2e) {
    iVar3 = _isdigit((uint)param_1[1]);
    pbVar6 = param_1;
    while (param_1 = pbVar6 + 1, iVar3 != 0) {
      local_18 = local_18 * _DAT_009fdca8 + (double)((char)*param_1 + -0x30);
      dVar2 = dVar2 * _DAT_009fdca8;
      iVar3 = _isdigit((uint)pbVar6[2]);
      pbVar6 = param_1;
    }
    fVar8 = (float10)local_18 / (float10)dVar2;
    local_18 = (double)fVar8;
  }
  else {
    fVar8 = (float10)local_18;
  }
  dVar2 = _DAT_0099d0a0;
  if ((*param_1 != 0x65) && (*param_1 != 0x45)) goto LAB_007d0c8d;
  uVar7 = 0;
  if (param_1[1] == 0x2d) {
    iVar5 = -1;
LAB_007d0bde:
    pbVar6 = param_1 + 2;
  }
  else {
    pbVar6 = param_1 + 1;
    if (param_1[1] == 0x2b) goto LAB_007d0bde;
  }
  param_1 = pbVar6;
  iVar3 = _isdigit((uint)*param_1);
  if (iVar3 == 0) {
    fVar8 = (float10)dVar2;
  }
  else {
    do {
      bVar1 = *param_1;
      pbVar6 = param_1 + 1;
      param_1 = param_1 + 1;
      uVar7 = (char)bVar1 + -0x30 + uVar7 * 10;
      iVar3 = _isdigit((uint)*pbVar6);
    } while (iVar3 != 0);
    fVar8 = (float10)dVar2;
    if (0x3f < (int)uVar7) {
      uVar4 = uVar7 >> 6;
      uVar7 = uVar7 + uVar4 * -0x40;
      do {
        uVar4 = uVar4 - 1;
        fVar8 = fVar8 * (float10)_DAT_00a000d0;
      } while (uVar4 != 0);
    }
    if (0xf < (int)uVar7) {
      uVar4 = uVar7 >> 4;
      uVar7 = uVar7 + uVar4 * -0x10;
      do {
        uVar4 = uVar4 - 1;
        fVar8 = fVar8 * (float10)_DAT_00a000c8;
      } while (uVar4 != 0);
    }
    if (3 < (int)uVar7) {
      uVar4 = uVar7 >> 2;
      uVar7 = uVar7 + uVar4 * -4;
      do {
        uVar4 = uVar4 - 1;
        fVar8 = fVar8 * (float10)_DAT_00a000c0;
      } while (uVar4 != 0);
    }
    if (0 < (int)uVar7) {
      do {
        uVar7 = uVar7 - 1;
        fVar8 = fVar8 * (float10)_DAT_009fdca8;
      } while (uVar7 != 0);
    }
  }
  if (iVar5 < 0) {
    fVar8 = (float10)local_18 / fVar8;
  }
  else {
    fVar8 = fVar8 * (float10)local_18;
  }
LAB_007d0c8d:
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_1;
  }
  if (local_20 < 0) {
    fVar8 = -fVar8;
  }
  return fVar8;
}


// ==== FUN_007d0cb0 @ 0x007d0cb0 ====

undefined4 FUN_007d0cb0(byte *param_1,int *param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  longlong lVar11;
  
  iVar5 = 0;
  iVar4 = 0;
  if (*param_1 == 0x2d) {
    bVar9 = true;
  }
  else {
    bVar9 = false;
    if (*param_1 != 0x2b) goto LAB_007d0cd2;
  }
  param_1 = param_1 + 1;
LAB_007d0cd2:
  iVar7 = 0;
  bVar2 = *param_1;
  while ((iVar3 = (int)(char)bVar2, 0x2f < iVar3 && (iVar3 < 0x3a))) {
    lVar11 = __allmul(iVar5,iVar4,10,0);
    iVar1 = iVar7 + 1;
    uVar6 = (uint)(lVar11 + iVar3);
    iVar5 = uVar6 - 0x30;
    iVar4 = (int)((ulonglong)(lVar11 + iVar3) >> 0x20) - (uint)(uVar6 < 0x30);
    iVar7 = iVar7 + 1;
    bVar2 = param_1[iVar1];
  }
  if (bVar9) {
    bVar9 = iVar5 != 0;
    iVar5 = -iVar5;
    iVar4 = -(iVar4 + (uint)bVar9);
  }
  *param_2 = iVar5;
  param_2[1] = iVar4;
  if ((iVar3 == 0) && (0 < iVar7)) {
    if (iVar7 < 0x13) {
      return 1;
    }
    if (iVar7 == 0x13) {
      iVar4 = 0x13;
      bVar9 = false;
      iVar5 = 0;
      bVar10 = true;
      pbVar8 = &DAT_00a000d8;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *param_1 < *pbVar8;
        bVar10 = *param_1 == *pbVar8;
        param_1 = param_1 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar10);
      if (!bVar10) {
        iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      }
      if (iVar5 < 1) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_007d0d70 @ 0x007d0d70 ====

undefined4 FUN_007d0d70(void)

{
  byte bVar1;
  byte *in_EAX;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  
  if ((*in_EAX == 0x2d) || (*in_EAX == 0x2b)) {
    in_EAX = in_EAX + 1;
  }
  bVar1 = *in_EAX;
  iVar2 = 0;
  if ('/' < (char)bVar1) {
    do {
      if ('9' < (char)bVar1) break;
      bVar1 = in_EAX[iVar2 + 1];
      iVar2 = iVar2 + 1;
    } while ('/' < (char)bVar1);
    if (9 < iVar2) {
      if (iVar2 == 10) {
        iVar3 = 10;
        bVar5 = false;
        iVar2 = 0;
        bVar6 = true;
        pbVar4 = &DAT_00a000ec;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar5 = *in_EAX < *pbVar4;
          bVar6 = *in_EAX == *pbVar4;
          in_EAX = in_EAX + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar6);
        if (!bVar6) {
          iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        }
        if (iVar2 < 1) {
          return 1;
        }
      }
      return 0;
    }
  }
  return 1;
}


// ==== FUN_007d0dd0 @ 0x007d0dd0 ====

undefined4 FUN_007d0dd0(undefined4 param_1,long *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_007d0d70();
  if ((int)uVar2 == 0) {
    return 0;
  }
  lVar1 = _atol((char *)((ulonglong)uVar2 >> 0x20));
  *param_2 = lVar1;
  return 1;
}


// ==== FUN_007d0e00 @ 0x007d0e00 ====

undefined4 FUN_007d0e00(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  
  if ((*param_1 == 0x2d) || (*param_1 == 0x2b)) {
    param_1 = param_1 + 1;
  }
  bVar1 = *param_1;
  iVar2 = 0;
  if ('/' < (char)bVar1) {
    do {
      if ('9' < (char)bVar1) break;
      bVar1 = param_1[iVar2 + 1];
      iVar2 = iVar2 + 1;
    } while ('/' < (char)bVar1);
    if (0x12 < iVar2) {
      if (iVar2 == 0x13) {
        iVar3 = 0x13;
        bVar5 = false;
        iVar2 = 0;
        bVar6 = true;
        pbVar4 = &DAT_00a000d8;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar5 = *param_1 < *pbVar4;
          bVar6 = *param_1 == *pbVar4;
          param_1 = param_1 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar6);
        if (!bVar6) {
          iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        }
        if (iVar2 < 1) {
          return 1;
        }
      }
      return 0;
    }
  }
  return 1;
}


// ==== FUN_007d0e60 @ 0x007d0e60 ====

undefined4 FUN_007d0e60(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (iVar1 == -0x5fd65969) {
    *(undefined4 *)(param_1 + 0x30) = 0xf03b7906;
    return 0;
  }
  if ((iVar1 == -0xfc486fa) || (iVar1 == -0x4aca86d0)) {
    *(undefined4 *)(param_1 + 0x30) = 0xb5357930;
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  }
  return 1;
}


// ==== FUN_007d0ea0 @ 0x007d0ea0 ====

undefined4 FUN_007d0ea0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (iVar1 == -0xfc486fa) {
    *(undefined4 *)(param_1 + 0x30) = 0xa029a697;
    return 0;
  }
  if ((iVar1 == -0x5fd65969) || (iVar1 == -0x4aca86d0)) {
    *(undefined4 *)(param_1 + 0x30) = 0xb5357930;
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  }
  return 1;
}


// ==== FUN_007d0ee0 @ 0x007d0ee0 ====

undefined4 FUN_007d0ee0(int param_1)

{
  int iVar1;
  
  if ((param_1 == 0) ||
     (((iVar1 = *(int *)(param_1 + 0x30), iVar1 != -0x60c3d2cd && (iVar1 != -0x5fd65969)) &&
      (iVar1 != -0xfc486fa)))) {
    return 1;
  }
  return 0;
}


// ==== FUN_007d0f10 @ 0x007d0f10 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007d0f10(byte *param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte local_10 [12];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if ((param_3 & 0xff000000) != 0) {
    param_1[8] = (byte)param_2;
    uVar2 = (param_2 >> 8 | param_3 << 0x18) >> 7;
    param_1[7] = (byte)(param_2 >> 8) | 0x80;
    uVar3 = (uVar2 | (param_3 >> 8) << 0x19) >> 7;
    param_1[6] = (byte)uVar2 | 0x80;
    uVar2 = (uVar3 | (param_3 >> 0xf) << 0x19) >> 7;
    param_1[5] = (byte)uVar3 | 0x80;
    uVar3 = (uVar2 | (param_3 >> 0x16) << 0x19) >> 7;
    uVar6 = uVar3 | (param_3 >> 0x1d) << 0x19;
    param_1[4] = (byte)uVar2 | 0x80;
    param_1[3] = (byte)uVar3 | 0x80;
    param_1[2] = (byte)(uVar6 >> 7) | 0x80;
    param_1[1] = (byte)(uVar6 >> 0xe) | 0x80;
    *param_1 = (byte)(uVar6 >> 0x15) | 0x80;
    return 9;
  }
  iVar7 = 0;
  do {
    iVar5 = iVar7;
    bVar4 = (byte)param_2;
    param_2 = param_2 >> 7 | param_3 << 0x19;
    local_10[iVar5] = bVar4 | 0x80;
    param_3 = param_3 >> 7;
    iVar7 = iVar5 + 1;
  } while (param_2 != 0 || param_3 != 0);
  local_10[0] = local_10[0] & 0x7f;
  if (-1 < iVar5) {
    do {
      pbVar1 = local_10 + iVar5;
      iVar5 = iVar5 + -1;
      *param_1 = *pbVar1;
      param_1 = param_1 + 1;
    } while (-1 < iVar5);
  }
  return iVar7;
}


// ==== FUN_007d1020 @ 0x007d1020 ====

int FUN_007d1020(byte *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  bVar1 = *param_1;
  if (-1 < (char)bVar1) {
    *param_2 = (uint)bVar1;
    param_2[1] = 0;
    return 1;
  }
  bVar2 = param_1[1];
  uVar3 = (bVar1 & 0x7f) << 7;
  if (-1 < (char)bVar2) {
    *param_2 = uVar3 | bVar2;
    param_2[1] = 0;
    return 2;
  }
  bVar1 = param_1[2];
  uVar3 = (bVar2 & 0x7f | uVar3) << 7;
  if (-1 < (char)bVar1) {
    *param_2 = uVar3 | bVar1;
    param_2[1] = 0;
    return 3;
  }
  bVar2 = param_1[3];
  uVar3 = (bVar1 & 0x7f | uVar3) << 7;
  if (-1 < (char)bVar2) {
    *param_2 = uVar3 | bVar2;
    param_2[1] = 0;
    return 4;
  }
  uVar3 = bVar2 & 0x7f | uVar3;
  uVar4 = 0;
  iVar5 = 4;
  do {
    bVar1 = param_1[iVar5];
    iVar5 = iVar5 + 1;
    if (iVar5 == 9) {
      param_2[1] = uVar4 << 8 | uVar3 >> 0x18;
      *param_2 = uVar3 << 8 | (uint)bVar1;
      return 9;
    }
    uVar4 = uVar4 << 7 | uVar3 >> 0x19;
    uVar3 = (uint)(bVar1 & 0x7f) | uVar3 << 7;
  } while ((char)bVar1 < '\0');
  param_2[1] = uVar4;
  *param_2 = uVar3;
  return iVar5;
}


// ==== FUN_007d1120 @ 0x007d1120 ====

int FUN_007d1120(byte *param_1,uint *param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  
  bVar2 = *param_1;
  if (-1 < (char)bVar2) {
    *param_2 = (uint)bVar2;
    return 1;
  }
  bVar3 = param_1[1];
  uVar5 = (bVar2 & 0x7f) << 7;
  if (-1 < (char)bVar3) {
    *param_2 = uVar5 | bVar3;
    return 2;
  }
  uVar5 = bVar3 & 0x7f | uVar5;
  iVar4 = 2;
  do {
    pbVar1 = param_1 + iVar4;
    uVar5 = uVar5 << 7 | *pbVar1 & 0x7f;
    iVar4 = iVar4 + 1;
    if (-1 < (char)*pbVar1) break;
  } while (iVar4 < 9);
  *param_2 = uVar5;
  return iVar4;
}


// ==== FUN_007d1190 @ 0x007d1190 ====

void FUN_007d1190(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    param_1 = param_1 >> 7 | param_2 << 0x19;
    param_2 = param_2 >> 7;
    iVar1 = iVar1 + 1;
    if (param_1 == 0 && param_2 == 0) {
      return;
    }
  } while (iVar1 < 9);
  return;
}


// ==== FUN_007d11c0 @ 0x007d11c0 ====

undefined4 * FUN_007d11c0(char *param_1)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  byte bVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  pcVar3 = param_1;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  uVar4 = (int)pcVar3 - (int)(param_1 + 1);
  uVar5 = uVar4 & 0x80000001;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
  }
  if (uVar5 != 0) {
    return (undefined4 *)0x0;
  }
  uVar5 = (int)uVar4 / 2;
  puVar6 = _malloc(uVar5);
  if (puVar6 == (undefined4 *)0x0) {
    if (0 < (int)uVar5) {
      DAT_00b5c4c4 = DAT_00b5c4c4 + 1;
    }
  }
  else {
    puVar9 = puVar6;
    for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar9 = 0;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
  }
  uVar5 = 0;
  if (0 < (int)uVar4) {
    do {
      cVar2 = param_1[uVar5];
      if ((cVar2 < '0') || ('9' < cVar2)) {
        if ((cVar2 < 'a') || ('f' < cVar2)) {
          cVar2 = cVar2 + -0x37;
        }
        else {
          cVar2 = cVar2 + -0x57;
        }
      }
      else {
        cVar2 = cVar2 + -0x30;
      }
      cVar1 = param_1[uVar5 + 1];
      if ((cVar1 < '0') || ('9' < cVar1)) {
        if ((cVar1 < 'a') || ('f' < cVar1)) {
          bVar7 = cVar1 - 0x37;
        }
        else {
          bVar7 = cVar1 + 0xa9;
        }
      }
      else {
        bVar7 = cVar1 - 0x30;
      }
      uVar8 = uVar5 >> 1;
      uVar5 = uVar5 + 2;
      *(byte *)(uVar8 + (int)puVar6) = cVar2 << 4 | bVar7;
    } while ((int)uVar5 < (int)uVar4);
  }
  return puVar6;
}


// ==== FUN_007d12a0 @ 0x007d12a0 ====

undefined4 FUN_007d12a0(LPCSTR param_1)

{
  DeleteFileA(param_1);
  return 0;
}


// ==== FUN_007d12b0 @ 0x007d12b0 ====

bool FUN_007d12b0(LPCSTR param_1)

{
  DWORD DVar1;
  
  DVar1 = GetFileAttributesA(param_1);
  return DVar1 != 0xffffffff;
}


// ==== FUN_007d12d0 @ 0x007d12d0 ====

undefined4 FUN_007d12d0(LPCSTR param_1,undefined4 *param_2,undefined4 *param_3)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateFileA(param_1,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,4,0x10000080,(HANDLE)0x0);
  if (pvVar1 == (HANDLE)0xffffffff) {
    pvVar1 = CreateFileA(param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,4,0x10000080,(HANDLE)0x0);
    if (pvVar1 == (HANDLE)0xffffffff) {
      return 0xe;
    }
    *param_3 = 1;
  }
  else {
    *param_3 = 0;
  }
  *param_2 = pvVar1;
  *(undefined1 *)(param_2 + 1) = 0;
  *(undefined2 *)((int)param_2 + 6) = 0;
  *(undefined1 *)((int)param_2 + 5) = 1;
  return 0;
}


// ==== FUN_007d1350 @ 0x007d1350 ====

undefined4 FUN_007d1350(LPCSTR param_1,undefined4 *param_2,int param_3)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateFileA(param_1,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,
                       (-(uint)(param_3 != 0) & 0x4000100) + 0x10000000,(HANDLE)0x0);
  if (pvVar1 == (HANDLE)0xffffffff) {
    return 0xe;
  }
  *param_2 = pvVar1;
  *(undefined1 *)(param_2 + 1) = 0;
  *(undefined2 *)((int)param_2 + 6) = 0;
  *(undefined1 *)((int)param_2 + 5) = 1;
  return 0;
}


// ==== FUN_007d13a0 @ 0x007d13a0 ====

undefined4 FUN_007d13a0(LPCSTR param_1,undefined4 *param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateFileA(param_1,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x10000080,(HANDLE)0x0);
  if (pvVar1 == (HANDLE)0xffffffff) {
    return 0xe;
  }
  *param_2 = pvVar1;
  *(undefined1 *)(param_2 + 1) = 0;
  *(undefined2 *)((int)param_2 + 6) = 0;
  *(undefined1 *)((int)param_2 + 5) = 1;
  return 0;
}


// ==== FUN_007d13e0 @ 0x007d13e0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007d13e0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  DWORD DVar4;
  int iVar5;
  int iVar6;
  CHAR local_13c;
  char local_13b;
  char acStack_13a [278];
  undefined1 local_24;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (DAT_00b5c4cc == (char *)0x0) {
    GetTempPathA(0x118,&local_13c);
  }
  else {
    _strncpy(&local_13c,DAT_00b5c4cc,0x118);
    local_24 = 0;
  }
  pcVar2 = &local_13c;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  for (iVar3 = (int)pcVar2 - (int)&local_13b; (0 < iVar3 && (acStack_13a[iVar3 + -3] == '\\'));
      iVar3 = iVar3 + -1) {
  }
  (&local_13c)[iVar3] = '\0';
  do {
    _sprintf(param_1,s__s_sqlite__00a000f8,&local_13c);
    pcVar2 = param_1;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    FUN_007e6500(0xf,param_1 + ((int)pcVar2 - (int)(param_1 + 1)));
    iVar5 = 3;
    iVar3 = (int)pcVar2 - (int)(param_1 + 1);
    do {
      param_1[iVar3] =
           s_abcdefghijklmnopqrstuvwxyzABCDEF_00b49160[(uint)(byte)param_1[iVar3] % 0x3e];
      param_1[iVar3 + 1] =
           s_abcdefghijklmnopqrstuvwxyzABCDEF_00b49160[(uint)(byte)param_1[iVar3 + 1] % 0x3e];
      param_1[iVar3 + 2] =
           s_abcdefghijklmnopqrstuvwxyzABCDEF_00b49160[(uint)(byte)param_1[iVar3 + 2] % 0x3e];
      param_1[iVar3 + 3] =
           s_abcdefghijklmnopqrstuvwxyzABCDEF_00b49160[(uint)(byte)param_1[iVar3 + 3] % 0x3e];
      iVar6 = iVar3 + 5;
      iVar5 = iVar5 + -1;
      param_1[iVar3 + 4] =
           s_abcdefghijklmnopqrstuvwxyzABCDEF_00b49160[(uint)(byte)param_1[iVar3 + 4] % 0x3e];
      iVar3 = iVar6;
    } while (iVar5 != 0);
    param_1[iVar6] = '\0';
    DVar4 = GetFileAttributesA(param_1);
  } while (DVar4 != 0xffffffff);
  return 0;
}


// ==== FUN_007d1530 @ 0x007d1530 ====

undefined4 FUN_007d1530(undefined4 *param_1)

{
  if (*(char *)((int)param_1 + 5) != '\0') {
    CloseHandle((HANDLE)*param_1);
    *(undefined1 *)((int)param_1 + 5) = 0;
  }
  return 0;
}


// ==== FUN_007d1550 @ 0x007d1550 ====

byte FUN_007d1550(undefined4 *param_1,LPVOID param_2,DWORD param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  
  DVar1 = param_3;
  BVar2 = ReadFile((HANDLE)*param_1,param_2,param_3,&param_3,(LPOVERLAPPED)0x0);
  if (BVar2 == 0) {
    return (DVar1 == 0) - 1U & 10;
  }
  return (param_3 == DVar1) - 1U & 10;
}


// ==== FUN_007d15a0 @ 0x007d15a0 ====

undefined4 FUN_007d15a0(undefined4 *param_1,LPCVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD nNumberOfBytesToWrite;
  
  if (0 < (int)param_3) {
    nNumberOfBytesToWrite = param_3;
    do {
      BVar1 = WriteFile((HANDLE)*param_1,param_2,nNumberOfBytesToWrite,&param_3,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) {
        return 0xd;
      }
      if (param_3 == 0) break;
      nNumberOfBytesToWrite = nNumberOfBytesToWrite - param_3;
      param_2 = (LPCVOID)((int)param_2 + param_3);
    } while (0 < (int)nNumberOfBytesToWrite);
    if ((int)nNumberOfBytesToWrite <= (int)param_3) {
      return 0;
    }
  }
  return 0xd;
}


// ==== FUN_007d1600 @ 0x007d1600 ====

undefined4 FUN_007d1600(undefined4 *param_1,LONG param_2,LONG param_3)

{
  LONG local_4;
  
  local_4 = param_3;
  SetFilePointer((HANDLE)*param_1,param_2,&local_4,0);
  return 0;
}


// ==== FUN_007d1630 @ 0x007d1630 ====

int FUN_007d1630(undefined4 *param_1)

{
  BOOL BVar1;
  
  BVar1 = FlushFileBuffers((HANDLE)*param_1);
  return (-(uint)(BVar1 != 0) & 0xfffffff6) + 10;
}


// ==== FUN_007d1650 @ 0x007d1650 ====

undefined4 FUN_007d1650(undefined4 *param_1,LONG param_2,LONG param_3)

{
  LONG local_4;
  
  local_4 = param_3;
  SetFilePointer((HANDLE)*param_1,param_2,&local_4,0);
  SetEndOfFile((HANDLE)*param_1);
  return 0;
}


// ==== FUN_007d1690 @ 0x007d1690 ====

undefined4 FUN_007d1690(undefined4 *param_1,longlong *param_2)

{
  DWORD DVar1;
  longlong lVar2;
  DWORD local_4;
  
  DVar1 = GetFileSize((HANDLE)*param_1,&local_4);
  lVar2 = __allmul(local_4,0,0,1);
  *param_2 = lVar2 + (ulonglong)DVar1;
  return 0;
}


// ==== FUN_007d16d0 @ 0x007d16d0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_007d16d0(void)

{
  _OSVERSIONINFOA local_98;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (DAT_00b5c4d0 == 0) {
    local_98.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_98);
    DAT_00b5c4d0 = (local_98.dwPlatformId == 2) + 1;
  }
  return DAT_00b5c4d0 == 2;
}


// ==== FUN_007d1730 @ 0x007d1730 ====

void FUN_007d1730(void)

{
  int iVar1;
  short sVar2;
  undefined4 *unaff_ESI;
  uint local_18;
  _OVERLAPPED local_14;
  
  iVar1 = FUN_007d16d0();
  if (iVar1 == 0) {
    FUN_007e6500(4,&local_18);
    sVar2 = (short)((local_18 & 0x7fffffff) % 0x1fd);
    *(short *)((int)unaff_ESI + 6) = sVar2;
    LockFile((HANDLE)*unaff_ESI,(int)sVar2 + 0x40000002,0,1,0);
    return;
  }
  local_14.u.Pointer = (PVOID)0x40000002;
  local_14.u.s.OffsetHigh = 0;
  local_14.hEvent = (HANDLE)0x0;
  LockFileEx((HANDLE)*unaff_ESI,1,0,0x1fe,0,&local_14);
  return;
}


// ==== FUN_007d17c0 @ 0x007d17c0 ====

void FUN_007d17c0(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  
  iVar1 = FUN_007d16d0();
  if (iVar1 == 0) {
    UnlockFile((HANDLE)*unaff_ESI,(int)*(short *)((int)unaff_ESI + 6) + 0x40000002,0,1,0);
    return;
  }
  UnlockFile((HANDLE)*unaff_ESI,0x40000002,0,0x1fe,0);
  return;
}


// ==== FUN_007d1800 @ 0x007d1800 ====

bool FUN_007d1800(LPCSTR param_1)

{
  char cVar1;
  int iVar2;
  LPCSTR pCVar3;
  DWORD DVar4;
  
  if (param_1 != (LPCSTR)0x0) {
    iVar2 = FUN_007d16d0();
    if (iVar2 == 0) {
      pCVar3 = param_1;
      do {
        cVar1 = *pCVar3;
        pCVar3 = pCVar3 + 1;
      } while (cVar1 != '\0');
      if (0x104 < (uint)((int)pCVar3 - (int)(param_1 + 1))) {
        return false;
      }
    }
    DVar4 = GetFileAttributesA(param_1);
    if (DVar4 != 0xffffffff) {
      return ((byte)DVar4 & 0x10) == 0x10;
    }
  }
  return false;
}


// ==== FUN_007d1850 @ 0x007d1850 ====

undefined4 FUN_007d1850(undefined4 *param_1,int param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  BOOL BVar3;
  int iVar4;
  
  puVar2 = param_1;
  bVar1 = *(byte *)(param_1 + 1);
  BVar3 = 0;
  if (param_2 <= (int)(uint)bVar1) {
    return 0;
  }
  if (bVar1 == 0) {
LAB_007d188e:
    iVar4 = 3;
    do {
      iVar4 = iVar4 + -1;
      BVar3 = LockFile((HANDLE)*param_1,0x40000000,0,1,0);
      if (BVar3 != 0) break;
      Sleep(1);
    } while (0 < iVar4);
    iVar4 = BVar3;
LAB_007d18bc:
    param_1._0_1_ = bVar1;
    if (param_2 == 1) {
      if (iVar4 != 0) {
        iVar4 = FUN_007d1730();
        if (iVar4 != 0) {
          param_1._0_1_ = 1;
        }
LAB_007d18d8:
        bVar1 = (byte)param_1;
      }
    }
    else if (param_2 == 2) {
      if (iVar4 != 0) {
        iVar4 = LockFile((HANDLE)*param_1,0x40000001,0,1,0);
        if (iVar4 != 0) {
          param_1._0_1_ = 2;
        }
        goto LAB_007d18d8;
      }
    }
    else if ((param_2 == 4) && (iVar4 != 0)) goto LAB_007d193c;
    param_1._0_1_ = bVar1;
    if ((BVar3 != 0) && (param_2 == 1)) {
      UnlockFile((HANDLE)*puVar2,0x40000000,0,1,0);
    }
  }
  else {
    iVar4 = 1;
    if (param_2 != 4) goto LAB_007d18bc;
    if (bVar1 == 2) goto LAB_007d188e;
LAB_007d193c:
    param_1._0_1_ = 3;
    FUN_007d17c0();
    iVar4 = LockFile((HANDLE)*puVar2,0x40000002,0,0x1fe,0);
    if (iVar4 == 0) goto LAB_007d196c;
    param_1._0_1_ = 4;
  }
  if (iVar4 != 0) {
    *(byte *)(puVar2 + 1) = (byte)param_1;
    return 0;
  }
LAB_007d196c:
  *(byte *)(puVar2 + 1) = (byte)param_1;
  return 5;
}


// ==== FUN_007d1980 @ 0x007d1980 ====

bool FUN_007d1980(undefined4 *param_1)

{
  BOOL BVar1;
  
  if (1 < *(byte *)(param_1 + 1)) {
    return true;
  }
  BVar1 = LockFile((HANDLE)*param_1,0x40000001,0,1,0);
  if (BVar1 != 0) {
    UnlockFile((HANDLE)*param_1,0x40000001,0,1,0);
  }
  return BVar1 == 0;
}


// ==== FUN_007d19d0 @ 0x007d19d0 ====

undefined4 FUN_007d19d0(undefined4 *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 local_4;
  
  bVar1 = *(byte *)(param_1 + 1);
  local_4 = 0;
  if (3 < bVar1) {
    UnlockFile((HANDLE)*param_1,0x40000002,0,0x1fe,0);
    if (param_2 == 1) {
      iVar2 = FUN_007d1730();
      if (iVar2 == 0) {
        local_4 = 10;
      }
    }
  }
  if (1 < bVar1) {
    UnlockFile((HANDLE)*param_1,0x40000001,0,1,0);
  }
  if ((param_2 == 0) && (bVar1 != 0)) {
    FUN_007d17c0();
  }
  if (2 < bVar1) {
    UnlockFile((HANDLE)*param_1,0x40000000,0,1,0);
  }
  *(char *)(param_1 + 1) = (char)param_2;
  return local_4;
}


// ==== FUN_007d1a70 @ 0x007d1a70 ====

LPSTR FUN_007d1a70(LPCSTR param_1)

{
  DWORD DVar1;
  LPSTR lpBuffer;
  LPSTR local_4;
  
  DVar1 = GetFullPathNameA(param_1,0,(LPSTR)0x0,&local_4);
  lpBuffer = (LPSTR)FUN_007d0550(DVar1 + 1);
  if (lpBuffer == (LPSTR)0x0) {
    return (LPSTR)0x0;
  }
  GetFullPathNameA(param_1,DVar1 + 1,lpBuffer,&local_4);
  return lpBuffer;
}


// ==== FUN_007d1ac0 @ 0x007d1ac0 ====

undefined4 FUN_007d1ac0(LPSYSTEMTIME param_1)

{
  int iVar1;
  LPSYSTEMTIME p_Var2;
  
  p_Var2 = param_1;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    p_Var2->wYear = 0;
    p_Var2->wMonth = 0;
    p_Var2 = (LPSYSTEMTIME)&p_Var2->wDayOfWeek;
  }
  GetSystemTime(param_1);
  return 0;
}


// ==== FUN_007d1ae0 @ 0x007d1ae0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007d1ae0(void)

{
  _DAT_00b5c4d4 = 1;
  return;
}


// ==== FUN_007d1af0 @ 0x007d1af0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007d1af0(void)

{
  _DAT_00b5c4d4 = 0;
  return;
}


// ==== FUN_007d1b00 @ 0x007d1b00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007d1b00(double *param_1)

{
  double dVar1;
  double dVar2;
  _FILETIME local_8;
  
  GetSystemTimeAsFileTime(&local_8);
  dVar1 = (double)(int)local_8.dwHighDateTime;
  if ((int)local_8.dwHighDateTime < 0) {
    dVar1 = dVar1 + _DAT_009c2f50;
  }
  dVar2 = (double)(int)local_8.dwLowDateTime;
  if ((int)local_8.dwLowDateTime < 0) {
    dVar2 = dVar2 + _DAT_009c2f50;
  }
  *param_1 = (dVar2 + dVar1 * _DAT_009c2f50) * _DAT_00a00110 + _DAT_00a00108;
  return 0;
}


// ==== FUN_007d1b60 @ 0x007d1b60 ====

void FUN_007d1b60(undefined1 *param_1,undefined1 param_2,undefined1 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// ==== FUN_007d1b80 @ 0x007d1b80 ====

void FUN_007d1b80(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  *(undefined4 *)(param_1 + 8) = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_007d05b0(*(int *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    if ((*(char *)(param_1 + 1) != '\0') && (puVar1[3] != 0)) {
      FUN_007d05b0(puVar1[3]);
    }
    FUN_007d05b0(puVar1);
    puVar1 = puVar2;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


// ==== FUN_007d1be0 @ 0x007d1be0 ====

uint FUN_007d1be0(byte *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  uVar2 = 0;
  if (param_2 < 1) {
    pbVar3 = param_1;
    do {
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + 1;
    } while (bVar1 != 0);
    param_2 = (int)pbVar3 - (int)(param_1 + 1);
    if (param_2 < 1) goto LAB_007d1c1b;
  }
  do {
    uVar2 = uVar2 ^ (uint)(byte)(&DAT_009fffc0)[*param_1] ^ uVar2 * 8;
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
LAB_007d1c1b:
  return uVar2 & 0x7fffffff;
}


// ==== FUN_007d1c30 @ 0x007d1c30 ====

undefined4 FUN_007d1c30(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_2 == param_4) {
    uVar1 = FUN_007d0930(param_1,param_3,param_2);
    return uVar1;
  }
  return 1;
}


// ==== FUN_007d1c60 @ 0x007d1c60 ====

uint FUN_007d1c60(char *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (0 < param_2) {
    do {
      uVar1 = uVar1 ^ uVar1 * 8 ^ (int)*param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return uVar1 & 0x7fffffff;
}


// ==== FUN_007d1c90 @ 0x007d1c90 ====

int FUN_007d1c90(byte *param_1,int param_2,byte *param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  if (param_2 != param_4) {
    return 1;
  }
  bVar2 = false;
  iVar1 = 0;
  bVar3 = true;
  do {
    if (param_2 == 0) break;
    param_2 = param_2 + -1;
    bVar2 = *param_1 < *param_3;
    bVar3 = *param_1 == *param_3;
    param_1 = param_1 + 1;
    param_3 = param_3 + 1;
  } while (bVar3);
  if (!bVar3) {
    iVar1 = (1 - (uint)bVar2) - (uint)(bVar2 != 0);
  }
  return iVar1;
}


// ==== FUN_007d1cc0 @ 0x007d1cc0 ====

void FUN_007d1cc0(void)

{
  int iVar1;
  int *in_EAX;
  int *in_EDX;
  int unaff_ESI;
  
  iVar1 = in_EDX[1];
  if (iVar1 == 0) {
    *in_EAX = *(int *)(unaff_ESI + 8);
    if (*(int *)(unaff_ESI + 8) != 0) {
      *(int **)(*(int *)(unaff_ESI + 8) + 4) = in_EAX;
    }
    in_EAX[1] = 0;
    *(int **)(unaff_ESI + 8) = in_EAX;
    *in_EDX = *in_EDX + 1;
    in_EDX[1] = (int)in_EAX;
    return;
  }
  *in_EAX = iVar1;
  in_EAX[1] = *(int *)(iVar1 + 4);
  if (*(undefined4 **)(iVar1 + 4) == (undefined4 *)0x0) {
    *(int **)(unaff_ESI + 8) = in_EAX;
    *(int **)(iVar1 + 4) = in_EAX;
    *in_EDX = *in_EDX + 1;
    in_EDX[1] = (int)in_EAX;
    return;
  }
  **(undefined4 **)(iVar1 + 4) = in_EAX;
  *(int **)(iVar1 + 4) = in_EAX;
  *in_EDX = *in_EDX + 1;
  in_EDX[1] = (int)in_EAX;
  return;
}


// ==== FUN_007d1d20 @ 0x007d1d20 ====

void FUN_007d1d20(char *param_1)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  uint uVar4;
  int *piVar5;
  code *local_8;
  
  iVar3 = FUN_007d0550(in_EAX * 8);
  if (iVar3 != 0) {
    if (*(int *)(param_1 + 0x10) != 0) {
      FUN_007d05b0(*(int *)(param_1 + 0x10));
    }
    *(int *)(param_1 + 0x10) = iVar3;
    *(int *)(param_1 + 0xc) = in_EAX;
    local_8 = FUN_007d1be0;
    if (*param_1 != '\x03') {
      local_8 = FUN_007d1c60;
    }
    piVar5 = *(int **)(param_1 + 8);
    param_1[8] = '\0';
    param_1[9] = '\0';
    param_1[10] = '\0';
    param_1[0xb] = '\0';
    if (piVar5 != (int *)0x0) {
      do {
        uVar4 = (*local_8)(piVar5[3],piVar5[4]);
        piVar1 = (int *)*piVar5;
        uVar4 = uVar4 & in_EAX - 1U;
        iVar2 = *(int *)(iVar3 + 4 + uVar4 * 8);
        if (iVar2 == 0) {
          *piVar5 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) != 0) {
            *(int **)(*(int *)(param_1 + 8) + 4) = piVar5;
          }
          piVar5[1] = 0;
          *(int **)(param_1 + 8) = piVar5;
        }
        else {
          *piVar5 = iVar2;
          piVar5[1] = *(int *)(iVar2 + 4);
          if (*(undefined4 **)(iVar2 + 4) == (undefined4 *)0x0) {
            *(int **)(param_1 + 8) = piVar5;
            *(int **)(iVar2 + 4) = piVar5;
          }
          else {
            **(undefined4 **)(iVar2 + 4) = piVar5;
            *(int **)(iVar2 + 4) = piVar5;
          }
        }
        *(int **)(iVar3 + 4 + uVar4 * 8) = piVar5;
        *(int *)(iVar3 + uVar4 * 8) = *(int *)(iVar3 + uVar4 * 8) + 1;
        piVar5 = piVar1;
      } while (piVar1 != (int *)0x0);
    }
  }
  return;
}


// ==== FUN_007d1e00 @ 0x007d1e00 ====

undefined4 * FUN_007d1e00(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char *in_ECX;
  int in_EDX;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(in_ECX + 0x10);
  if (iVar4 != 0) {
    puVar3 = *(undefined4 **)(iVar4 + 4 + in_EDX * 8);
    iVar4 = *(int *)(iVar4 + in_EDX * 8);
    pcVar2 = FUN_007d1c30;
    if (*in_ECX != '\x03') {
      pcVar2 = FUN_007d1c90;
    }
    if (iVar4 != 0) {
      do {
        iVar4 = iVar4 + -1;
        if (puVar3 == (undefined4 *)0x0) {
          return (undefined4 *)0x0;
        }
        iVar1 = (*pcVar2)(puVar3[3],puVar3[4],param_1,param_2);
        if (iVar1 == 0) {
          return puVar3;
        }
        puVar3 = (undefined4 *)*puVar3;
      } while (iVar4 != 0);
    }
  }
  return (undefined4 *)0x0;
}


// ==== FUN_007d1e60 @ 0x007d1e60 ====

void FUN_007d1e60(int param_1)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  int unaff_EDI;
  
  if ((int *)unaff_ESI[1] == (int *)0x0) {
    *(int *)(unaff_EDI + 8) = *unaff_ESI;
  }
  else {
    *(int *)unaff_ESI[1] = *unaff_ESI;
  }
  if (*unaff_ESI != 0) {
    *(int *)(*unaff_ESI + 4) = unaff_ESI[1];
  }
  piVar1 = (int *)(*(int *)(unaff_EDI + 0x10) + param_1 * 8);
  if (*(int **)(*(int *)(unaff_EDI + 0x10) + 4 + param_1 * 8) == unaff_ESI) {
    piVar1[1] = *unaff_ESI;
  }
  iVar2 = *piVar1;
  *piVar1 = iVar2 + -1;
  if (iVar2 + -1 < 1) {
    piVar1[1] = 0;
  }
  if ((*(char *)(unaff_EDI + 1) != '\0') && (unaff_ESI[3] != 0)) {
    FUN_007d05b0(unaff_ESI[3]);
  }
  FUN_007d05b0();
  *(int *)(unaff_EDI + 4) = *(int *)(unaff_EDI + 4) + -1;
  return;
}


// ==== FUN_007d1ed0 @ 0x007d1ed0 ====

undefined4 FUN_007d1ed0(char *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  
  if ((param_1 != (char *)0x0) && (*(int *)(param_1 + 0x10) != 0)) {
    pcVar1 = FUN_007d1be0;
    if (*param_1 != '\x03') {
      pcVar1 = FUN_007d1c60;
    }
    (*pcVar1)(param_2,param_3);
    iVar2 = FUN_007d1e00(param_2,param_3);
    if (iVar2 != 0) {
      return *(undefined4 *)(iVar2 + 8);
    }
  }
  return 0;
}


// ==== FUN_007d1f20 @ 0x007d1f20 ====

int FUN_007d1f20(char *param_1,undefined4 *param_2,uint param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  pcVar2 = FUN_007d1be0;
  if (*param_1 != '\x03') {
    pcVar2 = FUN_007d1c60;
  }
  uVar3 = (*pcVar2)(param_2,param_3);
  iVar5 = *(int *)(param_1 + 0xc);
  iVar4 = FUN_007d1e00(param_2,param_3);
  if (iVar4 != 0) {
    iVar1 = *(int *)(iVar4 + 8);
    if (param_4 == 0) {
      FUN_007d1e60(iVar5 - 1U & uVar3);
      return iVar1;
    }
    *(int *)(iVar4 + 8) = param_4;
    return iVar1;
  }
  if (param_4 == 0) {
    return 0;
  }
  iVar5 = FUN_007d0550(0x14);
  if (iVar5 == 0) {
    return param_4;
  }
  if ((param_1[1] == '\0') || (param_2 == (undefined4 *)0x0)) {
    *(undefined4 **)(iVar5 + 0xc) = param_2;
  }
  else {
    puVar6 = (undefined4 *)FUN_007d0590(param_3);
    *(undefined4 **)(iVar5 + 0xc) = puVar6;
    if (puVar6 == (undefined4 *)0x0) goto LAB_007d200b;
    for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *param_2;
      param_2 = param_2 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar3 = param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
  }
  *(uint *)(iVar5 + 0x10) = param_3;
  iVar4 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  if (iVar4 == 0) {
    FUN_007d1d20(param_1);
    iVar4 = *(int *)(param_1 + 0xc);
    if (iVar4 == 0) {
      param_1[4] = '\0';
      param_1[5] = '\0';
      param_1[6] = '\0';
      param_1[7] = '\0';
LAB_007d200b:
      FUN_007d05b0(iVar5);
      return param_4;
    }
  }
  if (iVar4 < *(int *)(param_1 + 4)) {
    FUN_007d1d20(param_1);
  }
  FUN_007d1cc0();
  *(int *)(iVar5 + 8) = param_4;
  return 0;
}


// ==== FUN_007d2060 @ 0x007d2060 ====

void FUN_007d2060(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x74) = param_2;
  *(undefined4 *)(param_1 + 100) = 0;
  return;
}


// ==== FUN_007d2080 @ 0x007d2080 ====

void FUN_007d2080(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int *local_8;
  
  iVar5 = 0;
  if (DAT_00b5c4c4 != 0) {
    return;
  }
  if (*(char *)((int)param_1 + 0x13) != '\0') {
    return;
  }
  if (param_1[3] == 0) {
    if (param_1[1] != 0) {
      return;
    }
    if (param_1[6] == 0) {
      return;
    }
    param_1[1] = 1;
    return;
  }
  piVar1 = (int *)*param_1;
  iVar2 = FUN_007e8190(param_1);
  if (iVar2 != 0) {
    FUN_007dc140(iVar2,0x25,0,0);
    if (0 < param_1[0xc]) {
      uVar3 = FUN_007dc320(iVar2);
      FUN_007dc400(iVar2,param_1[0xc] + -1,uVar3);
      uVar4 = 1;
      if (0 < *piVar1) {
        local_8 = param_1 + 0xd;
        do {
          if ((param_1[0xb] & uVar4) != 0) {
            FUN_007dc140(iVar2,0x69,iVar5,(param_1[10] & uVar4) != 0);
            FUN_007dc140(iVar2,0x65,iVar5,*local_8);
          }
          local_8 = local_8 + 1;
          uVar4 = uVar4 << 1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < *piVar1);
      }
      FUN_007dc140(iVar2,0x61,0,param_1[0xc]);
    }
    FUN_007dda80(iVar2,0x17,0,0,param_1[0x24],param_1[0x25] - param_1[0x24]);
    if (param_1[6] == 0) {
      FUN_007dc0b0(iVar2,-(uint)((*(byte *)(piVar1 + 2) & 1) != 0) & 0xb496a0);
      FUN_007dc970(iVar2,param_1[0x19],param_1[8] + 3,param_1[7] + 3,param_1[0x2c] + 1,
                   (char)param_1[0x1d]);
      param_1[1] = 0x65;
      *(undefined1 *)(param_1 + 4) = 0;
      goto LAB_007d21f6;
    }
  }
  if (param_1[1] == 0) {
    param_1[1] = 1;
  }
LAB_007d21f6:
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0x19] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  return;
}


// ==== FUN_007d2210 @ 0x007d2210 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007d2210(int param_1,undefined4 param_2,undefined1 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_54 [20];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar2 = FUN_007e47e0(param_2,&param_3);
    if (iVar2 != 0) {
      *(char *)(param_1 + 0x13) = *(char *)(param_1 + 0x13) + '\x01';
      puVar6 = (undefined4 *)(param_1 + 100);
      puVar4 = puVar6;
      puVar5 = local_54;
      for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar4 = puVar6;
      for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      FUN_007e50b0(param_1,iVar2,0);
      FUN_007d05b0(iVar2);
      cVar1 = *(char *)(param_1 + 0x13);
      puVar4 = local_54;
      for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      *(char *)(param_1 + 0x13) = cVar1 + -1;
    }
  }
  return;
}


// ==== FUN_007d22b0 @ 0x007d22b0 ====

int FUN_007d22b0(int *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 0;
  uVar4 = 0;
  if (*param_1 < 1) {
    return 0;
  }
  do {
    uVar5 = uVar4;
    if ((int)uVar4 < 2) {
      uVar5 = uVar4 ^ 1;
    }
    if ((param_3 == 0) ||
       (iVar2 = FUN_007d08e0(param_3,*(undefined4 *)(uVar5 * 0x70 + param_1[1])), iVar2 == 0)) {
      pcVar3 = param_2;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      iVar6 = FUN_007d1ed0(uVar5 * 0x70 + 0xc + param_1[1],param_2,pcVar3 + (1 - (int)(param_2 + 1))
                          );
      if (iVar6 != 0) {
        return iVar6;
      }
    }
    uVar4 = uVar4 + 1;
    if (*param_1 <= (int)uVar4) {
      return iVar6;
    }
  } while( true );
}


// ==== FUN_007d2330 @ 0x007d2330 ====

int FUN_007d2330(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_007ce9f0(param_1);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = FUN_007d22b0(*param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (param_3 != 0) {
      FUN_007d0820(param_1,s_no_such_table___s__s_00a00150,param_3,param_2);
      *(undefined1 *)((int)param_1 + 0x12) = 1;
      return 0;
    }
    iVar2 = FUN_007d22b0(*param_1,param_2,0);
    if (iVar2 != 0) {
      FUN_007d0820(param_1,s_table___s__is_not_in_database____00a0012c,param_2,0);
      *(undefined1 *)((int)param_1 + 0x12) = 1;
      return 0;
    }
    FUN_007d0820(param_1,s__t_no_such_table___s_00a00115 + 3,param_2);
    *(undefined1 *)((int)param_1 + 0x12) = 1;
  }
  return iVar1;
}


// ==== FUN_007d23d0 @ 0x007d23d0 ====

int FUN_007d23d0(int *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 0;
  uVar4 = 0;
  if (*param_1 < 1) {
    return 0;
  }
  do {
    uVar5 = uVar4;
    if ((int)uVar4 < 2) {
      uVar5 = uVar4 ^ 1;
    }
    if ((param_3 == 0) ||
       (iVar2 = FUN_007d08e0(param_3,*(undefined4 *)(uVar5 * 0x70 + param_1[1])), iVar2 == 0)) {
      pcVar3 = param_2;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      iVar6 = FUN_007d1ed0(uVar5 * 0x70 + 0x20 + param_1[1],param_2,
                           pcVar3 + (1 - (int)(param_2 + 1)));
      if (iVar6 != 0) {
        return iVar6;
      }
    }
    uVar4 = uVar4 + 1;
    if (*param_1 <= (int)uVar4) {
      return iVar6;
    }
  } while( true );
}


// ==== FUN_007d2450 @ 0x007d2450 ====

void FUN_007d2450(int param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 *unaff_ESI;
  
  pcVar2 = (char *)*unaff_ESI;
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  puVar4 = (undefined4 *)
           FUN_007d1f20((uint)*(byte *)((int)unaff_ESI + 0x16) * 0x70 + 0x20 + *(int *)(param_1 + 4)
                        ,pcVar2,pcVar3 + (1 - (int)(pcVar2 + 1)),0);
  if ((puVar4 != (undefined4 *)0x0) && (puVar4 != unaff_ESI)) {
    pcVar2 = (char *)*puVar4;
    pcVar3 = pcVar2;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_007d1f20((uint)*(byte *)((int)unaff_ESI + 0x16) * 0x70 + 0x20 + *(int *)(param_1 + 4),pcVar2
                 ,pcVar3 + (1 - (int)(pcVar2 + 1)),puVar4);
  }
  FUN_007d05b0(unaff_ESI[6]);
  FUN_007d05b0();
  return;
}


// ==== FUN_007d24e0 @ 0x007d24e0 ====

void FUN_007d24e0(int param_1,int param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  pcVar4 = param_3;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar5 = FUN_007d1f20(param_2 * 0x70 + 0x20 + *(int *)(param_1 + 4),param_3,
                       pcVar4 + (1 - (int)(param_3 + 1)),0);
  if (iVar5 != 0) {
    iVar2 = *(int *)(*(int *)(iVar5 + 0xc) + 0x10);
    if (iVar2 == iVar5) {
      *(undefined4 *)(*(int *)(iVar5 + 0xc) + 0x10) = *(undefined4 *)(iVar5 + 0x1c);
    }
    else {
      do {
        iVar3 = iVar2;
        if (iVar3 == 0) goto LAB_007d254f;
        iVar2 = *(int *)(iVar3 + 0x1c);
      } while (*(int *)(iVar3 + 0x1c) != iVar5);
      if (*(int *)(iVar3 + 0x1c) == iVar5) {
        *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar5 + 0x1c);
      }
    }
LAB_007d254f:
    FUN_007d05b0(*(undefined4 *)(iVar5 + 0x18));
    FUN_007d05b0(iVar5);
  }
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x10;
  return;
}


// ==== FUN_007d2570 @ 0x007d2570 ====

void FUN_007d2570(int param_1)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffffffef;
  return;
}


// ==== FUN_007d2580 @ 0x007d2580 ====

void FUN_007d2580(void)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar2 = *(undefined4 **)(unaff_EDI + 8);
  if (puVar2 != (undefined4 *)0x0) {
    iVar1 = 0;
    if (0 < *(int *)(unaff_EDI + 4)) {
      do {
        FUN_007d05b0(*puVar2);
        FUN_007eabc0(puVar2[1]);
        FUN_007d05b0(puVar2[2]);
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 5;
      } while (iVar1 < *(int *)(unaff_EDI + 4));
    }
    FUN_007d05b0(*(undefined4 *)(unaff_EDI + 8));
  }
  *(undefined4 *)(unaff_EDI + 8) = 0;
  *(undefined4 *)(unaff_EDI + 4) = 0;
  return;
}


// ==== FUN_007d25e0 @ 0x007d25e0 ====

void FUN_007d25e0(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 != (undefined4 *)0x0) &&
     (iVar2 = param_2[9], param_2[9] = iVar2 + -1, iVar2 + -1 < 1)) {
    iVar2 = param_2[4];
    if (iVar2 != 0) {
      do {
        iVar2 = *(int *)(iVar2 + 0x1c);
        FUN_007d2450(param_1);
      } while (iVar2 != 0);
    }
    iVar2 = param_2[0xb];
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 4);
      FUN_007d05b0(iVar2);
      iVar2 = iVar1;
    }
    FUN_007d2580();
    FUN_007d05b0(*param_2);
    FUN_007d05b0(param_2[0xc]);
    FUN_007e6af0(param_2[6]);
    FUN_007d05b0(param_2);
  }
  return;
}


// ==== FUN_007d2660 @ 0x007d2660 ====

void FUN_007d2660(int param_1,int param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = param_2 * 0x70 + *(int *)(param_1 + 4);
  pcVar3 = param_3;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  iVar4 = FUN_007d1f20(iVar8 + 0xc,param_3,pcVar3 + (1 - (int)(param_3 + 1)),0);
  if (iVar4 != 0) {
    iVar7 = *(int *)(iVar4 + 0x2c);
    if (iVar7 != 0) {
      iVar8 = iVar8 + 0x48;
      do {
        pcVar3 = *(char **)(iVar7 + 8);
        pcVar5 = pcVar3;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar6 = FUN_007d1ed0(iVar8,pcVar3,pcVar5 + (1 - (int)(pcVar3 + 1)));
        if (iVar6 == iVar7) {
          FUN_007d1f20(iVar8,*(undefined4 *)(iVar7 + 8),pcVar5 + (1 - (int)(pcVar3 + 1)),
                       *(undefined4 *)(iVar7 + 0xc));
        }
        else {
          do {
            iVar2 = iVar6;
            if (iVar2 == 0) goto LAB_007d2705;
            iVar6 = *(int *)(iVar2 + 0xc);
          } while (*(int *)(iVar2 + 0xc) != iVar7);
          *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar7 + 0xc);
        }
LAB_007d2705:
        iVar7 = *(int *)(iVar7 + 4);
      } while (iVar7 != 0);
    }
    FUN_007d25e0(param_1,iVar4);
  }
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x10;
  return;
}


// ==== FUN_007d2730 @ 0x007d2730 ====

undefined4 FUN_007d2730(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  uVar1 = FUN_007d06a0(*param_1,(uint)param_1[1] >> 1);
  FUN_007d0860(uVar1);
  return uVar1;
}


// ==== FUN_007d2760 @ 0x007d2760 ====

void FUN_007d2760(undefined4 param_1,undefined4 param_2)

{
  FUN_007dc140(param_1,0x32,param_2,0);
  FUN_007dc140(param_1,9,0,1);
  FUN_007dc140(param_1,0x67,0,5);
  return;
}


// ==== FUN_007d27a0 @ 0x007d27a0 ====

int FUN_007d27a0(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 *in_EAX;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int *in_ECX;
  undefined4 *puVar7;
  int iVar8;
  
  if (in_EAX == (undefined4 *)0x0) {
    return -1;
  }
  pcVar3 = (char *)FUN_007d06a0(*in_EAX,(uint)in_EAX[1] >> 1);
  FUN_007d0860(pcVar3);
  if (pcVar3 == (char *)0x0) {
    return -1;
  }
  pcVar4 = pcVar3;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar8 = *in_ECX + -1;
  puVar7 = (undefined4 *)(iVar8 * 0x70 + in_ECX[1]);
  for (; -1 < iVar8; iVar8 = iVar8 + -1) {
    pcVar2 = (char *)*puVar7;
    pcVar5 = pcVar2;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (((int)pcVar4 - (int)(pcVar3 + 1) == (int)pcVar5 - (int)(pcVar2 + 1)) &&
       (iVar6 = FUN_007d08e0(pcVar2,pcVar3), iVar6 == 0)) break;
    puVar7 = puVar7 + -0x1c;
  }
  FUN_007d05b0(pcVar3);
  return iVar8;
}


// ==== FUN_007d2850 @ 0x007d2850 ====

int FUN_007d2850(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  
  if ((param_3 == 0) || ((*(uint *)(param_3 + 4) & 0xfffffffe) == 0)) {
    iVar1 = *(int *)(*param_1 + 0x3c);
    *param_4 = param_2;
  }
  else {
    *param_4 = param_3;
    iVar1 = FUN_007d27a0();
    if (iVar1 < 0) {
      FUN_007d0820(param_1,s_unknown_database__T_00a00168,param_2);
      param_1[6] = param_1[6] + 1;
      return -1;
    }
  }
  return iVar1;
}


// ==== FUN_007d28b0 @ 0x007d28b0 ====

undefined4 FUN_007d28b0(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (((*(char *)(*param_1 + 0x44) == '\0') && (*(char *)((int)param_1 + 0x13) == '\0')) &&
     ((*(uint *)(*param_1 + 8) & 0x800) == 0)) {
    iVar1 = FUN_007d0930(param_2,s_sqlite__00a001a8,7);
    if (iVar1 == 0) {
      FUN_007d0820(param_1,s_object_name_reserved_for_interna_00a0017c,param_2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007d2910 @ 0x007d2910 ====

void FUN_007d2910(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = param_1[0x26];
  if ((iVar2 != 0) && (param_2 != (undefined4 *)0x0)) {
    pbVar4 = (byte *)FUN_007d06a0(*param_2,(uint)param_2[1] >> 1);
    FUN_007d0860(pbVar4);
    if (pbVar4 != (byte *)0x0) {
      iVar7 = 0;
      if (0 < *(int *)(iVar2 + 4)) {
        iVar6 = 0;
        do {
          pbVar3 = *(byte **)(iVar6 + *(int *)(iVar2 + 8));
          if (((&DAT_009fffc0)[*pbVar4] == (&DAT_009fffc0)[*pbVar3]) &&
             (iVar5 = FUN_007d08e0(pbVar4 + 1,pbVar3 + 1), iVar5 == 0)) {
            FUN_007d0820(param_1,s_duplicate_column_name___s_00a001b0,pbVar4);
            FUN_007d05b0(pbVar4);
            return;
          }
          iVar7 = iVar7 + 1;
          iVar6 = iVar6 + 0x14;
        } while (iVar7 < *(int *)(iVar2 + 4));
      }
      if ((*(uint *)(iVar2 + 4) & 7) == 0) {
        iVar7 = FUN_007d05d0(*(undefined4 *)(iVar2 + 8),(*(uint *)(iVar2 + 4) * 5 + 0x28) * 4);
        if (iVar7 == 0) {
          FUN_007d05b0(pbVar4);
          return;
        }
        *(int *)(iVar2 + 8) = iVar7;
      }
      puVar1 = (undefined4 *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 4) * 0x14);
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      *puVar1 = pbVar4;
      *(undefined1 *)((int)puVar1 + 0x12) = 0x6f;
      puVar1[3] = *(undefined4 *)(*param_1 + 0x18);
      *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
    }
  }
  return;
}


// ==== FUN_007d2a30 @ 0x007d2a30 ====

void FUN_007d2a30(int param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x98);
  if ((iVar1 != 0) && (iVar2 = *(int *)(iVar1 + 4) + -1, -1 < iVar2)) {
    *(undefined1 *)(*(int *)(iVar1 + 8) + 0x10 + iVar2 * 0x14) = param_2;
  }
  return;
}


// ==== FUN_007d2a60 @ 0x007d2a60 ====

char FUN_007d2a60(int param_1)

{
  char cVar1;
  uint uVar2;
  byte *in_EDX;
  byte *pbVar3;
  
  pbVar3 = in_EDX + param_1;
  uVar2 = 0;
  cVar1 = 'n';
  if (in_EDX == pbVar3) {
    return 'n';
  }
  do {
    uVar2 = uVar2 * 0x100 + (uint)(byte)(&DAT_009fffc0)[*in_EDX];
    in_EDX = in_EDX + 1;
    if (uVar2 == 0x63686172) {
      cVar1 = 't';
    }
    else if (uVar2 == 0x636c6f62) {
      cVar1 = 't';
    }
    else if (uVar2 == 0x74657874) {
      cVar1 = 't';
    }
    else if ((uVar2 == 0x626c6f62) && (cVar1 == 'n')) {
      cVar1 = 'o';
    }
    else if ((uVar2 & 0xffffff) == 0x696e74) {
      return 'i';
    }
  } while (in_EDX != pbVar3);
  return cVar1;
}


// ==== FUN_007d2ad0 @ 0x007d2ad0 ====

void FUN_007d2ad0(int param_1,int *param_2,int *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = *(int *)(param_1 + 0x98);
  if ((iVar2 != 0) && (iVar5 = *(int *)(iVar2 + 4) + -1, -1 < iVar5)) {
    iVar3 = *param_2;
    iVar2 = *(int *)(iVar2 + 8) + iVar5 * 0x14;
    iVar8 = (((uint)param_3[1] >> 1) - iVar3) + *param_3;
    iVar5 = FUN_007d0590(iVar8 + 1);
    *(int *)(iVar2 + 8) = iVar5;
    iVar7 = 0;
    if (iVar5 != 0) {
      param_1 = 0;
      if (0 < iVar8) {
        do {
          bVar1 = *(byte *)(iVar3 + param_1);
          iVar6 = _isspace((uint)bVar1);
          if (iVar6 == 0) {
            *(byte *)(iVar5 + iVar7) = bVar1;
            iVar7 = iVar7 + 1;
          }
          param_1 = param_1 + 1;
        } while (param_1 < iVar8);
      }
      *(undefined1 *)(iVar5 + iVar7) = 0;
      uVar4 = FUN_007d2a60(iVar8);
      *(undefined1 *)(iVar2 + 0x12) = uVar4;
    }
  }
  return;
}


// ==== FUN_007d2b90 @ 0x007d2b90 ====

void FUN_007d2b90(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(param_1 + 0x98);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(*(int *)(iVar2 + 8) + -0x14 + *(int *)(iVar2 + 4) * 0x14);
    iVar2 = FUN_007eaee0(param_2);
    if (iVar2 == 0) {
      FUN_007d0820(param_1,s_default_value_of_column___s__is_n_00a001cc,*puVar1);
      FUN_007eabc0(param_2);
      return;
    }
    FUN_007eabc0(puVar1[1]);
    uVar3 = FUN_007eb2d0(param_2);
    puVar1[1] = uVar3;
    FUN_007eabc0(param_2);
  }
  return;
}


// ==== FUN_007d2c00 @ 0x007d2c00 ====

undefined4 FUN_007d2c00(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_2 != 0) && (iVar2 = 0, 0 < *(int *)(param_2 + 4))) {
    puVar3 = (undefined4 *)(param_2 + 0x2c);
    do {
      iVar1 = FUN_007de5b0(param_1,*puVar3);
      if (iVar1 != 0) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < *(int *)(param_2 + 4));
  }
  return 0;
}


// ==== FUN_007d2c50 @ 0x007d2c50 ====

int FUN_007d2c50(int *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  iVar2 = *param_1;
  cVar1 = *(char *)(iVar2 + 0x44);
  iVar3 = FUN_007de2b0(iVar2,*(undefined1 *)(iVar2 + 0x10),param_2,param_3,cVar1);
  if ((cVar1 == '\0') && ((iVar3 == 0 || (*(int *)(iVar3 + 0xc) == 0)))) {
    iVar3 = FUN_007de4d0(iVar2,iVar3,param_2,param_3);
    if (iVar3 == 0) {
      if (param_3 < 0) {
        pcVar4 = param_2;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        param_3 = (int)pcVar4 - (int)(param_2 + 1);
      }
      FUN_007d0820(param_1,s_no_such_collation_sequence_____s_00a001fc,param_3,param_2);
      iVar3 = 0;
    }
  }
  return iVar3;
}


// ==== FUN_007d2ce0 @ 0x007d2ce0 ====

void FUN_007d2ce0(int param_1,undefined4 param_2,int param_3)

{
  FUN_007dc140(param_2,0x32,*(int *)(param_3 * 0x70 + 8 + *(int *)(param_1 + 4)) + 1,0);
  FUN_007dc140(param_2,3,param_3,0);
  return;
}


// ==== FUN_007d2d20 @ 0x007d2d20 ====

void FUN_007d2d20(int param_1,int *param_2)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  byte *in_EAX;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *param_2;
  bVar2 = *in_EAX;
  for (iVar6 = 0;
      (bVar2 != 0 &&
      ((iVar4 = _isalnum((uint)in_EAX[iVar6]), iVar4 != 0 || (in_EAX[iVar6] == 0x5f))));
      iVar6 = iVar6 + 1) {
    bVar2 = in_EAX[iVar6 + 1];
  }
  if (((in_EAX[iVar6] == 0) && (iVar6 = _isdigit((uint)*in_EAX), iVar6 == 0)) &&
     (iVar6 = FUN_007e4960(), iVar6 == 0x1b)) {
    bVar3 = false;
  }
  else {
    *(undefined1 *)(iVar5 + param_1) = 0x22;
    bVar3 = true;
    iVar5 = iVar5 + 1;
  }
  bVar2 = *in_EAX;
  while (bVar2 != 0) {
    *(byte *)(iVar5 + param_1) = *in_EAX;
    iVar6 = iVar5 + 1;
    if (*in_EAX == 0x22) {
      *(undefined1 *)(iVar6 + param_1) = 0x22;
      iVar6 = iVar5 + 2;
    }
    pbVar1 = in_EAX + 1;
    in_EAX = in_EAX + 1;
    iVar5 = iVar6;
    bVar2 = *pbVar1;
  }
  if (bVar3) {
    *(undefined1 *)(iVar5 + param_1) = 0x22;
    *(undefined1 *)(iVar5 + 1 + param_1) = 0;
    *param_2 = iVar5 + 1;
    return;
  }
  *(undefined1 *)(iVar5 + param_1) = 0;
  *param_2 = iVar5;
  return;
}


// ==== FUN_007d2de0 @ 0x007d2de0 ====

char * FUN_007d2de0(undefined4 *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char *local_14;
  char *local_10;
  char *local_c;
  int local_8;
  char *local_4;
  
  iVar6 = param_1[1];
  puVar7 = (undefined4 *)param_1[2];
  pcVar8 = (char *)0x0;
  if (0 < iVar6) {
    do {
      pcVar2 = (char *)*puVar7;
      iVar4 = 0;
      cVar1 = *pcVar2;
      while (cVar1 != '\0') {
        if (cVar1 == '\"') {
          iVar4 = iVar4 + 1;
        }
        pcVar5 = pcVar2 + 1;
        iVar4 = iVar4 + 1;
        pcVar2 = pcVar2 + 1;
        cVar1 = *pcVar5;
      }
      pcVar2 = (char *)puVar7[2];
      pcVar8 = pcVar8 + iVar4 + 2;
      if (pcVar2 != (char *)0x0) {
        pcVar5 = pcVar2 + 1;
        do {
          cVar1 = *pcVar2;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar8 = pcVar2 + (int)(pcVar8 + (1 - (int)pcVar5));
      }
      puVar7 = puVar7 + 5;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  pcVar2 = (char *)*param_1;
  iVar6 = 0;
  cVar1 = *pcVar2;
  while (cVar1 != '\0') {
    if (cVar1 == '\"') {
      iVar6 = iVar6 + 1;
    }
    pcVar5 = pcVar2 + 1;
    iVar6 = iVar6 + 1;
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar5;
  }
  if ((int)(pcVar8 + iVar6 + 2) < 0x32) {
    pcVar2 = &DAT_0099cf70;
    local_c = &DAT_00a00258;
    local_4 = &DAT_00a00254;
  }
  else {
    local_10 = &DAT_00a00250;
    pcVar2 = &DAT_00a00250;
    local_c = &DAT_00a00248;
    local_4 = &DAT_00a00244;
  }
  pcVar8 = (char *)FUN_007d0590(pcVar8 + iVar6 + 2 + param_1[1] * 6 + 0x23);
  if (pcVar8 == (char *)0x0) {
    return (char *)0x0;
  }
  pcVar5 = s_CREATE_TEMP_TABLE_00a00230;
  if (*(char *)((int)param_1 + 0x1d) != '\x01') {
    pcVar5 = s_CREATE_TABLE_00a00220;
  }
  pcVar3 = pcVar8;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = pcVar8;
  do {
    cVar1 = *local_14;
    local_14 = local_14 + 1;
  } while (cVar1 != '\0');
  local_14 = local_14 + -(int)(pcVar8 + 1);
  FUN_007d2d20(pcVar8,&local_14);
  pcVar8[(int)local_14] = '(';
  iVar6 = param_1[2];
  local_14 = local_14 + 1;
  local_8 = 0;
  if (0 < (int)param_1[1]) {
    while( true ) {
      pcVar5 = pcVar8 + (int)local_14;
      iVar4 = (int)pcVar5 - (int)pcVar2;
      do {
        cVar1 = *pcVar2;
        pcVar2[iVar4] = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = pcVar5 + 1;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      local_14 = pcVar5 + ((int)local_14 - (int)pcVar2);
      local_10 = local_c;
      FUN_007d2d20(pcVar8,&local_14);
      pcVar2 = *(char **)(iVar6 + 8);
      if (pcVar2 != (char *)0x0) {
        pcVar8[(int)local_14] = ' ';
        pcVar5 = pcVar2;
        do {
          cVar1 = *pcVar5;
          (pcVar8 + (int)(local_14 + (1 - (int)pcVar2)))[(int)pcVar5] = cVar1;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        pcVar5 = pcVar2 + 1;
        do {
          cVar1 = *pcVar2;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        local_14 = pcVar2 + (int)(local_14 + (1 - (int)pcVar5));
      }
      local_8 = local_8 + 1;
      iVar6 = iVar6 + 0x14;
      if ((int)param_1[1] <= local_8) break;
      pcVar2 = local_10;
    }
  }
  iVar6 = (int)local_14 - (int)local_4;
  do {
    cVar1 = *local_4;
    (pcVar8 + iVar6)[(int)local_4] = cVar1;
    local_4 = local_4 + 1;
  } while (cVar1 != '\0');
  return pcVar8;
}


// ==== FUN_007d2fe0 @ 0x007d2fe0 ====

void FUN_007d2fe0(int *param_1,int *param_2,int *param_3,int param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  char *pcVar8;
  char *local_4;
  
  iVar2 = *param_1;
  if ((param_3 == (int *)0x0) && (param_4 == 0)) {
    return;
  }
  if (param_1[6] != 0) {
    return;
  }
  if (DAT_00b5c4c4 != 0) {
    return;
  }
  puVar3 = (undefined4 *)param_1[0x26];
  if (puVar3 == (undefined4 *)0x0) {
    return;
  }
  if (*(char *)(iVar2 + 0x44) != '\0') {
    puVar3[5] = *(undefined4 *)(iVar2 + 0x40);
  }
  if (*(char *)(iVar2 + 0x44) == '\0') {
    iVar4 = FUN_007e8190(param_1);
    if (iVar4 == 0) {
      return;
    }
    FUN_007dc140(iVar4,0x1e,0,0);
    if (puVar3[6] == 0) {
      local_4 = s_table_009fda44;
      pcVar8 = s_TABLE_00a00310;
    }
    else {
      local_4 = &DAT_00a00308;
      pcVar8 = &DAT_00a00300;
    }
    if (param_4 == 0) {
      uVar6 = FUN_007e4830(s_CREATE__s____s_00a002f0,pcVar8,(*param_3 - param_1[0x20]) + 1,
                           param_1[0x20]);
    }
    else {
      FUN_007dc140(iVar4,0x60,0,0);
      FUN_007dc140(iVar4,0x32,*(undefined1 *)((int)puVar3 + 0x1d),0);
      FUN_007dc140(iVar4,9,1,0);
      param_1[7] = 2;
      FUN_007e9760(param_1,param_4,7,1,0,0,0,0);
      FUN_007dc140(iVar4,0x1e,1,0);
      if (param_1[6] == 0) {
        iVar5 = FUN_007e7770(param_1,0,param_4);
        if (iVar5 == 0) {
          return;
        }
        puVar3[1] = *(undefined4 *)(iVar5 + 4);
        puVar3[2] = *(undefined4 *)(iVar5 + 8);
        *(undefined4 *)(iVar5 + 4) = 0;
        *(undefined4 *)(iVar5 + 8) = 0;
        FUN_007d25e0(0,iVar5);
      }
      uVar6 = FUN_007d2de0(puVar3);
    }
    pcVar8 = s_sqlite_temp_master_009fff68;
    if (*(byte *)((int)puVar3 + 0x1d) != 1) {
      pcVar8 = s_sqlite_master_009fff58;
    }
    FUN_007d2210(param_1,s_UPDATE__Q__s_SET_type___s___name_00a00298,
                 *(undefined4 *)((uint)*(byte *)((int)puVar3 + 0x1d) * 0x70 + *(int *)(iVar2 + 4)),
                 pcVar8,local_4,*puVar3,*puVar3,uVar6);
    FUN_007d05b0(uVar6);
    FUN_007d2ce0(iVar2,iVar4,*(undefined1 *)((int)puVar3 + 0x1d));
    if ((*(char *)((int)puVar3 + 0x21) != '\0') &&
       (iVar5 = (uint)*(byte *)((int)puVar3 + 0x1d) * 0x70,
       *(int *)(iVar5 + 100 + *(int *)(iVar2 + 4)) == 0)) {
      FUN_007d2210(param_1,s_CREATE_TABLE__Q_sqlite_sequence__00a0026c,
                   *(undefined4 *)(iVar5 + *(int *)(iVar2 + 4)));
    }
    uVar6 = FUN_007e4830(s_tbl_name___q__00a0025c,*puVar3,0xffffffff);
    FUN_007dda80(iVar4,0x1c,*(undefined1 *)((int)puVar3 + 0x1d),0,uVar6);
    if (*(char *)(iVar2 + 0x44) == '\0') {
      return;
    }
  }
  if (param_1[6] == 0) {
    pcVar8 = (char *)*puVar3;
    iVar4 = (uint)*(byte *)((int)puVar3 + 0x1d) * 0x70 + *(int *)(iVar2 + 4);
    pcVar7 = pcVar8;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    iVar5 = FUN_007d1f20(iVar4 + 0xc,pcVar8,pcVar7 + (1 - (int)(pcVar8 + 1)),puVar3);
    if (iVar5 == 0) {
      iVar5 = puVar3[0xb];
      if (iVar5 != 0) {
        iVar4 = iVar4 + 0x48;
        do {
          pcVar8 = *(char **)(iVar5 + 8);
          pcVar7 = pcVar8;
          do {
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          uVar6 = FUN_007d1ed0(iVar4,pcVar8,pcVar7 + (1 - (int)(pcVar8 + 1)));
          *(undefined4 *)(iVar5 + 0xc) = uVar6;
          FUN_007d1f20(iVar4,*(undefined4 *)(iVar5 + 8),pcVar7 + (1 - (int)(pcVar8 + 1)),iVar5);
          iVar5 = *(int *)(iVar5 + 4);
        } while (iVar5 != 0);
      }
      param_1[0x26] = 0;
      *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
      *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | 0x10;
      if (puVar3[6] == 0) {
        if (*param_2 == 0) {
          param_2 = param_3;
        }
        puVar3[0xd] = (*param_2 - param_1[0x20]) + 0xd;
      }
    }
  }
  return;
}


// ==== FUN_007d32e0 @ 0x007d32e0 ====

int FUN_007d32e0(int param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  
  iVar4 = in_EAX * 0x70;
  iVar3 = *(int *)(param_1 + 4) + iVar4;
  if ((*(byte *)(*(int *)(param_1 + 4) + 0x5c + iVar4) & 2) != 0) {
    for (puVar2 = *(undefined4 **)(iVar3 + 0x14); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      if (*(int *)(puVar2[2] + 0x18) != 0) {
        FUN_007d2580();
      }
    }
    iVar3 = *(int *)(param_1 + 4);
    pbVar1 = (byte *)(iVar3 + 0x5c + iVar4);
    *pbVar1 = *pbVar1 & 0xfd;
    iVar3 = iVar3 + 0x5c + iVar4;
  }
  return iVar3;
}


// ==== FUN_007d3330 @ 0x007d3330 ====

void FUN_007d3330(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  
  for (puVar1 = *(undefined4 **)(param_1 + 0x14); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    if (*(int *)(puVar1[2] + 0x14) == param_2) {
      *(undefined4 *)(puVar1[2] + 0x14) = param_3;
      return;
    }
  }
  piVar2 = *(int **)(param_1 + 0x28);
  if (piVar2 != (int *)0x0) {
    while (*(int *)(piVar2[2] + 0x10) != param_2) {
      piVar2 = (int *)*piVar2;
      if (piVar2 == (int *)0x0) {
        return;
      }
    }
    *(undefined4 *)(piVar2[2] + 0x10) = param_3;
  }
  return;
}


// ==== FUN_007d3380 @ 0x007d3380 ====

void FUN_007d3380(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_007e8190();
  FUN_007dc140(uVar1,0x72);
  FUN_007d2210();
  return;
}


// ==== FUN_007d33d0 @ 0x007d33d0 ====

void FUN_007d33d0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *(int *)(param_1 + 0x14);
  iVar6 = 0;
  while( true ) {
    if ((iVar6 == 0) || (iVar7 = 0, iVar2 < iVar6)) {
      iVar7 = iVar2;
    }
    for (iVar3 = *(int *)(param_1 + 0x10); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x1c)) {
      iVar4 = *(int *)(iVar3 + 0x10);
      if (((iVar6 == 0) || (iVar4 < iVar6)) && (iVar7 < iVar4)) {
        iVar7 = iVar4;
      }
    }
    if (iVar7 == 0) break;
    uVar1 = *(undefined1 *)(param_1 + 0x1d);
    uVar5 = FUN_007e8190();
    FUN_007dc140(uVar5,0x72,iVar7,uVar1);
    FUN_007d2210();
    iVar6 = iVar7;
  }
  return;
}


// ==== FUN_007d3460 @ 0x007d3460 ====

void FUN_007d3460(int param_1,int *param_2,undefined4 *param_3,int *param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  char *pcVar12;
  int *piVar13;
  undefined4 *puVar14;
  int *piVar15;
  undefined4 *puVar16;
  int iVar17;
  int local_10;
  int local_8;
  int local_4;
  
  iVar2 = *(int *)(param_1 + 0x98);
  piVar11 = (int *)0x0;
  if ((iVar2 == 0) || (*(int *)(param_1 + 0x18) != 0)) goto LAB_007d3665;
  if (param_2 == (int *)0x0) {
    iVar3 = *(int *)(iVar2 + 4) + -1;
    if (iVar3 < 0) goto LAB_007d3665;
    if ((param_4 != (int *)0x0) && (*param_4 != 1)) {
      FUN_007d0820(param_1,s_foreign_key_on__s_should_referen_00a003e0,
                   *(undefined4 *)(*(int *)(iVar2 + 8) + iVar3 * 0x14),param_3);
      goto LAB_007d3665;
    }
    local_8 = 1;
  }
  else {
    if ((param_4 != (int *)0x0) && (*param_4 != *param_2)) {
      FUN_007d0820(param_1,s_number_of_columns_in_foreign_key_00a00380);
      goto LAB_007d3665;
    }
    local_8 = *param_2;
  }
  pcVar12 = (char *)(((uint)param_3[1] >> 1) + 0x1d + local_8 * 8);
  if ((param_4 != (int *)0x0) && (iVar3 = *param_4, 0 < iVar3)) {
    puVar8 = (undefined4 *)(param_4[2] + 4);
    do {
      pcVar4 = (char *)*puVar8;
      pcVar6 = pcVar4 + 1;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      puVar8 = puVar8 + 3;
      iVar3 = iVar3 + -1;
      pcVar12 = pcVar4 + (int)(pcVar12 + (1 - (int)pcVar6));
    } while (iVar3 != 0);
  }
  piVar11 = (int *)FUN_007d0550(pcVar12);
  if (piVar11 != (int *)0x0) {
    *piVar11 = iVar2;
    piVar11[1] = *(int *)(iVar2 + 0x2c);
    piVar11[5] = (int)(piVar11 + 7);
    piVar5 = piVar11 + 7 + local_8 * 2;
    piVar11[2] = (int)piVar5;
    uVar10 = param_3[1];
    piVar13 = (int *)*param_3;
    piVar15 = piVar5;
    for (uVar9 = uVar10 >> 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *piVar15 = *piVar13;
      piVar13 = piVar13 + 1;
      piVar15 = piVar15 + 1;
    }
    for (uVar10 = uVar10 >> 1 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(char *)piVar15 = (char)*piVar13;
      piVar13 = (int *)((int)piVar13 + 1);
      piVar15 = (int *)((int)piVar15 + 1);
    }
    *(undefined1 *)(((uint)param_3[1] >> 1) + (int)piVar5) = 0;
    puVar8 = (undefined4 *)((int)piVar5 + ((uint)param_3[1] >> 1) + 1);
    piVar11[3] = 0;
    piVar11[4] = local_8;
    if (param_2 == (int *)0x0) {
      *(int *)piVar11[5] = *(int *)(iVar2 + 4) + -1;
    }
    else {
      local_10 = 0;
      if (0 < local_8) {
        local_4 = 0;
        do {
          iVar3 = 0;
          if (0 < *(int *)(iVar2 + 4)) {
            iVar17 = 0;
            do {
              iVar7 = FUN_007d08e0(*(undefined4 *)(*(int *)(iVar2 + 8) + iVar17),
                                   *(undefined4 *)(local_4 + 4 + param_2[2]));
              if (iVar7 == 0) {
                *(int *)(piVar11[5] + local_10 * 8) = iVar3;
                break;
              }
              iVar3 = iVar3 + 1;
              iVar17 = iVar17 + 0x14;
            } while (iVar3 < *(int *)(iVar2 + 4));
          }
          if (*(int *)(iVar2 + 4) <= iVar3) {
            FUN_007d0820(param_1,s_unknown_column___s__in_foreign_k_00a00350,
                         *(undefined4 *)(param_2[2] + 4 + local_10 * 0xc));
            goto LAB_007d3665;
          }
          local_10 = local_10 + 1;
          local_4 = local_4 + 0xc;
        } while (local_10 < local_8);
      }
    }
    if ((param_4 != (int *)0x0) && (local_10 = 0, 0 < local_8)) {
      param_1 = 0;
      do {
        pcVar6 = *(char **)(param_1 + 4 + param_4[2]);
        pcVar12 = pcVar6 + 1;
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        uVar10 = (int)pcVar6 - (int)pcVar12;
        *(undefined4 **)(piVar11[5] + 4 + local_10 * 8) = puVar8;
        puVar14 = *(undefined4 **)(param_1 + 4 + param_4[2]);
        puVar16 = puVar8;
        for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *puVar16 = *puVar14;
          puVar14 = puVar14 + 1;
          puVar16 = puVar16 + 1;
        }
        for (uVar9 = uVar10 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
          puVar14 = (undefined4 *)((int)puVar14 + 1);
          puVar16 = (undefined4 *)((int)puVar16 + 1);
        }
        *(undefined1 *)(uVar10 + (int)puVar8) = 0;
        puVar8 = (undefined4 *)(uVar10 + 1 + (int)puVar8);
        local_10 = local_10 + 1;
        param_1 = param_1 + 0xc;
      } while (local_10 < local_8);
    }
    *(char *)((int)piVar11 + 0x1a) = (char)param_5;
    *(undefined1 *)(piVar11 + 6) = 0;
    *(char *)((int)piVar11 + 0x19) = (char)((uint)param_5 >> 8);
    *(char *)((int)piVar11 + 0x1b) = (char)((uint)param_5 >> 0x10);
    *(int **)(iVar2 + 0x2c) = piVar11;
    piVar11 = (int *)0x0;
  }
LAB_007d3665:
  FUN_007d05b0(piVar11);
  FUN_007ea740(param_2);
  FUN_007ea740(param_4);
  return;
}


// ==== FUN_007d3750 @ 0x007d3750 ====

void FUN_007d3750(int param_1,undefined1 param_2)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x98) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x98) + 0x2c), iVar1 != 0)) {
    *(undefined1 *)(iVar1 + 0x18) = param_2;
  }
  return;
}


// ==== FUN_007d3770 @ 0x007d3770 ====

void FUN_007d3770(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  bool bVar5;
  undefined4 local_4;
  
  iVar3 = *(int *)(in_EAX + 0xc);
  iVar1 = *(int *)(in_ECX + 0x1c);
  iVar2 = FUN_007ed5e0();
  if (iVar2 == 0) {
    iVar2 = FUN_007d2c00();
    if (iVar2 == 0) {
      iVar2 = FUN_007e8190();
      if (iVar2 != 0) {
        if (param_1 < 0) {
          local_4 = *(undefined4 *)(in_EAX + 0x10);
          FUN_007dc140(iVar2,0x62,local_4,*(undefined1 *)(in_EAX + 0x16));
        }
        else {
          FUN_007dc140(iVar2,1,param_1,0);
          local_4 = 0;
        }
        FUN_007dc140(iVar2,0x32,*(undefined1 *)(in_EAX + 0x16),0);
        FUN_007dda80(iVar2,9,iVar1 + 1,local_4,in_EAX + 0x20,0xfffffffa);
        FUN_007dc140(iVar2,0x32,*(undefined1 *)(iVar3 + 0x1d),0);
        FUN_007dc140(iVar2,0xe,iVar1,*(undefined4 *)(iVar3 + 0x14));
        FUN_007dc140(iVar2,0x67,iVar1,*(undefined4 *)(iVar3 + 4));
        iVar3 = FUN_007dc140(iVar2,0x79,iVar1,0);
        FUN_007ecd40(iVar2);
        bVar5 = *(char *)(in_EAX + 0x14) != '\0';
        FUN_007dc140(iVar2,0x6e,iVar1 + 1,bVar5);
        if (bVar5) {
          FUN_007dc430(iVar2,0xffffffff,s_indexed_columns_are_not_unique_00a00420,0xfffffffe);
        }
        FUN_007dc140(iVar2,0x6c,iVar1,iVar3 + 1);
        uVar4 = FUN_007dc320(iVar2);
        FUN_007dc400(iVar2,iVar3,uVar4);
        FUN_007dc140(iVar2,0x1e,iVar1,0);
        FUN_007dc140(iVar2,0x1e,iVar1 + 1,0);
      }
    }
  }
  return;
}


// ==== FUN_007d38e0 @ 0x007d38e0 ====

void FUN_007d38e0(int param_1,short *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *param_2) {
    piVar2 = (int *)(param_2 + 10);
    do {
      if (-1 < piVar2[2]) {
        return;
      }
      piVar2[2] = *(int *)(param_1 + 0x1c);
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      if (*piVar2 != 0) {
        FUN_007d38e0(param_1,*(undefined4 *)(*piVar2 + 8));
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 10;
    } while (iVar1 < *param_2);
  }
  return;
}


// ==== FUN_007d3930 @ 0x007d3930 ====

void FUN_007d3930(short *param_1,undefined4 *param_2)

{
  short sVar1;
  undefined4 uVar2;
  
  if ((param_1 != (short *)0x0) && (0 < *param_1)) {
    if (param_2 != (undefined4 *)0x0) {
      uVar2 = FUN_007d06a0(*param_2,(uint)param_2[1] >> 1);
      FUN_007d0860(uVar2);
      *(undefined4 *)(param_1 + *param_1 * 0x14 + -0xe) = uVar2;
      return;
    }
    sVar1 = *param_1;
    (param_1 + sVar1 * 0x14 + -0xe)[0] = 0;
    (param_1 + sVar1 * 0x14 + -0xe)[1] = 0;
  }
  return;
}


// ==== FUN_007d3980 @ 0x007d3980 ====

void FUN_007d3980(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = 0;
    if (0 < *param_1) {
      do {
        FUN_007d05b0(*(undefined4 *)(param_1[2] + iVar1 * 8));
        iVar1 = iVar1 + 1;
      } while (iVar1 < *param_1);
    }
    FUN_007d05b0(param_1[2]);
    FUN_007d05b0(param_1);
  }
  return;
}


// ==== FUN_007d39c0 @ 0x007d39c0 ====

int FUN_007d39c0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    return -1;
  }
  iVar2 = 0;
  if (0 < *param_1) {
    do {
      iVar1 = FUN_007d08e0(*(undefined4 *)(param_1[2] + iVar2 * 8),param_2);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *param_1);
  }
  return -1;
}


// ==== FUN_007d3a10 @ 0x007d3a10 ====

void FUN_007d3a10(short *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  
  if (param_1 != (short *)0x0) {
    iVar3 = 0;
    psVar4 = param_1 + 2;
    if (0 < *param_1) {
      do {
        FUN_007d05b0(*(undefined4 *)psVar4);
        FUN_007d05b0(*(undefined4 *)(psVar4 + 2));
        FUN_007d05b0(*(undefined4 *)(psVar4 + 4));
        FUN_007d25e0(0,*(undefined4 *)(psVar4 + 6));
        FUN_007e6af0(*(undefined4 *)(psVar4 + 8));
        FUN_007eabc0(*(undefined4 *)(psVar4 + 0xe));
        piVar1 = *(int **)(psVar4 + 0x10);
        if (piVar1 != (int *)0x0) {
          iVar2 = 0;
          if (0 < *piVar1) {
            do {
              FUN_007d05b0(*(undefined4 *)(piVar1[2] + iVar2 * 8));
              iVar2 = iVar2 + 1;
            } while (iVar2 < *piVar1);
          }
          FUN_007d05b0(piVar1[2]);
          FUN_007d05b0(piVar1);
        }
        iVar3 = iVar3 + 1;
        psVar4 = psVar4 + 0x14;
      } while (iVar3 < *param_1);
    }
    FUN_007d05b0(param_1);
  }
  return;
}


// ==== FUN_007d3ad0 @ 0x007d3ad0 ====

void FUN_007d3ad0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (((((param_1 != (int *)0x0) && (piVar1 = (int *)*param_1, piVar1 != (int *)0x0)) &&
       (*(int *)(piVar1[1] + 4) != 0)) && ((param_1[6] == 0 && (DAT_00b5c4c4 == 0)))) &&
     ((iVar2 = FUN_007ed5e0(param_1,0x16,s_BEGIN_00a00440,0,0), iVar2 == 0 &&
      (iVar2 = FUN_007e8190(param_1), iVar2 != 0)))) {
    if ((param_2 != 0xe) && (iVar3 = 0, 0 < *piVar1)) {
      do {
        FUN_007dc140(iVar2,0x69,iVar3,(param_2 == 0x10) + '\x01');
        iVar3 = iVar3 + 1;
      } while (iVar3 < *piVar1);
    }
    FUN_007dc140(iVar2,0x11,0,0);
  }
  return;
}


// ==== FUN_007d3b70 @ 0x007d3b70 ====

void FUN_007d3b70(int *param_1)

{
  int iVar1;
  
  if ((((param_1 != (int *)0x0) && (*param_1 != 0)) && (*(int *)(*(int *)(*param_1 + 4) + 4) != 0))
     && ((param_1[6] == 0 && (DAT_00b5c4c4 == 0)))) {
    iVar1 = FUN_007ed5e0(param_1,0x16,s_COMMIT_00a00448,0,0);
    if (iVar1 == 0) {
      iVar1 = FUN_007e8190(param_1);
      if (iVar1 != 0) {
        FUN_007dc140(iVar1,0x11,1,0);
      }
    }
  }
  return;
}


// ==== FUN_007d3bd0 @ 0x007d3bd0 ====

void FUN_007d3bd0(int *param_1)

{
  int iVar1;
  
  if ((((param_1 != (int *)0x0) && (*param_1 != 0)) && (*(int *)(*(int *)(*param_1 + 4) + 4) != 0))
     && ((param_1[6] == 0 && (DAT_00b5c4c4 == 0)))) {
    iVar1 = FUN_007ed5e0(param_1,0x16,s_ROLLBACK_00a00450,0,0);
    if (iVar1 == 0) {
      iVar1 = FUN_007e8190(param_1);
      if (iVar1 != 0) {
        FUN_007dc140(iVar1,0x11,1,1);
      }
    }
  }
  return;
}


// ==== FUN_007d3c30 @ 0x007d3c30 ====

undefined4 FUN_007d3c30(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EDI;
  
  iVar2 = *unaff_EDI;
  if ((*(int *)(*(int *)(iVar2 + 4) + 0x74) == 0) && ((char)unaff_EDI[0x1d] == '\0')) {
    iVar1 = FUN_007cd6c0(iVar2,0,0,2000,*(int *)(iVar2 + 4) + 0x74);
    if (iVar1 != 0) {
      FUN_007d0820();
      unaff_EDI[1] = iVar1;
      return 1;
    }
    if ((*(uint *)(iVar2 + 8) & (uint)(*(char *)(iVar2 + 0x11) == '\0')) != 0) {
      iVar2 = FUN_007d69e0(*(undefined4 *)(*(int *)(iVar2 + 4) + 0x74),1);
      if (iVar2 != 0) {
        FUN_007d0820();
        unaff_EDI[1] = iVar2;
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_007d3cc0 @ 0x007d3cc0 ====

void FUN_007d3cc0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_007e8190(param_1);
  if (iVar2 != 0) {
    iVar1 = *param_1;
    if (param_1[0xc] == 0) {
      iVar2 = FUN_007dc140(iVar2,0x61,0,0);
      param_1[0xc] = iVar2 + 1;
    }
    if (-1 < param_2) {
      uVar3 = 1 << ((byte)param_2 & 0x1f);
      if ((uVar3 & param_1[0xb]) == 0) {
        param_1[0xb] = param_1[0xb] | uVar3;
        param_1[param_2 + 0xd] = *(int *)(param_2 * 0x70 + 8 + *(int *)(iVar1 + 4));
        if (param_2 == 1) {
          FUN_007d3c30();
        }
      }
    }
  }
  return;
}


// ==== FUN_007d3d30 @ 0x007d3d30 ====

void FUN_007d3d30(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_007e8190(param_1);
  if (iVar1 != 0) {
    do {
      FUN_007d3cc0(param_1,param_3);
      param_1[10] = param_1[10] | 1 << ((byte)param_3 & 0x1f);
      if ((param_2 != 0) && (*(char *)((int)param_1 + 0x13) == '\0')) {
        FUN_007dc140(iVar1,0x29,param_3,0);
      }
      if (param_3 == 1) {
        return;
      }
      if (*(int *)(*(int *)(*param_1 + 4) + 0x74) == 0) {
        return;
      }
      param_3 = 1;
      iVar1 = FUN_007e8190(param_1);
    } while (iVar1 != 0);
  }
  return;
}


// ==== FUN_007d3db0 @ 0x007d3db0 ====

void FUN_007d3db0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *(int *)(param_2 + 0x10);
  do {
    if (iVar1 == 0) {
      return;
    }
    if (param_3 == 0) {
LAB_007d3de5:
      FUN_007d3d30(param_1,0,*(undefined1 *)(param_2 + 0x1d));
      FUN_007d3770(0xffffffff);
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x24);
      piVar3 = (int *)(iVar1 + 0x2c);
      while (iVar2 != 0) {
        iVar2 = iVar2 + -1;
        if (*piVar3 == param_3) goto LAB_007d3de5;
        piVar3 = piVar3 + 1;
      }
    }
    iVar1 = *(int *)(iVar1 + 0x1c);
  } while( true );
}


// ==== FUN_007d3e10 @ 0x007d3e10 ====

void FUN_007d3e10(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = param_1;
  piVar1 = (int *)*param_1;
  iVar4 = piVar1[1];
  param_1 = (int *)0x0;
  if (0 < *piVar1) {
    do {
      if (iVar4 != 0) {
        for (puVar2 = *(undefined4 **)(iVar4 + 0x14); puVar2 != (undefined4 *)0x0;
            puVar2 = (undefined4 *)*puVar2) {
          FUN_007d3db0(piVar3,puVar2[2],param_2);
        }
      }
      param_1 = (int *)((int)param_1 + 1);
      iVar4 = iVar4 + 0x70;
    } while ((int)param_1 < *piVar1);
  }
  return;
}


// ==== FUN_007d3e70 @ 0x007d3e70 ====

void FUN_007d3e70(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  piVar2 = param_1;
  iVar8 = *param_1;
  iVar6 = FUN_007ce9f0(param_1);
  piVar5 = param_3;
  piVar4 = param_2;
  if (iVar6 == 0) {
    if ((param_2 == (int *)0x0) || (*param_2 == 0)) {
      FUN_007d3e10(piVar2,0);
      return;
    }
    if (((param_3 == (int *)0x0) || (*param_3 == 0)) &&
       (iVar6 = FUN_007de2b0(iVar8,*(undefined1 *)(iVar8 + 0x10),*param_2,(uint)param_2[1] >> 1,0),
       iVar6 != 0)) {
      FUN_007d3e10(piVar2,iVar6);
    }
    else {
      iVar6 = FUN_007d2850(piVar2,piVar4,piVar5,&param_1);
      if (-1 < iVar6) {
        param_1 = (int *)FUN_007d2730(param_1);
        uVar1 = *(undefined4 *)(iVar6 * 0x70 + *(int *)(iVar8 + 4));
        iVar7 = FUN_007d22b0(iVar8,param_1,uVar1);
        uVar3 = param_1;
        if (iVar7 != 0) {
          for (iVar8 = *(int *)(iVar7 + 0x10); iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x1c)) {
            FUN_007d3d30(piVar2,0,*(undefined1 *)(iVar7 + 0x1d));
            FUN_007d3770(0xffffffff);
          }
          FUN_007d05b0(param_1);
          return;
        }
        iVar8 = FUN_007d23d0(iVar8,param_1,uVar1);
        FUN_007d05b0(uVar3);
        if (iVar8 == 0) {
          FUN_007d0820(piVar2,s_unable_to_identify_the_object_to_00a004e0);
          return;
        }
        FUN_007d3d30(piVar2,0,iVar6);
        FUN_007d3770(0xffffffff);
        return;
      }
    }
  }
  return;
}


// ==== FUN_007d3fc0 @ 0x007d3fc0 ====

void FUN_007d3fc0(int *param_1,int param_2)

{
  int *piVar1;
  byte *pbVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar4 = param_1;
  iVar6 = *param_1;
  param_1[2] = param_1[2] & 0xfffffffd;
  param_1 = (int *)param_2;
  if (param_2 < iVar6) {
    local_2c = param_2 * 0x70;
    do {
      iVar6 = piVar4[1] + local_2c;
      local_14 = *(undefined4 *)(iVar6 + 0xc);
      local_10 = *(undefined4 *)(iVar6 + 0x10);
      local_c = *(undefined4 **)(iVar6 + 0x14);
      local_8 = *(undefined4 *)(iVar6 + 0x18);
      local_4 = *(undefined4 *)(iVar6 + 0x1c);
      local_28 = *(undefined4 *)(iVar6 + 0x34);
      local_24 = *(undefined4 *)(iVar6 + 0x38);
      local_20 = *(undefined4 **)(iVar6 + 0x3c);
      local_1c = *(undefined4 *)(iVar6 + 0x40);
      local_18 = *(undefined4 *)(iVar6 + 0x44);
      FUN_007d1b60((undefined4 *)(iVar6 + 0x34),3,0);
      FUN_007d1b80(iVar6 + 0x48);
      FUN_007d1b80(iVar6 + 0x20);
      for (puVar8 = local_20; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {
        FUN_007ed8e0(puVar8[2]);
      }
      FUN_007d1b80(&local_28);
      FUN_007d1b60((undefined4 *)(iVar6 + 0xc),3,0);
      for (puVar8 = local_c; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {
        FUN_007d25e0(piVar4,puVar8[2]);
      }
      FUN_007d1b80(&local_14);
      *(undefined4 *)(iVar6 + 100) = 0;
      pbVar2 = (byte *)(local_2c + 0x5c + piVar4[1]);
      *pbVar2 = *pbVar2 & 0xfe;
      if (0 < param_2) {
        return;
      }
      param_1 = (int *)((int)param_1 + 1);
      local_2c = local_2c + 0x70;
    } while ((int)param_1 < *piVar4);
  }
  iVar6 = 0;
  piVar4[2] = piVar4[2] & 0xffffffef;
  if (0 < *piVar4) {
    iVar10 = 0;
    do {
      iVar7 = piVar4[1] + iVar10;
      if (*(int *)(piVar4[1] + 4 + iVar10) == 0) {
        if ((*(int *)(iVar7 + 0x68) != 0) && (*(code **)(iVar7 + 0x6c) != (code *)0x0)) {
          (**(code **)(iVar7 + 0x6c))(*(int *)(iVar7 + 0x68));
        }
        *(undefined4 *)(iVar7 + 0x68) = 0;
      }
      iVar6 = iVar6 + 1;
      iVar10 = iVar10 + 0x70;
    } while (iVar6 < *piVar4);
  }
  iVar6 = 2;
  param_1 = (int *)0x2;
  if (2 < *piVar4) {
    param_2 = 0xe0;
    local_2c = 0xe0;
    do {
      iVar10 = piVar4[1];
      puVar8 = (undefined4 *)(local_2c + iVar10);
      if (*(int *)(local_2c + 4 + iVar10) == 0) {
        FUN_007d05b0(*puVar8);
        *puVar8 = 0;
      }
      else {
        if (iVar6 < (int)param_1) {
          puVar11 = (undefined4 *)(param_2 + iVar10);
          for (iVar7 = 0x1c; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar11 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar11 = puVar11 + 1;
          }
        }
        iVar6 = iVar6 + 1;
        param_2 = param_2 + 0x70;
      }
      param_1 = (int *)((int)param_1 + 1);
      local_2c = local_2c + 0x70;
    } while ((int)param_1 < *piVar4);
  }
  puVar8 = (undefined4 *)(iVar6 * 0x70 + piVar4[1]);
  for (uVar5 = (uint)((*piVar4 - iVar6) * 0x70) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined1 *)puVar8 = 0;
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  *piVar4 = iVar6;
  if (iVar6 < 3) {
    piVar3 = (int *)piVar4[1];
    piVar1 = piVar4 + 0x32;
    if (piVar3 != piVar1) {
      piVar9 = piVar3;
      piVar12 = piVar1;
      for (iVar6 = 0x38; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar12 = *piVar9;
        piVar9 = piVar9 + 1;
        piVar12 = piVar12 + 1;
      }
      FUN_007d05b0(piVar3);
      piVar4[1] = (int)piVar1;
    }
  }
  return;
}


// ==== FUN_007d4220 @ 0x007d4220 ====

void FUN_007d4220(int param_1)

{
  if ((*(byte *)(param_1 + 8) & 0x10) != 0) {
    FUN_007d3fc0(param_1,0);
  }
  return;
}


// ==== FUN_007d4240 @ 0x007d4240 ====

void FUN_007d4240(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  bool bVar9;
  int iVar10;
  int *local_c;
  undefined4 local_8;
  int local_4;
  
  iVar10 = *param_1;
  iVar2 = FUN_007d2850(param_1,param_3,param_4,&local_c);
  if (-1 < iVar2) {
    if (param_5 != 0) {
      if (1 < iVar2) {
        FUN_007d0820(param_1,s_temporary_table_name_must_be_unq_00a0055c);
        return;
      }
      iVar2 = 1;
    }
    param_1[0x20] = *local_c;
    param_1[0x21] = local_c[1];
    pcVar3 = (char *)FUN_007d06a0(*local_c,(uint)local_c[1] >> 1);
    FUN_007d0860(pcVar3);
    if (pcVar3 != (char *)0x0) {
      iVar4 = FUN_007d28b0(param_1,pcVar3);
      if (iVar4 == 0) {
        if (*(int *)(iVar10 + 0x3c) == 1) {
          param_5 = 1;
        }
        iVar4 = iVar2 * 0x70;
        local_8 = *(undefined4 *)(*(int *)(iVar10 + 4) + iVar4);
        pcVar5 = s_sqlite_temp_master_009fff68;
        if (param_5 != 1) {
          pcVar5 = s_sqlite_master_009fff58;
        }
        local_4 = iVar4;
        iVar6 = FUN_007ed5e0(param_1,0x12,pcVar5,0,local_8);
        if (iVar6 == 0) {
          if (param_6 == 0) {
            cVar1 = (param_5 != 0) * '\x02' + '\x02';
          }
          else {
            cVar1 = (param_5 == 0) * '\x02' + '\x06';
          }
          iVar6 = FUN_007ed5e0(param_1,cVar1,pcVar3,0,local_8);
          if ((iVar6 == 0) && (iVar6 = FUN_007ce9f0(param_1), iVar6 == 0)) {
            iVar4 = FUN_007d22b0(iVar10,pcVar3,*(undefined4 *)(*(int *)(iVar10 + 4) + iVar4));
            if (iVar4 != 0) {
              FUN_007d0820(param_1,s_table__T_already_exists_00a00544,local_c);
              FUN_007d05b0(pcVar3);
              return;
            }
            iVar4 = FUN_007d23d0(iVar10,pcVar3,0);
            if ((iVar4 != 0) && ((iVar2 == 0 || (*(char *)(iVar10 + 0x44) == '\0')))) {
              FUN_007d0820(param_1,s_there_is_already_an_index_named___00a00520,pcVar3);
              FUN_007d05b0(pcVar3);
              return;
            }
            puVar7 = (undefined4 *)FUN_007d0550(0x38);
            if (puVar7 != (undefined4 *)0x0) {
              *puVar7 = pcVar3;
              puVar7[1] = 0;
              puVar7[2] = 0;
              puVar7[3] = 0xffffffff;
              puVar7[4] = 0;
              *(char *)((int)puVar7 + 0x1d) = (char)iVar2;
              puVar7[9] = 1;
              if (param_1[0x26] != 0) {
                FUN_007d25e0(iVar10,param_1[0x26]);
              }
              param_1[0x26] = (int)puVar7;
              iVar4 = 0x10;
              bVar9 = true;
              pcVar5 = s_sqlite_sequence_00a00510;
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar9 = *pcVar3 == *pcVar5;
                pcVar3 = pcVar3 + 1;
                pcVar5 = pcVar5 + 1;
              } while (bVar9);
              if (bVar9) {
                *(undefined4 **)(*(int *)(iVar10 + 4) + 100 + local_4) = puVar7;
              }
              if (*(char *)(iVar10 + 0x44) != '\0') {
                return;
              }
              iVar4 = FUN_007e8190(param_1);
              if (iVar4 == 0) {
                return;
              }
              FUN_007d3d30(param_1,0,iVar2);
              FUN_007dc140(iVar4,0x73,iVar2,1);
              uVar8 = FUN_007dc190(iVar4);
              FUN_007dc140(iVar4,10,0,uVar8);
              FUN_007dc140(iVar4,0x32,*(undefined1 *)(iVar10 + 0x12),0);
              FUN_007dc140(iVar4,3,iVar2,1);
              FUN_007dc140(iVar4,0x32,*(undefined1 *)(iVar10 + 0x10),0);
              FUN_007dc140(iVar4,3,iVar2,4);
              FUN_007dc1e0(iVar4,uVar8);
              if (param_6 == 0) {
                uVar8 = 0x35;
                iVar10 = iVar2;
              }
              else {
                uVar8 = 0x32;
                iVar10 = 0;
              }
              FUN_007dc140(iVar4,uVar8,iVar10,0);
              FUN_007d2760(iVar4,iVar2);
              FUN_007dc140(iVar4,0x19,0,0);
              FUN_007dc140(iVar4,0x60,0,0);
              FUN_007dc140(iVar4,0x76,0,0);
              FUN_007dc140(iVar4,0x71,0,0);
              FUN_007dc140(iVar4,0x1e,0,0);
              FUN_007dc140(iVar4,0x66,1,0);
              return;
            }
            param_1[1] = 7;
            param_1[6] = param_1[6] + 1;
          }
        }
      }
      FUN_007d05b0(pcVar3);
      return;
    }
  }
  return;
}


// ==== FUN_007d4590 @ 0x007d4590 ====

void FUN_007d4590(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x98);
  if (iVar1 != 0) {
    iVar3 = *(int *)(iVar1 + 4) + -1;
    uVar2 = FUN_007d2c50(param_1,param_2,param_3);
    *(undefined4 *)(*(int *)(iVar1 + 8) + 0xc + iVar3 * 0x14) = uVar2;
    for (iVar1 = *(int *)(iVar1 + 0x10); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
      if (**(int **)(iVar1 + 8) == iVar3) {
        *(undefined4 *)(iVar1 + 0x2c) = uVar2;
      }
    }
  }
  return;
}


// ==== FUN_007d45e0 @ 0x007d45e0 ====

undefined4 FUN_007d45e0(int *param_1,undefined4 *param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (0 < (int)param_2[1]) {
    return 0;
  }
  if ((int)param_2[1] < 0) {
    FUN_007d0820(param_1,s_view__s_is_circularly_defined_00a00588,*param_2);
    return 1;
  }
  iVar3 = FUN_007ead10(param_2[6]);
  iVar2 = param_1[7];
  FUN_007d38e0(param_1,*(undefined4 *)(iVar3 + 8));
  param_2[1] = 0xffffffff;
  iVar4 = FUN_007e7770(param_1,0,iVar3);
  param_1[7] = iVar2;
  if (iVar4 == 0) {
    param_2[1] = 0;
    FUN_007e6af0(iVar3);
    return 1;
  }
  param_2[1] = *(undefined4 *)(iVar4 + 4);
  param_2[2] = *(undefined4 *)(iVar4 + 8);
  *(undefined4 *)(iVar4 + 4) = 0;
  *(undefined4 *)(iVar4 + 8) = 0;
  FUN_007d25e0(0,iVar4);
  pbVar1 = (byte *)((uint)*(byte *)((int)param_2 + 0x1d) * 0x70 + 0x5c + *(int *)(*param_1 + 4));
  *pbVar1 = *pbVar1 | 2;
  FUN_007e6af0(iVar3);
  return 0;
}


// ==== FUN_007d46c0 @ 0x007d46c0 ====

void FUN_007d46c0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  
  iVar1 = *param_1;
  if (((param_1[6] == 0) && (DAT_00b5c4c4 == 0)) &&
     (puVar4 = (undefined4 *)
               FUN_007d2330(param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4)),
     puVar4 != (undefined4 *)0x0)) {
    uVar7 = (uint)*(byte *)((int)puVar4 + 0x1d);
    pcVar5 = s_sqlite_temp_master_009fff68;
    if (*(byte *)((int)puVar4 + 0x1d) != 1) {
      pcVar5 = s_sqlite_master_009fff58;
    }
    uVar9 = *(undefined4 *)((uint)*(byte *)((int)puVar4 + 0x1d) * 0x70 + *(int *)(iVar1 + 4));
    iVar6 = FUN_007ed5e0(param_1,9,pcVar5,0,uVar9);
    if (iVar6 == 0) {
      if (param_3 == 0) {
        cVar3 = (uVar7 == 1) * '\x02' + '\v';
      }
      else {
        cVar3 = (uVar7 != 1) * '\x02' + '\x0f';
      }
      iVar6 = FUN_007ed5e0(param_1,cVar3,*puVar4,0,uVar9);
      if ((iVar6 == 0) && (iVar6 = FUN_007ed5e0(param_1,9,*puVar4,0,uVar9), iVar6 == 0)) {
        if ((*(char *)(puVar4 + 7) == '\0') &&
           (puVar4 != *(undefined4 **)(uVar7 * 0x70 + 100 + *(int *)(iVar1 + 4)))) {
          if (param_3 == 0) {
            if (puVar4[6] == 0) goto LAB_007d47e6;
            uVar9 = *puVar4;
            pcVar5 = s_use_DROP_VIEW_to_delete_view__s_00a0062c;
          }
          else {
            if (puVar4[6] != 0) {
LAB_007d47e6:
              iVar6 = FUN_007e8190(param_1);
              if (iVar6 != 0) {
                uVar7 = (uint)*(byte *)((int)puVar4 + 0x1d);
                puVar8 = (undefined4 *)(uVar7 * 0x70 + *(int *)(iVar1 + 4));
                FUN_007d3d30(param_1,0,uVar7);
                for (iVar2 = puVar4[10]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x24)) {
                  FUN_007ed940(param_1,iVar2,1);
                }
                if (*(char *)((int)puVar4 + 0x21) != '\0') {
                  FUN_007d2210(param_1,s_DELETE_FROM__s_sqlite_sequence_W_00a005fc,*puVar8,*puVar4);
                }
                pcVar5 = s_sqlite_temp_master_009fff68;
                if (uVar7 != 1) {
                  pcVar5 = s_sqlite_master_009fff58;
                }
                FUN_007d2210(param_1,s_DELETE_FROM__Q__s_WHERE_tbl_name_00a005c4,*puVar8,pcVar5,
                             *puVar4);
                if (param_3 == 0) {
                  FUN_007d33d0(puVar4);
                }
                FUN_007dda80(iVar6,0x58,uVar7,0,*puVar4,0);
                FUN_007d2ce0(iVar1,iVar6,uVar7);
              }
              FUN_007d32e0(iVar1);
              FUN_007d3a10(param_2);
              return;
            }
            uVar9 = *puVar4;
            pcVar5 = s_use_DROP_TABLE_to_delete_table___00a0064c;
          }
        }
        else {
          uVar9 = *puVar4;
          pcVar5 = s_table__s_may_not_be_dropped_00a005a8;
        }
        FUN_007d0820(param_1,pcVar5,uVar9);
      }
    }
  }
  FUN_007d3a10(param_2);
  return;
}


// ==== FUN_007d4900 @ 0x007d4900 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007d4900(int *param_1,undefined4 param_2,int param_3,int param_4,int *param_5,int param_6,
                 int param_7,int *param_8)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  undefined4 uVar11;
  int *piVar12;
  int iVar13;
  undefined4 *local_60;
  char *local_5c;
  uint local_58;
  int local_54;
  int local_50;
  int *local_4c;
  int *local_48;
  int local_44;
  char *local_40;
  uint local_3c;
  int local_38;
  undefined1 local_34 [16];
  char local_24 [32];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar5 = *param_1;
  local_5c = (char *)0x0;
  local_4c = (int *)0x0;
  local_50 = iVar5;
  if ((param_1[6] != 0) || (DAT_00b5c4c4 != 0)) goto LAB_007d4e31;
  if (param_4 == 0) {
    local_60 = (undefined4 *)param_1[0x26];
    local_58 = (uint)*(byte *)((int)local_60 + 0x1d);
  }
  else {
    local_58 = FUN_007d2850(param_1,param_2,param_3,&local_4c);
    if ((int)local_58 < 0) goto LAB_007d4e31;
    iVar3 = FUN_007ecc30(param_1,param_4);
    if ((((param_3 != 0) && ((*(uint *)(param_3 + 4) & 0xfffffffe) == 0)) && (iVar3 != 0)) &&
       (*(char *)(iVar3 + 0x1d) == '\x01')) {
      local_58 = 1;
    }
    iVar3 = FUN_007ee9a0(local_34,param_1,local_58,s_index_009fe430,local_4c);
    if (((iVar3 != 0) && (iVar3 = FUN_007eea70(local_34,param_4), iVar3 != 0)) ||
       (local_60 = (undefined4 *)
                   FUN_007d2330(param_1,*(undefined4 *)(param_4 + 8),*(undefined4 *)(param_4 + 4)),
       local_60 == (undefined4 *)0x0)) goto LAB_007d4e31;
  }
  if (param_1[6] != 0) goto LAB_007d4e31;
  if (*(char *)(local_60 + 7) != '\0') {
    FUN_007d0820(param_1,s_table__s_may_not_be_indexed_00a00784,*local_60);
    goto LAB_007d4e31;
  }
  if (local_60[6] != 0) {
    FUN_007d0820(param_1,s_views_may_not_be_indexed_00a00768);
    goto LAB_007d4e31;
  }
  if (local_4c == (int *)0x0) {
    iVar13 = 1;
    for (iVar3 = local_60[4]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x1c)) {
      iVar13 = iVar13 + 1;
    }
    _sprintf(local_24,(char *)&PTR___break_00a00728,iVar13);
    local_5c = (char *)0x0;
    FUN_007d0700(&local_5c,s_sqlite_autoindex__00a00714,*local_60,local_24,0);
    if (local_5c == (char *)0x0) goto LAB_007d4e31;
  }
  else {
    local_5c = (char *)FUN_007d2730(local_4c);
    iVar3 = FUN_007ce9f0(param_1);
    if (((iVar3 != 0) || (local_5c == (char *)0x0)) ||
       (iVar3 = FUN_007d28b0(param_1,local_5c), iVar3 != 0)) goto LAB_007d4e31;
    if (*(char *)(iVar5 + 0x44) == '\0') {
      iVar3 = FUN_007ce9f0(param_1);
      if (iVar3 != 0) goto LAB_007d4e31;
      iVar3 = FUN_007d23d0(iVar5,local_5c,*(undefined4 *)(local_58 * 0x70 + *(int *)(iVar5 + 4)));
      if (iVar3 != 0) {
        FUN_007d0820(param_1,s_index__s_already_exists_00a00750,local_5c);
        goto LAB_007d4e31;
      }
      iVar3 = FUN_007d22b0(iVar5,local_5c,0);
      if (iVar3 != 0) {
        FUN_007d0820(param_1,s_there_is_already_a_table_named___00a0072c,local_5c);
        goto LAB_007d4e31;
      }
    }
  }
  local_38 = local_58 * 0x70;
  uVar11 = *(undefined4 *)(local_38 + *(int *)(iVar5 + 4));
  pcVar4 = s_sqlite_temp_master_009fff68;
  if (local_58 != 1) {
    pcVar4 = s_sqlite_master_009fff58;
  }
  iVar5 = FUN_007ed5e0(param_1,0x12,pcVar4,0,uVar11);
  if (iVar5 != 0) goto LAB_007d4e31;
  uVar6 = 1;
  if (local_58 == 1) {
    uVar6 = 3;
  }
  iVar5 = FUN_007ed5e0(param_1,uVar6,local_5c,*local_60,uVar11);
  if (iVar5 != 0) goto LAB_007d4e31;
  if (param_5 == (int *)0x0) {
    local_40 = *(char **)(local_60[2] + -0x14 + local_60[1] * 0x14);
    pcVar4 = local_40;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    local_3c = ((int)pcVar4 - (int)(local_40 + 1)) * 2 | local_3c & 1;
    param_5 = (int *)FUN_007eadd0(0,0,&local_40);
    if (param_5 == (int *)0x0) goto LAB_007d4e31;
  }
  pcVar4 = local_5c;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  piVar7 = (int *)FUN_007d0550(pcVar4 + *param_5 * 8 + (0x31 - (int)(local_5c + 1)));
  if (DAT_00b5c4c4 == 0) {
    iVar5 = *param_5;
    piVar7[2] = (int)(piVar7 + iVar5 + 0xb);
    piVar12 = piVar7 + iVar5 + 0xb + *param_5;
    *piVar7 = (int)piVar12;
    pcVar4 = local_5c;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      *(char *)piVar12 = cVar1;
      piVar12 = (int *)((int)piVar12 + 1);
    } while (cVar1 != '\0');
    piVar7[3] = (int)local_60;
    iVar5 = *param_5;
    *(undefined1 *)(piVar7 + 5) = (undefined1)param_6;
    piVar7[1] = iVar5;
    *(bool *)((int)piVar7 + 0x15) = local_4c == (int *)0x0;
    *(undefined1 *)((int)piVar7 + 0x16) = (undefined1)local_58;
    local_54 = 0;
    if (0 < *param_5) {
      iVar5 = 0;
      local_48 = piVar7 + 0xb;
      local_44 = -0x2c - (int)piVar7;
      do {
        iVar3 = 0;
        if (0 < (int)local_60[1]) {
          iVar13 = 0;
          do {
            iVar8 = FUN_007d08e0(*(undefined4 *)(param_5[2] + 4 + iVar5),
                                 *(undefined4 *)(local_60[2] + iVar13));
            if (iVar8 == 0) break;
            iVar3 = iVar3 + 1;
            iVar13 = iVar13 + 0x14;
          } while (iVar3 < (int)local_60[1]);
        }
        if ((int)local_60[1] <= iVar3) {
          FUN_007d0820(param_1,s_table__s_has_no_column_named__s_00a006f4,*local_60,
                       *(undefined4 *)(param_5[2] + 4 + local_54 * 0xc));
          goto LAB_007d4e14;
        }
        *(int *)((int)local_48 + piVar7[2] + local_44) = iVar3;
        if (*(int *)(iVar5 + param_5[2]) == 0) {
          *local_48 = *(int *)(local_60[2] + 0xc + iVar3 * 0x14);
        }
        else {
          *local_48 = *(int *)(*(int *)(iVar5 + param_5[2]) + 4);
        }
        if ((*(char *)(local_50 + 0x44) == '\0') &&
           (iVar3 = FUN_007de5b0(param_1,*local_48), iVar3 != 0)) goto LAB_007d4e14;
        local_54 = local_54 + 1;
        local_48 = local_48 + 1;
        iVar5 = iVar5 + 0xc;
      } while (local_54 < *param_5);
    }
    iVar5 = local_50;
    piVar7[9] = *param_5;
    if (local_60 == (undefined4 *)param_1[0x26]) {
      for (iVar3 = local_60[4]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x1c)) {
        if (*(int *)(iVar3 + 4) == piVar7[1]) {
          iVar13 = 0;
          if (0 < *(int *)(iVar3 + 4)) {
            piVar9 = (int *)piVar7[2];
            local_44 = *(int *)(iVar3 + 8) - (int)piVar9;
            piVar12 = piVar7 + 0xb;
            do {
              if ((*(int *)(local_44 + (int)piVar9) != *piVar9) ||
                 (*(int *)((int)piVar12 + (iVar3 - (int)piVar7)) != *piVar12)) break;
              iVar13 = iVar13 + 1;
              piVar9 = piVar9 + 1;
              piVar12 = piVar12 + 1;
            } while (iVar13 < *(int *)(iVar3 + 4));
          }
          if (iVar13 == *(int *)(iVar3 + 4)) {
            if (*(char *)(iVar3 + 0x14) != (char)piVar7[5]) {
              if ((*(char *)(iVar3 + 0x14) != 'c') && ((char)piVar7[5] != 'c')) {
                FUN_007d0820(param_1,s_conflicting_ON_CONFLICT_clauses_s_00a006c8,0);
              }
              if (*(char *)(iVar3 + 0x14) == 'c') {
                *(char *)(iVar3 + 0x14) = (char)piVar7[5];
              }
            }
            goto LAB_007d4e14;
          }
        }
      }
    }
    if (*(char *)(local_50 + 0x44) == '\0') {
      local_54 = param_1[8];
      param_1[8] = local_54 + 1;
      iVar5 = FUN_007e8190(param_1);
      uVar2 = local_58;
      if (iVar5 != 0) {
        FUN_007d3d30(param_1,1,local_58);
        FUN_007dc140(iVar5,0x20,uVar2,0);
        FUN_007dc140(iVar5,0x78,local_54,0);
        if ((param_7 == 0) || (param_8 == (int *)0x0)) {
          uVar11 = 0;
        }
        else {
          pcVar4 = &DAT_0099cf70;
          if (param_6 != 0) {
            pcVar4 = s_UNIQUE_00a006c0;
          }
          uVar11 = FUN_007e4830(s_CREATE_s_INDEX____s_00a006ac,pcVar4,(*param_8 - *local_4c) + 1,
                                *local_4c);
        }
        pcVar4 = s_sqlite_temp_master_009fff68;
        if (uVar2 != 1) {
          pcVar4 = s_sqlite_master_009fff58;
        }
        FUN_007d2210(param_1,s_INSERT_INTO__Q__s_VALUES__index__00a0067c,
                     *(undefined4 *)(*(int *)(local_50 + 4) + local_38),pcVar4,*piVar7,*local_60,
                     uVar11);
        FUN_007dc140(iVar5,0xb,1,0);
        FUN_007d05b0(uVar11);
        if (param_4 != 0) {
          FUN_007d3770(local_54);
          FUN_007d2ce0(local_50,iVar5,uVar2);
          uVar11 = FUN_007e4830(s_name___q__00a00670,*piVar7,0xffffffff);
          FUN_007dda80(iVar5,0x1c,uVar2,0,uVar11);
          FUN_007dc140(iVar5,0xf,0,0);
        }
        goto LAB_007d507b;
      }
    }
    else {
      pcVar4 = (char *)*piVar7;
      pcVar10 = pcVar4;
      do {
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      iVar3 = FUN_007d1f20((uint)*(byte *)((int)piVar7 + 0x16) * 0x70 + 0x20 +
                           *(int *)(local_50 + 4),pcVar4,pcVar10 + (1 - (int)(pcVar4 + 1)),piVar7);
      if (iVar3 == 0) {
        *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) | 0x10;
        if (param_4 != 0) {
          piVar7[4] = *(int *)(local_50 + 0x40);
        }
LAB_007d507b:
        if ((*(char *)(local_50 + 0x44) != '\0') || (param_4 == 0)) {
          if ((param_6 == 5) &&
             ((iVar5 = local_60[4], iVar5 != 0 && (*(char *)(iVar5 + 0x14) != '\x05')))) {
            iVar3 = *(int *)(iVar5 + 0x1c);
            while ((iVar3 != 0 &&
                   (iVar13 = *(int *)(iVar5 + 0x1c), *(char *)(iVar13 + 0x14) != '\x05'))) {
              iVar3 = *(int *)(iVar13 + 0x1c);
              iVar5 = iVar13;
            }
            piVar7[7] = *(int *)(iVar5 + 0x1c);
            *(int **)(iVar5 + 0x1c) = piVar7;
          }
          else {
            piVar7[7] = local_60[4];
            local_60[4] = piVar7;
          }
          goto LAB_007d4e31;
        }
      }
    }
  }
LAB_007d4e14:
  if (piVar7 != (int *)0x0) {
    FUN_007d05b0(piVar7[6]);
    FUN_007d05b0(piVar7);
  }
LAB_007d4e31:
  FUN_007ea740(param_5);
  FUN_007d3a10(param_4);
  FUN_007d05b0(local_5c);
  return;
}


// ==== FUN_007d50f0 @ 0x007d50f0 ====

void FUN_007d50f0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  uint uVar9;
  
  piVar4 = param_1;
  iVar1 = *param_1;
  if (((param_1[6] == 0) && (DAT_00b5c4c4 == 0)) && (iVar5 = FUN_007ce9f0(param_1), iVar5 == 0)) {
    puVar6 = (undefined4 *)
             FUN_007d23d0(iVar1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4));
    if (puVar6 == (undefined4 *)0x0) {
      FUN_007d0820(param_1,s_no_such_index___S_00a0080c,param_2,0);
      *(undefined1 *)((int)param_1 + 0x12) = 1;
      FUN_007d3a10(param_2);
      return;
    }
    if (*(char *)((int)puVar6 + 0x15) != '\0') {
      FUN_007d0820(param_1,s_index_associated_with_UNIQUE_or_P_00a007c0,0);
      FUN_007d3a10(param_2);
      return;
    }
    puVar2 = (undefined4 *)puVar6[3];
    uVar3 = *(undefined4 *)((uint)*(byte *)((int)puVar6 + 0x16) * 0x70 + *(int *)(iVar1 + 4));
    param_1 = (int *)0xa;
    pcVar7 = s_sqlite_temp_master_009fff68;
    if (*(byte *)((int)puVar6 + 0x16) != 1) {
      pcVar7 = s_sqlite_master_009fff58;
    }
    iVar5 = FUN_007ed5e0(piVar4,9,pcVar7,0,uVar3);
    if (iVar5 == 0) {
      uVar8 = 0xc;
      if (*(char *)((int)puVar6 + 0x16) == '\0') {
        uVar8 = param_1;
      }
      iVar5 = FUN_007ed5e0(piVar4,uVar8,*puVar6,*puVar2,uVar3);
      if ((iVar5 == 0) && (iVar5 = FUN_007e8190(piVar4), iVar5 != 0)) {
        uVar9 = (uint)*(byte *)((int)puVar6 + 0x16);
        pcVar7 = s_sqlite_temp_master_009fff68;
        if (uVar9 != 1) {
          pcVar7 = s_sqlite_master_009fff58;
        }
        FUN_007d2210(piVar4,s_DELETE_FROM__Q__s_WHERE_name__Q_00a007a0,
                     *(undefined4 *)(uVar9 * 0x70 + *(int *)(iVar1 + 4)),pcVar7,*puVar6);
        FUN_007d2ce0(iVar1,iVar5,uVar9);
        FUN_007d3380();
        FUN_007dda80(iVar5,0x3c,uVar9,0,*puVar6,0);
      }
    }
  }
  FUN_007d3a10(param_2);
  return;
}


// ==== FUN_007d5280 @ 0x007d5280 ====

int * FUN_007d5280(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_1 == (int *)0x0) {
    param_1 = (int *)FUN_007d0550(0xc);
    if (param_1 == (int *)0x0) {
      return (int *)0x0;
    }
    param_1[1] = 0;
  }
  if (param_1[1] <= *param_1) {
    iVar2 = param_1[1] * 2 + 5;
    param_1[1] = iVar2;
    iVar2 = FUN_007d05d0(param_1[2],iVar2 * 8);
    if (iVar2 == 0) {
      FUN_007d3980(param_1);
      return (int *)0x0;
    }
    param_1[2] = iVar2;
  }
  puVar1 = (undefined4 *)(param_1[2] + *param_1 * 8);
  *puVar1 = 0;
  puVar1[1] = 0;
  if (param_2 != (undefined4 *)0x0) {
    uVar3 = FUN_007d06a0(*param_2,(uint)param_2[1] >> 1);
    FUN_007d0860(uVar3);
  }
  *(undefined4 *)(param_1[2] + *param_1 * 8) = uVar3;
  *param_1 = *param_1 + 1;
  return param_1;
}


// ==== FUN_007d5320 @ 0x007d5320 ====

short * FUN_007d5320(short *param_1,int *param_2,int *param_3)

{
  short *psVar1;
  short sVar2;
  short *psVar3;
  int *piVar4;
  undefined4 uVar5;
  
  if (param_1 == (short *)0x0) {
    param_1 = (short *)FUN_007d0550(0x2c);
    if (param_1 == (short *)0x0) {
      return (short *)0x0;
    }
    param_1[1] = 1;
  }
  psVar3 = param_1;
  if (param_1[1] <= *param_1) {
    sVar2 = param_1[1] * 2;
    param_1[1] = sVar2;
    psVar3 = (short *)FUN_007d05d0(param_1,sVar2 * 0x28 + 4);
    if (psVar3 == (short *)0x0) {
      FUN_007d3a10(param_1);
      return (short *)0x0;
    }
  }
  psVar1 = psVar3 + *psVar3 * 0x14 + 2;
  psVar1[0] = 0;
  psVar1[1] = 0;
  psVar1[2] = 0;
  psVar1[3] = 0;
  psVar1[4] = 0;
  psVar1[5] = 0;
  psVar1[6] = 0;
  psVar1[7] = 0;
  psVar1[8] = 0;
  psVar1[9] = 0;
  psVar1[10] = 0;
  psVar1[0xb] = 0;
  psVar1[0xc] = 0;
  psVar1[0xd] = 0;
  psVar1[0xe] = 0;
  psVar1[0xf] = 0;
  psVar1[0x10] = 0;
  psVar1[0x11] = 0;
  psVar1[0x12] = 0;
  psVar1[0x13] = 0;
  if (param_3 == (int *)0x0) {
LAB_007d53b7:
    piVar4 = param_2;
    param_2 = param_3;
LAB_007d53bb:
    param_3 = param_2;
    if (piVar4 != (int *)0x0) {
      uVar5 = FUN_007d06a0(*piVar4,(uint)piVar4[1] >> 1);
      FUN_007d0860(uVar5);
      goto LAB_007d53ea;
    }
  }
  else {
    if (*param_3 == 0) {
      param_3 = (int *)0x0;
      goto LAB_007d53b7;
    }
    if (param_2 != (int *)0x0) {
      piVar4 = param_3;
      goto LAB_007d53bb;
    }
  }
  uVar5 = 0;
LAB_007d53ea:
  *(undefined4 *)(psVar1 + 2) = uVar5;
  if (param_3 == (int *)0x0) {
    psVar1[0] = 0;
    psVar1[1] = 0;
    psVar1[0xc] = -1;
    psVar1[0xd] = -1;
    *psVar3 = *psVar3 + 1;
    return psVar3;
  }
  uVar5 = FUN_007d06a0(*param_3,(uint)param_3[1] >> 1);
  FUN_007d0860(uVar5);
  *(undefined4 *)psVar1 = uVar5;
  psVar1[0xc] = -1;
  psVar1[0xd] = -1;
  *psVar3 = *psVar3 + 1;
  return psVar3;
}


// ==== FUN_007d5440 @ 0x007d5440 ====

void FUN_007d5440(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8;
  int local_4;
  
  puVar1 = *(undefined4 **)(param_1 + 0x98);
  iVar4 = -1;
  if (puVar1 == (undefined4 *)0x0) {
LAB_007d5472:
    FUN_007ea740(param_2);
    return;
  }
  if (*(char *)((int)puVar1 + 0x1f) != '\0') {
    FUN_007d0820(param_1,s_table___s__has_more_than_one_pri_00a00860,*puVar1);
    goto LAB_007d5472;
  }
  *(undefined1 *)((int)puVar1 + 0x1f) = 1;
  if (param_2 == (int *)0x0) {
    iVar4 = puVar1[1] + -1;
    *(undefined1 *)(puVar1[2] + 0x11 + iVar4 * 0x14) = 1;
  }
  else {
    local_4 = 0;
    if (0 < *param_2) {
      local_8 = 0;
      do {
        iVar4 = 0;
        if (0 < (int)puVar1[1]) {
          iVar3 = 0;
          do {
            iVar2 = FUN_007d08e0(*(undefined4 *)(local_8 + 4 + param_2[2]),
                                 *(undefined4 *)(puVar1[2] + iVar3));
            if (iVar2 == 0) break;
            iVar4 = iVar4 + 1;
            iVar3 = iVar3 + 0x14;
          } while (iVar4 < (int)puVar1[1]);
        }
        if (iVar4 < (int)puVar1[1]) {
          *(undefined1 *)(puVar1[2] + 0x11 + iVar4 * 0x14) = 1;
        }
        local_4 = local_4 + 1;
        local_8 = local_8 + 0xc;
      } while (local_4 < *param_2);
    }
    if (1 < *param_2) goto LAB_007d5568;
  }
  if ((((-1 < iVar4) && (iVar4 < (int)puVar1[1])) &&
      (iVar3 = *(int *)(puVar1[2] + 8 + iVar4 * 0x14), iVar3 != 0)) &&
     (iVar3 = FUN_007d08e0(iVar3,s_INTEGER_00a00858), iVar3 == 0)) {
    puVar1[3] = iVar4;
    *(undefined1 *)(puVar1 + 8) = (undefined1)param_3;
    *(undefined1 *)((int)puVar1 + 0x21) = (undefined1)param_4;
    FUN_007ea740(param_2);
    return;
  }
LAB_007d5568:
  if (param_4 == 0) {
    FUN_007d4900(param_1,0,0,0,param_2,param_3,0,0);
    FUN_007ea740(0);
    return;
  }
  FUN_007d0820(param_1,s_AUTOINCREMENT_is_only_allowed_on_00a00820);
  FUN_007ea740(param_2);
  return;
}


// ==== FUN_007d55c0 @ 0x007d55c0 ====

void FUN_007d55c0(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  char *pcVar11;
  char *pcVar12;
  char *local_24;
  int local_18;
  uint local_14;
  undefined1 local_10 [16];
  
  uVar8 = param_4;
  uVar10 = param_3;
  piVar6 = param_1;
  if (0 < param_1[0x19]) {
    FUN_007d0820(param_1,s_parameters_are_not_allowed_in_vi_00a0088c);
    FUN_007e6af0(param_5);
    return;
  }
  FUN_007d4240(param_1,param_2,param_3,param_4,param_6,1);
  iVar3 = piVar6[0x26];
  if ((iVar3 == 0) || (piVar6[6] != 0)) {
    FUN_007e6af0(param_5);
  }
  else {
    FUN_007d2850(piVar6,uVar10,uVar8,&param_1);
    iVar7 = FUN_007ee9a0(local_10,piVar6,*(undefined1 *)(iVar3 + 0x1d),&DAT_00a00308,param_1);
    uVar10 = param_5;
    if ((iVar7 != 0) && (iVar7 = FUN_007eeb20(local_10,param_5), iVar7 != 0)) {
      FUN_007e6af0(uVar10);
      return;
    }
    uVar8 = FUN_007ead10(uVar10);
    *(undefined4 *)(iVar3 + 0x18) = uVar8;
    FUN_007e6af0(uVar10);
    if (*(char *)(*piVar6 + 0x44) == '\0') {
      FUN_007d45e0(piVar6,iVar3);
    }
    pcVar12 = (char *)piVar6[0x22];
    uVar4 = piVar6[0x23];
    if ((*pcVar12 != '\0') && (*pcVar12 != ';')) {
      pcVar12 = pcVar12 + (uVar4 >> 1);
    }
    iVar3 = *param_2;
    iVar7 = (int)pcVar12 - iVar3;
    while ((0 < iVar7 &&
           ((bVar1 = *(byte *)(iVar3 + -1 + iVar7), bVar1 == 0x3b ||
            (iVar9 = _isspace((uint)bVar1), iVar9 != 0))))) {
      iVar7 = iVar7 + -1;
    }
    local_18 = iVar3 + -1 + iVar7;
    iVar3 = *piVar6;
    local_14 = uVar4 & 1 | 2;
    param_1 = (int *)0x0;
    if (((piVar6[6] == 0) && (DAT_00b5c4c4 == 0)) &&
       (puVar5 = (undefined4 *)piVar6[0x26], puVar5 != (undefined4 *)0x0)) {
      if ((*(char *)(iVar3 + 0x44) == '\0') ||
         (puVar5[5] = *(undefined4 *)(iVar3 + 0x40), *(char *)(iVar3 + 0x44) == '\0')) {
        iVar7 = FUN_007e8190(piVar6);
        if (iVar7 == 0) {
          return;
        }
        FUN_007dc140(iVar7,0x1e,0,0);
        if (puVar5[6] == 0) {
          local_24 = s_table_009fda44;
          pcVar12 = s_TABLE_00a00310;
        }
        else {
          local_24 = &DAT_00a00308;
          pcVar12 = &DAT_00a00300;
        }
        uVar10 = FUN_007e4830(s_CREATE__s____s_00a002f0,pcVar12,(local_18 - piVar6[0x20]) + 1,
                              piVar6[0x20]);
        pcVar12 = s_sqlite_temp_master_009fff68;
        if (*(byte *)((int)puVar5 + 0x1d) != 1) {
          pcVar12 = s_sqlite_master_009fff58;
        }
        FUN_007d2210(piVar6,s_UPDATE__Q__s_SET_type___s___name_00a00298,
                     *(undefined4 *)
                      ((uint)*(byte *)((int)puVar5 + 0x1d) * 0x70 + *(int *)(iVar3 + 4)),pcVar12,
                     local_24,*puVar5,*puVar5,uVar10);
        FUN_007d05b0(uVar10);
        FUN_007d2ce0(iVar3,iVar7,*(undefined1 *)((int)puVar5 + 0x1d));
        if ((*(char *)((int)puVar5 + 0x21) != '\0') &&
           (iVar9 = (uint)*(byte *)((int)puVar5 + 0x1d) * 0x70,
           *(int *)(iVar9 + 100 + *(int *)(iVar3 + 4)) == 0)) {
          FUN_007d2210(piVar6,s_CREATE_TABLE__Q_sqlite_sequence__00a0026c,
                       *(undefined4 *)(iVar9 + *(int *)(iVar3 + 4)));
        }
        uVar10 = FUN_007e4830(s_tbl_name___q__00a0025c,*puVar5,0xffffffff);
        FUN_007dda80(iVar7,0x1c,*(undefined1 *)((int)puVar5 + 0x1d),0,uVar10);
        if (*(char *)(iVar3 + 0x44) == '\0') {
          return;
        }
      }
      if (piVar6[6] == 0) {
        pcVar12 = (char *)*puVar5;
        iVar7 = (uint)*(byte *)((int)puVar5 + 0x1d) * 0x70 + *(int *)(iVar3 + 4);
        pcVar11 = pcVar12;
        do {
          cVar2 = *pcVar11;
          pcVar11 = pcVar11 + 1;
        } while (cVar2 != '\0');
        iVar9 = FUN_007d1f20(iVar7 + 0xc,pcVar12,pcVar11 + (1 - (int)(pcVar12 + 1)),puVar5);
        if (iVar9 == 0) {
          iVar9 = puVar5[0xb];
          if (iVar9 != 0) {
            iVar7 = iVar7 + 0x48;
            do {
              pcVar12 = *(char **)(iVar9 + 8);
              pcVar11 = pcVar12;
              do {
                cVar2 = *pcVar11;
                pcVar11 = pcVar11 + 1;
              } while (cVar2 != '\0');
              uVar10 = FUN_007d1ed0(iVar7,pcVar12,pcVar11 + (1 - (int)(pcVar12 + 1)));
              *(undefined4 *)(iVar9 + 0xc) = uVar10;
              FUN_007d1f20(iVar7,*(undefined4 *)(iVar9 + 8),pcVar11 + (1 - (int)(pcVar12 + 1)),iVar9
                          );
              iVar9 = *(int *)(iVar9 + 4);
            } while (iVar9 != 0);
          }
          piVar6[0x26] = 0;
          *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + 1;
          *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 0x10;
          if (puVar5[6] == 0) {
            if (*param_1 == 0) {
              param_1 = &local_18;
            }
            puVar5[0xd] = (*param_1 - piVar6[0x20]) + 0xd;
            return;
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_007d5960 @ 0x007d5960 ====

int FUN_007d5960(char param_1)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  int unaff_EBX;
  undefined4 *unaff_EDI;
  int local_4;
  
  if (in_EAX == 0) {
    return 0xb;
  }
  uVar1 = *(ushort *)((int)unaff_EDI + 0x16) / 5 + 1;
  iVar4 = FUN_007f1420(*unaff_EDI,((in_EAX - 2U) / uVar1) * uVar1 + 2,&local_4);
  if (iVar4 == 0) {
    iVar3 = ((in_EAX - 2U) % (*(ushort *)((int)unaff_EDI + 0x16) / 5 + 1)) * 5;
    if ((param_1 != *(char *)(iVar3 + -5 + local_4)) ||
       (CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + -4 + local_4),
                                   *(undefined1 *)(iVar3 + -3 + local_4)),
                          *(undefined1 *)(iVar3 + -2 + local_4)),
                 *(undefined1 *)(iVar3 + -1 + local_4)) != unaff_EBX)) {
      iVar4 = FUN_007f10a0(local_4);
      if (iVar4 == 0) {
        *(char *)(iVar3 + -5 + local_4) = param_1;
        puVar2 = (undefined1 *)(iVar3 + -4 + local_4);
        *puVar2 = (char)((uint)unaff_EBX >> 0x18);
        puVar2[1] = (char)((uint)unaff_EBX >> 0x10);
        puVar2[2] = (char)((uint)unaff_EBX >> 8);
        puVar2[3] = (char)unaff_EBX;
      }
    }
    FUN_007f1030(local_4);
  }
  return iVar4;
}


// ==== FUN_007d5a50 @ 0x007d5a50 ====

int FUN_007d5a50(int param_1,byte *param_2)

{
  uint uVar1;
  byte *pbVar2;
  undefined4 *in_EAX;
  int iVar3;
  undefined4 *unaff_EBX;
  uint uVar4;
  
  pbVar2 = param_2;
  uVar1 = *(ushort *)((int)in_EAX + 0x16) / 5 + 1;
  uVar4 = param_1 - 2;
  iVar3 = FUN_007f1420(*in_EAX,(uVar4 / uVar1) * uVar1 + 2,&param_1);
  if (iVar3 == 0) {
    iVar3 = (uVar4 % (*(ushort *)((int)in_EAX + 0x16) / 5 + 1)) * 5;
    if (pbVar2 != (byte *)0x0) {
      *pbVar2 = *(byte *)(iVar3 + -5 + param_1);
    }
    if (unaff_EBX != (undefined4 *)0x0) {
      *unaff_EBX = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + -4 + param_1),
                                              *(undefined1 *)(iVar3 + -3 + param_1)),
                                     *(undefined1 *)(iVar3 + -2 + param_1)),
                            *(undefined1 *)(iVar3 + -1 + param_1));
    }
    FUN_007f1030(param_1);
    if ((*pbVar2 != 0) && (*pbVar2 < 6)) {
      return 0;
    }
    iVar3 = 0xb;
  }
  return iVar3;
}


// ==== FUN_007d5b10 @ 0x007d5b10 ====

int FUN_007d5b10(void)

{
  undefined1 *puVar1;
  uint in_EAX;
  int iVar2;
  int *piVar3;
  int unaff_EDI;
  
  iVar2 = *(byte *)(unaff_EDI + 2) - 1;
  if (-1 < iVar2) {
    piVar3 = (int *)(unaff_EDI + 0x18 + iVar2 * 8);
    do {
      if ((int)(uint)*(ushort *)(piVar3 + 1) <= (int)in_EAX) {
        if (*(ushort *)(piVar3 + 1) == in_EAX) {
          return *piVar3;
        }
        in_EAX = in_EAX - 1;
      }
      iVar2 = iVar2 + -1;
      piVar3 = piVar3 + -2;
    } while (-1 < iVar2);
  }
  puVar1 = (undefined1 *)
           ((uint)*(ushort *)(unaff_EDI + 0xe) + *(int *)(unaff_EDI + 0x44) + in_EAX * 2);
  return *(int *)(unaff_EDI + 0x44) + (uint)CONCAT11(*puVar1,puVar1[1]);
}


// ==== FUN_007d5b50 @ 0x007d5b50 ====

void FUN_007d5b50(uint param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  int *unaff_ESI;
  short sVar4;
  uint uVar5;
  
  uVar1 = param_1;
  *unaff_ESI = param_2;
  uVar5 = (uint)*(byte *)(param_1 + 9);
  if (*(char *)(param_1 + 7) == '\0') {
    param_1 = 0;
  }
  else {
    iVar3 = FUN_007d1120(uVar5 + param_2,&param_1);
    uVar5 = uVar5 + iVar3;
  }
  iVar3 = FUN_007d1020(uVar5 + param_2,unaff_ESI + 2);
  sVar4 = (short)(uVar5 + iVar3);
  *(short *)(unaff_ESI + 5) = sVar4;
  unaff_ESI[4] = param_1;
  if (*(char *)(uVar1 + 3) == '\0') {
    param_1 = param_1 + unaff_ESI[2];
  }
  if (*(ushort *)(uVar1 + 10) < param_1) {
    uVar2 = *(ushort *)(uVar1 + 0xc);
    iVar3 = (param_1 - uVar2) % (*(ushort *)(*(int *)(uVar1 + 0x40) + 0x16) - 4) + (uint)uVar2;
    if ((int)(uint)*(ushort *)(uVar1 + 10) < iVar3) {
      *(ushort *)((int)unaff_ESI + 0x16) = uVar2;
    }
    else {
      *(short *)((int)unaff_ESI + 0x16) = (short)iVar3;
    }
    uVar2 = *(short *)((int)unaff_ESI + 0x16) + sVar4;
    *(ushort *)(unaff_ESI + 6) = uVar2;
    iVar3 = uVar2 + 4;
  }
  else {
    *(short *)((int)unaff_ESI + 0x16) = (short)param_1;
    iVar3 = param_1 + uVar5 + iVar3;
    *(undefined2 *)(unaff_ESI + 6) = 0;
    if (iVar3 < 4) {
      *(undefined2 *)((int)unaff_ESI + 0x1a) = 4;
      return;
    }
  }
  *(short *)((int)unaff_ESI + 0x1a) = (short)iVar3;
  return;
}


// ==== FUN_007d5c20 @ 0x007d5c20 ====

undefined2 FUN_007d5c20(void)

{
  undefined2 local_6;
  
  FUN_007d5b50();
  return local_6;
}


// ==== FUN_007d5c40 @ 0x007d5c40 ====

undefined4 FUN_007d5c40(void)

{
  int in_EAX;
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  uint local_18;
  int local_14;
  uint local_10;
  ushort local_a;
  
  if (in_EAX != 0) {
    FUN_007d5b50();
    if (*(char *)(in_ECX + 3) != '\0') {
      local_18 = 0;
      local_14 = 0;
    }
    iVar2 = local_14 + (uint)CARRY4(local_10,local_18);
    if ((-1 < iVar2) && ((0 < iVar2 || ((uint)local_a < local_10 + local_18)))) {
      uVar1 = FUN_007d5960(3);
      return uVar1;
    }
  }
  return 0;
}


// ==== FUN_007d5cd0 @ 0x007d5cd0 ====

undefined4 FUN_007d5cd0(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint local_3c;
  ushort local_6;
  
  iVar5 = FUN_007d0550(*(undefined2 *)(*(int *)(param_1 + 0x40) + 0x14));
  if (iVar5 == 0) {
    return 7;
  }
  uVar3 = *(ushort *)(param_1 + 0xe);
  uVar6 = (uint)*(ushort *)(param_1 + 0x14);
  uVar9 = (uint)*(byte *)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0x44);
  uVar11 = (uint)*(ushort *)(*(int *)(param_1 + 0x40) + 0x16);
  puVar2 = (undefined1 *)(uVar9 + 5 + iVar4);
  uVar8 = (uint)CONCAT11(*(undefined1 *)(uVar9 + 5 + iVar4),puVar2[1]);
  puVar12 = (undefined4 *)(uVar8 + iVar4);
  puVar13 = (undefined4 *)(uVar8 + iVar5);
  for (uVar7 = uVar11 - uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar13 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
  }
  for (uVar8 = uVar11 - uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
    puVar12 = (undefined4 *)((int)puVar12 + 1);
    puVar13 = (undefined4 *)((int)puVar13 + 1);
  }
  if (uVar6 != 0) {
    puVar10 = (undefined1 *)(iVar4 + (uint)uVar3);
    local_3c = uVar6;
    do {
      puVar12 = (undefined4 *)((uint)CONCAT11(*puVar10,puVar10[1]) + iVar5);
      FUN_007d5b50(param_1,puVar12);
      uVar11 = uVar11 - local_6;
      puVar13 = (undefined4 *)(uVar11 + iVar4);
      for (uVar8 = (uint)(local_6 >> 2); uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar13 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar13 = puVar13 + 1;
      }
      for (uVar8 = local_6 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
        puVar12 = (undefined4 *)((int)puVar12 + 1);
        puVar13 = (undefined4 *)((int)puVar13 + 1);
      }
      *puVar10 = (char)(uVar11 >> 8);
      puVar10[1] = (char)uVar11;
      puVar10 = puVar10 + 2;
      local_3c = local_3c - 1;
    } while (local_3c != 0);
  }
  puVar2[1] = (char)uVar11;
  *puVar2 = (char)(uVar11 >> 8);
  *(undefined1 *)(uVar9 + 1 + iVar4) = 0;
  *(undefined1 *)(uVar9 + 2 + iVar4) = 0;
  *(undefined1 *)(uVar9 + 7 + iVar4) = 0;
  iVar1 = (uint)uVar3 + uVar6 * 2;
  uVar11 = uVar11 - iVar1;
  puVar12 = (undefined4 *)(iVar1 + iVar4);
  for (uVar6 = uVar11 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined1 *)puVar12 = 0;
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  FUN_007d05b0(iVar5);
  return 0;
}


// ==== FUN_007d5e30 @ 0x007d5e30 ====

uint FUN_007d5e30(int param_1,int param_2)

{
  undefined1 *puVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar6 = *(int *)(param_1 + 0x44);
  if (param_2 < 4) {
    param_2 = 4;
  }
  if (((int)(uint)*(ushort *)(param_1 + 0x12) < param_2) || (*(char *)(param_1 + 2) != '\0')) {
    return 0;
  }
  uVar8 = (uint)*(byte *)(param_1 + 8);
  *(ushort *)(param_1 + 0x12) = *(ushort *)(param_1 + 0x12) - (short)param_2;
  bVar2 = *(byte *)(uVar8 + 7 + iVar6);
  if (bVar2 < 0x3c) {
    uVar7 = uVar8 + 1;
    uVar4 = (uint)CONCAT11(*(undefined1 *)(iVar6 + 1 + uVar8),*(undefined1 *)(iVar6 + 1 + uVar7));
    if (uVar4 != 0) {
      do {
        uVar5 = uVar4;
        cVar3 = *(char *)(iVar6 + 3 + uVar5);
        uVar4 = (uint)CONCAT11(*(undefined1 *)(iVar6 + 2 + uVar5),cVar3);
        if (param_2 <= (int)uVar4) {
          if ((int)uVar4 < param_2 + 4) {
            *(undefined2 *)(iVar6 + uVar7) = *(undefined2 *)(uVar5 + iVar6);
            *(byte *)(uVar8 + 7 + iVar6) = (bVar2 - (char)param_2) + cVar3;
            return uVar5;
          }
          param_2 = uVar4 - param_2;
          *(char *)(uVar5 + 2 + iVar6) = (char)((uint)param_2 >> 8);
          *(char *)(uVar5 + 3 + iVar6) = (char)param_2;
          return uVar5 + param_2;
        }
        uVar4 = (uint)CONCAT11(*(byte *)(uVar5 + iVar6),*(undefined1 *)(uVar5 + 1 + iVar6));
        uVar7 = uVar5;
      } while (uVar4 != 0 && -1 < (int3)(uint3)*(byte *)(uVar5 + iVar6));
    }
  }
  puVar1 = (undefined1 *)(uVar8 + 5 + iVar6);
  uVar7 = (uint)CONCAT11(*(undefined1 *)(uVar8 + 5 + iVar6),puVar1[1]);
  if ((0x3b < bVar2) ||
     ((int)(uVar7 - param_2) <
      (int)((uint)*(ushort *)(param_1 + 0xe) +
           (uint)CONCAT11(*(undefined1 *)(uVar8 + 3 + iVar6),*(undefined1 *)(uVar8 + 4 + iVar6)) * 2
           ))) {
    iVar6 = FUN_007d5cd0(param_1);
    if (iVar6 != 0) {
      return 0;
    }
    uVar7 = (uint)CONCAT11(*puVar1,puVar1[1]);
  }
  uVar7 = uVar7 - param_2;
  *puVar1 = (char)(uVar7 >> 8);
  puVar1[1] = (char)uVar7;
  return uVar7;
}


// ==== FUN_007d5f80 @ 0x007d5f80 ====

void FUN_007d5f80(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  char cVar3;
  char cVar4;
  undefined1 uVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  int in_EDX;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  iVar8 = *(int *)(param_1 + 0x44);
  if (param_2 < 4) {
    param_2 = 4;
  }
  uVar11 = (uint)*(byte *)(param_1 + 8);
  uVar6 = CONCAT11(*(undefined1 *)(uVar11 + 1 + iVar8),*(undefined1 *)(uVar11 + 2 + iVar8));
  uVar12 = uVar11 + 1;
  while ((uVar7 = (uint)uVar6, (int)uVar7 < in_EDX && (uVar6 = 0, uVar7 != 0))) {
    uVar12 = uVar7;
    uVar6 = CONCAT11(*(undefined1 *)(uVar7 + iVar8),*(undefined1 *)(uVar7 + 1 + iVar8));
  }
  *(char *)(uVar12 + 1 + iVar8) = (char)in_EDX;
  *(char *)(uVar12 + iVar8) = (char)((uint)in_EDX >> 8);
  *(char *)(iVar8 + 1 + in_EDX) = (char)uVar6;
  *(char *)(iVar8 + in_EDX) = (char)(uVar6 >> 8);
  *(char *)(iVar8 + 3 + in_EDX) = (char)param_2;
  *(char *)(iVar8 + 2 + in_EDX) = (char)((uint)param_2 >> 8);
  *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + (short)param_2;
  uVar12 = *(byte *)(param_1 + 8) + 1;
  uVar7 = (uint)CONCAT11(*(undefined1 *)(uVar12 + iVar8),
                         *(undefined1 *)(*(byte *)(param_1 + 8) + 2 + iVar8));
  if (uVar7 != 0) {
    do {
      cVar3 = *(char *)(uVar7 + 1 + iVar8);
      uVar9 = (uint)CONCAT11(*(undefined1 *)(uVar7 + iVar8),cVar3);
      cVar4 = *(char *)(iVar8 + 3 + uVar7);
      if ((CONCAT11(*(undefined1 *)(iVar8 + 2 + uVar7),cVar4) + 3 + uVar7 < uVar9) || (uVar9 == 0))
      {
        uVar12 = uVar7;
      }
      else {
        *(char *)(*(byte *)(param_1 + 8) + 7 + iVar8) =
             *(char *)(*(byte *)(param_1 + 8) + 7 + iVar8) + (cVar4 - cVar3) + (char)uVar7;
        uVar5 = *(undefined1 *)(uVar9 + iVar8);
        *(undefined1 *)(uVar7 + 1 + iVar8) = *(undefined1 *)(uVar9 + 1 + iVar8);
        *(undefined1 *)(uVar7 + iVar8) = uVar5;
        iVar10 = (CONCAT11(*(undefined1 *)(iVar8 + 2 + uVar9),*(undefined1 *)(iVar8 + 3 + uVar9)) -
                 uVar7) + uVar9;
        *(char *)(iVar8 + 2 + uVar7) = (char)((uint)iVar10 >> 8);
        *(char *)(iVar8 + 3 + uVar7) = (char)iVar10;
      }
      uVar7 = (uint)CONCAT11(*(byte *)(uVar12 + iVar8),*(undefined1 *)(uVar12 + 1 + iVar8));
    } while (uVar7 != 0 && -1 < (int3)(uint3)*(byte *)(uVar12 + iVar8));
  }
  puVar1 = (undefined1 *)(uVar11 + 5 + iVar8);
  puVar2 = (undefined2 *)(uVar11 + 1 + iVar8);
  if ((*(char *)(uVar11 + 1 + iVar8) == *(char *)(uVar11 + 5 + iVar8)) &&
     (*(char *)(uVar11 + 2 + iVar8) == *(char *)(uVar11 + 6 + iVar8))) {
    uVar12 = (uint)CONCAT11(*(undefined1 *)puVar2,*(undefined1 *)((int)puVar2 + 1));
    *puVar2 = *(undefined2 *)(uVar12 + iVar8);
    iVar8 = (uint)CONCAT11(*puVar1,puVar1[1]) +
            (uint)CONCAT11(*(undefined1 *)(uVar12 + 2 + iVar8),*(undefined1 *)(uVar12 + 3 + iVar8));
    *puVar1 = (char)((uint)iVar8 >> 8);
    puVar1[1] = (char)iVar8;
  }
  return;
}


// ==== FUN_007d60f0 @ 0x007d60f0 ====

void FUN_007d60f0(uint param_1)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  undefined2 uVar3;
  
  *(bool *)(in_EAX + 3) = (param_1 & 5) != 0;
  uVar2 = param_1 >> 3;
  *(char *)(in_EAX + 9) = ((uVar2 & 1) == 0) << 2;
  iVar1 = *(int *)(in_EAX + 0x40);
  *(byte *)(in_EAX + 5) = (byte)(param_1 >> 1) & 1;
  *(byte *)(in_EAX + 4) = (byte)uVar2 & 1;
  if ((param_1 & 4) == 0) {
    *(undefined1 *)(in_EAX + 6) = 0;
    *(undefined2 *)(in_EAX + 10) = *(undefined2 *)(iVar1 + 0x18);
    uVar3 = *(undefined2 *)(iVar1 + 0x1c);
  }
  else {
    *(undefined1 *)(in_EAX + 6) = 1;
    *(undefined2 *)(in_EAX + 10) = *(undefined2 *)(iVar1 + 0x20);
    uVar3 = *(undefined2 *)(iVar1 + 0x24);
  }
  *(undefined2 *)(in_EAX + 0xc) = uVar3;
  if (((param_1 >> 1 & 1) == 0) && (((uVar2 & 1) != 0 || (*(char *)(in_EAX + 6) == '\0')))) {
    *(undefined1 *)(in_EAX + 7) = 1;
    return;
  }
  *(undefined1 *)(in_EAX + 7) = 0;
  return;
}


// ==== FUN_007d6170 @ 0x007d6170 ====

undefined4 FUN_007d6170(int param_1)

{
  byte *pbVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char *unaff_EBX;
  int iVar10;
  uint uVar11;
  
  iVar10 = *(int *)(unaff_EBX + 0x4c);
  iVar4 = *(int *)(unaff_EBX + 0x40);
  if (iVar10 == param_1) {
    if (*unaff_EBX != '\0') {
      return 0;
    }
  }
  else if ((iVar10 != 0) || (*unaff_EBX != '\0')) {
    return 0xb;
  }
  if ((iVar10 == 0) && (param_1 != 0)) {
    *(int *)(unaff_EBX + 0x4c) = param_1;
    FUN_007f02c0(*(undefined4 *)(param_1 + 0x44));
  }
  iVar5 = *(int *)(unaff_EBX + 0x44);
  uVar11 = (uint)(byte)unaff_EBX[8];
  FUN_007d60f0(*(undefined1 *)(iVar5 + uVar11));
  unaff_EBX[2] = '\0';
  unaff_EBX[1] = '\0';
  uVar9 = (uint)*(ushort *)(iVar4 + 0x16);
  iVar10 = uVar11 + (3 - (uint)(byte)unaff_EBX[4]) * 4;
  *(short *)(unaff_EBX + 0xe) = (short)iVar10;
  uVar2 = *(undefined1 *)(iVar5 + 5 + uVar11);
  uVar3 = *(undefined1 *)(iVar5 + 6 + uVar11);
  uVar6 = CONCAT11(*(undefined1 *)(iVar5 + 3 + uVar11),*(undefined1 *)(iVar5 + 4 + uVar11));
  *(ushort *)(unaff_EBX + 0x14) = uVar6;
  if (((int)(uint)uVar6 <= (int)(*(ushort *)(iVar4 + 0x14) - 8) / 3) &&
     (((uVar6 != 0 || (param_1 == 0)) || (*(int *)(param_1 + 0x48) == 1)))) {
    uVar7 = (uint)CONCAT11(*(undefined1 *)(iVar5 + 1 + uVar11),*(undefined1 *)(iVar5 + 2 + uVar11));
    iVar10 = (((uint)*(byte *)(iVar5 + 7 + uVar11) + (uint)uVar6 * -2) - iVar10) +
             (uint)CONCAT11(uVar2,uVar3);
    if (uVar7 != 0) {
      do {
        if ((int)(uVar9 - 4) < (int)uVar7) {
          return 0xb;
        }
        pbVar1 = (byte *)(uVar7 + iVar5);
        uVar11 = (uint)CONCAT11(*pbVar1,*(undefined1 *)(uVar7 + 1 + iVar5));
        uVar8 = (uint)CONCAT11(*(undefined1 *)(uVar7 + 2 + iVar5),*(undefined1 *)(uVar7 + 3 + iVar5)
                              );
        if ((uVar11 != 0) && (uVar11 <= uVar8 + 3 + uVar7)) {
          return 0xb;
        }
        iVar10 = iVar10 + uVar8;
        uVar7 = uVar11;
      } while (uVar11 != 0 && -1 < (int3)(uint3)*pbVar1);
    }
    *(short *)(unaff_EBX + 0x12) = (short)iVar10;
    if (iVar10 < (int)uVar9) {
      *unaff_EBX = '\x01';
      return 0;
    }
  }
  return 0xb;
}


// ==== FUN_007d62d0 @ 0x007d62d0 ====

void FUN_007d62d0(uint param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *unaff_ESI;
  short sVar8;
  undefined4 *puVar9;
  
  uVar5 = param_1;
  iVar4 = *(int *)(unaff_ESI + 0x40);
  bVar2 = unaff_ESI[8];
  uVar6 = (uint)*(ushort *)(iVar4 + 0x16) - (uint)bVar2;
  puVar1 = (undefined4 *)((uint)bVar2 + *(int *)(unaff_ESI + 0x44));
  puVar9 = puVar1;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined1 *)puVar9 = 0;
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  *(char *)puVar1 = (char)param_1;
  *(undefined4 *)((int)puVar1 + 1) = 0;
  *(undefined1 *)((int)puVar1 + 7) = 0;
  sVar8 = bVar2 + 8 + (~(ushort)(param_1 >> 3) & 1) * 4;
  uVar3 = *(undefined2 *)(iVar4 + 0x16);
  *(char *)((int)puVar1 + 5) = (char)((ushort)uVar3 >> 8);
  param_1._0_1_ = (undefined1)uVar3;
  *(undefined1 *)((int)puVar1 + 6) = (undefined1)param_1;
  *(short *)(unaff_ESI + 0x12) = *(short *)(iVar4 + 0x16) - sVar8;
  FUN_007d60f0(uVar5);
  *(short *)(unaff_ESI + 0xe) = sVar8;
  unaff_ESI[8] = bVar2;
  unaff_ESI[2] = 0;
  unaff_ESI[1] = 0;
  *(undefined2 *)(unaff_ESI + 0x14) = 0;
  *unaff_ESI = 1;
  return;
}


// ==== FUN_007d6370 @ 0x007d6370 ====

int FUN_007d6370(int *param_1)

{
  int iVar1;
  int in_ECX;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  iVar1 = FUN_007f1420(*unaff_EDI);
  if (iVar1 == 0) {
    iVar1 = (uint)*(ushort *)(unaff_EDI + 5) + in_ECX;
    *(int *)(iVar1 + 0x44) = in_ECX;
    *(undefined4 **)(iVar1 + 0x40) = unaff_EDI;
    *(int *)(iVar1 + 0x48) = unaff_ESI;
    *(byte *)(iVar1 + 8) = (unaff_ESI != 1) - 1U & 100;
    *param_1 = iVar1;
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_007d63b0 @ 0x007d63b0 ====

int FUN_007d63b0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  char *pcVar2;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (unaff_ESI == 0) {
    return 0xb;
  }
  iVar1 = FUN_007f1420(*unaff_EDI);
  if (iVar1 == 0) {
    pcVar2 = (char *)((uint)*(ushort *)(unaff_EDI + 5) + in_ECX);
    *(int *)(pcVar2 + 0x44) = in_ECX;
    *(undefined4 **)(pcVar2 + 0x40) = unaff_EDI;
    *(int *)(pcVar2 + 0x48) = unaff_ESI;
    pcVar2[8] = (unaff_ESI != 1) - 1U & 100;
    *param_1 = pcVar2;
    iVar1 = 0;
    if (*pcVar2 == '\0') {
      iVar1 = FUN_007d6170(param_2);
    }
  }
  return iVar1;
}


// ==== FUN_007d6410 @ 0x007d6410 ====

void FUN_007d6410(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x4c + param_2);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x4c + param_2) = 0;
    FUN_007f1030(*(undefined4 *)(iVar1 + 0x44));
  }
  *(undefined1 *)(param_1 + param_2) = 0;
  return;
}


// ==== FUN_007d6470 @ 0x007d6470 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007d6470(char *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  bool bVar7;
  undefined1 local_68 [16];
  undefined1 local_58;
  undefined1 local_57;
  byte local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  piVar3 = (int *)FUN_007d0550(0x2c);
  if (piVar3 == (int *)0x0) {
    *param_2 = 0;
    return 7;
  }
  iVar4 = FUN_007efc10(piVar3,param_1,0x50,param_3);
  iVar5 = *piVar3;
  if (iVar4 != 0) {
    if (iVar5 != 0) {
      FUN_007f0f70(iVar5);
    }
    FUN_007d05b0(piVar3);
    *param_2 = 0;
    return iVar4;
  }
  FUN_007eff70(iVar5,FUN_007d6410);
  FUN_007eff80(*piVar3,&LAB_007d6440);
  piVar3[1] = 0;
  piVar3[2] = 0;
  uVar1 = FUN_007f05e0(*piVar3);
  *(undefined1 *)((int)piVar3 + 0xe) = uVar1;
  FUN_007effb0(*piVar3,100,local_68);
  uVar2 = CONCAT11(local_58,local_57);
  *(ushort *)(piVar3 + 5) = uVar2;
  if (((uVar2 < 0x200) || (0x2000 < uVar2)) ||
     ((ushort)(CONCAT11(local_58,local_57) & CONCAT11(local_58,local_57) - 1) != 0)) {
    *(undefined2 *)(piVar3 + 5) = 0x400;
    *(undefined1 *)((int)piVar3 + 0xf) = 0x40;
    *(undefined1 *)(piVar3 + 4) = 0x20;
    *(undefined1 *)((int)piVar3 + 0x11) = 0x20;
    if (param_1 != (char *)0x0) {
      iVar5 = 9;
      bVar7 = true;
      pcVar6 = s__memory__009ffce0;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar7 = *param_1 == *pcVar6;
        param_1 = param_1 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (!bVar7) {
        *(undefined1 *)((int)piVar3 + 0x13) = 0;
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = (ushort)local_54;
    *(undefined1 *)((int)piVar3 + 0xf) = local_53;
    *(undefined1 *)(piVar3 + 4) = local_52;
    *(undefined1 *)((int)piVar3 + 0x11) = local_51;
    *(undefined1 *)((int)piVar3 + 0x12) = 1;
    *(bool *)((int)piVar3 + 0x13) =
         CONCAT31(CONCAT21(CONCAT11(local_34,local_33),local_32),local_31) != 0;
  }
  *(ushort *)((int)piVar3 + 0x16) = (short)piVar3[5] - uVar2;
  FUN_007eff90(*piVar3,(short)piVar3[5]);
  *param_2 = piVar3;
  return 0;
}


// ==== FUN_007d6620 @ 0x007d6620 ====

undefined4 FUN_007d6620(undefined4 *param_1,undefined4 param_2)

{
  param_1[10] = param_2;
  FUN_007eff60(*param_1,param_2);
  return 0;
}


// ==== FUN_007d6640 @ 0x007d6640 ====

undefined4 FUN_007d6640(undefined4 *param_1,undefined4 param_2)

{
  FUN_007efb60(*param_1,param_2);
  return 0;
}


// ==== FUN_007d6660 @ 0x007d6660 ====

undefined4 FUN_007d6660(undefined4 *param_1,undefined4 param_2)

{
  FUN_007efb80(*param_1,param_2);
  return 0;
}


// ==== FUN_007d6680 @ 0x007d6680 ====

undefined4 FUN_007d6680(undefined4 *param_1,uint param_2,int param_3)

{
  undefined2 uVar1;
  
  if (*(char *)((int)param_1 + 0x12) != '\0') {
    return 8;
  }
  if (param_3 < 0) {
    param_3 = (uint)*(ushort *)(param_1 + 5) - (uint)*(ushort *)((int)param_1 + 0x16);
  }
  if (((0x1ff < (int)param_2) && ((int)param_2 < 0x2001)) && ((param_2 & param_2 - 1) == 0)) {
    uVar1 = FUN_007eff90(*param_1,param_2);
    *(undefined2 *)(param_1 + 5) = uVar1;
  }
  *(short *)((int)param_1 + 0x16) = *(short *)(param_1 + 5) - (short)param_3;
  return 0;
}


// ==== FUN_007d66e0 @ 0x007d66e0 ====

undefined2 FUN_007d66e0(int param_1)

{
  return *(undefined2 *)(param_1 + 0x14);
}


// ==== FUN_007d66f0 @ 0x007d66f0 ====

int FUN_007d66f0(int param_1)

{
  return (uint)*(ushort *)(param_1 + 0x14) - (uint)*(ushort *)(param_1 + 0x16);
}


// ==== FUN_007d6700 @ 0x007d6700 ====

undefined4 FUN_007d6700(int param_1,int param_2)

{
  if (*(char *)(param_1 + 0x12) == '\0') {
    *(bool *)(param_1 + 0x13) = param_2 != 0;
    return 0;
  }
  return 8;
}


// ==== FUN_007d6720 @ 0x007d6720 ====

undefined1 FUN_007d6720(int param_1)

{
  return *(undefined1 *)(param_1 + 0x13);
}


// ==== FUN_007d6730 @ 0x007d6730 ====

int FUN_007d6730(undefined4 *param_1)

{
  byte bVar1;
  int *piVar2;
  ushort uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  bool bVar9;
  
  puVar4 = param_1;
  if (param_1[2] != 0) {
    return 0;
  }
  iVar5 = FUN_007f1420(*param_1,1,&param_1);
  if (iVar5 != 0) {
    return iVar5;
  }
  iVar6 = (uint)*(ushort *)(puVar4 + 5) + (int)param_1;
  *(undefined4 **)(iVar6 + 0x44) = param_1;
  *(undefined4 **)(iVar6 + 0x40) = puVar4;
  *(undefined4 *)(iVar6 + 0x48) = 1;
  *(undefined1 *)(iVar6 + 8) = 100;
  iVar5 = FUN_007f0000(*puVar4);
  if (0 < iVar5) {
    piVar2 = *(int **)(iVar6 + 0x44);
    iVar5 = 4;
    bVar9 = true;
    piVar7 = piVar2;
    piVar8 = (int *)s_SQLite_format_3_00a008b0;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar9 = *piVar7 == *piVar8;
      piVar7 = piVar7 + 1;
      piVar8 = piVar8 + 1;
    } while (bVar9);
    if ((((!bVar9) || (1 < *(byte *)((int)piVar2 + 0x12))) || (1 < *(byte *)((int)piVar2 + 0x13)))
       || (uVar3 = CONCAT11((char)piVar2[4],*(undefined1 *)((int)piVar2 + 0x11)),
          (uVar3 & uVar3 - 1) != 0)) goto LAB_007d68aa;
    *(ushort *)(puVar4 + 5) = uVar3;
    bVar1 = *(byte *)(piVar2 + 5);
    *(ushort *)((int)puVar4 + 0x16) = uVar3 - bVar1;
    if ((ushort)(uVar3 - bVar1) < 500) goto LAB_007d68aa;
    *(undefined1 *)((int)puVar4 + 0xf) = *(undefined1 *)((int)piVar2 + 0x15);
    *(undefined1 *)(puVar4 + 4) = *(undefined1 *)((int)piVar2 + 0x16);
    *(undefined1 *)((int)puVar4 + 0x11) = *(undefined1 *)((int)piVar2 + 0x17);
    *(bool *)((int)puVar4 + 0x13) =
         CONCAT31(CONCAT21(CONCAT11((char)piVar2[0xd],*(undefined1 *)((int)piVar2 + 0x35)),
                           *(undefined1 *)((int)piVar2 + 0x36)),*(undefined1 *)((int)piVar2 + 0x37))
         != 0;
  }
  puVar4[6] = (int)((*(ushort *)((int)puVar4 + 0x16) - 0xc) * (uint)*(byte *)((int)puVar4 + 0xf)) /
              0xff + -0x17;
  puVar4[7] = (int)((*(ushort *)((int)puVar4 + 0x16) - 0xc) * (uint)*(byte *)(puVar4 + 4)) / 0xff +
              -0x17;
  puVar4[8] = *(ushort *)((int)puVar4 + 0x16) - 0x23;
  puVar4[9] = (int)((*(ushort *)((int)puVar4 + 0x16) - 0xc) * (uint)*(byte *)((int)puVar4 + 0x11)) /
              0xff + -0x17;
  if (((int)puVar4[7] <= (int)puVar4[6]) && (-1 < (int)puVar4[6])) {
    puVar4[2] = iVar6;
    return 0;
  }
LAB_007d68aa:
  FUN_007f1030(*(undefined4 *)(iVar6 + 0x44));
  puVar4[2] = 0;
  return 0x1a;
}


// ==== FUN_007d68d0 @ 0x007d68d0 ====

void FUN_007d68d0(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (((*(char *)(unaff_ESI + 0xc) == '\0') && (*(int *)(unaff_ESI + 4) == 0)) &&
     (iVar1 = *(int *)(unaff_ESI + 8), iVar1 != 0)) {
    if (*(int *)(iVar1 + 0x44) == 0) {
      *(uint *)(iVar1 + 0x44) = iVar1 - (uint)*(ushort *)(unaff_ESI + 0x14);
      *(int *)(iVar1 + 0x40) = unaff_ESI;
      *(undefined4 *)(iVar1 + 0x48) = 1;
    }
    if (*(int *)(unaff_ESI + 8) != 0) {
      FUN_007f1030(*(undefined4 *)(*(int *)(unaff_ESI + 8) + 0x44));
    }
    *(undefined4 *)(unaff_ESI + 8) = 0;
    *(undefined1 *)(unaff_ESI + 0xd) = 0;
  }
  return;
}


// ==== FUN_007d6920 @ 0x007d6920 ====

int FUN_007d6920(void)

{
  undefined2 uVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *unaff_EBX;
  char *pcVar4;
  
  iVar3 = FUN_007f0000(*unaff_EBX);
  if (0 < iVar3) {
    return 0;
  }
  pcVar2 = *(char **)(unaff_EBX[2] + 0x44);
  iVar3 = FUN_007f10a0(pcVar2);
  if (iVar3 == 0) {
    *(undefined4 *)pcVar2 = s_SQLite_format_3_00a008b0._0_4_;
    *(undefined4 *)(pcVar2 + 4) = s_SQLite_format_3_00a008b0._4_4_;
    *(undefined4 *)(pcVar2 + 8) = s_SQLite_format_3_00a008b0._8_4_;
    *(undefined4 *)(pcVar2 + 0xc) = s_SQLite_format_3_00a008b0._12_4_;
    uVar1 = *(undefined2 *)(unaff_EBX + 5);
    pcVar2[0x11] = (char)uVar1;
    pcVar2[0x10] = (char)((ushort)uVar1 >> 8);
    pcVar2[0x12] = '\x01';
    pcVar2[0x13] = '\x01';
    pcVar2[0x14] = *(char *)(unaff_EBX + 5) - *(char *)((int)unaff_EBX + 0x16);
    pcVar2[0x15] = *(char *)((int)unaff_EBX + 0xf);
    pcVar2[0x16] = *(char *)(unaff_EBX + 4);
    pcVar2[0x17] = *(char *)((int)unaff_EBX + 0x11);
    pcVar4 = pcVar2 + 0x18;
    for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
      pcVar4[0] = '\0';
      pcVar4[1] = '\0';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      pcVar4 = pcVar4 + 4;
    }
    FUN_007d62d0(0xd);
    *(undefined1 *)((int)unaff_EBX + 0x12) = 1;
    if (*(char *)((int)unaff_EBX + 0x13) != '\0') {
      pcVar2[0x34] = '\0';
      pcVar2[0x35] = '\0';
      pcVar2[0x36] = '\0';
      pcVar2[0x37] = '\x01';
    }
    iVar3 = 0;
  }
  return iVar3;
}


// ==== FUN_007d69e0 @ 0x007d69e0 ====

int FUN_007d69e0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  iVar3 = 0;
  local_4 = 0;
  if ((*(char *)(param_1 + 0xc) == '\x02') ||
     ((*(char *)(param_1 + 0xc) == '\x01' && (param_2 == 0)))) {
    return 0;
  }
  if ((*(char *)(param_1 + 0xe) != '\0') && (param_2 != 0)) {
    return 8;
  }
  do {
    if (*(int *)(param_1 + 8) == 0) {
      iVar3 = FUN_007d6730(param_1);
    }
    if ((iVar3 == 0) &&
       ((param_2 == 0 ||
        ((iVar3 = FUN_007f0d40(*(undefined4 *)(*(int *)(param_1 + 8) + 0x44),1 < param_2),
         iVar3 == 0 && (iVar3 = FUN_007d6920(), iVar3 == 0)))))) {
      *(char *)(param_1 + 0xc) = (param_2 != 0) + '\x01';
      if (param_2 != 0) {
        *(undefined1 *)(param_1 + 0xd) = 0;
      }
      return 0;
    }
    if (((*(char *)(param_1 + 0xc) == '\0') && (*(int *)(param_1 + 4) == 0)) &&
       (iVar2 = *(int *)(param_1 + 8), iVar2 != 0)) {
      if (*(int *)(iVar2 + 0x44) == 0) {
        *(uint *)(iVar2 + 0x44) = iVar2 - (uint)*(ushort *)(param_1 + 0x14);
        *(int *)(iVar2 + 0x40) = param_1;
        *(undefined4 *)(iVar2 + 0x48) = 1;
      }
      if (*(int *)(param_1 + 8) != 0) {
        FUN_007f1030(*(undefined4 *)(*(int *)(param_1 + 8) + 0x44));
      }
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined1 *)(param_1 + 0xd) = 0;
    }
    if (iVar3 != 5) {
      return iVar3;
    }
    if (*(char *)(param_1 + 0xc) != '\0') {
      return 5;
    }
    puVar1 = *(undefined4 **)(param_1 + 0x28);
    if (puVar1 == (undefined4 *)0x0) {
      return 5;
    }
    if ((code *)*puVar1 == (code *)0x0) {
      return 5;
    }
    iVar2 = (*(code *)*puVar1)(puVar1[1],local_4);
    local_4 = local_4 + 1;
  } while (iVar2 != 0);
  return 5;
}


// ==== FUN_007d6b10 @ 0x007d6b10 ====

int FUN_007d6b10(void)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined1 *unaff_ESI;
  
  uVar1 = *unaff_ESI;
  FUN_007d6170(0);
  uVar2 = *(ushort *)(unaff_ESI + 0x14);
  iVar4 = 0;
  if (uVar2 != 0) {
    do {
      iVar3 = FUN_007d5c40();
      if (iVar3 != 0) {
        *unaff_ESI = uVar1;
        return iVar3;
      }
      if (unaff_ESI[4] == '\0') {
        iVar3 = FUN_007d5960(5);
        if (iVar3 != 0) {
          *unaff_ESI = uVar1;
          return iVar3;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)uVar2);
  }
  if (unaff_ESI[4] == '\0') {
    iVar4 = FUN_007d5960(5);
    *unaff_ESI = uVar1;
    return iVar4;
  }
  *unaff_ESI = uVar1;
  return 0;
}


// ==== FUN_007d6c30 @ 0x007d6c30 ====

undefined4 FUN_007d6c30(int param_1,undefined4 param_2,char param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *in_EAX;
  uint uVar3;
  uint uVar4;
  undefined1 uVar6;
  undefined1 uVar5;
  int iVar7;
  undefined1 uVar8;
  undefined1 *puVar9;
  uint uVar10;
  ushort local_8;
  
  uVar2 = (undefined1)param_2;
  uVar5 = (undefined1)((uint)param_2 >> 8);
  uVar8 = (undefined1)((uint)param_2 >> 0x10);
  uVar6 = (undefined1)((uint)param_2 >> 0x18);
  if (param_3 == '\x04') {
    puVar9 = *(undefined1 **)(in_EAX + 0x44);
    if (CONCAT31(CONCAT21(CONCAT11(*puVar9,puVar9[1]),puVar9[2]),puVar9[3]) == param_1) {
      *puVar9 = uVar6;
      puVar9[3] = uVar2;
      puVar9[1] = uVar8;
      puVar9[2] = uVar5;
      return 0;
    }
    return 0xb;
  }
  uVar1 = *in_EAX;
  FUN_007d6170(0);
  uVar3 = (uint)*(ushort *)(in_EAX + 0x14);
  uVar10 = 0;
  if (uVar3 != 0) {
    do {
      iVar7 = (uint)*(ushort *)(in_EAX + 0xe) + *(int *)(in_EAX + 0x44);
      puVar9 = (undefined1 *)
               ((uint)CONCAT11(*(undefined1 *)(iVar7 + uVar10 * 2),
                               *(undefined1 *)(iVar7 + uVar10 * 2 + 1)) + *(int *)(in_EAX + 0x44));
      if (param_3 == '\x03') {
        FUN_007d5b50();
        if ((local_8 != 0) &&
           (uVar4 = (uint)local_8,
           param_1 ==
           CONCAT31(CONCAT21(CONCAT11(puVar9[uVar4],puVar9[uVar4 + 1]),puVar9[uVar4 + 2]),
                    puVar9[uVar4 + 3]))) {
          puVar9 = puVar9 + local_8;
          *puVar9 = uVar6;
          puVar9[1] = uVar8;
          puVar9[2] = uVar5;
          puVar9[3] = uVar2;
          break;
        }
      }
      else if (CONCAT31(CONCAT21(CONCAT11(*puVar9,puVar9[1]),puVar9[2]),puVar9[3]) == param_1) {
        *puVar9 = uVar6;
        puVar9[1] = uVar8;
        puVar9[2] = uVar5;
        puVar9[3] = uVar2;
        break;
      }
      uVar10 = uVar10 + 1;
    } while ((int)uVar10 < (int)uVar3);
  }
  if (uVar10 == uVar3) {
    if (param_3 != '\x05') {
      return 0xb;
    }
    puVar9 = (undefined1 *)((byte)in_EAX[8] + 8 + *(int *)(in_EAX + 0x44));
    if (CONCAT31(CONCAT21(CONCAT11(*puVar9,puVar9[1]),
                          *(undefined1 *)((byte)in_EAX[8] + 10 + *(int *)(in_EAX + 0x44))),puVar9[3]
                ) != param_1) {
      return 0xb;
    }
    *puVar9 = uVar6;
    puVar9[1] = uVar8;
    puVar9[2] = uVar5;
    puVar9[3] = uVar2;
  }
  *in_EAX = uVar1;
  return 0;
}


// ==== FUN_007d6df0 @ 0x007d6df0 ====

int FUN_007d6df0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int in_EAX;
  int iVar2;
  char cVar3;
  int local_8;
  undefined4 local_4;
  
  local_4 = *(undefined4 *)(in_EAX + 0x48);
  iVar2 = FUN_007f1a40(*param_1,*(undefined4 *)(in_EAX + 0x44),param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  cVar3 = (char)param_2;
  *(undefined4 *)(in_EAX + 0x48) = param_4;
  if ((cVar3 == '\x05') || (cVar3 == '\x01')) {
    iVar2 = FUN_007d6b10();
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  else {
    puVar1 = *(undefined1 **)(in_EAX + 0x44);
    if ((CONCAT21(CONCAT11(*puVar1,puVar1[1]),puVar1[2]) != 0 || puVar1[3] != '\0') &&
       (iVar2 = FUN_007d5960(4), iVar2 != 0)) {
      return iVar2;
    }
  }
  iVar2 = 0;
  if (cVar3 != '\x01') {
    iVar2 = FUN_007d6370(&local_8);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = FUN_007f10a0(*(undefined4 *)(local_8 + 0x44));
    if (iVar2 != 0) {
      FUN_007f1030(*(undefined4 *)(local_8 + 0x44));
      return iVar2;
    }
    iVar2 = FUN_007d6c30(local_4,param_4,param_2);
    FUN_007f1030(*(undefined4 *)(local_8 + 0x44));
    if (iVar2 == 0) {
      iVar2 = FUN_007d5960(param_2);
    }
  }
  return iVar2;
}


// ==== FUN_007d6f20 @ 0x007d6f20 ====

undefined4 FUN_007d6f20(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 3) == '\x02') {
    uVar1 = FUN_007f1b50(*param_1);
  }
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  FUN_007d68d0();
  return uVar1;
}


// ==== FUN_007d6f50 @ 0x007d6f50 ====

undefined4 FUN_007d6f50(undefined4 *param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar2 = param_1;
  uVar4 = 0;
  if (*(char *)(param_1 + 3) == '\x02') {
    uVar4 = FUN_007f0db0(*param_1);
    iVar3 = FUN_007f1420(*puVar2,1,&param_1);
    if (iVar3 == 0) {
      uVar1 = *(ushort *)(puVar2 + 5);
      *(undefined4 **)((int)param_1 + uVar1 + 0x44) = param_1;
      *(undefined4 **)((int)param_1 + uVar1 + 0x40) = puVar2;
      *(undefined4 *)((int)param_1 + uVar1 + 0x48) = 1;
      *(undefined1 *)((int)param_1 + uVar1 + 8) = 100;
      FUN_007f1030(param_1);
    }
  }
  *(undefined1 *)(puVar2 + 3) = 0;
  *(undefined1 *)((int)puVar2 + 0xd) = 0;
  FUN_007d68d0();
  return uVar4;
}


// ==== FUN_007d6fc0 @ 0x007d6fc0 ====

int FUN_007d6fc0(undefined4 *param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 3) != '\x02') || (*(char *)((int)param_1 + 0xd) != '\0')) {
    return (-(uint)(*(char *)((int)param_1 + 0xe) != '\0') & 7) + 1;
  }
  if (*(char *)((int)param_1 + 0xe) == '\0') {
    iVar1 = FUN_007f0640(*param_1);
    *(undefined1 *)((int)param_1 + 0xd) = 1;
    return iVar1;
  }
  *(undefined1 *)((int)param_1 + 0xd) = 1;
  return 0;
}


// ==== FUN_007d7000 @ 0x007d7000 ====

void FUN_007d7000(undefined4 *param_1)

{
  if ((*(char *)((int)param_1 + 0xd) == '\0') || (*(char *)((int)param_1 + 0xe) != '\0')) {
    *(undefined1 *)((int)param_1 + 0xd) = 0;
    return;
  }
  FUN_007f0790(*param_1);
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  return;
}


// ==== FUN_007d7030 @ 0x007d7030 ====

undefined4 FUN_007d7030(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if ((*(char *)((int)param_1 + 0xd) == '\0') || (*(char *)((int)param_1 + 0xe) != '\0')) {
    return 0;
  }
  uVar1 = FUN_007f0820(*param_1);
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  return uVar1;
}


// ==== FUN_007d70a0 @ 0x007d70a0 ====

undefined4 FUN_007d70a0(int *param_1)

{
  if (param_1[2] == 0) {
    *(int *)(*param_1 + 4) = param_1[1];
  }
  else {
    *(int *)(param_1[2] + 4) = param_1[1];
  }
  if (param_1[1] != 0) {
    *(int *)(param_1[1] + 8) = param_1[2];
  }
  if (param_1[6] != 0) {
    FUN_007f1030(*(undefined4 *)(param_1[6] + 0x44));
  }
  FUN_007d68d0();
  FUN_007d05b0(param_1);
  return 0;
}


// ==== FUN_007d70f0 @ 0x007d70f0 ====

undefined4 FUN_007d70f0(int param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x41) == '\0') {
    *param_2 = 0;
    param_2[1] = 0;
    return 0;
  }
  if (*(short *)(param_1 + 0x3a) == 0) {
    iVar2 = *(int *)(param_1 + 0x18);
    puVar1 = (undefined1 *)
             ((uint)*(ushort *)(iVar2 + 0xe) + *(int *)(iVar2 + 0x44) + *(int *)(param_1 + 0x1c) * 2
             );
    FUN_007d5b50(iVar2,(uint)CONCAT11(*puVar1,puVar1[1]) + *(int *)(iVar2 + 0x44));
  }
  *param_2 = *(undefined4 *)(param_1 + 0x28);
  param_2[1] = *(undefined4 *)(param_1 + 0x2c);
  return 0;
}


// ==== FUN_007d7160 @ 0x007d7160 ====

undefined4 FUN_007d7160(int param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x41) == '\0') {
    *param_2 = 0;
    return 0;
  }
  if (*(short *)(param_1 + 0x3a) == 0) {
    iVar2 = *(int *)(param_1 + 0x18);
    puVar1 = (undefined1 *)
             ((uint)*(ushort *)(iVar2 + 0xe) + *(int *)(iVar2 + 0x44) + *(int *)(param_1 + 0x1c) * 2
             );
    FUN_007d5b50(iVar2,(uint)CONCAT11(*puVar1,puVar1[1]) + *(int *)(iVar2 + 0x44));
  }
  *param_2 = *(undefined4 *)(param_1 + 0x30);
  return 0;
}


// ==== FUN_007d71c0 @ 0x007d71c0 ====

int FUN_007d71c0(undefined1 *param_1,undefined4 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  uVar7 = (uint)param_1;
  puVar2 = (undefined4 *)*in_ECX;
  iVar3 = in_ECX[6];
  if (*(short *)((int)in_ECX + 0x3a) == 0) {
    puVar1 = (undefined1 *)((uint)*(ushort *)(iVar3 + 0xe) + *(int *)(iVar3 + 0x44) + in_ECX[7] * 2)
    ;
    FUN_007d5b50(iVar3,(uint)CONCAT11(*puVar1,puVar1[1]) + *(int *)(iVar3 + 0x44));
  }
  param_1 = (undefined1 *)((uint)*(ushort *)(in_ECX + 0xd) + in_ECX[8]);
  if (*(char *)(iVar3 + 3) == '\0') {
    iVar3 = in_ECX[10];
  }
  else {
    iVar3 = 0;
  }
  if (param_3 != 0) {
    in_EAX = in_EAX + iVar3;
  }
  if ((uint)(in_ECX[0xc] + iVar3) < in_EAX + uVar7) {
    return 1;
  }
  uVar4 = (uint)*(ushort *)((int)in_ECX + 0x36);
  if (in_EAX < (int)uVar4) {
    uVar5 = uVar7;
    if ((int)uVar4 < (int)(in_EAX + uVar7)) {
      uVar5 = uVar4 - in_EAX;
    }
    puVar9 = (undefined4 *)(param_1 + in_EAX);
    puVar10 = param_2;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    if (uVar5 == uVar7) {
      return 0;
    }
    param_2 = (undefined4 *)((int)param_2 + uVar5);
    iVar3 = 0;
    uVar7 = uVar7 - uVar5;
  }
  else {
    iVar3 = in_EAX - uVar4;
  }
  iVar8 = *(ushort *)((int)puVar2 + 0x16) - 4;
  if (0 < (int)uVar7) {
    uVar4 = (uint)*(ushort *)((int)in_ECX + 0x36);
    iVar6 = CONCAT31(CONCAT21(CONCAT11(param_1[uVar4],param_1[uVar4 + 1]),param_1[uVar4 + 2]),
                     param_1[uVar4 + 3]);
    param_3 = iVar8;
    do {
      if (iVar6 == 0) {
        if ((int)uVar7 < 1) {
          return 0;
        }
        return 0xb;
      }
      iVar6 = FUN_007f1420(*puVar2,iVar6,&param_1);
      if (iVar6 != 0) {
        return iVar6;
      }
      iVar6 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
      if (iVar3 < iVar8) {
        uVar4 = uVar7;
        if (iVar8 < (int)(iVar3 + uVar7)) {
          uVar4 = iVar8 - iVar3;
        }
        puVar9 = (undefined4 *)(param_1 + iVar3 + 4);
        puVar10 = param_2;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        iVar3 = 0;
        uVar7 = uVar7 - uVar4;
        param_2 = (undefined4 *)((int)param_2 + uVar4);
        iVar8 = param_3;
      }
      else {
        iVar3 = iVar3 - iVar8;
      }
      FUN_007f1030(param_1);
    } while (0 < (int)uVar7);
  }
  return 0;
}


// ==== FUN_007d7380 @ 0x007d7380 ====

undefined4 FUN_007d7380(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(char *)(*(int *)(param_1 + 0x18) + 3) == '\0') {
    uVar1 = FUN_007d71c0(param_3,param_4,0);
    return uVar1;
  }
  return 0xb;
}


// ==== FUN_007d73b0 @ 0x007d73b0 ====

void FUN_007d73b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_007d71c0(param_3,param_4,1);
  return;
}


// ==== FUN_007d73d0 @ 0x007d73d0 ====

int FUN_007d73d0(int param_1,uint *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if (*(short *)(param_1 + 0x3a) == 0) {
    puVar1 = (undefined1 *)
             ((uint)*(ushort *)(iVar2 + 0xe) + *(int *)(iVar2 + 0x44) + *(int *)(param_1 + 0x1c) * 2
             );
    FUN_007d5b50(iVar2,(uint)CONCAT11(*puVar1,puVar1[1]) + *(int *)(iVar2 + 0x44));
  }
  iVar3 = (uint)*(ushort *)(param_1 + 0x34) + *(int *)(param_1 + 0x20);
  if (*(char *)(iVar2 + 3) == '\0') {
    uVar4 = *(uint *)(param_1 + 0x28);
  }
  else {
    uVar4 = 0;
  }
  if (uVar4 < *(ushort *)(param_1 + 0x36)) {
    *param_2 = uVar4;
    return iVar3;
  }
  *param_2 = (uint)*(ushort *)(param_1 + 0x36);
  return iVar3;
}


// ==== FUN_007d7440 @ 0x007d7440 ====

int FUN_007d7440(int param_1,uint *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if (*(short *)(param_1 + 0x3a) == 0) {
    puVar1 = (undefined1 *)
             ((uint)*(ushort *)(iVar2 + 0xe) + *(int *)(iVar2 + 0x44) + *(int *)(param_1 + 0x1c) * 2
             );
    FUN_007d5b50(iVar2,(uint)CONCAT11(*puVar1,puVar1[1]) + *(int *)(iVar2 + 0x44));
  }
  iVar3 = (uint)*(ushort *)(param_1 + 0x34) + *(int *)(param_1 + 0x20);
  if (*(char *)(iVar2 + 3) == '\0') {
    iVar2 = *(int *)(param_1 + 0x28);
    *param_2 = (uint)*(ushort *)(param_1 + 0x36) - iVar2;
    return iVar3 + iVar2;
  }
  *param_2 = (uint)*(ushort *)(param_1 + 0x36);
  return iVar3;
}


// ==== FUN_007d74c0 @ 0x007d74c0 ====

uint FUN_007d74c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = param_1;
  uVar4 = FUN_007d63b0(&param_1,*(undefined4 *)(param_1 + 0x18));
  iVar3 = param_1;
  if (uVar4 == 0) {
    *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(iVar2 + 0x1c);
    iVar1 = *(int *)(iVar2 + 0x18);
    *(undefined1 *)(iVar1 + 1) = 0;
    FUN_007f1030(*(undefined4 *)(iVar1 + 0x44));
    *(int *)(iVar2 + 0x18) = iVar3;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    *(undefined2 *)(iVar2 + 0x3a) = 0;
    uVar4 = -(uint)(*(short *)(iVar3 + 0x14) == 0) & 0xb;
  }
  return uVar4;
}


// ==== FUN_007d7520 @ 0x007d7520 ====

int FUN_007d7520(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1;
  iVar2 = FUN_007d63b0(&param_1,0);
  if (iVar2 != 0) {
    *(undefined1 *)(iVar1 + 0x41) = 0;
    return iVar2;
  }
  if (*(int *)(iVar1 + 0x18) != 0) {
    FUN_007f1030(*(undefined4 *)(*(int *)(iVar1 + 0x18) + 0x44));
  }
  *(int *)(iVar1 + 0x18) = param_1;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined2 *)(iVar1 + 0x3a) = 0;
  iVar2 = 0;
  if ((*(short *)(param_1 + 0x14) == 0) && (*(char *)(param_1 + 4) == '\0')) {
    *(undefined1 *)(iVar1 + 0x41) = 1;
    iVar2 = FUN_007d74c0(iVar1);
  }
  *(bool *)(iVar1 + 0x41) = *(short *)(*(int *)(iVar1 + 0x18) + 0x14) != 0;
  return iVar2;
}


// ==== FUN_007d75d0 @ 0x007d75d0 ====

int FUN_007d75d0(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined1 *puVar6;
  int *unaff_ESI;
  int local_8;
  int local_4;
  
  pcVar5 = (char *)unaff_ESI[6];
  cVar1 = pcVar5[4];
  while( true ) {
    if (cVar1 != '\0') {
      return 0;
    }
    puVar6 = (undefined1 *)
             ((uint)*(ushort *)(pcVar5 + 0xe) + *(int *)(pcVar5 + 0x44) + unaff_ESI[7] * 2);
    puVar2 = (undefined4 *)*unaff_ESI;
    puVar6 = (undefined1 *)((uint)CONCAT11(*puVar6,puVar6[1]) + *(int *)(pcVar5 + 0x44));
    iVar4 = CONCAT31(CONCAT21(CONCAT11(*puVar6,puVar6[1]),puVar6[2]),puVar6[3]);
    local_4 = unaff_ESI[6];
    if (iVar4 == 0) {
      return 0xb;
    }
    iVar3 = FUN_007f1420(*puVar2,iVar4,&local_8);
    if (iVar3 != 0) {
      return iVar3;
    }
    pcVar5 = (char *)((uint)*(ushort *)(puVar2 + 5) + local_8);
    *(int *)(pcVar5 + 0x44) = local_8;
    *(undefined4 **)(pcVar5 + 0x40) = puVar2;
    *(int *)(pcVar5 + 0x48) = iVar4;
    iVar3 = 0;
    pcVar5[8] = (iVar4 != 1) - 1U & 100;
    if (*pcVar5 == '\0') {
      iVar3 = FUN_007d6170(local_4);
    }
    if (iVar3 != 0) break;
    *(short *)(pcVar5 + 0x10) = (short)unaff_ESI[7];
    iVar4 = unaff_ESI[6];
    *(undefined1 *)(iVar4 + 1) = 0;
    FUN_007f1030(*(undefined4 *)(iVar4 + 0x44));
    unaff_ESI[6] = (int)pcVar5;
    unaff_ESI[7] = 0;
    *(undefined2 *)((int)unaff_ESI + 0x3a) = 0;
    if (*(short *)(pcVar5 + 0x14) == 0) {
      return 0xb;
    }
    cVar1 = pcVar5[4];
  }
  return iVar3;
}


// ==== FUN_007d76e0 @ 0x007d76e0 ====

int FUN_007d76e0(void)

{
  undefined1 *puVar1;
  char cVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  ushort uVar7;
  undefined4 *puVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  int *unaff_ESI;
  int local_8;
  int local_4;
  
  pcVar10 = (char *)unaff_ESI[6];
  cVar2 = pcVar10[4];
  while( true ) {
    if (cVar2 != '\0') {
      uVar7 = *(ushort *)(pcVar10 + 0x14);
      *(undefined2 *)((int)unaff_ESI + 0x3a) = 0;
      unaff_ESI[7] = uVar7 - 1;
      return 0;
    }
    uVar3 = *(undefined1 *)((byte)pcVar10[8] + 10 + *(int *)(pcVar10 + 0x44));
    puVar1 = (undefined1 *)((byte)pcVar10[8] + 8 + *(int *)(pcVar10 + 0x44));
    uVar4 = *puVar1;
    puVar8 = (undefined4 *)*unaff_ESI;
    uVar5 = puVar1[1];
    uVar6 = puVar1[3];
    unaff_ESI[7] = (uint)*(ushort *)(pcVar10 + 0x14);
    iVar11 = CONCAT31(CONCAT21(CONCAT11(uVar4,uVar5),uVar3),uVar6);
    local_4 = unaff_ESI[6];
    if (iVar11 == 0) {
      return 0xb;
    }
    iVar9 = FUN_007f1420(*puVar8,iVar11,&local_8);
    if (iVar9 != 0) {
      return iVar9;
    }
    pcVar10 = (char *)((uint)*(ushort *)(puVar8 + 5) + local_8);
    *(int *)(pcVar10 + 0x44) = local_8;
    *(undefined4 **)(pcVar10 + 0x40) = puVar8;
    *(int *)(pcVar10 + 0x48) = iVar11;
    iVar9 = 0;
    pcVar10[8] = (iVar11 != 1) - 1U & 100;
    if (*pcVar10 == '\0') {
      iVar9 = FUN_007d6170(local_4);
    }
    if (iVar9 != 0) break;
    *(short *)(pcVar10 + 0x10) = (short)unaff_ESI[7];
    iVar11 = unaff_ESI[6];
    *(undefined1 *)(iVar11 + 1) = 0;
    FUN_007f1030(*(undefined4 *)(iVar11 + 0x44));
    unaff_ESI[6] = (int)pcVar10;
    unaff_ESI[7] = 0;
    *(undefined2 *)((int)unaff_ESI + 0x3a) = 0;
    if (*(short *)(pcVar10 + 0x14) == 0) {
      return 0xb;
    }
    cVar2 = pcVar10[4];
  }
  return iVar9;
}


// ==== FUN_007d7800 @ 0x007d7800 ====

int FUN_007d7800(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_007d7520(param_1);
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 0x41) == '\0') {
      *param_2 = 1;
      return 0;
    }
    *param_2 = 0;
    iVar1 = FUN_007d75d0();
  }
  return iVar1;
}


// ==== FUN_007d7840 @ 0x007d7840 ====

int FUN_007d7840(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_007d7520(param_1);
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 0x41) == '\0') {
      *param_2 = 1;
      return 0;
    }
    *param_2 = 0;
    iVar1 = FUN_007d76e0();
  }
  return iVar1;
}


// ==== FUN_007d7880 @ 0x007d7880 ====

int FUN_007d7880(int param_1,int param_2,uint param_3,int param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iStack_14;
  int iStack_c;
  int iStack_4;
  
  iVar1 = FUN_007d7520(param_1);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*(char *)(param_1 + 0x41) == '\0') {
    *param_5 = -1;
    return 0;
  }
  do {
    iVar1 = *(int *)(param_1 + 0x18);
    iVar7 = -1;
    iVar5 = *(ushort *)(iVar1 + 0x14) - 1;
    iStack_14 = 0;
    if ((*(char *)(iVar1 + 3) == '\0') && (param_2 == 0)) {
      return 0xb;
    }
    iVar6 = 0;
    iStack_c = iVar5;
    if (-1 < iVar5) {
      do {
        iVar7 = (iVar5 + iStack_14) / 2;
        *(int *)(param_1 + 0x1c) = iVar7;
        *(undefined2 *)(param_1 + 0x3a) = 0;
        if (*(char *)(param_1 + 0x41) == '\0') {
          uVar8 = 0;
          iStack_4 = 0;
        }
        else {
          iVar6 = *(int *)(param_1 + 0x18);
          puVar3 = (undefined1 *)
                   ((uint)*(ushort *)(iVar6 + 0xe) + *(int *)(iVar6 + 0x44) + iVar7 * 2);
          FUN_007d5b50(iVar6,(uint)CONCAT11(*puVar3,puVar3[1]) + *(int *)(iVar6 + 0x44));
          iStack_4 = *(int *)(param_1 + 0x2c);
          uVar8 = *(uint *)(param_1 + 0x28);
        }
        if (*(char *)(iVar1 + 3) == '\0') {
          iVar5 = *(int *)(param_1 + 0x18);
          if (*(short *)(param_1 + 0x3a) == 0) {
            puVar3 = (undefined1 *)
                     ((uint)*(ushort *)(iVar5 + 0xe) + *(int *)(iVar5 + 0x44) +
                     *(int *)(param_1 + 0x1c) * 2);
            FUN_007d5b50(iVar5,(uint)CONCAT11(*puVar3,puVar3[1]) + *(int *)(iVar5 + 0x44));
          }
          if (*(char *)(iVar5 + 3) == '\0') {
            uVar4 = *(uint *)(param_1 + 0x28);
          }
          else {
            uVar4 = 0;
          }
          uVar2 = (uint)*(ushort *)(param_1 + 0x36);
          if (uVar4 < *(ushort *)(param_1 + 0x36)) {
            uVar2 = uVar4;
          }
          if (((int)uVar2 >> 0x1f < iStack_4) ||
             (((int)uVar2 >> 0x1f <= iStack_4 && (uVar2 < uVar8)))) {
            iVar5 = FUN_007d0590(uVar8);
            if (iVar5 == 0) {
              return 7;
            }
            if (*(char *)(*(int *)(param_1 + 0x18) + 3) == '\0') {
              iVar6 = FUN_007d71c0(uVar8,iVar5,0);
            }
            else {
              iVar6 = 0xb;
            }
            iVar7 = (**(code **)(param_1 + 0xc))
                              (*(undefined4 *)(param_1 + 0x10),uVar8,iVar5,param_3,param_2);
            FUN_007d05b0(iVar5);
            if (iVar6 != 0) {
              return iVar6;
            }
          }
          else {
            iVar7 = (**(code **)(param_1 + 0xc))
                              (*(undefined4 *)(param_1 + 0x10),uVar8,
                               (uint)*(ushort *)(param_1 + 0x34) + *(int *)(param_1 + 0x20),param_3,
                               param_2);
          }
          if (iVar7 == 0) {
LAB_007d7a8d:
            if ((*(char *)(iVar1 + 6) == '\0') || (*(char *)(iVar1 + 4) != '\0')) {
              if (param_5 == (int *)0x0) {
                return 0;
              }
              *param_5 = 0;
              return 0;
            }
            iVar6 = *(int *)(param_1 + 0x1c);
            break;
          }
          if (iVar7 < 0) {
            iStack_14 = *(int *)(param_1 + 0x1c) + 1;
            iVar5 = iStack_c;
            goto LAB_007d7985;
          }
LAB_007d797b:
          iStack_c = *(int *)(param_1 + 0x1c) + -1;
          iVar5 = iStack_c;
        }
        else {
          if (param_4 < iStack_4) {
LAB_007d7976:
            iVar7 = 1;
            goto LAB_007d797b;
          }
          if ((param_4 <= iStack_4) && (param_3 <= uVar8)) {
            if ((iStack_4 < param_4) || ((iStack_4 <= param_4 && (uVar8 <= param_3)))) {
              iVar7 = 0;
              goto LAB_007d7a8d;
            }
            goto LAB_007d7976;
          }
          iVar7 = -1;
          iStack_14 = *(int *)(param_1 + 0x1c) + 1;
        }
LAB_007d7985:
        iVar6 = iStack_14;
      } while (iStack_14 <= iVar5);
    }
    if (*(char *)(iVar1 + 4) != '\0') {
LAB_007d7b5a:
      if (param_5 != (int *)0x0) {
        *param_5 = iVar7;
      }
      return 0;
    }
    if (iVar6 < (int)(uint)*(ushort *)(iVar1 + 0x14)) {
      iVar5 = (uint)*(ushort *)(iVar1 + 0xe) + *(int *)(iVar1 + 0x44);
      uVar8 = (uint)CONCAT11(*(undefined1 *)(iVar5 + iVar6 * 2),
                             *(undefined1 *)(iVar5 + iVar6 * 2 + 1));
    }
    else {
      uVar8 = *(byte *)(iVar1 + 8) + 8;
    }
    puVar3 = (undefined1 *)(uVar8 + *(int *)(iVar1 + 0x44));
    if (CONCAT31(CONCAT21(CONCAT11(*puVar3,puVar3[1]),puVar3[2]),puVar3[3]) == 0) goto LAB_007d7b5a;
    *(int *)(param_1 + 0x1c) = iVar6;
    *(undefined2 *)(param_1 + 0x3a) = 0;
    iVar1 = FUN_007d74c0(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
  } while( true );
}


// ==== FUN_007d78b1 @ 0x007d78b1 ====

int FUN_007d78b1(void)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int unaff_EDI;
  int iStack00000004;
  int iStack00000008;
  int iStack0000000c;
  int iStack00000014;
  int in_stack_00000020;
  uint in_stack_00000024;
  int in_stack_00000028;
  int *in_stack_0000002c;
  
  do {
    iVar3 = *(int *)(unaff_EDI + 0x18);
    iVar6 = -1;
    iVar5 = *(ushort *)(iVar3 + 0x14) - 1;
    iStack00000004 = 0;
    if ((*(char *)(iVar3 + 3) == '\0') && (in_stack_00000020 == 0)) {
      return 0xb;
    }
    iStack00000008 = iVar3;
    iStack0000000c = iVar5;
    if (-1 < iVar5) {
      do {
        iVar6 = (iVar5 + iStack00000004) / 2;
        *(int *)(unaff_EDI + 0x1c) = iVar6;
        *(undefined2 *)(unaff_EDI + 0x3a) = 0;
        if (*(char *)(unaff_EDI + 0x41) == '\0') {
          uVar7 = 0;
          iStack00000014 = 0;
        }
        else {
          iVar3 = *(int *)(unaff_EDI + 0x18);
          puVar2 = (undefined1 *)
                   ((uint)*(ushort *)(iVar3 + 0xe) + *(int *)(iVar3 + 0x44) + iVar6 * 2);
          FUN_007d5b50(iVar3,(uint)CONCAT11(*puVar2,puVar2[1]) + *(int *)(iVar3 + 0x44));
          iStack00000014 = *(int *)(unaff_EDI + 0x2c);
          uVar7 = *(uint *)(unaff_EDI + 0x28);
          iVar3 = iStack00000008;
        }
        if (*(char *)(iVar3 + 3) == '\0') {
          iVar3 = *(int *)(unaff_EDI + 0x18);
          if (*(short *)(unaff_EDI + 0x3a) == 0) {
            puVar2 = (undefined1 *)
                     ((uint)*(ushort *)(iVar3 + 0xe) + *(int *)(iVar3 + 0x44) +
                     *(int *)(unaff_EDI + 0x1c) * 2);
            FUN_007d5b50(iVar3,(uint)CONCAT11(*puVar2,puVar2[1]) + *(int *)(iVar3 + 0x44));
          }
          if (*(char *)(iVar3 + 3) == '\0') {
            uVar4 = *(uint *)(unaff_EDI + 0x28);
          }
          else {
            uVar4 = 0;
          }
          uVar1 = (uint)*(ushort *)(unaff_EDI + 0x36);
          if (uVar4 < *(ushort *)(unaff_EDI + 0x36)) {
            uVar1 = uVar4;
          }
          if (((int)uVar1 >> 0x1f < iStack00000014) ||
             (((int)uVar1 >> 0x1f <= iStack00000014 && (uVar1 < uVar7)))) {
            iVar3 = FUN_007d0590(uVar7);
            if (iVar3 == 0) {
              return 7;
            }
            if (*(char *)(*(int *)(unaff_EDI + 0x18) + 3) == '\0') {
              iVar5 = FUN_007d71c0(uVar7,iVar3,0);
            }
            else {
              iVar5 = 0xb;
            }
            iVar6 = (**(code **)(unaff_EDI + 0xc))
                              (*(undefined4 *)(unaff_EDI + 0x10),uVar7,iVar3,in_stack_00000024,
                               in_stack_00000020);
            FUN_007d05b0(iVar3);
            if (iVar5 != 0) {
              return iVar5;
            }
          }
          else {
            iVar6 = (**(code **)(unaff_EDI + 0xc))
                              (*(undefined4 *)(unaff_EDI + 0x10),uVar7,
                               (uint)*(ushort *)(unaff_EDI + 0x34) + *(int *)(unaff_EDI + 0x20),
                               in_stack_00000024,in_stack_00000020);
          }
          iVar3 = iStack00000008;
          if (iVar6 == 0) {
LAB_007d7a8d:
            if ((*(char *)(iVar3 + 6) == '\0') || (*(char *)(iVar3 + 4) != '\0')) {
              if (in_stack_0000002c == (int *)0x0) {
                return 0;
              }
              *in_stack_0000002c = 0;
              return 0;
            }
            iStack00000004 = *(int *)(unaff_EDI + 0x1c);
            break;
          }
          if (iVar6 < 0) {
            iStack00000004 = *(int *)(unaff_EDI + 0x1c) + 1;
            iVar5 = iStack0000000c;
            goto LAB_007d7985;
          }
LAB_007d797b:
          iStack0000000c = *(int *)(unaff_EDI + 0x1c) + -1;
          iVar5 = iStack0000000c;
        }
        else {
          if (in_stack_00000028 < iStack00000014) {
LAB_007d7976:
            iVar6 = 1;
            goto LAB_007d797b;
          }
          if ((in_stack_00000028 <= iStack00000014) && (in_stack_00000024 <= uVar7)) {
            if ((iStack00000014 < in_stack_00000028) ||
               ((iStack00000014 <= in_stack_00000028 && (uVar7 <= in_stack_00000024)))) {
              iVar6 = 0;
              goto LAB_007d7a8d;
            }
            goto LAB_007d7976;
          }
          iVar6 = -1;
          iStack00000004 = *(int *)(unaff_EDI + 0x1c) + 1;
        }
LAB_007d7985:
      } while (iStack00000004 <= iVar5);
    }
    if (*(char *)(iVar3 + 4) != '\0') {
LAB_007d7b5a:
      if (in_stack_0000002c != (int *)0x0) {
        *in_stack_0000002c = iVar6;
      }
      return 0;
    }
    if (iStack00000004 < (int)(uint)*(ushort *)(iVar3 + 0x14)) {
      iVar5 = (uint)*(ushort *)(iVar3 + 0xe) + *(int *)(iVar3 + 0x44);
      uVar7 = (uint)CONCAT11(*(undefined1 *)(iVar5 + iStack00000004 * 2),
                             *(undefined1 *)(iVar5 + iStack00000004 * 2 + 1));
    }
    else {
      uVar7 = *(byte *)(iVar3 + 8) + 8;
    }
    puVar2 = (undefined1 *)(uVar7 + *(int *)(iVar3 + 0x44));
    if (CONCAT31(CONCAT21(CONCAT11(*puVar2,puVar2[1]),puVar2[2]),puVar2[3]) == 0) goto LAB_007d7b5a;
    *(int *)(unaff_EDI + 0x1c) = iStack00000004;
    *(undefined2 *)(unaff_EDI + 0x3a) = 0;
    iVar3 = FUN_007d74c0();
    if (iVar3 != 0) {
      return iVar3;
    }
  } while( true );
}


// ==== FUN_007d7b70 @ 0x007d7b70 ====

bool FUN_007d7b70(int param_1)

{
  return *(char *)(param_1 + 0x41) == '\0';
}


// ==== FUN_007d7b80 @ 0x007d7b80 ====

int FUN_007d7b80(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if (*(char *)(param_1 + 0x41) == '\0') {
    *param_2 = 1;
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x1c) + 1;
  *(int *)(param_1 + 0x1c) = iVar3;
  *(undefined2 *)(param_1 + 0x3a) = 0;
  if (iVar3 < (int)(uint)*(ushort *)(iVar2 + 0x14)) {
    *param_2 = 0;
    if (*(char *)(iVar2 + 4) == '\0') {
      iVar2 = FUN_007d75d0();
      return iVar2;
    }
    return 0;
  }
  if (*(char *)(iVar2 + 4) == '\0') {
    iVar2 = FUN_007d74c0(param_1);
    if (iVar2 == 0) {
      iVar2 = FUN_007d75d0();
      *param_2 = 0;
      return iVar2;
    }
  }
  else {
    do {
      iVar2 = *(int *)(iVar2 + 0x4c);
      if ((iVar2 == 0) ||
         ((*(uint *)(iVar2 + 0x48) < 2 &&
          (CONCAT11(*(undefined1 *)(*(byte *)(iVar2 + 8) + 3 + *(int *)(iVar2 + 0x44)),
                    *(undefined1 *)(*(byte *)(iVar2 + 8) + 4 + *(int *)(iVar2 + 0x44))) == 0)))) {
        *param_2 = 1;
        *(undefined1 *)(param_1 + 0x41) = 0;
        return 0;
      }
      iVar3 = *(int *)(param_1 + 0x18);
      iVar2 = *(int *)(iVar3 + 0x4c);
      uVar1 = *(ushort *)(iVar3 + 0x10);
      FUN_007f02c0(*(undefined4 *)(iVar2 + 0x44));
      FUN_007f1030(*(undefined4 *)(iVar3 + 0x44));
      *(int *)(param_1 + 0x18) = iVar2;
      *(undefined2 *)(param_1 + 0x3a) = 0;
      *(uint *)(param_1 + 0x1c) = (uint)uVar1;
    } while ((uint)*(ushort *)(iVar2 + 0x14) <= (uint)uVar1);
    *param_2 = 0;
    if (*(char *)(iVar2 + 6) == '\0') {
      return 0;
    }
    iVar2 = FUN_007d7b80(param_1,param_2);
  }
  return iVar2;
}


// ==== FUN_007d7cc0 @ 0x007d7cc0 ====

int FUN_007d7cc0(int param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (*(char *)(param_1 + 0x41) == '\0') {
    *param_2 = 1;
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x18);
  if (*(char *)(iVar3 + 4) == '\0') {
    iVar2 = FUN_007d74c0(param_1);
    if (iVar2 == 0) {
      iVar3 = FUN_007d76e0();
      *param_2 = 0;
      return iVar3;
    }
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x1c);
    while (uVar4 == 0) {
      iVar3 = *(int *)(iVar3 + 0x4c);
      if ((iVar3 == 0) ||
         ((*(uint *)(iVar3 + 0x48) < 2 &&
          (puVar1 = (undefined1 *)(*(byte *)(iVar3 + 8) + 3 + *(int *)(iVar3 + 0x44)),
          CONCAT11(*puVar1,puVar1[1]) == 0)))) {
        *(undefined1 *)(param_1 + 0x41) = 0;
        *param_2 = 1;
        return 0;
      }
      iVar2 = *(int *)(param_1 + 0x18);
      iVar3 = *(int *)(iVar2 + 0x4c);
      uVar4 = (uint)*(ushort *)(iVar2 + 0x10);
      FUN_007f02c0(*(undefined4 *)(iVar3 + 0x44));
      FUN_007f1030(*(undefined4 *)(iVar2 + 0x44));
      *(int *)(param_1 + 0x18) = iVar3;
      *(undefined2 *)(param_1 + 0x3a) = 0;
      *(uint *)(param_1 + 0x1c) = uVar4;
    }
    iVar2 = 0;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
    *(undefined2 *)(param_1 + 0x3a) = 0;
    if ((*(char *)(iVar3 + 6) != '\0') && (*(char *)(iVar3 + 4) == '\0')) {
      iVar2 = FUN_007d7cc0(param_1,param_2);
    }
    *param_2 = 0;
  }
  return iVar2;
}


// ==== FUN_007d7df0 @ 0x007d7df0 ====

int FUN_007d7df0(undefined4 *param_1,int *param_2,uint *param_3,uint param_4,char param_5)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  bool local_1e;
  char local_1d;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  puVar11 = param_1;
  iVar4 = param_1[2];
  iVar3 = *(int *)(iVar4 + 0x44);
  local_c = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 0x24),*(undefined1 *)(iVar3 + 0x25)),
                              *(undefined1 *)(iVar3 + 0x26)),*(undefined1 *)(iVar3 + 0x27));
  local_14 = iVar4;
  if (local_c < 1) {
    iVar4 = FUN_007f0000(*param_1);
    *param_3 = iVar4 + 1U;
    if ((*(char *)((int)puVar11 + 0x13) != '\0') &&
       (uVar7 = *(ushort *)((int)puVar11 + 0x16) / 5 + 1,
       ((iVar4 - 1U) / uVar7) * uVar7 + 2 == iVar4 + 1U)) {
      *param_3 = iVar4 + 2;
    }
    uVar7 = *param_3;
    iVar4 = FUN_007f1420(*puVar11,uVar7,&param_1);
    piVar1 = param_2;
    if (iVar4 != 0) {
      return iVar4;
    }
    iVar4 = (uint)*(ushort *)(puVar11 + 5) + (int)param_1;
    *(undefined4 **)(iVar4 + 0x44) = param_1;
    *(uint *)(iVar4 + 0x48) = uVar7;
    *(undefined4 **)(iVar4 + 0x40) = puVar11;
    *(byte *)(iVar4 + 8) = (uVar7 != 1) - 1U & 100;
    *param_2 = iVar4;
    local_1c = FUN_007f10a0(*(undefined4 *)(iVar4 + 0x44));
    if ((local_1c != 0) && (*piVar1 != 0)) {
      FUN_007f1030(*(undefined4 *)(*piVar1 + 0x44));
    }
  }
  else {
    local_1e = false;
    if (param_5 != '\0') {
      iVar3 = FUN_007d5a50(param_4,&local_1d);
      if (iVar3 != 0) {
        return iVar3;
      }
      local_1e = local_1d == '\x02';
      *param_3 = param_4;
    }
    iVar3 = FUN_007f10a0(*(undefined4 *)(iVar4 + 0x44));
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = *(int *)(iVar4 + 0x44);
    iVar6 = local_c + -1;
    *(char *)(iVar3 + 0x24) = (char)((uint)iVar6 >> 0x18);
    *(char *)(iVar3 + 0x25) = (char)((uint)iVar6 >> 0x10);
    *(char *)(iVar3 + 0x26) = (char)((uint)iVar6 >> 8);
    *(char *)(iVar3 + 0x27) = (char)iVar6;
    iVar3 = 0;
    while( true ) {
      if (iVar3 == 0) {
        puVar5 = (undefined1 *)(*(int *)(iVar4 + 0x44) + 0x20);
      }
      else {
        puVar5 = *(undefined1 **)(iVar3 + 0x44);
      }
      uVar7 = CONCAT31(CONCAT21(CONCAT11(*puVar5,puVar5[1]),puVar5[2]),puVar5[3]);
      local_18 = iVar3;
      iVar4 = FUN_007f1420(*puVar11,uVar7,&local_8);
      if (iVar4 != 0) {
        if (iVar3 != 0) {
          FUN_007f1030(*(undefined4 *)(iVar3 + 0x44));
        }
        return iVar4;
      }
      iVar4 = (uint)*(ushort *)(puVar11 + 5) + local_8;
      *(int *)(iVar4 + 0x44) = local_8;
      *(undefined4 **)(iVar4 + 0x40) = puVar11;
      *(uint *)(iVar4 + 0x48) = uVar7;
      *(byte *)(iVar4 + 8) = (uVar7 != 1) - 1U & 100;
      local_10 = iVar4;
      local_1c = FUN_007f10a0(*(undefined4 *)(iVar4 + 0x44));
      puVar2 = param_3;
      if (local_1c != 0) {
        FUN_007f1030(*(undefined4 *)(iVar4 + 0x44));
        if (iVar3 == 0) {
          return local_1c;
        }
        FUN_007f1030(*(undefined4 *)(iVar3 + 0x44));
        return local_1c;
      }
      iVar3 = *(int *)(iVar4 + 0x44);
      local_c = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 4),*(undefined1 *)(iVar3 + 5)),
                                  *(undefined1 *)(iVar3 + 6)),*(undefined1 *)(iVar3 + 7));
      iVar6 = 0;
      if ((local_c != 0) || (local_1e)) {
        if ((int)((*(ushort *)((int)puVar11 + 0x16) >> 2) - 8) < local_c) {
          return 0xb;
        }
        if ((local_1e) && (param_4 == uVar7)) {
          *param_2 = iVar4;
          local_1e = false;
          if (local_c == 0) {
            if (local_18 == 0) {
              *(undefined4 *)(*(int *)(local_14 + 0x44) + 0x20) = **(undefined4 **)(iVar4 + 0x44);
              local_10 = 0;
            }
            else {
              **(undefined4 **)(local_18 + 0x44) = **(undefined4 **)(iVar4 + 0x44);
              local_10 = 0;
            }
          }
          else {
            iVar3 = *(int *)(iVar4 + 0x44);
            local_10 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 8),
                                                  *(undefined1 *)(iVar3 + 9)),
                                         *(undefined1 *)(iVar3 + 10)),*(undefined1 *)(iVar3 + 0xb));
            iVar6 = FUN_007d6370(&local_4);
            iVar3 = local_4;
            if (iVar6 != 0) {
              FUN_007f1030(*(undefined4 *)(iVar4 + 0x44));
              if (local_18 == 0) {
                return iVar6;
              }
              FUN_007f1030(*(undefined4 *)(local_18 + 0x44));
              return iVar6;
            }
            iVar6 = FUN_007f10a0(*(undefined4 *)(local_4 + 0x44));
            local_1c = iVar6;
            if (iVar6 != 0) {
              FUN_007f1030(*(undefined4 *)(iVar3 + 0x44));
              FUN_007f1030(*(undefined4 *)(iVar4 + 0x44));
              if (local_18 == 0) {
                return iVar6;
              }
              FUN_007f1030(*(undefined4 *)(local_18 + 0x44));
              return iVar6;
            }
            **(undefined4 **)(iVar3 + 0x44) = **(undefined4 **)(iVar4 + 0x44);
            iVar6 = *(int *)(iVar3 + 0x44);
            iVar8 = local_c + -1;
            *(char *)(iVar6 + 4) = (char)((uint)iVar8 >> 0x18);
            *(char *)(iVar6 + 5) = (char)((uint)iVar8 >> 0x10);
            *(char *)(iVar6 + 6) = (char)((uint)iVar8 >> 8);
            *(char *)(iVar6 + 7) = (char)iVar8;
            puVar11 = (undefined4 *)(*(int *)(iVar4 + 0x44) + 0xc);
            puVar12 = (undefined4 *)(*(int *)(iVar3 + 0x44) + 8);
            for (; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar12 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar12 = puVar12 + 1;
            }
            if (local_18 == 0) {
              puVar5 = (undefined1 *)(*(int *)(local_14 + 0x44) + 0x20);
            }
            else {
              puVar5 = *(undefined1 **)(local_18 + 0x44);
            }
            *puVar5 = (char)((uint)local_10 >> 0x18);
            puVar5[1] = (char)((uint)local_10 >> 0x10);
            puVar5[2] = (char)((uint)local_10 >> 8);
            puVar5[3] = (char)local_10;
            FUN_007f1030(*(undefined4 *)(iVar3 + 0x44));
            local_10 = 0;
            puVar11 = param_1;
            iVar6 = local_1c;
          }
        }
        else {
          iVar4 = 0;
          if (param_4 != 0) {
            iVar8 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 8),*(undefined1 *)(iVar3 + 9)
                                              ),*(undefined1 *)(iVar3 + 10)),
                             *(undefined1 *)(iVar3 + 0xb)) - param_4;
            if (iVar8 < 0) {
              iVar8 = -iVar8;
            }
            iVar10 = 1;
            if (1 < local_c) {
              puVar5 = (undefined1 *)(iVar3 + 0xe);
              do {
                iVar9 = CONCAT31(CONCAT21(CONCAT11(puVar5[-2],puVar5[-1]),*puVar5),puVar5[1]) -
                        param_4;
                if (iVar9 < 0) {
                  iVar9 = -iVar9;
                }
                if (iVar9 < iVar8) {
                  iVar8 = iVar9;
                  iVar4 = iVar10;
                }
                iVar10 = iVar10 + 1;
                puVar5 = puVar5 + 4;
              } while (iVar10 < local_c);
            }
            puVar11 = param_1;
          }
          uVar7 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 8 + iVar4 * 4),
                                             *(undefined1 *)(iVar3 + 9 + iVar4 * 4)),
                                    *(undefined1 *)(iVar3 + 10 + iVar4 * 4)),
                           *(undefined1 *)(iVar3 + 0xb + iVar4 * 4));
          if ((!local_1e) || (uVar7 == param_4)) {
            *param_3 = uVar7;
            uVar7 = FUN_007f0000(*puVar11);
            piVar1 = param_2;
            if (uVar7 < *puVar2) {
              return 0xb;
            }
            if (iVar4 < local_c + -1) {
              *(undefined4 *)(iVar3 + 8 + iVar4 * 4) = *(undefined4 *)(iVar3 + 4 + local_c * 4);
            }
            iVar4 = local_c + -1;
            *(char *)(iVar3 + 4) = (char)((uint)iVar4 >> 0x18);
            *(char *)(iVar3 + 5) = (char)((uint)iVar4 >> 0x10);
            *(char *)(iVar3 + 6) = (char)((uint)iVar4 >> 8);
            *(char *)(iVar3 + 7) = (char)iVar4;
            local_1c = FUN_007d6370(param_2);
            if (local_1c == 0) {
              FUN_007f0520(*(undefined4 *)(*piVar1 + 0x44));
              local_1c = FUN_007f10a0(*(undefined4 *)(*piVar1 + 0x44));
              if ((local_1c != 0) && (*piVar1 != 0)) {
                FUN_007f1030(*(undefined4 *)(*piVar1 + 0x44));
              }
            }
            local_1e = false;
            iVar6 = local_1c;
          }
        }
      }
      else {
        *param_3 = uVar7;
        *(undefined4 *)(*(int *)(local_14 + 0x44) + 0x20) = **(undefined4 **)(iVar4 + 0x44);
        *param_2 = iVar4;
        local_10 = 0;
      }
      local_1c = iVar6;
      if (local_18 != 0) {
        FUN_007f1030(*(undefined4 *)(local_18 + 0x44));
      }
      if (!local_1e) break;
      iVar3 = local_10;
      iVar4 = local_14;
    }
    if (local_10 != 0) {
      FUN_007f1030(*(undefined4 *)(local_10 + 0x44));
      return local_1c;
    }
  }
  return local_1c;
}


// ==== FUN_007d83e0 @ 0x007d83e0 ====

int FUN_007d83e0(undefined1 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  
  puVar6 = param_1;
  puVar1 = *(undefined4 **)(param_1 + 0x40);
  iVar2 = puVar1[2];
  *param_1 = 0;
  if (*(int *)(param_1 + 0x4c) != 0) {
    FUN_007f1030(*(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x44));
  }
  *(undefined4 *)(puVar6 + 0x4c) = 0;
  iVar7 = FUN_007f10a0(*(undefined4 *)(iVar2 + 0x44));
  if (iVar7 == 0) {
    iVar3 = *(int *)(iVar2 + 0x44);
    param_1 = (undefined1 *)
              CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 0x24),*(undefined1 *)(iVar3 + 0x25)
                                        ),*(undefined1 *)(iVar3 + 0x26)),
                       *(undefined1 *)(iVar3 + 0x27));
    iVar7 = (int)param_1 + 1;
    *(char *)(iVar3 + 0x24) = (char)((uint)iVar7 >> 0x18);
    *(char *)(iVar3 + 0x25) = (char)((uint)iVar7 >> 0x10);
    *(char *)(iVar3 + 0x26) = (char)((uint)iVar7 >> 8);
    *(char *)(iVar3 + 0x27) = (char)iVar7;
    if ((*(char *)((int)puVar1 + 0x13) != '\0') && (iVar7 = FUN_007d5960(2), iVar7 != 0)) {
      return iVar7;
    }
    if (param_1 == (undefined1 *)0x0) {
      iVar7 = FUN_007f10a0(*(undefined4 *)(puVar6 + 0x44));
      if (iVar7 == 0) {
        puVar1 = *(undefined4 **)(puVar6 + 0x44);
        *puVar1 = 0;
        puVar1[1] = 0;
        uVar4 = *(undefined4 *)(puVar6 + 0x48);
        iVar2 = *(int *)(iVar2 + 0x44);
        *(char *)(iVar2 + 0x20) = (char)((uint)uVar4 >> 0x18);
        *(char *)(iVar2 + 0x21) = (char)((uint)uVar4 >> 0x10);
        *(char *)(iVar2 + 0x22) = (char)((uint)uVar4 >> 8);
        *(char *)(iVar2 + 0x23) = (char)uVar4;
        return 0;
      }
    }
    else {
      iVar7 = FUN_007d6370(&param_1);
      iVar3 = (int)param_1;
      if (iVar7 == 0) {
        iVar7 = *(int *)((int)param_1 + 0x44);
        iVar8 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar7 + 4),*(undefined1 *)(iVar7 + 5)),
                                  *(undefined1 *)(iVar7 + 6)),*(undefined1 *)(iVar7 + 7));
        if (iVar8 < (int)((*(ushort *)((int)puVar1 + 0x16) >> 2) - 8)) {
          iVar7 = FUN_007f10a0(iVar7);
          if (iVar7 == 0) {
            iVar7 = *(int *)(iVar3 + 0x44);
            iVar2 = iVar8 + 1;
            *(char *)(iVar7 + 4) = (char)((uint)iVar2 >> 0x18);
            *(char *)(iVar7 + 5) = (char)((uint)iVar2 >> 0x10);
            *(char *)(iVar7 + 7) = (char)iVar2;
            *(char *)(iVar7 + 6) = (char)((uint)iVar2 >> 8);
            uVar4 = *(undefined4 *)(puVar6 + 0x48);
            puVar5 = (undefined1 *)(*(int *)(iVar3 + 0x44) + 8 + iVar8 * 4);
            *puVar5 = (char)((uint)uVar4 >> 0x18);
            puVar5[1] = (char)((uint)uVar4 >> 0x10);
            puVar5[2] = (char)((uint)uVar4 >> 8);
            puVar5[3] = (char)uVar4;
            FUN_007f04d0(*puVar1,*(undefined4 *)(puVar6 + 0x48));
            FUN_007f1030(*(undefined4 *)(iVar3 + 0x44));
            iVar7 = 0;
          }
        }
        else {
          iVar7 = FUN_007f10a0(*(undefined4 *)(puVar6 + 0x44));
          if (iVar7 == 0) {
            uVar4 = *(undefined4 *)(iVar3 + 0x48);
            puVar5 = *(undefined1 **)(puVar6 + 0x44);
            *puVar5 = (char)((uint)uVar4 >> 0x18);
            puVar5[1] = (char)((uint)uVar4 >> 0x10);
            puVar5[3] = (char)uVar4;
            puVar5[2] = (char)((uint)uVar4 >> 8);
            iVar7 = *(int *)(puVar6 + 0x44);
            *(undefined1 *)(iVar7 + 4) = 0;
            *(undefined1 *)(iVar7 + 5) = 0;
            *(undefined1 *)(iVar7 + 6) = 0;
            *(undefined1 *)(iVar7 + 7) = 0;
            uVar4 = *(undefined4 *)(puVar6 + 0x48);
            iVar2 = *(int *)(iVar2 + 0x44);
            *(char *)(iVar2 + 0x20) = (char)((uint)uVar4 >> 0x18);
            *(char *)(iVar2 + 0x21) = (char)((uint)uVar4 >> 0x10);
            *(char *)(iVar2 + 0x22) = (char)((uint)uVar4 >> 8);
            *(char *)(iVar2 + 0x23) = (char)uVar4;
            FUN_007f1030(*(undefined4 *)(iVar3 + 0x44));
            return 0;
          }
        }
      }
    }
  }
  return iVar7;
}


// ==== FUN_007d8640 @ 0x007d8640 ====

int FUN_007d8640(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  undefined1 *local_24 [7];
  ushort local_8;
  
  puVar1 = *(undefined4 **)(in_EAX + 0x40);
  FUN_007d5b50();
  if (local_8 == 0) {
    return 0;
  }
  puVar2 = (undefined1 *)((uint)local_8 + in_ECX);
  uVar5 = CONCAT31(CONCAT21(CONCAT11(*puVar2,puVar2[1]),*(undefined1 *)(local_8 + 2 + in_ECX)),
                   puVar2[3]);
  do {
    if (uVar5 == 0) {
      return 0;
    }
    uVar3 = FUN_007f0000(*puVar1);
    if (uVar3 < uVar5) {
      return 0xb;
    }
    iVar4 = FUN_007f1420(*puVar1,uVar5,local_24);
    if (iVar4 != 0) {
      return iVar4;
    }
    puVar2 = local_24[0] + *(ushort *)(puVar1 + 5);
    *(uint *)(puVar2 + 0x48) = uVar5;
    *(undefined1 **)(puVar2 + 0x44) = local_24[0];
    *(undefined4 **)(puVar2 + 0x40) = puVar1;
    puVar2[8] = (uVar5 != 1) - 1U & 100;
    uVar5 = CONCAT31(CONCAT21(CONCAT11(*local_24[0],local_24[0][1]),local_24[0][2]),local_24[0][3]);
    iVar4 = FUN_007d83e0(puVar2);
    FUN_007f1030(*(undefined4 *)(puVar2 + 0x44));
  } while (iVar4 == 0);
  return iVar4;
}


// ==== FUN_007d8730 @ 0x007d8730 ====

int FUN_007d8730(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 *param_4,
                uint param_5,uint *param_6)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint local_3c;
  int local_38;
  uint local_34;
  undefined4 *local_30;
  int local_2c;
  int local_28;
  int local_24 [6];
  ushort local_a;
  ushort local_8;
  ushort local_6;
  
  local_28 = *(int *)(in_ECX + 0x40);
  iVar7 = 0;
  local_24[0] = 0;
  local_2c = 0;
  local_38 = 0;
  if (*(char *)(in_ECX + 4) == '\0') {
    iVar7 = 4;
  }
  if (*(char *)(in_ECX + 7) == '\0') {
    param_5 = 0;
  }
  else {
    iVar2 = FUN_007d0f10(in_EAX + iVar7,param_5,(int)param_5 >> 0x1f);
    iVar7 = iVar7 + iVar2;
  }
  iVar2 = FUN_007d0f10(in_EAX + iVar7,param_2,param_3);
  FUN_007d5b50();
  local_3c = param_5;
  if (*(char *)(in_ECX + 3) == '\0') {
    local_3c = param_2 + param_5;
    local_30 = param_1;
    local_34 = param_2;
  }
  else {
    local_30 = param_4;
    local_34 = param_5;
    param_5 = 0;
  }
  puVar8 = (undefined1 *)((uint)local_8 + in_EAX);
  *param_6 = (uint)local_6;
  uVar6 = (uint)local_a;
  param_6 = (undefined4 *)(in_EAX + iVar7 + iVar2);
  if (0 < (int)local_3c) {
    do {
      iVar2 = local_28;
      iVar7 = local_38;
      if (uVar6 == 0) {
        iVar3 = FUN_007d7df0(local_28,local_24,&local_38,local_38,0);
        iVar1 = local_28;
        if ((*(char *)(iVar2 + 0x13) != '\0') && (iVar7 != 0)) {
          if (iVar3 != 0) goto LAB_007d895b;
          iVar3 = FUN_007d5960(4);
          iVar2 = iVar1;
        }
        if (iVar3 != 0) {
LAB_007d895b:
          if (local_2c != 0) {
            FUN_007f1030(*(undefined4 *)(local_2c + 0x44));
          }
          return iVar3;
        }
        *puVar8 = (char)((uint)local_38 >> 0x18);
        puVar8[3] = (char)local_38;
        puVar8[1] = (char)((uint)local_38 >> 0x10);
        puVar8[2] = (char)((uint)local_38 >> 8);
        if (local_2c != 0) {
          FUN_007f1030(*(undefined4 *)(local_2c + 0x44));
        }
        puVar8 = *(undefined1 **)(local_24[0] + 0x44);
        *puVar8 = 0;
        puVar8[1] = 0;
        puVar8[2] = 0;
        puVar8[3] = 0;
        param_6 = (uint *)(*(int *)(local_24[0] + 0x44) + 4);
        local_2c = local_24[0];
        uVar6 = *(ushort *)(iVar2 + 0x16) - 4;
      }
      uVar4 = local_3c;
      if ((int)uVar6 < (int)local_3c) {
        uVar4 = uVar6;
      }
      if ((int)local_34 < (int)uVar4) {
        uVar4 = local_34;
      }
      puVar9 = local_30;
      puVar10 = param_6;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      local_30 = (undefined4 *)((int)local_30 + uVar4);
      local_3c = local_3c - uVar4;
      local_34 = local_34 - uVar4;
      uVar6 = uVar6 - uVar4;
      if (local_34 == 0) {
        local_34 = param_5;
        local_30 = param_4;
      }
      param_6 = (undefined4 *)((int)param_6 + uVar4);
    } while (0 < (int)local_3c);
    if (local_2c != 0) {
      FUN_007f1030(*(undefined4 *)(local_2c + 0x44));
    }
  }
  return 0;
}


// ==== FUN_007d8980 @ 0x007d8980 ====

undefined4 FUN_007d8980(int param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 *in_EAX;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar2 = FUN_007f0480(*in_EAX,param_1);
  if (iVar2 != 0) {
    iVar4 = (uint)*(ushort *)(in_EAX + 5) + iVar2;
    if (*(char *)((uint)*(ushort *)(in_EAX + 5) + iVar2) != '\0') {
      iVar1 = *(int *)(iVar4 + 0x4c);
      if (iVar1 != param_2) {
        if (iVar1 != 0) {
          FUN_007f1030(*(undefined4 *)(iVar1 + 0x44));
        }
        *(int *)(iVar4 + 0x4c) = param_2;
        if (param_2 != 0) {
          FUN_007f02c0(*(undefined4 *)(param_2 + 0x44));
        }
      }
      *(undefined2 *)(iVar4 + 0x10) = param_3;
    }
    FUN_007f1030(iVar2);
  }
  if (*(char *)((int)in_EAX + 0x13) == '\0') {
    return 0;
  }
  uVar3 = FUN_007d5960(5);
  return uVar3;
}


// ==== FUN_007d8a20 @ 0x007d8a20 ====

int FUN_007d8a20(void)

{
  undefined1 *puVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  
  iVar2 = 0;
  if (*(char *)(unaff_ESI + 4) != '\0') {
    return 0;
  }
  iVar3 = 0;
  if (*(short *)(unaff_ESI + 0x14) != 0) {
    do {
      puVar1 = (undefined1 *)
               ((uint)*(ushort *)(unaff_ESI + 0xe) + *(int *)(unaff_ESI + 0x44) + iVar3 * 2);
      puVar1 = (undefined1 *)(*(int *)(unaff_ESI + 0x44) + (uint)CONCAT11(*puVar1,puVar1[1]));
      if ((*(char *)(unaff_ESI + 4) == '\0') &&
         (iVar2 = FUN_007d8980(CONCAT31(CONCAT21(CONCAT11(*puVar1,puVar1[1]),puVar1[2]),puVar1[3])),
         iVar2 != 0)) {
        return iVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(uint)*(ushort *)(unaff_ESI + 0x14));
  }
  if (*(char *)(unaff_ESI + 4) == '\0') {
    iVar2 = *(byte *)(unaff_ESI + 8) + 8 + *(int *)(unaff_ESI + 0x44);
    iVar2 = FUN_007d8980(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                     (*(byte *)(unaff_ESI + 8) + 8 +
                                                     *(int *)(unaff_ESI + 0x44)),
                                                    *(undefined1 *)(iVar2 + 1)),
                                           *(undefined1 *)(iVar2 + 2)),*(undefined1 *)(iVar2 + 3)));
    *(undefined1 *)(unaff_ESI + 1) = 0;
  }
  return iVar2;
}


// ==== FUN_007d8ae0 @ 0x007d8ae0 ====

void FUN_007d8ae0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int unaff_ESI;
  undefined1 *puVar3;
  
  iVar2 = *(int *)(unaff_ESI + 0x44);
  puVar3 = (undefined1 *)((uint)*(ushort *)(unaff_ESI + 0xe) + iVar2 + param_1 * 2);
  FUN_007d5f80();
  param_1 = param_1 + 1;
  if (param_1 < (int)(uint)*(ushort *)(unaff_ESI + 0x14)) {
    do {
      *puVar3 = puVar3[2];
      puVar3[1] = puVar3[3];
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 2;
    } while (param_1 < (int)(uint)*(ushort *)(unaff_ESI + 0x14));
  }
  *(short *)(unaff_ESI + 0x14) = *(short *)(unaff_ESI + 0x14) + -1;
  uVar1 = *(undefined2 *)(unaff_ESI + 0x14);
  puVar3 = (undefined1 *)(*(byte *)(unaff_ESI + 8) + 3 + iVar2);
  *puVar3 = (char)((ushort)uVar1 >> 8);
  puVar3[1] = (char)uVar1;
  *(short *)(unaff_ESI + 0x12) = *(short *)(unaff_ESI + 0x12) + 2;
  *(undefined1 *)(unaff_ESI + 1) = 1;
  return;
}


// ==== FUN_007d8b50 @ 0x007d8b50 ====

int FUN_007d8b50(int param_1,int param_2,byte param_3)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int in_EDX;
  undefined1 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint local_18;
  int local_14;
  uint local_10;
  ushort local_a;
  
  if ((*(char *)(param_1 + 2) == '\0') && (in_ECX + 2 <= (int)(uint)*(ushort *)(param_1 + 0x12))) {
    uVar5 = (uint)*(byte *)(param_1 + 8);
    iVar3 = *(int *)(param_1 + 0x44);
    iVar7 = *(ushort *)(param_1 + 0xe) + 2 + (uint)*(ushort *)(param_1 + 0x14) * 2;
    iVar8 = (uint)*(ushort *)(param_1 + 0xe) + in_EDX * 2;
    if (((int)((uint)CONCAT11(*(undefined1 *)(uVar5 + 5 + iVar3),*(undefined1 *)(uVar5 + 6 + iVar3))
              - in_ECX) < iVar7) && (iVar4 = FUN_007d5cd0(param_1), iVar4 != 0)) {
      return iVar4;
    }
    iVar4 = FUN_007d5e30(param_1);
    uVar11 = (uint)param_3;
    *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + -2;
    *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + 1;
    puVar10 = (undefined4 *)(uVar11 + param_2);
    puVar12 = (undefined4 *)(uVar11 + iVar4 + iVar3);
    for (uVar6 = in_ECX - uVar11 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar12 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar12 = puVar12 + 1;
    }
    for (uVar6 = in_ECX - uVar11 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    iVar7 = iVar7 + -2;
    puVar9 = (undefined1 *)(iVar3 + iVar7);
    if (iVar8 < iVar7) {
      iVar7 = ((iVar7 - iVar8) - 1U >> 1) + 1;
      do {
        *puVar9 = puVar9[-2];
        puVar9[1] = puVar9[-1];
        puVar9 = puVar9 + -2;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    *(char *)(iVar8 + 1 + iVar3) = (char)iVar4;
    *(char *)(iVar8 + iVar3) = (char)((uint)iVar4 >> 8);
    uVar2 = *(undefined2 *)(param_1 + 0x14);
    *(char *)(uVar5 + 3 + iVar3) = (char)((ushort)uVar2 >> 8);
    *(char *)(uVar5 + 4 + iVar3) = (char)uVar2;
    *(undefined1 *)(param_1 + 1) = 1;
    if (*(char *)(*(int *)(param_1 + 0x40) + 0x13) != '\0') {
      FUN_007d5b50(param_1,param_2);
      if (*(char *)(param_1 + 3) != '\0') {
        local_18 = 0;
        local_14 = 0;
      }
      iVar8 = local_14 + (uint)CARRY4(local_10,local_18);
      if ((-1 < iVar8) &&
         (((0 < iVar8 || ((uint)local_a < local_10 + local_18)) &&
          (iVar8 = FUN_007d5960(3), iVar8 != 0)))) {
        return iVar8;
      }
    }
  }
  else {
    if (in_EAX != 0) {
      uVar5 = (uint)param_3;
      puVar10 = (undefined4 *)(param_2 + uVar5);
      puVar12 = (undefined4 *)(uVar5 + in_EAX);
      for (uVar6 = in_ECX - uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
      for (uVar5 = in_ECX - uVar5 & 3; param_2 = in_EAX, uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
    }
    bVar1 = *(byte *)(param_1 + 2);
    *(byte *)(param_1 + 2) = bVar1 + 1;
    *(int *)(param_1 + 0x18 + (uint)bVar1 * 8) = param_2;
    *(short *)(param_1 + 0x1c + (uint)bVar1 * 8) = (short)in_EDX;
    *(undefined2 *)(param_1 + 0x12) = 0;
  }
  return 0;
}


// ==== FUN_007d8d30 @ 0x007d8d30 ====

void FUN_007d8d30(int param_1,int param_2,int param_3,uint *param_4)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int local_c;
  
  iVar3 = 0;
  iVar4 = 0;
  if (0 < param_2) {
    do {
      iVar3 = iVar3 + param_4[iVar4];
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_2);
  }
  uVar1 = *(ushort *)(param_1 + 0xe);
  iVar4 = *(int *)(param_1 + 0x44);
  puVar7 = (undefined1 *)(*(byte *)(param_1 + 8) + 3 + iVar4);
  *puVar7 = (char)((uint)param_2 >> 8);
  puVar7[1] = (char)param_2;
  iVar3 = FUN_007d5e30(param_1,iVar3);
  sVar2 = (short)param_2;
  *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + sVar2 * -2;
  if (param_2 < 1) {
    *(short *)(param_1 + 0x14) = sVar2;
    return;
  }
  param_3 = param_3 - (int)param_4;
  puVar7 = (undefined1 *)(iVar4 + (uint)uVar1);
  local_c = param_2;
  do {
    puVar7[1] = (char)iVar3;
    *puVar7 = (char)((uint)iVar3 >> 8);
    uVar6 = *param_4;
    puVar8 = *(undefined4 **)(param_3 + (int)param_4);
    puVar9 = (undefined4 *)(iVar4 + iVar3);
    for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    puVar7 = puVar7 + 2;
    iVar3 = iVar3 + *param_4;
    param_4 = param_4 + 1;
    local_c = local_c + -1;
  } while (local_c != 0);
  *(short *)(param_1 + 0x14) = sVar2;
  return;
}


// ==== FUN_007d8e10 @ 0x007d8e10 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007d8e10(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int in_ECX;
  undefined4 local_9c;
  int local_98;
  int local_94;
  uint local_90;
  uint local_8c;
  undefined1 local_88 [12];
  undefined4 local_7c;
  undefined4 local_78;
  ushort local_4a;
  undefined1 local_44 [64];
  undefined4 local_4;
  
  local_90 = (uint)*(ushort *)(param_1 + 0x14);
  local_4 = DAT_00b49670;
  local_94 = *(int *)(in_ECX + 0x40);
  iVar2 = FUN_007d7df0(local_94,&local_98,local_88,0,0);
  if (iVar2 == 0) {
    local_9c = *(undefined4 *)(in_ECX + 0x18);
    FUN_007d5b50();
    iVar2 = local_98;
    local_8c = (uint)local_4a;
    FUN_007d62d0(**(undefined1 **)(in_ECX + 0x44));
    FUN_007d8d30(iVar2,1,&local_9c,&local_8c);
    *(undefined1 *)(in_ECX + 2) = 0;
    *(int *)(iVar2 + 0x4c) = param_1;
    FUN_007f02c0(*(undefined4 *)(param_1 + 0x44));
    FUN_007d5b50();
    iVar2 = FUN_007d8730(0,local_7c,local_78,0,0,&local_9c);
    if ((iVar2 == 0) && (iVar2 = FUN_007d8b50(param_1,local_44,4), iVar2 == 0)) {
      uVar1 = *(undefined4 *)(in_ECX + 0x48);
      puVar3 = (undefined1 *)FUN_007d5b10();
      *puVar3 = (char)((uint)uVar1 >> 0x18);
      puVar3[3] = (char)uVar1;
      puVar3[1] = (char)((uint)uVar1 >> 0x10);
      puVar3[2] = (char)((uint)uVar1 >> 8);
      puVar3 = (undefined1 *)(*(byte *)(param_1 + 8) + 8 + *(int *)(param_1 + 0x44));
      *puVar3 = local_88[3];
      puVar3[1] = local_88[2];
      puVar3[2] = local_88[1];
      puVar3[3] = local_88[0];
      if (*(char *)(local_94 + 0x13) != '\0') {
        iVar2 = FUN_007d5960(5);
        if (iVar2 != 0) {
          return;
        }
        FUN_007d5b10();
        iVar2 = FUN_007d5c40();
        if (iVar2 != 0) {
          return;
        }
      }
      FUN_007f1030(*(undefined4 *)(local_98 + 0x44));
      FUN_007d9f90(param_1,0);
    }
  }
  return;
}


// ==== FUN_007d8fd0 @ 0x007d8fd0 ====

/* WARNING: Type propagation algorithm not settling */

int FUN_007d8fd0(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  char *pcVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  undefined4 *puVar18;
  uint uVar19;
  uint *puVar20;
  undefined4 *puVar21;
  undefined4 *puVar22;
  int local_d0;
  uint *local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  uint local_bc;
  uint local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  undefined4 *local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94 [6];
  int aiStack_7c [8];
  int local_5c [7];
  ushort local_3e;
  uint auStack_3c [9];
  undefined4 local_18;
  undefined4 local_14;
  ushort local_6;
  
  local_a8 = *(undefined4 **)(param_1 + 0x40);
  iVar5 = *(int *)(param_1 + 0x4c);
  local_d0 = 0;
  local_a0 = 0;
  local_a4 = 0;
  local_9c = 0;
  local_c8 = iVar5;
  FUN_007f10a0(*(undefined4 *)(iVar5 + 0x44));
  if (((((*(char *)(param_1 + 4) != '\0') && (*(char *)(param_1 + 3) != '\0')) &&
       (*(char *)(param_1 + 6) != '\0')) &&
      ((*(char *)(param_1 + 2) == '\x01' &&
       (*(short *)(param_1 + 0x1c) == *(short *)(param_1 + 0x14))))) &&
     ((*(int *)(*(int *)(param_1 + 0x4c) + 0x48) != 1 &&
      (puVar6 = (undefined1 *)(*(byte *)(iVar5 + 8) + 8 + *(int *)(iVar5 + 0x44)),
      CONCAT31(CONCAT21(CONCAT11(*puVar6,puVar6[1]),puVar6[2]),puVar6[3]) ==
      *(int *)(param_1 + 0x48))))) {
    iVar5 = FUN_007d8e10(iVar5);
    return iVar5;
  }
  if (*(char *)(iVar5 + 1) == '\0') {
    uVar15 = (uint)*(ushort *)(param_1 + 0x10);
  }
  else {
    local_bc = *(uint *)(param_1 + 0x48);
    uVar15 = 0;
    if (*(short *)(iVar5 + 0x14) != 0) {
      iVar17 = *(int *)(iVar5 + 0x44);
      uVar10 = (uint)*(ushort *)(iVar5 + 0xe);
      do {
        uVar19 = (uint)CONCAT11(*(undefined1 *)(uVar10 + iVar17),
                                *(undefined1 *)(uVar10 + 1 + iVar17));
        if (CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(uVar19 + iVar17),
                                       *(undefined1 *)(uVar19 + 1 + iVar17)),
                              *(undefined1 *)(uVar19 + 2 + iVar17)),
                     *(undefined1 *)(uVar19 + iVar17 + 3)) == local_bc) break;
        uVar15 = uVar15 + 1;
        uVar10 = uVar10 + 2;
      } while ((int)uVar15 < (int)(uint)*(ushort *)(iVar5 + 0x14));
    }
  }
  local_b0 = 0;
  local_c0 = 0;
  FUN_007f02c0(*(undefined4 *)(iVar5 + 0x44));
  local_b8 = uVar15 - 1;
  if ((int)(uint)*(ushort *)(iVar5 + 0x14) < (int)(uVar15 + 2)) {
    local_b8 = *(ushort *)(iVar5 + 0x14) - 2;
  }
  if ((int)local_b8 < 0) {
    local_b8 = 0;
  }
  local_c4 = local_b8 * 2;
  iVar17 = 0;
  uVar15 = local_b8;
  do {
    if ((int)uVar15 < (int)(uint)*(ushort *)(iVar5 + 0x14)) {
      iVar7 = *(int *)(iVar5 + 0x44);
      puVar6 = (undefined1 *)((uint)*(ushort *)(iVar5 + 0xe) + local_c4 + iVar7);
      uVar1 = *puVar6;
      *(uint *)((int)local_94 + iVar17 + 4) = uVar15;
      puVar6 = (undefined1 *)((uint)CONCAT11(uVar1,puVar6[1]) + iVar7);
      uVar9 = CONCAT11(*puVar6,puVar6[1]);
      *(undefined1 **)((int)aiStack_7c + iVar17 + 0xc) = puVar6;
    }
    else {
      if (uVar15 != *(ushort *)(iVar5 + 0x14)) break;
      puVar6 = (undefined1 *)(*(byte *)(iVar5 + 8) + 8 + *(int *)(iVar5 + 0x44));
      uVar9 = CONCAT11(*puVar6,puVar6[1]);
    }
    iVar5 = CONCAT31(CONCAT21(uVar9,puVar6[2]),puVar6[3]);
    *(int *)((int)auStack_3c + iVar17 + 0x10) = iVar5;
    if (iVar5 == 0) {
      iVar7 = 0xb;
      goto LAB_007d9b38;
    }
    iVar7 = FUN_007f1420(*local_a8,iVar5,&local_bc);
    if (iVar7 == 0) {
      pcVar14 = (char *)(*(ushort *)(local_a8 + 5) + local_bc);
      *(undefined4 **)(pcVar14 + 0x40) = local_a8;
      *(uint *)(pcVar14 + 0x44) = local_bc;
      *(int *)(pcVar14 + 0x48) = iVar5;
      iVar7 = 0;
      *(char **)((int)aiStack_7c + iVar17) = pcVar14;
      pcVar14[8] = (iVar5 != 1) - 1U & 100;
      if (*pcVar14 == '\0') {
        iVar7 = FUN_007d6170(local_c8);
      }
    }
    if (iVar7 != 0) goto LAB_007d9b38;
    iVar5 = *(int *)((int)aiStack_7c + iVar17);
    *(short *)(iVar5 + 0x10) = (short)uVar15;
    bVar2 = *(byte *)(iVar5 + 2);
    local_c0 = local_c0 + 1;
    *(undefined4 *)((int)auStack_3c + iVar17 + 4) = 0;
    local_c4 = local_c4 + 2;
    iVar17 = iVar17 + 4;
    local_d0 = (uint)bVar2 + local_d0 + 1 + (uint)*(ushort *)(iVar5 + 0x14);
    uVar15 = uVar15 + 1;
    if (0xb < iVar17) break;
    iVar5 = local_c8;
  } while( true );
  puVar21 = local_a8;
  uVar15 = local_d0 + 1U & 0xfffffffe;
  local_a4 = FUN_007d0590((-(uint)(*(char *)((int)local_a8 + 0x13) != '\0') & uVar15) + 0xf0 +
                          (*(ushort *)(local_a8 + 5) + uVar15) * 8);
  if (local_a4 == 0) {
    iVar7 = 7;
  }
  else {
    local_ac = local_a4 + uVar15 * 4;
    local_94[1] = local_ac + uVar15 * 4;
    uVar15 = (uint)*(ushort *)(puVar21 + 5);
    local_94[2] = uVar15 + 0x50 + local_94[1];
    local_94[3] = uVar15 + 0x50 + local_94[2];
    local_98 = uVar15 + 0x50 + local_94[3];
    if (*(char *)((int)puVar21 + 0x13) != '\0') {
      local_9c = local_98 + uVar15 * 5;
    }
    iVar5 = 0;
    if (0 < local_c0) {
      do {
        iVar17 = aiStack_7c[iVar5];
        uVar15 = local_94[iVar5 + 1] + (uint)*(ushort *)(puVar21 + 5);
        puVar22 = (undefined4 *)(uVar15 - *(ushort *)(puVar21 + 5));
        *(undefined4 **)(uVar15 + 0x44) = puVar22;
        uVar3 = *(ushort *)(puVar21 + 5);
        puVar18 = *(undefined4 **)(iVar17 + 0x44);
        for (uVar10 = uVar3 + 0x50 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar22 = *puVar18;
          puVar18 = puVar18 + 1;
          puVar22 = puVar22 + 1;
        }
        for (uVar10 = uVar3 + 0x50 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined1 *)puVar22 = *(undefined1 *)puVar18;
          puVar18 = (undefined4 *)((int)puVar18 + 1);
          puVar22 = (undefined4 *)((int)puVar22 + 1);
        }
        uVar3 = *(ushort *)(puVar21 + 5);
        auStack_3c[iVar5 + 1] = uVar15;
        iVar5 = iVar5 + 1;
        *(uint *)(uVar15 + 0x44) = uVar15 - uVar3;
      } while (iVar5 < local_c0);
    }
    local_b4 = 0;
    local_94[0] = (uint)*(byte *)(param_1 + 4) << 2;
    if ((*(char *)(param_1 + 6) == '\0') || (local_c4 = 1, *(byte *)(param_1 + 4) == 0)) {
      local_c4 = 0;
    }
    local_d0 = 0;
    if (0 < local_c0) {
      do {
        uVar15 = auStack_3c[local_d0 + 1];
        local_cc = (uint *)((uint)*(ushort *)(uVar15 + 0x14) + (uint)*(byte *)(uVar15 + 2));
        uVar10 = 0;
        if (local_cc != (uint *)0x0) {
          piVar13 = (int *)(local_a4 + local_b4 * 4);
          local_bc = local_ac - local_a4;
          do {
            iVar5 = *(byte *)(uVar15 + 2) - 1;
            uVar19 = uVar10;
            if (-1 < iVar5) {
              piVar11 = (int *)(uVar15 + 0x18 + iVar5 * 8);
              do {
                if ((int)(uint)*(ushort *)(piVar11 + 1) <= (int)uVar19) {
                  if (*(ushort *)(piVar11 + 1) == uVar19) {
                    iVar5 = *piVar11;
                    goto LAB_007d93ba;
                  }
                  uVar19 = uVar19 - 1;
                }
                iVar5 = iVar5 + -1;
                piVar11 = piVar11 + -2;
              } while (-1 < iVar5);
            }
            iVar5 = (uint)*(ushort *)(uVar15 + 0xe) + *(int *)(uVar15 + 0x44);
            iVar5 = *(int *)(uVar15 + 0x44) +
                    (uint)CONCAT11(*(undefined1 *)(iVar5 + uVar19 * 2),
                                   *(undefined1 *)(iVar5 + uVar19 * 2 + 1));
LAB_007d93ba:
            *piVar13 = iVar5;
            FUN_007d5b50(uVar15,iVar5);
            *(uint *)(local_bc + (int)piVar13) = (uint)local_6;
            if (*(char *)((int)local_a8 + 0x13) != '\0') {
              *(undefined1 *)(local_9c + local_b4) = (undefined1)local_d0;
              iVar5 = 0;
              if (*(byte *)(uVar15 + 2) != 0) {
                piVar11 = (int *)(uVar15 + 0x18);
                do {
                  if (*piVar11 == *piVar13) {
                    *(undefined1 *)(local_9c + local_b4) = 0xff;
                    break;
                  }
                  iVar5 = iVar5 + 1;
                  piVar11 = piVar11 + 2;
                } while (iVar5 < (int)(uint)*(byte *)(uVar15 + 2));
              }
            }
            local_b4 = local_b4 + 1;
            piVar13 = piVar13 + 1;
            uVar10 = uVar10 + 1;
          } while ((int)uVar10 < (int)local_cc);
        }
        if (local_d0 < local_c0 + -1) {
          puVar21 = (undefined4 *)aiStack_7c[local_d0 + 3];
          FUN_007d5b50(local_c8,puVar21);
          iVar17 = local_94[0];
          iVar5 = local_b4;
          uVar10 = (uint)local_3e;
          if (local_c4 == 0) {
            *(uint *)(local_ac + local_b4 * 4) = uVar10;
            puVar22 = (undefined4 *)(local_98 + local_a0);
            local_a0 = local_a0 + uVar10;
            puVar18 = puVar22;
            for (uVar19 = (uint)(local_3e >> 2); uVar19 != 0; uVar19 = uVar19 - 1) {
              *puVar18 = *puVar21;
              puVar21 = puVar21 + 1;
              puVar18 = puVar18 + 1;
            }
            for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
              *(undefined1 *)puVar18 = *(undefined1 *)puVar21;
              puVar21 = (undefined4 *)((int)puVar21 + 1);
              puVar18 = (undefined4 *)((int)puVar18 + 1);
            }
            *(undefined1 **)(local_a4 + local_b4 * 4) = (undefined1 *)((int)puVar22 + local_94[0]);
            if (*(char *)((int)local_a8 + 0x13) != '\0') {
              *(undefined1 *)(local_9c + local_b4) = 0xff;
            }
            FUN_007d8ae0(local_b8);
            piVar13 = (int *)(local_ac + iVar5 * 4);
            *piVar13 = *piVar13 - iVar17;
            if (*(char *)(uVar15 + 4) == '\0') {
              **(undefined4 **)(local_a4 + iVar5 * 4) =
                   *(undefined4 *)(*(byte *)(uVar15 + 8) + 8 + *(int *)(uVar15 + 0x44));
            }
            local_b4 = iVar5 + 1;
          }
          else {
            FUN_007d8ae0(local_b8);
          }
        }
        local_d0 = local_d0 + 1;
      } while (local_d0 < local_c0);
    }
    uVar3 = *(ushort *)((int)local_a8 + 0x16);
    iVar17 = 0;
    iVar16 = 0;
    iVar5 = 0;
    if (0 < local_b4) {
      do {
        iVar7 = *(int *)(local_ac + iVar17 * 4);
        iVar5 = iVar5 + 2 + iVar7;
        if ((int)((uVar3 - 0xc) + local_94[0]) < iVar5) {
          *(int *)((int)local_5c + iVar16 * 4 + 4U) = iVar5 - iVar7;
          aiStack_7c[iVar16 + 3] = iVar17;
          if (local_c4 != 0) {
            iVar17 = iVar17 + -1;
          }
          iVar5 = 0;
          iVar16 = iVar16 + 1;
        }
        iVar17 = iVar17 + 1;
      } while (iVar17 < local_b4);
    }
    iVar17 = iVar16 + 1;
    local_5c[iVar17] = iVar5;
    aiStack_7c[iVar16 + 3] = local_b4;
    for (iVar5 = iVar16; 0 < iVar5; iVar5 = iVar5 + -1) {
      uVar15 = *(uint *)((int)local_5c + iVar5 * 4 + 4U);
      iVar7 = local_5c[iVar5];
      while( true ) {
        iVar8 = aiStack_7c[iVar5 + 2] + -1;
        iVar12 = (iVar8 - local_c4) + 1;
        if ((uVar15 != 0) &&
           ((iVar7 - *(int *)(local_ac + iVar8 * 4)) + -2 <
            (int)(*(int *)(local_ac + iVar12 * 4) + 2 + uVar15))) break;
        uVar15 = uVar15 + 2 + *(int *)(local_ac + iVar12 * 4);
        iVar7 = iVar7 + (-2 - *(int *)(local_ac + iVar8 * 4));
        aiStack_7c[iVar5 + 2] = aiStack_7c[iVar5 + 2] + -1;
      }
      *(uint *)((int)local_5c + iVar5 * 4 + 4U) = uVar15;
      local_5c[iVar5] = iVar7;
    }
    local_bc = (uint)**(byte **)(param_1 + 0x44);
    iVar5 = 0;
    if (0 < iVar17) {
      do {
        if (iVar5 < local_c0) {
          local_cc = (uint *)aiStack_7c[iVar5];
          uVar15 = local_cc[0x11];
          uVar10 = auStack_3c[iVar5 + 4];
          local_94[iVar5 + 1] = (int)local_cc;
          *(uint *)((int)local_5c + iVar5 * 4 + 4U) = uVar10;
          aiStack_7c[iVar5] = 0;
          iVar7 = FUN_007f10a0(uVar15);
          if (iVar7 != 0) goto LAB_007d9b38;
        }
        else {
          iVar7 = FUN_007d7df0(local_a8,&local_cc,(uint *)((int)local_5c + iVar5 * 4 + 4U),
                               local_5c[iVar5],0);
          if (iVar7 != 0) goto LAB_007d9b38;
          local_94[iVar5 + 1] = (int)local_cc;
        }
        local_b0 = local_b0 + 1;
        FUN_007d62d0(local_bc);
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar17);
    }
    if (iVar5 < local_c0) {
      do {
        iVar8 = aiStack_7c[iVar5];
        iVar7 = FUN_007d83e0(iVar8);
        if (iVar7 != 0) goto LAB_007d9b38;
        if (iVar8 != 0) {
          FUN_007f1030(*(undefined4 *)(iVar8 + 0x44));
        }
        aiStack_7c[iVar5] = 0;
        iVar5 = iVar5 + 1;
      } while (iVar5 < local_c0);
    }
    iVar5 = 0;
    if (0 < iVar16) {
      do {
        local_cc = (uint *)((int)local_5c + iVar5 * 4 + 4U);
        uVar15 = *local_cc;
        local_5c[0] = iVar5 + 1;
        iVar7 = local_5c[0];
        iVar8 = local_5c[0];
        iVar12 = iVar5;
        uVar10 = uVar15;
        if (local_5c[0] < iVar17) {
          do {
            uVar19 = *(uint *)((int)local_5c + iVar8 * 4 + 4U);
            if (uVar19 < uVar10) {
              iVar12 = iVar8;
              uVar10 = uVar19;
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar17);
          if (iVar5 < iVar12) {
            iVar8 = local_94[iVar5 + 1];
            *local_cc = *(uint *)((int)local_5c + iVar12 * 4 + 4U);
            local_94[iVar5 + 1] = local_94[iVar12 + 1];
            *(uint *)((int)local_5c + iVar12 * 4 + 4U) = uVar15;
            local_94[iVar12 + 1] = iVar8;
          }
        }
        iVar5 = iVar7;
      } while (iVar5 < iVar16);
    }
    iVar5 = 0;
    local_d0 = 0;
    if (0 < local_b0) {
      do {
        iVar17 = aiStack_7c[local_d0 + 3];
        iVar16 = local_94[local_d0 + 1];
        FUN_007d8d30(iVar16,iVar17 - iVar5,local_a4 + iVar5 * 4,local_ac + iVar5 * 4);
        if ((*(char *)((int)local_a8 + 0x13) != '\0') && (iVar5 < iVar17)) {
          local_cc = (uint *)0x0;
          do {
            if ((*(byte *)(local_9c + iVar5) == 0xff) ||
               (*(int *)(auStack_3c[*(byte *)(local_9c + iVar5) + 1] + 0x48) !=
                *(int *)(iVar16 + 0x48))) {
              iVar17 = *(byte *)(iVar16 + 2) - 1;
              if (-1 < iVar17) {
                iVar7 = iVar16 + 0x18 + iVar17 * 8;
                puVar20 = local_cc;
                do {
                  if ((int)(uint)*(ushort *)(iVar7 + 4) <= (int)puVar20) {
                    if ((uint *)(uint)*(ushort *)(iVar7 + 4) == puVar20) break;
                    puVar20 = (uint *)((int)puVar20 + -1);
                  }
                  iVar17 = iVar17 + -1;
                  iVar7 = iVar7 + -8;
                } while (-1 < iVar17);
              }
              iVar7 = FUN_007d5c40();
              if (iVar7 != 0) goto LAB_007d9b38;
            }
            iVar5 = iVar5 + 1;
            local_cc = (uint *)((int)local_cc + 1);
          } while (iVar5 < aiStack_7c[local_d0 + 3]);
        }
        iVar5 = aiStack_7c[local_d0 + 3];
        if ((local_d0 < local_b0 + -1) && (iVar5 < local_b4)) {
          puVar21 = *(undefined4 **)(local_a4 + iVar5 * 4);
          local_cc = (uint *)(*(int *)(local_ac + iVar5 * 4) + local_94[0]);
          if (*(char *)(iVar16 + 4) == '\0') {
            *(undefined4 *)(*(int *)(iVar16 + 0x44) + 8) = *puVar21;
          }
          else if (local_c4 == 0) {
            puVar21 = puVar21 + -1;
            local_a0 = local_a0 + (int)local_cc;
          }
          else {
            iVar17 = iVar5 * 4;
            iVar5 = iVar5 + -1;
            FUN_007d5b50(iVar16,*(undefined4 *)(local_a4 + -4 + iVar17));
            iVar17 = local_a0;
            puVar21 = (undefined4 *)(local_98 + local_a0);
            FUN_007d8730(0,local_18,local_14,0,0,&local_cc);
            local_a0 = iVar17 + (int)local_cc;
          }
          iVar7 = FUN_007d8b50(local_c8,puVar21,4);
          if (iVar7 != 0) goto LAB_007d9b38;
          iVar17 = *(byte *)(local_c8 + 2) - 1;
          uVar15 = local_b8;
          if (-1 < iVar17) {
            piVar13 = (int *)(local_c8 + 0x18 + iVar17 * 8);
            do {
              if ((int)(uint)*(ushort *)(piVar13 + 1) <= (int)uVar15) {
                if (*(ushort *)(piVar13 + 1) == uVar15) {
                  puVar6 = (undefined1 *)*piVar13;
                  goto LAB_007d9992;
                }
                uVar15 = uVar15 - 1;
              }
              iVar17 = iVar17 + -1;
              piVar13 = piVar13 + -2;
            } while (-1 < iVar17);
          }
          puVar6 = (undefined1 *)
                   ((uint)*(ushort *)(local_c8 + 0xe) + *(int *)(local_c8 + 0x44) + uVar15 * 2);
          puVar6 = (undefined1 *)(*(int *)(local_c8 + 0x44) + (uint)CONCAT11(*puVar6,puVar6[1]));
LAB_007d9992:
          uVar4 = *(undefined4 *)(iVar16 + 0x48);
          *puVar6 = (char)((uint)uVar4 >> 0x18);
          puVar6[1] = (char)((uint)uVar4 >> 0x10);
          puVar6[2] = (char)((uint)uVar4 >> 8);
          puVar6[3] = (char)uVar4;
          if ((*(char *)((int)local_a8 + 0x13) != '\0') && (local_c4 == 0)) {
            iVar17 = *(byte *)(local_c8 + 2) - 1;
            if (-1 < iVar17) {
              iVar7 = local_c8 + 0x18 + iVar17 * 8;
              uVar15 = local_b8;
              do {
                if ((int)(uint)*(ushort *)(iVar7 + 4) <= (int)uVar15) {
                  if (*(ushort *)(iVar7 + 4) == uVar15) break;
                  uVar15 = uVar15 - 1;
                }
                iVar17 = iVar17 + -1;
                iVar7 = iVar7 + -8;
              } while (-1 < iVar17);
            }
            iVar7 = FUN_007d5c40();
            if (iVar7 != 0) goto LAB_007d9b38;
          }
          iVar5 = iVar5 + 1;
          local_b8 = local_b8 + 1;
        }
        local_d0 = local_d0 + 1;
      } while (local_d0 < local_b0);
    }
    if ((local_bc & 8) == 0) {
      *(undefined4 *)(*(int *)(local_94[local_b0] + 0x44) + 8) =
           *(undefined4 *)(*(int *)(auStack_3c[local_c0] + 0x44) + 8);
    }
    if (local_b8 == (uint)*(ushort *)(local_c8 + 0x14) + (uint)*(byte *)(local_c8 + 2)) {
      iVar5 = local_5c[local_b0];
      puVar6 = (undefined1 *)(*(byte *)(local_c8 + 8) + 8 + *(int *)(local_c8 + 0x44));
      *puVar6 = (char)((uint)iVar5 >> 0x18);
      puVar6[1] = (char)((uint)iVar5 >> 0x10);
      puVar6[2] = (char)((uint)iVar5 >> 8);
      puVar6[3] = (char)iVar5;
    }
    else {
      iVar5 = *(byte *)(local_c8 + 2) - 1;
      uVar15 = local_b8;
      if (-1 < iVar5) {
        piVar13 = (int *)(local_c8 + 0x18 + iVar5 * 8);
        do {
          if ((int)(uint)*(ushort *)(piVar13 + 1) <= (int)uVar15) {
            if (*(ushort *)(piVar13 + 1) == uVar15) {
              puVar6 = (undefined1 *)*piVar13;
              goto LAB_007d9adc;
            }
            uVar15 = uVar15 - 1;
          }
          iVar5 = iVar5 + -1;
          piVar13 = piVar13 + -2;
        } while (-1 < iVar5);
      }
      puVar6 = (undefined1 *)
               ((uint)*(ushort *)(local_c8 + 0xe) + *(int *)(local_c8 + 0x44) + uVar15 * 2);
      puVar6 = (undefined1 *)(*(int *)(local_c8 + 0x44) + (uint)CONCAT11(*puVar6,puVar6[1]));
LAB_007d9adc:
      iVar5 = local_5c[local_b0];
      *puVar6 = (char)((uint)iVar5 >> 0x18);
      puVar6[1] = (char)((uint)iVar5 >> 0x10);
      puVar6[2] = (char)((uint)iVar5 >> 8);
      puVar6[3] = (char)iVar5;
    }
    iVar5 = 0;
    if (0 < local_b0) {
      do {
        iVar7 = FUN_007d8a20();
        if (iVar7 != 0) goto LAB_007d9b38;
        iVar5 = iVar5 + 1;
      } while (iVar5 < local_b0);
    }
    iVar5 = local_c8;
    iVar7 = FUN_007d8a20();
    if (iVar7 == 0) {
      iVar7 = FUN_007d9f90(iVar5,0);
    }
  }
LAB_007d9b38:
  FUN_007d05b0(local_a4);
  iVar5 = local_c0;
  iVar17 = 0;
  if (0 < local_c0) {
    do {
      if (aiStack_7c[iVar17] != 0) {
        FUN_007f1030(*(undefined4 *)(aiStack_7c[iVar17] + 0x44));
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 < iVar5);
  }
  iVar5 = local_b0;
  iVar17 = 0;
  if (0 < local_b0) {
    do {
      if (local_94[iVar17 + 1] != 0) {
        FUN_007f1030(*(undefined4 *)(local_94[iVar17 + 1] + 0x44));
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 < iVar5);
  }
  FUN_007f1030(*(undefined4 *)(local_c8 + 0x44));
  return iVar7;
}


// ==== FUN_007d9bb0 @ 0x007d9bb0 ====

int FUN_007d9bb0(undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  undefined4 *puVar13;
  int iVar14;
  undefined4 *puVar15;
  int local_28;
  int local_24;
  ushort local_6;
  
  local_24 = *(int *)(param_1 + 0x40);
  iVar8 = (int)(*(ushort *)(local_24 + 0x14) - 8) / 3;
  iVar14 = 0;
  iVar9 = FUN_007d0590(iVar8 * 8);
  if (iVar9 == 0) {
    return 7;
  }
  puVar3 = (uint *)(iVar9 + iVar8 * 4);
  if (param_1[4] == '\0') {
    iVar14 = FUN_007d6370(&local_28);
    iVar8 = local_28;
    if (iVar14 == 0) {
      if (*(int *)(param_1 + 0x48) == 1) {
        iVar14 = FUN_007d6170(param_1);
        if (iVar14 != 0) goto LAB_007d9de3;
        if (99 < *(ushort *)(iVar8 + 0x12)) {
          FUN_007d62d0(**(undefined1 **)(iVar8 + 0x44));
          if (*(short *)(iVar8 + 0x14) != 0) {
            local_28 = iVar9 - (int)puVar3;
            iVar14 = 0;
            puVar12 = puVar3;
            do {
              puVar1 = (undefined1 *)
                       ((uint)*(ushort *)(iVar8 + 0xe) + *(int *)(iVar8 + 0x44) + iVar14 * 2);
              iVar10 = *(int *)(iVar8 + 0x44) + (uint)CONCAT11(*puVar1,puVar1[1]);
              *(int *)(local_28 + (int)puVar12) = iVar10;
              FUN_007d5b50(iVar8,iVar10);
              *puVar12 = (uint)local_6;
              iVar14 = iVar14 + 1;
              puVar12 = puVar12 + 1;
            } while (iVar14 < (int)(uint)*(ushort *)(iVar8 + 0x14));
          }
          FUN_007d8d30(param_1,*(undefined2 *)(iVar8 + 0x14),iVar9,puVar3);
          puVar1 = (undefined1 *)(*(byte *)(iVar8 + 8) + 8 + *(int *)(iVar8 + 0x44));
          uVar4 = puVar1[2];
          uVar5 = puVar1[1];
          uVar6 = puVar1[3];
          puVar2 = (undefined1 *)((byte)param_1[8] + 8 + *(int *)(param_1 + 0x44));
          *puVar2 = *puVar1;
          puVar2[1] = uVar5;
          puVar2[2] = uVar4;
          puVar2[3] = uVar6;
          FUN_007d83e0(iVar8);
        }
      }
      else {
        uVar7 = *(ushort *)(*(int *)(param_1 + 0x40) + 0x16);
        puVar13 = *(undefined4 **)(local_28 + 0x44);
        puVar15 = *(undefined4 **)(param_1 + 0x44);
        for (uVar11 = (uint)(uVar7 >> 2); uVar11 != 0; uVar11 = uVar11 - 1) {
          *puVar15 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar15 = puVar15 + 1;
        }
        for (uVar11 = uVar7 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
          *(undefined1 *)puVar15 = *(undefined1 *)puVar13;
          puVar13 = (undefined4 *)((int)puVar13 + 1);
          puVar15 = (undefined4 *)((int)puVar15 + 1);
        }
        *param_1 = 0;
        *(undefined4 *)(param_1 + 0x4c) = 0;
        FUN_007d6170(0);
        FUN_007d83e0(iVar8);
      }
      iVar14 = FUN_007d8a20();
      if ((*(char *)(local_24 + 0x13) != '\0') && (iVar10 = 0, *(short *)(param_1 + 0x14) != 0)) {
        do {
          FUN_007d5b10();
          iVar14 = FUN_007d5c40();
          if (iVar14 != 0) goto LAB_007d9de3;
          iVar10 = iVar10 + 1;
        } while (iVar10 < (int)(uint)*(ushort *)(param_1 + 0x14));
      }
      if (iVar14 == 0) {
        FUN_007f1030(*(undefined4 *)(iVar8 + 0x44));
      }
    }
  }
LAB_007d9de3:
  FUN_007d05b0(iVar9);
  return iVar14;
}


// ==== FUN_007d9e00 @ 0x007d9e00 ====

int FUN_007d9e00(int param_1)

{
  undefined1 *puVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined1 local_8 [4];
  int local_4;
  
  iVar4 = param_1;
  iVar7 = *(int *)(param_1 + 0x40);
  local_4 = iVar7;
  iVar5 = FUN_007d7df0(iVar7,&param_1,local_8,*(undefined4 *)(param_1 + 0x48),0);
  iVar8 = param_1;
  if (iVar5 != 0) {
    return iVar5;
  }
  uVar3 = *(ushort *)(iVar7 + 0x16);
  iVar7 = *(int *)(iVar4 + 0x44);
  puVar13 = *(undefined4 **)(param_1 + 0x44);
  uVar9 = ((uint)*(ushort *)(iVar4 + 0xe) + (uint)*(ushort *)(iVar4 + 0x14) * 2) -
          (uint)*(byte *)(iVar4 + 8);
  puVar11 = (undefined4 *)((uint)*(byte *)(iVar4 + 8) + iVar7);
  uVar6 = (uint)CONCAT11(*(undefined1 *)((int)puVar11 + 5),*(undefined1 *)((int)puVar11 + 6));
  puVar12 = puVar13;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *puVar12 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar12 = puVar12 + 1;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
    puVar11 = (undefined4 *)((int)puVar11 + 1);
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  uVar9 = uVar3 - uVar6;
  puVar11 = (undefined4 *)(uVar6 + iVar7);
  puVar13 = (undefined4 *)((int)puVar13 + uVar6);
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *puVar13 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar13 = puVar13 + 1;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined1 *)puVar13 = *(undefined1 *)puVar11;
    puVar11 = (undefined4 *)((int)puVar11 + 1);
    puVar13 = (undefined4 *)((int)puVar13 + 1);
  }
  iVar7 = FUN_007d6170(iVar4);
  if (iVar7 == 0) {
    puVar11 = (undefined4 *)(iVar4 + 0x18);
    puVar13 = (undefined4 *)(iVar8 + 0x18);
    for (iVar7 = (uint)*(byte *)(iVar4 + 2) << 1; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar13 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar13 = puVar13 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar13 = *(undefined1 *)puVar11;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    cVar2 = *(char *)(iVar4 + 2);
    *(char *)(iVar8 + 2) = cVar2;
    if (cVar2 != '\0') {
      *(undefined2 *)(iVar8 + 0x12) = 0;
    }
    FUN_007d62d0(**(byte **)(iVar8 + 0x44) & 0xf7);
    puVar1 = (undefined1 *)(*(byte *)(iVar4 + 8) + 8 + *(int *)(iVar4 + 0x44));
    *puVar1 = local_8[3];
    puVar1[1] = local_8[2];
    puVar1[2] = local_8[1];
    puVar1[3] = local_8[0];
    if (*(char *)(local_4 + 0x13) != '\0') {
      iVar7 = FUN_007d5960(5);
      if (iVar7 != 0) goto LAB_007d9f73;
      iVar7 = 0;
      if (*(short *)(param_1 + 0x14) != 0) {
        do {
          iVar4 = param_1;
          FUN_007d5b10();
          iVar8 = FUN_007d5c40();
          if (iVar8 != 0) {
            return iVar8;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)(uint)*(ushort *)(iVar4 + 0x14));
      }
      iVar8 = param_1;
    }
    iVar7 = FUN_007d8fd0(iVar8);
  }
  else {
LAB_007d9f73:
    iVar8 = param_1;
  }
  FUN_007f1030(*(undefined4 *)(iVar8 + 0x44));
  return iVar7;
}


// ==== FUN_007d9f90 @ 0x007d9f90 ====

int FUN_007d9f90(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    if ((*(char *)(param_1 + 2) != '\0') && (iVar1 = FUN_007d9e00(param_1), iVar1 != 0)) {
      return iVar1;
    }
    if (*(short *)(param_1 + 0x14) == 0) {
      iVar1 = FUN_007d9bb0(param_1);
      return iVar1;
    }
  }
  else if ((*(char *)(param_1 + 2) != '\0') ||
          ((param_2 == 0 &&
           (((uint)*(ushort *)(*(int *)(param_1 + 0x40) + 0x16) << 1) / 3 <
            (uint)*(ushort *)(param_1 + 0x12))))) {
    iVar1 = FUN_007d8fd0(param_1);
    return iVar1;
  }
  return 0;
}


// ==== FUN_007da010 @ 0x007da010 ====

undefined4 FUN_007da010(void)

{
  int iVar1;
  int in_EAX;
  int unaff_EBX;
  int unaff_EDI;
  
  iVar1 = *(int *)(in_EAX + 4);
  do {
    if (iVar1 == 0) {
      return 0;
    }
    if ((*(int *)(iVar1 + 0x14) == unaff_EDI) && (iVar1 != unaff_EBX)) {
      if (*(char *)(iVar1 + 0x40) == '\0') {
        return 6;
      }
      if (*(int *)(*(int *)(iVar1 + 0x18) + 0x48) != *(int *)(iVar1 + 0x14)) {
        FUN_007d7520(iVar1);
      }
    }
    iVar1 = *(int *)(iVar1 + 4);
  } while( true );
}


// ==== FUN_007da050 @ 0x007da050 ====

int FUN_007da050(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_8;
  undefined1 local_4 [4];
  
  iVar5 = *param_1;
  if (*(char *)(iVar5 + 0xc) != '\x02') {
    return (-(uint)(*(char *)(iVar5 + 0xe) != '\0') & 7) + 1;
  }
  if ((char)param_1[0x10] == '\0') {
    return 3;
  }
  iVar2 = FUN_007da010();
  if (iVar2 != 0) {
    return 6;
  }
  iVar2 = FUN_007d7880(param_1,param_2,param_3,param_4,&local_8);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = param_1[6];
  iVar3 = FUN_007f10a0(*(undefined4 *)(iVar2 + 0x44));
  if (iVar3 != 0) {
    return iVar3;
  }
  puVar4 = (undefined4 *)FUN_007d0590(*(ushort *)(iVar5 + 0x14) - 8);
  if (puVar4 == (undefined4 *)0x0) {
    return 7;
  }
  iVar5 = FUN_007d8730(param_2,param_3,param_4,param_5,param_6,local_4);
  if (iVar5 == 0) {
    if (local_8 == 0) {
      if (*(char *)((int)param_1 + 0x41) != '\0') {
        puVar1 = (undefined1 *)
                 ((uint)*(ushort *)(iVar2 + 0xe) + *(int *)(iVar2 + 0x44) + param_1[7] * 2);
        if (*(char *)(iVar2 + 4) == '\0') {
          *puVar4 = *(undefined4 *)((uint)CONCAT11(*puVar1,puVar1[1]) + *(int *)(iVar2 + 0x44));
        }
        FUN_007d5c20();
        iVar5 = FUN_007d8640();
        if (iVar5 != 0) goto LAB_007da1db;
        FUN_007d8ae0(param_1[7]);
      }
    }
    else if ((local_8 < 0) && (*(short *)(iVar2 + 0x14) != 0)) {
      param_1[7] = param_1[7] + 1;
      *(undefined2 *)((int)param_1 + 0x3a) = 0;
    }
    iVar5 = FUN_007d8b50(iVar2,puVar4,0);
    if ((iVar5 == 0) && (iVar5 = FUN_007d9f90(iVar2,1), iVar5 == 0)) {
      FUN_007d7520(param_1);
    }
  }
LAB_007da1db:
  FUN_007d05b0(puVar4);
  return iVar5;
}


// ==== FUN_007da200 @ 0x007da200 ====

int FUN_007da200(int *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined1 *puVar7;
  int *piVar8;
  int *piVar9;
  int local_58;
  undefined1 local_4c [4];
  int local_48 [6];
  int local_30;
  int local_2c;
  
  piVar5 = param_1;
  iVar3 = *param_1;
  iVar4 = param_1[6];
  param_1 = (int *)0x0;
  if (*(char *)(iVar3 + 0xc) != '\x02') {
    return (-(uint)(*(char *)(iVar3 + 0xe) != '\0') & 7) + 1;
  }
  if ((int)(uint)*(ushort *)(iVar4 + 0x14) <= piVar5[7]) {
    return 1;
  }
  if ((char)piVar5[0x10] == '\0') {
    return 3;
  }
  iVar6 = FUN_007da010();
  if (iVar6 != 0) {
    return 6;
  }
  iVar6 = FUN_007f10a0(*(undefined4 *)(iVar4 + 0x44));
  if (iVar6 == 0) {
    puVar7 = (undefined1 *)((uint)*(ushort *)(iVar4 + 0xe) + *(int *)(iVar4 + 0x44) + piVar5[7] * 2)
    ;
    puVar7 = (undefined1 *)((uint)CONCAT11(*puVar7,puVar7[1]) + *(int *)(iVar4 + 0x44));
    if (*(char *)(iVar4 + 4) == '\0') {
      param_1 = (int *)CONCAT31(CONCAT21(CONCAT11(*puVar7,puVar7[1]),puVar7[2]),puVar7[3]);
    }
    iVar6 = FUN_007d8640();
    if (iVar6 == 0) {
      if (*(char *)(iVar4 + 4) == '\0') {
        piVar8 = piVar5;
        piVar9 = local_48;
        for (iVar6 = 0x12; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar9 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar9 = piVar9 + 1;
        }
        local_58 = 0;
        local_48[1] = 0;
        local_48[2] = 0;
        if (local_30 != 0) {
          FUN_007f02c0(*(undefined4 *)(local_30 + 0x44));
        }
        iVar6 = FUN_007d7b80(local_48,local_4c);
        if (iVar6 == 0) {
          iVar6 = FUN_007f10a0(*(undefined4 *)(local_30 + 0x44));
          if (iVar6 == 0) {
            FUN_007d5c20();
            FUN_007d8ae0(piVar5[7]);
            iVar6 = *(int *)(local_30 + 0x44);
            puVar7 = (undefined1 *)((uint)*(ushort *)(local_30 + 0xe) + iVar6 + local_2c * 2);
            uVar1 = *puVar7;
            uVar2 = puVar7[1];
            FUN_007d5c20();
            local_58 = FUN_007d0590(*(ushort *)(iVar3 + 0x14) - 8);
            if (local_58 == 0) {
              iVar6 = 7;
            }
            else {
              iVar6 = FUN_007d8b50(iVar4,iVar6 + (uint)CONCAT11(uVar1,uVar2) + -4,0);
              if (iVar6 == 0) {
                puVar7 = (undefined1 *)FUN_007d5b10();
                *puVar7 = (char)((uint)param_1 >> 0x18);
                puVar7[1] = (char)((uint)param_1 >> 0x10);
                puVar7[2] = (char)((uint)param_1 >> 8);
                puVar7[3] = (char)param_1;
                iVar6 = FUN_007d9f90(iVar4,0);
                if (iVar6 == 0) {
                  FUN_007d8ae0(local_2c);
                  iVar6 = FUN_007d9f90(local_30,0);
                }
              }
            }
          }
        }
        else if (iVar6 != 7) {
          iVar6 = 0xb;
        }
        FUN_007d05b0(local_58);
        if (local_30 != 0) {
          FUN_007f1030(*(undefined4 *)(local_30 + 0x44));
        }
      }
      else {
        FUN_007d5c20();
        FUN_007d8ae0(piVar5[7]);
        iVar6 = FUN_007d9f90(iVar4,0);
      }
      if (iVar6 == 0) {
        FUN_007d7520(piVar5);
      }
    }
  }
  return iVar6;
}


// ==== FUN_007da4a0 @ 0x007da4a0 ====

int FUN_007da4a0(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int local_4;
  
  local_4 = 0;
  uVar2 = FUN_007f0000(*param_1);
  if (uVar2 < param_2) {
    return 0xb;
  }
  iVar3 = FUN_007d63b0(&local_4,param_3);
  iVar1 = local_4;
  if ((iVar3 == 0) && (iVar3 = FUN_007f10a0(*(undefined4 *)(local_4 + 0x44)), iVar3 == 0)) {
    iVar5 = 0;
    if (*(short *)(iVar1 + 0x14) != 0) {
      do {
        iVar3 = (uint)*(ushort *)(iVar1 + 0xe) + *(int *)(iVar1 + 0x44);
        puVar4 = (undefined1 *)
                 ((uint)CONCAT11(*(undefined1 *)(iVar3 + iVar5 * 2),
                                 *(undefined1 *)(iVar3 + iVar5 * 2 + 1)) + *(int *)(iVar1 + 0x44));
        if (((*(char *)(iVar1 + 4) == '\0') &&
            (iVar3 = FUN_007da4a0(param_1,CONCAT31(CONCAT21(CONCAT11(*puVar4,puVar4[1]),puVar4[2]),
                                                   puVar4[3]),*(undefined4 *)(iVar1 + 0x4c),1),
            iVar3 != 0)) || (iVar3 = FUN_007d8640(), iVar3 != 0)) goto LAB_007da5dc;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)(uint)*(ushort *)(iVar1 + 0x14));
    }
    if (*(char *)(iVar1 + 4) == '\0') {
      iVar3 = *(int *)(iVar1 + 0x44);
      iVar3 = FUN_007da4a0(param_1,CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 8),
                                                              *(undefined1 *)(iVar3 + 9)),
                                                     *(undefined1 *)(iVar3 + 10)),
                                            *(undefined1 *)(iVar3 + 0xb)),
                           *(undefined4 *)(iVar1 + 0x4c),1);
      if (iVar3 != 0) goto LAB_007da5dc;
    }
    if (param_4 == 0) {
      FUN_007d62d0(**(byte **)(iVar1 + 0x44) | 8);
    }
    else {
      iVar3 = FUN_007d83e0(iVar1);
    }
  }
LAB_007da5dc:
  if (iVar1 != 0) {
    FUN_007f1030(*(undefined4 *)(iVar1 + 0x44));
  }
  return iVar3;
}


// ==== FUN_007da600 @ 0x007da600 ====

int FUN_007da600(int param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0xc) != '\x02') {
    return (-(uint)(*(char *)(param_1 + 0xe) != '\0') & 7) + 1;
  }
  iVar1 = *(int *)(param_1 + 4);
  do {
    if (iVar1 == 0) {
      iVar1 = FUN_007da4a0(param_1,param_2,0,0);
      if (iVar1 != 0) {
        FUN_007d6f50(param_1);
      }
      return iVar1;
    }
    if (*(int *)(iVar1 + 0x14) == param_2) {
      if (*(char *)(iVar1 + 0x40) == '\0') {
        return 6;
      }
      FUN_007d7520(iVar1);
    }
    iVar1 = *(int *)(iVar1 + 4);
  } while( true );
}


// ==== FUN_007da670 @ 0x007da670 ====

int FUN_007da670(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int local_4;
  
  iVar1 = FUN_007f1420(*param_1,1,&local_4);
  if (iVar1 == 0) {
    *param_3 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(local_4 + 0x24 + param_2 * 4),
                                          *(undefined1 *)(local_4 + 0x25 + param_2 * 4)),
                                 *(undefined1 *)(local_4 + 0x26 + param_2 * 4)),
                        *(undefined1 *)(local_4 + 0x27 + param_2 * 4));
    FUN_007f1030(local_4);
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_007da6d0 @ 0x007da6d0 ====

int FUN_007da6d0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0xc) != '\x02') {
    return (-(uint)(*(char *)(param_1 + 0xe) != '\0') & 7) + 1;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x44);
  iVar2 = FUN_007f10a0(iVar1);
  if (iVar2 == 0) {
    *(char *)(iVar1 + 0x24 + param_2 * 4) = (char)((uint)param_3 >> 0x18);
    *(char *)(iVar1 + 0x25 + param_2 * 4) = (char)((uint)param_3 >> 0x10);
    *(char *)(iVar1 + 0x26 + param_2 * 4) = (char)((uint)param_3 >> 8);
    *(char *)(iVar1 + 0x27 + param_2 * 4) = (char)param_3;
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_007da730 @ 0x007da730 ====

undefined1 FUN_007da730(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 == 0) {
    return 0;
  }
  return *(undefined1 *)((uint)*(byte *)(iVar1 + 8) + *(int *)(iVar1 + 0x44));
}


// ==== FUN_007da750 @ 0x007da750 ====

void FUN_007da750(int param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  undefined1 *in_EAX;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = FUN_007e47e0(param_2,&param_3);
  if (in_EAX == (undefined1 *)0x0) {
    in_EAX = &DAT_0099cf70;
  }
  iVar1 = *(int *)(param_1 + 0x10);
  puVar3 = (undefined4 *)(param_1 + 0x10);
  if (iVar1 == 0) {
    FUN_007d0700(puVar3,in_EAX,uVar2,0);
    FUN_007d05b0(uVar2);
    return;
  }
  *puVar3 = 0;
  FUN_007d0700(puVar3,iVar1,&DAT_009fd0b4);
  FUN_007d05b0(iVar1);
  FUN_007d05b0(uVar2);
  return;
}


// ==== FUN_007da7d0 @ 0x007da7d0 ====

undefined4 FUN_007da7d0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int in_EDX;
  
  if (in_ECX == 0) {
    return 1;
  }
  if ((*(int *)(in_EDX + 8) < in_ECX) || (in_ECX < 0)) {
    FUN_007da750();
  }
  else {
    if (*(int *)(*(int *)(in_EDX + 0xc) + in_ECX * 4) == 1) {
      FUN_007da750();
      return 1;
    }
    piVar1 = (int *)(*(int *)(in_EDX + 0xc) + in_ECX * 4);
    iVar2 = *piVar1;
    *piVar1 = iVar2 + 1;
    if (iVar2 < 2) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_007da830 @ 0x007da830 ====

void FUN_007da830(char param_1,int param_2)

{
  int iVar1;
  char local_5;
  int local_4;
  
  iVar1 = FUN_007d5a50();
  if (iVar1 != 0) {
    FUN_007da750();
    return;
  }
  if ((local_5 != param_1) || (local_4 != param_2)) {
    FUN_007da750();
  }
  return;
}


// ==== FUN_007da8b0 @ 0x007da8b0 ====

void FUN_007da8b0(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int *in_ECX;
  int iVar3;
  undefined1 *local_14;
  int local_10;
  int local_c;
  int local_4;
  
  local_4 = param_2;
  if (0 < param_2) {
    while( true ) {
      iVar3 = param_2 + -1;
      if (in_EAX < 1) {
        FUN_007da750();
        return;
      }
      if (in_EAX == 0) {
        return;
      }
      if ((in_ECX[2] < in_EAX) || (in_EAX < 0)) {
        FUN_007da750();
        return;
      }
      if (*(int *)(in_ECX[3] + in_EAX * 4) == 1) {
        FUN_007da750();
        return;
      }
      piVar1 = (int *)(in_ECX[3] + in_EAX * 4);
      iVar2 = *piVar1;
      *piVar1 = iVar2 + 1;
      if (1 < iVar2) {
        return;
      }
      iVar2 = FUN_007f1420(in_ECX[1],in_EAX,&local_14);
      if (iVar2 != 0) break;
      if (param_1 == 0) {
        if ((*(char *)(*in_ECX + 0x13) != '\0') && (0 < iVar3)) {
          FUN_007da830(4,in_EAX,param_3);
        }
      }
      else {
        iVar2 = CONCAT31(CONCAT21(CONCAT11(local_14[4],local_14[5]),local_14[6]),local_14[7]);
        local_c = iVar2;
        if (*(char *)(*in_ECX + 0x13) != '\0') {
          FUN_007da830(2,0,param_3);
        }
        if ((int)((*(ushort *)(*in_ECX + 0x16) >> 2) - 8) < iVar2) {
          FUN_007da750();
          iVar3 = param_2 + -2;
        }
        else {
          if (0 < iVar2) {
            local_10 = local_c;
            do {
              if (*(char *)(*in_ECX + 0x13) != '\0') {
                FUN_007da830(2,0,param_3);
              }
              FUN_007da7d0();
              local_10 = local_10 + -1;
            } while (local_10 != 0);
            local_10 = 0;
            iVar2 = local_c;
          }
          iVar3 = iVar3 - iVar2;
        }
      }
      in_EAX = CONCAT31(CONCAT21(CONCAT11(*local_14,local_14[1]),local_14[2]),local_14[3]);
      FUN_007f1030(local_14);
      param_2 = iVar3;
      if (iVar3 < 1) {
        return;
      }
    }
    FUN_007da750();
  }
  return;
}


// ==== FUN_007dab10 @ 0x007dab10 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007dab10(int *param_1,int param_2,undefined4 param_3)

{
  byte *pbVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined1 *puVar12;
  uint uVar13;
  undefined4 *puVar14;
  int local_a0;
  undefined1 *local_9c;
  uint local_98;
  uint local_94;
  int local_90;
  uint local_8c;
  int local_80;
  int local_78;
  ushort local_72;
  ushort local_6e;
  char local_68 [100];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  _sprintf(local_68,s_Page__d__00a00af4,param_2);
  iVar7 = *param_1;
  local_94 = (uint)*(ushort *)(iVar7 + 0x16);
  if ((param_2 != 0) && (iVar9 = FUN_007da7d0(), iVar9 == 0)) {
    iVar9 = FUN_007d6370(&local_98);
    uVar8 = local_98;
    if (iVar9 == 0) {
      iVar9 = FUN_007d6170(param_3);
      if (iVar9 != 0) {
        FUN_007da750(param_1,s_initPage___returns_error_code__d_00a00aa8,iVar9);
        if (uVar8 != 0) {
          FUN_007f1030(*(undefined4 *)(uVar8 + 0x44));
        }
        return 0;
      }
      local_90 = 0;
      local_a0 = 0;
      if (*(short *)(uVar8 + 0x14) != 0) {
        do {
          _sprintf(local_68,s_On_tree_page__d_cell__d__00a00a8c,param_2,local_a0);
          puVar12 = (undefined1 *)
                    ((uint)*(ushort *)(uVar8 + 0xe) + *(int *)(uVar8 + 0x44) + local_a0 * 2);
          puVar12 = (undefined1 *)((uint)CONCAT11(*puVar12,puVar12[1]) + *(int *)(uVar8 + 0x44));
          FUN_007d5b50(uVar8,puVar12);
          iVar9 = local_78;
          if (*(char *)(uVar8 + 3) == '\0') {
            iVar9 = local_78 + local_80;
          }
          if ((int)(uint)local_72 < iVar9) {
            local_98 = (int)((iVar9 - (uint)local_72) + -5 + local_94) / (int)(local_94 - 4);
            if (*(char *)(iVar7 + 0x13) != '\0') {
              FUN_007da830(3,param_2,local_68);
            }
            FUN_007da8b0(0,local_98,local_68);
          }
          if (*(char *)(uVar8 + 4) == '\0') {
            uVar2 = puVar12[2];
            uVar3 = puVar12[3];
            uVar4 = *puVar12;
            uVar5 = puVar12[1];
            if (*(char *)(iVar7 + 0x13) != '\0') {
              FUN_007da830(5,param_2,local_68);
            }
            iVar9 = FUN_007dab10(param_1,CONCAT31(CONCAT21(CONCAT11(uVar4,uVar5),uVar2),uVar3),uVar8
                                 ,local_68,0,0,0,0);
            if ((0 < local_a0) && (iVar9 != local_90)) {
              FUN_007da750(param_1,s_Child_page_depth_differs_00a00a70);
            }
            local_90 = iVar9;
          }
          local_a0 = local_a0 + 1;
        } while (local_a0 < (int)(uint)*(ushort *)(uVar8 + 0x14));
      }
      if (*(char *)(uVar8 + 4) == '\0') {
        uVar2 = *(undefined1 *)(*(byte *)(uVar8 + 8) + 8 + *(int *)(uVar8 + 0x44));
        iVar9 = *(byte *)(uVar8 + 8) + 8 + *(int *)(uVar8 + 0x44);
        uVar3 = *(undefined1 *)(iVar9 + 2);
        uVar4 = *(undefined1 *)(iVar9 + 1);
        uVar5 = *(undefined1 *)(iVar9 + 3);
        _sprintf(local_68,s_On_page__d_at_right_child__00a00a54,param_2);
        if (*(char *)(iVar7 + 0x13) != '\0') {
          FUN_007da830(5,param_2,0);
        }
        FUN_007dab10(param_1,CONCAT31(CONCAT21(CONCAT11(uVar2,uVar4),uVar3),uVar5),uVar8,local_68,0,
                     0,0,0);
      }
      uVar13 = (uint)*(byte *)(uVar8 + 8);
      iVar7 = *(int *)(uVar8 + 0x44);
      local_98 = uVar13;
      puVar10 = (undefined4 *)FUN_007d0550(local_94);
      if (puVar10 != (undefined4 *)0x0) {
        local_a0 = 0;
        bVar6 = *(byte *)(uVar13 + 6 + iVar7);
        puVar14 = puVar10;
        for (uVar11 = (uint)(ushort)(CONCAT11(*(undefined1 *)(uVar13 + 5 + iVar7),bVar6) >> 2);
            uVar11 != 0; uVar11 = uVar11 - 1) {
          *puVar14 = 0x1010101;
          puVar14 = puVar14 + 1;
        }
        for (uVar11 = bVar6 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
          *(undefined1 *)puVar14 = 1;
          puVar14 = (undefined4 *)((int)puVar14 + 1);
        }
        local_8c = (uint)CONCAT11(*(undefined1 *)(uVar13 + 3 + iVar7),
                                  *(undefined1 *)(uVar13 + 4 + iVar7));
        if (local_8c != 0) {
          local_9c = (undefined1 *)(uVar13 + (3 - (uint)*(byte *)(uVar8 + 4)) * 4 + iVar7);
          do {
            uVar13 = (uint)CONCAT11(*local_9c,local_9c[1]);
            FUN_007d5b50(uVar8,uVar13 + iVar7);
            iVar9 = (local_6e - 1) + uVar13;
            if (iVar9 < (int)local_94) {
              for (; (int)uVar13 <= iVar9; iVar9 = iVar9 + -1) {
                *(char *)(iVar9 + (int)puVar10) = *(char *)(iVar9 + (int)puVar10) + '\x01';
              }
            }
            else {
              FUN_007da750(param_1,s_Corruption_detected_in_cell__d_o_00a00a28,local_a0,param_2,0);
            }
            local_a0 = local_a0 + 1;
            local_9c = local_9c + 2;
          } while (local_a0 < (int)local_8c);
          uVar13 = local_98;
        }
        uVar13 = (uint)CONCAT11(*(undefined1 *)(uVar13 + 1 + iVar7),
                                *(undefined1 *)(uVar13 + 2 + iVar7));
        local_9c = (undefined1 *)0x0;
        if (uVar13 == 0) {
          uVar11 = local_94;
        }
        else {
          do {
            uVar11 = local_94;
            if (((int)local_94 <= (int)uVar13) || (9999 < (int)local_9c)) break;
            iVar9 = (CONCAT11(*(undefined1 *)(iVar7 + 2 + uVar13),
                              *(undefined1 *)(iVar7 + 3 + uVar13)) - 1) + uVar13;
            if (iVar9 < (int)local_94) {
              for (; (int)uVar13 <= iVar9; iVar9 = iVar9 + -1) {
                *(char *)(iVar9 + (int)puVar10) = *(char *)(iVar9 + (int)puVar10) + '\x01';
              }
            }
            else {
              FUN_007da750(param_1,s_Corruption_detected_in_cell__d_o_00a00a28,uVar13,param_2,0);
            }
            pbVar1 = (byte *)(iVar7 + uVar13);
            local_9c = (undefined1 *)((int)local_9c + 1);
            uVar13 = (uint)CONCAT11(*pbVar1,*(undefined1 *)(iVar7 + 1 + uVar13));
          } while (uVar13 != 0 && -1 < (int3)(uint3)*pbVar1);
        }
        uVar13 = 0;
        iVar9 = 0;
        if (0 < (int)uVar11) {
          do {
            if (*(char *)((int)puVar10 + iVar9) == '\0') {
              uVar13 = uVar13 + 1;
            }
            else if ('\x01' < *(char *)((int)puVar10 + iVar9)) {
              FUN_007da750(param_1,s_Multiple_uses_for_byte__d_of_pag_00a00a00,iVar9,param_2);
              break;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)uVar11);
        }
        uVar11 = (uint)*(byte *)(local_98 + 7 + iVar7);
        if (uVar13 != uVar11) {
          FUN_007da750(param_1,s_Fragmented_space_is__d_byte_repo_00a009c8,uVar13,uVar11,param_2);
        }
      }
      FUN_007d05b0(puVar10);
      FUN_007f1030(*(undefined4 *)(uVar8 + 0x44));
      return local_90 + 1;
    }
    FUN_007da750(param_1,s_unable_to_get_the_page__error_co_00a00acc,iVar9);
  }
  return 0;
}


// ==== FUN_007db070 @ 0x007db070 ====

void FUN_007db070(void)

{
  FUN_007f08e0();
  return;
}


// ==== FUN_007db080 @ 0x007db080 ====

void FUN_007db080(void)

{
  FUN_007f08f0();
  return;
}


// ==== FUN_007db090 @ 0x007db090 ====

void FUN_007db090(void)

{
  FUN_007f0900();
  return;
}


// ==== FUN_007db0a0 @ 0x007db0a0 ====

int FUN_007db0a0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_8;
  uint local_4;
  
  puVar2 = param_2;
  puVar1 = param_1;
  iVar6 = 0;
  if ((*(char *)(param_1 + 3) != '\x02') || (*(char *)(param_2 + 3) != '\x02')) {
    return 1;
  }
  if (param_1[1] != 0) {
    return 5;
  }
  local_4 = FUN_007f0000(*param_1);
  param_1 = (undefined4 *)FUN_007f0000(*puVar2);
  uVar4 = 1;
  while (((uVar5 = (uint)param_1, uVar4 <= param_1 &&
          (iVar6 = FUN_007f1420(*puVar2,uVar4,&local_8), uVar5 = (uint)param_1, iVar6 == 0)) &&
         (iVar6 = FUN_007f1850(*puVar1,uVar4,local_8), uVar5 = (uint)param_1, iVar6 == 0))) {
    FUN_007f1030(local_8);
    uVar4 = uVar4 + 1;
  }
  do {
    if (iVar6 != 0) {
LAB_007db1be:
      if (*(char *)(puVar1 + 3) == '\x02') {
        FUN_007f0db0(*puVar1);
        iVar3 = FUN_007f1420(*puVar1,1,&param_1);
        if (iVar3 == 0) {
          iVar3 = (uint)*(ushort *)(puVar1 + 5) + (int)param_1;
          *(undefined4 **)(iVar3 + 0x44) = param_1;
          *(undefined4 **)(iVar3 + 0x40) = puVar1;
          *(undefined4 *)(iVar3 + 0x48) = 1;
          *(undefined1 *)(iVar3 + 8) = 100;
          FUN_007f1030(param_1);
        }
      }
      *(undefined1 *)(puVar1 + 3) = 0;
      *(undefined1 *)((int)puVar1 + 0xd) = 0;
      if ((puVar1[1] == 0) && (iVar3 = puVar1[2], iVar3 != 0)) {
        if (*(int *)(iVar3 + 0x44) == 0) {
          *(uint *)(iVar3 + 0x44) = iVar3 - (uint)*(ushort *)(puVar1 + 5);
          *(undefined4 **)(iVar3 + 0x40) = puVar1;
          *(undefined4 *)(iVar3 + 0x48) = 1;
        }
        if (puVar1[2] != 0) {
          FUN_007f1030(*(undefined4 *)(puVar1[2] + 0x44));
        }
        puVar1[2] = 0;
        *(undefined1 *)((int)puVar1 + 0xd) = 0;
      }
      return iVar6;
    }
    uVar5 = uVar5 + 1;
    if (local_4 < uVar5) {
      if (local_4 <= param_1) {
        return 0;
      }
      iVar6 = FUN_007f0ba0(*puVar1,param_1);
      if (iVar6 == 0) {
        return 0;
      }
      goto LAB_007db1be;
    }
    iVar6 = FUN_007f1420(*puVar1,uVar5,&local_8);
    if (iVar6 != 0) goto LAB_007db1be;
    iVar6 = FUN_007f10a0(local_8);
    FUN_007f1030(local_8);
    FUN_007f04d0(*puVar1,uVar5);
  } while( true );
}


// ==== FUN_007db270 @ 0x007db270 ====

undefined4 FUN_007db270(int param_1)

{
  if ((param_1 == 0) || (*(char *)(param_1 + 0xc) != '\x02')) {
    return 0;
  }
  return 1;
}


// ==== FUN_007db290 @ 0x007db290 ====

undefined4 FUN_007db290(int param_1)

{
  if ((param_1 == 0) || (*(char *)(param_1 + 0xd) == '\0')) {
    return 0;
  }
  return 1;
}


// ==== FUN_007db2b0 @ 0x007db2b0 ====

undefined4 FUN_007db2b0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)param_1[1];
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    if (piVar1[2] == 0) {
      *(int *)(iVar2 + 4) = piVar1[1];
    }
    else {
      *(int *)(piVar1[2] + 4) = piVar1[1];
    }
    if (piVar1[1] != 0) {
      *(int *)(piVar1[1] + 8) = piVar1[2];
    }
    if (piVar1[6] != 0) {
      FUN_007f1030(*(undefined4 *)(piVar1[6] + 0x44));
    }
    if (((*(char *)(iVar2 + 0xc) == '\0') && (*(int *)(iVar2 + 4) == 0)) &&
       (iVar3 = *(int *)(iVar2 + 8), iVar3 != 0)) {
      if (*(int *)(iVar3 + 0x44) == 0) {
        *(uint *)(iVar3 + 0x44) = iVar3 - (uint)*(ushort *)(iVar2 + 0x14);
        *(int *)(iVar3 + 0x40) = iVar2;
        *(undefined4 *)(iVar3 + 0x48) = 1;
      }
      if (*(int *)(iVar2 + 8) != 0) {
        FUN_007f1030(*(undefined4 *)(*(int *)(iVar2 + 8) + 0x44));
      }
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined1 *)(iVar2 + 0xd) = 0;
    }
    FUN_007d05b0(piVar1);
    piVar1 = (int *)param_1[1];
  }
  FUN_007f0f70(*param_1);
  FUN_007d05b0(param_1);
  return 0;
}


// ==== FUN_007db370 @ 0x007db370 ====

int FUN_007db370(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  
  iVar2 = 0;
  if (*(char *)(unaff_ESI + 0xc) == '\0') {
    iVar2 = 0;
    iVar4 = 0;
    while( true ) {
      if (*(int *)(unaff_ESI + 8) == 0) {
        iVar2 = FUN_007d6730();
      }
      if (iVar2 == 0) break;
      if (((*(char *)(unaff_ESI + 0xc) == '\0') && (*(int *)(unaff_ESI + 4) == 0)) &&
         (iVar3 = *(int *)(unaff_ESI + 8), iVar3 != 0)) {
        if (*(int *)(iVar3 + 0x44) == 0) {
          *(uint *)(iVar3 + 0x44) = iVar3 - (uint)*(ushort *)(unaff_ESI + 0x14);
          *(int *)(iVar3 + 0x40) = unaff_ESI;
          *(undefined4 *)(iVar3 + 0x48) = 1;
        }
        if (*(int *)(unaff_ESI + 8) != 0) {
          FUN_007f1030(*(undefined4 *)(*(int *)(unaff_ESI + 8) + 0x44));
        }
        *(undefined4 *)(unaff_ESI + 8) = 0;
        *(undefined1 *)(unaff_ESI + 0xd) = 0;
      }
      if (((iVar2 != 5) || (*(char *)(unaff_ESI + 0xc) != '\0')) ||
         ((puVar1 = *(undefined4 **)(unaff_ESI + 0x28), puVar1 == (undefined4 *)0x0 ||
          ((code *)*puVar1 == (code *)0x0)))) goto LAB_007db411;
      iVar3 = (*(code *)*puVar1)(puVar1[1],iVar4);
      iVar4 = iVar4 + 1;
      if (iVar3 == 0) {
        *(undefined1 *)(unaff_ESI + 0xc) = 0;
        return 5;
      }
    }
    *(undefined1 *)(unaff_ESI + 0xc) = 1;
LAB_007db411:
    *(undefined1 *)(unaff_ESI + 0xc) = 0;
  }
  return iVar2;
}


// ==== FUN_007db420 @ 0x007db420 ====

/* WARNING: Removing unreachable block (ram,0x007db5d8) */
/* WARNING: Removing unreachable block (ram,0x007db617) */

int FUN_007db420(uint *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_EAX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  uint local_10;
  uint local_8;
  uint local_4;
  
  uVar1 = *in_EAX;
  local_1c = 0;
  uVar8 = *(ushort *)(in_EAX + 5) / 5;
  uVar6 = uVar8 + 1;
  local_14 = uVar1;
  local_4 = uVar6;
  iVar3 = FUN_007f0000(uVar1);
  local_18 = ((iVar3 + -2) / (int)uVar6) * uVar6 + 2;
  iVar3 = FUN_007f0000(uVar1);
  if (local_18 == iVar3) {
    return 0xb;
  }
  iVar3 = *(int *)(in_EAX[2] + 0x44);
  iVar3 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 0x24),*(undefined1 *)(iVar3 + 0x25)),
                            *(undefined1 *)(iVar3 + 0x26)),*(undefined1 *)(iVar3 + 0x27));
  if (iVar3 == 0) {
    *param_1 = 0;
    return 0;
  }
  local_18 = iVar3;
  uVar4 = FUN_007f0000(local_14);
  uVar7 = (uVar4 - ((((uVar4 - 2) / uVar6) * uVar6 - uVar4) + uVar8 + 2 + iVar3) / uVar8) - local_18
  ;
  uVar5 = (int)(0x40000000 / (ulonglong)(longlong)(int)(uint)*(ushort *)(in_EAX + 5)) + 1;
  uVar8 = uVar7;
  if (((uVar5 < uVar4) && (uVar7 <= uVar5)) &&
     (uVar5 = *(ushort *)((int)in_EAX + 0x16) / 5 + 1, uVar8 = uVar7 - 1,
     ((uVar7 - 3) / uVar5) * uVar5 + 2 == uVar8)) {
    uVar8 = uVar7 - 2;
  }
  local_24 = uVar8 + 1;
  local_8 = uVar4;
  if (local_24 <= uVar4) {
    local_20 = uVar8 - 1;
    do {
      if (((local_20 / uVar6) * uVar6 + 2 != local_24) &&
         (local_24 !=
          (int)(0x40000000 / (ulonglong)(longlong)(int)(uint)*(ushort *)(in_EAX + 5)) + 1U)) {
        iVar3 = FUN_007d5a50(local_24,&local_18);
        if (iVar3 != 0) goto LAB_007db6d3;
        if ((char)local_18 == '\x01') {
          iVar3 = 0xb;
          goto LAB_007db6d3;
        }
        if ((char)local_18 != '\x02') {
          iVar3 = FUN_007d6370(&local_1c);
          if (iVar3 != 0) goto LAB_007db6d3;
          do {
            iVar3 = FUN_007d7df0();
            iVar2 = local_1c;
            if (iVar3 != 0) {
              if (local_1c != 0) {
                FUN_007f1030(*(undefined4 *)(local_1c + 0x44));
              }
              goto LAB_007db6d3;
            }
          } while (uVar8 < local_10);
          iVar3 = FUN_007d6df0();
          if (iVar2 != 0) {
            FUN_007f1030(*(undefined4 *)(iVar2 + 0x44));
          }
          if (iVar3 != 0) goto LAB_007db6d3;
        }
        uVar4 = local_8;
        uVar6 = local_4;
      }
      local_24 = local_24 + 1;
      local_20 = local_20 + 1;
    } while (local_24 <= uVar4);
  }
  iVar3 = FUN_007f10a0(*(undefined4 *)(in_EAX[2] + 0x44));
  if (iVar3 == 0) {
    iVar3 = *(int *)(in_EAX[2] + 0x44);
    *(undefined1 *)(iVar3 + 0x20) = 0;
    *(undefined1 *)(iVar3 + 0x21) = 0;
    *(undefined1 *)(iVar3 + 0x22) = 0;
    *(undefined1 *)(iVar3 + 0x23) = 0;
    iVar3 = *(int *)(in_EAX[2] + 0x44);
    *(undefined1 *)(iVar3 + 0x24) = 0;
    *(undefined1 *)(iVar3 + 0x25) = 0;
    *(undefined1 *)(iVar3 + 0x26) = 0;
    *(undefined1 *)(iVar3 + 0x27) = 0;
    *param_1 = uVar8;
    return 0;
  }
LAB_007db6d3:
  FUN_007f0db0(local_14);
  return iVar3;
}


// ==== FUN_007db700 @ 0x007db700 ====

int FUN_007db700(undefined4 *param_1,int param_2,int param_3,undefined1 *param_4,undefined4 param_5,
                undefined4 *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_6 = 0;
  if (param_3 != 0) {
    if (*(char *)((int)param_1 + 0xe) != '\0') {
      return 8;
    }
    iVar1 = FUN_007da010();
    if (iVar1 != 0) {
      return 6;
    }
  }
  if ((param_1[2] == 0) && (iVar1 = FUN_007db370(), iVar1 != 0)) {
    return iVar1;
  }
  puVar2 = (undefined4 *)FUN_007d0590(0x48);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_007d68d0();
    return 7;
  }
  puVar2[5] = param_2;
  puVar2[6] = 0;
  if ((param_2 == 1) && (iVar1 = FUN_007f0000(*param_1), iVar1 == 0)) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = FUN_007d63b0(puVar2 + 6,0);
    if (iVar1 == 0) {
      if (param_4 == (undefined1 *)0x0) {
        param_4 = &LAB_007d7060;
      }
      puVar2[3] = param_4;
      puVar2[4] = param_5;
      *(undefined1 *)(puVar2 + 0x10) = (undefined1)param_3;
      *puVar2 = param_1;
      puVar2[7] = 0;
      puVar2[8] = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      puVar2[0xb] = 0;
      puVar2[0xc] = 0;
      puVar2[0xd] = 0;
      puVar2[0xe] = 0;
      puVar2[0xf] = 0;
      iVar1 = param_1[1];
      puVar2[1] = iVar1;
      if (iVar1 != 0) {
        *(undefined4 **)(iVar1 + 8) = puVar2;
      }
      puVar2[2] = 0;
      param_1[1] = puVar2;
      *(undefined1 *)((int)puVar2 + 0x41) = 0;
      *param_6 = puVar2;
      return 0;
    }
  }
  if (puVar2[6] != 0) {
    FUN_007f1030(*(undefined4 *)(puVar2[6] + 0x44));
  }
  FUN_007d05b0(puVar2);
  FUN_007d68d0();
  return iVar1;
}


// ==== FUN_007db850 @ 0x007db850 ====

int FUN_007db850(int param_1,int *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  iVar5 = param_1;
  if (*(char *)(param_1 + 0xc) != '\x02') {
    return (-(uint)(*(char *)(param_1 + 0xe) != '\0') & 7) + 1;
  }
  if (*(int *)(param_1 + 4) != 0) {
    return 6;
  }
  if (*(char *)(param_1 + 0x13) == '\0') {
    iVar5 = FUN_007d7df0(param_1,&param_1,&local_c,1,0);
    if (iVar5 != 0) {
      return iVar5;
    }
    iVar6 = local_c;
    iVar2 = param_1;
  }
  else {
    iVar2 = FUN_007da670(param_1,4,&local_c);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar6 = local_c + 1;
    uVar1 = *(ushort *)(iVar5 + 0x16) / 5 + 1;
    if ((iVar6 == ((local_c - 1U) / uVar1) * uVar1 + 2) ||
       (iVar6 == (int)(0x40000000 / (ulonglong)(longlong)(int)(uint)*(ushort *)(iVar5 + 0x14)) + 1))
    {
      iVar6 = local_c + 2;
    }
    iVar2 = FUN_007d7df0(iVar5,&param_1,&local_c,iVar6,1);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (local_c == iVar6) {
      iVar2 = param_1;
    }
    else {
      if (param_1 != 0) {
        FUN_007f1030(*(undefined4 *)(param_1 + 0x44));
      }
      iVar2 = FUN_007d6370(&param_1);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar3 = FUN_007d5a50(iVar6,&local_8);
      iVar4 = local_8;
      iVar2 = param_1;
      if (((iVar3 != 0) || ((char)local_8 == '\x01')) || ((char)local_8 == '\x02')) {
        if (param_1 != 0) {
          FUN_007f1030(*(undefined4 *)(param_1 + 0x44));
        }
        return iVar3;
      }
      local_8 = FUN_007f10a0(*(undefined4 *)(param_1 + 0x44));
      if (local_8 != 0) {
        FUN_007f1030(*(undefined4 *)(iVar2 + 0x44));
        return local_8;
      }
      iVar4 = FUN_007d6df0(iVar5,iVar4,local_4,local_c);
      FUN_007f1030(*(undefined4 *)(iVar2 + 0x44));
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = FUN_007d6370(&param_1);
      iVar2 = param_1;
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = FUN_007f10a0(*(undefined4 *)(param_1 + 0x44));
      if (iVar4 != 0) {
        FUN_007f1030(*(undefined4 *)(iVar2 + 0x44));
        return iVar4;
      }
    }
    iVar4 = FUN_007d5960(1);
    if (iVar4 != 0) {
      if (iVar2 == 0) {
        return iVar4;
      }
      FUN_007f1030(*(undefined4 *)(iVar2 + 0x44));
      return iVar4;
    }
    iVar5 = FUN_007da6d0(iVar5,4,iVar6);
    if (iVar5 != 0) {
      if (iVar2 != 0) {
        FUN_007f1030(*(undefined4 *)(iVar2 + 0x44));
      }
      return iVar5;
    }
  }
  FUN_007d62d0(param_3 | 8);
  FUN_007f1030(*(undefined4 *)(iVar2 + 0x44));
  *param_2 = iVar6;
  return 0;
}


// ==== FUN_007dbad0 @ 0x007dbad0 ====

int FUN_007dbad0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int local_4;
  
  puVar5 = param_2;
  puVar2 = param_1;
  local_4 = 0;
  if (*(char *)(param_1 + 3) != '\x02') {
    return (-(uint)(*(char *)((int)param_1 + 0xe) != '\0') & 7) + 1;
  }
  if (param_1[1] != 0) {
    return 6;
  }
  iVar6 = FUN_007d6370(&local_4);
  if (iVar6 == 0) {
    iVar6 = FUN_007da600(puVar2,puVar5);
    iVar7 = local_4;
    if (iVar6 == 0) {
      *param_3 = 0;
      if ((int)puVar5 < 2) {
        FUN_007d62d0(9);
        if (iVar7 != 0) {
          FUN_007f1030(*(undefined4 *)(iVar7 + 0x44));
        }
      }
      else {
        if (*(char *)((int)puVar2 + 0x13) != '\0') {
          iVar7 = FUN_007da670(puVar2,4,&param_1);
          iVar6 = local_4;
          puVar3 = param_1;
          if (iVar7 != 0) {
            if (local_4 != 0) {
              FUN_007f1030(*(undefined4 *)(local_4 + 0x44));
            }
            return iVar7;
          }
          if (puVar5 == param_1) {
            iVar7 = FUN_007d83e0(local_4);
            if (iVar6 != 0) {
              FUN_007f1030(*(undefined4 *)(iVar6 + 0x44));
            }
            if (iVar7 == 0) {
LAB_007dbc77:
              iVar6 = (int)puVar3 + -1;
              if (iVar6 == (int)(0x40000000 /
                                (ulonglong)(longlong)(int)(uint)*(ushort *)(puVar2 + 5)) + 1) {
                iVar6 = (int)puVar3 + -2;
              }
              uVar1 = *(ushort *)((int)puVar2 + 0x16) / 5 + 1;
              if (iVar6 == ((iVar6 - 2U) / uVar1) * uVar1 + 2) {
                iVar6 = iVar6 + -1;
              }
              iVar6 = FUN_007da6d0(puVar2,4,iVar6);
              return iVar6;
            }
          }
          else {
            if (local_4 != 0) {
              FUN_007f1030(*(undefined4 *)(local_4 + 0x44));
            }
            iVar6 = FUN_007d6370(&param_1);
            puVar4 = param_1;
            if (iVar6 != 0) {
              return iVar6;
            }
            iVar7 = FUN_007f1a40(*puVar2,param_1[0x11],puVar5);
            if (iVar7 == 0) {
              puVar4[0x12] = puVar5;
              iVar7 = FUN_007d6b10();
            }
            FUN_007f1030(puVar4[0x11]);
            if (iVar7 == 0) {
              iVar6 = FUN_007d6370(&param_1);
              puVar5 = param_1;
              if (iVar6 != 0) {
                return iVar6;
              }
              iVar7 = FUN_007d83e0(param_1);
              if (puVar5 != (undefined4 *)0x0) {
                FUN_007f1030(puVar5[0x11]);
              }
              if (iVar7 == 0) {
                *param_3 = puVar3;
                goto LAB_007dbc77;
              }
            }
          }
          return iVar7;
        }
        iVar6 = FUN_007d83e0(local_4);
        if (iVar7 != 0) {
          FUN_007f1030(*(undefined4 *)(iVar7 + 0x44));
          return iVar6;
        }
      }
    }
    else if (local_4 != 0) {
      FUN_007f1030(*(undefined4 *)(local_4 + 0x44));
      return iVar6;
    }
  }
  return iVar6;
}


// ==== FUN_007dbd20 @ 0x007dbd20 ====

undefined4 FUN_007dbd20(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  piVar3 = (int *)FUN_007f05f0(*param_1);
  iVar1 = *piVar3;
  iVar4 = FUN_007db370();
  if (iVar4 != 0) {
    uVar5 = FUN_007d0640(s_Unable_to_acquire_a_read_lock_on_00a00bc0);
    return uVar5;
  }
  local_10 = *param_1;
  local_14 = param_1;
  local_c = FUN_007f0000(local_10);
  if (local_c == 0) {
    FUN_007d68d0();
    return 0;
  }
  local_8 = FUN_007d0590(local_c * 4 + 4);
  if (local_8 == 0) {
    FUN_007d68d0();
    uVar5 = FUN_007e4830(s_Unable_to_malloc__d_bytes_00a00ba4,local_c * 4 + 4);
    return uVar5;
  }
  iVar4 = 0;
  if (-1 < local_c) {
    do {
      *(undefined4 *)(local_8 + iVar4 * 4) = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 <= local_c);
  }
  iVar4 = (int)(0x40000000 / (ulonglong)(longlong)(int)(uint)*(ushort *)(param_1 + 5)) + 1;
  if (iVar4 <= local_c) {
    *(undefined4 *)(local_8 + iVar4 * 4) = 1;
  }
  local_4 = 0;
  iVar4 = *(int *)(param_1[2] + 0x44);
  FUN_007da8b0(1,CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar4 + 0x24),
                                            *(undefined1 *)(iVar4 + 0x25)),
                                   *(undefined1 *)(iVar4 + 0x26)),*(undefined1 *)(iVar4 + 0x27)),
               s_Main_freelist__00a00b94);
  if (0 < param_3) {
    iVar4 = 0;
    do {
      iVar2 = *(int *)(param_2 + iVar4 * 4);
      if (iVar2 != 0) {
        if ((*(char *)((int)param_1 + 0x13) != '\0') && (1 < iVar2)) {
          FUN_007da830(1,0,0);
        }
        FUN_007dab10(&local_14,*(undefined4 *)(param_2 + iVar4 * 4),0,s_List_of_tree_roots__00a00b7c
                     ,0,0,0,0);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_3);
  }
  iVar4 = 1;
  if (0 < local_c) {
    do {
      if ((*(int *)(local_8 + iVar4 * 4) == 0) &&
         ((iVar2 = *(ushort *)((int)param_1 + 0x16) / 5 + 1,
          ((iVar4 + -2) / iVar2) * iVar2 + 2 != iVar4 || (*(char *)((int)param_1 + 0x13) == '\0'))))
      {
        FUN_007da750(&local_14,s_Page__d_is_never_used_00a00b64,iVar4);
      }
      if (((*(int *)(local_8 + iVar4 * 4) != 0) &&
          (iVar2 = *(ushort *)((int)param_1 + 0x16) / 5 + 1,
          ((iVar4 + -2) / iVar2) * iVar2 + 2 == iVar4)) && (*(char *)((int)param_1 + 0x13) != '\0'))
      {
        FUN_007da750(&local_14,s_Pointer_map_page__d_is_reference_00a00b40,iVar4);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= local_c);
  }
  if (((*(char *)(param_1 + 3) == '\0') && (param_1[1] == 0)) && (iVar4 = param_1[2], iVar4 != 0)) {
    if (*(int *)(iVar4 + 0x44) == 0) {
      *(uint *)(iVar4 + 0x44) = iVar4 - (uint)*(ushort *)(param_1 + 5);
      *(undefined4 **)(iVar4 + 0x40) = param_1;
      *(undefined4 *)(iVar4 + 0x48) = 1;
    }
    if (param_1[2] != 0) {
      FUN_007f1030(*(undefined4 *)(param_1[2] + 0x44));
    }
    param_1[2] = 0;
    *(undefined1 *)((int)param_1 + 0xd) = 0;
  }
  piVar3 = (int *)FUN_007f05f0(*param_1);
  if (iVar1 != *piVar3) {
    puVar6 = (undefined4 *)FUN_007f05f0(*param_1);
    FUN_007da750(&local_14,s_Outstanding_page_count_goes_from_00a00b00,iVar1,*puVar6);
  }
  FUN_007d05b0(local_8);
  return local_4;
}


// ==== FUN_007dc020 @ 0x007dc020 ====

int FUN_007dc020(undefined4 *param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = param_1;
  if (*(char *)(param_1 + 3) != '\x02') {
    return 0;
  }
  pcVar1 = (char *)((int)param_1 + 0x13);
  param_1 = (undefined4 *)0x0;
  if ((*pcVar1 == '\0') || (iVar3 = FUN_007db420(&param_1), iVar3 == 0)) {
    iVar3 = FUN_007f1920(*puVar2,param_2,param_1);
    return iVar3;
  }
  return iVar3;
}


// ==== FUN_007dc070 @ 0x007dc070 ====

void FUN_007dc070(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_007d0550(0x248);
  if (piVar1 == (int *)0x0) {
    return;
  }
  *piVar1 = param_1;
  if (*(int *)(param_1 + 0x48) != 0) {
    *(int **)(*(int *)(param_1 + 0x48) + 4) = piVar1;
  }
  piVar1[2] = *(int *)(param_1 + 0x48);
  piVar1[1] = 0;
  *(int **)(param_1 + 0x48) = piVar1;
  piVar1[0x16] = 0x26bceaa5;
  return;
}


// ==== FUN_007dc0b0 @ 0x007dc0b0 ====

void FUN_007dc0b0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}


// ==== FUN_007dc0c0 @ 0x007dc0c0 ====

void FUN_007dc0c0(void)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if (*(int *)(in_ECX + 0x58) == -0x420df25d) {
    *(int *)(in_ECX + 0x14) = in_EAX;
    uVar1 = FUN_007d05d0(*(undefined4 *)(in_ECX + 0x18),in_EAX * 0x14);
    *(undefined4 *)(in_ECX + 0x18) = uVar1;
    return;
  }
  iVar4 = *(int *)(in_ECX + 0x14);
  if (iVar4 < in_EAX) {
    *(int *)(in_ECX + 0x14) = in_EAX + 100;
    iVar2 = FUN_007d05d0(*(undefined4 *)(in_ECX + 0x18),(in_EAX + 100) * 0x14);
    *(int *)(in_ECX + 0x18) = iVar2;
    if (iVar2 != 0) {
      puVar5 = (undefined4 *)(iVar2 + iVar4 * 0x14);
      for (uVar3 = (uint)((*(int *)(in_ECX + 0x14) - iVar4) * 0x14) >> 2; uVar3 != 0;
          uVar3 = uVar3 - 1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar5 = 0;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
    }
  }
  return;
}


// ==== FUN_007dc140 @ 0x007dc140 ====

int FUN_007dc140(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 0x10) = iVar2 + 1;
  FUN_007dc0c0();
  if (*(int *)(param_1 + 0x18) == 0) {
    return 0;
  }
  puVar1 = (undefined1 *)(*(int *)(param_1 + 0x18) + iVar2 * 0x14);
  *puVar1 = param_2;
  *(undefined4 *)(puVar1 + 4) = param_3;
  *(undefined4 *)(puVar1 + 8) = param_4;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  *(undefined4 *)(puVar1 + 0x10) = 0;
  return iVar2;
}


// ==== FUN_007dc190 @ 0x007dc190 ====

int FUN_007dc190(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0x1c) = iVar2 + 1;
  if (*(int *)(param_1 + 0x20) <= iVar2) {
    iVar1 = *(int *)(param_1 + 0x20) * 2 + 10;
    *(int *)(param_1 + 0x20) = iVar1;
    uVar3 = FUN_007d05d0(*(undefined4 *)(param_1 + 0x24),iVar1 * 4);
    *(undefined4 *)(param_1 + 0x24) = uVar3;
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x24) + iVar2 * 4) = 0xffffffff;
  }
  return -1 - iVar2;
}


// ==== FUN_007dc1e0 @ 0x007dc1e0 ====

void FUN_007dc1e0(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x24) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x24) - (param_2 * 4 + 4)) = *(undefined4 *)(param_1 + 0x10);
  }
  return;
}


// ==== FUN_007dc200 @ 0x007dc200 ====

void FUN_007dc200(int *param_1,int *param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int unaff_ESI;
  int iVar8;
  int local_c;
  
  iVar5 = *(int *)(unaff_ESI + 0x24);
  pbVar6 = *(byte **)(unaff_ESI + 0x18);
  iVar7 = *(int *)(unaff_ESI + 0x10);
  iVar8 = 0;
  bVar3 = false;
  bVar2 = false;
  if (-1 < iVar7 + -1) {
    local_c = iVar7;
    do {
      bVar1 = *pbVar6;
      if (bVar1 == 0x16) {
        if (iVar8 < *(int *)(pbVar6 + 4)) {
          iVar8 = *(int *)(pbVar6 + 4);
        }
      }
      else if (bVar1 == 0x1d) {
        if (iVar8 < *(int *)(pbVar6 + 8)) {
          iVar8 = *(int *)(pbVar6 + 8);
        }
      }
      else if (bVar1 == 0x25) {
        if ((*(int *)(pbVar6 + 4) == 0x13) && (*(int *)(pbVar6 + 8) == 2)) {
          bVar3 = true;
        }
      }
      else if (bVar1 == 0x6e) {
        if (*(int *)(pbVar6 + 8) != 0) {
          bVar3 = true;
        }
      }
      else if (bVar1 == 0x29) {
        bVar2 = true;
      }
      if ((*(uint *)(&DAT_00a00bf0 + (uint)(bVar1 >> 5) * 4) & 1 << (bVar1 & 0x1f)) != 0) {
        iVar7 = iVar7 + -1;
      }
      if (*(int *)(pbVar6 + 8) < 0) {
        *(undefined4 *)(pbVar6 + 8) = *(undefined4 *)(iVar5 - (*(int *)(pbVar6 + 8) * 4 + 4));
      }
      pbVar6 = pbVar6 + 0x14;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  FUN_007d05b0(*(undefined4 *)(unaff_ESI + 0x24));
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  *param_1 = iVar8;
  *param_2 = iVar7;
  if ((bVar2) && (!bVar3)) {
    iVar5 = *(int *)(unaff_ESI + 0x10);
    pcVar4 = *(char **)(unaff_ESI + 0x18);
    if (-1 < iVar5 + -1) {
      do {
        if (*pcVar4 == ')') {
          *pcVar4 = '\x17';
        }
        pcVar4 = pcVar4 + 0x14;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  return;
}


// ==== FUN_007dc320 @ 0x007dc320 ====

undefined4 FUN_007dc320(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}


// ==== FUN_007dc330 @ 0x007dc330 ====

int FUN_007dc330(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  FUN_007dc0c0();
  if (*(int *)(param_1 + 0x18) == 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (0 < param_2) {
    piVar3 = (int *)(param_3 + 4);
    iVar5 = iVar1 * 0x14;
    local_4 = param_2;
    do {
      iVar4 = (int)*(short *)((int)piVar3 + -2);
      puVar2 = (undefined1 *)(*(int *)(param_1 + 0x18) + iVar5);
      *puVar2 = (char)piVar3[-1];
      *(int *)(puVar2 + 4) = (int)*(char *)((int)piVar3 + -3);
      if (iVar4 < 0) {
        iVar4 = (iVar1 - iVar4) + -1;
      }
      *(int *)(puVar2 + 8) = iVar4;
      *(int *)(puVar2 + 0xc) = *piVar3;
      *(uint *)(puVar2 + 0x10) = -(uint)(*piVar3 != 0) & 0xfffffffe;
      iVar5 = iVar5 + 0x14;
      piVar3 = piVar3 + 2;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + param_2;
  }
  return iVar1;
}


// ==== FUN_007dc3d0 @ 0x007dc3d0 ====

void FUN_007dc3d0(int param_1,int param_2,undefined4 param_3)

{
  if ((((param_1 != 0) && (-1 < param_2)) && (param_2 < *(int *)(param_1 + 0x10))) &&
     (*(int *)(param_1 + 0x18) != 0)) {
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 4 + param_2 * 0x14) = param_3;
  }
  return;
}


// ==== FUN_007dc400 @ 0x007dc400 ====

void FUN_007dc400(int param_1,int param_2,undefined4 param_3)

{
  if ((((param_1 != 0) && (-1 < param_2)) && (param_2 < *(int *)(param_1 + 0x10))) &&
     (*(int *)(param_1 + 0x18) != 0)) {
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 8 + param_2 * 0x14) = param_3;
  }
  return;
}


// ==== FUN_007dc430 @ 0x007dc430 ====

void FUN_007dc430(int param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x18) == 0)) {
    if ((param_4 == -1) || (param_4 == -9)) {
      FUN_007d05b0(param_3);
    }
    if (param_4 == -8) {
      FUN_007cfe40(param_3);
      return;
    }
  }
  else if (((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x10))) ||
          (param_2 = *(int *)(param_1 + 0x10) + -1, -1 < param_2)) {
    iVar1 = *(int *)(param_1 + 0x18) + param_2 * 0x14;
    if ((*(int *)(iVar1 + 0xc) != 0) && (*(int *)(iVar1 + 0x10) == -1)) {
      FUN_007d05b0(*(int *)(iVar1 + 0xc));
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    if (param_3 == (char *)0x0) {
      *(undefined4 *)(iVar1 + 0xc) = 0;
      *(undefined4 *)(iVar1 + 0x10) = 0;
      return;
    }
    if (param_4 != -6) {
      if (param_4 == -9) {
        *(char **)(iVar1 + 0xc) = param_3;
        *(undefined4 *)(iVar1 + 0x10) = 0xfffffffa;
        return;
      }
      if (param_4 < 0) {
        *(char **)(iVar1 + 0xc) = param_3;
        *(int *)(iVar1 + 0x10) = param_4;
        return;
      }
      if (param_4 == 0) {
        pcVar3 = param_3;
        do {
          cVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar2 != '\0');
        param_4 = (int)pcVar3 - (int)(param_3 + 1);
      }
      uVar4 = FUN_007d06a0(param_3,param_4);
      *(undefined4 *)(iVar1 + 0xc) = uVar4;
      *(undefined4 *)(iVar1 + 0x10) = 0xffffffff;
      return;
    }
    uVar5 = *(int *)(param_3 + 4) * 4 + 0xc;
    pcVar3 = (char *)FUN_007d0590(uVar5);
    *(char **)(iVar1 + 0xc) = pcVar3;
    if (pcVar3 == (char *)0x0) {
      *(undefined4 *)(iVar1 + 0x10) = 0;
      return;
    }
    for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)param_3;
      param_3 = param_3 + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pcVar3 = *param_3;
      param_3 = param_3 + 1;
      pcVar3 = pcVar3 + 1;
    }
    *(undefined4 *)(iVar1 + 0x10) = 0xfffffffa;
  }
  return;
}


// ==== FUN_007dc550 @ 0x007dc550 ====

void FUN_007dc550(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if ((*(int *)(param_1 + 0x18) != 0) &&
     (((-1 < param_2 && (param_2 < *(int *)(param_1 + 0x10))) ||
      (param_2 = *(int *)(param_1 + 0x10) + -1, -1 < param_2)))) {
    iVar1 = *(int *)(param_1 + 0x18) + param_2 * 0x14;
    pcVar2 = *(char **)(iVar1 + 0xc);
    if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
      if (*(int *)(iVar1 + 0x10) == -2) {
        uVar3 = FUN_007d0640(pcVar2);
        *(undefined4 *)(iVar1 + 0xc) = uVar3;
        *(undefined4 *)(iVar1 + 0x10) = 0xffffffff;
      }
      FUN_007d0860(*(undefined4 *)(iVar1 + 0xc));
    }
  }
  return;
}


// ==== FUN_007dc5b0 @ 0x007dc5b0 ====

int FUN_007dc5b0(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x18) + param_2 * 0x14;
}


// ==== FUN_007dc5d0 @ 0x007dc5d0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * FUN_007dc5d0(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  char *in_ECX;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  char *unaff_EBX;
  char *pcVar10;
  undefined4 *local_2c;
  int local_28;
  char local_24 [32];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar2 = *(int *)(in_ECX + 0x10);
  if (iVar2 == -6) {
    iVar2 = *(int *)(in_ECX + 0xc);
    _sprintf(unaff_EBX,s_keyinfo__d_00a00c20,*(undefined4 *)(iVar2 + 4));
    pcVar4 = unaff_EBX;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = pcVar4 + -(int)(unaff_EBX + 1);
    local_28 = 0;
    if (0 < *(int *)(iVar2 + 4)) {
      local_2c = (undefined4 *)(iVar2 + 0xc);
      do {
        puVar3 = (undefined4 *)*local_2c;
        if (puVar3 == (undefined4 *)0x0) {
          if ((int)(pcVar4 + 4) < (int)(param_1 + -6)) {
            *(undefined4 *)(unaff_EBX + (int)pcVar4) = DAT_00a00c18;
            (unaff_EBX + (int)pcVar4)[4] = DAT_00a00c1c;
            pcVar4 = pcVar4 + 4;
          }
        }
        else {
          pcVar6 = (char *)*puVar3;
          pcVar7 = pcVar6 + 1;
          do {
            cVar1 = *pcVar6;
            pcVar6 = pcVar6 + 1;
          } while (cVar1 != '\0');
          if ((int)(param_1 + -6) < (int)(pcVar6 + ((int)pcVar4 - (int)pcVar7))) {
            *(undefined4 *)(unaff_EBX + (int)pcVar4) = DAT_00a00c10;
            (unaff_EBX + (int)pcVar4)[4] = DAT_00a00c14;
            break;
          }
          unaff_EBX[(int)pcVar4] = ',';
          pcVar9 = pcVar4 + 1;
          if ((*(int *)(iVar2 + 8) != 0) && (*(char *)(*(int *)(iVar2 + 8) + local_28) != '\0')) {
            unaff_EBX[(int)pcVar9] = '-';
            pcVar9 = pcVar4 + 2;
          }
          pcVar10 = (char *)*puVar3;
          pcVar4 = unaff_EBX + (int)pcVar9;
          do {
            cVar1 = *pcVar10;
            pcVar10 = pcVar10 + 1;
            *pcVar4 = cVar1;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          pcVar4 = pcVar6 + ((int)pcVar9 - (int)pcVar7);
        }
        local_28 = local_28 + 1;
        local_2c = local_2c + 1;
      } while (local_28 < *(int *)(iVar2 + 4));
    }
    unaff_EBX[(int)pcVar4] = ')';
    unaff_EBX[(int)(pcVar4 + 1)] = '\0';
  }
  else {
    if (iVar2 != -5) {
      pcVar4 = *(char **)(in_ECX + 0xc);
      if (iVar2 == -4) {
        _sprintf(unaff_EBX,s_collseq___20s__00a00c3c,*(undefined4 *)pcVar4);
        return unaff_EBX;
      }
      if ((pcVar4 == (char *)0x0) || (*in_ECX == '\x17')) {
        return &DAT_0099cf70;
      }
      return pcVar4;
    }
    puVar3 = *(undefined4 **)(in_ECX + 0xc);
    _sprintf(unaff_EBX,&DAT_00a00c34,param_1,*puVar3);
    _sprintf(local_24,&DAT_00a00c2c,puVar3[1]);
    pcVar4 = unaff_EBX;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar7 = local_24;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (pcVar4 + (int)(pcVar7 + ((1 - (int)(local_24 + 1)) - (int)(unaff_EBX + 1))) <= param_1) {
      pcVar4 = local_24;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      uVar5 = (int)pcVar4 - (int)local_24;
      pcVar4 = unaff_EBX + -1;
      do {
        pcVar7 = pcVar4 + 1;
        pcVar4 = pcVar4 + 1;
      } while (*pcVar7 != '\0');
      pcVar7 = local_24;
      for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar4 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar4 = pcVar4 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar4 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar4 = pcVar4 + 1;
      }
      return unaff_EBX;
    }
  }
  return unaff_EBX;
}


// ==== FUN_007dc7f0 @ 0x007dc7f0 ====

undefined4 FUN_007dc7f0(int *param_1)

{
  char *pcVar1;
  byte *pbVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar8 = *param_1;
  if (param_1[0x16] != -0x420df25d) {
    return 0x15;
  }
  iVar10 = param_1[10];
  if ((param_1[0xb] == iVar10 + 0x100) && (iVar10 != 0)) {
    iVar9 = 5;
    do {
      FUN_007cf9b0(iVar10);
      iVar10 = iVar10 + 0x40;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  iVar10 = param_1[0x21];
  param_1[0x21] = iVar10 + 1;
  *(undefined1 *)(param_1 + 0x8f) = 0;
  if (param_1[4] <= iVar10) {
    param_1[0x22] = 0;
    return 0x65;
  }
  uVar4 = *(uint *)(iVar8 + 8);
  if ((uVar4 & 4) != 0) {
    *(uint *)(iVar8 + 8) = uVar4 & 0xfffffffb;
    param_1[0x22] = 9;
    uVar6 = FUN_007cd3a0(9,0);
    FUN_007d0700(param_1 + 0x8e,uVar6);
    return 1;
  }
  piVar5 = (int *)param_1[10];
  pbVar2 = (byte *)(param_1[6] + iVar10 * 0x14);
  *(undefined2 *)(piVar5 + 3) = 4;
  *piVar5 = iVar10;
  piVar5[1] = iVar10 >> 0x1f;
  *(undefined1 *)((int)piVar5 + 0xe) = 1;
  *(undefined2 *)(piVar5 + 0x13) = 0xa2;
  pcVar7 = (&PTR_DAT_00a02208)[*pbVar2];
  piVar5[0x16] = (int)pcVar7;
  pcVar1 = pcVar7 + 1;
  do {
    cVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar3 != '\0');
  *(undefined1 *)((int)piVar5 + 0x4f) = 1;
  *(undefined1 *)((int)piVar5 + 0x4e) = 3;
  piVar5[0x12] = (int)pcVar7 - (int)pcVar1;
  *(undefined2 *)(piVar5 + 0x23) = 4;
  iVar8 = *(int *)(pbVar2 + 4);
  *(undefined1 *)((int)piVar5 + 0x8e) = 1;
  piVar5[0x20] = iVar8;
  piVar5[0x21] = iVar8 >> 0x1f;
  *(undefined2 *)(piVar5 + 0x33) = 4;
  iVar8 = *(int *)(pbVar2 + 8);
  *(undefined1 *)((int)piVar5 + 0xce) = 1;
  piVar5[0x30] = iVar8;
  piVar5[0x31] = iVar8 >> 0x1f;
  *(undefined2 *)(piVar5 + 0x43) = 0x222;
  iVar8 = FUN_007dc5d0(0x20);
  piVar5[0x46] = iVar8;
  *(undefined1 *)((int)piVar5 + 0x10e) = 3;
  *(undefined1 *)((int)piVar5 + 0x10f) = 1;
  param_1[0xb] = (int)(piVar5 + 0x40);
  *(undefined1 *)(param_1 + 0x8f) = 1;
  param_1[0x8b] = 5;
  param_1[0x22] = 0;
  return 100;
}


// ==== FUN_007dc970 @ 0x007dc970 ====

void FUN_007dc970(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  iVar1 = param_1;
  *(undefined4 *)(param_1 + 0x58) = 0xbdf20da3;
  if (*(int *)(param_1 + 0x28) == 0) {
    FUN_007dc200(&param_1,&local_4);
    FUN_007dc0c0();
    iVar3 = param_3;
    iVar5 = param_2;
    iVar4 = 10;
    if (param_6 == 0) {
      iVar4 = local_4;
    }
    iVar2 = FUN_007d0550((param_5 * 7 + iVar4 * 0x10 + param_2 * 0x11 + param_3 * 0x10 + param_1 +
                         param_4) * 4);
    *(int *)(iVar1 + 0x28) = iVar2;
    if (DAT_00b5c4c4 == 0) {
      iVar2 = iVar4 * 0x40 + iVar2;
      *(int *)(iVar1 + 0x5c) = iVar3;
      iVar4 = iVar3 * 0x40 + iVar2;
      iVar3 = iVar5 * 0x40 + iVar4;
      *(int *)(iVar1 + 0x30) = iVar3;
      iVar3 = iVar3 + param_1 * 4;
      *(int *)(iVar1 + 0x50) = iVar3;
      iVar3 = iVar3 + iVar5 * 4;
      *(int *)(iVar1 + 0x60) = iVar2;
      *(int *)(iVar1 + 0x4c) = iVar4;
      *(int *)(iVar1 + 0x48) = iVar5;
      *(undefined4 *)(iVar1 + 0x54) = 0;
      *(int *)(iVar1 + 0x3c) = iVar3;
      if (0 < param_5) {
        *(int *)(iVar1 + 100) = param_5;
        *(int *)(iVar1 + 0x68) = iVar3 + param_4 * 4;
      }
      *(int *)(iVar1 + 0x38) = param_4;
      if (0 < iVar5) {
        iVar3 = 0;
        do {
          *(undefined2 *)(iVar3 + 0xc + *(int *)(iVar1 + 0x4c)) = 1;
          iVar3 = iVar3 + 0x40;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
  }
  iVar5 = 0;
  *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(iVar1 + 0x68);
  if (0 < *(int *)(iVar1 + 0x5c)) {
    iVar3 = 0;
    do {
      *(undefined2 *)(*(int *)(iVar1 + 0x60) + 0xc + iVar3) = 1;
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0x40;
    } while (iVar5 < *(int *)(iVar1 + 0x5c));
  }
  *(int *)(iVar1 + 0x2c) = *(int *)(iVar1 + 0x28) + -0x40;
  *(undefined4 *)(iVar1 + 0x88) = 0;
  *(undefined4 *)(iVar1 + 0x8c) = 0;
  *(undefined4 *)(iVar1 + 0x228) = 0;
  *(undefined4 *)(iVar1 + 0x234) = 0;
  *(undefined4 *)(iVar1 + 0x244) = 0;
  *(undefined4 *)(iVar1 + 0x84) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x90) = 2;
  *(byte *)(iVar1 + 0x23d) = *(byte *)(iVar1 + 0x23d) | (byte)param_6;
  *(undefined4 *)(iVar1 + 0x58) = 0xbdf20da3;
  return;
}


// ==== FUN_007dcaf0 @ 0x007dcaf0 ====

void FUN_007dcaf0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  while (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 0x40);
    *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(iVar1 + 0x48);
    FUN_007d05b0(*(undefined4 *)(iVar1 + 4));
    FUN_007cf9b0(iVar1 + 8);
    FUN_007d05b0(iVar1);
    iVar1 = *(int *)(param_1 + 0x40);
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  return;
}


// ==== FUN_007dcb40 @ 0x007dcb40 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007dcb40(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_5c [2];
  undefined4 auStack_54 [3];
  undefined2 local_48;
  undefined4 *local_14;
  undefined1 local_10;
  undefined4 local_c;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar3 = 0;
  if (0 < *param_2) {
    puVar2 = (undefined4 *)(param_1 + 0x20);
    do {
      if (((param_2[2] == 0) || (iVar1 = *(int *)(param_2[2] + iVar3 * 4), iVar1 == 0)) ||
         ((*(byte *)((int)puVar2 + -0xb) & 4) == 0)) {
        puVar4 = puVar2 + -6;
      }
      else {
        local_c = puVar2[-6];
        local_14 = (undefined4 *)*puVar2;
        local_48 = 1;
        local_10 = 0;
        local_5c[0] = iVar1;
        (**(code **)(iVar1 + 0x1c))(local_5c);
        *puVar2 = local_14;
        if ((local_14 != (undefined4 *)0x0) && (local_14 != puVar2 + 2)) {
          FUN_007d05b0(local_14);
        }
        puVar4 = auStack_54;
      }
      FUN_007cf9b0(puVar4);
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 0x10;
    } while (iVar3 < *param_2);
  }
  FUN_007d05b0(param_1);
  return;
}


// ==== FUN_007dcc00 @ 0x007dcc00 ====

void FUN_007dcc00(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    do {
      iVar1 = *(int *)(param_1 + 0xc);
      FUN_007d05b0(param_1);
      param_1 = iVar1;
    } while (iVar1 != 0);
  }
  return;
}


// ==== FUN_007dcc30 @ 0x007dcc30 ====

void FUN_007dcc30(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      FUN_007d70a0(*param_1);
    }
    if (param_1[0xc] != 0) {
      FUN_007db2b0(param_1[0xc]);
    }
    FUN_007d05b0(param_1[0xe]);
    FUN_007d05b0(param_1[0x17]);
    FUN_007d05b0(param_1);
  }
  return;
}


// ==== FUN_007dcc80 @ 0x007dcc80 ====

void FUN_007dcc80(void)

{
  int *piVar1;
  int unaff_EBX;
  int iVar2;
  
  if ((*(int *)(unaff_EBX + 0x3c) != 0) && (iVar2 = 0, 0 < *(int *)(unaff_EBX + 0x38))) {
    do {
      piVar1 = *(int **)(*(int *)(unaff_EBX + 0x3c) + iVar2 * 4);
      if (piVar1 != (int *)0x0) {
        if (*piVar1 != 0) {
          FUN_007d70a0(*piVar1);
        }
        if (piVar1[0xc] != 0) {
          FUN_007db2b0(piVar1[0xc]);
        }
        FUN_007d05b0(piVar1[0xe]);
        FUN_007d05b0(piVar1[0x17]);
        FUN_007d05b0(piVar1);
      }
      *(undefined4 *)(*(int *)(unaff_EBX + 0x3c) + iVar2 * 4) = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(unaff_EBX + 0x38));
  }
  return;
}


// ==== FUN_007dccf0 @ 0x007dccf0 ====

void FUN_007dccf0(int param_1,int param_2)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  
  iVar3 = param_2 * 2;
  *(int *)(param_1 + 0x22c) = param_2;
  iVar1 = FUN_007d0550(param_2 << 7);
  *(int *)(param_1 + 0x34) = iVar1;
  if ((iVar1 != 0) && (0 < iVar3)) {
    puVar2 = (undefined2 *)(iVar1 + 0xc);
    do {
      *puVar2 = 1;
      puVar2 = puVar2 + 0x20;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


// ==== FUN_007dcd30 @ 0x007dcd30 ====

int FUN_007dcd30(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00b5c4c4 != 0) {
    return 7;
  }
  iVar2 = param_2 * 0x40 + *(int *)(param_1 + 0x34);
  if ((param_4 == -1) || (param_4 == -2)) {
    uVar3 = 0;
    iVar1 = -1;
  }
  else {
    uVar3 = 0xffffffff;
    iVar1 = param_4;
  }
  iVar1 = FUN_007cfbe0(iVar2,param_3,iVar1,1,uVar3);
  if ((iVar1 == 0) && (param_4 == -1)) {
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    *(ushort *)(iVar2 + 0xc) = *(ushort *)(iVar2 + 0xc) & 0xff7f | 0x40;
  }
  return iVar1;
}


// ==== FUN_007dcdb0 @ 0x007dcdb0 ====

int FUN_007dcdb0(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  int *unaff_ESI;
  int iVar10;
  int local_10;
  uint local_c;
  int aiStack_8 [2];
  
  iVar10 = 0;
  bVar2 = false;
  local_c = 0;
  local_10 = 0;
  if (0 < *unaff_ESI) {
    iVar9 = 0;
    do {
      iVar3 = *(int *)(iVar10 + 4 + unaff_ESI[1]);
      if (((iVar3 != 0) && (iVar3 = FUN_007db270(iVar3), iVar3 != 0)) &&
         (bVar2 = true, iVar10 != 0x70)) {
        local_c = local_c + 1;
      }
      iVar9 = iVar9 + 1;
      iVar10 = iVar10 + 0x70;
    } while (iVar9 < *unaff_ESI);
    if ((bVar2) && (unaff_ESI[0x17] != 0)) {
      FUN_007d0ea0();
      iVar10 = (*(code *)unaff_ESI[0x17])(unaff_ESI[0x16]);
      FUN_007d0e60();
      if (iVar10 != 0) {
        return 0x13;
      }
    }
  }
  pcVar4 = (char *)FUN_007db070(*(undefined4 *)(unaff_ESI[1] + 4));
  pcVar7 = pcVar4 + 1;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  aiStack_8[0] = (int)pcVar4 - (int)pcVar7;
  if ((aiStack_8[0] == 0) || ((int)local_c < 2)) {
    iVar10 = 0;
    iVar9 = 0;
    while (iVar10 < *unaff_ESI) {
      iVar3 = *(int *)(iVar9 + 4 + unaff_ESI[1]);
      if (iVar3 != 0) {
        local_10 = FUN_007dc020(iVar3,0);
      }
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 0x70;
      if (local_10 != 0) {
        return local_10;
      }
    }
    if ((local_10 == 0) && (iVar10 = 0, 0 < *unaff_ESI)) {
      iVar9 = 0;
      do {
        iVar3 = *(int *)(iVar9 + 4 + unaff_ESI[1]);
        if (iVar3 != 0) {
          FUN_007d6f20(iVar3);
        }
        iVar10 = iVar10 + 1;
        iVar9 = iVar9 + 0x70;
      } while (iVar10 < *unaff_ESI);
    }
  }
  else {
    iVar9 = 0;
    iVar10 = 0;
    uVar5 = FUN_007db070(*(undefined4 *)(unaff_ESI[1] + 4));
    do {
      FUN_007d05b0(iVar10);
      FUN_007e6500(4,&local_c);
      iVar10 = FUN_007e4830(s__s_mj_08X_00a00c4c,uVar5,local_c & 0x7fffffff);
      if (iVar10 == 0) {
        return 7;
      }
      iVar3 = FUN_007d12b0(iVar10);
    } while (iVar3 != 0);
    aiStack_8[0] = 0;
    aiStack_8[1] = 0;
    iVar3 = FUN_007d1350(iVar10,aiStack_8,0);
    if (iVar3 != 0) {
      FUN_007d05b0(iVar10);
      return iVar3;
    }
    local_10 = 0;
    if (0 < *unaff_ESI) {
      do {
        iVar3 = *(int *)(unaff_ESI[1] + 4 + iVar9);
        if ((((iVar9 != 0x70) && (iVar3 != 0)) && (iVar6 = FUN_007db270(iVar3), iVar6 != 0)) &&
           (pcVar7 = (char *)FUN_007db090(iVar3), *pcVar7 != '\0')) {
          pcVar4 = pcVar7;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          iVar3 = FUN_007d15a0(aiStack_8,pcVar7,pcVar4 + (1 - (int)(pcVar7 + 1)));
          if (iVar3 != 0) goto LAB_007dd06a;
        }
        local_10 = local_10 + 1;
        iVar9 = iVar9 + 0x70;
      } while (local_10 < *unaff_ESI);
    }
    uVar8 = FUN_007db080(*(undefined4 *)(unaff_ESI[1] + 4));
    local_c = uVar8;
    iVar3 = FUN_004d8fb0(uVar8,aiStack_8);
    if ((iVar3 != 0) || (iVar3 = FUN_007d1630(aiStack_8), iVar3 != 0)) {
LAB_007dd06a:
      FUN_007d1530(aiStack_8);
      FUN_007d12a0(iVar10);
      FUN_007d05b0(iVar10);
      return iVar3;
    }
    if (0 < *unaff_ESI) {
      iVar9 = 0;
      local_10 = 0;
      do {
        iVar3 = *(int *)(unaff_ESI[1] + 4 + iVar9);
        if (((iVar3 != 0) && (iVar6 = FUN_007db270(iVar3), iVar6 != 0)) &&
           (iVar3 = FUN_007dc020(iVar3,iVar10), iVar3 != 0)) {
          FUN_007d1530(aiStack_8);
          FUN_007d05b0(iVar10);
          return iVar3;
        }
        local_10 = local_10 + 1;
        iVar9 = iVar9 + 0x70;
      } while (local_10 < *unaff_ESI);
      uVar8 = local_c;
    }
    FUN_007d1530(aiStack_8);
    FUN_007d12a0(iVar10);
    FUN_007d05b0(iVar10);
    local_10 = FUN_004d8fb0(uVar8);
    if ((local_10 == 0) && (iVar10 = 0, 0 < *unaff_ESI)) {
      iVar9 = 0;
      do {
        iVar3 = *(int *)(iVar9 + 4 + unaff_ESI[1]);
        if (iVar3 != 0) {
          FUN_007d6f20(iVar3);
        }
        iVar10 = iVar10 + 1;
        iVar9 = iVar9 + 0x70;
      } while (iVar10 < *unaff_ESI);
      return 0;
    }
  }
  return local_10;
}


// ==== FUN_007dd100 @ 0x007dd100 ====

void FUN_007dd100(void)

{
  int *piVar1;
  int *unaff_ESI;
  
  piVar1 = *(int **)(*unaff_ESI + 0x48);
  if (piVar1 != (int *)0x0) {
    do {
      if (((piVar1 != unaff_ESI) && (piVar1[0x16] == -0x420df25d)) && (-1 < piVar1[0x21])) {
        FUN_007dcc80();
        *(undefined1 *)((int)piVar1 + 0x23f) = 1;
      }
      piVar1 = (int *)piVar1[2];
    } while (piVar1 != (int *)0x0);
  }
  return;
}


// ==== FUN_007dd140 @ 0x007dd140 ====

void FUN_007dd140(int *param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar1 = param_1;
  if (0 < param_1[1]) {
    do {
      piVar2 = piVar1 + 2;
      if (((0x1f < iVar3) || ((param_2 & 1 << ((byte)iVar3 & 0x1f)) == 0)) && (*piVar2 != 0)) {
        if ((code *)piVar1[3] != (code *)0x0) {
          (*(code *)piVar1[3])(*piVar2);
        }
        *piVar2 = 0;
      }
      iVar3 = iVar3 + 1;
      piVar1 = piVar2;
    } while (iVar3 < param_1[1]);
  }
  return;
}


// ==== FUN_007dd1a0 @ 0x007dd1a0 ====

int FUN_007dd1a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  puVar2 = param_1;
  if (*(char *)((int)param_1 + 0x1f) != '\0') {
    puVar1 = param_1 + 10;
    if (*(char *)(param_1 + 8) == '\0') {
      uVar4 = *param_1;
      uVar7 = 0;
      uVar6 = 8;
      puVar5 = puVar1;
    }
    else {
      uVar7 = param_1[0xb];
      uVar6 = *puVar1;
      uVar4 = *param_1;
      puVar5 = (undefined4 *)0x0;
    }
    iVar3 = FUN_007d7880(uVar4,puVar5,uVar6,uVar7,&param_1);
    if (iVar3 != 0) {
      return iVar3;
    }
    *(undefined1 *)puVar2[0x12] = 0;
    puVar2[2] = *puVar1;
    puVar2[3] = puVar2[0xb];
    *(bool *)((int)puVar2 + 0x19) = param_1 == (undefined4 *)0x0;
    if (((int)param_1 < 0) && (iVar3 = FUN_007d7b80(*puVar2,&param_1), iVar3 != 0)) {
      return iVar3;
    }
    DAT_00b5c4dc = DAT_00b5c4dc + 1;
    *(undefined1 *)((int)puVar2 + 0x1f) = 0;
    *(undefined1 *)(puVar2 + 0x15) = 0;
  }
  return 0;
}


// ==== FUN_007dd230 @ 0x007dd230 ====

int FUN_007dd230(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = param_1[3];
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 4) != 0) {
      uVar1 = param_1[1];
      uVar2 = *param_1;
      if (((int)uVar1 < 1) && ((int)uVar1 < 0)) {
        bVar3 = uVar2 != 0;
        uVar2 = -uVar2;
        uVar1 = -(uVar1 + bVar3);
      }
      if (uVar1 == 0) {
        if (uVar2 < 0x80) {
          return 1;
        }
        if (uVar2 < 0x8000) {
          return 2;
        }
        if (uVar2 < 0x800000) {
          return 3;
        }
        if (uVar2 < 0x80000000) {
          return 4;
        }
      }
      if (uVar1 < 0x1000) {
        return 5;
      }
      return 6;
    }
    if ((uVar1 & 8) != 0) {
      return 7;
    }
    if ((uVar1 & 2) != 0) {
      return param_1[2] * 2 + 0xd;
    }
    if ((uVar1 & 0x10) != 0) {
      return param_1[2] * 2 + 0xc;
    }
  }
  return 0;
}


// ==== FUN_007dd2f0 @ 0x007dd2f0 ====

uint FUN_007dd2f0(uint param_1)

{
  if (param_1 < 0xc) {
    return (uint)(byte)(&DAT_00a00c04)[param_1];
  }
  return param_1 - 0xc >> 1;
}


// ==== FUN_007dd310 @ 0x007dd310 ====

uint FUN_007dd310(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar1 = FUN_007dd230(param_2);
  if (uVar1 == 0) {
    return 0;
  }
  if (7 < uVar1) {
    if (uVar1 < 0xc) {
      uVar1 = (uint)(byte)(&DAT_00a00c04)[uVar1];
    }
    else {
      uVar1 = uVar1 - 0xc >> 1;
    }
    puVar5 = (undefined4 *)param_2[6];
    for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_1 = *puVar5;
      puVar5 = puVar5 + 1;
      param_1 = param_1 + 1;
    }
    for (uVar3 = uVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)param_1 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
    return uVar1;
  }
  if (uVar1 == 7) {
    uVar3 = param_2[4];
    uVar4 = param_2[5];
  }
  else {
    uVar3 = *param_2;
    uVar4 = param_2[1];
    if (0xb < uVar1) {
      uVar1 = uVar1 - 0xc >> 1;
      goto LAB_007dd339;
    }
  }
  uVar1 = (uint)(byte)(&DAT_00a00c04)[uVar1];
LAB_007dd339:
  uVar2 = uVar1;
  if (uVar1 == 0) {
    return 0;
  }
  do {
    uVar1 = uVar1 - 1;
    *(char *)(uVar1 + (int)param_1) = (char)uVar3;
    uVar3 = uVar3 >> 8 | uVar4 << 0x18;
    uVar4 = uVar4 >> 8;
  } while (uVar1 != 0);
  return uVar2;
}


// ==== FUN_007dd3a0 @ 0x007dd3a0 ====

uint FUN_007dd3a0(char *param_1,uint param_2,int *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int3 iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  switch(param_2) {
  case 0:
  case 8:
  case 9:
  case 10:
  case 0xb:
    *(undefined2 *)(param_3 + 3) = 1;
    return 0;
  case 1:
    cVar1 = *param_1;
    *param_3 = (int)cVar1;
    param_3[1] = (int)cVar1 >> 0x1f;
    *(undefined2 *)(param_3 + 3) = 4;
    return 1;
  case 2:
    cVar1 = *param_1;
    cVar2 = param_1[1];
    *param_3 = (int)CONCAT11(cVar1,cVar2);
    param_3[1] = (int)CONCAT11(cVar1,cVar2) >> 0x1f;
    *(undefined2 *)(param_3 + 3) = 4;
    return 2;
  case 3:
    iVar6 = (int)CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]);
    *param_3 = iVar6;
    param_3[1] = iVar6 >> 0x1f;
    *(undefined2 *)(param_3 + 3) = 4;
    return 3;
  case 4:
    iVar5 = CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]);
    *param_3 = CONCAT31(iVar5,param_1[3]);
    param_3[1] = (int)iVar5 >> 0x17;
    *(undefined2 *)(param_3 + 3) = 4;
    return 4;
  case 5:
    cVar1 = param_1[4];
    cVar2 = param_1[2];
    cVar3 = param_1[3];
    cVar4 = param_1[5];
    param_3[1] = (int)CONCAT11(*param_1,param_1[1]);
    *param_3 = CONCAT31(CONCAT21(CONCAT11(cVar2,cVar3),cVar1),cVar4);
    *(undefined2 *)(param_3 + 3) = 4;
    return 6;
  case 6:
  case 7:
    break;
  default:
    uVar8 = param_2 - 0xc >> 1;
    param_3[6] = (int)param_1;
    param_3[2] = uVar8;
    param_3[7] = 0;
    *(ushort *)(param_3 + 3) = (-(ushort)((param_2 & 1) != 0) & 0xfff2) + 0x110;
    return uVar8;
  }
  iVar6 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
  iVar7 = CONCAT31(CONCAT21(CONCAT11(param_1[4],param_1[5]),param_1[6]),param_1[7]);
  if (param_2 == 6) {
    param_3[1] = iVar6;
    *param_3 = iVar7;
    *(undefined2 *)(param_3 + 3) = 4;
    return 8;
  }
  *(ulonglong *)(param_3 + 4) = CONCAT44(iVar6,iVar7);
  *(undefined2 *)(param_3 + 3) = 8;
  return 8;
}


// ==== FUN_007dd5c0 @ 0x007dd5c0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007dd5c0(undefined1 *param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int local_a4;
  uint local_a0;
  undefined4 *local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  int local_88;
  undefined1 local_84 [12];
  byte local_78;
  undefined1 local_75;
  undefined1 local_44 [12];
  byte local_38;
  undefined1 local_35;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  local_75 = *param_1;
  iVar5 = 0;
  local_a4 = 0;
  local_35 = local_75;
  uVar1 = FUN_007d1120(param_3,&local_98);
  uVar7 = local_98;
  local_a0 = FUN_007d1120(param_5,&local_94);
  local_88 = *(int *)(param_1 + 4);
  uVar6 = local_94;
  if (uVar1 < local_98) {
    local_9c = (undefined4 *)(param_1 + 0xc);
    do {
      if (local_94 <= local_a0) break;
      iVar2 = FUN_007d1120(uVar1 + param_3,&local_90);
      uVar1 = uVar1 + iVar2;
      if (param_2 <= uVar7) {
        if (local_90 < 0xc) {
          uVar3 = (uint)(byte)(&DAT_00a00c04)[local_90];
        }
        else {
          uVar3 = local_90 - 0xc >> 1;
        }
        if (uVar3 != 0) break;
      }
      iVar2 = FUN_007d1120(local_a0 + param_5,&local_8c);
      local_a0 = local_a0 + iVar2;
      if (param_4 <= uVar6) {
        if (local_8c < 0xc) {
          uVar3 = (uint)(byte)(&DAT_00a00c04)[local_8c];
        }
        else {
          uVar3 = local_8c - 0xc >> 1;
        }
        if (uVar3 != 0) break;
      }
      iVar5 = FUN_007dd3a0(uVar7 + param_3,local_90,local_84);
      uVar7 = uVar7 + iVar5;
      iVar5 = FUN_007dd3a0(param_5 + uVar6,local_8c,local_44);
      uVar6 = uVar6 + iVar5;
      if (local_a4 < local_88) {
        uVar4 = *local_9c;
      }
      else {
        uVar4 = 0;
      }
      iVar5 = FUN_007d03a0(local_84,local_44,uVar4);
      if ((local_78 & 0x40) != 0) {
        FUN_007cf9b0(local_84);
      }
      if ((local_38 & 0x40) != 0) {
        FUN_007cf9b0(local_44);
      }
      if (iVar5 != 0) goto LAB_007dd7d2;
      local_a4 = local_a4 + 1;
      local_9c = local_9c + 1;
    } while (uVar1 < local_98);
  }
  if (param_1[1] == '\0') {
    if (uVar7 < param_2) {
      iVar5 = 1;
      goto LAB_007dd7d2;
    }
    if (param_4 <= uVar6) goto LAB_007dd7d2;
  }
  iVar5 = -1;
LAB_007dd7d2:
  if (((*(int *)(param_1 + 8) != 0) && (local_a4 < *(int *)(param_1 + 4))) &&
     (*(char *)(*(int *)(param_1 + 8) + local_a4) != '\0')) {
    iVar5 = -iVar5;
  }
  return iVar5;
}


// ==== FUN_007dd810 @ 0x007dd810 ====

uint FUN_007dd810(undefined4 param_1,int param_2)

{
  int iVar1;
  uint local_4;
  
  iVar1 = param_2;
  FUN_007d1120(param_2,&param_2);
  FUN_007d1120(param_2 + -1 + iVar1,&local_4);
  if (local_4 < 0xc) {
    return (uint)(byte)(&DAT_00a00c04)[local_4];
  }
  return local_4 - 0xc >> 1;
}


// ==== FUN_007dd860 @ 0x007dd860 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007dd860(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  int local_94;
  uint local_90;
  int local_8c;
  int local_88;
  undefined1 local_84 [8];
  int local_7c;
  int local_6c;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  FUN_007d70f0(param_1,&local_8c);
  if ((local_88 < 1) && ((local_88 < 0 || (local_8c == 0)))) {
    return 0xb;
  }
  iVar1 = FUN_007cfd00(param_1,0,local_8c,1,local_84);
  if (iVar1 == 0) {
    FUN_007d1120(local_6c,&local_94);
    FUN_007d1120(local_6c + -1 + local_94,&local_90);
    if (local_90 < 0xc) {
      uVar2 = (uint)(byte)(&DAT_00a00c04)[local_90];
    }
    else {
      uVar2 = local_90 - 0xc >> 1;
    }
    FUN_007dd3a0((local_7c - uVar2) + local_6c,local_90,&local_44);
    *param_2 = local_44;
    param_2[1] = local_40;
    FUN_007cf9b0(local_84);
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_007dd960 @ 0x007dd960 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007dd960(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_4c;
  int local_48;
  undefined1 local_44 [8];
  int local_3c;
  undefined4 local_2c;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  FUN_007d70f0(*param_1,&local_4c);
  if ((local_48 < 1) && ((local_48 < 0 || (local_4c == 0)))) {
    *param_4 = 0;
    return 0;
  }
  iVar1 = FUN_007cfd00(*param_1,0,local_4c,1,local_44);
  if (iVar1 == 0) {
    iVar1 = FUN_007dd810(local_3c,local_2c);
    uVar2 = FUN_007dd5c0(param_1[0x13],local_3c - iVar1,local_2c,param_2,param_3);
    *param_4 = uVar2;
    FUN_007cf9b0(local_44);
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_007dda20 @ 0x007dda20 ====

void FUN_007dda20(int param_1,int param_2)

{
  *(int *)(param_1 + 0x34) = param_2;
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + param_2;
  return;
}


// ==== FUN_007dda40 @ 0x007dda40 ====

void FUN_007dda40(int param_1)

{
  *(undefined1 *)(param_1 + 0x23e) = 1;
  return;
}


// ==== FUN_007dda50 @ 0x007dda50 ====

void FUN_007dda50(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x48); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
    *(undefined1 *)(iVar1 + 0x240) = 1;
  }
  return;
}


// ==== FUN_007dda70 @ 0x007dda70 ====

undefined4 FUN_007dda70(undefined4 *param_1)

{
  return *param_1;
}


// ==== FUN_007dda80 @ 0x007dda80 ====

int FUN_007dda80(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 0x10) = iVar2 + 1;
  FUN_007dc0c0();
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar2 = 0;
  }
  else {
    puVar1 = (undefined1 *)(*(int *)(param_1 + 0x18) + iVar2 * 0x14);
    *puVar1 = param_2;
    *(undefined4 *)(puVar1 + 4) = param_3;
    *(undefined4 *)(puVar1 + 8) = param_4;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    *(undefined4 *)(puVar1 + 0x10) = 0;
  }
  FUN_007dc430(param_1,iVar2,param_5,param_6);
  return iVar2;
}


// ==== FUN_007ddae0 @ 0x007ddae0 ====

int FUN_007ddae0(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 local_4;
  
  puVar3 = param_2;
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  piVar1 = param_2 + 4;
  iVar5 = *piVar1;
  if (iVar5 == 0) {
    if (param_2[1] != 0) {
      FUN_007dcb40(param_2[1],param_2);
    }
  }
  else {
    iVar4 = FUN_007d7800(iVar5,&param_2);
    while (param_2 == (undefined4 *)0x0) {
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = FUN_007d73b0(iVar5,0,4,&local_4);
      if (iVar4 != 0) {
        return iVar4;
      }
      FUN_007dcb40(local_4,puVar3);
      iVar4 = FUN_007d7b80(iVar5,&param_2);
    }
    if (iVar4 != 0) {
      return iVar4;
    }
    FUN_007d70a0(iVar5);
    FUN_007da600(puVar3[3],puVar3[5]);
  }
  if (param_1 == 0) {
    if (puVar3[3] != 0) {
      FUN_007db2b0(puVar3[3]);
      puVar3[3] = 0;
      puVar3[5] = 0;
    }
    *piVar1 = 0;
  }
  else {
    puVar2 = puVar3 + 3;
    if (puVar3[3] == 0) {
      iVar5 = FUN_007cd6c0(param_1,s__memory__009ffce0,0,500,puVar2);
      if (iVar5 != 0) {
        return iVar5;
      }
      FUN_007d69e0(*puVar2,1);
      iVar5 = FUN_007db850(*puVar2,puVar3 + 5,0);
      if (iVar5 != 0) {
        return iVar5;
      }
    }
    iVar5 = FUN_007db700(*puVar2,puVar3[5],1,FUN_007dd5c0,param_3,piVar1);
    if (iVar5 != 0) {
      return iVar5;
    }
  }
  if (puVar3[2] != 0) {
    FUN_007d05b0(puVar3[2]);
    puVar3[2] = 0;
  }
  puVar3[1] = 0;
  *puVar3 = 0;
  *(undefined1 *)(puVar3 + 6) = 0;
  return 0;
}


// ==== FUN_007ddc40 @ 0x007ddc40 ====

void FUN_007ddc40(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(in_EAX + 0x28);
  iVar3 = 0;
  if (iVar4 != 0) {
    iVar2 = (*(int *)(in_EAX + 0x2c) - iVar4 >> 6) + 1;
    if (0 < iVar2) {
      do {
        FUN_007cf9b0(iVar4);
        iVar4 = iVar4 + 0x40;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    *(int *)(in_EAX + 0x2c) = *(int *)(in_EAX + 0x28) + -0x40;
  }
  FUN_007dcc80();
  iVar4 = *(int *)(in_EAX + 0x60);
  iVar2 = *(int *)(in_EAX + 0x5c);
  if ((iVar4 != 0) && (0 < iVar2)) {
    do {
      FUN_007cf9b0(iVar4);
      iVar4 = iVar4 + 0x40;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar4 = *(int *)(in_EAX + 0x74);
  if (*(int *)(in_EAX + 0x74) != 0) {
    do {
      iVar2 = *(int *)(iVar4 + 0xc);
      FUN_007d05b0(iVar4);
      iVar4 = iVar2;
    } while (iVar2 != 0);
    *(undefined4 *)(in_EAX + 0x74) = 0;
  }
  if (*(int *)(in_EAX + 0x80) != 0) {
    if (0 < *(int *)(in_EAX + 0x78)) {
      iVar4 = 0;
      do {
        iVar2 = *(int *)(iVar4 + 8 + *(int *)(in_EAX + 0x80));
        while (iVar2 != 0) {
          iVar1 = *(int *)(iVar2 + 0xc);
          FUN_007d05b0(iVar2);
          iVar2 = iVar1;
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar3 < *(int *)(in_EAX + 0x78));
    }
    FUN_007d05b0(*(undefined4 *)(in_EAX + 0x80));
  }
  FUN_007dcaf0();
  iVar4 = 0;
  if (0 < *(int *)(in_EAX + 100)) {
    iVar3 = 0;
    do {
      FUN_007ddae0(0,*(int *)(in_EAX + 0x68) + iVar3,0);
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x1c;
    } while (iVar4 < *(int *)(in_EAX + 100));
  }
  *(undefined4 *)(in_EAX + 0x80) = 0;
  *(undefined4 *)(in_EAX + 0x7c) = 0;
  *(undefined4 *)(in_EAX + 0x78) = 0;
  FUN_007d05b0(*(undefined4 *)(in_EAX + 0x238));
  *(undefined4 *)(in_EAX + 0x238) = 0;
  return;
}


// ==== FUN_007ddd70 @ 0x007ddd70 ====

undefined4 FUN_007ddd70(code *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  puVar4 = (undefined4 *)param_1;
  piVar1 = (int *)((int)param_1 + 0x58);
  piVar2 = *(int **)param_1;
  param_1 = (code *)0x0;
  if (*piVar1 != -0x420df25d) {
    return 0;
  }
  FUN_007dcc80();
  if (-1 < (int)puVar4[0x21]) {
    if ((*(char *)((int)piVar2 + 0x11) == '\0') || (piVar2[0x13] != 1)) {
      if ((puVar4[0x22] == 0) || (puVar4[0x24] == 3)) {
        param_1 = FUN_007d7000;
      }
      else if (puVar4[0x24] == 2) {
        param_1 = FUN_007d7030;
      }
      else {
        param_1 = FUN_007d6f50;
        *(undefined1 *)((int)piVar2 + 0x11) = 1;
        FUN_007dd100();
      }
    }
    else if ((puVar4[0x22] == 0) || (puVar4[0x24] == 3)) {
      iVar6 = FUN_007dcdb0();
      if (iVar6 == 5) {
        return 5;
      }
      if (iVar6 != 0) {
        puVar4[0x22] = iVar6;
        param_1 = FUN_007d6f50;
      }
    }
    else {
      param_1 = FUN_007d6f50;
    }
  }
  iVar6 = 0;
  if (param_1 != (code *)0x0) {
    iVar7 = 0;
    for (; iVar6 < *piVar2; iVar6 = iVar6 + 1) {
      iVar3 = *(int *)(piVar2[1] + 4 + iVar7);
      if ((iVar3 != 0) && (uVar5 = (*param_1)(iVar3), puVar4[0x22] == 0)) {
        puVar4[0x22] = uVar5;
      }
      iVar7 = iVar7 + 0x70;
    }
  }
  if ((*(char *)((int)puVar4 + 0x23e) != '\0') && (-1 < (int)puVar4[0x21])) {
    if ((param_1 == (code *)0x0) || (param_1 == FUN_007d7000)) {
      iVar6 = puVar4[0x91];
      piVar2[0xd] = iVar6;
      piVar2[0xe] = piVar2[0xe] + iVar6;
    }
    else {
      piVar2[0xd] = 0;
    }
    puVar4[0x91] = 0;
  }
  if (puVar4[0x22] == 0) {
    if ((*(byte *)(piVar2 + 2) & 0x10) != 0) {
      FUN_007d2570(piVar2);
    }
  }
  else {
    FUN_007d4220(piVar2);
  }
  if (-1 < (int)puVar4[0x21]) {
    piVar2[0x13] = piVar2[0x13] + -1;
  }
  puVar4[0x16] = 0x519c2973;
  return 0;
}


// ==== FUN_007ddef0 @ 0x007ddef0 ====

undefined4 FUN_007ddef0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1[0x16] != -0x420df25d) && (param_1[0x16] != 0x519c2973)) {
    FUN_007d07b0(*param_1,0x15,0);
    return 0x15;
  }
  FUN_007ddd70(param_1);
  if ((int)param_1[0x21] < 0) {
    iVar2 = param_1[0x22];
    if ((iVar2 == 0) || (*(char *)(param_1 + 0x90) == '\0')) goto LAB_007ddfa4;
    uVar1 = *param_1;
  }
  else {
    if (param_1[0x8e] != 0) {
      FUN_007d07b0(*param_1,param_1[0x22],&DAT_009d5e14,param_1[0x8e]);
      FUN_007d05b0(param_1[0x8e]);
      param_1[0x8e] = 0;
      goto LAB_007ddfa4;
    }
    iVar2 = param_1[0x22];
    if (iVar2 == 0) {
      uVar1 = *param_1;
      iVar2 = 0;
    }
    else {
      uVar1 = *param_1;
    }
  }
  FUN_007d07b0(uVar1,iVar2,0);
LAB_007ddfa4:
  FUN_007ddc40();
  param_1[0x16] = 0x26bceaa5;
  *(undefined1 *)((int)param_1 + 0x23f) = 0;
  if (param_1[0x22] == 0x11) {
    FUN_007d3fc0(*param_1,0);
  }
  return param_1[0x22];
}


// ==== FUN_007ddfe0 @ 0x007ddfe0 ====

void FUN_007ddfe0(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar3 = param_1;
  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    FUN_007ddc40();
    if (param_1[1] == 0) {
      *(int *)(*param_1 + 0x48) = param_1[2];
    }
    else {
      *(int *)(param_1[1] + 8) = param_1[2];
    }
    if (param_1[2] != 0) {
      *(int *)(param_1[2] + 4) = param_1[1];
    }
    if (param_1[6] != 0) {
      piVar1 = param_1 + 4;
      param_1 = (int *)0x0;
      if (0 < *piVar1) {
        do {
          iVar4 = *(int *)(piVar3[6] + 0x10 + iVar5);
          iVar6 = piVar3[6] + iVar5;
          if ((iVar4 == -1) || (iVar4 == -6)) {
            FUN_007d05b0(*(undefined4 *)(iVar6 + 0xc));
          }
          if (*(int *)(iVar6 + 0x10) == -7) {
            uVar2 = *(undefined4 *)(iVar6 + 0xc);
            FUN_007dd140(uVar2,0);
            FUN_007d05b0(uVar2);
          }
          if (*(int *)(iVar6 + 0x10) == -8) {
            FUN_007cfe40(*(undefined4 *)(iVar6 + 0xc));
          }
          param_1 = (int *)((int)param_1 + 1);
          iVar5 = iVar5 + 0x14;
        } while ((int)param_1 < piVar3[4]);
      }
      FUN_007d05b0(piVar3[6]);
    }
    iVar5 = piVar3[0x13];
    iVar4 = piVar3[0x12];
    if ((iVar5 != 0) && (0 < iVar4)) {
      do {
        FUN_007cf9b0(iVar5);
        iVar5 = iVar5 + 0x40;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    FUN_007d05b0(piVar3[9]);
    FUN_007d05b0(piVar3[10]);
    iVar5 = piVar3[0xd];
    iVar4 = piVar3[0x8b] << 1;
    if ((iVar5 != 0) && (0 < iVar4)) {
      do {
        FUN_007cf9b0(iVar5);
        iVar5 = iVar5 + 0x40;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    FUN_007d05b0(piVar3[0xd]);
    piVar3[0x16] = -0x49f93c38;
    FUN_007d05b0(piVar3);
  }
  return;
}


// ==== FUN_007de120 @ 0x007de120 ====

undefined4 FUN_007de120(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x58);
  uVar2 = 0;
  if ((iVar1 == -0x420df25d) || (iVar1 == 0x519c2973)) {
    uVar2 = FUN_007ddef0(param_1);
  }
  else if (iVar1 != 0x26bceaa5) {
    return 0x15;
  }
  FUN_007ddfe0(param_1);
  return uVar2;
}


// ==== FUN_007de170 @ 0x007de170 ====

void FUN_007de170(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  char *unaff_EBX;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    do {
      cVar1 = *unaff_EBX;
      unaff_EBX = unaff_EBX + 1;
    } while (cVar1 != '\0');
  }
  if (*(int *)(unaff_ESI + 0x60) != 0) {
    iVar2 = FUN_007d06a0();
    if (iVar2 == 0) {
      return;
    }
    (**(code **)(unaff_ESI + 0x60))(*(undefined4 *)(unaff_ESI + 0x68));
    FUN_007d05b0(iVar2);
  }
  if (*(int *)(unaff_ESI + 100) != 0) {
    uVar3 = FUN_007cd140();
    FUN_007cfe10(uVar3,0xffffffff);
    iVar2 = FUN_007d0100(uVar3,(DAT_009ff8b0 == '\0') + '\x02');
    if (iVar2 != 0) {
      (**(code **)(unaff_ESI + 100))(*(undefined4 *)(unaff_ESI + 0x68));
    }
  }
  return;
}


// ==== FUN_007de210 @ 0x007de210 ====

int * FUN_007de210(int param_1,uint param_2,int param_3)

{
  char cVar1;
  char *in_EAX;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  int *piVar6;
  
  if ((int)param_2 < 0) {
    pcVar5 = in_EAX;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    param_2 = (int)pcVar5 - (int)(in_EAX + 1);
  }
  piVar2 = (int *)FUN_007d1ed0(param_1 + 0xa8);
  if (((piVar2 == (int *)0x0) && (param_3 != 0)) &&
     (piVar2 = (int *)FUN_007d0550(param_2 + 0x31), piVar2 != (int *)0x0)) {
    piVar6 = piVar2 + 0xc;
    *piVar2 = (int)piVar6;
    *(undefined1 *)(piVar2 + 1) = 1;
    piVar2[4] = (int)piVar6;
    *(undefined1 *)(piVar2 + 5) = 2;
    piVar2[8] = (int)piVar6;
    *(undefined1 *)(piVar2 + 9) = 3;
    for (uVar4 = param_2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *piVar6 = *(undefined4 *)in_EAX;
      in_EAX = in_EAX + 4;
      piVar6 = (int *)((int)piVar6 + 4);
    }
    for (uVar4 = param_2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)piVar6 = *in_EAX;
      in_EAX = in_EAX + 1;
      piVar6 = (int *)((int)piVar6 + 1);
    }
    *(undefined1 *)(*piVar2 + param_2) = 0;
    uVar3 = FUN_007d1f20(param_1 + 0xa8,*piVar2,param_2,piVar2);
    FUN_007d05b0(uVar3);
  }
  return piVar2;
}


// ==== FUN_007de2b0 @ 0x007de2b0 ====

int FUN_007de2b0(undefined4 param_1,byte param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_007de210(param_1,param_4,param_5);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = iVar1 + -0x10 + (uint)param_2 * 0x10;
  }
  return iVar2;
}


// ==== FUN_007de2e0 @ 0x007de2e0 ====

int * FUN_007de2e0(int param_1,undefined4 *param_2,uint param_3,int param_4,char param_5,int param_6
                  )

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  uint local_4;
  
  piVar6 = (int *)0x0;
  local_4 = 0;
  if (param_4 < -1) {
    param_4 = -1;
  }
  piVar3 = (int *)FUN_007d1ed0(param_1 + 0x94,param_2,param_3);
  piVar4 = piVar3;
  do {
    if (piVar4 == (int *)0x0) {
      if ((param_6 != 0) && (local_4 < 6)) {
        piVar6 = (int *)FUN_007d0550(param_3 + 0x25);
        if (piVar6 == (int *)0x0) {
          return (int *)0x0;
        }
        *(char *)(piVar6 + 2) = param_5;
        piVar6[1] = param_4;
        uVar5 = param_3 >> 2;
        piVar6[4] = (int)piVar3;
        *piVar6 = (int)(piVar6 + 9);
        piVar4 = piVar6 + 9;
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          *piVar4 = *param_2;
          param_2 = param_2 + 1;
          piVar4 = piVar4 + 1;
        }
        for (uVar5 = param_3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)piVar4 = *(undefined1 *)param_2;
          param_2 = (undefined4 *)((int)param_2 + 1);
          piVar4 = (undefined4 *)((int)piVar4 + 1);
        }
        *(undefined1 *)(param_3 + *piVar6) = 0;
        piVar4 = (int *)FUN_007d1f20(param_1 + 0x94,*piVar6,param_3,piVar6);
        if (piVar6 == piVar4) {
          FUN_007d05b0(piVar6);
          return (int *)0x0;
        }
      }
      if ((piVar6 == (int *)0x0) || (((piVar6[6] == 0 && (piVar6[5] == 0)) && (param_6 == 0)))) {
        return (int *)0x0;
      }
      return piVar6;
    }
    iVar2 = piVar4[1];
    if (((iVar2 == -1) || (iVar2 == param_4)) || (param_4 == -1)) {
      uVar5 = 1;
      if ((iVar2 == param_4) || (param_4 == -1)) {
        uVar5 = 4;
      }
      cVar1 = (char)piVar4[2];
      if (param_5 == cVar1) {
        uVar5 = uVar5 + 2;
      }
      else if (param_5 == '\x02') {
        if (cVar1 == '\x03') {
LAB_007de369:
          uVar5 = uVar5 + 1;
        }
      }
      else if ((param_5 == '\x03') && (cVar1 == '\x02')) goto LAB_007de369;
      if (local_4 < uVar5) {
        piVar6 = piVar4;
        local_4 = uVar5;
      }
    }
    piVar4 = (int *)piVar4[4];
  } while( true );
}


// ==== FUN_007de420 @ 0x007de420 ====

undefined4 FUN_007de420(int param_1,undefined4 *param_2)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  
  pcVar3 = (char *)*param_2;
  pcVar4 = pcVar3;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar8 = 0;
  while( true ) {
    bVar2 = (&DAT_00a00c58)[iVar8];
    iVar6 = (int)pcVar4 - (int)(pcVar3 + 1);
    if ((int)pcVar4 - (int)(pcVar3 + 1) < 0) {
      pcVar5 = pcVar3;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      iVar6 = (int)pcVar5 - (int)(pcVar3 + 1);
    }
    iVar6 = FUN_007d1ed0(param_1 + 0xa8,pcVar3,iVar6);
    puVar7 = (undefined4 *)0x0;
    if (iVar6 != 0) {
      puVar7 = (undefined4 *)(iVar6 + -0x10 + (uint)bVar2 * 0x10);
    }
    if (puVar7[3] != 0) break;
    iVar8 = iVar8 + 1;
    if (2 < iVar8) {
      return 1;
    }
  }
  *param_2 = *puVar7;
  param_2[1] = puVar7[1];
  param_2[2] = puVar7[2];
  param_2[3] = puVar7[3];
  return 0;
}


// ==== FUN_007de4d0 @ 0x007de4d0 ====

int FUN_007de4d0(int param_1,int param_2,char *param_3,int param_4)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  
  if (param_2 == 0) {
    bVar1 = *(byte *)(param_1 + 0x10);
    iVar4 = param_4;
    if (param_4 < 0) {
      pcVar3 = param_3;
      do {
        cVar2 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar2 != '\0');
      iVar4 = (int)pcVar3 - (int)(param_3 + 1);
    }
    iVar4 = FUN_007d1ed0(param_1 + 0xa8,param_3,iVar4);
    param_2 = 0;
    if (iVar4 != 0) {
      param_2 = iVar4 + -0x10 + (uint)bVar1 * 0x10;
    }
    if (param_2 != 0) goto LAB_007de530;
  }
  else {
LAB_007de530:
    if (*(int *)(param_2 + 0xc) != 0) goto LAB_007de57c;
  }
  FUN_007de170();
  bVar1 = *(byte *)(param_1 + 0x10);
  if (param_4 < 0) {
    pcVar3 = param_3;
    do {
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    param_4 = (int)pcVar3 - (int)(param_3 + 1);
  }
  iVar4 = FUN_007d1ed0(param_1 + 0xa8,param_3,param_4);
  param_2 = 0;
  if (iVar4 != 0) {
    param_2 = iVar4 + -0x10 + (uint)bVar1 * 0x10;
  }
LAB_007de57c:
  if (((param_2 == 0) || (*(int *)(param_2 + 0xc) != 0)) ||
     (iVar4 = FUN_007de420(param_1,param_2), iVar4 == 0)) {
    return param_2;
  }
  return 0;
}


// ==== FUN_007de5b0 @ 0x007de5b0 ====

undefined4 FUN_007de5b0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = *param_2;
    iVar2 = FUN_007de4d0(*param_1,param_2,uVar1,0xffffffff);
    if (iVar2 == 0) {
      if (param_1[6] == 0) {
        FUN_007d0820(param_1,s_no_such_collation_sequence___s_00a00c5c,uVar1);
      }
      param_1[6] = param_1[6] + 1;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007de600 @ 0x007de600 ====

void FUN_007de600(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_c;
  int local_8;
  
  if (param_2 != 0) {
    iVar2 = FUN_007ce1c0(param_1);
    uVar1 = *(undefined4 *)(param_1 + 0x54);
    local_8 = 0;
    iVar3 = FUN_007cdf80(*param_3);
    if (iVar3 != 5) {
      iVar3 = 1;
      if (1 < param_2) {
        local_c = 0;
        do {
          iVar4 = FUN_007cdf80(param_3[iVar3]);
          if (iVar4 == 5) {
            return;
          }
          uVar5 = FUN_007d03a0(*(undefined4 *)(local_c + (int)param_3),param_3[iVar3],uVar1);
          if (-1 < (int)(uVar5 ^ -(uint)(iVar2 != 0))) {
            local_c = iVar3 * 4;
            local_8 = iVar3;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_2);
      }
      FUN_007ce090(param_1,param_3[local_8]);
    }
  }
  return;
}


// ==== FUN_007de6d0 @ 0x007de6d0 ====

void FUN_007de6d0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  puVar2 = (undefined *)0x0;
  uVar1 = FUN_007cdf80(*param_3);
  switch(uVar1) {
  case 1:
    FUN_007ce030(param_1,s_integer_00a00ef0,0xffffffff,0);
    return;
  case 2:
    FUN_007ce030(param_1,&DAT_00a00ee0,0xffffffff,0);
    return;
  case 3:
    FUN_007ce030(param_1,&DAT_00a00ee8,0xffffffff,0);
    return;
  case 4:
    puVar2 = &DAT_00a00ed8;
    break;
  case 5:
    FUN_007ce030(param_1,&DAT_009fef08,0xffffffff,0);
    return;
  }
  FUN_007ce030(param_1,puVar2,0xffffffff,0);
  return;
}


// ==== FUN_007de810 @ 0x007de810 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007de810(undefined4 param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_007cdf80();
  if (iVar1 == 1) {
    thunk_FUN_007cff80();
    FUN_007ce000();
    return;
  }
  if (iVar1 == 5) {
    FUN_007ce020();
    return;
  }
  fVar2 = (float10)thunk_FUN_007d0050();
  if (fVar2 < (float10)_DAT_0099d098) {
    fVar2 = fVar2 * (float10)_DAT_009fd350;
  }
  FUN_007cdf90(param_1,(double)fVar2);
  return;
}


// ==== FUN_007de8a0 @ 0x007de8a0 ====

void FUN_007de8a0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  
  pbVar2 = (byte *)FUN_007cdf50(*param_3);
  if (pbVar2 != (byte *)0x0) {
    iVar3 = thunk_FUN_007cff80(param_3[1]);
    iVar4 = thunk_FUN_007cff80(param_3[2]);
    bVar5 = *pbVar2;
    iVar7 = 0;
    if (bVar5 != 0) {
      pbVar6 = pbVar2;
      do {
        if ((bVar5 & 0xc0) != 0x80) {
          iVar7 = iVar7 + 1;
        }
        bVar5 = pbVar6[1];
        pbVar6 = pbVar6 + 1;
      } while (bVar5 != 0);
    }
    if (iVar3 < 0) {
      iVar3 = iVar3 + iVar7;
      if (iVar3 < 0) {
        iVar4 = iVar4 + iVar3;
        iVar3 = 0;
      }
    }
    else if (0 < iVar3) {
      iVar3 = iVar3 + -1;
    }
    if (iVar7 < iVar4 + iVar3) {
      iVar4 = iVar7 - iVar3;
    }
    iVar7 = 0;
    if (0 < iVar3) {
      do {
        if (pbVar2[iVar7] == 0) break;
        if ((pbVar2[iVar7] & 0xc0) == 0x80) {
          iVar3 = iVar3 + 1;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar3);
    }
    bVar5 = pbVar2[iVar7];
    while ((bVar5 != 0 && ((bVar5 & 0xc0) == 0x80))) {
      iVar8 = iVar7 + 1;
      iVar7 = iVar7 + 1;
      iVar3 = iVar3 + 1;
      bVar5 = pbVar2[iVar8];
    }
    iVar8 = iVar4 + iVar3;
    if (iVar7 < iVar8) {
      do {
        if (pbVar2[iVar7] == 0) break;
        if ((pbVar2[iVar7] & 0xc0) == 0x80) {
          iVar4 = iVar4 + 1;
          iVar8 = iVar8 + 1;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar8);
    }
    pbVar6 = pbVar2 + iVar7;
    bVar5 = *pbVar6;
    while ((bVar5 != 0 && ((bVar5 & 0xc0) == 0x80))) {
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      iVar4 = iVar4 + 1;
      bVar5 = *pbVar1;
    }
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    FUN_007ce030(param_1,pbVar2 + iVar3,iVar4,0xffffffff);
  }
  return;
}


// ==== FUN_007de9a0 @ 0x007de9a0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007de9a0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  char local_68 [100];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar2 = 0;
  if (param_2 == 2) {
    iVar2 = FUN_007cdf80();
    if (iVar2 == 5) {
      return;
    }
    iVar2 = thunk_FUN_007cff80();
    if (iVar2 < 0x1f) {
      if (iVar2 < 0) {
        iVar2 = 0;
      }
    }
    else {
      iVar2 = 0x1e;
    }
  }
  iVar1 = FUN_007cdf80();
  if (iVar1 != 5) {
    fVar3 = (float10)thunk_FUN_007d0050();
    _sprintf(local_68,&DAT_00a00ef8,iVar2,(double)fVar3);
    FUN_007ce030(param_1,local_68,0xffffffff,0xffffffff);
  }
  return;
}


// ==== FUN_007dea50 @ 0x007dea50 ====

void FUN_007dea50(undefined4 param_1,int param_2,undefined4 *param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  if ((0 < param_2) && (iVar2 = FUN_007cdf80(*param_3), iVar2 != 5)) {
    iVar2 = FUN_007cdf00(*param_3);
    pbVar3 = (byte *)FUN_007d0550(iVar2 + 1);
    if (pbVar3 != (byte *)0x0) {
      pbVar4 = (byte *)FUN_007cdf50(*param_3);
      pbVar5 = pbVar3;
      do {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + 1;
        *pbVar5 = bVar1;
        pbVar5 = pbVar5 + 1;
      } while (bVar1 != 0);
      if (*pbVar3 != 0) {
        pbVar5 = pbVar3;
        do {
          iVar2 = _toupper((uint)*pbVar5);
          *pbVar5 = (byte)iVar2;
          pbVar4 = pbVar5 + 1;
          pbVar5 = pbVar5 + 1;
        } while (*pbVar4 != 0);
      }
      FUN_007ce030(param_1,pbVar3,0xffffffff,0xffffffff);
      FUN_007d05b0(pbVar3);
    }
  }
  return;
}


// ==== FUN_007deae0 @ 0x007deae0 ====

void FUN_007deae0(undefined4 param_1,int param_2,undefined4 *param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  if ((0 < param_2) && (iVar2 = FUN_007cdf80(*param_3), iVar2 != 5)) {
    iVar2 = FUN_007cdf00(*param_3);
    pbVar3 = (byte *)FUN_007d0550(iVar2 + 1);
    if (pbVar3 != (byte *)0x0) {
      pbVar4 = (byte *)FUN_007cdf50(*param_3);
      pbVar5 = pbVar3;
      do {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + 1;
        *pbVar5 = bVar1;
        pbVar5 = pbVar5 + 1;
      } while (bVar1 != 0);
      if (*pbVar3 != 0) {
        pbVar5 = pbVar3;
        do {
          iVar2 = _tolower((uint)*pbVar5);
          *pbVar5 = (byte)iVar2;
          pbVar4 = pbVar5 + 1;
          pbVar5 = pbVar5 + 1;
        } while (*pbVar4 != 0);
      }
      FUN_007ce030(param_1,pbVar3,0xffffffff,0xffffffff);
      FUN_007d05b0(pbVar3);
    }
  }
  return;
}


// ==== FUN_007deb70 @ 0x007deb70 ====

void FUN_007deb70(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_2) {
    while (iVar1 = FUN_007cdf80(*(undefined4 *)(param_3 + iVar2 * 4)), iVar1 == 5) {
      iVar2 = iVar2 + 1;
      if (param_2 <= iVar2) {
        return;
      }
    }
    FUN_007ce090(param_1,*(undefined4 *)(param_3 + iVar2 * 4));
  }
  return;
}


// ==== FUN_007debb0 @ 0x007debb0 ====

void FUN_007debb0(undefined4 param_1)

{
  undefined4 local_4;
  
  FUN_007e6500(4,&local_4);
  FUN_007cdfe0(param_1,local_4);
  return;
}


// ==== FUN_007debd0 @ 0x007debd0 ====

void FUN_007debd0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_007ce1c0(param_1);
  uVar2 = FUN_007cd190(uVar1);
  FUN_007ce000(param_1,uVar2);
  return;
}


// ==== FUN_007debf0 @ 0x007debf0 ====

void FUN_007debf0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_007ce1c0(param_1);
  uVar1 = FUN_007bdf30(uVar1);
  FUN_007cdfe0(param_1,uVar1);
  return;
}


// ==== FUN_007dec10 @ 0x007dec10 ====

void FUN_007dec10(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_007ce1c0(param_1);
  uVar1 = FUN_007cd1a0(uVar1);
  FUN_007cdfe0(param_1,uVar1);
  return;
}


// ==== FUN_007dec30 @ 0x007dec30 ====

bool FUN_007dec30(byte *param_1,byte *param_2,byte *param_3,int param_4)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  byte *pbVar15;
  bool bVar16;
  
  bVar2 = param_3[1];
  bVar3 = param_3[2];
  bVar4 = *param_3;
  bVar5 = param_3[3];
  uVar14 = (uint)*param_1;
  bVar16 = false;
  bVar8 = false;
  if (uVar14 == 0) {
LAB_007def6b:
    return *param_2 == 0;
  }
LAB_007dec70:
  if (bVar16) {
LAB_007deca2:
    if (uVar14 == bVar3) {
      iVar10 = FUN_007e5380(param_2);
      if (iVar10 == 0) {
        return false;
      }
      bVar9 = param_1[1];
      pbVar15 = param_1 + 1;
      bVar16 = bVar9 == 0x5e;
      if (bVar16) {
        bVar9 = param_1[2];
        pbVar15 = param_1 + 2;
      }
      if (bVar9 == 0x5d) {
        pbVar15 = pbVar15 + 1;
      }
      bVar7 = bVar9 == 0x5d && iVar10 == 0x5d;
      iVar11 = FUN_007e5380(pbVar15);
      iVar6 = 0;
      while( true ) {
        if (iVar11 == 0) {
          return false;
        }
        if (iVar11 == 0x5d) break;
        if ((((iVar11 == 0x2d) && (pbVar15[1] != 0x5d)) && (pbVar15[1] != 0)) && (0 < iVar6)) {
          pbVar15 = pbVar15 + 1;
          iVar11 = FUN_007e5380(pbVar15);
          if ((iVar6 <= iVar10) && (iVar10 <= iVar11)) {
            bVar7 = true;
          }
          iVar11 = 0;
        }
        else if (iVar10 == iVar11) {
          bVar7 = true;
        }
        do {
          pbVar1 = pbVar15 + 1;
          pbVar15 = pbVar15 + 1;
        } while ((*pbVar1 & 0xc0) == 0x80);
        iVar12 = FUN_007e5380(pbVar15);
        iVar6 = iVar11;
        iVar11 = iVar12;
      }
      if (bVar16 == bVar7) {
        return false;
      }
      do {
        pbVar1 = param_2 + 1;
        param_2 = param_2 + 1;
      } while ((*pbVar1 & 0xc0) == 0x80);
      param_1 = pbVar15 + 1;
      bVar16 = bVar8;
    }
    else if (((param_4 == 0) || (bVar16)) || (iVar10 = FUN_007e5380(param_1), iVar10 != param_4)) {
      if (bVar5 == 0) {
        bVar16 = uVar14 == *param_2;
      }
      else {
        bVar16 = (&DAT_009fffc0)[uVar14] == (&DAT_009fffc0)[*param_2];
      }
      if (!bVar16) {
        return false;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      bVar16 = false;
      bVar8 = false;
    }
    else {
      bVar16 = true;
      bVar8 = true;
      do {
        pbVar15 = param_1 + 1;
        param_1 = param_1 + 1;
      } while ((*pbVar15 & 0xc0) == 0x80);
    }
  }
  else {
    if (uVar14 == bVar4) {
      for (; (uVar14 = (uint)param_1[1], uVar14 == bVar4 || (uVar14 == bVar2));
          param_1 = param_1 + 1) {
        if (uVar14 == bVar2) {
          if (*param_2 == 0) {
            return false;
          }
          do {
            pbVar15 = param_2 + 1;
            param_2 = param_2 + 1;
          } while ((*pbVar15 & 0xc0) == 0x80);
        }
      }
      if (uVar14 != 0) {
        if (param_4 != 0) {
          pbVar15 = param_1 + 1;
          iVar10 = FUN_007e5380(pbVar15);
          if (iVar10 == param_4) {
            do {
              pbVar1 = pbVar15 + 1;
              pbVar15 = pbVar15 + 1;
            } while ((*pbVar1 & 0xc0) == 0x80);
            uVar14 = (uint)*pbVar15;
          }
        }
        if (uVar14 != 0) {
          if (uVar14 != bVar3) {
            uVar13 = (uint)*param_2;
            if (uVar13 == 0) {
              return false;
            }
            do {
              if (bVar5 == 0) {
                while (uVar13 != uVar14) {
                  uVar13 = (uint)param_2[1];
                  param_2 = param_2 + 1;
                  if (uVar13 == 0) {
                    return false;
                  }
                }
              }
              else {
                uVar13 = (uint)(byte)(&DAT_009fffc0)[uVar13];
                uVar14 = (uint)(byte)(&DAT_009fffc0)[uVar14];
                if (uVar13 == 0) {
                  return false;
                }
                while (uVar13 != uVar14) {
                  uVar13 = (uint)(byte)(&DAT_009fffc0)[param_2[1]];
                  param_2 = param_2 + 1;
                  if (uVar13 == 0) {
                    return false;
                  }
                }
              }
              if (uVar13 == 0) {
                return false;
              }
              iVar10 = FUN_007dec30(param_1 + 1,param_2,param_3,param_4);
              if (iVar10 != 0) {
                return true;
              }
              do {
                pbVar15 = param_2 + 1;
                param_2 = param_2 + 1;
              } while ((*pbVar15 & 0xc0) == 0x80);
              uVar13 = (uint)*param_2;
            } while (uVar13 != 0);
            return false;
          }
          if (*param_2 != 0) {
            do {
              iVar10 = FUN_007dec30(param_1 + 1,param_2,param_3,param_4);
              if (iVar10 != 0) break;
              do {
                pbVar15 = param_2 + 1;
                param_2 = param_2 + 1;
              } while ((*pbVar15 & 0xc0) == 0x80);
            } while (*param_2 != 0);
          }
          return *param_2 != 0;
        }
      }
      return true;
    }
    if (uVar14 != bVar2) goto LAB_007deca2;
    if (*param_2 == 0) {
      return false;
    }
    do {
      pbVar15 = param_2 + 1;
      param_2 = param_2 + 1;
    } while ((*pbVar15 & 0xc0) == 0x80);
    param_1 = param_1 + 1;
  }
  uVar14 = (uint)*param_1;
  if (uVar14 == 0) goto LAB_007def6b;
  goto LAB_007dec70;
}


// ==== FUN_007def80 @ 0x007def80 ====

void FUN_007def80(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = FUN_007cdf50(*param_3);
  iVar2 = FUN_007cdf50(param_3[1]);
  uVar3 = 0;
  if (param_2 == 3) {
    uVar3 = FUN_007cdf50(param_3[2]);
    iVar4 = FUN_007e5c30(uVar3,0xffffffff);
    if (iVar4 != 1) {
      FUN_007cdfb0();
      return;
    }
    uVar3 = FUN_007e5380(uVar3);
  }
  if ((iVar1 != 0) && (iVar2 != 0)) {
    uVar3 = FUN_007dec30(iVar1,iVar2,&DAT_00a00c84,uVar3);
    FUN_007cdfe0(param_1,uVar3);
  }
  return;
}


// ==== FUN_007df010 @ 0x007df010 ====

void FUN_007df010(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_007cdf50(*param_3);
  iVar2 = FUN_007cdf50(param_3[1]);
  if ((iVar1 != 0) && (iVar2 != 0)) {
    uVar3 = FUN_007dec30(iVar1,iVar2,&DAT_00a00c80,0);
    FUN_007cdfe0(param_1,uVar3);
  }
  return;
}


// ==== FUN_007df060 @ 0x007df060 ====

void FUN_007df060(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_007d03a0(*param_3,param_3[1],*(undefined4 *)(param_1 + 0x54));
  if (iVar1 != 0) {
    FUN_007ce090(param_1,*param_3);
  }
  return;
}


// ==== FUN_007df090 @ 0x007df090 ====

void FUN_007df090(undefined4 param_1)

{
  FUN_007ce030(param_1,s_3_2_2_009ff8d8,0xffffffff,0);
  return;
}


// ==== FUN_007df0b0 @ 0x007df0b0 ====

void FUN_007df0b0(undefined4 param_1,int param_2,undefined4 *param_3)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  char *pcVar8;
  undefined1 *puVar9;
  
  if (0 < param_2) {
    uVar3 = FUN_007cdf80(*param_3);
    switch(uVar3) {
    case 1:
    case 2:
      FUN_007ce090(param_1,*param_3);
      return;
    case 3:
      pcVar8 = (char *)FUN_007cdf50(*param_3);
      iVar4 = 0;
      iVar5 = 0;
      cVar2 = *pcVar8;
      while (cVar2 != '\0') {
        if (cVar2 == '\'') {
          iVar4 = iVar4 + 1;
        }
        iVar7 = iVar5 + 1;
        iVar5 = iVar5 + 1;
        cVar2 = pcVar8[iVar7];
      }
      puVar6 = (undefined1 *)FUN_007d0550(iVar4 + 3 + iVar5);
      if (puVar6 != (undefined1 *)0x0) {
        *puVar6 = 0x27;
        cVar2 = *pcVar8;
        iVar4 = 1;
        while (cVar2 != '\0') {
          puVar6[iVar4] = *pcVar8;
          iVar5 = iVar4 + 1;
          if (*pcVar8 == '\'') {
            puVar6[iVar5] = 0x27;
            iVar5 = iVar4 + 2;
          }
          pcVar1 = pcVar8 + 1;
          pcVar8 = pcVar8 + 1;
          iVar4 = iVar5;
          cVar2 = *pcVar1;
        }
        puVar6[iVar4] = 0x27;
        puVar6[iVar4 + 1] = 0;
        FUN_007ce030(param_1,puVar6,iVar4 + 1,0xffffffff);
        FUN_007d05b0(puVar6);
        return;
      }
      break;
    case 4:
      iVar4 = FUN_007cdf00(*param_3);
      iVar5 = FUN_007ce400(*param_3);
      puVar6 = (undefined1 *)FUN_007d0550(iVar4 * 2 + 4);
      if (puVar6 == (undefined1 *)0x0) {
        FUN_007cdfb0();
        return;
      }
      iVar7 = 0;
      if (0 < iVar4) {
        puVar9 = puVar6 + 3;
        do {
          puVar9[-1] = (&DAT_00a00c88)[*(byte *)(iVar7 + iVar5) >> 4];
          *puVar9 = (&DAT_00a00c88)[*(byte *)(iVar7 + iVar5) & 0xf];
          iVar7 = iVar7 + 1;
          puVar9 = puVar9 + 2;
        } while (iVar7 < iVar4);
      }
      puVar6[iVar4 * 2 + 2] = 0x27;
      puVar6[iVar4 * 2 + 3] = 0;
      *puVar6 = 0x58;
      puVar6[1] = 0x27;
      FUN_007ce030(param_1,puVar6,0xffffffff,0xffffffff);
      FUN_007d05b0(puVar6);
      break;
    case 5:
      FUN_007ce030(param_1,&DAT_00a00f30,4,0);
      return;
    }
  }
  return;
}


// ==== FUN_007df250 @ 0x007df250 ====

void FUN_007df250(undefined4 param_1,int param_2,undefined4 *param_3)

{
  double *pdVar1;
  int iVar2;
  float10 fVar3;
  
  if (((0 < param_2) && (pdVar1 = (double *)FUN_007ce1d0(param_1,0x10), pdVar1 != (double *)0x0)) &&
     (iVar2 = FUN_007cdf80(*param_3), iVar2 != 5)) {
    fVar3 = (float10)thunk_FUN_007d0050(*param_3);
    *pdVar1 = (double)(fVar3 + (float10)*pdVar1);
    *(int *)(pdVar1 + 1) = *(int *)(pdVar1 + 1) + 1;
  }
  return;
}


// ==== FUN_007df2a0 @ 0x007df2a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007df2a0(undefined4 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_007ce1d0(param_1,0x10);
  if (puVar1 == (undefined8 *)0x0) {
    FUN_007cdf90(param_1,_DAT_0099d098);
    return;
  }
  FUN_007cdf90(param_1,*puVar1);
  return;
}


// ==== FUN_007df2e0 @ 0x007df2e0 ====

void FUN_007df2e0(undefined4 param_1)

{
  double *pdVar1;
  
  pdVar1 = (double *)FUN_007ce1d0(param_1,0x10);
  if ((pdVar1 != (double *)0x0) && (0 < *(int *)(pdVar1 + 1))) {
    FUN_007cdf90(param_1,*pdVar1 / (double)*(int *)(pdVar1 + 1));
  }
  return;
}


// ==== FUN_007df320 @ 0x007df320 ====

void FUN_007df320(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_007ce1d0(param_1,4);
  if ((param_2 != 0) && (iVar2 = FUN_007cdf80(*param_3), iVar2 == 5)) {
    return;
  }
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  return;
}


// ==== FUN_007df360 @ 0x007df360 ====

void FUN_007df360(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_007ce1d0(param_1,4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_007cdfe0(param_1,0);
    return;
  }
  FUN_007cdfe0(param_1,*puVar1);
  return;
}


// ==== FUN_007df390 @ 0x007df390 ====

void FUN_007df390(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = *param_3;
  iVar3 = FUN_007cdf80(uVar1);
  if (iVar3 == 5) {
    return;
  }
  iVar3 = FUN_007ce1d0(param_1,0x40);
  if (iVar3 == 0) {
    return;
  }
  if (*(short *)(iVar3 + 0xc) != 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x54);
    iVar4 = FUN_007ce1c0(param_1);
    iVar5 = FUN_007d03a0(iVar3,uVar1,uVar2);
    if (iVar4 == -1) {
      if (iVar5 < 0) {
        FUN_007cfb20(iVar3,uVar1);
        return;
      }
      return;
    }
    if (iVar5 < 1) {
      return;
    }
  }
  FUN_007cfb20(iVar3,uVar1);
  return;
}


// ==== FUN_007df410 @ 0x007df410 ====

void FUN_007df410(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_007ce1d0(param_1,0x40);
  if (*(short *)(iVar1 + 0xc) != 0) {
    FUN_007ce090(param_1,iVar1);
  }
  FUN_007cf9b0(iVar1);
  return;
}


// ==== FUN_007df440 @ 0x007df440 ====

void FUN_007df440(undefined4 param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar6 = 0;
  do {
    if ((&DAT_00a00c9d)[uVar6] == '\x01') {
      uVar5 = param_1;
    }
    else {
      uVar5 = 0;
      if ((&DAT_00a00c9d)[uVar6] == '\x02') {
        uVar5 = 0xffffffff;
      }
    }
    FUN_007cd550(param_1,*(undefined4 *)((int)&PTR_DAT_00a00c98 + uVar6),
                 (int)(char)(&DAT_00a00c9c)[uVar6],(&DAT_00a00c9e)[uVar6],uVar5,
                 *(undefined4 *)((int)&PTR_FUN_00a00ca0 + uVar6),0,0);
    if ((&DAT_00a00c9f)[uVar6] != '\0') {
      pcVar2 = *(char **)((int)&PTR_DAT_00a00c98 + uVar6);
      pcVar3 = pcVar2;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      iVar4 = FUN_007de2e0(param_1,pcVar2,(int)pcVar3 - (int)(pcVar2 + 1),
                           (int)(char)(&DAT_00a00c9c)[uVar6],(&DAT_00a00c9e)[uVar6],0);
      if ((iVar4 != 0) && ((&DAT_00a00c9f)[uVar6] != '\0')) {
        *(undefined1 *)(iVar4 + 0x20) = 1;
      }
    }
    uVar6 = uVar6 + 0xc;
  } while (uVar6 < 0x144);
  FUN_007f3500(param_1);
  uVar6 = 0;
  do {
    if ((&DAT_00a00de5)[uVar6] == '\x01') {
      uVar5 = param_1;
    }
    else {
      uVar5 = 0;
      if ((&DAT_00a00de5)[uVar6] == '\x02') {
        uVar5 = 0xffffffff;
      }
    }
    FUN_007cd550(param_1,*(undefined4 *)((int)&PTR_DAT_00a00de0 + uVar6),
                 (int)(char)(&DAT_00a00de4)[uVar6],1,uVar5,0,
                 *(undefined4 *)((int)&PTR_FUN_00a00de8 + uVar6),
                 *(undefined4 *)((int)&PTR_FUN_00a00dec + uVar6));
    if ((&DAT_00a00de6)[uVar6] != '\0') {
      pcVar2 = *(char **)((int)&PTR_DAT_00a00de0 + uVar6);
      pcVar3 = pcVar2;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      iVar4 = FUN_007de2e0(param_1,pcVar2,(int)pcVar3 - (int)(pcVar2 + 1),
                           (int)(char)(&DAT_00a00de4)[uVar6],1,0);
      if ((iVar4 != 0) && ((&DAT_00a00de6)[uVar6] != '\0')) {
        *(undefined1 *)(iVar4 + 0x20) = 1;
      }
    }
    uVar6 = uVar6 + 0x10;
  } while (uVar6 < 0x60);
  FUN_007f3330(param_1);
  return;
}


// ==== FUN_007df5a0 @ 0x007df5a0 ====

void FUN_007df5a0(void)

{
  ushort uVar1;
  int in_ECX;
  
  uVar1 = *(ushort *)(in_ECX + 0xc);
  if ((uVar1 & 1) != 0) {
    *(undefined1 *)(in_ECX + 0xe) = 5;
    return;
  }
  if ((uVar1 & 4) != 0) {
    *(undefined1 *)(in_ECX + 0xe) = 1;
    return;
  }
  if ((uVar1 & 8) == 0) {
    *(char *)(in_ECX + 0xe) = '\x04' - ((uVar1 & 2) != 0);
    return;
  }
  *(undefined1 *)(in_ECX + 0xe) = 2;
  return;
}


// ==== FUN_007df5d0 @ 0x007df5d0 ====

int FUN_007df5d0(undefined4 *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *unaff_EBX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar1 = (uint)param_2;
  param_2 = (int *)FUN_007d0550(*unaff_EBX * 0x40 + 8 + (int)param_2);
  if (param_2 == (int *)0x0) {
    return 7;
  }
  *param_2 = (int)(param_2 + *unaff_EBX * 0x10 + 2);
  puVar5 = param_1;
  puVar6 = (undefined4 *)*param_2;
  for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar3 = uVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  param_2[1] = uVar1;
  if (unaff_EBX[4] != 0) {
    iVar2 = FUN_007da050(unaff_EBX[4],param_1,uVar1,(int)uVar1 >> 0x1f,&param_2,4);
    if (iVar2 != 0) {
      FUN_007d05b0(param_2);
      return iVar2;
    }
  }
  iVar2 = 0;
  if (0 < *unaff_EBX) {
    iVar4 = 0;
    do {
      *(undefined2 *)(iVar4 + 0x14 + (int)param_2) = 1;
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x40;
    } while (iVar2 < *unaff_EBX);
  }
  unaff_EBX[1] = (int)param_2;
  return 0;
}


// ==== FUN_007df690 @ 0x007df690 ====

void FUN_007df690(int *param_1)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = *param_1;
  if (0 < in_EAX) {
    do {
      if ((*(byte *)(iVar1 + 0xc) & 0x40) != 0) {
        FUN_007cf9b0(iVar1);
      }
      iVar1 = iVar1 + -0x40;
      in_EAX = in_EAX + -1;
    } while (in_EAX != 0);
  }
  *param_1 = iVar1;
  return;
}


// ==== FUN_007df6c0 @ 0x007df6c0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007df6c0(undefined4 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 *in_EDX;
  undefined1 local_54 [72];
  undefined4 local_c;
  undefined4 local_4;
  
  puVar1 = local_54;
  local_c = 0;
  local_4 = DAT_00b49670;
  while( true ) {
    if (in_EDX == (undefined4 *)0x0) {
      if (in_ECX != (undefined4 *)0x0) {
        *(undefined4 **)(puVar1 + 0x48) = in_ECX;
      }
      return local_c;
    }
    if (in_ECX == (undefined4 *)0x0) break;
    iVar2 = FUN_007dd5c0(param_1,*in_EDX,in_EDX[1],*in_ECX,in_ECX[1]);
    if (iVar2 < 1) {
      *(undefined4 **)(puVar1 + 0x48) = in_EDX;
      in_EDX = (undefined4 *)in_EDX[0x12];
    }
    else {
      *(undefined4 **)(puVar1 + 0x48) = in_ECX;
      in_ECX = (undefined4 *)in_ECX[0x12];
    }
    puVar1 = *(undefined1 **)(puVar1 + 0x48);
  }
  if (in_EDX == (undefined4 *)0x0) {
    return local_c;
  }
  *(undefined4 **)(puVar1 + 0x48) = in_EDX;
  return local_c;
}


// ==== FUN_007df760 @ 0x007df760 ====

void FUN_007df760(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0x3c) + unaff_ESI * 4);
  if (iVar1 != 0) {
    FUN_007dcc30(iVar1);
  }
  uVar2 = FUN_007d0550(0x68);
  *(undefined4 *)(*(int *)(unaff_EDI + 0x3c) + unaff_ESI * 4) = uVar2;
  return;
}


// ==== FUN_007df790 @ 0x007df790 ====

void FUN_007df790(undefined4 param_1)

{
  ushort uVar1;
  char in_AL;
  int iVar2;
  longlong *unaff_ESI;
  longlong lVar3;
  int local_4;
  
  if (in_AL != 'o') {
    if (in_AL == 't') {
      if (((*(ushort *)((int)unaff_ESI + 0xc) & 2) == 0) &&
         ((*(ushort *)((int)unaff_ESI + 0xc) & 0xc) != 0)) {
        FUN_007cfee0();
      }
      *(byte *)((int)unaff_ESI + 0xc) = *(byte *)((int)unaff_ESI + 0xc) & 0xf3;
      return;
    }
    if ((((*(byte *)((int)unaff_ESI + 0xc) & 0xc) == 0) &&
        (FUN_007cf920(), (*(byte *)((int)unaff_ESI + 0xc) & 2) != 0)) &&
       (iVar2 = FUN_007d0990((int)unaff_ESI[3],&local_4,param_1), iVar2 != 0)) {
      if (local_4 == 0) {
        FUN_007d0000();
      }
      else {
        FUN_007d00b0();
      }
    }
    if (((in_AL == 'i') && (uVar1 = *(ushort *)((int)unaff_ESI + 0xc), (uVar1 & 8) != 0)) &&
       ((uVar1 & 4) == 0)) {
      lVar3 = FUN_00802534();
      *unaff_ESI = lVar3;
      if ((double)unaff_ESI[2] == (double)*unaff_ESI) {
        *(ushort *)((int)unaff_ESI + 0xc) = uVar1 | 4;
      }
    }
  }
  return;
}


// ==== FUN_007df850 @ 0x007df850 ====

void FUN_007df850(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_007df790(param_3);
  return;
}


// ==== FUN_007df870 @ 0x007df870 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_007df870(int *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  byte bVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  uint uVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  undefined4 uVar14;
  uint *extraout_ECX;
  uint *puVar15;
  uint uVar16;
  int extraout_ECX_00;
  uint *puVar17;
  int extraout_ECX_01;
  int extraout_EDX;
  int iVar18;
  int extraout_EDX_00;
  uint *puVar19;
  undefined4 *puVar20;
  int iVar21;
  byte *pbVar22;
  uint *puVar23;
  bool bVar24;
  float10 fVar25;
  undefined8 uVar26;
  uint *local_3a8;
  uint *local_3a4;
  int *local_3a0;
  uint *puStack_39c;
  uint *puStack_398;
  int local_394;
  uint *puStack_390;
  uint *puStack_38c;
  byte *local_388;
  byte bStack_381;
  uint uStack_380;
  uint uStack_37c;
  uint *puStack_378;
  undefined4 *puStack_374;
  double dStack_370;
  uint *puStack_368;
  uint *puStack_364;
  uint uStack_360;
  uint *puStack_35c;
  int iStack_358;
  uint *puStack_354;
  uint *puStack_350;
  byte bStack_349;
  uint uStack_348;
  int iStack_344;
  int iStack_340;
  uint uStack_33c;
  uint uStack_338;
  uint uStack_334;
  int iStack_330;
  int iStack_32c;
  int iStack_328;
  int local_324;
  uint *puStack_320;
  int iStack_31c;
  int iStack_318;
  uint *puStack_314;
  uint uStack_310;
  uint uStack_30c;
  int iStack_304;
  uint uStack_300;
  uint uStack_2fc;
  int iStack_2f4;
  uint uStack_2f0;
  uint uStack_2ec;
  int iStack_2e8;
  int iStack_2e4;
  uint uStack_2e0;
  uint uStack_2dc;
  undefined4 uStack_2d8;
  int iStack_2d4;
  int iStack_2d0;
  int iStack_2cc;
  int iStack_2c8;
  int iStack_2c4;
  uint uStack_2c0;
  uint uStack_2bc;
  uint uStack_2b8;
  uint uStack_2b4;
  int *piStack_2b0;
  int *piStack_2ac;
  int aiStack_2a8 [32];
  uint *apuStack_228 [2];
  undefined4 *puStack_220;
  undefined4 *puStack_21c;
  undefined1 auStack_218 [12];
  undefined2 uStack_20c;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  char cStack_1d4;
  undefined4 uStack_1cc;
  undefined1 auStack_1c8 [12];
  ushort uStack_1bc;
  uint *puStack_1b0;
  int aiStack_188 [8];
  uint *puStack_168;
  uint uStack_140;
  char cStack_13c;
  uint uStack_138;
  undefined4 uStack_134;
  int aiStack_130 [2];
  uint auStack_128 [3];
  undefined2 uStack_11c;
  uint *puStack_110;
  uint *puStack_e8;
  uint uStack_e0;
  uint auStack_d8 [8];
  uint auStack_b8 [16];
  undefined1 auStack_78 [108];
  undefined4 local_c;
  
  local_3a0 = (int *)*param_1;
  local_c = DAT_00b49670;
  local_3a4 = (uint *)0x0;
  local_324 = 0;
  if (param_1[0x16] != -0x420df25d) {
    return 0x15;
  }
  local_3a8 = (uint *)param_1[0xb];
  param_1[0x22] = 0;
  puVar17 = local_3a8;
  if (DAT_00b5c4c4 != 0) {
LAB_007e3555:
    FUN_007d0700(param_1 + 0x8e,s_out_of_memory_009ffbcc,0);
    local_3a4 = (uint *)0x7;
    param_1[0x22] = 7;
    iVar7 = 1;
    goto LAB_007e3630;
  }
  if (param_1[0x8d] != 0) {
    FUN_007df690(&local_3a8);
    param_1[0x8d] = 0;
  }
  *(undefined1 *)(param_1 + 0x8f) = 0;
  puVar17 = local_3a8;
  if ((*(byte *)(local_3a0 + 2) & 4) != 0) {
LAB_007e358d:
    local_3a0[2] = local_3a0[2] & 0xfffffffb;
    local_3a4 = (uint *)(((local_3a0[0xc] == -0xfc486fa) - 1 & 0xc) + 9);
    param_1[0x22] = (int)local_3a4;
    uVar14 = FUN_007cd3a0(local_3a4,0);
LAB_007e360c:
    FUN_007d0700(param_1 + 0x8e,uVar14);
LAB_007e3614:
    if (local_3a4 == (uint *)0x0) {
      iVar7 = 0x65;
    }
    else {
      param_1[0x22] = (int)local_3a4;
      iVar7 = 1;
    }
    goto LAB_007e3630;
  }
  local_394 = param_1[0x21];
  puVar15 = local_3a8;
LAB_007df921:
  puVar17 = puVar15;
  if (DAT_00b5c4c4 != 0) goto LAB_007e3555;
  pbVar22 = (byte *)(param_1[6] + local_394 * 0x14);
  local_388 = pbVar22;
  if ((code *)local_3a0[0x21] != (code *)0x0) {
    if (local_3a0[0x23] != local_324) {
LAB_007df988:
      local_324 = local_324 + 1;
      goto LAB_007df98f;
    }
    iVar7 = (*(code *)local_3a0[0x21])(local_3a0[0x22]);
    if (iVar7 == 0) {
      local_324 = 0;
      goto LAB_007df988;
    }
    local_3a4 = (uint *)0x4;
    goto switchD_007df9a7_caseD_d;
  }
LAB_007df98f:
  piVar12 = local_3a0;
  bVar6 = *pbVar22;
  puStack_39c = (uint *)(uint)bVar6;
  switch(puStack_39c) {
  case (uint *)0x1:
switchD_007df9a7_caseD_1:
    puVar17 = puVar15 + 0x10;
    local_3a8 = puVar17;
    FUN_007cfae0(puVar17,*(int *)(pbVar22 + 4) * 0x40 + param_1[0x18],0x100);
    break;
  case (uint *)0x2:
    puStack_39c = *(uint **)(pbVar22 + 8);
    iVar7 = *(int *)(pbVar22 + 4);
    puVar17 = puVar15 + 0x10;
    uStack_1bc = 0;
    puStack_398 = (uint *)0x0;
    *(undefined2 *)(puVar15 + 0x13) = 1;
    local_3a8 = puVar17;
    if (iVar7 < 0) {
      puStack_364 = (uint *)puVar17[iVar7 * 0x10 + 2];
      puStack_35c = (uint *)puVar17[iVar7 * 0x10 + 6];
      puStack_354 = (uint *)puVar17[iVar7 * 0x10 + -0x10];
LAB_007e0975:
      uStack_360 = 0;
      puVar19 = puStack_398;
    }
    else {
      puVar19 = *(uint **)(param_1[0xf] + iVar7 * 4);
      puStack_398 = puVar19;
      if (*puVar19 == 0) {
        if (*(char *)((int)puVar19 + 0x1e) == '\0') {
          puStack_364 = (uint *)0x0;
          *(undefined2 *)(puVar15 + 0x13) = 1;
          break;
        }
        puStack_364 = (uint *)puVar19[0xd];
        puStack_35c = (uint *)puVar19[0xe];
        puStack_354 = (uint *)puVar19[0x14];
        *(undefined1 *)(puVar19 + 0x15) = 0;
        goto LAB_007e0975;
      }
      local_3a4 = (uint *)FUN_007dd1a0(puVar19);
      if (local_3a4 != (uint *)0x0) goto LAB_007e35da;
      uStack_360 = *puVar19;
      puStack_35c = local_3a4;
      if ((char)puVar19[7] == '\0') {
        if ((char)puVar19[0x15] == '\0') {
          if (*(char *)((int)puVar19 + 0x21) == '\0') {
            FUN_007d7160(uStack_360,&puStack_364);
            puStack_354 = (uint *)puVar19[0x14];
          }
          else {
            FUN_007d70f0(uStack_360,apuStack_228);
            puStack_364 = apuStack_228[0];
            puStack_354 = (uint *)puVar19[0x14];
          }
        }
        else {
          puStack_364 = (uint *)puVar19[0x16];
          puStack_35c = (uint *)puVar19[0x19];
          puStack_354 = (uint *)puVar19[0x14];
        }
      }
      else {
        puStack_354 = (uint *)puVar19[0x14];
        puStack_364 = (uint *)0x0;
      }
    }
    if (puStack_364 == (uint *)0x0) {
      *(undefined2 *)(puVar15 + 0x13) = 1;
    }
    else {
      if (puVar19 == (uint *)0x0) {
LAB_007e0a9f:
        puVar11 = (undefined4 *)FUN_007d0590((int)puStack_354 * 8);
LAB_007e0ab5:
        puStack_390 = puVar11 + (int)puStack_354;
        puStack_374 = puVar11;
        if (puVar11 == (undefined4 *)0x0) goto LAB_007e3555;
        if (puStack_35c == (uint *)0x0) {
          if (*(char *)((int)puVar19 + 0x21) == '\0') {
            puStack_378 = (uint *)FUN_007d7440(uStack_360,&puStack_314);
          }
          else {
            puStack_378 = (uint *)FUN_007d73d0(uStack_360,&puStack_314);
          }
          if (puStack_314 < puStack_364) {
            puVar19[0x19] = 0;
          }
          else {
            puVar19[0x19] = (uint)puStack_378;
            puStack_35c = puStack_378;
          }
        }
        else {
          puStack_378 = puStack_35c;
        }
        puStack_368 = (uint *)FUN_007d1120(puStack_378,&puStack_320);
        if ((puStack_35c == (uint *)0x0) && (puStack_314 < puStack_320)) {
          local_3a4 = (uint *)FUN_007cfd00(uStack_360,0,puStack_320,
                                           *(undefined1 *)((int)puVar19 + 0x21),auStack_1c8);
          if (local_3a4 == (uint *)0x0) {
            puStack_378 = puStack_1b0;
            goto LAB_007e0b8e;
          }
        }
        else {
LAB_007e0b8e:
          puStack_38c = puStack_320;
          local_3a4 = (uint *)0x0;
          if (puStack_368 < puStack_320) {
            dStack_370 = (double)CONCAT44(dStack_370._4_4_,(int)puStack_390 - (int)puStack_374);
            puVar11 = puStack_374;
            do {
              if ((puStack_354 <= local_3a4) || (puStack_364 < puStack_38c)) break;
              *(uint **)(dStack_370._0_4_ + (int)puVar11) = puStack_38c;
              iVar7 = FUN_007d1120((int)puStack_368 + (int)puStack_378,puVar11);
              puStack_368 = (uint *)((int)puStack_368 + iVar7);
              iVar7 = FUN_007dd2f0(*puVar11);
              puStack_38c = (uint *)((int)puStack_38c + iVar7);
              local_3a4 = (uint *)((int)local_3a4 + 1);
              puVar11 = puVar11 + 1;
            } while (puStack_368 < puStack_320);
          }
          if ((uStack_1bc & 0x40) != 0) {
            FUN_007cf9b0(auStack_1c8);
          }
          uStack_1bc = 1;
          if (local_3a4 < puStack_354) {
            puVar19 = puStack_390 + (int)local_3a4;
            for (iVar7 = (int)puStack_354 - (int)local_3a4; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar19 = 0;
              puVar19 = puVar19 + 1;
            }
            pbVar22 = local_388;
          }
          if ((puStack_368 == puStack_320) && (puStack_38c == puStack_364)) {
            if (puStack_398 != (uint *)0x0) {
              puStack_398[0x16] = (uint)puStack_364;
              puStack_398[0x17] = (uint)puStack_374;
              puStack_398[0x18] = (uint)puStack_390;
              *(undefined1 *)(puStack_398 + 0x15) = 1;
            }
            goto LAB_007e0ca3;
          }
          local_3a4 = (uint *)0xb;
        }
      }
      else {
        puVar11 = (undefined4 *)puVar19[0x17];
        if ((char)puVar19[0x15] == '\0') {
          if (puVar11 == (undefined4 *)0x0) goto LAB_007e0a9f;
          goto LAB_007e0ab5;
        }
        puStack_390 = (uint *)puVar19[0x18];
        puStack_374 = puVar11;
LAB_007e0ca3:
        puVar19 = puStack_39c;
        if (puStack_390[(int)puStack_39c] == 0) {
          if (*(int *)(pbVar22 + 0xc) == 0) {
            *(undefined2 *)(puVar15 + 0x13) = 1;
          }
          else {
            FUN_007cfae0(puVar17,*(int *)(pbVar22 + 0xc),0x80);
          }
        }
        else {
          if (puStack_35c == (uint *)0x0) {
            uVar14 = FUN_007dd2f0(puStack_374[(int)puStack_39c]);
            local_3a4 = (uint *)FUN_007cfd00(uStack_360,puStack_390[(int)puVar19],uVar14,
                                             *(undefined1 *)((int)puStack_398 + 0x21),auStack_1c8);
            if (local_3a4 != (uint *)0x0) goto LAB_007e0d81;
            puVar19 = puStack_1b0;
          }
          else {
            puVar19 = (uint *)(puStack_390[(int)puStack_39c] + (int)puStack_35c);
          }
          FUN_007dd3a0(puVar19,puStack_374[(int)puStack_39c],puVar17);
          *(char *)((int)puVar15 + 0x4f) = (char)local_3a0[4];
        }
        if ((uStack_1bc & 0x40) != 0) {
          *(ushort *)(puVar15 + 0x13) = (ushort)puVar15[0x13] & 0xfeff | 0x60;
        }
        local_3a4 = (uint *)FUN_007cf890(puVar17);
      }
LAB_007e0d81:
      if (puStack_398 != (uint *)0x0) {
        if (puStack_398[0x17] != 0) break;
      }
      FUN_007d05b0(puStack_374);
    }
    break;
  case (uint *)0x3:
    iVar7 = *(int *)(pbVar22 + 4) * 0x70 + local_3a0[1];
    FUN_007d0000(puVar15);
    local_3a4 = (uint *)FUN_007da6d0(*(undefined4 *)(iVar7 + 4),*(int *)(pbVar22 + 8) + 1,*puVar15);
    if (*(int *)(pbVar22 + 8) == 0) {
      *(uint *)(iVar7 + 8) = *puVar15;
      local_3a0[2] = local_3a0[2] | 0x10;
    }
    puVar17 = puVar15 + -0x10;
    local_3a8 = puVar15 + -0x10;
    break;
  case (uint *)0x4:
    iVar7 = *(int *)(*(int *)(pbVar22 + 4) * 0x40 + 4 + param_1[0x18]);
    if (-1 < iVar7) {
      if (iVar7 < 1) {
        if (*(int *)(*(int *)(pbVar22 + 4) * 0x40 + param_1[0x18]) == 0) break;
      }
      local_394 = *(int *)(pbVar22 + 8) + -1;
    }
    break;
  case (uint *)0x5:
  case (uint *)0x43:
  case (uint *)0x64:
  case (uint *)0x7a:
    piVar12 = *(int **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    if (*piVar12 == 0) {
LAB_007e173d:
      if ((puVar15[3] & 0x40) == 0) goto LAB_007e2f84;
      FUN_007cf9b0(puVar15);
      puVar17 = puVar15 + -0x10;
      local_3a8 = puVar15 + -0x10;
      break;
    }
    *(undefined1 *)(piVar12 + 7) = 0;
    if ((puStack_39c == (uint *)0x5) || (puStack_39c == (uint *)0x43)) {
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
    *(undefined1 *)piVar12[0x12] = uVar5;
    if ((char)piVar12[8] == '\0') {
      if ((puVar15[3] & 0x12) == 0) {
        iVar7 = FUN_007cfee0(puVar15,(char)local_3a0[4]);
        if (iVar7 != 0) goto LAB_007e3555;
      }
      local_3a4 = (uint *)FUN_007d7880(*piVar12,puVar15[6],puVar15[2],(int)puVar15[2] >> 0x1f,
                                       &iStack_358);
      if (local_3a4 == (uint *)0x0) {
        *(undefined1 *)((int)piVar12 + 0x19) = 0;
LAB_007e16a1:
        *(undefined1 *)((int)piVar12 + 0x1f) = 0;
        *(undefined1 *)(piVar12 + 0x15) = 0;
        *(undefined1 *)piVar12[0x12] = 0;
        DAT_00b5c4dc = DAT_00b5c4dc + 1;
        if ((puStack_39c == (uint *)0x7a) || (puStack_39c == (uint *)0x5)) {
          if (-1 < iStack_358) {
            iStack_358 = 0;
            goto LAB_007e173d;
          }
          local_3a4 = (uint *)FUN_007d7b80(*piVar12,&iStack_358);
LAB_007e16df:
          if (local_3a4 != (uint *)0x0) goto LAB_007e35da;
          *(undefined1 *)((int)piVar12 + 0x19) = 0;
        }
        else {
          if (-1 < iStack_358) {
            local_3a4 = (uint *)FUN_007d7cc0(*piVar12,&iStack_358);
            goto LAB_007e16df;
          }
          iStack_358 = FUN_007d7b70(*piVar12);
        }
        if (iStack_358 != 0) {
          if (*(int *)(pbVar22 + 8) < 1) {
            *(undefined1 *)(piVar12 + 7) = 1;
          }
          else {
            local_394 = *(int *)(pbVar22 + 8) + -1;
          }
        }
        goto LAB_007e173d;
      }
      goto LAB_007e35da;
    }
    FUN_007d0000(puVar15);
    uVar10 = puVar15[1];
    if ((*(int *)(pbVar22 + 8) == 0) && (*pbVar22 == 0x7a)) {
      piVar12[10] = *puVar15;
      piVar12[0xb] = uVar10;
      *(undefined1 *)((int)piVar12 + 0x1f) = 1;
      puVar17 = puVar15 + -0x10;
      local_3a8 = puVar15 + -0x10;
      break;
    }
    local_3a4 = (uint *)FUN_007d7880(*piVar12,0,*puVar15,uVar10,&iStack_358);
    if (local_3a4 == (uint *)0x0) {
      piVar12[2] = *puVar15;
      piVar12[3] = puVar15[1];
      *(bool *)((int)piVar12 + 0x19) = iStack_358 == 0;
      goto LAB_007e16a1;
    }
    goto LAB_007e35da;
  case (uint *)0x6:
    if ((puVar15[3] & 0x12) == 0) {
      iVar7 = FUN_007cfee0(puVar15,(char)local_3a0[4]);
      if (iVar7 != 0) goto LAB_007e3555;
    }
    uVar10 = puVar15[2];
    puStack_39c = (uint *)puVar15[6];
    dStack_370 = (double)CONCAT44(dStack_370._4_4_,uVar10);
    local_3a4 = (uint *)FUN_007d7880(*(undefined4 *)(param_1[0x1b] + 0x10),puStack_39c,uVar10,
                                     (int)uVar10 >> 0x1f,&iStack_2cc);
    if (local_3a4 == (uint *)0x0) {
      if (iStack_2cc == 0) {
        local_3a4 = (uint *)FUN_007d73b0(*(undefined4 *)(param_1[0x1b] + 0x10),0,4,param_1[0x1b] + 4
                                        );
        local_394 = *(int *)(pbVar22 + 8) + -1;
      }
      else {
        local_3a4 = (uint *)FUN_007df5d0(puStack_39c,dStack_370._0_4_);
        puVar15 = local_3a8;
      }
      puVar17 = puVar15;
      if (local_3a4 == (uint *)0x0) {
        if ((puVar15[3] & 0x40) != 0) {
          FUN_007cf9b0(puVar15);
        }
        goto LAB_007e2f84;
      }
    }
    goto LAB_007e35da;
  case (uint *)0x7:
  case (uint *)0x2a:
    piVar12 = *(int **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    puVar17 = puVar15 + 0x10;
    local_3a8 = puVar17;
    if ((char)piVar12[7] == '\0') {
      iVar7 = *piVar12;
      if (iVar7 == 0) {
        if (*(char *)((int)piVar12 + 0x1e) == '\0') goto LAB_007e2383;
        puVar15[0x12] = piVar12[0xd];
        puVar15[0x16] = piVar12[0xe];
        *(undefined2 *)(puVar15 + 0x13) = 0x110;
      }
      else {
        local_3a4 = (uint *)FUN_007dd1a0(piVar12);
        if (local_3a4 != (uint *)0x0) goto LAB_007e35da;
        if ((char)piVar12[7] == '\0') {
          if (*(char *)((int)piVar12 + 0x21) == '\0') {
            FUN_007d7160(iVar7,&uStack_348);
          }
          else {
            FUN_007d70f0(iVar7,aiStack_2a8 + 0x1e);
            uStack_348 = aiStack_2a8[0x1e];
          }
          puVar15[0x12] = uStack_348;
          if (uStack_348 < 0x21) {
            *(undefined2 *)(puVar15 + 0x13) = 0x210;
            puVar15[0x16] = (uint)(puVar15 + 0x18);
          }
          else {
            uVar10 = FUN_007d0590(uStack_348);
            if (uVar10 == 0) goto LAB_007e3555;
            *(undefined2 *)(puVar15 + 0x13) = 0x50;
            puVar15[0x17] = 0;
            puVar15[0x16] = uVar10;
          }
          if (*(char *)((int)piVar12 + 0x21) == '\0') {
            FUN_007d73b0(iVar7,0,uStack_348,puVar15[0x16]);
          }
          else {
            FUN_007d7380(iVar7,0,uStack_348,puVar15[0x16]);
          }
        }
        else {
          *(undefined2 *)(puVar15 + 0x13) = 1;
        }
      }
    }
    else {
      *(undefined2 *)(puVar15 + 0x13) = 1;
    }
    break;
  case (uint *)0x8:
    if ((*(byte *)(local_3a0 + 2) & 4) == 0) {
      iVar7 = param_1[0x1b];
      if (*(char *)(iVar7 + 0x18) == '\0') {
        *(undefined1 *)(iVar7 + 0x18) = 1;
        if (*(int *)(param_1[0x1b] + 0x10) == 0) {
          iStack_328 = 0;
        }
        else {
          local_3a4 = (uint *)FUN_007d7800(*(int *)(param_1[0x1b] + 0x10),&iStack_328);
        }
      }
      else if (*(int *)(iVar7 + 0x10) == 0) {
        iStack_328 = 1;
      }
      else {
        local_3a4 = (uint *)FUN_007d7b80(*(int *)(iVar7 + 0x10),&iStack_328);
      }
      if (local_3a4 == (uint *)0x0) {
        if (iStack_328 != 0) goto LAB_007e3123;
        iVar7 = *(int *)(param_1[0x1b] + 0x10);
        if ((iVar7 == 0) ||
           (local_3a4 = (uint *)FUN_007d73b0(iVar7,0,4,param_1[0x1b] + 4), local_3a4 == (uint *)0x0)
           ) {
          puStack_39c = (uint *)0x0;
          if (0 < *(int *)param_1[0x1b]) {
            puStack_398 = (uint *)(((int *)param_1[0x1b])[1] + 0x28);
            do {
              puVar15 = puStack_398;
              iVar7 = *(int *)(*(int *)(param_1[0x1b] + 8) + (int)puStack_39c * 4);
              if ((iVar7 != 0) && (*(int *)(iVar7 + 0x1c) != 0)) {
                uStack_11c = 1;
                puStack_110 = puStack_398;
                puStack_e8 = (uint *)puStack_398[-2];
                uStack_e0 = puStack_398[-8];
                puVar19 = puStack_398 + -8;
                aiStack_130[0] = iVar7;
                (**(code **)(iVar7 + 0x1c))(aiStack_130);
                puVar15[-2] = (uint)puStack_e8;
                if ((puStack_e8 != (uint *)0x0) && (puStack_e8 != puVar15)) {
                  FUN_007d05b0(puStack_e8);
                }
                puVar15 = auStack_128;
                for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
                  *puVar19 = *puVar15;
                  puVar15 = puVar15 + 1;
                  puVar19 = puVar19 + 1;
                }
                if ((*(byte *)((int)puStack_398 + -0x13) & 2) != 0) {
                  puStack_398[-2] = (uint)puStack_398;
                }
              }
              puStack_398 = puStack_398 + 0x10;
              puStack_39c = (uint *)((int)puStack_39c + 1);
            } while ((int)puStack_39c < *(int *)param_1[0x1b]);
          }
          break;
        }
      }
      goto LAB_007e35da;
    }
    goto LAB_007e358d;
  case (uint *)0x9:
  case (uint *)0xe:
    puStack_39c = *(uint **)(pbVar22 + 8);
    dStack_370 = (double)CONCAT44(dStack_370._4_4_,*(undefined4 *)(pbVar22 + 4));
    FUN_007d0000(puVar15);
    puStack_398 = *(uint **)(*puVar15 * 0x70 + 4 + local_3a0[1]);
    puVar17 = puVar15 + -0x10;
    puStack_378 = (uint *)(uint)(*pbVar22 == 9);
    local_3a8 = puVar17;
    if ((int)puStack_39c < 1) {
      FUN_007d0000(puVar17);
      puStack_39c = (uint *)*puVar17;
      puVar17 = puVar15 + -0x20;
      local_3a8 = puVar17;
      if ((int)puStack_39c < 2) {
        FUN_007d0700(param_1 + 0x8e,s_root_page_number_less_than_2_00a00f9c,0);
        local_3a4 = (uint *)0x2;
        break;
      }
    }
    puVar17 = local_3a8;
    puVar11 = (undefined4 *)FUN_007df760();
    pbVar22 = local_388;
    if (puVar11 == (undefined4 *)0x0) goto LAB_007e3555;
    *(undefined1 *)(puVar11 + 7) = 1;
    if (puStack_398 != (uint *)0x0) {
      local_3a4 = (uint *)FUN_007db700(puStack_398,puStack_39c,puStack_378,FUN_007dd5c0,
                                       *(undefined4 *)(local_388 + 0xc),puVar11);
      if (*(int *)(pbVar22 + 0x10) == -6) {
        iVar7 = *(int *)(pbVar22 + 0xc);
        puVar11[0x13] = iVar7;
        puVar11[0x12] = iVar7 + 1;
        *(undefined1 *)puVar11[0x13] = *(undefined1 *)(*param_1 + 0x10);
      }
      else {
        puVar11[0x12] = (int)puVar11 + 0x22;
        puVar11[0x13] = 0;
      }
      if (local_3a4 == (uint *)0x0) {
        uVar10 = FUN_007da730(*puVar11);
        if (((uVar10 & 0xf0) == 0) && (((uVar10 & 7) == 5 || ((uVar10 & 7) == 2)))) {
          *(byte *)(puVar11 + 8) = (byte)uVar10 & 1;
          *(byte *)((int)puVar11 + 0x21) = (byte)(uVar10 >> 1) & 1;
          if (((uVar10 & 1) == 0) || (*(int *)(pbVar22 + 0x10) != -6)) {
            if ((uVar10 >> 1 & 1) != 0) {
              if (*(int *)(local_388 + 0x10) != -6) goto LAB_007e1435;
            }
            break;
          }
        }
LAB_007e1435:
        local_3a4 = (uint *)0xb;
        goto LAB_007e35da;
      }
      if (local_3a4 == (uint *)0x5) {
        param_1[0x21] = local_394;
        param_1[0x22] = 5;
        param_1[0xb] = (int)(puVar17 + ((*(int *)(pbVar22 + 8) < 1) + 1) * 0x10);
        return 5;
      }
      if (local_3a4 != (uint *)0x10) goto LAB_007e35da;
      iVar7 = *(int *)(local_388 + 0x10);
      *(bool *)(puVar11 + 8) = iVar7 != -6;
      *(bool *)((int)puVar11 + 0x21) = iVar7 == -6;
      local_3a4 = (uint *)0x0;
    }
    break;
  case (uint *)0xa:
  case (uint *)0x4c:
    if ((puVar15[3] & 1) == 0) {
      fVar25 = (float10)FUN_007d0050(puVar15);
      uVar10 = (uint)((float10)_DAT_0099d098 != fVar25);
      if (*pbVar22 == 0x4c) {
        uVar10 = (uint)(uVar10 == 0);
      }
    }
    else {
      uVar10 = *(uint *)(pbVar22 + 4);
    }
    if ((puVar15[3] & 0x40) != 0) {
      FUN_007cf9b0(puVar15);
    }
    puVar17 = puVar15 + -0x10;
    local_3a8 = puVar17;
    if (uVar10 != 0) {
      local_394 = *(int *)(pbVar22 + 8) + -1;
    }
    break;
  case (uint *)0xb:
    FUN_007df690(&local_3a8);
    goto LAB_007e32f5;
  case (uint *)0xc:
    param_1[0x1b] = param_1[0x1b] + 0x1c;
    break;
  case (uint *)0xd:
  case (uint *)0x17:
    break;
  case (uint *)0xf:
    if (*(int *)(pbVar22 + 4) == 0) {
      FUN_007dda50(local_3a0);
    }
    else {
      *(undefined1 *)(param_1 + 0x90) = 1;
    }
    break;
  case (uint *)0x10:
    FUN_007dcaf0(param_1);
    break;
  case (uint *)0x11:
    bStack_381 = pbVar22[4];
    if (((local_3a0[0x13] < 2) || (bStack_381 == 0)) || (*(char *)((int)local_3a0 + 0x11) != '\0'))
    {
      if (bStack_381 != *(byte *)((int)local_3a0 + 0x11)) {
        *(byte *)((int)local_3a0 + 0x11) = bStack_381;
        if (*(int *)(pbVar22 + 8) == 0) {
          iVar7 = FUN_007ddd70(param_1);
          if (iVar7 == 5) {
            param_1[0xb] = (int)puVar15;
            param_1[0x21] = local_394;
            *(byte *)((int)local_3a0 + 0x11) = '\x01' - bStack_381;
            goto LAB_007e3471;
          }
        }
        else {
          FUN_007cd350(local_3a0);
        }
        return 0x65;
      }
      if (bStack_381 == 0) {
        pcVar8 = s_cannot_start_a_transaction_withi_00a01014;
      }
      else {
        pcVar8 = s_cannot_rollback___no_transaction_00a00fe8;
        if (pbVar22[8] == 0) {
          pcVar8 = s_cannot_commit___no_transaction_i_00a00fbc;
        }
      }
      FUN_007d0700(param_1 + 0x8e,pcVar8,0);
      local_3a4 = (uint *)0x1;
    }
    else {
      pcVar8 = s_rollback_00a01080;
      if (pbVar22[8] == 0) {
        pcVar8 = s_commit_00a01078;
      }
      FUN_007d0700(param_1 + 0x8e,s_cannot_00a01044,pcVar8,
                   s_transaction___SQL_statements_in_p_00a0104c,0);
      local_3a4 = (uint *)0x1;
    }
    break;
  case (uint *)0x12:
    puVar4 = *(undefined1 **)(pbVar22 + 0xc);
    DAT_00b5c4e4 = DAT_00b5c4e4 + 1;
    aiStack_2a8[0] = 0;
    aiStack_2a8[1] = 0;
    aiStack_2a8[2] = 0;
    aiStack_2a8[3] = 0;
    aiStack_2a8[4] = 0;
    aiStack_2a8[5] = 0;
    aiStack_2a8[6] = 0;
    aiStack_2a8[7] = 0;
    aiStack_2a8[8] = 0;
    aiStack_2a8[9] = 0;
    aiStack_2a8[10] = 0;
    aiStack_2a8[0xb] = 0;
    aiStack_2a8[0xc] = 0;
    aiStack_2a8[0xd] = 0;
    aiStack_2a8[0xe] = 0;
    aiStack_2a8[0xf] = 0;
    aiStack_2a8[0x10] = 0;
    aiStack_2a8[0x11] = 0;
    aiStack_2a8[0x12] = 0;
    aiStack_2a8[0x13] = 0;
    aiStack_2a8[0x14] = 0;
    aiStack_2a8[0x15] = 0;
    aiStack_2a8[0x16] = 0;
    aiStack_2a8[0x17] = 0;
    aiStack_2a8[0x18] = 0;
    aiStack_2a8[0x19] = 0;
    aiStack_2a8[0x1a] = 0;
    *puVar4 = *(undefined1 *)(*param_1 + 0x10);
    iVar7 = param_1[0x10];
    aiStack_2a8[0x1b] = 0;
    aiStack_2a8[0x1c] = 0;
    aiStack_2a8[0x1d] = 0;
    while (iVar7 != 0) {
      iVar7 = param_1[0x10];
      param_1[0x10] = *(int *)(iVar7 + 0x48);
      *(undefined4 *)(iVar7 + 0x48) = 0;
      iVar13 = 0;
      do {
        if (aiStack_2a8[iVar13] == 0) {
          aiStack_2a8[iVar13] = iVar7;
          if (iVar13 < 0x1d) goto LAB_007e2b9e;
          break;
        }
        iVar7 = FUN_007df6c0(puVar4);
        aiStack_2a8[iVar13] = 0;
        iVar13 = iVar13 + 1;
      } while (iVar13 < 0x1d);
      aiStack_2a8[0x1d] = FUN_007df6c0(puVar4);
LAB_007e2b9e:
      iVar7 = param_1[0x10];
    }
    iVar7 = 0;
    do {
      iVar13 = FUN_007df6c0(puVar4);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x1e);
    param_1[0x10] = iVar13;
    break;
  case (uint *)0x13:
    iVar7 = param_1[0x1d];
    iVar13 = 0;
    while (iVar7 != 0) {
      iVar18 = param_1[0x1d];
      param_1[0x1d] = *(int *)(iVar18 + 0xc);
      *(int *)(iVar18 + 0xc) = iVar13;
      iVar13 = iVar18;
      iVar7 = param_1[0x1d];
    }
    param_1[0x1d] = iVar13;
    break;
  case (uint *)0x14:
    iVar7 = 0;
    if ((uint *)param_1[10] <= puVar15) {
      iVar13 = 0;
      puVar19 = puVar15;
      do {
        if ((puVar19[3] & 4) == 0) break;
        iVar13 = iVar13 + 0x40;
        puVar19 = (uint *)((int)puVar15 - iVar13);
        iVar7 = iVar7 + 1;
        dStack_370 = (double)CONCAT44(dStack_370._4_4_,puVar19);
      } while ((uint *)param_1[10] <= puVar19);
    }
    puStack_398 = (uint *)FUN_007d0590(iVar7 * 4 + 4);
    if (puStack_398 != (uint *)0x0) {
      iVar13 = 0;
      if (0 < iVar7) {
        do {
          puStack_398[iVar13] = *puVar15;
          iVar13 = iVar13 + 1;
          puVar15 = puVar15 + -0x10;
        } while (iVar13 < iVar7);
      }
      puStack_398[iVar13] = 0;
      FUN_007df690(&local_3a8);
      puVar17 = local_3a8;
      puVar15 = local_3a8 + 0x10;
      local_3a8 = puVar15;
      pcVar8 = (char *)FUN_007dbd20(*(undefined4 *)(*(int *)(pbVar22 + 8) * 0x70 + 4 + local_3a0[1])
                                    ,puStack_398,iVar7);
      if (pcVar8 == (char *)0x0) {
LAB_007e27d4:
        puVar17[0x16] = (uint)&DAT_00a00f60;
        puVar17[0x12] = 2;
        *(undefined2 *)(puVar17 + 0x13) = 0xa2;
      }
      else {
        if (*pcVar8 == '\0') {
          FUN_007d05b0(pcVar8);
          goto LAB_007e27d4;
        }
        puVar17[0x16] = (uint)pcVar8;
        pcVar9 = pcVar8 + 1;
        do {
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        puVar17[0x12] = (int)pcVar8 - (int)pcVar9;
        *(undefined2 *)(puVar17 + 0x13) = 0x62;
        puVar17[0x17] = 0;
      }
      *(undefined1 *)((int)puVar17 + 0x4f) = 1;
      FUN_007cfe90(puVar15,(char)local_3a0[4]);
      FUN_007d05b0(puStack_398);
      goto LAB_007e32f5;
    }
    goto LAB_007e3555;
  case (uint *)0x15:
    iVar7 = FUN_007cf820(puVar15);
    if (iVar7 != 0) goto LAB_007e3555;
    puVar19 = (uint *)FUN_007d0590(0x50);
    if (puVar19 == (uint *)0x0) goto LAB_007e3555;
    puVar19[0x12] = 0;
    if (param_1[0x11] == 0) {
      param_1[0x10] = (int)puVar19;
    }
    else {
      *(uint **)(param_1[0x11] + 0x48) = puVar19;
    }
    param_1[0x11] = (int)puVar19;
    *puVar19 = puVar15[2];
    puVar19[1] = puVar15[6];
    *(undefined2 *)(puVar19 + 5) = 1;
    local_3a4 = (uint *)FUN_007cfb80(puVar19 + 2,puVar15 + -0x10);
    puVar17 = puVar15 + -0x20;
    local_3a8 = puVar15 + -0x20;
    break;
  case (uint *)0x16:
    iVar7 = *(int *)(pbVar22 + 4);
    puStack_39c = (uint *)param_1[0xc];
    puVar15 = puVar15 + iVar7 * -0x10;
    iVar13 = 0;
    if (0 < iVar7) {
      do {
        puStack_39c[iVar13] = (uint)(puVar15 + 0x10);
        FUN_007df5a0();
        iVar13 = extraout_EDX + 1;
        puVar15 = extraout_ECX;
      } while (iVar13 < iVar7);
    }
    puVar11 = *(undefined4 **)(pbVar22 + 0xc);
    if (*(int *)(pbVar22 + 0x10) == -5) {
      puStack_21c = (undefined4 *)0x0;
      puStack_220 = puVar11;
    }
    else {
      puStack_220 = (undefined4 *)*puVar11;
      puStack_21c = puVar11;
    }
    uStack_20c = 1;
    uStack_200 = 0;
    uStack_1fc = 0;
    cStack_1d4 = '\0';
    if (*(char *)(puStack_220 + 8) != '\0') {
      uStack_1cc = *(undefined4 *)(pbVar22 + -8);
    }
    iVar13 = FUN_007d0ea0(local_3a0);
    if (iVar13 != 0) goto LAB_007e3284;
    (*(code *)puStack_220[5])(&puStack_220,iVar7,puStack_39c);
    iVar7 = FUN_007d0e60(local_3a0);
    if (iVar7 == 0) {
      if (DAT_00b5c4c4 == 0) {
        FUN_007df690(&local_3a8);
        if (puStack_21c != (undefined4 *)0x0) {
          FUN_007dd140(puStack_21c,*(undefined4 *)(pbVar22 + 8));
          *(undefined4 **)(pbVar22 + 0xc) = puStack_21c;
          pbVar22[0x10] = 0xf9;
          pbVar22[0x11] = 0xff;
          pbVar22[0x12] = 0xff;
          pbVar22[0x13] = 0xff;
        }
        piVar12 = local_3a0;
        FUN_007cfe90(auStack_218,(char)local_3a0[4]);
        puVar17 = local_3a8 + 0x10;
        *(undefined2 *)(local_3a8 + 0x13) = 0;
        local_3a8 = puVar17;
        FUN_007cfb80(puVar17,auStack_218);
        puVar17 = local_3a8;
        if (cStack_1d4 != '\0') {
          if ((local_3a8[3] & 2) == 0) {
            FUN_007d0700(param_1 + 0x8e,s_user_function_error_00a0108c);
            local_3a4 = (uint *)0x1;
          }
          else {
            uVar14 = FUN_007cdf50(local_3a8,0);
            FUN_007d0700(param_1 + 0x8e,uVar14);
            FUN_007cfe90(puVar17,(char)piVar12[4]);
            local_3a4 = (uint *)0x1;
          }
        }
        goto LAB_007e32f5;
      }
      goto LAB_007e3555;
    }
    goto LAB_007e3284;
  case (uint *)0x18:
    iVar7 = param_1[0x8a];
    param_1[0x8a] = iVar7 + -1;
    local_394 = param_1[iVar7 + 0x25] + -1;
    break;
  case (uint *)0x19:
    uStack_380 = 0;
    uStack_37c = 0;
    local_388 = *(byte **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    if (*(int *)local_388 != 0) {
      puStack_398 = (uint *)0x0;
      bVar6 = FUN_007da730(*(int *)local_388);
      if ((bVar6 & 3) != 1) {
        local_3a4 = (uint *)0xb;
        goto LAB_007e35da;
      }
      if (local_388[0x1b] == 0) {
        if (local_388[0x1d] == 0) {
          puStack_398 = (uint *)FUN_007d7840(*(undefined4 *)local_388,&iStack_318);
          if (iStack_318 == 0) {
            FUN_007d70f0(*(undefined4 *)local_388,&uStack_380);
            if ((uStack_380 == 0xffffffff) && (uStack_37c == 0x7fffffff)) {
              local_388[0x1b] = 1;
            }
            else {
              bVar24 = 0xfffffffe < uStack_380;
              uStack_380 = uStack_380 + 1;
              uStack_37c = uStack_37c + bVar24;
            }
          }
          else {
            uStack_380 = 1;
            uStack_37c = 0;
          }
        }
        else {
          uStack_380 = *(uint *)(local_388 + 0x10);
          uStack_37c = *(uint *)(local_388 + 0x14);
        }
        if (*(int *)(pbVar22 + 8) == 0) {
LAB_007e1b2a:
          if ((uStack_37c < 0x80000000) && ((uStack_37c < 0x7fffffff || (uStack_380 != 0xffffffff)))
             ) {
            local_388[0x1d] = 1;
            *(uint *)(local_388 + 0x10) = uStack_380 + 1;
            *(uint *)(local_388 + 0x14) = uStack_37c + (0xfffffffe < uStack_380);
          }
          else {
            local_388[0x1d] = 0;
          }
          goto LAB_007e1b63;
        }
        puVar19 = (uint *)(*(int *)(pbVar22 + 8) * 0x40 + param_1[0x18]);
        FUN_007d0000(puVar19);
        uVar10 = *puVar19;
        if (((uVar10 != 0xffffffff) || (puVar19[1] != 0x7fffffff)) && (local_388[0x1b] == 0)) {
          uVar16 = puVar19[1] + (uint)(0xfffffffe < uVar10);
          if ((int)uStack_37c <= (int)uVar16) {
            if ((int)uVar16 <= (int)uStack_37c) {
              if (uVar10 + 1 <= uStack_380) goto LAB_007e1b1d;
            }
            uStack_380 = uVar10 + 1;
            uStack_37c = uVar16;
          }
LAB_007e1b1d:
          *puVar19 = uStack_380;
          puVar19[1] = uStack_37c;
          goto LAB_007e1b2a;
        }
LAB_007e350e:
        local_3a4 = (uint *)0xd;
        goto LAB_007e35da;
      }
LAB_007e1b63:
      if (local_388[0x1b] != 0) {
        uStack_380 = local_3a0[10];
        uStack_37c = local_3a0[0xb];
        iVar7 = 0;
        do {
          if ((uStack_380 == 0 && uStack_37c == 0) || (2 < iVar7)) {
            FUN_007e6500(8,&uStack_380);
            if (iVar7 < 5) {
              uStack_380 = uStack_380 & 0xffffff;
              uStack_37c = 0;
            }
          }
          else {
            FUN_007e6500(1,&bStack_349);
            bVar24 = CARRY4(uStack_380,bStack_349 + 1);
            uStack_380 = uStack_380 + bStack_349 + 1;
            uStack_37c = uStack_37c + bVar24;
          }
          if (uStack_380 != 0 || uStack_37c != 0) {
            puStack_398 = (uint *)FUN_007d7880(*(undefined4 *)local_388,0,uStack_380,uStack_37c,
                                               &iStack_318);
            iVar7 = iVar7 + 1;
          }
        } while (((iVar7 < 1000) && (puStack_398 == (uint *)0x0)) && (iStack_318 == 0));
        local_3a0[0xb] = uStack_37c;
        local_3a0[10] = uStack_380;
        if ((puStack_398 == (uint *)0x0) && (iStack_318 == 0)) goto LAB_007e350e;
      }
      local_388[0x19] = 0;
      local_388[0x1f] = 0;
      local_388[0x54] = 0;
    }
    puVar17 = puVar15 + 0x10;
    *puVar17 = uStack_380;
    puVar15[0x11] = uStack_37c;
    *(undefined2 *)(puVar15 + 0x13) = 4;
    local_3a8 = puVar17;
    break;
  case (uint *)0x1a:
    puVar17 = puVar15 + 0x10;
    local_3a8 = puVar17;
    FUN_007cfae0(puVar17,*(int *)(pbVar22 + 4) * 0x40 + -0x40 + param_1[0x13],0x80);
    break;
  case (uint *)0x1b:
switchD_007df9a7_caseD_1b:
    puVar17 = puVar15 + 0x10;
    *(undefined2 *)(puVar15 + 0x13) = 0xa2;
    pcVar8 = *(char **)(pbVar22 + 0xc);
    puVar15[0x16] = (uint)pcVar8;
    local_3a8 = puVar17;
    if ((char)local_3a0[4] == '\x01') {
      pcVar9 = pcVar8 + 1;
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      puVar15[0x12] = (int)pcVar8 - (int)pcVar9;
      *(char *)((int)puVar15 + 0x4f) = (char)local_3a0[4];
    }
    else {
      uVar10 = FUN_007e5c70(pcVar8,0xffffffff);
      puVar15[0x12] = uVar10;
      *(char *)((int)puVar15 + 0x4f) = (char)local_3a0[4];
    }
    break;
  case (uint *)0x1c:
    iVar7 = *(int *)(pbVar22 + 4);
    puVar11 = (undefined4 *)(iVar7 * 0x70 + local_3a0[1]);
    if ((*(byte *)(puVar11 + 0x17) & 1) != 0) {
      puStack_39c = (uint *)s_sqlite_temp_master_009fff68;
      if (iVar7 != 1) {
        puStack_39c = (uint *)s_sqlite_master_009fff58;
      }
      piStack_2b0 = local_3a0;
      piStack_2ac = param_1 + 0x8e;
      iVar7 = FUN_007e4830(s_SELECT_name__rootpage__sql___d_F_00a00f64,iVar7,*puVar11,puStack_39c,
                           *(undefined4 *)(pbVar22 + 0xc));
      piVar12 = local_3a0;
      if (iVar7 == 0) goto LAB_007e3555;
      FUN_007d0ea0(local_3a0);
      *(undefined1 *)(piVar12 + 0x11) = 1;
      local_3a4 = (uint *)FUN_007cdb70(piVar12,iVar7,FUN_007ce490,&piStack_2b0,0);
      *(undefined1 *)(piVar12 + 0x11) = 0;
      FUN_007d0e60(piVar12);
      FUN_007d05b0(iVar7);
    }
    break;
  case (uint *)0x1d:
    iVar7 = *(int *)(pbVar22 + 8);
    puVar17 = puVar15 + iVar7 * -0x10;
    puStack_39c = (uint *)param_1[0xc];
    iVar13 = 0;
    if (0 < iVar7) {
      do {
        puStack_39c[iVar13] = (uint)puVar17;
        FUN_007df5a0();
        iVar13 = extraout_EDX_00 + 1;
        puVar17 = (uint *)(extraout_ECX_00 + 0x40);
      } while (iVar13 < iVar7);
    }
    aiStack_188[0] = *(int *)(pbVar22 + 0xc);
    puVar17 = (uint *)(*(int *)(param_1[0x1b] + 4) + 8 + *puVar15 * 0x40);
    puStack_168 = puVar17 + 8;
    uStack_140 = puVar17[6];
    uVar10 = *puVar17;
    *puVar17 = uVar10 + 1;
    puVar17[1] = puVar17[1] + (uint)(0xfffffffe < uVar10);
    uStack_138 = *puVar17;
    cStack_13c = '\0';
    uStack_134 = 0;
    if (*(char *)(aiStack_188[0] + 0x20) != '\0') {
      uStack_134 = *(undefined4 *)(pbVar22 + -8);
    }
    (**(code **)(aiStack_188[0] + 0x18))(aiStack_188,iVar7,puStack_39c);
    puVar17[6] = uStack_140;
    *(undefined2 *)(puVar17 + 3) = 0x400;
    FUN_007df690(&local_3a8);
    puVar17 = local_3a8;
    if (cStack_13c != '\0') {
      local_3a4 = (uint *)0x1;
    }
    break;
  case (uint *)0x1e:
    iVar7 = *(int *)(pbVar22 + 4);
    if (-1 < iVar7) {
      if (iVar7 < param_1[0xe]) {
        FUN_007dcc30(*(undefined4 *)(param_1[0xf] + iVar7 * 4));
        *(undefined4 *)(param_1[0xf] + iVar7 * 4) = 0;
      }
    }
    break;
  case (uint *)0x1f:
    piVar12 = (int *)param_1[0x1d];
    if ((piVar12 == (int *)0x0) || (*piVar12 <= piVar12[1])) {
      piVar12 = (int *)FUN_007d0590(0x1f50);
      if (piVar12 == (int *)0x0) goto LAB_007e3555;
      piVar12[2] = 0;
      piVar12[1] = 0;
      *piVar12 = 1000;
      piVar12[3] = param_1[0x1d];
      param_1[0x1d] = (int)piVar12;
    }
    FUN_007d0000(puVar15);
    iVar7 = piVar12[1];
    piVar12[iVar7 * 2 + 4] = *puVar15;
    piVar12[iVar7 * 2 + 5] = puVar15[1];
    piVar12[1] = piVar12[1] + 1;
    puVar17 = puVar15 + -0x10;
    local_3a8 = puVar15 + -0x10;
    break;
  case (uint *)0x20:
  case (uint *)0x35:
    local_3a4 = (uint *)FUN_007db850(*(undefined4 *)
                                      (*(int *)(pbVar22 + 4) * 0x70 + local_3a0[1] + 4),&uStack_2dc,
                                     ((bVar6 != 0x35) - 1U & 3) + 2);
    puVar17 = puVar15 + 0x10;
    if (local_3a4 == (uint *)0x0) {
      *puVar17 = uStack_2dc;
      puVar15[0x11] = (int)uStack_2dc >> 0x1f;
      *(undefined2 *)(puVar15 + 0x13) = 4;
      local_3a8 = puVar17;
    }
    else {
LAB_007e2383:
      *(undefined2 *)(puVar15 + 0x13) = 1;
      puVar17 = puVar15 + 0x10;
      local_3a8 = puVar15 + 0x10;
    }
    break;
  case (uint *)0x21:
    dStack_370 = (double)CONCAT44(dStack_370._4_4_,*(undefined4 *)(pbVar22 + 4));
    puVar17 = puVar15 + -0x10;
    FUN_007d0000(puVar15);
    uStack_2f0 = *puVar15;
    uStack_2ec = puVar15[1];
    puVar11 = *(undefined4 **)(param_1[0xf] + dStack_370._0_4_ * 4);
    puStack_39c = (uint *)*puVar11;
    local_3a8 = puVar17;
    if (puStack_39c != (uint *)0x0) {
      if (((puVar15[-0xd] & 0x12) != 0) ||
         (iVar7 = FUN_007cfee0(puVar17,(char)local_3a0[4]), iVar7 == 0)) {
        puStack_398 = (uint *)puVar15[-10];
        uVar10 = puVar15[-0xe];
        iVar7 = FUN_007dd810(uVar10,puStack_398);
        iVar7 = uVar10 - iVar7;
        *(undefined1 *)(puVar11 + 0x15) = 0;
        iVar13 = FUN_007d7880(puStack_39c,puStack_398,iVar7,iVar7 >> 0x1f,&iStack_340);
        puVar17 = local_3a8;
        if (iVar13 != 0) goto LAB_007e35da;
        if ((-1 < iStack_340) || (FUN_007d7b80(puStack_39c,&iStack_340), iStack_340 == 0)) {
          iVar7 = FUN_007dd960(puVar11,iVar7,puStack_398,&iStack_340);
          puVar17 = local_3a8;
          if (iVar7 != 0) goto LAB_007e35da;
          if (iStack_340 < 1) {
            iVar7 = FUN_007dd860(puStack_39c,&uStack_2c0);
            puVar17 = local_3a8;
            if (iVar7 != 0) goto LAB_007e35da;
            if ((uStack_2c0 != uStack_2f0) || (uStack_2bc != uStack_2ec)) {
              local_3a8[0x10] = uStack_2c0;
              local_3a8[0x11] = uStack_2bc;
              *(undefined2 *)(local_3a8 + 0x13) = 4;
              local_3a8 = local_3a8 + 0x10;
              goto LAB_007e32f5;
            }
          }
        }
        iVar7 = *(int *)(pbVar22 + 8);
LAB_007e32f0:
        local_394 = iVar7 + -1;
        goto LAB_007e32f5;
      }
      puVar17 = local_3a8;
      goto LAB_007e3555;
    }
    goto LAB_007e32f5;
  case (uint *)0x22:
    puStack_39c = *(uint **)(pbVar22 + 4);
    puStack_398 = (uint *)puVar15[2];
    dStack_370 = (double)CONCAT44(dStack_370._4_4_,puVar15[6]);
    iVar7 = FUN_007d1120(puVar15[6],&iStack_2f4);
    if (iVar7 < (int)puStack_398) {
      do {
        if ((int)puStack_39c < 1) break;
        iVar13 = FUN_007d1120(iVar7 + dStack_370._0_4_,&iStack_2f4);
        iVar7 = iVar7 + iVar13;
        if (iStack_2f4 == 0) goto LAB_007e244b;
        puStack_39c = (uint *)((int)puStack_39c + -1);
      } while (iVar7 < (int)puStack_398);
    }
    goto LAB_007e2453;
  case (uint *)0x23:
  case (uint *)0x6f:
  case (uint *)0x7b:
    piVar12 = *(int **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    bVar24 = false;
    if (*piVar12 != 0) {
      if ((puVar15[3] & 0x12) == 0) {
        iVar7 = FUN_007cfee0(puVar15,(char)local_3a0[4]);
        if (iVar7 != 0) goto LAB_007e3555;
      }
      iVar7 = FUN_007d7880(*piVar12,puVar15[6],puVar15[2],(int)puVar15[2] >> 0x1f,&iStack_2c8);
      if ((iVar7 == 0) && (iStack_2c8 == 0)) {
        bVar24 = true;
      }
      else {
        bVar24 = false;
      }
      *(undefined1 *)((int)piVar12 + 0x1f) = 0;
      *(undefined1 *)(piVar12 + 0x15) = 0;
    }
    if (*pbVar22 == 0x7b) {
      if (bVar24) goto LAB_007e17db;
    }
    else if (!bVar24) {
LAB_007e17db:
      local_394 = *(int *)(pbVar22 + 8) + -1;
    }
    if (*pbVar22 != 0x6f) {
      if ((puVar15[3] & 0x40) == 0) goto LAB_007e2f84;
      FUN_007cf9b0(puVar15);
      puVar17 = puVar15 + -0x10;
      local_3a8 = puVar15 + -0x10;
    }
    break;
  case (uint *)0x24:
    FUN_007df790((char)local_3a0[4]);
    if ((puVar15[3] & 4) == 0) {
      if (*(int *)(pbVar22 + 8) == 0) {
        local_3a4 = (uint *)0x14;
        goto LAB_007e35da;
      }
      if (*(int *)(pbVar22 + 4) != 0) {
        if ((puVar15[3] & 0x40) != 0) {
          FUN_007cf9b0(puVar15);
        }
        goto LAB_007e04b8;
      }
LAB_007e04bf:
      local_394 = *(int *)(pbVar22 + 8) + -1;
      puVar17 = puVar15;
    }
    else {
      if ((puVar15[3] & 0x40) != 0) {
        FUN_007cf9b0(puVar15);
      }
      *(undefined2 *)(puVar15 + 3) = 4;
    }
    break;
  case (uint *)0x25:
    param_1[0xb] = (int)puVar15;
    param_1[0x22] = *(int *)(pbVar22 + 4);
    param_1[0x21] = local_394;
    param_1[0x24] = *(int *)(pbVar22 + 8);
    if (*(int *)(pbVar22 + 0xc) != 0) {
      FUN_007d0700(param_1 + 0x8e,*(int *)(pbVar22 + 0xc),0);
    }
    iVar7 = FUN_007ddd70(param_1);
    if (iVar7 != 5) {
      return (-(uint)(param_1[0x22] != 0) & 0xffffff9c) + 0x65;
    }
LAB_007e3471:
    param_1[0x22] = 5;
    return 5;
  case (uint *)0x26:
    piVar12 = *(int **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    local_3a4 = (uint *)FUN_007dd1a0(piVar12);
    if (local_3a4 != (uint *)0x0) goto LAB_007e35da;
    puVar17 = puVar15 + 0x10;
    local_3a8 = puVar17;
    if (*(char *)((int)piVar12 + 0x19) == '\0') {
      if (*(char *)((int)piVar12 + 0x1e) == '\0') {
        if (((char)piVar12[7] != '\0') || (*piVar12 == 0)) goto LAB_007e2383;
        FUN_007d70f0(*piVar12,&uStack_310);
      }
      else {
        uStack_310 = piVar12[0x10];
        uStack_30c = piVar12[0x11];
      }
    }
    else {
      uStack_310 = piVar12[2];
      uStack_30c = piVar12[3];
    }
    *puVar17 = uStack_310;
    puVar15[0x11] = uStack_30c;
    *(undefined2 *)(puVar15 + 0x13) = 4;
    break;
  case (uint *)0x27:
  case (uint *)0x3d:
  case (uint *)0x63:
    piVar12 = *(int **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    if (*piVar12 != 0) {
      if ((puVar15[3] & 0x12) == 0) {
        iVar7 = FUN_007cfee0(puVar15,(char)local_3a0[4]);
        if (iVar7 != 0) goto LAB_007e3555;
      }
      *(bool *)piVar12[0x12] = *(int *)(pbVar22 + 0xc) != 0;
      iVar7 = FUN_007dd960(piVar12,puVar15[2],puVar15[6],&iStack_344);
      *(undefined1 *)piVar12[0x12] = 0;
      if (iVar7 != 0) break;
      if (*pbVar22 == 0x27) {
        iStack_344 = -iStack_344;
      }
      else if (*pbVar22 == 0x3d) {
        iStack_344 = iStack_344 + 1;
      }
      if (0 < iStack_344) {
LAB_007e244b:
        local_394 = *(int *)(pbVar22 + 8) + -1;
      }
    }
LAB_007e2453:
    if ((puVar15[3] & 0x40) == 0) {
LAB_007e2f84:
      puVar17 = puVar15 + -0x10;
      local_3a8 = puVar15 + -0x10;
    }
    else {
      FUN_007cf9b0(puVar15);
      puVar17 = puVar15 + -0x10;
      local_3a8 = puVar15 + -0x10;
    }
    break;
  case (uint *)0x28:
    FUN_007d0000(puVar15);
    uVar10 = *(uint *)(pbVar22 + 4);
    uVar16 = *puVar15;
    *puVar15 = uVar16 + uVar10;
    puVar15[1] = puVar15[1] + ((int)uVar10 >> 0x1f) + (uint)CARRY4(uVar16,uVar10);
    break;
  case (uint *)0x29:
    iVar7 = *(int *)(pbVar22 + 4);
    if (-1 < iVar7) {
      if (iVar7 < *local_3a0) {
        iVar7 = *(int *)(iVar7 * 0x70 + 4 + local_3a0[1]);
        if (iVar7 != 0) {
          if (*(char *)((int)local_3a0 + 0x11) == '\0') {
            iVar13 = FUN_007db290(iVar7);
            if (iVar13 == 0) {
              local_3a4 = (uint *)FUN_007d6fc0(iVar7);
            }
          }
        }
      }
    }
    break;
  case (uint *)0x2b:
    puVar19 = (uint *)(*(int *)(pbVar22 + 4) * 0x40 + param_1[0x18]);
    FUN_007d0000(puVar19);
    FUN_007d0000(puVar15);
    uVar10 = puVar15[1];
    if ((int)puVar19[1] <= (int)uVar10) {
      if ((int)uVar10 <= (int)puVar19[1]) {
        if (*puVar15 <= *puVar19) break;
      }
      *puVar19 = *puVar15;
      puVar19[1] = uVar10;
    }
    break;
  case (uint *)0x2c:
    FUN_007cfb80(puVar15 + *(int *)(pbVar22 + 4) * -0x10,puVar15);
    puVar17 = puVar15 + -0x10;
    local_3a8 = puVar15 + -0x10;
    break;
  case (uint *)0x2d:
    piVar12 = *(int **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    if (*piVar12 != 0) {
      local_3a4 = (uint *)FUN_007d7880(*piVar12,0,*puVar15,puVar15[1],&iStack_2e8);
      piVar12[2] = *puVar15;
      piVar12[3] = puVar15[1];
      *(bool *)((int)piVar12 + 0x19) = iStack_2e8 == 0;
      *(undefined1 *)(piVar12 + 7) = 0;
      *(undefined1 *)(piVar12 + 0x15) = 0;
      if (iStack_2e8 != 0) {
        local_394 = *(int *)(pbVar22 + 8) + -1;
        *(undefined1 *)((int)piVar12 + 0x19) = 0;
      }
    }
    if ((puVar15[3] & 0x40) != 0) {
      FUN_007cf9b0(puVar15);
      puVar17 = puVar15 + -0x10;
      local_3a8 = puVar15 + -0x10;
      break;
    }
    goto LAB_007e2f84;
  case (uint *)0x2e:
    iVar7 = FUN_007df760();
    if (iVar7 == 0) goto LAB_007e3555;
    puVar11 = (undefined4 *)(iVar7 + 0x30);
    *(undefined1 *)(iVar7 + 0x1c) = 1;
    local_3a4 = (uint *)FUN_007cd6c0(local_3a0,0,1,500,puVar11);
    if ((local_3a4 == (uint *)0x0) &&
       (local_3a4 = (uint *)FUN_007d69e0(*puVar11,1), local_3a4 == (uint *)0x0)) {
      if (*(int *)(local_388 + 0xc) != 0) {
        local_3a4 = (uint *)FUN_007db850(*puVar11,&uStack_2d8,2);
        if (local_3a4 == (uint *)0x0) {
          local_3a4 = (uint *)FUN_007db700(*puVar11,uStack_2d8,1,FUN_007dd5c0,
                                           *(undefined4 *)(local_388 + 0xc),iVar7);
          puVar4 = *(undefined1 **)(local_388 + 0xc);
          *(undefined1 **)(iVar7 + 0x4c) = puVar4;
          *puVar4 = *(undefined1 *)(*param_1 + 0x10);
          *(int *)(iVar7 + 0x48) = *(int *)(iVar7 + 0x4c) + 1;
        }
        *(undefined1 *)(iVar7 + 0x20) = 0;
        *(bool *)(iVar7 + 0x21) = *(char *)(iVar7 + 0x20) == '\0';
        break;
      }
      local_3a4 = (uint *)FUN_007db700(*puVar11,1,1,0,0,iVar7);
      *(undefined1 *)(iVar7 + 0x20) = 1;
      *(int *)(iVar7 + 0x48) = iVar7 + 0x22;
    }
    *(bool *)(iVar7 + 0x21) = *(char *)(iVar7 + 0x20) == '\0';
    break;
  case (uint *)0x2f:
    iVar7 = param_1[0x18];
    iVar13 = *(int *)(pbVar22 + 4) * 0x40;
    iVar21 = *(uint *)(iVar13 + iVar7) + 1;
    iVar18 = *(int *)(iVar13 + 4 + iVar7) + (uint)(0xfffffffe < *(uint *)(iVar13 + iVar7));
    *(int *)(iVar13 + iVar7) = iVar21;
    ((int *)(iVar13 + iVar7))[1] = iVar18;
    if (0 < *(int *)(pbVar22 + 8)) {
      if (iVar21 == 1) {
        if (iVar18 == 0) {
          local_394 = *(int *)(pbVar22 + 8) + -1;
        }
      }
    }
    break;
  case (uint *)0x30:
    param_1[param_1[0x8a] + 0x26] = local_394 + 1;
    param_1[0x8a] = param_1[0x8a] + 1;
    local_394 = *(int *)(pbVar22 + 8) + -1;
    break;
  case (uint *)0x31:
    if (*(int *)(param_1[0x1b] + 4) == 0) goto LAB_007e3555;
    local_3a4 = (uint *)FUN_007cfb80(*(int *)(pbVar22 + 8) * 0x40 + 8 + *(int *)(param_1[0x1b] + 4),
                                     puVar15);
    puVar17 = puVar15 + -0x10;
    local_3a8 = puVar15 + -0x10;
    break;
  case (uint *)0x32:
    puVar17 = puVar15 + 0x10;
    local_3a8 = puVar17;
    if (*(int *)(pbVar22 + 0xc) == 0) {
      *(undefined2 *)(puVar15 + 0x13) = 4;
      uVar10 = *(uint *)(pbVar22 + 4);
      *puVar17 = uVar10;
      puVar15[0x11] = (int)uVar10 >> 0x1f;
    }
    else {
      *(undefined2 *)(puVar15 + 0x13) = 0xa2;
      pcVar9 = *(char **)(pbVar22 + 0xc);
      puVar15[0x16] = (uint)pcVar9;
      pcVar8 = pcVar9 + 1;
      do {
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      puVar15[0x12] = (int)pcVar9 - (int)pcVar8;
      *(undefined1 *)((int)puVar15 + 0x4f) = 1;
      uVar26 = FUN_007cff80(puVar17);
      *(undefined8 *)puVar17 = uVar26;
      *(byte *)(puVar15 + 0x13) = (byte)puVar15[0x13] | 4;
    }
    break;
  case (uint *)0x33:
    iVar7 = param_1[0x10];
    if ((*(byte *)(local_3a0 + 2) & 4) != 0) goto LAB_007e358d;
    if (iVar7 == 0) {
LAB_007e3123:
      local_394 = *(int *)(pbVar22 + 8) + -1;
    }
    else {
      puVar17 = puVar15 + 0x10;
      param_1[0x10] = *(int *)(iVar7 + 0x48);
      *(undefined2 *)(puVar15 + 0x13) = 1;
      local_3a8 = puVar17;
      local_3a4 = (uint *)FUN_007cfb80(puVar17,iVar7 + 8);
      FUN_007d05b0(*(undefined4 *)(iVar7 + 4));
      FUN_007d05b0(iVar7);
    }
    break;
  case (uint *)0x34:
  case (uint *)0x6c:
    if ((*(byte *)(local_3a0 + 2) & 4) != 0) goto LAB_007e358d;
    piVar12 = *(int **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    iVar7 = *piVar12;
    if (iVar7 == 0) {
      *(undefined1 *)(piVar12 + 7) = 1;
LAB_007e21b9:
      *(undefined1 *)((int)piVar12 + 0x19) = 0;
    }
    else if ((char)piVar12[7] == '\0') {
      if (bVar6 == 0x6c) {
        local_3a4 = (uint *)FUN_007d7b80(iVar7,&iStack_31c);
      }
      else {
        local_3a4 = (uint *)FUN_007d7cc0(iVar7,&iStack_31c);
      }
      *(char *)(piVar12 + 7) = (char)iStack_31c;
      *(undefined1 *)(piVar12 + 0x15) = 0;
      if (iStack_31c != 0) goto LAB_007e21b9;
      local_394 = *(int *)(pbVar22 + 8) + -1;
      DAT_00b5c4dc = DAT_00b5c4dc + 1;
      *(undefined1 *)((int)piVar12 + 0x19) = 0;
    }
    else {
      iStack_31c = 1;
      *(undefined1 *)((int)piVar12 + 0x19) = 0;
    }
    break;
  case (uint *)0x36:
    piVar12 = *(int **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    if (*piVar12 == 0) {
      *(undefined1 *)(piVar12 + 7) = 0;
    }
    else {
      local_3a4 = (uint *)FUN_007d7840(*piVar12,&iStack_2d0);
      *(char *)(piVar12 + 7) = (char)iStack_2d0;
      *(undefined1 *)((int)piVar12 + 0x1f) = 0;
      *(undefined1 *)(piVar12 + 0x15) = 0;
      if (iStack_2d0 != 0) {
        if (0 < *(int *)(pbVar22 + 8)) {
          local_394 = *(int *)(pbVar22 + 8) + -1;
        }
      }
    }
    break;
  case (uint *)0x37:
    iVar7 = *(int *)(pbVar22 + 4);
    puVar17 = puVar15 + 0x10;
    *(undefined2 *)(puVar15 + 0x13) = 1;
    piVar12 = *(int **)(param_1[0xf] + iVar7 * 4);
    iVar7 = *piVar12;
    local_3a8 = puVar17;
    if (iVar7 != 0) {
      if ((char)piVar12[7] != '\0') goto LAB_007e2383;
      local_3a4 = (uint *)FUN_007dd860(iVar7,&uStack_2b8);
      if (local_3a4 != (uint *)0x0) goto LAB_007e35da;
      *(undefined2 *)(puVar15 + 0x13) = 4;
      *puVar17 = uStack_2b8;
      puVar15[0x11] = uStack_2b4;
    }
    break;
  case (uint *)0x38:
    if (*(int *)(pbVar22 + 4) != 0) {
      FUN_007dda20(local_3a0,param_1[0x91]);
    }
    param_1[0x91] = 0;
    break;
  case (uint *)0x39:
    uStack_33c = 0;
    if (0 < *(int *)(pbVar22 + 4)) {
      puStack_350 = puVar15;
      do {
        FUN_007cf920(puStack_350);
        FUN_007df5a0();
        puStack_350 = (uint *)(extraout_ECX_01 + -0x40);
        uStack_33c = uStack_33c + 1;
      } while ((int)uStack_33c < *(int *)(pbVar22 + 4));
    }
    param_1[0x1c] = param_1[0x1c] + 1;
    *(undefined1 *)(param_1 + 0x8f) = 1;
    param_1[0x8d] = *(int *)(pbVar22 + 4);
    param_1[0x21] = local_394 + 1;
    param_1[0xb] = (int)puVar15;
    return 100;
  case (uint *)0x3a:
    iVar7 = param_1[0x1e];
    param_1[0x1e] = iVar7 + 1;
    if (param_1[0x1f] <= iVar7) {
      param_1[0x1f] = iVar7 + 1;
      iVar13 = FUN_007d05d0(param_1[0x20],(iVar7 * 3 + 3) * 4);
      param_1[0x20] = iVar13;
      if (iVar13 == 0) goto LAB_007e3555;
    }
    piVar12 = (int *)(param_1[0x20] + iVar7 * 0xc);
    *piVar12 = local_3a0[8];
    piVar12[1] = param_1[0x91];
    piVar12[2] = param_1[0x1d];
    param_1[0x1d] = 0;
    break;
  case (uint *)0x3b:
    FUN_007eda60(local_3a0,*(undefined4 *)(pbVar22 + 4),*(undefined4 *)(pbVar22 + 0xc));
    break;
  case (uint *)0x3c:
    FUN_007d24e0(local_3a0,*(undefined4 *)(pbVar22 + 4),*(undefined4 *)(pbVar22 + 0xc));
    break;
  case (uint *)0x3e:
  case (uint *)0x3f:
    if ((puVar15[3] & 1) == 0) {
      FUN_007d0000(puVar15);
      if (*puVar15 == 0 && puVar15[1] == 0) {
        iVar7 = 1;
      }
      else {
        iVar7 = 0;
      }
    }
    else {
      iVar7 = 2;
    }
    if ((puVar15[-0xd] & 1) == 0) {
      FUN_007d0000(puVar15 + -0x10);
      if (puVar15[-0x10] == 0 && puVar15[-0xf] == 0) {
        iVar13 = 1;
      }
      else {
        iVar13 = 0;
      }
    }
    else {
      iVar13 = 2;
    }
    if (*pbVar22 == 0x3f) {
      cVar1 = *(char *)(iVar7 * 3 + 0xa00f38 + iVar13);
    }
    else {
      cVar1 = *(char *)(iVar7 * 3 + 0xa00f44 + iVar13);
    }
    iVar7 = 2;
    do {
      puVar17 = puVar15;
      if ((puVar17[3] & 0x40) != 0) {
        FUN_007cf9b0(puVar17);
      }
      iVar7 = iVar7 + -1;
      puVar15 = puVar17 + -0x10;
    } while (iVar7 != 0);
    local_3a8 = puVar17;
    if (cVar1 == '\x02') {
      *(undefined2 *)(puVar17 + 3) = 1;
    }
    else {
      *puVar17 = (uint)(cVar1 == '\0');
      puVar17[1] = 0;
      *(undefined2 *)(puVar17 + 3) = 4;
    }
    break;
  case (uint *)0x40:
    if ((puVar15[3] & 1) == 0) {
      FUN_007d0000(puVar15);
      if (*puVar15 == 0 && puVar15[1] == 0) {
        *puVar15 = 1;
        puVar15[1] = 0;
        *(undefined2 *)(puVar15 + 3) = 4;
      }
      else {
        *puVar15 = 0;
        puVar15[1] = 0;
        *(undefined2 *)(puVar15 + 3) = 4;
      }
    }
    break;
  case (uint *)0x41:
    piVar12 = *(int **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    iVar7 = *piVar12;
    if (iVar7 != 0) {
      iVar13 = FUN_007d7880(iVar7,puVar15[6],puVar15[2],(int)puVar15[2] >> 0x1f,&iStack_2c4);
      if ((iVar13 == 0) && (iStack_2c4 == 0)) {
        local_3a4 = (uint *)FUN_007da200(iVar7);
      }
      *(undefined1 *)(piVar12 + 0x15) = 0;
    }
    if ((puVar15[3] & 0x40) == 0) goto LAB_007e2f84;
    FUN_007cf9b0(puVar15);
    puVar17 = puVar15 + -0x10;
    local_3a8 = puVar15 + -0x10;
    break;
  case (uint *)0x42:
    iVar7 = FUN_007d0ea0(local_3a0);
    piVar12 = local_3a0;
    if (iVar7 == 0) {
      local_3a4 = (uint *)FUN_007f3dc0(param_1 + 0x8e,local_3a0);
      iVar7 = FUN_007d0e60(piVar12);
      if (iVar7 == 0) break;
    }
LAB_007e3284:
    local_3a4 = (uint *)0x15;
LAB_007e35da:
    if (param_1[0x8e] != 0) goto LAB_007e3614;
    if (DAT_00b5c4c4 != 0) {
      local_3a4 = (uint *)0x7;
    }
    uVar14 = FUN_007cd3a0(local_3a4,0);
    goto LAB_007e360c;
  case (uint *)0x44:
    iVar7 = *(int *)(pbVar22 + 4);
    iVar13 = iVar7;
    if (iVar7 < 0) {
      iVar13 = -iVar7;
    }
    iVar18 = 0;
    if (0 < iVar13) {
      puVar15 = puVar15 + iVar13 * -0x10 + 0x13;
      do {
        if ((*puVar15 & 1) != 0) {
          local_394 = *(int *)(pbVar22 + 8) + -1;
          break;
        }
        iVar18 = iVar18 + 1;
        puVar15 = puVar15 + 0x10;
      } while (iVar18 < iVar13);
    }
    if (0 < iVar7) {
      FUN_007df690(&local_3a8);
      goto LAB_007e32f5;
    }
    break;
  case (uint *)0x45:
    puStack_39c = *(uint **)(pbVar22 + 4);
    puVar19 = puStack_39c;
    if ((int)puStack_39c < 0) {
      puVar19 = (uint *)-(int)puStack_39c;
    }
    iVar7 = 0;
    if (0 < (int)puVar19) {
      puVar15 = puVar15 + (int)puVar19 * -0x10 + 0x13;
      do {
        if ((*puVar15 & 1) != 0) {
          if (iVar7 < (int)puVar19) goto LAB_007e08fd;
          break;
        }
        iVar7 = iVar7 + 1;
        puVar15 = puVar15 + 0x10;
      } while (iVar7 < (int)puVar19);
    }
    local_394 = *(int *)(pbVar22 + 8) + -1;
LAB_007e08fd:
    if (0 < (int)puStack_39c) {
      FUN_007df690(&local_3a8);
      goto LAB_007e32f5;
    }
    break;
  case (uint *)0x46:
  case (uint *)0x47:
  case (uint *)0x48:
  case (uint *)0x49:
  case (uint *)0x4a:
  case (uint *)0x4b:
    if ((((byte)puVar15[-0xd] | (byte)puVar15[3]) & 1) == 0) {
      bStack_381 = pbVar22[4];
      if (bStack_381 != 0) {
        FUN_007df790((char)local_3a0[4]);
        FUN_007df790((char)local_3a0[4]);
      }
      iVar7 = FUN_007d03a0(puVar15 + -0x10,puVar15,*(undefined4 *)(pbVar22 + 0xc));
      switch(*pbVar22) {
      case 0x46:
        uVar10 = (uint)(iVar7 != 0);
        break;
      case 0x47:
        uVar10 = (uint)(iVar7 == 0);
        break;
      case 0x48:
        uVar10 = (uint)(0 < iVar7);
        break;
      case 0x49:
        uVar10 = (uint)(iVar7 < 1);
        break;
      case 0x4a:
        uVar10 = (uint)(iVar7 < 0);
        break;
      default:
        uVar10 = (uint)(-1 < iVar7);
      }
      puStack_39c = (uint *)0x2;
      do {
        puVar17 = puVar15;
        if ((puVar17[3] & 0x40) != 0) {
          FUN_007cf9b0(puVar17);
        }
        puVar15 = puVar17 + -0x10;
        puStack_39c = (uint *)((int)puStack_39c + -1);
      } while (puStack_39c != (uint *)0x0);
      iVar7 = *(int *)(pbVar22 + 8);
      puStack_39c = (uint *)0x0;
      if (iVar7 == 0) {
        *(undefined2 *)(puVar17 + 3) = 4;
        *puVar17 = uVar10;
        puVar17[1] = 0;
        local_3a8 = puVar17;
      }
      else {
        local_3a8 = puVar15;
        if (uVar10 != 0) goto LAB_007e32f0;
      }
    }
    else {
      iVar7 = 2;
      do {
        if ((puVar15[3] & 0x40) != 0) {
          FUN_007cf9b0(puVar15);
        }
        puVar15 = puVar15 + -0x10;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      if (*(int *)(pbVar22 + 8) == 0) goto LAB_007e02cc;
      local_3a8 = puVar15;
      if ((*(uint *)(pbVar22 + 4) & 0x100) != 0) {
        local_394 = *(int *)(pbVar22 + 8) + -1;
      }
    }
    goto LAB_007e32f5;
  case (uint *)0x4d:
  case (uint *)0x4e:
  case (uint *)0x4f:
  case (uint *)0x50:
    puStack_390 = puVar15 + -0x10;
    if ((((byte)puVar15[-0xd] | (byte)puVar15[3]) & 1) == 0) {
      uVar10 = FUN_007cff80(puStack_390);
      uVar16 = FUN_007cff80(puVar15);
      switch(*pbVar22) {
      case 0x4d:
        uVar10 = uVar10 & uVar16;
        break;
      case 0x4e:
        uVar10 = uVar10 | uVar16;
        break;
      case 0x4f:
        uVar10 = uVar10 << ((byte)uVar16 & 0x1f);
        break;
      case 0x50:
        uVar10 = (int)uVar10 >> ((byte)uVar16 & 0x1f);
      }
      if ((puVar15[3] & 0x40) != 0) {
        FUN_007cf9b0(puVar15);
      }
      puVar17 = puStack_390;
      local_3a8 = puStack_390;
      if ((puStack_390[3] & 0x40) != 0) {
        FUN_007cf9b0(puStack_390);
      }
      *puVar17 = uVar10;
      puVar17[1] = (int)uVar10 >> 0x1f;
      *(undefined2 *)(puVar17 + 3) = 4;
    }
    else {
      iVar7 = 2;
      do {
        if ((puVar15[3] & 0x40) != 0) {
          FUN_007cf9b0(puVar15);
        }
        puVar15 = puVar15 + -0x10;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
LAB_007e02cc:
      *(undefined2 *)(puVar15 + 0x13) = 1;
      local_3a8 = puVar15 + 0x10;
    }
    goto LAB_007e32f5;
  case (uint *)0x51:
  case (uint *)0x52:
  case (uint *)0x53:
  case (uint *)0x54:
  case (uint *)0x55:
    puVar17 = puVar15 + -0x10;
    bVar6 = (byte)puVar15[3];
    puStack_390 = puVar17;
    if ((((byte)puVar15[-0xd] | bVar6) & 1) == 0) {
      if (((byte)puVar15[-0xd] & bVar6 & 4) == 0) {
        fVar25 = (float10)FUN_007d0050(puVar15);
        dStack_370 = (double)fVar25;
        fVar25 = (float10)FUN_007d0050(puVar17);
        switch(*pbVar22) {
        case 0x51:
          fVar25 = fVar25 + (float10)dStack_370;
          break;
        case 0x52:
          fVar25 = fVar25 - (float10)dStack_370;
          break;
        case 0x53:
          fVar25 = fVar25 * (float10)dStack_370;
          break;
        case 0x54:
          if (dStack_370 == _DAT_0099d098) goto LAB_007e00b6;
          fVar25 = fVar25 / (float10)dStack_370;
          break;
        default:
          puVar19 = (uint *)FUN_00802534();
          puStack_39c = puVar19;
          iVar7 = FUN_00802534();
          if (_DAT_0099d098 == (double)(int)puStack_39c) goto LAB_007e00b6;
          puStack_39c = (uint *)(iVar7 % (int)puVar19);
          fVar25 = (float10)(int)puStack_39c;
        }
        dStack_370 = (double)fVar25;
        if ((puVar15[3] & 0x40) != 0) {
          FUN_007cf9b0(puVar15);
        }
        local_3a8 = puVar17;
        if ((puVar15[-0xd] & 0x40) != 0) {
          FUN_007cf9b0(puVar17);
        }
        *(double *)(puVar15 + -0xc) = dStack_370;
        *(undefined2 *)(puVar15 + -0xd) = 8;
      }
      else {
        uVar10 = *puVar17;
        uVar16 = puVar15[-0xf];
        uVar2 = *puVar15;
        uVar3 = puVar15[1];
        switch(puStack_39c) {
        case (uint *)0x51:
          uVar26 = CONCAT44(uVar16 + uVar3 + (uint)CARRY4(uVar10,uVar2),uVar10 + uVar2);
          break;
        case (uint *)0x52:
          uVar26 = CONCAT44((uVar16 - uVar3) - (uint)(uVar10 < uVar2),uVar10 - uVar2);
          break;
        case (uint *)0x53:
          uVar26 = __allmul(uVar10,uVar16,uVar2,uVar3);
          break;
        case (uint *)0x54:
          if (uVar2 == 0 && uVar3 == 0) {
LAB_007e00b6:
            bVar24 = (puVar15[3] & 0x40) == 0;
            goto LAB_007e00ba;
          }
          uVar26 = __alldiv(uVar10,uVar16,uVar2,uVar3);
          break;
        default:
          if (uVar2 == 0 && uVar3 == 0) goto LAB_007e00b6;
          uVar26 = __allrem(uVar10,uVar16,uVar2,uVar3);
        }
        if ((puVar15[3] & 0x40) != 0) {
          FUN_007cf9b0(puVar15);
        }
        puVar17 = puStack_390;
        local_3a8 = puStack_390;
        if ((puStack_390[3] & 0x40) != 0) {
          FUN_007cf9b0(puStack_390);
        }
        *(undefined8 *)puVar17 = uVar26;
        *(undefined2 *)(puVar17 + 3) = 4;
      }
    }
    else {
      bVar24 = ((ushort)puVar15[3] & 0x40) == 0;
LAB_007e00ba:
      if (!bVar24) {
        FUN_007cf9b0(puVar15);
      }
      local_3a8 = puVar17;
      if ((puVar15[-0xd] & 0x40) != 0) {
        FUN_007cf9b0(puVar17);
      }
      *(undefined2 *)(puVar15 + -0xd) = 1;
    }
    goto LAB_007e32f5;
  case (uint *)0x56:
    puVar19 = (uint *)(*(int *)(pbVar22 + 4) + 2);
    puStack_38c = puVar15 + (int)puVar19 * -0x10 + 0x10;
    puStack_390 = (uint *)0x0;
    puStack_39c = (uint *)0x0;
    puStack_378 = puVar19;
    puStack_368 = puStack_38c;
    if (0 < (int)puVar19) {
      do {
        if ((puStack_38c[3] & 1) != 0) goto LAB_007dfe29;
        if ((puStack_38c[3] & 0x12) == 0) {
          iVar7 = FUN_007cfee0(puStack_38c,(char)local_3a0[4]);
          if (iVar7 != 0) goto LAB_007e3555;
        }
        puStack_390 = (uint *)((int)puStack_390 + puStack_38c[2]);
        puStack_39c = (uint *)((int)puStack_39c + 1);
        puStack_38c = puStack_38c + 0x10;
      } while ((int)puStack_39c < (int)puVar19);
      if ((int)puStack_390 < 0) {
LAB_007dfe29:
        if (*(int *)(pbVar22 + 8) == 0) {
          FUN_007df690(&local_3a8);
          puVar15 = local_3a8;
        }
        goto switchD_007df9a7_caseD_76;
      }
    }
    puStack_398 = (uint *)FUN_007d0590((int)puStack_390 + 2);
    if (puStack_398 == (uint *)0x0) goto LAB_007e3555;
    puStack_390 = (uint *)0x0;
    if (0 < (int)puVar19) {
      puVar17 = puStack_368 + 6;
      puStack_39c = puStack_378;
      do {
        puStack_38c = (uint *)puVar17[-4];
        puVar11 = (undefined4 *)*puVar17;
        puVar20 = (undefined4 *)((int)puStack_398 + (int)puStack_390);
        for (uVar10 = (uint)puStack_38c >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar20 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar20 = puVar20 + 1;
        }
        for (uVar10 = (uint)puStack_38c & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined1 *)puVar20 = *(undefined1 *)puVar11;
          puVar11 = (undefined4 *)((int)puVar11 + 1);
          puVar20 = (undefined4 *)((int)puVar20 + 1);
        }
        puStack_390 = (uint *)((int)puStack_390 + (int)puStack_38c);
        puVar17 = puVar17 + 0x10;
        puStack_39c = (uint *)((int)puStack_39c + -1);
      } while (puStack_39c != (uint *)0x0);
    }
    *(undefined1 *)((int)puStack_390 + (int)puStack_398) = 0;
    *(undefined1 *)((int)puStack_390 + 1 + (int)puStack_398) = 0;
    if (*(int *)(local_388 + 8) == 0) {
      FUN_007df690(&local_3a8);
      puVar15 = local_3a8;
    }
    puVar15[0x12] = (uint)puStack_390;
    *(undefined2 *)(puVar15 + 0x13) = 0x62;
    puVar15[0x17] = 0;
    *(char *)((int)puVar15 + 0x4f) = (char)local_3a0[4];
    puVar15[0x16] = (uint)puStack_398;
    puVar17 = puVar15 + 0x10;
    local_3a8 = puVar15 + 0x10;
    break;
  case (uint *)0x57:
  case (uint *)0x68:
    uVar10 = puVar15[3];
    if ((uVar10 & 8) == 0) {
      if ((uVar10 & 4) == 0) {
        if ((uVar10 & 1) == 0) {
          FUN_007d00b0(puVar15);
          if ((*pbVar22 == 0x57) || (*(double *)(puVar15 + 4) < _DAT_0099d098)) {
            *(double *)(puVar15 + 4) = -*(double *)(puVar15 + 4);
          }
          *(undefined2 *)(puVar15 + 3) = 8;
        }
      }
      else {
        if ((uVar10 & 0x40) != 0) {
          FUN_007cf9b0(puVar15);
        }
        if ((*pbVar22 == 0x57) || (((int)puVar15[1] < 1 && ((int)puVar15[1] < 0)))) {
          uVar10 = *puVar15;
          *puVar15 = -uVar10;
          puVar15[1] = -(puVar15[1] + (uint)(uVar10 != 0));
        }
        *(undefined2 *)(puVar15 + 3) = 4;
      }
    }
    else {
      if ((uVar10 & 0x40) != 0) {
        FUN_007cf9b0(puVar15);
      }
      if ((*pbVar22 == 0x57) || (*(double *)(puVar15 + 4) < _DAT_0099d098)) {
        *(double *)(puVar15 + 4) = -*(double *)(puVar15 + 4);
      }
      *(undefined2 *)(puVar15 + 3) = 8;
    }
    break;
  case (uint *)0x58:
    FUN_007d2660(local_3a0,*(undefined4 *)(pbVar22 + 4),*(undefined4 *)(pbVar22 + 0xc));
    break;
  case (uint *)0x59:
    if ((puVar15[3] & 1) == 0) {
      FUN_007d0000(puVar15);
      *puVar15 = ~*puVar15;
      puVar15[1] = ~puVar15[1];
      *(undefined2 *)(puVar15 + 3) = 4;
    }
    break;
  case (uint *)0x5a:
    *pbVar22 = 0x1b;
    if ((char)local_3a0[4] == '\x01') goto switchD_007df9a7_caseD_1b;
    puVar17 = puVar15 + 0x10;
    local_3a8 = puVar17;
    FUN_007cfbe0(puVar17,*(undefined4 *)(pbVar22 + 0xc),0xffffffff,1,0);
    iVar7 = FUN_007cfe90(puVar17,(char)local_3a0[4]);
    if (iVar7 != 0) goto LAB_007e3555;
    iVar7 = FUN_007cf820(puVar17);
    if (iVar7 != 0) goto LAB_007e3555;
    *(ushort *)(puVar15 + 0x13) = (ushort)puVar15[0x13] & 0xffbf | 0x80;
    if (*(int *)(pbVar22 + 0x10) == -1) {
      FUN_007d05b0(*(undefined4 *)(pbVar22 + 0xc));
    }
    pbVar22[0x10] = 0xff;
    pbVar22[0x11] = 0xff;
    pbVar22[0x12] = 0xff;
    pbVar22[0x13] = 0xff;
    *(uint *)(pbVar22 + 0xc) = puVar15[0x16];
    break;
  case (uint *)0x5b:
    uStack_360 = (uint)(*(int *)(pbVar22 + 4) < 0);
    puStack_378 = (uint *)0x0;
    puStack_38c = (uint *)0x0;
    puStack_374 = (undefined4 *)0x0;
    puStack_368 = (uint *)0x0;
    local_388 = (byte *)(((uint)(uStack_360 == 0) * 2 + -1) * *(int *)(pbVar22 + 4));
    puStack_354 = (uint *)(*(uint *)(pbVar22 + 8) & 0xffffff);
    puStack_39c = (uint *)(uint)(((int)*(uint *)(pbVar22 + 8) >> 0x18 & 0xffffU) != 0);
    puStack_390 = *(uint **)(pbVar22 + 0xc);
    puVar23 = puVar15 + (int)local_388 * -0x10;
    puVar19 = puVar23 + 0x10;
    puStack_398 = puVar19;
    if (puVar19 <= puVar15) {
      dStack_370 = (double)CONCAT44(dStack_370._4_4_,-0xc - (int)puVar19);
      do {
        if (puStack_390 != (uint *)0x0) {
          FUN_007df790((char)local_3a0[4]);
        }
        if ((puVar19[3] & 1) != 0) {
          puStack_368 = (uint *)0x1;
        }
        puStack_35c = (uint *)FUN_007dd230(puVar19);
        iVar7 = FUN_007dd2f0(puStack_35c);
        puStack_38c = (uint *)((int)puStack_38c + iVar7);
        iVar7 = FUN_007d1190(puStack_35c,0);
        puStack_374 = (undefined4 *)((int)puStack_374 + iVar7);
        puVar19 = puVar19 + 0x10;
      } while (puVar19 <= puVar15);
    }
    if (puStack_39c == (uint *)0x0) {
      puVar11 = puStack_374;
    }
    else {
      puStack_378 = puVar23;
      FUN_007d0000(puVar23);
      uVar14 = FUN_007dd230(puVar23);
      iVar7 = FUN_007dd2f0(uVar14);
      puStack_38c = (uint *)((int)puStack_38c + iVar7);
      iVar7 = FUN_007d1190(uVar14,0);
      puVar11 = (undefined4 *)((int)puStack_374 + iVar7);
    }
    iVar7 = FUN_007d1190(puVar11,(int)puVar11 >> 0x1f);
    puVar11 = (undefined4 *)((int)puVar11 + iVar7);
    puStack_374 = puVar11;
    iVar13 = FUN_007d1190(puVar11,(int)puVar11 >> 0x1f);
    if (iVar7 < iVar13) {
      puVar11 = (undefined4 *)((int)puVar11 + 1);
      puStack_374 = puVar11;
    }
    puStack_390 = (uint *)((int)puVar11 + (int)puStack_38c);
    if (puStack_390 < (uint *)0x21) {
      puStack_38c = auStack_d8;
    }
    else {
      puStack_38c = (uint *)FUN_007d0590(puStack_390);
      if (puStack_38c == (uint *)0x0) goto LAB_007e3555;
      puVar11 = puStack_374;
    }
    puVar17 = puStack_38c;
    iVar7 = FUN_007d0f10(puStack_38c,puVar11,(int)puVar11 >> 0x1f);
    iVar7 = iVar7 + (int)puVar17;
    for (puVar17 = puStack_398; puVar17 <= puVar15; puVar17 = puVar17 + 0x10) {
      uVar14 = FUN_007dd230(puVar17);
      iVar13 = FUN_007d0f10(iVar7,uVar14,0);
      iVar7 = iVar7 + iVar13;
    }
    puVar17 = puStack_398;
    if (puStack_39c != (uint *)0x0) {
      uVar14 = FUN_007dd230(puStack_378);
      iVar13 = FUN_007d0f10(iVar7,uVar14,0);
      iVar7 = iVar7 + iVar13;
      puVar17 = puStack_398;
    }
    for (; puVar17 <= puVar15; puVar17 = puVar17 + 0x10) {
      iVar13 = FUN_007dd310(iVar7,puVar17);
      iVar7 = iVar7 + iVar13;
    }
    if (puStack_39c != (uint *)0x0) {
      FUN_007dd310(iVar7,puStack_378);
    }
    if (uStack_360 == 0) {
      FUN_007df690(&local_3a8);
      puVar15 = local_3a8;
    }
    puVar17 = puVar15 + 0x10;
    puVar15[0x12] = (uint)puStack_390;
    if (puStack_390 < (uint *)0x21) {
      uVar10 = (uint)puStack_390 >> 2;
      puVar15[0x16] = (uint)(puVar15 + 0x18);
      puVar19 = auStack_d8;
      puVar23 = puVar15 + 0x18;
      for (; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar23 = *puVar19;
        puVar19 = puVar19 + 1;
        puVar23 = puVar23 + 1;
      }
      for (uVar10 = (uint)puStack_390 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(char *)puVar23 = (char)*puVar19;
        puVar19 = (uint *)((int)puVar19 + 1);
        puVar23 = (uint *)((int)puVar23 + 1);
      }
      *(undefined2 *)(puVar15 + 0x13) = 0x210;
    }
    else {
      puVar15[0x16] = (uint)puStack_38c;
      *(undefined2 *)(puVar15 + 0x13) = 0x50;
      puVar15[0x17] = 0;
    }
    local_3a8 = puVar17;
    if (puStack_354 != (uint *)0x0) {
      if (puStack_368 != (uint *)0x0) {
        local_394 = (int)puStack_354 + -1;
      }
    }
    break;
  case (uint *)0x5c:
    piVar12 = *(int **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    if (*piVar12 != 0) {
      local_3a4 = (uint *)FUN_007dd1a0(piVar12);
      if (local_3a4 != (uint *)0x0) goto LAB_007e35da;
      local_3a4 = (uint *)FUN_007da200(*piVar12);
      *(undefined1 *)((int)piVar12 + 0x1d) = 0;
      *(undefined1 *)(piVar12 + 0x15) = 0;
    }
    if ((pbVar22[8] & 1) != 0) {
      param_1[0x91] = param_1[0x91] + 1;
    }
    break;
  case (uint *)0x5d:
    param_1[0x1b] = param_1[0x1b] + -0x1c;
    break;
  case (uint *)0x5e:
    if ((*(byte *)(local_3a0 + 2) & 4) != 0) goto LAB_007e358d;
    iVar7 = param_1[0x1d];
    if (iVar7 == 0) goto LAB_007e3123;
    iVar13 = *(int *)(iVar7 + 8);
    puVar17 = puVar15 + 0x10;
    *puVar17 = *(uint *)(iVar7 + 0x10 + iVar13 * 8);
    puVar15[0x11] = *(uint *)(iVar7 + 0x14 + iVar13 * 8);
    *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + 1;
    *(undefined2 *)(puVar15 + 0x13) = 4;
    local_3a8 = puVar17;
    if (*(int *)(iVar7 + 4) <= *(int *)(iVar7 + 8)) {
      param_1[0x1d] = *(int *)(iVar7 + 0xc);
      FUN_007d05b0(iVar7);
    }
    break;
  case (uint *)0x5f:
    if (param_1[0x1d] != 0) {
      FUN_007dcc00(param_1[0x1d]);
      param_1[0x1d] = 0;
    }
    break;
  case (uint *)0x60:
    puVar17 = puVar15 + 0x10;
    local_3a8 = puVar17;
    FUN_007cfae0(puVar17,puVar15 + *(int *)(pbVar22 + 4) * -0x10,0x100);
    if (*(int *)(pbVar22 + 8) != 0) {
      if ((*(byte *)((int)puVar15 + 0x4d) & 1) != 0) {
        iVar7 = FUN_007cf890(puVar17);
        if (iVar7 != 0) goto LAB_007e3555;
      }
    }
    break;
  case (uint *)0x61:
    if ((*(byte *)(local_3a0 + 2) & 4) != 0) goto LAB_007e358d;
    local_394 = *(int *)(pbVar22 + 8) + -1;
    break;
  case (uint *)0x62:
    local_3a4 = (uint *)FUN_007da600(*(undefined4 *)
                                      (*(int *)(pbVar22 + 8) * 0x70 + 4 + local_3a0[1]),
                                     *(undefined4 *)(pbVar22 + 4));
    break;
  case (uint *)0x65:
    iVar7 = *(int *)(*(int *)(pbVar22 + 4) * 0x70 + 4 + local_3a0[1]);
    if (iVar7 == 0) {
      local_3a4 = (uint *)0x0;
      iStack_304 = 0;
    }
    else {
      local_3a4 = (uint *)FUN_007da670(iVar7,1,&iStack_304);
      if (local_3a4 != (uint *)0x0) break;
    }
    if (iStack_304 != *(int *)(pbVar22 + 8)) {
      FUN_007d0700(param_1 + 0x8e,s_database_schema_has_changed_009ffabc,0);
      local_3a4 = (uint *)0x11;
    }
    break;
  case (uint *)0x66:
    puStack_38c = puVar15 + *(int *)(local_388 + 4) * -0x10;
    bVar6 = *(byte *)((int)puVar15 + 0xd);
    puVar19 = puStack_38c;
    puVar23 = auStack_b8;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar23 = *puVar19;
      puVar19 = puVar19 + 1;
      puVar23 = puVar23 + 1;
    }
    if ((bVar6 & 1) != 0) {
      iVar7 = FUN_007cf890(puVar15);
      if (iVar7 != 0) goto LAB_007e3555;
    }
    puStack_39c = (uint *)0x0;
    if (0 < *(int *)(local_388 + 4)) {
      puStack_398 = puStack_38c + 0x10;
      do {
        if ((*(byte *)((int)puStack_398 + 0xd) & 1) != 0) {
          iVar7 = FUN_007cf890(puStack_398);
          if (iVar7 != 0) goto LAB_007e3555;
        }
        puVar19 = puStack_398;
        puVar23 = puStack_38c;
        for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar23 = *puVar19;
          puVar19 = puVar19 + 1;
          puVar23 = puVar23 + 1;
        }
        if ((*(byte *)((int)puStack_398 + -0x33) & 2) != 0) {
          puStack_398[-10] = (uint)(puStack_398 + -8);
        }
        puStack_398 = puStack_398 + 0x10;
        puStack_39c = (uint *)((int)puStack_39c + 1);
        puStack_38c = puStack_38c + 0x10;
      } while ((int)puStack_39c < *(int *)(local_388 + 4));
    }
    puVar19 = auStack_b8;
    puVar23 = puVar15;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar23 = *puVar19;
      puVar19 = puVar19 + 1;
      puVar23 = puVar23 + 1;
    }
    if ((*(byte *)((int)puVar15 + 0xd) & 2) != 0) {
      puVar15[6] = (uint)(puVar15 + 8);
    }
    break;
  case (uint *)0x67:
    *(undefined4 *)(*(int *)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4) + 0x50) =
         *(undefined4 *)(pbVar22 + 8);
    break;
  case (uint *)0x69:
    iVar7 = *(int *)(*(int *)(pbVar22 + 4) * 0x70 + 4 + local_3a0[1]);
    if (iVar7 != 0) {
      local_3a4 = (uint *)FUN_007d69e0(iVar7,*(undefined4 *)(pbVar22 + 8));
      if (local_3a4 == (uint *)0x5) {
        param_1[0x21] = local_394;
        param_1[0x22] = 5;
        param_1[0xb] = (int)puVar15;
        return 5;
      }
      if ((local_3a4 != (uint *)0x0) && (local_3a4 != (uint *)0x8)) goto LAB_007e35da;
    }
    break;
  case (uint *)0x6a:
    iVar7 = param_1[0x1b] + *(int *)(pbVar22 + 4) * -0x1c;
    puStack_350 = *(uint **)(iVar7 + 4);
    dStack_370 = (double)CONCAT44(dStack_370._4_4_,*(undefined4 *)(pbVar22 + 8));
    if (puStack_350 == (uint *)0x0) {
      if (DAT_00b5c4c4 != 0) goto LAB_007e3555;
      iVar13 = FUN_007d7800(*(undefined4 *)(iVar7 + 0x10),&iStack_2d4);
      if (iVar13 != 0) {
        return iVar13;
      }
      if (iStack_2d4 == 0) {
        local_3a4 = (uint *)FUN_007d73b0(*(undefined4 *)(iVar7 + 0x10),0,4,&puStack_350);
      }
      else {
        local_3a4 = (uint *)FUN_007df5d0(&DAT_0099cf70,1);
        puStack_350 = *(uint **)(iVar7 + 4);
        puVar15 = local_3a8;
      }
    }
    puVar17 = puVar15 + 0x10;
    local_3a8 = puVar17;
    FUN_007cfae0(puVar17,puStack_350 + dStack_370._0_4_ * 0x10 + 2,0x100);
    if ((puVar15[0x13] & 2) != 0) {
      FUN_007cfe90(puVar17,(char)local_3a0[4]);
    }
    break;
  case (uint *)0x6b:
    piVar12 = (int *)(param_1[0x20] + (param_1[0x1e] + -1) * 0xc);
    param_1[0x1e] = param_1[0x1e] + -1;
    iVar7 = *piVar12;
    local_3a0[8] = iVar7;
    local_3a0[9] = iVar7 >> 0x1f;
    param_1[0x91] = piVar12[1];
    FUN_007dcc00(param_1[0x1d]);
    param_1[0x1d] = piVar12[2];
    break;
  case (uint *)0x6d:
    *(undefined4 *)(*(int *)(param_1[0x1b] + 8) + *(int *)(pbVar22 + 8) * 4) =
         *(undefined4 *)(pbVar22 + 0xc);
    break;
  case (uint *)0x6e:
    puStack_378 = *(uint **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    puStack_398 = (uint *)*puStack_378;
    if (puStack_398 != (uint *)0x0) {
      puStack_39c = (uint *)puVar15[2];
      uVar10 = puVar15[6];
      if (*(int *)(pbVar22 + 8) != 0) {
        iVar7 = FUN_007dd810(puStack_39c,uVar10);
        iVar7 = (int)puStack_39c - iVar7;
        dStack_370 = (double)CONCAT44(dStack_370._4_4_,iVar7);
        local_3a4 = (uint *)FUN_007d7880(puStack_398,uVar10,iVar7,iVar7 >> 0x1f,&iStack_32c);
        if (local_3a4 != (uint *)0x0) goto LAB_007e35da;
        local_3a4 = (uint *)0x0;
        if (iStack_32c != 0) {
          while (iVar7 = FUN_007d7b70(puStack_398), iVar7 == 0) {
            iVar7 = FUN_007dd960(puStack_378,dStack_370._0_4_,uVar10,&iStack_2e4);
            if ((iVar7 == 0) && (iStack_2e4 == 0)) {
              pcVar8 = *(char **)(pbVar22 + 0xc);
              local_3a4 = (uint *)0x13;
              if ((pcVar8 != (char *)0x0) && (*pcVar8 != '\0')) {
                FUN_007d0700(param_1 + 0x8e,pcVar8,0);
              }
              goto LAB_007e35da;
            }
            if (-1 < iStack_32c) break;
            FUN_007d7b80(puStack_398,&iStack_32c);
            iStack_32c = 1;
          }
        }
      }
      local_3a4 = (uint *)FUN_007da050(puStack_398,uVar10,puStack_39c,(int)puStack_39c >> 0x1f,
                                       &DAT_0099cf70,0);
      *(undefined1 *)(puStack_378 + 0x15) = 0;
    }
    if ((puVar15[3] & 0x40) == 0) goto LAB_007e2f84;
    FUN_007cf9b0(puVar15);
    puVar17 = puVar15 + -0x10;
    local_3a8 = puVar15 + -0x10;
    break;
  case (uint *)0x70:
    if (*(int *)(pbVar22 + 4) == 0) {
      local_3a4 = (uint *)FUN_007ddae0(local_3a0,param_1[0x1b],*(undefined4 *)(pbVar22 + 0xc));
      *(undefined4 *)param_1[0x1b] = *(undefined4 *)(pbVar22 + 8);
    }
    else {
      FUN_007ddae0(0,param_1[0x1b],*(undefined4 *)(pbVar22 + 0xc));
      *(undefined4 *)param_1[0x1b] = *(undefined4 *)(pbVar22 + 8);
      local_3a4 = (uint *)FUN_007df5d0(0,0);
      puVar15 = local_3a8;
    }
    puVar17 = puVar15;
    if (local_3a4 != (uint *)0x0) goto LAB_007e35da;
    uVar14 = FUN_007d0550(*(int *)param_1[0x1b] << 2);
    *(undefined4 *)(param_1[0x1b] + 8) = uVar14;
    if (*(int *)(param_1[0x1b] + 8) == 0) goto LAB_007e3555;
    break;
  case (uint *)0x71:
    puVar19 = *(uint **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    puStack_39c = puVar19;
    if ((*puVar19 != 0) || (*(char *)((int)puVar19 + 0x1e) != '\0')) {
      uStack_300 = puVar15[-0x10];
      uStack_2fc = puVar15[-0xf];
      if ((pbVar22[8] & 1) != 0) {
        param_1[0x91] = param_1[0x91] + 1;
      }
      if ((pbVar22[8] & 2) != 0) {
        local_3a0[8] = puVar15[-0x10];
        local_3a0[9] = puVar15[-0xf];
      }
      if (*(char *)((int)puVar19 + 0x1d) != '\0') {
        if (((int)puVar19[5] <= (int)puVar15[1]) &&
           (((int)puVar19[5] < (int)puVar15[1] || (puVar19[4] <= *puVar15)))) {
          *(undefined1 *)((int)puVar19 + 0x1d) = 0;
        }
      }
      if ((puVar15[3] & 1) != 0) {
        puVar15[6] = 0;
        puVar15[2] = 0;
      }
      if (*(char *)((int)puVar19 + 0x1e) == '\0') {
        local_3a4 = (uint *)FUN_007da050(*puVar19,0,uStack_300,uStack_2fc,puVar15[6],puVar15[2]);
      }
      else {
        FUN_007d05b0(puVar19[0xe]);
        puVar19[0x10] = uStack_300;
        puVar19[0x11] = uStack_2fc;
        uVar10 = puVar15[2];
        puVar19[0xd] = uVar10;
        if ((puVar15[3] & 0x40) == 0) {
          puVar11 = (undefined4 *)FUN_007d0590(uVar10 + 2);
          puVar19[0xe] = (uint)puVar11;
          if (puVar11 == (undefined4 *)0x0) goto LAB_007e3555;
          uVar10 = puStack_39c[0xd];
          puVar20 = (undefined4 *)puVar15[6];
          for (uVar16 = uVar10 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
            *puVar11 = *puVar20;
            puVar20 = puVar20 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar20;
            puVar20 = (undefined4 *)((int)puVar20 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          *(undefined1 *)(puStack_39c[0xd] + puStack_39c[0xe]) = 0;
          *(undefined1 *)(puStack_39c[0xd] + 1 + puStack_39c[0xe]) = 0;
          *(undefined1 *)(puStack_39c + 7) = 0;
          puVar19 = puStack_39c;
        }
        else {
          puVar19[0xe] = puVar15[6];
          *(undefined2 *)(puVar15 + 3) = 1;
          *(undefined1 *)(puVar19 + 7) = 0;
        }
      }
      *(undefined1 *)((int)puVar19 + 0x19) = 0;
      *(undefined1 *)((int)puVar19 + 0x1f) = 0;
      *(undefined1 *)(puVar19 + 0x15) = 0;
    }
    iVar7 = 2;
    do {
      if ((puVar15[3] & 0x40) != 0) {
        FUN_007cf9b0(puVar15);
      }
      puVar15 = puVar15 + -0x10;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    local_3a8 = puVar15;
LAB_007e32f5:
    puVar17 = local_3a8;
    break;
  case (uint *)0x72:
    if (local_3a0[0x13] < 2) {
      local_3a4 = (uint *)FUN_007dbad0(*(undefined4 *)
                                        (*(int *)(pbVar22 + 8) * 0x70 + 4 + local_3a0[1]),
                                       *(undefined4 *)(pbVar22 + 4),&uStack_33c);
      puVar17 = puVar15 + 0x10;
      *(undefined2 *)(puVar15 + 0x13) = 4;
      *puVar17 = uStack_33c;
      puVar15[0x11] = (int)uStack_33c >> 0x1f;
      local_3a8 = puVar17;
      if (local_3a4 == (uint *)0x0) {
        if (uStack_33c != 0) {
          FUN_007d3330(*(int *)(pbVar22 + 8) * 0x70 + piVar12[1],uStack_33c,
                       *(undefined4 *)(pbVar22 + 4));
        }
      }
    }
    else {
      local_3a4 = (uint *)0x6;
    }
    break;
  case (uint *)0x73:
    local_3a4 = (uint *)FUN_007da670(*(undefined4 *)
                                      (*(int *)(pbVar22 + 4) * 0x70 + 4 + local_3a0[1]),
                                     *(int *)(pbVar22 + 8) + 1,&uStack_2e0);
    puVar17 = puVar15 + 0x10;
    *puVar17 = uStack_2e0;
    puVar15[0x11] = (int)uStack_2e0 >> 0x1f;
    *(undefined2 *)(puVar15 + 0x13) = 4;
    local_3a8 = puVar17;
    break;
  case (uint *)0x74:
    FUN_007df790((char)local_3a0[4]);
    uVar10 = puVar15[3];
    if ((uVar10 & 0xc) == 0) {
      if ((uVar10 & 0x40) == 0) {
LAB_007e04b8:
        puVar15 = puVar15 + -0x10;
        local_3a8 = puVar15;
        goto LAB_007e04bf;
      }
      FUN_007cf9b0(puVar15);
      local_394 = *(int *)(pbVar22 + 8) + -1;
      puVar17 = puVar15 + -0x10;
      local_3a8 = puVar15 + -0x10;
    }
    else {
      if ((uVar10 & 4) == 0) {
        FUN_007d00b0(puVar15);
        uStack_338 = FUN_00802534();
        uStack_334 = (int)uStack_338 >> 0x1f;
        if ((double)(longlong)(int)uStack_338 < *(double *)(puVar15 + 4)) {
          bVar24 = 0xfffffffe < uStack_338;
          uStack_338 = uStack_338 + 1;
          uStack_334 = uStack_334 + bVar24;
        }
        uVar10 = uStack_338;
        if ((*(int *)(pbVar22 + 4) != 0) &&
           (*(double *)(puVar15 + 4) == (double)CONCAT44(uStack_334,uStack_338))) {
          uVar10 = uStack_338 + 1;
          uStack_334 = uStack_334 + (0xfffffffe < uStack_338);
        }
        uVar16 = uStack_334;
      }
      else if (*(int *)(pbVar22 + 4) == 0) {
        uVar10 = *puVar15;
        uVar16 = puVar15[1];
      }
      else {
        uVar10 = *puVar15 + 1;
        uVar16 = puVar15[1] + (uint)(0xfffffffe < *puVar15);
      }
      if ((puVar15[3] & 0x40) != 0) {
        FUN_007cf9b0(puVar15);
      }
      *puVar15 = uVar10;
      puVar15[1] = uVar16;
      *(undefined2 *)(puVar15 + 3) = 4;
    }
    break;
  case (uint *)0x75:
    iVar7 = FUN_007df760();
    if (iVar7 == 0) goto LAB_007e3555;
    *(undefined1 *)(iVar7 + 0x1c) = 1;
    *(undefined1 *)(iVar7 + 0x1e) = 1;
    *(int *)(iVar7 + 0x48) = iVar7 + 0x22;
    *(undefined1 *)(iVar7 + 0x20) = 1;
    *(undefined1 *)(iVar7 + 0x21) = 0;
    break;
  case (uint *)0x76:
switchD_007df9a7_caseD_76:
    *(undefined2 *)(puVar15 + 0x13) = 1;
    puVar17 = puVar15 + 0x10;
    local_3a8 = puVar15 + 0x10;
    break;
  case (uint *)0x77:
    goto switchD_007df9a7_caseD_77;
  case (uint *)0x78:
    local_3a4 = (uint *)FUN_007cfb80(*(int *)(pbVar22 + 4) * 0x40 + param_1[0x18],puVar15);
    puVar15 = puVar15 + -0x10;
    puVar17 = puVar15;
    local_3a8 = puVar15;
    if (*(int *)(pbVar22 + 8) == 0) goto switchD_007df9a7_caseD_1;
    break;
  case (uint *)0x79:
    piVar12 = *(int **)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    if (*piVar12 == 0) {
      iStack_330 = 1;
    }
    else {
      local_3a4 = (uint *)FUN_007d7800(*piVar12,&iStack_330);
      *(bool *)((int)piVar12 + 0x1a) = iStack_330 == 0;
      *(undefined1 *)((int)piVar12 + 0x1f) = 0;
      *(undefined1 *)(piVar12 + 0x15) = 0;
    }
    *(undefined1 *)(piVar12 + 7) = (undefined1)iStack_330;
    if (iStack_330 != 0) {
      if (0 < *(int *)(pbVar22 + 8)) {
        local_394 = *(int *)(pbVar22 + 8) + -1;
      }
    }
    break;
  case (uint *)0x7c:
    iVar7 = *(int *)(param_1[0xf] + *(int *)(pbVar22 + 4) * 4);
    *(undefined1 *)(iVar7 + 0x1c) = 1;
    *(undefined1 *)(iVar7 + 0x19) = 0;
    break;
  default:
    FUN_007e4880(100,auStack_78,&DAT_009fff54,puStack_39c);
    FUN_007d0700(param_1 + 0x8e,s_unknown_opcode_00a00f50,auStack_78,0);
    local_3a4 = (uint *)0x2;
    break;
  case (uint *)0x80:
    puVar17 = puVar15 + 0x10;
    *(undefined2 *)(puVar15 + 0x13) = 0xa2;
    pcVar9 = *(char **)(pbVar22 + 0xc);
    puVar15[0x16] = (uint)pcVar9;
    pcVar8 = pcVar9 + 1;
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    puVar15[0x12] = (int)pcVar9 - (int)pcVar8;
    *(undefined1 *)((int)puVar15 + 0x4f) = 1;
    local_3a8 = puVar17;
    fVar25 = (float10)FUN_007d0050(puVar17);
    *(double *)(puVar15 + 0x14) = (double)fVar25;
    *(byte *)(puVar15 + 0x13) = (byte)puVar15[0x13] | 8;
    FUN_007cfe90(puVar17,(char)local_3a0[4]);
    break;
  case (uint *)0x81:
    pcVar8 = *(char **)(pbVar22 + 0xc);
    *pbVar22 = 0x77;
    pcVar9 = pcVar8;
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    uVar10 = (uint)((int)pcVar9 - (int)(pcVar8 + 1)) >> 1;
    *(uint *)(pbVar22 + 4) = uVar10;
    if (uVar10 == 0) {
      if (*(int *)(pbVar22 + 0x10) == -1) {
        FUN_007d05b0(pcVar8);
      }
      pbVar22[0x10] = 0xfe;
      pbVar22[0x11] = 0xff;
      pbVar22[0x12] = 0xff;
      pbVar22[0x13] = 0xff;
      *(undefined1 **)(pbVar22 + 0xc) = &DAT_0099cf70;
    }
    else {
      iVar7 = FUN_007d11c0(pcVar8);
      if (iVar7 == 0) goto LAB_007e3555;
      if (*(int *)(pbVar22 + 0x10) == -1) {
        FUN_007d05b0(*(undefined4 *)(pbVar22 + 0xc));
      }
      *(int *)(pbVar22 + 0xc) = iVar7;
      pbVar22[0x10] = 0xff;
      pbVar22[0x11] = 0xff;
      pbVar22[0x12] = 0xff;
      pbVar22[0x13] = 0xff;
    }
switchD_007df9a7_caseD_77:
    puVar17 = puVar15 + 0x10;
    local_3a8 = puVar17;
    FUN_007cfbe0(puVar17,*(undefined4 *)(pbVar22 + 0xc),*(undefined4 *)(pbVar22 + 4),0,0);
  }
switchD_007df9a7_caseD_d:
  local_394 = local_394 + 1;
  puVar15 = puVar17;
  if (local_3a4 != (uint *)0x0) goto code_r0x007e3311;
  goto LAB_007df921;
code_r0x007e3311:
  param_1[0x22] = (int)local_3a4;
  iVar7 = 1;
LAB_007e3630:
  FUN_007ddd70(param_1);
  param_1[0xb] = (int)puVar17;
  return iVar7;
}


