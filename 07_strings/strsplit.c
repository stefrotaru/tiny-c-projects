#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strsplit()

int strsplit(char *org, int offset, char **s1, char **s2) { // 0
    int len;

    len = strlen(org); // 1
    if ( offset > len ) // 2
        return 0;

    *s1 = malloc(sizeof(char) * offset + 1); // 3
    *s2 = malloc(sizeof(char) * len - offset + 1); // 4
    if ( s1 == NULL || s2 == NULL ) // 5
        return 0;
    
    strncpy(*s1, org, offset); // 6
    strncpy(*s2, org+offset, len-offset); // 6

    return 1;
}

// 0. Pointer org = string to split
//    int offset = the location of the split
//    char **s1 = pointer to the first part of the split (passed by reference)
//    char **s2 = pointer to the second part of the split (passed by reference)
// 1. Obtains the original string's lenght
// 2. If the offset argument is out of range, return 0--error
// 3. Allocate storage for split string 1, argument s1 dereferenced
// 4. Allocate storage for split string 2, calculating the proper size
// 5. Returns an error if either allocation fails
// 6. Copies the proper number of chars into the new string


int main() {
    char string[] = "When this baby hits 88 miles per hour";
    char *first, *second;
    int r;

    r = strsplit(string, 15, &first, &second);
    if ( r == 1 ) {
        printf("Split succesful\n");
        printf("'%s' split into:\n", string);
        printf("'%s'\n", first);
        printf("'%s'\n", second);
    }
    else {
        puts("The function was unable to split the string");
    }

    return 0;
}