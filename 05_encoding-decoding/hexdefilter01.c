#include <stdio.h>

int tohex(char c) {
    if ( c >= '0' && c <= '9' ) // 1
        return(c - '0'); // 2
    if ( c >= 'A' && c <= 'F') // 3
        return(c - 'A' + 0xA); // 4
    return -1; // 5
}

int main() {
    int ch, a, b;

    while (1) { // 6
        ch = getchar(); // 7
        if ( ch == EOF ) break; // 8
        a = tohex(ch); // 9
        if ( a < 0 ) break; // 10
        a <<= 4; // 11
        ch = getchar(); // 12
        if ( ch == EOF ) break;
        b = tohex(ch);
        if ( b < 0 ) break;
        putchar(a + b); // 13
    }
    putchar('\n');

    return 0;
}

// converts hex input to ASCII

// 1. Eliminates the digits 0 through 9
// 2. Returns the digit's integer value
// 3. Eliminates the letters A through F
// 4. Returns the character's hex value: 'A' == 0x0A
// 5. All other characters return -1

// 6. The endless loop relies upon the presence o fan EOF to terminate
// 7. Reads a character and immediately...
// 8. ...checks for the EOF and break the loop if found
// 9. Converts the character to a hex value
// 10. Exits if the character isn't hex
// 11. Shifts value a four bits to represent the upper half of the byte in value
// 12. Repeats the process for the next character, but without the shift
// 13. Outputs the resulting byte

// feeding this program the input "48656C6C6F2C207468657265210A" will output "Hello, there!"