#include <stdio.h>
#include <stdlib.h>

void line_out(int offset, int length, unsigned char *data) {
	int a;

	printf("%05X ", offset);

	for( a = 0; a < length; a++ ) {
		printf(" %02X", *(data+a));
		if( (a+1) % 8 == 0 )
			putchar(' ');
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
	const int length = 16;
	unsigned char buffer[length];
	char *filename;
	FILE *fp;
	int ch, offset, index;

	if( argc<2 ) {
		fprintf(stderr, "Format: dumpfile filename\n");
		exit(1);
	}

	filename = argv[1];
	fp = fopen(filename, "r");
	if( fp==NULL ) {
		fprintf(stderr, "Unable to open file '%s'\n", filename);
		exit(1);
	}

	offset = 0;
	index = 0;
	while( !feof(fp) ) { // 1
		ch = fgetc(fp); // 2
		if ( ch==EOF ) { // 3
			if ( index != 0 ) // 4
				line_out(offset, index, buffer); // 5
			break; // 6
		}
		buffer[index] = ch; // 7
		index++; // 8
		if( index==length )	{ // 9
			line_out(offset, length, buffer); // 10
			offset += length; // 11
			index = 0; // 12
		}
	}

	fclose(fp);

	return 0;
}

// 1. Loops until the end of file is encountered
// 2. Fetches a character
// 3. Immediately tests for EOF
// 4. If the index is 0, the buffer is empty; otherwise..
// 5. ..it outputs the final line of the hex dump.
// 6. Exits the loop
// 7. Stores the character
// 8. Increments the index into the buffer
// 9. If the buffer is full, outputs a row of the hex dump
// 10. Outputs the row
// 11. Adjusts the offset
// 12. Resets the index to start reading the next length (16) bytes

// Pass a filename (for example: bytes.dat) as an argument to the program to dump the file in hex format