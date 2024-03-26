#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int options; // 1

#define SIZE 16 // 2
#define ABBR 1 // 3
#define OCT 2 // 4
#define set_abbr() options|=ABBR // 5
#define test_abbr() ((options&ABBR)==ABBR) // 6
#define set_oct() options|=OCT // 7
#define test_oct() ((options&OCT)==OCT) // 8

// 1. Declares the external variable before it's used
// 2. Size value is used elsewhere in the code
// 3. Abbreviation status is bit 1
// 4. Octal output status is bit 2
// 5. Uses the bitwise logical OR to set bit 1 (ABBR) in variable
// options
// 6. Uses the bitwise logical AND to test bit 1 (ABBR) in variable
// options
// 7. Uses the bitwise logical OR to set bit 2 (OCT) in variable
// options
// 8. Uses the bitwise logical AND to test bit 2 (OCT) in variable


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

void help(void) {
	puts("dumpfile - output a file's raw data");
	puts("Format: dumpfile filename [options]");
	puts("Options:");
	puts("-a abbreviated output");
	puts("-o output octal instead of hex");
	puts("-h display this text");
	exit(1);
}

int main(int argc, char *argv[]) {
    unsigned char buffer[SIZE];
    char *filename;
    char *r;
    FILE *fp;
    int ch, offset, index;

    if ( argc < 2 ) {
        puts("Format: dumpfile filename [options]");
		exit(1);
    }
    
    filename = argv[1];

    if( strcmp(filename,"-h") == 0 )
		help();

    fp = fopen(filename, "r");
    if( fp==NULL ) {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    offset = index = opterr = options = 0; // 9
    while( (*r = getopt(argc, argv, "aoh")) != -1 ) { // 10
		switch(*r) {
			case 'a':
				set_abbr(); // 11
				break;
			case 'o':
				set_oct(); // 12
				break;
			case 'h':
				help(); // 13
			case '?':
				printf("Switch '%c' is invalid\n", optopt);
				break;
			default:
				puts("Unknown option");
		}
	}

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

// 9. Variables offset and index are used elsewhere in the main() function
// 10. Valid switches are 'a', 'o', and 'h'
// 11. For the -a switch, the set_abbr() macro modifies variable options
// 12. For the -o switch, the set_oct() macro modifies variable options
// 13. The -h switch displays the help text