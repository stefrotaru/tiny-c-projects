#include <stdio.h>
#include <stdlib.h> // 1
#include <string.h> // 1

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE * 3 + 1)

int main() {
    char line[LENGTH];
    int x, ch;
    char *r; // 2

    r = fgets(line, LENGTH, stdin); // 3
    if ( r == NULL || strncmp(line, "HEX ENCODE", 10) != 0 ) { // 4
        fprintf(stderr, "Invalid HEX ENCODE data\n"); // 5
        exit(1);
    }

    x = 0;
    while ( (ch = getchar()) != EOF ) {
        line[x] = ch;
        x++;
        if ( ch == '\n' || x == LENGTH ) {
            if ( line[x - 1] == '\n' )
                line[x-1] = '\0';
            else
                line[x] = '\0';
            
            printf("%s\n", line);
            x = 0;   
        }
    }

    return 0;
}



// 1. needed for exit() and strncmp()
// 2. this pointer holds the return value from the fgets(), which is used to determine wether input is valid.
// 3. the first line of input is gobbled up
// 4. fgets() returns NULL on invalid input; otherwise, strncmp() performs
// an exact comparison on the first line of text versus the required text.
// 5. an error message is sent to the standard error devide to avoid output
// confusion 
