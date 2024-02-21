#include <stdio.h>
#include <ctype.h>

int main() {
    int shift, ch;

    shift = 'D' - 'A'; // 1

    while ( (ch = getchar()) != EOF ) {
        if ( isalpha(ch) ) { // 2
            ch += shift; // 3
            if ( (ch > 'Z' && ch < 'a') || ch > 'z' ) { // 4
                ch -= 26; // 5
            }
            putchar(ch);
        }
    }
    
    return 0;
}

// 1. Shifts from A to D, which is done backward here because math
// 2. Handles letters specifically
// 3. Shifts the letters
// 4. Determines wether the new character is out of range
// 5. If so, adjusts its value back within range