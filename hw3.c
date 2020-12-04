File Edit Options Buffers Tools C Help
#include <stdio.h>
#include <stdlib.h>


// Problem 1
long sum(long a[], long n) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             long sum = 0;
  int i;
  for(i = 0; i < n; i++){
    sum += a[i];
  }

  return sum;
}


// Problem 2
long sum2(long a[], long n) {

  long i, sum =0;

  for(i = 0; i < n; i++){
    sum += *(a + i);
  }

  return sum;
}


// Problem 3
long decode2 (long x, long y, long z) {
  long result = 0;
  x -= z;
  y *= x;
  result = x;
  result = result<<63;
  result = result>>63;
  result ^= y;
  result += z;


  return result; // replace this with appropriate return statement
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           // Problem 4
// Write here AS A COMMENT the assembly code corresponding to
// the body of the for loop you implemented in function sum
/*
.L3:
movslq  %edx, %rcx
  addq    (%rdi,%rcx,8), %rax
  addl    $1, %edx
  .L2:
  movslq  %edx, %rcx
    cmpq    %rsi, %rcx                                                      jl      .L3
        rep ret
       .cfi_endproc
*/


// Write here AS A COMMENT the assembly code corresponding to
// the body of the for loop you implemented in function sum2

/*
.L6:
addq    (%rdi,%rdx,8), %rax
  addq    $1, %rdx
  .L5:
  cmpq    %rsi, %rdx
        jl      .L6
        rep ret
        .cfi_endproc


void main () {
  // test function sum implementation; do not modify!
  phase_5(9, 60);
  long a[8] = {10, 8, 6 , 4, 2, 0, -2, -4};
  printf("sum(a, 8) = %d\n", sum(a, 8));
  printf("sum2(a, 8) = %d\n", sum2(a, 8));
}


void phase_5(int *num1, int *num2)
{

  if (!("%d %d", &num1, &num2) > 1)
    printf("The bomb exploded.");

  num1 = num1 & 15;

  if (num1 == 15) printf("The bomb exploded.");

  int sum = 0;
  int count = 0;

  while (num1 != 15) {
    sum = sum + num1;
    count++;
  };

  if ((count != 9) || (sum != num2))
    printf("The bomb exploded.");
}

void explode_bomb(){
  printf("The bomb exploded.");
}
*/
