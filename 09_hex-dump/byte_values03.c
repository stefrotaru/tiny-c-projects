#include <stdio.h>

int main() {
    unsigned char data[255];
    int b;

    for ( b = 0; b < 256; b++ ) {
        data[b] = b;
    }

    for ( b = 0; b < 256; b++ ) {
        printf(" %02X", data[b]); // 1
        if ( (b + 1) % 16 == 0 ) // 2
            putchar('\n');
    }

    return 0;
}

// 1. Outputs the value in 2-digit hexadecimal format
// 2. Output a new line for every 16 values