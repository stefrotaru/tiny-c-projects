#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    const char *nato[] = {
        "Alpha", "Bravo", "Charlie", "Delta", "Echo",
        "Foxtrot", "Golf", "Hotel", "India", "Juliett",
        "Kilo", "Lima", "Mike", "November", "Oscar",
        "Papa", "Quebec", "Romeo", "Sierra", "Tango",
        "Uniform", "Victor", "Whiskey", "Xray", "Yankee",
        "Zulu"
    };
    FILE *n;
    int ch;

    if ( argc < 2 ) { // 1
        fprintf(stderr, "Please supply a text file argument\n");
        exit(1);
    }

    n = fopen(argv[1], "r"); // 2
    if ( n == NULL ) {
        fprintf(stderr, "Unable to open '%s'\n", argv[1]);
        exit(1);
    }

    while ( (ch = fgetc(n)) != EOF ) { // 3
        if( isalpha(ch) ) // 4
            printf("%s ", nato[toupper(ch) - 'A']); // 5
    }
    putchar('\n');

    fclose(n);
    
    return 0;
}

// 1. If fewer than two arguments are present, the filename option is missing
// 2. Open the filename supplied at the command prompt, referenced as argv[1]
// 3. Reads one character at a time from the file, storing it in variable ch. The EOF marks the end of the file
// 4. Processes only text characters
// 5. Uses the uppercase version of the character, minus the value of 'A' to index the nato[] array

// Fot this program, I added a text file with a famous Shakespeare poem, Shall I compare thee to a summer's day? (shall-i-compare.txt)
// To run the program, add the filename as an argument