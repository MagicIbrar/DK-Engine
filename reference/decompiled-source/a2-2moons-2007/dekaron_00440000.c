// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x440000-0x44ffff

// ==== FUN_004400d0 @ 0x004400d0 ====

void FUN_004400d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e6f8;
  in_ECX[1] = 0;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401740(&DAT_0099e616,0);
  return;
}


// ==== FUN_00440100 @ 0x00440100 ====

undefined4 FUN_00440100(char *param_1,char param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 extraout_EAX;
  HANDLE pvVar3;
  LPCSTR pCVar4;
  int in_ECX;
  uint dwShareMode;
  DWORD dwDesiredAccess;
  DWORD dwCreationDisposition;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b08a;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &local_c;
  FUN_00401740(param_1,(int)pcVar2 - (int)(param_1 + 1));
  local_4 = 0;
  FUN_00401660(local_28,0,0xffffffff);
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (param_2 == '\0') {
    dwCreationDisposition = 3;
    dwDesiredAccess = 0x80000000;
  }
  else {
    dwCreationDisposition = 2;
    dwDesiredAccess = 0x40000000;
  }
  dwShareMode = (uint)(param_2 == '\0');
  if (*(uint *)(in_ECX + 0x20) < 0x10) {
    pCVar4 = (LPCSTR)(in_ECX + 0xc);
  }
  else {
    pCVar4 = *(LPCSTR *)(in_ECX + 0xc);
  }
  pvVar3 = CreateFileA(pCVar4,dwDesiredAccess,dwShareMode,(LPSECURITY_ATTRIBUTES)0x0,
                       dwCreationDisposition,0x80,(HANDLE)0x0);
  *(HANDLE *)(in_ECX + 4) = pvVar3;
  if (pvVar3 != (HANDLE)0xffffffff) {
    ExceptionList = local_c;
    return 1;
  }
  if ((param_2 != '\0') && (cVar1 = FUN_0043ff80(in_ECX + 8), cVar1 != '\0')) {
    if (*(uint *)(in_ECX + 0x20) < 0x10) {
      pCVar4 = (LPCSTR)(in_ECX + 0xc);
    }
    else {
      pCVar4 = *(LPCSTR *)(in_ECX + 0xc);
    }
    pvVar3 = CreateFileA(pCVar4,dwDesiredAccess,dwShareMode,(LPSECURITY_ATTRIBUTES)0x0,
                         dwCreationDisposition,0x80,(HANDLE)0x0);
    *(HANDLE *)(in_ECX + 4) = pvVar3;
    if (pvVar3 != (HANDLE)0xffffffff) {
      ExceptionList = local_c;
      return 1;
    }
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_00440260 @ 0x00440260 ====

void FUN_00440260(void)

{
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b09c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CloseHandle(*(HANDLE *)(in_ECX + 4));
  *(undefined4 *)(in_ECX + 4) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_0099e61a,0);
  local_4 = 0;
  FUN_00401660(local_28,0,0xffffffff);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_004402f0 @ 0x004402f0 ====

uint FUN_004402f0(LPVOID param_1,undefined1 *param_2)

{
  BOOL BVar1;
  uint extraout_EAX;
  LPCSTR **lpText;
  HWND hWnd;
  uint extraout_EAX_00;
  int in_ECX;
  undefined1 auStack_64 [4];
  uint uStack_60;
  char *lpCaption;
  UINT uType;
  undefined1 auStack_44 [4];
  LPCSTR **apppCStack_40 [5];
  uint uStack_2c;
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097b0b6;
  local_c = ExceptionList;
  if ((*(HANDLE *)(in_ECX + 4) != (HANDLE)0x0) && (*(int *)(in_ECX + 0x1c) != 0)) {
    uStack_60 = 0x440330;
    ExceptionList = &local_c;
    BVar1 = ReadFile(*(HANDLE *)(in_ECX + 4),param_1,(DWORD)param_2,(LPDWORD)&param_2,
                     (LPOVERLAPPED)0x0);
    ExceptionList = local_c;
    return -(uint)(BVar1 != 0) & (uint)param_2;
  }
  param_2 = auStack_64;
  uStack_60 = uStack_60 & 0xffffff00;
  ExceptionList = &local_c;
  FUN_00401740(s_<<_error_>>_File_is_not_opened__a_0099e61c,0x2e);
  FUN_00404230(auStack_44);
  uStack_4 = 0;
  if (*(int *)(in_ECX + 0x1c) != 0) {
    FUN_004022a0();
    uStack_4 = CONCAT31(uStack_4._1_3_,1);
    FUN_00401ff0();
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return extraout_EAX;
    }
  }
  lpText = apppCStack_40[0];
  if (uStack_2c < 0x10) {
    lpText = (LPCSTR **)apppCStack_40;
  }
  uType = 0x30;
  lpCaption = s_Fatal_Error_0099e660;
  hWnd = GetForegroundWindow();
  MessageBoxA(hWnd,(LPCSTR)lpText,lpCaption,uType);
  if (uStack_2c < 0x10) {
    ExceptionList = local_c;
    return 0;
  }
  _free(apppCStack_40[0]);
  return extraout_EAX_00;
}


// ==== FUN_0044034a @ 0x0044034a ====

undefined4 FUN_0044034a(undefined1 param_1,LPCSTR param_2)

{
  undefined4 extraout_EAX;
  LPCSTR lpText;
  HWND hWnd;
  undefined4 extraout_EAX_00;
  int unaff_ESI;
  uint in_stack_0000001c;
  void *in_stack_00000024;
  uint in_stack_00000038;
  void *in_stack_0000003c;
  undefined4 in_stack_00000044;
  undefined1 *puStack00000050;
  undefined1 auStack_1c [4];
  undefined1 local_18;
  undefined4 uStack_14;
  char *lpCaption;
  UINT uType;
  
  puStack00000050 = auStack_1c;
  local_18 = 0;
  FUN_00401740(s_<<_error_>>_File_is_not_opened__a_0099e61c,0x2e);
  FUN_00404230(&param_1);
  in_stack_00000044 = 0;
  if (*(int *)(unaff_ESI + 0x1c) != 0) {
    FUN_004022a0();
    in_stack_00000044 = CONCAT31(in_stack_00000044._1_3_,1);
    FUN_00401ff0();
    if (0xf < in_stack_00000038) {
      _free(in_stack_00000024);
      return extraout_EAX;
    }
  }
  lpText = param_2;
  if (in_stack_0000001c < 0x10) {
    lpText = (LPCSTR)&param_2;
  }
  uType = 0x30;
  lpCaption = s_Fatal_Error_0099e660;
  hWnd = GetForegroundWindow();
  uStack_14 = 0x4403ee;
  MessageBoxA(hWnd,lpText,lpCaption,uType);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = in_stack_0000003c;
    return 0;
  }
  _free(param_2);
  return extraout_EAX_00;
}


// ==== FUN_00440420 @ 0x00440420 ====

undefined4 FUN_00440420(LPCVOID param_1,undefined1 *param_2)

{
  BOOL BVar1;
  LPCSTR *****ppppppCVar2;
  HWND pHVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  undefined1 auStack_68 [4];
  uint uStack_64;
  char *pcVar4;
  UINT UVar5;
  LPCSTR *****appppppCStack_40 [5];
  uint uStack_2c;
  undefined1 local_28 [4];
  LPCSTR *****local_24 [5];
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097b0d0;
  local_c = ExceptionList;
  if ((*(HANDLE *)(in_ECX + 4) == (HANDLE)0x0) || (*(int *)(in_ECX + 0x1c) == 0)) {
    param_2 = auStack_68;
    uStack_64 = uStack_64 & 0xffffff00;
    ExceptionList = &local_c;
    FUN_00401740(s_<<_error_>>_File_is_not_opened__a_0099e66c);
    FUN_00404230();
    uStack_4 = 0;
    if (*(int *)(in_ECX + 0x1c) != 0) {
      FUN_004022a0();
      uStack_4 = CONCAT31(uStack_4._1_3_,1);
      FUN_00401ff0();
      if (0xf < local_10) {
        _free(local_24[0]);
        return extraout_EAX;
      }
    }
    ppppppCVar2 = appppppCStack_40[0];
    if (uStack_2c < 0x10) {
      ppppppCVar2 = (LPCSTR *****)appppppCStack_40;
    }
    UVar5 = 0x30;
    pcVar4 = s_Fatal_Error_0099e6b0;
    pHVar3 = GetForegroundWindow();
    MessageBoxA(pHVar3,(LPCSTR)ppppppCVar2,pcVar4,UVar5);
    if (uStack_2c < 0x10) {
      ExceptionList = local_c;
      return 0;
    }
    local_24[0] = appppppCStack_40[0];
  }
  else {
    uStack_64 = 0x440469;
    ExceptionList = &local_c;
    BVar1 = WriteFile(*(HANDLE *)(in_ECX + 4),param_1,(DWORD)param_2,(LPDWORD)&param_2,
                      (LPOVERLAPPED)0x0);
    if (BVar1 != 0) {
      ExceptionList = local_c;
      return 1;
    }
    FUN_00401830(s_<<_error_>>_Couldn_t_Write_File__0099e6bc);
    FUN_00404230(local_28);
    ppppppCVar2 = local_24[0];
    if (local_10 < 0x10) {
      ppppppCVar2 = (LPCSTR *****)local_24;
    }
    UVar5 = 0x30;
    pcVar4 = s_Fatal_Error_0099e6e8;
    pHVar3 = GetForegroundWindow();
    MessageBoxA(pHVar3,(LPCSTR)ppppppCVar2,pcVar4,UVar5);
    if (local_10 < 0x10) {
      ExceptionList = local_c;
      return 0;
    }
  }
  _free(local_24[0]);
  return extraout_EAX_00;
}


// ==== FUN_004404ec @ 0x004404ec ====

uint FUN_004404ec(undefined4 param_1,undefined1 param_2,LPCSTR param_3)

{
  uint extraout_EAX;
  LPCSTR lpText;
  HWND hWnd;
  uint uVar1;
  uint extraout_EAX_00;
  int unaff_ESI;
  uint in_stack_00000020;
  void *in_stack_00000028;
  uint in_stack_0000003c;
  void *in_stack_00000040;
  undefined4 in_stack_00000048;
  undefined1 *puStack00000054;
  undefined1 auStack_1c [4];
  undefined1 local_18;
  undefined4 uStack_14;
  char *lpCaption;
  UINT uType;
  
  puStack00000054 = auStack_1c;
  local_18 = 0;
  FUN_00401740(s_<<_error_>>_File_is_not_opened__a_0099e66c,0x2f);
  FUN_00404230(&param_2);
  in_stack_00000048 = 0;
  if (*(int *)(unaff_ESI + 0x1c) != 0) {
    FUN_004022a0();
    in_stack_00000048 = CONCAT31(in_stack_00000048._1_3_,1);
    FUN_00401ff0();
    if (0xf < in_stack_0000003c) {
      _free(in_stack_00000028);
      return extraout_EAX;
    }
  }
  lpText = param_3;
  if (in_stack_00000020 < 0x10) {
    lpText = (LPCSTR)&param_3;
  }
  uType = 0x30;
  lpCaption = s_Fatal_Error_0099e6b0;
  hWnd = GetForegroundWindow();
  uStack_14 = 0x440593;
  uVar1 = MessageBoxA(hWnd,lpText,lpCaption,uType);
  if (in_stack_00000020 < 0x10) {
    ExceptionList = in_stack_00000040;
    return uVar1 & 0xffffff00;
  }
  _free(param_3);
  return extraout_EAX_00;
}


// ==== FUN_004405c0 @ 0x004405c0 ====

void * FUN_004405c0(DWORD param_1,DWORD *param_2)

{
  DWORD *pDVar1;
  char cVar2;
  DWORD DVar3;
  void *pvVar4;
  int in_ECX;
  
  cVar2 = FUN_00440100(param_1,0);
  if (cVar2 == '\0') {
    return (void *)0x0;
  }
  DVar3 = GetFileSize(*(HANDLE *)(in_ECX + 4),&param_1);
  pDVar1 = param_2;
  *param_2 = DVar3;
  pvVar4 = operator_new(DVar3);
  FUN_004402f0(pvVar4,*pDVar1);
  FUN_00440260();
  return pvVar4;
}


// ==== FUN_00440720 @ 0x00440720 ====

void FUN_00440720(byte param_1)

{
  void *in_ECX;
  
  FUN_0043ff50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00440740 @ 0x00440740 ====

int FUN_00440740(int param_1,int param_2)

{
  int extraout_EAX;
  char *pcVar1;
  undefined4 uVar2;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b108;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_4 = 0;
  if (param_2 == 4) {
    uVar2 = 0x11;
    pcVar1 = s_Texture_empty_dds_0099e708;
  }
  else {
    ExceptionList = &local_c;
    if (param_2 != 5) goto LAB_0044079b;
    uVar2 = 0x1b;
    pcVar1 = s_TexturePack_etc_empty_tpack_0099e71c;
  }
  ExceptionList = &local_c;
  FUN_00401740(pcVar1,uVar2);
LAB_0044079b:
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_28,0,0xffffffff);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_004407f0 @ 0x004407f0 ====

undefined4 FUN_004407f0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_60 [4];
  undefined1 local_5c;
  uint uStack_50;
  undefined4 local_4c;
  void *local_48;
  undefined1 auStack_44 [12];
  undefined4 uStack_38;
  uint uStack_34;
  void *pvStack_2c;
  undefined1 local_28 [12];
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b12a;
  pvStack_c = ExceptionList;
  local_48 = (void *)0xf;
  local_4c = 0;
  local_5c = 0;
  pcVar3 = PTR_s_DataPath_00adc308;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740(PTR_s_DataPath_00adc308,(int)pcVar3 - (int)(PTR_s_DataPath_00adc308 + 1));
  local_4 = 0;
  uVar4 = FUN_00440740(local_28,param_2);
  local_4 = CONCAT31(local_4._1_3_,1);
  piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar6 = (**(code **)(*piVar5 + 8))(auStack_44,local_60);
  uVar2 = local_4;
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
  FUN_00405bd0(local_4,uVar6,uVar4);
  if (0xf < uStack_34) {
    _free(local_48);
    return extraout_EAX;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  local_48 = (void *)((uint)local_48 & 0xffffff00);
  if (0xf < uStack_18) {
    _free(pvStack_2c);
    return extraout_EAX_00;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  if (uStack_50 < 0x10) {
    ExceptionList = pvStack_14;
    return uVar2;
  }
  _free((void *)0x0);
  return extraout_EAX_01;
}


// ==== FUN_00440910 @ 0x00440910 ====

undefined4 FUN_00440910(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b13c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = FUN_00440740(local_28,param_2);
  local_4 = 0;
  FUN_004022a0(param_1,s_Data__0099e700,uVar1);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00440980 @ 0x00440980 ====

undefined4 FUN_00440980(undefined4 param_1)

{
  FUN_00446a50(param_1);
  return 1;
}


// ==== FUN_004409a0 @ 0x004409a0 ====

int FUN_004409a0(undefined1 *param_1)

{
  int extraout_EAX;
  char *_Str2;
  int iVar1;
  int *piVar2;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int in_ECX;
  char *****_Str1;
  undefined1 auStack_94 [4];
  undefined1 local_90;
  undefined4 uStack_88;
  undefined1 *puStack_84;
  undefined4 local_80;
  int local_64;
  undefined1 local_60 [4];
  char *****local_5c [5];
  uint local_48;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b188;
  local_c = ExceptionList;
  local_80 = 0x4409cd;
  ExceptionList = &local_c;
  local_80 = FUN_0043fdf0();
  puStack_84 = local_60;
  local_4 = 0;
  uStack_88 = 0x4409e1;
  FUN_004041d0();
  local_4 = CONCAT31(local_4._1_3_,2);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  param_1 = (undefined1 *)FUN_00441440();
  if (param_1 != (undefined1 *)*(int *)(in_ECX + 0x68)) {
    if (*(uint *)((int)param_1 + 0x28) < 0x10) {
      _Str2 = (char *)((int)param_1 + 0x14);
    }
    else {
      _Str2 = *(char **)((int)param_1 + 0x14);
    }
    _Str1 = local_5c[0];
    if (local_48 < 0x10) {
      _Str1 = (char *****)local_5c;
    }
    local_80 = 0x440a4c;
    iVar1 = __stricmp((char *)_Str1,_Str2);
    if (-1 < iVar1) {
      piVar2 = (int *)&param_1;
      goto LAB_00440a64;
    }
  }
  local_64 = *(int *)(in_ECX + 0x68);
  piVar2 = &local_64;
LAB_00440a64:
  if (*piVar2 == *(int *)(in_ECX + 0x68)) {
    param_1 = auStack_94;
    local_80 = 0;
    local_90 = 0;
    FUN_00401740(s_data___s_missing___0099e76c,0x12);
    FUN_00404230(local_44);
    local_4 = CONCAT31(local_4._1_3_,3);
    FUN_00796d50(local_44);
    if (0xf < local_2c) {
      _free(local_40);
      return extraout_EAX_00;
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    if (0xf < local_48) {
      _free(local_5c[0]);
      return extraout_EAX_01;
    }
  }
  else {
    local_80 = *(undefined4 *)(*piVar2 + 0x50);
    puStack_84 = (undefined1 *)0x440b21;
    iVar1 = FUN_00446ab0();
    if (iVar1 != 0) {
      if (local_48 < 0x10) {
        ExceptionList = local_c;
        return iVar1;
      }
      _free(local_5c[0]);
      return extraout_EAX_03;
    }
    if (0xf < local_48) {
      _free(local_5c[0]);
      return extraout_EAX_02;
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_00440b90 @ 0x00440b90 ====

void FUN_00440b90(int param_1)

{
  uint *puVar1;
  char cVar2;
  char *_Memory;
  char *pcVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  int local_1ac;
  int *local_1a8;
  undefined4 local_1a4;
  int local_1a0;
  undefined1 local_19c [4];
  undefined1 local_198;
  undefined4 local_188;
  undefined4 local_184;
  undefined1 local_15c [4];
  void *local_158;
  undefined4 local_148;
  uint local_144;
  void *local_13c;
  undefined4 local_12c;
  uint local_128;
  undefined1 local_108 [4];
  void *local_104;
  undefined4 local_f4;
  uint local_f0;
  undefined1 local_ec [4];
  void *local_e8;
  undefined4 local_d8;
  uint local_d4;
  undefined1 local_d0 [4];
  void *local_cc;
  undefined4 local_bc;
  uint local_b8;
  undefined1 local_b4 [4];
  void *local_b0;
  undefined4 local_a0;
  uint local_9c;
  undefined1 local_98 [8];
  undefined1 local_90 [108];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b202;
  pvStack_c = ExceptionList;
  local_144 = 0xf;
  local_148 = 0;
  local_158 = (void *)((uint)local_158 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Framework__DriverKernel__Data__L_0099e780,0x43);
  local_4 = 0;
  FUN_00401870(local_15c);
  local_4._0_1_ = 2;
  if (0xf < local_144) {
    _free(local_158);
    return;
  }
  local_144 = 0xf;
  local_148 = 0;
  local_158 = (void *)((uint)local_158 & 0xffffff00);
  FUN_004400d0();
  local_4 = CONCAT31(local_4._1_3_,3);
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    param_1 = param_1 + 4;
  }
  else {
    param_1 = *(int *)(param_1 + 4);
  }
  FUN_00440100(param_1,0);
  FUN_0043ff10(400);
  FUN_004402f0(in_ECX + 0x48,8);
  local_1a8 = (int *)(in_ECX + 0x50);
  FUN_004402f0(local_1a8,4);
  puVar1 = (uint *)(in_ECX + 0x54);
  FUN_004402f0(puVar1,4);
  uVar5 = 0;
  if (*puVar1 != 0) {
    do {
      FUN_004402f0(local_98,4);
      FUN_004402f0(local_90,8);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar1);
  }
  local_128 = 0xf;
  local_12c = 0;
  local_13c = (void *)((uint)local_13c & 0xffffff00);
  local_4._0_1_ = 4;
  local_1a4 = 0;
  if (*local_1a8 == 0) {
    FUN_00440260();
    if (0xf < local_128) {
      _free(local_13c);
      return;
    }
    local_128 = 0xf;
    local_12c = 0;
    local_13c = (void *)((uint)local_13c & 0xffffff00);
    local_4 = CONCAT31(local_4._1_3_,2);
    FUN_0043ff50();
    local_4 = 0xb;
    FUN_00796d40();
    if (uStack_10 < 0x10) {
      ExceptionList = pvStack_c;
      return;
    }
    _free(pvStack_24);
    return;
  }
  local_1a0 = in_ECX + 100;
  FUN_004402f0(&local_1ac,4);
  _Memory = operator_new(local_1ac + 1);
  FUN_004402f0(_Memory,local_1ac);
  _Memory[local_1ac] = '\0';
  local_184 = 0xf;
  local_188 = 0;
  local_198 = 0;
  pcVar3 = _Memory;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  FUN_00401740(_Memory,(int)pcVar3 - (int)(_Memory + 1));
  local_4._0_1_ = 5;
  uVar4 = FUN_004041d0(local_d0,local_19c);
  local_4._0_1_ = 6;
  FUN_00401660(uVar4,0,0xffffffff);
  local_4._0_1_ = 5;
  if (0xf < local_b8) {
    _free(local_cc);
    return;
  }
  local_b8 = 0xf;
  local_bc = 0;
  local_cc = (void *)((uint)local_cc & 0xffffff00);
  if ((*_Memory == '/') || (*_Memory == '\\')) {
    uVar4 = FUN_00405b90(local_108,1,local_1ac + -1);
    local_4._0_1_ = 7;
    uVar4 = FUN_0043fdf0(local_ec,uVar4);
    local_4._0_1_ = 8;
    FUN_00401660(uVar4,0,0xffffffff);
    if (0xf < local_d4) {
      _free(local_e8);
      return;
    }
    local_d4 = 0xf;
    local_d8 = 0;
    local_e8 = (void *)((uint)local_e8 & 0xffffff00);
    local_4 = CONCAT31(local_4._1_3_,5);
    if (0xf < local_f0) {
      _free(local_104);
      return;
    }
    local_f0 = 0xf;
    local_f4 = 0;
    local_104 = (void *)((uint)local_104 & 0xffffff00);
  }
  else {
    uVar4 = FUN_0043fdf0(local_b4,local_19c);
    local_4._0_1_ = 9;
    FUN_00401660(uVar4,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,5);
    if (0xf < local_9c) {
      _free(local_b0);
      return;
    }
    local_9c = 0xf;
    local_a0 = 0;
    local_b0 = (void *)((uint)local_b0 & 0xffffff00);
  }
  _free(_Memory);
  return;
}


// ==== FUN_00441090 @ 0x00441090 ====

void FUN_00441090(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097b222;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099e7c8;
  local_4 = 1;
  FUN_00446970();
  local_4 = local_4 & 0xffffff00;
  FUN_00442250();
  local_4 = 0xffffffff;
  FUN_00446cc0();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00441100 @ 0x00441100 ====

void FUN_00441100(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  DWORD local_f0;
  undefined1 local_ec [4];
  void *local_e8;
  undefined4 local_d8;
  uint local_d4;
  undefined4 local_d0;
  undefined1 local_cc [4];
  void *local_c8;
  undefined4 local_b8;
  uint local_b4;
  DWORD local_ac;
  undefined1 local_a8 [4];
  void *local_a4;
  undefined4 local_94;
  uint local_90;
  DWORD local_8c;
  DWORD local_88;
  undefined1 local_84 [4];
  void *local_80;
  undefined4 local_70;
  uint local_6c;
  undefined1 local_68 [4];
  void *local_64;
  undefined4 local_54;
  uint local_50;
  undefined1 local_4c [4];
  void *local_48;
  uint local_34;
  _SYSTEM_INFO local_30;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b284;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099e7c8;
  FUN_00446d80();
  local_4 = 0;
  FUN_004421c0();
  local_4._0_1_ = 1;
  GetDiskFreeSpaceA((LPCSTR)0x0,&local_8c,&local_f0,&local_88,&local_ac);
  in_ECX[0x1d] = local_f0;
  uVar1 = FUN_00404890(local_68);
  local_4._0_1_ = 2;
  uVar1 = FUN_004045b0(local_84,uVar1);
  local_4._0_1_ = 3;
  FUN_004046f0(local_4c,uVar1);
  if (0xf < local_6c) {
    _free(local_80);
    return;
  }
  local_6c = 0xf;
  local_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  local_4._0_1_ = 5;
  if (0xf < local_50) {
    _free(local_64);
    return;
  }
  local_50 = 0xf;
  local_54 = 0;
  local_64 = (void *)((uint)local_64 & 0xffffff00);
  FUN_00402220(local_a8,local_4c,s_data_data_hd_0099e74c);
  local_4._0_1_ = 7;
  FUN_00402220(local_cc,local_4c,s_data_data_pak_0099e75c);
  local_4._0_1_ = 8;
  FUN_00440b90(local_a8);
  local_d4 = 0xf;
  local_d8 = 0;
  local_e8 = (void *)((uint)local_e8 & 0xffffff00);
  local_4 = CONCAT31(local_4._1_3_,9);
  FUN_00401660(local_cc,0,0xffffffff);
  local_d0 = in_ECX[0x1d];
  FUN_004469c0(local_ec);
  GetSystemInfo(&local_30);
  in_ECX[0x1c] = local_30.dwAllocationGranularity;
  if (0xf < local_d4) {
    _free(local_e8);
    return;
  }
  local_d4 = 0xf;
  local_d8 = 0;
  local_e8 = (void *)((uint)local_e8 & 0xffffff00);
  if (0xf < local_b4) {
    _free(local_c8);
    return;
  }
  local_b4 = 0xf;
  local_b8 = 0;
  local_c8 = (void *)((uint)local_c8 & 0xffffff00);
  if (0xf < local_90) {
    _free(local_a4);
    return;
  }
  local_90 = 0xf;
  local_94 = 0;
  local_a4 = (void *)((uint)local_a4 & 0xffffff00);
  if (local_34 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_48);
  return;
}


// ==== FUN_00441360 @ 0x00441360 ====

void FUN_00441360(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x69);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x69);
  }
  return;
}


// ==== FUN_00441380 @ 0x00441380 ====

void FUN_00441380(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x29);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x29);
  }
  return;
}


// ==== FUN_004413a0 @ 0x004413a0 ====

void FUN_004413a0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x69) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x69) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x69);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x69);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x69);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x69);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_004413f0 @ 0x004413f0 ====

void FUN_004413f0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x69) == '\0') {
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


// ==== FUN_00441440 @ 0x00441440 ====

undefined4 * FUN_00441440(int param_1)

{
  char *_Str1;
  int iVar1;
  int in_ECX;
  char *_Str2;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x69) == '\0') {
    puVar2 = puVar3;
    puVar4 = (undefined4 *)puVar3[1];
    do {
      puVar3 = puVar4;
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        _Str2 = (char *)(param_1 + 4);
      }
      else {
        _Str2 = *(char **)(param_1 + 4);
      }
      if ((uint)puVar3[10] < 0x10) {
        _Str1 = (char *)(puVar3 + 5);
      }
      else {
        _Str1 = (char *)puVar3[5];
      }
      iVar1 = __stricmp(_Str1,_Str2);
      if (iVar1 < 0) {
        puVar4 = (undefined4 *)puVar3[2];
        puVar3 = puVar2;
      }
      else {
        puVar4 = (undefined4 *)*puVar3;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar4 + 0x69) == '\0');
  }
  return puVar3;
}


// ==== FUN_004414b0 @ 0x004414b0 ====

void FUN_004414b0(void)

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
  *(undefined1 *)(puVar1 + 10) = 1;
  *(undefined1 *)((int)puVar1 + 0x29) = 0;
  return;
}


// ==== FUN_004414f0 @ 0x004414f0 ====

void FUN_004414f0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x29) == '\0') {
    FUN_004414f0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00441530 @ 0x00441530 ====

void FUN_00441530(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x48)) {
    _free(*(void **)(in_ECX + 0x34));
    return;
  }
  *(undefined4 *)(in_ECX + 0x48) = 0xf;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined1 *)(in_ECX + 0x34) = 0;
  if (*(uint *)(in_ECX + 0x28) < 0x10) {
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0xf;
    *(undefined1 *)(in_ECX + 0x14) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_00441580 @ 0x00441580 ====

void FUN_00441580(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b158;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  FUN_00401660(param_1 + 0x20,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x54);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00441620 @ 0x00441620 ====

void FUN_00441620(undefined4 param_1,int param_2)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b158;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  FUN_00401660(param_2,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_2 + 0x24);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_2 + 0x34);
  ExceptionList = local_c;
  return;
}


// ==== FUN_004416c0 @ 0x004416c0 ====

/* WARNING: Removing unreachable block (ram,0x004417d3) */
/* WARNING: Removing unreachable block (ram,0x004417e3) */
/* WARNING: Removing unreachable block (ram,0x004417ec) */
/* WARNING: Removing unreachable block (ram,0x004417ef) */
/* WARNING: Removing unreachable block (ram,0x004417df) */
/* WARNING: Removing unreachable block (ram,0x004417fd) */
/* WARNING: Removing unreachable block (ram,0x0044180a) */
/* WARNING: Removing unreachable block (ram,0x00441815) */
/* WARNING: Removing unreachable block (ram,0x00441811) */
/* WARNING: Removing unreachable block (ram,0x00441805) */
/* WARNING: Removing unreachable block (ram,0x00441818) */

void FUN_004416c0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097b298;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x29) != '\0') {
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
  FUN_00798b00();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x29) == '\0') {
    if (*(char *)(param_2[2] + 0x29) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x29) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x29) == '\0') {
      piVar3 = (int *)FUN_00441380(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x29) == '\0') {
      uVar4 = FUN_0043e2c0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[10] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[10] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[10] == '\0') {
            *(undefined1 *)(piVar5 + 10) = 1;
            *(undefined1 *)(piVar3 + 10) = 0;
            FUN_004c9300(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x29) == '\0') {
            if ((*(char *)(*piVar5 + 0x28) == '\x01') && (*(char *)(piVar5[2] + 0x28) == '\x01'))
            goto LAB_004418e5;
            if (*(char *)(piVar5[2] + 0x28) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x28) = 1;
              *(undefined1 *)(piVar5 + 10) = 0;
              FUN_0043e2e0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 10) = (char)piVar3[10];
            *(undefined1 *)(piVar3 + 10) = 1;
            *(undefined1 *)(piVar5[2] + 0x28) = 1;
            FUN_004c9300(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[10] == '\0') {
            *(undefined1 *)(piVar5 + 10) = 1;
            *(undefined1 *)(piVar3 + 10) = 0;
            FUN_0043e2e0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x29) == '\0') {
            if ((*(char *)(piVar5[2] + 0x28) != '\x01') || (*(char *)(*piVar5 + 0x28) != '\x01')) {
              if (*(char *)(*piVar5 + 0x28) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x28) = 1;
                *(undefined1 *)(piVar5 + 10) = 0;
                FUN_004c9300(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 10) = (char)piVar3[10];
              *(undefined1 *)(piVar3 + 10) = 1;
              *(undefined1 *)(*piVar5 + 0x28) = 1;
              FUN_0043e2e0(piVar3);
              break;
            }
LAB_004418e5:
            *(undefined1 *)(piVar5 + 10) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 10) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_00441970 @ 0x00441970 ====

undefined4 *
FUN_00441970(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097b2c1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x70);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    FUN_00441580(param_4);
    *(undefined1 *)(puVar1 + 0x1a) = param_5;
    *(undefined1 *)((int)puVar1 + 0x69) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@004419ee @ 0x004419ee ====

void Catch_004419ee(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00441a10 @ 0x00441a10 ====

void FUN_00441a10(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004414f0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x29) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x29) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x29);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x29);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x29);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x29);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004416c0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00441ad0 @ 0x00441ad0 ====

/* WARNING: Removing unreachable block (ram,0x00441bdd) */
/* WARNING: Removing unreachable block (ram,0x00441bed) */
/* WARNING: Removing unreachable block (ram,0x00441bf6) */
/* WARNING: Removing unreachable block (ram,0x00441bf9) */
/* WARNING: Removing unreachable block (ram,0x00441be9) */
/* WARNING: Removing unreachable block (ram,0x00441c07) */
/* WARNING: Removing unreachable block (ram,0x00441c14) */
/* WARNING: Removing unreachable block (ram,0x00441c1f) */
/* WARNING: Removing unreachable block (ram,0x00441c1b) */
/* WARNING: Removing unreachable block (ram,0x00441c0f) */
/* WARNING: Removing unreachable block (ram,0x00441c22) */

