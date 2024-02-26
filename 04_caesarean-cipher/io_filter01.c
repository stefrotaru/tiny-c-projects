#include <stdio.h>

int main() {
    int ch; // 1

    while ( (ch = getchar()) != EOF ) // 2
        putchar(ch); // 3

    return 0;
}

// 1. I/O deals with integers, not characters.
// 2. Reads input until the end of file si encountered; EOF is an integer value.
// 3. Spews output.

// Input is echoed to output. This is a filter. It reads from standard input and writes to standard output.
// The program demonstrates the basic structure for creating a filter that does something useful.