 /* 
 * CS:APP Data Lab 
 * 
 * <于可欣 20300750093>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  //同位在同时取反和同时不取反时的与，都为0
    int temp1;
    int temp2;
    int result;

    temp1 = ~(x&y);
    temp2 = ~((~x)&(~y));
    result = temp1 & temp2;

    return result;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    //最小值是1后面31个0
    int myMin;
    int minus1 = 1;
    int bit = 31;

    myMin = minus1 << bit;

    return myMin;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  //只有-1和最大值满足x+x+1后为-1
    int sum;
    int result;

    sum = x + x + 1;
    result =(!(!(~x))) & (!(~sum));

  return result;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  //利用常量，使偶数位不变，奇数位变1，然后观察改变前后的数据是否相同
  int constant = 170;
  int result;

  constant = constant + (constant<<8);
  constant = constant + (constant<<16);

  result = x | constant;
  result = !(x ^ result);

  return result;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //原数据取反+1
  x= ~x;
  x = x + 1;

  return x;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  //判断数据满足：只有六位，大于等于0x30，小于等于0x39
  int judge;
  int up,low;
  int result;

  judge = x >> 6;
  up = 0x39 + (~x) + 1;
  low = x+ (~0x30) + 1;
  up = up >> 31;
  low = low >> 31;

  //为全一则是表示不满足
  result = judge | up | low ;
  result = ! (result);

  return result;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //将x映射为judge，以judge决定选择哪个
  int returny,returnz;
  int judge;
  int result;

  judge = ~(!x) + 1;

  returny = (~judge) & y;
  returnz = judge & z;

  result = returny | returnz;

  return result;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  //分符号讨论
  int judge;
  int less;
  int equal;
  int result;

  //judge表示是否同号
  judge = (x>>31) ^ (y>>31);

  //表示xy大小关系
  equal = (~x) + y;
  less = x + (~y) + 1;
  less = less >> 31 ;

  //分同号异号两种情况
  result = (judge & (x>>31) ) | ((~judge) & (equal | less));
  result = !(~result);
  
  return result;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  //只有符号位为0，且加完-1不变号的才是0
  int numberNeg = x >> 31;
  int isZero = (x + (~0)) >> 31;
  int result;

  result = numberNeg | (~isZero);
  result = result + 1;

  return result;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {

  //实际是寻找第一个0与1的衔接点(对正数来说只用保留前面的一个0,负数保留一个1)
  int findDiff;
  int bits = 0;
  int judge = 0;

 //让位于前面的所有相同数据变成0
  findDiff = x ^ (x<<1);

  //现在用二分法寻找findDiff的最高位
  judge = !!(findDiff>>16);
  bits = bits + (judge << 4);
  //judge为0的看后16位，为1的看前16位
  findDiff = findDiff >> (judge << 4);

  judge = !!(findDiff >> 8);
  bits = bits + (judge << 3);
  findDiff = findDiff >> (judge << 3);

  judge = !!(findDiff >> 4);
  bits = bits + (judge << 2);
  findDiff = findDiff >> (judge << 2);

  judge = !!(findDiff >> 2);
  bits = bits + (judge << 1);
  findDiff = findDiff >> (judge << 1);

  judge = !!(findDiff >> 1);
  bits = bits + judge;

  //加上符号位
  bits = bits + 1;

  return bits;


}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  //截取阶码位分类讨论
  unsigned resultf = uf;
  unsigned testNaN = 1;
  unsigned temp = uf;
  int i = 0;

  while(i<7)
  {
    testNaN = testNaN<<1;
    testNaN = testNaN + 1;
    i = i + 1;
  }

  //检测是否为NaN or inf
 if (((uf<<1)>>24) == testNaN  )
  {
    resultf = uf;
  }
  

  //检测是否为Denormalized,若不是
  else if((uf<<1)>>24)
  {
    resultf = uf + (1<<23);
  }
  //若是
  else
  {
    temp = uf >>31;
    resultf = (uf << 1) + (temp << 31);
  }


  return resultf;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  //截取exp和frac分类讨论
  unsigned temp = uf >> 23;
  unsigned result = 0;
  unsigned power = 0;
  unsigned gainFrac = 1;
  int i = 0;
  int j = 0;
  int flag = 0;

   while(j<22)
  {
    gainFrac = gainFrac<<1;
    gainFrac = gainFrac + 1;
    j = j + 1;
  }

  //收集幂次信息
  while (i<8)
  {
    power = power + ((temp & 1) << i)  ;
    temp = temp >> 1;
    flag = flag + (temp & 1);
    i = i + 1;
  }

  //计算有效数据的int转换绝对值

  //对于denormalized
  if(flag == 0)
  {
    result = 0;
  }
  //对于极大值
  else if (flag == 8)
  {
    result = 0x80000000u;
  }

  //对于普通的幂次大于等于0的值
  else if (power>=(127) && power<=(157))
  {
    //截取末尾
    gainFrac = gainFrac & uf;
    power = power - ((1<<7) - 1) ;
    result = ((gainFrac << power)>>23) + (1 << power);
  }

//对于越界
  else if(power>157)
  {
    result = 0x80000000u;
  }
  
  //对于普通值 但幂次小于零 说明至多为0
  else
    result = 0;

  //分析符号位并做相关调整
  //若为负，做补码转换
  if(uf>>31)
    result = 1 + (~result);
  
  return result;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  //截取exp和frac分类讨论
    unsigned exp,frac;
    unsigned u;

    if(x<(~149)+1)
    {
      //too small return 0
        exp = 0;
        frac = 0;
    }

    else if(x<(~126)+1)
    {
        //Denormalized result
        exp = 0;
        frac = 1 <<(23+x+126);
    }

    else if(x <= 128)
    {
        //Normalized result
        exp = 127+x;
        frac = 0;
    }

    else
    {
        //Too big. return +∞
        exp = 255;
        frac = 0;
    }

    //Pack exp and frac into 32 bits
    u = exp << 23 | frac;
    //return as *float
    return u;
}