void FUN_00441ad0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b298;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x69) != '\0') {
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
  FUN_004413a0();
  piVar5 = (int *)*param_2;
  if (*(char *)((int)piVar5 + 0x69) == '\0') {
    if (*(char *)(param_2[2] + 0x69) == '\0') {
      piVar5 = (int *)param_2[2];
    }
  }
  else {
    piVar5 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar5 + 0x69) == '\0') {
    piVar5[1] = (int)piVar6;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar5;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar5;
  }
  else {
    piVar6[2] = (int)piVar5;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar5 + 0x69) == '\0') {
      piVar3 = (int *)FUN_00441360(piVar5);
    }
    else {
      piVar3 = piVar6;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar5 + 0x69) == '\0') {
      uVar4 = FUN_0043e2a0(piVar5);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar6;
    }
  }
  if ((char)param_2[0x1a] == '\x01') {
    if (piVar5 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        if ((char)piVar5[0x1a] != '\x01') break;
        piVar3 = (int *)*piVar6;
        if (piVar5 == piVar3) {
          piVar3 = (int *)piVar6[2];
          if ((char)piVar3[0x1a] == '\0') {
            *(undefined1 *)(piVar3 + 0x1a) = 1;
            *(undefined1 *)(piVar6 + 0x1a) = 0;
            FUN_004413f0(piVar6);
            piVar3 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar3 + 0x69) == '\0') {
            if ((*(char *)(*piVar3 + 0x68) == '\x01') && (*(char *)(piVar3[2] + 0x68) == '\x01'))
            goto LAB_00441cf4;
            if (*(char *)(piVar3[2] + 0x68) == '\x01') {
              *(undefined1 *)(*piVar3 + 0x68) = 1;
              *(undefined1 *)(piVar3 + 0x1a) = 0;
              FUN_0043ee80(piVar3);
              piVar3 = (int *)piVar6[2];
            }
            *(char *)(piVar3 + 0x1a) = (char)piVar6[0x1a];
            *(undefined1 *)(piVar6 + 0x1a) = 1;
            *(undefined1 *)(piVar3[2] + 0x68) = 1;
            FUN_004413f0(piVar6);
            break;
          }
        }
        else {
          if ((char)piVar3[0x1a] == '\0') {
            *(undefined1 *)(piVar3 + 0x1a) = 1;
            *(undefined1 *)(piVar6 + 0x1a) = 0;
            FUN_0043ee80(piVar6);
            piVar3 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar3 + 0x69) == '\0') {
            if ((*(char *)(piVar3[2] + 0x68) != '\x01') || (*(char *)(*piVar3 + 0x68) != '\x01')) {
              if (*(char *)(*piVar3 + 0x68) == '\x01') {
                *(undefined1 *)(piVar3[2] + 0x68) = 1;
                *(undefined1 *)(piVar3 + 0x1a) = 0;
                FUN_004413f0(piVar3);
                piVar3 = (int *)*piVar6;
              }
              *(char *)(piVar3 + 0x1a) = (char)piVar6[0x1a];
              *(undefined1 *)(piVar6 + 0x1a) = 1;
              *(undefined1 *)(*piVar3 + 0x68) = 1;
              FUN_0043ee80(piVar6);
              break;
            }
LAB_00441cf4:
            *(undefined1 *)(piVar3 + 0x1a) = 0;
          }
        }
        bVar7 = piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4);
        piVar5 = piVar6;
        piVar6 = (int *)piVar6[1];
      } while (bVar7);
    }
    *(undefined1 *)(piVar5 + 0x1a) = 1;
  }
  if (0xf < (uint)param_2[0x12]) {
    _free((void *)param_2[0xd]);
    return;
  }
  param_2[0x12] = 0xf;
  param_2[0x11] = 0;
  *(undefined1 *)(param_2 + 0xd) = 0;
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


// ==== FUN_00441dc0 @ 0x00441dc0 ====

void FUN_00441dc0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x69) == '\0') {
    FUN_00441dc0(*(undefined4 *)((int)param_1 + 8));
    FUN_00441530();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004420d0 @ 0x004420d0 ====

void FUN_004420d0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00441dc0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x69) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x69) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x69);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x69);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x69);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x69);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00441ad0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00442190 @ 0x00442190 ====

void FUN_00442190(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00441a10(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004421c0 @ 0x004421c0 ====

void FUN_004421c0(void)

{
  int iVar1;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b2db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_004414b0();
  *(int *)(in_ECX + 0x14) = iVar1;
  *(undefined1 *)(iVar1 + 0x29) = 1;
  *(int *)(*(int *)(in_ECX + 0x14) + 4) = *(int *)(in_ECX + 0x14);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x14);
  *(int *)(*(int *)(in_ECX + 0x14) + 8) = *(int *)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = 0;
  local_4 = 0;
  iVar1 = FUN_0043ef90();
  *(int *)(in_ECX + 0x20) = iVar1;
  *(undefined1 *)(iVar1 + 0x69) = 1;
  *(int *)(*(int *)(in_ECX + 0x20) + 4) = *(int *)(in_ECX + 0x20);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(in_ECX + 0x20);
  *(int *)(*(int *)(in_ECX + 0x20) + 8) = *(int *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00442250 @ 0x00442250 ====

void FUN_00442250(void)

{
  int in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b2fb;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_004420d0(local_10,**(undefined4 **)(in_ECX + 0x20),*(undefined4 **)(in_ECX + 0x20));
  _free(*(void **)(in_ECX + 0x20));
  return;
}


// ==== FUN_004422f0 @ 0x004422f0 ====

void FUN_004422f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00441090();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00442310 @ 0x00442310 ====

void FUN_00442310(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_00442310(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00442350 @ 0x00442350 ====

/* WARNING: Removing unreachable block (ram,0x00442460) */
/* WARNING: Removing unreachable block (ram,0x00442471) */
/* WARNING: Removing unreachable block (ram,0x0044247a) */
/* WARNING: Removing unreachable block (ram,0x0044247d) */
/* WARNING: Removing unreachable block (ram,0x0044246d) */
/* WARNING: Removing unreachable block (ram,0x0044248b) */
/* WARNING: Removing unreachable block (ram,0x00442498) */
/* WARNING: Removing unreachable block (ram,0x004424a3) */
/* WARNING: Removing unreachable block (ram,0x0044249f) */
/* WARNING: Removing unreachable block (ram,0x00442493) */
/* WARNING: Removing unreachable block (ram,0x004424a6) */

void FUN_00442350(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097b318;
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
            goto LAB_00442577;
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
LAB_00442577:
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


// ==== FUN_00442620 @ 0x00442620 ====

void * FUN_00442620(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097b341;
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


// ==== Catch@00442692 @ 0x00442692 ====

void Catch_00442692(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004426b0 @ 0x004426b0 ====

undefined4 FUN_004426b0(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  
  piVar2 = param_1;
  uVar4 = (**(code **)(*param_1 + 4))();
  FUN_0069a470(&param_1,uVar4);
  piVar3 = param_1;
  if (param_1 == *(int **)(in_ECX + 0xc)) {
    return 0;
  }
  puVar1 = (undefined4 *)param_1[10];
  FUN_00446a50(piVar2);
  iVar5 = FUN_00446960();
  if (iVar5 == 0) {
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    FUN_00442350(&param_1,piVar3);
  }
  return 1;
}


// ==== FUN_00442720 @ 0x00442720 ====

void * FUN_00442720(void *param_1)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  int in_ECX;
  int iVar5;
  int iVar6;
  undefined1 local_54 [8];
  undefined1 local_4c [4];
  void *local_48;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_18;
  uint local_14;
  undefined4 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  iVar5 = (int)param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b36b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0069a470(&param_1,param_1);
  if (param_1 == (void *)*(int *)(in_ECX + 0xc)) {
    local_34 = 0xf;
    local_38 = 0;
    local_48 = (void *)((uint)local_48 & 0xffffff00);
    local_4 = 0;
    FUN_00401660(iVar5,0,0xffffffff);
    local_30 = *(undefined4 *)(in_ECX + 4);
    param_1 = operator_new(0x40);
    local_4._0_1_ = 1;
    if (param_1 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)FUN_00446d80();
    }
    local_4 = (uint)local_4._1_3_ << 8;
    cVar1 = FUN_004469c0(local_4c);
    if (cVar1 != '\0') {
      iVar6 = iVar5;
      uVar2 = FUN_00446950(iVar5);
      param_1 = (void *)FUN_00446ab0(0,uVar2,iVar6);
      if (param_1 != (void *)0x0) {
        local_14 = 0xf;
        local_18 = 0;
        local_28 = (void *)((uint)local_28 & 0xffffff00);
        FUN_00401660(iVar5,0,0xffffffff);
        local_4 = CONCAT31(local_4._1_3_,2);
        local_10 = puVar4;
        FUN_00442c90(local_54,local_2c);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_00;
        }
        if (local_34 < 0x10) {
          ExceptionList = local_c;
          return param_1;
        }
        _free(local_48);
        return extraout_EAX_01;
      }
    }
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    if (0xf < local_34) {
      _free(local_48);
      return extraout_EAX;
    }
  }
  else {
    puVar4 = *(undefined4 **)((int)param_1 + 0x28);
    uVar2 = FUN_00446950(iVar5);
    pvVar3 = (void *)FUN_00446ab0(0,uVar2,iVar5);
    if (pvVar3 != (void *)0x0) {
      ExceptionList = local_c;
      return pvVar3;
    }
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
      ExceptionList = local_10;
      return (void *)0x0;
    }
  }
  ExceptionList = local_c;
  return (void *)0x0;
}


// ==== FUN_004428d0 @ 0x004428d0 ====

void FUN_004428d0(void)

{
  undefined4 *in_ECX;
  uint local_14;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b380;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099e7d0;
  local_4 = 0;
  if (in_ECX[4] != 0) {
    local_14 = local_14 & 0xffffff00;
    FUN_0082c4f0(*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3],local_14);
    FUN_00442310(*(undefined4 *)(in_ECX[3] + 4));
    *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
    in_ECX[4] = 0;
    *(undefined4 *)in_ECX[3] = in_ECX[3];
    *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  }
  local_4 = 0xffffffff;
  FUN_00442bd0(local_10,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00442980 @ 0x00442980 ====

void FUN_00442980(void)

{
  int iVar1;
  undefined4 *in_ECX;
  DWORD local_10;
  DWORD local_c;
  DWORD local_8;
  DWORD local_4;
  
  *in_ECX = &PTR_FUN_0099e7d0;
  iVar1 = FUN_004a37b0();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  GetDiskFreeSpaceA((LPCSTR)0x0,&local_4,&local_10,&local_8,&local_c);
  in_ECX[1] = local_10;
  return;
}


// ==== FUN_004429f0 @ 0x004429f0 ====

void FUN_004429f0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097b318;
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
  piVar4 = (int *)FUN_00442620(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00442ae9:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_00442ae9;
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


// ==== FUN_00442bd0 @ 0x00442bd0 ====

void FUN_00442bd0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00442310(piVar6[1]);
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
    FUN_00442350(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00442c90 @ 0x00442c90 ====

/* WARNING: Removing unreachable block (ram,0x00442cef) */

void FUN_00442c90(undefined4 *param_1,undefined4 *param_2)

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
LAB_00442d20:
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
        if (uVar5 == 0) goto LAB_00442d20;
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
      puVar6 = (undefined4 *)FUN_004429f0(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_004429f0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_00442e00 @ 0x00442e00 ====

void FUN_00442e00(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00442bd0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00442e30 @ 0x00442e30 ====

void FUN_00442e30(byte param_1)

{
  void *in_ECX;
  
  FUN_004428d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00442ee0 @ 0x00442ee0 ====

void FUN_00442ee0(void)

{
  return;
}


// ==== FUN_00442ef0 @ 0x00442ef0 ====

void FUN_00442ef0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== FUN_00442f20 @ 0x00442f20 ====

undefined4 FUN_00442f20(void)

{
  return 0;
}


// ==== FUN_00442f30 @ 0x00442f30 ====

undefined4 FUN_00442f30(void)

{
  return 0;
}


// ==== FUN_00442f40 @ 0x00442f40 ====

void FUN_00442f40(void)

{
  return;
}


// ==== FUN_00442f50 @ 0x00442f50 ====

undefined1 FUN_00442f50(void)

{
  return 0;
}


// ==== FUN_00442f60 @ 0x00442f60 ====

undefined1 FUN_00442f60(void)

{
  return 0;
}


// ==== FUN_00442f70 @ 0x00442f70 ====

undefined1 FUN_00442f70(void)

{
  return 0;
}


// ==== FUN_00442f90 @ 0x00442f90 ====

void FUN_00442f90(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *puVar1 = &PTR_FUN_0099e808;
  *in_ECX = &PTR_FUN_0099e818;
  *puVar1 = &PTR_FUN_0099e810;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a7e8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a7e8 = in_ECX;
  return;
}


// ==== FUN_00442fc0 @ 0x00442fc0 ====

void FUN_00442fc0(void *param_1)

{
  _free(param_1);
  return;
}


// ==== FUN_00442fd0 @ 0x00442fd0 ====

void FUN_00442fd0(void)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x20080;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  iVar2 = FUN_004244d0();
  uVar3 = FUN_00447bf0();
  *(uint *)(iVar2 + 0x10) =
       CONCAT31((int3)uVar3,(char)(uVar3 >> 8)) << 0x10 | uVar3 >> 0x18 |
       (uVar3 >> 0x10 & 0xff) << 8;
  FUN_00447b80(iVar2);
  FUN_00448140(iVar2);
  FUN_00447ba0();
  FUN_00447a30();
  return;
}


// ==== FUN_00443050 @ 0x00443050 ====

void FUN_00443050(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = &PTR_FUN_0099e810;
  DAT_00b5a7e8 = 0;
  in_ECX[1] = &PTR_FUN_0099e808;
  *in_ECX = &PTR_FUN_0099e7d8;
  return;
}


// ==== FUN_00443070 @ 0x00443070 ====

void FUN_00443070(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  
  FUN_00447af0(param_1);
  piVar1 = (int *)FUN_00447b90();
  (**(code **)(*piVar1 + 0x14))();
  FUN_00447b80();
  FUN_00447dd0();
  FUN_00447b70();
  FUN_00448560();
  FUN_00447bb0();
  FUN_00448420();
  FUN_00447ba0();
  FUN_00447930();
  FUN_00447be0(DAT_00b5a7ec);
  FUN_00442fd0(param_2);
  return;
}


// ==== FUN_004430f0 @ 0x004430f0 ====

void FUN_004430f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e7d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00443110 @ 0x00443110 ====

void FUN_00443110(void)

{
  FUN_00443140();
  return;
}


// ==== FUN_00443120 @ 0x00443120 ====

void FUN_00443120(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e808;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00443140 @ 0x00443140 ====

void FUN_00443140(byte param_1)

{
  void *in_ECX;
  
  FUN_00443050();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00443210 @ 0x00443210 ====

void FUN_00443210(void)

{
  return;
}


// ==== FUN_00443220 @ 0x00443220 ====

void FUN_00443220(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== FUN_00443250 @ 0x00443250 ====

undefined4 FUN_00443250(void)

{
  return 0;
}


// ==== FUN_00443260 @ 0x00443260 ====

undefined4 FUN_00443260(void)

{
  return 0;
}


// ==== FUN_00443270 @ 0x00443270 ====

void FUN_00443270(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00447bc0();
  if ((*param_1 == *piVar1) && (param_1[1] == piVar1[1])) {
    FUN_00447ba0();
    thunk_FUN_00447960();
  }
  return;
}


// ==== FUN_004432a0 @ 0x004432a0 ====

undefined4 FUN_004432a0(int *param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  
  piVar2 = (int *)FUN_00447bc0();
  if ((*param_1 == *piVar2) && (param_1[1] == piVar2[1])) {
    FUN_00447bb0();
    cVar1 = thunk_FUN_00448470();
    if (cVar1 != '\x01') {
      (**(code **)(*in_ECX + 8))(0,param_2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004432f0 @ 0x004432f0 ====

undefined4 FUN_004432f0(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int *in_ECX;
  
  uVar1 = FUN_00424830();
  uVar2 = FUN_00447bf0();
  if ((uVar1 < uVar2) || (uVar1 - uVar2 < 0x7531)) {
    return 0;
  }
  (**(code **)(*in_ECX + 8))(0,param_1);
  return 1;
}


// ==== FUN_00443360 @ 0x00443360 ====

void FUN_00443360(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *puVar1 = &PTR_FUN_0099e848;
  *in_ECX = &PTR_FUN_0099e858;
  *puVar1 = &PTR_FUN_0099e850;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a7ec = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a7ec = in_ECX;
  return;
}


// ==== FUN_00443390 @ 0x00443390 ====

void FUN_00443390(char param_1)

{
  int *piVar1;
  
  if (param_1 != '\x01') {
    FUN_00447be0(DAT_00b5a7e8);
    FUN_00447ba0();
    FUN_004479f0();
    FUN_00447bb0();
    FUN_00448430();
    FUN_00447b70();
    FUN_00448650();
    FUN_00447b80();
    FUN_00447e10();
    piVar1 = (int *)FUN_00447b90();
    (**(code **)(*piVar1 + 0x18))();
    FUN_00447b50();
  }
  return;
}


// ==== FUN_00443400 @ 0x00443400 ====

void FUN_00443400(void *param_1)

{
  _free(param_1);
  return;
}


// ==== FUN_00443410 @ 0x00443410 ====

void FUN_00443410(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = &PTR_FUN_0099e850;
  DAT_00b5a7ec = 0;
  in_ECX[1] = &PTR_FUN_0099e848;
  *in_ECX = &PTR_FUN_0099e7d8;
  return;
}


// ==== FUN_00443430 @ 0x00443430 ====

void FUN_00443430(void *param_1,undefined4 param_2)

{
  int iVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b398;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  iVar1 = FUN_00424500();
  if (iVar1 == 0x20081) {
    FUN_00443610(param_1,param_2);
    _free(param_1);
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_004434c0 @ 0x004434c0 ====

void FUN_004434c0(void)

{
  undefined4 *in_ECX;
  
  _free((void *)*in_ECX);
  return;
}


// ==== FUN_004434d0 @ 0x004434d0 ====

void FUN_004434d0(void)

{
  FUN_00443790();
  return;
}


// ==== FUN_004434e0 @ 0x004434e0 ====

void FUN_004434e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e848;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00443500 @ 0x00443500 ====

void FUN_00443500(void)

{
  int *piVar1;
  undefined1 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined2 unaff_BX;
  undefined4 unaff_ESI;
  undefined4 local_10;
  int iStack_c;
  
  pvVar3 = operator_new(0x400);
  *(undefined4 *)((int)pvVar3 + 8) = 0;
  *(undefined4 *)((int)pvVar3 + 0xc) = 0x10002;
  *(undefined2 *)((int)pvVar3 + 6) = 0x18;
  iVar4 = FUN_004244d0();
  puVar5 = (undefined4 *)FUN_00447bc0();
  piVar1 = (int *)*puVar5;
  (**(code **)(*piVar1 + 0x18))(&local_10,puVar5[1]);
  *(undefined4 *)(iVar4 + 0x10) = unaff_ESI;
  *(undefined2 *)(iVar4 + 0x14) = unaff_BX;
  uVar2 = (**(code **)(*piVar1 + 0x14))();
  *(undefined1 *)(iVar4 + 0x16) = uVar2;
  iStack_c = iVar4;
  local_10 = FUN_00447b60();
  (**(code **)(*DAT_00b5a68c + 0x10))(&local_10);
  return;
}


// ==== FUN_00443590 @ 0x00443590 ====

void FUN_00443590(uint param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x20082;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  iVar2 = FUN_004244d0();
  *(uint *)(iVar2 + 0x10) =
       CONCAT31((int3)param_1,(char)(param_1 >> 8)) << 0x10 | param_1 >> 0x18 |
       (param_1 >> 0x10 & 0xff) << 8;
  FUN_00447b80(iVar2);
  FUN_00448140(iVar2);
  FUN_00447ba0();
  FUN_00447a30();
  return;
}


// ==== FUN_00443610 @ 0x00443610 ====

undefined4 FUN_00443610(int param_1,uint param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uStack_18;
  int iStack_14;
  uint uStack_10;
  int iStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  uVar7 = param_2;
  iVar6 = param_1;
  uVar4 = *(uint *)(param_1 + 0x10);
  uVar8 = *(uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 0x10) =
       CONCAT31((int3)uVar4,(char)(uVar4 >> 8)) << 0x10 | uVar4 >> 0x18 |
       (uVar4 >> 0x10 & 0xff) << 8;
  puVar1 = (undefined1 *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x14) =
       CONCAT31((int3)uVar8,(char)(uVar8 >> 8)) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
       uVar8 >> 0x18;
  puVar2 = (undefined1 *)(param_1 + 0x1c);
  param_1._0_2_ = CONCAT11(*puVar2,*puVar1);
  FUN_00447cd0(&param_1);
  FUN_00447ca0(iVar6 + 0x20);
  uVar4 = FUN_00424830();
  if (uVar4 < *(uint *)(iVar6 + 0x14)) {
    return 0;
  }
  iVar3 = *(int *)(iVar6 + 0x10);
  uVar8 = uVar4 - *(uint *)(iVar6 + 0x14);
  FUN_00447c00(uVar4);
  param_2 = uVar8 >> 1;
  FUN_00447c50((param_2 - uVar4) + iVar3);
  FUN_00447c70(uVar8);
  param_2 = param_2 + iVar3;
  uStack_10 = uVar8;
  iStack_c = param_2;
  uStack_8 = uVar4;
  uStack_4 = FUN_00424840();
  FUN_00447c20(&uStack_10);
  FUN_00443590(iVar3,uVar7);
  FUN_00447be0(DAT_00b5a7f0);
  FUN_00443500(uVar7);
  pvVar5 = operator_new(0x400);
  *(undefined4 *)((int)pvVar5 + 8) = 0;
  *(undefined4 *)((int)pvVar5 + 0xc) = 0x10005;
  *(undefined2 *)((int)pvVar5 + 6) = 0x20;
  iVar6 = FUN_004244d0();
  *(uint *)(iVar6 + 0x10) = uVar8;
  *(uint *)(iVar6 + 0x14) = param_2;
  *(uint *)(iVar6 + 0x18) = uVar4;
  uVar7 = FUN_00424840();
  *(undefined4 *)(iVar6 + 0x1c) = uVar7;
  iStack_14 = iVar6;
  uStack_18 = FUN_00447b60();
  (**(code **)(*DAT_00b5a68c + 0x10))(&uStack_18);
  return 1;
}


// ==== FUN_00443790 @ 0x00443790 ====

void FUN_00443790(byte param_1)

{
  void *in_ECX;
  
  FUN_00443410();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00443860 @ 0x00443860 ====

void FUN_00443860(void)

{
  return;
}


// ==== FUN_00443870 @ 0x00443870 ====

undefined4 * FUN_00443870(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00447c10();
  *param_1 = *puVar1;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  param_1[3] = puVar1[3];
  return param_1;
}


// ==== FUN_004438a0 @ 0x004438a0 ====

int FUN_004438a0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00447c40();
  iVar2 = FUN_00424830();
  return iVar2 + iVar1;
}


// ==== FUN_004438c0 @ 0x004438c0 ====

int FUN_004438c0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00447bf0();
  iVar2 = FUN_00424830();
  return iVar2 + iVar1;
}


// ==== FUN_004438e0 @ 0x004438e0 ====

void FUN_004438e0(undefined4 param_1)

{
  FUN_00447b80(param_1);
  FUN_00448140(param_1);
  FUN_00447ba0();
  FUN_00447a30();
  return;
}


// ==== FUN_00443910 @ 0x00443910 ====

void FUN_00443910(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00447bc0();
  if ((*param_1 == *piVar1) && (param_1[1] == piVar1[1])) {
    FUN_00447ba0();
    thunk_FUN_00447960();
  }
  return;
}


// ==== FUN_00443940 @ 0x00443940 ====

undefined4 FUN_00443940(int *param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  
  piVar2 = (int *)FUN_00447bc0();
  if ((*param_1 == *piVar2) && (param_1[1] == piVar2[1])) {
    FUN_00447bb0();
    cVar1 = thunk_FUN_00448470();
    if (cVar1 != '\x01') {
      (**(code **)(*in_ECX + 8))(0,param_2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00443990 @ 0x00443990 ====

undefined4 FUN_00443990(int param_1)

{
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  char local_80 [128];
  
  local_90 = *(undefined4 *)(param_1 + 0x10);
  local_8c = *(undefined4 *)(param_1 + 0x14);
  local_88 = *(undefined4 *)(param_1 + 0x18);
  local_84 = *(undefined4 *)(param_1 + 0x1c);
  _sprintf(local_80,s_Auth_Server___lu__lu__lu__lu_0099e888,local_90,local_8c,local_88,local_84);
  OutputDebugStringA(local_80);
  FUN_00815860(&local_90);
  return 1;
}


// ==== FUN_00443a20 @ 0x00443a20 ====

void FUN_00443a20(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *puVar1 = &PTR_FUN_0099e8ac;
  *in_ECX = &PTR_FUN_0099e8bc;
  *puVar1 = &PTR_FUN_0099e8b4;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a7f0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a7f0 = in_ECX;
  return;
}


// ==== FUN_00443a50 @ 0x00443a50 ====

void FUN_00443a50(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = &PTR_FUN_0099e8b4;
  DAT_00b5a7f0 = 0;
  in_ECX[1] = &PTR_FUN_0099e8ac;
  *in_ECX = &PTR_FUN_0099e7d8;
  return;
}


// ==== FUN_00443a70 @ 0x00443a70 ====

void FUN_00443a70(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  
  FUN_00443cd0(param_1,param_2);
  FUN_00447be0(DAT_00b5a7e8);
  FUN_00447ba0();
  FUN_004479f0();
  FUN_00447bb0();
  FUN_00448430();
  FUN_00447b70();
  FUN_00448650();
  FUN_00447b80();
  FUN_00447e10();
  piVar1 = (int *)FUN_00447b90();
  (**(code **)(*piVar1 + 0x18))();
  FUN_00447b50();
  return;
}


// ==== FUN_00443ae0 @ 0x00443ae0 ====

uint FUN_00443ae0(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  FUN_00447b80();
  FUN_00448290();
  FUN_00447ba0();
  FUN_00447a30();
  uVar1 = FUN_00424830();
  uVar2 = FUN_00447bf0();
  if ((uVar2 <= uVar1) && (20000 < uVar1 - uVar2)) {
    uVar2 = FUN_00443d30(uVar1,param_1);
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_00443b40 @ 0x00443b40 ====

void FUN_00443b40(void *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b3b8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  cVar1 = FUN_004244e0(1);
  if (cVar1 == '\x01') {
    _free(param_1);
    return;
  }
  cVar1 = FUN_004244e0(2);
  if (cVar1 == '\x01') {
    FUN_00443f70(param_1,param_2);
    _free(param_1);
    return;
  }
  local_10 = param_1;
  local_14 = FUN_00447b60();
  (**(code **)(*DAT_00b5a68c + 0x10))(&local_14);
  _free((void *)0x0);
  return;
}


// ==== FUN_00443c10 @ 0x00443c10 ====

undefined4 FUN_00443c10(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x10) =
       CONCAT31((int3)uVar1,(char)(uVar1 >> 8)) << 0x10 | uVar1 >> 0x18 |
       (uVar1 >> 0x10 & 0xff) << 8;
  uVar2 = FUN_00424830();
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar2 < uVar1) {
    return 0;
  }
  FUN_00447c00(uVar2);
  FUN_00447c70(uVar2 - uVar1);
  return 1;
}


// ==== FUN_00443c70 @ 0x00443c70 ====

undefined4 FUN_00443c70(int param_1)

{
  undefined4 in_EAX;
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)in_EAX >> 0x10),*(ushort *)(param_1 + 0x10) >> 8) |
          (uint)(byte)*(ushort *)(param_1 + 0x10) << 8;
  *(short *)(param_1 + 0x10) = (short)uVar1;
  FUN_00447b80(uVar1);
  FUN_00447ee0(uVar1);
  return 1;
}


// ==== FUN_00443ca0 @ 0x00443ca0 ====

void FUN_00443ca0(void)

{
  FUN_00443f50();
  return;
}


// ==== FUN_00443cb0 @ 0x00443cb0 ====

void FUN_00443cb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e8ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00443cd0 @ 0x00443cd0 ====

void FUN_00443cd0(undefined1 param_1)

{
  void *pvVar1;
  undefined4 local_8;
  int local_4;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x10003;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  local_4 = FUN_004244d0();
  *(undefined1 *)(local_4 + 0x10) = param_1;
  local_8 = FUN_00447b60();
  (**(code **)(*DAT_00b5a68c + 0x10))(&local_8);
  return;
}


// ==== FUN_00443d30 @ 0x00443d30 ====

void FUN_00443d30(uint param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x20083;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  iVar2 = FUN_004244d0();
  *(uint *)(iVar2 + 0x10) =
       CONCAT31((int3)param_1,(char)(param_1 >> 8)) << 0x10 | param_1 >> 0x18 |
       (param_1 >> 0x10 & 0xff) << 8;
  FUN_00447b80(iVar2);
  FUN_00448140(iVar2);
  FUN_00447ba0();
  FUN_00447a30();
  return;
}


// ==== FUN_00443db0 @ 0x00443db0 ====

void FUN_00443db0(uint param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x20084;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  iVar2 = FUN_004244d0();
  *(uint *)(iVar2 + 0x10) =
       CONCAT31((int3)param_1,(char)(param_1 >> 8)) << 0x10 | param_1 >> 0x18 |
       (param_1 >> 0x10 & 0xff) << 8;
  FUN_00447b80(iVar2);
  FUN_00448140(iVar2);
  FUN_00447ba0();
  FUN_00447a30();
  return;
}


// ==== FUN_00443e30 @ 0x00443e30 ====

undefined4 FUN_00443e30(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uStack_18;
  int iStack_14;
  uint uStack_10;
  int iStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  uVar2 = *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x10) =
       CONCAT31((int3)uVar2,(char)(uVar2 >> 8)) << 0x10 | uVar2 >> 0x18 |
       (uVar2 >> 0x10 & 0xff) << 8;
  iVar1 = FUN_00424830();
  iVar6 = *(int *)(param_1 + 0x10);
  uVar2 = FUN_00447c60();
  FUN_00424850(s_>>>>_Receive_Ping____u_0099e8e8,iVar6);
  FUN_00447c50(((uVar2 >> 1) - iVar1) + iVar6);
  iVar6 = iVar6 + (uVar2 >> 1);
  uStack_10 = uVar2;
  iStack_c = iVar6;
  iStack_8 = iVar1;
  uStack_4 = FUN_00424840();
  FUN_00447c20(&uStack_10);
  FUN_00443db0(*(undefined4 *)(param_1 + 0x10),param_2);
  pvVar3 = operator_new(0x400);
  *(undefined4 *)((int)pvVar3 + 8) = 0;
  *(undefined4 *)((int)pvVar3 + 0xc) = 0x10005;
  *(undefined2 *)((int)pvVar3 + 6) = 0x20;
  iVar4 = FUN_004244d0();
  *(uint *)(iVar4 + 0x10) = uVar2;
  *(int *)(iVar4 + 0x14) = iVar6;
  *(int *)(iVar4 + 0x18) = iVar1;
  uVar5 = FUN_00424840();
  *(undefined4 *)(iVar4 + 0x1c) = uVar5;
  iStack_14 = iVar4;
  uStack_18 = FUN_00447b60();
  (**(code **)(*DAT_00b5a68c + 0x10))(&uStack_18);
  return 1;
}


// ==== FUN_00443f50 @ 0x00443f50 ====

void FUN_00443f50(byte param_1)

{
  void *in_ECX;
  
  FUN_00443a50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00443f70 @ 0x00443f70 ====

undefined1 FUN_00443f70(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  uVar1 = 0;
  uVar2 = FUN_00424500();
  switch(uVar2) {
  case 0x20005:
    uVar1 = FUN_00443c70(param_1,param_2);
    return uVar1;
  case 0x20083:
    uVar1 = FUN_00443e30(param_1,param_2);
    return uVar1;
  case 0x20084:
    uVar1 = FUN_00443c10(param_1,param_2);
    return uVar1;
  case 0x2008a:
    uVar1 = FUN_00443990(param_1,param_2);
  }
  return uVar1;
}


// ==== FUN_00444090 @ 0x00444090 ====

void FUN_00444090(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e920;
  return;
}


// ==== FUN_004440a0 @ 0x004440a0 ====

void FUN_004440a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e920;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004440c0 @ 0x004440c0 ====

void FUN_004440c0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)FUN_00447bd0();
  (**(code **)(*piVar1 + 4))(param_1,*(undefined4 *)(in_ECX + 0x20));
  return;
}


// ==== FUN_004440e0 @ 0x004440e0 ====

undefined4 FUN_004440e0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)FUN_00447bd0();
  (**(code **)(*piVar1 + 0xc))(param_1,*(undefined4 *)(in_ECX + 0x20));
  return param_1;
}


// ==== FUN_00444110 @ 0x00444110 ====

void FUN_00444110(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)FUN_00447bd0();
  (**(code **)(*piVar1 + 0x10))(*(undefined4 *)(in_ECX + 0x20));
  return;
}


// ==== FUN_00444130 @ 0x00444130 ====

void FUN_00444130(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)FUN_00447bd0();
  (**(code **)(*piVar1 + 0x14))(*(undefined4 *)(in_ECX + 0x20));
  return;
}


// ==== __break @ 0x0044414f ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00444150 @ 0x00444150 ====

void FUN_00444150(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)FUN_00447bd0();
  (**(code **)(*piVar1 + 0x18))(param_1,*(undefined4 *)(in_ECX + 0x20));
  return;
}


// ==== FUN_00444170 @ 0x00444170 ====

void FUN_00444170(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)FUN_00447bd0();
  (**(code **)(*piVar1 + 0x1c))(param_1,*(undefined4 *)(in_ECX + 0x20));
  return;
}


// ==== FUN_004441a0 @ 0x004441a0 ====

void FUN_004441a0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097b425;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099e94c;
  pvVar1 = operator_new(0x78);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00447cf0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[8] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00449700(in_ECX[8]);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0x20);
  local_4._0_1_ = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004492e0(in_ECX[8]);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x1c);
  local_4._0_1_ = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00447fc0(in_ECX[8]);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[7] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4._0_1_ = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00448910(in_ECX[8]);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(8);
  local_4._0_1_ = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004483f0(in_ECX[8]);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(0x14);
  local_4._0_1_ = 7;
  if (pvVar1 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    local_24 = FUN_004478c0(in_ECX[8]);
  }
  local_1c = in_ECX[6];
  local_18 = in_ECX[7];
  local_14 = in_ECX[2];
  in_ECX[4] = local_24;
  local_10 = in_ECX[3];
  local_20 = in_ECX[5];
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00447ab0(local_28);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00444350 @ 0x00444350 ====

void FUN_00444350(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b437;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099e94c;
  local_4 = 0;
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
  if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[7])(1);
  }
  in_ECX[7] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
  }
  in_ECX[8] = 0;
  *in_ECX = &PTR_FUN_0099e920;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00444410 @ 0x00444410 ====

void FUN_00444410(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)FUN_00447bd0();
  (**(code **)(*piVar1 + 8))(param_1,*(undefined4 *)(in_ECX + 0x20));
  (**(code **)(*DAT_00b5a7dc + 8))();
  return;
}


// ==== FUN_00444440 @ 0x00444440 ====

void FUN_00444440(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)FUN_00447bd0();
  cVar1 = (**(code **)(*piVar2 + 0x20))(param_1,*(undefined4 *)(in_ECX + 0x20));
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5a7dc + 8))();
  }
  return;
}


// ==== FUN_00444470 @ 0x00444470 ====

void FUN_00444470(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)FUN_00447bd0();
  cVar1 = (**(code **)(*piVar2 + 0x24))(*(undefined4 *)(in_ECX + 0x20));
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5a7dc + 8))();
  }
  return;
}


