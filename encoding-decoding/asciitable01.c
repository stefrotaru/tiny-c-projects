#include <stdio.h>

int main()
{
	int ch,wrap;

	wrap = 0; // 1
	while ( (ch=getchar()) != EOF )	{
		printf("%02X ",ch); // 2
		wrap+=3; // 3

		if( wrap>77 || ch=='\n' ) { // 4
			putchar('\n'); // 5
			wrap=0;	// 6
		}
	}

	return(0);
}

// 1. initialize the wrap to zero
// 2. print the character in hexadecimal format
// 3. each printf() output is 3 characters wide 
// 4. assume that the terminal column width is 80. (77 + 3 = 80)
// 5. output a newline - wrap
// 6. reset the wrap value