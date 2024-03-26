#include <stdio.h>

int main() {
    unsigned char i; // 1

    i = 0;
    while ( 1 ) { // 2
        printf("%d\n", i); // 3
        if ( i == 255 ) // 4
            break;
        i++; // 5
    }

    return 0;
}

// 1. The range for unsigned char is from 0 to 255
// 2. Loops endlessly
// 3. Outputs the value
// 4. Once the value hits 255, breaks the loop
// 5. Otherwise, increments the value by one