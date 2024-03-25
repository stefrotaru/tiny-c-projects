#include <stdio.h>

void strlower(char *s) {
    while (*s) {
        if ( *s >= 'A' && *s <= 'Z' ) { // 1
            *s += 32; // 2
        }
        s++;
    }
}

int main() {
    char string[] = "Random STRING sample 123&^#";

    printf("Original string: %s\n", string);
    strlower(string);
    printf("Uppercase string: %s\n", string);

    return 0;
}

// 1. Converts only uppercase letters
// 2. Adds 32 to convert to lowercase