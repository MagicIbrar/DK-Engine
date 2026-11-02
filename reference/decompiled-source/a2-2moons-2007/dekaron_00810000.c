// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x810000-0x81ffff

// ==== __cintrindisp2 @ 0x00810090 ====

/* Library Function - Single Match
    __cintrindisp2
   
   Library: Visual Studio */

void __cintrindisp2(void)

{
  __trandisp2();
  FUN_0081015a();
  return;
}


// ==== __cintrindisp1 @ 0x008100ce ====

/* Library Function - Single Match
    __cintrindisp1
   
   Library: Visual Studio */

void __cintrindisp1(void)

{
  __trandisp1();
  FUN_0081015a();
  return;
}


// ==== __ctrandisp2 @ 0x0081010b ====

/* Library Function - Single Match
    __ctrandisp2
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */

void __ctrandisp2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __fload(param_1,param_2);
  __fload(param_3,param_4);
  __trandisp2();
  FUN_00810153();
  return;
}


// ==== FUN_00810153 @ 0x00810153 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00810153(void)

{
  char cVar1;
  ushort uVar2;
  int unaff_EBP;
  ushort in_FPUStatusWord;
  float10 in_ST0;
  
  *(byte *)(unaff_EBP + -0x2c8) = *(byte *)(unaff_EBP + -0x2c8) & 0xfe;
  if (DAT_00b5c638 != 0) {
    return;
  }
  *(double *)(unaff_EBP + -0x2d0) = (double)in_ST0;
  cVar1 = *(char *)(unaff_EBP + -0x90);
  if (cVar1 != '\0') {
    if (cVar1 == -1) {
      uVar2 = *(ushort *)(unaff_EBP + -0x2ca) & 0x7ff0;
    }
    else {
      if (cVar1 != -2) {
        if (cVar1 == '\0') {
          return;
        }
        *(int *)(unaff_EBP + -0x8e) = (int)cVar1;
        goto LAB_0081023f;
      }
      uVar2 = *(ushort *)(unaff_EBP + -0x2ca) & 0x7ff0;
      if (uVar2 == 0) {
        *(undefined4 *)(unaff_EBP + -0x8e) = 4;
        in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_00a0b778);
        if (ABS(in_ST0) < (float10)_DAT_00a0b768) {
          in_ST0 = in_ST0 * (float10)_DAT_00a0b788;
        }
        goto LAB_0081023f;
      }
    }
    if (uVar2 == 0x7ff0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 3;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_00a0b770);
      if ((float10)_DAT_00a0b760 < ABS(in_ST0)) {
        in_ST0 = in_ST0 * (float10)_DAT_00a0b780;
      }
      goto LAB_0081023f;
    }
  }
  if ((*(ushort *)(unaff_EBP + -0xa4) & 0x20) != 0) {
    return;
  }
  if ((in_FPUStatusWord & 0x20) == 0) {
    return;
  }
  *(undefined4 *)(unaff_EBP + -0x8e) = 8;
LAB_0081023f:
  *(int *)(unaff_EBP + -0x8a) = *(int *)(unaff_EBP + -0x94) + 1;
  if ((*(byte *)(unaff_EBP + -0x2c8) & 1) == 0) {
    *(undefined4 *)(unaff_EBP + -0x86) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x82) = *(undefined4 *)(unaff_EBP + 0xc);
    if (*(char *)(*(int *)(unaff_EBP + -0x94) + 0xd) != '\x01') {
      *(undefined4 *)(unaff_EBP + -0x7e) = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -0x7a) = *(undefined4 *)(unaff_EBP + 0x14);
    }
  }
  *(double *)(unaff_EBP + -0x76) = (double)in_ST0;
  FUN_008138d5((int)*(char *)(*(int *)(unaff_EBP + -0x94) + 0xe),unaff_EBP + -0x8e,unaff_EBP + -0xa4
              );
  return;
}


// ==== FUN_0081015a @ 0x0081015a ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0081015a(void)

{
  char cVar1;
  ushort uVar2;
  int unaff_EBP;
  ushort in_FPUStatusWord;
  float10 in_ST0;
  
  if (DAT_00b5c638 != 0) {
    return;
  }
  *(double *)(unaff_EBP + -0x2d0) = (double)in_ST0;
  cVar1 = *(char *)(unaff_EBP + -0x90);
  if (cVar1 != '\0') {
    if (cVar1 == -1) {
      uVar2 = *(ushort *)(unaff_EBP + -0x2ca) & 0x7ff0;
    }
    else {
      if (cVar1 != -2) {
        if (cVar1 == '\0') {
          return;
        }
        *(int *)(unaff_EBP + -0x8e) = (int)cVar1;
        goto LAB_0081023f;
      }
      uVar2 = *(ushort *)(unaff_EBP + -0x2ca) & 0x7ff0;
      if (uVar2 == 0) {
        *(undefined4 *)(unaff_EBP + -0x8e) = 4;
        in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_00a0b778);
        if (ABS(in_ST0) < (float10)_DAT_00a0b768) {
          in_ST0 = in_ST0 * (float10)_DAT_00a0b788;
        }
        goto LAB_0081023f;
      }
    }
    if (uVar2 == 0x7ff0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 3;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_00a0b770);
      if ((float10)_DAT_00a0b760 < ABS(in_ST0)) {
        in_ST0 = in_ST0 * (float10)_DAT_00a0b780;
      }
      goto LAB_0081023f;
    }
  }
  if ((*(ushort *)(unaff_EBP + -0xa4) & 0x20) != 0) {
    return;
  }
  if ((in_FPUStatusWord & 0x20) == 0) {
    return;
  }
  *(undefined4 *)(unaff_EBP + -0x8e) = 8;
LAB_0081023f:
  *(int *)(unaff_EBP + -0x8a) = *(int *)(unaff_EBP + -0x94) + 1;
  if ((*(byte *)(unaff_EBP + -0x2c8) & 1) == 0) {
    *(undefined4 *)(unaff_EBP + -0x86) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x82) = *(undefined4 *)(unaff_EBP + 0xc);
    if (*(char *)(*(int *)(unaff_EBP + -0x94) + 0xd) != '\x01') {
      *(undefined4 *)(unaff_EBP + -0x7e) = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -0x7a) = *(undefined4 *)(unaff_EBP + 0x14);
    }
  }
  *(double *)(unaff_EBP + -0x76) = (double)in_ST0;
  FUN_008138d5((int)*(char *)(*(int *)(unaff_EBP + -0x94) + 0xe),unaff_EBP + -0x8e,unaff_EBP + -0xa4
              );
  return;
}


// ==== __ctrandisp1 @ 0x008102a1 ====

/* Library Function - Single Match
    __ctrandisp1
   
   Library: Visual Studio */

void __ctrandisp1(undefined4 param_1,undefined4 param_2)

{
  __fload(param_1,param_2);
  __trandisp1();
  FUN_00810153();
  return;
}


// ==== __fload @ 0x008102d4 ====

/* Library Function - Single Match
    __fload
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */

float10 __fload(uint param_1,int param_2)

{
  float10 fVar1;
  
  if ((param_2._2_2_ & 0x7ff0) == 0x7ff0) {
    fVar1 = (float10)CONCAT28(param_2._2_2_ | 0x7fff,
                              CONCAT44(param_2 << 0xb | param_1 >> 0x15,param_1));
  }
  else {
    fVar1 = (float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
  }
  return fVar1;
}


// ==== FUN_00810b16 @ 0x00810b16 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00810b16(undefined4 param_1,uint param_2,ushort param_3)

{
  undefined4 in_EAX;
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  undefined4 in_stack_0000001c;
  undefined2 uStack00000020;
  undefined2 uStack00000022;
  ushort in_stack_00000024;
  
  if ((((((CONCAT22(param_3,param_2._2_2_) ^ 0x700) & 0x700) == 0) &&
       ((&DAT_00b4a06c)[(param_2._2_2_ & 0x7800) >> 0xb] != '\0')) && ((param_3 & 0x7fff) != 0x7fff)
      ) && ((((in_stack_00000024 & 0x7fff) != 0 && ((in_stack_00000024 & 0x7fff) != 0x7fff)) &&
            (((_uStack00000020 & 0x7fffffff) == 0 && ((param_2 & 0x7fffffff) == 0)))))) {
    if ((ushort)((param_3 & 0x7fff) + 0x3f) < (in_stack_00000024 & 0x7fff)) {
      iVar1 = ((in_stack_00000024 & 0x7fff) - (param_3 & 0x7fff) & 0x3f | 0x20) + 1;
      param_3 = in_stack_00000024 & 0x7fff | param_3 & 0x8000;
      fVar3 = ABS((float10)CONCAT28(param_3,CONCAT26(param_2._2_2_,
                                                     CONCAT24((undefined2)param_2,param_1))));
      fVar2 = ABS((float10)CONCAT28(in_stack_00000024,
                                    CONCAT26(uStack00000022,
                                             CONCAT24(uStack00000020,in_stack_0000001c))));
      do {
        if (fVar3 <= fVar2) {
          fVar2 = fVar2 - fVar3;
        }
        fVar3 = fVar3 * (float10)_DAT_00b4a09c;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    else {
      while (-1 < (int)((in_stack_00000024 & 0x7fff) - ((param_3 & 0x7fff) + 10))) {
        fVar2 = (float10)CONCAT28(in_stack_00000024,
                                  CONCAT26(uStack00000022,CONCAT24(uStack00000020,in_stack_0000001c)
                                          ));
        fVar3 = (float10)CONCAT28((in_stack_00000024 & 0x7fff) -
                                  ((in_stack_00000024 & 0x7fff) - param_3 & 7 | 4) |
                                  param_3 & 0x8000,
                                  CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)));
        fVar2 = fVar2 - (float10)(unkint10)(fVar2 / fVar3) * fVar3;
        in_stack_0000001c = SUB104(fVar2,0);
        uStack00000020 = (undefined2)((unkuint10)fVar2 >> 0x20);
        uStack00000022 = (undefined2)((unkuint10)fVar2 >> 0x30);
        in_stack_00000024 = (ushort)((unkuint10)fVar2 >> 0x40);
      }
    }
  }
  return in_EAX;
}


// ==== FUN_00810d1c @ 0x00810d1c ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00810d1c(void)

{
  float10 in_ST0;
  float10 fVar1;
  float10 in_ST1;
  
  if (((uint)((unkuint10)in_ST1 >> 0x30) & 0x7fff0000) != 0) {
    fVar1 = (float10)FUN_00810b16();
    return fVar1;
  }
  if (SUB104(in_ST1,0) == 0 && (int)((unkuint10)in_ST1 >> 0x20) == 0) {
    return in_ST0 - (float10)(unkint10)(in_ST0 / in_ST1) * in_ST1;
  }
  fVar1 = (float10)FUN_00810b16(in_ST1 * (float10)_DAT_00b4a084);
  return fVar1;
}


// ==== xtoa @ 0x0081109b ====

/* Library Function - Single Match
    _xtoa
   
   Library: Visual Studio 2003 Release */

void __cdecl xtoa(uint param_1,int param_2)

{
  char *pcVar1;
  uint in_EAX;
  uint uVar2;
  char *in_ECX;
  char *pcVar3;
  char cVar4;
  
  pcVar1 = in_ECX;
  if (param_2 != 0) {
    *in_ECX = '-';
    in_ECX = in_ECX + 1;
    in_EAX = -in_EAX;
    pcVar1 = in_ECX;
  }
  do {
    pcVar3 = pcVar1;
    uVar2 = in_EAX / param_1;
    cVar4 = (char)(in_EAX % param_1);
    if (in_EAX % param_1 < 10) {
      cVar4 = cVar4 + '0';
    }
    else {
      cVar4 = cVar4 + 'W';
    }
    *pcVar3 = cVar4;
    in_EAX = uVar2;
    pcVar1 = pcVar3 + 1;
  } while (uVar2 != 0);
  pcVar3[1] = '\0';
  do {
    cVar4 = *pcVar3;
    *pcVar3 = *in_ECX;
    pcVar3 = pcVar3 + -1;
    *in_ECX = cVar4;
    in_ECX = in_ECX + 1;
  } while (in_ECX < pcVar3);
  return;
}


// ==== __itoa @ 0x008110d9 ====

/* Library Function - Single Match
    __itoa
   
   Library: Visual Studio 2003 Release */

char * __cdecl __itoa(int _Value,char *_Dest,int _Radix)

{
  undefined4 uVar1;
  
  if ((_Radix == 10) && (_Value < 0)) {
    uVar1 = 1;
    _Radix = 10;
  }
  else {
    uVar1 = 0;
  }
  xtoa(_Radix,uVar1);
  return _Dest;
}


// ==== __ultoa @ 0x00811103 ====

/* Library Function - Single Match
    __ultoa
   
   Library: Visual Studio 2003 Release */

char * __cdecl __ultoa(ulong _Value,char *_Dest,int _Radix)

{
  xtoa(_Radix,0);
  return _Dest;
}


// ==== __mbsrchr @ 0x00811123 ====

/* Library Function - Single Match
    __mbsrchr
   
   Library: Visual Studio 2003 Release */

uchar * __cdecl __mbsrchr(uchar *_Str,uint _Ch)

{
  byte bVar1;
  ushort uVar2;
  _ptiddata p_Var3;
  void *pvVar4;
  uchar *puVar5;
  byte *pbVar6;
  byte bVar7;
  byte *pbVar8;
  bool bVar9;
  
  pbVar8 = (byte *)0x0;
  p_Var3 = __getptd();
  pvVar4 = p_Var3->_tpxcptinfoptrs;
  if (pvVar4 != DAT_00b60d04) {
    pvVar4 = (void *)FUN_0081276a();
  }
  if (*(int *)((int)pvVar4 + 8) == 0) {
    puVar5 = (uchar *)_strrchr((char *)_Str,_Ch);
    return puVar5;
  }
  do {
    bVar7 = *_Str;
    if ((*(byte *)(bVar7 + 0x1d + (int)pvVar4) & 4) == 0) {
      bVar9 = _Ch == bVar7;
LAB_0081117e:
      pbVar6 = _Str;
      if (bVar9) {
        pbVar8 = _Str;
      }
    }
    else {
      pbVar6 = _Str + 1;
      bVar1 = *pbVar6;
      if (bVar1 == 0) {
        bVar9 = pbVar8 == (byte *)0x0;
        _Str = pbVar6;
        bVar7 = bVar1;
        goto LAB_0081117e;
      }
      uVar2 = CONCAT11(bVar7,bVar1);
      bVar7 = bVar1;
      if (_Ch == uVar2) {
        pbVar8 = _Str;
      }
    }
    _Str = pbVar6 + 1;
    if (bVar7 == 0) {
      return pbVar8;
    }
  } while( true );
}


// ==== FUN_0081118e @ 0x0081118e ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

int FUN_0081118e(void)

{
  void *_File;
  int iVar1;
  int _Index;
  int local_20;
  
  local_20 = 0;
  __lock(1);
  for (_Index = 0; _Index < DAT_00b620c0; _Index = _Index + 1) {
    _File = *(void **)(DAT_00b610b0 + _Index * 4);
    if ((_File != (void *)0x0) && ((*(byte *)((int)_File + 0xc) & 0x83) != 0)) {
      __lock_file2(_Index,_File);
      iVar1 = *(int *)(DAT_00b610b0 + _Index * 4);
      if (((*(byte *)(iVar1 + 0xc) & 0x83) != 0) && (*(int *)(iVar1 + 0x1c) != 0)) {
        FUN_00803a2e(iVar1);
        local_20 = local_20 + 1;
      }
      FUN_00811204();
    }
  }
  FUN_00811227();
  return local_20;
}


// ==== FUN_00811204 @ 0x00811204 ====

void FUN_00811204(void)

{
  int unaff_ESI;
  
  __unlock_file2(unaff_ESI,*(void **)(DAT_00b610b0 + unaff_ESI * 4));
  return;
}


// ==== FUN_00811227 @ 0x00811227 ====

void FUN_00811227(void)

{
  FUN_00806c2f(1);
  return;
}


// ==== __access @ 0x00811230 ====

/* Library Function - Single Match
    __access
   
   Library: Visual Studio 2003 Release */

int __cdecl __access(char *_Filename,int _AccessMode)

{
  DWORD DVar1;
  undefined4 *puVar2;
  
  DVar1 = GetFileAttributesA(_Filename);
  if (DVar1 == 0xffffffff) {
    DVar1 = GetLastError();
    __dosmaperr(DVar1);
  }
  else {
    if (((DVar1 & 1) == 0) || ((_AccessMode & 2U) == 0)) {
      return 0;
    }
    puVar2 = (undefined4 *)FUN_00804b94();
    *puVar2 = 0xd;
    puVar2 = (undefined4 *)FUN_00804b9d();
    *puVar2 = 5;
  }
  return -1;
}


// ==== __tsopen_lk @ 0x00811276 ====

/* Library Function - Single Match
    __tsopen_lk
   
   Library: Visual Studio 2003 Release */

uint __tsopen_lk(undefined4 *param_1,uint *param_2,LPCSTR param_3,uint param_4,byte param_5)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  undefined4 *puVar4;
  HANDLE hFile;
  int *piVar5;
  int iVar6;
  int in_ECX;
  DWORD DVar7;
  int iVar8;
  bool bVar9;
  _SECURITY_ATTRIBUTES local_20;
  DWORD local_14;
  DWORD local_10;
  uint local_c;
  char local_6;
  byte local_5;
  
  bVar9 = -1 < (char)param_4;
  local_20.nLength = 0xc;
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  if (bVar9) {
    local_5 = 0;
  }
  else {
    local_5 = 0x10;
  }
  local_20.bInheritHandle = (BOOL)bVar9;
  if (((param_4 & 0x8000) == 0) && (((param_4 & 0x4000) != 0 || (DAT_00b5cbb8 != 0x8000)))) {
    local_5 = local_5 | 0x80;
  }
  uVar3 = param_4 & 3;
  if (uVar3 == 0) {
    local_14 = 0x80000000;
  }
  else if (uVar3 == 1) {
    local_14 = 0x40000000;
  }
  else {
    if (uVar3 != 2) goto LAB_008112fd;
    local_14 = 0xc0000000;
  }
  if (in_ECX == 0x10) {
    local_c = 0;
  }
  else if (in_ECX == 0x20) {
    local_c = 1;
  }
  else if (in_ECX == 0x30) {
    local_c = 2;
  }
  else {
    if (in_ECX != 0x40) {
LAB_008112fd:
      puVar4 = (undefined4 *)FUN_00804b94();
      *puVar4 = 0x16;
      puVar4 = (undefined4 *)FUN_00804b9d();
      *puVar4 = 0;
      return 0xffffffff;
    }
    local_c = 3;
  }
  uVar3 = param_4 & 0x700;
  if (uVar3 < 0x401) {
    if ((uVar3 == 0x400) || (uVar3 == 0)) {
      local_10 = 3;
    }
    else if (uVar3 == 0x100) {
      local_10 = 4;
    }
    else {
      if (uVar3 == 0x200) goto LAB_008113a4;
      if (uVar3 != 0x300) goto LAB_0081138a;
      local_10 = 2;
    }
  }
  else {
    if (uVar3 != 0x500) {
      if (uVar3 == 0x600) {
LAB_008113a4:
        local_10 = 5;
        goto LAB_008113b4;
      }
      if (uVar3 != 0x700) {
LAB_0081138a:
        puVar4 = (undefined4 *)FUN_00804b94();
        *puVar4 = 0x16;
        puVar4 = (undefined4 *)FUN_00804b9d();
        *puVar4 = 0;
        return 0xffffffff;
      }
    }
    local_10 = 1;
  }
LAB_008113b4:
  DVar7 = 0x80;
  if (((param_4 & 0x100) != 0) && (-1 < (char)(~(byte)DAT_00b5c71c & param_5))) {
    DVar7 = 1;
  }
  if ((param_4 & 0x40) != 0) {
    local_14 = CONCAT13(local_14._3_1_,0x10000);
    DVar7 = DVar7 | 0x4000000;
    if (DAT_00b5c720 == 2) {
      local_c = local_c | 4;
    }
  }
  if ((param_4 & 0x1000) != 0) {
    DVar7 = DVar7 | 0x100;
  }
  if ((param_4 & 0x20) == 0) {
    if ((param_4 & 0x10) != 0) {
      DVar7 = DVar7 | 0x10000000;
    }
  }
  else {
    DVar7 = DVar7 | 0x8000000;
  }
  uVar3 = __alloc_osfhnd();
  if (uVar3 == 0xffffffff) {
    puVar4 = (undefined4 *)FUN_00804b94();
    *puVar4 = 0x18;
    puVar4 = (undefined4 *)FUN_00804b9d();
    *puVar4 = 0;
  }
  else {
    *param_1 = 1;
    *param_2 = uVar3;
    hFile = CreateFileA(param_3,local_14,local_c,&local_20,local_10,DVar7,(HANDLE)0x0);
    if (hFile != (HANDLE)0xffffffff) {
      DVar7 = GetFileType(hFile);
      if (DVar7 != 0) {
        if (DVar7 == 2) {
          local_5 = local_5 | 0x40;
        }
        else if (DVar7 == 3) {
          local_5 = local_5 | 8;
        }
        __set_osfhnd(uVar3,(intptr_t)hFile);
        bVar2 = local_5 | 1;
        iVar8 = (uVar3 & 0x1f) * 0x24;
        local_5 = local_5 & 0x48;
        *(byte *)(iVar8 + 4 + (&DAT_00b60fa0)[(int)uVar3 >> 5]) = bVar2;
        if (((local_5 != 0) || (-1 < (char)bVar2)) || ((param_4 & 2) == 0)) {
LAB_008114f6:
          if (local_5 != 0) {
            return uVar3;
          }
          if ((param_4 & 8) == 0) {
            return uVar3;
          }
          pbVar1 = (byte *)(iVar8 + 4 + (&DAT_00b60fa0)[(int)uVar3 >> 5]);
          *pbVar1 = *pbVar1 | 0x20;
          return uVar3;
        }
        local_14 = __lseek_lk(uVar3,0xffffffff,2);
        if (local_14 == -1) {
          piVar5 = (int *)FUN_00804b9d();
          if (*piVar5 == 0x83) goto LAB_008114f6;
        }
        else {
          local_6 = '\0';
          iVar6 = FUN_008115f6(uVar3,&local_6,1);
          if ((((iVar6 != 0) || (local_6 != '\x1a')) ||
              (iVar6 = FUN_0081433b(uVar3,local_14), iVar6 != -1)) &&
             (iVar6 = __lseek_lk(uVar3,0,0), iVar6 != -1)) goto LAB_008114f6;
        }
        __close_lk(uVar3);
        return 0xffffffff;
      }
      CloseHandle(hFile);
    }
    DVar7 = GetLastError();
    __dosmaperr(DVar7);
  }
  return 0xffffffff;
}


// ==== __sopen @ 0x0081155d ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __sopen
   
   Library: Visual Studio 2003 Release */

int __cdecl __sopen(char *_Filename,int _OpenFlag,int _ShareFlag,...)

{
  int iVar1;
  undefined4 in_stack_00000010;
  undefined1 local_24 [4];
  undefined4 local_20 [5];
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x811569;
  local_20[0] = 0;
  local_8 = 0;
  iVar1 = __tsopen_lk(local_20,local_24,_Filename,_OpenFlag,in_stack_00000010);
  local_8 = 0xffffffff;
  FUN_008115a2();
  return iVar1;
}


// ==== FUN_008115a2 @ 0x008115a2 ====

void FUN_008115a2(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) != 0) {
    __unlock_fhandle(*(int *)(unaff_EBP + -0x20));
  }
  return;
}


// ==== __getbuf @ 0x008115b2 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __getbuf
   
   Library: Visual Studio 2003 Release */

void __cdecl __getbuf(FILE *_File)

{
  char *pcVar1;
  
  _DAT_00b5c644 = _DAT_00b5c644 + 1;
  pcVar1 = _malloc(0x1000);
  _File->_base = pcVar1;
  if (pcVar1 == (char *)0x0) {
    _File->_flag = _File->_flag | 4;
    _File->_base = (char *)&_File->_charbuf;
    _File->_bufsiz = 2;
  }
  else {
    _File->_flag = _File->_flag | 8;
    _File->_bufsiz = 0x1000;
  }
  _File->_cnt = 0;
  _File->_ptr = _File->_base;
  return;
}


// ==== FUN_008115f6 @ 0x008115f6 ====

int FUN_008115f6(uint param_1,char *param_2,char *param_3)

{
  int *piVar1;
  byte *pbVar2;
  char *pcVar3;
  byte bVar4;
  char cVar5;
  BOOL BVar6;
  DWORD DVar7;
  undefined4 *puVar8;
  char *pcVar9;
  int iVar10;
  DWORD local_10;
  char *local_c;
  char local_5;
  
  local_c = (char *)0x0;
  if (param_3 != (char *)0x0) {
    piVar1 = &DAT_00b60fa0 + ((int)param_1 >> 5);
    iVar10 = (param_1 & 0x1f) * 0x24;
    bVar4 = *(byte *)(*piVar1 + iVar10 + 4);
    if ((bVar4 & 2) == 0) {
      pcVar9 = param_2;
      if (((bVar4 & 0x48) != 0) && (*(char *)(*piVar1 + iVar10 + 5) != '\n')) {
        param_3 = (char *)((int)param_3 - 1);
        *param_2 = *(char *)(*piVar1 + 5 + iVar10);
        pcVar9 = param_2 + 1;
        local_c = (char *)0x1;
        *(undefined1 *)(*piVar1 + 5 + iVar10) = 10;
      }
      BVar6 = ReadFile(*(HANDLE *)(*piVar1 + iVar10),pcVar9,(DWORD)param_3,&local_10,
                       (LPOVERLAPPED)0x0);
      if (BVar6 == 0) {
        DVar7 = GetLastError();
        if (DVar7 == 5) {
          puVar8 = (undefined4 *)FUN_00804b94();
          *puVar8 = 9;
          puVar8 = (undefined4 *)FUN_00804b9d();
          *puVar8 = 5;
        }
        else {
          if (DVar7 == 0x6d) {
            return 0;
          }
          __dosmaperr(DVar7);
        }
        return -1;
      }
      local_c = (char *)((int)local_c + local_10);
      if ((*(byte *)(*piVar1 + 4 + iVar10) & 0x80) != 0) {
        if ((local_10 == 0) || (*param_2 != '\n')) {
          pbVar2 = (byte *)(*piVar1 + 4 + iVar10);
          *pbVar2 = *pbVar2 & 0xfb;
        }
        else {
          pbVar2 = (byte *)(*piVar1 + 4 + iVar10);
          *pbVar2 = *pbVar2 | 4;
        }
        local_c = param_2 + (int)local_c;
        param_3 = param_2;
        pcVar9 = param_2;
        if (param_2 < local_c) {
          do {
            cVar5 = *param_3;
            if (cVar5 == '\x1a') {
              if ((*(byte *)(*piVar1 + 4 + iVar10) & 0x40) == 0) {
                pbVar2 = (byte *)(*piVar1 + 4 + iVar10);
                *pbVar2 = *pbVar2 | 2;
              }
              break;
            }
            if (cVar5 == '\r') {
              if (param_3 < local_c + -1) {
                if (param_3[1] == '\n') {
                  pcVar3 = param_3 + 2;
                  goto LAB_00811783;
                }
LAB_0081179f:
                param_3 = param_3 + 1;
                *pcVar9 = '\r';
              }
              else {
                pcVar3 = param_3 + 1;
                BVar6 = ReadFile(*(HANDLE *)(*piVar1 + iVar10),&local_5,1,&local_10,
                                 (LPOVERLAPPED)0x0);
                if (((BVar6 == 0) && (DVar7 = GetLastError(), DVar7 != 0)) || (local_10 == 0))
                goto LAB_0081179f;
                if ((*(byte *)(*piVar1 + 4 + iVar10) & 0x48) == 0) {
                  if ((pcVar9 == param_2) && (local_5 == '\n')) goto LAB_00811783;
                  __lseeki64_lk(param_1,0xffffffff,0xffffffff,1);
                  if (local_5 == '\n') goto LAB_008117a3;
                  goto LAB_0081179f;
                }
                if (local_5 == '\n') {
LAB_00811783:
                  param_3 = pcVar3;
                  *pcVar9 = '\n';
                }
                else {
                  *pcVar9 = '\r';
                  *(char *)(*piVar1 + 5 + iVar10) = local_5;
                  param_3 = pcVar3;
                }
              }
              pcVar9 = pcVar9 + 1;
              pcVar3 = param_3;
            }
            else {
              *pcVar9 = cVar5;
              pcVar9 = pcVar9 + 1;
              pcVar3 = param_3 + 1;
            }
LAB_008117a3:
            param_3 = pcVar3;
          } while (param_3 < local_c);
        }
        local_c = (char *)((int)pcVar9 - (int)param_2);
      }
      return (int)local_c;
    }
  }
  return 0;
}


// ==== __read @ 0x008117d3 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __read
   
   Library: Visual Studio 2003 Release */

int __cdecl __read(int _FileHandle,void *_DstBuf,uint _MaxCharCount)

{
  undefined4 *puVar1;
  int iVar2;
  int local_20;
  
  if ((uint)_FileHandle < DAT_00b60f80) {
    iVar2 = (_FileHandle & 0x1fU) * 0x24;
    if ((*(byte *)((&DAT_00b60fa0)[_FileHandle >> 5] + 4 + iVar2) & 1) != 0) {
      __lock_fhandle(_FileHandle);
      if ((*(byte *)((&DAT_00b60fa0)[_FileHandle >> 5] + 4 + iVar2) & 1) == 0) {
        puVar1 = (undefined4 *)FUN_00804b94();
        *puVar1 = 9;
        puVar1 = (undefined4 *)FUN_00804b9d();
        *puVar1 = 0;
        local_20 = -1;
      }
      else {
        local_20 = FUN_008115f6(_FileHandle,_DstBuf,_MaxCharCount);
      }
      FUN_0081185a();
      return local_20;
    }
  }
  puVar1 = (undefined4 *)FUN_00804b94();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_00804b9d();
  *puVar1 = 0;
  return -1;
}


// ==== FUN_0081185a @ 0x0081185a ====

void FUN_0081185a(void)

{
  int unaff_EBX;
  
  __unlock_fhandle(unaff_EBX);
  return;
}


// ==== FUN_0081187e @ 0x0081187e ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0081187e(uint param_1,char *param_2,DWORD param_3)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  BOOL BVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  DWORD local_428;
  char *local_424;
  int local_420;
  DWORD local_41c;
  char *local_418;
  int local_414;
  ulong local_410;
  char local_40c [100];
  undefined1 local_3a8 [928];
  uint local_8;
  
  local_8 = DAT_00b49670 ^ (uint)local_3a8;
  local_424 = param_2;
  local_41c = 0;
  local_420 = 0;
  if (param_3 == 0) {
    return 0;
  }
  piVar1 = &DAT_00b60fa0 + ((int)param_1 >> 5);
  iVar8 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)(*piVar1 + 4 + iVar8) & 0x20) != 0) {
    __lseeki64_lk(param_1,0,0,2);
  }
  if ((*(byte *)((undefined4 *)(*piVar1 + iVar8) + 1) & 0x80) == 0) {
    BVar5 = WriteFile(*(HANDLE *)(*piVar1 + iVar8),param_2,param_3,&local_428,(LPOVERLAPPED)0x0);
    if (BVar5 == 0) {
LAB_008119b6:
      local_410 = GetLastError();
    }
    else {
      local_410 = 0;
      local_41c = local_428;
    }
  }
  else {
    local_418 = param_2;
    local_410 = 0;
    if (param_3 == 0) goto LAB_008119f5;
    do {
      local_414 = 0;
      uVar7 = (int)local_418 - (int)local_424;
      pcVar4 = local_40c;
      do {
        if (param_3 <= uVar7) break;
        pcVar2 = local_418 + 1;
        cVar3 = *local_418;
        uVar7 = uVar7 + 1;
        if (cVar3 == '\n') {
          local_420 = local_420 + 1;
          *pcVar4 = '\r';
          pcVar4 = pcVar4 + 1;
          local_414 = local_414 + 1;
        }
        *pcVar4 = cVar3;
        pcVar4 = pcVar4 + 1;
        local_414 = local_414 + 1;
        local_418 = pcVar2;
      } while (local_414 < 0x400);
      BVar5 = WriteFile(*(HANDLE *)(*piVar1 + iVar8),local_40c,(int)pcVar4 - (int)local_40c,
                        &local_428,(LPOVERLAPPED)0x0);
      if (BVar5 == 0) goto LAB_008119b6;
      local_41c = local_41c + local_428;
    } while (((int)pcVar4 - (int)local_40c <= (int)local_428) &&
            ((uint)((int)local_418 - (int)local_424) < param_3));
  }
  if (local_41c != 0) {
    return local_41c - local_420;
  }
  if (local_410 != 0) {
    if (local_410 == 5) {
      puVar6 = (undefined4 *)FUN_00804b94();
      *puVar6 = 9;
      puVar6 = (undefined4 *)FUN_00804b9d();
      *puVar6 = 5;
      return -1;
    }
    __dosmaperr(local_410);
    return -1;
  }
  param_2 = local_424;
LAB_008119f5:
  if (((*(byte *)(*piVar1 + 4 + iVar8) & 0x40) == 0) || (*param_2 != '\x1a')) {
    puVar6 = (undefined4 *)FUN_00804b94();
    *puVar6 = 0x1c;
    puVar6 = (undefined4 *)FUN_00804b9d();
    *puVar6 = 0;
    return -1;
  }
  return 0;
}


// ==== __write @ 0x00811a3a ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __write
   
   Library: Visual Studio 2003 Release */

int __cdecl __write(int _FileHandle,void *_Buf,uint _MaxCharCount)

{
  undefined4 *puVar1;
  int iVar2;
  int local_20;
  
  if ((uint)_FileHandle < DAT_00b60f80) {
    iVar2 = (_FileHandle & 0x1fU) * 0x24;
    if ((*(byte *)((&DAT_00b60fa0)[_FileHandle >> 5] + 4 + iVar2) & 1) != 0) {
      __lock_fhandle(_FileHandle);
      if ((*(byte *)((&DAT_00b60fa0)[_FileHandle >> 5] + 4 + iVar2) & 1) == 0) {
        puVar1 = (undefined4 *)FUN_00804b94();
        *puVar1 = 9;
        puVar1 = (undefined4 *)FUN_00804b9d();
        *puVar1 = 0;
        local_20 = -1;
      }
      else {
        local_20 = FUN_0081187e(_FileHandle,_Buf,_MaxCharCount);
      }
      FUN_00811ac1();
      return local_20;
    }
  }
  puVar1 = (undefined4 *)FUN_00804b94();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_00804b9d();
  *puVar1 = 0;
  return -1;
}


// ==== FUN_00811ac1 @ 0x00811ac1 ====

void FUN_00811ac1(void)

{
  int unaff_EBX;
  
  __unlock_fhandle(unaff_EBX);
  return;
}


// ==== __lseek_lk @ 0x00811ae5 ====

/* Library Function - Single Match
    __lseek_lk
   
   Library: Visual Studio 2003 Release */

DWORD __lseek_lk(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  undefined4 *puVar2;
  DWORD DVar3;
  ulong uVar4;
  
  hFile = (HANDLE)__get_osfhandle(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    puVar2 = (undefined4 *)FUN_00804b94();
    *puVar2 = 9;
    return 0xffffffff;
  }
  DVar3 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
  if (DVar3 == 0xffffffff) {
    uVar4 = GetLastError();
  }
  else {
    uVar4 = 0;
  }
  if (uVar4 == 0) {
    pbVar1 = (byte *)((&DAT_00b60fa0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
    *pbVar1 = *pbVar1 & 0xfd;
  }
  else {
    __dosmaperr(uVar4);
    DVar3 = 0xffffffff;
  }
  return DVar3;
}


// ==== __lseek @ 0x00811b59 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __lseek
   
   Library: Visual Studio 2003 Release */

long __cdecl __lseek(int _FileHandle,long _Offset,int _Origin)

{
  undefined4 *puVar1;
  int iVar2;
  long local_20;
  
  if ((uint)_FileHandle < DAT_00b60f80) {
    iVar2 = (_FileHandle & 0x1fU) * 0x24;
    if ((*(byte *)((&DAT_00b60fa0)[_FileHandle >> 5] + 4 + iVar2) & 1) != 0) {
      __lock_fhandle(_FileHandle);
      if ((*(byte *)((&DAT_00b60fa0)[_FileHandle >> 5] + 4 + iVar2) & 1) == 0) {
        puVar1 = (undefined4 *)FUN_00804b94();
        *puVar1 = 9;
        puVar1 = (undefined4 *)FUN_00804b9d();
        *puVar1 = 0;
        local_20 = -1;
      }
      else {
        local_20 = __lseek_lk(_FileHandle,_Offset,_Origin);
      }
      FUN_00811be0();
      return local_20;
    }
  }
  puVar1 = (undefined4 *)FUN_00804b94();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_00804b9d();
  *puVar1 = 0;
  return -1;
}


// ==== FUN_00811be0 @ 0x00811be0 ====

void FUN_00811be0(void)

{
  int unaff_EBX;
  
  __unlock_fhandle(unaff_EBX);
  return;
}


// ==== __commit @ 0x00811c04 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __commit
   
   Library: Visual Studio 2003 Release */

int __cdecl __commit(int _FileHandle)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD *pDVar2;
  undefined4 *puVar3;
  int iVar4;
  DWORD local_20;
  
  if (DAT_00b60f80 <= (uint)_FileHandle) {
LAB_00811cac:
    puVar3 = (undefined4 *)FUN_00804b94();
    *puVar3 = 9;
    return -1;
  }
  iVar4 = (_FileHandle & 0x1fU) * 0x24;
  if ((*(byte *)((&DAT_00b60fa0)[_FileHandle >> 5] + 4 + iVar4) & 1) == 0) goto LAB_00811cac;
  __lock_fhandle(_FileHandle);
  if ((*(byte *)((&DAT_00b60fa0)[_FileHandle >> 5] + 4 + iVar4) & 1) != 0) {
    hFile = (HANDLE)__get_osfhandle(_FileHandle);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      local_20 = GetLastError();
    }
    else {
      local_20 = 0;
    }
    if (local_20 == 0) goto LAB_00811c93;
    pDVar2 = (DWORD *)FUN_00804b9d();
    *pDVar2 = local_20;
  }
  puVar3 = (undefined4 *)FUN_00804b94();
  *puVar3 = 9;
  local_20 = 0xffffffff;
LAB_00811c93:
  FUN_00811ca4();
  return local_20;
}


// ==== FUN_00811ca4 @ 0x00811ca4 ====

void FUN_00811ca4(void)

{
  int unaff_EBX;
  
  __unlock_fhandle(unaff_EBX);
  return;
}


// ==== FUN_00811cc0 @ 0x00811cc0 ====

int FUN_00811cc0(undefined4 param_1,uchar *param_2,undefined4 param_3,undefined4 param_4)

{
  uchar uVar1;
  int iVar2;
  int *piVar3;
  uchar *puVar4;
  char *_Src;
  size_t sVar5;
  uchar *puVar6;
  size_t sVar7;
  uchar *puVar8;
  int extraout_EAX;
  bool bVar9;
  
  iVar2 = FUN_00811e7c(param_1,param_2,param_3,param_4);
  if ((((iVar2 != -1) || (piVar3 = (int *)FUN_00804b94(), *piVar3 != 2)) ||
      (puVar4 = __mbschr(param_2,0x2f), puVar4 != (uchar *)0x0)) ||
     ((_Src = _getenv(&DAT_00a0bb2c), _Src == (char *)0x0 ||
      (puVar4 = _malloc(0x104), puVar4 == (uchar *)0x0)))) {
    return iVar2;
  }
  do {
    do {
      _Src = __getpath(_Src,(char *)puVar4,0x103);
      if ((_Src == (char *)0x0) || (*puVar4 == '\0')) goto LAB_00811e1a;
      sVar5 = _strlen((char *)puVar4);
      uVar1 = puVar4[sVar5 - 1];
      if (uVar1 == '\\') {
        puVar6 = __mbsrchr(puVar4,0x5c);
        bVar9 = puVar4 + (sVar5 - 1) == puVar6;
      }
      else {
        bVar9 = uVar1 == '/';
      }
      if (!bVar9) {
        FUN_00809190(puVar4,&DAT_009ff4a8);
      }
      sVar5 = _strlen((char *)puVar4);
      sVar7 = _strlen((char *)param_2);
      if (0x103 < sVar5 + sVar7) goto LAB_00811e1a;
      FUN_00809190(puVar4,param_2);
      iVar2 = FUN_00811e7c(param_1,puVar4,param_3,param_4);
      if (iVar2 != -1) goto LAB_00811e1a;
      piVar3 = (int *)FUN_00804b94();
    } while (*piVar3 == 2);
    puVar6 = __mbschr(puVar4,0x5c);
    if ((puVar4 != puVar6) && (puVar6 = __mbschr(puVar4,0x2f), puVar4 != puVar6)) break;
    puVar6 = puVar4 + 1;
    puVar8 = __mbschr(puVar6,0x5c);
  } while ((puVar6 == puVar8) || (puVar8 = __mbschr(puVar6,0x2f), puVar6 == puVar8));
LAB_00811e1a:
  _free(puVar4);
  return extraout_EAX;
}


// ==== FUN_00811e29 @ 0x00811e29 ====

undefined4 FUN_00811e29(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_EAX;
  undefined4 local_c;
  void *local_8;
  
  iVar1 = FUN_008147c7(param_3,param_4,&local_8,&local_c,param_2);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  FUN_008145ed(param_1,param_2,local_8,local_c);
  _free(local_8);
  return extraout_EAX;
}


// ==== FUN_00811e7c @ 0x00811e7c ====

undefined4 FUN_00811e7c(undefined4 param_1,uchar *param_2,undefined4 param_3,undefined4 param_4)

{
  uchar *puVar1;
  uchar *puVar2;
  size_t sVar3;
  uchar *puVar4;
  int iVar5;
  char *_Filename;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined **ppuVar6;
  undefined4 local_c;
  
  puVar1 = __mbsrchr(param_2,0x5c);
  puVar2 = __mbsrchr(param_2,0x2f);
  puVar4 = param_2;
  if (puVar2 == (uchar *)0x0) {
    if ((puVar1 == (uchar *)0x0) && (puVar1 = __mbschr(param_2,0x3a), puVar1 == (uchar *)0x0)) {
      sVar3 = _strlen((char *)param_2);
      puVar4 = _malloc(sVar3 + 3);
      if (puVar4 == (uchar *)0x0) {
        return 0xffffffff;
      }
      FUN_00809180(puVar4,&DAT_00a0bb54);
      FUN_00809190(puVar4,param_2);
      puVar1 = puVar4 + 2;
    }
  }
  else if ((puVar1 == (uchar *)0x0) || (puVar1 < puVar2)) {
    puVar1 = puVar2;
  }
  local_c = 0xffffffff;
  puVar1 = __mbsrchr(puVar1,0x2e);
  if (puVar1 != (uchar *)0x0) {
    iVar5 = __access((char *)puVar4,0);
    if (iVar5 != -1) {
      local_c = FUN_00811e29(param_1,puVar4,param_3,param_4);
    }
    if (puVar4 == param_2) {
      return local_c;
    }
    _free(puVar4);
    return extraout_EAX_00;
  }
  sVar3 = _strlen((char *)puVar4);
  _Filename = _malloc(sVar3 + 5);
  if (_Filename == (char *)0x0) {
    return 0xffffffff;
  }
  FUN_00809180(_Filename,puVar4);
  sVar3 = _strlen((char *)puVar4);
  ppuVar6 = &PTR_DAT_00b4a278;
  do {
    FUN_00809180(_Filename + sVar3,*ppuVar6);
    iVar5 = __access(_Filename,0);
    if (iVar5 != -1) {
      FUN_00811e29(param_1,_Filename,param_3,param_4);
      break;
    }
    ppuVar6 = ppuVar6 + -1;
  } while (0xb4a26b < (int)ppuVar6);
  _free(_Filename);
  return extraout_EAX;
}


// ==== __mbsnbicoll @ 0x00811fc5 ====

/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 2003 Release */

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  _ptiddata p_Var1;
  void *pvVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  pvVar2 = p_Var1->_tpxcptinfoptrs;
  if (pvVar2 != DAT_00b60d04) {
    pvVar2 = (void *)FUN_0081276a();
  }
  if (_MaxCount == 0) {
    return 0;
  }
  iVar3 = FUN_00812101(*(undefined4 *)((int)pvVar2 + 0xc),1,_Str1,_MaxCount,_Str2,_MaxCount,
                       *(undefined4 *)((int)pvVar2 + 4));
  if (iVar3 == 0) {
    return 0x7fffffff;
  }
  return iVar3 + -2;
}


// ==== FUN_00812013 @ 0x00812013 ====

undefined4 FUN_00812013(void)

{
  LPCWSTR lpWideCharStr;
  size_t _Size;
  int iVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 *puVar2;
  LPSTR local_8;
  
  local_8 = (LPSTR)0x0;
  lpWideCharStr = (LPCWSTR)*DAT_00b5c748;
  puVar2 = DAT_00b5c748;
  while( true ) {
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
    _Size = WideCharToMultiByte(0,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if ((_Size == 0) || (local_8 = _malloc(_Size), local_8 == (LPSTR)0x0)) {
      return 0xffffffff;
    }
    iVar1 = WideCharToMultiByte(0,0,(LPCWSTR)*puVar2,-1,local_8,_Size,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 == 0) {
      _free(local_8);
      return extraout_EAX_00;
    }
    iVar1 = FUN_00814a70(&local_8,0);
    if ((iVar1 < 0) && (local_8 != (LPSTR)0x0)) break;
    puVar2 = puVar2 + 1;
    lpWideCharStr = (LPCWSTR)*puVar2;
  }
  _free(local_8);
  return extraout_EAX;
}


// ==== __rt_probe_read4@4 @ 0x008120a3 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __rt_probe_read4@4
   
   Library: Visual Studio 2003 Release */

void __rt_probe_read4_4(void)

{
  return;
}


// ==== FUN_008120d4 @ 0x008120d4 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_008120d4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4) = 0x8120e2;
  return 0;
}


// ==== _strncnt @ 0x008120e5 ====

/* Library Function - Single Match
    _strncnt
   
   Library: Visual Studio 2003 Release */

size_t __cdecl _strncnt(char *_String,size_t _Cnt)

{
  char *pcVar1;
  char *in_EAX;
  
  pcVar1 = _String;
  for (; (pcVar1 != (char *)0x0 && (*in_EAX != '\0')); in_EAX = in_EAX + 1) {
    pcVar1 = pcVar1 + -1;
  }
  return (size_t)(_String + (-1 - (int)(pcVar1 + -1)));
}


// ==== FUN_00812101 @ 0x00812101 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Type propagation algorithm not settling */

int FUN_00812101(LCID param_1,DWORD param_2,byte *param_3,char *param_4,byte *param_5,char *param_6,
                UINT param_7)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  BOOL BVar5;
  BYTE *pBVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  int extraout_EAX;
  int extraout_EAX_00;
  UINT UVar12;
  int extraout_EAX_01;
  int extraout_EAX_02;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  size_t unaff_EDI;
  byte *_Memory;
  size_t sStackY_84;
  undefined1 auStack_5a [2];
  size_t local_58 [6];
  byte *local_40;
  undefined1 *local_3c;
  byte *local_38;
  _cpinfo local_34;
  uint local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00a0bb68;
  uStack_c = 0x81210d;
  local_20 = DAT_00b49670 ^ (uint)(local_58 + 0x15);
  local_40 = param_3;
  local_38 = param_5;
  _Memory = (byte *)0x0;
  if (DAT_00b5cb8c == 0) {
    sStackY_84 = 0x812140;
    iVar3 = CompareStringW(0,0,(PCNZWCH)&DAT_0099cdc8,1,(PCNZWCH)&DAT_0099cdc8,1);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00b5cb8c = 2;
      }
    }
    else {
      DAT_00b5cb8c = 1;
    }
  }
  if (0 < (int)param_4) {
    param_4 = (char *)_strncnt(param_4,unaff_EDI);
  }
  if (0 < (int)param_6) {
    param_6 = (char *)_strncnt(param_6,unaff_EDI);
  }
  if ((DAT_00b5cb8c == 2) || (DAT_00b5cb8c == 0)) {
    if (param_1 == 0) {
      param_1 = DAT_00b5ca64;
    }
    if (param_7 == 0) {
      param_7 = DAT_00b5ca74;
    }
    UVar12 = FUN_00812dc7();
    if (UVar12 == 0xffffffff) {
      return 0;
    }
    if (UVar12 != param_7) {
      sStackY_84 = 0x812411;
      _Memory = (byte *)FUN_00812e0e();
      if (_Memory == (byte *)0x0) {
        return 0;
      }
      sStackY_84 = 0x81242c;
      local_38 = (byte *)FUN_00812e0e();
      if (local_38 == (byte *)0x0) {
        _free(_Memory);
        return extraout_EAX_01;
      }
      local_40 = _Memory;
    }
    sStackY_84 = 0x812460;
    iVar3 = CompareStringA(param_1,param_2,(PCNZCH)local_40,(int)param_4,(PCNZCH)local_38,
                           (int)param_6);
    if (_Memory == (byte *)0x0) {
      return iVar3;
    }
    _free(_Memory);
    return extraout_EAX_02;
  }
  if (DAT_00b5cb8c != 1) {
    return 0;
  }
  bVar2 = false;
  bVar1 = false;
  local_58[3] = 0;
  if (param_7 == 0) {
    param_7 = DAT_00b5ca74;
  }
  if ((param_4 == (char *)0x0) || (param_6 == (char *)0x0)) {
    if (param_4 == param_6) {
      return 2;
    }
    if (1 < (int)param_6) {
      return 1;
    }
    if (1 < (int)param_4) {
      return 3;
    }
    BVar5 = GetCPInfo(param_7,&local_34);
    if (BVar5 == 0) {
      return 0;
    }
    if (0 < (int)param_4) {
      if (local_34.MaxCharSize < 2) {
        return 3;
      }
      pBVar6 = local_34.LeadByte;
      while( true ) {
        if (local_34.LeadByte[0] == 0) {
          return 3;
        }
        if (pBVar6[1] == 0) break;
        if ((*pBVar6 <= *param_3) && (*param_3 <= pBVar6[1])) {
          return 2;
        }
        pBVar6 = pBVar6 + 2;
        local_34.LeadByte[0] = *pBVar6;
      }
      return 3;
    }
    if (0 < (int)param_6) {
      if (1 < local_34.MaxCharSize) {
        pBVar6 = local_34.LeadByte;
        while ((local_34.LeadByte[0] != 0 && (pBVar6[1] != 0))) {
          if ((*pBVar6 <= *param_5) && (*param_5 <= pBVar6[1])) {
            return 2;
          }
          pBVar6 = pBVar6 + 2;
          local_34.LeadByte[0] = *pBVar6;
        }
      }
      return 1;
    }
  }
  sStackY_84 = 0x81227e;
  iVar3 = MultiByteToWideChar(param_7,9,(LPCSTR)param_3,(int)param_4,(LPWSTR)0x0,0);
  if (iVar3 == 0) {
    return 0;
  }
  puVar7 = (undefined1 *)(iVar3 * 2 + 3U & 0xfffffffc);
  iVar8 = -(int)puVar7;
  local_3c = auStack_5a + iVar8 + -0xe;
  local_1c = auStack_5a + iVar8 + -0xe;
  local_8 = (undefined *)0xffffffff;
  if (auStack_5a + -0xe == puVar7) {
    *(int *)(auStack_5a + iVar8 + -0x12) = iVar3 * 2;
    *(undefined4 *)(auStack_5a + iVar8 + -0x16) = 0x8122d6;
    local_3c = _malloc(*(size_t *)(auStack_5a + iVar8 + -0x12));
    if (local_3c == (void *)0x0) {
      return 0;
    }
    bVar2 = true;
  }
  *(int *)(auStack_5a + iVar8 + -0x12) = iVar3;
  *(undefined1 **)(auStack_5a + iVar8 + -0x16) = local_3c;
  *(char **)(auStack_5a + iVar8 + -0x1a) = param_4;
  *(byte **)(auStack_5a + iVar8 + -0x1e) = param_3;
  *(undefined4 *)(auStack_5a + iVar8 + -0x22) = 1;
  *(UINT *)(auStack_5a + iVar8 + -0x26) = param_7;
  puVar13 = auStack_5a + iVar8 + -0x2a;
  *(undefined4 *)(auStack_5a + iVar8 + -0x2a) = 0x8122fa;
  iVar8 = MultiByteToWideChar(*(UINT *)(auStack_5a + iVar8 + -0x26),
                              *(DWORD *)(auStack_5a + iVar8 + -0x22),
                              *(LPCSTR *)(auStack_5a + iVar8 + -0x1e),
                              *(int *)(auStack_5a + iVar8 + -0x1a),
                              *(LPWSTR *)(auStack_5a + iVar8 + -0x16),
                              *(int *)(auStack_5a + iVar8 + -0x12));
  puVar7 = puVar13;
  if (iVar8 != 0) {
    *(undefined4 *)(puVar13 + -4) = 0;
    *(undefined4 *)(puVar13 + -8) = 0;
    *(char **)(puVar13 + -0xc) = param_6;
    *(byte **)(puVar13 + -0x10) = param_5;
    *(undefined4 *)(puVar13 + -0x14) = 9;
    *(UINT *)(puVar13 + -0x18) = param_7;
    puVar14 = puVar13 + -0x1c;
    *(undefined4 *)(puVar13 + -0x1c) = 0x812317;
    iVar8 = MultiByteToWideChar(*(UINT *)(puVar13 + -0x18),*(DWORD *)(puVar13 + -0x14),
                                *(LPCSTR *)(puVar13 + -0x10),*(int *)(puVar13 + -0xc),
                                *(LPWSTR *)(puVar13 + -8),*(int *)(puVar13 + -4));
    puVar7 = puVar14;
    if (iVar8 != 0) {
      puVar9 = (undefined1 *)(iVar8 * 2 + 3U & 0xfffffffc);
      *(undefined4 *)(puVar14 + -4) = 0x812339;
      iVar11 = -(int)puVar9;
      puVar10 = puVar14 + iVar11;
      puVar7 = puVar14 + iVar11;
      local_1c = puVar14 + iVar11;
      local_8 = (undefined *)0xffffffff;
      if (puVar14 == puVar9) {
        sRamfffffffc = iVar8 * 2;
        uRamfffffff8 = 0x81236c;
        puVar10 = _malloc(sRamfffffffc);
        if (puVar10 == (undefined1 *)0x0) goto LAB_008123b3;
        bVar1 = true;
      }
      *(int *)(puVar14 + iVar11 + -4) = iVar8;
      *(undefined1 **)(puVar14 + iVar11 + -8) = puVar10;
      *(char **)(puVar14 + iVar11 + -0xc) = param_6;
      *(byte **)(puVar14 + iVar11 + -0x10) = param_5;
      *(undefined4 *)(puVar14 + iVar11 + -0x14) = 1;
      *(UINT *)(puVar14 + iVar11 + -0x18) = param_7;
      puVar15 = puVar14 + iVar11 + -0x1c;
      *(undefined4 *)(puVar14 + iVar11 + -0x1c) = 0x81238d;
      iVar11 = MultiByteToWideChar(*(UINT *)(puVar14 + iVar11 + -0x18),
                                   *(DWORD *)(puVar14 + iVar11 + -0x14),
                                   *(LPCSTR *)(puVar14 + iVar11 + -0x10),
                                   *(int *)(puVar14 + iVar11 + -0xc),
                                   *(LPWSTR *)(puVar14 + iVar11 + -8),
                                   *(int *)(puVar14 + iVar11 + -4));
      puVar7 = puVar15;
      if (iVar11 != 0) {
        *(int *)(puVar15 + -4) = iVar8;
        *(undefined1 **)(puVar15 + -8) = puVar10;
        *(int *)(puVar15 + -0xc) = iVar3;
        *(undefined1 **)(puVar15 + -0x10) = local_3c;
        *(DWORD *)(puVar15 + -0x14) = param_2;
        *(LCID *)(puVar15 + -0x18) = param_1;
        puVar7 = puVar15 + -0x1c;
        *(undefined4 *)(puVar15 + -0x1c) = 0x8123a3;
        local_58[3] = CompareStringW(*(LCID *)(puVar15 + -0x18),*(DWORD *)(puVar15 + -0x14),
                                     *(PCNZWCH *)(puVar15 + -0x10),*(int *)(puVar15 + -0xc),
                                     *(PCNZWCH *)(puVar15 + -8),*(int *)(puVar15 + -4));
      }
      if (bVar1) {
        *(undefined1 **)(puVar7 + -4) = puVar10;
        *(undefined4 *)(puVar7 + -8) = 0x8123b2;
        _free(*(void **)(puVar7 + -4));
        return extraout_EAX;
      }
    }
  }
LAB_008123b3:
  if (bVar2) {
    *(undefined1 **)(puVar7 + -4) = local_3c;
    *(undefined4 *)(puVar7 + -8) = 0x8123c1;
    _free(*(void **)(puVar7 + -4));
    return extraout_EAX_00;
  }
  return local_58[3];
}


// ==== FUN_008122ae @ 0x008122ae ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */

undefined4 FUN_008122ae(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x8122b6;
  __resetstkoflw();
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = *(int *)(unaff_EBP + -0x4c);
  uVar7 = *(undefined4 *)(unaff_EBP + -0x3c);
  pvVar2 = *(void **)(unaff_EBP + -0x38);
  if (pvVar2 == (void *)0x0) {
    *(int *)(iVar3 + -4) = iVar1 * 2;
    *(undefined4 *)(iVar3 + -8) = 0x8122d6;
    pvVar2 = _malloc(*(size_t *)(iVar3 + -4));
    *(void **)(unaff_EBP + -0x38) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      uVar7 = 0;
      goto LAB_00812478;
    }
    *(undefined4 *)(unaff_EBP + -0x50) = 1;
  }
  *(int *)(iVar3 + -4) = iVar1;
  *(void **)(iVar3 + -8) = pvVar2;
  *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined4 *)(iVar3 + -0x10) = uVar7;
  *(undefined4 *)(iVar3 + -0x14) = 1;
  *(undefined4 *)(iVar3 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
  puVar8 = (undefined1 *)(iVar3 + -0x1c);
  *(undefined4 *)(iVar3 + -0x1c) = 0x8122fa;
  iVar3 = MultiByteToWideChar(*(UINT *)(iVar3 + -0x18),*(DWORD *)(iVar3 + -0x14),
                              *(LPCSTR *)(iVar3 + -0x10),*(int *)(iVar3 + -0xc),
                              *(LPWSTR *)(iVar3 + -8),*(int *)(iVar3 + -4));
  puVar11 = puVar8;
  if (iVar3 != 0) {
    *(undefined4 *)(puVar8 + -4) = 0;
    *(undefined4 *)(puVar8 + -8) = 0;
    *(undefined4 *)(puVar8 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
    *(undefined4 *)(puVar8 + -0x10) = *(undefined4 *)(unaff_EBP + -0x34);
    *(undefined4 *)(puVar8 + -0x14) = 9;
    *(undefined4 *)(puVar8 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
    puVar9 = puVar8 + -0x1c;
    *(undefined4 *)(puVar8 + -0x1c) = 0x812317;
    iVar3 = MultiByteToWideChar(*(UINT *)(puVar8 + -0x18),*(DWORD *)(puVar8 + -0x14),
                                *(LPCSTR *)(puVar8 + -0x10),*(int *)(puVar8 + -0xc),
                                *(LPWSTR *)(puVar8 + -8),*(int *)(puVar8 + -4));
    *(int *)(unaff_EBP + -0x54) = iVar3;
    puVar11 = puVar9;
    if (iVar3 != 0) {
      *(undefined4 *)(unaff_EBP + -4) = 1;
      puVar4 = (undefined1 *)(iVar3 * 2 + 3U & 0xfffffffc);
      *(undefined4 *)(puVar9 + -4) = 0x812339;
      iVar6 = -(int)puVar4;
      puVar5 = puVar9 + iVar6;
      puVar11 = puVar9 + iVar6;
      *(int *)(unaff_EBP + -0x18) = (int)puVar9 + iVar6;
      *(int *)(unaff_EBP + -0x58) = (int)puVar9 + iVar6;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (puVar9 == puVar4) {
        sRamfffffffc = iVar3 * 2;
        uRamfffffff8 = 0x81236c;
        puVar5 = _malloc(sRamfffffffc);
        if (puVar5 == (undefined1 *)0x0) goto LAB_008123b3;
        *(undefined4 *)(unaff_EBP + -0x44) = 1;
      }
      *(int *)(puVar9 + iVar6 + -4) = iVar3;
      *(undefined1 **)(puVar9 + iVar6 + -8) = puVar5;
      *(undefined4 *)(puVar9 + iVar6 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
      *(undefined4 *)(puVar9 + iVar6 + -0x10) = *(undefined4 *)(unaff_EBP + -0x34);
      *(undefined4 *)(puVar9 + iVar6 + -0x14) = 1;
      *(undefined4 *)(puVar9 + iVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
      puVar10 = puVar9 + iVar6 + -0x1c;
      *(undefined4 *)(puVar9 + iVar6 + -0x1c) = 0x81238d;
      iVar6 = MultiByteToWideChar(*(UINT *)(puVar9 + iVar6 + -0x18),
                                  *(DWORD *)(puVar9 + iVar6 + -0x14),
                                  *(LPCSTR *)(puVar9 + iVar6 + -0x10),
                                  *(int *)(puVar9 + iVar6 + -0xc),*(LPWSTR *)(puVar9 + iVar6 + -8),
                                  *(int *)(puVar9 + iVar6 + -4));
      puVar11 = puVar10;
      if (iVar6 != 0) {
        *(int *)(puVar10 + -4) = iVar3;
        *(undefined1 **)(puVar10 + -8) = puVar5;
        *(int *)(puVar10 + -0xc) = iVar1;
        *(undefined4 *)(puVar10 + -0x10) = *(undefined4 *)(unaff_EBP + -0x38);
        *(undefined4 *)(puVar10 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(puVar10 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
        puVar11 = puVar10 + -0x1c;
        *(undefined4 *)(puVar10 + -0x1c) = 0x8123a3;
        iVar3 = CompareStringW(*(LCID *)(puVar10 + -0x18),*(DWORD *)(puVar10 + -0x14),
                               *(PCNZWCH *)(puVar10 + -0x10),*(int *)(puVar10 + -0xc),
                               *(PCNZWCH *)(puVar10 + -8),*(int *)(puVar10 + -4));
        *(int *)(unaff_EBP + -0x48) = iVar3;
      }
      if (*(int *)(unaff_EBP + -0x44) != 0) {
        *(undefined1 **)(puVar11 + -4) = puVar5;
        *(undefined4 *)(puVar11 + -8) = 0x8123b2;
        _free(*(void **)(puVar11 + -4));
        return extraout_EAX;
      }
    }
  }
LAB_008123b3:
  if (*(int *)(unaff_EBP + -0x50) != 0) {
    *(undefined4 *)(puVar11 + -4) = *(undefined4 *)(unaff_EBP + -0x38);
    *(undefined4 *)(puVar11 + -8) = 0x8123c1;
    _free(*(void **)(puVar11 + -4));
    return extraout_EAX_00;
  }
  uVar7 = *(undefined4 *)(unaff_EBP + -0x48);
LAB_00812478:
  *(undefined4 *)(unaff_EBP + -0x68) = 0x812485;
  *(undefined4 *)(unaff_EBP + -0x6c) = 0x81248a;
  return uVar7;
}


// ==== FUN_0081234b @ 0x0081234b ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_0081234b(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int unaff_EBP;
  
  puVar6 = *(undefined1 **)(unaff_EBP + -0x18);
  *(undefined4 *)(puVar6 + -4) = 0x812353;
  __resetstkoflw();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x4c);
  iVar4 = *(int *)(unaff_EBP + -0x54);
  *(int *)(puVar6 + -4) = iVar4 * 2;
  *(undefined4 *)(puVar6 + -8) = 0x81236c;
  pvVar2 = _malloc(*(size_t *)(puVar6 + -4));
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x44) = 1;
    *(int *)(puVar6 + -4) = iVar4;
    *(void **)(puVar6 + -8) = pvVar2;
    *(undefined4 *)(puVar6 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
    *(undefined4 *)(puVar6 + -0x10) = *(undefined4 *)(unaff_EBP + -0x34);
    *(undefined4 *)(puVar6 + -0x14) = 1;
    *(undefined4 *)(puVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
    puVar5 = puVar6 + -0x1c;
    *(undefined4 *)(puVar6 + -0x1c) = 0x81238d;
    iVar3 = MultiByteToWideChar(*(UINT *)(puVar6 + -0x18),*(DWORD *)(puVar6 + -0x14),
                                *(LPCSTR *)(puVar6 + -0x10),*(int *)(puVar6 + -0xc),
                                *(LPWSTR *)(puVar6 + -8),*(int *)(puVar6 + -4));
    puVar6 = puVar5;
    if (iVar3 != 0) {
      *(int *)(puVar5 + -4) = iVar4;
      *(void **)(puVar5 + -8) = pvVar2;
      *(undefined4 *)(puVar5 + -0xc) = uVar1;
      *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + -0x38);
      *(undefined4 *)(puVar5 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
      *(undefined4 *)(puVar5 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
      puVar6 = puVar5 + -0x1c;
      *(undefined4 *)(puVar5 + -0x1c) = 0x8123a3;
      iVar4 = CompareStringW(*(LCID *)(puVar5 + -0x18),*(DWORD *)(puVar5 + -0x14),
                             *(PCNZWCH *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                             *(PCNZWCH *)(puVar5 + -8),*(int *)(puVar5 + -4));
      *(int *)(unaff_EBP + -0x48) = iVar4;
    }
    if (*(int *)(unaff_EBP + -0x44) != 0) {
      *(void **)(puVar6 + -4) = pvVar2;
      *(undefined4 *)(puVar6 + -8) = 0x8123b2;
      _free(*(void **)(puVar6 + -4));
      return extraout_EAX;
    }
  }
  if (*(int *)(unaff_EBP + -0x50) == 0) {
    *(undefined4 *)(unaff_EBP + -0x68) = 0x812485;
    *(undefined4 *)(unaff_EBP + -0x6c) = 0x81248a;
    return *(undefined4 *)(unaff_EBP + -0x48);
  }
  *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(unaff_EBP + -0x38);
  *(undefined4 *)(puVar6 + -8) = 0x8123c1;
  _free(*(void **)(puVar6 + -4));
  return extraout_EAX_00;
}


// ==== ___crtInitCritSecNoSpinCount@8 @ 0x0081248c ====

/* Library Function - Single Match
    ___crtInitCritSecNoSpinCount@8
   
   Library: Visual Studio 2003 Release */

undefined4 ___crtInitCritSecNoSpinCount_8(LPCRITICAL_SECTION param_1)

{
  InitializeCriticalSection(param_1);
  return 1;
}


// ==== ___crtInitCritSecAndSpinCount @ 0x0081249c ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___crtInitCritSecAndSpinCount
   
   Library: Visual Studio 2003 Release */

void ___crtInitCritSecAndSpinCount(undefined4 param_1,undefined4 param_2)

{
  HMODULE hModule;
  
  if (DAT_00b5cb90 == (code *)0x0) {
    if (DAT_00b5c720 != 1) {
      hModule = GetModuleHandleA(s_kernel32_dll_00a061f4);
      if (hModule != (HMODULE)0x0) {
        DAT_00b5cb90 = GetProcAddress(hModule,s_InitializeCriticalSectionAndSpin_00a0bb80);
        if (DAT_00b5cb90 != (FARPROC)0x0) goto LAB_008124e8;
      }
    }
    DAT_00b5cb90 = ___crtInitCritSecNoSpinCount_8;
  }
LAB_008124e8:
  (*DAT_00b5cb90)(param_1,param_2);
  return;
}


// ==== FUN_00812507 @ 0x00812507 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00812507(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int unaff_EBP;
  
  puVar1 = *(undefined1 **)(unaff_EBP + -0x18);
  puVar2 = puVar1;
  if (*(int *)(unaff_EBP + -0x1c) == -0x3fffffe9) {
    *(undefined4 *)(puVar1 + -4) = 8;
    puVar2 = puVar1 + -8;
    *(undefined4 *)(puVar1 + -8) = 0x81251b;
    SetLastError(*(DWORD *)(puVar1 + -4));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(puVar2 + -4) = 0x812526;
  return 0;
}


// ==== _ValidateRead @ 0x00812527 ====

/* Library Function - Single Match
    int __cdecl _ValidateRead(void const *,unsigned int)
   
   Library: Visual Studio 2003 Release */

int __cdecl _ValidateRead(void *param_1,uint param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return (uint)(BVar1 == 0);
}


// ==== _ValidateWrite @ 0x00812543 ====

/* Library Function - Multiple Matches With Different Base Names
    int __cdecl _ValidateRead(void const *,unsigned int)
    int __cdecl _ValidateWrite(void *,unsigned int)
   
   Library: Visual Studio 2003 Release */

int __cdecl _ValidateWrite(void *param_1,uint param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return (uint)(BVar1 == 0);
}


// ==== _ValidateExecute @ 0x0081255f ====

/* Library Function - Single Match
    int __cdecl _ValidateExecute(int (__stdcall*)(void))
   
   Library: Visual Studio 2003 Release */

int __cdecl _ValidateExecute(_func_int *param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr((FARPROC)param_1);
  return (uint)(BVar1 == 0);
}


// ==== FUN_00812577 @ 0x00812577 ====

undefined4 FUN_00812577(void)

{
  int in_EAX;
  
  if (in_EAX == 0x3a4) {
    return 0x411;
  }
  if (in_EAX == 0x3a8) {
    return 0x804;
  }
  if (in_EAX == 0x3b5) {
    return 0x412;
  }
  if (in_EAX == 0x3b6) {
    return 0x404;
  }
  return 0;
}


// ==== setSBCS @ 0x008125a6 ====

/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 2003 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00b60d20;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00b60e24 = 0;
  DAT_00b60d08 = 0;
  DAT_00b60d00 = 0;
  DAT_00b60e30 = 0;
  DAT_00b60e34 = 0;
  DAT_00b60e38 = 0;
  return;
}


// ==== FUN_008125cf @ 0x008125cf ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008125cf(void)

{
  byte *pbVar1;
  BOOL BVar2;
  uint uVar3;
  undefined1 uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  BYTE *pBVar8;
  undefined4 *puVar9;
  _cpinfo local_51c;
  ushort local_508 [54];
  undefined1 local_49c [404];
  undefined1 local_308 [256];
  undefined1 local_208 [256];
  undefined4 local_108 [64];
  uint local_8;
  
  local_8 = DAT_00b49670 ^ (uint)local_49c;
  BVar2 = GetCPInfo(DAT_00b60e24,&local_51c);
  if (BVar2 == 1) {
    uVar3 = 0;
    do {
      *(char *)((int)local_108 + uVar3) = (char)uVar3;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
    local_108[0]._0_1_ = 0x20;
    if (local_51c.LeadByte[0] != 0) {
      pBVar8 = local_51c.LeadByte + 1;
      do {
        uVar3 = (uint)local_51c.LeadByte[0];
        if (uVar3 <= *pBVar8) {
          uVar6 = (*pBVar8 - uVar3) + 1;
          puVar9 = (undefined4 *)((int)local_108 + uVar3);
          for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *puVar9 = 0x20202020;
            puVar9 = puVar9 + 1;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined1 *)puVar9 = 0x20;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
        }
        local_51c.LeadByte[0] = pBVar8[1];
        pBVar8 = pBVar8 + 2;
      } while (local_51c.LeadByte[0] != 0);
    }
    FUN_00809c38(1,local_108,0x100,local_508,DAT_00b60e24,DAT_00b60d00,0);
    FUN_0080cc3e(DAT_00b60d00,0x100,local_108,0x100,local_208,0x100,DAT_00b60e24,0);
    FUN_0080cc3e(DAT_00b60d00,0x200,local_108,0x100,local_308,0x100,DAT_00b60e24,0);
    uVar3 = 0;
    do {
      if ((local_508[uVar3] & 1) == 0) {
        if ((local_508[uVar3] & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_00b60d20 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar4 = local_308[uVar3];
          goto LAB_008126e5;
        }
        (&DAT_00b60e40)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_00b60d20 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar4 = local_208[uVar3];
LAB_008126e5:
        (&DAT_00b60e40)[uVar3] = uVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  else {
    uVar3 = 0;
    do {
      if ((uVar3 < 0x41) || (0x5a < uVar3)) {
        if ((0x60 < uVar3) && (uVar3 < 0x7b)) {
          pbVar1 = (byte *)((int)&DAT_00b60d20 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar5 = (char)uVar3 + -0x20;
          goto LAB_00812728;
        }
        (&DAT_00b60e40)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_00b60d20 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar5 = (char)uVar3 + ' ';
LAB_00812728:
        (&DAT_00b60e40)[uVar3] = cVar5;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}


// ==== FUN_0081276a @ 0x0081276a ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

int * FUN_0081276a(void)

{
  _ptiddata p_Var1;
  int *extraout_EAX;
  int *_Memory;
  
  __lock(0xd);
  p_Var1 = __getptd();
  _Memory = p_Var1->_tpxcptinfoptrs;
  if (_Memory != DAT_00b60d04) {
    if ((_Memory != (int *)0x0) && (*_Memory = *_Memory + -1, *_Memory == 0)) {
      _free(_Memory);
      return extraout_EAX;
    }
    p_Var1->_tpxcptinfoptrs = DAT_00b60d04;
    _Memory = DAT_00b60d04;
    *DAT_00b60d04 = *DAT_00b60d04 + 1;
  }
  FUN_008127d0();
  return _Memory;
}


// ==== FUN_008127cd @ 0x008127cd ====

void FUN_008127cd(void)

{
  FUN_00806c2f(0xd);
  return;
}


// ==== FUN_008127d0 @ 0x008127d0 ====

void FUN_008127d0(void)

{
  FUN_00806c2f(0xd);
  return;
}


// ==== FUN_008127d9 @ 0x008127d9 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008127d9(UINT param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  BOOL BVar6;
  BYTE *pBVar7;
  int iVar8;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  uint local_20;
  _cpinfo local_1c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)(&local_1c)[1].DefaultChar;
  if (param_1 != 0) {
    iVar9 = 0;
    uVar5 = 0;
    do {
      if (*(UINT *)((int)&DAT_00b4a2f8 + uVar5) == param_1) {
        puVar12 = &DAT_00b60d20;
        for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar12 = 0;
          puVar12 = puVar12 + 1;
        }
        local_20 = 0;
        *(undefined1 *)puVar12 = 0;
        pbVar10 = (byte *)(iVar9 * 0x30 + 0xb4a308);
        do {
          bVar4 = *pbVar10;
          pbVar11 = pbVar10;
          while ((bVar4 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
            uVar5 = (uint)bVar4;
            if (uVar5 <= bVar3) {
              bVar4 = (&DAT_00b4a2f0)[local_20];
              do {
                pbVar2 = (byte *)((int)&DAT_00b60d20 + uVar5 + 1);
                *pbVar2 = *pbVar2 | bVar4;
                uVar5 = uVar5 + 1;
              } while (uVar5 <= bVar3);
            }
            pbVar11 = pbVar11 + 2;
            bVar4 = *pbVar11;
          }
          local_20 = local_20 + 1;
          pbVar10 = pbVar10 + 8;
        } while (local_20 < 4);
        DAT_00b60e24 = param_1;
        DAT_00b60d08 = 1;
        DAT_00b60d00 = FUN_00812577();
        DAT_00b60e30 = *(undefined4 *)(&DAT_00b4a2fc + extraout_ECX);
        DAT_00b60e34 = *(undefined4 *)(&DAT_00b4a300 + extraout_ECX);
        DAT_00b60e38 = *(undefined4 *)(&DAT_00b4a304 + extraout_ECX);
        goto LAB_00812952;
      }
      uVar5 = uVar5 + 0x30;
      iVar9 = iVar9 + 1;
    } while (uVar5 < 0xf0);
    BVar6 = GetCPInfo(param_1,&local_1c);
    if (BVar6 == 1) {
      puVar12 = &DAT_00b60d20;
      for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
      }
      *(undefined1 *)puVar12 = 0;
      DAT_00b60e24 = param_1;
      DAT_00b60d00 = 0;
      if (local_1c.MaxCharSize < 2) {
        DAT_00b60d08 = 0;
      }
      else {
        if (local_1c.LeadByte[0] != '\0') {
          pBVar7 = local_1c.LeadByte + 1;
          do {
            bVar4 = *pBVar7;
            if (bVar4 == 0) break;
            for (uVar5 = (uint)pBVar7[-1]; uVar5 <= bVar4; uVar5 = uVar5 + 1) {
              pbVar10 = (byte *)((int)&DAT_00b60d20 + uVar5 + 1);
              *pbVar10 = *pbVar10 | 4;
            }
            pBVar1 = pBVar7 + 1;
            pBVar7 = pBVar7 + 2;
          } while (*pBVar1 != 0);
        }
        uVar5 = 1;
        do {
          pbVar10 = (byte *)((int)&DAT_00b60d20 + uVar5 + 1);
          *pbVar10 = *pbVar10 | 8;
          uVar5 = uVar5 + 1;
        } while (uVar5 < 0xff);
        DAT_00b60d00 = FUN_00812577();
        DAT_00b60d08 = extraout_ECX_00;
      }
      DAT_00b60e30 = 0;
      DAT_00b60e34 = 0;
      DAT_00b60e38 = 0;
      goto LAB_00812952;
    }
    if (DAT_00b5cb94 == 0) {
      return 0xffffffff;
    }
  }
  setSBCS();
LAB_00812952:
  FUN_008125cf();
  return 0;
}


// ==== FUN_0081296d @ 0x0081296d ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

int FUN_0081296d(UINT param_1)

{
  int *_Memory;
  int iVar1;
  int extraout_EAX;
  int local_24;
  
  local_24 = -1;
  __lock(0xd);
  DAT_00b5cb94 = 0;
  if (param_1 == 0xfffffffe) {
    DAT_00b5cb94 = 1;
    param_1 = GetOEMCP();
  }
  else if (param_1 == 0xfffffffd) {
    DAT_00b5cb94 = 1;
    param_1 = GetACP();
  }
  else if (param_1 == 0xfffffffc) {
    DAT_00b5cb94 = 1;
    param_1 = DAT_00b5ca74;
  }
  if (param_1 == DAT_00b60e24) {
    local_24 = 0;
  }
  else {
    if ((DAT_00b60d04 == (int *)0x0) || (_Memory = DAT_00b60d04, *DAT_00b60d04 != 0)) {
      _Memory = _malloc(0x220);
    }
    if (_Memory != (int *)0x0) {
      local_24 = FUN_008127d9(param_1);
      if (local_24 == 0) {
        *_Memory = 0;
        _Memory[1] = DAT_00b60e24;
        _Memory[2] = DAT_00b60d08;
        _Memory[3] = DAT_00b60d00;
        for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
          *(undefined2 *)((int)_Memory + iVar1 * 2 + 0x10) =
               *(undefined2 *)((int)&DAT_00b60e30 + iVar1 * 2);
        }
        for (iVar1 = 0; iVar1 < 0x101; iVar1 = iVar1 + 1) {
          *(undefined1 *)(iVar1 + 0x1c + (int)_Memory) = *(undefined1 *)((int)&DAT_00b60d20 + iVar1)
          ;
        }
        for (iVar1 = 0; iVar1 < 0x100; iVar1 = iVar1 + 1) {
          *(undefined1 *)(iVar1 + 0x11d + (int)_Memory) = (&DAT_00b60e40)[iVar1];
        }
        DAT_00b60d04 = _Memory;
      }
    }
    if ((local_24 == -1) && (_Memory != DAT_00b60d04)) {
      _free(_Memory);
      return extraout_EAX;
    }
  }
  FUN_00812ab4();
  return local_24;
}


// ==== FUN_00812ab4 @ 0x00812ab4 ====

void FUN_00812ab4(void)

{
  FUN_00806c2f(0xd);
  return;
}


// ==== ___initmbctable @ 0x00812abd ====

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 2003 Release */

undefined4 ___initmbctable(void)

{
  if (DAT_00b610ac == 0) {
    FUN_0081296d(0xfffffffd);
    DAT_00b610ac = 1;
  }
  return 0;
}


// ==== ___crtMessageBoxA @ 0x00812adb ====

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 2003 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  int iVar2;
  undefined1 local_14 [8];
  byte local_c;
  undefined1 local_8 [4];
  
  iVar2 = 0;
  if (DAT_00b5cb98 == (FARPROC)0x0) {
    hModule = LoadLibraryA(s_user32_dll_00a0bc38);
    if ((hModule == (HMODULE)0x0) ||
       (DAT_00b5cb98 = GetProcAddress(hModule,s_MessageBoxA_00a0bc2c), DAT_00b5cb98 == (FARPROC)0x0)
       ) {
      return 0;
    }
    DAT_00b5cb9c = GetProcAddress(hModule,s_GetActiveWindow_00a0bc1c);
    DAT_00b5cba0 = GetProcAddress(hModule,s_GetLastActivePopup_00a0bc08);
    if ((DAT_00b5c720 == 2) &&
       (DAT_00b5cba8 = GetProcAddress(hModule,s_GetUserObjectInformationA_00a0bbec),
       DAT_00b5cba8 != (FARPROC)0x0)) {
      DAT_00b5cba4 = GetProcAddress(hModule,s_GetProcessWindowStation_00a0bbd4);
    }
  }
  if ((DAT_00b5cba4 == (FARPROC)0x0) ||
     (((iVar1 = (*DAT_00b5cba4)(), iVar1 != 0 &&
       (iVar1 = (*DAT_00b5cba8)(iVar1,1,local_14,0xc,local_8), iVar1 != 0)) && ((local_c & 1) != 0))
     )) {
    if (((DAT_00b5cb9c != (FARPROC)0x0) && (iVar2 = (*DAT_00b5cb9c)(), iVar2 != 0)) &&
       (DAT_00b5cba0 != (FARPROC)0x0)) {
      iVar2 = (*DAT_00b5cba0)(iVar2);
    }
  }
  else if (DAT_00b5c72c < 4) {
    _UType = _UType | 0x40000;
  }
  else {
    _UType = _UType | 0x200000;
  }
  iVar2 = (*DAT_00b5cb98)(iVar2,_LpText,_LpCaption,_UType);
  return iVar2;
}


// ==== x_ismbbtype @ 0x00812bd4 ====

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 2003 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  if ((*(byte *)((int)&DAT_00b60d20 + param_1 + 1) & param_3) == 0) {
    if (param_2 == 0) {
      param_2 = 0;
    }
    else {
      param_2 = *(ushort *)(PTR_DAT_00b49d38 + (uint)param_1 * 2) & param_2;
    }
    if (param_2 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== __ismbblead @ 0x00812c07 ====

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 2003 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype(_C,0,4);
  return iVar1;
}


// ==== FUN_00812c18 @ 0x00812c18 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00812c18(int param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  byte bVar1;
  bool bVar2;
  size_t sVar3;
  DWORD DVar4;
  char *_Source;
  char *_Dest;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int iVar5;
  byte *pbVar6;
  char local_88 [28];
  undefined1 local_6c [100];
  uint local_8;
  
  local_8 = DAT_00b49670 ^ (uint)local_6c;
  if (param_1 == 1) {
    _Source = local_88;
    bVar2 = false;
    sVar3 = FUN_00814d76(param_2,param_3,_Source,0x80,0);
    if (sVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 != 0x7a) {
        return 0xffffffff;
      }
      sVar3 = FUN_00814d76(param_2,param_3,0,0,0);
      if (sVar3 == 0) {
        return 0xffffffff;
      }
      _Source = _malloc(sVar3);
      if (_Source == (char *)0x0) {
        return 0xffffffff;
      }
      bVar2 = true;
      sVar3 = FUN_00814d76(param_2,param_3,_Source,sVar3,0);
      if (sVar3 == 0) goto LAB_00812cc7;
    }
    _Dest = _malloc(sVar3);
    *(char **)param_4 = _Dest;
    if (_Dest != (char *)0x0) {
      _strncpy(_Dest,_Source,sVar3);
      if (bVar2) {
        _free(_Source);
        return extraout_EAX_00;
      }
      return 0;
    }
    if (bVar2) {
LAB_00812cc7:
      _free(_Source);
      return extraout_EAX;
    }
  }
  else if (param_1 == 0) {
    pbVar6 = &DAT_00b5cbac;
    iVar5 = FUN_00814c46(param_2,param_3,&DAT_00b5cbac,4,0);
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    *param_4 = '\0';
    do {
      bVar1 = *pbVar6;
      iVar5 = _isdigit((uint)bVar1);
      if (iVar5 == 0) {
        return 0;
      }
      pbVar6 = pbVar6 + 2;
      *param_4 = *param_4 * '\n' + bVar1 + -0x30;
    } while ((int)pbVar6 < 0xb5cbb4);
    return 0;
  }
  return 0xffffffff;
}


// ==== __strnicmp @ 0x00812d48 ====

/* Library Function - Single Match
    __strnicmp
   
   Library: Visual Studio 2003 Release */

int __cdecl __strnicmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  int iVar4;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  if (_MaxCount == 0) {
    iVar3 = 0;
  }
  else if (ptVar2->lc_category[0].wlocale == (wchar_t *)0x0) {
    iVar3 = ___ascii_strnicmp(_Str1,_Str2,_MaxCount);
  }
  else {
    do {
      iVar3 = ___tolower_mt(ptVar2,*_Str1);
      _Str1 = _Str1 + 1;
      iVar4 = ___tolower_mt(ptVar2,*_Str2);
      _Str2 = _Str2 + 1;
      _MaxCount = _MaxCount - 1;
      if ((_MaxCount == 0) || (iVar3 == 0)) break;
    } while (iVar3 == iVar4);
    iVar3 = iVar3 - iVar4;
  }
  return iVar3;
}


// ==== FUN_00812dc7 @ 0x00812dc7 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long FUN_00812dc7(LCID param_1)

{
  int iVar1;
  long lVar2;
  CHAR local_10 [6];
  undefined1 local_a;
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)(local_10 + 0xc);
  local_a = 0;
  iVar1 = GetLocaleInfoA(param_1,0x1004,local_10,6);
  if (iVar1 == 0) {
    lVar2 = -1;
  }
  else {
    lVar2 = _atol(local_10);
  }
  return lVar2;
}


// ==== FUN_00812e0e @ 0x00812e0e ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

LPSTR FUN_00812e0e(UINT param_1,UINT param_2,char *param_3,int *param_4,LPSTR param_5,int param_6)

{
  bool bVar1;
  bool bVar2;
  BOOL BVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  LPSTR extraout_EAX;
  LPSTR extraout_EAX_00;
  undefined1 uStack00000000;
  undefined4 local_58;
  int local_40;
  LPSTR local_38;
  _cpinfo local_34;
  uint local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_8 = &DAT_00a0bc48;
  uStack_c = 0x812e1a;
  local_20 = DAT_00b49670 ^ (int)register0x00000010 - 4U;
  local_38 = (LPSTR)0x0;
  bVar2 = false;
  iVar6 = *param_4;
  bVar1 = false;
  if (param_1 != param_2) {
    BVar3 = GetCPInfo(param_1,&local_34);
    if ((((BVar3 != 0) && (local_34.MaxCharSize == 1)) &&
        (BVar3 = GetCPInfo(param_2,&local_34), BVar3 != 0)) && (local_34.MaxCharSize == 1)) {
      bVar1 = true;
    }
    if (bVar1) {
      if (iVar6 == -1) {
        sVar4 = _strlen(param_3);
        local_40 = sVar4 + 1;
      }
      else {
        local_40 = iVar6;
      }
    }
    if ((!bVar1) &&
       (local_40 = MultiByteToWideChar(param_1,1,param_3,iVar6,(LPWSTR)0x0,0), local_40 == 0)) {
      return (LPSTR)0x0;
    }
    local_8 = (undefined *)0x0;
    local_1c = (undefined1 *)((int)register0x00000010 + -100);
    local_58 = (LPWSTR)((int)register0x00000010 + -100);
    _memset((void *)((int)register0x00000010 + -100),0,local_40 * 2);
    local_8 = (undefined *)0xffffffff;
    if (&uStack00000000 == (undefined1 *)0x64) {
      local_58 = (LPWSTR)FUN_0080faf9(2,local_40);
      if (local_58 == (LPWSTR)0x0) {
        return (LPSTR)0x0;
      }
      bVar2 = true;
    }
    iVar5 = MultiByteToWideChar(param_1,1,param_3,iVar6,local_58,local_40);
    if (iVar5 != 0) {
      if (param_5 == (LPSTR)0x0) {
        if (((bVar1) ||
            (local_40 = WideCharToMultiByte(param_2,0,local_58,local_40,(LPSTR)0x0,0,(LPCSTR)0x0,
                                            (LPBOOL)0x0), local_40 != 0)) &&
           (local_38 = (LPSTR)FUN_0080faf9(1,local_40), local_38 != (LPSTR)0x0)) {
          iVar5 = WideCharToMultiByte(param_2,0,local_58,local_40,local_38,local_40,(LPCSTR)0x0,
                                      (LPBOOL)0x0);
          if (iVar5 == 0) {
            _free(local_38);
            return extraout_EAX;
          }
          if (iVar6 != -1) {
            *param_4 = iVar5;
          }
        }
      }
      else {
        iVar6 = WideCharToMultiByte(param_2,0,local_58,local_40,param_5,param_6,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        if (iVar6 != 0) {
          local_38 = param_5;
        }
      }
    }
  }
  if (!bVar2) {
    return local_38;
  }
  _free(local_58);
  return extraout_EAX_00;
}


// ==== FUN_00812ef3 @ 0x00812ef3 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00812ef3(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x812efb;
  __resetstkoflw();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar4 = *(int *)(unaff_EBP + -0x3c);
  *(int *)(iVar3 + -4) = iVar4;
  *(undefined4 *)(iVar3 + -8) = 2;
  *(undefined4 *)(iVar3 + -0xc) = 0x812f12;
  iVar1 = FUN_0080faf9();
  if (iVar1 == 0) {
    uVar2 = 0;
    goto LAB_00812fd5;
  }
  *(undefined4 *)(unaff_EBP + -0x4c) = 1;
  *(int *)(iVar3 + -4) = iVar4;
  *(int *)(iVar3 + -8) = iVar1;
  *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(unaff_EBP + -0x48);
  *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + -0x44);
  *(undefined4 *)(iVar3 + -0x14) = 1;
  *(undefined4 *)(iVar3 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  puVar5 = (undefined1 *)(iVar3 + -0x1c);
  *(undefined4 *)(iVar3 + -0x1c) = 0x812f3b;
  iVar3 = MultiByteToWideChar(*(UINT *)(iVar3 + -0x18),*(DWORD *)(iVar3 + -0x14),
                              *(LPCSTR *)(iVar3 + -0x10),*(int *)(iVar3 + -0xc),
                              *(LPWSTR *)(iVar3 + -8),*(int *)(iVar3 + -4));
  puVar8 = puVar5;
  if (iVar3 != 0) {
    if (*(int *)(unaff_EBP + -0x40) == 0) {
      puVar7 = puVar5;
      if (*(int *)(unaff_EBP + -0x38) == 0) {
        *(undefined4 *)(puVar5 + -4) = 0;
        *(undefined4 *)(puVar5 + -8) = 0;
        *(undefined4 *)(puVar5 + -0xc) = 0;
        *(undefined4 *)(puVar5 + -0x10) = 0;
        *(int *)(puVar5 + -0x14) = iVar4;
        *(int *)(puVar5 + -0x18) = iVar1;
        *(undefined4 *)(puVar5 + -0x1c) = 0;
        *(undefined4 *)(puVar5 + -0x20) = *(undefined4 *)(unaff_EBP + 0xc);
        puVar7 = puVar5 + -0x24;
        *(undefined4 *)(puVar5 + -0x24) = 0x812f7d;
        iVar4 = WideCharToMultiByte(*(UINT *)(puVar5 + -0x20),*(DWORD *)(puVar5 + -0x1c),
                                    *(LPCWSTR *)(puVar5 + -0x18),*(int *)(puVar5 + -0x14),
                                    *(LPSTR *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                                    *(LPCSTR *)(puVar5 + -8),*(LPBOOL *)(puVar5 + -4));
        puVar8 = puVar7;
        if (iVar4 == 0) goto LAB_00812fc6;
      }
      *(int *)(puVar7 + -4) = iVar4;
      *(undefined4 *)(puVar7 + -8) = 1;
      *(undefined4 *)(puVar7 + -0xc) = 0x812f8b;
      iVar3 = FUN_0080faf9();
      *(int *)(unaff_EBP + -0x34) = iVar3;
      puVar8 = puVar7;
      if (iVar3 != 0) {
        *(undefined4 *)(puVar7 + -4) = 0;
        *(undefined4 *)(puVar7 + -8) = 0;
        *(int *)(puVar7 + -0xc) = iVar4;
        *(int *)(puVar7 + -0x10) = iVar3;
        *(int *)(puVar7 + -0x14) = iVar4;
        *(int *)(puVar7 + -0x18) = iVar1;
        *(undefined4 *)(puVar7 + -0x1c) = 0;
        *(undefined4 *)(puVar7 + -0x20) = *(undefined4 *)(unaff_EBP + 0xc);
        puVar8 = puVar7 + -0x24;
        *(undefined4 *)(puVar7 + -0x24) = 0x812fa4;
        iVar3 = WideCharToMultiByte(*(UINT *)(puVar7 + -0x20),*(DWORD *)(puVar7 + -0x1c),
                                    *(LPCWSTR *)(puVar7 + -0x18),*(int *)(puVar7 + -0x14),
                                    *(LPSTR *)(puVar7 + -0x10),*(int *)(puVar7 + -0xc),
                                    *(LPCSTR *)(puVar7 + -8),*(LPBOOL *)(puVar7 + -4));
        if (iVar3 == 0) {
          *(undefined4 *)(puVar8 + -4) = *(undefined4 *)(unaff_EBP + -0x34);
          *(undefined4 *)(puVar8 + -8) = 0x812fb0;
          _free(*(void **)(puVar8 + -4));
          return extraout_EAX;
        }
        if (*(int *)(unaff_EBP + -0x48) != -1) {
          **(int **)(unaff_EBP + -0x50) = iVar3;
        }
      }
    }
    else {
      *(undefined4 *)(puVar5 + -4) = 0;
      *(undefined4 *)(puVar5 + -8) = 0;
      *(undefined4 *)(puVar5 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
      *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + -0x40);
      *(int *)(puVar5 + -0x14) = iVar4;
      *(int *)(puVar5 + -0x18) = iVar1;
      *(undefined4 *)(puVar5 + -0x1c) = 0;
      *(undefined4 *)(puVar5 + -0x20) = *(undefined4 *)(unaff_EBP + 0xc);
      puVar6 = puVar5 + -0x24;
      *(undefined4 *)(puVar5 + -0x24) = 0x812f5c;
      iVar3 = WideCharToMultiByte(*(UINT *)(puVar5 + -0x20),*(DWORD *)(puVar5 + -0x1c),
                                  *(LPCWSTR *)(puVar5 + -0x18),*(int *)(puVar5 + -0x14),
                                  *(LPSTR *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                                  *(LPCSTR *)(puVar5 + -8),*(LPBOOL *)(puVar5 + -4));
      puVar8 = puVar6;
      if (iVar3 != 0) {
        *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x40);
      }
    }
  }
LAB_00812fc6:
  if (*(int *)(unaff_EBP + -0x4c) != 0) {
    *(int *)(puVar8 + -4) = iVar1;
    *(undefined4 *)(puVar8 + -8) = 0x812fd1;
    _free(*(void **)(puVar8 + -4));
    return extraout_EAX_00;
  }
  uVar2 = *(undefined4 *)(unaff_EBP + -0x34);
LAB_00812fd5:
  *(undefined4 *)(unaff_EBP + -100) = 0x812fe2;
  *(undefined4 *)(unaff_EBP + -0x68) = 0x812fe7;
  return uVar2;
}


// ==== FUN_00812fe8 @ 0x00812fe8 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

BOOL FUN_00812fe8(DWORD param_1,LPCWSTR param_2,int param_3,LPWORD param_4,UINT param_5,int param_6)

{
  short *psVar1;
  bool bVar2;
  bool bVar3;
  BOOL BVar4;
  DWORD DVar5;
  UINT UVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined1 *puVar10;
  BOOL extraout_EAX;
  BOOL extraout_EAX_00;
  undefined1 *puVar11;
  undefined4 uStackY_68;
  undefined4 local_38;
  size_t local_34 [3];
  undefined1 *local_28;
  undefined1 *local_24;
  WORD local_20 [2];
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00a0bc58;
  uStack_c = 0x812ff4;
  if (DAT_00b5cbb4 == 0) {
    BVar4 = GetStringTypeW(1,(LPCWSTR)&DAT_0099cdc8,1,local_20);
    if (BVar4 == 0) {
      DVar5 = GetLastError();
      if (DVar5 == 0x78) {
        DAT_00b5cbb4 = 2;
      }
    }
    else {
      DAT_00b5cbb4 = 1;
    }
  }
  if (DAT_00b5cbb4 == 1) {
    BVar4 = GetStringTypeW(param_1,param_2,param_3,param_4);
    return BVar4;
  }
  if ((DAT_00b5cbb4 == 2) || (DAT_00b5cbb4 == 0)) {
    bVar3 = false;
    bVar2 = false;
    if (param_6 == 0) {
      param_6 = DAT_00b5ca64;
    }
    if (param_5 == 0) {
      param_5 = DAT_00b5ca74;
    }
    UVar6 = FUN_00812dc7();
    if ((param_5 != UVar6) && (UVar6 != 0xffffffff)) {
      param_5 = UVar6;
    }
    uStackY_68 = 0x8130a6;
    iVar7 = WideCharToMultiByte(param_5,0,param_2,param_3,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar7 != 0) {
      local_8 = (undefined *)0x0;
      puVar8 = (undefined1 *)(iVar7 + 3U & 0xfffffffc);
      iVar9 = -(int)puVar8;
      local_28 = (undefined1 *)((int)local_34 + iVar9 + -0x10);
      local_1c = (undefined1 *)((int)local_34 + iVar9 + -0x10);
      *(int *)((int)local_34 + iVar9 + -0x14) = iVar7;
      *(undefined4 *)((int)local_34 + iVar9 + -0x18) = 0;
      *(int *)((int)local_34 + iVar9 + -0x1c) = (int)local_34 + iVar9 + -0x10;
      *(undefined4 *)((int)local_34 + iVar9 + -0x20) = 0x8130d6;
      _memset(*(void **)((int)local_34 + iVar9 + -0x1c),*(int *)((int)local_34 + iVar9 + -0x18),
              *(size_t *)((int)local_34 + iVar9 + -0x14));
      local_8 = (undefined *)0xffffffff;
      if (local_34 + -4 == (size_t *)puVar8) {
        *(int *)((int)local_34 + iVar9 + -0x14) = iVar7;
        *(undefined4 *)((int)local_34 + iVar9 + -0x18) = 1;
        *(undefined4 *)((int)local_34 + iVar9 + -0x1c) = 0x813107;
        local_28 = (undefined1 *)FUN_0080faf9();
        if (local_28 == (undefined1 *)0x0) {
          return 0;
        }
        bVar3 = true;
      }
      *(undefined4 *)((int)local_34 + iVar9 + -0x14) = 0;
      *(undefined4 *)((int)local_34 + iVar9 + -0x18) = 0;
      *(int *)((int)local_34 + iVar9 + -0x1c) = iVar7;
      *(undefined1 **)((int)local_34 + iVar9 + -0x20) = local_28;
      *(int *)((int)local_34 + iVar9 + -0x24) = param_3;
      *(LPCWSTR *)((int)local_34 + iVar9 + -0x28) = param_2;
      *(undefined4 *)((int)local_34 + iVar9 + -0x2c) = 0;
      *(UINT *)((int)local_34 + iVar9 + -0x30) = param_5;
      puVar11 = (undefined1 *)((int)local_34 + iVar9 + -0x34);
      *(undefined4 *)((int)local_34 + iVar9 + -0x34) = 0x813129;
      iVar9 = WideCharToMultiByte(*(UINT *)((int)local_34 + iVar9 + -0x30),
                                  *(DWORD *)((int)local_34 + iVar9 + -0x2c),
                                  *(LPCWSTR *)((int)local_34 + iVar9 + -0x28),
                                  *(int *)((int)local_34 + iVar9 + -0x24),
                                  *(LPSTR *)((int)local_34 + iVar9 + -0x20),
                                  *(int *)((int)local_34 + iVar9 + -0x1c),
                                  *(LPCSTR *)((int)local_34 + iVar9 + -0x18),
                                  *(LPBOOL *)((int)local_34 + iVar9 + -0x14));
      puVar8 = puVar11;
      if (iVar9 != 0) {
        puVar10 = (undefined1 *)(iVar7 * 2 + 5U & 0xfffffffc);
        *(undefined4 *)(puVar11 + -4) = 0x813143;
        iVar9 = -(int)puVar10;
        local_24 = puVar11 + iVar9;
        puVar8 = puVar11 + iVar9;
        local_1c = puVar11 + iVar9;
        local_8 = (undefined *)0xffffffff;
        if (puVar11 == puVar10) {
          *(int *)(puVar11 + iVar9 + -4) = iVar7 * 2 + 2;
          *(undefined4 *)(puVar11 + iVar9 + -8) = 0x81317c;
          local_24 = _malloc(*(size_t *)(puVar11 + iVar9 + -4));
          if (local_24 == (undefined1 *)0x0) goto LAB_008131f3;
          bVar2 = true;
        }
        if (param_6 == 0) {
          param_6 = DAT_00b5ca64;
        }
        psVar1 = (short *)(local_24 + param_3 * 2);
        *psVar1 = -1;
        psVar1[-1] = -1;
        *(undefined1 **)(puVar11 + iVar9 + -4) = local_24;
        *(int *)(puVar11 + iVar9 + -8) = iVar7;
        *(undefined1 **)(puVar11 + iVar9 + -0xc) = local_28;
        *(DWORD *)(puVar11 + iVar9 + -0x10) = param_1;
        *(int *)(puVar11 + iVar9 + -0x14) = param_6;
        puVar8 = puVar11 + iVar9 + -0x18;
        *(undefined4 *)(puVar11 + iVar9 + -0x18) = 0x8131bb;
        local_38 = GetStringTypeA(*(LCID *)(puVar11 + iVar9 + -0x14),
                                  *(DWORD *)(puVar11 + iVar9 + -0x10),
                                  *(LPCSTR *)(puVar11 + iVar9 + -0xc),*(int *)(puVar11 + iVar9 + -8)
                                  ,*(LPWORD *)(puVar11 + iVar9 + -4));
        if ((psVar1[-1] == -1) || (*psVar1 != -1)) {
          local_38 = 0;
        }
        else {
          *(int *)(puVar8 + -4) = param_3 * 2;
          *(undefined1 **)(puVar8 + -8) = local_24;
          *(LPWORD *)(puVar8 + -0xc) = param_4;
          *(undefined4 *)(puVar8 + -0x10) = 0x8131d9;
          _memmove(*(void **)(puVar8 + -0xc),*(void **)(puVar8 + -8),*(size_t *)(puVar8 + -4));
        }
        if (bVar2) {
          *(undefined1 **)(puVar8 + -4) = local_24;
          *(undefined4 *)(puVar8 + -8) = 0x8131f0;
          _free(*(void **)(puVar8 + -4));
          return extraout_EAX;
        }
      }
LAB_008131f3:
      if (bVar3) {
        *(undefined1 **)(puVar8 + -4) = local_28;
        *(undefined4 *)(puVar8 + -8) = 0x813200;
        _free(*(void **)(puVar8 + -4));
        return extraout_EAX_00;
      }
      return local_38;
    }
  }
  return 0;
}


// ==== FUN_008130e3 @ 0x008130e3 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_008130e3(void)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  BOOL BVar8;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int unaff_EBP;
  
  iVar6 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar6 + -4) = 0x8130eb;
  __resetstkoflw();
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar2 = *(int *)(unaff_EBP + -0x28);
  if (*(int *)(unaff_EBP + -0x24) == 0) {
    *(int *)(iVar6 + -4) = iVar2;
    *(undefined4 *)(iVar6 + -8) = 1;
    *(undefined4 *)(iVar6 + -0xc) = 0x813107;
    iVar5 = FUN_0080faf9();
    *(int *)(unaff_EBP + -0x24) = iVar5;
    if (iVar5 == 0) {
      uVar4 = 0;
      goto LAB_00813204;
    }
    *(undefined4 *)(unaff_EBP + -0x30) = 1;
  }
  *(undefined4 *)(iVar6 + -4) = 0;
  *(undefined4 *)(iVar6 + -8) = 0;
  *(int *)(iVar6 + -0xc) = iVar2;
  *(undefined4 *)(iVar6 + -0x10) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(iVar6 + -0x14) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(iVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(iVar6 + -0x1c) = 0;
  *(undefined4 *)(iVar6 + -0x20) = *(undefined4 *)(unaff_EBP + 0x18);
  puVar9 = (undefined1 *)(iVar6 + -0x24);
  *(undefined4 *)(iVar6 + -0x24) = 0x813129;
  iVar6 = WideCharToMultiByte(*(UINT *)(iVar6 + -0x20),*(DWORD *)(iVar6 + -0x1c),
                              *(LPCWSTR *)(iVar6 + -0x18),*(int *)(iVar6 + -0x14),
                              *(LPSTR *)(iVar6 + -0x10),*(int *)(iVar6 + -0xc),
                              *(LPCSTR *)(iVar6 + -8),*(LPBOOL *)(iVar6 + -4));
  puVar10 = puVar9;
  if (iVar6 != 0) {
    *(undefined4 *)(unaff_EBP + -4) = 1;
    *(undefined4 *)(puVar9 + -4) = 0x813143;
    iVar6 = -(iVar2 * 2 + 5U & 0xfffffffc);
    puVar10 = puVar9 + iVar6;
    *(int *)(unaff_EBP + -0x18) = (int)puVar9 + iVar6;
    *(int *)(unaff_EBP + -0x20) = (int)puVar9 + iVar6;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x20) == 0) {
      *(int *)(puVar9 + iVar6 + -4) = iVar2 * 2 + 2;
      *(undefined4 *)(puVar9 + iVar6 + -8) = 0x81317c;
      pvVar7 = _malloc(*(size_t *)(puVar9 + iVar6 + -4));
      *(void **)(unaff_EBP + -0x20) = pvVar7;
      if (pvVar7 == (void *)0x0) goto LAB_008131f3;
      *(undefined4 *)(unaff_EBP + -0x2c) = 1;
    }
    if (*(int *)(unaff_EBP + 0x1c) == 0) {
      *(undefined4 *)(unaff_EBP + 0x1c) = DAT_00b5ca64;
    }
    iVar3 = *(int *)(unaff_EBP + 0x10) * 2;
    iVar5 = *(int *)(unaff_EBP + -0x20);
    psVar1 = (short *)(iVar3 + iVar5);
    *psVar1 = -1;
    psVar1[-1] = -1;
    *(int *)(puVar9 + iVar6 + -4) = iVar5;
    *(int *)(puVar9 + iVar6 + -8) = iVar2;
    *(undefined4 *)(puVar9 + iVar6 + -0xc) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(puVar9 + iVar6 + -0x10) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(puVar9 + iVar6 + -0x14) = *(undefined4 *)(unaff_EBP + 0x1c);
    puVar10 = puVar9 + iVar6 + -0x18;
    *(undefined4 *)(puVar9 + iVar6 + -0x18) = 0x8131bb;
    BVar8 = GetStringTypeA(*(LCID *)(puVar9 + iVar6 + -0x14),*(DWORD *)(puVar9 + iVar6 + -0x10),
                           *(LPCSTR *)(puVar9 + iVar6 + -0xc),*(int *)(puVar9 + iVar6 + -8),
                           *(LPWORD *)(puVar9 + iVar6 + -4));
    *(BOOL *)(unaff_EBP + -0x34) = BVar8;
    if ((psVar1[-1] == -1) || (*psVar1 != -1)) {
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
    }
    else {
      *(int *)(puVar10 + -4) = iVar3;
      *(undefined4 *)(puVar10 + -8) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(puVar10 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
      *(undefined4 *)(puVar10 + -0x10) = 0x8131d9;
      _memmove(*(void **)(puVar10 + -0xc),*(void **)(puVar10 + -8),*(size_t *)(puVar10 + -4));
    }
    if (*(int *)(unaff_EBP + -0x2c) != 0) {
      *(undefined4 *)(puVar10 + -4) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(puVar10 + -8) = 0x8131f0;
      _free(*(void **)(puVar10 + -4));
      return extraout_EAX;
    }
  }
LAB_008131f3:
  if (*(int *)(unaff_EBP + -0x30) != 0) {
    *(undefined4 *)(puVar10 + -4) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(puVar10 + -8) = 0x813200;
    _free(*(void **)(puVar10 + -4));
    return extraout_EAX_00;
  }
  uVar4 = *(undefined4 *)(unaff_EBP + -0x34);
LAB_00813204:
  *(undefined4 *)(unaff_EBP + -0x44) = 0x81320c;
  return uVar4;
}


// ==== FUN_00813155 @ 0x00813155 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00813155(void)

{
  short *psVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  BOOL BVar7;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined1 *puVar8;
  int unaff_EBP;
  
  puVar2 = *(undefined1 **)(unaff_EBP + -0x18);
  *(undefined4 *)(puVar2 + -4) = 0x81315d;
  __resetstkoflw();
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar3 = *(int *)(unaff_EBP + -0x28);
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    *(int *)(puVar2 + -4) = iVar3 * 2 + 2;
    *(undefined4 *)(puVar2 + -8) = 0x81317c;
    pvVar6 = _malloc(*(size_t *)(puVar2 + -4));
    *(void **)(unaff_EBP + -0x20) = pvVar6;
    puVar8 = puVar2;
    if (pvVar6 == (void *)0x0) goto LAB_008131f3;
    *(undefined4 *)(unaff_EBP + -0x2c) = 1;
  }
  if (*(int *)(unaff_EBP + 0x1c) == 0) {
    *(undefined4 *)(unaff_EBP + 0x1c) = DAT_00b5ca64;
  }
  iVar5 = *(int *)(unaff_EBP + 0x10) * 2;
  iVar4 = *(int *)(unaff_EBP + -0x20);
  psVar1 = (short *)(iVar5 + iVar4);
  *psVar1 = -1;
  psVar1[-1] = -1;
  *(int *)(puVar2 + -4) = iVar4;
  *(int *)(puVar2 + -8) = iVar3;
  *(undefined4 *)(puVar2 + -0xc) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(puVar2 + -0x14) = *(undefined4 *)(unaff_EBP + 0x1c);
  puVar8 = puVar2 + -0x18;
  *(undefined4 *)(puVar2 + -0x18) = 0x8131bb;
  BVar7 = GetStringTypeA(*(LCID *)(puVar2 + -0x14),*(DWORD *)(puVar2 + -0x10),
                         *(LPCSTR *)(puVar2 + -0xc),*(int *)(puVar2 + -8),*(LPWORD *)(puVar2 + -4));
  *(BOOL *)(unaff_EBP + -0x34) = BVar7;
  if ((psVar1[-1] == -1) || (*psVar1 != -1)) {
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
  }
  else {
    *(int *)(puVar8 + -4) = iVar5;
    *(undefined4 *)(puVar8 + -8) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(puVar8 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
    *(undefined4 *)(puVar8 + -0x10) = 0x8131d9;
    _memmove(*(void **)(puVar8 + -0xc),*(void **)(puVar8 + -8),*(size_t *)(puVar8 + -4));
  }
  if (*(int *)(unaff_EBP + -0x2c) != 0) {
    *(undefined4 *)(puVar8 + -4) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(puVar8 + -8) = 0x8131f0;
    _free(*(void **)(puVar8 + -4));
    return extraout_EAX;
  }
LAB_008131f3:
  if (*(int *)(unaff_EBP + -0x30) == 0) {
    *(undefined4 *)(unaff_EBP + -0x44) = 0x81320c;
    return *(undefined4 *)(unaff_EBP + -0x34);
  }
  *(undefined4 *)(puVar8 + -4) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(puVar8 + -8) = 0x813200;
  _free(*(void **)(puVar8 + -4));
  return extraout_EAX_00;
}


// ==== __ZeroTail @ 0x0081320d ====

/* Library Function - Single Match
    __ZeroTail
   
   Library: Visual Studio 2003 Release */

undefined4 __ZeroTail(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_2 / 0x20;
  uVar1 = *(uint *)(param_1 + iVar2 * 4) & ~(-1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f));
  while( true ) {
    if (uVar1 != 0) {
      return 0;
    }
    iVar2 = iVar2 + 1;
    if (2 < iVar2) break;
    uVar1 = *(uint *)(param_1 + iVar2 * 4);
  }
  return 1;
}


// ==== __IncMan @ 0x0081323f ====

/* Library Function - Single Match
    __IncMan
   
   Library: Visual Studio 2003 Release */

void __IncMan(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + (param_2 / 0x20) * 4);
  iVar1 = ___addl(*puVar3,1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f),puVar3);
  iVar2 = param_2 / 0x20 + -1;
  if (-1 < iVar2) {
    puVar3 = (undefined4 *)(param_1 + iVar2 * 4);
    do {
      if (iVar1 == 0) {
        return;
      }
      iVar1 = ___addl(*puVar3,1,puVar3);
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
  }
  return;
}


// ==== __RoundMan @ 0x0081328c ====

/* Library Function - Single Match
    __RoundMan
   
   Library: Visual Studio 2003 Release */

undefined4 __RoundMan(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  local_8 = 0;
  iVar2 = param_2 / 0x20;
  bVar4 = 0x1f - (char)(param_2 % 0x20);
  if (((*(uint *)(param_1 + iVar2 * 4) & 1 << (bVar4 & 0x1f)) != 0) &&
     (iVar3 = __ZeroTail(param_1,param_2), iVar3 == 0)) {
    local_8 = __IncMan(param_1,param_2 + -1);
  }
  puVar1 = (uint *)(param_1 + iVar2 * 4);
  *puVar1 = *puVar1 & -1 << (bVar4 & 0x1f);
  iVar2 = iVar2 + 1;
  if (iVar2 < 3) {
    puVar5 = (undefined4 *)(param_1 + iVar2 * 4);
    for (iVar3 = 3 - iVar2; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return local_8;
}


// ==== __CopyMan @ 0x008132fe ====

/* Library Function - Single Match
    __CopyMan
   
   Library: Visual Studio 2003 Release */

void __CopyMan(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = 3;
  param_1 = param_1 - (int)param_2;
  do {
    *(undefined4 *)(param_1 + (int)param_2) = *param_2;
    param_2 = param_2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// ==== __IsZeroMan @ 0x00813319 ====

/* Library Function - Single Match
    __IsZeroMan
   
   Library: Visual Studio 2003 Release */

undefined4 __IsZeroMan(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int *)(param_1 + iVar1 * 4) != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  return 1;
}


// ==== __ShrMan @ 0x00813332 ====

/* Library Function - Single Match
    __ShrMan
   
   Library: Visual Studio 2003 Release */

void __ShrMan(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  uint local_8;
  
  bVar3 = (byte)(param_2 % 0x20);
  iVar2 = 0;
  local_8 = 0;
  do {
    uVar1 = *(uint *)(param_1 + iVar2 * 4);
    *(uint *)(param_1 + iVar2 * 4) = uVar1 >> (bVar3 & 0x1f) | local_8;
    local_8 = (uVar1 & ~(-1 << (bVar3 & 0x1f))) << (0x20 - bVar3 & 0x1f);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  iVar2 = 2;
  puVar4 = (undefined4 *)(param_1 + (2 - param_2 / 0x20) * 4);
  do {
    if (iVar2 < param_2 / 0x20) {
      *(undefined4 *)(param_1 + iVar2 * 4) = 0;
    }
    else {
      *(undefined4 *)(param_1 + iVar2 * 4) = *puVar4;
    }
    iVar2 = iVar2 + -1;
    puVar4 = puVar4 + -1;
  } while (-1 < iVar2);
  return;
}


// ==== __ld12cvt @ 0x008133ad ====

/* Library Function - Single Match
    __ld12cvt
   
   Library: Visual Studio 2003 Release */

undefined4 __ld12cvt(ushort *param_1,uint *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 local_1c [12];
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar1 = param_1[5];
  local_10 = *(uint *)(param_1 + 3);
  local_c = *(uint *)(param_1 + 1);
  local_8 = (uint)*param_1 << 0x10;
  uVar4 = uVar1 & 0x7fff;
  iVar5 = uVar4 - 0x3fff;
  if (iVar5 == -0x3fff) {
    iVar5 = 0;
    iVar2 = __IsZeroMan();
    if (iVar2 != 0) {
LAB_008134c5:
      uVar3 = 0;
      goto LAB_008134c7;
    }
    local_10 = 0;
    local_c = 0;
  }
  else {
    __CopyMan(local_1c,&local_10);
    iVar2 = __RoundMan(&local_10,param_3[2]);
    if (iVar2 != 0) {
      iVar5 = uVar4 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar5 < iVar2 - param_3[2]) {
      local_10 = 0;
      local_c = 0;
    }
    else {
      if (iVar2 < iVar5) {
        if (*param_3 <= iVar5) {
          local_c = 0;
          local_8 = 0;
          local_10 = 0x80000000;
          __ShrMan(&local_10,param_3[3]);
          iVar5 = param_3[5] + *param_3;
          uVar3 = 1;
          goto LAB_008134c7;
        }
        local_10 = local_10 & 0x7fffffff;
        iVar5 = param_3[5] + iVar5;
        __ShrMan(&local_10,param_3[3]);
        goto LAB_008134c5;
      }
      __CopyMan(&local_10,local_1c);
      __ShrMan(&local_10,iVar2 - iVar5);
      __RoundMan(&local_10,param_3[2]);
      __ShrMan(&local_10,param_3[3] + 1);
    }
  }
  iVar5 = 0;
  uVar3 = 2;
LAB_008134c7:
  local_10 = iVar5 << (0x1fU - (char)param_3[3] & 0x1f) |
             -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 | local_10;
  if (param_3[4] == 0x40) {
    param_2[1] = local_10;
    *param_2 = local_c;
  }
  else if (param_3[4] == 0x20) {
    *param_2 = local_10;
  }
  return uVar3;
}


// ==== FID_conflict:__ld12tod @ 0x00813505 ====

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 2003 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt(_Ifp,_D,&DAT_00b4a3e8);
  return IVar1;
}


// ==== FID_conflict:__ld12tod @ 0x0081351b ====

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 2003 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt(_Ifp,_D,&DAT_00b4a400);
  return IVar1;
}


// ==== FUN_00813531 @ 0x00813531 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00813531(_CRT_DOUBLE *param_1,undefined4 param_2)

{
  undefined1 local_18 [4];
  _LDBL12 local_14;
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)((&local_14)[1].ld12 + 4);
  FUN_00813efb(&local_14,local_18,param_2,0,0,0,0);
  FID_conflict___ld12tod(&local_14,param_1);
  return;
}


// ==== FUN_00813576 @ 0x00813576 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00813576(_CRT_DOUBLE *param_1,undefined4 param_2)

{
  undefined1 local_18 [4];
  _LDBL12 local_14;
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)((&local_14)[1].ld12 + 4);
  FUN_00813efb(&local_14,local_18,param_2,0,0,0,0);
  FID_conflict___ld12tod(&local_14,param_1);
  return;
}


// ==== __fptostr @ 0x008135bb ====

/* Library Function - Single Match
    __fptostr
   
   Library: Visual Studio 2003 Release */

errno_t __cdecl __fptostr(char *_Buf,size_t _SizeInBytes,int _Digits,STRFLT _PtFlt)

{
  char *_Str;
  char *_Dst;
  char *pcVar1;
  size_t sVar2;
  char *pcVar3;
  char cVar4;
  
  _Dst = _Buf;
  pcVar3 = *(char **)(_Digits + 0xc);
  _Str = _Buf + 1;
  *_Buf = '0';
  pcVar1 = _Str;
  if (0 < (int)_SizeInBytes) {
    _Buf = (char *)_SizeInBytes;
    _SizeInBytes = 0;
    do {
      cVar4 = *pcVar3;
      if (cVar4 == '\0') {
        cVar4 = '0';
      }
      else {
        pcVar3 = pcVar3 + 1;
      }
      *pcVar1 = cVar4;
      pcVar1 = pcVar1 + 1;
      _Buf = _Buf + -1;
    } while (_Buf != (char *)0x0);
  }
  *pcVar1 = '\0';
  if ((-1 < (int)_SizeInBytes) && ('4' < *pcVar3)) {
    while (pcVar1 = pcVar1 + -1, *pcVar1 == '9') {
      *pcVar1 = '0';
    }
    *pcVar1 = *pcVar1 + '\x01';
  }
  if (*_Dst == '1') {
    *(int *)(_Digits + 4) = *(int *)(_Digits + 4) + 1;
  }
  else {
    sVar2 = _strlen(_Str);
    pcVar1 = _memmove(_Dst,_Str,sVar2 + 1);
  }
  return (errno_t)pcVar1;
}


// ==== ___dtold @ 0x00813632 ====

/* Library Function - Single Match
    ___dtold
   
   Library: Visual Studio 2003 Release */

void ___dtold(uint *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  uint local_8;
  
  uVar1 = *(ushort *)((int)param_2 + 6);
  local_8 = 0x80000000;
  uVar3 = uVar1 >> 4;
  uVar4 = uVar3 & 0x7ff;
  uVar2 = *param_2;
  if ((uVar3 & 0x7ff) == 0) {
    if (((param_2[1] & 0xfffff) == 0) && (uVar2 == 0)) {
      param_1[1] = 0;
      *param_1 = 0;
      *(undefined2 *)(param_1 + 2) = 0;
      return;
    }
    uVar4 = uVar4 + 0x3c01;
    local_8 = 0;
  }
  else if (uVar4 == 0x7ff) {
    uVar4 = 0x7fff;
  }
  else {
    uVar4 = uVar4 + 0x3c00;
  }
  param_1[1] = uVar2 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | local_8;
  *param_1 = uVar2 << 0xb;
  while (local_8 == 0) {
    uVar2 = param_1[1];
    uVar4 = uVar4 - 1;
    param_1[1] = uVar2 << 1 | *param_1 >> 0x1f;
    *param_1 = *param_1 * 2;
    local_8 = uVar2 << 1 & 0x80000000;
  }
  *(ushort *)(param_1 + 2) = uVar1 & 0x8000 | uVar4;
  return;
}


// ==== FUN_008136ec @ 0x008136ec ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_008136ec(undefined1 param_1,undefined4 param_2,int *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  short local_30;
  char local_2e;
  undefined1 local_2c [24];
  undefined4 local_14;
  undefined4 uStack_10;
  undefined2 uStack_c;
  undefined4 local_8;
  
  iVar2 = param_4;
  piVar1 = param_3;
  local_8 = DAT_00b49670 ^ (uint)(local_2c + 0x28);
  ___dtold(&local_14,&param_1);
  iVar3 = FUN_008150e3(local_14,uStack_10,uStack_c,0x11,0,&local_30);
  piVar1[2] = iVar3;
  *piVar1 = (int)local_2e;
  piVar1[1] = (int)local_30;
  FUN_00809180(iVar2,local_2c);
  piVar1[3] = iVar2;
  return piVar1;
}


// ==== __abstract_cw @ 0x0081376d ====

/* Library Function - Single Match
    __abstract_cw
   
   Library: Visual Studio 2003 Release */

uint __abstract_cw(void)

{
  uint uVar1;
  ushort uVar2;
  ushort unaff_BX;
  
  uVar1 = 0;
  if ((unaff_BX & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((unaff_BX & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((unaff_BX & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((unaff_BX & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((unaff_BX & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((unaff_BX & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  uVar2 = unaff_BX & 0xc00;
  if ((unaff_BX & 0xc00) != 0) {
    if (uVar2 == 0x400) {
      uVar1 = uVar1 | 0x100;
    }
    else if (uVar2 == 0x800) {
      uVar1 = uVar1 | 0x200;
    }
    else if (uVar2 == 0xc00) {
      uVar1 = uVar1 | 0x300;
    }
  }
  if ((unaff_BX & 0x300) == 0) {
    uVar1 = uVar1 | 0x20000;
  }
  else if ((unaff_BX & 0x300) == 0x200) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((unaff_BX & 0x1000) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  return uVar1;
}


// ==== __hw_cw @ 0x008137ff ====

/* Library Function - Single Match
    __hw_cw
   
   Library: Visual Studio 2003 Release */

uint __hw_cw(void)

{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  
  uVar1 = (uint)((unaff_EBX & 0x10) != 0);
  if ((unaff_EBX & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((unaff_EBX & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((unaff_EBX & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((unaff_EBX & 1) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if ((unaff_EBX & 0x80000) != 0) {
    uVar1 = uVar1 | 2;
  }
  uVar2 = unaff_EBX & 0x300;
  if (uVar2 != 0) {
    if (uVar2 == 0x100) {
      uVar1 = uVar1 | 0x400;
    }
    else if (uVar2 == 0x200) {
      uVar1 = uVar1 | 0x800;
    }
    else if (uVar2 == 0x300) {
      uVar1 = uVar1 | 0xc00;
    }
  }
  if ((unaff_EBX & 0x30000) == 0) {
    uVar1 = uVar1 | 0x300;
  }
  else if ((unaff_EBX & 0x30000) == 0x10000) {
    uVar1 = uVar1 | 0x200;
  }
  if ((unaff_EBX & 0x40000) != 0) {
    uVar1 = uVar1 | 0x1000;
  }
  return uVar1;
}


// ==== __control87 @ 0x0081388d ====

/* Library Function - Single Match
    __control87
   
   Library: Visual Studio 2003 Release */

uint __cdecl __control87(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = __abstract_cw();
  __hw_cw();
  return uVar1 & ~_Mask | _NewValue & _Mask;
}


// ==== __controlfp @ 0x008138bf ====

/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 2003 Release */

uint __cdecl __controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = __control87(_NewValue,_Mask & 0xfff7ffff);
  return uVar1;
}


// ==== FUN_008138d5 @ 0x008138d5 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008138d5(int param_1,int *param_2,ushort *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_94;
  undefined1 local_90 [48];
  undefined8 local_60;
  uint local_50;
  uint local_14;
  undefined1 auStack_10 [12];
  
  local_14 = DAT_00b49670 ^ (uint)(auStack_10 + 0xc);
  local_94 = (uint)*param_3;
  iVar1 = *param_2;
  if (iVar1 == 1) {
LAB_0081392f:
    uVar2 = 8;
  }
  else if (iVar1 == 2) {
    uVar2 = 4;
  }
  else if (iVar1 == 3) {
    uVar2 = 0x11;
  }
  else if (iVar1 == 4) {
    uVar2 = 0x12;
  }
  else {
    if (iVar1 == 5) goto LAB_0081392f;
    if (iVar1 == 7) {
      *param_2 = 1;
      goto LAB_0081398b;
    }
    if (iVar1 != 8) goto LAB_0081398b;
    uVar2 = 0x10;
  }
  iVar1 = __handle_exc(uVar2,param_2 + 6,local_94);
  if (iVar1 == 0) {
    if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {
      local_60 = *(undefined8 *)(param_2 + 4);
      local_50 = local_50 & 0xffffffe3 | 3;
    }
    else {
      local_50 = local_50 & 0xfffffffe;
    }
    __raise_exc(local_90,&local_94,uVar2,param_1,param_2 + 2,param_2 + 6);
  }
LAB_0081398b:
  __ctrlfp(local_94,0xffff);
  if (((*param_2 == 8) || (DAT_00b4a418 != 0)) || (iVar1 = FUN_00813a93(param_2), iVar1 == 0)) {
    FID_conflict___set_errno_from_matherr(*param_2);
    return;
  }
  return;
}


// ==== __frnd @ 0x008139d1 ====

/* Library Function - Single Match
    __frnd
   
   Library: Visual Studio 2003 Release */

float10 __frnd(double param_1)

{
  return (float10)ROUND(param_1);
}


// ==== __isatty @ 0x008139e2 ====

/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 2003 Release */

int __cdecl __isatty(int _FileHandle)

{
  if ((uint)_FileHandle < DAT_00b60f80) {
    return (int)*(char *)((&DAT_00b60fa0)[_FileHandle >> 5] + 4 + (_FileHandle & 0x1fU) * 0x24) &
           0x40;
  }
  return 0;
}


// ==== ___wctomb_mt @ 0x00813a0c ====

/* Library Function - Single Match
    ___wctomb_mt
   
   Library: Visual Studio 2003 Release */

int ___wctomb_mt(int param_1,LPSTR param_2,WCHAR param_3)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  undefined4 *puVar2;
  
  lpMultiByteStr = param_2;
  if (param_2 == (LPSTR)0x0) {
    iVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x14) == 0) {
      if ((ushort)param_3 < 0x100) {
        *param_2 = (CHAR)param_3;
        return 1;
      }
    }
    else {
      param_2 = (LPSTR)0x0;
      iVar1 = WideCharToMultiByte(*(UINT *)(param_1 + 4),0,&param_3,1,lpMultiByteStr,
                                  *(int *)(param_1 + 0x28),(LPCSTR)0x0,(LPBOOL)&param_2);
      if ((iVar1 != 0) && (param_2 == (LPSTR)0x0)) {
        return iVar1;
      }
    }
    puVar2 = (undefined4 *)FUN_00804b94();
    *puVar2 = 0x2a;
    iVar1 = -1;
  }
  return iVar1;
}


// ==== _wctomb @ 0x00813a6c ====

/* Library Function - Single Match
    _wctomb
   
   Library: Visual Studio 2003 Release */

int __cdecl _wctomb(char *_MbCh,wchar_t _WCh)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  undefined2 in_stack_0000000a;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  iVar3 = ___wctomb_mt(ptVar2,_MbCh,__WCh);
  return iVar3;
}


// ==== FUN_00813a93 @ 0x00813a93 ====

undefined4 FUN_00813a93(void)

{
  return 0;
}


// ==== __set_osfhnd @ 0x00813a96 ====

/* Library Function - Single Match
    __set_osfhnd
   
   Library: Visual Studio 2003 Release */

int __cdecl __set_osfhnd(int param_1,intptr_t param_2)

{
  undefined4 *puVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if ((uint)param_1 < DAT_00b60f80) {
    iVar2 = (param_1 & 0x1fU) * 0x24;
    if (*(int *)(iVar2 + (&DAT_00b60fa0)[param_1 >> 5]) == -1) {
      if (DAT_00b49330 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_00813aef;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)param_2);
      }
LAB_00813aef:
      *(intptr_t *)(iVar2 + (&DAT_00b60fa0)[param_1 >> 5]) = param_2;
      return 0;
    }
  }
  puVar1 = (undefined4 *)FUN_00804b94();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_00804b9d();
  *puVar1 = 0;
  return -1;
}


// ==== __free_osfhnd @ 0x00813b12 ====

/* Library Function - Single Match
    __free_osfhnd
   
   Library: Visual Studio 2003 Release */

int __cdecl __free_osfhnd(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if ((uint)param_1 < DAT_00b60f80) {
    iVar3 = (param_1 & 0x1fU) * 0x24;
    piVar1 = (int *)((&DAT_00b60fa0)[param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_00b49330 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_00813b6e;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_00813b6e:
      *(undefined4 *)(iVar3 + (&DAT_00b60fa0)[param_1 >> 5]) = 0xffffffff;
      return 0;
    }
  }
  puVar2 = (undefined4 *)FUN_00804b94();
  *puVar2 = 9;
  puVar2 = (undefined4 *)FUN_00804b9d();
  *puVar2 = 0;
  return -1;
}


// ==== __get_osfhandle @ 0x00813b91 ====

/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 2003 Release */

intptr_t __cdecl __get_osfhandle(int _FileHandle)

{
  intptr_t *piVar1;
  undefined4 *puVar2;
  
  if (((uint)_FileHandle < DAT_00b60f80) &&
     (piVar1 = (intptr_t *)((&DAT_00b60fa0)[_FileHandle >> 5] + (_FileHandle & 0x1fU) * 0x24),
     (*(byte *)(piVar1 + 1) & 1) != 0)) {
    return *piVar1;
  }
  puVar2 = (undefined4 *)FUN_00804b94();
  *puVar2 = 9;
  puVar2 = (undefined4 *)FUN_00804b9d();
  *puVar2 = 0;
  return -1;
}


// ==== __lock_fhandle @ 0x00813bd2 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __lock_fhandle
   
   Library: Visual Studio 2003 Release */

int __cdecl __lock_fhandle(int _Filehandle)

{
  int iVar1;
  int iVar2;
  undefined1 local_14 [8];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00a0bc70;
  uStack_c = 0x813bde;
  iVar1 = (&DAT_00b60fa0)[_Filehandle >> 5] + (_Filehandle & 0x1fU) * 0x24;
  if (*(int *)(iVar1 + 8) == 0) {
    __lock(10);
    local_8 = (undefined *)0x0;
    if (*(int *)(iVar1 + 8) == 0) {
      iVar2 = ___crtInitCritSecAndSpinCount(iVar1 + 0xc,4000);
      if (iVar2 == 0) {
        __local_unwind2(local_14,0xffffffff);
        return 0;
      }
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    local_8 = (undefined *)0xffffffff;
    FUN_00813c69();
  }
  EnterCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_00b60fa0)[_Filehandle >> 5] + 0xc + (_Filehandle & 0x1fU) * 0x24));
  return 1;
}


// ==== FUN_00813c66 @ 0x00813c66 ====

void FUN_00813c66(void)

{
  FUN_00806c2f(10);
  return;
}


// ==== FUN_00813c69 @ 0x00813c69 ====

void FUN_00813c69(void)

{
  FUN_00806c2f(10);
  return;
}


// ==== __unlock_fhandle @ 0x00813c72 ====

/* Library Function - Single Match
    __unlock_fhandle
   
   Library: Visual Studio 2003 Release */

void __cdecl __unlock_fhandle(int _Filehandle)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_00b60fa0)[_Filehandle >> 5] + 0xc + (_Filehandle & 0x1fU) * 0x24));
  return;
}


// ==== __alloc_osfhnd @ 0x00813c94 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __alloc_osfhnd
   
   Library: Visual Studio 2003 Release */

int __cdecl __alloc_osfhnd(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_20;
  undefined1 local_14 [8];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00a0bc80;
  uStack_c = 0x813ca0;
  local_20 = -1;
  iVar1 = FUN_00806c44(0xb);
  if (iVar1 == 0) {
LAB_00813d35:
    local_20 = -1;
  }
  else {
    __lock(0xb);
    local_8 = (undefined *)0x0;
    for (iVar1 = 0; iVar1 < 0x40; iVar1 = iVar1 + 1) {
      puVar3 = (undefined4 *)(&DAT_00b60fa0)[iVar1];
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = _malloc(0x480);
        if (puVar3 != (undefined4 *)0x0) {
          (&DAT_00b60fa0)[iVar1] = puVar3;
          DAT_00b60f80 = DAT_00b60f80 + 0x20;
          for (; puVar3 < (undefined4 *)((&DAT_00b60fa0)[iVar1] + 0x480); puVar3 = puVar3 + 9) {
            *(undefined1 *)(puVar3 + 1) = 0;
            *puVar3 = 0xffffffff;
            *(undefined1 *)((int)puVar3 + 5) = 10;
            puVar3[2] = 0;
          }
          local_20 = iVar1 << 5;
          iVar1 = __lock_fhandle(local_20);
          if (iVar1 == 0) {
            local_20 = -1;
          }
        }
        break;
      }
      for (; puVar3 < (undefined4 *)((&DAT_00b60fa0)[iVar1] + 0x480); puVar3 = puVar3 + 9) {
        if ((*(byte *)(puVar3 + 1) & 1) == 0) {
          if (puVar3[2] == 0) {
            __lock(10);
            local_8 = (undefined *)0x1;
            if (puVar3[2] == 0) {
              iVar2 = ___crtInitCritSecAndSpinCount(puVar3 + 3,4000);
              if (iVar2 == 0) {
                __local_unwind2(local_14,0xffffffff);
                goto LAB_00813d35;
              }
              puVar3[2] = puVar3[2] + 1;
            }
            local_8 = (undefined *)0x0;
            FUN_00813d6d();
          }
          EnterCriticalSection((LPCRITICAL_SECTION)(puVar3 + 3));
          if ((*(byte *)(puVar3 + 1) & 1) == 0) {
            *puVar3 = 0xffffffff;
            local_20 = ((int)puVar3 - (&DAT_00b60fa0)[iVar1]) / 0x24 + iVar1 * 0x20;
            break;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)(puVar3 + 3));
        }
      }
      if (local_20 != -1) break;
    }
    local_8 = (undefined *)0xffffffff;
    FUN_00813e07();
  }
  return local_20;
}


// ==== FUN_00813d6d @ 0x00813d6d ====

void FUN_00813d6d(void)

{
  FUN_00806c2f(10);
  return;
}


// ==== FUN_00813e07 @ 0x00813e07 ====

void FUN_00813e07(void)

{
  FUN_00806c2f(0xb);
  return;
}


// ==== ___mbtowc_mt @ 0x00813e10 ====

/* Library Function - Single Match
    ___mbtowc_mt
   
   Library: Visual Studio 2003 Release */

undefined4 ___mbtowc_mt(int param_1,LPWSTR param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_3 != (byte *)0x0) && (param_4 != 0)) {
    bVar1 = *param_3;
    if (bVar1 != 0) {
      if (*(int *)(param_1 + 0x14) == 0) {
        if (param_2 != (LPWSTR)0x0) {
          *param_2 = (ushort)bVar1;
        }
        return 1;
      }
      if ((*(byte *)(*(int *)(param_1 + 0x48) + 1 + (uint)bVar1 * 2) & 0x80) == 0) {
        iVar2 = MultiByteToWideChar(*(UINT *)(param_1 + 4),9,(LPCSTR)param_3,1,param_2,
                                    (uint)(param_2 != (LPWSTR)0x0));
        if (iVar2 != 0) {
          return 1;
        }
      }
      else {
        iVar2 = *(int *)(param_1 + 0x28);
        if ((((1 < iVar2) && (iVar2 <= (int)param_4)) &&
            (iVar2 = MultiByteToWideChar(*(UINT *)(param_1 + 4),9,(LPCSTR)param_3,iVar2,param_2,
                                         (uint)(param_2 != (LPWSTR)0x0)), iVar2 != 0)) ||
           ((*(uint *)(param_1 + 0x28) <= param_4 && (param_3[1] != 0)))) {
          return *(undefined4 *)(param_1 + 0x28);
        }
      }
      puVar3 = (undefined4 *)FUN_00804b94();
      *puVar3 = 0x2a;
      return 0xffffffff;
    }
    if (param_2 != (LPWSTR)0x0) {
      *param_2 = L'\0';
    }
  }
  return 0;
}


// ==== _mbtowc @ 0x00813ed0 ====

/* Library Function - Single Match
    _mbtowc
   
   Library: Visual Studio 2003 Release */

int __cdecl _mbtowc(wchar_t *_DstCh,char *_SrcCh,size_t _SrcSizeInBytes)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  iVar3 = ___mbtowc_mt(ptVar2,_DstCh,_SrcCh,_SrcSizeInBytes);
  return iVar3;
}


// ==== FUN_00813efb @ 0x00813efb ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x008141db) */
/* WARNING: Removing unreachable block (ram,0x00814154) */
/* WARNING: Removing unreachable block (ram,0x008142b7) */
/* WARNING: Removing unreachable block (ram,0x00814167) */
/* WARNING: Removing unreachable block (ram,0x0081416f) */
/* WARNING: Removing unreachable block (ram,0x00814175) */
/* WARNING: Removing unreachable block (ram,0x00814178) */
/* WARNING: Removing unreachable block (ram,0x0081417f) */
/* WARNING: Removing unreachable block (ram,0x00814189) */
/* WARNING: Removing unreachable block (ram,0x00814253) */
/* WARNING: Removing unreachable block (ram,0x0081424d) */
/* WARNING: Removing unreachable block (ram,0x00814259) */
/* WARNING: Removing unreachable block (ram,0x00814276) */
/* WARNING: Removing unreachable block (ram,0x00814278) */
/* WARNING: Removing unreachable block (ram,0x00814280) */
/* WARNING: Removing unreachable block (ram,0x00814283) */
/* WARNING: Removing unreachable block (ram,0x00814288) */
/* WARNING: Removing unreachable block (ram,0x0081428b) */
/* WARNING: Removing unreachable block (ram,0x008142c0) */
/* WARNING: Removing unreachable block (ram,0x00814292) */
/* WARNING: Removing unreachable block (ram,0x00814299) */
/* WARNING: Removing unreachable block (ram,0x008142d7) */
/* WARNING: Removing unreachable block (ram,0x008142de) */
/* WARNING: Removing unreachable block (ram,0x008142e6) */

undefined4 FUN_00813efb(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  for (; (((cVar1 = *param_3, cVar1 == ' ' || (cVar1 == '\t')) || (cVar1 == '\n')) ||
         (cVar1 == '\r')); param_3 = param_3 + 1) {
  }
                    /* WARNING: Could not recover jumptable at 0x00813f6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)PTR_LAB_0081430b)();
  return uVar2;
}


// ==== FUN_0081433b @ 0x0081433b ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0081433b(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  HANDLE hFile;
  BOOL BVar7;
  DWORD *pDVar8;
  DWORD DVar9;
  int iVar10;
  undefined1 local_1008 [4096];
  undefined4 local_8;
  
  iVar10 = 0;
  local_8 = DAT_00b49670 ^ (uint)(local_1008 + 0x1004);
  iVar1 = __lseek_lk(param_1,0,1);
  if ((iVar1 == -1) || (iVar2 = __lseek_lk(param_1,0,2), iVar2 == -1)) {
    iVar10 = -1;
  }
  else {
    iVar2 = param_2 - iVar2;
    if (iVar2 < 1) {
      if (iVar2 < 0) {
        __lseek_lk(param_1,param_2,0);
        hFile = (HANDLE)__get_osfhandle(param_1);
        BVar7 = SetEndOfFile(hFile);
        iVar10 = (BVar7 != 0) - 1;
        if (iVar10 == -1) {
          puVar6 = (undefined4 *)FUN_00804b94();
          *puVar6 = 0xd;
          pDVar8 = (DWORD *)FUN_00804b9d();
          DVar9 = GetLastError();
          *pDVar8 = DVar9;
        }
      }
    }
    else {
      _memset(local_1008,0,0x1000);
      uVar3 = __setmode_lk(param_1,0x8000);
      do {
        iVar4 = 0x1000;
        if (iVar2 < 0x1000) {
          iVar4 = iVar2;
        }
        iVar4 = FUN_0081187e(param_1,local_1008,iVar4);
        if (iVar4 == -1) {
          piVar5 = (int *)FUN_00804b9d();
          if (*piVar5 == 5) {
            puVar6 = (undefined4 *)FUN_00804b94();
            *puVar6 = 0xd;
          }
          iVar10 = -1;
          break;
        }
        iVar2 = iVar2 - iVar4;
      } while (0 < iVar2);
      __setmode_lk(param_1,uVar3);
    }
    __lseek_lk(param_1,iVar1,0);
  }
  return iVar10;
}


// ==== __lseeki64_lk @ 0x00814480 ====

/* Library Function - Single Match
    __lseeki64_lk
   
   Library: Visual Studio 2003 Release */

undefined8 __lseeki64_lk(uint param_1,LONG param_2,LONG param_3,DWORD param_4)

{
  byte *pbVar1;
  HANDLE hFile;
  undefined4 *puVar2;
  DWORD DVar3;
  DWORD DVar4;
  LONG local_8;
  
  local_8 = param_3;
  hFile = (HANDLE)__get_osfhandle(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    puVar2 = (undefined4 *)FUN_00804b94();
    *puVar2 = 9;
LAB_008144da:
    DVar4 = 0xffffffff;
    local_8 = -1;
  }
  else {
    DVar4 = SetFilePointer(hFile,param_2,&local_8,param_4);
    if (DVar4 == 0xffffffff) {
      DVar3 = GetLastError();
      if (DVar3 != 0) {
        __dosmaperr(DVar3);
        goto LAB_008144da;
      }
    }
    pbVar1 = (byte *)((&DAT_00b60fa0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
    *pbVar1 = *pbVar1 & 0xfd;
  }
  return CONCAT44(local_8,DVar4);
}


// ==== __getpath @ 0x00814503 ====

/* Library Function - Single Match
    __getpath
   
   Library: Visual Studio 2003 Release */

char * __cdecl __getpath(char *_Src,char *_Dst,size_t _SizeInChars)

{
  char *pcVar1;
  char cVar2;
  
  for (; *_Src == ';'; _Src = _Src + 1) {
  }
  _SizeInChars = _SizeInChars - 1;
  pcVar1 = _Src;
  if (_SizeInChars != 0) {
    do {
      while( true ) {
        cVar2 = *pcVar1;
        if (cVar2 == '\0') goto LAB_0081455f;
        if (cVar2 == ';') goto LAB_0081455e;
        if (cVar2 != '\"') break;
        pcVar1 = pcVar1 + 1;
        cVar2 = *pcVar1;
        if (cVar2 == '\0') goto LAB_0081455f;
        do {
          if (cVar2 == '\"') break;
          *_Dst = cVar2;
          _Dst = _Dst + 1;
          pcVar1 = pcVar1 + 1;
          _SizeInChars = _SizeInChars - 1;
          if (_SizeInChars == 0) goto LAB_00814531;
          cVar2 = *pcVar1;
        } while (cVar2 != '\0');
        if (*pcVar1 == '\0') goto LAB_0081455f;
        pcVar1 = pcVar1 + 1;
      }
      *_Dst = cVar2;
      _Dst = _Dst + 1;
      pcVar1 = pcVar1 + 1;
      _SizeInChars = _SizeInChars - 1;
    } while (_SizeInChars != 0);
LAB_00814531:
    _Src = pcVar1;
    pcVar1 = _Src;
  }
LAB_00814564:
  *_Dst = '\0';
  return (char *)(-(uint)(_Src != pcVar1) & (uint)pcVar1);
LAB_0081455f:
  for (; *pcVar1 == ';'; pcVar1 = pcVar1 + 1) {
LAB_0081455e:
  }
  goto LAB_00814564;
}


// ==== __mbschr @ 0x00814572 ====

/* Library Function - Single Match
    __mbschr
   
   Library: Visual Studio 2003 Release */

uchar * __cdecl __mbschr(uchar *_Str,uint _Ch)

{
  byte bVar1;
  byte bVar2;
  _ptiddata p_Var3;
  void *pvVar4;
  uchar *puVar5;
  byte *pbVar6;
  uint uVar7;
  
  p_Var3 = __getptd();
  pvVar4 = p_Var3->_tpxcptinfoptrs;
  if (pvVar4 != DAT_00b60d04) {
    pvVar4 = (void *)FUN_0081276a();
  }
  if (*(int *)((int)pvVar4 + 8) == 0) {
    puVar5 = (uchar *)_strchr((char *)_Str,_Ch);
    return puVar5;
  }
  while( true ) {
    bVar2 = *_Str;
    uVar7 = (uint)bVar2;
    if (bVar2 == 0) break;
    if ((*(byte *)(uVar7 + 0x1d + (int)pvVar4) & 4) == 0) {
      pbVar6 = _Str;
      if (_Ch == uVar7) break;
    }
    else {
      bVar1 = _Str[1];
      if (bVar1 == 0) {
        return (uchar *)0x0;
      }
      pbVar6 = _Str + 1;
      if (_Ch == CONCAT11(bVar2,bVar1)) {
        return _Str;
      }
    }
    _Str = pbVar6 + 1;
  }
  return (uchar *)(~-(uint)(_Ch != uVar7) & (uint)_Str);
}


// ==== FUN_008145ed @ 0x008145ed ====

undefined4 FUN_008145ed(int param_1,LPCSTR param_2,char *param_3,LPVOID param_4)

{
  undefined4 *puVar1;
  byte bVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 extraout_EAX;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  _STARTUPINFOA local_6c;
  _PROCESS_INFORMATION local_28;
  char *local_14;
  DWORD local_10;
  uint local_c;
  char local_5;
  
  local_10 = 0;
  local_5 = '\0';
  if ((param_1 != 0) && (param_1 != 1)) {
    if (param_1 < 2) {
LAB_00814620:
      puVar4 = (undefined4 *)FUN_00804b94();
      *puVar4 = 0x16;
      puVar4 = (undefined4 *)FUN_00804b9d();
      *puVar4 = 0;
      return 0xffffffff;
    }
    if (3 < param_1) {
      if (param_1 != 4) goto LAB_00814620;
      local_5 = '\x01';
    }
  }
  local_14 = param_3;
  while (*param_3 != '\0') {
    do {
      pcVar3 = param_3;
      param_3 = pcVar3 + 1;
    } while (*param_3 != '\0');
    pcVar3 = pcVar3 + 2;
    if (*pcVar3 != '\0') {
      *param_3 = ' ';
      param_3 = pcVar3;
    }
  }
  _memset(&local_6c,0,0x44);
  local_6c.cb = 0x44;
  uVar8 = DAT_00b60f80;
  uVar5 = DAT_00b60f80;
  while ((uVar8 != 0 &&
         (uVar5 = uVar5 - 1,
         *(char *)((&DAT_00b60fa0)[(int)uVar5 >> 5] + 4 + (uVar5 & 0x1f) * 0x24) == '\0'))) {
    uVar8 = uVar8 - 1;
  }
  uVar5 = uVar8 * 5 + 4;
  local_6c.cbReserved2 = (WORD)uVar5;
  local_6c.lpReserved2 = (LPBYTE)FUN_0080faf9(uVar5 & 0xffff,1);
  *(uint *)local_6c.lpReserved2 = uVar8;
  local_c = 0;
  puVar6 = (uint *)((int)local_6c.lpReserved2 + 4);
  puVar4 = (undefined4 *)((int)local_6c.lpReserved2 + uVar8 + 4);
  if (0 < (int)uVar8) {
    do {
      puVar1 = (undefined4 *)((&DAT_00b60fa0)[(int)local_c >> 5] + (local_c & 0x1f) * 0x24);
      bVar2 = *(byte *)(puVar1 + 1);
      if ((bVar2 & 0x10) == 0) {
        *(byte *)puVar6 = bVar2;
        *puVar4 = *puVar1;
      }
      else {
        *(byte *)puVar6 = 0;
        *puVar4 = 0xffffffff;
      }
      local_c = local_c + 1;
      puVar6 = (uint *)((int)puVar6 + 1);
      puVar4 = puVar4 + 1;
    } while ((int)local_c < (int)uVar8);
  }
  if (local_5 != '\0') {
    puVar6 = (uint *)((int)local_6c.lpReserved2 + 4);
    iVar7 = 0;
    puVar4 = (undefined4 *)((int)local_6c.lpReserved2 + uVar8 + 4);
    while( true ) {
      if ((int)uVar8 < 3) {
        uVar5 = uVar8;
      }
      else {
        uVar5 = 3;
      }
      if ((int)uVar5 <= iVar7) break;
      *(undefined1 *)puVar6 = 0;
      *puVar4 = 0xffffffff;
      iVar7 = iVar7 + 1;
      puVar6 = (uint *)((int)puVar6 + 1);
      puVar4 = puVar4 + 1;
    }
    local_10 = 8;
  }
  puVar4 = (undefined4 *)FUN_00804b94();
  *puVar4 = 0;
  puVar4 = (undefined4 *)FUN_00804b9d();
  *puVar4 = 0;
  CreateProcessA(param_2,local_14,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,1,local_10,
                 param_4,(LPCSTR)0x0,&local_6c,&local_28);
  GetLastError();
  _free(local_6c.lpReserved2);
  return extraout_EAX;
}


// ==== FUN_008147c7 @ 0x008147c7 ====

undefined4 FUN_008147c7(int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  size_t sVar1;
  void *pvVar2;
  size_t sVar3;
  char *pcVar4;
  undefined4 extraout_EAX;
  undefined4 *puVar5;
  undefined4 extraout_EAX_00;
  char cVar6;
  int *piVar7;
  size_t sVar8;
  undefined1 *puVar9;
  int *piVar10;
  
  sVar8 = 2;
  sVar3 = sVar8;
  for (piVar7 = param_1; (char *)*piVar7 != (char *)0x0; piVar7 = piVar7 + 1) {
    sVar1 = _strlen((char *)*piVar7);
    sVar3 = sVar3 + 1 + sVar1;
  }
  pvVar2 = _malloc(sVar3);
  *param_3 = (int)pvVar2;
  if (pvVar2 == (void *)0x0) {
    *param_4 = 0;
    puVar5 = (undefined4 *)FUN_00804b94();
    *puVar5 = 0xc;
    puVar5 = (undefined4 *)FUN_00804b9d();
    *puVar5 = 8;
    return 0xffffffff;
  }
  piVar7 = param_2;
  if (param_2 == (int *)0x0) {
    *param_4 = 0;
    piVar7 = param_1;
    piVar10 = param_1;
  }
  else {
    for (; (char *)*piVar7 != (char *)0x0; piVar7 = piVar7 + 1) {
      sVar3 = _strlen((char *)*piVar7);
      sVar8 = sVar8 + 1 + sVar3;
    }
    if ((DAT_00b5c61c == (char *)0x0) &&
       (DAT_00b5c61c = (char *)FUN_008080e1(), DAT_00b5c61c == (char *)0x0)) {
      return 0xffffffff;
    }
    piVar7 = (int *)0x0;
    if (*DAT_00b5c61c != '\0') {
      cVar6 = *DAT_00b5c61c;
      pcVar4 = DAT_00b5c61c;
      do {
        if (cVar6 == '=') break;
        sVar3 = _strlen(pcVar4);
        piVar7 = (int *)((int)piVar7 + sVar3 + 1);
        pcVar4 = DAT_00b5c61c + (int)piVar7;
        cVar6 = *pcVar4;
      } while (cVar6 != '\0');
    }
    pcVar4 = DAT_00b5c61c + (int)piVar7;
    piVar10 = piVar7;
    while ((((*pcVar4 == '=' && (pcVar4[1] != '\0')) && (pcVar4[2] == ':')) && (pcVar4[3] == '=')))
    {
      sVar3 = _strlen(pcVar4 + 4);
      piVar10 = (int *)((int)piVar10 + sVar3 + 5);
      pcVar4 = DAT_00b5c61c + (int)piVar10;
    }
    pvVar2 = _malloc((int)piVar10 + (sVar8 - (int)piVar7));
    *param_4 = pvVar2;
    if (pvVar2 == (void *)0x0) {
      _free((void *)*param_3);
      return extraout_EAX;
    }
  }
  puVar9 = (undefined1 *)*param_3;
  param_3 = param_1;
  if (*param_1 == 0) goto LAB_0081493f;
  FUN_00809180(puVar9,*param_1);
  sVar3 = _strlen((char *)*param_1);
  puVar9 = puVar9 + sVar3 + 1;
  param_3 = param_1 + 1;
  while (*param_3 != 0) {
    FUN_00809180(puVar9,*param_3);
    sVar3 = _strlen((char *)*param_3);
    puVar9 = puVar9 + sVar3;
    param_3 = param_3 + 1;
    *puVar9 = 0x20;
LAB_0081493f:
    puVar9 = puVar9 + 1;
  }
  puVar9[-1] = 0;
  *puVar9 = 0;
  puVar9 = (undefined1 *)*param_4;
  if (param_2 != (int *)0x0) {
    _memcpy(puVar9,DAT_00b5c61c + (int)piVar7,(int)piVar10 - (int)piVar7);
    puVar9 = puVar9 + ((int)piVar10 - (int)piVar7);
    for (; *param_2 != 0; param_2 = param_2 + 1) {
      FUN_00809180(puVar9,*param_2);
      sVar3 = _strlen((char *)*param_2);
      puVar9 = puVar9 + sVar3 + 1;
    }
  }
  if (puVar9 != (undefined1 *)0x0) {
    if (puVar9 == (undefined1 *)*param_4) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    *puVar9 = 0;
  }
  _free(DAT_00b5c61c);
  return extraout_EAX_00;
}


// ==== findenv @ 0x008149c2 ====

/* Library Function - Single Match
    _findenv
   
   Library: Visual Studio 2003 Release */

int __cdecl findenv(uchar *param_1)

{
  int iVar1;
  int *piVar2;
  size_t unaff_EDI;
  
  piVar2 = DAT_00b5c740;
  while( true ) {
    if ((uchar *)*piVar2 == (uchar *)0x0) {
      return -((int)piVar2 - (int)DAT_00b5c740 >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,(uchar *)*piVar2,unaff_EDI);
    if ((iVar1 == 0) &&
       ((*(char *)(unaff_EDI + *piVar2) == '=' || (*(char *)(unaff_EDI + *piVar2) == '\0')))) break;
    piVar2 = piVar2 + 1;
  }
  return (int)piVar2 - (int)DAT_00b5c740 >> 2;
}


// ==== copy_environ @ 0x00814a0f ====

/* Library Function - Single Match
    _copy_environ
   
   Library: Visual Studio 2003 Release */

undefined4 * __cdecl copy_environ(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  int *unaff_EDI;
  
  iVar5 = 0;
  if (unaff_EDI == (int *)0x0) {
    return (undefined4 *)0x0;
  }
  iVar1 = *unaff_EDI;
  piVar2 = unaff_EDI;
  while (iVar1 != 0) {
    piVar2 = piVar2 + 1;
    iVar5 = iVar5 + 1;
    iVar1 = *piVar2;
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  pcVar4 = (char *)*unaff_EDI;
  puVar6 = puVar3;
  while (pcVar4 != (char *)0x0) {
    pcVar4 = __strdup(pcVar4);
    *puVar6 = pcVar4;
    puVar6 = puVar6 + 1;
    unaff_EDI = unaff_EDI + 1;
    pcVar4 = (char *)*unaff_EDI;
  }
  *puVar6 = 0;
  return puVar3;
}


// ==== FUN_00814a70 @ 0x00814a70 ====

/* WARNING: Removing unreachable block (ram,0x00814c25) */

undefined4 FUN_00814a70(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  uchar uVar2;
  uchar *_Str;
  int *piVar3;
  uchar *puVar4;
  int iVar5;
  undefined4 extraout_EAX;
  int iVar6;
  size_t sVar7;
  LPCSTR lpName;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  _Str = (uchar *)*param_1;
  if (_Str == (uchar *)0x0) {
    return 0xffffffff;
  }
  puVar4 = __mbschr(_Str,0x3d);
  if (puVar4 == (uchar *)0x0) {
    return 0xffffffff;
  }
  if (_Str == puVar4) {
    return 0xffffffff;
  }
  uVar2 = puVar4[1];
  if (DAT_00b5c740 == DAT_00b5c744) {
    DAT_00b5c740 = (int *)copy_environ();
  }
  if (DAT_00b5c740 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_00b5c748 == (undefined4 *)0x0)) {
      if (uVar2 == '\0') {
        return 0;
      }
      DAT_00b5c740 = _malloc(4);
      if (DAT_00b5c740 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_00b5c740 = 0;
      if (DAT_00b5c748 == (undefined4 *)0x0) {
        DAT_00b5c748 = _malloc(4);
        if (DAT_00b5c748 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_00b5c748 = 0;
      }
    }
    else {
      iVar5 = FUN_00812013();
      if (iVar5 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_00b5c740;
  iVar5 = findenv(_Str);
  if ((-1 < iVar5) && (*piVar3 != 0)) {
    _free((void *)piVar3[iVar5]);
    return extraout_EAX;
  }
  if (uVar2 == '\0') {
    _free(_Str);
    return extraout_EAX_01;
  }
  if (iVar5 < 0) {
    iVar5 = -iVar5;
  }
  iVar6 = FUN_00806326(DAT_00b5c740,iVar5 * 4 + 8);
  if (iVar6 == 0) {
    return 0xffffffff;
  }
  puVar1 = (undefined4 *)(iVar6 + iVar5 * 4);
  puVar1[1] = 0;
  *puVar1 = _Str;
  *param_1 = 0;
  if (param_2 == 0) {
    DAT_00b5c740 = (int *)iVar6;
    return 0;
  }
  DAT_00b5c740 = (int *)iVar6;
  sVar7 = _strlen((char *)_Str);
  lpName = _malloc(sVar7 + 2);
  if (lpName == (LPCSTR)0x0) {
    return 0;
  }
  FUN_00809180(lpName,_Str);
  puVar4[(int)lpName - (int)_Str] = '\0';
  SetEnvironmentVariableA(lpName,(LPCSTR)(puVar4 + ((int)lpName - (int)_Str) + 1));
  _free(lpName);
  return extraout_EAX_00;
}


// ==== FUN_00814c46 @ 0x00814c46 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

int FUN_00814c46(LCID param_1,LCTYPE param_2,LPWSTR param_3,int param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int extraout_EAX;
  undefined1 *puVar7;
  size_t sStackY_4c;
  undefined1 auStack_2a [10];
  int local_20;
  
  if (DAT_00b5cbbc == 0) {
    sStackY_4c = 0x814c69;
    iVar3 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00b5cbbc = 2;
      }
    }
    else {
      DAT_00b5cbbc = 1;
    }
  }
  if (DAT_00b5cbbc == 1) {
    sStackY_4c = 0x814ca5;
    iVar3 = GetLocaleInfoW(param_1,param_2,param_3,param_4);
    return iVar3;
  }
  if ((DAT_00b5cbbc == 2) || (DAT_00b5cbbc == 0)) {
    local_20 = 0;
    bVar2 = false;
    if (param_5 == 0) {
      param_5 = DAT_00b5ca74;
    }
    sStackY_4c = 0x814cd4;
    iVar3 = GetLocaleInfoA(param_1,param_2,(LPSTR)0x0,0);
    if (iVar3 != 0) {
      puVar5 = (undefined1 *)(iVar3 + 3U & 0xfffffffc);
      iVar1 = -(int)puVar5;
      puVar6 = auStack_2a + iVar1 + -0xe;
      if (auStack_2a + -0xe == puVar5) {
        *(int *)(auStack_2a + iVar1 + -0x12) = iVar3;
        *(undefined4 *)(auStack_2a + iVar1 + -0x16) = 0x814d21;
        puVar6 = _malloc(*(size_t *)(auStack_2a + iVar1 + -0x12));
        if (puVar6 == (undefined1 *)0x0) {
          return 0;
        }
        bVar2 = true;
      }
      *(int *)(auStack_2a + iVar1 + -0x12) = iVar3;
      *(undefined1 **)(auStack_2a + iVar1 + -0x16) = puVar6;
      *(LCTYPE *)(auStack_2a + iVar1 + -0x1a) = param_2;
      *(LCID *)(auStack_2a + iVar1 + -0x1e) = param_1;
      puVar7 = auStack_2a + iVar1 + -0x22;
      *(undefined4 *)(auStack_2a + iVar1 + -0x22) = 0x814d3b;
      iVar3 = GetLocaleInfoA(*(LCID *)(auStack_2a + iVar1 + -0x1e),
                             *(LCTYPE *)(auStack_2a + iVar1 + -0x1a),
                             *(LPSTR *)(auStack_2a + iVar1 + -0x16),
                             *(int *)(auStack_2a + iVar1 + -0x12));
      puVar5 = puVar7;
      if (iVar3 != 0) {
        if (param_4 == 0) {
          *(undefined4 *)(puVar7 + -4) = 0;
          *(undefined4 *)(puVar7 + -8) = 0;
        }
        else {
          *(int *)(puVar7 + -4) = param_4;
          *(LPWSTR *)(puVar7 + -8) = param_3;
        }
        *(undefined4 *)(puVar7 + -0xc) = 0xffffffff;
        *(undefined1 **)(puVar7 + -0x10) = puVar6;
        *(undefined4 *)(puVar7 + -0x14) = 1;
        *(int *)(puVar7 + -0x18) = param_5;
        puVar5 = puVar7 + -0x1c;
        *(undefined4 *)(puVar7 + -0x1c) = 0x814d5b;
        local_20 = MultiByteToWideChar(*(UINT *)(puVar7 + -0x18),*(DWORD *)(puVar7 + -0x14),
                                       *(LPCSTR *)(puVar7 + -0x10),*(int *)(puVar7 + -0xc),
                                       *(LPWSTR *)(puVar7 + -8),*(int *)(puVar7 + -4));
      }
      if (bVar2) {
        *(undefined1 **)(puVar5 + -4) = puVar6;
        *(undefined4 *)(puVar5 + -8) = 0x814d69;
        _free(*(void **)(puVar5 + -4));
        return extraout_EAX;
      }
      return local_20;
    }
  }
  return 0;
}


// ==== FUN_00814d02 @ 0x00814d02 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00814d02(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x814d0a;
  __resetstkoflw();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar3 + -4) = *(undefined4 *)(unaff_EBP + -0x20);
  *(undefined4 *)(iVar3 + -8) = 0x814d21;
  pvVar2 = _malloc(*(size_t *)(iVar3 + -4));
  if (pvVar2 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x24) = 1;
    *(undefined4 *)(iVar3 + -4) = *(undefined4 *)(unaff_EBP + -0x20);
    *(void **)(iVar3 + -8) = pvVar2;
    *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + 8);
    puVar4 = (undefined1 *)(iVar3 + -0x14);
    *(undefined4 *)(iVar3 + -0x14) = 0x814d3b;
    iVar3 = GetLocaleInfoA(*(LCID *)(iVar3 + -0x10),*(LCTYPE *)(iVar3 + -0xc),*(LPSTR *)(iVar3 + -8)
                           ,*(int *)(iVar3 + -4));
    puVar5 = puVar4;
    if (iVar3 != 0) {
      if (*(int *)(unaff_EBP + 0x14) == 0) {
        *(undefined4 *)(puVar4 + -4) = 0;
        *(undefined4 *)(puVar4 + -8) = 0;
      }
      else {
        *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(unaff_EBP + 0x14);
        *(undefined4 *)(puVar4 + -8) = *(undefined4 *)(unaff_EBP + 0x10);
      }
      *(undefined4 *)(puVar4 + -0xc) = 0xffffffff;
      *(void **)(puVar4 + -0x10) = pvVar2;
      *(undefined4 *)(puVar4 + -0x14) = 1;
      *(undefined4 *)(puVar4 + -0x18) = *(undefined4 *)(unaff_EBP + 0x18);
      puVar5 = puVar4 + -0x1c;
      *(undefined4 *)(puVar4 + -0x1c) = 0x814d5b;
      iVar3 = MultiByteToWideChar(*(UINT *)(puVar4 + -0x18),*(DWORD *)(puVar4 + -0x14),
                                  *(LPCSTR *)(puVar4 + -0x10),*(int *)(puVar4 + -0xc),
                                  *(LPWSTR *)(puVar4 + -8),*(int *)(puVar4 + -4));
      *(int *)(unaff_EBP + -0x1c) = iVar3;
    }
    if (*(int *)(unaff_EBP + -0x24) != 0) {
      *(void **)(puVar5 + -4) = pvVar2;
      *(undefined4 *)(puVar5 + -8) = 0x814d69;
      _free(*(void **)(puVar5 + -4));
      return extraout_EAX;
    }
    uVar1 = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  *(undefined4 *)(unaff_EBP + -0x38) = 0x814d75;
  return uVar1;
}


// ==== FUN_00814d76 @ 0x00814d76 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

int FUN_00814d76(LCID param_1,LCTYPE param_2,LPSTR param_3,int param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int extraout_EAX;
  undefined1 *puVar7;
  size_t sStackY_4c;
  undefined1 auStack_2a [10];
  int local_20;
  
  if (DAT_00b5cbc0 == 0) {
    sStackY_4c = 0x814d99;
    iVar3 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00b5cbc0 = 2;
      }
    }
    else {
      DAT_00b5cbc0 = 1;
    }
  }
  if ((DAT_00b5cbc0 == 2) || (DAT_00b5cbc0 == 0)) {
    sStackY_4c = 0x814ead;
    iVar3 = GetLocaleInfoA(param_1,param_2,param_3,param_4);
    return iVar3;
  }
  if (DAT_00b5cbc0 == 1) {
    local_20 = 0;
    bVar2 = false;
    if (param_5 == 0) {
      param_5 = DAT_00b5ca74;
    }
    sStackY_4c = 0x814df6;
    iVar3 = GetLocaleInfoW(param_1,param_2,(LPWSTR)0x0,0);
    if (iVar3 != 0) {
      puVar5 = (undefined1 *)(iVar3 * 2 + 3U & 0xfffffffc);
      iVar1 = -(int)puVar5;
      puVar6 = auStack_2a + iVar1 + -0xe;
      if (auStack_2a + -0xe == puVar5) {
        *(int *)(auStack_2a + iVar1 + -0x12) = iVar3 * 2;
        *(undefined4 *)(auStack_2a + iVar1 + -0x16) = 0x814e49;
        puVar6 = _malloc(*(size_t *)(auStack_2a + iVar1 + -0x12));
        if (puVar6 == (undefined1 *)0x0) {
          return 0;
        }
        bVar2 = true;
      }
      *(int *)(auStack_2a + iVar1 + -0x12) = iVar3;
      *(undefined1 **)(auStack_2a + iVar1 + -0x16) = puVar6;
      *(LCTYPE *)(auStack_2a + iVar1 + -0x1a) = param_2;
      *(LCID *)(auStack_2a + iVar1 + -0x1e) = param_1;
      puVar7 = auStack_2a + iVar1 + -0x22;
      *(undefined4 *)(auStack_2a + iVar1 + -0x22) = 0x814e65;
      iVar3 = GetLocaleInfoW(*(LCID *)(auStack_2a + iVar1 + -0x1e),
                             *(LCTYPE *)(auStack_2a + iVar1 + -0x1a),
                             *(LPWSTR *)(auStack_2a + iVar1 + -0x16),
                             *(int *)(auStack_2a + iVar1 + -0x12));
      puVar5 = puVar7;
      if (iVar3 != 0) {
        *(undefined4 *)(puVar7 + -4) = 0;
        *(undefined4 *)(puVar7 + -8) = 0;
        if (param_4 == 0) {
          *(undefined4 *)(puVar7 + -0xc) = 0;
          *(undefined4 *)(puVar7 + -0x10) = 0;
        }
        else {
          *(int *)(puVar7 + -0xc) = param_4;
          *(LPSTR *)(puVar7 + -0x10) = param_3;
        }
        *(undefined4 *)(puVar7 + -0x14) = 0xffffffff;
        *(undefined1 **)(puVar7 + -0x18) = puVar6;
        *(undefined4 *)(puVar7 + -0x1c) = 0;
        *(int *)(puVar7 + -0x20) = param_5;
        puVar5 = puVar7 + -0x24;
        *(undefined4 *)(puVar7 + -0x24) = 0x814e87;
        local_20 = WideCharToMultiByte(*(UINT *)(puVar7 + -0x20),*(DWORD *)(puVar7 + -0x1c),
                                       *(LPCWSTR *)(puVar7 + -0x18),*(int *)(puVar7 + -0x14),
                                       *(LPSTR *)(puVar7 + -0x10),*(int *)(puVar7 + -0xc),
                                       *(LPCSTR *)(puVar7 + -8),*(LPBOOL *)(puVar7 + -4));
      }
      if (bVar2) {
        *(undefined1 **)(puVar5 + -4) = puVar6;
        *(undefined4 *)(puVar5 + -8) = 0x814e95;
        _free(*(void **)(puVar5 + -4));
        return extraout_EAX;
      }
      return local_20;
    }
  }
  return 0;
}


// ==== FUN_00814e29 @ 0x00814e29 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00814e29(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 extraout_EAX;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int unaff_EBP;
  
  iVar4 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar4 + -4) = 0x814e31;
  __resetstkoflw();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = *(int *)(unaff_EBP + -0x24);
  *(int *)(iVar4 + -4) = iVar1 * 2;
  *(undefined4 *)(iVar4 + -8) = 0x814e49;
  pvVar3 = _malloc(*(size_t *)(iVar4 + -4));
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
    *(int *)(iVar4 + -4) = iVar1;
    *(void **)(iVar4 + -8) = pvVar3;
    *(undefined4 *)(iVar4 + -0xc) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(iVar4 + -0x10) = *(undefined4 *)(unaff_EBP + 8);
    puVar5 = (undefined1 *)(iVar4 + -0x14);
    *(undefined4 *)(iVar4 + -0x14) = 0x814e65;
    iVar4 = GetLocaleInfoW(*(LCID *)(iVar4 + -0x10),*(LCTYPE *)(iVar4 + -0xc),
                           *(LPWSTR *)(iVar4 + -8),*(int *)(iVar4 + -4));
    puVar6 = puVar5;
    if (iVar4 != 0) {
      *(undefined4 *)(puVar5 + -4) = 0;
      *(undefined4 *)(puVar5 + -8) = 0;
      if (*(int *)(unaff_EBP + 0x14) == 0) {
        *(undefined4 *)(puVar5 + -0xc) = 0;
        *(undefined4 *)(puVar5 + -0x10) = 0;
      }
      else {
        *(undefined4 *)(puVar5 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
        *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + 0x10);
      }
      *(undefined4 *)(puVar5 + -0x14) = 0xffffffff;
      *(void **)(puVar5 + -0x18) = pvVar3;
      *(undefined4 *)(puVar5 + -0x1c) = 0;
      *(undefined4 *)(puVar5 + -0x20) = *(undefined4 *)(unaff_EBP + 0x18);
      puVar6 = puVar5 + -0x24;
      *(undefined4 *)(puVar5 + -0x24) = 0x814e87;
      iVar4 = WideCharToMultiByte(*(UINT *)(puVar5 + -0x20),*(DWORD *)(puVar5 + -0x1c),
                                  *(LPCWSTR *)(puVar5 + -0x18),*(int *)(puVar5 + -0x14),
                                  *(LPSTR *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                                  *(LPCSTR *)(puVar5 + -8),*(LPBOOL *)(puVar5 + -4));
      *(int *)(unaff_EBP + -0x1c) = iVar4;
    }
    if (*(int *)(unaff_EBP + -0x20) != 0) {
      *(void **)(puVar6 + -4) = pvVar3;
      *(undefined4 *)(puVar6 + -8) = 0x814e95;
      _free(*(void **)(puVar6 + -4));
      return extraout_EAX;
    }
    uVar2 = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  *(undefined4 *)(unaff_EBP + -0x38) = 0x814eb5;
  return uVar2;
}


// ==== ___ascii_strnicmp @ 0x00814ec0 ====

/* Library Function - Single Match
    ___ascii_strnicmp
   
   Library: Visual Studio 2003 Release */

int __cdecl ___ascii_strnicmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = 0;
  if (_MaxCount != 0) {
    do {
      bVar2 = *_Str1;
      cVar1 = *_Str2;
      uVar3 = CONCAT11(bVar2,cVar1);
      if (bVar2 == 0) break;
      uVar3 = CONCAT11(bVar2,cVar1);
      uVar4 = (uint)uVar3;
      if (cVar1 == '\0') break;
      _Str1 = _Str1 + 1;
      _Str2 = _Str2 + 1;
      if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
        uVar4 = (uint)CONCAT11(bVar2 + 0x20,cVar1);
      }
      uVar3 = (ushort)uVar4;
      bVar2 = (byte)uVar4;
      if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
        uVar3 = (ushort)CONCAT31((int3)(uVar4 >> 8),bVar2 + 0x20);
      }
      bVar2 = (byte)(uVar3 >> 8);
      bVar6 = bVar2 < (byte)uVar3;
      if (bVar2 != (byte)uVar3) goto LAB_00814f11;
      _MaxCount = _MaxCount - 1;
    } while (_MaxCount != 0);
    iVar5 = 0;
    bVar2 = (byte)(uVar3 >> 8);
    bVar6 = bVar2 < (byte)uVar3;
    if (bVar2 != (byte)uVar3) {
LAB_00814f11:
      iVar5 = -1;
      if (!bVar6) {
        iVar5 = 1;
      }
    }
  }
  return iVar5;
}


// ==== ___addl @ 0x00814f21 ====

/* Library Function - Single Match
    ___addl
   
   Library: Visual Studio 2003 Release */

undefined4 ___addl(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1 + param_2;
  uVar2 = 0;
  if ((uVar1 < param_1) || (uVar1 < param_2)) {
    uVar2 = 1;
  }
  *param_3 = uVar1;
  return uVar2;
}


// ==== ___add_12 @ 0x00814f42 ====

/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 2003 Release */

void ___add_12(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = ___addl(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = ___addl(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = ___addl(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  ___addl(param_1[2],param_2[2],param_1 + 2);
  return;
}


// ==== ___shl_12 @ 0x00814fa0 ====

/* Library Function - Single Match
    ___shl_12
   
   Library: Visual Studio 2003 Release */

void ___shl_12(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  *param_1 = uVar1 * 2;
  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;
  param_1[2] = param_1[2] << 1 | uVar2 >> 0x1f;
  return;
}


// ==== ___shr_12 @ 0x00814fce ====

/* Library Function - Single Match
    ___shr_12
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void ___shr_12(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}


// ==== FUN_00814ffb @ 0x00814ffb ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00814ffb(char *param_1,int param_2,uint *param_3)

{
  short sVar1;
  uint uVar2;
  int local_20;
  char *local_1c;
  uint local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (int)register0x00000010 - 4U;
  local_1c = param_1;
  sVar1 = 0x404e;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  if (param_2 != 0) {
    local_20 = param_2;
    do {
      local_14 = *param_3;
      local_10 = param_3[1];
      local_c = param_3[2];
      ___shl_12(param_3);
      ___shl_12(param_3);
      ___add_12(param_3,&local_14);
      ___shl_12(param_3);
      local_14 = (uint)*local_1c;
      local_10 = 0;
      local_c = 0;
      ___add_12(param_3,&local_14);
      local_1c = local_1c + 1;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  if (param_3[2] == 0) {
    do {
      sVar1 = sVar1 + -0x10;
      uVar2 = param_3[1] >> 0x10;
      param_3[1] = *param_3 >> 0x10 | param_3[1] << 0x10;
      *param_3 = *param_3 << 0x10;
    } while (uVar2 == 0);
    param_3[2] = uVar2;
  }
  while ((param_3[2] & 0x8000) == 0) {
    ___shl_12(param_3);
    sVar1 = sVar1 + -1;
  }
  *(short *)((int)param_3 + 10) = sVar1;
  return;
}


// ==== FUN_008150e3 @ 0x008150e3 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_008150e3(int param_1,uint param_2,ushort param_3,int param_4,byte param_5,short *param_6)

{
  short *psVar1;
  char cVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  short sVar6;
  int iVar7;
  char *pcVar8;
  int local_38;
  undefined4 local_34;
  short *local_30;
  int local_2c;
  uint local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 uStack_10;
  undefined2 local_e;
  undefined2 uStack_c;
  undefined1 local_a;
  char cStack_9;
  undefined4 local_8;
  
  local_2c = param_1;
  local_28 = param_2;
  local_8 = DAT_00b49670 ^ (int)register0x00000010 - 4U;
  local_24 = CONCAT22(local_24._2_2_,param_3);
  uVar3 = param_3 & 0x7fff;
  local_20 = 0xcc;
  local_1f = 0xcc;
  local_1e = 0xcc;
  local_1d = 0xcc;
  local_1c = 0xcc;
  local_1b = 0xcc;
  local_1a = 0xcc;
  local_19 = 0xcc;
  local_18 = 0xcc;
  local_17 = 0xcc;
  local_16 = 0xfb;
  local_15 = 0x3f;
  local_34 = 1;
  if ((param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar3 == 0) && (param_2 == 0)) && (param_1 == 0)) {
LAB_00815265:
    *(undefined1 *)(param_6 + 2) = 0x30;
LAB_0081536a:
    *param_6 = 0;
    *(undefined1 *)(param_6 + 1) = 0x20;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(undefined1 *)((int)param_6 + 5) = 0;
    local_34 = 1;
  }
  else {
    if ((short)uVar3 == 0x7fff) {
      *param_6 = 1;
      if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {
        if (((param_3 & 0x8000) == 0) || (param_2 != 0xc0000000)) {
          if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_008151db;
          pcVar8 = s_1_INF_00a0bcbc;
        }
        else {
          if (param_1 != 0) {
LAB_008151db:
            pcVar8 = s_1_QNAN_00a0bcb4;
            goto LAB_008151e0;
          }
          pcVar8 = s_1_IND_00a0bcc4;
        }
        FUN_00809180(param_6 + 2,pcVar8);
        *(undefined1 *)((int)param_6 + 3) = 5;
      }
      else {
        pcVar8 = s_1_SNAN_00a0bccc;
LAB_008151e0:
        FUN_00809180(param_6 + 2,pcVar8);
        *(undefined1 *)((int)param_6 + 3) = 6;
      }
      local_34 = 0;
      goto LAB_0081534a;
    }
    local_14 = 0;
    local_12 = (undefined2)param_1;
    uStack_10 = (undefined2)((uint)param_1 >> 0x10);
    sVar6 = (short)(((uVar3 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar3 * 0x4d10 >>
                   0x10);
    local_a = (undefined1)uVar3;
    cStack_9 = (char)(uVar3 >> 8);
    local_e = (undefined2)param_2;
    uStack_c = (undefined2)(param_2 >> 0x10);
    FUN_008155b5(&local_14,-(int)sVar6,1);
    if (0x3ffe < CONCAT11(cStack_9,local_a)) {
      sVar6 = sVar6 + 1;
      FUN_0081537f(&local_14,&local_20);
    }
    *param_6 = sVar6;
    if (((param_5 & 1) != 0) && (param_4 = param_4 + sVar6, param_4 < 1)) goto LAB_00815265;
    if (0x15 < param_4) {
      param_4 = 0x15;
    }
    iVar7 = CONCAT11(cStack_9,local_a) - 0x3ffe;
    local_a = 0;
    cStack_9 = '\0';
    local_30 = (short *)0x8;
    do {
      ___shl_12(&local_14);
      local_30 = (short *)((int)local_30 + -1);
    } while (local_30 != (short *)0x0);
    if (iVar7 < 0) {
      for (uVar3 = -iVar7 & 0xff; uVar3 != 0; uVar3 = uVar3 - 1) {
        ___shr_12(&local_14);
      }
    }
    local_38 = param_4 + 1;
    psVar4 = param_6 + 2;
    if (0 < local_38) {
      local_30 = psVar4;
      do {
        local_2c = CONCAT22(local_12,local_14);
        local_28 = CONCAT22(local_e,uStack_10);
        local_24 = CONCAT13(cStack_9,CONCAT12(local_a,uStack_c));
        ___shl_12(&local_14);
        ___shl_12(&local_14);
        ___add_12(&local_14,&local_2c);
        ___shl_12(&local_14);
        psVar4 = (short *)((int)local_30 + 1);
        local_38 = local_38 + -1;
        *(char *)local_30 = cStack_9 + '0';
        cStack_9 = '\0';
        local_30 = psVar4;
      } while (local_38 != 0);
    }
    psVar5 = psVar4 + -1;
    psVar1 = param_6 + 2;
    if (*(char *)((int)psVar4 + -1) < '5') {
      for (; (psVar1 <= psVar5 && ((char)*psVar5 == '0')); psVar5 = (short *)((int)psVar5 + -1)) {
      }
      if (psVar5 < psVar1) {
        *(char *)psVar1 = '0';
        goto LAB_0081536a;
      }
    }
    else {
      for (; (psVar1 <= psVar5 && ((char)*psVar5 == '9')); psVar5 = (short *)((int)psVar5 + -1)) {
        *(char *)psVar5 = '0';
      }
      if (psVar5 < psVar1) {
        psVar5 = (short *)((int)psVar5 + 1);
        *param_6 = *param_6 + 1;
      }
      *(char *)psVar5 = (char)*psVar5 + '\x01';
    }
    cVar2 = ((char)psVar5 - (char)param_6) + -3;
    *(char *)((int)param_6 + 3) = cVar2;
    *(undefined1 *)(cVar2 + 4 + (int)param_6) = 0;
  }
LAB_0081534a:
  return local_34;
}


// ==== FUN_0081537f @ 0x0081537f ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0081537f(int *param_1,int *param_2)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  ushort uVar8;
  int local_34;
  int local_30;
  ushort *local_2c;
  int local_28;
  ushort *local_24;
  short *local_20;
  int local_1c;
  ushort local_18;
  byte local_14;
  undefined1 uStack_13;
  undefined2 uStack_12;
  short local_10;
  undefined2 uStack_e;
  undefined2 local_c;
  undefined1 uStack_a;
  byte bStack_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (int)register0x00000010 - 4U;
  local_28 = 0;
  local_14 = 0;
  uStack_13 = 0;
  uStack_12 = 0;
  local_10 = 0;
  uStack_e = 0;
  local_c = 0;
  uStack_a = 0;
  bStack_9 = 0;
  uVar6 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  uVar4 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar8 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar3 = uVar6 + uVar4;
  if (((uVar4 < 0x7fff) && (uVar6 < 0x7fff)) && (uVar3 < 0xbffe)) {
    if (uVar3 < 0x3fc0) goto LAB_0081542e;
    if (uVar4 == 0) {
      uVar3 = uVar3 + 1;
      local_18 = 0;
      if ((((param_1[2] & 0x7fffffffU) != 0) || (param_1[1] != 0)) || (*param_1 != 0))
      goto LAB_00815418;
    }
    else {
LAB_00815418:
      if (((uVar6 == 0) && (uVar3 = uVar3 + 1, (param_2[2] & 0x7fffffffU) == 0)) &&
         ((param_2[1] == 0 && (*param_2 == 0)))) {
LAB_0081542e:
        param_1[2] = 0;
        param_1[1] = 0;
        *param_1 = 0;
        return;
      }
      local_30 = 0;
      local_20 = &local_10;
      local_1c = 5;
      do {
        if (0 < local_1c) {
          local_2c = (ushort *)(local_30 * 2 + (int)param_1);
          local_24 = (ushort *)(param_2 + 2);
          local_34 = local_1c;
          do {
            iVar5 = ___addl(*(undefined4 *)(local_20 + -2),(uint)*local_24 * (uint)*local_2c,
                            local_20 + -2);
            if (iVar5 != 0) {
              *local_20 = *local_20 + 1;
            }
            local_2c = local_2c + 1;
            local_24 = local_24 + -1;
            local_34 = local_34 + -1;
          } while (local_34 != 0);
        }
        local_20 = local_20 + 1;
        local_30 = local_30 + 1;
        local_1c = local_1c + -1;
      } while (0 < local_1c);
      local_18 = uVar3 + 0xc002;
      if ((short)local_18 < 1) {
LAB_008154e2:
        local_18 = local_18 - 1;
        if ((short)local_18 < 0) {
          uVar7 = (uint)(ushort)-local_18;
          local_18 = 0;
          do {
            if ((local_14 & 1) != 0) {
              local_28 = local_28 + 1;
            }
            ___shr_12(&local_14);
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
          if (local_28 != 0) {
            local_14 = local_14 | 1;
          }
        }
      }
      else {
        do {
          if ((bStack_9 & 0x80) != 0) break;
          ___shl_12(&local_14);
          local_18 = local_18 - 1;
        } while (0 < (short)local_18);
        if ((short)local_18 < 1) goto LAB_008154e2;
      }
      if ((0x8000 < CONCAT11(uStack_13,local_14)) ||
         (sVar1 = CONCAT11(bStack_9,uStack_a), iVar2 = CONCAT22(local_c,uStack_e),
         iVar5 = CONCAT22(local_10,uStack_12),
         (CONCAT22(uStack_12,CONCAT11(uStack_13,local_14)) & 0x1ffff) == 0x18000)) {
        if (CONCAT22(local_10,uStack_12) == -1) {
          iVar5 = 0;
          if (CONCAT22(local_c,uStack_e) == -1) {
            if (CONCAT11(bStack_9,uStack_a) == -1) {
              local_18 = local_18 + 1;
              sVar1 = -0x8000;
              iVar2 = 0;
              iVar5 = 0;
            }
            else {
              sVar1 = CONCAT11(bStack_9,uStack_a) + 1;
              iVar2 = 0;
              iVar5 = 0;
            }
          }
          else {
            sVar1 = CONCAT11(bStack_9,uStack_a);
            iVar2 = CONCAT22(local_c,uStack_e) + 1;
          }
        }
        else {
          iVar5 = CONCAT22(local_10,uStack_12) + 1;
          sVar1 = CONCAT11(bStack_9,uStack_a);
          iVar2 = CONCAT22(local_c,uStack_e);
        }
      }
      local_10 = (short)((uint)iVar5 >> 0x10);
      uStack_12 = (undefined2)iVar5;
      local_c = (undefined2)((uint)iVar2 >> 0x10);
      uStack_e = (undefined2)iVar2;
      bStack_9 = (byte)((ushort)sVar1 >> 8);
      uStack_a = (undefined1)sVar1;
      if (0x7ffe < local_18) goto LAB_0081558b;
      *(undefined2 *)param_1 = uStack_12;
      *(uint *)((int)param_1 + 2) = CONCAT22(uStack_e,local_10);
      *(uint *)((int)param_1 + 6) = CONCAT13(bStack_9,CONCAT12(uStack_a,local_c));
      local_18 = local_18 | uVar8;
    }
    *(ushort *)((int)param_1 + 10) = local_18;
  }
  else {
LAB_0081558b:
    param_1[1] = 0;
    *param_1 = 0;
    param_1[2] = (-(uint)(uVar8 != 0) & 0x80000000) + 0x7fff8000;
  }
  return;
}


// ==== FUN_008155b5 @ 0x008155b5 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008155b5(undefined2 *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  ushort local_14;
  undefined4 local_12;
  undefined2 uStack_e;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (int)register0x00000010 - 4U;
  iVar3 = 0xb4a3c0;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      iVar3 = 0xb4a520;
    }
    if (param_3 == 0) {
      *param_1 = 0;
    }
    while (param_2 != 0) {
      uVar1 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      iVar3 = iVar3 + 0x54;
      param_2 = uVar1;
      if (uVar2 != 0) {
        puVar4 = (ushort *)(iVar3 + uVar2 * 0xc);
        if (0x7fff < *puVar4) {
          local_14 = (ushort)*(undefined4 *)puVar4;
          local_12._0_2_ = (undefined2)((uint)*(undefined4 *)puVar4 >> 0x10);
          local_12._2_2_ = (undefined2)*(undefined4 *)(puVar4 + 2);
          uStack_e = (undefined2)((uint)*(undefined4 *)(puVar4 + 2) >> 0x10);
          uStack_c = *(undefined4 *)(puVar4 + 4);
          local_12 = CONCAT22(local_12._2_2_,(undefined2)local_12) + -1;
          puVar4 = &local_14;
        }
        FUN_0081537f(param_1,puVar4);
      }
    }
  }
  return;
}


// ==== __setmode_lk @ 0x00815643 ====

/* Library Function - Single Match
    __setmode_lk
   
   Library: Visual Studio 2003 Release */

int __setmode_lk(uint param_1,int param_2)

{
  int *piVar1;
  byte *pbVar2;
  byte bVar3;
  undefined4 *puVar4;
  int iVar5;
  
  piVar1 = &DAT_00b60fa0 + ((int)param_1 >> 5);
  iVar5 = (param_1 & 0x1f) * 0x24;
  bVar3 = *(byte *)(*piVar1 + 4 + iVar5);
  if (param_2 == 0x8000) {
    pbVar2 = (byte *)(*piVar1 + 4 + iVar5);
    *pbVar2 = *pbVar2 & 0x7f;
  }
  else {
    if (param_2 != 0x4000) {
      puVar4 = (undefined4 *)FUN_00804b94();
      *puVar4 = 0x16;
      return -1;
    }
    pbVar2 = (byte *)(*piVar1 + 4 + iVar5);
    *pbVar2 = *pbVar2 | 0x80;
  }
  return (-(uint)((bVar3 & 0x80) != 0) & 0xffffc000) + 0x8000;
}


// ==== FUN_008156b0 @ 0x008156b0 ====

void FUN_008156b0(void)

{
  FUN_008156c0();
  FUN_008156d0();
  return;
}


// ==== FUN_008156c0 @ 0x008156c0 ====

void FUN_008156c0(void)

{
  FUN_0081aee0();
  return;
}


// ==== FUN_008156d0 @ 0x008156d0 ====

void FUN_008156d0(void)

{
  _atexit(FUN_008156e0);
  return;
}


// ==== FUN_008156e0 @ 0x008156e0 ====

void FUN_008156e0(void)

{
  FUN_0081aef0();
  return;
}


// ==== FUN_008156f0 @ 0x008156f0 ====

undefined4 FUN_008156f0(void)

{
  undefined4 uVar1;
  
  if (DAT_00b5cf2c == 0) {
    return 0;
  }
  uVar1 = FUN_00815a70();
  return uVar1;
}


// ==== FUN_00815710 @ 0x00815710 ====

void FUN_00815710(undefined4 param_1)

{
  if (DAT_00b5cf2c != 0) {
    FUN_00817d80(param_1);
  }
  return;
}


// ==== FUN_00815730 @ 0x00815730 ====

undefined4 FUN_00815730(undefined4 param_1)

{
  LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter;
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if (DAT_00b5cf2c != (undefined1 *)0x0) {
    return 0;
  }
  lpTopLevelExceptionFilter =
       SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)&LAB_00819390);
  puVar1 = operator_new(0x1690);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    *(undefined4 *)(puVar1 + 4) = 0;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    *(undefined4 *)(puVar1 + 0x10) = 0;
    *(undefined4 *)(puVar1 + 0x14) = 0;
    *(undefined4 *)(puVar1 + 0x18) = 0;
    puVar1[0x1c] = 0;
    puVar1[0x1d] = 0;
    puVar1[0x1e] = 0;
    puVar1[0x1f] = 0;
    *(undefined4 *)(puVar1 + 0x20) = 0xffffffff;
    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x24));
    *(undefined4 *)(puVar1 + 0x1460) = 0;
    FUN_0081bb90();
    FUN_0081b120();
    *(undefined4 *)(puVar1 + 0x1604) = 0;
    *(undefined4 *)(puVar1 + 0x1628) = 0;
    *(undefined4 *)(puVar1 + 0x162c) = 0;
    puVar1[0x1670] = 0;
    puVar1[0x1671] = 0;
    *(undefined4 *)(puVar1 + 0x1674) = 1000;
    *(undefined4 *)(puVar1 + 0x1678) = 0;
    *(undefined4 *)(puVar1 + 0x167c) = 0;
    *(undefined4 *)(puVar1 + 0x1680) = 0;
    puVar1[0x1684] = 0;
    *(undefined4 *)(puVar1 + 0x1688) = 0;
    *(undefined4 *)(puVar1 + 0x168c) = 0;
    puVar1[0x1630] = 0;
  }
  DAT_00b5cf2c = puVar1;
  uVar2 = FUN_00815ac0(param_1);
  *(undefined4 *)(DAT_00b5cf2c + 0x10) = uVar2;
  if (*(HANDLE *)(DAT_00b5cf2c + 0x18) != (HANDLE)0x0) {
    SetEvent(*(HANDLE *)(DAT_00b5cf2c + 0x18));
  }
  if (lpTopLevelExceptionFilter != (LPTOP_LEVEL_EXCEPTION_FILTER)0x0) {
    SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);
  }
  return *(undefined4 *)(DAT_00b5cf2c + 0x10);
}


// ==== FUN_00815860 @ 0x00815860 ====

undefined1 FUN_00815860(undefined4 param_1)

{
  undefined1 uVar1;
  
  if (DAT_00b5cf2c == 0) {
    return 0;
  }
  uVar1 = FUN_00817fe0(param_1);
  return uVar1;
}


// ==== FUN_00815880 @ 0x00815880 ====

uint FUN_00815880(void)

{
  void *_Memory;
  byte bVar1;
  uint extraout_EAX;
  
  if (DAT_00b5cf2c == (void *)0x0) {
    return 0;
  }
  bVar1 = FUN_00818010();
  _Memory = DAT_00b5cf2c;
  if (DAT_00b5cf2c == (void *)0x0) {
    DAT_00b5cf2c = (void *)0x0;
    return (uint)bVar1;
  }
  FUN_008158d0();
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_008158d0 @ 0x008158d0 ====

void FUN_008158d0(void)

{
  byte *_Dest;
  byte bVar1;
  undefined *puVar2;
  char *_Format;
  byte *pbVar3;
  int in_ECX;
  uint uVar4;
  DWORD nNumberOfBytesToWrite;
  int iVar5;
  int *piVar6;
  DWORD local_10;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00999164;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  FUN_0081b170();
  local_4 = local_4 & 0xffffff00;
  thunk_FUN_0081bdd0();
  piVar6 = (int *)(in_ECX + 0x20);
  local_4 = 2;
  if (*piVar6 != -1) {
    GetLocalTime((LPSYSTEMTIME)(in_ECX + 0x103c));
    if ((*(uint *)(in_ECX + 0x145c) == 0) ||
       (puVar2 = &DAT_00b4a754, *(uint *)(in_ECX + 0x1460) <= *(uint *)(in_ECX + 0x145c))) {
      puVar2 = &DAT_00b5cf64;
    }
    _Dest = (byte *)(in_ECX + 0x3c);
    _Format = (char *)FUN_0081c940(&DAT_00b4a6fc,((LPSYSTEMTIME)(in_ECX + 0x103c))->wYear,
                                   *(undefined2 *)(in_ECX + 0x103e),*(undefined2 *)(in_ECX + 0x1042)
                                   ,*(undefined2 *)(in_ECX + 0x1044),
                                   *(undefined2 *)(in_ECX + 0x1046),*(undefined2 *)(in_ECX + 0x1048)
                                   ,*(undefined2 *)(in_ECX + 0x104a),puVar2);
    _sprintf((char *)_Dest,_Format);
    uVar4 = 0xffffffff;
    pbVar3 = _Dest;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + 1;
    } while (bVar1 != 0);
    nNumberOfBytesToWrite = ~uVar4 - 1;
    if (*(int *)(in_ECX + 0x1458) == 0) {
      FUN_0081c2f0(in_ECX + 0x1050,nNumberOfBytesToWrite,_Dest,_Dest);
    }
    else if (0 < (int)nNumberOfBytesToWrite) {
      pbVar3 = _Dest;
      do {
        iVar5 = *(int *)(in_ECX + 0x1458) + 2;
        *(int *)(in_ECX + 0x1458) = iVar5;
        *pbVar3 = *pbVar3 ^ (char)iVar5 + 0x43U;
        pbVar3 = pbVar3 + 1;
      } while ((int)(pbVar3 + (-0x1c - (int)piVar6)) < (int)nNumberOfBytesToWrite);
    }
    if (*(int *)(in_ECX + 0x145c) != 999) {
      WriteFile((HANDLE)*piVar6,_Dest,nNumberOfBytesToWrite,&local_10,(LPOVERLAPPED)0x0);
    }
    SetEndOfFile((HANDLE)*piVar6);
    CloseHandle((HANDLE)*piVar6);
    *piVar6 = -1;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x24));
  ExceptionList = local_c;
  return;
}


// ==== FUN_00815a70 @ 0x00815a70 ====

undefined4 FUN_00815a70(void)

{
  undefined4 uVar1;
  char *in_ECX;
  
  if (*in_ECX == '\0') {
    uVar1 = FUN_0081c9b0(s_InitNPGameMon___lu_00b4a774,*(undefined4 *)(in_ECX + 0x10));
    FUN_00817c00(in_ECX + 0x20,uVar1);
    return *(undefined4 *)(in_ECX + 0x10);
  }
  uVar1 = FUN_0081c9b0(&DAT_00b4a758);
  FUN_00817c00(in_ECX + 0x20,uVar1);
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00815ac0 @ 0x00815ac0 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x008165c8) */
/* WARNING: Removing unreachable block (ram,0x0081661e) */
/* WARNING: Removing unreachable block (ram,0x00816655) */
/* WARNING: Removing unreachable block (ram,0x00816000) */
/* WARNING: Removing unreachable block (ram,0x00816056) */
/* WARNING: Removing unreachable block (ram,0x0081608d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00815ac0(uchar *param_1)

{
  LPSYSTEMTIME p_Var1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  char cVar5;
  DWORD DVar6;
  int iVar7;
  BOOL BVar8;
  undefined4 uVar9;
  uchar *puVar10;
  HANDLE pvVar11;
  char *pcVar12;
  byte *pbVar13;
  LPCSTR pCVar14;
  DWORD DVar15;
  int iVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  char *in_ECX;
  uint uVar19;
  uint uVar20;
  uchar *puVar21;
  int *piVar22;
  CHAR *pCVar23;
  char *pcVar24;
  char *pcVar25;
  _STARTUPINFOA *p_Var26;
  bool bVar27;
  undefined *puVar28;
  undefined4 *puVar29;
  undefined1 auStack_1136 [2];
  undefined1 *puStack_1134;
  BYTE aBStack_1130 [20];
  byte abStack_111c [64];
  uchar *puStack_10dc;
  undefined4 uStack_10d8;
  _PROCESS_INFORMATION _Stack_10d4;
  DWORD DStack_10c4;
  HANDLE pvStack_10c0;
  HANDLE pvStack_10bc;
  byte abStack_10b8 [16];
  _SECURITY_ATTRIBUTES _Stack_10a8;
  HANDLE pvStack_109c;
  HANDLE pvStack_1098;
  byte abStack_1094 [16];
  _STARTUPINFOA _Stack_1084;
  uchar auStack_1040 [32];
  char acStack_1020 [260];
  uchar auStack_f1c [264];
  CHAR aCStack_e14 [256];
  char acStack_d14 [260];
  undefined4 auStack_c10 [512];
  CHAR aCStack_410 [1028];
  undefined4 uStack_c;
  undefined4 uStack_4;
  
  uStack_4 = 0x815aca;
  if (*in_ECX != '\0') {
    return 0x755;
  }
  cVar5 = FUN_00817e30();
  in_ECX[0x1671] = cVar5;
  DVar6 = GetCurrentProcessId();
  *(DWORD *)(in_ECX + 0x1604) = DVar6;
  DAT_00b5cefc = GetCurrentThreadId();
  __mbsnbcpy((uchar *)(in_ECX + 0x1608),param_1,0x20);
  in_ECX[0x1627] = '\0';
  FUN_00817f00(s_C__Program_Files_Acclaim_2Moons__00b5cbd4,0x104);
  iVar7 = __access(s_C__Program_Files_Acclaim_2Moons__00b5cbd4,0);
  if ((iVar7 == -1) &&
     (BVar8 = CreateDirectoryA(s_C__Program_Files_Acclaim_2Moons__00b5cbd4,
                               (LPSECURITY_ATTRIBUTES)0x0), BVar8 == 0)) {
    GetLastError();
    DVar6 = GetLastError();
    uVar9 = FUN_0081c9b0(&DAT_00b4ae74,DVar6);
    FUN_00817c00(in_ECX + 0x20,uVar9);
    return 0x6f;
  }
  lstrcat(s_C__Program_Files_Acclaim_2Moons__00b5cbd4,&DAT_00b4ae70);
  uVar9 = FUN_0081c9b0(&DAT_00b4ae60);
  lstrcat(s_C__Program_Files_Acclaim_2Moons__00b5cbd4,uVar9);
  piVar22 = (int *)(in_ECX + 0x20);
  aBStack_1130[0] = '\x06';
  aBStack_1130[1] = 2;
  aBStack_1130[2] = 0;
  aBStack_1130[3] = 0;
  aBStack_1130[4] = 0;
  aBStack_1130[5] = 0xa4;
  aBStack_1130[6] = 0;
  aBStack_1130[7] = 0;
  aBStack_1130[8] = 0x52;
  aBStack_1130[9] = 0x53;
  aBStack_1130[10] = 0x41;
  aBStack_1130[0xb] = 0x31;
  aBStack_1130[0xc] = '\0';
  aBStack_1130[0xd] = '\x02';
  aBStack_1130[0xe] = '\0';
  aBStack_1130[0xf] = '\0';
  aBStack_1130[0x10] = 1;
  aBStack_1130[0x11] = 0;
  aBStack_1130[0x12] = 1;
  aBStack_1130[0x13] = 0;
  abStack_111c[0] = 0x69;
  abStack_111c[1] = 0xb3;
  abStack_111c[2] = 0xdd;
  abStack_111c[3] = 0xe8;
  abStack_111c[4] = 0x3d;
  abStack_111c[5] = 0x70;
  abStack_111c[6] = 0xa5;
  abStack_111c[7] = 0xfb;
  abStack_111c[8] = 0xd7;
  abStack_111c[9] = 0xb8;
  abStack_111c[10] = 0xfb;
  abStack_111c[0xb] = 0x60;
  abStack_111c[0xc] = 0x68;
  abStack_111c[0xd] = 0xf;
  abStack_111c[0xe] = 0x99;
  abStack_111c[0xf] = 0xc2;
  abStack_111c[0x10] = 0xb9;
  abStack_111c[0x11] = 0xe4;
  abStack_111c[0x12] = 0x20;
  abStack_111c[0x13] = 0x83;
  abStack_111c[0x14] = 0xb5;
  abStack_111c[0x15] = 0xe6;
  abStack_111c[0x16] = 0x5d;
  abStack_111c[0x17] = 0xbf;
  abStack_111c[0x18] = 0x69;
  abStack_111c[0x19] = 0x62;
  abStack_111c[0x1a] = 0x23;
  abStack_111c[0x1b] = 0x29;
  abStack_111c[0x1c] = 0x6e;
  abStack_111c[0x1d] = 0xe6;
  abStack_111c[0x1e] = 0x68;
  abStack_111c[0x1f] = 0xb;
  abStack_111c[0x20] = 0xea;
  abStack_111c[0x21] = 0xea;
  abStack_111c[0x22] = 0x60;
  abStack_111c[0x23] = 0xde;
  abStack_111c[0x24] = 0xba;
  abStack_111c[0x25] = 0x87;
  abStack_111c[0x26] = 0x7e;
  abStack_111c[0x27] = 0x39;
  abStack_111c[0x28] = 0x37;
  abStack_111c[0x29] = 0x26;
  abStack_111c[0x2a] = 0x45;
  abStack_111c[0x2b] = 0xd7;
  abStack_111c[0x2c] = 0x3b;
  abStack_111c[0x2d] = 0x2a;
  abStack_111c[0x2e] = 0xac;
  abStack_111c[0x2f] = 0x79;
  abStack_111c[0x30] = 0xb0;
  abStack_111c[0x31] = 0x40;
  abStack_111c[0x32] = 0xb2;
  abStack_111c[0x33] = 0x26;
  abStack_111c[0x34] = 0xcb;
  abStack_111c[0x35] = 0xdb;
  abStack_111c[0x36] = 0xb8;
  abStack_111c[0x37] = 0x4d;
  abStack_111c[0x38] = 0x55;
  abStack_111c[0x39] = 0x12;
  abStack_111c[0x3a] = 0x17;
  abStack_111c[0x3b] = 0x65;
  abStack_111c[0x3c] = 0x17;
  abStack_111c[0x3d] = 0xc9;
  abStack_111c[0x3e] = 0x85;
  abStack_111c[0x3f] = 0xba;
  if (*piVar22 == -1) {
    uVar19 = 0xffffffff;
    in_ECX[0x1458] = '\0';
    in_ECX[0x1459] = '\0';
    in_ECX[0x145a] = '\0';
    in_ECX[0x145b] = '\0';
    in_ECX[0x145c] = -0x18;
    in_ECX[0x145d] = '\x03';
    in_ECX[0x145e] = '\0';
    in_ECX[0x145f] = '\0';
    pcVar12 = s_C__Program_Files_Acclaim_2Moons__00b5cbd4;
    do {
      if (uVar19 == 0) break;
      uVar19 = uVar19 - 1;
      cVar5 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar5 != '\0');
    if ((~uVar19 - 1 < 4) || (s_C__Program_Files_Acclaim_2Moons__00b5cbd4[1] == ':')) {
LAB_00815db7:
      puVar21 = auStack_f1c;
    }
    else {
      GetModuleFileNameA((HMODULE)0x0,(LPSTR)auStack_f1c,0x104);
      puVar10 = __mbsrchr(auStack_f1c,0x5c);
      puVar21 = puVar10 + 1;
      if (puVar10 == (uchar *)0x0) goto LAB_00815db7;
    }
    uVar19 = 0xffffffff;
    pcVar12 = s_C__Program_Files_Acclaim_2Moons__00b5cbd4;
    do {
      pcVar25 = pcVar12;
      if (uVar19 == 0) break;
      uVar19 = uVar19 - 1;
      pcVar25 = pcVar12 + 1;
      cVar5 = *pcVar12;
      pcVar12 = pcVar25;
    } while (cVar5 != '\0');
    uVar19 = ~uVar19;
    puVar10 = (uchar *)(pcVar25 + -uVar19);
    for (uVar20 = uVar19 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
      *(undefined4 *)puVar21 = *(undefined4 *)puVar10;
      puVar10 = puVar10 + 4;
      puVar21 = puVar21 + 4;
    }
    for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
      *puVar21 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar21 = puVar21 + 1;
    }
    pvVar11 = CreateFileA((LPCSTR)auStack_f1c,0xc0000000,1,(LPSECURITY_ATTRIBUTES)0x0,2,0x80000080,
                          (HANDLE)0x0);
    *piVar22 = (int)pvVar11;
    if (pvVar11 != (HANDLE)0xffffffff) {
      p_Var1 = (LPSYSTEMTIME)(in_ECX + 0x103c);
      GetLocalTime(p_Var1);
      pcVar12 = (char *)FUN_0081c940(s____________Log_Started_at__04d___00b4ae10,p_Var1->wYear,
                                     *(undefined2 *)(in_ECX + 0x103e),
                                     *(undefined2 *)(in_ECX + 0x1042),
                                     *(undefined2 *)(in_ECX + 0x1044),
                                     *(undefined2 *)(in_ECX + 0x1046),
                                     *(undefined2 *)(in_ECX + 0x1048),
                                     *(undefined2 *)(in_ECX + 0x104a));
      _sprintf(in_ECX + 0x3c,pcVar12);
      uVar19 = 0xffffffff;
      pcVar12 = in_ECX + 0x3c;
      do {
        if (uVar19 == 0) break;
        uVar19 = uVar19 - 1;
        cVar5 = *pcVar12;
        pcVar12 = pcVar12 + 1;
      } while (cVar5 != '\0');
      DVar6 = ~uVar19 - 1;
      if (*(int *)(in_ECX + 0x145c) == 999) {
        DVar6 = 0;
      }
      if (*(int *)(in_ECX + 0x1458) == 0) {
        uVar3 = *(ushort *)(in_ECX + 0x104a);
        DVar15 = GetTickCount();
        uVar19 = ((uint)*(ushort *)(in_ECX + 0x1046) +
                 DVar15 + uVar3 + (uint)*(ushort *)(in_ECX + 0x1048)) *
                 ((uint)*(ushort *)(in_ECX + 0x1042) * (uint)*(ushort *)(in_ECX + 0x103e) *
                  (uint)p_Var1->wYear * (uint)uVar3 + 1) & 0xffff | 0xdc000000;
        *(uint *)(in_ECX + 0x104c) = (uVar19 % 10 ^ 0x55) << 0x10 | uVar19;
        DVar15 = GetTickCount();
        FUN_00801d2d(DVar15);
        iVar7 = 0;
        do {
          iVar16 = _rand();
          abStack_10b8[iVar7] = (byte)iVar16;
          iVar7 = iVar7 + 1;
        } while (iVar7 < 0x10);
        FUN_0081c200(in_ECX + 0x1050,0x10,abStack_10b8);
        BVar8 = CryptAcquireContextA
                          ((HCRYPTPROV *)(auStack_1136 + -0xe),(LPCSTR)0x0,
                           s_Microsoft_Base_Cryptographic_Pro_00b4ade4,1,0xf0000000);
        if (BVar8 != 0) {
          BVar8 = CryptImportKey(0,aBStack_1130,0x54,0,0,(HCRYPTKEY *)(auStack_1136 + -10));
          if (BVar8 != 0) {
            CryptEncrypt(0,0,1,0,(BYTE *)0x0,(DWORD *)(auStack_1136 + -0x12),0);
            puStack_10dc = (uchar *)0xccdd00;
            WriteFile((HANDLE)*piVar22,&puStack_10dc,4,(LPDWORD)(auStack_1136 + -0x12),
                      (LPOVERLAPPED)0x0);
            iVar7 = 0;
            do {
              abStack_1094[iVar7] = abStack_10b8[iVar7] ^ abStack_111c[iVar7];
              iVar7 = iVar7 + 1;
            } while (iVar7 < 0x10);
            WriteFile((HANDLE)*piVar22,abStack_1094,0x10,(LPDWORD)(auStack_1136 + -0x12),
                      (LPOVERLAPPED)0x0);
            CryptDestroyKey(0);
          }
          CryptReleaseContext(0,0);
        }
        FUN_0081c2f0(in_ECX + 0x1050,DVar6,in_ECX + 0x3c,in_ECX + 0x3c);
      }
      else if (0 < (int)DVar6) {
        pbVar13 = (byte *)(in_ECX + 0x3c);
        do {
          iVar7 = *(int *)(in_ECX + 0x1458);
          *(int *)(in_ECX + 0x1458) = iVar7 + 2;
          *pbVar13 = *pbVar13 ^ (char)(iVar7 + 2) + 0x43U;
          pbVar13 = pbVar13 + 1;
        } while ((int)(pbVar13 + (-0x1c - (int)piVar22)) < (int)DVar6);
      }
      goto LAB_008166f5;
    }
  }
  puStack_10dc = __mbsrchr((uchar *)s_C__Program_Files_Acclaim_2Moons__00b5cbd4,0x2e);
  if (puStack_10dc != (uchar *)0x0) {
    iVar7 = 1;
    do {
      puVar21 = puStack_10dc;
      pcVar12 = (char *)FUN_0081c9b0(&DAT_00b4add8,iVar7);
      _sprintf((char *)puVar21,pcVar12);
      aBStack_1130[0] = '\x06';
      aBStack_1130[1] = 2;
      aBStack_1130[2] = 0;
      aBStack_1130[3] = 0;
      aBStack_1130[4] = 0;
      aBStack_1130[5] = 0xa4;
      aBStack_1130[6] = 0;
      aBStack_1130[7] = 0;
      aBStack_1130[8] = 0x52;
      aBStack_1130[9] = 0x53;
      aBStack_1130[10] = 0x41;
      aBStack_1130[0xb] = 0x31;
      aBStack_1130[0xc] = '\0';
      aBStack_1130[0xd] = '\x02';
      aBStack_1130[0xe] = '\0';
      aBStack_1130[0xf] = '\0';
      aBStack_1130[0x10] = 1;
      aBStack_1130[0x11] = 0;
      aBStack_1130[0x12] = 1;
      aBStack_1130[0x13] = 0;
      abStack_111c[0] = 0x69;
      abStack_111c[1] = 0xb3;
      abStack_111c[2] = 0xdd;
      abStack_111c[3] = 0xe8;
      abStack_111c[4] = 0x3d;
      abStack_111c[5] = 0x70;
      abStack_111c[6] = 0xa5;
      abStack_111c[7] = 0xfb;
      abStack_111c[8] = 0xd7;
      abStack_111c[9] = 0xb8;
      abStack_111c[10] = 0xfb;
      abStack_111c[0xb] = 0x60;
      abStack_111c[0xc] = 0x68;
      abStack_111c[0xd] = 0xf;
      abStack_111c[0xe] = 0x99;
      abStack_111c[0xf] = 0xc2;
      abStack_111c[0x10] = 0xb9;
      abStack_111c[0x11] = 0xe4;
      abStack_111c[0x12] = 0x20;
      abStack_111c[0x13] = 0x83;
      abStack_111c[0x14] = 0xb5;
      abStack_111c[0x15] = 0xe6;
      abStack_111c[0x16] = 0x5d;
      abStack_111c[0x17] = 0xbf;
      abStack_111c[0x18] = 0x69;
      abStack_111c[0x19] = 0x62;
      abStack_111c[0x1a] = 0x23;
      abStack_111c[0x1b] = 0x29;
      abStack_111c[0x1c] = 0x6e;
      abStack_111c[0x1d] = 0xe6;
      abStack_111c[0x1e] = 0x68;
      abStack_111c[0x1f] = 0xb;
      abStack_111c[0x20] = 0xea;
      abStack_111c[0x21] = 0xea;
      abStack_111c[0x22] = 0x60;
      abStack_111c[0x23] = 0xde;
      abStack_111c[0x24] = 0xba;
      abStack_111c[0x25] = 0x87;
      abStack_111c[0x26] = 0x7e;
      abStack_111c[0x27] = 0x39;
      abStack_111c[0x28] = 0x37;
      abStack_111c[0x29] = 0x26;
      abStack_111c[0x2a] = 0x45;
      abStack_111c[0x2b] = 0xd7;
      abStack_111c[0x2c] = 0x3b;
      abStack_111c[0x2d] = 0x2a;
      abStack_111c[0x2e] = 0xac;
      abStack_111c[0x2f] = 0x79;
      abStack_111c[0x30] = 0xb0;
      abStack_111c[0x31] = 0x40;
      abStack_111c[0x32] = 0xb2;
      abStack_111c[0x33] = 0x26;
      abStack_111c[0x34] = 0xcb;
      abStack_111c[0x35] = 0xdb;
      abStack_111c[0x36] = 0xb8;
      abStack_111c[0x37] = 0x4d;
      abStack_111c[0x38] = 0x55;
      abStack_111c[0x39] = 0x12;
      abStack_111c[0x3a] = 0x17;
      abStack_111c[0x3b] = 0x65;
      abStack_111c[0x3c] = 0x17;
      abStack_111c[0x3d] = 0xc9;
      abStack_111c[0x3e] = 0x85;
      abStack_111c[0x3f] = 0xba;
      if (*piVar22 == -1) {
        uVar19 = 0xffffffff;
        in_ECX[0x1458] = '\0';
        in_ECX[0x1459] = '\0';
        in_ECX[0x145a] = '\0';
        in_ECX[0x145b] = '\0';
        in_ECX[0x145c] = -0x18;
        in_ECX[0x145d] = '\x03';
        in_ECX[0x145e] = '\0';
        in_ECX[0x145f] = '\0';
        pcVar12 = s_C__Program_Files_Acclaim_2Moons__00b5cbd4;
        do {
          if (uVar19 == 0) break;
          uVar19 = uVar19 - 1;
          cVar5 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar5 != '\0');
        if ((~uVar19 - 1 < 4) || (s_C__Program_Files_Acclaim_2Moons__00b5cbd4[1] == ':')) {
LAB_00816370:
          puVar21 = auStack_f1c;
        }
        else {
          GetModuleFileNameA((HMODULE)0x0,(LPSTR)auStack_f1c,0x104);
          puVar10 = __mbsrchr(auStack_f1c,0x5c);
          puVar21 = puVar10 + 1;
          if (puVar10 == (uchar *)0x0) goto LAB_00816370;
        }
        uVar19 = 0xffffffff;
        pcVar12 = s_C__Program_Files_Acclaim_2Moons__00b5cbd4;
        do {
          pcVar25 = pcVar12;
          if (uVar19 == 0) break;
          uVar19 = uVar19 - 1;
          pcVar25 = pcVar12 + 1;
          cVar5 = *pcVar12;
          pcVar12 = pcVar25;
        } while (cVar5 != '\0');
        uVar19 = ~uVar19;
        puVar10 = (uchar *)(pcVar25 + -uVar19);
        for (uVar20 = uVar19 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
          *(undefined4 *)puVar21 = *(undefined4 *)puVar10;
          puVar10 = puVar10 + 4;
          puVar21 = puVar21 + 4;
        }
        for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
          *puVar21 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar21 = puVar21 + 1;
        }
        pvVar11 = CreateFileA((LPCSTR)auStack_f1c,0xc0000000,1,(LPSECURITY_ATTRIBUTES)0x0,2,
                              0x80000080,(HANDLE)0x0);
        *piVar22 = (int)pvVar11;
        if (pvVar11 != (HANDLE)0xffffffff) {
          p_Var1 = (LPSYSTEMTIME)(in_ECX + 0x103c);
          GetLocalTime(p_Var1);
          pcVar12 = (char *)FUN_0081c940(s____________Log_Started_at__04d___00b4ae10,p_Var1->wYear,
                                         *(undefined2 *)(in_ECX + 0x103e),
                                         *(undefined2 *)(in_ECX + 0x1042),
                                         *(undefined2 *)(in_ECX + 0x1044),
                                         *(undefined2 *)(in_ECX + 0x1046),
                                         *(undefined2 *)(in_ECX + 0x1048),
                                         *(undefined2 *)(in_ECX + 0x104a));
          _sprintf(in_ECX + 0x3c,pcVar12);
          uVar19 = 0xffffffff;
          pcVar12 = in_ECX + 0x3c;
          goto code_r0x00816448;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 10);
  }
  goto LAB_00816705;
  while( true ) {
    uVar19 = uVar19 - 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    if (cVar5 == '\0') break;
code_r0x00816448:
    if (uVar19 == 0) break;
  }
  DVar6 = ~uVar19 - 1;
  if (*(int *)(in_ECX + 0x145c) == 999) {
    DVar6 = 0;
  }
  if (*(int *)(in_ECX + 0x1458) == 0) {
    uVar3 = *(ushort *)(in_ECX + 0x104a);
    DVar15 = GetTickCount();
    uVar19 = ((uint)*(ushort *)(in_ECX + 0x1046) +
             DVar15 + uVar3 + (uint)*(ushort *)(in_ECX + 0x1048)) *
             ((uint)p_Var1->wYear * (uint)*(ushort *)(in_ECX + 0x1042) *
              (uint)*(ushort *)(in_ECX + 0x103e) * (uint)uVar3 + 1) & 0xffff | 0xdc000000;
    *(uint *)(in_ECX + 0x104c) = (uVar19 % 10 ^ 0x55) << 0x10 | uVar19;
    DVar15 = GetTickCount();
    FUN_00801d2d(DVar15);
    iVar7 = 0;
    do {
      iVar16 = _rand();
      abStack_10b8[iVar7] = (byte)iVar16;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x10);
    FUN_0081c200(in_ECX + 0x1050,0x10,abStack_10b8);
    BVar8 = CryptAcquireContextA
                      ((HCRYPTPROV *)(auStack_1136 + -0xe),(LPCSTR)0x0,
                       s_Microsoft_Base_Cryptographic_Pro_00b4ade4,1,0xf0000000);
    if (BVar8 != 0) {
      BVar8 = CryptImportKey(0,aBStack_1130,0x54,0,0,(HCRYPTKEY *)(auStack_1136 + -6));
      if (BVar8 != 0) {
        CryptEncrypt(0,0,1,0,(BYTE *)0x0,(DWORD *)(auStack_1136 + -0x12),0);
        uStack_10d8 = 0xccdd00;
        WriteFile((HANDLE)*piVar22,&uStack_10d8,4,(LPDWORD)(auStack_1136 + -0x12),(LPOVERLAPPED)0x0)
        ;
        iVar7 = 0;
        do {
          abStack_1094[iVar7] = abStack_10b8[iVar7] ^ abStack_111c[iVar7];
          iVar7 = iVar7 + 1;
        } while (iVar7 < 0x10);
        WriteFile((HANDLE)*piVar22,abStack_1094,0x10,(LPDWORD)(auStack_1136 + -0x12),
                  (LPOVERLAPPED)0x0);
        CryptDestroyKey(0);
      }
      CryptReleaseContext(0,0);
    }
    FUN_0081c2f0(in_ECX + 0x1050,DVar6,in_ECX + 0x3c,in_ECX + 0x3c);
  }
  else if (0 < (int)DVar6) {
    pbVar13 = (byte *)(in_ECX + 0x3c);
    do {
      iVar7 = *(int *)(in_ECX + 0x1458);
      *(int *)(in_ECX + 0x1458) = iVar7 + 2;
      *pbVar13 = *pbVar13 ^ (char)(iVar7 + 2) + 0x43U;
      pbVar13 = pbVar13 + 1;
    } while ((int)(pbVar13 + (-0x1c - (int)piVar22)) < (int)DVar6);
  }
LAB_008166f5:
  WriteFile((HANDLE)*piVar22,in_ECX + 0x3c,DVar6,(LPDWORD)&pvStack_10c0,(LPOVERLAPPED)0x0);
LAB_00816705:
  uVar9 = FUN_0081c940(s_____NPGameLib_lib_version__d_____00b4ad90,0x2f,
                       s_Wed_Jun_13_13_53_46_2007_00b4adbc);
  FUN_00817c00(piVar22,uVar9);
  uVar9 = FUN_0081c9b0(&DAT_00b4ad50,*(undefined4 *)(puStack_1134 + 0x1604),uStack_c,FUN_008156f0);
  FUN_00817c00(piVar22,uVar9);
  FUN_008191c0();
  FUN_008192a0();
  if (puStack_1134[0x1684] != '\0') {
    FUN_0081ae00(1);
  }
  iVar7 = FUN_00818530(0x251c);
  if (iVar7 == 0) {
    uVar9 = FUN_0081c9b0(&DAT_00b4ad34);
    FUN_00817c00(piVar22,uVar9);
    return 0x73;
  }
  iVar7 = FUN_00818640(0);
  if (iVar7 == 0) {
    pCVar14 = (LPCSTR)FUN_0081c9b0(&DAT_00b4ad20);
    pvVar11 = OpenEventA(0x100002,0,pCVar14);
    if (pvVar11 == (HANDLE)0x0) {
      return 0x6e;
    }
    DVar6 = WaitForSingleObject(pvVar11,0);
    if (DVar6 == 0x102) {
      SetEvent(pvVar11);
      CloseHandle(pvVar11);
    }
    iVar7 = FUN_00818640(0x251c);
    if (iVar7 == 0) {
      return 0x6e;
    }
    uVar9 = FUN_0081c9b0(&DAT_00b4ad00);
    FUN_00817c00(piVar22,uVar9);
  }
  DVar6 = GetTickCount();
  _Stack_10a8.nLength = 0xc;
  _Stack_10a8.lpSecurityDescriptor = (LPVOID)0x0;
  _Stack_10a8.bInheritHandle = 1;
  pvVar11 = CreateEventA(&_Stack_10a8,0,0,(LPCSTR)0x0);
  *(HANDLE *)(puStack_1134 + 0x1680) = pvVar11;
  if (pvVar11 == (HANDLE)0x0) {
    GetLastError();
    DVar6 = GetLastError();
    puVar28 = &DAT_00b4acdc;
LAB_008168e8:
    uVar9 = FUN_0081c9b0(puVar28,DVar6);
    FUN_00817c00(piVar22,uVar9);
    return 0xab;
  }
  pvVar11 = CreateEventA(&_Stack_10a8,1,0,(LPCSTR)0x0);
  *(HANDLE *)(puStack_1134 + 0x18) = pvVar11;
  if (pvVar11 == (HANDLE)0x0) {
    GetLastError();
    DVar6 = GetLastError();
    puVar28 = &DAT_00b4acb8;
    goto LAB_008168e8;
  }
  pvVar11 = CreateEventA(&_Stack_10a8,0,0,(LPCSTR)0x0);
  *(HANDLE *)(puStack_1134 + 0x167c) = pvVar11;
  if (pvVar11 == (HANDLE)0x0) {
    GetLastError();
    DVar6 = GetLastError();
    puVar28 = &DAT_00b4ac94;
    goto LAB_008168e8;
  }
  uVar9 = FUN_0081c9b0(&DAT_00b4ac8c);
  FUN_00817c00(piVar22,uVar9);
  FUN_00817f50(acStack_1020,0x104);
  uVar19 = 0xffffffff;
  pcVar12 = &DAT_00b4ae70;
  do {
    pcVar25 = pcVar12;
    if (uVar19 == 0) break;
    uVar19 = uVar19 - 1;
    pcVar25 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar25;
  } while (cVar5 != '\0');
  uVar19 = ~uVar19;
  iVar7 = -1;
  pcVar12 = acStack_1020;
  do {
    pcVar24 = pcVar12;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar24 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar24;
  } while (cVar5 != '\0');
  pcVar12 = pcVar25 + -uVar19;
  pcVar25 = pcVar24 + -1;
  for (uVar20 = uVar19 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
    *(undefined4 *)pcVar25 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar25 = pcVar25 + 4;
  }
  for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
    *pcVar25 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar25 = pcVar25 + 1;
  }
  pcVar12 = (char *)FUN_0081c9b0(&DAT_00b4ac78);
  uVar19 = 0xffffffff;
  do {
    pcVar25 = pcVar12;
    if (uVar19 == 0) break;
    uVar19 = uVar19 - 1;
    pcVar25 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar25;
  } while (cVar5 != '\0');
  uVar19 = ~uVar19;
  iVar7 = -1;
  pcVar12 = acStack_1020;
  do {
    pcVar24 = pcVar12;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar24 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar24;
  } while (cVar5 != '\0');
  pcVar12 = pcVar25 + -uVar19;
  pcVar25 = pcVar24 + -1;
  for (uVar20 = uVar19 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
    *(undefined4 *)pcVar25 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar25 = pcVar25 + 4;
  }
  for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
    *pcVar25 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar25 = pcVar25 + 1;
  }
  iVar7 = __access(acStack_1020,0);
  if (iVar7 == -1) {
    uVar9 = FUN_0081c9b0(&DAT_00b4ac64,acStack_1020);
    FUN_00817c00(piVar22,uVar9);
    return 0x99;
  }
  bVar27 = false;
  cVar5 = FUN_0081b1e0(acStack_1020,1);
  if (cVar5 == '\0') {
    bVar4 = false;
    if ((*(int *)(puStack_1134 + 0x1600) == 8) && (DVar15 = GetLastError(), DVar15 == 0x80090006)) {
      bVar4 = true;
    }
    GetLastError();
    uVar9 = *(undefined4 *)(puStack_1134 + 0x1600);
    pcVar12 = acStack_1020;
    DVar15 = GetLastError();
    uVar9 = FUN_0081c9b0(&DAT_00b4ac48,uVar9,DVar15,pcVar12);
    FUN_00817c00(piVar22,uVar9);
    pvVar11 = CreateFileA(acStack_1020,0x80000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (pvVar11 == (HANDLE)0xffffffff) {
      pcVar12 = acStack_1020;
      DVar15 = GetLastError();
      uVar9 = FUN_0081c9b0(&DAT_00b4ac30,DVar15,pcVar12);
      FUN_00817c00(piVar22,uVar9);
    }
    else {
      DVar15 = GetFileSize(pvVar11,(LPDWORD)0x0);
      uVar9 = FUN_0081c9b0(&DAT_00b4ac20,DVar15);
      FUN_00817c00(piVar22,uVar9);
      SetFilePointer(pvVar11,-4,(PLONG)0x0,2);
      ReadFile(pvVar11,auStack_1136 + -6,4,(LPDWORD)&pvStack_10c0,(LPOVERLAPPED)0x0);
      uVar9 = FUN_0081c9b0(&DAT_00b4ac10,0);
      FUN_00817c00(piVar22,uVar9);
      CloseHandle(pvVar11);
    }
    if (!bVar4) {
LAB_00816b95:
      uVar9 = FUN_0081c9b0(&DAT_00b4abd4);
      FUN_00817c00(piVar22,uVar9);
      return 0x7c;
    }
    if ((puStack_1134[0x1671] != '\0') || (cVar5 = FUN_0081a180(), cVar5 == '\0')) {
      return 0x9b;
    }
    cVar5 = FUN_0081b1e0(acStack_1020,1);
    if (cVar5 == '\0') {
      if ((*(int *)(puStack_1134 + 0x1600) == 8) && (DVar15 = GetLastError(), DVar15 == 0x80090006))
      {
        return 0x9b;
      }
      bVar27 = true;
    }
    uVar9 = FUN_0081c9b0(&DAT_00b4abf8);
    FUN_00817c00(piVar22,uVar9);
    if (bVar27) goto LAB_00816b95;
  }
  uVar9 = FUN_0081c9b0(&DAT_00b4abcc);
  FUN_00817c00(piVar22,uVar9);
  p_Var26 = &_Stack_1084;
  for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
    p_Var26->cb = 0;
    p_Var26 = (_STARTUPINFOA *)&p_Var26->lpReserved;
  }
  _Stack_10d4.hProcess = (HANDLE)0x0;
  _Stack_10d4.hThread = (HANDLE)0x0;
  _Stack_1084.cb = 0x44;
  _Stack_10d4.dwProcessId = 0;
  _Stack_10d4.dwThreadId = 0;
  pCVar14 = (LPCSTR)FUN_0081c9b0(&DAT_00b4abb4,DVar6 & 0xfff00000,puStack_1134 + 0x1608,
                                 *(undefined4 *)(puStack_1134 + 0x1680),
                                 *(undefined4 *)(puStack_1134 + 0x18),
                                 *(undefined4 *)(puStack_1134 + 0x1604),DAT_00b5cf18);
  wsprintfA(aCStack_e14,pCVar14);
  FUN_00817c00(piVar22,s_cmd___s_00b4abac,aCStack_e14);
  pbVar13 = (byte *)FUN_0081c8a0(aCStack_e14);
  pCVar23 = aCStack_410;
  uVar19 = 0xffffffff;
  pcVar12 = aCStack_e14;
  do {
    if (uVar19 == 0) break;
    uVar19 = uVar19 - 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar5 != '\0');
  FUN_00817c00(piVar22,s_len___d_00b4aba4,~uVar19 - 1);
  iVar7 = ~uVar19 + 3;
  if (0 < iVar7) {
    do {
      bVar2 = *pbVar13;
      pbVar13 = pbVar13 + 1;
      iVar16 = wsprintfA(pCVar23,s__x_02x_00b4ab9c,(uint)bVar2);
      pCVar23 = pCVar23 + iVar16;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  *pCVar23 = '\0';
  FUN_00817c00(piVar22,s_enc___s_00b4ab94,aCStack_410);
  BVar8 = CreateProcessA(acStack_1020,aCStack_410,(LPSECURITY_ATTRIBUTES)0x0,
                         (LPSECURITY_ATTRIBUTES)0x0,1,0,(LPVOID)0x0,(LPCSTR)0x0,&_Stack_1084,
                         &_Stack_10d4);
  if (BVar8 == 0) {
    GetLastError();
    pCVar23 = aCStack_e14;
    DVar6 = GetLastError();
    uVar9 = FUN_0081c9b0(&DAT_00b4ab6c,acStack_1020,DVar6,pCVar23);
    FUN_00817c00(piVar22,uVar9);
    return 0xaa;
  }
  uVar9 = FUN_0081c9b0(&DAT_00b4ab64);
  FUN_00817c00(piVar22,uVar9);
  pvStack_109c = *(HANDLE *)(puStack_1134 + 0x1680);
  DStack_10c4 = 0;
  pvStack_1098 = _Stack_10d4.hProcess;
  DVar6 = WaitForMultipleObjects(2,&pvStack_109c,0,0xffffffff);
  if (DVar6 != 0) {
    BVar8 = GetExitCodeProcess(_Stack_10d4.hProcess,&DStack_10c4);
    if (BVar8 == 0) {
      DVar6 = GetLastError();
      uVar9 = FUN_0081c9b0(&DAT_00b4ab40,DVar6);
      FUN_00817c00(piVar22,uVar9);
    }
    uVar9 = FUN_0081c9b0(&DAT_00b4ab1c,DStack_10c4);
    FUN_00817c00(piVar22,uVar9);
    CloseHandle(_Stack_10d4.hProcess);
    CloseHandle(_Stack_10d4.hThread);
    return DStack_10c4;
  }
  uVar9 = FUN_0081c9b0(&DAT_00b4ab14);
  FUN_00817c00(piVar22,uVar9);
  uVar9 = FUN_00819be0(&_Stack_10d4);
  CloseHandle(_Stack_10d4.hProcess);
  CloseHandle(_Stack_10d4.hThread);
  FUN_00817f00(acStack_d14,0x104);
  uVar19 = 0xffffffff;
  pcVar12 = &DAT_00b4ae70;
  do {
    pcVar25 = pcVar12;
    if (uVar19 == 0) break;
    uVar19 = uVar19 - 1;
    pcVar25 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar25;
  } while (cVar5 != '\0');
  uVar19 = ~uVar19;
  iVar7 = -1;
  pcVar12 = acStack_d14;
  do {
    pcVar24 = pcVar12;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar24 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar24;
  } while (cVar5 != '\0');
  pcVar12 = pcVar25 + -uVar19;
  pcVar25 = pcVar24 + -1;
  for (uVar20 = uVar19 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
    *(undefined4 *)pcVar25 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar25 = pcVar25 + 4;
  }
  for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
    *pcVar25 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar25 = pcVar25 + 1;
  }
  uVar19 = 0xffffffff;
  pcVar12 = puStack_1134 + 0x1608;
  do {
    pcVar25 = pcVar12;
    if (uVar19 == 0) break;
    uVar19 = uVar19 - 1;
    pcVar25 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar25;
  } while (cVar5 != '\0');
  uVar19 = ~uVar19;
  iVar7 = -1;
  pcVar12 = acStack_d14;
  do {
    pcVar24 = pcVar12;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar24 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar24;
  } while (cVar5 != '\0');
  pcVar12 = pcVar25 + -uVar19;
  pcVar25 = pcVar24 + -1;
  for (uVar20 = uVar19 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
    *(undefined4 *)pcVar25 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar25 = pcVar25 + 4;
  }
  for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
    *pcVar25 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar25 = pcVar25 + 1;
  }
  pcVar12 = (char *)FUN_0081c9b0(&DAT_00b4ab08);
  uVar19 = 0xffffffff;
  do {
    pcVar25 = pcVar12;
    if (uVar19 == 0) break;
    uVar19 = uVar19 - 1;
    pcVar25 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar25;
  } while (cVar5 != '\0');
  uVar19 = ~uVar19;
  iVar7 = -1;
  pcVar12 = acStack_d14;
  do {
    pcVar24 = pcVar12;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar24 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar24;
  } while (cVar5 != '\0');
  pcVar12 = pcVar25 + -uVar19;
  pcVar25 = pcVar24 + -1;
  for (uVar20 = uVar19 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
    *(undefined4 *)pcVar25 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar25 = pcVar25 + 4;
  }
  for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
    *pcVar25 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar25 = pcVar25 + 1;
  }
  cVar5 = FUN_0081b1e0(acStack_d14,1);
  if (cVar5 == '\0') {
    GetLastError();
    puVar21 = *(uchar **)(puStack_1134 + 0x1600);
    DVar6 = GetLastError();
    puVar28 = &DAT_00b4aaf0;
LAB_008174e1:
    uVar9 = FUN_0081c9b0(puVar28,puVar21,DVar6);
    FUN_00817c00(piVar22,uVar9);
    return 0x78;
  }
  iVar7 = FUN_0081c9b0(PTR_DAT_00b4a6dc);
  cVar5 = FUN_0081b5f0(acStack_d14,auStack_c10,0x7ff,iVar7 + 5);
  if (cVar5 == '\0') {
    GetLastError();
    uVar9 = *(undefined4 *)(puStack_1134 + 0x1600);
    DVar6 = GetLastError();
    uVar9 = FUN_0081c9b0(&DAT_00b4aad0,uVar9,DVar6);
    FUN_00817c00(piVar22,uVar9);
    return 0x82;
  }
  uVar17 = FUN_0081c940(&DAT_00b4aac4);
  uVar18 = FUN_0081c940(&DAT_00b4aab8,auStack_1040,0x20,auStack_c10);
  uVar18 = FUN_0081c9b0(&DAT_00b4aaa8,uVar18);
  FUN_0081cc00(uVar17,uVar18);
  iVar7 = __mbsicmp(auStack_1040,puStack_1134 + 0x1608);
  if (iVar7 != 0) {
    uVar9 = FUN_0081c9b0(&DAT_00b4aa90);
    FUN_00817c00(piVar22,uVar9);
    return 0x8e;
  }
  uVar18 = FUN_0081c9b0(&DAT_00b4aa84,1,auStack_c10);
  DAT_00b4a6e0 = FUN_0081cb90(uVar17,uVar18);
  uVar18 = FUN_0081c9b0(&DAT_00b4aa74,100000,auStack_c10);
  DAT_00b5cf00 = FUN_0081cb90(uVar17,uVar18);
  uVar18 = FUN_0081c9b0(&DAT_00b4aa64,0,auStack_c10);
  DAT_00b5cf04 = (HANDLE)FUN_0081cb90(uVar17,uVar18);
  uVar18 = FUN_0081c9b0(&DAT_00b4aa54,0,auStack_c10);
  puStack_10dc = (uchar *)FUN_0081cb90(uVar17,uVar18);
  uVar18 = FUN_0081c9b0(&DAT_00b4aa48,0,auStack_c10);
  uStack_10d8 = FUN_0081cb90(uVar17,uVar18);
  uVar18 = FUN_0081c9b0(&DAT_00b4aa38,0,auStack_c10);
  pvStack_10c0 = (HANDLE)FUN_0081cb90(uVar17,uVar18);
  uVar18 = FUN_0081c9b0(&DAT_00b4aa24,0,auStack_c10);
  uVar19 = FUN_0081cb90(uVar17,uVar18);
  puStack_1134[0x1e] = ~(byte)(uVar19 >> 1) & 1;
  uVar18 = FUN_0081c9b0(&DAT_00b4aa0c,1000,auStack_c10);
  uVar18 = FUN_0081cb90(uVar17,uVar18);
  *(undefined4 *)(puStack_1134 + 0x1674) = uVar18;
  uVar18 = FUN_0081c9b0(&DAT_00b4a9f8,0,auStack_c10);
  uVar17 = FUN_0081cb90(uVar17,uVar18);
  *(undefined4 *)(puStack_1134 + 0x1678) = uVar17;
  puVar29 = auStack_c10;
  for (iVar7 = 0x200; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar29 = 0;
    puVar29 = puVar29 + 1;
  }
  uVar17 = FUN_0081c9b0(&DAT_00b4a9f0);
  FUN_00817c00(piVar22,uVar17);
  FUN_00817f00(&DAT_00b5cde8,0x104);
  uVar19 = 0xffffffff;
  pcVar12 = &DAT_00b4ae70;
  do {
    pcVar25 = pcVar12;
    if (uVar19 == 0) break;
    uVar19 = uVar19 - 1;
    pcVar25 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar25;
  } while (cVar5 != '\0');
  uVar19 = ~uVar19;
  iVar7 = -1;
  pcVar12 = (char *)&DAT_00b5cde8;
  do {
    pcVar24 = pcVar12;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar24 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar24;
  } while (cVar5 != '\0');
  pcVar12 = pcVar25 + -uVar19;
  pcVar25 = pcVar24 + -1;
  for (uVar20 = uVar19 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
    *(undefined4 *)pcVar25 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar25 = pcVar25 + 4;
  }
  for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
    *pcVar25 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar25 = pcVar25 + 1;
  }
  pcVar12 = (char *)FUN_0081c9b0(&DAT_00b4a9e0);
  uVar19 = 0xffffffff;
  do {
    pcVar25 = pcVar12;
    if (uVar19 == 0) break;
    uVar19 = uVar19 - 1;
    pcVar25 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar25;
  } while (cVar5 != '\0');
  uVar19 = ~uVar19;
  iVar7 = -1;
  pcVar12 = (char *)&DAT_00b5cde8;
  do {
    pcVar24 = pcVar12;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar24 = pcVar12 + 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar24;
  } while (cVar5 != '\0');
  pcVar12 = pcVar25 + -uVar19;
  pcVar25 = pcVar24 + -1;
  for (uVar20 = uVar19 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
    *(undefined4 *)pcVar25 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar25 = pcVar25 + 4;
  }
  bVar27 = DAT_00b5cf2c != 0;
  for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
    *pcVar25 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar25 = pcVar25 + 1;
  }
  if (bVar27) {
    uVar17 = FUN_0081c9b0(&DAT_00b4a9bc,*GetProcAddress_exref,GetProcAddress_exref[1],
                          GetProcAddress_exref[2],GetProcAddress_exref[3],GetProcAddress_exref[4]);
    FUN_00817c00(DAT_00b5cf2c + 0x20,uVar17);
    if (DAT_00b5cf2c != 0) {
      uVar17 = FUN_0081c9b0(&DAT_00b4a998,*GetModuleHandleA_exref,GetModuleHandleA_exref[1],
                            GetModuleHandleA_exref[2],GetModuleHandleA_exref[3],
                            GetModuleHandleA_exref[4]);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar17);
    }
  }
  uVar17 = FUN_0081c9b0(&DAT_00b4a990);
  FUN_00817c00(piVar22,uVar17);
  iVar7 = __access((char *)&DAT_00b5cde8,0);
  if (iVar7 == -1) {
    FUN_00817f00(&DAT_00b5cde8,0x104);
    uVar19 = 0xffffffff;
    pcVar12 = &DAT_00b4ae70;
    do {
      pcVar25 = pcVar12;
      if (uVar19 == 0) break;
      uVar19 = uVar19 - 1;
      pcVar25 = pcVar12 + 1;
      cVar5 = *pcVar12;
      pcVar12 = pcVar25;
    } while (cVar5 != '\0');
    uVar19 = ~uVar19;
    iVar7 = -1;
    pcVar12 = (char *)&DAT_00b5cde8;
    do {
      pcVar24 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar24 = pcVar12 + 1;
      cVar5 = *pcVar12;
      pcVar12 = pcVar24;
    } while (cVar5 != '\0');
    pcVar12 = pcVar25 + -uVar19;
    pcVar25 = pcVar24 + -1;
    for (uVar20 = uVar19 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
      *(undefined4 *)pcVar25 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar25 = pcVar25 + 4;
    }
    for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
      *pcVar25 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar25 = pcVar25 + 1;
    }
    pcVar12 = (char *)FUN_0081c9b0(&DAT_00b4a980);
    uVar19 = 0xffffffff;
    do {
      pcVar25 = pcVar12;
      if (uVar19 == 0) break;
      uVar19 = uVar19 - 1;
      pcVar25 = pcVar12 + 1;
      cVar5 = *pcVar12;
      pcVar12 = pcVar25;
    } while (cVar5 != '\0');
    uVar19 = ~uVar19;
    iVar7 = -1;
    pcVar12 = (char *)&DAT_00b5cde8;
    do {
      pcVar24 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar24 = pcVar12 + 1;
      cVar5 = *pcVar12;
      pcVar12 = pcVar24;
    } while (cVar5 != '\0');
    pcVar12 = pcVar25 + -uVar19;
    pcVar25 = pcVar24 + -1;
    for (uVar20 = uVar19 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
      *(undefined4 *)pcVar25 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar25 = pcVar25 + 4;
    }
    for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
      *pcVar25 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar25 = pcVar25 + 1;
    }
    iVar7 = __access((char *)&DAT_00b5cde8,0);
    if (iVar7 == -1) {
      uVar9 = FUN_0081c9b0(&DAT_00b4a964,&DAT_00b5cde8);
      FUN_00817c00(piVar22,uVar9);
      return 0x9a;
    }
  }
  cVar5 = FUN_0081b1e0(&DAT_00b5cde8,1);
  if (cVar5 == '\0') {
    GetLastError();
    uVar9 = *(undefined4 *)(puStack_1134 + 0x1600);
    puVar29 = &DAT_00b5cde8;
    DVar6 = GetLastError();
    uVar9 = FUN_0081c9b0(&DAT_00b4ac48,uVar9,DVar6,puVar29);
    FUN_00817c00(piVar22,uVar9);
    return 0x7a;
  }
  uVar17 = FUN_0081c9b0(&DAT_00b4a95c);
  FUN_00817c00(piVar22,uVar17);
  cVar5 = FUN_0081bc00();
  if (cVar5 == '\0') {
    uVar9 = FUN_0081c9b0(&DAT_00b4a948);
    FUN_00817c00(piVar22,uVar9);
    return 0xa0;
  }
  SetThreadPriority(*(HANDLE *)(puStack_1134 + 0x1464),2);
  uVar17 = FUN_0081c9b0(&DAT_00b4a940);
  FUN_00817c00(piVar22,uVar17);
  DVar6 = GetTickCount();
  if (puStack_10dc < (uchar *)0x2f) {
    DVar6 = 0x2f;
    puVar28 = &DAT_00b4a920;
    puVar21 = puStack_10dc;
    goto LAB_008174e1;
  }
  pvVar11 = *(HANDLE *)(puStack_1134 + 0x1680);
  p_Var26 = &_Stack_1084;
  for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
    p_Var26->cb = 0;
    p_Var26 = (_STARTUPINFOA *)&p_Var26->lpReserved;
  }
  _Stack_10d4.hProcess = (HANDLE)0x0;
  _Stack_1084.cb = 0x44;
  _Stack_10d4.hThread = (HANDLE)0x0;
  _Stack_10d4.dwProcessId = 0;
  _Stack_10d4.dwThreadId = 0;
  ResetEvent(pvVar11);
  uVar17 = FUN_0081b990(puStack_1134 + 0x1608,*(undefined4 *)(puStack_1134 + 0x167c),
                        *(undefined4 *)(puStack_1134 + 0x1680),uStack_10d8);
  uVar17 = FUN_0081b980(uVar17);
  pCVar14 = (LPCSTR)FUN_0081c9b0(&DAT_00b4a8f8,DVar6 & 0xfff00000,
                                 *(undefined4 *)(puStack_1134 + 0x1604),puStack_1134[0x1671],uVar17)
  ;
  wsprintfA(aCStack_e14,pCVar14);
  pbVar13 = (byte *)FUN_0081c8a0(aCStack_e14);
  uVar19 = 0xffffffff;
  pCVar23 = aCStack_410;
  pcVar12 = aCStack_e14;
  do {
    if (uVar19 == 0) break;
    uVar19 = uVar19 - 1;
    cVar5 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar5 != '\0');
  iVar7 = ~uVar19 + 3;
  if (0 < iVar7) {
    do {
      bVar2 = *pbVar13;
      pbVar13 = pbVar13 + 1;
      iVar16 = wsprintfA(pCVar23,s__x_02x_00b4ab9c,(uint)bVar2);
      pCVar23 = pCVar23 + iVar16;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  *pCVar23 = '\0';
  uVar17 = FUN_0081c9b0(&DAT_00b4a8f0);
  FUN_00817c00(piVar22,uVar17);
  if ((DAT_00b5cf18 == 0) && (DAT_00b5cf1c == 0)) {
    BVar8 = CreateProcessA((LPCSTR)&DAT_00b5cde8,aCStack_410,(LPSECURITY_ATTRIBUTES)0x0,
                           (LPSECURITY_ATTRIBUTES)0x0,0,4,(LPVOID)0x0,(LPCSTR)0x0,&_Stack_1084,
                           &_Stack_10d4);
    if (BVar8 == 0) {
      GetLastError();
      pCVar23 = aCStack_e14;
      DVar6 = GetLastError();
      uVar9 = FUN_0081c9b0(&DAT_00b4ab6c,&DAT_00b5cde8,DVar6,pCVar23);
      FUN_00817c00(piVar22,uVar9);
      return 0xaa;
    }
    uVar17 = FUN_0081c9b0(&DAT_00b4a8e4,_Stack_10d4.dwProcessId);
    FUN_00817c00(piVar22,uVar17);
  }
  DAT_00b5cf14 = DAT_00b5cf04;
  if ((DAT_00b5cf04 == (HANDLE)0x0) && (DAT_00b5cf14 = pvStack_10c0, pvStack_10c0 == (HANDLE)0x0)) {
    uVar19 = FUN_008199d0(&DAT_00b5cde8,&DAT_00b4a8d0,uVar9);
    DAT_00b5cf14 = (HANDLE)(uVar19 & 0xff);
  }
  uVar17 = FUN_0081c9b0(&DAT_00b4a8c8);
  FUN_00817c00(piVar22,uVar17);
  iVar7 = FUN_0081bd50();
  if (iVar7 == 0) {
    GetLastError();
    DVar6 = GetLastError();
    uVar9 = FUN_0081c9b0(&DAT_00b4a8b4,DVar6);
    FUN_00817c00(piVar22,uVar9);
    return 0xa0;
  }
  uVar17 = FUN_0081c9b0(&DAT_00b4a884,iVar7);
  FUN_00817c00(piVar22,uVar17);
  if (DAT_00b5cf18 == 0) {
    ResumeThread(_Stack_10d4.hThread);
    pvStack_10c0 = *(HANDLE *)(puStack_1134 + 0x167c);
    pvStack_10bc = _Stack_10d4.hProcess;
    DVar6 = WaitForMultipleObjects(2,&pvStack_10c0,0,DAT_00b5cf00);
    if (DVar6 == 0) goto LAB_00817874;
    pCVar14 = (LPCSTR)FUN_0081c9b0(&DAT_00b4a870);
    pvVar11 = OpenEventA(0x100000,0,pCVar14);
    if (pvVar11 != (HANDLE)0x0) {
      CloseHandle(pvVar11);
      DVar6 = WaitForSingleObject(*(HANDLE *)(puStack_1134 + 0x167c),DAT_00b5cf00);
      if (DVar6 == 0) goto LAB_00817874;
      puVar28 = &DAT_00b4a854;
      goto LAB_00817850;
    }
  }
  else {
    DVar6 = WaitForSingleObject(*(HANDLE *)(puStack_1134 + 0x167c),DAT_00b5cf00);
    if (DVar6 == 0) {
LAB_00817874:
      uVar17 = FUN_0081c9b0(&DAT_00b4a82c);
      FUN_00817c00(piVar22,uVar17);
      DVar6 = WaitForSingleObject(*(HANDLE *)(puStack_1134 + 0x1680),0);
      if (DVar6 != 0) {
        uVar9 = FUN_0081c9b0(&DAT_00b4a814);
        FUN_00817c00(piVar22,uVar9);
        return 0x72;
      }
      pCVar14 = (LPCSTR)FUN_0081c9b0(&DAT_00b4a870);
      pvVar11 = OpenEventA(0x100000,0,pCVar14);
      if (pvVar11 == (HANDLE)0x0) {
        DAT_00b5cf20 = _Stack_10d4.dwProcessId;
        _DAT_00b5cf24 = _Stack_10d4.hProcess;
      }
      else {
        CloseHandle(pvVar11);
        uVar17 = FUN_0081c9b0(&DAT_00b4a808);
        FUN_00817c00(piVar22,uVar17);
      }
      uVar17 = FUN_0081c9b0(&DAT_00b4a800);
      FUN_00817c00(piVar22,uVar17);
      if (DAT_00b5cf14 == (HANDLE)0x0) {
        return 0x7a;
      }
      FUN_0081ae70();
      iVar7 = FUN_008194a0();
      if (iVar7 == 0) {
        FUN_008187b0(puStack_1134 + 0x1464,0x62d,0xb);
      }
      uVar17 = FUN_0081c9b0(&DAT_00b4a7e8,iVar7);
      FUN_00817c00(piVar22,uVar17);
      iVar7 = FUN_008197e0();
      if (iVar7 == 0) {
        FUN_0081bb10(0x8b1,0x630,0xd);
      }
      uVar17 = FUN_0081c9b0(&DAT_00b4a7d0,iVar7);
      FUN_00817c00(piVar22,uVar17);
      if ((puStack_1134[0x1e] == '\0') || (cVar5 = FUN_008180f0(), cVar5 != '\0')) {
        uVar17 = FUN_0081c9b0(&DAT_00b4a7ac);
        FUN_00817c00(piVar22,uVar17);
        FUN_0081bb10(0x8b1,0x611,*(undefined4 *)(puStack_1134 + 0x1604));
        FUN_0081bb10(0x8b1,0x617,uVar9);
        uVar9 = FUN_0081c9b0(&DAT_00b4a78c);
        FUN_00817c00(piVar22,uVar9);
        *puStack_1134 = 1;
        return 0x755;
      }
      uVar9 = FUN_0081c9b0(&DAT_00b4a7b4);
      FUN_00817c00(piVar22,uVar9);
      return 0xdc;
    }
  }
  puVar28 = &DAT_00b4a83c;
LAB_00817850:
  uVar9 = FUN_0081c9b0(puVar28,DAT_00b5cf00);
  FUN_00817c00(piVar22,uVar9);
  return 0x72;
}


// ==== FUN_00817a80 @ 0x00817a80 ====

void FUN_00817a80(void)

{
  LPCRITICAL_SECTION in_ECX;
  
  DeleteCriticalSection(in_ECX);
  return;
}


// ==== FUN_00817a90 @ 0x00817a90 ====

void FUN_00817a90(void)

{
  byte *_Dest;
  byte bVar1;
  int iVar2;
  undefined *puVar3;
  char *_Format;
  byte *pbVar4;
  int *in_ECX;
  uint uVar5;
  DWORD nNumberOfBytesToWrite;
  DWORD local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099917b;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  if (*in_ECX != -1) {
    ExceptionList = &local_c;
    GetLocalTime((LPSYSTEMTIME)(in_ECX + 0x407));
    if ((in_ECX[0x50f] == 0) || (puVar3 = &DAT_00b4a754, (uint)in_ECX[0x510] <= (uint)in_ECX[0x50f])
       ) {
      puVar3 = &DAT_00b5cf64;
    }
    _Dest = (byte *)(in_ECX + 7);
    _Format = (char *)FUN_0081c940(&DAT_00b4a6fc,((LPSYSTEMTIME)(in_ECX + 0x407))->wYear,
                                   *(undefined2 *)((int)in_ECX + 0x101e),
                                   *(undefined2 *)((int)in_ECX + 0x1022),(short)in_ECX[0x409],
                                   *(undefined2 *)((int)in_ECX + 0x1026),(short)in_ECX[0x40a],
                                   *(undefined2 *)((int)in_ECX + 0x102a),puVar3);
    _sprintf((char *)_Dest,_Format);
    uVar5 = 0xffffffff;
    pbVar4 = _Dest;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (bVar1 != 0);
    nNumberOfBytesToWrite = ~uVar5 - 1;
    if (in_ECX[0x50e] == 0) {
      FUN_0081c2f0(in_ECX + 0x40c,nNumberOfBytesToWrite,_Dest,_Dest);
    }
    else if (0 < (int)nNumberOfBytesToWrite) {
      pbVar4 = _Dest;
      do {
        iVar2 = in_ECX[0x50e];
        in_ECX[0x50e] = iVar2 + 2;
        *pbVar4 = *pbVar4 ^ (char)(iVar2 + 2) + 0x43U;
        pbVar4 = pbVar4 + 1;
      } while ((int)(pbVar4 + (-0x1c - (int)in_ECX)) < (int)nNumberOfBytesToWrite);
    }
    if (in_ECX[0x50f] != 999) {
      WriteFile((HANDLE)*in_ECX,_Dest,nNumberOfBytesToWrite,&local_10,(LPOVERLAPPED)0x0);
    }
    SetEndOfFile((HANDLE)*in_ECX);
    CloseHandle((HANDLE)*in_ECX);
    *in_ECX = -1;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 1));
  ExceptionList = local_c;
  return;
}


// ==== FUN_00817c00 @ 0x00817c00 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 FUN_00817c00(int *param_1,char *param_2,char param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  byte *_Dest;
  byte bVar1;
  int iVar2;
  char *_Format;
  byte *pbVar3;
  uint uVar4;
  DWORD nNumberOfBytesToWrite;
  DWORD local_1004;
  char local_1000 [4092];
  undefined4 uStack_4;
  
  uStack_4 = 0x817c0a;
  if (*param_1 != -1) {
    if ((param_1[0x50f] != 0) && (*param_2 != '!')) {
      if ((uint)param_1[0x50f] < (uint)param_1[0x510]) {
        return 0;
      }
      param_1[0x510] = param_1[0x510] + 1;
    }
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 1);
    EnterCriticalSection(lpCriticalSection);
    _vsprintf(local_1000,param_2,&param_3);
    GetLocalTime((LPSYSTEMTIME)(param_1 + 0x407));
    if ((_sprintf != (code)0xcc) && (*WriteFile_exref != (code)0xcc)) {
      _Dest = (byte *)(param_1 + 7);
      _Format = (char *)FUN_0081c940(s__02d__02d__02d__03d__s_00b4ae90,(short)param_1[0x409],
                                     *(undefined2 *)((int)param_1 + 0x1026),(short)param_1[0x40a],
                                     *(undefined2 *)((int)param_1 + 0x102a),local_1000);
      _sprintf((char *)_Dest,_Format);
      uVar4 = 0xffffffff;
      pbVar3 = _Dest;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        bVar1 = *pbVar3;
        pbVar3 = pbVar3 + 1;
      } while (bVar1 != 0);
      nNumberOfBytesToWrite = ~uVar4 - 1;
      if (param_1[0x50e] == 0) {
        FUN_0081c2f0(param_1 + 0x40c,nNumberOfBytesToWrite,_Dest,_Dest);
      }
      else if (0 < (int)nNumberOfBytesToWrite) {
        pbVar3 = _Dest;
        do {
          iVar2 = param_1[0x50e];
          param_1[0x50e] = iVar2 + 2;
          *pbVar3 = *pbVar3 ^ (char)(iVar2 + 2) + 0x43U;
          pbVar3 = pbVar3 + 1;
        } while ((int)(pbVar3 + (-0x1c - (int)param_1)) < (int)nNumberOfBytesToWrite);
      }
      WriteFile((HANDLE)*param_1,_Dest,nNumberOfBytesToWrite,&local_1004,(LPOVERLAPPED)0x0);
      LeaveCriticalSection(lpCriticalSection);
      return 1;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0;
}


// ==== FUN_00817d80 @ 0x00817d80 ====

void FUN_00817d80(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = in_ECX + 0x20;
  uVar2 = FUN_0081c9b0(&DAT_00b4af0c);
  FUN_00817c00(iVar1,uVar2);
  FUN_008191c0();
  FUN_008192a0();
  *(undefined4 *)(in_ECX + 4) = param_1;
  FUN_0081bb10(0x8b1,0x612,param_1);
  if (*(int *)(in_ECX + 8) != 0) {
    uVar2 = FUN_0081c9b0(&DAT_00b4aeec,*(int *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc));
    FUN_00817c00(iVar1,uVar2);
    iVar3 = FUN_0040b270(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc));
    if (iVar3 == 0) {
      uVar2 = FUN_0081c9b0(&DAT_00b4aed0);
      FUN_00817c00(iVar1,uVar2);
    }
  }
  uVar2 = FUN_0081c9b0(&DAT_00b4aeb0);
  FUN_00817c00(iVar1,uVar2);
  return;
}


// ==== FUN_00817e30 @ 0x00817e30 ====

undefined4 FUN_00817e30(void)

{
  LPCSTR pCVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  int in_ECX;
  _OSVERSIONINFOA local_94;
  
  local_94.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&local_94);
  pCVar1 = (LPCSTR)FUN_0081c9b0(&DAT_00b4af50);
  hModule = GetModuleHandleA(pCVar1);
  pCVar1 = (LPCSTR)FUN_0081c9b0(&DAT_00b4af3c);
  pFVar2 = GetProcAddress(hModule,pCVar1);
  if (pFVar2 != (FARPROC)0x0) {
    pCVar1 = (LPCSTR)FUN_0081c9b0(&DAT_00b4af24);
    pFVar2 = GetProcAddress(hModule,pCVar1);
    if ((pFVar2 != (FARPROC)0x0) &&
       ((local_94.dwMajorVersion < 5 ||
        ((local_94.dwMajorVersion == 5 && (local_94.dwMinorVersion == 0)))))) {
      *(undefined1 *)(in_ECX + 0x1684) = 1;
      return 1;
    }
  }
  if (local_94.dwPlatformId != 2) {
    return 0;
  }
  DAT_00b5cf2a = 1;
  if ((local_94.dwMajorVersion == 5) && (local_94.dwMinorVersion == 0)) {
    DAT_00b4a6e4 = DAT_00b4a6e4 * 2;
  }
  return 1;
}


// ==== FUN_00817f00 @ 0x00817f00 ====

undefined4 FUN_00817f00(char *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  FUN_00817f50(param_1,param_2);
  pcVar2 = (char *)FUN_0081c9b0(&DAT_00b4af64);
  uVar3 = 0xffffffff;
  do {
    pcVar6 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar4 = -1;
  do {
    pcVar2 = param_1;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar2 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar2;
  } while (cVar1 != '\0');
  pcVar6 = pcVar6 + -uVar3;
  pcVar2 = pcVar2 + -1;
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return 1;
}


// ==== FUN_00817f50 @ 0x00817f50 ====

undefined4 FUN_00817f50(uchar *param_1,DWORD param_2)

{
  char cVar1;
  DWORD DVar2;
  uchar *puVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  DVar2 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)param_1,param_2);
  if (DVar2 != 0) {
    puVar3 = __mbsrchr(param_1,0x5c);
    if (puVar3 != (uchar *)0x0) {
      *puVar3 = '\0';
      return 1;
    }
    uVar4 = 0xffffffff;
    pcVar6 = &DAT_00b4af74;
    do {
      pcVar7 = pcVar6;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar7 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    puVar3 = (uchar *)(pcVar7 + -uVar4);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)param_1 = *(undefined4 *)puVar3;
      puVar3 = puVar3 + 4;
      param_1 = param_1 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *param_1 = *puVar3;
      puVar3 = puVar3 + 1;
      param_1 = param_1 + 1;
    }
    return 1;
  }
  uVar4 = 0xffffffff;
  pcVar6 = &DAT_00b4af74;
  do {
    pcVar7 = pcVar6;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  puVar3 = (uchar *)(pcVar7 + -uVar4);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)param_1 = *(undefined4 *)puVar3;
    puVar3 = puVar3 + 4;
    param_1 = param_1 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *param_1 = *puVar3;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  }
  return 0;
}


// ==== FUN_00817fe0 @ 0x00817fe0 ====

uint FUN_00817fe0(undefined4 param_1)

{
  uint in_EAX;
  uint uVar1;
  char *in_ECX;
  
  if (*in_ECX == '\0') {
    return in_EAX & 0xffffff00;
  }
  uVar1 = FUN_0081bb10(0x8b1,0x619,param_1);
  return uVar1;
}


// ==== FUN_00818010 @ 0x00818010 ====

undefined4 FUN_00818010(void)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  
  if (in_ECX[1] != '\0') {
    return 1;
  }
  uVar1 = FUN_0081c9b0(&DAT_00b4afb0);
  FUN_00817c00(in_ECX + 0x20,uVar1);
  in_ECX[1] = 1;
  if (in_ECX[0x1c] != '\0') {
    FUN_00818360();
    in_ECX[0x1c] = 0;
  }
  if (*(HANDLE *)(in_ECX + 0x167c) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(in_ECX + 0x167c));
    *(undefined4 *)(in_ECX + 0x167c) = 0;
  }
  if (*(HANDLE *)(in_ECX + 0x18) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(in_ECX + 0x18));
    *(undefined4 *)(in_ECX + 0x18) = 0;
  }
  if (*(HANDLE *)(in_ECX + 0x1680) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(in_ECX + 0x1680));
    *(undefined4 *)(in_ECX + 0x1680) = 0;
  }
  if (in_ECX[0x1684] != '\0') {
    FUN_0081ae00(0);
    FUN_0081ac10();
  }
  if ((DAT_00b4a6e0 != 0) && (DAT_00b5cef4 != 0)) {
    FUN_00818b00();
  }
  uVar1 = FUN_0081c9b0(&DAT_00b4af98);
  FUN_00817c00(in_ECX + 0x20,uVar1);
  *in_ECX = 0;
  uVar1 = FUN_0081bdd0();
  return uVar1;
}


// ==== FUN_008180f0 @ 0x008180f0 ====

undefined4 FUN_008180f0(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  DWORD DVar5;
  HMODULE pHVar6;
  HANDLE pvVar7;
  LPVOID in_ECX;
  uint uVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar12;
  undefined *puVar13;
  DWORD local_108;
  char local_104 [260];
  
  if (*(char *)((int)in_ECX + 0x1c) != '\0') {
    return 1;
  }
  iVar1 = (int)in_ECX + 0x20;
  uVar3 = FUN_0081c9b0(&DAT_00b4b0dc);
  FUN_00817c00(iVar1,uVar3);
  FUN_00817f00(local_104,0x104);
  uVar8 = 0xffffffff;
  pcVar4 = &DAT_00b4ae70;
  do {
    pcVar12 = pcVar4;
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    pcVar12 = pcVar4 + 1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar12;
  } while (cVar2 != '\0');
  uVar8 = ~uVar8;
  iVar9 = -1;
  pcVar4 = local_104;
  do {
    pcVar11 = pcVar4;
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    pcVar11 = pcVar4 + 1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar11;
  } while (cVar2 != '\0');
  pcVar4 = pcVar12 + -uVar8;
  pcVar12 = pcVar11 + -1;
  for (uVar10 = uVar8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar12 = pcVar12 + 4;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pcVar12 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar12 = pcVar12 + 1;
  }
  pcVar4 = (char *)FUN_0081c9b0(&DAT_00b4b0cc);
  uVar8 = 0xffffffff;
  do {
    pcVar12 = pcVar4;
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    pcVar12 = pcVar4 + 1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar12;
  } while (cVar2 != '\0');
  uVar8 = ~uVar8;
  iVar9 = -1;
  pcVar4 = local_104;
  do {
    pcVar11 = pcVar4;
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    pcVar11 = pcVar4 + 1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar11;
  } while (cVar2 != '\0');
  pcVar4 = pcVar12 + -uVar8;
  pcVar12 = pcVar11 + -1;
  for (uVar10 = uVar8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar12 = pcVar12 + 4;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pcVar12 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar12 = pcVar12 + 1;
  }
  uVar3 = FUN_0081c9b0(&DAT_00b4b0c0,local_104);
  FUN_00817c00(iVar1,uVar3);
  cVar2 = FUN_0081b1e0(local_104,1);
  if (cVar2 == '\0') {
    GetLastError();
    uVar3 = *(undefined4 *)((int)in_ECX + 0x1600);
    DVar5 = GetLastError();
    uVar3 = FUN_0081c9b0(&DAT_00b4b0a0,uVar3,DVar5);
    FUN_00817c00(iVar1,uVar3);
    return 0;
  }
  pHVar6 = LoadLibraryA(local_104);
  *(HMODULE *)((int)in_ECX + 0x1628) = pHVar6;
  if (pHVar6 == (HMODULE)0x0) {
    DVar5 = GetLastError();
    puVar13 = &DAT_00b4b084;
  }
  else {
    uVar3 = FUN_00819e40(pHVar6,2);
    *(undefined4 *)((int)in_ECX + 0x1688) = uVar3;
    iVar9 = FUN_00819e40(*(undefined4 *)((int)in_ECX + 0x1628),1);
    *(int *)((int)in_ECX + 0x168c) = iVar9;
    if ((*(int *)((int)in_ECX + 0x1688) == 0) || (iVar9 == 0)) {
      DVar5 = GetLastError();
      puVar13 = &DAT_00b4afcc;
    }
    else {
      pvVar7 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
      *(HANDLE *)((int)in_ECX + 0x14) = pvVar7;
      if (pvVar7 == (HANDLE)0x0) {
        DVar5 = GetLastError();
        puVar13 = &DAT_00b4b05c;
      }
      else {
        *(undefined1 *)((int)in_ECX + 0x1c) = 1;
        pvVar7 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00818440,in_ECX,0,&local_108);
        *(HANDLE *)((int)in_ECX + 0x162c) = pvVar7;
        if (pvVar7 == (HANDLE)0x0) {
          DVar5 = GetLastError();
          puVar13 = &DAT_00b4b038;
        }
        else {
          uVar3 = FUN_0081c9b0(&DAT_00b4b014,local_108);
          FUN_00817c00(iVar1,uVar3);
          DVar5 = (**(code **)((int)in_ECX + 0x1688))
                            (*(undefined4 *)((int)in_ECX + 0x1604),
                             *(undefined4 *)((int)in_ECX + 0x1678),
                             *(undefined4 *)((int)in_ECX + 0x1674),
                             *(undefined4 *)((int)in_ECX + 0x14));
          if (DVar5 == 0x6b) {
            uVar3 = FUN_0081c9b0(&DAT_00b4afe4);
            FUN_00817c00(iVar1,uVar3);
            return 1;
          }
          puVar13 = &DAT_00b4aff8;
        }
      }
    }
  }
  uVar3 = FUN_0081c9b0(puVar13,DVar5);
  FUN_00817c00(iVar1,uVar3);
  return 0;
}


// ==== FUN_00818360 @ 0x00818360 ====

undefined4 FUN_00818360(void)

{
  int iVar1;
  undefined4 uVar2;
  DWORD DVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x1c) == '\0') {
    return 1;
  }
  iVar1 = in_ECX + 0x20;
  uVar2 = FUN_0081c9b0(&DAT_00b4b11c);
  FUN_00817c00(iVar1,uVar2);
  (**(code **)(in_ECX + 0x168c))(*(undefined4 *)(in_ECX + 0x1604),in_ECX + 0x1630);
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  if (*(HANDLE *)(in_ECX + 0x14) != (HANDLE)0x0) {
    SetEvent(*(HANDLE *)(in_ECX + 0x14));
  }
  DVar3 = WaitForSingleObject(*(HANDLE *)(in_ECX + 0x162c),2000);
  if (DVar3 == 0x102) {
    uVar2 = FUN_0081c9b0(&DAT_00b4b104);
    FUN_00817c00(iVar1,uVar2);
    TerminateThread(*(HANDLE *)(in_ECX + 0x162c),0);
  }
  CloseHandle(*(HANDLE *)(in_ECX + 0x162c));
  if (*(HMODULE *)(in_ECX + 0x1628) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(in_ECX + 0x1628));
  }
  *(undefined4 *)(in_ECX + 0x1688) = 0;
  *(undefined4 *)(in_ECX + 0x168c) = 0;
  uVar2 = FUN_0081c9b0(&DAT_00b4b0f0);
  FUN_00817c00(iVar1,uVar2);
  return 1;
}


// ==== FUN_00818440 @ 0x00818440 ====

undefined4 FUN_00818440(int param_1)

{
  DWORD DVar1;
  int iVar2;
  undefined4 uVar3;
  
  while( true ) {
    while( true ) {
      DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x14),0xde3);
      if (DVar1 == 0) break;
      iVar2 = FUN_00819700();
      if (iVar2 == 0) {
        FUN_008187b0(param_1 + 0x1464,0x62d,10);
      }
      else {
        iVar2 = FUN_00819930();
        if (iVar2 == 0) {
          FUN_0081bb10(0x8b1,0x630,0xc);
        }
        else {
          iVar2 = FUN_00818760();
          if ((iVar2 != 0) || (*(char *)(param_1 + 0x1d) != '\0')) {
            if (DAT_00b5cf2c != 0) {
              uVar3 = FUN_00818760(*(undefined1 *)(param_1 + 0x1d));
              uVar3 = FUN_0081c9b0(&DAT_00b4b130,uVar3);
              FUN_00817c00(DAT_00b5cf2c + 0x20,uVar3);
            }
            FUN_008187b0(param_1 + 0x1464,500,0);
          }
        }
      }
    }
    if (*(char *)(param_1 + 0x1c) == '\0') break;
    FUN_008187b0(param_1 + 0x1464,0x62d,0);
  }
  return 0;
}


// ==== FUN_00818530 @ 0x00818530 ====

undefined4 FUN_00818530(DWORD param_1)

{
  BOOL BVar1;
  LPCSTR pCVar2;
  HANDLE hHandle;
  DWORD DVar3;
  undefined4 uVar4;
  int in_ECX;
  _SECURITY_ATTRIBUTES *lpMutexAttributes;
  _SECURITY_ATTRIBUTES local_20;
  undefined1 local_14 [20];
  
  local_20.lpSecurityDescriptor = local_14;
  local_20.nLength = 0xc;
  local_20.bInheritHandle = 0;
  lpMutexAttributes = (LPSECURITY_ATTRIBUTES)0x0;
  BVar1 = InitializeSecurityDescriptor(local_14,1);
  if (BVar1 != 0) {
    BVar1 = SetSecurityDescriptorDacl(local_14,1,(PACL)0x0,0);
    if (BVar1 != 0) {
      lpMutexAttributes = &local_20;
    }
  }
  pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4b174);
  hHandle = CreateMutexA(lpMutexAttributes,0,pCVar2);
  if (hHandle == (HANDLE)0x0) {
    pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4b168);
    hHandle = CreateMutexA(lpMutexAttributes,0,pCVar2);
    if (hHandle == (HANDLE)0x0) {
      GetLastError();
      DVar3 = GetLastError();
      uVar4 = FUN_0081c9b0(&DAT_00b4b144,DVar3);
      FUN_00817c00(in_ECX + 0x20,uVar4);
      return 0;
    }
  }
  DVar3 = GetLastError();
  if (DVar3 == 0xb7) {
    CloseHandle(hHandle);
    return 0;
  }
  DVar3 = WaitForSingleObject(hHandle,param_1);
  if (DVar3 == 0x102) {
    CloseHandle(hHandle);
    return 0;
  }
  return 1;
}


// ==== FUN_00818640 @ 0x00818640 ====

undefined4 FUN_00818640(DWORD param_1)

{
  BOOL BVar1;
  LPCSTR pCVar2;
  HANDLE hHandle;
  DWORD DVar3;
  undefined4 uVar4;
  int in_ECX;
  _SECURITY_ATTRIBUTES *lpMutexAttributes;
  _SECURITY_ATTRIBUTES local_20;
  undefined1 local_14 [20];
  
  local_20.lpSecurityDescriptor = local_14;
  local_20.nLength = 0xc;
  local_20.bInheritHandle = 0;
  lpMutexAttributes = (LPSECURITY_ATTRIBUTES)0x0;
  BVar1 = InitializeSecurityDescriptor(local_14,1);
  if (BVar1 != 0) {
    BVar1 = SetSecurityDescriptorDacl(local_14,1,(PACL)0x0,0);
    if (BVar1 != 0) {
      lpMutexAttributes = &local_20;
    }
  }
  pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4af84);
  hHandle = CreateMutexA(lpMutexAttributes,0,pCVar2);
  if (hHandle == (HANDLE)0x0) {
    pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4af78);
    hHandle = CreateMutexA(lpMutexAttributes,0,pCVar2);
    if (hHandle == (HANDLE)0x0) {
      GetLastError();
      DVar3 = GetLastError();
      uVar4 = FUN_0081c9b0(&DAT_00b4b1a4,DVar3);
      FUN_00817c00(in_ECX + 0x20,uVar4);
      return 0;
    }
  }
  DVar3 = GetLastError();
  if (DVar3 == 0xb7) {
    DVar3 = WaitForSingleObject(hHandle,param_1);
    if (DVar3 == 0x102) {
      uVar4 = FUN_0081c9b0(&DAT_00b4b188);
      FUN_00817c00(in_ECX + 0x20,uVar4);
      CloseHandle(hHandle);
      return 0;
    }
  }
  ReleaseMutex(hHandle);
  CloseHandle(hHandle);
  return 1;
}


// ==== FUN_00818760 @ 0x00818760 ====

undefined1 FUN_00818760(void)

{
  int in_ECX;
  
  if (DAT_00b5cf29 != '\0') {
    return 0;
  }
  if (*(char *)(in_ECX + 0x1671) == '\0') {
    return ClientId.UniqueProcess._0_1_;
  }
  return *(undefined1 *)((int)ProcessEnvironmentBlock + 2);
}


// ==== FUN_008187b0 @ 0x008187b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008187b0(undefined4 param_1,int param_2,uint param_3)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  
  if (DAT_00b5cf2c != (char *)0x0) {
    uVar3 = FUN_0081c9b0(&DAT_00b4b250,param_2,param_3);
    FUN_00817c00(DAT_00b5cf2c + 0x20,uVar3);
  }
  switch(param_2) {
  case 0x60f:
    uVar3 = 0x3e9;
    bVar5 = *DAT_00b5cf2c == '\0';
    goto LAB_00818810;
  case 0x610:
    uVar3 = 0x3ea;
    bVar5 = *DAT_00b5cf2c == '\0';
    goto LAB_0081882d;
  default:
    if (param_2 == 500) {
      uVar3 = 0x3f6;
      param_3 = 500;
      bVar5 = *(int *)(DAT_00b5cf2c + 4) == 0;
    }
    else {
      uVar3 = 1000;
      bVar5 = *(int *)(DAT_00b5cf2c + 4) == 0;
    }
    goto LAB_0081882d;
  case 0x615:
    _DAT_00b5cf10 = param_3;
    if (DAT_00b5cf20 == 0) {
      DAT_00b5cf20 = param_3;
    }
    else if (param_3 != DAT_00b5cf20) {
      if (DAT_00b5cf2c != (char *)0x0) {
        uVar3 = FUN_0081c9b0(&DAT_00b4b1c8,param_3,DAT_00b5cf20);
        FUN_00817c00(DAT_00b5cf2c + 0x20,uVar3);
      }
      DAT_00b5cef4 = 2;
      uVar3 = 0x3f6;
      param_3 = 0xe6;
      bVar5 = *(int *)(DAT_00b5cf2c + 4) == 0;
      goto LAB_0081882d;
    }
    cVar2 = FUN_00819c80(&DAT_00b5cde8,0x7d6,10,5,1);
    if (cVar2 != '\0') {
      return 1;
    }
    if (DAT_00b5cf2c != (char *)0x0) {
      uVar3 = FUN_0081c9b0(&DAT_00b4b1f0);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar3);
    }
    uVar3 = 0x3f6;
    param_3 = 0xe6;
    bVar5 = *(int *)(DAT_00b5cf2c + 4) == 0;
    goto LAB_00818810;
  case 0x618:
    if (param_3 < (uint)(DAT_00b4a6e4 * 800)) {
      return 1;
    }
    FUN_008191c0();
    FUN_008192a0();
    if (DAT_00b5cf2c != (char *)0x0) {
      uVar3 = FUN_0081c9b0(&DAT_00b4b238,param_3);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar3);
    }
    uVar3 = 0x3e9;
    break;
  case 0x619:
    param_3 = FUN_0081b9a0();
    uVar3 = 0x3f9;
    break;
  case 0x62d:
    uVar3 = 0x3f3;
    goto LAB_00818907;
  case 0x62e:
    uVar3 = 0x3f4;
    bVar5 = *(int *)(DAT_00b5cf2c + 4) == 0;
    goto LAB_00818810;
  case 0x62f:
    uVar3 = 0x3f5;
    bVar5 = *(int *)(DAT_00b5cf2c + 4) == 0;
    goto LAB_0081882d;
  case 0x630:
    uVar3 = 0x3f7;
LAB_00818907:
    if (*(int *)(DAT_00b5cf2c + 4) == 0) {
      *(undefined4 *)(DAT_00b5cf2c + 8) = uVar3;
      *(uint *)(DAT_00b5cf2c + 0xc) = param_3;
      return 1;
    }
    break;
  case 0x637:
    uVar3 = 0x3f6;
    param_3 = 0xd2;
    bVar5 = *(int *)(DAT_00b5cf2c + 4) == 0;
LAB_00818810:
    if (bVar5) {
      *(undefined4 *)(DAT_00b5cf2c + 8) = uVar3;
      *(uint *)(DAT_00b5cf2c + 0xc) = param_3;
      return 1;
    }
    break;
  case 0x638:
    uVar3 = 0x3f6;
    param_3 = 0xdc;
    bVar5 = *(int *)(DAT_00b5cf2c + 4) == 0;
LAB_0081882d:
    if (bVar5) {
      *(undefined4 *)(DAT_00b5cf2c + 8) = uVar3;
      *(uint *)(DAT_00b5cf2c + 0xc) = param_3;
      return 1;
    }
    break;
  case 0x639:
    uVar3 = 0x3f6;
    param_3 = 0xe6;
    if (*(int *)(DAT_00b5cf2c + 4) == 0) {
      pcVar1 = DAT_00b5cf2c;
      pcVar1[8] = -10;
      pcVar1[9] = '\x03';
      pcVar1[10] = '\0';
      pcVar1[0xb] = '\0';
      pcVar1 = DAT_00b5cf2c;
      pcVar1[0xc] = -0x1a;
      pcVar1[0xd] = '\0';
      pcVar1[0xe] = '\0';
      pcVar1[0xf] = '\0';
      return 1;
    }
    break;
  case 0x63a:
    if (DAT_00b5cf2c != (char *)0x0) {
      uVar3 = FUN_0081c9b0(&DAT_00b4b204,param_3);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar3);
    }
    uVar3 = 0x3f8;
  }
  iVar4 = FUN_0040b270(uVar3,param_3);
  if (iVar4 != 0) {
    return 1;
  }
  if (DAT_00b5cf2c != (char *)0x0) {
    uVar3 = FUN_0081c9b0(&DAT_00b4b218,uVar3,param_3);
    FUN_00817c00(DAT_00b5cf2c + 0x20,uVar3);
  }
  DAT_00b5cf2c[0x1f] = '\x01';
  return 0;
}


// ==== FUN_00818b00 @ 0x00818b00 ====

void FUN_00818b00(void)

{
  int *piVar1;
  byte *_Dest;
  byte bVar2;
  bool bVar3;
  LPCSTR pCVar4;
  LSTATUS LVar5;
  int iVar6;
  char *pcVar7;
  byte *pbVar8;
  code *pcVar9;
  code *pcVar10;
  code *pcVar11;
  code *pcVar12;
  undefined4 uVar13;
  int iVar14;
  int in_ECX;
  uint uVar15;
  uint unaff_ESI;
  uint unaff_EDI;
  undefined *puVar16;
  DWORD DVar17;
  LPSTR lpClass;
  DWORD DVar18;
  REGSAM samDesired;
  LPDWORD pDVar19;
  LPSECURITY_ATTRIBUTES lpSecurityAttributes;
  LPDWORD pDVar20;
  DWORD dwType;
  int iVar21;
  undefined2 uVar22;
  HKEY *phkResult;
  BYTE *pBVar23;
  uint *puVar24;
  undefined2 uVar25;
  DWORD *pDVar26;
  undefined2 uVar27;
  DWORD aDStack_2c0 [2];
  uint local_2b4;
  DWORD local_2b0;
  HKEY local_2ac [2];
  DWORD local_2a4;
  DWORD local_2a0 [7];
  BYTE local_284 [64];
  CHAR local_244 [12];
  CHAR aCStack_238 [128];
  CHAR aCStack_1b8 [128];
  char acStack_138 [312];
  
  piVar1 = (int *)(in_ECX + 0x20);
  FUN_0081c9b0();
  FUN_00817c00();
  pDVar26 = local_2a0;
  phkResult = local_2ac;
  local_2b4 = 0;
  lpSecurityAttributes = (LPSECURITY_ATTRIBUTES)0x0;
  samDesired = 0xf003f;
  DVar18 = 0;
  lpClass = (LPSTR)0x0;
  DVar17 = 0;
  bVar3 = false;
  pCVar4 = (LPCSTR)FUN_0081c9b0(&DAT_00b4b44c);
  LVar5 = RegCreateKeyExA((HKEY)0x80000001,pCVar4,DVar17,lpClass,DVar18,samDesired,
                          lpSecurityAttributes,phkResult,pDVar26);
  if (LVar5 == 0) {
    if (local_2a0[0] == 2) {
      pDVar26 = &local_2b0;
      pBVar23 = local_284;
      pDVar20 = (LPDWORD)0x0;
      pDVar19 = (LPDWORD)0x0;
      local_2b0 = 0x40;
      pCVar4 = (LPCSTR)FUN_0081c9b0();
      RegQueryValueExA(local_2ac[0],pCVar4,pDVar19,pDVar20,pBVar23,pDVar26);
      wsprintfA(local_244,(LPCSTR)&PTR___break_00b4b434);
      if ((local_2b0 != 0) && (iVar6 = lstrcmpA((LPCSTR)local_284,local_244), iVar6 == 0)) {
        bVar3 = true;
      }
      pDVar26 = &local_2b0;
      puVar24 = &local_2b4;
      pDVar20 = (LPDWORD)0x0;
      pDVar19 = (LPDWORD)0x0;
      local_2b0 = 4;
      pCVar4 = (LPCSTR)FUN_0081c9b0();
      RegQueryValueExA(local_2ac[0],pCVar4,pDVar19,pDVar20,(LPBYTE)puVar24,pDVar26);
    }
    wsprintfA((LPSTR)local_284,(LPCSTR)&PTR___break_00b4b434);
    iVar6 = lstrlenA((LPCSTR)local_284);
    local_2b0 = iVar6 + 1;
    pBVar23 = local_284;
    dwType = 1;
    DVar18 = 0;
    DVar17 = local_2b0;
    pCVar4 = (LPCSTR)FUN_0081c9b0();
    RegSetValueExA(local_2ac[0],pCVar4,DVar18,dwType,pBVar23,DVar17);
    local_2b0 = 4;
    if (bVar3) {
      local_2b4 = local_2b4 + 1;
    }
    else {
      local_2b4 = 0;
    }
    puVar24 = &local_2b4;
    uVar22 = 4;
    uVar25 = 0;
    DVar18 = 4;
    DVar17 = 0;
    pCVar4 = (LPCSTR)FUN_0081c9b0();
    RegSetValueExA(local_2ac[0],pCVar4,DVar17,DVar18,(BYTE *)puVar24,CONCAT22(uVar25,uVar22));
    RegCloseKey(local_2ac[0]);
  }
  if (((local_2b4 != 1) && (local_2b4 < 6)) && ((!bVar3 || (DAT_00b5cef4 < 9)))) {
    FUN_0081c9b0();
    FUN_00817c00();
    if (*piVar1 != -1) {
      GetLocalTime((LPSYSTEMTIME)(in_ECX + 0x103c));
      _Dest = (byte *)(in_ECX + 0x3c);
      pcVar7 = (char *)FUN_0081c940(&DAT_00b4a6fc,((LPSYSTEMTIME)(in_ECX + 0x103c))->wYear,
                                    *(undefined2 *)(in_ECX + 0x103e));
      _sprintf((char *)_Dest,pcVar7);
      uVar15 = 0xffffffff;
      pbVar8 = _Dest;
      do {
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        bVar2 = *pbVar8;
        pbVar8 = pbVar8 + 1;
      } while (bVar2 != 0);
      DVar17 = ~uVar15 - 1;
      if (*(int *)(in_ECX + 0x1458) == 0) {
        FUN_0081c2f0();
      }
      else if (0 < (int)DVar17) {
        pbVar8 = _Dest;
        do {
          iVar6 = *(int *)(in_ECX + 0x1458) + 2;
          *(int *)(in_ECX + 0x1458) = iVar6;
          *pbVar8 = *pbVar8 ^ (char)iVar6 + 0x43U;
          pbVar8 = pbVar8 + 1;
        } while ((int)(pbVar8 + (-0x1c - (int)piVar1)) < (int)DVar17);
      }
      if (*(int *)(in_ECX + 0x145c) != 999) {
        WriteFile((HANDLE)*piVar1,_Dest,DVar17,&local_2a4,(LPOVERLAPPED)0x0);
      }
      SetEndOfFile((HANDLE)*piVar1);
      CloseHandle((HANDLE)*piVar1);
      *piVar1 = -1;
    }
    iVar6 = FUN_0081b110();
    if (iVar6 == 0) {
      FUN_0081c9b0();
      iVar6 = FUN_0081af00();
      if (iVar6 == 0) {
        return;
      }
    }
    FUN_0081c9b0();
    FUN_0081b110();
    pcVar9 = (code *)FUN_00819e40();
    FUN_0081c9b0();
    FUN_0081b110();
    pcVar10 = (code *)FUN_00819e40();
    FUN_0081c9b0();
    FUN_0081b110();
    pcVar11 = (code *)FUN_00819e40();
    FUN_0081c9b0();
    FUN_0081b110();
    local_2a4 = FUN_00819e40();
    if ((((pcVar9 != (code *)0x0) && (pcVar10 != (code *)0x0)) && (pcVar11 != (code *)0x0)) &&
       (local_2a4 != 0)) {
      uVar27 = 0;
      uVar22 = 0;
      uVar25 = 0;
      iVar21 = 0;
      pcVar12 = (code *)FUN_0081c940();
      iVar6 = (*pcVar9)();
      if (iVar6 != 0) {
        uVar13 = FUN_0081c9b0(&DAT_00b4b35c,1,0x8000000);
        uVar13 = FUN_0081c940(&DAT_00b4b350,uVar13);
        uVar13 = FUN_0081c940(&DAT_00b4b340,0x17ac,uVar13);
        iVar14 = (*pcVar10)(iVar6,uVar13);
        if (iVar14 == 0) {
          (*pcVar11)(iVar6);
          return;
        }
        aCStack_1b8[0] = '\0';
        GetComputerNameA(aCStack_1b8,aDStack_2c0 + -7);
        aCStack_238[0] = '\0';
        GetUserNameA(aCStack_238,aDStack_2c0 + -7);
        GetLocalTime((LPSYSTEMTIME)(aDStack_2c0 + -3));
        if (DAT_00b5cef4 == 1) {
          puVar16 = &DAT_00b4b334;
        }
        else if (DAT_00b5cef4 == 2) {
          puVar16 = &DAT_00b4b328;
        }
        else if (DAT_00b5cef4 == 3) {
          puVar16 = &DAT_00b4b320;
        }
        else if (DAT_00b5cef4 == 4) {
          puVar16 = &DAT_00b4b314;
        }
        else if (DAT_00b5cef4 == 5) {
          puVar16 = &DAT_00b4b308;
        }
        else if (DAT_00b5cef4 == 6) {
          puVar16 = &DAT_00b4b2f8;
        }
        else if (DAT_00b5cef4 == 7) {
          puVar16 = &DAT_00b4b2ec;
        }
        else if (DAT_00b5cef4 == 8) {
          puVar16 = &DAT_00b4b2e0;
        }
        else if (DAT_00b5cef4 == 9) {
          puVar16 = &DAT_00b4b2d4;
        }
        else {
          puVar16 = &DAT_00b4b2cc;
        }
        uVar13 = FUN_0081c940(puVar16);
        pcVar7 = (char *)FUN_0081c9b0(&DAT_00b4b270,iVar21 + 0x1608,0x2f,uVar13,
                                      *(undefined4 *)(DAT_00b5cf2c + 0x10),aCStack_1b8,aCStack_238,
                                      iVar21 + 0x1630,uVar22,uVar25,uVar27,unaff_EDI & 0xffff,
                                      unaff_EDI >> 0x10,unaff_ESI & 0xffff,unaff_ESI >> 0x10);
        __snprintf(acStack_138,0x104,pcVar7);
        (*pcVar12)(iVar14,s_C__Program_Files_Acclaim_2Moons__00b5cbd4,acStack_138,0x4000002,0);
        GetLastError();
        (*pcVar11)(iVar6);
        (*pcVar11)(iVar14);
      }
    }
  }
  return;
}


// ==== FUN_008190e0 @ 0x008190e0 ====

undefined4 FUN_008190e0(void)

{
  LPCSTR lpModuleName;
  HMODULE pHVar1;
  undefined4 uVar2;
  
  if (DAT_00b5cf34 != '\0') {
    return 1;
  }
  lpModuleName = (LPCSTR)FUN_0081c9b0(&DAT_00b4b504);
  pHVar1 = GetModuleHandleA(lpModuleName);
  if (pHVar1 == (HMODULE)0x0) {
    return 0;
  }
  uVar2 = FUN_0081c9b0(&DAT_00b4b4e4);
  DAT_00b5ccd8 = FUN_00819e40(pHVar1,uVar2);
  if (DAT_00b5ccd8 == 0) {
    return 0;
  }
  uVar2 = FUN_0081c9b0(&DAT_00b4b4d0);
  DAT_00b5cbc8 = FUN_00819e40(pHVar1,uVar2);
  if (DAT_00b5cbc8 == 0) {
    return 0;
  }
  uVar2 = FUN_0081c9b0(&DAT_00b4b4bc);
  DAT_00b5cef0 = FUN_00819e40(pHVar1,uVar2);
  if (DAT_00b5cef0 == 0) {
    return 0;
  }
  uVar2 = FUN_0081c9b0(&DAT_00b4b4a8);
  DAT_00b5ceec = FUN_00819e40(pHVar1,uVar2);
  if (DAT_00b5ceec == 0) {
    return 0;
  }
  uVar2 = FUN_0081c9b0(&DAT_00b4b494);
  DAT_00b5cbcc = FUN_00819e40(pHVar1,uVar2);
  if (DAT_00b5cbcc == 0) {
    return 0;
  }
  DAT_00b5cf34 = 1;
  return 1;
}


// ==== FUN_008191c0 @ 0x008191c0 ====

void FUN_008191c0(void)

{
  char cVar1;
  HANDLE hObject;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piStack_138;
  int iStack_134;
  undefined4 local_124 [4];
  undefined1 auStack_114 [276];
  
  cVar1 = FUN_008190e0();
  if (cVar1 != '\0') {
    iStack_134 = 0;
    puVar4 = local_124;
    for (iVar3 = 0x49; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    piStack_138 = (int *)0x2;
    hObject = (HANDLE)(*DAT_00b5ccd8)();
    if (hObject != (HANDLE)0xffffffff) {
      piStack_138 = local_124 + -3;
      iVar3 = (*DAT_00b5cbc8)(hObject);
      if (iVar3 != 0) {
        if (DAT_00b5cf2c == 0) goto LAB_0081927c;
        uVar2 = FUN_0081c9b0(&DAT_00b4b53c);
        FUN_00817c00(DAT_00b5cf2c + 0x20,uVar2);
        do {
          if (DAT_00b5cf2c != 0) {
            uVar2 = FUN_0081c9b0(&DAT_00b4b518,auStack_114,0x128,local_124[0],local_124[2]);
            FUN_00817c00(DAT_00b5cf2c + 0x20,uVar2);
          }
LAB_0081927c:
          iVar3 = (*DAT_00b5cef0)(hObject,&piStack_138);
        } while (iVar3 != 0);
      }
      CloseHandle(hObject);
    }
  }
  return;
}


// ==== FUN_008192a0 @ 0x008192a0 ====

void FUN_008192a0(void)

{
  char cVar1;
  HANDLE hObject;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puStack_234;
  DWORD DStack_230;
  undefined4 local_220 [3];
  undefined1 auStack_214 [256];
  undefined1 auStack_114 [276];
  
  cVar1 = FUN_008190e0();
  if (cVar1 != '\0') {
    puVar4 = local_220;
    for (iVar3 = 0x88; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    DStack_230 = 0x8192d0;
    DStack_230 = GetCurrentProcessId();
    puStack_234 = (undefined4 *)0x8;
    hObject = (HANDLE)(*DAT_00b5ccd8)();
    if (hObject != (HANDLE)0xffffffff) {
      puStack_234 = local_220 + -3;
      iVar3 = (*DAT_00b5ceec)(hObject);
      if (iVar3 != 0) {
        if (DAT_00b5cf2c == 0) goto LAB_00819365;
        uVar2 = FUN_0081c9b0(&DAT_00b4b590);
        FUN_00817c00(DAT_00b5cf2c + 0x20,uVar2);
        do {
          if (DAT_00b5cf2c != 0) {
            uVar2 = FUN_0081c9b0(&DAT_00b4b570,auStack_214,local_220[0],local_220[1],auStack_114);
            FUN_00817c00(DAT_00b5cf2c + 0x20,uVar2);
          }
LAB_00819365:
          iVar3 = (*DAT_00b5cbcc)(hObject,&puStack_234);
        } while (iVar3 != 0);
      }
      CloseHandle(hObject);
    }
  }
  return;
}


// ==== FUN_008194a0 @ 0x008194a0 ====

undefined1 FUN_008194a0(void)

{
  code *pcVar1;
  LPCSTR pCVar2;
  HMODULE pHVar3;
  HMODULE pHVar4;
  HMODULE pHVar5;
  undefined4 uVar6;
  int local_4;
  
  local_4 = 0;
  pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4b718);
  pHVar3 = GetModuleHandleA(pCVar2);
  pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4b708);
  pHVar4 = GetModuleHandleA(pCVar2);
  pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4b6f4);
  pHVar5 = GetModuleHandleA(pCVar2);
  if (pHVar5 == (HMODULE)0x0) {
    return 2;
  }
  uVar6 = FUN_0081c9b0(&DAT_00b4b6d8);
  DAT_00b5cf3c = (HMODULE)FUN_00819e40(pHVar5,uVar6);
  if (DAT_00b5cf3c != (HMODULE)0x0) {
    DAT_00b5cf50 = QueryPerformanceCounter_exref;
    if (DAT_00b5cf2c != 0) {
      uVar6 = FUN_0081c9b0(&DAT_00b4b6c4,DAT_00b5cf3c,QueryPerformanceCounter_exref);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar6);
    }
    if (((DAT_00b5cf3c < pHVar5) && (pHVar4 == (HMODULE)0x0)) &&
       ((pHVar3 == (HMODULE)0x0 || (DAT_00b5cf3c < pHVar3)))) {
      if (DAT_00b5cf2c != 0) {
        uVar6 = FUN_0081c9b0(&DAT_00b4b6ac,pHVar5);
        FUN_00817c00(DAT_00b5cf2c + 0x20,uVar6);
      }
      local_4 = 1;
    }
  }
  uVar6 = FUN_0081c9b0(&DAT_00b4b698);
  DAT_00b5cf38 = (HMODULE)FUN_00819e40(pHVar5,uVar6);
  if (DAT_00b5cf38 != (HMODULE)0x0) {
    DAT_00b5cf4c = GetTickCount_exref;
    if (DAT_00b5cf2c != 0) {
      uVar6 = FUN_0081c9b0(&DAT_00b4b684,DAT_00b5cf38,GetTickCount_exref);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar6);
    }
    if (((DAT_00b5cf38 < pHVar5) && (pHVar4 == (HMODULE)0x0)) &&
       ((pHVar3 == (HMODULE)0x0 || (DAT_00b5cf3c < pHVar3)))) {
      if (DAT_00b5cf2c != 0) {
        uVar6 = FUN_0081c9b0(&DAT_00b4b66c,pHVar5);
        FUN_00817c00(DAT_00b5cf2c + 0x20,uVar6);
      }
      local_4 = local_4 + 1;
    }
  }
  pcVar1 = timeGetTime_exref;
  timeGetTime();
  pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4b65c);
  pHVar5 = GetModuleHandleA(pCVar2);
  if (pHVar5 != (HMODULE)0x0) {
    uVar6 = FUN_0081c9b0(&DAT_00b4b64c);
    DAT_00b5cf40 = (HMODULE)FUN_00819e40(pHVar5,uVar6);
    if (DAT_00b5cf40 != (HMODULE)0x0) {
      DAT_00b5cf54 = pcVar1;
      if (DAT_00b5cf2c != 0) {
        uVar6 = FUN_0081c9b0(&DAT_00b4b638,DAT_00b5cf40,pcVar1);
        FUN_00817c00(DAT_00b5cf2c + 0x20,uVar6);
      }
      if (((DAT_00b5cf40 < pHVar5) && (pHVar4 == (HMODULE)0x0)) &&
         ((pHVar3 == (HMODULE)0x0 || (DAT_00b5cf3c < pHVar3)))) {
        if (DAT_00b5cf2c != 0) {
          uVar6 = FUN_0081c9b0(&DAT_00b4b620,pHVar5);
          FUN_00817c00(DAT_00b5cf2c + 0x20,uVar6);
        }
        local_4 = local_4 + 1;
      }
    }
  }
  DAT_00b5cf60 = 1;
  return local_4 == 0;
}


// ==== FUN_00819700 @ 0x00819700 ====

bool FUN_00819700(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_00b5cf28 != '\0') {
    return true;
  }
  if (DAT_00b5cf60 == '\0') {
    return (bool)2;
  }
  iVar2 = 0;
  if (DAT_00b5cf50 != QueryPerformanceCounter_exref) {
    if (DAT_00b5cf2c != 0) {
      uVar1 = FUN_0081c9b0(&DAT_00b4b754,QueryPerformanceCounter_exref);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar1);
    }
    iVar2 = 1;
  }
  if (DAT_00b5cf4c != GetTickCount_exref) {
    if (DAT_00b5cf2c != 0) {
      uVar1 = FUN_0081c9b0(&DAT_00b4b740,GetTickCount_exref);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar1);
    }
    iVar2 = iVar2 + 1;
  }
  if (DAT_00b5cf54 != timeGetTime_exref) {
    if (DAT_00b5cf2c != 0) {
      uVar1 = FUN_0081c9b0(&DAT_00b4b72c,timeGetTime_exref);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar1);
    }
    iVar2 = iVar2 + 1;
  }
  return iVar2 == 0;
}


// ==== FUN_008197e0 @ 0x008197e0 ====

undefined1 FUN_008197e0(void)

{
  LPCSTR lpModuleName;
  HMODULE pHVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  lpModuleName = (LPCSTR)FUN_0081c9b0(&DAT_00b4b7e8);
  pHVar1 = GetModuleHandleA(lpModuleName);
  if (pHVar1 == (HMODULE)0x0) {
    return 2;
  }
  uVar2 = FUN_0081c9b0(&DAT_00b4b7dc);
  DAT_00b5cf44 = (HMODULE)FUN_00819e40(pHVar1,uVar2);
  if (DAT_00b5cf44 != (HMODULE)0x0) {
    DAT_00b5cf58 = WSASend_exref;
    if (DAT_00b5cf2c != 0) {
      uVar2 = FUN_0081c9b0(&DAT_00b4b7c4,DAT_00b5cf44,WSASend_exref);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar2);
    }
    if (DAT_00b5cf44 < pHVar1) {
      if (DAT_00b5cf2c != 0) {
        uVar2 = FUN_0081c9b0(&DAT_00b4b7a8,pHVar1);
        FUN_00817c00(DAT_00b5cf2c + 0x20,uVar2);
      }
      iVar3 = 1;
    }
  }
  uVar2 = FUN_0081c9b0(&DAT_00b4b79c);
  DAT_00b5cf48 = (HMODULE)FUN_00819e40(pHVar1,uVar2);
  if (DAT_00b5cf48 != (HMODULE)0x0) {
    DAT_00b5cf5c = send_exref;
    if (DAT_00b5cf2c != 0) {
      uVar2 = FUN_0081c9b0(&DAT_00b4b784,DAT_00b5cf48,send_exref);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar2);
    }
    if (DAT_00b5cf48 < pHVar1) {
      if (DAT_00b5cf2c != 0) {
        uVar2 = FUN_0081c9b0(&DAT_00b4b768,pHVar1);
        FUN_00817c00(DAT_00b5cf2c + 0x20,uVar2);
      }
      iVar3 = iVar3 + 1;
    }
  }
  DAT_00b5cf61 = 1;
  return iVar3 == 0;
}


// ==== FUN_00819930 @ 0x00819930 ====

undefined1 FUN_00819930(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_00b5cf61 == '\0') {
    return 2;
  }
  iVar2 = 0;
  if (DAT_00b5cf58 != WSASend_exref) {
    if (DAT_00b5cf2c != 0) {
      uVar1 = FUN_0081c9b0(&DAT_00b4b80c,WSASend_exref);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar1);
    }
    iVar2 = 1;
  }
  if (DAT_00b5cf5c != send_exref) {
    if (DAT_00b5cf2c != 0) {
      uVar1 = FUN_0081c9b0(&DAT_00b4b7f8,send_exref);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar1);
    }
    iVar2 = iVar2 + 1;
  }
  return iVar2 == 0;
}


// ==== FUN_008199d0 @ 0x008199d0 ====

undefined4 FUN_008199d0(undefined4 param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  DWORD DVar2;
  undefined4 uVar3;
  LPCSTR pCVar4;
  LSTATUS LVar5;
  LPSTR lpClass;
  DWORD dwOptions;
  REGSAM samDesired;
  LPSECURITY_ATTRIBUTES lpSecurityAttributes;
  HKEY *phkResult;
  LPDWORD lpReserved;
  DWORD *pDVar6;
  LPDWORD lpType;
  int *lpData;
  int local_424;
  int local_420;
  HKEY local_41c;
  DWORD local_418 [258];
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099919b;
  local_c = ExceptionList;
  local_418[1] = 4;
  local_420 = 0;
  local_424 = 1;
  ExceptionList = &local_c;
  FUN_0081ce10();
  local_4 = 0;
  cVar1 = FUN_0081ce50(param_1,&local_424);
  if ((cVar1 == '\0') && (GetLastError(), DAT_00b5cf2c != 0)) {
    DVar2 = GetLastError();
    uVar3 = FUN_0081c9b0(&DAT_00b4b8a0,param_1,local_10,DVar2);
    FUN_00817c00(DAT_00b5cf2c + 0x20,uVar3);
  }
  pDVar6 = local_418;
  phkResult = &local_41c;
  lpSecurityAttributes = (LPSECURITY_ATTRIBUTES)0x0;
  samDesired = 0xf003f;
  dwOptions = 0;
  lpClass = (LPSTR)0x0;
  DVar2 = 0;
  pCVar4 = (LPCSTR)FUN_0081c9b0(&DAT_00b4b86c);
  LVar5 = RegCreateKeyExA((HKEY)0x80000001,pCVar4,DVar2,lpClass,dwOptions,samDesired,
                          lpSecurityAttributes,phkResult,pDVar6);
  if (LVar5 == 0) {
    if (local_418[0] == 2) {
      pDVar6 = local_418 + 1;
      lpData = &local_420;
      lpType = (LPDWORD)0x0;
      lpReserved = (LPDWORD)0x0;
      pCVar4 = (LPCSTR)FUN_0081c9b0(param_2);
      RegQueryValueExA(local_41c,pCVar4,lpReserved,lpType,(LPBYTE)lpData,pDVar6);
    }
    RegCloseKey(local_41c);
    if (local_424 == local_420) goto LAB_00819b48;
    if (DAT_00b5cf2c == 0) goto LAB_00819b7f;
    uVar3 = FUN_0081c9b0(&DAT_00b4b854,local_424,local_420);
  }
  else {
    if (DAT_00b5cf2c != 0) {
      uVar3 = FUN_0081c9b0(&DAT_00b4b83c,LVar5);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar3);
    }
LAB_00819b48:
    if (local_424 == param_3) {
      local_4 = 0xffffffff;
      FUN_0081aef0();
      ExceptionList = local_c;
      return 1;
    }
    if (DAT_00b5cf2c == 0) goto LAB_00819b7f;
    uVar3 = FUN_0081c9b0(&DAT_00b4b824,local_424,param_3);
  }
  FUN_00817c00(DAT_00b5cf2c + 0x20,uVar3);
LAB_00819b7f:
  local_4 = 0xffffffff;
  FUN_0081aef0();
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_00819be0 @ 0x00819be0 ====

uint FUN_00819be0(undefined4 *param_1)

{
  LPCSTR lpModuleName;
  HMODULE pHVar1;
  undefined4 uVar2;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  undefined1 local_40 [36];
  uint uStack_1c;
  
  lpModuleName = (LPCSTR)FUN_0081c9b0(&DAT_00b4b8f8);
  pHVar1 = GetModuleHandleA(lpModuleName);
  uVar2 = FUN_0081c9b0(&DAT_00b4b8d8);
  pcVar3 = (code *)FUN_00819e40(pHVar1,uVar2);
  uVar2 = FUN_0081c9b0(&DAT_00b4b8c0);
  pcVar4 = (code *)FUN_00819e40(pHVar1,uVar2);
  iVar5 = 0;
  if (pcVar4 != (code *)0x0) {
    iVar5 = (*pcVar4)(*param_1,0x400000,local_40,0x40,0);
  }
  if (pcVar3 != (code *)0x0) {
    if (iVar5 != 0) goto LAB_00819c65;
    iVar5 = (*pcVar3)(param_1[2],0x400000,local_40,0x40,0);
  }
  if (iVar5 == 0) {
    return 0;
  }
LAB_00819c65:
  return ~uStack_1c;
}


// ==== FUN_00819c80 @ 0x00819c80 ====

uint FUN_00819c80(uint param_1)

{
  LPCSTR lpLibFileName;
  HMODULE hLibModule;
  undefined4 uVar1;
  code *pcVar2;
  code *pcVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  uint extraout_EAX;
  int *unaff_EBX;
  void *unaff_ESI;
  uint unaff_retaddr;
  undefined1 auStack_14 [2];
  undefined1 uStack_12;
  byte local_11;
  void *pvStack_10;
  undefined4 local_c;
  uint uStack_8;
  uint uStack_4;
  
  local_11 = 1;
  lpLibFileName = (LPCSTR)FUN_0081c9b0(&DAT_00b4b970);
  hLibModule = LoadLibraryA(lpLibFileName);
  if (hLibModule == (HMODULE)0x0) {
    return (uint)local_11;
  }
  uVar1 = FUN_0081c9b0(&DAT_00b4b954);
  pcVar2 = (code *)FUN_00819e40(hLibModule,uVar1);
  uVar1 = FUN_0081c9b0(&DAT_00b4b93c);
  pcVar3 = (code *)FUN_00819e40(hLibModule,uVar1);
  uVar1 = FUN_0081c9b0(&DAT_00b4b928);
  pcVar4 = (code *)FUN_00819e40(hLibModule,uVar1);
  if ((((pcVar2 == (code *)0x0) || (pcVar3 == (code *)0x0)) || (pcVar4 == (code *)0x0)) ||
     (uVar5 = (*pcVar2)(param_1,&local_c), uVar5 == 0)) {
    FreeLibrary(hLibModule);
    return (uint)local_11;
  }
  pvStack_10 = operator_new(uVar5);
  iVar6 = (*pcVar3)(param_1,local_c,uVar5,pvStack_10);
  if ((iVar6 != 0) &&
     ((*pcVar4)(unaff_ESI,&DAT_00b4ae70,auStack_14 + -4,auStack_14), *unaff_EBX == -0x110fb43)) {
    if (DAT_00b5cf2c != 0) {
      uVar1 = FUN_0081c9b0(&DAT_00b4b90c,local_c,
                           (uint)*(ushort *)(unaff_EBX + 3) +
                           (((uint)unaff_EBX[3] >> 0x10) +
                           ((uint)*(ushort *)(unaff_EBX + 2) + ((uint)unaff_EBX[2] >> 0x10) * 100) *
                           100) * 100,
                           (param_1 & 0xffff) +
                           ((unaff_retaddr & 0xffff) +
                           ((uStack_4 & 0xffff) + (uStack_8 & 0xffff) * 100) * 100) * 100);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar1);
    }
  }
  _free(unaff_ESI);
  return extraout_EAX;
}


// ==== FUN_00819e40 @ 0x00819e40 ====

char * FUN_00819e40(short *param_1,char *param_2)

{
  char cVar1;
  BOOL BVar2;
  HMODULE pHVar3;
  uint uVar4;
  uint uVar5;
  byte *lp;
  uchar *puVar6;
  char *pcVar7;
  char *pcVar8;
  uchar *puVar9;
  undefined1 auStackY_180 [128];
  uchar local_e8 [128];
  uchar *local_68;
  byte *local_64;
  char local_60;
  uint local_5c;
  char local_58;
  uint local_54;
  int *local_50;
  ushort *local_4c;
  char *local_48;
  int *local_44;
  int local_40;
  int *local_3c;
  char *local_38;
  short *local_34;
  int local_30;
  int *local_2c;
  int local_28;
  char *local_24;
  undefined4 local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00a0bcd8;
  puStack_10 = &DAT_0080015c;
  local_14 = ExceptionList;
  local_1c = auStackY_180 + 0x88;
  ExceptionList = &local_14;
  BVar2 = IsBadReadPtr(param_1,4);
  if (BVar2 != 0) {
    ExceptionList = local_14;
    return (char *)0x0;
  }
  local_24 = (char *)0x0;
  local_20 = 0;
  local_8 = 0;
  local_34 = param_1;
  if (*param_1 != 0x5a4d) {
    ExceptionList = local_14;
    return (char *)0x0;
  }
  local_3c = (int *)(*(int *)(param_1 + 0x1e) + (int)param_1);
  if (*local_3c != 0x4550) {
    ExceptionList = local_14;
    return (char *)0x0;
  }
  if ((short)local_3c[6] == 0x20b) {
    local_30 = local_3c[0x22];
    local_28 = local_3c[0x23];
    local_44 = local_3c;
  }
  else {
    local_30 = local_3c[0x1e];
    local_28 = local_3c[0x1f];
  }
  if (local_30 == 0) {
    ExceptionList = local_14;
    return (char *)0x0;
  }
  local_40 = local_30 + (int)param_1;
  if (param_2 < (char *)0x10000) {
    local_38 = param_2 + -1;
  }
  else {
    local_54 = 0;
    local_48 = param_2;
    while (*local_48 != '\0') {
      local_48 = local_48 + 1;
      local_54 = local_54 + 1;
      if (0xff < local_54) {
        ExceptionList = local_14;
        return (char *)0x0;
      }
    }
    local_50 = (int *)(*(int *)(local_40 + 0x20) + (int)param_1);
    local_58 = '\0';
    for (local_38 = (char *)0x0; local_38 < *(uint *)(local_40 + 0x18);
        local_38 = (char *)((int)local_38 + 1)) {
      lp = (byte *)(*local_50 + (int)param_1);
      local_64 = lp;
      local_48 = param_2;
      BVar2 = IsBadReadPtr(lp,4);
      if (BVar2 != 0) {
        ExceptionList = local_14;
        return (char *)0x0;
      }
      local_60 = '\x01';
      pcVar7 = param_2;
      for (local_5c = 0; local_5c < local_54; local_5c = local_5c + 1) {
        if ((uint)*lp != (int)*pcVar7) {
          local_60 = '\0';
          break;
        }
        lp = lp + 1;
        pcVar7 = pcVar7 + 1;
        local_64 = lp;
        local_48 = pcVar7;
      }
      if (local_60 != '\0') {
        local_58 = '\x01';
        break;
      }
      local_50 = local_50 + 1;
    }
    if (local_58 == '\0') {
      ExceptionList = local_14;
      return (char *)0x0;
    }
    local_4c = (ushort *)((int)param_1 + (int)local_38 * 2 + *(int *)(local_40 + 0x24));
    local_38 = (char *)(uint)*local_4c;
  }
  local_2c = (int *)((int)param_1 + (int)local_38 * 4 + *(int *)(local_40 + 0x1c));
  local_24 = (char *)(*local_2c + (int)param_1);
  if (((char *)(local_30 + (int)param_1) <= local_24) &&
     (local_24 < (char *)(local_28 + local_30 + (int)param_1))) {
    uVar4 = 0xffffffff;
    pcVar7 = local_24;
    do {
      pcVar8 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    puVar6 = (uchar *)(pcVar8 + -uVar4);
    puVar9 = local_e8;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)puVar9 = *(undefined4 *)puVar6;
      puVar6 = puVar6 + 4;
      puVar9 = puVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    local_68 = __mbsstr(local_e8,&DAT_00b4af74);
    if (local_68 != (uchar *)0x0) {
      *local_68 = '\0';
      local_68 = local_68 + 1;
    }
    puVar6 = local_68;
    pHVar3 = GetModuleHandleA((LPCSTR)local_e8);
    local_24 = (char *)FUN_00819e40(pHVar3,puVar6);
  }
  ExceptionList = local_14;
  return local_24;
}


// ==== FUN_0081a114 @ 0x0081a114 ====

void FUN_0081a114(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = (undefined4 *)**(int **)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0xe8) = *puVar1;
  *(undefined4 *)(unaff_EBP + -0x1c) = puVar1[3];
  return;
}


// ==== FUN_0081a12a @ 0x0081a12a ====

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_0081a12a(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  if (DAT_00b5cf2c != 0) {
    *(undefined4 *)(iVar1 + -4) = *(undefined4 *)(unaff_EBP + -0x1c);
    *(undefined4 *)(iVar1 + -8) = *(undefined4 *)(unaff_EBP + -0xe8);
    *(undefined **)(iVar1 + -0xc) = &DAT_00b4b980;
    *(undefined4 *)(iVar1 + -0x10) = 0x81a14b;
    uVar2 = FUN_0081c9b0();
    *(undefined4 *)(iVar1 + -0xc) = uVar2;
    *(int *)(iVar1 + -0x10) = DAT_00b5cf2c + 0x20;
    *(undefined4 *)(iVar1 + -0x14) = 0x81a15d;
    FUN_00817c00();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return *(undefined4 *)(unaff_EBP + -0x20);
}


// ==== FUN_0081a180 @ 0x0081a180 ====

undefined4 FUN_0081a180(void)

{
  char cVar1;
  LPCSTR pCVar2;
  LSTATUS LVar3;
  undefined4 uVar4;
  char *pcVar5;
  HANDLE hFile;
  HMODULE hLibModule;
  code *pcVar6;
  code *pcVar7;
  void *_Memory;
  undefined4 extraout_EAX;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  char *pcVar12;
  char *pcVar13;
  undefined *puVar14;
  LPDWORD pDVar15;
  DWORD DVar16;
  LPDWORD pDVar17;
  DWORD dwType;
  REGSAM RVar18;
  BYTE *pBVar19;
  HKEY *ppHVar20;
  DWORD *pDVar21;
  CHAR *pCVar22;
  DWORD cbData;
  BYTE aBStack_2b0 [120];
  int *piStack_238;
  undefined1 uStack_234;
  undefined1 uStack_233;
  undefined1 uStack_232;
  undefined1 uStack_231;
  undefined1 uStack_230;
  undefined1 uStack_22f;
  undefined1 uStack_22e;
  undefined1 uStack_22d;
  code *pcStack_22c;
  HKEY local_228;
  DWORD local_224;
  DWORD local_220;
  int local_21c [2];
  code *local_214;
  undefined4 local_210 [2];
  BYTE local_208;
  undefined1 uStack_207;
  undefined1 uStack_206;
  undefined1 uStack_205;
  CHAR local_104 [260];
  
  ppHVar20 = &local_228;
  uVar11 = 0;
  RVar18 = 1;
  DVar16 = 0;
  pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4baec);
  LVar3 = RegOpenKeyExA((HKEY)0x80000002,pCVar2,DVar16,RVar18,ppHVar20);
  if (LVar3 == 0) {
    pDVar21 = &local_224;
    pBVar19 = &local_208;
    pDVar17 = (LPDWORD)0x0;
    pDVar15 = (LPDWORD)0x0;
    local_224 = 0x104;
    pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4bae0);
    LVar3 = RegQueryValueExA(local_228,pCVar2,pDVar15,pDVar17,pBVar19,pDVar21);
    if ((LVar3 == 0) && (DAT_00b5cf2c != 0)) {
      uVar4 = FUN_0081c9b0(&DAT_00b4bacc,&local_208);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar4);
    }
    RegCloseKey(local_228);
  }
  ppHVar20 = &local_228;
  RVar18 = 3;
  DVar16 = 0;
  pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4ba68);
  LVar3 = RegOpenKeyExA((HKEY)0x80000002,pCVar2,DVar16,RVar18,ppHVar20);
  if (LVar3 != 0) {
    return 0;
  }
  pDVar21 = &local_224;
  pBVar19 = &local_208;
  pDVar17 = (LPDWORD)0x0;
  pDVar15 = (LPDWORD)0x0;
  local_224 = 0x104;
  pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4ba58);
  LVar3 = RegQueryValueExA(local_228,pCVar2,pDVar15,pDVar17,pBVar19,pDVar21);
  if ((LVar3 == 0) && (DAT_00b5cf2c != 0)) {
    uVar4 = FUN_0081c9b0(&DAT_00b4ba34,local_208,uStack_207,uStack_206,uStack_205);
    FUN_00817c00(DAT_00b5cf2c + 0x20,uVar4);
  }
  GetSystemDirectoryA(local_104,0x104);
  pcVar5 = (char *)FUN_0081c9b0(&DAT_00b4ba20);
  uVar8 = 0xffffffff;
  do {
    pcVar13 = pcVar5;
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    pcVar13 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar13;
  } while (cVar1 != '\0');
  uVar8 = ~uVar8;
  iVar9 = -1;
  pcVar5 = local_104;
  do {
    pcVar12 = pcVar5;
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    pcVar12 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar12;
  } while (cVar1 != '\0');
  pcVar5 = pcVar13 + -uVar8;
  pcVar13 = pcVar12 + -1;
  for (uVar10 = uVar8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar13 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pcVar13 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar13 = pcVar13 + 1;
  }
  local_220 = 0;
  hFile = CreateFileA(local_104,0x80000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    if (DAT_00b5cf2c != 0) {
      pCVar22 = local_104;
      DVar16 = GetLastError();
      uVar4 = FUN_0081c9b0(&DAT_00b4ac30,DVar16,pCVar22);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar4);
    }
  }
  else {
    local_220 = GetFileSize(hFile,(LPDWORD)0x0);
    if (DAT_00b5cf2c != 0) {
      uVar4 = FUN_0081c9b0(&DAT_00b4ac20,local_220);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar4);
    }
    CloseHandle(hFile);
  }
  pCVar2 = (LPCSTR)FUN_0081c9b0(&DAT_00b4b970);
  hLibModule = LoadLibraryA(pCVar2);
  if (hLibModule != (HMODULE)0x0) {
    uVar4 = FUN_0081c9b0(&DAT_00b4b954);
    pcVar6 = (code *)FUN_00819e40(hLibModule,uVar4);
    uVar4 = FUN_0081c9b0(&DAT_00b4b93c);
    pcVar7 = (code *)FUN_00819e40(hLibModule,uVar4);
    local_214 = pcVar7;
    uVar4 = FUN_0081c9b0(&DAT_00b4b928);
    local_21c[0] = FUN_00819e40(hLibModule,uVar4);
    if ((((pcVar6 != (code *)0x0) && (pcVar7 != (code *)0x0)) && (local_21c[0] != 0)) &&
       (uVar8 = (*pcVar6)(local_104,local_210), uVar8 != 0)) {
      _Memory = operator_new(uVar8);
      (*local_214)(local_104,local_210[0],uVar8,_Memory);
      (*pcStack_22c)(_Memory,&DAT_00b4ae70,&local_228,local_21c);
      if ((*piStack_238 == -0x110fb43) && (DAT_00b5cf2c != 0)) {
        uVar11 = FUN_0081c9b0(&DAT_00b4ba08,(uint)piStack_238[2] >> 0x10,(short)piStack_238[2],
                              (uint)piStack_238[3] >> 0x10,(short)piStack_238[3]);
        FUN_00817c00(DAT_00b5cf2c + 0x20,uVar11);
      }
      _free(_Memory);
      return extraout_EAX;
    }
    FreeLibrary(hLibModule);
  }
  if (local_220 == 0x18d10) {
    if (DAT_00b5cf2c != 0) {
      uVar11 = FUN_0081c9b0(&DAT_00b4b9ec);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar11);
    }
    aBStack_2b0[1] = 199;
    aBStack_2b0[0x11] = 199;
    aBStack_2b0[0x33] = 0xf2;
    aBStack_2b0[0x26] = 0x16;
    aBStack_2b0[0x37] = 0xf2;
    aBStack_2b0[0x44] = 0x16;
    aBStack_2b0[0] = '*';
    aBStack_2b0[2] = 0xe;
    aBStack_2b0[3] = 0x10;
    aBStack_2b0[4] = 6;
    aBStack_2b0[5] = 0xbe;
    aBStack_2b0[6] = 0xa7;
    aBStack_2b0[7] = 0xcd;
    aBStack_2b0[8] = 0xf5;
    aBStack_2b0[9] = 0xfa;
    aBStack_2b0[10] = 0x66;
    aBStack_2b0[0xb] = 0xf;
    aBStack_2b0[0xc] = 0x86;
    aBStack_2b0[0xd] = 0xa3;
    aBStack_2b0[0xe] = 0x8a;
    aBStack_2b0[0xf] = 0x41;
    aBStack_2b0[0x10] = 0x58;
    aBStack_2b0[0x12] = 0xaf;
    aBStack_2b0[0x13] = 0x6e;
    aBStack_2b0[0x14] = 0xf5;
    aBStack_2b0[0x15] = 0xc1;
    aBStack_2b0[0x16] = 0x92;
    aBStack_2b0[0x17] = 0x3d;
    aBStack_2b0[0x18] = 0xf5;
    aBStack_2b0[0x19] = 0x56;
    aBStack_2b0[0x1a] = 0xa8;
    aBStack_2b0[0x1b] = 0x81;
    aBStack_2b0[0x1c] = 0x48;
    aBStack_2b0[0x1d] = 0x2e;
    aBStack_2b0[0x1e] = 0x89;
    aBStack_2b0[0x1f] = 0x7c;
    aBStack_2b0[0x20] = 4;
    aBStack_2b0[0x21] = 0x36;
    aBStack_2b0[0x22] = 0x53;
    aBStack_2b0[0x23] = 0xe3;
    aBStack_2b0[0x24] = 100;
    aBStack_2b0[0x25] = 0x79;
    aBStack_2b0[0x27] = 0x34;
    aBStack_2b0[0x28] = 0x7d;
    aBStack_2b0[0x29] = 0xe8;
    aBStack_2b0[0x2a] = 0xb0;
    aBStack_2b0[0x2b] = 0xae;
    aBStack_2b0[0x2c] = 0xd7;
    aBStack_2b0[0x2d] = 0x3c;
    aBStack_2b0[0x2e] = 0xc5;
    aBStack_2b0[0x2f] = 0xeb;
    aBStack_2b0[0x30] = 0x7a;
    aBStack_2b0[0x31] = 0x25;
    aBStack_2b0[0x32] = 0x2d;
    aBStack_2b0[0x34] = 0xb8;
    aBStack_2b0[0x35] = 0xe4;
    aBStack_2b0[0x36] = 0xf4;
    aBStack_2b0[0x38] = 0xcd;
    aBStack_2b0[0x39] = 0x95;
    aBStack_2b0[0x3a] = 0xb;
    aBStack_2b0[0x3b] = 0xdd;
    aBStack_2b0[0x3c] = 0x4f;
    aBStack_2b0[0x3d] = 10;
    aBStack_2b0[0x3e] = 0x9f;
    aBStack_2b0[0x3f] = 0x27;
    aBStack_2b0[0x40] = 0x19;
    aBStack_2b0[0x41] = 0xb5;
    aBStack_2b0[0x42] = 0xf6;
    aBStack_2b0[0x43] = 0x52;
    aBStack_2b0[0x45] = 0x77;
    aBStack_2b0[0x46] = 1;
    aBStack_2b0[0x47] = 0x2c;
    aBStack_2b0[0x48] = 0xf6;
    aBStack_2b0[0x49] = 0xae;
    aBStack_2b0[0x4a] = 0x9a;
    aBStack_2b0[0x65] = 0xf5;
    aBStack_2b0[0x4b] = 0xd3;
    aBStack_2b0[0x4c] = 0x7f;
    aBStack_2b0[0x4d] = 0xbf;
    aBStack_2b0[0x4e] = 0x6a;
    aBStack_2b0[0x4f] = 0x22;
    aBStack_2b0[0x50] = 0x91;
    aBStack_2b0[0x51] = 0x6b;
    aBStack_2b0[0x52] = 0xf3;
    aBStack_2b0[0x53] = 0xdb;
    aBStack_2b0[0x54] = 0x93;
    aBStack_2b0[0x55] = 0xd;
    aBStack_2b0[0x56] = 0x1c;
    aBStack_2b0[0x57] = 0xd2;
    aBStack_2b0[0x58] = 0;
    aBStack_2b0[0x59] = 0xb5;
    aBStack_2b0[0x5a] = 0xb8;
    aBStack_2b0[0x5b] = 0x14;
    aBStack_2b0[0x5c] = 0x1c;
    aBStack_2b0[0x5d] = 0x3e;
    aBStack_2b0[0x5e] = 0x9e;
    aBStack_2b0[0x5f] = 0x94;
    aBStack_2b0[0x60] = 0x7b;
    aBStack_2b0[0x61] = 0xa9;
    aBStack_2b0[0x62] = 0x8e;
    aBStack_2b0[99] = 0xc6;
    aBStack_2b0[100] = 0x84;
    aBStack_2b0[0x66] = 0x2b;
    aBStack_2b0[0x67] = 0xfa;
    aBStack_2b0[0x68] = 0xb5;
    aBStack_2b0[0x69] = 0x95;
    aBStack_2b0[0x6a] = 0;
    aBStack_2b0[0x6b] = 0xa5;
    aBStack_2b0[0x6c] = 0x95;
    aBStack_2b0[0x6d] = 0xb2;
    aBStack_2b0[0x6e] = 0x65;
    aBStack_2b0[0x6f] = 0x8c;
    aBStack_2b0[0x70] = 0x31;
    aBStack_2b0[0x71] = 0x19;
    aBStack_2b0[0x72] = 0x77;
    aBStack_2b0[0x73] = 0;
    aBStack_2b0[0x74] = 0xcd;
    aBStack_2b0[0x75] = 0x5b;
    aBStack_2b0[0x76] = 0x4e;
    aBStack_2b0[0x77] = 0x92;
    piStack_238 = (int *)0x6642e468;
    uStack_234 = 0x17;
    uStack_233 = 0xb5;
    uStack_232 = 0xd4;
    uStack_231 = 0x93;
    puVar14 = &DAT_00b4b9dc;
  }
  else {
    if (local_220 != 0x17110) goto LAB_0081abf1;
    if (DAT_00b5cf2c != 0) {
      uVar11 = FUN_0081c9b0(&DAT_00b4b9c0);
      FUN_00817c00(DAT_00b5cf2c + 0x20,uVar11);
    }
    aBStack_2b0[0x13] = 7;
    aBStack_2b0[0x28] = 7;
    aBStack_2b0[0x2f] = 7;
    aBStack_2b0[0] = '_';
    aBStack_2b0[1] = 0x71;
    aBStack_2b0[2] = 0x69;
    aBStack_2b0[3] = 0x53;
    aBStack_2b0[4] = 0x8a;
    aBStack_2b0[5] = 0x8e;
    aBStack_2b0[6] = 0x54;
    aBStack_2b0[7] = 0xac;
    aBStack_2b0[8] = 9;
    aBStack_2b0[9] = 0x3f;
    aBStack_2b0[10] = 0x65;
    aBStack_2b0[0xb] = 0x5a;
    aBStack_2b0[0xc] = 0x26;
    aBStack_2b0[0xd] = 0x8d;
    aBStack_2b0[0xe] = 0x77;
    aBStack_2b0[0xf] = 0x15;
    aBStack_2b0[0x10] = 0x9e;
    aBStack_2b0[0x11] = 0x68;
    aBStack_2b0[0x12] = 0xbb;
    aBStack_2b0[0x14] = 0xed;
    aBStack_2b0[0x15] = 0x8f;
    aBStack_2b0[0x16] = 0xf0;
    aBStack_2b0[0x17] = 0xb7;
    aBStack_2b0[0x18] = 0xf1;
    aBStack_2b0[0x19] = 0x99;
    aBStack_2b0[0x1a] = 5;
    aBStack_2b0[0x1b] = 0x15;
    aBStack_2b0[0x1c] = 0x80;
    aBStack_2b0[0x1d] = 100;
    aBStack_2b0[0x1e] = 0xa8;
    aBStack_2b0[0x1f] = 0xd8;
    aBStack_2b0[0x20] = 0x87;
    aBStack_2b0[0x21] = 0xc3;
    aBStack_2b0[0x22] = 0x58;
    aBStack_2b0[0x23] = 0xa9;
    aBStack_2b0[0x24] = 0xce;
    aBStack_2b0[0x25] = 0x26;
    aBStack_2b0[0x26] = 0xfe;
    aBStack_2b0[0x27] = 0xb3;
    aBStack_2b0[0x29] = 0xd7;
    aBStack_2b0[0x2a] = 0xa3;
    aBStack_2b0[0x2b] = 0x81;
    aBStack_2b0[0x2c] = 0xbe;
    aBStack_2b0[0x2d] = 0xb8;
    aBStack_2b0[0x2e] = 0x6e;
    aBStack_2b0[0x30] = 0x15;
    aBStack_2b0[0x31] = 0x68;
    aBStack_2b0[0x32] = 0x44;
    aBStack_2b0[0x33] = 0x17;
    aBStack_2b0[0x34] = 0xbe;
    aBStack_2b0[0x35] = 0x81;
    aBStack_2b0[0x36] = 0x80;
    aBStack_2b0[0x37] = 0x75;
    aBStack_2b0[0x38] = 0xa1;
    aBStack_2b0[0x39] = 0xdb;
    aBStack_2b0[0x3a] = 0xab;
    aBStack_2b0[0x3b] = 0x21;
    aBStack_2b0[0x3c] = 0xd1;
    aBStack_2b0[0x3d] = 0x1f;
    aBStack_2b0[0x3e] = 0xbc;
    aBStack_2b0[0x3f] = 0x9c;
    aBStack_2b0[0x40] = 0x1d;
    aBStack_2b0[0x41] = 0x49;
    aBStack_2b0[0x42] = 0xf0;
    aBStack_2b0[0x43] = 0xe5;
    aBStack_2b0[0x44] = 0xdd;
    aBStack_2b0[0x45] = 0x49;
    aBStack_2b0[0x46] = 0x7f;
    aBStack_2b0[0x47] = 0xb5;
    aBStack_2b0[0x48] = 0xe4;
    aBStack_2b0[0x49] = 9;
    aBStack_2b0[0x4a] = 0xf0;
    aBStack_2b0[0x4b] = 0x39;
    aBStack_2b0[0x4c] = 0x94;
    aBStack_2b0[0x5a] = 0x20;
    uStack_234 = 0x20;
    aBStack_2b0[0x4d] = 0x2a;
    aBStack_2b0[0x66] = 0x2a;
    aBStack_2b0[0x4e] = 0x6b;
    aBStack_2b0[0x4f] = 0x83;
    aBStack_2b0[0x50] = 0xf;
    aBStack_2b0[0x51] = 0xdb;
    aBStack_2b0[0x52] = 0x56;
    aBStack_2b0[0x53] = 0xe;
    aBStack_2b0[0x54] = 0xa3;
    aBStack_2b0[0x55] = 0x61;
    aBStack_2b0[0x56] = 0x9f;
    aBStack_2b0[0x57] = 0x12;
    aBStack_2b0[0x58] = 0xd4;
    aBStack_2b0[0x59] = 0xd7;
    aBStack_2b0[0x5b] = 0x90;
    aBStack_2b0[0x5c] = 0x54;
    aBStack_2b0[0x5d] = 0x9b;
    aBStack_2b0[0x5e] = 0xc6;
    aBStack_2b0[0x5f] = 0x99;
    aBStack_2b0[0x60] = 0xc;
    aBStack_2b0[0x61] = 0x44;
    aBStack_2b0[0x62] = 3;
    aBStack_2b0[99] = 0xd5;
    aBStack_2b0[100] = 0x1b;
    aBStack_2b0[0x65] = 0x9a;
    aBStack_2b0[0x67] = 0xa0;
    aBStack_2b0[0x68] = 0xa2;
    aBStack_2b0[0x69] = 0x8c;
    aBStack_2b0[0x6a] = 0x1c;
    aBStack_2b0[0x6b] = 0xf6;
    aBStack_2b0[0x6c] = 0x68;
    aBStack_2b0[0x6d] = 0xa5;
    aBStack_2b0[0x6e] = 0x57;
    aBStack_2b0[0x6f] = 0x2e;
    aBStack_2b0[0x70] = 0x11;
    aBStack_2b0[0x71] = 0x40;
    aBStack_2b0[0x72] = 0xa5;
    aBStack_2b0[0x73] = 0x8f;
    aBStack_2b0[0x74] = 0x77;
    aBStack_2b0[0x75] = 0x71;
    aBStack_2b0[0x76] = 0xec;
    aBStack_2b0[0x77] = 0x6a;
    piStack_238 = (int *)0x1ecba069;
    uStack_233 = 0x8e;
    uStack_232 = 0xe0;
    uStack_231 = 5;
    puVar14 = &DAT_00b4b9b0;
  }
  pcStack_22c = (code *)0x0;
  uStack_22d = 0;
  uStack_22e = 0;
  uStack_22f = 0;
  uStack_230 = 0;
  cbData = 0x88;
  pBVar19 = aBStack_2b0;
  dwType = 3;
  DVar16 = 0;
  pCVar2 = (LPCSTR)FUN_0081c9b0(puVar14);
  RegSetValueExA(local_228,pCVar2,DVar16,dwType,pBVar19,cbData);
  uVar11 = 1;
LAB_0081abf1:
  RegCloseKey(local_228);
  return uVar11;
}


// ==== FUN_0081ac10 @ 0x0081ac10 ====

undefined1 FUN_0081ac10(void)

{
  char cVar1;
  int iVar2;
  uchar *puVar3;
  LSTATUS LVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  uchar *puVar10;
  int cbMultiByte;
  DWORD DVar11;
  LPCSTR pCVar12;
  REGSAM samDesired;
  LPBOOL lpUsedDefaultChar;
  HKEY *phkResult;
  undefined1 local_53d;
  HKEY local_53c;
  DWORD local_538;
  BYTE local_534 [32];
  CHAR local_514 [260];
  uchar local_410 [260];
  uchar local_30c [260];
  WCHAR local_208 [260];
  
  local_53d = 0;
  GetModuleFileNameW((HMODULE)0x0,local_208,0x104);
  lpUsedDefaultChar = (LPBOOL)0x0;
  pCVar12 = (LPCSTR)0x0;
  puVar3 = local_410;
  cbMultiByte = 0x104;
  iVar2 = FUN_00803417(local_208);
  WideCharToMultiByte(0,0,local_208,iVar2 + 1,(LPSTR)puVar3,cbMultiByte,pCVar12,lpUsedDefaultChar);
  puVar3 = __mbsrchr(local_410,0x5c);
  if (puVar3 != (uchar *)0x0) {
    *puVar3 = '\0';
  }
  phkResult = &local_53c;
  samDesired = 3;
  DVar11 = 0;
  pCVar12 = (LPCSTR)FUN_0081c9b0(&DAT_00b4bb30);
  LVar4 = RegOpenKeyExA((HKEY)0x80000001,pCVar12,DVar11,samDesired,phkResult);
  if (LVar4 != 0) {
    return 0;
  }
  local_538 = 0x104;
  iVar2 = RegEnumValueA(local_53c,0,local_514,&local_538,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,
                        (LPDWORD)0x0);
  DVar11 = 1;
  do {
    if (iVar2 == 0x103) {
      RegCloseKey(local_53c);
      return local_53d;
    }
    if (iVar2 == 0) {
      uVar6 = 0xffffffff;
      pcVar8 = local_514;
      do {
        pcVar9 = pcVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      puVar3 = (uchar *)(pcVar9 + -uVar6);
      puVar10 = local_30c;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)puVar10 = *(undefined4 *)puVar3;
        puVar3 = puVar3 + 4;
        puVar10 = puVar10 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar10 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar10 = puVar10 + 1;
      }
      puVar3 = __mbsrchr(local_30c,0x5c);
      if (puVar3 != (uchar *)0x0) {
        *puVar3 = '\0';
      }
      iVar2 = __mbsicmp(local_30c,local_410);
      if ((iVar2 == 0) &&
         (LVar4 = RegQueryValueExA(local_53c,local_514,(LPDWORD)0x0,(LPDWORD)0x0,local_534,
                                   &local_538), LVar4 == 0)) {
        if (DAT_00b5cf2c != 0) {
          uVar5 = FUN_0081c9b0(&DAT_00b4bb18,local_534);
          FUN_00817c00(DAT_00b5cf2c + 0x20,uVar5);
        }
        LVar4 = RegDeleteValueA(local_53c,local_514);
        if (LVar4 == 0) {
          local_53d = 1;
        }
      }
    }
    local_538 = 0x104;
    iVar2 = RegEnumValueA(local_53c,DVar11,local_514,&local_538,(LPDWORD)0x0,(LPDWORD)0x0,
                          (LPBYTE)0x0,(LPDWORD)0x0);
    DVar11 = DVar11 + 1;
  } while( true );
}


// ==== FUN_0081ae00 @ 0x0081ae00 ====

bool FUN_0081ae00(BYTE param_1)

{
  LPCSTR pCVar1;
  LSTATUS LVar2;
  bool bVar3;
  DWORD DVar4;
  DWORD dwType;
  REGSAM samDesired;
  BYTE *lpData;
  HKEY *phkResult;
  DWORD cbData;
  HKEY local_4;
  
  phkResult = &local_4;
  samDesired = 0xf003f;
  DVar4 = 0;
  bVar3 = false;
  pCVar1 = (LPCSTR)FUN_0081c9b0(&DAT_00b4bb90);
  DVar4 = RegOpenKeyExA((HKEY)0x80000002,pCVar1,DVar4,samDesired,phkResult);
  if (DVar4 == 0) {
    lpData = &param_1;
    cbData = 4;
    dwType = 4;
    pCVar1 = (LPCSTR)FUN_0081c9b0(&DAT_00b4bb78);
    LVar2 = RegSetValueExA(local_4,pCVar1,DVar4,dwType,lpData,cbData);
    bVar3 = LVar2 == 0;
    RegCloseKey(local_4);
  }
  return bVar3;
}


// ==== FUN_0081ae70 @ 0x0081ae70 ====

void FUN_0081ae70(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  HMODULE pHVar4;
  uint uVar5;
  
  pHVar4 = GetModuleHandleA((LPCSTR)0x0);
  if ((short)pHVar4->unused == 0x5a4d) {
    if (((pHVar4[0xd].unused != 0) && (pHVar4[0xe].unused != 0)) &&
       (DAT_00b5cf28 = 1, pHVar4[0xc].unused == 0)) {
      DAT_00b5cf29 = 1;
    }
    uVar1 = pHVar4[0xe].unused;
    if (((uVar1 != 0) && (uVar2 = pHVar4[0xd].unused, uVar2 != 0)) &&
       (uVar3 = pHVar4[0xc].unused, uVar3 != 0)) {
      if (uVar1 < uVar2) {
        uVar5 = uVar2 - uVar1;
      }
      else {
        uVar5 = uVar1 - uVar2;
      }
      if ((uVar3 == uVar5) || ((uVar2 == uVar1 && (uVar3 == uVar2)))) {
        DAT_00b5cf29 = 1;
      }
    }
  }
  return;
}


// ==== FUN_0081aee0 @ 0x0081aee0 ====

void FUN_0081aee0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  return;
}


// ==== FUN_0081aef0 @ 0x0081aef0 ====

void FUN_0081aef0(void)

{
  return;
}


// ==== FUN_0081af00 @ 0x0081af00 ====

bool FUN_0081af00(LPCSTR param_1)

{
  int *lpBuffer;
  char cVar1;
  HANDLE hFile;
  HMODULE pHVar2;
  int *in_ECX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  LPCSTR pCVar7;
  char *pcVar8;
  char *pcVar9;
  DWORD local_240;
  short local_23c [30];
  LONG local_200;
  int local_1fc [13];
  uint local_1c8;
  CHAR local_104 [260];
  
  if (*in_ECX != 0) {
    FUN_0081b0c0();
  }
  GetSystemDirectoryA(local_104,0x104);
  uVar3 = 0xffffffff;
  pcVar6 = &DAT_00b4ae70;
  do {
    pcVar9 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar4 = -1;
  pcVar6 = local_104;
  do {
    pcVar8 = pcVar6;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar8 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar8;
  } while (cVar1 != '\0');
  pcVar6 = pcVar9 + -uVar3;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar3 = 0xffffffff;
  pCVar7 = param_1;
  do {
    pcVar6 = pCVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pCVar7 + 1;
    cVar1 = *pCVar7;
    pCVar7 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar4 = -1;
  pcVar9 = local_104;
  do {
    pcVar8 = pcVar9;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar8 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar8;
  } while (cVar1 != '\0');
  pcVar6 = pcVar6 + -uVar3;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  lpBuffer = in_ECX + 1;
  GetTempPathA(0x104,(LPSTR)lpBuffer);
  GetTempFileNameA((LPCSTR)lpBuffer,&DAT_00b4bbdc,0,(LPSTR)lpBuffer);
  CopyFileA(local_104,(LPCSTR)lpBuffer,0);
  hFile = CreateFileA((LPCSTR)lpBuffer,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    ReadFile(hFile,local_23c,0x40,&local_240,(LPOVERLAPPED)0x0);
    if (local_23c[0] == 0x5a4d) {
      SetFilePointer(hFile,local_200,(PLONG)0x0,0);
      ReadFile(hFile,local_1fc,0xf8,&local_240,(LPOVERLAPPED)0x0);
      if ((local_1fc[0] == 0x4550) && (0x80000000 < local_1c8)) {
        local_1c8 = 0x10000000;
        SetFilePointer(hFile,local_200,(PLONG)0x0,0);
        WriteFile(hFile,local_1fc,0xf8,&local_240,(LPOVERLAPPED)0x0);
      }
    }
    CloseHandle(hFile);
  }
  pHVar2 = LoadLibraryExA((LPCSTR)lpBuffer,(HANDLE)0x0,8);
  *in_ECX = (int)pHVar2;
  if (pHVar2 == (HMODULE)0x0) {
    *(CHAR *)lpBuffer = '\0';
    pHVar2 = LoadLibraryExA(param_1,(HANDLE)0x0,8);
    *in_ECX = (int)pHVar2;
    return pHVar2 != (HMODULE)0x0;
  }
  return true;
}


// ==== FUN_0081b0c0 @ 0x0081b0c0 ====

void FUN_0081b0c0(void)

{
  HANDLE hHeap;
  undefined4 *in_ECX;
  DWORD dwFlags;
  HMODULE hLibModule;
  
  hLibModule = (HMODULE)*in_ECX;
  if (hLibModule != (HMODULE)0x0) {
    if (*(char *)(in_ECX + 1) != '\0') {
      FreeLibrary(hLibModule);
      DeleteFileA((LPCSTR)(in_ECX + 1));
      *in_ECX = 0;
      return;
    }
    dwFlags = 0;
    hHeap = GetProcessHeap();
    HeapFree(hHeap,dwFlags,hLibModule);
    *in_ECX = 0;
  }
  return;
}


// ==== FUN_0081b110 @ 0x0081b110 ====

undefined4 FUN_0081b110(void)

{
  undefined4 *in_ECX;
  
  return *in_ECX;
}


// ==== FUN_0081b120 @ 0x0081b120 ====

void FUN_0081b120(void)

{
  BOOL BVar1;
  HCRYPTPROV *in_ECX;
  
  in_ECX[5] = 0;
  in_ECX[3] = 0;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[9] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0xf] = 0;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  in_ECX[8] = 0;
  in_ECX[0x11] = 0;
  in_ECX[4] = 0;
  BVar1 = CryptAcquireContextA
                    (in_ECX,(LPCSTR)0x0,s_Microsoft_Base_Cryptographic_Pro_00b4ade4,1,0xf0000000);
  if (BVar1 == 0) {
    *in_ECX = 0;
  }
  return;
}


// ==== FUN_0081b170 @ 0x0081b170 ====

void FUN_0081b170(void)

{
  HCRYPTPROV *in_ECX;
  
  if ((void *)in_ECX[1] != (void *)0x0) {
    _free((void *)in_ECX[1]);
    return;
  }
  if ((void *)in_ECX[5] != (void *)0x0) {
    _free((void *)in_ECX[5]);
    return;
  }
  if (in_ECX[3] != 0) {
    CryptDestroyHash(in_ECX[3]);
  }
  if (in_ECX[4] != 0) {
    CryptDestroyKey(in_ECX[4]);
  }
  if (in_ECX[0xf] != 0) {
    CryptDestroyKey(in_ECX[0xf]);
  }
  if (in_ECX[0x10] != 0) {
    CryptDestroyHash(in_ECX[0x10]);
  }
  if (*in_ECX != 0) {
    CryptReleaseContext(*in_ECX,0);
  }
  return;
}


// ==== FUN_0081b1e0 @ 0x0081b1e0 ====

uint FUN_0081b1e0(char *param_1,char param_2)

{
  HCRYPTPROV *pHVar1;
  HCRYPTKEY *phKey;
  HCRYPTHASH *phHash;
  HCRYPTPROV *pHVar2;
  HCRYPTPROV HVar3;
  HANDLE hFile;
  DWORD DVar4;
  uint uVar5;
  uint extraout_EAX;
  void *lpBuffer;
  HCRYPTPROV *pHVar6;
  uint extraout_EAX_00;
  undefined4 *puVar7;
  BOOL BVar8;
  char *pcVar9;
  uint extraout_EAX_01;
  HCRYPTPROV *in_ECX;
  uint uVar10;
  undefined4 *puVar11;
  HCRYPTPROV *local_4;
  
  if (param_1 == (LPCSTR)0x0) {
    in_ECX[0x11] = 1;
    return 0;
  }
  if (*param_1 == '\0') {
    in_ECX[0x11] = 2;
    return (uint)param_1 & 0xffffff00;
  }
  local_4 = in_ECX;
  hFile = CreateFileA(param_1,0x80000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    in_ECX[0x11] = 3;
    return 0xffffff00;
  }
  DVar4 = GetFileSize(hFile,(LPDWORD)0x0);
  in_ECX[9] = DVar4;
  if (DVar4 == 0xffffffff) {
    uVar5 = CloseHandle(hFile);
    in_ECX[0x11] = 0x21;
    return uVar5 & 0xffffff00;
  }
  if ((void *)in_ECX[1] != (void *)0x0) {
    _free((void *)in_ECX[1]);
    return extraout_EAX;
  }
  lpBuffer = _malloc(in_ECX[9]);
  in_ECX[1] = (HCRYPTPROV)lpBuffer;
  if (lpBuffer == (void *)0x0) {
    uVar5 = CloseHandle(hFile);
    in_ECX[0x11] = 4;
    return uVar5 & 0xffffff00;
  }
  ReadFile(hFile,lpBuffer,in_ECX[9],(LPDWORD)&local_4,(LPOVERLAPPED)0x0);
  pHVar6 = (HCRYPTPROV *)in_ECX[9];
  if (local_4 != pHVar6) {
    uVar5 = CloseHandle(hFile);
    in_ECX[0x11] = 5;
    return uVar5 & 0xffffff00;
  }
  pHVar1 = in_ECX + 10;
  pHVar2 = (HCRYPTPROV *)((in_ECX[1] - 0x10) + (int)pHVar6);
  *pHVar1 = *pHVar2;
  in_ECX[0xb] = pHVar2[1];
  in_ECX[0xc] = pHVar2[2];
  in_ECX[0xd] = pHVar2[3];
  if ((*pHVar1 == 0x32812622) && (in_ECX[0xd] == 0x32812621)) {
    *(undefined1 *)(in_ECX + 7) = 1;
    HVar3 = in_ECX[0xc] + 0x10 + in_ECX[0xb];
    in_ECX[0xe] = in_ECX[0xb];
    in_ECX[8] = HVar3;
    in_ECX[2] = (int)pHVar6 - HVar3;
  }
  else {
    *pHVar1 = 0;
    in_ECX[0xb] = 0;
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0;
    pHVar6 = (HCRYPTPROV *)in_ECX[9];
    *(undefined1 *)(in_ECX + 7) = 0;
    in_ECX[8] = 0;
    in_ECX[2] = (HCRYPTPROV)pHVar6;
    in_ECX[0xe] = 0;
  }
  if (pHVar6 < (HCRYPTPROV *)in_ECX[8]) {
    *(undefined1 *)(in_ECX + 7) = 0;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[2] = 0;
    in_ECX[0xe] = 0;
  }
  uVar5 = CloseHandle(hFile);
  if ((char)in_ECX[7] == '\0') {
    in_ECX[0x11] = 6;
    return uVar5 & 0xffffff00;
  }
  in_ECX[6] = in_ECX[0xc];
  if ((void *)in_ECX[5] != (void *)0x0) {
    _free((void *)in_ECX[5]);
    return extraout_EAX_00;
  }
  puVar7 = _malloc(in_ECX[6]);
  in_ECX[5] = (HCRYPTPROV)puVar7;
  if (puVar7 == (undefined4 *)0x0) {
    in_ECX[0x11] = 7;
    return 0;
  }
  uVar5 = in_ECX[6];
  puVar11 = (undefined4 *)(in_ECX[2] + in_ECX[1] + in_ECX[0xe]);
  for (uVar10 = uVar5 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *puVar7 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar7 = puVar7 + 1;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar7 = *(undefined1 *)puVar11;
    puVar11 = (undefined4 *)((int)puVar11 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  if ((*in_ECX == 0) &&
     (BVar8 = CryptAcquireContextA
                        (in_ECX,(LPCSTR)0x0,s_Microsoft_Base_Cryptographic_Pro_00b4ade4,1,0xf0000000
                        ), BVar8 == 0)) {
    in_ECX[0x11] = 8;
    return 0;
  }
  phKey = in_ECX + 4;
  if (in_ECX[4] != 0) {
    CryptDestroyKey(in_ECX[4]);
    *phKey = 0;
  }
  BVar8 = CryptImportKey(*in_ECX,&DAT_00b4bbe0,DAT_00b4bc34,0,0,phKey);
  if (BVar8 == 0) {
    uVar5 = GetLastError();
    if (uVar5 != 0x57) {
LAB_0081b494:
      in_ECX[0x11] = 9;
      return uVar5 & 0xffffff00;
    }
    BVar8 = CryptAcquireContextA
                      (in_ECX,(LPCSTR)0x0,s_Microsoft_Base_Cryptographic_Pro_00b4ade4,1,0xf0000000);
    if (BVar8 == 0) {
      in_ECX[0x11] = 0x62;
      return 0;
    }
    BVar8 = CryptImportKey(*in_ECX,&DAT_00b4bbe0,DAT_00b4bc34,0,0,phKey);
    uVar5 = 0;
    if (BVar8 == 0) goto LAB_0081b494;
  }
  phHash = in_ECX + 3;
  if (in_ECX[3] != 0) {
    CryptDestroyHash(in_ECX[3]);
    *phHash = 0;
  }
  BVar8 = CryptCreateHash(*in_ECX,0x8003,0,0,phHash);
  if (BVar8 == 0) {
    in_ECX[0x11] = 10;
    return 0;
  }
  BVar8 = CryptHashData(*phHash,(BYTE *)in_ECX[1],in_ECX[2] + in_ECX[0xe],0);
  if (BVar8 == 0) {
    in_ECX[0x11] = 0xb;
    return 0;
  }
  BVar8 = CryptVerifySignatureA(*phHash,(BYTE *)in_ECX[5],in_ECX[6],*phKey,(LPCSTR)0x0,0);
  if (BVar8 == 0) {
    uVar5 = GetLastError();
    if (uVar5 == 0x57) {
      BVar8 = CryptAcquireContextA
                        (in_ECX,(LPCSTR)0x0,s_Microsoft_Base_Cryptographic_Pro_00b4ade4,1,0xf0000000
                        );
      if (BVar8 == 0) {
        in_ECX[0x11] = 0x80;
        return 0;
      }
      BVar8 = CryptVerifySignatureA(*phHash,(BYTE *)in_ECX[5],in_ECX[6],*phKey,(LPCSTR)0x0,0);
      uVar5 = 0;
      if (BVar8 != 0) goto LAB_0081b584;
    }
    in_ECX[0x11] = 0xc;
    return uVar5 & 0xffffff00;
  }
LAB_0081b584:
  if (param_2 != '\0') {
    pcVar9 = _strrchr(param_1,0x5c);
    if (pcVar9 != (char *)0x0) {
      param_1 = pcVar9 + 1;
    }
    uVar5 = __strnicmp(param_1,(char *)(in_ECX[2] + in_ECX[1]),in_ECX[0xe]);
    if (uVar5 != 0) {
      in_ECX[0x11] = 0xd;
      return uVar5 & 0xffffff00;
    }
  }
  if ((void *)in_ECX[1] == (void *)0x0) {
    return 1;
  }
  _free((void *)in_ECX[1]);
  return extraout_EAX_01;
}


// ==== FUN_0081b5f0 @ 0x0081b5f0 ====

uint FUN_0081b5f0(LPCSTR param_1,undefined4 *param_2,uint param_3,BYTE *param_4)

{
  HCRYPTPROV *pHVar1;
  HCRYPTHASH *phHash;
  HCRYPTKEY *phKey;
  HCRYPTPROV *pHVar2;
  HCRYPTPROV HVar3;
  BYTE BVar4;
  HANDLE hFile;
  DWORD DVar5;
  uint uVar6;
  uint extraout_EAX;
  void *lpBuffer;
  HCRYPTPROV *pHVar7;
  BOOL BVar8;
  uint extraout_EAX_00;
  HCRYPTPROV *in_ECX;
  uint uVar9;
  undefined4 *puVar10;
  BYTE *pBVar11;
  undefined4 *puVar12;
  HCRYPTPROV *local_4;
  
  local_4 = in_ECX;
  hFile = CreateFileA(param_1,0x80000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    in_ECX[0x11] = 1;
    return 0xffffff00;
  }
  DVar5 = GetFileSize(hFile,(LPDWORD)0x0);
  in_ECX[9] = DVar5;
  if (DVar5 == 0xffffffff) {
    uVar6 = CloseHandle(hFile);
    in_ECX[0x11] = 0xb;
    return uVar6 & 0xffffff00;
  }
  if ((void *)in_ECX[1] != (void *)0x0) {
    _free((void *)in_ECX[1]);
    return extraout_EAX;
  }
  lpBuffer = _malloc(in_ECX[9]);
  in_ECX[1] = (HCRYPTPROV)lpBuffer;
  if (lpBuffer == (void *)0x0) {
    uVar6 = CloseHandle(hFile);
    in_ECX[0x11] = 2;
    return uVar6 & 0xffffff00;
  }
  ReadFile(hFile,lpBuffer,in_ECX[9],(LPDWORD)&local_4,(LPOVERLAPPED)0x0);
  pHVar7 = (HCRYPTPROV *)in_ECX[9];
  if (local_4 != pHVar7) {
    uVar6 = CloseHandle(hFile);
    in_ECX[0x11] = 3;
    return uVar6 & 0xffffff00;
  }
  pHVar1 = in_ECX + 10;
  pHVar2 = (HCRYPTPROV *)((in_ECX[1] - 0x10) + (int)pHVar7);
  *pHVar1 = *pHVar2;
  in_ECX[0xb] = pHVar2[1];
  in_ECX[0xc] = pHVar2[2];
  in_ECX[0xd] = pHVar2[3];
  if ((*pHVar1 == 0x32812622) && (in_ECX[0xd] == 0x32812621)) {
    *(undefined1 *)(in_ECX + 7) = 1;
    HVar3 = in_ECX[0xc] + 0x10 + in_ECX[0xb];
    in_ECX[0xe] = in_ECX[0xb];
    in_ECX[8] = HVar3;
    in_ECX[2] = (int)pHVar7 - HVar3;
  }
  else {
    *pHVar1 = 0;
    in_ECX[0xb] = 0;
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0;
    *(undefined1 *)(in_ECX + 7) = 0;
    pHVar7 = (HCRYPTPROV *)in_ECX[9];
    in_ECX[8] = 0;
    in_ECX[2] = (HCRYPTPROV)pHVar7;
    in_ECX[0xe] = 0;
  }
  if (pHVar7 < (HCRYPTPROV *)in_ECX[8]) {
    *(undefined1 *)(in_ECX + 7) = 0;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[2] = 0;
    in_ECX[0xe] = 0;
  }
  CloseHandle(hFile);
  if (*in_ECX == 0) {
    BVar8 = CryptAcquireContextA
                      (in_ECX,(LPCSTR)0x0,s_Microsoft_Base_Cryptographic_Pro_00b4ade4,1,0xf0000000);
    if (BVar8 == 0) {
      in_ECX[0x11] = 4;
      return 0;
    }
  }
  phHash = in_ECX + 0x10;
  if (in_ECX[0x10] != 0) {
    CryptDestroyHash(in_ECX[0x10]);
    *phHash = 0;
  }
  BVar8 = CryptCreateHash(*in_ECX,0x8003,0,0,phHash);
  if (BVar8 == 0) {
    in_ECX[0x11] = 5;
    return 0;
  }
  uVar6 = 0xffffffff;
  pBVar11 = param_4;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    BVar4 = *pBVar11;
    pBVar11 = pBVar11 + 1;
  } while (BVar4 != '\0');
  BVar8 = CryptHashData(*phHash,param_4,~uVar6 - 1,0);
  if (BVar8 == 0) {
    in_ECX[0x11] = 6;
    return 0;
  }
  phKey = in_ECX + 0xf;
  if (in_ECX[0xf] != 0) {
    CryptDestroyKey(in_ECX[0xf]);
    *phKey = 0;
  }
  BVar8 = CryptDeriveKey(*in_ECX,0x6801,*phHash,0,phKey);
  if (BVar8 == 0) {
    in_ECX[0x11] = 7;
    return 0;
  }
  param_1 = (LPCSTR)in_ECX[2];
  BVar8 = CryptDecrypt(*phKey,0,1,0,(BYTE *)in_ECX[1],(DWORD *)&param_1);
  if (BVar8 == 0) {
    DVar5 = GetLastError();
    if (DVar5 != 0x80090010) {
      in_ECX[0x11] = 8;
      return DVar5 & 0xffffff00;
    }
    uVar6 = FUN_0081b8f0(in_ECX[1],param_1);
    if ((char)uVar6 == '\0') {
      in_ECX[0x11] = 0x58;
      return uVar6;
    }
  }
  uVar6 = param_3;
  if (in_ECX[2] < param_3) {
    uVar6 = in_ECX[2];
  }
  puVar10 = (undefined4 *)in_ECX[1];
  puVar12 = param_2;
  for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *puVar12 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar12 = puVar12 + 1;
  }
  for (uVar9 = uVar6 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
    puVar10 = (undefined4 *)((int)puVar10 + 1);
    puVar12 = (undefined4 *)((int)puVar12 + 1);
  }
  *(undefined1 *)((int)param_2 + uVar6) = 0;
  if ((void *)in_ECX[1] == (void *)0x0) {
    return 1;
  }
  _free((void *)in_ECX[1]);
  return extraout_EAX_00;
}


// ==== FUN_0081b8f0 @ 0x0081b8f0 ====

undefined4 FUN_0081b8f0(undefined4 param_1,undefined4 param_2)

{
  BOOL BVar1;
  int in_ECX;
  DWORD local_41c;
  BYTE local_418 [5];
  undefined4 local_413;
  undefined4 local_40f;
  undefined2 local_40b;
  undefined1 local_409;
  undefined1 local_408 [1032];
  
  local_41c = 0x10;
  BVar1 = CryptGetHashParam(*(HCRYPTHASH *)(in_ECX + 0x40),2,local_418,&local_41c,0);
  if (BVar1 == 0) {
    return 0;
  }
  local_413 = 0;
  local_40f = 0;
  local_40b = 0;
  local_409 = 0;
  FUN_0081c200(local_408,0x10,local_418);
  FUN_0081c2f0(local_408,param_2,param_1,param_1);
  return 1;
}


// ==== FUN_0081b980 @ 0x0081b980 ====

undefined4 FUN_0081b980(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x138);
}


// ==== FUN_0081b990 @ 0x0081b990 ====

undefined4 FUN_0081b990(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x144);
}


// ==== FUN_0081b9a0 @ 0x0081b9a0 ====

int FUN_0081b9a0(void)

{
  int in_ECX;
  
  return in_ECX + 0x18;
}


// ==== FUN_0081b9b0 @ 0x0081b9b0 ====

undefined4 FUN_0081b9b0(undefined4 param_1,int param_2,CHAR *param_3)

{
  int iVar1;
  LPCSTR nNumberOfBytesToWrite;
  BOOL BVar2;
  DWORD DVar3;
  int in_ECX;
  uint uVar4;
  CHAR *pCVar5;
  HANDLE hFile;
  undefined4 *lpBuffer;
  DWORD local_148;
  undefined4 local_144;
  undefined4 local_140;
  int local_13c;
  LPCSTR local_138;
  undefined4 local_134;
  undefined4 local_130;
  int local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  int local_10c;
  LPCSTR local_108;
  CHAR local_104 [260];
  
  hFile = *(HANDLE *)(in_ECX + 4);
  if (hFile == (HANDLE)0xffffffff) {
    return 0;
  }
  local_140 = *(undefined4 *)(in_ECX + 0xc);
  local_144 = param_1;
  local_13c = param_2;
  local_138 = param_3;
  if (param_2 == 0x613) {
    iVar1 = lstrlenA(param_3);
    local_138 = (LPCSTR)(iVar1 + 1);
    if ((LPCSTR)0x104 < local_138) {
      param_3[0x103] = '\0';
      local_138 = (LPCSTR)0x104;
    }
    local_114 = local_144;
    local_10c = local_13c;
    local_110 = local_140;
    pCVar5 = local_104;
    for (uVar4 = (uint)local_138 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pCVar5 = *(undefined4 *)param_3;
      param_3 = param_3 + 4;
      pCVar5 = pCVar5 + 4;
    }
    nNumberOfBytesToWrite = local_138 + 0x10;
    for (uVar4 = (uint)local_138 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pCVar5 = *param_3;
      param_3 = param_3 + 1;
      pCVar5 = pCVar5 + 1;
    }
    lpBuffer = &local_114;
    hFile = *(HANDLE *)(in_ECX + 4);
    local_108 = local_138;
  }
  else if (param_2 == 0x619) {
    local_12c = param_2;
    local_120 = *(undefined4 *)(param_3 + 4);
    local_138 = (LPCSTR)0x10;
    local_134 = param_1;
    local_124 = *(undefined4 *)param_3;
    local_128 = 0x10;
    local_11c = *(undefined4 *)(param_3 + 8);
    local_118 = *(undefined4 *)(param_3 + 0xc);
    lpBuffer = &local_134;
    nNumberOfBytesToWrite = (LPCSTR)0x20;
    local_130 = local_140;
  }
  else {
    lpBuffer = &local_144;
    nNumberOfBytesToWrite = (LPCSTR)0x10;
  }
  BVar2 = WriteFile(hFile,lpBuffer,(DWORD)nNumberOfBytesToWrite,&local_148,(LPOVERLAPPED)0x0);
  if ((BVar2 == 0) && (((DVar3 = GetLastError(), DVar3 == 0x6d || (DVar3 == 0xe8)) || (DVar3 == 6)))
     ) {
    return 0;
  }
  return 1;
}


// ==== FUN_0081bb10 @ 0x0081bb10 ====

undefined4 FUN_0081bb10(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int in_ECX;
  uint uVar2;
  
  if (*(int *)(in_ECX + 0x14c) != 0x619) {
    if (((*(int *)(in_ECX + 0x148) == param_1) && (*(int *)(in_ECX + 0x14c) == param_2)) &&
       (*(int *)(in_ECX + 0x150) == param_3)) {
      uVar2 = *(int *)(in_ECX + 0x154) + 1;
      *(uint *)(in_ECX + 0x154) = uVar2;
      if (2 < uVar2) {
        return CONCAT31((int3)(uVar2 >> 8),1);
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0x154) = 0;
    }
    *(int *)(in_ECX + 0x148) = param_1;
    *(int *)(in_ECX + 0x14c) = param_2;
    *(int *)(in_ECX + 0x150) = param_3;
  }
  uVar1 = FUN_0081b9b0(param_1,param_2,param_3);
  return uVar1;
}


// ==== FUN_0081bb90 @ 0x0081bb90 ====

void FUN_0081bb90(void)

{
  undefined4 *in_ECX;
  _SYSTEMTIME local_10;
  
  GetLocalTime(&local_10);
  in_ECX[1] = 0xffffffff;
  in_ECX[2] = 0xffffffff;
  in_ECX[3] = (uint)local_10.wDay * (uint)local_10.wMonth * (uint)local_10.wYear ^ 0xdad53a;
  *in_ECX = 0;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  return;
}


// ==== FUN_0081bc00 @ 0x0081bc00 ====

undefined4 FUN_0081bc00(void)

{
  PHANDLE ppvVar1;
  HANDLE pvVar2;
  BOOL BVar3;
  HANDLE pvVar4;
  HANDLE pvVar5;
  int in_ECX;
  LPHANDLE lpTargetHandle;
  LPHANDLE lpTargetHandle_00;
  DWORD DVar6;
  DWORD DVar7;
  _SECURITY_ATTRIBUTES local_c;
  
  lpTargetHandle_00 = (LPHANDLE)(in_ECX + 4);
  if (*(int *)(in_ECX + 4) != -1) {
    return 0;
  }
  local_c.nLength = 0xc;
  local_c.bInheritHandle = 1;
  local_c.lpSecurityDescriptor = (LPVOID)0x0;
  pvVar2 = GetStdHandle(0xfffffff5);
  *(HANDLE *)(in_ECX + 0x134) = pvVar2;
  ppvVar1 = (PHANDLE)(in_ECX + 0x140);
  BVar3 = CreatePipe(ppvVar1,(PHANDLE)(in_ECX + 0x144),&local_c,0);
  if (BVar3 == 0) {
    return 0;
  }
  BVar3 = SetStdHandle(0xfffffff5,*(PHANDLE)(in_ECX + 0x144));
  if (BVar3 == 0) {
    return 0;
  }
  DVar7 = 2;
  BVar3 = 0;
  lpTargetHandle = (LPHANDLE)(in_ECX + 8);
  DVar6 = 0;
  pvVar4 = GetCurrentProcess();
  pvVar2 = *ppvVar1;
  pvVar5 = GetCurrentProcess();
  BVar3 = DuplicateHandle(pvVar5,pvVar2,pvVar4,lpTargetHandle,DVar6,BVar3,DVar7);
  if (BVar3 == 0) {
    return 0;
  }
  CloseHandle(*ppvVar1);
  pvVar2 = GetStdHandle(0xfffffff6);
  *(HANDLE *)(in_ECX + 0x130) = pvVar2;
  ppvVar1 = (PHANDLE)(in_ECX + 0x13c);
  BVar3 = CreatePipe((PHANDLE)(in_ECX + 0x138),ppvVar1,&local_c,0);
  if (BVar3 == 0) {
    return 0;
  }
  BVar3 = SetStdHandle(0xfffffff6,*(PHANDLE)(in_ECX + 0x138));
  if (BVar3 == 0) {
    return 0;
  }
  DVar7 = 2;
  BVar3 = 0;
  DVar6 = 0;
  pvVar4 = GetCurrentProcess();
  pvVar2 = *ppvVar1;
  pvVar5 = GetCurrentProcess();
  BVar3 = DuplicateHandle(pvVar5,pvVar2,pvVar4,lpTargetHandle_00,DVar6,BVar3,DVar7);
  if (BVar3 == 0) {
    return 0;
  }
  CloseHandle(*ppvVar1);
  return 1;
}


// ==== FUN_0081bd50 @ 0x0081bd50 ====

uint FUN_0081bd50(void)

{
  BOOL BVar1;
  HANDLE pvVar2;
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  if (in_ECX[1] == -1) {
    return 0;
  }
  local_4 = in_ECX;
  BVar1 = SetStdHandle(0xfffffff6,(HANDLE)in_ECX[0x4c]);
  if (BVar1 == 0) {
    return 0;
  }
  BVar1 = SetStdHandle(0xfffffff5,(HANDLE)in_ECX[0x4d]);
  if (BVar1 == 0) {
    return 0;
  }
  pvVar2 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  in_ECX[4] = pvVar2;
  if (pvVar2 == (HANDLE)0x0) {
    return 0;
  }
  pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0081be50,in_ECX,0,(LPDWORD)&local_4);
  *in_ECX = pvVar2;
  return -(uint)(pvVar2 != (HANDLE)0x0) & (uint)local_4;
}


// ==== FUN_0081bdd0 @ 0x0081bdd0 ====

undefined4 FUN_0081bdd0(void)

{
  DWORD DVar1;
  undefined4 *in_ECX;
  
  if (in_ECX[1] == -1) {
    return 0;
  }
  if ((HANDLE)in_ECX[4] != (HANDLE)0x0) {
    SetEvent((HANDLE)in_ECX[4]);
  }
  if ((HANDLE)*in_ECX != (HANDLE)0x0) {
    DVar1 = WaitForSingleObject((HANDLE)*in_ECX,100);
    if (DVar1 == 0x102) {
      TerminateThread((HANDLE)*in_ECX,0);
    }
    CloseHandle((HANDLE)*in_ECX);
    *in_ECX = 0;
  }
  if ((HANDLE)in_ECX[1] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)in_ECX[1]);
    in_ECX[1] = 0xffffffff;
  }
  if ((HANDLE)in_ECX[2] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)in_ECX[2]);
    in_ECX[2] = 0xffffffff;
  }
  return 1;
}


// ==== FUN_0081be50 @ 0x0081be50 ====

undefined4 FUN_0081be50(int param_1)

{
  char cVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  DWORD local_24;
  DWORD local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00a0bce8;
  puStack_10 = &DAT_0080015c;
  local_14 = ExceptionList;
  local_1c = (undefined1 *)((int)register0x00000010 + -0x50);
  local_24 = 0;
  local_44 = 0;
  local_30 = 0;
  local_8 = 0;
  ExceptionList = &local_14;
LAB_0081be8d:
  do {
    if (local_24 == 0) {
      BVar2 = PeekNamedPipe(*(HANDLE *)(param_1 + 8),(LPVOID)0x0,0,(LPDWORD)0x0,&local_24,
                            (LPDWORD)0x0);
      if ((BVar2 == 0) && (cVar1 = FUN_008187b0(param_1,0x60f,0), cVar1 == '\0')) goto LAB_0081c179;
      if (local_24 != 0) goto LAB_0081bf81;
      DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x10),0x32);
      if ((DVar3 == 0) ||
         ((local_30 = local_30 + 1, 199 < local_30 &&
          (((cVar1 = FUN_0081b9b0(0x8b1,0x60e,0), cVar1 == '\0' &&
            (cVar1 = FUN_008187b0(param_1,0x60f,0), cVar1 == '\0')) ||
           ((799 < local_30 && (cVar1 = FUN_008187b0(param_1,0x618,local_30), cVar1 == '\0'))))))))
      goto LAB_0081c179;
      if ((*(char *)(param_1 + 0x14) == '\0') || (local_44 = local_44 + 1, local_44 < 0x50))
      goto LAB_0081be8d;
      local_44 = 0;
      *(undefined1 *)(param_1 + 0x14) = 0;
      cVar1 = FUN_0081b9b0(0x8b0,0,0);
      if (cVar1 != '\0') goto LAB_0081be8d;
      cVar1 = FUN_008187b0(param_1,0x60f,0);
    }
    else {
LAB_0081bf81:
      local_30 = 0;
      BVar2 = ReadFile(*(HANDLE *)(param_1 + 8),&local_40,0x10,&local_20,(LPOVERLAPPED)0x0);
      if (((BVar2 == 0) || (local_20 == 0)) &&
         (cVar1 = FUN_008187b0(param_1,0x60f,0), cVar1 == '\0')) goto LAB_0081c179;
      local_24 = local_24 - local_20;
      if (local_38 == 0x60e) goto LAB_0081be8d;
      if (local_40 == 0x8b1) {
        if (local_38 == 0x613) {
          if ((0x104 < local_34) ||
             (((BVar2 = ReadFile(*(HANDLE *)(param_1 + 8),(LPVOID)(param_1 + 0x2c),local_34,
                                 &local_20,(LPOVERLAPPED)0x0), BVar2 == 0 || (local_20 == 0)) &&
              (cVar1 = FUN_008187b0(param_1,0x60f,0), cVar1 == '\0')))) goto LAB_0081c179;
          local_24 = local_24 - local_20;
          goto LAB_0081be8d;
        }
        if (local_38 == 0x619) {
          if ((local_34 < 0x11) &&
             (((BVar2 = ReadFile(*(HANDLE *)(param_1 + 8),(LPVOID)(param_1 + 0x18),local_34,
                                 &local_20,(LPOVERLAPPED)0x0), BVar2 != 0 && (local_20 != 0)) ||
              (cVar1 = FUN_008187b0(param_1,0x60f,0), cVar1 != '\0')))) {
            local_24 = local_24 - local_20;
            cVar1 = FUN_008187b0(param_1,local_38,local_34);
            goto joined_r0x0081c0af;
          }
          goto LAB_0081c179;
        }
      }
      if (local_40 == 0x8b2) {
        if (local_38 == 0) {
          *(undefined1 *)(param_1 + 0x14) = 0;
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          goto LAB_0081be8d;
        }
        if (local_38 != 0x610) goto LAB_0081be8d;
        cVar1 = FUN_008187b0(param_1,0x610,0);
      }
      else {
        if (local_40 == 0x8b0) {
          if (*(int *)(param_1 + 0xc) == local_3c) {
            cVar1 = FUN_0081b9b0(0x8b2,local_38,0);
            if ((cVar1 == '\0') && (cVar1 = FUN_008187b0(param_1,0x60f,0), cVar1 == '\0'))
            goto LAB_0081c179;
            *(undefined1 *)(param_1 + 0x14) = 1;
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          }
          else {
            cVar1 = FUN_008187b0(param_1,0x60f,0);
            if (cVar1 == '\0') goto LAB_0081c179;
            *(undefined1 *)(param_1 + 0x14) = 1;
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          }
          goto LAB_0081be8d;
        }
        if (local_40 != 0x8b1) goto LAB_0081be8d;
        if ((local_38 == 0x610) && (cVar1 = FUN_008187b0(param_1,0x610,0), cVar1 == '\0'))
        goto LAB_0081c179;
        cVar1 = FUN_0081b9b0(0x8b2,local_38,local_34);
        if (cVar1 == '\0') {
          cVar1 = FUN_008187b0(param_1,0x60f,0);
        }
        else {
          cVar1 = FUN_008187b0(param_1,local_38,local_34);
        }
      }
    }
joined_r0x0081c0af:
    if (cVar1 == '\0') {
LAB_0081c179:
      if (*(HANDLE *)(param_1 + 8) != (HANDLE)0xffffffff) {
        CloseHandle(*(HANDLE *)(param_1 + 8));
        *(undefined4 *)(param_1 + 8) = 0xffffffff;
      }
      DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x10),30000);
      if (((DVar3 == 0) && (local_38 != 0x610)) && (local_38 != 0x60f)) {
        FUN_0081b9b0(0x8b1,0x610,0);
      }
      ExceptionList = local_14;
      return 0;
    }
  } while( true );
}


// ==== FUN_0081c1d4 @ 0x0081c1d4 ====

undefined4 FUN_0081c1d4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return 0;
}


// ==== FUN_0081c200 @ 0x0081c200 ====

void FUN_0081c200(uint *param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  
  puVar2 = param_1;
  puVar1 = param_1 + 2;
  uVar6 = 0;
  uVar3 = 0;
  puVar5 = puVar1;
  do {
    *puVar5 = uVar3;
    uVar3 = uVar3 + 1;
    puVar5 = puVar5 + 1;
  } while (uVar3 < 0x100);
  *param_1 = 0;
  param_1[1] = 0;
  iVar4 = 0;
  param_1 = (uint *)0x40;
  do {
    puVar5 = puVar2 + 4;
    uVar3 = puVar2[2];
    uVar6 = *(byte *)(iVar4 + param_3) + uVar3 + uVar6 & 0xff;
    iVar4 = iVar4 + 1;
    if (iVar4 == param_2) {
      iVar4 = 0;
    }
    puVar2[2] = puVar1[uVar6];
    puVar1[uVar6] = uVar3;
    uVar3 = puVar2[3];
    uVar6 = *(byte *)(iVar4 + param_3) + uVar3 + uVar6 & 0xff;
    iVar4 = iVar4 + 1;
    if (iVar4 == param_2) {
      iVar4 = 0;
    }
    puVar2[3] = puVar1[uVar6];
    puVar1[uVar6] = uVar3;
    uVar3 = *puVar5;
    uVar6 = *(byte *)(iVar4 + param_3) + uVar3 + uVar6 & 0xff;
    iVar4 = iVar4 + 1;
    if (iVar4 == param_2) {
      iVar4 = 0;
    }
    *puVar5 = puVar1[uVar6];
    puVar1[uVar6] = uVar3;
    uVar3 = puVar2[5];
    uVar6 = *(byte *)(iVar4 + param_3) + uVar3 + uVar6 & 0xff;
    iVar4 = iVar4 + 1;
    if (iVar4 == param_2) {
      iVar4 = 0;
    }
    puVar2[5] = puVar1[uVar6];
    puVar1[uVar6] = uVar3;
    param_1 = (uint *)((int)param_1 + -1);
    puVar2 = puVar5;
  } while (param_1 != (uint *)0x0);
  return;
}


// ==== FUN_0081c2f0 @ 0x0081c2f0 ====

void FUN_0081c2f0(uint *param_1,uint param_2,byte *param_3,byte *param_4)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = param_1[1];
  uVar7 = *param_1;
  if (param_2 >> 3 != 0) {
    uVar5 = uVar7 + 1 & 0xff;
    uVar7 = param_1[uVar5 + 2];
    uVar3 = uVar4 + uVar7 & 0xff;
    uVar4 = param_1[uVar3 + 2];
    param_1[uVar5 + 2] = uVar4;
    param_1[uVar3 + 2] = uVar7;
    *param_4 = (byte)param_1[(uVar4 + uVar7 & 0xff) + 2] ^ *param_3;
    uVar5 = uVar5 + 1 & 0xff;
    uVar4 = param_1[uVar5 + 2];
    uVar3 = uVar3 + uVar4 & 0xff;
    uVar7 = param_1[uVar3 + 2];
    param_1[uVar5 + 2] = uVar7;
    param_1[uVar3 + 2] = uVar4;
    param_4[1] = (byte)param_1[(uVar7 + uVar4 & 0xff) + 2] ^ param_3[1];
    uVar5 = uVar5 + 1 & 0xff;
    uVar4 = param_1[uVar5 + 2];
    uVar3 = uVar3 + uVar4 & 0xff;
    uVar7 = param_1[uVar3 + 2];
    param_1[uVar5 + 2] = uVar7;
    param_1[uVar3 + 2] = uVar4;
    param_4[2] = (byte)param_1[(uVar7 + uVar4 & 0xff) + 2] ^ param_3[2];
    uVar5 = uVar5 + 1 & 0xff;
    uVar4 = param_1[uVar5 + 2];
    uVar3 = uVar3 + uVar4 & 0xff;
    uVar7 = param_1[uVar3 + 2];
    param_1[uVar5 + 2] = uVar7;
    param_1[uVar3 + 2] = uVar4;
    param_4[3] = (byte)param_1[(uVar7 + uVar4 & 0xff) + 2] ^ param_3[3];
    uVar5 = uVar5 + 1 & 0xff;
    uVar4 = param_1[uVar5 + 2];
    uVar3 = uVar3 + uVar4 & 0xff;
    uVar7 = param_1[uVar3 + 2];
    param_1[uVar5 + 2] = uVar7;
    param_1[uVar3 + 2] = uVar4;
    param_4[4] = (byte)param_1[(uVar7 + uVar4 & 0xff) + 2] ^ param_3[4];
    uVar5 = uVar5 + 1 & 0xff;
    uVar4 = param_1[uVar5 + 2];
    uVar3 = uVar3 + uVar4 & 0xff;
    uVar7 = param_1[uVar3 + 2];
    param_1[uVar5 + 2] = uVar7;
    param_1[uVar3 + 2] = uVar4;
    param_4[5] = (byte)param_1[(uVar7 + uVar4 & 0xff) + 2] ^ param_3[5];
    uVar6 = uVar5 + 1 & 0xff;
    uVar4 = param_1[uVar6 + 2];
    uVar5 = uVar3 + uVar4 & 0xff;
    uVar7 = param_1[uVar5 + 2];
    param_1[uVar6 + 2] = uVar7;
    param_1[uVar5 + 2] = uVar4;
    param_4[6] = (byte)param_1[(uVar7 + uVar4 & 0xff) + 2] ^ param_3[6];
    uVar7 = uVar6 + 1 & 0xff;
    uVar3 = param_1[uVar7 + 2];
    uVar4 = uVar5 + uVar3 & 0xff;
    uVar5 = param_1[uVar4 + 2];
    param_1[uVar7 + 2] = uVar5;
    param_1[uVar4 + 2] = uVar3;
    param_4[7] = (byte)param_1[(uVar5 + uVar3 & 0xff) + 2] ^ param_3[7];
    pbVar1 = param_4 + 8;
    param_3 = param_3 + 8;
    param_4 = (byte *)((param_2 >> 3) - 1);
    if (param_4 != (byte *)0x0) {
      do {
        uVar5 = uVar7 + 1 & 0xff;
        uVar7 = param_1[uVar5 + 2];
        uVar3 = uVar4 + uVar7 & 0xff;
        uVar4 = param_1[uVar3 + 2];
        param_1[uVar5 + 2] = uVar4;
        param_1[uVar3 + 2] = uVar7;
        *pbVar1 = (byte)param_1[(uVar4 + uVar7 & 0xff) + 2] ^ *param_3;
        uVar5 = uVar5 + 1 & 0xff;
        uVar4 = param_1[uVar5 + 2];
        uVar3 = uVar3 + uVar4 & 0xff;
        uVar7 = param_1[uVar3 + 2];
        param_1[uVar5 + 2] = uVar7;
        param_1[uVar3 + 2] = uVar4;
        pbVar1[1] = (byte)param_1[(uVar7 + uVar4 & 0xff) + 2] ^ param_3[1];
        uVar5 = uVar5 + 1 & 0xff;
        uVar4 = param_1[uVar5 + 2];
        uVar3 = uVar3 + uVar4 & 0xff;
        uVar7 = param_1[uVar3 + 2];
        param_1[uVar5 + 2] = uVar7;
        param_1[uVar3 + 2] = uVar4;
        pbVar1[2] = (byte)param_1[(uVar7 + uVar4 & 0xff) + 2] ^ param_3[2];
        uVar5 = uVar5 + 1 & 0xff;
        uVar4 = param_1[uVar5 + 2];
        uVar3 = uVar3 + uVar4 & 0xff;
        uVar7 = param_1[uVar3 + 2];
        param_1[uVar5 + 2] = uVar7;
        param_1[uVar3 + 2] = uVar4;
        pbVar1[3] = (byte)param_1[(uVar7 + uVar4 & 0xff) + 2] ^ param_3[3];
        uVar5 = uVar5 + 1 & 0xff;
        uVar4 = param_1[uVar5 + 2];
        uVar3 = uVar3 + uVar4 & 0xff;
        uVar7 = param_1[uVar3 + 2];
        param_1[uVar5 + 2] = uVar7;
        param_1[uVar3 + 2] = uVar4;
        pbVar1[4] = (byte)param_1[(uVar7 + uVar4 & 0xff) + 2] ^ param_3[4];
        uVar5 = uVar5 + 1 & 0xff;
        uVar4 = param_1[uVar5 + 2];
        uVar3 = uVar3 + uVar4 & 0xff;
        uVar7 = param_1[uVar3 + 2];
        param_1[uVar5 + 2] = uVar7;
        param_1[uVar3 + 2] = uVar4;
        pbVar1[5] = (byte)param_1[(uVar7 + uVar4 & 0xff) + 2] ^ param_3[5];
        uVar6 = uVar5 + 1 & 0xff;
        uVar4 = param_1[uVar6 + 2];
        uVar5 = uVar3 + uVar4 & 0xff;
        uVar7 = param_1[uVar5 + 2];
        param_1[uVar6 + 2] = uVar7;
        param_1[uVar5 + 2] = uVar4;
        pbVar1[6] = (byte)param_1[(uVar7 + uVar4 & 0xff) + 2] ^ param_3[6];
        uVar7 = uVar6 + 1 & 0xff;
        uVar3 = param_1[uVar7 + 2];
        uVar4 = uVar5 + uVar3 & 0xff;
        uVar5 = param_1[uVar4 + 2];
        param_1[uVar7 + 2] = uVar5;
        param_1[uVar4 + 2] = uVar3;
        pbVar1[7] = (byte)param_1[(uVar5 + uVar3 & 0xff) + 2] ^ param_3[7];
        pbVar1 = pbVar1 + 8;
        param_3 = param_3 + 8;
        param_4 = (byte *)((int)param_4 + -1);
      } while (param_4 != (byte *)0x0);
    }
    param_4 = pbVar1;
  }
  if ((param_2 & 7) != 0) {
    uVar7 = uVar7 + 1 & 0xff;
    uVar3 = param_1[uVar7 + 2];
    uVar4 = uVar4 + uVar3 & 0xff;
    uVar5 = param_1[uVar4 + 2];
    param_1[uVar7 + 2] = uVar5;
    param_1[uVar4 + 2] = uVar3;
    *param_4 = (byte)param_1[(uVar5 + uVar3 & 0xff) + 2] ^ *param_3;
    for (iVar2 = (param_2 & 7) - 1; iVar2 != 0; iVar2 = iVar2 + -7) {
      uVar7 = uVar7 + 1 & 0xff;
      uVar3 = param_1[uVar7 + 2];
      uVar4 = uVar4 + uVar3 & 0xff;
      uVar5 = param_1[uVar4 + 2];
      param_1[uVar7 + 2] = uVar5;
      param_1[uVar4 + 2] = uVar3;
      param_4[1] = (byte)param_1[(uVar5 + uVar3 & 0xff) + 2] ^ param_3[1];
      if (iVar2 == 1) break;
      uVar7 = uVar7 + 1 & 0xff;
      uVar3 = param_1[uVar7 + 2];
      uVar4 = uVar4 + uVar3 & 0xff;
      uVar5 = param_1[uVar4 + 2];
      param_1[uVar7 + 2] = uVar5;
      param_1[uVar4 + 2] = uVar3;
      param_4[2] = (byte)param_1[(uVar5 + uVar3 & 0xff) + 2] ^ param_3[2];
      if (iVar2 == 2) break;
      uVar7 = uVar7 + 1 & 0xff;
      uVar3 = param_1[uVar7 + 2];
      uVar4 = uVar4 + uVar3 & 0xff;
      uVar5 = param_1[uVar4 + 2];
      param_1[uVar7 + 2] = uVar5;
      param_1[uVar4 + 2] = uVar3;
      param_4[3] = (byte)param_1[(uVar5 + uVar3 & 0xff) + 2] ^ param_3[3];
      if (iVar2 == 3) break;
      uVar7 = uVar7 + 1 & 0xff;
      uVar3 = param_1[uVar7 + 2];
      uVar4 = uVar4 + uVar3 & 0xff;
      uVar5 = param_1[uVar4 + 2];
      param_1[uVar7 + 2] = uVar5;
      param_1[uVar4 + 2] = uVar3;
      param_4[4] = (byte)param_1[(uVar5 + uVar3 & 0xff) + 2] ^ param_3[4];
      if (iVar2 == 4) break;
      uVar7 = uVar7 + 1 & 0xff;
      uVar3 = param_1[uVar7 + 2];
      uVar4 = uVar4 + uVar3 & 0xff;
      uVar5 = param_1[uVar4 + 2];
      param_1[uVar7 + 2] = uVar5;
      param_1[uVar4 + 2] = uVar3;
      param_4[5] = (byte)param_1[(uVar5 + uVar3 & 0xff) + 2] ^ param_3[5];
      if (iVar2 == 5) break;
      uVar7 = uVar7 + 1 & 0xff;
      uVar3 = param_1[uVar7 + 2];
      uVar4 = uVar4 + uVar3 & 0xff;
      uVar5 = param_1[uVar4 + 2];
      param_1[uVar7 + 2] = uVar5;
      param_1[uVar4 + 2] = uVar3;
      param_4[6] = (byte)param_1[(uVar5 + uVar3 & 0xff) + 2] ^ param_3[6];
      param_4 = param_4 + 7;
      param_3 = param_3 + 7;
      if (iVar2 == 6) break;
      uVar7 = uVar7 + 1 & 0xff;
      uVar3 = param_1[uVar7 + 2];
      uVar4 = uVar4 + uVar3 & 0xff;
      uVar5 = param_1[uVar4 + 2];
      param_1[uVar7 + 2] = uVar5;
      param_1[uVar4 + 2] = uVar3;
      *param_4 = (byte)param_1[(uVar5 + uVar3 & 0xff) + 2] ^ *param_3;
    }
  }
  *param_1 = uVar7;
  param_1[1] = uVar4;
  return;
}


// ==== FUN_0081c8a0 @ 0x0081c8a0 ====

undefined * FUN_0081c8a0(LPCSTR param_1)

{
  int iVar1;
  char cVar2;
  LPCSTR pCVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  pCVar3 = param_1;
  iVar4 = lstrlenA(param_1);
  if (iVar4 == 0) {
    return &DAT_00b5d010;
  }
  uVar5 = (uint)param_1 & 0xff;
  DAT_00b5d011 = (char)param_1;
  DAT_00b5d010 = 1;
  param_1._0_1_ = DAT_00b5d011 * '\x03' + 0x65;
  iVar6 = 4;
  iVar1 = (uVar5 * 3 + 1) * 3;
  cVar2 = (char)iVar1;
  if (0 < iVar4) {
    do {
      iVar1 = (iVar1 + 1) * 3;
      (&DAT_00b5d010)[iVar6] = pCVar3[iVar6 + -4] ^ (char)iVar1 + 0x65U;
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  (&DAT_00b5d010)[iVar6] = 0;
  DAT_00b5d012 = (byte)((uint)(iVar6 + -4) >> 8) ^ (byte)param_1;
  DAT_00b5d013 = cVar2 + 0x65U ^ (byte)(iVar6 + -4);
  return &DAT_00b5d010;
}


// ==== FUN_0081c940 @ 0x0081c940 ====

void FUN_0081c940(char *param_1)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  
  if (param_1 == (char *)0x0) {
    return;
  }
  if (*param_1 == '\x01') {
    cVar2 = param_1[1] * '\t';
    cVar1 = cVar2 + '\x03';
    param_1[2] = param_1[2] ^ param_1[1] * '\x03' + 0x65U;
    iVar5 = 0;
    bVar4 = param_1[3] ^ cVar2 + 0x68U;
    uVar3 = (uint)CONCAT11(param_1[2],bVar4);
    param_1[3] = bVar4;
    if (uVar3 != 0) {
      do {
        cVar1 = (cVar1 + '\x01') * '\x03';
        param_1[iVar5] = param_1[iVar5 + 4] ^ cVar1 + 0x65U;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar3);
    }
    param_1[uVar3] = '\0';
  }
  return;
}


// ==== FUN_0081c9b0 @ 0x0081c9b0 ====

char * FUN_0081c9b0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  DWORD DVar5;
  DWORD *pDVar6;
  uint uVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  byte local_400 [1024];
  
  if ((DAT_00b5d008 & 1) == 0) {
    DAT_00b5d008 = DAT_00b5d008 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00b5cf68);
    _atexit((_func_4879 *)&LAB_0081cb80);
  }
  if (param_1 == (char *)0x0) {
    return (char *)0x0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00b5cf68);
  if (*param_1 == '\x01') {
    iVar11 = 0;
    cVar3 = param_1[1] * '\t';
    cVar1 = cVar3 + '\x03';
    param_1[2] = param_1[2] ^ param_1[1] * '\x03' + 0x65U;
    bVar9 = param_1[3] ^ cVar3 + 0x68U;
    uVar7 = (uint)CONCAT11(param_1[2],bVar9);
    param_1[3] = bVar9;
    if (uVar7 != 0) {
      do {
        cVar1 = (cVar1 + '\x01') * '\x03';
        param_1[iVar11] = param_1[iVar11 + 4] ^ cVar1 + 0x65U;
        iVar11 = iVar11 + 1;
      } while (iVar11 < (int)uVar7);
    }
    param_1[uVar7] = '\0';
  }
  DVar5 = GetCurrentThreadId();
  uVar7 = 1;
  pDVar6 = &DAT_00b5cf8c;
  do {
    if (*pDVar6 == DVar5) {
      uVar4 = uVar7;
      if (uVar7 != 0) goto LAB_0081caa1;
      break;
    }
    pDVar6 = pDVar6 + 1;
    uVar7 = uVar7 + 1;
    uVar4 = 0;
  } while ((int)pDVar6 < 0xb5cfb0);
  uVar7 = uVar4;
  if (DAT_00b5d410 < 9) {
    uVar7 = DAT_00b5d410 + 1;
    DAT_00b5d410 = uVar7;
    *(DWORD *)(uVar7 * 4 + 0xb5cf88) = DVar5;
  }
LAB_0081caa1:
  pcVar2 = (char *)(&DAT_00b5cfb0)[uVar7];
  (&DAT_00b5cfb0)[uVar7] = param_1;
  if ((((pcVar2 != (char *)0x0) && (pcVar2 != param_1)) && (*param_1 != '\x01')) &&
     (*pcVar2 != '\x01')) {
    lstrcpy(local_400,pcVar2);
    iVar11 = lstrlenA((LPCSTR)local_400);
    if (iVar11 != 0) {
      *pcVar2 = '\x01';
      iVar10 = 4;
      pcVar2[1] = '\0';
      iVar8 = 0;
      cVar1 = '\x03';
      if (0 < iVar11) {
        do {
          cVar1 = (cVar1 + '\x01') * '\x03';
          pcVar2[iVar10] = local_400[iVar8] ^ cVar1 + 0x65U;
          iVar10 = iVar10 + 1;
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar11);
      }
      pcVar2[iVar10] = '\0';
      pcVar2[2] = (byte)((uint)(iVar10 + -4) >> 8) ^ 0x65;
      pcVar2[3] = (byte)(iVar10 + -4) ^ 0x68;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00b5cf68);
  return param_1;
}


// ==== FUN_0081cb90 @ 0x0081cb90 ====

undefined4 FUN_0081cb90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_84;
  char local_80 [64];
  char local_40 [64];
  
  _sprintf(local_80,&DAT_00b4bc4c,param_3);
  FUN_0081cc00(param_1,param_2,local_80,local_40,0x40,param_4);
  local_84 = 0;
  _sscanf(local_40,&DAT_00b4bc4c,&local_84);
  return local_84;
}


// ==== FUN_0081cc00 @ 0x0081cc00 ====

int FUN_0081cc00(undefined4 param_1,undefined4 param_2,uchar *param_3,uchar *param_4,size_t param_5,
                undefined4 param_6)

{
  uchar uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uchar *puVar6;
  uchar local_180 [64];
  uchar local_140 [63];
  uchar auStack_101 [257];
  
  _sprintf((char *)local_140,&DAT_00b4bc54,param_1);
  _sprintf((char *)local_180,&DAT_00b4bc50,param_2);
  uVar4 = 0xffffffff;
  puVar6 = local_140;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
  } while (uVar1 != '\0');
  uVar5 = 0xffffffff;
  puVar6 = local_180;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
  } while (uVar1 != '\0');
  pcVar2 = (char *)FUN_0081cd80(param_6,auStack_101 + 1);
  iVar3 = __mbsnbicmp(local_140,auStack_101 + 1,~uVar4 - 1);
  while (iVar3 != 0) {
    if (*pcVar2 == '\0') goto LAB_0081cd55;
    pcVar2 = (char *)FUN_0081cd80(pcVar2,auStack_101 + 1);
    iVar3 = __mbsnbicmp(local_140,auStack_101 + 1,~uVar4 - 1);
  }
  pcVar2 = (char *)FUN_0081cd80(pcVar2,auStack_101 + 1);
  while (auStack_101[1] != '[') {
    iVar3 = __mbsnbicmp(local_180,auStack_101 + 1,~uVar5 - 1);
    if (iVar3 == 0) {
      uVar4 = 0xffffffff;
      puVar6 = local_180;
      goto code_r0x0081cd47;
    }
    if (*pcVar2 == '\0') break;
    pcVar2 = (char *)FUN_0081cd80(pcVar2,auStack_101 + 1);
  }
  goto LAB_0081cd55;
  while( true ) {
    uVar4 = uVar4 - 1;
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    if (uVar1 == '\0') break;
code_r0x0081cd47:
    if (uVar4 == 0) break;
  }
  param_3 = auStack_101 + ~uVar4;
LAB_0081cd55:
  __mbsnbcpy(param_4,param_3,param_5);
  uVar4 = 0xffffffff;
  param_4[param_5 - 1] = '\0';
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    uVar1 = *param_4;
    param_4 = param_4 + 1;
  } while (uVar1 != '\0');
  return ~uVar4 - 1;
}


// ==== FUN_0081cd80 @ 0x0081cd80 ====

char * FUN_0081cd80(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  if (cVar1 != '\0') {
    while ((cVar1 != '\r' && (cVar1 != '\n'))) {
      *param_2 = cVar1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
      if ((0xfe < iVar2) || (cVar1 = *param_1, cVar1 == '\0')) break;
    }
  }
  *param_2 = '\0';
  if (*param_1 == '\r') {
    param_1 = param_1 + 1;
  }
  if (*param_1 == '\n') {
    param_1 = param_1 + 1;
  }
  return param_1;
}


// ==== FUN_0081cdd0 @ 0x0081cdd0 ====

void FUN_0081cdd0(void)

{
  FUN_0081cde0();
  FUN_0081cdf0();
  return;
}


// ==== FUN_0081cde0 @ 0x0081cde0 ====

void FUN_0081cde0(void)

{
  FUN_0081ce10();
  return;
}


// ==== FUN_0081cdf0 @ 0x0081cdf0 ====

void FUN_0081cdf0(void)

{
  _atexit(FUN_0081ce00);
  return;
}


// ==== FUN_0081ce00 @ 0x0081ce00 ====

void FUN_0081ce00(void)

{
  FUN_0081aef0();
  return;
}


// ==== FUN_0081ce10 @ 0x0081ce10 ====

void FUN_0081ce10(void)

{
  uint *in_ECX;
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    iVar2 = 8;
    uVar1 = uVar3;
    do {
      if ((uVar1 & 1) == 0) {
        uVar1 = uVar1 >> 1;
      }
      else {
        uVar1 = uVar1 >> 1 ^ 0xedb88320;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *in_ECX = uVar1;
    uVar3 = uVar3 + 1;
    in_ECX = in_ECX + 1;
  } while ((int)uVar3 < 0x100);
  return;
}


// ==== FUN_0081ce50 @ 0x0081ce50 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 FUN_0081ce50(LPCSTR param_1,uint *param_2)

{
  HANDLE hFile;
  int iVar1;
  byte *pbVar2;
  int in_ECX;
  DWORD local_1004;
  byte local_1000 [4092];
  undefined4 uStack_4;
  
  uStack_4 = 0x81ce5a;
  *param_2 = 0xffffffff;
  if ((param_1 == (LPCSTR)0x0) || (*param_1 == '\0')) {
    *(undefined4 *)(in_ECX + 0x400) = 1;
    return 0;
  }
  hFile = CreateFileA(param_1,0x80000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    *(undefined4 *)(in_ECX + 0x400) = 2;
    return 0;
  }
  iVar1 = ReadFile(hFile,local_1000,0x1000,&local_1004,(LPOVERLAPPED)0x0);
  do {
    if (iVar1 == 0) {
LAB_0081cf2f:
      *(undefined4 *)(in_ECX + 0x400) = 3;
LAB_0081cf39:
      CloseHandle(hFile);
      *param_2 = ~*param_2;
      return 1;
    }
    if (local_1004 == 0) {
      if (iVar1 != 0) goto LAB_0081cf39;
      goto LAB_0081cf2f;
    }
    for (pbVar2 = local_1000; pbVar2 < local_1000 + local_1004; pbVar2 = pbVar2 + 1) {
      *param_2 = *(uint *)(in_ECX + (uint)(byte)((byte)*param_2 ^ *pbVar2) * 4) ^ *param_2 >> 8;
    }
    iVar1 = ReadFile(hFile,local_1000,0x1000,&local_1004,(LPOVERLAPPED)0x0);
  } while( true );
}


// ==== FUN_0081cfb0 @ 0x0081cfb0 ====

void FUN_0081cfb0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009991bb;
  local_c = ExceptionList;
  if (DAT_00b5ace8 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x30);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_0081de90(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081d000 @ 0x0081d000 ====

void FUN_0081d000(void)

{
  if (DAT_00b5ace8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ace8)(1);
  }
  return;
}


// ==== FUN_0081d020 @ 0x0081d020 ====

void FUN_0081d020(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009991db;
  local_c = ExceptionList;
  if (DAT_00b5acec == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x1c);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_0081e4b0(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081d070 @ 0x0081d070 ====

void FUN_0081d070(void)

{
  if (DAT_00b5acec != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5acec)(1);
  }
  return;
}


// ==== FUN_0081d090 @ 0x0081d090 ====

void FUN_0081d090(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009991fb;
  local_c = ExceptionList;
  if (DAT_00b5a794 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x70);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_0081fd70(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081d0e0 @ 0x0081d0e0 ====

void FUN_0081d0e0(void)

{
  if (DAT_00b5a794 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a794)(1);
  }
  return;
}


// ==== FUN_0081d100 @ 0x0081d100 ====

void FUN_0081d100(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099921b;
  local_c = ExceptionList;
  if (DAT_00b5ac68 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_008225c0(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081d150 @ 0x0081d150 ====

void FUN_0081d150(void)

{
  if (DAT_00b5ac68 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ac68)(1);
  }
  return;
}


// ==== FUN_0081d170 @ 0x0081d170 ====

void FUN_0081d170(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099923b;
  local_c = ExceptionList;
  if (DAT_00b5acf0 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x3c);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_00823b10(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081d1c0 @ 0x0081d1c0 ====

void FUN_0081d1c0(void)

{
  if (DAT_00b5acf0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5acf0)(1);
  }
  return;
}


// ==== FUN_0081d1e0 @ 0x0081d1e0 ====

void FUN_0081d1e0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099925b;
  local_c = ExceptionList;
  if (DAT_00b5acf4 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x30);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_00824b70(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081d230 @ 0x0081d230 ====

void FUN_0081d230(void)

{
  if (DAT_00b5acf4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5acf4)(1);
  }
  return;
}


// ==== FUN_0081d250 @ 0x0081d250 ====

int FUN_0081d250(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      param_2 = *(int *)(in_ECX + 0xc) + param_2;
    }
    else {
      iVar1 = 0;
      if (param_1 != 2) goto LAB_0081d27e;
      param_2 = *(int *)(in_ECX + 8) + param_2;
    }
  }
  iVar1 = param_2;
  if (param_2 < 0) {
    return -1;
  }
LAB_0081d27e:
  if (iVar1 < *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 0xc) = iVar1;
    return iVar1;
  }
  return -1;
}


// ==== FUN_0081d2a0 @ 0x0081d2a0 ====

void FUN_0081d2a0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00999278;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0be80;
  in_ECX[1] = param_1;
  uVar1 = FUN_004cc8c0();
  in_ECX[2] = uVar1;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081d300 @ 0x0081d300 ====

void FUN_0081d300(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099928a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0be80;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(in_ECX[1]);
    in_ECX[1] = 0;
  }
  *in_ECX = &PTR_FUN_009ae824;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081d360 @ 0x0081d360 ====

uint FUN_0081d360(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = *(int *)(in_ECX + 8) - *(int *)(in_ECX + 0xc);
  if (uVar1 < param_1) {
    param_1 = uVar1;
  }
  iVar2 = FUN_004cc960(param_1);
  FUN_00797a80(param_2,iVar2 + *(int *)(in_ECX + 0xc));
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + param_1;
  return param_1;
}


// ==== FUN_0081d3a0 @ 0x0081d3a0 ====

void FUN_0081d3a0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009992a4;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0be80;
  uVar1 = FUN_004022a0(local_28,s_share__00a0be70,param_1);
  local_4._0_1_ = 1;
  uVar1 = FUN_0050f070(uVar1);
  in_ECX[1] = uVar1;
  local_4 = (uint)local_4._1_3_ << 8;
  if (local_10 < 0x10) {
    uVar1 = FUN_004cc8c0();
    in_ECX[2] = uVar1;
    in_ECX[3] = 0;
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_0081d440 @ 0x0081d440 ====

void FUN_0081d440(byte param_1)

{
  void *in_ECX;
  
  FUN_0081d300();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0081d460 @ 0x0081d460 ====

int FUN_0081d460(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      param_2 = *(int *)(in_ECX + 8) + param_2;
    }
    else {
      iVar1 = 0;
      if (param_1 != 2) goto LAB_0081d48e;
      param_2 = *(int *)(in_ECX + 4) + param_2;
    }
  }
  iVar1 = param_2;
  if (param_2 < 0) {
    return -1;
  }
LAB_0081d48e:
  if (iVar1 < *(int *)(in_ECX + 4)) {
    *(int *)(in_ECX + 8) = iVar1;
    return iVar1;
  }
  return -1;
}


// ==== FUN_0081d4c0 @ 0x0081d4c0 ====

void FUN_0081d4c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009992b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0be90;
  local_4 = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  *in_ECX = &PTR_FUN_009ae824;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081d510 @ 0x0081d510 ====

uint FUN_0081d510(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = *(int *)(in_ECX + 4) - *(int *)(in_ECX + 8);
  if (uVar1 < param_1) {
    param_1 = uVar1;
  }
  iVar2 = FUN_00426450();
  FUN_00797a80(param_2,*(int *)(in_ECX + 8) + iVar2,param_1);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return param_1;
}


// ==== FUN_0081d550 @ 0x0081d550 ====

void FUN_0081d550(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *in_ECX;
  undefined1 local_60 [12];
  undefined4 uStack_54;
  uint uStack_50;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  void *local_2c;
  undefined1 local_28 [16];
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009992e2;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_00a0be90;
  uVar1 = FUN_00404890(local_44);
  local_4._0_1_ = 1;
  FUN_004045b0(local_28,uVar1);
  local_4._0_1_ = 3;
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_2c = (void *)0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00405bd0(local_60,local_28,param_1);
  local_4 = CONCAT31(local_4._1_3_,4);
  piVar2 = (int *)(**(code **)(*DAT_00b5a740 + 4))(local_60,6);
  in_ECX[3] = piVar2;
  uVar1 = (**(code **)(*piVar2 + 0x10))();
  in_ECX[1] = uVar1;
  in_ECX[2] = 0;
  if (0xf < uStack_50) {
    _free(in_ECX);
    return;
  }
  uStack_50 = 0xf;
  uStack_54 = 0;
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_0081d650 @ 0x0081d650 ====

void FUN_0081d650(byte param_1)

{
  void *in_ECX;
  
  FUN_0081d4c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0081d670 @ 0x0081d670 ====

void FUN_0081d670(void)

{
  return;
}


// ==== FUN_0081d680 @ 0x0081d680 ====

void FUN_0081d680(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  return;
}


// ==== FUN_0081d6a0 @ 0x0081d6a0 ====

void FUN_0081d6a0(void)

{
  return;
}


// ==== FUN_0081d6b0 @ 0x0081d6b0 ====

float10 FUN_0081d6b0(int param_1)

{
  float *pfVar1;
  float *in_ECX;
  float fVar2;
  
  if (in_ECX[5] == 0.0) {
    in_ECX[7] = (float)((int)in_ECX[7] + param_1);
    fVar2 = in_ECX[2];
    if ((int)in_ECX[7] <= (int)fVar2) goto LAB_0081d724;
    if (in_ECX[3] == 2.8026e-45) {
      in_ECX[5] = 1.4013e-45;
    }
    else {
      if (in_ECX[3] != 4.2039e-45) {
        in_ECX[7] = 0.0;
        goto LAB_0081d724;
      }
      in_ECX[5] = 2.8026e-45;
    }
  }
  else {
    if (in_ECX[5] != 1.4013e-45) goto LAB_0081d724;
    pfVar1 = in_ECX + 7;
    *pfVar1 = (float)((int)*pfVar1 - param_1);
    if (-1 < (int)*pfVar1) goto LAB_0081d724;
    if (in_ECX[3] == 2.8026e-45) {
      in_ECX[7] = 0.0;
      in_ECX[5] = 0.0;
      goto LAB_0081d724;
    }
    if (in_ECX[3] == 5.60519e-45) {
      in_ECX[7] = 0.0;
      in_ECX[5] = 2.8026e-45;
      goto LAB_0081d724;
    }
    fVar2 = in_ECX[2];
  }
  in_ECX[7] = fVar2;
LAB_0081d724:
  fVar2 = ((float)(int)in_ECX[7] / (float)(int)in_ECX[2]) * in_ECX[4] + *in_ECX;
  in_ECX[6] = fVar2;
  return (float10)fVar2;
}


// ==== FUN_0081d760 @ 0x0081d760 ====

void FUN_0081d760(void)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = 0;
  in_ECX[1] = 0;
  *in_ECX = 0;
  in_ECX[3] = DAT_0099d080;
  return;
}


// ==== FUN_0081d790 @ 0x0081d790 ====

void FUN_0081d790(void)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = 0;
  in_ECX[1] = 0;
  *in_ECX = 0;
  in_ECX[3] = DAT_0099d080;
  return;
}


// ==== FUN_0081d7e0 @ 0x0081d7e0 ====

void FUN_0081d7e0(void)

{
  undefined1 local_10 [16];
  
  thunk_FUN_007a0810(local_10);
  thunk_FUN_007a0af7();
  return;
}


// ==== FUN_0081d830 @ 0x0081d830 ====

void FUN_0081d830(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_4c;
  undefined1 local_40 [60];
  undefined4 *puStack_4;
  
  thunk_FUN_0079fb96(local_40);
  puVar2 = (undefined4 *)(local_40 + -8);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puStack_4 = *puVar2;
    puVar2 = puVar2 + 1;
    puStack_4 = puStack_4 + 1;
  }
  return;
}


// ==== FUN_0081d860 @ 0x0081d860 ====

void FUN_0081d860(float param_1,float param_2,float param_3,float param_4)

{
  float *in_ECX;
  
  *in_ECX = param_2;
  in_ECX[1] = param_3;
  if ((int)param_4 < 1) {
    param_4 = 1.4013e-45;
  }
  in_ECX[2] = param_4;
  in_ECX[3] = param_1;
  in_ECX[4] = ABS(param_3 - param_2);
  if (param_1 == 7.00649e-45) {
    in_ECX[5] = 2.8026e-45;
    in_ECX[6] = param_2;
    in_ECX[7] = 0.0;
    return;
  }
  if (((param_1 == 2.8026e-45) || (param_1 == 0.0)) || (param_1 == 4.2039e-45)) {
    in_ECX[5] = 0.0;
    in_ECX[6] = param_2;
    in_ECX[7] = 0.0;
    return;
  }
  in_ECX[6] = param_3;
  in_ECX[7] = param_4;
  in_ECX[5] = 1.4013e-45;
  return;
}


// ==== FUN_0081d8f0 @ 0x0081d8f0 ====

void FUN_0081d8f0(undefined4 param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [16];
  
  local_1c = DAT_0099d080;
  local_18 = 0;
  local_14 = 0;
  thunk_FUN_007a095f(local_10,&local_1c,param_1);
  thunk_FUN_007a0af7();
  return;
}


// ==== FUN_0081d940 @ 0x0081d940 ====

void FUN_0081d940(undefined4 param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [16];
  
  local_1c = 0;
  local_18 = DAT_0099d080;
  local_14 = 0;
  thunk_FUN_007a095f(local_10,&local_1c,param_1);
  thunk_FUN_007a0af7();
  return;
}


// ==== FUN_0081d990 @ 0x0081d990 ====

void FUN_0081d990(undefined4 param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [16];
  
  local_1c = 0;
  local_18 = 0;
  local_14 = DAT_0099d080;
  thunk_FUN_007a095f(local_10,&local_1c,param_1);
  thunk_FUN_007a0af7();
  return;
}


// ==== FUN_0081d9e0 @ 0x0081d9e0 ====

int FUN_0081d9e0(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      param_2 = *(int *)(in_ECX + 0xc) + param_2;
    }
    else {
      iVar1 = 0;
      if (param_1 != 2) goto LAB_0081da0e;
      param_2 = *(int *)(in_ECX + 8) + param_2;
    }
  }
  iVar1 = param_2;
  if (param_2 < 0) {
    return -1;
  }
LAB_0081da0e:
  if (iVar1 < *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 0xc) = iVar1;
    return iVar1;
  }
  return -1;
}


// ==== FUN_0081da30 @ 0x0081da30 ====

void FUN_0081da30(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009992f8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0bee0;
  in_ECX[1] = param_1;
  uVar1 = FUN_004cc8c0();
  in_ECX[2] = uVar1;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081da90 @ 0x0081da90 ====

void FUN_0081da90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099930a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0bee0;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x1c))(in_ECX[1]);
    in_ECX[1] = 0;
  }
  *in_ECX = &PTR_FUN_009ae824;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081daf0 @ 0x0081daf0 ====

uint FUN_0081daf0(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = *(int *)(in_ECX + 8) - *(int *)(in_ECX + 0xc);
  if (uVar1 < param_1) {
    param_1 = uVar1;
  }
  iVar2 = FUN_004cc960(param_1);
  FUN_00797a80(param_2,iVar2 + *(int *)(in_ECX + 0xc));
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + param_1;
  return param_1;
}


// ==== FUN_0081db30 @ 0x0081db30 ====

void FUN_0081db30(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099931c;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0bee0;
  uVar1 = FUN_0050f070(param_1);
  in_ECX[1] = uVar1;
  uVar1 = FUN_004cc8c0();
  in_ECX[2] = uVar1;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081db90 @ 0x0081db90 ====

void FUN_0081db90(byte param_1)

{
  void *in_ECX;
  
  FUN_0081da90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0081dbb0 @ 0x0081dbb0 ====

void FUN_0081dbb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0bf70;
  return;
}


// ==== FUN_0081dbc0 @ 0x0081dbc0 ====

void FUN_0081dbc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0bf70;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0081dbe0 @ 0x0081dbe0 ====

void FUN_0081dbe0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099934e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0bf80;
  local_4 = 2;
  FUN_004eb890(in_ECX + 8);
  DAT_00b5ace8 = 0;
  if ((void *)in_ECX[9] != (void *)0x0) {
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[6] = 0;
    in_ECX[7] = 0xf;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_00a0bf70;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0081dc80 @ 0x0081dc80 ====

void FUN_0081dc80(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099936e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar3 = operator_new(0x10);
  local_4 = 0;
  if (pvVar3 == (void *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_0081d3a0(param_1);
  }
  local_4 = 0xffffffff;
  pvVar3 = operator_new(0x2c);
  local_4 = 1;
  if (pvVar3 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_008257e0(puVar4);
  }
  local_4 = 0xffffffff;
  iVar2 = *(int *)(in_ECX + 0x24);
  if ((iVar2 == 0) ||
     (piVar1 = (int *)(in_ECX + 0x28), in_ECX = param_2, (uint)(*piVar1 - iVar2 >> 2) <= param_2)) {
    uVar5 = FUN_0081df30();
    param_2 = in_ECX;
  }
  *(undefined4 *)(iVar2 + param_2 * 4) = uVar5;
  if (puVar4 != (undefined4 *)0x0) {
    (**(code **)*puVar4)(1);
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0081dd40 @ 0x0081dd40 ====

int FUN_0081dd40(undefined4 param_1,uint param_2)

{
  int extraout_EAX;
  int extraout_EAX_00;
  int iVar1;
  int in_ECX;
  uint extraout_EDX;
  undefined1 local_44 [4];
  void *local_40;
  uint local_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00999388;
  local_c = ExceptionList;
  if ((int)param_2 < 4) {
    iVar1 = *(int *)(in_ECX + 0x24);
    if ((iVar1 == 0) ||
       (ExceptionList = &local_c, (uint)(*(int *)(in_ECX + 0x28) - iVar1 >> 2) <= param_2)) {
      ExceptionList = &local_c;
      FUN_0081df30();
      param_2 = extraout_EDX;
    }
    if (*(int *)(iVar1 + param_2 * 4) != 0) {
      iVar1 = FUN_00825540();
      ExceptionList = local_c;
      return iVar1;
    }
    FUN_00401740(s_NULL_Type_ShareString____u__u_00a0bf48,0x1d);
    FUN_00797530(auStack_28);
    local_4 = 1;
    FUN_00401660();
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return extraout_EAX_00;
    }
  }
  else {
    ExceptionList = &local_c;
    FUN_00401740(s_Invalid_ShareString_Type____u_00a0bf28,0x1d);
    FUN_00797530(local_44);
    local_4 = 0;
    FUN_00401660();
    if (0xf < local_2c) {
      _free(local_40);
      return extraout_EAX;
    }
  }
  ExceptionList = local_c;
  return in_ECX + 4;
}


// ==== FUN_0081de90 @ 0x0081de90 ====

void FUN_0081de90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009993b0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0bf80;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  local_4 = 2;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ace8 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ace8 = in_ECX;
  }
  FUN_0081e1f0(4,0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081df10 @ 0x0081df10 ====

void FUN_0081df10(byte param_1)

{
  void *in_ECX;
  
  FUN_0081dbe0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0081df30 @ 0x0081df30 ====

void FUN_0081df30(void)

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
  puStack_8 = &LAB_009993c8;
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


// ==== FUN_0081dfa0 @ 0x0081dfa0 ====

void FUN_0081dfa0(void)

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
  puStack_8 = &LAB_009993c8;
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


// ==== FUN_0081e010 @ 0x0081e010 ====

void FUN_0081e010(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_0081dfa0();
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


// ==== FUN_0081e1f0 @ 0x0081e1f0 ====

void FUN_0081e1f0(uint param_1,undefined1 param_2)

{
  void *_Dst;
  uint uVar1;
  int iVar2;
  void *pvVar3;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    FUN_0081e010(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if (((iVar2 != 0) && (pvVar3 = *(void **)(in_ECX + 8), param_1 < (uint)((int)pvVar3 - iVar2 >> 2))
      ) && (_Dst = (void *)(iVar2 + param_1 * 4), _Dst != pvVar3)) {
    pvVar3 = _memmove(_Dst,pvVar3,0);
    *(void **)(in_ECX + 8) = pvVar3;
  }
  return;
}


// ==== FUN_0081e280 @ 0x0081e280 ====

void FUN_0081e280(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0c000;
  return;
}


// ==== FUN_0081e290 @ 0x0081e290 ====

void FUN_0081e290(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0c000;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0081e2b0 @ 0x0081e2b0 ====

void FUN_0081e2b0(void)

{
  int *in_ECX;
  
  if ((char)in_ECX[1] == '\x01') {
    (**(code **)(*in_ECX + 0xc))();
  }
                    /* WARNING: Could not recover jumptable at 0x0081e2c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 8))();
  return;
}


// ==== FUN_0081e2d0 @ 0x0081e2d0 ====

void FUN_0081e2d0(void)

{
  int iVar1;
  int *in_ECX;
  
  if ((char)in_ECX[1] == '\x01') {
    if ((int *)in_ECX[2] != (int *)0x0) {
      iVar1 = (**(code **)(*(int *)in_ECX[2] + 4))();
      *(undefined4 *)(iVar1 + 0x28) = 0;
      (**(code **)(*DAT_00b5a7cc + 0x2c))(in_ECX[2]);
      in_ECX[2] = 0;
    }
    *(undefined1 *)(in_ECX + 1) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0081e30b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 8))();
  return;
}


// ==== FUN_0081e310 @ 0x0081e310 ====

void FUN_0081e310(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    if (*(int *)(in_ECX + 8) != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 8));
      *(undefined4 *)(in_ECX + 8) = 0;
    }
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0081e340 @ 0x0081e340 ====

undefined4 FUN_0081e340(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  int unaff_ESI;
  undefined1 uStack00000000;
  undefined1 auStack_2 [2];
  
  if ((char)in_ECX[1] != '\0') {
    iVar1 = (**(code **)(*in_ECX + 0x18))(param_1);
    if (iVar1 != 0) {
      iVar1 = in_ECX[2];
      FUN_0079bba0(auStack_2 + -6,&uStack00000000);
      if (unaff_ESI != *(int *)(iVar1 + 0x40)) {
        return *(undefined4 *)(unaff_ESI + 0x10);
      }
    }
  }
  return 0;
}


// ==== FUN_0081e390 @ 0x0081e390 ====

int FUN_0081e390(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *in_ECX;
  int unaff_retaddr;
  
  iVar1 = (**(code **)(*in_ECX + 0x18))(param_3);
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  if (param_1 == 1) {
    FUN_00401660(iVar1 + 4,0,0xffffffff);
    return unaff_retaddr;
  }
  if (param_1 == 2) {
    FUN_00401660(iVar1 + 0x20,0,0xffffffff);
    return unaff_retaddr;
  }
  FUN_00401740(&DAT_00a0bff6,0);
  return unaff_retaddr;
}


// ==== FUN_0081e410 @ 0x0081e410 ====

uint FUN_0081e410(char param_1)

{
  char *pcVar1;
  char *pcVar2;
  int in_ECX;
  char *pcVar3;
  
  pcVar1 = *(char **)(in_ECX + 0x14);
  pcVar3 = *(char **)(in_ECX + 0x10);
  pcVar2 = operator_new(0x58);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2[0x18] = '\0';
    pcVar2[0x19] = '\0';
    pcVar2[0x1a] = '\0';
    pcVar2[0x1b] = '\0';
    pcVar2[0x1c] = '\x0f';
    pcVar2[0x1d] = '\0';
    pcVar2[0x1e] = '\0';
    pcVar2[0x1f] = '\0';
    pcVar2[8] = '\0';
    pcVar2[0x38] = '\x0f';
    pcVar2[0x39] = '\0';
    pcVar2[0x3a] = '\0';
    pcVar2[0x3b] = '\0';
    pcVar2[0x34] = '\0';
    pcVar2[0x35] = '\0';
    pcVar2[0x36] = '\0';
    pcVar2[0x37] = '\0';
    pcVar2[0x24] = '\0';
    pcVar2[0x54] = '\x0f';
    pcVar2[0x55] = '\0';
    pcVar2[0x56] = '\0';
    pcVar2[0x57] = '\0';
    pcVar2[0x50] = '\0';
    pcVar2[0x51] = '\0';
    pcVar2[0x52] = '\0';
    pcVar2[0x53] = '\0';
    pcVar2[0x40] = '\0';
  }
  for (; pcVar3 != pcVar1; pcVar3 = pcVar3 + 0x58) {
    if (*pcVar3 == param_1) {
      *pcVar2 = *pcVar3;
      pcVar2[1] = pcVar3[1];
      FUN_00401660(pcVar3 + 4,0,0xffffffff);
      FUN_00401660(pcVar3 + 0x20,0,0xffffffff);
      FUN_00401660(pcVar3 + 0x3c,0,0xffffffff);
    }
  }
  return (*pcVar2 != param_1) - 1 & (uint)pcVar2;
}


// ==== FUN_0081e4b0 @ 0x0081e4b0 ====

void FUN_0081e4b0(void)

{
  int *piVar1;
  int *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00999473;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_00a0c028;
  piVar1 = in_ECX + 1;
  *(char *)piVar1 = '\0';
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  local_4 = 1;
  DAT_00b5acec = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    DAT_00b5acec = in_ECX;
  }
  if ((char)*piVar1 == '\x01') {
    (**(code **)(*in_ECX + 0xc))();
  }
  (**(code **)(*in_ECX + 8))();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0081e520 @ 0x0081e520 ====

void FUN_0081e520(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00999490;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_00a0c028;
  local_4 = 1;
  if (*(char *)(in_ECX + 1) != '\0') {
    if (in_ECX[2] != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[2]);
      in_ECX[2] = 0;
    }
    *(undefined1 *)(in_ECX + 1) = 0;
  }
  DAT_00b5acec = 0;
  FUN_006dfe40();
  *in_ECX = &PTR_FUN_00a0c000;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0081e5a0 @ 0x0081e5a0 ====

undefined4 FUN_0081e5a0(void)

{
  int iVar1;
  char cVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined1 local_b0 [4];
  void *local_ac;
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined1 local_9c [4];
  void *local_98;
  undefined4 local_88;
  uint local_84;
  undefined1 local_80 [4];
  void *local_7c;
  undefined4 uStack_6c;
  uint local_68;
  undefined1 uStack_64;
  undefined1 uStack_63;
  undefined1 local_5c;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_24;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009994c0;
  local_c = ExceptionList;
  local_84 = 0xf;
  local_88 = 0;
  local_98 = (void *)((uint)local_98 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_Environment_sky_table_txt_00a0bfdc,0x19);
  local_4 = 0;
  FUN_00410500(local_9c);
  local_4 = 0xffffffff;
  if (0xf < local_84) {
    _free(local_98);
    return extraout_EAX;
  }
  local_84 = 0xf;
  local_88 = 0;
  local_98 = (void *)((uint)local_98 & 0xffffff00);
  FUN_0049d760();
  FUN_0049d780();
  cVar2 = FUN_0049d7c0();
  while( true ) {
    if (cVar2 != '\0') {
      ExceptionList = local_c;
      return 1;
    }
    FUN_0049d800(local_80);
    local_ac = (void *)0x0;
    local_a8 = 0;
    local_a4 = 0;
    local_4 = 2;
    FUN_00404fb0(local_80,0x2c,local_b0);
    if (local_ac == (void *)0x0) break;
    iVar1 = (local_a8 - (int)local_ac) / 0x1c;
    if (iVar1 == 0) {
      if (local_ac != (void *)0x0) {
        FUN_00405de0(local_ac,local_a8,local_b0,local_a0);
        _free(local_ac);
        return extraout_EAX_02;
      }
      break;
    }
    local_48 = 0xf;
    local_4c = 0;
    local_5c = 0;
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    local_10 = 0xf;
    local_14 = 0;
    local_24 = 0;
    local_4 = CONCAT31(local_4._1_3_,3);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uStack_64 = thunk_FUN_00796f50(local_ac);
    if ((local_ac == (void *)0x0) || ((uint)((local_a8 - (int)local_ac) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    FUN_00401660((int)local_ac + 0x1c,0,0xffffffff);
    if ((local_ac == (void *)0x0) || ((uint)((local_a8 - (int)local_ac) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    FUN_00401660((int)local_ac + 0x38,0,0xffffffff);
    if ((local_ac == (void *)0x0) || ((uint)((local_a8 - (int)local_ac) / 0x1c) < 4)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    uStack_63 = thunk_FUN_00796f50((int)local_ac + 0x54);
    if ((local_ac == (void *)0x0) || ((uint)((local_a8 - (int)local_ac) / 0x1c) < 5)) {
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
    FUN_00401660((int)local_ac + 0x70,0,0xffffffff);
    FUN_0081f010(&uStack_64);
    FUN_006dfb30();
    if (local_ac != (void *)0x0) {
      FUN_00405de0(local_ac,local_a8,local_b0,local_a0);
      _free(local_ac);
      return extraout_EAX_00;
    }
    local_ac = (void *)0x0;
    local_a8 = 0;
    local_a4 = 0;
    local_4 = 0xffffffff;
    if (0xf < local_68) {
      _free(local_7c);
      return extraout_EAX_01;
    }
    local_68 = 0xf;
    uStack_6c = 0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    FUN_0049d780();
    cVar2 = FUN_0049d7c0();
  }
  local_ac = (void *)0x0;
  local_a8 = 0;
  local_a4 = 0;
  if (local_68 < 0x10) {
    ExceptionList = local_c;
    return 0;
  }
  _free(local_7c);
  return extraout_EAX_03;
}


// ==== FUN_0081e930 @ 0x0081e930 ====

void FUN_0081e930(void)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009994d2;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_Environment_sky_txt_00a0bfc8,0x13);
  local_4 = 0;
  uVar3 = FUN_0081e9d0(local_28);
  *(undefined4 *)(in_ECX + 8) = uVar3;
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  cVar2 = FUN_0081e5a0();
  if (cVar2 == '\0') {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  *(undefined1 *)(in_ECX + 4) = 1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081e9d0 @ 0x0081e9d0 ====

undefined4 FUN_0081e9d0(undefined4 param_1)

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
  puStack_8 = &LAB_009993e8;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0x1b;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 8))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_0081ea60 @ 0x0081ea60 ====

undefined1 * FUN_0081ea60(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x58;
    puVar2 = param_3 + -0x58;
    *puVar2 = *(undefined1 *)(param_2 + -0x58);
    param_3[-0x57] = *(undefined1 *)(param_2 + -0x57);
    FUN_00401660(param_2 + -0x54,0,0xffffffff);
    FUN_00401660(param_2 + -0x38,0,0xffffffff);
    FUN_00401660(param_2 + -0x1c,0,0xffffffff);
    param_2 = iVar1;
    param_3 = puVar2;
  } while (iVar1 != param_1);
  return puVar2;
}


// ==== FUN_0081ead0 @ 0x0081ead0 ====

void FUN_0081ead0(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      FUN_00401660(param_3 + 4,0,0xffffffff);
      FUN_00401660(param_3 + 0x20,0,0xffffffff);
      FUN_00401660(param_3 + 0x3c,0,0xffffffff);
      param_1 = param_1 + 0x58;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0081eb30 @ 0x0081eb30 ====

int FUN_0081eb30(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00999411;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x58) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_006dfba0(param_1);
    }
    param_3 = param_3 + 0x58;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0081eb86 @ 0x0081eb86 ====

void Catch_0081eb86(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x58) {
    FUN_006dfb30();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0081ebc0 @ 0x0081ebc0 ====

void FUN_0081ebc0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00999431;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_006dfba0(param_3);
    }
    param_1 = param_1 + 0x58;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0081ec18 @ 0x0081ec18 ====

void Catch_0081ec18(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x58) {
    FUN_006dfb30();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0081ec50 @ 0x0081ec50 ====

int FUN_0081ec50(int param_1,int param_2,undefined4 param_3)

{
  FUN_0081ebc0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x58;
}


// ==== FUN_0081ec80 @ 0x0081ec80 ====

void FUN_0081ec80(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined1 local_70 [2];
  undefined1 auStack_6e [90];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999448;
  local_10 = ExceptionList;
  local_14 = local_70 + -0xc;
  ExceptionList = &local_10;
  FUN_006dfba0(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x58;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x58;
    }
    if (0x2e8ba2eU - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x58;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x2e8ba2e - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x58;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_006dc7b0();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x58);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = FUN_0081eb30(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0081ebc0(iVar2,param_2,local_70);
      FUN_0081eb30(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x58);
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x58;
      }
      if (iVar2 != 0) {
        FUN_006dfd50(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x58 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar1) * 0x58);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      iVar1 = param_2 * 0x58;
      if ((uint)((iVar2 - param_1) / 0x58) < param_2) {
        FUN_0081eb30(param_1,iVar2,iVar1 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0081ec50(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x58,local_70
                    );
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
        local_8 = 0;
        FUN_0081ead0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x58,local_70);
      }
      else {
        iVar6 = iVar2 + param_2 * -0x58;
        uVar4 = FUN_0081eb30(iVar6,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_0081ea60(param_1,iVar6,iVar2,param_1);
        FUN_0081ead0(param_1,iVar1 + param_1,local_70);
      }
    }
  }
  FUN_006dfb30();
  ExceptionList = local_10;
  return;
}


// ==== Catch@0081ee4c @ 0x0081ee4c ====

void Catch_0081ee4c(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_006dfd50(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0081ef08 @ 0x0081ef08 ====

void Catch_0081ef08(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x58;
  FUN_006dfd50(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0081ef90 @ 0x0081ef90 ====

void FUN_0081ef90(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x58 != 0) {
      iVar1 = (param_2 - iVar1) / 0x58;
      goto LAB_0081efd5;
    }
  }
  iVar1 = 0;
LAB_0081efd5:
  FUN_0081ec80(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x58;
  return;
}


// ==== FUN_0081f000 @ 0x0081f000 ====

int FUN_0081f000(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_0081f010 @ 0x0081f010 ====

void FUN_0081f010(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x58) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x58))) {
    FUN_0081ef90(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0081ebc0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x58;
  return;
}


// ==== FUN_0081f0a0 @ 0x0081f0a0 ====

void FUN_0081f0a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0081e520();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0081f0c0 @ 0x0081f0c0 ====

void FUN_0081f0c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0c17c;
  return;
}


// ==== FUN_0081f0d0 @ 0x0081f0d0 ====

void FUN_0081f0d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0c17c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0081f0f0 @ 0x0081f0f0 ====

void FUN_0081f0f0(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((int)puVar1[3] < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (int)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_0081f160 @ 0x0081f160 ====

void FUN_0081f160(undefined4 *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x2d) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(ushort *)(puVar1 + 3) < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x2d) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < *(ushort *)(puVar3 + 3))) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_0081f1d0 @ 0x0081f1d0 ====

void FUN_0081f1d0(undefined4 *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x1d) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(ushort *)(puVar1 + 3) < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x1d) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < *(ushort *)(puVar3 + 3))) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_0081f240 @ 0x0081f240 ====

void FUN_0081f240(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x14) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_0081f270 @ 0x0081f270 ====

/* WARNING: Removing unreachable block (ram,0x0081f310) */

int FUN_0081f270(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  int iVar4;
  undefined1 auStack_2a [22];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &LAB_009994e8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*in_ECX + 0xc))(param_2,param_3);
  FUN_00401660(uVar3,0,0xffffffff);
  iVar4 = *(int *)(param_2 + 4);
  iVar1 = *(int *)(param_2 + 8);
  pvStack_c = (void *)0x0;
  iVar2 = iStack_4;
  for (; iStack_4 = iVar2, iVar4 != iVar1; iVar4 = iVar4 + 0x38) {
    FUN_00404440(auStack_2a + -6,iVar4,iVar4 + 0x1c);
    iVar2 = iStack_4;
  }
  *(undefined4 *)(iVar2 + 0x18) = 0xf;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined1 *)(iVar2 + 4) = 0;
  FUN_00401660(auStack_2a + -6,0,0xffffffff);
  ExceptionList = pvStack_14;
  return iVar2;
}


// ==== FUN_0081f340 @ 0x0081f340 ====

uint FUN_0081f340(int param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint extraout_EAX;
  int in_ECX;
  undefined4 *puVar6;
  undefined1 auStack_74 [4];
  undefined1 local_70;
  undefined4 local_60;
  int *local_5c;
  int local_48;
  undefined1 local_44 [4];
  void *local_40;
  uint local_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00999502;
  local_c = ExceptionList;
  local_5c = &local_48;
  local_60 = 0x81f36f;
  ExceptionList = &local_c;
  FUN_0081f0f0();
  if (local_48 == *(int *)(in_ECX + 0x68)) {
    param_2 = auStack_74;
    local_5c = (int *)0xf;
    local_60 = 0;
    local_70 = 0;
    FUN_00401740(s_Invalid_Type____u_00a0c10c,0x12);
    uVar3 = FUN_00404230(local_44);
    local_4 = 0;
    uVar4 = FUN_00796d50(uVar3);
    if (local_2c < 0x10) goto LAB_0081f46c;
  }
  else {
    puVar1 = *(undefined4 **)(local_48 + 0x18);
    for (puVar6 = *(undefined4 **)(local_48 + 0x14); puVar6 != puVar1; puVar6 = puVar6 + 1) {
      piVar2 = (int *)*puVar6;
      local_5c = &param_1;
      local_60 = 0x81f3f3;
      (**(code **)(*piVar2 + 0x34))();
      local_60 = 0x81f3fa;
      FUN_0081f1d0();
      iVar5 = (**(code **)(*piVar2 + 0x34))();
      if (param_1 != *(int *)(iVar5 + 4)) {
        ExceptionList = local_c;
        return CONCAT22((short)((uint)*(int *)(iVar5 + 4) >> 0x10),*(undefined2 *)(param_1 + 0x18));
      }
    }
    param_2 = auStack_74;
    local_5c = (int *)0xf;
    local_60 = 0;
    local_70 = 0;
    FUN_00401740(s_Invalid_Category____u_00a0c120,0x16);
    uVar3 = FUN_00404230(auStack_28);
    local_4 = 1;
    uVar4 = FUN_00796d50(uVar3);
    if (uStack_10 < 0x10) {
LAB_0081f46c:
      ExceptionList = local_c;
      return uVar4 & 0xffff0000;
    }
    local_40 = pvStack_24;
  }
  local_5c = (int *)0x81f469;
  _free(local_40);
  return extraout_EAX;
}


// ==== FUN_0081f4a0 @ 0x0081f4a0 ====

int FUN_0081f4a0(undefined1 **param_1,uint param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_EAX;
  int iVar5;
  int extraout_EAX_00;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  undefined1 *puStack_8c;
  undefined1 local_88 [4];
  undefined1 local_84;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  undefined4 *puStack_6c;
  undefined1 local_44 [4];
  void *local_40;
  uint local_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099951c;
  local_c = ExceptionList;
  puStack_6c = &param_2;
  uVar6 = param_2 >> 0x10;
  local_70 = 0x81f4e5;
  ExceptionList = &local_c;
  FUN_0081f0f0();
  if (param_2 == *(uint *)(in_ECX + 0x68)) {
    local_70 = (int)param_1;
    param_1 = &puStack_8c;
    local_74 = 0xf;
    local_78 = 0;
    local_88[0] = 0;
    puStack_6c = (undefined4 *)uVar6;
    FUN_00401740(s_Invalid_Type____u__u__u_00a0c138,0x18);
    uVar4 = FUN_00404230(local_44);
    local_4 = 0;
    FUN_00796d50(uVar4);
    if (local_2c < 0x10) {
      ExceptionList = local_c;
      return in_ECX + 4;
    }
    puStack_6c = (undefined4 *)0x81f54f;
    _free(local_40);
    return extraout_EAX;
  }
  puVar1 = *(undefined4 **)(param_2 + 0x18);
  for (puVar7 = *(undefined4 **)(param_2 + 0x14); puVar7 != puVar1; puVar7 = puVar7 + 1) {
    piVar2 = (int *)*puVar7;
    puStack_6c = &param_1;
    local_70 = 0x81f58b;
    (**(code **)(*piVar2 + 0x34))();
    local_70 = 0x81f592;
    FUN_0081f1d0();
    iVar5 = (**(code **)(*piVar2 + 0x34))();
    iVar3 = (int)param_1;
    if (param_1 != (undefined1 **)*(int *)(iVar5 + 4)) {
      puStack_6c = &param_2;
      local_70 = 0x81f5b8;
      FUN_0081f160();
      if (param_2 != *(uint *)(iVar3 + 0x14)) {
        ExceptionList = local_c;
        return param_2 + 0x10;
      }
    }
  }
  param_1 = (undefined1 **)local_88;
  puStack_8c = (undefined1 *)0x5;
  local_70 = 0xf;
  local_74 = 0;
  local_84 = 0;
  puStack_6c = (undefined4 *)uVar6;
  FUN_00401740(s__u__u_00a0c154);
  puStack_8c = auStack_28;
  local_70 = FUN_00404230();
  puStack_6c = (undefined4 *)0x0;
  local_4 = 1;
  local_74 = 0x81f626;
  FUN_00401660();
  if (uStack_10 < 0x10) {
    ExceptionList = local_c;
    return in_ECX + 0x20;
  }
  puStack_6c = (undefined4 *)0x81f637;
  _free(pvStack_24);
  return extraout_EAX_00;
}


// ==== FUN_0081f670 @ 0x0081f670 ====

/* WARNING: Removing unreachable block (ram,0x0081f6f6) */

void FUN_0081f670(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  void **ppvVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  int *piVar8;
  undefined4 *puVar9;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &LAB_0099952e;
  pvStack_c = ExceptionList;
  piVar2 = *(int **)(in_ECX + 0x68);
  piVar8 = (int *)*piVar2;
  ExceptionList = &pvStack_c;
  ppvVar5 = &pvStack_c;
  if (piVar8 != piVar2) {
    do {
      ExceptionList = ppvVar5;
      puVar3 = (undefined4 *)piVar8[6];
      for (puVar9 = (undefined4 *)piVar8[5]; puVar9 != puVar3; puVar9 = puVar9 + 1) {
        uStack_4 = 0xffffffff;
        piVar4 = (int *)*puVar9;
        uVar7 = (**(code **)(*piVar4 + 4))();
        FUN_00401660(uVar7,0,0xffffffff);
        uStack_4 = 0;
        (**(code **)(*DAT_00b5a7cc + 0x14))(piVar4);
      }
      if (*(char *)((int)piVar8 + 0x21) == '\0') {
        piVar4 = (int *)piVar8[2];
        if (*(char *)((int)piVar4 + 0x21) == '\0') {
          cVar1 = *(char *)(*piVar4 + 0x21);
          piVar8 = piVar4;
          piVar4 = (int *)*piVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x21);
            piVar8 = piVar4;
            piVar4 = (int *)*piVar4;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x21);
          piVar6 = (int *)piVar8[1];
          piVar4 = piVar8;
          while ((piVar8 = piVar6, cVar1 == '\0' && (piVar4 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x21);
            piVar6 = (int *)piVar8[1];
            piVar4 = piVar8;
          }
        }
      }
      ppvVar5 = ExceptionList;
    } while (piVar8 != piVar2);
  }
  uStack_4 = 0xffffffff;
  FUN_00820f80(*(undefined4 *)(*(int *)(in_ECX + 0x68) + 4));
  *(int *)(*(int *)(in_ECX + 0x68) + 4) = *(int *)(in_ECX + 0x68);
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(in_ECX + 0x68);
  *(int *)(*(int *)(in_ECX + 0x68) + 8) = *(int *)(in_ECX + 0x68);
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0081f7b0 @ 0x0081f7b0 ====

void FUN_0081f7b0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00999577;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_00a0c194;
  local_4 = 5;
  FUN_0081f670();
  DAT_00b5a794 = 0;
  local_4 = CONCAT31(local_4._1_3_,4);
  FUN_00821300(local_10,*(undefined4 *)in_ECX[0x1a],(undefined4 *)in_ECX[0x1a]);
  _free((void *)in_ECX[0x1a]);
  return;
}


// ==== FUN_0081f8c0 @ 0x0081f8c0 ====

void FUN_0081f8c0(void)

{
  code *pcVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined1 local_a4 [4];
  void *local_a0;
  int local_9c;
  undefined4 local_98;
  int local_94;
  undefined1 local_90 [4];
  void *local_8c;
  undefined4 local_7c;
  uint local_78;
  int local_74;
  undefined1 local_70 [4];
  void *local_6c;
  undefined4 local_5c;
  uint local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
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
  puStack_8 = &LAB_009995af;
  local_c = ExceptionList;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_string_list_txt_00a0c15c,0xf);
  local_4 = 0;
  iVar4 = FUN_00410500(local_44);
  local_4 = 0xffffffff;
  local_94 = iVar4;
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (iVar4 != 0) {
    local_48 = *(undefined4 *)(iVar4 + 0x4c);
    FUN_0049d760();
    cVar3 = FUN_0049d7c0();
    if (cVar3 == '\0') {
      do {
        FUN_0049d800(local_90);
        local_a0 = (void *)0x0;
        local_9c = 0;
        local_98 = 0;
        local_4 = 2;
        FUN_00404fb0(local_90,0x2c,local_a4);
        iVar4 = local_74;
        if (local_a0 == (void *)0x0) {
          local_a0 = (void *)0x0;
          local_9c = 0;
          local_98 = 0;
        }
        else {
          iVar2 = local_9c - (int)local_a0 >> 0x1f;
          iVar5 = (local_9c - (int)local_a0) / 0x1c + iVar2;
          if ((uint)(iVar5 - iVar2) < 2) {
            FUN_00405de0(local_a0,local_9c,local_a4,local_94);
            _free(local_a0);
            return;
          }
          if (iVar5 == iVar2) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          FUN_0069a470(&local_54,local_a0);
          iVar2 = local_54;
          if (local_54 == *(int *)(iVar4 + 0x5c)) {
            if (local_a0 != (void *)0x0) {
              FUN_00405de0(local_a0,local_9c,local_a4,local_94);
              _free(local_a0);
              return;
            }
            local_a0 = (void *)0x0;
            local_9c = 0;
            local_98 = 0;
          }
          else {
            if ((local_a0 == (void *)0x0) || ((uint)((local_9c - (int)local_a0) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
              FUN_00405ca0();
            }
            local_58 = 0xf;
            local_5c = 0;
            local_6c = (void *)((uint)local_6c & 0xffffff00);
            FUN_00401660((int)local_a0 + 0x1c,0,0xffffffff);
            local_4._0_1_ = 3;
            local_50 = FUN_00820450(local_70);
            if (local_50 == 0) {
              FUN_00401830(s_FALSE_00a0c16c);
              local_4 = CONCAT31(local_4._1_3_,4);
              FUN_00406880(local_28);
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
            local_4c = *(undefined4 *)(iVar2 + 0x28);
            FUN_008218f0(&local_4c);
            FUN_008211f0(&local_50);
            if (0xf < local_58) {
              _free(local_6c);
              return;
            }
            local_58 = 0xf;
            local_5c = 0;
            local_6c = (void *)((uint)local_6c & 0xffffff00);
            FUN_00406250();
          }
        }
        if (0xf < local_78) {
          local_4 = 0xffffffff;
          _free(local_8c);
          return;
        }
        local_4 = 0xffffffff;
        local_78 = 0xf;
        local_7c = 0;
        local_8c = (void *)((uint)local_8c & 0xffffff00);
        FUN_0049d780();
        cVar3 = FUN_0049d7c0();
      } while (cVar3 == '\0');
      iVar4 = local_94;
    }
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar4);
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0081fc80 @ 0x0081fc80 ====

void FUN_0081fc80(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x68);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    for (uVar8 = 0; (iVar7 = puVar3[5], iVar7 != 0 && (uVar8 < (uint)(puVar3[6] - iVar7 >> 2)));
        uVar8 = uVar8 + 1) {
      piVar4 = *(int **)(iVar7 + uVar8 * 4);
      if (piVar4 != (int *)0x0) {
        iVar7 = (**(code **)(*piVar4 + 4))();
        *(undefined4 *)(iVar7 + 0x28) = 0;
        (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar4);
      }
    }
    if (*(char *)((int)puVar3 + 0x21) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x21) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x21);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x21);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x21);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x21);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  FUN_00820f80(*(undefined4 *)(*(int *)(in_ECX + 0x68) + 4));
  *(int *)(*(int *)(in_ECX + 0x68) + 4) = *(int *)(in_ECX + 0x68);
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(in_ECX + 0x68);
  *(int *)(*(int *)(in_ECX + 0x68) + 8) = *(int *)(in_ECX + 0x68);
  FUN_0081f8c0();
  return;
}


// ==== FUN_0081fd70 @ 0x0081fd70 ====

undefined4 * FUN_0081fd70(void)

{
  int iVar1;
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  undefined4 *extraout_EAX_01;
  undefined4 *extraout_EAX_02;
  undefined4 *extraout_EAX_03;
  undefined4 *extraout_EAX_04;
  undefined4 *extraout_EAX_05;
  undefined4 *extraout_EAX_06;
  undefined4 *extraout_EAX_07;
  undefined4 *extraout_EAX_08;
  undefined4 *extraout_EAX_09;
  undefined4 *extraout_EAX_10;
  undefined4 *extraout_EAX_11;
  undefined4 *extraout_EAX_12;
  undefined4 *extraout_EAX_13;
  undefined4 *extraout_EAX_14;
  undefined4 *extraout_EAX_15;
  undefined4 *extraout_EAX_16;
  undefined4 *extraout_EAX_17;
  undefined4 *extraout_EAX_18;
  undefined4 *in_ECX;
  undefined1 local_50 [8];
  undefined1 local_48 [4];
  void *local_44;
  undefined4 local_34;
  uint local_30;
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00999698;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_00a0c194;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  in_ECX[0x15] = 0xf;
  in_ECX[0x14] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  local_4 = 3;
  iVar1 = FUN_004a37b0();
  in_ECX[0x17] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[0x17] + 4) = in_ECX[0x17];
  *(undefined4 *)in_ECX[0x17] = in_ECX[0x17];
  *(undefined4 *)(in_ECX[0x17] + 8) = in_ECX[0x17];
  in_ECX[0x18] = 0;
  local_4._0_1_ = 4;
  iVar1 = FUN_004be360();
  in_ECX[0x1a] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(undefined4 *)(in_ECX[0x1a] + 4) = in_ECX[0x1a];
  *(undefined4 *)in_ECX[0x1a] = in_ECX[0x1a];
  *(undefined4 *)(in_ECX[0x1a] + 8) = in_ECX[0x1a];
  in_ECX[0x1b] = 0;
  local_4._0_1_ = 5;
  FUN_00401740(s_Type_Error_00a0c088,10);
  FUN_00401740(s_Category_Error_00a0c094,0xe);
  FUN_00401740(s_Code_Error_00a0c0a4,10);
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(s_NORMAL_00a0c0b0,6);
  local_4._0_1_ = 6;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 0;
  local_4._0_1_ = 7;
  FUN_00821080(local_50,local_2c);
  if (0xf < local_14) {
    _free(local_28);
    return extraout_EAX;
  }
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4._0_1_ = 5;
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_00;
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(s_QUEST_00a0c0b8,5);
  local_4._0_1_ = 8;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 1;
  local_4._0_1_ = 9;
  FUN_00821080(local_50,local_2c);
  if (0xf < local_14) {
    _free(local_28);
    return extraout_EAX_01;
  }
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4._0_1_ = 5;
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_02;
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(s_COMMON_00a0c0c0,6);
  local_4._0_1_ = 10;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 2;
  local_4._0_1_ = 0xb;
  FUN_00821080(local_50,local_2c);
  if (0xf < local_14) {
    _free(local_28);
    return extraout_EAX_03;
  }
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4._0_1_ = 5;
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_04;
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(s_TELEPORT_00a0c0c8,8);
  local_4._0_1_ = 0xc;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 3;
  local_4._0_1_ = 0xd;
  FUN_00821080(local_50,local_2c);
  if (0xf < local_14) {
    _free(local_28);
    return extraout_EAX_05;
  }
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4._0_1_ = 5;
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_06;
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(s_HELPER_00a0c0d4,6);
  local_4._0_1_ = 0xe;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 4;
  local_4._0_1_ = 0xf;
  FUN_00821080(local_50,local_2c);
  if (0xf < local_14) {
    _free(local_28);
    return extraout_EAX_07;
  }
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4._0_1_ = 5;
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_08;
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(s_SYSTEM_00a0c0dc,6);
  local_4._0_1_ = 0x10;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 5;
  local_4._0_1_ = 0x11;
  FUN_00821080(local_50,local_2c);
  if (0xf < local_14) {
    _free(local_28);
    return extraout_EAX_09;
  }
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4._0_1_ = 5;
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_10;
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(s_MINIHELP_00a0c0e4,8);
  local_4._0_1_ = 0x12;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 6;
  local_4._0_1_ = 0x13;
  FUN_00821080(local_50,local_2c);
  if (0xf < local_14) {
    _free(local_28);
    return extraout_EAX_11;
  }
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4._0_1_ = 5;
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_12;
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(s_DUNGEON_00a0c0f0,7);
  local_4._0_1_ = 0x14;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 7;
  local_4._0_1_ = 0x15;
  FUN_00821080(local_50,local_2c);
  if (0xf < local_14) {
    _free(local_28);
    return extraout_EAX_13;
  }
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4._0_1_ = 5;
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_14;
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(s_SIEGE_00a0c0f8,5);
  local_4._0_1_ = 0x16;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 8;
  local_4._0_1_ = 0x17;
  FUN_00821080(local_50,local_2c);
  if (0xf < local_14) {
    _free(local_28);
    return extraout_EAX_15;
  }
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4._0_1_ = 5;
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_16;
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  FUN_00401740(s_PARTYWAR_00a0c100,8);
  local_4._0_1_ = 0x18;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401660(local_48,0,0xffffffff);
  local_10 = 9;
  local_4._0_1_ = 0x19;
  FUN_00821080(local_50,local_2c);
  if (0xf < local_14) {
    _free(local_28);
    return extraout_EAX_17;
  }
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4 = CONCAT31(local_4._1_3_,5);
  if (0xf < local_30) {
    _free(local_44);
    return extraout_EAX_18;
  }
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a794 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a794 = in_ECX;
  }
  FUN_0081f8c0();
  ExceptionList = local_c;
  return in_ECX;
}


