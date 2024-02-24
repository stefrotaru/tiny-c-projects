#include <stdio.h>
#include <ctype.h>

int main() {
    int ch;

    while ( (ch = getchar()) != EOF ) {
        if ( ch == '-' || ch == '.' || ch == '_' || ch == '*' ) // 1
            putchar(ch);
        else if ( ch == ' ') // 2
            putchar('+');
        else if ( isalnum(ch) ) // 3
            putchar(ch);
        else
            printf("%%%02X", ch); // 4
    }

    return 0;
}

// 1. These characters are allowed in the URL, output as-is.
// 2. Space is replaced by a plus sign.
// 3. Alphanumeric characters are allowed in the URL, output as-is.
// 4. The %% is required to output a single %, and the %02X format specifier is used to output the character as a two-digit hexadecimal number.

// pass in a url to encode it