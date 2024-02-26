#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE * 3 + 1)

int main() {
    char line[LENGTH];
    int x, ch, hex;
    int checksum, row, b;
    float version;
    char *r;

    // check for proper file format
    r = fgets(line, LENGTH, stdin);
    if ( r == NULL || strncmp(line, "HEX ENCODE", 10) != 0 ) {
        fprintf(stderr, "Invalid HEX ENCODE data\n");
        exit(1);
    }

    sscanf(line, "HEX ENCODE v%f", &version);

    x = 0;
    row = 0;
    while ( (ch = getchar()) != EOF ) {
        line[x] = ch;
        x++;
        if ( ch == '\n' || x == LENGTH ) {
            if ( line[x - 1] == '\n' )
                line[x-1] = '\0';
            else
                line[x] = '\0';

            if ( strncmp(line, "HEX ENCODED END", 13) == 0 )
                break;

            // extract values
            checksum = 0;
            b = 0;
            r = strtok(line, " ");
            while (r) {
                sscanf(r, "%02X", &hex);
                if ( b < BYTES_PER_LINE ) {
                    checksum += hex;
                    printf("%c", hex);
                    r = strtok(NULL, " ");
                    b++;
                }
                else {
                    if ( hex != (checksum % 0x100) ) {
                        fprintf(stderr, "Checksum error on row %d\n", row);
                        fprintf(stderr, "Unable to decode data\n");
                        exit(1);
                    }
                    break;
                }
            }
            x = 0;   
            row++;
        }
    }

    return 0;
}