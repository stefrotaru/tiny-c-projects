#include <stdio.h>

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE * 3 + 1) // 1

int main() {
    char line[LENGTH];
    int x, ch;

    x = 0;
    while ( (ch = getchar()) != EOF ) {
        line[x] = ch; // 2
        x++; // 3
        if ( ch == '\n' || x == LENGTH ) { // 4
            if ( line[x - 1] == '\n' ) // 5
                line[x-1] = '\0';
            else
                line[x] = '\0';
            
            printf("%s\n", line); // 6
            x = 0;   
        }
    }

    return 0;
}

// 1. Calculates the buffer size for the number of bytes times the number of spaces used, plus one for the null char
// 2. Stores incoming characters in the buffer
// 3. Increments th offset
// 4. Checks for newline (as the decoded file is formatted) or a full buffer
// 5. Replaces the newine with a null char; otherwise, caps the string
// 6. Outputs the line, unmodified