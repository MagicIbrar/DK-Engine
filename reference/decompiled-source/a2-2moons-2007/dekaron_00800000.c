// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x800000-0x80ffff

// ==== __global_unwind2 @ 0x00800064 ====

/* Library Function - Single Match
    __global_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x80007c,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


// ==== __local_unwind2 @ 0x008000a6 ====

/* Library Function - Single Match
    __local_unwind2
   
   Library: Visual Studio 2003 Release */

void __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  puStack_18 = &LAB_00800084;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_0080013a(0x101);
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== __abnormal_termination @ 0x0080010e ====

/* Library Function - Single Match
    __abnormal_termination
   
   Library: Visual Studio 2003 Release */

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(undefined1 **)((int)ExceptionList + 4) == &LAB_00800084) &&
     (*(int *)((int)ExceptionList + 8) == *(int *)(*(int *)((int)ExceptionList + 0xc) + 0xc))) {
    iVar1 = 1;
  }
  return iVar1;
}


// ==== __NLG_Notify1 @ 0x00800131 ====

/* Library Function - Single Match
    __NLG_Notify1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __NLG_Notify1(void)

{
  undefined4 in_EAX;
  undefined4 in_ECX;
  undefined4 unaff_EBP;
  
  DAT_00b49308 = in_ECX;
  DAT_00b49304 = in_EAX;
  DAT_00b4930c = unaff_EBP;
  return;
}


// ==== FUN_0080013a @ 0x0080013a ====

void FUN_0080013a(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_00b49308 = *(undefined4 *)(unaff_EBP + 8);
  DAT_00b49304 = in_EAX;
  DAT_00b4930c = unaff_EBP;
  return;
}


// ==== FUN_00800242 @ 0x00800242 ====

void FUN_00800242(int param_1)

{
  __local_unwind2(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
  return;
}


// ==== _memmove @ 0x00800260 ====

/* Library Function - Single Match
    _memmove
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2003 Release */

void * __cdecl _memmove(void *_Dst,void *_Src,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((_Src < _Dst) && (_Dst < (void *)(_Size + (int)_Src))) {
    puVar3 = (undefined4 *)((_Size - 4) + (int)_Src);
    puVar4 = (undefined4 *)((_Size - 4) + (int)_Dst);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = _Size >> 2;
      uVar2 = _Size & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return _Dst;
        case 2:
          goto switchD_0080041b_caseD_2;
        case 3:
          goto switchD_0080041b_caseD_3;
        }
        goto switchD_0080041b_caseD_1;
      }
    }
    else {
      switch(_Size) {
      case 0:
        goto switchD_0080041b_caseD_0;
      case 1:
        goto switchD_0080041b_caseD_1;
      case 2:
        goto switchD_0080041b_caseD_2;
      case 3:
        goto switchD_0080041b_caseD_3;
      default:
        uVar1 = _Size - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_0080041b_caseD_2;
            case 3:
              goto switchD_0080041b_caseD_3;
            }
            goto switchD_0080041b_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_0080041b_caseD_2;
            case 3:
              goto switchD_0080041b_caseD_3;
            }
            goto switchD_0080041b_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_0080041b_caseD_2;
            case 3:
              goto switchD_0080041b_caseD_3;
            }
            goto switchD_0080041b_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_0080041b_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return _Dst;
    case 2:
switchD_0080041b_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return _Dst;
    case 3:
switchD_0080041b_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return _Dst;
    }
switchD_0080041b_caseD_0:
    return _Dst;
  }
  puVar3 = _Dst;
  if (((uint)_Dst & 3) == 0) {
    uVar1 = _Size >> 2;
    uVar2 = _Size & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *(undefined4 *)_Src;
        _Src = (undefined4 *)((int)_Src + 4);
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return _Dst;
      case 2:
        goto switchD_00800295_caseD_2;
      case 3:
        goto switchD_00800295_caseD_3;
      }
      goto switchD_00800295_caseD_1;
    }
  }
  else {
    switch(_Size) {
    case 0:
      goto switchD_00800295_caseD_0;
    case 1:
      goto switchD_00800295_caseD_1;
    case 2:
      goto switchD_00800295_caseD_2;
    case 3:
      goto switchD_00800295_caseD_3;
    default:
      uVar1 = (_Size - 4) + ((uint)_Dst & 3);
      switch((uint)_Dst & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        *(undefined1 *)((int)_Dst + 1) = *(undefined1 *)((int)_Src + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)_Dst + 2) = *(undefined1 *)((int)_Src + 2);
        _Src = (void *)((int)_Src + 3);
        puVar3 = (undefined4 *)((int)_Dst + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_00800295_caseD_2;
          case 3:
            goto switchD_00800295_caseD_3;
          }
          goto switchD_00800295_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)_Dst + 1) = *(undefined1 *)((int)_Src + 1);
        _Src = (void *)((int)_Src + 2);
        puVar3 = (undefined4 *)((int)_Dst + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_00800295_caseD_2;
          case 3:
            goto switchD_00800295_caseD_3;
          }
          goto switchD_00800295_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        _Src = (void *)((int)_Src + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)_Dst + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_00800295_caseD_2;
          case 3:
            goto switchD_00800295_caseD_3;
          }
          goto switchD_00800295_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = *(undefined4 *)((int)_Src + (uVar1 - 7) * 4);
  case 6:
    puVar3[uVar1 - 6] = *(undefined4 *)((int)_Src + (uVar1 - 6) * 4);
  case 5:
    puVar3[uVar1 - 5] = *(undefined4 *)((int)_Src + (uVar1 - 5) * 4);
  case 4:
    puVar3[uVar1 - 4] = *(undefined4 *)((int)_Src + (uVar1 - 4) * 4);
  case 3:
    puVar3[uVar1 - 3] = *(undefined4 *)((int)_Src + (uVar1 - 3) * 4);
  case 2:
    puVar3[uVar1 - 2] = *(undefined4 *)((int)_Src + (uVar1 - 2) * 4);
  case 1:
    puVar3[uVar1 - 1] = *(undefined4 *)((int)_Src + (uVar1 - 1) * 4);
    _Src = (void *)((int)_Src + uVar1 * 4);
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_00800295_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    return _Dst;
  case 2:
switchD_00800295_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)_Src + 1);
    return _Dst;
  case 3:
switchD_00800295_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)_Src + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)_Src + 2);
    return _Dst;
  }
switchD_00800295_caseD_0:
  return _Dst;
}


// ==== FUN_0080059d @ 0x0080059d ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

void FUN_0080059d(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &type_info::vftable;
  __lock(0xe);
  if ((void *)in_ECX[1] == (void *)0x0) {
    FUN_008005da();
    return;
  }
  _free((void *)in_ECX[1]);
  return;
}


// ==== FUN_008005da @ 0x008005da ====

void FUN_008005da(void)

{
  FUN_00806c2f(0xe);
  return;
}


// ==== FUN_008005e3 @ 0x008005e3 ====

void FUN_008005e3(byte param_1)

{
  void *in_ECX;
  
  FUN_0080059d();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== _JumpToContinuation @ 0x00800604 ====

/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)
   
   Library: Visual Studio 2003 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x0080062d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)();
  return;
}


// ==== FID_conflict:_CallMemberFunction1 @ 0x00800634 ====

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 2003 Release */

void FID_conflict__CallMemberFunction1(void *param_1,void *param_2,void *param_3,int param_4)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00800639. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_2)();
  return;
}


// ==== _UnwindNestedFrames @ 0x0080063b ====

/* Library Function - Single Match
    void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *)
   
   Library: Visual Studio 2003 Release */

void _UnwindNestedFrames(EHRegistrationNode *param_1,EHExceptionRecord *param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x800664,(PEXCEPTION_RECORD)param_2,(PVOID)0x0);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}


// ==== ___CxxFrameHandler @ 0x0080068d ====

/* Library Function - Single Match
    ___CxxFrameHandler
   
   Library: Visual Studio 2003 Release */

undefined4
___CxxFrameHandler(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = ___InternalCxxFrameHandler(param_1,param_2,param_3,param_4);
  return uVar1;
}


// ==== _CallSETranslator @ 0x008006fe ====

/* Library Function - Single Match
    int __cdecl _CallSETranslator(struct EHExceptionRecord *,struct EHRegistrationNode *,void *,void
   *,struct _s_FuncInfo const *,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 2003 Release */

int __cdecl
_CallSETranslator(EHExceptionRecord *param_1,EHRegistrationNode *param_2,void *param_3,void *param_4
                 ,_s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7)

{
  _ptiddata p_Var1;
  undefined4 uVar2;
  EHExceptionRecord **ppEVar3;
  undefined4 local_38;
  EHExceptionRecord *local_34;
  void *local_30;
  undefined4 *local_2c;
  code *local_28;
  undefined4 local_24;
  _s_FuncInfo *local_20;
  EHRegistrationNode *local_1c;
  int local_18;
  EHRegistrationNode *local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  undefined4 local_8;
  
  local_c = (undefined1 *)((int)register0x00000010 + -4);
  local_10 = (undefined1 *)((int)register0x00000010 + -0x3c);
  if (param_1 == (EHExceptionRecord *)0x123) {
    *(undefined4 *)param_2 = 0x800799;
    local_38 = 1;
  }
  else {
    local_28 = TranslatorGuardHandler;
    local_24 = DAT_00b49670;
    local_20 = param_5;
    local_1c = param_2;
    local_18 = param_6;
    local_14 = param_7;
    local_8 = 0;
    local_2c = ExceptionList;
    ExceptionList = &local_2c;
    local_34 = param_1;
    local_30 = param_3;
    ppEVar3 = &local_34;
    uVar2 = *(undefined4 *)param_1;
    p_Var1 = __getptd();
    (*(code *)p_Var1->_NLG_dwCode)(uVar2,ppEVar3);
    local_38 = 0;
    if (local_8 != 0) {
      *local_2c = *(undefined4 *)ExceptionList;
    }
    ExceptionList = local_2c;
  }
  return local_38;
}


// ==== TranslatorGuardHandler @ 0x008007c5 ====

/* Library Function - Single Match
    enum _EXCEPTION_DISPOSITION __cdecl TranslatorGuardHandler(struct EHExceptionRecord *,struct
   TranslatorGuardRN *,void *,void *)
   
   Library: Visual Studio 2003 Release */

_EXCEPTION_DISPOSITION __cdecl
TranslatorGuardHandler
          (EHExceptionRecord *param_1,TranslatorGuardRN *param_2,void *param_3,void *param_4)

{
  _EXCEPTION_DISPOSITION _Var1;
  code *local_8;
  
  if (*(int *)(param_2 + 8) == DAT_00b49670) {
    if ((*(uint *)(param_1 + 4) & 0x66) == 0) {
      ___InternalCxxFrameHandler
                (param_1,*(undefined4 *)(param_2 + 0x10),param_3,0,*(undefined4 *)(param_2 + 0xc),
                 *(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18),1);
      if (*(int *)(param_2 + 0x24) == 0) {
        _UnwindNestedFrames((EHRegistrationNode *)param_2,param_1);
      }
      _CallSETranslator((EHExceptionRecord *)0x123,(EHRegistrationNode *)&local_8,(void *)0x0,
                        (void *)0x0,(_s_FuncInfo *)0x0,0,(EHRegistrationNode *)0x0);
                    /* WARNING: Could not recover jumptable at 0x0080086f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      _Var1 = (*local_8)();
      return _Var1;
    }
    *(undefined4 *)(param_2 + 0x24) = 1;
  }
  else {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 8;
  }
  return 1;
}


// ==== _GetRangeOfTrysToCheck @ 0x00800877 ====

/* Library Function - Single Match
    struct _s_TryBlockMapEntry const * __cdecl _GetRangeOfTrysToCheck(struct _s_FuncInfo const
   *,int,int,unsigned int *,unsigned int *)
   
   Library: Visual Studio 2003 Release */

_s_TryBlockMapEntry * __cdecl
_GetRangeOfTrysToCheck(_s_FuncInfo *param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  TryBlockMapEntry *pTVar1;
  _s_FuncInfo *p_Var2;
  _s_FuncInfo *p_Var3;
  _s_FuncInfo *local_8;
  
  p_Var2 = param_1;
  local_8 = (_s_FuncInfo *)param_1->nTryBlocks;
  pTVar1 = param_1->pTryBlockMap;
  p_Var3 = local_8;
  param_1 = local_8;
  if (-1 < param_2) {
    do {
      if (p_Var3 == (_s_FuncInfo *)0xffffffff) {
        _inconsistency();
      }
      p_Var3 = (_s_FuncInfo *)((int)&p_Var3[-1].pIPToStateMap + 3);
      if (((pTVar1[(int)p_Var3].tryHigh < param_3) && (param_3 <= pTVar1[(int)p_Var3].catchHigh)) ||
         (p_Var3 == (_s_FuncInfo *)0xffffffff)) {
        param_2 = param_2 + -1;
        local_8 = param_1;
        param_1 = p_Var3;
      }
    } while (-1 < param_2);
  }
  p_Var3 = (_s_FuncInfo *)((int)&p_Var3->magicNumber_and_bbtFlags + 1);
  *param_4 = (uint)p_Var3;
  *param_5 = (uint)local_8;
  if (((_s_FuncInfo *)p_Var2->nTryBlocks < local_8) || (local_8 < p_Var3)) {
    _inconsistency();
  }
  return pTVar1 + (int)p_Var3;
}


// ==== _CreateFrameInfo @ 0x008008f1 ====

/* Library Function - Single Match
    struct FrameInfo * __cdecl _CreateFrameInfo(struct FrameInfo *,void *)
   
   Library: Visual Studio 2003 Release */

FrameInfo * __cdecl _CreateFrameInfo(FrameInfo *param_1,void *param_2)

{
  _ptiddata p_Var1;
  
  *(void **)param_1 = param_2;
  p_Var1 = __getptd();
  *(void **)(param_1 + 4) = p_Var1->_curexception;
  p_Var1 = __getptd();
  p_Var1->_curexception = param_1;
  return param_1;
}


// ==== IsExceptionObjectToBeDestroyed @ 0x00800919 ====

/* Library Function - Single Match
    int __cdecl IsExceptionObjectToBeDestroyed(void *)
   
   Library: Visual Studio 2003 Release */

int __cdecl IsExceptionObjectToBeDestroyed(void *param_1)

{
  _ptiddata p_Var1;
  int *piVar2;
  
  p_Var1 = __getptd();
  piVar2 = p_Var1->_curexception;
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 1;
    }
    if ((void *)*piVar2 == param_1) break;
    piVar2 = (int *)piVar2[1];
  }
  return 0;
}


// ==== _FindAndUnlinkFrame @ 0x0080093a ====

/* Library Function - Single Match
    void __cdecl _FindAndUnlinkFrame(struct FrameInfo *)
   
   Library: Visual Studio 2003 Release */

void __cdecl _FindAndUnlinkFrame(FrameInfo *param_1)

{
  _ptiddata p_Var1;
  FrameInfo *pFVar2;
  
  p_Var1 = __getptd();
  if (param_1 == p_Var1->_curexception) {
    p_Var1 = __getptd();
    p_Var1->_curexception = *(void **)(param_1 + 4);
    return;
  }
  p_Var1 = __getptd();
  pFVar2 = p_Var1->_curexception;
  while( true ) {
    if (*(int *)(pFVar2 + 4) == 0) {
      _inconsistency();
      return;
    }
    if (param_1 == *(FrameInfo **)(pFVar2 + 4)) break;
    pFVar2 = *(FrameInfo **)(pFVar2 + 4);
  }
  *(undefined4 *)(pFVar2 + 4) = *(undefined4 *)(param_1 + 4);
  return;
}


// ==== _CallCatchBlock2 @ 0x00800986 ====

/* Library Function - Single Match
    void * __cdecl _CallCatchBlock2(struct EHRegistrationNode *,struct _s_FuncInfo const *,void
   *,int,unsigned long)
   
   Library: Visual Studio 2003 Release */

void * __cdecl
_CallCatchBlock2(EHRegistrationNode *param_1,_s_FuncInfo *param_2,void *param_3,int param_4,
                ulong param_5)

{
  void *pvVar1;
  void *local_1c;
  undefined1 *local_18;
  undefined4 local_14;
  _s_FuncInfo *local_10;
  EHRegistrationNode *local_c;
  int local_8;
  
  local_14 = DAT_00b49670;
  local_10 = param_2;
  local_8 = param_4 + 1;
  local_18 = &LAB_008006c3;
  local_c = param_1;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  pvVar1 = (void *)__CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_1c;
  return pvVar1;
}


// ==== __CxxThrowException@8 @ 0x008009df ====

/* Library Function - Single Match
    __CxxThrowException@8
   
   Library: Visual Studio 2003 Release */

void __CxxThrowException_8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD *pDVar2;
  DWORD *pDVar3;
  DWORD local_24 [4];
  DWORD local_14;
  ULONG_PTR local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  pDVar2 = &DAT_00a05ac4;
  pDVar3 = local_24;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pDVar3 = *pDVar2;
    pDVar2 = pDVar2 + 1;
    pDVar3 = pDVar3 + 1;
  }
  local_c = param_1;
  local_8 = param_2;
  RaiseException(local_24[0],local_24[1],local_14,&local_10);
  return;
}


// ==== __amsg_exit @ 0x00800a19 ====

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00b5c624 == 1) {
    __FF_MSGBANNER();
  }
  FUN_00807a9a(param_1);
  (*(code *)PTR___exit_00b4932c)(0xff);
  return;
}


// ==== fast_error_exit @ 0x00800a3e ====

/* Library Function - Single Match
    _fast_error_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl fast_error_exit(undefined4 param_1)

{
  if (DAT_00b5c624 == 1) {
    __FF_MSGBANNER();
  }
  FUN_00807a9a(param_1);
  ___crtExitProcess(0xff);
  return;
}


// ==== entry @ 0x00800a62 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int entry(void)

{
  HMODULE pHVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  _OSVERSIONINFOA local_114;
  _STARTUPINFOA local_74;
  int local_30;
  int local_2c;
  undefined4 local_24;
  uint local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00a05ae8;
  uStack_c = 0x800a6e;
  local_114.szCSDVersion[0x7c] = 'z';
  local_114.szCSDVersion[0x7d] = '\n';
  local_114.szCSDVersion[0x7e] = -0x80;
  local_114.szCSDVersion[0x7f] = '\0';
  local_1c = (undefined1 *)&local_114;
  local_114.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&local_114);
  DAT_00b5c720 = local_114.dwPlatformId;
  DAT_00b5c72c = local_114.dwMajorVersion;
  _DAT_00b5c730 = local_114.dwMinorVersion;
  _DAT_00b5c724 = local_114.dwBuildNumber & 0x7fff;
  if (local_114.dwPlatformId != 2) {
    _DAT_00b5c724 = _DAT_00b5c724 | 0x8000;
  }
  _DAT_00b5c728 = local_114.dwMajorVersion * 0x100 + local_114.dwMinorVersion;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  if (((short)pHVar1->unused == 0x5a4d) &&
     (piVar5 = (int *)((int)&pHVar1->unused + pHVar1[0xf].unused), *piVar5 == 0x4550)) {
    if ((short)piVar5[6] == 0x10b) {
      if (0xe < (uint)piVar5[0x1d]) {
        iVar2 = piVar5[0x3a];
        goto LAB_00800b23;
      }
    }
    else if (((short)piVar5[6] == 0x20b) && (0xe < (uint)piVar5[0x21])) {
      iVar2 = piVar5[0x3e];
LAB_00800b23:
      local_20 = (uint)(iVar2 != 0);
      goto LAB_00800b29;
    }
  }
  local_20 = 0;
LAB_00800b29:
  iVar2 = __heap_init();
  if (iVar2 == 0) {
    fast_error_exit(0x1c);
  }
  iVar2 = __mtinit();
  if (iVar2 == 0) {
    fast_error_exit(0x10);
  }
  __RTC_Initialize();
  local_8 = (undefined *)0x0;
  iVar2 = __ioinit();
  if (iVar2 < 0) {
    __amsg_exit(0x1b);
  }
  DAT_00b620c4 = GetCommandLineA();
  DAT_00b5c61c = FUN_008080e1();
  iVar2 = __setargv();
  if (iVar2 < 0) {
    __amsg_exit(8);
  }
  iVar2 = FUN_00807e0c();
  if (iVar2 < 0) {
    __amsg_exit(9);
  }
  local_2c = __cinit(1);
  if (local_2c != 0) {
    __amsg_exit(local_2c);
  }
  local_74.dwFlags = 0;
  GetStartupInfoA(&local_74);
  uVar3 = __wincmdln();
  if ((local_74.dwFlags & 1) == 0) {
    uVar4 = 10;
  }
  else {
    uVar4 = (uint)local_74.wShowWindow;
  }
  uVar6 = 0;
  local_24 = uVar3;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  iVar2 = FUN_00401130(pHVar1,uVar6,uVar3,uVar4);
  local_30 = iVar2;
  if (local_20 == 0) {
                    /* WARNING: Subroutine does not return */
    _exit(iVar2);
  }
  __cexit();
  return iVar2;
}


// ==== FUN_00800c11 @ 0x00800c11 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00800c11(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int unaff_EBP;
  
  puVar2 = *(undefined1 **)(unaff_EBP + -0x18);
  uVar1 = *(undefined4 *)(unaff_EBP + -0x24);
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    *(undefined4 *)(puVar2 + -4) = uVar1;
    *(undefined4 *)(puVar2 + -8) = 0x800c23;
    __exit();
    puVar2 = puVar2 + -4;
  }
  *(undefined4 *)(puVar2 + -4) = 0x800c28;
  FUN_00805dcb();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x80) = 0x800c36;
  return uVar1;
}


// ==== FUN_00800c37 @ 0x00800c37 ====

void FUN_00800c37(void *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (((*(int *)((int)param_1 + 0x3c) != DAT_00b5ca34) && (*(int *)((int)param_1 + 0x3c) != 0)) &&
     (**(int **)((int)param_1 + 0x2c) == 0)) {
    piVar1 = *(int **)((int)param_1 + 0x34);
    if (((piVar1 != (int *)0x0) && (*piVar1 == 0)) && (piVar1 != DAT_00b60f6c)) {
      _free(piVar1);
      return;
    }
    piVar1 = *(int **)((int)param_1 + 0x30);
    if (((piVar1 == (int *)0x0) || (*piVar1 != 0)) || (piVar1 == DAT_00b60f74)) {
      _free(*(void **)((int)param_1 + 0x2c));
      return;
    }
    _free(piVar1);
    return;
  }
  piVar1 = *(int **)((int)param_1 + 0x40);
  if (((piVar1 != DAT_00b60f68) && (piVar1 != (int *)0x0)) && (*piVar1 == 0)) {
    _free(piVar1);
    return;
  }
  iVar2 = *(int *)((int)param_1 + 0x50);
  if (((iVar2 == DAT_00b5ca30) || (iVar2 == 0)) || (*(int *)(iVar2 + 0xb4) != 0)) {
    _free(param_1);
    return;
  }
  FUN_0080885b(iVar2);
  _free(*(void **)((int)param_1 + 0x50));
  return;
}


// ==== ___updatetlocinfo_lk @ 0x00800d07 ====

/* Library Function - Single Match
    ___updatetlocinfo_lk
   
   Library: Visual Studio 2003 Release */

int ___updatetlocinfo_lk(void)

{
  int *piVar1;
  int *piVar2;
  _ptiddata p_Var3;
  
  p_Var3 = __getptd();
  piVar1 = (int *)p_Var3->_tfpecode;
  if (piVar1 != (int *)PTR_DAT_00b49394) {
    if (piVar1 != (int *)0x0) {
      piVar2 = (int *)piVar1[0xb];
      *piVar1 = *piVar1 + -1;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + -1;
      }
      piVar2 = (int *)piVar1[0xd];
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + -1;
      }
      piVar2 = (int *)piVar1[0xc];
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + -1;
      }
      piVar2 = (int *)piVar1[0x10];
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + -1;
      }
      *(int *)(piVar1[0x13] + 0xb4) = *(int *)(piVar1[0x13] + 0xb4) + -1;
    }
    p_Var3->_tfpecode = (int)PTR_DAT_00b49394;
    *(int *)PTR_DAT_00b49394 = *(int *)PTR_DAT_00b49394 + 1;
    if (*(int *)(PTR_DAT_00b49394 + 0x2c) != 0) {
      **(int **)(PTR_DAT_00b49394 + 0x2c) = **(int **)(PTR_DAT_00b49394 + 0x2c) + 1;
    }
    if (*(int *)(PTR_DAT_00b49394 + 0x34) != 0) {
      **(int **)(PTR_DAT_00b49394 + 0x34) = **(int **)(PTR_DAT_00b49394 + 0x34) + 1;
    }
    if (*(int *)(PTR_DAT_00b49394 + 0x30) != 0) {
      **(int **)(PTR_DAT_00b49394 + 0x30) = **(int **)(PTR_DAT_00b49394 + 0x30) + 1;
    }
    if (*(int *)(PTR_DAT_00b49394 + 0x40) != 0) {
      **(int **)(PTR_DAT_00b49394 + 0x40) = **(int **)(PTR_DAT_00b49394 + 0x40) + 1;
    }
    *(int *)(*(int *)(PTR_DAT_00b49394 + 0x4c) + 0xb4) =
         *(int *)(*(int *)(PTR_DAT_00b49394 + 0x4c) + 0xb4) + 1;
    if (((piVar1 != (int *)0x0) && (*piVar1 == 0)) && (piVar1 != &DAT_00b49340)) {
      FUN_00800c37(piVar1);
    }
  }
  return p_Var3->_tfpecode;
}


// ==== __strcats @ 0x00800dc8 ====

/* Library Function - Single Match
    __strcats
   
   Library: Visual Studio 2003 Release */

void __strcats(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (0 < param_2) {
    puVar1 = &param_2;
    iVar2 = param_2;
    do {
      puVar1 = puVar1 + 1;
      FUN_00809190(param_1,*puVar1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


// ==== ___lc_strtolc @ 0x00800dec ====

/* Library Function - Single Match
    ___lc_strtolc
   
   Library: Visual Studio 2003 Release */

undefined4 ___lc_strtolc(char *param_1,char *param_2)

{
  char cVar1;
  char *_Dest;
  size_t _Count;
  char *_Str;
  
  _Str = param_2;
  _memset(param_1,0,0x90);
  if (*param_2 != '\0') {
    if ((*param_2 != '.') || (param_2[1] == '\0')) {
      param_2 = (char *)0x0;
      do {
        _Count = _strcspn(_Str,&DAT_00a05cb8);
        if (_Count == 0) {
          return 0xffffffff;
        }
        cVar1 = _Str[_Count];
        if (param_2 == (char *)0x0) {
          if (0x3f < _Count) {
            return 0xffffffff;
          }
          if (cVar1 == '.') {
            return 0xffffffff;
          }
          _Dest = param_1;
        }
        else if (param_2 == (char *)0x1) {
          if (0x3f < _Count) {
            return 0xffffffff;
          }
          if (cVar1 == '_') {
            return 0xffffffff;
          }
          _Dest = param_1 + 0x40;
        }
        else {
          if (param_2 != (char *)0x2) {
            return 0xffffffff;
          }
          if (0xf < _Count) {
            return 0xffffffff;
          }
          if ((cVar1 != '\0') && (cVar1 != ',')) {
            return 0xffffffff;
          }
          _Dest = param_1 + 0x80;
        }
        _strncpy(_Dest,_Str,_Count);
        if ((cVar1 == ',') || (cVar1 == '\0')) {
          return 0;
        }
        param_2 = (char *)((int)param_2 + 1);
        _Str = _Str + _Count + 1;
      } while( true );
    }
    _strncpy(param_1 + 0x80,param_2 + 1,0xf);
    param_1[0x8f] = '\0';
  }
  return 0;
}


// ==== ___lc_lctostr @ 0x00800ec8 ====

/* Library Function - Single Match
    ___lc_lctostr
   
   Library: Visual Studio 2003 Release */

void ___lc_lctostr(undefined4 param_1,int param_2)

{
  FUN_00809180(param_1,param_2);
  if (*(char *)(param_2 + 0x40) != '\0') {
    __strcats(param_1,2,&DAT_00a05cbc,(char *)(param_2 + 0x40));
  }
  if (*(char *)(param_2 + 0x80) != '\0') {
    __strcats(param_1,2,&DAT_00a0119c,(char *)(param_2 + 0x80));
  }
  return;
}


// ==== ___updatetlocinfo @ 0x00800f16 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___updatetlocinfo
   
   Library: Visual Studio 2003 Release */

pthreadlocinfo __cdecl ___updatetlocinfo(void)

{
  pthreadlocinfo ptVar1;
  
  __lock(0xc);
  ptVar1 = (pthreadlocinfo)___updatetlocinfo_lk();
  FUN_00800f48();
  return ptVar1;
}


// ==== FUN_00800f48 @ 0x00800f48 ====

void FUN_00800f48(void)

{
  FUN_00806c2f(0xc);
  return;
}


// ==== FUN_00800f51 @ 0x00800f51 ====

undefined1 * FUN_00800f51(void)

{
  bool bVar1;
  int iVar2;
  undefined1 *extraout_EAX;
  undefined **ppuVar3;
  int iVar4;
  
  iVar4 = 1;
  bVar1 = true;
  if ((DAT_00b494d4 == (undefined1 *)0x0) &&
     (DAT_00b494d4 = _malloc(0x351), DAT_00b494d4 == (undefined1 *)0x0)) {
    return (undefined1 *)0x0;
  }
  *DAT_00b494d4 = 0;
  __strcats(DAT_00b494d4,3,PTR_s_LC_COLLATE_00b494dc,&DAT_009ff77c,PTR_DAT_00b494e0);
  iVar2 = 0xc;
  ppuVar3 = &PTR_DAT_00b494e0;
  do {
    FUN_00809190(DAT_00b494d4,&DAT_00a05ccc);
    iVar2 = _strcmp(*ppuVar3,*(char **)((int)&PTR_DAT_00b494e0 + iVar2));
    if (iVar2 != 0) {
      bVar1 = false;
    }
    iVar4 = iVar4 + 1;
    iVar2 = iVar4 * 0xc;
    ppuVar3 = &DAT_00b494d4 + iVar4 * 3;
    __strcats(DAT_00b494d4,3,*(undefined4 *)(iVar2 + 0xb494d0),&DAT_009ff77c,*ppuVar3);
  } while (iVar4 < 5);
  if (bVar1) {
    _free(DAT_00b494d4);
    return extraout_EAX;
  }
  return DAT_00b494d4;
}


// ==== FUN_0080102b @ 0x0080102b ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0080102b(char *param_1,undefined *param_2,undefined2 *param_3,undefined4 *param_4)

{
  size_t sVar1;
  int iVar2;
  BOOL BVar3;
  undefined1 local_98 [48];
  undefined1 local_68 [96];
  uint local_8;
  
  local_8 = DAT_00b49670 ^ (uint)local_68;
  if (param_1 == (char *)0x0) {
    param_2 = (undefined *)0x0;
  }
  else if ((*param_1 == 'C') && (param_1[1] == '\0')) {
    *param_2 = 0x43;
    param_2[1] = 0;
    if (param_3 != (undefined2 *)0x0) {
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
    }
  }
  else {
    sVar1 = _strlen(param_1);
    if ((0x81 < sVar1) ||
       ((iVar2 = _strcmp(&DAT_00b49448,param_1), iVar2 != 0 &&
        (iVar2 = _strcmp(&DAT_00b493c0,param_1), iVar2 != 0)))) {
      iVar2 = ___lc_strtolc(local_98,param_1);
      if ((iVar2 != 0) ||
         (BVar3 = ___get_qualified_locale
                            ((LPLC_STRINGS)local_98,(UINT *)&DAT_00b5c628,(LPLC_STRINGS)local_98),
         BVar3 == 0)) {
        return (undefined *)0x0;
      }
      _DAT_00b5c630 = (uint)DAT_00b5c62c;
      ___lc_lctostr(&DAT_00b49448,local_98);
      if ((*param_1 == '\0') || (sVar1 = _strlen(param_1), 0x81 < sVar1)) {
        param_1 = &DAT_0099cf70;
      }
      DAT_00b49442 = 0;
      _strncpy(&DAT_00b493c0,param_1,0x82);
    }
    if (param_3 != (undefined2 *)0x0) {
      _memcpy(param_3,&DAT_00b5c628,6);
    }
    if (param_4 != (undefined4 *)0x0) {
      _memcpy(param_4,&DAT_00b5c630,4);
    }
    FUN_00809180(param_2,&DAT_00b49448);
    param_2 = &DAT_00b49448;
  }
  return param_2;
}


// ==== FUN_0080118b @ 0x0080118b ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0080118b(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int unaff_ESI;
  undefined1 local_1c4 [8];
  int local_1bc;
  uint local_1b4;
  ushort local_1b0 [6];
  int local_1a4;
  int local_1a0;
  void *local_19c;
  undefined *local_198;
  int local_194;
  undefined *local_190;
  undefined1 local_18c;
  byte abStack_18b [255];
  char local_8c [20];
  undefined1 local_78 [112];
  uint local_8;
  
  local_8 = DAT_00b49670 ^ (uint)local_78;
  iVar2 = FUN_0080102b(param_1,local_8c,local_1b0,&local_194);
  uVar4 = 0;
  if (iVar2 != 0) {
    iVar2 = _strcmp(local_8c,(char *)(&DAT_00b494d4)[unaff_ESI * 3]);
    if (iVar2 == 0) {
      uVar4 = (&DAT_00b494d4)[unaff_ESI * 3];
    }
    else {
      sVar3 = _strlen(local_8c);
      local_19c = _malloc(sVar3 + 1);
      uVar4 = 0;
      if (local_19c != (void *)0x0) {
        local_198 = (undefined *)(&DAT_00b494d4)[unaff_ESI * 3];
        local_1b4 = (&DAT_00b5ca5c)[unaff_ESI];
        local_190 = &DAT_00b5ca80 + unaff_ESI * 6;
        _memcpy(local_1c4,local_190,6);
        local_1a0 = DAT_00b5ca74;
        uVar4 = FUN_00809180(local_19c,local_8c);
        (&DAT_00b494d4)[unaff_ESI * 3] = uVar4;
        (&DAT_00b5ca5c)[unaff_ESI] = (uint)local_1b0[0];
        _memcpy(local_190,local_1b0,6);
        if (unaff_ESI == 2) {
          local_190 = (undefined *)0x0;
          DAT_00b5ca74 = local_194;
          local_1a4 = DAT_00b493bc;
          piVar5 = &DAT_00b49398;
          iVar2 = DAT_00b493b8;
          do {
            if (local_194 == *piVar5) {
              if (local_190 != (undefined *)0x0) {
                DAT_00b49398 = (&DAT_00b49398)[(int)local_190 * 2];
                DAT_00b4939c = (&DAT_00b4939c)[(int)local_190 * 2];
                (&DAT_00b49398)[(int)local_190 * 2] = iVar2;
                (&DAT_00b4939c)[(int)local_190 * 2] = local_1a4;
              }
              break;
            }
            local_1bc = *piVar5;
            local_190 = local_190 + 1;
            *piVar5 = iVar2;
            iVar1 = piVar5[1];
            piVar5[1] = local_1a4;
            piVar5 = piVar5 + 2;
            iVar2 = local_1bc;
            local_1a4 = iVar1;
          } while ((int)piVar5 < 0xb493c0);
          if (local_190 == (undefined *)0x5) {
            iVar2 = FUN_00809c38(1,&DAT_00a05bf8,0x7f,&local_18c,local_194,DAT_00b5ca64,1);
            if (iVar2 == 0) {
              DAT_00b4939c = 0;
            }
            else {
              uVar6 = 0;
              do {
                abStack_18b[uVar6 * 2] = abStack_18b[uVar6 * 2] & 1;
                uVar6 = uVar6 + 1;
              } while (uVar6 < 0x7f);
              iVar2 = _memcmp(&local_18c,&DAT_00a05af8,0xfe);
              DAT_00b4939c = (uint)(iVar2 == 0);
            }
            DAT_00b49398 = DAT_00b5ca74;
          }
          DAT_00b49d80 = DAT_00b4939c;
        }
        if (unaff_ESI == 1) {
          DAT_00b5ca78 = local_194;
        }
        iVar2 = (**(code **)(&DAT_00b494d8 + unaff_ESI * 0xc))();
        if (iVar2 != 0) {
          (&DAT_00b494d4)[unaff_ESI * 3] = local_198;
          _free(local_19c);
          return extraout_EAX;
        }
        if (local_198 != &DAT_00b49338) {
          _free(local_198);
          return extraout_EAX_00;
        }
        uVar4 = (&DAT_00b494d4)[unaff_ESI * 3];
      }
    }
  }
  return uVar4;
}


// ==== FUN_0080141f @ 0x0080141f ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0080141f(void)

{
  bool bVar1;
  undefined4 uVar2;
  char *pcVar3;
  size_t sVar4;
  int iVar5;
  size_t sVar6;
  undefined4 extraout_EAX;
  int in_ECX;
  char *in_EDX;
  undefined4 *puVar7;
  undefined **ppuVar8;
  int local_98;
  int local_90;
  char local_8c [16];
  undefined1 local_7c [116];
  uint local_8;
  
  local_8 = DAT_00b49670 ^ (uint)local_7c;
  if (in_ECX == 0) {
    bVar1 = true;
    local_90 = 0;
    if (in_EDX != (char *)0x0) {
      if (((*in_EDX == 'L') && (in_EDX[1] == 'C')) && (in_EDX[2] == '_')) {
        do {
          pcVar3 = _strpbrk(in_EDX,&DAT_00a05cd0);
          if (((pcVar3 == (char *)0x0) || (sVar4 = (int)pcVar3 - (int)in_EDX, sVar4 == 0)) ||
             (*pcVar3 == ';')) {
            return 0;
          }
          local_98 = 1;
          ppuVar8 = &PTR_s_LC_COLLATE_00b494dc;
          do {
            iVar5 = _strncmp(*ppuVar8,in_EDX,sVar4);
            if ((iVar5 == 0) && (sVar6 = _strlen(*ppuVar8), sVar4 == sVar6)) break;
            local_98 = local_98 + 1;
            ppuVar8 = ppuVar8 + 3;
          } while ((int)ppuVar8 < 0xb4950d);
          pcVar3 = pcVar3 + 1;
          sVar4 = _strcspn(pcVar3,&DAT_00a05ccc);
          if ((sVar4 == 0) && (*pcVar3 != ';')) {
            return 0;
          }
          if (local_98 < 6) {
            _strncpy(local_8c,pcVar3,sVar4);
            local_8c[sVar4] = '\0';
            iVar5 = FUN_0080118b(local_8c);
            if (iVar5 != 0) {
              local_90 = local_90 + 1;
            }
          }
        } while ((pcVar3[sVar4] != '\0') && (in_EDX = pcVar3 + sVar4 + 1, *in_EDX != '\0'));
        if (local_90 == 0) {
          return 0;
        }
      }
      else {
        iVar5 = FUN_0080102b();
        if (iVar5 == 0) {
          return 0;
        }
        puVar7 = &DAT_00b494d4;
        do {
          if ((void **)puVar7 != &DAT_00b494d4) {
            iVar5 = _strcmp(local_8c,(char *)*puVar7);
            if ((iVar5 == 0) || (iVar5 = FUN_0080118b(local_8c), iVar5 != 0)) {
              local_90 = local_90 + 1;
            }
            else {
              bVar1 = false;
            }
          }
          puVar7 = puVar7 + 3;
        } while ((int)puVar7 < 0xb49511);
        if (bVar1) {
          FUN_00800f51();
          _free(DAT_00b494d4);
          return extraout_EAX;
        }
        if (local_90 == 0) {
          return 0;
        }
      }
    }
    uVar2 = FUN_00800f51();
  }
  else {
    if (in_EDX == (char *)0x0) {
      return (&DAT_00b494d4)[in_ECX * 3];
    }
    uVar2 = FUN_0080118b();
  }
  return uVar2;
}


// ==== FUN_008015fc @ 0x008015fc ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

int FUN_008015fc(int param_1,int param_2)

{
  undefined4 *_Memory;
  int iVar1;
  int extraout_EAX;
  int local_20;
  undefined1 local_14 [8];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00a05cd8;
  uStack_c = 0x801608;
  if ((param_1 < 0) || (5 < param_1)) {
    local_20 = 0;
  }
  else {
    __lock(0xc);
    local_8 = (undefined *)0x0;
    if (param_2 == 0) {
      local_20 = FUN_0080141f();
      __local_unwind2(local_14,0xffffffff);
    }
    else {
      _Memory = _malloc(0x54);
      if (_Memory == (undefined4 *)0x0) {
        local_20 = 0;
      }
      else {
        local_20 = FUN_0080141f();
        if (local_20 != 0) {
          *_Memory = 0;
          _Memory[1] = DAT_00b5ca74;
          _Memory[2] = DAT_00b5ca78;
          for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
            _Memory[iVar1 + 3] = (&DAT_00b5ca5c)[iVar1];
          }
          _Memory[9] = DAT_00b49d80;
          _Memory[10] = DAT_00b49d90;
          _Memory[0xb] = DAT_00b60f70;
          _Memory[0xc] = DAT_00b60f74;
          _Memory[0xd] = DAT_00b60f6c;
          _Memory[0xe] = PTR_PTR_00b49d74;
          _Memory[0xf] = DAT_00b5ca34;
          _Memory[0x10] = DAT_00b60f68;
          _Memory[0x11] = DAT_00b60f64;
          _Memory[0x12] = PTR_DAT_00b49d38;
          _Memory[0x13] = PTR_PTR_00b495b0;
          _Memory[0x14] = DAT_00b5ca30;
          if ((*(int *)PTR_DAT_00b49394 == 0) && ((undefined4 *)PTR_DAT_00b49394 != &DAT_00b49340))
          {
            FUN_00800c37(PTR_DAT_00b49394);
          }
          PTR_DAT_00b49394 = (undefined *)_Memory;
          ___updatetlocinfo_lk();
        }
      }
      if ((local_20 == 0) && (_Memory != (undefined4 *)0x0)) {
        _free(_Memory);
        return extraout_EAX;
      }
      local_8 = (undefined *)0xffffffff;
      FUN_00801745();
    }
  }
  return local_20;
}


// ==== FUN_00801745 @ 0x00801745 ====

void FUN_00801745(void)

{
  FUN_00806c2f(0xc);
  return;
}


// ==== FUN_00801756 @ 0x00801756 ====

void FUN_00801756(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_00a05ce8;
  return;
}


// ==== FUN_00801767 @ 0x00801767 ====

void FUN_00801767(undefined4 *param_1)

{
  size_t sVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a05ce8;
  if ((char *)*param_1 == (char *)0x0) {
    in_ECX[1] = 0;
  }
  else {
    sVar1 = _strlen((char *)*param_1);
    pvVar2 = _malloc(sVar1 + 1);
    in_ECX[1] = pvVar2;
    if (pvVar2 != (void *)0x0) {
      FUN_00809180(pvVar2,*param_1);
    }
  }
  in_ECX[2] = 1;
  return;
}


// ==== FUN_008017af @ 0x008017af ====

void FUN_008017af(int param_1)

{
  int iVar1;
  char *_Str;
  size_t sVar2;
  void *pvVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a05ce8;
  iVar1 = *(int *)(param_1 + 8);
  in_ECX[2] = iVar1;
  _Str = *(char **)(param_1 + 4);
  if (iVar1 == 0) {
    in_ECX[1] = _Str;
  }
  else if (_Str == (char *)0x0) {
    in_ECX[1] = 0;
  }
  else {
    sVar2 = _strlen(_Str);
    pvVar3 = _malloc(sVar2 + 1);
    in_ECX[1] = pvVar3;
    if (pvVar3 != (void *)0x0) {
      FUN_00809180(pvVar3,*(undefined4 *)(param_1 + 4));
    }
  }
  return;
}


// ==== FUN_00801801 @ 0x00801801 ====

void FUN_00801801(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a05ce8;
  if (in_ECX[2] == 0) {
    return;
  }
  _free((void *)in_ECX[1]);
  return;
}


// ==== FUN_00801817 @ 0x00801817 ====

char * FUN_00801817(void)

{
  char *pcVar1;
  int in_ECX;
  
  pcVar1 = *(char **)(in_ECX + 4);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = s_Unknown_exception_00a05cf0;
  }
  return pcVar1;
}


// ==== FUN_00801824 @ 0x00801824 ====

void FUN_00801824(undefined1 param_1)

{
  undefined4 *in_ECX;
  
  FUN_00801767(&param_1);
  *in_ECX = &PTR_FUN_00a05d08;
  return;
}


// ==== FUN_0080183d @ 0x0080183d ====

void FUN_0080183d(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008017af(param_1);
  *in_ECX = &PTR_FUN_00a05d08;
  return;
}


// ==== FUN_00801855 @ 0x00801855 ====

void FUN_00801855(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a05d08;
  FUN_00801801();
  return;
}


// ==== FUN_00801860 @ 0x00801860 ====

void FUN_00801860(undefined1 param_1)

{
  undefined4 *in_ECX;
  
  FUN_00801767(&param_1);
  *in_ECX = &PTR_FUN_00a05d14;
  return;
}


// ==== FUN_00801879 @ 0x00801879 ====

void FUN_00801879(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008017af(param_1);
  *in_ECX = &PTR_FUN_00a05d14;
  return;
}


// ==== FUN_00801891 @ 0x00801891 ====

void FUN_00801891(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_00801860(param_1);
  *in_ECX = &PTR_FUN_00a05d20;
  return;
}


// ==== FUN_008018a9 @ 0x008018a9 ====

void FUN_008018a9(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_00801879(param_1);
  *in_ECX = &PTR_FUN_00a05d20;
  return;
}


// ==== FUN_008018c1 @ 0x008018c1 ====

void FUN_008018c1(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a05d14;
  FUN_00801801();
  return;
}


// ==== FUN_008018cc @ 0x008018cc ====

void FUN_008018cc(byte param_1)

{
  void *in_ECX;
  
  FUN_00801801();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008018e8 @ 0x008018e8 ====

void FUN_008018e8(byte param_1)

{
  void *in_ECX;
  
  FUN_00801855();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00801904 @ 0x00801904 ====

void FUN_00801904(byte param_1)

{
  void *in_ECX;
  
  FUN_008018c1();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00801920 @ 0x00801920 ====

void FUN_00801920(void)

{
  if (DAT_00b5c634 != (code *)0x0) {
    (*DAT_00b5c634)();
  }
  __amsg_exit(0x19);
  return;
}


// ==== _isalpha @ 0x00801934 ====

/* Library Function - Single Match
    _isalpha
   
   Library: Visual Studio 2003 Release */

int __cdecl _isalpha(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  if ((int)ptVar2->lc_category[1].refcount < 2) {
    return *(ushort *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 0x103;
  }
  iVar3 = ___isctype_mt(ptVar2,_C,0x103);
  return iVar3;
}


// ==== _isupper @ 0x00801973 ====

/* Library Function - Single Match
    _isupper
   
   Library: Visual Studio 2003 Release */

int __cdecl _isupper(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  if ((int)ptVar2->lc_category[1].refcount < 2) {
    return *(byte *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 1;
  }
  iVar3 = ___isctype_mt(ptVar2,_C,1);
  return iVar3;
}


// ==== _islower @ 0x008019ad ====

/* Library Function - Single Match
    _islower
   
   Library: Visual Studio 2003 Release */

int __cdecl _islower(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  if ((int)ptVar2->lc_category[1].refcount < 2) {
    return *(byte *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 2;
  }
  iVar3 = ___isctype_mt(ptVar2,_C,2);
  return iVar3;
}


// ==== _isdigit @ 0x008019e7 ====

/* Library Function - Single Match
    _isdigit
   
   Library: Visual Studio 2003 Release */

int __cdecl _isdigit(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  if ((int)ptVar2->lc_category[1].refcount < 2) {
    return *(byte *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 4;
  }
  iVar3 = ___isctype_mt(ptVar2,_C,4);
  return iVar3;
}


// ==== _isxdigit @ 0x00801a21 ====

/* Library Function - Single Match
    _isxdigit
   
   Library: Visual Studio 2003 Release */

int __cdecl _isxdigit(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  if ((int)ptVar2->lc_category[1].refcount < 2) {
    return *(byte *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 0x80;
  }
  iVar3 = ___isctype_mt(ptVar2,_C,0x80);
  return iVar3;
}


// ==== _isspace @ 0x00801a60 ====

/* Library Function - Single Match
    _isspace
   
   Library: Visual Studio 2003 Release */

int __cdecl _isspace(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  if ((int)ptVar2->lc_category[1].refcount < 2) {
    return *(byte *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 8;
  }
  iVar3 = ___isctype_mt(ptVar2,_C,8);
  return iVar3;
}


// ==== _ispunct @ 0x00801a9a ====

/* Library Function - Single Match
    _ispunct
   
   Library: Visual Studio 2003 Release */

int __cdecl _ispunct(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  if ((int)ptVar2->lc_category[1].refcount < 2) {
    return *(byte *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 0x10;
  }
  iVar3 = ___isctype_mt(ptVar2,_C,0x10);
  return iVar3;
}


// ==== _isalnum @ 0x00801ad4 ====

/* Library Function - Single Match
    _isalnum
   
   Library: Visual Studio 2003 Release */

int __cdecl _isalnum(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  if ((int)ptVar2->lc_category[1].refcount < 2) {
    return *(ushort *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 0x107;
  }
  iVar3 = ___isctype_mt(ptVar2,_C,0x107);
  return iVar3;
}


// ==== _isprint @ 0x00801b13 ====

/* Library Function - Single Match
    _isprint
   
   Library: Visual Studio 2003 Release */

int __cdecl _isprint(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  if ((int)ptVar2->lc_category[1].refcount < 2) {
    return *(ushort *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 0x157;
  }
  iVar3 = ___isctype_mt(ptVar2,_C,0x157);
  return iVar3;
}


// ==== _isgraph @ 0x00801b52 ====

/* Library Function - Single Match
    _isgraph
   
   Library: Visual Studio 2003 Release */

int __cdecl _isgraph(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  if ((int)ptVar2->lc_category[1].refcount < 2) {
    return *(ushort *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 0x117;
  }
  iVar3 = ___isctype_mt(ptVar2,_C,0x117);
  return iVar3;
}


// ==== _iscntrl @ 0x00801b91 ====

/* Library Function - Single Match
    _iscntrl
   
   Library: Visual Studio 2003 Release */

int __cdecl _iscntrl(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  if ((int)ptVar2->lc_category[1].refcount < 2) {
    return *(byte *)((int)ptVar2->lc_category[3].refcount + _C * 2) & 0x20;
  }
  iVar3 = ___isctype_mt(ptVar2,_C,0x20);
  return iVar3;
}


// ==== FUN_00801bcb @ 0x00801bcb ====

ushort FUN_00801bcb(byte param_1)

{
  return *(ushort *)(PTR_DAT_00b49d38 + (uint)param_1 * 2) & 0x8000;
}


// ==== _iswalpha @ 0x00801be0 ====

/* Library Function - Single Match
    _iswalpha
   
   Library: Visual Studio 2003 Release */

int __cdecl _iswalpha(wint_t _C)

{
  int iVar1;
  
  iVar1 = _iswctype(_C,0x103);
  return iVar1;
}


// ==== _iswdigit @ 0x00801bf1 ====

/* Library Function - Single Match
    _iswdigit
   
   Library: Visual Studio 2003 Release */

int __cdecl _iswdigit(wint_t _C)

{
  int iVar1;
  
  iVar1 = _iswctype(_C,4);
  return iVar1;
}


// ==== _iswspace @ 0x00801bff ====

/* Library Function - Single Match
    _iswspace
   
   Library: Visual Studio 2003 Release */

int __cdecl _iswspace(wint_t _C)

{
  int iVar1;
  
  iVar1 = _iswctype(_C,8);
  return iVar1;
}


// ==== _iswpunct @ 0x00801c0d ====

/* Library Function - Single Match
    _iswpunct
   
   Library: Visual Studio 2003 Release */

int __cdecl _iswpunct(wint_t _C)

{
  int iVar1;
  
  iVar1 = _iswctype(_C,0x10);
  return iVar1;
}


// ==== FUN_00801c1b @ 0x00801c1b ====

void FUN_00801c1b(void)

{
  PTR___cfltcvt_00b49d9c = __cfltcvt;
  PTR___cropzeros_00b49da0 = __cropzeros;
  PTR___fassign_00b49da4 = __fassign;
  PTR___forcdecpt_00b49da8 = __forcdecpt;
  PTR_FUN_00b49dac = FUN_00809f99;
  PTR___cfltcvt_00b49db0 = __cfltcvt;
  return;
}


// ==== __fpmath @ 0x00801c53 ====

/* Library Function - Single Match
    __fpmath
   
   Library: Visual Studio 2003 Release */

void __cdecl __fpmath(int param_1)

{
  FUN_00801c1b();
  DAT_00b5c63c = __ms_p5_mp_test_fdiv();
  if (param_1 != 0) {
    __setdefaultprecision();
  }
  return;
}


// ==== _memchr @ 0x00801c80 ====

/* Library Function - Single Match
    _memchr
   
   Library: Visual Studio */

void * __cdecl _memchr(void *_Buf,int _Val,size_t _MaxCount)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  char cVar5;
  uint uVar6;
  bool bVar7;
  
  if (_MaxCount == 0) {
    return (void *)0x0;
  }
  uVar6 = _Val & 0xff;
  while (((uint)_Buf & 3) != 0) {
    uVar2 = *(uint *)_Buf;
    _Buf = (void *)((int)_Buf + 1);
    if ((char)uVar2 == (char)_Val) goto LAB_00801d16;
    _MaxCount = _MaxCount - 1;
    if (_MaxCount == 0) {
      return (void *)0x0;
    }
  }
  uVar2 = _MaxCount - 4;
  if (3 < _MaxCount) {
    uVar6 = uVar6 * 0x1010101;
    puVar4 = _Buf;
    do {
      _Buf = puVar4 + 1;
      if (((*puVar4 ^ uVar6 ^ 0xffffffff ^ (*puVar4 ^ uVar6) + 0x7efefeff) & 0x81010100) != 0) {
        uVar1 = *puVar4;
        cVar5 = (char)uVar6;
        if ((char)uVar1 == cVar5) {
          return puVar4;
        }
        if ((char)(uVar1 >> 8) == cVar5) {
          return (char *)((int)puVar4 + 1);
        }
        if ((char)(uVar1 >> 0x10) == cVar5) {
          return (char *)((int)puVar4 + 2);
        }
        if ((char)(uVar1 >> 0x18) == cVar5) goto LAB_00801d16;
      }
      bVar7 = 3 < uVar2;
      uVar2 = uVar2 - 4;
      puVar4 = _Buf;
    } while (bVar7);
  }
  iVar3 = uVar2 + 4;
  while( true ) {
    if (iVar3 == 0) {
      return (void *)0x0;
    }
    uVar2 = *(uint *)_Buf;
    _Buf = (void *)((int)_Buf + 1);
    if ((char)uVar2 == (char)uVar6) break;
    iVar3 = iVar3 + -1;
  }
LAB_00801d16:
  return (char *)((int)_Buf + -1);
}


// ==== FUN_00801d2d @ 0x00801d2d ====

void FUN_00801d2d(ulong param_1)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  p_Var1->_holdrand = param_1;
  return;
}


// ==== _rand @ 0x00801d3a ====

/* Library Function - Single Match
    _rand
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release */

int __cdecl _rand(void)

{
  _ptiddata p_Var1;
  uint uVar2;
  
  p_Var1 = __getptd();
  uVar2 = p_Var1->_holdrand * 0x343fd + 0x269ec3;
  p_Var1->_holdrand = uVar2;
  return uVar2 >> 0x10 & 0x7fff;
}


// ==== FUN_00801d60 @ 0x00801d60 ====

void FUN_00801d60(void)

{
  float10 in_ST0;
  
  FUN_0080a658((double)in_ST0);
  FUN_00801d7d();
  return;
}


// ==== FUN_00801d7d @ 0x00801d7d ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00801d7d(int param_1,uint param_2)

{
  uint in_EAX;
  bool in_ZF;
  short in_FPUControlWord;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 fVar1;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) == 0) && (param_1 == 0)) {
LAB_00801dff:
      fVar1 = _DAT_00b49dc0;
    }
    else {
      fVar1 = (float10)FUN_0080a5fc();
    }
    if (DAT_00b5c638 == 0) {
      fVar1 = (float10)__startOneArgErrorHandling();
      return fVar1;
    }
  }
  else {
    if (in_FPUControlWord != 0x27f) {
      in_EAX = FUN_0080a5e5();
      in_ST0 = extraout_ST0;
    }
    if (in_EAX < 0x3ff00000) {
      fVar1 = (float10)fpatan(SQRT(((float10)1 - in_ST0) * ((float10)1 + in_ST0)),in_ST0);
    }
    else {
      if ((0x3ff00000 < in_EAX) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) goto LAB_00801dff;
      if ((param_2 & 0x80000000) == 0) {
        fVar1 = (float10)0;
      }
      else {
        fVar1 = (float10)3.141592653589793;
      }
    }
    if (DAT_00b5c638 == 0) {
      fVar1 = (float10)__math_exit();
      return fVar1;
    }
  }
  return fVar1;
}


// ==== FUN_00801e30 @ 0x00801e30 ====

void FUN_00801e30(void)

{
  float10 in_ST0;
  
  FUN_0080a658((double)in_ST0);
  FUN_00801e4d();
  return;
}


// ==== FUN_00801e4d @ 0x00801e4d ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00801e4d(int param_1,uint param_2)

{
  uint in_EAX;
  bool in_ZF;
  short in_FPUControlWord;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 fVar1;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) == 0) && (param_1 == 0)) {
LAB_00801ecf:
      fVar1 = _DAT_00b49dc0;
    }
    else {
      fVar1 = (float10)FUN_0080a5fc();
    }
    if (DAT_00b5c638 == 0) {
      fVar1 = (float10)__startOneArgErrorHandling();
      return fVar1;
    }
  }
  else {
    if (in_FPUControlWord != 0x27f) {
      in_EAX = FUN_0080a5e5();
      in_ST0 = extraout_ST0;
    }
    if (in_EAX < 0x3ff00000) {
      fVar1 = (float10)fpatan(in_ST0,SQRT(((float10)1 - in_ST0) * ((float10)1 + in_ST0)));
    }
    else {
      if ((0x3ff00000 < in_EAX) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) goto LAB_00801ecf;
      fVar1 = _DAT_00b49dca;
      if ((param_2 & 0x80000000) != 0) {
        fVar1 = -_DAT_00b49dca;
      }
    }
    if (DAT_00b5c638 == 0) {
      fVar1 = (float10)__math_exit();
      return fVar1;
    }
  }
  return fVar1;
}


// ==== FUN_00801f40 @ 0x00801f40 ====

void FUN_00801f40(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  float10 in_ST1;
  
  if ((DAT_00b60f5c == 0) || ((MXCSR & 0x1f80) != 0x1f80 || (in_FPUControlWord & 0x7f) != 0x7f)) {
    FUN_00801f9d((double)in_ST1,(double)in_ST0);
    return;
  }
  FUN_0080a870();
  return;
}


// ==== FUN_00801f9d @ 0x00801f9d ====

undefined4 FUN_00801f9d(int param_1,uint param_2,int param_3,uint param_4)

{
  uint in_EAX;
  uint uVar1;
  undefined4 uVar2;
  char extraout_CL;
  uint extraout_ECX;
  int extraout_ECX_00;
  int iVar3;
  int extraout_ECX_01;
  bool bVar4;
  short in_FPUControlWord;
  float10 extraout_ST0;
  float10 fVar5;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 fVar6;
  unkbyte10 in_ST7;
  undefined1 local_78 [20];
  undefined4 uStack_64;
  undefined1 auStack_e [10];
  short local_4;
  undefined2 uStack_2;
  
  _local_4 = CONCAT22((short)(in_EAX >> 0x10),in_FPUControlWord);
  uVar1 = in_EAX;
  if (in_FPUControlWord != 0x27f) {
    auStack_e._6_4_ = 0x801fb1;
    in_EAX = FUN_0080a5e5();
    uVar1 = extraout_ECX;
  }
  bVar4 = (uVar1 & 0x7ff00000) == 0x7ff00000;
  if (bVar4) {
    if ((in_EAX & 0xfffff) == 0 && param_3 == 0) {
      auStack_e._6_4_ = 0x80207a;
      fVar5 = (float10)__fload_withFB();
      iVar3 = extraout_ECX_01;
      fVar6 = extraout_ST1_01;
      goto LAB_0080207a;
    }
    auStack_e._6_4_ = 0x80203d;
    fVar5 = (float10)__fload_withFB();
    if ((param_4 & 0x80000) == 0) {
      iVar3 = extraout_ECX_00 + 1;
      fVar6 = extraout_ST1_00;
      goto LAB_0080207a;
    }
LAB_00802047:
    uVar2 = 1;
  }
  else {
    auStack_e._6_4_ = 0x801fcc;
    uVar1 = __fload_withFB();
    if (!bVar4) {
      if (((uVar1 & 0x7ff00000) != 0) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) {
        fVar5 = extraout_ST0;
        if ((param_2 & 0x80000000) != 0) {
          auStack_e._6_4_ = 0x802144;
          fVar5 = (float10)FUN_00802162();
          fVar5 = -fVar5;
          if (extraout_CL == '\0') {
            uVar2 = 1;
            goto LAB_00802015;
          }
        }
        log2(fVar5);
        auStack_e._6_4_ = 0x801ff1;
        uVar2 = FUN_0080a5d0();
        if (DAT_00b5c638 == 0) {
          uVar2 = FUN_0080a6b9();
          return uVar2;
        }
        return uVar2;
      }
      if ((param_4 & 0x7fffffff) == 0 && param_3 == 0) {
        return 0;
      }
      auStack_e._6_4_ = 0x8020fc;
      uVar2 = FUN_00802162();
      if ((param_4 & 0x80000000) == 0) {
        return uVar2;
      }
      uVar2 = 2;
      goto LAB_00802015;
    }
    iVar3 = 0;
    fVar5 = extraout_ST0;
    fVar6 = extraout_ST1;
LAB_0080207a:
    if (((param_2 & 0x7ff00000) == 0x7ff00000) && ((param_2 & 0xfffff) != 0 || param_1 != 0)) {
      if ((param_2 & 0x80000) != 0) goto LAB_00802047;
    }
    else if (iVar3 == 0) {
      uStack_64 = 0x8020a8;
      auStack_e = (undefined1  [10])in_ST7;
      iVar3 = __powhlp((double)fVar5,(double)fVar6,local_78);
      if (iVar3 == 0) {
        return 0;
      }
      uVar2 = 1;
      goto LAB_00802015;
    }
    uVar2 = 7;
  }
LAB_00802015:
  if (DAT_00b5c638 == 0) {
    auStack_e._6_4_ = 0x802032;
    uVar2 = FUN_0080a570();
    return uVar2;
  }
  return uVar2;
}


// ==== FUN_00802162 @ 0x00802162 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00802162(void)

{
  float10 in_ST0;
  
  if (ROUND(in_ST0) == in_ST0) {
    return;
  }
  return;
}


// ==== `eh_vector_constructor_iterator' @ 0x0080218a ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *),void (__thiscall*)(void *))
   
   Library: Visual Studio 2003 Release */

void _eh_vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4,
               _func_void_void_ptr *param_5)

{
  void *unaff_EDI;
  int local_20;
  
  for (local_20 = 0; local_20 < param_3; local_20 = local_20 + 1) {
    (*param_4)(unaff_EDI);
  }
  FUN_008021d4();
  return;
}


// ==== FUN_008021d4 @ 0x008021d4 ====

void FUN_008021d4(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}


// ==== __ArrayUnwind @ 0x008021ec ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall __ArrayUnwind(void *,unsigned int,int,void (__thiscall*)(void *))
   
   Library: Visual Studio 2003 Release */

void __ArrayUnwind(void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *unaff_EDI;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(unaff_EDI);
  }
  return;
}


// ==== FUN_0080221b @ 0x0080221b ====

undefined4 FUN_0080221b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x20) = **(undefined4 **)(unaff_EBP + -0x1c);
  if (**(int **)(unaff_EBP + -0x20) == -0x1f928c9d) {
                    /* WARNING: Subroutine does not return */
    terminate();
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  return *(undefined4 *)(unaff_EBP + -0x24);
}


// ==== FUN_0080223f @ 0x0080223f ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_0080223f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4) = 0x802218;
  return;
}


// ==== `eh_vector_destructor_iterator' @ 0x0080224a ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *))
   
   Library: Visual Studio 2003 Release */

void _eh_vector_destructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *unaff_EDI;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(unaff_EDI);
  }
  FUN_00802292();
  return;
}


// ==== FUN_00802292 @ 0x00802292 ====

void FUN_00802292(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}


// ==== `eh_vector_copy_constructor_iterator' @ 0x008022aa ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector copy constructor iterator'(void *,void *,unsigned int,int,void
   (__thiscall*)(void *,void *),void (__thiscall*)(void *))
   
   Library: Visual Studio 2003 Release */

void _eh_vector_copy_constructor_iterator_
               (void *param_1,void *param_2,uint param_3,int param_4,
               _func_void_void_ptr_void_ptr *param_5,_func_void_void_ptr *param_6)

{
  void *unaff_EDI;
  int local_20;
  
  for (local_20 = 0; local_20 < param_4; local_20 = local_20 + 1) {
    (*param_5)(param_2,unaff_EDI);
    param_2 = (void *)((int)param_2 + param_3);
  }
  FUN_008022f8();
  return;
}


// ==== FUN_008022f8 @ 0x008022f8 ====

void FUN_008022f8(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0x10),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x1c));
  }
  return;
}


// ==== _abort @ 0x00802310 ====

/* Library Function - Single Match
    _abort
   
   Library: Visual Studio 2003 Release */

void __cdecl _abort(void)

{
  code *pcVar1;
  
  FUN_00807a9a(10);
  _raise(0x16);
  __exit(3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== __vsnprintf @ 0x00802328 ====

/* Library Function - Single Match
    __vsnprintf
   
   Library: Visual Studio 2003 Release */

int __cdecl __vsnprintf(char *_Dest,size_t _Count,char *_Format,va_list _Args)

{
  int iVar1;
  FILE local_24;
  
  local_24._cnt = _Count;
  local_24._flag = 0x42;
  local_24._base = _Dest;
  local_24._ptr = _Dest;
  iVar1 = FUN_0080bae5(&local_24,_Format,_Args);
  if (_Dest != (char *)0x0) {
    local_24._cnt = local_24._cnt - 1;
    if (local_24._cnt < 0) {
      __flsbuf(0,&local_24);
    }
    else {
      *local_24._ptr = '\0';
    }
  }
  return iVar1;
}


// ==== __stricmp @ 0x00802383 ====

/* Library Function - Single Match
    __stricmp
   
   Library: Visual Studio 2003 Release */

int __cdecl __stricmp(char *_Str1,char *_Str2)

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
  if (ptVar2->lc_category[0].wlocale == (wchar_t *)0x0) {
    iVar3 = ___ascii_stricmp(_Str1,_Str2);
  }
  else {
    do {
      iVar3 = ___tolower_mt(ptVar2,*_Str1);
      _Str1 = _Str1 + 1;
      iVar4 = ___tolower_mt(ptVar2,*_Str2);
      _Str2 = _Str2 + 1;
      if (iVar3 == 0) break;
    } while (iVar3 == iVar4);
    iVar3 = iVar3 - iVar4;
  }
  return iVar3;
}


// ==== __allmul @ 0x008023f0 ====

/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio 2003 Release */

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}


// ==== __alldiv @ 0x00802430 ====

/* Library Function - Single Match
    __alldiv
   
   Library: Visual Studio */

undefined8 __alldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  char cVar10;
  
  cVar10 = (int)param_2 < 0;
  if ((bool)cVar10) {
    bVar9 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar9 - param_2;
  }
  if ((int)param_4 < 0) {
    cVar10 = cVar10 + '\x01';
    bVar9 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar9 - param_4;
  }
  if (param_4 == 0) {
    uVar4 = param_2 / param_3;
    iVar5 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    uVar7 = param_1;
    uVar4 = param_3;
    uVar6 = param_2;
    uVar8 = param_4;
    do {
      uVar3 = uVar8 & 1;
      uVar8 = uVar8 >> 1;
      uVar4 = (uint)(CONCAT14(uVar3 != 0,uVar4) >> 1);
      uVar3 = uVar6 & 1;
      uVar6 = uVar6 >> 1;
      uVar7 = (uint)(CONCAT14(uVar3 != 0,uVar7) >> 1);
    } while (uVar8 != 0);
    uVar1 = CONCAT44(uVar6,uVar7) / (ulonglong)uVar4;
    iVar5 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar7 = uVar4 + iVar5 * param_4;
    if (((CARRY4(uVar4,iVar5 * param_4)) || (param_2 < uVar7)) ||
       ((param_2 <= uVar7 && (param_1 < (uint)lVar2)))) {
      iVar5 = iVar5 + -1;
    }
    uVar4 = 0;
  }
  if (cVar10 == '\x01') {
    bVar9 = iVar5 != 0;
    iVar5 = -iVar5;
    uVar4 = -(uint)bVar9 - uVar4;
  }
  return CONCAT44(uVar4,iVar5);
}


// ==== _sprintf @ 0x008024da ====

/* Library Function - Single Match
    _sprintf
   
   Library: Visual Studio 2003 Release */

int __cdecl _sprintf(char *_Dest,char *_Format,...)

{
  int iVar1;
  undefined1 uStack0000000c;
  FILE local_24;
  
  local_24._cnt = 0x7fffffff;
  local_24._flag = 0x42;
  local_24._base = _Dest;
  local_24._ptr = _Dest;
  iVar1 = FUN_0080bae5(&local_24,_Format,&uStack0000000c);
  if (_Dest != (char *)0x0) {
    local_24._cnt = local_24._cnt + -1;
    if (local_24._cnt < 0) {
      __flsbuf(0,&local_24);
    }
    else {
      *local_24._ptr = '\0';
    }
  }
  return iVar1;
}


// ==== FUN_00802534 @ 0x00802534 ====

ulonglong FUN_00802534(void)

{
  ulonglong uVar1;
  uint uVar2;
  float fVar3;
  float10 in_ST0;
  uint local_20;
  float fStack_1c;
  
  uVar1 = (ulonglong)ROUND(in_ST0);
  local_20 = (uint)uVar1;
  fStack_1c = (float)(uVar1 >> 0x20);
  fVar3 = (float)in_ST0;
  if ((local_20 != 0) || (fVar3 = fStack_1c, (uVar1 & 0x7fffffff00000000) != 0)) {
    if ((int)fVar3 < 0) {
      uVar1 = uVar1 + (0x80000000 < (uint)-(float)(in_ST0 - (float10)(longlong)uVar1));
    }
    else {
      uVar2 = (uint)(0x80000000 < (uint)(float)(in_ST0 - (float10)(longlong)uVar1));
      uVar1 = CONCAT44((int)fStack_1c - (uint)(local_20 < uVar2),local_20 - uVar2);
    }
  }
  return uVar1;
}


// ==== FID_conflict:__time32 @ 0x008025a9 ====

/* Library Function - Multiple Matches With Different Base Names
    __time32
    _time
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

__time32_t __cdecl FID_conflict___time32(__time32_t *_Time)

{
  __time32_t _Var1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  _Var1 = __aulldiv(local_c.dwLowDateTime + 0x2ac18000,
                    local_c.dwHighDateTime + 0xfe624e21 + (uint)(0xd53e7fff < local_c.dwLowDateTime)
                    ,10000000,0);
  if (_Time != (__time32_t *)0x0) {
    *_Time = _Var1;
  }
  return _Var1;
}


// ==== __onexit_lk @ 0x008025e2 ====

/* Library Function - Single Match
    __onexit_lk
   
   Library: Visual Studio 2003 Release */

void __onexit_lk(void)

{
  size_t sVar1;
  void *pvVar2;
  size_t sVar3;
  undefined4 unaff_EDI;
  
  sVar1 = __msize(DAT_00b610a8);
  if (sVar1 < (uint)((int)DAT_00b610a4 + (4 - (int)DAT_00b610a8))) {
    sVar3 = 0x800;
    if (sVar1 < 0x800) {
      sVar3 = sVar1;
    }
    pvVar2 = (void *)FUN_00806326(DAT_00b610a8,sVar3 + sVar1);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)FUN_00806326(DAT_00b610a8,sVar1 + 0x10);
      if (pvVar2 == (void *)0x0) {
        return;
      }
    }
    DAT_00b610a4 = (undefined4 *)((int)pvVar2 + ((int)DAT_00b610a4 - (int)DAT_00b610a8 >> 2) * 4);
    DAT_00b610a8 = pvVar2;
  }
  *DAT_00b610a4 = unaff_EDI;
  DAT_00b610a4 = DAT_00b610a4 + 1;
  return;
}


// ==== ___onexitinit @ 0x00802662 ====

/* Library Function - Single Match
    ___onexitinit
   
   Library: Visual Studio 2003 Release */

undefined4 ___onexitinit(void)

{
  DAT_00b610a8 = _malloc(0x80);
  if (DAT_00b610a8 == (undefined4 *)0x0) {
    return 0x18;
  }
  *DAT_00b610a8 = 0;
  DAT_00b610a4 = DAT_00b610a8;
  return 0;
}


// ==== __onexit @ 0x0080268a ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 2003 Release */

_onexit_t __cdecl __onexit(_onexit_t _Func)

{
  _onexit_t p_Var1;
  
  FUN_00805c43();
  p_Var1 = (_onexit_t)__onexit_lk();
  FUN_008026bc();
  return p_Var1;
}


// ==== FUN_008026bc @ 0x008026bc ====

void FUN_008026bc(void)

{
  FUN_00805c4c();
  return;
}


// ==== _atexit @ 0x008026c2 ====

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2003 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}


// ==== __store_str @ 0x008026d4 ====

/* Library Function - Single Match
    __store_str
   
   Library: Visual Studio 2003 Release */

void __store_str(void)

{
  int iVar1;
  int *in_EAX;
  int *in_ECX;
  char *in_EDX;
  
  iVar1 = *in_EAX;
  for (; (iVar1 != 0 && (*in_EDX != '\0')); in_EDX = in_EDX + 1) {
    *(char *)*in_ECX = *in_EDX;
    *in_ECX = *in_ECX + 1;
    *in_EAX = *in_EAX + -1;
    iVar1 = *in_EAX;
  }
  return;
}


// ==== __store_num @ 0x008026f4 ====

/* Library Function - Single Match
    __store_num
   
   Library: Visual Studio 2003 Release */

void __store_num(int param_1)

{
  char cVar1;
  uint uVar2;
  int in_EAX;
  int iVar3;
  char *pcVar4;
  uint *in_ECX;
  uint in_EDX;
  char *pcVar5;
  int *unaff_EDI;
  int local_8;
  
  local_8 = 0;
  if (param_1 == 0) {
    if (in_EDX < *in_ECX) {
      iVar3 = in_EDX - 1;
      if (in_EDX != 0) {
        do {
          local_8 = local_8 + 1;
          *(char *)(iVar3 + *unaff_EDI) = (char)(in_EAX % 10) + '0';
          iVar3 = iVar3 + -1;
          in_EAX = in_EAX / 10;
        } while (iVar3 != -1);
      }
      *unaff_EDI = *unaff_EDI + local_8;
      *in_ECX = *in_ECX - local_8;
    }
    else {
      *in_ECX = 0;
    }
  }
  else {
    uVar2 = *in_ECX;
    pcVar5 = (char *)*unaff_EDI;
    do {
      if (uVar2 < 2) break;
      iVar3 = in_EAX / 10;
      *pcVar5 = (char)(in_EAX % 10) + '0';
      pcVar5 = pcVar5 + 1;
      *in_ECX = *in_ECX - 1;
      uVar2 = *in_ECX;
      in_EAX = iVar3;
    } while (0 < iVar3);
    pcVar4 = (char *)*unaff_EDI;
    *unaff_EDI = (int)pcVar5;
    pcVar5 = pcVar5 + -1;
    do {
      cVar1 = *pcVar5;
      *pcVar5 = *pcVar4;
      pcVar5 = pcVar5 + -1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 < pcVar5);
  }
  return;
}


// ==== __expandtime @ 0x0080276d ====

/* Library Function - Single Match
    __expandtime
   
   Library: Visual Studio 2003 Release */

undefined4 __expandtime(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char in_AL;
  int iVar1;
  int *in_ECX;
  int *unaff_EBX;
  undefined4 uVar2;
  
  if (in_AL < '[') {
    if (in_AL == 'Z') {
LAB_0080295e:
      ___tzset();
LAB_008029c3:
      __store_str();
      return 1;
    }
    if (in_AL < 'N') {
      if (in_AL != 'M') {
        if (in_AL == '%') {
          *(undefined1 *)*in_ECX = 0x25;
          *in_ECX = *in_ECX + 1;
          *unaff_EBX = *unaff_EBX + -1;
          return 1;
        }
        if ((in_AL == 'A') || (in_AL == 'B')) goto LAB_008029c3;
        if ((in_AL != 'H') && (in_AL != 'I')) {
          return 1;
        }
      }
LAB_00802835:
      __store_num(param_4);
      return 1;
    }
    if (((in_AL == 'S') || (in_AL == 'U')) || (in_AL == 'W')) goto LAB_00802835;
    if (in_AL != 'X') {
      if (in_AL != 'Y') {
        return 1;
      }
      goto LAB_00802835;
    }
  }
  else {
    if ('m' < in_AL) {
      if (in_AL == 'p') goto LAB_008029c3;
      if (in_AL == 'w') goto LAB_00802835;
      if (in_AL == 'x') {
        if (param_4 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
        goto LAB_0080284a;
      }
      if (in_AL == 'y') goto LAB_00802835;
      if (in_AL != 'z') {
        return 1;
      }
      goto LAB_0080295e;
    }
    if (in_AL == 'm') goto LAB_00802835;
    if ((in_AL == 'a') || (in_AL == 'b')) goto LAB_008029c3;
    if (in_AL != 'c') {
      if ((in_AL != 'd') && (in_AL != 'j')) {
        return 1;
      }
      goto LAB_00802835;
    }
    iVar1 = FUN_008029d3(param_1,param_4 != 0,param_2);
    if (iVar1 == 0) {
      return 0;
    }
    if (*unaff_EBX == 0) {
      return 0;
    }
    *(undefined1 *)*in_ECX = 0x20;
    *in_ECX = *in_ECX + 1;
    *unaff_EBX = *unaff_EBX + -1;
  }
  uVar2 = 2;
LAB_0080284a:
  iVar1 = FUN_008029d3(param_1,uVar2,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}


// ==== FUN_008029d3 @ 0x008029d3 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

undefined4
FUN_008029d3(int param_1,int param_2,undefined2 *param_3,int *param_4,uint *param_5,int param_6)

{
  byte bVar1;
  short *psVar2;
  short *psVar3;
  short *_Memory;
  int iVar4;
  undefined4 extraout_EAX;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  undefined1 uStack00000000;
  short local_4c;
  short local_4a [2];
  undefined2 local_46;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined1 *local_3c;
  int local_38;
  code *local_34;
  size_t local_30;
  undefined4 local_2c;
  byte *local_28;
  byte *local_24;
  char local_1d;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00a05eb0;
  uStack_c = 0x8029df;
  if (param_2 == 0) {
    local_24 = *(byte **)(param_6 + 0xa0);
  }
  else if (param_2 == 1) {
    local_24 = *(byte **)(param_6 + 0xa4);
  }
  else {
    local_24 = *(byte **)(param_6 + 0xa8);
  }
  if (*(int *)(param_6 + 0xb0) != 1) {
    local_34 = GetDateFormatA_exref;
    if (param_2 == 2) {
      local_34 = GetTimeFormatA_exref;
    }
    local_4c = param_3[10] + 0x76c;
    local_4a[0] = param_3[8] + 1;
    local_46 = param_3[6];
    local_44 = param_3[4];
    local_42 = param_3[2];
    local_40 = *param_3;
    local_3e = 0;
    local_30 = (*local_34)(*(undefined4 *)(param_6 + 0xac),0,&local_4c,local_24,0,0);
    if (local_30 != 0) {
      local_38 = 0;
      local_1c = (undefined1 *)(local_4a + -7);
      _Memory = local_4a + -7;
      local_3c = (undefined1 *)(local_4a + -7);
      local_8 = (undefined *)0xffffffff;
      psVar2 = local_4a + -7;
      psVar3 = local_4a + -7;
      if (&uStack00000000 == (undefined1 *)0x58) {
        _Memory = _malloc(local_30);
        if (_Memory == (short *)0x0) goto LAB_00802b33;
        local_38 = 1;
        psVar2 = (short *)local_3c;
        psVar3 = (short *)local_1c;
      }
      local_1c = (undefined1 *)psVar3;
      local_3c = (undefined1 *)psVar2;
      local_28 = (byte *)_Memory;
      iVar4 = (*local_34)(*(undefined4 *)(param_6 + 0xac),0,&local_4c,local_24,_Memory,local_30);
      while ((iVar4 = iVar4 + -1, 0 < iVar4 && (*param_5 != 0))) {
        *(byte *)*param_4 = *local_28;
        *param_4 = *param_4 + 1;
        local_28 = local_28 + 1;
        *param_5 = *param_5 - 1;
      }
      if (local_38 == 0) {
        return 1;
      }
      _free(_Memory);
      return extraout_EAX;
    }
  }
LAB_00802b33:
  bVar1 = *local_24;
  pbVar5 = local_24;
  do {
    if ((bVar1 == 0) || (*param_5 == 0)) {
      return 1;
    }
    local_1d = '\0';
    local_2c = 0;
    local_28 = pbVar5;
    uVar7 = 0;
    do {
      uVar6 = uVar7;
      local_28 = local_28 + 1;
      uVar7 = uVar6 + 1;
    } while (*local_28 == bVar1);
    local_24 = pbVar5;
    if ((char)bVar1 < 'e') {
      if (bVar1 == 100) {
        if (uVar6 == 0) {
          local_2c = 1;
        }
        else if (uVar6 != 1) {
          if (uVar6 == 2) {
            local_1d = 'a';
          }
          else if (uVar6 == 3) {
            local_1d = 'A';
          }
          goto LAB_00802deb;
        }
        local_1d = 'd';
        goto LAB_00802deb;
      }
      if (bVar1 != 0x27) {
        if (bVar1 == 0x41) {
LAB_00802b94:
          iVar4 = ___ascii_stricmp((char *)pbVar5,s_am_pm_00a05ea4);
          if (iVar4 == 0) {
            local_28 = pbVar5 + 5;
          }
          else {
            iVar4 = ___ascii_stricmp((char *)pbVar5,&DAT_00a05ea0);
            if (iVar4 == 0) {
              local_28 = pbVar5 + 3;
            }
          }
          local_1d = 'p';
        }
        else if (bVar1 == 0x48) {
          if (uVar6 == 0) {
            local_2c = 1;
          }
          else if (uVar6 != 1) goto LAB_00802deb;
          local_1d = 'H';
        }
        else if (bVar1 == 0x4d) {
          if (uVar6 == 0) {
            local_2c = 1;
          }
          else if (uVar6 != 1) {
            if (uVar6 == 2) {
              local_1d = 'b';
            }
            else if (uVar6 == 3) {
              local_1d = 'B';
            }
            goto LAB_00802deb;
          }
          local_1d = 'm';
        }
        else if (bVar1 == 0x61) goto LAB_00802b94;
        goto LAB_00802deb;
      }
      local_24 = pbVar5 + uVar7;
      if ((uVar7 & 1) != 0) {
        while( true ) {
          bVar1 = *local_24;
          if ((bVar1 == 0) || (*param_5 == 0)) goto LAB_00802e4b;
          if (bVar1 == 0x27) break;
          if (((*(byte *)(*(int *)(param_1 + 0x48) + 1 + (uint)bVar1 * 2) & 0x80) != 0) &&
             (1 < *param_5)) {
            local_24 = local_24 + 1;
            if (*local_24 == 0) {
              return 0;
            }
            *(byte *)*param_4 = bVar1;
            *param_4 = *param_4 + 1;
            *param_5 = *param_5 - 1;
          }
          *(byte *)*param_4 = *local_24;
          *param_4 = *param_4 + 1;
          local_24 = local_24 + 1;
          *param_5 = *param_5 - 1;
        }
        local_24 = local_24 + 1;
      }
    }
    else {
      if (bVar1 == 0x68) {
        if (uVar6 == 0) {
          local_2c = 1;
        }
        else if (uVar6 != 1) goto LAB_00802deb;
        local_1d = 'I';
LAB_00802deb:
        if (local_1d == '\0') {
          bVar1 = *local_24;
          if (((*(byte *)(*(int *)(param_1 + 0x48) + 1 + (uint)bVar1 * 2) & 0x80) != 0) &&
             (1 < *param_5)) {
            local_24 = local_24 + 1;
            if (*local_24 == 0) {
              return 0;
            }
            *(byte *)*param_4 = bVar1;
            *param_4 = *param_4 + 1;
            *param_5 = *param_5 - 1;
          }
          *(byte *)*param_4 = *local_24;
          *param_4 = *param_4 + 1;
          local_24 = local_24 + 1;
          *param_5 = *param_5 - 1;
          goto LAB_00802e4b;
        }
        iVar4 = __expandtime(param_1,param_3,param_6,local_2c);
        if (iVar4 == 0) {
          return 0;
        }
      }
      else {
        if (bVar1 == 0x6d) {
          if (uVar6 == 0) {
            local_2c = 1;
          }
          else if (uVar6 != 1) goto LAB_00802deb;
          local_1d = 'M';
          goto LAB_00802deb;
        }
        if (bVar1 == 0x73) {
          if (uVar6 == 0) {
            local_2c = 1;
          }
          else if (uVar6 != 1) goto LAB_00802deb;
          local_1d = 'S';
          goto LAB_00802deb;
        }
        if (bVar1 != 0x74) {
          if (bVar1 == 0x79) {
            if (uVar6 == 1) {
              local_1d = 'y';
            }
            else if (uVar6 == 3) {
              local_1d = 'Y';
            }
          }
          goto LAB_00802deb;
        }
        if (*(int *)(param_3 + 4) < 0xc) {
          pbVar5 = *(byte **)(param_6 + 0x98);
        }
        else {
          pbVar5 = *(byte **)(param_6 + 0x9c);
        }
        if ((uVar7 == 1) && (*param_5 != 0)) {
          bVar1 = *pbVar5;
          if (((*(byte *)(*(int *)(param_1 + 0x48) + 1 + (uint)bVar1 * 2) & 0x80) != 0) &&
             (1 < *param_5)) {
            pbVar5 = pbVar5 + 1;
            if (*pbVar5 == 0) {
              return 0;
            }
            *(byte *)*param_4 = bVar1;
            *param_4 = *param_4 + 1;
            *param_5 = *param_5 - 1;
          }
          *(byte *)*param_4 = *pbVar5;
          *param_4 = *param_4 + 1;
          *param_5 = *param_5 - 1;
        }
        else {
          while( true ) {
            bVar1 = *pbVar5;
            if ((bVar1 == 0) || (*param_5 == 0)) break;
            if (((*(byte *)(*(int *)(param_1 + 0x48) + 1 + (uint)bVar1 * 2) & 0x80) != 0) &&
               (1 < *param_5)) {
              pbVar5 = pbVar5 + 1;
              if (*pbVar5 == 0) {
                return 0;
              }
              *(byte *)*param_4 = bVar1;
              *param_4 = *param_4 + 1;
              *param_5 = *param_5 - 1;
            }
            *(byte *)*param_4 = *pbVar5;
            *param_4 = *param_4 + 1;
            pbVar5 = pbVar5 + 1;
            *param_5 = *param_5 - 1;
          }
        }
      }
      local_24 = local_28;
    }
LAB_00802e4b:
    bVar1 = *local_24;
    pbVar5 = local_24;
  } while( true );
}


// ==== FUN_00802aaa @ 0x00802aaa ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00802aaa(void)

{
  byte bVar1;
  code *pcVar2;
  int *piVar3;
  int *piVar4;
  uint *puVar5;
  void *pvVar6;
  int iVar7;
  undefined4 extraout_EAX;
  undefined4 uVar8;
  char *pcVar9;
  int iVar10;
  char cVar11;
  byte *pbVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined1 *puVar16;
  int unaff_EBP;
  
  iVar7 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar7 + -4) = 0x802ab2;
  __resetstkoflw();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar15 = *(int *)(unaff_EBP + 0x10);
  *(undefined4 *)(iVar7 + -4) = *(undefined4 *)(unaff_EBP + -0x2c);
  *(undefined4 *)(iVar7 + -8) = 0x802ac9;
  pvVar6 = _malloc(*(size_t *)(iVar7 + -4));
  if (pvVar6 == (void *)0x0) {
    cVar11 = **(char **)(unaff_EBP + -0x20);
    if (cVar11 != '\0') {
      puVar5 = *(uint **)(unaff_EBP + 0x18);
      piVar3 = *(int **)(unaff_EBP + 0x14);
      while (*puVar5 != 0) {
        *(undefined1 *)(unaff_EBP + -0x19) = 0;
        *(undefined4 *)(unaff_EBP + -0x28) = 0;
        pcVar9 = *(char **)(unaff_EBP + -0x20);
        uVar14 = 0;
        do {
          uVar13 = uVar14;
          pcVar9 = pcVar9 + 1;
          uVar14 = uVar13 + 1;
        } while (*pcVar9 == cVar11);
        *(char **)(unaff_EBP + -0x24) = pcVar9;
        if (cVar11 < 'e') {
          if (cVar11 == 'd') {
            if (uVar13 == 0) {
              *(undefined4 *)(unaff_EBP + -0x28) = 1;
            }
            else if (uVar13 != 1) {
              if (uVar13 == 2) {
                *(undefined1 *)(unaff_EBP + -0x19) = 0x61;
              }
              else if (uVar13 == 3) {
                *(undefined1 *)(unaff_EBP + -0x19) = 0x41;
              }
              goto LAB_00802deb;
            }
            *(undefined1 *)(unaff_EBP + -0x19) = 100;
            goto LAB_00802deb;
          }
          if (cVar11 != '\'') {
            if (cVar11 != 'A') {
              if (cVar11 == 'H') {
                if (uVar13 == 0) {
                  *(undefined4 *)(unaff_EBP + -0x28) = 1;
                }
                else if (uVar13 != 1) goto LAB_00802deb;
                *(undefined1 *)(unaff_EBP + -0x19) = 0x48;
              }
              else if (cVar11 == 'M') {
                if (uVar13 == 0) {
                  *(undefined4 *)(unaff_EBP + -0x28) = 1;
                }
                else if (uVar13 != 1) {
                  if (uVar13 == 2) {
                    *(undefined1 *)(unaff_EBP + -0x19) = 0x62;
                  }
                  else if (uVar13 == 3) {
                    *(undefined1 *)(unaff_EBP + -0x19) = 0x42;
                  }
                  goto LAB_00802deb;
                }
                *(undefined1 *)(unaff_EBP + -0x19) = 0x6d;
              }
              else if (cVar11 == 'a') goto LAB_00802b94;
              goto LAB_00802deb;
            }
LAB_00802b94:
            *(char **)(iVar7 + -4) = s_am_pm_00a05ea4;
            iVar15 = *(int *)(unaff_EBP + -0x20);
            *(int *)(iVar7 + -8) = iVar15;
            *(undefined4 *)(iVar7 + -0xc) = 0x802ba2;
            iVar10 = ___ascii_stricmp(*(char **)(iVar7 + -8),*(char **)(iVar7 + -4));
            if (iVar10 == 0) {
              iVar15 = iVar15 + 5;
LAB_00802c12:
              *(int *)(unaff_EBP + -0x24) = iVar15;
            }
            else {
              *(undefined **)(iVar7 + -4) = &DAT_00a05ea0;
              *(int *)(iVar7 + -8) = iVar15;
              *(undefined4 *)(iVar7 + -0xc) = 0x802c09;
              iVar10 = ___ascii_stricmp(*(char **)(iVar7 + -8),*(char **)(iVar7 + -4));
              if (iVar10 == 0) {
                iVar15 = iVar15 + 3;
                goto LAB_00802c12;
              }
            }
            *(undefined1 *)(unaff_EBP + -0x19) = 0x70;
            goto LAB_00802deb;
          }
          *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + uVar14;
          if ((uVar14 & 1) != 0) {
            pbVar12 = *(byte **)(unaff_EBP + -0x20);
            while( true ) {
              bVar1 = *pbVar12;
              if ((bVar1 == 0) || (*puVar5 == 0)) goto LAB_00802e4b;
              if (bVar1 == 0x27) break;
              if (((*(byte *)(*(int *)(*(int *)(unaff_EBP + 8) + 0x48) + 1 + (uint)bVar1 * 2) & 0x80
                   ) == 0) || (*puVar5 < 2)) {
                pcVar9 = *(char **)(unaff_EBP + -0x20);
              }
              else {
                pcVar9 = (char *)(*(int *)(unaff_EBP + -0x20) + 1);
                if (*pcVar9 == '\0') goto LAB_00802e0e;
                *(byte *)*piVar3 = bVar1;
                *piVar3 = *piVar3 + 1;
                *puVar5 = *puVar5 - 1;
              }
              *(char *)*piVar3 = *pcVar9;
              *piVar3 = *piVar3 + 1;
              pbVar12 = (byte *)(pcVar9 + 1);
              *(byte **)(unaff_EBP + -0x20) = pbVar12;
              *puVar5 = *puVar5 - 1;
            }
            *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
          }
        }
        else {
          if (cVar11 != 'h') {
            if (cVar11 == 'm') {
              if (uVar13 == 0) {
                *(undefined4 *)(unaff_EBP + -0x28) = 1;
              }
              else if (uVar13 != 1) goto LAB_00802deb;
              *(undefined1 *)(unaff_EBP + -0x19) = 0x4d;
              goto LAB_00802deb;
            }
            if (cVar11 == 's') {
              if (uVar13 == 0) {
                *(undefined4 *)(unaff_EBP + -0x28) = 1;
              }
              else if (uVar13 != 1) goto LAB_00802deb;
              *(undefined1 *)(unaff_EBP + -0x19) = 0x53;
              goto LAB_00802deb;
            }
            if (cVar11 != 't') {
              if (cVar11 == 'y') {
                if (uVar13 == 1) {
                  *(undefined1 *)(unaff_EBP + -0x19) = 0x79;
                }
                else if (uVar13 == 3) {
                  *(undefined1 *)(unaff_EBP + -0x19) = 0x59;
                }
              }
              goto LAB_00802deb;
            }
            if (*(int *)(iVar15 + 8) < 0xc) {
              pbVar12 = *(byte **)(*(int *)(unaff_EBP + 0x1c) + 0x98);
            }
            else {
              pbVar12 = *(byte **)(*(int *)(unaff_EBP + 0x1c) + 0x9c);
            }
            if ((uVar14 != 1) || (*puVar5 == 0)) {
              while( true ) {
                bVar1 = *pbVar12;
                if ((bVar1 == 0) || (*puVar5 == 0)) break;
                if (((*(byte *)(*(int *)(*(int *)(unaff_EBP + 8) + 0x48) + 1 + (uint)bVar1 * 2) &
                     0x80) != 0) && (1 < *puVar5)) {
                  pbVar12 = pbVar12 + 1;
                  if (*pbVar12 == 0) goto LAB_00802e0e;
                  *(byte *)*piVar3 = bVar1;
                  *piVar3 = *piVar3 + 1;
                  *puVar5 = *puVar5 - 1;
                }
                *(byte *)*piVar3 = *pbVar12;
                *piVar3 = *piVar3 + 1;
                pbVar12 = pbVar12 + 1;
                *puVar5 = *puVar5 - 1;
              }
              goto LAB_00802d9d;
            }
            bVar1 = *pbVar12;
            if (((*(byte *)(*(int *)(*(int *)(unaff_EBP + 8) + 0x48) + 1 + (uint)bVar1 * 2) & 0x80)
                 == 0) || (*puVar5 < 2)) {
LAB_00802d54:
              *(byte *)*piVar3 = *pbVar12;
              *piVar3 = *piVar3 + 1;
              *puVar5 = *puVar5 - 1;
              goto LAB_00802d9d;
            }
            pbVar12 = pbVar12 + 1;
            if (*pbVar12 != 0) {
              *(byte *)*piVar3 = bVar1;
              *piVar3 = *piVar3 + 1;
              *puVar5 = *puVar5 - 1;
              goto LAB_00802d54;
            }
LAB_00802e0e:
            uVar8 = 0;
            goto LAB_00802b27;
          }
          if (uVar13 == 0) {
            *(undefined4 *)(unaff_EBP + -0x28) = 1;
          }
          else if (uVar13 != 1) goto LAB_00802deb;
          *(undefined1 *)(unaff_EBP + -0x19) = 0x49;
LAB_00802deb:
          if (*(char *)(unaff_EBP + -0x19) == '\0') {
            pbVar12 = *(byte **)(unaff_EBP + -0x20);
            bVar1 = *pbVar12;
            if (((*(byte *)(*(int *)(*(int *)(unaff_EBP + 8) + 0x48) + 1 + (uint)bVar1 * 2) & 0x80)
                 != 0) && (1 < *puVar5)) {
              pbVar12 = pbVar12 + 1;
              if (*pbVar12 == 0) goto LAB_00802e0e;
              *(byte *)*piVar3 = bVar1;
              *piVar3 = *piVar3 + 1;
              *puVar5 = *puVar5 - 1;
            }
            *(byte *)*piVar3 = *pbVar12;
            *piVar3 = *piVar3 + 1;
            *(byte **)(unaff_EBP + -0x20) = pbVar12 + 1;
            *puVar5 = *puVar5 - 1;
          }
          else {
            *(undefined4 *)(iVar7 + -4) = *(undefined4 *)(unaff_EBP + -0x28);
            *(undefined4 *)(iVar7 + -8) = *(undefined4 *)(unaff_EBP + 0x1c);
            *(undefined4 *)(iVar7 + -0xc) = *(undefined4 *)(unaff_EBP + 0x10);
            *(undefined4 *)(iVar7 + -0x10) = *(undefined4 *)(unaff_EBP + 8);
            *(undefined4 *)(iVar7 + -0x14) = 0x802e07;
            iVar15 = __expandtime();
            if (iVar15 == 0) goto LAB_00802e0e;
LAB_00802d9d:
            *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x24);
          }
        }
LAB_00802e4b:
        cVar11 = **(char **)(unaff_EBP + -0x20);
        if (cVar11 == '\0') break;
        iVar15 = *(int *)(unaff_EBP + 0x10);
      }
    }
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x34) = 1;
    *(void **)(unaff_EBP + -0x24) = pvVar6;
    *(undefined4 *)(iVar7 + -4) = *(undefined4 *)(unaff_EBP + -0x2c);
    *(void **)(iVar7 + -8) = pvVar6;
    *(undefined4 *)(iVar7 + -0xc) = *(undefined4 *)(unaff_EBP + -0x20);
    *(int *)(iVar7 + -0x10) = unaff_EBP + -0x48;
    *(undefined4 *)(iVar7 + -0x14) = 0;
    *(undefined4 *)(iVar7 + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + 0x1c) + 0xac);
    pcVar2 = *(code **)(unaff_EBP + -0x30);
    puVar16 = (undefined1 *)(iVar7 + -0x1c);
    *(undefined4 *)(iVar7 + -0x1c) = 0x802af2;
    iVar7 = (*pcVar2)();
    iVar7 = iVar7 + -1;
    if (0 < iVar7) {
      piVar3 = *(int **)(unaff_EBP + 0x18);
      piVar4 = *(int **)(unaff_EBP + 0x14);
      do {
        if (*piVar3 == 0) break;
        *(undefined1 *)*piVar4 = **(undefined1 **)(unaff_EBP + -0x24);
        *piVar4 = *piVar4 + 1;
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
        *piVar3 = *piVar3 + -1;
        iVar7 = iVar7 + -1;
      } while (0 < iVar7);
    }
    if (*(int *)(unaff_EBP + -0x34) != 0) {
      *(void **)(puVar16 + -4) = pvVar6;
      *(undefined4 *)(puVar16 + -8) = 0x802b23;
      _free(*(void **)(puVar16 + -4));
      return extraout_EAX;
    }
  }
  uVar8 = 1;
LAB_00802b27:
  *(undefined4 *)(unaff_EBP + -0x58) = 0x802b2f;
  return uVar8;
}


// ==== FUN_00802e5d @ 0x00802e5d ====

int FUN_00802e5d(int param_1,byte *param_2,uint param_3,byte *param_4,undefined4 param_5,
                uint param_6)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  
  pbVar2 = param_2;
  iVar3 = param_6;
  if (param_6 == 0) {
    iVar3 = *(int *)(param_1 + 0x4c);
  }
  if (param_3 != 0) {
    param_6 = param_3;
    if (param_3 != 0) {
      do {
        bVar1 = *param_4;
        if (bVar1 == 0) break;
        if (bVar1 == 0x25) {
          pbVar5 = param_4 + 1;
          bVar1 = *pbVar5;
          if (bVar1 == 0x23) {
            pbVar5 = param_4 + 2;
          }
          iVar4 = __expandtime(param_1,param_5,iVar3,bVar1 == 0x23);
          if (iVar4 == 0) goto LAB_00802f13;
        }
        else {
          if (((*(byte *)(*(int *)(param_1 + 0x48) + 1 + (uint)bVar1 * 2) & 0x80) != 0) &&
             (1 < param_6)) {
            param_4 = param_4 + 1;
            if (*param_4 == 0) goto LAB_00802f13;
            *param_2 = bVar1;
            param_2 = param_2 + 1;
            param_6 = param_6 - 1;
          }
          *param_2 = *param_4;
          param_2 = param_2 + 1;
          param_6 = param_6 - 1;
          pbVar5 = param_4;
        }
        param_4 = pbVar5 + 1;
      } while (param_6 != 0);
      if (param_6 != 0) {
        *param_2 = 0;
        return param_3 - param_6;
      }
    }
LAB_00802f13:
    *pbVar2 = 0;
  }
  return 0;
}


// ==== __Strftime @ 0x00802f20 ====

/* Library Function - Single Match
    __Strftime
   
   Library: Visual Studio 2003 Release */

size_t __cdecl __Strftime(char *param_1,size_t _Maxsize,char *param_3,tm *param_4,void *param_5)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  size_t sVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  sVar3 = FUN_00802e5d(ptVar2,param_1,_Maxsize,param_3,param_4,param_5);
  return sVar3;
}


// ==== _strftime @ 0x00802f52 ====

/* Library Function - Single Match
    _strftime
   
   Library: Visual Studio 2003 Release */

size_t __cdecl _strftime(char *_Buf,size_t _SizeInBytes,char *_Format,tm *_Tm)

{
  size_t sVar1;
  
  sVar1 = __Strftime(_Buf,_SizeInBytes,_Format,_Tm,(void *)0x0);
  return sVar1;
}


// ==== _localtime @ 0x00802f6d ====

/* Library Function - Single Match
    _localtime
   
   Library: Visual Studio 2003 Release */

tm * __cdecl _localtime(time_t *_Time)

{
  time_t *_Time_00;
  tm *ptVar1;
  int iVar2;
  
  _Time_00 = _Time;
  if ((int)*_Time < 0) {
    return (tm *)0x0;
  }
  ___tzset();
  iVar2 = (int)*_Time_00;
  if ((0x3f480 < iVar2) && (iVar2 < 0x7ffc0b7f)) {
    _Time = (time_t *)(iVar2 - DAT_00b49e60);
    ptVar1 = _gmtime((time_t *)&_Time);
    if (DAT_00b49e64 == 0) {
      return ptVar1;
    }
    iVar2 = __isindst(ptVar1);
    if (iVar2 == 0) {
      return ptVar1;
    }
    _Time = (time_t *)((int)_Time - DAT_00b49e68);
    ptVar1 = _gmtime((time_t *)&_Time);
    ptVar1->tm_isdst = 1;
    return ptVar1;
  }
  ptVar1 = _gmtime(_Time_00);
  if ((DAT_00b49e64 == 0) || (iVar2 = __isindst(ptVar1), iVar2 == 0)) {
    _Time = (time_t *)(ptVar1->tm_sec - DAT_00b49e60);
  }
  else {
    _Time = (time_t *)((ptVar1->tm_sec - DAT_00b49e68) - DAT_00b49e60);
    ptVar1->tm_isdst = 1;
  }
  iVar2 = (int)_Time % 0x3c;
  ptVar1->tm_sec = iVar2;
  if (iVar2 < 0) {
    ptVar1->tm_sec = iVar2 + 0x3c;
    _Time = (time_t *)((int)_Time + -0x3c);
  }
  _Time = (time_t *)((int)_Time / 0x3c + ptVar1->tm_min);
  iVar2 = (int)_Time % 0x3c;
  ptVar1->tm_min = iVar2;
  if (iVar2 < 0) {
    ptVar1->tm_min = iVar2 + 0x3c;
    _Time = (time_t *)((int)_Time + -0x3c);
  }
  _Time = (time_t *)((int)_Time / 0x3c + ptVar1->tm_hour);
  iVar2 = (int)_Time % 0x18;
  ptVar1->tm_hour = iVar2;
  if (iVar2 < 0) {
    ptVar1->tm_hour = iVar2 + 0x18;
    _Time = _Time + -3;
  }
  iVar2 = (int)_Time / 0x18;
  if (iVar2 < 1) {
    if (-1 < iVar2) {
      return ptVar1;
    }
    ptVar1->tm_wday = (ptVar1->tm_wday + 7 + iVar2) % 7;
    ptVar1->tm_mday = ptVar1->tm_mday + iVar2;
    if (ptVar1->tm_mday < 1) {
      ptVar1->tm_year = ptVar1->tm_year + -1;
      ptVar1->tm_mday = ptVar1->tm_mday + 0x1f;
      ptVar1->tm_yday = 0x16c;
      ptVar1->tm_mon = 0xb;
      return ptVar1;
    }
  }
  else {
    ptVar1->tm_wday = (ptVar1->tm_wday + iVar2) % 7;
    ptVar1->tm_mday = ptVar1->tm_mday + iVar2;
  }
  ptVar1->tm_yday = ptVar1->tm_yday + iVar2;
  return ptVar1;
}


// ==== _atol @ 0x008030ed ====

/* Library Function - Single Match
    _atol
   
   Library: Visual Studio 2003 Release */

long __cdecl _atol(char *_Str)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  while( true ) {
    if ((int)ptVar2->lc_category[1].refcount < 2) {
      uVar3 = *(byte *)((int)ptVar2->lc_category[3].refcount + (uint)(byte)*_Str * 2) & 8;
    }
    else {
      uVar3 = ___isctype_mt(ptVar2,(uint)(byte)*_Str,8);
    }
    if (uVar3 == 0) break;
    _Str = _Str + 1;
  }
  uVar3 = (uint)(byte)*_Str;
  pbVar7 = (byte *)(_Str + 1);
  if ((uVar3 == 0x2d) || (uVar5 = uVar3, uVar3 == 0x2b)) {
    uVar5 = (uint)*pbVar7;
    pbVar7 = (byte *)(_Str + 2);
  }
  iVar4 = 0;
  while( true ) {
    if ((uVar5 < 0x30) || (0x39 < uVar5)) {
      iVar6 = -1;
    }
    else {
      iVar6 = uVar5 - 0x30;
    }
    if (iVar6 == -1) break;
    iVar4 = iVar6 + iVar4 * 10;
    uVar5 = (uint)*pbVar7;
    pbVar7 = pbVar7 + 1;
  }
  if (uVar3 == 0x2d) {
    iVar4 = -iVar4;
  }
  return iVar4;
}


// ==== __atoi64 @ 0x0080317a ====

/* Library Function - Single Match
    __atoi64
   
   Library: Visual Studio 2003 Release */

longlong __cdecl __atoi64(char *_String)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  while( true ) {
    if ((int)ptVar2->lc_category[1].refcount < 2) {
      uVar3 = *(byte *)((int)ptVar2->lc_category[3].refcount + (uint)(byte)*_String * 2) & 8;
    }
    else {
      uVar3 = ___isctype_mt(ptVar2,(uint)(byte)*_String,8);
    }
    if (uVar3 == 0) break;
    _String = _String + 1;
  }
  uVar3 = (uint)(byte)*_String;
  pbVar4 = (byte *)(_String + 1);
  if ((uVar3 == 0x2d) || (uVar5 = uVar3, uVar3 == 0x2b)) {
    uVar5 = (uint)*pbVar4;
    pbVar4 = (byte *)(_String + 2);
  }
  lVar7 = 0;
  while( true ) {
    if ((uVar5 < 0x30) || (0x39 < uVar5)) {
      iVar6 = -1;
    }
    else {
      iVar6 = uVar5 - 0x30;
    }
    if (iVar6 == -1) break;
    lVar7 = __allmul(lVar7,10,0);
    uVar5 = (uint)*pbVar4;
    lVar7 = lVar7 + iVar6;
    pbVar4 = pbVar4 + 1;
  }
  if (uVar3 == 0x2d) {
    lVar7 = CONCAT44(-((int)((ulonglong)lVar7 >> 0x20) + (uint)((int)lVar7 != 0)),-(int)lVar7);
  }
  return lVar7;
}


// ==== wcstoxl @ 0x00803221 ====

/* Library Function - Single Match
    _wcstoxl
   
   Library: Visual Studio 2003 Release */

uint __cdecl wcstoxl(ushort *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  ushort *puVar1;
  _ptiddata p_Var2;
  pthreadlocinfo ptVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  ushort *puVar9;
  ushort uVar10;
  uint local_8;
  
  p_Var2 = __getptd();
  ptVar3 = (pthreadlocinfo)p_Var2->_tfpecode;
  if (ptVar3 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar3 = ___updatetlocinfo();
  }
  local_8 = 0;
  uVar10 = *param_1;
  puVar1 = param_1;
  while( true ) {
    uVar7 = (uint)uVar10;
    puVar9 = puVar1 + 1;
    iVar4 = ___iswctype_mt(ptVar3,uVar7,8);
    if (iVar4 == 0) break;
    uVar10 = *puVar9;
    puVar1 = puVar9;
  }
  if (uVar10 == 0x2d) {
    param_4 = param_4 | 2;
LAB_0080327a:
    uVar7 = (uint)*puVar9;
    puVar9 = puVar1 + 2;
  }
  else if (uVar10 == 0x2b) goto LAB_0080327a;
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
    }
    return 0;
  }
  if (param_3 == 0) {
    iVar4 = __wchartodigit(uVar7);
    if (iVar4 != 0) {
      param_3 = 10;
      goto LAB_008032fa;
    }
    if ((*puVar9 != 0x78) && (*puVar9 != 0x58)) {
      param_3 = 8;
      goto LAB_008032fa;
    }
    param_3 = 0x10;
  }
  if (((param_3 == 0x10) && (iVar4 = __wchartodigit(uVar7), iVar4 == 0)) &&
     ((*puVar9 == 0x78 || (*puVar9 == 0x58)))) {
    uVar7 = (uint)puVar9[1];
    puVar9 = puVar9 + 2;
  }
LAB_008032fa:
  uVar5 = (uint)(0xffffffff / (ulonglong)param_3);
  do {
    uVar6 = __wchartodigit(uVar7);
    if (uVar6 == 0xffffffff) {
      uVar10 = (ushort)uVar7;
      if (((uVar10 < 0x41) || (0x5a < uVar10)) && ((uVar10 < 0x61 || (0x7a < uVar10)))) {
LAB_00803373:
        puVar9 = puVar9 + -1;
        if ((param_4 & 8) == 0) {
          if (param_2 != (undefined4 *)0x0) {
            puVar9 = param_1;
          }
          local_8 = 0;
        }
        else if (((param_4 & 4) != 0) ||
                (((param_4 & 1) == 0 &&
                 ((((param_4 & 2) != 0 && (0x80000000 < local_8)) ||
                  (((param_4 & 2) == 0 && (0x7fffffff < local_8)))))))) {
          puVar8 = (undefined4 *)FUN_00804b94();
          *puVar8 = 0x22;
          if ((param_4 & 1) == 0) {
            local_8 = ((param_4 & 2) != 0) + 0x7fffffff;
          }
          else {
            local_8 = 0xffffffff;
          }
        }
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = puVar9;
        }
        if ((param_4 & 2) != 0) {
          local_8 = -local_8;
        }
        return local_8;
      }
      if ((0x60 < uVar10) && (uVar10 < 0x7b)) {
        uVar7 = uVar7 - 0x20;
      }
      uVar6 = uVar7 - 0x37;
    }
    if (param_3 <= uVar6) goto LAB_00803373;
    if ((local_8 < uVar5) ||
       ((local_8 == uVar5 && (uVar6 <= (uint)(0xffffffff % (ulonglong)param_3))))) {
      local_8 = local_8 * param_3 + uVar6;
      param_4 = param_4 | 8;
    }
    else {
      param_4 = param_4 | 0xc;
    }
    uVar7 = (uint)*puVar9;
    puVar9 = puVar9 + 1;
  } while( true );
}


// ==== _wcstoul @ 0x00803400 ====

/* Library Function - Single Match
    _wcstoul
   
   Library: Visual Studio 2003 Release */

ulong __cdecl _wcstoul(wchar_t *_Str,wchar_t **_EndPtr,int _Radix)

{
  ulong uVar1;
  
  uVar1 = wcstoxl(_Str,_EndPtr,_Radix,1);
  return uVar1;
}


// ==== FUN_00803417 @ 0x00803417 ====

int FUN_00803417(short *param_1)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = param_1;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  return ((int)psVar2 - (int)param_1 >> 1) + -1;
}


// ==== __chkstk @ 0x00803430 ====

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    __chkstk
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2003 Release */

void __chkstk(undefined1 param_1)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  if (in_EAX < 0x1000) {
    *(undefined4 *)((int)register0x00000010 - in_EAX) = unaff_retaddr;
    return;
  }
  puVar1 = &param_1;
  do {
    puVar1 = puVar1 + -0x1000;
    in_EAX = in_EAX - 0x1000;
  } while (0xfff < in_EAX);
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}


// ==== FUN_0080346d @ 0x0080346d ====

int FUN_0080346d(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = (int)in_ECX - *(int *)(*(int *)(*in_ECX + -4) + 4);
  iVar1 = *(int *)(*(int *)(*in_ECX + -4) + 8);
  if (iVar1 != 0) {
    iVar2 = iVar2 + *(int *)((int)in_ECX - iVar1);
  }
  return iVar2;
}


// ==== FindSITargetTypeInstance @ 0x00803483 ====

/* Library Function - Single Match
    struct _s_RTTIBaseClassDescriptor const * __cdecl FindSITargetTypeInstance(void *,struct
   _s_RTTICompleteObjectLocator const *,struct TypeDescriptor *,int,struct TypeDescriptor *)
   
   Library: Visual Studio 2003 Release */

_s_RTTIBaseClassDescriptor * __cdecl
FindSITargetTypeInstance
          (void *param_1,_s_RTTICompleteObjectLocator *param_2,TypeDescriptor *param_3,int param_4,
          TypeDescriptor *param_5)

{
  _s_RTTIBaseClassDescriptor *p_Var1;
  int iVar2;
  int unaff_EBX;
  int *piVar3;
  uint local_8;
  
  local_8 = 0;
  piVar3 = *(int **)(*(int *)(unaff_EBX + 0x10) + 0xc);
  if (*(int *)(*(int *)(unaff_EBX + 0x10) + 8) != 0) {
    do {
      p_Var1 = (_s_RTTIBaseClassDescriptor *)*piVar3;
      if (((*(void **)p_Var1 == param_1) ||
          (iVar2 = _strcmp((char *)((int)*(void **)p_Var1 + 8),(char *)((int)param_1 + 8)),
          iVar2 == 0)) && (((byte)p_Var1[0x14] & 1) == 0)) {
        return p_Var1;
      }
      local_8 = local_8 + 1;
      piVar3 = piVar3 + 1;
    } while (local_8 < *(uint *)(*(int *)(unaff_EBX + 0x10) + 8));
  }
  return (_s_RTTIBaseClassDescriptor *)0x0;
}


// ==== PMDtoOffset @ 0x008034d8 ====

/* Library Function - Single Match
    int __cdecl PMDtoOffset(void *,struct PMD const &)
   
   Library: Visual Studio 2003 Release */

int __cdecl PMDtoOffset(void *param_1,PMD *param_2)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  
  iVar1 = in_EAX[1];
  iVar2 = 0;
  if (-1 < iVar1) {
    iVar2 = iVar1 + *(int *)(*(int *)(iVar1 + (int)param_1) + in_EAX[2]);
  }
  return *in_EAX + iVar2;
}


// ==== FindMITargetTypeInstance @ 0x008034f7 ====

/* Library Function - Single Match
    struct _s_RTTIBaseClassDescriptor const * __cdecl FindMITargetTypeInstance(void *,struct
   _s_RTTICompleteObjectLocator const *,struct TypeDescriptor *,int,struct TypeDescriptor *)
   
   Library: Visual Studio 2003 Release */

_s_RTTIBaseClassDescriptor * __cdecl
FindMITargetTypeInstance
          (void *param_1,_s_RTTICompleteObjectLocator *param_2,TypeDescriptor *param_3,int param_4,
          TypeDescriptor *param_5)

{
  _s_RTTIBaseClassDescriptor *p_Var1;
  int iVar2;
  TypeDescriptor *pTVar3;
  int unaff_EBX;
  int *piVar4;
  PMD *unaff_EDI;
  uint local_10;
  int *local_c;
  uint local_8;
  
  local_8 = 0;
  piVar4 = *(int **)(*(int *)(unaff_EBX + 0x10) + 0xc);
  if (*(int *)(*(int *)(unaff_EBX + 0x10) + 8) != 0) {
    do {
      p_Var1 = (_s_RTTIBaseClassDescriptor *)*piVar4;
      if (((*(int *)p_Var1 == param_4) ||
          (iVar2 = _strcmp((char *)(*(int *)p_Var1 + 8),(char *)(param_4 + 8)), iVar2 == 0)) &&
         (local_10 = 0, local_c = piVar4, *(int *)(p_Var1 + 4) != 0)) {
        do {
          local_c = local_c + 1;
          if (((*(_s_RTTICompleteObjectLocator **)*local_c == param_2) ||
              (iVar2 = _strcmp((char *)(*(_s_RTTICompleteObjectLocator **)*local_c + 8),
                               (char *)(param_2 + 8)), iVar2 == 0)) &&
             (pTVar3 = (TypeDescriptor *)PMDtoOffset(param_1,unaff_EDI), pTVar3 == param_3)) {
            return p_Var1;
          }
          local_10 = local_10 + 1;
        } while (local_10 < *(uint *)(p_Var1 + 4));
      }
      local_8 = local_8 + 1;
      piVar4 = piVar4 + 1;
    } while (local_8 < *(uint *)(*(int *)(unaff_EBX + 0x10) + 8));
  }
  local_8 = 0;
  piVar4 = *(int **)(*(int *)(unaff_EBX + 0x10) + 0xc);
  if (*(int *)(*(int *)(unaff_EBX + 0x10) + 8) != 0) {
    do {
      p_Var1 = (_s_RTTIBaseClassDescriptor *)*piVar4;
      if (((*(int *)p_Var1 == param_4) ||
          (iVar2 = _strcmp((char *)(*(int *)p_Var1 + 8),(char *)(param_4 + 8)), iVar2 == 0)) &&
         (((byte)p_Var1[0x14] & 3) == 0)) {
        return p_Var1;
      }
      local_8 = local_8 + 1;
      piVar4 = piVar4 + 1;
    } while (local_8 < *(uint *)(*(int *)(unaff_EBX + 0x10) + 8));
  }
  return (_s_RTTIBaseClassDescriptor *)0x0;
}


// ==== FindVITargetTypeInstance @ 0x008035f0 ====

/* Library Function - Single Match
    struct _s_RTTIBaseClassDescriptor const * __cdecl FindVITargetTypeInstance(void *,struct
   _s_RTTICompleteObjectLocator const *,struct TypeDescriptor *,int,struct TypeDescriptor *)
   
   Library: Visual Studio 2003 Release */

_s_RTTIBaseClassDescriptor * __cdecl
FindVITargetTypeInstance
          (void *param_1,_s_RTTICompleteObjectLocator *param_2,TypeDescriptor *param_3,int param_4,
          TypeDescriptor *param_5)

{
  _s_RTTIBaseClassDescriptor *p_Var1;
  int iVar2;
  int iVar3;
  PMD *unaff_EDI;
  int *piVar4;
  PMD *pPVar5;
  uint local_14;
  int *local_10;
  _s_RTTIBaseClassDescriptor *local_c;
  uint local_8;
  
  piVar4 = *(int **)(*(int *)(param_2 + 0x10) + 0xc);
  local_c = (_s_RTTIBaseClassDescriptor *)0x0;
  local_8 = 0;
  if (*(int *)(*(int *)(param_2 + 0x10) + 8) != 0) {
    do {
      p_Var1 = (_s_RTTIBaseClassDescriptor *)*piVar4;
      if (((*(TypeDescriptor **)p_Var1 == param_5) ||
          (iVar2 = _strcmp((char *)(*(TypeDescriptor **)p_Var1 + 1),(char *)(param_5 + 1)),
          iVar2 == 0)) && (local_14 = 0, local_10 = piVar4, *(int *)(p_Var1 + 4) != 0)) {
        do {
          local_10 = local_10 + 1;
          if (((*(TypeDescriptor **)*local_10 == param_3) ||
              (iVar2 = _strcmp((char *)(*(TypeDescriptor **)*local_10 + 1),(char *)(param_3 + 1)),
              iVar2 == 0)) && (iVar2 = PMDtoOffset(param_1,unaff_EDI), iVar2 == param_4)) {
            if (local_c != (_s_RTTIBaseClassDescriptor *)0x0) {
              pPVar5 = param_1;
              iVar2 = PMDtoOffset(param_1,unaff_EDI);
              iVar3 = PMDtoOffset(param_1,pPVar5);
              if (iVar3 != iVar2) {
                return (_s_RTTIBaseClassDescriptor *)0x0;
              }
            }
            local_c = p_Var1;
          }
          local_14 = local_14 + 1;
        } while (local_14 < *(uint *)(p_Var1 + 4));
      }
      local_8 = local_8 + 1;
      piVar4 = piVar4 + 1;
    } while (local_8 < *(uint *)(*(int *)(param_2 + 0x10) + 8));
    if (local_c != (_s_RTTIBaseClassDescriptor *)0x0) {
      return local_c;
    }
  }
  piVar4 = *(int **)(*(int *)(param_2 + 0x10) + 0xc);
  local_8 = 0;
  if (*(int *)(*(int *)(param_2 + 0x10) + 8) != 0) {
    do {
      p_Var1 = (_s_RTTIBaseClassDescriptor *)*piVar4;
      if (((*(TypeDescriptor **)p_Var1 == param_5) ||
          (iVar2 = _strcmp((char *)(*(TypeDescriptor **)p_Var1 + 1),(char *)(param_5 + 1)),
          iVar2 == 0)) && (((byte)p_Var1[0x14] & 3) == 0)) {
        return p_Var1;
      }
      local_8 = local_8 + 1;
      piVar4 = piVar4 + 1;
    } while (local_8 < *(uint *)(*(int *)(param_2 + 0x10) + 8));
  }
  return (_s_RTTIBaseClassDescriptor *)0x0;
}


// ==== FUN_00803725 @ 0x00803725 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

int FUN_00803725(int *param_1,int param_2,TypeDescriptor *param_3,TypeDescriptor *param_4,
                int param_5)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBX;
  TypeDescriptor *unaff_ESI;
  TypeDescriptor *unaff_EDI;
  TypeDescriptor *in_stack_ffffffb8;
  undefined1 local_3c [12];
  TypeDescriptor *local_30;
  _s_RTTICompleteObjectLocator *local_2c;
  void *local_28;
  undefined4 local_24;
  _s_RTTIBaseClassDescriptor *local_20;
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x803731;
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    local_8 = 0;
    pvVar2 = (void *)FUN_0080346d();
    local_2c = *(_s_RTTICompleteObjectLocator **)(*param_1 + -4);
    local_30 = (TypeDescriptor *)((int)param_1 + (-(int)pvVar2 - param_2));
    local_28 = pvVar2;
    if ((*(uint *)(*(int *)(local_2c + 0x10) + 4) & 1) == 0) {
      local_20 = FindSITargetTypeInstance
                           (param_4,(_s_RTTICompleteObjectLocator *)unaff_EDI,unaff_ESI,unaff_EBX,
                            in_stack_ffffffb8);
    }
    else if ((*(uint *)(*(int *)(local_2c + 0x10) + 4) & 2) == 0) {
      local_20 = FindMITargetTypeInstance
                           (pvVar2,(_s_RTTICompleteObjectLocator *)param_3,local_30,(int)param_4,
                            unaff_EDI);
    }
    else {
      local_20 = FindVITargetTypeInstance(pvVar2,local_2c,param_3,(int)local_30,param_4);
    }
    if (local_20 == (_s_RTTIBaseClassDescriptor *)0x0) {
      iVar1 = 0;
      local_24 = 0;
      if (param_5 != 0) {
        FUN_00801824(s_Bad_dynamic_cast__00a05ee0);
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_3c,&DAT_00ad1070);
      }
    }
    else {
      iVar1 = PMDtoOffset(pvVar2,(PMD *)unaff_EDI);
      iVar1 = iVar1 + (int)pvVar2;
    }
  }
  return iVar1;
}


// ==== FUN_008037e6 @ 0x008037e6 ====

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_008037e6(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(char **)(iVar1 + -4) = s_Access_violation___no_RTTI_data__00a05ebc;
  *(undefined4 *)(iVar1 + -8) = 0x8037f6;
  FUN_00801891();
  *(undefined **)(iVar1 + -4) = &DAT_00ad1038;
  *(int *)(iVar1 + -8) = unaff_EBP + -0x44;
                    /* WARNING: Subroutine does not return */
  *(undefined4 *)(iVar1 + -0xc) = 0x803804;
  __CxxThrowException_8();
}


// ==== ___tolower_mt @ 0x00803805 ====

/* Library Function - Single Match
    ___tolower_mt
   
   Library: Visual Studio 2003 Release */

uint ___tolower_mt(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_8;
  
  uVar2 = param_2;
  iVar5 = param_1;
  if ((*(int *)(param_1 + 0x14) == 0) || ((*(int *)(param_1 + 0x24) != 0 && (param_2 < 0x80)))) {
    if ((0x40 < (int)param_2) && ((int)param_2 < 0x5b)) {
      return param_2 + 0x20;
    }
  }
  else {
    if (param_2 < 0x100) {
      if (*(int *)(param_1 + 0x28) < 2) {
        uVar3 = *(byte *)(*(int *)(param_1 + 0x48) + param_2 * 2) & 1;
      }
      else {
        uVar3 = ___isctype_mt(param_1,param_2,1);
      }
      if (uVar3 == 0) {
        return uVar2;
      }
    }
    iVar1 = param_1;
    if ((*(byte *)(*(int *)(iVar5 + 0x48) + 1 + ((int)uVar2 >> 8 & 0xffU) * 2) & 0x80) == 0) {
      param_1._0_2_ = (ushort)(byte)uVar2;
      uVar4 = 1;
    }
    else {
      param_1._0_2_ = CONCAT11((byte)uVar2,(char)(uVar2 >> 8));
      param_1._3_1_ = SUB41(iVar1,3);
      param_1._0_3_ = (uint3)(ushort)param_1;
      uVar4 = 2;
    }
    iVar5 = FUN_0080cc3e(*(undefined4 *)(iVar5 + 0x14),0x100,&param_1,uVar4,&local_8,3,
                         *(undefined4 *)(iVar5 + 4),1);
    if (iVar5 != 0) {
      if (iVar5 == 1) {
        return local_8 & 0xff;
      }
      return (uint)CONCAT11((undefined1)local_8,local_8._1_1_);
    }
  }
  return uVar2;
}


// ==== _tolower @ 0x008038cd ====

/* Library Function - Single Match
    _tolower
   
   Library: Visual Studio 2003 Release */

int __cdecl _tolower(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  iVar3 = ___tolower_mt(ptVar2,_C);
  return iVar3;
}


// ==== __copysign @ 0x008038ef ====

/* Library Function - Single Match
    __copysign
   
   Library: Visual Studio 2003 Release */

double __cdecl __copysign(double _Number,double _Sign)

{
  return (double)CONCAT44((_Sign._4_4_ ^ _Number._4_4_) & 0x7fffffff ^ _Sign._4_4_,_Number._0_4_);
}


// ==== FUN_00803910 @ 0x00803910 ====

bool FUN_00803910(undefined4 param_1,undefined4 param_2)

{
  return (param_2._2_2_ & 0x7ff0) != 0x7ff0;
}


// ==== __isnan @ 0x00803925 ====

/* Library Function - Single Match
    __isnan
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

int __cdecl __isnan(double _X)

{
  if ((((_X._6_2_ & 0x7ff8) == 0x7ff0) &&
      ((((ulonglong)_X & 0x7ffff00000000) != 0 || (_X._0_4_ != 0)))) ||
     ((_X._6_2_ & 0x7ff8) == 0x7ff8)) {
    return 1;
  }
  return 0;
}


// ==== __fpclass @ 0x00803953 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fpclass
   
   Library: Visual Studio 2003 Release */

int __cdecl __fpclass(double _X)

{
  int iVar1;
  int iStack_8;
  
  if ((_X._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar1 = __sptype();
    if (iVar1 == 1) {
      return 0x200;
    }
    if (iVar1 == 2) {
      iStack_8 = 4;
    }
    else {
      if (iVar1 != 3) {
        return 1;
      }
      iStack_8 = 2;
    }
    return iStack_8;
  }
  if ((((ulonglong)_X & 0x7ff0000000000000) == 0) &&
     ((((ulonglong)_X & 0xfffff00000000) != 0 || (_X._0_4_ != 0)))) {
    return (-(uint)(((ulonglong)_X & 0x8000000000000000) != 0) & 0xffffff90) + 0x80;
  }
  if (_X == _DAT_0099d098) {
    return (-(uint)(((ulonglong)_X & 0x8000000000000000) != 0) & 0xffffffe0) + 0x40;
  }
  return (-(uint)(((ulonglong)_X & 0x8000000000000000) != 0) & 0xffffff08) + 0x100;
}


// ==== report_failure @ 0x008039ef ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* Library Function - Single Match
    _report_failure
   
   Library: Visual Studio 2003 Release */

void __cdecl report_failure(void)

{
  FUN_0080da43(1,0);
                    /* WARNING: Subroutine does not return */
  ExitProcess(3);
}


// ==== FUN_00803a10 @ 0x00803a10 ====

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00803a10(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar1 + -4) = 3;
                    /* WARNING: Subroutine does not return */
  *(undefined4 *)(iVar1 + -8) = 0x803a1f;
  ExitProcess(*(UINT *)(iVar1 + -4));
}


// ==== __security_check_cookie @ 0x00803a20 ====

/* WARNING: This is an inlined function */

void __fastcall __security_check_cookie(uintptr_t _StackCookie)

{
  if (_StackCookie == DAT_00b49670) {
    return;
  }
  report_failure();
  return;
}


// ==== FUN_00803a2e @ 0x00803a2e ====

int FUN_00803a2e(FILE *param_1)

{
  int iVar1;
  int extraout_EAX;
  int iVar2;
  
  iVar2 = -1;
  if ((param_1->_flag & 0x83) != 0) {
    iVar2 = __flush(param_1);
    FUN_0080dcac(param_1);
    iVar1 = __close(param_1->_file);
    if (iVar1 < 0) {
      iVar2 = -1;
    }
    else if (param_1->_tmpfname != (char *)0x0) {
      _free(param_1->_tmpfname);
      return extraout_EAX;
    }
  }
  param_1->_flag = 0;
  return iVar2;
}


// ==== _fclose @ 0x00803a7a ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fclose
   
   Library: Visual Studio 2003 Release */

int __cdecl _fclose(FILE *_File)

{
  int local_20;
  
  local_20 = -1;
  if ((_File->_flag & 0x40) == 0) {
    __lock_file(_File);
    local_20 = FUN_00803a2e(_File);
    FUN_00803ac3();
  }
  else {
    _File->_flag = 0;
  }
  return local_20;
}


// ==== FUN_00803ac3 @ 0x00803ac3 ====

void FUN_00803ac3(void)

{
  FILE *unaff_ESI;
  
  __unlock_file(unaff_ESI);
  return;
}


// ==== __fsopen @ 0x00803acb ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __fsopen
   
   Library: Visual Studio 2003 Release */

FILE * __cdecl __fsopen(char *_Filename,char *_Mode,int _ShFlag)

{
  FILE *pFVar1;
  undefined4 *puVar2;
  
  pFVar1 = (FILE *)FUN_0080de3f();
  if (pFVar1 == (FILE *)0x0) {
    puVar2 = (undefined4 *)FUN_00804b94();
    *puVar2 = 0x18;
    pFVar1 = (FILE *)0x0;
  }
  else {
    pFVar1 = __openfile(_Filename,_Mode,_ShFlag,pFVar1);
    FUN_00803b1d();
  }
  return pFVar1;
}


// ==== FUN_00803b1d @ 0x00803b1d ====

void FUN_00803b1d(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + -0x1c));
  return;
}


// ==== FUN_00803b27 @ 0x00803b27 ====

void FUN_00803b27(char *param_1,char *param_2)

{
  __fsopen(param_1,param_2,0x40);
  return;
}


// ==== __snscanf @ 0x00803b3a ====

/* Library Function - Single Match
    __snscanf
   
   Library: Visual Studio 2003 Release */

int __cdecl __snscanf(char *_Src,size_t _MaxCount,char *_Format,...)

{
  int iVar1;
  undefined1 uStack00000010;
  char *local_24;
  size_t local_20;
  char *local_1c;
  undefined4 local_18;
  
  local_1c = _Src;
  local_24 = _Src;
  local_20 = _MaxCount;
  local_18 = 0x49;
  iVar1 = FUN_0080df77(&local_24,_Format,&uStack00000010);
  return iVar1;
}


// ==== _atof @ 0x00803b6b ====

/* Library Function - Single Match
    _atof
   
   Library: Visual Studio 2003 Release */

double __cdecl _atof(char *_String)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  undefined1 local_1c [24];
  
  while( true ) {
    iVar1 = _isspace((uint)(byte)*_String);
    if (iVar1 == 0) break;
    _String = _String + 1;
  }
  iVar3 = iVar1;
  sVar2 = _strlen(_String);
  iVar1 = FUN_0080eda2(local_1c,_String,sVar2,iVar1,iVar3);
  return *(double *)(iVar1 + 0x10);
}


// ==== __heap_alloc @ 0x00803ba3 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  void *pvVar1;
  LPVOID pvVar2;
  
  if ((DAT_00b60f7c == 3) && (_Size <= DAT_00b60f4c)) {
    __lock(4);
    pvVar1 = (void *)___sbh_alloc_block(_Size);
    FUN_00803c15();
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
  }
  if (_Size == 0) {
    _Size = 1;
  }
  if (DAT_00b60f7c != 1) {
    _Size = _Size + 0xf & 0xfffffff0;
  }
  pvVar2 = HeapAlloc(DAT_00b60f78,0,_Size);
  return pvVar2;
}


// ==== FUN_00803c12 @ 0x00803c12 ====

void FUN_00803c12(void)

{
  FUN_00806c2f(4);
  return;
}


// ==== FUN_00803c15 @ 0x00803c15 ====

void FUN_00803c15(void)

{
  FUN_00806c2f(4);
  return;
}


// ==== __nh_malloc @ 0x00803c1e ====

/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  void *pvVar1;
  int iVar2;
  
  if (_Size < 0xffffffe1) {
    do {
      pvVar1 = __heap_alloc(_Size);
      if (pvVar1 != (void *)0x0) {
        return pvVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = __callnewh(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}


// ==== _malloc @ 0x00803c4a ====

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00b5cb78);
  return pvVar1;
}


// ==== __callnewh @ 0x00803c5c ====

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 2003 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_00b5c640 != (code *)0x0) {
    iVar1 = (*DAT_00b5c640)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== _strlen @ 0x00803c80 ====

/* Library Function - Single Match
    _strlen
   
   Library: Visual Studio */

size_t __cdecl _strlen(char *_Str)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)_Str;
  if (((uint)_Str & 3) != 0) {
    do {
      uVar1 = *puVar2;
      puVar2 = (uint *)((int)puVar2 + 1);
      if ((char)uVar1 == '\0') goto LAB_00803ce3;
    } while (((uint)puVar2 & 3) != 0);
  }
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (int)puVar3 - (int)_Str;
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (size_t)((int)puVar3 + (1 - (int)_Str));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (size_t)((int)puVar3 + (2 - (int)_Str));
    }
  } while ((uVar1 & 0xff000000) != 0);
LAB_00803ce3:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
}


// ==== _memcpy @ 0x00803d10 ====

/* Library Function - Multiple Matches With Different Base Names
    _memcpy
    _memmove
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2003 Release, Visual Studio 2019 Release */

void * __cdecl _memcpy(void *_Dst,void *_Src,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((_Src < _Dst) && (_Dst < (void *)(_Size + (int)_Src))) {
    puVar3 = (undefined4 *)((_Size - 4) + (int)_Src);
    puVar4 = (undefined4 *)((_Size - 4) + (int)_Dst);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = _Size >> 2;
      uVar2 = _Size & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return _Dst;
        case 2:
          goto switchD_00803ecb_caseD_2;
        case 3:
          goto switchD_00803ecb_caseD_3;
        }
        goto switchD_00803ecb_caseD_1;
      }
    }
    else {
      switch(_Size) {
      case 0:
        goto switchD_00803ecb_caseD_0;
      case 1:
        goto switchD_00803ecb_caseD_1;
      case 2:
        goto switchD_00803ecb_caseD_2;
      case 3:
        goto switchD_00803ecb_caseD_3;
      default:
        uVar1 = _Size - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_00803ecb_caseD_2;
            case 3:
              goto switchD_00803ecb_caseD_3;
            }
            goto switchD_00803ecb_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_00803ecb_caseD_2;
            case 3:
              goto switchD_00803ecb_caseD_3;
            }
            goto switchD_00803ecb_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_00803ecb_caseD_2;
            case 3:
              goto switchD_00803ecb_caseD_3;
            }
            goto switchD_00803ecb_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_00803ecb_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return _Dst;
    case 2:
switchD_00803ecb_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return _Dst;
    case 3:
switchD_00803ecb_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return _Dst;
    }
switchD_00803ecb_caseD_0:
    return _Dst;
  }
  puVar3 = _Dst;
  if (((uint)_Dst & 3) == 0) {
    uVar1 = _Size >> 2;
    uVar2 = _Size & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *(undefined4 *)_Src;
        _Src = (undefined4 *)((int)_Src + 4);
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return _Dst;
      case 2:
        goto switchD_00803d45_caseD_2;
      case 3:
        goto switchD_00803d45_caseD_3;
      }
      goto switchD_00803d45_caseD_1;
    }
  }
  else {
    switch(_Size) {
    case 0:
      goto switchD_00803d45_caseD_0;
    case 1:
      goto switchD_00803d45_caseD_1;
    case 2:
      goto switchD_00803d45_caseD_2;
    case 3:
      goto switchD_00803d45_caseD_3;
    default:
      uVar1 = (_Size - 4) + ((uint)_Dst & 3);
      switch((uint)_Dst & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        *(undefined1 *)((int)_Dst + 1) = *(undefined1 *)((int)_Src + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)_Dst + 2) = *(undefined1 *)((int)_Src + 2);
        _Src = (void *)((int)_Src + 3);
        puVar3 = (undefined4 *)((int)_Dst + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_00803d45_caseD_2;
          case 3:
            goto switchD_00803d45_caseD_3;
          }
          goto switchD_00803d45_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)_Dst + 1) = *(undefined1 *)((int)_Src + 1);
        _Src = (void *)((int)_Src + 2);
        puVar3 = (undefined4 *)((int)_Dst + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_00803d45_caseD_2;
          case 3:
            goto switchD_00803d45_caseD_3;
          }
          goto switchD_00803d45_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        _Src = (void *)((int)_Src + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)_Dst + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_00803d45_caseD_2;
          case 3:
            goto switchD_00803d45_caseD_3;
          }
          goto switchD_00803d45_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = *(undefined4 *)((int)_Src + (uVar1 - 7) * 4);
  case 6:
    puVar3[uVar1 - 6] = *(undefined4 *)((int)_Src + (uVar1 - 6) * 4);
  case 5:
    puVar3[uVar1 - 5] = *(undefined4 *)((int)_Src + (uVar1 - 5) * 4);
  case 4:
    puVar3[uVar1 - 4] = *(undefined4 *)((int)_Src + (uVar1 - 4) * 4);
  case 3:
    puVar3[uVar1 - 3] = *(undefined4 *)((int)_Src + (uVar1 - 3) * 4);
  case 2:
    puVar3[uVar1 - 2] = *(undefined4 *)((int)_Src + (uVar1 - 2) * 4);
  case 1:
    puVar3[uVar1 - 1] = *(undefined4 *)((int)_Src + (uVar1 - 1) * 4);
    _Src = (void *)((int)_Src + uVar1 * 4);
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_00803d45_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    return _Dst;
  case 2:
switchD_00803d45_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)_Src + 1);
    return _Dst;
  case 3:
switchD_00803d45_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)_Src;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)_Src + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)_Src + 2);
    return _Dst;
  }
switchD_00803d45_caseD_0:
  return _Dst;
}


// ==== FUN_00804050 @ 0x00804050 ====

void FUN_00804050(void)

{
  undefined1 auStack_c [12];
  
  ExceptionList = auStack_c;
  return;
}


// ==== __ftol @ 0x00804070 ====

/* Library Function - Single Match
    __ftol
   
   Library: Visual Studio */

longlong __ftol(void)

{
  float10 in_ST0;
  
  return (longlong)ROUND(in_ST0);
}


// ==== _strchr @ 0x008040b0 ====

/* Library Function - Single Match
    _strchr
   
   Library: Visual Studio 2003 Release */

char * __cdecl _strchr(char *_Str,int _Val)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  while (((uint)_Str & 3) != 0) {
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    _Str = (char *)((int)_Str + 1);
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *(uint *)_Str;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = (uint *)((int)_Str + 4);
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      _Str = (char *)puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 3);
    }
    _Str = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}


// ==== _fgets @ 0x0080416e ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fgets
   
   Library: Visual Studio 2003 Release */

char * __cdecl _fgets(char *_Buf,int _MaxCount,FILE *_File)

{
  int *piVar1;
  uint uVar2;
  char *pcVar3;
  char *local_20;
  
  local_20 = _Buf;
  if (_MaxCount < 1) {
    local_20 = (char *)0x0;
  }
  else {
    __lock_file(_File);
    pcVar3 = _Buf;
    do {
      _MaxCount = _MaxCount + -1;
      if (_MaxCount == 0) break;
      piVar1 = &_File->_cnt;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 < 0) {
        uVar2 = __filbuf(_File);
      }
      else {
        uVar2 = (uint)(byte)*_File->_ptr;
        _File->_ptr = _File->_ptr + 1;
      }
      if (uVar2 == 0xffffffff) {
        if (pcVar3 == _Buf) {
          local_20 = (char *)0x0;
          goto LAB_008041d7;
        }
        break;
      }
      *pcVar3 = (char)uVar2;
      pcVar3 = pcVar3 + 1;
    } while ((char)uVar2 != '\n');
    *pcVar3 = '\0';
LAB_008041d7:
    FUN_008041ec();
  }
  return local_20;
}


// ==== FUN_008041e9 @ 0x008041e9 ====

void FUN_008041e9(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + -0x20));
  return;
}


// ==== FUN_008041ec @ 0x008041ec ====

void FUN_008041ec(void)

{
  FILE *unaff_ESI;
  
  __unlock_file(unaff_ESI);
  return;
}


// ==== _fputs @ 0x008041f4 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fputs
   
   Library: Visual Studio 2003 Release */

int __cdecl _fputs(char *_Str,FILE *_File)

{
  size_t sVar1;
  int _Flag;
  size_t sVar2;
  
  sVar1 = _strlen(_Str);
  __lock_file(_File);
  _Flag = __stbuf(_File);
  sVar2 = __fwrite_lk(_Str,1,sVar1,_File);
  __ftbuf(_Flag,_File);
  FUN_0080425b();
  return (sVar2 == sVar1) - 1;
}


// ==== FUN_0080425b @ 0x0080425b ====

void FUN_0080425b(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 0xc));
  return;
}


// ==== FUN_00804265 @ 0x00804265 ====

undefined4 FUN_00804265(void)

{
  int iVar1;
  undefined **ppuVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  iVar1 = 0x14;
  if (DAT_00b620c0 == 0) {
    iVar1 = 0x200;
  }
  else if (0x13 < DAT_00b620c0) goto LAB_00804284;
  DAT_00b620c0 = iVar1;
LAB_00804284:
  DAT_00b610b0 = FUN_0080faf9(DAT_00b620c0,4);
  if (DAT_00b610b0 == 0) {
    DAT_00b620c0 = 0x14;
    DAT_00b610b0 = FUN_0080faf9(0x14,4);
    if (DAT_00b610b0 == 0) {
      return 0x1a;
    }
  }
  iVar1 = 0;
  ppuVar2 = &PTR_DAT_00b49680;
  do {
    *(undefined ***)(iVar1 + DAT_00b610b0) = ppuVar2;
    ppuVar2 = ppuVar2 + 8;
    iVar1 = iVar1 + 4;
  } while ((int)ppuVar2 < 0xb49900);
  uVar3 = 0;
  puVar4 = &DAT_00b49690;
  do {
    iVar1 = *(int *)((&DAT_00b60fa0)[(int)uVar3 >> 5] + (uVar3 & 0x1f) * 0x24);
    if ((iVar1 == -1) || (iVar1 == 0)) {
      *puVar4 = 0xffffffff;
    }
    puVar4 = puVar4 + 8;
    uVar3 = uVar3 + 1;
  } while ((int)puVar4 < 0xb496f0);
  return 0;
}


// ==== FUN_0080430e @ 0x0080430e ====

void FUN_0080430e(void)

{
  FUN_008056f1();
  if (DAT_00b5c758 == '\0') {
    return;
  }
  FUN_0080fbd0();
  return;
}


// ==== __lock_file @ 0x00804322 ====

/* Library Function - Single Match
    __lock_file
   
   Library: Visual Studio 2003 Release */

void __cdecl __lock_file(FILE *_File)

{
  if ((_File < (FILE *)0xb49680) || ((FILE *)0xb498e0 < _File)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(_File + 1));
    return;
  }
  __lock(((int)(_File + -0x5a4b4) >> 5) + 0x10);
  return;
}


// ==== __lock_file2 @ 0x00804351 ====

/* Library Function - Single Match
    __lock_file2
   
   Library: Visual Studio 2003 Release */

void __cdecl __lock_file2(int _Index,void *_File)

{
  if (_Index < 0x14) {
    __lock(_Index + 0x10);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((int)_File + 0x20));
  return;
}


// ==== __unlock_file @ 0x00804374 ====

/* Library Function - Single Match
    __unlock_file
   
   Library: Visual Studio 2003 Release */

void __cdecl __unlock_file(FILE *_File)

{
  if ((_File < (FILE *)0xb49680) || ((FILE *)0xb498e0 < _File)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
    return;
  }
  FUN_00806c2f(((int)(_File + -0x5a4b4) >> 5) + 0x10);
  return;
}


// ==== __unlock_file2 @ 0x008043a3 ====

/* Library Function - Single Match
    __unlock_file2
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void __cdecl __unlock_file2(int _Index,void *_File)

{
  if (_Index < 0x14) {
    FUN_00806c2f(_Index + 0x10);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)_File + 0x20));
  return;
}


// ==== FUN_008043d0 @ 0x008043d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_008043d0(double param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort in_FPUControlWord;
  float10 fVar4;
  double dVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  
  if ((DAT_00b60f5c != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    uVar2 = (uint)((ulonglong)param_1 >> 0x20);
    uVar1 = uVar2 >> 0x14;
    lVar6 = CONCAT44(uRam00a05f84,_DAT_00a05f80 - (uVar2 >> 0x14 & _DAT_00a05fa0));
    if ((uVar1 & 0x800) == 0) {
      dVar5 = (double)(((ulonglong)param_1 >> lVar6) << lVar6);
      if (uVar1 < 0x3ff) {
        return (float10)(double)(-(ulonglong)(_DAT_00a05f90 < param_1) & _DAT_00a05f70);
      }
      if (uVar1 < 0x433) {
        return (float10)(dVar5 + (double)(-(ulonglong)(dVar5 < param_1) & _DAT_00a05f70));
      }
    }
    else {
      if (uVar1 < 0xbff) {
        return (float10)_DAT_00a05fb0;
      }
      if (uVar1 < 0xc33) {
        return (float10)(double)(((ulonglong)param_1 >> lVar6) << lVar6);
      }
    }
    if (NAN(param_1)) {
      FUN_0080fc6b(&param_1,&param_1,&param_1,0x3ec);
    }
    return (float10)(double)CONCAT26(param_1._6_2_,param_1._0_6_);
  }
  uVar2 = __ctrlfp(DAT_00b4a03c,0xffff);
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = __sptype();
    if (0 < iVar3) {
      if (iVar3 < 3) {
        __ctrlfp(uVar2,0xffff);
        return (float10)(double)CONCAT26(param_1._6_2_,param_1._0_6_);
      }
      if (iVar3 == 3) {
        fVar4 = (float10)__handle_qnan1();
        return fVar4;
      }
    }
    dVar5 = (double)CONCAT26(param_1._6_2_,param_1._0_6_) + _DAT_0099d0a0;
    uVar8 = CONCAT26(param_1._6_2_,param_1._0_6_);
    uVar7 = 8;
  }
  else {
    fVar4 = (float10)__frnd((int)param_1._0_6_,(int)(CONCAT26(param_1._6_2_,param_1._0_6_) >> 0x20))
    ;
    dVar5 = (double)fVar4;
    if ((dVar5 == (double)CONCAT26(param_1._6_2_,param_1._0_6_)) || ((uVar2 & 0x20) != 0)) {
      __ctrlfp(uVar2,0xffff);
      return (float10)dVar5;
    }
    uVar8 = CONCAT26(param_1._6_2_,param_1._0_6_);
    uVar7 = 0x10;
  }
  fVar4 = (float10)FUN_0080d7c3(uVar7,0xc,uVar8,dVar5,uVar2);
  return fVar4;
}


// ==== FUN_008044f0 @ 0x008044f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_008044f0(double param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort in_FPUControlWord;
  float10 fVar4;
  double dVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  
  if ((DAT_00b60f5c != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    uVar2 = (uint)((ulonglong)param_1 >> 0x20);
    uVar1 = uVar2 >> 0x14;
    lVar6 = CONCAT44(uRam00a05fd4,_DAT_00a05fd0 - (uVar2 >> 0x14 & _DAT_00a06000));
    if ((uVar1 & 0x800) == 0) {
      if (uVar1 < 0x3ff) {
        return (float10)0;
      }
      if (uVar1 < 0x433) {
        return (float10)(double)(((ulonglong)param_1 >> lVar6) << lVar6);
      }
    }
    else {
      dVar5 = (double)(((ulonglong)param_1 >> lVar6) << lVar6);
      if (uVar1 < 0xbff) {
        return (float10)(double)((-(ulonglong)(param_1 < _DAT_00a05ff0) | (ulonglong)_DAT_00a05ff0)
                                & _DAT_00a05fe0);
      }
      if (uVar1 < 0xc33) {
        return (float10)(dVar5 - (double)(-(ulonglong)(param_1 < dVar5) & _DAT_00a05fc0));
      }
    }
    if (NAN(param_1)) {
      FUN_0080fc6b(&param_1,&param_1,&param_1,0x3ed);
    }
    return (float10)(double)CONCAT26(param_1._6_2_,param_1._0_6_);
  }
  uVar2 = __ctrlfp(DAT_00b4a040,0xffff);
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = __sptype();
    if (0 < iVar3) {
      if (iVar3 < 3) {
        __ctrlfp(uVar2,0xffff);
        return (float10)(double)CONCAT26(param_1._6_2_,param_1._0_6_);
      }
      if (iVar3 == 3) {
        fVar4 = (float10)__handle_qnan1();
        return fVar4;
      }
    }
    dVar5 = (double)CONCAT26(param_1._6_2_,param_1._0_6_) + _DAT_0099d0a0;
    uVar8 = CONCAT26(param_1._6_2_,param_1._0_6_);
    uVar7 = 8;
  }
  else {
    fVar4 = (float10)__frnd((int)param_1._0_6_,(int)(CONCAT26(param_1._6_2_,param_1._0_6_) >> 0x20))
    ;
    dVar5 = (double)fVar4;
    if ((dVar5 == (double)CONCAT26(param_1._6_2_,param_1._0_6_)) || ((uVar2 & 0x20) != 0)) {
      __ctrlfp(uVar2,0xffff);
      return (float10)dVar5;
    }
    uVar8 = CONCAT26(param_1._6_2_,param_1._0_6_);
    uVar7 = 0x10;
  }
  fVar4 = (float10)FUN_0080d7c3(uVar7,0xb,uVar8,dVar5,uVar2);
  return fVar4;
}


// ==== FUN_0080462a @ 0x0080462a ====

void FUN_0080462a(void)

{
  __cintrindisp2();
  return;
}


// ==== _frexp @ 0x00804652 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _frexp
   
   Library: Visual Studio 2003 Release */

double __cdecl _frexp(double _X,int *_Y)

{
  double dVar1;
  undefined4 uVar2;
  int iVar3;
  float10 fVar4;
  
  uVar2 = __ctrlfp(0x133f,0xffff);
  if ((_X._6_2_ & 0x7ff0) != 0x7ff0) {
    fVar4 = (float10)__decomp(_X,_Y);
    __ctrlfp(uVar2,0xffff);
    fVar4 = (float10)(double)fVar4;
    goto LAB_008046fa;
  }
  *_Y = -1;
  iVar3 = __sptype(_X);
  if (iVar3 < 1) {
LAB_008046b8:
    dVar1 = _X + _DAT_0099d0a0;
  }
  else {
    if (2 < iVar3) {
      if (iVar3 == 3) {
        fVar4 = (float10)__handle_qnan1();
        goto LAB_008046fa;
      }
      goto LAB_008046b8;
    }
    dVar1 = _DAT_00b49f18;
  }
  fVar4 = (float10)FUN_0080d7c3(8,0x17,_X,SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20),uVar2);
LAB_008046fa:
  return (double)fVar4;
}


// ==== _ldexp @ 0x008046fe ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _ldexp
   
   Library: Visual Studio 2003 Release */

double __cdecl _ldexp(double _X,int _Y)

{
  undefined4 uVar1;
  int iVar2;
  float10 fVar3;
  double dVar4;
  undefined4 uVar5;
  int local_8;
  
  uVar1 = __ctrlfp(0x133f,0xffff);
  if ((_X._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar2 = __sptype(_X);
    if (0 < iVar2) {
      if (iVar2 < 3) goto LAB_008047a9;
      if (iVar2 == 3) {
        fVar3 = (float10)__handle_qnan2();
        goto LAB_008048e5;
      }
    }
    dVar4 = _X + _DAT_0099d0a0;
    uVar5 = 8;
  }
  else {
    if (_X == _DAT_0099d098) {
LAB_008047a9:
      __ctrlfp(uVar1,0xffff);
      fVar3 = (float10)_X;
      goto LAB_008048e5;
    }
    fVar3 = (float10)__decomp(_X,&local_8);
    dVar4 = (double)fVar3;
    local_8 = _Y + local_8;
    if (local_8 < 0xa01) {
      if (local_8 < 0x401) {
        if (local_8 < -0x9fd) {
          dVar4 = dVar4 * _DAT_0099d098;
        }
        else {
          if (-0x3fe < local_8) {
            fVar3 = (float10)__set_exp(dVar4,local_8);
            __ctrlfp(uVar1,0xffff);
            fVar3 = (float10)(double)fVar3;
            goto LAB_008048e5;
          }
          fVar3 = (float10)__set_exp(dVar4,local_8 + 0x600);
          dVar4 = (double)fVar3;
        }
        uVar5 = 0x12;
        goto LAB_008048c0;
      }
      fVar3 = (float10)__set_exp(dVar4,local_8 + -0x600);
      dVar4 = (double)fVar3;
    }
    else {
      dVar4 = __copysign(_DAT_00b49f10,dVar4);
    }
    uVar5 = 0x11;
  }
LAB_008048c0:
  fVar3 = (float10)FUN_0080d87f(uVar5,0x19,_X,(double)_Y,dVar4,uVar1);
LAB_008048e5:
  return (double)fVar3;
}


// ==== ___toupper_mt @ 0x008048e9 ====

/* Library Function - Single Match
    ___toupper_mt
   
   Library: Visual Studio 2003 Release */

uint ___toupper_mt(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_8;
  
  uVar2 = param_2;
  iVar5 = param_1;
  if ((*(int *)(param_1 + 0x14) == 0) || ((*(int *)(param_1 + 0x24) != 0 && (param_2 < 0x80)))) {
    if ((0x60 < (int)param_2) && ((int)param_2 < 0x7b)) {
      return param_2 - 0x20;
    }
  }
  else {
    if (param_2 < 0x100) {
      if (*(int *)(param_1 + 0x28) < 2) {
        uVar3 = *(byte *)(*(int *)(param_1 + 0x48) + param_2 * 2) & 2;
      }
      else {
        uVar3 = ___isctype_mt(param_1,param_2,2);
      }
      if (uVar3 == 0) {
        return uVar2;
      }
    }
    iVar1 = param_1;
    if ((*(byte *)(*(int *)(iVar5 + 0x48) + 1 + ((int)uVar2 >> 8 & 0xffU) * 2) & 0x80) == 0) {
      param_1._0_2_ = (ushort)(byte)uVar2;
      uVar4 = 1;
    }
    else {
      param_1._0_2_ = CONCAT11((byte)uVar2,(char)(uVar2 >> 8));
      param_1._3_1_ = SUB41(iVar1,3);
      param_1._0_3_ = (uint3)(ushort)param_1;
      uVar4 = 2;
    }
    iVar5 = FUN_0080cc3e(*(undefined4 *)(iVar5 + 0x14),0x200,&param_1,uVar4,&local_8,3,
                         *(undefined4 *)(iVar5 + 4),1);
    if (iVar5 != 0) {
      if (iVar5 == 1) {
        return local_8 & 0xff;
      }
      return (uint)CONCAT11((undefined1)local_8,local_8._1_1_);
    }
  }
  return uVar2;
}


// ==== _toupper @ 0x008049b2 ====

/* Library Function - Single Match
    _toupper
   
   Library: Visual Studio 2003 Release */

int __cdecl _toupper(int _C)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  iVar3 = ___toupper_mt(ptVar2,_C);
  return iVar3;
}


// ==== _strpbrk @ 0x008049e0 ====

/* Library Function - Single Match
    _strpbrk
   
   Library: Visual Studio */

char * __cdecl _strpbrk(char *_Str,char *_Control)

{
  byte bVar1;
  byte *pbVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = _Control + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = (byte *)_Str;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (char *)0x0;
    }
    _Str = (char *)(pbVar2 + 1);
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return (char *)pbVar2;
}


// ==== _strncpy @ 0x00804a20 ====

/* Library Function - Single Match
    _strncpy
   
   Library: Visual Studio 2003 Release */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x00804a6c;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_00804ab3;
        goto LAB_00804b29;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x00804b25:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00804b29:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_00804ab3;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00804b25;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00804b25;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00804b25;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x00804a6c:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_00804ab3:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}


// ==== _strerror @ 0x00804b44 ====

/* Library Function - Single Match
    _strerror
   
   Library: Visual Studio 2003 Release */

char * __cdecl _strerror(char *_ErrMsg)

{
  _ptiddata p_Var1;
  char *pcVar2;
  char *pcVar3;
  
  p_Var1 = __getptd();
  if (p_Var1->_errmsg == (char *)0x0) {
    pcVar2 = _malloc(0x86);
    p_Var1->_errmsg = pcVar2;
    if (pcVar2 == (char *)0x0) {
      pcVar2 = &DAT_00b5c648;
      goto LAB_00804b6e;
    }
  }
  pcVar2 = p_Var1->_errmsg;
LAB_00804b6e:
  pcVar3 = DAT_00b4a260;
  if ((-1 < (int)_ErrMsg) && ((int)_ErrMsg < (int)DAT_00b4a260)) {
    pcVar3 = _ErrMsg;
  }
  FUN_00809180(pcVar2,(&PTR_s_No_error_00b4a1b0)[(int)pcVar3]);
  return pcVar2;
}


// ==== FUN_00804b94 @ 0x00804b94 ====

int * FUN_00804b94(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_terrno;
}


// ==== FUN_00804b9d @ 0x00804b9d ====

ulong * FUN_00804b9d(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return &p_Var1->_tdoserrno;
}


// ==== __dosmaperr @ 0x00804ba6 ====

/* Library Function - Single Match
    __dosmaperr
   
   Library: Visual Studio 2003 Release */

void __cdecl __dosmaperr(ulong param_1)

{
  _ptiddata p_Var1;
  uint uVar2;
  
  p_Var1 = __getptd();
  p_Var1->_tdoserrno = param_1;
  uVar2 = 0;
  do {
    if (param_1 == (&DAT_00b49950)[uVar2 * 2]) {
      p_Var1 = __getptd();
      p_Var1->_terrno = *(int *)(uVar2 * 8 + 0xb49954);
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x2d);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    p_Var1 = __getptd();
    p_Var1->_terrno = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (0xca < param_1)) {
    p_Var1 = __getptd();
    p_Var1->_terrno = 0x16;
    return;
  }
  p_Var1 = __getptd();
  p_Var1->_terrno = 8;
  return;
}


// ==== init_namebuf @ 0x00804c19 ====

/* Library Function - Single Match
    _init_namebuf
   
   Library: Visual Studio 2003 Release */

void __cdecl init_namebuf(int param_1)

{
  char *pcVar1;
  DWORD _Value;
  char *pcVar2;
  int _Radix;
  
  pcVar2 = &DAT_00b5c6d0;
  if (param_1 != 0) {
    pcVar2 = &DAT_00b5c6e0;
  }
  FUN_00809180(pcVar2,&DAT_009ff4a8);
  pcVar1 = pcVar2 + 1;
  if ((*pcVar2 != '\\') && (*pcVar2 != '/')) {
    *pcVar1 = '\\';
    pcVar1 = pcVar2 + 2;
  }
  if (param_1 == 0) {
    *pcVar1 = 's';
  }
  else {
    *pcVar1 = 't';
  }
  pcVar1 = pcVar1 + 1;
  _Radix = 0x20;
  _Value = GetCurrentProcessId();
  __ultoa(_Value,pcVar1,_Radix);
  FUN_00809190(pcVar2,&DAT_00a0119c);
  return;
}


// ==== genfname @ 0x00804c7a ====

/* Library Function - Single Match
    _genfname
   
   Library: Visual Studio 2003 Release */

undefined4 __cdecl genfname(uchar *param_1)

{
  uchar *puVar1;
  ulong uVar2;
  undefined4 uVar3;
  char *pcVar4;
  char local_8 [4];
  
  puVar1 = __mbsrchr(param_1,0x2e);
  uVar2 = _strtoul((char *)(puVar1 + 1),(char **)0x0,0x20);
  if (uVar2 + 1 < 0x7fff) {
    pcVar4 = __ultoa(uVar2 + 1,local_8,0x20);
    FUN_00809180(puVar1 + 1,pcVar4);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ==== _tmpnam @ 0x00804cc1 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _tmpnam
   
   Library: Visual Studio 2003 Release */

char * __cdecl _tmpnam(char *_Buffer)

{
  int iVar1;
  _ptiddata p_Var2;
  char *pcVar3;
  char *local_20;
  
  local_20 = (char *)0x0;
  iVar1 = FUN_00806c44(2);
  pcVar3 = (char *)0x0;
  if (iVar1 != 0) {
    __lock(2);
    if (DAT_00b5c6d0 != '\0') goto LAB_00804d0e;
    init_namebuf(0);
    do {
      iVar1 = __access(&DAT_00b5c6d0,0);
      if (iVar1 != 0) {
        if (_Buffer == (char *)0x0) {
          p_Var2 = __getptd();
          if (p_Var2->_namebuf0 != (char *)0x0) {
LAB_00804d4e:
            _Buffer = p_Var2->_namebuf0;
            goto LAB_00804d54;
          }
          pcVar3 = _malloc(0xe);
          p_Var2->_namebuf0 = pcVar3;
          if (pcVar3 != (char *)0x0) goto LAB_00804d4e;
          _Buffer = &DAT_00b5c6d0;
        }
        else {
LAB_00804d54:
          FUN_00809180(_Buffer,&DAT_00b5c6d0);
        }
        local_20 = _Buffer;
        break;
      }
LAB_00804d0e:
      iVar1 = genfname(&DAT_00b5c6d0);
    } while (iVar1 == 0);
    FUN_00804d72();
    pcVar3 = local_20;
  }
  return pcVar3;
}


// ==== FUN_00804d72 @ 0x00804d72 ====

void FUN_00804d72(void)

{
  FUN_00806c2f(2);
  return;
}


// ==== _tmpfile @ 0x00804d7b ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _tmpfile
   
   Library: Visual Studio 2003 Release */

FILE * __cdecl _tmpfile(void)

{
  int iVar1;
  FILE *pFVar2;
  undefined4 *puVar3;
  int *piVar4;
  char *pcVar5;
  FILE *local_28;
  
  local_28 = (FILE *)0x0;
  iVar1 = FUN_00806c44(2);
  if (iVar1 == 0) {
    return (FILE *)0x0;
  }
  __lock(2);
  if (DAT_00b5c6e0 == '\0') {
    init_namebuf(1);
  }
  else {
    iVar1 = genfname(&DAT_00b5c6e0);
    if (iVar1 != 0) goto LAB_00804e6a;
  }
  pFVar2 = (FILE *)FUN_0080de3f();
  if (pFVar2 == (FILE *)0x0) {
    puVar3 = (undefined4 *)FUN_00804b94();
    *puVar3 = 0x18;
  }
  else {
    do {
      iVar1 = __sopen(&DAT_00b5c6e0,0x8542,0x40,0x180);
      if (iVar1 != -1) {
        pcVar5 = __strdup(&DAT_00b5c6e0);
        pFVar2->_tmpfname = pcVar5;
        if (pcVar5 == (char *)0x0) {
          __close(iVar1);
        }
        else {
          pFVar2->_cnt = 0;
          pFVar2->_ptr = (char *)0x0;
          pFVar2->_base = (char *)0x0;
          pFVar2->_flag = DAT_00b5cb88 | 0x80;
          pFVar2->_file = iVar1;
          local_28 = pFVar2;
        }
        goto LAB_00804e6a;
      }
      piVar4 = (int *)FUN_00804b94();
    } while ((*piVar4 == 0x11) && (iVar1 = genfname(&DAT_00b5c6e0), iVar1 == 0));
  }
LAB_00804e6a:
  FUN_00804e7f();
  return local_28;
}


// ==== FUN_00804e7c @ 0x00804e7c ====

void FUN_00804e7c(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    __unlock_file(*(FILE **)(unaff_EBP + -0x1c));
  }
  FUN_00806c2f(2);
  return;
}


// ==== FUN_00804e7f @ 0x00804e7f ====

void FUN_00804e7f(void)

{
  int unaff_EBP;
  FILE *unaff_ESI;
  
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    __unlock_file(unaff_ESI);
  }
  FUN_00806c2f(2);
  return;
}


// ==== FID_conflict:_fscanf @ 0x00804e95 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Different Base Names
    _fscanf
    _fwscanf
   
   Library: Visual Studio 2003 Release */

int __cdecl FID_conflict__fscanf(FILE *_File,wchar_t *_Format,...)

{
  int iVar1;
  undefined1 uStack0000000c;
  
  __lock_file(_File);
  iVar1 = FUN_0080df77(_File,_Format,&uStack0000000c);
  FUN_00804ed5();
  return iVar1;
}


// ==== FUN_00804ed5 @ 0x00804ed5 ====

void FUN_00804ed5(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}


// ==== __ungetc_lk @ 0x00804edf ====

/* Library Function - Single Match
    __ungetc_lk
   
   Library: Visual Studio 2003 Release */

uint __ungetc_lk(uint param_1,FILE *param_2)

{
  uint uVar1;
  char *pcVar2;
  
  if (param_1 != 0xffffffff) {
    uVar1 = param_2->_flag;
    if (((uVar1 & 1) != 0) || (((char)uVar1 < '\0' && ((uVar1 & 2) == 0)))) {
      if (param_2->_base == (char *)0x0) {
        __getbuf(param_2);
      }
      if (param_2->_ptr == param_2->_base) {
        if (param_2->_cnt != 0) {
          return 0xffffffff;
        }
        param_2->_ptr = param_2->_ptr + 1;
      }
      param_2->_ptr = param_2->_ptr + -1;
      pcVar2 = param_2->_ptr;
      if ((param_2->_flag & 0x40) == 0) {
        *pcVar2 = (char)param_1;
      }
      else if (*pcVar2 != (char)param_1) {
        param_2->_ptr = pcVar2 + 1;
        return 0xffffffff;
      }
      param_2->_cnt = param_2->_cnt + 1;
      param_2->_flag = param_2->_flag & 0xffffffefU | 1;
      return param_1 & 0xff;
    }
  }
  return 0xffffffff;
}


// ==== _ungetc @ 0x00804f4b ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _ungetc
   
   Library: Visual Studio 2003 Release */

int __cdecl _ungetc(int _Ch,FILE *_File)

{
  int iVar1;
  
  __lock_file(_File);
  iVar1 = __ungetc_lk(_Ch,_File);
  FUN_00804f86();
  return iVar1;
}


// ==== FUN_00804f86 @ 0x00804f86 ====

void FUN_00804f86(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 0xc));
  return;
}


// ==== FID_conflict:_getc @ 0x00804f90 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Different Base Names
    _fgetc
    _getc
   
   Library: Visual Studio 2003 Release */

int __cdecl FID_conflict__getc(FILE *_File)

{
  int *piVar1;
  uint uVar2;
  
  __lock_file(_File);
  piVar1 = &_File->_cnt;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = __filbuf(_File);
  }
  else {
    uVar2 = (uint)(byte)*_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  FUN_00804fd8();
  return uVar2;
}


// ==== FUN_00804fd5 @ 0x00804fd5 ====

void FUN_00804fd5(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}


// ==== FUN_00804fd8 @ 0x00804fd8 ====

void FUN_00804fd8(void)

{
  FILE *unaff_ESI;
  
  __unlock_file(unaff_ESI);
  return;
}


// ==== __fread_lk @ 0x00804fe0 ====

/* Library Function - Single Match
    __fread_lk
   
   Library: Visual Studio 2003 Release */

uint __fread_lk(undefined1 *param_1,uint param_2,uint param_3,FILE *param_4)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint _Size;
  uint local_8;
  
  uVar4 = param_2 * param_3;
  if (uVar4 == 0) {
    param_2 = 0;
  }
  else {
    puVar3 = param_1;
    param_1 = (undefined1 *)uVar4;
    if ((param_4->_flag & 0x10c) == 0) {
      local_8 = 0x1000;
    }
    else {
      local_8 = param_4->_bufsiz;
    }
    while (((param_4->_flag & 0x10c) != 0 && (uVar1 = param_4->_cnt, uVar1 != 0))) {
      _Size = (uint)param_1;
      if (uVar1 <= param_1) {
        _Size = uVar1;
      }
      _memcpy(puVar3,param_4->_ptr,_Size);
      param_1 = (undefined1 *)((int)param_1 - _Size);
      param_4->_cnt = param_4->_cnt - _Size;
      param_4->_ptr = param_4->_ptr + _Size;
      puVar3 = puVar3 + _Size;
LAB_008050a1:
      if (param_1 == (undefined1 *)0x0) {
        return param_3;
      }
    }
    if (param_1 < local_8) {
      iVar2 = __filbuf(param_4);
      if (iVar2 != -1) {
        *puVar3 = (char)iVar2;
        local_8 = param_4->_bufsiz;
        puVar3 = puVar3 + 1;
        param_1 = (undefined1 *)((int)param_1 - 1);
        goto LAB_008050a1;
      }
    }
    else {
      uVar1 = (uint)param_1;
      if (local_8 != 0) {
        uVar1 = (int)param_1 - (uint)param_1 % local_8;
      }
      iVar2 = __read(param_4->_file,puVar3,uVar1);
      if (iVar2 == 0) {
        param_4->_flag = param_4->_flag | 0x10;
      }
      else {
        if (iVar2 != -1) {
          param_1 = (undefined1 *)((int)param_1 - iVar2);
          puVar3 = puVar3 + iVar2;
          goto LAB_008050a1;
        }
        param_4->_flag = param_4->_flag | 0x20;
      }
    }
    param_2 = (uVar4 - (int)param_1) / param_2;
  }
  return param_2;
}


// ==== _fread @ 0x008050c9 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fread
   
   Library: Visual Studio 2003 Release */

size_t __cdecl _fread(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File)

{
  size_t sVar1;
  
  __lock_file(_File);
  sVar1 = __fread_lk(_DstBuf,_ElementSize,_Count,_File);
  FUN_0080510b();
  return sVar1;
}


// ==== FUN_0080510b @ 0x0080510b ====

void FUN_0080510b(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 0x14));
  return;
}


// ==== __fwrite_lk @ 0x00805115 ====

/* Library Function - Single Match
    __fwrite_lk
   
   Library: Visual Studio 2003 Release */

uint __fwrite_lk(char *param_1,uint param_2,uint param_3,FILE *param_4)

{
  uint uVar1;
  int iVar2;
  uint _Size;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_8;
  
  uVar5 = param_2 * param_3;
  if (uVar5 == 0) {
    param_3 = 0;
  }
  else {
    uVar4 = uVar5;
    if ((param_4->_flag & 0x10c) == 0) {
      local_8 = 0x1000;
    }
    else {
      local_8 = param_4->_bufsiz;
    }
    do {
      uVar3 = param_4->_flag & 0x108;
      if ((uVar3 == 0) || (uVar1 = param_4->_cnt, uVar1 == 0)) {
        if (local_8 <= uVar4) {
          if ((uVar3 != 0) && (iVar2 = __flush(param_4), iVar2 != 0)) {
LAB_0080520a:
            return (uVar5 - uVar4) / param_2;
          }
          uVar3 = uVar4;
          if (local_8 != 0) {
            uVar3 = uVar4 - uVar4 % local_8;
          }
          _Size = __write(param_4->_file,param_1,uVar3);
          if ((_Size == 0xffffffff) || (uVar4 = uVar4 - _Size, _Size < uVar3)) {
            param_4->_flag = param_4->_flag | 0x20;
            goto LAB_0080520a;
          }
          goto LAB_008051ca;
        }
        iVar2 = __flsbuf((int)*param_1,param_4);
        if (iVar2 == -1) goto LAB_0080520a;
        param_1 = param_1 + 1;
        local_8 = param_4->_bufsiz;
        uVar4 = uVar4 - 1;
        if ((int)local_8 < 1) {
          local_8 = 1;
        }
      }
      else {
        _Size = uVar4;
        if (uVar1 <= uVar4) {
          _Size = uVar1;
        }
        _memcpy(param_4->_ptr,param_1,_Size);
        param_4->_cnt = param_4->_cnt - _Size;
        param_4->_ptr = param_4->_ptr + _Size;
        uVar4 = uVar4 - _Size;
LAB_008051ca:
        param_1 = param_1 + _Size;
      }
    } while (uVar4 != 0);
  }
  return param_3;
}


// ==== _fwrite @ 0x0080521c ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fwrite
   
   Library: Visual Studio 2003 Release */

size_t __cdecl _fwrite(void *_Str,size_t _Size,size_t _Count,FILE *_File)

{
  size_t sVar1;
  
  __lock_file(_File);
  sVar1 = __fwrite_lk(_Str,_Size,_Count,_File);
  FUN_0080525e();
  return sVar1;
}


// ==== FUN_0080525e @ 0x0080525e ====

void FUN_0080525e(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 0x14));
  return;
}


// ==== FID_conflict:_fwprintf @ 0x00805268 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Different Base Names
    _fprintf
    _fwprintf
   
   Library: Visual Studio 2003 Release */

int __cdecl FID_conflict__fwprintf(FILE *_File,wchar_t *_Format,...)

{
  int _Flag;
  int iVar1;
  undefined1 uStack0000000c;
  
  __lock_file(_File);
  _Flag = __stbuf(_File);
  iVar1 = FUN_0080bae5(_File,_Format,&uStack0000000c);
  __ftbuf(_Flag,_File);
  FUN_008052bc();
  return iVar1;
}


// ==== FUN_008052bc @ 0x008052bc ====

void FUN_008052bc(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + -0x20));
  return;
}


// ==== __ftell_lk @ 0x008052c6 ====

/* Library Function - Single Match
    __ftell_lk
   
   Library: Visual Studio 2003 Release */

int __ftell_lk(uint *param_1)

{
  uint _FileHandle;
  uint uVar1;
  byte bVar2;
  uint *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int local_c;
  int local_8;
  
  puVar3 = param_1;
  _FileHandle = param_1[4];
  if ((int)param_1[1] < 0) {
    param_1[1] = 0;
  }
  local_8 = __lseek(_FileHandle,0,1);
  if (local_8 < 0) {
LAB_00805363:
    local_c = -1;
  }
  else {
    uVar1 = param_1[3];
    if ((uVar1 & 0x108) == 0) {
      return local_8 - param_1[1];
    }
    pcVar5 = (char *)*param_1;
    pcVar7 = (char *)param_1[2];
    local_c = (int)pcVar5 - (int)pcVar7;
    if ((uVar1 & 3) == 0) {
      if (-1 < (char)uVar1) {
        puVar4 = (undefined4 *)FUN_00804b94();
        *puVar4 = 0x16;
        goto LAB_00805363;
      }
    }
    else if (((*(byte *)((&DAT_00b60fa0)[(int)_FileHandle >> 5] + 4 + (_FileHandle & 0x1f) * 0x24) &
              0x80) != 0) && (pcVar8 = pcVar7, pcVar7 < pcVar5)) {
      do {
        if (*pcVar8 == '\n') {
          local_c = local_c + 1;
        }
        pcVar8 = pcVar8 + 1;
      } while (pcVar8 < (char *)*param_1);
    }
    if (local_8 != 0) {
      if ((param_1[3] & 1) != 0) {
        if (param_1[1] == 0) {
          local_c = 0;
        }
        else {
          pcVar5 = pcVar5 + (param_1[1] - (int)pcVar7);
          iVar9 = (_FileHandle & 0x1f) * 0x24;
          if ((*(byte *)(iVar9 + 4 + (&DAT_00b60fa0)[(int)_FileHandle >> 5]) & 0x80) != 0) {
            lVar6 = __lseek(_FileHandle,0,2);
            if (lVar6 == local_8) {
              pcVar7 = (char *)param_1[2];
              pcVar8 = pcVar7 + (int)pcVar5;
              param_1 = (uint *)pcVar5;
              for (; pcVar7 < pcVar8; pcVar7 = pcVar7 + 1) {
                if (*pcVar7 == '\n') {
                  param_1 = (uint *)((int)param_1 + 1);
                }
              }
              bVar2 = *(byte *)((int)puVar3 + 0xd) & 0x20;
            }
            else {
              __lseek(_FileHandle,local_8,0);
              pcVar7 = (char *)0x200;
              if ((((char *)0x200 < pcVar5) || ((param_1[3] & 8) == 0)) ||
                 ((param_1[3] & 0x400) != 0)) {
                pcVar7 = (char *)param_1[6];
              }
              bVar2 = *(byte *)(iVar9 + 4 + (&DAT_00b60fa0)[(int)_FileHandle >> 5]) & 4;
              param_1 = (uint *)pcVar7;
            }
            pcVar5 = (char *)param_1;
            if (bVar2 != 0) {
              pcVar5 = (char *)((int)param_1 + 1);
            }
          }
          param_1 = (uint *)pcVar5;
          local_8 = local_8 - (int)param_1;
        }
      }
      local_c = local_c + local_8;
    }
  }
  return local_c;
}


// ==== _ftell @ 0x00805428 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _ftell
   
   Library: Visual Studio 2003 Release */

long __cdecl _ftell(FILE *_File)

{
  long lVar1;
  
  __lock_file(_File);
  lVar1 = __ftell_lk(_File);
  FUN_0080545f();
  return lVar1;
}


// ==== FUN_0080545f @ 0x0080545f ====

void FUN_0080545f(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}


// ==== __fseek_lk @ 0x00805469 ====

/* Library Function - Single Match
    __fseek_lk
   
   Library: Visual Studio 2003 Release */

int __fseek_lk(FILE *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined4 *puVar4;
  
  if (((param_1->_flag & 0x83U) == 0) || (((param_3 != 0 && (param_3 != 1)) && (param_3 != 2)))) {
    puVar4 = (undefined4 *)FUN_00804b94();
    *puVar4 = 0x16;
    iVar2 = -1;
  }
  else {
    param_1->_flag = param_1->_flag & 0xffffffef;
    if (param_3 == 1) {
      iVar2 = __ftell_lk(param_1);
      param_2 = param_2 + iVar2;
      param_3 = 0;
    }
    __flush(param_1);
    uVar1 = param_1->_flag;
    if ((char)uVar1 < '\0') {
      param_1->_flag = uVar1 & 0xfffffffc;
    }
    else if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
      param_1->_bufsiz = 0x200;
    }
    lVar3 = __lseek(param_1->_file,param_2,param_3);
    iVar2 = (lVar3 != -1) - 1;
  }
  return iVar2;
}


// ==== _fseek @ 0x008054f8 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fseek
   
   Library: Visual Studio 2003 Release */

int __cdecl _fseek(FILE *_File,long _Offset,int _Origin)

{
  int iVar1;
  
  __lock_file(_File);
  iVar1 = __fseek_lk(_File,_Offset,_Origin);
  FUN_00805537();
  return iVar1;
}


// ==== FUN_00805537 @ 0x00805537 ====

void FUN_00805537(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}


// ==== __flush @ 0x00805541 ====

/* Library Function - Single Match
    __flush
   
   Library: Visual Studio 2003 Release */

int __cdecl __flush(FILE *_File)

{
  uint uVar1;
  int iVar2;
  uint _MaxCharCount;
  
  iVar2 = 0;
  if ((((byte)_File->_flag & 3) == 2) && ((_File->_flag & 0x108U) != 0)) {
    _MaxCharCount = (int)_File->_ptr - (int)_File->_base;
    if (0 < (int)_MaxCharCount) {
      uVar1 = __write(_File->_file,_File->_base,_MaxCharCount);
      if (uVar1 == _MaxCharCount) {
        if ((char)_File->_flag < '\0') {
          _File->_flag = _File->_flag & 0xfffffffd;
        }
      }
      else {
        _File->_flag = _File->_flag | 0x20;
        iVar2 = -1;
      }
    }
  }
  _File->_cnt = 0;
  _File->_ptr = _File->_base;
  return iVar2;
}


// ==== __fflush_lk @ 0x0080559e ====

/* Library Function - Single Match
    __fflush_lk
   
   Library: Visual Studio 2003 Release */

int __fflush_lk(FILE *param_1)

{
  int iVar1;
  
  iVar1 = __flush(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((param_1->_flag & 0x4000) == 0) {
    return 0;
  }
  iVar1 = __commit(param_1->_file);
  return -(uint)(iVar1 != 0);
}


// ==== flsall @ 0x008055cc ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 2003 Release */

int __cdecl flsall(int param_1)

{
  void *_File;
  int iVar1;
  int _Index;
  int local_28;
  int local_20;
  
  local_20 = 0;
  local_28 = 0;
  __lock(1);
  for (_Index = 0; _Index < DAT_00b620c0; _Index = _Index + 1) {
    _File = *(void **)(DAT_00b610b0 + _Index * 4);
    if ((_File != (void *)0x0) && ((*(byte *)((int)_File + 0xc) & 0x83) != 0)) {
      __lock_file2(_Index,_File);
      iVar1 = *(int *)(DAT_00b610b0 + _Index * 4);
      if ((*(uint *)(iVar1 + 0xc) & 0x83) != 0) {
        if (param_1 == 1) {
          iVar1 = __fflush_lk(iVar1);
          if (iVar1 != -1) {
            local_20 = local_20 + 1;
          }
        }
        else if ((param_1 == 0) && ((*(uint *)(iVar1 + 0xc) & 2) != 0)) {
          iVar1 = __fflush_lk(iVar1);
          if (iVar1 == -1) {
            local_28 = -1;
          }
        }
      }
      FUN_0080566c();
    }
  }
  FUN_00805698();
  if (param_1 != 1) {
    local_20 = local_28;
  }
  return local_20;
}


// ==== FUN_0080566c @ 0x0080566c ====

void FUN_0080566c(void)

{
  int unaff_ESI;
  
  __unlock_file2(unaff_ESI,*(void **)(DAT_00b610b0 + unaff_ESI * 4));
  return;
}


// ==== FUN_00805698 @ 0x00805698 ====

void FUN_00805698(void)

{
  FUN_00806c2f(1);
  return;
}


// ==== _fflush @ 0x008056a1 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fflush
   
   Library: Visual Studio 2003 Release */

int __cdecl _fflush(FILE *_File)

{
  int iVar1;
  
  if (_File == (FILE *)0x0) {
    iVar1 = flsall(0);
  }
  else {
    __lock_file(_File);
    iVar1 = __fflush_lk(_File);
    FUN_008056e7();
  }
  return iVar1;
}


// ==== FUN_008056e7 @ 0x008056e7 ====

void FUN_008056e7(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}


// ==== FUN_008056f1 @ 0x008056f1 ====

void FUN_008056f1(void)

{
  flsall(1);
  return;
}


// ==== FID_conflict:__wsystem @ 0x008056fa ====

/* Library Function - Multiple Matches With Different Base Names
    __wsystem
    _system
   
   Library: Visual Studio 2003 Release */

int __cdecl FID_conflict___wsystem(char *_Command)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  char *local_14;
  undefined *local_10;
  char *local_c;
  undefined4 local_8;
  
  local_14 = _getenv(s_COMSPEC_00a060ec);
  if (_Command == (char *)0x0) {
    if (local_14 == (char *)0x0) {
      uVar1 = 0;
    }
    else {
      iVar2 = __access(local_14,0);
      uVar1 = (uint)(iVar2 == 0);
    }
  }
  else {
    local_10 = &DAT_00a060e8;
    local_c = _Command;
    local_8 = 0;
    if ((local_14 == (char *)0x0) ||
       ((uVar1 = FUN_00811e7c(0,local_14,&local_14,0), uVar1 == 0xffffffff &&
        ((piVar3 = (int *)FUN_00804b94(), *piVar3 == 2 ||
         (piVar3 = (int *)FUN_00804b94(), *piVar3 == 0xd)))))) {
      local_14 = s_command_com_00a060dc;
      if ((DAT_00b5c725 & 0x80) == 0) {
        local_14 = s_cmd_exe_00a060d4;
      }
      uVar1 = FUN_00811cc0(0,local_14,&local_14,0);
    }
  }
  return uVar1;
}


// ==== FUN_0080579c @ 0x0080579c ====

undefined4 FUN_0080579c(LPCSTR param_1)

{
  BOOL BVar1;
  ulong uVar2;
  
  BVar1 = DeleteFileA(param_1);
  if (BVar1 == 0) {
    uVar2 = GetLastError();
  }
  else {
    uVar2 = 0;
  }
  if (uVar2 == 0) {
    return 0;
  }
  __dosmaperr(uVar2);
  return 0xffffffff;
}


// ==== FUN_008057c6 @ 0x008057c6 ====

undefined4 FUN_008057c6(LPCSTR param_1,LPCSTR param_2)

{
  BOOL BVar1;
  ulong uVar2;
  
  BVar1 = MoveFileA(param_1,param_2);
  if (BVar1 == 0) {
    uVar2 = GetLastError();
  }
  else {
    uVar2 = 0;
  }
  if (uVar2 == 0) {
    return 0;
  }
  __dosmaperr(uVar2);
  return 0xffffffff;
}


// ==== __getenv_lk @ 0x008057f4 ====

/* Library Function - Single Match
    __getenv_lk
   
   Library: Visual Studio 2003 Release */

int __getenv_lk(uchar *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *piVar3;
  
  if (DAT_00b610a0 == 0) {
    return 0;
  }
  if (((DAT_00b5c740 != (int *)0x0) ||
      (((DAT_00b5c748 != 0 && (iVar1 = FUN_00812013(), iVar1 == 0)) && (DAT_00b5c740 != (int *)0x0))
      )) && (piVar3 = DAT_00b5c740, param_1 != (uchar *)0x0)) {
    _MaxCount = _strlen((char *)param_1);
    for (; (char *)*piVar3 != (char *)0x0; piVar3 = piVar3 + 1) {
      sVar2 = _strlen((char *)*piVar3);
      if (((_MaxCount < sVar2) && (((uchar *)*piVar3)[_MaxCount] == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*piVar3,param_1,_MaxCount), iVar1 == 0)) {
        return *piVar3 + 1 + _MaxCount;
      }
    }
  }
  return 0;
}


// ==== _getenv @ 0x00805875 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _getenv
   
   Library: Visual Studio 2003 Release */

char * __cdecl _getenv(char *_VarName)

{
  char *pcVar1;
  
  __lock(7);
  pcVar1 = (char *)__getenv_lk(_VarName);
  FUN_008058ab();
  return pcVar1;
}


// ==== FUN_008058ab @ 0x008058ab ====

void FUN_008058ab(void)

{
  FUN_00806c2f(7);
  return;
}


// ==== _clock @ 0x008058b4 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _clock
   
   Library: Visual Studio 2003 Release */

clock_t __cdecl _clock(void)

{
  clock_t cVar1;
  longlong lVar2;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar2 = __allmul(local_c.dwHighDateTime,0,0,1);
  cVar1 = __aulldiv((lVar2 - CONCAT44(_DAT_00b5c6f4,_DAT_00b5c6f0)) +
                    (ulonglong)local_c.dwLowDateTime,10000,0);
  return cVar1;
}


// ==== ___inittime @ 0x008058f7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___inittime
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release */

undefined4 ___inittime(void)

{
  longlong lVar1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar1 = __allmul(local_c.dwHighDateTime,0,0,1);
  _DAT_00b5c6f0 = lVar1 + (ulonglong)local_c.dwLowDateTime;
  return 0;
}


// ==== _gmtime @ 0x0080592e ====

/* Library Function - Single Match
    _gmtime
   
   Library: Visual Studio 2003 Release */

tm * __cdecl _gmtime(time_t *_Time)

{
  bool bVar1;
  _ptiddata p_Var2;
  void *pvVar3;
  tm *ptVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  
  iVar8 = (int)*_Time;
  bVar1 = false;
  p_Var2 = __getptd();
  if (iVar8 < 0) {
    return (tm *)0x0;
  }
  if (p_Var2->_gmtimebuf == (void *)0x0) {
    pvVar3 = _malloc(0x24);
    p_Var2->_gmtimebuf = pvVar3;
    ptVar4 = (tm *)&DAT_00b5c6f8;
    if (pvVar3 == (void *)0x0) goto LAB_00805968;
  }
  ptVar4 = p_Var2->_gmtimebuf;
LAB_00805968:
  iVar6 = iVar8 % 0x7861f80;
  iVar8 = (iVar8 / 0x7861f80) * 4;
  iVar5 = iVar8 + 0x46;
  iVar7 = iVar6;
  if (0x1e1337f < iVar6) {
    iVar7 = iVar6 + -0x1e13380;
    iVar5 = iVar8 + 0x47;
    if (0x1e1337f < iVar7) {
      iVar7 = iVar6 + -0x3c26700;
      iVar5 = iVar8 + 0x48;
      if (iVar7 < 0x1e28500) {
        bVar1 = true;
      }
      else {
        iVar5 = iVar8 + 0x49;
        iVar7 = iVar6 + -0x5a4ec00;
      }
    }
  }
  ptVar4->tm_year = iVar5;
  puVar9 = (undefined4 *)&DAT_00b4a27c;
  ptVar4->tm_yday = iVar7 / 0x15180;
  if (!bVar1) {
    puVar9 = &DAT_00b4a2b0;
  }
  iVar5 = 1;
  iVar8 = puVar9[1];
  while (iVar8 < ptVar4->tm_yday) {
    iVar5 = iVar5 + 1;
    iVar8 = puVar9[iVar5];
  }
  ptVar4->tm_mon = iVar5 + -1;
  ptVar4->tm_mday = ptVar4->tm_yday - puVar9[iVar5 + -1];
  ptVar4->tm_wday = ((int)*_Time / 0x15180 + 4) % 7;
  ptVar4->tm_hour = (iVar7 % 0x15180) / 0xe10;
  iVar8 = (iVar7 % 0x15180) % 0xe10;
  ptVar4->tm_min = iVar8 / 0x3c;
  ptVar4->tm_isdst = 0;
  ptVar4->tm_sec = iVar8 % 0x3c;
  return ptVar4;
}


// ==== __make_time_t @ 0x00805a35 ====

/* Library Function - Single Match
    __make_time_t
   
   Library: Visual Studio 2003 Release */

int __make_time_t(int param_1)

{
  int iVar1;
  int *in_EAX;
  tm *ptVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  uVar3 = in_EAX[5];
  if ((0x44 < (int)uVar3) && ((int)uVar3 < 0x8c)) {
    iVar5 = in_EAX[4];
    if ((iVar5 < 0) || (0xb < iVar5)) {
      iVar4 = iVar5 % 0xc;
      uVar3 = uVar3 + iVar5 / 0xc;
      in_EAX[4] = iVar4;
      if (iVar4 < 0) {
        in_EAX[4] = iVar4 + 0xc;
        uVar3 = uVar3 - 1;
      }
      if ((int)uVar3 < 0x45) {
        return -1;
      }
      if (0x8b < (int)uVar3) {
        return -1;
      }
    }
    iVar5 = (&DAT_00b4a2b0)[in_EAX[4]];
    if (((uVar3 & 3) == 0) && (1 < in_EAX[4])) {
      iVar5 = iVar5 + 1;
    }
    iVar4 = uVar3 * 0x16d + -0x63df + ((int)(uVar3 - 1) >> 2) + iVar5;
    iVar1 = in_EAX[3];
    iVar5 = iVar4 + iVar1;
    if (iVar4 < 0) {
      if ((iVar1 < 0) && (-1 < iVar5)) {
        return -1;
      }
    }
    else if ((-1 < iVar1) && (iVar5 < 0)) {
      return -1;
    }
    iVar4 = iVar5 * 0x18;
    if (iVar5 != 0 && iVar4 / iVar5 != 0x18) {
      return -1;
    }
    iVar1 = in_EAX[2];
    iVar5 = iVar1 + iVar4;
    if (iVar4 < 0) {
      if ((iVar1 < 0) && (-1 < iVar5)) {
        return -1;
      }
    }
    else if ((-1 < iVar1) && (iVar5 < 0)) {
      return -1;
    }
    iVar4 = iVar5 * 0x3c;
    if (iVar5 != 0 && iVar4 / iVar5 != 0x3c) {
      return -1;
    }
    iVar1 = in_EAX[1];
    iVar5 = iVar1 + iVar4;
    if (iVar4 < 0) {
      if ((iVar1 < 0) && (-1 < iVar5)) {
        return -1;
      }
    }
    else if ((-1 < iVar1) && (iVar5 < 0)) {
      return -1;
    }
    iVar4 = iVar5 * 0x3c;
    if (iVar5 != 0 && iVar4 / iVar5 != 0x3c) {
      return -1;
    }
    iVar5 = *in_EAX;
    local_8 = iVar5 + iVar4;
    if (iVar4 < 0) {
      if ((iVar5 < 0) && (-1 < local_8)) {
        return -1;
      }
    }
    else if ((-1 < iVar5) && (local_8 < 0)) {
      return -1;
    }
    if (param_1 == 0) {
      ptVar2 = _gmtime((time_t *)&local_8);
    }
    else {
      ___tzset();
      local_8 = local_8 + DAT_00b49e60;
      ptVar2 = _localtime((time_t *)&local_8);
      if (ptVar2 == (tm *)0x0) {
        return -1;
      }
      if ((in_EAX[8] < 1) && ((-1 < in_EAX[8] || (ptVar2->tm_isdst < 1)))) goto LAB_00805be6;
      local_8 = local_8 + DAT_00b49e68;
      ptVar2 = _localtime((time_t *)&local_8);
    }
    if (ptVar2 != (tm *)0x0) {
LAB_00805be6:
      for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
        *in_EAX = ptVar2->tm_sec;
        ptVar2 = (tm *)&ptVar2->tm_min;
        in_EAX = in_EAX + 1;
      }
      return local_8;
    }
  }
  return -1;
}


// ==== _mktime @ 0x00805bf5 ====

/* Library Function - Single Match
    _mktime
   
   Library: Visual Studio 2003 Release */

time_t __cdecl _mktime(tm *_Tm)

{
  time_t tVar1;
  
  tVar1 = __make_time_t(1);
  return tVar1;
}


// ==== FUN_00805c02 @ 0x00805c02 ====

float10 FUN_00805c02(int param_1,int param_2)

{
  return (float10)(param_1 - param_2);
}


// ==== ___crtExitProcess @ 0x00805c13 ====

/* Library Function - Single Match
    ___crtExitProcess
   
   Library: Visual Studio 2003 Release */

void __cdecl ___crtExitProcess(int param_1)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA(s_mscoree_dll_00a06114);
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,s_CorExitProcess_00a06104);
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(param_1);
    }
  }
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}


// ==== FUN_00805c43 @ 0x00805c43 ====

void FUN_00805c43(void)

{
  __lock(8);
  return;
}


// ==== FUN_00805c4c @ 0x00805c4c ====

void FUN_00805c4c(void)

{
  FUN_00806c2f(8);
  return;
}


// ==== __initterm @ 0x00805c55 ====

/* Library Function - Single Match
    __initterm
   
   Library: Visual Studio 2003 Release */

void __initterm(undefined4 *param_1)

{
  undefined4 *in_EAX;
  
  for (; in_EAX < param_1; in_EAX = in_EAX + 1) {
    if ((code *)*in_EAX != (code *)0x0) {
      (*(code *)*in_EAX)();
    }
  }
  return;
}


// ==== __cinit @ 0x00805c6d ====

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 2003 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (PTR___fpmath_00b49574 != (undefined *)0x0) {
    (*(code *)PTR___fpmath_00b49574)(param_1);
  }
  iVar1 = 0;
  puVar2 = &DAT_00adab80;
  do {
    if (iVar1 != 0) {
      return iVar1;
    }
    if ((code *)*puVar2 != (code *)0x0) {
      iVar1 = (*(code *)*puVar2)();
    }
    puVar2 = puVar2 + 1;
  } while (puVar2 < &DAT_00adab9c);
  if (iVar1 == 0) {
    _atexit((_func_4879 *)&LAB_00808445);
    puVar2 = &DAT_00ad9000;
    do {
      if ((code *)*puVar2 != (code *)0x0) {
        (*(code *)*puVar2)();
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 < &DAT_00adab7c);
    iVar1 = 0;
  }
  return iVar1;
}


// ==== doexit @ 0x00805cd7 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x00805d8b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 2003 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  UINT uExitCode;
  
  __lock(8);
  if (DAT_00b5c760 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00b5c75c = 1;
  DAT_00b5c758 = (undefined1)param_3;
  if (param_2 == 0) {
    if (DAT_00b610a8 != (undefined4 *)0x0) {
      while (DAT_00b610a4 = DAT_00b610a4 + -1, DAT_00b610a8 <= DAT_00b610a4) {
        if ((code *)*DAT_00b610a4 != (code *)0x0) {
          (*(code *)*DAT_00b610a4)();
        }
      }
    }
    __initterm(&DAT_00adabac);
  }
  __initterm(&DAT_00adabb8);
  FUN_00805d86();
  if (param_3 == 0) {
    DAT_00b5c760 = 1;
    ___crtExitProcess(param_1);
    return;
  }
  return;
}


// ==== FUN_00805d86 @ 0x00805d86 ====

void FUN_00805d86(void)

{
  int unaff_EBP;
  int unaff_EDI;
  
  if (*(int *)(unaff_EBP + 0x10) != unaff_EDI) {
    FUN_00806c2f(8);
  }
  return;
}


// ==== _exit @ 0x00805d9a ====

/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 2003 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}


// ==== __exit @ 0x00805dab ====

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2003 Release */

void __exit(undefined4 param_1)

{
  doexit(param_1,1,0);
  return;
}


// ==== __cexit @ 0x00805dbc ====

/* Library Function - Single Match
    __cexit
   
   Library: Visual Studio 2003 Release */

void __cdecl __cexit(void)

{
  doexit(0,0,1);
  return;
}


// ==== FUN_00805dcb @ 0x00805dcb ====

void FUN_00805dcb(void)

{
  doexit(0,1,1);
  return;
}


// ==== strtoxl @ 0x00805dda ====

/* Library Function - Single Match
    _strtoxl
   
   Library: Visual Studio 2003 Release */

uint __cdecl strtoxl(byte *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  _ptiddata p_Var2;
  pthreadlocinfo ptVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  byte *pbVar9;
  uint local_8;
  
  p_Var2 = __getptd();
  ptVar3 = (pthreadlocinfo)p_Var2->_tfpecode;
  if (ptVar3 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar3 = ___updatetlocinfo();
  }
  local_8 = 0;
  bVar8 = *param_1;
  pbVar1 = param_1;
  while( true ) {
    pbVar9 = pbVar1 + 1;
    if ((int)ptVar3->lc_category[1].refcount < 2) {
      uVar4 = *(byte *)((int)ptVar3->lc_category[3].refcount + (uint)bVar8 * 2) & 8;
    }
    else {
      uVar4 = ___isctype_mt(ptVar3,(uint)bVar8,8);
    }
    if (uVar4 == 0) break;
    bVar8 = *pbVar9;
    pbVar1 = pbVar9;
  }
  if (bVar8 == 0x2d) {
    param_4 = param_4 | 2;
LAB_00805e41:
    bVar8 = *pbVar9;
    pbVar9 = pbVar1 + 2;
  }
  else if (bVar8 == 0x2b) goto LAB_00805e41;
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
    }
    return 0;
  }
  if (param_3 == 0) {
    if (bVar8 != 0x30) {
      param_3 = 10;
      goto LAB_00805ea4;
    }
    if ((*pbVar9 != 0x78) && (*pbVar9 != 0x58)) {
      param_3 = 8;
      goto LAB_00805ea4;
    }
    param_3 = 0x10;
  }
  if (((param_3 == 0x10) && (bVar8 == 0x30)) && ((*pbVar9 == 0x78 || (*pbVar9 == 0x58)))) {
    bVar8 = pbVar9[1];
    pbVar9 = pbVar9 + 2;
  }
LAB_00805ea4:
  uVar4 = (uint)(0xffffffff / (ulonglong)param_3);
  do {
    if ((*(ushort *)(PTR_DAT_00b49d38 + (uint)bVar8 * 2) & 4) == 0) {
      if ((*(ushort *)(PTR_DAT_00b49d38 + (uint)bVar8 * 2) & 0x103) == 0) {
LAB_00805f10:
        pbVar9 = pbVar9 + -1;
        if ((param_4 & 8) == 0) {
          if (param_2 != (undefined4 *)0x0) {
            pbVar9 = param_1;
          }
          local_8 = 0;
        }
        else if (((param_4 & 4) != 0) ||
                (((param_4 & 1) == 0 &&
                 ((((param_4 & 2) != 0 && (0x80000000 < local_8)) ||
                  (((param_4 & 2) == 0 && (0x7fffffff < local_8)))))))) {
          puVar5 = (undefined4 *)FUN_00804b94();
          *puVar5 = 0x22;
          if ((param_4 & 1) == 0) {
            local_8 = ((param_4 & 2) != 0) + 0x7fffffff;
          }
          else {
            local_8 = 0xffffffff;
          }
        }
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = pbVar9;
        }
        if ((param_4 & 2) != 0) {
          local_8 = -local_8;
        }
        return local_8;
      }
      if (((char)bVar8 < 'a') || ('z' < (char)bVar8)) {
        iVar7 = (int)(char)bVar8;
      }
      else {
        iVar7 = (char)bVar8 + -0x20;
      }
      uVar6 = iVar7 - 0x37;
    }
    else {
      uVar6 = (int)(char)bVar8 - 0x30;
    }
    if (param_3 <= uVar6) goto LAB_00805f10;
    if ((local_8 < uVar4) ||
       ((local_8 == uVar4 && (uVar6 <= (uint)(0xffffffff % (ulonglong)param_3))))) {
      local_8 = local_8 * param_3 + uVar6;
      param_4 = param_4 | 8;
    }
    else {
      param_4 = param_4 | 0xc;
    }
    bVar8 = *pbVar9;
    pbVar9 = pbVar9 + 1;
  } while( true );
}


// ==== _strtoul @ 0x00805f99 ====

/* Library Function - Single Match
    _strtoul
   
   Library: Visual Studio 2003 Release */

ulong __cdecl _strtoul(char *_Str,char **_EndPtr,int _Radix)

{
  ulong uVar1;
  
  uVar1 = strtoxl(_Str,_EndPtr,_Radix,1);
  return uVar1;
}


// ==== _longjmp @ 0x00805fb0 ====

/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    _longjmp
   
   Library: Visual Studio 2003 Release */

void __cdecl _longjmp(int *_Buf,int _Value)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = (void *)_Buf[6];
  if (pvVar1 != ExceptionList) {
    __global_unwind2(pvVar1);
  }
  if (pvVar1 != (void *)0x0) {
    iVar2 = __rt_probe_read4_4(_Buf + 8);
    if ((iVar2 == 0) || (_Buf[8] != 0x56433230)) {
      __local_unwind2(pvVar1,_Buf[7]);
    }
    else if ((code *)_Buf[9] != (code *)0x0) {
      (*(code *)_Buf[9])(_Buf);
    }
  }
  FUN_0080013a(0);
                    /* WARNING: Could not recover jumptable at 0x00806025. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)_Buf[5])();
  return;
}


// ==== __setjmp3 @ 0x0080602c ====

/* Library Function - Single Match
    __setjmp3
   
   Library: Visual Studio */

undefined4
__setjmp3(undefined4 *param_1,int param_2,void *param_3,undefined4 param_4,undefined4 param_5)

{
  void *pvVar1;
  uint uVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 *puVar3;
  undefined4 unaff_EDI;
  undefined4 *puVar4;
  undefined4 unaff_retaddr;
  
  *param_1 = unaff_EBP;
  param_1[1] = unaff_EBX;
  param_1[2] = unaff_EDI;
  param_1[3] = unaff_ESI;
  param_1[4] = register0x00000010;
  param_1[5] = unaff_retaddr;
  param_1[8] = 0x56433230;
  param_1[9] = 0;
  pvVar1 = ExceptionList;
  param_1[6] = ExceptionList;
  if (pvVar1 == (void *)0xffffffff) {
    param_1[7] = 0xffffffff;
  }
  else if ((param_2 == 0) || (param_1[9] = param_3, pvVar1 = param_3, param_2 == 1)) {
    param_1[7] = *(undefined4 *)((int)pvVar1 + 0xc);
  }
  else {
    param_1[7] = param_4;
    uVar2 = param_2 - 2;
    if (uVar2 != 0) {
      puVar3 = &param_5;
      puVar4 = param_1 + 10;
      if (6 < uVar2) {
        uVar2 = 6;
      }
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
  }
  return 0;
}


// ==== _strcoll @ 0x008060a7 ====

/* Library Function - Single Match
    _strcoll
   
   Library: Visual Studio 2003 Release */

int __cdecl _strcoll(char *_Str1,char *_Str2)

{
  char *pcVar1;
  _ptiddata p_Var2;
  pthreadlocinfo ptVar3;
  int iVar4;
  undefined4 *puVar5;
  
  p_Var2 = __getptd();
  ptVar3 = (pthreadlocinfo)p_Var2->_tfpecode;
  if (ptVar3 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar3 = ___updatetlocinfo();
  }
  pcVar1 = ptVar3->lc_category[0].locale;
  if ((pcVar1 == (char *)0x0) && (DAT_00b5ca60 == 0)) {
    iVar4 = _strcmp(_Str1,_Str2);
    return iVar4;
  }
  iVar4 = FUN_00812101(pcVar1,0x1000,_Str1,0xffffffff,_Str2,0xffffffff,ptVar3->lc_collate_cp);
  if (iVar4 == 0) {
    puVar5 = (undefined4 *)FUN_00804b94();
    *puVar5 = 0x16;
    return 0x7fffffff;
  }
  return iVar4 + -2;
}


// ==== _strtod @ 0x00806106 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _strtod
   
   Library: Visual Studio 2003 Release */

double __cdecl _strtod(char *_Str,char **_EndPtr)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  uint *puVar5;
  undefined4 *puVar6;
  byte *_Str_00;
  int iVar7;
  undefined1 local_24 [24];
  double local_c;
  
  bVar1 = *_Str;
  _Str_00 = (byte *)_Str;
  while (iVar3 = _isspace((uint)bVar1), iVar3 != 0) {
    _Str_00 = _Str_00 + 1;
    bVar1 = *_Str_00;
  }
  iVar7 = iVar3;
  sVar4 = _strlen((char *)_Str_00);
  puVar5 = (uint *)FUN_0080eda2(local_24,_Str_00,sVar4,iVar3,iVar7);
  if (_EndPtr != (char **)0x0) {
    *_EndPtr = (char *)(_Str_00 + puVar5[1]);
  }
  uVar2 = *puVar5;
  if ((uVar2 & 0x240) == 0) {
    if ((uVar2 & 0x81) == 0) {
      if ((uVar2 & 0x100) == 0) {
        return *(double *)(puVar5 + 4);
      }
      local_c = 0.0;
    }
    else {
      local_c = _DAT_00b4a2e4;
      if (*_Str_00 == 0x2d) {
        local_c = -_DAT_00b4a2e4;
      }
    }
    puVar6 = (undefined4 *)FUN_00804b94();
    *puVar6 = 0x22;
  }
  else {
    local_c = 0.0;
    if (_EndPtr != (char **)0x0) {
      *_EndPtr = _Str;
    }
  }
  return local_c;
}


// ==== _strncat @ 0x008061a0 ====

/* Library Function - Single Match
    _strncat
   
   Library: Visual Studio */

char * __cdecl _strncat(char *_Dest,char *_Source,size_t _Count)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar5 = (uint *)_Dest;
  if (_Count == 0) {
    return _Dest;
  }
  do {
    if (((uint)puVar5 & 3) == 0) goto LAB_008061cc;
    uVar4 = *puVar5;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_008061fd;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar6 = (uint *)((int)puVar6 + 2);
      goto LAB_0080620f;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_008061cc:
    do {
      puVar6 = puVar5;
      puVar5 = puVar6 + 1;
    } while (((*puVar6 ^ 0xffffffff ^ *puVar6 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar6;
    if ((char)uVar4 == '\0') goto LAB_0080620f;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar6 = (uint *)((int)puVar6 + 1);
      goto LAB_0080620f;
    }
  }
LAB_008061fd:
  puVar6 = (uint *)((int)puVar5 + -1);
LAB_0080620f:
  if (((uint)_Source & 3) == 0) {
    uVar3 = _Count >> 2;
  }
  else {
    do {
      bVar1 = (byte)*(uint *)_Source;
      uVar4 = (uint)bVar1;
      _Source = (char *)((int)_Source + 1);
      if (bVar1 == 0) goto LAB_0080626a;
      *(byte *)puVar6 = bVar1;
      puVar6 = (uint *)((int)puVar6 + 1);
      _Count = _Count - 1;
      if (_Count == 0) goto LAB_00806260;
    } while (((uint)_Source & 3) != 0);
    uVar3 = _Count >> 2;
  }
  do {
    if (uVar3 == 0) {
      for (uVar4 = _Count & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar3 = *(uint *)_Source;
        _Source = (char *)((int)_Source + 1);
        *(byte *)puVar6 = (byte)uVar3;
        puVar6 = (uint *)((int)puVar6 + 1);
        if ((byte)uVar3 == 0) {
          return _Dest;
        }
      }
LAB_00806260:
      *(byte *)puVar6 = 0;
      return _Dest;
    }
    uVar2 = *(uint *)_Source;
    uVar4 = *(uint *)_Source;
    _Source = (char *)((int)_Source + 4);
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar4 == '\0') {
LAB_0080626a:
        *(byte *)puVar6 = (byte)uVar4;
        return _Dest;
      }
      if ((char)(uVar4 >> 8) == '\0') {
        *(short *)puVar6 = (short)uVar4;
        return _Dest;
      }
      if ((uVar4 & 0xff0000) == 0) {
        *(short *)puVar6 = (short)uVar4;
        *(byte *)((int)puVar6 + 2) = 0;
        return _Dest;
      }
      if ((uVar4 & 0xff000000) == 0) {
        *puVar6 = uVar4;
        return _Dest;
      }
    }
    *puVar6 = uVar4;
    puVar6 = puVar6 + 1;
    uVar3 = uVar3 - 1;
  } while( true );
}


// ==== _strcspn @ 0x008062e0 ====

/* Library Function - Single Match
    _strcspn
   
   Library: Visual Studio 2003 Release */

size_t __cdecl _strcspn(char *_Str,char *_Control)

{
  byte bVar1;
  size_t sVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = _Control + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  sVar2 = 0xffffffff;
  do {
    sVar2 = sVar2 + 1;
    bVar1 = *_Str;
    if (bVar1 == 0) {
      return sVar2;
    }
    _Str = _Str + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return sVar2;
}


// ==== FUN_00806326 @ 0x00806326 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

void * FUN_00806326(void *param_1,size_t param_2)

{
  void *pvVar1;
  void *extraout_EAX;
  int iVar2;
  uint uVar3;
  LPVOID pvVar4;
  int local_24;
  void *local_20;
  
  if (param_1 == (void *)0x0) {
    pvVar1 = _malloc(param_2);
  }
  else {
    if (param_2 == 0) {
      _free(param_1);
      return extraout_EAX;
    }
    if (DAT_00b60f7c == 3) {
      do {
        local_20 = (void *)0x0;
        if (0xffffffe0 < param_2) {
LAB_008064c9:
          __callnewh(param_2);
          return (void *)0x0;
        }
        __lock(4);
        local_24 = ___sbh_find_block(param_1);
        if (local_24 != 0) {
          if (param_2 <= DAT_00b60f4c) {
            iVar2 = ___sbh_resize_block(local_24,param_1,param_2);
            if (iVar2 == 0) {
              local_20 = (void *)___sbh_alloc_block(param_2);
              if (local_20 != (void *)0x0) {
                uVar3 = *(int *)((int)param_1 + -4) - 1;
                if (param_2 <= uVar3) {
                  uVar3 = param_2;
                }
                _memcpy(local_20,param_1,uVar3);
                local_24 = ___sbh_find_block(param_1);
                ___sbh_free_block(local_24,param_1);
              }
            }
            else {
              local_20 = param_1;
            }
          }
          if (local_20 == (void *)0x0) {
            if (param_2 == 0) {
              param_2 = 1;
            }
            param_2 = param_2 + 0xf & 0xfffffff0;
            local_20 = HeapAlloc(DAT_00b60f78,0,param_2);
            if (local_20 != (LPVOID)0x0) {
              uVar3 = *(int *)((int)param_1 + -4) - 1;
              if (param_2 <= uVar3) {
                uVar3 = param_2;
              }
              _memcpy(local_20,param_1,uVar3);
              ___sbh_free_block(local_24,param_1);
            }
          }
        }
        FUN_0080648e();
        if (local_24 == 0) {
          if (param_2 == 0) {
            param_2 = 1;
          }
          param_2 = param_2 + 0xf & 0xfffffff0;
          local_20 = HeapReAlloc(DAT_00b60f78,0,param_1,param_2);
        }
        if (local_20 != (void *)0x0) {
          return local_20;
        }
        if (DAT_00b5cb78 == 0) {
          return (void *)0x0;
        }
        iVar2 = __callnewh(param_2);
      } while (iVar2 != 0);
    }
    else {
      do {
        if (0xffffffe0 < param_2) goto LAB_008064c9;
        if (param_2 == 0) {
          param_2 = 1;
        }
        pvVar4 = HeapReAlloc(DAT_00b60f78,0,param_1,param_2);
        if (pvVar4 != (LPVOID)0x0) {
          return pvVar4;
        }
        if (DAT_00b5cb78 == 0) {
          return (void *)0x0;
        }
        iVar2 = __callnewh(param_2);
      } while (iVar2 != 0);
    }
    pvVar1 = (void *)0x0;
  }
  return pvVar1;
}


// ==== FUN_0080648e @ 0x0080648e ====

void FUN_0080648e(void)

{
  FUN_00806c2f(4);
  return;
}


// ==== _free @ 0x008064d8 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _free
   
   Library: Visual Studio 2003 Release */

void __cdecl _free(void *_Memory)

{
  int iVar1;
  
  if (_Memory != (void *)0x0) {
    if (DAT_00b60f7c == 3) {
      __lock(4);
      iVar1 = ___sbh_find_block(_Memory);
      if (iVar1 != 0) {
        ___sbh_free_block(iVar1,_Memory);
      }
      FUN_0080652b();
      if (iVar1 != 0) {
        return;
      }
    }
    HeapFree(DAT_00b60f78,0,_Memory);
  }
  return;
}


// ==== FUN_0080652b @ 0x0080652b ====

void FUN_0080652b(void)

{
  FUN_00806c2f(4);
  return;
}


// ==== __snprintf @ 0x00806549 ====

/* Library Function - Single Match
    __snprintf
   
   Library: Visual Studio 2003 Release */

int __cdecl __snprintf(char *_Dest,size_t _Count,char *_Format,...)

{
  int iVar1;
  undefined1 uStack00000010;
  FILE local_24;
  
  local_24._cnt = _Count;
  local_24._flag = 0x42;
  local_24._base = _Dest;
  local_24._ptr = _Dest;
  iVar1 = FUN_0080bae5(&local_24,_Format,&uStack00000010);
  if (_Dest != (char *)0x0) {
    local_24._cnt = local_24._cnt - 1;
    if (local_24._cnt < 0) {
      __flsbuf(0,&local_24);
    }
    else {
      *local_24._ptr = '\0';
    }
  }
  return iVar1;
}


// ==== _sscanf @ 0x008065a0 ====

/* Library Function - Single Match
    _sscanf
   
   Library: Visual Studio 2003 Release */

int __cdecl _sscanf(char *_Src,char *_Format,...)

{
  int iVar1;
  undefined1 uStack0000000c;
  char *local_24;
  size_t local_20;
  char *local_1c;
  undefined4 local_18;
  
  local_18 = 0x49;
  local_1c = _Src;
  local_24 = _Src;
  local_20 = _strlen(_Src);
  iVar1 = FUN_0080df77(&local_24,_Format,&uStack0000000c);
  return iVar1;
}


// ==== FUN_008065d4 @ 0x008065d4 ====

undefined4 FUN_008065d4(LPCSTR param_1,byte param_2)

{
  DWORD DVar1;
  BOOL BVar2;
  
  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 != 0xffffffff) {
    if ((param_2 & 0x80) == 0) {
      DVar1 = DVar1 | 1;
    }
    else {
      DVar1 = DVar1 & 0xfffffffe;
    }
    BVar2 = SetFileAttributesA(param_1,DVar1);
    if (BVar2 != 0) {
      return 0;
    }
  }
  DVar1 = GetLastError();
  __dosmaperr(DVar1);
  return 0xffffffff;
}


// ==== __strdup @ 0x00806615 ====

/* Library Function - Single Match
    __strdup
   
   Library: Visual Studio 2003 Release */

char * __cdecl __strdup(char *_Src)

{
  size_t sVar1;
  void *pvVar2;
  char *pcVar3;
  
  if (_Src != (char *)0x0) {
    sVar1 = _strlen(_Src);
    pvVar2 = _malloc(sVar1 + 1);
    if (pvVar2 != (void *)0x0) {
      pcVar3 = (char *)FUN_00809180(pvVar2,_Src);
      return pcVar3;
    }
  }
  return (char *)0x0;
}


// ==== _strrchr @ 0x00806640 ====

/* Library Function - Single Match
    _strrchr
   
   Library: Visual Studio 2003 Release */

char * __cdecl _strrchr(char *_Str,int _Ch)

{
  char cVar1;
  int iVar2;
  char *pcVar4;
  char *pcVar3;
  
  iVar2 = -1;
  do {
    pcVar4 = _Str;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = _Str + 1;
    cVar1 = *_Str;
    _Str = pcVar4;
  } while (cVar1 != '\0');
  iVar2 = -(iVar2 + 1);
  pcVar4 = pcVar4 + -1;
  do {
    pcVar3 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar3 = pcVar4 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar3;
  } while ((char)_Ch != cVar1);
  pcVar3 = pcVar3 + 1;
  if (*pcVar3 != (char)_Ch) {
    pcVar3 = (char *)0x0;
  }
  return pcVar3;
}


// ==== _strstr @ 0x00806670 ====

/* Library Function - Single Match
    _strstr
   
   Library: Visual Studio 2003 Release */

char * __cdecl _strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint *puVar9;
  char *pcVar10;
  
  cVar3 = *_SubStr;
  if (cVar3 == '\0') {
    return _Str;
  }
  if (_SubStr[1] == '\0') {
    while (((uint)_Str & 3) != 0) {
      uVar4 = *(uint *)_Str;
      if ((char)uVar4 == cVar3) {
        return (char *)(uint *)_Str;
      }
      _Str = (char *)((int)_Str + 1);
      if ((char)uVar4 == '\0') {
        return (char *)0x0;
      }
    }
    while( true ) {
      while( true ) {
        uVar4 = *(uint *)_Str;
        uVar7 = uVar4 ^ CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,cVar3));
        uVar6 = uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff;
        puVar9 = (uint *)((int)_Str + 4);
        if (((uVar7 ^ 0xffffffff ^ uVar7 + 0x7efefeff) & 0x81010100) != 0) break;
        _Str = (char *)puVar9;
        if ((uVar6 & 0x81010100) != 0) {
          if ((uVar6 & 0x1010100) != 0) {
            return (char *)0x0;
          }
          if ((uVar4 + 0x7efefeff & 0x80000000) == 0) {
            return (char *)0x0;
          }
        }
      }
      uVar4 = *(uint *)_Str;
      if ((char)uVar4 == cVar3) {
        return (char *)(uint *)_Str;
      }
      if ((char)uVar4 == '\0') {
        return (char *)0x0;
      }
      cVar5 = (char)(uVar4 >> 8);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 1);
      }
      if (cVar5 == '\0') {
        return (char *)0x0;
      }
      cVar5 = (char)(uVar4 >> 0x10);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 2);
      }
      if (cVar5 == '\0') break;
      cVar5 = (char)(uVar4 >> 0x18);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 3);
      }
      _Str = (char *)puVar9;
      if (cVar5 == '\0') {
        return (char *)0x0;
      }
    }
    return (char *)0x0;
  }
  do {
    cVar5 = *_Str;
    do {
      while (_Str = _Str + 1, cVar5 != cVar3) {
        if (cVar5 == '\0') {
          return (char *)0x0;
        }
        cVar5 = *_Str;
      }
      cVar5 = *_Str;
      pcVar10 = _Str + 1;
      pcVar8 = _SubStr;
    } while (cVar5 != _SubStr[1]);
    do {
      if (pcVar8[2] == '\0') {
LAB_008066e9:
        return _Str + -1;
      }
      if (*pcVar10 != pcVar8[2]) break;
      pcVar1 = pcVar8 + 3;
      if (*pcVar1 == '\0') goto LAB_008066e9;
      pcVar2 = pcVar10 + 1;
      pcVar8 = pcVar8 + 2;
      pcVar10 = pcVar10 + 2;
    } while (*pcVar1 == *pcVar2);
  } while( true );
}


// ==== __allrem @ 0x00806700 ====

/* Library Function - Single Match
    __allrem
   
   Library: Visual Studio */

undefined8 __allrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  
  bVar12 = (int)param_2 < 0;
  if (bVar12) {
    bVar11 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar11 - param_2;
  }
  uVar10 = (uint)bVar12;
  if ((int)param_4 < 0) {
    bVar12 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar12 - param_4;
  }
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
    if ((int)(uVar10 - 1) < 0) goto LAB_008067ad;
  }
  else {
    uVar5 = param_1;
    uVar4 = param_3;
    uVar8 = param_2;
    uVar9 = param_4;
    do {
      uVar3 = uVar9 & 1;
      uVar9 = uVar9 >> 1;
      uVar4 = (uint)(CONCAT14(uVar3 != 0,uVar4) >> 1);
      uVar3 = uVar8 & 1;
      uVar8 = uVar8 >> 1;
      uVar5 = (uint)(CONCAT14(uVar3 != 0,uVar5) >> 1);
    } while (uVar9 != 0);
    uVar1 = CONCAT44(uVar8,uVar5) / (ulonglong)uVar4;
    uVar4 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar8 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar5 = (uint)lVar2;
    uVar9 = uVar8 + uVar4;
    if (((CARRY4(uVar8,uVar4)) || (param_2 < uVar9)) || ((param_2 <= uVar9 && (param_1 < uVar5)))) {
      bVar12 = uVar5 < param_3;
      uVar5 = uVar5 - param_3;
      uVar9 = (uVar9 - param_4) - (uint)bVar12;
    }
    iVar6 = uVar5 - param_1;
    iVar7 = (uVar9 - param_2) - (uint)(uVar5 < param_1);
    if (-1 < (int)(uVar10 - 1)) goto LAB_008067ad;
  }
  bVar12 = iVar6 != 0;
  iVar6 = -iVar6;
  iVar7 = -(uint)bVar12 - iVar7;
LAB_008067ad:
  return CONCAT44(iVar7,iVar6);
}


// ==== __aulldvrm @ 0x008067c0 ====

/* Library Function - Single Match
    __aulldvrm
   
   Library: Visual Studio */

undefined8 __aulldvrm(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_4 == 0) {
    uVar4 = param_2 / param_3;
    iVar5 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    uVar8 = param_1;
    uVar6 = param_4;
    uVar7 = param_2;
    uVar4 = param_3;
    do {
      uVar3 = uVar6 & 1;
      uVar6 = uVar6 >> 1;
      uVar4 = (uint)(CONCAT14(uVar3 != 0,uVar4) >> 1);
      uVar3 = uVar7 & 1;
      uVar7 = uVar7 >> 1;
      uVar8 = (uint)(CONCAT14(uVar3 != 0,uVar8) >> 1);
    } while (uVar6 != 0);
    uVar1 = CONCAT44(uVar7,uVar8) / (ulonglong)uVar4;
    iVar5 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar4 + iVar5 * param_4;
    if (((CARRY4(uVar4,iVar5 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar5 = iVar5 + -1;
    }
    uVar4 = 0;
  }
  return CONCAT44(uVar4,iVar5);
}


// ==== _memset @ 0x00806860 ====

/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2003 Release, Visual Studio 2019 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = _Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}


// ==== _strncmp @ 0x008068c0 ====

/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2003 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar5 = 0;
  if (_MaxCount != 0) {
    sVar3 = _MaxCount;
    pcVar6 = _Str1;
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}


// ==== __aulldiv @ 0x00806900 ====

/* Library Function - Single Match
    __aulldiv
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_4 == 0) {
    uVar4 = param_2 / param_3;
    iVar5 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    uVar8 = param_1;
    uVar6 = param_4;
    uVar7 = param_2;
    uVar4 = param_3;
    do {
      uVar3 = uVar6 & 1;
      uVar6 = uVar6 >> 1;
      uVar4 = (uint)(CONCAT14(uVar3 != 0,uVar4) >> 1);
      uVar3 = uVar7 & 1;
      uVar7 = uVar7 >> 1;
      uVar8 = (uint)(CONCAT14(uVar3 != 0,uVar8) >> 1);
    } while (uVar6 != 0);
    uVar1 = CONCAT44(uVar7,uVar8) / (ulonglong)uVar4;
    iVar5 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar4 + iVar5 * param_4;
    if (((CARRY4(uVar4,iVar5 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar5 = iVar5 + -1;
    }
    uVar4 = 0;
  }
  return CONCAT44(uVar4,iVar5);
}


// ==== __ValidateEH3RN @ 0x00806968 ====

/* Library Function - Single Match
    __ValidateEH3RN
   
   Library: Visual Studio 2003 Release */

undefined4 __ValidateEH3RN(void *param_1)

{
  uint *puVar1;
  void *pvVar2;
  uint uVar3;
  void *pvVar4;
  uint *puVar5;
  SIZE_T SVar6;
  int *piVar7;
  LONG LVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  _MEMORY_BASIC_INFORMATION local_24;
  void *local_8;
  
  pvVar4 = param_1;
  puVar9 = *(uint **)((int)param_1 + 8);
  if ((((uint)puVar9 & 3) != 0) ||
     ((local_8 = StackLimit, StackLimit <= puVar9 && (puVar9 < StackBase)))) {
    return 0;
  }
  puVar1 = (uint *)((int)param_1 + 0xc);
  if (*puVar1 == 0xffffffff) {
    return 1;
  }
  uVar11 = 0;
  param_1 = (void *)0x0;
  puVar5 = puVar9;
  do {
    if ((*puVar5 != 0xffffffff) && (uVar11 <= *puVar5)) {
      return 0;
    }
    if (puVar5[1] != 0) {
      param_1 = (void *)((int)param_1 + 1);
    }
    uVar11 = uVar11 + 1;
    puVar5 = puVar5 + 3;
  } while (uVar11 <= *puVar1);
  if ((param_1 != (void *)0x0) &&
     ((pvVar2 = *(void **)((int)pvVar4 + -8), pvVar2 < StackLimit || (pvVar4 <= pvVar2)))) {
    return 0;
  }
  uVar11 = (uint)puVar9 & 0xfffff000;
  iVar14 = 0;
  if (0 < DAT_00b5c768) {
    do {
      if ((&DAT_00b5c770)[iVar14] == uVar11) {
        if (iVar14 < 1) {
          return 1;
        }
        LVar8 = InterlockedExchange((LONG *)&DAT_00b5c7b0,1);
        if (LVar8 != 0) {
          return 1;
        }
        if ((&DAT_00b5c770)[iVar14] == uVar11) goto LAB_00806b63;
        iVar14 = DAT_00b5c768 + -1;
        if (iVar14 < 0) goto LAB_00806b51;
        goto LAB_00806b41;
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 < DAT_00b5c768);
  }
  SVar6 = VirtualQuery(puVar9,&local_24,0x1c);
  if (SVar6 == 0) {
    return 0xffffffff;
  }
  if (local_24.Type != 0x1000000) {
    return 0xffffffff;
  }
  if (((byte)local_24.Protect & 0xcc) != 0) {
    if (((*(short *)local_24.AllocationBase != 0x5a4d) ||
        (piVar7 = (int *)(*(int *)((int)local_24.AllocationBase + 0x3c) +
                         (int)local_24.AllocationBase), *piVar7 != 0x4550)) ||
       ((short)piVar7[6] != 0x10b)) {
      return 0xffffffff;
    }
    uVar10 = (uint)*(ushort *)(piVar7 + 5);
    if (*(short *)((int)piVar7 + 6) == 0) {
      return 0xffffffff;
    }
    uVar3 = *(uint *)((int)piVar7 + uVar10 + 0x24);
    if (((uVar3 <= (uint)((int)puVar9 - (int)local_24.AllocationBase)) &&
        ((uint)((int)puVar9 - (int)local_24.AllocationBase) <
         *(int *)((int)piVar7 + uVar10 + 0x20) + uVar3)) &&
       ((*(byte *)((int)piVar7 + uVar10 + 0x3f) & 0x80) != 0)) {
      return 0;
    }
  }
  LVar8 = InterlockedExchange((LONG *)&DAT_00b5c7b0,1);
  iVar14 = DAT_00b5c768;
  if (LVar8 != 0) {
    return 1;
  }
  iVar12 = DAT_00b5c768;
  if (0 < DAT_00b5c768) {
    puVar9 = (uint *)(&DAT_00b5c76c + DAT_00b5c768 * 4);
    do {
      if (*puVar9 == uVar11) break;
      iVar12 = iVar12 + -1;
      puVar9 = puVar9 + -1;
    } while (0 < iVar12);
  }
  if (iVar12 == 0) {
    iVar12 = 0xf;
    if (DAT_00b5c768 < 0x10) {
      iVar12 = DAT_00b5c768;
    }
    iVar13 = 0;
    if (-1 < iVar12) {
      do {
        puVar9 = &DAT_00b5c770 + iVar13;
        uVar10 = *puVar9;
        iVar13 = iVar13 + 1;
        *puVar9 = uVar11;
        uVar11 = uVar10;
      } while (iVar13 <= iVar12);
    }
    if (iVar14 < 0x10) {
      DAT_00b5c768 = iVar14 + 1;
    }
  }
  InterlockedExchange((LONG *)&DAT_00b5c7b0,0);
  return 1;
  while (iVar14 = iVar14 + -1, -1 < iVar14) {
LAB_00806b41:
    if ((&DAT_00b5c770)[iVar14] == uVar11) break;
  }
  if (iVar14 < 0) {
LAB_00806b51:
    if (DAT_00b5c768 < 0x10) {
      DAT_00b5c768 = DAT_00b5c768 + 1;
    }
    iVar14 = DAT_00b5c768 + -1;
  }
  else if (iVar14 == 0) goto LAB_00806b7b;
LAB_00806b63:
  iVar12 = 0;
  if (-1 < iVar14) {
    do {
      puVar9 = &DAT_00b5c770 + iVar12;
      uVar10 = *puVar9;
      iVar12 = iVar12 + 1;
      *puVar9 = uVar11;
      uVar11 = uVar10;
    } while (iVar12 <= iVar14);
  }
LAB_00806b7b:
  InterlockedExchange((LONG *)&DAT_00b5c7b0,0);
  return 1;
}


// ==== __mtinitlocks @ 0x00806b91 ====

/* Library Function - Single Match
    __mtinitlocks
   
   Library: Visual Studio 2003 Release */

int __cdecl __mtinitlocks(void)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0;
  puVar3 = &DAT_00b5c7b8;
  do {
    if ((&DAT_00b49ac4)[iVar2 * 2] == 1) {
      (&PTR_DAT_00b49ac0)[iVar2 * 2] = puVar3;
      puVar3 = puVar3 + 0x18;
      iVar1 = ___crtInitCritSecAndSpinCount((&PTR_DAT_00b49ac0)[iVar2 * 2],4000);
      if (iVar1 == 0) {
        (&PTR_DAT_00b49ac0)[iVar2 * 2] = (undefined *)0x0;
        return 0;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x24);
  return 1;
}


// ==== FUN_00806bda @ 0x00806bda ====

void FUN_00806bda(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined **ppuVar1;
  
  ppuVar1 = &PTR_DAT_00b49ac0;
  while ((lpCriticalSection = (LPCRITICAL_SECTION)*ppuVar1,
         lpCriticalSection == (LPCRITICAL_SECTION)0x0 || (ppuVar1[1] == (undefined *)0x1))) {
    ppuVar1 = ppuVar1 + 2;
    if (0xb49bdf < (int)ppuVar1) {
      ppuVar1 = &PTR_DAT_00b49ac0;
      do {
        if (((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
           (ppuVar1[1] == (undefined *)0x1)) {
          DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
        }
        ppuVar1 = ppuVar1 + 2;
      } while ((int)ppuVar1 < 0xb49be0);
      return;
    }
  }
  DeleteCriticalSection(lpCriticalSection);
  _free(lpCriticalSection);
  return;
}


// ==== FUN_00806c2f @ 0x00806c2f ====

void FUN_00806c2f(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&PTR_DAT_00b49ac0)[param_1 * 2]);
  return;
}


// ==== FUN_00806c44 @ 0x00806c44 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

undefined4 FUN_00806c44(int param_1)

{
  undefined **ppuVar1;
  undefined *_Memory;
  undefined4 *puVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  
  ppuVar1 = &PTR_DAT_00b49ac0 + param_1 * 2;
  if (*ppuVar1 == (undefined *)0x0) {
    _Memory = _malloc(0x18);
    if (_Memory == (undefined *)0x0) {
      puVar2 = (undefined4 *)FUN_00804b94();
      *puVar2 = 0xc;
      return 0;
    }
    __lock(10);
    if (*ppuVar1 != (undefined *)0x0) {
      _free(_Memory);
      return extraout_EAX_00;
    }
    iVar3 = ___crtInitCritSecAndSpinCount(_Memory,4000);
    if (iVar3 == 0) {
      _free(_Memory);
      return extraout_EAX;
    }
    *ppuVar1 = _Memory;
    FUN_00806cdb();
  }
  return 1;
}


// ==== FUN_00806cdb @ 0x00806cdb ====

void FUN_00806cdb(void)

{
  FUN_00806c2f(10);
  return;
}


// ==== __lock @ 0x00806ce4 ====

/* Library Function - Single Match
    __lock
   
   Library: Visual Studio 2003 Release */

void __cdecl __lock(int _File)

{
  int iVar1;
  
  if ((&PTR_DAT_00b49ac0)[_File * 2] == (undefined *)0x0) {
    iVar1 = FUN_00806c44(_File);
    if (iVar1 == 0) {
      __amsg_exit(0x11);
    }
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(&PTR_DAT_00b49ac0)[_File * 2]);
  return;
}


// ==== __SEH_prolog @ 0x00806d18 ====

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    __SEH_prolog
   
   Library: Visual Studio */

void __SEH_prolog(undefined4 param_1,int param_2)

{
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  undefined4 auStack_18 [4];
  undefined1 local_8 [8];
  
  param_2 = -param_2;
  *(undefined4 *)((int)auStack_18 + param_2 + 0xc) = unaff_EBX;
  *(undefined4 *)((int)auStack_18 + param_2 + 8) = unaff_ESI;
  *(undefined4 *)((int)auStack_18 + param_2 + 4) = unaff_EDI;
  *(undefined4 *)((int)auStack_18 + param_2) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}


// ==== __SEH_epilog @ 0x00806d53 ====

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __SEH_epilog
   
   Library: Visual Studio */

void __SEH_epilog(void)

{
  undefined4 *unaff_EBP;
  undefined4 unaff_retaddr;
  
  ExceptionList = (void *)unaff_EBP[-4];
  *unaff_EBP = unaff_retaddr;
  return;
}


// ==== _strcmp @ 0x00806d70 ====

/* Library Function - Single Match
    _strcmp
   
   Library: Visual Studio 2003 Release */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  bool bVar4;
  
  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar3 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar4 = bVar3 < (byte)*_Str2;
      if (bVar3 != *_Str2) goto LAB_00806db4;
      _Str2 = _Str2 + 1;
      if (bVar3 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_00806d80;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar3 = (byte)uVar1;
    bVar4 = bVar3 < (byte)*_Str2;
    if (bVar3 != *_Str2) goto LAB_00806db4;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((ushort)uVar1 >> 8);
    bVar4 = bVar3 < (byte)_Str2[1];
    if (bVar3 != _Str2[1]) goto LAB_00806db4;
    if (bVar3 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_00806d80:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar3 = (byte)uVar2;
    bVar4 = bVar3 < (byte)*_Str2;
    if (bVar3 != *_Str2) break;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((uint)uVar2 >> 8);
    bVar4 = bVar3 < (byte)_Str2[1];
    if (bVar3 != _Str2[1]) break;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((uint)uVar2 >> 0x10);
    bVar4 = bVar3 < (byte)_Str2[2];
    if (bVar3 != _Str2[2]) break;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    bVar4 = bVar3 < (byte)_Str2[3];
    if (bVar3 != _Str2[3]) break;
    _Str2 = _Str2 + 4;
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_00806db4:
  return (uint)bVar4 * -2 + 1;
}


// ==== TypeMatch @ 0x00806df8 ====

/* Library Function - Single Match
    int __cdecl TypeMatch(struct _s_HandlerType const *,struct _s_CatchableType const *,struct
   _s_ThrowInfo const *)
   
   Library: Visual Studio 2003 Release */

int __cdecl TypeMatch(_s_HandlerType *param_1,_s_CatchableType *param_2,_s_ThrowInfo *param_3)

{
  int iVar1;
  byte *unaff_ESI;
  byte *unaff_EDI;
  
  iVar1 = *(int *)(unaff_ESI + 4);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 8) != '\0')) {
    if ((iVar1 != *(int *)(unaff_EDI + 4)) &&
       (iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(unaff_EDI + 4) + 8)), iVar1 != 0)) {
      return 0;
    }
    if (((((*unaff_EDI & 2) != 0) && ((*unaff_ESI & 8) == 0)) ||
        (((param_1->adjectives & 1) != 0 && ((*unaff_ESI & 1) == 0)))) ||
       (((param_1->adjectives & 2) != 0 && ((*unaff_ESI & 2) == 0)))) {
      return 0;
    }
  }
  return 1;
}


// ==== ___FrameUnwindToState @ 0x00806e65 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___FrameUnwindToState
   
   Library: Visual Studio 2003 Release */

void ___FrameUnwindToState(int param_1,undefined4 param_2,int param_3,int param_4)

{
  _ptiddata p_Var1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 8);
  p_Var1 = __getptd();
  p_Var1->_purecall = (void *)((int)p_Var1->_purecall + 1);
  while (iVar4 != param_4) {
    if ((iVar4 < 0) || (*(int *)(param_3 + 4) <= iVar4)) {
      _inconsistency();
    }
    iVar2 = iVar4 * 8;
    piVar3 = (int *)(*(int *)(param_3 + 8) + iVar2);
    iVar4 = *piVar3;
    if (piVar3[1] != 0) {
      *(int *)(param_1 + 8) = iVar4;
      __CallSettingFrame_12(*(undefined4 *)(*(int *)(param_3 + 8) + 4 + iVar2),param_1,0x103);
    }
  }
  FUN_00806f18();
  if (iVar4 != param_4) {
    _inconsistency();
  }
  *(int *)(param_1 + 8) = iVar4;
  return;
}


// ==== FUN_00806ee1 @ 0x00806ee1 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00806ee1(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int unaff_EBP;
  int iVar6;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(unaff_EBP + 0x10);
  iVar3 = *(int *)(unaff_EBP + 8);
  iVar6 = *(int *)(unaff_EBP + -0x20);
  while (*(int *)(unaff_EBP + -0x1c) = iVar6, iVar6 != *(int *)(unaff_EBP + 0x14)) {
    if ((iVar6 < 0) || (*(int *)(iVar2 + 4) <= iVar6)) {
      *(undefined4 *)(iVar1 + -4) = 0x806ea1;
      _inconsistency();
    }
    iVar4 = iVar6 * 8;
    piVar5 = (int *)(*(int *)(iVar2 + 8) + iVar4);
    iVar6 = *piVar5;
    *(int *)(unaff_EBP + -0x20) = iVar6;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (piVar5[1] != 0) {
      *(int *)(iVar3 + 8) = iVar6;
      *(undefined4 *)(iVar1 + -4) = 0x103;
      *(int *)(iVar1 + -8) = iVar3;
      *(undefined4 *)(iVar1 + -0xc) = *(undefined4 *)(*(int *)(iVar2 + 8) + 4 + iVar4);
      *(undefined4 *)(iVar1 + -0x10) = 0x806ed2;
      __CallSettingFrame_12();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar1 + -4) = 0x806eff;
  FUN_00806f18();
  if (iVar6 != *(int *)(unaff_EBP + 0x14)) {
    *(undefined4 *)(iVar1 + -4) = 0x806f09;
    _inconsistency();
  }
  *(int *)(iVar3 + 8) = iVar6;
  *(undefined4 *)(iVar1 + -4) = 0x806f11;
  return;
}


// ==== FUN_00806f12 @ 0x00806f12 ====

void FUN_00806f12(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (0 < (int)p_Var1->_purecall) {
    p_Var1 = __getptd();
    p_Var1->_purecall = (void *)((int)p_Var1->_purecall + -1);
  }
  return;
}


// ==== FUN_00806f18 @ 0x00806f18 ====

void FUN_00806f18(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (0 < (int)p_Var1->_purecall) {
    p_Var1 = __getptd();
    p_Var1->_purecall = (void *)((int)p_Var1->_purecall + -1);
  }
  return;
}


// ==== ___DestructExceptionObject @ 0x00806f33 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___DestructExceptionObject
   
   Library: Visual Studio 2003 Release */

void ___DestructExceptionObject(int param_1)

{
  void *pvVar1;
  int unaff_ESI;
  void *unaff_EDI;
  
  if ((param_1 != 0) && (pvVar1 = *(void **)(*(int *)(param_1 + 0x1c) + 4), pvVar1 != (void *)0x0))
  {
    FID_conflict__CallMemberFunction1(*(void **)(param_1 + 0x18),pvVar1,unaff_EDI,unaff_ESI);
  }
  return;
}


// ==== FUN_00806f67 @ 0x00806f67 ====

bool FUN_00806f67(void)

{
  int unaff_EBP;
  
  return *(char *)(unaff_EBP + 0xc) != '\0';
}


// ==== FUN_00806f70 @ 0x00806f70 ====

void FUN_00806f70(void)

{
                    /* WARNING: Subroutine does not return */
  terminate();
}


// ==== AdjustPointer @ 0x00806f78 ====

/* Library Function - Single Match
    void * __cdecl AdjustPointer(void *,struct PMD const &)
   
   Library: Visual Studio 2003 Release */

void * __cdecl AdjustPointer(void *param_1,PMD *param_2)

{
  int in_EAX;
  void *pvVar1;
  int *in_ECX;
  
  pvVar1 = (void *)(*in_ECX + in_EAX);
  if (-1 < in_ECX[1]) {
    pvVar1 = (void *)((int)pvVar1 + *(int *)(*(int *)(in_ECX[1] + in_EAX) + in_ECX[2]) + in_ECX[1]);
  }
  return pvVar1;
}


// ==== CallCatchBlock @ 0x00806f97 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void * __cdecl CallCatchBlock(struct EHExceptionRecord *,struct EHRegistrationNode *,struct
   _CONTEXT *,struct _s_FuncInfo const *,void *,int,unsigned long)
   
   Library: Visual Studio 2003 Release */

void * __cdecl
CallCatchBlock(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,
              _s_FuncInfo *param_4,void *param_5,int param_6,ulong param_7)

{
  _ptiddata p_Var1;
  void *in_ECX;
  FrameInfo local_54 [8];
  undefined4 local_4c;
  void *local_48;
  void *local_44;
  FrameInfo *local_40;
  undefined4 local_3c;
  void *local_24;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00a06188;
  uStack_c = 0x806fa3;
  local_4c = 0;
  local_3c = *(undefined4 *)(param_2 + -4);
  local_40 = _CreateFrameInfo(local_54,*(void **)(param_1 + 0x18));
  p_Var1 = __getptd();
  local_44 = p_Var1->_unexpected;
  p_Var1 = __getptd();
  local_48 = p_Var1->_translator;
  p_Var1 = __getptd();
  p_Var1->_unexpected = param_1;
  p_Var1 = __getptd();
  p_Var1->_translator = param_3;
  local_8 = (undefined *)0x1;
  local_24 = _CallCatchBlock2(param_2,param_4,in_ECX,(int)param_5,param_6);
  local_8 = (undefined *)0xffffffff;
  FUN_008070ec();
  return local_24;
}


// ==== FUN_00807071 @ 0x00807071 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00807071(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int unaff_EBP;
  
  iVar2 = *(int *)(unaff_EBP + -0x18);
  iVar3 = *(int *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(iVar3 + 8);
  iVar4 = *(int *)(unaff_EBP + 0xc);
  iVar7 = *(int *)(iVar4 + 8);
  *(int *)(unaff_EBP + -0x28) = iVar7;
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar3 + 0x10);
  uVar8 = 0;
  do {
    *(uint *)(unaff_EBP + -0x34) = uVar8;
    if (*(uint *)(iVar3 + 0xc) <= uVar8) {
LAB_008070ba:
      *(int *)(iVar2 + -4) = iVar7;
      *(int *)(iVar2 + -8) = iVar3;
      *(undefined4 *)(iVar2 + -0xc) = 0;
      *(int *)(iVar2 + -0x10) = iVar4;
      *(undefined4 *)(iVar2 + -0x14) = 0x8070c5;
      ___FrameUnwindToState();
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(iVar2 + -4) = 0x8070da;
      FUN_008070ec();
      uVar6 = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(iVar2 + -4) = 0x8070e2;
      return uVar6;
    }
    iVar1 = *(int *)(unaff_EBP + -0x2c) + uVar8 * 0x14;
    iVar5 = *(int *)(iVar1 + 4);
    if ((iVar5 < iVar7) && (iVar7 <= *(int *)(iVar1 + 8))) {
      iVar5 = iVar5 + 1;
      *(int *)(unaff_EBP + -0x28) = iVar5;
      iVar7 = *(int *)(*(int *)(unaff_EBP + -0x30) + iVar5 * 8);
      *(int *)(unaff_EBP + -0x28) = iVar7;
      goto LAB_008070ba;
    }
    uVar8 = uVar8 + 1;
  } while( true );
}


// ==== FUN_008070ec @ 0x008070ec ====

void FUN_008070ec(void)

{
  _ptiddata p_Var1;
  int iVar2;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + -4) = *(undefined4 *)(unaff_EBP + -0x38);
  _FindAndUnlinkFrame(*(FrameInfo **)(unaff_EBP + -0x3c));
  p_Var1 = __getptd();
  p_Var1->_unexpected = *(void **)(unaff_EBP + -0x40);
  p_Var1 = __getptd();
  p_Var1->_translator = *(void **)(unaff_EBP + -0x44);
  if ((((*unaff_ESI == -0x1f928c9d) && (unaff_ESI[4] == 3)) &&
      ((unaff_ESI[5] == 0x19930520 || (unaff_ESI[5] == 0x19930521)))) &&
     ((*(int *)(unaff_EBP + -0x48) == 0 && (*(int *)(unaff_EBP + -0x20) != 0)))) {
    iVar2 = IsExceptionObjectToBeDestroyed((void *)unaff_ESI[6]);
    if (iVar2 != 0) {
      __abnormal_termination();
      ___DestructExceptionObject();
    }
  }
  return;
}


// ==== BuildCatchObject @ 0x0080715b ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __cdecl BuildCatchObject(struct EHExceptionRecord *,void *,struct _s_HandlerType const
   *,struct _s_CatchableType const *)
   
   Library: Visual Studio 2003 Release */

void __cdecl
BuildCatchObject(EHExceptionRecord *param_1,void *param_2,_s_HandlerType *param_3,
                _s_CatchableType *param_4)

{
  int iVar1;
  void *pvVar2;
  void *_Src;
  byte *in_ECX;
  int *in_EDX;
  PMD *unaff_ESI;
  PMD *unaff_EDI;
  
  if (*(int *)((int)param_2 + 4) == 0) {
    return;
  }
  if (*(char *)(*(int *)((int)param_2 + 4) + 8) == '\0') {
    return;
  }
  if ((*(int *)((int)param_2 + 8) == 0) && ((*(byte *)((int)param_2 + 3) & 0x80) == 0)) {
    return;
  }
  if (-1 < (int)*(uint *)param_2) {
    in_EDX = (int *)(*(int *)((int)param_2 + 8) + 0xc + (int)in_EDX);
  }
  pvVar2 = *(void **)(param_1 + 0x18);
  if ((*(uint *)param_2 & 8) == 0) {
    if ((*in_ECX & 1) == 0) {
      if (*(int *)(in_ECX + 0x18) == 0) {
        iVar1 = _ValidateRead(pvVar2,1);
        if ((iVar1 != 0) && (iVar1 = _ValidateWrite(in_EDX,1), iVar1 != 0)) {
          pvVar2 = *(void **)(in_ECX + 0x14);
          _Src = AdjustPointer(pvVar2,unaff_EDI);
          _memmove(in_EDX,_Src,(size_t)pvVar2);
          return;
        }
      }
      else {
        iVar1 = _ValidateRead(pvVar2,1);
        if (((iVar1 != 0) && (iVar1 = _ValidateWrite(in_EDX,1), iVar1 != 0)) &&
           (iVar1 = _ValidateExecute(*(_func_int **)(in_ECX + 0x18)), iVar1 != 0)) {
          if ((*in_ECX & 4) == 0) {
            pvVar2 = AdjustPointer(unaff_EDI,unaff_ESI);
            FID_conflict__CallMemberFunction1
                      (in_EDX,*(void **)(in_ECX + 0x18),pvVar2,(int)unaff_EDI);
            return;
          }
          iVar1 = 1;
          pvVar2 = AdjustPointer((void *)0x1,unaff_EDI);
          FID_conflict__CallMemberFunction1(in_EDX,*(void **)(in_ECX + 0x18),pvVar2,iVar1);
          return;
        }
      }
    }
    else {
      iVar1 = _ValidateRead(pvVar2,1);
      if ((iVar1 != 0) && (iVar1 = _ValidateWrite(in_EDX,1), iVar1 != 0)) {
        _memmove(in_EDX,*(void **)(param_1 + 0x18),*(size_t *)(in_ECX + 0x14));
        if (*(int *)(in_ECX + 0x14) != 4) {
          return;
        }
        if (*in_EDX == 0) {
          return;
        }
        goto LAB_008071d4;
      }
    }
  }
  else {
    iVar1 = _ValidateRead(pvVar2,1);
    if ((iVar1 != 0) && (iVar1 = _ValidateWrite(in_EDX,1), iVar1 != 0)) {
      *in_EDX = *(int *)(param_1 + 0x18);
LAB_008071d4:
      pvVar2 = AdjustPointer(unaff_EDI,unaff_ESI);
      *in_EDX = (int)pvVar2;
      return;
    }
  }
  _inconsistency();
  return;
}


// ==== FUN_008072cb @ 0x008072cb ====

undefined4 FUN_008072cb(void)

{
  return 1;
}


// ==== FUN_008072cf @ 0x008072cf ====

void FUN_008072cf(void)

{
                    /* WARNING: Subroutine does not return */
  terminate();
}


// ==== CatchIt @ 0x008072d7 ====

/* Library Function - Single Match
    void __cdecl CatchIt(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,struct _s_HandlerType const *,struct _s_CatchableType const
   *,struct _s_TryBlockMapEntry const *,int,struct EHRegistrationNode *,unsigned char)
   
   Library: Visual Studio 2003 Release */

void __cdecl
CatchIt(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
       _s_FuncInfo *param_5,_s_HandlerType *param_6,_s_CatchableType *param_7,
       _s_TryBlockMapEntry *param_8,int param_9,EHRegistrationNode *param_10,uchar param_11)

{
  void *pvVar1;
  int in_ECX;
  void *unaff_EBX;
  _s_HandlerType *unaff_EBP;
  _s_HandlerType *unaff_ESI;
  int unaff_EDI;
  _s_CatchableType *unaff_retaddr;
  _s_HandlerType *p_Var2;
  
  if (in_ECX != 0) {
    BuildCatchObject(param_1,unaff_EBX,unaff_EBP,unaff_retaddr);
  }
  if (param_6 == (_s_HandlerType *)0x0) {
    param_6 = unaff_ESI;
  }
  else {
  }
  _UnwindNestedFrames((EHRegistrationNode *)param_6,param_1);
  p_Var2 = unaff_ESI;
  ___FrameUnwindToState();
  unaff_ESI->dispCatchObj = *(int *)(unaff_EDI + 4) + 1;
  pvVar1 = CallCatchBlock(param_1,(EHRegistrationNode *)unaff_ESI,(_CONTEXT *)param_2,param_4,
                          param_5,0x100,(ulong)p_Var2);
  if (pvVar1 != (void *)0x0) {
    _JumpToContinuation(pvVar1,(EHRegistrationNode *)unaff_ESI);
  }
  return;
}


// ==== FindHandlerForForeignException @ 0x0080733e ====

/* Library Function - Single Match
    void __cdecl FindHandlerForForeignException(struct EHExceptionRecord *,struct EHRegistrationNode
   *,struct _CONTEXT *,void *,struct _s_FuncInfo const *,int,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 2003 Release */

void __cdecl
FindHandlerForForeignException
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
          _s_FuncInfo *param_5,int param_6,int param_7,EHRegistrationNode *param_8)

{
  TypeDescriptor *pTVar1;
  _ptiddata p_Var2;
  int iVar3;
  _s_TryBlockMapEntry *p_Var4;
  EHRegistrationNode *in_ECX;
  _s_CatchableType *unaff_EBX;
  int unaff_ESI;
  _s_TryBlockMapEntry *unaff_EDI;
  EHRegistrationNode *pEVar5;
  
  if (*(int *)param_1 != -0x7ffffffd) {
    pEVar5 = in_ECX;
    p_Var2 = __getptd();
    if (((p_Var2->_NLG_dwCode == 0) ||
        (iVar3 = _CallSETranslator(param_1,param_2,param_3,param_4,param_5,param_7,param_8),
        iVar3 == 0)) &&
       (p_Var4 = _GetRangeOfTrysToCheck
                           (param_5,param_7,param_6,(uint *)((int)register0x00000010 + -8),
                            (uint *)((int)register0x00000010 + -0xc)), in_ECX < pEVar5)) {
      do {
        if (((p_Var4->tryLow <= param_6) && (param_6 <= p_Var4->tryHigh)) &&
           ((pTVar1 = p_Var4->pHandlerArray[p_Var4->nCatches + -1].pType,
            pTVar1 == (TypeDescriptor *)0x0 || (*(char *)&pTVar1[1].pVFTable == '\0')))) {
          CatchIt(param_1,(EHRegistrationNode *)param_3,param_4,param_5,(_s_FuncInfo *)param_7,
                  (_s_HandlerType *)param_8,unaff_EBX,unaff_EDI,unaff_ESI,pEVar5,(uchar)in_ECX);
        }
        in_ECX = in_ECX + 1;
        p_Var4 = p_Var4 + 1;
      } while (in_ECX < pEVar5);
    }
  }
  return;
}


// ==== FindHandler @ 0x008073fc ====

/* Library Function - Single Match
    void __cdecl FindHandler(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,unsigned char,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 2003 Release */

void __cdecl
FindHandler(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
           _s_FuncInfo *param_5,uchar param_6,int param_7,EHRegistrationNode *param_8)

{
  int iVar1;
  _ptiddata p_Var2;
  int iVar3;
  _s_TryBlockMapEntry *p_Var4;
  int iVar5;
  int unaff_EBX;
  _s_TryBlockMapEntry *unaff_ESI;
  _s_CatchableType *unaff_EDI;
  EHRegistrationNode *pEVar6;
  uint in_stack_ffffffdc;
  uint local_20 [2];
  int local_18;
  int *local_14;
  uint local_10;
  _s_TryBlockMapEntry *local_c;
  undefined1 local_5;
  
  iVar1 = *(int *)(param_2 + 8);
  local_5 = 0;
  if ((iVar1 < -1) || (param_5->maxState <= iVar1)) {
    _inconsistency();
  }
  if (*(int *)param_1 == -0x1f928c9d) {
    if ((*(int *)(param_1 + 0x10) == 3) &&
       (((*(int *)(param_1 + 0x14) == 0x19930520 || (*(int *)(param_1 + 0x14) == 0x19930521)) &&
        (*(int *)(param_1 + 0x1c) == 0)))) {
      p_Var2 = __getptd();
      if (p_Var2->_unexpected == (void *)0x0) {
        return;
      }
      p_Var2 = __getptd();
      param_1 = p_Var2->_unexpected;
      p_Var2 = __getptd();
      param_3 = p_Var2->_translator;
      local_5 = 1;
      iVar3 = _ValidateRead(param_1,1);
      if (iVar3 == 0) {
        _inconsistency();
      }
      if (*(int *)param_1 != -0x1f928c9d) goto LAB_008075d5;
      if (((*(int *)(param_1 + 0x10) == 3) &&
          ((*(int *)(param_1 + 0x14) == 0x19930520 || (*(int *)(param_1 + 0x14) == 0x19930521)))) &&
         (*(int *)(param_1 + 0x1c) == 0)) {
        _inconsistency();
      }
    }
    if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
       ((*(int *)(param_1 + 0x14) == 0x19930520 || (*(int *)(param_1 + 0x14) == 0x19930521)))) {
      p_Var4 = _GetRangeOfTrysToCheck(param_5,param_7,iVar1,&local_10,local_20 + -1);
      do {
        local_c = p_Var4;
        if (in_stack_ffffffdc <= local_10) {
          if (param_6 == '\0') {
            return;
          }
          ___DestructExceptionObject(param_1,1);
          return;
        }
        if ((p_Var4->tryLow <= iVar1) && (iVar1 <= p_Var4->tryHigh)) {
          for (iVar3 = p_Var4->nCatches; 0 < iVar3; iVar3 = iVar3 + -1) {
            local_14 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc);
            local_18 = *local_14;
            if (0 < local_18) {
              do {
                local_14 = local_14 + 1;
                pEVar6 = (EHRegistrationNode *)*local_14;
                iVar5 = TypeMatch(*(_s_HandlerType **)(param_1 + 0x1c),unaff_EDI,
                                  (_s_ThrowInfo *)unaff_ESI);
                p_Var4 = local_c;
                if (iVar5 != 0) {
                  CatchIt(param_1,(EHRegistrationNode *)param_3,param_4,param_5,
                          (_s_FuncInfo *)param_7,(_s_HandlerType *)param_8,unaff_EDI,unaff_ESI,
                          unaff_EBX,pEVar6,(uchar)in_stack_ffffffdc);
                  goto LAB_008075a8;
                }
                local_18 = local_18 + -1;
              } while (0 < local_18);
            }
          }
        }
LAB_008075a8:
        local_10 = local_10 + 1;
        p_Var4 = p_Var4 + 1;
      } while( true );
    }
  }
LAB_008075d5:
  if (param_6 != '\0') {
                    /* WARNING: Subroutine does not return */
    terminate();
  }
  FindHandlerForForeignException(param_1,param_2,param_3,param_4,param_5,iVar1,param_7,param_8);
  return;
}


// ==== ___InternalCxxFrameHandler @ 0x00807600 ====

/* Library Function - Single Match
    ___InternalCxxFrameHandler
   
   Library: Visual Studio 2003 Release */

undefined4
___InternalCxxFrameHandler
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
          _s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7,uchar param_8)

{
  undefined4 uVar1;
  
  if ((param_5->magicNumber_and_bbtFlags & 0x1fffffff) != 0x19930520) {
    _inconsistency();
  }
  if (((byte)param_1[4] & 0x66) == 0) {
    if (param_5->nTryBlocks != 0) {
      if (((*(int *)param_1 == -0x1f928c9d) && (0x19930520 < *(uint *)(param_1 + 0x14))) &&
         (*(code **)(*(int *)(param_1 + 0x1c) + 8) != (code *)0x0)) {
        uVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 8))
                          (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar1;
      }
      FindHandler(param_1,param_2,param_3,param_4,param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5->maxState != 0) && (param_6 == 0)) {
    ___FrameUnwindToState(param_2,param_4,param_5,0xffffffff);
  }
  return 1;
}


// ==== FUN_008076a2 @ 0x008076a2 ====

void FUN_008076a2(void)

{
  TlsAlloc();
  return;
}


// ==== __mtterm @ 0x008076ab ====

/* Library Function - Single Match
    __mtterm
   
   Library: Visual Studio 2003 Release */

void __cdecl __mtterm(void)

{
  if (DAT_00b49be4 != -1) {
    (*DAT_00b5c914)(DAT_00b49be4);
    DAT_00b49be4 = -1;
  }
  FUN_00806bda();
  return;
}


// ==== __getptd @ 0x008076c8 ====

/* Library Function - Single Match
    __getptd
   
   Library: Visual Studio 2003 Release */

_ptiddata __cdecl __getptd(void)

{
  DWORD dwErrCode;
  _ptiddata p_Var1;
  int iVar2;
  DWORD DVar3;
  
  dwErrCode = GetLastError();
  p_Var1 = (_ptiddata)(*DAT_00b5c90c)(DAT_00b49be4);
  if (p_Var1 == (_ptiddata)0x0) {
    p_Var1 = (_ptiddata)FUN_0080faf9(1,0x8c);
    if (p_Var1 != (_ptiddata)0x0) {
      iVar2 = (*DAT_00b5c910)(DAT_00b49be4,p_Var1);
      if (iVar2 != 0) {
        p_Var1->_initaddr = &DAT_00b49c88;
        p_Var1->_holdrand = 1;
        DVar3 = GetCurrentThreadId();
        p_Var1->_thandle = 0xffffffff;
        p_Var1->_tid = DVar3;
        goto LAB_0080772d;
      }
    }
    __amsg_exit(0x10);
  }
LAB_0080772d:
  SetLastError(dwErrCode);
  return p_Var1;
}


// ==== FUN_00807866 @ 0x00807866 ====

void FUN_00807866(void)

{
  FUN_00806c2f(0xd);
  return;
}


// ==== FUN_0080786b @ 0x0080786b ====

void FUN_0080786b(void)

{
  FUN_00806c2f(0xd);
  return;
}


// ==== FUN_00807874 @ 0x00807874 ====

void FUN_00807874(void)

{
  FUN_00806c2f(0xc);
  return;
}


// ==== FUN_00807877 @ 0x00807877 ====

void FUN_00807877(void)

{
  FUN_00806c2f(0xc);
  return;
}


// ==== __mtinit @ 0x00807880 ====

/* Library Function - Single Match
    __mtinit
   
   Library: Visual Studio 2003 Release */

int __cdecl __mtinit(void)

{
  int iVar1;
  HMODULE hModule;
  DWORD *pDVar2;
  DWORD DVar3;
  
  iVar1 = __mtinitlocks();
  if (iVar1 == 0) {
    __mtterm();
    return 0;
  }
  hModule = GetModuleHandleA(s_kernel32_dll_00a061f4);
  if (hModule != (HMODULE)0x0) {
    DAT_00b5c908 = GetProcAddress(hModule,s_FlsAlloc_00a061e8);
    DAT_00b5c90c = GetProcAddress(hModule,s_FlsGetValue_00a061dc);
    DAT_00b5c910 = GetProcAddress(hModule,s_FlsSetValue_00a061d0);
    DAT_00b5c914 = GetProcAddress(hModule,s_FlsFree_00a061c8);
    if (DAT_00b5c90c == (FARPROC)0x0) {
      DAT_00b5c90c = TlsGetValue_exref;
      DAT_00b5c910 = TlsSetValue_exref;
      DAT_00b5c908 = FUN_008076a2;
      DAT_00b5c914 = TlsFree_exref;
    }
  }
  DAT_00b49be4 = (*DAT_00b5c908)(&LAB_00807739);
  if (((DAT_00b49be4 == -1) || (pDVar2 = (DWORD *)FUN_0080faf9(1,0x8c), pDVar2 == (DWORD *)0x0)) ||
     (iVar1 = (*DAT_00b5c910)(DAT_00b49be4,pDVar2), iVar1 == 0)) {
    __mtterm();
    return 0;
  }
  pDVar2[0x15] = (DWORD)&DAT_00b49c88;
  pDVar2[5] = 1;
  DVar3 = GetCurrentThreadId();
  pDVar2[1] = 0xffffffff;
  *pDVar2 = DVar3;
  return 1;
}


// ==== terminate @ 0x0080796f ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* Library Function - Single Match
    void __cdecl terminate(void)
   
   Library: Visual Studio 2003 Release */

void __cdecl terminate(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (p_Var1->ptlocinfo != (pthreadlocinfo)0x0) {
    p_Var1 = __getptd();
    (*(code *)p_Var1->ptlocinfo)();
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}


// ==== FUN_00807998 @ 0x00807998 ====

void FUN_00807998(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}


// ==== _inconsistency @ 0x008079a4 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* Library Function - Single Match
    void __cdecl _inconsistency(void)
   
   Library: Visual Studio 2003 Release */

void __cdecl _inconsistency(void)

{
  if (PTR_terminate_00b49be8 == (undefined *)0x0) {
                    /* WARNING: Subroutine does not return */
    terminate();
  }
  (*(code *)PTR_terminate_00b49be8)();
  return;
}


// ==== FUN_008079c5 @ 0x008079c5 ====

void FUN_008079c5(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  terminate();
}


// ==== __CallSettingFrame@12 @ 0x008079e0 ====

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Library: Visual Studio 2003 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}


// ==== FUN_00807a2c @ 0x00807a2c ====

int FUN_00807a2c(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) &&
     ((piVar1[5] == 0x19930520 || (piVar1[5] == 0x19930521)))) {
                    /* WARNING: Subroutine does not return */
    terminate();
  }
  if ((DAT_00b5c918 == (_func_int *)0x0) || (iVar2 = _ValidateExecute(DAT_00b5c918), iVar2 == 0)) {
    return 0;
  }
  iVar2 = (*DAT_00b5c918)(param_1);
  return iVar2;
}


// ==== FUN_00807a7a @ 0x00807a7a ====

undefined4 FUN_00807a7a(void)

{
  DAT_00b5c918 = SetUnhandledExceptionFilter(FUN_00807a2c);
  return 0;
}


// ==== FUN_00807a8d @ 0x00807a8d ====

void FUN_00807a8d(void)

{
  SetUnhandledExceptionFilter(DAT_00b5c918);
  return;
}


// ==== FUN_00807a9a @ 0x00807a9a ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_00807a9a(int param_1)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  size_t sVar4;
  size_t sVar5;
  HANDLE hFile;
  int iVar6;
  char *_Str;
  undefined4 uStackY_150;
  undefined4 uStackY_14c;
  UINT aUStackY_148 [2];
  undefined1 auStackY_140 [4];
  undefined4 uStackY_13c;
  undefined4 uStackY_138;
  LPCVOID lpBuffer;
  LPDWORD lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  undefined4 local_114;
  CHAR local_110 [124];
  undefined1 local_94 [136];
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_00b49670 ^ (uint)local_94;
  uVar2 = 0;
  do {
    if (param_1 == (&DAT_00b49bf0)[uVar2 * 2]) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x13);
  iVar6 = uVar2 * 8;
  if (param_1 == (&DAT_00b49bf0)[uVar2 * 2]) {
    if ((DAT_00b5c624 == 1) || ((DAT_00b5c624 == 0 && (DAT_00b49330 == 1)))) {
      lpOverlapped = (LPOVERLAPPED)0x0;
      lpNumberOfBytesWritten = &local_114;
      sVar4 = _strlen(*(char **)(iVar6 + 0xb49bf4));
      lpBuffer = *(LPCVOID *)(iVar6 + 0xb49bf4);
      uStackY_138 = 0x807bed;
      hFile = GetStdHandle(0xfffffff4);
      uStackY_138 = 0x807bf4;
      WriteFile(hFile,lpBuffer,sVar4,lpNumberOfBytesWritten,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      local_c = 0;
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_110,0x104);
      if (DVar3 == 0) {
        FUN_00809180();
      }
      _Str = local_110;
      sVar4 = _strlen(_Str);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen(_Str);
        _Str = (char *)((int)aUStackY_148 + (sVar4 - 3));
        _strncpy(_Str,(char *)&DAT_009fe62c,3);
      }
      sVar4 = _strlen(_Str);
      sVar5 = _strlen(*(char **)(iVar6 + 0xb49bf4));
      iVar1 = -(sVar4 + sVar5 + 0x1f & 0xfffffffc);
      *(char **)(local_110 + iVar1 + -0x14) = s_Runtime_Error__Program__00a065f4;
      *(CHAR **)(auStackY_140 + iVar1 + 0x18) = local_110 + iVar1 + -0x10;
      *(undefined4 *)(auStackY_140 + iVar1 + 0x14) = 0x807b9c;
      FUN_00809180();
      *(char **)(auStackY_140 + iVar1 + 0x14) = _Str;
      *(CHAR **)(auStackY_140 + iVar1 + 0x10) = local_110 + iVar1 + -0x10;
      *(undefined4 *)(auStackY_140 + iVar1 + 0xc) = 0x807ba3;
      FUN_00809190();
      *(undefined **)(auStackY_140 + iVar1 + 0xc) = &DAT_00a065f0;
      *(CHAR **)(auStackY_140 + iVar1 + 8) = local_110 + iVar1 + -0x10;
      *(undefined4 *)(auStackY_140 + iVar1 + 4) = 0x807bae;
      FUN_00809190();
      *(undefined4 *)(auStackY_140 + iVar1 + 4) = *(undefined4 *)(iVar6 + 0xb49bf4);
      *(CHAR **)(auStackY_140 + iVar1) = local_110 + iVar1 + -0x10;
      *(undefined4 *)((int)aUStackY_148 + iVar1 + 4) = 0x807bba;
      FUN_00809190();
      *(undefined4 *)((int)aUStackY_148 + iVar1 + 4) = 0x12010;
      *(char **)((int)aUStackY_148 + iVar1) = s_Microsoft_Visual_C___Runtime_Lib_00a065c8;
      *(CHAR **)((int)aUStackY_148 + iVar1 + -4) = local_110 + iVar1 + -0x10;
      *(undefined4 *)((int)aUStackY_148 + iVar1 + -8) = 0x807bca;
      ___crtMessageBoxA(*(LPCSTR *)((int)aUStackY_148 + iVar1 + -4),
                        *(LPCSTR *)((int)aUStackY_148 + iVar1),
                        *(UINT *)((int)aUStackY_148 + iVar1 + 4));
    }
  }
  return;
}


// ==== __FF_MSGBANNER @ 0x00807c12 ====

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 2003 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_00b5c624 == 1) || ((DAT_00b5c624 == 0 && (DAT_00b49330 == 1)))) {
    FUN_00807a9a(0xfc);
    if (DAT_00b5c91c != (code *)0x0) {
      (*DAT_00b5c91c)();
    }
    FUN_00807a9a(0xff);
  }
  return;
}


// ==== __XcptFilter @ 0x00807c4b ====

/* Library Function - Single Match
    __XcptFilter
   
   Library: Visual Studio 2003 Release */

int __cdecl __XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  ulong *puVar1;
  code *pcVar2;
  void *pvVar3;
  ulong uVar4;
  void *pvVar5;
  _ptiddata p_Var6;
  int iVar7;
  int iVar8;
  ulong *puVar9;
  
  p_Var6 = __getptd();
  puVar1 = p_Var6->_initaddr;
  puVar9 = puVar1;
  do {
    if (*puVar9 == _ExceptionNum) break;
    puVar9 = puVar9 + 3;
  } while (puVar9 < puVar1 + DAT_00b49d0c * 3);
  if ((puVar1 + DAT_00b49d0c * 3 <= puVar9) || (*puVar9 != _ExceptionNum)) {
    puVar9 = (ulong *)0x0;
  }
  if ((puVar9 == (ulong *)0x0) || (pcVar2 = (code *)puVar9[2], pcVar2 == (code *)0x0)) {
    iVar7 = UnhandledExceptionFilter(_ExceptionPtr);
  }
  else if (pcVar2 == (code *)0x5) {
    puVar9[2] = 0;
    iVar7 = 1;
  }
  else {
    if (pcVar2 != (code *)0x1) {
      pvVar3 = p_Var6->_initarg;
      p_Var6->_initarg = _ExceptionPtr;
      if (puVar9[1] == 8) {
        if (DAT_00b49d00 < DAT_00b49d04 + DAT_00b49d00) {
          iVar8 = DAT_00b49d00 * 0xc;
          iVar7 = DAT_00b49d00;
          do {
            *(undefined4 *)(iVar8 + 8 + (int)p_Var6->_initaddr) = 0;
            iVar7 = iVar7 + 1;
            iVar8 = iVar8 + 0xc;
          } while (iVar7 < DAT_00b49d04 + DAT_00b49d00);
        }
        uVar4 = *puVar9;
        pvVar5 = p_Var6->_pxcptacttab;
        if (uVar4 == 0xc000008e) {
          p_Var6->_pxcptacttab = (void *)0x83;
        }
        else if (uVar4 == 0xc0000090) {
          p_Var6->_pxcptacttab = (void *)0x81;
        }
        else if (uVar4 == 0xc0000091) {
          p_Var6->_pxcptacttab = (void *)0x84;
        }
        else if (uVar4 == 0xc0000093) {
          p_Var6->_pxcptacttab = (void *)0x85;
        }
        else if (uVar4 == 0xc000008d) {
          p_Var6->_pxcptacttab = (void *)0x82;
        }
        else if (uVar4 == 0xc000008f) {
          p_Var6->_pxcptacttab = (void *)0x86;
        }
        else if (uVar4 == 0xc0000092) {
          p_Var6->_pxcptacttab = (void *)0x8a;
        }
        (*pcVar2)(8,p_Var6->_pxcptacttab);
        p_Var6->_pxcptacttab = pvVar5;
      }
      else {
        puVar9[2] = 0;
        (*pcVar2)(puVar9[1]);
      }
      p_Var6->_initarg = pvVar3;
    }
    iVar7 = -1;
  }
  return iVar7;
}


// ==== __wincmdln @ 0x00807daf ====

/* Library Function - Single Match
    __wincmdln
   
   Library: Visual Studio 2003 Release */

byte * __wincmdln(void)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  byte *pbVar4;
  
  bVar2 = false;
  if (DAT_00b610ac == 0) {
    ___initmbctable();
  }
  pbVar4 = DAT_00b620c4;
  if (DAT_00b620c4 == (byte *)0x0) {
    pbVar4 = &DAT_0099cf70;
  }
  do {
    bVar1 = *pbVar4;
    if (bVar1 < 0x21) {
      if (bVar1 == 0) {
        return pbVar4;
      }
      if (!bVar2) {
        for (; (*pbVar4 != 0 && (*pbVar4 < 0x21)); pbVar4 = pbVar4 + 1) {
        }
        return pbVar4;
      }
    }
    if (bVar1 == 0x22) {
      bVar2 = !bVar2;
    }
    iVar3 = __ismbblead((uint)bVar1);
    if (iVar3 != 0) {
      pbVar4 = pbVar4 + 1;
    }
    pbVar4 = pbVar4 + 1;
  } while( true );
}


// ==== FUN_00807e0c @ 0x00807e0c ====

undefined4 FUN_00807e0c(void)

{
  undefined4 *puVar1;
  size_t sVar2;
  void *pvVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  char *pcVar4;
  int iVar5;
  
  if (DAT_00b610ac == 0) {
    ___initmbctable();
  }
  iVar5 = 0;
  pcVar4 = DAT_00b5c61c;
  if (DAT_00b5c61c != (char *)0x0) {
    for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + sVar2 + 1) {
      if (*pcVar4 != '=') {
        iVar5 = iVar5 + 1;
      }
      sVar2 = _strlen(pcVar4);
    }
    puVar1 = _malloc(iVar5 * 4 + 4);
    DAT_00b5c740 = puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      pcVar4 = DAT_00b5c61c;
      do {
        if (*pcVar4 == '\0') {
          _free(DAT_00b5c61c);
          return extraout_EAX;
        }
        sVar2 = _strlen(pcVar4);
        if (*pcVar4 != '=') {
          pvVar3 = _malloc(sVar2 + 1);
          *puVar1 = pvVar3;
          if (pvVar3 == (void *)0x0) {
            _free(DAT_00b5c740);
            return extraout_EAX_00;
          }
          FUN_00809180(pvVar3,pcVar4);
          puVar1 = puVar1 + 1;
        }
        pcVar4 = pcVar4 + sVar2 + 1;
      } while( true );
    }
  }
  return 0xffffffff;
}


// ==== parse_cmdline @ 0x00807ed3 ====

/* Library Function - Single Match
    _parse_cmdline
   
   Library: Visual Studio 2003 Release */

void __cdecl parse_cmdline(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  bool bVar2;
  byte *in_EAX;
  byte *pbVar3;
  byte bVar4;
  byte *in_ECX;
  uint uVar5;
  int *unaff_ESI;
  
  bVar1 = false;
  *unaff_ESI = 0;
  *param_2 = 1;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = in_ECX;
    param_1 = param_1 + 1;
  }
  do {
    if (*in_EAX == 0x22) {
      bVar1 = !bVar1;
      pbVar3 = in_EAX + 1;
      bVar4 = 0x22;
    }
    else {
      *unaff_ESI = *unaff_ESI + 1;
      if (in_ECX != (byte *)0x0) {
        *in_ECX = *in_EAX;
        in_ECX = in_ECX + 1;
      }
      bVar4 = *in_EAX;
      pbVar3 = in_EAX + 1;
      if ((*(byte *)((int)&DAT_00b60d20 + bVar4 + 1) & 4) != 0) {
        *unaff_ESI = *unaff_ESI + 1;
        if (in_ECX != (byte *)0x0) {
          *in_ECX = *pbVar3;
          in_ECX = in_ECX + 1;
        }
        pbVar3 = in_EAX + 2;
      }
      if (bVar4 == 0) {
        pbVar3 = pbVar3 + -1;
        goto LAB_00807f4c;
      }
    }
    in_EAX = pbVar3;
  } while ((bVar1) || ((bVar4 != 0x20 && (bVar4 != 9))));
  if (in_ECX != (byte *)0x0) {
    in_ECX[-1] = 0;
  }
LAB_00807f4c:
  bVar1 = false;
  while (*pbVar3 != 0) {
    for (; (*pbVar3 == 0x20 || (*pbVar3 == 9)); pbVar3 = pbVar3 + 1) {
    }
    if (*pbVar3 == 0) break;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = in_ECX;
      param_1 = param_1 + 1;
    }
    *param_2 = *param_2 + 1;
    while( true ) {
      bVar2 = true;
      uVar5 = 0;
      for (; *pbVar3 == 0x5c; pbVar3 = pbVar3 + 1) {
        uVar5 = uVar5 + 1;
      }
      if (*pbVar3 == 0x22) {
        if ((uVar5 & 1) == 0) {
          if ((bVar1) && (pbVar3[1] == 0x22)) {
            pbVar3 = pbVar3 + 1;
          }
          else {
            bVar2 = false;
          }
          bVar1 = !bVar1;
        }
        uVar5 = uVar5 >> 1;
      }
      for (; uVar5 != 0; uVar5 = uVar5 - 1) {
        if (in_ECX != (byte *)0x0) {
          *in_ECX = 0x5c;
          in_ECX = in_ECX + 1;
        }
        *unaff_ESI = *unaff_ESI + 1;
      }
      bVar4 = *pbVar3;
      if ((bVar4 == 0) || ((!bVar1 && ((bVar4 == 0x20 || (bVar4 == 9)))))) break;
      if (bVar2) {
        if (in_ECX == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_00b60d20 + bVar4 + 1) & 4) != 0) {
            pbVar3 = pbVar3 + 1;
            *unaff_ESI = *unaff_ESI + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_00b60d20 + bVar4 + 1) & 4) != 0) {
            *in_ECX = bVar4;
            in_ECX = in_ECX + 1;
            pbVar3 = pbVar3 + 1;
            *unaff_ESI = *unaff_ESI + 1;
          }
          *in_ECX = *pbVar3;
          in_ECX = in_ECX + 1;
        }
        *unaff_ESI = *unaff_ESI + 1;
      }
      pbVar3 = pbVar3 + 1;
    }
    if (in_ECX != (byte *)0x0) {
      *in_ECX = 0;
      in_ECX = in_ECX + 1;
    }
    *unaff_ESI = *unaff_ESI + 1;
  }
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
  }
  *param_2 = *param_2 + 1;
  return;
}


// ==== __setargv @ 0x0080803f ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 2003 Release */

int __cdecl __setargv(void)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  int local_8;
  
  local_8 = in_ECX;
  if (DAT_00b610ac == 0) {
    ___initmbctable();
  }
  DAT_00b5ca24 = 0;
  GetModuleFileNameA((HMODULE)0x0,s_C__Program_Files_Acclaim_2Moons__00b5c920,0x104);
  PTR_s_C__Program_Files_Acclaim_2Moons__00b5c750 = s_C__Program_Files_Acclaim_2Moons__00b5c920;
  parse_cmdline(0,&local_8);
  pvVar1 = _malloc(in_ECX + local_8 * 4);
  if (pvVar1 == (void *)0x0) {
    iVar2 = -1;
  }
  else {
    parse_cmdline(pvVar1,&local_8);
    _DAT_00b5c734 = local_8 + -1;
    iVar2 = 0;
    _DAT_00b5c738 = pvVar1;
  }
  return iVar2;
}


// ==== FUN_008080e1 @ 0x008080e1 ====

LPSTR FUN_008080e1(void)

{
  char cVar1;
  WCHAR WVar2;
  DWORD DVar3;
  WCHAR *pWVar5;
  WCHAR *pWVar4;
  int iVar6;
  size_t _Size;
  LPSTR lpMultiByteStr;
  LPSTR extraout_EAX;
  LPCH _Src;
  char *pcVar8;
  char *pcVar7;
  LPSTR pCVar9;
  LPWCH lpWideCharStr;
  
  lpWideCharStr = (LPWCH)0x0;
  if (DAT_00b5ca28 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_00b5ca28 = 1;
      goto LAB_0080812f;
    }
    DVar3 = GetLastError();
    if (DVar3 == 0x78) {
      DAT_00b5ca28 = 2;
    }
  }
  if (DAT_00b5ca28 != 1) {
    if ((DAT_00b5ca28 != 2) && (DAT_00b5ca28 != 0)) {
      return (LPSTR)0x0;
    }
    _Src = GetEnvironmentStrings();
    if (_Src == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    cVar1 = *_Src;
    pcVar7 = _Src;
    while (cVar1 != '\0') {
      do {
        pcVar8 = pcVar7;
        pcVar7 = pcVar8 + 1;
      } while (*pcVar7 != '\0');
      pcVar7 = pcVar8 + 2;
      cVar1 = *pcVar7;
    }
    pCVar9 = _malloc((size_t)(pcVar7 + (1 - (int)_Src)));
    if (pCVar9 == (LPSTR)0x0) {
      pCVar9 = (LPSTR)0x0;
    }
    else {
      _memcpy(pCVar9,_Src,(size_t)(pcVar7 + (1 - (int)_Src)));
    }
    FreeEnvironmentStringsA(_Src);
    return pCVar9;
  }
LAB_0080812f:
  if ((lpWideCharStr == (LPWCH)0x0) &&
     (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
    return (LPSTR)0x0;
  }
  WVar2 = *lpWideCharStr;
  pWVar4 = lpWideCharStr;
  while (WVar2 != L'\0') {
    do {
      pWVar5 = pWVar4;
      pWVar4 = pWVar5 + 1;
    } while (*pWVar4 != L'\0');
    pWVar4 = pWVar5 + 2;
    WVar2 = *pWVar4;
  }
  iVar6 = ((int)pWVar4 - (int)lpWideCharStr >> 1) + 1;
  _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar6,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  pCVar9 = (LPSTR)0x0;
  if ((_Size != 0) && (lpMultiByteStr = _malloc(_Size), lpMultiByteStr != (LPSTR)0x0)) {
    iVar6 = WideCharToMultiByte(0,0,lpWideCharStr,iVar6,lpMultiByteStr,_Size,(LPCSTR)0x0,(LPBOOL)0x0
                               );
    if (iVar6 == 0) {
      _free(lpMultiByteStr);
      return extraout_EAX;
    }
    pCVar9 = lpMultiByteStr;
  }
  FreeEnvironmentStringsW(lpWideCharStr);
  return pCVar9;
}


// ==== __ioinit @ 0x00808203 ====

/* Library Function - Single Match
    __ioinit
   
   Library: Visual Studio 2003 Release */

int __cdecl __ioinit(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  DWORD DVar6;
  HANDLE hFile;
  int iVar7;
  uint uVar8;
  UINT *pUVar9;
  UINT UVar10;
  byte *local_48;
  _STARTUPINFOA local_44;
  
  puVar3 = _malloc(0x480);
  if (puVar3 == (undefined4 *)0x0) {
    iVar4 = -1;
  }
  else {
    DAT_00b60f80 = 0x20;
    DAT_00b60fa0 = puVar3;
    for (; puVar3 < DAT_00b60fa0 + 0x120; puVar3 = puVar3 + 9) {
      *puVar3 = 0xffffffff;
      puVar3[2] = 0;
      *(undefined1 *)(puVar3 + 1) = 0;
      *(undefined1 *)((int)puVar3 + 5) = 10;
    }
    GetStartupInfoA(&local_44);
    if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
      UVar10 = *(UINT *)local_44.lpReserved2;
      pUVar9 = (UINT *)((int)local_44.lpReserved2 + 4);
      local_48 = (byte *)(UVar10 + (int)pUVar9);
      if (0x7ff < (int)UVar10) {
        UVar10 = 0x800;
      }
      if ((int)DAT_00b60f80 < (int)UVar10) {
        puVar3 = &DAT_00b60fa4;
        do {
          puVar5 = _malloc(0x480);
          if (puVar5 == (undefined4 *)0x0) {
            UVar10 = DAT_00b60f80;
            break;
          }
          DAT_00b60f80 = DAT_00b60f80 + 0x20;
          *puVar3 = puVar5;
          puVar2 = puVar5;
          for (; puVar5 < puVar2 + 0x120; puVar5 = puVar5 + 9) {
            *puVar5 = 0xffffffff;
            puVar5[2] = 0;
            *(undefined1 *)(puVar5 + 1) = 0;
            *(undefined1 *)((int)puVar5 + 5) = 10;
            puVar2 = (undefined4 *)*puVar3;
          }
          puVar3 = puVar3 + 1;
        } while ((int)DAT_00b60f80 < (int)UVar10);
      }
      uVar8 = 0;
      if (0 < (int)UVar10) {
        do {
          if (((*(HANDLE *)local_48 != (HANDLE)0xffffffff) && ((*pUVar9 & 1) != 0)) &&
             (((*pUVar9 & 8) != 0 || (DVar6 = GetFileType(*(HANDLE *)local_48), DVar6 != 0)))) {
            puVar3 = (undefined4 *)((int)(&DAT_00b60fa0)[(int)uVar8 >> 5] + (uVar8 & 0x1f) * 0x24);
            *puVar3 = *(undefined4 *)local_48;
            *(byte *)(puVar3 + 1) = (byte)*pUVar9;
            iVar4 = ___crtInitCritSecAndSpinCount(puVar3 + 3,4000);
            if (iVar4 == 0) {
              return -1;
            }
            puVar3[2] = puVar3[2] + 1;
          }
          local_48 = local_48 + 4;
          uVar8 = uVar8 + 1;
          pUVar9 = (UINT *)((int)pUVar9 + 1);
        } while ((int)uVar8 < (int)UVar10);
      }
    }
    iVar4 = 0;
    do {
      piVar1 = DAT_00b60fa0 + iVar4 * 9;
      if (*piVar1 == -1) {
        *(undefined1 *)(piVar1 + 1) = 0x81;
        if (iVar4 == 0) {
          DVar6 = 0xfffffff6;
        }
        else {
          DVar6 = 0xfffffff5 - (iVar4 != 1);
        }
        hFile = GetStdHandle(DVar6);
        if ((hFile == (HANDLE)0xffffffff) || (DVar6 = GetFileType(hFile), DVar6 == 0)) {
          *(byte *)(piVar1 + 1) = *(byte *)(piVar1 + 1) | 0x40;
        }
        else {
          *piVar1 = (int)hFile;
          if ((DVar6 & 0xff) == 2) {
            *(byte *)(piVar1 + 1) = *(byte *)(piVar1 + 1) | 0x40;
          }
          else if ((DVar6 & 0xff) == 3) {
            *(byte *)(piVar1 + 1) = *(byte *)(piVar1 + 1) | 8;
          }
          iVar7 = ___crtInitCritSecAndSpinCount(piVar1 + 3,4000);
          if (iVar7 == 0) {
            return -1;
          }
          piVar1[2] = piVar1[2] + 1;
        }
      }
      else {
        *(byte *)(piVar1 + 1) = *(byte *)(piVar1 + 1) | 0x80;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    SetHandleCount(DAT_00b60f80);
    iVar4 = 0;
  }
  return iVar4;
}


// ==== __RTC_Initialize @ 0x00808401 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __RTC_Initialize
   
   Library: Visual Studio 2003 Release */

void __RTC_Initialize(void)

{
  undefined4 *local_20;
  
  for (local_20 = &DAT_00a9c1c0; local_20 < &DAT_00a9c1c0; local_20 = local_20 + 1) {
    if ((code *)*local_20 != (code *)0x0) {
      (*(code *)*local_20)();
    }
  }
  return;
}


// ==== FUN_00808432 @ 0x00808432 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00808432(void)

{
  code *pcVar1;
  undefined4 *puVar3;
  undefined1 *puVar2;
  int unaff_EBP;
  
  puVar2 = *(undefined1 **)(unaff_EBP + -0x18);
  while( true ) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
    if (0xa9c1bf < *(uint *)(unaff_EBP + -0x1c)) break;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    pcVar1 = (code *)**(undefined4 **)(unaff_EBP + -0x1c);
    if (pcVar1 != (code *)0x0) {
      puVar3 = (undefined4 *)(puVar2 + -4);
      puVar2 = puVar2 + -4;
      *puVar3 = 0x80842c;
      (*pcVar1)();
    }
  }
  *(undefined4 *)(puVar2 + -4) = 0x808444;
  return;
}


// ==== FUN_00808476 @ 0x00808476 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00808476(void)

{
  code *pcVar1;
  undefined4 *puVar3;
  undefined1 *puVar2;
  int unaff_EBP;
  
  puVar2 = *(undefined1 **)(unaff_EBP + -0x18);
  while( true ) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
    if (0xa9c1c7 < *(uint *)(unaff_EBP + -0x1c)) break;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    pcVar1 = (code *)**(undefined4 **)(unaff_EBP + -0x1c);
    if (pcVar1 != (code *)0x0) {
      puVar3 = (undefined4 *)(puVar2 + -4);
      puVar2 = puVar2 + -4;
      *puVar3 = 0x808470;
      (*pcVar1)();
    }
  }
  *(undefined4 *)(puVar2 + -4) = 0x808488;
  return;
}


// ==== ___heap_select @ 0x00808489 ====

/* Library Function - Single Match
    ___heap_select
   
   Library: Visual Studio 2003 Release */

undefined4 ___heap_select(void)

{
  if ((DAT_00b5c720 == 2) && (4 < DAT_00b5c72c)) {
    return 1;
  }
  return 3;
}


// ==== __heap_init @ 0x008084a3 ====

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 2003 Release */

int __cdecl __heap_init(void)

{
  int iVar1;
  int in_stack_00000004;
  
  DAT_00b60f78 = HeapCreate((uint)(in_stack_00000004 == 0),0x1000,0);
  if (DAT_00b60f78 == (HANDLE)0x0) {
    return 0;
  }
  DAT_00b60f7c = ___heap_select();
  if ((DAT_00b60f7c == 3) && (iVar1 = ___sbh_heap_init(0x3f8), iVar1 == 0)) {
    HeapDestroy(DAT_00b60f78);
    return 0;
  }
  return 1;
}


// ==== __get_lc_time @ 0x008084f4 ====

/* Library Function - Single Match
    __get_lc_time
   
   Library: Visual Studio 2003 Release */

uint __get_lc_time(void)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  uint uVar46;
  int unaff_ESI;
  
  uVar1 = DAT_00b5ca9e;
  uVar46 = (uint)DAT_00b5caa0;
  if (unaff_ESI == 0) {
    return 0xffffffff;
  }
  uVar2 = FUN_00812c18(1,DAT_00b5ca9e,0x31,unaff_ESI + 4);
  uVar3 = FUN_00812c18(1,uVar1,0x32,unaff_ESI + 8);
  uVar4 = FUN_00812c18(1,uVar1,0x33,unaff_ESI + 0xc);
  uVar5 = FUN_00812c18(1,uVar1,0x34,unaff_ESI + 0x10);
  uVar6 = FUN_00812c18(1,uVar1,0x35,unaff_ESI + 0x14);
  uVar7 = FUN_00812c18(1,uVar1,0x36,unaff_ESI + 0x18);
  uVar8 = FUN_00812c18(1,uVar1,0x37);
  uVar9 = FUN_00812c18(1,uVar1,0x2a,unaff_ESI + 0x20);
  uVar10 = FUN_00812c18(1,uVar1,0x2b,unaff_ESI + 0x24);
  uVar11 = FUN_00812c18(1,uVar1,0x2c,unaff_ESI + 0x28);
  uVar12 = FUN_00812c18(1,uVar1,0x2d,unaff_ESI + 0x2c);
  uVar13 = FUN_00812c18(1,uVar1,0x2e,unaff_ESI + 0x30);
  uVar14 = FUN_00812c18(1,uVar1,0x2f,unaff_ESI + 0x34);
  uVar15 = FUN_00812c18(1,uVar1,0x30,unaff_ESI + 0x1c);
  uVar16 = FUN_00812c18(1,uVar1,0x44,unaff_ESI + 0x38);
  uVar17 = FUN_00812c18(1,uVar1,0x45,unaff_ESI + 0x3c);
  uVar18 = FUN_00812c18(1,uVar1,0x46,unaff_ESI + 0x40);
  uVar19 = FUN_00812c18(1,uVar1,0x47,unaff_ESI + 0x44);
  uVar20 = FUN_00812c18(1,uVar1,0x48,unaff_ESI + 0x48);
  uVar21 = FUN_00812c18(1,uVar1,0x49,unaff_ESI + 0x4c);
  uVar22 = FUN_00812c18(1,uVar1,0x4a,unaff_ESI + 0x50);
  uVar23 = FUN_00812c18(1,uVar1,0x4b,unaff_ESI + 0x54);
  uVar24 = FUN_00812c18(1,uVar1,0x4c,unaff_ESI + 0x58);
  uVar25 = FUN_00812c18(1,uVar1,0x4d,unaff_ESI + 0x5c);
  uVar26 = FUN_00812c18(1,uVar1,0x4e,unaff_ESI + 0x60);
  uVar27 = FUN_00812c18(1,uVar1,0x4f,unaff_ESI + 100);
  uVar28 = FUN_00812c18(1,uVar1,0x38,unaff_ESI + 0x68);
  uVar29 = FUN_00812c18(1,uVar1,0x39,unaff_ESI + 0x6c);
  uVar30 = FUN_00812c18(1,uVar1,0x3a,unaff_ESI + 0x70);
  uVar31 = FUN_00812c18(1,uVar1,0x3b,unaff_ESI + 0x74);
  uVar32 = FUN_00812c18(1,uVar1,0x3c,unaff_ESI + 0x78);
  uVar33 = FUN_00812c18(1,uVar1,0x3d,unaff_ESI + 0x7c);
  uVar34 = FUN_00812c18(1,uVar1,0x3e,unaff_ESI + 0x80);
  uVar35 = FUN_00812c18(1,uVar1,0x3f,unaff_ESI + 0x84);
  uVar36 = FUN_00812c18(1,uVar1,0x40,unaff_ESI + 0x88);
  uVar37 = FUN_00812c18(1,uVar1,0x41,unaff_ESI + 0x8c);
  uVar38 = FUN_00812c18(1,uVar1,0x42,unaff_ESI + 0x90);
  uVar39 = FUN_00812c18(1,uVar1,0x43,unaff_ESI + 0x94);
  uVar40 = FUN_00812c18(1,uVar1,0x28,unaff_ESI + 0x98);
  uVar41 = FUN_00812c18(1,uVar1,0x29,unaff_ESI + 0x9c);
  uVar42 = FUN_00812c18(1,uVar46,0x1f,unaff_ESI + 0xa0);
  uVar43 = FUN_00812c18(1,uVar46,0x20,unaff_ESI + 0xa4);
  uVar44 = FUN_00812c18(1,uVar46,0x1003,unaff_ESI + 0xa8);
  uVar45 = FUN_00812c18(0,uVar46,0x1009,unaff_ESI + 0xb0);
  *(uint *)(unaff_ESI + 0xac) = uVar46;
  return uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 | uVar12 |
         uVar13 | uVar14 | uVar15 | uVar16 | uVar17 | uVar18 | uVar19 | uVar20 | uVar21 | uVar22 |
         uVar23 | uVar24 | uVar25 | uVar26 | uVar27 | uVar28 | uVar29 | uVar30 | uVar31 | uVar32 |
         uVar33 | uVar34 | uVar35 | uVar36 | uVar37 | uVar38 | uVar39 | uVar40 | uVar41 | uVar42 |
         uVar43 | uVar44 | uVar45;
}


// ==== FUN_0080885b @ 0x0080885b ====

void FUN_0080885b(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  _free(*(void **)(param_1 + 4));
  return;
}


// ==== FUN_008089eb @ 0x008089eb ====

undefined4 FUN_008089eb(void)

{
  undefined *_Memory;
  int iVar1;
  undefined4 extraout_EAX;
  
  if (DAT_00b5ca70 == 0) {
    DAT_00b5ca30 = (undefined *)0x0;
    PTR_PTR_00b495b0 = (undefined *)&PTR_DAT_00b495b8;
  }
  else {
    _Memory = (undefined *)FUN_0080faf9(1,0xb8);
    if (_Memory == (undefined *)0x0) {
      return 1;
    }
    iVar1 = __get_lc_time();
    if (iVar1 != 0) {
      FUN_0080885b(_Memory);
      _free(_Memory);
      return extraout_EAX;
    }
    PTR_PTR_00b495b0 = _Memory;
    DAT_00b5ca30 = _Memory;
  }
  return 0;
}


// ==== FUN_00808a4a @ 0x00808a4a ====

void FUN_00808a4a(undefined4 *param_1)

{
  undefined *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined *)*param_1;
    if ((puVar1 != *(undefined **)PTR_PTR_00b49d74) && (puVar1 != PTR_DAT_00b49d44)) {
      _free(puVar1);
      return;
    }
    puVar1 = (undefined *)param_1[1];
    if ((puVar1 != *(undefined **)(PTR_PTR_00b49d74 + 4)) && (puVar1 != PTR_DAT_00b49d48)) {
      _free(puVar1);
      return;
    }
    puVar1 = (undefined *)param_1[2];
    if ((puVar1 != *(undefined **)(PTR_PTR_00b49d74 + 8)) && (puVar1 != PTR_DAT_00b49d4c)) {
      _free(puVar1);
      return;
    }
  }
  return;
}


// ==== FUN_00808aa9 @ 0x00808aa9 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00808aa9(void)

{
  char *pcVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 extraout_EAX;
  undefined4 *puVar4;
  undefined4 extraout_EAX_00;
  int iVar5;
  int iVar6;
  undefined4 extraout_EAX_01;
  char *pcVar7;
  undefined4 extraout_EAX_02;
  int iVar8;
  undefined **_Memory;
  char *pcVar9;
  undefined **ppuVar10;
  
  if ((DAT_00b5ca6c == 0) && (DAT_00b5ca68 == 0)) {
    if (((DAT_00b60f70 != (int *)0x0) && (*DAT_00b60f70 == 0)) &&
       (DAT_00b60f70 != *(int **)(PTR_DAT_00b49394 + 0x2c))) {
      _free(DAT_00b60f70);
      return extraout_EAX;
    }
    DAT_00b60f74 = (undefined4 *)0x0;
    DAT_00b60f70 = (undefined4 *)0x0;
    _Memory = &PTR_DAT_00b49d44;
    DAT_00b5ca34 = (undefined **)0x0;
  }
  else {
    _Memory = (undefined **)FUN_0080faf9(1,0x30);
    if (_Memory == (undefined **)0x0) {
      return 1;
    }
    puVar4 = (undefined4 *)PTR_PTR_00b49d74;
    ppuVar10 = _Memory;
    for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
      *ppuVar10 = (undefined *)*puVar4;
      puVar4 = puVar4 + 1;
      ppuVar10 = ppuVar10 + 1;
    }
    puVar4 = _malloc(4);
    if (puVar4 == (undefined4 *)0x0) {
      _free(_Memory);
      return extraout_EAX_00;
    }
    *puVar4 = 0;
    if (DAT_00b5ca6c == 0) {
      DAT_00b60f74 = (undefined4 *)0x0;
      *_Memory = PTR_DAT_00b49d44;
      _Memory[1] = PTR_DAT_00b49d48;
      _Memory[2] = PTR_DAT_00b49d4c;
    }
    else {
      DAT_00b60f74 = _malloc(4);
      if (DAT_00b60f74 == (undefined4 *)0x0) {
LAB_00808bb4:
        _free(_Memory);
        return extraout_EAX_01;
      }
      *DAT_00b60f74 = 0;
      uVar3 = DAT_00b5ca9a;
      iVar8 = FUN_00812c18(1,DAT_00b5ca9a,0xe,_Memory);
      iVar5 = FUN_00812c18(1,uVar3,0xf,_Memory + 1);
      iVar6 = FUN_00812c18(1,uVar3,0x10,_Memory + 2);
      if (iVar6 != 0 || (iVar8 != 0 || iVar5 != 0)) {
        FUN_00808a4a(_Memory);
        goto LAB_00808bb4;
      }
      pcVar7 = _Memory[2];
      while (*pcVar7 != '\0') {
        cVar2 = *pcVar7;
        if ((cVar2 < '0') || ('9' < cVar2)) {
          if (cVar2 != ';') goto LAB_00808be0;
          pcVar9 = pcVar7;
          do {
            pcVar1 = pcVar9 + 1;
            *pcVar9 = *pcVar1;
            pcVar9 = pcVar1;
          } while (*pcVar1 != '\0');
        }
        else {
          *pcVar7 = cVar2 + -0x30;
LAB_00808be0:
          pcVar7 = pcVar7 + 1;
        }
      }
    }
    if (((DAT_00b60f70 != (int *)0x0) && (*DAT_00b60f70 == 0)) &&
       (DAT_00b60f70 != *(int **)(PTR_DAT_00b49394 + 0x2c))) {
      _free(DAT_00b60f70);
      return extraout_EAX_02;
    }
    DAT_00b5ca34 = _Memory;
    DAT_00b60f70 = puVar4;
  }
  _DAT_00b49d98 = 1;
  DAT_00b49d94 = **_Memory;
  PTR_PTR_00b49d74 = (undefined *)_Memory;
  return 0;
}


// ==== FUN_00808c76 @ 0x00808c76 ====

void FUN_00808c76(int param_1)

{
  undefined *puVar1;
  
  if (param_1 != 0) {
    puVar1 = *(undefined **)(param_1 + 0xc);
    if ((puVar1 != *(undefined **)(PTR_PTR_00b49d74 + 0xc)) && (puVar1 != PTR_DAT_00b49d50)) {
      _free(puVar1);
      return;
    }
    puVar1 = *(undefined **)(param_1 + 0x10);
    if ((puVar1 != *(undefined **)(PTR_PTR_00b49d74 + 0x10)) && (puVar1 != PTR_DAT_00b49d54)) {
      _free(puVar1);
      return;
    }
    puVar1 = *(undefined **)(param_1 + 0x14);
    if ((puVar1 != *(undefined **)(PTR_PTR_00b49d74 + 0x14)) && (puVar1 != PTR_DAT_00b49d58)) {
      _free(puVar1);
      return;
    }
    puVar1 = *(undefined **)(param_1 + 0x18);
    if ((puVar1 != *(undefined **)(PTR_PTR_00b49d74 + 0x18)) && (puVar1 != PTR_DAT_00b49d5c)) {
      _free(puVar1);
      return;
    }
    puVar1 = *(undefined **)(param_1 + 0x1c);
    if ((puVar1 != *(undefined **)(PTR_PTR_00b49d74 + 0x1c)) && (puVar1 != PTR_DAT_00b49d60)) {
      _free(puVar1);
      return;
    }
    puVar1 = *(undefined **)(param_1 + 0x20);
    if ((puVar1 != *(undefined **)(PTR_PTR_00b49d74 + 0x20)) && (puVar1 != PTR_DAT_00b49d64)) {
      _free(puVar1);
      return;
    }
    puVar1 = *(undefined **)(param_1 + 0x24);
    if ((puVar1 != *(undefined **)(PTR_PTR_00b49d74 + 0x24)) && (puVar1 != PTR_DAT_00b49d68)) {
      _free(puVar1);
      return;
    }
  }
  return;
}


// ==== FUN_00808d4f @ 0x00808d4f ====

undefined4 FUN_00808d4f(void)

{
  char *pcVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 *_Memory;
  undefined4 *puVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  undefined4 extraout_EAX_01;
  char *pcVar20;
  char *pcVar21;
  undefined **ppuVar22;
  undefined4 *puVar23;
  
  if ((DAT_00b5ca68 == 0) && (DAT_00b5ca6c == 0)) {
    DAT_00b60f6c = (undefined4 *)0x0;
    DAT_00b60f70 = (undefined4 *)0x0;
    PTR_PTR_00b49d74 = (undefined *)&PTR_DAT_00b49d44;
    DAT_00b5ca34 = (undefined4 *)0x0;
  }
  else {
    _Memory = (undefined4 *)FUN_0080faf9(1,0x30);
    if (_Memory == (undefined4 *)0x0) {
      return 1;
    }
    puVar4 = _malloc(4);
    if (puVar4 == (undefined4 *)0x0) {
      _free(_Memory);
      return extraout_EAX;
    }
    *puVar4 = 0;
    if (DAT_00b5ca68 == 0) {
      ppuVar22 = &PTR_DAT_00b49d44;
      puVar23 = _Memory;
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar23 = *ppuVar22;
        ppuVar22 = ppuVar22 + 1;
        puVar23 = puVar23 + 1;
      }
      DAT_00b60f6c = (undefined4 *)0x0;
    }
    else {
      DAT_00b60f6c = _malloc(4);
      if (DAT_00b60f6c == (undefined4 *)0x0) {
        _free(_Memory);
        return extraout_EAX_00;
      }
      *DAT_00b60f6c = 0;
      uVar3 = DAT_00b5ca94;
      iVar5 = FUN_00812c18(1,DAT_00b5ca94,0x15,_Memory + 3);
      iVar6 = FUN_00812c18(1,uVar3,0x14,_Memory + 4);
      iVar7 = FUN_00812c18(1,uVar3,0x16,_Memory + 5);
      iVar8 = FUN_00812c18(1,uVar3,0x17,_Memory + 6);
      iVar9 = FUN_00812c18(1,uVar3,0x18,_Memory + 7);
      iVar10 = FUN_00812c18(1,uVar3,0x50,_Memory + 8);
      iVar11 = FUN_00812c18(1,uVar3,0x51,_Memory + 9);
      iVar12 = FUN_00812c18(0,uVar3,0x1a,_Memory + 10);
      iVar13 = FUN_00812c18(0,uVar3,0x19,(int)_Memory + 0x29);
      iVar14 = FUN_00812c18(0,uVar3,0x54,(int)_Memory + 0x2a);
      iVar15 = FUN_00812c18(0,uVar3,0x55,(int)_Memory + 0x2b);
      iVar16 = FUN_00812c18(0,uVar3,0x56,_Memory + 0xb);
      iVar17 = FUN_00812c18(0,uVar3,0x57,(int)_Memory + 0x2d);
      iVar18 = FUN_00812c18(0,uVar3,0x52,(int)_Memory + 0x2e);
      iVar19 = FUN_00812c18(0,uVar3,0x53,(int)_Memory + 0x2f);
      if (iVar19 != 0 ||
          (((((((((((((iVar5 != 0 || iVar6 != 0) || iVar7 != 0) || iVar8 != 0) || iVar9 != 0) ||
                  iVar10 != 0) || iVar11 != 0) || iVar12 != 0) || iVar13 != 0) || iVar14 != 0) ||
             iVar15 != 0) || iVar16 != 0) || iVar17 != 0) || iVar18 != 0)) {
        FUN_00808c76(_Memory);
        _free(_Memory);
        return extraout_EAX_01;
      }
      pcVar20 = (char *)_Memory[7];
      while (*pcVar20 != '\0') {
        cVar2 = *pcVar20;
        if ((cVar2 < '0') || ('9' < cVar2)) {
          if (cVar2 != ';') goto LAB_00808f22;
          pcVar21 = pcVar20;
          do {
            pcVar1 = pcVar21 + 1;
            *pcVar21 = *pcVar1;
            pcVar21 = pcVar1;
          } while (*pcVar1 != '\0');
        }
        else {
          *pcVar20 = cVar2 + -0x30;
LAB_00808f22:
          pcVar20 = pcVar20 + 1;
        }
      }
    }
    *_Memory = *(undefined4 *)PTR_PTR_00b49d74;
    _Memory[1] = *(undefined4 *)(PTR_PTR_00b49d74 + 4);
    _Memory[2] = *(undefined4 *)(PTR_PTR_00b49d74 + 8);
    PTR_PTR_00b49d74 = (undefined *)_Memory;
    DAT_00b5ca34 = _Memory;
    DAT_00b60f70 = puVar4;
  }
  return 0;
}


// ==== FUN_00808f8e @ 0x00808f8e ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00808f8e(void)

{
  BYTE *pBVar1;
  byte bVar2;
  int iVar3;
  void *_Dst;
  void *_Memory;
  BOOL BVar4;
  BYTE *pBVar5;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  uint uVar6;
  undefined2 *puVar7;
  undefined4 *local_24;
  _cpinfo local_1c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)(&local_1c)[1].DefaultChar;
  if (DAT_00b5ca64 == 0) {
    PTR_DAT_00b49d38 = &DAT_00a06748;
    DAT_00b60f68 = (undefined4 *)0x0;
    DAT_00b60f64 = (undefined2 *)0x0;
    return 0;
  }
  if ((DAT_00b5ca74 != 0) || (iVar3 = FUN_00812c18(0,DAT_00b5ca8c,0x1004,&DAT_00b5ca74), iVar3 == 0)
     ) {
    local_24 = _malloc(4);
    _Dst = _malloc(0x300);
    _Memory = _malloc(0x101);
    if ((local_24 != (undefined4 *)0x0) && ((_Dst != (void *)0x0 && (_Memory != (void *)0x0)))) {
      *local_24 = 0;
      iVar3 = 0;
      do {
        *(char *)(iVar3 + (int)_Memory) = (char)iVar3;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x100);
      BVar4 = GetCPInfo(DAT_00b5ca74,&local_1c);
      if ((BVar4 != 0) && (local_1c.MaxCharSize < 6)) {
        DAT_00b49d90 = local_1c.MaxCharSize & 0xffff;
        if ((1 < DAT_00b49d90) && (local_1c.LeadByte[0] != '\0')) {
          pBVar5 = local_1c.LeadByte + 1;
          do {
            bVar2 = *pBVar5;
            if (bVar2 == 0) break;
            for (uVar6 = (uint)pBVar5[-1]; (int)uVar6 <= (int)(uint)bVar2; uVar6 = uVar6 + 1) {
              *(undefined1 *)(uVar6 + (int)_Memory) = 0;
              bVar2 = *pBVar5;
            }
            pBVar1 = pBVar5 + 1;
            pBVar5 = pBVar5 + 2;
          } while (*pBVar1 != 0);
        }
        iVar3 = FUN_00809c38(1,_Memory,0x100,(undefined *)((int)_Dst + 0x100),0,0,0);
        if (iVar3 != 0) {
          *(undefined2 *)((int)_Dst + 0xfe) = 0;
          if ((1 < (int)DAT_00b49d90) && (local_1c.LeadByte[0] != '\0')) {
            pBVar5 = local_1c.LeadByte + 1;
            do {
              if (*pBVar5 == 0) break;
              uVar6 = (uint)pBVar5[-1];
              if (uVar6 <= *pBVar5) {
                puVar7 = (undefined2 *)((int)_Dst + uVar6 * 2 + 0x100);
                do {
                  *puVar7 = 0x8000;
                  uVar6 = uVar6 + 1;
                  puVar7 = puVar7 + 1;
                } while ((int)uVar6 <= (int)(uint)*pBVar5);
              }
              pBVar1 = pBVar5 + 1;
              pBVar5 = pBVar5 + 2;
            } while (*pBVar1 != 0);
          }
          _memcpy(_Dst,(void *)((int)_Dst + 0x200),0xfe);
          PTR_DAT_00b49d38 = (undefined *)((int)_Dst + 0x100);
          DAT_00b60f64 = (undefined2 *)((int)_Dst + 0xfe);
          DAT_00b60f68 = local_24;
          _free(_Memory);
          return extraout_EAX;
        }
      }
    }
  }
  _free(local_24);
  return extraout_EAX_00;
}


// ==== FUN_00809180 @ 0x00809180 ====

uint * FUN_00809180(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = param_1;
  while (((uint)param_2 & 3) != 0) {
    bVar1 = (byte)*param_2;
    uVar3 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_00809270;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_00809270:
        *(byte *)puVar4 = (byte)uVar3;
        return param_1;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return param_1;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return param_1;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return param_1;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}


// ==== FUN_00809190 @ 0x00809190 ====

uint * FUN_00809190(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_008091b0;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_008091e3;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x008091ff;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_008091b0:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x008091ff;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x008091ff;
    }
  }
LAB_008091e3:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x008091ff:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_00809270:
            *(byte *)puVar5 = (byte)uVar4;
            return param_1;
          }
          if ((char)(uVar4 >> 8) == '\0') {
            *(short *)puVar5 = (short)uVar4;
            return param_1;
          }
          if ((uVar4 & 0xff0000) == 0) {
            *(short *)puVar5 = (short)uVar4;
            *(byte *)((int)puVar5 + 2) = 0;
            return param_1;
          }
          if ((uVar4 & 0xff000000) == 0) {
            *puVar5 = uVar4;
            return param_1;
          }
        }
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
      } while( true );
    }
    bVar1 = (byte)*param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_00809270;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}


// ==== _TranslateName @ 0x00809278 ====

/* Library Function - Single Match
    _TranslateName
   
   Library: Visual Studio 2003 Release */

bool _TranslateName(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar3 = 0;
  iVar2 = 1;
  if (-1 < param_2) {
    do {
      bVar5 = iVar2 == 0;
      iVar2 = 0;
      if (bVar5) break;
      iVar4 = (param_2 + iVar3) / 2;
      puVar1 = (undefined4 *)(param_1 + iVar4 * 8);
      iVar2 = __stricmp((char *)*param_3,(char *)*puVar1);
      if (iVar2 == 0) {
        *param_3 = puVar1 + 1;
      }
      else if (iVar2 < 0) {
        param_2 = iVar4 + -1;
      }
      else {
        iVar3 = iVar4 + 1;
      }
    } while (iVar3 <= param_2);
  }
  return iVar2 == 0;
}


// ==== _GetLcidFromDefault @ 0x008092d8 ====

/* Library Function - Single Match
    _GetLcidFromDefault
   
   Library: Visual Studio 2003 Release */

void _GetLcidFromDefault(void)

{
  DAT_00b5ca38._0_2_ = (ushort)DAT_00b5ca38 | 0x104;
  DAT_00b5ca40 = GetUserDefaultLCID();
  DAT_00b5ca3c = DAT_00b5ca40;
  return;
}


// ==== FUN_008092f2 @ 0x008092f2 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008092f2(void)

{
  int iVar1;
  char *in_ECX;
  undefined4 uVar2;
  char local_10 [8];
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)(local_10 + 0xc);
  if (((in_ECX == (char *)0x0) || (*in_ECX == '\0')) ||
     (iVar1 = _strcmp(in_ECX,&DAT_00a07950), iVar1 == 0)) {
    uVar2 = 0x1004;
  }
  else {
    iVar1 = _strcmp(in_ECX,&DAT_00a0794c);
    if (iVar1 != 0) goto LAB_00809358;
    uVar2 = 0xb;
  }
  iVar1 = (*DAT_00b5ca58)(DAT_00b5ca40,uVar2,local_10,8);
  if (iVar1 == 0) {
    return;
  }
  in_ECX = local_10;
LAB_00809358:
  _atol(in_ECX);
  return;
}


// ==== FUN_0080936c @ 0x0080936c ====

undefined4 FUN_0080936c(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (param_1 == *(short *)((int)&DAT_00a0716c + uVar1)) {
      return 0;
    }
    uVar1 = uVar1 + 2;
  } while (uVar1 < 0x14);
  return 1;
}


// ==== crtGetLocaleInfoA @ 0x0080938a ====

/* Library Function - Single Match
    _crtGetLocaleInfoA@16
   
   Library: Visual Studio 2003 Release
   __stdcall crtGetLocaleInfoA,16 */

int crtGetLocaleInfoA(uint param_1,LCTYPE param_2,LPSTR param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *_Source;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0x1a;
  do {
    iVar2 = (iVar3 + iVar4) / 2;
    uVar1 = *(uint *)(iVar2 * 0x2c + 0xa06b50);
    if (param_1 == uVar1) {
      if (param_2 == 1) {
        _Source = &DAT_00a06b54 + iVar2 * 0x2c;
      }
      else if (param_2 == 3) {
        _Source = &DAT_00a06b60 + iVar2 * 0x2c;
      }
      else if (param_2 == 7) {
        _Source = &DAT_00a06b68 + iVar2 * 0x2c;
      }
      else if (param_2 == 0xb) {
        _Source = &DAT_00a06b6c + iVar2 * 0x2c;
      }
      else if (param_2 == 0x1001) {
        _Source = *(char **)(iVar2 * 0x2c + 0xa06b5c);
      }
      else if (param_2 == 0x1002) {
        _Source = *(char **)(iVar2 * 0x2c + 0xa06b64);
      }
      else {
        if (param_2 != 0x1004) break;
        _Source = &DAT_00a06b74 + iVar2 * 0x2c;
      }
      if ((_Source != (char *)0x0) && (0 < param_4)) {
        _strncpy(param_3,_Source,param_4 - 1);
        param_3[param_4 + -1] = '\0';
        return 1;
      }
      break;
    }
    if (param_1 < uVar1) {
      iVar3 = iVar2 + -1;
    }
    else {
      iVar4 = iVar2 + 1;
    }
  } while (iVar4 <= iVar3);
  iVar3 = GetLocaleInfoA(param_1,param_2,param_3,param_4);
  return iVar3;
}


// ==== _LcidFromHexString @ 0x0080946d ====

/* Library Function - Single Match
    _LcidFromHexString
   
   Library: Visual Studio 2003 Release */

int _LcidFromHexString(void)

{
  int iVar1;
  char cVar2;
  char *in_EDX;
  
  iVar1 = 0;
  while (cVar2 = *in_EDX, cVar2 != '\0') {
    in_EDX = in_EDX + 1;
    if ((cVar2 < 'a') || ('f' < cVar2)) {
      if (('@' < cVar2) && (cVar2 < 'G')) {
        cVar2 = cVar2 + -7;
      }
    }
    else {
      cVar2 = cVar2 + -0x27;
    }
    iVar1 = (iVar1 + 0xffffffd) * 0x10 + (int)cVar2;
  }
  return iVar1;
}


// ==== _GetPrimaryLen @ 0x008094a2 ====

/* Library Function - Single Match
    _GetPrimaryLen
   
   Library: Visual Studio 2003 Release */

int _GetPrimaryLen(void)

{
  char cVar1;
  int iVar2;
  char *in_EDX;
  
  iVar2 = 0;
  while( true ) {
    cVar1 = *in_EDX;
    in_EDX = in_EDX + 1;
    if (((cVar1 < 'A') || ('Z' < cVar1)) && ((cVar1 < 'a' || ('z' < cVar1)))) break;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


// ==== FUN_008094bf @ 0x008094bf ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_008094bf(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char local_80 [120];
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)(local_80 + 0x7c);
  uVar1 = _LcidFromHexString();
  iVar2 = (*DAT_00b5ca58)(uVar1,(-(uint)(DAT_00b5ca48 != 0) & 0xfffff005) + 0x1002,local_80,0x78);
  if (iVar2 == 0) {
    DAT_00b5ca38 = 0;
    uVar3 = 1;
  }
  else {
    iVar2 = __stricmp(DAT_00b5ca4c,local_80);
    if (iVar2 == 0) {
      iVar2 = FUN_0080936c(uVar1);
      if (iVar2 != 0) {
        DAT_00b5ca38 = DAT_00b5ca38 | 4;
        DAT_00b5ca3c = uVar1;
        DAT_00b5ca40 = uVar1;
      }
    }
    uVar3 = ~(DAT_00b5ca38 >> 2) & 1;
  }
  return uVar3;
}


// ==== FUN_00809557 @ 0x00809557 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00809557(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  size_t sVar4;
  undefined4 uVar5;
  undefined1 local_80 [120];
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)(local_80 + 0x7c);
  iVar1 = (*DAT_00b5ca58)(param_1 & 0x3ff | 0x400,1,local_80,0x78);
  if (iVar1 == 0) {
LAB_008095b9:
    uVar5 = 0;
  }
  else {
    uVar2 = _LcidFromHexString();
    if ((param_1 != uVar2) && (param_2 != 0)) {
      sVar3 = _strlen(DAT_00b5ca54);
      sVar4 = _GetPrimaryLen();
      if (sVar4 == sVar3) goto LAB_008095b9;
    }
    uVar5 = 1;
  }
  return uVar5;
}


// ==== FUN_008095cc @ 0x008095cc ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_008095cc(void)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  char local_80 [120];
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)(local_80 + 0x7c);
  iVar1 = _LcidFromHexString();
  iVar2 = (*DAT_00b5ca58)(iVar1,(-(uint)(DAT_00b5ca48 != 0) & 0xfffff005) + 0x1002,local_80,0x78);
  if (iVar2 == 0) {
    DAT_00b5ca38 = 0;
    return 1;
  }
  iVar2 = __stricmp(DAT_00b5ca4c,local_80);
  if (iVar2 == 0) {
    iVar2 = (*DAT_00b5ca58)(iVar1,(-(uint)(DAT_00b5ca44 != 0) & 0xfffff002) + 0x1001,local_80,0x78);
    if (iVar2 == 0) {
      DAT_00b5ca38 = 0;
      return 1;
    }
    iVar2 = __stricmp(DAT_00b5ca54,local_80);
    if (iVar2 == 0) {
      DAT_00b5ca38 = DAT_00b5ca38 | 0x304;
      DAT_00b5ca3c = iVar1;
LAB_008096f3:
      DAT_00b5ca40 = iVar1;
    }
    else if ((DAT_00b5ca38 & 2) == 0) {
      if ((DAT_00b5ca50 == 0) ||
         (iVar2 = __strnicmp(DAT_00b5ca54,local_80,DAT_00b5ca50), iVar2 != 0)) {
        if (((DAT_00b5ca38 & 1) == 0) && (iVar2 = FUN_0080936c(iVar1), iVar2 != 0)) {
          DAT_00b5ca38 = DAT_00b5ca38 | 1;
          goto LAB_008096f3;
        }
      }
      else {
        DAT_00b5ca38 = DAT_00b5ca38 | 2;
        DAT_00b5ca40 = iVar1;
        sVar3 = _strlen(DAT_00b5ca54);
        if (sVar3 == DAT_00b5ca50) {
          DAT_00b5ca3c = iVar1;
        }
      }
    }
  }
  if ((DAT_00b5ca38 & 0x300) == 0x300) goto LAB_008097cc;
  iVar2 = (*DAT_00b5ca58)(iVar1,(-(uint)(DAT_00b5ca44 != 0) & 0xfffff002) + 0x1001,local_80,0x78);
  if (iVar2 == 0) {
    DAT_00b5ca38 = 0;
    return 1;
  }
  iVar2 = __stricmp(DAT_00b5ca54,local_80);
  if (iVar2 == 0) {
    DAT_00b5ca38 = DAT_00b5ca38 | 0x200;
    if (((DAT_00b5ca44 == 0) && (DAT_00b5ca50 != 0)) &&
       (sVar3 = _strlen(DAT_00b5ca54), sVar3 == DAT_00b5ca50)) {
      uVar4 = 1;
      goto LAB_008097ab;
    }
  }
  else {
    if (((DAT_00b5ca44 != 0) || (DAT_00b5ca50 == 0)) ||
       (iVar2 = __strnicmp(DAT_00b5ca54,local_80,DAT_00b5ca50), iVar2 != 0)) goto LAB_008097cc;
    uVar4 = 0;
LAB_008097ab:
    iVar2 = FUN_00809557(iVar1,uVar4);
    if (iVar2 == 0) goto LAB_008097cc;
  }
  DAT_00b5ca38 = DAT_00b5ca38 | 0x100;
  if (DAT_00b5ca3c == 0) {
    DAT_00b5ca3c = iVar1;
  }
LAB_008097cc:
  return ~(DAT_00b5ca38 >> 2) & 1;
}


// ==== FUN_008097ea @ 0x008097ea ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_008097ea(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  char local_80 [120];
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)(local_80 + 0x7c);
  uVar1 = _LcidFromHexString();
  iVar2 = (*DAT_00b5ca58)(uVar1,(-(uint)(DAT_00b5ca44 != 0) & 0xfffff002) + 0x1001,local_80,0x78);
  if (iVar2 == 0) {
    DAT_00b5ca38 = 0;
    return 1;
  }
  iVar2 = __stricmp(DAT_00b5ca54,local_80);
  if (iVar2 == 0) {
    if (DAT_00b5ca44 == 0) {
      uVar3 = 1;
      goto LAB_0080987e;
    }
  }
  else {
    if (((DAT_00b5ca44 != 0) || (DAT_00b5ca50 == 0)) ||
       (iVar2 = __strnicmp(DAT_00b5ca54,local_80,DAT_00b5ca50), iVar2 != 0)) goto LAB_0080989d;
    uVar3 = 0;
LAB_0080987e:
    iVar2 = FUN_00809557(uVar1,uVar3);
    if (iVar2 == 0) goto LAB_0080989d;
  }
  DAT_00b5ca38 = DAT_00b5ca38 | 4;
  DAT_00b5ca3c = uVar1;
  DAT_00b5ca40 = uVar1;
LAB_0080989d:
  return ~(DAT_00b5ca38 >> 2) & 1;
}


// ==== _GetLcidFromCountry @ 0x008098b9 ====

/* Library Function - Single Match
    _GetLcidFromCountry
   
   Library: Visual Studio 2003 Release */

void _GetLcidFromCountry(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_00b5ca4c);
  DAT_00b5ca48 = (uint)(sVar1 == 3);
  EnumSystemLocalesA(FUN_008094bf,1);
  if ((DAT_00b5ca38 & 4) == 0) {
    DAT_00b5ca38 = 0;
  }
  return;
}


// ==== _GetLcidFromLangCountry @ 0x008098f0 ====

/* Library Function - Single Match
    _GetLcidFromLangCountry
   
   Library: Visual Studio 2003 Release */

void _GetLcidFromLangCountry(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_00b5ca54);
  DAT_00b5ca44 = (uint)(sVar1 == 3);
  sVar1 = _strlen(DAT_00b5ca4c);
  DAT_00b5ca48 = (uint)(sVar1 == 3);
  DAT_00b5ca3c = 0;
  if (DAT_00b5ca44 == 0) {
    DAT_00b5ca50 = _GetPrimaryLen();
  }
  else {
    DAT_00b5ca50 = 2;
  }
  EnumSystemLocalesA(FUN_008095cc,1);
  if ((((DAT_00b5ca38 & 0x100) == 0) || ((DAT_00b5ca38 & 0x200) == 0)) || ((DAT_00b5ca38 & 7) == 0))
  {
    DAT_00b5ca38 = 0;
  }
  return;
}


// ==== _GetLcidFromLanguage @ 0x00809976 ====

/* Library Function - Single Match
    _GetLcidFromLanguage
   
   Library: Visual Studio 2003 Release */

void _GetLcidFromLanguage(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_00b5ca54);
  DAT_00b5ca44 = (uint)(sVar1 == 3);
  if (sVar1 == 3) {
    DAT_00b5ca50 = 2;
  }
  else {
    DAT_00b5ca50 = _GetPrimaryLen();
  }
  EnumSystemLocalesA(FUN_008097ea,1);
  if ((DAT_00b5ca38 & 4) == 0) {
    DAT_00b5ca38 = 0;
  }
  return;
}


// ==== ___get_qualified_locale @ 0x008099cb ====

/* Library Function - Single Match
    ___get_qualified_locale
   
   Library: Visual Studio 2003 Release */

BOOL __cdecl ___get_qualified_locale(LPLC_STRINGS _LpInStr,UINT *_LpCodePage,LPLC_STRINGS _LpOutStr)

{
  LCID LVar1;
  undefined2 uVar2;
  int iVar3;
  uint _Value;
  BOOL BVar4;
  
  if (DAT_00b5ca58 == (code *)0x0) {
    if (DAT_00b5c720 == 2) {
      DAT_00b5ca58 = GetLocaleInfoA_exref;
    }
    else {
      DAT_00b5ca58 = crtGetLocaleInfoA;
    }
  }
  if (_LpInStr == (LPLC_STRINGS)0x0) {
LAB_00809aa5:
    _GetLcidFromDefault();
LAB_00809aaa:
    if (DAT_00b5ca38 == 0) {
      return 0;
    }
  }
  else {
    DAT_00b5ca4c = _LpInStr->szLanguage + 0x20;
    DAT_00b5ca54 = _LpInStr;
    if ((DAT_00b5ca4c != (wchar_t *)0x0) && ((char)*DAT_00b5ca4c != '\0')) {
      _TranslateName(&PTR_s_america_00a07180,0x16,&DAT_00b5ca4c);
    }
    DAT_00b5ca38 = 0;
    if ((DAT_00b5ca54 == (LPLC_STRINGS)0x0) || ((char)DAT_00b5ca54->szLanguage[0] == '\0')) {
      if ((DAT_00b5ca4c == (wchar_t *)0x0) || ((char)*DAT_00b5ca4c == '\0')) goto LAB_00809aa5;
      _GetLcidFromCountry();
      goto LAB_00809aaa;
    }
    if ((DAT_00b5ca4c == (wchar_t *)0x0) || ((char)*DAT_00b5ca4c == '\0')) {
      _GetLcidFromLanguage();
    }
    else {
      _GetLcidFromLangCountry();
    }
    if (DAT_00b5ca38 == 0) {
      iVar3 = _TranslateName(&PTR_s_american_00a07330,0x40,&DAT_00b5ca54);
      if (iVar3 != 0) {
        if ((DAT_00b5ca4c == (wchar_t *)0x0) || ((char)*DAT_00b5ca4c == '\0')) {
          _GetLcidFromLanguage();
        }
        else {
          _GetLcidFromLangCountry();
        }
      }
      goto LAB_00809aaa;
    }
  }
  _Value = FUN_008092f2();
  if (((_Value == 0) || (BVar4 = IsValidCodePage(_Value & 0xffff), BVar4 == 0)) ||
     (BVar4 = IsValidLocale(DAT_00b5ca3c,1), LVar1 = DAT_00b5ca3c, BVar4 == 0)) {
LAB_00809b7a:
    BVar4 = 0;
  }
  else {
    if (_LpCodePage != (UINT *)0x0) {
      uVar2 = (undefined2)DAT_00b5ca40;
      *(short *)_LpCodePage = (short)DAT_00b5ca3c;
      *(undefined2 *)((int)_LpCodePage + 2) = uVar2;
      *(short *)(_LpCodePage + 1) = (short)_Value;
    }
    if (_LpOutStr != (LPLC_STRINGS)0x0) {
      if ((short)*_LpCodePage == 0x814) {
        FUN_00809180(_LpOutStr,s_Norwegian_Nynorsk_00a07954);
      }
      else {
        iVar3 = (*DAT_00b5ca58)(LVar1,0x1001,_LpOutStr,0x40);
        if (iVar3 == 0) goto LAB_00809b7a;
      }
      iVar3 = (*DAT_00b5ca58)(DAT_00b5ca40,0x1002,_LpOutStr->szLanguage + 0x20,0x40);
      if (iVar3 == 0) goto LAB_00809b7a;
      __itoa(_Value,(char *)_LpOutStr->szCountry,10);
    }
    BVar4 = 1;
  }
  return BVar4;
}


// ==== _memcmp @ 0x00809b80 ====

/* Library Function - Single Match
    _memcmp
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2003 Release */

int __cdecl _memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  uint *puVar7;
  uint *puVar8;
  bool bVar9;
  
  if (_Size != 0) {
    if ((((uint)_Buf1 | (uint)_Buf2) & 3) == 0) {
      uVar2 = _Size & 3;
      uVar5 = _Size >> 2;
      bVar9 = false;
      puVar7 = _Buf1;
      puVar8 = _Buf2;
      if (uVar5 != 0) {
        do {
          _Buf1 = puVar7;
          _Buf2 = puVar8;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          _Buf2 = puVar8 + 1;
          _Buf1 = puVar7 + 1;
          bVar9 = *puVar7 == *puVar8;
          puVar7 = _Buf1;
          puVar8 = _Buf2;
        } while (bVar9);
        if (!bVar9) {
          uVar2 = *(uint *)((int)_Buf1 + -4);
          uVar5 = *(uint *)((int)_Buf2 + -4);
          bVar9 = (byte)uVar2 < (byte)uVar5;
          if ((((byte)uVar2 == (byte)uVar5) &&
              (bVar4 = (byte)(uVar2 >> 8), bVar6 = (byte)(uVar5 >> 8), bVar9 = bVar4 < bVar6,
              bVar4 == bVar6)) &&
             (bVar4 = (byte)(uVar2 >> 0x10), bVar6 = (byte)(uVar5 >> 0x10), bVar9 = bVar4 < bVar6,
             bVar4 == bVar6)) {
            bVar9 = (byte)(uVar2 >> 0x18) < (byte)(uVar5 >> 0x18);
          }
          goto LAB_00809c00;
        }
      }
      if (uVar2 != 0) {
        uVar5 = *(uint *)_Buf1;
        uVar1 = *(uint *)_Buf2;
        bVar9 = (byte)uVar5 < (byte)uVar1;
        if ((byte)uVar5 != (byte)uVar1) {
LAB_00809c00:
          return (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        iVar3 = 0;
        if (uVar2 != 1) {
          bVar6 = (byte)(uVar5 >> 8);
          bVar4 = (byte)(uVar1 >> 8);
          bVar9 = bVar6 < bVar4;
          if (bVar6 != bVar4) goto LAB_00809c00;
          iVar3 = 0;
          if (uVar2 != 2) {
            bVar9 = (uVar5 & 0xff0000) < (uVar1 & 0xff0000);
            if ((uVar5 & 0xff0000) != (uVar1 & 0xff0000)) goto LAB_00809c00;
            iVar3 = uVar2 - 3;
          }
        }
        return iVar3;
      }
    }
    else {
      if ((_Size & 1) == 0) goto LAB_00809bb3;
      bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
      if (*(byte *)_Buf1 != *(byte *)_Buf2) goto LAB_00809c00;
      _Buf1 = (void *)((int)_Buf1 + 1);
      _Buf2 = (void *)((int)_Buf2 + 1);
      for (_Size = _Size - 1; _Size != 0; _Size = _Size - 2) {
LAB_00809bb3:
        bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
        if ((*(byte *)_Buf1 != *(byte *)_Buf2) ||
           (bVar9 = *(byte *)((int)_Buf1 + 1) < *(byte *)((int)_Buf2 + 1),
           *(byte *)((int)_Buf1 + 1) != *(byte *)((int)_Buf2 + 1))) goto LAB_00809c00;
        _Buf2 = (void *)((int)_Buf2 + 2);
        _Buf1 = (void *)((int)_Buf1 + 2);
      }
    }
  }
  return 0;
}


// ==== FUN_00809c38 @ 0x00809c38 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

BOOL FUN_00809c38(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
                 int param_7)

{
  int iVar1;
  bool bVar2;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  BOOL extraout_EAX;
  UINT UVar8;
  BOOL extraout_EAX_00;
  undefined1 *puVar9;
  LPCSTR _Memory;
  undefined4 uStackY_58;
  undefined1 auStack_2e [2];
  size_t local_2c [3];
  WORD local_20 [2];
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00a07968;
  uStack_c = 0x809c44;
  _Memory = (LPCSTR)0x0;
  if (DAT_00b5ca7c == 0) {
    BVar3 = GetStringTypeW(1,(LPCWSTR)&DAT_0099cdc8,1,local_20);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00b5ca7c = 2;
      }
    }
    else {
      DAT_00b5ca7c = 1;
    }
  }
  if ((DAT_00b5ca7c == 2) || (DAT_00b5ca7c == 0)) {
    if (param_6 == 0) {
      param_6 = DAT_00b5ca64;
    }
    if (param_5 == 0) {
      param_5 = DAT_00b5ca74;
    }
    UVar8 = FUN_00812dc7();
    if (UVar8 != 0xffffffff) {
      if (UVar8 != param_5) {
        uStackY_58 = 0x809dbb;
        _Memory = (LPCSTR)FUN_00812e0e();
        if (_Memory == (LPCSTR)0x0) {
          return 0;
        }
        param_2 = _Memory;
      }
      BVar3 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
      if (_Memory == (LPCSTR)0x0) {
        return BVar3;
      }
      _free(_Memory);
      return extraout_EAX_00;
    }
  }
  else if (DAT_00b5ca7c == 1) {
    local_2c[1] = 0;
    bVar2 = false;
    if (param_5 == 0) {
      param_5 = DAT_00b5ca74;
    }
    uStackY_58 = 0x809cd6;
    iVar5 = MultiByteToWideChar(param_5,(uint)(param_7 != 0) * 8 + 1,param_2,param_3,(LPWSTR)0x0,0);
    if (iVar5 != 0) {
      local_8 = (undefined *)0x0;
      puVar6 = (undefined1 *)(iVar5 * 2 + 3U & 0xfffffffc);
      iVar1 = -(int)puVar6;
      puVar7 = auStack_2e + iVar1 + -0xe;
      local_1c = auStack_2e + iVar1 + -0xe;
      *(int *)(auStack_2e + iVar1 + -0x12) = iVar5 * 2;
      *(undefined4 *)(auStack_2e + iVar1 + -0x16) = 0;
      *(undefined1 **)(auStack_2e + iVar1 + -0x1a) = auStack_2e + iVar1 + -0xe;
      *(undefined4 *)(auStack_2e + iVar1 + -0x1e) = 0x809d08;
      _memset(*(void **)(auStack_2e + iVar1 + -0x1a),*(int *)(auStack_2e + iVar1 + -0x16),
              *(size_t *)(auStack_2e + iVar1 + -0x12));
      local_8 = (undefined *)0xffffffff;
      if (auStack_2e + -0xe == puVar6) {
        *(int *)(auStack_2e + iVar1 + -0x12) = iVar5;
        *(undefined4 *)(auStack_2e + iVar1 + -0x16) = 2;
        *(undefined4 *)(auStack_2e + iVar1 + -0x1a) = 0x809d32;
        puVar7 = (undefined1 *)FUN_0080faf9();
        if (puVar7 == (undefined1 *)0x0) {
          return 0;
        }
        bVar2 = true;
      }
      *(int *)(auStack_2e + iVar1 + -0x12) = iVar5;
      *(undefined1 **)(auStack_2e + iVar1 + -0x16) = puVar7;
      *(int *)(auStack_2e + iVar1 + -0x1a) = param_3;
      *(LPCSTR *)(auStack_2e + iVar1 + -0x1e) = param_2;
      *(undefined4 *)(auStack_2e + iVar1 + -0x22) = 1;
      *(UINT *)(auStack_2e + iVar1 + -0x26) = param_5;
      puVar9 = auStack_2e + iVar1 + -0x2a;
      *(undefined4 *)(auStack_2e + iVar1 + -0x2a) = 0x809d54;
      iVar5 = MultiByteToWideChar(*(UINT *)(auStack_2e + iVar1 + -0x26),
                                  *(DWORD *)(auStack_2e + iVar1 + -0x22),
                                  *(LPCSTR *)(auStack_2e + iVar1 + -0x1e),
                                  *(int *)(auStack_2e + iVar1 + -0x1a),
                                  *(LPWSTR *)(auStack_2e + iVar1 + -0x16),
                                  *(int *)(auStack_2e + iVar1 + -0x12));
      puVar6 = puVar9;
      if (iVar5 != 0) {
        *(LPWORD *)(puVar9 + -4) = param_4;
        *(int *)(puVar9 + -8) = iVar5;
        *(undefined1 **)(puVar9 + -0xc) = puVar7;
        *(DWORD *)(puVar9 + -0x10) = param_1;
        puVar6 = puVar9 + -0x14;
        *(undefined4 *)(puVar9 + -0x14) = 0x809d66;
        local_2c[1] = GetStringTypeW(*(DWORD *)(puVar9 + -0x10),*(LPCWSTR *)(puVar9 + -0xc),
                                     *(int *)(puVar9 + -8),*(LPWORD *)(puVar9 + -4));
      }
      if (bVar2) {
        *(undefined1 **)(puVar6 + -4) = puVar7;
        *(undefined4 *)(puVar6 + -8) = 0x809d75;
        _free(*(void **)(puVar6 + -4));
        return extraout_EAX;
      }
      return local_2c[1];
    }
  }
  return 0;
}


// ==== FUN_00809d15 @ 0x00809d15 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00809d15(void)

{
  int iVar1;
  int iVar2;
  BOOL BVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int unaff_EBP;
  
  iVar2 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar2 + -4) = 0x809d1d;
  __resetstkoflw();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar4 = *(undefined4 *)(unaff_EBP + -0x28);
  *(undefined4 *)(iVar2 + -4) = uVar4;
  *(undefined4 *)(iVar2 + -8) = 2;
  *(undefined4 *)(iVar2 + -0xc) = 0x809d32;
  iVar1 = FUN_0080faf9();
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
    *(undefined4 *)(iVar2 + -4) = uVar4;
    *(int *)(iVar2 + -8) = iVar1;
    *(undefined4 *)(iVar2 + -0xc) = *(undefined4 *)(unaff_EBP + 0x10);
    *(undefined4 *)(iVar2 + -0x10) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(iVar2 + -0x14) = 1;
    *(undefined4 *)(iVar2 + -0x18) = *(undefined4 *)(unaff_EBP + 0x18);
    puVar5 = (undefined1 *)(iVar2 + -0x1c);
    *(undefined4 *)(iVar2 + -0x1c) = 0x809d54;
    iVar2 = MultiByteToWideChar(*(UINT *)(iVar2 + -0x18),*(DWORD *)(iVar2 + -0x14),
                                *(LPCSTR *)(iVar2 + -0x10),*(int *)(iVar2 + -0xc),
                                *(LPWSTR *)(iVar2 + -8),*(int *)(iVar2 + -4));
    puVar6 = puVar5;
    if (iVar2 != 0) {
      *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(unaff_EBP + 0x14);
      *(int *)(puVar5 + -8) = iVar2;
      *(int *)(puVar5 + -0xc) = iVar1;
      *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + 8);
      puVar6 = puVar5 + -0x14;
      *(undefined4 *)(puVar5 + -0x14) = 0x809d66;
      BVar3 = GetStringTypeW(*(DWORD *)(puVar5 + -0x10),*(LPCWSTR *)(puVar5 + -0xc),
                             *(int *)(puVar5 + -8),*(LPWORD *)(puVar5 + -4));
      *(BOOL *)(unaff_EBP + -0x24) = BVar3;
    }
    if (*(int *)(unaff_EBP + -0x20) != 0) {
      *(int *)(puVar6 + -4) = iVar1;
      *(undefined4 *)(puVar6 + -8) = 0x809d75;
      _free(*(void **)(puVar6 + -4));
      return extraout_EAX;
    }
    uVar4 = *(undefined4 *)(unaff_EBP + -0x24);
  }
  *(undefined4 *)(unaff_EBP + -0x3c) = 0x809df1;
  return uVar4;
}


// ==== ___isctype_mt @ 0x00809df2 ====

/* Library Function - Single Match
    ___isctype_mt
   
   Library: Visual Studio 2003 Release */

uint ___isctype_mt(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_ECX;
  undefined4 local_8;
  
  if (param_2 + 1U < 0x101) {
    param_2._2_2_ = *(ushort *)(*(int *)(param_1 + 0x48) + param_2 * 2);
  }
  else {
    local_8._2_2_ = (undefined2)((uint)in_ECX >> 0x10);
    if ((*(byte *)(*(int *)(param_1 + 0x48) + 1 + (param_2 >> 8 & 0xffU) * 2) & 0x80) == 0) {
      local_8._0_2_ = (ushort)(byte)param_2;
      uVar1 = 1;
    }
    else {
      local_8 = CONCAT31(CONCAT21(local_8._2_2_,(byte)param_2),(char)((uint)param_2 >> 8));
      uVar1 = local_8;
      local_8._3_1_ = (undefined1)((uint)in_ECX >> 0x18);
      local_8._0_2_ = (ushort)uVar1;
      local_8._0_3_ = (uint3)(ushort)local_8;
      uVar1 = 2;
    }
    iVar2 = FUN_00809c38(1,&local_8,uVar1,(int)&param_2 + 2,*(undefined4 *)(param_1 + 4),
                         *(undefined4 *)(param_1 + 0x14),1);
    if (iVar2 == 0) {
      return 0;
    }
  }
  return param_2._2_2_ & param_3;
}


// ==== ___iswctype_mt @ 0x00809e69 ====

/* Library Function - Single Match
    ___iswctype_mt
   
   Library: Visual Studio 2003 Release */

uint ___iswctype_mt(int param_1,ushort param_2,ushort param_3)

{
  int iVar1;
  uint local_8;
  
  if (param_2 != 0xffff) {
    if (param_2 < 0x100) {
      local_8 = (uint)*(ushort *)(PTR_DAT_00b49d3c + (uint)param_2 * 2);
      goto LAB_00809eb5;
    }
    iVar1 = FUN_00812fe8(1,&param_2,1,&local_8,*(undefined4 *)(param_1 + 4),
                         *(undefined4 *)(param_1 + 0x14));
    if (iVar1 != 0) goto LAB_00809eb5;
  }
  local_8 = 0;
LAB_00809eb5:
  return local_8 & 0xffff & (uint)param_3;
}


// ==== _iswctype @ 0x00809ec0 ====

/* Library Function - Single Match
    _iswctype
   
   Library: Visual Studio 2003 Release */

int __cdecl _iswctype(wint_t _C,wctype_t _Type)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  int iVar3;
  undefined2 in_stack_00000006;
  undefined2 in_stack_0000000a;
  
  if (_C < 0x100) {
    return (uint)(*(ushort *)(PTR_DAT_00b49d3c + (uint)_C * 2) & _Type);
  }
  if (_C == 0xffff) {
    return 0;
  }
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_00b49394) {
    ptVar2 = ___updatetlocinfo();
  }
  iVar3 = ___iswctype_mt(ptVar2,__C,__Type);
  return iVar3;
}


// ==== __forcdecpt @ 0x00809f12 ====

/* Library Function - Single Match
    __forcdecpt
   
   Library: Visual Studio 2003 Release */

void __cdecl __forcdecpt(char *_Buf)

{
  char cVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = _tolower((int)*_Buf);
  bVar4 = iVar3 == 0x65;
  while (!bVar4) {
    _Buf = _Buf + 1;
    iVar3 = _isdigit((int)*_Buf);
    bVar4 = iVar3 == 0;
  }
  cVar2 = *_Buf;
  *_Buf = DAT_00b49d94;
  do {
    _Buf = _Buf + 1;
    cVar1 = *_Buf;
    *_Buf = cVar2;
    cVar2 = cVar1;
  } while (*_Buf != '\0');
  return;
}


// ==== __cropzeros @ 0x00809f4e ====

/* Library Function - Single Match
    __cropzeros
   
   Library: Visual Studio 2003 Release */

void __cdecl __cropzeros(char *_Buf)

{
  char cVar1;
  char *pcVar3;
  char *pcVar2;
  
  for (; (*_Buf != '\0' && (*_Buf != DAT_00b49d94)); _Buf = _Buf + 1) {
  }
  if (*_Buf != '\0') {
    do {
      _Buf = _Buf + 1;
      cVar1 = *_Buf;
      pcVar2 = _Buf;
      if ((cVar1 == '\0') || (cVar1 == 'e')) break;
    } while (cVar1 != 'E');
    do {
      pcVar3 = pcVar2;
      pcVar2 = pcVar3 + -1;
    } while (*pcVar2 == '0');
    if (*pcVar2 == DAT_00b49d94) {
      pcVar2 = pcVar3 + -2;
    }
    do {
      cVar1 = *_Buf;
      pcVar2 = pcVar2 + 1;
      _Buf = _Buf + 1;
      *pcVar2 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// ==== FUN_00809f99 @ 0x00809f99 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00809f99(double *param_1)

{
  if (_DAT_0099d098 <= *param_1) {
    return 1;
  }
  return 0;
}


// ==== __fassign @ 0x00809fb3 ====

/* Library Function - Single Match
    __fassign
   
   Library: Visual Studio 2003 Release */

void __cdecl __fassign(int flag,char *argument,char *number)

{
  undefined4 local_c;
  undefined4 local_8;
  
  if (flag == 0) {
    FUN_00813576(&flag,number);
    *(int *)argument = flag;
    return;
  }
  FUN_00813531(&local_c);
  *(undefined4 *)argument = local_c;
  *(undefined4 *)(argument + 4) = local_8;
  return;
}


// ==== __shift @ 0x00809ff1 ====

/* Library Function - Single Match
    __shift
   
   Library: Visual Studio 2003 Release */

void __shift(void)

{
  char *in_EAX;
  size_t sVar1;
  int unaff_EDI;
  
  if (unaff_EDI != 0) {
    sVar1 = _strlen(in_EAX);
    _memmove(in_EAX + unaff_EDI,in_EAX,sVar1 + 1);
  }
  return;
}


// ==== __cftoe2 @ 0x0080a00e ====

/* Library Function - Single Match
    __cftoe2
   
   Library: Visual Studio 2003 Release */

void __cftoe2(int param_1,int param_2,char param_3)

{
  int *in_EAX;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 *unaff_EBX;
  
  if (param_3 != '\0') {
    __shift();
  }
  if (*in_EAX == 0x2d) {
    *unaff_EBX = 0x2d;
    unaff_EBX = unaff_EBX + 1;
  }
  puVar1 = unaff_EBX;
  if (0 < param_1) {
    puVar1 = unaff_EBX + 1;
    *unaff_EBX = *puVar1;
    *puVar1 = DAT_00b49d94;
  }
  puVar1 = (undefined1 *)FUN_00809180(puVar1 + param_1 + (uint)(param_3 == '\0'),s_e_000_00a07974);
  if (param_2 != 0) {
    *puVar1 = 0x45;
  }
  if (*(char *)in_EAX[3] != '0') {
    iVar2 = in_EAX[1] + -1;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
      puVar1[1] = 0x2d;
    }
    if (99 < iVar2) {
      iVar3 = iVar2 / 100;
      iVar2 = iVar2 % 100;
      puVar1[2] = puVar1[2] + (char)iVar3;
    }
    if (9 < iVar2) {
      iVar3 = iVar2 / 10;
      iVar2 = iVar2 % 10;
      puVar1[3] = puVar1[3] + (char)iVar3;
    }
    puVar1[4] = puVar1[4] + (char)iVar2;
  }
  return;
}


// ==== FUN_0080a0bc @ 0x0080a0bc ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0080a0bc(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  STRFLT _PtFlt;
  int local_30 [4];
  undefined1 local_20 [24];
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)(local_20 + 0x1c);
  _PtFlt = (STRFLT)*param_1;
  FUN_008136ec(_PtFlt,param_1[1],local_30,local_20);
  __fptostr((char *)((uint)(0 < param_3) + (uint)(local_30[0] == 0x2d) + param_2),param_3 + 1,
            (int)local_30,_PtFlt);
  __cftoe2(param_3,param_4,0);
  return param_2;
}


// ==== __cftof2 @ 0x0080a12c ====

/* Library Function - Single Match
    __cftof2
   
   Library: Visual Studio 2003 Release */

undefined1 * __cftof2(undefined1 *param_1,size_t param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  undefined1 *puVar3;
  size_t sVar4;
  
  iVar1 = in_EAX[1];
  if ((param_3 != '\0') && (iVar1 - 1U == param_2)) {
    iVar2 = *in_EAX;
    param_1[(uint)(iVar2 == 0x2d) + (iVar1 - 1U)] = 0x30;
    (param_1 + (uint)(iVar2 == 0x2d) + (iVar1 - 1U))[1] = 0;
  }
  puVar3 = param_1;
  if (*in_EAX == 0x2d) {
    *param_1 = 0x2d;
    puVar3 = param_1 + 1;
  }
  if (in_EAX[1] < 1) {
    __shift();
    *puVar3 = 0x30;
    puVar3 = puVar3 + 1;
  }
  else {
    puVar3 = puVar3 + in_EAX[1];
  }
  if (0 < (int)param_2) {
    __shift();
    *puVar3 = DAT_00b49d94;
    if (in_EAX[1] < 0) {
      sVar4 = -in_EAX[1];
      if ((param_3 != '\0') || ((int)sVar4 <= (int)param_2)) {
        param_2 = sVar4;
      }
      __shift();
      _memset(puVar3 + 1,0x30,param_2);
    }
  }
  return param_1;
}


// ==== FUN_0080a1c8 @ 0x0080a1c8 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0080a1c8(undefined4 *param_1,int param_2,int param_3)

{
  STRFLT _PtFlt;
  int local_30;
  int local_2c;
  undefined1 local_20 [24];
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)(local_20 + 0x1c);
  _PtFlt = (STRFLT)*param_1;
  FUN_008136ec(_PtFlt,param_1[1],&local_30,local_20);
  __fptostr((char *)((uint)(local_30 == 0x2d) + param_2),local_2c + param_3,(int)&local_30,_PtFlt);
  __cftof2(param_2,param_3,0);
  return param_2;
}


// ==== FUN_0080a22f @ 0x0080a22f ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0080a22f(undefined4 *param_1,int param_2,size_t param_3,undefined4 param_4)

{
  char *_Buf;
  int iVar1;
  char *pcVar2;
  STRFLT _PtFlt;
  int local_30;
  int local_2c;
  undefined1 local_20 [24];
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)(local_20 + 0x1c);
  _PtFlt = (STRFLT)*param_1;
  FUN_008136ec(_PtFlt,param_1[1],&local_30,local_20);
  iVar1 = local_2c + -1;
  _Buf = (char *)((uint)(local_30 == 0x2d) + param_2);
  __fptostr(_Buf,param_3,(int)&local_30,_PtFlt);
  local_2c = local_2c + -1;
  if ((local_2c < -4) || ((int)param_3 <= local_2c)) {
    __cftoe2(param_3,param_4,1);
  }
  else {
    if (iVar1 < local_2c) {
      do {
        pcVar2 = _Buf;
        _Buf = pcVar2 + 1;
      } while (*pcVar2 != '\0');
      pcVar2[-1] = '\0';
    }
    __cftof2(param_2,param_3,1);
  }
  return;
}


// ==== __cfltcvt @ 0x0080a2ce ====

/* Library Function - Single Match
    __cfltcvt
   
   Library: Visual Studio 2003 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  errno_t eVar1;
  
  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    eVar1 = FUN_0080a0bc(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      eVar1 = FUN_0080a1c8(arg,buffer,format);
      return eVar1;
    }
    eVar1 = FUN_0080a22f(arg,buffer,format,precision);
  }
  return eVar1;
}


// ==== __setdefaultprecision @ 0x0080a31f ====

/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 2003 Release */

void __setdefaultprecision(void)

{
  __controlfp(0x10000,0x30000);
  return;
}


// ==== __ms_p5_test_fdiv @ 0x0080a331 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __ms_p5_test_fdiv
   
   Library: Visual Studio 2003 Release */

undefined4 __ms_p5_test_fdiv(void)

{
  if (_DAT_0099d0a0 < _DAT_00a07980 - (_DAT_00a07980 / _DAT_00a07988) * _DAT_00a07988) {
    return 1;
  }
  return 0;
}


// ==== __ms_p5_mp_test_fdiv @ 0x0080a371 ====

/* Library Function - Single Match
    __ms_p5_mp_test_fdiv
   
   Library: Visual Studio 2003 Release */

void __ms_p5_mp_test_fdiv(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA(s_KERNEL32_00a079ac);
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,s_GAIsProcessorFeaturePresent_00a0798e + 2);
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(0);
      return;
    }
  }
  __ms_p5_test_fdiv();
  return;
}


// ==== __trandisp1 @ 0x0080a3a0 ====

/* Library Function - Single Match
    __trandisp1
   
   Library: Visual Studio */

void __trandisp1(void)

{
  float10 fVar1;
  byte bVar2;
  int in_EDX;
  undefined2 uVar3;
  int unaff_EBP;
  float10 in_ST0;
  
  if (*(char *)(in_EDX + 0xe) == '\x05') {
    uVar3 = (undefined2)
            CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(unaff_EBP + -0xa4) >> 8) & 0xfe | 2),
                     0x3f);
  }
  else {
    uVar3 = 0x133f;
  }
  *(undefined2 *)(unaff_EBP + -0xa2) = uVar3;
  fVar1 = (float10)0;
  *(int *)(unaff_EBP + -0x94) = in_EDX;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)NAN(in_ST0) << 8 | (ushort)(in_ST0 < fVar1) << 9 | (ushort)(in_ST0 != fVar1) << 10 |
       (ushort)(in_ST0 == fVar1) << 0xe;
  *(undefined1 *)(unaff_EBP + -0x90) = 0;
  bVar2 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;
                    /* WARNING: Could not recover jumptable at 0x0080a405. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(in_EDX + (char)(&DAT_00b49ddc)[(byte)((bVar2 & 7) << 1 | (char)bVar2 < '\0')] + 0x10)
  )();
  return;
}


// ==== __trandisp2 @ 0x0080a407 ====

/* Library Function - Single Match
    __trandisp2
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */

void __trandisp2(void)

{
  float10 fVar1;
  char cVar2;
  byte bVar3;
  int in_EDX;
  undefined2 uVar4;
  int unaff_EBP;
  float10 in_ST0;
  float10 in_ST1;
  
  if (*(char *)(in_EDX + 0xe) == '\x05') {
    uVar4 = (undefined2)
            CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(unaff_EBP + -0xa4) >> 8) & 0xfe | 2),
                     0x3f);
  }
  else {
    uVar4 = 0x133f;
  }
  *(undefined2 *)(unaff_EBP + -0xa2) = uVar4;
  fVar1 = (float10)0;
  *(int *)(unaff_EBP + -0x94) = in_EDX;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)NAN(in_ST0) << 8 | (ushort)(in_ST0 < fVar1) << 9 | (ushort)(in_ST0 != fVar1) << 10 |
       (ushort)(in_ST0 == fVar1) << 0xe;
  *(undefined1 *)(unaff_EBP + -0x90) = 0;
  fVar1 = (float10)0;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)NAN(in_ST1) << 8 | (ushort)(in_ST1 < fVar1) << 9 | (ushort)(in_ST1 != fVar1) << 10 |
       (ushort)(in_ST1 == fVar1) << 0xe;
  bVar3 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;
  cVar2 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;
                    /* WARNING: Could not recover jumptable at 0x0080a491. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(in_EDX + (char)((&DAT_00b49ddc)[(byte)(cVar2 << 1 | cVar2 < '\0') & 0xf] |
                              (&DAT_00b49ddc)[(byte)((bVar3 & 7) << 1 | (char)bVar3 < '\0')] << 2) +
              0x10))();
  return;
}


// ==== FUN_0080a4dd @ 0x0080a4dd ====

float10 FUN_0080a4dd(void)

{
  int unaff_EBP;
  float10 in_ST0;
  unkbyte10 in_ST1;
  
  *(unkbyte10 *)(unaff_EBP + -0x9e) = in_ST1;
  if ((*(byte *)(unaff_EBP + -0x97) & 0x40) == 0) {
    *(undefined1 *)(unaff_EBP + -0x90) = 1;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x90) = 7;
  }
  return *(float10 *)(unaff_EBP + -0x9e) + in_ST0;
}


// ==== FUN_0080a507 @ 0x0080a507 ====

float10 FUN_0080a507(void)

{
  float10 fVar1;
  int unaff_EBP;
  unkbyte10 in_ST0;
  float10 fVar2;
  float10 in_ST1;
  
  *(unkbyte10 *)(unaff_EBP + -0x9e) = in_ST0;
  fVar1 = *(float10 *)(unaff_EBP + -0x9e);
  fVar2 = fVar1;
  if ((*(byte *)(unaff_EBP + -0x97) & 0x40) != 0) {
    *(float10 *)(unaff_EBP + -0x9e) = in_ST1;
    fVar2 = *(float10 *)(unaff_EBP + -0x9e);
    in_ST1 = fVar1;
    if ((*(byte *)(unaff_EBP + -0x97) & 0x40) != 0) {
      *(undefined1 *)(unaff_EBP + -0x90) = 7;
      goto LAB_0080a543;
    }
  }
  *(undefined1 *)(unaff_EBP + -0x90) = 1;
LAB_0080a543:
  return fVar2 + in_ST1;
}


// ==== FUN_0080a546 @ 0x0080a546 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

unkbyte10 FUN_0080a546(void)

{
  int unaff_EBP;
  unkbyte10 Var1;
  
  Var1 = _DAT_00b49dc0;
  if (*(char *)(unaff_EBP + -0x90) < '\x01') {
    *(undefined1 *)(unaff_EBP + -0x90) = 1;
  }
  return Var1;
}


// ==== FUN_0080a570 @ 0x0080a570 ====

float10 FUN_0080a570(void)

{
  float10 in_ST0;
  
  FUN_008138d5();
  return (float10)(double)in_ST0;
}


// ==== __startOneArgErrorHandling @ 0x0080a587 ====

/* Library Function - Single Match
    __startOneArgErrorHandling
   
   Library: Visual Studio */

float10 __startOneArgErrorHandling(void)

{
  float10 in_ST0;
  
  FUN_008138d5();
  return (float10)(double)in_ST0;
}


// ==== FUN_0080a5d0 @ 0x0080a5d0 ====

unkbyte10 FUN_0080a5d0(void)

{
  float10 in_ST0;
  float10 fVar1;
  unkbyte10 Var2;
  
  fVar1 = (float10)f2xm1(-(ROUND(in_ST0) - in_ST0));
  Var2 = fscale((float10)1 + fVar1,ROUND(in_ST0));
  return Var2;
}


// ==== FUN_0080a5e5 @ 0x0080a5e5 ====

void FUN_0080a5e5(void)

{
  return;
}


// ==== FUN_0080a5fc @ 0x0080a5fc ====

undefined4 FUN_0080a5fc(void)

{
  uint in_EAX;
  
  if ((in_EAX & 0x80000) == 0) {
    return 1;
  }
  return 7;
}


// ==== __fload_withFB @ 0x0080a615 ====

/* Library Function - Single Match
    __fload_withFB
   
   Library: Visual Studio */

uint __fload_withFB(void)

{
  uint uVar1;
  int in_EDX;
  
  uVar1 = *(uint *)(in_EDX + 4) & 0x7ff00000;
  if (uVar1 == 0x7ff00000) {
    return *(uint *)(in_EDX + 4);
  }
  return uVar1;
}


// ==== FUN_0080a658 @ 0x0080a658 ====

uint FUN_0080a658(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0x7ff00000) == 0x7ff00000) {
    return param_2;
  }
  return param_2 & 0x7ff00000;
}


// ==== __math_exit @ 0x0080a67b ====

/* Library Function - Single Match
    __math_exit
   
   Library: Visual Studio */

void __math_exit(void)

{
  ushort in_FPUStatusWord;
  ushort unaff_retaddr;
  
  if (((unaff_retaddr == 0x27f) || ((unaff_retaddr & 0x20) == 0)) ||
     ((in_FPUStatusWord & 0x20) == 0)) {
    return;
  }
  __startOneArgErrorHandling();
  return;
}


// ==== FUN_0080a6b9 @ 0x0080a6b9 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0080a6b9(void)

{
  int in_EDX;
  ushort in_FPUStatusWord;
  float10 in_ST0;
  ushort unaff_retaddr;
  uint uStack_4;
  
  uStack_4 = (uint)((ulonglong)(double)in_ST0 >> 0x20);
  if (((ulonglong)(double)in_ST0 & 0x7ff0000000000000) == 0) {
    fscale(in_ST0,(float10)_DAT_00a079ec);
  }
  else if ((uStack_4 & 0x7ff00000) == 0x7ff00000) {
    fscale(in_ST0,(float10)_DAT_00a079e4);
  }
  else if (((unaff_retaddr == 0x27f) || ((unaff_retaddr & 0x20) != 0)) ||
          ((in_FPUStatusWord & 0x20) == 0)) {
    return;
  }
  if (in_EDX == 0x1d) {
    FUN_0080a570();
    return;
  }
  __startOneArgErrorHandling();
  return;
}


// ==== FUN_0080a75c @ 0x0080a75c ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

undefined4 FUN_0080a75c(void)

{
  return 1;
}


// ==== FUN_0080a781 @ 0x0080a781 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_0080a781(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x1c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4) = 0x80a790;
  return uVar1;
}


// ==== FUN_0080a791 @ 0x0080a791 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0080a7d7) */
/* WARNING: Removing unreachable block (ram,0x0080a7c4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0080a791(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar4;
  uint local_20;
  int local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (int)register0x00000010 - 4U;
  local_20 = 0;
  local_1c = 0;
  local_18 = local_18 & 0xffffff00;
  uVar4 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | 0x40
          | (uint)(in_AF & 1) * 0x10 | 4 | (uint)(in_ID & 1) * 0x200000 |
          (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000
  ;
  uVar2 = uVar4 ^ 0x200000;
  if (((uint)((uVar2 & 0x4000) != 0) * 0x4000 | (uint)((uVar2 & 0x200) != 0) * 0x200 |
       (uint)((uVar2 & 0x100) != 0) * 0x100 | (uint)((uVar2 & 0x40) != 0) * 0x40 |
       (uint)((uVar2 & 0x10) != 0) * 0x10 | (uint)((uVar2 & 4) != 0) * 4 |
       (uint)((uVar2 & 0x200000) != 0) * 0x200000 | (uint)((uVar2 & 0x40000) != 0) * 0x40000) !=
      uVar4) {
    iVar3 = cpuid_basic_info(0);
    local_18 = *(uint *)(iVar3 + 4);
    local_14 = *(undefined4 *)(iVar3 + 8);
    local_10 = *(undefined4 *)(iVar3 + 0xc);
    piVar1 = (int *)cpuid_Version_info(1);
    local_1c = *piVar1;
    local_20 = piVar1[2];
  }
  _DAT_00b60f60 = 0;
  DAT_00b60f5c = 0;
  if (((local_20 & 0x4000000) != 0) && (iVar3 = FUN_0080a75c(), iVar3 != 0)) {
    _DAT_00b60f60 = 1;
    iVar3 = _strncmp(s_AuthenticAMD_009fc940,(char *)&local_18,0xc);
    if ((iVar3 != 0) ||
       (uVar2 = local_1c >> 8 & 0xf,
       (~-(uint)(uVar2 != 0xf) & local_1c >> 0x14 & 0xffU) + uVar2 != 0xf)) {
      DAT_00b60f5c = 1;
    }
  }
  return 0;
}


// ==== FUN_0080a870 @ 0x0080a870 ====

void FUN_0080a870(void)

{
  float10 in_ST0;
  float10 in_ST1;
  
  FUN_0080a889((double)in_ST1,(double)in_ST0);
  return;
}


// ==== FUN_0080a889 @ 0x0080a889 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0080a889(double param_1,int param_2,uint param_3)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  ushort uVar11;
  bool bVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined1 auVar17 [16];
  ulonglong uVar16;
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  longlong lVar22;
  ulonglong in_XMM2_Qb;
  undefined1 auVar23 [16];
  longlong lVar26;
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  ulonglong in_XMM3_Qb;
  undefined1 auVar27 [16];
  ulonglong uVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  double dVar35;
  undefined1 local_c [4];
  
  dVar13 = (double)((ulonglong)param_1 >> 0x2c);
  uVar11 = (ushort)((ulonglong)param_1 >> 0x30);
  uVar3 = (SUB82(dVar13,0) & 0xff) + 1 & 0x1fe;
  dVar34 = (double)((ulonglong)DAT_00a0b2b0 & (ulonglong)param_1 | (ulonglong)DAT_00a0b2c0) *
           *(double *)(&DAT_00a07a20 + uVar3 * 4);
  dVar31 = *(double *)(&DAT_00a07a20 + uVar3 * 4);
  dVar14 = *(double *)(&DAT_00a07e30 + uVar3 * 8);
  dVar33 = *(double *)(uVar3 * 8 + 0xa07e38);
  uVar7 = 0x7fef - uVar11;
  uVar3 = SUB84(param_1,0);
  uVar9 = (uint)((ulonglong)param_1 >> 0x20);
  dVar32 = param_1;
  if ((uVar11 - 0x10 | uVar7) < 0x80000000) {
    uVar7 = 0;
    uVar8 = 0x3fe7f;
LAB_0080a906:
    uVar4 = ((ushort)((ulonglong)dVar34 >> 0x26) & 0xff) + 1 & 0x1fe;
    dVar29 = (double)((ulonglong)dVar32 & (ulonglong)DAT_00a0b2b0 | (ulonglong)DAT_00a0b2c0);
    dVar15 = (double)(DAT_00a0b308 & (ulonglong)dVar29);
    in_XMM3_Qb = in_XMM3_Qb >> 0x1f;
    dVar29 = dVar29 - dVar15;
    uVar5 = ((ushort)((ulonglong)(dVar34 * *(double *)(&DAT_00a08640 + uVar4 * 4)) >> 0x1f) & 0x1ff)
            + 1 & 0x3fe;
    dVar30 = dVar31 * *(double *)(&DAT_00a08640 + uVar4 * 4) *
             *(double *)(&DAT_00a09260 + uVar5 * 4);
    dVar34 = dVar34 * *(double *)(&DAT_00a08640 + uVar4 * 4) *
             *(double *)(&DAT_00a09260 + uVar5 * 4);
    dVar32 = dVar14 + *(double *)(&DAT_00a08a50 + uVar4 * 8) +
             (double)(int)((longlong)dVar13 - (ulonglong)uVar8 >> 8) +
             *(double *)(&DAT_00a09a70 + uVar5 * 8);
    dVar13 = dVar33 + *(double *)(&DAT_00a08a58 + uVar4 * 8) +
             *(double *)(&DAT_00a09a78 + uVar5 * 8);
    dVar14 = (double)(DAT_00a0b308 & (ulonglong)dVar30);
    dVar30 = dVar30 - dVar14;
    dVar35 = DAT_00a0b310 + dVar34;
    dVar33 = dVar32 + dVar35;
    dVar31 = (double)CONCAT44(param_3,param_2);
    uVar1 = (ushort)(param_3 >> 0x10);
    dVar32 = dVar32 - dVar33;
    uVar4 = (uint)(ushort)((ulonglong)dVar33 >> 0x30);
    dVar14 = (((dVar34 - dVar14 * dVar15) - dVar15 * dVar30) - dVar14 * dVar29) - dVar29 * dVar30;
    dVar15 = dVar35 - dVar14;
    dVar34 = dVar33 - dVar14;
    uVar8 = uVar1 & 0x7ff0;
    if (uVar8 < 0x7ff0) {
      iVar6 = (uVar8 - 0x3ff0) + (uVar4 & 0x7ff0);
      if ((0x40a0U - iVar6 | iVar6 - 0x3c70U) < 0x80000000) {
LAB_0080aa58:
        dVar29 = (double)(DAT_00a0b308 & (ulonglong)dVar31);
        dVar30 = (double)(DAT_00a0b308 & (ulonglong)dVar34);
        dVar14 = (dVar32 + dVar35) - (dVar14 - (dVar33 - dVar34));
        dVar33 = dVar29 * dVar30 * 128.0;
        uVar3 = (uint)ROUND(dVar33);
        dVar31 = dVar29 * (dVar34 - dVar30) + dVar30 * (dVar31 - dVar29) +
                 (dVar34 - dVar30) * (dVar31 - dVar29);
        if (0 < (int)(0x1ff7f - uVar3 | uVar3 + 0x1e1ff)) {
          iVar6 = (uVar3 & 0x7f) * 0x10;
          auVar17._0_8_ = (double)((ulonglong)((uVar7 + uVar3 & 0xffffff80) + 0x1ff80) << 0x2d);
          auVar17._8_4_ = 0;
          auVar17._12_4_ = (int)((ulonglong)auVar17._0_8_ >> 0x20);
          dVar32 = *(double *)(&DAT_00a0aaa0 + iVar6) * auVar17._0_8_;
          dVar31 = (dVar33 - ((dVar33 + _DAT_00a0b2a0) - _DAT_00a0b2a0)) * 0.0078125 +
                   dVar31 + ((_DAT_00a0aa80 * dVar15 + _DAT_00a0aa90 * dVar15 * dVar15) *
                             dVar15 * dVar15 +
                             dRam00a0aa88 * dVar15 + dRam00a0aa98 * dVar15 * dVar15 +
                            dVar13 + dVar14) * (double)CONCAT44(param_3,param_2);
          return (float10)(dVar31 * dVar31 * dVar32 *
                           (_DAT_00a0b2f0 + _DAT_00a0b2e0 * dVar31) * dVar31 * dVar31 +
                           *(double *)(iVar6 + 0xa0aaa8) * auVar17._8_8_ +
                           (dRam00a0b2f8 + dRam00a0b2e8 * dVar31) * dVar31 * dVar31 * dVar32 +
                           DAT_00a0b300 * dVar31 * dVar32 + dVar32);
        }
        if ((int)uVar3 < 1) {
          if ((int)uVar3 < -0x3fdff) {
LAB_0080b2ea:
            _local_c = (double)((ulonglong)(DAT_00a0b338 * DAT_00a0b338) | (ulonglong)uVar7 << 0x2d)
            ;
            uVar10 = 0x19;
            goto LAB_0080b091;
          }
          uVar7 = uVar7 + 0x80;
          uVar9 = (uVar3 & 0xffffff80) + 0x3fe80;
          uVar11 = 0;
        }
        else {
          if (0x3ffff < uVar3) goto LAB_0080b30d;
          uVar7 = uVar7 + 0x3ff00;
          uVar9 = uVar3 - 0x80 & 0xffffff80;
          uVar11 = 0x3ff0;
        }
        iVar6 = (uVar3 & 0x7f) * 0x10;
        uVar3 = ((int)-(uVar9 - 0x1ff80) >> 7) + 2;
        auVar21._0_8_ = (double)((ulonglong)uVar9 << 0x2d);
        auVar21._8_4_ = 0;
        auVar21._12_4_ = (int)((ulonglong)auVar21._0_8_ >> 0x20);
        dVar32 = *(double *)(&DAT_00a0aaa0 + iVar6) * auVar21._0_8_;
        dVar31 = (dVar33 - ((dVar33 + _DAT_00a0b2a0) - _DAT_00a0b2a0)) * 0.0078125 +
                 dVar31 + ((_DAT_00a0aa80 * dVar15 + _DAT_00a0aa90 * dVar15 * dVar15) *
                           dVar15 * dVar15 + dRam00a0aa88 * dVar15 + dRam00a0aa98 * dVar15 * dVar15
                          + dVar13 + dVar14) * (double)CONCAT44(param_3,param_2);
        _local_c = (double)((ulonglong)uVar7 << 0x2d);
        uVar28 = (ulonglong)(uVar3 + (uVar3 & 0x20));
        dVar14 = (double)(-1L << uVar28 & (ulonglong)dVar32);
        dVar31 = dVar31 * dVar31 * dVar32 *
                 (_DAT_00a0b2f0 + _DAT_00a0b2e0 * dVar31) * dVar31 * dVar31 +
                 *(double *)(iVar6 + 0xa0aaa8) * auVar21._8_8_ +
                 (dRam00a0b2f8 + dRam00a0b2e8 * dVar31) * dVar31 * dVar31 * dVar32 +
                 DAT_00a0b300 * dVar31 * dVar32;
        dVar33 = (double)((ulonglong)(dVar14 + dVar31) & -1L << uVar28);
        dVar31 = dVar31 + (dVar14 - dVar33) + (dVar32 - dVar14);
        if ((int)(uVar9 - 0x1ff80) < 1) {
          _local_c = dVar31 * _local_c + dVar33 * _local_c;
          _local_c = _local_c + (double)((ulonglong)uVar11 << 0x30) * _local_c;
          uVar10 = 0x18;
          if ((((ushort)((ulonglong)_local_c >> 0x30) & 0x7ff0) != 0x7ff0) &&
             (uVar10 = 0x19, ((ulonglong)_local_c & 0x7ff0000000000000) != 0)) {
            return (float10)_local_c;
          }
        }
        else {
          _local_c = (dVar31 + dVar33) * _local_c;
          _local_c = _local_c + (double)((ulonglong)uVar11 << 0x30) * _local_c;
          uVar10 = 0x18;
          if ((((ushort)((ulonglong)_local_c >> 0x30) & 0x7ff0) != 0x7ff0) &&
             (uVar10 = 0x19, ((ulonglong)_local_c & 0x7ff0000000000000) != 0)) {
            return (float10)_local_c;
          }
        }
      }
      else {
        dVar33 = dVar31 * dVar34;
        uVar3 = (ushort)((ulonglong)dVar33 >> 0x30) & 0x7ff0;
        uVar9 = uVar3 - 0x3c70;
        if ((0x40a0 - uVar3 | uVar9) < 0x80000000) goto LAB_0080aa58;
        if (0x7fffffff < uVar9) {
          return (float10)(double)((ulonglong)(uVar7 | 0x1ff80) << 0x2d);
        }
        if (((uVar1 ^ (uVar11 & 0x7ff0) + 0xc010) & 0x8000) != 0) goto LAB_0080b2ea;
LAB_0080b30d:
        uVar10 = 0x18;
        if (uVar7 == 0) {
          _local_c = DAT_00a0b320;
        }
        else {
          _local_c = DAT_00a0b328;
        }
      }
      goto LAB_0080b091;
    }
    _local_c = (double)CONCAT44(param_3,param_2);
    auVar23._8_8_ = in_XMM2_Qb;
    auVar23._0_8_ = _local_c;
    bVar12 = uVar3 != 0;
    uVar3 = uVar4;
    if (bVar12) goto LAB_0080af9c;
    if (uVar9 == 0x3ff00000) goto LAB_0080b07a;
    uVar3 = uVar9;
    if (uVar9 != 0xbff00000) goto LAB_0080af9c;
    auVar19._0_4_ = -(uint)((int)((ulonglong)DAT_00a0b2b0 & (ulonglong)_local_c) == 0);
    auVar19._4_4_ = -(uint)((int)(((ulonglong)DAT_00a0b2b0 & (ulonglong)_local_c) >> 0x20) == 0);
    auVar19._8_4_ = -(uint)((int)(in_XMM3_Qb & in_XMM2_Qb) == 0);
    auVar19._12_4_ = -(uint)((int)((in_XMM3_Qb & in_XMM2_Qb) >> 0x20) == 0);
    if ((ushort)((ushort)(SUB161(auVar19 >> 7,0) & 1) | (ushort)(SUB161(auVar19 >> 0xf,0) & 1) << 1
                 | (ushort)(SUB161(auVar19 >> 0x17,0) & 1) << 2 |
                 (ushort)(SUB161(auVar19 >> 0x1f,0) & 1) << 3 |
                 (ushort)(SUB161(auVar19 >> 0x27,0) & 1) << 4 |
                 (ushort)(SUB161(auVar19 >> 0x2f,0) & 1) << 5 |
                 (ushort)(SUB161(auVar19 >> 0x37,0) & 1) << 6 |
                 (ushort)(SUB161(auVar19 >> 0x3f,0) & 1) << 7 |
                 (ushort)(SUB161(auVar19 >> 0x47,0) & 1) << 8 |
                 (ushort)(SUB161(auVar19 >> 0x4f,0) & 1) << 9 |
                 (ushort)(SUB161(auVar19 >> 0x57,0) & 1) << 10 |
                 (ushort)(SUB161(auVar19 >> 0x5f,0) & 1) << 0xb |
                 (ushort)((byte)(auVar19._12_4_ >> 7) & 1) << 0xc |
                 (ushort)((byte)(auVar19._12_4_ >> 0xf) & 1) << 0xd |
                 (ushort)((byte)(auVar19._12_4_ >> 0x17) & 1) << 0xe |
                (ushort)(byte)(auVar19._12_4_ >> 0x1f) << 0xf) == 0xff) {
      return (float10)1;
    }
  }
  else {
    auVar23._4_4_ = param_3;
    auVar23._0_4_ = param_2;
    auVar23._8_8_ = in_XMM2_Qb;
    uVar8 = param_3 & DAT_00a0b2d0._4_4_;
    if (uVar8 < 0x7ff00000) {
      if (param_2 == 0 && uVar8 == 0) {
        uVar10 = 0x1a;
        _local_c = DAT_00a0b2c0;
        if (uVar3 != 0 || ((ulonglong)param_1 & 0x7fffffff00000000) != 0) {
          uVar10 = 0x1d;
          if (((uVar9 & 0x7fffffff) < 0x7ff00001) &&
             (((uVar9 & 0x7fffffff) < 0x7ff00000 || (uVar3 == 0)))) {
            return (float10)DAT_00a0b2c0;
          }
        }
        goto LAB_0080b091;
      }
      if ((int)uVar7 < 0) {
        auVar27._0_8_ = CONCAT44(DAT_00a0b2d0._4_4_,(undefined4)DAT_00a0b2d0) << 0x34;
        auVar27._8_8_ = in_XMM3_Qb << 0x34;
        iVar6 = (uVar8 >> 0x14) - 0x3f3;
        in_XMM3_Qb = 0;
        uVar28 = (ulonglong)
                 CONCAT22((ushort)(-1 < iVar6) * (short)((uint)iVar6 >> 0x10),
                          (ushort)(-1 < (short)iVar6) * (short)iVar6);
        lVar22 = SUB168(auVar23 | auVar27,0) << uVar28;
        lVar26 = SUB168(auVar23 | auVar27,8) << uVar28;
        auVar24._0_4_ = -(uint)((int)lVar22 == 0);
        auVar24._4_4_ = -(uint)((int)((ulonglong)lVar22 >> 0x20) == 0);
        auVar24._8_4_ = -(uint)((int)lVar26 == 0);
        auVar24._12_4_ = -(uint)((int)((ulonglong)lVar26 >> 0x20) == 0);
        bVar2 = SUB161(auVar24 >> 7,0) & 1 | (SUB161(auVar24 >> 0xf,0) & 1) << 1 |
                (SUB161(auVar24 >> 0x17,0) & 1) << 2 | (SUB161(auVar24 >> 0x1f,0) & 1) << 3 |
                (SUB161(auVar24 >> 0x27,0) & 1) << 4 | (SUB161(auVar24 >> 0x2f,0) & 1) << 5 |
                (SUB161(auVar24 >> 0x37,0) & 1) << 6 | SUB161(auVar24 >> 0x3f,0) << 7;
        uVar8 = 0x7fef - uVar7 & 0x7fff;
        uVar28 = auVar24._8_8_;
        if (0x7fef < uVar8) {
          auVar18._0_4_ = -(uint)((int)((ulonglong)DAT_00a0b2b0 & (ulonglong)param_1) == 0);
          auVar18._4_4_ =
               -(uint)((int)(((ulonglong)DAT_00a0b2b0 & (ulonglong)param_1) >> 0x20) == 0);
          auVar18._8_4_ = 0xffffffff;
          auVar18._12_4_ = 0xffffffff;
          if ((byte)(SUB161(auVar18 >> 7,0) & 1 | (SUB161(auVar18 >> 0xf,0) & 1) << 1 |
                     (SUB161(auVar18 >> 0x17,0) & 1) << 2 | (SUB161(auVar18 >> 0x1f,0) & 1) << 3 |
                     (SUB161(auVar18 >> 0x27,0) & 1) << 4 | (SUB161(auVar18 >> 0x2f,0) & 1) << 5 |
                     (SUB161(auVar18 >> 0x37,0) & 1) << 6 | SUB161(auVar18 >> 0x3f,0) << 7) == 0xff)
          {
            if (((ulonglong)param_1 & 0x8000000000000000) != 0) {
              if ((bVar2 != 0xff) ||
                 (uVar16 = (ulonglong)(((param_3 & DAT_00a0b2d0._4_4_) >> 0x14) - 0x3f4),
                 lVar22 = CONCAT44(param_3,param_2) << uVar16, lVar26 = uVar28 << uVar16,
                 auVar25._0_4_ = -(uint)((int)lVar22 == 0),
                 auVar25._4_4_ = -(uint)((int)((ulonglong)lVar22 >> 0x20) == 0),
                 auVar25._8_4_ = -(uint)((int)lVar26 == 0),
                 auVar25._12_4_ = -(uint)((int)((ulonglong)lVar26 >> 0x20) == 0),
                 (byte)(SUB161(auVar25 >> 7,0) & 1 | (SUB161(auVar25 >> 0xf,0) & 1) << 1 |
                        (SUB161(auVar25 >> 0x17,0) & 1) << 2 | (SUB161(auVar25 >> 0x1f,0) & 1) << 3
                        | (SUB161(auVar25 >> 0x27,0) & 1) << 4 |
                        (SUB161(auVar25 >> 0x2f,0) & 1) << 5 | (SUB161(auVar25 >> 0x37,0) & 1) << 6
                       | SUB161(auVar25 >> 0x3f,0) << 7) == 0xff)) {
                if ((param_3 & 0x80000000) != 0) {
                  return (float10)0;
                }
                goto LAB_0080b00e;
              }
              if ((param_3 & 0x80000000) == 0) {
                return (float10)DAT_00a0b328;
              }
              goto LAB_0080aea9;
            }
            if ((param_3 & 0x80000000) != 0) {
              return (float10)0;
            }
            goto LAB_0080b00e;
          }
          goto LAB_0080aeef;
        }
        if (bVar2 == 0xff) {
          uVar16 = (ulonglong)(((param_3 & DAT_00a0b2d0._4_4_) >> 0x14) - 0x3f4);
          in_XMM3_Qb = 0;
          lVar22 = CONCAT44(param_3,param_2) << uVar16;
          lVar26 = uVar28 << uVar16;
          auVar23._0_4_ = -(uint)((int)lVar22 == SUB84(DAT_00a0b330,0));
          auVar23._4_4_ =
               -(uint)((int)((ulonglong)lVar22 >> 0x20) == (int)((ulonglong)DAT_00a0b330 >> 0x20));
          auVar23._8_4_ = -(uint)((int)lVar26 == 0);
          auVar23._12_4_ = -(uint)((int)((ulonglong)lVar26 >> 0x20) == 0);
          uVar7 = (ushort)((ushort)(SUB161(auVar23 >> 7,0) & 1) |
                           (ushort)(SUB161(auVar23 >> 0xf,0) & 1) << 1 |
                           (ushort)(SUB161(auVar23 >> 0x17,0) & 1) << 2 |
                           (ushort)(SUB161(auVar23 >> 0x1f,0) & 1) << 3 |
                           (ushort)(SUB161(auVar23 >> 0x27,0) & 1) << 4 |
                           (ushort)(SUB161(auVar23 >> 0x2f,0) & 1) << 5 |
                           (ushort)(SUB161(auVar23 >> 0x37,0) & 1) << 6 |
                          (ushort)(SUB161(auVar23 >> 0x3f,0) & 1) << 7) + 0x3ff01 & 0x40000;
          if (0xf < uVar8) {
            uVar8 = 0xbfe7f;
            in_XMM3_Qb = 0;
            in_XMM2_Qb = auVar23._8_8_;
            goto LAB_0080a906;
          }
          goto LAB_0080ad24;
        }
        dVar31 = (double)((ulonglong)param_1 >> 0x20);
        in_XMM2_Qb = uVar28 >> 0x20;
        uVar7 = 0;
        uVar8 = 0;
        if (uVar3 != 0 || ((ulonglong)param_1 & 0x7fffffff00000000) != 0) {
          uVar10 = 0x1c;
          _local_c = DAT_00a0b340;
          goto LAB_0080b091;
        }
LAB_0080adaa:
        dVar32 = dVar13;
        if ((uVar8 & 0x7fffffff) == 0) {
          if ((param_3 & 0x80000000) == 0) {
            if ((uVar8 & uVar7 << 0xd) == 0) {
              return (float10)0;
            }
LAB_0080aea9:
            return (float10)DAT_00a0b330;
          }
          _local_c = (double)((ulonglong)(uVar8 & uVar7 << 0xd | 0x7ff00000) << 0x20);
          uVar10 = 0x1b;
          goto LAB_0080b091;
        }
      }
      else {
        uVar7 = 0;
LAB_0080ad24:
        in_XMM2_Qb = auVar23._8_8_;
        dVar13 = param_1 * 1.8446744073709552e+19;
        uVar8 = uVar9;
        dVar32 = dVar13;
        dVar34 = DAT_00a0b2b0;
        dVar31 = DAT_00a0b2c0;
        if (uVar3 == 0) goto LAB_0080adaa;
      }
      dVar13 = (double)(((ulonglong)dVar32 & CONCAT44(DAT_00a0b2d0._4_4_,(undefined4)DAT_00a0b2d0))
                       >> 0x2c);
      uVar8 = (SUB82(dVar13,0) & 0xff) + 1 & 0x1fe;
      dVar34 = (double)((ulonglong)dVar34 & (ulonglong)dVar32 | (ulonglong)dVar31) *
               *(double *)(&DAT_00a07a20 + uVar8 * 4);
      dVar31 = *(double *)(&DAT_00a07a20 + uVar8 * 4);
      dVar14 = *(double *)(&DAT_00a07e30 + uVar8 * 8);
      dVar33 = *(double *)(uVar8 * 8 + 0xa07e38);
      uVar8 = 0x43e7f;
      goto LAB_0080a906;
    }
    uVar7 = uVar9;
    if ((0x7fefffff < (uVar9 & 0x7fffffff)) && ((0x7ff00000 < (uVar9 & 0x7fffffff) || (uVar3 != 0)))
       ) {
LAB_0080aeef:
      _local_c = param_1 + param_1;
      uVar10 = 0x3ee;
      goto LAB_0080b091;
    }
LAB_0080af9c:
    _local_c = auVar23._0_8_;
    uVar28 = in_XMM3_Qb & auVar23._8_8_;
    auVar20._0_4_ = -(uint)((int)((ulonglong)DAT_00a0b2b0 & (ulonglong)_local_c) == 0);
    auVar20._4_4_ = -(uint)((int)(((ulonglong)DAT_00a0b2b0 & (ulonglong)_local_c) >> 0x20) == 0);
    auVar20._8_4_ = -(uint)((int)uVar28 == 0);
    auVar20._12_4_ = -(uint)((int)(uVar28 >> 0x20) == 0);
    if ((byte)(SUB161(auVar20 >> 7,0) & 1 | (SUB161(auVar20 >> 0xf,0) & 1) << 1 |
               (SUB161(auVar20 >> 0x17,0) & 1) << 2 | (SUB161(auVar20 >> 0x1f,0) & 1) << 3 |
               (SUB161(auVar20 >> 0x27,0) & 1) << 4 | (SUB161(auVar20 >> 0x2f,0) & 1) << 5 |
               (SUB161(auVar20 >> 0x37,0) & 1) << 6 | SUB161(auVar20 >> 0x3f,0) << 7) == 0xff) {
      if (uVar3 != 0 || uVar7 != 0xbff00000) {
        if ((auVar23._6_2_ & 0x8000) == 0) {
          if ((uVar11 & 0x7ff0) < 0x3ff0) {
            return (float10)0;
          }
        }
        else if (0x3fef < (uVar11 & 0x7ff0)) {
          return (float10)0;
        }
LAB_0080b00e:
        return (float10)DAT_00a0b320;
      }
LAB_0080b07a:
      _local_c = (double)CONCAT44(param_3,param_2) + DAT_00a0b340;
      uVar10 = 0x1c;
      goto LAB_0080b091;
    }
  }
  _local_c = _local_c + _local_c;
  uVar10 = 0x3ee;
LAB_0080b091:
  FUN_0080fc6b(&param_1,&param_2,local_c,uVar10);
  return (float10)_local_c;
}


// ==== __d_inttype @ 0x0080b5c7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __d_inttype
   
   Library: Visual Studio 2003 Release */

undefined4 __d_inttype(double param_1)

{
  uint uVar1;
  float10 fVar2;
  undefined8 extraout_var;
  
  uVar1 = __fpclass(param_1);
  if ((uVar1 & 0x90) == 0) {
    fVar2 = (float10)__frnd(param_1,extraout_var);
    if ((double)fVar2 == param_1) {
      param_1 = param_1 / _DAT_00a0b350;
      fVar2 = (float10)__frnd();
      if ((float10)param_1 == fVar2) {
        return 2;
      }
      return 1;
    }
  }
  return 0;
}


// ==== __powhlp @ 0x0080b635 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __powhlp
   
   Library: Visual Studio 2003 Release */

undefined4 __powhlp(int param_1,int param_2,double param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  int iVar3;
  undefined4 uVar4;
  
  dVar1 = (double)CONCAT44(param_2,param_1);
  uVar4 = 0;
  if (dVar1 < _DAT_0099d098) {
    dVar1 = -dVar1;
  }
  dVar2 = _DAT_00b49f10;
  if (param_3._4_4_ == 0x7ff00000) {
    if (param_3._0_4_ != 0) goto LAB_0080b6e0;
    if (_DAT_0099d0a0 < dVar1) goto LAB_0080b790;
    if (_DAT_0099d0a0 <= dVar1) goto LAB_0080b693;
  }
  else {
    if ((param_3._4_4_ == -0x100000) && (param_3._0_4_ == 0)) {
      if (_DAT_0099d0a0 < dVar1) {
        dVar2 = 0.0;
        goto LAB_0080b790;
      }
      if (dVar1 < _DAT_0099d0a0) goto LAB_0080b790;
LAB_0080b693:
      uVar4 = 1;
      dVar2 = _DAT_00b49f18;
      goto LAB_0080b790;
    }
LAB_0080b6e0:
    if (param_2 != 0x7ff00000) {
      if (param_2 != -0x100000) {
        return 0;
      }
      if (param_1 != 0) {
        return 0;
      }
      iVar3 = __d_inttype(param_3);
      if (param_3 <= _DAT_0099d098) {
        if (_DAT_0099d098 <= param_3) {
          dVar2 = 1.0;
        }
        else if (iVar3 == 1) {
          dVar2 = _DAT_00b49f30;
        }
        else {
          dVar2 = 0.0;
        }
      }
      else {
        dVar2 = _DAT_00b49f10;
        if (iVar3 == 1) {
          dVar2 = -_DAT_00b49f10;
        }
      }
      goto LAB_0080b790;
    }
    if (param_1 != 0) {
      return 0;
    }
    if (_DAT_0099d098 < param_3) goto LAB_0080b790;
    if (_DAT_0099d098 <= param_3) {
      dVar2 = 1.0;
      goto LAB_0080b790;
    }
  }
  dVar2 = 0.0;
LAB_0080b790:
  *param_4 = dVar2;
  return uVar4;
}


// ==== siglookup @ 0x0080b797 ====

/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 2003 Release */

void __cdecl siglookup(void)

{
  uint uVar1;
  uint in_EDX;
  int unaff_ESI;
  
  uVar1 = in_EDX;
  do {
    if (*(int *)(uVar1 + 4) == unaff_ESI) {
      return;
    }
    uVar1 = uVar1 + 0xc;
  } while (uVar1 < in_EDX + DAT_00b49d0c * 0xc);
  return;
}


// ==== _raise @ 0x0080b7c5 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 2003 Release */

int __cdecl _raise(int _SigNum)

{
  int iVar1;
  void *extraout_ECX;
  void *_File;
  undefined4 *puVar2;
  code *pcVar3;
  void *local_34;
  void *local_30;
  _ptiddata local_28;
  void *local_20;
  
  local_20 = (void *)0x0;
  if (_SigNum == 2) {
    puVar2 = &DAT_00b5caa4;
    pcVar3 = DAT_00b5caa4;
LAB_0080b852:
    local_20 = (void *)0x1;
  }
  else {
    if (((_SigNum != 4) && (_SigNum != 8)) && (_SigNum != 0xb)) {
      if (_SigNum == 0xf) {
        puVar2 = &DAT_00b5cab0;
        pcVar3 = DAT_00b5cab0;
      }
      else if (_SigNum == 0x15) {
        puVar2 = &DAT_00b5caa8;
        pcVar3 = DAT_00b5caa8;
      }
      else {
        if (_SigNum != 0x16) {
          return -1;
        }
        puVar2 = &DAT_00b5caac;
        pcVar3 = DAT_00b5caac;
      }
      goto LAB_0080b852;
    }
    local_28 = __getptd();
    iVar1 = siglookup();
    puVar2 = (undefined4 *)(iVar1 + 8);
    pcVar3 = (code *)*puVar2;
  }
  _File = (void *)0x0;
  if (pcVar3 == (code *)0x1) {
    return 0;
  }
  if (pcVar3 == (code *)0x0) {
    __exit(3);
    _File = extraout_ECX;
  }
  if (local_20 != _File) {
    __lock((int)_File);
    _File = (void *)0x0;
  }
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (_SigNum == 4)) {
    local_30 = local_28->_initarg;
    local_28->_initarg = _File;
    if (_SigNum == 8) {
      local_34 = local_28->_pxcptacttab;
      local_28->_pxcptacttab = (void *)0x8c;
      goto LAB_0080b8b1;
    }
  }
  else {
LAB_0080b8b1:
    if (_SigNum == 8) {
      for (iVar1 = DAT_00b49d00; iVar1 < DAT_00b49d04 + DAT_00b49d00; iVar1 = iVar1 + 1) {
        *(void **)((int)local_28->_initaddr + iVar1 * 0xc + 8) = _File;
      }
      goto LAB_0080b8df;
    }
  }
  *puVar2 = _File;
LAB_0080b8df:
  FUN_0080b900();
  if (_SigNum == 8) {
    (*pcVar3)(8,local_28->_pxcptacttab);
  }
  else {
    (*pcVar3)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  local_28->_initarg = local_30;
  if (_SigNum == 8) {
    local_28->_pxcptacttab = local_34;
  }
  return 0;
}


// ==== FUN_0080b900 @ 0x0080b900 ====

void FUN_0080b900(void)

{
  int in_ECX;
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) != in_ECX) {
    FUN_00806c2f();
  }
  return;
}


// ==== __flsbuf @ 0x0080b93e ====

/* Library Function - Single Match
    __flsbuf
   
   Library: Visual Studio 2003 Release */

int __cdecl __flsbuf(int _Ch,FILE *_File)

{
  uint uVar1;
  uint _FileHandle;
  char *_Buf;
  char *pcVar2;
  FILE *_File_00;
  int iVar3;
  undefined *puVar4;
  FILE *_MaxCharCount;
  
  _File_00 = _File;
  uVar1 = _File->_flag;
  _FileHandle = _File->_file;
  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {
LAB_0080ba4a:
    _File->_flag = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      _File->_cnt = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_0080ba4a;
      _File->_ptr = _File->_base;
      _File->_flag = uVar1 & 0xfffffffe;
    }
    uVar1 = _File->_flag;
    _File->_cnt = 0;
    _File = (FILE *)0x0;
    _File_00->_flag = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((_File_00 != (FILE *)&DAT_00b496a0 && (_File_00 != (FILE *)&DAT_00b496c0)) ||
        (iVar3 = __isatty(_FileHandle), iVar3 == 0)))) {
      __getbuf(_File_00);
    }
    if ((_File_00->_flag & 0x108) == 0) {
      _MaxCharCount = (FILE *)0x1;
      _File = (FILE *)__write(_FileHandle,&_Ch,1);
    }
    else {
      _Buf = _File_00->_base;
      pcVar2 = _File_00->_ptr;
      _File_00->_ptr = _Buf + 1;
      _MaxCharCount = (FILE *)(pcVar2 + -(int)_Buf);
      _File_00->_cnt = _File_00->_bufsiz + -1;
      if ((int)_MaxCharCount < 1) {
        if (_FileHandle == 0xffffffff) {
          puVar4 = &DAT_00b49d10;
        }
        else {
          puVar4 = (undefined *)
                   ((&DAT_00b60fa0)[(int)_FileHandle >> 5] + (_FileHandle & 0x1f) * 0x24);
        }
        if ((puVar4[4] & 0x20) != 0) {
          __lseek(_FileHandle,0,2);
        }
      }
      else {
        _File = (FILE *)__write(_FileHandle,_Buf,(uint)_MaxCharCount);
      }
      *_File_00->_base = (char)_Ch;
    }
    if (_File == _MaxCharCount) {
      return _Ch & 0xff;
    }
    _File_00->_flag = _File_00->_flag | 0x20;
  }
  return -1;
}


// ==== write_char @ 0x0080ba57 ====

/* Library Function - Single Match
    _write_char
   
   Library: Visual Studio 2003 Release */

void __cdecl write_char(void)

{
  int *piVar1;
  byte in_AL;
  uint uVar2;
  FILE *in_ECX;
  int *unaff_ESI;
  
  if (((in_ECX->_flag & 0x40) == 0) || (in_ECX->_base != (char *)0x0)) {
    piVar1 = &in_ECX->_cnt;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      uVar2 = __flsbuf((int)(char)in_AL,in_ECX);
    }
    else {
      *in_ECX->_ptr = in_AL;
      in_ECX->_ptr = in_ECX->_ptr + 1;
      uVar2 = (uint)in_AL;
    }
    if (uVar2 == 0xffffffff) {
      *unaff_ESI = -1;
      return;
    }
  }
  *unaff_ESI = *unaff_ESI + 1;
  return;
}


// ==== write_multi_char @ 0x0080ba8a ====

/* Library Function - Single Match
    _write_multi_char
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

void __cdecl write_multi_char(undefined4 param_1,int param_2)

{
  int *in_EAX;
  
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    write_char();
  } while (*in_EAX != -1);
  return;
}


// ==== write_string @ 0x0080baae ====

/* Library Function - Single Match
    _write_string
   
   Library: Visual Studio 2003 Release */

void __cdecl write_string(int param_1)

{
  int *in_EAX;
  int unaff_EDI;
  
  if (((*(byte *)(unaff_EDI + 0xc) & 0x40) == 0) || (*(int *)(unaff_EDI + 8) != 0)) {
    do {
      if (param_1 < 1) {
        return;
      }
      param_1 = param_1 + -1;
      write_char();
    } while (*in_EAX != -1);
  }
  else {
    *in_EAX = *in_EAX + param_1;
  }
  return;
}


// ==== FUN_0080bae5 @ 0x0080bae5 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0080bae5(undefined4 param_1,byte *param_2,wchar_t *param_3)

{
  byte bVar1;
  wchar_t _WCh;
  short *psVar2;
  undefined4 uVar3;
  uint uVar4;
  wchar_t *pwVar5;
  int iVar6;
  int extraout_EAX;
  int iVar7;
  int extraout_ECX;
  byte bVar8;
  undefined1 *puVar9;
  bool bVar10;
  longlong lVar11;
  undefined4 local_264;
  undefined4 local_260;
  undefined1 *local_258;
  int local_254;
  undefined4 local_250;
  int local_24c;
  int local_248;
  wchar_t *local_244;
  int local_240;
  int local_23c;
  undefined4 local_238;
  byte *local_234;
  int local_230;
  undefined1 local_22c;
  char local_22b;
  int local_228;
  undefined1 *local_224;
  wchar_t *local_220;
  int local_21c;
  wchar_t *local_218;
  uint local_214;
  undefined1 local_210 [44];
  undefined1 local_1e4 [467];
  undefined2 local_11;
  uint local_8;
  
  local_8 = DAT_00b49670 ^ (uint)local_1e4;
  local_238 = param_1;
  bVar8 = *param_2;
  local_218 = param_3;
  local_254 = 0;
  local_224 = (undefined1 *)0x0;
  local_228 = 0;
  local_244 = (wchar_t *)0x0;
  if (bVar8 != 0) {
    while (local_234 = param_2 + 1, -1 < local_228) {
      if (((char)bVar8 < ' ') || ('x' < (char)bVar8)) {
        uVar4 = 0;
      }
      else {
        uVar4 = (int)(char)(&DAT_00a0b348)[(char)bVar8] & 0xf;
      }
      local_254 = (int)(char)(&DAT_00a0b368)[uVar4 * 8 + local_254] >> 4;
      switch(local_254) {
      case 0:
switchD_0080bb7c_caseD_0:
        local_240 = 0;
        if ((PTR_DAT_00b49d38[(uint)bVar8 * 2 + 1] & 0x80) != 0) {
          write_char();
          local_234 = param_2 + 2;
        }
        write_char();
        break;
      case 1:
        local_21c = -1;
        local_250 = 0;
        local_248 = 0;
        local_23c = 0;
        local_230 = 0;
        local_214 = 0;
        local_240 = 0;
        break;
      case 2:
        if (bVar8 == 0x20) {
          local_214 = local_214 | 2;
        }
        else if (bVar8 == 0x23) {
          local_214 = local_214 | 0x80;
        }
        else if (bVar8 == 0x2b) {
          local_214 = local_214 | 1;
        }
        else if (bVar8 == 0x2d) {
          local_214 = local_214 | 4;
        }
        else if (bVar8 == 0x30) {
          local_214 = local_214 | 8;
        }
        break;
      case 3:
        if (bVar8 == 0x2a) {
          pwVar5 = local_218 + 2;
          local_23c = *(int *)local_218;
          local_218 = pwVar5;
          if (local_23c < 0) {
            local_214 = local_214 | 4;
            local_23c = -local_23c;
          }
        }
        else {
          local_23c = (char)bVar8 + -0x30 + local_23c * 10;
        }
        break;
      case 4:
        local_21c = 0;
        break;
      case 5:
        if (bVar8 == 0x2a) {
          pwVar5 = local_218 + 2;
          local_21c = *(int *)local_218;
          local_218 = pwVar5;
          if (local_21c < 0) {
            local_21c = -1;
          }
        }
        else {
          local_21c = (char)bVar8 + -0x30 + local_21c * 10;
        }
        break;
      case 6:
        if (bVar8 == 0x49) {
          bVar1 = *local_234;
          if ((bVar1 == 0x36) && (param_2[2] == 0x34)) {
            local_234 = param_2 + 3;
            local_214 = local_214 | 0x8000;
          }
          else if ((bVar1 == 0x33) && (param_2[2] == 0x32)) {
            local_234 = param_2 + 3;
            local_214 = local_214 & 0xffff7fff;
          }
          else if (((((bVar1 != 100) && (bVar1 != 0x69)) && (bVar1 != 0x6f)) &&
                   ((bVar1 != 0x75 && (bVar1 != 0x78)))) && (bVar1 != 0x58)) {
            local_254 = 0;
            goto switchD_0080bb7c_caseD_0;
          }
        }
        else if (bVar8 == 0x68) {
          local_214 = local_214 | 0x20;
        }
        else if (bVar8 == 0x6c) {
          local_214 = local_214 | 0x10;
        }
        else if (bVar8 == 0x77) {
          local_214 = local_214 | 0x800;
        }
        break;
      case 7:
        if ((char)bVar8 < 'h') {
          if ((char)bVar8 < 'e') {
            if ((char)bVar8 < 'Y') {
              if (bVar8 == 0x58) {
LAB_0080c001:
                local_24c = 7;
LAB_0080c004:
                local_224 = (undefined1 *)0x10;
                if ((local_214 & 0x80) != 0) {
                  local_22b = (char)local_24c + 'Q';
                  local_22c = 0x30;
                  local_230 = 2;
                }
                goto LAB_0080be46;
              }
              if (bVar8 == 0x43) {
                if ((local_214 & 0x830) == 0) {
                  local_214 = local_214 | 0x800;
                }
                goto LAB_0080bdfb;
              }
              if ((bVar8 != 0x45) && (bVar8 != 0x47)) {
                if (bVar8 == 0x53) {
                  if ((local_214 & 0x830) == 0) {
                    local_214 = local_214 | 0x800;
                  }
                  goto LAB_0080bd84;
                }
                goto LAB_0080c14f;
              }
              local_250 = 1;
              bVar8 = bVar8 + 0x20;
              goto LAB_0080bdcf;
            }
            if (bVar8 == 0x5a) {
              pwVar5 = local_218 + 2;
              psVar2 = *(short **)local_218;
              local_218 = pwVar5;
              if ((psVar2 == (short *)0x0) ||
                 (local_220 = *(wchar_t **)(psVar2 + 2), local_220 == (wchar_t *)0x0)) {
                local_220 = (wchar_t *)PTR_s__null__00b49e4c;
                pwVar5 = (wchar_t *)PTR_s__null__00b49e4c;
                goto LAB_0080bf75;
              }
              local_224 = (undefined1 *)(int)*psVar2;
              if ((local_214 & 0x800) == 0) {
                local_240 = 0;
              }
              else {
                local_224 = (undefined1 *)((int)local_224 / 2);
                local_240 = 1;
              }
              goto LAB_0080c14c;
            }
            if (bVar8 == 99) {
LAB_0080bdfb:
              if ((local_214 & 0x810) == 0) {
                local_210[0] = (char)*local_218;
                local_224 = (undefined1 *)0x1;
                local_218 = local_218 + 2;
              }
              else {
                _WCh = *local_218;
                local_218 = local_218 + 2;
                local_224 = (undefined1 *)_wctomb(local_210,_WCh);
                if ((int)local_224 < 0) {
                  local_248 = 1;
                }
              }
              local_220 = (wchar_t *)local_210;
            }
            else if (bVar8 == 100) goto LAB_0080be3b;
          }
          else {
LAB_0080bdcf:
            local_214 = local_214 | 0x40;
            pwVar5 = (wchar_t *)local_210;
            local_220 = pwVar5;
            if (local_21c < 0) {
              local_21c = 6;
            }
            else if (local_21c == 0) {
              if (bVar8 == 0x67) {
                local_21c = 1;
              }
            }
            else {
              if (0x200 < local_21c) {
                local_21c = 0x200;
              }
              if (0xa3 < local_21c) {
                local_244 = _malloc(local_21c + 0x15d);
                if (local_244 == (wchar_t *)0x0) {
                  local_21c = 0xa3;
                }
                else {
                  pwVar5 = local_244;
                  local_220 = local_244;
                }
              }
            }
            local_264 = *(undefined4 *)local_218;
            local_260 = *(undefined4 *)(local_218 + 2);
            local_218 = local_218 + 4;
            (*(code *)PTR___cfltcvt_00b49d9c)
                      (&local_264,pwVar5,(int)(char)bVar8,local_21c,local_250);
            uVar4 = local_214 & 0x80;
            if ((uVar4 != 0) && (local_21c == 0)) {
              (*(code *)PTR___forcdecpt_00b49da8)(pwVar5);
            }
            if ((bVar8 == 0x67) && (uVar4 == 0)) {
              (*(code *)PTR___cropzeros_00b49da0)(pwVar5);
            }
            if ((char)*pwVar5 == '-') {
              local_214 = local_214 | 0x100;
              pwVar5 = (wchar_t *)((int)pwVar5 + 1);
              local_220 = pwVar5;
            }
LAB_0080bf75:
            local_224 = (undefined1 *)_strlen((char *)pwVar5);
LAB_0080c14c:
          }
LAB_0080c14f:
          uVar4 = local_214;
          if (local_248 == 0) {
            if ((local_214 & 0x40) != 0) {
              if ((local_214 & 0x100) == 0) {
                if ((local_214 & 1) == 0) {
                  if ((local_214 & 2) == 0) goto LAB_0080c187;
                  local_22c = 0x20;
                }
                else {
                  local_22c = 0x2b;
                }
              }
              else {
                local_22c = 0x2d;
              }
              local_230 = 1;
            }
LAB_0080c187:
            iVar7 = (local_23c - local_230) - (int)local_224;
            if ((local_214 & 0xc) == 0) {
              write_multi_char(0x20,iVar7,local_238);
            }
            uVar3 = local_238;
            write_string(local_230);
            if (((uVar4 & 8) != 0) && ((uVar4 & 4) == 0)) {
              write_multi_char(0x30,iVar7,uVar3);
            }
            if ((local_240 == 0) || ((int)local_224 < 1)) {
              write_string(local_224);
            }
            else {
              local_258 = local_224;
              pwVar5 = local_220;
              do {
                local_258 = local_258 + -1;
                iVar6 = _wctomb((char *)((int)&local_11 + 1),*pwVar5);
                pwVar5 = pwVar5 + 1;
                if (iVar6 < 1) break;
                write_string(iVar6);
              } while (local_258 != (undefined1 *)0x0);
            }
            if ((local_214 & 4) != 0) {
              write_multi_char(0x20,iVar7,local_238);
            }
          }
        }
        else {
          if (bVar8 == 0x69) {
LAB_0080be3b:
            local_214 = local_214 | 0x40;
LAB_0080be3f:
            local_224 = (undefined1 *)0xa;
LAB_0080be46:
            if ((local_214 & 0x8000) == 0) {
              if ((local_214 & 0x20) == 0) {
                uVar4 = *(uint *)local_218;
                if ((local_214 & 0x40) == 0) {
                  iVar7 = 0;
                  local_218 = local_218 + 2;
                  goto LAB_0080c099;
                }
              }
              else if ((local_214 & 0x40) == 0) {
                uVar4 = (uint)(ushort)*local_218;
              }
              else {
                uVar4 = (uint)*local_218;
              }
              iVar7 = (int)uVar4 >> 0x1f;
              local_218 = local_218 + 2;
            }
            else {
              uVar4 = *(uint *)local_218;
              iVar7 = *(int *)(local_218 + 2);
              local_218 = local_218 + 4;
            }
LAB_0080c099:
            if ((((local_214 & 0x40) != 0) && (iVar7 < 1)) && (iVar7 < 0)) {
              bVar10 = uVar4 != 0;
              uVar4 = -uVar4;
              iVar7 = -(iVar7 + (uint)bVar10);
              local_214 = local_214 | 0x100;
            }
            if ((local_214 & 0x8000) == 0) {
              iVar7 = 0;
            }
            lVar11 = CONCAT44(iVar7,uVar4);
            if (local_21c < 0) {
              local_21c = 1;
            }
            else {
              local_214 = local_214 & 0xfffffff7;
              if (0x200 < local_21c) {
                local_21c = 0x200;
              }
            }
            if (uVar4 == 0 && iVar7 == 0) {
              local_230 = 0;
            }
            pwVar5 = &local_11;
            while( true ) {
              puVar9 = (undefined1 *)lVar11;
              iVar7 = local_21c + -1;
              if ((local_21c < 1) && (lVar11 == 0)) break;
              local_21c = iVar7;
              lVar11 = __aulldvrm(lVar11,local_224,(int)local_224 >> 0x1f);
              iVar7 = extraout_ECX + 0x30;
              if (0x39 < iVar7) {
                iVar7 = iVar7 + local_24c;
              }
              *(char *)pwVar5 = (char)iVar7;
              pwVar5 = (wchar_t *)((int)pwVar5 + -1);
              local_258 = puVar9;
            }
            local_224 = local_1e4 + -(int)pwVar5 + 0x1d3;
            local_220 = (wchar_t *)((int)pwVar5 + 1);
            local_21c = iVar7;
            if (((local_214 & 0x200) != 0) &&
               ((*(char *)local_220 != '0' || (local_224 == (undefined1 *)0x0)))) {
              *(char *)pwVar5 = '0';
              local_224 = local_1e4 + -(int)pwVar5 + 0x1d4;
              local_220 = pwVar5;
              goto LAB_0080c14c;
            }
            goto LAB_0080c14f;
          }
          if (bVar8 != 0x6e) {
            if (bVar8 != 0x6f) {
              if (bVar8 == 0x70) {
                local_21c = 8;
                goto LAB_0080c001;
              }
              if (bVar8 == 0x73) {
LAB_0080bd84:
                iVar7 = local_21c;
                if (local_21c == -1) {
                  iVar7 = 0x7fffffff;
                }
                local_220 = *(wchar_t **)local_218;
                if ((local_214 & 0x810) == 0) {
                  if (local_220 == (wchar_t *)0x0) {
                    local_220 = (wchar_t *)PTR_s__null__00b49e4c;
                  }
                  for (pwVar5 = local_220;
                      (iVar7 != 0 && (iVar7 = iVar7 + -1, (char)*pwVar5 != '\0'));
                      pwVar5 = (wchar_t *)((int)pwVar5 + 1)) {
                  }
                  local_224 = (undefined1 *)((int)pwVar5 - (int)local_220);
                  local_218 = local_218 + 2;
                }
                else {
                  if (local_220 == (wchar_t *)0x0) {
                    local_220 = (wchar_t *)PTR_DAT_00b49e50;
                  }
                  local_240 = 1;
                  for (pwVar5 = local_220; (iVar7 != 0 && (iVar7 = iVar7 + -1, *pwVar5 != L'\0'));
                      pwVar5 = pwVar5 + 1) {
                  }
                  local_224 = (undefined1 *)((int)pwVar5 - (int)local_220 >> 1);
                  local_218 = local_218 + 2;
                }
                goto LAB_0080c14c;
              }
              if (bVar8 != 0x75) {
                if (bVar8 != 0x78) goto LAB_0080c14f;
                local_24c = 0x27;
                goto LAB_0080c004;
              }
              goto LAB_0080be3f;
            }
            local_224 = (undefined1 *)0x8;
            if ((local_214 & 0x80) != 0) {
              local_214 = local_214 | 0x200;
            }
            goto LAB_0080be46;
          }
          if ((local_214 & 0x20) == 0) {
            **(int **)local_218 = local_228;
          }
          else {
            *(undefined2 *)*(int **)local_218 = (undefined2)local_228;
          }
          local_248 = 1;
          local_218 = local_218 + 2;
        }
        if (local_244 != (wchar_t *)0x0) {
          _free(local_244);
          return extraout_EAX;
        }
      }
      bVar8 = *local_234;
      if (bVar8 == 0) {
        return local_228;
      }
      param_2 = local_234;
    }
  }
  return local_228;
}


// ==== ___ascii_stricmp @ 0x0080c2b0 ====

/* Library Function - Single Match
    ___ascii_stricmp
   
   Library: Visual Studio 2003 Release */

int __cdecl ___ascii_stricmp(char *_Str1,char *_Str2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  
  bVar3 = 0xff;
  do {
    do {
      cVar4 = '\0';
      if (bVar3 == 0) goto LAB_0080c2f6;
      bVar3 = *_Str2;
      _Str2 = _Str2 + 1;
      bVar2 = *_Str1;
      _Str1 = _Str1 + 1;
    } while (bVar2 == bVar3);
    bVar1 = bVar3 + 0xbf + (-((byte)(bVar3 + 0xbf) < 0x1a) & 0x20U) + 0x41;
    bVar2 = bVar2 + 0xbf;
    bVar3 = bVar2 + (-(bVar2 < 0x1a) & 0x20U) + 0x41;
  } while (bVar3 == bVar1);
  cVar4 = (bVar3 < bVar1) * -2 + '\x01';
LAB_0080c2f6:
  return (int)cVar4;
}


// ==== __msize @ 0x0080c2fe ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __msize
   
   Library: Visual Studio 2003 Release */

size_t __cdecl __msize(void *_Memory)

{
  int iVar1;
  SIZE_T SVar2;
  size_t local_20;
  
  if (DAT_00b60f7c == 3) {
    __lock(4);
    iVar1 = ___sbh_find_block(_Memory);
    if (iVar1 != 0) {
      local_20 = *(int *)((int)_Memory + -4) - 9;
    }
    FUN_0080c36b();
    if (iVar1 != 0) {
      return local_20;
    }
  }
  SVar2 = HeapSize(DAT_00b60f78,0,_Memory);
  return SVar2;
}


// ==== FUN_0080c368 @ 0x0080c368 ====

void FUN_0080c368(void)

{
  FUN_00806c2f(4);
  return;
}


// ==== FUN_0080c36b @ 0x0080c36b ====

void FUN_0080c36b(void)

{
  FUN_00806c2f(4);
  return;
}


// ==== FUN_0080c374 @ 0x0080c374 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

void FUN_0080c374(void)

{
  char cVar1;
  char cVar2;
  UINT CodePage;
  char *_Str1;
  int iVar3;
  size_t sVar4;
  long lVar5;
  DWORD DVar6;
  char *_Str;
  int local_20 [3];
  undefined1 local_14 [8];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00a0b428;
  uStack_c = 0x80c380;
  __lock(7);
  CodePage = DAT_00b5ca74;
  local_8 = (undefined *)0x0;
  DAT_00b5cb64 = 0;
  DAT_00b49f04 = 0xffffffff;
  DAT_00b49ef8 = 0xffffffff;
  _Str1 = (char *)__getenv_lk(&DAT_00a0b424);
  if ((_Str1 == (char *)0x0) || (*_Str1 == '\0')) {
    if (DAT_00b5cb68 != (char *)0x0) {
      _free(DAT_00b5cb68);
      return;
    }
    DVar6 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_00b5cab8);
    if (DVar6 != 0xffffffff) {
      DAT_00b5cb64 = 1;
      DAT_00b49e60 = DAT_00b5cab8 * 0x3c;
      if (DAT_00b5cafe != 0) {
        DAT_00b49e60 = DAT_00b49e60 + DAT_00b5cb0c * 0x3c;
      }
      if ((DAT_00b5cb52 == 0) || (DAT_00b5cb60 == 0)) {
        DAT_00b49e64 = 0;
        DAT_00b49e68 = 0;
      }
      else {
        DAT_00b49e64 = 1;
        DAT_00b49e68 = (DAT_00b5cb60 - DAT_00b5cb0c) * 0x3c;
      }
      iVar3 = WideCharToMultiByte(CodePage,0,(LPCWSTR)&DAT_00b5cabc,-1,PTR_DAT_00b49ef0,0x3f,
                                  (LPCSTR)0x0,local_20);
      if ((iVar3 == 0) || (local_20[0] != 0)) {
        *PTR_DAT_00b49ef0 = 0;
      }
      else {
        PTR_DAT_00b49ef0[0x3f] = 0;
      }
      iVar3 = WideCharToMultiByte(CodePage,0,(LPCWSTR)&DAT_00b5cb10,-1,PTR_DAT_00b49ef4,0x3f,
                                  (LPCSTR)0x0,local_20);
      if ((iVar3 == 0) || (local_20[0] != 0)) {
        *PTR_DAT_00b49ef4 = 0;
      }
      else {
        PTR_DAT_00b49ef4[0x3f] = 0;
      }
    }
  }
  else {
    if (DAT_00b5cb68 != (char *)0x0) {
      iVar3 = _strcmp(_Str1,DAT_00b5cb68);
      if (iVar3 == 0) goto LAB_0080c578;
      if (DAT_00b5cb68 != (char *)0x0) {
        _free(DAT_00b5cb68);
        return;
      }
    }
    sVar4 = _strlen(_Str1);
    DAT_00b5cb68 = _malloc(sVar4 + 1);
    if (DAT_00b5cb68 != (char *)0x0) {
      FUN_00809180(DAT_00b5cb68,_Str1);
      local_8 = (undefined *)0xffffffff;
      FUN_0080c58f();
      _strncpy(PTR_DAT_00b49ef0,_Str1,3);
      PTR_DAT_00b49ef0[3] = 0;
      _Str = _Str1 + 3;
      cVar1 = *_Str;
      if (cVar1 == '-') {
        _Str = _Str1 + 4;
      }
      lVar5 = _atol(_Str);
      DAT_00b49e60 = lVar5 * 0xe10;
      for (; (cVar2 = *_Str, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':')))); _Str = _Str + 1) {
      }
      if (*_Str == ':') {
        _Str = _Str + 1;
        lVar5 = _atol(_Str);
        DAT_00b49e60 = DAT_00b49e60 + lVar5 * 0x3c;
        for (; ('/' < *_Str && (*_Str < ':')); _Str = _Str + 1) {
        }
        if (*_Str == ':') {
          _Str = _Str + 1;
          lVar5 = _atol(_Str);
          DAT_00b49e60 = DAT_00b49e60 + lVar5;
          for (; ('/' < *_Str && (*_Str < ':')); _Str = _Str + 1) {
          }
        }
      }
      if (cVar1 == '-') {
        DAT_00b49e60 = -DAT_00b49e60;
      }
      DAT_00b49e64 = (int)*_Str;
      if (DAT_00b49e64 == 0) {
        *PTR_DAT_00b49ef4 = 0;
        return;
      }
      _strncpy(PTR_DAT_00b49ef4,_Str,3);
      PTR_DAT_00b49ef4[3] = 0;
      return;
    }
  }
LAB_0080c578:
  __local_unwind2(local_14,0xffffffff);
  return;
}


// ==== FUN_0080c58f @ 0x0080c58f ====

void FUN_0080c58f(void)

{
  FUN_00806c2f(7);
  return;
}


// ==== cvtdate @ 0x0080c61c ====

/* Library Function - Single Match
    _cvtdate
   
   Library: Visual Studio 2003 Release */

int __cdecl
cvtdate(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
       int param_8,int param_9)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  iVar2 = param_3 % 4;
  if (param_2 == 1) {
    if (((iVar2 == 0) && (param_3 % 100 != 0)) || ((param_3 + 0x76c) % 400 == 0)) {
      puVar3 = (&PTR_DAT_00b4a278)[in_EAX];
    }
    else {
      puVar3 = *(undefined **)(&DAT_00b4a2ac + in_EAX * 4);
    }
    puVar4 = puVar3 + 1;
    iVar1 = (param_4 * 7 -
            (int)(puVar4 + param_3 * 0x16d + -0x63db +
                           ((param_3 + 299) / 400 - (param_3 + -1) / 100) + (param_3 + -1) / 4) % 7)
            + param_5;
    if ((int)(puVar4 + param_3 * 0x16d + -0x63db +
                       ((param_3 + 299) / 400 - (param_3 + -1) / 100) + (param_3 + -1) / 4) % 7 <=
        param_5) {
      puVar4 = puVar3 + -6;
    }
    puVar4 = puVar4 + iVar1;
    if (param_4 == 5) {
      if (((iVar2 == 0) && (param_3 % 100 != 0)) || ((param_3 + 0x76c) % 400 == 0)) {
        iVar1 = *(int *)(&DAT_00b4a27c + in_EAX * 4);
      }
      else {
        iVar1 = (&DAT_00b4a2b0)[in_EAX];
      }
      if (iVar1 < (int)puVar4) {
        puVar4 = puVar4 + -7;
      }
    }
  }
  else {
    if (((iVar2 == 0) && (iVar1 = param_3 / 100, param_3 % 100 != 0)) ||
       (iVar1 = (param_3 + 0x76c) / 400, (param_3 + 0x76c) % 400 == 0)) {
      puVar4 = (&PTR_DAT_00b4a278)[in_EAX];
    }
    else {
      puVar4 = *(undefined **)(&DAT_00b4a2ac + in_EAX * 4);
    }
    puVar4 = puVar4 + param_6;
  }
  iVar2 = (in_ECX * 0x3c + param_7) * 0x3c;
  if (param_1 == 1) {
    DAT_00b49ef8 = param_3;
    DAT_00b49efc = puVar4;
    DAT_00b49f00 = (iVar2 + param_8) * 1000 + param_9;
    return iVar1;
  }
  DAT_00b49f0c = (iVar2 + DAT_00b49e68 + param_8) * 1000 + param_9;
  if (DAT_00b49f0c < 0) {
    DAT_00b49f0c = DAT_00b49f0c + 86400000;
    DAT_00b49f08 = puVar4 + -1;
  }
  else {
    iVar1 = 86400000;
    if (DAT_00b49f0c < 86400000) {
      DAT_00b49f04 = param_3;
      DAT_00b49f08 = puVar4;
      return 86400000;
    }
    DAT_00b49f0c = DAT_00b49f0c + -86400000;
    DAT_00b49f08 = puVar4 + 1;
  }
  DAT_00b49f04 = param_3;
  return iVar1;
}


// ==== __isindst_lk @ 0x0080c7d4 ====

/* Library Function - Single Match
    __isindst_lk
   
   Library: Visual Studio 2003 Release */

bool __isindst_lk(void)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int *unaff_EBX;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  if (DAT_00b49e64 == 0) {
    return false;
  }
  iVar1 = unaff_EBX[5];
  if ((iVar1 != DAT_00b49ef8) || (iVar1 != DAT_00b49f04)) {
    if (DAT_00b5cb64 == 0) {
      cvtdate(1,1,iVar1,1,0,0,0,0,0);
      cvtdate(0,1,iVar1,5,0,0,0,0,0);
    }
    else {
      if (DAT_00b5cb50 != 0) {
        uVar5 = 0;
        uVar4 = 0;
        uVar6 = DAT_00b5cb56;
      }
      else {
        uVar5 = DAT_00b5cb54;
        uVar4 = DAT_00b5cb56;
        uVar6 = 0;
      }
      cvtdate(1,DAT_00b5cb50 == 0,iVar1,uVar4,uVar5,uVar6,DAT_00b5cb5a,DAT_00b5cb5c,DAT_00b5cb5e);
      if (DAT_00b5cafc != 0) {
        uVar5 = 0;
        uVar4 = 0;
        uVar6 = DAT_00b5cb02;
      }
      else {
        uVar5 = DAT_00b5cb00;
        uVar4 = DAT_00b5cb02;
        uVar6 = 0;
      }
      cvtdate(0,DAT_00b5cafc == 0,iVar1,uVar4,uVar5,uVar6,DAT_00b5cb06,DAT_00b5cb08,DAT_00b5cb0a);
    }
  }
  iVar1 = unaff_EBX[7];
  if (DAT_00b49efc < DAT_00b49f08) {
    if ((iVar1 < DAT_00b49efc) || (DAT_00b49f08 < iVar1)) {
      return false;
    }
    if ((iVar1 <= DAT_00b49efc) || (DAT_00b49f08 <= iVar1)) {
LAB_0080c927:
      iVar3 = ((unaff_EBX[2] * 0x3c + unaff_EBX[1]) * 0x3c + *unaff_EBX) * 1000;
      if (iVar1 == DAT_00b49efc) {
        bVar2 = DAT_00b49f00 <= iVar3;
      }
      else {
        bVar2 = iVar3 < DAT_00b49f0c;
      }
      return bVar2;
    }
  }
  else if ((DAT_00b49f08 <= iVar1) && (iVar1 <= DAT_00b49efc)) {
    if ((DAT_00b49f08 < iVar1) && (iVar1 < DAT_00b49efc)) {
      return false;
    }
    goto LAB_0080c927;
  }
  return true;
}


// ==== ___tzset @ 0x0080c95b ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___tzset
   
   Library: Visual Studio 2003 Release */

void __cdecl ___tzset(void)

{
  if (DAT_00b5cb6c == 0) {
    __lock(6);
    if (DAT_00b5cb6c == 0) {
      FUN_0080c374();
      DAT_00b5cb6c = DAT_00b5cb6c + 1;
    }
    FUN_0080c99e();
  }
  return;
}


// ==== FUN_0080c99e @ 0x0080c99e ====

void FUN_0080c99e(void)

{
  FUN_00806c2f(6);
  return;
}


// ==== __isindst @ 0x0080c9a7 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __isindst
   
   Library: Visual Studio 2003 Release */

int __cdecl __isindst(tm *_Time)

{
  int iVar1;
  
  __lock(6);
  iVar1 = __isindst_lk();
  FUN_0080c9dc();
  return iVar1;
}


// ==== FUN_0080c9dc @ 0x0080c9dc ====

void FUN_0080c9dc(void)

{
  FUN_00806c2f(6);
  return;
}


// ==== __resetstkoflw @ 0x0080c9e5 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* Library Function - Single Match
    __resetstkoflw
   
   Library: Visual Studio 2003 Release */

int __cdecl __resetstkoflw(void)

{
  SIZE_T SVar1;
  BOOL BVar2;
  LPCVOID pvVar3;
  LPCVOID pvVar4;
  undefined4 uStack_60;
  _SYSTEM_INFO local_50;
  _MEMORY_BASIC_INFORMATION local_2c;
  DWORD local_10;
  SIZE_T local_c;
  LPCVOID local_8;
  
  uStack_60 = 0x80c9f6;
  SVar1 = VirtualQuery(&uStack_60,&local_2c,0x1c);
  if (SVar1 != 0) {
    GetSystemInfo(&local_50);
    pvVar4 = (LPCVOID)((~(local_50.dwPageSize - 1) & (uint)&uStack_60) - local_50.dwPageSize);
    pvVar3 = (LPCVOID)(((-(uint)(DAT_00b5c720 != 1) & 0xfffffff1) + 0x11) * local_50.dwPageSize +
                      (int)local_2c.AllocationBase);
    local_c = local_50.dwPageSize;
    if (pvVar3 <= pvVar4) {
      if (DAT_00b5c720 == 1) {
        local_8 = pvVar4;
      }
      else {
        local_8 = local_2c.AllocationBase;
        do {
          SVar1 = VirtualQuery(local_8,&local_2c,0x1c);
          if (SVar1 == 0) {
            return 0;
          }
          local_8 = (LPCVOID)((int)local_8 + local_2c.RegionSize);
        } while ((local_2c.State & 0x1000) == 0);
        local_8 = local_2c.BaseAddress;
        if ((local_2c.Protect._1_1_ & 1) != 0) {
          return 1;
        }
        if (pvVar4 < local_2c.BaseAddress) {
          return 0;
        }
        if (local_2c.BaseAddress < pvVar3) {
          local_8 = pvVar3;
        }
        VirtualAlloc(local_8,local_c,0x1000,4);
      }
      BVar2 = VirtualProtect(local_8,local_c,(-(uint)(DAT_00b5c720 != 1) & 0x103) + 1,&local_10);
      return BVar2;
    }
  }
  return 0;
}


// ==== __wchartodigit @ 0x0080cac8 ====

/* Library Function - Single Match
    __wchartodigit
   
   Library: Visual Studio 2003 Release */

int __wchartodigit(ushort param_1)

{
  int iVar1;
  bool bVar2;
  
  if (0x2f < param_1) {
    if (param_1 < 0x3a) {
      return param_1 - 0x30;
    }
    iVar1 = 0xff10;
    if (param_1 < 0xff10) {
      iVar1 = 0x660;
      if (param_1 < 0x660) {
        return -1;
      }
      if (param_1 < 0x66a) goto LAB_0080cc34;
      iVar1 = 0x6f0;
      if (param_1 < 0x6f0) {
        return -1;
      }
      if (param_1 < 0x6fa) goto LAB_0080cc34;
      iVar1 = 0x966;
      if (param_1 < 0x966) {
        return -1;
      }
      if (param_1 < 0x970) goto LAB_0080cc34;
      iVar1 = 0x9e6;
      if (param_1 < 0x9e6) {
        return -1;
      }
      if (param_1 < 0x9f0) goto LAB_0080cc34;
      iVar1 = 0xa66;
      if (param_1 < 0xa66) {
        return -1;
      }
      if (param_1 < 0xa70) goto LAB_0080cc34;
      iVar1 = 0xae6;
      if (param_1 < 0xae6) {
        return -1;
      }
      if (param_1 < 0xaf0) goto LAB_0080cc34;
      iVar1 = 0xb66;
      if (param_1 < 0xb66) {
        return -1;
      }
      if (param_1 < 0xb70) goto LAB_0080cc34;
      iVar1 = 0xc66;
      if (param_1 < 0xc66) {
        return -1;
      }
      if (param_1 < 0xc70) goto LAB_0080cc34;
      iVar1 = 0xce6;
      if (param_1 < 0xce6) {
        return -1;
      }
      if (param_1 < 0xcf0) goto LAB_0080cc34;
      iVar1 = 0xd66;
      if (param_1 < 0xd66) {
        return -1;
      }
      if (param_1 < 0xd70) goto LAB_0080cc34;
      iVar1 = 0xe50;
      if (param_1 < 0xe50) {
        return -1;
      }
      if (param_1 < 0xe5a) goto LAB_0080cc34;
      iVar1 = 0xed0;
      if (param_1 < 0xed0) {
        return -1;
      }
      if (param_1 < 0xeda) goto LAB_0080cc34;
      iVar1 = 0xf20;
      if (param_1 < 0xf20) {
        return -1;
      }
      if (param_1 < 0xf2a) goto LAB_0080cc34;
      iVar1 = 0x1040;
      if (param_1 < 0x1040) {
        return -1;
      }
      if (param_1 < 0x104a) goto LAB_0080cc34;
      iVar1 = 0x17e0;
      if (param_1 < 0x17e0) {
        return -1;
      }
      if (param_1 < 0x17ea) goto LAB_0080cc34;
      iVar1 = 0x1810;
      if (param_1 < 0x1810) {
        return -1;
      }
      bVar2 = param_1 < 0x181a;
    }
    else {
      bVar2 = param_1 < 0xff1a;
    }
    if (bVar2) {
LAB_0080cc34:
      return (uint)param_1 - iVar1;
    }
  }
  return -1;
}


// ==== FUN_0080cc3e @ 0x0080cc3e ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

uint FUN_0080cc3e(LCID param_1,uint param_2,LPCSTR param_3,int param_4,LPSTR param_5,int param_6,
                 UINT param_7,int param_8)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  LPCSTR pCVar5;
  undefined1 *puVar6;
  int iVar7;
  uint extraout_EAX;
  uint extraout_EAX_00;
  UINT UVar8;
  size_t _Size;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint uVar13;
  size_t *lpDestStr;
  undefined1 uStack00000000;
  UINT UStackY_78;
  undefined4 local_50;
  size_t local_4c [6];
  LPSTR local_34;
  LPCSTR local_2c;
  undefined1 *local_24;
  undefined1 *local_20;
  
  if (DAT_00b5cb70 == 0) {
    UStackY_78 = 0x80cc6b;
    iVar3 = LCMapStringW(0,0x100,(LPCWSTR)&DAT_0099cdc8,1,(LPWSTR)0x0,0);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_00b5cb70 = 2;
      }
    }
    else {
      DAT_00b5cb70 = 1;
    }
  }
  if (0 < param_4) {
    pCVar5 = param_3;
    iVar3 = param_4;
    do {
      iVar3 = iVar3 + -1;
      if (*pCVar5 == '\0') goto LAB_0080cca4;
      pCVar5 = pCVar5 + 1;
    } while (iVar3 != 0);
    iVar3 = -1;
LAB_0080cca4:
    param_4 = param_4 + (-1 - iVar3);
  }
  if ((DAT_00b5cb70 != 2) && (DAT_00b5cb70 != 0)) {
    if (DAT_00b5cb70 == 1) {
      uVar13 = 0;
      bVar2 = false;
      bVar1 = false;
      if (param_7 == 0) {
        param_7 = DAT_00b5ca74;
      }
      UStackY_78 = 0x80cd04;
      iVar3 = MultiByteToWideChar(param_7,(uint)(param_8 != 0) * 8 + 1,param_3,param_4,(LPWSTR)0x0,0
                                 );
      if (iVar3 != 0) {
        puVar6 = (undefined1 *)(iVar3 * 2 + 3U & 0xfffffffc);
        iVar7 = -(int)puVar6;
        local_20 = (undefined1 *)((int)local_4c + iVar7 + -0x10);
        if (local_4c + -4 == (size_t *)puVar6) {
          *(int *)((int)local_4c + iVar7 + -0x14) = iVar3 * 2;
          *(undefined4 *)((int)local_4c + iVar7 + -0x18) = 0x80cd5d;
          local_20 = _malloc(*(size_t *)((int)local_4c + iVar7 + -0x14));
          if (local_20 == (void *)0x0) {
            return 0;
          }
          bVar2 = true;
        }
        *(int *)((int)local_4c + iVar7 + -0x14) = iVar3;
        *(undefined1 **)((int)local_4c + iVar7 + -0x18) = local_20;
        *(int *)((int)local_4c + iVar7 + -0x1c) = param_4;
        *(LPCSTR *)((int)local_4c + iVar7 + -0x20) = param_3;
        *(undefined4 *)((int)local_4c + iVar7 + -0x24) = 1;
        *(UINT *)((int)local_4c + iVar7 + -0x28) = param_7;
        puVar9 = (undefined1 *)((int)local_4c + iVar7 + -0x2c);
        *(undefined4 *)((int)local_4c + iVar7 + -0x2c) = 0x80cd85;
        iVar7 = MultiByteToWideChar(*(UINT *)((int)local_4c + iVar7 + -0x28),
                                    *(DWORD *)((int)local_4c + iVar7 + -0x24),
                                    *(LPCSTR *)((int)local_4c + iVar7 + -0x20),
                                    *(int *)((int)local_4c + iVar7 + -0x1c),
                                    *(LPWSTR *)((int)local_4c + iVar7 + -0x18),
                                    *(int *)((int)local_4c + iVar7 + -0x14));
        puVar6 = puVar9;
        if (iVar7 != 0) {
          *(undefined4 *)(puVar9 + -4) = 0;
          *(undefined4 *)(puVar9 + -8) = 0;
          *(int *)(puVar9 + -0xc) = iVar3;
          *(undefined1 **)(puVar9 + -0x10) = local_20;
          *(uint *)(puVar9 + -0x14) = param_2;
          *(LCID *)(puVar9 + -0x18) = param_1;
          puVar10 = puVar9 + -0x1c;
          *(undefined4 *)(puVar9 + -0x1c) = 0x80cd9f;
          uVar13 = LCMapStringW(*(LCID *)(puVar9 + -0x18),*(DWORD *)(puVar9 + -0x14),
                                *(LPCWSTR *)(puVar9 + -0x10),*(int *)(puVar9 + -0xc),
                                *(LPWSTR *)(puVar9 + -8),*(int *)(puVar9 + -4));
          puVar6 = puVar10;
          if (uVar13 != 0) {
            if ((param_2 & 0x400) == 0) {
              puVar6 = (undefined1 *)(uVar13 * 2 + 3 & 0xfffffffc);
              *(undefined4 *)(puVar10 + -4) = 0x80cdf4;
              iVar7 = -(int)puVar6;
              local_24 = puVar10 + iVar7;
              if (puVar10 == puVar6) {
                *(uint *)(puVar10 + iVar7 + -4) = uVar13 * 2;
                *(undefined4 *)(puVar10 + iVar7 + -8) = 0x80ce2b;
                local_24 = _malloc(*(size_t *)(puVar10 + iVar7 + -4));
                puVar6 = puVar10 + iVar7;
                if (local_24 == (undefined1 *)0x0) goto LAB_0080ce73;
                bVar1 = true;
              }
              *(uint *)(puVar10 + iVar7 + -4) = uVar13;
              *(undefined1 **)(puVar10 + iVar7 + -8) = local_24;
              *(int *)(puVar10 + iVar7 + -0xc) = iVar3;
              *(undefined1 **)(puVar10 + iVar7 + -0x10) = local_20;
              *(uint *)(puVar10 + iVar7 + -0x14) = param_2;
              *(LCID *)(puVar10 + iVar7 + -0x18) = param_1;
              puVar12 = puVar10 + iVar7 + -0x1c;
              *(undefined4 *)(puVar10 + iVar7 + -0x1c) = 0x80ce4e;
              iVar3 = LCMapStringW(*(LCID *)(puVar10 + iVar7 + -0x18),
                                   *(DWORD *)(puVar10 + iVar7 + -0x14),
                                   *(LPCWSTR *)(puVar10 + iVar7 + -0x10),
                                   *(int *)(puVar10 + iVar7 + -0xc),
                                   *(LPWSTR *)(puVar10 + iVar7 + -8),*(int *)(puVar10 + iVar7 + -4))
              ;
              puVar6 = puVar12;
              if (iVar3 != 0) {
                *(undefined4 *)(puVar12 + -4) = 0;
                *(undefined4 *)(puVar12 + -8) = 0;
                if (param_6 == 0) {
                  *(undefined4 *)(puVar12 + -0xc) = 0;
                  *(undefined4 *)(puVar12 + -0x10) = 0;
                }
                else {
                  *(int *)(puVar12 + -0xc) = param_6;
                  *(LPSTR *)(puVar12 + -0x10) = param_5;
                }
                *(uint *)(puVar12 + -0x14) = uVar13;
                *(undefined1 **)(puVar12 + -0x18) = local_24;
                *(undefined4 *)(puVar12 + -0x1c) = 0;
                *(UINT *)(puVar12 + -0x20) = param_7;
                puVar6 = puVar12 + -0x24;
                *(undefined4 *)(puVar12 + -0x24) = 0x80ce71;
                uVar13 = WideCharToMultiByte(*(UINT *)(puVar12 + -0x20),*(DWORD *)(puVar12 + -0x1c),
                                             *(LPCWSTR *)(puVar12 + -0x18),*(int *)(puVar12 + -0x14)
                                             ,*(LPSTR *)(puVar12 + -0x10),*(int *)(puVar12 + -0xc),
                                             *(LPCSTR *)(puVar12 + -8),*(LPBOOL *)(puVar12 + -4));
              }
            }
            else if ((param_6 != 0) && ((int)uVar13 <= param_6)) {
              *(int *)(puVar10 + -4) = param_6;
              *(LPSTR *)(puVar10 + -8) = param_5;
              *(int *)(puVar10 + -0xc) = iVar3;
              *(undefined1 **)(puVar10 + -0x10) = local_20;
              *(uint *)(puVar10 + -0x14) = param_2;
              *(LCID *)(puVar10 + -0x18) = param_1;
              puVar11 = puVar10 + -0x1c;
              *(undefined4 *)(puVar10 + -0x1c) = 0x80cdda;
              LCMapStringW(*(LCID *)(puVar10 + -0x18),*(DWORD *)(puVar10 + -0x14),
                           *(LPCWSTR *)(puVar10 + -0x10),*(int *)(puVar10 + -0xc),
                           *(LPWSTR *)(puVar10 + -8),*(int *)(puVar10 + -4));
              puVar6 = puVar11;
            }
          }
        }
LAB_0080ce73:
        if (bVar1) {
          *(undefined1 **)(puVar6 + -4) = local_24;
          *(undefined4 *)(puVar6 + -8) = 0x80ce80;
          _free(*(void **)(puVar6 + -4));
          return extraout_EAX;
        }
        if (!bVar2) {
          return uVar13;
        }
        *(undefined1 **)(puVar6 + -4) = local_20;
        *(undefined4 *)(puVar6 + -8) = 0x80ce8e;
        _free(*(void **)(puVar6 + -4));
        return extraout_EAX_00;
      }
    }
    return 0;
  }
  local_2c = (LPCSTR)0x0;
  lpDestStr = (size_t *)0x0;
  local_34 = (LPSTR)0x0;
  bVar1 = false;
  if (param_1 == 0) {
    param_1 = DAT_00b5ca64;
  }
  if (param_7 == 0) {
    param_7 = DAT_00b5ca74;
  }
  UVar8 = FUN_00812dc7();
  if (UVar8 == 0xffffffff) {
    return 0;
  }
  if (UVar8 == param_7) {
    UStackY_78 = 0x80cfe6;
    local_50 = LCMapStringA(param_1,param_2,param_3,param_4,param_5,param_6);
    goto LAB_0080cfe8;
  }
  UStackY_78 = 0x80ceee;
  local_2c = (LPCSTR)FUN_00812e0e();
  if (local_2c == (LPCSTR)0x0) {
    return 0;
  }
  UStackY_78 = 0x80cf0a;
  _Size = LCMapStringA(param_1,param_2,local_2c,param_4,(LPSTR)0x0,0);
  if (_Size != 0) {
    lpDestStr = local_4c + -4;
    _memset(local_4c + -4,0,_Size);
    if (&uStack00000000 == (undefined1 *)0x5c) {
      lpDestStr = _malloc(_Size);
      if (lpDestStr != (size_t *)0x0) {
        _memset(lpDestStr,0,_Size);
        bVar1 = true;
        goto LAB_0080cf75;
      }
    }
    else {
LAB_0080cf75:
      UStackY_78 = 0x80cf8b;
      uVar13 = LCMapStringA(param_1,param_2,local_2c,param_4,(LPSTR)lpDestStr,_Size);
      if (uVar13 != 0) {
        UStackY_78 = 0x80cfac;
        local_34 = (LPSTR)FUN_00812e0e();
        local_50 = -(uint)(local_34 != (LPSTR)0x0) & uVar13;
        goto LAB_0080cfc0;
      }
    }
    local_50 = 0;
  }
LAB_0080cfc0:
  if (bVar1) {
    _free(lpDestStr);
    return extraout_EAX_01;
  }
LAB_0080cfe8:
  if (local_2c != (LPCSTR)0x0) {
    _free(local_2c);
    return extraout_EAX_02;
  }
  if ((local_34 == (LPSTR)0x0) || (param_5 == local_34)) {
    return local_50;
  }
  _free(local_34);
  return extraout_EAX_03;
}


// ==== FUN_0080cd38 @ 0x0080cd38 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

int FUN_0080cd38(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int extraout_EAX;
  int extraout_EAX_00;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(iVar3 + -4) = 0x80cd40;
  __resetstkoflw();
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar4 = *(int *)(unaff_EBP + -0x2c);
  iVar1 = *(int *)(unaff_EBP + -0x34);
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    *(int *)(iVar3 + -4) = iVar1 * 2;
    *(undefined4 *)(iVar3 + -8) = 0x80cd5d;
    pvVar2 = _malloc(*(size_t *)(iVar3 + -4));
    *(void **)(unaff_EBP + -0x1c) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      iVar4 = 0;
      goto LAB_0080d00b;
    }
    *(undefined4 *)(unaff_EBP + -0x3c) = 1;
  }
  *(int *)(iVar3 + -4) = iVar1;
  *(undefined4 *)(iVar3 + -8) = *(undefined4 *)(unaff_EBP + -0x1c);
  *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(iVar3 + -0x14) = 1;
  *(undefined4 *)(iVar3 + -0x18) = *(undefined4 *)(unaff_EBP + 0x20);
  puVar5 = (undefined1 *)(iVar3 + -0x1c);
  *(undefined4 *)(iVar3 + -0x1c) = 0x80cd85;
  iVar3 = MultiByteToWideChar(*(UINT *)(iVar3 + -0x18),*(DWORD *)(iVar3 + -0x14),
                              *(LPCSTR *)(iVar3 + -0x10),*(int *)(iVar3 + -0xc),
                              *(LPWSTR *)(iVar3 + -8),*(int *)(iVar3 + -4));
  puVar9 = puVar5;
  if (iVar3 != 0) {
    *(undefined4 *)(puVar5 + -4) = 0;
    *(undefined4 *)(puVar5 + -8) = 0;
    *(int *)(puVar5 + -0xc) = iVar1;
    *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + -0x1c);
    *(undefined4 *)(puVar5 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(puVar5 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
    puVar6 = puVar5 + -0x1c;
    *(undefined4 *)(puVar5 + -0x1c) = 0x80cd9f;
    iVar4 = LCMapStringW(*(LCID *)(puVar5 + -0x18),*(DWORD *)(puVar5 + -0x14),
                         *(LPCWSTR *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                         *(LPWSTR *)(puVar5 + -8),*(int *)(puVar5 + -4));
    *(int *)(unaff_EBP + -0x2c) = iVar4;
    puVar9 = puVar6;
    if (iVar4 != 0) {
      if ((*(byte *)(unaff_EBP + 0xd) & 4) == 0) {
        *(undefined4 *)(unaff_EBP + -4) = 2;
        *(undefined4 *)(puVar6 + -4) = 0x80cdf4;
        iVar3 = -(iVar4 * 2 + 3U & 0xfffffffc);
        *(int *)(unaff_EBP + -0x18) = (int)puVar6 + iVar3;
        *(int *)(unaff_EBP + -0x20) = (int)puVar6 + iVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (*(int *)(unaff_EBP + -0x20) == 0) {
          *(int *)(puVar6 + iVar3 + -4) = iVar4 * 2;
          *(undefined4 *)(puVar6 + iVar3 + -8) = 0x80ce2b;
          pvVar2 = _malloc(*(size_t *)(puVar6 + iVar3 + -4));
          *(void **)(unaff_EBP + -0x20) = pvVar2;
          puVar9 = puVar6 + iVar3;
          if (pvVar2 == (void *)0x0) goto LAB_0080ce73;
          *(undefined4 *)(unaff_EBP + -0x38) = 1;
        }
        *(int *)(puVar6 + iVar3 + -4) = iVar4;
        *(undefined4 *)(puVar6 + iVar3 + -8) = *(undefined4 *)(unaff_EBP + -0x20);
        *(int *)(puVar6 + iVar3 + -0xc) = iVar1;
        *(undefined4 *)(puVar6 + iVar3 + -0x10) = *(undefined4 *)(unaff_EBP + -0x1c);
        *(undefined4 *)(puVar6 + iVar3 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(puVar6 + iVar3 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
        puVar8 = puVar6 + iVar3 + -0x1c;
        *(undefined4 *)(puVar6 + iVar3 + -0x1c) = 0x80ce4e;
        iVar3 = LCMapStringW(*(LCID *)(puVar6 + iVar3 + -0x18),*(DWORD *)(puVar6 + iVar3 + -0x14),
                             *(LPCWSTR *)(puVar6 + iVar3 + -0x10),*(int *)(puVar6 + iVar3 + -0xc),
                             *(LPWSTR *)(puVar6 + iVar3 + -8),*(int *)(puVar6 + iVar3 + -4));
        puVar9 = puVar8;
        if (iVar3 != 0) {
          *(undefined4 *)(puVar8 + -4) = 0;
          *(undefined4 *)(puVar8 + -8) = 0;
          if (*(int *)(unaff_EBP + 0x1c) == 0) {
            *(undefined4 *)(puVar8 + -0xc) = 0;
            *(undefined4 *)(puVar8 + -0x10) = 0;
          }
          else {
            *(undefined4 *)(puVar8 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
            *(undefined4 *)(puVar8 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
          }
          *(int *)(puVar8 + -0x14) = iVar4;
          *(undefined4 *)(puVar8 + -0x18) = *(undefined4 *)(unaff_EBP + -0x20);
          *(undefined4 *)(puVar8 + -0x1c) = 0;
          *(undefined4 *)(puVar8 + -0x20) = *(undefined4 *)(unaff_EBP + 0x20);
          puVar9 = puVar8 + -0x24;
          *(undefined4 *)(puVar8 + -0x24) = 0x80ce71;
          iVar4 = WideCharToMultiByte(*(UINT *)(puVar8 + -0x20),*(DWORD *)(puVar8 + -0x1c),
                                      *(LPCWSTR *)(puVar8 + -0x18),*(int *)(puVar8 + -0x14),
                                      *(LPSTR *)(puVar8 + -0x10),*(int *)(puVar8 + -0xc),
                                      *(LPCSTR *)(puVar8 + -8),*(LPBOOL *)(puVar8 + -4));
        }
      }
      else if ((*(int *)(unaff_EBP + 0x1c) != 0) && (iVar4 <= *(int *)(unaff_EBP + 0x1c))) {
        *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(unaff_EBP + 0x1c);
        *(undefined4 *)(puVar6 + -8) = *(undefined4 *)(unaff_EBP + 0x18);
        *(int *)(puVar6 + -0xc) = iVar1;
        *(undefined4 *)(puVar6 + -0x10) = *(undefined4 *)(unaff_EBP + -0x1c);
        *(undefined4 *)(puVar6 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(puVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
        puVar7 = puVar6 + -0x1c;
        *(undefined4 *)(puVar6 + -0x1c) = 0x80cdda;
        LCMapStringW(*(LCID *)(puVar6 + -0x18),*(DWORD *)(puVar6 + -0x14),
                     *(LPCWSTR *)(puVar6 + -0x10),*(int *)(puVar6 + -0xc),*(LPWSTR *)(puVar6 + -8),
                     *(int *)(puVar6 + -4));
        puVar9 = puVar7;
      }
    }
  }
LAB_0080ce73:
  if (*(int *)(unaff_EBP + -0x38) != 0) {
    *(undefined4 *)(puVar9 + -4) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(puVar9 + -8) = 0x80ce80;
    _free(*(void **)(puVar9 + -4));
    return extraout_EAX;
  }
  if (*(int *)(unaff_EBP + -0x3c) != 0) {
    *(undefined4 *)(puVar9 + -4) = *(undefined4 *)(unaff_EBP + -0x1c);
    *(undefined4 *)(puVar9 + -8) = 0x80ce8e;
    _free(*(void **)(puVar9 + -4));
    return extraout_EAX_00;
  }
LAB_0080d00b:
  *(undefined4 *)(unaff_EBP + -0x5c) = 0x80d013;
  return iVar4;
}


// ==== FUN_0080ce06 @ 0x0080ce06 ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

int FUN_0080ce06(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int extraout_EAX;
  int extraout_EAX_00;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int unaff_EBP;
  
  puVar6 = *(undefined1 **)(unaff_EBP + -0x18);
  *(undefined4 *)(puVar6 + -4) = 0x80ce0e;
  __resetstkoflw();
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar4 = *(int *)(unaff_EBP + -0x2c);
  uVar1 = *(undefined4 *)(unaff_EBP + -0x34);
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    *(int *)(puVar6 + -4) = iVar4 * 2;
    *(undefined4 *)(puVar6 + -8) = 0x80ce2b;
    pvVar2 = _malloc(*(size_t *)(puVar6 + -4));
    *(void **)(unaff_EBP + -0x20) = pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_0080ce73;
    *(undefined4 *)(unaff_EBP + -0x38) = 1;
  }
  *(int *)(puVar6 + -4) = iVar4;
  *(undefined4 *)(puVar6 + -8) = *(undefined4 *)(unaff_EBP + -0x20);
  *(undefined4 *)(puVar6 + -0xc) = uVar1;
  *(undefined4 *)(puVar6 + -0x10) = *(undefined4 *)(unaff_EBP + -0x1c);
  *(undefined4 *)(puVar6 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(puVar6 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  puVar5 = puVar6 + -0x1c;
  *(undefined4 *)(puVar6 + -0x1c) = 0x80ce4e;
  iVar3 = LCMapStringW(*(LCID *)(puVar6 + -0x18),*(DWORD *)(puVar6 + -0x14),
                       *(LPCWSTR *)(puVar6 + -0x10),*(int *)(puVar6 + -0xc),*(LPWSTR *)(puVar6 + -8)
                       ,*(int *)(puVar6 + -4));
  puVar6 = puVar5;
  if (iVar3 != 0) {
    *(undefined4 *)(puVar5 + -4) = 0;
    *(undefined4 *)(puVar5 + -8) = 0;
    if (*(int *)(unaff_EBP + 0x1c) == 0) {
      *(undefined4 *)(puVar5 + -0xc) = 0;
      *(undefined4 *)(puVar5 + -0x10) = 0;
    }
    else {
      *(undefined4 *)(puVar5 + -0xc) = *(undefined4 *)(unaff_EBP + 0x1c);
      *(undefined4 *)(puVar5 + -0x10) = *(undefined4 *)(unaff_EBP + 0x18);
    }
    *(int *)(puVar5 + -0x14) = iVar4;
    *(undefined4 *)(puVar5 + -0x18) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(puVar5 + -0x1c) = 0;
    *(undefined4 *)(puVar5 + -0x20) = *(undefined4 *)(unaff_EBP + 0x20);
    puVar6 = puVar5 + -0x24;
    *(undefined4 *)(puVar5 + -0x24) = 0x80ce71;
    iVar4 = WideCharToMultiByte(*(UINT *)(puVar5 + -0x20),*(DWORD *)(puVar5 + -0x1c),
                                *(LPCWSTR *)(puVar5 + -0x18),*(int *)(puVar5 + -0x14),
                                *(LPSTR *)(puVar5 + -0x10),*(int *)(puVar5 + -0xc),
                                *(LPCSTR *)(puVar5 + -8),*(LPBOOL *)(puVar5 + -4));
  }
LAB_0080ce73:
  if (*(int *)(unaff_EBP + -0x38) != 0) {
    *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(puVar6 + -8) = 0x80ce80;
    _free(*(void **)(puVar6 + -4));
    return extraout_EAX;
  }
  if (*(int *)(unaff_EBP + -0x3c) == 0) {
    *(undefined4 *)(unaff_EBP + -0x5c) = 0x80d013;
    return iVar4;
  }
  *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(unaff_EBP + -0x1c);
  *(undefined4 *)(puVar6 + -8) = 0x80ce8e;
  _free(*(void **)(puVar6 + -4));
  return extraout_EAX_00;
}


// ==== FUN_0080cf3e @ 0x0080cf3e ====

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

uint FUN_0080cf3e(void)

{
  undefined1 *puVar1;
  void *pvVar2;
  int iVar3;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  undefined1 *puVar4;
  int unaff_EBP;
  uint uVar5;
  
  puVar1 = *(undefined1 **)(unaff_EBP + -0x18);
  *(undefined4 *)(puVar1 + -4) = 0x80cf46;
  __resetstkoflw();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(puVar1 + -8) = 0x80cf5a;
  pvVar2 = _malloc(*(size_t *)(puVar1 + -4));
  puVar4 = puVar1;
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(puVar1 + -8) = 0;
    *(void **)(puVar1 + -0xc) = pvVar2;
    *(undefined4 *)(puVar1 + -0x10) = 0x80cf6b;
    _memset(*(void **)(puVar1 + -0xc),*(int *)(puVar1 + -8),*(size_t *)(puVar1 + -4));
    *(undefined4 *)(unaff_EBP + -0x40) = 1;
    *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(unaff_EBP + -0x24);
    *(void **)(puVar1 + -8) = pvVar2;
    *(undefined4 *)(puVar1 + -0xc) = *(undefined4 *)(unaff_EBP + 0x14);
    *(undefined4 *)(puVar1 + -0x10) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(puVar1 + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(puVar1 + -0x18) = *(undefined4 *)(unaff_EBP + 8);
    puVar4 = puVar1 + -0x1c;
    *(undefined4 *)(puVar1 + -0x1c) = 0x80cf8b;
    iVar3 = LCMapStringA(*(LCID *)(puVar1 + -0x18),*(DWORD *)(puVar1 + -0x14),
                         *(LPCSTR *)(puVar1 + -0x10),*(int *)(puVar1 + -0xc),*(LPSTR *)(puVar1 + -8)
                         ,*(int *)(puVar1 + -4));
    *(int *)(unaff_EBP + -0x24) = iVar3;
    if (iVar3 != 0) {
      *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(unaff_EBP + 0x1c);
      *(undefined4 *)(puVar4 + -8) = *(undefined4 *)(unaff_EBP + 0x18);
      *(int *)(puVar4 + -0xc) = unaff_EBP + -0x24;
      *(void **)(puVar4 + -0x10) = pvVar2;
      *(undefined4 *)(puVar4 + -0x14) = *(undefined4 *)(unaff_EBP + 0x20);
      *(undefined4 *)(puVar4 + -0x18) = *(undefined4 *)(unaff_EBP + -0x44);
      *(undefined4 *)(puVar4 + -0x1c) = 0x80cfac;
      iVar3 = FUN_00812e0e();
      *(int *)(unaff_EBP + -0x30) = iVar3;
      uVar5 = -(uint)(iVar3 != 0) & *(uint *)(unaff_EBP + -0x24);
      goto LAB_0080cfc0;
    }
  }
  uVar5 = 0;
LAB_0080cfc0:
  if (*(int *)(unaff_EBP + -0x40) != 0) {
    *(void **)(puVar4 + -4) = pvVar2;
    *(undefined4 *)(puVar4 + -8) = 0x80cfcb;
    _free(*(void **)(puVar4 + -4));
    return extraout_EAX;
  }
  if (*(int *)(unaff_EBP + -0x28) != 0) {
    *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(puVar4 + -8) = 0x80cff5;
    _free(*(void **)(puVar4 + -4));
    return extraout_EAX_00;
  }
  iVar3 = *(int *)(unaff_EBP + -0x30);
  if ((iVar3 == 0) || (*(int *)(unaff_EBP + 0x18) == iVar3)) {
    *(undefined4 *)(unaff_EBP + -0x5c) = 0x80d013;
    return uVar5;
  }
  *(int *)(puVar4 + -4) = iVar3;
  *(undefined4 *)(puVar4 + -8) = 0x80d008;
  _free(*(void **)(puVar4 + -4));
  return extraout_EAX_01;
}


// ==== __set_exp @ 0x0080d014 ====

/* Library Function - Single Match
    __set_exp
   
   Library: Visual Studio 2003 Release */

float10 __set_exp(undefined8 param_1,short param_2)

{
  undefined8 local_c;
  
  local_c = (double)CONCAT26((param_2 + 0x3fe) * 0x10 | param_1._6_2_ & 0x800f,(undefined6)param_1);
  return (float10)local_c;
}


// ==== __sptype @ 0x0080d03e ====

/* Library Function - Single Match
    __sptype
   
   Library: Visual Studio 2003 Release */

undefined4 __sptype(int param_1,uint param_2)

{
  undefined4 uStack_8;
  
  if (param_2 == 0x7ff00000) {
    if (param_1 == 0) {
      return 1;
    }
  }
  else if ((param_2 == 0xfff00000) && (param_1 == 0)) {
    return 2;
  }
  if ((param_2._2_2_ & 0x7ff8) == 0x7ff8) {
    uStack_8 = 3;
  }
  else {
    if (((param_2._2_2_ & 0x7ff8) != 0x7ff0) || (((param_2 & 0x7ffff) == 0 && (param_1 == 0)))) {
      return 0;
    }
    uStack_8 = 4;
  }
  return uStack_8;
}


// ==== __decomp @ 0x0080d099 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __decomp
   
   Library: Visual Studio 2003 Release */

float10 __decomp(uint param_1,uint param_2,int *param_3)

{
  bool bVar1;
  int iVar2;
  int extraout_EDX;
  float10 fVar3;
  
  if ((double)CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))) ==
      _DAT_0099d098) {
    fVar3 = (float10)0;
    iVar2 = 0;
  }
  else if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
    if (_DAT_0099d098 <=
        (double)CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    while ((param_2._2_1_ & 0x10) == 0) {
      iVar2 = CONCAT13(param_2._3_1_,CONCAT12(param_2._2_1_,(ushort)param_2)) << 1;
      param_2._0_2_ = (ushort)iVar2;
      param_2._2_1_ = (byte)((uint)iVar2 >> 0x10);
      param_2._3_1_ = (byte)((uint)iVar2 >> 0x18);
      if ((param_1 & 0x80000000) != 0) {
        param_2._0_2_ = (ushort)param_2 | 1;
      }
      param_1 = param_1 << 1;
    }
    if (bVar1) {
      param_2._3_1_ = param_2._3_1_ | 0x80;
    }
    fVar3 = (float10)__set_exp(CONCAT17(param_2._3_1_,
                                        CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))) &
                               0xffefffffffffffff,0);
    iVar2 = extraout_EDX;
  }
  else {
    fVar3 = (float10)__set_exp(CONCAT17(param_2._3_1_,
                                        CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))),0
                              );
    iVar2 = ((param_2 >> 0x10 & 0x7ff0) >> 4) - 0x3fe;
  }
  *param_3 = iVar2;
  return (float10)(double)fVar3;
}


// ==== __raise_exc @ 0x0080d155 ====

/* Library Function - Single Match
    __raise_exc
   
   Library: Visual Studio 2003 Release */

void __raise_exc(uint *param_1,uint *param_2,uint param_3,int param_4,undefined8 *param_5,
                undefined8 *param_6)

{
  uint *puVar1;
  undefined8 *puVar2;
  byte bVar3;
  uint uVar4;
  
  uVar4 = param_3;
  puVar1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((param_3 & 0x10) != 0) {
    param_1[1] = param_1[1] | 1;
    param_3 = 0xc000008f;
  }
  if ((uVar4 & 2) != 0) {
    param_1[1] = param_1[1] | 2;
    param_3 = 0xc0000093;
  }
  if ((uVar4 & 1) != 0) {
    param_1[1] = param_1[1] | 4;
    param_3 = 0xc0000091;
  }
  if ((uVar4 & 4) != 0) {
    param_1[1] = param_1[1] | 8;
    param_3 = 0xc000008e;
  }
  if ((uVar4 & 8) != 0) {
    param_1[1] = param_1[1] | 0x10;
    param_3 = 0xc0000090;
  }
  param_1[2] = param_1[2] ^ (~(*param_2 << 4) ^ param_1[2]) & 0x10;
  param_1[2] = param_1[2] ^ (~(*param_2 << 1) ^ param_1[2]) & 8;
  param_1[2] = param_1[2] ^ (~(*param_2 >> 1) ^ param_1[2]) & 4;
  param_1[2] = param_1[2] ^ (~(*param_2 >> 3) ^ param_1[2]) & 2;
  param_1[2] = param_1[2] ^ (~(*param_2 >> 5) ^ param_1[2]) & 1;
  bVar3 = __statfp();
  puVar2 = param_6;
  if ((bVar3 & 1) != 0) {
    param_1[3] = param_1[3] | 0x10;
  }
  if ((bVar3 & 4) != 0) {
    param_1[3] = param_1[3] | 8;
  }
  if ((bVar3 & 8) != 0) {
    param_1[3] = param_1[3] | 4;
  }
  if ((bVar3 & 0x10) != 0) {
    param_1[3] = param_1[3] | 2;
  }
  if ((bVar3 & 0x20) != 0) {
    param_1[3] = param_1[3] | 1;
  }
  uVar4 = *puVar1 & 0xc00;
  if (uVar4 == 0) {
    *param_1 = *param_1 & 0xfffffffc;
  }
  else {
    if (uVar4 == 0x400) {
      uVar4 = *param_1 & 0xfffffffd | 1;
    }
    else {
      if (uVar4 != 0x800) {
        if (uVar4 == 0xc00) {
          *param_1 = *param_1 | 3;
        }
        goto LAB_0080d2b2;
      }
      uVar4 = *param_1 & 0xfffffffe | 2;
    }
    *param_1 = uVar4;
  }
LAB_0080d2b2:
  uVar4 = *puVar1 & 0x300;
  if (uVar4 == 0) {
    uVar4 = *param_1 & 0xffffffeb | 8;
LAB_0080d2e8:
    *param_1 = uVar4;
  }
  else {
    if (uVar4 == 0x200) {
      uVar4 = *param_1 & 0xffffffe7 | 4;
      goto LAB_0080d2e8;
    }
    if (uVar4 == 0x300) {
      *param_1 = *param_1 & 0xffffffe3;
    }
  }
  *param_1 = *param_1 ^ (param_4 << 5 ^ *param_1) & 0x1ffe0;
  param_1[8] = param_1[8] | 1;
  param_1[8] = param_1[8] & 0xffffffe3 | 2;
  *(undefined8 *)(param_1 + 4) = *param_5;
  param_1[0x18] = param_1[0x18] | 1;
  param_1[0x18] = param_1[0x18] & 0xffffffe3 | 2;
  *(undefined8 *)(param_1 + 0x14) = *param_6;
  __clrfp();
  RaiseException(param_3,0,1,(ULONG_PTR *)&param_1);
  if ((param_1[2] & 0x10) != 0) {
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  if ((param_1[2] & 8) != 0) {
    *puVar1 = *puVar1 & 0xfffffffb;
  }
  if ((param_1[2] & 4) != 0) {
    *puVar1 = *puVar1 & 0xfffffff7;
  }
  if ((param_1[2] & 2) != 0) {
    *puVar1 = *puVar1 & 0xffffffef;
  }
  if ((param_1[2] & 1) != 0) {
    *puVar1 = *puVar1 & 0xffffffdf;
  }
  uVar4 = *param_1 & 3;
  if (uVar4 == 0) {
    *puVar1 = *puVar1 & 0xfffff3ff;
  }
  else {
    if (uVar4 == 1) {
      uVar4 = *puVar1 & 0xfffff7ff | 0x400;
    }
    else {
      if (uVar4 != 2) {
        if (uVar4 == 3) {
          *(byte *)((int)puVar1 + 1) = *(byte *)((int)puVar1 + 1) | 0xc;
        }
        goto LAB_0080d3c1;
      }
      uVar4 = *puVar1 & 0xfffffbff | 0x800;
    }
    *puVar1 = uVar4;
  }
LAB_0080d3c1:
  uVar4 = *param_1 >> 2 & 7;
  if (uVar4 == 0) {
    uVar4 = *puVar1 & 0xfffff3ff | 0x300;
  }
  else {
    if (uVar4 != 1) {
      if (uVar4 == 2) {
        *puVar1 = *puVar1 & 0xfffff3ff;
      }
      goto LAB_0080d3f0;
    }
    uVar4 = *puVar1 & 0xfffff3ff | 0x200;
  }
  *puVar1 = uVar4;
LAB_0080d3f0:
  *puVar2 = *(undefined8 *)(param_1 + 0x14);
  return;
}


// ==== __handle_exc @ 0x0080d3fa ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __handle_exc
   
   Library: Visual Studio 2003 Release */

bool __handle_exc(uint param_1,double *param_2,uint param_3)

{
  double dVar1;
  uint uVar2;
  bool bVar3;
  float10 fVar4;
  undefined8 local_14;
  int local_c;
  uint local_8;
  
  uVar2 = param_1 & 0x1f;
  local_8 = uVar2;
  if (((param_1 & 8) != 0) && ((param_3 & 1) != 0)) {
    FUN_0080d987(1);
    uVar2 = param_1 & 0x17;
    goto LAB_0080d5fc;
  }
  if (((param_1 & 4) != 0) && ((param_3 & 4) != 0)) {
    FUN_0080d987(4);
    uVar2 = param_1 & 0x1b;
    goto LAB_0080d5fc;
  }
  if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {
    if (((param_1 & 2) != 0) && ((param_3 & 0x10) != 0)) {
      bVar3 = (param_1 & 0x10) != 0;
      if (*param_2 == _DAT_0099d098) {
        bVar3 = true;
      }
      else {
        fVar4 = (float10)__decomp(*param_2,&local_c);
        dVar1 = (double)fVar4;
        local_c = local_c + -0x600;
        if (local_c < -0x432) {
          local_14 = dVar1 * _DAT_0099d098;
          bVar3 = true;
        }
        else {
          local_14 = (double)((ulonglong)dVar1 & 0xfffffffffffff | 0x10000000000000);
          if (local_c < -0x3fd) {
            local_c = -0x3fd - local_c;
            do {
              if ((((ulonglong)local_14 & 1) != 0) && (!bVar3)) {
                bVar3 = true;
              }
              uVar2 = (uint)local_14 >> 1;
              if (((ulonglong)local_14 & 0x100000000) != 0) {
                local_14._3_1_ = (byte)((ulonglong)local_14 >> 0x18) >> 1;
                local_14._0_3_ = (undefined3)uVar2;
                local_14._0_4_ = CONCAT13(local_14._3_1_,(undefined3)local_14) | 0x80000000;
                uVar2 = (uint)local_14;
              }
              local_14._0_4_ = uVar2;
              local_14 = (double)CONCAT44(local_14._4_4_ >> 1,(uint)local_14);
              local_c = local_c + -1;
            } while (local_c != 0);
          }
          if (dVar1 < _DAT_0099d098) {
            local_14 = -local_14;
          }
        }
        *param_2 = local_14;
      }
      if (bVar3) {
        FUN_0080d987(0x10);
      }
      uVar2 = local_8 & 0xfffffffd;
      local_8 = uVar2;
    }
    goto LAB_0080d5fc;
  }
  FUN_0080d987(8);
  uVar2 = param_3 & 0xc00;
  dVar1 = _DAT_00b49f10;
  if (uVar2 == 0) {
    if (*param_2 <= _DAT_0099d098) {
      dVar1 = -_DAT_00b49f10;
    }
LAB_0080d518:
    *param_2 = dVar1;
  }
  else {
    if (uVar2 == 0x400) {
      if (*param_2 <= _DAT_0099d098) {
        dVar1 = -_DAT_00b49f10;
      }
      else {
        dVar1 = _DAT_00b49f20;
      }
      goto LAB_0080d518;
    }
    if (uVar2 == 0x800) {
      if (*param_2 <= _DAT_0099d098) {
        dVar1 = -_DAT_00b49f20;
      }
      goto LAB_0080d518;
    }
    if (uVar2 == 0xc00) {
      dVar1 = _DAT_00b49f20;
      if (*param_2 <= _DAT_0099d098) {
        dVar1 = -_DAT_00b49f20;
      }
      goto LAB_0080d518;
    }
  }
  uVar2 = param_1 & 0x1e;
LAB_0080d5fc:
  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    FUN_0080d987(0x20);
    uVar2 = uVar2 & 0xffffffef;
  }
  return uVar2 == 0;
}


// ==== FID_conflict:__set_errno_from_matherr @ 0x0080d61e ====

/* Library Function - Multiple Matches With Different Base Names
    __set_errno
    __set_errno_from_matherr
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

errno_t __cdecl FID_conflict___set_errno_from_matherr(int _Value)

{
  undefined4 *puVar1;
  
  if (_Value == 1) {
    _Value = FUN_00804b94();
    *(undefined4 *)_Value = 0x21;
  }
  else if ((1 < _Value) && (_Value < 4)) {
    puVar1 = (undefined4 *)FUN_00804b94();
    *puVar1 = 0x22;
    return (errno_t)puVar1;
  }
  return _Value;
}


// ==== __errcode @ 0x0080d646 ====

/* Library Function - Single Match
    __errcode
   
   Library: Visual Studio 2003 Release */

int __errcode(byte param_1)

{
  int iStack_4;
  
  if ((param_1 & 0x20) == 0) {
    if ((param_1 & 8) != 0) {
      return 1;
    }
    if ((param_1 & 4) == 0) {
      if ((param_1 & 1) == 0) {
        return (param_1 & 2) << 1;
      }
      iStack_4 = 3;
    }
    else {
      iStack_4 = 2;
    }
  }
  else {
    iStack_4 = 5;
  }
  return iStack_4;
}


// ==== __umatherr @ 0x0080d673 ====

/* Library Function - Single Match
    __umatherr
   
   Library: Visual Studio 2003 Release */

float10 __umatherr(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                  undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  iVar1 = 0;
  do {
    if ((&DAT_00b49f38)[iVar1 * 2] == param_2) {
      local_20 = *(int *)(iVar1 * 8 + 0xb49f3c);
      goto LAB_0080d68f;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1d);
  local_20 = 0;
LAB_0080d68f:
  if (local_20 == 0) {
    __ctrlfp(param_9,0xffff);
    FID_conflict___set_errno_from_matherr(param_1);
    return (float10)(double)CONCAT44(param_8,param_7);
  }
  local_1c = param_3;
  local_18 = param_4;
  local_14 = param_5;
  local_10 = param_6;
  local_c = param_7;
  local_24 = param_1;
  uStack_8 = param_8;
  __ctrlfp(param_9,0xffff);
  iVar1 = FUN_00813a93(&local_24);
  if (iVar1 == 0) {
    FID_conflict___set_errno_from_matherr(param_1);
  }
  return (float10)(double)CONCAT44(uStack_8,local_c);
}


// ==== __handle_qnan1 @ 0x0080d711 ====

/* Library Function - Single Match
    __handle_qnan1
   
   Library: Visual Studio 2003 Release */

float10 __handle_qnan1(undefined4 param_1,double param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  float10 fVar2;
  
  if (DAT_00b4a418 == 0) {
    fVar2 = (float10)__umatherr(1,param_1,param_2,0,param_2,param_3);
    return fVar2;
  }
  puVar1 = (undefined4 *)FUN_00804b94();
  *puVar1 = 0x21;
  __ctrlfp();
  return (float10)param_2;
}


// ==== __handle_qnan2 @ 0x0080d764 ====

/* Library Function - Single Match
    __handle_qnan2
   
   Library: Visual Studio 2003 Release */

float10 __handle_qnan2(undefined4 param_1,double param_2,double param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  float10 fVar2;
  
  if (DAT_00b4a418 == 0) {
    fVar2 = (float10)__umatherr(1,param_1,param_2,param_3,param_2 + param_3,param_4);
    return fVar2;
  }
  puVar1 = (undefined4 *)FUN_00804b94();
  *puVar1 = 0x21;
  __ctrlfp();
  return (float10)(param_2 + param_3);
}


// ==== FUN_0080d7c3 @ 0x0080d7c3 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

float10 FUN_0080d7c3(undefined4 param_1,undefined4 param_2,undefined8 param_3,double param_4,
                    undefined4 param_5)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = __handle_exc(param_1,&param_4,param_5);
  if (iVar1 == 0) {
    __raise_exc();
  }
  iVar1 = __errcode(param_1);
  if ((DAT_00b4a418 == 0) && (iVar1 != 0)) {
    fVar2 = (float10)__umatherr(iVar1,param_2,param_3,0,param_4,param_5);
  }
  else {
    FID_conflict___set_errno_from_matherr(iVar1);
    __ctrlfp();
    fVar2 = (float10)param_4;
  }
  return fVar2;
}


// ==== FUN_0080d87f @ 0x0080d87f ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

float10 FUN_0080d87f(undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                    double param_5,undefined4 param_6)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = __handle_exc(param_1,&param_5,param_6);
  if (iVar1 == 0) {
    __raise_exc();
  }
  iVar1 = __errcode(param_1);
  if ((DAT_00b4a418 == 0) && (iVar1 != 0)) {
    fVar2 = (float10)__umatherr(iVar1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    FID_conflict___set_errno_from_matherr(iVar1);
    __ctrlfp();
    fVar2 = (float10)param_5;
  }
  return fVar2;
}


// ==== __statfp @ 0x0080d94c ====

/* Library Function - Single Match
    __statfp
   
   Library: Visual Studio 2003 Release */

int __statfp(void)

{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}


// ==== __clrfp @ 0x0080d957 ====

/* Library Function - Single Match
    __clrfp
   
   Library: Visual Studio 2003 Release */

int __clrfp(void)

{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}


// ==== __ctrlfp @ 0x0080d963 ====

/* Library Function - Single Match
    __ctrlfp
   
   Library: Visual Studio 2003 Release */

int __ctrlfp(void)

{
  short in_FPUControlWord;
  
  return (int)in_FPUControlWord;
}


// ==== FUN_0080d987 @ 0x0080d987 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0080d987(void)

{
  return;
}


// ==== ___security_init_cookie @ 0x0080d9dd ====

/* Library Function - Single Match
    ___security_init_cookie
   
   Library: Visual Studio 2003 Release */

void __cdecl ___security_init_cookie(void)

{
  DWORD DVar1;
  DWORD DVar2;
  DWORD DVar3;
  LARGE_INTEGER local_14;
  _FILETIME local_c;
  
  if ((DAT_00b49670 == 0) || (DAT_00b49670 == 0xbb40e64e)) {
    GetSystemTimeAsFileTime(&local_c);
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_00b49670 = local_c.dwHighDateTime ^ local_c.dwLowDateTime ^ DVar1 ^ DVar2 ^ DVar3 ^
                   local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_00b49670 == 0) {
      DAT_00b49670 = 0xbb40e64e;
    }
  }
  return;
}


// ==== FUN_0080da43 @ 0x0080da43 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_0080da43(int param_1)

{
  code *pcVar1;
  DWORD DVar2;
  size_t sVar3;
  char *_Str;
  char acStack_156 [14];
  undefined4 local_12c;
  CHAR local_128 [260];
  undefined1 local_24;
  uint local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_8 = &DAT_00a0b680;
  uStack_c = 0x80da52;
  local_20 = DAT_00b49670 ^ (uint)(local_128 + 0x124);
  if (DAT_00b5cb74 == (code *)0x0) {
    if (param_1 == 1) {
      local_12c = s_A_buffer_overrun_has_been_detect_00a0b4e8;
    }
    else {
      local_12c = s_A_security_error_of_unknown_caus_00a0b5a8;
    }
    local_24 = 0;
    DVar2 = GetModuleFileNameA((HMODULE)0x0,local_128,0x104);
    if (DVar2 == 0) {
      FUN_00809180();
    }
    _Str = local_128;
    sVar3 = _strlen(_Str);
    if (0x3c < sVar3 + 0xb) {
      sVar3 = _strlen(_Str);
      _Str = acStack_156 + (sVar3 - 3);
      _strncpy(_Str,(char *)&DAT_009fe62c,3);
    }
    _strlen(_Str);
    local_1c = local_128 + -0x10;
    FUN_00809180();
    FUN_00809190();
    FUN_00809190();
    FUN_00809190();
    FUN_00809190(local_128 + -0x10,&DAT_00a065f0);
    FUN_00809190(local_128 + -0x10,local_12c);
    ___crtMessageBoxA(local_128 + -0x10,s_Microsoft_Visual_C___Runtime_Lib_00a065c8,0x12010);
  }
  else {
    local_8 = (undefined *)0x0;
    (*DAT_00b5cb74)();
    local_8 = (undefined *)0xffffffff;
  }
  __exit();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_0080da82 @ 0x0080da82 ====

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_0080da82(void)

{
  int iVar1;
  code *pcVar2;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar1 + -4) = 3;
  *(undefined4 *)(iVar1 + -8) = 0x80db8d;
  __exit();
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}


// ==== __close_lk @ 0x0080db8e ====

/* Library Function - Single Match
    __close_lk
   
   Library: Visual Studio 2003 Release */

undefined4 __close_lk(uint param_1)

{
  intptr_t iVar1;
  intptr_t iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = __get_osfhandle(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = __get_osfhandle(2);
      iVar2 = __get_osfhandle(1);
      if (iVar2 == iVar1) goto LAB_0080dbdc;
    }
    hObject = (HANDLE)__get_osfhandle(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_0080dbde;
    }
  }
LAB_0080dbdc:
  DVar4 = 0;
LAB_0080dbde:
  __free_osfhnd(param_1);
  *(undefined1 *)((&DAT_00b60fa0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    __dosmaperr(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


// ==== __close @ 0x0080dc11 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __close
   
   Library: Visual Studio 2003 Release */

int __cdecl __close(int _FileHandle)

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
        local_20 = -1;
      }
      else {
        local_20 = __close_lk(_FileHandle);
      }
      FUN_0080dc88();
      return local_20;
    }
  }
  puVar1 = (undefined4 *)FUN_00804b94();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_00804b9d();
  *puVar1 = 0;
  return -1;
}


// ==== FUN_0080dc88 @ 0x0080dc88 ====

void FUN_0080dc88(void)

{
  int unaff_EBX;
  
  __unlock_fhandle(unaff_EBX);
  return;
}


// ==== FUN_0080dcac @ 0x0080dcac ====

void FUN_0080dcac(int param_1)

{
  if (((*(uint *)(param_1 + 0xc) & 0x83) == 0) || ((*(uint *)(param_1 + 0xc) & 8) == 0)) {
    return;
  }
  _free(*(void **)(param_1 + 8));
  return;
}


// ==== __openfile @ 0x0080dcd7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __openfile
   
   Library: Visual Studio 2003 Release */

FILE * __cdecl __openfile(char *_Filename,char *_Mode,int _ShFlag,FILE *_File)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  uint _OpenFlag;
  uint uVar6;
  
  cVar1 = *_Mode;
  bVar4 = false;
  bVar3 = false;
  if (cVar1 == 'a') {
    _OpenFlag = 0x109;
  }
  else {
    if (cVar1 == 'r') {
      _OpenFlag = 0;
      uVar6 = DAT_00b5cb88 | 1;
      goto LAB_0080dd18;
    }
    if (cVar1 != 'w') {
      return (FILE *)0x0;
    }
    _OpenFlag = 0x301;
  }
  uVar6 = DAT_00b5cb88 | 2;
LAB_0080dd18:
  bVar2 = true;
LAB_0080ddf7:
  _Mode = _Mode + 1;
  cVar1 = *_Mode;
  if ((cVar1 == '\0') || (!bVar2)) {
    iVar5 = __sopen(_Filename,_OpenFlag,_ShFlag,0x1a4);
    if (iVar5 < 0) {
      return (FILE *)0x0;
    }
    _DAT_00b5c644 = _DAT_00b5c644 + 1;
    _File->_flag = uVar6;
    _File->_cnt = 0;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_tmpfname = (char *)0x0;
    _File->_file = iVar5;
    return _File;
  }
  if (cVar1 < 'U') {
    if (cVar1 == 'T') {
      if ((_OpenFlag & 0x1000) == 0) {
        _OpenFlag = _OpenFlag | 0x1000;
        goto LAB_0080ddf7;
      }
    }
    else if (cVar1 == '+') {
      if ((_OpenFlag & 2) == 0) {
        _OpenFlag = _OpenFlag & 0xfffffffe | 2;
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_0080ddf7;
      }
    }
    else if (cVar1 == 'D') {
      if ((_OpenFlag & 0x40) == 0) {
        _OpenFlag = _OpenFlag | 0x40;
        goto LAB_0080ddf7;
      }
    }
    else if (cVar1 == 'R') {
      if (!bVar3) {
        bVar3 = true;
        _OpenFlag = _OpenFlag | 0x10;
        goto LAB_0080ddf7;
      }
    }
    else if ((cVar1 == 'S') && (!bVar3)) {
      bVar3 = true;
      _OpenFlag = _OpenFlag | 0x20;
      goto LAB_0080ddf7;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((_OpenFlag & 0xc000) != 0) goto LAB_0080ddd9;
      _OpenFlag = _OpenFlag | 0x8000;
      goto LAB_0080ddf7;
    }
    if (cVar1 == 'c') {
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 | 0x4000;
        goto LAB_0080ddf7;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((_OpenFlag & 0xc000) != 0)) goto LAB_0080ddd9;
        _OpenFlag = _OpenFlag | 0x4000;
        goto LAB_0080ddf7;
      }
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 & 0xffffbfff;
        goto LAB_0080ddf7;
      }
    }
  }
LAB_0080ddd9:
  bVar2 = false;
  goto LAB_0080ddf7;
}


// ==== FUN_0080de3f @ 0x0080de3f ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

undefined4 * FUN_0080de3f(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 *extraout_EAX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *_File;
  
  puVar4 = (undefined4 *)0x0;
  __lock(1);
  iVar3 = 0;
  do {
    _File = puVar4;
    if (DAT_00b620c0 <= iVar3) {
LAB_0080df2e:
      if (_File != (undefined4 *)0x0) {
        _File[1] = 0;
        _File[3] = 0;
        _File[2] = 0;
        *_File = 0;
        _File[7] = 0;
        _File[4] = 0xffffffff;
      }
      FUN_0080df58();
      return _File;
    }
    iVar1 = *(int *)(DAT_00b610b0 + iVar3 * 4);
    if (iVar1 == 0) {
      iVar3 = iVar3 * 4;
      pvVar2 = _malloc(0x38);
      *(void **)(iVar3 + DAT_00b610b0) = pvVar2;
      if (*(int *)(iVar3 + DAT_00b610b0) != 0) {
        iVar1 = ___crtInitCritSecAndSpinCount(*(int *)(iVar3 + DAT_00b610b0) + 0x20,4000);
        if (iVar1 == 0) {
          _free(*(void **)(iVar3 + DAT_00b610b0));
          return extraout_EAX;
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_00b610b0) + 0x20));
        _File = *(undefined4 **)(iVar3 + DAT_00b610b0);
      }
      goto LAB_0080df2e;
    }
    if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
      if (((2 < iVar3) && (iVar3 < 0x14)) && (iVar1 = FUN_00806c44(iVar3 + 0x10), iVar1 == 0))
      goto LAB_0080df2e;
      __lock_file2(iVar3,*(void **)(DAT_00b610b0 + iVar3 * 4));
      _File = *(undefined4 **)(DAT_00b610b0 + iVar3 * 4);
      if ((*(byte *)(_File + 3) & 0x83) == 0) goto LAB_0080df2e;
      __unlock_file2(iVar3,_File);
    }
    iVar3 = iVar3 + 1;
  } while( true );
}


// ==== FUN_0080df55 @ 0x0080df55 ====

void FUN_0080df55(void)

{
  FUN_00806c2f(1);
  return;
}


// ==== FUN_0080df58 @ 0x0080df58 ====

void FUN_0080df58(void)

{
  FUN_00806c2f(1);
  return;
}


// ==== __inc @ 0x0080df61 ====

/* Library Function - Single Match
    __inc
   
   Library: Visual Studio 2003 Release */

uint __inc(void)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  FILE *in_EDX;
  
  piVar1 = &in_EDX->_cnt;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar3 = __filbuf(in_EDX);
    return uVar3;
  }
  bVar2 = *in_EDX->_ptr;
  in_EDX->_ptr = in_EDX->_ptr + 1;
  return (uint)bVar2;
}


// ==== FUN_0080df77 @ 0x0080df77 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x0080ed62) */

int FUN_0080df77(undefined4 param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  wchar_t *pwVar10;
  char *pcVar11;
  char *pcVar12;
  byte *pbVar13;
  byte *pbVar14;
  wchar_t *pwVar15;
  bool bVar16;
  longlong lVar17;
  undefined4 local_1ec;
  byte *local_1e4;
  uint local_1e0;
  wchar_t local_1dc [2];
  undefined4 *local_1d8;
  int local_1d4;
  byte local_1d0;
  undefined1 local_1cf;
  undefined1 *local_1cc;
  uint local_1c8;
  int local_1c4;
  int local_1c0;
  wchar_t *local_1bc;
  byte local_1b5;
  undefined8 local_1b4;
  int local_1ac;
  byte local_1a5;
  int local_1a4;
  byte *local_1a0;
  char local_19b;
  char local_19a;
  char local_199;
  undefined4 local_198;
  uint local_194;
  char local_18f;
  char local_18e;
  char local_18d;
  int local_18c;
  int local_188;
  char local_181;
  char local_180;
  char local_17f [351];
  uint local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_8 = &DAT_00a0b6b0;
  uStack_c = 0x80df86;
  local_20 = DAT_00b49670 ^ (uint)(local_17f + 0x17b);
  local_198 = param_1;
  local_1a0 = param_2;
  local_1d8 = param_3;
  local_1cc = (undefined1 *)0x0;
  local_1bc = (wchar_t *)0x0;
  local_194 = 0;
  local_199 = '\0';
  local_188 = 0;
  local_1c4 = 0;
LAB_0080dfdf:
  while (*local_1a0 != 0) {
    iVar4 = _isspace((uint)*local_1a0);
    pbVar13 = local_1a0;
    if (iVar4 == 0) {
      if (*local_1a0 != 0x25) {
        local_188 = local_188 + 1;
        uVar9 = __inc();
        pbVar14 = pbVar13 + 1;
        local_1a0 = pbVar14;
        local_194 = uVar9;
        if (*pbVar13 != uVar9) goto LAB_0080ed1a;
        if ((PTR_DAT_00b49d38[(uVar9 & 0xff) * 2 + 1] & 0x80) != 0) {
          local_188 = local_188 + 1;
          uVar6 = __inc();
          local_1a0 = pbVar13 + 2;
          if (*pbVar14 != uVar6) {
            if (uVar6 != 0xffffffff) {
              __ungetc_lk(uVar6,local_198);
            }
            goto LAB_0080ed1a;
          }
          local_188 = local_188 + -1;
        }
        goto LAB_0080ed37;
      }
      iVar4 = 0;
      local_1ac = 0;
      local_1a5 = 0;
      local_1a4 = 0;
      local_1c0 = 0;
      local_18c = 0;
      local_1b5 = 0;
      local_19b = '\0';
      local_18e = '\0';
      local_181 = '\0';
      local_19a = '\0';
      local_18d = '\0';
      local_18f = '\x01';
      local_1d4 = 0;
      do {
        pbVar14 = pbVar13 + 1;
        uVar9 = (uint)*pbVar14;
        iVar5 = _isdigit(uVar9);
        if (iVar5 == 0) {
          if (uVar9 < 0x4f) {
            if (uVar9 != 0x4e) {
              if (uVar9 == 0x2a) {
                local_18e = local_18e + '\x01';
              }
              else if (uVar9 != 0x46) {
                if (uVar9 == 0x49) {
                  bVar8 = pbVar13[2];
                  if ((bVar8 == 0x36) && (pbVar13[3] == 0x34)) {
                    local_1d4 = local_1d4 + 1;
                    local_1b4 = 0;
                    pbVar14 = pbVar13 + 3;
                  }
                  else if ((bVar8 == 0x33) && (pbVar13[3] == 0x32)) {
                    pbVar14 = pbVar13 + 3;
                  }
                  else if ((((bVar8 != 100) && (bVar8 != 0x69)) && (bVar8 != 0x6f)) &&
                          ((bVar8 != 0x78 && (bVar8 != 0x58)))) goto LAB_0080e173;
                }
                else if (uVar9 == 0x4c) {
                  local_18f = local_18f + '\x01';
                }
                else {
LAB_0080e173:
                  local_181 = local_181 + '\x01';
                }
              }
            }
          }
          else if (uVar9 == 0x68) {
            local_18f = local_18f + -1;
            local_18d = local_18d + -1;
          }
          else {
            if (uVar9 == 0x6c) {
              local_18f = local_18f + '\x01';
            }
            else if (uVar9 != 0x77) goto LAB_0080e173;
            local_18d = local_18d + '\x01';
          }
        }
        else {
          local_1c0 = local_1c0 + 1;
          iVar4 = (uVar9 - 0x30) + iVar4 * 10;
        }
        pbVar13 = pbVar14;
      } while (local_181 == '\0');
      if (local_18e == '\0') {
        local_1ec = local_1d8;
        local_1bc = (wchar_t *)*local_1d8;
        local_1d8 = local_1d8 + 1;
      }
      pwVar10 = local_1bc;
      local_181 = '\0';
      if ((local_18d == '\0') && ((*pbVar14 == 0x53 || (local_18d = -1, *pbVar14 == 0x43)))) {
        local_18d = '\x01';
      }
      uVar9 = *pbVar14 | 0x20;
      local_1c8 = uVar9;
      local_1a0 = pbVar14;
      local_18c = iVar4;
      if (uVar9 != 0x6e) {
        if ((uVar9 == 99) || (uVar9 == 0x7b)) {
          local_188 = local_188 + 1;
          local_194 = __inc();
        }
        else {
          do {
            local_188 = local_188 + 1;
            uVar6 = __inc();
            iVar4 = _isspace(uVar6);
          } while (iVar4 != 0);
          uVar9 = local_1c8;
          local_194 = uVar6;
        }
      }
      uVar3 = local_198;
      if ((local_1c0 == 0) || (local_18c != 0)) {
        if ((int)uVar9 < 0x70) {
          if (uVar9 == 0x6f) goto LAB_0080e983;
          if (uVar9 == 99) {
            if (local_1c0 == 0) {
              local_1c0 = 1;
              local_18c = local_18c + 1;
            }
            goto LAB_0080e51d;
          }
          if (uVar9 == 100) goto LAB_0080e983;
          if ((int)uVar9 < 0x65) {
LAB_0080e67e:
            if (*pbVar14 != local_194) goto LAB_0080e689;
            local_199 = local_199 + -1;
            if (local_18e == '\0') {
              local_1d8 = local_1ec;
            }
            goto LAB_0080e4f7;
          }
          if (0x67 < (int)uVar9) {
            if (uVar9 == 0x69) {
              uVar9 = 100;
              goto LAB_0080e2cf;
            }
            if (uVar9 != 0x6e) goto LAB_0080e67e;
            iVar4 = local_188;
            local_1a0 = pbVar14;
            if (local_18e != '\0') goto LAB_0080e4f7;
            goto LAB_0080ec77;
          }
          pcVar11 = &local_180;
          if (local_194 == 0x2d) {
            local_180 = '-';
            pcVar11 = local_17f;
LAB_0080e30e:
            local_18c = local_18c + -1;
            local_188 = local_188 + 1;
            local_194 = __inc();
          }
          else if (local_194 == 0x2b) goto LAB_0080e30e;
          if ((local_1c0 == 0) || (0x15d < local_18c)) {
            local_18c = 0x15d;
          }
          while( true ) {
            uVar9 = local_194;
            iVar4 = _isdigit(local_194);
            if ((iVar4 == 0) ||
               (iVar4 = local_18c + -1, bVar16 = local_18c == 0, local_18c = iVar4, bVar16)) break;
            local_1a4 = local_1a4 + 1;
            *pcVar11 = (char)uVar9;
            pcVar11 = pcVar11 + 1;
            local_188 = local_188 + 1;
            local_194 = __inc();
          }
          if ((DAT_00b49d94 == (char)uVar9) &&
             (iVar4 = local_18c + -1, bVar16 = local_18c != 0, local_18c = iVar4, bVar16)) {
            local_188 = local_188 + 1;
            uVar9 = __inc();
            *pcVar11 = DAT_00b49d94;
            while( true ) {
              pcVar11 = pcVar11 + 1;
              local_194 = uVar9;
              iVar4 = _isdigit(uVar9);
              if ((iVar4 == 0) ||
                 (iVar4 = local_18c + -1, bVar16 = local_18c == 0, local_18c = iVar4, bVar16))
              break;
              local_1a4 = local_1a4 + 1;
              *pcVar11 = (char)uVar9;
              local_188 = local_188 + 1;
              uVar9 = __inc();
            }
          }
          pcVar12 = pcVar11;
          if ((local_1a4 != 0) &&
             (((uVar9 == 0x65 || (uVar9 == 0x45)) &&
              (iVar4 = local_18c + -1, bVar16 = local_18c != 0, local_18c = iVar4, bVar16)))) {
            *pcVar11 = 'e';
            pcVar12 = pcVar11 + 1;
            local_188 = local_188 + 1;
            local_194 = __inc();
            if (local_194 == 0x2d) {
              *pcVar12 = '-';
              pcVar12 = pcVar11 + 2;
LAB_0080e44e:
              bVar16 = local_18c != 0;
              local_18c = local_18c + -1;
              if (bVar16) goto LAB_0080e47f;
              local_18c = 0;
            }
            else if (local_194 == 0x2b) goto LAB_0080e44e;
            while( true ) {
              uVar9 = local_194;
              iVar4 = _isdigit(local_194);
              if ((iVar4 == 0) ||
                 (iVar4 = local_18c + -1, bVar16 = local_18c == 0, local_18c = iVar4, bVar16))
              break;
              local_1a4 = local_1a4 + 1;
              *pcVar12 = (char)uVar9;
              pcVar12 = pcVar12 + 1;
LAB_0080e47f:
              local_188 = local_188 + 1;
              local_194 = __inc();
            }
          }
          local_188 = local_188 + -1;
          if (uVar9 != 0xffffffff) {
            __ungetc_lk(uVar9,uVar3);
          }
          if (local_1a4 != 0) {
            if (local_18e == '\0') {
              local_1c4 = local_1c4 + 1;
              *pcVar12 = '\0';
              (*(code *)PTR___fassign_00b49da4)(local_18f + -1,local_1bc,&local_180);
            }
            goto LAB_0080e4f1;
          }
        }
        else {
          if (uVar9 == 0x70) {
            local_18f = '\x01';
LAB_0080e983:
            if (local_194 == 0x2d) {
              local_19b = '\x01';
            }
            else if (local_194 != 0x2b) goto LAB_0080e9ca;
            local_18c = local_18c + -1;
            if ((local_18c == 0) && (local_1c0 != 0)) {
              local_181 = '\x01';
            }
            else {
              local_188 = local_188 + 1;
              local_194 = __inc();
            }
          }
          else {
            if (uVar9 == 0x73) {
LAB_0080e51d:
              if ('\0' < local_18d) {
                local_19a = '\x01';
              }
LAB_0080e52d:
              local_188 = local_188 + -1;
              pwVar15 = pwVar10;
              if (local_194 != 0xffffffff) {
                __ungetc_lk(local_194,local_198);
              }
              do {
                if ((local_1c0 != 0) &&
                   (iVar4 = local_18c + -1, bVar16 = local_18c == 0, local_18c = iVar4, bVar16))
                goto LAB_0080e92e;
                local_188 = local_188 + 1;
                local_194 = __inc();
                if (local_194 == 0xffffffff) goto LAB_0080e915;
                bVar8 = (byte)local_194;
                if ((uVar9 != 99) &&
                   (((uVar9 != 0x73 || ((8 < (int)local_194 && ((int)local_194 < 0xe)))) ||
                    (local_194 == 0x20)))) {
                  if ((uVar9 != 0x7b) ||
                     (((int)(char)(local_1cc[(int)local_194 >> 3] ^ local_1b5) & 1 << (bVar8 & 7))
                      == 0)) goto LAB_0080e915;
                  uVar9 = local_1c8;
                }
                if (local_18e == '\0') {
                  if (local_19a == '\0') {
                    *(byte *)pwVar10 = bVar8;
                    pwVar10 = (wchar_t *)((int)pwVar10 + 1);
                  }
                  else {
                    local_1d0 = bVar8;
                    if ((PTR_DAT_00b49d38[(local_194 & 0xff) * 2 + 1] & 0x80) != 0) {
                      local_188 = local_188 + 1;
                      local_1cf = __inc();
                    }
                    _mbtowc(local_1dc,(char *)&local_1d0,DAT_00b49d90);
                    *pwVar10 = local_1dc[0];
                    pwVar10 = pwVar10 + 1;
                  }
                  local_1bc = pwVar10;
                }
                else {
                  pwVar15 = (wchar_t *)((int)pwVar15 + 1);
                }
              } while( true );
            }
            if (uVar9 == 0x75) goto LAB_0080e983;
            if (uVar9 != 0x78) {
              if (uVar9 == 0x7b) {
                if ('\0' < local_18d) {
                  local_19a = '\x01';
                }
                pbVar13 = local_1a0 + 1;
                local_1e4 = pbVar13;
                if (*pbVar13 == 0x5e) {
                  local_1e4 = local_1a0 + 2;
                  local_1b5 = 0xff;
                }
                if (local_1cc == (undefined1 *)0x0) {
                  local_1c = (undefined1 *)(local_1dc + -0xe);
                  local_1cc = (undefined1 *)(local_1dc + -0xe);
                  local_8 = (undefined *)0xffffffff;
                }
                puVar2 = local_1cc;
                local_1a0 = pbVar13;
                _memset(local_1cc,0,0x20);
                if (local_1c8 != 0x7b) goto LAB_0080e7e3;
                if (*local_1e4 != 0x5d) goto LAB_0080e7e3;
                local_1e4 = local_1e4 + 1;
                puVar2[0xb] = 0x20;
                bVar8 = 0x5d;
                while (bVar7 = *local_1e4, bVar7 != 0x5d) {
                  if (((bVar7 == 0x2d) && (bVar8 != 0)) && (bVar1 = local_1e4[1], bVar1 != 0x5d)) {
                    local_1e4 = local_1e4 + 2;
                    if (bVar8 < bVar1) {
                      bVar7 = bVar8;
                      bVar8 = bVar1;
                    }
                    else {
                      bVar7 = bVar1;
                    }
                    if (bVar7 <= bVar8) {
                      uVar9 = (uint)bVar7;
                      local_1e0 = (uint)(byte)((bVar8 - bVar7) + 1);
                      do {
                        puVar2[uVar9 >> 3] = puVar2[uVar9 >> 3] | '\x01' << ((byte)uVar9 & 7);
                        uVar9 = uVar9 + 1;
                        local_1e0 = local_1e0 - 1;
                      } while (local_1e0 != 0);
                    }
                    bVar8 = 0;
                  }
                  else {
                    local_1a5 = bVar7;
                    puVar2[bVar7 >> 3] = puVar2[bVar7 >> 3] | '\x01' << (bVar7 & 7);
                    local_1e4 = local_1e4 + 1;
LAB_0080e7e3:
                    bVar8 = local_1a5;
                  }
                }
                pwVar10 = local_1bc;
                uVar9 = local_1c8;
                if (local_1c8 == 0x7b) {
                  local_1a0 = local_1e4;
                }
                goto LAB_0080e52d;
              }
              goto LAB_0080e67e;
            }
LAB_0080e2cf:
            if (local_194 == 0x2d) {
              local_19b = '\x01';
LAB_0080e81c:
              local_18c = local_18c + -1;
              if ((local_18c == 0) && (local_1c0 != 0)) {
                local_181 = '\x01';
              }
              else {
                local_188 = local_188 + 1;
                local_194 = __inc();
              }
            }
            else if (local_194 == 0x2b) goto LAB_0080e81c;
            if (local_194 == 0x30) {
              local_188 = local_188 + 1;
              local_194 = __inc();
              if (((char)local_194 == 'x') || ((char)local_194 == 'X')) {
                local_188 = local_188 + 1;
                local_194 = __inc();
                if ((local_1c0 != 0) && (local_18c = local_18c + -2, local_18c < 1)) {
                  local_181 = local_181 + '\x01';
                }
                uVar9 = 0x78;
              }
              else {
                local_1a4 = 1;
                if (uVar9 == 0x78) {
                  local_188 = local_188 + -1;
                  if (local_194 != 0xffffffff) {
                    __ungetc_lk(local_194,local_198);
                  }
                  local_194 = 0x30;
                }
                else {
                  if ((local_1c0 != 0) && (local_18c = local_18c + -1, local_18c == 0)) {
                    local_181 = local_181 + '\x01';
                  }
                  uVar9 = 0x6f;
                }
              }
            }
          }
LAB_0080e9ca:
          lVar17 = local_1b4;
          if (local_1d4 == 0) {
            uVar6 = local_194;
            if (local_181 == '\0') {
              do {
                local_1b4 = lVar17;
                if ((uVar9 == 0x78) || (uVar9 == 0x70)) {
                  iVar4 = _isxdigit(uVar6);
                  if (iVar4 != 0) {
                    local_1ac = local_1ac << 4;
                    iVar4 = _isdigit(uVar6);
                    if (iVar4 == 0) {
                      uVar6 = (uVar6 & 0xffffffdf) - 7;
                    }
                    goto LAB_0080ebb0;
                  }
LAB_0080ebaa:
                  local_181 = local_181 + '\x01';
                }
                else {
                  iVar4 = _isdigit(uVar6);
                  if (iVar4 == 0) goto LAB_0080ebaa;
                  if (uVar9 == 0x6f) {
                    if (0x37 < (int)uVar6) goto LAB_0080ebaa;
                    local_1ac = local_1ac << 3;
                  }
                  else {
                    local_1ac = local_1ac * 10;
                  }
                }
LAB_0080ebb0:
                lVar17 = local_1b4;
                if (local_181 == '\0') {
                  local_1a4 = local_1a4 + 1;
                  local_1ac = local_1ac + -0x30 + uVar6;
                  if ((local_1c0 == 0) || (local_18c = local_18c + -1, local_18c != 0)) {
                    local_188 = local_188 + 1;
                    uVar6 = __inc();
                    lVar17 = local_1b4;
                  }
                  else {
                    local_181 = '\x01';
                  }
                }
                else {
                  local_188 = local_188 + -1;
                  if (uVar6 != 0xffffffff) {
                    __ungetc_lk(uVar6,local_198);
                    lVar17 = local_1b4;
                  }
                }
              } while (local_181 == '\0');
              local_194 = uVar6;
            }
            if (local_19b != '\0') {
              local_1ac = -local_1ac;
            }
          }
          else {
            uVar6 = local_194;
            if (local_181 == '\0') {
              do {
                if ((uVar9 == 0x78) || (uVar9 == 0x70)) {
                  iVar4 = _isxdigit(uVar6);
                  if (iVar4 != 0) {
                    local_1b4 = local_1b4 << 4;
                    iVar4 = _isdigit(uVar6);
                    if (iVar4 == 0) {
                      uVar6 = (uVar6 & 0xffffffdf) - 7;
                    }
                    goto LAB_0080ea92;
                  }
LAB_0080ea8c:
                  local_181 = local_181 + '\x01';
                }
                else {
                  iVar4 = _isdigit(uVar6);
                  if (iVar4 == 0) goto LAB_0080ea8c;
                  if (uVar9 == 0x6f) {
                    if (0x37 < (int)uVar6) goto LAB_0080ea8c;
                    local_1b4 = local_1b4 << 3;
                  }
                  else {
                    lVar17 = __allmul(local_1b4,10,0);
                    local_1b4 = lVar17;
                  }
                }
LAB_0080ea92:
                if (local_181 == '\0') {
                  local_1a4 = local_1a4 + 1;
                  lVar17 = local_1b4 + (int)(uVar6 - 0x30);
                  local_1b4 = local_1b4 + (int)(uVar6 - 0x30);
                  if ((local_1c0 == 0) || (local_18c = local_18c + -1, local_18c != 0)) {
                    local_188 = local_188 + 1;
                    local_1b4 = lVar17;
                    uVar6 = __inc();
                  }
                  else {
                    local_181 = '\x01';
                  }
                }
                else {
                  local_188 = local_188 + -1;
                  if (uVar6 != 0xffffffff) {
                    __ungetc_lk(uVar6,local_198);
                  }
                }
              } while (local_181 == '\0');
              local_194 = uVar6;
              lVar17 = local_1b4;
            }
            local_1b4._4_4_ = (int)((ulonglong)lVar17 >> 0x20);
            local_1b4._0_4_ = (int)lVar17;
            if (local_19b != '\0') {
              lVar17 = CONCAT44(-(local_1b4._4_4_ + (uint)((int)local_1b4 != 0)),-(int)local_1b4);
            }
          }
          if (uVar9 == 0x46) {
            local_1a4 = 0;
          }
          if (local_1a4 != 0) {
            local_1b4 = lVar17;
            if (local_18e == '\0') {
              local_1c4 = local_1c4 + 1;
              iVar4 = local_1ac;
              pwVar10 = local_1bc;
LAB_0080ec77:
              pbVar14 = local_1a0;
              if (local_1d4 == 0) {
                if (local_18f == '\0') {
                  *pwVar10 = (wchar_t)iVar4;
                }
                else {
                  *(int *)pwVar10 = iVar4;
                }
              }
              else {
                *(longlong *)pwVar10 = local_1b4;
              }
              goto LAB_0080e4f7;
            }
            goto LAB_0080e4f1;
          }
        }
      }
      else {
LAB_0080e689:
        uVar9 = local_194;
LAB_0080ed1a:
        if (uVar9 != 0xffffffff) {
          __ungetc_lk(local_194,local_198);
        }
      }
      break;
    }
    local_188 = local_188 + -1;
    do {
      local_188 = local_188 + 1;
      iVar4 = __inc();
      iVar5 = _isspace(iVar4);
    } while (iVar5 != 0);
    if (iVar4 != -1) {
      __ungetc_lk(iVar4,local_198);
    }
    pbVar13 = local_1a0;
    do {
      pbVar13 = pbVar13 + 1;
      iVar4 = _isspace((uint)*pbVar13);
    } while (iVar4 != 0);
    local_1a0 = pbVar13;
  }
  goto LAB_0080ed59;
LAB_0080e915:
  local_188 = local_188 + -1;
  if (local_194 != 0xffffffff) {
    __ungetc_lk(local_194,local_198);
  }
LAB_0080e92e:
  if (pwVar15 == pwVar10) {
LAB_0080ed59:
    if (((local_194 == 0xffffffff) && (local_1c4 == 0)) && (local_199 == '\0')) {
      local_1c4 = -1;
    }
    return local_1c4;
  }
  if ((local_18e == '\0') && (local_1c4 = local_1c4 + 1, local_1c8 != 99)) {
    pbVar14 = local_1a0;
    if (local_19a == '\0') {
      *(byte *)local_1bc = 0;
    }
    else {
      *local_1bc = L'\0';
    }
  }
  else {
LAB_0080e4f1:
    pbVar14 = local_1a0;
  }
LAB_0080e4f7:
  local_199 = local_199 + '\x01';
  local_1a0 = pbVar14 + 1;
LAB_0080ed37:
  if ((local_194 == 0xffffffff) && ((*local_1a0 != 0x25 || (local_1a0[1] != 0x6e))))
  goto LAB_0080ed59;
  goto LAB_0080dfdf;
}


// ==== FUN_0080e719 @ 0x0080e719 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

int FUN_0080e719(void)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  byte bVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined *puVar7;
  undefined1 uVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  void *pvVar12;
  int extraout_EAX;
  int iVar13;
  byte bVar14;
  byte bVar15;
  uint uVar16;
  byte *pbVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  int unaff_EBP;
  char *pcVar22;
  char *pcVar23;
  byte *pbVar24;
  undefined8 uVar25;
  
  puVar20 = *(undefined1 **)(unaff_EBP + -0x18);
  *(undefined4 *)(puVar20 + -4) = 0x80e721;
  __resetstkoflw();
  *(undefined4 *)(puVar20 + -4) = 0x20;
  *(undefined4 *)(puVar20 + -8) = 0x80e728;
  pvVar12 = _malloc(*(size_t *)(puVar20 + -4));
  *(void **)(unaff_EBP + -0x1c8) = pvVar12;
  if (pvVar12 == (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_0080ed59:
    if (*(int *)(unaff_EBP + -0x1e4) == 1) {
      *(undefined4 *)(puVar20 + -4) = *(undefined4 *)(unaff_EBP + -0x1c8);
      *(undefined4 *)(puVar20 + -8) = 0x80ed6d;
      _free(*(void **)(puVar20 + -4));
      return extraout_EAX;
    }
    iVar13 = *(int *)(unaff_EBP + -0x1c0);
    if (((*(int *)(unaff_EBP + -400) == -1) && (iVar13 == 0)) &&
       (*(char *)(unaff_EBP + -0x195) == '\0')) {
      iVar13 = -1;
    }
    *(undefined4 *)(unaff_EBP + -0x1f8) = 0x80ed9c;
    *(undefined4 *)(unaff_EBP + -0x1fc) = 0x80eda1;
    return iVar13;
  }
  *(undefined4 *)(unaff_EBP + -0x1e4) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  pbVar24 = *(byte **)(unaff_EBP + -0x1e0);
  puVar18 = *(undefined1 **)(unaff_EBP + -0x1c8);
  puVar21 = puVar20;
LAB_0080e756:
  *(undefined4 *)(puVar21 + -4) = 0x20;
  *(undefined4 *)(puVar21 + -8) = 0;
  *(undefined1 **)(puVar21 + -0xc) = puVar18;
  *(undefined4 *)(puVar21 + -0x10) = 0x80e760;
  _memset(*(void **)(puVar21 + -0xc),*(int *)(puVar21 + -8),*(size_t *)(puVar21 + -4));
  if (*(int *)(unaff_EBP + -0x1c4) != 0x7b) goto LAB_0080e7e3;
  if (*pbVar24 != 0x5d) goto LAB_0080e7e3;
  bVar15 = 0x5d;
  pbVar24 = pbVar24 + 1;
  puVar18[0xb] = 0x20;
  while (bVar14 = *pbVar24, bVar14 != 0x5d) {
    if (((bVar14 == 0x2d) && (bVar15 != 0)) && (bVar4 = pbVar24[1], bVar4 != 0x5d)) {
      pbVar24 = pbVar24 + 2;
      if (bVar15 < bVar4) {
        bVar14 = bVar15;
        bVar15 = bVar4;
      }
      else {
        bVar14 = bVar4;
      }
      if (bVar14 <= bVar15) {
        uVar16 = (uint)bVar14;
        *(uint *)(unaff_EBP + -0x1dc) = (uint)(byte)((bVar15 - bVar14) + 1);
        do {
          puVar18[uVar16 >> 3] = puVar18[uVar16 >> 3] | '\x01' << ((byte)uVar16 & 7);
          uVar16 = uVar16 + 1;
          piVar1 = (int *)(unaff_EBP + -0x1dc);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
      }
      bVar15 = 0;
    }
    else {
      *(byte *)(unaff_EBP + -0x1a1) = bVar14;
      puVar18[bVar14 >> 3] = puVar18[bVar14 >> 3] | '\x01' << (bVar14 & 7);
      pbVar24 = pbVar24 + 1;
LAB_0080e7e3:
      bVar15 = *(byte *)(unaff_EBP + -0x1a1);
    }
  }
  uVar16 = *(uint *)(unaff_EBP + -0x1c4);
  pbVar17 = *(byte **)(unaff_EBP + -0x1b8);
  puVar20 = puVar21;
  if (uVar16 == 0x7b) {
    *(byte **)(unaff_EBP + -0x19c) = pbVar24;
  }
LAB_0080e52d:
  *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + -1;
  pbVar24 = pbVar17;
  if (*(int *)(unaff_EBP + -400) != -1) {
    *(undefined4 *)(puVar20 + -4) = *(undefined4 *)(unaff_EBP + -0x194);
    *(undefined4 *)(puVar20 + -8) = *(undefined4 *)(unaff_EBP + -400);
    *(undefined4 *)(puVar20 + -0xc) = 0x80e54f;
    __ungetc_lk();
  }
  do {
    if ((*(int *)(unaff_EBP + -0x1bc) != 0) &&
       (iVar13 = *(int *)(unaff_EBP + -0x188),
       *(int *)(unaff_EBP + -0x188) = *(int *)(unaff_EBP + -0x188) + -1, iVar13 == 0))
    goto LAB_0080e92e;
    *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
    *(undefined4 *)(puVar20 + -4) = 0x80e57f;
    uVar11 = __inc();
    *(uint *)(unaff_EBP + -400) = uVar11;
    if (uVar11 == 0xffffffff) break;
    bVar15 = (byte)uVar11;
    if ((uVar16 != 99) &&
       (((uVar16 != 0x73 || ((8 < (int)uVar11 && ((int)uVar11 < 0xe)))) || (uVar11 == 0x20)))) {
      if ((uVar16 != 0x7b) ||
         (((int)(char)(*(byte *)(((int)uVar11 >> 3) + *(int *)(unaff_EBP + -0x1c8)) ^
                      *(byte *)(unaff_EBP + -0x1b1)) & 1 << (bVar15 & 7)) == 0)) break;
      uVar16 = *(uint *)(unaff_EBP + -0x1c4);
    }
    if (*(char *)(unaff_EBP + -0x18a) == '\0') {
      if (*(char *)(unaff_EBP + -0x196) == '\0') {
        *pbVar17 = bVar15;
        pbVar17 = pbVar17 + 1;
      }
      else {
        *(byte *)(unaff_EBP + -0x1cc) = bVar15;
        if ((PTR_DAT_00b49d38[(uVar11 & 0xff) * 2 + 1] & 0x80) != 0) {
          *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
          *(undefined4 *)(puVar20 + -4) = 0x80e621;
          uVar8 = __inc();
          *(undefined1 *)(unaff_EBP + -0x1cb) = uVar8;
        }
        *(undefined4 *)(puVar20 + -4) = DAT_00b49d90;
        *(int *)(puVar20 + -8) = unaff_EBP + -0x1cc;
        *(int *)(puVar20 + -0xc) = unaff_EBP + -0x1d8;
        *(undefined4 *)(puVar20 + -0x10) = 0x80e640;
        _mbtowc(*(wchar_t **)(puVar20 + -0xc),*(char **)(puVar20 + -8),*(size_t *)(puVar20 + -4));
        *(undefined2 *)pbVar17 = *(undefined2 *)(unaff_EBP + -0x1d8);
        pbVar17 = pbVar17 + 2;
      }
      *(byte **)(unaff_EBP + -0x1b8) = pbVar17;
    }
    else {
      pbVar24 = pbVar24 + 1;
    }
  } while( true );
  *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + -1;
  if (uVar11 != 0xffffffff) {
    *(undefined4 *)(puVar20 + -4) = *(undefined4 *)(unaff_EBP + -0x194);
    *(uint *)(puVar20 + -8) = uVar11;
    *(undefined4 *)(puVar20 + -0xc) = 0x80e92c;
    __ungetc_lk();
  }
LAB_0080e92e:
  if (pbVar24 == pbVar17) goto LAB_0080ed59;
  if (*(char *)(unaff_EBP + -0x18a) != '\0') goto LAB_0080e4f1;
  *(int *)(unaff_EBP + -0x1c0) = *(int *)(unaff_EBP + -0x1c0) + 1;
  if (*(int *)(unaff_EBP + -0x1c4) == 99) goto LAB_0080e4f1;
  pbVar24 = *(byte **)(unaff_EBP + -0x19c);
  if (*(char *)(unaff_EBP + -0x196) == '\0') {
    *(undefined1 *)*(undefined2 **)(unaff_EBP + -0x1b8) = 0;
  }
  else {
    **(undefined2 **)(unaff_EBP + -0x1b8) = 0;
  }
LAB_0080e4f7:
  *(char *)(unaff_EBP + -0x195) = *(char *)(unaff_EBP + -0x195) + '\x01';
  pbVar24 = pbVar24 + 1;
  *(byte **)(unaff_EBP + -0x19c) = pbVar24;
  while( true ) {
    if (*(int *)(unaff_EBP + -400) == -1) {
      if ((*pbVar24 != 0x25) || (*(char *)(*(int *)(unaff_EBP + -0x19c) + 1) != 'n'))
      goto LAB_0080ed59;
      pbVar24 = *(byte **)(unaff_EBP + -0x19c);
    }
    while( true ) {
      if (*pbVar24 == 0) goto LAB_0080ed59;
      *(uint *)(puVar20 + -4) = (uint)*pbVar24;
      *(undefined4 *)(puVar20 + -8) = 0x80dff2;
      iVar13 = _isspace(*(int *)(puVar20 + -4));
      if (iVar13 == 0) break;
      *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + -1;
      do {
        *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
        *(undefined4 *)(puVar20 + -4) = 0x80e00e;
        iVar13 = __inc();
        *(int *)(puVar20 + -4) = iVar13;
        *(undefined4 *)(puVar20 + -8) = 0x80e016;
        iVar9 = _isspace(*(int *)(puVar20 + -4));
      } while (iVar9 != 0);
      if (iVar13 != -1) {
        *(undefined4 *)(puVar20 + -4) = *(undefined4 *)(unaff_EBP + -0x194);
        *(int *)(puVar20 + -8) = iVar13;
        *(undefined4 *)(puVar20 + -0xc) = 0x80e02c;
        __ungetc_lk();
      }
      pbVar24 = *(byte **)(unaff_EBP + -0x19c);
      do {
        pbVar24 = pbVar24 + 1;
        *(uint *)(puVar20 + -4) = (uint)*pbVar24;
        *(undefined4 *)(puVar20 + -8) = 0x80e03e;
        iVar13 = _isspace(*(int *)(puVar20 + -4));
      } while (iVar13 != 0);
      *(byte **)(unaff_EBP + -0x19c) = pbVar24;
    }
    pbVar17 = *(byte **)(unaff_EBP + -0x19c);
    if (*pbVar17 == 0x25) break;
    *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
    *(undefined4 *)(puVar20 + -4) = 0x80ecbf;
    uVar16 = __inc();
    *(uint *)(unaff_EBP + -400) = uVar16;
    bVar15 = *pbVar17;
    pbVar24 = pbVar17 + 1;
    *(byte **)(unaff_EBP + -0x19c) = pbVar24;
    if (bVar15 != uVar16) goto LAB_0080ed1a;
    if ((PTR_DAT_00b49d38[(uVar16 & 0xff) * 2 + 1] & 0x80) != 0) {
      *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
      *(undefined4 *)(puVar20 + -4) = 0x80ecf6;
      uVar11 = __inc();
      bVar15 = *pbVar24;
      pbVar24 = pbVar17 + 2;
      *(byte **)(unaff_EBP + -0x19c) = pbVar24;
      if (bVar15 != uVar11) {
        if (uVar11 != 0xffffffff) {
          *(undefined4 *)(puVar20 + -4) = *(undefined4 *)(unaff_EBP + -0x194);
          *(uint *)(puVar20 + -8) = uVar11;
          *(undefined4 *)(puVar20 + -0xc) = 0x80ed15;
          __ungetc_lk();
        }
        goto LAB_0080ed1a;
      }
      *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + -1;
    }
  }
  iVar13 = 0;
  *(undefined4 *)(unaff_EBP + -0x1a8) = 0;
  *(undefined1 *)(unaff_EBP + -0x1a1) = 0;
  *(undefined4 *)(unaff_EBP + -0x1a0) = 0;
  *(undefined4 *)(unaff_EBP + -0x1bc) = 0;
  *(undefined4 *)(unaff_EBP + -0x188) = 0;
  *(undefined1 *)(unaff_EBP + -0x1b1) = 0;
  *(undefined1 *)(unaff_EBP + -0x197) = 0;
  *(undefined1 *)(unaff_EBP + -0x18a) = 0;
  *(undefined1 *)(unaff_EBP + -0x17d) = 0;
  *(undefined1 *)(unaff_EBP + -0x196) = 0;
  *(undefined1 *)(unaff_EBP + -0x189) = 0;
  *(undefined1 *)(unaff_EBP + -0x18b) = 1;
  *(undefined4 *)(unaff_EBP + -0x1d0) = 0;
  do {
    pbVar24 = pbVar17 + 1;
    uVar16 = (uint)*pbVar24;
    *(uint *)(puVar20 + -4) = uVar16;
    *(undefined4 *)(puVar20 + -8) = 0x80e0bf;
    iVar9 = _isdigit(*(int *)(puVar20 + -4));
    if (iVar9 == 0) {
      if (uVar16 < 0x4f) {
        if (uVar16 != 0x4e) {
          if (uVar16 == 0x2a) {
            *(char *)(unaff_EBP + -0x18a) = *(char *)(unaff_EBP + -0x18a) + '\x01';
          }
          else if (uVar16 != 0x46) {
            if (uVar16 == 0x49) {
              bVar15 = pbVar17[2];
              if ((bVar15 == 0x36) && (pbVar17[3] == 0x34)) {
                *(int *)(unaff_EBP + -0x1d0) = *(int *)(unaff_EBP + -0x1d0) + 1;
                *(undefined4 *)(unaff_EBP + -0x1b0) = 0;
                *(undefined4 *)(unaff_EBP + -0x1ac) = 0;
                pbVar24 = pbVar17 + 3;
              }
              else if ((bVar15 == 0x33) && (pbVar17[3] == 0x32)) {
                pbVar24 = pbVar17 + 3;
              }
              else if ((((bVar15 != 100) && (bVar15 != 0x69)) && (bVar15 != 0x6f)) &&
                      ((bVar15 != 0x78 && (bVar15 != 0x58)))) goto LAB_0080e173;
            }
            else if (uVar16 == 0x4c) {
              *(char *)(unaff_EBP + -0x18b) = *(char *)(unaff_EBP + -0x18b) + '\x01';
            }
            else {
LAB_0080e173:
              *(char *)(unaff_EBP + -0x17d) = *(char *)(unaff_EBP + -0x17d) + '\x01';
            }
          }
        }
      }
      else if (uVar16 == 0x68) {
        *(char *)(unaff_EBP + -0x18b) = *(char *)(unaff_EBP + -0x18b) + -1;
        *(char *)(unaff_EBP + -0x189) = *(char *)(unaff_EBP + -0x189) + -1;
      }
      else {
        if (uVar16 == 0x6c) {
          *(char *)(unaff_EBP + -0x18b) = *(char *)(unaff_EBP + -0x18b) + '\x01';
        }
        else if (uVar16 != 0x77) goto LAB_0080e173;
        *(char *)(unaff_EBP + -0x189) = *(char *)(unaff_EBP + -0x189) + '\x01';
      }
    }
    else {
      *(int *)(unaff_EBP + -0x1bc) = *(int *)(unaff_EBP + -0x1bc) + 1;
      iVar13 = (uVar16 - 0x30) + iVar13 * 10;
    }
    pbVar17 = pbVar24;
  } while (*(char *)(unaff_EBP + -0x17d) == '\0');
  *(int *)(unaff_EBP + -0x188) = iVar13;
  *(byte **)(unaff_EBP + -0x19c) = pbVar24;
  if (*(char *)(unaff_EBP + -0x18a) == '\0') {
    puVar5 = *(undefined4 **)(unaff_EBP + -0x1d4);
    *(undefined4 **)(unaff_EBP + -0x1e8) = puVar5;
    *(undefined4 **)(unaff_EBP + -0x1d4) = puVar5 + 1;
    pbVar17 = (byte *)*puVar5;
    *(byte **)(unaff_EBP + -0x1b8) = pbVar17;
  }
  else {
    pbVar17 = *(byte **)(unaff_EBP + -0x1b8);
  }
  *(undefined1 *)(unaff_EBP + -0x17d) = 0;
  if ((*(char *)(unaff_EBP + -0x189) == '\0') &&
     ((bVar15 = *pbVar24, bVar15 == 0x53 ||
      (*(undefined1 *)(unaff_EBP + -0x189) = 0xff, bVar15 == 0x43)))) {
    *(undefined1 *)(unaff_EBP + -0x189) = 1;
  }
  uVar16 = *pbVar24 | 0x20;
  *(uint *)(unaff_EBP + -0x1c4) = uVar16;
  if (uVar16 != 0x6e) {
    if ((uVar16 == 99) || (uVar16 == 0x7b)) {
      *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
      *(undefined4 *)(puVar20 + -4) = 0x80e25d;
      uVar10 = __inc();
      *(undefined4 *)(unaff_EBP + -400) = uVar10;
    }
    else {
      do {
        *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
        *(undefined4 *)(puVar20 + -4) = 0x80e231;
        uVar10 = __inc();
        *(undefined4 *)(puVar20 + -4) = uVar10;
        *(undefined4 *)(puVar20 + -8) = 0x80e239;
        iVar13 = _isspace(*(int *)(puVar20 + -4));
      } while (iVar13 != 0);
      *(undefined4 *)(unaff_EBP + -400) = uVar10;
      uVar16 = *(uint *)(unaff_EBP + -0x1c4);
    }
  }
  iVar13 = *(int *)(unaff_EBP + -0x1bc);
  if ((iVar13 != 0) && (*(int *)(unaff_EBP + -0x188) == 0)) {
LAB_0080e689:
    uVar16 = *(uint *)(unaff_EBP + -400);
LAB_0080ed1a:
    if (uVar16 != 0xffffffff) {
      *(undefined4 *)(puVar20 + -4) = *(undefined4 *)(unaff_EBP + -0x194);
      *(undefined4 *)(puVar20 + -8) = *(undefined4 *)(unaff_EBP + -400);
      *(undefined4 *)(puVar20 + -0xc) = 0x80ed2d;
      __ungetc_lk();
    }
    goto LAB_0080ed59;
  }
  if (0x6f < (int)uVar16) {
    if (uVar16 == 0x70) {
      *(undefined1 *)(unaff_EBP + -0x18b) = 1;
      goto LAB_0080e983;
    }
    if (uVar16 == 0x73) goto LAB_0080e51d;
    if (uVar16 == 0x75) goto LAB_0080e983;
    if (uVar16 != 0x78) {
      if (uVar16 != 0x7b) goto LAB_0080e67e;
      if ('\0' < *(char *)(unaff_EBP + -0x189)) {
        *(undefined1 *)(unaff_EBP + -0x196) = 1;
      }
      iVar13 = *(int *)(unaff_EBP + -0x19c);
      pbVar24 = (byte *)(iVar13 + 1);
      *(byte **)(unaff_EBP + -0x19c) = pbVar24;
      *(byte **)(unaff_EBP + -0x1e0) = pbVar24;
      if (*pbVar24 == 0x5e) {
        pbVar24 = (byte *)(iVar13 + 2);
        *(byte **)(unaff_EBP + -0x1e0) = pbVar24;
        *(undefined1 *)(unaff_EBP + -0x1b1) = 0xff;
      }
      puVar18 = *(undefined1 **)(unaff_EBP + -0x1c8);
      puVar21 = puVar20;
      if (puVar18 == (undefined1 *)0x0) {
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(puVar20 + -4) = 0x20;
        iVar13 = *(int *)(puVar20 + -4);
        *(undefined4 *)(puVar20 + -4) = 0x80e704;
        iVar13 = -iVar13;
        puVar21 = puVar20 + iVar13;
        puVar18 = puVar20 + iVar13;
        *(int *)(unaff_EBP + -0x18) = (int)puVar20 + iVar13;
        *(int *)(unaff_EBP + -0x1c8) = (int)puVar20 + iVar13;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
      goto LAB_0080e756;
    }
LAB_0080e2cf:
    uVar11 = *(uint *)(unaff_EBP + -400);
    if (uVar11 == 0x2d) {
      *(undefined1 *)(unaff_EBP + -0x197) = 1;
LAB_0080e81c:
      piVar1 = (int *)(unaff_EBP + -0x188);
      *piVar1 = *piVar1 + -1;
      if ((*piVar1 == 0) && (iVar13 != 0)) {
        *(undefined1 *)(unaff_EBP + -0x17d) = 1;
      }
      else {
        *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
        *(undefined4 *)(puVar20 + -4) = 0x80e842;
        uVar11 = __inc();
        *(uint *)(unaff_EBP + -400) = uVar11;
      }
    }
    else if (uVar11 == 0x2b) goto LAB_0080e81c;
    if (uVar11 == 0x30) {
      *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
      *(undefined4 *)(puVar20 + -4) = 0x80e864;
      uVar11 = __inc();
      *(uint *)(unaff_EBP + -400) = uVar11;
      if (((char)uVar11 == 'x') || ((char)uVar11 == 'X')) {
        *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
        *(undefined4 *)(puVar20 + -4) = 0x80e8d6;
        uVar11 = __inc();
        *(uint *)(unaff_EBP + -400) = uVar11;
        if ((*(int *)(unaff_EBP + -0x1bc) != 0) &&
           (*(int *)(unaff_EBP + -0x188) = *(int *)(unaff_EBP + -0x188) + -2,
           *(int *)(unaff_EBP + -0x188) < 1)) {
          *(char *)(unaff_EBP + -0x17d) = *(char *)(unaff_EBP + -0x17d) + '\x01';
        }
        *(undefined4 *)(puVar20 + -4) = 0x78;
LAB_0080e89e:
        uVar16 = *(uint *)(puVar20 + -4);
        goto LAB_0080e9ca;
      }
      *(undefined4 *)(unaff_EBP + -0x1a0) = 1;
      if (uVar16 != 0x78) {
        if (*(int *)(unaff_EBP + -0x1bc) != 0) {
          piVar1 = (int *)(unaff_EBP + -0x188);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            *(char *)(unaff_EBP + -0x17d) = *(char *)(unaff_EBP + -0x17d) + '\x01';
          }
        }
        *(undefined4 *)(puVar20 + -4) = 0x6f;
        goto LAB_0080e89e;
      }
      *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + -1;
      if (uVar11 != 0xffffffff) {
        *(undefined4 *)(puVar20 + -4) = *(undefined4 *)(unaff_EBP + -0x194);
        *(uint *)(puVar20 + -8) = uVar11;
        *(undefined4 *)(puVar20 + -0xc) = 0x80e8bb;
        __ungetc_lk();
      }
      *(undefined4 *)(puVar20 + -4) = 0x30;
      uVar11 = *(uint *)(puVar20 + -4);
      goto LAB_0080e9c4;
    }
LAB_0080e9ca:
    if (*(int *)(unaff_EBP + -0x1d0) == 0) {
      if (*(char *)(unaff_EBP + -0x17d) == '\0') {
        do {
          if ((uVar16 == 0x78) || (uVar16 == 0x70)) {
            *(uint *)(puVar20 + -4) = uVar11;
            *(undefined4 *)(puVar20 + -8) = 0x80eb8b;
            iVar13 = _isxdigit(*(int *)(puVar20 + -4));
            if (iVar13 != 0) {
              *(int *)(unaff_EBP + -0x1a8) = *(int *)(unaff_EBP + -0x1a8) << 4;
              *(uint *)(puVar20 + -4) = uVar11;
              *(undefined4 *)(puVar20 + -8) = 0x80eb9d;
              iVar13 = _isdigit(*(int *)(puVar20 + -4));
              if (iVar13 == 0) {
                uVar11 = (uVar11 & 0xffffffdf) - 7;
              }
              goto LAB_0080ebb0;
            }
LAB_0080ebaa:
            *(char *)(unaff_EBP + -0x17d) = *(char *)(unaff_EBP + -0x17d) + '\x01';
          }
          else {
            *(uint *)(puVar20 + -4) = uVar11;
            *(undefined4 *)(puVar20 + -8) = 0x80eb5a;
            iVar13 = _isdigit(*(int *)(puVar20 + -4));
            if (iVar13 == 0) goto LAB_0080ebaa;
            if (uVar16 == 0x6f) {
              if (0x37 < (int)uVar11) goto LAB_0080ebaa;
              *(int *)(unaff_EBP + -0x1a8) = *(int *)(unaff_EBP + -0x1a8) << 3;
            }
            else {
              *(int *)(unaff_EBP + -0x1a8) = *(int *)(unaff_EBP + -0x1a8) * 10;
            }
          }
LAB_0080ebb0:
          if (*(char *)(unaff_EBP + -0x17d) == '\0') {
            *(int *)(unaff_EBP + -0x1a0) = *(int *)(unaff_EBP + -0x1a0) + 1;
            *(uint *)(unaff_EBP + -0x1a8) = *(int *)(unaff_EBP + -0x1a8) + -0x30 + uVar11;
            if (*(int *)(unaff_EBP + -0x1bc) != 0) {
              piVar1 = (int *)(unaff_EBP + -0x188);
              *piVar1 = *piVar1 + -1;
              if (*piVar1 == 0) {
                *(undefined1 *)(unaff_EBP + -0x17d) = 1;
                goto LAB_0080ec17;
              }
            }
            *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
            *(undefined4 *)(puVar20 + -4) = 0x80ebfa;
            uVar11 = __inc();
          }
          else {
            *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + -1;
            if (uVar11 != 0xffffffff) {
              *(undefined4 *)(puVar20 + -4) = *(undefined4 *)(unaff_EBP + -0x194);
              *(uint *)(puVar20 + -8) = uVar11;
              *(undefined4 *)(puVar20 + -0xc) = 0x80ec15;
              __ungetc_lk();
            }
          }
LAB_0080ec17:
        } while (*(char *)(unaff_EBP + -0x17d) == '\0');
        *(uint *)(unaff_EBP + -400) = uVar11;
      }
      if (*(char *)(unaff_EBP + -0x197) != '\0') {
        *(int *)(unaff_EBP + -0x1a8) = -*(int *)(unaff_EBP + -0x1a8);
      }
    }
    else {
      if (*(char *)(unaff_EBP + -0x17d) == '\0') {
        do {
          if ((uVar16 == 0x78) || (uVar16 == 0x70)) {
            *(uint *)(puVar20 + -4) = uVar11;
            *(undefined4 *)(puVar20 + -8) = 0x80ea55;
            iVar13 = _isxdigit(*(int *)(puVar20 + -4));
            if (iVar13 != 0) {
              uVar6 = *(uint *)(unaff_EBP + -0x1b0);
              *(uint *)(unaff_EBP + -0x1b0) = uVar6 << 4;
              *(uint *)(unaff_EBP + -0x1ac) = *(int *)(unaff_EBP + -0x1ac) << 4 | uVar6 >> 0x1c;
              *(uint *)(puVar20 + -4) = uVar11;
              *(undefined4 *)(puVar20 + -8) = 0x80ea7f;
              iVar13 = _isdigit(*(int *)(puVar20 + -4));
              if (iVar13 == 0) {
                uVar11 = (uVar11 & 0xffffffdf) - 7;
              }
              goto LAB_0080ea92;
            }
LAB_0080ea8c:
            *(char *)(unaff_EBP + -0x17d) = *(char *)(unaff_EBP + -0x17d) + '\x01';
          }
          else {
            *(uint *)(puVar20 + -4) = uVar11;
            *(undefined4 *)(puVar20 + -8) = 0x80e9f4;
            iVar13 = _isdigit(*(int *)(puVar20 + -4));
            if (iVar13 == 0) goto LAB_0080ea8c;
            if (uVar16 == 0x6f) {
              if (0x37 < (int)uVar11) goto LAB_0080ea8c;
              uVar6 = *(uint *)(unaff_EBP + -0x1b0);
              *(uint *)(unaff_EBP + -0x1b0) = uVar6 << 3;
              *(uint *)(unaff_EBP + -0x1ac) = *(int *)(unaff_EBP + -0x1ac) << 3 | uVar6 >> 0x1d;
            }
            else {
              *(undefined4 *)(puVar20 + -4) = 0;
              *(undefined4 *)(puVar20 + -8) = 10;
              *(undefined4 *)(puVar20 + -0xc) = *(undefined4 *)(unaff_EBP + -0x1ac);
              *(undefined4 *)(puVar20 + -0x10) = *(undefined4 *)(unaff_EBP + -0x1b0);
              *(undefined4 *)(puVar20 + -0x14) = 0x80ea41;
              uVar25 = __allmul();
              *(undefined8 *)(unaff_EBP + -0x1b0) = uVar25;
            }
          }
LAB_0080ea92:
          if (*(char *)(unaff_EBP + -0x17d) == '\0') {
            *(int *)(unaff_EBP + -0x1a0) = *(int *)(unaff_EBP + -0x1a0) + 1;
            uVar6 = uVar11 - 0x30;
            puVar2 = (uint *)(unaff_EBP + -0x1b0);
            uVar3 = *puVar2;
            *puVar2 = *puVar2 + uVar6;
            *(int *)(unaff_EBP + -0x1ac) =
                 *(int *)(unaff_EBP + -0x1ac) + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar3,uVar6);
            if (*(int *)(unaff_EBP + -0x1bc) != 0) {
              piVar1 = (int *)(unaff_EBP + -0x188);
              *piVar1 = *piVar1 + -1;
              if (*piVar1 == 0) {
                *(undefined1 *)(unaff_EBP + -0x17d) = 1;
                goto LAB_0080eaf9;
              }
            }
            *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
            *(undefined4 *)(puVar20 + -4) = 0x80eadc;
            uVar11 = __inc();
          }
          else {
            *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + -1;
            if (uVar11 != 0xffffffff) {
              *(undefined4 *)(puVar20 + -4) = *(undefined4 *)(unaff_EBP + -0x194);
              *(uint *)(puVar20 + -8) = uVar11;
              *(undefined4 *)(puVar20 + -0xc) = 0x80eaf7;
              __ungetc_lk();
            }
          }
LAB_0080eaf9:
        } while (*(char *)(unaff_EBP + -0x17d) == '\0');
        *(uint *)(unaff_EBP + -400) = uVar11;
      }
      if (*(char *)(unaff_EBP + -0x197) != '\0') {
        iVar13 = *(int *)(unaff_EBP + -0x1b0);
        *(int *)(unaff_EBP + -0x1b0) = -iVar13;
        *(uint *)(unaff_EBP + -0x1ac) = -(*(int *)(unaff_EBP + -0x1ac) + (uint)(iVar13 != 0));
      }
    }
    if (uVar16 == 0x46) {
      *(undefined4 *)(unaff_EBP + -0x1a0) = 0;
    }
    if (*(int *)(unaff_EBP + -0x1a0) == 0) goto LAB_0080ed59;
    if (*(char *)(unaff_EBP + -0x18a) == '\0') {
      *(int *)(unaff_EBP + -0x1c0) = *(int *)(unaff_EBP + -0x1c0) + 1;
      pbVar17 = *(byte **)(unaff_EBP + -0x1b8);
      pbVar24 = *(byte **)(unaff_EBP + -0x19c);
      uVar10 = *(undefined4 *)(unaff_EBP + -0x1a8);
      goto LAB_0080ec77;
    }
LAB_0080e4f1:
    pbVar24 = *(byte **)(unaff_EBP + -0x19c);
    goto LAB_0080e4f7;
  }
  if (uVar16 == 0x6f) {
LAB_0080e983:
    uVar11 = *(uint *)(unaff_EBP + -400);
    if (uVar11 == 0x2d) {
      *(undefined1 *)(unaff_EBP + -0x197) = 1;
    }
    else if (uVar11 != 0x2b) goto LAB_0080e9ca;
    piVar1 = (int *)(unaff_EBP + -0x188);
    *piVar1 = *piVar1 + -1;
    if ((*piVar1 == 0) && (iVar13 != 0)) {
      *(undefined1 *)(unaff_EBP + -0x17d) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
      *(undefined4 *)(puVar20 + -4) = 0x80e9c2;
      uVar11 = __inc();
LAB_0080e9c4:
      *(uint *)(unaff_EBP + -400) = uVar11;
    }
    goto LAB_0080e9ca;
  }
  if (uVar16 != 99) {
    if (uVar16 == 100) goto LAB_0080e983;
    if ((int)uVar16 < 0x65) {
LAB_0080e67e:
      if ((uint)*pbVar24 != *(uint *)(unaff_EBP + -400)) goto LAB_0080e689;
      *(char *)(unaff_EBP + -0x195) = *(char *)(unaff_EBP + -0x195) + -1;
      if (*(char *)(unaff_EBP + -0x18a) == '\0') {
        *(undefined4 *)(unaff_EBP + -0x1d4) = *(undefined4 *)(unaff_EBP + -0x1e8);
      }
    }
    else {
      if ((int)uVar16 < 0x68) {
        pcVar22 = (char *)(unaff_EBP + -0x17c);
        iVar13 = *(int *)(unaff_EBP + -400);
        if (iVar13 == 0x2d) {
          *(undefined1 *)(unaff_EBP + -0x17c) = 0x2d;
          pcVar22 = (char *)(unaff_EBP + -0x17b);
LAB_0080e30e:
          *(int *)(unaff_EBP + -0x188) = *(int *)(unaff_EBP + -0x188) + -1;
          *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
          uVar10 = *(undefined4 *)(unaff_EBP + -0x194);
          *(undefined4 *)(puVar20 + -4) = 0x80e327;
          iVar13 = __inc();
          *(int *)(unaff_EBP + -400) = iVar13;
        }
        else {
          if (iVar13 == 0x2b) goto LAB_0080e30e;
          uVar10 = *(undefined4 *)(unaff_EBP + -0x194);
        }
        if ((*(int *)(unaff_EBP + -0x1bc) == 0) || (0x15d < *(int *)(unaff_EBP + -0x188))) {
          *(undefined4 *)(unaff_EBP + -0x188) = 0x15d;
        }
        while( true ) {
          *(int *)(puVar20 + -4) = iVar13;
          *(undefined4 *)(puVar20 + -8) = 0x80e38c;
          iVar9 = _isdigit(*(int *)(puVar20 + -4));
          if ((iVar9 == 0) ||
             (iVar9 = *(int *)(unaff_EBP + -0x188),
             *(int *)(unaff_EBP + -0x188) = *(int *)(unaff_EBP + -0x188) + -1, iVar9 == 0)) break;
          *(int *)(unaff_EBP + -0x1a0) = *(int *)(unaff_EBP + -0x1a0) + 1;
          *pcVar22 = (char)iVar13;
          pcVar22 = pcVar22 + 1;
          *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
          *(undefined4 *)(puVar20 + -4) = 0x80e37e;
          iVar13 = __inc();
          *(int *)(unaff_EBP + -400) = iVar13;
        }
        if ((DAT_00b49d94 == (char)iVar13) &&
           (iVar9 = *(int *)(unaff_EBP + -0x188),
           *(int *)(unaff_EBP + -0x188) = *(int *)(unaff_EBP + -0x188) + -1, iVar9 != 0)) {
          *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
          *(undefined4 *)(puVar20 + -4) = 0x80e3b6;
          iVar13 = __inc();
          *pcVar22 = DAT_00b49d94;
          while( true ) {
            pcVar22 = pcVar22 + 1;
            *(int *)(puVar20 + -4) = iVar13;
            *(int *)(unaff_EBP + -400) = iVar13;
            *(undefined4 *)(puVar20 + -8) = 0x80e3f6;
            iVar9 = _isdigit(*(int *)(puVar20 + -4));
            if ((iVar9 == 0) ||
               (iVar9 = *(int *)(unaff_EBP + -0x188),
               *(int *)(unaff_EBP + -0x188) = *(int *)(unaff_EBP + -0x188) + -1, iVar9 == 0)) break;
            *(int *)(unaff_EBP + -0x1a0) = *(int *)(unaff_EBP + -0x1a0) + 1;
            *pcVar22 = (char)iVar13;
            *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
            *(undefined4 *)(puVar20 + -4) = 0x80e3e8;
            iVar13 = __inc();
          }
        }
        pcVar23 = pcVar22;
        if ((*(int *)(unaff_EBP + -0x1a0) != 0) &&
           (((iVar13 == 0x65 || (iVar13 == 0x45)) &&
            (iVar9 = *(int *)(unaff_EBP + -0x188),
            *(int *)(unaff_EBP + -0x188) = *(int *)(unaff_EBP + -0x188) + -1, iVar9 != 0)))) {
          *pcVar22 = 'e';
          pcVar23 = pcVar22 + 1;
          *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
          *(undefined4 *)(puVar20 + -4) = 0x80e437;
          iVar13 = __inc();
          *(int *)(unaff_EBP + -400) = iVar13;
          if (iVar13 == 0x2d) {
            *pcVar23 = '-';
            pcVar23 = pcVar22 + 2;
LAB_0080e44e:
            iVar9 = *(int *)(unaff_EBP + -0x188);
            *(int *)(unaff_EBP + -0x188) = *(int *)(unaff_EBP + -0x188) + -1;
            if (iVar9 != 0) goto LAB_0080e47f;
            *(undefined4 *)(unaff_EBP + -0x188) = 0;
          }
          else if (iVar13 == 0x2b) goto LAB_0080e44e;
          while( true ) {
            *(int *)(puVar20 + -4) = iVar13;
            *(undefined4 *)(puVar20 + -8) = 0x80e49a;
            iVar9 = _isdigit(*(int *)(puVar20 + -4));
            if ((iVar9 == 0) ||
               (iVar9 = *(int *)(unaff_EBP + -0x188),
               *(int *)(unaff_EBP + -0x188) = *(int *)(unaff_EBP + -0x188) + -1, iVar9 == 0)) break;
            *(int *)(unaff_EBP + -0x1a0) = *(int *)(unaff_EBP + -0x1a0) + 1;
            *pcVar23 = (char)iVar13;
            pcVar23 = pcVar23 + 1;
LAB_0080e47f:
            *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + 1;
            *(undefined4 *)(puVar20 + -4) = 0x80e48c;
            iVar13 = __inc();
            *(int *)(unaff_EBP + -400) = iVar13;
          }
        }
        *(int *)(unaff_EBP + -0x184) = *(int *)(unaff_EBP + -0x184) + -1;
        if (iVar13 != -1) {
          *(undefined4 *)(puVar20 + -4) = uVar10;
          *(int *)(puVar20 + -8) = iVar13;
          *(undefined4 *)(puVar20 + -0xc) = 0x80e4b1;
          __ungetc_lk();
        }
        if (*(int *)(unaff_EBP + -0x1a0) != 0) {
          if (*(char *)(unaff_EBP + -0x18a) == '\0') {
            *(int *)(unaff_EBP + -0x1c0) = *(int *)(unaff_EBP + -0x1c0) + 1;
            *pcVar23 = '\0';
            *(int *)(puVar20 + -4) = unaff_EBP + -0x17c;
            *(undefined4 *)(puVar20 + -8) = *(undefined4 *)(unaff_EBP + -0x1b8);
            *(int *)(puVar20 + -0xc) = *(char *)(unaff_EBP + -0x18b) + -1;
            puVar7 = PTR___fassign_00b49da4;
            puVar19 = puVar20 + -0x10;
            *(undefined4 *)(puVar20 + -0x10) = 0x80e4ee;
            (*(code *)puVar7)();
            puVar20 = puVar19 + 0xc;
          }
          goto LAB_0080e4f1;
        }
        goto LAB_0080ed59;
      }
      if (uVar16 == 0x69) {
        *(undefined4 *)(puVar20 + -4) = 100;
        uVar16 = *(uint *)(puVar20 + -4);
        goto LAB_0080e2cf;
      }
      if (uVar16 != 0x6e) goto LAB_0080e67e;
      uVar10 = *(undefined4 *)(unaff_EBP + -0x184);
      if (*(char *)(unaff_EBP + -0x18a) == '\0') {
LAB_0080ec77:
        if (*(int *)(unaff_EBP + -0x1d0) == 0) {
          if (*(char *)(unaff_EBP + -0x18b) == '\0') {
            *(short *)pbVar17 = (short)uVar10;
          }
          else {
            *(undefined4 *)pbVar17 = uVar10;
          }
        }
        else {
          *(undefined4 *)pbVar17 = *(undefined4 *)(unaff_EBP + -0x1b0);
          *(undefined4 *)(pbVar17 + 4) = *(undefined4 *)(unaff_EBP + -0x1ac);
        }
      }
    }
    goto LAB_0080e4f7;
  }
  if (iVar13 == 0) {
    *(undefined4 *)(unaff_EBP + -0x1bc) = 1;
    *(int *)(unaff_EBP + -0x188) = *(int *)(unaff_EBP + -0x188) + 1;
  }
LAB_0080e51d:
  if ('\0' < *(char *)(unaff_EBP + -0x189)) {
    *(undefined1 *)(unaff_EBP + -0x196) = 1;
  }
  goto LAB_0080e52d;
}


// ==== FUN_0080eda2 @ 0x0080eda2 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint * FUN_0080eda2(uint *param_1,int param_2)

{
  INTRNCVT_STATUS IVar1;
  uint uVar2;
  int local_28;
  int local_24;
  _CRT_DOUBLE local_20;
  uint local_18;
  _LDBL12 local_14;
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (uint)((&local_14)[1].ld12 + 4);
  local_24 = param_2;
  uVar2 = 0;
  local_18 = FUN_00813efb(&local_14,&local_28,param_2,0,0,0,0);
  if ((local_18 & 4) == 0) {
    IVar1 = FID_conflict___ld12tod(&local_14,&local_20);
    if (((local_18 & 2) != 0) || (IVar1 == INTRNCVT_OVERFLOW)) {
      uVar2 = 0x80;
    }
    if (((local_18 & 1) != 0) || (IVar1 == INTRNCVT_UNDERFLOW)) {
      uVar2 = uVar2 | 0x100;
    }
  }
  else {
    uVar2 = 0x200;
    local_20.x._0_4_ = 0;
    local_20.x._4_4_ = 0;
  }
  param_1[1] = local_28 - local_24;
  param_1[4] = local_20.x._0_4_;
  param_1[5] = local_20.x._4_4_;
  *param_1 = uVar2;
  return param_1;
}


// ==== ___sbh_heap_init @ 0x0080ee43 ====

/* Library Function - Single Match
    ___sbh_heap_init
   
   Library: Visual Studio 2003 Release */

undefined4 ___sbh_heap_init(undefined4 param_1)

{
  DAT_00b60f48 = HeapAlloc(DAT_00b60f78,0,0x140);
  if (DAT_00b60f48 == (LPVOID)0x0) {
    return 0;
  }
  DAT_00b60f40 = 0;
  DAT_00b60f44 = 0;
  DAT_00b60f50 = DAT_00b60f48;
  DAT_00b60f4c = param_1;
  DAT_00b60f54 = 0x10;
  return 1;
}


// ==== ___sbh_find_block @ 0x0080ee8b ====

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 2003 Release */

uint ___sbh_find_block(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_00b60f48;
  while( true ) {
    if (DAT_00b60f48 + DAT_00b60f44 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}


// ==== ___sbh_free_block @ 0x0080eeb6 ====

/* Library Function - Single Match
    ___sbh_free_block
   
   Library: Visual Studio 2003 Release */

void ___sbh_free_block(uint *param_1,int param_2)

{
  int *piVar1;
  char *pcVar2;
  uint *puVar3;
  int *piVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint local_8;
  
  uVar6 = param_1[4];
  puVar12 = (uint *)(param_2 + -4);
  uVar14 = param_2 - param_1[3] >> 0xf;
  piVar4 = (int *)(uVar14 * 0x204 + 0x144 + uVar6);
  local_8 = *puVar12 - 1;
  if ((local_8 & 1) == 0) {
    puVar10 = (uint *)(local_8 + (int)puVar12);
    uVar13 = *puVar10;
    uVar7 = *(uint *)(param_2 + -8);
    if ((uVar13 & 1) == 0) {
      uVar9 = ((int)uVar13 >> 4) - 1;
      if (0x3f < uVar9) {
        uVar9 = 0x3f;
      }
      if (puVar10[1] == puVar10[2]) {
        if (uVar9 < 0x20) {
          pcVar2 = (char *)(uVar9 + 4 + uVar6);
          uVar9 = ~(0x80000000U >> ((byte)uVar9 & 0x1f));
          puVar11 = (uint *)(uVar6 + 0x44 + uVar14 * 4);
          *puVar11 = *puVar11 & uVar9;
          *pcVar2 = *pcVar2 + -1;
          if (*pcVar2 == '\0') {
            *param_1 = *param_1 & uVar9;
          }
        }
        else {
          pcVar2 = (char *)(uVar9 + 4 + uVar6);
          uVar9 = ~(0x80000000U >> ((byte)uVar9 - 0x20 & 0x1f));
          puVar11 = (uint *)(uVar6 + 0xc4 + uVar14 * 4);
          *puVar11 = *puVar11 & uVar9;
          *pcVar2 = *pcVar2 + -1;
          if (*pcVar2 == '\0') {
            param_1[1] = param_1[1] & uVar9;
          }
        }
      }
      local_8 = local_8 + uVar13;
      *(uint *)(puVar10[2] + 4) = puVar10[1];
      *(uint *)(puVar10[1] + 8) = puVar10[2];
    }
    puVar10 = (uint *)(((int)local_8 >> 4) + -1);
    if ((uint *)0x3f < puVar10) {
      puVar10 = (uint *)0x3f;
    }
    if ((uVar7 & 1) == 0) {
      puVar12 = (uint *)((int)puVar12 - uVar7);
      puVar11 = (uint *)(((int)uVar7 >> 4) + -1);
      if ((uint *)0x3f < puVar11) {
        puVar11 = (uint *)0x3f;
      }
      local_8 = local_8 + uVar7;
      puVar10 = (uint *)(((int)local_8 >> 4) + -1);
      if ((uint *)0x3f < puVar10) {
        puVar10 = (uint *)0x3f;
      }
      if (puVar11 != puVar10) {
        if (puVar12[1] == puVar12[2]) {
          if (puVar11 < (uint *)0x20) {
            uVar13 = ~(0x80000000U >> ((byte)puVar11 & 0x1f));
            puVar3 = (uint *)(uVar6 + 0x44 + uVar14 * 4);
            *puVar3 = *puVar3 & uVar13;
            pcVar2 = (char *)((int)puVar11 + uVar6 + 4);
            *pcVar2 = *pcVar2 + -1;
            if (*pcVar2 == '\0') {
              *param_1 = *param_1 & uVar13;
            }
          }
          else {
            uVar13 = ~(0x80000000U >> ((byte)puVar11 - 0x20 & 0x1f));
            puVar3 = (uint *)(uVar6 + 0xc4 + uVar14 * 4);
            *puVar3 = *puVar3 & uVar13;
            pcVar2 = (char *)((int)puVar11 + uVar6 + 4);
            *pcVar2 = *pcVar2 + -1;
            if (*pcVar2 == '\0') {
              param_1[1] = param_1[1] & uVar13;
            }
          }
        }
        *(uint *)(puVar12[2] + 4) = puVar12[1];
        *(uint *)(puVar12[1] + 8) = puVar12[2];
      }
    }
    else {
      puVar11 = param_1;
    }
    if (((uVar7 & 1) != 0) || (puVar11 != puVar10)) {
      piVar1 = piVar4 + (int)puVar10 * 2;
      uVar13 = piVar1[1];
      puVar12[2] = (uint)piVar1;
      puVar12[1] = uVar13;
      piVar1[1] = (int)puVar12;
      *(uint **)(puVar12[1] + 8) = puVar12;
      if (puVar12[1] == puVar12[2]) {
        cVar5 = *(char *)((int)puVar10 + uVar6 + 4);
        *(char *)((int)puVar10 + uVar6 + 4) = cVar5 + '\x01';
        bVar8 = (byte)puVar10;
        if (puVar10 < (uint *)0x20) {
          if (cVar5 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
          }
          puVar10 = (uint *)(uVar6 + 0x44 + uVar14 * 4);
          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 & 0x1f);
        }
        else {
          if (cVar5 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
          }
          puVar10 = (uint *)(uVar6 + 0xc4 + uVar14 * 4);
          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
      }
    }
    *puVar12 = local_8;
    *(uint *)((local_8 - 4) + (int)puVar12) = local_8;
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      if (DAT_00b60f40 != (uint *)0x0) {
        VirtualFree((LPVOID)(DAT_00b60f58 * 0x8000 + DAT_00b60f40[3]),0x8000,0x4000);
        DAT_00b60f40[2] = DAT_00b60f40[2] | 0x80000000U >> ((byte)DAT_00b60f58 & 0x1f);
        *(undefined4 *)(DAT_00b60f40[4] + 0xc4 + DAT_00b60f58 * 4) = 0;
        *(char *)(DAT_00b60f40[4] + 0x43) = *(char *)(DAT_00b60f40[4] + 0x43) + -1;
        if (*(char *)(DAT_00b60f40[4] + 0x43) == '\0') {
          DAT_00b60f40[1] = DAT_00b60f40[1] & 0xfffffffe;
        }
        if (DAT_00b60f40[2] == 0xffffffff) {
          VirtualFree((LPVOID)DAT_00b60f40[3],0,0x8000);
          HeapFree(DAT_00b60f78,0,(LPVOID)DAT_00b60f40[4]);
          _memmove(DAT_00b60f40,DAT_00b60f40 + 5,
                   (DAT_00b60f44 * 0x14 - (int)DAT_00b60f40) + -0x14 + DAT_00b60f48);
          DAT_00b60f44 = DAT_00b60f44 + -1;
          if (DAT_00b60f40 < param_1) {
            param_1 = param_1 + -5;
          }
          DAT_00b60f50 = DAT_00b60f48;
        }
      }
      DAT_00b60f40 = param_1;
      DAT_00b60f58 = uVar14;
    }
  }
  return;
}


// ==== ___sbh_alloc_new_region @ 0x0080f1ce ====

/* Library Function - Single Match
    ___sbh_alloc_new_region
   
   Library: Visual Studio 2003 Release */

undefined4 * ___sbh_alloc_new_region(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_00b60f44 == DAT_00b60f54) {
    pvVar2 = HeapReAlloc(DAT_00b60f78,0,DAT_00b60f48,(DAT_00b60f54 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_00b60f54 = DAT_00b60f54 + 0x10;
    DAT_00b60f48 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_00b60f48 + DAT_00b60f44 * 0x14);
  pvVar2 = HeapAlloc(DAT_00b60f78,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_00b60f44 = DAT_00b60f44 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_00b60f78,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}


// ==== ___sbh_alloc_new_group @ 0x0080f285 ====

/* Library Function - Single Match
    ___sbh_alloc_new_group
   
   Library: Visual Studio 2003 Release */

int ___sbh_alloc_new_group(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  LPVOID pvVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  LPVOID lpAddress;
  
  iVar2 = *(int *)(param_1 + 0x10);
  iVar8 = 0;
  for (iVar3 = *(int *)(param_1 + 8); -1 < iVar3; iVar3 = iVar3 << 1) {
    iVar8 = iVar8 + 1;
  }
  iVar3 = iVar8 * 0x204 + 0x144 + iVar2;
  iVar7 = 0x3f;
  iVar4 = iVar3;
  do {
    *(int *)(iVar4 + 8) = iVar4;
    *(int *)(iVar4 + 4) = iVar4;
    iVar4 = iVar4 + 8;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  lpAddress = (LPVOID)(iVar8 * 0x8000 + *(int *)(param_1 + 0xc));
  pvVar5 = VirtualAlloc(lpAddress,0x8000,0x1000,4);
  if (pvVar5 == (LPVOID)0x0) {
    iVar8 = -1;
  }
  else {
    if (lpAddress <= (LPVOID)((int)lpAddress + 0x7000U)) {
      piVar6 = (int *)((int)lpAddress + 0x10);
      iVar7 = ((uint)((int)((int)lpAddress + 0x7000U) - (int)lpAddress) >> 0xc) + 1;
      do {
        piVar6[-2] = -1;
        piVar6[0x3fb] = -1;
        *piVar6 = (int)(piVar6 + 0x3ff);
        piVar6[-1] = 0xff0;
        piVar6[1] = (int)(piVar6 + -0x401);
        piVar6[0x3fa] = 0xff0;
        piVar6 = piVar6 + 0x400;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    *(int *)(iVar3 + 0x1fc) = (int)lpAddress + 0xc;
    *(int *)((int)lpAddress + 0x14) = iVar3 + 0x1f8;
    *(int *)(iVar3 + 0x200) = (int)lpAddress + 0x700c;
    *(int *)((int)lpAddress + 0x7010) = iVar3 + 0x1f8;
    *(undefined4 *)(iVar2 + 0x44 + iVar8 * 4) = 0;
    *(undefined4 *)(iVar2 + 0xc4 + iVar8 * 4) = 1;
    cVar1 = *(char *)(iVar2 + 0x43);
    *(char *)(iVar2 + 0x43) = cVar1 + '\x01';
    if (cVar1 == '\0') {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    }
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & ~(0x80000000U >> ((byte)iVar8 & 0x1f));
  }
  return iVar8;
}


// ==== ___sbh_resize_block @ 0x0080f38b ====

/* Library Function - Single Match
    ___sbh_resize_block
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

undefined4 ___sbh_resize_block(uint *param_1,int param_2,int param_3)

{
  char *pcVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_c;
  
  uVar8 = param_1[4];
  uVar10 = param_2 - param_1[3] >> 0xf;
  iVar5 = uVar10 * 0x204 + 0x144 + uVar8;
  uVar12 = param_3 + 0x17U & 0xfffffff0;
  param_3 = *(int *)(param_2 + -4) + -1;
  puVar9 = (uint *)(*(int *)(param_2 + -4) + -5 + param_2);
  uVar13 = *puVar9;
  if (param_3 < (int)uVar12) {
    if (((uVar13 & 1) != 0) || ((int)(uVar13 + param_3) < (int)uVar12)) {
      return 0;
    }
    local_c = ((int)uVar13 >> 4) - 1;
    if (0x3f < local_c) {
      local_c = 0x3f;
    }
    if (puVar9[1] == puVar9[2]) {
      if (local_c < 0x20) {
        pcVar1 = (char *)(local_c + 4 + uVar8);
        uVar11 = ~(0x80000000U >> ((byte)local_c & 0x1f));
        puVar2 = (uint *)(uVar8 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(local_c + 4 + uVar8);
        uVar11 = ~(0x80000000U >> ((byte)local_c - 0x20 & 0x1f));
        puVar2 = (uint *)(uVar8 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(uint *)(puVar9[2] + 4) = puVar9[1];
    *(uint *)(puVar9[1] + 8) = puVar9[2];
    iVar6 = uVar13 + (param_3 - uVar12);
    if (0 < iVar6) {
      uVar13 = (iVar6 >> 4) - 1;
      iVar3 = param_2 + -4 + uVar12;
      if (0x3f < uVar13) {
        uVar13 = 0x3f;
      }
      iVar5 = iVar5 + uVar13 * 8;
      *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar5 + 4);
      *(int *)(iVar3 + 8) = iVar5;
      *(int *)(iVar5 + 4) = iVar3;
      *(int *)(*(int *)(iVar3 + 4) + 8) = iVar3;
      if (*(int *)(iVar3 + 4) == *(int *)(iVar3 + 8)) {
        cVar7 = *(char *)(uVar13 + 4 + uVar8);
        *(char *)(uVar13 + 4 + uVar8) = cVar7 + '\x01';
        if (uVar13 < 0x20) {
          if (cVar7 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> ((byte)uVar13 & 0x1f);
          }
          puVar9 = (uint *)(uVar8 + 0x44 + uVar10 * 4);
        }
        else {
          if (cVar7 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> ((byte)uVar13 - 0x20 & 0x1f);
          }
          puVar9 = (uint *)(uVar8 + 0xc4 + uVar10 * 4);
          uVar13 = uVar13 - 0x20;
        }
        *puVar9 = *puVar9 | 0x80000000U >> ((byte)uVar13 & 0x1f);
      }
      piVar4 = (int *)(param_2 + -4 + uVar12);
      *piVar4 = iVar6;
      *(int *)(iVar6 + -4 + (int)piVar4) = iVar6;
    }
    *(uint *)(param_2 + -4) = uVar12 + 1;
    *(uint *)(param_2 + -8 + uVar12) = uVar12 + 1;
  }
  else if ((int)uVar12 < param_3) {
    param_3 = param_3 - uVar12;
    *(uint *)(param_2 + -4) = uVar12 + 1;
    piVar4 = (int *)(param_2 + -4 + uVar12);
    uVar11 = (param_3 >> 4) - 1;
    piVar4[-1] = uVar12 + 1;
    if (0x3f < uVar11) {
      uVar11 = 0x3f;
    }
    if ((uVar13 & 1) == 0) {
      uVar12 = ((int)uVar13 >> 4) - 1;
      if (0x3f < uVar12) {
        uVar12 = 0x3f;
      }
      if (puVar9[1] == puVar9[2]) {
        if (uVar12 < 0x20) {
          pcVar1 = (char *)(uVar12 + 4 + uVar8);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 & 0x1f));
          puVar2 = (uint *)(uVar8 + 0x44 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar12;
          }
        }
        else {
          pcVar1 = (char *)(uVar12 + 4 + uVar8);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 - 0x20 & 0x1f));
          puVar2 = (uint *)(uVar8 + 0xc4 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar12;
          }
        }
      }
      *(uint *)(puVar9[2] + 4) = puVar9[1];
      *(uint *)(puVar9[1] + 8) = puVar9[2];
      param_3 = param_3 + uVar13;
      uVar11 = (param_3 >> 4) - 1;
      if (0x3f < uVar11) {
        uVar11 = 0x3f;
      }
    }
    iVar5 = iVar5 + uVar11 * 8;
    iVar6 = *(int *)(iVar5 + 4);
    piVar4[2] = iVar5;
    piVar4[1] = iVar6;
    *(int **)(iVar5 + 4) = piVar4;
    *(int **)(piVar4[1] + 8) = piVar4;
    if (piVar4[1] == piVar4[2]) {
      cVar7 = *(char *)(uVar11 + 4 + uVar8);
      *(char *)(uVar11 + 4 + uVar8) = cVar7 + '\x01';
      if (uVar11 < 0x20) {
        if (cVar7 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> ((byte)uVar11 & 0x1f);
        }
        puVar9 = (uint *)(uVar8 + 0x44 + uVar10 * 4);
      }
      else {
        if (cVar7 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> ((byte)uVar11 - 0x20 & 0x1f);
        }
        puVar9 = (uint *)(uVar8 + 0xc4 + uVar10 * 4);
        uVar11 = uVar11 - 0x20;
      }
      *puVar9 = *puVar9 | 0x80000000U >> ((byte)uVar11 & 0x1f);
    }
    *piVar4 = param_3;
    *(int *)(param_3 + -4 + (int)piVar4) = param_3;
  }
  return 1;
}


// ==== ___sbh_alloc_block @ 0x0080f66a ====

/* Library Function - Single Match
    ___sbh_alloc_block
   
   Library: Visual Studio 2003 Release */

int * ___sbh_alloc_block(uint *param_1)

{
  uint *puVar1;
  int *piVar2;
  char *pcVar3;
  int *piVar4;
  char cVar5;
  int *piVar6;
  undefined4 uVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  uint local_c;
  int local_8;
  
  uVar9 = (int)param_1 + 0x17U & 0xfffffff0;
  iVar10 = (int)((int)param_1 + 0x17U) >> 4;
  iVar11 = iVar10 + -1;
  puVar12 = DAT_00b60f48 + DAT_00b60f44 * 5;
  if (iVar11 < 0x20) {
    uVar15 = 0xffffffff >> ((byte)iVar11 & 0x1f);
    local_c = 0xffffffff;
  }
  else {
    uVar15 = 0;
    local_c = 0xffffffff >> ((char)iVar10 - 0x21U & 0x1f);
  }
  for (param_1 = DAT_00b60f50;
      (param_1 < puVar12 && ((param_1[1] & local_c) == 0 && (*param_1 & uVar15) == 0));
      param_1 = param_1 + 5) {
  }
  if (param_1 == puVar12) {
    for (param_1 = DAT_00b60f48;
        (param_1 < DAT_00b60f50 && ((param_1[1] & local_c) == 0 && (*param_1 & uVar15) == 0));
        param_1 = param_1 + 5) {
    }
    if (param_1 == DAT_00b60f50) {
      for (; (param_1 < puVar12 && (param_1[2] == 0)); param_1 = param_1 + 5) {
      }
      if (param_1 == puVar12) {
        for (param_1 = DAT_00b60f48; (param_1 < DAT_00b60f50 && (param_1[2] == 0));
            param_1 = param_1 + 5) {
        }
        if ((param_1 == DAT_00b60f50) &&
           (param_1 = (uint *)___sbh_alloc_new_region(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      uVar7 = ___sbh_alloc_new_group(param_1);
      *(undefined4 *)param_1[4] = uVar7;
      if (*(int *)param_1[4] == -1) {
        return (int *)0x0;
      }
    }
  }
  piVar6 = (int *)param_1[4];
  local_8 = *piVar6;
  if ((local_8 == -1) ||
     ((piVar6[local_8 + 0x31] & local_c) == 0 && (piVar6[local_8 + 0x11] & uVar15) == 0)) {
    local_8 = 0;
    puVar12 = (uint *)(piVar6 + 0x11);
    if ((piVar6[0x31] & local_c) == 0 && (*puVar12 & uVar15) == 0) {
      do {
        puVar1 = puVar12 + 0x21;
        local_8 = local_8 + 1;
        puVar12 = puVar12 + 1;
      } while ((*puVar1 & local_c) == 0 && (*puVar12 & uVar15) == 0);
    }
  }
  piVar4 = piVar6 + local_8 * 0x81 + 0x51;
  iVar10 = 0;
  uVar15 = piVar6[local_8 + 0x11] & uVar15;
  if (uVar15 == 0) {
    uVar15 = piVar6[local_8 + 0x31] & local_c;
    iVar10 = 0x20;
  }
  for (; -1 < (int)uVar15; uVar15 = uVar15 << 1) {
    iVar10 = iVar10 + 1;
  }
  piVar14 = (int *)piVar4[iVar10 * 2 + 1];
  iVar13 = *piVar14 - uVar9;
  iVar11 = (iVar13 >> 4) + -1;
  if (0x3f < iVar11) {
    iVar11 = 0x3f;
  }
  DAT_00b60f50 = param_1;
  if (iVar11 != iVar10) {
    if (piVar14[1] == piVar14[2]) {
      if (iVar10 < 0x20) {
        pcVar3 = (char *)((int)piVar6 + iVar10 + 4);
        uVar15 = ~(0x80000000U >> ((byte)iVar10 & 0x1f));
        piVar6[local_8 + 0x11] = uVar15 & piVar6[local_8 + 0x11];
        *pcVar3 = *pcVar3 + -1;
        if (*pcVar3 == '\0') {
          *param_1 = *param_1 & uVar15;
        }
      }
      else {
        pcVar3 = (char *)((int)piVar6 + iVar10 + 4);
        uVar15 = ~(0x80000000U >> ((byte)iVar10 - 0x20 & 0x1f));
        piVar6[local_8 + 0x31] = piVar6[local_8 + 0x31] & uVar15;
        *pcVar3 = *pcVar3 + -1;
        if (*pcVar3 == '\0') {
          param_1[1] = param_1[1] & uVar15;
        }
      }
    }
    *(int *)(piVar14[2] + 4) = piVar14[1];
    *(int *)(piVar14[1] + 8) = piVar14[2];
    if (iVar13 == 0) goto LAB_0080f923;
    piVar2 = piVar4 + iVar11 * 2;
    iVar10 = piVar2[1];
    piVar14[2] = (int)piVar2;
    piVar14[1] = iVar10;
    piVar2[1] = (int)piVar14;
    *(int **)(piVar14[1] + 8) = piVar14;
    if (piVar14[1] == piVar14[2]) {
      cVar5 = *(char *)(iVar11 + 4 + (int)piVar6);
      *(char *)(iVar11 + 4 + (int)piVar6) = cVar5 + '\x01';
      bVar8 = (byte)iVar11;
      if (iVar11 < 0x20) {
        if (cVar5 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
        }
        piVar6[local_8 + 0x11] = piVar6[local_8 + 0x11] | 0x80000000U >> (bVar8 & 0x1f);
      }
      else {
        if (cVar5 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        piVar6[local_8 + 0x31] = piVar6[local_8 + 0x31] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
      }
    }
  }
  if (iVar13 != 0) {
    *piVar14 = iVar13;
    *(int *)(iVar13 + -4 + (int)piVar14) = iVar13;
  }
LAB_0080f923:
  piVar14 = (int *)((int)piVar14 + iVar13);
  *piVar14 = uVar9 + 1;
  *(uint *)((int)piVar14 + (uVar9 - 4)) = uVar9 + 1;
  iVar10 = *piVar4;
  *piVar4 = iVar10 + 1;
  if (((iVar10 == 0) && (param_1 == DAT_00b60f40)) && (local_8 == DAT_00b60f58)) {
    DAT_00b60f40 = (uint *)0x0;
  }
  *piVar6 = local_8;
  return piVar14 + 1;
}


// ==== __filbuf @ 0x0080f966 ====

/* Library Function - Single Match
    __filbuf
   
   Library: Visual Studio 2003 Release */

int __cdecl __filbuf(FILE *_File)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar2 = _File->_flag;
  if (((uVar2 & 0x83) != 0) && ((uVar2 & 0x40) == 0)) {
    if ((uVar2 & 2) == 0) {
      _File->_flag = uVar2 | 1;
      if ((uVar2 & 0x10c) == 0) {
        __getbuf(_File);
      }
      else {
        _File->_ptr = _File->_base;
      }
      iVar3 = __read(_File->_file,_File->_base,_File->_bufsiz);
      _File->_cnt = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) {
        if ((_File->_flag & 0x82U) == 0) {
          uVar2 = _File->_file;
          if (uVar2 == 0xffffffff) {
            puVar4 = &DAT_00b49d10;
          }
          else {
            puVar4 = (undefined *)((&DAT_00b60fa0)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
          }
          if ((puVar4[4] & 0x82) == 0x82) {
            _File->_flag = _File->_flag | 0x2000;
          }
        }
        if (((_File->_bufsiz == 0x200) && ((_File->_flag & 8U) != 0)) &&
           ((_File->_flag & 0x400U) == 0)) {
          _File->_bufsiz = 0x1000;
        }
        _File->_cnt = iVar3 + -1;
        bVar1 = *_File->_ptr;
        _File->_ptr = _File->_ptr + 1;
        return (uint)bVar1;
      }
      _File->_flag = _File->_flag | (-(uint)(iVar3 != 0) & 0x10) + 0x10;
      _File->_cnt = 0;
    }
    else {
      _File->_flag = uVar2 | 0x20;
    }
  }
  return -1;
}


// ==== __stbuf @ 0x0080fa47 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __stbuf
   
   Library: Visual Studio 2003 Release */

int __cdecl __stbuf(FILE *_File)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  void *pvVar4;
  
  iVar3 = __isatty(_File->_file);
  if (iVar3 == 0) {
    return 0;
  }
  if (_File == (FILE *)&DAT_00b496a0) {
    iVar3 = 0;
  }
  else {
    if (_File != (FILE *)&DAT_00b496c0) {
      return 0;
    }
    iVar3 = 1;
  }
  _DAT_00b5c644 = _DAT_00b5c644 + 1;
  if ((_File->_flag & 0x10c) != 0) {
    return 0;
  }
  piVar1 = &DAT_00b5cb7c + iVar3;
  if (*piVar1 == 0) {
    pvVar4 = _malloc(0x1000);
    *piVar1 = (int)pvVar4;
    if (pvVar4 == (void *)0x0) {
      _File->_base = (char *)&_File->_charbuf;
      _File->_ptr = (char *)&_File->_charbuf;
      _File->_bufsiz = 2;
      _File->_cnt = 2;
      goto LAB_0080fabe;
    }
  }
  pcVar2 = (char *)*piVar1;
  _File->_base = pcVar2;
  _File->_ptr = pcVar2;
  _File->_bufsiz = 0x1000;
  _File->_cnt = 0x1000;
LAB_0080fabe:
  *(ushort *)&_File->_flag = (ushort)_File->_flag | 0x1102;
  return 1;
}


// ==== __ftbuf @ 0x0080facf ====

/* Library Function - Single Match
    __ftbuf
   
   Library: Visual Studio 2003 Release */

void __cdecl __ftbuf(int _Flag,FILE *_File)

{
  byte *pbVar1;
  
  if ((_Flag != 0) && ((_File->_flag & 0x1000) != 0)) {
    __flush(_File);
    pbVar1 = (byte *)((int)&_File->_flag + 1);
    *pbVar1 = *pbVar1 & 0xee;
    _File->_bufsiz = 0;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
  }
  return;
}


// ==== FUN_0080faf9 @ 0x0080faf9 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

void * FUN_0080faf9(uint param_1,uint param_2)

{
  int iVar1;
  uint dwBytes;
  void *_Dst;
  
  if ((param_1 == 0) || (param_2 <= 0xffffffe0 / param_1)) {
    param_1 = param_1 * param_2;
    dwBytes = param_1;
    if (param_1 == 0) {
      dwBytes = 1;
    }
    do {
      _Dst = (void *)0x0;
      if (dwBytes < 0xffffffe1) {
        if ((DAT_00b60f7c == 3) && (dwBytes = dwBytes + 0xf & 0xfffffff0, param_1 <= DAT_00b60f4c))
        {
          __lock(4);
          _Dst = (void *)___sbh_alloc_block(param_1);
          FUN_0080fbbf();
          if (_Dst != (void *)0x0) {
            _memset(_Dst,0,param_1);
            goto LAB_0080fb87;
          }
        }
        else {
LAB_0080fb87:
          if (_Dst != (void *)0x0) {
            return _Dst;
          }
        }
        _Dst = HeapAlloc(DAT_00b60f78,8,dwBytes);
      }
      if ((_Dst != (void *)0x0) || (DAT_00b5cb78 == 0)) {
        return _Dst;
      }
      iVar1 = __callnewh(dwBytes);
    } while (iVar1 != 0);
  }
  return (void *)0x0;
}


// ==== FUN_0080fbbf @ 0x0080fbbf ====

void FUN_0080fbbf(void)

{
  FUN_00806c2f(4);
  return;
}


// ==== FUN_0080fbd0 @ 0x0080fbd0 ====

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */

int FUN_0080fbd0(void)

{
  FILE *_File;
  int iVar1;
  int extraout_EAX;
  int iVar2;
  int iVar3;
  int local_20;
  
  local_20 = 0;
  __lock(1);
  iVar3 = 3;
  do {
    if (DAT_00b620c0 <= iVar3) {
      FUN_0080fc62();
      return local_20;
    }
    iVar2 = iVar3 * 4;
    _File = *(FILE **)(iVar2 + DAT_00b610b0);
    if (_File != (FILE *)0x0) {
      if ((_File->_flag & 0x83) != 0) {
        iVar1 = _fclose(_File);
        if (iVar1 != -1) {
          local_20 = local_20 + 1;
        }
      }
      if (0x13 < iVar3) {
        DeleteCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar2 + DAT_00b610b0) + 0x20));
        _free(*(void **)(iVar2 + DAT_00b610b0));
        return extraout_EAX;
      }
    }
    iVar3 = iVar3 + 1;
  } while( true );
}


// ==== FUN_0080fc62 @ 0x0080fc62 ====

void FUN_0080fc62(void)

{
  FUN_00806c2f(1);
  return;
}


// ==== FUN_0080fc6b @ 0x0080fc6b ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0080fc6b(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_28;
  undefined **local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  undefined4 local_8;
  
  local_8 = DAT_00b49670 ^ (int)register0x00000010 - 4U;
  if (0xa1 < param_4) {
    if (param_4 < 0x3eb) {
      if (param_4 != 0x3ea) {
        if (param_4 == 0xa2) {
          local_28 = 4;
          goto LAB_0080fe1d;
        }
        if (param_4 == 0xa6) {
          local_28 = 3;
          local_24 = (undefined **)s_exp10_00a0b750;
        }
        else {
          if (param_4 != 0xaa) {
            if (param_4 == 0xab) {
              local_24 = (undefined **)&DAT_00a0b758;
              goto LAB_0080fe9f;
            }
            if (param_4 == 1000) {
              local_24 = (undefined **)&DAT_009fd1bc;
            }
            else {
              if (param_4 != 0x3e9) {
                return;
              }
              local_24 = (undefined **)s_log10_009fd1b4;
            }
            goto LAB_0080fe9b;
          }
          local_28 = 2;
          local_24 = (undefined **)&DAT_00a0b758;
        }
        goto LAB_0080fe24;
      }
      local_24 = &PTR_LAB_009fd1b0;
    }
    else if (param_4 == 0x3eb) {
      local_24 = (undefined **)&DAT_009fd1fc;
    }
    else if (param_4 == 0x3ec) {
      local_24 = (undefined **)&DAT_009fd1ec;
    }
    else if (param_4 == 0x3ed) {
      local_24 = (undefined **)s_floor_009fd1e4;
    }
    else {
      if (param_4 == 0x3ee) {
LAB_0080fe79:
        local_24 = &PTR_LAB_00776f6b_5_009fd1a8;
        goto LAB_0080fe9f;
      }
      if (param_4 != 0x3ef) {
        return;
      }
      local_24 = (undefined **)&DAT_00a0b4b4;
    }
LAB_0080fe9b:
    *param_3 = *param_1;
    goto LAB_0080fe9f;
  }
  if (param_4 == 0xa1) {
    local_28 = 3;
LAB_0080fe1d:
    local_24 = (undefined **)&DAT_00a0b748;
    goto LAB_0080fe24;
  }
  if (param_4 < 0x19) {
    if (param_4 == 0x18) {
      local_28 = 3;
      goto LAB_0080fd21;
    }
    if (param_4 == 2) {
      local_28 = 2;
      local_24 = (undefined **)&DAT_009fd1bc;
    }
    else {
      if (param_4 == 3) {
        local_24 = (undefined **)&DAT_009fd1bc;
LAB_0080fe9f:
        local_20 = *param_1;
        local_18 = *param_2;
        local_28 = 1;
        local_10 = *param_3;
        iVar1 = (*(code *)PTR_FUN_00b4a038)(&local_28);
        if (iVar1 == 0) {
          puVar2 = (undefined4 *)FUN_00804b94();
          *puVar2 = 0x21;
        }
        goto LAB_0080fed2;
      }
      if (param_4 == 8) {
        local_28 = 2;
        local_24 = (undefined **)s_log10_009fd1b4;
      }
      else {
        if (param_4 == 9) {
          local_24 = (undefined **)s_log10_009fd1b4;
          goto LAB_0080fe9f;
        }
        if (param_4 != 0xe) {
          if (param_4 != 0xf) {
            return;
          }
          local_24 = &PTR_LAB_009fd1b0;
          goto LAB_0080fd69;
        }
        local_28 = 3;
        local_24 = &PTR_LAB_009fd1b0;
      }
    }
  }
  else {
    if (param_4 == 0x19) {
      local_24 = &PTR_LAB_00776f6b_5_009fd1a8;
LAB_0080fd69:
      local_20 = *param_1;
      local_18 = *param_2;
      local_28 = 4;
      local_10 = *param_3;
      (*(code *)PTR_FUN_00b4a038)(&local_28);
      goto LAB_0080fed2;
    }
    if (param_4 == 0x1a) {
      local_10 = 0x3ff0000000000000;
      goto LAB_0080fed2;
    }
    if (param_4 != 0x1b) {
      if (param_4 == 0x1c) goto LAB_0080fe79;
      if (param_4 != 0x1d) {
        return;
      }
      local_24 = &PTR_LAB_00776f6b_5_009fd1a8;
      goto LAB_0080fe9b;
    }
    local_28 = 2;
LAB_0080fd21:
    local_24 = &PTR_LAB_00776f6b_5_009fd1a8;
  }
LAB_0080fe24:
  local_20 = *param_1;
  local_18 = *param_2;
  local_10 = *param_3;
  iVar1 = (*(code *)PTR_FUN_00b4a038)(&local_28);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)FUN_00804b94();
    *puVar2 = 0x22;
  }
LAB_0080fed2:
  *param_3 = local_10;
  return;
}


// ==== __ceil_default @ 0x0080fee2 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __ceil_default
   
   Library: Visual Studio 2003 Release */

float10 __ceil_default(double param_1)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  undefined4 uVar5;
  
  uVar2 = __ctrlfp(DAT_00b4a03c,0xffff);
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = __sptype();
    if (0 < iVar3) {
      if (iVar3 < 3) {
        __ctrlfp(uVar2,0xffff);
        return (float10)param_1;
      }
      if (iVar3 == 3) {
        fVar4 = (float10)__handle_qnan1();
        return fVar4;
      }
    }
    dVar1 = param_1 + _DAT_0099d0a0;
    uVar5 = 8;
  }
  else {
    fVar4 = (float10)__frnd(SUB84(param_1,0),(int)((ulonglong)param_1 >> 0x20));
    dVar1 = (double)fVar4;
    if ((dVar1 == param_1) || ((uVar2 & 0x20) != 0)) {
      __ctrlfp(uVar2,0xffff);
      return (float10)dVar1;
    }
    uVar5 = 0x10;
  }
  fVar4 = (float10)FUN_0080d7c3(uVar5,0xc,param_1,dVar1,uVar2);
  return fVar4;
}


// ==== __floor_default @ 0x0080ffb5 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __floor_default
   
   Library: Visual Studio 2003 Release */

float10 __floor_default(double param_1)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  undefined4 uVar5;
  
  uVar2 = __ctrlfp(DAT_00b4a040,0xffff);
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = __sptype();
    if (0 < iVar3) {
      if (iVar3 < 3) {
        __ctrlfp(uVar2,0xffff);
        return (float10)param_1;
      }
      if (iVar3 == 3) {
        fVar4 = (float10)__handle_qnan1();
        return fVar4;
      }
    }
    dVar1 = param_1 + _DAT_0099d0a0;
    uVar5 = 8;
  }
  else {
    fVar4 = (float10)__frnd(SUB84(param_1,0),(int)((ulonglong)param_1 >> 0x20));
    dVar1 = (double)fVar4;
    if ((dVar1 == param_1) || ((uVar2 & 0x20) != 0)) {
      __ctrlfp(uVar2,0xffff);
      return (float10)dVar1;
    }
    uVar5 = 0x10;
  }
  fVar4 = (float10)FUN_0080d7c3(uVar5,0xb,param_1,dVar1,uVar2);
  return fVar4;
}