// ==== FUN_004444a0 @ 0x004444a0 ====

void FUN_004444a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00444350();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00444510 @ 0x00444510 ====

void FUN_00444510(void)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  int *_Memory;
  int *piVar3;
  undefined4 uStack_8;
  int iStack_4;
  
  _Memory = (int *)**(int **)(*(int *)(in_ECX + 0xc) + 4);
  uVar1 = FUN_00424830();
  if (_Memory != *(int **)(*(int *)(in_ECX + 0xc) + 4)) {
    do {
      piVar3 = _Memory;
      if (_Memory[3] + 7000U < uVar1) {
        pvVar2 = operator_new(0x400);
        *(undefined4 *)((int)pvVar2 + 8) = 0;
        *(undefined4 *)((int)pvVar2 + 0xc) = 0x10004;
        *(undefined2 *)((int)pvVar2 + 6) = 0x18;
        iStack_4 = FUN_004244d0();
        *(int *)(iStack_4 + 0x10) = _Memory[4];
        *(short *)(iStack_4 + 0x14) = (short)_Memory[5];
        *(undefined1 *)(iStack_4 + 0x16) = 0;
        uStack_8 = 0;
        (**(code **)(*DAT_00b5a68c + 0x10))(&uStack_8);
        FUN_00445850(_Memory[2]);
        piVar3 = (int *)*_Memory;
        if (_Memory != *(int **)(*(int *)(in_ECX + 0xc) + 4)) {
          *(int **)_Memory[1] = piVar3;
          *(int *)(*_Memory + 4) = _Memory[1];
          _free(_Memory);
          return;
        }
      }
      _Memory = (int *)*piVar3;
    } while (_Memory != *(int **)(*(int *)(in_ECX + 0xc) + 4));
  }
  return;
}


// ==== FUN_004445f0 @ 0x004445f0 ====

void FUN_004445f0(short param_1,int param_2)

{
  int *piVar1;
  void *pvVar2;
  int in_ECX;
  int *_Memory;
  undefined4 local_8;
  int local_4;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0xc) + 4);
  _Memory = (int *)*piVar1;
  if (_Memory != piVar1) {
    while (_Memory[2] != param_2) {
      _Memory = (int *)*_Memory;
      if (_Memory == piVar1) {
        return;
      }
    }
    if (param_1 == 0) {
      FUN_00444da0();
    }
    else {
      FUN_00445850(param_2);
      pvVar2 = operator_new(0x400);
      *(undefined4 *)((int)pvVar2 + 8) = 0;
      *(undefined4 *)((int)pvVar2 + 0xc) = 0x10004;
      *(undefined2 *)((int)pvVar2 + 6) = 0x18;
      local_4 = FUN_004244d0();
      *(int *)(local_4 + 0x10) = _Memory[4];
      *(short *)(local_4 + 0x14) = (short)_Memory[5];
      *(undefined1 *)(local_4 + 0x16) = 0;
      local_8 = 0;
      (**(code **)(*DAT_00b5a68c + 0x10))(&local_8);
    }
    if (_Memory != *(int **)(*(int *)(in_ECX + 0xc) + 4)) {
      *(int *)_Memory[1] = *_Memory;
      *(int *)(*_Memory + 4) = _Memory[1];
      _free(_Memory);
      return;
    }
  }
  return;
}


// ==== FUN_004446c0 @ 0x004446c0 ====

void FUN_004446c0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  int *piVar1;
  
  *in_ECX = &PTR_FUN_0099e978;
  piVar1 = (int *)**(int **)(in_ECX[3] + 4);
  if (piVar1 != *(int **)(in_ECX[3] + 4)) {
    do {
      FUN_00445850(piVar1[2]);
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(in_ECX[3] + 4));
  }
  _Memory = (void *)in_ECX[3];
  if (_Memory == (void *)0x0) {
    in_ECX[3] = 0;
    return;
  }
  FUN_008984a0();
  _free(_Memory);
  return;
}


// ==== FUN_00444710 @ 0x00444710 ====

void FUN_00444710(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int in_ECX;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined2 local_10;
  undefined2 uStack_e;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 0;
  local_c = *param_1;
  _local_10 = CONCAT22(CONCAT11((char)*(undefined2 *)(param_1 + 1),
                                (char)((ushort)*(undefined2 *)(param_1 + 1) >> 8)),2);
  uStack_34 = 0x444753;
  uVar1 = FUN_00445820();
  uStack_34 = 0;
  iStack_38 = 0;
  uStack_3c = 0;
  iVar2 = WSAConnect(uVar1,&local_10,0x10,0);
  if (iVar2 != -1) {
    FUN_00444da0(uVar1);
    return;
  }
  iVar2 = WSAGetLastError();
  if (iVar2 == 0x2733) {
    uStack_3c = uVar1;
    iStack_38 = FUN_00424830();
    uStack_34 = *param_1;
    iVar2 = *(int *)(*(int *)(in_ECX + 0xc) + 4);
    iVar4 = FUN_00444910(iVar2,*(undefined4 *)(iVar2 + 4),&uStack_3c);
    FUN_00444970(1);
    *(int *)(iVar2 + 4) = iVar4;
    **(int **)(iVar4 + 4) = iVar4;
    return;
  }
  FUN_00445850(uVar1);
  pvVar3 = operator_new(0x400);
  *(undefined4 *)((int)pvVar3 + 8) = 0;
  *(undefined4 *)((int)pvVar3 + 0xc) = 0x10004;
  *(undefined2 *)((int)pvVar3 + 6) = 0x18;
  iStack_38 = FUN_004244d0();
  *(undefined4 *)(iStack_38 + 0x10) = *param_1;
  *(undefined2 *)(iStack_38 + 0x14) = *(undefined2 *)(param_1 + 1);
  *(undefined1 *)(iStack_38 + 0x16) = 0;
  uStack_3c = 0;
  (**(code **)(*DAT_00b5a68c + 0x10))(&uStack_3c);
  return;
}


// ==== FUN_00444840 @ 0x00444840 ====

void FUN_00444840(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b49b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099e978;
  in_ECX[1] = param_1;
  in_ECX[2] = param_2;
  pvVar1 = operator_new(0xc);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    in_ECX[3] = 0;
    ExceptionList = local_c;
    return;
  }
  local_18 = 0;
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  local_1c = 0;
  local_14 = 0;
  local_10 = 0;
  uVar2 = FUN_004448f0();
  *(undefined4 *)((int)pvVar1 + 4) = uVar2;
  FUN_00444ac0(0,&local_1c);
  in_ECX[3] = pvVar1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004448f0 @ 0x004448f0 ====

void FUN_004448f0(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x18);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  return;
}


// ==== FUN_00444910 @ 0x00444910 ====

void FUN_00444910(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = *param_3;
    puVar1[3] = param_3[1];
    puVar1[4] = param_3[2];
    puVar1[5] = param_3[3];
  }
  return;
}


// ==== __break @ 0x0044494f ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00444950 @ 0x00444950 ====

void FUN_00444950(byte param_1)

{
  void *in_ECX;
  
  FUN_004446c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00444970 @ 0x00444970 ====

void FUN_00444970(uint param_1)

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
  puStack_8 = &LAB_0097b458;
  local_c = ExceptionList;
  if (0xfffffffU - *(int *)(in_ECX + 8) < param_1) {
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


// ==== FUN_00444a10 @ 0x00444a10 ====

void FUN_00444a10(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0097b470;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    iVar1 = FUN_00444910(param_1,*(undefined4 *)(param_1 + 4),param_3);
    FUN_00444970(1);
    *(int *)(param_1 + 4) = iVar1;
    **(int **)(iVar1 + 4) = iVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00444a75 @ 0x00444a75 ====

void Catch_00444a75(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  
  if (*(uint *)(unaff_EBP + 0xc) < *(uint *)(unaff_EBP + -0x18)) {
    iVar1 = *(int *)(unaff_EBP + 8);
    iVar2 = *(uint *)(unaff_EBP + -0x18) - *(uint *)(unaff_EBP + 0xc);
    do {
      FUN_005171c0(unaff_EBP + 0xc,*(undefined4 *)(iVar1 + 4));
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00444ac0 @ 0x00444ac0 ====

void FUN_00444ac0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0097b480;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_00444a10(**(undefined4 **)(in_ECX + 4),param_1,param_2);
  ExceptionList = local_10;
  return;
}


// ==== Catch@00444b11 @ 0x00444b11 ====

void Catch_00444b11(void)

{
  FUN_008984a0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00444b30 @ 0x00444b30 ====

void FUN_00444b30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e98c;
  return;
}


// ==== FUN_00444b50 @ 0x00444b50 ====

void FUN_00444b50(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_20 [2];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20[0] = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_WSASend_0099e980,7);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  puVar2 = param_2;
  iVar1 = WSASend(param_1,param_2,1,local_20,0,0,0);
  if (iVar1 == -1) {
    *param_2 = 0;
    return;
  }
  *param_2 = puVar2;
  return;
}


// ==== FUN_00444bd0 @ 0x00444bd0 ====

void FUN_00444bd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e98c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00444bf0 @ 0x00444bf0 ====

void FUN_00444bf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e9a0;
  return;
}


// ==== FUN_00444c10 @ 0x00444c10 ====

uint FUN_00444c10(undefined4 param_1,undefined4 *param_2)

{
  uint extraout_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined4 local_24;
  undefined4 local_20 [2];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_24 = 0;
  local_20[0] = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_WSARecv_0099e994,7);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  uVar2 = 1;
  iVar1 = WSARecv(param_1,param_2,1,&local_24,local_20,0,0);
  if (iVar1 == -1) {
    *param_2 = 0;
    iVar1 = WSAGetLastError();
    return (uint)(iVar1 == 0x2733);
  }
  *param_2 = uVar2;
  return 1;
}


// ==== FUN_00444ca0 @ 0x00444ca0 ====

void FUN_00444ca0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e9a0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00444d00 @ 0x00444d00 ====

void FUN_00444d00(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(0xc);
  *(undefined4 **)(in_ECX + 4) = puVar1;
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  puVar1[2] = param_1[2];
  return;
}


// ==== FUN_00444d30 @ 0x00444d30 ====

void FUN_00444d30(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  
  sVar1 = (short)param_2;
  if (sVar1 == 0x10) {
    FUN_004445f0();
    return;
  }
  if ((sVar1 == 0x20) || ((short)((uint)param_2 >> 0x10) != 0)) {
    FUN_00444fb0();
    return;
  }
  if (sVar1 == 2) {
    FUN_00444f60(param_1);
    return;
  }
  FUN_00444f10(param_1);
  return;
}


// ==== FUN_00444da0 @ 0x00444da0 ====

void FUN_00444da0(void)

{
  FUN_00445000();
  return;
}


// ==== FUN_00444db0 @ 0x00444db0 ====

void FUN_00444db0(undefined4 param_1)

{
  FUN_00444fb0(1,param_1);
  FUN_00445850(param_1);
  return;
}


// ==== FUN_00444de0 @ 0x00444de0 ====

void FUN_00444de0(char *param_1,SOCKET param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_1c [2];
  uint local_14;
  sockaddr local_10;
  
  local_10.sa_family = 0;
  local_10.sa_data[0] = '\0';
  local_10.sa_data[1] = '\0';
  local_10.sa_data[2] = '\0';
  local_10.sa_data[3] = '\0';
  local_10.sa_data[4] = '\0';
  local_10.sa_data[5] = '\0';
  local_10.sa_data[6] = '\0';
  local_10.sa_data[7] = '\0';
  local_10.sa_data[8] = '\0';
  local_10.sa_data[9] = '\0';
  local_10.sa_data[10] = '\0';
  local_10.sa_data[0xb] = '\0';
  local_10.sa_data[0xc] = '\0';
  local_10.sa_data[0xd] = '\0';
  uVar2._0_1_ = '\0';
  uVar2._1_1_ = '\0';
  uVar2._2_1_ = '\0';
  uVar2._3_1_ = '\0';
  local_1c[0] = 0x10;
  local_14 = local_14 & 0xffff0000;
  iVar1 = getpeername(param_2,&local_10,local_1c);
  if (iVar1 != -1) {
    local_14 = CONCAT22(local_14._2_2_,CONCAT11(local_10.sa_data[0],local_10.sa_data[1]));
    uVar2 = local_10.sa_data._2_4_;
  }
  *(undefined4 *)param_1 = uVar2;
  *(uint *)(param_1 + 4) = local_14;
  return;
}


// ==== FUN_00444e50 @ 0x00444e50 ====

void FUN_00444e50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e9a8;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00444e60 @ 0x00444e60 ====

void FUN_00444e60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e9a8;
  _free((void *)in_ECX[1]);
  return;
}


// ==== FUN_00444e80 @ 0x00444e80 ====

undefined4 FUN_00444e80(int *param_1)

{
  if (*param_1 == 0x113) {
    FUN_00444510();
  }
  else if (*param_1 == 0x926) {
    FUN_00444d30(param_1[1],param_1[2]);
    return 1;
  }
  return 0;
}


// ==== FUN_00444ec0 @ 0x00444ec0 ====

void FUN_00444ec0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e9a8;
  _free((void *)in_ECX[1]);
  return;
}


// ==== FUN_00444f10 @ 0x00444f10 ====

void FUN_00444f10(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0079bba0(&local_c,&param_1);
  if (local_c != *(int *)(iVar1 + 4)) {
    local_8 = *(undefined4 *)(in_ECX + 4);
    local_4 = param_1;
    (**(code **)(**(int **)(local_c + 0x10) + 0x20))(&local_8);
  }
  return;
}


// ==== FUN_00444f60 @ 0x00444f60 ====

void FUN_00444f60(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0079bba0(&local_c,&param_1);
  if (local_c != *(int *)(iVar1 + 4)) {
    local_8 = *(undefined4 *)(in_ECX + 4);
    local_4 = param_1;
    (**(code **)(**(int **)(local_c + 0x10) + 0x1c))(&local_8);
  }
  return;
}


// ==== FUN_00444fb0 @ 0x00444fb0 ====

void FUN_00444fb0(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  int local_4;
  
  iVar1 = *(int *)(in_ECX + 8);
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_2);
  if (local_4 != *(int *)(iVar1 + 4)) {
    piVar2 = *(int **)(local_4 + 0x10);
    FUN_00445170(&param_2,local_4);
    if ((char)local_4 == '\0') {
      (**(code **)(*piVar2 + 8))(0);
    }
  }
  return;
}


// ==== FUN_00445000 @ 0x00445000 ====

void FUN_00445000(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 uStack_18;
  int *piStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 auStack_8 [8];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a7dc + 4))();
  uStack_18 = param_1;
  piStack_14 = piVar1;
  FUN_004456c0(auStack_8,&uStack_18);
  uStack_10 = *(undefined4 *)(in_ECX + 4);
  uStack_c = param_1;
  (**(code **)(*piVar1 + 4))(&uStack_10);
  return;
}


// ==== FUN_00445060 @ 0x00445060 ====

void FUN_00445060(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b4db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099e9b0;
  in_ECX[1] = param_1;
  pvVar1 = operator_new(0xc);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    in_ECX[2] = 0;
    ExceptionList = local_c;
    return;
  }
  iVar2 = FUN_0058d7c0();
  *(int *)((int)pvVar1 + 4) = iVar2;
  *(undefined1 *)(iVar2 + 0x15) = 1;
  *(int *)(*(int *)((int)pvVar1 + 4) + 4) = *(int *)((int)pvVar1 + 4);
  *(undefined4 *)*(undefined4 *)((int)pvVar1 + 4) = *(undefined4 *)((int)pvVar1 + 4);
  *(int *)(*(int *)((int)pvVar1 + 4) + 8) = *(int *)((int)pvVar1 + 4);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  in_ECX[2] = pvVar1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00445100 @ 0x00445100 ====

void FUN_00445100(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[2];
  *in_ECX = &PTR_FUN_0099e9b0;
  if (_Memory == (void *)0x0) {
    in_ECX[2] = 0;
    return;
  }
  FUN_00445780();
  _free(_Memory);
  return;
}


// ==== FUN_00445130 @ 0x00445130 ====

void FUN_00445130(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00445130(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00445170 @ 0x00445170 ====

/* WARNING: Removing unreachable block (ram,0x00445283) */
/* WARNING: Removing unreachable block (ram,0x00445293) */
/* WARNING: Removing unreachable block (ram,0x0044529c) */
/* WARNING: Removing unreachable block (ram,0x0044529f) */
/* WARNING: Removing unreachable block (ram,0x0044528f) */
/* WARNING: Removing unreachable block (ram,0x004452ad) */
/* WARNING: Removing unreachable block (ram,0x004452ba) */
/* WARNING: Removing unreachable block (ram,0x004452c5) */
/* WARNING: Removing unreachable block (ram,0x004452c1) */
/* WARNING: Removing unreachable block (ram,0x004452b5) */
/* WARNING: Removing unreachable block (ram,0x004452c8) */

void FUN_00445170(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097b4b8;
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
            goto LAB_00445395;
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
LAB_00445395:
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


// ==== FUN_00445420 @ 0x00445420 ====

void FUN_00445420(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097b4b8;
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
LAB_00445519:
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
      if ((char)piVar6[5] == '\0') goto LAB_00445519;
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


// ==== FUN_00445600 @ 0x00445600 ====

void FUN_00445600(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00445130(piVar6[1]);
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
    FUN_00445170(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004456c0 @ 0x004456c0 ====

void FUN_004456c0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00445420(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00445420(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00445780 @ 0x00445780 ====

void FUN_00445780(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00445600(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004457b0 @ 0x004457b0 ====

void FUN_004457b0(byte param_1)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[2];
  *in_ECX = &PTR_FUN_0099e9b0;
  if (_Memory != (void *)0x0) {
    FUN_00445780();
    _free(_Memory);
    return;
  }
  in_ECX[2] = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004457f0 @ 0x004457f0 ====

void FUN_004457f0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e9c8;
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00445820 @ 0x00445820 ====

SOCKET FUN_00445820(void)

{
  SOCKET s;
  int in_ECX;
  
  s = socket(2,1,0);
  WSAAsyncSelect(s,*(HWND *)(in_ECX + 8),0x926,0x33);
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  return s;
}


// ==== FUN_00445850 @ 0x00445850 ====

/* WARNING: Removing unreachable block (ram,0x00445880) */

void FUN_00445850(SOCKET param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + -1;
  FUN_00401740(s_closesocket_0099e9b8,0xb);
  closesocket(param_1);
  return;
}


// ==== FUN_004458a0 @ 0x004458a0 ====

void FUN_004458a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099e9c8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004458c0 @ 0x004458c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004458c0(float *param_1,undefined4 param_2,int param_3,int param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
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
  puStack_8 = &LAB_0097b500;
  local_c = ExceptionList;
  switch(param_2) {
  case 1:
    fVar7 = (float)param_4;
    fVar4 = 0.0;
    if (param_4 < 0) {
      fVar7 = fVar7 + _DAT_0099d104;
    }
    fVar5 = DAT_0099d0dc;
    fVar6 = DAT_0099d080;
    break;
  case 2:
    fVar7 = (float)param_3;
    fVar5 = 0.0;
    if (param_3 < 0) {
      fVar7 = fVar7 + _DAT_0099d104;
    }
    fVar8 = (float)param_4;
    fVar6 = 0.0;
    if (param_4 < 0) {
      fVar8 = fVar8 + _DAT_0099d104;
    }
    fVar4 = DAT_0099d0dc;
    goto LAB_00445a40;
  case 3:
    fVar8 = (float)param_3;
    fVar7 = 0.0;
    if (param_3 < 0) {
      fVar8 = fVar8 + _DAT_0099d104;
    }
    fVar5 = DAT_0099d080;
    fVar6 = DAT_0099d0dc;
    fVar4 = 0.0;
    goto LAB_00445a40;
  default:
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(s_____data_Helper_cpp_108__0099ea1c,0x19);
    local_4 = 0;
    uVar3 = FUN_004022a0(local_28,s_Invalid_Rotation_0099ea38,local_44);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_00796d50(uVar3);
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    local_10 = 0xf;
    if (0xf < local_2c) {
      _free(local_40);
      return;
    }
  case 0:
    fVar7 = 0.0;
    fVar4 = DAT_0099d080;
    fVar5 = 0.0;
    fVar6 = 0.0;
  }
  fVar8 = 0.0;
LAB_00445a40:
  fVar1 = param_5[1];
  fVar2 = *param_5;
  param_1[1] = param_5[1] * fVar4 + *param_5 * fVar6 + fVar8;
  *param_1 = fVar1 * fVar5 + fVar2 * fVar4 + fVar7;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00445ab0 @ 0x00445ab0 ====

void FUN_00445ab0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64 [4];
  undefined1 local_54 [16];
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  void *pvStack_18;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined4 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = (undefined4 *)&LAB_0097b51a;
  pvStack_c = ExceptionList;
  local_70 = 0;
  local_6c = DAT_0099d0dc;
  local_68 = 0;
  fVar2 = 0.0;
  ExceptionList = &pvStack_c;
  switch(param_2) {
  case 0:
    break;
  case 1:
    fVar2 = DAT_00adc6c8;
    ExceptionList = &pvStack_c;
    break;
  case 2:
    fVar2 = DAT_0099eaac;
    ExceptionList = &pvStack_c;
    break;
  case 3:
    fVar2 = DAT_00adc6c8 + DAT_0099eaac;
    ExceptionList = &pvStack_c;
    break;
  default:
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    ExceptionList = &pvStack_c;
    FUN_00401740(s_____data_Helper_cpp_152__0099ea4c,0x19);
    local_4 = 0;
    uVar1 = FUN_004022a0(local_28,s_Invalid_Rotation___0099ea68,local_44);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_00796d50(uVar1);
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    local_10 = 0xf;
    if (0xf < local_2c) {
      _free(local_40);
      return;
    }
    fVar2 = 0.0;
  }
  thunk_FUN_007a095f(local_54,&local_70,fVar2);
  thunk_FUN_007a0af7(local_64,param_3,local_54);
  *puStack_8 = local_70;
  puStack_8[1] = local_6c;
  puStack_8[2] = local_68;
  puStack_8[3] = local_64[0];
  ExceptionList = pvStack_18;
  return;
}


// ==== FUN_00445c20 @ 0x00445c20 ====

void FUN_00445c20(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int *param_6,
                 int *param_7)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
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
  puStack_8 = &LAB_0097b534;
  local_c = ExceptionList;
  switch(param_1) {
  case 0:
    goto LAB_00445d28;
  case 1:
    param_2 = 0;
    iVar2 = 0;
    iVar3 = -1;
    iVar6 = param_3 + -1;
    iVar4 = 1;
    iVar5 = 0;
    break;
  case 2:
    iVar2 = -1;
    iVar3 = 0;
    iVar6 = param_2 + -1;
    iVar4 = 0;
    iVar5 = -1;
    param_2 = param_3 + -1;
    break;
  case 3:
    iVar2 = 0;
    iVar6 = 0;
    iVar4 = -1;
    iVar5 = 0;
    iVar3 = 1;
    param_2 = param_2 + -1;
    break;
  default:
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(s_____data_Helper_cpp_210__0099ea7c,0x19);
    local_4 = 0;
    uVar1 = FUN_004022a0(local_28,s_Invalid_Rotation_0099ea98,local_44);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_00796d50(uVar1);
    if (0xf < local_10) {
      _free(local_24);
      return;
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    if (0xf < local_2c) {
      _free(local_40);
      return;
    }
LAB_00445d28:
    param_2 = 0;
    iVar2 = 1;
    iVar6 = 0;
    iVar3 = 0;
    iVar4 = 0;
    iVar5 = 1;
  }
  *param_6 = iVar3 * param_5 + iVar2 * param_4 + iVar6;
  *param_7 = iVar5 * param_5 + iVar4 * param_4 + param_2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00445d80 @ 0x00445d80 ====

void FUN_00445d80(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  
  iVar3 = param_2 * param_3;
  FUN_004271c0(iVar3);
  if (iVar3 != 0) {
    do {
      param_2 = _rand();
      iVar1 = *(int *)(param_1 + 0x6c);
      param_2 = param_2 & 3;
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(param_1 + 0x74) - iVar1 >> 1) <=
          (uint)(*(int *)(param_1 + 0x70) - iVar1 >> 1))) {
        FUN_00427290(*(undefined4 *)(param_1 + 0x70),1,&param_2);
      }
      else {
        puVar2 = *(undefined2 **)(param_1 + 0x70);
        *puVar2 = (short)param_2;
        *(undefined2 **)(param_1 + 0x70) = puVar2 + 1;
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


// ==== FUN_00445e00 @ 0x00445e00 ====

void FUN_00445e00(int param_1)

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
  puStack_8 = &LAB_0097b54e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(param_1 + 0x14) = 2;
  FUN_00401740(s_maptile_braiken__0099e9e0,0x10);
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401740(s_maptex_first_dds_0099e9f4,0x10);
  local_4 = 0;
  FUN_00406720(local_44);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_maptex_second_dds_0099ea08,0x11);
  local_4 = 1;
  FUN_00406720(local_28);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00445ef0 @ 0x00445ef0 ====

int FUN_00445ef0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b560;
  local_c = ExceptionList;
  if (((((param_1 != 0x10) && (param_1 != 0x20)) && (param_1 != 0x40)) &&
      (((param_1 != 0x80 && (param_1 != 0x100)) && (param_1 != 0x200)))) ||
     (((param_2 != 0x10 && (param_2 != 0x20)) &&
      ((param_2 != 0x40 && (((param_2 != 0x80 && (param_2 != 0x100)) && (param_2 != 0x200)))))))) {
    ExceptionList = &local_c;
    FUN_00401830(s_map_size_error_0099e9d0);
    local_4 = 0;
    (**(code **)(*DAT_00b5a6c0 + 4))(1,local_28);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  ExceptionList = &local_c;
  iVar1 = FUN_00446700();
  FUN_0042b150();
  FUN_0042b1a0(0);
  *(int *)(iVar1 + 0xc) = param_1;
  *(int *)(iVar1 + 0x10) = param_2;
  FUN_00445e00(iVar1,param_3);
  iVar2 = (param_1 + 1) * (param_2 + 1);
  FUN_004465c0(iVar2,0);
  FUN_00446090(iVar2,0xffffffff);
  FUN_00446090(iVar2,0);
  FUN_00446650(iVar2,0,DAT_0099d080,0);
  FUN_00445d80(iVar1,param_1,param_2);
  FUN_00413bd0(*(undefined4 *)(*(int *)(iVar1 + 0x88) + 4));
  *(int *)(*(int *)(iVar1 + 0x88) + 4) = *(int *)(iVar1 + 0x88);
  *(undefined4 *)(iVar1 + 0x8c) = 0;
  *(undefined4 *)*(undefined4 *)(iVar1 + 0x88) = *(undefined4 *)(iVar1 + 0x88);
  *(int *)(*(int *)(iVar1 + 0x88) + 8) = *(int *)(iVar1 + 0x88);
  ExceptionList = local_c;
  return iVar1;
}


// ==== FUN_00446090 @ 0x00446090 ====

void FUN_00446090(uint param_1,undefined1 param_2)

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
    FUN_0042f3e0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if (((iVar2 != 0) && (pvVar3 = *(void **)(in_ECX + 8), param_1 < (uint)((int)pvVar3 - iVar2 >> 2))
      ) && (_Dst = (void *)(iVar2 + param_1 * 4), _Dst != pvVar3)) {
    pvVar3 = _memmove(_Dst,pvVar3,0);
    *(void **)(in_ECX + 8) = pvVar3;
  }
  return;
}


// ==== FUN_00446120 @ 0x00446120 ====

void FUN_00446120(void *param_1,uint param_2,undefined4 *param_3)

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
  
  param_3 = (undefined4 *)*param_3;
  iVar5 = *(int *)(in_ECX + 4);
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
      uVar7 = FUN_00412e70();
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


// ==== FUN_00446310 @ 0x00446310 ====

void FUN_00446310(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0097b570;
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
      FUN_00412e70();
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


// ==== Catch@004464c2 @ 0x004464c2 ====

void Catch_004464c2(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_004465c0 @ 0x004465c0 ====

void FUN_004465c0(uint param_1,undefined1 param_2)

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
    FUN_00446120(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if (((iVar2 != 0) && (pvVar3 = *(void **)(in_ECX + 8), param_1 < (uint)((int)pvVar3 - iVar2 >> 2))
      ) && (_Dst = (void *)(iVar2 + param_1 * 4), _Dst != pvVar3)) {
    pvVar3 = _memmove(_Dst,pvVar3,0);
    *(void **)(in_ECX + 8) = pvVar3;
  }
  return;
}


// ==== FUN_00446650 @ 0x00446650 ====

void FUN_00446650(uint param_1,undefined1 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
  }
  if (uVar2 < param_1) {
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    FUN_00446310(*(undefined4 *)(in_ECX + 8),param_1 - iVar3,&param_2);
    return;
  }
  if (((iVar3 != 0) && (iVar1 = *(int *)(in_ECX + 8), param_1 < (uint)((iVar1 - iVar3) / 0xc))) &&
     (iVar3 = iVar3 + param_1 * 0xc, iVar3 != iVar1)) {
    uVar4 = FUN_0042ea00(iVar1,iVar1,iVar3,param_1);
    *(undefined4 *)(in_ECX + 8) = uVar4;
  }
  return;
}


// ==== FUN_00446700 @ 0x00446700 ====

int FUN_00446700(void)

{
  code *pcVar1;
  void *pvVar2;
  int extraout_EAX;
  int iVar3;
  undefined1 local_28 [4];
  void *local_24;
  int local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b593;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(0xd8);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = FUN_00414ea0();
  }
  local_4 = 0xffffffff;
  if (local_14 != 0) {
    ExceptionList = local_c;
    return local_14;
  }
  local_10 = 0xf;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  local_4 = 1;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)(pvVar2);
    return iVar3;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_004467b0 @ 0x004467b0 ====

void FUN_004467b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eab4;
  return;
}


// ==== FUN_004467c0 @ 0x004467c0 ====

void FUN_004467c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eab4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004467e0 @ 0x004467e0 ====

int FUN_004467e0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_004467f0 @ 0x004467f0 ====

undefined1 FUN_004467f0(void)

{
  return 1;
}


// ==== FUN_00446800 @ 0x00446800 ====

undefined1 FUN_00446800(void)

{
  return 1;
}


// ==== FUN_00446810 @ 0x00446810 ====

undefined1 FUN_00446810(void)

{
  return 1;
}


// ==== FUN_00446820 @ 0x00446820 ====

int * FUN_00446820(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 8))();
  if (cVar1 == '\0') {
    return (int *)0x0;
  }
  piVar2 = (int *)FUN_0043fda0(param_1,in_ECX[8],in_ECX[9]);
  (**(code **)(*piVar2 + 0x18))((char)in_ECX[10]);
  return piVar2;
}


// ==== FUN_00446860 @ 0x00446860 ====

void FUN_00446860(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ead4;
  _free((void *)in_ECX[8]);
  return;
}


// ==== FUN_00446910 @ 0x00446910 ====

void FUN_00446910(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x28) = param_1;
  return;
}


// ==== FUN_00446920 @ 0x00446920 ====

void FUN_00446920(byte param_1)

{
  void *in_ECX;
  
  FUN_00446860();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00446950 @ 0x00446950 ====

undefined4 FUN_00446950(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}


// ==== FUN_00446960 @ 0x00446960 ====

undefined4 FUN_00446960(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x3c);
}


// ==== FUN_00446970 @ 0x00446970 ====

void FUN_00446970(void)

{
  int in_ECX;
  
  if (*(HANDLE *)(in_ECX + 0x24) != (HANDLE)0x0) {
    CancelIo(*(HANDLE *)(in_ECX + 0x24));
    CloseHandle(*(HANDLE *)(in_ECX + 0x24));
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    FUN_00401740(&DAT_0099eaf2,0);
  }
  return;
}


// ==== FUN_004469c0 @ 0x004469c0 ====

uint FUN_004469c0(int param_1)

{
  undefined4 uVar1;
  uint in_EAX;
  LPCSTR lpFileName;
  HANDLE hFile;
  DWORD DVar2;
  uint uVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x24) != 0) {
    return in_EAX & 0xffffff00;
  }
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    lpFileName = (LPCSTR)(param_1 + 4);
  }
  else {
    lpFileName = *(LPCSTR *)(param_1 + 4);
  }
  hFile = CreateFileA(lpFileName,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x60000080,(HANDLE)0x0);
  *(HANDLE *)(in_ECX + 0x24) = hFile;
  if (hFile == (HANDLE)0xffffffff) {
    *(undefined4 *)(in_ECX + 0x24) = 0;
    return 0xffffff00;
  }
  DVar2 = GetFileSize(hFile,(LPDWORD)0x0);
  *(DWORD *)(in_ECX + 0x28) = DVar2;
  if (DVar2 == 0xffffffff) {
    uVar3 = FUN_00446970();
    return uVar3 & 0xffffff00;
  }
  FUN_00401660(param_1,0,0xffffffff);
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = uVar1;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}


// ==== FUN_00446a50 @ 0x00446a50 ====

void FUN_00446a50(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  uVar2 = (**(code **)(*param_1 + 4))();
  FUN_00446f70(&param_1,uVar2);
  piVar1 = param_1;
  if (((param_1 != *(int **)(in_ECX + 0x38)) && (param_1[10] != 0)) &&
     (iVar3 = param_1[10] + -1, param_1[10] = iVar3, iVar3 == 0)) {
    if ((undefined4 *)param_1[0xb] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xb])(1);
    }
    piVar1[0xb] = 0;
    FUN_00447100(&param_1,piVar1);
  }
  return;
}


// ==== FUN_00446ab0 @ 0x00446ab0 ====

undefined4 FUN_00446ab0(uint param_1,int param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  void *local_80;
  undefined4 local_7c;
  int local_78 [11];
  undefined1 local_4c [32];
  undefined4 local_2c;
  void *local_28;
  uint local_24;
  void *local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b5fb;
  local_c = ExceptionList;
  if ((*(int *)(in_ECX + 0x24) == 0) || (*(int *)(in_ECX + 0x28) == 0)) {
    return 0;
  }
  local_78[0] = in_ECX + 0x34;
  ExceptionList = &local_c;
  FUN_00446f70(&local_80,param_3);
  if (local_80 != *(void **)(in_ECX + 0x38)) {
    *(int *)((int)local_80 + 0x28) = *(int *)((int)local_80 + 0x28) + 1;
    ExceptionList = local_c;
    return *(undefined4 *)((int)local_80 + 0x2c);
  }
  uVar5 = *(uint *)(in_ECX + 0x20);
  iVar6 = (param_1 / uVar5) * uVar5;
  uVar3 = param_1 + param_2;
  if (uVar3 % uVar5 != 0) {
    uVar3 = (uVar3 - uVar3 % uVar5) + uVar5;
  }
  iVar4 = uVar3 - iVar6;
  if (iVar4 == 0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar3 = *(int *)(in_ECX + 0x20) + iVar4;
  FUN_00447020();
  local_2c = *(undefined4 *)(in_ECX + 0x24);
  local_4 = 0;
  FUN_00401660(param_3,0,0xffffffff);
  local_28 = operator_new(uVar3);
  uVar5 = (uint)local_28 % *(uint *)(in_ECX + 0x20);
  if (uVar5 == 0) {
    local_20 = local_28;
  }
  else {
    local_20 = (void *)((*(uint *)(in_ECX + 0x20) - uVar5) + (int)local_28);
  }
  local_24 = uVar3;
  local_1c = iVar4;
  pvVar1 = operator_new(0x14);
  FUN_00403ea0(pvVar1,0,0x14);
  *(int *)((int)pvVar1 + 8) = iVar6;
  local_18 = (int)local_20 + (param_1 - iVar6);
  local_4c[0] = 0;
  local_14 = param_2;
  local_10 = pvVar1;
  local_80 = operator_new(0x48);
  local_4._0_1_ = 1;
  if (local_80 == (void *)0x0) {
    local_7c = 0;
  }
  else {
    local_7c = FUN_00449900();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00449de0(local_4c);
  local_80 = (void *)0x1;
  uVar2 = FUN_00446fe0(param_3,&local_80);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00447700(local_78,uVar2);
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00446cc0 @ 0x00446cc0 ====

void FUN_00446cc0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097b61b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099eaf8;
  local_4 = 1;
  if ((HANDLE)in_ECX[9] != (HANDLE)0x0) {
    CancelIo((HANDLE)in_ECX[9]);
    CloseHandle((HANDLE)in_ECX[9]);
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[8] = 0;
    FUN_00401740(&DAT_0099eaf2,0);
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00447640(local_10,*(undefined4 *)in_ECX[0xe],(undefined4 *)in_ECX[0xe]);
  _free((void *)in_ECX[0xe]);
  return;
}


// ==== FUN_00446d80 @ 0x00446d80 ====

void FUN_00446d80(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b630;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099eaf8;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_4 = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  iVar1 = FUN_00821b80();
  in_ECX[0xe] = iVar1;
  *(undefined1 *)(iVar1 + 0x31) = 1;
  *(undefined4 *)(in_ECX[0xe] + 4) = in_ECX[0xe];
  *(undefined4 *)in_ECX[0xe] = in_ECX[0xe];
  *(undefined4 *)(in_ECX[0xe] + 8) = in_ECX[0xe];
  in_ECX[0xf] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00446e00 @ 0x00446e00 ====

void FUN_00446e00(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x31);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x31);
  }
  return;
}


// ==== FUN_00446e20 @ 0x00446e20 ====

/* WARNING: Removing unreachable block (ram,0x00446e78) */

undefined4 * FUN_00446e20(int param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  undefined4 *local_8;
  
  local_8 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)local_8[1] + 0x31) == '\0') {
    uVar1 = *(uint *)(param_1 + 0x14);
    puVar5 = (undefined4 *)local_8[1];
    do {
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        pbVar8 = (byte *)(param_1 + 4);
      }
      else {
        pbVar8 = *(byte **)(param_1 + 4);
      }
      uVar2 = puVar5[8];
      if (uVar2 == 0) {
LAB_00446ea3:
        if (uVar1 <= uVar2) {
          bVar9 = false;
          goto LAB_00446eb0;
        }
LAB_00446eb2:
        puVar6 = (undefined4 *)puVar5[2];
      }
      else {
        uVar3 = uVar2;
        if (uVar1 <= uVar2) {
          uVar3 = uVar1;
        }
        if ((uint)puVar5[9] < 0x10) {
          pbVar7 = (byte *)(puVar5 + 4);
        }
        else {
          pbVar7 = (byte *)puVar5[4];
        }
        bVar9 = false;
        iVar4 = 0;
        bVar10 = true;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          bVar9 = *pbVar7 < *pbVar8;
          bVar10 = *pbVar7 == *pbVar8;
          pbVar7 = pbVar7 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar10);
        if (!bVar10) {
          iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        bVar9 = iVar4 < 0;
        if (iVar4 == 0) goto LAB_00446ea3;
LAB_00446eb0:
        if (bVar9) goto LAB_00446eb2;
        puVar6 = (undefined4 *)*puVar5;
        local_8 = puVar5;
      }
      puVar5 = puVar6;
    } while (*(char *)((int)puVar6 + 0x31) == '\0');
  }
  return local_8;
}


