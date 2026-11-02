// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x7b0000-0x7bffff

// ==== FUN_007b0f36 @ 0x007b0f36 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007b0f36(undefined8 *param_1,undefined4 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 in_MM4;
  undefined8 uVar8;
  undefined4 uVar10;
  undefined8 uVar9;
  undefined8 in_MM5;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 in_MM6;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 in_MM7;
  undefined8 uVar17;
  undefined4 uStack_2c;
  
  uVar2 = param_3[2];
  uVar3 = param_3[4];
  uVar11 = PackedSwapDWords(in_MM5,uVar2);
  uVar8 = PackedSwapDWords(in_MM4,uVar3);
  uVar1 = *param_3;
  uVar14 = PackedSwapDWords(in_MM6,param_3[6]);
  uVar17 = PackedSwapDWords(in_MM7,uVar3);
  uVar11 = PackedFloatingMUL(uVar11,uVar1);
  uVar8 = PackedFloatingMUL(uVar8,uVar1);
  uVar14 = PackedFloatingMUL(uVar14,uVar1);
  uVar1 = PackedSwapDWords(uVar1,param_3[6]);
  uVar17 = PackedFloatingMUL(uVar17,uVar2);
  uVar12 = PackedFloatingNegAccumulate(uVar11,uVar8);
  uVar2 = PackedFloatingMUL(uVar2,uVar1);
  uVar3 = PackedFloatingMUL(uVar3,uVar1);
  uVar17 = PackedFloatingNegAccumulate(uVar14,uVar17);
  uVar1 = PackedFloatingNegAccumulate(uVar2,uVar3);
  uVar2 = param_3[7];
  uVar3 = param_3[5];
  uVar4 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar10 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar2);
  uVar6 = (undefined4)uVar1;
  uVar1 = PackedFloatingMUL(CONCAT44(uVar10,uVar10),param_3[3]);
  uVar11 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),uVar3);
  uVar1 = PackedFloatingADD(uVar8,uVar1);
  uVar14 = PackedFloatingSUB(uVar1,uVar11);
  uVar7 = (undefined4)uVar17;
  uVar5 = (undefined4)((ulonglong)uVar12 >> 0x20);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar10,uVar10),param_3[1]);
  uVar1 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),uVar2);
  uVar9 = PackedFloatingMUL(CONCAT44(uVar7,uVar7),uVar3);
  uVar1 = PackedFloatingSUB(uVar1,uVar9);
  uVar17 = PackedFloatingADD(uVar1,uVar8);
  uVar8 = CONCAT44((int)uVar12,(int)uVar12);
  uVar1 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),param_3[1]);
  uVar2 = PackedFloatingMUL(uVar2,uVar8);
  uVar11 = PackedFloatingMUL(CONCAT44(uVar7,uVar7),param_3[3]);
  uVar2 = PackedFloatingADD(uVar2,uVar1);
  uVar11 = PackedFloatingSUB(uVar2,uVar11);
  uVar1 = PackedFloatingMUL(uVar8,uVar3);
  uVar13 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),param_3[3]);
  uVar2 = param_3[1];
  uVar15 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),param_3[1]);
  uVar1 = PackedFloatingSUB(uVar1,uVar13);
  uVar12 = PackedFloatingADD(uVar1,uVar15);
  uVar1 = param_3[3];
  uVar8 = param_3[5];
  uVar13 = PackedSwapDWords(uVar13,uVar1);
  uVar9 = PackedSwapDWords(uVar9,uVar8);
  uVar13 = PackedFloatingMUL(uVar13,uVar2);
  uVar15 = PackedSwapDWords(uVar15,param_3[7]);
  uVar9 = PackedFloatingMUL(uVar9,uVar2);
  uVar3 = PackedSwapDWords(uVar3,uVar8);
  uVar16 = PackedFloatingMUL(uVar15,uVar2);
  uVar2 = PackedSwapDWords(uVar2,param_3[7]);
  uVar15 = PackedFloatingNegAccumulate(uVar13,uVar9);
  uVar9 = PackedFloatingMUL(uVar3,uVar1);
  uVar3 = PackedFloatingMUL(uVar1,uVar2);
  uVar2 = PackedFloatingMUL(uVar8,uVar2);
  uVar13 = PackedFloatingNegAccumulate(uVar16,uVar9);
  uVar1 = PackedFloatingNegAccumulate(uVar3,uVar2);
  uVar2 = param_3[6];
  uVar3 = param_3[4];
  uVar10 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar6 = (undefined4)uVar1;
  uVar4 = (undefined4)((ulonglong)uVar13 >> 0x20);
  uVar9 = PackedFloatingMUL(CONCAT44(uVar10,uVar10),param_3[2]);
  uVar1 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar2);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),uVar3);
  uVar1 = PackedFloatingADD(uVar1,uVar9);
  uVar9 = PackedFloatingSUB(uVar1,uVar8);
  uVar7 = (undefined4)uVar13;
  uVar5 = (undefined4)((ulonglong)uVar15 >> 0x20);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar10,uVar10),*param_3);
  uVar1 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),uVar2);
  uVar13 = PackedFloatingMUL(CONCAT44(uVar7,uVar7),uVar3);
  uVar1 = PackedFloatingSUB(uVar1,uVar13);
  uVar13 = PackedFloatingADD(uVar1,uVar8);
  uVar15 = CONCAT44((int)uVar15,(int)uVar15);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),*param_3);
  uVar1 = PackedFloatingMUL(uVar2,uVar15);
  uVar16 = PackedFloatingMUL(CONCAT44(uVar7,uVar7),param_3[2]);
  uVar1 = PackedFloatingADD(uVar1,uVar8);
  uVar1 = PackedFloatingSUB(uVar1,uVar16);
  uVar8 = PackedFloatingMUL(uVar15,uVar3);
  uVar15 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),param_3[2]);
  uVar16 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),*param_3);
  uVar8 = PackedFloatingSUB(uVar8,uVar15);
  uVar15 = PackedFloatingADD(uVar8,uVar16);
  uStack_2c = (undefined4)((ulonglong)uVar13 >> 0x20);
  uVar8 = CONCAT44(uStack_2c,(int)((ulonglong)uVar9 >> 0x20));
  uVar2 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar15 >> 0x20),
                                     (int)((ulonglong)uVar1 >> 0x20)),
                            CONCAT44((int)uVar2,(int)uVar3));
  uVar3 = PackedFloatingMUL(CONCAT44(*(undefined4 *)(param_3 + 2),(int)*param_3),uVar8);
  uVar2 = PackedFloatingNegAccumulate(uVar2,uVar3);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar4 = (undefined4)uVar2;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar4;
  }
  uVar3 = FloatingReciprocalAprox(uVar8,uVar2);
  uVar8 = PackedFloatingCompareEQ(0,uVar2);
  uVar2 = PackedFloatingReciprocalIter1(CONCAT44(uVar4,uVar4),uVar3);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar3);
  uVar2 = PackedFloatingMUL(uVar2,_DAT_009fc830);
  uVar3 = PackedSwapDWords(uVar3,uVar2);
  if ((int)uVar8 == 0) {
    uVar8 = PackedFloatingMUL(uVar9,uVar3);
    uVar9 = PackedFloatingMUL(uVar13,uVar2);
    uVar14 = PackedFloatingMUL(uVar14,uVar3);
    uVar17 = PackedFloatingMUL(uVar17,uVar2);
    *param_1 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),(int)((ulonglong)uVar8 >> 0x20));
    param_1[2] = CONCAT44((int)uVar9,(int)uVar8);
    param_1[4] = CONCAT44((int)((ulonglong)uVar17 >> 0x20),(int)((ulonglong)uVar14 >> 0x20));
    param_1[6] = CONCAT44((int)uVar17,(int)uVar14);
    uVar1 = PackedFloatingMUL(uVar1,uVar3);
    uVar8 = PackedFloatingMUL(uVar15,uVar2);
    uVar3 = PackedFloatingMUL(uVar11,uVar3);
    uVar2 = PackedFloatingMUL(uVar12,uVar2);
    param_1[1] = CONCAT44((int)((ulonglong)uVar8 >> 0x20),(int)((ulonglong)uVar1 >> 0x20));
    param_1[3] = CONCAT44((int)uVar8,(int)uVar1);
    param_1[5] = CONCAT44((int)((ulonglong)uVar2 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
    param_1[7] = CONCAT44((int)uVar2,(int)uVar3);
  }
  FastExitMediaState();
  return;
}


// ==== FUN_007b1610 @ 0x007b1610 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_007b1610(undefined8 *param_1,undefined4 *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar4;
  undefined8 uVar3;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined4 uVar11;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined4 uVar21;
  undefined8 uVar20;
  undefined4 uStack_34;
  
  uVar11 = (undefined4)((ulonglong)*param_3 >> 0x20);
  uVar2 = (undefined4)param_3[4];
  uVar16 = (undefined4)param_3[2];
  uVar12 = (undefined4)*param_3;
  uVar21 = (undefined4)((ulonglong)param_3[2] >> 0x20);
  uVar4 = (undefined4)((ulonglong)param_3[4] >> 0x20);
  uVar9 = PackedFloatingMUL(CONCAT44(uVar11,uVar11),CONCAT44(uVar2,uVar16));
  uVar13 = PackedFloatingMUL(CONCAT44(uVar12,uVar12),CONCAT44(uVar4,uVar21));
  uVar14 = PackedFloatingSUB(uVar13,uVar9);
  uVar5 = (undefined4)((ulonglong)param_3[6] >> 0x20);
  uVar8 = (undefined4)param_3[6];
  uVar17 = PackedFloatingMUL(CONCAT44(uVar4,uVar5),CONCAT44(uVar16,uVar12));
  uVar20 = PackedFloatingMUL(CONCAT44(uVar21,uVar11),CONCAT44(uVar2,uVar8));
  uVar9 = PackedFloatingMUL(CONCAT44(uVar2,uVar16),CONCAT44(uVar5,uVar5));
  uVar13 = PackedFloatingMUL(CONCAT44(uVar4,uVar21),CONCAT44(uVar8,uVar8));
  uVar18 = PackedFloatingSUB(uVar17,uVar20);
  uVar17 = PackedFloatingSUBR(uVar13,uVar9);
  uVar9 = param_3[7];
  uVar13 = param_3[5];
  uVar2 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar20 = PackedFloatingMUL(CONCAT44(uVar2,uVar2),uVar9);
  uVar5 = (undefined4)uVar17;
  uVar17 = PackedFloatingMUL(CONCAT44(uVar11,uVar11),param_3[3]);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),uVar13);
  uVar17 = PackedFloatingADD(uVar20,uVar17);
  uVar3 = PackedFloatingSUB(uVar17,uVar6);
  uVar8 = (undefined4)uVar18;
  uVar4 = (undefined4)((ulonglong)uVar14 >> 0x20);
  uVar20 = PackedFloatingMUL(CONCAT44(uVar11,uVar11),param_3[1]);
  uVar17 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar9);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar8,uVar8),uVar13);
  uVar17 = PackedFloatingSUB(uVar17,uVar6);
  uVar18 = PackedFloatingADD(uVar17,uVar20);
  uVar20 = CONCAT44((int)uVar14,(int)uVar14);
  uVar17 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),param_3[1]);
  uVar9 = PackedFloatingMUL(uVar9,uVar20);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar8,uVar8),param_3[3]);
  uVar9 = PackedFloatingADD(uVar9,uVar17);
  uVar17 = PackedFloatingSUB(uVar9,uVar6);
  uVar9 = PackedFloatingMUL(uVar20,uVar13);
  uVar13 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),param_3[3]);
  uVar20 = PackedFloatingMUL(CONCAT44(uVar2,uVar2),param_3[1]);
  uVar9 = PackedFloatingSUB(uVar9,uVar13);
  uVar14 = PackedFloatingADD(uVar9,uVar20);
  uVar11 = (undefined4)((ulonglong)param_3[1] >> 0x20);
  uVar2 = (undefined4)param_3[5];
  uVar16 = (undefined4)param_3[3];
  uVar12 = (undefined4)param_3[1];
  uVar21 = (undefined4)((ulonglong)param_3[3] >> 0x20);
  uVar4 = (undefined4)((ulonglong)param_3[5] >> 0x20);
  uVar9 = PackedFloatingMUL(CONCAT44(uVar11,uVar11),CONCAT44(uVar2,uVar16));
  uVar13 = PackedFloatingMUL(CONCAT44(uVar12,uVar12),CONCAT44(uVar4,uVar21));
  uVar15 = PackedFloatingSUB(uVar13,uVar9);
  uVar5 = (undefined4)((ulonglong)param_3[7] >> 0x20);
  uVar8 = (undefined4)param_3[7];
  uVar20 = PackedFloatingMUL(CONCAT44(uVar4,uVar5),CONCAT44(uVar16,uVar12));
  uVar6 = PackedFloatingMUL(CONCAT44(uVar21,uVar11),CONCAT44(uVar2,uVar8));
  uVar9 = PackedFloatingMUL(CONCAT44(uVar2,uVar16),CONCAT44(uVar5,uVar5));
  uVar13 = PackedFloatingMUL(CONCAT44(uVar4,uVar21),CONCAT44(uVar8,uVar8));
  uVar19 = PackedFloatingSUB(uVar20,uVar6);
  uVar20 = PackedFloatingSUBR(uVar13,uVar9);
  uVar9 = param_3[6];
  uVar13 = param_3[4];
  uVar11 = (undefined4)((ulonglong)uVar20 >> 0x20);
  uVar5 = (undefined4)uVar20;
  uVar2 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar10 = PackedFloatingMUL(CONCAT44(uVar11,uVar11),param_3[2]);
  uVar20 = PackedFloatingMUL(CONCAT44(uVar2,uVar2),uVar9);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),uVar13);
  uVar20 = PackedFloatingADD(uVar20,uVar10);
  uVar10 = PackedFloatingSUB(uVar20,uVar6);
  uVar8 = (undefined4)uVar19;
  uVar4 = (undefined4)((ulonglong)uVar15 >> 0x20);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar11,uVar11),*param_3);
  uVar20 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar9);
  uVar19 = PackedFloatingMUL(CONCAT44(uVar8,uVar8),uVar13);
  uVar20 = PackedFloatingSUB(uVar20,uVar19);
  uVar19 = PackedFloatingADD(uVar20,uVar6);
  uVar15 = CONCAT44((int)uVar15,(int)uVar15);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),*param_3);
  uVar20 = PackedFloatingMUL(uVar9,uVar15);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar8,uVar8),param_3[2]);
  uVar20 = PackedFloatingADD(uVar20,uVar6);
  uVar20 = PackedFloatingSUB(uVar20,uVar7);
  uVar6 = PackedFloatingMUL(uVar15,uVar13);
  uVar15 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),param_3[2]);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar2,uVar2),*param_3);
  uVar6 = PackedFloatingSUB(uVar6,uVar15);
  uVar6 = PackedFloatingADD(uVar6,uVar7);
  uVar9 = PackedFloatingMUL(CONCAT44((int)uVar9,(int)uVar13),_DAT_009fc830);
  uStack_34 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar13 = CONCAT44(uStack_34,(int)((ulonglong)uVar10 >> 0x20));
  uVar15 = PackedFloatingMUL(CONCAT44(*(undefined4 *)(param_3 + 2),(int)*param_3),_DAT_009fc830);
  uVar9 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar6 >> 0x20),
                                     (int)((ulonglong)uVar20 >> 0x20)),uVar9);
  uVar15 = PackedFloatingMUL(uVar15,uVar13);
  uVar9 = PackedFloatingADD(uVar9,uVar15);
  uVar9 = PackedFloatingAccumulate(uVar9,uVar9);
  uVar2 = (undefined4)uVar9;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar2;
  }
  uVar13 = FloatingReciprocalAprox(uVar13,uVar9);
  uVar15 = PackedFloatingCompareEQ(0,uVar9);
  uVar9 = PackedFloatingReciprocalIter1(CONCAT44(uVar2,uVar2),uVar13);
  uVar9 = PackedFloatingReciprocalIter2(uVar9,uVar13);
  uVar13 = PackedFloatingMUL(uVar9,_DAT_009fc830);
  uVar9 = CONCAT44((int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
  puVar1 = (undefined8 *)uVar15;
  if ((undefined8 *)uVar15 == (undefined8 *)0x0) {
    uVar10 = PackedFloatingMUL(uVar10,uVar9);
    uVar19 = PackedFloatingMUL(uVar19,uVar13);
    uVar3 = PackedFloatingMUL(uVar3,uVar9);
    uVar18 = PackedFloatingMUL(uVar18,uVar13);
    *param_1 = CONCAT44((int)((ulonglong)uVar19 >> 0x20),(int)((ulonglong)uVar10 >> 0x20));
    param_1[2] = CONCAT44((int)uVar19,(int)uVar10);
    param_1[4] = CONCAT44((int)((ulonglong)uVar18 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
    param_1[6] = CONCAT44((int)uVar18,(int)uVar3);
    uVar20 = PackedFloatingMUL(uVar20,uVar9);
    uVar6 = PackedFloatingMUL(uVar6,uVar13);
    uVar9 = PackedFloatingMUL(uVar17,uVar9);
    uVar13 = PackedFloatingMUL(uVar14,uVar13);
    param_1[1] = CONCAT44((int)((ulonglong)uVar6 >> 0x20),(int)((ulonglong)uVar20 >> 0x20));
    param_1[3] = CONCAT44((int)uVar6,(int)uVar20);
    param_1[5] = CONCAT44((int)((ulonglong)uVar13 >> 0x20),(int)((ulonglong)uVar9 >> 0x20));
    param_1[7] = CONCAT44((int)uVar13,(int)uVar9);
    puVar1 = param_1;
  }
  return puVar1;
}


// ==== FUN_007b1946 @ 0x007b1946 ====

undefined4 FUN_007b1946(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FastExitMediaState();
  FUN_007b1610(param_1,param_2,param_3);
  FastExitMediaState();
  return param_1;
}


// ==== FUN_007b1964 @ 0x007b1964 ====

undefined8 * FUN_007b1964(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar4 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar7 = CONCAT44(uVar1,uVar1);
  uVar8 = CONCAT44(*(undefined4 *)(param_2 + 1),*(undefined4 *)(param_2 + 1));
  uVar2 = PackedFloatingMUL(uVar4,*param_3);
  uVar3 = PackedFloatingMUL(uVar7,param_3[2]);
  uVar5 = PackedFloatingMUL(uVar8,param_3[4]);
  uVar2 = PackedFloatingADD(uVar2,param_3[6]);
  uVar6 = PackedFloatingMUL(uVar4,param_3[1]);
  uVar4 = PackedFloatingADD(uVar3,uVar5);
  uVar3 = PackedFloatingMUL(uVar7,param_3[3]);
  uVar8 = PackedFloatingMUL(uVar8,param_3[5]);
  uVar7 = PackedFloatingADD(uVar6,param_3[7]);
  uVar4 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingADD(uVar3,uVar8);
  uVar2 = PackedFloatingADD(uVar7,uVar2);
  *param_1 = uVar4;
  param_1[1] = uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== FUN_007b19d7 @ 0x007b19d7 ====

undefined8 * FUN_007b19d7(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar4 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar8 = CONCAT44(uVar1,uVar1);
  uVar5 = CONCAT44(*(undefined4 *)(param_2 + 1),*(undefined4 *)(param_2 + 1));
  uVar2 = PackedFloatingMUL(uVar4,*param_3);
  uVar3 = PackedFloatingMUL(uVar8,param_3[2]);
  uVar6 = PackedFloatingMUL(uVar5,param_3[4]);
  uVar7 = PackedFloatingMUL(uVar4,param_3[1]);
  uVar4 = PackedFloatingADD(uVar3,uVar6);
  uVar8 = PackedFloatingMUL(uVar8,param_3[3]);
  uVar3 = PackedFloatingMUL(uVar5,param_3[5]);
  uVar4 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingADD(uVar8,uVar3);
  uVar2 = PackedFloatingADD(uVar7,uVar2);
  *param_1 = uVar4;
  *(int *)(param_1 + 1) = (int)uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== FUN_007b1a40 @ 0x007b1a40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007b1a40(undefined8 *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 in_MM4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  FastExitMediaState();
  uVar1 = *param_2;
  uVar3 = (ulonglong)(uint)param_2[1];
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar3,uVar3);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar5 = PackedFloatingReciprocalSQRAprox(in_MM4,uVar2);
  uVar6 = PackedFloatingCompareGT(uVar2,_DAT_009fc8b0);
  uVar4 = PackedFloatingMUL(uVar5,uVar5);
  uVar2 = PackedFloatingReciprocalSQRIter1(uVar2,uVar4);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar5);
  uVar4 = PackedFloatingMUL(uVar1 & uVar6,uVar2);
  uVar2 = PackedFloatingMUL(uVar3 & uVar6,uVar2);
  *param_1 = uVar4;
  *(int *)(param_1 + 1) = (int)uVar2;
  FastExitMediaState();
  return;
}


// ==== FUN_007b1cce @ 0x007b1cce ====

undefined8 * FUN_007b1cce(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar4 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar7 = CONCAT44(uVar1,uVar1);
  uVar8 = CONCAT44(*(undefined4 *)(param_2 + 1),*(undefined4 *)(param_2 + 1));
  uVar2 = PackedFloatingMUL(uVar4,*param_3);
  uVar3 = PackedFloatingMUL(uVar7,param_3[2]);
  uVar5 = PackedFloatingMUL(uVar8,param_3[4]);
  uVar2 = PackedFloatingADD(uVar2,param_3[6]);
  uVar6 = PackedFloatingMUL(uVar4,param_3[1]);
  uVar4 = PackedFloatingADD(uVar3,uVar5);
  uVar3 = PackedFloatingMUL(uVar7,param_3[3]);
  uVar8 = PackedFloatingMUL(uVar8,param_3[5]);
  uVar7 = PackedFloatingADD(uVar6,param_3[7]);
  uVar4 = PackedFloatingADD(uVar2,uVar4);
  uVar3 = PackedFloatingADD(uVar3,uVar8);
  uVar2 = PackedFloatingADD(uVar7,uVar3);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  uVar8 = CONCAT44(uVar1,uVar1);
  uVar7 = FloatingReciprocalAprox(uVar3,uVar8);
  uVar3 = PackedFloatingReciprocalIter1(uVar8,uVar7);
  uVar7 = PackedFloatingReciprocalIter2(uVar3,uVar7);
  uVar4 = PackedFloatingMUL(uVar4,uVar7);
  uVar2 = PackedFloatingMUL(uVar2,uVar7);
  *param_1 = uVar4;
  *(int *)(param_1 + 1) = (int)uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== FUN_007b1d5b @ 0x007b1d5b ====

undefined8 * FUN_007b1d5b(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar2 = (undefined4)((ulonglong)param_2[1] >> 0x20);
  uVar3 = (undefined4)*param_2;
  uVar6 = CONCAT44(uVar3,uVar3);
  uVar3 = (undefined4)param_2[1];
  uVar9 = CONCAT44(uVar3,uVar3);
  uVar7 = PackedFloatingMUL(*param_3,uVar6);
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar6,param_3[1]);
  uVar8 = PackedFloatingMUL(param_3[2],uVar5);
  uVar6 = CONCAT44(uVar2,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,param_3[3]);
  uVar7 = PackedFloatingADD(uVar8,uVar7);
  uVar8 = PackedFloatingMUL(param_3[4],uVar9);
  uVar4 = PackedFloatingADD(uVar5,uVar4);
  uVar5 = PackedFloatingMUL(uVar9,param_3[5]);
  uVar9 = PackedFloatingADD(uVar8,uVar7);
  uVar7 = PackedFloatingMUL(param_3[6],uVar6);
  uVar4 = PackedFloatingADD(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar6,param_3[7]);
  uVar7 = PackedFloatingADD(uVar7,uVar9);
  uVar5 = param_2[2];
  uVar9 = PackedFloatingADD(uVar6,uVar4);
  uVar6 = param_2[3];
  *param_1 = uVar7;
  uVar4 = *param_3;
  param_1[1] = uVar9;
  uVar1 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar3 = (undefined4)uVar5;
  uVar9 = CONCAT44(uVar3,uVar3);
  uVar3 = (undefined4)uVar6;
  uVar7 = CONCAT44(uVar3,uVar3);
  uVar8 = PackedFloatingMUL(uVar4,uVar9);
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar9,param_3[1]);
  uVar9 = PackedFloatingMUL(param_3[2],uVar5);
  uVar6 = CONCAT44(uVar2,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,param_3[3]);
  uVar9 = PackedFloatingADD(uVar9,uVar8);
  uVar8 = PackedFloatingMUL(param_3[4],uVar7);
  uVar4 = PackedFloatingADD(uVar5,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,param_3[5]);
  uVar9 = PackedFloatingADD(uVar8,uVar9);
  uVar7 = PackedFloatingMUL(param_3[6],uVar6);
  uVar4 = PackedFloatingADD(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar6,param_3[7]);
  uVar7 = PackedFloatingADD(uVar7,uVar9);
  uVar5 = param_2[4];
  uVar9 = PackedFloatingADD(uVar6,uVar4);
  uVar6 = param_2[5];
  param_1[2] = uVar7;
  uVar4 = *param_3;
  param_1[3] = uVar9;
  uVar1 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar3 = (undefined4)uVar5;
  uVar9 = CONCAT44(uVar3,uVar3);
  uVar3 = (undefined4)uVar6;
  uVar7 = CONCAT44(uVar3,uVar3);
  uVar8 = PackedFloatingMUL(uVar4,uVar9);
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar9,param_3[1]);
  uVar9 = PackedFloatingMUL(param_3[2],uVar5);
  uVar6 = CONCAT44(uVar2,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,param_3[3]);
  uVar9 = PackedFloatingADD(uVar9,uVar8);
  uVar8 = PackedFloatingMUL(param_3[4],uVar7);
  uVar4 = PackedFloatingADD(uVar5,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,param_3[5]);
  uVar9 = PackedFloatingADD(uVar8,uVar9);
  uVar7 = PackedFloatingMUL(param_3[6],uVar6);
  uVar4 = PackedFloatingADD(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar6,param_3[7]);
  uVar7 = PackedFloatingADD(uVar7,uVar9);
  uVar5 = param_2[6];
  uVar9 = PackedFloatingADD(uVar6,uVar4);
  uVar6 = param_2[7];
  param_1[4] = uVar7;
  uVar4 = *param_3;
  param_1[5] = uVar9;
  uVar1 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar3 = (undefined4)uVar5;
  uVar9 = CONCAT44(uVar3,uVar3);
  uVar3 = (undefined4)uVar6;
  uVar7 = CONCAT44(uVar3,uVar3);
  uVar8 = PackedFloatingMUL(uVar4,uVar9);
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar9,param_3[1]);
  uVar9 = PackedFloatingMUL(param_3[2],uVar5);
  uVar6 = CONCAT44(uVar2,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,param_3[3]);
  uVar9 = PackedFloatingADD(uVar9,uVar8);
  uVar8 = PackedFloatingMUL(param_3[4],uVar7);
  uVar4 = PackedFloatingADD(uVar5,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,param_3[5]);
  uVar9 = PackedFloatingADD(uVar8,uVar9);
  uVar7 = PackedFloatingMUL(param_3[6],uVar6);
  uVar5 = PackedFloatingADD(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar6,param_3[7]);
  uVar4 = PackedFloatingADD(uVar7,uVar9);
  uVar5 = PackedFloatingADD(uVar6,uVar5);
  param_1[6] = uVar4;
  param_1[7] = uVar5;
  FastExitMediaState();
  return param_1;
}


// ==== FUN_007b1f24 @ 0x007b1f24 ====

void FUN_007b1f24(void)

{
  FUN_007b1cce();
  return;
}


// ==== FUN_007b1f2f @ 0x007b1f2f ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong *
FUN_007b1f2f(ulonglong *param_1,undefined4 param_2,undefined8 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 uVar8;
  undefined8 uVar7;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
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
  
  puVar1 = &local_44;
  switch(((param_6 != (undefined4 *)0x0) << 1 | param_5 != (undefined4 *)0x0) << 1 |
         param_4 != (undefined4 *)0x0) {
  case '\0':
    local_c = 0;
    local_10 = 0;
    local_14 = 0;
    local_18 = 0;
    local_20 = 0;
    local_24 = 0;
    local_28 = 0;
    local_2c = 0;
    local_34 = 0;
    local_38 = 0;
    local_3c = 0;
    local_40 = 0;
    local_8 = 0x3f800000;
    local_1c = 0x3f800000;
    local_30 = 0x3f800000;
    local_44 = 0x3f800000;
    break;
  case '\x01':
    puVar1 = param_4;
    break;
  case '\x02':
    puVar1 = param_5;
    break;
  case '\x03':
    FastExitMediaState();
    FUN_007b1d5b(&local_44,param_5,param_4);
    FastExitMediaState();
    break;
  case '\x04':
    puVar1 = param_6;
    break;
  case '\x05':
    FastExitMediaState();
    FUN_007b1d5b(&local_44,param_6,param_4);
    FastExitMediaState();
    break;
  case '\x06':
    FastExitMediaState();
    FUN_007b1d5b(&local_44,param_6,param_5);
    FastExitMediaState();
    break;
  case '\a':
    FastExitMediaState();
    FUN_007b1d5b(&local_44,param_6,param_5);
    FUN_007b1d5b(&local_44,&local_44,param_4);
    FastExitMediaState();
  }
  FUN_007b1cce(param_1,param_2,puVar1);
  if (param_3 != (undefined8 *)0x0) {
    FastExitMediaState();
    uVar4 = param_3[2];
    uVar5 = PackedIntToFloatingDwordConv(*param_3,*param_3);
    uVar6 = PackedIntToFloatingDwordConv(param_3[1],param_3[1]);
    uVar2 = PackedFloatingADD(*param_1 ^ DAT_009fc8c0,_DAT_009fc8c8);
    uVar6 = PackedFloatingMUL(uVar6,DAT_009fc8d0);
    uVar8 = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar7 = PackedFloatingSUB(CONCAT44(uVar8,uVar8),uVar4);
    uVar2 = PackedFloatingMUL(uVar2,uVar6);
    uVar6 = PackedFloatingMUL((ulonglong)(uint)param_1[1],uVar7);
    uVar4 = PackedFloatingADD(uVar6,uVar4);
    uVar3 = PackedFloatingADD(uVar2,uVar5);
    *param_1 = uVar3;
    *(int *)(param_1 + 1) = (int)uVar4;
    FastExitMediaState();
  }
  return param_1;
}


// ==== FUN_007b20bb @ 0x007b20bb ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong *
FUN_007b20bb(ulonglong *param_1,ulonglong *param_2,undefined8 *param_3,int param_4,int param_5,
            int param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar7;
  undefined8 uVar6;
  undefined8 uVar8;
  unkbyte10 in_ST5;
  undefined8 uVar9;
  unkbyte10 in_ST6;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
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
  
  uVar2 = (undefined8)in_ST5;
  uVar9 = (undefined8)in_ST6;
  switch(((param_6 != 0) << 1 | param_5 != 0) << 1 | param_4 != 0) {
  case '\0':
    local_c = 0;
    local_10 = 0;
    local_14 = 0;
    local_18 = 0;
    local_20 = 0;
    local_24 = 0;
    local_28 = 0;
    local_2c = 0;
    local_34 = 0;
    local_38 = 0;
    local_3c = 0;
    local_40 = 0;
    local_8 = 0x3f800000;
    local_1c = 0x3f800000;
    local_30 = 0x3f800000;
    local_44 = 0x3f800000;
    break;
  case '\x01':
    FastExitMediaState();
    FUN_007b1610(&local_44,0,param_4);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x02':
    FastExitMediaState();
    FUN_007b1610(&local_44,0,param_5);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x03':
    FastExitMediaState();
    FUN_007b1d5b(&local_44,param_5,param_4);
    FUN_007b1610(&local_44,0,&local_44);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x04':
    FastExitMediaState();
    FUN_007b1610(&local_44,0,param_6);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x05':
    FastExitMediaState();
    FUN_007b1d5b(&local_44,param_6,param_4);
    FUN_007b1610(&local_44,0,&local_44);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x06':
    FastExitMediaState();
    FUN_007b1d5b(&local_44,param_6,param_5);
    FUN_007b1610(&local_44,0,&local_44);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\a':
    FastExitMediaState();
    FUN_007b1d5b(&local_44,param_6,param_5);
    FUN_007b1d5b(&local_44,&local_44,param_4);
    FUN_007b1610(&local_44,0,&local_44);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
  }
  if (param_3 == (undefined8 *)0x0) {
  }
  else {
    FastExitMediaState();
    uVar4 = PackedIntToFloatingDwordConv(*param_3,*param_3);
    uVar1 = param_3[2];
    uVar5 = PackedIntToFloatingDwordConv(param_3[1],param_3[1]);
    uVar7 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar6 = CONCAT44(uVar7,uVar7);
    uVar8 = FloatingReciprocalAprox(uVar2,uVar5);
    uVar6 = FloatingReciprocalAprox(uVar6,uVar6);
    uVar2 = PackedFloatingSUB(*param_2,uVar4);
    uVar6 = CONCAT44((int)uVar6,(int)uVar8);
    uVar4 = PackedFloatingReciprocalIter1(uVar5,uVar6);
    uVar4 = PackedFloatingReciprocalIter2(uVar4,uVar6);
    uVar4 = PackedFloatingMUL(uVar4,DAT_009fc8d8);
    uVar2 = PackedFloatingMUL(uVar2,uVar4);
    uVar7 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar3 = PackedFloatingSUB(uVar2,_DAT_009fc8c8);
    uVar2 = PackedFloatingSUB(CONCAT44(uVar7,uVar7),uVar1);
    uVar9 = FloatingReciprocalAprox(uVar9,uVar2);
    uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar9);
    uVar9 = PackedFloatingReciprocalIter2(uVar2,uVar9);
    uVar2 = PackedFloatingSUB((ulonglong)(uint)param_2[1],uVar1);
    uVar2 = PackedFloatingMUL(uVar2,uVar9);
    *param_1 = uVar3 ^ DAT_009fc8c0;
    *(int *)(param_1 + 1) = (int)uVar2;
    FastExitMediaState();
    param_2 = param_1;
  }
  FUN_007b1cce(param_1,param_2,&local_44);
  return param_1;
}


// ==== FUN_007b22d8 @ 0x007b22d8 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong *
FUN_007b22d8(ulonglong *param_1,ulonglong *param_2,undefined8 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar7;
  undefined8 uVar6;
  undefined8 uVar8;
  unkbyte10 in_ST5;
  undefined8 uVar9;
  unkbyte10 in_ST6;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
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
  
  uVar2 = (undefined8)in_ST5;
  uVar9 = (undefined8)in_ST6;
  switch(((param_6 != (undefined4 *)0x0) << 1 | param_5 != (undefined4 *)0x0) << 1 |
         param_4 != (undefined4 *)0x0) {
  case '\0':
    local_c = 0;
    local_10 = 0;
    local_14 = 0;
    local_18 = 0;
    local_20 = 0;
    local_24 = 0;
    local_28 = 0;
    local_2c = 0;
    local_34 = 0;
    local_38 = 0;
    local_3c = 0;
    local_40 = 0;
    local_8 = 0x3f800000;
    local_1c = 0x3f800000;
    local_30 = 0x3f800000;
    local_44 = 0x3f800000;
    goto switchD_007b2311_default;
  case '\x01':
    param_6 = param_4;
    goto LAB_007b23a3;
  case '\x02':
    param_6 = param_5;
    goto LAB_007b23a3;
  case '\x03':
    param_6 = param_5;
    break;
  case '\x04':
    goto LAB_007b23a3;
  case '\x05':
    break;
  case '\x06':
    param_4 = param_5;
    break;
  case '\a':
    FUN_007b1d5b(&local_44,param_6,param_5);
    param_6 = &local_44;
    break;
  default:
    goto switchD_007b2311_default;
  }
  FUN_007b1d5b(&local_44,param_6,param_4);
  param_6 = &local_44;
LAB_007b23a3:
  FUN_007b0f36(&local_44,0,param_6);
  uVar2 = (undefined8)in_ST5;
  uVar9 = (undefined8)in_ST6;
switchD_007b2311_default:
  if (param_3 == (undefined8 *)0x0) {
  }
  else {
    FastExitMediaState();
    uVar4 = PackedIntToFloatingDwordConv(*param_3,*param_3);
    uVar1 = param_3[2];
    uVar5 = PackedIntToFloatingDwordConv(param_3[1],param_3[1]);
    uVar7 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar6 = CONCAT44(uVar7,uVar7);
    uVar8 = FloatingReciprocalAprox(uVar2,uVar5);
    uVar6 = FloatingReciprocalAprox(uVar6,uVar6);
    uVar2 = PackedFloatingSUB(*param_2,uVar4);
    uVar6 = CONCAT44((int)uVar6,(int)uVar8);
    uVar4 = PackedFloatingReciprocalIter1(uVar5,uVar6);
    uVar4 = PackedFloatingReciprocalIter2(uVar4,uVar6);
    uVar4 = PackedFloatingMUL(uVar4,DAT_009fc8d8);
    uVar2 = PackedFloatingMUL(uVar2,uVar4);
    uVar7 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar3 = PackedFloatingSUB(uVar2,_DAT_009fc8c8);
    uVar2 = PackedFloatingSUB(CONCAT44(uVar7,uVar7),uVar1);
    uVar9 = FloatingReciprocalAprox(uVar9,uVar2);
    uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar9);
    uVar9 = PackedFloatingReciprocalIter2(uVar2,uVar9);
    uVar2 = PackedFloatingSUB((ulonglong)(uint)param_2[1],uVar1);
    uVar2 = PackedFloatingMUL(uVar2,uVar9);
    *param_1 = uVar3 ^ DAT_009fc8c0;
    *(int *)(param_1 + 1) = (int)uVar2;
    FastExitMediaState();
    param_2 = param_1;
  }
  FUN_007b1cce(param_1,param_2,&local_44);
  return param_1;
}


// ==== FUN_007b3000 @ 0x007b3000 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong * FUN_007b3000(ulonglong *param_1,undefined4 *param_2,int param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  int iVar10;
  
  puVar1 = param_1;
  if (param_3 < 4) {
    if (param_3 != 0) {
      FUN_0079ddd0(param_1,param_2,param_3);
    }
  }
  else {
    while( true ) {
      for (; 3 < param_3; param_3 = param_3 + -4) {
        uVar7 = (ulonglong)CONCAT24((short)((uint)*param_2 >> 0x10),*param_2) & 0xffffffff0000ffff;
        uVar3 = (ulonglong)CONCAT24((short)((uint)param_2[1] >> 0x10),param_2[1]) &
                0xffffffff0000ffff;
        uVar9 = CONCAT44(-(uint)((int)((uVar7 & DAT_00b48000) >> 0x20) == 0),
                         -(uint)((int)(uVar7 & DAT_00b48000) == 0));
        uVar4 = CONCAT44(-(uint)((int)((uVar3 & DAT_00b48000) >> 0x20) == 0),
                         -(uint)((int)(uVar3 & DAT_00b48000) == 0));
        uVar6 = uVar7 & DAT_00b48020;
        uVar8 = uVar3 & DAT_00b48020;
        iVar10 = (int)((ulonglong)DAT_00b48010 >> 0x20);
        uVar2 = uVar9 & _DAT_00b48030;
        uVar5 = uVar4 & _DAT_00b48030;
        uVar7 = PackedFloatingSUB(CONCAT44(((int)((uVar7 ^ uVar6) >> 0x20) + iVar10 +
                                           (int)(uVar2 >> 0x20)) * 0x2000,
                                           ((int)(uVar7 ^ uVar6) + (int)DAT_00b48010 + (int)uVar2) *
                                           0x2000),uVar9 & _DAT_00b48040);
        uVar9 = PackedFloatingSUB(CONCAT44(((int)((uVar3 ^ uVar8) >> 0x20) + iVar10 +
                                           (int)(uVar5 >> 0x20)) * 0x2000,
                                           ((int)(uVar3 ^ uVar8) + (int)DAT_00b48010 + (int)uVar5) *
                                           0x2000),uVar4 & _DAT_00b48040);
        *puVar1 = uVar7 | CONCAT44((int)(uVar6 >> 0x20) << 0x10,(int)uVar6 << 0x10);
        puVar1[1] = uVar9 | CONCAT44((int)(uVar8 >> 0x20) << 0x10,(int)uVar8 << 0x10);
        puVar1 = puVar1 + 2;
        param_2 = param_2 + 2;
      }
      if (param_3 == 0) break;
      param_2 = (undefined4 *)((int)param_2 + (param_3 + -4) * 2);
      puVar1 = (ulonglong *)((int)puVar1 + (param_3 + -4) * 4);
      param_3 = 4;
    }
  }
  FastExitMediaState();
  return param_1;
}


// ==== FUN_007b32bb @ 0x007b32bb ====

undefined8 * FUN_007b32bb(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar3 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar6 = CONCAT44(uVar1,uVar1);
  uVar2 = PackedFloatingMUL(uVar3,*param_3);
  uVar4 = PackedFloatingMUL(uVar6,param_3[2]);
  uVar2 = PackedFloatingADD(uVar2,param_3[6]);
  uVar5 = PackedFloatingMUL(uVar3,param_3[1]);
  uVar6 = PackedFloatingMUL(uVar6,param_3[3]);
  uVar3 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingADD(uVar5,param_3[7]);
  uVar2 = PackedFloatingADD(uVar2,uVar6);
  *param_1 = uVar3;
  param_1[1] = uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== FUN_007b3312 @ 0x007b3312 ====

undefined8 * FUN_007b3312(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar4;
  undefined8 uVar3;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar4 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar2 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),*param_3);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),param_3[2]);
  uVar2 = PackedFloatingADD(uVar2,uVar3);
  *param_1 = uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== FUN_007b334d @ 0x007b334d ====

undefined8 * FUN_007b334d(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar3 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar6 = CONCAT44(uVar1,uVar1);
  uVar2 = PackedFloatingMUL(uVar3,*param_3);
  uVar4 = PackedFloatingMUL(uVar6,param_3[2]);
  uVar2 = PackedFloatingADD(uVar2,param_3[6]);
  uVar5 = PackedFloatingMUL(uVar3,param_3[1]);
  uVar6 = PackedFloatingMUL(uVar6,param_3[3]);
  uVar3 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingADD(uVar5,param_3[7]);
  uVar2 = PackedFloatingADD(uVar2,uVar6);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  uVar2 = CONCAT44(uVar1,uVar1);
  uVar6 = FloatingReciprocalAprox(uVar6,uVar2);
  uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar6);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar6);
  uVar3 = PackedFloatingMUL(uVar3,uVar2);
  *param_1 = uVar3;
  FastExitMediaState();
  return param_1;
}


// ==== FUN_007b3582 @ 0x007b3582 ====

undefined8 * FUN_007b3582(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar8 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)param_2[1];
  uVar9 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)param_2[1] >> 0x20);
  uVar6 = CONCAT44(uVar1,uVar1);
  uVar2 = PackedFloatingMUL(uVar5,*param_3);
  uVar3 = PackedFloatingMUL(uVar8,param_3[2]);
  uVar4 = PackedFloatingMUL(uVar9,param_3[4]);
  uVar7 = PackedFloatingMUL(uVar6,param_3[6]);
  uVar2 = PackedFloatingADD(uVar2,uVar3);
  uVar3 = PackedFloatingMUL(uVar5,param_3[1]);
  uVar5 = PackedFloatingADD(uVar4,uVar7);
  uVar8 = PackedFloatingMUL(uVar8,param_3[3]);
  uVar9 = PackedFloatingMUL(uVar9,param_3[5]);
  uVar4 = PackedFloatingMUL(uVar6,param_3[7]);
  uVar5 = PackedFloatingADD(uVar2,uVar5);
  uVar2 = PackedFloatingADD(uVar3,uVar8);
  uVar8 = PackedFloatingADD(uVar9,uVar4);
  uVar2 = PackedFloatingADD(uVar2,uVar8);
  *param_1 = uVar5;
  param_1[1] = uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== FUN_007b3b95 @ 0x007b3b95 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007b3b95(undefined8 *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 in_MM4;
  undefined8 uVar5;
  
  uVar1 = *param_2;
  uVar3 = param_2[1] & _DAT_009fc890;
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar3,uVar3);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar5 = PackedFloatingReciprocalSQRAprox(in_MM4,uVar2);
  uVar3 = PackedFloatingCompareGT(uVar2,_DAT_009fc8b0);
  uVar4 = PackedFloatingMUL(uVar5,uVar5);
  uVar2 = PackedFloatingReciprocalSQRIter1(uVar2,uVar4);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar5);
  uVar4 = PackedFloatingMUL(uVar1 & uVar3,uVar2);
  uVar2 = PackedFloatingMUL(param_2[1] & uVar3,uVar2);
  *param_1 = uVar4;
  param_1[1] = uVar2;
  FastExitMediaState();
  return;
}


// ==== FUN_007b3c77 @ 0x007b3c77 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007b3c77(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  uint uVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  
  fVar6 = (float)(*param_1 & _DAT_00b48230);
  fVar10 = (float)(param_1[1] & uRam00b48234);
  fVar14 = (float)(param_1[2] & uRam00b48238);
  fVar18 = (float)(param_1[3] & uRam00b4823c);
  uVar22 = param_1[1] & uRam00b48224;
  uVar23 = param_1[2] & uRam00b48228;
  uVar24 = param_1[3] & uRam00b4822c;
  fVar7 = fVar6 * _DAT_00b48210 + _DAT_00b481c0;
  fVar11 = fVar10 * fRam00b48214 + fRam00b481c4;
  fVar15 = fVar14 * fRam00b48218 + fRam00b481c8;
  fVar19 = fVar18 * fRam00b4821c + fRam00b481cc;
  fVar8 = fVar7 - _DAT_00b481c0;
  fVar12 = fVar11 - fRam00b481c4;
  fVar16 = fVar15 - fRam00b481c8;
  fVar20 = fVar19 - fRam00b481cc;
  fVar6 = (((fVar6 - _DAT_00b48200 * fVar8) - _DAT_00b481f0 * fVar8) - _DAT_00b481e0 * fVar8) -
          _DAT_00b481d0 * fVar8;
  fVar8 = (((fVar10 - fRam00b48204 * fVar12) - fRam00b481f4 * fVar12) - fRam00b481e4 * fVar12) -
          fRam00b481d4 * fVar12;
  fVar10 = (((fVar14 - fRam00b48208 * fVar16) - fRam00b481f8 * fVar16) - fRam00b481e8 * fVar16) -
           fRam00b481d8 * fVar16;
  fVar12 = (((fVar18 - fRam00b4820c * fVar20) - fRam00b481fc * fVar20) - fRam00b481ec * fVar20) -
           fRam00b481dc * fVar20;
  fVar14 = fVar6 * fVar6;
  fVar16 = fVar8 * fVar8;
  fVar18 = fVar10 * fVar10;
  fVar20 = fVar12 * fVar12;
  uVar25 = (uint)fVar7 & _DAT_00b48190;
  uVar26 = (uint)fVar11 & uRam00b48194;
  uVar27 = (uint)fVar15 & uRam00b48198;
  uVar28 = (uint)fVar19 & uRam00b4819c;
  uVar9 = uVar25 & _DAT_00b48180;
  uVar13 = uVar26 & uRam00b48184;
  uVar17 = uVar27 & uRam00b48188;
  uVar21 = uVar28 & uRam00b4818c;
  uVar1 = uVar26 - uVar13 & _DAT_00b48170;
  uVar2 = uVar27 - uVar17 & _DAT_00b48170;
  uVar3 = uVar28 - uVar21 & _DAT_00b48170;
  uVar4 = uVar25 + uVar9 & _DAT_00b48170;
  uVar26 = uVar26 + uVar13 & _DAT_00b48170;
  uVar27 = uVar27 + uVar17 & _DAT_00b48170;
  uVar28 = uVar28 + uVar21 & _DAT_00b48170;
  uVar5 = -(uint)((float)(uVar9 << 0x1e) != 0.0);
  uVar13 = -(uint)((float)(uVar13 << 0x1e) != 0.0);
  uVar17 = -(uint)((float)(uVar17 << 0x1e) != 0.0);
  uVar21 = -(uint)((float)(uVar21 << 0x1e) != 0.0);
  fVar6 = (((_DAT_00b481b0 * fVar14 + _DAT_00b48160) * fVar14 + _DAT_00b48140) * fVar14 +
          _DAT_00b48120) * fVar6;
  fVar8 = (((fRam00b481b4 * fVar16 + fRam00b48164) * fVar16 + fRam00b48144) * fVar16 + fRam00b48124)
          * fVar8;
  fVar10 = (((fRam00b481b8 * fVar18 + fRam00b48168) * fVar18 + fRam00b48148) * fVar18 + fRam00b48128
           ) * fVar10;
  fVar12 = (((fRam00b481bc * fVar20 + fRam00b4816c) * fVar20 + fRam00b4814c) * fVar20 + fRam00b4812c
           ) * fVar12;
  fVar7 = (((_DAT_00b481a0 * fVar14 + _DAT_00b48150) * fVar14 + _DAT_00b48130) * fVar14 +
          _DAT_00b48110) * fVar14 + _DAT_00b48100;
  fVar11 = (((fRam00b481a4 * fVar16 + fRam00b48154) * fVar16 + fRam00b48134) * fVar16 + fRam00b48114
           ) * fVar16 + fRam00b48104;
  fVar14 = (((fRam00b481a8 * fVar18 + fRam00b48158) * fVar18 + fRam00b48138) * fVar18 + fRam00b48118
           ) * fVar18 + fRam00b48108;
  fVar15 = (((fRam00b481ac * fVar20 + fRam00b4815c) * fVar20 + fRam00b4813c) * fVar20 + fRam00b4811c
           ) * fVar20 + fRam00b4810c;
  *param_2 = (~uVar5 & (uint)fVar6 | uVar5 & (uint)fVar7) ^
             (uVar25 - uVar9 & _DAT_00b48170) << 0x1e ^ *param_1 & _DAT_00b48220;
  param_2[1] = (~uVar13 & (uint)fVar8 | uVar13 & (uint)fVar11) ^ uVar1 << 0x1e ^ uVar22;
  param_2[2] = (~uVar17 & (uint)fVar10 | uVar17 & (uint)fVar14) ^ uVar2 << 0x1e ^ uVar23;
  param_2[3] = (~uVar21 & (uint)fVar12 | uVar21 & (uint)fVar15) ^ uVar3 << 0x1e ^ uVar24;
  *param_3 = (uVar5 & (uint)fVar6 | ~uVar5 & (uint)fVar7) ^ uVar4 << 0x1e;
  param_3[1] = (uVar13 & (uint)fVar8 | ~uVar13 & (uint)fVar11) ^ uVar26 << 0x1e;
  param_3[2] = (uVar17 & (uint)fVar10 | ~uVar17 & (uint)fVar14) ^ uVar27 << 0x1e;
  param_3[3] = (uVar21 & (uint)fVar12 | ~uVar21 & (uint)fVar15) ^ uVar28 << 0x1e;
  return;
}


// ==== FUN_007b3e63 @ 0x007b3e63 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007b3e63(uint *param_1,uint *param_2,uint *param_3)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  float fVar16;
  float fVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  float fVar25;
  float fVar26;
  uint uVar27;
  uint uVar28;
  
  fVar16 = (float)(*param_1 & _DAT_00b48370);
  fVar17 = (float)(param_1[1] & uRam00b48374);
  fVar25 = (float)(param_1[2] & uRam00b48378);
  fVar26 = (float)(param_1[3] & uRam00b4837c);
  uVar13 = param_1[1] & uRam00b48364;
  uVar14 = param_1[2] & uRam00b48368;
  uVar15 = param_1[3] & uRam00b4836c;
  fVar1 = fVar16 * _DAT_00b48350 + _DAT_00b48300;
  fVar4 = fVar17 * fRam00b48354 + fRam00b48304;
  fVar7 = fVar25 * fRam00b48358 + fRam00b48308;
  fVar10 = fVar26 * fRam00b4835c + fRam00b4830c;
  fVar2 = fVar1 - _DAT_00b48300;
  fVar5 = fVar4 - fRam00b48304;
  fVar8 = fVar7 - fRam00b48308;
  fVar11 = fVar10 - fRam00b4830c;
  fVar16 = (((fVar16 - _DAT_00b48340 * fVar2) - _DAT_00b48330 * fVar2) - _DAT_00b48320 * fVar2) -
           _DAT_00b48310 * fVar2;
  fVar2 = (((fVar17 - fRam00b48344 * fVar5) - fRam00b48334 * fVar5) - fRam00b48324 * fVar5) -
          fRam00b48314 * fVar5;
  fVar17 = (((fVar25 - fRam00b48348 * fVar8) - fRam00b48338 * fVar8) - fRam00b48328 * fVar8) -
           fRam00b48318 * fVar8;
  fVar5 = (((fVar26 - fRam00b4834c * fVar11) - fRam00b4833c * fVar11) - fRam00b4832c * fVar11) -
          fRam00b4831c * fVar11;
  fVar25 = fVar16 * fVar16;
  fVar8 = fVar2 * fVar2;
  fVar26 = fVar17 * fVar17;
  fVar11 = fVar5 * fVar5;
  uVar18 = (uint)fVar1 & _DAT_00b482d0;
  uVar19 = (uint)fVar4 & uRam00b482d4;
  uVar21 = (uint)fVar7 & uRam00b482d8;
  uVar23 = (uint)fVar10 & uRam00b482dc;
  uVar3 = uVar18 & _DAT_00b482c0;
  uVar6 = uVar19 & uRam00b482c4;
  uVar9 = uVar21 & uRam00b482c8;
  uVar12 = uVar23 & uRam00b482cc;
  uVar20 = uVar19 - uVar6 & uRam00b482b4;
  uVar22 = uVar21 - uVar9 & uRam00b482b8;
  uVar24 = uVar23 - uVar12 & uRam00b482bc;
  uVar27 = uVar18 + uVar3 & _DAT_00b482b0;
  uVar28 = uVar19 + uVar6 & uRam00b482b4;
  uVar21 = uVar21 + uVar9 & uRam00b482b8;
  uVar23 = uVar23 + uVar12 & uRam00b482bc;
  uVar19 = -(uint)((float)(uVar3 << 0x1e) != 0.0);
  uVar6 = -(uint)((float)(uVar6 << 0x1e) != 0.0);
  uVar9 = -(uint)((float)(uVar9 << 0x1e) != 0.0);
  uVar12 = -(uint)((float)(uVar12 << 0x1e) != 0.0);
  fVar16 = (((_DAT_00b482f0 * fVar25 + _DAT_00b482a0) * fVar25 + _DAT_00b48280) * fVar25 +
           _DAT_00b48260) * fVar16;
  fVar2 = (((fRam00b482f4 * fVar8 + fRam00b482a4) * fVar8 + fRam00b48284) * fVar8 + fRam00b48264) *
          fVar2;
  fVar17 = (((fRam00b482f8 * fVar26 + fRam00b482a8) * fVar26 + fRam00b48288) * fVar26 + fRam00b48268
           ) * fVar17;
  fVar5 = (((fRam00b482fc * fVar11 + fRam00b482ac) * fVar11 + fRam00b4828c) * fVar11 + fRam00b4826c)
          * fVar5;
  fVar1 = (((_DAT_00b482e0 * fVar25 + _DAT_00b48290) * fVar25 + _DAT_00b48270) * fVar25 +
          _DAT_00b48250) * fVar25 + _DAT_00b48240;
  fVar4 = (((fRam00b482e4 * fVar8 + fRam00b48294) * fVar8 + fRam00b48274) * fVar8 + fRam00b48254) *
          fVar8 + fRam00b48244;
  fVar25 = (((fRam00b482e8 * fVar26 + fRam00b48298) * fVar26 + fRam00b48278) * fVar26 + fRam00b48258
           ) * fVar26 + fRam00b48248;
  fVar7 = (((fRam00b482ec * fVar11 + fRam00b4829c) * fVar11 + fRam00b4827c) * fVar11 + fRam00b4825c)
          * fVar11 + fRam00b4824c;
  *param_2 = (~uVar19 & (uint)fVar16 | uVar19 & (uint)fVar1) ^
             (uVar18 - uVar3 & _DAT_00b482b0) << 0x1e ^ *param_1 & _DAT_00b48360;
  param_2[1] = (~uVar6 & (uint)fVar2 | uVar6 & (uint)fVar4) ^ uVar20 << 0x1e ^ uVar13;
  param_2[2] = (~uVar9 & (uint)fVar17 | uVar9 & (uint)fVar25) ^ uVar22 << 0x1e ^ uVar14;
  param_2[3] = (~uVar12 & (uint)fVar5 | uVar12 & (uint)fVar7) ^ uVar24 << 0x1e ^ uVar15;
  *param_3 = (uVar19 & (uint)fVar16 | ~uVar19 & (uint)fVar1) ^ uVar27 << 0x1e;
  param_3[1] = (uVar6 & (uint)fVar2 | ~uVar6 & (uint)fVar4) ^ uVar28 << 0x1e;
  param_3[2] = (uVar9 & (uint)fVar17 | ~uVar9 & (uint)fVar25) ^ uVar21 << 0x1e;
  param_3[3] = (uVar12 & (uint)fVar5 | ~uVar12 & (uint)fVar7) ^ uVar23 << 0x1e;
  return;
}


// ==== FUN_007b40c0 @ 0x007b40c0 ====

ulonglong FUN_007b40c0(void)

{
  ulonglong in_MM0;
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong in_MM1;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  uVar9 = (DAT_00b49098 & in_MM0) >> 1 | DAT_00b49098 & in_MM1;
  uVar3 = in_MM1 & DAT_00b4909c;
  uVar1 = in_MM0 & DAT_00b4909c;
  uVar2 = PackedFloatingMAX(uVar1,uVar3);
  uVar7 = (uint)((int)uVar1 < (int)uVar3) * -0x80000000;
  uVar4 = PackedFloatingMIN(uVar3,uVar1);
  uVar5 = FloatingReciprocalAprox(uVar1,uVar2);
  uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar5);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar5);
  uVar2 = PackedFloatingMUL(uVar2,uVar4);
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar5 = PackedFloatingADD((ulonglong)DAT_00b490d0,uVar4);
  uVar6 = PackedFloatingMUL((ulonglong)DAT_00b490dc,uVar4);
  uVar5 = PackedFloatingMUL(uVar5,uVar4);
  uVar6 = PackedFloatingADD(uVar6,(ulonglong)DAT_00b490d8);
  uVar5 = PackedFloatingADD(uVar5,(ulonglong)DAT_00b490cc);
  uVar6 = PackedFloatingMUL(uVar6,uVar4);
  uVar5 = PackedFloatingMUL(uVar5,uVar4);
  uVar6 = PackedFloatingADD(uVar6,(ulonglong)DAT_00b490d4);
  uVar5 = PackedFloatingADD(uVar5,(ulonglong)DAT_00b490c8);
  uVar4 = PackedFloatingMUL(uVar4,uVar6);
  uVar4 = PackedFloatingMUL(uVar4,uVar2);
  uVar6 = FloatingReciprocalAprox((ulonglong)DAT_00b490d4,uVar5);
  uVar8 = (int)uVar9 << 1;
  uVar5 = PackedFloatingReciprocalIter1(uVar5,uVar6);
  uVar5 = PackedFloatingReciprocalIter2(uVar5,uVar6);
  uVar4 = PackedFloatingMUL(uVar4,uVar5);
  uVar1 = PackedFloatingADD(uVar4,uVar2);
  uVar2 = PackedFloatingSUB(~(ulonglong)(uint)((int)uVar7 >> 0x1f) &
                            (ulonglong)(uVar8 ^ DAT_00b490f8),(ulonglong)DAT_00b490f8);
  uVar1 = PackedFloatingADD(uVar1 | uVar8 ^ uVar7,uVar2);
  return uVar1 | DAT_00b49098 & uVar9;
}


// ==== FUN_007b41c0 @ 0x007b41c0 ====

ulonglong FUN_007b41c0(void)

{
  uint uVar1;
  ulonglong in_MM0;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  
  uVar2 = in_MM0 & DAT_00b4909c;
  uVar6 = -(uint)(DAT_00b490a8 < (int)uVar2);
  uVar3 = PackedFloatingMUL(uVar2,(ulonglong)DAT_00b490ac);
  uVar3 = PackedFloatingSUBR(uVar3,(ulonglong)DAT_00b490ac);
  uVar7 = PackedFloatingReciprocalSQRAprox((ulonglong)DAT_00b4909c,uVar3);
  uVar8 = PackedFloatingMUL(uVar7,uVar7);
  uVar1 = (uint)((int)uVar2 < DAT_00b490e0);
  uVar4 = -uVar1;
  uVar5 = (ulonglong)uVar4;
  uVar8 = PackedFloatingReciprocalSQRIter1(uVar8,uVar3);
  uVar7 = PackedFloatingReciprocalIter2(uVar8,uVar7);
  uVar9 = PackedFloatingMUL(uVar7,uVar3);
  uVar2 = ~uVar5 & uVar9 | uVar2 & uVar4;
  uVar3 = PackedFloatingMUL(uVar2,uVar2);
  uVar8 = PackedFloatingMUL((ulonglong)DAT_00b490e8,uVar3);
  uVar7 = PackedFloatingADD((ulonglong)DAT_00b490f0,uVar3);
  uVar8 = PackedFloatingADD(uVar8,(ulonglong)DAT_00b490e4);
  uVar8 = PackedFloatingMUL(uVar8,uVar3);
  uVar3 = PackedFloatingMUL(uVar3,uVar7);
  uVar3 = PackedFloatingADD(uVar3,(ulonglong)DAT_00b490ec);
  uVar8 = PackedFloatingMUL(uVar8,uVar2);
  uVar7 = FloatingReciprocalAprox(uVar7,uVar3);
  uVar3 = PackedFloatingReciprocalIter1(uVar3,uVar7);
  uVar3 = PackedFloatingReciprocalIter2(uVar3,uVar7);
  uVar3 = PackedFloatingMUL(uVar3,uVar8);
  uVar2 = PackedFloatingADD(uVar2,uVar3);
  uVar3 = PackedFloatingADD(~uVar5 & (ulonglong)DAT_00b490f8 ^ DAT_00b49098 & in_MM0,
                            (ulonglong)DAT_00b490f4);
  uVar2 = PackedFloatingADD(uVar2,~uVar5 & uVar2);
  uVar2 = PackedFloatingADD(uVar3,uVar2 | (ulonglong)(uVar1 * -0x80000000) ^ DAT_00b49098 & in_MM0);
  return (ulonglong)(DAT_00b490b4 & uVar6) | ~(ulonglong)uVar6 & uVar2;
}


// ==== FUN_007b47a0 @ 0x007b47a0 ====

uint FUN_007b47a0(void)

{
  ulonglong in_MM0;
  undefined8 uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar1 = PackedFloatingMUL(in_MM0 & DAT_00b4909c,(ulonglong)DAT_00b49150);
  uVar2 = PackedFloatingToIntDwordConv(uVar1,uVar1);
  uVar1 = PackedIntToFloatingDwordConv(uVar2,uVar2);
  uVar1 = PackedFloatingMUL(CONCAT44((int)uVar1,(int)uVar1),DAT_00b49060);
  uVar4 = PackedFloatingADD(in_MM0 & DAT_00b4909c,uVar1);
  uVar3 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar1 = PackedFloatingADD(uVar4,CONCAT44(uVar3,uVar3));
  uVar1 = CONCAT44((int)uVar1,(int)uVar1);
  if ((uVar2 & 1) != 0) {
    uVar1 = PackedFloatingSUBR(uVar1,DAT_00b49070);
  }
  uVar4 = PackedFloatingMUL(uVar1,uVar1);
  uVar6 = PackedFloatingMUL(DAT_00b49068,uVar4);
  uVar5 = PackedFloatingMUL(DAT_00b49078,uVar4);
  uVar7 = PackedFloatingADD(uVar6,DAT_00b49018);
  uVar6 = PackedFloatingMUL(DAT_00b49080,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,uVar5);
  uVar7 = PackedFloatingADD(uVar5,DAT_00b49018);
  uVar5 = PackedFloatingMUL(DAT_00b49088,uVar4);
  uVar4 = PackedFloatingMUL(uVar6,uVar7);
  uVar4 = PackedFloatingADD(uVar4,DAT_00b49018);
  uVar4 = PackedFloatingMUL(uVar4,CONCAT44((int)DAT_00b49018,(int)uVar5));
  uVar4 = PackedFloatingADD(uVar4,DAT_00b49018 >> 0x20);
  PackedFloatingMUL(uVar4,CONCAT44((int)uVar1,(int)DAT_00b49018));
  return (uint)in_MM0 ^ (uint)in_MM0 & 0x80000000;
}


// ==== FUN_007b48a0 @ 0x007b48a0 ====

uint FUN_007b48a0(void)

{
  ulonglong in_MM0;
  undefined8 uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar1 = PackedFloatingMUL(in_MM0 & DAT_00b4909c,(ulonglong)DAT_00b49150);
  uVar2 = PackedFloatingToIntDwordConv(uVar1,uVar1);
  uVar1 = PackedIntToFloatingDwordConv(uVar2,uVar2);
  uVar1 = PackedFloatingMUL(CONCAT44((int)uVar1,(int)uVar1),DAT_00b49060);
  uVar4 = PackedFloatingADD(in_MM0 & DAT_00b4909c,uVar1);
  uVar3 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar1 = PackedFloatingADD(uVar4,CONCAT44(uVar3,uVar3));
  uVar1 = CONCAT44((int)uVar1,(int)uVar1);
  if ((uVar2 & 1) != 0) {
    uVar1 = PackedFloatingSUBR(uVar1,DAT_00b49070);
  }
  uVar4 = PackedFloatingMUL(uVar1,uVar1);
  uVar6 = PackedFloatingMUL(DAT_00b49068,uVar4);
  uVar5 = PackedFloatingMUL(DAT_00b49078,uVar4);
  uVar7 = PackedFloatingADD(uVar6,DAT_00b49018);
  uVar6 = PackedFloatingMUL(DAT_00b49080,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,uVar5);
  uVar7 = PackedFloatingADD(uVar5,DAT_00b49018);
  uVar5 = PackedFloatingMUL(DAT_00b49088,uVar4);
  uVar4 = PackedFloatingMUL(uVar6,uVar7);
  uVar4 = PackedFloatingADD(uVar4,DAT_00b49018);
  uVar4 = PackedFloatingMUL(uVar4,CONCAT44((int)DAT_00b49018,(int)uVar5));
  uVar4 = PackedFloatingADD(uVar4,DAT_00b49018 >> 0x20);
  PackedFloatingMUL(uVar4,CONCAT44((int)uVar1,(int)DAT_00b49018));
  return (uint)in_MM0 ^ (uint)in_MM0 & 0x80000000;
}


// ==== FUN_007b4c60 @ 0x007b4c60 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007b4c60(void)

{
  DWORD DVar1;
  CHAR local_84 [128];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  DVar1 = GetLastError();
  DVar1 = FormatMessageA(0x1200,(LPCVOID)0x0,DVar1,0,local_84,0x80,(va_list *)0x0);
  if (DVar1 == 0) {
    FUN_007bc510();
    return;
  }
  FUN_007bc470();
  return;
}


// ==== FUN_007b4ce0 @ 0x007b4ce0 ====

undefined4 FUN_007b4ce0(undefined4 param_1)

{
  LPCSTR lpLibFileName;
  LPCSTR lpProcName;
  HMODULE hModule;
  FARPROC pFVar1;
  undefined *puVar2;
  
  lpLibFileName = (LPCSTR)FUN_007bbad0(param_1,1,0);
  lpProcName = (LPCSTR)FUN_007bbad0(param_1,2,0);
  hModule = LoadLibraryA(lpLibFileName);
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,lpProcName);
    if (pFVar1 != (FARPROC)0x0) {
      FUN_007bc600(param_1,hModule);
      FUN_007bc540(param_1,pFVar1,1);
      return 1;
    }
  }
  FUN_007bc3e0(param_1);
  FUN_007b4c60();
  puVar2 = &DAT_009fce7c;
  if (hModule == (HMODULE)0x0) {
    puVar2 = &DAT_009fce74;
  }
  FUN_007bc470(param_1,puVar2);
  if (hModule != (HMODULE)0x0) {
    FreeLibrary(hModule);
  }
  return 3;
}


// ==== FUN_007b4d80 @ 0x007b4d80 ====

undefined4 FUN_007b4d80(undefined4 param_1)

{
  FUN_007bc470(param_1,s_loadlib_009fce84);
  FUN_007bc540(param_1,FUN_007b4ce0,0);
  FUN_007bc810(param_1,0xffffd8ef);
  return 0;
}


// ==== FUN_007b4db0 @ 0x007b4db0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b4db0(undefined4 param_1)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined1 local_70 [4];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_50 [68];
  undefined4 local_c;
  
  local_c = DAT_00b49670;
  pcVar4 = (char *)FUN_007bbb40(param_1,2,s_flnSu_009fd008,0);
  iVar5 = FUN_007bc030(param_1,1);
  if (iVar5 == 0) {
    iVar5 = FUN_007bbfa0(param_1,1);
    if (iVar5 != 6) {
      uVar7 = 0x9fcf8000000001;
      goto LAB_007b5023;
    }
    FUN_007bc510(param_1,&DAT_009fd004,pcVar4);
    pcVar4 = (char *)FUN_007bc230(param_1,0xffffffff);
    FUN_007bbf60(param_1,1);
  }
  else {
    FUN_007bc1a0(param_1,1,local_70);
    uVar6 = FUN_00802534();
    iVar5 = FUN_007bdf40(param_1,uVar6);
    if (iVar5 == 0) {
      FUN_007bc3e0();
      return 1;
    }
  }
  iVar5 = FUN_007beab0(param_1,pcVar4,local_70);
  if (iVar5 != 0) {
    FUN_007bc710();
    cVar2 = *pcVar4;
    uVar6 = local_6c;
    uVar3 = local_60;
    while (cVar2 != '\0') {
      local_6c = uVar6;
      local_60 = uVar3;
      switch(cVar2) {
      case 'S':
        FUN_007bc470(param_1,s_source_009fcfec);
        FUN_007bc470(param_1,uVar3);
        FUN_007bc850(param_1,0xfffffffd);
        FUN_007bc470(param_1,s_short_src_009fcfe0);
        FUN_007bc470(param_1,local_50);
        FUN_007bc850(param_1,0xfffffffd);
        FUN_007bc470(param_1,s_linedefined_009fcfd4);
        FUN_007bc400(param_1);
        FUN_007bc850(param_1,0xfffffffd);
        uVar6 = local_64;
        FUN_007bc470(param_1,&DAT_009fcfcc);
        FUN_007bc470(param_1,uVar6);
        FUN_007bc850(param_1,0xfffffffd);
        break;
      case 'f':
        FUN_007bc420(param_1);
        FUN_007bbf60(param_1,0xfffffffd);
        FUN_007bc850(param_1,0xfffffffd);
        break;
      case 'l':
        FUN_007bc470(param_1,s_currentline_009fcfc0);
        FUN_007bc400(param_1);
        FUN_007bc850(param_1,0xfffffffd);
        break;
      case 'n':
        FUN_007bc470(param_1,&DAT_009fcfb0);
        FUN_007bc470(param_1,uVar6);
        FUN_007bc850(param_1,0xfffffffd);
        uVar6 = local_68;
        FUN_007bc470(param_1,s_namewhat_009fcfa4);
        FUN_007bc470(param_1,uVar6);
        FUN_007bc850(param_1,0xfffffffd);
        break;
      case 'u':
        FUN_007bc470(param_1,&DAT_009fcfb8);
        FUN_007bc400(param_1);
        FUN_007bc850(param_1,0xfffffffd);
      }
      pcVar1 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
      uVar6 = local_6c;
      uVar3 = local_60;
      cVar2 = *pcVar1;
    }
    return 1;
  }
  uVar7 = 0x9fcff400000002;
LAB_007b5023:
  uVar6 = FUN_007bb990(param_1,uVar7);
  return uVar6;
}


// ==== FUN_007b5080 @ 0x007b5080 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b5080(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_64 [96];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  FUN_007bbba0(param_1,1,local_64);
  uVar1 = FUN_00802534();
  iVar2 = FUN_007bdf40(param_1,uVar1);
  if (iVar2 == 0) {
    uVar1 = FUN_007bb990(param_1,1,s_level_out_of_range_009fd010);
    return uVar1;
  }
  FUN_007bbba0(param_1,2);
  uVar1 = FUN_00802534();
  iVar2 = FUN_007bdfc0(param_1,local_64,uVar1);
  if (iVar2 == 0) {
    FUN_007bc3e0(param_1);
    return 1;
  }
  FUN_007bc470(param_1,iVar2);
  FUN_007bbf60(param_1,0xfffffffe);
  return 2;
}


// ==== FUN_007b5140 @ 0x007b5140 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b5140(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_64 [96];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  FUN_007bbba0(param_1,1,local_64);
  uVar1 = FUN_00802534();
  iVar2 = FUN_007bdf40(param_1,uVar1);
  if (iVar2 == 0) {
    uVar1 = FUN_007bb990(param_1,1,s_level_out_of_range_009fd010);
    return uVar1;
  }
  FUN_007bbaa0(param_1,3);
  FUN_007bbba0(param_1,2);
  uVar1 = FUN_00802534();
  uVar1 = FUN_007be040(param_1,local_64,uVar1);
  FUN_007bc470(param_1,uVar1);
  return 1;
}


// ==== FUN_007b51e0 @ 0x007b51e0 ====

undefined4 FUN_007b51e0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_007bbba0(param_1,2);
  uVar1 = FUN_00802534();
  FUN_007bba50(param_1,1,6);
  iVar2 = FUN_007bbff0(param_1,1);
  if (iVar2 == 0) {
    iVar2 = FUN_007bcd30(param_1,1,uVar1);
    if (iVar2 != 0) {
      FUN_007bc470(param_1,iVar2);
      FUN_007bbeb0(param_1,0xfffffffe);
      return 2;
    }
  }
  return 0;
}


// ==== FUN_007b5240 @ 0x007b5240 ====

undefined4 FUN_007b5240(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_007bbaa0(param_1,3);
  FUN_007bbba0(param_1,2);
  uVar1 = FUN_00802534();
  FUN_007bba50(param_1,1,6);
  iVar2 = FUN_007bbff0(param_1,1);
  if (iVar2 == 0) {
    iVar2 = FUN_007bcd70(param_1,1,uVar1);
    if (iVar2 != 0) {
      FUN_007bc470(param_1,iVar2);
      FUN_007bbeb0(param_1,0xffffffff);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007b5350 @ 0x007b5350 ====

byte FUN_007b5350(int param_1)

{
  char *pcVar1;
  char *unaff_EDI;
  byte bVar2;
  
  pcVar1 = _strchr(unaff_EDI,99);
  bVar2 = pcVar1 != (char *)0x0;
  pcVar1 = _strchr(unaff_EDI,0x72);
  if (pcVar1 != (char *)0x0) {
    bVar2 = bVar2 | 2;
  }
  pcVar1 = _strchr(unaff_EDI,0x6c);
  if (pcVar1 != (char *)0x0) {
    bVar2 = bVar2 | 4;
  }
  if (0 < param_1) {
    bVar2 = bVar2 | 8;
  }
  return bVar2;
}


// ==== FUN_007b53a0 @ 0x007b53a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b53a0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_007bbfa0(param_1,1);
  if (iVar1 < 1) {
    FUN_007bbdf0(param_1,1);
    FUN_007bded0(param_1,0,0,0);
  }
  else {
    FUN_007bbad0(param_1,2,0);
    FUN_007bbc20(param_1,3,_DAT_0099d098);
    uVar2 = FUN_00802534();
    FUN_007bba50(param_1,1,6);
    uVar2 = FUN_007b5350(uVar2,uVar2);
    FUN_007bded0(param_1,&LAB_007b52b0,uVar2);
  }
  FUN_007bc600(param_1,&DAT_009fce90);
  FUN_007bbf60(param_1,1);
  FUN_007bc850(param_1,0xffffd8f0);
  return 0;
}


// ==== FUN_007b5450 @ 0x007b5450 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b5450(undefined4 param_1)

{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  undefined1 local_c [8];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  uVar1 = FUN_007bdf20();
  puVar2 = (undefined1 *)FUN_007bdf10(param_1);
  if ((puVar2 == (undefined1 *)0x0) || (puVar2 == &LAB_007b52b0)) {
    FUN_007bc600(param_1,&DAT_009fce90);
    FUN_007bc670(param_1,0xffffd8f0);
  }
  else {
    FUN_007bc420(param_1,s_external_hook_009fd024,0xd);
  }
  bVar5 = (uVar1 & 1) != 0;
  if (bVar5) {
    local_c[0] = 99;
  }
  uVar3 = (uint)bVar5;
  if ((uVar1 & 2) != 0) {
    local_c[uVar3] = 0x72;
    uVar3 = uVar3 + 1;
  }
  if ((uVar1 & 4) != 0) {
    local_c[uVar3] = 0x6c;
    uVar3 = uVar3 + 1;
  }
  local_c[uVar3] = 0;
  FUN_007bc470(param_1,local_c);
  iVar4 = FUN_007bdf30(param_1);
  FUN_007bc400(param_1,(double)iVar4);
  return 3;
}


// ==== FUN_007b5520 @ 0x007b5520 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b5520(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  char local_100 [252];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  _fputs(s_lua_debug>_009fd03c,(FILE *)&DAT_00b496c0);
  pcVar1 = _fgets(local_100,0xfa,(FILE *)&PTR_DAT_00b49680);
  if (pcVar1 == (char *)0x0) {
    return 0;
  }
  do {
    iVar2 = 6;
    bVar4 = true;
    pcVar1 = local_100;
    pcVar3 = s_cont_009fd034;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar4 = *pcVar1 == *pcVar3;
      pcVar1 = pcVar1 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return 0;
    }
    FUN_007bb960(param_1,local_100);
    FUN_007bbdf0(param_1,0);
    _fputs(s_lua_debug>_009fd03c,(FILE *)&DAT_00b496c0);
    pcVar1 = _fgets(local_100,0xfa,(FILE *)&PTR_DAT_00b49680);
    if (pcVar1 == (char *)0x0) {
      return 0;
    }
  } while( true );
}


// ==== FUN_007b55f0 @ 0x007b55f0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b55f0(undefined4 param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 local_64 [4];
  undefined4 local_60;
  undefined1 *local_5c;
  char *local_58;
  int local_50;
  undefined4 local_48;
  undefined1 local_44 [64];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  bVar2 = true;
  iVar3 = FUN_007bbde0(param_1);
  if (iVar3 == 0) {
    puVar7 = &DAT_0099cf70;
    uVar5 = 0;
  }
  else {
    iVar3 = FUN_007bc080(param_1,1);
    if (iVar3 == 0) {
      return 1;
    }
    uVar5 = 1;
    puVar7 = &DAT_009fd0b4;
  }
  FUN_007bc420(param_1,puVar7,uVar5);
  FUN_007bc420(param_1,s_stack_traceback__009fd0a0,0x10);
  iVar4 = FUN_007bdf40(param_1,1,local_64);
  iVar3 = 1;
  while (iVar4 != 0) {
    iVar6 = iVar3 + 1;
    if ((iVar6 < 0xd) || (!bVar2)) {
      FUN_007bc420(param_1,&DAT_009fd094,2);
      FUN_007beab0(param_1,&DAT_009fd090,local_64);
      FUN_007bc510(param_1,&DAT_009fd08c,local_44);
      if (0 < local_50) {
        FUN_007bc510(param_1,&DAT_009fd088,local_50);
      }
      switch(*local_5c) {
      case 0x66:
      case 0x67:
      case 0x6c:
      case 0x6d:
        FUN_007bc510(param_1,s_in_function___s__009fd074,local_60);
        break;
      default:
        cVar1 = *local_58;
        if (cVar1 == 'm') {
          FUN_007bc510(param_1,s_in_main_chunk_009fd064);
        }
        else if ((cVar1 == 'C') || (cVar1 == 't')) {
          FUN_007bc420(param_1,&DAT_009fd048,2);
        }
        else {
          FUN_007bc510(param_1,s_in_function_<_s:_d>_009fd04c,local_44,local_48);
        }
      }
      uVar5 = FUN_007bbde0(param_1);
      FUN_007bcc00(param_1,uVar5);
    }
    else {
      iVar4 = FUN_007bdf40(param_1,iVar3 + 0xb,local_64);
      if (iVar4 == 0) {
        bVar2 = false;
        iVar6 = iVar3;
      }
      else {
        FUN_007bc420(param_1,s_____009fd098,5);
        iVar3 = FUN_007bdf40(param_1,iVar3 + 0xb,local_64);
        while (iVar3 != 0) {
          iVar3 = FUN_007bdf40(param_1,iVar6 + 0xb,local_64);
          iVar6 = iVar6 + 1;
        }
        bVar2 = false;
      }
    }
    iVar4 = FUN_007bdf40(param_1,iVar6,local_64);
    iVar3 = iVar6;
  }
  uVar5 = FUN_007bbde0(param_1);
  FUN_007bcc00(param_1,uVar5);
  return 1;
}


// ==== FUN_007b57f0 @ 0x007b57f0 ====

undefined4 FUN_007b57f0(undefined4 param_1)

{
  FUN_007bb040(param_1,s_debug_009fcf04,&PTR_s_getlocal_009fcea8,0);
  FUN_007bc420(param_1,s__TRACEBACK_009fd0b8,10);
  FUN_007bc540(param_1,FUN_007b55f0,0);
  FUN_007bc810(param_1,0xffffd8ef);
  return 1;
}


// ==== FUN_007b5840 @ 0x007b5840 ====

undefined4 FUN_007b5840(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_007bbba0(param_1,1);
  FUN_007bc400(param_1,(double)ABS(fVar1));
  return 1;
}


// ==== FUN_007b5870 @ 0x007b5870 ====

undefined4 FUN_007b5870(undefined4 param_1)

{
  unkbyte10 Var1;
  float10 fVar2;
  
  Var1 = FUN_007bbba0(param_1,1);
  fVar2 = (float10)fsin(Var1);
  FUN_007bc400(param_1,(double)fVar2);
  return 1;
}


// ==== FUN_007b58a0 @ 0x007b58a0 ====

undefined4 FUN_007b58a0(undefined4 param_1)

{
  unkbyte10 Var1;
  float10 fVar2;
  
  Var1 = FUN_007bbba0(param_1,1);
  fVar2 = (float10)fcos(Var1);
  FUN_007bc400(param_1,(double)fVar2);
  return 1;
}


// ==== FUN_007b58d0 @ 0x007b58d0 ====

undefined4 FUN_007b58d0(undefined4 param_1)

{
  unkbyte10 Var1;
  float10 fVar2;
  
  Var1 = FUN_007bbba0(param_1,1);
  fVar2 = (float10)fptan(Var1);
  FUN_007bc400(param_1,(double)fVar2);
  return 1;
}


// ==== FUN_007b5900 @ 0x007b5900 ====

undefined4 FUN_007b5900(undefined4 param_1)

{
  float10 fVar1;
  
  FUN_007bbba0(param_1,1);
  fVar1 = (float10)FUN_00801e30();
  FUN_007bc400(param_1,(double)fVar1);
  return 1;
}


// ==== FUN_007b5930 @ 0x007b5930 ====

undefined4 FUN_007b5930(undefined4 param_1)

{
  float10 fVar1;
  
  FUN_007bbba0(param_1,1);
  fVar1 = (float10)FUN_00801d60();
  FUN_007bc400(param_1,(double)fVar1);
  return 1;
}


// ==== FUN_007b5960 @ 0x007b5960 ====

undefined4 FUN_007b5960(undefined4 param_1)

{
  unkbyte10 Var1;
  float10 fVar2;
  
  Var1 = FUN_007bbba0(param_1,1);
  fVar2 = (float10)fpatan(Var1,(float10)1);
  FUN_007bc400(param_1,(double)fVar2);
  return 1;
}


// ==== FUN_007b5990 @ 0x007b5990 ====

undefined4 FUN_007b5990(undefined4 param_1)

{
  float10 fVar1;
  unkbyte10 Var2;
  
  fVar1 = (float10)FUN_007bbba0(param_1,1);
  Var2 = FUN_007bbba0(param_1,2);
  fVar1 = (float10)fpatan((float10)(double)fVar1,Var2);
  FUN_007bc400(param_1,(double)fVar1);
  return 1;
}


// ==== FUN_007b59d0 @ 0x007b59d0 ====

undefined4 FUN_007b59d0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_007bbba0(param_1,1);
  fVar1 = (float10)FUN_008043d0((double)fVar1);
  FUN_007bc400(param_1,(double)fVar1);
  return 1;
}


// ==== FUN_007b5a00 @ 0x007b5a00 ====

undefined4 FUN_007b5a00(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_007bbba0(param_1,1);
  fVar1 = (float10)FUN_008044f0((double)fVar1);
  FUN_007bc400(param_1,(double)fVar1);
  return 1;
}


// ==== FUN_007b5a30 @ 0x007b5a30 ====

undefined4 FUN_007b5a30(undefined4 param_1)

{
  float10 fVar1;
  
  FUN_007bbba0(param_1,1);
  FUN_007bbba0(param_1,2);
  fVar1 = (float10)FUN_0080462a();
  FUN_007bc400(param_1,(double)fVar1);
  return 1;
}


// ==== FUN_007b5a80 @ 0x007b5a80 ====

undefined4 FUN_007b5a80(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_007bbba0(param_1,1);
  FUN_007bc400(param_1,(double)SQRT(fVar1));
  return 1;
}


// ==== FUN_007b5ab0 @ 0x007b5ab0 ====

undefined4 FUN_007b5ab0(undefined4 param_1)

{
  float10 fVar1;
  
  FUN_007bbba0(param_1,1);
  FUN_007bbba0(param_1,2);
  fVar1 = (float10)FUN_00801f40();
  FUN_007bc400(param_1,(double)fVar1);
  return 1;
}


// ==== FUN_007b5b00 @ 0x007b5b00 ====

undefined4 FUN_007b5b00(undefined4 param_1)

{
  float10 fVar1;
  unkbyte10 Var2;
  
  Var2 = FUN_007bbba0(param_1,1);
  fVar1 = (float10)log2(Var2);
  FUN_007bc400(param_1,(double)((float10)0.6931471805599453 * fVar1));
  return 1;
}


// ==== FUN_007b5b30 @ 0x007b5b30 ====

undefined4 FUN_007b5b30(undefined4 param_1)

{
  float10 fVar1;
  unkbyte10 Var2;
  
  Var2 = FUN_007bbba0(param_1,1);
  fVar1 = (float10)log2(Var2);
  FUN_007bc400(param_1,(double)((float10)0.3010299956639812 * fVar1));
  return 1;
}


// ==== FUN_007b5b60 @ 0x007b5b60 ====

undefined4 FUN_007b5b60(undefined4 param_1)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)FUN_007bbba0(param_1,1);
  fVar2 = ROUND((float10)1.4426950408889634 * fVar1);
  fVar1 = (float10)f2xm1((float10)1.4426950408889634 * fVar1 - fVar2);
  fVar1 = (float10)fscale((float10)1 + fVar1,fVar2);
  FUN_007bc400(param_1,(double)fVar1);
  return 1;
}


// ==== FUN_007b5ba0 @ 0x007b5ba0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b5ba0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_007bbba0(param_1,1);
  FUN_007bc400(param_1,(double)(fVar1 * (float10)_DAT_009fd228));
  return 1;
}


// ==== FUN_007b5bd0 @ 0x007b5bd0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b5bd0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_007bbba0(param_1,1);
  FUN_007bc400(param_1,(double)(fVar1 * (float10)_DAT_009fd230));
  return 1;
}


// ==== FUN_007b5c00 @ 0x007b5c00 ====

undefined4 FUN_007b5c00(undefined4 param_1)

{
  float10 fVar1;
  double dVar2;
  int *_Y;
  int local_4;
  
  _Y = &local_4;
  fVar1 = (float10)FUN_007bbba0(param_1,1);
  dVar2 = _frexp((double)fVar1,_Y);
  FUN_007bc400(param_1,SUB84(dVar2,0),(int)((ulonglong)dVar2 >> 0x20));
  FUN_007bc400(param_1,(double)local_4);
  return 2;
}


// ==== FUN_007b5c50 @ 0x007b5c50 ====

undefined4 FUN_007b5c50(undefined4 param_1)

{
  int _Y;
  float10 fVar1;
  double dVar2;
  
  FUN_007bbba0(param_1,2);
  _Y = FUN_00802534();
  fVar1 = (float10)FUN_007bbba0(param_1,1);
  dVar2 = _ldexp((double)fVar1,_Y);
  FUN_007bc400(param_1,SUB84(dVar2,0),(int)((ulonglong)dVar2 >> 0x20));
  return 1;
}


// ==== FUN_007b5c90 @ 0x007b5c90 ====

undefined4 FUN_007b5c90(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  double local_10;
  
  iVar1 = FUN_007bbde0();
  fVar3 = (float10)FUN_007bbba0(param_1,1);
  local_10 = (double)fVar3;
  iVar2 = 2;
  if (1 < iVar1) {
    do {
      fVar3 = (float10)FUN_007bbba0(param_1,iVar2);
      if (fVar3 < (float10)local_10) {
        local_10 = (double)fVar3;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= iVar1);
  }
  FUN_007bc400(param_1,local_10);
  return 1;
}


// ==== FUN_007b5d10 @ 0x007b5d10 ====

undefined4 FUN_007b5d10(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  double local_10;
  
  iVar1 = FUN_007bbde0();
  fVar3 = (float10)FUN_007bbba0(param_1,1);
  local_10 = (double)fVar3;
  iVar2 = 2;
  if (1 < iVar1) {
    do {
      fVar3 = (float10)FUN_007bbba0(param_1,iVar2);
      if ((float10)local_10 < fVar3) {
        local_10 = (double)fVar3;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= iVar1);
  }
  FUN_007bc400(param_1,local_10);
  return 1;
}


// ==== FUN_007b5d90 @ 0x007b5d90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b5d90(undefined4 param_1)

{
  double dVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = _rand();
  dVar1 = (double)(iVar2 % 0x7fff) * _PTR_DAT_009fd268;
  iVar2 = FUN_007bbde0();
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      FUN_007bbba0(param_1,1);
      iVar2 = FUN_00802534();
      if (iVar2 < 1) {
        FUN_007bb990(param_1,1,s__interval_is_empty_009fd237 + 1);
      }
      FUN_008044f0((double)iVar2 * dVar1);
      iVar2 = FUN_00802534();
      dVar1 = (double)(iVar2 + 1);
    }
    else {
      if (iVar2 != 2) {
        uVar3 = FUN_007bad90(param_1,s_wrong_number_of_arguments_009fd24c);
        return uVar3;
      }
      FUN_007bbba0(param_1,1);
      iVar2 = FUN_00802534();
      FUN_007bbba0(param_1,2);
      iVar4 = FUN_00802534();
      if (iVar4 < iVar2) {
        FUN_007bb990(param_1,2,s__interval_is_empty_009fd237 + 1);
      }
      FUN_008044f0((double)((iVar4 - iVar2) + 1) * dVar1);
      iVar4 = FUN_00802534();
      dVar1 = (double)(iVar4 + iVar2);
    }
  }
  FUN_007bc400(param_1,dVar1);
  return 1;
}


// ==== FUN_007b5ec0 @ 0x007b5ec0 ====

undefined4 FUN_007b5ec0(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_007bbba0(param_1,1);
  uVar1 = FUN_00802534();
  FUN_00801d2d(uVar1);
  return 0;
}


// ==== FUN_007b5ee0 @ 0x007b5ee0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b5ee0(undefined4 param_1)

{
  FUN_007bb040(param_1,&DAT_009fd284,&PTR_DAT_009fd0c8,0);
  FUN_007bc420(param_1,&DAT_009fd280,2);
  FUN_007bc400(param_1,_DAT_009fd278);
  FUN_007bc810(param_1,0xfffffffd);
  FUN_007bc420(param_1,s___pow_009fd270,5);
  FUN_007bc540(param_1,FUN_007b5ab0,0);
  FUN_007bc810(param_1,0xffffd8ef);
  return 1;
}


// ==== FUN_007b5f50 @ 0x007b5f50 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b5f50(undefined4 param_1)

{
  double dVar1;
  int local_8 [2];
  
  FUN_007bbad0(param_1,1,local_8);
  dVar1 = (double)local_8[0];
  if (local_8[0] < 0) {
    dVar1 = dVar1 + _DAT_009c2f50;
  }
  FUN_007bc400(param_1,dVar1);
  return 1;
}


// ==== FUN_007b5f90 @ 0x007b5f90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b5f90(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar2 = FUN_007bbad0(param_1,1,&local_4);
  iVar4 = local_4;
  FUN_007bbba0(param_1,2);
  iVar3 = FUN_00802534();
  iVar1 = local_4;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1 + iVar4;
  }
  FUN_007bbc20(param_1,3,_DAT_009fd350);
  iVar4 = FUN_00802534();
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1 + iVar1;
  }
  if (iVar3 < 1) {
    iVar3 = 1;
  }
  if (local_4 < iVar4) {
    iVar4 = local_4;
  }
  if (iVar4 < iVar3) {
    FUN_007bc420(param_1,&DAT_0099cf70,0);
    return 1;
  }
  FUN_007bc420(param_1,iVar3 + -1 + iVar2,(iVar4 - iVar3) + 1);
  return 1;
}


// ==== FUN_007b6040 @ 0x007b6040 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b6040(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_214;
  undefined4 *local_210 [131];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar1 = FUN_007bbad0(param_1,1,&local_214);
  FUN_007bb5b0(param_1,local_210);
  uVar3 = 0;
  if (local_214 != 0) {
    do {
      if (&local_4 <= local_210[0]) {
        FUN_007bb420(local_210);
      }
      iVar2 = _tolower((uint)*(byte *)(uVar3 + iVar1));
      *(char *)local_210[0] = (char)iVar2;
      local_210[0] = (undefined4 *)((int)local_210[0] + 1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < local_214);
  }
  FUN_007bb4c0(local_210);
  return 1;
}


// ==== FUN_007b60f0 @ 0x007b60f0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b60f0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_214;
  undefined4 *local_210 [131];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar1 = FUN_007bbad0(param_1,1,&local_214);
  FUN_007bb5b0(param_1,local_210);
  uVar3 = 0;
  if (local_214 != 0) {
    do {
      if (&local_4 <= local_210[0]) {
        FUN_007bb420(local_210);
      }
      iVar2 = _toupper((uint)*(byte *)(uVar3 + iVar1));
      *(char *)local_210[0] = (char)iVar2;
      local_210[0] = (undefined4 *)((int)local_210[0] + 1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < local_214);
  }
  FUN_007bb4c0(local_210);
  return 1;
}


// ==== FUN_007b61a0 @ 0x007b61a0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b61a0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_214;
  undefined1 local_210 [524];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  uVar1 = FUN_007bbad0(param_1,1,&local_214);
  FUN_007bbba0(param_1,2);
  iVar2 = FUN_00802534();
  FUN_007bb5b0(param_1,local_210);
  if (0 < iVar2) {
    do {
      FUN_007bb460(local_210,uVar1,local_214);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_007bb4c0(local_210);
  return 1;
}


// ==== FUN_007b6230 @ 0x007b6230 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b6230(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  uint local_8;
  uint local_4;
  
  iVar2 = FUN_007bbad0(param_1,1,&local_8);
  uVar1 = local_8;
  FUN_007bbc20(param_1,2,_DAT_0099d0a0);
  uVar3 = FUN_00802534();
  bVar4 = false;
  if ((int)uVar3 < 0) {
    uVar3 = uVar3 + 1 + uVar1;
    bVar4 = (int)uVar3 < 0;
  }
  if ((uVar3 == 0 || bVar4) || (local_8 < uVar3)) {
    return 0;
  }
  local_4 = (uint)*(byte *)((uVar3 - 1) + iVar2);
  FUN_007bc400(param_1,(double)local_4);
  return 1;
}


// ==== FUN_007b62b0 @ 0x007b62b0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b62b0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *local_210 [131];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar1 = FUN_007bbde0(param_1);
  FUN_007bb5b0(param_1,local_210);
  iVar3 = 1;
  if (0 < iVar1) {
    do {
      FUN_007bbba0(param_1,iVar3);
      uVar2 = FUN_00802534();
      if ((uVar2 & 0xff) != uVar2) {
        FUN_007bb990(param_1,iVar3,s_invalid_value_009fd358);
      }
      if (&local_4 <= local_210[0]) {
        FUN_007bb420(local_210);
      }
      *(char *)local_210[0] = (char)uVar2;
      local_210[0] = (undefined4 *)((int)local_210[0] + 1);
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar1);
  }
  FUN_007bb4c0(local_210);
  return 1;
}


// ==== FUN_007b6390 @ 0x007b6390 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b6390(undefined4 param_1)

{
  int iVar1;
  undefined1 local_210 [524];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  FUN_007bba50(param_1,1,6);
  FUN_007bb5b0(param_1,local_210);
  iVar1 = FUN_007bcaf0(param_1,&LAB_007b6370,local_210);
  if (iVar1 == 0) {
    FUN_007bad90(param_1,s_unable_to_dump_given_function_009fd368);
  }
  FUN_007bb4c0(local_210);
  return 1;
}


// ==== FUN_007b6410 @ 0x007b6410 ====

char * FUN_007b6410(void)

{
  char *in_EAX;
  char *pcVar1;
  char *pcVar2;
  int unaff_EDI;
  
  pcVar1 = in_EAX + 1;
  if (*in_EAX == '%') {
    if (*pcVar1 == '\0') {
      FUN_007bad90(*(undefined4 *)(unaff_EDI + 8),s_malformed_pattern__ends_with_____009fd3b8);
    }
    return in_EAX + 2;
  }
  if (*in_EAX != '[') {
    return pcVar1;
  }
  if (*pcVar1 == '^') {
    pcVar1 = in_EAX + 2;
  }
  do {
    if (*pcVar1 == '\0') {
      FUN_007bad90(*(undefined4 *)(unaff_EDI + 8),s_malformed_pattern__missing______009fd3dc);
    }
    pcVar2 = pcVar1 + 1;
    if ((*pcVar1 == '%') && (*pcVar2 != '\0')) {
      pcVar2 = pcVar1 + 2;
    }
    pcVar1 = pcVar2;
  } while (*pcVar2 != ']');
  return pcVar2 + 1;
}


// ==== FUN_007b6480 @ 0x007b6480 ====

uint FUN_007b6480(void)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  
  iVar1 = _tolower(unaff_EDI);
  switch(iVar1) {
  case 0x61:
    uVar2 = _isalpha(in_EAX);
    break;
  default:
    return (uint)(unaff_EDI == in_EAX);
  case 99:
    uVar2 = _iscntrl(in_EAX);
    break;
  case 100:
    uVar2 = _isdigit(in_EAX);
    break;
  case 0x6c:
    uVar2 = _islower(in_EAX);
    break;
  case 0x70:
    uVar2 = _ispunct(in_EAX);
    break;
  case 0x73:
    uVar2 = _isspace(in_EAX);
    break;
  case 0x75:
    uVar2 = _isupper(in_EAX);
    break;
  case 0x77:
    uVar2 = _isalnum(in_EAX);
    break;
  case 0x78:
    uVar2 = _isxdigit(in_EAX);
    break;
  case 0x7a:
    uVar2 = (uint)(in_EAX == 0);
  }
  iVar1 = _islower(unaff_EDI);
  if (iVar1 == 0) {
    return (uint)(uVar2 == 0);
  }
  return uVar2;
}


// ==== FUN_007b6590 @ 0x007b6590 ====

bool FUN_007b6590(byte *param_1)

{
  byte bVar1;
  int in_EAX;
  int iVar2;
  uint unaff_EBX;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  
  bVar5 = *(char *)(in_EAX + 1) == '^';
  if (bVar5) {
    in_EAX = in_EAX + 1;
  }
  bVar5 = !bVar5;
  pbVar4 = (byte *)(in_EAX + 1);
  if (pbVar4 < param_1) {
    pbVar3 = (byte *)(in_EAX + 3);
    do {
      if (*pbVar4 == 0x25) {
        pbVar4 = pbVar4 + 1;
        pbVar3 = pbVar3 + 1;
        iVar2 = FUN_007b6480();
        if (iVar2 != 0) {
          return bVar5;
        }
      }
      else if ((pbVar4[1] == 0x2d) && (pbVar3 < param_1)) {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + 2;
        pbVar3 = pbVar3 + 2;
        if (((int)(uint)bVar1 <= (int)unaff_EBX) && ((int)unaff_EBX <= (int)(uint)*pbVar4)) {
          return bVar5;
        }
      }
      else if (*pbVar4 == unaff_EBX) {
        return bVar5;
      }
      pbVar4 = pbVar4 + 1;
      pbVar3 = pbVar3 + 1;
    } while (pbVar4 < param_1);
  }
  return !bVar5;
}


// ==== FUN_007b6630 @ 0x007b6630 ====

char * FUN_007b6630(void)

{
  char *pcVar1;
  char *in_EAX;
  char *in_ECX;
  int unaff_EBX;
  int iVar2;
  
  if ((*in_EAX == '\0') || (in_EAX[1] == '\0')) {
    FUN_007bad90(*(undefined4 *)(unaff_EBX + 8),s_unbalanced_pattern_009fd3fc);
  }
  if (*in_ECX != *in_EAX) {
    return (char *)0x0;
  }
  iVar2 = 1;
  do {
    while( true ) {
      pcVar1 = in_ECX;
      in_ECX = pcVar1 + 1;
      if (*(char **)(unaff_EBX + 4) <= in_ECX) {
        return (char *)0x0;
      }
      if (*in_ECX == in_EAX[1]) break;
      if (*in_ECX == *in_EAX) {
        iVar2 = iVar2 + 1;
      }
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return pcVar1 + 2;
}


// ==== FUN_007b66a0 @ 0x007b66a0 ====

int FUN_007b66a0(int param_1,char *param_2,int param_3)

{
  char cVar1;
  char *in_EAX;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int local_4;
  
  local_4 = 0;
  iVar5 = 0;
  if (param_2 < *(char **)(param_1 + 4)) {
    pcVar4 = param_2;
    do {
      cVar1 = *in_EAX;
      if (cVar1 == '%') {
        uVar2 = FUN_007b6480();
LAB_007b66ff:
        if (uVar2 == 0) break;
      }
      else if (cVar1 != '.') {
        if (cVar1 == '[') {
          uVar2 = FUN_007b6590(param_3 + -1);
        }
        else {
          uVar2 = (uint)(cVar1 == *pcVar4);
        }
        goto LAB_007b66ff;
      }
      local_4 = local_4 + 1;
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 < *(char **)(param_1 + 4));
    iVar5 = local_4;
    if (local_4 < 0) {
      return 0;
    }
  }
  do {
    iVar3 = FUN_007b68f0(param_1,param_2 + iVar5,param_3 + 1);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar5 = iVar5 + -1;
  } while (-1 < iVar5);
  return 0;
}


// ==== FUN_007b6750 @ 0x007b6750 ====

int FUN_007b6750(int param_1,char *param_2,int param_3)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_007b68f0(param_1);
  if (iVar2 == 0) {
    while (in_EAX < *(char **)(param_1 + 4)) {
      cVar1 = *param_2;
      if (cVar1 == '%') {
        uVar3 = FUN_007b6480();
LAB_007b67ba:
        if (uVar3 == 0) break;
      }
      else if (cVar1 != '.') {
        if (cVar1 == '[') {
          uVar3 = FUN_007b6590(param_3 + -1);
        }
        else {
          uVar3 = (uint)(cVar1 == *in_EAX);
        }
        goto LAB_007b67ba;
      }
      in_EAX = in_EAX + 1;
      iVar2 = FUN_007b68f0(param_1,in_EAX,param_3 + 1);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_007b67f0 @ 0x007b67f0 ====

void FUN_007b67f0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_EBX;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0xc);
  if (0x1f < iVar1) {
    FUN_007bad90(*(undefined4 *)(unaff_ESI + 8),s_too_many_captures_009fd410);
  }
  *(undefined4 *)(unaff_ESI + 0x10 + iVar1 * 8) = unaff_EBX;
  *(undefined4 *)(unaff_ESI + 0x14 + iVar1 * 8) = param_2;
  *(int *)(unaff_ESI + 0xc) = iVar1 + 1;
  iVar1 = FUN_007b68f0();
  if (iVar1 == 0) {
    *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 0xc) + -1;
  }
  return;
}


// ==== FUN_007b6840 @ 0x007b6840 ====

void FUN_007b6840(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBX;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0xc) + -1;
  if (-1 < iVar1) {
    piVar3 = (int *)(unaff_ESI + 0x14 + iVar1 * 8);
    do {
      if (*piVar3 == -1) goto LAB_007b686e;
      iVar1 = iVar1 + -1;
      piVar3 = piVar3 + -2;
    } while (-1 < iVar1);
  }
  iVar1 = FUN_007bad90(*(undefined4 *)(unaff_ESI + 8),s_invalid_pattern_capture_009fd3a0);
LAB_007b686e:
  *(int *)(unaff_ESI + 0x14 + iVar1 * 8) = unaff_EBX - *(int *)(unaff_ESI + 0x10 + iVar1 * 8);
  iVar2 = FUN_007b68f0();
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_ESI + 0x14 + iVar1 * 8) = 0xffffffff;
  }
  return;
}


// ==== FUN_007b68a0 @ 0x007b68a0 ====

char * FUN_007b68a0(void)

{
  uint uVar1;
  int in_EAX;
  int iVar2;
  int in_ECX;
  uint uVar3;
  char *unaff_EBX;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  iVar2 = in_EAX + -0x31;
  if (((iVar2 < 0) || (*(int *)(in_ECX + 0xc) <= iVar2)) ||
     (*(int *)(in_ECX + 0x14 + iVar2 * 8) == -1)) {
    iVar2 = FUN_007bad90(*(undefined4 *)(in_ECX + 8),s_invalid_capture_index_009fd388);
  }
  uVar1 = *(uint *)(in_ECX + 0x14 + iVar2 * 8);
  if (uVar1 <= (uint)(*(int *)(in_ECX + 4) - (int)unaff_EBX)) {
    bVar6 = true;
    uVar3 = uVar1;
    pcVar4 = *(char **)(in_ECX + 0x10 + iVar2 * 8);
    pcVar5 = unaff_EBX;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      return unaff_EBX + uVar1;
    }
  }
  return (char *)0x0;
}


// ==== __break @ 0x007b68ee ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_007b68f0 @ 0x007b68f0 ====

char * FUN_007b68f0(int param_1,char *param_2,char *param_3)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  
LAB_007b68f8:
LAB_007b6900:
  switch(*param_3) {
  case '\0':
    return param_2;
  case '$':
    if (param_3[1] == '\0') {
      return (char *)((param_2 != *(char **)(param_1 + 4)) - 1 & (uint)param_2);
    }
  default:
switchD_007b6914_caseD_1:
    pcVar5 = (char *)FUN_007b6410();
    if (param_2 < *(char **)(param_1 + 4)) {
      cVar2 = *param_3;
      if (cVar2 == '%') {
        uVar6 = FUN_007b6480();
LAB_007b6a3f:
        if (uVar6 == 0) goto LAB_007b6a4a;
      }
      else if (cVar2 != '.') {
        if (cVar2 == '[') {
          uVar6 = FUN_007b6590(pcVar5 + -1);
        }
        else {
          uVar6 = (uint)(cVar2 == *param_2);
        }
        goto LAB_007b6a3f;
      }
      bVar3 = true;
    }
    else {
LAB_007b6a4a:
      bVar3 = false;
    }
    switch(*pcVar5) {
    case '*':
      pcVar5 = (char *)FUN_007b66a0(param_1,param_2,pcVar5);
      return pcVar5;
    case '+':
      if (!bVar3) {
        return (char *)0x0;
      }
      pcVar5 = (char *)FUN_007b66a0(param_1,param_2 + 1,pcVar5);
      return pcVar5;
    default:
      if (!bVar3) {
        return (char *)0x0;
      }
      param_2 = param_2 + 1;
      param_3 = pcVar5;
      break;
    case '-':
      pcVar5 = (char *)FUN_007b6750(param_1,param_3,pcVar5);
      return pcVar5;
    case '?':
      if ((bVar3) &&
         (pcVar7 = (char *)FUN_007b68f0(param_1,param_2 + 1,pcVar5 + 1), pcVar7 != (char *)0x0)) {
        return pcVar7;
      }
      param_3 = pcVar5 + 1;
    }
    goto LAB_007b6900;
  case '%':
    break;
  case '(':
    if (param_3[1] == ')') {
      pcVar5 = (char *)FUN_007b67f0(param_3 + 2,0xfffffffe);
      return pcVar5;
    }
    pcVar5 = (char *)FUN_007b67f0(param_3 + 1,0xffffffff);
    return pcVar5;
  case ')':
    pcVar5 = (char *)FUN_007b6840(param_3 + 1);
    return pcVar5;
  }
  bVar1 = param_3[1];
  if (bVar1 == 0x62) goto LAB_007b69bf;
  if (bVar1 != 0x66) {
    iVar4 = _isdigit((uint)bVar1);
    if (iVar4 == 0) goto switchD_007b6914_caseD_1;
    param_2 = (char *)FUN_007b68a0();
    if (param_2 == (char *)0x0) {
      return (char *)0x0;
    }
    param_3 = param_3 + 2;
    goto LAB_007b6900;
  }
  if (param_3[2] != '[') {
    FUN_007bad90(*(undefined4 *)(param_1 + 8),s_missing_____after____f__in_patte_009fd424);
  }
  param_3 = (char *)FUN_007b6410();
  iVar4 = FUN_007b6590(param_3 + -1);
  if ((iVar4 != 0) || (iVar4 = FUN_007b6590(param_3 + -1), iVar4 == 0)) {
    return (char *)0x0;
  }
  goto LAB_007b68f8;
LAB_007b69bf:
  param_2 = (char *)FUN_007b6630();
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  param_3 = param_3 + 4;
  goto LAB_007b6900;
}


// ==== FUN_007b6bb0 @ 0x007b6bb0 ====

char * FUN_007b6bb0(uint param_1,char *param_2,uint param_3)

{
  char *in_EAX;
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char *_MaxCount;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  if (param_3 == 0) {
    return in_EAX;
  }
  if (param_1 < param_3) {
    return (char *)0x0;
  }
  _MaxCount = (char *)(param_1 - (param_3 - 1));
  if (_MaxCount != (char *)0x0) {
    while (pcVar1 = _memchr(in_EAX,(int)*param_2,(size_t)_MaxCount), pcVar1 != (char *)0x0) {
      pcVar2 = pcVar1 + 1;
      bVar6 = true;
      iVar3 = param_3 - 1;
      pcVar4 = pcVar2;
      pcVar5 = param_2;
      do {
        pcVar5 = pcVar5 + 1;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
      } while (bVar6);
      if (bVar6) {
        return pcVar1;
      }
      _MaxCount = in_EAX + ((int)_MaxCount - (int)pcVar2);
      in_EAX = pcVar2;
      if (_MaxCount == (char *)0x0) {
        return (char *)0x0;
      }
    }
  }
  return (char *)0x0;
}


// ==== FUN_007b6c20 @ 0x007b6c20 ====

void FUN_007b6c20(void)

{
  int iVar1;
  int in_EAX;
  int *unaff_ESI;
  
  iVar1 = unaff_ESI[in_EAX * 2 + 5];
  if (iVar1 == -1) {
    FUN_007bad90(unaff_ESI[2],s_unfinished_capture_009fd448);
  }
  else if (iVar1 == -2) {
    FUN_007bc400(unaff_ESI[2],(double)((unaff_ESI[in_EAX * 2 + 4] - *unaff_ESI) + 1));
    return;
  }
  FUN_007bc420(unaff_ESI[2],unaff_ESI[in_EAX * 2 + 4],iVar1);
  return;
}


// ==== FUN_007b6c90 @ 0x007b6c90 ====

int FUN_007b6c90(void)

{
  int in_ECX;
  int *unaff_ESI;
  int *piVar1;
  int local_10;
  
  FUN_007baf50(unaff_ESI[2],unaff_ESI[3],s_too_many_captures_009fd410);
  if ((unaff_ESI[3] == 0) && (in_ECX != 0)) {
    FUN_007bc420(unaff_ESI[2]);
    return 1;
  }
  local_10 = 0;
  if (0 < unaff_ESI[3]) {
    piVar1 = unaff_ESI + 4;
    do {
      if (piVar1[1] == -1) {
        FUN_007bad90(unaff_ESI[2],s_unfinished_capture_009fd448);
LAB_007b6d09:
        FUN_007bc420(unaff_ESI[2]);
      }
      else {
        if (piVar1[1] != -2) goto LAB_007b6d09;
        FUN_007bc400(unaff_ESI[2],(double)((*piVar1 - *unaff_ESI) + 1));
      }
      local_10 = local_10 + 1;
      piVar1 = piVar1 + 2;
    } while (local_10 < unaff_ESI[3]);
  }
  return unaff_ESI[3];
}


// ==== FUN_007b6d60 @ 0x007b6d60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_007b6d60(undefined4 param_1)

{
  char cVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  char *local_128;
  uint local_120;
  int local_11c;
  int local_118;
  uint local_114;
  undefined4 local_110;
  undefined4 local_10c;
  
  iVar3 = FUN_007bbad0(param_1,1,&local_120);
  local_128 = (char *)FUN_007bbad0(param_1,2,&local_11c);
  uVar6 = local_120;
  FUN_007bbc20(param_1,3,_DAT_0099d0a0);
  iVar4 = FUN_00802534();
  if (iVar4 < 0) {
    iVar4 = iVar4 + 1 + uVar6;
  }
  uVar6 = iVar4 - 1;
  if ((int)uVar6 < 0) {
    uVar6 = 0;
  }
  else if (local_120 < uVar6) {
    uVar6 = local_120;
  }
  iVar4 = FUN_007bc1f0(param_1);
  if ((iVar4 == 0) && (pcVar5 = _strpbrk(local_128,s____________009fd45c), pcVar5 != (char *)0x0)) {
    cVar1 = *local_128;
    if (cVar1 == '^') {
      local_128 = local_128 + 1;
    }
    local_114 = local_120 + iVar3;
    local_110 = param_1;
    uVar6 = uVar6 + iVar3;
    local_118 = iVar3;
    do {
      local_10c = 0;
      iVar4 = FUN_007b68f0(&local_118,uVar6,local_128);
      if (iVar4 != 0) {
        FUN_007bc400(param_1,(double)(int)((uVar6 - iVar3) + 1));
        FUN_007bc400(param_1,(double)(iVar4 - iVar3));
        iVar4 = FUN_007b6c90();
        return iVar4 + 2;
      }
    } while ((uVar6 < local_114) && (uVar6 = uVar6 + 1, cVar1 != '^'));
  }
  else {
    iVar4 = FUN_007b6bb0(local_120 - uVar6,local_128,local_11c);
    if (iVar4 != 0) {
      FUN_007bc400(param_1,(double)((iVar4 - iVar3) + 1));
      local_11c = (iVar4 - iVar3) + local_11c;
      dVar2 = (double)local_11c;
      if (local_11c < 0) {
        dVar2 = dVar2 + _DAT_009c2f50;
      }
      FUN_007bc400(param_1,dVar2);
      return 2;
    }
  }
  FUN_007bc3e0();
  return 1;
}


// ==== FUN_007b7030 @ 0x007b7030 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b7030(undefined4 param_1)

{
  FUN_007bbad0(param_1,1,0);
  FUN_007bbad0(param_1,2,0);
  FUN_007bbdf0(param_1,2);
  FUN_007bc400(param_1,_DAT_0099d098);
  FUN_007bc540(param_1,&LAB_007b6f40,3);
  return 1;
}


// ==== FUN_007b7080 @ 0x007b7080 ====

void FUN_007b7080(void)

{
  undefined4 uVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *unaff_EBX;
  uint uVar6;
  
  uVar1 = *(undefined4 *)(in_EAX + 8);
  iVar2 = FUN_007bc080(uVar1,3);
  if (iVar2 != 0) {
    iVar2 = FUN_007bc230(uVar1,3);
    uVar3 = FUN_007bc2a0(uVar1,3);
    uVar6 = 0;
    if (uVar3 != 0) {
      do {
        if (*(char *)(uVar6 + iVar2) == '%') {
          iVar4 = uVar6 + 1;
          uVar6 = uVar6 + 1;
          iVar4 = _isdigit((uint)*(byte *)(iVar4 + iVar2));
          if (iVar4 == 0) {
            if (unaff_EBX + 0x83 <= (int *)*unaff_EBX) {
              FUN_007bb420();
            }
            *(undefined1 *)*unaff_EBX = *(undefined1 *)(uVar6 + iVar2);
            *unaff_EBX = *unaff_EBX + 1;
          }
          else {
            iVar4 = *(char *)(uVar6 + iVar2) + -0x31;
            if (((iVar4 < 0) || (*(int *)(in_EAX + 0xc) <= iVar4)) ||
               (*(int *)(in_EAX + 0x14 + iVar4 * 8) == -1)) {
              FUN_007bad90(*(undefined4 *)(in_EAX + 8),s_invalid_capture_index_009fd388);
            }
            FUN_007b6c20();
            FUN_007bb510();
          }
        }
        else {
          if (unaff_EBX + 0x83 <= (int *)*unaff_EBX) {
            FUN_007bb420();
          }
          *(undefined1 *)*unaff_EBX = *(undefined1 *)(uVar6 + iVar2);
          *unaff_EBX = *unaff_EBX + 1;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar3);
    }
    return;
  }
  FUN_007bbf60(uVar1,3);
  uVar5 = FUN_007b6c90();
  FUN_007bc9f0(uVar1,uVar5,1);
  iVar2 = FUN_007bc080(uVar1,0xffffffff);
  if (iVar2 == 0) {
    FUN_007bbdf0(uVar1,0xfffffffe);
    return;
  }
  FUN_007bb510();
  return;
}


// ==== FUN_007b71b0 @ 0x007b71b0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b71b0(undefined4 param_1)

{
  char cVar1;
  double dVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int local_334;
  char *local_328;
  int local_324;
  undefined1 *local_320;
  undefined1 *local_31c;
  undefined4 local_318;
  undefined4 local_314;
  undefined4 *local_210 [131];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  puVar3 = (undefined1 *)FUN_007bbad0(param_1,1,&local_324);
  local_328 = (char *)FUN_007bbad0(param_1,2,0);
  dVar2 = (double)(local_324 + 1);
  if (local_324 + 1 < 0) {
    dVar2 = dVar2 + _DAT_009c2f50;
  }
  FUN_007bbc20(param_1,4,dVar2);
  iVar4 = FUN_00802534();
  cVar1 = *local_328;
  if (cVar1 == '^') {
    local_328 = local_328 + 1;
  }
  local_334 = 0;
  iVar5 = FUN_007bbde0();
  if ((iVar5 < 3) ||
     ((iVar5 = FUN_007bc080(param_1,3), iVar5 == 0 && (iVar5 = FUN_007bbfa0(param_1,3), iVar5 != 6))
     )) {
    FUN_007bb990(param_1,3,s_string_or_function_expected_009fd468);
  }
  FUN_007bb5b0(param_1,local_210);
  local_31c = puVar3 + local_324;
  local_318 = param_1;
  local_320 = puVar3;
  if (iVar4 < 1) {
LAB_007b7346:
    FUN_007bb460(local_210,puVar3,(int)local_31c - (int)puVar3);
    FUN_007bb4c0(local_210);
    FUN_007bc400(param_1,(double)local_334);
    return 2;
  }
  do {
    local_314 = 0;
    puVar6 = (undefined1 *)FUN_007b68f0(&local_320,puVar3,local_328);
    if (puVar6 == (undefined1 *)0x0) {
LAB_007b72ef:
      if (local_31c <= puVar3) goto LAB_007b7346;
      if (&local_4 <= local_210[0]) {
        FUN_007bb420();
      }
      *(undefined1 *)local_210[0] = *puVar3;
      local_210[0] = (undefined4 *)((int)local_210[0] + 1);
      puVar6 = puVar3 + 1;
    }
    else {
      local_334 = local_334 + 1;
      FUN_007b7080();
      if (puVar6 <= puVar3) goto LAB_007b72ef;
    }
    puVar3 = puVar6;
    if ((cVar1 == '^') || (iVar4 <= local_334)) goto LAB_007b7346;
  } while( true );
}


// ==== FUN_007b73a0 @ 0x007b73a0 ====

void FUN_007b73a0(void)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  int in_ECX;
  int *unaff_ESI;
  
  puVar3 = (undefined1 *)FUN_007bbad0();
  piVar1 = unaff_ESI + 0x83;
  if (piVar1 <= (int *)*unaff_ESI) {
    FUN_007bb420();
  }
  *(undefined1 *)*unaff_ESI = 0x22;
  *unaff_ESI = *unaff_ESI + 1;
  do {
    if (in_ECX == 0) {
      if (piVar1 <= (int *)*unaff_ESI) {
        FUN_007bb420();
      }
      *(undefined1 *)*unaff_ESI = 0x22;
      *unaff_ESI = *unaff_ESI + 1;
      return;
    }
    in_ECX = in_ECX + -1;
    switch(*puVar3) {
    case 0:
      FUN_007bb460();
      goto LAB_007b744f;
    default:
      if (piVar1 <= (int *)*unaff_ESI) {
        FUN_007bb420();
      }
      *(undefined1 *)*unaff_ESI = *puVar3;
      break;
    case 10:
    case 0x22:
    case 0x5c:
      if (piVar1 <= (int *)*unaff_ESI) {
        FUN_007bb420();
      }
      *(undefined1 *)*unaff_ESI = 0x5c;
      iVar2 = *unaff_ESI;
      *unaff_ESI = iVar2 + 1;
      if (piVar1 <= (int *)(iVar2 + 1)) {
        FUN_007bb420();
      }
      *(undefined1 *)*unaff_ESI = *puVar3;
    }
    *unaff_ESI = *unaff_ESI + 1;
LAB_007b744f:
    puVar3 = puVar3 + 1;
  } while( true );
}


// ==== FUN_007b74f0 @ 0x007b74f0 ====

byte * FUN_007b74f0(undefined4 param_1,undefined1 *param_2,undefined4 *param_3)

{
  byte *pbVar1;
  char *pcVar2;
  int iVar3;
  byte *unaff_EBX;
  byte *pbVar4;
  
  pcVar2 = _strchr(s_____0_009fd4d8,(int)(char)*unaff_EBX);
  pbVar4 = unaff_EBX;
  while (pcVar2 != (char *)0x0) {
    pbVar1 = pbVar4 + 1;
    pbVar4 = pbVar4 + 1;
    pcVar2 = _strchr(s_____0_009fd4d8,(int)(char)*pbVar1);
  }
  iVar3 = _isdigit((uint)*pbVar4);
  if (iVar3 != 0) {
    pbVar4 = pbVar4 + 1;
  }
  iVar3 = _isdigit((uint)*pbVar4);
  if (iVar3 != 0) {
    pbVar4 = pbVar4 + 1;
  }
  if (*pbVar4 == 0x2e) {
    *param_3 = 1;
    iVar3 = _isdigit((uint)pbVar4[1]);
    pbVar1 = pbVar4 + 1;
    if (iVar3 != 0) {
      pbVar1 = pbVar4 + 2;
    }
    pbVar4 = pbVar1;
    iVar3 = _isdigit((uint)*pbVar4);
    if (iVar3 != 0) {
      pbVar4 = pbVar4 + 1;
    }
  }
  iVar3 = _isdigit((uint)*pbVar4);
  if (iVar3 != 0) {
    FUN_007bad90(param_1,s_invalid_format__width_or_precisi_009fd4a8);
  }
  if (0x14 < (int)(pbVar4 + (2 - (int)unaff_EBX))) {
    FUN_007bad90(param_1,s_invalid_format__too_long__009fd48c);
  }
  *param_2 = 0x25;
  _strncpy(param_2 + 1,(char *)unaff_EBX,(size_t)(pbVar4 + (1 - (int)unaff_EBX)));
  param_2[(int)(pbVar4 + (2 - (int)unaff_EBX))] = 0;
  return pbVar4;
}


// ==== FUN_007b75e0 @ 0x007b75e0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b75e0(undefined4 param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  float10 fVar9;
  int local_43c;
  uint local_438;
  char local_434 [20];
  char *local_420 [131];
  char local_214 [4];
  char local_210 [516];
  undefined4 local_c;
  
  local_c = DAT_00b49670;
  iVar8 = 1;
  pcVar2 = (char *)FUN_007bbad0(param_1,1);
  pcVar7 = pcVar2 + local_43c;
  FUN_007bb5b0(param_1,local_420);
joined_r0x007b762f:
  while( true ) {
    while( true ) {
      if (pcVar7 <= pcVar2) {
        FUN_007bb4c0();
        return 1;
      }
      if (*pcVar2 == '%') break;
      if (local_214 <= local_420[0]) {
        FUN_007bb420();
      }
      *local_420[0] = *pcVar2;
      local_420[0] = local_420[0] + 1;
      pcVar2 = pcVar2 + 1;
    }
    if (pcVar2[1] != 0x25) break;
    if (local_214 <= local_420[0]) {
      FUN_007bb420();
    }
    *local_420[0] = pcVar2[1];
    local_420[0] = local_420[0] + 1;
    pcVar2 = pcVar2 + 2;
  }
  iVar3 = _isdigit((uint)(byte)pcVar2[1]);
  if ((iVar3 != 0) && (pcVar2[2] == '$')) {
    uVar6 = FUN_007bad90(param_1,s_obsolete_option__d___to__format__009fd4fc);
    return uVar6;
  }
  iVar8 = iVar8 + 1;
  puVar4 = (undefined1 *)FUN_007b74f0(param_1,local_434);
  pcVar2 = puVar4 + 1;
  switch(*puVar4) {
  case 0x45:
  case 0x47:
  case 0x65:
  case 0x66:
  case 0x67:
    fVar9 = (float10)FUN_007bbba0(param_1,iVar8);
    _sprintf(local_210,local_434,(double)fVar9);
    break;
  default:
    uVar6 = FUN_007bad90(param_1,s_invalid_option_to__format__009fd4e0);
    return uVar6;
  case 0x58:
  case 0x6f:
  case 0x75:
  case 0x78:
    FUN_007bbba0(param_1);
    uVar6 = FUN_00802534();
    _sprintf(local_210,local_434,uVar6);
    break;
  case 99:
  case 100:
  case 0x69:
    FUN_007bbba0(param_1);
    uVar6 = FUN_00802534();
    _sprintf(local_210,local_434,uVar6);
    break;
  case 0x71:
    FUN_007b73a0();
    goto joined_r0x007b762f;
  case 0x73:
    FUN_007bbad0(param_1,iVar8);
    if (local_438 < 100) {
      _sprintf(local_210,local_434);
      break;
    }
    FUN_007bbf60(param_1);
    FUN_007bb510(local_420);
    goto joined_r0x007b762f;
  }
  pcVar5 = local_210;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_007bb460(local_420,local_210);
  goto joined_r0x007b762f;
}


// ==== FUN_007b78b0 @ 0x007b78b0 ====

undefined4 FUN_007b78b0(undefined4 param_1)

{
  FUN_007bb040(param_1,s_string_009fd520,&PTR_DAT_009fd290,0);
  return 1;
}


// ==== FUN_007b78d0 @ 0x007b78d0 ====

undefined4 FUN_007b78d0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int unaff_EDI;
  
  if (in_EAX != 0) {
    FUN_007bc5d0();
    return 1;
  }
  FUN_007bc3e0();
  puVar1 = (undefined4 *)FUN_00804b94();
  if (unaff_EDI == 0) {
    _strerror((char *)*puVar1);
    FUN_007bc510();
  }
  else {
    _strerror((char *)*puVar1);
    FUN_007bc510();
  }
  FUN_00804b94();
  FUN_007bc400();
  return 3;
}


// ==== FUN_007b7950 @ 0x007b7950 ====

undefined4 FUN_007b7950(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_007baec0(param_1,1,s_FILE__009fd79c);
  if (piVar1 == (int *)0x0) {
    FUN_007bc3e0(param_1);
    return 1;
  }
  if (*piVar1 == 0) {
    FUN_007bc420(param_1,s_closed_file_009fd7ac,0xb);
    return 1;
  }
  FUN_007bc420(param_1,&DAT_009fd7a4,4);
  return 1;
}


// ==== FUN_007b79b0 @ 0x007b79b0 ====

int FUN_007b79b0(void)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_007baec0();
  if (piVar1 == (int *)0x0) {
    FUN_007bb990();
  }
  if (*piVar1 == 0) {
    FUN_007bad90();
  }
  return *piVar1;
}


// ==== FUN_007b79f0 @ 0x007b79f0 ====

void FUN_007b79f0(undefined4 param_1)

{
  undefined4 *puVar1;
  int unaff_EBX;
  
  FUN_007bc470();
  puVar1 = (undefined4 *)FUN_007bcc80();
  *puVar1 = 0;
  FUN_007baea0();
  FUN_007bc910();
  *puVar1 = param_1;
  if (unaff_EBX != 0) {
    FUN_007bc470();
    FUN_007bbf60();
    FUN_007bc810();
  }
  FUN_007bc810();
  return;
}


// ==== FUN_007b7a50 @ 0x007b7a50 ====

undefined4 FUN_007b7a50(void)

{
  FILE *_File;
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  piVar1 = (int *)FUN_007baec0();
  if (piVar1 == (int *)0x0) {
    FUN_007bb990();
  }
  if (*piVar1 == 0) {
    FUN_007bad90();
  }
  _File = (FILE *)*piVar1;
  if (((_File == (FILE *)&PTR_DAT_00b49680) || (_File == (FILE *)&DAT_00b496a0)) ||
     (_File == (FILE *)&DAT_00b496c0)) {
    return 0;
  }
  iVar2 = _fclose(_File);
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)FUN_007bc300();
    *puVar3 = 0;
    return 1;
  }
  return 0;
}


// ==== FUN_007b7ae0 @ 0x007b7ae0 ====

undefined4 FUN_007b7ae0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int *piVar4;
  
  iVar1 = FUN_007bbfa0(param_1);
  if (iVar1 == -1) {
    FUN_007bc470(param_1);
    FUN_007bc670(param_1,0xffffd8ee);
  }
  iVar1 = FUN_007b7a50();
  if (iVar1 == 0) {
    FUN_007bc3e0();
    puVar2 = (undefined4 *)FUN_00804b94();
    pcVar3 = _strerror((char *)*puVar2);
    FUN_007bc510(param_1,&DAT_009d5e14,pcVar3);
    piVar4 = (int *)FUN_00804b94();
    FUN_007bc400(param_1,(double)*piVar4);
    return 3;
  }
  FUN_007bc5d0(param_1,1);
  return 1;
}


// ==== FUN_007b7b70 @ 0x007b7b70 ====

undefined4 FUN_007b7b70(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_007baec0(param_1,1,s_FILE__009fd79c);
  if (piVar1 == (int *)0x0) {
    FUN_007bb990(param_1,1,s_bad_file_009fd790);
  }
  if (*piVar1 != 0) {
    FUN_007b7a50();
  }
  return 0;
}


// ==== FUN_007b7bb0 @ 0x007b7bb0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b7bb0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  char local_24 [4];
  char local_20 [2];
  char local_1e;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  piVar1 = (int *)FUN_007baec0(param_1,1,s_FILE__009fd79c);
  if (piVar1 == (int *)0x0) {
    FUN_007bb990(param_1,1,s_bad_file_009fd790);
  }
  if (*piVar1 == 0) {
    local_24[0] = s_closed_009fd7f0[0];
    local_24[1] = s_closed_009fd7f0[1];
    local_24[2] = s_closed_009fd7f0[2];
    local_24[3] = s_closed_009fd7f0[3];
    local_20[0] = s_closed_009fd7f0[4];
    local_20[1] = s_closed_009fd7f0[5];
    local_1e = s_closed_009fd7f0[6];
  }
  else {
    uVar2 = FUN_007bc300(param_1,1);
    _sprintf(local_24,&DAT_009fd7ec,uVar2);
  }
  FUN_007bc510(param_1,s_file___s__009fd7e0,local_24);
  return 1;
}


// ==== FUN_007b7c50 @ 0x007b7c50 ====

undefined4 FUN_007b7c50(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  
  iVar1 = FUN_007bbad0(param_1,1);
  uVar2 = FUN_007bbb40(param_1,2,&DAT_009fd7f8,0);
  piVar3 = (int *)FUN_007bcc80(param_1,4);
  *piVar3 = 0;
  FUN_007baea0(param_1,s_FILE__009fd79c);
  FUN_007bc910(param_1,0xfffffffe);
  iVar4 = FUN_00803b27(iVar1,uVar2);
  *piVar3 = iVar4;
  if (iVar4 != 0) {
    return 1;
  }
  FUN_007bc3e0();
  puVar5 = (undefined4 *)FUN_00804b94();
  if (iVar1 == 0) {
    pcVar6 = _strerror((char *)*puVar5);
    FUN_007bc510(param_1,&DAT_009d5e14,pcVar6);
  }
  else {
    pcVar6 = _strerror((char *)*puVar5);
    FUN_007bc510(param_1,s__s___s_009fd788,iVar1,pcVar6);
  }
  piVar3 = (int *)FUN_00804b94();
  FUN_007bc400(param_1,(double)*piVar3);
  return 3;
}


// ==== FUN_007b7d20 @ 0x007b7d20 ====

undefined4 FUN_007b7d20(undefined4 param_1)

{
  FUN_007bad90(param_1,s__popen__not_supported_009fd7fc);
  return 0;
}


// ==== FUN_007b7d40 @ 0x007b7d40 ====

undefined4 FUN_007b7d40(undefined4 param_1)

{
  undefined4 *puVar1;
  FILE *pFVar2;
  char *pcVar3;
  int *piVar4;
  
  puVar1 = (undefined4 *)FUN_007bcc80(param_1);
  *puVar1 = 0;
  FUN_007baea0(param_1,s_FILE__009fd79c);
  FUN_007bc910(param_1,0xfffffffe);
  pFVar2 = _tmpfile();
  *puVar1 = pFVar2;
  if (pFVar2 == (FILE *)0x0) {
    FUN_007bc3e0();
    puVar1 = (undefined4 *)FUN_00804b94();
    pcVar3 = _strerror((char *)*puVar1);
    FUN_007bc510(param_1,&DAT_009d5e14,pcVar3);
    piVar4 = (int *)FUN_00804b94();
    FUN_007bc400(param_1,(double)*piVar4);
    return 3;
  }
  return 1;
}


// ==== FUN_007b7dc0 @ 0x007b7dc0 ====

undefined4 FUN_007b7dc0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_007bbfa0();
  if (0 < iVar1) {
    iVar1 = FUN_007bc230();
    FUN_007bc470();
    if (iVar1 == 0) {
      FUN_007b79b0();
      FUN_007bbf60();
    }
    else {
      piVar2 = (int *)FUN_007bcc80();
      *piVar2 = 0;
      FUN_007baea0();
      FUN_007bc910();
      iVar1 = FUN_00803b27(iVar1,param_2);
      *piVar2 = iVar1;
      if (iVar1 == 0) {
        puVar3 = (undefined4 *)FUN_00804b94();
        _strerror((char *)*puVar3);
        FUN_007bc510();
        FUN_007bc230();
        FUN_007bb990();
      }
    }
    FUN_007bc850();
  }
  FUN_007bc470();
  FUN_007bc670();
  return 1;
}


// ==== FUN_007b7ea0 @ 0x007b7ea0 ====

void FUN_007b7ea0(void)

{
  FUN_007b7dc0(s__input_009fd814,&DAT_009fd7f8);
  return;
}


// ==== FUN_007b7ec0 @ 0x007b7ec0 ====

void FUN_007b7ec0(void)

{
  FUN_007b7dc0(s__output_009fd7d8,&DAT_009fd81c);
  return;
}


// ==== FUN_007b7ee0 @ 0x007b7ee0 ====

undefined4 FUN_007b7ee0(undefined4 param_1)

{
  int iVar1;
  FILE *in_ECX;
  undefined8 local_8;
  
  iVar1 = FID_conflict__fscanf(in_ECX,(wchar_t *)&DAT_009fd820);
  if (iVar1 == 1) {
    FUN_007bc400(param_1,local_8);
    return 1;
  }
  return 0;
}


// ==== FUN_007b7f20 @ 0x007b7f20 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_007b7f20(undefined4 param_1)

{
  char cVar1;
  char *_Buf;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  FILE *unaff_EDI;
  char *local_210 [131];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  FUN_007bb5b0(param_1,local_210);
  _Buf = (char *)FUN_007bb420(local_210);
  pcVar2 = _fgets(_Buf,0x200,unaff_EDI);
  while( true ) {
    if (pcVar2 == (char *)0x0) {
      FUN_007bb4c0(local_210);
      iVar4 = FUN_007bc2a0(param_1,0xffffffff);
      return iVar4 != 0;
    }
    pcVar2 = _Buf + 1;
    pcVar3 = _Buf;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (_Buf[(int)(pcVar3 + (-1 - (int)pcVar2))] == '\n') break;
    local_210[0] = pcVar3 + ((int)local_210[0] - (int)pcVar2);
    _Buf = (char *)FUN_007bb420(local_210);
    pcVar2 = _fgets(_Buf,0x200,unaff_EDI);
  }
  local_210[0] = pcVar3 + (int)(local_210[0] + (-1 - (int)pcVar2));
  FUN_007bb4c0(local_210);
  return true;
}


// ==== FUN_007b8010 @ 0x007b8010 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b8010(undefined4 param_1)

{
  void *_DstBuf;
  size_t sVar1;
  int iVar2;
  uint in_ECX;
  FILE *unaff_EBX;
  uint _Count;
  int local_210 [131];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  FUN_007bb5b0(param_1,local_210);
  _Count = 0x200;
  do {
    _DstBuf = (void *)FUN_007bb420(local_210);
    if (in_ECX < _Count) {
      _Count = in_ECX;
    }
    sVar1 = _fread(_DstBuf,1,_Count,unaff_EBX);
    local_210[0] = local_210[0] + sVar1;
    in_ECX = in_ECX - sVar1;
  } while ((in_ECX != 0) && (sVar1 == _Count));
  FUN_007bb4c0(local_210);
  if (in_ECX != 0) {
    iVar2 = FUN_007bc2a0(param_1,0xffffffff);
    if (iVar2 == 0) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_007b80d0 @ 0x007b80d0 ====

int FUN_007b80d0(int param_1)

{
  FILE *in_EAX;
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  iVar1 = FUN_007bbde0();
  iVar1 = iVar1 + -1;
  if (iVar1 == 0) {
    uVar2 = FUN_007b7f20();
    iVar5 = param_1 + 1;
  }
  else {
    FUN_007baf50();
    uVar2 = 1;
    iVar5 = param_1;
    do {
      iVar1 = iVar1 + -1;
      if (uVar2 == 0) goto LAB_007b80f8;
      iVar3 = FUN_007bbfa0();
      if (iVar3 == 3) {
        FUN_007bc1a0();
        iVar3 = FUN_00802534();
        if (iVar3 == 0) {
          iVar3 = FID_conflict__getc(in_EAX);
          _ungetc(iVar3,in_EAX);
          FUN_007bc420();
          uVar2 = (uint)(iVar3 != -1);
        }
        else {
          uVar2 = FUN_007b8010();
        }
      }
      else {
        pcVar4 = (char *)FUN_007bc230();
        if ((pcVar4 == (char *)0x0) || (*pcVar4 != '*')) {
          FUN_007bb990();
        }
        switch(pcVar4[1]) {
        case 'a':
          FUN_007b8010();
          uVar2 = 1;
          break;
        default:
          iVar1 = FUN_007bb990();
          return iVar1;
        case 'l':
          uVar2 = FUN_007b7f20();
          break;
        case 'n':
          uVar2 = FUN_007b7ee0();
          break;
        case 'w':
          iVar1 = FUN_007bad90();
          return iVar1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar1 != 0);
  }
  if (uVar2 == 0) {
LAB_007b80f8:
    FUN_007bbdf0();
    FUN_007bc3e0();
  }
  return iVar5 - param_1;
}


// ==== FUN_007b8260 @ 0x007b8260 ====

void FUN_007b8260(undefined4 param_1)

{
  int *piVar1;
  
  FUN_007bc470(param_1,s__input_009fd814);
  FUN_007bc670(param_1,0xffffd8ee);
  piVar1 = (int *)FUN_007baec0(param_1,0xffffffff,s_FILE__009fd79c);
  if (piVar1 == (int *)0x0) {
    FUN_007bb990(param_1,0xffffffff,s_bad_file_009fd790);
  }
  if (*piVar1 == 0) {
    FUN_007bad90(param_1,s_attempt_to_use_a_closed_file_009fd7b8);
  }
  FUN_007b80d0(1);
  return;
}


// ==== FUN_007b82d0 @ 0x007b82d0 ====

void FUN_007b82d0(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_007baec0(param_1,1,s_FILE__009fd79c);
  if (piVar1 == (int *)0x0) {
    FUN_007bb990(param_1,1,s_bad_file_009fd790);
  }
  if (*piVar1 == 0) {
    FUN_007bad90(param_1,s_attempt_to_use_a_closed_file_009fd7b8);
  }
  FUN_007b80d0(2);
  return;
}


// ==== FUN_007b8320 @ 0x007b8320 ====

undefined4 FUN_007b8320(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_007bc300(param_1,0xffffd8ed);
  if (*piVar1 == 0) {
    FUN_007bad90(param_1,s_file_is_already_closed_009fd868);
  }
  iVar2 = FUN_007b7f20(param_1);
  if (iVar2 != 0) {
    return 1;
  }
  iVar2 = FUN_007bc1f0(param_1,0xffffd8ec);
  if (iVar2 != 0) {
    FUN_007bbdf0(param_1,0);
    FUN_007bbf60(param_1,0xffffd8ed);
    FUN_007b7a50();
  }
  return 0;
}


// ==== FUN_007b83a0 @ 0x007b83a0 ====

undefined4 FUN_007b83a0(FILE *param_1)

{
  bool bVar1;
  int iVar2;
  void *_Str;
  size_t sVar3;
  undefined4 *puVar4;
  float10 fVar5;
  size_t local_10;
  int local_c;
  
  local_c = FUN_007bbde0();
  local_c = local_c + -1;
  bVar1 = true;
  if (local_c != 0) {
    do {
      iVar2 = FUN_007bbfa0();
      if (iVar2 == 3) {
        if (bVar1) {
          fVar5 = (float10)FUN_007bc1a0();
          iVar2 = FID_conflict__fwprintf(param_1,(wchar_t *)s___14g_009fd880,(double)fVar5);
          if (0 < iVar2) goto LAB_007b844b;
        }
LAB_007b83f4:
        bVar1 = false;
      }
      else {
        _Str = (void *)FUN_007bbad0();
        if ((!bVar1) || (sVar3 = _fwrite(_Str,1,local_10,param_1), sVar3 != local_10))
        goto LAB_007b83f4;
LAB_007b844b:
        bVar1 = true;
      }
      local_c = local_c + -1;
    } while (local_c != 0);
    if (!bVar1) {
      FUN_007bc3e0();
      puVar4 = (undefined4 *)FUN_00804b94();
      _strerror((char *)*puVar4);
      FUN_007bc510();
      FUN_00804b94();
      FUN_007bc400();
      return 3;
    }
  }
  FUN_007bc5d0();
  return 1;
}


// ==== FUN_007b84a0 @ 0x007b84a0 ====

void FUN_007b84a0(undefined4 param_1)

{
  int *piVar1;
  
  FUN_007bc470(param_1,s__output_009fd7d8);
  FUN_007bc670(param_1,0xffffd8ee);
  piVar1 = (int *)FUN_007baec0(param_1,0xffffffff,s_FILE__009fd79c);
  if (piVar1 == (int *)0x0) {
    FUN_007bb990(param_1,0xffffffff,s_bad_file_009fd790);
  }
  if (*piVar1 == 0) {
    FUN_007bad90(param_1,s_attempt_to_use_a_closed_file_009fd7b8);
  }
  FUN_007b83a0(*piVar1);
  return;
}


// ==== FUN_007b8510 @ 0x007b8510 ====

void FUN_007b8510(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_007baec0(param_1,1,s_FILE__009fd79c);
  if (piVar1 == (int *)0x0) {
    FUN_007bb990(param_1,1,s_bad_file_009fd790);
  }
  if (*piVar1 == 0) {
    FUN_007bad90(param_1,s_attempt_to_use_a_closed_file_009fd7b8);
  }
  FUN_007b83a0(*piVar1);
  return;
}


// ==== FUN_007b8570 @ 0x007b8570 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b8570(undefined4 param_1)

{
  FILE *_File;
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  undefined4 *puVar5;
  char *pcVar6;
  
  piVar1 = (int *)FUN_007baec0(param_1,1,s_FILE__009fd79c);
  if (piVar1 == (int *)0x0) {
    FUN_007bb990(param_1,1,s_bad_file_009fd790);
  }
  if (*piVar1 == 0) {
    FUN_007bad90(param_1,s_attempt_to_use_a_closed_file_009fd7b8);
  }
  _File = (FILE *)*piVar1;
  uVar2 = FUN_007bbb40(param_1,2,&DAT_009fd780,0,&PTR_DAT_009fd534);
  iVar3 = FUN_007badc0(uVar2);
  FUN_007bbc20(param_1,3,_DAT_0099d098);
  lVar4 = FUN_00802534();
  if (iVar3 == -1) {
    FUN_007bb990(param_1,2);
  }
  iVar3 = _fseek(_File,lVar4,*(int *)(&DAT_009fd528 + iVar3 * 4));
  if (iVar3 == 0) {
    lVar4 = _ftell(_File);
    FUN_007bc400(param_1,(double)lVar4);
    return 1;
  }
  FUN_007bc3e0();
  puVar5 = (undefined4 *)FUN_00804b94();
  pcVar6 = _strerror((char *)*puVar5);
  FUN_007bc510(param_1,&DAT_009d5e14,pcVar6);
  piVar1 = (int *)FUN_00804b94();
  FUN_007bc400(param_1,(double)*piVar1);
  return 3;
}


// ==== FUN_007b8680 @ 0x007b8680 ====

undefined4 FUN_007b8680(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  
  FUN_007bc470(param_1);
  FUN_007bc670(param_1,0xffffd8ee);
  piVar1 = (int *)FUN_007baec0(param_1,0xffffffff,s_FILE__009fd79c);
  if (piVar1 == (int *)0x0) {
    FUN_007bb990(param_1,0xffffffff);
  }
  if (*piVar1 == 0) {
    FUN_007bad90(param_1);
  }
  iVar2 = _fflush((FILE *)*piVar1);
  if (iVar2 == 0) {
    FUN_007bc5d0(param_1,1);
    return 1;
  }
  FUN_007bc3e0();
  puVar3 = (undefined4 *)FUN_00804b94();
  pcVar4 = _strerror((char *)*puVar3);
  FUN_007bc510(param_1,&DAT_009d5e14,pcVar4);
  piVar1 = (int *)FUN_00804b94();
  FUN_007bc400(param_1,(double)*piVar1);
  return 3;
}


// ==== FUN_007b8740 @ 0x007b8740 ====

undefined4 FUN_007b8740(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  
  piVar1 = (int *)FUN_007baec0(param_1,1);
  if (piVar1 == (int *)0x0) {
    FUN_007bb990(param_1,1);
  }
  if (*piVar1 == 0) {
    FUN_007bad90(param_1);
  }
  iVar2 = _fflush((FILE *)*piVar1);
  if (iVar2 == 0) {
    FUN_007bc5d0(param_1,1);
    return 1;
  }
  FUN_007bc3e0();
  puVar3 = (undefined4 *)FUN_00804b94();
  pcVar4 = _strerror((char *)*puVar3);
  FUN_007bc510(param_1,&DAT_009d5e14,pcVar4);
  piVar1 = (int *)FUN_00804b94();
  FUN_007bc400(param_1,(double)*piVar1);
  return 3;
}


// ==== FUN_007b87e0 @ 0x007b87e0 ====

undefined4 FUN_007b87e0(undefined4 param_1)

{
  char *_Command;
  int iVar1;
  
  _Command = (char *)FUN_007bbad0(param_1,1,0);
  iVar1 = FID_conflict___wsystem(_Command);
  FUN_007bc400(param_1,(double)iVar1);
  return 1;
}


// ==== FUN_007b8820 @ 0x007b8820 ====

void FUN_007b8820(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_007bbad0(param_1,1,0);
  FUN_0080579c(uVar1);
  FUN_007b78d0();
  return;
}


// ==== FUN_007b8850 @ 0x007b8850 ====

void FUN_007b8850(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_007bbad0(param_1,1,0);
  uVar2 = FUN_007bbad0(param_1,2,0);
  FUN_008057c6(uVar1,uVar2);
  FUN_007b78d0();
  return;
}


// ==== FUN_007b8890 @ 0x007b8890 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007b8890(undefined4 param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  char local_14 [16];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  pcVar1 = _tmpnam(local_14);
  if (pcVar1 == local_14) {
    FUN_007bc470(param_1,local_14);
    return 1;
  }
  uVar2 = FUN_007bad90(param_1,s_unable_to_generate_a_unique_file_009fd8a0);
  return uVar2;
}


// ==== FUN_007b8900 @ 0x007b8900 ====

undefined4 FUN_007b8900(undefined4 param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)FUN_007bbad0(param_1,1,0);
  pcVar1 = _getenv(pcVar1);
  FUN_007bc470(param_1,pcVar1);
  return 1;
}


// ==== FUN_007b8930 @ 0x007b8930 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b8930(undefined4 param_1)

{
  clock_t cVar1;
  
  cVar1 = _clock();
  FUN_007bc400(param_1,(double)cVar1 * _DAT_009fa718);
  return 1;
}


// ==== FUN_007b8960 @ 0x007b8960 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b8960(undefined4 param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  char *local_11c;
  tm *local_118;
  int local_114;
  char local_110 [260];
  undefined4 local_c;
  
  local_c = DAT_00b49670;
  local_11c = (char *)FUN_007bbb40(param_1,1,&DAT_009fd94c,0);
  FUN_007bbc20(param_1,2,_DAT_009fd350);
  local_114 = FUN_00802534();
  if (local_114 == -1) {
    local_114 = FID_conflict___time32((__time32_t *)0x0);
  }
  if (*local_11c == '!') {
    local_118 = _gmtime((time_t *)&local_114);
    local_11c = local_11c + 1;
  }
  else {
    local_118 = _localtime((time_t *)&local_114);
  }
  if (local_118 == (tm *)0x0) {
    FUN_007bc3e0();
    return 1;
  }
  iVar3 = 3;
  bVar6 = true;
  pcVar4 = local_11c;
  pcVar5 = &DAT_009fd948;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    FUN_007bc710();
    iVar3 = local_118->tm_sec;
    FUN_007bc470(param_1,&PTR_LAB_009fd944);
    FUN_007bc400(param_1,(double)iVar3);
    FUN_007bc850(param_1,0xfffffffd);
    iVar3 = local_118->tm_min;
    FUN_007bc470(param_1,&DAT_009fd1c4);
    FUN_007bc400(param_1,(double)iVar3);
    FUN_007bc850(param_1,0xfffffffd);
    iVar3 = local_118->tm_hour;
    FUN_007bc470(param_1,&DAT_009fd93c);
    FUN_007bc400(param_1,(double)iVar3);
    FUN_007bc850(param_1,0xfffffffd);
    iVar3 = local_118->tm_mday;
    FUN_007bc470(param_1,&DAT_009fd938);
    FUN_007bc400(param_1,(double)iVar3);
    FUN_007bc850(param_1,0xfffffffd);
    iVar3 = local_118->tm_mon;
    FUN_007bc470(param_1,s_month_009fd930);
    FUN_007bc400(param_1,(double)(iVar3 + 1));
    FUN_007bc850(param_1,0xfffffffd);
    iVar3 = local_118->tm_year;
    FUN_007bc470(param_1,&DAT_009fd928);
    FUN_007bc400(param_1,(double)(iVar3 + 0x76c));
    FUN_007bc850(param_1,0xfffffffd);
    iVar3 = local_118->tm_wday;
    FUN_007bc470(param_1,&DAT_009fd920);
    FUN_007bc400(param_1,(double)(iVar3 + 1));
    FUN_007bc850(param_1,0xfffffffd);
    iVar3 = local_118->tm_yday;
    FUN_007bc470(param_1,&DAT_009fd918);
    FUN_007bc400(param_1,(double)(iVar3 + 1));
    FUN_007bc850(param_1,0xfffffffd);
    iVar3 = local_118->tm_isdst;
    FUN_007bc470(param_1,s_isdst_009fd910);
    FUN_007bc5d0(param_1,iVar3);
    FUN_007bc850(param_1,0xfffffffd);
    return 1;
  }
  sVar1 = _strftime(local_110,0x100,local_11c,local_118);
  if (sVar1 == 0) {
    uVar2 = FUN_007bad90(param_1,s__date__format_too_long_009fd8f8);
    return uVar2;
  }
  FUN_007bc470(param_1,local_110);
  return 1;
}


// ==== FUN_007b8c30 @ 0x007b8c30 ====

undefined4 FUN_007b8c30(undefined4 param_1)

{
  int iVar1;
  time_t tVar2;
  tm local_24;
  
  iVar1 = FUN_007bbfa0(param_1);
  if (iVar1 < 1) {
    iVar1 = FID_conflict___time32((__time32_t *)0x0);
  }
  else {
    FUN_007bba50(param_1,1,5);
    FUN_007bbdf0(param_1,1);
    FUN_007bc470(param_1,&PTR_LAB_009fd944);
    FUN_007bc620(param_1,0xfffffffe);
    iVar1 = FUN_007bc030(param_1,0xffffffff);
    if (iVar1 == 0) {
      local_24.tm_sec = 0;
    }
    else {
      FUN_007bc1a0(param_1,0xffffffff);
      local_24.tm_sec = FUN_00802534();
    }
    FUN_007bbdf0(param_1,0xfffffffe);
    FUN_007bc470(param_1,&DAT_009fd1c4);
    FUN_007bc620(param_1,0xfffffffe);
    iVar1 = FUN_007bc030(param_1,0xffffffff);
    if (iVar1 == 0) {
      local_24.tm_min = 0;
    }
    else {
      FUN_007bc1a0(param_1,0xffffffff);
      local_24.tm_min = FUN_00802534();
    }
    FUN_007bbdf0(param_1,0xfffffffe);
    FUN_007bc470(param_1,&DAT_009fd93c);
    FUN_007bc620(param_1,0xfffffffe);
    iVar1 = FUN_007bc030(param_1,0xffffffff);
    if (iVar1 == 0) {
      local_24.tm_hour = 0xc;
    }
    else {
      FUN_007bc1a0(param_1,0xffffffff);
      local_24.tm_hour = FUN_00802534();
    }
    FUN_007bbdf0(param_1,0xfffffffe);
    FUN_007bc470(param_1,&DAT_009fd938);
    FUN_007bc620(param_1,0xfffffffe);
    iVar1 = FUN_007bc030(param_1,0xffffffff);
    if (iVar1 == 0) {
      local_24.tm_mday =
           FUN_007bad90(param_1,s_field___s__missing_in_date_table_009fd8d4,&DAT_009fd938);
    }
    else {
      FUN_007bc1a0(param_1,0xffffffff);
      local_24.tm_mday = FUN_00802534();
      FUN_007bbdf0(param_1,0xfffffffe);
    }
    FUN_007bc470(param_1,s_month_009fd930);
    FUN_007bc620(param_1,0xfffffffe);
    iVar1 = FUN_007bc030(param_1,0xffffffff);
    if (iVar1 == 0) {
      local_24.tm_mon =
           FUN_007bad90(param_1,s_field___s__missing_in_date_table_009fd8d4,s_month_009fd930);
    }
    else {
      FUN_007bc1a0(param_1,0xffffffff);
      local_24.tm_mon = FUN_00802534();
      FUN_007bbdf0(param_1,0xfffffffe);
    }
    local_24.tm_mon = local_24.tm_mon + -1;
    FUN_007bc470(param_1,&DAT_009fd928);
    FUN_007bc620(param_1,0xfffffffe);
    iVar1 = FUN_007bc030(param_1,0xffffffff);
    if (iVar1 == 0) {
      local_24.tm_year =
           FUN_007bad90(param_1,s_field___s__missing_in_date_table_009fd8d4,&DAT_009fd928);
    }
    else {
      FUN_007bc1a0(param_1,0xffffffff);
      local_24.tm_year = FUN_00802534();
      FUN_007bbdf0(param_1,0xfffffffe);
    }
    local_24.tm_year = local_24.tm_year + -0x76c;
    FUN_007bc470(param_1,s_isdst_009fd910);
    FUN_007bc620(param_1,0xfffffffe);
    iVar1 = FUN_007bc1f0(param_1,0xffffffff);
    FUN_007bbdf0(param_1,0xfffffffe);
    local_24.tm_isdst = iVar1;
    tVar2 = _mktime(&local_24);
    iVar1 = (int)tVar2;
    if (iVar1 == -1) {
      FUN_007bc3e0();
      return 1;
    }
  }
  FUN_007bc400(param_1,(double)iVar1);
  return 1;
}


// ==== FUN_007b8ec0 @ 0x007b8ec0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b8ec0(undefined4 param_1)

{
  undefined4 uVar1;
  float10 fVar2;
  
  FUN_007bbc20(param_1,2,_DAT_0099d098);
  uVar1 = FUN_00802534();
  FUN_007bbba0(param_1,1,uVar1);
  uVar1 = FUN_00802534();
  fVar2 = (float10)FUN_00805c02(uVar1);
  FUN_007bc400(param_1,(double)fVar2);
  return 1;
}


// ==== FUN_007b8f10 @ 0x007b8f10 ====

undefined4 FUN_007b8f10(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_007bc230(param_1,1);
  uVar2 = FUN_007bbb40(param_1,2,&DAT_009fd70c,0,&PTR_DAT_009fd608);
  iVar3 = FUN_007badc0(uVar2);
  if (iVar1 == 0) {
    iVar4 = FUN_007bbfa0(param_1,1);
    if (0 < iVar4) {
      FUN_007bb990(param_1,1,s_string_expected_009fd950);
    }
  }
  if (iVar3 == -1) {
    FUN_007bb990(param_1,2,s_invalid_option_009fcff4);
  }
  uVar2 = FUN_008015fc(*(undefined4 *)(&DAT_009fd5f0 + iVar3 * 4),iVar1);
  FUN_007bc470(param_1,uVar2);
  return 1;
}


// ==== FUN_007b8fa0 @ 0x007b8fa0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007b8fa0(undefined4 param_1)

{
  int _Code;
  
  FUN_007bbc20(param_1,1,_DAT_0099d098);
  _Code = FUN_00802534();
                    /* WARNING: Subroutine does not return */
  _exit(_Code);
}


// ==== FUN_007b8fd0 @ 0x007b8fd0 ====

undefined4 FUN_007b8fd0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  FUN_007bb040(param_1,&DAT_009fd97c,&PTR_s_clock_009fd628,0);
  FUN_007bae20(param_1,s_FILE__009fd79c);
  FUN_007bc420(param_1,s___index_009fd898,7);
  FUN_007bbf60(param_1,0xfffffffe);
  FUN_007bc850(param_1,0xfffffffd);
  FUN_007bb040(param_1,0,&PTR_s_flush_009fd5a8,0);
  FUN_007bbf60(param_1,0xffffffff);
  FUN_007bb040(param_1,&DAT_009fd978,&PTR_s_input_009fd548,1);
  FUN_007b79f0(&PTR_DAT_00b49680);
  FUN_007b79f0(&DAT_00b496a0);
  FUN_007bc470(param_1,s_stderr_009fd960);
  puVar1 = (undefined4 *)FUN_007bcc80(param_1,4);
  *puVar1 = 0;
  FUN_007baea0(param_1,s_FILE__009fd79c);
  FUN_007bc910(param_1,0xfffffffe);
  *puVar1 = &DAT_00b496c0;
  FUN_007bc810(param_1,0xfffffffd);
  return 1;
}


// ==== FUN_007b90b0 @ 0x007b90b0 ====

undefined4 FUN_007b90b0(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_007baec0(param_1,1,s_FILE__009fd79c);
  if (piVar1 == (int *)0x0) {
    FUN_007bb990(param_1,1,s_bad_file_009fd790);
  }
  if (*piVar1 == 0) {
    FUN_007bad90(param_1,s_attempt_to_use_a_closed_file_009fd7b8);
  }
  FUN_007bc420(param_1,s_FILE__009fd79c,5);
  FUN_007bc670(param_1,0xffffd8f0);
  FUN_007bbf60(param_1,1);
  FUN_007bc5d0(param_1,0);
  FUN_007bc540(param_1,FUN_007b8320,3);
  return 1;
}


// ==== FUN_007b9130 @ 0x007b9130 ====

undefined4 FUN_007b9130(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  iVar1 = FUN_007bbfa0(param_1,1);
  if (iVar1 < 1) {
    FUN_007bc470(param_1,s__input_009fd814);
    FUN_007bc670(param_1,0xffffd8ee);
    uVar2 = FUN_007b90b0(param_1);
    return uVar2;
  }
  uVar2 = FUN_007bbad0(param_1,1,0);
  piVar3 = (int *)FUN_007bcc80(param_1,4);
  *piVar3 = 0;
  FUN_007baea0(param_1,s_FILE__009fd79c);
  FUN_007bc910(param_1,0xfffffffe);
  iVar1 = FUN_00803b27(uVar2,&DAT_009fd7f8);
  *piVar3 = iVar1;
  if (iVar1 == 0) {
    puVar4 = (undefined4 *)FUN_00804b94();
    pcVar5 = _strerror((char *)*puVar4);
    FUN_007bb990(param_1,1,pcVar5);
  }
  uVar2 = FUN_007bbde0(param_1);
  FUN_007bc420(param_1,s_FILE__009fd79c,5);
  FUN_007bc670(param_1,0xffffd8f0);
  FUN_007bbf60(param_1,uVar2);
  FUN_007bc5d0(param_1,1);
  FUN_007bc540(param_1,FUN_007b8320,3);
  return 1;
}


// ==== FUN_007b9210 @ 0x007b9210 ====

undefined4 FUN_007b9210(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int local_c;
  
  FUN_007bba50(param_1,1,5);
  iVar1 = FUN_007bb280(param_1,1);
  FUN_007bba50(param_1,2,6);
  local_c = 1;
  if (0 < iVar1) {
    do {
      FUN_007bbf60(param_1,2);
      FUN_007bc400(param_1,(double)local_c);
      FUN_007bc6c0(param_1,1,local_c);
      FUN_007bc9f0(param_1,2,1);
      iVar2 = FUN_007bbfa0(param_1,0xffffffff);
      if (iVar2 != 0) {
        return 1;
      }
      FUN_007bbdf0();
      local_c = local_c + 1;
    } while (local_c <= iVar1);
  }
  return 0;
}


// ==== FUN_007b92b0 @ 0x007b92b0 ====

undefined4 FUN_007b92b0(undefined4 param_1)

{
  int iVar1;
  
  FUN_007bba50(param_1,1,5);
  FUN_007bba50(param_1,2,6);
  FUN_007bc3e0(param_1);
  iVar1 = FUN_007bcbb0(param_1,1);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    FUN_007bbf60(param_1,2);
    FUN_007bbf60(param_1,0xfffffffd);
    FUN_007bbf60(param_1,0xfffffffd);
    FUN_007bc9f0(param_1,2,1);
    iVar1 = FUN_007bbfa0(param_1,0xffffffff);
    if (iVar1 != 0) break;
    FUN_007bbdf0(param_1,0xfffffffd);
    iVar1 = FUN_007bcbb0(param_1,1);
  }
  return 1;
}


// ==== FUN_007b9340 @ 0x007b9340 ====

undefined4 FUN_007b9340(undefined4 param_1)

{
  int iVar1;
  
  FUN_007bba50(param_1,1,5);
  iVar1 = FUN_007bb280(param_1,1);
  FUN_007bc400(param_1,(double)iVar1);
  return 1;
}


// ==== FUN_007b9380 @ 0x007b9380 ====

undefined4 FUN_007b9380(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_007bba50(param_1,1,5);
  FUN_007bbba0(param_1,2);
  uVar1 = FUN_00802534();
  FUN_007bb1b0(param_1,1,uVar1);
  return 0;
}


// ==== FUN_007b93b0 @ 0x007b93b0 ====

undefined4 FUN_007b93b0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_007bbde0(param_1);
  FUN_007bba50(param_1,1,5);
  iVar3 = FUN_007bb280(param_1,1);
  iVar3 = iVar3 + 1;
  if (iVar2 == 2) {
    uVar4 = 2;
    iVar2 = iVar3;
  }
  else {
    FUN_007bbba0(param_1,2);
    iVar2 = FUN_00802534();
    if (iVar3 < iVar2) {
      iVar3 = iVar2;
    }
    uVar4 = 3;
  }
  FUN_007bb1b0(param_1,1,iVar3);
  while (iVar1 = iVar3 + -1, iVar2 <= iVar1) {
    FUN_007bc6c0(param_1,1,iVar1);
    FUN_007bc8b0(param_1,1,iVar3);
    iVar3 = iVar1;
  }
  FUN_007bbf60(param_1,uVar4);
  FUN_007bc8b0(param_1,1,iVar2);
  return 0;
}


// ==== FUN_007b9450 @ 0x007b9450 ====

undefined4 FUN_007b9450(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint unaff_EBX;
  undefined4 uVar5;
  longlong lVar4;
  
  FUN_007bba50(param_1,1,5);
  iVar2 = FUN_007bb280(param_1,1);
  FUN_007bbc20(param_1,2,(double)iVar2);
  iVar3 = FUN_00802534();
  if (iVar2 < 1) {
    return 0;
  }
  FUN_007bb1b0(param_1,1,iVar2 + -1);
  FUN_007bc6c0(param_1,1,iVar3);
  if (iVar3 < iVar2) {
    lVar4 = (ulonglong)unaff_EBX << 0x20;
    do {
      iVar1 = iVar3 + 1;
      uVar5 = (undefined4)((ulonglong)lVar4 >> 0x20);
      lVar4 = CONCAT44(uVar5,iVar1);
      FUN_007bc6c0(param_1,1,iVar1,uVar5);
      FUN_007bc8b0(param_1,1,iVar3);
      iVar3 = iVar1;
    } while (iVar1 < iVar2);
  }
  FUN_007bc3e0();
  FUN_007bc8b0(param_1,1,iVar2);
  return 1;
}


// ==== FUN_007b94f0 @ 0x007b94f0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b94f0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_214 [4];
  undefined1 local_210 [524];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  FUN_007bbb40(param_1,2,&DAT_0099cf70,local_214);
  FUN_007bbc20(param_1,3,_DAT_0099d0a0);
  iVar1 = FUN_00802534();
  FUN_007bbc20(param_1,4,_DAT_0099d098);
  iVar2 = FUN_00802534();
  FUN_007bba50(param_1,1,5);
  if (iVar2 == 0) {
    iVar2 = FUN_007bb280(param_1,1);
  }
  FUN_007bb5b0(param_1,local_210);
  for (; iVar1 <= iVar2; iVar1 = iVar1 + 1) {
    FUN_007bc6c0(param_1,1,iVar1);
    iVar3 = FUN_007bc080(param_1,0xffffffff);
    if (iVar3 == 0) {
      FUN_007bb990(param_1,1);
    }
    FUN_007bb510();
    if (iVar1 != iVar2) {
      FUN_007bb460(local_210);
    }
  }
  FUN_007bb4c0();
  return 1;
}


// ==== FUN_007b9610 @ 0x007b9610 ====

void FUN_007b9610(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 < param_3) {
    do {
      FUN_007bc6c0(param_1,1,param_2);
      FUN_007bc6c0(param_1,1,param_3);
      iVar1 = FUN_007bbfa0(param_1,2);
      if (iVar1 == 0) {
        iVar1 = FUN_007bc130(param_1,0xffffffff,0xfffffffe);
      }
      else {
        FUN_007bbf60(param_1,2);
        FUN_007bbf60(param_1,0xfffffffe);
        FUN_007bbf60(param_1,0xfffffffc);
        FUN_007bc9f0(param_1,2,1);
        iVar1 = FUN_007bc1f0(param_1,0xffffffff);
        FUN_007bbdf0(param_1,0xfffffffe);
      }
      if (iVar1 == 0) {
        FUN_007bbdf0(param_1,0xfffffffd);
      }
      else {
        FUN_007bc8b0(param_1,1,param_2);
        FUN_007bc8b0(param_1,1,param_3);
      }
      if (param_3 - param_2 == 1) {
        return;
      }
      iVar5 = (param_2 + param_3) / 2;
      FUN_007bc6c0(param_1,1,iVar5);
      FUN_007bc6c0(param_1,1,param_2);
      iVar1 = FUN_007bbfa0(param_1,2);
      if (iVar1 == 0) {
        iVar1 = FUN_007bc130(param_1,0xfffffffe,0xffffffff);
      }
      else {
        FUN_007bbf60(param_1,2);
        FUN_007bbf60(param_1,0xfffffffd);
        FUN_007bbf60(param_1,0xfffffffd);
        FUN_007bc9f0(param_1,2,1);
        iVar1 = FUN_007bc1f0(param_1,0xffffffff);
        FUN_007bbdf0(param_1,0xfffffffe);
      }
      if (iVar1 == 0) {
        FUN_007bbdf0(param_1,0xfffffffe);
        FUN_007bc6c0(param_1,1,param_3);
        iVar1 = FUN_007bbfa0(param_1,2);
        if (iVar1 == 0) {
          iVar1 = FUN_007bc130(param_1,0xffffffff,0xfffffffe);
        }
        else {
          FUN_007bbf60(param_1,2);
          FUN_007bbf60(param_1,0xfffffffe);
          FUN_007bbf60(param_1,0xfffffffc);
          FUN_007bc9f0(param_1,2,1);
          iVar1 = FUN_007bc1f0(param_1,0xffffffff);
          FUN_007bbdf0(param_1,0xfffffffe);
        }
        if (iVar1 == 0) {
          FUN_007bbdf0(param_1,0xfffffffd);
        }
        else {
          FUN_007bc8b0(param_1,1,iVar5);
          FUN_007bc8b0(param_1,1,param_3);
        }
      }
      else {
        FUN_007bc8b0(param_1,1,iVar5);
        FUN_007bc8b0(param_1,1,param_2);
      }
      if (param_3 - param_2 == 2) {
        return;
      }
      FUN_007bc6c0(param_1,1,iVar5);
      FUN_007bbf60(param_1,0xffffffff);
      iVar1 = param_3 + -1;
      FUN_007bc6c0(param_1,1,iVar1);
      FUN_007bc8b0(param_1,1,iVar5);
      FUN_007bc8b0(param_1,1,iVar1);
      iVar5 = param_2;
      iVar4 = iVar1;
      while( true ) {
        while( true ) {
          iVar3 = iVar5 + 1;
          FUN_007bc6c0(param_1,1,iVar3);
          iVar2 = FUN_007bbfa0(param_1,2);
          if (iVar2 == 0) {
            iVar2 = FUN_007bc130(param_1,0xffffffff,0xfffffffe);
          }
          else {
            FUN_007bbf60(param_1,2);
            FUN_007bbf60(param_1,0xfffffffe);
            FUN_007bbf60(param_1,0xfffffffc);
            FUN_007bc9f0(param_1,2,1);
            iVar2 = FUN_007bc1f0(param_1,0xffffffff);
            FUN_007bbdf0(param_1,0xfffffffe);
          }
          if (iVar2 == 0) break;
          if (param_3 < iVar3) {
            FUN_007bad90(param_1,s_invalid_order_function_for_sorti_009fda20);
          }
          FUN_007bbdf0(param_1,0xfffffffe);
          iVar5 = iVar3;
        }
        while( true ) {
          iVar4 = iVar4 + -1;
          FUN_007bc6c0(param_1,1,iVar4);
          iVar2 = FUN_007bbfa0(param_1,2);
          if (iVar2 == 0) {
            iVar2 = FUN_007bc130(param_1,0xfffffffd,0xffffffff);
          }
          else {
            FUN_007bbf60(param_1,2);
            FUN_007bbf60(param_1,0xfffffffc);
            FUN_007bbf60(param_1,0xfffffffd);
            FUN_007bc9f0(param_1,2,1);
            iVar2 = FUN_007bc1f0(param_1,0xffffffff);
            FUN_007bbdf0(param_1,0xfffffffe);
          }
          if (iVar2 == 0) break;
          if (iVar4 < param_2) {
            FUN_007bad90(param_1,s_invalid_order_function_for_sorti_009fda20);
          }
          FUN_007bbdf0(param_1,0xfffffffe);
        }
        if (iVar4 < iVar3) break;
        FUN_007bc8b0(param_1,1,iVar3);
        FUN_007bc8b0(param_1,1,iVar4);
        iVar5 = iVar3;
      }
      FUN_007bbdf0(param_1,0xfffffffc);
      FUN_007bc6c0(param_1,1,iVar1);
      FUN_007bc6c0(param_1,1,iVar3);
      FUN_007bc8b0(param_1,1,iVar1);
      FUN_007bc8b0(param_1,1,iVar3);
      if (iVar3 - param_2 < param_3 - iVar3) {
        iVar1 = param_2;
        iVar4 = iVar5;
        param_2 = iVar5 + 2;
      }
      else {
        iVar1 = iVar5 + 2;
        iVar4 = param_3;
        param_3 = iVar5;
      }
      FUN_007b9610(param_1,iVar1,iVar4);
    } while (param_2 < param_3);
  }
  return;
}


// ==== FUN_007b9a00 @ 0x007b9a00 ====

undefined4 FUN_007b9a00(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_007bba50(param_1,1,5);
  uVar1 = FUN_007bb280(param_1,1);
  FUN_007baf50(param_1,0x28,&DAT_0099cf70);
  iVar2 = FUN_007bbfa0(param_1,2);
  if (0 < iVar2) {
    FUN_007bba50(param_1,2,6);
  }
  FUN_007bbdf0(param_1,2);
  FUN_007b9610(param_1,1,uVar1);
  return 0;
}


// ==== FUN_007b9a60 @ 0x007b9a60 ====

undefined4 FUN_007b9a60(undefined4 param_1)

{
  FUN_007bb040(param_1,s_table_009fda44,&PTR_s_concat_009fd980,0);
  return 1;
}


// ==== FUN_007b9a80 @ 0x007b9a80 ====

undefined4 FUN_007b9a80(undefined4 param_1)

{
  int iVar1;
  char *_Str;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_007bbde0(param_1);
  FUN_007bc470(param_1,s_tostring_009fdbf4);
  FUN_007bc620(param_1,0xffffd8ef);
  iVar3 = 1;
  if (0 < iVar1) {
    do {
      FUN_007bbf60(param_1,0xffffffff);
      FUN_007bbf60(param_1,iVar3);
      FUN_007bc9f0(param_1,1,1);
      _Str = (char *)FUN_007bc230(param_1,0xffffffff);
      if (_Str == (char *)0x0) {
        uVar2 = FUN_007bad90(param_1,s__tostring__must_return_a_string_t_009fdc64);
        return uVar2;
      }
      if (1 < iVar3) {
        _fputs(&DAT_009fdc90,(FILE *)&DAT_00b496a0);
      }
      _fputs(_Str,(FILE *)&DAT_00b496a0);
      FUN_007bbdf0(param_1,0xfffffffe);
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar1);
  }
  _fputs(&DAT_009fd0b4,(FILE *)&DAT_00b496a0);
  return 0;
}


// ==== FUN_007b9b40 @ 0x007b9b40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b9b40(undefined4 param_1)

{
  double dVar1;
  int iVar2;
  byte *_Str;
  ulong uVar3;
  float10 fVar4;
  byte *local_8;
  ulong local_4;
  
  FUN_007bbc20(param_1,2,_DAT_009fdca8);
  iVar2 = FUN_00802534();
  if (iVar2 == 10) {
    FUN_007bbaa0(param_1,1);
    iVar2 = FUN_007bc030(param_1,1);
    if (iVar2 != 0) {
      fVar4 = (float10)FUN_007bc1a0(param_1,1);
      FUN_007bc400(param_1,(double)fVar4);
      return 1;
    }
  }
  else {
    _Str = (byte *)FUN_007bbad0(param_1,1,0);
    if ((iVar2 < 2) || (0x24 < iVar2)) {
      FUN_007bb990(param_1,2,s_base_out_of_range_009fdc94);
    }
    uVar3 = _strtoul((char *)_Str,(char **)&local_8,iVar2);
    if (_Str != local_8) {
      iVar2 = _isspace((uint)*local_8);
      while (iVar2 != 0) {
        local_8 = local_8 + 1;
        iVar2 = _isspace((uint)*local_8);
      }
      if (*local_8 == 0) {
        dVar1 = (double)(int)uVar3;
        if ((int)uVar3 < 0) {
          dVar1 = dVar1 + _DAT_009c2f50;
        }
        local_4 = uVar3;
        FUN_007bc400(param_1,dVar1);
        return 1;
      }
    }
  }
  FUN_007bc3e0();
  return 1;
}


// ==== FUN_007b9c70 @ 0x007b9c70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007b9c70(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_007bbc20(param_1,2,_DAT_0099d0a0);
  iVar1 = FUN_00802534();
  FUN_007bbaa0(param_1,1);
  iVar2 = FUN_007bc080(param_1,1);
  if ((iVar2 == 0) || (iVar1 == 0)) {
    FUN_007bbf60(param_1,1);
    FUN_007bcba0();
    return;
  }
  FUN_007bad00(param_1,iVar1);
  FUN_007bbf60(param_1,1);
  FUN_007bcc00(param_1,2);
  FUN_007bcba0();
  return;
}


// ==== FUN_007b9cf0 @ 0x007b9cf0 ====

undefined4 FUN_007b9cf0(undefined4 param_1)

{
  int iVar1;
  
  FUN_007bbaa0(param_1,1);
  iVar1 = FUN_007bc750(param_1,1);
  if (iVar1 == 0) {
    FUN_007bc3e0(param_1);
    return 1;
  }
  FUN_007baf80(param_1,1,s_____metatable_009fdcae + 2);
  return 1;
}


// ==== FUN_007b9d40 @ 0x007b9d40 ====

undefined4 FUN_007b9d40(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_007bbfa0(param_1,2);
  FUN_007bba50(param_1,1,5);
  if ((iVar1 != 0) && (iVar1 != 5)) {
    FUN_007bb990(param_1,2,s_nil_or_table_expected_009fdce0);
  }
  iVar1 = FUN_007baf80(param_1,1,s_____metatable_009fdcae + 2);
  if (iVar1 != 0) {
    FUN_007bad90(param_1,s_cannot_change_a_protected_metata_009fdcbc);
  }
  FUN_007bbdf0(param_1,2);
  FUN_007bc910(param_1,1);
  return 1;
}


// ==== FUN_007b9dc0 @ 0x007b9dc0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007b9dc0(void)

{
  int iVar1;
  
  iVar1 = FUN_007bbfa0();
  if (iVar1 == 6) {
    FUN_007bbf60();
    return;
  }
  FUN_007bbc20();
  iVar1 = FUN_00802534();
  if (iVar1 < 0) {
    FUN_007bb990();
  }
  iVar1 = FUN_007bdf40();
  if (iVar1 == 0) {
    FUN_007bb990();
  }
  FUN_007beab0();
  iVar1 = FUN_007bbfa0();
  if (iVar1 == 0) {
    FUN_007bad90();
  }
  return;
}


// ==== FUN_007b9e90 @ 0x007b9e90 ====

undefined4 FUN_007b9e90(undefined4 param_1)

{
  int iVar1;
  
  FUN_007b9dc0();
  FUN_007bc7c0(param_1,0xffffffff);
  FUN_007bc420(param_1,s___fenv_009fdd5c,6);
  FUN_007bc670(param_1,0xfffffffe);
  iVar1 = FUN_007bbfa0(param_1,0xffffffff);
  if (iVar1 == 0) {
    FUN_007bbdf0(param_1,0xfffffffe);
  }
  return 1;
}


// ==== FUN_007b9ee0 @ 0x007b9ee0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b9ee0(undefined4 param_1)

{
  int iVar1;
  float10 fVar2;
  
  FUN_007bba50(param_1,2,5);
  FUN_007b9dc0();
  FUN_007bc7c0(param_1,0xffffffff);
  FUN_007bc420(param_1,s___fenv_009fdd5c,6);
  FUN_007bc670(param_1,0xfffffffe);
  iVar1 = FUN_007bbfa0(param_1,0xffffffff);
  if (iVar1 == 0) {
    FUN_007bbdf0(param_1,0xfffffffd);
  }
  else {
    FUN_007bad90(param_1,s__setfenv__cannot_change_a_protec_009fdd9c);
  }
  FUN_007bbf60(param_1,2);
  iVar1 = FUN_007bc030(param_1,1);
  if (iVar1 != 0) {
    fVar2 = (float10)FUN_007bc1a0(param_1,1);
    if ((float10)_DAT_0099d098 == fVar2) {
      FUN_007bbf10(param_1,0xffffd8ef);
      return 0;
    }
  }
  iVar1 = FUN_007bc980(param_1,0xfffffffe);
  if (iVar1 == 0) {
    FUN_007bad90(param_1,s__setfenv__cannot_change_environm_009fdd64);
  }
  return 0;
}


// ==== FUN_007b9fa0 @ 0x007b9fa0 ====

undefined4 FUN_007b9fa0(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_007bbaa0(param_1,1);
  FUN_007bbaa0(param_1,2);
  uVar1 = FUN_007bc0c0(param_1,1,2);
  FUN_007bc5d0(param_1,uVar1);
  return 1;
}


// ==== FUN_007b9fd0 @ 0x007b9fd0 ====

undefined4 FUN_007b9fd0(undefined4 param_1)

{
  FUN_007bba50(param_1,1,5);
  FUN_007bbaa0(param_1,2);
  FUN_007bc670(param_1,1);
  return 1;
}


// ==== FUN_007ba000 @ 0x007ba000 ====

undefined4 FUN_007ba000(undefined4 param_1)

{
  FUN_007bba50(param_1,1,5);
  FUN_007bbaa0(param_1,2);
  FUN_007bbaa0(param_1,3);
  FUN_007bc850(param_1,1);
  return 1;
}


// ==== FUN_007ba040 @ 0x007ba040 ====

undefined4 FUN_007ba040(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_007bcb50();
  FUN_007bc400(param_1,(double)iVar1);
  iVar1 = FUN_007bcb40(param_1);
  FUN_007bc400(param_1,(double)iVar1);
  return 2;
}


// ==== FUN_007ba090 @ 0x007ba090 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007ba090(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_007bbc20(param_1,1,_DAT_0099d098);
  uVar1 = FUN_00802534();
  FUN_007bcb60(param_1,uVar1);
  return 0;
}


// ==== FUN_007ba0c0 @ 0x007ba0c0 ====

undefined4 FUN_007ba0c0(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_007bbaa0(param_1,1);
  uVar1 = FUN_007bbfa0(param_1,1);
  uVar1 = FUN_007bbfd0(param_1,uVar1);
  FUN_007bc470(param_1,uVar1);
  return 1;
}


// ==== FUN_007ba0f0 @ 0x007ba0f0 ====

undefined4 FUN_007ba0f0(undefined4 param_1)

{
  int iVar1;
  
  FUN_007bba50(param_1,1,5);
  FUN_007bbdf0(param_1,2);
  iVar1 = FUN_007bcbb0(param_1,1);
  if (iVar1 == 0) {
    FUN_007bc3e0(param_1);
    return 1;
  }
  return 2;
}


// ==== FUN_007ba130 @ 0x007ba130 ====

undefined4 FUN_007ba130(undefined4 param_1)

{
  FUN_007bba50(param_1,1,5);
  FUN_007bc420(param_1,&DAT_009fdc24,4);
  FUN_007bc670(param_1,0xffffd8ef);
  FUN_007bbf60(param_1,1);
  FUN_007bc3e0(param_1);
  return 3;
}


// ==== FUN_007ba170 @ 0x007ba170 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_007ba170(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  float10 fVar3;
  
  fVar3 = (float10)FUN_007bc1a0(param_1,2);
  FUN_007bba50(param_1,1,5);
  if ((double)fVar3 == _DAT_0099d098) {
    iVar1 = FUN_007bbfa0(param_1,2);
    if (iVar1 == -1) {
      FUN_007bc420(param_1,s_ipairs_009fdc1c,6);
      FUN_007bc670(param_1,0xffffd8ef);
      FUN_007bbf60(param_1,1);
      FUN_007bc400(param_1,_DAT_0099d098);
      return 3;
    }
  }
  FUN_007bc400(param_1,(double)fVar3 + _DAT_0099d0a0);
  uVar2 = FUN_00802534();
  FUN_007bc6c0(param_1,1,uVar2);
  iVar1 = FUN_007bbfa0(param_1,0xffffffff);
  return -(iVar1 != 0) & 2;
}


// ==== FUN_007ba240 @ 0x007ba240 ====

undefined4 FUN_007ba240(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_4;
  
  uVar1 = FUN_007bbad0(param_1,1,&local_4);
  uVar2 = FUN_007bbb40(param_1,2,uVar1,0);
  iVar3 = FUN_007bb860(param_1,uVar1,local_4,uVar2);
  if (iVar3 == 0) {
    return 1;
  }
  FUN_007bc3e0(param_1);
  FUN_007bbeb0(param_1,0xfffffffe);
  return 2;
}


// ==== FUN_007ba2a0 @ 0x007ba2a0 ====

undefined4 FUN_007ba2a0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_007bbb40(param_1,1,0,0);
  iVar2 = FUN_007bb650(param_1,uVar1);
  if (iVar2 == 0) {
    return 1;
  }
  FUN_007bc3e0(param_1);
  FUN_007bbeb0(param_1,0xfffffffe);
  return 2;
}


// ==== FUN_007ba2e0 @ 0x007ba2e0 ====

int FUN_007ba2e0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_007bbb40(param_1,1,0,0);
  iVar2 = FUN_007bb650(param_1,uVar1);
  if (iVar2 != 0) {
    FUN_007bcba0(param_1);
  }
  FUN_007bc9f0(param_1,0,0xffffffff);
  iVar2 = FUN_007bbde0(param_1);
  return iVar2 + -1;
}


// ==== FUN_007ba320 @ 0x007ba320 ====

undefined4 FUN_007ba320(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_007bbaa0(param_1,1);
  iVar1 = FUN_007bc1f0(param_1,1);
  if (iVar1 == 0) {
    uVar2 = FUN_007bbb40(param_1,2,s_assertion_failed__009fddcc,0);
    uVar2 = FUN_007bad90(param_1,&DAT_009d5e14,uVar2);
    return uVar2;
  }
  FUN_007bbdf0(param_1,1);
  return 1;
}


// ==== FUN_007ba370 @ 0x007ba370 ====

int FUN_007ba370(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_007bba50(param_1,1,5);
  iVar1 = FUN_007bb280(param_1,1);
  FUN_007baf50(param_1,iVar1,s_table_too_big_to_unpack_009fdde0);
  iVar2 = 1;
  if (0 < iVar1) {
    do {
      FUN_007bc6c0(param_1,1,iVar2);
      iVar2 = iVar2 + 1;
    } while (iVar2 <= iVar1);
  }
  return iVar1;
}


// ==== FUN_007ba3c0 @ 0x007ba3c0 ====

void FUN_007ba3c0(undefined4 param_1)

{
  int iVar1;
  
  FUN_007bbaa0(param_1,1);
  iVar1 = FUN_007bbde0(param_1,0xffffffff,0);
  iVar1 = FUN_007bca30(param_1,iVar1 + -1);
  FUN_007bc5d0(param_1,iVar1 == 0);
  FUN_007bbeb0(param_1,1);
  FUN_007bbde0(param_1);
  return;
}


// ==== FUN_007ba410 @ 0x007ba410 ====

void FUN_007ba410(undefined4 param_1)

{
  int iVar1;
  
  FUN_007bbaa0(param_1,2);
  FUN_007bbdf0(param_1,2);
  FUN_007bbeb0(param_1,1);
  iVar1 = FUN_007bca30(param_1,0,0xffffffff,1);
  FUN_007bc5d0(param_1,iVar1 == 0);
  FUN_007bbf10(param_1,1);
  FUN_007bbde0(param_1);
  return;
}


// ==== FUN_007ba460 @ 0x007ba460 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007ba460(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  char local_44 [64];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  FUN_007bbaa0(param_1,1);
  iVar1 = FUN_007bafe0(param_1,1,s___tostring_009fd710);
  if (iVar1 != 0) {
    return 1;
  }
  uVar2 = FUN_007bbfa0(param_1,1);
  switch(uVar2) {
  case 0:
    FUN_007bc420(param_1,&PTR_LAB_009fddf8,3);
    return 1;
  case 1:
    iVar1 = FUN_007bc1f0(param_1,1);
    pcVar3 = &DAT_009fde3c;
    if (iVar1 == 0) {
      pcVar3 = s_false_009fde34;
    }
    goto LAB_007ba513;
  case 2:
  case 7:
    uVar2 = FUN_007bc300(param_1,1);
    pcVar3 = s_userdata___p_009fde08;
    break;
  case 3:
    uVar2 = FUN_007bc230(param_1,1);
    FUN_007bc470(param_1,uVar2);
    return 1;
  case 4:
    FUN_007bbf60(param_1,1);
    return 1;
  case 5:
    uVar2 = FUN_007bc370(param_1,1);
    pcVar3 = s_table___p_009fde28;
    break;
  case 6:
    uVar2 = FUN_007bc370(param_1,1);
    pcVar3 = s_function___p_009fde18;
    break;
  case 8:
    uVar2 = FUN_007bc340(param_1,1);
    pcVar3 = s_thread___p_009fddfc;
    break;
  default:
    goto switchD_007ba4a1_default;
  }
  _sprintf(local_44,pcVar3,uVar2);
switchD_007ba4a1_default:
  pcVar3 = local_44;
LAB_007ba513:
  FUN_007bc470(param_1,pcVar3);
  return 1;
}


// ==== FUN_007ba680 @ 0x007ba680 ====

char * FUN_007ba680(void)

{
  char *pcVar1;
  
  FUN_007bc470();
  FUN_007bc620();
  pcVar1 = (char *)FUN_007bc230();
  FUN_007bbdf0();
  if (pcVar1 != (char *)0x0) {
    return pcVar1;
  }
  pcVar1 = _getenv(s_LUA_PATH_009fde68);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = s_____lua_009fde60;
  }
  return pcVar1;
}


// ==== FUN_007ba6d0 @ 0x007ba6d0 ====

void FUN_007ba6d0(void)

{
  char *pcVar1;
  
  pcVar1 = (char *)FUN_007bc230();
  for (pcVar1 = _strchr(pcVar1,0x3f); pcVar1 != (char *)0x0; pcVar1 = _strchr(pcVar1 + 1,0x3f)) {
    FUN_007baf50();
    FUN_007bc420();
    FUN_007bbf60();
  }
  FUN_007bc470();
  FUN_007bcc00();
  return;
}


// ==== FUN_007ba740 @ 0x007ba740 ====

undefined4 FUN_007ba740(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char *_Str;
  char *pcVar4;
  int iVar5;
  
  iVar5 = 2;
  FUN_007bbad0(param_1,1,0);
  FUN_007bbdf0(param_1,1);
  FUN_007bc470(param_1,s__LOADED_009fdf10);
  FUN_007bc620(param_1,0xffffd8ef);
  iVar2 = FUN_007bbfa0(param_1,2);
  if (iVar2 != 5) {
    uVar3 = FUN_007bad90(param_1,s___LOADED__is_not_a_table_009fdef4);
    return uVar3;
  }
  _Str = (char *)FUN_007ba680();
  FUN_007bbf60(param_1,1);
  FUN_007bc670(param_1,2);
  iVar2 = FUN_007bc1f0(param_1,0xffffffff);
  if (iVar2 == 0) {
    do {
      FUN_007bbdf0(param_1,3);
      if (*_Str == '\0') break;
      if (*_Str == ';') {
        _Str = _Str + 1;
      }
      pcVar4 = _strchr(_Str,0x3b);
      if (pcVar4 == (char *)0x0) {
        pcVar1 = _Str;
        do {
          pcVar4 = pcVar1;
          pcVar1 = pcVar4 + 1;
        } while (*pcVar4 != '\0');
      }
      FUN_007bc420(param_1,_Str,(int)pcVar4 - (int)_Str);
      if (pcVar4 == (char *)0x0) break;
      FUN_007ba6d0();
      uVar3 = FUN_007bc230(param_1,0xffffffff);
      iVar5 = FUN_007bb650(param_1,uVar3);
      _Str = pcVar4;
    } while (iVar5 == 2);
    if (iVar5 != 0) {
      if (iVar5 == 2) {
        uVar3 = FUN_007ba680();
        uVar3 = FUN_007bc230(param_1,1,uVar3);
        uVar3 = FUN_007bad90(param_1,s_could_not_load_package___s__from_009fdea8,uVar3);
        return uVar3;
      }
      uVar3 = FUN_007bc230(param_1,0xffffffff);
      uVar3 = FUN_007bc230(param_1,1,uVar3);
      uVar3 = FUN_007bad90(param_1,s_error_loading_package___s____s__009fded4,uVar3);
      return uVar3;
    }
    FUN_007bc470(param_1,s__REQUIREDNAME_009fde98);
    FUN_007bc620(param_1,0xffffd8ef);
    FUN_007bbeb0(param_1,0xfffffffe);
    FUN_007bbf60(param_1,1);
    FUN_007bc470(param_1,s__REQUIREDNAME_009fde98);
    FUN_007bbeb0(param_1,0xfffffffe);
    FUN_007bc810(param_1,0xffffd8ef);
    FUN_007bc9f0(param_1,0,1);
    FUN_007bbeb0(param_1,0xfffffffe);
    FUN_007bc470(param_1,s__REQUIREDNAME_009fde98);
    FUN_007bbeb0(param_1,0xfffffffe);
    FUN_007bc810(param_1,0xffffd8ef);
    iVar2 = FUN_007bbfa0(param_1,0xffffffff);
    if (iVar2 == 0) {
      FUN_007bc5d0(param_1,1);
      FUN_007bbf10(param_1,0xfffffffe);
    }
    FUN_007bbf60(param_1,1);
    FUN_007bbf60(param_1,0xfffffffe);
    FUN_007bc850(param_1,2);
  }
  return 1;
}


// ==== FUN_007ba950 @ 0x007ba950 ====

undefined4 FUN_007ba950(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_007bbce0();
  if (iVar1 == 0) {
    FUN_007bad90();
  }
  FUN_007bbd40();
  iVar1 = FUN_007bdd40();
  if (iVar1 != 0) {
    FUN_007bbd40();
    return 0xffffffff;
  }
  uVar2 = FUN_007bbde0();
  iVar1 = FUN_007bbce0();
  if (iVar1 == 0) {
    FUN_007bad90();
  }
  FUN_007bbd40();
  return uVar2;
}


// ==== FUN_007ba9d0 @ 0x007ba9d0 ====

int FUN_007ba9d0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_007bc340(param_1,1);
  if (iVar1 == 0) {
    FUN_007bb990(param_1,1,s_coroutine_expected_009fdf54);
  }
  FUN_007bbde0(param_1);
  iVar1 = FUN_007ba950();
  if (iVar1 < 0) {
    FUN_007bc5d0(param_1,0);
    FUN_007bbeb0(param_1,0xfffffffe);
    return 2;
  }
  FUN_007bc5d0(param_1,1);
  FUN_007bbeb0(param_1,-1 - iVar1);
  return iVar1 + 1;
}


// ==== FUN_007baab0 @ 0x007baab0 ====

undefined4 FUN_007baab0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_007bbda0(param_1);
  iVar2 = FUN_007bbfa0(param_1,1);
  if (iVar2 == 6) {
    iVar2 = FUN_007bbff0(param_1,1);
    if (iVar2 == 0) goto LAB_007baaed;
  }
  FUN_007bb990(param_1,1,s_Lua_function_expected_009fdf68);
LAB_007baaed:
  FUN_007bbf60(param_1,1);
  FUN_007bbd40(param_1,uVar1,1);
  return 1;
}


// ==== FUN_007bab10 @ 0x007bab10 ====

undefined4 FUN_007bab10(undefined4 param_1)

{
  FUN_007baab0(param_1);
  FUN_007bc540(param_1,&LAB_007baa50,1);
  return 1;
}


// ==== FUN_007bab40 @ 0x007bab40 ====

void FUN_007bab40(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_007bbde0(param_1);
  FUN_007bdb10(param_1,uVar1);
  return;
}


// ==== FUN_007bab60 @ 0x007bab60 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007bab60(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined1 local_64 [96];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar1 = FUN_007bc340(param_1,1);
  if (iVar1 == 0) {
    FUN_007bb990(param_1,1,s_coroutine_expected_009fdf54);
  }
  if (param_1 == iVar1) {
    uVar4 = 7;
    pcVar3 = s_running_009fdf94;
  }
  else {
    iVar2 = FUN_007bdf40(iVar1,0,local_64);
    if (iVar2 == 0) {
      iVar1 = FUN_007bbde0(iVar1);
      if (iVar1 == 0) {
        uVar4 = 4;
        pcVar3 = &DAT_009fdf8c;
        goto LAB_007babd1;
      }
    }
    uVar4 = 9;
    pcVar3 = s_suspended_009fdf80;
  }
LAB_007babd1:
  FUN_007bc420(param_1,pcVar3,uVar4);
  return 1;
}


// ==== FUN_007babf0 @ 0x007babf0 ====

void FUN_007babf0(void)

{
  FUN_007bc420();
  FUN_007bbf60();
  FUN_007bb040();
  FUN_007bc420();
  FUN_007bc420();
  FUN_007bc850();
  FUN_007bc420();
  FUN_007bc710();
  FUN_007bbf60();
  FUN_007bc910();
  FUN_007bc420();
  FUN_007bc420();
  FUN_007bc850();
  FUN_007bc540();
  FUN_007bc850();
  FUN_007bc850();
  return;
}


// ==== FUN_007bacb0 @ 0x007bacb0 ====

undefined4 FUN_007bacb0(undefined4 param_1)

{
  FUN_007babf0();
  FUN_007bb040(param_1,s_coroutine_009fdfcc,&PTR_s_create_009fdb20,0);
  FUN_007bc710(param_1);
  FUN_007bc470(param_1,s__LOADED_009fdf10);
  FUN_007bbeb0(param_1,0xfffffffe);
  FUN_007bc810(param_1,0xffffd8ef);
  return 0;
}


// ==== FUN_007bad00 @ 0x007bad00 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007bad00(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_64 [20];
  int local_50;
  undefined1 local_44 [64];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar1 = FUN_007bdf40(param_1,param_2,local_64);
  if (iVar1 != 0) {
    FUN_007beab0(param_1,&DAT_009fd090,local_64);
    if (0 < local_50) {
      FUN_007bc510(param_1,s__s__d__009fdfd8,local_44,local_50);
      return;
    }
  }
  FUN_007bc420(param_1,&DAT_0099cf70,0);
  return;
}


// ==== FUN_007bad90 @ 0x007bad90 ====

void FUN_007bad90(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_007bad00(param_1,1);
  FUN_007bc4e0(param_1,param_2,&param_3);
  FUN_007bcc00(param_1,2);
  FUN_007bcba0(param_1);
  return;
}


// ==== FUN_007badc0 @ 0x007badc0 ====

int FUN_007badc0(byte *param_1,undefined4 *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  bool bVar6;
  
  pbVar2 = (byte *)*param_2;
  iVar5 = 0;
  do {
    if (pbVar2 == (byte *)0x0) {
      return -1;
    }
    pbVar4 = param_1;
    do {
      bVar1 = *pbVar2;
      bVar6 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_007badfb:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_007bae00;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar6 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_007badfb;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_007bae00:
    if (iVar3 == 0) {
      return iVar5;
    }
    pbVar2 = (byte *)param_2[iVar5 + 1];
    iVar5 = iVar5 + 1;
  } while( true );
}


// ==== FUN_007bae20 @ 0x007bae20 ====

undefined4 FUN_007bae20(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_007bc470(param_1,param_2);
  FUN_007bc670(param_1,0xffffd8f0);
  iVar1 = FUN_007bbfa0(param_1,0xffffffff);
  if (iVar1 == 0) {
    FUN_007bbdf0(param_1,0xfffffffe);
    FUN_007bc710(param_1);
    FUN_007bc470(param_1,param_2);
    FUN_007bbf60(param_1,0xfffffffe);
    FUN_007bc850(param_1,0xffffd8f0);
    FUN_007bbf60(param_1,0xffffffff);
    FUN_007bc470(param_1,param_2);
    FUN_007bc850(param_1,0xffffd8f0);
    return 1;
  }
  return 0;
}


// ==== FUN_007baea0 @ 0x007baea0 ====

void FUN_007baea0(undefined4 param_1,undefined4 param_2)

{
  FUN_007bc470(param_1,param_2);
  FUN_007bc670(param_1,0xffffd8f0);
  return;
}


// ==== FUN_007baec0 @ 0x007baec0 ====

undefined4 FUN_007baec0(undefined4 param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  bool bVar5;
  
  iVar2 = FUN_007bc750(param_1,param_2);
  if (iVar2 != 0) {
    FUN_007bc670(param_1,0xffffd8f0);
    pbVar3 = (byte *)FUN_007bc230(param_1,0xffffffff);
    if (pbVar3 != (byte *)0x0) {
      do {
        bVar1 = *pbVar3;
        bVar5 = bVar1 < *param_3;
        if (bVar1 != *param_3) {
LAB_007baf20:
          iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
          goto LAB_007baf25;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar5 = bVar1 < param_3[1];
        if (bVar1 != param_3[1]) goto LAB_007baf20;
        pbVar3 = pbVar3 + 2;
        param_3 = param_3 + 2;
      } while (bVar1 != 0);
      iVar2 = 0;
LAB_007baf25:
      if (iVar2 == 0) {
        FUN_007bbdf0(param_1,0xfffffffe);
        uVar4 = FUN_007bc300(param_1,param_2);
        return uVar4;
      }
    }
    FUN_007bbdf0(param_1,0xfffffffe);
  }
  return 0;
}


// ==== FUN_007baf50 @ 0x007baf50 ====

void FUN_007baf50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_007bbce0(param_1,param_2);
  if (iVar1 == 0) {
    FUN_007bad90(param_1,s_stack_overflow___s__009fdfe0,param_3);
  }
  return;
}


// ==== FUN_007baf80 @ 0x007baf80 ====

undefined4 FUN_007baf80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_007bc750(param_1,param_2);
  if (iVar1 != 0) {
    FUN_007bc470(param_1,param_3);
    FUN_007bc670(param_1,0xfffffffe);
    iVar1 = FUN_007bbfa0(param_1,0xffffffff);
    if (iVar1 != 0) {
      FUN_007bbe50(param_1,0xfffffffe);
      return 1;
    }
    FUN_007bbdf0(param_1,0xfffffffd);
  }
  return 0;
}


// ==== FUN_007bafe0 @ 0x007bafe0 ====

undefined4 FUN_007bafe0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((param_2 < 1) && (-10000 < param_2)) {
    iVar1 = FUN_007bbde0(param_1);
    param_2 = param_2 + 1 + iVar1;
  }
  iVar1 = FUN_007baf80(param_1,param_2,param_3);
  if (iVar1 == 0) {
    return 0;
  }
  FUN_007bbf60(param_1,param_2);
  FUN_007bc9f0(param_1,1,1);
  return 1;
}


// ==== FUN_007bb040 @ 0x007bb040 ====

void FUN_007bb040(undefined4 param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  
  if (param_2 != 0) {
    FUN_007bc470(param_1,param_2);
    FUN_007bc620(param_1,0xffffd8ef);
    iVar1 = FUN_007bbfa0(param_1,0xffffffff);
    if (iVar1 == 0) {
      FUN_007bbdf0(param_1,0xfffffffe);
      FUN_007bc710(param_1);
      FUN_007bc470(param_1,param_2);
      FUN_007bbf60(param_1,0xfffffffe);
      FUN_007bc810(param_1,0xffffd8ef);
    }
    FUN_007bbeb0(param_1,-1 - param_4);
  }
  iVar1 = *param_3;
  if (iVar1 != 0) {
    do {
      FUN_007bc470(param_1,iVar1);
      if (0 < param_4) {
        param_2 = param_4;
        do {
          FUN_007bbf60(param_1,-1 - param_4);
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
      FUN_007bc540(param_1,param_3[1],param_4);
      FUN_007bc810(param_1,-3 - param_4);
      iVar1 = param_3[2];
      param_3 = param_3 + 2;
    } while (iVar1 != 0);
  }
  FUN_007bbdf0(param_1,-1 - param_4);
  return;
}


// ==== FUN_007bb130 @ 0x007bb130 ====

void FUN_007bb130(void)

{
  int iVar1;
  
  FUN_007bc6c0();
  iVar1 = FUN_007bbfa0();
  if (iVar1 == 0) {
    FUN_007bbdf0();
    FUN_007bc710();
    FUN_007bbf60();
    FUN_007bc910();
    FUN_007bc420();
    FUN_007bc420();
    FUN_007bc850();
    FUN_007bbf60();
    FUN_007bc8b0();
  }
  return;
}


// ==== FUN_007bb1b0 @ 0x007bb1b0 ====

void FUN_007bb1b0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 < 1) && (-10000 < param_2)) {
    iVar1 = FUN_007bbde0();
    param_2 = param_2 + 1 + iVar1;
  }
  FUN_007bc420(param_1,&DAT_009fdff4,1);
  FUN_007bc670(param_1,param_2);
  FUN_007bc1a0(param_1,0xffffffff);
  iVar1 = FUN_00802534();
  if (iVar1 == 0) {
    iVar2 = FUN_007bc030(param_1,0xffffffff);
    if (iVar2 == 0) {
      iVar1 = -1;
    }
  }
  FUN_007bbdf0(param_1,0xfffffffe);
  if (iVar1 < 0) {
    FUN_007bb130();
    FUN_007bbf60(param_1,param_2);
    FUN_007bc400(param_1,(double)param_3);
    FUN_007bc850(param_1,0xfffffffd);
    FUN_007bbdf0(param_1,0xfffffffe);
    return;
  }
  FUN_007bc420(param_1,&DAT_009fdff4,1);
  FUN_007bc400(param_1,(double)param_3);
  FUN_007bc850(param_1,param_2);
  return;
}


// ==== FUN_007bb280 @ 0x007bb280 ====

int FUN_007bb280(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 < 1) && (-10000 < param_2)) {
    iVar1 = FUN_007bbde0(param_1);
    param_2 = param_2 + 1 + iVar1;
  }
  FUN_007bc420(param_1,&DAT_009fdff4,1);
  FUN_007bc670(param_1,param_2);
  FUN_007bc1a0(param_1,0xffffffff);
  iVar1 = FUN_00802534();
  if ((iVar1 == 0) && (iVar2 = FUN_007bc030(param_1,0xffffffff), iVar2 == 0)) {
    iVar1 = -1;
  }
  FUN_007bbdf0(param_1,0xfffffffe);
  if (iVar1 < 0) {
    FUN_007bb130();
    FUN_007bbf60(param_1,param_2);
    FUN_007bc670(param_1,0xfffffffe);
    FUN_007bc1a0(param_1,0xffffffff);
    iVar1 = FUN_00802534();
    if ((iVar1 == 0) && (iVar2 = FUN_007bc030(param_1,0xffffffff), iVar2 == 0)) {
      iVar1 = -1;
    }
    FUN_007bbdf0(param_1,0xfffffffd);
    if (iVar1 < 0) {
      iVar1 = 1;
      FUN_007bc6c0(param_1,param_2,1);
      iVar2 = FUN_007bbfa0(param_1,0xffffffff);
      while (iVar2 != 0) {
        FUN_007bbdf0(param_1,0xfffffffe);
        iVar1 = iVar1 + 1;
        FUN_007bc6c0(param_1,param_2,iVar1);
        iVar2 = FUN_007bbfa0(param_1,0xffffffff);
      }
      FUN_007bbdf0(param_1,0xfffffffe);
      return iVar1 + -1;
    }
  }
  return iVar1;
}


// ==== FUN_007bb3a0 @ 0x007bb3a0 ====

void FUN_007bb3a0(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = param_1;
  iVar4 = 1;
  if (1 < *(int *)(param_1 + 4)) {
    uVar1 = *(undefined4 *)(param_1 + 8);
    param_1 = FUN_007bc2a0(uVar1,0xffffffff);
    iVar5 = -2;
    do {
      uVar3 = FUN_007bc2a0(uVar1,iVar5);
      if (((*(int *)(iVar2 + 4) - iVar4) + 1 < 10) && (param_1 <= uVar3)) break;
      param_1 = param_1 + uVar3;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar4 < *(int *)(iVar2 + 4));
    FUN_007bcc00(uVar1,iVar4);
    *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + (1 - iVar4);
  }
  return;
}


// ==== FUN_007bb420 @ 0x007bb420 ====

int * FUN_007bb420(int *param_1)

{
  int iVar1;
  
  iVar1 = (*param_1 - (int)param_1) + -0xc;
  if (iVar1 != 0) {
    FUN_007bc420(param_1[2],param_1 + 3,iVar1);
    *param_1 = (int)(param_1 + 3);
    param_1[1] = param_1[1] + 1;
    FUN_007bb3a0(param_1);
  }
  return param_1 + 3;
}


// ==== FUN_007bb460 @ 0x007bb460 ====

void FUN_007bb460(int *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    do {
      if ((param_1 + 0x83 <= (int *)*param_1) &&
         (iVar1 = *param_1 + (-0xc - (int)param_1), iVar1 != 0)) {
        FUN_007bc420(param_1[2],param_1 + 3,iVar1);
        *param_1 = (int)(param_1 + 3);
        param_1[1] = param_1[1] + 1;
        FUN_007bb3a0(param_1);
      }
      *(undefined1 *)*param_1 = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
      *param_1 = *param_1 + 1;
    } while (param_3 != 0);
  }
  return;
}


// ==== FUN_007bb4c0 @ 0x007bb4c0 ====

void FUN_007bb4c0(int *param_1)

{
  int iVar1;
  
  iVar1 = (*param_1 - (int)param_1) + -0xc;
  if (iVar1 != 0) {
    FUN_007bc420(param_1[2],param_1 + 3,iVar1);
    *param_1 = (int)(param_1 + 3);
    param_1[1] = param_1[1] + 1;
  }
  FUN_007bcc00(param_1[2],param_1[1]);
  param_1[1] = 1;
  return;
}


// ==== FUN_007bb510 @ 0x007bb510 ====

void FUN_007bb510(int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  iVar1 = param_1[2];
  uVar2 = FUN_007bc2a0(iVar1,0xffffffff);
  if ((uint)((int)param_1 + (0x20c - *param_1)) < uVar2) {
    iVar4 = (*param_1 - (int)param_1) + -0xc;
    if (iVar4 != 0) {
      FUN_007bc420(param_1[2],param_1 + 3,iVar4);
      *param_1 = (int)(param_1 + 3);
      param_1[1] = param_1[1] + 1;
      FUN_007bbeb0(iVar1,0xfffffffe);
    }
    param_1[1] = param_1[1] + 1;
    FUN_007bb3a0(param_1);
    return;
  }
  puVar3 = (undefined4 *)FUN_007bc230(iVar1,0xffffffff);
  puVar6 = (undefined4 *)*param_1;
  for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar6 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar5 = uVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  *param_1 = *param_1 + uVar2;
  FUN_007bbdf0(iVar1,0xfffffffe);
  return;
}


// ==== FUN_007bb5b0 @ 0x007bb5b0 ====

void FUN_007bb5b0(int param_1,int *param_2)

{
  param_2[2] = param_1;
  *param_2 = (int)(param_2 + 3);
  param_2[1] = 0;
  return;
}


// ==== FUN_007bb610 @ 0x007bb610 ====

undefined4 FUN_007bb610(void)

{
  undefined4 *puVar1;
  
  FUN_007bc230();
  puVar1 = (undefined4 *)FUN_00804b94();
  _strerror((char *)*puVar1);
  FUN_007bc510();
  FUN_007bbe50();
  return 2;
}


// ==== FUN_007bb650 @ 0x007bb650 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007bb650(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  FILE *_File;
  FILE *local_208 [129];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar2 = FUN_007bbde0(param_1);
  iVar2 = iVar2 + 1;
  if (param_2 == 0) {
    FUN_007bc420(param_1,s__stdin_009fe014,6);
    local_208[0] = (FILE *)&PTR_DAT_00b49680;
  }
  else {
    FUN_007bc510(param_1,&DAT_009fe00c,param_2);
    local_208[0] = (FILE *)FUN_00803b27(param_2,&DAT_009fd7f8);
    if (local_208[0] == (FILE *)0x0) {
      iVar3 = FUN_007bc230(param_1,iVar2);
      puVar6 = (undefined4 *)FUN_00804b94();
      pcVar7 = _strerror((char *)*puVar6);
      FUN_007bc510(param_1,s_cannot_read__s___s_009fdff8,iVar3 + 1,pcVar7);
      FUN_007bbe50(param_1,iVar2);
      return 2;
    }
  }
  _File = local_208[0];
  iVar3 = FID_conflict__getc(local_208[0]);
  iVar3 = _ungetc(iVar3,_File);
  iVar4 = _isspace(iVar3);
  if (iVar4 == 0) {
    iVar3 = _isprint(iVar3);
    if ((iVar3 == 0) && (local_208[0] != (FILE *)&PTR_DAT_00b49680)) {
      _fclose(local_208[0]);
      local_208[0] = (FILE *)FUN_00803b27(param_2,&DAT_009fe010);
      if (local_208[0] == (FILE *)0x0) {
        uVar5 = FUN_007bb610();
        return uVar5;
      }
    }
  }
  uVar5 = FUN_007bc230(param_1,0xffffffff);
  uVar5 = FUN_007bcaa0(param_1,&LAB_007bb5d0,local_208,uVar5);
  uVar1 = local_208[0]->_flag;
  if (local_208[0] != (FILE *)&PTR_DAT_00b49680) {
    _fclose(local_208[0]);
  }
  if ((uVar1 & 0x20) == 0) {
    FUN_007bbe50(param_1,iVar2);
    return uVar5;
  }
  FUN_007bbdf0();
  iVar3 = FUN_007bc230(param_1,iVar2);
  puVar6 = (undefined4 *)FUN_00804b94();
  pcVar7 = _strerror((char *)*puVar6);
  FUN_007bc510(param_1,s_cannot_read__s___s_009fdff8,iVar3 + 1,pcVar7);
  FUN_007bbe50(param_1,iVar2);
  return 2;
}


// ==== FUN_007bb860 @ 0x007bb860 ====

void FUN_007bb860(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = param_2;
  local_4 = param_3;
  FUN_007bcaa0(param_1,&LAB_007bb840,&local_8,param_4);
  return;
}


// ==== FUN_007bb890 @ 0x007bb890 ====

void FUN_007bb890(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  if (in_EAX != 0) {
    FUN_007bc470();
    FUN_007bc620();
    iVar1 = FUN_007bbfa0();
    if (iVar1 == 6) {
      FUN_007bbeb0();
      FUN_007bc9f0();
      return;
    }
    uVar2 = FUN_007bc230();
    FID_conflict__fwprintf((FILE *)&DAT_00b496c0,(wchar_t *)&DAT_009fe01c,uVar2);
    FUN_007bbdf0();
  }
  return;
}


// ==== FUN_007bb900 @ 0x007bb900 ====

int FUN_007bb900(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = param_2;
  local_4 = param_3;
  iVar1 = FUN_007bcaa0(param_1,&LAB_007bb840,&local_8,param_4);
  if (iVar1 == 0) {
    iVar1 = FUN_007bca30(param_1,0,0xffffffff,0);
  }
  FUN_007bb890();
  return iVar1;
}


// ==== FUN_007bb960 @ 0x007bb960 ====

void FUN_007bb960(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_007bb900(param_1,param_2,(int)pcVar2 - (int)(param_2 + 1),param_2);
  return;
}


// ==== FUN_007bb990 @ 0x007bb990 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007bb990(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  undefined1 local_64 [4];
  undefined *local_60;
  char *local_5c;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  FUN_007bdf40(param_1,0,local_64);
  FUN_007beab0(param_1,&DAT_009fdff4,local_64);
  iVar1 = 7;
  bVar3 = true;
  pcVar2 = s_method_009fe06c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar3 = *local_5c == *pcVar2;
    local_5c = local_5c + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar3);
  if (bVar3) {
    param_2 = param_2 + -1;
    if (param_2 == 0) {
      FUN_007bad90(param_1,s_calling___s__on_bad_self___s__009fe04c,local_60,param_3);
      return;
    }
  }
  if (local_60 == (undefined *)0x0) {
    local_60 = &DAT_009fe048;
  }
  FUN_007bad90(param_1,s_bad_argument___d_to___s____s__009fe028,param_2,local_60,param_3);
  return;
}


// ==== FUN_007bba50 @ 0x007bba50 ====

void FUN_007bba50(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_007bbfa0(param_1,param_2);
  if (iVar1 != param_3) {
    uVar2 = FUN_007bbfd0(param_1,param_3);
    uVar3 = FUN_007bbfa0(param_1,param_2);
    uVar3 = FUN_007bbfd0(param_1,uVar3);
    uVar2 = FUN_007bc510(param_1,s__s_expected__got__s_009fe074,uVar2,uVar3);
    FUN_007bb990(param_1,param_2,uVar2);
  }
  return;
}


// ==== FUN_007bbaa0 @ 0x007bbaa0 ====

void FUN_007bbaa0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_007bbfa0(param_1,param_2);
  if (iVar1 == -1) {
    FUN_007bb990(param_1,param_2,s_value_expected_009fe088);
  }
  return;
}


// ==== FUN_007bbad0 @ 0x007bbad0 ====

int FUN_007bbad0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_007bc230(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = FUN_007bbfd0(param_1,4);
    uVar3 = FUN_007bbfa0(param_1,param_2);
    uVar3 = FUN_007bbfd0(param_1,uVar3);
    uVar2 = FUN_007bc510(param_1,s__s_expected__got__s_009fe074,uVar2,uVar3);
    FUN_007bb990(param_1,param_2,uVar2);
  }
  if (param_3 != (undefined4 *)0x0) {
    uVar2 = FUN_007bc2a0(param_1,param_2);
    *param_3 = uVar2;
  }
  return iVar1;
}


// ==== FUN_007bbb40 @ 0x007bbb40 ====

void FUN_007bbb40(undefined4 param_1,undefined4 param_2,char *param_3,int *param_4)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = FUN_007bbfa0(param_1,param_2);
  if (iVar3 < 1) {
    if (param_4 != (int *)0x0) {
      if (param_3 == (char *)0x0) {
        *param_4 = 0;
        return;
      }
      pcVar1 = param_3 + 1;
      do {
        cVar2 = *param_3;
        param_3 = param_3 + 1;
      } while (cVar2 != '\0');
      *param_4 = (int)param_3 - (int)pcVar1;
      return;
    }
  }
  else {
    FUN_007bbad0(param_1,param_2,param_4);
  }
  return;
}


// ==== FUN_007bbba0 @ 0x007bbba0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_007bbba0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float10 fVar4;
  
  fVar4 = (float10)FUN_007bc1a0(param_1,param_2);
  if (fVar4 == (float10)_DAT_0099d098) {
    iVar1 = FUN_007bc030(param_1,param_2);
    if (iVar1 == 0) {
      uVar2 = FUN_007bbfd0(param_1,3);
      uVar3 = FUN_007bbfa0(param_1,param_2);
      uVar3 = FUN_007bbfd0(param_1,uVar3);
      uVar2 = FUN_007bc510(param_1,s__s_expected__got__s_009fe074,uVar2,uVar3);
      FUN_007bb990(param_1,param_2,uVar2);
    }
    fVar4 = (float10)(double)fVar4;
  }
  return fVar4;
}


// ==== FUN_007bbc20 @ 0x007bbc20 ====

float10 FUN_007bbc20(undefined4 param_1,undefined4 param_2,double param_3)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_007bbfa0(param_1,param_2);
  if (iVar1 < 1) {
    return (float10)param_3;
  }
  fVar2 = (float10)FUN_007bbba0(param_1,param_2);
  return fVar2;
}


// ==== FUN_007bbc50 @ 0x007bbc50 ====

int FUN_007bbc50(void)

{
  int iVar1;
  int in_EAX;
  int in_ECX;
  
  if (-10000 < in_EAX) {
    return in_EAX * 0x10 + *(int *)(in_ECX + 8);
  }
  if (in_EAX == -0x2711) {
    return in_ECX + 0x40;
  }
  if (in_EAX == -10000) {
    return *(int *)(in_ECX + 0x10) + 0x30;
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0xc) + -8);
  if ((int)(uint)*(byte *)(iVar1 + 7) < -0x2711 - in_EAX) {
    return 0;
  }
  return (-0x2711 - in_EAX) * 0x10 + iVar1;
}


// ==== FUN_007bbca0 @ 0x007bbca0 ====

void FUN_007bbca0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = *param_2;
  puVar1[2] = param_2[2];
  puVar1[3] = param_2[3];
  if (*(int *)(param_1 + 0x18) - *(int *)(param_1 + 8) < 0x11) {
    FUN_007bd420(param_1,1);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bbce0 @ 0x007bbce0 ====

undefined4 FUN_007bbce0(int param_1,int param_2)

{
  uint uVar1;
  
  if (0x800 < (*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4) + param_2) {
    return 0;
  }
  if (*(int *)(param_1 + 0x18) - *(int *)(param_1 + 8) <= param_2 * 0x10) {
    FUN_007bd420(param_1,param_2);
  }
  uVar1 = *(int *)(param_1 + 8) + param_2 * 0x10;
  if (*(uint *)(*(int *)(param_1 + 0x14) + 4) < uVar1) {
    *(uint *)(*(int *)(param_1 + 0x14) + 4) = uVar1;
  }
  return 1;
}


// ==== FUN_007bbd40 @ 0x007bbd40 ====

void FUN_007bbd40(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * -0x10;
  if (0 < param_3) {
    iVar3 = 0;
    do {
      puVar1 = *(undefined4 **)(param_2 + 8);
      iVar2 = *(int *)(param_1 + 8) + iVar3;
      *puVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + iVar3);
      puVar1[2] = *(undefined4 *)(iVar2 + 8);
      puVar1[3] = *(undefined4 *)(iVar2 + 0xc);
      iVar3 = iVar3 + 0x10;
      param_3 = param_3 + -1;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x10;
    } while (param_3 != 0);
  }
  return;
}


// ==== FUN_007bbda0 @ 0x007bbda0 ====

void FUN_007bbda0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  uVar2 = FUN_007bcff0(param_1);
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = 8;
  puVar1[2] = uVar2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bbde0 @ 0x007bbde0 ====

int FUN_007bbde0(int param_1)

{
  return *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4;
}


// ==== FUN_007bbdf0 @ 0x007bbdf0 ====

void FUN_007bbdf0(int param_1,int param_2)

{
  if (param_2 < 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_2 * 0x10 + 0x10;
    return;
  }
  param_2 = param_2 * 0x10;
  if (*(uint *)(param_1 + 8) < (uint)(*(int *)(param_1 + 0xc) + param_2)) {
    do {
      **(undefined4 **)(param_1 + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < (uint)(*(int *)(param_1 + 0xc) + param_2));
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + param_2;
  return;
}


// ==== FUN_007bbe50 @ 0x007bbe50 ====

void FUN_007bbe50(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 < 1) {
    iVar1 = FUN_007bbc50();
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10;
  }
  puVar2 = (undefined4 *)(iVar1 + 0x10);
  if (puVar2 < *(undefined4 **)(param_1 + 8)) {
    do {
      puVar2[-4] = *puVar2;
      puVar2[-2] = puVar2[2];
      puVar2[-1] = puVar2[3];
      puVar2 = puVar2 + 4;
    } while (puVar2 < *(undefined4 **)(param_1 + 8));
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  return;
}


// ==== FUN_007bbeb0 @ 0x007bbeb0 ====

void FUN_007bbeb0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_2 < 1) {
    puVar1 = (undefined4 *)FUN_007bbc50();
  }
  else {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
  }
  for (puVar2 = *(undefined4 **)(param_1 + 8); puVar1 < puVar2; puVar2 = puVar2 + -4) {
    *puVar2 = puVar2[-4];
    puVar2[2] = puVar2[-2];
    puVar2[3] = puVar2[-1];
  }
  puVar2 = *(undefined4 **)(param_1 + 8);
  *puVar1 = *puVar2;
  puVar1[2] = puVar2[2];
  puVar1[3] = puVar2[3];
  return;
}


// ==== FUN_007bbf10 @ 0x007bbf10 ====

void FUN_007bbf10(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  if (param_2 < 1) {
    puVar2 = (undefined4 *)FUN_007bbc50();
  }
  else {
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
  }
  *puVar2 = *(undefined4 *)(iVar1 + -0x10);
  puVar2[2] = *(undefined4 *)(iVar1 + -8);
  puVar2[3] = *(undefined4 *)(iVar1 + -4);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  return;
}


// ==== FUN_007bbf60 @ 0x007bbf60 ====

void FUN_007bbf60(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_2 < 1) {
    puVar2 = (undefined4 *)FUN_007bbc50();
  }
  else {
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = *puVar2;
  puVar1[2] = puVar2[2];
  puVar1[3] = puVar2[3];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bbfa0 @ 0x007bbfa0 ====

undefined4 FUN_007bbfa0(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_2 < 1) {
    puVar1 = (undefined4 *)FUN_007bbc50();
  }
  else {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
    if (*(undefined4 **)(param_1 + 8) <= puVar1) {
      return 0xffffffff;
    }
  }
  if (puVar1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  return *puVar1;
}


// ==== FUN_007bbfd0 @ 0x007bbfd0 ====

char * FUN_007bbfd0(undefined4 param_1,int param_2)

{
  if (param_2 == -1) {
    return s_no_value_009fe124;
  }
  return (&PTR_PTR_009fe340)[param_2];
}


// ==== FUN_007bbff0 @ 0x007bbff0 ====

undefined4 FUN_007bbff0(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 < 1) {
    piVar1 = (int *)FUN_007bbc50();
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
    if (*(int **)(param_1 + 8) <= piVar1) {
      return 0;
    }
  }
  if (((piVar1 == (int *)0x0) || (*piVar1 != 6)) || (*(char *)(piVar1[2] + 6) == '\0')) {
    return 0;
  }
  return 1;
}


// ==== FUN_007bc030 @ 0x007bc030 ====

undefined4 FUN_007bc030(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 local_10 [16];
  
  if (param_2 < 1) {
    piVar1 = (int *)FUN_007bbc50();
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
    if (*(int **)(param_1 + 8) <= piVar1) {
      return 0;
    }
  }
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  if ((*piVar1 == 3) || (iVar2 = FUN_007bf840(piVar1,local_10), iVar2 != 0)) {
    return 1;
  }
  return 0;
}


// ==== FUN_007bc080 @ 0x007bc080 ====

undefined4 FUN_007bc080(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 < 1) {
    piVar1 = (int *)FUN_007bbc50();
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
    if (*(int **)(param_1 + 8) <= piVar1) {
      return 0;
    }
  }
  if ((piVar1 == (int *)0x0) || ((*piVar1 != 4 && (*piVar1 != 3)))) {
    return 0;
  }
  return 1;
}


// ==== FUN_007bc0c0 @ 0x007bc0c0 ====

undefined4 FUN_007bc0c0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_2 < 1) {
    uVar3 = FUN_007bbc50();
  }
  else {
    uVar3 = *(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10;
    uVar3 = -(uint)(uVar3 < *(uint *)(param_1 + 8)) & uVar3;
  }
  if (param_3 < 1) {
    uVar1 = FUN_007bbc50();
  }
  else {
    uVar1 = *(int *)(param_1 + 0xc) + -0x10 + param_3 * 0x10;
    uVar1 = -(uint)(uVar1 < *(uint *)(param_1 + 8)) & uVar1;
  }
  if ((uVar3 == 0) || (uVar1 == 0)) {
    return 0;
  }
  uVar2 = FUN_007c16c0(uVar3,uVar1);
  return uVar2;
}


// ==== FUN_007bc130 @ 0x007bc130 ====

undefined4 FUN_007bc130(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_2 < 1) {
    uVar3 = FUN_007bbc50();
  }
  else {
    uVar3 = *(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10;
    uVar3 = -(uint)(uVar3 < *(uint *)(param_1 + 8)) & uVar3;
  }
  if (param_3 < 1) {
    uVar1 = FUN_007bbc50();
  }
  else {
    uVar1 = *(int *)(param_1 + 0xc) + -0x10 + param_3 * 0x10;
    uVar1 = -(uint)(uVar1 < *(uint *)(param_1 + 8)) & uVar1;
  }
  if ((uVar3 == 0) || (uVar1 == 0)) {
    return 0;
  }
  uVar2 = FUN_007bfe80(param_1,uVar3,uVar1);
  return uVar2;
}


// ==== FUN_007bc1a0 @ 0x007bc1a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_007bc1a0(int param_1,int param_2)

{
  int *piVar1;
  undefined1 local_10 [16];
  
  if (param_2 < 1) {
    piVar1 = (int *)FUN_007bbc50();
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
    if (*(int **)(param_1 + 8) <= piVar1) goto LAB_007bc1be;
  }
  if (piVar1 == (int *)0x0) {
LAB_007bc1be:
    return (float10)_DAT_0099d098;
  }
  if (*piVar1 != 3) {
    piVar1 = (int *)FUN_007bf840(piVar1,local_10);
    if (piVar1 == (int *)0x0) goto LAB_007bc1be;
  }
  return (float10)*(double *)(piVar1 + 2);
}


// ==== FUN_007bc1f0 @ 0x007bc1f0 ====

undefined4 FUN_007bc1f0(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 < 1) {
    piVar1 = (int *)FUN_007bbc50();
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
    if (*(int **)(param_1 + 8) <= piVar1) {
      return 0;
    }
  }
  if (((piVar1 == (int *)0x0) || (*piVar1 == 0)) || ((*piVar1 == 1 && (piVar1[2] == 0)))) {
    return 0;
  }
  return 1;
}


// ==== FUN_007bc230 @ 0x007bc230 ====

int FUN_007bc230(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 < 1) {
    piVar1 = (int *)FUN_007bbc50();
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
    if (*(int **)(param_1 + 8) <= piVar1) {
      return 0;
    }
  }
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  if (*piVar1 == 4) {
    return piVar1[2] + 0x10;
  }
  iVar2 = FUN_007bf890(param_1,piVar1);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = piVar1[2] + 0x10;
  }
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  return iVar2;
}


// ==== FUN_007bc2a0 @ 0x007bc2a0 ====

undefined4 FUN_007bc2a0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 < 1) {
    piVar1 = (int *)FUN_007bbc50();
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
    if (*(int **)(param_1 + 8) <= piVar1) {
      return 0;
    }
  }
  if (piVar1 != (int *)0x0) {
    if (*piVar1 == 4) {
      return *(undefined4 *)(piVar1[2] + 0xc);
    }
    iVar2 = FUN_007bf890(param_1,piVar1);
    if (iVar2 != 0) {
      return *(undefined4 *)(piVar1[2] + 0xc);
    }
  }
  return 0;
}


// ==== FUN_007bc300 @ 0x007bc300 ====

int FUN_007bc300(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 < 1) {
    piVar1 = (int *)FUN_007bbc50();
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
    if (*(int **)(param_1 + 8) <= piVar1) {
      return 0;
    }
  }
  if (piVar1 != (int *)0x0) {
    if (*piVar1 == 2) {
      return piVar1[2];
    }
    if (*piVar1 == 7) {
      return piVar1[2] + 0x10;
    }
  }
  return 0;
}


// ==== FUN_007bc340 @ 0x007bc340 ====

int FUN_007bc340(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 < 1) {
    piVar1 = (int *)FUN_007bbc50();
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
    if (*(int **)(param_1 + 8) <= piVar1) {
      return 0;
    }
  }
  if ((piVar1 == (int *)0x0) || (*piVar1 != 8)) {
    return 0;
  }
  return piVar1[2];
}


// ==== FUN_007bc370 @ 0x007bc370 ====

undefined4 FUN_007bc370(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_2 < 1) {
    puVar1 = (undefined4 *)FUN_007bbc50();
  }
  else {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
    if (*(undefined4 **)(param_1 + 8) <= puVar1) {
      return 0;
    }
  }
  if (puVar1 != (undefined4 *)0x0) {
    switch(*puVar1) {
    case 2:
    case 7:
      uVar2 = FUN_007bc300(param_1,param_2);
      return uVar2;
    case 5:
    case 6:
    case 8:
      return puVar1[2];
    }
  }
  return 0;
}


// ==== FUN_007bc3e0 @ 0x007bc3e0 ====

void FUN_007bc3e0(int param_1)

{
  **(undefined4 **)(param_1 + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bc400 @ 0x007bc400 ====

void FUN_007bc400(int param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  *(undefined8 *)(puVar1 + 2) = param_2;
  *puVar1 = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bc420 @ 0x007bc420 ====

void FUN_007bc420(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = 4;
  uVar2 = FUN_007c1d70(param_1,param_2,param_3);
  puVar1[2] = uVar2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bc470 @ 0x007bc470 ====

void FUN_007bc470(int param_1,char *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  if (param_2 == (char *)0x0) {
    **(undefined4 **)(param_1 + 8) = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return;
  }
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  puVar2 = *(undefined4 **)(param_1 + 8);
  *puVar2 = 4;
  uVar4 = FUN_007c1d70(param_1,param_2,(int)pcVar3 - (int)(param_2 + 1));
  puVar2[2] = uVar4;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bc4e0 @ 0x007bc4e0 ====

void FUN_007bc4e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  FUN_007c17d0(param_1,param_2,param_3);
  return;
}


// ==== FUN_007bc510 @ 0x007bc510 ====

void FUN_007bc510(int param_1,undefined4 param_2,undefined1 param_3)

{
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  FUN_007c17d0(param_1,param_2,&param_3);
  return;
}


// ==== FUN_007bc540 @ 0x007bc540 ====

void FUN_007bc540(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  iVar1 = FUN_007c1e40(param_1,param_3);
  *(undefined4 *)(iVar1 + 0xc) = param_2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * -0x10;
  if (param_3 != 0) {
    puVar3 = (undefined4 *)(param_3 * 0x10 + 0x10 + iVar1);
    do {
      puVar4 = puVar3 + -4;
      puVar2 = (undefined4 *)((int)puVar4 + *(int *)(param_1 + 8) + (-0x10 - iVar1));
      param_3 = param_3 + -1;
      *puVar4 = *puVar2;
      puVar3[-2] = puVar2[2];
      puVar3[-1] = puVar2[3];
      puVar3 = puVar4;
    } while (param_3 != 0);
  }
  puVar3 = *(undefined4 **)(param_1 + 8);
  puVar3[2] = iVar1;
  *puVar3 = 6;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bc5d0 @ 0x007bc5d0 ====

void FUN_007bc5d0(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = 1;
  puVar1[2] = (uint)(param_2 != 0);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bc600 @ 0x007bc600 ====

void FUN_007bc600(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = 2;
  puVar1[2] = param_2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bc620 @ 0x007bc620 ====

void FUN_007bc620(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 < 1) {
    iVar1 = FUN_007bbc50();
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10;
  }
  puVar2 = (undefined4 *)FUN_007bfb60(param_1,iVar1,*(int *)(param_1 + 8) + -0x10,0);
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(iVar1 + -0x10) = *puVar2;
  *(undefined4 *)(iVar1 + -8) = puVar2[2];
  *(undefined4 *)(iVar1 + -4) = puVar2[3];
  return;
}


// ==== FUN_007bc670 @ 0x007bc670 ====

void FUN_007bc670(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 < 1) {
    iVar1 = FUN_007bbc50();
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10;
  }
  puVar2 = (undefined4 *)FUN_007c26b0(*(undefined4 *)(iVar1 + 8),*(int *)(param_1 + 8) + -0x10);
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(iVar1 + -0x10) = *puVar2;
  *(undefined4 *)(iVar1 + -8) = puVar2[2];
  *(undefined4 *)(iVar1 + -4) = puVar2[3];
  return;
}


// ==== FUN_007bc6c0 @ 0x007bc6c0 ====

void FUN_007bc6c0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 < 1) {
    iVar2 = FUN_007bbc50();
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10;
  }
  puVar3 = (undefined4 *)FUN_007c25e0(*(undefined4 *)(iVar2 + 8),param_3);
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = *puVar3;
  puVar1[2] = puVar3[2];
  puVar1[3] = puVar3[3];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bc710 @ 0x007bc710 ====

void FUN_007bc710(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = 5;
  uVar2 = FUN_007c24d0(param_1,0,0);
  puVar1[2] = uVar2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bc750 @ 0x007bc750 ====

undefined4 FUN_007bc750(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  if (param_2 < 1) {
    piVar2 = (int *)FUN_007bbc50();
  }
  else {
    piVar2 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
    if (*(int **)(param_1 + 8) <= piVar2) {
      return 0;
    }
  }
  if (piVar2 != (int *)0x0) {
    if (*piVar2 == 5) {
      iVar3 = *(int *)(piVar2[2] + 8);
    }
    else {
      if (*piVar2 != 7) {
        return 0;
      }
      iVar3 = *(int *)(piVar2[2] + 8);
    }
    if ((iVar3 != 0) && (iVar3 != *(int *)(*(int *)(param_1 + 0x10) + 0x48))) {
      puVar1 = *(undefined4 **)(param_1 + 8);
      *puVar1 = 5;
      puVar1[2] = iVar3;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007bc7c0 @ 0x007bc7c0 ====

void FUN_007bc7c0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  if (param_2 < 1) {
    piVar2 = (int *)FUN_007bbc50();
  }
  else {
    piVar2 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
  }
  if ((*piVar2 == 6) && (*(char *)(piVar2[2] + 6) == '\0')) {
    puVar3 = (undefined4 *)(piVar2[2] + 0x10);
  }
  else {
    puVar3 = (undefined4 *)(param_1 + 0x40);
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = *puVar3;
  puVar1[2] = puVar3[2];
  puVar1[3] = puVar3[3];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bc810 @ 0x007bc810 ====

void FUN_007bc810(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 1) {
    iVar1 = FUN_007bbc50();
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10;
  }
  FUN_007bfbd0(param_1,iVar1,*(int *)(param_1 + 8) + -0x20,*(int *)(param_1 + 8) + -0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x20;
  return;
}


// ==== FUN_007bc850 @ 0x007bc850 ====

void FUN_007bc850(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 < 1) {
    iVar2 = FUN_007bbc50();
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10;
  }
  iVar1 = *(int *)(param_1 + 8);
  puVar3 = (undefined4 *)FUN_007c2710(param_1,*(undefined4 *)(iVar2 + 8),iVar1 + -0x20);
  *puVar3 = *(undefined4 *)(iVar1 + -0x10);
  puVar3[2] = *(undefined4 *)(iVar1 + -8);
  puVar3[3] = *(undefined4 *)(iVar1 + -4);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x20;
  return;
}


// ==== FUN_007bc8b0 @ 0x007bc8b0 ====

void FUN_007bc8b0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 < 1) {
    iVar2 = FUN_007bbc50();
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10;
  }
  iVar1 = *(int *)(param_1 + 8);
  puVar3 = (undefined4 *)FUN_007c2c90(param_1,*(undefined4 *)(iVar2 + 8),param_3);
  *puVar3 = *(undefined4 *)(iVar1 + -0x10);
  puVar3[2] = *(undefined4 *)(iVar1 + -8);
  puVar3[3] = *(undefined4 *)(iVar1 + -4);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  return;
}


// ==== FUN_007bc910 @ 0x007bc910 ====

undefined4 FUN_007bc910(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 < 1) {
    piVar1 = (int *)FUN_007bbc50();
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
  }
  iVar2 = *(int *)(param_1 + 8) + -0x10;
  if (*(int *)(*(int *)(param_1 + 8) + -0x10) == 0) {
    iVar2 = *(int *)(param_1 + 0x10) + 0x40;
  }
  if ((*piVar1 == 5) || (*piVar1 == 7)) {
    *(undefined4 *)(piVar1[2] + 8) = *(undefined4 *)(iVar2 + 8);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
    return 1;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  return 0;
}


// ==== FUN_007bc980 @ 0x007bc980 ====

undefined4 FUN_007bc980(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2 < 1) {
    piVar3 = (int *)FUN_007bbc50();
  }
  else {
    piVar3 = (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
  }
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 **)(param_1 + 8) = (undefined4 *)(iVar1 + -0x10);
  if ((*piVar3 == 6) && (iVar2 = piVar3[2], *(char *)(iVar2 + 6) == '\0')) {
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + -0x10);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + -0xc);
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar1 + -8);
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar1 + -4);
    return 1;
  }
  return 0;
}


// ==== FUN_007bc9f0 @ 0x007bc9f0 ====

void FUN_007bc9f0(void)

{
  FUN_007bd9d0();
  return;
}


// ==== FUN_007bca30 @ 0x007bca30 ====

void FUN_007bca30(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int local_8;
  undefined4 local_4;
  
  if (param_4 == 0) {
    iVar1 = 0;
  }
  else {
    if (param_4 < 1) {
      iVar1 = FUN_007bbc50();
    }
    else {
      iVar1 = *(int *)(param_1 + 0xc) + -0x10 + param_4 * 0x10;
    }
    iVar1 = iVar1 - *(int *)(param_1 + 0x1c);
  }
  local_8 = *(int *)(param_1 + 8) + (param_2 + 1) * -0x10;
  local_4 = param_3;
  FUN_007bdda0(param_1,&LAB_007bca10,&local_8,local_8 - *(int *)(param_1 + 0x1c),iVar1);
  return;
}


// ==== FUN_007bcaa0 @ 0x007bcaa0 ====

void FUN_007bcaa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined *param_4)

{
  int iVar1;
  undefined1 local_14 [20];
  
  if (param_4 == (undefined *)0x0) {
    param_4 = &DAT_009fe048;
  }
  FUN_007c2d70(local_14,param_2,param_3,param_4);
  iVar1 = FUN_007c2d20(local_14);
  FUN_007bdc70(param_1,local_14,iVar1 == 0x1b);
  return;
}


// ==== FUN_007bcaf0 @ 0x007bcaf0 ====

undefined4 FUN_007bcaf0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (((*(int *)(*(int *)(param_1 + 8) + -0x10) == 6) &&
      (iVar1 = *(int *)(*(int *)(param_1 + 8) + -8), *(char *)(iVar1 + 6) == '\0')) &&
     (*(char *)(iVar1 + 7) == '\0')) {
    FUN_007c33e0(param_1,*(undefined4 *)(iVar1 + 0xc),param_2,param_3);
    return 1;
  }
  return 0;
}


// ==== FUN_007bcb40 @ 0x007bcb40 ====

uint FUN_007bcb40(int param_1)

{
  return *(uint *)(*(int *)(param_1 + 0x10) + 0x20) >> 10;
}


// ==== FUN_007bcb50 @ 0x007bcb50 ====

uint FUN_007bcb50(int param_1)

{
  return *(uint *)(*(int *)(param_1 + 0x10) + 0x24) >> 10;
}


// ==== FUN_007bcb60 @ 0x007bcb60 ====

void FUN_007bcb60(int param_1,uint param_2)

{
  if (param_2 < 0x400000) {
    *(uint *)(*(int *)(param_1 + 0x10) + 0x20) = param_2 << 10;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x20) = 0xffffffff;
  }
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  return;
}


// ==== FUN_007bcba0 @ 0x007bcba0 ====

undefined4 FUN_007bcba0(undefined4 param_1)

{
  FUN_007be8c0(param_1);
  return 0;
}


// ==== FUN_007bcbb0 @ 0x007bcbb0 ====

void FUN_007bcbb0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 1) {
    iVar1 = FUN_007bbc50();
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10;
  }
  iVar1 = FUN_007c2810(param_1,*(undefined4 *)(iVar1 + 8),*(int *)(param_1 + 8) + -0x10);
  if (iVar1 == 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
    return;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bcc00 @ 0x007bcc00 ====

void FUN_007bcc00(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  if (1 < param_2) {
    FUN_007c0090(param_1,param_2,(*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4) + -1);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_2 * -0x10 + 0x10;
    return;
  }
  if (param_2 == 0) {
    puVar1 = *(undefined4 **)(param_1 + 8);
    *puVar1 = 4;
    uVar2 = FUN_007c1d70(param_1,0,0);
    puVar1[2] = uVar2;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  }
  return;
}


// ==== FUN_007bcc80 @ 0x007bcc80 ====

int FUN_007bcc80(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  iVar2 = FUN_007c1e00(param_1,param_2);
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar1[2] = iVar2;
  *puVar1 = 7;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return iVar2 + 0x10;
}


// ==== FUN_007bccd0 @ 0x007bccd0 ====

undefined1 * FUN_007bccd0(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  int in_ECX;
  int in_EDX;
  int *unaff_EDI;
  
  if (in_EAX < 1) {
    piVar3 = (int *)FUN_007bbc50();
  }
  else {
    piVar3 = (int *)(*(int *)(in_ECX + 0xc) + -0x10 + in_EAX * 0x10);
  }
  if (*piVar3 == 6) {
    iVar1 = piVar3[2];
    if (*(char *)(iVar1 + 6) == '\0') {
      iVar2 = *(int *)(iVar1 + 0xc);
      if (in_EDX <= *(int *)(iVar2 + 0x24)) {
        *unaff_EDI = *(int *)(*(int *)(iVar1 + 0x1c + in_EDX * 4) + 8);
        return (undefined1 *)(*(int *)(*(int *)(iVar2 + 0x1c) + -4 + in_EDX * 4) + 0x10);
      }
    }
    else if (in_EDX <= (int)(uint)*(byte *)(iVar1 + 7)) {
      *unaff_EDI = in_EDX * 0x10 + iVar1;
      return &DAT_0099cf70;
    }
  }
  return (undefined1 *)0x0;
}


// ==== FUN_007bcd30 @ 0x007bcd30 ====

void FUN_007bcd30(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  iVar2 = FUN_007bccd0();
  if (iVar2 != 0) {
    puVar1 = *(undefined4 **)(param_1 + 8);
    *puVar1 = *in_ECX;
    puVar1[2] = in_ECX[2];
    puVar1[3] = in_ECX[3];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  }
  return;
}


// ==== FUN_007bcd70 @ 0x007bcd70 ====

void FUN_007bcd70(int param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  
  iVar1 = FUN_007bccd0();
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = (undefined4 *)(iVar1 + -0x10);
    *in_ECX = *(undefined4 *)(iVar1 + -0x10);
    in_ECX[2] = *(undefined4 *)(iVar1 + -8);
    in_ECX[3] = *(undefined4 *)(iVar1 + -4);
  }
  return;
}


// ==== FUN_007bcdb0 @ 0x007bcdb0 ====

void FUN_007bcdb0(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FUN_007c3420();
  *(int *)(unaff_ESI + 0x1c) = iVar1;
  *(int *)(unaff_ESI + 8) = iVar1;
  *(undefined4 *)(unaff_ESI + 0x20) = 0x2d;
  *(int *)(unaff_ESI + 0x18) = iVar1 + 0x270;
  iVar1 = FUN_007c3420();
  *(int *)(unaff_ESI + 0x28) = iVar1;
  *(int *)(unaff_ESI + 0x14) = iVar1;
  *(undefined4 *)(iVar1 + 8) = 1;
  **(undefined4 **)(unaff_ESI + 8) = 0;
  iVar1 = *(int *)(unaff_ESI + 8) + 0x10;
  *(int *)(unaff_ESI + 8) = iVar1;
  **(int **)(unaff_ESI + 0x14) = iVar1;
  *(undefined4 *)(unaff_ESI + 0xc) = **(undefined4 **)(unaff_ESI + 0x14);
  (*(undefined4 **)(unaff_ESI + 0x14))[1] = *(int *)(unaff_ESI + 8) + 0x140;
  *(undefined2 *)(unaff_ESI + 0x2c) = 8;
  *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x28) + 0xc0;
  return;
}


// ==== FUN_007bce40 @ 0x007bce40 ====

void FUN_007bce40(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)FUN_007c3420(0,0,0,0xc0);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_007bd240(param_1,4);
  }
  *(undefined4 **)(param_1 + 0x10) = puVar1;
  puVar1[0x14] = param_1;
  puVar1[8] = 0;
  puVar1[2] = 0;
  puVar1[1] = 0;
  *puVar1 = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x40) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x30) = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[10] = FUN_004d8fb0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[0x16] = 0;
  puVar1[0x1a] = 0;
  puVar1[0x1e] = 0;
  puVar1[9] = 0x120;
  FUN_007bcdb0();
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x40) = 5;
  iVar3 = *(int *)(param_1 + 0x10);
  *(undefined4 *)(iVar3 + 0x40) = 5;
  uVar2 = FUN_007c24d0(param_1,0,0);
  *(undefined4 *)(iVar3 + 0x48) = uVar2;
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0x48);
  *(int *)(iVar3 + 8) = iVar3;
  *(undefined4 *)(param_1 + 0x40) = 5;
  uVar2 = FUN_007c24d0(param_1,0,4);
  *(undefined4 *)(param_1 + 0x48) = uVar2;
  iVar3 = *(int *)(param_1 + 0x10);
  *(undefined4 *)(iVar3 + 0x30) = 5;
  uVar2 = FUN_007c24d0(param_1,4,4);
  *(undefined4 *)(iVar3 + 0x38) = uVar2;
  FUN_007c1c30(param_1,0x20);
  FUN_007bf760(param_1);
  FUN_007c3520(param_1);
  iVar3 = FUN_007c1d70(param_1,s_not_enough_memory_009fe130,0x11);
  *(byte *)(iVar3 + 5) = *(byte *)(iVar3 + 5) | 0x10;
  puVar1[8] = *(int *)(*(int *)(param_1 + 0x10) + 0x24) << 2;
  return;
}


// ==== FUN_007bcf50 @ 0x007bcf50 ====

void FUN_007bcf50(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  FUN_007c1f30();
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    FUN_007bf560();
    FUN_007c1c10();
    uVar1 = FUN_007c3420();
    *(undefined4 *)(*(int *)(unaff_ESI + 0x10) + 0x18) = uVar1;
    *(undefined4 *)(*(int *)(unaff_ESI + 0x10) + 0x1c) = 0;
  }
  FUN_007c3420();
  FUN_007c3420();
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    FUN_007c3420(0,*(int *)(unaff_ESI + 0x10),0xc0,0);
  }
  FUN_007c3420(0);
  return;
}


// ==== FUN_007bcff0 @ 0x007bcff0 ====

int FUN_007bcff0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_007c3420(param_1,0,0,0x60);
  FUN_007bf730(param_1,iVar1,8);
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x58) = 0;
  *(undefined4 *)(iVar1 + 0x3c) = 0;
  *(undefined1 *)(iVar1 + 0x32) = 0;
  *(undefined1 *)(iVar1 + 0x30) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined1 *)(iVar1 + 0x31) = 1;
  *(undefined4 *)(iVar1 + 0x38) = 0;
  *(undefined4 *)(iVar1 + 0x50) = 0;
  *(undefined2 *)(iVar1 + 0x2c) = 0;
  *(undefined2 *)(iVar1 + 0x2e) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined4 *)(iVar1 + 0x40) = 0;
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  FUN_007bcdb0();
  *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  return iVar1;
}


// ==== FUN_007bd070 @ 0x007bd070 ====

void FUN_007bd070(undefined4 param_1,int param_2)

{
  FUN_007c1f30(param_2,*(undefined4 *)(param_2 + 0x1c));
  FUN_007c3420(param_1,*(undefined4 *)(param_2 + 0x28),(uint)*(ushort *)(param_2 + 0x2c) * 0x18,0);
  FUN_007c3420(param_1,*(undefined4 *)(param_2 + 0x1c),*(int *)(param_2 + 0x20) << 4,0);
  FUN_007c3420(param_1,param_2,0x60,0);
  return;
}


// ==== FUN_007bd0c0 @ 0x007bd0c0 ====

undefined4 * FUN_007bd0c0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_007c3420(0,0,0,0x60);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined1 *)(puVar1 + 1) = 8;
    *(undefined1 *)((int)puVar1 + 5) = 0;
    puVar1[0x15] = 0;
    *puVar1 = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[0x16] = 0;
    puVar1[0xf] = 0;
    *(undefined1 *)((int)puVar1 + 0x32) = 0;
    *(undefined1 *)(puVar1 + 0xc) = 0;
    puVar1[0xd] = 0;
    *(undefined1 *)((int)puVar1 + 0x31) = 1;
    puVar1[0xe] = 0;
    puVar1[0x14] = 0;
    *(undefined2 *)(puVar1 + 0xb) = 0;
    *(undefined2 *)((int)puVar1 + 0x2e) = 0;
    puVar1[5] = 0;
    puVar1[10] = 0;
    puVar1[0x17] = 0;
    puVar1[0x10] = 0;
    puVar1[4] = 0;
    iVar2 = FUN_007bd280(puVar1,FUN_007bce40,0);
    if (iVar2 == 0) {
      return puVar1;
    }
    FUN_007bcf50();
  }
  return (undefined4 *)0x0;
}


// ==== FUN_007bd150 @ 0x007bd150 ====

void FUN_007bd150(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x50);
  FUN_007c1f30(iVar1,*(undefined4 *)(iVar1 + 0x1c));
  FUN_007bed20(iVar1);
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  do {
    *(undefined4 **)(iVar1 + 0x14) = *(undefined4 **)(iVar1 + 0x28);
    uVar2 = **(undefined4 **)(iVar1 + 0x28);
    *(undefined4 *)(iVar1 + 8) = uVar2;
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
    *(undefined2 *)(iVar1 + 0x2e) = 0;
    iVar3 = FUN_007bd280(iVar1,&LAB_007bd140,0);
  } while (iVar3 != 0);
  FUN_007bcf50();
  return;
}


// ==== FUN_007bd1b0 @ 0x007bd1b0 ====

void FUN_007bd1b0(void)

{
  int iVar1;
  undefined4 in_EAX;
  undefined4 uVar2;
  undefined4 *in_ECX;
  int unaff_EDI;
  
  switch(in_EAX) {
  case 1:
  case 3:
    iVar1 = *(int *)(unaff_EDI + 8);
    *in_ECX = *(undefined4 *)(iVar1 + -0x10);
    in_ECX[2] = *(undefined4 *)(iVar1 + -8);
    in_ECX[3] = *(undefined4 *)(iVar1 + -4);
    break;
  case 4:
    *in_ECX = 4;
    uVar2 = FUN_007c1d70();
    in_ECX[2] = uVar2;
    *(undefined4 **)(unaff_EDI + 8) = in_ECX + 4;
    return;
  case 5:
    *in_ECX = 4;
    uVar2 = FUN_007c1d70();
    in_ECX[2] = uVar2;
    *(undefined4 **)(unaff_EDI + 8) = in_ECX + 4;
    return;
  }
  *(undefined4 **)(unaff_EDI + 8) = in_ECX + 4;
  return;
}


// ==== FUN_007bd240 @ 0x007bd240 ====

void FUN_007bd240(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x58) == 0) {
    (**(code **)(*(int *)(param_1 + 0x10) + 0x28))(param_1);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x44) = param_2;
                    /* WARNING: Subroutine does not return */
  _longjmp((int *)(*(int *)(param_1 + 0x58) + 4),1);
}


// ==== FUN_007bd280 @ 0x007bd280 ====

undefined4 FUN_007bd280(int param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_4c;
  undefined1 local_48 [64];
  undefined4 local_8;
  
  local_4c = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 **)(param_1 + 0x58) = &local_4c;
  local_8 = 0;
  iVar1 = __setjmp3(local_48,0);
  if (iVar1 == 0) {
    (*param_2)(param_1,param_3);
    *(undefined4 *)(param_1 + 0x58) = local_4c;
    return local_8;
  }
  *(undefined4 *)(param_1 + 0x58) = local_4c;
  return local_8;
}


// ==== FUN_007bd2e0 @ 0x007bd2e0 ====

void FUN_007bd2e0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  int *piVar2;
  int in_EDX;
  
  *(int *)(in_EAX + 8) = (*(int *)(in_EAX + 8) - in_EDX >> 4) * 0x10 + *(int *)(in_EAX + 0x1c);
  for (puVar1 = *(undefined4 **)(in_EAX + 0x50); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    puVar1[2] = (puVar1[2] - in_EDX >> 4) * 0x10 + *(int *)(in_EAX + 0x1c);
  }
  piVar2 = *(int **)(in_EAX + 0x28);
  if (piVar2 <= *(int **)(in_EAX + 0x14)) {
    do {
      piVar2[1] = (piVar2[1] - in_EDX >> 4) * 0x10 + *(int *)(in_EAX + 0x1c);
      *piVar2 = (*piVar2 - in_EDX >> 4) * 0x10 + *(int *)(in_EAX + 0x1c);
      piVar2 = piVar2 + 6;
    } while (piVar2 <= *(int **)(in_EAX + 0x14));
  }
  *(undefined4 *)(in_EAX + 0xc) = **(undefined4 **)(in_EAX + 0x14);
  return;
}


// ==== FUN_007bd360 @ 0x007bd360 ====

void FUN_007bd360(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_007c3420(param_1,*(undefined4 *)(param_1 + 0x1c),*(int *)(param_1 + 0x20) << 4,
                       param_2 << 4);
  *(int *)(param_1 + 0x20) = param_2;
  *(int *)(param_1 + 0x1c) = iVar1;
  *(int *)(param_1 + 0x18) = (param_2 + -6) * 0x10 + iVar1;
  FUN_007bd2e0();
  return;
}


// ==== FUN_007bd3b0 @ 0x007bd3b0 ====

void FUN_007bd3b0(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x28);
  iVar2 = FUN_007c3420(param_1,iVar1,(uint)*(ushort *)(param_1 + 0x2c) * 0x18,param_2 * 0x18);
  *(int *)(param_1 + 0x14) = iVar2 + ((*(int *)(param_1 + 0x14) - iVar1) / 0x18) * 0x18;
  *(short *)(param_1 + 0x2c) = (short)param_2;
  *(int *)(param_1 + 0x28) = iVar2;
  *(uint *)(param_1 + 0x24) = iVar2 + (param_2 & 0xffff) * 0x18;
  return;
}


// ==== FUN_007bd420 @ 0x007bd420 ====

void FUN_007bd420(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x20);
  if (iVar2 < param_2) {
    param_2 = iVar2 + 5 + param_2;
    iVar2 = FUN_007c3420(param_1,*(undefined4 *)(param_1 + 0x1c),iVar2 << 4,param_2 * 0x10);
    *(int *)(param_1 + 0x20) = param_2;
    *(int *)(param_1 + 0x18) = (param_2 + -6) * 0x10 + iVar2;
    *(int *)(param_1 + 0x1c) = iVar2;
    FUN_007bd2e0();
    return;
  }
  iVar1 = FUN_007c3420(param_1,*(undefined4 *)(param_1 + 0x1c),iVar2 << 4,iVar2 << 5);
  *(int *)(param_1 + 0x20) = iVar2 * 2;
  *(int *)(param_1 + 0x18) = (iVar2 * 2 + -6) * 0x10 + iVar1;
  *(int *)(param_1 + 0x1c) = iVar1;
  FUN_007bd2e0();
  return;
}


// ==== FUN_007bd4a0 @ 0x007bd4a0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007bd4a0(int param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_64 [5];
  undefined4 local_50;
  int local_8;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  pcVar1 = *(code **)(param_1 + 0x3c);
  if ((pcVar1 != (code *)0x0) && (*(char *)(param_1 + 0x31) != '\0')) {
    iVar2 = *(int *)(param_1 + 0x1c);
    iVar3 = *(int *)(param_1 + 8);
    iVar4 = *(int *)(*(int *)(param_1 + 0x14) + 4);
    local_64[0] = param_2;
    local_50 = param_3;
    if (param_2 == 4) {
      local_8 = 0;
    }
    else {
      local_8 = (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x28)) / 0x18;
    }
    if (*(int *)(param_1 + 0x18) - iVar3 < 0x141) {
      FUN_007bd420(param_1,0x14);
    }
    *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 8) + 0x140;
    *(undefined1 *)(param_1 + 0x31) = 0;
    (*pcVar1)(param_1,local_64);
    *(undefined1 *)(param_1 + 0x31) = 1;
    *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 0x1c) + (iVar4 - iVar2);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 0x1c) + (iVar3 - iVar2);
  }
  return;
}


// ==== FUN_007bd580 @ 0x007bd580 ====

void FUN_007bd580(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_EDX;
  int iVar3;
  int unaff_ESI;
  int iVar4;
  undefined4 *puVar5;
  
  iVar3 = *(int *)(unaff_ESI + 8) - in_EDX >> 4;
  if (iVar3 < param_1) {
    iVar4 = param_1 - iVar3;
    if (*(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 8) <= iVar4 * 0x10) {
      FUN_007bd420();
    }
    iVar3 = iVar3 + iVar4;
    do {
      **(undefined4 **)(unaff_ESI + 8) = 0;
      iVar4 = iVar4 + -1;
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
    } while (iVar4 != 0);
  }
  iVar3 = iVar3 - param_1;
  uVar1 = FUN_007c24d0();
  iVar4 = 0;
  if (0 < iVar3) {
    param_1 = iVar3 * -0x10;
    do {
      iVar4 = iVar4 + 1;
      puVar5 = (undefined4 *)(*(int *)(unaff_ESI + 8) + param_1);
      puVar2 = (undefined4 *)FUN_007c2c90();
      *puVar2 = *puVar5;
      puVar2[2] = puVar5[2];
      puVar2[3] = puVar5[3];
      param_1 = param_1 + 0x10;
    } while (iVar4 < iVar3);
  }
  FUN_007c1d70();
  puVar2 = (undefined4 *)FUN_007c2710();
  *puVar2 = 3;
  *(double *)(puVar2 + 2) = (double)iVar3;
  puVar2 = (undefined4 *)(*(int *)(unaff_ESI + 8) + iVar3 * -0x10);
  *(undefined4 **)(unaff_ESI + 8) = puVar2;
  puVar2[2] = uVar1;
  *puVar2 = 5;
  if (*(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 8) < 0x11) {
    FUN_007bd420();
  }
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  return;
}


// ==== FUN_007bd6c0 @ 0x007bd6c0 ====

void FUN_007bd6c0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  piVar2 = (int *)FUN_007bf7f0();
  iVar1 = *(int *)(unaff_ESI + 0x1c);
  if (*piVar2 != 6) {
    FUN_007beb70();
  }
  for (puVar3 = *(undefined4 **)(unaff_ESI + 8); unaff_EDI < puVar3; puVar3 = puVar3 + -4) {
    *puVar3 = puVar3[-4];
    puVar3[2] = puVar3[-2];
    puVar3[3] = puVar3[-1];
  }
  if (*(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 8) < 0x11) {
    FUN_007bd420();
  }
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  piVar4 = (int *)((int)unaff_EDI + (*(int *)(unaff_ESI + 0x1c) - iVar1));
  *piVar4 = *piVar2;
  piVar4[2] = piVar2[2];
  piVar4[3] = piVar2[3];
  return;
}


// ==== FUN_007bd750 @ 0x007bd750 ====

int FUN_007bd750(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x1c);
  piVar3 = param_2;
  if (*param_2 != 6) {
    piVar3 = (int *)FUN_007bd6c0();
  }
  if (*(int *)(param_1 + 0x14) + 0x18 == *(int *)(param_1 + 0x24)) {
    uVar4 = (uint)*(ushort *)(param_1 + 0x2c);
    if (0x1000 < *(ushort *)(param_1 + 0x2c)) {
      uVar4 = FUN_007bd240(param_1,5);
    }
    FUN_007bd3b0(param_1,(uVar4 & 0xffff) << 1);
    if (0x1000 < *(ushort *)(param_1 + 0x2c)) {
      FUN_007be950(param_1,s_stack_overflow_009fe15c);
    }
  }
  if (*(char *)(piVar3[2] + 6) == '\0') {
    iVar1 = *(int *)(piVar3[2] + 0xc);
    if (*(char *)(iVar1 + 0x46) != '\0') {
      FUN_007bd580(*(undefined1 *)(iVar1 + 0x45));
    }
    if (*(int *)(param_1 + 0x18) - *(int *)(param_1 + 8) <=
        (int)((uint)*(byte *)(iVar1 + 0x47) * 0x10)) {
      FUN_007bd420(param_1,(uint)*(byte *)(iVar1 + 0x47));
    }
    iVar2 = *(int *)(param_1 + 0x14);
    *(int **)(param_1 + 0x14) = (int *)(iVar2 + 0x18);
    *(int *)(iVar2 + 0x18) = (int)param_2 + ((*(int *)(param_1 + 0x1c) + 0x10) - iVar5);
    iVar5 = **(int **)(param_1 + 0x14);
    *(int *)(param_1 + 0xc) = iVar5;
    *(uint *)(iVar2 + 0x1c) = (uint)*(byte *)(iVar1 + 0x47) * 0x10 + iVar5;
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar2 + 0x2c) = 0;
    *(undefined4 *)(iVar2 + 0x20) = 8;
    if (*(uint *)(param_1 + 8) < *(uint *)(iVar2 + 0x1c)) {
      do {
        **(undefined4 **)(param_1 + 8) = 0;
        uVar4 = *(int *)(param_1 + 8) + 0x10;
        *(uint *)(param_1 + 8) = uVar4;
      } while (uVar4 < *(uint *)(iVar2 + 0x1c));
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar2 + 0x1c);
    return 0;
  }
  if (*(int *)(param_1 + 0x18) - *(int *)(param_1 + 8) < 0x141) {
    FUN_007bd420(param_1,0x14);
  }
  iVar1 = *(int *)(param_1 + 0x14);
  *(int **)(param_1 + 0x14) = (int *)(iVar1 + 0x18);
  *(int *)(iVar1 + 0x18) = (int)param_2 + ((*(int *)(param_1 + 0x1c) + 0x10) - iVar5);
  *(undefined4 *)(param_1 + 0xc) = **(undefined4 **)(param_1 + 0x14);
  *(int *)(iVar1 + 0x1c) = *(int *)(param_1 + 8) + 0x140;
  *(undefined4 *)(iVar1 + 0x20) = 1;
  if ((*(byte *)(param_1 + 0x30) & 1) != 0) {
    FUN_007bd4a0(param_1,0,0xffffffff);
  }
  iVar5 = (**(code **)(*(int *)(*(int *)(param_1 + 0xc) + -8) + 0xc))(param_1);
  return *(int *)(param_1 + 8) + iVar5 * -0x10;
}


// ==== FUN_007bd8f0 @ 0x007bd8f0 ====

int FUN_007bd8f0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_EAX;
  int unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI + 0x1c);
  FUN_007bd4a0();
  if ((*(byte *)(*(int *)(unaff_ESI + 0x14) + 8) & 1) == 0) {
    iVar3 = *(int *)(*(int *)(unaff_ESI + 0x14) + 0x14);
    while (iVar3 != 0) {
      *(int *)(*(int *)(unaff_ESI + 0x14) + 0x14) = *(int *)(*(int *)(unaff_ESI + 0x14) + 0x14) + -1
      ;
      FUN_007bd4a0();
      iVar3 = *(int *)(*(int *)(unaff_ESI + 0x14) + 0x14);
    }
    piVar1 = (int *)(*(int *)(unaff_ESI + 0x14) + 0x14);
    *piVar1 = *piVar1 + -1;
  }
  return *(int *)(unaff_ESI + 0x1c) + (in_EAX - iVar2);
}


// ==== FUN_007bd950 @ 0x007bd950 ====

void FUN_007bd950(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(byte *)(param_1 + 0x30) & 2) != 0) {
    param_3 = (undefined4 *)FUN_007bd8f0();
  }
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0x14) + -0x18);
  *(undefined4 **)(param_1 + 0x14) = puVar3;
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc) + -0x10);
  *(undefined4 *)(param_1 + 0xc) = *puVar3;
  if (param_2 != 0) {
    do {
      if (*(undefined4 **)(param_1 + 8) <= param_3) break;
      *puVar1 = *param_3;
      puVar1[2] = param_3[2];
      puVar3 = param_3 + 3;
      param_3 = param_3 + 4;
      puVar2 = puVar1 + 4;
      param_2 = param_2 + -1;
      puVar1[3] = *puVar3;
      puVar1 = puVar2;
    } while (param_2 != 0);
    if (0 < param_2) {
      do {
        *puVar1 = 0;
        puVar1 = puVar1 + 4;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  *(undefined4 **)(param_1 + 8) = puVar1;
  return;
}


// ==== FUN_007bd9d0 @ 0x007bd9d0 ====

void FUN_007bd9d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  code *pcVar2;
  int iVar3;
  
  *(short *)(param_1 + 0x2e) = *(short *)(param_1 + 0x2e) + 1;
  uVar1 = *(ushort *)(param_1 + 0x2e);
  if (199 < uVar1) {
    if (uVar1 == 200) {
      FUN_007be950(param_1,s_C_stack_overflow_009fe16c);
    }
    else if (0xe0 < uVar1) {
      FUN_007bd240(param_1,5);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  iVar3 = FUN_007bd750(param_1,param_2);
  if (iVar3 == 0) {
    iVar3 = FUN_007c04b0(param_1);
  }
  FUN_007bd950(param_1,param_3,iVar3);
  *(short *)(param_1 + 0x2e) = *(short *)(param_1 + 0x2e) + -1;
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  return;
}


// ==== FUN_007bdb10 @ 0x007bdb10 ====

undefined4 FUN_007bdb10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (*(short *)(param_1 + 0x2e) != 0) {
    FUN_007be950(param_1,s_attempt_to_yield_across_metameth_009fe1e4);
  }
  if ((*(byte *)(iVar1 + 8) & 1) == 0) {
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 0x10;
    return 0xffffffff;
  }
  if ((*(byte *)(iVar1 + -0x10) & 1) != 0) {
    FUN_007be950(param_1,s_cannot_yield_a_C_function_009fe1c8);
  }
  iVar2 = param_2 * 0x10;
  if (*(uint *)(param_1 + 0xc) < (uint)(*(int *)(param_1 + 8) + param_2 * -0x10)) {
    if (0 < param_2) {
      iVar6 = 0;
      iVar5 = param_2 * -0x10;
      do {
        iVar3 = *(int *)(param_1 + 8) + iVar5;
        puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar6);
        *puVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + iVar5);
        puVar4[2] = *(undefined4 *)(iVar3 + 8);
        iVar6 = iVar6 + 0x10;
        iVar5 = iVar5 + 0x10;
        param_2 = param_2 + -1;
        puVar4[3] = *(undefined4 *)(iVar3 + 0xc);
      } while (param_2 != 0);
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + iVar2;
  }
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 0x10;
  return 0xffffffff;
}


// ==== FUN_007bdbe0 @ 0x007bdbe0 ====

void FUN_007bdbe0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
    FUN_007bf6e0(param_1);
  }
  if (param_2[3] == 0) {
    uVar2 = FUN_007c7720(param_1,*param_2,param_2 + 1);
  }
  else {
    uVar2 = FUN_007c8250(param_1,*param_2,param_2 + 1);
  }
  iVar3 = FUN_007c1e80(param_1,0,param_1 + 0x40);
  *(undefined4 *)(iVar3 + 0xc) = uVar2;
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = 6;
  puVar1[2] = iVar3;
  if (*(int *)(param_1 + 0x18) - *(int *)(param_1 + 8) < 0x11) {
    FUN_007bd420(param_1,1);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}


// ==== FUN_007bdc70 @ 0x007bdc70 ====

int FUN_007bdc70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = param_2;
  local_4 = param_3;
  local_c = 0;
  local_8 = 0;
  iVar1 = FUN_007bd280(param_1,FUN_007bdbe0,&local_10);
  local_c = FUN_007c3420(param_1,local_c,local_8,0);
  local_8 = 0;
  if (iVar1 != 0) {
    FUN_007bd1b0();
  }
  return iVar1;
}


// ==== FUN_007bdcf0 @ 0x007bdcf0 ====

void FUN_007bdcf0(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x20) * 0x10 + -0x10 + *(int *)(in_ECX + 0x1c);
  if ((0x1000 < *(ushort *)(in_ECX + 0x2c)) &&
     ((*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x28)) / 0x18 + 1 < 0x1000)) {
    FUN_007bd3b0();
  }
  return;
}


// ==== FUN_007bdd40 @ 0x007bdd40 ====

int FUN_007bdd40(int param_1,undefined1 param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(undefined1 *)(param_1 + 0x31);
  iVar3 = FUN_007bd280(param_1,&LAB_007bda50,&param_2);
  if (iVar3 != 0) {
    *(undefined4 **)(param_1 + 0x14) = *(undefined4 **)(param_1 + 0x28);
    uVar2 = **(undefined4 **)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0xc) = uVar2;
    *(undefined2 *)(param_1 + 0x2e) = 0;
    FUN_007c1f30(param_1,uVar2);
    FUN_007bd1b0();
    *(undefined1 *)(param_1 + 0x31) = uVar1;
    FUN_007bdcf0();
  }
  return iVar3;
}


// ==== FUN_007bdda0 @ 0x007bdda0 ====

int FUN_007bdda0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  
  uVar2 = *(undefined2 *)(param_1 + 0x2e);
  uVar1 = *(undefined1 *)(param_1 + 0x31);
  iVar3 = *(int *)(param_1 + 0x28);
  iVar4 = *(int *)(param_1 + 0x14);
  uVar5 = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x5c) = param_5;
  iVar6 = FUN_007bd280(param_1,param_2,param_3);
  if (iVar6 == 0) {
    *(undefined4 *)(param_1 + 0x5c) = uVar5;
    return 0;
  }
  FUN_007c1f30(param_1,*(int *)(param_1 + 0x1c) + param_4);
  FUN_007bd1b0();
  puVar7 = (undefined4 *)(*(int *)(param_1 + 0x28) + (iVar4 - iVar3));
  *(undefined2 *)(param_1 + 0x2e) = uVar2;
  *(undefined4 **)(param_1 + 0x14) = puVar7;
  *(undefined4 *)(param_1 + 0xc) = *puVar7;
  *(undefined1 *)(param_1 + 0x31) = uVar1;
  FUN_007bdcf0();
  *(undefined4 *)(param_1 + 0x5c) = uVar5;
  return iVar6;
}


// ==== FUN_007bde50 @ 0x007bde50 ====

undefined4 FUN_007bde50(void)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  
  if ((in_EAX[2] & 1U) == 0) {
    if ((in_EAX[2] & 2U) != 0) {
      in_EAX[3] = *(int *)in_EAX[4];
    }
    iVar1 = *(int *)(*(int *)(*in_EAX + -8) + 0xc);
    iVar2 = (in_EAX[3] - *(int *)(iVar1 + 0xc) >> 2) + -1;
    if (-1 < iVar2) {
      iVar1 = *(int *)(iVar1 + 0x14);
      if (iVar1 == 0) {
        return 0;
      }
      return *(undefined4 *)(iVar1 + iVar2 * 4);
    }
  }
  return 0xffffffff;
}


// ==== FUN_007bde90 @ 0x007bde90 ====

void FUN_007bde90(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (iVar1 != *(int *)(param_1 + 0x28)) {
    do {
      if (((*(uint *)(iVar1 + 8) & 1) == 0) && ((*(uint *)(iVar1 + 8) & 2) != 0)) {
        *(undefined4 *)(iVar1 + 0xc) = **(undefined4 **)(iVar1 + 0x10);
      }
      iVar1 = iVar1 + -0x18;
    } while (iVar1 != *(int *)(param_1 + 0x28));
  }
  *(undefined1 *)(param_1 + 0x32) = 1;
  return;
}


// ==== FUN_007bded0 @ 0x007bded0 ====

undefined4 FUN_007bded0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  if ((param_2 == 0) || (param_3 == 0)) {
    param_3 = 0;
    param_2 = 0;
  }
  *(int *)(param_1 + 0x3c) = param_2;
  *(undefined4 *)(param_1 + 0x34) = param_4;
  *(undefined4 *)(param_1 + 0x38) = param_4;
  *(char *)(param_1 + 0x30) = (char)param_3;
  *(undefined1 *)(param_1 + 0x32) = 0;
  return 1;
}


// ==== FUN_007bdf10 @ 0x007bdf10 ====

undefined4 FUN_007bdf10(int param_1)

{
  return *(undefined4 *)(param_1 + 0x3c);
}


// ==== FUN_007bdf20 @ 0x007bdf20 ====

undefined1 FUN_007bdf20(int param_1)

{
  return *(undefined1 *)(param_1 + 0x30);
}


// ==== FUN_007bdf30 @ 0x007bdf30 ====

undefined4 FUN_007bdf30(int param_1)

{
  return *(undefined4 *)(param_1 + 0x34);
}


// ==== FUN_007bdf40 @ 0x007bdf40 ====

undefined4 FUN_007bdf40(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if (0 < param_2) {
    do {
      if (uVar1 <= *(uint *)(param_1 + 0x28)) {
        if (0 < param_2) {
          return 0;
        }
        break;
      }
      param_2 = param_2 + -1;
      if ((*(byte *)(uVar1 + 8) & 1) == 0) {
        param_2 = param_2 - *(int *)(uVar1 + 0x14);
      }
      uVar1 = uVar1 - 0x18;
    } while (0 < param_2);
  }
  if (uVar1 == *(uint *)(param_1 + 0x28)) {
    return 0;
  }
  if (param_2 < 0) {
    *(undefined4 *)(param_3 + 0x5c) = 0;
    return 1;
  }
  *(int *)(param_3 + 0x5c) = (int)(uVar1 - *(uint *)(param_1 + 0x28)) / 0x18;
  return 1;
}


// ==== FUN_007bdfc0 @ 0x007bdfc0 ====

int FUN_007bdfc0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = *(uint *)(*(int *)(param_1 + 0x28) + 8 + *(int *)(param_2 + 0x5c) * 0x18);
  piVar1 = (int *)(*(int *)(param_1 + 0x28) + *(int *)(param_2 + 0x5c) * 0x18);
  iVar4 = 0;
  if ((uVar2 & 1) == 0) {
    iVar3 = *(int *)(*(int *)(*piVar1 + -8) + 0xc);
    if (iVar3 != 0) {
      if ((uVar2 & 2) != 0) {
        piVar1[3] = *(int *)piVar1[4];
      }
      iVar4 = FUN_007c20c0(iVar3,param_3,
                           (piVar1[3] - *(int *)(*(int *)(*(int *)(*piVar1 + -8) + 0xc) + 0xc) >> 2)
                           + -1);
      if (iVar4 != 0) {
        FUN_007bbca0(param_1,param_3 * 0x10 + -0x10 + *piVar1);
      }
    }
  }
  return iVar4;
}


// ==== FUN_007be040 @ 0x007be040 ====

char * FUN_007be040(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x28) + *(int *)(param_2 + 0x5c) * 0x18);
  if ((*(byte *)(piVar1 + 2) & 1) == 0) {
    iVar6 = *(int *)(*(int *)(*piVar1 + -8) + 0xc);
  }
  else {
    iVar6 = 0;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  if (iVar6 != 0) {
    if ((piVar1[2] & 1U) == 0) {
      if ((piVar1[2] & 2U) != 0) {
        piVar1[3] = *(int *)piVar1[4];
      }
      iVar4 = (piVar1[3] - *(int *)(*(int *)(*(int *)(*piVar1 + -8) + 0xc) + 0xc) >> 2) + -1;
    }
    else {
      iVar4 = -1;
    }
    pcVar5 = (char *)FUN_007c20c0(iVar6,param_3,iVar4);
    if ((pcVar5 != (char *)0x0) && (*pcVar5 != '(')) {
      puVar3 = *(undefined4 **)(param_1 + 8);
      puVar2 = (undefined4 *)(param_3 * 0x10 + -0x10 + *piVar1);
      *puVar2 = *puVar3;
      puVar2[2] = puVar3[2];
      puVar2[3] = puVar3[3];
      return pcVar5;
    }
  }
  return (char *)0x0;
}


// ==== FUN_007be0f0 @ 0x007be0f0 ====

void FUN_007be0f0(void)

{
  int iVar1;
  int in_EAX;
  undefined *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_EAX + 8);
  if (*(char *)(iVar1 + 6) != '\0') {
    *(undefined **)(in_ECX + 0x10) = &DAT_009fe228;
    *(undefined4 *)(in_ECX + 0x1c) = 0xffffffff;
    *(undefined1 **)(in_ECX + 0xc) = &DAT_009fe224;
    FUN_007c1ac0(in_ECX + 0x20,*(undefined4 *)(in_ECX + 0x10),0x3c);
    return;
  }
  *(int *)(in_ECX + 0x10) = *(int *)(*(int *)(iVar1 + 0xc) + 0x20) + 0x10;
  iVar1 = *(int *)(*(int *)(iVar1 + 0xc) + 0x3c);
  *(int *)(in_ECX + 0x1c) = iVar1;
  puVar2 = &DAT_009fe21c;
  if (iVar1 != 0) {
    puVar2 = &DAT_009fe218;
  }
  *(undefined **)(in_ECX + 0xc) = puVar2;
  FUN_007c1ac0(in_ECX + 0x20,*(undefined4 *)(in_ECX + 0x10),0x3c);
  return;
}


// ==== FUN_007be160 @ 0x007be160 ====

int FUN_007be160(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = *(int *)(in_EAX + 0x48);
  iVar5 = 1 << (*(byte *)(iVar1 + 7) & 0x1f);
  if (iVar5 != 0) {
    iVar3 = iVar5 * 0x28;
    do {
      iVar3 = iVar3 + -0x28;
      piVar4 = (int *)(*(int *)(iVar1 + 0x10) + iVar3);
      iVar5 = iVar5 + -1;
      iVar2 = FUN_007c16c0(param_1,piVar4 + 4);
      if ((iVar2 != 0) && (*piVar4 == 4)) {
        return piVar4[2] + 0x10;
      }
    } while (iVar5 != 0);
  }
  return 0;
}


// ==== FUN_007be1c0 @ 0x007be1c0 ====

void FUN_007be1c0(int param_1)

{
  int unaff_ESI;
  
  *(undefined1 **)(unaff_ESI + 8) = &DAT_0099cf70;
  *(undefined1 **)(unaff_ESI + 4) = &DAT_0099cf70;
  *(undefined4 *)(unaff_ESI + 0x14) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0xffffffff;
  *(undefined **)(unaff_ESI + 0xc) = &DAT_009fe230;
  *(char **)(unaff_ESI + 0x10) = s___tail_call__009fe238;
  FUN_007c1ac0(unaff_ESI + 0x20,s___tail_call__009fe238,0x3c);
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  **(undefined4 **)(param_1 + 8) = 0;
  return;
}


// ==== FUN_007be210 @ 0x007be210 ====

bool FUN_007be210(void)

{
  uint uVar1;
  int in_EAX;
  uint uVar2;
  int in_EDX;
  
  uVar1 = *(uint *)(*(int *)(in_EAX + 0xc) + 4 + in_EDX * 4);
  uVar2 = uVar1 & 0x3f;
  if (0x18 < uVar2) {
    if (uVar2 < 0x1c) {
      return (uVar1 & 0xff8000) == 0;
    }
    if (uVar2 == 0x20) {
      return true;
    }
  }
  return false;
}


// ==== FUN_007be240 @ 0x007be240 ====

undefined4 FUN_007be240(void)

{
  int in_EAX;
  int in_ECX;
  
  if ((in_EAX < (int)(uint)*(byte *)(in_ECX + 0x47)) ||
     ((0xf9 < in_EAX && (in_EAX + -0xfa < *(int *)(in_ECX + 0x28))))) {
    return 1;
  }
  return 0;
}


// ==== FUN_007be270 @ 0x007be270 ====

undefined4 FUN_007be270(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined8 uVar13;
  int local_18;
  int local_10;
  
  iVar2 = *(int *)(param_1 + 0x2c);
  local_10 = iVar2 + -1;
  if ((0xfa < *(byte *)(param_1 + 0x47)) ||
     (((*(int *)(param_1 + 0x30) != iVar2 && (*(int *)(param_1 + 0x30) != 0)) ||
      (iVar3 = *(int *)(param_1 + 0xc),
      ((byte)*(undefined4 *)(iVar3 + -4 + iVar2 * 4) & 0x3f) != 0x1b)))) {
    return 0;
  }
  local_18 = 0;
  if (0 < param_2) {
    uVar6 = (uint)*(byte *)(param_1 + 0x47);
    do {
      uVar5 = *(uint *)(iVar3 + local_18 * 4);
      uVar11 = uVar5 >> 0x18;
      uVar10 = 0;
      uVar9 = 0;
      if (uVar6 <= uVar11) {
        return 0;
      }
      bVar1 = s__a___a4A_009fec74[uVar5 & 0x3f];
      if ((bVar1 & 3) == 0) {
        uVar9 = uVar5 >> 6 & 0x1ff;
        uVar10 = uVar5 >> 0xf & 0x1ff;
        if ((bVar1 & 4) == 0) {
          if (((bVar1 & 8) != 0) && (iVar4 = FUN_007be240(), iVar4 == 0)) {
            return 0;
          }
        }
        else if (uVar6 <= uVar10) {
          return 0;
        }
        if (((bVar1 & 0x10) != 0) && (uVar6 <= uVar9)) {
          if (uVar9 < 0xfa) {
            return 0;
          }
          bVar12 = SBORROW4(uVar9 - 0xfa,*(int *)(param_1 + 0x28));
          iVar4 = (uVar9 - 0xfa) - *(int *)(param_1 + 0x28);
LAB_007be39e:
          if (bVar12 == iVar4 < 0) {
            return 0;
          }
        }
      }
      else if ((bVar1 & 3) == 1) {
        uVar10 = uVar5 >> 6 & 0x3ffff;
        if ((bVar1 & 0x40) != 0) {
          bVar12 = SBORROW4(uVar10,*(int *)(param_1 + 0x28));
          iVar4 = uVar10 - *(int *)(param_1 + 0x28);
          goto LAB_007be39e;
        }
      }
      else if ((bVar1 & 3) == 2) {
        uVar10 = (uVar5 >> 6 & 0x3ffff) - 0x1ffff;
      }
      if (((bVar1 & 0x20) != 0) && (uVar11 == param_3)) {
        local_10 = local_18;
      }
      if ((char)bVar1 < '\0') {
        if (iVar2 <= local_18 + 2) {
          return 0;
        }
        if (((byte)*(undefined4 *)(iVar3 + 4 + local_18 * 4) & 0x3f) != 0x14) {
          return 0;
        }
      }
      switch(uVar5 & 0x3f) {
      case 2:
        if ((uVar9 != 0) && (iVar2 <= local_18 + 2)) {
          return 0;
        }
        break;
      case 3:
        if (((int)uVar11 <= (int)param_3) && ((int)param_3 <= (int)uVar10)) {
          local_10 = local_18;
        }
        break;
      case 4:
      case 8:
        uVar9 = (uint)*(byte *)(param_1 + 0x44);
        goto joined_r0x007be485;
      case 5:
      case 7:
        if (*(int *)(uVar10 * 0x10 + *(int *)(param_1 + 8)) != 4) {
          return 0;
        }
        break;
      case 0xb:
        if (uVar6 <= uVar11 + 1) {
          return 0;
        }
        if (param_3 == uVar11 + 1) {
          local_10 = local_18;
        }
        break;
      case 0x13:
        if (0xf9 < uVar9) {
          return 0;
        }
joined_r0x007be485:
        if ((int)uVar9 <= (int)uVar10) {
          return 0;
        }
        break;
      case 0x19:
      case 0x1a:
        if ((uVar10 != 0) && ((int)uVar6 <= (int)((uVar10 - 1) + uVar11))) {
          return 0;
        }
        iVar4 = uVar9 - 1;
        if (iVar4 == -1) {
          uVar13 = FUN_007be210();
          iVar7 = (int)((ulonglong)uVar13 >> 0x20);
          if ((int)uVar13 == 0) {
            return 0;
          }
        }
        else {
          iVar7 = local_18;
          if ((iVar4 != 0) && ((int)uVar6 <= (int)((uVar11 - 1) + iVar4))) {
            return 0;
          }
        }
        if ((int)uVar11 <= (int)param_3) {
          local_10 = iVar7;
        }
        break;
      case 0x1b:
        if ((0 < (int)(uVar10 - 1)) && ((int)uVar6 <= (int)((uVar10 - 2) + uVar11))) {
          return 0;
        }
        break;
      case 0x1d:
        if (uVar6 <= uVar11 + 5 + uVar9) {
          return 0;
        }
        if ((int)uVar11 <= (int)param_3) {
          local_10 = local_18;
        }
      case 0x1c:
        if (uVar6 <= uVar11 + 2) {
          return 0;
        }
      case 0x14:
        iVar4 = uVar10 + 1 + local_18;
        if (iVar4 < 0) {
          return 0;
        }
        if (iVar2 <= iVar4) {
          return 0;
        }
        if (((param_3 != 0xff) && (local_18 < iVar4)) && (iVar4 <= param_2)) {
          local_18 = uVar10 + local_18;
        }
        break;
      case 0x1f:
        if (uVar6 <= (uVar10 & 0x1f) + 1 + uVar11) {
          return 0;
        }
        break;
      case 0x22:
        if (*(int *)(param_1 + 0x34) <= (int)uVar10) {
          return 0;
        }
        uVar5 = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + uVar10 * 4) + 0x44);
        if (iVar2 <= (int)(uVar5 + local_18)) {
          return 0;
        }
        if (uVar5 != 0) {
          puVar8 = (uint *)(iVar3 + (uVar5 + local_18) * 4);
          do {
            if (((*puVar8 & 0x3f) != 4) && ((*puVar8 & 0x3f) != 0)) {
              return 0;
            }
            uVar5 = uVar5 - 1;
            puVar8 = puVar8 + -1;
          } while (0 < (int)uVar5);
        }
      }
      local_18 = local_18 + 1;
    } while (local_18 < param_2);
  }
  return *(undefined4 *)(iVar3 + local_10 * 4);
}


// ==== FUN_007be630 @ 0x007be630 ====

void FUN_007be630(int param_1)

{
  FUN_007be270(param_1,*(undefined4 *)(param_1 + 0x2c),0xff);
  return;
}


// ==== FUN_007be650 @ 0x007be650 ====

undefined * FUN_007be650(void)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  
  if ((in_EAX + -0xfa < 0) ||
     (iVar1 = (in_EAX + -0xfa) * 0x10, *(int *)(iVar1 + *(int *)(in_ECX + 8)) != 4)) {
    return &DAT_009fe048;
  }
  return (undefined *)(*(int *)(iVar1 + *(int *)(in_ECX + 8) + 8) + 0x10);
}


// ==== FUN_007be680 @ 0x007be680 ====

char * FUN_007be680(uint param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *unaff_EBX;
  int iVar5;
  
  bVar1 = *(byte *)(unaff_EBX + 2);
  while ((bVar1 & 1) == 0) {
    iVar4 = *(int *)(*(int *)(*unaff_EBX + -8) + 0xc);
    if ((unaff_EBX[2] & 1U) == 0) {
      if ((unaff_EBX[2] & 2U) != 0) {
        unaff_EBX[3] = *(int *)unaff_EBX[4];
      }
      iVar5 = (unaff_EBX[3] - *(int *)(*(int *)(*(int *)(*unaff_EBX + -8) + 0xc) + 0xc) >> 2) + -1;
    }
    else {
      iVar5 = -1;
    }
    iVar2 = FUN_007c20c0(iVar4,param_1 + 1,iVar5);
    *param_2 = iVar2;
    if (iVar2 != 0) {
      return s_local_009fe258;
    }
    uVar3 = FUN_007be270(iVar4,iVar5,param_1);
    switch(uVar3 & 0x3f) {
    case 0:
      param_1 = uVar3 >> 0xf & 0x1ff;
      if (uVar3 >> 0x18 <= param_1) {
        return (char *)0x0;
      }
      bVar1 = *(byte *)(unaff_EBX + 2);
      break;
    default:
      goto switchD_007be6f5_caseD_1;
    case 5:
      *param_2 = *(int *)((uVar3 >> 6 & 0x3ffff) * 0x10 + 8 + *(int *)(iVar4 + 8)) + 0x10;
      return s_global_009fe250;
    case 6:
      iVar4 = FUN_007be650();
      *param_2 = iVar4;
      return s_field_009fe248;
    case 0xb:
      iVar4 = FUN_007be650();
      *param_2 = iVar4;
      return s_method_009fe06c;
    }
  }
switchD_007be6f5_caseD_1:
  return (char *)0x0;
}


// ==== FUN_007be7b0 @ 0x007be7b0 ====

undefined4 FUN_007be7b0(undefined4 param_1)

{
  uint uVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if ((((*(byte *)(in_EAX + 8) & 1) != 0) || (*(int *)(in_EAX + 0x14) < 1)) &&
     ((*(byte *)(in_EAX + -0x10) & 1) == 0)) {
    if ((*(uint *)(in_EAX + -0x10) & 1) == 0) {
      if ((*(uint *)(in_EAX + -0x10) & 2) != 0) {
        *(undefined4 *)(in_EAX + -0xc) = **(undefined4 **)(in_EAX + -8);
      }
      iVar2 = (*(int *)(in_EAX + -0xc) -
               *(int *)(*(int *)(*(int *)(*(int *)(in_EAX + -0x18) + -8) + 0xc) + 0xc) >> 2) + -1;
    }
    else {
      iVar2 = -1;
    }
    uVar1 = *(uint *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + -0x18) + -8) + 0xc) + 0xc) +
                     iVar2 * 4);
    uVar4 = uVar1 & 0x3f;
    if ((uVar4 == 0x19) || (uVar4 == 0x1a)) {
      uVar3 = FUN_007be680(uVar1 >> 0x18,param_1);
      return uVar3;
    }
  }
  return 0;
}


// ==== FUN_007be830 @ 0x007be830 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007be830(void)

{
  int *piVar1;
  int unaff_EDI;
  undefined1 local_40 [60];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  piVar1 = *(int **)(unaff_EDI + 0x14);
  if ((piVar1[2] & 1U) == 0) {
    if ((piVar1[2] & 2U) != 0) {
      piVar1[3] = *(int *)piVar1[4];
    }
    FUN_007c1ac0(local_40,*(int *)(*(int *)(*(int *)(*piVar1 + -8) + 0xc) + 0x20) + 0x10,0x3c);
    FUN_007c1aa0();
  }
  return;
}


// ==== FUN_007be8c0 @ 0x007be8c0 ====

void FUN_007be8c0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x5c) != 0) {
    piVar3 = (int *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x5c));
    if (*piVar3 != 6) {
      FUN_007bd240(param_1,5);
    }
    puVar1 = *(undefined4 **)(param_1 + 8);
    *puVar1 = puVar1[-4];
    puVar1[2] = puVar1[-2];
    puVar1[3] = puVar1[-1];
    iVar2 = *(int *)(param_1 + 8);
    *(int *)(iVar2 + -0x10) = *piVar3;
    *(int *)(iVar2 + -8) = piVar3[2];
    *(int *)(iVar2 + -4) = piVar3[3];
    if (*(int *)(param_1 + 0x18) - *(int *)(param_1 + 8) < 0x11) {
      FUN_007bd420(param_1,1);
    }
    iVar2 = *(int *)(param_1 + 8);
    *(int *)(param_1 + 8) = iVar2 + 0x10;
    FUN_007bd9d0(param_1,iVar2 + -0x10,1);
  }
  FUN_007bd240(param_1,1);
  return;
}


// ==== FUN_007be950 @ 0x007be950 ====

void FUN_007be950(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_007c17d0(param_1,param_2,&param_3);
  FUN_007be830(uVar1);
  FUN_007be8c0(param_1);
  return;
}


// ==== FUN_007be980 @ 0x007be980 ====

undefined4 FUN_007be980(int param_1,char *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBX;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  undefined4 local_4;
  
  cVar2 = *param_2;
  local_4 = 1;
  if (cVar2 == '\0') {
    return 1;
  }
  do {
    switch(cVar2) {
    case 'S':
      FUN_007be0f0();
      break;
    default:
      local_4 = 0;
      break;
    case 'f':
      puVar1 = *(undefined4 **)(param_1 + 8);
      *puVar1 = *unaff_EDI;
      puVar1[2] = unaff_EDI[2];
      puVar1[3] = unaff_EDI[3];
      break;
    case 'l':
      if (unaff_EBX == 0) {
        *(undefined4 *)(unaff_ESI + 0x14) = 0xffffffff;
      }
      else {
        uVar3 = FUN_007bde50();
        *(undefined4 *)(unaff_ESI + 0x14) = uVar3;
      }
      break;
    case 'n':
      if (unaff_EBX == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_007be7b0(unaff_ESI + 4);
      }
      *(int *)(unaff_ESI + 8) = iVar4;
      if (iVar4 == 0) {
        iVar4 = FUN_007be160();
        *(int *)(unaff_ESI + 4) = iVar4;
        if (iVar4 == 0) {
          *(undefined1 **)(unaff_ESI + 8) = &DAT_0099cf70;
        }
        else {
          *(char **)(unaff_ESI + 8) = s_global_009fe250;
        }
      }
      break;
    case 'u':
      *(uint *)(unaff_ESI + 0x18) = (uint)*(byte *)(unaff_EDI[2] + 7);
    }
    param_2 = param_2 + 1;
    cVar2 = *param_2;
  } while (cVar2 != '\0');
  return local_4;
}


// ==== FUN_007beab0 @ 0x007beab0 ====

undefined4 FUN_007beab0(int param_1,char *param_2,int param_3)

{
  char *pcVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*param_2 == '>') {
    if (*(int *)(*(int *)(param_1 + 8) + -0x10) != 6) {
      FUN_007be950(param_1,s_value_for__lua_getinfo__is_not_a_009fe26c);
    }
    uVar2 = FUN_007be980(param_1,param_2 + 1);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  }
  else if (*(int *)(param_3 + 0x5c) == 0) {
    FUN_007be1c0(param_1);
  }
  else {
    uVar2 = FUN_007be980(param_1,param_2);
  }
  pcVar1 = _strchr(param_2,0x66);
  if (pcVar1 != (char *)0x0) {
    if (*(int *)(param_1 + 0x18) - *(int *)(param_1 + 8) < 0x11) {
      FUN_007bd420(param_1,1);
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  }
  return uVar2;
}


// ==== FUN_007beb70 @ 0x007beb70 ====

void FUN_007beb70(int param_1,int *param_2,undefined4 param_3)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_4;
  
  puVar1 = (&PTR_PTR_009fe340)[*param_2];
  local_4 = 0;
  piVar2 = (int *)**(undefined4 **)(param_1 + 0x14);
  do {
    if ((int *)(*(undefined4 **)(param_1 + 0x14))[1] <= piVar2) {
LAB_007bebab:
      FUN_007be950(param_1,s_attempt_to__s_a__s_value_009fe2bc,param_3,puVar1);
      return;
    }
    if (param_2 == piVar2) {
      iVar3 = FUN_007be680((int)param_2 - *(int *)(param_1 + 0xc) >> 4,&local_4);
      if (iVar3 != 0) {
        FUN_007be950(param_1,s_attempt_to__s__s___s___a__s_valu_009fe298,param_3,iVar3,local_4,
                     puVar1);
        return;
      }
      goto LAB_007bebab;
    }
    piVar2 = piVar2 + 4;
  } while( true );
}


// ==== FUN_007bec00 @ 0x007bec00 ====

void FUN_007bec00(void)

{
  FUN_007beb70();
  return;
}


// ==== FUN_007bec20 @ 0x007bec20 ====

void FUN_007bec20(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_10 [16];
  
  iVar1 = FUN_007bf840(param_2,local_10);
  if (iVar1 != 0) {
    param_2 = param_3;
  }
  FUN_007beb70(param_1,param_2,s_perform_arithmetic_on_009fe2e4);
  return;
}


// ==== FUN_007bec60 @ 0x007bec60 ====

undefined4 FUN_007bec60(undefined4 param_1,int *param_2,int *param_3)

{
  undefined *puVar1;
  
  puVar1 = (&PTR_PTR_009fe340)[*param_2];
  if (puVar1[2] == (&PTR_PTR_009fe340)[*param_3][2]) {
    FUN_007be950(param_1,s_attempt_to_compare_two__s_values_009fe31c,puVar1);
    return 0;
  }
  FUN_007be950(param_1,s_attempt_to_compare__s_with__s_009fe2fc,puVar1,(&PTR_PTR_009fe340)[*param_3]
              );
  return 0;
}


// ==== FUN_007becb0 @ 0x007becb0 ====

void FUN_007becb0(void)

{
  int in_EAX;
  uint uVar1;
  int *in_EDX;
  
  *(byte *)(in_EAX + 5) = *(byte *)(in_EAX + 5) | 1;
  uVar1 = *(byte *)(in_EAX + 4) - 5;
  if (4 < uVar1) {
    return;
  }
  while( true ) {
    switch((&switchD_007becc0::switchdataD_007bed04)[uVar1]) {
    case (undefined *)0x7bece1:
      *(int *)(in_EAX + 8) = *in_EDX;
      *in_EDX = in_EAX;
      return;
    case (undefined *)0x7bece9:
      *(int *)(in_EAX + 0x18) = *in_EDX;
      *in_EDX = in_EAX;
      return;
    case (undefined *)0x7becf1:
      *(int *)(in_EAX + 0x54) = *in_EDX;
      *in_EDX = in_EAX;
      return;
    case (undefined *)0x7becf9:
      *(int *)(in_EAX + 0x40) = *in_EDX;
      *in_EDX = in_EAX;
      return;
    }
    in_EAX = *(int *)(in_EAX + 8);
    if ((*(byte *)(in_EAX + 5) & 0x11) != 0) break;
    *(byte *)(in_EAX + 5) = *(byte *)(in_EAX + 5) | 1;
    uVar1 = *(byte *)(in_EAX + 4) - 5;
    if (4 < uVar1) {
      return;
    }
  }
  return;
}


// ==== FUN_007bed20 @ 0x007bed20 ====

void FUN_007bed20(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = param_1;
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x10) + 0x10);
  puVar5 = (undefined4 *)(*(int *)(param_1 + 0x10) + 0x10);
  param_1 = 0;
  puVar4 = &param_1;
  do {
    if (puVar1 == (undefined4 *)0x0) {
      *puVar4 = *(undefined4 *)(*(int *)(iVar2 + 0x10) + 0x14);
      *(int *)(*(int *)(iVar2 + 0x10) + 0x14) = param_1;
      return;
    }
    if (((*(byte *)((int)puVar1 + 5) & 0x11) == 0) && ((*(byte *)((int)puVar1 + 5) & 2) != 0)) {
      if (((*(byte *)(puVar1[2] + 6) & 4) != 0) ||
         (iVar3 = FUN_007bf7c0(puVar1[2],2,*(undefined4 *)(*(int *)(iVar2 + 0x10) + 0x88)),
         iVar3 == 0)) {
        *(byte *)((int)puVar1 + 5) = *(byte *)((int)puVar1 + 5) & 0xfd;
        goto LAB_007bed72;
      }
      *puVar5 = *puVar1;
      *puVar1 = 0;
      *puVar4 = puVar1;
      puVar4 = puVar1;
    }
    else {
LAB_007bed72:
      puVar5 = puVar1;
    }
    puVar1 = (undefined4 *)*puVar5;
  } while( true );
}


// ==== FUN_007bedb0 @ 0x007bedb0 ====

void FUN_007bedb0(int param_1)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  bool bVar5;
  bool bVar6;
  int local_4;
  
  bVar6 = false;
  bVar5 = false;
  if ((*(byte *)(*(int *)(unaff_EDI + 8) + 5) & 0x11) == 0) {
    FUN_007becb0();
  }
  if ((*(byte *)(*(int *)(unaff_EDI + 8) + 6) & 8) == 0) {
    piVar1 = (int *)FUN_007bf7c0(*(int *)(unaff_EDI + 8),3,
                                 *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x8c));
    if ((piVar1 != (int *)0x0) && (*piVar1 == 4)) {
      pcVar2 = _strchr((char *)(piVar1[2] + 0x10),0x6b);
      bVar5 = pcVar2 != (char *)0x0;
      pcVar2 = _strchr((char *)(piVar1[2] + 0x10),0x76);
      bVar6 = pcVar2 != (char *)0x0;
      if ((bVar5) || (bVar6)) {
        *(byte *)(unaff_EDI + 5) = (bVar6 << 1 | bVar5) << 1 | *(byte *)(unaff_EDI + 5) & 0xf9;
        if (bVar5) {
          if (bVar6) {
            piVar1 = (int *)(param_1 + 0xc);
          }
          else {
            piVar1 = (int *)(param_1 + 4);
          }
        }
        else {
          piVar1 = (int *)(param_1 + 8);
        }
        *(int *)(unaff_EDI + 0x18) = *piVar1;
        *piVar1 = unaff_EDI;
        if (bVar6) goto LAB_007beea5;
      }
    }
  }
  iVar3 = *(int *)(unaff_EDI + 0x1c);
  if (iVar3 != 0) {
    iVar4 = iVar3 << 4;
    do {
      iVar4 = iVar4 + -0x10;
      if ((3 < *(int *)(*(int *)(unaff_EDI + 0xc) + iVar4)) &&
         ((*(byte *)(*(int *)(*(int *)(unaff_EDI + 0xc) + iVar4 + 8) + 5) & 0x11) == 0)) {
        FUN_007becb0();
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
LAB_007beea5:
  local_4 = 1 << (*(byte *)(unaff_EDI + 7) & 0x1f);
  if (local_4 != 0) {
    iVar3 = local_4 * 0x28;
    do {
      iVar3 = iVar3 + -0x28;
      piVar1 = (int *)(*(int *)(unaff_EDI + 0x10) + iVar3);
      if (*(int *)(*(int *)(unaff_EDI + 0x10) + 0x10 + iVar3) != 0) {
        if (((3 < *piVar1) && ((*(byte *)(piVar1[2] + 5) & 0x11) == 0)) && (!bVar5)) {
          FUN_007becb0();
        }
        if (((3 < piVar1[4]) && ((*(byte *)(piVar1[6] + 5) & 0x11) == 0)) && (!bVar6)) {
          FUN_007becb0();
        }
      }
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}


// ==== FUN_007bef20 @ 0x007bef20 ====

void FUN_007bef20(void)

{
  byte *pbVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  
  *(byte *)(*(int *)(unaff_ESI + 0x20) + 5) = *(byte *)(*(int *)(unaff_ESI + 0x20) + 5) | 1;
  iVar3 = 0;
  if (0 < *(int *)(unaff_ESI + 0x28)) {
    iVar2 = 0;
    do {
      if (*(int *)(iVar2 + *(int *)(unaff_ESI + 8)) == 4) {
        pbVar1 = (byte *)(*(int *)(iVar2 + 8 + *(int *)(unaff_ESI + 8)) + 5);
        *pbVar1 = *pbVar1 | 1;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10;
    } while (iVar3 < *(int *)(unaff_ESI + 0x28));
  }
  iVar3 = 0;
  if (0 < *(int *)(unaff_ESI + 0x24)) {
    do {
      pbVar1 = (byte *)(*(int *)(*(int *)(unaff_ESI + 0x1c) + iVar3 * 4) + 5);
      *pbVar1 = *pbVar1 | 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(unaff_ESI + 0x24));
  }
  iVar3 = 0;
  if (0 < *(int *)(unaff_ESI + 0x34)) {
    do {
      if ((*(byte *)(*(int *)(*(int *)(unaff_ESI + 0x10) + iVar3 * 4) + 5) & 0x11) == 0) {
        FUN_007becb0();
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(unaff_ESI + 0x34));
  }
  iVar3 = 0;
  if (0 < *(int *)(unaff_ESI + 0x38)) {
    iVar2 = 0;
    do {
      pbVar1 = (byte *)(*(int *)(iVar2 + *(int *)(unaff_ESI + 0x18)) + 5);
      *pbVar1 = *pbVar1 | 1;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc;
    } while (iVar3 < *(int *)(unaff_ESI + 0x38));
  }
  return;
}


// ==== FUN_007befc0 @ 0x007befc0 ====

void FUN_007befc0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int unaff_EDI;
  
  if (*(char *)(unaff_EDI + 6) == '\0') {
    if ((*(byte *)(*(int *)(unaff_EDI + 0x18) + 5) & 0x11) == 0) {
      FUN_007becb0();
    }
    if ((*(byte *)(*(int *)(unaff_EDI + 0xc) + 5) & 0x11) == 0) {
      FUN_007becb0();
    }
    iVar2 = 0;
    if (*(char *)(unaff_EDI + 7) != '\0') {
      piVar3 = (int *)(unaff_EDI + 0x20);
      do {
        iVar1 = *piVar3;
        if (*(char *)(iVar1 + 5) == '\0') {
          if ((3 < *(int *)(iVar1 + 0x10)) && ((*(byte *)(*(int *)(iVar1 + 0x18) + 5) & 0x11) == 0))
          {
            FUN_007becb0();
          }
          *(undefined1 *)(iVar1 + 5) = 1;
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar2 < (int)(uint)*(byte *)(unaff_EDI + 7));
    }
  }
  else {
    iVar2 = 0;
    if (*(char *)(unaff_EDI + 7) != '\0') {
      piVar3 = (int *)(unaff_EDI + 0x18);
      do {
        if ((3 < piVar3[-2]) && ((*(byte *)(*piVar3 + 5) & 0x11) == 0)) {
          FUN_007becb0();
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 4;
      } while (iVar2 < (int)(uint)*(byte *)(unaff_EDI + 7));
      return;
    }
  }
  return;
}


// ==== FUN_007bf060 @ 0x007bf060 ====

void FUN_007bf060(void)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int unaff_EDI;
  
  if ((3 < *(int *)(unaff_EDI + 0x40)) && ((*(byte *)(*(int *)(unaff_EDI + 0x48) + 5) & 0x11) == 0))
  {
    FUN_007becb0();
  }
  piVar2 = *(int **)(unaff_EDI + 8);
  for (uVar1 = *(uint *)(unaff_EDI + 0x28); uVar1 <= *(uint *)(unaff_EDI + 0x14);
      uVar1 = uVar1 + 0x18) {
    if (((*(byte *)(uVar1 + 8) & 1) == 0) && (piVar2 < *(int **)(uVar1 + 4))) {
      piVar2 = *(int **)(uVar1 + 4);
    }
  }
  piVar3 = *(int **)(unaff_EDI + 0x1c);
  if (piVar3 < *(int **)(unaff_EDI + 8)) {
    do {
      if ((3 < *piVar3) && ((*(byte *)(piVar3[2] + 5) & 0x11) == 0)) {
        FUN_007becb0();
      }
      piVar3 = piVar3 + 4;
    } while (piVar3 < *(int **)(unaff_EDI + 8));
  }
  for (; piVar3 <= piVar2; piVar3 = piVar3 + 4) {
    *piVar3 = 0;
  }
  if ((((*(int *)(unaff_EDI + 0x14) - *(int *)(unaff_EDI + 0x28)) / 0x18) * 4 <
       (int)(uint)*(ushort *)(unaff_EDI + 0x2c)) && (0x10 < *(ushort *)(unaff_EDI + 0x2c))) {
    FUN_007bd3b0();
  }
  if ((((int)piVar2 - *(int *)(unaff_EDI + 0x1c) >> 4) * 4 < *(int *)(unaff_EDI + 0x20)) &&
     (0x5a < *(int *)(unaff_EDI + 0x20))) {
    FUN_007bd360();
  }
  return;
}


// ==== FUN_007bf150 @ 0x007bf150 ====

void FUN_007bf150(void)

{
  int iVar1;
  int *unaff_EBX;
  
  iVar1 = *unaff_EBX;
  while (iVar1 != 0) {
    iVar1 = *unaff_EBX;
    switch(*(undefined1 *)(iVar1 + 4)) {
    case 5:
      *unaff_EBX = *(int *)(iVar1 + 0x18);
      FUN_007bedb0();
      break;
    case 6:
      *unaff_EBX = *(int *)(iVar1 + 8);
      FUN_007befc0();
      break;
    case 8:
      *unaff_EBX = *(int *)(iVar1 + 0x54);
      FUN_007bf060();
      break;
    case 9:
      *unaff_EBX = *(int *)(iVar1 + 0x40);
      FUN_007bef20();
    }
    iVar1 = *unaff_EBX;
  }
  return;
}


// ==== FUN_007bf1d0 @ 0x007bf1d0 ====

void FUN_007bf1d0(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  for (; in_EAX != 0; in_EAX = *(int *)(in_EAX + 0x18)) {
    iVar2 = 1 << (*(byte *)(in_EAX + 7) & 0x1f);
    if (iVar2 != 0) {
      iVar4 = iVar2 * 0x28;
      do {
        iVar4 = iVar4 + -0x28;
        iVar1 = *(int *)(*(int *)(in_EAX + 0x10) + iVar4);
        piVar3 = (int *)(*(int *)(in_EAX + 0x10) + iVar4);
        if (iVar1 == 4) {
          *(byte *)(piVar3[2] + 5) = *(byte *)(piVar3[2] + 5) | 1;
          iVar1 = *piVar3;
        }
        if ((3 < iVar1) && ((*(byte *)(piVar3[2] + 5) & 1) == 0)) {
          piVar3[4] = 0;
          *piVar3 = -1;
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return;
}


// ==== FUN_007bf230 @ 0x007bf230 ====

void FUN_007bf230(void)

{
  int iVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  for (; in_EAX != 0; in_EAX = *(int *)(in_EAX + 0x18)) {
    iVar4 = *(int *)(in_EAX + 0x1c);
    if (iVar4 != 0) {
      iVar3 = iVar4 << 4;
      do {
        iVar3 = iVar3 + -0x10;
        iVar1 = *(int *)(*(int *)(in_EAX + 0xc) + iVar3);
        piVar2 = (int *)(*(int *)(in_EAX + 0xc) + iVar3);
        if (iVar1 == 4) {
          *(byte *)(piVar2[2] + 5) = *(byte *)(piVar2[2] + 5) | 1;
          iVar1 = *piVar2;
        }
        if ((3 < iVar1) && ((*(byte *)(piVar2[2] + 5) & 1) == 0)) {
          *piVar2 = 0;
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    iVar4 = 1 << (*(byte *)(in_EAX + 7) & 0x1f);
    if (iVar4 != 0) {
      iVar3 = iVar4 * 0x28;
      do {
        iVar3 = iVar3 + -0x28;
        iVar1 = *(int *)(*(int *)(in_EAX + 0x10) + 0x10 + iVar3);
        piVar2 = (int *)(*(int *)(in_EAX + 0x10) + iVar3);
        if (iVar1 == 4) {
          *(byte *)(piVar2[6] + 5) = *(byte *)(piVar2[6] + 5) | 1;
          iVar1 = piVar2[4];
        }
        if (((3 < iVar1) && ((*(byte *)(piVar2[6] + 5) & 1) == 0)) && (piVar2[4] = 0, 3 < *piVar2))
        {
          *piVar2 = -1;
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  return;
}


// ==== FUN_007bf2e0 @ 0x007bf2e0 ====

void FUN_007bf2e0(void)

{
  int in_EAX;
  
  switch(*(undefined1 *)(in_EAX + 4)) {
  case 4:
    FUN_007c3420();
    return;
  case 5:
    FUN_007c2530();
    return;
  case 6:
    FUN_007c2080();
    return;
  case 7:
    FUN_007c3420();
    break;
  case 8:
    FUN_007bd070();
    return;
  case 9:
    FUN_007c1fe0();
    return;
  case 10:
    FUN_007c3420();
    return;
  }
  return;
}


// ==== FUN_007bf380 @ 0x007bf380 ====

int FUN_007bf380(int param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = (undefined4 *)*in_EAX;
  while (puVar1 != (undefined4 *)0x0) {
    if (param_1 < (int)(uint)*(byte *)((int)puVar1 + 5)) {
      *(byte *)((int)puVar1 + 5) = *(byte *)((int)puVar1 + 5) & 0xfe;
      in_EAX = puVar1;
    }
    else {
      *in_EAX = *puVar1;
      iVar2 = iVar2 + 1;
      FUN_007bf2e0();
    }
    puVar1 = (undefined4 *)*in_EAX;
  }
  return iVar2;
}


// ==== FUN_007bf3c0 @ 0x007bf3c0 ====

void FUN_007bf3c0(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(*(int *)(in_EAX + 0x10) + 8)) {
    do {
      iVar1 = FUN_007bf380();
      *(int *)(*(int *)(in_EAX + 0x10) + 4) = *(int *)(*(int *)(in_EAX + 0x10) + 4) - iVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(*(int *)(in_EAX + 0x10) + 8));
  }
  return;
}


// ==== FUN_007bf400 @ 0x007bf400 ====

void FUN_007bf400(void)

{
  int iVar1;
  uint uVar2;
  int in_EAX;
  undefined4 uVar3;
  
  iVar1 = *(int *)(in_EAX + 0x10);
  if ((*(int *)(iVar1 + 4) < (int)(*(int *)(iVar1 + 8) + (*(int *)(iVar1 + 8) >> 0x1f & 3U)) >> 2)
     && (0x40 < *(int *)(iVar1 + 8))) {
    FUN_007c1c30();
  }
  if (0x40 < *(uint *)(*(int *)(in_EAX + 0x10) + 0x1c)) {
    uVar2 = *(uint *)(*(int *)(in_EAX + 0x10) + 0x1c);
    uVar3 = FUN_007c3420();
    *(undefined4 *)(*(int *)(in_EAX + 0x10) + 0x18) = uVar3;
    *(uint *)(*(int *)(in_EAX + 0x10) + 0x1c) = uVar2 >> 1;
  }
  *(int *)(*(int *)(in_EAX + 0x10) + 0x20) = *(int *)(*(int *)(in_EAX + 0x10) + 0x24) << 1;
  return;
}


// ==== FUN_007bf470 @ 0x007bf470 ====

void FUN_007bf470(int param_1)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar1 = *(undefined1 *)(param_1 + 0x31);
  *(undefined1 *)(param_1 + 0x31) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  if (*(int *)(*(int *)(param_1 + 0x10) + 0x14) == 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
    *(undefined1 *)(param_1 + 0x31) = uVar1;
    return;
  }
  do {
    puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x10) + 0x14);
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x14) = *puVar2;
    *puVar2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10);
    *(undefined4 **)(*(int *)(param_1 + 0x10) + 0x10) = puVar2;
    iVar3 = *(int *)(param_1 + 8);
    *(undefined4 *)(iVar3 + -0x10) = 7;
    *(undefined4 **)(iVar3 + -8) = puVar2;
    *(byte *)((int)puVar2 + 5) = *(byte *)((int)puVar2 + 5) & 0xfc;
    if ((*(byte *)(puVar2[2] + 6) & 4) == 0) {
      puVar5 = (undefined4 *)
               FUN_007bf7c0(puVar2[2],2,*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x88));
      if (puVar5 != (undefined4 *)0x0) {
        puVar4 = *(undefined4 **)(param_1 + 8);
        *puVar4 = *puVar5;
        puVar4[2] = puVar5[2];
        puVar4[3] = puVar5[3];
        iVar3 = *(int *)(param_1 + 8);
        *(undefined4 *)(iVar3 + 0x10) = 7;
        *(undefined4 **)(iVar3 + 0x18) = puVar2;
        iVar3 = *(int *)(param_1 + 8);
        *(int *)(param_1 + 8) = iVar3 + 0x20;
        FUN_007bd9d0(param_1,iVar3,0);
      }
    }
  } while (*(int *)(*(int *)(param_1 + 0x10) + 0x14) != 0);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  *(undefined1 *)(param_1 + 0x31) = uVar1;
  return;
}


// ==== FUN_007bf560 @ 0x007bf560 ====

void FUN_007bf560(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = 0x100;
  }
  FUN_007bf380(uVar1);
  FUN_007bf3c0();
  FUN_007bf380(uVar1);
  return;
}


// ==== FUN_007bf5a0 @ 0x007bf5a0 ====

void FUN_007bf5a0(int param_1)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if ((3 < *(int *)(*(int *)(unaff_ESI + 0x10) + 0x40)) &&
     ((*(byte *)(*(int *)(*(int *)(unaff_ESI + 0x10) + 0x48) + 5) & 0x11) == 0)) {
    FUN_007becb0();
  }
  if ((3 < *(int *)(*(int *)(unaff_ESI + 0x10) + 0x30)) &&
     ((*(byte *)(*(int *)(*(int *)(unaff_ESI + 0x10) + 0x38) + 5) & 0x11) == 0)) {
    FUN_007becb0();
  }
  FUN_007bf060(param_1);
  if ((unaff_ESI == *(int *)(iVar1 + 0x50)) || ((*(byte *)(unaff_ESI + 5) & 0x11) != 0)) {
    return;
  }
  FUN_007becb0();
  return;
}


// ==== FUN_007bf610 @ 0x007bf610 ====

void FUN_007bf610(void)

{
  int in_EAX;
  int *piVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  local_4 = *(int *)(in_EAX + 0x10);
  local_14 = 0;
  local_c = 0;
  local_10 = 0;
  local_8 = 0;
  FUN_007bf5a0(&local_14);
  FUN_007bf150();
  FUN_007bf230();
  FUN_007bf230();
  local_8 = 0;
  local_c = 0;
  FUN_007bed20();
  piVar1 = *(int **)(local_4 + 0x14);
  if (piVar1 != (int *)0x0) {
    do {
      *(byte *)((int)piVar1 + 5) = *(byte *)((int)piVar1 + 5) & 0xfe;
      FUN_007becb0();
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
  }
  FUN_007bf150();
  FUN_007bf1d0();
  FUN_007bf1d0();
  FUN_007bf230();
  FUN_007bf1d0();
  FUN_007bf230();
  return;
}


// ==== FUN_007bf6e0 @ 0x007bf6e0 ====

void FUN_007bf6e0(undefined4 param_1)

{
  FUN_007bf610();
  FUN_007bf380(0);
  FUN_007bf3c0();
  FUN_007bf380(0);
  FUN_007bf400();
  FUN_007bf470(param_1);
  return;
}


// ==== FUN_007bf730 @ 0x007bf730 ====

void FUN_007bf730(int param_1,undefined4 *param_2,undefined1 param_3)

{
  *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc);
  *(undefined4 **)(*(int *)(param_1 + 0x10) + 0xc) = param_2;
  *(undefined1 *)((int)param_2 + 5) = 0;
  *(undefined1 *)(param_2 + 1) = param_3;
  return;
}


// ==== FUN_007bf760 @ 0x007bf760 ====

void FUN_007bf760(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = 0x80;
  do {
    pcVar2 = *(char **)(s_perform_arithmetic_on_009fe2e4 + iVar6);
    pcVar4 = pcVar2;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar5 = FUN_007c1d70(param_1,pcVar2,(int)pcVar4 - (int)(pcVar2 + 1));
    *(undefined4 *)(iVar6 + *(int *)(param_1 + 0x10)) = uVar5;
    iVar3 = *(int *)(*(int *)(param_1 + 0x10) + iVar6);
    iVar6 = iVar6 + 4;
    *(byte *)(iVar3 + 5) = *(byte *)(iVar3 + 5) | 0x10;
  } while (iVar6 < 0xbc);
  return;
}


// ==== FUN_007bf7c0 @ 0x007bf7c0 ====

int * FUN_007bf7c0(int param_1,byte param_2,undefined4 param_3)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_007c2670(param_1,param_3);
  if (*piVar1 == 0) {
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | '\x01' << (param_2 & 0x1f);
    piVar1 = (int *)0x0;
  }
  return piVar1;
}


// ==== FUN_007bf7f0 @ 0x007bf7f0 ====

undefined4 * FUN_007bf7f0(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x80 + param_3 * 4);
  if (*param_2 == 5) {
    puVar2 = (undefined4 *)FUN_007c2670(*(undefined4 *)(param_2[2] + 8),uVar1);
    return puVar2;
  }
  if (*param_2 == 7) {
    puVar2 = (undefined4 *)FUN_007c2670(*(undefined4 *)(param_2[2] + 8),uVar1);
    return puVar2;
  }
  return &DAT_009fe508;
}


// ==== FUN_007bf840 @ 0x007bf840 ====

int * FUN_007bf840(int *param_1,int *param_2)

{
  int iVar1;
  undefined8 local_8;
  
  if (*param_1 != 3) {
    if (*param_1 == 4) {
      iVar1 = FUN_007c1710(param_1[2] + 0x10,&local_8);
      if (iVar1 != 0) {
        *(undefined8 *)(param_2 + 2) = local_8;
        *param_2 = 3;
        return param_2;
      }
    }
    param_1 = (int *)0x0;
  }
  return param_1;
}


// ==== FUN_007bf890 @ 0x007bf890 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007bf890(undefined4 param_1,int *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char local_24 [32];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (*param_2 != 3) {
    return 0;
  }
  _sprintf(local_24,s___14g_009fd880,*(undefined8 *)(param_2 + 2));
  pcVar2 = local_24;
  *param_2 = 4;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = FUN_007c1d70(param_1,local_24,(int)pcVar2 - (int)(local_24 + 1));
  param_2[2] = iVar3;
  return 1;
}


// ==== FUN_007bf920 @ 0x007bf920 ====

void FUN_007bf920(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  
  if ((4 < *(byte *)(unaff_EDI + 0x30)) && (*(int *)(unaff_EDI + 0x38) == 0)) {
    *(undefined4 *)(unaff_EDI + 0x38) = *(undefined4 *)(unaff_EDI + 0x34);
    FUN_007bd4a0();
    return;
  }
  if ((*(byte *)(unaff_EDI + 0x30) & 4) == 0) {
    return;
  }
  piVar2 = *(int **)(unaff_EDI + 0x14);
  iVar3 = *(int *)(*(int *)(*piVar2 + -8) + 0xc);
  if (*(int *)(iVar3 + 0x14) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(*(int *)(iVar3 + 0x14) + -4 +
                    (*(int *)piVar2[4] - *(int *)(iVar3 + 0xc) >> 2) * 4);
  }
  if (*(char *)(unaff_EDI + 0x32) == '\0') {
    FUN_007bde90();
    return;
  }
  uVar1 = *(uint *)piVar2[4];
  if ((int)(uVar1 - *(int *)(iVar3 + 0xc)) >> 2 == 1) {
    piVar2[3] = uVar1;
  }
  if ((uint)piVar2[3] < *(uint *)piVar2[4]) {
    if (*(int *)(iVar3 + 0x14) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x14) + -4 + (piVar2[3] - *(int *)(iVar3 + 0xc) >> 2) * 4);
    }
    if (iVar4 == iVar3) goto LAB_007bf9c8;
  }
  FUN_007bd4a0();
  piVar2 = *(int **)(unaff_EDI + 0x14);
LAB_007bf9c8:
  piVar2[3] = *(int *)piVar2[4];
  return;
}


// ==== FUN_007bf9e0 @ 0x007bf9e0 ====

void FUN_007bf9e0(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *in_EDX;
  int unaff_ESI;
  
  puVar1 = *(undefined4 **)(unaff_ESI + 8);
  *puVar1 = *in_EAX;
  puVar1[2] = in_EAX[2];
  puVar1[3] = in_EAX[3];
  iVar2 = *(int *)(unaff_ESI + 8);
  *(undefined4 *)(iVar2 + 0x10) = *in_EDX;
  *(undefined4 *)(iVar2 + 0x18) = in_EDX[2];
  *(undefined4 *)(iVar2 + 0x1c) = in_EDX[3];
  iVar2 = *(int *)(unaff_ESI + 8);
  *(undefined4 *)(iVar2 + 0x20) = *in_ECX;
  *(undefined4 *)(iVar2 + 0x28) = in_ECX[2];
  *(undefined4 *)(iVar2 + 0x2c) = in_ECX[3];
  if (*(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 8) < 0x31) {
    FUN_007bd420();
  }
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x30;
  FUN_007bd9d0();
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
  return;
}


// ==== FUN_007bfa60 @ 0x007bfa60 ====

void FUN_007bfa60(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *in_EDX;
  int unaff_ESI;
  
  puVar1 = *(undefined4 **)(unaff_ESI + 8);
  *puVar1 = *param_1;
  puVar1[2] = param_1[2];
  puVar1[3] = param_1[3];
  iVar2 = *(int *)(unaff_ESI + 8);
  *(undefined4 *)(iVar2 + 0x10) = *in_EAX;
  *(undefined4 *)(iVar2 + 0x18) = in_EAX[2];
  *(undefined4 *)(iVar2 + 0x1c) = in_EAX[3];
  iVar2 = *(int *)(unaff_ESI + 8);
  *(undefined4 *)(iVar2 + 0x20) = *in_EDX;
  *(undefined4 *)(iVar2 + 0x28) = in_EDX[2];
  *(undefined4 *)(iVar2 + 0x2c) = in_EDX[3];
  iVar2 = *(int *)(unaff_ESI + 8);
  *(undefined4 *)(iVar2 + 0x30) = *in_ECX;
  *(undefined4 *)(iVar2 + 0x38) = in_ECX[2];
  *(undefined4 *)(iVar2 + 0x3c) = in_ECX[3];
  if (*(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 8) < 0x41) {
    FUN_007bd420();
  }
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x40;
  FUN_007bd9d0();
  return;
}


// ==== FUN_007bfb00 @ 0x007bfb00 ====

undefined4 FUN_007bfb00(void)

{
  int in_EAX;
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)FUN_007bf7f0();
  if (*piVar1 == 0) {
    FUN_007beb70();
  }
  if (*piVar1 == 6) {
    FUN_007bf9e0();
    return *(undefined4 *)(in_EAX + 8);
  }
  uVar2 = FUN_007bfb60();
  return uVar2;
}


// ==== FUN_007bfb60 @ 0x007bfb60 ====

void FUN_007bfb60(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  if (100 < param_4) {
    FUN_007be950(param_1,s_loop_in_gettable_009fe438);
  }
  if (*param_2 != 5) {
    FUN_007bfb00(param_3,param_4 + 1);
    return;
  }
  piVar1 = (int *)FUN_007c26b0(param_2[2],param_3);
  if (*piVar1 == 0) {
    FUN_007c0440(param_1,param_2,param_3,param_4 + 1);
  }
  return;
}


// ==== FUN_007bfbd0 @ 0x007bfbd0 ====

void FUN_007bfbd0(int param_1,int *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_4;
  
  local_4 = 0;
  do {
    if (*param_2 == 5) {
      iVar1 = param_2[2];
      piVar2 = (int *)FUN_007c2710(param_1,iVar1,param_3);
      if ((*piVar2 != 0) || (iVar1 = *(int *)(iVar1 + 8), (*(byte *)(iVar1 + 6) & 2) != 0)) {
LAB_007bfc29:
        *piVar2 = *param_4;
        piVar2[2] = param_4[2];
        piVar2[3] = param_4[3];
        return;
      }
      piVar3 = (int *)FUN_007bf7c0(iVar1,1,*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x84));
      if (piVar3 == (int *)0x0) goto LAB_007bfc29;
    }
    else {
      piVar3 = (int *)FUN_007bf7f0(param_1,param_2,1);
      if (*piVar3 == 0) {
        FUN_007beb70(param_1,param_2,s_index_009fe430);
      }
    }
    param_2 = piVar3;
    if (*param_2 == 6) {
      FUN_007bfa60(param_2);
      return;
    }
    local_4 = local_4 + 1;
    if (100 < local_4) {
      FUN_007be950(param_1,s_loop_in_settable_009fe44c);
      return;
    }
  } while( true );
}


// ==== FUN_007bfcb0 @ 0x007bfcb0 ====

undefined4 FUN_007bfcb0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EAX;
  int *piVar3;
  undefined4 *puVar4;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x1c);
  piVar3 = (int *)FUN_007bf7f0();
  if (*piVar3 == 0) {
    piVar3 = (int *)FUN_007bf7f0();
  }
  if (*piVar3 == 6) {
    FUN_007bf9e0();
    puVar2 = *(undefined4 **)(in_ECX + 8);
    puVar4 = (undefined4 *)(*(int *)(in_ECX + 0x1c) + (in_EAX - iVar1));
    *puVar4 = *puVar2;
    puVar4[2] = puVar2[2];
    puVar4[3] = puVar2[3];
    return 1;
  }
  return 0;
}


// ==== FUN_007bfd20 @ 0x007bfd20 ====

uint FUN_007bfd20(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  byte unaff_SI;
  int unaff_EDI;
  
  bVar3 = (byte)(1 << (unaff_SI & 0x1f));
  if ((bVar3 & *(byte *)(unaff_EDI + 6)) == 0) {
    uVar1 = FUN_007bf7c0();
    if (uVar1 != 0) {
      if (unaff_EDI == param_2) {
        return uVar1;
      }
      if ((*(byte *)(param_2 + 6) & bVar3) == 0) {
        iVar2 = FUN_007bf7c0(param_2);
        if (iVar2 != 0) {
          iVar2 = FUN_007c16c0(uVar1,iVar2);
          return -(uint)(iVar2 != 0) & uVar1;
        }
      }
    }
  }
  return 0;
}


// ==== FUN_007bfda0 @ 0x007bfda0 ====

undefined4 FUN_007bfda0(void)

{
  int in_EAX;
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)FUN_007bf7f0();
  if (*piVar1 != 0) {
    uVar2 = FUN_007bf7f0();
    iVar3 = FUN_007c16c0(piVar1,uVar2);
    if (iVar3 != 0) {
      FUN_007bf9e0();
      iVar3 = **(int **)(in_EAX + 8);
      if ((iVar3 == 0) || ((iVar3 == 1 && ((*(int **)(in_EAX + 8))[2] == 0)))) {
        return 0;
      }
      return 1;
    }
  }
  return 0xffffffff;
}


// ==== FUN_007bfe10 @ 0x007bfe10 ====

uint FUN_007bfe10(void)

{
  char cVar1;
  int in_EAX;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  char *_Str1;
  char *_Str2;
  
  iVar5 = *(int *)(in_EAX + 0xc);
  iVar6 = *(int *)(in_ECX + 0xc);
  _Str2 = (char *)(in_EAX + 0x10);
  _Str1 = (char *)(in_ECX + 0x10);
  uVar2 = _strcoll(_Str1,_Str2);
  if (uVar2 == 0) {
    while( true ) {
      pcVar3 = _Str1;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      iVar4 = (int)pcVar3 - (int)(_Str1 + 1);
      if (iVar4 == iVar5) {
        return (uint)(iVar4 != iVar6);
      }
      if (iVar4 == iVar6) break;
      iVar4 = iVar4 + 1;
      _Str2 = _Str2 + iVar4;
      _Str1 = _Str1 + iVar4;
      iVar6 = iVar6 - iVar4;
      iVar5 = iVar5 - iVar4;
      uVar2 = _strcoll(_Str1,_Str2);
      if (uVar2 != 0) {
        return uVar2;
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ==== FUN_007bfe80 @ 0x007bfe80 ====

uint FUN_007bfe80(undefined4 param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *param_2;
  if (iVar2 != *param_3) {
    uVar1 = FUN_007bec60(param_1,param_2,param_3);
    return uVar1;
  }
  if (iVar2 == 3) {
    if (*(double *)(param_2 + 2) < *(double *)(param_3 + 2)) {
      return 1;
    }
    return 0;
  }
  if (iVar2 == 4) {
    iVar2 = FUN_007bfe10();
    return (uint)(iVar2 < 0);
  }
  uVar1 = FUN_007bfda0(param_2,0xb);
  if (uVar1 == 0xffffffff) {
    uVar1 = FUN_007bec60(param_1,param_2,param_3);
  }
  return uVar1;
}


// ==== FUN_007bff10 @ 0x007bff10 ====

uint FUN_007bff10(undefined4 param_1)

{
  double dVar1;
  double dVar2;
  uint uVar3;
  int iVar4;
  int *unaff_ESI;
  int *unaff_EDI;
  
  iVar4 = *unaff_EDI;
  if (iVar4 != *unaff_ESI) {
    uVar3 = FUN_007bec60(param_1);
    return uVar3;
  }
  if (iVar4 == 3) {
    dVar1 = *(double *)(unaff_EDI + 2);
    dVar2 = *(double *)(unaff_ESI + 2);
    if ((NAN(dVar1) || NAN(dVar2)) || dVar1 < dVar2 == (dVar1 == dVar2)) {
      return 0;
    }
    return 1;
  }
  if (iVar4 == 4) {
    iVar4 = FUN_007bfe10();
    return (uint)(iVar4 < 1);
  }
  uVar3 = FUN_007bfda0();
  if (uVar3 == 0xffffffff) {
    iVar4 = FUN_007bfda0();
    if (iVar4 != -1) {
      return (uint)(iVar4 == 0);
    }
    uVar3 = FUN_007bec60(param_1);
  }
  return uVar3;
}


// ==== FUN_007bffb0 @ 0x007bffb0 ====

bool FUN_007bffb0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  switch(*param_2) {
  case 0:
    break;
  default:
    return param_2[2] == *(int *)(param_3 + 8);
  case 2:
    return param_2[2] == *(int *)(param_3 + 8);
  case 3:
    if (*(double *)(param_2 + 2) != *(double *)(param_3 + 8)) {
      return false;
    }
    break;
  case 5:
  case 7:
    if (param_2[2] != *(int *)(param_3 + 8)) {
      iVar1 = FUN_007bfd20(param_1,*(undefined4 *)(*(int *)(param_3 + 8) + 8));
      if (iVar1 != 0) {
        FUN_007bf9e0();
        iVar1 = **(int **)(param_1 + 8);
        if (iVar1 != 0) {
          if (iVar1 != 1) {
            return true;
          }
          if ((*(int **)(param_1 + 8))[2] != 0) {
            return true;
          }
        }
      }
      return false;
    }
  }
  return true;
}


