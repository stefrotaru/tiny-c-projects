#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 256

int main() {
    const char filename[] = "pithy.txt";
    FILE *fp;
    char buffer[BSIZE];
    char *r, *entry;
    int items, x;
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

    for ( x = 0; x < items; x++ )
        printf("%d: %s", x, *(list_base + x));

    return 0;
}

// Improving pithy03.c
// 1. Every time items is exactly divisible by 100...
// 2. ... existing storage is increased by 100 pointer-size chunks. The realloc() function is used to increase the storage.