// ==== FUN_00446ee0 @ 0x00446ee0 ====

void FUN_00446ee0(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x1c) < 0x10) {
    *(undefined4 *)(in_ECX + 0x1c) = 0xf;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined1 *)(in_ECX + 8) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_00446f10 @ 0x00446f10 ====

void FUN_00446f10(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00446f40 @ 0x00446f40 ====

void FUN_00446f40(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x24) < 0x10) {
    *(undefined4 *)(in_ECX + 0x24) = 0xf;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_00446f70 @ 0x00446f70 ====

void FUN_00446f70(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_00446e20(param_2);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if (*(uint *)(iVar1 + 0x24) < 0x10) {
      iVar2 = iVar1 + 0x10;
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x10);
    }
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),iVar2,*(undefined4 *)(iVar1 + 0x20));
    if (-1 < iVar2) {
      *param_1 = iVar1;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_00446fe0 @ 0x00446fe0 ====

void FUN_00446fe0(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x1c) = *param_2;
  *(undefined4 *)(in_ECX + 0x20) = param_2[1];
  return;
}


// ==== FUN_00447020 @ 0x00447020 ====

void FUN_00447020(void)

{
  undefined1 *in_ECX;
  
  *in_ECX = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0xf;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  in_ECX[8] = 0;
  FUN_00401740(&DAT_0099cf70,0);
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  return;
}


// ==== FUN_00447060 @ 0x00447060 ====

void FUN_00447060(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_2;
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_4,0,0xffffffff);
  in_ECX[10] = *(undefined4 *)(param_4 + 0x1c);
  in_ECX[0xb] = *(undefined4 *)(param_4 + 0x20);
  *(undefined1 *)(in_ECX + 0xc) = param_5;
  *(undefined1 *)((int)in_ECX + 0x31) = 0;
  return;
}


// ==== FUN_004470c0 @ 0x004470c0 ====

void FUN_004470c0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x31) == '\0') {
    FUN_004470c0(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00447100 @ 0x00447100 ====

/* WARNING: Removing unreachable block (ram,0x00447210) */
/* WARNING: Removing unreachable block (ram,0x00447221) */
/* WARNING: Removing unreachable block (ram,0x0044722a) */
/* WARNING: Removing unreachable block (ram,0x0044722d) */
/* WARNING: Removing unreachable block (ram,0x0044721d) */
/* WARNING: Removing unreachable block (ram,0x0044723b) */
/* WARNING: Removing unreachable block (ram,0x00447248) */
/* WARNING: Removing unreachable block (ram,0x00447253) */
/* WARNING: Removing unreachable block (ram,0x0044724f) */
/* WARNING: Removing unreachable block (ram,0x00447243) */
/* WARNING: Removing unreachable block (ram,0x00447256) */

void FUN_00447100(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097b5a8;
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
            goto LAB_00447327;
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
LAB_00447327:
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


// ==== FUN_004473d0 @ 0x004473d0 ====

void * FUN_004473d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097b5d1;
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


// ==== Catch@00447442 @ 0x00447442 ====

void Catch_00447442(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00447460 @ 0x00447460 ====

void FUN_00447460(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097b5a8;
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
  piVar4 = (int *)FUN_004473d0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00447559:
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
      if ((char)piVar6[0xc] == '\0') goto LAB_00447559;
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


// ==== FUN_00447640 @ 0x00447640 ====

void FUN_00447640(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004470c0(piVar6[1]);
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
    FUN_00447100(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00447700 @ 0x00447700 ====

/* WARNING: Removing unreachable block (ram,0x0044775f) */

void FUN_00447700(undefined4 *param_1,undefined4 *param_2)

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
  if (*(char *)((int)puVar6[1] + 0x31) == '\0') {
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
LAB_00447790:
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
        if (uVar5 == 0) goto LAB_00447790;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x31) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_00447460(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_008840e0();
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
    puVar6 = (undefined4 *)FUN_00447460(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_00447870 @ 0x00447870 ====

void FUN_00447870(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00447640(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004478a0 @ 0x004478a0 ====

void FUN_004478a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00446cc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004478c0 @ 0x004478c0 ====

void FUN_004478c0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eb00;
  in_ECX[1] = param_1;
  pvVar1 = operator_new(8);
  in_ECX[3] = pvVar1;
  return;
}


// ==== FUN_004478f0 @ 0x004478f0 ====

void FUN_004478f0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_00447b80();
  uVar1 = FUN_004480e0();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  return;
}


// ==== FUN_00447910 @ 0x00447910 ====

void FUN_00447910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eb00;
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00447930 @ 0x00447930 ====

void FUN_00447930(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00447940 @ 0x00447940 ====

void FUN_00447940(void)

{
  int in_ECX;
  
  FUN_00447b80();
  FUN_004481e0();
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00447960 @ 0x00447960 ====

void FUN_00447960(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_ECX;
  
  iVar5 = *(int *)(in_ECX + 8);
  while( true ) {
    if (iVar5 == 0) {
      return;
    }
    puVar4 = (undefined4 *)FUN_00447bc0();
    uVar1 = (*(uint **)(in_ECX + 8))[1];
    uVar2 = **(uint **)(in_ECX + 8);
    uVar3 = puVar4[1];
    **(int **)(in_ECX + 0xc) = uVar2 - *(int *)(in_ECX + 0x10);
    *(uint *)(*(int *)(in_ECX + 0xc) + 4) = *(int *)(in_ECX + 0x10) + uVar1;
    (**(code **)(*(int *)*puVar4 + 8))(uVar3,*(undefined4 *)(in_ECX + 0xc));
    *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + **(int **)(in_ECX + 0xc);
    if (*(uint *)(in_ECX + 0x10) < uVar2) break;
    FUN_00447b80();
    FUN_004481e0();
    *(undefined4 *)(in_ECX + 8) = 0;
    FUN_00447b80();
    iVar5 = FUN_004480e0();
    *(int *)(in_ECX + 8) = iVar5;
    *(undefined4 *)(in_ECX + 0x10) = 0;
  }
  return;
}


// ==== FUN_004479f0 @ 0x004479f0 ====

void FUN_004479f0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    FUN_00447b80();
    FUN_004481e0();
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  puVar1 = (undefined4 *)FUN_00447bc0();
  (**(code **)(*(int *)*puVar1 + 0x10))(puVar1[1]);
  return;
}


// ==== FUN_00447a30 @ 0x00447a30 ====

void FUN_00447a30(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00447b80();
    uVar1 = FUN_004480e0();
    *(undefined4 *)(in_ECX + 8) = uVar1;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    FUN_00447960();
    return;
  }
  return;
}


// ==== FUN_00447a70 @ 0x00447a70 ====

void FUN_00447a70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eb00;
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00447ab0 @ 0x00447ab0 ====

void FUN_00447ab0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  
  puVar1 = operator_new(0x1c);
  *(undefined4 **)(in_ECX + 8) = puVar1;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    param_1 = param_1 + 1;
    puVar1 = puVar1 + 1;
  }
  *(undefined1 *)(in_ECX + 0x34) = 0;
  puVar1 = (undefined4 *)(in_ECX + 0x35);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  return;
}


// ==== FUN_00447af0 @ 0x00447af0 ====

void FUN_00447af0(undefined4 *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  **(undefined1 **)(in_ECX + 0xc) = 0xf;
  *(undefined1 *)(*(int *)(in_ECX + 0xc) + 1) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  uVar3 = FUN_00424830();
  *(undefined4 *)(in_ECX + 0x2c) = uVar3;
  cVar2 = (**(code **)(*(int *)**(undefined4 **)(in_ECX + 0x10) + 0x14))();
  if (cVar2 == '\x01') {
    *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(*(int *)(in_ECX + 8) + 0x18);
    return;
  }
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(*(int *)(in_ECX + 8) + 0x14);
  return;
}


// ==== FUN_00447b50 @ 0x00447b50 ====

void FUN_00447b50(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x34) = 0;
  return;
}


// ==== FUN_00447b60 @ 0x00447b60 ====

undefined4 FUN_00447b60(void)

{
  int in_ECX;
  
  return **(undefined4 **)(in_ECX + 8);
}


// ==== FUN_00447b70 @ 0x00447b70 ====

undefined4 FUN_00447b70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 8) + 0xc);
}


// ==== FUN_00447b80 @ 0x00447b80 ====

undefined4 FUN_00447b80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 8) + 0x10);
}


// ==== FUN_00447b90 @ 0x00447b90 ====

undefined4 FUN_00447b90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00447ba0 @ 0x00447ba0 ====

undefined4 FUN_00447ba0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 8) + 4);
}


// ==== FUN_00447bb0 @ 0x00447bb0 ====

undefined4 FUN_00447bb0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 8) + 8);
}


// ==== FUN_00447bc0 @ 0x00447bc0 ====

undefined4 FUN_00447bc0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00447bd0 @ 0x00447bd0 ====

undefined4 FUN_00447bd0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_00447be0 @ 0x00447be0 ====

void FUN_00447be0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = param_1;
  return;
}


// ==== FUN_00447bf0 @ 0x00447bf0 ====

undefined4 FUN_00447bf0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2c);
}


// ==== FUN_00447c00 @ 0x00447c00 ====

void FUN_00447c00(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c) = param_1;
  return;
}


// ==== FUN_00447c10 @ 0x00447c10 ====

int FUN_00447c10(void)

{
  int in_ECX;
  
  return in_ECX + 0x18;
}


// ==== FUN_00447c20 @ 0x00447c20 ====

void FUN_00447c20(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = *param_1;
  *(undefined4 *)(in_ECX + 0x1c) = param_1[1];
  *(undefined4 *)(in_ECX + 0x20) = param_1[2];
  *(undefined4 *)(in_ECX + 0x24) = param_1[3];
  return;
}


// ==== FUN_00447c40 @ 0x00447c40 ====

undefined4 FUN_00447c40(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}


// ==== FUN_00447c50 @ 0x00447c50 ====

void FUN_00447c50(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x28) = param_1;
  return;
}


// ==== FUN_00447c60 @ 0x00447c60 ====

undefined4 FUN_00447c60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}


// ==== FUN_00447c70 @ 0x00447c70 ====

void FUN_00447c70(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30) = param_1;
  return;
}


// ==== FUN_00447ca0 @ 0x00447ca0 ====

void FUN_00447ca0(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x35);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(in_ECX + 0x34) = 1;
  return;
}


// ==== FUN_00447cc0 @ 0x00447cc0 ====

undefined4 FUN_00447cc0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00447cd0 @ 0x00447cd0 ====

void FUN_00447cd0(undefined2 *param_1)

{
  int in_ECX;
  
  **(undefined2 **)(in_ECX + 0xc) = *param_1;
  return;
}


// ==== FUN_00447cf0 @ 0x00447cf0 ====

void FUN_00447cf0(void)

{
  void *pvVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eb08;
  in_ECX[2] = 0;
  in_ECX[5] = DAT_00b5a7e8;
  pvVar1 = operator_new(2);
  in_ECX[3] = pvVar1;
  pvVar1 = operator_new(8);
  in_ECX[4] = pvVar1;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  return;
}


// ==== FUN_00447d30 @ 0x00447d30 ====

void FUN_00447d30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eb08;
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00447d70 @ 0x00447d70 ====

void FUN_00447d70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eb08;
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00447dd0 @ 0x00447dd0 ====

void FUN_00447dd0(void)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_00447df0 @ 0x00447df0 ====

void FUN_00447df0(void)

{
  undefined4 *in_ECX;
  
  _free((void *)*in_ECX);
  return;
}


// ==== FUN_00447e10 @ 0x00447e10 ====

void FUN_00447e10(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int in_ECX;
  int *piVar5;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x14) + 4);
  piVar5 = (int *)*piVar1;
  if (piVar5 != piVar1) {
    do {
      if ((undefined4 *)piVar5[2] != (undefined4 *)0x0) {
        _free(*(void **)piVar5[2]);
        return;
      }
      piVar5[2] = 0;
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)*(int *)(*(int *)(in_ECX + 0x14) + 4));
  }
  piVar1 = *(int **)(*(int *)(in_ECX + 0x18) + 4);
  piVar5 = (int *)*piVar1;
  if (piVar5 != piVar1) {
    do {
      if ((undefined4 *)piVar5[2] != (undefined4 *)0x0) {
        _free(*(void **)piVar5[2]);
        return;
      }
      piVar5[2] = 0;
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)*(int *)(*(int *)(in_ECX + 0x18) + 4));
  }
  iVar2 = *(int *)(in_ECX + 0x14);
  puVar3 = *(undefined4 **)(iVar2 + 4);
  pvVar4 = (void *)*puVar3;
  *puVar3 = puVar3;
  *(int *)(*(int *)(iVar2 + 4) + 4) = *(int *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 8) = 0;
  if (pvVar4 != *(void **)(iVar2 + 4)) {
    _free(pvVar4);
    return;
  }
  iVar2 = *(int *)(in_ECX + 0x18);
  puVar3 = *(undefined4 **)(iVar2 + 4);
  pvVar4 = (void *)*puVar3;
  *puVar3 = puVar3;
  *(int *)(*(int *)(iVar2 + 4) + 4) = *(int *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 8) = 0;
  if (pvVar4 == *(void **)(iVar2 + 4)) {
    return;
  }
  _free(pvVar4);
  return;
}


// ==== FUN_00447ee0 @ 0x00447ee0 ====

void FUN_00447ee0(ushort param_1)

{
  int *piVar1;
  int in_ECX;
  int *_Memory;
  int iVar2;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x18) + 4);
  _Memory = (int *)*piVar1;
  do {
    if (_Memory == piVar1) {
      piVar1 = *(int **)(*(int *)(in_ECX + 0x14) + 4);
      _Memory = (int *)*piVar1;
      if (_Memory != piVar1) {
        while ((*(char *)(_Memory[2] + 4) == '\0' || (*(uint *)(_Memory[2] + 0xc) != (uint)param_1))
              ) {
          _Memory = (int *)*_Memory;
          if (_Memory == piVar1) {
            return;
          }
        }
        if ((undefined4 *)_Memory[2] != (undefined4 *)0x0) {
          _free(*(void **)_Memory[2]);
          return;
        }
        _Memory[2] = 0;
        iVar2 = *(int *)(in_ECX + 0x14);
LAB_00447f8f:
        if (_Memory != *(int **)(iVar2 + 4)) {
          *(int *)_Memory[1] = *_Memory;
          *(int *)(*_Memory + 4) = _Memory[1];
          _free(_Memory);
          return;
        }
      }
      return;
    }
    if ((*(char *)(_Memory[2] + 4) != '\0') && (*(uint *)(_Memory[2] + 0xc) == (uint)param_1)) {
      if ((undefined4 *)_Memory[2] != (undefined4 *)0x0) {
        _free(*(void **)_Memory[2]);
        return;
      }
      _Memory[2] = 0;
      iVar2 = *(int *)(in_ECX + 0x18);
      goto LAB_00447f8f;
    }
    _Memory = (int *)*_Memory;
  } while( true );
}


// ==== FUN_00447fc0 @ 0x00447fc0 ====

void FUN_00447fc0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b656;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099eb10;
  in_ECX[3] = 0;
  in_ECX[4] = param_1;
  pvVar1 = operator_new(8);
  in_ECX[2] = pvVar1;
  pvVar1 = operator_new(0xc);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    uVar2 = FUN_00415c90();
    *(undefined4 *)((int)pvVar1 + 4) = uVar2;
    *(undefined4 *)((int)pvVar1 + 8) = 0;
  }
  local_4 = 0xffffffff;
  in_ECX[5] = pvVar1;
  pvVar1 = operator_new(0xc);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    in_ECX[6] = 0;
  }
  else {
    uVar2 = FUN_00415c90();
    *(undefined4 *)((int)pvVar1 + 4) = uVar2;
    *(undefined4 *)((int)pvVar1 + 8) = 0;
    in_ECX[6] = pvVar1;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00448080 @ 0x00448080 ====

void FUN_00448080(void)

{
  void *pvVar1;
  undefined4 *in_ECX;
  
  pvVar1 = (void *)in_ECX[6];
  *in_ECX = &PTR_FUN_0099eb10;
  if (pvVar1 != (void *)0x0) {
    FUN_008984a0();
    _free(pvVar1);
    return;
  }
  pvVar1 = (void *)in_ECX[5];
  in_ECX[6] = 0;
  if (pvVar1 == (void *)0x0) {
    in_ECX[5] = 0;
    _free((void *)in_ECX[2]);
    return;
  }
  FUN_008984a0();
  _free(pvVar1);
  return;
}


// ==== FUN_004480e0 @ 0x004480e0 ====

undefined4 FUN_004480e0(void)

{
  int iVar1;
  int *_Memory;
  undefined4 extraout_EAX;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x14);
  if (*(int *)(iVar1 + 8) == 0) {
    return 0;
  }
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(**(int **)(iVar1 + 4) + 8);
  _Memory = (int *)**(int **)(iVar1 + 4);
  if (_Memory == *(int **)(iVar1 + 4)) {
    *(undefined4 *)(*(int *)(in_ECX + 8) + 4) = **(undefined4 **)(in_ECX + 0xc);
    **(undefined4 **)(in_ECX + 8) = *(undefined4 *)(*(int *)(in_ECX + 0xc) + 8);
    return *(undefined4 *)(in_ECX + 8);
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00448140 @ 0x00448140 ====

void FUN_00448140(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined2 extraout_var;
  undefined1 auStack_2 [2];
  
  piVar3 = operator_new(0x10);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *piVar3 = 0;
  }
  *piVar3 = param_1;
  piVar3[2] = (uint)*(ushort *)(param_1 + 6);
  piVar3[3] = (uint)*(ushort *)(in_ECX + 4);
  cVar2 = FUN_0044a050();
  *(char *)(piVar3 + 1) = cVar2;
  if (cVar2 == '\x01') {
    *(short *)(in_ECX + 4) = *(short *)(in_ECX + 4) + 1;
  }
  piVar3 = (int *)FUN_00447b90();
  (**(code **)(*piVar3 + 0xc))(CONCAT22(extraout_var,*(undefined2 *)(in_ECX + 4)),param_1);
  iVar1 = *(int *)(*(int *)(in_ECX + 0x14) + 4);
  iVar4 = FUN_00448300(iVar1,*(undefined4 *)(iVar1 + 4),auStack_2 + -10);
  FUN_00448350(1);
  *(int *)(iVar1 + 4) = iVar4;
  **(int **)(iVar4 + 4) = iVar4;
  return;
}


// ==== FUN_004481e0 @ 0x004481e0 ====

void FUN_004481e0(void)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  
  puVar3 = (undefined4 *)FUN_00447bc0();
  cVar2 = (**(code **)(*(int *)*puVar3 + 0x14))();
  if (cVar2 != '\0') {
    puVar3 = *(undefined4 **)(in_ECX + 0xc);
    if (*(char *)(puVar3 + 1) == '\0') {
      if (puVar3 != (undefined4 *)0x0) {
        _free((void *)*puVar3);
        return;
      }
    }
    else {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + 4);
      iVar4 = FUN_00448300(iVar1,*(undefined4 *)(iVar1 + 4),(undefined4 *)(in_ECX + 0xc));
      FUN_00448350(1);
      *(int *)(iVar1 + 4) = iVar4;
      **(int **)(iVar4 + 4) = iVar4;
    }
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  if (*(undefined4 **)(in_ECX + 0xc) == (undefined4 *)0x0) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free((void *)**(undefined4 **)(in_ECX + 0xc));
  return;
}


// ==== FUN_00448290 @ 0x00448290 ====

void FUN_00448290(void)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  int iStack_4;
  
  iStack_4 = in_ECX;
  puVar3 = (undefined4 *)FUN_00447bc0();
  cVar2 = (**(code **)(*(int *)*puVar3 + 0x14))();
  if (cVar2 != '\0') {
    iVar1 = *(int *)(in_ECX + 0x14);
    iVar4 = *(int *)(iVar1 + 8);
    while (iVar4 != 0) {
      iStack_4 = *(int *)(**(int **)(*(int *)(in_ECX + 0x18) + 4) + 8);
      iVar1 = *(int *)(iVar1 + 4);
      iVar4 = FUN_00448300(iVar1,*(undefined4 *)(iVar1 + 4),&iStack_4);
      FUN_00448350(1);
      *(int *)(iVar1 + 4) = iVar4;
      **(int **)(iVar4 + 4) = iVar4;
      iVar1 = *(int *)(in_ECX + 0x14);
      iVar4 = *(int *)(iVar1 + 8);
    }
    FUN_00510b80();
  }
  return;
}


// ==== FUN_00448300 @ 0x00448300 ====

void FUN_00448300(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = *param_3;
  }
  return;
}


// ==== FUN_00448330 @ 0x00448330 ====

void FUN_00448330(byte param_1)

{
  void *in_ECX;
  
  FUN_00448080();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00448350 @ 0x00448350 ====

void FUN_00448350(uint param_1)

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
  puStack_8 = &LAB_0097b668;
  local_c = ExceptionList;
  if (0x3fffffffU - *(int *)(in_ECX + 8) < param_1) {
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


// ==== FUN_004483f0 @ 0x004483f0 ====

void FUN_004483f0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eb18;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_00448420 @ 0x00448420 ====

void FUN_00448420(void)

{
  return;
}


// ==== FUN_00448430 @ 0x00448430 ====

void FUN_00448430(void)

{
  return;
}


// ==== FUN_00448450 @ 0x00448450 ====

void FUN_00448450(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eb18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00448470 @ 0x00448470 ====

char FUN_00448470(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  
  piVar2 = (int *)FUN_00447b90();
  piVar2 = (int *)(**(code **)(*piVar2 + 4))();
  do {
    if (piVar2 == (int *)0x0) {
      return '\0';
    }
    puVar3 = (undefined4 *)FUN_00447bc0();
    cVar1 = (**(code **)(*(int *)*puVar3 + 0xc))(puVar3[1],piVar2);
    piVar4 = (int *)FUN_00447b90();
    (**(code **)(*piVar4 + 8))();
    if ((cVar1 == '\0') || (*piVar2 == 0)) {
      return cVar1;
    }
    cVar1 = '\x01';
    do {
      piVar2 = (int *)FUN_00447b90();
      iVar5 = (**(code **)(*piVar2 + 0x10))();
      if (iVar5 == 0) break;
      FUN_00447b70(iVar5);
      cVar1 = FUN_004486f0(iVar5);
    } while (cVar1 == '\x01');
    if (cVar1 == '\0') {
      return '\0';
    }
    piVar2 = (int *)FUN_00447b90();
    piVar2 = (int *)(**(code **)(*piVar2 + 4))();
  } while( true );
}


// ==== FUN_00448560 @ 0x00448560 ====

void FUN_00448560(void)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_004485f0 @ 0x004485f0 ====

void FUN_004485f0(undefined2 param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x20005;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  iVar2 = FUN_004244d0();
  *(ushort *)(iVar2 + 0x10) = CONCAT11((char)param_1,(char)((ushort)param_1 >> 8));
  FUN_00447b80(iVar2);
  FUN_00448140(iVar2);
  FUN_00447ba0();
  FUN_00447a30();
  return;
}


// ==== FUN_00448650 @ 0x00448650 ====

void FUN_00448650(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 8) + 4);
  piVar2 = (int *)*piVar1;
  if (piVar2 == piVar1) {
    iVar3 = *(int *)(in_ECX + 8);
    FUN_00448a50(*(undefined4 *)(*(int *)(iVar3 + 4) + 4));
    *(int *)(*(int *)(iVar3 + 4) + 4) = *(int *)(iVar3 + 4);
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)*(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar3 + 4);
    *(int *)(*(int *)(iVar3 + 4) + 8) = *(int *)(iVar3 + 4);
    return;
  }
  _free((void *)piVar2[4]);
  return;
}


// ==== FUN_004486f0 @ 0x004486f0 ====

