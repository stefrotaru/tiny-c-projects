#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *left(char *s, int len) {
    char *buf; // 1
    int x;

    buf = malloc( sizeof(char) * len + 1 ); // 2
    if ( buf == NULL ) {
        fprintf(stderr, "Unable to allocate memory.\n");
        exit(1);
    }

    for ( x = 0; x < len; x++ ) { // 3
        if ( *(s+x) == '\0' ) // 4
            break;
        *(buf+x) = *(s+x); // 5
    }
    *(buf+x) = '\0'; // 6

    return buf;
}

// 1. Storage for the new string
// 2. Allocates storage for the new string, plus one for the null char
// 3. Copies the len characters
// 4. Checks for an unexpected null char and terminates the loop if found
// 5. Copies the characters
// 6. Caps the newly created string


char *right(char *s, int len) {
    char *buf;
    char *start;
    int x;

    buf = (char *)malloc( sizeof(char) * len + 1 );
    if ( buf == NULL ) {
        fprintf(stderr, "Unable to allocate memory.\n");
        exit(1);
    }

    start = s; // 7
    while(*start != '\0') // 8
        start++;
    start -= len; // 9
    if ( start < s ) // 10
        exit(1);

    for ( x = 0; x < len; x++ ) // 11
        *(buf+x) = *(start+x);
    *(buf+x) = '\0'; // 12

    return buf;
}

// 7. Uses the pointer start as the offset to retain for later the address in
// variable s
// 8. Searches for the end of the string
// 9. Adjusts the pointer start to reference where the right end of the string
// starts
// 10. Checks for underflow and exits if true
// 11. Copies the rightmost portion of the string into the new buffer
// 12. Caps the newly created string


char *mid(char *s, int offset, int len) { // 13
    char *buf;
    int x;

    buf = (char *)malloc( sizeof(char) * len + 1 );
    if ( buf == NULL ) {
        fprintf(stderr, "Unable to allocate memory.\n");
        exit(1);
    }

    for ( x = 0; x < len; x++ ) { // 14
        *(buf+x) = *(s+offset-1+x); // 15
        if ( *(buf+x) == '\0' ) // 16
            break;
    }
    *(buf+x) = '\0'; // 17

    return buf;
}

// 13. *s = the strin to slice; offset = the starting point; len = the number of
// characters to extract
// 14. Copies len number of chars
// 15. The offset value is decresed by 1 because the first character is offset 0,
// not offset 1
// 16. Catches any overflow and stops
// 17. Caps the newly created string


int main() {
    char string[] = "Slice me, dice me, make Julienne fries!";

    printf("Original: %s\n", string);
    printf("Left    : %s\n", left(string,8));
    printf("Mid     : %s\n", mid(string,11,7));
    printf("Right   : %s\n", right(string,20));

    return 0;
}