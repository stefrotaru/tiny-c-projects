#include <stdio.h>
#include <stdlib.h>

#define BSIZE 256

int main() {
    const char filename[] = "pithy.txt"; // 1
    FILE *fp;
    char buffer[BSIZE]; // 2
    char *r;

    fp = fopen(filename, "r"); // 3
    if ( fp == NULL) {
        fprintf(stderr, "unable to open file %s\n", filename);
        exit(1);
    }

    while ( !feof(fp) ) { // 4
        r = fgets(buffer, BSIZE, fp); // 5
        if ( r == NULL )
            break;
        printf("%s", buffer); // 6
    }

    fclose(fp);

    return 0;
}

// 1. The file is assumed to be in the same directory as the program
// 2. The buffer is used to read text from the file, the sze is a guess defined just before main()
// 3. open the file for reading
// 4. loops as long as the file isn't empty
// 5. the variable r ensures that fgets() doesn't mess up and read beyond the end of the file; if so, the loop stops
// 6. Outputs all the lines in the file

// The purpose is to read all the lines from the file. Each line is stored in char array buffer[] and then output. The same buffer is used over and over.