undefined4 FUN_004486f0(void *param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  int in_ECX;
  undefined2 extraout_var;
  void *_Memory;
  undefined2 uStack_1c;
  undefined1 auStack_1a [2];
  void *pvStack_18;
  void *pvStack_14;
  char cStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097b6a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  puVar7 = (undefined4 *)FUN_00447bc0();
  cVar6 = (**(code **)(*(int *)*puVar7 + 0x14))();
  if (cVar6 == '\0') {
    piVar8 = (int *)FUN_00447bd0();
    uVar9 = (**(code **)(*piVar8 + 0x28))(param_1);
    ExceptionList = pvStack_14;
    return uVar9;
  }
  cVar6 = FUN_0044a050();
  if (cVar6 == '\0') {
    piVar8 = (int *)FUN_00447bd0();
    uVar9 = (**(code **)(*piVar8 + 0x28))(param_1,*(undefined4 *)(in_ECX + 0xc));
    ExceptionList = pvStack_14;
    return uVar9;
  }
  FUN_004485f0(CONCAT22(extraout_var,*(undefined2 *)((int)param_1 + 4)));
  uStack_1c = *(undefined2 *)((int)param_1 + 4);
  pvStack_18 = param_1;
  FUN_00448cb0(&pvStack_14,&uStack_1c);
  if (cStack_10 == '\0') {
    _free(param_1);
    return extraout_EAX;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 8) == 0) {
    ExceptionList = pvStack_c;
    return 1;
  }
  iVar3 = **(int **)(*(int *)(in_ECX + 8) + 4);
  _Memory = *(void **)(iVar3 + 0x10);
  uStack_4 = 0;
  FUN_00448da0(&uStack_1c,iVar3);
  uVar1 = *(ushort *)((int)_Memory + 4);
  uVar2 = *(ushort *)(in_ECX + 4);
  if (uVar1 == uVar2) {
    bVar4 = false;
  }
  else if (uVar2 < uVar1) {
    bVar4 = 0x7ffe < (int)((uint)uVar1 - (uint)uVar2);
  }
  else {
    bVar4 = (int)((uint)uVar2 - (uint)uVar1) < 0x7fff;
  }
  if (uVar2 == uVar1) {
    bVar5 = false;
  }
  else if (uVar1 < uVar2) {
    bVar5 = 0x7ffe < (int)((uint)uVar2 - (uint)uVar1);
  }
  else {
    bVar5 = (int)((uint)uVar1 - (uint)uVar2) < 0x7fff;
  }
  if (!bVar4) {
    if (bVar5) {
      uStack_4 = 0;
      FUN_00448cb0(&uStack_1c,auStack_1a + -10);
      _free((void *)0x0);
      return extraout_EAX_01;
    }
    *(ushort *)(in_ECX + 4) = uVar2 + 1;
    piVar8 = (int *)FUN_00447bd0();
    uStack_4 = 0;
    cVar6 = (**(code **)(*piVar8 + 0x28))(_Memory,*(undefined4 *)(in_ECX + 0xc));
    _Memory = (void *)0x0;
    if (cVar6 == '\0') {
      _free((void *)0x0);
      return extraout_EAX_02;
    }
  }
  pvStack_c = (void *)0xffffffff;
  _free(_Memory);
  return extraout_EAX_00;
}


// ==== FUN_00448910 @ 0x00448910 ====

void FUN_00448910(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b6bd;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099eb20;
  in_ECX[3] = param_1;
  pvVar1 = operator_new(0xc);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    in_ECX[2] = 0;
    ExceptionList = local_c;
    return;
  }
  iVar2 = FUN_0058d7c0();
  *(int *)((int)pvVar1 + 4) = iVar2;
  *(undefined1 *)(iVar2 + 0x15) = 1;
  *(int *)(*(int *)((int)pvVar1 + 4) + 4) = *(int *)((int)pvVar1 + 4);
  *(undefined4 *)*(undefined4 *)((int)pvVar1 + 4) = *(undefined4 *)((int)pvVar1 + 4);
  *(int *)(*(int *)((int)pvVar1 + 4) + 8) = *(int *)((int)pvVar1 + 4);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  in_ECX[2] = pvVar1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004489b0 @ 0x004489b0 ====

void FUN_004489b0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[2];
  *in_ECX = &PTR_FUN_0099eb20;
  if (_Memory == (void *)0x0) {
    in_ECX[2] = 0;
    return;
  }
  FUN_00449110();
  _free(_Memory);
  return;
}


// ==== FUN_004489e0 @ 0x004489e0 ====

void FUN_004489e0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x15) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x15) == '\0');
  }
  return;
}


// ==== FUN_00448a00 @ 0x00448a00 ====

void FUN_00448a00(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x15) == '\0') {
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


// ==== FUN_00448a50 @ 0x00448a50 ====

void FUN_00448a50(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00448a50(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00448a90 @ 0x00448a90 ====

void FUN_00448a90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[2] = param_3;
    puVar1[1] = param_2;
    puVar1[3] = *param_4;
    puVar1[4] = param_4[1];
    *(undefined1 *)(puVar1 + 5) = param_5;
    *(undefined1 *)((int)puVar1 + 0x15) = 0;
  }
  return;
}


// ==== FUN_00448ad0 @ 0x00448ad0 ====

void FUN_00448ad0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097b688;
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
LAB_00448bc9:
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
      if ((char)piVar6[5] == '\0') goto LAB_00448bc9;
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


// ==== FUN_00448cb0 @ 0x00448cb0 ====

void FUN_00448cb0(undefined4 *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  bool bVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puVar6;
  
  puVar3 = param_2;
  puVar5 = *(undefined4 **)(in_ECX + 4);
  bVar4 = true;
  if (*(char *)((int)puVar5[1] + 0x15) == '\0') {
    uVar1 = *param_2;
    puVar6 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar6;
      uVar2 = *(ushort *)(puVar5 + 3);
      if (uVar1 == uVar2) {
        bVar4 = false;
      }
      else if (uVar2 < uVar1) {
        bVar4 = 0x7ffe < (int)((uint)uVar1 - (uint)uVar2);
      }
      else {
        bVar4 = (int)((uint)uVar2 - (uint)uVar1) < 0x7fff;
      }
      if (bVar4 == false) {
        puVar6 = (undefined4 *)puVar5[2];
      }
      else {
        puVar6 = (undefined4 *)*puVar5;
      }
    } while (*(char *)((int)puVar6 + 0x15) == '\0');
  }
  param_2 = (ushort *)puVar5;
  if (bVar4 != false) {
    if (puVar5 == (undefined4 *)**(int **)(in_ECX + 4)) {
      bVar4 = true;
      goto LAB_00448d2b;
    }
    FUN_0058d720();
  }
  uVar1 = *puVar3;
  uVar2 = *(ushort *)((int)param_2 + 0xc);
  if (uVar2 != uVar1) {
    if (uVar1 < uVar2) {
      if (0x7ffe < (int)((uint)uVar2 - (uint)uVar1)) goto LAB_00448d2b;
    }
    else if ((int)((uint)uVar1 - (uint)uVar2) < 0x7fff) {
LAB_00448d2b:
      puVar5 = (undefined4 *)FUN_00448ad0(&param_2,bVar4,puVar5,puVar3);
      *param_1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
  }
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_00448da0 @ 0x00448da0 ====

/* WARNING: Removing unreachable block (ram,0x00448eb3) */
/* WARNING: Removing unreachable block (ram,0x00448ec3) */
/* WARNING: Removing unreachable block (ram,0x00448ecc) */
/* WARNING: Removing unreachable block (ram,0x00448ecf) */
/* WARNING: Removing unreachable block (ram,0x00448ebf) */
/* WARNING: Removing unreachable block (ram,0x00448edd) */
/* WARNING: Removing unreachable block (ram,0x00448eea) */
/* WARNING: Removing unreachable block (ram,0x00448ef5) */
/* WARNING: Removing unreachable block (ram,0x00448ef1) */
/* WARNING: Removing unreachable block (ram,0x00448ee5) */
/* WARNING: Removing unreachable block (ram,0x00448ef8) */

void FUN_00448da0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_0097b688;
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
            goto LAB_00448fc5;
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
LAB_00448fc5:
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


// ==== FUN_00449050 @ 0x00449050 ====

void FUN_00449050(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00448a50(piVar6[1]);
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
    FUN_00448da0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00449110 @ 0x00449110 ====

void FUN_00449110(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00449050(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00449140 @ 0x00449140 ====

void FUN_00449140(byte param_1)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[2];
  *in_ECX = &PTR_FUN_0099eb20;
  if (_Memory != (void *)0x0) {
    FUN_00449110();
    _free(_Memory);
    return;
  }
  in_ECX[2] = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00449210 @ 0x00449210 ====

void FUN_00449210(void)

{
  void *pvVar1;
  int in_ECX;
  
  pvVar1 = operator_new(0x400);
  *(void **)(in_ECX + 0xc) = pvVar1;
  *(void **)(in_ECX + 0x10) = pvVar1;
  *(int *)(in_ECX + 0x14) = (int)pvVar1 + 0x400;
  *(undefined4 *)(in_ECX + 0x18) = 4;
  *(undefined4 *)(in_ECX + 0x1c) = 0xffffffff;
  return;
}


// ==== FUN_00449240 @ 0x00449240 ====

void FUN_00449240(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + **(int **)(in_ECX + 8);
  return;
}


// ==== FUN_00449250 @ 0x00449250 ====

void FUN_00449250(undefined4 param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  pbVar5 = (byte *)FUN_00447cc0();
  bVar1 = pbVar5[1];
  bVar2 = *pbVar5;
  uVar3 = *(ushort *)((int)param_2 + 6);
  uVar8 = 0xffffffff;
  FUN_00449f30(param_1);
  uVar6 = 4;
  if (4 < uVar3) {
    do {
      bVar4 = (&DAT_0099ec78)[(uVar6 & 0xff) * 4] ^ bVar1 ^ bVar2 ^ *(byte *)(uVar6 + (int)param_2);
      uVar7 = uVar6 + 1;
      *(byte *)(uVar6 + (int)param_2) = bVar4;
      uVar8 = uVar8 >> 8 ^ *(uint *)(&DAT_0099ec78 + ((bVar4 ^ uVar8) & 0xff) * 4);
      uVar6 = uVar7;
    } while (uVar7 < uVar3);
  }
  uVar8 = ~uVar8;
  *param_2 = CONCAT31((int3)uVar8,(char)(uVar8 >> 8)) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
             uVar8 >> 0x18;
  return;
}


// ==== FUN_004492e0 @ 0x004492e0 ====

void FUN_004492e0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b6d8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099eb48;
  in_ECX[1] = param_1;
  pvVar1 = operator_new(8);
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[2] = pvVar1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00449340 @ 0x00449340 ====

void FUN_00449340(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eb48;
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00449370 @ 0x00449370 ====

void FUN_00449370(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_00449390 @ 0x00449390 ====

undefined4 FUN_00449390(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) == *(int *)(in_ECX + 0x14)) {
    return 0;
  }
  *(undefined4 *)(*(int *)(in_ECX + 8) + 4) = *(undefined4 *)(in_ECX + 0x10);
  **(int **)(in_ECX + 8) = *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10);
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_004493c0 @ 0x004493c0 ====

uint * FUN_004493c0(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint *puVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  int in_ECX;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  
  iVar4 = *(int *)(in_ECX + 0xc);
  uVar9 = *(int *)(in_ECX + 0x10) - iVar4;
  if (0xf < uVar9) {
    pbVar6 = (byte *)FUN_00447cc0();
    bVar1 = pbVar6[1];
    bVar2 = *pbVar6;
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      do {
        uVar11 = *(uint *)(in_ECX + 0x18);
        bVar3 = *(byte *)(uVar11 + iVar4);
        *(uint *)(in_ECX + 0x1c) =
             *(uint *)(in_ECX + 0x1c) >> 8 ^
             *(uint *)(&DAT_0099ec78 + (((uint)bVar3 ^ *(uint *)(in_ECX + 0x1c)) & 0xff) * 4);
        *(byte *)(uVar11 + iVar4) = (&DAT_0099ec78)[(uVar11 & 0xff) * 4] ^ bVar3 ^ bVar1 ^ bVar2;
        *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
      } while (*(uint *)(in_ECX + 0x18) < 0x10);
      FUN_00449fc0();
    }
    uVar11 = (uint)*(ushort *)(*(int *)(in_ECX + 0xc) + 6);
    if ((uVar11 <= uVar9) && (uVar11 < 0x401)) {
      uVar8 = *(uint *)(in_ECX + 0x18);
      while (uVar8 < uVar11) {
        uVar8 = *(uint *)(in_ECX + 0x18);
        bVar3 = *(byte *)(uVar8 + iVar4);
        *(uint *)(in_ECX + 0x1c) =
             *(uint *)(in_ECX + 0x1c) >> 8 ^
             *(uint *)(&DAT_0099ec78 + (((uint)bVar3 ^ *(uint *)(in_ECX + 0x1c)) & 0xff) * 4);
        *(byte *)(uVar8 + iVar4) = (&DAT_0099ec78)[(uVar8 & 0xff) * 4] ^ bVar3 ^ bVar1 ^ bVar2;
        *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
        uVar8 = *(uint *)(in_ECX + 0x18);
      }
      puVar5 = *(uint **)(in_ECX + 0xc);
      if (~*(uint *)(in_ECX + 0x1c) == *puVar5) {
        puVar7 = operator_new(0x400);
        uVar9 = uVar9 - uVar11;
        *(undefined4 **)(in_ECX + 0x10) = puVar7;
        *(undefined4 **)(in_ECX + 0xc) = puVar7;
        *(undefined4 **)(in_ECX + 0x14) = puVar7 + 0x100;
        puVar10 = (undefined4 *)(iVar4 + uVar11);
        for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar7 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar7 = puVar7 + 1;
        }
        for (uVar11 = uVar9 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + uVar9;
        *(undefined4 *)(in_ECX + 0x18) = 4;
        *(undefined4 *)(in_ECX + 0x1c) = 0xffffffff;
        return puVar5;
      }
    }
  }
  return (uint *)0x0;
}


// ==== FUN_00449520 @ 0x00449520 ====

void FUN_00449520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eb28;
  return;
}


// ==== FUN_00449530 @ 0x00449530 ====

void FUN_00449530(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eb28;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00449550 @ 0x00449550 ====

void FUN_00449550(byte param_1)

{
  void *in_ECX;
  
  FUN_00449340();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00449620 @ 0x00449620 ====

void FUN_00449620(void)

{
  void *pvVar1;
  int in_ECX;
  
  pvVar1 = operator_new(0x400);
  *(void **)(in_ECX + 0xc) = pvVar1;
  return;
}


// ==== FUN_00449640 @ 0x00449640 ====

undefined4 FUN_00449640(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 8) + 4) = *(undefined4 *)(in_ECX + 0xc);
  **(undefined4 **)(in_ECX + 8) = 0x400;
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00449660 @ 0x00449660 ====

void FUN_00449660(void)

{
  return;
}


// ==== FUN_00449670 @ 0x00449670 ====

void FUN_00449670(undefined4 param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  pbVar5 = (byte *)FUN_00447cc0();
  bVar1 = pbVar5[1];
  bVar2 = *pbVar5;
  uVar3 = *(ushort *)((int)param_2 + 6);
  uVar8 = 0xffffffff;
  FUN_00449f30(param_1);
  uVar6 = 4;
  if (4 < uVar3) {
    do {
      bVar4 = (&DAT_0099ec78)[(uVar6 & 0xff) * 4] ^ bVar1 ^ bVar2 ^ *(byte *)(uVar6 + (int)param_2);
      uVar7 = uVar6 + 1;
      *(byte *)(uVar6 + (int)param_2) = bVar4;
      uVar8 = uVar8 >> 8 ^ *(uint *)(&DAT_0099ec78 + ((bVar4 ^ uVar8) & 0xff) * 4);
      uVar6 = uVar7;
    } while (uVar7 < uVar3);
  }
  uVar8 = ~uVar8;
  *param_2 = CONCAT31((int3)uVar8,(char)(uVar8 >> 8)) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
             uVar8 >> 0x18;
  return;
}


// ==== FUN_00449700 @ 0x00449700 ====

void FUN_00449700(undefined4 param_1)

{
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b6f8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099eb68;
  in_ECX[1] = param_1;
  pvVar1 = operator_new(8);
  in_ECX[2] = pvVar1;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00449760 @ 0x00449760 ====

void FUN_00449760(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099eb68;
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00449790 @ 0x00449790 ====

void FUN_00449790(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_004497b0 @ 0x004497b0 ====

uint * FUN_004497b0(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  byte *pbVar7;
  uint uVar8;
  void *pvVar9;
  int in_ECX;
  uint uVar10;
  
  uVar4 = **(uint **)(in_ECX + 8);
  if (uVar4 < 0x10) {
    return (uint *)0x0;
  }
  pbVar7 = (byte *)FUN_00447cc0();
  bVar1 = pbVar7[1];
  bVar2 = *pbVar7;
  iVar5 = *(int *)(in_ECX + 0xc);
  uVar8 = 4;
  uVar10 = 0xffffffff;
  if (4 < uVar4) {
    do {
      bVar3 = *(byte *)(uVar8 + iVar5);
      uVar10 = uVar10 >> 8 ^ *(uint *)(&DAT_0099ec78 + ((bVar3 ^ uVar10) & 0xff) * 4);
      *(byte *)(uVar8 + iVar5) = (&DAT_0099ec78)[(uVar8 & 0xff) * 4] ^ bVar3 ^ bVar1 ^ bVar2;
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar4);
  }
  FUN_00449fc0();
  puVar6 = *(uint **)(in_ECX + 0xc);
  uVar8 = *puVar6;
  if ((~uVar10 ==
       (CONCAT31((int3)uVar8,(char)(uVar8 >> 8)) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
       uVar8 >> 0x18)) && (uVar4 == *(ushort *)((int)puVar6 + 6))) {
    pvVar9 = operator_new(0x400);
    *(void **)(in_ECX + 0xc) = pvVar9;
    **(undefined4 **)(in_ECX + 8) = 0;
    return puVar6;
  }
  return (uint *)0x0;
}


// ==== FUN_00449880 @ 0x00449880 ====

void FUN_00449880(byte param_1)

{
  void *in_ECX;
  
  FUN_00449760();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004498a0 @ 0x004498a0 ====

int FUN_004498a0(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_004498c0 @ 0x004498c0 ====

int * FUN_004498c0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 8))();
  if (cVar1 == '\0') {
    return (int *)0x0;
  }
  piVar2 = (int *)FUN_0043fda0(param_1,in_ECX[0xf],in_ECX[0x10]);
  (**(code **)(*piVar2 + 0x18))(*(undefined1 *)((int)in_ECX + 5));
  return piVar2;
}


// ==== FUN_00449900 @ 0x00449900 ====

void FUN_00449900(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b718;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099ec54;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401740(&DAT_0099cf70,0);
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00449980 @ 0x00449980 ====

void FUN_00449980(void)

{
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b73d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099ec54;
  local_4 = 1;
  if (*(char *)(in_ECX + 2) != '\0') {
    _free((void *)in_ECX[0xb]);
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_0099eb88,0x31);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00796d50(local_28);
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[8] = 0;
    in_ECX[9] = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    *in_ECX = &PTR_FUN_0099eab4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_00449a50 @ 0x00449a50 ====

undefined1 FUN_00449a50(void)

{
  BOOL BVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_58 [16];
  undefined4 uStack_48;
  DWORD local_30;
  undefined1 *local_2c;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b74f;
  local_c = ExceptionList;
  if (*(char *)(in_ECX + 8) == '\x01') {
    return 1;
  }
  if (*(char *)(in_ECX + 4) == '\0') {
    return 0;
  }
  uStack_48 = 0x449ab0;
  ExceptionList = &local_c;
  BVar1 = GetOverlappedResult(*(HANDLE *)(in_ECX + 0x28),*(LPOVERLAPPED *)(in_ECX + 0x44),&local_30,
                              0);
  *(bool *)(in_ECX + 8) = BVar1 == 1;
  if ((BVar1 == 1) && (DAT_00b5a7f4 = DAT_00b5a7f4 + -1, DAT_00b5a7f4 != 0)) {
    local_2c = auStack_58;
    FUN_00401830(s_OverlappedIO_Complete__u__u_0099ebbc);
    uVar2 = FUN_00797530(local_28);
    local_4 = 0;
    FUN_00796d90(uVar2);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  ExceptionList = local_c;
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_00449b20 @ 0x00449b20 ====

uint FUN_00449b20(void)

{
  uint uVar1;
  BOOL BVar2;
  undefined4 uVar3;
  uint extraout_EAX;
  int *in_ECX;
  undefined1 auStack_60 [4];
  undefined1 uStack_5c;
  undefined4 uStack_50;
  DWORD DStack_30;
  undefined1 *puStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097b761;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar1 = (**(code **)(*in_ECX + 8))();
  if ((char)uVar1 == '\x01') {
    ExceptionList = pvStack_c;
    return uVar1;
  }
  DStack_30 = 0;
  if ((char)in_ECX[2] == '\0') {
    do {
      uStack_50 = 0x449b81;
      BVar2 = GetOverlappedResult((HANDLE)in_ECX[10],(LPOVERLAPPED)in_ECX[0x11],&DStack_30,1);
      *(bool *)(in_ECX + 2) = BVar2 == 1;
    } while (BVar2 != 1);
  }
  DAT_00b5a7f4 = DAT_00b5a7f4 + -1;
  if (DAT_00b5a7f4 != 0) {
    puStack_2c = auStack_60;
    uStack_5c = 0;
    FUN_00401740(s_OverlappedIO_Wait__u__u_0099ebd8,0x17);
    uVar3 = FUN_00797530(auStack_28);
    uStack_4 = 0;
    FUN_00796d90(uVar3);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return extraout_EAX;
    }
  }
  ExceptionList = pvStack_c;
  return (uint)*(byte *)(in_ECX + 2);
}


// ==== FUN_00449c10 @ 0x00449c10 ====

undefined4 FUN_00449c10(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  BOOL BVar2;
  undefined4 extraout_EAX_00;
  DWORD DVar3;
  int in_ECX;
  undefined1 local_44 [4];
  void *local_40;
  uint local_2c;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b783;
  local_c = ExceptionList;
  if (*(char *)(in_ECX + 4) != '\x01') {
    DAT_00b5a7f4 = DAT_00b5a7f4 + 1;
    if (DAT_00b5a7f8 <= DAT_00b5a7f4) {
      DAT_00b5a7f8 = DAT_00b5a7f4;
    }
    ExceptionList = &local_c;
    if (1 < DAT_00b5a7f8) {
      ExceptionList = &local_c;
      FUN_00401740(s_OverlappedIO_Start__u__u_0099ebf0,0x18);
      uVar1 = FUN_00797530(local_44);
      local_4 = 0;
      FUN_00796d90(uVar1);
      local_4 = 0xffffffff;
      if (0xf < local_2c) {
        _free(local_40);
        return extraout_EAX;
      }
    }
    local_4 = 0xffffffff;
    BVar2 = ReadFile(*(HANDLE *)(in_ECX + 0x28),*(LPVOID *)(in_ECX + 0x34),*(DWORD *)(in_ECX + 0x38)
                     ,(LPDWORD)0x0,*(LPOVERLAPPED *)(in_ECX + 0x44));
    if (BVar2 == 1) {
      *(undefined1 *)(in_ECX + 8) = 1;
      *(undefined1 *)(in_ECX + 4) = 1;
      DAT_00b5a7f4 = DAT_00b5a7f4 - 1;
      if (DAT_00b5a7f4 != 0) {
        FUN_00401830(s_OverlappedIO_Start_Complete__u___0099ec0c);
        uVar1 = FUN_00797530(local_44);
        local_4 = 1;
        FUN_00796d90(uVar1);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX_00;
        }
      }
    }
    else {
      DVar3 = GetLastError();
      if (DVar3 != 0x3e5) {
        DAT_00b5a7f4 = DAT_00b5a7f4 - 1;
        if (DAT_00b5a7f4 != 0) {
          FUN_00401830(s_OverlappedIO_Start_Fail__u__u_0099ec30);
          uVar1 = FUN_00797530(local_28);
          local_4 = 2;
          FUN_00796d90(uVar1);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        ExceptionList = local_c;
        return 0;
      }
      *(undefined1 *)(in_ECX + 4) = 1;
    }
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00449de0 @ 0x00449de0 ====

undefined1 * FUN_00449de0(undefined1 *param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = *param_1;
  FUN_00401660(param_1 + 4,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x3c);
  return (undefined1 *)(in_ECX + 8);
}


// ==== FUN_00449e50 @ 0x00449e50 ====

void FUN_00449e50(byte param_1)

{
  void *in_ECX;
  
  FUN_00449980();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00449f30 @ 0x00449f30 ====

void FUN_00449f30(undefined2 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  byte bVar4;
  uint *in_ECX;
  
  uVar1 = in_ECX[3];
  bVar4 = (byte)(uVar1 >> 0x10);
  uVar3 = (undefined1)(uVar1 >> 8);
  *in_ECX = CONCAT31((int3)uVar1,uVar3) << 0x10 | (uint)bVar4 << 8 | uVar1 >> 0x18;
  *(ushort *)(in_ECX + 1) = CONCAT11((char)param_1,(char)((ushort)param_1 >> 8));
  *(ushort *)((int)in_ECX + 6) =
       CONCAT11((char)*(undefined2 *)((int)in_ECX + 6),
                (char)((ushort)*(undefined2 *)((int)in_ECX + 6) >> 8));
  uVar2 = in_ECX[2];
  in_ECX[2] = CONCAT31((int3)uVar2,(char)(uVar2 >> 8)) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
  in_ECX[3] = CONCAT31((int3)uVar1,uVar3) << 0x10 | (uint)bVar4 << 8 | uVar1 >> 0x18;
  return;
}


// ==== FUN_00449fc0 @ 0x00449fc0 ====

void FUN_00449fc0(void)

{
  uint uVar1;
  uint uVar2;
  uint *in_ECX;
  
  uVar1 = *in_ECX;
  *in_ECX = CONCAT31((int3)uVar1,(char)(uVar1 >> 8)) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
            uVar1 >> 0x18;
  *(ushort *)(in_ECX + 1) = CONCAT11((char)in_ECX[1],(char)(in_ECX[1] >> 8));
  uVar1 = in_ECX[2];
  *(ushort *)((int)in_ECX + 6) =
       CONCAT11((char)*(undefined2 *)((int)in_ECX + 6),
                (char)((ushort)*(undefined2 *)((int)in_ECX + 6) >> 8));
  uVar2 = in_ECX[3];
  in_ECX[2] = CONCAT31((int3)uVar1,(char)(uVar1 >> 8)) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
              uVar1 >> 0x18;
  in_ECX[3] = CONCAT31((int3)uVar2,(char)(uVar2 >> 8)) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
  return;
}


// ==== FUN_0044a050 @ 0x0044a050 ====

bool FUN_0044a050(void)

{
  int in_ECX;
  
  return (*(byte *)(in_ECX + 0xc) & 0x80) != 0x80;
}


// ==== FUN_0044a060 @ 0x0044a060 ====

void FUN_0044a060(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f084;
  return;
}


// ==== FUN_0044a070 @ 0x0044a070 ====

void FUN_0044a070(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f084;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044a090 @ 0x0044a090 ====

void FUN_0044a090(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097b827;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f08c;
  pvVar1 = operator_new(0x1c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044f0f0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(8);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044e840();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4._0_1_ = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044dd10();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[8] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044d020();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[9] = uVar2;
  pvVar1 = operator_new(8);
  local_4._0_1_ = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044ca40();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4._0_1_ = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044c8b0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(8);
  local_4._0_1_ = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044c5a0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0x14);
  local_4._0_1_ = 8;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044bf10();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0xc] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 9;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044be30();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0xd] = uVar2;
  pvVar1 = operator_new(8);
  local_4._0_1_ = 10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044b810();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4._0_1_ = 0xb;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044ad90();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[10] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0xc;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044a6e0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0xb] = uVar2;
  pvVar1 = operator_new(0x14);
  local_4 = CONCAT31(local_4._1_3_,0xd);
  if (pvVar1 == (void *)0x0) {
    in_ECX[0xe] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0044a480();
  in_ECX[0xe] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== __break @ 0x0044a2f6 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_0044a300 @ 0x0044a300 ====

void FUN_0044a300(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b839;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099f08c;
  local_4 = 0;
  if ((undefined4 *)in_ECX[0xe] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xe])(1);
  }
  in_ECX[0xe] = 0;
  if ((undefined4 *)in_ECX[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xb])(1);
  }
  in_ECX[0xb] = 0;
  if ((undefined4 *)in_ECX[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[10])(1);
  }
  in_ECX[10] = 0;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  if ((undefined4 *)in_ECX[0xc] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xc])(1);
  }
  in_ECX[0xc] = 0;
  if ((undefined4 *)in_ECX[0xd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xd])(1);
  }
  in_ECX[0xd] = 0;
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[9])(1);
  }
  in_ECX[9] = 0;
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
  }
  in_ECX[8] = 0;
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_0099f084;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0044a420 @ 0x0044a420 ====

void FUN_0044a420(byte param_1)

{
  void *in_ECX;
  
  FUN_0044a300();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044a440 @ 0x0044a440 ====

undefined4 FUN_0044a440(int param_1)

{
  char *in_ECX;
  uint uVar1;
  
  uVar1 = 0;
  param_1 = param_1 - (int)in_ECX;
  while( true ) {
    if (*in_ECX != in_ECX[param_1]) {
      return 0;
    }
    if (*in_ECX == '\0') break;
    uVar1 = uVar1 + 1;
    in_ECX = in_ECX + 1;
    if (0xff < uVar1) {
      return 1;
    }
  }
  return 1;
}


// ==== FUN_0044a480 @ 0x0044a480 ====

void FUN_0044a480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f09c;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a7fc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a7fc = in_ECX;
  return;
}


// ==== FUN_0044a4d0 @ 0x0044a4d0 ====

void FUN_0044a4d0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_110;
  undefined1 local_10c [4];
  undefined4 local_108;
  undefined4 local_104;
  
  local_110 = param_1;
  local_10c[0] = 0x2c;
  local_108 = 0xff;
  local_104 = 0;
  piVar1 = (int *)(**(code **)(*DAT_00b5a6f0 + 4))(&local_110);
  (**(code **)(*piVar1 + 0xc))(1,0);
  FUN_0044a580(local_10c,&DAT_0099f094,&DAT_0099f091);
  uVar2 = FUN_0044ab50(1,0);
  *(undefined4 *)(in_ECX + 4) = uVar2;
  uVar2 = FUN_0044ab50(1,1);
  *(undefined4 *)(in_ECX + 8) = uVar2;
  uVar2 = FUN_0044ab50(1,2);
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  uVar2 = FUN_0044ab50(1,3);
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  (**(code **)(*DAT_00b5a6f0 + 8))(piVar1);
  return;
}


// ==== FUN_0044a580 @ 0x0044a580 ====

char * FUN_0044a580(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x100,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x100)) {
    param_1[0xff] = '\0';
  }
  return param_1;
}


// ==== FUN_0044a5c0 @ 0x0044a5c0 ====

void FUN_0044a5c0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 local_100 [256];
  
  uVar1 = 0;
  do {
    if (*(char *)(uVar1 + param_1) == '\0') {
      if (uVar1 != 0) goto LAB_0044a618;
      goto LAB_0044a5ec;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  uVar1 = 0;
LAB_0044a5ec:
  local_100[0] = 0;
  uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                       s_d__usa_24_0_1_2__develop_share_s_0099f0b4,0xa0);
  FUN_00797b80(uVar2);
  FUN_00797a40();
LAB_0044a618:
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      if ((*(char *)(uVar3 + param_1) < '0') || ('9' < *(char *)(uVar3 + param_1))) {
        local_100[0] = 0;
        uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                             s_d__usa_24_0_1_2__develop_share_s_0099f0b4,0xaa);
        FUN_00797b80(uVar2);
        FUN_00797a40();
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}


// ==== FUN_0044a670 @ 0x0044a670 ====

void FUN_0044a670(void)

{
  FUN_0044a580();
  return;
}


// ==== FUN_0044a690 @ 0x0044a690 ====

void FUN_0044a690(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f09c;
  DAT_00b5a7fc = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044a6c0 @ 0x0044a6c0 ====

void FUN_0044a6c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f178;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044a6e0 @ 0x0044a6e0 ====

void FUN_0044a6e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f184;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a710 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a710 = in_ECX;
  return;
}


// ==== FUN_0044a710 @ 0x0044a710 ====

void FUN_0044a710(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a710 = 0;
  *in_ECX = &PTR_FUN_0099f178;
  return;
}


// ==== FUN_0044a730 @ 0x0044a730 ====

void FUN_0044a730(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined4 local_4bc;
  undefined4 local_4b8;
  uint local_4b4;
  uint local_4b0;
  undefined4 uStack_4ac;
  undefined4 uStack_4a8;
  undefined4 uStack_4a4;
  undefined4 uStack_4a0;
  undefined4 uStack_49c;
  undefined4 uStack_498;
  undefined4 uStack_494;
  undefined4 uStack_490;
  undefined4 uStack_48c;
  undefined4 uStack_488;
  undefined4 uStack_484;
  undefined1 uStack_480;
  undefined4 uStack_47c;
  undefined4 uStack_478;
  undefined4 uStack_474;
  undefined4 uStack_470;
  undefined4 uStack_46c;
  undefined4 uStack_468;
  undefined4 uStack_464;
  undefined4 uStack_460;
  undefined4 uStack_45c;
  undefined4 uStack_458;
  undefined4 uStack_454;
  undefined4 uStack_450;
  undefined4 uStack_44c;
  undefined4 uStack_448;
  undefined4 uStack_444;
  undefined4 uStack_440;
  undefined4 uStack_43c;
  undefined4 uStack_438;
  undefined4 uStack_434;
  undefined4 uStack_430;
  undefined4 uStack_42c;
  undefined4 uStack_428;
  undefined4 uStack_424;
  undefined4 uStack_420;
  void *pvStack_41c;
  char acStack_418 [256];
  undefined1 auStack_318 [256];
  undefined1 auStack_218 [256];
  undefined1 auStack_118 [260];
  void *pvStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097b85e;
  pvStack_c = ExceptionList;
  local_4bc = param_1;
  local_4b8 = CONCAT31(local_4b8._1_3_,0x2c);
  local_4b4 = 0xff;
  local_4b0 = 0;
  ExceptionList = &pvStack_c;
  piVar1 = (int *)(**(code **)(*DAT_00b5a6f0 + 4))(&local_4bc);
  iVar7 = 1;
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (1 < iVar2) {
    do {
      pcVar3 = (char *)(**(code **)(*piVar1 + 0xc))(iVar7,0);
      FUN_0044a580(acStack_418,&DAT_0099f170,&DAT_0099f0f5);
      uVar5 = 0;
      iVar2 = -(int)pcVar3;
      do {
        if (*pcVar3 != pcVar3[(int)(acStack_418 + iVar2)]) {
          piVar6 = (int *)0x0;
          uVar4 = FUN_0044ab50(iVar7,0);
          local_4b8 = FUN_0044ab50(iVar7,1);
          local_4b0 = FUN_0044ab50(iVar7,2);
          local_4b4 = FUN_0044ab50(iVar7,3);
          uStack_4ac = FUN_0044ab50(iVar7,4);
          uStack_4a8 = FUN_0044ab50(iVar7,5);
          uStack_4a4 = FUN_0044ab50(iVar7,6);
          uStack_4a0 = FUN_0044ab50(iVar7,7);
          uStack_49c = FUN_0044ab50(iVar7,8);
          uStack_498 = FUN_0044ab50(iVar7,9);
          uStack_494 = FUN_0044ab50(iVar7,10);
          uStack_490 = FUN_0044ab50(iVar7,0xb);
          uStack_48c = FUN_0044ab50(iVar7,0xc);
          uStack_488 = FUN_0044ab50(iVar7,0xd);
          uStack_484 = FUN_0044ab50(iVar7,0xe);
          uStack_480 = FUN_0044ab50(iVar7,0xf);
          uStack_47c = FUN_0044ab50(iVar7,0x10);
          uStack_444 = FUN_0044ab50(iVar7,0x11);
          uStack_440 = FUN_0044ab50(iVar7,0x12);
          uStack_43c = FUN_0044ab50(iVar7,0x13);
          uStack_438 = FUN_0044ab50(iVar7,0x14);
          uStack_434 = FUN_0044ab50(iVar7,0x15);
          uStack_430 = FUN_0044ab50(iVar7,0x16);
          uStack_478 = FUN_0044ab50(iVar7,0x17);
          uStack_474 = FUN_0044ab50(iVar7,0x18);
          uStack_470 = FUN_0044ab50(iVar7,0x19);
          uStack_46c = FUN_0044ab50(iVar7,0x1a);
          uStack_468 = FUN_0044ab50(iVar7,0x1b);
          uStack_464 = FUN_0044ab50(iVar7,0x1c);
          uStack_460 = FUN_0044ab50(iVar7,0x1d);
          uStack_45c = FUN_0044ab50(iVar7,0x1e);
          uStack_44c = FUN_0044ab50(iVar7,0x1f);
          uStack_458 = FUN_0044ab50(iVar7,0x20);
          uStack_454 = FUN_0044ab50(iVar7,0x21);
          uStack_450 = FUN_0044ab50(iVar7,0x22);
          uStack_448 = FUN_0044ab50(iVar7,0x23);
          uStack_42c = FUN_0044ab50(iVar7,0x24);
          uStack_428 = FUN_0044ab50(iVar7,0x25);
          uStack_424 = FUN_0044ab50(iVar7,0x26);
          uStack_420 = FUN_0044ab50(iVar7,0x27);
          if (local_4b4 < local_4b0) {
            FUN_0044a580(auStack_218,&DAT_0099f170,s_Info_csv_Error___Sight_>_Persuit_0099f0f8);
            FUN_00797b80(auStack_218);
            FUN_0044a580(auStack_318,&DAT_0099f170,s_Info_csv_Error___Sight_>_Persuit_0099f120);
            FUN_00797b80(auStack_318);
            FUN_0044a580(auStack_118,&DAT_0099f170,s_Info_csv_Error___Sight_>_Persuit_0099f148);
            FUN_00797b80(auStack_118);
          }
          else {
            pvStack_41c = operator_new(0xa0);
            uStack_10 = 0;
            if (pvStack_41c != (void *)0x0) {
              piVar6 = (int *)FUN_004510c0();
            }
            uStack_10 = 0xffffffff;
            (**(code **)(*piVar6 + 4))(&local_4b8);
            (**(code **)(*DAT_00b5a714 + 4))(uVar4,piVar6);
          }
          break;
        }
        if (*pcVar3 == '\0') break;
        uVar5 = uVar5 + 1;
        pcVar3 = pcVar3 + 1;
      } while (uVar5 < 0x100);
      iVar7 = iVar7 + 1;
      iVar2 = (**(code **)(*piVar1 + 4))();
    } while (iVar7 < iVar2);
  }
  (**(code **)(*DAT_00b5a6f0 + 8))(piVar1);
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_0044ab50 @ 0x0044ab50 ====

long FUN_0044ab50(undefined4 param_1,undefined4 param_2)

{
  char *_Str;
  uint uVar1;
  long lVar2;
  int *in_ECX;
  
  _Str = (char *)(**(code **)(*in_ECX + 0xc))(param_1,param_2);
  FUN_0044a5c0(_Str,param_1,param_2);
  uVar1 = 0;
  do {
    if (_Str[uVar1] == '\0') {
      if (uVar1 == 0) {
        return 0;
      }
      lVar2 = _atol(_Str);
      return lVar2;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  return 0;
}


// ==== FUN_0044abb0 @ 0x0044abb0 ====

void FUN_0044abb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0044a710();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044abd0 @ 0x0044abd0 ====

void FUN_0044abd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f190;
  return;
}


// ==== FUN_0044abe0 @ 0x0044abe0 ====

void FUN_0044abe0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f190;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044ac00 @ 0x0044ac00 ====

void FUN_0044ac00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f1a0;
  return;
}


// ==== FUN_0044ac10 @ 0x0044ac10 ====

void FUN_0044ac10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f1bc;
  return;
}


// ==== FUN_0044ac20 @ 0x0044ac20 ====

void FUN_0044ac20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f214;
  return;
}


