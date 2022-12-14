///
/// main.cxx
///

#include <stdio.h>

// 2-complement representation test
// Prueba de representacion de numeros en complemento a dos

void test2C() {

    unsigned int ui32 = 0x7fffffff;
      signed int si32 = 0x7fffffff;

    fprintf(stdout, "unsigned: %11u + 1 = %11u\n", ui32, ui32 + 1);
    fprintf(stdout, "  signed: %11d + 1 = %11d\n", si32, si32 + 1);

    fprintf(stdout, "=======================================\n");

    fprintf(stdout, "0x%08x: MININT (U) = %11u\n", 0x00000000, 0x00000000);
    fprintf(stdout, "0x%08x: 2^31 - 1   = %11u\n", 0x7fffffff, 0x7fffffff);
    fprintf(stdout, "0x%08x: 2^31       = %11u\n", 0x80000000, 0x80000000);
    fprintf(stdout, "0x%08x: MAXINT (U) = %11u\n", 0xffffffff, 0xffffffff);

    fprintf(stdout, "=======================================\n");

    fprintf(stdout, "0x%08x: -2^31      = %11d\n", 0x80000000, 0x80000000);
    fprintf(stdout, "0x%08x: -1         = %11d\n", 0xffffffff, 0xffffffff);
    fprintf(stdout, "0x%08x: 0          = %11d\n", 0x00000000, 0x00000000);
    fprintf(stdout, "0x%08x: 2^31 - 1   = %11d\n", 0x7fffffff, 0x7fffffff);
}


int main() {
    test2C();
    return 0;
}

/*

000 => 0
001 => 1
010 => 2
011 => 3
100 => 4
101 => 5
110 => 6
111 => 7

100 => -4
101 => -3
110 => -2
111 => -1
000 => 0
001 => 1
010 => 2
011 => 3

1000000000000000
1000000000000001
...

1111111111111101 => -3
1111111111111110 => -2
1111111111111111 => -1
0000000000000000 =>  0
0000000000000001 =>  1
0000000000000010 =>  2
0000000000000011 =>  3
...
0111111111111111 =>

*/
