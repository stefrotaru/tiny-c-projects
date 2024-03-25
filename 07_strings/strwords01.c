#include <stdio.h>
#include <ctype.h>

int strwords(char *s) {
    enum { FALSE, TRUE }; // 1
    int inword = FALSE; // 2
    int count;

    count = 0; // 3
    while ( *s ) { // 4
        if ( isalpha(*s) ) { // 5 
            if ( !inword ) { // 6
                count++; // 7
                inword = TRUE; // 8
            }
        }
        else {
            inword = FALSE; // 9
        }
        s++;
    }

    return count;
}

int main() {
    char string[] = "This is a sample string";

    printf("The string '%s' contains %d words\n", string, strwords(string));

    return 0;
}

// 1. Creates the constants FALSE = 0 and TRUE = 1
// 2. Starts out assuming the code isn't reading inside of a word
// 3. Word count initialized
// 4. Loops through the string
// 5. Is the current letter alphabetic?
// 6. Confirms that a word isn't being processed
// 7. Inside the word, increments the count
// 8. Resets the inword variable
// 9. For nonalpha characters, inword is FALSE