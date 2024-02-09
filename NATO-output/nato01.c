#include <stdio.h>
#include <ctype.h> // 1

int main() {
    const char *nato[] = {
        "Alpha", "Bravo", "Charlie", "Delta", "Echo",
        "Foxtrot", "Golf", "Hotel", "India", "Juliett",
        "Kilo", "Lima", "Mike", "November", "Oscar",
        "Papa", "Quebec", "Romeo", "Sierra", "Tango",
        "Uniform", "Victor", "Whiskey", "Xray", "Yankee",
        "Zulu"
    };
    char phrase[64];
    char ch;
    int i;

    printf("Enter a word or phrase: ");
    fgets(phrase, 64, stdin); // 2

    i = 0;
    while( phrase[i] ) { // 3
        ch = toupper(phrase[i]); // 4
        if ( isalpha(ch) ) // 5
            printf("%s ", nato[ch-'A']); // 6
        i++;
        if ( i==64 ) // 7
            break;
    }
    putchar('\n');

    return 0;
}

// 1. Include the ctype.h library for the toupper() and isalpha() functions
// 2. Stores into location phrase 63 characters (+ the null character) from stdin
// 3. Loops until the null character is found in the string
// 4. Converts the character to uppercase
// 5. Checks if it is an alphabetic character
// 6. ch-'A' transforms the letters to values 0-25, matching the correscponding array element
// 7. A long string may not have a null character, so bail if the buffer size is reached