#include <stdio.h>

int main() {
    unsigned char data[255];
    int b;

    for ( b = 0; b < 256; b++ ) {
        data[b] = b;
    }

    for ( b = 0; b < 256; b++ ) {
        if( b % 16 ==0 ) // 1
			printf("%05X ",b);
		printf(" %02X",data[b]);

		if( (b + 1) % 8 ==0 ) // 3
			putchar(' '); // 4
            
		if( (b + 1) % 16 ==0 ) // 5
			putchar('\n');
    }

    return 0;
}

// 1. The start of every line
// 2. Outputs the offset
// 3. After the 8th column
// 4. Adds a space
// 5. Newline after 16 bytes