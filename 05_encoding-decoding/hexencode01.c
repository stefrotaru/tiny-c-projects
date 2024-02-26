#include <stdio.h>

#define BYTES_PER_LINE 18 // 1

int main() {
    int ch, bytes;

    bytes = 0; // 2
    printf("HEX ENCODE v1.0\n"); // 3
    while ( (ch = getchar()) != EOF ) {
        printf(" %02X ", ch);
        bytes++;
        if ( bytes == BYTES_PER_LINE ) {  // 4
            putchar('\n'); // 5
            bytes = 0; // 6
        }
    }
    printf("\nHEX ENCODE END\n"); // 7

    return 0;
}

// 1. Set this value as a defined constant so that it can be updated easily
// 2. Initialize the byte counter
// 3. Outputs the header line before processing standard input
// 4. Checks for the end of the line
// 5. If so, outputs a newline...
// 6. ...and resets the byte counter
// 7. After processing standard input (including EOF), outputs the tail line

// try to echo "Hello, there!" | ./hexencode01
// the output should be the hexadecimal representation of the input