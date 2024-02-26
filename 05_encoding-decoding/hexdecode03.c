#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE*3+1)

int main()
{
	char line[LENGTH];
	int x,ch,hex;
	char *r;

	r = fgets(line,LENGTH,stdin);
	if( r==NULL || strncmp(line,"HEX ENCODE",10)!=0 ) {
		fprintf(stderr,"Invalid HEX ENCODE data\n");
		exit(1);
	}

	x = 0;
	while( (ch=getchar()) != EOF ) {
		line[x] = ch;
		x++;
		if( ch=='\n' || x==LENGTH) {
			if( line[x-1]=='\n')
				line[x-1] = '\0';
			else
				line[x] = '\0';

			if( strncmp(line,"HEX ENCODE END",13)==0 )
				break;

			r = strtok(line," "); // 1
			while(r) { // 2
				sscanf(r,"%02X",&hex); // 3
				printf("%c",hex); // 4
				r = strtok(NULL," "); // 5
			}
			x = 0;
		}
	}

	return 0;
}

// 1. Parses the string (input line of text), separating its content by spaces
// 2. As lon as the strtok() function returns a non-NULL value, loops
// 3. Translates the 2-character hex string into an integer value
// 4. Outputs the integer value (which can be non-ASCII)
// 5. Keeps scanning the same string