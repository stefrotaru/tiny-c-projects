#include <stdio.h>

int main() {
    char sentence[] = "This Is A Test Sentence\n";
    char *s;

    s = sentence;
    while (*s) {
        if ( *s >= 'A' && *s <= 'Z' ) // 1
            putchar( *s | 0x20 ); // 2
        else
            putchar( *s );
        s++;
    }

    s = sentence;
    while (*s) {
        if ( *s >= 'a' && *s <= 'z' ) // 3
            putchar( *s & 0xdf ); // 4
        else
            putchar( *s );
        s++;
    }

    return 0;
}

// converts sentence to lowercase and then uppercase
// 1. Filters out uppercase text
// 2. Outputs the lowercase character
// 3. Filters out lowercase text
// 4. Outputs the uppercase character