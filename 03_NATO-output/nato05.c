#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
        n = nato[x];
        t = term;
        while ( *n != '\0' ) {
            if ( (*n|0x20) != (*t|0x20))
                break;
            n++;
            t++;
        }

        if ( *n == '\0' )
            return( *nato[x] );
    }

    return('\0');
}

int main(int argc, char *argv[]) {
    FILE *n;
    char word[64];
    int ch, offset;

    if ( argc < 2 ) { 
        fprintf(stderr, "Please supply a text file argument\n");
        exit(1);
    }

    n = fopen(argv[1], "r");
    if ( n == NULL ) {
        fprintf(stderr, "Unable to open '%s'\n", argv[1]);
        exit(1);
    }

    offset = 0;
    while ( (ch = fgetc(n)) != EOF ) { // 1
        if ( isalpha(ch) ) { // 2
            word[offset] = ch; // 3
            offset++;
            if ( offset >= 64 ) { // 4
                fprintf(stderr, "Buffer overflow\n");
                return(1);
            }
        } 
        else { // 5
            if ( offset > 0 ) { // 6
                word[offset] = '\0'; // 7
                putchar( isterm(word) ); // 8
                offset = 0; // 9
            }
        }
    }

    fclose(n);
    
    return 0;
}

// Beyond peeking into a file for NATO phonetic alphabetic terms,
// this program provides a practical example of how to scan any file for specific words.

// 1. Loops as long as the file has bytes to read
// 2. Words start with a letter of the alphabet
// 3. Stores the character to build the word
// 4. Checks for overflow; bails if so
// 5. A nonalphabetic character is found, meaning the end of a word
// 6. Confirms that the word[] buffer has some text in it
// 7. Cap your strings!
// 8. Processes the word, returning a valid character or the null character (doesn't print)
// 9. Resets the offset to store the next word