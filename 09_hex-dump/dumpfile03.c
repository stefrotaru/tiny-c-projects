#include <stdio.h>
#include <stdlib.h>
#include <string.h> // required for filename copying

#define SIZE 16

void line_out(int offset, int length, unsigned char *data) {
	int a;

	printf("%05X ", offset);

	for( a = 0; a < length; a++ ) {
		printf(" %02X", *(data+a));
		if( (a+1) % 8 == 0 )
			putchar(' ');
	}

    if ( length < SIZE ) {
        for( ; a < SIZE; a++ ) {
			printf("   ");
			if( (a+1) % 8 ==0 )
				putchar(' ');
		}
    }

	putchar(' ');
	for( a = 0; a < length; a++ ) {
		if( *(data+a) >= ' ' && *(data+a) <= '~' )
			putchar( *(data+a) );
		else
			putchar(' ');
	}

	putchar('\n');
}

int main(int argc, char *argv[]) {
	unsigned char buffer[SIZE];
	char filename[BUFSIZ]; // BUFSIZ is defined in stdio.h
    char *r; // for the fgets() function return value
	FILE *fp;
	int ch, offset, index;

	if ( argc < 2 ) {
		printf("Filename: ");
        r = fgets(filename, BUFSIZ, stdin);

        if ( r == NULL || filename[0] == '\n') {
            exit(1);
        }

        while ( *r != '\n' ) { // r = the string entered
            r++;
            if ( r-filename==BUFSIZ ) // check for overflow
                exit(1);
        }
        *r = '\0'; // replace the newline character with a null character
	}
    else {
        strcpy(filename, argv[1]);
    }

	fp = fopen(filename, "r");
	if( fp==NULL ) {
		fprintf(stderr, "Unable to open file '%s'\n", filename);
		exit(1);
	}

	offset = 0;
	index = 0;
	while( !feof(fp) ) {
		ch = fgetc(fp);
		if ( ch==EOF ) {
			if ( index != 0 )
				line_out(offset, index, buffer);
			break;
		}
		buffer[index] = ch;
		index++;
		if( index==SIZE )	{
			line_out(offset, SIZE, buffer); 
			offset += SIZE; 
			index = 0; 
		}
	}

	fclose(fp);

	return 0;
}