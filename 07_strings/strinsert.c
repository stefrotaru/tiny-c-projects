#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strinsert(char *org, char *ins, int offset) {
    char *new;
    int size, index, append;

    size = strlen(org) + strlen(ins); // 1
    if ( offset < 0 ) // 2
        return NULL;
    
    new = malloc(sizeof(char) * size + 1); // 3
    if ( new == NULL ) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    offset -= 1; // 4
    index = 0; // 5
    append = 0; // 6
    while ( *org ) {
        if ( index == offset ) { //8
            while ( *ins ) { // 9
                *(new + index) = *ins;
                index++;
                ins++;
            }
            append = 1; // 10
        }
        *(new + index) = *org; // 11
        index++;
        org++;
    }
    if ( !append ) { // 12
        while ( *ins ) {
            *(new + index) = *ins;
            index++;
            ins++;
        }
    }
    *(new + index) = '\0'; // 13

    return new;
}

// 1. Obtains the size of the string
// 2. Returns an empty string if the offset is a silly value
// 3. Allocates storage for the new string
// 4. Reduces the offset value to account for strings starting at 0, not 1
// 5. Indexes to track progress through the new string
// 6. Status varriable to track whether ins string has been inserted
// 7. Loops through the original string
// 8. Immediately checks for the offset value to account for offset = 0
// 9. Inserts ins string, adding it to string new
// 10. Marks that the string has been inserted
// 11. Continues building the new string from the original string
// 12. Confirms that a string was inserted; if not, string ins is appended
// 13. Adds the null terminator to the new string

int main() {
    char s1[] = "Well, this is another mess!";
	char s2[] = "fine ";

	printf("Before: %s\n",s1);
	printf("After : %s\n",strinsert(s1,s2,23));

	return 0;
}