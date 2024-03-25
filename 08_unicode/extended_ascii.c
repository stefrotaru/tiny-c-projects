#include <stdio.h>

int main() {
    int x, y;

    printf("      "); // 1
    for ( x = 0; x < 16; x++ )
        printf(" %X ", x); // 2
    putchar('\n');

    for ( x = 0x80; x < 0x100; x += 0x10 ) { // 3
        printf(" 0x%2x ", x);
        for ( y = 0; y < 10; y++ )
            printf(" %c ", x+y); // 4
        putchar('\n');
    }

    return 0;
}

// 1. 6 spaces to line up output
// 2. Output header row
// 3. Output left column
// 4. Inner loop that outputs characters, x + y, calculating proper offset