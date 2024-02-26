#include <stdio.h>
#include <ctype.h>

#define WORDSIZE 64 // 1

int main() {
    char word[WORDSIZE];
    int ch, offset;

    offset = 0; // 2
    while ( (ch = getchar()) != EOF ) {
        if ( isspace(ch) ) { // 3
            word[offset] = '\0'; // 4
            if ( offset > 0 ) // 5
                printf("%s\n", word); // 6
            offset = 0; // 7
        }
        else { // 8
            word[offset] = ch; // 9
            offset++; // 10
            if ( offset == WORDSIZE - 1 ) { // 11
                word[offset] = '\0'; // 12
                printf("%s\n", word); // 13
                offset = 0; // 14
            }
        }
    }

    return 0;
}

// 1. The word size is set here
// 2. Initializes the offset value
// 3. The isspace() function return TRUE for whitespace characters, marking the end of a word
// 4. Always cap your strings!
// 5. Ensures that the buffer has text in it to print
// 6. Outputs the buffer's content (a word) on a line by itself
// 7. Resets the offset
// 8. Printable characters are handled here, filling the buffer
// 9. Stores the character
// 10. Increments the offset
// 11. Checks for potential overflow, a full buffer
// 12. Cap the string!
// 13. Outputs the word, dumping the buffer
// 14. Resets the buffer