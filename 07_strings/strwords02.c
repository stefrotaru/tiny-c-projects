#include <stdio.h>
#include <ctype.h>

int strwords(char *s) {
    enum { FALSE, TRUE };
    int inword = FALSE;
    int count;

    count = 0;
    while ( *s ) {
        if ( isspace(*s) ) { // 1
            if ( inword ) {
                count++;
                inword = FALSE;
            }
        }
        else {
            inword = TRUE;
        }
        s++;
    }

    if ( inword == TRUE ) // 2
        count++;

    return count;
}

int main() {
    char string[] = "This isn't a sample string";

    printf("The string '%s' contains %d words\n", string, strwords(string));

    return 0;
}

// 1. whitespace encountered
// 2. if we end inside a word, count it