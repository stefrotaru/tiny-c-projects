#include <stdio.h>
#include <ctype.h> // 1

int tohex(int c) {
    if ( c >= '0' && c <= '9')
        return c - '0';
    if ( c >= 'A' && c <= 'F')
        return c - 'A' + 0xA;
    if ( c >= 'a' && c <= 'f')
       return c - 'a' + 0xA;
    return -1;
}

int main() {
    int ch, a, b;

    while ( (ch = getchar()) != EOF ) {
        if ( ch == '%' ) {
            ch = getchar();
            if ( ch == EOF ) break;
            a = tohex(ch);
            ch = getchar();
            if ( ch == EOF ) break;
            b = tohex(ch);
            putchar((a << 4) + b);
        }
        else { // 2
            if ( ch == '-' || ch == '.' || ch == '_' || ch == '*' )
                putchar(ch);
            else if (isalnum(ch))
                putchar(ch);
            else {
                fprintf(stderr, "Invalid character: %c\n", ch);
                break;
            }
        }
        

    }
    return 0;
}

// 1. We need to include ctype.h to use the isalnum function
// 2. Do more filtering here