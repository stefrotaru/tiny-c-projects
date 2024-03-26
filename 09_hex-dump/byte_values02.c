#include <stdio.h>

int main() {
    unsigned char data[255]; // 1
    int b;

    for ( b = 0; b < 256; b++ ) { // 2
        data[b] = b;
    }

    for ( b = 0; b < 256; b++ ) { // 3
        printf("%d\n", data[b]);
    }

    return 0;
}

// 1. Room for the full variety of byte values
// 2. Fills the array with valyes 0 through 255
// 3. Outputs the array, with each value on a line by itself