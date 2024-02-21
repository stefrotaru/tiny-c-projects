#include <stdio.h>

int main() {
    int ch, wrap;

    wrap = 0; // 1
    while ( (ch = getchar()) != EOF ) {
        printf("%02X ", ch);
        wrap += 3; // 2

        if ( wrap > 77 || ch == '\n' ) { // 3
            putchar('\n'); // 4
            wrap = 0; // 5
        }
    }

    return 0;
}

// 1. initializa the wrap
// 2. each printf() output is 3 characters wide
// 3. if the terminal column width is 80
// 4. print a newline
// 5. reset the wrap value

// here's a very long english word to text this program:
// pneumonoultramicroscopicsilicovolcanoconiosis