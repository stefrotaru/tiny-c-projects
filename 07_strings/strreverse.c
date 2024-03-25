#include <stdio.h>
#include <stdlib.h>

char *strreverse(char *s) {
    int len, i;
    char *reversed;

    len = 0; // 1
    while ( *s ) { // 2
        len++;
        s++;
    }

    reversed = malloc( sizeof(char) * len ); // 3
    if ( reversed == NULL ) {
        fprintf(stderr, "Unable to allocate memory.\n");
        exit(1);
    }

    s--; // 4
    i = 0; // 5
    while ( len ) { // 6
        *(reversed+i) = *s; // 7
        i++; // 8
        len--; // 9
        s--; // 10
    }
    *(reversed+i) = '\0'; // 11

    return reversed; // 12
}

int main() {
    char s[] = "A string dwelling in memory";

	printf("Before: %s\n",s);
	printf("After: %s\n",strreverse(s));

    return 0;
}

// 1. Variable len contains the offset of the null char and also the string's length
// 2. Loops until *s references the null character terminating the passed string
// 3. Allocates storage for the reversed string; same length as the passed string
// 4. Backs up s over the terminating null character; it now points to the last
// character in the passed string
// 5. Indexes into the new string, reversed
// 6. Copies the number of characters in the original string
// 7. Copies the characters
// 8. Increments the offset for the reversed string
// 9. Decrements the offset for the original string
// 10. Backs up the pointer
// 11. Always cap a newly constructed string with the null character!
// 12. Don't free the pointer here! Its data must be restrained