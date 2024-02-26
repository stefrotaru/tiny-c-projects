#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ch, r;

    srand( (unsigned) time(NULL) ); // 1

    while ( (ch = getchar()) != EOF ) {
        r = rand() % 2; // 2

        if ( r ) // 3
            putchar(toupper(ch));
        else // 4
            putchar(tolower(ch));
    }

    return 0;
}

// The program reads from standard input and generates output in a random mix of
// upper and lower case.

// stdlib.h and time.h are included for the srand() and rand() functions.
// 1. seed the randomizer
// 2. generate a random number between 0 and 1
// 3. if r is non-zero, output the uppercase equivalent of the input character
// 4. otherwise, output the lowercase equivalent of the input character
// toupper() and tolower() affect only letters;