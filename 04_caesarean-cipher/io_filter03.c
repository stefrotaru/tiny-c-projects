#include <stdio.h>
#include <ctype.h> // 1

int main() {
    int ch;

    while ( (ch = getchar()) != EOF )
        if ( islower(ch) ) // 2
            putchar(toupper(ch)); // 3
        else
            putchar(ch);

    return 0;
}

// This program reads from standard input and generates output in ALL CAPS. It's a simple filter.

// 1. The toupper(), islower() functions are declared in the ctype.h header file.
// 2. The islower() function returns a non-zero value if the argument is a lowercase letter.
// 3. The toupper() function returns the uppercase equivalent of the argument if it's a lowercase letter.