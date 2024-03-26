#include <stdio.h>

void line_out(int offset, int length, unsigned char *data) {
	int a;

	printf("%05X ",offset); // 1

	for( a = 0; a < length; a++ ) 	{ // 2
		printf(" %02X", *(data+a)); // 3
		if( (a + 1) % 8 ==0 ) // 4
			putchar(' ');
	}

	putchar(' '); // 5
	for( a = 0; a < length; a++ ) { // 6
		if( *(data+a) >= ' ' && *(data+a) <= '~' ) // 7
			putchar( *(data+a) ); // 8
		else
			putchar(' '); // 9
	}

	putchar('\n');
}

// 1. Outputs the offset value
// 2. The first loop outputs the hex values
// 3. The hex value calculation is based on the start of the data
// plus the looping value
// 4. After the 8th hex byte output, adds an extra space for readability
// 5. Adds another space after the hex columns
// 6. The second loop outputs the ASCII values, if any
// 7. Checks the printable character range
// 8. Outputs a printable character
// 9. Otherwise, outputs a space


int main() {
	unsigned char data[256];
	int b;
	const int length = 16;

	for( b = 0; b < 256; b++ )
		data[b] = b;

	for( b = 0; b < 256; b += length ) {
		line_out(b, length, data+b);
	}

	return 0;
}