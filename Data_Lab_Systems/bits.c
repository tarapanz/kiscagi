/* 
 * CS:APP Data Lab 
 * 
 * <Tara Panzarino  tapa9778>
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
    return ~(~x & ~y);
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
    int x = 1;
    x |= x<<2;
    x |= x<<4;
    x |= x<<8;
    x |= x<<16;

    return x;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {  
    int x = 0;
    return ~x;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
    x &= x>>2;
    x &= x>>4;
    x &= x>>8;
    x &= x>>16;
    x &= 1;
    return x;
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
     // 0xaa = 1010 1010
     x = (x & 0xaa) | (x>>8 & 0xaa) | (x>>16 & 0xaa) | (x>>24 & 0xaa);
     return !!x;    //true/false equivalent
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    
    int n_bits = n <<3; 
    int m_bits = m <<3;
    
    int x_n = x >> n_bits;
    int n_mask = x_n & 0xFF;
    int n_to_m = n_mask << m_bits;
    
    
    int x_m = x >> m_bits;
    int m_mask = x_m & 0xFF;
    int m_to_n = m_mask << n_bits; 
    
    int new_spots = (n_to_m | m_to_n);
   
    
    
    int swapped_m = (0xff << m_bits);
    int swapped_n = (0xff << n_bits) ;

    int mask = ~(swapped_m | swapped_n);
    
    
    
    return  (x & mask) | (new_spots);
    
  
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    int x_sign = x>>31; // 1 or 0
    int y_sign = y>>31; // 1 0r 0
    int sum_sign = (x+y)>>31; //1 or 0
    
    
    return  !!((x_sign ^ y_sign ) | ((x_sign & sum_sign)) | ((!x_sign) & (!sum_sign)));


}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    // True X-> True Y : ~X or Y : X and ~Y
    //~True X-> True Z:  X or Z  : ~X and ~Z
    
     int a = !!x;  // truth value 1 or 0;
     int b = ~a + 1;//twos compl all 1 or all 0   
     return (~b | y) & (b | z );

}
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
// 110000 
//    110001
//    110010
//    110011  
//    110100
//    110101
//    110110
//    110111
//    111000
//    111001    
// 0x3 = 11    
    
    int spot54 = !(x>>4 ^ 0x3); //1 if 11 is in 5/4 spot
    int spot3 = !!(x>>3 & 0x1); // 1 if 1 is in 3 spot
    int spot21 = !!(x>>1 & 0x3); // 1 if 11 is in 2/1 spot
    
    
//    110000 is present & nothing is in the 2^3 place AND the 2^2 and 2^2
    
    return spot54 & !(spot3 & spot21);
    


                  
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
    int m = n << 3;
    
    int a = 0xff << m;  // create mask
    int b = ~a; // flip bits
    
    int d = c << m;
    return (x & b) | d;
    
}
/* reverseBits - reverse the bits in a 32-bit integer,
              i.e. b0 swaps with b31, b1 with b30, etc
 *  Examples: reverseBits(0x11111111) = 0x88888888
 *            reverseBits(0xdeadbeef) = 0xf77db57b
 *            reverseBits(0x88888888) = 0x11111111
 *            reverseBits(0)  = 0
 *            reverseBits(-1) = -1
 *            reverseBits(0x9) = 0x90000000
 *  Legal ops: ! ~ & ^ | + << >> and unsigned int type
 *  Max ops: 90
 *  Rating: 4
 */
int reverseBits(int x) {
    //0x11111111
    
// swapping nibbles:
    
    int b = 0;
    int n = 0;
    int a = 0;
    int m = 0;
    
//     b = b << 4;
    n = x & 0xf; //1111
    b = b|n;
    x = x >> 4;
    
    b = b << 4;
    n = x & 0xf;
    b = b|n;
    x = x >> 4;
    
    b = b << 4;
    n = x & 0xf;
    b = b|n;
    x = x >> 4;
    
    b = b << 4;
    n = x & 0xf;
    b = b|n;
    x = x >> 4;
    
    b = b << 4;
    n = x & 0xf;
    b = b|n;
    x = x >> 4;
    
    b = b << 4;
    n = x & 0xf;
    b = b|n;
    x = x >> 4;
    
    b = b << 4;
    n = x & 0xf;
    b = b|n;
    x = x >> 4;
    
    b = b << 4;
    n = x & 0xf;
    b = b|n;
    

    // swapping bits: 
    
//     a = a << 1;
    m = b & 0x11111111;
    a = a|m;
    b = b >> 1;

    a = a << 1;
    m = b & 0x11111111;
    a = a|m;
    b = b >> 1;
    
    a = a << 1;
    m = b & 0x11111111;
    a = a|m;
    b = b >> 1;
    
    a = a << 1;
    m = b & 0x11111111;
    a = a|m;

    return a;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value (Tmax), and when negative overflow occurs,
 *          it returns minimum negative value (Tmin)
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
    // True X-> True Y : ~X or Y : X and ~Y
    //~True X-> True Z:  X or Z  : ~X and ~Z
//     int a = !!x;  // truth value
//     int b = ~a + 1; //twos compl 
//     return (~b | y) & (b | z );    
    
    
    int x_sign = x>>31; // 1 or 0
    int y_sign = y>>31; // 1 0r 0
    int sum_sign = (x+y)>>31; //1 or 0
    
    int no_overflow = ~(!!((x_sign ^ y_sign ) | ((x_sign & sum_sign)) | ((!x_sign) & (!sum_sign))));  // 1 if true
    int sattop = (!x_sign) & (!y_sign) & sum_sign;
    int satbottom = x_sign & y_sign & (!sum_sign);
    
    int Tmax = 127;
    int Tmin = ~Tmax+1;
    
    return (~no_overflow | (x+y)) & ((~no_overflow & sattop) | Tmax) & ((~no_overflow & satbottom) |Tmin);
    
}
/*
 * Extra credit
 */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  return 2;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
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
int float_f2i(unsigned uf) {
  return 2;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  return 2;
}
