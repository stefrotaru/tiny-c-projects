#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 1

#define BSIZE 256

int main() {
    const char filename[] = "pithy.txt";
    FILE *fp;
    char buffer[BSIZE];
    char *r, *entry;
    int items;

    fp = fopen(filename, "r");
    if ( fp == NULL) {
        fprintf(stderr, "unable to open file %s\n", filename);
        exit(1);
    }

    items = 0;
    while ( !feof(fp) ) { // 2
        r = fgets(buffer, BSIZE, fp);
        if ( r == NULL )
            break;

        entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1); // 3
        if ( entry == NULL ) {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(1);
        }
        strcpy(entry, buffer); // 4
        printf("%d: %s", items, entry);
        items++;
    }

    fclose(fp);

    return 0;
}

// pithy01.c with memory allocation added

// 1. Required for the strcpy() and strlen() functions
// 2. Within the while loop, memory is allocated for variable entry. The pointer must be tesetd to ensure memory is available. Then the conetnts of buffer[] are copied to entry, the contents of entry output, andthe items variable incremented.
// 3. Enough storage for the strin, plus one for the null character
// 4. The contents of buffer are copied to entry