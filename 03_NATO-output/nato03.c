#include <stdio.h>
#include <string.h>

char isterm(char *term) {
    char *nato[] = {
        "Alpha", "Bravo", "Charlie", "Delta", "Echo",
        "Foxtrot", "Golf", "Hotel", "India", "Juliett",
        "Kilo", "Lima", "Mike", "November", "Oscar",
        "Papa", "Quebec", "Romeo", "Sierra", "Tango",
        "Uniform", "Victor", "Whiskey", "Xray", "Yankee",
        "Zulu"
    };
    int x;
    char *n, *t;

    for ( x = 0; x < 26; x++) {
        n = nato[x]; // 1
        t = term; // 2
        while ( *n != '\0' ) { // 3
            if ( (*n|0x20) != (*t|0x20)) // 4
                break; // 5
            n++;
            t++; // 6
        }

        if ( *n == '\0' ) // 7
            return( *nato[x] ); // 8
    }

    return('\0');
}

int main() {
    char phrase[64];
    char *match;
    char ch;
    printf("NATO word of phrase: ");
    fgets(phrase, 64, stdin);

    match = strtok(phrase, " ");
    while ( match ) {
        if ( (ch = isterm(match)) != '\0' ) // 9
            putchar(ch); // 10
        match = strtok(NULL, " "); // 11
    }
    putchar('\n');

    return(0);
}

// The isterm() function accepts a word as its argument. The return value is a single character if 
// the word matches a NATO phonetic alphabet term; otherwise the null character is returned.

// 1. Sets pointer n to the current NATO word
// 2. Pointer t references the term passed.
// 3. Loops until the NATO terms ends.
// 4. Logically converts each letter to uppercase and compares. 
//    reference: https://en.wikipedia.org/wiki/Bitwise_operations_in_C
// 5. For no match, the loop breaks and the next term in nato[] is compared.
// 6. Increments through each letter.
// 7. When pointer n is the null character, the terms have matched.
// 8. Returns the first letter of the NATO term.

// The main() function scans the line input for any matching phonetic alphabet terms. The isterm()
// function handles the job. The matching character is returned and output.

// 9. If the return value is not the null character, the term is a match.
// 10. Outputs the matching character.
// 11. The next term is processed.


// TODO: Add in code to translate special characters, such as punctuation characters.