// ==== FUN_0044ac30 @ 0x0044ac30 ====

void FUN_0044ac30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f1a0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044ac50 @ 0x0044ac50 ====

void FUN_0044ac50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f1bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044ac70 @ 0x0044ac70 ====

void FUN_0044ac70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f214;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044ac90 @ 0x0044ac90 ====

undefined4 FUN_0044ac90(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_0044acc0 @ 0x0044acc0 ====

void FUN_0044acc0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b878;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099f234;
  DAT_00b5a714 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
  (**(code **)(*(int *)in_ECX[2] + 0x20))();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_0099f190;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0044ad60 @ 0x0044ad60 ====

void FUN_0044ad60(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar1 = unaff_ESI;
  puVar1[1] = unaff_retaddr;
  (**(code **)(**(int **)(in_ECX + 8) + 0x24))(puVar1);
  return;
}


// ==== FUN_0044ad90 @ 0x0044ad90 ====

void FUN_0044ad90(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097b8a0;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f234;
  pvVar2 = operator_new(0x4e38);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0044aea0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x8ccc);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0044b460(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a714 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a714 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044ae60 @ 0x0044ae60 ====

void FUN_0044ae60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f22c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,1000,FUN_006ef6d0);
  return;
}


// ==== FUN_0044ae80 @ 0x0044ae80 ====

void FUN_0044ae80(byte param_1)

{
  void *in_ECX;
  
  FUN_0044ae60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044aea0 @ 0x0044aea0 ====

void FUN_0044aea0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b8b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f244;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_0099f22c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,1000,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x138a] = 0;
  in_ECX[0x138a] = in_ECX[0x138a] + 1000;
  in_ECX[0x138d] = in_ECX + 2;
  in_ECX[0x138b] = 0;
  in_ECX[0x138c] = 0;
  iVar2 = 999;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[4999] = 0;
  in_ECX[5000] = 0;
  in_ECX[0x1389] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044af50 @ 0x0044af50 ====

undefined4 FUN_0044af50(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x4e2c);
}


// ==== FUN_0044af60 @ 0x0044af60 ====

void FUN_0044af60(byte param_1)

{
  void *in_ECX;
  
  FUN_0044af80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044af80 @ 0x0044af80 ====

void FUN_0044af80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b8e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f244;
  local_4 = 1;
  if ((void *)in_ECX[0x138c] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_0099f22c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,1000,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_0099f1a0;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x138c]);
  return;
}


// ==== FUN_0044b000 @ 0x0044b000 ====

void * FUN_0044b000(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b8fb;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x4e34);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x4e2c) = *(int *)(in_ECX + 0x4e2c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x4e30);
      *(void **)(in_ECX + 0x4e30) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x4e34) = *(undefined4 *)((int)param_2 + 8);
    }
    *(undefined4 *)((int)param_2 + 8) = 0;
    *(int *)((int)param_2 + 0x10) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099f258,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0044b0e0 @ 0x0044b0e0 ====

undefined4 FUN_0044b0e0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099f258,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x4e34);
    *(int *)(in_ECX + 0x4e2c) = *(int *)(in_ECX + 0x4e2c) + -1;
    *(int *)(in_ECX + 0x4e34) = param_2;
  }
  return 0;
}


// ==== FUN_0044b160 @ 0x0044b160 ====

void FUN_0044b160(byte param_1)

{
  void *in_ECX;
  
  FUN_0044acc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044b180 @ 0x0044b180 ====

void FUN_0044b180(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f2c4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x24,1000,FUN_006ef6d0);
  return;
}


// ==== FUN_0044b1a0 @ 0x0044b1a0 ====

void FUN_0044b1a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b923;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f2cc;
  local_4 = 1;
  if ((void *)in_ECX[0x232c] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_0099f2c4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x24,1000,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_0099f214;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x232c]);
  return;
}


// ==== FUN_0044b220 @ 0x0044b220 ====

undefined4 FUN_0044b220(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x8cac);
}


// ==== FUN_0044b230 @ 0x0044b230 ====

undefined4 FUN_0044b230(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x20) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099f258,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x20);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x20);
    }
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(in_ECX + 0x8cb4);
    *(int *)(in_ECX + 0x8cac) = *(int *)(in_ECX + 0x8cac) + -1;
    *(int *)(in_ECX + 0x8cb4) = param_2;
  }
  return 0;
}


// ==== FUN_0044b2b0 @ 0x0044b2b0 ====

undefined4 * FUN_0044b2b0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[8] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099f258,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[8] = param_2[8] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x8cb4);
  *(int *)(in_ECX + 0x8cac) = *(int *)(in_ECX + 0x8cac) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x24);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[7] = *(undefined4 *)(in_ECX + 0x8cb0);
    *(undefined4 **)(in_ECX + 0x8cb0) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x8cb4) = puVar2[6];
  }
  puVar2[6] = 0;
  puVar2[8] = param_1;
  return puVar2;
}


// ==== FUN_0044b370 @ 0x0044b370 ====

void FUN_0044b370(byte param_1)

{
  void *in_ECX;
  
  FUN_0044b180();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044b390 @ 0x0044b390 ====

void FUN_0044b390(byte param_1)

{
  void *in_ECX;
  
  FUN_0044b1a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044b3b0 @ 0x0044b3b0 ====

void FUN_0044b3b0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b938;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f2cc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_0099f2c4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x24,1000,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x232a] = 0;
  in_ECX[0x232a] = in_ECX[0x232a] + 1000;
  in_ECX[0x232d] = in_ECX + 2;
  in_ECX[0x232b] = 0;
  in_ECX[0x232c] = 0;
  iVar2 = 999;
  puVar1 = in_ECX;
  do {
    puVar1[8] = puVar1 + 0xb;
    puVar1[9] = 0;
    puVar1[10] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 9;
  } while (iVar2 != 0);
  in_ECX[8999] = 0;
  in_ECX[9000] = 0;
  in_ECX[0x2329] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044b460 @ 0x0044b460 ====

void FUN_0044b460(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b963;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099f2e4;
  FUN_0044b3b0();
  in_ECX[3] = param_1;
  local_4 = CONCAT31(local_4._1_3_,1);
  puVar1 = (undefined4 *)(**(code **)(in_ECX[5] + 0xc))(1,0);
  in_ECX[1] = puVar1;
  *puVar1 = 0;
  *(undefined4 *)(in_ECX[1] + 8) = in_ECX[1];
  *(undefined4 *)(in_ECX[1] + 0xc) = in_ECX[1];
  *(undefined4 *)(in_ECX[1] + 0x10) = in_ECX[1];
  *(undefined1 *)(in_ECX[1] + 0x14) = 1;
  in_ECX[2] = in_ECX[1];
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_0044b4f0 @ 0x0044b4f0 ====

int FUN_0044b4f0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 == *(int *)(in_ECX + 4)) {
    return 0;
  }
  for (iVar2 = *(int *)(iVar1 + 8); iVar2 != *(int *)(in_ECX + 4); iVar2 = *(int *)(iVar2 + 8)) {
    iVar1 = iVar2;
  }
  return iVar1;
}


// ==== FUN_0044b510 @ 0x0044b510 ====

int FUN_0044b510(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 == *(int *)(in_ECX + 4)) {
    return 0;
  }
  for (iVar2 = *(int *)(iVar1 + 0xc); iVar2 != *(int *)(in_ECX + 4); iVar2 = *(int *)(iVar2 + 0xc))
  {
    iVar1 = iVar2;
  }
  return iVar1;
}


// ==== FUN_0044b530 @ 0x0044b530 ====

void FUN_0044b530(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    FUN_0044b550(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_0044b550 @ 0x0044b550 ====

void FUN_0044b550(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != *(int *)(in_ECX + 4)) {
    FUN_0044b550(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != *(int *)(in_ECX + 4)) {
    FUN_0044b550(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0044b590 @ 0x0044b590 ====

uint FUN_0044b590(undefined4 param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = FUN_0044e520(param_1);
  return -(uint)(uVar1 != *(uint *)(in_ECX + 4)) & uVar1;
}


// ==== FUN_0044b5b0 @ 0x0044b5b0 ====

uint FUN_0044b5b0(undefined4 param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = FUN_0044e570(param_1);
  return -(uint)(uVar1 != *(uint *)(in_ECX + 4)) & uVar1;
}


// ==== FUN_0044b5d0 @ 0x0044b5d0 ====

void FUN_0044b5d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    FUN_0044b5f0(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_0044b5f0 @ 0x0044b5f0 ====

void FUN_0044b5f0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != *(int *)(in_ECX + 4)) {
    FUN_0044b5f0(param_1[2]);
  }
  if (param_1[3] != *(int *)(in_ECX + 4)) {
    FUN_0044b5f0(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0044b660 @ 0x0044b660 ====

void FUN_0044b660(int param_1)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (*(char *)(iVar1 + 0x14) != '\0') {
    *(undefined1 *)(*(int *)(in_ECX + 8) + 0x14) = 1;
    return;
  }
  do {
    if (iVar1 == *(int *)(*(int *)(iVar1 + 0x10) + 8)) {
      param_1 = FUN_0054f9d0(param_1);
    }
    else {
      param_1 = FUN_0044e710(param_1);
    }
    iVar1 = *(int *)(param_1 + 0x10);
  } while (*(char *)(iVar1 + 0x14) == '\0');
  *(undefined1 *)(*(int *)(in_ECX + 8) + 0x14) = 1;
  return;
}


// ==== FUN_0044b6b0 @ 0x0044b6b0 ====

uint FUN_0044b6b0(undefined4 param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = FUN_0054e000(param_1);
  return -(uint)(uVar1 != *(uint *)(in_ECX + 4)) & uVar1;
}


// ==== FUN_0044b6d0 @ 0x0044b6d0 ====

uint FUN_0044b6d0(uint *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(in_ECX + 8);
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if (puVar2 != puVar1) {
    do {
      if (*param_1 < *(uint *)*puVar2) {
        puVar2 = (undefined4 *)puVar2[2];
      }
      else {
        if (*param_1 <= *(uint *)*puVar2) break;
        puVar2 = (undefined4 *)puVar2[3];
      }
    } while (puVar2 != puVar1);
  }
  return -(uint)(puVar2 != puVar1) & (uint)puVar2;
}


// ==== FUN_0044b710 @ 0x0044b710 ====

void FUN_0044b710(byte param_1)

{
  void *in_ECX;
  
  FUN_0044b730();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044b730 @ 0x0044b730 ====

void FUN_0044b730(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097b963;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f2e4;
  local_4 = 1;
  if (in_ECX[2] != in_ECX[1]) {
    FUN_0044b5f0(in_ECX[2]);
    in_ECX[2] = in_ECX[1];
  }
  FUN_0054e140();
  local_4 = local_4 & 0xffffff00;
  FUN_0044b1a0();
  *in_ECX = &PTR_FUN_0099f1bc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044b7a0 @ 0x0044b7a0 ====

void FUN_0044b7a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0044b7a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0044b7b0 @ 0x0044b7b0 ====

void FUN_0044b7b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0044b7b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0044b7c0 @ 0x0044b7c0 ====

int FUN_0044b7c0(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  if (param_2 == 0) {
    param_2 = 0;
  }
  else {
    param_2 = param_2 + -4;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  return iVar1 + 4;
}


// ==== FUN_0044b7f0 @ 0x0044b7f0 ====

void FUN_0044b7f0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0044b808. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_0044b810 @ 0x0044b810 ====

void FUN_0044b810(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b9a3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f4e4;
  pvVar1 = operator_new(0xe18);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044b9a0();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a70c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a70c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044b8a0 @ 0x0044b8a0 ====

void FUN_0044b8a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b9b5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f4e4;
  DAT_00b5a70c = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_0099f494;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044b900 @ 0x0044b900 ====

void FUN_0044b900(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f4ac;
  return;
}


// ==== FUN_0044b910 @ 0x0044b910 ====

void FUN_0044b910(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f4ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044b940 @ 0x0044b940 ====

void FUN_0044b940(void)

{
  FUN_004510f0();
  return;
}


// ==== FUN_0044b950 @ 0x0044b950 ====

void FUN_0044b950(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f494;
  return;
}


// ==== FUN_0044b960 @ 0x0044b960 ====

void FUN_0044b960(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f494;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044b980 @ 0x0044b980 ====

void FUN_0044b980(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f4c4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,0x80,(_func_void_void_ptr *)&LAB_0044b930);
  return;
}


// ==== FUN_0044b9a0 @ 0x0044b9a0 ====

void FUN_0044b9a0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097b978;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f4cc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_0099f4c4;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x1c,0x80,FUN_0044b940,(_func_void_void_ptr *)&LAB_0044b930);
  in_ECX[0x382] = 0;
  in_ECX[0x382] = in_ECX[0x382] + 0x80;
  in_ECX[0x385] = in_ECX + 2;
  in_ECX[899] = 0;
  in_ECX[900] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[6] = puVar1 + 9;
    puVar1[7] = 0;
    puVar1[8] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 7;
  } while (iVar2 != 0);
  in_ECX[0x37f] = 0;
  in_ECX[0x380] = 0;
  in_ECX[0x381] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044ba50 @ 0x0044ba50 ====

undefined4 FUN_0044ba50(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe0c);
}


// ==== FUN_0044ba60 @ 0x0044ba60 ====

void FUN_0044ba60(byte param_1)

{
  void *in_ECX;
  
  FUN_0044b980();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044ba80 @ 0x0044ba80 ====

void * FUN_0044ba80(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097b9d9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0xe14);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xe0c) = *(int *)(in_ECX + 0xe0c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x1c);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_004510f0();
      }
      *(undefined4 *)((int)param_2 + 0x14) = *(undefined4 *)(in_ECX + 0xe10);
      *(void **)(in_ECX + 0xe10) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0xe14) = *(undefined4 *)((int)param_2 + 0x10);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0x18) = param_1;
    *(undefined4 *)((int)param_2 + 0x10) = 0;
    FUN_00451110();
  }
  else {
    if (*(int *)((int)param_2 + 0x18) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099f4f8,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x18) = *(int *)((int)param_2 + 0x18) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0044bba0 @ 0x0044bba0 ====

undefined4 FUN_0044bba0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099f4f8,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x18);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x18);
    }
    FUN_00451120();
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(in_ECX + 0xe14);
    *(int *)(in_ECX + 0xe0c) = *(int *)(in_ECX + 0xe0c) + -1;
    *(int *)(in_ECX + 0xe14) = param_2;
  }
  return 0;
}


// ==== FUN_0044bc30 @ 0x0044bc30 ====

void FUN_0044bc30(byte param_1)

{
  void *in_ECX;
  
  FUN_0044bc50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044bc50 @ 0x0044bc50 ====

void FUN_0044bc50(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097ba09;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f4cc;
  local_4 = 1;
  if (in_ECX[899] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f39c,
                         s_d__usa_24_0_1_2__develop_share_s_0099f340,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 8;
  iVar3 = 0x80;
  do {
    if (*piVar2 != 0) {
      local_10c[0] = 0;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f40c,
                           s_d__usa_24_0_1_2__develop_share_s_0099f3b0,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 7;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[900];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_0099f4c4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,0x80,(_func_void_void_ptr *)&LAB_0044b930);
    *in_ECX = &PTR_FUN_0099f4ac;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0x18) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f47c,
                         s_d__usa_24_0_1_2__develop_share_s_0099f420,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00451100();
  _free(_Memory);
  return;
}


// ==== FUN_0044bd90 @ 0x0044bd90 ====

void FUN_0044bd90(byte param_1)

{
  void *in_ECX;
  
  FUN_0044b8a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044bdb0 @ 0x0044bdb0 ====

void FUN_0044bdb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f560;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044bdd0 @ 0x0044bdd0 ====

undefined4 FUN_0044bdd0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097ba2b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x14);
  uVar2 = 0;
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0044bf10();
  }
  local_4 = 0xffffffff;
  FUN_0044c040(param_1);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_0044be30 @ 0x0044be30 ====

void FUN_0044be30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f570;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a6f0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a6f0 = in_ECX;
  return;
}


// ==== FUN_0044be60 @ 0x0044be60 ====

void FUN_0044be60(undefined4 *param_1)

{
  FUN_0044bf70();
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(1);
  }
  return;
}


// ==== FUN_0044be80 @ 0x0044be80 ====

void FUN_0044be80(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a6f0 = 0;
  *in_ECX = &PTR_FUN_0099f560;
  return;
}


// ==== FUN_0044bea0 @ 0x0044bea0 ====

void FUN_0044bea0(byte param_1)

{
  void *in_ECX;
  
  FUN_0044be80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044bec0 @ 0x0044bec0 ====

void FUN_0044bec0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f638;
  return;
}


// ==== FUN_0044bed0 @ 0x0044bed0 ====

void FUN_0044bed0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f638;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044bef0 @ 0x0044bef0 ====

undefined4 FUN_0044bef0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_0044bf00 @ 0x0044bf00 ====

undefined4 FUN_0044bf00(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_0044bf10 @ 0x0044bf10 ====

void FUN_0044bf10(void)

{
  undefined1 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ba48;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f64c;
  in_ECX[1] = 0;
  puVar1 = operator_new(0x100000);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    *puVar1 = 0;
  }
  in_ECX[2] = puVar1;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044bf70 @ 0x0044bf70 ====

void FUN_0044bf70(void)

{
  void *pvVar1;
  int in_ECX;
  
  pvVar1 = *(void **)(in_ECX + 4);
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    return;
  }
  _eh_vector_destructor_iterator_(pvVar1,0x100,*(int *)((int)pvVar1 + -4),FUN_006ef6d0);
  _free((void *)((int)pvVar1 + -4));
  return;
}


// ==== FUN_0044bfb0 @ 0x0044bfb0 ====

void FUN_0044bfb0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097ba5d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f64c;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f598,s___Table_Provider_cpp_0099f580,
                         0x11);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    *in_ECX = &PTR_FUN_0099f638;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0044c040 @ 0x0044c040 ====

void FUN_0044c040(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int in_ECX;
  int *piVar5;
  undefined1 local_20c [248];
  undefined1 auStack_114 [256];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097ba75;
  pvStack_c = ExceptionList;
  piVar5 = (int *)0x0;
  ExceptionList = &pvStack_c;
  if ((int)param_1[2] < 1) {
    local_20c[0] = 0;
    ExceptionList = &pvStack_c;
    uVar1 = FUN_0044a580(local_20c,s_File___s__Line___d_0099f5c4,s___Table_Provider_cpp_0099f5ac,
                         0x18);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  *(undefined4 *)(in_ECX + 0xc) = param_1[3];
  *(undefined4 *)(in_ECX + 0x10) = param_1[2];
  iVar2 = (**(code **)(*(int *)*param_1 + 8))(0x100000,*(undefined4 *)(in_ECX + 8));
  *(undefined1 *)(*(int *)(in_ECX + 8) + iVar2) = 0;
  uVar3 = 0;
  do {
    if (*(char *)(*(int *)(in_ECX + 8) + uVar3) == '\0') {
      if (0xfffff < uVar3) {
        auStack_114[0] = 0;
        uVar1 = FUN_0044a580(auStack_114,s_File___s__Line___d_0099f5f0,
                             s___Table_Provider_cpp_0099f5d8,0x21);
        FUN_00797b80(uVar1);
        FUN_00797a40();
      }
      break;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100000);
  if (*(int *)(in_ECX + 0xc) == 0) {
    uVar1 = FUN_0044c270();
    *(undefined4 *)(in_ECX + 0xc) = uVar1;
  }
  iVar2 = *(int *)(in_ECX + 0x10) * *(int *)(in_ECX + 0xc);
  piVar4 = operator_new(iVar2 * 0x100 + 4);
  pvStack_c = (void *)0x0;
  if (piVar4 != (int *)0x0) {
    piVar5 = piVar4 + 1;
    *piVar4 = iVar2;
    _eh_vector_constructor_iterator_(piVar5,0x100,iVar2,FUN_005fd550,FUN_006ef6d0);
  }
  *(int **)(in_ECX + 4) = piVar5;
  pvStack_c = (void *)0xffffffff;
  FUN_0044c350(*(undefined1 *)(param_1 + 1));
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_0044c190 @ 0x0044c190 ====

int FUN_0044c190(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (*(int *)(in_ECX + 4) == 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f61c,s___Table_Provider_cpp_0099f604,
                         0x42);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  iVar2 = FUN_0044c2c0(param_1,param_2);
  return iVar2 * 0x100 + *(int *)(in_ECX + 4);
}


// ==== FUN_0044c1f0 @ 0x0044c1f0 ====

void FUN_0044c1f0(void)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = 0;
  while ((((cVar1 = *(char *)(uVar3 + in_ECX), cVar1 == ' ' || (cVar1 == '\t')) || (cVar1 == '\r'))
         || (cVar1 == '\n'))) {
    uVar3 = uVar3 + 1;
    if (0xff < uVar3) {
LAB_0044c21a:
      uVar3 = 0;
      pcVar2 = (char *)(uVar4 + in_ECX);
      while( true ) {
        cVar1 = *pcVar2;
        *(char *)(uVar3 + in_ECX) = cVar1;
        if (cVar1 == '\0') {
          return;
        }
        cVar1 = pcVar2[1];
        *(char *)(uVar3 + 1 + in_ECX) = cVar1;
        if (cVar1 == '\0') {
          return;
        }
        cVar1 = pcVar2[2];
        *(char *)(uVar3 + 2 + in_ECX) = cVar1;
        if (cVar1 == '\0') {
          return;
        }
        cVar1 = pcVar2[3];
        *(char *)(uVar3 + 3 + in_ECX) = cVar1;
        if (cVar1 == '\0') break;
        uVar3 = uVar3 + 4;
        pcVar2 = pcVar2 + 4;
        if (0xff < uVar3) {
          return;
        }
      }
      return;
    }
  }
  uVar4 = uVar3;
  goto LAB_0044c21a;
}


// ==== FUN_0044c270 @ 0x0044c270 ====

int FUN_0044c270(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 1;
  uVar2 = 0;
  do {
    if (*(char *)(*(int *)(in_ECX + 8) + uVar2) == '\0') goto LAB_0044c293;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100000);
  uVar2 = 0;
LAB_0044c293:
  uVar3 = 0;
  if (uVar2 != 0) {
    do {
      if (*(char *)(uVar3 + *(int *)(in_ECX + 8)) == '\n') {
        iVar1 = iVar1 + 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return iVar1;
}


// ==== FUN_0044c2c0 @ 0x0044c2c0 ====

int FUN_0044c2c0(int param_1,int param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (*(int *)(in_ECX + 0xc) < param_1) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,s___Table_Provider_cpp_0099f65c,
                         0x4a);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (*(int *)(in_ECX + 0x10) < param_2) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,s___Table_Provider_cpp_0099f65c,
                         0x4b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  return *(int *)(in_ECX + 0x10) * param_1 + param_2;
}


// ==== FUN_0044c350 @ 0x0044c350 ====

void FUN_0044c350(char param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int in_ECX;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_108;
  uint local_104;
  undefined1 local_100 [256];
  
  iVar2 = *(int *)(in_ECX + 8);
  uVar9 = 0;
  local_104 = 0;
  do {
    if (*(char *)(iVar2 + local_104) == '\0') goto LAB_0044c379;
    local_104 = local_104 + 1;
  } while (local_104 < 0x100000);
  local_104 = 0;
LAB_0044c379:
  local_108 = 0;
  if (*(int *)(in_ECX + 0xc) < 1) {
    return;
  }
LAB_0044c388:
  iVar8 = 0;
  iVar7 = 0;
  if (0 < *(int *)(in_ECX + 0x10)) {
    do {
      if (local_104 < uVar9) goto LAB_0044c497;
      iVar4 = FUN_0044c2c0(local_108,iVar7);
      cVar1 = *(char *)(iVar2 + uVar9);
      iVar4 = iVar4 * 0x100 + *(int *)(in_ECX + 4);
      if (cVar1 == param_1) {
        *(undefined1 *)(iVar4 + iVar8) = 0;
        uVar6 = 0;
        do {
          if (*(char *)(uVar6 + iVar4) == '\0') goto LAB_0044c405;
          uVar6 = uVar6 + 1;
        } while (uVar6 < 0x100);
        uVar6 = 0;
LAB_0044c405:
        do {
          do {
            uVar3 = uVar6;
            uVar6 = uVar3 - 1;
            cVar1 = *(char *)(uVar6 + iVar4);
          } while (cVar1 == ' ');
        } while (((cVar1 == '\t') || (cVar1 == '\r')) || (cVar1 == '\n'));
        *(undefined1 *)(uVar3 + iVar4) = 0;
        FUN_0044c1f0();
        iVar8 = 0;
        iVar7 = iVar7 + 1;
      }
      else {
        if (cVar1 == '\n') {
LAB_0044c4b8:
          *(undefined1 *)(iVar4 + iVar8) = 0;
          uVar6 = 0;
          goto LAB_0044c4c0;
        }
        if (cVar1 != '\r') {
          if (cVar1 == '\0') goto LAB_0044c4b8;
          *(char *)(iVar4 + iVar8) = cVar1;
          iVar8 = iVar8 + 1;
        }
      }
      uVar9 = uVar9 + 1;
    } while (iVar7 < *(int *)(in_ECX + 0x10));
  }
  cVar1 = *(char *)(iVar2 + uVar9);
  while ((cVar1 != '\n' && (cVar1 != '\0'))) {
    uVar9 = uVar9 + 1;
    if (local_104 < uVar9) {
      local_100[0] = 0;
      uVar5 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,s___Table_Provider_cpp_0099f65c,
                           0xac);
      FUN_00797b80(uVar5);
      FUN_00797a40();
    }
    cVar1 = *(char *)(iVar2 + uVar9);
  }
  goto LAB_0044c494;
  while (uVar6 = uVar6 + 1, uVar6 < 0x100) {
LAB_0044c4c0:
    if (*(char *)(uVar6 + iVar4) == '\0') goto LAB_0044c4d5;
  }
  uVar6 = 0;
LAB_0044c4d5:
  do {
    do {
      uVar3 = uVar6;
      uVar6 = uVar3 - 1;
      cVar1 = *(char *)(uVar6 + iVar4);
    } while (cVar1 == ' ');
  } while (((cVar1 == '\t') || (cVar1 == '\r')) || (cVar1 == '\n'));
  *(undefined1 *)(uVar3 + iVar4) = 0;
  FUN_0044c1f0();
LAB_0044c494:
  uVar9 = uVar9 + 1;
LAB_0044c497:
  local_108 = local_108 + 1;
  if (*(int *)(in_ECX + 0xc) <= local_108) {
    return;
  }
  goto LAB_0044c388;
}


// ==== FUN_0044c500 @ 0x0044c500 ====

void FUN_0044c500(byte param_1)

{
  void *in_ECX;
  
  FUN_0044bfb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044c520 @ 0x0044c520 ====

void FUN_0044c520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f678;
  return;
}


// ==== FUN_0044c530 @ 0x0044c530 ====

void FUN_0044c530(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f678;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044c550 @ 0x0044c550 ====

void FUN_0044c550(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f684;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044c570 @ 0x0044c570 ====

undefined4 FUN_0044c570(int param_1)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 4) + 4 + param_1 * 4);
}


// ==== FUN_0044c5a0 @ 0x0044c5a0 ====

void FUN_0044c5a0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097bae0;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f68c;
  puVar2 = operator_new(0x28);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_0099f684;
    puVar2[9] = 0;
  }
  in_ECX[1] = puVar2;
  puVar2[9] = puVar2[9] + 8;
  piVar1 = in_ECX + 1;
  *(undefined4 *)(in_ECX[1] + 4) = 0;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 0;
  *(undefined4 *)(*piVar1 + 0x18) = 0;
  *(undefined4 *)(*piVar1 + 0x1c) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = 0;
  pvVar3 = operator_new(8);
  local_4._0_1_ = 1;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00453f30();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  *(undefined4 *)(*piVar1 + 4) = uVar4;
  pvVar3 = operator_new(4);
  local_4._0_1_ = 2;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00453540();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  *(undefined4 *)(*piVar1 + 8) = uVar4;
  pvVar3 = operator_new(8);
  local_4._0_1_ = 3;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00452ad0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  *(undefined4 *)(*piVar1 + 0xc) = uVar4;
  pvVar3 = operator_new(4);
  local_4._0_1_ = 4;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004522f0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  *(undefined4 *)(*piVar1 + 0x14) = uVar4;
  pvVar3 = operator_new(4);
  local_4._0_1_ = 5;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00451b80();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  *(undefined4 *)(*piVar1 + 0x10) = uVar4;
  pvVar3 = operator_new(4);
  local_4._0_1_ = 6;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00451890();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  *(undefined4 *)(*piVar1 + 0x1c) = uVar4;
  pvVar3 = operator_new(8);
  local_4._0_1_ = 7;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00451530();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  *(undefined4 *)(*piVar1 + 0x18) = uVar4;
  pvVar3 = operator_new(4);
  local_4 = CONCAT31(local_4._1_3_,8);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004511a0();
  }
  *(undefined4 *)(*piVar1 + 0x20) = uVar4;
  if (piVar1 == (int *)0x0) {
    DAT_00b5a708 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a708 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044c7b0 @ 0x0044c7b0 ====

void FUN_0044c7b0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097baf2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099f68c;
  local_4 = 0;
  DAT_00b5a708 = 0;
  iVar2 = 0;
  do {
    puVar1 = *(undefined4 **)(in_ECX[1] + 4 + iVar2);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    *(undefined4 *)(in_ECX[1] + 4 + iVar2) = 0;
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x20);
  *(int *)(in_ECX[1] + 0x24) = *(int *)(in_ECX[1] + 0x24) + -8;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_0099f678;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0044c840 @ 0x0044c840 ====

void FUN_0044c840(byte param_1)

{
  void *in_ECX;
  
  FUN_0044c7b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044c860 @ 0x0044c860 ====

void FUN_0044c860(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f698;
  return;
}


// ==== FUN_0044c870 @ 0x0044c870 ====

void FUN_0044c870(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f698;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044c890 @ 0x0044c890 ====

undefined4 FUN_0044c890(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0044c8a0 @ 0x0044c8a0 ====

undefined4 FUN_0044c8a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0044c8b0 @ 0x0044c8b0 ====

void FUN_0044c8b0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097bb1e;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f6a8;
  pvVar1 = operator_new(0xc);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00454710();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00454710();
  }
  in_ECX[2] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a6fc = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a6fc = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044c970 @ 0x0044c970 ====

void FUN_0044c970(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bb30;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099f6a8;
  DAT_00b5a6fc = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_0099f698;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0044c9e0 @ 0x0044c9e0 ====

void FUN_0044c9e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0044c970();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044ca00 @ 0x0044ca00 ====

void FUN_0044ca00(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0044ca05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0044ca10 @ 0x0044ca10 ====

void FUN_0044ca10(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0044ca15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0044ca20 @ 0x0044ca20 ====

void FUN_0044ca20(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0044ca25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0044ca30 @ 0x0044ca30 ====

void FUN_0044ca30(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0044ca35. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_0044ca40 @ 0x0044ca40 ====

void FUN_0044ca40(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bb73;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f864;
  pvVar1 = operator_new(0x1418);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044cbd0();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a6f8 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a6f8 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044cad0 @ 0x0044cad0 ====

void FUN_0044cad0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bb85;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f864;
  DAT_00b5a6f8 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_0099f814;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044cb30 @ 0x0044cb30 ====

void FUN_0044cb30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f82c;
  return;
}


// ==== FUN_0044cb40 @ 0x0044cb40 ====

void FUN_0044cb40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f82c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044cb70 @ 0x0044cb70 ====

void FUN_0044cb70(void)

{
  FUN_004551c0();
  return;
}


// ==== FUN_0044cb80 @ 0x0044cb80 ====

void FUN_0044cb80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f814;
  return;
}


// ==== FUN_0044cb90 @ 0x0044cb90 ====

void FUN_0044cb90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f814;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044cbb0 @ 0x0044cbb0 ====

void FUN_0044cbb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099f844;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x28,0x80,(_func_void_void_ptr *)&LAB_0044cb60);
  return;
}


// ==== FUN_0044cbd0 @ 0x0044cbd0 ====

void FUN_0044cbd0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bb48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f84c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_0099f844;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x28,0x80,FUN_0044cb70,(_func_void_void_ptr *)&LAB_0044cb60);
  in_ECX[0x502] = 0;
  in_ECX[0x502] = in_ECX[0x502] + 0x80;
  in_ECX[0x505] = in_ECX + 2;
  in_ECX[0x503] = 0;
  in_ECX[0x504] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[9] = puVar1 + 0xc;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 10;
  } while (iVar2 != 0);
  in_ECX[0x4ff] = 0;
  in_ECX[0x500] = 0;
  in_ECX[0x501] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044cc80 @ 0x0044cc80 ====

void FUN_0044cc80(byte param_1)

{
  void *in_ECX;
  
  FUN_0044cbb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044cca0 @ 0x0044cca0 ====

void * FUN_0044cca0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097bba9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x1414);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x140c) = *(int *)(in_ECX + 0x140c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x28);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_004551c0();
      }
      *(undefined4 *)((int)param_2 + 0x20) = *(undefined4 *)(in_ECX + 0x1410);
      *(void **)(in_ECX + 0x1410) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x1414) = *(undefined4 *)((int)param_2 + 0x1c);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0x24) = param_1;
    *(undefined4 *)((int)param_2 + 0x1c) = 0;
    FUN_00455360();
  }
  else {
    if (*(int *)((int)param_2 + 0x24) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099f878,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x24) = *(int *)((int)param_2 + 0x24) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0044cdc0 @ 0x0044cdc0 ====

undefined4 FUN_0044cdc0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x24) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099f878,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x24);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x24);
    }
    FUN_00455320();
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(in_ECX + 0x1414);
    *(int *)(in_ECX + 0x140c) = *(int *)(in_ECX + 0x140c) + -1;
    *(int *)(in_ECX + 0x1414) = param_2;
  }
  return 0;
}


