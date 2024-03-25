#include <stdio.h>
#include <ctype.h>

void strcaps(char *s) {
    enum { FALSE, TRUE }; // 1
    int inword = FALSE;

    // 2
    while (*s) {
        if ( isalpha(*s) ) { // 3
            if ( !inword ) { // 4
                *s = toupper(*s); // 5
                inword = TRUE; // 6
            }
        }
        else { // 7
            inword = FALSE; // 8
        }
        s++; // 9
    }
}

int main() {
    char string[] = "This is a sample string that should get capitalized.";

    printf("Original string : %s\n", string);
    strcaps(string);
    printf("Uppercase string: %s\n", string);

    return 0;
}

// 1. create TRUE/FALSE constants, 0 and 1
// 2. loop through the string until *s == '\0'
// 3. look for alphabetic characters
// 4. is a word being processed? if not...
// 5. convert first letter to uppercase
// 6. currently inside a word
// 7. non alphabetic character here
// 8. not in a word
// 9. continue processing the string