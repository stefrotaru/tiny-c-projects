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
    char **list_base; // 1

    fp = fopen(filename, "r");
    if ( fp == NULL) {
        fprintf(stderr, "unable to open file %s\n", filename);
        exit(1);
    }

    list_base = (char **)malloc(sizeof(char *) * 100); // 2
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
        *(list_base + items) = entry; // 3
        items++;
    }

    fclose(fp);

    for ( x = 0; x < items; x++ )
        printf("%d: %s", x, *(list_base + x)); // 4

    return 0;
}

// Improving pithy02.c 
// As the program sits now, it allocates a series of buffers to store the strings read. Yet the addresses for these buffers are lost in memory. To resolve this issue, a pointer-pointer (address of pointer operator) is required.

// 1. The list_base variable keeps track of the entry pointers allocated later in the code. But first, the list_base pointer must be allocated itself.
// 2. The list_base is a pointer-pointer variable. It is allocated enough stoarge to hold 100 entries. The typecast (char **) matches the variable's data type.
// 3. Using the offset provided by the items count, this statement copies the address store in pointer variable entry into the list maintained at location list_base. Only the address is copied, not the whole string.
// 4. In this loop, variable x sets the offset in the list of addresses: *(list_base + x) references each line of text read from the file, now stored in memory. The output is the same as before, but the addresses are now stored in list_base.