// ==== FUN_0044ce50 @ 0x0044ce50 ====

void FUN_0044ce50(byte param_1)

{
  void *in_ECX;
  
  FUN_0044ce70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044ce70 @ 0x0044ce70 ====

void FUN_0044ce70(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097bbd9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099f84c;
  local_4 = 1;
  if (in_ECX[0x503] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f71c,
                         s_d__usa_24_0_1_2__develop_share_s_0099f6c0,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0xb;
  iVar3 = 0x80;
  do {
    if (*piVar2 != 0) {
      local_10c[0] = 0;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f78c,
                           s_d__usa_24_0_1_2__develop_share_s_0099f730,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 10;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x504];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_0099f844;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x28,0x80,(_func_void_void_ptr *)&LAB_0044cb60);
    *in_ECX = &PTR_FUN_0099f82c;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0x24) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f7fc,
                         s_d__usa_24_0_1_2__develop_share_s_0099f7a0,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00455290();
  _free(_Memory);
  return;
}


// ==== FUN_0044cfb0 @ 0x0044cfb0 ====

void FUN_0044cfb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0044cad0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044cfd0 @ 0x0044cfd0 ====

void FUN_0044cfd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fae4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044cff0 @ 0x0044cff0 ====

void FUN_0044cff0(int param_1)

{
  char cVar1;
  char *in_ECX;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  pcVar2 = in_ECX;
  do {
    cVar1 = pcVar2[param_1 - (int)in_ECX];
    *pcVar2 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0x100);
  *in_ECX = '\0';
  return;
}


// ==== FUN_0044d020 @ 0x0044d020 ====

void FUN_0044d020(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099faf0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a700 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a700 = in_ECX;
  return;
}


// ==== FUN_0044d050 @ 0x0044d050 ====

void FUN_0044d050(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a700 = 0;
  *in_ECX = &PTR_FUN_0099fae4;
  return;
}


// ==== FUN_0044d070 @ 0x0044d070 ====

int FUN_0044d070(undefined1 param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  char local_100 [256];
  
  FUN_0044a580(local_100,&DAT_0099fadc,s_UNDER_ATTACK_0099f8d8);
  uVar2 = 0;
  while ((&param_1)[uVar2] == local_100[uVar2]) {
    if (((&param_1)[uVar2] == '\0') || (uVar2 = uVar2 + 1, 0xff < uVar2)) {
      return 0;
    }
  }
  FUN_0044a580(local_100,&DAT_0099fadc,s_DEFEAT_0099f8e8);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 1;
  }
  FUN_0044a580(local_100,&DAT_0099fadc,s_BLOCKING_0099f8f0);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 2;
  }
  FUN_0044a580(local_100,&DAT_0099fadc,s_BLOCKED_0099f8fc);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 3;
  }
  FUN_0044a580(local_100,&DAT_0099fadc,s_HEALED_0099f904);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 6;
  }
  uVar3 = FUN_0044a670(s_SLIDE_0099f90c);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 4;
  }
  uVar3 = FUN_0044a670(&DAT_0099f914);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 7;
  }
  uVar3 = FUN_0044a670(s_REVIVE_0099f91c);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 9;
  }
  uVar3 = FUN_0044a670(s_AVOID_0099f924);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 8;
  }
  uVar3 = FUN_0044a670(s_SIGHT_IN_0099f92c);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 10;
  }
  uVar3 = FUN_0044a670(s_SIGHT_OUT_0099f938);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0xb;
  }
  uVar3 = FUN_0044a670(s_PERSUIT_IN_0099f944);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0xc;
  }
  uVar3 = FUN_0044a670(s_PERSUIT_OUT_0099f950);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0xd;
  }
  uVar3 = FUN_0044a670(s_MELEE_ATTACK_IN_0099f95c);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0xe;
  }
  uVar3 = FUN_0044a670(s_MELEE_ATTACK_OUT_0099f96c);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0xf;
  }
  uVar3 = FUN_0044a670(s_RANGE_ATTACK_IN_0099f980);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0x10;
  }
  uVar3 = FUN_0044a670(s_RANGE_ATTACK_OUT_0099f990);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0x11;
  }
  uVar3 = FUN_0044a670(s_MASTER_UNDER_ATTACK_0099f9a4);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0x12;
  }
  uVar3 = FUN_0044a670(s_MASTER_DEFEAT_0099f9b8);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0x13;
  }
  uVar3 = FUN_0044a670(s_MASTER_BLOCKING_0099f9c8);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0x14;
  }
  uVar3 = FUN_0044a670(s_MASTER_BLOCKED_0099f9d8);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0x15;
  }
  uVar3 = FUN_0044a670(s_MASTER_SLIDE_0099f9e8);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0x16;
  }
  uVar3 = FUN_0044a670(s_MASTER_FOLLOW_RANGE_0099f9f8);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0x17;
  }
  uVar3 = FUN_0044a670(s_MASTER_WARP_RANGE_0099fa0c);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0x18;
  }
  uVar3 = FUN_0044a670(s_COMPULSION_UNDERATTACK_0099fa20);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 != '\0') {
    return 0x19;
  }
  uVar3 = FUN_0044a670(s_COMPULSION_STOP_0099fa38);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 == '\0') {
    uVar3 = FUN_0044a670(s_MASTER_ASSIST_0099fa48);
    cVar1 = FUN_0044a440(uVar3);
    return (-(uint)(cVar1 != '\0') & 0xfffffffe) + 0x1d;
  }
  return 0x1a;
}


// ==== FUN_0044d580 @ 0x0044d580 ====

int FUN_0044d580(undefined1 param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  char local_100 [256];
  
  FUN_0044a580(local_100,&DAT_0099fadc,&DAT_0099fa58);
  uVar2 = 0;
  while ((&param_1)[uVar2] == local_100[uVar2]) {
    if (((&param_1)[uVar2] == '\0') || (uVar2 = uVar2 + 1, 0xff < uVar2)) {
      return 0;
    }
  }
  FUN_0044a580(local_100,&DAT_0099fadc,&DAT_0099fa60);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 1;
  }
  FUN_0044a580(local_100,&DAT_0099fadc,s_UNCARING_0099fa68);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 2;
  }
  FUN_0044a580(local_100,&DAT_0099fadc,s_ANNOYED_0099fa74);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 3;
  }
  FUN_0044a580(local_100,&DAT_0099fadc,&DAT_0099fa7c);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 == '\0') {
    uVar3 = FUN_0044a670(s_BERSERK_0099fa84);
    cVar1 = FUN_0044a440(uVar3);
    return 6 - (uint)(cVar1 != '\0');
  }
  return 4;
}


// ==== FUN_0044d6e0 @ 0x0044d6e0 ====

int FUN_0044d6e0(undefined1 param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  char local_100 [256];
  
  FUN_0044a580(local_100,&DAT_0099fadc,s_AVOID_0099fa8c);
  uVar2 = 0;
  while ((&param_1)[uVar2] == local_100[uVar2]) {
    if (((&param_1)[uVar2] == '\0') || (uVar2 = uVar2 + 1, 0xff < uVar2)) {
      return 0;
    }
  }
  FUN_0044a580(local_100,&DAT_0099fadc,s_EXPLORE_0099fa94);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 1;
  }
  FUN_0044a580(local_100,&DAT_0099fadc,s_PERSUIT_0099fa9c);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 2;
  }
  FUN_0044a580(local_100,&DAT_0099fadc,s_RANGE_ATTACK_0099faa4);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 3;
  }
  FUN_0044a580(local_100,&DAT_0099fadc,s_MELEE_ATTACK_0099fab4);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 4;
  }
  uVar3 = FUN_0044a670(s_COMEBACK_0099fac4);
  cVar1 = FUN_0044a440(uVar3);
  if (cVar1 == '\0') {
    uVar3 = FUN_0044a670(s_CALLTEAM_0099fad0);
    cVar1 = FUN_0044a440(uVar3);
    return (-(uint)(cVar1 != '\0') & 0xfffffffe) + 8;
  }
  return 5;
}


// ==== FUN_0044d870 @ 0x0044d870 ====

void FUN_0044d870(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  undefined *unaff_EDI;
  uint uVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint auStackY_37c [61];
  undefined4 uStackY_288;
  uint *puStackY_284;
  undefined **ppuStackY_280;
  int *piStackY_27c;
  undefined4 uStackY_278;
  undefined4 uStackY_274;
  undefined4 uStackY_270;
  undefined4 uStackY_26c;
  int *piStackY_268;
  undefined *puStackY_264;
  undefined *puStackY_260;
  uint uStackY_25c;
  undefined4 uVar11;
  uint uStack_244;
  void *local_240;
  char acStack_23c [8];
  undefined4 auStack_234 [4];
  undefined1 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  int aiStack_124 [64];
  void *pvStack_24;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0097bbfe;
  pvStack_14 = ExceptionList;
  auStack_234[3] = param_2;
  local_224 = 0x2c;
  local_220 = 0xff;
  local_21c = 0;
  ExceptionList = &pvStack_14;
  piVar2 = (int *)(**(code **)(*DAT_00b5a6f0 + 4))();
  uStackY_25c = 0x44d8cb;
  local_240 = operator_new(0xc);
  puStack_10 = (undefined1 *)0x0;
  if (local_240 == (void *)0x0) {
    local_240 = (void *)0x0;
  }
  else {
    local_240 = (void *)FUN_004566d0();
  }
  puStack_10 = (undefined1 *)0xffffffff;
  iVar3 = (**(code **)(*piVar2 + 4))();
  if (iVar3 < 2) {
LAB_0044daf0:
    uStackY_25c = 0x44dafc;
    (**(code **)(*DAT_00b5a6f0 + 8))();
    uStackY_25c = uStack_244;
    puStackY_260 = (undefined *)param_1;
    puStackY_264 = (undefined *)0x44db10;
    (**(code **)(*DAT_00b5a6f4 + 4))();
    ExceptionList = pvStack_24;
    return;
  }
  do {
    uVar11 = 0;
    puStackY_260 = (undefined *)0x44d91f;
    uStackY_25c = 1;
    pcVar4 = (char *)(**(code **)(*piVar2 + 0xc))();
    puStackY_260 = &DAT_0099f8d5;
    piStackY_268 = aiStack_124;
    puStackY_264 = &DAT_0099fadc;
    uStackY_26c = 0x44d938;
    FUN_0044a580();
    uVar8 = 0;
    iVar3 = (int)aiStack_124 - (int)pcVar4;
    while (*pcVar4 == pcVar4[iVar3]) {
      if (*pcVar4 == '\0') goto LAB_0044dad6;
      uVar8 = uVar8 + 1;
      pcVar4 = pcVar4 + 1;
      if (0xff < uVar8) goto LAB_0044dad6;
    }
    puStackY_260 = (undefined *)0x0;
    piStackY_268 = (int *)0x44d978;
    puStackY_264 = unaff_EDI;
    puVar5 = (undefined4 *)(**(code **)(*piVar2 + 0xc))();
    puVar6 = puVar5;
    puVar9 = auStack_234 + 2;
    for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar7 = auStackY_37c + 6;
    for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    auStackY_37c[5] = 0x44d9a2;
    local_240 = (void *)FUN_0044d070();
    uStackY_26c = uVar11;
    piStackY_268 = (int *)0x1;
    uStackY_270 = 0x44d9b4;
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    uVar8 = 0;
    do {
      cVar1 = ((char *)((int)auStack_234 + uVar8))[iVar3 - (int)auStack_234];
      *(char *)((int)auStack_234 + uVar8) = cVar1;
      if (cVar1 == '\0') goto LAB_0044d9dd;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x100);
    auStack_234[0]._0_1_ = 0;
LAB_0044d9dd:
    puVar5 = auStack_234;
    puVar7 = auStackY_37c + 4;
    for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    auStackY_37c[3] = 0x44d9ff;
    FUN_0044d580();
    uStackY_270 = 2;
    uStackY_274 = puStackY_260;
    uStackY_278 = 0x44da11;
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    uVar8 = 0;
    do {
      cVar1 = (acStack_23c + uVar8)[iVar3 - (int)acStack_23c];
      acStack_23c[uVar8] = cVar1;
      if (cVar1 == '\0') goto LAB_0044da3d;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x100);
    acStack_23c[0] = '\0';
LAB_0044da3d:
    pcVar4 = acStack_23c;
    puVar7 = auStackY_37c + 2;
    for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      puVar7 = puVar7 + 1;
    }
    auStackY_37c[1] = 0x44da5f;
    uStackY_25c = FUN_0044d580();
    uStackY_278 = 3;
    piStackY_27c = piStackY_268;
    ppuStackY_280 = (undefined **)0x44da71;
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    uVar8 = 0;
    do {
      cVar1 = (acStack_23c + (uVar8 - 8))[iVar3 - (int)&uStack_244];
      acStack_23c[uVar8 - 8] = cVar1;
      if (cVar1 == '\0') goto LAB_0044da9d;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x100);
    uStack_244 = uStack_244 & 0xffffff00;
LAB_0044da9d:
    puVar7 = &uStack_244;
    puVar10 = auStackY_37c;
    for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    puStackY_260 = (undefined *)FUN_0044d6e0();
    ppuStackY_280 = &puStackY_264;
    puStackY_284 = &uStackY_25c;
    uStackY_288 = 0x44dad6;
    (**(code **)(*piStackY_268 + 4))();
LAB_0044dad6:
    unaff_EDI = unaff_EDI + 1;
    puStackY_260 = (undefined *)0x44dae8;
    iVar3 = (**(code **)(*piVar2 + 4))();
    if (iVar3 <= (int)unaff_EDI) goto LAB_0044daf0;
  } while( true );
}


// ==== FUN_0044db30 @ 0x0044db30 ====

void FUN_0044db30(byte param_1)

{
  void *in_ECX;
  
  FUN_0044d050();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044db50 @ 0x0044db50 ====

void FUN_0044db50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fafc;
  return;
}


// ==== FUN_0044db60 @ 0x0044db60 ====

void FUN_0044db60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fafc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044db80 @ 0x0044db80 ====

void FUN_0044db80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fb0c;
  return;
}


// ==== FUN_0044db90 @ 0x0044db90 ====

void FUN_0044db90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fb24;
  return;
}


// ==== FUN_0044dba0 @ 0x0044dba0 ====

void FUN_0044dba0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fb7c;
  return;
}


// ==== FUN_0044dbb0 @ 0x0044dbb0 ====

void FUN_0044dbb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fb0c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044dbd0 @ 0x0044dbd0 ====

void FUN_0044dbd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fb24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044dbf0 @ 0x0044dbf0 ====

void FUN_0044dbf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fb7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044dc10 @ 0x0044dc10 ====

undefined4 FUN_0044dc10(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_0044dc40 @ 0x0044dc40 ====

void FUN_0044dc40(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bc18;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099fb9c;
  DAT_00b5a6f4 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
  (**(code **)(*(int *)in_ECX[2] + 0x20))();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_0099fafc;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0044dce0 @ 0x0044dce0 ====

void FUN_0044dce0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar1 = unaff_ESI;
  puVar1[1] = unaff_retaddr;
  (**(code **)(**(int **)(in_ECX + 8) + 0x24))(puVar1);
  return;
}


// ==== FUN_0044dd10 @ 0x0044dd10 ====

void FUN_0044dd10(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097bc40;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099fb9c;
  pvVar2 = operator_new(0x4e38);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0044de30();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x8ccc);
  local_4._0_1_ = 2;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0044e3e0(*puVar1);
  }
  in_ECX[2] = uVar3;
  local_4 = (uint)local_4._1_3_ << 8;
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0;
  puVar4[1] = 0;
  (**(code **)(*(int *)in_ECX[2] + 0x24))(puVar4);
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a6f4 = (undefined4 *)0x0;
    ExceptionList = unaff_EBX;
    return;
  }
  DAT_00b5a6f4 = in_ECX;
  ExceptionList = unaff_EBX;
  return;
}


// ==== FUN_0044ddf0 @ 0x0044ddf0 ====

void FUN_0044ddf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fb94;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,1000,FUN_006ef6d0);
  return;
}


// ==== FUN_0044de10 @ 0x0044de10 ====

void FUN_0044de10(byte param_1)

{
  void *in_ECX;
  
  FUN_0044ddf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044de30 @ 0x0044de30 ====

void FUN_0044de30(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bc58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099fbac;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_0099fb94;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,1000,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x138a] = 0;
  in_ECX[0x138a] = in_ECX[0x138a] + 1000;
  in_ECX[0x138d] = in_ECX + 2;
  in_ECX[0x138b] = 0;
  in_ECX[0x138c] = 0;
  iVar2 = 999;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[4999] = 0;
  in_ECX[5000] = 0;
  in_ECX[0x1389] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044dee0 @ 0x0044dee0 ====

void FUN_0044dee0(byte param_1)

{
  void *in_ECX;
  
  FUN_0044df00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044df00 @ 0x0044df00 ====

void FUN_0044df00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bc83;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099fbac;
  local_4 = 1;
  if ((void *)in_ECX[0x138c] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_0099fb94;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,1000,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_0099fb0c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x138c]);
  return;
}


// ==== FUN_0044df80 @ 0x0044df80 ====

void * FUN_0044df80(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097bc9b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x4e34);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x4e2c) = *(int *)(in_ECX + 0x4e2c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x4e30);
      *(void **)(in_ECX + 0x4e30) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x4e34) = *(undefined4 *)((int)param_2 + 8);
    }
    *(undefined4 *)((int)param_2 + 8) = 0;
    *(int *)((int)param_2 + 0x10) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099fbc0,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0044e060 @ 0x0044e060 ====

undefined4 FUN_0044e060(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099fbc0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x4e34);
    *(int *)(in_ECX + 0x4e2c) = *(int *)(in_ECX + 0x4e2c) + -1;
    *(int *)(in_ECX + 0x4e34) = param_2;
  }
  return 0;
}


// ==== FUN_0044e0e0 @ 0x0044e0e0 ====

void FUN_0044e0e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0044dc40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044e100 @ 0x0044e100 ====

void FUN_0044e100(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fc38;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x24,1000,FUN_006ef6d0);
  return;
}


// ==== FUN_0044e120 @ 0x0044e120 ====

void FUN_0044e120(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bcc3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099fc40;
  local_4 = 1;
  if ((void *)in_ECX[0x232c] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_0099fc38;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x24,1000,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_0099fb7c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x232c]);
  return;
}


// ==== FUN_0044e1a0 @ 0x0044e1a0 ====

undefined4 FUN_0044e1a0(void)

{
  return 1000;
}


// ==== FUN_0044e1b0 @ 0x0044e1b0 ====

undefined4 FUN_0044e1b0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x20) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099fbc0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x20);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x20);
    }
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(in_ECX + 0x8cb4);
    *(int *)(in_ECX + 0x8cac) = *(int *)(in_ECX + 0x8cac) + -1;
    *(int *)(in_ECX + 0x8cb4) = param_2;
  }
  return 0;
}


// ==== FUN_0044e230 @ 0x0044e230 ====

undefined4 * FUN_0044e230(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[8] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099fbc0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[8] = param_2[8] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x8cb4);
  *(int *)(in_ECX + 0x8cac) = *(int *)(in_ECX + 0x8cac) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x24);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[7] = *(undefined4 *)(in_ECX + 0x8cb0);
    *(undefined4 **)(in_ECX + 0x8cb0) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x8cb4) = puVar2[6];
  }
  puVar2[6] = 0;
  puVar2[8] = param_1;
  return puVar2;
}


// ==== FUN_0044e2f0 @ 0x0044e2f0 ====

void FUN_0044e2f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0044e100();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044e310 @ 0x0044e310 ====

void FUN_0044e310(byte param_1)

{
  void *in_ECX;
  
  FUN_0044e120();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044e330 @ 0x0044e330 ====

void FUN_0044e330(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bcd8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099fc40;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_0099fc38;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x24,1000,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x232a] = 0;
  in_ECX[0x232a] = in_ECX[0x232a] + 1000;
  in_ECX[0x232d] = in_ECX + 2;
  in_ECX[0x232b] = 0;
  in_ECX[0x232c] = 0;
  iVar2 = 999;
  puVar1 = in_ECX;
  do {
    puVar1[8] = puVar1 + 0xb;
    puVar1[9] = 0;
    puVar1[10] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 9;
  } while (iVar2 != 0);
  in_ECX[8999] = 0;
  in_ECX[9000] = 0;
  in_ECX[0x2329] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044e3e0 @ 0x0044e3e0 ====

void FUN_0044e3e0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bd03;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099fc5c;
  FUN_0044e330();
  in_ECX[3] = param_1;
  local_4 = CONCAT31(local_4._1_3_,1);
  puVar1 = (undefined4 *)(**(code **)(in_ECX[5] + 0xc))(1,0);
  in_ECX[1] = puVar1;
  *puVar1 = 0;
  *(undefined4 *)(in_ECX[1] + 8) = in_ECX[1];
  *(undefined4 *)(in_ECX[1] + 0xc) = in_ECX[1];
  *(undefined4 *)(in_ECX[1] + 0x10) = in_ECX[1];
  *(undefined1 *)(in_ECX[1] + 0x14) = 1;
  in_ECX[2] = in_ECX[1];
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_0044e470 @ 0x0044e470 ====

void FUN_0044e470(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    FUN_0044e490(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_0044e490 @ 0x0044e490 ====

void FUN_0044e490(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != *(int *)(in_ECX + 4)) {
    FUN_0044e490(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != *(int *)(in_ECX + 4)) {
    FUN_0044e490(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0044e4d0 @ 0x0044e4d0 ====

void FUN_0044e4d0(undefined4 *param_1)

{
  int *in_ECX;
  
  FUN_0044e4f0(*param_1);
  (**(code **)(*in_ECX + 0x3c))(param_1);
  return;
}


// ==== FUN_0044e4f0 @ 0x0044e4f0 ====

void FUN_0044e4f0(void *param_1)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,param_1);
    return;
  }
  if (param_1 == (void *)0x0) {
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_0044e520 @ 0x0044e520 ====

void FUN_0044e520(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (*(int *)(param_1 + 0xc) == iVar1) {
    iVar3 = *(int *)(param_1 + 0x10);
    while ((iVar2 = iVar3, iVar2 != iVar1 && (*(int *)(iVar2 + 0xc) == param_1))) {
      param_1 = iVar2;
      iVar3 = *(int *)(iVar2 + 0x10);
    }
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    if (iVar3 != iVar1) {
      do {
        iVar3 = *(int *)(iVar3 + 8);
      } while (iVar3 != iVar1);
      return;
    }
  }
  return;
}


// ==== FUN_0044e570 @ 0x0044e570 ====

void FUN_0044e570(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (*(int *)(param_1 + 8) == iVar1) {
    iVar3 = *(int *)(param_1 + 0x10);
    while ((iVar2 = iVar3, iVar2 != iVar1 && (*(int *)(iVar2 + 8) == param_1))) {
      param_1 = iVar2;
      iVar3 = *(int *)(iVar2 + 0x10);
    }
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 0xc);
    if (iVar3 != iVar1) {
      do {
        iVar3 = *(int *)(iVar3 + 0xc);
      } while (iVar3 != iVar1);
      return;
    }
  }
  return;
}


// ==== FUN_0044e5c0 @ 0x0044e5c0 ====

void FUN_0044e5c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    FUN_0044e5e0(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_0044e5e0 @ 0x0044e5e0 ====

void FUN_0044e5e0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != *(int *)(in_ECX + 4)) {
    FUN_0044e5e0(param_1[2]);
  }
  if (param_1[3] != *(int *)(in_ECX + 4)) {
    FUN_0044e5e0(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0044e650 @ 0x0044e650 ====

undefined4 * FUN_0044e650(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  uint *unaff_EBX;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)(**(code **)(*(int *)(in_ECX + 0x14) + 0xc))(1,0);
  *puVar2 = unaff_EBX;
  puVar2[2] = *(undefined4 *)(in_ECX + 4);
  puVar2[3] = *(undefined4 *)(in_ECX + 4);
  puVar2[4] = *(undefined4 *)(in_ECX + 4);
  *(undefined1 *)(puVar2 + 5) = 0;
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if (*(undefined4 **)(in_ECX + 8) == puVar1) {
    *(undefined4 **)(in_ECX + 8) = puVar2;
    FUN_0044b660(puVar2);
    return (undefined4 *)0x0;
  }
  puVar3 = *(undefined4 **)(in_ECX + 8);
  while( true ) {
    while (*unaff_EBX < *(uint *)*puVar3) {
      if ((undefined4 *)puVar3[2] == puVar1) {
        puVar2[4] = puVar3;
        puVar3[2] = puVar2;
        FUN_0044b660(puVar2);
        return (undefined4 *)0x0;
      }
      puVar3 = (undefined4 *)puVar3[2];
    }
    if (*unaff_EBX <= *(uint *)*puVar3) break;
    if ((undefined4 *)puVar3[3] == puVar1) {
      puVar2[4] = puVar3;
      puVar3[3] = puVar2;
      FUN_0044b660(puVar2);
      return (undefined4 *)0x0;
    }
    puVar3 = (undefined4 *)puVar3[3];
  }
  (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,puVar2);
  return puVar3;
}


// ==== FUN_0044e710 @ 0x0044e710 ====

int FUN_0044e710(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(*(int *)(iVar1 + 0x10) + 8);
  if (*(char *)(iVar2 + 0x14) == '\0') {
    *(undefined1 *)(iVar2 + 0x14) = 1;
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x10);
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x14) = 1;
    *(undefined1 *)(iVar1 + 0x14) = 0;
    return iVar1;
  }
  if (param_1 == *(int *)(iVar1 + 8)) {
    FUN_00457070(iVar1);
    param_1 = iVar1;
  }
  iVar1 = *(int *)(param_1 + 0x10);
  *(undefined1 *)(iVar1 + 0x14) = 1;
  iVar1 = *(int *)(iVar1 + 0x10);
  *(undefined1 *)(iVar1 + 0x14) = 0;
  FUN_00457010(iVar1);
  return param_1;
}


// ==== FUN_0044e770 @ 0x0044e770 ====

void FUN_0044e770(byte param_1)

{
  void *in_ECX;
  
  FUN_0044e790();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044e790 @ 0x0044e790 ====

void FUN_0044e790(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097bd03;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099fc5c;
  local_4 = 1;
  if (in_ECX[2] != in_ECX[1]) {
    FUN_0044e5e0(in_ECX[2]);
    in_ECX[2] = in_ECX[1];
  }
  FUN_0054e140();
  local_4 = local_4 & 0xffffff00;
  FUN_0044e120();
  *in_ECX = &PTR_FUN_0099fb24;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044e800 @ 0x0044e800 ====

void FUN_0044e800(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0044e805. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0044e810 @ 0x0044e810 ====

void FUN_0044e810(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0044e815. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0044e820 @ 0x0044e820 ====

void FUN_0044e820(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0044e825. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0044e830 @ 0x0044e830 ====

void FUN_0044e830(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0044e835. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_0044e840 @ 0x0044e840 ====

void FUN_0044e840(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bd43;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099fe88;
  pvVar1 = operator_new(0xa18);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0044e9d0();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a704 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a704 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044e8d0 @ 0x0044e8d0 ====

void FUN_0044e8d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bd55;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099fe88;
  DAT_00b5a704 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_0099fe38;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044e930 @ 0x0044e930 ====

void FUN_0044e930(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fe50;
  return;
}


// ==== FUN_0044e940 @ 0x0044e940 ====

void FUN_0044e940(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fe50;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044e970 @ 0x0044e970 ====

void FUN_0044e970(void)

{
  FUN_004572c0();
  return;
}


// ==== FUN_0044e980 @ 0x0044e980 ====

void FUN_0044e980(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fe38;
  return;
}


// ==== FUN_0044e990 @ 0x0044e990 ====

void FUN_0044e990(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fe38;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044e9b0 @ 0x0044e9b0 ====

void FUN_0044e9b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099fe68;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,(_func_void_void_ptr *)&LAB_0044e960);
  return;
}


// ==== FUN_0044e9d0 @ 0x0044e9d0 ====

void FUN_0044e9d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bd18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099fe70;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_0099fe68;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x14,0x80,FUN_0044e970,(_func_void_void_ptr *)&LAB_0044e960);
  in_ECX[0x282] = 0;
  in_ECX[0x282] = in_ECX[0x282] + 0x80;
  in_ECX[0x285] = in_ECX + 2;
  in_ECX[0x283] = 0;
  in_ECX[0x284] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x27f] = 0;
  in_ECX[0x280] = 0;
  in_ECX[0x281] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044ea80 @ 0x0044ea80 ====

void FUN_0044ea80(byte param_1)

{
  void *in_ECX;
  
  FUN_0044e9b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044eaa0 @ 0x0044eaa0 ====

void * FUN_0044eaa0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097bd79;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0xa14);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xa0c) = *(int *)(in_ECX + 0xa0c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_004572c0();
      }
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0xa10);
      *(void **)(in_ECX + 0xa10) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0xa14) = *(undefined4 *)((int)param_2 + 8);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0x10) = param_1;
    *(undefined4 *)((int)param_2 + 8) = 0;
    FUN_00457280();
  }
  else {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099fea0,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0044ebc0 @ 0x0044ebc0 ====

undefined4 FUN_0044ebc0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_s_0099fea0,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    FUN_00457290();
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0xa14);
    *(int *)(in_ECX + 0xa0c) = *(int *)(in_ECX + 0xa0c) + -1;
    *(int *)(in_ECX + 0xa14) = param_2;
  }
  return 0;
}


// ==== FUN_0044ec50 @ 0x0044ec50 ====

void FUN_0044ec50(byte param_1)

{
  void *in_ECX;
  
  FUN_0044ec70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044ec70 @ 0x0044ec70 ====

void FUN_0044ec70(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097bda9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099fe70;
  local_4 = 1;
  if (in_ECX[0x283] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099fd20,
                         s_d__usa_24_0_1_2__develop_share_s_0099fcb8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 6;
  iVar3 = 0x80;
  do {
    if (*piVar2 != 0) {
      local_10c[0] = 0;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099fda0,
                           s_d__usa_24_0_1_2__develop_share_s_0099fd38,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 5;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x284];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_0099fe68;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,(_func_void_void_ptr *)&LAB_0044e960);
    *in_ECX = &PTR_FUN_0099fe50;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0x10) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099fe20,
                         s_d__usa_24_0_1_2__develop_share_s_0099fdb8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00457270();
  _free(_Memory);
  return;
}


// ==== FUN_0044edb0 @ 0x0044edb0 ====

void FUN_0044edb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0044e8d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044edd0 @ 0x0044edd0 ====

void FUN_0044edd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ff0c;
  return;
}


// ==== FUN_0044ede0 @ 0x0044ede0 ====

void FUN_0044ede0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ff0c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044ee00 @ 0x0044ee00 ====

int FUN_0044ee00(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == param_2) {
    return param_1;
  }
  iVar1 = FUN_00797ac0(0x1000);
  uVar2 = FUN_00797ac0(0x1000);
  uVar3 = FUN_00797ac0(0x100);
  return (uVar3 & 0xff | iVar1 << 0x14 | (uVar2 & 0xfff) << 8) % (uint)(param_2 - param_1) + param_1
  ;
}


