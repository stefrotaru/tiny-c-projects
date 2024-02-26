#include <stdio.h>

int tohex(int c) {
    if ( c >= '0' && c <= '9')
        return c - '0';
    if ( c >= 'A' && c <= 'F')
        return c - 'A' + 0xA;
    if ( c >= 'a' && c <= 'f') // 1
       return c - 'a' + 0xA;
    return -1;
}

int main() {
    int ch, a, b;

    while ( (ch = getchar()) != EOF ) {
        if ( ch == '%' ) { // 2
            ch = getchar();
            if ( ch == EOF ) break; // 3
            a = tohex(ch); // 4
            ch = getchar(); // 5
            if ( ch == EOF ) break;
            b = tohex(ch);
            putchar((a << 4) + b); // 6
        }
        else
            putchar(ch);
    }
    
    return 0;
}

// 1. Modified to add lowercase
// 2. Checks for the % sign and grabs the next two characters
// 3. Bails on EOF
// 4. Converts the hex digit into a integer
// 5. Grabs the next character
// 6. Outputs the proper character value