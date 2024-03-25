#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strappend(char *dest, char *src) {
    char *s;
    char *index;

    // 1
    s = malloc(strlen(dest) + strlen(src) + 1); // 2

    if ( s==NULL ) { // 2
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // 3
    index = s; // 4
    while ( *dest ) { // 5
        *index = *dest; // 6
        index++; // 7
        dest++; // 8
    }

    // 9
    while ( *src ) {
        *index = *src;
        index++;
        src++;
    }
    *index = '\0'; // 10

    return s;
}

int main() {
    char s1[] = "This is, yet again, another ";
    char s2[] = "fine mess!";
    char *s3;

    s3 = strappend(s1, s2);
    printf("%s\n", s3);

    return 0;
}

// 1. Allocate storage for new string. Can't use sizeof because dest is a pointer.
// 2. The +1 is for the null character.
// 3. Copy the first string
// 4. Initialize offset
// 5. Loop unti \0 is found
// 6. copy the character
// 7. Increment offset
// 8. Increment string
// 9. Copy the second string
// 10. Properly terminate the new string