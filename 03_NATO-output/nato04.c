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
    char phrase[64];
    char *match, ch;

    if ( argc < 2 ) { 
        fprintf(stderr, "Please supply a text file argument\n");
        exit(1);
    }

    n = fopen(argv[1], "r");
    if ( n == NULL ) {
        fprintf(stderr, "Unable to open '%s'\n", argv[1]);
        exit(1);
    }

    while ( !feof(n) ) { // 1
        fgets(phrase, 64, n); // 2
        match = strtok(phrase, " ,.!?=()[]{}'\""); // 3
        while (match) { // 4
            if ( (ch = isterm(match)) != '\0' ) // 5
                putchar(ch);
            match = strtok(NULL, " ,.!?=()[]{}'\""); // 6
        }
    }
    putchar('\n');

    fclose(n);
    
    return 0;
}

// nato02.c mixed with nato03.c
// Processes an open file by using two while loops.
// For this program, I've created test.txt to use as input

// 1. Loops until the end of open file handler n
// 2. Grabs a line of text up to 63 characters
// 3. Filters out a lot of characters
// 4. Loops until all the words in the line are read
// 5. Sends the matching word off to the isterm() function