#include <stdio.h>

char *binString(char a) {
    static char b[9]; // 1
    int i;
    i = 0; // 2
    while ( i < 8 ) { // 3
        b[i] = a & 0x80 ? '1' : '0'; // 4
        a = a << 1; // 5
        i++;
    }
    b[i] = '\0'; // 6

    return(b);
}

int main () {
    int a;

    printf(" d x    BIN    c |  d x    BIN    c |  d x    BIN    c |  d x    BIN    c |\n\n");
    for ( a = 0; a < 32; a++ ) {
        printf("%2d %02X %s - | ",a,a,binString(a));
		printf("%2d %02X %s %c | ",a+32,a+32,binString(a+32),a+32);
		printf("%2d %02X %s %c | ",a+64,a+64,binString(a+64),a+64);
		printf("%3d %02X %s %c |\n",a+96,a+96,binString(a+96),a+96);
    }

    return 0;
}

// 1. The string is static so that its value is retained; nine characters
// allow for an 8-bit byte, plus another element for the terminating null char.
// 2. Initialize the index variable.
// 3. Loop for each bit in the 8-bit byte.
// 4. The ternary operator sets a 1 or 0 into the string, depending on the
// value of the far left bit in variabl a.
// 5. Variable a's value is shifted one bit position to the left.
// 6. At this point, i is equal to 8, so the string is capped.

// main function outputs an ASCII table with binary data