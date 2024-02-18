#include <stdio.h>
#include <ctype.h>

int main() {
    int ch;

    while ( (ch = getchar()) != EOF ) {
        if (isalpha(ch)) { // 1
            if (toupper(ch) >= 'A' && toupper(ch) <= 'M') // 2
                ch += 13; // 3
            else
                ch -= 13; // 4
        }
        putchar(ch);
    }

    return 0;
}


// This code uses isalpha() function to weed out letters of the alphabet.
// The toupper() function converts the letters to uppercase so that it can test
// for characters in the range from A through M. If so, there characters are
// shifted up 13 places: ch+=13. Otherwise, the else statement catches the higher
// letters of the alphabet, shiftingthem down.

// 1. Only processes alphabet characters.
// 2. Searches for "A" through "M" or "a" through "m".
// 3. Shifts up for the lower half of the alphabet.
// 4. Otherwise, shifts down.

// test: echo "Hello, World!" | ./caesar01
// or run directly to be prompted for input to filter