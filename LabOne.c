





int bitAnd(int x, int y) {











  return ~(~x|~y);
}
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
/* Applying DeMorgan's Law
 * NOT X AND NOT Y = NOT X OR Y
 */






  return (~x & ~y);
}
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x){
/* (X AND 1) finds the lsb.
 * ~(x & 1) will result in -2 or -1
' * Adding 1 will result in -1 or 0
 */






   return ~(x & 1) + 1;
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getint bitAnd(int x, int y) {
/* Using NOT and OR distributively
 * to turn OR into AND.
 * (~~x|~~y) = (x&y)
 */
  return ~(~x|~y);
}
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
/* Applying DeMorgan's Law
 * NOT X AND NOT Y = NOT X OR Y
 */
  return (~x & ~y);
}
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x){
/* (X AND 1) finds the lsb.
 * ~(x & 1) will result in -2 or -1
 * Adding 1 will result in -1 or 0
 */
   return ~(x & 1) + 1;
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n){
/* Shifted n to the left 3 times = n*8
 * It is then shifted back to result in the correct
 * byte.
 */
   return (0xFF & (x >> (n << 3)));
}
/* byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */Byte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n){
/* Shifted n to the left 3 times = n*8
 * It is then shifted back to result in the correct
 * byte.
 */






   return (0xFF & (x >> (n << 3)));
}
/* byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */



int byteSwap(int x, int n, int m) {
/* Initializing 3 ints, a and b are for shifting
 * n and m to the left 3 times. z is the hex
 * representaion of a shifted to the right 3
 * time and swapped with b.
 */






        int z = 0;
        int a = n << 3;
        int b = m << 3;
        z = 0xFF & ((x >> a) ^ (x>>b));
        x = x ^ (z << a);
        x = x ^ (z << b);
   return x;
}
/*
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x){
/* Mask for all even positions are 1, odds are 0.
 *  ((x&b) ^ b) would be flipped, so adding
 *  a ! would return 1 for evens.
 */





  int a = (0x55 << 8) | 0x55;
  int b = (a << 16) | a;
  return !((x & b) ^ b);
}
/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int leastBitPos(int x) {
/* negX will get the least significant bit.
 * x & negX will return that bit
 */






        int negX = ~x + 1;
  return (x & negX);
}
/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
/* finding the complement of x then
 * adding 1 will subtract 1.
 */





        int x = 1;
  return ~x + 1;
}
/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   max ops: 4
 *   Rating: 1
 */
int tmax(void) {
/* finding the compliment of x shifted
 * 24 bits produces the largest 32-bit integer.
 */






        int x = 0x80; //
  return (~(x << 24));
}
/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
/* x ^ y would result in 0 if they were equal
 * ! would result in the opposite of that
 */






  return !(x ^ y);
}
/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
/* Shifting to the right 31 bits
 * will isolate the top bit.
 * & 0x1 will return 1 is negative, 0
 * if positive.
 */







  return (x >> 31) & 0x1;
}
/*
 * negate - return -x  = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
/* (x - 1) would not work.
 * However, finding the complement of
 * of that equation will find the negation.
 */







  x = ~(x - 1);
  return x;
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
/* Finding the sum first
 * ((Sum^x) & (Sum^ y)) will equal a negative
 * number, adding ! will result in 1 if it
 * won't overflow. Shifting to the right 31 bits will
 * result in flipping the 1 and 0, making it result in 0
 * if overflow occurs.
 */







        int sum = (x+y);
  return  !(((sum ^ x) & (sum ^ y)) >> 31);
}int bitAnd(int x, int y) {
/* Using NOT and OR distributively
 * to turn OR into AND.
 * (~~x|~~y) = (x&y)
 */
  return ~(~x|~y);
}
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
/* Applying DeMorgan's Law
 * NOT X AND NOT Y = NOT X OR Y
 */
  return (~x & ~y);
}
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x){
/* (X AND 1) finds the lsb.
 * ~(x & 1) will result in -2 or -1
 * Adding 1 will result in -1 or 0
 */
   return ~(x & 1) + 1;
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n){
/* Shifted n to the left 3 times = n*8
 * It is then shifted back to result in the correct
 * byte.
 */
   return (0xFF & (x >> (n << 3)));
}
/* byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
/* yBool and xBool will result in 0 if positive,
 * -1 if negative.
 *  xLessThanY will return 1 if x <= y, 0 if x>y.
 *  ((!yBool) & xBool) will return 0 if x>y.
 */







        int yBool = (y >> 31) & 1;
        int xBool = (x >> 31) & 1;
        int xLessThanY = (!(yBool ^ xBool)) & (((x+~y) >> 31) & 1);
return xLessThanY|((!yBool) & xBool);
}
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
/* a will return -1 if negative, 0 if positive.
 * (x = x ^ a) would result in (~x +1)
 * (x = x - a) will result in the negation
 */






        int a = x >>31;
        x = x ^ a;
        x = x - a;
  return x;
}
