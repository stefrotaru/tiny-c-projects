#include <stdio.h>
#include <unistd.h> // 1

int main(int argc, char *argv[]) {
	int r;

	opterr = 0; // 2
	while( (r=getopt(argc,argv,"abc")) != -1 ) 	{ // 3
		switch(r) { // 4
			case 'a': // 5
				puts("alfa option set");
				break;
			case 'b':
				puts("bravo option set");
				break;
			case 'c':
				puts("charlie option set");
				break;
			case '?': // 6
				printf("Switch '%c' is invalid\n",optopt);
				break;
			default:
				puts("Unknown option");
		}
	}

	return 0;
}

// 1. The unistd.h header file is required for the getopt() function
// 2. Suppresses error output from getopt()
// 3. Scans the arguments, repeating the loop until every argument is
// processed
// 4. Examines the character returned
// 5. The case statements examine each valid option letter
// 6. A question mark is returned for unknown/invalid options