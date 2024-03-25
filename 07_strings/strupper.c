#include <stdio.h>

void strupper(char *s) {
    while (*s) { // 1
        if ( *s >= 'a' && *s <= 'z' ) { // 2
            *s &= 0xdf; // 3
        }
        s++;
    }
}

int main() {
    char string[] = "Random STRING sample 123&^#";

    printf("Original string: %s\n", string);
    strupper(string);
    printf("Uppercase string: %s\n", string);

    return 0;
}

// 1. Loops until *s references the null char (end of the string)
// 2. Changes only lowercase letters
// 3. Resets the 6th bit to convert to uppercase