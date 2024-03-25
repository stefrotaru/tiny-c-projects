#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strappend(char *dest, char *src) {
    return strcat(dest, src); // 1
}

int main() {
    char s1[32] = "This is another "; // 2
    char s2[] = "fine mess!";
    char *s3;

    s3 = strappend(s1, s2);
    printf("%s\n", s3);

    return 0;
}

// 1. The strcat() function appends the src string to the dest string overwriting
// the '\0' character at the end of dest, and then adds a terminating '\0'
// character. The strings may not overlap, and the dest string must have enough
// space for the result.
// 2. Array s1 contains enough storage for both strings.

// strappend() doesn't really create a new string. It merely returns a pointer to
// the first string passed, which now contains both strings.