// ==== FUN_0044ee60 @ 0x0044ee60 ====

uint FUN_0044ee60(int *param_1,int *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort in_FPUControlWord;
  float10 fVar10;
  
  piVar5 = (int *)(**(code **)(*param_2 + 0xc))();
  iVar6 = (**(code **)(*param_2 + 0x14))();
  fVar10 = (float10)(**(code **)(*piVar5 + 0x9c))();
  uVar9 = (uint)ROUND((float10)*(float *)(iVar6 + 0x18) - fVar10);
  piVar5 = (int *)(**(code **)(*param_2 + 0xc))();
  iVar6 = (**(code **)(*param_2 + 0x14))();
  fVar10 = (float10)(**(code **)(*piVar5 + 0x98))();
  uVar1 = (uint)ROUND((float10)*(float *)(iVar6 + 0x1c) - fVar10);
  piVar5 = (int *)(**(code **)(*param_2 + 0xc))();
  iVar6 = (**(code **)(*param_2 + 0x14))();
  fVar10 = (float10)(**(code **)(*piVar5 + 0x9c))();
  uVar2 = (uint)ROUND(fVar10 + (float10)*(float *)(iVar6 + 0x18));
  piVar5 = (int *)(**(code **)(*param_2 + 0xc))();
  iVar6 = (**(code **)(*param_2 + 0x14))();
  fVar10 = (float10)(**(code **)(*piVar5 + 0x98))();
  uVar3 = (uint)ROUND(fVar10 + (float10)*(float *)(iVar6 + 0x1c));
  iVar6 = (**(code **)(*param_1 + 0x14))();
  fVar4 = *(float *)(iVar6 + 0x18);
  iVar6 = (**(code **)(*param_1 + 0x14))();
  param_2 = (int *)(uint)(in_FPUControlWord | 0xc00);
  if (uVar9 <= uVar2) {
    iVar8 = (int)ROUND(fVar4) - uVar9;
    param_2 = (int *)uVar9;
    do {
      if (uVar1 <= uVar3) {
        iVar7 = (int)ROUND(*(float *)(iVar6 + 0x1c)) - uVar1;
        uVar9 = uVar1;
        do {
          if ((uint)(iVar7 * iVar7 + iVar8 * iVar8) <= (uint)(param_3 * param_3)) {
            return CONCAT31((int3)((uint)iVar7 >> 8),1);
          }
          uVar9 = uVar9 + 1;
          iVar7 = iVar7 + -1;
        } while (uVar9 <= uVar3);
      }
      param_2 = (int *)((int)param_2 + 1);
      iVar8 = iVar8 + -1;
    } while (param_2 <= uVar2);
  }
  return (uint)param_2 & 0xffffff00;
}


// ==== FUN_0044f040 @ 0x0044f040 ====

uint FUN_0044f040(uint param_1,uint param_2)

{
  if (param_2 <= param_1) {
    return 100;
  }
  if (param_2 < 10000) {
    return (param_1 * 100) / param_2;
  }
  return ((param_1 / 100) * 100) / (param_2 / 100);
}


// ==== FUN_0044f0f0 @ 0x0044f0f0 ====

void FUN_0044f0f0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097bdd3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_0099ff38;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00457310();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  puVar3 = operator_new(0x58);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_0099ff30;
    puVar3[0x15] = 0;
  }
  in_ECX[3] = puVar3;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a804 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a804 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0044f1b0 @ 0x0044f1b0 ====

void FUN_0044f1b0(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_0044f820(param_1);
  if (piVar1 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0044f1cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x34))();
  return;
}


// ==== FUN_0044f1e0 @ 0x0044f1e0 ====

void FUN_0044f1e0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097bde5;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_0099ff38;
  DAT_00b5a804 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_0099ff0c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0044f250 @ 0x0044f250 ====

void FUN_0044f250(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_retaddr;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar1 = (int *)FUN_0044f820(param_1);
  if (piVar1 != (int *)0x0) {
    iVar3 = *param_2;
    if ((((iVar3 == 0) || (iVar3 == 1)) || (iVar3 == 2)) ||
       (((iVar3 == 3 || (iVar3 == 4)) || ((iVar3 == 5 || ((iVar3 == 0x1c || (iVar3 == 7)))))))) {
      (**(code **)(*piVar1 + 0x34))(1);
      piVar2 = (int *)FUN_0044f820(param_2[2]);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x34))(1);
      }
    }
    iVar3 = (**(code **)(*piVar1 + 0x28))();
    if (iVar3 == 0) {
      piVar1 = (int *)FUN_0044f820(param_1);
      if (piVar1 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar1 + 0x10))();
        iVar3 = *(int *)(iVar3 + 8);
        iVar5 = FUN_0044f820(iVar3);
        if ((iVar5 != 0) && (iVar3 != 0)) {
          FUN_00450770(iVar3,param_2[2],param_2);
        }
      }
      piVar1 = (int *)FUN_0044f820(param_2[2]);
      if (piVar1 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar1 + 0x10))();
        iVar3 = *(int *)(iVar3 + 8);
        iVar5 = FUN_0044f820(iVar3);
        if ((iVar5 != 0) && (iVar3 != 0)) {
          FUN_00450770(iVar3,param_1,param_2);
        }
      }
      FUN_00450ae0(param_1,param_2);
    }
    else {
      if ((*param_2 == 0x1c) &&
         (((piVar2 = (int *)(**(code **)(*piVar1 + 0x30))(), *piVar2 == 1 ||
           (piVar2 = (int *)(**(code **)(*piVar1 + 0x30))(), *piVar2 == 0xc)) ||
          (piVar2 = (int *)(**(code **)(*piVar1 + 0x30))(), *piVar2 == 0x11)))) {
        puVar4 = (undefined4 *)(**(code **)(*piVar1 + 0x30))();
        uStack_8 = *puVar4;
        uStack_4 = 0;
        (**(code **)(*piVar1 + 0x2c))(&uStack_8);
        piVar2 = (int *)(**(code **)(*piVar1 + 0x20))();
        (**(code **)(*piVar2 + 8))(param_2[1],piVar1);
        return;
      }
      iVar3 = FUN_0044fcf0(param_2[2]);
      (**(code **)(*piVar1 + 4))(param_2);
      if (iVar3 != 0) {
        FUN_00450770(iVar3,unaff_retaddr,param_2);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0044f3f0 @ 0x0044f3f0 ====

void FUN_0044f3f0(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar2 != (int *)0x0) {
    for (piVar3 = (int *)(**(code **)(*piVar2 + 8))(); piVar3 != (int *)0x0;
        piVar3 = (int *)(**(code **)(*piVar2 + 0x48))(piVar3)) {
      piVar1 = *(int **)(*piVar3 + 4);
      if (piVar1 != (int *)0x0) {
        uVar4 = (**(code **)(*piVar1 + 0xc))();
        (**(code **)(*DAT_00b5a808 + 4))(param_1,uVar4);
        FUN_00450ed0(piVar1);
      }
    }
  }
  return;
}


// ==== FUN_0044f460 @ 0x0044f460 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044f460(float param_1)

{
  int *piVar1;
  uint uVar2;
  float fVar3;
  int iVar4;
  char cVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  int in_ECX;
  int iVar12;
  uint uStack_10;
  
  iVar4 = (int)param_1;
  FUN_0044f3f0(param_1);
  iVar12 = (int)param_1 - *(int *)(in_ECX + 0x18);
  piVar6 = (int *)(**(code **)(*DAT_00b5a6fc + 8))();
  iVar7 = (**(code **)(*piVar6 + 0x14))();
  param_1 = (float)iVar7;
  if (iVar7 < 0) {
    param_1 = param_1 + _DAT_0099d104;
  }
  if (param_1 < DAT_0099ff58) {
    param_1 = DAT_0099ff58;
  }
  fVar3 = (float)iVar12;
  if (iVar12 < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  uStack_10 = (uint)ROUND(fVar3 * param_1 * DAT_0099d0ec);
  if (uStack_10 < 3) {
    uStack_10 = 3;
  }
  if ((*(int *)(in_ECX + 0x14) == 0) || (*(int *)(in_ECX + 0x10) == 0)) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    uVar8 = (**(code **)(*piVar6 + 8))();
    *(undefined4 *)(in_ECX + 0x10) = uVar8;
  }
  iVar7 = *(int *)(in_ECX + 0x10);
  param_1 = 0.0;
  while ((iVar7 != 0 && ((uint)param_1 <= uStack_10))) {
    piVar9 = *(int **)(in_ECX + 0x10);
    if (piVar9 != (int *)0x0) {
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + (int)param_1;
    }
    piVar1 = *(int **)(*piVar9 + 4);
    if (piVar1 == (int *)0x0) {
      iVar7 = (**(code **)(*piVar6 + 0x48))(piVar9);
    }
    else {
      piVar9 = (int *)(**(code **)(*piVar1 + 0x28))();
      iVar7 = (**(code **)(*piVar9 + 8))();
      if (iVar7 == 0) {
        iVar7 = (**(code **)(*piVar6 + 0x48))(*(undefined4 *)(in_ECX + 0x10));
      }
      else {
        piVar9 = (int *)(**(code **)(*piVar1 + 0x30))();
        if (*piVar9 == 0xe) {
          iVar7 = (**(code **)(*piVar6 + 0x48))(*(undefined4 *)(in_ECX + 0x10));
        }
        else {
          iVar7 = (**(code **)(*piVar1 + 0x48))();
          uVar2 = *(uint *)(iVar7 + 0x2c);
          if (uVar2 != 0) {
            iVar7 = (**(code **)(*piVar1 + 0x14))();
            uVar8 = *(undefined4 *)(iVar7 + 8);
            iVar7 = (**(code **)(*piVar1 + 0x14))();
            uVar10 = FUN_0044f040(uVar8,*(undefined4 *)(iVar7 + 0xc));
            if ((uVar10 & 0xff) <= uVar2) {
              piVar11 = (int *)(**(code **)(*piVar1 + 0xc))();
              piVar9 = DAT_00b5a708;
              iVar7 = *piVar1;
              uVar8 = (**(code **)(*piVar11 + 0x54))();
              uVar8 = (**(code **)(*piVar9 + 4))(6,iVar4,uVar8);
              (**(code **)(iVar7 + 0x1c))(uVar8);
            }
          }
          cVar5 = FUN_00450c00(iVar4,piVar1);
          if (cVar5 == '\x01') {
            piVar11 = (int *)(**(code **)(*piVar1 + 0xc))();
            piVar9 = DAT_00b5a708;
            iVar7 = *piVar1;
            uVar8 = (**(code **)(*piVar11 + 0x54))();
            uVar8 = (**(code **)(*piVar9 + 4))(7,iVar4,uVar8);
            (**(code **)(iVar7 + 0x1c))(uVar8);
          }
          cVar5 = FUN_00450ba0(iVar4,piVar1);
          if (cVar5 == '\0') {
            iVar7 = (**(code **)(*piVar6 + 0x48))(*(undefined4 *)(in_ECX + 0x10));
          }
          else {
            iVar7 = (**(code **)(*piVar1 + 0x14))();
            if (*(int *)(iVar7 + 4) == 2) {
              cVar5 = FUN_00450550(iVar4,piVar1);
              if (cVar5 == '\x01') {
                FUN_00450ca0(iVar4,piVar1);
              }
            }
            else {
              iVar7 = (**(code **)(*piVar1 + 0x14))();
              if (*(char *)(iVar7 + 0x28) == '\0') {
                FUN_0044fec0(iVar4,piVar1);
              }
              else {
                FUN_00450170(iVar4,piVar1);
              }
              iVar7 = (**(code **)(*piVar1 + 0x10))();
              iVar7 = *(int *)(iVar7 + 4);
              iVar12 = FUN_0044f820(iVar7);
              if ((iVar12 != 0) && (iVar7 != 0)) {
                FUN_004505c0(iVar4,iVar7,piVar1);
              }
            }
            piVar9 = (int *)(**(code **)(*piVar1 + 0x20))();
            (**(code **)(*piVar9 + 8))(iVar4,piVar1);
            iVar7 = (**(code **)(*piVar6 + 0x48))(*(undefined4 *)(in_ECX + 0x10));
            param_1 = (float)((int)param_1 + 1);
          }
        }
      }
    }
    *(int *)(in_ECX + 0x10) = iVar7;
  }
  *(int *)(in_ECX + 0x18) = iVar4;
  return;
}


// ==== FUN_0044f730 @ 0x0044f730 ====

void FUN_0044f730(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0099ff30;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0044f750 @ 0x0044f750 ====

bool FUN_0044f750(int *param_1,int *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    return false;
  }
  iVar3 = (**(code **)(*param_1 + 0x14))();
  fVar1 = *(float *)(iVar3 + 0x18);
  iVar3 = (**(code **)(*param_1 + 0x14))();
  fVar2 = *(float *)(iVar3 + 0x1c);
  iVar3 = (**(code **)(*param_2 + 0x14))();
  iVar4 = (int)ROUND(fVar1) - (int)ROUND(*(float *)(iVar3 + 0x18));
  iVar3 = (**(code **)(*param_2 + 0x14))();
  iVar3 = (int)ROUND(fVar2) - (int)*(float *)(iVar3 + 0x1c);
  return (uint)(iVar3 * iVar3 + iVar4 * iVar4) <= (uint)(param_3 * param_3);
}


// ==== FUN_0044f820 @ 0x0044f820 ====

undefined4 FUN_0044f820(undefined4 param_1)

{
  int *piVar1;
  undefined4 auStack_8 [2];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar1 != (int *)0x0) {
    auStack_8[0] = param_1;
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))(auStack_8);
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 4);
    }
  }
  return 0;
}


// ==== FUN_0044f860 @ 0x0044f860 ====

uint FUN_0044f860(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  
  if (param_1 == (int *)0x0) {
    return param_2;
  }
  iVar7 = *(int *)(DAT_00b5a7fc + 0x10);
  piVar4 = (int *)(**(code **)(*param_1 + 0xc))();
  iVar5 = (**(code **)(*piVar4 + 0x6c))();
  if (param_3 < (uint)(iVar5 + iVar7)) {
    return param_2;
  }
  puVar6 = (uint *)(**(code **)(*param_1 + 0x18))();
  uVar1 = *puVar6;
  iVar7 = (**(code **)(*param_1 + 0x18))();
  uVar2 = *(uint *)(DAT_00b5a7fc + 0xc);
  uVar3 = *(uint *)(iVar7 + 0x18);
  if (uVar2 < param_2) {
    uVar8 = param_2 - uVar2;
    if (uVar3 < uVar8) goto LAB_0044f8c7;
  }
  else {
    uVar8 = 0;
  }
  if (uVar3 != 0) {
    return uVar3;
  }
LAB_0044f8c7:
  if ((uVar1 < uVar8) || (uVar1 == 0)) {
    piVar4 = (int *)(**(code **)(*param_1 + 0xc))();
    (**(code **)(*piVar4 + 0x60))(param_2 - uVar2);
    piVar4 = (int *)(**(code **)(*param_1 + 0xc))();
    (**(code **)(*piVar4 + 0x68))(param_2);
    return param_2 - uVar2;
  }
  return uVar1;
}


// ==== FUN_0044f910 @ 0x0044f910 ====

undefined4 FUN_0044f910(float *param_1,float *param_2,float param_3,undefined4 param_4)

{
  float fVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  float *pfVar5;
  short sVar6;
  int iVar7;
  undefined4 local_14;
  
  if (param_3 < DAT_0099cdc8) {
    fVar1 = *param_2;
    pfVar5 = param_1;
  }
  else {
    fVar1 = *param_1;
    pfVar5 = param_2;
  }
  param_3 = (float)(int)*pfVar5;
  iVar7 = (int)fVar1 + 1;
  if ((int)param_3 < iVar7) {
    return 1;
  }
  while( true ) {
    sVar6 = (short)iVar7;
    param_4 = CONCAT22(param_4._2_2_,sVar6);
    uVar2 = FUN_00802534();
    param_4 = CONCAT22(uVar2,(undefined2)param_4);
    iVar4 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_4);
    if (*(char *)(iVar4 + 5) == '\0') {
      return 0;
    }
    uVar3 = FUN_00802534();
    local_14 = (float *)CONCAT22(uVar3,sVar6);
    param_3 = (float)local_14;
    iVar4 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_3);
    if (*(char *)(iVar4 + 5) == '\0') {
      return 0;
    }
    local_14 = (float *)CONCAT22(uVar2,sVar6 + -1);
    param_2 = local_14;
    iVar4 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_2);
    if (*(char *)(iVar4 + 5) == '\0') {
      return 0;
    }
    local_14 = (float *)CONCAT22(uVar3,sVar6 + -1);
    param_1 = local_14;
    iVar4 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_1);
    if (*(char *)(iVar4 + 5) == '\0') break;
    iVar7 = iVar7 + 1;
    if ((int)param_3 < iVar7) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0044fa70 @ 0x0044fa70 ====

undefined4 FUN_0044fa70(undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  short sVar6;
  undefined1 uStack00000000;
  undefined4 local_14;
  
  if (param_4 < DAT_0099cdc8) {
    uVar3 = FUN_00802534();
    uVar4 = FUN_00802534();
  }
  else {
    uVar3 = FUN_00802534();
    uVar4 = FUN_00802534();
  }
  param_4 = (float)(uVar4 & 0xffff);
  uVar3 = (uVar3 & 0xffff) + 1;
  if (uVar3 <= (uint)param_4) {
    do {
      uVar1 = FUN_00802534();
      sVar6 = (short)uVar3;
      param_3 = CONCAT22(sVar6,uVar1);
      iVar5 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_3);
      if (*(char *)(iVar5 + 5) == '\0') {
        return 0;
      }
      uVar2 = FUN_00802534();
      local_14 = CONCAT22(sVar6,uVar2);
      param_2 = local_14;
      iVar5 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_2);
      if (*(char *)(iVar5 + 5) == '\0') {
        return 0;
      }
      local_14 = CONCAT22(sVar6 + -1,uVar1);
      param_1 = local_14;
      iVar5 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_1);
      if (*(char *)(iVar5 + 5) == '\0') {
        return 0;
      }
      iVar5 = (**(code **)(*DAT_00b5a718 + 0x10))(&uStack00000000);
      if (*(char *)(iVar5 + 5) == '\0') {
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 <= (int)param_4);
  }
  return 1;
}


// ==== FUN_0044fbf0 @ 0x0044fbf0 ====

void FUN_0044fbf0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *param_2 - *param_1;
  fVar3 = param_2[1] - param_1[1];
  if (fVar1 <= 0.0) {
    fVar4 = 0.0 - fVar1;
  }
  else {
    fVar4 = fVar1;
  }
  if (fVar3 <= 0.0) {
    fVar2 = 0.0 - fVar3;
  }
  else {
    fVar2 = fVar3;
  }
  if (fVar2 <= fVar4) {
    FUN_0044f910();
    return;
  }
  FUN_0044fa70(param_1,param_2,fVar1,fVar3);
  return;
}


// ==== FUN_0044fc60 @ 0x0044fc60 ====

int FUN_0044fc60(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  iVar1 = FUN_0044f820(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a6fc + 8))();
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  piVar3 = (int *)(**(code **)(*piVar2 + 8))();
  iVar1 = 0;
joined_r0x0044fc95:
  do {
    if (piVar3 == (int *)0x0) {
      return iVar1;
    }
    piVar6 = *(int **)(*piVar3 + 4);
    if (piVar6 != (int *)0x0) {
      piVar4 = (int *)(**(code **)(*piVar6 + 0xc))();
      iVar5 = (**(code **)(*piVar4 + 0x54))();
      if (iVar5 != 0) {
        piVar6 = (int *)(**(code **)(*piVar6 + 0xc))();
        iVar5 = (**(code **)(*piVar6 + 0x54))();
        if (param_1 == iVar5) {
          iVar1 = iVar1 + 1;
        }
        piVar3 = (int *)(**(code **)(*piVar2 + 0x48))(piVar3);
        goto joined_r0x0044fc95;
      }
    }
    piVar3 = (int *)(**(code **)(*piVar2 + 0x48))(piVar3);
  } while( true );
}


// ==== FUN_0044fcf0 @ 0x0044fcf0 ====

uint FUN_0044fcf0(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)FUN_0044f820(param_1);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  uVar1 = *(uint *)(iVar3 + 8);
  iVar3 = FUN_0044f820(uVar1);
  return -(uint)(iVar3 != 0) & uVar1;
}


// ==== FUN_0044fd20 @ 0x0044fd20 ====

int FUN_0044fd20(int *param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iStack_c;
  
  if (param_1 == (int *)0x0) {
    return -1;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar3 != (int *)0x0) {
    iStack_c = 0;
    iVar4 = (**(code **)(*param_1 + 0x48))();
    iVar4 = *(int *)(iVar4 + 8);
    if (iVar4 != 0) {
      piVar5 = (int *)(**(code **)(*piVar3 + 8))();
      if (piVar5 != (int *)0x0) {
        do {
          piVar1 = *(int **)(*piVar5 + 4);
          if (piVar1 == (int *)0x0) {
LAB_0044fdd2:
            piVar5 = (int *)(**(code **)(*piVar3 + 0x48))(piVar5);
          }
          else {
            iVar6 = (**(code **)(*piVar1 + 0x14))();
            iVar7 = (**(code **)(*param_1 + 0x14))();
            if (*(int *)(iVar7 + 4) == *(int *)(iVar6 + 4)) {
              cVar2 = FUN_0044f750(param_1,piVar1,iVar4);
              if (cVar2 == '\x01') {
                iStack_c = iStack_c + 1;
              }
              goto LAB_0044fdd2;
            }
            piVar5 = (int *)(**(code **)(*piVar3 + 0x48))(piVar5);
          }
        } while (piVar5 != (int *)0x0);
      }
      return iStack_c;
    }
  }
  return -1;
}


// ==== FUN_0044fdf0 @ 0x0044fdf0 ====

int FUN_0044fdf0(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iStack_c;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  iStack_c = 0;
  iVar5 = (**(code **)(*param_1 + 0x48))();
  uVar1 = *(undefined4 *)(iVar5 + 8);
  piVar6 = (int *)(**(code **)(*piVar4 + 8))();
joined_r0x0044fe3e:
  do {
    if (piVar6 == (int *)0x0) {
      return iStack_c;
    }
    piVar2 = *(int **)(*piVar6 + 4);
    if ((piVar2 != (int *)0x0) && (iVar5 = (**(code **)(*piVar2 + 0x28))(), iVar5 == 0)) {
      iVar5 = (**(code **)(*piVar2 + 0x14))();
      iVar7 = (**(code **)(*param_1 + 0x14))();
      if (*(int *)(iVar7 + 4) == *(int *)(iVar5 + 4)) {
        piVar6 = (int *)(**(code **)(*piVar4 + 0x48))(piVar6);
        goto joined_r0x0044fe3e;
      }
      cVar3 = FUN_0044f750(param_1,piVar2,uVar1);
      if (cVar3 == '\x01') {
        iStack_c = iStack_c + 1;
      }
    }
    piVar6 = (int *)(**(code **)(*piVar4 + 0x48))(piVar6);
  } while( true );
}


// ==== FUN_0044fec0 @ 0x0044fec0 ====

void FUN_0044fec0(undefined4 param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  char cVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  int in_ECX;
  undefined4 uVar14;
  
  piVar1 = param_2;
  if ((((param_2 != (int *)0x0) &&
       (piVar6 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar6 != 0x12)) &&
      (piVar6 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar6 != 0x11)) &&
     ((piVar6 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar6 != 0xf &&
      (piVar6 = (int *)(**(code **)(*param_2 + 0x30))(), *piVar6 != 0x10)))) {
    (**(code **)(*param_2 + 0x48))();
    piVar6 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
    if (piVar6 != (int *)0x0) {
      iVar7 = (**(code **)(*param_2 + 0x48))();
      uVar2 = *(uint *)(iVar7 + 0x3c);
      param_2 = (int *)0x0;
      piVar8 = (int *)(**(code **)(*piVar6 + 8))();
      iVar7 = 0;
      if (piVar8 != (int *)0x0) {
        do {
          piVar3 = *(int **)(*piVar8 + 4);
          if (piVar3 == (int *)0x0) {
            piVar8 = (int *)(**(code **)(*piVar6 + 0x48))(piVar8);
            goto LAB_00450112;
          }
          piVar9 = (int *)(**(code **)(*piVar1 + 0x10))();
          piVar10 = (int *)(**(code **)(*piVar3 + 0x10))();
          if (*piVar9 == *piVar10) {
LAB_0045010a:
            piVar8 = (int *)(**(code **)(*piVar6 + 0x48))(piVar8);
          }
          else {
            piVar9 = (int *)(**(code **)(*piVar3 + 0x10))();
            iVar7 = (**(code **)(*piVar1 + 0x10))();
            if ((*(int *)(iVar7 + 4) == *piVar9) ||
               (piVar9 = (int *)(**(code **)(*piVar3 + 0x30))(), *piVar9 == 0xe)) goto LAB_0045010a;
            iVar7 = (**(code **)(*piVar1 + 0x14))();
            if ((*(int *)(iVar7 + 4) == 0) &&
               (iVar7 = (**(code **)(*piVar3 + 0x14))(), *(int *)(iVar7 + 4) == 0)) {
              piVar8 = (int *)(**(code **)(*piVar6 + 0x48))(piVar8);
            }
            else {
              iVar7 = (**(code **)(*piVar1 + 0x14))();
              if ((*(int *)(iVar7 + 4) == 1) &&
                 (iVar7 = (**(code **)(*piVar3 + 0x14))(), *(int *)(iVar7 + 4) == 3))
              goto LAB_0045010a;
              piVar9 = (int *)(**(code **)(*piVar1 + 0x30))();
              if ((*piVar9 != 0x12) ||
                 (((piVar9 = (int *)(**(code **)(*piVar1 + 0x30))(), *piVar9 != 0x10 ||
                   (piVar9 = (int *)(**(code **)(*piVar1 + 0x30))(), *piVar9 != 0xf)) ||
                  (piVar9 = (int *)(**(code **)(*piVar1 + 0x30))(), *piVar9 != 0x11)))) {
                iVar7 = (**(code **)(*piVar1 + 0x14))();
                iVar7 = *(int *)(iVar7 + 4);
                iVar11 = (**(code **)(*piVar3 + 0x14))();
                if (iVar7 == *(int *)(iVar11 + 4)) {
                  piVar8 = (int *)(**(code **)(*piVar6 + 0x48))(piVar8);
                  goto LAB_00450112;
                }
              }
              puVar13 = (undefined4 *)(**(code **)(*piVar3 + 0x10))();
              uVar12 = FUN_0044fc60(*puVar13);
              if (uVar12 < uVar2) {
                iVar7 = (**(code **)(*piVar1 + 0x10))();
                piVar9 = (int *)FUN_0044f820(*(undefined4 *)(iVar7 + 4));
                if (piVar9 == (int *)0x0) {
                  iVar7 = (**(code **)(*piVar1 + 0x48))();
                  uVar14 = *(undefined4 *)(iVar7 + 8);
                  piVar9 = piVar1;
                }
                else {
                  iVar7 = (**(code **)(*piVar1 + 0x48))();
                  uVar14 = *(undefined4 *)(iVar7 + 0x20);
                }
                cVar5 = FUN_0044f750(piVar9,piVar3,uVar14);
                if (cVar5 == '\x01') {
                  if (0x13 < *(uint *)(*(int *)(in_ECX + 0xc) + 0x54)) goto LAB_0045010a;
                  piVar9 = (int *)(*(int *)(in_ECX + 0xc) + 0x54);
                  *piVar9 = *piVar9 + 1;
                  iVar11 = *(int *)(in_ECX + 0xc);
                  iVar7 = (int)param_2 * 4;
                  puVar13 = (undefined4 *)(**(code **)(*piVar3 + 0x10))();
                  param_2 = (int *)((int)param_2 + 1);
                  *(undefined4 *)(iVar11 + 4 + iVar7) = *puVar13;
                }
                piVar8 = (int *)(**(code **)(*piVar6 + 0x48))(piVar8);
              }
              else {
                piVar8 = (int *)(**(code **)(*piVar6 + 0x48))(piVar8);
              }
            }
          }
LAB_00450112:
        } while (piVar8 != (int *)0x0);
        iVar7 = (int)param_2;
      }
      puVar13 = (undefined4 *)(**(code **)(*piVar1 + 0x10))();
      uVar14 = *puVar13;
      if (iVar7 != 0) {
        iVar7 = FUN_0044ee00(0,iVar7);
        uVar4 = *(undefined4 *)(*(int *)(in_ECX + 0xc) + 4 + iVar7 * 4);
        iVar7 = FUN_0044f820(uVar4);
        if (iVar7 != 0) {
          piVar1 = (int *)(*(int *)(in_ECX + 0xc) + 0x54);
          *piVar1 = *piVar1 - *(int *)(*(int *)(in_ECX + 0xc) + 0x54);
          FUN_00457530(param_1,uVar14,uVar4);
        }
      }
    }
  }
  return;
}


