#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 256

int main() {
    const char filename[] = "pithy.txt";
    FILE *fp;
    char buffer[BSIZE];
    char *r, *entry;
    int items, saying;
    char **list_base;

    fp = fopen(filename, "r");
    if ( fp == NULL) {
        fprintf(stderr, "unable to open file %s\n", filename);
        exit(1);
    }

    list_base = (char **)malloc(sizeof(char *) * 100);
    if ( list_base == NULL ) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    items = 0;
    while ( !feof(fp) ) {
        r = fgets(buffer, BSIZE, fp);
        if ( r == NULL )
            break;

        entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
        if ( entry == NULL ) {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(1);
        }
        strcpy(entry, buffer);
        *(list_base + items) = entry;
        items++;
    }

    if ( items % 100 == 0 ) { // 1
        list_base = (char **)realloc(list_base, sizeof(char *) * (items + 100)); // 2

        if ( list_base == NULL ) {
            fprintf(stderr, "Unable to reallocate memory\n");
            exit(1);
        }
    }

    fclose(fp);

    srand( (unsigned)time(NULL) ); // using srand() to seed the random number generator
    saying = rand() % (items - 1);
    printf("%s", *(list_base + saying));

    return 0;
}

// Improving pithy04.c for our usecase, which is to output a random line from the file pithy.txt
// The program doesn't release any memory directly. Normally, the end of a function would be dotted wtih free() statements, one for each memory chunk allocated. Because the entire code dwells within the main() function, freeing memory isn't necessary. The memory allocated is freed wen the program quits.
// Had the allocation taken place in a function, however, it's necessary to release the allocation or risk losing the memory chunk and potentially cause a memory overflow.

// TODO: Incorporate the pithy05.c code into the daily-greetings project