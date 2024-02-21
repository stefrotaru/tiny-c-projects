#include <stdio.h>
#include <ctype.h>

int main() {
    int shift, ch;

    shift = 'A' - 'D';

    while ( (ch = getchar()) != EOF ) {
        if ( isalpha(ch) ) {
            ch += shift;
            if ( ch < 'A' || (ch > 'Z' && ch < 'a') ) {
                ch += 26;
            }
            putchar(ch);
        }
    }
    
    return 0;
}

// This filter cand be used to decrypt the output of caesar02.c

// As with any filter, you can pipe output through both filters to recover the
// original text
// Example: echo "Hello world" | ./caesar02 | ./caesar03